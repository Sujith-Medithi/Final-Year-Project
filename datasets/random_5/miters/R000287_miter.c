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
struct CipherContext_R000287_8713_0
{
  unsigned char counter;
  int nonce;
  unsigned char tag;
  short flags;
  int buffer[3];
};
struct Vector3D_R000287_8713_1
{
  unsigned char heading;
  unsigned char coord_x;
  int coord_z;
  int buffer[3];
};
struct StreamBuffer_R000287_8713_2
{
  unsigned char head;
  unsigned char capacity;
  unsigned char tail;
  int buffer[3];
};
struct EventLog_R000287_8713_3
{
  int signature;
  unsigned char code;
  int timestamp;
  short severity;
  short seq;
  int buffer[3];
};
union TelemetryField_R000287_8713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000287_8713_1
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
void fn_R000287_8713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int segment_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_18_1 > 32)
  {
    acc_1 = ((acc_1 + (segment_18_1 * 2)) + 5) & 127;
    aux_1 ^= segment_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_18_2 > 32)
  {
    acc_2 = ((acc_2 + (segment_18_2 * 2)) + 5) & 127;
    aux_2 ^= segment_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_29_1) & 63;
  aux_2 = (aux_2 + pivot_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_42_1 = local_arr_1[aux_1 % 3];
  int damping_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_18_1 == segment_18_2);
  assert(pivot_29_1 == pivot_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_42_1 == damping_42_2);
}

int fn_R000287_8713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int segment_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_18 > 32)
  {
    acc = ((acc + (segment_18 * 2)) + 5) & 127;
    aux ^= segment_18 & 15;
  }
  else
  {
    acc = ((acc - segment_18) + 11) & 127;
    aux += 3;
  }
  int pivot_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_29) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_42 = local_arr[aux % 3];
  acc = (acc + (damping_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_73_1) & 63;
  aux_2 = (aux_2 + phase_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_56_1 = local_arr_1[aux_1 % 3];
  int anchor_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_73_1 == phase_73_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_56_1 == anchor_56_2);
}

int fn_R000287_8713_1(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_73) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_56 = local_arr[aux % 3];
  acc = (acc + (anchor_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_21_1 > 44)
  {
    acc_1 = ((acc_1 + (margin_21_1 * 2)) + 5) & 127;
    aux_1 ^= margin_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_21_2 > 44)
  {
    acc_2 = ((acc_2 + (margin_21_2 * 2)) + 5) & 127;
    aux_2 ^= margin_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_21_1 == margin_21_2);
}

int fn_R000287_8713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_21 > 44)
  {
    acc = ((acc + (margin_21 * 2)) + 5) & 127;
    aux ^= margin_21 & 15;
  }
  else
  {
    acc = ((acc - margin_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_80_1)
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

  switch (accumulator_80_2)
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

  int checksum_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_67_1 > 22)
  {
    acc_1 = ((acc_1 + (checksum_67_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_67_2 > 22)
  {
    acc_2 = ((acc_2 + (checksum_67_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_80_1 == accumulator_80_2);
  assert(checksum_67_1 == checksum_67_2);
}

int fn_R000287_8713_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_80 = (aux + st.buffer[1]) & 3;
  switch (accumulator_80)
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

  int checksum_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_67 > 22)
  {
    acc = ((acc + (checksum_67 * 2)) + 5) & 127;
    aux ^= checksum_67 & 15;
  }
  else
  {
    acc = ((acc - checksum_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_89_1 = local_arr_1[aux_1 % 3];
  int checksum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_89_2 * 2)) & 127;
  int damping_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_41_1)
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

  switch (damping_41_2)
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

  int pivot_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_97_1 > 28)
  {
    acc_1 = ((acc_1 + (pivot_97_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_97_2 > 28)
  {
    acc_2 = ((acc_2 + (pivot_97_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_89_1 == checksum_89_2);
  assert(damping_41_1 == damping_41_2);
  assert(pivot_97_1 == pivot_97_2);
}

int fn_R000287_8713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int checksum_89 = local_arr[aux % 3];
  acc = (acc + (checksum_89 * 2)) & 127;
  int damping_41 = (aux + st.buffer[1]) & 3;
  switch (damping_41)
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

  int pivot_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_97 > 28)
  {
    acc = ((acc + (pivot_97 * 2)) + 5) & 127;
    aux ^= pivot_97 & 15;
  }
  else
  {
    acc = ((acc - pivot_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000287_8713_1 st_1 = {0};
  struct Vector3D_R000287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_19_1)
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

  switch (pivot_19_2)
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

  int window_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_69_1 > 33)
  {
    acc_1 = ((acc_1 + (window_69_1 * 2)) + 5) & 127;
    aux_1 ^= window_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_69_2 > 33)
  {
    acc_2 = ((acc_2 + (window_69_2 * 2)) + 5) & 127;
    aux_2 ^= window_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_19_1 == pivot_19_2);
  assert(window_69_1 == window_69_2);
}

int fn_R000287_8713_5(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_19 = (aux + st.buffer[1]) & 3;
  switch (pivot_19)
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

  int window_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_69 > 33)
  {
    acc = ((acc + (window_69 * 2)) + 5) & 127;
    aux ^= window_69 & 15;
  }
  else
  {
    acc = ((acc - window_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_49_1) & 63;
  aux_2 = (aux_2 + factor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_68_1 > 23)
  {
    acc_1 = ((acc_1 + (scale_68_1 * 2)) + 5) & 127;
    aux_1 ^= scale_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_68_2 > 23)
  {
    acc_2 = ((acc_2 + (scale_68_2 * 2)) + 5) & 127;
    aux_2 ^= scale_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  assert(scale_68_1 == scale_68_2);
}

int fn_R000287_8713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_49) & 63;
  acc ^= aux;
  int scale_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_68 > 23)
  {
    acc = ((acc + (scale_68 * 2)) + 5) & 127;
    aux ^= scale_68 & 15;
  }
  else
  {
    acc = ((acc - scale_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tracker_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_10_1)
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

  switch (tracker_10_2)
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

  int index_reg_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_16_1 > 30)
  {
    acc_1 = ((acc_1 + (index_reg_16_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_16_2 > 30)
  {
    acc_2 = ((acc_2 + (index_reg_16_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_16_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_10_1 == tracker_10_2);
  assert(index_reg_16_1 == index_reg_16_2);
}

int fn_R000287_8713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tracker_10 = (aux + st.buffer[1]) & 3;
  switch (tracker_10)
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

  int index_reg_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_16 > 30)
  {
    acc = ((acc + (index_reg_16 * 2)) + 5) & 127;
    aux ^= index_reg_16 & 15;
  }
  else
  {
    acc = ((acc - index_reg_16) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_10_1)
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

  switch (residue_10_2)
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

  int segment_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_17_1 > 24)
  {
    acc_1 = ((acc_1 + (segment_17_1 * 2)) + 5) & 127;
    aux_1 ^= segment_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_17_2 > 24)
  {
    acc_2 = ((acc_2 + (segment_17_2 * 2)) + 5) & 127;
    aux_2 ^= segment_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_91_1) & 63;
  aux_2 = (aux_2 + margin_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_51_1 = local_arr_1[aux_1 % 3];
  int pivot_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_10_1 == residue_10_2);
  assert(segment_17_1 == segment_17_2);
  assert(margin_91_1 == margin_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_51_1 == pivot_51_2);
}

int fn_R000287_8713_8(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_10 = (aux + st.buffer[1]) & 3;
  switch (residue_10)
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

  int segment_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_17 > 24)
  {
    acc = ((acc + (segment_17 * 2)) + 5) & 127;
    aux ^= segment_17 & 15;
  }
  else
  {
    acc = ((acc - segment_17) + 11) & 127;
    aux += 3;
  }
  int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_91) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_51 = local_arr[aux % 3];
  acc = (acc + (pivot_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_77_1)
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

  switch (scale_77_2)
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

  int threshold_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_35_1) & 63;
  aux_2 = (aux_2 + threshold_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_77_1 == scale_77_2);
  assert(threshold_35_1 == threshold_35_2);
}

int fn_R000287_8713_9(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_77 = (aux + st.buffer[1]) & 3;
  switch (scale_77)
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

  int threshold_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000287_8713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int metric_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_43_1 > 39)
  {
    acc_1 = ((acc_1 + (metric_43_1 * 2)) + 5) & 127;
    aux_1 ^= metric_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_43_2 > 39)
  {
    acc_2 = ((acc_2 + (metric_43_2 * 2)) + 5) & 127;
    aux_2 ^= metric_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_50_1) & 63;
  aux_2 = (aux_2 + factor_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_15_1 = local_arr_1[aux_1 % 3];
  int scale_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_43_1 == metric_43_2);
  assert(factor_50_1 == factor_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_15_1 == scale_15_2);
}

int fn_R000287_8713_10(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int metric_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_43 > 39)
  {
    acc = ((acc + (metric_43 * 2)) + 5) & 127;
    aux ^= metric_43 & 15;
  }
  else
  {
    acc = ((acc - metric_43) + 11) & 127;
    aux += 3;
  }
  int factor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_15 = local_arr[aux % 3];
  acc = (acc + (scale_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_45_1 > 11)
  {
    acc_1 = ((acc_1 + (scale_45_1 * 2)) + 5) & 127;
    aux_1 ^= scale_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_45_2 > 11)
  {
    acc_2 = ((acc_2 + (scale_45_2 * 2)) + 5) & 127;
    aux_2 ^= scale_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_76_1) & 63;
  aux_2 = (aux_2 + offset_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_45_1 == scale_45_2);
  assert(offset_76_1 == offset_76_2);
}

int fn_R000287_8713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_45 > 11)
  {
    acc = ((acc + (scale_45 * 2)) + 5) & 127;
    aux ^= scale_45 & 15;
  }
  else
  {
    acc = ((acc - scale_45) + 11) & 127;
    aux += 3;
  }
  int offset_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_76) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000287_8713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_45_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_45_1 * 2)) + 5) & 127;
    aux_1 ^= mask_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_45_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_45_2 * 2)) + 5) & 127;
    aux_2 ^= mask_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_70_1) & 63;
  aux_2 = (aux_2 + sample_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_45_1 == mask_45_2);
  assert(sample_70_1 == sample_70_2);
}

int fn_R000287_8713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_45 > 47)
  {
    acc = ((acc + (mask_45 * 2)) + 5) & 127;
    aux ^= mask_45 & 15;
  }
  else
  {
    acc = ((acc - mask_45) + 11) & 127;
    aux += 3;
  }
  int sample_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_70) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000287_8713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_18_1 = local_arr_1[aux_1 % 3];
  int tally_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_18_2 * 2)) & 127;
  int vector_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_17_1) & 63;
  aux_2 = (aux_2 + vector_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_34_1)
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

  switch (offset_34_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_18_1 == tally_18_2);
  assert(vector_17_1 == vector_17_2);
  assert(offset_34_1 == offset_34_2);
}

int fn_R000287_8713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tally_18 = local_arr[aux % 3];
  acc = (acc + (tally_18 * 2)) & 127;
  int vector_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_17) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_34 = (aux + st.buffer[1]) & 3;
  switch (offset_34)
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

void fn_R000287_8713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int quotient_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_16_1) & 63;
  aux_2 = (aux_2 + quotient_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_78_1 = local_arr_1[aux_1 % 3];
  int checksum_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_78_2 * 2)) & 127;
  int damping_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_64_1)
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

  switch (damping_64_2)
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
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_16_1 == quotient_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_78_1 == checksum_78_2);
  assert(damping_64_1 == damping_64_2);
}

int fn_R000287_8713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int quotient_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_78 = local_arr[aux % 3];
  acc = (acc + (checksum_78 * 2)) & 127;
  int damping_64 = (aux + st.buffer[1]) & 3;
  switch (damping_64)
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

void fn_R000287_8713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_58_1)
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

  switch (threshold_58_2)
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

  int quantum_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_76_1 > 49)
  {
    acc_1 = ((acc_1 + (quantum_76_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_76_2 > 49)
  {
    acc_2 = ((acc_2 + (quantum_76_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_15_1 = local_arr_1[aux_1 % 3];
  int checksum_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_15_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_58_1 == threshold_58_2);
  assert(quantum_76_1 == quantum_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_15_1 == checksum_15_2);
}

int fn_R000287_8713_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000287_8713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_58 = (aux + st.buffer[1]) & 3;
  switch (threshold_58)
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

  int quantum_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_76 > 49)
  {
    acc = ((acc + (quantum_76 * 2)) + 5) & 127;
    aux ^= quantum_76 & 15;
  }
  else
  {
    acc = ((acc - quantum_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_15 = local_arr[aux % 3];
  acc = (acc + (checksum_15 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_99_1)
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

  switch (accumulator_99_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
}

int fn_R000287_8713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_99 = (aux + st.buffer[1]) & 3;
  switch (accumulator_99)
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

void fn_R000287_8713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_54_1 = local_arr_1[aux_1 % 3];
  int offset_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_54_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_15_1) & 63;
  aux_2 = (aux_2 + stride_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_54_1 == offset_54_2);
  assert(stride_15_1 == stride_15_2);
}

int fn_R000287_8713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int offset_54 = local_arr[aux % 3];
  acc = (acc + (offset_54 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000287_8713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_34_1 = local_arr_1[aux_1 % 3];
  int parity_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_34_2 * 2)) & 127;
  int accumulator_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_96_1)
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

  switch (accumulator_96_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_34_1 == parity_34_2);
  assert(accumulator_96_1 == accumulator_96_2);
}

int fn_R000287_8713_18(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int parity_34 = local_arr[aux % 3];
  acc = (acc + (parity_34 * 2)) & 127;
  int accumulator_96 = (aux + st.buffer[1]) & 3;
  switch (accumulator_96)
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

void fn_R000287_8713_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_72_1) & 63;
  aux_2 = (aux_2 + vector_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_51_1 = local_arr_1[aux_1 % 3];
  int mask_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_72_1 == vector_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_51_1 == mask_51_2);
}

int fn_R000287_8713_19(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int mask_51 = local_arr[aux % 3];
  acc = (acc + (mask_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_62_1 = local_arr_1[aux_1 % 3];
  int margin_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_62_2 * 2)) & 127;
  int delta_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_67_1 > 42)
  {
    acc_1 = ((acc_1 + (delta_67_1 * 2)) + 5) & 127;
    aux_1 ^= delta_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_67_2 > 42)
  {
    acc_2 = ((acc_2 + (delta_67_2 * 2)) + 5) & 127;
    aux_2 ^= delta_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_62_1 == margin_62_2);
  assert(delta_67_1 == delta_67_2);
}

int fn_R000287_8713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int margin_62 = local_arr[aux % 3];
  acc = (acc + (margin_62 * 2)) & 127;
  int delta_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_67 > 42)
  {
    acc = ((acc + (delta_67 * 2)) + 5) & 127;
    aux ^= delta_67 & 15;
  }
  else
  {
    acc = ((acc - delta_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st_1 = {0};
  struct CipherContext_R000287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int phase_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_26_1)
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

  switch (phase_26_2)
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

  int segment_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_88_1 > 33)
  {
    acc_1 = ((acc_1 + (segment_88_1 * 2)) + 5) & 127;
    aux_1 ^= segment_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_88_2 > 33)
  {
    acc_2 = ((acc_2 + (segment_88_2 * 2)) + 5) & 127;
    aux_2 ^= segment_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_69_1 = local_arr_1[aux_1 % 3];
  int scale_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_69_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.tag == st_2.tag);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_26_1 == phase_26_2);
  assert(segment_88_1 == segment_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_69_1 == scale_69_2);
}

int fn_R000287_8713_21(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int phase_26 = (aux + st.buffer[1]) & 3;
  switch (phase_26)
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

  int segment_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_88 > 33)
  {
    acc = ((acc + (segment_88 * 2)) + 5) & 127;
    aux ^= segment_88 & 15;
  }
  else
  {
    acc = ((acc - segment_88) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_69 = local_arr[aux % 3];
  acc = (acc + (scale_69 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000287_8713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st_1 = {0};
  struct EventLog_R000287_8713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int weight_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_16_1) & 63;
  aux_2 = (aux_2 + weight_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_67_1 > 46)
  {
    acc_1 = ((acc_1 + (segment_67_1 * 2)) + 5) & 127;
    aux_1 ^= segment_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_67_2 > 46)
  {
    acc_2 = ((acc_2 + (segment_67_2 * 2)) + 5) & 127;
    aux_2 ^= segment_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_16_1 == weight_16_2);
  assert(segment_67_1 == segment_67_2);
}

int fn_R000287_8713_22(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000287_8713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int weight_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_16) & 63;
  acc ^= aux;
  int segment_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_67 > 46)
  {
    acc = ((acc + (segment_67 * 2)) + 5) & 127;
    aux ^= segment_67 & 15;
  }
  else
  {
    acc = ((acc - segment_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000287_8713_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000287_8713_1 st_1 = {0};
  struct Vector3D_R000287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int tally_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_72_1) & 63;
  aux_2 = (aux_2 + tally_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_13_1 = local_arr_1[aux_1 % 3];
  int checksum_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_13_2 * 2)) & 127;
  int sample_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_60_1 > 50)
  {
    acc_1 = ((acc_1 + (sample_60_1 * 2)) + 5) & 127;
    aux_1 ^= sample_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_60_2 > 50)
  {
    acc_2 = ((acc_2 + (sample_60_2 * 2)) + 5) & 127;
    aux_2 ^= sample_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_72_1 == tally_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_13_1 == checksum_13_2);
  assert(sample_60_1 == sample_60_2);
}

int fn_R000287_8713_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int tally_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_13 = local_arr[aux % 3];
  acc = (acc + (checksum_13 * 2)) & 127;
  int sample_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_60 > 50)
  {
    acc = ((acc + (sample_60 * 2)) + 5) & 127;
    aux ^= sample_60 & 15;
  }
  else
  {
    acc = ((acc - sample_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000287_0_1;
  int sec_r000287_0_2;
  int sec_r000287_1_1;
  int sec_r000287_1_2;
  int sec_r000287_2_1;
  int sec_r000287_2_2;
  int sec_r000287_3_1;
  int sec_r000287_3_2;
  int sec_r000287_4_1;
  int sec_r000287_4_2;
  int sec_r000287_5_1;
  int sec_r000287_5_2;
  int sec_r000287_6_1;
  int sec_r000287_6_2;
  int sec_r000287_7_1;
  int sec_r000287_7_2;
  int sec_r000287_8_1;
  int sec_r000287_8_2;
  int sec_r000287_9_1;
  int sec_r000287_9_2;
  int sec_r000287_10_1;
  int sec_r000287_10_2;
  int sec_r000287_11_1;
  int sec_r000287_11_2;
  int sec_r000287_12_1;
  int sec_r000287_12_2;
  int sec_r000287_13_1;
  int sec_r000287_13_2;
  int sec_r000287_14_1;
  int sec_r000287_14_2;
  int sec_r000287_15_1;
  int sec_r000287_15_2;
  int sec_r000287_16_1;
  int sec_r000287_16_2;
  int sec_r000287_17_1;
  int sec_r000287_17_2;
  int sec_r000287_18_1;
  int sec_r000287_18_2;
  int sec_r000287_19_1;
  int sec_r000287_19_2;
  int sec_r000287_20_1;
  int sec_r000287_20_2;
  int pub_r000287_0_1;
  int pub_r000287_0_2;
  int pub_r000287_1_1;
  int pub_r000287_1_2;
  int pub_r000287_2_1;
  int pub_r000287_2_2;
  int pub_r000287_3_1;
  int pub_r000287_3_2;
  int pub_r000287_4_1;
  int pub_r000287_4_2;
  int pub_r000287_5_1;
  int pub_r000287_5_2;
  int pub_r000287_6_1;
  int pub_r000287_6_2;
  int pub_r000287_7_1;
  int pub_r000287_7_2;
  int pub_r000287_8_1;
  int pub_r000287_8_2;
  int pub_r000287_9_1;
  int pub_r000287_9_2;
  int pub_r000287_10_1;
  int pub_r000287_10_2;
  int pub_r000287_11_1;
  int pub_r000287_11_2;
  int pub_r000287_12_1;
  int pub_r000287_12_2;
  int pub_r000287_13_1;
  int pub_r000287_13_2;
  int pub_r000287_14_1;
  int pub_r000287_14_2;
  int pub_r000287_15_1;
  int pub_r000287_15_2;
  int pub_r000287_16_1;
  int pub_r000287_16_2;
  int pub_r000287_17_1;
  int pub_r000287_17_2;
  int pub_r000287_18_1;
  int pub_r000287_18_2;
  int pub_r000287_19_1;
  int pub_r000287_19_2;
  int pub_r000287_20_1;
  int pub_r000287_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000287_0_1 >= (-100)) && (pub_r000287_0_1 <= 100));
  __CPROVER_assume((pub_r000287_0_2 >= (-100)) && (pub_r000287_0_2 <= 100));
  __CPROVER_assume((pub_r000287_1_1 >= (-100)) && (pub_r000287_1_1 <= 100));
  __CPROVER_assume((pub_r000287_1_2 >= (-100)) && (pub_r000287_1_2 <= 100));
  __CPROVER_assume((pub_r000287_2_1 >= (-100)) && (pub_r000287_2_1 <= 100));
  __CPROVER_assume((pub_r000287_2_2 >= (-100)) && (pub_r000287_2_2 <= 100));
  __CPROVER_assume((pub_r000287_3_1 >= (-100)) && (pub_r000287_3_1 <= 100));
  __CPROVER_assume((pub_r000287_3_2 >= (-100)) && (pub_r000287_3_2 <= 100));
  __CPROVER_assume((pub_r000287_4_1 >= (-100)) && (pub_r000287_4_1 <= 100));
  __CPROVER_assume((pub_r000287_4_2 >= (-100)) && (pub_r000287_4_2 <= 100));
  __CPROVER_assume((pub_r000287_5_1 >= (-100)) && (pub_r000287_5_1 <= 100));
  __CPROVER_assume((pub_r000287_5_2 >= (-100)) && (pub_r000287_5_2 <= 100));
  __CPROVER_assume((pub_r000287_6_1 >= (-100)) && (pub_r000287_6_1 <= 100));
  __CPROVER_assume((pub_r000287_6_2 >= (-100)) && (pub_r000287_6_2 <= 100));
  __CPROVER_assume((pub_r000287_7_1 >= (-100)) && (pub_r000287_7_1 <= 100));
  __CPROVER_assume((pub_r000287_7_2 >= (-100)) && (pub_r000287_7_2 <= 100));
  __CPROVER_assume((pub_r000287_8_1 >= (-100)) && (pub_r000287_8_1 <= 100));
  __CPROVER_assume((pub_r000287_8_2 >= (-100)) && (pub_r000287_8_2 <= 100));
  __CPROVER_assume((pub_r000287_9_1 >= (-100)) && (pub_r000287_9_1 <= 100));
  __CPROVER_assume((pub_r000287_9_2 >= (-100)) && (pub_r000287_9_2 <= 100));
  __CPROVER_assume((pub_r000287_10_1 >= (-100)) && (pub_r000287_10_1 <= 100));
  __CPROVER_assume((pub_r000287_10_2 >= (-100)) && (pub_r000287_10_2 <= 100));
  __CPROVER_assume((pub_r000287_11_1 >= (-100)) && (pub_r000287_11_1 <= 100));
  __CPROVER_assume((pub_r000287_11_2 >= (-100)) && (pub_r000287_11_2 <= 100));
  __CPROVER_assume((pub_r000287_12_1 >= (-100)) && (pub_r000287_12_1 <= 100));
  __CPROVER_assume((pub_r000287_12_2 >= (-100)) && (pub_r000287_12_2 <= 100));
  __CPROVER_assume((pub_r000287_13_1 >= (-100)) && (pub_r000287_13_1 <= 100));
  __CPROVER_assume((pub_r000287_13_2 >= (-100)) && (pub_r000287_13_2 <= 100));
  __CPROVER_assume((pub_r000287_14_1 >= (-100)) && (pub_r000287_14_1 <= 100));
  __CPROVER_assume((pub_r000287_14_2 >= (-100)) && (pub_r000287_14_2 <= 100));
  __CPROVER_assume((pub_r000287_15_1 >= (-100)) && (pub_r000287_15_1 <= 100));
  __CPROVER_assume((pub_r000287_15_2 >= (-100)) && (pub_r000287_15_2 <= 100));
  __CPROVER_assume((pub_r000287_16_1 >= (-100)) && (pub_r000287_16_1 <= 100));
  __CPROVER_assume((pub_r000287_16_2 >= (-100)) && (pub_r000287_16_2 <= 100));
  __CPROVER_assume((pub_r000287_17_1 >= (-100)) && (pub_r000287_17_1 <= 100));
  __CPROVER_assume((pub_r000287_17_2 >= (-100)) && (pub_r000287_17_2 <= 100));
  __CPROVER_assume((pub_r000287_18_1 >= (-100)) && (pub_r000287_18_1 <= 100));
  __CPROVER_assume((pub_r000287_18_2 >= (-100)) && (pub_r000287_18_2 <= 100));
  __CPROVER_assume((pub_r000287_19_1 >= (-100)) && (pub_r000287_19_1 <= 100));
  __CPROVER_assume((pub_r000287_19_2 >= (-100)) && (pub_r000287_19_2 <= 100));
  __CPROVER_assume((pub_r000287_20_1 >= (-100)) && (pub_r000287_20_1 <= 100));
  __CPROVER_assume((pub_r000287_20_2 >= (-100)) && (pub_r000287_20_2 <= 100));
  __CPROVER_assume((sec_r000287_0_1 >= 0) && (sec_r000287_0_1 <= 255));
  __CPROVER_assume((sec_r000287_0_2 >= 0) && (sec_r000287_0_2 <= 255));
  __CPROVER_assume((sec_r000287_1_1 >= 0) && (sec_r000287_1_1 <= 255));
  __CPROVER_assume((sec_r000287_1_2 >= 0) && (sec_r000287_1_2 <= 255));
  __CPROVER_assume((sec_r000287_2_1 >= 0) && (sec_r000287_2_1 <= 255));
  __CPROVER_assume((sec_r000287_2_2 >= 0) && (sec_r000287_2_2 <= 255));
  __CPROVER_assume((sec_r000287_3_1 >= 0) && (sec_r000287_3_1 <= 255));
  __CPROVER_assume((sec_r000287_3_2 >= 0) && (sec_r000287_3_2 <= 255));
  __CPROVER_assume((sec_r000287_4_1 >= 0) && (sec_r000287_4_1 <= 255));
  __CPROVER_assume((sec_r000287_4_2 >= 0) && (sec_r000287_4_2 <= 255));
  __CPROVER_assume((sec_r000287_5_1 >= 0) && (sec_r000287_5_1 <= 255));
  __CPROVER_assume((sec_r000287_5_2 >= 0) && (sec_r000287_5_2 <= 255));
  __CPROVER_assume((sec_r000287_6_1 >= 0) && (sec_r000287_6_1 <= 255));
  __CPROVER_assume((sec_r000287_6_2 >= 0) && (sec_r000287_6_2 <= 255));
  __CPROVER_assume((sec_r000287_7_1 >= 0) && (sec_r000287_7_1 <= 255));
  __CPROVER_assume((sec_r000287_7_2 >= 0) && (sec_r000287_7_2 <= 255));
  __CPROVER_assume((sec_r000287_8_1 >= 0) && (sec_r000287_8_1 <= 255));
  __CPROVER_assume((sec_r000287_8_2 >= 0) && (sec_r000287_8_2 <= 255));
  __CPROVER_assume((sec_r000287_9_1 >= 0) && (sec_r000287_9_1 <= 255));
  __CPROVER_assume((sec_r000287_9_2 >= 0) && (sec_r000287_9_2 <= 255));
  __CPROVER_assume((sec_r000287_10_1 >= 0) && (sec_r000287_10_1 <= 255));
  __CPROVER_assume((sec_r000287_10_2 >= 0) && (sec_r000287_10_2 <= 255));
  __CPROVER_assume((sec_r000287_11_1 >= 0) && (sec_r000287_11_1 <= 255));
  __CPROVER_assume((sec_r000287_11_2 >= 0) && (sec_r000287_11_2 <= 255));
  __CPROVER_assume((sec_r000287_12_1 >= 0) && (sec_r000287_12_1 <= 255));
  __CPROVER_assume((sec_r000287_12_2 >= 0) && (sec_r000287_12_2 <= 255));
  __CPROVER_assume((sec_r000287_13_1 >= 0) && (sec_r000287_13_1 <= 255));
  __CPROVER_assume((sec_r000287_13_2 >= 0) && (sec_r000287_13_2 <= 255));
  __CPROVER_assume((sec_r000287_14_1 >= 0) && (sec_r000287_14_1 <= 255));
  __CPROVER_assume((sec_r000287_14_2 >= 0) && (sec_r000287_14_2 <= 255));
  __CPROVER_assume((sec_r000287_15_1 >= 0) && (sec_r000287_15_1 <= 255));
  __CPROVER_assume((sec_r000287_15_2 >= 0) && (sec_r000287_15_2 <= 255));
  __CPROVER_assume((sec_r000287_16_1 >= 0) && (sec_r000287_16_1 <= 255));
  __CPROVER_assume((sec_r000287_16_2 >= 0) && (sec_r000287_16_2 <= 255));
  __CPROVER_assume((sec_r000287_17_1 >= 0) && (sec_r000287_17_1 <= 255));
  __CPROVER_assume((sec_r000287_17_2 >= 0) && (sec_r000287_17_2 <= 255));
  __CPROVER_assume((sec_r000287_18_1 >= 0) && (sec_r000287_18_1 <= 255));
  __CPROVER_assume((sec_r000287_18_2 >= 0) && (sec_r000287_18_2 <= 255));
  __CPROVER_assume((sec_r000287_19_1 >= 0) && (sec_r000287_19_1 <= 255));
  __CPROVER_assume((sec_r000287_19_2 >= 0) && (sec_r000287_19_2 <= 255));
  __CPROVER_assume((sec_r000287_20_1 >= 0) && (sec_r000287_20_1 <= 255));
  __CPROVER_assume((sec_r000287_20_2 >= 0) && (sec_r000287_20_2 <= 255));
  struct CipherContext_R000287_8713_0 st_var_0_1 = {0};
  struct CipherContext_R000287_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000287_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000287_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000287_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000287_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000287_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000287_0_2 + 7) & 15;
  struct Vector3D_R000287_8713_1 st_var_1_1 = {0};
  struct Vector3D_R000287_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000287_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000287_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000287_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000287_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000287_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000287_0_2 + 9) & 15;
  struct StreamBuffer_R000287_8713_2 st_var_2_1 = {0};
  struct StreamBuffer_R000287_8713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000287_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000287_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000287_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000287_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000287_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000287_0_2 + 11) & 15;
  struct EventLog_R000287_8713_3 st_var_3_1 = {0};
  struct EventLog_R000287_8713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000287_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000287_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000287_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000287_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000287_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000287_0_2 + 13) & 15;
  union TelemetryField_R000287_8713_0 u_var_1;
  union TelemetryField_R000287_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
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
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 29)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 29)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 32)
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
  if (stage_v_5_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 32)
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
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (12 & 31);
  int stage_v_7_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (12 & 31);
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= (stage_v_7_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_7_2 << 1) & 127;
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
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 11) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 11) & 15;
  int stage_v_10_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_10_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= stage_v_10_1;
  chk_sum_2 ^= stage_v_10_2;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((sec_r000287_15_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((sec_r000287_15_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000287_12_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000287_12_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((sec_r000287_1_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((sec_r000287_1_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((sec_r000287_18_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000287_20_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000287_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000287_20_1 + 7) & 127;
  }
  if ((sec_r000287_18_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000287_20_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000287_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000287_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000287_17_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000287_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000287_17_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000287_17_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000287_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000287_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000287_2_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000287_9_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000287_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000287_9_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000287_2_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000287_9_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000287_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000287_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((sec_r000287_12_1 & 1) != 0)
  {
    if ((sec_r000287_20_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((sec_r000287_12_2 & 1) != 0)
  {
    if ((sec_r000287_20_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000287_3_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000287_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000287_3_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000287_3_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000287_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000287_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000287_6_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000287_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000287_6_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000287_6_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000287_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000287_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000287_17_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000287_17_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000287_9_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000287_9_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000287_8_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000287_8_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000287_8_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000287_3_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000287_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000287_3_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000287_8_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000287_3_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000287_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000287_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r000287_14_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000287_17_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000287_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000287_17_1 + 7) & 127;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r000287_14_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000287_17_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000287_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000287_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((sec_r000287_9_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((sec_r000287_9_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((sec_r000287_20_1 & 1) != 0)
  {
    if ((sec_r000287_14_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((sec_r000287_20_2 & 1) != 0)
  {
    if ((sec_r000287_14_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000287_19_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000287_1_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000287_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000287_1_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000287_19_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000287_1_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000287_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000287_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000287_6_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000287_17_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000287_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000287_17_1 + 7) & 127;
  }
  if ((sec_r000287_6_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000287_17_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000287_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000287_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000287_9_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000287_11_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000287_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000287_11_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000287_9_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000287_11_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000287_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000287_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000287_2_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000287_2_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((sec_r000287_12_1 & 1) != 0)
  {
    if ((sec_r000287_6_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000287_6_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000287_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000287_6_1 + 7) & 127;
  }
  if ((sec_r000287_12_2 & 1) != 0)
  {
    if ((sec_r000287_6_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000287_6_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000287_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000287_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000287_7_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000287_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000287_7_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000287_7_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000287_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000287_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000287_9_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000287_9_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000287_19_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000287_2_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000287_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000287_2_1 + 7) & 127;
  }
  if ((sec_r000287_19_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000287_2_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000287_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000287_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000287_8_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000287_8_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000287_8_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((sec_r000287_8_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((sec_r000287_1_1 & 1) != 0)
  {
    if ((sec_r000287_7_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((sec_r000287_1_2 & 1) != 0)
  {
    if ((sec_r000287_7_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((sec_r000287_7_1 & 1) != 0)
  {
    if ((sec_r000287_20_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000287_10_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000287_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000287_10_1 + 7) & 127;
  }
  if ((sec_r000287_7_2 & 1) != 0)
  {
    if ((sec_r000287_20_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000287_10_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000287_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000287_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000287_14_1 & 1) != 0)
  {
    if ((sec_r000287_2_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((sec_r000287_14_2 & 1) != 0)
  {
    if ((sec_r000287_2_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000287_17_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000287_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000287_17_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000287_17_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000287_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000287_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000287_11_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000287_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000287_11_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000287_11_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000287_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000287_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000287_6_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000287_6_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000287_17_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000287_17_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000287_6_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000287_6_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000287_14_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((sec_r000287_14_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((sec_r000287_20_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000287_8_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000287_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000287_8_1 + 7) & 127;
  }
  if ((sec_r000287_20_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000287_8_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000287_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000287_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000287_7_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000287_11_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000287_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000287_11_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000287_7_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000287_11_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000287_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000287_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((sec_r000287_4_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000287_3_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000287_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000287_3_1 + 7) & 127;
  }
  if ((sec_r000287_4_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000287_3_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000287_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000287_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000287_19_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000287_19_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000287_14_1 & 1) != 0)
  {
    if ((sec_r000287_14_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((sec_r000287_14_2 & 1) != 0)
  {
    if ((sec_r000287_14_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000287_10_1 & 1) != 0)
  {
    if ((sec_r000287_17_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000287_16_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000287_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000287_16_1 + 7) & 127;
  }
  if ((sec_r000287_10_2 & 1) != 0)
  {
    if ((sec_r000287_17_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000287_16_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000287_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000287_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000287_20_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000287_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000287_20_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000287_20_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000287_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000287_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000287_20_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000287_1_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000287_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000287_1_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000287_20_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000287_1_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000287_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000287_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000287_6_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000287_7_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000287_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000287_7_1 + 7) & 127;
  }
  if ((sec_r000287_6_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000287_7_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000287_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000287_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000287_7_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000287_7_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000287_17_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000287_17_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((sec_r000287_8_1 & 1) != 0)
  {
    if ((sec_r000287_12_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000287_3_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000287_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000287_3_1 + 7) & 127;
  }
  if ((sec_r000287_8_2 & 1) != 0)
  {
    if ((sec_r000287_12_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000287_3_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000287_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000287_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000287_11_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000287_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000287_11_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000287_11_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000287_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000287_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000287_14_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000287_8_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000287_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000287_8_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000287_14_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000287_8_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000287_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000287_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((sec_r000287_16_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000287_20_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000287_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000287_20_1 + 7) & 127;
  }
  if ((sec_r000287_16_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000287_20_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000287_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000287_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_43_1 & 1) != 0)
  {
    if ((sec_r000287_17_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_43_2 & 1) != 0)
  {
    if ((sec_r000287_17_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000287_14_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000287_9_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000287_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000287_9_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000287_14_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000287_9_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000287_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000287_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000287_13_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000287_10_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000287_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000287_10_1 + 7) & 127;
  }
  if ((sec_r000287_13_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000287_10_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000287_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000287_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000287_16_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000287_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000287_16_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000287_16_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000287_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000287_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000287_12_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000287_12_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000287_17_1 & 1) != 0)
  {
    if ((sec_r000287_20_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000287_17_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000287_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000287_17_1 + 7) & 127;
  }
  if ((sec_r000287_17_2 & 1) != 0)
  {
    if ((sec_r000287_20_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000287_17_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000287_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000287_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000287_8_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000287_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000287_8_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000287_8_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000287_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000287_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000287_7_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000287_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000287_7_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000287_7_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000287_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000287_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_92_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000287_7_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000287_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000287_7_1 + 7) & 127;
  }
  if ((stage_v_92_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000287_7_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000287_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000287_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000287_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000287_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000287_9_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000287_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000287_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000287_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000287_9_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000287_6_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000287_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000287_6_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000287_9_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000287_6_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000287_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000287_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000287_7_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000287_16_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000287_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000287_16_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000287_7_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000287_16_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000287_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000287_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((sec_r000287_18_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((sec_r000287_18_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000287_13_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000287_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000287_13_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000287_13_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000287_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000287_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000287_16_1 & 1) != 0)
  {
    if ((sec_r000287_16_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((sec_r000287_16_2 & 1) != 0)
  {
    if ((sec_r000287_16_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000287_12_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((sec_r000287_12_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000287_6_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((sec_r000287_6_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000287_11_1 & 1) != 0)
  {
    if ((sec_r000287_19_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((sec_r000287_11_2 & 1) != 0)
  {
    if ((sec_r000287_19_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000287_17_1 & 1) != 0)
  {
    if ((sec_r000287_20_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000287_5_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000287_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000287_5_1 + 7) & 127;
  }
  if ((sec_r000287_17_2 & 1) != 0)
  {
    if ((sec_r000287_20_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000287_5_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000287_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000287_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000287_5_1 & 1) != 0)
  {
    if ((sec_r000287_2_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000287_4_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000287_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000287_4_1 + 7) & 127;
  }
  if ((sec_r000287_5_2 & 1) != 0)
  {
    if ((sec_r000287_2_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000287_4_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000287_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000287_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000287_15_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000287_15_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000287_2_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000287_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000287_2_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000287_2_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000287_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000287_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000287_0_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000287_20_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000287_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000287_20_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000287_0_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000287_20_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000287_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000287_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r000287_8_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r000287_8_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((sec_r000287_10_1 & 1) != 0)
  {
    if ((sec_r000287_1_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000287_1_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000287_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000287_1_1 + 7) & 127;
  }
  if ((sec_r000287_10_2 & 1) != 0)
  {
    if ((sec_r000287_1_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000287_1_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000287_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000287_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000287_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000287_12_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000287_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000287_12_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000287_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000287_12_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000287_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000287_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000287_0_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000287_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000287_0_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000287_0_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000287_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000287_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000287_15_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000287_15_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000287_8_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000287_8_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000287_5_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000287_5_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000287_18_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000287_18_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000287_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000287_18_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000287_18_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000287_18_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000287_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000287_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000287_11_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000287_11_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000287_3_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000287_14_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000287_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000287_14_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000287_3_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000287_14_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000287_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000287_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000287_11_1 & 1) != 0)
  {
    if ((sec_r000287_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000287_19_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000287_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000287_19_1 + 7) & 127;
  }
  if ((sec_r000287_11_2 & 1) != 0)
  {
    if ((sec_r000287_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000287_19_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000287_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000287_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000287_18_1 & 1) != 0)
  {
    if ((sec_r000287_2_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000287_6_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000287_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000287_6_1 + 7) & 127;
  }
  if ((sec_r000287_18_2 & 1) != 0)
  {
    if ((sec_r000287_2_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000287_6_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000287_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000287_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((sec_r000287_13_1 & 1) != 0)
  {
    if ((sec_r000287_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000287_15_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000287_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000287_15_1 + 7) & 127;
  }
  if ((sec_r000287_13_2 & 1) != 0)
  {
    if ((sec_r000287_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000287_15_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000287_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000287_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000287_16_1 & 1) != 0)
  {
    if ((sec_r000287_10_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000287_8_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000287_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000287_8_1 + 7) & 127;
  }
  if ((sec_r000287_16_2 & 1) != 0)
  {
    if ((sec_r000287_10_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000287_8_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000287_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000287_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000287_16_1 == pub_r000287_16_2);
  __CPROVER_assume(pub_r000287_8_1 == pub_r000287_8_2);
  __CPROVER_assume(pub_r000287_10_1 == pub_r000287_10_2);
  __CPROVER_assume(pub_r000287_1_1 == pub_r000287_1_2);
  __CPROVER_assume(pub_r000287_2_1 == pub_r000287_2_2);
  __CPROVER_assume(sec_r000287_18_1 != sec_r000287_18_2);
  __CPROVER_assume(sec_r000287_2_1 != sec_r000287_2_2);
  __CPROVER_assume(sec_r000287_10_1 != sec_r000287_10_2);
  __CPROVER_assume(pub_r000287_11_1 == pub_r000287_11_2);
  __CPROVER_assume(pub_r000287_18_1 == pub_r000287_18_2);
  __CPROVER_assume(pub_r000287_19_1 == pub_r000287_19_2);
  __CPROVER_assume(sec_r000287_20_1 != sec_r000287_20_2);
  __CPROVER_assume(pub_r000287_20_1 == pub_r000287_20_2);
  __CPROVER_assume(pub_r000287_13_1 == pub_r000287_13_2);
  __CPROVER_assume(pub_r000287_6_1 == pub_r000287_6_2);
  __CPROVER_assume(sec_r000287_12_1 != sec_r000287_12_2);
  __CPROVER_assume(sec_r000287_13_1 != sec_r000287_13_2);
  __CPROVER_assume(pub_r000287_0_1 == pub_r000287_0_2);
  __CPROVER_assume(pub_r000287_4_1 == pub_r000287_4_2);
  __CPROVER_assume(pub_r000287_12_1 == pub_r000287_12_2);
  __CPROVER_assume(pub_r000287_17_1 == pub_r000287_17_2);
  __CPROVER_assume(sec_r000287_15_1 != sec_r000287_15_2);
  __CPROVER_assume(sec_r000287_3_1 != sec_r000287_3_2);
  __CPROVER_assume(sec_r000287_6_1 != sec_r000287_6_2);
  __CPROVER_assume(sec_r000287_4_1 != sec_r000287_4_2);
  __CPROVER_assume(pub_r000287_15_1 == pub_r000287_15_2);
  __CPROVER_assume(sec_r000287_16_1 != sec_r000287_16_2);
  __CPROVER_assume(pub_r000287_7_1 == pub_r000287_7_2);
  __CPROVER_assume(sec_r000287_11_1 != sec_r000287_11_2);
  __CPROVER_assume(pub_r000287_5_1 == pub_r000287_5_2);
  __CPROVER_assume(sec_r000287_17_1 != sec_r000287_17_2);
  __CPROVER_assume(pub_r000287_9_1 == pub_r000287_9_2);
  __CPROVER_assume(sec_r000287_7_1 != sec_r000287_7_2);
  __CPROVER_assume(sec_r000287_5_1 != sec_r000287_5_2);
  __CPROVER_assume(pub_r000287_14_1 == pub_r000287_14_2);
  __CPROVER_assume(sec_r000287_14_1 != sec_r000287_14_2);
  __CPROVER_assume(sec_r000287_19_1 != sec_r000287_19_2);
  __CPROVER_assume(sec_r000287_1_1 != sec_r000287_1_2);
  __CPROVER_assume(sec_r000287_9_1 != sec_r000287_9_2);
  __CPROVER_assume(pub_r000287_3_1 == pub_r000287_3_2);
  __CPROVER_assume(sec_r000287_8_1 != sec_r000287_8_2);
  __CPROVER_assume(sec_r000287_0_1 != sec_r000287_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.capacity == st_var_2_2.capacity);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.severity == st_var_3_2.severity);
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
}


