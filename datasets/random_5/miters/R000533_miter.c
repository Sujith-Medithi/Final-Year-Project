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
struct EventLog_R000533_3313_0
{
  short facility;
  short code;
  short signature;
  int seq;
  int buffer[3];
};
struct AudioFrame_R000533_3313_1
{
  int sample_rate;
  int envelope;
  int peak;
  int gain;
  unsigned char channels;
  unsigned char rms;
  int buffer[3];
};
struct MatrixBlock_R000533_3313_2
{
  int trace;
  unsigned char determinant;
  unsigned char density;
  int buffer[3];
};
union TelemetryField_R000533_3313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000533_3313_1
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
void fn_R000533_3313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_23_1 = local_arr_1[aux_1 % 3];
  int tally_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_23_2 * 2)) & 127;
  int weight_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_70_1) & 63;
  aux_2 = (aux_2 + weight_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_88_1)
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

  switch (sample_88_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_23_1 == tally_23_2);
  assert(weight_70_1 == weight_70_2);
  assert(sample_88_1 == sample_88_2);
}

int fn_R000533_3313_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int tally_23 = local_arr[aux % 3];
  acc = (acc + (tally_23 * 2)) & 127;
  int weight_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_70) & 63;
  acc ^= aux;
  int sample_88 = (aux + st.buffer[1]) & 3;
  switch (sample_88)
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

void fn_R000533_3313_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int margin_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_48_1) & 63;
  aux_2 = (aux_2 + margin_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(margin_48_1 == margin_48_2);
}

int fn_R000533_3313_1(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int margin_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_48) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000533_3313_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_15_1)
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

  switch (weight_15_2)
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
  int coefficient_48_1 = local_arr_1[aux_1 % 3];
  int coefficient_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_48_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_15_1 == weight_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_48_1 == coefficient_48_2);
}

int fn_R000533_3313_2(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_15 = (aux + st.buffer[1]) & 3;
  switch (weight_15)
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
  int coefficient_48 = local_arr[aux % 3];
  acc = (acc + (coefficient_48 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000533_3313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000533_3313_0 st_1 = {0};
  struct EventLog_R000533_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int weight_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_89_1) & 63;
  aux_2 = (aux_2 + weight_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 30)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 30)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_79_1 = local_arr_1[aux_1 % 3];
  int vector_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_79_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_89_1 == weight_89_2);
  assert(offset_60_1 == offset_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_79_1 == vector_79_2);
}

int fn_R000533_3313_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000533_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int weight_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_89) & 63;
  acc ^= aux;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 30)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_79 = local_arr[aux % 3];
  acc = (acc + (vector_79 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000533_3313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tally_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_88_1) & 63;
  aux_2 = (aux_2 + tally_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_21_1)
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

  switch (mask_21_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_88_1 == tally_88_2);
  assert(mask_21_1 == mask_21_2);
}

int fn_R000533_3313_4(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tally_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_88) & 63;
  acc ^= aux;
  int mask_21 = (aux + st.buffer[1]) & 3;
  switch (mask_21)
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

void fn_R000533_3313_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_19_1 = local_arr_1[aux_1 % 3];
  int parity_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_19_2 * 2)) & 127;
  int residue_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_53_1 > 22)
  {
    acc_1 = ((acc_1 + (residue_53_1 * 2)) + 5) & 127;
    aux_1 ^= residue_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_53_2 > 22)
  {
    acc_2 = ((acc_2 + (residue_53_2 * 2)) + 5) & 127;
    aux_2 ^= residue_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_19_1 == parity_19_2);
  assert(residue_53_1 == residue_53_2);
}

int fn_R000533_3313_5(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int parity_19 = local_arr[aux % 3];
  acc = (acc + (parity_19 * 2)) & 127;
  int residue_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_53 > 22)
  {
    acc = ((acc + (residue_53 * 2)) + 5) & 127;
    aux ^= residue_53 & 15;
  }
  else
  {
    acc = ((acc - residue_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000533_3313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_35_1 = local_arr_1[aux_1 % 3];
  int sample_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_35_2 * 2)) & 127;
  int quotient_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_63_1)
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

  switch (quotient_63_2)
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

  int sample_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_50_1 > 37)
  {
    acc_1 = ((acc_1 + (sample_50_1 * 2)) + 5) & 127;
    aux_1 ^= sample_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_50_2 > 37)
  {
    acc_2 = ((acc_2 + (sample_50_2 * 2)) + 5) & 127;
    aux_2 ^= sample_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_69_1) & 63;
  aux_2 = (aux_2 + window_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_35_1 == sample_35_2);
  assert(quotient_63_1 == quotient_63_2);
  assert(sample_50_1 == sample_50_2);
  assert(window_69_1 == window_69_2);
}

int fn_R000533_3313_6(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int sample_35 = local_arr[aux % 3];
  acc = (acc + (sample_35 * 2)) & 127;
  int quotient_63 = (aux + st.buffer[1]) & 3;
  switch (quotient_63)
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

  int sample_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_50 > 37)
  {
    acc = ((acc + (sample_50 * 2)) + 5) & 127;
    aux ^= sample_50 & 15;
  }
  else
  {
    acc = ((acc - sample_50) + 11) & 127;
    aux += 3;
  }
  int window_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000533_3313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int accumulator_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_23_1 > 42)
  {
    acc_1 = ((acc_1 + (accumulator_23_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_23_2 > 42)
  {
    acc_2 = ((acc_2 + (accumulator_23_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_99_1 = local_arr_1[aux_1 % 3];
  int threshold_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_99_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_23_1 == accumulator_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_99_1 == threshold_99_2);
}

int fn_R000533_3313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int accumulator_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_23 > 42)
  {
    acc = ((acc + (accumulator_23 * 2)) + 5) & 127;
    aux ^= accumulator_23 & 15;
  }
  else
  {
    acc = ((acc - accumulator_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_99 = local_arr[aux % 3];
  acc = (acc + (threshold_99 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000533_3313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_55_1)
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

  switch (phase_55_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_55_1 == phase_55_2);
}

int fn_R000533_3313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_55 = (aux + st.buffer[1]) & 3;
  switch (phase_55)
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

void fn_R000533_3313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_40_1) & 63;
  aux_2 = (aux_2 + threshold_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_56_1 > 48)
  {
    acc_1 = ((acc_1 + (coefficient_56_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_56_2 > 48)
  {
    acc_2 = ((acc_2 + (coefficient_56_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_19_1)
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

  switch (quantum_19_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_40_1 == threshold_40_2);
  assert(coefficient_56_1 == coefficient_56_2);
  assert(quantum_19_1 == quantum_19_2);
}

int fn_R000533_3313_9(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_40) & 63;
  acc ^= aux;
  int coefficient_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_56 > 48)
  {
    acc = ((acc + (coefficient_56 * 2)) + 5) & 127;
    aux ^= coefficient_56 & 15;
  }
  else
  {
    acc = ((acc - coefficient_56) + 11) & 127;
    aux += 3;
  }
  int quantum_19 = (aux + st.buffer[1]) & 3;
  switch (quantum_19)
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

void fn_R000533_3313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int index_reg_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_64_1 > 37)
  {
    acc_1 = ((acc_1 + (index_reg_64_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_64_2 > 37)
  {
    acc_2 = ((acc_2 + (index_reg_64_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_42_1) & 63;
  aux_2 = (aux_2 + factor_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_22_1 = local_arr_1[aux_1 % 3];
  int quotient_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_64_1 == index_reg_64_2);
  assert(factor_42_1 == factor_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_22_1 == quotient_22_2);
}

int fn_R000533_3313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int index_reg_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_64 > 37)
  {
    acc = ((acc + (index_reg_64 * 2)) + 5) & 127;
    aux ^= index_reg_64 & 15;
  }
  else
  {
    acc = ((acc - index_reg_64) + 11) & 127;
    aux += 3;
  }
  int factor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_42) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_22 = local_arr[aux % 3];
  acc = (acc + (quotient_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000533_3313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int cursor_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_23_1) & 63;
  aux_2 = (aux_2 + cursor_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_23_1 == cursor_23_2);
}

int fn_R000533_3313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000533_3313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int cursor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_23) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000533_3313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_30_1 = local_arr_1[aux_1 % 3];
  int cursor_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_30_2 * 2)) & 127;
  int stride_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_82_1) & 63;
  aux_2 = (aux_2 + stride_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_30_1 == cursor_30_2);
  assert(stride_82_1 == stride_82_2);
}

int fn_R000533_3313_12(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int cursor_30 = local_arr[aux % 3];
  acc = (acc + (cursor_30 * 2)) & 127;
  int stride_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000533_3313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st_1 = {0};
  struct AudioFrame_R000533_3313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int residue_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_16_1) & 63;
  aux_2 = (aux_2 + residue_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_97_1 = local_arr_1[aux_1 % 3];
  int quantum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_97_2 * 2)) & 127;
  int window_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_95_1)
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

  switch (window_95_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_16_1 == residue_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_97_1 == quantum_97_2);
  assert(window_95_1 == window_95_2);
}

int fn_R000533_3313_13(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000533_3313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int residue_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_16) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_97 = local_arr[aux % 3];
  acc = (acc + (quantum_97 * 2)) & 127;
  int window_95 = (aux + st.buffer[1]) & 3;
  switch (window_95)
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

void fn_R000533_3313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000533_3313_0 st_1 = {0};
  struct EventLog_R000533_3313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_72_1) & 63;
  aux_2 = (aux_2 + cursor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_29_1 > 43)
  {
    acc_1 = ((acc_1 + (cursor_29_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_29_2 > 43)
  {
    acc_2 = ((acc_2 + (cursor_29_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_31_1)
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

  switch (parity_31_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_72_1 == cursor_72_2);
  assert(cursor_29_1 == cursor_29_2);
  assert(parity_31_1 == parity_31_2);
}

int fn_R000533_3313_14(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000533_3313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_72) & 63;
  acc ^= aux;
  int cursor_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_29 > 43)
  {
    acc = ((acc + (cursor_29 * 2)) + 5) & 127;
    aux ^= cursor_29 & 15;
  }
  else
  {
    acc = ((acc - cursor_29) + 11) & 127;
    aux += 3;
  }
  int parity_31 = (aux + st.buffer[1]) & 3;
  switch (parity_31)
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

void main()
{
  int sec_r000533_0_1;
  int sec_r000533_0_2;
  int sec_r000533_1_1;
  int sec_r000533_1_2;
  int sec_r000533_2_1;
  int sec_r000533_2_2;
  int sec_r000533_3_1;
  int sec_r000533_3_2;
  int sec_r000533_4_1;
  int sec_r000533_4_2;
  int sec_r000533_5_1;
  int sec_r000533_5_2;
  int sec_r000533_6_1;
  int sec_r000533_6_2;
  int sec_r000533_7_1;
  int sec_r000533_7_2;
  int sec_r000533_8_1;
  int sec_r000533_8_2;
  int sec_r000533_9_1;
  int sec_r000533_9_2;
  int sec_r000533_10_1;
  int sec_r000533_10_2;
  int sec_r000533_11_1;
  int sec_r000533_11_2;
  int sec_r000533_12_1;
  int sec_r000533_12_2;
  int sec_r000533_13_1;
  int sec_r000533_13_2;
  int sec_r000533_14_1;
  int sec_r000533_14_2;
  int sec_r000533_15_1;
  int sec_r000533_15_2;
  int sec_r000533_16_1;
  int sec_r000533_16_2;
  int sec_r000533_17_1;
  int sec_r000533_17_2;
  int sec_r000533_18_1;
  int sec_r000533_18_2;
  int sec_r000533_19_1;
  int sec_r000533_19_2;
  int sec_r000533_20_1;
  int sec_r000533_20_2;
  int sec_r000533_21_1;
  int sec_r000533_21_2;
  int pub_r000533_0_1;
  int pub_r000533_0_2;
  int pub_r000533_1_1;
  int pub_r000533_1_2;
  int pub_r000533_2_1;
  int pub_r000533_2_2;
  int pub_r000533_3_1;
  int pub_r000533_3_2;
  int pub_r000533_4_1;
  int pub_r000533_4_2;
  int pub_r000533_5_1;
  int pub_r000533_5_2;
  int pub_r000533_6_1;
  int pub_r000533_6_2;
  int pub_r000533_7_1;
  int pub_r000533_7_2;
  int pub_r000533_8_1;
  int pub_r000533_8_2;
  int pub_r000533_9_1;
  int pub_r000533_9_2;
  int pub_r000533_10_1;
  int pub_r000533_10_2;
  int pub_r000533_11_1;
  int pub_r000533_11_2;
  int pub_r000533_12_1;
  int pub_r000533_12_2;
  int pub_r000533_13_1;
  int pub_r000533_13_2;
  int pub_r000533_14_1;
  int pub_r000533_14_2;
  int pub_r000533_15_1;
  int pub_r000533_15_2;
  int pub_r000533_16_1;
  int pub_r000533_16_2;
  int pub_r000533_17_1;
  int pub_r000533_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000533_0_1 >= (-100)) && (pub_r000533_0_1 <= 100));
  __CPROVER_assume((pub_r000533_0_2 >= (-100)) && (pub_r000533_0_2 <= 100));
  __CPROVER_assume((pub_r000533_1_1 >= (-100)) && (pub_r000533_1_1 <= 100));
  __CPROVER_assume((pub_r000533_1_2 >= (-100)) && (pub_r000533_1_2 <= 100));
  __CPROVER_assume((pub_r000533_2_1 >= (-100)) && (pub_r000533_2_1 <= 100));
  __CPROVER_assume((pub_r000533_2_2 >= (-100)) && (pub_r000533_2_2 <= 100));
  __CPROVER_assume((pub_r000533_3_1 >= (-100)) && (pub_r000533_3_1 <= 100));
  __CPROVER_assume((pub_r000533_3_2 >= (-100)) && (pub_r000533_3_2 <= 100));
  __CPROVER_assume((pub_r000533_4_1 >= (-100)) && (pub_r000533_4_1 <= 100));
  __CPROVER_assume((pub_r000533_4_2 >= (-100)) && (pub_r000533_4_2 <= 100));
  __CPROVER_assume((pub_r000533_5_1 >= (-100)) && (pub_r000533_5_1 <= 100));
  __CPROVER_assume((pub_r000533_5_2 >= (-100)) && (pub_r000533_5_2 <= 100));
  __CPROVER_assume((pub_r000533_6_1 >= (-100)) && (pub_r000533_6_1 <= 100));
  __CPROVER_assume((pub_r000533_6_2 >= (-100)) && (pub_r000533_6_2 <= 100));
  __CPROVER_assume((pub_r000533_7_1 >= (-100)) && (pub_r000533_7_1 <= 100));
  __CPROVER_assume((pub_r000533_7_2 >= (-100)) && (pub_r000533_7_2 <= 100));
  __CPROVER_assume((pub_r000533_8_1 >= (-100)) && (pub_r000533_8_1 <= 100));
  __CPROVER_assume((pub_r000533_8_2 >= (-100)) && (pub_r000533_8_2 <= 100));
  __CPROVER_assume((pub_r000533_9_1 >= (-100)) && (pub_r000533_9_1 <= 100));
  __CPROVER_assume((pub_r000533_9_2 >= (-100)) && (pub_r000533_9_2 <= 100));
  __CPROVER_assume((pub_r000533_10_1 >= (-100)) && (pub_r000533_10_1 <= 100));
  __CPROVER_assume((pub_r000533_10_2 >= (-100)) && (pub_r000533_10_2 <= 100));
  __CPROVER_assume((pub_r000533_11_1 >= (-100)) && (pub_r000533_11_1 <= 100));
  __CPROVER_assume((pub_r000533_11_2 >= (-100)) && (pub_r000533_11_2 <= 100));
  __CPROVER_assume((pub_r000533_12_1 >= (-100)) && (pub_r000533_12_1 <= 100));
  __CPROVER_assume((pub_r000533_12_2 >= (-100)) && (pub_r000533_12_2 <= 100));
  __CPROVER_assume((pub_r000533_13_1 >= (-100)) && (pub_r000533_13_1 <= 100));
  __CPROVER_assume((pub_r000533_13_2 >= (-100)) && (pub_r000533_13_2 <= 100));
  __CPROVER_assume((pub_r000533_14_1 >= (-100)) && (pub_r000533_14_1 <= 100));
  __CPROVER_assume((pub_r000533_14_2 >= (-100)) && (pub_r000533_14_2 <= 100));
  __CPROVER_assume((pub_r000533_15_1 >= (-100)) && (pub_r000533_15_1 <= 100));
  __CPROVER_assume((pub_r000533_15_2 >= (-100)) && (pub_r000533_15_2 <= 100));
  __CPROVER_assume((pub_r000533_16_1 >= (-100)) && (pub_r000533_16_1 <= 100));
  __CPROVER_assume((pub_r000533_16_2 >= (-100)) && (pub_r000533_16_2 <= 100));
  __CPROVER_assume((pub_r000533_17_1 >= (-100)) && (pub_r000533_17_1 <= 100));
  __CPROVER_assume((pub_r000533_17_2 >= (-100)) && (pub_r000533_17_2 <= 100));
  __CPROVER_assume((sec_r000533_0_1 >= 0) && (sec_r000533_0_1 <= 255));
  __CPROVER_assume((sec_r000533_0_2 >= 0) && (sec_r000533_0_2 <= 255));
  __CPROVER_assume((sec_r000533_1_1 >= 0) && (sec_r000533_1_1 <= 255));
  __CPROVER_assume((sec_r000533_1_2 >= 0) && (sec_r000533_1_2 <= 255));
  __CPROVER_assume((sec_r000533_2_1 >= 0) && (sec_r000533_2_1 <= 255));
  __CPROVER_assume((sec_r000533_2_2 >= 0) && (sec_r000533_2_2 <= 255));
  __CPROVER_assume((sec_r000533_3_1 >= 0) && (sec_r000533_3_1 <= 255));
  __CPROVER_assume((sec_r000533_3_2 >= 0) && (sec_r000533_3_2 <= 255));
  __CPROVER_assume((sec_r000533_4_1 >= 0) && (sec_r000533_4_1 <= 255));
  __CPROVER_assume((sec_r000533_4_2 >= 0) && (sec_r000533_4_2 <= 255));
  __CPROVER_assume((sec_r000533_5_1 >= 0) && (sec_r000533_5_1 <= 255));
  __CPROVER_assume((sec_r000533_5_2 >= 0) && (sec_r000533_5_2 <= 255));
  __CPROVER_assume((sec_r000533_6_1 >= 0) && (sec_r000533_6_1 <= 255));
  __CPROVER_assume((sec_r000533_6_2 >= 0) && (sec_r000533_6_2 <= 255));
  __CPROVER_assume((sec_r000533_7_1 >= 0) && (sec_r000533_7_1 <= 255));
  __CPROVER_assume((sec_r000533_7_2 >= 0) && (sec_r000533_7_2 <= 255));
  __CPROVER_assume((sec_r000533_8_1 >= 0) && (sec_r000533_8_1 <= 255));
  __CPROVER_assume((sec_r000533_8_2 >= 0) && (sec_r000533_8_2 <= 255));
  __CPROVER_assume((sec_r000533_9_1 >= 0) && (sec_r000533_9_1 <= 255));
  __CPROVER_assume((sec_r000533_9_2 >= 0) && (sec_r000533_9_2 <= 255));
  __CPROVER_assume((sec_r000533_10_1 >= 0) && (sec_r000533_10_1 <= 255));
  __CPROVER_assume((sec_r000533_10_2 >= 0) && (sec_r000533_10_2 <= 255));
  __CPROVER_assume((sec_r000533_11_1 >= 0) && (sec_r000533_11_1 <= 255));
  __CPROVER_assume((sec_r000533_11_2 >= 0) && (sec_r000533_11_2 <= 255));
  __CPROVER_assume((sec_r000533_12_1 >= 0) && (sec_r000533_12_1 <= 255));
  __CPROVER_assume((sec_r000533_12_2 >= 0) && (sec_r000533_12_2 <= 255));
  __CPROVER_assume((sec_r000533_13_1 >= 0) && (sec_r000533_13_1 <= 255));
  __CPROVER_assume((sec_r000533_13_2 >= 0) && (sec_r000533_13_2 <= 255));
  __CPROVER_assume((sec_r000533_14_1 >= 0) && (sec_r000533_14_1 <= 255));
  __CPROVER_assume((sec_r000533_14_2 >= 0) && (sec_r000533_14_2 <= 255));
  __CPROVER_assume((sec_r000533_15_1 >= 0) && (sec_r000533_15_1 <= 255));
  __CPROVER_assume((sec_r000533_15_2 >= 0) && (sec_r000533_15_2 <= 255));
  __CPROVER_assume((sec_r000533_16_1 >= 0) && (sec_r000533_16_1 <= 255));
  __CPROVER_assume((sec_r000533_16_2 >= 0) && (sec_r000533_16_2 <= 255));
  __CPROVER_assume((sec_r000533_17_1 >= 0) && (sec_r000533_17_1 <= 255));
  __CPROVER_assume((sec_r000533_17_2 >= 0) && (sec_r000533_17_2 <= 255));
  __CPROVER_assume((sec_r000533_18_1 >= 0) && (sec_r000533_18_1 <= 255));
  __CPROVER_assume((sec_r000533_18_2 >= 0) && (sec_r000533_18_2 <= 255));
  __CPROVER_assume((sec_r000533_19_1 >= 0) && (sec_r000533_19_1 <= 255));
  __CPROVER_assume((sec_r000533_19_2 >= 0) && (sec_r000533_19_2 <= 255));
  __CPROVER_assume((sec_r000533_20_1 >= 0) && (sec_r000533_20_1 <= 255));
  __CPROVER_assume((sec_r000533_20_2 >= 0) && (sec_r000533_20_2 <= 255));
  __CPROVER_assume((sec_r000533_21_1 >= 0) && (sec_r000533_21_1 <= 255));
  __CPROVER_assume((sec_r000533_21_2 >= 0) && (sec_r000533_21_2 <= 255));
  struct EventLog_R000533_3313_0 st_var_0_1 = {0};
  struct EventLog_R000533_3313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000533_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000533_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000533_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000533_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000533_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000533_0_2 + 7) & 15;
  struct AudioFrame_R000533_3313_1 st_var_1_1 = {0};
  struct AudioFrame_R000533_3313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000533_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000533_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000533_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000533_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000533_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000533_0_2 + 9) & 15;
  struct MatrixBlock_R000533_3313_2 st_var_2_1 = {0};
  struct MatrixBlock_R000533_3313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000533_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000533_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000533_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000533_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000533_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000533_0_2 + 11) & 15;
  union TelemetryField_R000533_3313_0 u_var_1;
  union TelemetryField_R000533_3313_0 u_var_2;
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
  int stage_v_1_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (6 & 31);
  int stage_v_1_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (6 & 31);
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= (stage_v_1_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_1_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 3) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = (st_var_1_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_1_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int sub_step_7_1 = ((sec_r000533_18_1 + pub_r000533_13_1) + 29) & 127;
  int sub_step_7_2 = ((sec_r000533_18_2 + pub_r000533_13_2) + 29) & 127;
  int stage_v_7_1 = ((sub_step_7_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_7_2 = ((sub_step_7_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_7_1 & 15;
  st_var_1_2.buffer[1] = stage_v_7_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int sub_step_8_1 = ((sec_r000533_17_1 + pub_r000533_16_1) + 35) & 127;
  int sub_step_8_2 = ((sec_r000533_17_2 + pub_r000533_16_2) + 35) & 127;
  int stage_v_8_1 = ((sub_step_8_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_8_2 = ((sub_step_8_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_8_1 & 15;
  st_var_2_2.buffer[2] = stage_v_8_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int sub_step_9_1 = ((stage_v_7_1 + pub_r000533_12_1) + 17) & 127;
  int sub_step_9_2 = ((stage_v_7_2 + pub_r000533_12_2) + 17) & 127;
  int stage_v_9_1 = ((sub_step_9_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_9_2 = ((sub_step_9_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_9_1 & 15;
  st_var_0_2.buffer[0] = stage_v_9_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int sub_step_10_1 = ((stage_v_9_1 + pub_r000533_9_1) + 7) & 127;
  int sub_step_10_2 = ((stage_v_9_2 + pub_r000533_9_2) + 7) & 127;
  int stage_v_10_1 = ((sub_step_10_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_10_2 = ((sub_step_10_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_10_1 & 15;
  st_var_1_2.buffer[1] = stage_v_10_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int sub_step_11_1 = ((sec_r000533_7_1 + pub_r000533_11_1) + 26) & 127;
  int sub_step_11_2 = ((sec_r000533_7_2 + pub_r000533_11_2) + 26) & 127;
  int stage_v_11_1 = ((sub_step_11_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_11_2 = ((sub_step_11_2 * 2) + pub_r000533_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_11_1 & 15;
  st_var_2_2.buffer[2] = stage_v_11_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int sub_step_12_1 = ((sub_step_10_1 + pub_r000533_16_1) + 31) & 127;
  int sub_step_12_2 = ((sub_step_10_2 + pub_r000533_16_2) + 31) & 127;
  int stage_v_12_1 = ((sub_step_12_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_12_2 = ((sub_step_12_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_12_1 & 15;
  st_var_0_2.buffer[0] = stage_v_12_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int sub_step_13_1 = ((sec_r000533_14_1 + pub_r000533_16_1) + 17) & 127;
  int sub_step_13_2 = ((sec_r000533_14_2 + pub_r000533_16_2) + 17) & 127;
  int stage_v_13_1 = ((sub_step_13_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_13_2 = ((sub_step_13_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_13_1 & 15;
  st_var_1_2.buffer[1] = stage_v_13_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int sub_step_14_1 = ((sec_r000533_16_1 + pub_r000533_9_1) + 15) & 127;
  int sub_step_14_2 = ((sec_r000533_16_2 + pub_r000533_9_2) + 15) & 127;
  int stage_v_14_1 = ((sub_step_14_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_14_2 = ((sub_step_14_2 * 2) + pub_r000533_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_14_1 & 15;
  st_var_2_2.buffer[2] = stage_v_14_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int sub_step_15_1 = ((sec_r000533_17_1 + pub_r000533_12_1) + 8) & 127;
  int sub_step_15_2 = ((sec_r000533_17_2 + pub_r000533_12_2) + 8) & 127;
  int stage_v_15_1 = ((sub_step_15_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_15_2 = ((sub_step_15_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_15_1 & 15;
  st_var_0_2.buffer[0] = stage_v_15_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int sub_step_16_1 = ((stage_v_14_1 + pub_r000533_1_1) + 33) & 127;
  int sub_step_16_2 = ((stage_v_14_2 + pub_r000533_1_2) + 33) & 127;
  int stage_v_16_1 = ((sub_step_16_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_16_2 = ((sub_step_16_2 * 2) + pub_r000533_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_16_1 & 15;
  st_var_1_2.buffer[1] = stage_v_16_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int sub_step_17_1 = ((sub_step_12_1 + pub_r000533_6_1) + 5) & 127;
  int sub_step_17_2 = ((sub_step_12_2 + pub_r000533_6_2) + 5) & 127;
  int stage_v_17_1 = ((sub_step_17_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_17_2 = ((sub_step_17_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_17_1 & 15;
  st_var_2_2.buffer[2] = stage_v_17_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int sub_step_18_1 = ((stage_v_12_1 + pub_r000533_5_1) + 13) & 127;
  int sub_step_18_2 = ((stage_v_12_2 + pub_r000533_5_2) + 13) & 127;
  int stage_v_18_1 = ((sub_step_18_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_18_2 = ((sub_step_18_2 * 2) + pub_r000533_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_18_1 & 15;
  st_var_0_2.buffer[0] = stage_v_18_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  int sub_step_19_1 = ((stage_v_9_1 + pub_r000533_13_1) + 19) & 127;
  int sub_step_19_2 = ((stage_v_9_2 + pub_r000533_13_2) + 19) & 127;
  int stage_v_19_1 = ((sub_step_19_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_19_2 = ((sub_step_19_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_19_1 & 15;
  st_var_1_2.buffer[1] = stage_v_19_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int sub_step_20_1 = ((sub_step_17_1 + pub_r000533_11_1) + 10) & 127;
  int sub_step_20_2 = ((sub_step_17_2 + pub_r000533_11_2) + 10) & 127;
  int stage_v_20_1 = ((sub_step_20_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_20_2 = ((sub_step_20_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_20_1 & 15;
  st_var_2_2.buffer[2] = stage_v_20_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int sub_step_21_1 = ((stage_v_10_1 + pub_r000533_15_1) + 7) & 127;
  int sub_step_21_2 = ((stage_v_10_2 + pub_r000533_15_2) + 7) & 127;
  int stage_v_21_1 = ((sub_step_21_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_21_2 = ((sub_step_21_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_21_1 & 15;
  st_var_0_2.buffer[0] = stage_v_21_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int sub_step_22_1 = ((sub_step_18_1 + pub_r000533_2_1) + 9) & 127;
  int sub_step_22_2 = ((sub_step_18_2 + pub_r000533_2_2) + 9) & 127;
  int stage_v_22_1 = ((sub_step_22_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_22_2 = ((sub_step_22_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_22_1 & 15;
  st_var_1_2.buffer[1] = stage_v_22_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int sub_step_23_1 = ((sub_step_19_1 + pub_r000533_12_1) + 11) & 127;
  int sub_step_23_2 = ((sub_step_19_2 + pub_r000533_12_2) + 11) & 127;
  int stage_v_23_1 = ((sub_step_23_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_23_2 = ((sub_step_23_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_23_1 & 15;
  st_var_2_2.buffer[2] = stage_v_23_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int sub_step_24_1 = ((sec_r000533_0_1 + pub_r000533_11_1) + 13) & 127;
  int sub_step_24_2 = ((sec_r000533_0_2 + pub_r000533_11_2) + 13) & 127;
  int stage_v_24_1 = ((sub_step_24_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_24_2 = ((sub_step_24_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_24_1 & 15;
  st_var_0_2.buffer[0] = stage_v_24_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int sub_step_25_1 = ((sub_step_10_1 + pub_r000533_5_1) + 11) & 127;
  int sub_step_25_2 = ((sub_step_10_2 + pub_r000533_5_2) + 11) & 127;
  int stage_v_25_1 = ((sub_step_25_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_25_2 = ((sub_step_25_2 * 2) + pub_r000533_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_25_1 & 15;
  st_var_1_2.buffer[1] = stage_v_25_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int sub_step_26_1 = ((sub_step_17_1 + pub_r000533_9_1) + 28) & 127;
  int sub_step_26_2 = ((sub_step_17_2 + pub_r000533_9_2) + 28) & 127;
  int stage_v_26_1 = ((sub_step_26_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_26_2 = ((sub_step_26_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_26_1 & 15;
  st_var_2_2.buffer[2] = stage_v_26_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int sub_step_27_1 = ((sub_step_12_1 + pub_r000533_7_1) + 26) & 127;
  int sub_step_27_2 = ((sub_step_12_2 + pub_r000533_7_2) + 26) & 127;
  int stage_v_27_1 = ((sub_step_27_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_27_2 = ((sub_step_27_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_27_1 & 15;
  st_var_0_2.buffer[0] = stage_v_27_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  int sub_step_28_1 = ((sec_r000533_12_1 + pub_r000533_15_1) + 19) & 127;
  int sub_step_28_2 = ((sec_r000533_12_2 + pub_r000533_15_2) + 19) & 127;
  int stage_v_28_1 = ((sub_step_28_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_28_2 = ((sub_step_28_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_28_1 & 15;
  st_var_1_2.buffer[1] = stage_v_28_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int sub_step_29_1 = ((sub_step_22_1 + pub_r000533_9_1) + 21) & 127;
  int sub_step_29_2 = ((sub_step_22_2 + pub_r000533_9_2) + 21) & 127;
  int stage_v_29_1 = ((sub_step_29_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_29_2 = ((sub_step_29_2 * 2) + pub_r000533_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_29_1 & 15;
  st_var_2_2.buffer[2] = stage_v_29_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  int sub_step_30_1 = ((stage_v_24_1 + pub_r000533_0_1) + 7) & 127;
  int sub_step_30_2 = ((stage_v_24_2 + pub_r000533_0_2) + 7) & 127;
  int stage_v_30_1 = ((sub_step_30_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_30_2 = ((sub_step_30_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_30_1 & 15;
  st_var_0_2.buffer[0] = stage_v_30_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int sub_step_31_1 = ((sec_r000533_15_1 + pub_r000533_4_1) + 29) & 127;
  int sub_step_31_2 = ((sec_r000533_15_2 + pub_r000533_4_2) + 29) & 127;
  int stage_v_31_1 = ((sub_step_31_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_31_2 = ((sub_step_31_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_31_1 & 15;
  st_var_1_2.buffer[1] = stage_v_31_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int sub_step_32_1 = ((sub_step_22_1 + pub_r000533_12_1) + 16) & 127;
  int sub_step_32_2 = ((sub_step_22_2 + pub_r000533_12_2) + 16) & 127;
  int stage_v_32_1 = ((sub_step_32_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_32_2 = ((sub_step_32_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_32_1 & 15;
  st_var_2_2.buffer[2] = stage_v_32_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int sub_step_33_1 = ((stage_v_28_1 + pub_r000533_12_1) + 14) & 127;
  int sub_step_33_2 = ((stage_v_28_2 + pub_r000533_12_2) + 14) & 127;
  int stage_v_33_1 = ((sub_step_33_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_33_2 = ((sub_step_33_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_33_1 & 15;
  st_var_0_2.buffer[0] = stage_v_33_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int sub_step_34_1 = ((sub_step_29_1 + pub_r000533_6_1) + 26) & 127;
  int sub_step_34_2 = ((sub_step_29_2 + pub_r000533_6_2) + 26) & 127;
  int stage_v_34_1 = ((sub_step_34_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_34_2 = ((sub_step_34_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_34_1 & 15;
  st_var_1_2.buffer[1] = stage_v_34_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int sub_step_35_1 = ((stage_v_30_1 + pub_r000533_5_1) + 9) & 127;
  int sub_step_35_2 = ((stage_v_30_2 + pub_r000533_5_2) + 9) & 127;
  int stage_v_35_1 = ((sub_step_35_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_35_2 = ((sub_step_35_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_35_1 & 15;
  st_var_2_2.buffer[2] = stage_v_35_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int sub_step_36_1 = ((sub_step_19_1 + pub_r000533_13_1) + 33) & 127;
  int sub_step_36_2 = ((sub_step_19_2 + pub_r000533_13_2) + 33) & 127;
  int stage_v_36_1 = ((sub_step_36_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_36_2 = ((sub_step_36_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_36_1 & 15;
  st_var_0_2.buffer[0] = stage_v_36_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int sub_step_37_1 = ((sec_r000533_5_1 + pub_r000533_1_1) + 28) & 127;
  int sub_step_37_2 = ((sec_r000533_5_2 + pub_r000533_1_2) + 28) & 127;
  int stage_v_37_1 = ((sub_step_37_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_37_2 = ((sub_step_37_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_37_1 & 15;
  st_var_1_2.buffer[1] = stage_v_37_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int sub_step_38_1 = ((sec_r000533_0_1 + pub_r000533_8_1) + 29) & 127;
  int sub_step_38_2 = ((sec_r000533_0_2 + pub_r000533_8_2) + 29) & 127;
  int stage_v_38_1 = ((sub_step_38_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_38_2 = ((sub_step_38_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_38_1 & 15;
  st_var_2_2.buffer[2] = stage_v_38_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int sub_step_39_1 = ((sub_step_36_1 + pub_r000533_17_1) + 34) & 127;
  int sub_step_39_2 = ((sub_step_36_2 + pub_r000533_17_2) + 34) & 127;
  int stage_v_39_1 = ((sub_step_39_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_39_2 = ((sub_step_39_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_39_1 & 15;
  st_var_0_2.buffer[0] = stage_v_39_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int sub_step_40_1 = ((stage_v_22_1 + pub_r000533_5_1) + 33) & 127;
  int sub_step_40_2 = ((stage_v_22_2 + pub_r000533_5_2) + 33) & 127;
  int stage_v_40_1 = ((sub_step_40_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_40_2 = ((sub_step_40_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_40_1 & 15;
  st_var_1_2.buffer[1] = stage_v_40_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int sub_step_41_1 = ((sub_step_40_1 + pub_r000533_9_1) + 9) & 127;
  int sub_step_41_2 = ((sub_step_40_2 + pub_r000533_9_2) + 9) & 127;
  int stage_v_41_1 = ((sub_step_41_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_41_2 = ((sub_step_41_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_41_1 & 15;
  st_var_2_2.buffer[2] = stage_v_41_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int sub_step_42_1 = ((stage_v_9_1 + pub_r000533_5_1) + 20) & 127;
  int sub_step_42_2 = ((stage_v_9_2 + pub_r000533_5_2) + 20) & 127;
  int stage_v_42_1 = ((sub_step_42_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_42_2 = ((sub_step_42_2 * 2) + pub_r000533_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_42_1 & 15;
  st_var_0_2.buffer[0] = stage_v_42_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int sub_step_43_1 = ((sec_r000533_2_1 + pub_r000533_5_1) + 9) & 127;
  int sub_step_43_2 = ((sec_r000533_2_2 + pub_r000533_5_2) + 9) & 127;
  int stage_v_43_1 = ((sub_step_43_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_43_2 = ((sub_step_43_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_43_1 & 15;
  st_var_1_2.buffer[1] = stage_v_43_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int sub_step_44_1 = ((sec_r000533_4_1 + pub_r000533_3_1) + 25) & 127;
  int sub_step_44_2 = ((sec_r000533_4_2 + pub_r000533_3_2) + 25) & 127;
  int stage_v_44_1 = ((sub_step_44_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_44_2 = ((sub_step_44_2 * 2) + pub_r000533_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_44_1 & 15;
  st_var_2_2.buffer[2] = stage_v_44_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int sub_step_45_1 = ((stage_v_17_1 + pub_r000533_6_1) + 6) & 127;
  int sub_step_45_2 = ((stage_v_17_2 + pub_r000533_6_2) + 6) & 127;
  int stage_v_45_1 = ((sub_step_45_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_45_2 = ((sub_step_45_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_45_1 & 15;
  st_var_0_2.buffer[0] = stage_v_45_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  int sub_step_46_1 = ((stage_v_16_1 + pub_r000533_14_1) + 24) & 127;
  int sub_step_46_2 = ((stage_v_16_2 + pub_r000533_14_2) + 24) & 127;
  int stage_v_46_1 = ((sub_step_46_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_46_2 = ((sub_step_46_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_46_1 & 15;
  st_var_1_2.buffer[1] = stage_v_46_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int sub_step_47_1 = ((sec_r000533_7_1 + pub_r000533_5_1) + 30) & 127;
  int sub_step_47_2 = ((sec_r000533_7_2 + pub_r000533_5_2) + 30) & 127;
  int stage_v_47_1 = ((sub_step_47_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_47_2 = ((sub_step_47_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_47_1 & 15;
  st_var_2_2.buffer[2] = stage_v_47_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int sub_step_48_1 = ((stage_v_19_1 + pub_r000533_0_1) + 9) & 127;
  int sub_step_48_2 = ((stage_v_19_2 + pub_r000533_0_2) + 9) & 127;
  int stage_v_48_1 = ((sub_step_48_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_48_2 = ((sub_step_48_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_48_1 & 15;
  st_var_0_2.buffer[0] = stage_v_48_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int sub_step_49_1 = ((sec_r000533_11_1 + pub_r000533_8_1) + 13) & 127;
  int sub_step_49_2 = ((sec_r000533_11_2 + pub_r000533_8_2) + 13) & 127;
  int stage_v_49_1 = ((sub_step_49_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_49_2 = ((sub_step_49_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_49_1 & 15;
  st_var_1_2.buffer[1] = stage_v_49_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int sub_step_50_1 = ((sub_step_7_1 + pub_r000533_8_1) + 5) & 127;
  int sub_step_50_2 = ((sub_step_7_2 + pub_r000533_8_2) + 5) & 127;
  int stage_v_50_1 = ((sub_step_50_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_50_2 = ((sub_step_50_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_50_1 & 15;
  st_var_2_2.buffer[2] = stage_v_50_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int sub_step_51_1 = ((sub_step_22_1 + pub_r000533_17_1) + 33) & 127;
  int sub_step_51_2 = ((sub_step_22_2 + pub_r000533_17_2) + 33) & 127;
  int stage_v_51_1 = ((sub_step_51_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_51_2 = ((sub_step_51_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_51_1 & 15;
  st_var_0_2.buffer[0] = stage_v_51_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int sub_step_52_1 = ((sec_r000533_20_1 + pub_r000533_14_1) + 16) & 127;
  int sub_step_52_2 = ((sec_r000533_20_2 + pub_r000533_14_2) + 16) & 127;
  int stage_v_52_1 = ((sub_step_52_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_52_2 = ((sub_step_52_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_52_1 & 15;
  st_var_1_2.buffer[1] = stage_v_52_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int sub_step_53_1 = ((sub_step_32_1 + pub_r000533_17_1) + 5) & 127;
  int sub_step_53_2 = ((sub_step_32_2 + pub_r000533_17_2) + 5) & 127;
  int stage_v_53_1 = ((sub_step_53_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_53_2 = ((sub_step_53_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_53_1 & 15;
  st_var_2_2.buffer[2] = stage_v_53_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  int sub_step_54_1 = ((sub_step_38_1 + pub_r000533_16_1) + 6) & 127;
  int sub_step_54_2 = ((sub_step_38_2 + pub_r000533_16_2) + 6) & 127;
  int stage_v_54_1 = ((sub_step_54_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_54_2 = ((sub_step_54_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_54_1 & 15;
  st_var_0_2.buffer[0] = stage_v_54_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int sub_step_55_1 = ((stage_v_45_1 + pub_r000533_9_1) + 29) & 127;
  int sub_step_55_2 = ((stage_v_45_2 + pub_r000533_9_2) + 29) & 127;
  int stage_v_55_1 = ((sub_step_55_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_55_2 = ((sub_step_55_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_55_1 & 15;
  st_var_1_2.buffer[1] = stage_v_55_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int sub_step_56_1 = ((sub_step_53_1 + pub_r000533_13_1) + 20) & 127;
  int sub_step_56_2 = ((sub_step_53_2 + pub_r000533_13_2) + 20) & 127;
  int stage_v_56_1 = ((sub_step_56_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_56_2 = ((sub_step_56_2 * 2) + pub_r000533_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_56_1 & 15;
  st_var_2_2.buffer[2] = stage_v_56_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int sub_step_57_1 = ((sec_r000533_16_1 + pub_r000533_12_1) + 25) & 127;
  int sub_step_57_2 = ((sec_r000533_16_2 + pub_r000533_12_2) + 25) & 127;
  int stage_v_57_1 = ((sub_step_57_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_57_2 = ((sub_step_57_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_57_1 & 15;
  st_var_0_2.buffer[0] = stage_v_57_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int sub_step_58_1 = ((sub_step_18_1 + pub_r000533_0_1) + 35) & 127;
  int sub_step_58_2 = ((sub_step_18_2 + pub_r000533_0_2) + 35) & 127;
  int stage_v_58_1 = ((sub_step_58_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_58_2 = ((sub_step_58_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_58_1 & 15;
  st_var_1_2.buffer[1] = stage_v_58_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int sub_step_59_1 = ((sec_r000533_18_1 + pub_r000533_7_1) + 33) & 127;
  int sub_step_59_2 = ((sec_r000533_18_2 + pub_r000533_7_2) + 33) & 127;
  int stage_v_59_1 = ((sub_step_59_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_59_2 = ((sub_step_59_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_59_1 & 15;
  st_var_2_2.buffer[2] = stage_v_59_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int sub_step_60_1 = ((sub_step_23_1 + pub_r000533_0_1) + 25) & 127;
  int sub_step_60_2 = ((sub_step_23_2 + pub_r000533_0_2) + 25) & 127;
  int stage_v_60_1 = ((sub_step_60_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_60_2 = ((sub_step_60_2 * 2) + pub_r000533_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_60_1 & 15;
  st_var_0_2.buffer[0] = stage_v_60_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int sub_step_61_1 = ((sub_step_58_1 + pub_r000533_12_1) + 14) & 127;
  int sub_step_61_2 = ((sub_step_58_2 + pub_r000533_12_2) + 14) & 127;
  int stage_v_61_1 = ((sub_step_61_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_61_2 = ((sub_step_61_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_61_1 & 15;
  st_var_1_2.buffer[1] = stage_v_61_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int sub_step_62_1 = ((sub_step_31_1 + pub_r000533_12_1) + 5) & 127;
  int sub_step_62_2 = ((sub_step_31_2 + pub_r000533_12_2) + 5) & 127;
  int stage_v_62_1 = ((sub_step_62_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_62_2 = ((sub_step_62_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_62_1 & 15;
  st_var_2_2.buffer[2] = stage_v_62_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int sub_step_63_1 = ((sub_step_30_1 + pub_r000533_16_1) + 33) & 127;
  int sub_step_63_2 = ((sub_step_30_2 + pub_r000533_16_2) + 33) & 127;
  int stage_v_63_1 = ((sub_step_63_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_63_2 = ((sub_step_63_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_63_1 & 15;
  st_var_0_2.buffer[0] = stage_v_63_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int sub_step_64_1 = ((sec_r000533_6_1 + pub_r000533_15_1) + 32) & 127;
  int sub_step_64_2 = ((sec_r000533_6_2 + pub_r000533_15_2) + 32) & 127;
  int stage_v_64_1 = ((sub_step_64_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_64_2 = ((sub_step_64_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_64_1 & 15;
  st_var_1_2.buffer[1] = stage_v_64_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int sub_step_65_1 = ((sub_step_16_1 + pub_r000533_17_1) + 18) & 127;
  int sub_step_65_2 = ((sub_step_16_2 + pub_r000533_17_2) + 18) & 127;
  int stage_v_65_1 = ((sub_step_65_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_65_2 = ((sub_step_65_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_65_1 & 15;
  st_var_2_2.buffer[2] = stage_v_65_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int sub_step_66_1 = ((sub_step_31_1 + pub_r000533_4_1) + 7) & 127;
  int sub_step_66_2 = ((sub_step_31_2 + pub_r000533_4_2) + 7) & 127;
  int stage_v_66_1 = ((sub_step_66_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_66_2 = ((sub_step_66_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_66_1 & 15;
  st_var_0_2.buffer[0] = stage_v_66_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int sub_step_67_1 = ((sub_step_24_1 + pub_r000533_10_1) + 17) & 127;
  int sub_step_67_2 = ((sub_step_24_2 + pub_r000533_10_2) + 17) & 127;
  int stage_v_67_1 = ((sub_step_67_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_67_2 = ((sub_step_67_2 * 2) + pub_r000533_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_67_1 & 15;
  st_var_1_2.buffer[1] = stage_v_67_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int sub_step_68_1 = ((stage_v_65_1 + pub_r000533_10_1) + 5) & 127;
  int sub_step_68_2 = ((stage_v_65_2 + pub_r000533_10_2) + 5) & 127;
  int stage_v_68_1 = ((sub_step_68_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_68_2 = ((sub_step_68_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_68_1 & 15;
  st_var_2_2.buffer[2] = stage_v_68_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  int sub_step_69_1 = ((sec_r000533_0_1 + pub_r000533_11_1) + 18) & 127;
  int sub_step_69_2 = ((sec_r000533_0_2 + pub_r000533_11_2) + 18) & 127;
  int stage_v_69_1 = ((sub_step_69_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_69_2 = ((sub_step_69_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_69_1 & 15;
  st_var_0_2.buffer[0] = stage_v_69_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int sub_step_70_1 = ((sub_step_35_1 + pub_r000533_16_1) + 35) & 127;
  int sub_step_70_2 = ((sub_step_35_2 + pub_r000533_16_2) + 35) & 127;
  int stage_v_70_1 = ((sub_step_70_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_70_2 = ((sub_step_70_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_70_1 & 15;
  st_var_1_2.buffer[1] = stage_v_70_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int sub_step_71_1 = ((stage_v_34_1 + pub_r000533_11_1) + 15) & 127;
  int sub_step_71_2 = ((stage_v_34_2 + pub_r000533_11_2) + 15) & 127;
  int stage_v_71_1 = ((sub_step_71_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_71_2 = ((sub_step_71_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_71_1 & 15;
  st_var_2_2.buffer[2] = stage_v_71_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int sub_step_72_1 = ((sub_step_35_1 + pub_r000533_9_1) + 31) & 127;
  int sub_step_72_2 = ((sub_step_35_2 + pub_r000533_9_2) + 31) & 127;
  int stage_v_72_1 = ((sub_step_72_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_72_2 = ((sub_step_72_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_72_1 & 15;
  st_var_0_2.buffer[0] = stage_v_72_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int sub_step_73_1 = ((sub_step_66_1 + pub_r000533_1_1) + 33) & 127;
  int sub_step_73_2 = ((sub_step_66_2 + pub_r000533_1_2) + 33) & 127;
  int stage_v_73_1 = ((sub_step_73_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_73_2 = ((sub_step_73_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_73_1 & 15;
  st_var_1_2.buffer[1] = stage_v_73_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int sub_step_74_1 = ((stage_v_64_1 + pub_r000533_17_1) + 31) & 127;
  int sub_step_74_2 = ((stage_v_64_2 + pub_r000533_17_2) + 31) & 127;
  int stage_v_74_1 = ((sub_step_74_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_74_2 = ((sub_step_74_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_74_1 & 15;
  st_var_2_2.buffer[2] = stage_v_74_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  int sub_step_75_1 = ((sec_r000533_17_1 + pub_r000533_2_1) + 31) & 127;
  int sub_step_75_2 = ((sec_r000533_17_2 + pub_r000533_2_2) + 31) & 127;
  int stage_v_75_1 = ((sub_step_75_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_75_2 = ((sub_step_75_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_75_1 & 15;
  st_var_0_2.buffer[0] = stage_v_75_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int sub_step_76_1 = ((sub_step_15_1 + pub_r000533_15_1) + 18) & 127;
  int sub_step_76_2 = ((sub_step_15_2 + pub_r000533_15_2) + 18) & 127;
  int stage_v_76_1 = ((sub_step_76_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_76_2 = ((sub_step_76_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_76_1 & 15;
  st_var_1_2.buffer[1] = stage_v_76_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int sub_step_77_1 = ((stage_v_18_1 + pub_r000533_9_1) + 9) & 127;
  int sub_step_77_2 = ((stage_v_18_2 + pub_r000533_9_2) + 9) & 127;
  int stage_v_77_1 = ((sub_step_77_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_77_2 = ((sub_step_77_2 * 2) + pub_r000533_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_77_1 & 15;
  st_var_2_2.buffer[2] = stage_v_77_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int sub_step_78_1 = ((sub_step_7_1 + pub_r000533_10_1) + 6) & 127;
  int sub_step_78_2 = ((sub_step_7_2 + pub_r000533_10_2) + 6) & 127;
  int stage_v_78_1 = ((sub_step_78_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_78_2 = ((sub_step_78_2 * 2) + pub_r000533_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_78_1 & 15;
  st_var_0_2.buffer[0] = stage_v_78_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int sub_step_79_1 = ((stage_v_22_1 + pub_r000533_11_1) + 14) & 127;
  int sub_step_79_2 = ((stage_v_22_2 + pub_r000533_11_2) + 14) & 127;
  int stage_v_79_1 = ((sub_step_79_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_79_2 = ((sub_step_79_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_79_1 & 15;
  st_var_1_2.buffer[1] = stage_v_79_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int sub_step_80_1 = ((sec_r000533_1_1 + pub_r000533_5_1) + 20) & 127;
  int sub_step_80_2 = ((sec_r000533_1_2 + pub_r000533_5_2) + 20) & 127;
  int stage_v_80_1 = ((sub_step_80_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_80_2 = ((sub_step_80_2 * 2) + pub_r000533_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_80_1 & 15;
  st_var_2_2.buffer[2] = stage_v_80_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int sub_step_81_1 = ((sub_step_11_1 + pub_r000533_9_1) + 9) & 127;
  int sub_step_81_2 = ((sub_step_11_2 + pub_r000533_9_2) + 9) & 127;
  int stage_v_81_1 = ((sub_step_81_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_81_2 = ((sub_step_81_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_81_1 & 15;
  st_var_0_2.buffer[0] = stage_v_81_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int sub_step_82_1 = ((sec_r000533_2_1 + pub_r000533_17_1) + 21) & 127;
  int sub_step_82_2 = ((sec_r000533_2_2 + pub_r000533_17_2) + 21) & 127;
  int stage_v_82_1 = ((sub_step_82_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_82_2 = ((sub_step_82_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_82_1 & 15;
  st_var_1_2.buffer[1] = stage_v_82_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int sub_step_83_1 = ((stage_v_56_1 + pub_r000533_2_1) + 35) & 127;
  int sub_step_83_2 = ((stage_v_56_2 + pub_r000533_2_2) + 35) & 127;
  int stage_v_83_1 = ((sub_step_83_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_83_2 = ((sub_step_83_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_83_1 & 15;
  st_var_2_2.buffer[2] = stage_v_83_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int sub_step_84_1 = ((sub_step_67_1 + pub_r000533_15_1) + 23) & 127;
  int sub_step_84_2 = ((sub_step_67_2 + pub_r000533_15_2) + 23) & 127;
  int stage_v_84_1 = ((sub_step_84_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_84_2 = ((sub_step_84_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_84_1 & 15;
  st_var_0_2.buffer[0] = stage_v_84_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int sub_step_85_1 = ((sub_step_51_1 + pub_r000533_7_1) + 23) & 127;
  int sub_step_85_2 = ((sub_step_51_2 + pub_r000533_7_2) + 23) & 127;
  int stage_v_85_1 = ((sub_step_85_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_85_2 = ((sub_step_85_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_85_1 & 15;
  st_var_1_2.buffer[1] = stage_v_85_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int sub_step_86_1 = ((sub_step_80_1 + pub_r000533_15_1) + 10) & 127;
  int sub_step_86_2 = ((sub_step_80_2 + pub_r000533_15_2) + 10) & 127;
  int stage_v_86_1 = ((sub_step_86_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_86_2 = ((sub_step_86_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_86_1 & 15;
  st_var_2_2.buffer[2] = stage_v_86_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int sub_step_87_1 = ((stage_v_68_1 + pub_r000533_3_1) + 23) & 127;
  int sub_step_87_2 = ((stage_v_68_2 + pub_r000533_3_2) + 23) & 127;
  int stage_v_87_1 = ((sub_step_87_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_87_2 = ((sub_step_87_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_87_1 & 15;
  st_var_0_2.buffer[0] = stage_v_87_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int sub_step_88_1 = ((sub_step_28_1 + pub_r000533_13_1) + 14) & 127;
  int sub_step_88_2 = ((sub_step_28_2 + pub_r000533_13_2) + 14) & 127;
  int stage_v_88_1 = ((sub_step_88_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_88_2 = ((sub_step_88_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_88_1 & 15;
  st_var_1_2.buffer[1] = stage_v_88_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int sub_step_89_1 = ((sec_r000533_15_1 + pub_r000533_7_1) + 5) & 127;
  int sub_step_89_2 = ((sec_r000533_15_2 + pub_r000533_7_2) + 5) & 127;
  int stage_v_89_1 = ((sub_step_89_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_89_2 = ((sub_step_89_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_89_1 & 15;
  st_var_2_2.buffer[2] = stage_v_89_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int sub_step_90_1 = ((sub_step_41_1 + pub_r000533_8_1) + 22) & 127;
  int sub_step_90_2 = ((sub_step_41_2 + pub_r000533_8_2) + 22) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_90_1 & 15;
  st_var_0_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((stage_v_32_1 + pub_r000533_14_1) + 12) & 127;
  int sub_step_91_2 = ((stage_v_32_2 + pub_r000533_14_2) + 12) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000533_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_91_1 & 15;
  st_var_1_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((stage_v_41_1 + pub_r000533_7_1) + 6) & 127;
  int sub_step_92_2 = ((stage_v_41_2 + pub_r000533_7_2) + 6) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000533_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_92_1 & 15;
  st_var_2_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((sub_step_84_1 + pub_r000533_12_1) + 11) & 127;
  int sub_step_93_2 = ((sub_step_84_2 + pub_r000533_12_2) + 11) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000533_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_93_1 & 15;
  st_var_0_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_10_1 + pub_r000533_10_1) + 11) & 127;
  int sub_step_94_2 = ((stage_v_10_2 + pub_r000533_10_2) + 11) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_94_1 & 15;
  st_var_1_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sub_step_39_1 + pub_r000533_1_1) + 20) & 127;
  int sub_step_95_2 = ((sub_step_39_2 + pub_r000533_1_2) + 20) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000533_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_95_1 & 15;
  st_var_2_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((stage_v_49_1 + pub_r000533_8_1) + 8) & 127;
  int sub_step_96_2 = ((stage_v_49_2 + pub_r000533_8_2) + 8) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000533_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sec_r000533_19_1 + pub_r000533_11_1) + 32) & 127;
  int sub_step_97_2 = ((sec_r000533_19_2 + pub_r000533_11_2) + 32) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sec_r000533_9_1 + pub_r000533_14_1) + 7) & 127;
  int sub_step_98_2 = ((sec_r000533_9_2 + pub_r000533_14_2) + 7) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((sec_r000533_8_1 + pub_r000533_8_1) + 30) & 127;
  int sub_step_99_2 = ((sec_r000533_8_2 + pub_r000533_8_2) + 30) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000533_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_99_1 & 15;
  st_var_0_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((sec_r000533_2_1 + pub_r000533_13_1) + 6) & 127;
  int sub_step_100_2 = ((sec_r000533_2_2 + pub_r000533_13_2) + 6) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_100_1 & 15;
  st_var_1_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((sub_step_29_1 + pub_r000533_15_1) + 18) & 127;
  int sub_step_101_2 = ((sub_step_29_2 + pub_r000533_15_2) + 18) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000533_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_101_1 & 15;
  st_var_2_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((stage_v_66_1 + pub_r000533_2_1) + 19) & 127;
  int sub_step_102_2 = ((stage_v_66_2 + pub_r000533_2_2) + 19) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000533_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_102_1 & 15;
  st_var_0_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((stage_v_56_1 + pub_r000533_1_1) + 32) & 127;
  int sub_step_103_2 = ((stage_v_56_2 + pub_r000533_1_2) + 32) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_103_1 & 15;
  st_var_1_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((stage_v_10_1 + pub_r000533_11_1) + 34) & 127;
  int sub_step_104_2 = ((stage_v_10_2 + pub_r000533_11_2) + 34) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_104_1 & 15;
  st_var_2_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sub_step_88_1 + pub_r000533_0_1) + 24) & 127;
  int sub_step_105_2 = ((sub_step_88_2 + pub_r000533_0_2) + 24) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_105_1 & 15;
  st_var_0_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((sub_step_33_1 + pub_r000533_15_1) + 26) & 127;
  int sub_step_106_2 = ((sub_step_33_2 + pub_r000533_15_2) + 26) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000533_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_106_1 & 15;
  st_var_1_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((stage_v_52_1 + pub_r000533_2_1) + 6) & 127;
  int sub_step_107_2 = ((stage_v_52_2 + pub_r000533_2_2) + 6) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000533_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_107_1 & 15;
  st_var_2_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((sec_r000533_20_1 + pub_r000533_5_1) + 26) & 127;
  int sub_step_108_2 = ((sec_r000533_20_2 + pub_r000533_5_2) + 26) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sec_r000533_3_1 + pub_r000533_8_1) + 10) & 127;
  int sub_step_109_2 = ((sec_r000533_3_2 + pub_r000533_8_2) + 10) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000533_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((sec_r000533_1_1 + pub_r000533_0_1) + 26) & 127;
  int sub_step_110_2 = ((sec_r000533_1_2 + pub_r000533_0_2) + 26) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((sub_step_25_1 + pub_r000533_12_1) + 17) & 127;
  int sub_step_111_2 = ((sub_step_25_2 + pub_r000533_12_2) + 17) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_111_1 & 15;
  st_var_0_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((stage_v_85_1 + pub_r000533_12_1) + 8) & 127;
  int sub_step_112_2 = ((stage_v_85_2 + pub_r000533_12_2) + 8) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_112_1 & 15;
  st_var_1_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sub_step_91_1 + pub_r000533_7_1) + 22) & 127;
  int sub_step_113_2 = ((sub_step_91_2 + pub_r000533_7_2) + 22) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_113_1 & 15;
  st_var_2_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((stage_v_78_1 + pub_r000533_3_1) + 34) & 127;
  int sub_step_114_2 = ((stage_v_78_2 + pub_r000533_3_2) + 34) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_114_1 & 15;
  st_var_0_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_8_1 + pub_r000533_7_1) + 16) & 127;
  int sub_step_115_2 = ((sub_step_8_2 + pub_r000533_7_2) + 16) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_115_1 & 15;
  st_var_1_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sub_step_115_1 + pub_r000533_1_1) + 5) & 127;
  int sub_step_116_2 = ((sub_step_115_2 + pub_r000533_1_2) + 5) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000533_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_116_1 & 15;
  st_var_2_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000533_13_1 + pub_r000533_12_1) + 14) & 127;
  int sub_step_117_2 = ((sec_r000533_13_2 + pub_r000533_12_2) + 14) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_117_1 & 15;
  st_var_0_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((stage_v_55_1 + pub_r000533_3_1) + 28) & 127;
  int sub_step_118_2 = ((stage_v_55_2 + pub_r000533_3_2) + 28) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000533_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_118_1 & 15;
  st_var_1_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((sec_r000533_2_1 + pub_r000533_15_1) + 14) & 127;
  int sub_step_119_2 = ((sec_r000533_2_2 + pub_r000533_15_2) + 14) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_119_1 & 15;
  st_var_2_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sec_r000533_4_1 + pub_r000533_9_1) + 29) & 127;
  int sub_step_120_2 = ((sec_r000533_4_2 + pub_r000533_9_2) + 29) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000533_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sec_r000533_1_1 + pub_r000533_1_1) + 14) & 127;
  int sub_step_121_2 = ((sec_r000533_1_2 + pub_r000533_1_2) + 14) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000533_21_1 + pub_r000533_13_1) + 8) & 127;
  int sub_step_122_2 = ((sec_r000533_21_2 + pub_r000533_13_2) + 8) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((stage_v_53_1 + pub_r000533_15_1) + 18) & 127;
  int sub_step_123_2 = ((stage_v_53_2 + pub_r000533_15_2) + 18) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_123_1 & 15;
  st_var_0_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sub_step_54_1 + pub_r000533_11_1) + 31) & 127;
  int sub_step_124_2 = ((sub_step_54_2 + pub_r000533_11_2) + 31) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_124_1 & 15;
  st_var_1_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((sub_step_88_1 + pub_r000533_16_1) + 28) & 127;
  int sub_step_125_2 = ((sub_step_88_2 + pub_r000533_16_2) + 28) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_125_1 & 15;
  st_var_2_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((stage_v_110_1 + pub_r000533_14_1) + 23) & 127;
  int sub_step_126_2 = ((stage_v_110_2 + pub_r000533_14_2) + 23) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_126_1 & 15;
  st_var_0_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((sec_r000533_19_1 + pub_r000533_11_1) + 8) & 127;
  int sub_step_127_2 = ((sec_r000533_19_2 + pub_r000533_11_2) + 8) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_127_1 & 15;
  st_var_1_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_110_1 + pub_r000533_12_1) + 6) & 127;
  int sub_step_128_2 = ((stage_v_110_2 + pub_r000533_12_2) + 6) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_128_1 & 15;
  st_var_2_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((sub_step_96_1 + pub_r000533_5_1) + 25) & 127;
  int sub_step_129_2 = ((sub_step_96_2 + pub_r000533_5_2) + 25) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_129_1 & 15;
  st_var_0_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sec_r000533_13_1 + pub_r000533_6_1) + 6) & 127;
  int sub_step_130_2 = ((sec_r000533_13_2 + pub_r000533_6_2) + 6) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_130_1 & 15;
  st_var_1_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((stage_v_93_1 + pub_r000533_17_1) + 21) & 127;
  int sub_step_131_2 = ((stage_v_93_2 + pub_r000533_17_2) + 21) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_131_1 & 15;
  st_var_2_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((sec_r000533_17_1 + pub_r000533_12_1) + 22) & 127;
  int sub_step_132_2 = ((sec_r000533_17_2 + pub_r000533_12_2) + 22) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000533_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((stage_v_48_1 + pub_r000533_12_1) + 23) & 127;
  int sub_step_133_2 = ((stage_v_48_2 + pub_r000533_12_2) + 23) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000533_13_1 + pub_r000533_14_1) + 35) & 127;
  int sub_step_134_2 = ((sec_r000533_13_2 + pub_r000533_14_2) + 35) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((sec_r000533_4_1 + pub_r000533_2_1) + 33) & 127;
  int sub_step_135_2 = ((sec_r000533_4_2 + pub_r000533_2_2) + 33) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000533_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_135_1 & 15;
  st_var_0_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((stage_v_30_1 + pub_r000533_7_1) + 12) & 127;
  int sub_step_136_2 = ((stage_v_30_2 + pub_r000533_7_2) + 12) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_136_1 & 15;
  st_var_1_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sec_r000533_19_1 + pub_r000533_10_1) + 25) & 127;
  int sub_step_137_2 = ((sec_r000533_19_2 + pub_r000533_10_2) + 25) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_137_1 & 15;
  st_var_2_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((sub_step_66_1 + pub_r000533_0_1) + 10) & 127;
  int sub_step_138_2 = ((sub_step_66_2 + pub_r000533_0_2) + 10) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_138_1 & 15;
  st_var_0_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((stage_v_14_1 + pub_r000533_7_1) + 15) & 127;
  int sub_step_139_2 = ((stage_v_14_2 + pub_r000533_7_2) + 15) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000533_5_2) & 127;
  st_var_1_1.buffer[1] = stage_v_139_1 & 15;
  st_var_1_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((stage_v_11_1 + pub_r000533_8_1) + 11) & 127;
  int sub_step_140_2 = ((stage_v_11_2 + pub_r000533_8_2) + 11) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_140_1 & 15;
  st_var_2_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sec_r000533_17_1 + pub_r000533_0_1) + 32) & 127;
  int sub_step_141_2 = ((sec_r000533_17_2 + pub_r000533_0_2) + 32) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000533_4_2) & 127;
  st_var_0_1.buffer[0] = stage_v_141_1 & 15;
  st_var_0_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sub_step_136_1 + pub_r000533_16_1) + 19) & 127;
  int sub_step_142_2 = ((sub_step_136_2 + pub_r000533_16_2) + 19) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000533_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_142_1 & 15;
  st_var_1_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sub_step_53_1 + pub_r000533_4_1) + 23) & 127;
  int sub_step_143_2 = ((sub_step_53_2 + pub_r000533_4_2) + 23) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_143_1 & 15;
  st_var_2_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((sub_step_44_1 + pub_r000533_11_1) + 35) & 127;
  int sub_step_144_2 = ((sub_step_44_2 + pub_r000533_11_2) + 35) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((stage_v_142_1 + pub_r000533_14_1) + 23) & 127;
  int sub_step_145_2 = ((stage_v_142_2 + pub_r000533_14_2) + 23) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((sub_step_126_1 + pub_r000533_14_1) + 27) & 127;
  int sub_step_146_2 = ((sub_step_126_2 + pub_r000533_14_2) + 27) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sub_step_36_1 + pub_r000533_5_1) + 26) & 127;
  int sub_step_147_2 = ((sub_step_36_2 + pub_r000533_5_2) + 26) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_147_1 & 15;
  st_var_0_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((stage_v_135_1 + pub_r000533_9_1) + 32) & 127;
  int sub_step_148_2 = ((stage_v_135_2 + pub_r000533_9_2) + 32) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_148_1 & 15;
  st_var_1_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sub_step_72_1 + pub_r000533_4_1) + 13) & 127;
  int sub_step_149_2 = ((sub_step_72_2 + pub_r000533_4_2) + 13) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_149_1 & 15;
  st_var_2_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((sec_r000533_14_1 + pub_r000533_0_1) + 23) & 127;
  int sub_step_150_2 = ((sec_r000533_14_2 + pub_r000533_0_2) + 23) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000533_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_150_1 & 15;
  st_var_0_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sub_step_106_1 + pub_r000533_16_1) + 29) & 127;
  int sub_step_151_2 = ((sub_step_106_2 + pub_r000533_16_2) + 29) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_151_1 & 15;
  st_var_1_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((stage_v_66_1 + pub_r000533_14_1) + 6) & 127;
  int sub_step_152_2 = ((stage_v_66_2 + pub_r000533_14_2) + 6) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_152_1 & 15;
  st_var_2_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sec_r000533_5_1 + pub_r000533_14_1) + 35) & 127;
  int sub_step_153_2 = ((sec_r000533_5_2 + pub_r000533_14_2) + 35) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_153_1 & 15;
  st_var_0_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((stage_v_132_1 + pub_r000533_8_1) + 28) & 127;
  int sub_step_154_2 = ((stage_v_132_2 + pub_r000533_8_2) + 28) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_154_1 & 15;
  st_var_1_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sub_step_43_1 + pub_r000533_0_1) + 20) & 127;
  int sub_step_155_2 = ((sub_step_43_2 + pub_r000533_0_2) + 20) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_155_1 & 15;
  st_var_2_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((stage_v_60_1 + pub_r000533_17_1) + 10) & 127;
  int sub_step_156_2 = ((stage_v_60_2 + pub_r000533_17_2) + 10) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000533_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((sub_step_50_1 + pub_r000533_16_1) + 26) & 127;
  int sub_step_157_2 = ((sub_step_50_2 + pub_r000533_16_2) + 26) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((stage_v_149_1 + pub_r000533_5_1) + 21) & 127;
  int sub_step_158_2 = ((stage_v_149_2 + pub_r000533_5_2) + 21) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000533_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000533_10_1 + pub_r000533_6_1) + 22) & 127;
  int sub_step_159_2 = ((sec_r000533_10_2 + pub_r000533_6_2) + 22) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_159_1 & 15;
  st_var_0_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sec_r000533_14_1 + pub_r000533_15_1) + 29) & 127;
  int sub_step_160_2 = ((sec_r000533_14_2 + pub_r000533_15_2) + 29) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_160_1 & 15;
  st_var_1_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((sec_r000533_16_1 + pub_r000533_11_1) + 28) & 127;
  int sub_step_161_2 = ((sec_r000533_16_2 + pub_r000533_11_2) + 28) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_161_1 & 15;
  st_var_2_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((sec_r000533_15_1 + pub_r000533_14_1) + 12) & 127;
  int sub_step_162_2 = ((sec_r000533_15_2 + pub_r000533_14_2) + 12) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_162_1 & 15;
  st_var_0_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_161_1 + pub_r000533_7_1) + 9) & 127;
  int sub_step_163_2 = ((sub_step_161_2 + pub_r000533_7_2) + 9) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_163_1 & 15;
  st_var_1_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((stage_v_107_1 + pub_r000533_6_1) + 27) & 127;
  int sub_step_164_2 = ((stage_v_107_2 + pub_r000533_6_2) + 27) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_164_1 & 15;
  st_var_2_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((sub_step_54_1 + pub_r000533_16_1) + 29) & 127;
  int sub_step_165_2 = ((sub_step_54_2 + pub_r000533_16_2) + 29) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_165_1 & 15;
  st_var_0_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((stage_v_73_1 + pub_r000533_9_1) + 18) & 127;
  int sub_step_166_2 = ((stage_v_73_2 + pub_r000533_9_2) + 18) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_166_1 & 15;
  st_var_1_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((sub_step_129_1 + pub_r000533_3_1) + 13) & 127;
  int sub_step_167_2 = ((sub_step_129_2 + pub_r000533_3_2) + 13) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_167_1 & 15;
  st_var_2_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sec_r000533_18_1 + pub_r000533_17_1) + 28) & 127;
  int sub_step_168_2 = ((sec_r000533_18_2 + pub_r000533_17_2) + 28) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sec_r000533_20_1 + pub_r000533_7_1) + 31) & 127;
  int sub_step_169_2 = ((sec_r000533_20_2 + pub_r000533_7_2) + 31) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000533_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((stage_v_104_1 + pub_r000533_16_1) + 33) & 127;
  int sub_step_170_2 = ((stage_v_104_2 + pub_r000533_16_2) + 33) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((sub_step_130_1 + pub_r000533_14_1) + 35) & 127;
  int sub_step_171_2 = ((sub_step_130_2 + pub_r000533_14_2) + 35) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_171_1 & 15;
  st_var_0_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((sub_step_31_1 + pub_r000533_5_1) + 15) & 127;
  int sub_step_172_2 = ((sub_step_31_2 + pub_r000533_5_2) + 15) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000533_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_172_1 & 15;
  st_var_1_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((stage_v_103_1 + pub_r000533_3_1) + 20) & 127;
  int sub_step_173_2 = ((stage_v_103_2 + pub_r000533_3_2) + 20) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000533_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_173_1 & 15;
  st_var_2_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((stage_v_150_1 + pub_r000533_14_1) + 24) & 127;
  int sub_step_174_2 = ((stage_v_150_2 + pub_r000533_14_2) + 24) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_174_1 & 15;
  st_var_0_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((sub_step_57_1 + pub_r000533_11_1) + 33) & 127;
  int sub_step_175_2 = ((sub_step_57_2 + pub_r000533_11_2) + 33) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_175_1 & 15;
  st_var_1_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((stage_v_76_1 + pub_r000533_2_1) + 18) & 127;
  int sub_step_176_2 = ((stage_v_76_2 + pub_r000533_2_2) + 18) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_176_1 & 15;
  st_var_2_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((sec_r000533_17_1 + pub_r000533_8_1) + 28) & 127;
  int sub_step_177_2 = ((sec_r000533_17_2 + pub_r000533_8_2) + 28) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_177_1 & 15;
  st_var_0_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sub_step_119_1 + pub_r000533_0_1) + 23) & 127;
  int sub_step_178_2 = ((sub_step_119_2 + pub_r000533_0_2) + 23) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_178_1 & 15;
  st_var_1_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((stage_v_47_1 + pub_r000533_11_1) + 7) & 127;
  int sub_step_179_2 = ((stage_v_47_2 + pub_r000533_11_2) + 7) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_179_1 & 15;
  st_var_2_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((stage_v_77_1 + pub_r000533_6_1) + 25) & 127;
  int sub_step_180_2 = ((stage_v_77_2 + pub_r000533_6_2) + 25) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000533_4_1 + pub_r000533_3_1) + 16) & 127;
  int sub_step_181_2 = ((sec_r000533_4_2 + pub_r000533_3_2) + 16) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sec_r000533_4_1 + pub_r000533_17_1) + 34) & 127;
  int sub_step_182_2 = ((sec_r000533_4_2 + pub_r000533_17_2) + 34) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((stage_v_135_1 + pub_r000533_7_1) + 18) & 127;
  int sub_step_183_2 = ((stage_v_135_2 + pub_r000533_7_2) + 18) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_183_1 & 15;
  st_var_0_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((stage_v_19_1 + pub_r000533_17_1) + 27) & 127;
  int sub_step_184_2 = ((stage_v_19_2 + pub_r000533_17_2) + 27) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000533_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_184_1 & 15;
  st_var_1_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sec_r000533_1_1 + pub_r000533_7_1) + 34) & 127;
  int sub_step_185_2 = ((sec_r000533_1_2 + pub_r000533_7_2) + 34) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_185_1 & 15;
  st_var_2_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((stage_v_84_1 + pub_r000533_3_1) + 5) & 127;
  int sub_step_186_2 = ((stage_v_84_2 + pub_r000533_3_2) + 5) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000533_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_186_1 & 15;
  st_var_0_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_183_1 + pub_r000533_1_1) + 17) & 127;
  int sub_step_187_2 = ((stage_v_183_2 + pub_r000533_1_2) + 17) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_187_1 & 15;
  st_var_1_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sec_r000533_19_1 + pub_r000533_2_1) + 13) & 127;
  int sub_step_188_2 = ((sec_r000533_19_2 + pub_r000533_2_2) + 13) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_188_1 & 15;
  st_var_2_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sub_step_24_1 + pub_r000533_4_1) + 35) & 127;
  int sub_step_189_2 = ((sub_step_24_2 + pub_r000533_4_2) + 35) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_189_1 & 15;
  st_var_0_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((sub_step_83_1 + pub_r000533_9_1) + 19) & 127;
  int sub_step_190_2 = ((sub_step_83_2 + pub_r000533_9_2) + 19) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_190_1 & 15;
  st_var_1_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sec_r000533_19_1 + pub_r000533_1_1) + 33) & 127;
  int sub_step_191_2 = ((sec_r000533_19_2 + pub_r000533_1_2) + 33) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000533_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_191_1 & 15;
  st_var_2_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((sub_step_180_1 + pub_r000533_5_1) + 19) & 127;
  int sub_step_192_2 = ((sub_step_180_2 + pub_r000533_5_2) + 19) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000533_15_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000533_20_1 + pub_r000533_6_1) + 35) & 127;
  int sub_step_193_2 = ((sec_r000533_20_2 + pub_r000533_6_2) + 35) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000533_15_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((sec_r000533_19_1 + pub_r000533_4_1) + 21) & 127;
  int sub_step_194_2 = ((sec_r000533_19_2 + pub_r000533_4_2) + 21) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sub_step_149_1 + pub_r000533_5_1) + 9) & 127;
  int sub_step_195_2 = ((sub_step_149_2 + pub_r000533_5_2) + 9) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_195_1 & 15;
  st_var_0_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sub_step_178_1 + pub_r000533_17_1) + 10) & 127;
  int sub_step_196_2 = ((sub_step_178_2 + pub_r000533_17_2) + 10) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_196_1 & 15;
  st_var_1_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sec_r000533_14_1 + pub_r000533_2_1) + 7) & 127;
  int sub_step_197_2 = ((sec_r000533_14_2 + pub_r000533_2_2) + 7) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_197_1 & 15;
  st_var_2_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((stage_v_25_1 + pub_r000533_0_1) + 12) & 127;
  int sub_step_198_2 = ((stage_v_25_2 + pub_r000533_0_2) + 12) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_198_1 & 15;
  st_var_0_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_58_1 + pub_r000533_8_1) + 11) & 127;
  int sub_step_199_2 = ((stage_v_58_2 + pub_r000533_8_2) + 11) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_199_1 & 15;
  st_var_1_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sec_r000533_15_1 + pub_r000533_5_1) + 24) & 127;
  int sub_step_200_2 = ((sec_r000533_15_2 + pub_r000533_5_2) + 24) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_200_1 & 15;
  st_var_2_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sub_step_49_1 + pub_r000533_7_1) + 16) & 127;
  int sub_step_201_2 = ((sub_step_49_2 + pub_r000533_7_2) + 16) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_201_1 & 15;
  st_var_0_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sec_r000533_19_1 + pub_r000533_16_1) + 11) & 127;
  int sub_step_202_2 = ((sec_r000533_19_2 + pub_r000533_16_2) + 11) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_202_1 & 15;
  st_var_1_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((stage_v_93_1 + pub_r000533_0_1) + 20) & 127;
  int sub_step_203_2 = ((stage_v_93_2 + pub_r000533_0_2) + 20) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_203_1 & 15;
  st_var_2_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((sub_step_108_1 + pub_r000533_9_1) + 19) & 127;
  int sub_step_204_2 = ((sub_step_108_2 + pub_r000533_9_2) + 19) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000533_2_1 + pub_r000533_13_1) + 20) & 127;
  int sub_step_205_2 = ((sec_r000533_2_2 + pub_r000533_13_2) + 20) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((stage_v_197_1 + pub_r000533_7_1) + 15) & 127;
  int sub_step_206_2 = ((stage_v_197_2 + pub_r000533_7_2) + 15) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000533_3_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((sub_step_177_1 + pub_r000533_1_1) + 7) & 127;
  int sub_step_207_2 = ((sub_step_177_2 + pub_r000533_1_2) + 7) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_207_1 & 15;
  st_var_0_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((sub_step_141_1 + pub_r000533_17_1) + 23) & 127;
  int sub_step_208_2 = ((sub_step_141_2 + pub_r000533_17_2) + 23) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_208_1 & 15;
  st_var_1_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sec_r000533_14_1 + pub_r000533_0_1) + 32) & 127;
  int sub_step_209_2 = ((sec_r000533_14_2 + pub_r000533_0_2) + 32) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000533_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_209_1 & 15;
  st_var_2_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sec_r000533_11_1 + pub_r000533_8_1) + 34) & 127;
  int sub_step_210_2 = ((sec_r000533_11_2 + pub_r000533_8_2) + 34) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_210_1 & 15;
  st_var_0_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((stage_v_168_1 + pub_r000533_1_1) + 31) & 127;
  int sub_step_211_2 = ((stage_v_168_2 + pub_r000533_1_2) + 31) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_211_1 & 15;
  st_var_1_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((sec_r000533_15_1 + pub_r000533_13_1) + 8) & 127;
  int sub_step_212_2 = ((sec_r000533_15_2 + pub_r000533_13_2) + 8) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_212_1 & 15;
  st_var_2_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((stage_v_155_1 + pub_r000533_6_1) + 10) & 127;
  int sub_step_213_2 = ((stage_v_155_2 + pub_r000533_6_2) + 10) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_213_1 & 15;
  st_var_0_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((sec_r000533_4_1 + pub_r000533_10_1) + 9) & 127;
  int sub_step_214_2 = ((sec_r000533_4_2 + pub_r000533_10_2) + 9) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_214_1 & 15;
  st_var_1_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((sec_r000533_20_1 + pub_r000533_6_1) + 22) & 127;
  int sub_step_215_2 = ((sec_r000533_20_2 + pub_r000533_6_2) + 22) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000533_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_215_1 & 15;
  st_var_2_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((sub_step_62_1 + pub_r000533_17_1) + 11) & 127;
  int sub_step_216_2 = ((sub_step_62_2 + pub_r000533_17_2) + 11) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sub_step_113_1 + pub_r000533_10_1) + 11) & 127;
  int sub_step_217_2 = ((sub_step_113_2 + pub_r000533_10_2) + 11) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((sec_r000533_20_1 + pub_r000533_8_1) + 35) & 127;
  int sub_step_218_2 = ((sec_r000533_20_2 + pub_r000533_8_2) + 35) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000533_11_1 + pub_r000533_1_1) + 22) & 127;
  int sub_step_219_2 = ((sec_r000533_11_2 + pub_r000533_1_2) + 22) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_219_1 & 15;
  st_var_0_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sub_step_214_1 + pub_r000533_15_1) + 21) & 127;
  int sub_step_220_2 = ((sub_step_214_2 + pub_r000533_15_2) + 21) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_220_1 & 15;
  st_var_1_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sec_r000533_0_1 + pub_r000533_3_1) + 23) & 127;
  int sub_step_221_2 = ((sec_r000533_0_2 + pub_r000533_3_2) + 23) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_221_1 & 15;
  st_var_2_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sub_step_199_1 + pub_r000533_12_1) + 7) & 127;
  int sub_step_222_2 = ((sub_step_199_2 + pub_r000533_12_2) + 7) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000533_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_222_1 & 15;
  st_var_0_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000533_19_1 + pub_r000533_2_1) + 19) & 127;
  int sub_step_223_2 = ((sec_r000533_19_2 + pub_r000533_2_2) + 19) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_223_1 & 15;
  st_var_1_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sec_r000533_21_1 + pub_r000533_2_1) + 20) & 127;
  int sub_step_224_2 = ((sec_r000533_21_2 + pub_r000533_2_2) + 20) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000533_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_224_1 & 15;
  st_var_2_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_69_1 + pub_r000533_7_1) + 6) & 127;
  int sub_step_225_2 = ((sub_step_69_2 + pub_r000533_7_2) + 6) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_225_1 & 15;
  st_var_0_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int sub_step_226_1 = ((sub_step_102_1 + pub_r000533_4_1) + 13) & 127;
  int sub_step_226_2 = ((sub_step_102_2 + pub_r000533_4_2) + 13) & 127;
  int stage_v_226_1 = ((sub_step_226_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_226_2 = ((sub_step_226_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_226_1 & 15;
  st_var_1_2.buffer[1] = stage_v_226_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int sub_step_227_1 = ((stage_v_15_1 + pub_r000533_0_1) + 23) & 127;
  int sub_step_227_2 = ((stage_v_15_2 + pub_r000533_0_2) + 23) & 127;
  int stage_v_227_1 = ((sub_step_227_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_227_2 = ((sub_step_227_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_227_1 & 15;
  st_var_2_2.buffer[2] = stage_v_227_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int sub_step_228_1 = ((sub_step_223_1 + pub_r000533_16_1) + 13) & 127;
  int sub_step_228_2 = ((sub_step_223_2 + pub_r000533_16_2) + 13) & 127;
  int stage_v_228_1 = ((sub_step_228_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_228_2 = ((sub_step_228_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_228_1 & 15;
  st_var_0_2.buffer[0] = stage_v_228_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int sub_step_229_1 = ((sub_step_150_1 + pub_r000533_7_1) + 8) & 127;
  int sub_step_229_2 = ((sub_step_150_2 + pub_r000533_7_2) + 8) & 127;
  int stage_v_229_1 = ((sub_step_229_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_229_2 = ((sub_step_229_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_229_1 & 15;
  st_var_1_2.buffer[1] = stage_v_229_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int sub_step_230_1 = ((sec_r000533_9_1 + pub_r000533_12_1) + 31) & 127;
  int sub_step_230_2 = ((sec_r000533_9_2 + pub_r000533_12_2) + 31) & 127;
  int stage_v_230_1 = ((sub_step_230_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_230_2 = ((sub_step_230_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_230_1 & 15;
  st_var_2_2.buffer[2] = stage_v_230_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int sub_step_231_1 = ((stage_v_196_1 + pub_r000533_14_1) + 34) & 127;
  int sub_step_231_2 = ((stage_v_196_2 + pub_r000533_14_2) + 34) & 127;
  int stage_v_231_1 = ((sub_step_231_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_231_2 = ((sub_step_231_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_231_1 & 15;
  st_var_0_2.buffer[0] = stage_v_231_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int sub_step_232_1 = ((sec_r000533_17_1 + pub_r000533_5_1) + 9) & 127;
  int sub_step_232_2 = ((sec_r000533_17_2 + pub_r000533_5_2) + 9) & 127;
  int stage_v_232_1 = ((sub_step_232_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_232_2 = ((sub_step_232_2 * 2) + pub_r000533_17_2) & 127;
  st_var_1_1.buffer[1] = stage_v_232_1 & 15;
  st_var_1_2.buffer[1] = stage_v_232_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int sub_step_233_1 = ((sub_step_105_1 + pub_r000533_8_1) + 17) & 127;
  int sub_step_233_2 = ((sub_step_105_2 + pub_r000533_8_2) + 17) & 127;
  int stage_v_233_1 = ((sub_step_233_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_233_2 = ((sub_step_233_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_233_1 & 15;
  st_var_2_2.buffer[2] = stage_v_233_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int sub_step_234_1 = ((sec_r000533_9_1 + pub_r000533_17_1) + 7) & 127;
  int sub_step_234_2 = ((sec_r000533_9_2 + pub_r000533_17_2) + 7) & 127;
  int stage_v_234_1 = ((sub_step_234_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_234_2 = ((sub_step_234_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_234_1 & 15;
  st_var_0_2.buffer[0] = stage_v_234_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int sub_step_235_1 = ((sec_r000533_16_1 + pub_r000533_8_1) + 24) & 127;
  int sub_step_235_2 = ((sec_r000533_16_2 + pub_r000533_8_2) + 24) & 127;
  int stage_v_235_1 = ((sub_step_235_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_235_2 = ((sub_step_235_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_235_1 & 15;
  st_var_1_2.buffer[1] = stage_v_235_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int sub_step_236_1 = ((stage_v_185_1 + pub_r000533_3_1) + 16) & 127;
  int sub_step_236_2 = ((stage_v_185_2 + pub_r000533_3_2) + 16) & 127;
  int stage_v_236_1 = ((sub_step_236_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_236_2 = ((sub_step_236_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_236_1 & 15;
  st_var_2_2.buffer[2] = stage_v_236_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int sub_step_237_1 = ((sub_step_93_1 + pub_r000533_9_1) + 7) & 127;
  int sub_step_237_2 = ((sub_step_93_2 + pub_r000533_9_2) + 7) & 127;
  int stage_v_237_1 = ((sub_step_237_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_237_2 = ((sub_step_237_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_237_1 & 15;
  st_var_0_2.buffer[0] = stage_v_237_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int sub_step_238_1 = ((sub_step_156_1 + pub_r000533_0_1) + 11) & 127;
  int sub_step_238_2 = ((sub_step_156_2 + pub_r000533_0_2) + 11) & 127;
  int stage_v_238_1 = ((sub_step_238_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_238_2 = ((sub_step_238_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_238_1 & 15;
  st_var_1_2.buffer[1] = stage_v_238_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int sub_step_239_1 = ((stage_v_43_1 + pub_r000533_9_1) + 6) & 127;
  int sub_step_239_2 = ((stage_v_43_2 + pub_r000533_9_2) + 6) & 127;
  int stage_v_239_1 = ((sub_step_239_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_239_2 = ((sub_step_239_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_239_1 & 15;
  st_var_2_2.buffer[2] = stage_v_239_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int sub_step_240_1 = ((stage_v_37_1 + pub_r000533_14_1) + 19) & 127;
  int sub_step_240_2 = ((stage_v_37_2 + pub_r000533_14_2) + 19) & 127;
  int stage_v_240_1 = ((sub_step_240_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_240_2 = ((sub_step_240_2 * 2) + pub_r000533_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_240_1 & 15;
  st_var_0_2.buffer[0] = stage_v_240_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int sub_step_241_1 = ((sec_r000533_8_1 + pub_r000533_14_1) + 34) & 127;
  int sub_step_241_2 = ((sec_r000533_8_2 + pub_r000533_14_2) + 34) & 127;
  int stage_v_241_1 = ((sub_step_241_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_241_2 = ((sub_step_241_2 * 2) + pub_r000533_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_241_1 & 15;
  st_var_1_2.buffer[1] = stage_v_241_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int sub_step_242_1 = ((sub_step_239_1 + pub_r000533_9_1) + 6) & 127;
  int sub_step_242_2 = ((sub_step_239_2 + pub_r000533_9_2) + 6) & 127;
  int stage_v_242_1 = ((sub_step_242_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_242_2 = ((sub_step_242_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_242_1 & 15;
  st_var_2_2.buffer[2] = stage_v_242_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int sub_step_243_1 = ((sub_step_117_1 + pub_r000533_10_1) + 24) & 127;
  int sub_step_243_2 = ((sub_step_117_2 + pub_r000533_10_2) + 24) & 127;
  int stage_v_243_1 = ((sub_step_243_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_243_2 = ((sub_step_243_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_243_1 & 15;
  st_var_0_2.buffer[0] = stage_v_243_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int sub_step_244_1 = ((sub_step_213_1 + pub_r000533_9_1) + 26) & 127;
  int sub_step_244_2 = ((sub_step_213_2 + pub_r000533_9_2) + 26) & 127;
  int stage_v_244_1 = ((sub_step_244_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_244_2 = ((sub_step_244_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_244_1 & 15;
  st_var_1_2.buffer[1] = stage_v_244_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int sub_step_245_1 = ((sub_step_72_1 + pub_r000533_13_1) + 19) & 127;
  int sub_step_245_2 = ((sub_step_72_2 + pub_r000533_13_2) + 19) & 127;
  int stage_v_245_1 = ((sub_step_245_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_245_2 = ((sub_step_245_2 * 2) + pub_r000533_13_2) & 127;
  st_var_2_1.buffer[2] = stage_v_245_1 & 15;
  st_var_2_2.buffer[2] = stage_v_245_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int sub_step_246_1 = ((stage_v_170_1 + pub_r000533_7_1) + 25) & 127;
  int sub_step_246_2 = ((stage_v_170_2 + pub_r000533_7_2) + 25) & 127;
  int stage_v_246_1 = ((sub_step_246_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_246_2 = ((sub_step_246_2 * 2) + pub_r000533_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_246_1 & 15;
  st_var_0_2.buffer[0] = stage_v_246_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int sub_step_247_1 = ((sec_r000533_20_1 + pub_r000533_14_1) + 26) & 127;
  int sub_step_247_2 = ((sec_r000533_20_2 + pub_r000533_14_2) + 26) & 127;
  int stage_v_247_1 = ((sub_step_247_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_247_2 = ((sub_step_247_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_247_1 & 15;
  st_var_1_2.buffer[1] = stage_v_247_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int sub_step_248_1 = ((stage_v_144_1 + pub_r000533_17_1) + 25) & 127;
  int sub_step_248_2 = ((stage_v_144_2 + pub_r000533_17_2) + 25) & 127;
  int stage_v_248_1 = ((sub_step_248_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_248_2 = ((sub_step_248_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_248_1 & 15;
  st_var_2_2.buffer[2] = stage_v_248_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int sub_step_249_1 = ((sub_step_62_1 + pub_r000533_15_1) + 25) & 127;
  int sub_step_249_2 = ((sub_step_62_2 + pub_r000533_15_2) + 25) & 127;
  int stage_v_249_1 = ((sub_step_249_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_249_2 = ((sub_step_249_2 * 2) + pub_r000533_11_2) & 127;
  st_var_0_1.buffer[0] = stage_v_249_1 & 15;
  st_var_0_2.buffer[0] = stage_v_249_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int sub_step_250_1 = ((sub_step_152_1 + pub_r000533_4_1) + 27) & 127;
  int sub_step_250_2 = ((sub_step_152_2 + pub_r000533_4_2) + 27) & 127;
  int stage_v_250_1 = ((sub_step_250_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_250_2 = ((sub_step_250_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_250_1 & 15;
  st_var_1_2.buffer[1] = stage_v_250_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int sub_step_251_1 = ((sec_r000533_4_1 + pub_r000533_13_1) + 17) & 127;
  int sub_step_251_2 = ((sec_r000533_4_2 + pub_r000533_13_2) + 17) & 127;
  int stage_v_251_1 = ((sub_step_251_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_251_2 = ((sub_step_251_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_251_1 & 15;
  st_var_2_2.buffer[2] = stage_v_251_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int sub_step_252_1 = ((sec_r000533_17_1 + pub_r000533_2_1) + 13) & 127;
  int sub_step_252_2 = ((sec_r000533_17_2 + pub_r000533_2_2) + 13) & 127;
  int stage_v_252_1 = ((sub_step_252_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_252_2 = ((sub_step_252_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_252_1 & 15;
  st_var_0_2.buffer[0] = stage_v_252_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int sub_step_253_1 = ((sec_r000533_4_1 + pub_r000533_5_1) + 33) & 127;
  int sub_step_253_2 = ((sec_r000533_4_2 + pub_r000533_5_2) + 33) & 127;
  int stage_v_253_1 = ((sub_step_253_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_253_2 = ((sub_step_253_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_253_1 & 15;
  st_var_1_2.buffer[1] = stage_v_253_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int sub_step_254_1 = ((sub_step_39_1 + pub_r000533_9_1) + 15) & 127;
  int sub_step_254_2 = ((sub_step_39_2 + pub_r000533_9_2) + 15) & 127;
  int stage_v_254_1 = ((sub_step_254_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_254_2 = ((sub_step_254_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_254_1 & 15;
  st_var_2_2.buffer[2] = stage_v_254_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int sub_step_255_1 = ((sec_r000533_13_1 + pub_r000533_2_1) + 17) & 127;
  int sub_step_255_2 = ((sec_r000533_13_2 + pub_r000533_2_2) + 17) & 127;
  int stage_v_255_1 = ((sub_step_255_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_255_2 = ((sub_step_255_2 * 2) + pub_r000533_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_255_1 & 15;
  st_var_0_2.buffer[0] = stage_v_255_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int sub_step_256_1 = ((sec_r000533_12_1 + pub_r000533_3_1) + 29) & 127;
  int sub_step_256_2 = ((sec_r000533_12_2 + pub_r000533_3_2) + 29) & 127;
  int stage_v_256_1 = ((sub_step_256_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_256_2 = ((sub_step_256_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_256_1 & 15;
  st_var_1_2.buffer[1] = stage_v_256_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int sub_step_257_1 = ((stage_v_212_1 + pub_r000533_4_1) + 32) & 127;
  int sub_step_257_2 = ((stage_v_212_2 + pub_r000533_4_2) + 32) & 127;
  int stage_v_257_1 = ((sub_step_257_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_257_2 = ((sub_step_257_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_257_1 & 15;
  st_var_2_2.buffer[2] = stage_v_257_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int sub_step_258_1 = ((stage_v_71_1 + pub_r000533_3_1) + 25) & 127;
  int sub_step_258_2 = ((stage_v_71_2 + pub_r000533_3_2) + 25) & 127;
  int stage_v_258_1 = ((sub_step_258_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_258_2 = ((sub_step_258_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_258_1 & 15;
  st_var_0_2.buffer[0] = stage_v_258_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int sub_step_259_1 = ((stage_v_181_1 + pub_r000533_0_1) + 18) & 127;
  int sub_step_259_2 = ((stage_v_181_2 + pub_r000533_0_2) + 18) & 127;
  int stage_v_259_1 = ((sub_step_259_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_259_2 = ((sub_step_259_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_259_1 & 15;
  st_var_1_2.buffer[1] = stage_v_259_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int sub_step_260_1 = ((sub_step_212_1 + pub_r000533_12_1) + 34) & 127;
  int sub_step_260_2 = ((sub_step_212_2 + pub_r000533_12_2) + 34) & 127;
  int stage_v_260_1 = ((sub_step_260_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_260_2 = ((sub_step_260_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_260_1 & 15;
  st_var_2_2.buffer[2] = stage_v_260_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int sub_step_261_1 = ((stage_v_27_1 + pub_r000533_10_1) + 7) & 127;
  int sub_step_261_2 = ((stage_v_27_2 + pub_r000533_10_2) + 7) & 127;
  int stage_v_261_1 = ((sub_step_261_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_261_2 = ((sub_step_261_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_261_1 & 15;
  st_var_0_2.buffer[0] = stage_v_261_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int sub_step_262_1 = ((stage_v_46_1 + pub_r000533_3_1) + 27) & 127;
  int sub_step_262_2 = ((stage_v_46_2 + pub_r000533_3_2) + 27) & 127;
  int stage_v_262_1 = ((sub_step_262_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_262_2 = ((sub_step_262_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_262_1 & 15;
  st_var_1_2.buffer[1] = stage_v_262_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int sub_step_263_1 = ((stage_v_215_1 + pub_r000533_11_1) + 28) & 127;
  int sub_step_263_2 = ((stage_v_215_2 + pub_r000533_11_2) + 28) & 127;
  int stage_v_263_1 = ((sub_step_263_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_263_2 = ((sub_step_263_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_263_1 & 15;
  st_var_2_2.buffer[2] = stage_v_263_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int sub_step_264_1 = ((stage_v_125_1 + pub_r000533_17_1) + 21) & 127;
  int sub_step_264_2 = ((stage_v_125_2 + pub_r000533_17_2) + 21) & 127;
  int stage_v_264_1 = ((sub_step_264_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_264_2 = ((sub_step_264_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_264_1 & 15;
  st_var_0_2.buffer[0] = stage_v_264_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int sub_step_265_1 = ((sub_step_264_1 + pub_r000533_4_1) + 5) & 127;
  int sub_step_265_2 = ((sub_step_264_2 + pub_r000533_4_2) + 5) & 127;
  int stage_v_265_1 = ((sub_step_265_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_265_2 = ((sub_step_265_2 * 2) + pub_r000533_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_265_1 & 15;
  st_var_1_2.buffer[1] = stage_v_265_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int sub_step_266_1 = ((stage_v_238_1 + pub_r000533_7_1) + 24) & 127;
  int sub_step_266_2 = ((stage_v_238_2 + pub_r000533_7_2) + 24) & 127;
  int stage_v_266_1 = ((sub_step_266_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_266_2 = ((sub_step_266_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_266_1 & 15;
  st_var_2_2.buffer[2] = stage_v_266_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int sub_step_267_1 = ((stage_v_183_1 + pub_r000533_7_1) + 14) & 127;
  int sub_step_267_2 = ((stage_v_183_2 + pub_r000533_7_2) + 14) & 127;
  int stage_v_267_1 = ((sub_step_267_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_267_2 = ((sub_step_267_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_267_1 & 15;
  st_var_0_2.buffer[0] = stage_v_267_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int sub_step_268_1 = ((sec_r000533_2_1 + pub_r000533_5_1) + 26) & 127;
  int sub_step_268_2 = ((sec_r000533_2_2 + pub_r000533_5_2) + 26) & 127;
  int stage_v_268_1 = ((sub_step_268_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_268_2 = ((sub_step_268_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_268_1 & 15;
  st_var_1_2.buffer[1] = stage_v_268_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int sub_step_269_1 = ((sec_r000533_12_1 + pub_r000533_17_1) + 26) & 127;
  int sub_step_269_2 = ((sec_r000533_12_2 + pub_r000533_17_2) + 26) & 127;
  int stage_v_269_1 = ((sub_step_269_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_269_2 = ((sub_step_269_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_269_1 & 15;
  st_var_2_2.buffer[2] = stage_v_269_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int sub_step_270_1 = ((sec_r000533_5_1 + pub_r000533_4_1) + 29) & 127;
  int sub_step_270_2 = ((sec_r000533_5_2 + pub_r000533_4_2) + 29) & 127;
  int stage_v_270_1 = ((sub_step_270_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_270_2 = ((sub_step_270_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_270_1 & 15;
  st_var_0_2.buffer[0] = stage_v_270_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int sub_step_271_1 = ((stage_v_150_1 + pub_r000533_13_1) + 29) & 127;
  int sub_step_271_2 = ((stage_v_150_2 + pub_r000533_13_2) + 29) & 127;
  int stage_v_271_1 = ((sub_step_271_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_271_2 = ((sub_step_271_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_271_1 & 15;
  st_var_1_2.buffer[1] = stage_v_271_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int sub_step_272_1 = ((sub_step_186_1 + pub_r000533_2_1) + 32) & 127;
  int sub_step_272_2 = ((sub_step_186_2 + pub_r000533_2_2) + 32) & 127;
  int stage_v_272_1 = ((sub_step_272_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_272_2 = ((sub_step_272_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_272_1 & 15;
  st_var_2_2.buffer[2] = stage_v_272_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int sub_step_273_1 = ((sub_step_159_1 + pub_r000533_1_1) + 31) & 127;
  int sub_step_273_2 = ((sub_step_159_2 + pub_r000533_1_2) + 31) & 127;
  int stage_v_273_1 = ((sub_step_273_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_273_2 = ((sub_step_273_2 * 2) + pub_r000533_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_273_1 & 15;
  st_var_0_2.buffer[0] = stage_v_273_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int sub_step_274_1 = ((sub_step_214_1 + pub_r000533_13_1) + 31) & 127;
  int sub_step_274_2 = ((sub_step_214_2 + pub_r000533_13_2) + 31) & 127;
  int stage_v_274_1 = ((sub_step_274_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_274_2 = ((sub_step_274_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_274_1 & 15;
  st_var_1_2.buffer[1] = stage_v_274_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int sub_step_275_1 = ((sec_r000533_20_1 + pub_r000533_10_1) + 33) & 127;
  int sub_step_275_2 = ((sec_r000533_20_2 + pub_r000533_10_2) + 33) & 127;
  int stage_v_275_1 = ((sub_step_275_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_275_2 = ((sub_step_275_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_275_1 & 15;
  st_var_2_2.buffer[2] = stage_v_275_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int sub_step_276_1 = ((stage_v_231_1 + pub_r000533_13_1) + 29) & 127;
  int sub_step_276_2 = ((stage_v_231_2 + pub_r000533_13_2) + 29) & 127;
  int stage_v_276_1 = ((sub_step_276_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_276_2 = ((sub_step_276_2 * 2) + pub_r000533_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_276_1 & 15;
  st_var_0_2.buffer[0] = stage_v_276_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int sub_step_277_1 = ((sub_step_85_1 + pub_r000533_12_1) + 35) & 127;
  int sub_step_277_2 = ((sub_step_85_2 + pub_r000533_12_2) + 35) & 127;
  int stage_v_277_1 = ((sub_step_277_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_277_2 = ((sub_step_277_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_277_1 & 15;
  st_var_1_2.buffer[1] = stage_v_277_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int sub_step_278_1 = ((stage_v_174_1 + pub_r000533_1_1) + 31) & 127;
  int sub_step_278_2 = ((stage_v_174_2 + pub_r000533_1_2) + 31) & 127;
  int stage_v_278_1 = ((sub_step_278_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_278_2 = ((sub_step_278_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_278_1 & 15;
  st_var_2_2.buffer[2] = stage_v_278_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int sub_step_279_1 = ((sec_r000533_16_1 + pub_r000533_0_1) + 33) & 127;
  int sub_step_279_2 = ((sec_r000533_16_2 + pub_r000533_0_2) + 33) & 127;
  int stage_v_279_1 = ((sub_step_279_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_279_2 = ((sub_step_279_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_279_1 & 15;
  st_var_0_2.buffer[0] = stage_v_279_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int sub_step_280_1 = ((sec_r000533_12_1 + pub_r000533_8_1) + 28) & 127;
  int sub_step_280_2 = ((sec_r000533_12_2 + pub_r000533_8_2) + 28) & 127;
  int stage_v_280_1 = ((sub_step_280_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_280_2 = ((sub_step_280_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_280_1 & 15;
  st_var_1_2.buffer[1] = stage_v_280_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int sub_step_281_1 = ((sec_r000533_8_1 + pub_r000533_1_1) + 24) & 127;
  int sub_step_281_2 = ((sec_r000533_8_2 + pub_r000533_1_2) + 24) & 127;
  int stage_v_281_1 = ((sub_step_281_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_281_2 = ((sub_step_281_2 * 2) + pub_r000533_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_281_1 & 15;
  st_var_2_2.buffer[2] = stage_v_281_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int sub_step_282_1 = ((sub_step_190_1 + pub_r000533_8_1) + 32) & 127;
  int sub_step_282_2 = ((sub_step_190_2 + pub_r000533_8_2) + 32) & 127;
  int stage_v_282_1 = ((sub_step_282_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_282_2 = ((sub_step_282_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_282_1 & 15;
  st_var_0_2.buffer[0] = stage_v_282_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int sub_step_283_1 = ((sec_r000533_7_1 + pub_r000533_8_1) + 22) & 127;
  int sub_step_283_2 = ((sec_r000533_7_2 + pub_r000533_8_2) + 22) & 127;
  int stage_v_283_1 = ((sub_step_283_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_283_2 = ((sub_step_283_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_283_1 & 15;
  st_var_1_2.buffer[1] = stage_v_283_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int sub_step_284_1 = ((stage_v_72_1 + pub_r000533_8_1) + 26) & 127;
  int sub_step_284_2 = ((stage_v_72_2 + pub_r000533_8_2) + 26) & 127;
  int stage_v_284_1 = ((sub_step_284_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_284_2 = ((sub_step_284_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_284_1 & 15;
  st_var_2_2.buffer[2] = stage_v_284_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int sub_step_285_1 = ((stage_v_176_1 + pub_r000533_10_1) + 25) & 127;
  int sub_step_285_2 = ((stage_v_176_2 + pub_r000533_10_2) + 25) & 127;
  int stage_v_285_1 = ((sub_step_285_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_285_2 = ((sub_step_285_2 * 2) + pub_r000533_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_285_1 & 15;
  st_var_0_2.buffer[0] = stage_v_285_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int sub_step_286_1 = ((sub_step_242_1 + pub_r000533_15_1) + 29) & 127;
  int sub_step_286_2 = ((sub_step_242_2 + pub_r000533_15_2) + 29) & 127;
  int stage_v_286_1 = ((sub_step_286_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_286_2 = ((sub_step_286_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_286_1 & 15;
  st_var_1_2.buffer[1] = stage_v_286_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int sub_step_287_1 = ((stage_v_264_1 + pub_r000533_16_1) + 5) & 127;
  int sub_step_287_2 = ((stage_v_264_2 + pub_r000533_16_2) + 5) & 127;
  int stage_v_287_1 = ((sub_step_287_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_287_2 = ((sub_step_287_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_287_1 & 15;
  st_var_2_2.buffer[2] = stage_v_287_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int sub_step_288_1 = ((stage_v_68_1 + pub_r000533_2_1) + 29) & 127;
  int sub_step_288_2 = ((stage_v_68_2 + pub_r000533_2_2) + 29) & 127;
  int stage_v_288_1 = ((sub_step_288_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_288_2 = ((sub_step_288_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_288_1 & 15;
  st_var_0_2.buffer[0] = stage_v_288_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int sub_step_289_1 = ((sec_r000533_19_1 + pub_r000533_12_1) + 32) & 127;
  int sub_step_289_2 = ((sec_r000533_19_2 + pub_r000533_12_2) + 32) & 127;
  int stage_v_289_1 = ((sub_step_289_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_289_2 = ((sub_step_289_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_289_1 & 15;
  st_var_1_2.buffer[1] = stage_v_289_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int sub_step_290_1 = ((sec_r000533_2_1 + pub_r000533_9_1) + 17) & 127;
  int sub_step_290_2 = ((sec_r000533_2_2 + pub_r000533_9_2) + 17) & 127;
  int stage_v_290_1 = ((sub_step_290_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_290_2 = ((sub_step_290_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_290_1 & 15;
  st_var_2_2.buffer[2] = stage_v_290_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int sub_step_291_1 = ((sub_step_116_1 + pub_r000533_3_1) + 16) & 127;
  int sub_step_291_2 = ((sub_step_116_2 + pub_r000533_3_2) + 16) & 127;
  int stage_v_291_1 = ((sub_step_291_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_291_2 = ((sub_step_291_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_291_1 & 15;
  st_var_0_2.buffer[0] = stage_v_291_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int sub_step_292_1 = ((sub_step_42_1 + pub_r000533_8_1) + 22) & 127;
  int sub_step_292_2 = ((sub_step_42_2 + pub_r000533_8_2) + 22) & 127;
  int stage_v_292_1 = ((sub_step_292_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_292_2 = ((sub_step_292_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_292_1 & 15;
  st_var_1_2.buffer[1] = stage_v_292_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int sub_step_293_1 = ((stage_v_80_1 + pub_r000533_3_1) + 17) & 127;
  int sub_step_293_2 = ((stage_v_80_2 + pub_r000533_3_2) + 17) & 127;
  int stage_v_293_1 = ((sub_step_293_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_293_2 = ((sub_step_293_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_293_1 & 15;
  st_var_2_2.buffer[2] = stage_v_293_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int sub_step_294_1 = ((sec_r000533_10_1 + pub_r000533_13_1) + 16) & 127;
  int sub_step_294_2 = ((sec_r000533_10_2 + pub_r000533_13_2) + 16) & 127;
  int stage_v_294_1 = ((sub_step_294_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_294_2 = ((sub_step_294_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_294_1 & 15;
  st_var_0_2.buffer[0] = stage_v_294_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int sub_step_295_1 = ((sec_r000533_4_1 + pub_r000533_3_1) + 27) & 127;
  int sub_step_295_2 = ((sec_r000533_4_2 + pub_r000533_3_2) + 27) & 127;
  int stage_v_295_1 = ((sub_step_295_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_295_2 = ((sub_step_295_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_295_1 & 15;
  st_var_1_2.buffer[1] = stage_v_295_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int sub_step_296_1 = ((sec_r000533_20_1 + pub_r000533_14_1) + 6) & 127;
  int sub_step_296_2 = ((sec_r000533_20_2 + pub_r000533_14_2) + 6) & 127;
  int stage_v_296_1 = ((sub_step_296_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_296_2 = ((sub_step_296_2 * 2) + pub_r000533_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_296_1 & 15;
  st_var_2_2.buffer[2] = stage_v_296_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int sub_step_297_1 = ((sec_r000533_0_1 + pub_r000533_16_1) + 24) & 127;
  int sub_step_297_2 = ((sec_r000533_0_2 + pub_r000533_16_2) + 24) & 127;
  int stage_v_297_1 = ((sub_step_297_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_297_2 = ((sub_step_297_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_297_1 & 15;
  st_var_0_2.buffer[0] = stage_v_297_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int sub_step_298_1 = ((sec_r000533_4_1 + pub_r000533_5_1) + 33) & 127;
  int sub_step_298_2 = ((sec_r000533_4_2 + pub_r000533_5_2) + 33) & 127;
  int stage_v_298_1 = ((sub_step_298_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_298_2 = ((sub_step_298_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_298_1 & 15;
  st_var_1_2.buffer[1] = stage_v_298_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int sub_step_299_1 = ((sub_step_224_1 + pub_r000533_2_1) + 6) & 127;
  int sub_step_299_2 = ((sub_step_224_2 + pub_r000533_2_2) + 6) & 127;
  int stage_v_299_1 = ((sub_step_299_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_299_2 = ((sub_step_299_2 * 2) + pub_r000533_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_299_1 & 15;
  st_var_2_2.buffer[2] = stage_v_299_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int sub_step_300_1 = ((sub_step_261_1 + pub_r000533_6_1) + 7) & 127;
  int sub_step_300_2 = ((sub_step_261_2 + pub_r000533_6_2) + 7) & 127;
  int stage_v_300_1 = ((sub_step_300_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_300_2 = ((sub_step_300_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_300_1 & 15;
  st_var_0_2.buffer[0] = stage_v_300_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int sub_step_301_1 = ((stage_v_166_1 + pub_r000533_3_1) + 20) & 127;
  int sub_step_301_2 = ((stage_v_166_2 + pub_r000533_3_2) + 20) & 127;
  int stage_v_301_1 = ((sub_step_301_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_301_2 = ((sub_step_301_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_301_1 & 15;
  st_var_1_2.buffer[1] = stage_v_301_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int sub_step_302_1 = ((stage_v_253_1 + pub_r000533_15_1) + 35) & 127;
  int sub_step_302_2 = ((stage_v_253_2 + pub_r000533_15_2) + 35) & 127;
  int stage_v_302_1 = ((sub_step_302_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_302_2 = ((sub_step_302_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_302_1 & 15;
  st_var_2_2.buffer[2] = stage_v_302_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int sub_step_303_1 = ((stage_v_268_1 + pub_r000533_4_1) + 13) & 127;
  int sub_step_303_2 = ((stage_v_268_2 + pub_r000533_4_2) + 13) & 127;
  int stage_v_303_1 = ((sub_step_303_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_303_2 = ((sub_step_303_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_303_1 & 15;
  st_var_0_2.buffer[0] = stage_v_303_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int sub_step_304_1 = ((stage_v_245_1 + pub_r000533_7_1) + 33) & 127;
  int sub_step_304_2 = ((stage_v_245_2 + pub_r000533_7_2) + 33) & 127;
  int stage_v_304_1 = ((sub_step_304_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_304_2 = ((sub_step_304_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_304_1 & 15;
  st_var_1_2.buffer[1] = stage_v_304_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int sub_step_305_1 = ((sec_r000533_13_1 + pub_r000533_4_1) + 7) & 127;
  int sub_step_305_2 = ((sec_r000533_13_2 + pub_r000533_4_2) + 7) & 127;
  int stage_v_305_1 = ((sub_step_305_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_305_2 = ((sub_step_305_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_305_1 & 15;
  st_var_2_2.buffer[2] = stage_v_305_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int sub_step_306_1 = ((sec_r000533_2_1 + pub_r000533_4_1) + 17) & 127;
  int sub_step_306_2 = ((sec_r000533_2_2 + pub_r000533_4_2) + 17) & 127;
  int stage_v_306_1 = ((sub_step_306_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_306_2 = ((sub_step_306_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_306_1 & 15;
  st_var_0_2.buffer[0] = stage_v_306_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int sub_step_307_1 = ((sec_r000533_20_1 + pub_r000533_15_1) + 24) & 127;
  int sub_step_307_2 = ((sec_r000533_20_2 + pub_r000533_15_2) + 24) & 127;
  int stage_v_307_1 = ((sub_step_307_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_307_2 = ((sub_step_307_2 * 2) + pub_r000533_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_307_1 & 15;
  st_var_1_2.buffer[1] = stage_v_307_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int sub_step_308_1 = ((stage_v_250_1 + pub_r000533_11_1) + 25) & 127;
  int sub_step_308_2 = ((stage_v_250_2 + pub_r000533_11_2) + 25) & 127;
  int stage_v_308_1 = ((sub_step_308_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_308_2 = ((sub_step_308_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_308_1 & 15;
  st_var_2_2.buffer[2] = stage_v_308_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int sub_step_309_1 = ((stage_v_86_1 + pub_r000533_6_1) + 14) & 127;
  int sub_step_309_2 = ((stage_v_86_2 + pub_r000533_6_2) + 14) & 127;
  int stage_v_309_1 = ((sub_step_309_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_309_2 = ((sub_step_309_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_309_1 & 15;
  st_var_0_2.buffer[0] = stage_v_309_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int sub_step_310_1 = ((stage_v_258_1 + pub_r000533_15_1) + 20) & 127;
  int sub_step_310_2 = ((stage_v_258_2 + pub_r000533_15_2) + 20) & 127;
  int stage_v_310_1 = ((sub_step_310_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_310_2 = ((sub_step_310_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_310_1 & 15;
  st_var_1_2.buffer[1] = stage_v_310_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int sub_step_311_1 = ((stage_v_114_1 + pub_r000533_14_1) + 13) & 127;
  int sub_step_311_2 = ((stage_v_114_2 + pub_r000533_14_2) + 13) & 127;
  int stage_v_311_1 = ((sub_step_311_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_311_2 = ((sub_step_311_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_311_1 & 15;
  st_var_2_2.buffer[2] = stage_v_311_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int sub_step_312_1 = ((sec_r000533_8_1 + pub_r000533_2_1) + 20) & 127;
  int sub_step_312_2 = ((sec_r000533_8_2 + pub_r000533_2_2) + 20) & 127;
  int stage_v_312_1 = ((sub_step_312_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_312_2 = ((sub_step_312_2 * 2) + pub_r000533_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_312_1 & 15;
  st_var_0_2.buffer[0] = stage_v_312_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  int sub_step_313_1 = ((stage_v_259_1 + pub_r000533_13_1) + 17) & 127;
  int sub_step_313_2 = ((stage_v_259_2 + pub_r000533_13_2) + 17) & 127;
  int stage_v_313_1 = ((sub_step_313_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_313_2 = ((sub_step_313_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_313_1 & 15;
  st_var_1_2.buffer[1] = stage_v_313_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_313_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_313_2) & 255;
  int sub_step_314_1 = ((sub_step_65_1 + pub_r000533_5_1) + 21) & 127;
  int sub_step_314_2 = ((sub_step_65_2 + pub_r000533_5_2) + 21) & 127;
  int stage_v_314_1 = ((sub_step_314_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_314_2 = ((sub_step_314_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_314_1 & 15;
  st_var_2_2.buffer[2] = stage_v_314_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_314_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_314_2) & 255;
  int sub_step_315_1 = ((sub_step_313_1 + pub_r000533_0_1) + 32) & 127;
  int sub_step_315_2 = ((sub_step_313_2 + pub_r000533_0_2) + 32) & 127;
  int stage_v_315_1 = ((sub_step_315_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_315_2 = ((sub_step_315_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_315_1 & 15;
  st_var_0_2.buffer[0] = stage_v_315_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_315_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_315_2) & 255;
  int sub_step_316_1 = ((stage_v_87_1 + pub_r000533_7_1) + 8) & 127;
  int sub_step_316_2 = ((stage_v_87_2 + pub_r000533_7_2) + 8) & 127;
  int stage_v_316_1 = ((sub_step_316_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_316_2 = ((sub_step_316_2 * 2) + pub_r000533_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_316_1 & 15;
  st_var_1_2.buffer[1] = stage_v_316_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_316_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_316_2) & 255;
  int sub_step_317_1 = ((sec_r000533_15_1 + pub_r000533_15_1) + 33) & 127;
  int sub_step_317_2 = ((sec_r000533_15_2 + pub_r000533_15_2) + 33) & 127;
  int stage_v_317_1 = ((sub_step_317_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_317_2 = ((sub_step_317_2 * 2) + pub_r000533_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_317_1 & 15;
  st_var_2_2.buffer[2] = stage_v_317_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_317_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_317_2) & 255;
  int sub_step_318_1 = ((sec_r000533_0_1 + pub_r000533_11_1) + 33) & 127;
  int sub_step_318_2 = ((sec_r000533_0_2 + pub_r000533_11_2) + 33) & 127;
  int stage_v_318_1 = ((sub_step_318_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_318_2 = ((sub_step_318_2 * 2) + pub_r000533_9_2) & 127;
  st_var_0_1.buffer[0] = stage_v_318_1 & 15;
  st_var_0_2.buffer[0] = stage_v_318_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_318_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_318_2) & 255;
  int sub_step_319_1 = ((stage_v_74_1 + pub_r000533_12_1) + 34) & 127;
  int sub_step_319_2 = ((stage_v_74_2 + pub_r000533_12_2) + 34) & 127;
  int stage_v_319_1 = ((sub_step_319_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_319_2 = ((sub_step_319_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_319_1 & 15;
  st_var_1_2.buffer[1] = stage_v_319_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_319_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_319_2) & 255;
  int sub_step_320_1 = ((stage_v_164_1 + pub_r000533_8_1) + 18) & 127;
  int sub_step_320_2 = ((stage_v_164_2 + pub_r000533_8_2) + 18) & 127;
  int stage_v_320_1 = ((sub_step_320_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_320_2 = ((sub_step_320_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_320_1 & 15;
  st_var_2_2.buffer[2] = stage_v_320_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_320_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_320_2) & 255;
  int sub_step_321_1 = ((stage_v_310_1 + pub_r000533_15_1) + 11) & 127;
  int sub_step_321_2 = ((stage_v_310_2 + pub_r000533_15_2) + 11) & 127;
  int stage_v_321_1 = ((sub_step_321_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_321_2 = ((sub_step_321_2 * 2) + pub_r000533_3_2) & 127;
  st_var_0_1.buffer[0] = stage_v_321_1 & 15;
  st_var_0_2.buffer[0] = stage_v_321_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_321_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_321_2) & 255;
  int sub_step_322_1 = ((sec_r000533_12_1 + pub_r000533_6_1) + 23) & 127;
  int sub_step_322_2 = ((sec_r000533_12_2 + pub_r000533_6_2) + 23) & 127;
  int stage_v_322_1 = ((sub_step_322_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_322_2 = ((sub_step_322_2 * 2) + pub_r000533_16_2) & 127;
  st_var_1_1.buffer[1] = stage_v_322_1 & 15;
  st_var_1_2.buffer[1] = stage_v_322_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_322_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_322_2) & 255;
  int sub_step_323_1 = ((sec_r000533_2_1 + pub_r000533_1_1) + 10) & 127;
  int sub_step_323_2 = ((sec_r000533_2_2 + pub_r000533_1_2) + 10) & 127;
  int stage_v_323_1 = ((sub_step_323_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_323_2 = ((sub_step_323_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_323_1 & 15;
  st_var_2_2.buffer[2] = stage_v_323_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_323_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_323_2) & 255;
  int sub_step_324_1 = ((sec_r000533_0_1 + pub_r000533_6_1) + 6) & 127;
  int sub_step_324_2 = ((sec_r000533_0_2 + pub_r000533_6_2) + 6) & 127;
  int stage_v_324_1 = ((sub_step_324_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_324_2 = ((sub_step_324_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_324_1 & 15;
  st_var_0_2.buffer[0] = stage_v_324_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_324_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_324_2) & 255;
  int sub_step_325_1 = ((sec_r000533_20_1 + pub_r000533_11_1) + 12) & 127;
  int sub_step_325_2 = ((sec_r000533_20_2 + pub_r000533_11_2) + 12) & 127;
  int stage_v_325_1 = ((sub_step_325_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_325_2 = ((sub_step_325_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_325_1 & 15;
  st_var_1_2.buffer[1] = stage_v_325_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_325_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_325_2) & 255;
  int sub_step_326_1 = ((sub_step_162_1 + pub_r000533_1_1) + 24) & 127;
  int sub_step_326_2 = ((sub_step_162_2 + pub_r000533_1_2) + 24) & 127;
  int stage_v_326_1 = ((sub_step_326_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_326_2 = ((sub_step_326_2 * 2) + pub_r000533_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_326_1 & 15;
  st_var_2_2.buffer[2] = stage_v_326_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_326_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_326_2) & 255;
  int sub_step_327_1 = ((sub_step_54_1 + pub_r000533_16_1) + 16) & 127;
  int sub_step_327_2 = ((sub_step_54_2 + pub_r000533_16_2) + 16) & 127;
  int stage_v_327_1 = ((sub_step_327_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_327_2 = ((sub_step_327_2 * 2) + pub_r000533_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_327_1 & 15;
  st_var_0_2.buffer[0] = stage_v_327_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_327_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_327_2) & 255;
  int sub_step_328_1 = ((sec_r000533_14_1 + pub_r000533_16_1) + 11) & 127;
  int sub_step_328_2 = ((sec_r000533_14_2 + pub_r000533_16_2) + 11) & 127;
  int stage_v_328_1 = ((sub_step_328_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_328_2 = ((sub_step_328_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_328_1 & 15;
  st_var_1_2.buffer[1] = stage_v_328_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_328_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_328_2) & 255;
  int sub_step_329_1 = ((sub_step_17_1 + pub_r000533_14_1) + 23) & 127;
  int sub_step_329_2 = ((sub_step_17_2 + pub_r000533_14_2) + 23) & 127;
  int stage_v_329_1 = ((sub_step_329_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_329_2 = ((sub_step_329_2 * 2) + pub_r000533_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_329_1 & 15;
  st_var_2_2.buffer[2] = stage_v_329_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_329_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_329_2) & 255;
  int sub_step_330_1 = ((sub_step_124_1 + pub_r000533_7_1) + 25) & 127;
  int sub_step_330_2 = ((sub_step_124_2 + pub_r000533_7_2) + 25) & 127;
  int stage_v_330_1 = ((sub_step_330_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_330_2 = ((sub_step_330_2 * 2) + pub_r000533_7_2) & 127;
  st_var_0_1.buffer[0] = stage_v_330_1 & 15;
  st_var_0_2.buffer[0] = stage_v_330_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_330_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_330_2) & 255;
  int sub_step_331_1 = ((sub_step_151_1 + pub_r000533_16_1) + 17) & 127;
  int sub_step_331_2 = ((sub_step_151_2 + pub_r000533_16_2) + 17) & 127;
  int stage_v_331_1 = ((sub_step_331_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_331_2 = ((sub_step_331_2 * 2) + pub_r000533_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_331_1 & 15;
  st_var_1_2.buffer[1] = stage_v_331_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_331_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_331_2) & 255;
  int sub_step_332_1 = ((sub_step_125_1 + pub_r000533_16_1) + 22) & 127;
  int sub_step_332_2 = ((sub_step_125_2 + pub_r000533_16_2) + 22) & 127;
  int stage_v_332_1 = ((sub_step_332_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_332_2 = ((sub_step_332_2 * 2) + pub_r000533_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_332_1 & 15;
  st_var_2_2.buffer[2] = stage_v_332_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_332_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_332_2) & 255;
  int sub_step_333_1 = ((stage_v_304_1 + pub_r000533_10_1) + 30) & 127;
  int sub_step_333_2 = ((stage_v_304_2 + pub_r000533_10_2) + 30) & 127;
  int stage_v_333_1 = ((sub_step_333_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_333_2 = ((sub_step_333_2 * 2) + pub_r000533_0_2) & 127;
  st_var_0_1.buffer[0] = stage_v_333_1 & 15;
  st_var_0_2.buffer[0] = stage_v_333_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_333_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_333_2) & 255;
  int sub_step_334_1 = ((stage_v_134_1 + pub_r000533_10_1) + 10) & 127;
  int sub_step_334_2 = ((stage_v_134_2 + pub_r000533_10_2) + 10) & 127;
  int stage_v_334_1 = ((sub_step_334_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_334_2 = ((sub_step_334_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_334_1 & 15;
  st_var_1_2.buffer[1] = stage_v_334_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_334_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_334_2) & 255;
  int sub_step_335_1 = ((sub_step_38_1 + pub_r000533_5_1) + 19) & 127;
  int sub_step_335_2 = ((sub_step_38_2 + pub_r000533_5_2) + 19) & 127;
  int stage_v_335_1 = ((sub_step_335_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_335_2 = ((sub_step_335_2 * 2) + pub_r000533_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_335_1 & 15;
  st_var_2_2.buffer[2] = stage_v_335_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_335_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_335_2) & 255;
  int sub_step_336_1 = ((sec_r000533_12_1 + pub_r000533_3_1) + 15) & 127;
  int sub_step_336_2 = ((sec_r000533_12_2 + pub_r000533_3_2) + 15) & 127;
  int stage_v_336_1 = ((sub_step_336_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_336_2 = ((sub_step_336_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_336_1 & 15;
  st_var_0_2.buffer[0] = stage_v_336_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_336_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_336_2) & 255;
  int sub_step_337_1 = ((sub_step_54_1 + pub_r000533_15_1) + 32) & 127;
  int sub_step_337_2 = ((sub_step_54_2 + pub_r000533_15_2) + 32) & 127;
  int stage_v_337_1 = ((sub_step_337_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_337_2 = ((sub_step_337_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_337_1 & 15;
  st_var_1_2.buffer[1] = stage_v_337_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_337_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_337_2) & 255;
  int sub_step_338_1 = ((sub_step_226_1 + pub_r000533_11_1) + 34) & 127;
  int sub_step_338_2 = ((sub_step_226_2 + pub_r000533_11_2) + 34) & 127;
  int stage_v_338_1 = ((sub_step_338_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_338_2 = ((sub_step_338_2 * 2) + pub_r000533_9_2) & 127;
  st_var_2_1.buffer[2] = stage_v_338_1 & 15;
  st_var_2_2.buffer[2] = stage_v_338_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_338_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_338_2) & 255;
  int sub_step_339_1 = ((sec_r000533_4_1 + pub_r000533_10_1) + 25) & 127;
  int sub_step_339_2 = ((sec_r000533_4_2 + pub_r000533_10_2) + 25) & 127;
  int stage_v_339_1 = ((sub_step_339_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_339_2 = ((sub_step_339_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_339_1 & 15;
  st_var_0_2.buffer[0] = stage_v_339_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_339_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_339_2) & 255;
  int sub_step_340_1 = ((sec_r000533_9_1 + pub_r000533_8_1) + 10) & 127;
  int sub_step_340_2 = ((sec_r000533_9_2 + pub_r000533_8_2) + 10) & 127;
  int stage_v_340_1 = ((sub_step_340_1 * 2) + pub_r000533_14_1) & 127;
  int stage_v_340_2 = ((sub_step_340_2 * 2) + pub_r000533_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_340_1 & 15;
  st_var_1_2.buffer[1] = stage_v_340_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_340_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_340_2) & 255;
  int sub_step_341_1 = ((sec_r000533_18_1 + pub_r000533_1_1) + 17) & 127;
  int sub_step_341_2 = ((sec_r000533_18_2 + pub_r000533_1_2) + 17) & 127;
  int stage_v_341_1 = ((sub_step_341_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_341_2 = ((sub_step_341_2 * 2) + pub_r000533_12_2) & 127;
  st_var_2_1.buffer[2] = stage_v_341_1 & 15;
  st_var_2_2.buffer[2] = stage_v_341_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_341_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_341_2) & 255;
  int sub_step_342_1 = ((sub_step_313_1 + pub_r000533_1_1) + 21) & 127;
  int sub_step_342_2 = ((sub_step_313_2 + pub_r000533_1_2) + 21) & 127;
  int stage_v_342_1 = ((sub_step_342_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_342_2 = ((sub_step_342_2 * 2) + pub_r000533_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_342_1 & 15;
  st_var_0_2.buffer[0] = stage_v_342_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_342_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_342_2) & 255;
  int sub_step_343_1 = ((sec_r000533_5_1 + pub_r000533_13_1) + 6) & 127;
  int sub_step_343_2 = ((sec_r000533_5_2 + pub_r000533_13_2) + 6) & 127;
  int stage_v_343_1 = ((sub_step_343_1 * 2) + pub_r000533_3_1) & 127;
  int stage_v_343_2 = ((sub_step_343_2 * 2) + pub_r000533_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_343_1 & 15;
  st_var_1_2.buffer[1] = stage_v_343_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_343_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_343_2) & 255;
  int sub_step_344_1 = ((sub_step_74_1 + pub_r000533_2_1) + 20) & 127;
  int sub_step_344_2 = ((sub_step_74_2 + pub_r000533_2_2) + 20) & 127;
  int stage_v_344_1 = ((sub_step_344_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_344_2 = ((sub_step_344_2 * 2) + pub_r000533_0_2) & 127;
  st_var_2_1.buffer[2] = stage_v_344_1 & 15;
  st_var_2_2.buffer[2] = stage_v_344_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_344_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_344_2) & 255;
  int sub_step_345_1 = ((sec_r000533_5_1 + pub_r000533_1_1) + 14) & 127;
  int sub_step_345_2 = ((sec_r000533_5_2 + pub_r000533_1_2) + 14) & 127;
  int stage_v_345_1 = ((sub_step_345_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_345_2 = ((sub_step_345_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_345_1 & 15;
  st_var_0_2.buffer[0] = stage_v_345_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_345_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_345_2) & 255;
  int sub_step_346_1 = ((sub_step_334_1 + pub_r000533_2_1) + 25) & 127;
  int sub_step_346_2 = ((sub_step_334_2 + pub_r000533_2_2) + 25) & 127;
  int stage_v_346_1 = ((sub_step_346_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_346_2 = ((sub_step_346_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_346_1 & 15;
  st_var_1_2.buffer[1] = stage_v_346_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_346_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_346_2) & 255;
  int sub_step_347_1 = ((sub_step_277_1 + pub_r000533_7_1) + 8) & 127;
  int sub_step_347_2 = ((sub_step_277_2 + pub_r000533_7_2) + 8) & 127;
  int stage_v_347_1 = ((sub_step_347_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_347_2 = ((sub_step_347_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_347_1 & 15;
  st_var_2_2.buffer[2] = stage_v_347_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_347_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_347_2) & 255;
  int sub_step_348_1 = ((sub_step_177_1 + pub_r000533_17_1) + 9) & 127;
  int sub_step_348_2 = ((sub_step_177_2 + pub_r000533_17_2) + 9) & 127;
  int stage_v_348_1 = ((sub_step_348_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_348_2 = ((sub_step_348_2 * 2) + pub_r000533_5_2) & 127;
  st_var_0_1.buffer[0] = stage_v_348_1 & 15;
  st_var_0_2.buffer[0] = stage_v_348_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_348_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_348_2) & 255;
  int sub_step_349_1 = ((sec_r000533_8_1 + pub_r000533_4_1) + 32) & 127;
  int sub_step_349_2 = ((sec_r000533_8_2 + pub_r000533_4_2) + 32) & 127;
  int stage_v_349_1 = ((sub_step_349_1 * 2) + pub_r000533_9_1) & 127;
  int stage_v_349_2 = ((sub_step_349_2 * 2) + pub_r000533_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_349_1 & 15;
  st_var_1_2.buffer[1] = stage_v_349_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_349_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_349_2) & 255;
  int sub_step_350_1 = ((sec_r000533_2_1 + pub_r000533_8_1) + 21) & 127;
  int sub_step_350_2 = ((sec_r000533_2_2 + pub_r000533_8_2) + 21) & 127;
  int stage_v_350_1 = ((sub_step_350_1 * 2) + pub_r000533_4_1) & 127;
  int stage_v_350_2 = ((sub_step_350_2 * 2) + pub_r000533_4_2) & 127;
  st_var_2_1.buffer[2] = stage_v_350_1 & 15;
  st_var_2_2.buffer[2] = stage_v_350_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_350_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_350_2) & 255;
  int sub_step_351_1 = ((stage_v_57_1 + pub_r000533_5_1) + 13) & 127;
  int sub_step_351_2 = ((stage_v_57_2 + pub_r000533_5_2) + 13) & 127;
  int stage_v_351_1 = ((sub_step_351_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_351_2 = ((sub_step_351_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_351_1 & 15;
  st_var_0_2.buffer[0] = stage_v_351_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_351_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_351_2) & 255;
  int sub_step_352_1 = ((sec_r000533_5_1 + pub_r000533_1_1) + 9) & 127;
  int sub_step_352_2 = ((sec_r000533_5_2 + pub_r000533_1_2) + 9) & 127;
  int stage_v_352_1 = ((sub_step_352_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_352_2 = ((sub_step_352_2 * 2) + pub_r000533_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_352_1 & 15;
  st_var_1_2.buffer[1] = stage_v_352_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_352_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_352_2) & 255;
  int sub_step_353_1 = ((sub_step_205_1 + pub_r000533_4_1) + 17) & 127;
  int sub_step_353_2 = ((sub_step_205_2 + pub_r000533_4_2) + 17) & 127;
  int stage_v_353_1 = ((sub_step_353_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_353_2 = ((sub_step_353_2 * 2) + pub_r000533_16_2) & 127;
  st_var_2_1.buffer[2] = stage_v_353_1 & 15;
  st_var_2_2.buffer[2] = stage_v_353_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_353_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_353_2) & 255;
  int sub_step_354_1 = ((stage_v_347_1 + pub_r000533_9_1) + 27) & 127;
  int sub_step_354_2 = ((stage_v_347_2 + pub_r000533_9_2) + 27) & 127;
  int stage_v_354_1 = ((sub_step_354_1 * 2) + pub_r000533_17_1) & 127;
  int stage_v_354_2 = ((sub_step_354_2 * 2) + pub_r000533_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_354_1 & 15;
  st_var_0_2.buffer[0] = stage_v_354_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_354_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_354_2) & 255;
  int sub_step_355_1 = ((sub_step_332_1 + pub_r000533_6_1) + 28) & 127;
  int sub_step_355_2 = ((sub_step_332_2 + pub_r000533_6_2) + 28) & 127;
  int stage_v_355_1 = ((sub_step_355_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_355_2 = ((sub_step_355_2 * 2) + pub_r000533_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_355_1 & 15;
  st_var_1_2.buffer[1] = stage_v_355_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_355_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_355_2) & 255;
  int sub_step_356_1 = ((stage_v_38_1 + pub_r000533_14_1) + 9) & 127;
  int sub_step_356_2 = ((stage_v_38_2 + pub_r000533_14_2) + 9) & 127;
  int stage_v_356_1 = ((sub_step_356_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_356_2 = ((sub_step_356_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_356_1 & 15;
  st_var_2_2.buffer[2] = stage_v_356_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_356_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_356_2) & 255;
  int sub_step_357_1 = ((sub_step_202_1 + pub_r000533_0_1) + 33) & 127;
  int sub_step_357_2 = ((sub_step_202_2 + pub_r000533_0_2) + 33) & 127;
  int stage_v_357_1 = ((sub_step_357_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_357_2 = ((sub_step_357_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_357_1 & 15;
  st_var_0_2.buffer[0] = stage_v_357_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_357_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_357_2) & 255;
  int sub_step_358_1 = ((sub_step_235_1 + pub_r000533_15_1) + 18) & 127;
  int sub_step_358_2 = ((sub_step_235_2 + pub_r000533_15_2) + 18) & 127;
  int stage_v_358_1 = ((sub_step_358_1 * 2) + pub_r000533_0_1) & 127;
  int stage_v_358_2 = ((sub_step_358_2 * 2) + pub_r000533_0_2) & 127;
  st_var_1_1.buffer[1] = stage_v_358_1 & 15;
  st_var_1_2.buffer[1] = stage_v_358_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_358_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_358_2) & 255;
  int sub_step_359_1 = ((sec_r000533_18_1 + pub_r000533_3_1) + 28) & 127;
  int sub_step_359_2 = ((sec_r000533_18_2 + pub_r000533_3_2) + 28) & 127;
  int stage_v_359_1 = ((sub_step_359_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_359_2 = ((sub_step_359_2 * 2) + pub_r000533_6_2) & 127;
  st_var_2_1.buffer[2] = stage_v_359_1 & 15;
  st_var_2_2.buffer[2] = stage_v_359_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_359_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_359_2) & 255;
  int sub_step_360_1 = ((sub_step_352_1 + pub_r000533_8_1) + 35) & 127;
  int sub_step_360_2 = ((sub_step_352_2 + pub_r000533_8_2) + 35) & 127;
  int stage_v_360_1 = ((sub_step_360_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_360_2 = ((sub_step_360_2 * 2) + pub_r000533_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_360_1 & 15;
  st_var_0_2.buffer[0] = stage_v_360_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_360_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_360_2) & 255;
  int sub_step_361_1 = ((stage_v_146_1 + pub_r000533_16_1) + 18) & 127;
  int sub_step_361_2 = ((stage_v_146_2 + pub_r000533_16_2) + 18) & 127;
  int stage_v_361_1 = ((sub_step_361_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_361_2 = ((sub_step_361_2 * 2) + pub_r000533_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_361_1 & 15;
  st_var_1_2.buffer[1] = stage_v_361_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_361_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_361_2) & 255;
  int sub_step_362_1 = ((stage_v_11_1 + pub_r000533_17_1) + 19) & 127;
  int sub_step_362_2 = ((stage_v_11_2 + pub_r000533_17_2) + 19) & 127;
  int stage_v_362_1 = ((sub_step_362_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_362_2 = ((sub_step_362_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_362_1 & 15;
  st_var_2_2.buffer[2] = stage_v_362_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_362_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_362_2) & 255;
  int sub_step_363_1 = ((sec_r000533_10_1 + pub_r000533_1_1) + 27) & 127;
  int sub_step_363_2 = ((sec_r000533_10_2 + pub_r000533_1_2) + 27) & 127;
  int stage_v_363_1 = ((sub_step_363_1 * 2) + pub_r000533_6_1) & 127;
  int stage_v_363_2 = ((sub_step_363_2 * 2) + pub_r000533_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_363_1 & 15;
  st_var_0_2.buffer[0] = stage_v_363_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_363_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_363_2) & 255;
  int sub_step_364_1 = ((sec_r000533_14_1 + pub_r000533_12_1) + 28) & 127;
  int sub_step_364_2 = ((sec_r000533_14_2 + pub_r000533_12_2) + 28) & 127;
  int stage_v_364_1 = ((sub_step_364_1 * 2) + pub_r000533_13_1) & 127;
  int stage_v_364_2 = ((sub_step_364_2 * 2) + pub_r000533_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_364_1 & 15;
  st_var_1_2.buffer[1] = stage_v_364_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_364_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_364_2) & 255;
  int sub_step_365_1 = ((sec_r000533_18_1 + pub_r000533_4_1) + 33) & 127;
  int sub_step_365_2 = ((sec_r000533_18_2 + pub_r000533_4_2) + 33) & 127;
  int stage_v_365_1 = ((sub_step_365_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_365_2 = ((sub_step_365_2 * 2) + pub_r000533_10_2) & 127;
  st_var_2_1.buffer[2] = stage_v_365_1 & 15;
  st_var_2_2.buffer[2] = stage_v_365_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_365_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_365_2) & 255;
  int sub_step_366_1 = ((sec_r000533_2_1 + pub_r000533_16_1) + 7) & 127;
  int sub_step_366_2 = ((sec_r000533_2_2 + pub_r000533_16_2) + 7) & 127;
  int stage_v_366_1 = ((sub_step_366_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_366_2 = ((sub_step_366_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_366_1 & 15;
  st_var_0_2.buffer[0] = stage_v_366_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_366_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_366_2) & 255;
  int sub_step_367_1 = ((sub_step_162_1 + pub_r000533_9_1) + 26) & 127;
  int sub_step_367_2 = ((sub_step_162_2 + pub_r000533_9_2) + 26) & 127;
  int stage_v_367_1 = ((sub_step_367_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_367_2 = ((sub_step_367_2 * 2) + pub_r000533_1_2) & 127;
  st_var_1_1.buffer[1] = stage_v_367_1 & 15;
  st_var_1_2.buffer[1] = stage_v_367_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_367_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_367_2) & 255;
  int sub_step_368_1 = ((stage_v_309_1 + pub_r000533_0_1) + 32) & 127;
  int sub_step_368_2 = ((stage_v_309_2 + pub_r000533_0_2) + 32) & 127;
  int stage_v_368_1 = ((sub_step_368_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_368_2 = ((sub_step_368_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_368_1 & 15;
  st_var_2_2.buffer[2] = stage_v_368_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_368_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_368_2) & 255;
  int sub_step_369_1 = ((sub_step_189_1 + pub_r000533_13_1) + 13) & 127;
  int sub_step_369_2 = ((sub_step_189_2 + pub_r000533_13_2) + 13) & 127;
  int stage_v_369_1 = ((sub_step_369_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_369_2 = ((sub_step_369_2 * 2) + pub_r000533_1_2) & 127;
  st_var_0_1.buffer[0] = stage_v_369_1 & 15;
  st_var_0_2.buffer[0] = stage_v_369_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_369_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_369_2) & 255;
  int sub_step_370_1 = ((stage_v_17_1 + pub_r000533_3_1) + 8) & 127;
  int sub_step_370_2 = ((stage_v_17_2 + pub_r000533_3_2) + 8) & 127;
  int stage_v_370_1 = ((sub_step_370_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_370_2 = ((sub_step_370_2 * 2) + pub_r000533_10_2) & 127;
  st_var_1_1.buffer[1] = stage_v_370_1 & 15;
  st_var_1_2.buffer[1] = stage_v_370_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_370_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_370_2) & 255;
  int sub_step_371_1 = ((sub_step_109_1 + pub_r000533_12_1) + 32) & 127;
  int sub_step_371_2 = ((sub_step_109_2 + pub_r000533_12_2) + 32) & 127;
  int stage_v_371_1 = ((sub_step_371_1 * 2) + pub_r000533_15_1) & 127;
  int stage_v_371_2 = ((sub_step_371_2 * 2) + pub_r000533_15_2) & 127;
  st_var_2_1.buffer[2] = stage_v_371_1 & 15;
  st_var_2_2.buffer[2] = stage_v_371_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_371_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_371_2) & 255;
  int sub_step_372_1 = ((sub_step_155_1 + pub_r000533_13_1) + 13) & 127;
  int sub_step_372_2 = ((sub_step_155_2 + pub_r000533_13_2) + 13) & 127;
  int stage_v_372_1 = ((sub_step_372_1 * 2) + pub_r000533_16_1) & 127;
  int stage_v_372_2 = ((sub_step_372_2 * 2) + pub_r000533_16_2) & 127;
  st_var_0_1.buffer[0] = stage_v_372_1 & 15;
  st_var_0_2.buffer[0] = stage_v_372_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_372_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_372_2) & 255;
  int sub_step_373_1 = ((sub_step_363_1 + pub_r000533_8_1) + 30) & 127;
  int sub_step_373_2 = ((sub_step_363_2 + pub_r000533_8_2) + 30) & 127;
  int stage_v_373_1 = ((sub_step_373_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_373_2 = ((sub_step_373_2 * 2) + pub_r000533_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_373_1 & 15;
  st_var_1_2.buffer[1] = stage_v_373_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_373_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_373_2) & 255;
  int sub_step_374_1 = ((stage_v_76_1 + pub_r000533_3_1) + 19) & 127;
  int sub_step_374_2 = ((stage_v_76_2 + pub_r000533_3_2) + 19) & 127;
  int stage_v_374_1 = ((sub_step_374_1 * 2) + pub_r000533_11_1) & 127;
  int stage_v_374_2 = ((sub_step_374_2 * 2) + pub_r000533_11_2) & 127;
  st_var_2_1.buffer[2] = stage_v_374_1 & 15;
  st_var_2_2.buffer[2] = stage_v_374_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_374_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_374_2) & 255;
  int sub_step_375_1 = ((stage_v_37_1 + pub_r000533_1_1) + 10) & 127;
  int sub_step_375_2 = ((stage_v_37_2 + pub_r000533_1_2) + 10) & 127;
  int stage_v_375_1 = ((sub_step_375_1 * 2) + pub_r000533_8_1) & 127;
  int stage_v_375_2 = ((sub_step_375_2 * 2) + pub_r000533_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_375_1 & 15;
  st_var_0_2.buffer[0] = stage_v_375_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_375_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_375_2) & 255;
  int sub_step_376_1 = ((sec_r000533_19_1 + pub_r000533_13_1) + 18) & 127;
  int sub_step_376_2 = ((sec_r000533_19_2 + pub_r000533_13_2) + 18) & 127;
  int stage_v_376_1 = ((sub_step_376_1 * 2) + pub_r000533_12_1) & 127;
  int stage_v_376_2 = ((sub_step_376_2 * 2) + pub_r000533_12_2) & 127;
  st_var_1_1.buffer[1] = stage_v_376_1 & 15;
  st_var_1_2.buffer[1] = stage_v_376_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_376_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_376_2) & 255;
  int sub_step_377_1 = ((sub_step_123_1 + pub_r000533_12_1) + 23) & 127;
  int sub_step_377_2 = ((sub_step_123_2 + pub_r000533_12_2) + 23) & 127;
  int stage_v_377_1 = ((sub_step_377_1 * 2) + pub_r000533_5_1) & 127;
  int stage_v_377_2 = ((sub_step_377_2 * 2) + pub_r000533_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_377_1 & 15;
  st_var_2_2.buffer[2] = stage_v_377_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_377_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_377_2) & 255;
  int sub_step_378_1 = ((sub_step_224_1 + pub_r000533_2_1) + 19) & 127;
  int sub_step_378_2 = ((sub_step_224_2 + pub_r000533_2_2) + 19) & 127;
  int stage_v_378_1 = ((sub_step_378_1 * 2) + pub_r000533_10_1) & 127;
  int stage_v_378_2 = ((sub_step_378_2 * 2) + pub_r000533_10_2) & 127;
  st_var_0_1.buffer[0] = stage_v_378_1 & 15;
  st_var_0_2.buffer[0] = stage_v_378_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_378_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_378_2) & 255;
  int sub_step_379_1 = ((stage_v_124_1 + pub_r000533_2_1) + 5) & 127;
  int sub_step_379_2 = ((stage_v_124_2 + pub_r000533_2_2) + 5) & 127;
  int stage_v_379_1 = ((sub_step_379_1 * 2) + pub_r000533_7_1) & 127;
  int stage_v_379_2 = ((sub_step_379_2 * 2) + pub_r000533_7_2) & 127;
  st_var_1_1.buffer[1] = stage_v_379_1 & 15;
  st_var_1_2.buffer[1] = stage_v_379_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_379_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_379_2) & 255;
  int sub_step_380_1 = ((sec_r000533_7_1 + pub_r000533_13_1) + 28) & 127;
  int sub_step_380_2 = ((sec_r000533_7_2 + pub_r000533_13_2) + 28) & 127;
  int stage_v_380_1 = ((sub_step_380_1 * 2) + pub_r000533_1_1) & 127;
  int stage_v_380_2 = ((sub_step_380_2 * 2) + pub_r000533_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_380_1 & 15;
  st_var_2_2.buffer[2] = stage_v_380_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_380_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_380_2) & 255;
  int sub_step_381_1 = ((sec_r000533_0_1 + pub_r000533_13_1) + 22) & 127;
  int sub_step_381_2 = ((sec_r000533_0_2 + pub_r000533_13_2) + 22) & 127;
  int stage_v_381_1 = ((sub_step_381_1 * 2) + pub_r000533_2_1) & 127;
  int stage_v_381_2 = ((sub_step_381_2 * 2) + pub_r000533_2_2) & 127;
  st_var_0_1.buffer[0] = stage_v_381_1 & 15;
  st_var_0_2.buffer[0] = stage_v_381_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_381_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_381_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000533_7_1 == pub_r000533_7_2);
  __CPROVER_assume(sec_r000533_13_1 != sec_r000533_13_2);
  __CPROVER_assume(sec_r000533_5_1 != sec_r000533_5_2);
  __CPROVER_assume(sec_r000533_6_1 != sec_r000533_6_2);
  __CPROVER_assume(sec_r000533_4_1 != sec_r000533_4_2);
  __CPROVER_assume(sec_r000533_19_1 != sec_r000533_19_2);
  __CPROVER_assume(sec_r000533_1_1 != sec_r000533_1_2);
  __CPROVER_assume(sec_r000533_7_1 != sec_r000533_7_2);
  __CPROVER_assume(sec_r000533_17_1 != sec_r000533_17_2);
  __CPROVER_assume(pub_r000533_3_1 == pub_r000533_3_2);
  __CPROVER_assume(pub_r000533_17_1 == pub_r000533_17_2);
  __CPROVER_assume(pub_r000533_13_1 == pub_r000533_13_2);
  __CPROVER_assume(pub_r000533_6_1 == pub_r000533_6_2);
  __CPROVER_assume(pub_r000533_10_1 == pub_r000533_10_2);
  __CPROVER_assume(sec_r000533_12_1 != sec_r000533_12_2);
  __CPROVER_assume(sec_r000533_14_1 != sec_r000533_14_2);
  __CPROVER_assume(sec_r000533_18_1 != sec_r000533_18_2);
  __CPROVER_assume(pub_r000533_9_1 == pub_r000533_9_2);
  __CPROVER_assume(pub_r000533_8_1 == pub_r000533_8_2);
  __CPROVER_assume(sec_r000533_0_1 != sec_r000533_0_2);
  __CPROVER_assume(pub_r000533_1_1 == pub_r000533_1_2);
  __CPROVER_assume(pub_r000533_16_1 == pub_r000533_16_2);
  __CPROVER_assume(sec_r000533_3_1 != sec_r000533_3_2);
  __CPROVER_assume(pub_r000533_0_1 == pub_r000533_0_2);
  __CPROVER_assume(sec_r000533_2_1 != sec_r000533_2_2);
  __CPROVER_assume(sec_r000533_10_1 != sec_r000533_10_2);
  __CPROVER_assume(sec_r000533_11_1 != sec_r000533_11_2);
  __CPROVER_assume(pub_r000533_15_1 == pub_r000533_15_2);
  __CPROVER_assume(pub_r000533_11_1 == pub_r000533_11_2);
  __CPROVER_assume(pub_r000533_12_1 == pub_r000533_12_2);
  __CPROVER_assume(pub_r000533_14_1 == pub_r000533_14_2);
  __CPROVER_assume(sec_r000533_16_1 != sec_r000533_16_2);
  __CPROVER_assume(pub_r000533_2_1 == pub_r000533_2_2);
  __CPROVER_assume(sec_r000533_20_1 != sec_r000533_20_2);
  __CPROVER_assume(sec_r000533_15_1 != sec_r000533_15_2);
  __CPROVER_assume(pub_r000533_4_1 == pub_r000533_4_2);
  __CPROVER_assume(sec_r000533_9_1 != sec_r000533_9_2);
  __CPROVER_assume(sec_r000533_8_1 != sec_r000533_8_2);
  __CPROVER_assume(sec_r000533_21_1 != sec_r000533_21_2);
  __CPROVER_assume(pub_r000533_5_1 == pub_r000533_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.determinant == st_var_2_2.determinant);
  assert(st_var_2_1.density == st_var_2_2.density);
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
  assert(sub_step_7_1 == sub_step_7_2);
  assert(stage_v_7_1 == stage_v_7_2);
  assert(sub_step_8_1 == sub_step_8_2);
  assert(stage_v_8_1 == stage_v_8_2);
  assert(sub_step_9_1 == sub_step_9_2);
  assert(stage_v_9_1 == stage_v_9_2);
  assert(sub_step_10_1 == sub_step_10_2);
  assert(stage_v_10_1 == stage_v_10_2);
  assert(sub_step_11_1 == sub_step_11_2);
  assert(stage_v_11_1 == stage_v_11_2);
  assert(sub_step_12_1 == sub_step_12_2);
  assert(stage_v_12_1 == stage_v_12_2);
  assert(sub_step_13_1 == sub_step_13_2);
  assert(stage_v_13_1 == stage_v_13_2);
  assert(sub_step_14_1 == sub_step_14_2);
  assert(stage_v_14_1 == stage_v_14_2);
  assert(sub_step_15_1 == sub_step_15_2);
  assert(stage_v_15_1 == stage_v_15_2);
  assert(sub_step_16_1 == sub_step_16_2);
  assert(stage_v_16_1 == stage_v_16_2);
  assert(sub_step_17_1 == sub_step_17_2);
  assert(stage_v_17_1 == stage_v_17_2);
  assert(sub_step_18_1 == sub_step_18_2);
  assert(stage_v_18_1 == stage_v_18_2);
  assert(sub_step_19_1 == sub_step_19_2);
  assert(stage_v_19_1 == stage_v_19_2);
  assert(sub_step_20_1 == sub_step_20_2);
  assert(stage_v_20_1 == stage_v_20_2);
  assert(sub_step_21_1 == sub_step_21_2);
  assert(stage_v_21_1 == stage_v_21_2);
  assert(sub_step_22_1 == sub_step_22_2);
  assert(stage_v_22_1 == stage_v_22_2);
  assert(sub_step_23_1 == sub_step_23_2);
  assert(stage_v_23_1 == stage_v_23_2);
  assert(sub_step_24_1 == sub_step_24_2);
  assert(stage_v_24_1 == stage_v_24_2);
  assert(sub_step_25_1 == sub_step_25_2);
  assert(stage_v_25_1 == stage_v_25_2);
  assert(sub_step_26_1 == sub_step_26_2);
  assert(stage_v_26_1 == stage_v_26_2);
  assert(sub_step_27_1 == sub_step_27_2);
  assert(stage_v_27_1 == stage_v_27_2);
  assert(sub_step_28_1 == sub_step_28_2);
  assert(stage_v_28_1 == stage_v_28_2);
  assert(sub_step_29_1 == sub_step_29_2);
  assert(stage_v_29_1 == stage_v_29_2);
  assert(sub_step_30_1 == sub_step_30_2);
  assert(stage_v_30_1 == stage_v_30_2);
  assert(sub_step_31_1 == sub_step_31_2);
  assert(stage_v_31_1 == stage_v_31_2);
  assert(sub_step_32_1 == sub_step_32_2);
  assert(stage_v_32_1 == stage_v_32_2);
  assert(sub_step_33_1 == sub_step_33_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(sub_step_34_1 == sub_step_34_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(sub_step_35_1 == sub_step_35_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(sub_step_36_1 == sub_step_36_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(sub_step_37_1 == sub_step_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(sub_step_38_1 == sub_step_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(sub_step_39_1 == sub_step_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(sub_step_40_1 == sub_step_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(sub_step_41_1 == sub_step_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(sub_step_42_1 == sub_step_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(sub_step_43_1 == sub_step_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(sub_step_44_1 == sub_step_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(sub_step_45_1 == sub_step_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(sub_step_46_1 == sub_step_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(sub_step_47_1 == sub_step_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(sub_step_48_1 == sub_step_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(sub_step_49_1 == sub_step_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(sub_step_50_1 == sub_step_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(sub_step_51_1 == sub_step_51_2);
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
  assert(sub_step_306_1 == sub_step_306_2);
  assert(stage_v_306_1 == stage_v_306_2);
  assert(sub_step_307_1 == sub_step_307_2);
  assert(stage_v_307_1 == stage_v_307_2);
  assert(sub_step_308_1 == sub_step_308_2);
  assert(stage_v_308_1 == stage_v_308_2);
  assert(sub_step_309_1 == sub_step_309_2);
  assert(stage_v_309_1 == stage_v_309_2);
  assert(sub_step_310_1 == sub_step_310_2);
  assert(stage_v_310_1 == stage_v_310_2);
  assert(sub_step_311_1 == sub_step_311_2);
  assert(stage_v_311_1 == stage_v_311_2);
  assert(sub_step_312_1 == sub_step_312_2);
  assert(stage_v_312_1 == stage_v_312_2);
  assert(sub_step_313_1 == sub_step_313_2);
  assert(stage_v_313_1 == stage_v_313_2);
  assert(sub_step_314_1 == sub_step_314_2);
  assert(stage_v_314_1 == stage_v_314_2);
  assert(sub_step_315_1 == sub_step_315_2);
  assert(stage_v_315_1 == stage_v_315_2);
  assert(sub_step_316_1 == sub_step_316_2);
  assert(stage_v_316_1 == stage_v_316_2);
  assert(sub_step_317_1 == sub_step_317_2);
  assert(stage_v_317_1 == stage_v_317_2);
  assert(sub_step_318_1 == sub_step_318_2);
  assert(stage_v_318_1 == stage_v_318_2);
  assert(sub_step_319_1 == sub_step_319_2);
  assert(stage_v_319_1 == stage_v_319_2);
  assert(sub_step_320_1 == sub_step_320_2);
  assert(stage_v_320_1 == stage_v_320_2);
  assert(sub_step_321_1 == sub_step_321_2);
  assert(stage_v_321_1 == stage_v_321_2);
  assert(sub_step_322_1 == sub_step_322_2);
  assert(stage_v_322_1 == stage_v_322_2);
  assert(sub_step_323_1 == sub_step_323_2);
  assert(stage_v_323_1 == stage_v_323_2);
  assert(sub_step_324_1 == sub_step_324_2);
  assert(stage_v_324_1 == stage_v_324_2);
  assert(sub_step_325_1 == sub_step_325_2);
  assert(stage_v_325_1 == stage_v_325_2);
  assert(sub_step_326_1 == sub_step_326_2);
  assert(stage_v_326_1 == stage_v_326_2);
  assert(sub_step_327_1 == sub_step_327_2);
  assert(stage_v_327_1 == stage_v_327_2);
  assert(sub_step_328_1 == sub_step_328_2);
  assert(stage_v_328_1 == stage_v_328_2);
  assert(sub_step_329_1 == sub_step_329_2);
  assert(stage_v_329_1 == stage_v_329_2);
  assert(sub_step_330_1 == sub_step_330_2);
  assert(stage_v_330_1 == stage_v_330_2);
  assert(sub_step_331_1 == sub_step_331_2);
  assert(stage_v_331_1 == stage_v_331_2);
  assert(sub_step_332_1 == sub_step_332_2);
  assert(stage_v_332_1 == stage_v_332_2);
  assert(sub_step_333_1 == sub_step_333_2);
  assert(stage_v_333_1 == stage_v_333_2);
  assert(sub_step_334_1 == sub_step_334_2);
  assert(stage_v_334_1 == stage_v_334_2);
  assert(sub_step_335_1 == sub_step_335_2);
  assert(stage_v_335_1 == stage_v_335_2);
  assert(sub_step_336_1 == sub_step_336_2);
  assert(stage_v_336_1 == stage_v_336_2);
  assert(sub_step_337_1 == sub_step_337_2);
  assert(stage_v_337_1 == stage_v_337_2);
  assert(sub_step_338_1 == sub_step_338_2);
  assert(stage_v_338_1 == stage_v_338_2);
  assert(sub_step_339_1 == sub_step_339_2);
  assert(stage_v_339_1 == stage_v_339_2);
  assert(sub_step_340_1 == sub_step_340_2);
  assert(stage_v_340_1 == stage_v_340_2);
  assert(sub_step_341_1 == sub_step_341_2);
  assert(stage_v_341_1 == stage_v_341_2);
  assert(sub_step_342_1 == sub_step_342_2);
  assert(stage_v_342_1 == stage_v_342_2);
  assert(sub_step_343_1 == sub_step_343_2);
  assert(stage_v_343_1 == stage_v_343_2);
  assert(sub_step_344_1 == sub_step_344_2);
  assert(stage_v_344_1 == stage_v_344_2);
  assert(sub_step_345_1 == sub_step_345_2);
  assert(stage_v_345_1 == stage_v_345_2);
  assert(sub_step_346_1 == sub_step_346_2);
  assert(stage_v_346_1 == stage_v_346_2);
  assert(sub_step_347_1 == sub_step_347_2);
  assert(stage_v_347_1 == stage_v_347_2);
  assert(sub_step_348_1 == sub_step_348_2);
  assert(stage_v_348_1 == stage_v_348_2);
  assert(sub_step_349_1 == sub_step_349_2);
  assert(stage_v_349_1 == stage_v_349_2);
  assert(sub_step_350_1 == sub_step_350_2);
  assert(stage_v_350_1 == stage_v_350_2);
  assert(sub_step_351_1 == sub_step_351_2);
  assert(stage_v_351_1 == stage_v_351_2);
  assert(sub_step_352_1 == sub_step_352_2);
  assert(stage_v_352_1 == stage_v_352_2);
  assert(sub_step_353_1 == sub_step_353_2);
  assert(stage_v_353_1 == stage_v_353_2);
  assert(sub_step_354_1 == sub_step_354_2);
  assert(stage_v_354_1 == stage_v_354_2);
  assert(sub_step_355_1 == sub_step_355_2);
  assert(stage_v_355_1 == stage_v_355_2);
  assert(sub_step_356_1 == sub_step_356_2);
  assert(stage_v_356_1 == stage_v_356_2);
  assert(sub_step_357_1 == sub_step_357_2);
  assert(stage_v_357_1 == stage_v_357_2);
  assert(sub_step_358_1 == sub_step_358_2);
  assert(stage_v_358_1 == stage_v_358_2);
  assert(sub_step_359_1 == sub_step_359_2);
  assert(stage_v_359_1 == stage_v_359_2);
  assert(sub_step_360_1 == sub_step_360_2);
  assert(stage_v_360_1 == stage_v_360_2);
  assert(sub_step_361_1 == sub_step_361_2);
  assert(stage_v_361_1 == stage_v_361_2);
  assert(sub_step_362_1 == sub_step_362_2);
  assert(stage_v_362_1 == stage_v_362_2);
  assert(sub_step_363_1 == sub_step_363_2);
  assert(stage_v_363_1 == stage_v_363_2);
  assert(sub_step_364_1 == sub_step_364_2);
  assert(stage_v_364_1 == stage_v_364_2);
  assert(sub_step_365_1 == sub_step_365_2);
  assert(stage_v_365_1 == stage_v_365_2);
  assert(sub_step_366_1 == sub_step_366_2);
  assert(stage_v_366_1 == stage_v_366_2);
  assert(sub_step_367_1 == sub_step_367_2);
  assert(stage_v_367_1 == stage_v_367_2);
  assert(sub_step_368_1 == sub_step_368_2);
  assert(stage_v_368_1 == stage_v_368_2);
  assert(sub_step_369_1 == sub_step_369_2);
  assert(stage_v_369_1 == stage_v_369_2);
  assert(sub_step_370_1 == sub_step_370_2);
  assert(stage_v_370_1 == stage_v_370_2);
  assert(sub_step_371_1 == sub_step_371_2);
  assert(stage_v_371_1 == stage_v_371_2);
  assert(sub_step_372_1 == sub_step_372_2);
  assert(stage_v_372_1 == stage_v_372_2);
  assert(sub_step_373_1 == sub_step_373_2);
  assert(stage_v_373_1 == stage_v_373_2);
  assert(sub_step_374_1 == sub_step_374_2);
  assert(stage_v_374_1 == stage_v_374_2);
  assert(sub_step_375_1 == sub_step_375_2);
  assert(stage_v_375_1 == stage_v_375_2);
  assert(sub_step_376_1 == sub_step_376_2);
  assert(stage_v_376_1 == stage_v_376_2);
  assert(sub_step_377_1 == sub_step_377_2);
  assert(stage_v_377_1 == stage_v_377_2);
  assert(sub_step_378_1 == sub_step_378_2);
  assert(stage_v_378_1 == stage_v_378_2);
  assert(sub_step_379_1 == sub_step_379_2);
  assert(stage_v_379_1 == stage_v_379_2);
  assert(sub_step_380_1 == sub_step_380_2);
  assert(stage_v_380_1 == stage_v_380_2);
  assert(sub_step_381_1 == sub_step_381_2);
  assert(stage_v_381_1 == stage_v_381_2);
}


