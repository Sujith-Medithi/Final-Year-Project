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
struct CipherContext_R001120_2013_0
{
  int nonce;
  short round_key;
  short flags;
  int buffer[3];
};
struct AudioFrame_R001120_2013_1
{
  int peak;
  int envelope;
  short sample_rate;
  int rms;
  int buffer[3];
};
struct EventLog_R001120_2013_2
{
  unsigned char code;
  unsigned char severity;
  int signature;
  int buffer[3];
};
union TelemetryField_R001120_2013_0
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
void fn_R001120_2013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_44_1 = local_arr_1[aux_1 % 3];
  int factor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_44_1 == factor_44_2);
}

int fn_R001120_2013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int factor_44 = local_arr[aux % 3];
  acc = (acc + (factor_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_19_1 = local_arr_1[aux_1 % 3];
  int delta_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_19_2 * 2)) & 127;
  int segment_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_81_1)
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

  switch (segment_81_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_60_1) & 63;
  aux_2 = (aux_2 + weight_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(segment_81_1 == segment_81_2);
  assert(weight_60_1 == weight_60_2);
}

int fn_R001120_2013_1(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int delta_19 = local_arr[aux % 3];
  acc = (acc + (delta_19 * 2)) & 127;
  int segment_81 = (aux + st.buffer[1]) & 3;
  switch (segment_81)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001120_2013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quantum_56_1 = 0;
  int quantum_56_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_56_1 = ((quantum_56_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_56_2 = ((quantum_56_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_56_1) & 127;
    acc_2 = (acc_2 + quantum_56_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_82_1 = local_arr_1[aux_1 % 3];
  int cursor_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_56_1 == quantum_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_82_1 == cursor_82_2);
}

int fn_R001120_2013_2(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quantum_56 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_56 = ((quantum_56 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_56) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_82 = local_arr[aux % 3];
  acc = (acc + (cursor_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int coefficient_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_31_1 > 13)
  {
    acc_1 = ((acc_1 + (coefficient_31_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_31_2 > 13)
  {
    acc_2 = ((acc_2 + (coefficient_31_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_68_1 = local_arr_1[aux_1 % 3];
  int sample_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_31_1 == coefficient_31_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_68_1 == sample_68_2);
}

int fn_R001120_2013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int coefficient_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_31 > 13)
  {
    acc = ((acc + (coefficient_31 * 2)) + 5) & 127;
    aux ^= coefficient_31 & 15;
  }
  else
  {
    acc = ((acc - coefficient_31) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_68 = local_arr[aux % 3];
  acc = (acc + (sample_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_48_1 = local_arr_1[aux_1 % 3];
  int vector_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_48_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_48_1 == vector_48_2);
}

int fn_R001120_2013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int vector_48 = local_arr[aux % 3];
  acc = (acc + (vector_48 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int segment_66_1 = 0;
  int segment_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_66_1 = ((segment_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_66_2 = ((segment_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_66_1) & 127;
    acc_2 = (acc_2 + segment_66_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_66_1 == segment_66_2);
}

int fn_R001120_2013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int segment_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_66 = ((segment_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_66) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
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
  int quotient_56_1 = local_arr_1[aux_1 % 3];
  int quotient_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_56_2 * 2)) & 127;
  int bound_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_67_1) & 63;
  aux_2 = (aux_2 + bound_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_56_1 == quotient_56_2);
  assert(bound_67_1 == bound_67_2);
}

int fn_R001120_2013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_56 = local_arr[aux % 3];
  acc = (acc + (quotient_56 * 2)) & 127;
  int bound_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_67) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001120_2013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int offset_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_37_1 > 30)
  {
    acc_1 = ((acc_1 + (offset_37_1 * 2)) + 5) & 127;
    aux_1 ^= offset_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_37_2 > 30)
  {
    acc_2 = ((acc_2 + (offset_37_2 * 2)) + 5) & 127;
    aux_2 ^= offset_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int checksum_33_1 = 0;
  int checksum_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_33_1 = ((checksum_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_33_2 = ((checksum_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_33_1) & 127;
    acc_2 = (acc_2 + checksum_33_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_66_1 = local_arr_1[aux_1 % 3];
  int phase_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_37_1 == offset_37_2);
  assert(checksum_33_1 == checksum_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_66_1 == phase_66_2);
}

int fn_R001120_2013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int offset_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_37 > 30)
  {
    acc = ((acc + (offset_37 * 2)) + 5) & 127;
    aux ^= offset_37 & 15;
  }
  else
  {
    acc = ((acc - offset_37) + 11) & 127;
    aux += 3;
  }
  int checksum_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_33 = ((checksum_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_33) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_66 = local_arr[aux % 3];
  acc = (acc + (phase_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int mask_97_1 = 0;
  int mask_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_97_1 = ((mask_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_97_2 = ((mask_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_97_1) & 127;
    acc_2 = (acc_2 + mask_97_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_89_1 > 35)
  {
    acc_1 = ((acc_1 + (scale_89_1 * 2)) + 5) & 127;
    aux_1 ^= scale_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_89_2 > 35)
  {
    acc_2 = ((acc_2 + (scale_89_2 * 2)) + 5) & 127;
    aux_2 ^= scale_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_97_1 == mask_97_2);
  assert(scale_89_1 == scale_89_2);
}

int fn_R001120_2013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int mask_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_97 = ((mask_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_97) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_89 > 35)
  {
    acc = ((acc + (scale_89 * 2)) + 5) & 127;
    aux ^= scale_89 & 15;
  }
  else
  {
    acc = ((acc - scale_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001120_2013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_56_1) & 63;
  aux_2 = (aux_2 + quantum_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_90_1 > 33)
  {
    acc_1 = ((acc_1 + (phase_90_1 * 2)) + 5) & 127;
    aux_1 ^= phase_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_90_2 > 33)
  {
    acc_2 = ((acc_2 + (phase_90_2 * 2)) + 5) & 127;
    aux_2 ^= phase_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_42_1 = 0;
  int pivot_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_42_1 = ((pivot_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_42_2 = ((pivot_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_42_1) & 127;
    acc_2 = (acc_2 + pivot_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_56_1 == quantum_56_2);
  assert(phase_90_1 == phase_90_2);
  assert(pivot_42_1 == pivot_42_2);
}

int fn_R001120_2013_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_56) & 63;
  acc ^= aux;
  int phase_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_90 > 33)
  {
    acc = ((acc + (phase_90 * 2)) + 5) & 127;
    aux ^= phase_90 & 15;
  }
  else
  {
    acc = ((acc - phase_90) + 11) & 127;
    aux += 3;
  }
  int pivot_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_42 = ((pivot_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001120_2013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quotient_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_40_1)
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

  switch (quotient_40_2)
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

  int damping_50_1 = 0;
  int damping_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_50_1 = ((damping_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_50_2 = ((damping_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_50_1) & 127;
    acc_2 = (acc_2 + damping_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_40_1 == quotient_40_2);
  assert(damping_50_1 == damping_50_2);
}

int fn_R001120_2013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quotient_40 = (aux + st.buffer[1]) & 3;
  switch (quotient_40)
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

  int damping_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_50 = ((damping_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001120_2013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int pivot_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_29_1 > 30)
  {
    acc_1 = ((acc_1 + (pivot_29_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_29_2 > 30)
  {
    acc_2 = ((acc_2 + (pivot_29_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_13_1 = local_arr_1[aux_1 % 3];
  int index_reg_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_13_2 * 2)) & 127;
  int bound_95_1 = 0;
  int bound_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_95_1 = ((bound_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_95_2 = ((bound_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_95_1) & 127;
    acc_2 = (acc_2 + bound_95_2) & 127;
  }

  int pivot_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_26_1)
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

  switch (pivot_26_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_29_1 == pivot_29_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_13_1 == index_reg_13_2);
  assert(bound_95_1 == bound_95_2);
  assert(pivot_26_1 == pivot_26_2);
}

int fn_R001120_2013_11(int p0, int p1)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int pivot_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_29 > 30)
  {
    acc = ((acc + (pivot_29 * 2)) + 5) & 127;
    aux ^= pivot_29 & 15;
  }
  else
  {
    acc = ((acc - pivot_29) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_13 = local_arr[aux % 3];
  acc = (acc + (index_reg_13 * 2)) & 127;
  int bound_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_95 = ((bound_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_95) & 127;
  }

  int pivot_26 = (aux + st.buffer[1]) & 3;
  switch (pivot_26)
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

void fn_R001120_2013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tally_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_82_1)
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

  switch (tally_82_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_89_1 = local_arr_1[aux_1 % 3];
  int quantum_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_89_2 * 2)) & 127;
  int threshold_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_43_1) & 63;
  aux_2 = (aux_2 + threshold_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_82_1 == tally_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_89_1 == quantum_89_2);
  assert(threshold_43_1 == threshold_43_2);
}

int fn_R001120_2013_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tally_82 = (aux + st.buffer[1]) & 3;
  switch (tally_82)
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
  int local_arr[3] = {4, 9, 15};
  int quantum_89 = local_arr[aux % 3];
  acc = (acc + (quantum_89 * 2)) & 127;
  int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_43) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001120_2013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_76_1) & 63;
  aux_2 = (aux_2 + parity_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_49_1 = local_arr_1[aux_1 % 3];
  int quotient_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_49_2 * 2)) & 127;
  int offset_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_30_1)
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

  switch (offset_30_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_76_1 == parity_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_49_1 == quotient_49_2);
  assert(offset_30_1 == offset_30_2);
}

int fn_R001120_2013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_76) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_49 = local_arr[aux % 3];
  acc = (acc + (quotient_49 * 2)) & 127;
  int offset_30 = (aux + st.buffer[1]) & 3;
  switch (offset_30)
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

void fn_R001120_2013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int residue_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_13_1)
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

  switch (residue_13_2)
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

  int quantum_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_89_1 > 18)
  {
    acc_1 = ((acc_1 + (quantum_89_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_89_2 > 18)
  {
    acc_2 = ((acc_2 + (quantum_89_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_43_1 = local_arr_1[aux_1 % 3];
  int vector_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_43_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_13_1 == residue_13_2);
  assert(quantum_89_1 == quantum_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_43_1 == vector_43_2);
}

int fn_R001120_2013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int residue_13 = (aux + st.buffer[1]) & 3;
  switch (residue_13)
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

  int quantum_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_89 > 18)
  {
    acc = ((acc + (quantum_89 * 2)) + 5) & 127;
    aux ^= quantum_89 & 15;
  }
  else
  {
    acc = ((acc - quantum_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_43 = local_arr[aux % 3];
  acc = (acc + (vector_43 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int scale_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_89_1 > 45)
  {
    acc_1 = ((acc_1 + (scale_89_1 * 2)) + 5) & 127;
    aux_1 ^= scale_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_89_2 > 45)
  {
    acc_2 = ((acc_2 + (scale_89_2 * 2)) + 5) & 127;
    aux_2 ^= scale_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_75_1 = local_arr_1[aux_1 % 3];
  int delta_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_75_2 * 2)) & 127;
  int pivot_69_1 = 0;
  int pivot_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_69_1 = ((pivot_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_69_2 = ((pivot_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_69_1) & 127;
    acc_2 = (acc_2 + pivot_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_89_1 == scale_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_75_1 == delta_75_2);
  assert(pivot_69_1 == pivot_69_2);
}

int fn_R001120_2013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int scale_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_89 > 45)
  {
    acc = ((acc + (scale_89 * 2)) + 5) & 127;
    aux ^= scale_89 & 15;
  }
  else
  {
    acc = ((acc - scale_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_75 = local_arr[aux % 3];
  acc = (acc + (delta_75 * 2)) & 127;
  int pivot_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_69 = ((pivot_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001120_2013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_32_1 = 0;
  int phase_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_32_1 = ((phase_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_32_2 = ((phase_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_32_1) & 127;
    acc_2 = (acc_2 + phase_32_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_82_1)
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

  switch (accumulator_82_2)
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
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  assert(accumulator_82_1 == accumulator_82_2);
}

int fn_R001120_2013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_32 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_32 = ((phase_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_32) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_82 = (aux + st.buffer[1]) & 3;
  switch (accumulator_82)
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

void fn_R001120_2013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_24_1) & 63;
  aux_2 = (aux_2 + parity_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_78_1 = 0;
  int stride_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_78_1 = ((stride_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_78_2 = ((stride_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_78_1) & 127;
    acc_2 = (acc_2 + stride_78_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_24_1 == parity_24_2);
  assert(stride_78_1 == stride_78_2);
}

int fn_R001120_2013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_24) & 63;
  acc ^= aux;
  int stride_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_78 = ((stride_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_78) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001120_2013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_65_1)
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

  switch (tracker_65_2)
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

  int coefficient_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_84_1) & 63;
  aux_2 = (aux_2 + coefficient_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_91_1 > 20)
  {
    acc_1 = ((acc_1 + (vector_91_1 * 2)) + 5) & 127;
    aux_1 ^= vector_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_91_2 > 20)
  {
    acc_2 = ((acc_2 + (vector_91_2 * 2)) + 5) & 127;
    aux_2 ^= vector_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_91_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_65_1 == tracker_65_2);
  assert(coefficient_84_1 == coefficient_84_2);
  assert(vector_91_1 == vector_91_2);
}

int fn_R001120_2013_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_65 = (aux + st.buffer[1]) & 3;
  switch (tracker_65)
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

  int coefficient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_84) & 63;
  acc ^= aux;
  int vector_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_91 > 20)
  {
    acc = ((acc + (vector_91 * 2)) + 5) & 127;
    aux ^= vector_91 & 15;
  }
  else
  {
    acc = ((acc - vector_91) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001120_2013_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_76_1)
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

  switch (mask_76_2)
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

  int residue_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_30_1) & 63;
  aux_2 = (aux_2 + residue_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_23_1 = local_arr_1[aux_1 % 3];
  int residue_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_23_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_76_1 == mask_76_2);
  assert(residue_30_1 == residue_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_23_1 == residue_23_2);
}

int fn_R001120_2013_19(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_76 = (aux + st.buffer[1]) & 3;
  switch (mask_76)
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

  int residue_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int residue_23 = local_arr[aux % 3];
  acc = (acc + (residue_23 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001120_2013_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st_1 = {0};
  struct CipherContext_R001120_2013_0 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_19_1 = local_arr_1[aux_1 % 3];
  int threshold_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_19_2 * 2)) & 127;
  int threshold_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_97_1) & 63;
  aux_2 = (aux_2 + threshold_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.flags == st_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_19_1 == threshold_19_2);
  assert(threshold_97_1 == threshold_97_2);
}

int fn_R001120_2013_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001120_2013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_19 = local_arr[aux % 3];
  acc = (acc + (threshold_19 * 2)) & 127;
  int threshold_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001120_2013_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_74_1) & 63;
  aux_2 = (aux_2 + index_reg_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_83_1 = 0;
  int tally_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_83_1 = ((tally_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_83_2 = ((tally_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_83_1) & 127;
    acc_2 = (acc_2 + tally_83_2) & 127;
  }

  int window_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_16_1)
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

  switch (window_16_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_74_1 == index_reg_74_2);
  assert(tally_83_1 == tally_83_2);
  assert(window_16_1 == window_16_2);
}

int fn_R001120_2013_21(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_74) & 63;
  acc ^= aux;
  int tally_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_83 = ((tally_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_83) & 127;
  }

  int window_16 = (aux + st.buffer[1]) & 3;
  switch (window_16)
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

void fn_R001120_2013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st_1 = {0};
  struct EventLog_R001120_2013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_43_1 > 16)
  {
    acc_1 = ((acc_1 + (mask_43_1 * 2)) + 5) & 127;
    aux_1 ^= mask_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_43_2 > 16)
  {
    acc_2 = ((acc_2 + (mask_43_2 * 2)) + 5) & 127;
    aux_2 ^= mask_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_47_1) & 63;
  aux_2 = (aux_2 + threshold_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_43_1 == mask_43_2);
  assert(threshold_47_1 == threshold_47_2);
}

int fn_R001120_2013_22(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001120_2013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_43 > 16)
  {
    acc = ((acc + (mask_43 * 2)) + 5) & 127;
    aux ^= mask_43 & 15;
  }
  else
  {
    acc = ((acc - mask_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001120_2013_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st_1 = {0};
  struct AudioFrame_R001120_2013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int bound_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_37_1)
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

  switch (bound_37_2)
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

  int margin_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_11_1) & 63;
  aux_2 = (aux_2 + margin_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_37_1 == bound_37_2);
  assert(margin_11_1 == margin_11_2);
}

int fn_R001120_2013_23(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001120_2013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int bound_37 = (aux + st.buffer[1]) & 3;
  switch (bound_37)
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

  int margin_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001120_0_1;
  int sec_r001120_0_2;
  int sec_r001120_1_1;
  int sec_r001120_1_2;
  int sec_r001120_2_1;
  int sec_r001120_2_2;
  int sec_r001120_3_1;
  int sec_r001120_3_2;
  int sec_r001120_4_1;
  int sec_r001120_4_2;
  int sec_r001120_5_1;
  int sec_r001120_5_2;
  int sec_r001120_6_1;
  int sec_r001120_6_2;
  int sec_r001120_7_1;
  int sec_r001120_7_2;
  int sec_r001120_8_1;
  int sec_r001120_8_2;
  int sec_r001120_9_1;
  int sec_r001120_9_2;
  int sec_r001120_10_1;
  int sec_r001120_10_2;
  int sec_r001120_11_1;
  int sec_r001120_11_2;
  int sec_r001120_12_1;
  int sec_r001120_12_2;
  int sec_r001120_13_1;
  int sec_r001120_13_2;
  int sec_r001120_14_1;
  int sec_r001120_14_2;
  int sec_r001120_15_1;
  int sec_r001120_15_2;
  int sec_r001120_16_1;
  int sec_r001120_16_2;
  int sec_r001120_17_1;
  int sec_r001120_17_2;
  int sec_r001120_18_1;
  int sec_r001120_18_2;
  int sec_r001120_19_1;
  int sec_r001120_19_2;
  int sec_r001120_20_1;
  int sec_r001120_20_2;
  int sec_r001120_21_1;
  int sec_r001120_21_2;
  int sec_r001120_22_1;
  int sec_r001120_22_2;
  int sec_r001120_23_1;
  int sec_r001120_23_2;
  int pub_r001120_0_1;
  int pub_r001120_0_2;
  int pub_r001120_1_1;
  int pub_r001120_1_2;
  int pub_r001120_2_1;
  int pub_r001120_2_2;
  int pub_r001120_3_1;
  int pub_r001120_3_2;
  int pub_r001120_4_1;
  int pub_r001120_4_2;
  int pub_r001120_5_1;
  int pub_r001120_5_2;
  int pub_r001120_6_1;
  int pub_r001120_6_2;
  int pub_r001120_7_1;
  int pub_r001120_7_2;
  int pub_r001120_8_1;
  int pub_r001120_8_2;
  int pub_r001120_9_1;
  int pub_r001120_9_2;
  int pub_r001120_10_1;
  int pub_r001120_10_2;
  int pub_r001120_11_1;
  int pub_r001120_11_2;
  int pub_r001120_12_1;
  int pub_r001120_12_2;
  int pub_r001120_13_1;
  int pub_r001120_13_2;
  int pub_r001120_14_1;
  int pub_r001120_14_2;
  int pub_r001120_15_1;
  int pub_r001120_15_2;
  int pub_r001120_16_1;
  int pub_r001120_16_2;
  int pub_r001120_17_1;
  int pub_r001120_17_2;
  int pub_r001120_18_1;
  int pub_r001120_18_2;
  int pub_r001120_19_1;
  int pub_r001120_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001120_0_1 >= (-100)) && (pub_r001120_0_1 <= 100));
  __CPROVER_assume((pub_r001120_0_2 >= (-100)) && (pub_r001120_0_2 <= 100));
  __CPROVER_assume((pub_r001120_1_1 >= (-100)) && (pub_r001120_1_1 <= 100));
  __CPROVER_assume((pub_r001120_1_2 >= (-100)) && (pub_r001120_1_2 <= 100));
  __CPROVER_assume((pub_r001120_2_1 >= (-100)) && (pub_r001120_2_1 <= 100));
  __CPROVER_assume((pub_r001120_2_2 >= (-100)) && (pub_r001120_2_2 <= 100));
  __CPROVER_assume((pub_r001120_3_1 >= (-100)) && (pub_r001120_3_1 <= 100));
  __CPROVER_assume((pub_r001120_3_2 >= (-100)) && (pub_r001120_3_2 <= 100));
  __CPROVER_assume((pub_r001120_4_1 >= (-100)) && (pub_r001120_4_1 <= 100));
  __CPROVER_assume((pub_r001120_4_2 >= (-100)) && (pub_r001120_4_2 <= 100));
  __CPROVER_assume((pub_r001120_5_1 >= (-100)) && (pub_r001120_5_1 <= 100));
  __CPROVER_assume((pub_r001120_5_2 >= (-100)) && (pub_r001120_5_2 <= 100));
  __CPROVER_assume((pub_r001120_6_1 >= (-100)) && (pub_r001120_6_1 <= 100));
  __CPROVER_assume((pub_r001120_6_2 >= (-100)) && (pub_r001120_6_2 <= 100));
  __CPROVER_assume((pub_r001120_7_1 >= (-100)) && (pub_r001120_7_1 <= 100));
  __CPROVER_assume((pub_r001120_7_2 >= (-100)) && (pub_r001120_7_2 <= 100));
  __CPROVER_assume((pub_r001120_8_1 >= (-100)) && (pub_r001120_8_1 <= 100));
  __CPROVER_assume((pub_r001120_8_2 >= (-100)) && (pub_r001120_8_2 <= 100));
  __CPROVER_assume((pub_r001120_9_1 >= (-100)) && (pub_r001120_9_1 <= 100));
  __CPROVER_assume((pub_r001120_9_2 >= (-100)) && (pub_r001120_9_2 <= 100));
  __CPROVER_assume((pub_r001120_10_1 >= (-100)) && (pub_r001120_10_1 <= 100));
  __CPROVER_assume((pub_r001120_10_2 >= (-100)) && (pub_r001120_10_2 <= 100));
  __CPROVER_assume((pub_r001120_11_1 >= (-100)) && (pub_r001120_11_1 <= 100));
  __CPROVER_assume((pub_r001120_11_2 >= (-100)) && (pub_r001120_11_2 <= 100));
  __CPROVER_assume((pub_r001120_12_1 >= (-100)) && (pub_r001120_12_1 <= 100));
  __CPROVER_assume((pub_r001120_12_2 >= (-100)) && (pub_r001120_12_2 <= 100));
  __CPROVER_assume((pub_r001120_13_1 >= (-100)) && (pub_r001120_13_1 <= 100));
  __CPROVER_assume((pub_r001120_13_2 >= (-100)) && (pub_r001120_13_2 <= 100));
  __CPROVER_assume((pub_r001120_14_1 >= (-100)) && (pub_r001120_14_1 <= 100));
  __CPROVER_assume((pub_r001120_14_2 >= (-100)) && (pub_r001120_14_2 <= 100));
  __CPROVER_assume((pub_r001120_15_1 >= (-100)) && (pub_r001120_15_1 <= 100));
  __CPROVER_assume((pub_r001120_15_2 >= (-100)) && (pub_r001120_15_2 <= 100));
  __CPROVER_assume((pub_r001120_16_1 >= (-100)) && (pub_r001120_16_1 <= 100));
  __CPROVER_assume((pub_r001120_16_2 >= (-100)) && (pub_r001120_16_2 <= 100));
  __CPROVER_assume((pub_r001120_17_1 >= (-100)) && (pub_r001120_17_1 <= 100));
  __CPROVER_assume((pub_r001120_17_2 >= (-100)) && (pub_r001120_17_2 <= 100));
  __CPROVER_assume((pub_r001120_18_1 >= (-100)) && (pub_r001120_18_1 <= 100));
  __CPROVER_assume((pub_r001120_18_2 >= (-100)) && (pub_r001120_18_2 <= 100));
  __CPROVER_assume((pub_r001120_19_1 >= (-100)) && (pub_r001120_19_1 <= 100));
  __CPROVER_assume((pub_r001120_19_2 >= (-100)) && (pub_r001120_19_2 <= 100));
  __CPROVER_assume((sec_r001120_0_1 >= 0) && (sec_r001120_0_1 <= 255));
  __CPROVER_assume((sec_r001120_0_2 >= 0) && (sec_r001120_0_2 <= 255));
  __CPROVER_assume((sec_r001120_1_1 >= 0) && (sec_r001120_1_1 <= 255));
  __CPROVER_assume((sec_r001120_1_2 >= 0) && (sec_r001120_1_2 <= 255));
  __CPROVER_assume((sec_r001120_2_1 >= 0) && (sec_r001120_2_1 <= 255));
  __CPROVER_assume((sec_r001120_2_2 >= 0) && (sec_r001120_2_2 <= 255));
  __CPROVER_assume((sec_r001120_3_1 >= 0) && (sec_r001120_3_1 <= 255));
  __CPROVER_assume((sec_r001120_3_2 >= 0) && (sec_r001120_3_2 <= 255));
  __CPROVER_assume((sec_r001120_4_1 >= 0) && (sec_r001120_4_1 <= 255));
  __CPROVER_assume((sec_r001120_4_2 >= 0) && (sec_r001120_4_2 <= 255));
  __CPROVER_assume((sec_r001120_5_1 >= 0) && (sec_r001120_5_1 <= 255));
  __CPROVER_assume((sec_r001120_5_2 >= 0) && (sec_r001120_5_2 <= 255));
  __CPROVER_assume((sec_r001120_6_1 >= 0) && (sec_r001120_6_1 <= 255));
  __CPROVER_assume((sec_r001120_6_2 >= 0) && (sec_r001120_6_2 <= 255));
  __CPROVER_assume((sec_r001120_7_1 >= 0) && (sec_r001120_7_1 <= 255));
  __CPROVER_assume((sec_r001120_7_2 >= 0) && (sec_r001120_7_2 <= 255));
  __CPROVER_assume((sec_r001120_8_1 >= 0) && (sec_r001120_8_1 <= 255));
  __CPROVER_assume((sec_r001120_8_2 >= 0) && (sec_r001120_8_2 <= 255));
  __CPROVER_assume((sec_r001120_9_1 >= 0) && (sec_r001120_9_1 <= 255));
  __CPROVER_assume((sec_r001120_9_2 >= 0) && (sec_r001120_9_2 <= 255));
  __CPROVER_assume((sec_r001120_10_1 >= 0) && (sec_r001120_10_1 <= 255));
  __CPROVER_assume((sec_r001120_10_2 >= 0) && (sec_r001120_10_2 <= 255));
  __CPROVER_assume((sec_r001120_11_1 >= 0) && (sec_r001120_11_1 <= 255));
  __CPROVER_assume((sec_r001120_11_2 >= 0) && (sec_r001120_11_2 <= 255));
  __CPROVER_assume((sec_r001120_12_1 >= 0) && (sec_r001120_12_1 <= 255));
  __CPROVER_assume((sec_r001120_12_2 >= 0) && (sec_r001120_12_2 <= 255));
  __CPROVER_assume((sec_r001120_13_1 >= 0) && (sec_r001120_13_1 <= 255));
  __CPROVER_assume((sec_r001120_13_2 >= 0) && (sec_r001120_13_2 <= 255));
  __CPROVER_assume((sec_r001120_14_1 >= 0) && (sec_r001120_14_1 <= 255));
  __CPROVER_assume((sec_r001120_14_2 >= 0) && (sec_r001120_14_2 <= 255));
  __CPROVER_assume((sec_r001120_15_1 >= 0) && (sec_r001120_15_1 <= 255));
  __CPROVER_assume((sec_r001120_15_2 >= 0) && (sec_r001120_15_2 <= 255));
  __CPROVER_assume((sec_r001120_16_1 >= 0) && (sec_r001120_16_1 <= 255));
  __CPROVER_assume((sec_r001120_16_2 >= 0) && (sec_r001120_16_2 <= 255));
  __CPROVER_assume((sec_r001120_17_1 >= 0) && (sec_r001120_17_1 <= 255));
  __CPROVER_assume((sec_r001120_17_2 >= 0) && (sec_r001120_17_2 <= 255));
  __CPROVER_assume((sec_r001120_18_1 >= 0) && (sec_r001120_18_1 <= 255));
  __CPROVER_assume((sec_r001120_18_2 >= 0) && (sec_r001120_18_2 <= 255));
  __CPROVER_assume((sec_r001120_19_1 >= 0) && (sec_r001120_19_1 <= 255));
  __CPROVER_assume((sec_r001120_19_2 >= 0) && (sec_r001120_19_2 <= 255));
  __CPROVER_assume((sec_r001120_20_1 >= 0) && (sec_r001120_20_1 <= 255));
  __CPROVER_assume((sec_r001120_20_2 >= 0) && (sec_r001120_20_2 <= 255));
  __CPROVER_assume((sec_r001120_21_1 >= 0) && (sec_r001120_21_1 <= 255));
  __CPROVER_assume((sec_r001120_21_2 >= 0) && (sec_r001120_21_2 <= 255));
  __CPROVER_assume((sec_r001120_22_1 >= 0) && (sec_r001120_22_1 <= 255));
  __CPROVER_assume((sec_r001120_22_2 >= 0) && (sec_r001120_22_2 <= 255));
  __CPROVER_assume((sec_r001120_23_1 >= 0) && (sec_r001120_23_1 <= 255));
  __CPROVER_assume((sec_r001120_23_2 >= 0) && (sec_r001120_23_2 <= 255));
  struct CipherContext_R001120_2013_0 st_var_0_1 = {0};
  struct CipherContext_R001120_2013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001120_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001120_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001120_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001120_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001120_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001120_0_2 + 7) & 15;
  struct AudioFrame_R001120_2013_1 st_var_1_1 = {0};
  struct AudioFrame_R001120_2013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001120_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001120_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001120_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001120_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001120_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001120_0_2 + 9) & 15;
  struct EventLog_R001120_2013_2 st_var_2_1 = {0};
  struct EventLog_R001120_2013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001120_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001120_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001120_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001120_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001120_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001120_0_2 + 11) & 15;
  union TelemetryField_R001120_2013_0 u_var_1;
  union TelemetryField_R001120_2013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001120_2013_0(sec_r001120_0_1, pub_r001120_1_1, pub_r001120_2_1, pub_r001120_3_1);
  int helper_flow_0_2 = fn_R001120_2013_0(sec_r001120_0_2, pub_r001120_1_2, pub_r001120_2_2, pub_r001120_3_2);
  fn_R001120_2013_0_2(sec_r001120_0_1, pub_r001120_1_1, pub_r001120_2_1, pub_r001120_3_1, sec_r001120_0_2, pub_r001120_1_2, pub_r001120_2_2, pub_r001120_3_2);
  int helper_flow_1_1 = fn_R001120_2013_1(sec_r001120_1_1, pub_r001120_2_1);
  int helper_flow_1_2 = fn_R001120_2013_1(sec_r001120_1_2, pub_r001120_2_2);
  fn_R001120_2013_1_2(sec_r001120_1_1, pub_r001120_2_1, sec_r001120_1_2, pub_r001120_2_2);
  int helper_flow_2_1 = fn_R001120_2013_2(sec_r001120_2_1, sec_r001120_3_1);
  int helper_flow_2_2 = fn_R001120_2013_2(sec_r001120_2_2, sec_r001120_3_2);
  fn_R001120_2013_2_2(sec_r001120_2_1, sec_r001120_3_1, sec_r001120_2_2, sec_r001120_3_2);
  int helper_flow_3_1 = fn_R001120_2013_3(sec_r001120_3_1, sec_r001120_4_1, pub_r001120_5_1, pub_r001120_6_1);
  int helper_flow_3_2 = fn_R001120_2013_3(sec_r001120_3_2, sec_r001120_4_2, pub_r001120_5_2, pub_r001120_6_2);
  fn_R001120_2013_3_2(sec_r001120_3_1, sec_r001120_4_1, pub_r001120_5_1, pub_r001120_6_1, sec_r001120_3_2, sec_r001120_4_2, pub_r001120_5_2, pub_r001120_6_2);
  int helper_flow_4_1 = fn_R001120_2013_4(sec_r001120_4_1, sec_r001120_5_1, pub_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1);
  int helper_flow_4_2 = fn_R001120_2013_4(sec_r001120_4_2, sec_r001120_5_2, pub_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2);
  fn_R001120_2013_4_2(sec_r001120_4_1, sec_r001120_5_1, pub_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1, sec_r001120_4_2, sec_r001120_5_2, pub_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2);
  int helper_flow_5_1 = fn_R001120_2013_5(sec_r001120_5_1, pub_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1);
  int helper_flow_5_2 = fn_R001120_2013_5(sec_r001120_5_2, pub_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2);
  fn_R001120_2013_5_2(sec_r001120_5_1, pub_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1, sec_r001120_5_2, pub_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2);
  int helper_flow_6_1 = fn_R001120_2013_6(sec_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1, pub_r001120_9_1);
  int helper_flow_6_2 = fn_R001120_2013_6(sec_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2, pub_r001120_9_2);
  fn_R001120_2013_6_2(sec_r001120_6_1, pub_r001120_7_1, pub_r001120_8_1, pub_r001120_9_1, sec_r001120_6_2, pub_r001120_7_2, pub_r001120_8_2, pub_r001120_9_2);
  int helper_flow_7_1 = fn_R001120_2013_7(sec_r001120_7_1, pub_r001120_8_1, pub_r001120_9_1, pub_r001120_10_1, pub_r001120_11_1);
  int helper_flow_7_2 = fn_R001120_2013_7(sec_r001120_7_2, pub_r001120_8_2, pub_r001120_9_2, pub_r001120_10_2, pub_r001120_11_2);
  fn_R001120_2013_7_2(sec_r001120_7_1, pub_r001120_8_1, pub_r001120_9_1, pub_r001120_10_1, pub_r001120_11_1, sec_r001120_7_2, pub_r001120_8_2, pub_r001120_9_2, pub_r001120_10_2, pub_r001120_11_2);
  int helper_flow_8_1 = fn_R001120_2013_8(sec_r001120_8_1, sec_r001120_9_1, pub_r001120_10_1, pub_r001120_11_1);
  int helper_flow_8_2 = fn_R001120_2013_8(sec_r001120_8_2, sec_r001120_9_2, pub_r001120_10_2, pub_r001120_11_2);
  fn_R001120_2013_8_2(sec_r001120_8_1, sec_r001120_9_1, pub_r001120_10_1, pub_r001120_11_1, sec_r001120_8_2, sec_r001120_9_2, pub_r001120_10_2, pub_r001120_11_2);
  int helper_flow_9_1 = fn_R001120_2013_9(sec_r001120_9_1, sec_r001120_10_1, pub_r001120_11_1, pub_r001120_12_1);
  int helper_flow_9_2 = fn_R001120_2013_9(sec_r001120_9_2, sec_r001120_10_2, pub_r001120_11_2, pub_r001120_12_2);
  fn_R001120_2013_9_2(sec_r001120_9_1, sec_r001120_10_1, pub_r001120_11_1, pub_r001120_12_1, sec_r001120_9_2, sec_r001120_10_2, pub_r001120_11_2, pub_r001120_12_2);
  int helper_flow_10_1 = fn_R001120_2013_10(sec_r001120_10_1, pub_r001120_11_1, pub_r001120_12_1);
  int helper_flow_10_2 = fn_R001120_2013_10(sec_r001120_10_2, pub_r001120_11_2, pub_r001120_12_2);
  fn_R001120_2013_10_2(sec_r001120_10_1, pub_r001120_11_1, pub_r001120_12_1, sec_r001120_10_2, pub_r001120_11_2, pub_r001120_12_2);
  int helper_flow_11_1 = fn_R001120_2013_11(sec_r001120_11_1, pub_r001120_12_1);
  int helper_flow_11_2 = fn_R001120_2013_11(sec_r001120_11_2, pub_r001120_12_2);
  fn_R001120_2013_11_2(sec_r001120_11_1, pub_r001120_12_1, sec_r001120_11_2, pub_r001120_12_2);
  int helper_flow_12_1 = fn_R001120_2013_12(sec_r001120_12_1, pub_r001120_13_1, pub_r001120_14_1, pub_r001120_15_1, pub_r001120_16_1);
  int helper_flow_12_2 = fn_R001120_2013_12(sec_r001120_12_2, pub_r001120_13_2, pub_r001120_14_2, pub_r001120_15_2, pub_r001120_16_2);
  fn_R001120_2013_12_2(sec_r001120_12_1, pub_r001120_13_1, pub_r001120_14_1, pub_r001120_15_1, pub_r001120_16_1, sec_r001120_12_2, pub_r001120_13_2, pub_r001120_14_2, pub_r001120_15_2, pub_r001120_16_2);
  int helper_flow_13_1 = fn_R001120_2013_13(sec_r001120_13_1, pub_r001120_14_1, pub_r001120_15_1, pub_r001120_16_1);
  int helper_flow_13_2 = fn_R001120_2013_13(sec_r001120_13_2, pub_r001120_14_2, pub_r001120_15_2, pub_r001120_16_2);
  fn_R001120_2013_13_2(sec_r001120_13_1, pub_r001120_14_1, pub_r001120_15_1, pub_r001120_16_1, sec_r001120_13_2, pub_r001120_14_2, pub_r001120_15_2, pub_r001120_16_2);
  int stage_v_0_1 = ((pub_r001120_5_1 * 2) + 20) & 63;
  int stage_v_0_2 = ((pub_r001120_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001120_12_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_1_2 = (((sec_r001120_12_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_1_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((sec_r001120_19_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_2_2 = (((sec_r001120_19_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_2_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (((sec_r001120_23_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_3_2 = (((sec_r001120_23_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_3_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_4_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_4_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001120_10_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_5_2 = (((sec_r001120_10_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_5_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((sec_r001120_20_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_6_2 = (((sec_r001120_20_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_6_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001120_0_1 ^ 0x2A) * 2) + pub_r001120_12_1) & 127;
  int stage_v_7_2 = (((sec_r001120_0_2 ^ 0x2A) * 2) + pub_r001120_12_2) & 127;
  if (stage_v_7_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_8_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001120_17_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_9_2 = (((sec_r001120_17_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_9_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_10_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_10_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (((sec_r001120_7_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_11_2 = (((sec_r001120_7_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_11_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((pub_r001120_16_1 * 2) + 15) & 63;
  int stage_v_12_2 = ((pub_r001120_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_13_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_13_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((sec_r001120_9_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_14_2 = (((sec_r001120_9_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_14_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001120_19_1 * 2) + 21) & 63;
  int stage_v_15_2 = ((pub_r001120_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001120_11_1) & 127;
  int stage_v_16_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001120_11_2) & 127;
  if (stage_v_16_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((sec_r001120_23_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_17_2 = (((sec_r001120_23_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_17_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_18_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_18_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_19_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_19_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((sec_r001120_6_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_20_2 = (((sec_r001120_6_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_20_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001120_9_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_21_2 = (((sec_r001120_9_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_21_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_22_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_22_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((sec_r001120_9_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_23_2 = (((sec_r001120_9_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_23_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_24_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_24_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((pub_r001120_18_1 * 2) + 49) & 63;
  int stage_v_25_2 = ((pub_r001120_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_26_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_26_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001120_0_1 * 2) + 50) & 63;
  int stage_v_27_2 = ((pub_r001120_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_28_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_28_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_29_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_29_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_30_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_30_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_31_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_31_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = ((pub_r001120_6_1 * 2) + 24) & 63;
  int stage_v_32_2 = ((pub_r001120_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001120_0_1 * 2) + 43) & 63;
  int stage_v_33_2 = ((pub_r001120_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_34_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_34_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((pub_r001120_14_1 * 2) + 15) & 63;
  int stage_v_35_2 = ((pub_r001120_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001120_17_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_36_2 = (((sec_r001120_17_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_36_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_37_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_37_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_38_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_38_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_39_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_39_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001120_5_1 * 2) + 20) & 63;
  int stage_v_40_2 = ((pub_r001120_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_41_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_41_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = ((pub_r001120_12_1 * 2) + 43) & 63;
  int stage_v_42_2 = ((pub_r001120_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_43_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_43_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
  }
  if (stage_v_43_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = (((sec_r001120_4_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_44_2 = (((sec_r001120_4_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_44_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_45_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_45_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_46_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_46_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((sec_r001120_5_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_47_2 = (((sec_r001120_5_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_47_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_48_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_48_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_49_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_49_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_50_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_50_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001120_7_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_51_2 = (((sec_r001120_7_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_51_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((sec_r001120_19_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_52_2 = (((sec_r001120_19_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_52_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_53_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_53_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_54_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_54_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((sec_r001120_3_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_55_2 = (((sec_r001120_3_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_55_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_56_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_56_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_57_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_57_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_58_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_58_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_59_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_59_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_60_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_60_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_61_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_61_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((sec_r001120_3_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_62_2 = (((sec_r001120_3_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_62_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_63_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_63_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_64_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_64_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001120_10_1 * 2) + 19) & 63;
  int stage_v_65_2 = ((pub_r001120_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_66_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_66_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_67_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_67_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((stage_v_10_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_68_2 = (((stage_v_10_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_68_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_69_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_69_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((sec_r001120_19_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_70_2 = (((sec_r001120_19_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_70_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001120_4_1 * 2) + 44) & 63;
  int stage_v_71_2 = ((pub_r001120_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_72_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_72_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_73_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_73_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((sec_r001120_4_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_74_2 = (((sec_r001120_4_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_74_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_75_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_75_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_76_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_76_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_77_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_77_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((sec_r001120_16_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_78_2 = (((sec_r001120_16_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_78_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001120_18_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_79_2 = (((sec_r001120_18_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_79_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_80_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_80_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_81_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_81_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((sec_r001120_5_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_82_2 = (((sec_r001120_5_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_82_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_83_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_83_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_84_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_84_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_85_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_85_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001120_13_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_86_2 = (((sec_r001120_13_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_86_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_87_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_87_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((pub_r001120_13_1 * 2) + 43) & 63;
  int stage_v_88_2 = ((pub_r001120_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_89_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_89_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_90_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_90_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((pub_r001120_4_1 * 2) + 19) & 63;
  int stage_v_91_2 = ((pub_r001120_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_92_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_92_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((sec_r001120_19_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_93_2 = (((sec_r001120_19_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_93_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001120_12_1) & 127;
  int stage_v_94_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001120_12_2) & 127;
  if (stage_v_94_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_95_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_95_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((sec_r001120_8_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_96_2 = (((sec_r001120_8_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_96_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001120_12_1) & 127;
  int stage_v_97_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001120_12_2) & 127;
  if (stage_v_97_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_98_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_98_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((sec_r001120_15_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_99_2 = (((sec_r001120_15_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_99_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((pub_r001120_9_1 * 2) + 24) & 63;
  int stage_v_100_2 = ((pub_r001120_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_101_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_101_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((pub_r001120_8_1 * 2) + 40) & 63;
  int stage_v_102_2 = ((pub_r001120_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_103_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_103_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001120_16_1 * 2) + 40) & 63;
  int stage_v_104_2 = ((pub_r001120_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_43_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_105_2 = (((stage_v_43_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_105_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_106_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_106_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_107_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_107_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_108_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_108_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_109_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_109_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001120_11_1) & 127;
  int stage_v_110_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001120_11_2) & 127;
  if (stage_v_110_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001120_12_1) & 127;
  int stage_v_111_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001120_12_2) & 127;
  if (stage_v_111_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((stage_v_64_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_112_2 = (((stage_v_64_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_112_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((stage_v_8_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_113_2 = (((stage_v_8_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_113_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((sec_r001120_19_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_114_2 = (((sec_r001120_19_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_114_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001120_13_1 * 2) + 24) & 63;
  int stage_v_115_2 = ((pub_r001120_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001120_1_1 * 2) + 10) & 63;
  int stage_v_116_2 = ((pub_r001120_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_113_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_117_2 = (((stage_v_113_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_117_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_118_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_118_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((sec_r001120_1_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_119_2 = (((sec_r001120_1_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_119_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_120_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_120_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_121_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_121_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_122_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_122_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_123_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_123_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_83_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_124_2 = (((stage_v_83_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_124_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001120_5_1 * 2) + 12) & 63;
  int stage_v_125_2 = ((pub_r001120_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_126_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_126_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_127_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_127_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((pub_r001120_7_1 * 2) + 28) & 63;
  int stage_v_128_2 = ((pub_r001120_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_129_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_129_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_130_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_130_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((sec_r001120_3_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_131_2 = (((sec_r001120_3_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_131_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_132_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_132_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((pub_r001120_4_1 * 2) + 12) & 63;
  int stage_v_133_2 = ((pub_r001120_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = (((sec_r001120_5_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_134_2 = (((sec_r001120_5_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_134_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001120_11_1) & 127;
  int stage_v_135_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001120_11_2) & 127;
  if (stage_v_135_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_136_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_136_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((pub_r001120_15_1 * 2) + 41) & 63;
  int stage_v_137_2 = ((pub_r001120_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001120_10_1 * 2) + 19) & 63;
  int stage_v_138_2 = ((pub_r001120_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_139_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_139_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((sec_r001120_17_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_140_2 = (((sec_r001120_17_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_140_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_141_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_141_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_139_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_142_2 = (((stage_v_139_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_142_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_143_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_143_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_144_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_144_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((sec_r001120_23_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_145_2 = (((sec_r001120_23_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_145_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((pub_r001120_8_1 * 2) + 47) & 63;
  int stage_v_146_2 = ((pub_r001120_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001120_15_1 * 2) + 35) & 63;
  int stage_v_147_2 = ((pub_r001120_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_148_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_148_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_149_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_149_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_150_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_150_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_151_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_151_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((sec_r001120_13_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_152_2 = (((sec_r001120_13_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_152_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((pub_r001120_10_1 * 2) + 32) & 63;
  int stage_v_153_2 = ((pub_r001120_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001120_7_1 * 2) + 29) & 63;
  int stage_v_154_2 = ((pub_r001120_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001120_12_1) & 127;
  int stage_v_155_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001120_12_2) & 127;
  if (stage_v_155_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_156_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_156_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_157_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_157_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = (((stage_v_150_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_158_2 = (((stage_v_150_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_158_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_159_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_159_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((sec_r001120_11_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_160_2 = (((sec_r001120_11_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_160_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((sec_r001120_20_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_161_2 = (((sec_r001120_20_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_161_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_162_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_162_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_163_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_163_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_164_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_164_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((pub_r001120_5_1 * 2) + 7) & 63;
  int stage_v_165_2 = ((pub_r001120_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001120_17_1 * 2) + 43) & 63;
  int stage_v_166_2 = ((pub_r001120_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_167_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_167_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_168_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_168_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_169_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_169_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_170_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_170_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((pub_r001120_4_1 * 2) + 43) & 63;
  int stage_v_171_2 = ((pub_r001120_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_172_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_172_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_173_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_173_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001120_13_1 * 2) + 18) & 63;
  int stage_v_174_2 = ((pub_r001120_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001120_16_1 * 2) + 39) & 63;
  int stage_v_175_2 = ((pub_r001120_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_176_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_176_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = (((sec_r001120_5_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_177_2 = (((sec_r001120_5_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_177_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_178_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_178_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_179_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_179_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((pub_r001120_16_1 * 2) + 24) & 63;
  int stage_v_180_2 = ((pub_r001120_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001120_6_1 * 2) + 21) & 63;
  int stage_v_181_2 = ((pub_r001120_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_182_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_182_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001120_0_1 * 2) + 39) & 63;
  int stage_v_183_2 = ((pub_r001120_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_158_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_184_2 = (((stage_v_158_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_184_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_185_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_185_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((sec_r001120_8_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_186_2 = (((sec_r001120_8_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_186_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001120_13_1 * 2) + 16) & 63;
  int stage_v_187_2 = ((pub_r001120_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_188_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_188_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_189_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_189_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_190_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_190_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_191_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_191_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_192_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_192_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((pub_r001120_10_1 * 2) + 28) & 63;
  int stage_v_193_2 = ((pub_r001120_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_194_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_194_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001120_11_1) & 127;
  int stage_v_195_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001120_11_2) & 127;
  if (stage_v_195_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_196_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_196_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_197_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_197_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_198_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_198_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_199_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_199_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((pub_r001120_17_1 * 2) + 16) & 63;
  int stage_v_200_2 = ((pub_r001120_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((sec_r001120_23_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_201_2 = (((sec_r001120_23_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_201_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((pub_r001120_10_1 * 2) + 32) & 63;
  int stage_v_202_2 = ((pub_r001120_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_203_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_203_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_204_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_204_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((pub_r001120_5_1 * 2) + 7) & 63;
  int stage_v_205_2 = ((pub_r001120_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_206_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_206_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_207_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_207_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_170_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_208_2 = (((stage_v_170_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_208_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((pub_r001120_18_1 * 2) + 39) & 63;
  int stage_v_209_2 = ((pub_r001120_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_37_1 ^ 0x2A) * 2) + pub_r001120_19_1) & 127;
  int stage_v_210_2 = (((stage_v_37_2 ^ 0x2A) * 2) + pub_r001120_19_2) & 127;
  if (stage_v_210_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001120_0_1) & 127;
  int stage_v_211_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001120_0_2) & 127;
  if (stage_v_211_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001120_5_1) & 127;
  int stage_v_212_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001120_5_2) & 127;
  if (stage_v_212_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001120_6_1) & 127;
  int stage_v_213_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001120_6_2) & 127;
  if (stage_v_213_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001120_16_1) & 127;
  int stage_v_214_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001120_16_2) & 127;
  if (stage_v_214_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001120_19_1 * 2) + 41) & 63;
  int stage_v_215_2 = ((pub_r001120_19_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001120_9_1 * 2) + 35) & 63;
  int stage_v_216_2 = ((pub_r001120_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((sec_r001120_0_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_217_2 = (((sec_r001120_0_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_217_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_197_1 ^ 0x2A) * 2) + pub_r001120_7_1) & 127;
  int stage_v_218_2 = (((stage_v_197_2 ^ 0x2A) * 2) + pub_r001120_7_2) & 127;
  if (stage_v_218_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001120_3_1) & 127;
  int stage_v_219_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001120_3_2) & 127;
  if (stage_v_219_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = (((stage_v_18_1 ^ 0x2A) * 2) + pub_r001120_15_1) & 127;
  int stage_v_220_2 = (((stage_v_18_2 ^ 0x2A) * 2) + pub_r001120_15_2) & 127;
  if (stage_v_220_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_221_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_221_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001120_1_1) & 127;
  int stage_v_222_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001120_1_2) & 127;
  if (stage_v_222_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((sec_r001120_2_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_223_2 = (((sec_r001120_2_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_223_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((pub_r001120_0_1 * 2) + 17) & 63;
  int stage_v_224_2 = ((pub_r001120_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_225_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_225_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((pub_r001120_0_1 * 2) + 25) & 63;
  int stage_v_226_2 = ((pub_r001120_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001120_8_1) & 127;
  int stage_v_227_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001120_8_2) & 127;
  if (stage_v_227_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = (((stage_v_169_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_228_2 = (((stage_v_169_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_228_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((sec_r001120_23_1 ^ 0x2A) * 2) + pub_r001120_18_1) & 127;
  int stage_v_229_2 = (((sec_r001120_23_2 ^ 0x2A) * 2) + pub_r001120_18_2) & 127;
  if (stage_v_229_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_212_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_230_2 = (((stage_v_212_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_230_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((pub_r001120_12_1 * 2) + 14) & 63;
  int stage_v_231_2 = ((pub_r001120_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001120_8_1 * 2) + 48) & 63;
  int stage_v_232_2 = ((pub_r001120_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_135_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_233_2 = (((stage_v_135_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_233_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
  }
  if (stage_v_233_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = (((sec_r001120_2_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_234_2 = (((sec_r001120_2_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_234_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
  }
  if (stage_v_234_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001120_17_1) & 127;
  int stage_v_235_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001120_17_2) & 127;
  if (stage_v_235_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
  }
  if (stage_v_235_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((pub_r001120_19_1 * 2) + 26) & 63;
  int stage_v_236_2 = ((pub_r001120_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_93_1 ^ 0x2A) * 2) + pub_r001120_2_1) & 127;
  int stage_v_237_2 = (((stage_v_93_2 ^ 0x2A) * 2) + pub_r001120_2_2) & 127;
  if (stage_v_237_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
  }
  if (stage_v_237_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((pub_r001120_1_1 * 2) + 18) & 63;
  int stage_v_238_2 = ((pub_r001120_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_144_1 ^ 0x2A) * 2) + pub_r001120_9_1) & 127;
  int stage_v_239_2 = (((stage_v_144_2 ^ 0x2A) * 2) + pub_r001120_9_2) & 127;
  if (stage_v_239_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
  }
  if (stage_v_239_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_240_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_240_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
  }
  if (stage_v_240_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001120_4_1) & 127;
  int stage_v_241_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001120_4_2) & 127;
  if (stage_v_241_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
  }
  if (stage_v_241_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = (((sec_r001120_8_1 ^ 0x2A) * 2) + pub_r001120_13_1) & 127;
  int stage_v_242_2 = (((sec_r001120_8_2 ^ 0x2A) * 2) + pub_r001120_13_2) & 127;
  if (stage_v_242_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
  }
  if (stage_v_242_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((pub_r001120_15_1 * 2) + 38) & 63;
  int stage_v_243_2 = ((pub_r001120_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001120_10_1) & 127;
  int stage_v_244_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001120_10_2) & 127;
  if (stage_v_244_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
  }
  if (stage_v_244_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((pub_r001120_11_1 * 2) + 29) & 63;
  int stage_v_245_2 = ((pub_r001120_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = (((stage_v_237_1 ^ 0x2A) * 2) + pub_r001120_14_1) & 127;
  int stage_v_246_2 = (((stage_v_237_2 ^ 0x2A) * 2) + pub_r001120_14_2) & 127;
  if (stage_v_246_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
  }
  if (stage_v_246_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001120_1_1 != sec_r001120_1_2);
  __CPROVER_assume(sec_r001120_9_1 != sec_r001120_9_2);
  __CPROVER_assume(sec_r001120_8_1 != sec_r001120_8_2);
  __CPROVER_assume(pub_r001120_19_1 == pub_r001120_19_2);
  __CPROVER_assume(pub_r001120_17_1 == pub_r001120_17_2);
  __CPROVER_assume(pub_r001120_0_1 == pub_r001120_0_2);
  __CPROVER_assume(pub_r001120_9_1 == pub_r001120_9_2);
  __CPROVER_assume(sec_r001120_22_1 != sec_r001120_22_2);
  __CPROVER_assume(sec_r001120_3_1 != sec_r001120_3_2);
  __CPROVER_assume(sec_r001120_13_1 != sec_r001120_13_2);
  __CPROVER_assume(pub_r001120_16_1 == pub_r001120_16_2);
  __CPROVER_assume(sec_r001120_16_1 != sec_r001120_16_2);
  __CPROVER_assume(sec_r001120_0_1 != sec_r001120_0_2);
  __CPROVER_assume(pub_r001120_4_1 == pub_r001120_4_2);
  __CPROVER_assume(sec_r001120_10_1 != sec_r001120_10_2);
  __CPROVER_assume(sec_r001120_17_1 != sec_r001120_17_2);
  __CPROVER_assume(pub_r001120_10_1 == pub_r001120_10_2);
  __CPROVER_assume(pub_r001120_8_1 == pub_r001120_8_2);
  __CPROVER_assume(sec_r001120_15_1 != sec_r001120_15_2);
  __CPROVER_assume(sec_r001120_19_1 != sec_r001120_19_2);
  __CPROVER_assume(sec_r001120_6_1 != sec_r001120_6_2);
  __CPROVER_assume(sec_r001120_5_1 != sec_r001120_5_2);
  __CPROVER_assume(sec_r001120_12_1 != sec_r001120_12_2);
  __CPROVER_assume(pub_r001120_11_1 == pub_r001120_11_2);
  __CPROVER_assume(pub_r001120_7_1 == pub_r001120_7_2);
  __CPROVER_assume(pub_r001120_6_1 == pub_r001120_6_2);
  __CPROVER_assume(pub_r001120_3_1 == pub_r001120_3_2);
  __CPROVER_assume(sec_r001120_21_1 != sec_r001120_21_2);
  __CPROVER_assume(sec_r001120_7_1 != sec_r001120_7_2);
  __CPROVER_assume(pub_r001120_5_1 == pub_r001120_5_2);
  __CPROVER_assume(pub_r001120_12_1 == pub_r001120_12_2);
  __CPROVER_assume(sec_r001120_23_1 != sec_r001120_23_2);
  __CPROVER_assume(sec_r001120_4_1 != sec_r001120_4_2);
  __CPROVER_assume(pub_r001120_13_1 == pub_r001120_13_2);
  __CPROVER_assume(sec_r001120_2_1 != sec_r001120_2_2);
  __CPROVER_assume(pub_r001120_14_1 == pub_r001120_14_2);
  __CPROVER_assume(pub_r001120_2_1 == pub_r001120_2_2);
  __CPROVER_assume(pub_r001120_15_1 == pub_r001120_15_2);
  __CPROVER_assume(sec_r001120_14_1 != sec_r001120_14_2);
  __CPROVER_assume(sec_r001120_11_1 != sec_r001120_11_2);
  __CPROVER_assume(sec_r001120_18_1 != sec_r001120_18_2);
  __CPROVER_assume(pub_r001120_18_1 == pub_r001120_18_2);
  __CPROVER_assume(pub_r001120_1_1 == pub_r001120_1_2);
  __CPROVER_assume(sec_r001120_20_1 != sec_r001120_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.nonce == st_var_0_2.nonce);
  assert(st_var_0_1.round_key == st_var_0_2.round_key);
  assert(st_var_0_1.flags == st_var_0_2.flags);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.signature == st_var_2_2.signature);
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
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
  assert(helper_flow_13_1 == helper_flow_13_2);
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
}


