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
struct CipherContext_R000467_6713_0
{
  unsigned char counter;
  int iv;
  int nonce;
  int round_key;
  int tag;
  int buffer[3];
};
struct SensorNode_R000467_6713_1
{
  unsigned char offset;
  int reading;
  short calib;
  short status;
  int gain;
  int buffer[3];
};
struct EventLog_R000467_6713_2
{
  int facility;
  int code;
  short timestamp;
  short seq;
  int signature;
  int buffer[3];
};
struct MatrixBlock_R000467_6713_3
{
  unsigned char trace;
  short scale;
  unsigned char dim;
  int density;
  int buffer[3];
};
union ColorPixel_R000467_6713_0
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
void fn_R000467_6713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_14_1) & 63;
  aux_2 = (aux_2 + weight_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_53_1 = local_arr_1[aux_1 % 3];
  int checksum_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_53_2 * 2)) & 127;
  int phase_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_52_1 > 13)
  {
    acc_1 = ((acc_1 + (phase_52_1 * 2)) + 5) & 127;
    aux_1 ^= phase_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_52_2 > 13)
  {
    acc_2 = ((acc_2 + (phase_52_2 * 2)) + 5) & 127;
    aux_2 ^= phase_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_14_1 == weight_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_53_1 == checksum_53_2);
  assert(phase_52_1 == phase_52_2);
}

int fn_R000467_6713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_14) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int checksum_53 = local_arr[aux % 3];
  acc = (acc + (checksum_53 * 2)) & 127;
  int phase_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_52 > 13)
  {
    acc = ((acc + (phase_52 * 2)) + 5) & 127;
    aux ^= phase_52 & 15;
  }
  else
  {
    acc = ((acc - phase_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000467_6713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st_1 = {0};
  struct EventLog_R000467_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_96_1 = local_arr_1[aux_1 % 3];
  int vector_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_96_2 * 2)) & 127;
  int threshold_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_66_1)
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

  switch (threshold_66_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_97_1) & 63;
  aux_2 = (aux_2 + margin_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_96_1 == vector_96_2);
  assert(threshold_66_1 == threshold_66_2);
  assert(margin_97_1 == margin_97_2);
}

int fn_R000467_6713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int vector_96 = local_arr[aux % 3];
  acc = (acc + (vector_96 * 2)) & 127;
  int threshold_66 = (aux + st.buffer[1]) & 3;
  switch (threshold_66)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000467_6713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int scale_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_64_1) & 63;
  aux_2 = (aux_2 + scale_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_64_1 == scale_64_2);
}

int fn_R000467_6713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int scale_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_64) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st_1 = {0};
  struct CipherContext_R000467_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tally_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_18_1)
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

  switch (tally_18_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_24_1 = local_arr_1[aux_1 % 3];
  int phase_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_24_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_18_1 == tally_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_24_1 == phase_24_2);
}

int fn_R000467_6713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tally_18 = (aux + st.buffer[1]) & 3;
  switch (tally_18)
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
  int local_arr[3] = {4, 9, 15};
  int phase_24 = local_arr[aux % 3];
  acc = (acc + (phase_24 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int pivot_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_30_1)
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

  switch (pivot_30_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_62_1 = local_arr_1[aux_1 % 3];
  int anchor_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_62_2 * 2)) & 127;
  int checksum_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_25_1) & 63;
  aux_2 = (aux_2 + checksum_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_30_1 == pivot_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_62_1 == anchor_62_2);
  assert(checksum_25_1 == checksum_25_2);
}

int fn_R000467_6713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int pivot_30 = (aux + st.buffer[1]) & 3;
  switch (pivot_30)
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

  int local_arr[3] = {4, 9, 15};
  int anchor_62 = local_arr[aux % 3];
  acc = (acc + (anchor_62 * 2)) & 127;
  int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_25) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000467_6713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st_1 = {0};
  struct CipherContext_R000467_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_96_1)
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

  switch (sample_96_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_72_1 = local_arr_1[aux_1 % 3];
  int threshold_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_72_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_96_1 == sample_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_72_1 == threshold_72_2);
}

int fn_R000467_6713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_96 = (aux + st.buffer[1]) & 3;
  switch (sample_96)
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

  int local_arr[3] = {4, 9, 15};
  int threshold_72 = local_arr[aux % 3];
  acc = (acc + (threshold_72 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_66_1 > 35)
  {
    acc_1 = ((acc_1 + (threshold_66_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_66_2 > 35)
  {
    acc_2 = ((acc_2 + (threshold_66_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_66_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_66_1) & 63;
  aux_2 = (aux_2 + parity_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_66_1 == threshold_66_2);
  assert(parity_66_1 == parity_66_2);
}

int fn_R000467_6713_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_66 > 35)
  {
    acc = ((acc + (threshold_66 * 2)) + 5) & 127;
    aux ^= threshold_66 & 15;
  }
  else
  {
    acc = ((acc - threshold_66) + 11) & 127;
    aux += 3;
  }
  int parity_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000467_6713_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_52_1) & 63;
  aux_2 = (aux_2 + vector_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_81_1)
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

  switch (pivot_81_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_52_1 == vector_52_2);
  assert(pivot_81_1 == pivot_81_2);
}

int fn_R000467_6713_7(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_52) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_81 = (aux + st.buffer[1]) & 3;
  switch (pivot_81)
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

void fn_R000467_6713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int parity_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_90_1 > 45)
  {
    acc_1 = ((acc_1 + (parity_90_1 * 2)) + 5) & 127;
    aux_1 ^= parity_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_90_2 > 45)
  {
    acc_2 = ((acc_2 + (parity_90_2 * 2)) + 5) & 127;
    aux_2 ^= parity_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_65_1 = local_arr_1[aux_1 % 3];
  int metric_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_65_2 * 2)) & 127;
  int anchor_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_62_1) & 63;
  aux_2 = (aux_2 + anchor_62_2) & 63;
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_90_1 == parity_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(anchor_62_1 == anchor_62_2);
}

int fn_R000467_6713_8(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int parity_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_90 > 45)
  {
    acc = ((acc + (parity_90 * 2)) + 5) & 127;
    aux ^= parity_90 & 15;
  }
  else
  {
    acc = ((acc - parity_90) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_65 = local_arr[aux % 3];
  acc = (acc + (metric_65 * 2)) & 127;
  int anchor_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_62) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int segment_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_88_1)
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

  switch (segment_88_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_13_1 = local_arr_1[aux_1 % 3];
  int pivot_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_13_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_88_1 == segment_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_13_1 == pivot_13_2);
}

int fn_R000467_6713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int segment_88 = (aux + st.buffer[1]) & 3;
  switch (segment_88)
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

  int local_arr[3] = {4, 9, 15};
  int pivot_13 = local_arr[aux % 3];
  acc = (acc + (pivot_13 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st_1 = {0};
  struct EventLog_R000467_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_63_1)
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

  switch (threshold_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_16_1 > 20)
  {
    acc_1 = ((acc_1 + (stride_16_1 * 2)) + 5) & 127;
    aux_1 ^= stride_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_16_2 > 20)
  {
    acc_2 = ((acc_2 + (stride_16_2 * 2)) + 5) & 127;
    aux_2 ^= stride_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_16_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_63_1 == threshold_63_2);
  assert(stride_16_1 == stride_16_2);
}

int fn_R000467_6713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_63 = (aux + st.buffer[1]) & 3;
  switch (threshold_63)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_16 > 20)
  {
    acc = ((acc + (stride_16 * 2)) + 5) & 127;
    aux ^= stride_16 & 15;
  }
  else
  {
    acc = ((acc - stride_16) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000467_6713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_42_1 = local_arr_1[aux_1 % 3];
  int tracker_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_42_2 * 2)) & 127;
  int offset_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_31_1)
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

  switch (offset_31_2)
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

  int threshold_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_96_1 > 34)
  {
    acc_1 = ((acc_1 + (threshold_96_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_96_2 > 34)
  {
    acc_2 = ((acc_2 + (threshold_96_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_42_1 == tracker_42_2);
  assert(offset_31_1 == offset_31_2);
  assert(threshold_96_1 == threshold_96_2);
}

int fn_R000467_6713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_42 = local_arr[aux % 3];
  acc = (acc + (tracker_42 * 2)) & 127;
  int offset_31 = (aux + st.buffer[1]) & 3;
  switch (offset_31)
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

  int threshold_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_96 > 34)
  {
    acc = ((acc + (threshold_96 * 2)) + 5) & 127;
    aux ^= threshold_96 & 15;
  }
  else
  {
    acc = ((acc - threshold_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000467_6713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st_1 = {0};
  struct EventLog_R000467_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_83_1 = local_arr_1[aux_1 % 3];
  int quotient_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_83_2 * 2)) & 127;
  int bound_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_83_1 > 23)
  {
    acc_1 = ((acc_1 + (bound_83_1 * 2)) + 5) & 127;
    aux_1 ^= bound_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_83_2 > 23)
  {
    acc_2 = ((acc_2 + (bound_83_2 * 2)) + 5) & 127;
    aux_2 ^= bound_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_83_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_83_1 == quotient_83_2);
  assert(bound_83_1 == bound_83_2);
}

int fn_R000467_6713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int quotient_83 = local_arr[aux % 3];
  acc = (acc + (quotient_83 * 2)) & 127;
  int bound_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_83 > 23)
  {
    acc = ((acc + (bound_83 * 2)) + 5) & 127;
    aux ^= bound_83 & 15;
  }
  else
  {
    acc = ((acc - bound_83) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st_1 = {0};
  struct CipherContext_R000467_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int parity_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_66_1) & 63;
  aux_2 = (aux_2 + parity_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_22_1 > 18)
  {
    acc_1 = ((acc_1 + (anchor_22_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_22_2 > 18)
  {
    acc_2 = ((acc_2 + (anchor_22_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_22_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_66_1 == parity_66_2);
  assert(anchor_22_1 == anchor_22_2);
}

int fn_R000467_6713_13(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int parity_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_66) & 63;
  acc ^= aux;
  int anchor_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_22 > 18)
  {
    acc = ((acc + (anchor_22 * 2)) + 5) & 127;
    aux ^= anchor_22 & 15;
  }
  else
  {
    acc = ((acc - anchor_22) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000467_6713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int bound_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_69_1)
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

  switch (bound_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_69_1 == bound_69_2);
}

int fn_R000467_6713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int bound_69 = (aux + st.buffer[1]) & 3;
  switch (bound_69)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st_1 = {0};
  struct EventLog_R000467_6713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_47_1)
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

  switch (delta_47_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.seq == st_2.seq);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_47_1 == delta_47_2);
}

int fn_R000467_6713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000467_6713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_47 = (aux + st.buffer[1]) & 3;
  switch (delta_47)
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

void fn_R000467_6713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int window_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_84_1 > 45)
  {
    acc_1 = ((acc_1 + (window_84_1 * 2)) + 5) & 127;
    aux_1 ^= window_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_84_2 > 45)
  {
    acc_2 = ((acc_2 + (window_84_2 * 2)) + 5) & 127;
    aux_2 ^= window_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_64_1)
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

  switch (parity_64_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_84_1 == window_84_2);
  assert(parity_64_1 == parity_64_2);
}

int fn_R000467_6713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int window_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_84 > 45)
  {
    acc = ((acc + (window_84 * 2)) + 5) & 127;
    aux ^= window_84 & 15;
  }
  else
  {
    acc = ((acc - window_84) + 11) & 127;
    aux += 3;
  }
  int parity_64 = (aux + st.buffer[1]) & 3;
  switch (parity_64)
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

void fn_R000467_6713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_27_1 = local_arr_1[aux_1 % 3];
  int phase_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_27_2 * 2)) & 127;
  int index_reg_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_51_1 > 24)
  {
    acc_1 = ((acc_1 + (index_reg_51_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_51_2 > 24)
  {
    acc_2 = ((acc_2 + (index_reg_51_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_16_1)
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

  switch (bound_16_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_27_1 == phase_27_2);
  assert(index_reg_51_1 == index_reg_51_2);
  assert(bound_16_1 == bound_16_2);
}

int fn_R000467_6713_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int phase_27 = local_arr[aux % 3];
  acc = (acc + (phase_27 * 2)) & 127;
  int index_reg_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_51 > 24)
  {
    acc = ((acc + (index_reg_51 * 2)) + 5) & 127;
    aux ^= index_reg_51 & 15;
  }
  else
  {
    acc = ((acc - index_reg_51) + 11) & 127;
    aux += 3;
  }
  int bound_16 = (aux + st.buffer[1]) & 3;
  switch (bound_16)
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
  return (acc + aux) & 255;
}

void fn_R000467_6713_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st_1 = {0};
  struct CipherContext_R000467_6713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_36_1)
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

  switch (offset_36_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_36_1 == offset_36_2);
}

int fn_R000467_6713_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R000467_6713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_36 = (aux + st.buffer[1]) & 3;
  switch (offset_36)
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

void fn_R000467_6713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int pivot_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_53_1 > 16)
  {
    acc_1 = ((acc_1 + (pivot_53_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_53_2 > 16)
  {
    acc_2 = ((acc_2 + (pivot_53_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_53_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_61_1) & 63;
  aux_2 = (aux_2 + accumulator_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_53_1 == pivot_53_2);
  assert(accumulator_61_1 == accumulator_61_2);
}

int fn_R000467_6713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int pivot_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_53 > 16)
  {
    acc = ((acc + (pivot_53 * 2)) + 5) & 127;
    aux ^= pivot_53 & 15;
  }
  else
  {
    acc = ((acc - pivot_53) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000467_6713_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st_1 = {0};
  struct SensorNode_R000467_6713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int offset_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_42_1 > 38)
  {
    acc_1 = ((acc_1 + (offset_42_1 * 2)) + 5) & 127;
    aux_1 ^= offset_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_42_2 > 38)
  {
    acc_2 = ((acc_2 + (offset_42_2 * 2)) + 5) & 127;
    aux_2 ^= offset_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_73_1 = local_arr_1[aux_1 % 3];
  int quantum_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_42_1 == offset_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_73_1 == quantum_73_2);
}

int fn_R000467_6713_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000467_6713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int offset_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_42 > 38)
  {
    acc = ((acc + (offset_42 * 2)) + 5) & 127;
    aux ^= offset_42 & 15;
  }
  else
  {
    acc = ((acc - offset_42) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_73 = local_arr[aux % 3];
  acc = (acc + (quantum_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000467_6713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_94_1 = local_arr_1[aux_1 % 3];
  int residue_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_94_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_61_1)
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

  switch (tally_61_2)
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

  int window_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_60_1 > 31)
  {
    acc_1 = ((acc_1 + (window_60_1 * 2)) + 5) & 127;
    aux_1 ^= window_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_60_2 > 31)
  {
    acc_2 = ((acc_2 + (window_60_2 * 2)) + 5) & 127;
    aux_2 ^= window_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_60_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_94_1 == residue_94_2);
  assert(tally_61_1 == tally_61_2);
  assert(window_60_1 == window_60_2);
}

int fn_R000467_6713_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int residue_94 = local_arr[aux % 3];
  acc = (acc + (residue_94 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_61 = (aux + st.buffer[1]) & 3;
  switch (tally_61)
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

  int window_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_60 > 31)
  {
    acc = ((acc + (window_60 * 2)) + 5) & 127;
    aux ^= window_60 & 15;
  }
  else
  {
    acc = ((acc - window_60) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000467_6713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int damping_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_43_1 > 21)
  {
    acc_1 = ((acc_1 + (damping_43_1 * 2)) + 5) & 127;
    aux_1 ^= damping_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_43_2 > 21)
  {
    acc_2 = ((acc_2 + (damping_43_2 * 2)) + 5) & 127;
    aux_2 ^= damping_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_58_1)
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

  switch (quotient_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_43_1 == damping_43_2);
  assert(quotient_58_1 == quotient_58_2);
}

int fn_R000467_6713_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000467_6713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int damping_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_43 > 21)
  {
    acc = ((acc + (damping_43 * 2)) + 5) & 127;
    aux ^= damping_43 & 15;
  }
  else
  {
    acc = ((acc - damping_43) + 11) & 127;
    aux += 3;
  }
  int quotient_58 = (aux + st.buffer[1]) & 3;
  switch (quotient_58)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000467_0_1;
  int sec_r000467_0_2;
  int sec_r000467_1_1;
  int sec_r000467_1_2;
  int sec_r000467_2_1;
  int sec_r000467_2_2;
  int sec_r000467_3_1;
  int sec_r000467_3_2;
  int sec_r000467_4_1;
  int sec_r000467_4_2;
  int sec_r000467_5_1;
  int sec_r000467_5_2;
  int sec_r000467_6_1;
  int sec_r000467_6_2;
  int sec_r000467_7_1;
  int sec_r000467_7_2;
  int sec_r000467_8_1;
  int sec_r000467_8_2;
  int sec_r000467_9_1;
  int sec_r000467_9_2;
  int sec_r000467_10_1;
  int sec_r000467_10_2;
  int sec_r000467_11_1;
  int sec_r000467_11_2;
  int sec_r000467_12_1;
  int sec_r000467_12_2;
  int sec_r000467_13_1;
  int sec_r000467_13_2;
  int sec_r000467_14_1;
  int sec_r000467_14_2;
  int sec_r000467_15_1;
  int sec_r000467_15_2;
  int sec_r000467_16_1;
  int sec_r000467_16_2;
  int pub_r000467_0_1;
  int pub_r000467_0_2;
  int pub_r000467_1_1;
  int pub_r000467_1_2;
  int pub_r000467_2_1;
  int pub_r000467_2_2;
  int pub_r000467_3_1;
  int pub_r000467_3_2;
  int pub_r000467_4_1;
  int pub_r000467_4_2;
  int pub_r000467_5_1;
  int pub_r000467_5_2;
  int pub_r000467_6_1;
  int pub_r000467_6_2;
  int pub_r000467_7_1;
  int pub_r000467_7_2;
  int pub_r000467_8_1;
  int pub_r000467_8_2;
  int pub_r000467_9_1;
  int pub_r000467_9_2;
  int pub_r000467_10_1;
  int pub_r000467_10_2;
  int pub_r000467_11_1;
  int pub_r000467_11_2;
  int pub_r000467_12_1;
  int pub_r000467_12_2;
  int pub_r000467_13_1;
  int pub_r000467_13_2;
  int pub_r000467_14_1;
  int pub_r000467_14_2;
  int pub_r000467_15_1;
  int pub_r000467_15_2;
  int pub_r000467_16_1;
  int pub_r000467_16_2;
  int pub_r000467_17_1;
  int pub_r000467_17_2;
  int pub_r000467_18_1;
  int pub_r000467_18_2;
  int pub_r000467_19_1;
  int pub_r000467_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000467_0_1 >= (-100)) && (pub_r000467_0_1 <= 100));
  __CPROVER_assume((pub_r000467_0_2 >= (-100)) && (pub_r000467_0_2 <= 100));
  __CPROVER_assume((pub_r000467_1_1 >= (-100)) && (pub_r000467_1_1 <= 100));
  __CPROVER_assume((pub_r000467_1_2 >= (-100)) && (pub_r000467_1_2 <= 100));
  __CPROVER_assume((pub_r000467_2_1 >= (-100)) && (pub_r000467_2_1 <= 100));
  __CPROVER_assume((pub_r000467_2_2 >= (-100)) && (pub_r000467_2_2 <= 100));
  __CPROVER_assume((pub_r000467_3_1 >= (-100)) && (pub_r000467_3_1 <= 100));
  __CPROVER_assume((pub_r000467_3_2 >= (-100)) && (pub_r000467_3_2 <= 100));
  __CPROVER_assume((pub_r000467_4_1 >= (-100)) && (pub_r000467_4_1 <= 100));
  __CPROVER_assume((pub_r000467_4_2 >= (-100)) && (pub_r000467_4_2 <= 100));
  __CPROVER_assume((pub_r000467_5_1 >= (-100)) && (pub_r000467_5_1 <= 100));
  __CPROVER_assume((pub_r000467_5_2 >= (-100)) && (pub_r000467_5_2 <= 100));
  __CPROVER_assume((pub_r000467_6_1 >= (-100)) && (pub_r000467_6_1 <= 100));
  __CPROVER_assume((pub_r000467_6_2 >= (-100)) && (pub_r000467_6_2 <= 100));
  __CPROVER_assume((pub_r000467_7_1 >= (-100)) && (pub_r000467_7_1 <= 100));
  __CPROVER_assume((pub_r000467_7_2 >= (-100)) && (pub_r000467_7_2 <= 100));
  __CPROVER_assume((pub_r000467_8_1 >= (-100)) && (pub_r000467_8_1 <= 100));
  __CPROVER_assume((pub_r000467_8_2 >= (-100)) && (pub_r000467_8_2 <= 100));
  __CPROVER_assume((pub_r000467_9_1 >= (-100)) && (pub_r000467_9_1 <= 100));
  __CPROVER_assume((pub_r000467_9_2 >= (-100)) && (pub_r000467_9_2 <= 100));
  __CPROVER_assume((pub_r000467_10_1 >= (-100)) && (pub_r000467_10_1 <= 100));
  __CPROVER_assume((pub_r000467_10_2 >= (-100)) && (pub_r000467_10_2 <= 100));
  __CPROVER_assume((pub_r000467_11_1 >= (-100)) && (pub_r000467_11_1 <= 100));
  __CPROVER_assume((pub_r000467_11_2 >= (-100)) && (pub_r000467_11_2 <= 100));
  __CPROVER_assume((pub_r000467_12_1 >= (-100)) && (pub_r000467_12_1 <= 100));
  __CPROVER_assume((pub_r000467_12_2 >= (-100)) && (pub_r000467_12_2 <= 100));
  __CPROVER_assume((pub_r000467_13_1 >= (-100)) && (pub_r000467_13_1 <= 100));
  __CPROVER_assume((pub_r000467_13_2 >= (-100)) && (pub_r000467_13_2 <= 100));
  __CPROVER_assume((pub_r000467_14_1 >= (-100)) && (pub_r000467_14_1 <= 100));
  __CPROVER_assume((pub_r000467_14_2 >= (-100)) && (pub_r000467_14_2 <= 100));
  __CPROVER_assume((pub_r000467_15_1 >= (-100)) && (pub_r000467_15_1 <= 100));
  __CPROVER_assume((pub_r000467_15_2 >= (-100)) && (pub_r000467_15_2 <= 100));
  __CPROVER_assume((pub_r000467_16_1 >= (-100)) && (pub_r000467_16_1 <= 100));
  __CPROVER_assume((pub_r000467_16_2 >= (-100)) && (pub_r000467_16_2 <= 100));
  __CPROVER_assume((pub_r000467_17_1 >= (-100)) && (pub_r000467_17_1 <= 100));
  __CPROVER_assume((pub_r000467_17_2 >= (-100)) && (pub_r000467_17_2 <= 100));
  __CPROVER_assume((pub_r000467_18_1 >= (-100)) && (pub_r000467_18_1 <= 100));
  __CPROVER_assume((pub_r000467_18_2 >= (-100)) && (pub_r000467_18_2 <= 100));
  __CPROVER_assume((pub_r000467_19_1 >= (-100)) && (pub_r000467_19_1 <= 100));
  __CPROVER_assume((pub_r000467_19_2 >= (-100)) && (pub_r000467_19_2 <= 100));
  __CPROVER_assume((sec_r000467_0_1 >= 0) && (sec_r000467_0_1 <= 255));
  __CPROVER_assume((sec_r000467_0_2 >= 0) && (sec_r000467_0_2 <= 255));
  __CPROVER_assume((sec_r000467_1_1 >= 0) && (sec_r000467_1_1 <= 255));
  __CPROVER_assume((sec_r000467_1_2 >= 0) && (sec_r000467_1_2 <= 255));
  __CPROVER_assume((sec_r000467_2_1 >= 0) && (sec_r000467_2_1 <= 255));
  __CPROVER_assume((sec_r000467_2_2 >= 0) && (sec_r000467_2_2 <= 255));
  __CPROVER_assume((sec_r000467_3_1 >= 0) && (sec_r000467_3_1 <= 255));
  __CPROVER_assume((sec_r000467_3_2 >= 0) && (sec_r000467_3_2 <= 255));
  __CPROVER_assume((sec_r000467_4_1 >= 0) && (sec_r000467_4_1 <= 255));
  __CPROVER_assume((sec_r000467_4_2 >= 0) && (sec_r000467_4_2 <= 255));
  __CPROVER_assume((sec_r000467_5_1 >= 0) && (sec_r000467_5_1 <= 255));
  __CPROVER_assume((sec_r000467_5_2 >= 0) && (sec_r000467_5_2 <= 255));
  __CPROVER_assume((sec_r000467_6_1 >= 0) && (sec_r000467_6_1 <= 255));
  __CPROVER_assume((sec_r000467_6_2 >= 0) && (sec_r000467_6_2 <= 255));
  __CPROVER_assume((sec_r000467_7_1 >= 0) && (sec_r000467_7_1 <= 255));
  __CPROVER_assume((sec_r000467_7_2 >= 0) && (sec_r000467_7_2 <= 255));
  __CPROVER_assume((sec_r000467_8_1 >= 0) && (sec_r000467_8_1 <= 255));
  __CPROVER_assume((sec_r000467_8_2 >= 0) && (sec_r000467_8_2 <= 255));
  __CPROVER_assume((sec_r000467_9_1 >= 0) && (sec_r000467_9_1 <= 255));
  __CPROVER_assume((sec_r000467_9_2 >= 0) && (sec_r000467_9_2 <= 255));
  __CPROVER_assume((sec_r000467_10_1 >= 0) && (sec_r000467_10_1 <= 255));
  __CPROVER_assume((sec_r000467_10_2 >= 0) && (sec_r000467_10_2 <= 255));
  __CPROVER_assume((sec_r000467_11_1 >= 0) && (sec_r000467_11_1 <= 255));
  __CPROVER_assume((sec_r000467_11_2 >= 0) && (sec_r000467_11_2 <= 255));
  __CPROVER_assume((sec_r000467_12_1 >= 0) && (sec_r000467_12_1 <= 255));
  __CPROVER_assume((sec_r000467_12_2 >= 0) && (sec_r000467_12_2 <= 255));
  __CPROVER_assume((sec_r000467_13_1 >= 0) && (sec_r000467_13_1 <= 255));
  __CPROVER_assume((sec_r000467_13_2 >= 0) && (sec_r000467_13_2 <= 255));
  __CPROVER_assume((sec_r000467_14_1 >= 0) && (sec_r000467_14_1 <= 255));
  __CPROVER_assume((sec_r000467_14_2 >= 0) && (sec_r000467_14_2 <= 255));
  __CPROVER_assume((sec_r000467_15_1 >= 0) && (sec_r000467_15_1 <= 255));
  __CPROVER_assume((sec_r000467_15_2 >= 0) && (sec_r000467_15_2 <= 255));
  __CPROVER_assume((sec_r000467_16_1 >= 0) && (sec_r000467_16_1 <= 255));
  __CPROVER_assume((sec_r000467_16_2 >= 0) && (sec_r000467_16_2 <= 255));
  struct CipherContext_R000467_6713_0 st_var_0_1 = {0};
  struct CipherContext_R000467_6713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000467_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000467_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000467_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000467_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000467_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000467_0_2 + 7) & 15;
  struct SensorNode_R000467_6713_1 st_var_1_1 = {0};
  struct SensorNode_R000467_6713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000467_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000467_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000467_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000467_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000467_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000467_0_2 + 9) & 15;
  struct EventLog_R000467_6713_2 st_var_2_1 = {0};
  struct EventLog_R000467_6713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000467_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000467_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000467_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000467_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000467_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000467_0_2 + 11) & 15;
  struct MatrixBlock_R000467_6713_3 st_var_3_1 = {0};
  struct MatrixBlock_R000467_6713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000467_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000467_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000467_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000467_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000467_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000467_0_2 + 13) & 15;
  union ColorPixel_R000467_6713_0 u_var_1;
  union ColorPixel_R000467_6713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
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
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 33)
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
  if (stage_v_5_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 33)
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
  int stage_v_6_1 = (st_var_2_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_2_2.buffer[0] ^ 9) & 3;
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

  int stage_v_7_1 = 0;
  int stage_v_7_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_7_1 = ((stage_v_7_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_7_2 = ((stage_v_7_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 12) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 12) & 15;
  int stage_v_11_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_11_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= stage_v_11_1;
  chk_sum_2 ^= stage_v_11_2;
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
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 39)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 39)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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

  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (29 & 31);
  int stage_v_24_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (29 & 31);
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= (stage_v_24_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_24_2 << 1) & 127;
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 27) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 27) & 15;
  int stage_v_26_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_26_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= stage_v_26_1;
  chk_sum_2 ^= stage_v_26_2;
  int stage_v_27_1 = ((st_var_3_1.buffer[0] * 2) + 88) & 63;
  int stage_v_27_2 = ((st_var_3_2.buffer[0] * 2) + 88) & 63;
  if (stage_v_27_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + stage_v_27_1) - 5) & 255;
    if (stage_v_27_1 > 49)
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
  if (stage_v_27_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + stage_v_27_2) - 5) & 255;
    if (stage_v_27_2 > 49)
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 29) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 29) & 15;
  int stage_v_28_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_28_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  chk_sum_1 ^= stage_v_28_1;
  chk_sum_2 ^= stage_v_28_2;
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

  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
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
  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 36) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 36) & 15;
  int stage_v_35_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_35_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= stage_v_35_1;
  chk_sum_2 ^= stage_v_35_2;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 44)
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
  if (stage_v_36_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 44)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 44)
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
  if (stage_v_40_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 44)
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
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 46)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 46)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((st_var_2_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_2_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 27)
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
  if (stage_v_42_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 27)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 31)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 31)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = ((st_var_3_1.buffer[2] * 2) + 148) & 63;
  int stage_v_47_2 = ((st_var_3_2.buffer[2] * 2) + 148) & 63;
  if (stage_v_47_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_47_1) - 5) & 255;
    if (stage_v_47_1 > 27)
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
  if (stage_v_47_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_47_2) - 5) & 255;
    if (stage_v_47_2 > 27)
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

  switch (stage_v_48_2)
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
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 51) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_51_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_52_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_52_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_53_1 = ((st_var_1_1.buffer[2] * 2) + 166) & 63;
  int stage_v_53_2 = ((st_var_1_2.buffer[2] * 2) + 166) & 63;
  if (stage_v_53_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_53_1) - 5) & 255;
    if (stage_v_53_1 > 40)
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
  if (stage_v_53_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_53_2) - 5) & 255;
    if (stage_v_53_2 > 40)
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
  int stage_v_54_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_54_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_55_1 = table_1[3];
  int stage_v_55_2 = table_2[3];
  table_1[3] = (table_1[0] + 111) & 63;
  table_2[3] = (table_2[0] + 111) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((st_var_0_1.buffer[2] * 2) + 175) & 63;
  int stage_v_56_2 = ((st_var_0_2.buffer[2] * 2) + 175) & 63;
  if (stage_v_56_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_56_1) - 5) & 255;
    if (stage_v_56_1 > 55)
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
  if (stage_v_56_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_56_2) - 5) & 255;
    if (stage_v_56_2 > 55)
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
  int stage_v_57_1 = table_1[1];
  int stage_v_57_2 = table_2[1];
  table_1[1] = (table_1[2] + 115) & 63;
  table_2[1] = (table_2[2] + 115) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = table_1[2];
  int stage_v_58_2 = table_2[2];
  table_1[2] = (table_1[3] + 117) & 63;
  table_2[2] = (table_2[3] + 117) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = table_1[3];
  int stage_v_59_2 = table_2[3];
  table_1[3] = (table_1[0] + 119) & 63;
  table_2[3] = (table_2[0] + 119) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 61) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 61) & 15;
  int stage_v_60_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_60_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  chk_sum_1 ^= stage_v_60_1;
  chk_sum_2 ^= stage_v_60_2;
  int stage_v_61_1 = (st_var_1_1.buffer[0] ^ 64) & 3;
  int stage_v_61_2 = (st_var_1_2.buffer[0] ^ 64) & 3;
  switch (stage_v_61_1)
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

  switch (stage_v_61_2)
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

  int stage_v_62_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_62_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_63_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (68 & 31);
  int stage_v_63_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (68 & 31);
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= (stage_v_63_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_63_2 << 1) & 127;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 68) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = ((st_var_0_1.buffer[2] * 2) + 211) & 63;
  int stage_v_68_2 = ((st_var_0_2.buffer[2] * 2) + 211) & 63;
  if (stage_v_68_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_68_1) - 5) & 255;
    if (stage_v_68_1 > 34)
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
  if (stage_v_68_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_68_2) - 5) & 255;
    if (stage_v_68_2 > 34)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = (st_var_2_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_2_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  st_var_3_1.buffer[2] = (st_var_3_1.buffer[2] + 72) & 15;
  st_var_3_2.buffer[2] = (st_var_3_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_3_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_3_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = table_1[0];
  int stage_v_72_2 = table_2[0];
  table_1[0] = (table_1[1] + 145) & 63;
  table_2[0] = (table_2[1] + 145) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000467_14_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000467_18_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000467_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000467_18_1 + 7) & 127;
  }
  if ((sec_r000467_14_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000467_18_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000467_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000467_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000467_5_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000467_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000467_5_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000467_5_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000467_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000467_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000467_10_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000467_7_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000467_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000467_7_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000467_10_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000467_7_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000467_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000467_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000467_14_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000467_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000467_14_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000467_14_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000467_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000467_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000467_6_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000467_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000467_6_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000467_6_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000467_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000467_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000467_8_1 & 1) != 0)
  {
    if ((sec_r000467_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000467_13_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000467_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000467_13_1 + 7) & 127;
  }
  if ((sec_r000467_8_2 & 1) != 0)
  {
    if ((sec_r000467_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000467_13_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000467_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000467_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000467_8_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000467_14_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000467_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000467_14_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000467_8_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000467_14_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000467_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000467_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000467_8_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000467_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000467_8_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000467_8_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000467_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000467_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000467_1_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000467_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000467_1_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000467_1_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000467_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000467_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000467_10_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000467_16_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000467_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000467_16_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000467_10_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000467_16_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000467_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000467_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000467_16_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000467_19_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000467_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000467_19_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000467_16_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000467_19_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000467_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000467_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000467_3_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000467_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000467_3_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000467_3_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000467_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000467_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_79_1 & 1) != 0)
  {
    if ((sec_r000467_10_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((stage_v_79_2 & 1) != 0)
  {
    if ((sec_r000467_10_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000467_13_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000467_13_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000467_3_1 & 1) != 0)
  {
    if ((sec_r000467_9_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000467_4_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000467_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000467_4_1 + 7) & 127;
  }
  if ((sec_r000467_3_2 & 1) != 0)
  {
    if ((sec_r000467_9_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000467_4_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000467_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000467_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000467_10_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000467_1_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000467_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000467_1_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000467_10_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000467_1_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000467_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000467_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000467_1_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000467_19_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000467_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000467_19_1 + 7) & 127;
  }
  if ((sec_r000467_1_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000467_19_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000467_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000467_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000467_3_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000467_3_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000467_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000467_3_1 + 7) & 127;
  }
  if ((sec_r000467_3_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000467_3_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000467_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000467_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000467_5_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000467_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000467_5_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000467_5_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000467_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000467_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000467_14_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000467_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000467_14_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000467_14_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000467_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000467_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000467_0_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000467_13_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000467_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000467_13_1 + 7) & 127;
  }
  if ((sec_r000467_0_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000467_13_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000467_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000467_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((sec_r000467_1_1 & 1) != 0)
  {
    if ((sec_r000467_8_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((sec_r000467_1_2 & 1) != 0)
  {
    if ((sec_r000467_8_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000467_13_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000467_3_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000467_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000467_3_1 + 7) & 127;
  }
  if ((sec_r000467_13_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000467_3_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000467_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000467_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000467_10_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000467_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000467_10_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000467_10_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000467_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000467_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000467_11_1 & 1) != 0)
  {
    if ((sec_r000467_7_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000467_6_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000467_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000467_6_1 + 7) & 127;
  }
  if ((sec_r000467_11_2 & 1) != 0)
  {
    if ((sec_r000467_7_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000467_6_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000467_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000467_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000467_0_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000467_3_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000467_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000467_3_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000467_0_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000467_3_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000467_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000467_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000467_7_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000467_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000467_7_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000467_7_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000467_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000467_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((sec_r000467_11_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000467_9_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000467_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000467_9_1 + 7) & 127;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((sec_r000467_11_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000467_9_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000467_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000467_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000467_6_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000467_0_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000467_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000467_0_1 + 7) & 127;
  }
  if ((sec_r000467_6_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000467_0_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000467_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000467_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000467_3_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000467_9_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000467_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000467_9_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000467_3_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000467_9_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000467_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000467_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000467_11_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000467_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000467_11_1 + 7) & 127;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000467_11_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000467_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000467_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000467_15_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000467_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000467_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000467_14_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000467_15_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000467_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000467_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000467_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000467_5_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000467_11_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000467_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000467_11_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000467_5_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000467_11_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000467_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000467_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000467_2_1 & 1) != 0)
  {
    if ((sec_r000467_3_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000467_14_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000467_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000467_14_1 + 7) & 127;
  }
  if ((sec_r000467_2_2 & 1) != 0)
  {
    if ((sec_r000467_3_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000467_14_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000467_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000467_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((sec_r000467_2_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000467_0_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000467_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000467_0_1 + 7) & 127;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((sec_r000467_2_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000467_0_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000467_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000467_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000467_10_1 & 1) != 0)
  {
    if ((sec_r000467_1_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000467_5_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000467_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000467_5_1 + 7) & 127;
  }
  if ((sec_r000467_10_2 & 1) != 0)
  {
    if ((sec_r000467_1_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000467_5_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000467_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000467_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000467_0_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000467_0_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000467_2_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000467_12_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000467_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000467_12_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000467_2_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000467_12_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000467_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000467_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000467_15_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000467_8_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000467_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000467_8_1 + 7) & 127;
  }
  if ((sec_r000467_15_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000467_8_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000467_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000467_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000467_14_1 & 1) != 0)
  {
    if ((sec_r000467_2_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000467_9_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000467_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000467_9_1 + 7) & 127;
  }
  if ((sec_r000467_14_2 & 1) != 0)
  {
    if ((sec_r000467_2_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000467_9_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000467_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000467_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((sec_r000467_13_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000467_6_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000467_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000467_6_1 + 7) & 127;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((sec_r000467_13_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000467_6_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000467_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000467_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_80_1 & 1) != 0)
  {
    if ((sec_r000467_2_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000467_15_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000467_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000467_15_1 + 7) & 127;
  }
  if ((stage_v_80_2 & 1) != 0)
  {
    if ((sec_r000467_2_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000467_15_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000467_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000467_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000467_7_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000467_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000467_7_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000467_7_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000467_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000467_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000467_12_1 & 1) != 0)
  {
    if ((sec_r000467_13_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000467_18_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000467_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000467_18_1 + 7) & 127;
  }
  if ((sec_r000467_12_2 & 1) != 0)
  {
    if ((sec_r000467_13_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000467_18_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000467_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000467_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000467_11_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000467_1_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000467_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000467_1_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000467_11_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000467_1_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000467_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000467_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000467_0_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000467_18_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000467_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000467_18_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000467_0_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000467_18_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000467_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000467_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000467_0_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000467_19_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000467_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000467_19_1 + 7) & 127;
  }
  if ((sec_r000467_0_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000467_19_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000467_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000467_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r000467_11_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000467_16_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000467_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000467_16_1 + 7) & 127;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r000467_11_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000467_16_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000467_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000467_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000467_6_1 & 1) != 0)
  {
    if ((sec_r000467_13_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000467_18_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000467_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000467_18_1 + 7) & 127;
  }
  if ((sec_r000467_6_2 & 1) != 0)
  {
    if ((sec_r000467_13_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000467_18_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000467_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000467_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000467_1_1 & 1) != 0)
  {
    if ((sec_r000467_1_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000467_7_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000467_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000467_7_1 + 7) & 127;
  }
  if ((sec_r000467_1_2 & 1) != 0)
  {
    if ((sec_r000467_1_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000467_7_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000467_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000467_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000467_14_1 & 1) != 0)
  {
    if ((sec_r000467_10_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000467_15_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000467_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000467_15_1 + 7) & 127;
  }
  if ((sec_r000467_14_2 & 1) != 0)
  {
    if ((sec_r000467_10_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000467_15_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000467_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000467_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_116_1 & 1) != 0)
  {
    if ((sec_r000467_0_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000467_6_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000467_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000467_6_1 + 7) & 127;
  }
  if ((stage_v_116_2 & 1) != 0)
  {
    if ((sec_r000467_0_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000467_6_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000467_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000467_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000467_16_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000467_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000467_16_1 + 7) & 127;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000467_16_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000467_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000467_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_117_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000467_2_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000467_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000467_2_1 + 7) & 127;
  }
  if ((stage_v_117_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000467_2_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000467_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000467_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((sec_r000467_5_1 & 1) != 0)
  {
    if ((sec_r000467_6_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000467_16_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000467_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000467_16_1 + 7) & 127;
  }
  if ((sec_r000467_5_2 & 1) != 0)
  {
    if ((sec_r000467_6_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000467_16_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000467_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000467_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((sec_r000467_12_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000467_9_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000467_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000467_9_1 + 7) & 127;
  }
  if ((sec_r000467_12_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000467_9_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000467_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000467_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((sec_r000467_14_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000467_17_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000467_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000467_17_1 + 7) & 127;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((sec_r000467_14_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000467_17_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000467_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000467_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000467_13_1 & 1) != 0)
  {
    if ((sec_r000467_3_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000467_5_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000467_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000467_5_1 + 7) & 127;
  }
  if ((sec_r000467_13_2 & 1) != 0)
  {
    if ((sec_r000467_3_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000467_5_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000467_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000467_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000467_9_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000467_16_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000467_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000467_16_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000467_9_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000467_16_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000467_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000467_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000467_13_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000467_9_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000467_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000467_9_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000467_13_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000467_9_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000467_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000467_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000467_12_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000467_19_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000467_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000467_19_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000467_12_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000467_19_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000467_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000467_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000467_11_1 & 2) != 0)
    {
      stage_v_135_1 = (pub_r000467_5_1 + 31) & 127;
    }
    else
    {
      stage_v_135_1 = (pub_r000467_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_1 = (pub_r000467_5_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000467_11_2 & 2) != 0)
    {
      stage_v_135_2 = (pub_r000467_5_2 + 31) & 127;
    }
    else
    {
      stage_v_135_2 = (pub_r000467_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_135_2 = (pub_r000467_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000467_12_1 == pub_r000467_12_2);
  __CPROVER_assume(pub_r000467_8_1 == pub_r000467_8_2);
  __CPROVER_assume(sec_r000467_0_1 != sec_r000467_0_2);
  __CPROVER_assume(sec_r000467_14_1 != sec_r000467_14_2);
  __CPROVER_assume(pub_r000467_1_1 == pub_r000467_1_2);
  __CPROVER_assume(pub_r000467_10_1 == pub_r000467_10_2);
  __CPROVER_assume(sec_r000467_6_1 != sec_r000467_6_2);
  __CPROVER_assume(sec_r000467_10_1 != sec_r000467_10_2);
  __CPROVER_assume(pub_r000467_11_1 == pub_r000467_11_2);
  __CPROVER_assume(sec_r000467_5_1 != sec_r000467_5_2);
  __CPROVER_assume(sec_r000467_2_1 != sec_r000467_2_2);
  __CPROVER_assume(sec_r000467_4_1 != sec_r000467_4_2);
  __CPROVER_assume(sec_r000467_8_1 != sec_r000467_8_2);
  __CPROVER_assume(pub_r000467_15_1 == pub_r000467_15_2);
  __CPROVER_assume(pub_r000467_2_1 == pub_r000467_2_2);
  __CPROVER_assume(pub_r000467_18_1 == pub_r000467_18_2);
  __CPROVER_assume(pub_r000467_17_1 == pub_r000467_17_2);
  __CPROVER_assume(sec_r000467_9_1 != sec_r000467_9_2);
  __CPROVER_assume(pub_r000467_4_1 == pub_r000467_4_2);
  __CPROVER_assume(pub_r000467_14_1 == pub_r000467_14_2);
  __CPROVER_assume(pub_r000467_13_1 == pub_r000467_13_2);
  __CPROVER_assume(pub_r000467_5_1 == pub_r000467_5_2);
  __CPROVER_assume(sec_r000467_16_1 != sec_r000467_16_2);
  __CPROVER_assume(pub_r000467_19_1 == pub_r000467_19_2);
  __CPROVER_assume(pub_r000467_16_1 == pub_r000467_16_2);
  __CPROVER_assume(sec_r000467_12_1 != sec_r000467_12_2);
  __CPROVER_assume(pub_r000467_7_1 == pub_r000467_7_2);
  __CPROVER_assume(sec_r000467_13_1 != sec_r000467_13_2);
  __CPROVER_assume(pub_r000467_0_1 == pub_r000467_0_2);
  __CPROVER_assume(sec_r000467_15_1 != sec_r000467_15_2);
  __CPROVER_assume(sec_r000467_7_1 != sec_r000467_7_2);
  __CPROVER_assume(pub_r000467_6_1 == pub_r000467_6_2);
  __CPROVER_assume(sec_r000467_1_1 != sec_r000467_1_2);
  __CPROVER_assume(sec_r000467_3_1 != sec_r000467_3_2);
  __CPROVER_assume(pub_r000467_3_1 == pub_r000467_3_2);
  __CPROVER_assume(pub_r000467_9_1 == pub_r000467_9_2);
  __CPROVER_assume(sec_r000467_11_1 != sec_r000467_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.counter == st_var_0_2.counter);
  assert(st_var_0_1.iv == st_var_0_2.iv);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.tag == st_var_0_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.facility == st_var_2_2.facility);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.density == st_var_3_2.density);
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
}


