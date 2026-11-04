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
struct SensorNode_R000831_3117_0
{
  short gain;
  int status;
  short reading;
  unsigned char threshold;
  int buffer[3];
};
struct CipherContext_R000831_3117_1
{
  int round_key;
  int tag;
  int flags;
  short nonce;
  short counter;
  int buffer[3];
};
struct DeviceConfig_R000831_3117_2
{
  short port;
  int id;
  short stop_bits;
  unsigned char timeout;
  int parity;
  int buffer[3];
};
struct EventLog_R000831_3117_3
{
  int severity;
  int signature;
  int timestamp;
  unsigned char seq;
  int buffer[3];
};
union TelemetryField_R000831_3117_0
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
void fn_R000831_3117_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st_1 = {0};
  struct CipherContext_R000831_3117_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_75_1 = local_arr_1[aux_1 % 3];
  int threshold_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_75_2 * 2)) & 127;
  int quantum_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_25_1) & 63;
  aux_2 = (aux_2 + quantum_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_75_1 == threshold_75_2);
  assert(quantum_25_1 == quantum_25_2);
}

int fn_R000831_3117_0(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_75 = local_arr[aux % 3];
  acc = (acc + (threshold_75 * 2)) & 127;
  int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_25) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000831_3117_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int vector_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_58_1)
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

  switch (vector_58_2)
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

  int quotient_75_1 = 0;
  int quotient_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_75_1 = ((quotient_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_75_2 = ((quotient_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_75_1) & 127;
    acc_2 = (acc_2 + quotient_75_2) & 127;
  }

  int cursor_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_71_1 > 16)
  {
    acc_1 = ((acc_1 + (cursor_71_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_71_2 > 16)
  {
    acc_2 = ((acc_2 + (cursor_71_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_71_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_58_1 == vector_58_2);
  assert(quotient_75_1 == quotient_75_2);
  assert(cursor_71_1 == cursor_71_2);
}

int fn_R000831_3117_1(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int vector_58 = (aux + st.buffer[1]) & 3;
  switch (vector_58)
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

  int quotient_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_75 = ((quotient_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_75) & 127;
  }

  int cursor_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_71 > 16)
  {
    acc = ((acc + (cursor_71 * 2)) + 5) & 127;
    aux ^= cursor_71 & 15;
  }
  else
  {
    acc = ((acc - cursor_71) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000831_3117_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st_1 = {0};
  struct CipherContext_R000831_3117_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_45_1)
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

  switch (offset_45_2)
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

  int stride_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_65_1) & 63;
  aux_2 = (aux_2 + stride_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_86_1 > 48)
  {
    acc_1 = ((acc_1 + (margin_86_1 * 2)) + 5) & 127;
    aux_1 ^= margin_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_86_2 > 48)
  {
    acc_2 = ((acc_2 + (margin_86_2 * 2)) + 5) & 127;
    aux_2 ^= margin_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_45_1 == offset_45_2);
  assert(stride_65_1 == stride_65_2);
  assert(margin_86_1 == margin_86_2);
}

int fn_R000831_3117_2(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_45 = (aux + st.buffer[1]) & 3;
  switch (offset_45)
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

  int stride_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_65) & 63;
  acc ^= aux;
  int margin_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_86 > 48)
  {
    acc = ((acc + (margin_86 * 2)) + 5) & 127;
    aux ^= margin_86 & 15;
  }
  else
  {
    acc = ((acc - margin_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000831_3117_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int damping_87_1 = 0;
  int damping_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_87_1 = ((damping_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_87_2 = ((damping_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_87_1) & 127;
    acc_2 = (acc_2 + damping_87_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_94_1 = local_arr_1[aux_1 % 3];
  int tracker_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_86_1) & 63;
  aux_2 = (aux_2 + offset_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_87_1 == damping_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_94_1 == tracker_94_2);
  assert(offset_86_1 == offset_86_2);
}

int fn_R000831_3117_3(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int damping_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_87 = ((damping_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_87) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_94 = local_arr[aux % 3];
  acc = (acc + (tracker_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_86) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000831_3117_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st_1 = {0};
  struct SensorNode_R000831_3117_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int quantum_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_22_1)
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

  switch (quantum_22_2)
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

  int threshold_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_72_1) & 63;
  aux_2 = (aux_2 + threshold_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_33_1 = 0;
  int mask_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_33_1 = ((mask_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_33_2 = ((mask_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_33_1) & 127;
    acc_2 = (acc_2 + mask_33_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(threshold_72_1 == threshold_72_2);
  assert(mask_33_1 == mask_33_2);
}

int fn_R000831_3117_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int quantum_22 = (aux + st.buffer[1]) & 3;
  switch (quantum_22)
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

  int threshold_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_72) & 63;
  acc ^= aux;
  int mask_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_33 = ((mask_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_33) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000831_3117_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_18_1 > 47)
  {
    acc_1 = ((acc_1 + (checksum_18_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_18_2 > 47)
  {
    acc_2 = ((acc_2 + (checksum_18_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_95_1 = local_arr_1[aux_1 % 3];
  int bound_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_96_1 = 0;
  int bound_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_96_1 = ((bound_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_96_2 = ((bound_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_96_1) & 127;
    acc_2 = (acc_2 + bound_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_18_1 == checksum_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_95_1 == bound_95_2);
  assert(bound_96_1 == bound_96_2);
}

int fn_R000831_3117_5(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_18 > 47)
  {
    acc = ((acc + (checksum_18 * 2)) + 5) & 127;
    aux ^= checksum_18 & 15;
  }
  else
  {
    acc = ((acc - checksum_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_95 = local_arr[aux % 3];
  acc = (acc + (bound_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_96 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_96 = ((bound_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000831_3117_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_24_1 = local_arr_1[aux_1 % 3];
  int threshold_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_24_2 * 2)) & 127;
  int weight_16_1 = 0;
  int weight_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_16_1 = ((weight_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_16_2 = ((weight_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_16_1) & 127;
    acc_2 = (acc_2 + weight_16_2) & 127;
  }

  int stride_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_80_1 > 19)
  {
    acc_1 = ((acc_1 + (stride_80_1 * 2)) + 5) & 127;
    aux_1 ^= stride_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_80_2 > 19)
  {
    acc_2 = ((acc_2 + (stride_80_2 * 2)) + 5) & 127;
    aux_2 ^= stride_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_24_1 == threshold_24_2);
  assert(weight_16_1 == weight_16_2);
  assert(stride_80_1 == stride_80_2);
}

int fn_R000831_3117_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int threshold_24 = local_arr[aux % 3];
  acc = (acc + (threshold_24 * 2)) & 127;
  int weight_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_16 = ((weight_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_16) & 127;
  }

  int stride_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_80 > 19)
  {
    acc = ((acc + (stride_80 * 2)) + 5) & 127;
    aux ^= stride_80 & 15;
  }
  else
  {
    acc = ((acc - stride_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000831_3117_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tally_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_20_1)
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

  switch (tally_20_2)
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
  int weight_42_1 = local_arr_1[aux_1 % 3];
  int weight_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_42_2 * 2)) & 127;
  int bound_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_41_1) & 63;
  aux_2 = (aux_2 + bound_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_53_1 > 47)
  {
    acc_1 = ((acc_1 + (threshold_53_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_53_2 > 47)
  {
    acc_2 = ((acc_2 + (threshold_53_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_20_1 == tally_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_42_1 == weight_42_2);
  assert(bound_41_1 == bound_41_2);
  assert(threshold_53_1 == threshold_53_2);
}

int fn_R000831_3117_7(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tally_20 = (aux + st.buffer[1]) & 3;
  switch (tally_20)
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
  int weight_42 = local_arr[aux % 3];
  acc = (acc + (weight_42 * 2)) & 127;
  int bound_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_41) & 63;
  acc ^= aux;
  int threshold_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_53 > 47)
  {
    acc = ((acc + (threshold_53 * 2)) + 5) & 127;
    aux ^= threshold_53 & 15;
  }
  else
  {
    acc = ((acc - threshold_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000831_3117_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st_1 = {0};
  struct SensorNode_R000831_3117_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_22_1 = local_arr_1[aux_1 % 3];
  int threshold_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_22_2 * 2)) & 127;
  int offset_19_1 = 0;
  int offset_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_19_1 = ((offset_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_19_2 = ((offset_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_19_1) & 127;
    acc_2 = (acc_2 + offset_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_22_1 == threshold_22_2);
  assert(offset_19_1 == offset_19_2);
}

int fn_R000831_3117_8(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int threshold_22 = local_arr[aux % 3];
  acc = (acc + (threshold_22 * 2)) & 127;
  int offset_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_19 = ((offset_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000831_3117_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st_1 = {0};
  struct DeviceConfig_R000831_3117_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_66_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_66_1 * 2)) + 5) & 127;
    aux_1 ^= parity_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_66_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_66_2 * 2)) + 5) & 127;
    aux_2 ^= parity_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_76_1)
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

  switch (delta_76_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_66_1 == parity_66_2);
  assert(delta_76_1 == delta_76_2);
}

int fn_R000831_3117_9(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_66 > 16)
  {
    acc = ((acc + (parity_66 * 2)) + 5) & 127;
    aux ^= parity_66 & 15;
  }
  else
  {
    acc = ((acc - parity_66) + 11) & 127;
    aux += 3;
  }
  int delta_76 = (aux + st.buffer[1]) & 3;
  switch (delta_76)
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

void fn_R000831_3117_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st_1 = {0};
  struct SensorNode_R000831_3117_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int tracker_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_84_1)
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

  switch (tracker_84_2)
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

  int mask_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_98_1 > 26)
  {
    acc_1 = ((acc_1 + (mask_98_1 * 2)) + 5) & 127;
    aux_1 ^= mask_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_98_2 > 26)
  {
    acc_2 = ((acc_2 + (mask_98_2 * 2)) + 5) & 127;
    aux_2 ^= mask_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_35_1 = 0;
  int pivot_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_35_1 = ((pivot_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_35_2 = ((pivot_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_35_1) & 127;
    acc_2 = (acc_2 + pivot_35_2) & 127;
  }

  int stride_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_16_1) & 63;
  aux_2 = (aux_2 + stride_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_84_1 == tracker_84_2);
  assert(mask_98_1 == mask_98_2);
  assert(pivot_35_1 == pivot_35_2);
  assert(stride_16_1 == stride_16_2);
}

int fn_R000831_3117_10(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int tracker_84 = (aux + st.buffer[1]) & 3;
  switch (tracker_84)
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

  int mask_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_98 > 26)
  {
    acc = ((acc + (mask_98 * 2)) + 5) & 127;
    aux ^= mask_98 & 15;
  }
  else
  {
    acc = ((acc - mask_98) + 11) & 127;
    aux += 3;
  }
  int pivot_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_35 = ((pivot_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_35) & 127;
  }

  int stride_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000831_3117_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st_1 = {0};
  struct DeviceConfig_R000831_3117_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quotient_68_1 = 0;
  int quotient_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_68_1 = ((quotient_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_68_2 = ((quotient_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_68_1) & 127;
    acc_2 = (acc_2 + quotient_68_2) & 127;
  }

  int margin_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_95_1 > 23)
  {
    acc_1 = ((acc_1 + (margin_95_1 * 2)) + 5) & 127;
    aux_1 ^= margin_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_95_2 > 23)
  {
    acc_2 = ((acc_2 + (margin_95_2 * 2)) + 5) & 127;
    aux_2 ^= margin_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_68_1 == quotient_68_2);
  assert(margin_95_1 == margin_95_2);
}

int fn_R000831_3117_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quotient_68 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_68 = ((quotient_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_68) & 127;
  }

  int margin_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_95 > 23)
  {
    acc = ((acc + (margin_95 * 2)) + 5) & 127;
    aux ^= margin_95 & 15;
  }
  else
  {
    acc = ((acc - margin_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000831_3117_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st_1 = {0};
  struct SensorNode_R000831_3117_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_11_1)
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

  switch (segment_11_2)
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

  int scale_76_1 = 0;
  int scale_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_76_1 = ((scale_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_76_2 = ((scale_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_76_1) & 127;
    acc_2 = (acc_2 + scale_76_2) & 127;
  }

  int mask_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_44_1 > 29)
  {
    acc_1 = ((acc_1 + (mask_44_1 * 2)) + 5) & 127;
    aux_1 ^= mask_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_44_2 > 29)
  {
    acc_2 = ((acc_2 + (mask_44_2 * 2)) + 5) & 127;
    aux_2 ^= mask_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_44_1) & 63;
  aux_2 = (aux_2 + sample_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_11_1 == segment_11_2);
  assert(scale_76_1 == scale_76_2);
  assert(mask_44_1 == mask_44_2);
  assert(sample_44_1 == sample_44_2);
}

int fn_R000831_3117_12(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000831_3117_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_11 = (aux + st.buffer[1]) & 3;
  switch (segment_11)
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

  int scale_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_76 = ((scale_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_76) & 127;
  }

  int mask_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_44 > 29)
  {
    acc = ((acc + (mask_44 * 2)) + 5) & 127;
    aux ^= mask_44 & 15;
  }
  else
  {
    acc = ((acc - mask_44) + 11) & 127;
    aux += 3;
  }
  int sample_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_44) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000831_3117_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st_1 = {0};
  struct DeviceConfig_R000831_3117_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_93_1 > 44)
  {
    acc_1 = ((acc_1 + (residue_93_1 * 2)) + 5) & 127;
    aux_1 ^= residue_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_93_2 > 44)
  {
    acc_2 = ((acc_2 + (residue_93_2 * 2)) + 5) & 127;
    aux_2 ^= residue_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_79_1 = 0;
  int sample_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_79_1 = ((sample_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_79_2 = ((sample_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_79_1) & 127;
    acc_2 = (acc_2 + sample_79_2) & 127;
  }

  int scale_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_37_1)
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

  switch (scale_37_2)
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

  int bound_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_37_1) & 63;
  aux_2 = (aux_2 + bound_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_93_1 == residue_93_2);
  assert(sample_79_1 == sample_79_2);
  assert(scale_37_1 == scale_37_2);
  assert(bound_37_1 == bound_37_2);
}

int fn_R000831_3117_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000831_3117_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_93 > 44)
  {
    acc = ((acc + (residue_93 * 2)) + 5) & 127;
    aux ^= residue_93 & 15;
  }
  else
  {
    acc = ((acc - residue_93) + 11) & 127;
    aux += 3;
  }
  int sample_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_79 = ((sample_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_79) & 127;
  }

  int scale_37 = (aux + st.buffer[1]) & 3;
  switch (scale_37)
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

  int bound_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_37) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000831_3117_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st_1 = {0};
  struct EventLog_R000831_3117_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_55_1)
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

  switch (vector_55_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_55_1 == vector_55_2);
}

int fn_R000831_3117_14(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000831_3117_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_55 = (aux + st.buffer[1]) & 3;
  switch (vector_55)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000831_3117_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st_1 = {0};
  struct CipherContext_R000831_3117_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_56_1) & 63;
  aux_2 = (aux_2 + index_reg_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_41_1 = local_arr_1[aux_1 % 3];
  int residue_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_41_2 * 2)) & 127;
  int pivot_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_46_1 > 35)
  {
    acc_1 = ((acc_1 + (pivot_46_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_46_2 > 35)
  {
    acc_2 = ((acc_2 + (pivot_46_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_56_1 == index_reg_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_41_1 == residue_41_2);
  assert(pivot_46_1 == pivot_46_2);
}

int fn_R000831_3117_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000831_3117_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_41 = local_arr[aux % 3];
  acc = (acc + (residue_41 * 2)) & 127;
  int pivot_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_46 > 35)
  {
    acc = ((acc + (pivot_46 * 2)) + 5) & 127;
    aux ^= pivot_46 & 15;
  }
  else
  {
    acc = ((acc - pivot_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000831_0_1;
  int sec_r000831_0_2;
  int sec_r000831_1_1;
  int sec_r000831_1_2;
  int sec_r000831_2_1;
  int sec_r000831_2_2;
  int sec_r000831_3_1;
  int sec_r000831_3_2;
  int sec_r000831_4_1;
  int sec_r000831_4_2;
  int sec_r000831_5_1;
  int sec_r000831_5_2;
  int sec_r000831_6_1;
  int sec_r000831_6_2;
  int sec_r000831_7_1;
  int sec_r000831_7_2;
  int sec_r000831_8_1;
  int sec_r000831_8_2;
  int sec_r000831_9_1;
  int sec_r000831_9_2;
  int sec_r000831_10_1;
  int sec_r000831_10_2;
  int sec_r000831_11_1;
  int sec_r000831_11_2;
  int sec_r000831_12_1;
  int sec_r000831_12_2;
  int sec_r000831_13_1;
  int sec_r000831_13_2;
  int sec_r000831_14_1;
  int sec_r000831_14_2;
  int sec_r000831_15_1;
  int sec_r000831_15_2;
  int sec_r000831_16_1;
  int sec_r000831_16_2;
  int sec_r000831_17_1;
  int sec_r000831_17_2;
  int sec_r000831_18_1;
  int sec_r000831_18_2;
  int sec_r000831_19_1;
  int sec_r000831_19_2;
  int sec_r000831_20_1;
  int sec_r000831_20_2;
  int pub_r000831_0_1;
  int pub_r000831_0_2;
  int pub_r000831_1_1;
  int pub_r000831_1_2;
  int pub_r000831_2_1;
  int pub_r000831_2_2;
  int pub_r000831_3_1;
  int pub_r000831_3_2;
  int pub_r000831_4_1;
  int pub_r000831_4_2;
  int pub_r000831_5_1;
  int pub_r000831_5_2;
  int pub_r000831_6_1;
  int pub_r000831_6_2;
  int pub_r000831_7_1;
  int pub_r000831_7_2;
  int pub_r000831_8_1;
  int pub_r000831_8_2;
  int pub_r000831_9_1;
  int pub_r000831_9_2;
  int pub_r000831_10_1;
  int pub_r000831_10_2;
  int pub_r000831_11_1;
  int pub_r000831_11_2;
  int pub_r000831_12_1;
  int pub_r000831_12_2;
  int pub_r000831_13_1;
  int pub_r000831_13_2;
  int pub_r000831_14_1;
  int pub_r000831_14_2;
  int pub_r000831_15_1;
  int pub_r000831_15_2;
  int pub_r000831_16_1;
  int pub_r000831_16_2;
  int pub_r000831_17_1;
  int pub_r000831_17_2;
  int pub_r000831_18_1;
  int pub_r000831_18_2;
  int pub_r000831_19_1;
  int pub_r000831_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000831_0_1 >= (-100)) && (pub_r000831_0_1 <= 100));
  __CPROVER_assume((pub_r000831_0_2 >= (-100)) && (pub_r000831_0_2 <= 100));
  __CPROVER_assume((pub_r000831_1_1 >= (-100)) && (pub_r000831_1_1 <= 100));
  __CPROVER_assume((pub_r000831_1_2 >= (-100)) && (pub_r000831_1_2 <= 100));
  __CPROVER_assume((pub_r000831_2_1 >= (-100)) && (pub_r000831_2_1 <= 100));
  __CPROVER_assume((pub_r000831_2_2 >= (-100)) && (pub_r000831_2_2 <= 100));
  __CPROVER_assume((pub_r000831_3_1 >= (-100)) && (pub_r000831_3_1 <= 100));
  __CPROVER_assume((pub_r000831_3_2 >= (-100)) && (pub_r000831_3_2 <= 100));
  __CPROVER_assume((pub_r000831_4_1 >= (-100)) && (pub_r000831_4_1 <= 100));
  __CPROVER_assume((pub_r000831_4_2 >= (-100)) && (pub_r000831_4_2 <= 100));
  __CPROVER_assume((pub_r000831_5_1 >= (-100)) && (pub_r000831_5_1 <= 100));
  __CPROVER_assume((pub_r000831_5_2 >= (-100)) && (pub_r000831_5_2 <= 100));
  __CPROVER_assume((pub_r000831_6_1 >= (-100)) && (pub_r000831_6_1 <= 100));
  __CPROVER_assume((pub_r000831_6_2 >= (-100)) && (pub_r000831_6_2 <= 100));
  __CPROVER_assume((pub_r000831_7_1 >= (-100)) && (pub_r000831_7_1 <= 100));
  __CPROVER_assume((pub_r000831_7_2 >= (-100)) && (pub_r000831_7_2 <= 100));
  __CPROVER_assume((pub_r000831_8_1 >= (-100)) && (pub_r000831_8_1 <= 100));
  __CPROVER_assume((pub_r000831_8_2 >= (-100)) && (pub_r000831_8_2 <= 100));
  __CPROVER_assume((pub_r000831_9_1 >= (-100)) && (pub_r000831_9_1 <= 100));
  __CPROVER_assume((pub_r000831_9_2 >= (-100)) && (pub_r000831_9_2 <= 100));
  __CPROVER_assume((pub_r000831_10_1 >= (-100)) && (pub_r000831_10_1 <= 100));
  __CPROVER_assume((pub_r000831_10_2 >= (-100)) && (pub_r000831_10_2 <= 100));
  __CPROVER_assume((pub_r000831_11_1 >= (-100)) && (pub_r000831_11_1 <= 100));
  __CPROVER_assume((pub_r000831_11_2 >= (-100)) && (pub_r000831_11_2 <= 100));
  __CPROVER_assume((pub_r000831_12_1 >= (-100)) && (pub_r000831_12_1 <= 100));
  __CPROVER_assume((pub_r000831_12_2 >= (-100)) && (pub_r000831_12_2 <= 100));
  __CPROVER_assume((pub_r000831_13_1 >= (-100)) && (pub_r000831_13_1 <= 100));
  __CPROVER_assume((pub_r000831_13_2 >= (-100)) && (pub_r000831_13_2 <= 100));
  __CPROVER_assume((pub_r000831_14_1 >= (-100)) && (pub_r000831_14_1 <= 100));
  __CPROVER_assume((pub_r000831_14_2 >= (-100)) && (pub_r000831_14_2 <= 100));
  __CPROVER_assume((pub_r000831_15_1 >= (-100)) && (pub_r000831_15_1 <= 100));
  __CPROVER_assume((pub_r000831_15_2 >= (-100)) && (pub_r000831_15_2 <= 100));
  __CPROVER_assume((pub_r000831_16_1 >= (-100)) && (pub_r000831_16_1 <= 100));
  __CPROVER_assume((pub_r000831_16_2 >= (-100)) && (pub_r000831_16_2 <= 100));
  __CPROVER_assume((pub_r000831_17_1 >= (-100)) && (pub_r000831_17_1 <= 100));
  __CPROVER_assume((pub_r000831_17_2 >= (-100)) && (pub_r000831_17_2 <= 100));
  __CPROVER_assume((pub_r000831_18_1 >= (-100)) && (pub_r000831_18_1 <= 100));
  __CPROVER_assume((pub_r000831_18_2 >= (-100)) && (pub_r000831_18_2 <= 100));
  __CPROVER_assume((pub_r000831_19_1 >= (-100)) && (pub_r000831_19_1 <= 100));
  __CPROVER_assume((pub_r000831_19_2 >= (-100)) && (pub_r000831_19_2 <= 100));
  __CPROVER_assume((sec_r000831_0_1 >= 0) && (sec_r000831_0_1 <= 255));
  __CPROVER_assume((sec_r000831_0_2 >= 0) && (sec_r000831_0_2 <= 255));
  __CPROVER_assume((sec_r000831_1_1 >= 0) && (sec_r000831_1_1 <= 255));
  __CPROVER_assume((sec_r000831_1_2 >= 0) && (sec_r000831_1_2 <= 255));
  __CPROVER_assume((sec_r000831_2_1 >= 0) && (sec_r000831_2_1 <= 255));
  __CPROVER_assume((sec_r000831_2_2 >= 0) && (sec_r000831_2_2 <= 255));
  __CPROVER_assume((sec_r000831_3_1 >= 0) && (sec_r000831_3_1 <= 255));
  __CPROVER_assume((sec_r000831_3_2 >= 0) && (sec_r000831_3_2 <= 255));
  __CPROVER_assume((sec_r000831_4_1 >= 0) && (sec_r000831_4_1 <= 255));
  __CPROVER_assume((sec_r000831_4_2 >= 0) && (sec_r000831_4_2 <= 255));
  __CPROVER_assume((sec_r000831_5_1 >= 0) && (sec_r000831_5_1 <= 255));
  __CPROVER_assume((sec_r000831_5_2 >= 0) && (sec_r000831_5_2 <= 255));
  __CPROVER_assume((sec_r000831_6_1 >= 0) && (sec_r000831_6_1 <= 255));
  __CPROVER_assume((sec_r000831_6_2 >= 0) && (sec_r000831_6_2 <= 255));
  __CPROVER_assume((sec_r000831_7_1 >= 0) && (sec_r000831_7_1 <= 255));
  __CPROVER_assume((sec_r000831_7_2 >= 0) && (sec_r000831_7_2 <= 255));
  __CPROVER_assume((sec_r000831_8_1 >= 0) && (sec_r000831_8_1 <= 255));
  __CPROVER_assume((sec_r000831_8_2 >= 0) && (sec_r000831_8_2 <= 255));
  __CPROVER_assume((sec_r000831_9_1 >= 0) && (sec_r000831_9_1 <= 255));
  __CPROVER_assume((sec_r000831_9_2 >= 0) && (sec_r000831_9_2 <= 255));
  __CPROVER_assume((sec_r000831_10_1 >= 0) && (sec_r000831_10_1 <= 255));
  __CPROVER_assume((sec_r000831_10_2 >= 0) && (sec_r000831_10_2 <= 255));
  __CPROVER_assume((sec_r000831_11_1 >= 0) && (sec_r000831_11_1 <= 255));
  __CPROVER_assume((sec_r000831_11_2 >= 0) && (sec_r000831_11_2 <= 255));
  __CPROVER_assume((sec_r000831_12_1 >= 0) && (sec_r000831_12_1 <= 255));
  __CPROVER_assume((sec_r000831_12_2 >= 0) && (sec_r000831_12_2 <= 255));
  __CPROVER_assume((sec_r000831_13_1 >= 0) && (sec_r000831_13_1 <= 255));
  __CPROVER_assume((sec_r000831_13_2 >= 0) && (sec_r000831_13_2 <= 255));
  __CPROVER_assume((sec_r000831_14_1 >= 0) && (sec_r000831_14_1 <= 255));
  __CPROVER_assume((sec_r000831_14_2 >= 0) && (sec_r000831_14_2 <= 255));
  __CPROVER_assume((sec_r000831_15_1 >= 0) && (sec_r000831_15_1 <= 255));
  __CPROVER_assume((sec_r000831_15_2 >= 0) && (sec_r000831_15_2 <= 255));
  __CPROVER_assume((sec_r000831_16_1 >= 0) && (sec_r000831_16_1 <= 255));
  __CPROVER_assume((sec_r000831_16_2 >= 0) && (sec_r000831_16_2 <= 255));
  __CPROVER_assume((sec_r000831_17_1 >= 0) && (sec_r000831_17_1 <= 255));
  __CPROVER_assume((sec_r000831_17_2 >= 0) && (sec_r000831_17_2 <= 255));
  __CPROVER_assume((sec_r000831_18_1 >= 0) && (sec_r000831_18_1 <= 255));
  __CPROVER_assume((sec_r000831_18_2 >= 0) && (sec_r000831_18_2 <= 255));
  __CPROVER_assume((sec_r000831_19_1 >= 0) && (sec_r000831_19_1 <= 255));
  __CPROVER_assume((sec_r000831_19_2 >= 0) && (sec_r000831_19_2 <= 255));
  __CPROVER_assume((sec_r000831_20_1 >= 0) && (sec_r000831_20_1 <= 255));
  __CPROVER_assume((sec_r000831_20_2 >= 0) && (sec_r000831_20_2 <= 255));
  struct SensorNode_R000831_3117_0 st_var_0_1 = {0};
  struct SensorNode_R000831_3117_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000831_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000831_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000831_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000831_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000831_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000831_0_2 + 7) & 15;
  struct CipherContext_R000831_3117_1 st_var_1_1 = {0};
  struct CipherContext_R000831_3117_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000831_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000831_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000831_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000831_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000831_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000831_0_2 + 9) & 15;
  struct DeviceConfig_R000831_3117_2 st_var_2_1 = {0};
  struct DeviceConfig_R000831_3117_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000831_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000831_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000831_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000831_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000831_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000831_0_2 + 11) & 15;
  struct EventLog_R000831_3117_3 st_var_3_1 = {0};
  struct EventLog_R000831_3117_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000831_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000831_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000831_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000831_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000831_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000831_0_2 + 13) & 15;
  union TelemetryField_R000831_3117_0 u_var_1;
  union TelemetryField_R000831_3117_0 u_var_2;
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
  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (7 & 31);
  int stage_v_2_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (7 & 31);
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= (stage_v_2_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_2_2 << 1) & 127;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_7_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_7_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_7_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_7_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = ((st_var_1_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_1_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 35)
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
  if (stage_v_9_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 35)
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
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
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 50)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 50)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_18_1 = table_1[2];
  int stage_v_18_2 = table_2[2];
  table_1[2] = (table_1[3] + 37) & 63;
  table_2[2] = (table_2[3] + 37) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 21) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 21) & 15;
  int stage_v_20_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_20_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= stage_v_20_1;
  chk_sum_2 ^= stage_v_20_2;
  int stage_v_21_1 = (st_var_1_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_1_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 24) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 47)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 47)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 31)
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
  if (stage_v_26_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 31)
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
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 28) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (st_var_1_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_1_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = (st_var_2_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_2_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = table_1[0];
  int stage_v_36_2 = table_2[0];
  table_1[0] = (table_1[1] + 73) & 63;
  table_2[0] = (table_2[1] + 73) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 55)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 55)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 53)
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
  if (stage_v_40_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 53)
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
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 44) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 44) & 15;
  int stage_v_43_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_43_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= stage_v_43_1;
  chk_sum_2 ^= stage_v_43_2;
  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 47) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = table_1[0];
  int stage_v_48_2 = table_2[0];
  table_1[0] = (table_1[1] + 97) & 63;
  table_2[0] = (table_2[1] + 97) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 50)
    {
      chk_sum_1 ^= stage_v_53_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_53_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 50)
    {
      chk_sum_2 ^= stage_v_53_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_54_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (59 & 31);
  int stage_v_54_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (59 & 31);
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  chk_sum_1 ^= (stage_v_54_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_54_2 << 1) & 127;
  int stage_v_55_1 = ((st_var_3_1.buffer[1] * 2) + 172) & 63;
  int stage_v_55_2 = ((st_var_3_2.buffer[1] * 2) + 172) & 63;
  if (stage_v_55_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_55_1) - 5) & 255;
    if (stage_v_55_1 > 42)
    {
      chk_sum_1 ^= stage_v_55_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_55_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_55_2) - 5) & 255;
    if (stage_v_55_2 > 42)
    {
      chk_sum_2 ^= stage_v_55_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_61_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = (st_var_3_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_3_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 65) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  int stage_v_65_1 = ((st_var_1_1.buffer[2] * 2) + 202) & 63;
  int stage_v_65_2 = ((st_var_1_2.buffer[2] * 2) + 202) & 63;
  if (stage_v_65_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_65_1) - 5) & 255;
    if (stage_v_65_1 > 46)
    {
      chk_sum_1 ^= stage_v_65_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_65_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_65_2) - 5) & 255;
    if (stage_v_65_2 > 46)
    {
      chk_sum_2 ^= stage_v_65_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  if (stage_v_68_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 47)
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
  if (stage_v_68_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 47)
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
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 53)
    {
      chk_sum_1 ^= stage_v_72_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_72_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 53)
    {
      chk_sum_2 ^= stage_v_72_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_75_1 = ((st_var_3_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_3_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 50)
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
  if (stage_v_75_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 50)
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
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 48)
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
  if (stage_v_77_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 48)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 79) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 79) & 15;
  int stage_v_78_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_78_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  chk_sum_1 ^= stage_v_78_1;
  chk_sum_2 ^= stage_v_78_2;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
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

  int stage_v_81_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (86 & 31);
  int stage_v_81_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (86 & 31);
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  chk_sum_1 ^= (stage_v_81_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_81_2 << 1) & 127;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 83) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (st_var_2_1.buffer[0] ^ 89) & 3;
  int stage_v_86_2 = (st_var_2_2.buffer[0] ^ 89) & 3;
  switch (stage_v_86_1)
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

  switch (stage_v_86_2)
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

  int stage_v_87_1 = (st_var_3_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_3_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = table_1[0];
  int stage_v_88_2 = table_2[0];
  table_1[0] = (table_1[1] + 177) & 63;
  table_2[0] = (table_2[1] + 177) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 91) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  int stage_v_91_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_91_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_92_1 = ((st_var_0_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_0_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 50)
    {
      chk_sum_1 ^= stage_v_92_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_92_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 50)
    {
      chk_sum_2 ^= stage_v_92_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_93_1 = table_1[1];
  int stage_v_93_2 = table_2[1];
  table_1[1] = (table_1[2] + 187) & 63;
  table_2[1] = (table_2[2] + 187) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((st_var_0_1.buffer[0] * 2) + 295) & 63;
  int stage_v_96_2 = ((st_var_0_2.buffer[0] * 2) + 295) & 63;
  if (stage_v_96_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_96_1) - 5) & 255;
    if (stage_v_96_1 > 37)
    {
      chk_sum_1 ^= stage_v_96_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_96_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_96_2) - 5) & 255;
    if (stage_v_96_2 > 37)
    {
      chk_sum_2 ^= stage_v_96_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_97_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_97_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_98_1 = table_1[2];
  int stage_v_98_2 = table_2[2];
  table_1[2] = (table_1[3] + 197) & 63;
  table_2[2] = (table_2[3] + 197) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = table_1[3];
  int stage_v_99_2 = table_2[3];
  table_1[3] = (table_1[0] + 199) & 63;
  table_2[3] = (table_2[0] + 199) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (st_var_0_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_0_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 103) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 103) & 15;
  int stage_v_102_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_102_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= stage_v_102_1;
  chk_sum_2 ^= stage_v_102_2;
  int stage_v_103_1 = (st_var_3_1.buffer[0] ^ 106) & 3;
  int stage_v_103_2 = (st_var_3_2.buffer[0] ^ 106) & 3;
  switch (stage_v_103_1)
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

  switch (stage_v_103_2)
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

  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((st_var_1_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_1_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 35)
    {
      chk_sum_1 ^= stage_v_105_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_105_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 35)
    {
      chk_sum_2 ^= stage_v_105_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_106_1 = table_1[2];
  int stage_v_106_2 = table_2[2];
  table_1[2] = (table_1[3] + 213) & 63;
  table_2[2] = (table_2[3] + 213) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((st_var_3_1.buffer[2] * 2) + 328) & 63;
  int stage_v_107_2 = ((st_var_3_2.buffer[2] * 2) + 328) & 63;
  if (stage_v_107_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_107_1) - 5) & 255;
    if (stage_v_107_1 > 54)
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
  if (stage_v_107_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_107_2) - 5) & 255;
    if (stage_v_107_2 > 54)
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
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  }

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
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (118 & 31);
  int stage_v_113_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (118 & 31);
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  chk_sum_1 ^= (stage_v_113_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_113_2 << 1) & 127;
  int stage_v_114_1 = ((st_var_2_1.buffer[0] * 2) + 349) & 63;
  int stage_v_114_2 = ((st_var_2_2.buffer[0] * 2) + 349) & 63;
  if (stage_v_114_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_114_1) - 5) & 255;
    if (stage_v_114_1 > 48)
    {
      chk_sum_1 ^= stage_v_114_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_114_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_114_2) - 5) & 255;
    if (stage_v_114_2 > 48)
    {
      chk_sum_2 ^= stage_v_114_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 117) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 118) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 118) & 15;
  int stage_v_117_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_117_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= stage_v_117_1;
  chk_sum_2 ^= stage_v_117_2;
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
  int stage_v_119_1 = table_1[3];
  int stage_v_119_2 = table_2[3];
  table_1[3] = (table_1[0] + 239) & 63;
  table_2[3] = (table_2[0] + 239) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (st_var_0_1.buffer[0] ^ 123) & 3;
  int stage_v_120_2 = (st_var_0_2.buffer[0] ^ 123) & 3;
  switch (stage_v_120_1)
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

  switch (stage_v_120_2)
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

  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_121_1 = ((stage_v_121_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_121_2 = ((stage_v_121_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = ((st_var_3_1.buffer[0] * 2) + 376) & 63;
  int stage_v_123_2 = ((st_var_3_2.buffer[0] * 2) + 376) & 63;
  if (stage_v_123_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_123_1) - 5) & 255;
    if (stage_v_123_1 > 41)
    {
      chk_sum_1 ^= stage_v_123_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_123_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_123_2) - 5) & 255;
    if (stage_v_123_2 > 41)
    {
      chk_sum_2 ^= stage_v_123_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_124_1 = ((st_var_0_1.buffer[1] * 2) + 379) & 63;
  int stage_v_124_2 = ((st_var_0_2.buffer[1] * 2) + 379) & 63;
  if (stage_v_124_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_124_1) - 5) & 255;
    if (stage_v_124_1 > 48)
    {
      chk_sum_1 ^= stage_v_124_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_124_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_124_2) - 5) & 255;
    if (stage_v_124_2 > 48)
    {
      chk_sum_2 ^= stage_v_124_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_125_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (130 & 31);
  int stage_v_125_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (130 & 31);
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= (stage_v_125_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_125_2 << 1) & 127;
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
  int stage_v_128_1 = (st_var_0_1.buffer[0] ^ 131) & 3;
  int stage_v_128_2 = (st_var_0_2.buffer[0] ^ 131) & 3;
  switch (stage_v_128_1)
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

  switch (stage_v_128_2)
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

  int stage_v_129_1 = ((st_var_1_1.buffer[0] * 2) + 394) & 63;
  int stage_v_129_2 = ((st_var_1_2.buffer[0] * 2) + 394) & 63;
  if (stage_v_129_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_129_1) - 5) & 255;
    if (stage_v_129_1 > 33)
    {
      chk_sum_1 ^= stage_v_129_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_129_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_129_2) - 5) & 255;
    if (stage_v_129_2 > 33)
    {
      chk_sum_2 ^= stage_v_129_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_130_1 = ((st_var_2_1.buffer[1] * 2) + 397) & 63;
  int stage_v_130_2 = ((st_var_2_2.buffer[1] * 2) + 397) & 63;
  if (stage_v_130_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_130_1) - 5) & 255;
    if (stage_v_130_1 > 50)
    {
      chk_sum_1 ^= stage_v_130_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_130_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_130_2) - 5) & 255;
    if (stage_v_130_2 > 50)
    {
      chk_sum_2 ^= stage_v_130_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_131_1 = (st_var_3_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_3_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = table_1[0];
  int stage_v_132_2 = table_2[0];
  table_1[0] = (table_1[1] + 265) & 63;
  table_2[0] = (table_2[1] + 265) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = table_1[1];
  int stage_v_133_2 = table_2[1];
  table_1[1] = (table_1[2] + 267) & 63;
  table_2[1] = (table_2[2] + 267) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (st_var_2_1.buffer[0] ^ 137) & 3;
  int stage_v_134_2 = (st_var_2_2.buffer[0] ^ 137) & 3;
  switch (stage_v_134_1)
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

  switch (stage_v_134_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 136) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 136) & 15;
  int stage_v_135_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_135_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  chk_sum_1 ^= stage_v_135_1;
  chk_sum_2 ^= stage_v_135_2;
  int stage_v_136_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (141 & 31);
  int stage_v_136_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (141 & 31);
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  chk_sum_1 ^= (stage_v_136_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_136_2 << 1) & 127;
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
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 141) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 143) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 143) & 15;
  int stage_v_142_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_142_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= stage_v_142_1;
  chk_sum_2 ^= stage_v_142_2;
  int stage_v_143_1 = ((st_var_3_1.buffer[2] * 2) + 436) & 63;
  int stage_v_143_2 = ((st_var_3_2.buffer[2] * 2) + 436) & 63;
  if (stage_v_143_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_143_1) - 5) & 255;
    if (stage_v_143_1 > 25)
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
  if (stage_v_143_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_143_2) - 5) & 255;
    if (stage_v_143_2 > 25)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 145) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 145) & 15;
  int stage_v_144_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_144_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  chk_sum_1 ^= stage_v_144_1;
  chk_sum_2 ^= stage_v_144_2;
  int stage_v_145_1 = 0;
  int stage_v_145_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_145_1 = ((stage_v_145_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_145_2 = ((stage_v_145_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 147) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 147) & 15;
  int stage_v_146_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_146_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= stage_v_146_1;
  chk_sum_2 ^= stage_v_146_2;
  int stage_v_147_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (152 & 31);
  int stage_v_147_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (152 & 31);
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  chk_sum_1 ^= (stage_v_147_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_147_2 << 1) & 127;
  int stage_v_148_1 = 0;
  int stage_v_148_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_148_1 = ((stage_v_148_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_148_2 = ((stage_v_148_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((st_var_1_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_1_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 47)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 47)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = ((st_var_2_1.buffer[0] * 2) + 457) & 63;
  int stage_v_150_2 = ((st_var_2_2.buffer[0] * 2) + 457) & 63;
  if (stage_v_150_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_150_1) - 5) & 255;
    if (stage_v_150_1 > 44)
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
  if (stage_v_150_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_150_2) - 5) & 255;
    if (stage_v_150_2 > 44)
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
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_153_1 = (st_var_1_1.buffer[0] ^ 156) & 3;
  int stage_v_153_2 = (st_var_1_2.buffer[0] ^ 156) & 3;
  switch (stage_v_153_1)
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

  switch (stage_v_153_2)
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

  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = table_1[3];
  int stage_v_155_2 = table_2[3];
  table_1[3] = (table_1[0] + 311) & 63;
  table_2[3] = (table_2[0] + 311) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (st_var_0_1.buffer[0] ^ 159) & 3;
  int stage_v_156_2 = (st_var_0_2.buffer[0] ^ 159) & 3;
  switch (stage_v_156_1)
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

  switch (stage_v_156_2)
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

  int stage_v_157_1 = table_1[1];
  int stage_v_157_2 = table_2[1];
  table_1[1] = (table_1[2] + 315) & 63;
  table_2[1] = (table_2[2] + 315) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
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
  int stage_v_160_1 = ((st_var_0_1.buffer[1] * 2) + 487) & 63;
  int stage_v_160_2 = ((st_var_0_2.buffer[1] * 2) + 487) & 63;
  if (stage_v_160_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_160_1) - 5) & 255;
    if (stage_v_160_1 > 28)
    {
      chk_sum_1 ^= stage_v_160_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_160_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_160_2) - 5) & 255;
    if (stage_v_160_2 > 28)
    {
      chk_sum_2 ^= stage_v_160_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((st_var_2_1.buffer[0] * 2) + 493) & 63;
  int stage_v_162_2 = ((st_var_2_2.buffer[0] * 2) + 493) & 63;
  if (stage_v_162_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_162_1) - 5) & 255;
    if (stage_v_162_1 > 35)
    {
      chk_sum_1 ^= stage_v_162_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_162_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_162_2) - 5) & 255;
    if (stage_v_162_2 > 35)
    {
      chk_sum_2 ^= stage_v_162_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_163_1 = table_1[3];
  int stage_v_163_2 = table_2[3];
  table_1[3] = (table_1[0] + 327) & 63;
  table_2[3] = (table_2[0] + 327) & 63;
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
  int stage_v_165_1 = 0;
  int stage_v_165_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_165_1 = ((stage_v_165_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_165_2 = ((stage_v_165_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 168) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 168) & 15;
  int stage_v_167_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_167_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  chk_sum_1 ^= stage_v_167_1;
  chk_sum_2 ^= stage_v_167_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 169) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 169) & 15;
  int stage_v_168_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_168_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= stage_v_168_1;
  chk_sum_2 ^= stage_v_168_2;
  int stage_v_169_1 = ((st_var_1_1.buffer[1] * 2) + 514) & 63;
  int stage_v_169_2 = ((st_var_1_2.buffer[1] * 2) + 514) & 63;
  if (stage_v_169_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_169_1) - 5) & 255;
    if (stage_v_169_1 > 52)
    {
      chk_sum_1 ^= stage_v_169_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_169_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_169_2) - 5) & 255;
    if (stage_v_169_2 > 52)
    {
      chk_sum_2 ^= stage_v_169_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_170_1 = table_1[2];
  int stage_v_170_2 = table_2[2];
  table_1[2] = (table_1[3] + 341) & 63;
  table_2[2] = (table_2[3] + 341) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 172) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 172) & 15;
  int stage_v_171_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_171_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= stage_v_171_1;
  chk_sum_2 ^= stage_v_171_2;
  int stage_v_172_1 = ((st_var_0_1.buffer[1] * 2) + 523) & 63;
  int stage_v_172_2 = ((st_var_0_2.buffer[1] * 2) + 523) & 63;
  if (stage_v_172_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_172_1) - 5) & 255;
    if (stage_v_172_1 > 30)
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
  if (stage_v_172_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_172_2) - 5) & 255;
    if (stage_v_172_2 > 30)
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
  int stage_v_173_1 = 0;
  int stage_v_173_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_173_1 = ((stage_v_173_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_173_2 = ((stage_v_173_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((st_var_2_1.buffer[0] * 2) + 529) & 63;
  int stage_v_174_2 = ((st_var_2_2.buffer[0] * 2) + 529) & 63;
  if (stage_v_174_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_174_1) - 5) & 255;
    if (stage_v_174_1 > 49)
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
  if (stage_v_174_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_174_2) - 5) & 255;
    if (stage_v_174_2 > 49)
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
  int stage_v_175_1 = ((st_var_3_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_3_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 49)
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
  if (stage_v_175_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 49)
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
  if (stage_v_176_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_176_1) - 5) & 255;
    if (stage_v_176_1 > 46)
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
  if (stage_v_176_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_176_2) - 5) & 255;
    if (stage_v_176_2 > 46)
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
  int stage_v_177_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (182 & 31);
  int stage_v_177_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (182 & 31);
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= (stage_v_177_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_177_2 << 1) & 127;
  int stage_v_178_1 = (st_var_2_1.buffer[0] ^ 181) & 3;
  int stage_v_178_2 = (st_var_2_2.buffer[0] ^ 181) & 3;
  switch (stage_v_178_1)
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

  switch (stage_v_178_2)
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

  int s_lut_1[4] = {41, 28, 93, 27};
  int s_lut_2[4] = {41, 28, 93, 27};
  int s_idx_1 = sec_r000831_18_1 & 3;
  int s_idx_2 = sec_r000831_18_2 & 3;
  out_sink_1 += s_lut_1[s_idx_1];
  out_sink_2 += s_lut_2[s_idx_2];
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000831_14_1 != sec_r000831_14_2);
  __CPROVER_assume(sec_r000831_3_1 != sec_r000831_3_2);
  __CPROVER_assume(sec_r000831_20_1 != sec_r000831_20_2);
  __CPROVER_assume(pub_r000831_15_1 == pub_r000831_15_2);
  __CPROVER_assume(sec_r000831_12_1 != sec_r000831_12_2);
  __CPROVER_assume(sec_r000831_13_1 != sec_r000831_13_2);
  __CPROVER_assume(pub_r000831_11_1 == pub_r000831_11_2);
  __CPROVER_assume(sec_r000831_10_1 != sec_r000831_10_2);
  __CPROVER_assume(pub_r000831_7_1 == pub_r000831_7_2);
  __CPROVER_assume(sec_r000831_1_1 != sec_r000831_1_2);
  __CPROVER_assume(pub_r000831_19_1 == pub_r000831_19_2);
  __CPROVER_assume(sec_r000831_4_1 != sec_r000831_4_2);
  __CPROVER_assume(pub_r000831_12_1 == pub_r000831_12_2);
  __CPROVER_assume(pub_r000831_1_1 == pub_r000831_1_2);
  __CPROVER_assume(pub_r000831_17_1 == pub_r000831_17_2);
  __CPROVER_assume(pub_r000831_13_1 == pub_r000831_13_2);
  __CPROVER_assume(sec_r000831_11_1 != sec_r000831_11_2);
  __CPROVER_assume(sec_r000831_15_1 != sec_r000831_15_2);
  __CPROVER_assume(sec_r000831_8_1 != sec_r000831_8_2);
  __CPROVER_assume(sec_r000831_0_1 != sec_r000831_0_2);
  __CPROVER_assume(pub_r000831_4_1 == pub_r000831_4_2);
  __CPROVER_assume(pub_r000831_5_1 == pub_r000831_5_2);
  __CPROVER_assume(pub_r000831_3_1 == pub_r000831_3_2);
  __CPROVER_assume(sec_r000831_9_1 != sec_r000831_9_2);
  __CPROVER_assume(sec_r000831_17_1 != sec_r000831_17_2);
  __CPROVER_assume(pub_r000831_16_1 == pub_r000831_16_2);
  __CPROVER_assume(sec_r000831_5_1 != sec_r000831_5_2);
  __CPROVER_assume(sec_r000831_6_1 != sec_r000831_6_2);
  __CPROVER_assume(sec_r000831_16_1 != sec_r000831_16_2);
  __CPROVER_assume(sec_r000831_2_1 != sec_r000831_2_2);
  __CPROVER_assume(sec_r000831_18_1 != sec_r000831_18_2);
  __CPROVER_assume(pub_r000831_18_1 == pub_r000831_18_2);
  __CPROVER_assume(pub_r000831_2_1 == pub_r000831_2_2);
  __CPROVER_assume(pub_r000831_6_1 == pub_r000831_6_2);
  __CPROVER_assume(pub_r000831_9_1 == pub_r000831_9_2);
  __CPROVER_assume(pub_r000831_14_1 == pub_r000831_14_2);
  __CPROVER_assume(pub_r000831_0_1 == pub_r000831_0_2);
  __CPROVER_assume(sec_r000831_19_1 != sec_r000831_19_2);
  __CPROVER_assume(pub_r000831_10_1 == pub_r000831_10_2);
  __CPROVER_assume(sec_r000831_7_1 != sec_r000831_7_2);
  __CPROVER_assume(pub_r000831_8_1 == pub_r000831_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.flags == st_var_1_2.flags);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.seq == st_var_3_2.seq);
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
  for (int i_0 = 0; i_0 < 4; i_0++)
  {
    assert(s_lut_1[i_0] == s_lut_2[i_0]);
  }

  assert(s_idx_1 == s_idx_2);
}


