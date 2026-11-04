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
struct SensorNode_R000405_513_0
{
  int status;
  short threshold;
  unsigned char gain;
  int reading;
  short calib;
  unsigned char offset;
  int buffer[3];
};
struct AudioFrame_R000405_513_1
{
  int channels;
  int envelope;
  int gain;
  short peak;
  unsigned char sample_rate;
  int buffer[3];
};
struct EventLog_R000405_513_2
{
  unsigned char timestamp;
  int facility;
  unsigned char seq;
  int severity;
  unsigned char code;
  int buffer[3];
};
union RegisterBank_R000405_513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000405_513_1
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
void fn_R000405_513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_49_1 = local_arr_1[aux_1 % 3];
  int threshold_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_49_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_32_1)
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

  switch (stride_32_2)
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

  int vector_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_37_1 > 23)
  {
    acc_1 = ((acc_1 + (vector_37_1 * 2)) + 5) & 127;
    aux_1 ^= vector_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_37_2 > 23)
  {
    acc_2 = ((acc_2 + (vector_37_2 * 2)) + 5) & 127;
    aux_2 ^= vector_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_49_1 == threshold_49_2);
  assert(stride_32_1 == stride_32_2);
  assert(vector_37_1 == vector_37_2);
}

int fn_R000405_513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int threshold_49 = local_arr[aux % 3];
  acc = (acc + (threshold_49 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_32 = (aux + st.buffer[1]) & 3;
  switch (stride_32)
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

  int vector_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_37 > 23)
  {
    acc = ((acc + (vector_37 * 2)) + 5) & 127;
    aux ^= vector_37 & 15;
  }
  else
  {
    acc = ((acc - vector_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000405_513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int checksum_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_11_1 > 13)
  {
    acc_1 = ((acc_1 + (checksum_11_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_11_2 > 13)
  {
    acc_2 = ((acc_2 + (checksum_11_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_19_1)
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

  switch (offset_19_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_11_1 == checksum_11_2);
  assert(offset_19_1 == offset_19_2);
}

int fn_R000405_513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int checksum_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_11 > 13)
  {
    acc = ((acc + (checksum_11 * 2)) + 5) & 127;
    aux ^= checksum_11 & 15;
  }
  else
  {
    acc = ((acc - checksum_11) + 11) & 127;
    aux += 3;
  }
  int offset_19 = (aux + st.buffer[1]) & 3;
  switch (offset_19)
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

void fn_R000405_513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st_1 = {0};
  struct EventLog_R000405_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int margin_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_61_1)
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

  switch (margin_61_2)
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

  int phase_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_42_1) & 63;
  aux_2 = (aux_2 + phase_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_61_1 == margin_61_2);
  assert(phase_42_1 == phase_42_2);
}

int fn_R000405_513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int margin_61 = (aux + st.buffer[1]) & 3;
  switch (margin_61)
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

  int phase_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000405_513_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_96_1 = local_arr_1[aux_1 % 3];
  int parity_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_96_2 * 2)) & 127;
  int pivot_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_11_1 > 37)
  {
    acc_1 = ((acc_1 + (pivot_11_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_11_2 > 37)
  {
    acc_2 = ((acc_2 + (pivot_11_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_11_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_52_1) & 63;
  aux_2 = (aux_2 + anchor_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_96_1 == parity_96_2);
  assert(pivot_11_1 == pivot_11_2);
  assert(anchor_52_1 == anchor_52_2);
}

int fn_R000405_513_3(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int parity_96 = local_arr[aux % 3];
  acc = (acc + (parity_96 * 2)) & 127;
  int pivot_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_11 > 37)
  {
    acc = ((acc + (pivot_11 * 2)) + 5) & 127;
    aux ^= pivot_11 & 15;
  }
  else
  {
    acc = ((acc - pivot_11) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000405_513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_65_1)
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

  switch (vector_65_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_55_1 = local_arr_1[aux_1 % 3];
  int offset_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_55_2 * 2)) & 127;
  int scale_23_1 = 0;
  int scale_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_23_1 = ((scale_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_23_2 = ((scale_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_23_1) & 127;
    acc_2 = (acc_2 + scale_23_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_65_1 == vector_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_55_1 == offset_55_2);
  assert(scale_23_1 == scale_23_2);
}

int fn_R000405_513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_65 = (aux + st.buffer[1]) & 3;
  switch (vector_65)
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
  int local_arr[3] = {4, 9, 15};
  int offset_55 = local_arr[aux % 3];
  acc = (acc + (offset_55 * 2)) & 127;
  int scale_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_23 = ((scale_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_23) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000405_513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st_1 = {0};
  struct AudioFrame_R000405_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int tally_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_43_1 > 50)
  {
    acc_1 = ((acc_1 + (tally_43_1 * 2)) + 5) & 127;
    aux_1 ^= tally_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_43_2 > 50)
  {
    acc_2 = ((acc_2 + (tally_43_2 * 2)) + 5) & 127;
    aux_2 ^= tally_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_19_1)
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

  switch (segment_19_2)
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

  int cursor_89_1 = 0;
  int cursor_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_89_1 = ((cursor_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_89_2 = ((cursor_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_89_1) & 127;
    acc_2 = (acc_2 + cursor_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_43_1 == tally_43_2);
  assert(segment_19_1 == segment_19_2);
  assert(cursor_89_1 == cursor_89_2);
}

int fn_R000405_513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int tally_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_43 > 50)
  {
    acc = ((acc + (tally_43 * 2)) + 5) & 127;
    aux ^= tally_43 & 15;
  }
  else
  {
    acc = ((acc - tally_43) + 11) & 127;
    aux += 3;
  }
  int segment_19 = (aux + st.buffer[1]) & 3;
  switch (segment_19)
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

  int cursor_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_89 = ((cursor_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000405_513_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_20_1)
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

  switch (sample_20_2)
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
  int factor_62_1 = local_arr_1[aux_1 % 3];
  int factor_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_62_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_20_1 == sample_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_62_1 == factor_62_2);
}

int fn_R000405_513_6(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_20 = (aux + st.buffer[1]) & 3;
  switch (sample_20)
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
  int factor_62 = local_arr[aux % 3];
  acc = (acc + (factor_62 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000405_513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st_1 = {0};
  struct EventLog_R000405_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_44_1 = 0;
  int stride_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_44_1 = ((stride_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_44_2 = ((stride_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_44_1) & 127;
    acc_2 = (acc_2 + stride_44_2) & 127;
  }

  int checksum_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_41_1 > 11)
  {
    acc_1 = ((acc_1 + (checksum_41_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_41_2 > 11)
  {
    acc_2 = ((acc_2 + (checksum_41_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_44_1 == stride_44_2);
  assert(checksum_41_1 == checksum_41_2);
}

int fn_R000405_513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_44 = ((stride_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_44) & 127;
  }

  int checksum_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_41 > 11)
  {
    acc = ((acc + (checksum_41 * 2)) + 5) & 127;
    aux ^= checksum_41 & 15;
  }
  else
  {
    acc = ((acc - checksum_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000405_513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st_1 = {0};
  struct AudioFrame_R000405_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_79_1 > 14)
  {
    acc_1 = ((acc_1 + (stride_79_1 * 2)) + 5) & 127;
    aux_1 ^= stride_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_79_2 > 14)
  {
    acc_2 = ((acc_2 + (stride_79_2 * 2)) + 5) & 127;
    aux_2 ^= stride_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_79_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_79_1 == stride_79_2);
}

int fn_R000405_513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_79 > 14)
  {
    acc = ((acc + (stride_79 * 2)) + 5) & 127;
    aux ^= stride_79 & 15;
  }
  else
  {
    acc = ((acc - stride_79) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000405_513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st_1 = {0};
  struct AudioFrame_R000405_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_44_1)
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

  switch (coefficient_44_2)
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

  int scale_64_1 = 0;
  int scale_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_64_1 = ((scale_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_64_2 = ((scale_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_64_1) & 127;
    acc_2 = (acc_2 + scale_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_44_1 == coefficient_44_2);
  assert(scale_64_1 == scale_64_2);
}

int fn_R000405_513_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_44 = (aux + st.buffer[1]) & 3;
  switch (coefficient_44)
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

  int scale_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_64 = ((scale_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000405_513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_83_1) & 63;
  aux_2 = (aux_2 + anchor_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_97_1 = 0;
  int anchor_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_97_1 = ((anchor_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_97_2 = ((anchor_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_97_1) & 127;
    acc_2 = (acc_2 + anchor_97_2) & 127;
  }

  int anchor_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_64_1)
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

  switch (anchor_64_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_83_1 == anchor_83_2);
  assert(anchor_97_1 == anchor_97_2);
  assert(anchor_64_1 == anchor_64_2);
}

int fn_R000405_513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_83) & 63;
  acc ^= aux;
  int anchor_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_97 = ((anchor_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_97) & 127;
  }

  int anchor_64 = (aux + st.buffer[1]) & 3;
  switch (anchor_64)
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

void fn_R000405_513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int accumulator_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_86_1 > 23)
  {
    acc_1 = ((acc_1 + (accumulator_86_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_86_2 > 23)
  {
    acc_2 = ((acc_2 + (accumulator_86_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_19_1 = 0;
  int tally_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_19_1 = ((tally_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_19_2 = ((tally_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_19_1) & 127;
    acc_2 = (acc_2 + tally_19_2) & 127;
  }

  int metric_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_73_1)
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

  switch (metric_73_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_86_1 == accumulator_86_2);
  assert(tally_19_1 == tally_19_2);
  assert(metric_73_1 == metric_73_2);
}

int fn_R000405_513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int accumulator_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_86 > 23)
  {
    acc = ((acc + (accumulator_86 * 2)) + 5) & 127;
    aux ^= accumulator_86 & 15;
  }
  else
  {
    acc = ((acc - accumulator_86) + 11) & 127;
    aux += 3;
  }
  int tally_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_19 = ((tally_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_19) & 127;
  }

  int metric_73 = (aux + st.buffer[1]) & 3;
  switch (metric_73)
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

void fn_R000405_513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st_1 = {0};
  struct EventLog_R000405_513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_91_1 = local_arr_1[aux_1 % 3];
  int tally_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_91_2 * 2)) & 127;
  int phase_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_71_1)
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

  switch (phase_71_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_91_1 == tally_91_2);
  assert(phase_71_1 == phase_71_2);
}

int fn_R000405_513_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000405_513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int tally_91 = local_arr[aux % 3];
  acc = (acc + (tally_91 * 2)) & 127;
  int phase_71 = (aux + st.buffer[1]) & 3;
  switch (phase_71)
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

void fn_R000405_513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st_1 = {0};
  struct AudioFrame_R000405_513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_13_1)
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

  switch (threshold_13_2)
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

  int delta_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_35_1) & 63;
  aux_2 = (aux_2 + delta_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_13_1 == threshold_13_2);
  assert(delta_35_1 == delta_35_2);
}

int fn_R000405_513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000405_513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_13 = (aux + st.buffer[1]) & 3;
  switch (threshold_13)
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

  int delta_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_35) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000405_513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_74_1) & 63;
  aux_2 = (aux_2 + residue_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_22_1 = local_arr_1[aux_1 % 3];
  int factor_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_22_2 * 2)) & 127;
  int vector_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_10_1)
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

  switch (vector_10_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_74_1 == residue_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_22_1 == factor_22_2);
  assert(vector_10_1 == vector_10_2);
}

int fn_R000405_513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_22 = local_arr[aux % 3];
  acc = (acc + (factor_22 * 2)) & 127;
  int vector_10 = (aux + st.buffer[1]) & 3;
  switch (vector_10)
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

void fn_R000405_513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st_1 = {0};
  struct SensorNode_R000405_513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_26_1 = local_arr_1[aux_1 % 3];
  int vector_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_26_1 == vector_26_2);
}

int fn_R000405_513_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000405_513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_26 = local_arr[aux % 3];
  acc = (acc + (vector_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000405_0_1;
  int sec_r000405_0_2;
  int sec_r000405_1_1;
  int sec_r000405_1_2;
  int sec_r000405_2_1;
  int sec_r000405_2_2;
  int sec_r000405_3_1;
  int sec_r000405_3_2;
  int sec_r000405_4_1;
  int sec_r000405_4_2;
  int sec_r000405_5_1;
  int sec_r000405_5_2;
  int sec_r000405_6_1;
  int sec_r000405_6_2;
  int sec_r000405_7_1;
  int sec_r000405_7_2;
  int sec_r000405_8_1;
  int sec_r000405_8_2;
  int sec_r000405_9_1;
  int sec_r000405_9_2;
  int sec_r000405_10_1;
  int sec_r000405_10_2;
  int sec_r000405_11_1;
  int sec_r000405_11_2;
  int sec_r000405_12_1;
  int sec_r000405_12_2;
  int sec_r000405_13_1;
  int sec_r000405_13_2;
  int sec_r000405_14_1;
  int sec_r000405_14_2;
  int sec_r000405_15_1;
  int sec_r000405_15_2;
  int sec_r000405_16_1;
  int sec_r000405_16_2;
  int sec_r000405_17_1;
  int sec_r000405_17_2;
  int sec_r000405_18_1;
  int sec_r000405_18_2;
  int sec_r000405_19_1;
  int sec_r000405_19_2;
  int pub_r000405_0_1;
  int pub_r000405_0_2;
  int pub_r000405_1_1;
  int pub_r000405_1_2;
  int pub_r000405_2_1;
  int pub_r000405_2_2;
  int pub_r000405_3_1;
  int pub_r000405_3_2;
  int pub_r000405_4_1;
  int pub_r000405_4_2;
  int pub_r000405_5_1;
  int pub_r000405_5_2;
  int pub_r000405_6_1;
  int pub_r000405_6_2;
  int pub_r000405_7_1;
  int pub_r000405_7_2;
  int pub_r000405_8_1;
  int pub_r000405_8_2;
  int pub_r000405_9_1;
  int pub_r000405_9_2;
  int pub_r000405_10_1;
  int pub_r000405_10_2;
  int pub_r000405_11_1;
  int pub_r000405_11_2;
  int pub_r000405_12_1;
  int pub_r000405_12_2;
  int pub_r000405_13_1;
  int pub_r000405_13_2;
  int pub_r000405_14_1;
  int pub_r000405_14_2;
  int pub_r000405_15_1;
  int pub_r000405_15_2;
  int pub_r000405_16_1;
  int pub_r000405_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000405_0_1 >= (-100)) && (pub_r000405_0_1 <= 100));
  __CPROVER_assume((pub_r000405_0_2 >= (-100)) && (pub_r000405_0_2 <= 100));
  __CPROVER_assume((pub_r000405_1_1 >= (-100)) && (pub_r000405_1_1 <= 100));
  __CPROVER_assume((pub_r000405_1_2 >= (-100)) && (pub_r000405_1_2 <= 100));
  __CPROVER_assume((pub_r000405_2_1 >= (-100)) && (pub_r000405_2_1 <= 100));
  __CPROVER_assume((pub_r000405_2_2 >= (-100)) && (pub_r000405_2_2 <= 100));
  __CPROVER_assume((pub_r000405_3_1 >= (-100)) && (pub_r000405_3_1 <= 100));
  __CPROVER_assume((pub_r000405_3_2 >= (-100)) && (pub_r000405_3_2 <= 100));
  __CPROVER_assume((pub_r000405_4_1 >= (-100)) && (pub_r000405_4_1 <= 100));
  __CPROVER_assume((pub_r000405_4_2 >= (-100)) && (pub_r000405_4_2 <= 100));
  __CPROVER_assume((pub_r000405_5_1 >= (-100)) && (pub_r000405_5_1 <= 100));
  __CPROVER_assume((pub_r000405_5_2 >= (-100)) && (pub_r000405_5_2 <= 100));
  __CPROVER_assume((pub_r000405_6_1 >= (-100)) && (pub_r000405_6_1 <= 100));
  __CPROVER_assume((pub_r000405_6_2 >= (-100)) && (pub_r000405_6_2 <= 100));
  __CPROVER_assume((pub_r000405_7_1 >= (-100)) && (pub_r000405_7_1 <= 100));
  __CPROVER_assume((pub_r000405_7_2 >= (-100)) && (pub_r000405_7_2 <= 100));
  __CPROVER_assume((pub_r000405_8_1 >= (-100)) && (pub_r000405_8_1 <= 100));
  __CPROVER_assume((pub_r000405_8_2 >= (-100)) && (pub_r000405_8_2 <= 100));
  __CPROVER_assume((pub_r000405_9_1 >= (-100)) && (pub_r000405_9_1 <= 100));
  __CPROVER_assume((pub_r000405_9_2 >= (-100)) && (pub_r000405_9_2 <= 100));
  __CPROVER_assume((pub_r000405_10_1 >= (-100)) && (pub_r000405_10_1 <= 100));
  __CPROVER_assume((pub_r000405_10_2 >= (-100)) && (pub_r000405_10_2 <= 100));
  __CPROVER_assume((pub_r000405_11_1 >= (-100)) && (pub_r000405_11_1 <= 100));
  __CPROVER_assume((pub_r000405_11_2 >= (-100)) && (pub_r000405_11_2 <= 100));
  __CPROVER_assume((pub_r000405_12_1 >= (-100)) && (pub_r000405_12_1 <= 100));
  __CPROVER_assume((pub_r000405_12_2 >= (-100)) && (pub_r000405_12_2 <= 100));
  __CPROVER_assume((pub_r000405_13_1 >= (-100)) && (pub_r000405_13_1 <= 100));
  __CPROVER_assume((pub_r000405_13_2 >= (-100)) && (pub_r000405_13_2 <= 100));
  __CPROVER_assume((pub_r000405_14_1 >= (-100)) && (pub_r000405_14_1 <= 100));
  __CPROVER_assume((pub_r000405_14_2 >= (-100)) && (pub_r000405_14_2 <= 100));
  __CPROVER_assume((pub_r000405_15_1 >= (-100)) && (pub_r000405_15_1 <= 100));
  __CPROVER_assume((pub_r000405_15_2 >= (-100)) && (pub_r000405_15_2 <= 100));
  __CPROVER_assume((pub_r000405_16_1 >= (-100)) && (pub_r000405_16_1 <= 100));
  __CPROVER_assume((pub_r000405_16_2 >= (-100)) && (pub_r000405_16_2 <= 100));
  __CPROVER_assume((sec_r000405_0_1 >= 0) && (sec_r000405_0_1 <= 255));
  __CPROVER_assume((sec_r000405_0_2 >= 0) && (sec_r000405_0_2 <= 255));
  __CPROVER_assume((sec_r000405_1_1 >= 0) && (sec_r000405_1_1 <= 255));
  __CPROVER_assume((sec_r000405_1_2 >= 0) && (sec_r000405_1_2 <= 255));
  __CPROVER_assume((sec_r000405_2_1 >= 0) && (sec_r000405_2_1 <= 255));
  __CPROVER_assume((sec_r000405_2_2 >= 0) && (sec_r000405_2_2 <= 255));
  __CPROVER_assume((sec_r000405_3_1 >= 0) && (sec_r000405_3_1 <= 255));
  __CPROVER_assume((sec_r000405_3_2 >= 0) && (sec_r000405_3_2 <= 255));
  __CPROVER_assume((sec_r000405_4_1 >= 0) && (sec_r000405_4_1 <= 255));
  __CPROVER_assume((sec_r000405_4_2 >= 0) && (sec_r000405_4_2 <= 255));
  __CPROVER_assume((sec_r000405_5_1 >= 0) && (sec_r000405_5_1 <= 255));
  __CPROVER_assume((sec_r000405_5_2 >= 0) && (sec_r000405_5_2 <= 255));
  __CPROVER_assume((sec_r000405_6_1 >= 0) && (sec_r000405_6_1 <= 255));
  __CPROVER_assume((sec_r000405_6_2 >= 0) && (sec_r000405_6_2 <= 255));
  __CPROVER_assume((sec_r000405_7_1 >= 0) && (sec_r000405_7_1 <= 255));
  __CPROVER_assume((sec_r000405_7_2 >= 0) && (sec_r000405_7_2 <= 255));
  __CPROVER_assume((sec_r000405_8_1 >= 0) && (sec_r000405_8_1 <= 255));
  __CPROVER_assume((sec_r000405_8_2 >= 0) && (sec_r000405_8_2 <= 255));
  __CPROVER_assume((sec_r000405_9_1 >= 0) && (sec_r000405_9_1 <= 255));
  __CPROVER_assume((sec_r000405_9_2 >= 0) && (sec_r000405_9_2 <= 255));
  __CPROVER_assume((sec_r000405_10_1 >= 0) && (sec_r000405_10_1 <= 255));
  __CPROVER_assume((sec_r000405_10_2 >= 0) && (sec_r000405_10_2 <= 255));
  __CPROVER_assume((sec_r000405_11_1 >= 0) && (sec_r000405_11_1 <= 255));
  __CPROVER_assume((sec_r000405_11_2 >= 0) && (sec_r000405_11_2 <= 255));
  __CPROVER_assume((sec_r000405_12_1 >= 0) && (sec_r000405_12_1 <= 255));
  __CPROVER_assume((sec_r000405_12_2 >= 0) && (sec_r000405_12_2 <= 255));
  __CPROVER_assume((sec_r000405_13_1 >= 0) && (sec_r000405_13_1 <= 255));
  __CPROVER_assume((sec_r000405_13_2 >= 0) && (sec_r000405_13_2 <= 255));
  __CPROVER_assume((sec_r000405_14_1 >= 0) && (sec_r000405_14_1 <= 255));
  __CPROVER_assume((sec_r000405_14_2 >= 0) && (sec_r000405_14_2 <= 255));
  __CPROVER_assume((sec_r000405_15_1 >= 0) && (sec_r000405_15_1 <= 255));
  __CPROVER_assume((sec_r000405_15_2 >= 0) && (sec_r000405_15_2 <= 255));
  __CPROVER_assume((sec_r000405_16_1 >= 0) && (sec_r000405_16_1 <= 255));
  __CPROVER_assume((sec_r000405_16_2 >= 0) && (sec_r000405_16_2 <= 255));
  __CPROVER_assume((sec_r000405_17_1 >= 0) && (sec_r000405_17_1 <= 255));
  __CPROVER_assume((sec_r000405_17_2 >= 0) && (sec_r000405_17_2 <= 255));
  __CPROVER_assume((sec_r000405_18_1 >= 0) && (sec_r000405_18_1 <= 255));
  __CPROVER_assume((sec_r000405_18_2 >= 0) && (sec_r000405_18_2 <= 255));
  __CPROVER_assume((sec_r000405_19_1 >= 0) && (sec_r000405_19_1 <= 255));
  __CPROVER_assume((sec_r000405_19_2 >= 0) && (sec_r000405_19_2 <= 255));
  struct SensorNode_R000405_513_0 st_var_0_1 = {0};
  struct SensorNode_R000405_513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000405_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000405_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000405_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000405_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000405_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000405_0_2 + 7) & 15;
  struct AudioFrame_R000405_513_1 st_var_1_1 = {0};
  struct AudioFrame_R000405_513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000405_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000405_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000405_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000405_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000405_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000405_0_2 + 9) & 15;
  struct EventLog_R000405_513_2 st_var_2_1 = {0};
  struct EventLog_R000405_513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000405_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000405_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000405_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000405_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000405_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000405_0_2 + 11) & 15;
  union RegisterBank_R000405_513_0 u_var_1;
  union RegisterBank_R000405_513_0 u_var_2;
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 28)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 28)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
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
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_4_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_4_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_4_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 7) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = ((st_var_2_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_2_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 39)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 39)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = ((st_var_0_1.buffer[0] * 2) + 34) & 63;
  int stage_v_9_2 = ((st_var_0_2.buffer[0] * 2) + 34) & 63;
  if (stage_v_9_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_9_1) - 5) & 255;
    if (stage_v_9_1 > 55)
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
  if (stage_v_9_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_9_2) - 5) & 255;
    if (stage_v_9_2 > 55)
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
  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 13) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 13) & 15;
  int stage_v_12_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_12_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= stage_v_12_1;
  chk_sum_2 ^= stage_v_12_2;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = (st_var_2_1.buffer[0] ^ 17) & 3;
  int stage_v_14_2 = (st_var_2_2.buffer[0] ^ 17) & 3;
  switch (stage_v_14_1)
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

  switch (stage_v_14_2)
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

  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (22 & 31);
  int stage_v_17_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (22 & 31);
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  chk_sum_1 ^= (stage_v_17_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_17_2 << 1) & 127;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
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

  switch (stage_v_21_2)
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

  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 24) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (33 & 31);
  int stage_v_28_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (33 & 31);
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= (stage_v_28_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_28_2 << 1) & 127;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = table_1[3];
  int stage_v_31_2 = table_2[3];
  table_1[3] = (table_1[0] + 63) & 63;
  table_2[3] = (table_2[0] + 63) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_33_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_34_1 = table_1[2];
  int stage_v_34_2 = table_2[2];
  table_1[2] = (table_1[3] + 69) & 63;
  table_2[2] = (table_2[3] + 69) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 41) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (st_var_2_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_2_2.buffer[0] ^ 44) & 3;
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

  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 49) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 49) & 15;
  int stage_v_48_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_48_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= stage_v_48_1;
  chk_sum_2 ^= stage_v_48_2;
  int stage_v_49_1 = table_1[1];
  int stage_v_49_2 = table_2[1];
  table_1[1] = (table_1[2] + 99) & 63;
  table_2[1] = (table_2[2] + 99) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 38)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 38)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 56) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 56) & 15;
  int stage_v_55_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_55_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  chk_sum_1 ^= stage_v_55_1;
  chk_sum_2 ^= stage_v_55_2;
  int stage_v_56_1 = ((st_var_2_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_2_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 25)
    {
      chk_sum_1 ^= stage_v_56_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_56_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 25)
    {
      chk_sum_2 ^= stage_v_56_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 58) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((st_var_2_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_2_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 34)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 34)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_60_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (st_var_0_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_0_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 65) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 65) & 15;
  int stage_v_64_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_64_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= stage_v_64_1;
  chk_sum_2 ^= stage_v_64_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 66) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 66) & 15;
  int stage_v_65_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_65_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= stage_v_65_1;
  chk_sum_2 ^= stage_v_65_2;
  int stage_v_66_1 = ((st_var_0_1.buffer[0] * 2) + 205) & 63;
  int stage_v_66_2 = ((st_var_0_2.buffer[0] * 2) + 205) & 63;
  if (stage_v_66_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_66_1) - 5) & 255;
    if (stage_v_66_1 > 25)
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
  if (stage_v_66_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_66_2) - 5) & 255;
    if (stage_v_66_2 > 25)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 68) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 69) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 73) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 73) & 15;
  int stage_v_72_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_72_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  chk_sum_1 ^= stage_v_72_1;
  chk_sum_2 ^= stage_v_72_2;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 75) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 75) & 15;
  int stage_v_74_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_74_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= stage_v_74_1;
  chk_sum_2 ^= stage_v_74_2;
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 78) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 78) & 15;
  int stage_v_77_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_77_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  chk_sum_1 ^= stage_v_77_1;
  chk_sum_2 ^= stage_v_77_2;
  int stage_v_78_1 = ((st_var_0_1.buffer[0] * 2) + 241) & 63;
  int stage_v_78_2 = ((st_var_0_2.buffer[0] * 2) + 241) & 63;
  if (stage_v_78_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_78_1) - 5) & 255;
    if (stage_v_78_1 > 38)
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
  if (stage_v_78_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_78_2) - 5) & 255;
    if (stage_v_78_2 > 38)
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
  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 81) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 81) & 15;
  int stage_v_80_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_80_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= stage_v_80_1;
  chk_sum_2 ^= stage_v_80_2;
  int stage_v_81_1 = ((st_var_0_1.buffer[0] * 2) + 250) & 63;
  int stage_v_81_2 = ((st_var_0_2.buffer[0] * 2) + 250) & 63;
  if (stage_v_81_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_81_1) - 5) & 255;
    if (stage_v_81_1 > 26)
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
  if (stage_v_81_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_81_2) - 5) & 255;
    if (stage_v_81_2 > 26)
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
  int stage_v_82_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_82_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (91 & 31);
  int stage_v_86_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (91 & 31);
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= (stage_v_86_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_86_2 << 1) & 127;
  int stage_v_87_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (92 & 31);
  int stage_v_87_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (92 & 31);
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= (stage_v_87_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_87_2 << 1) & 127;
  int stage_v_88_1 = table_1[0];
  int stage_v_88_2 = table_2[0];
  table_1[0] = (table_1[1] + 177) & 63;
  table_2[0] = (table_2[1] + 177) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (st_var_2_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_2_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 91) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 91) & 15;
  int stage_v_90_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_90_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= stage_v_90_1;
  chk_sum_2 ^= stage_v_90_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 92) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 92) & 15;
  int stage_v_91_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_91_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  chk_sum_1 ^= stage_v_91_1;
  chk_sum_2 ^= stage_v_91_2;
  int stage_v_92_1 = (st_var_2_1.buffer[0] ^ 95) & 3;
  int stage_v_92_2 = (st_var_2_2.buffer[0] ^ 95) & 3;
  switch (stage_v_92_1)
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

  switch (stage_v_92_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 94) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 94) & 15;
  int stage_v_93_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_93_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  chk_sum_1 ^= stage_v_93_1;
  chk_sum_2 ^= stage_v_93_2;
  int stage_v_94_1 = table_1[2];
  int stage_v_94_2 = table_2[2];
  table_1[2] = (table_1[3] + 189) & 63;
  table_2[2] = (table_2[3] + 189) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((st_var_2_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_2_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 28)
    {
      chk_sum_1 ^= stage_v_95_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_95_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 28)
    {
      chk_sum_2 ^= stage_v_95_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 98) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 98) & 15;
  int stage_v_97_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_97_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= stage_v_97_1;
  chk_sum_2 ^= stage_v_97_2;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (104 & 31);
  int stage_v_99_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (104 & 31);
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  chk_sum_1 ^= (stage_v_99_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_99_2 << 1) & 127;
  int stage_v_100_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (105 & 31);
  int stage_v_100_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (105 & 31);
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  chk_sum_1 ^= (stage_v_100_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_100_2 << 1) & 127;
  int stage_v_101_1 = table_1[1];
  int stage_v_101_2 = table_2[1];
  table_1[1] = (table_1[2] + 203) & 63;
  table_2[1] = (table_2[2] + 203) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 104) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 104) & 15;
  int stage_v_103_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_103_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  chk_sum_1 ^= stage_v_103_1;
  chk_sum_2 ^= stage_v_103_2;
  int stage_v_104_1 = ((st_var_2_1.buffer[2] * 2) + 319) & 63;
  int stage_v_104_2 = ((st_var_2_2.buffer[2] * 2) + 319) & 63;
  if (stage_v_104_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_104_1) - 5) & 255;
    if (stage_v_104_1 > 49)
    {
      chk_sum_1 ^= stage_v_104_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_104_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_104_2) - 5) & 255;
    if (stage_v_104_2 > 49)
    {
      chk_sum_2 ^= stage_v_104_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_105_1 = ((st_var_0_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_0_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 33)
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
  if (stage_v_105_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 33)
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
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((st_var_2_1.buffer[2] * 2) + 328) & 63;
  int stage_v_107_2 = ((st_var_2_2.buffer[2] * 2) + 328) & 63;
  if (stage_v_107_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_107_1) - 5) & 255;
    if (stage_v_107_1 > 28)
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
  if (stage_v_107_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_107_2) - 5) & 255;
    if (stage_v_107_2 > 28)
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
  int stage_v_108_1 = ((st_var_0_1.buffer[0] * 2) + 331) & 63;
  int stage_v_108_2 = ((st_var_0_2.buffer[0] * 2) + 331) & 63;
  if (stage_v_108_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_108_1) - 5) & 255;
    if (stage_v_108_1 > 54)
    {
      chk_sum_1 ^= stage_v_108_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_108_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_108_2) - 5) & 255;
    if (stage_v_108_2 > 54)
    {
      chk_sum_2 ^= stage_v_108_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
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

  switch (stage_v_109_2)
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

  int stage_v_110_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (115 & 31);
  int stage_v_110_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (115 & 31);
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  chk_sum_1 ^= (stage_v_110_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_110_2 << 1) & 127;
  int stage_v_111_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_111_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = table_1[1];
  int stage_v_113_2 = table_2[1];
  table_1[1] = (table_1[2] + 227) & 63;
  table_2[1] = (table_2[2] + 227) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_114_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_115_1 = (st_var_1_1.buffer[0] ^ 118) & 3;
  int stage_v_115_2 = (st_var_1_2.buffer[0] ^ 118) & 3;
  switch (stage_v_115_1)
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

  switch (stage_v_115_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 117) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 117) & 15;
  int stage_v_116_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_116_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  chk_sum_1 ^= stage_v_116_1;
  chk_sum_2 ^= stage_v_116_2;
  int stage_v_117_1 = table_1[1];
  int stage_v_117_2 = table_2[1];
  table_1[1] = (table_1[2] + 235) & 63;
  table_2[1] = (table_2[2] + 235) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 121) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 121) & 15;
  int stage_v_120_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_120_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= stage_v_120_1;
  chk_sum_2 ^= stage_v_120_2;
  int stage_v_121_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_121_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 124) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 124) & 15;
  int stage_v_123_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_123_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= stage_v_123_1;
  chk_sum_2 ^= stage_v_123_2;
  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 127) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 127) & 15;
  int stage_v_126_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_126_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  chk_sum_1 ^= stage_v_126_1;
  chk_sum_2 ^= stage_v_126_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 128) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 128) & 15;
  int stage_v_127_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_127_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= stage_v_127_1;
  chk_sum_2 ^= stage_v_127_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 129) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 129) & 15;
  int stage_v_128_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_128_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= stage_v_128_1;
  chk_sum_2 ^= stage_v_128_2;
  int stage_v_129_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_129_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_130_1 = ((stage_v_130_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_130_2 = ((stage_v_130_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = table_1[3];
  int stage_v_131_2 = table_2[3];
  table_1[3] = (table_1[0] + 263) & 63;
  table_2[3] = (table_2[0] + 263) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_134_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_134_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((st_var_1_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_1_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 31)
    {
      chk_sum_1 ^= stage_v_136_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_136_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 31)
    {
      chk_sum_2 ^= stage_v_136_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_137_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (142 & 31);
  int stage_v_137_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (142 & 31);
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= (stage_v_137_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_137_2 << 1) & 127;
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
  int stage_v_139_1 = ((st_var_1_1.buffer[1] * 2) + 424) & 63;
  int stage_v_139_2 = ((st_var_1_2.buffer[1] * 2) + 424) & 63;
  if (stage_v_139_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_139_1) - 5) & 255;
    if (stage_v_139_1 > 26)
    {
      chk_sum_1 ^= stage_v_139_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_139_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_139_2) - 5) & 255;
    if (stage_v_139_2 > 26)
    {
      chk_sum_2 ^= stage_v_139_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_140_1 = (st_var_2_1.buffer[0] ^ 143) & 3;
  int stage_v_140_2 = (st_var_2_2.buffer[0] ^ 143) & 3;
  switch (stage_v_140_1)
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

  switch (stage_v_140_2)
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

  int stage_v_141_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_141_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_142_1 = table_1[2];
  int stage_v_142_2 = table_2[2];
  table_1[2] = (table_1[3] + 285) & 63;
  table_2[2] = (table_2[3] + 285) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_143_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_144_1 = (st_var_0_1.buffer[0] ^ 147) & 3;
  int stage_v_144_2 = (st_var_0_2.buffer[0] ^ 147) & 3;
  switch (stage_v_144_1)
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

  switch (stage_v_144_2)
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

  int stage_v_145_1 = (st_var_1_1.buffer[0] ^ 148) & 3;
  int stage_v_145_2 = (st_var_1_2.buffer[0] ^ 148) & 3;
  switch (stage_v_145_1)
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

  switch (stage_v_145_2)
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

  int stage_v_146_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (151 & 31);
  int stage_v_146_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (151 & 31);
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  chk_sum_1 ^= (stage_v_146_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_146_2 << 1) & 127;
  int stage_v_147_1 = ((st_var_0_1.buffer[0] * 2) + 448) & 63;
  int stage_v_147_2 = ((st_var_0_2.buffer[0] * 2) + 448) & 63;
  if (stage_v_147_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_147_1) - 5) & 255;
    if (stage_v_147_1 > 38)
    {
      chk_sum_1 ^= stage_v_147_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_147_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_147_2) - 5) & 255;
    if (stage_v_147_2 > 38)
    {
      chk_sum_2 ^= stage_v_147_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_148_1 = (st_var_1_1.buffer[0] ^ 151) & 3;
  int stage_v_148_2 = (st_var_1_2.buffer[0] ^ 151) & 3;
  switch (stage_v_148_1)
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

  switch (stage_v_148_2)
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

  int stage_v_149_1 = table_1[1];
  int stage_v_149_2 = table_2[1];
  table_1[1] = (table_1[2] + 299) & 63;
  table_2[1] = (table_2[2] + 299) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = table_1[2];
  int stage_v_150_2 = table_2[2];
  table_1[2] = (table_1[3] + 301) & 63;
  table_2[2] = (table_2[3] + 301) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 152) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 152) & 15;
  int stage_v_151_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_151_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  chk_sum_1 ^= stage_v_151_1;
  chk_sum_2 ^= stage_v_151_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 153) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 153) & 15;
  int stage_v_152_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_152_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  chk_sum_1 ^= stage_v_152_1;
  chk_sum_2 ^= stage_v_152_2;
  int stage_v_153_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_153_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_155_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_155_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_156_1 = ((st_var_0_1.buffer[0] * 2) + 475) & 63;
  int stage_v_156_2 = ((st_var_0_2.buffer[0] * 2) + 475) & 63;
  if (stage_v_156_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_156_1) - 5) & 255;
    if (stage_v_156_1 > 25)
    {
      chk_sum_1 ^= stage_v_156_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_156_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_156_2) - 5) & 255;
    if (stage_v_156_2 > 25)
    {
      chk_sum_2 ^= stage_v_156_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_157_1 = table_1[1];
  int stage_v_157_2 = table_2[1];
  table_1[1] = (table_1[2] + 315) & 63;
  table_2[1] = (table_2[2] + 315) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (163 & 31);
  int stage_v_158_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (163 & 31);
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= (stage_v_158_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_158_2 << 1) & 127;
  int stage_v_159_1 = (st_var_0_1.buffer[0] ^ 162) & 3;
  int stage_v_159_2 = (st_var_0_2.buffer[0] ^ 162) & 3;
  switch (stage_v_159_1)
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

  switch (stage_v_159_2)
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

  int stage_v_160_1 = table_1[0];
  int stage_v_160_2 = table_2[0];
  table_1[0] = (table_1[1] + 321) & 63;
  table_2[0] = (table_2[1] + 321) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((st_var_2_1.buffer[2] * 2) + 490) & 63;
  int stage_v_161_2 = ((st_var_2_2.buffer[2] * 2) + 490) & 63;
  if (stage_v_161_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_161_1) - 5) & 255;
    if (stage_v_161_1 > 27)
    {
      chk_sum_1 ^= stage_v_161_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_161_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_161_2) - 5) & 255;
    if (stage_v_161_2 > 27)
    {
      chk_sum_2 ^= stage_v_161_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 163) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 163) & 15;
  int stage_v_162_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_162_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  chk_sum_1 ^= stage_v_162_1;
  chk_sum_2 ^= stage_v_162_2;
  int stage_v_163_1 = table_1[3];
  int stage_v_163_2 = table_2[3];
  table_1[3] = (table_1[0] + 327) & 63;
  table_2[3] = (table_2[0] + 327) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 165) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 165) & 15;
  int stage_v_164_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_164_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= stage_v_164_1;
  chk_sum_2 ^= stage_v_164_2;
  int stage_v_165_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_165_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_166_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_166_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_167_1 = 0;
  int stage_v_167_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_167_1 = ((stage_v_167_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_167_2 = ((stage_v_167_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 169) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 169) & 15;
  int stage_v_168_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_168_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  chk_sum_1 ^= stage_v_168_1;
  chk_sum_2 ^= stage_v_168_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 170) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 170) & 15;
  int stage_v_169_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_169_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  chk_sum_1 ^= stage_v_169_1;
  chk_sum_2 ^= stage_v_169_2;
  int stage_v_170_1 = (st_var_2_1.buffer[0] ^ 173) & 3;
  int stage_v_170_2 = (st_var_2_2.buffer[0] ^ 173) & 3;
  switch (stage_v_170_1)
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

  switch (stage_v_170_2)
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

  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 173) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 173) & 15;
  int stage_v_172_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_172_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  chk_sum_1 ^= stage_v_172_1;
  chk_sum_2 ^= stage_v_172_2;
  int stage_v_173_1 = (st_var_2_1.buffer[0] ^ 176) & 3;
  int stage_v_173_2 = (st_var_2_2.buffer[0] ^ 176) & 3;
  switch (stage_v_173_1)
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

  switch (stage_v_173_2)
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

  int stage_v_174_1 = (st_var_0_1.buffer[0] ^ 177) & 3;
  int stage_v_174_2 = (st_var_0_2.buffer[0] ^ 177) & 3;
  switch (stage_v_174_1)
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

  switch (stage_v_174_2)
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

  int stage_v_175_1 = ((st_var_1_1.buffer[1] * 2) + 532) & 63;
  int stage_v_175_2 = ((st_var_1_2.buffer[1] * 2) + 532) & 63;
  if (stage_v_175_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_175_1) - 5) & 255;
    if (stage_v_175_1 > 40)
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
  if (stage_v_175_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_175_2) - 5) & 255;
    if (stage_v_175_2 > 40)
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
  int stage_v_176_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_176_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_177_1 = table_1[1];
  int stage_v_177_2 = table_2[1];
  table_1[1] = (table_1[2] + 355) & 63;
  table_2[1] = (table_2[2] + 355) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((st_var_1_1.buffer[1] * 2) + 541) & 63;
  int stage_v_178_2 = ((st_var_1_2.buffer[1] * 2) + 541) & 63;
  if (stage_v_178_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_178_1) - 5) & 255;
    if (stage_v_178_1 > 31)
    {
      chk_sum_1 ^= stage_v_178_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_178_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_178_2) - 5) & 255;
    if (stage_v_178_2 > 31)
    {
      chk_sum_2 ^= stage_v_178_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_179_1 = table_1[3];
  int stage_v_179_2 = table_2[3];
  table_1[3] = (table_1[0] + 359) & 63;
  table_2[3] = (table_2[0] + 359) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (st_var_0_1.buffer[0] ^ 183) & 3;
  int stage_v_180_2 = (st_var_0_2.buffer[0] ^ 183) & 3;
  switch (stage_v_180_1)
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

  switch (stage_v_180_2)
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

  int stage_v_181_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_181_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 183) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 183) & 15;
  int stage_v_182_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_182_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  chk_sum_1 ^= stage_v_182_1;
  chk_sum_2 ^= stage_v_182_2;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = table_1[0];
  int stage_v_184_2 = table_2[0];
  table_1[0] = (table_1[1] + 369) & 63;
  table_2[0] = (table_2[1] + 369) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (190 & 31);
  int stage_v_185_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (190 & 31);
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  chk_sum_1 ^= (stage_v_185_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_185_2 << 1) & 127;
  int stage_v_186_1 = ((st_var_0_1.buffer[0] * 2) + 565) & 63;
  int stage_v_186_2 = ((st_var_0_2.buffer[0] * 2) + 565) & 63;
  if (stage_v_186_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_186_1) - 5) & 255;
    if (stage_v_186_1 > 53)
    {
      chk_sum_1 ^= stage_v_186_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_186_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_186_2) - 5) & 255;
    if (stage_v_186_2 > 53)
    {
      chk_sum_2 ^= stage_v_186_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int b_w0_1 = (sec_r000405_9_1 ^ 0x5A) & 63;
  int b_w0_2 = (sec_r000405_9_2 ^ 0x5A) & 63;
  int b_w1_1 = ((b_w0_1 << 1) | (sec_r000405_8_1 >> 1)) & 63;
  int b_w1_2 = ((b_w0_2 << 1) | (sec_r000405_8_2 >> 1)) & 63;
  int b_w2_1 = ((b_w1_1 << 2) | (sec_r000405_3_1 >> 2)) & 63;
  int b_w2_2 = ((b_w1_2 << 2) | (sec_r000405_3_2 >> 2)) & 63;
  int b_w3_1 = ((b_w2_1 << 2) ^ (sec_r000405_11_1 >> 2)) & 63;
  int b_w3_2 = ((b_w2_2 << 2) ^ (sec_r000405_11_2 >> 2)) & 63;
  int b_w4_1 = ((b_w3_1 << 1) ^ (sec_r000405_9_1 >> 1)) & 63;
  int b_w4_2 = ((b_w3_2 << 1) ^ (sec_r000405_9_2 >> 1)) & 63;
  out_sink_1 += b_w4_1 & 63;
  out_sink_2 += b_w4_2 & 63;
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000405_16_1 != sec_r000405_16_2);
  __CPROVER_assume(sec_r000405_15_1 != sec_r000405_15_2);
  __CPROVER_assume(pub_r000405_10_1 == pub_r000405_10_2);
  __CPROVER_assume(sec_r000405_6_1 != sec_r000405_6_2);
  __CPROVER_assume(pub_r000405_6_1 == pub_r000405_6_2);
  __CPROVER_assume(sec_r000405_11_1 != sec_r000405_11_2);
  __CPROVER_assume(sec_r000405_8_1 != sec_r000405_8_2);
  __CPROVER_assume(sec_r000405_10_1 != sec_r000405_10_2);
  __CPROVER_assume(pub_r000405_13_1 == pub_r000405_13_2);
  __CPROVER_assume(sec_r000405_7_1 != sec_r000405_7_2);
  __CPROVER_assume(pub_r000405_14_1 == pub_r000405_14_2);
  __CPROVER_assume(sec_r000405_2_1 != sec_r000405_2_2);
  __CPROVER_assume(pub_r000405_5_1 == pub_r000405_5_2);
  __CPROVER_assume(sec_r000405_19_1 != sec_r000405_19_2);
  __CPROVER_assume(sec_r000405_0_1 != sec_r000405_0_2);
  __CPROVER_assume(sec_r000405_3_1 != sec_r000405_3_2);
  __CPROVER_assume(sec_r000405_17_1 != sec_r000405_17_2);
  __CPROVER_assume(pub_r000405_9_1 == pub_r000405_9_2);
  __CPROVER_assume(pub_r000405_0_1 == pub_r000405_0_2);
  __CPROVER_assume(pub_r000405_15_1 == pub_r000405_15_2);
  __CPROVER_assume(pub_r000405_4_1 == pub_r000405_4_2);
  __CPROVER_assume(sec_r000405_9_1 != sec_r000405_9_2);
  __CPROVER_assume(pub_r000405_3_1 == pub_r000405_3_2);
  __CPROVER_assume(sec_r000405_4_1 != sec_r000405_4_2);
  __CPROVER_assume(pub_r000405_2_1 == pub_r000405_2_2);
  __CPROVER_assume(sec_r000405_12_1 != sec_r000405_12_2);
  __CPROVER_assume(sec_r000405_18_1 != sec_r000405_18_2);
  __CPROVER_assume(sec_r000405_1_1 != sec_r000405_1_2);
  __CPROVER_assume(sec_r000405_5_1 != sec_r000405_5_2);
  __CPROVER_assume(pub_r000405_8_1 == pub_r000405_8_2);
  __CPROVER_assume(sec_r000405_13_1 != sec_r000405_13_2);
  __CPROVER_assume(pub_r000405_1_1 == pub_r000405_1_2);
  __CPROVER_assume(pub_r000405_12_1 == pub_r000405_12_2);
  __CPROVER_assume(sec_r000405_14_1 != sec_r000405_14_2);
  __CPROVER_assume(pub_r000405_16_1 == pub_r000405_16_2);
  __CPROVER_assume(pub_r000405_7_1 == pub_r000405_7_2);
  __CPROVER_assume(pub_r000405_11_1 == pub_r000405_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.code == st_var_2_2.code);
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
  assert(b_w0_1 == b_w0_2);
  assert(b_w1_1 == b_w1_2);
  assert(b_w2_1 == b_w2_2);
  assert(b_w3_1 == b_w3_2);
  assert(b_w4_1 == b_w4_2);
}


