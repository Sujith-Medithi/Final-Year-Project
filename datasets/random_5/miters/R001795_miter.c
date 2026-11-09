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
struct AudioFrame_R001795_9513_0
{
  int sample_rate;
  unsigned char envelope;
  short gain;
  short peak;
  unsigned char rms;
  int channels;
  int buffer[3];
};
struct FilterState_R001795_9513_1
{
  int prev_out;
  unsigned char gain_db;
  int mode;
  int buffer[3];
};
struct MatrixBlock_R001795_9513_2
{
  int trace;
  int stride;
  unsigned char density;
  int buffer[3];
};
struct EventLog_R001795_9513_3
{
  int seq;
  unsigned char severity;
  short timestamp;
  int code;
  int buffer[3];
};
union PacketPayload_R001795_9513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001795_9513_1
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
void fn_R001795_9513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tally_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_68_1)
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

  switch (tally_68_2)
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
  int metric_88_1 = local_arr_1[aux_1 % 3];
  int metric_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_88_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_68_1 == tally_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_88_1 == metric_88_2);
}

int fn_R001795_9513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tally_68 = (aux + st.buffer[1]) & 3;
  switch (tally_68)
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
  int metric_88 = local_arr[aux % 3];
  acc = (acc + (metric_88 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st_1 = {0};
  struct AudioFrame_R001795_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int parity_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_86_1) & 63;
  aux_2 = (aux_2 + parity_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_46_1 = local_arr_1[aux_1 % 3];
  int pivot_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_46_2 * 2)) & 127;
  int parity_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_72_1)
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

  switch (parity_72_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_86_1 == parity_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(parity_72_1 == parity_72_2);
}

int fn_R001795_9513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int parity_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_46 = local_arr[aux % 3];
  acc = (acc + (pivot_46 * 2)) & 127;
  int parity_72 = (aux + st.buffer[1]) & 3;
  switch (parity_72)
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

void fn_R001795_9513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_44_1)
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

  switch (coefficient_44_2)
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

  int stride_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_92_1) & 63;
  aux_2 = (aux_2 + stride_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_85_1 = local_arr_1[aux_1 % 3];
  int index_reg_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_44_1 == coefficient_44_2);
  assert(stride_92_1 == stride_92_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_85_1 == index_reg_85_2);
}

int fn_R001795_9513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_44 = (aux + st.buffer[1]) & 3;
  switch (coefficient_44)
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

  int stride_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_92) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_85 = local_arr[aux % 3];
  acc = (acc + (index_reg_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st_1 = {0};
  struct AudioFrame_R001795_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_63_1)
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

  switch (damping_63_2)
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
  int window_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_62_1) & 63;
  aux_2 = (aux_2 + window_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_42_1 > 15)
  {
    acc_1 = ((acc_1 + (vector_42_1 * 2)) + 5) & 127;
    aux_1 ^= vector_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_42_2 > 15)
  {
    acc_2 = ((acc_2 + (vector_42_2 * 2)) + 5) & 127;
    aux_2 ^= vector_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_63_1 == damping_63_2);
  assert(window_62_1 == window_62_2);
  assert(vector_42_1 == vector_42_2);
}

int fn_R001795_9513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_63 = (aux + st.buffer[1]) & 3;
  switch (damping_63)
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
  int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_62) & 63;
  acc ^= aux;
  int vector_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_42 > 15)
  {
    acc = ((acc + (vector_42 * 2)) + 5) & 127;
    aux ^= vector_42 & 15;
  }
  else
  {
    acc = ((acc - vector_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001795_9513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_74_1 = local_arr_1[aux_1 % 3];
  int mask_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_74_2 * 2)) & 127;
  int bound_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_40_1)
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

  switch (bound_40_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_94_1) & 63;
  aux_2 = (aux_2 + weight_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_74_1 == mask_74_2);
  assert(bound_40_1 == bound_40_2);
  assert(weight_94_1 == weight_94_2);
}

int fn_R001795_9513_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int mask_74 = local_arr[aux % 3];
  acc = (acc + (mask_74 * 2)) & 127;
  int bound_40 = (aux + st.buffer[1]) & 3;
  switch (bound_40)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001795_9513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st_1 = {0};
  struct AudioFrame_R001795_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int sample_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_80_1) & 63;
  aux_2 = (aux_2 + sample_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_74_1 = 0;
  int damping_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_74_1 = ((damping_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_74_2 = ((damping_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_74_1) & 127;
    acc_2 = (acc_2 + damping_74_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_80_1 == sample_80_2);
  assert(damping_74_1 == damping_74_2);
}

int fn_R001795_9513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_80) & 63;
  acc ^= aux;
  int damping_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_74 = ((damping_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_74) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int bound_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_30_1 > 12)
  {
    acc_1 = ((acc_1 + (bound_30_1 * 2)) + 5) & 127;
    aux_1 ^= bound_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_30_2 > 12)
  {
    acc_2 = ((acc_2 + (bound_30_2 * 2)) + 5) & 127;
    aux_2 ^= bound_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_59_1)
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

  switch (margin_59_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_30_1 == bound_30_2);
  assert(margin_59_1 == margin_59_2);
}

int fn_R001795_9513_6(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int bound_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_30 > 12)
  {
    acc = ((acc + (bound_30 * 2)) + 5) & 127;
    aux ^= bound_30 & 15;
  }
  else
  {
    acc = ((acc - bound_30) + 11) & 127;
    aux += 3;
  }
  int margin_59 = (aux + st.buffer[1]) & 3;
  switch (margin_59)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
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
  int vector_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_20_1) & 63;
  aux_2 = (aux_2 + vector_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_97_1 = local_arr_1[aux_1 % 3];
  int tracker_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_97_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_20_1 == vector_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_97_1 == tracker_97_2);
}

int fn_R001795_9513_7(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_97 = local_arr[aux % 3];
  acc = (acc + (tracker_97 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int weight_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_94_1 > 41)
  {
    acc_1 = ((acc_1 + (weight_94_1 * 2)) + 5) & 127;
    aux_1 ^= weight_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_94_2 > 41)
  {
    acc_2 = ((acc_2 + (weight_94_2 * 2)) + 5) & 127;
    aux_2 ^= weight_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_50_1 = 0;
  int metric_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_50_1 = ((metric_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_50_2 = ((metric_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_50_1) & 127;
    acc_2 = (acc_2 + metric_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_94_1 == weight_94_2);
  assert(metric_50_1 == metric_50_2);
}

int fn_R001795_9513_8(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int weight_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_94 > 41)
  {
    acc = ((acc + (weight_94 * 2)) + 5) & 127;
    aux ^= weight_94 & 15;
  }
  else
  {
    acc = ((acc - weight_94) + 11) & 127;
    aux += 3;
  }
  int metric_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_50 = ((metric_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001795_9513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_35_1) & 63;
  aux_2 = (aux_2 + tally_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_64_1 = local_arr_1[aux_1 % 3];
  int metric_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_35_1 == tally_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_64_1 == metric_64_2);
}

int fn_R001795_9513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_64 = local_arr[aux % 3];
  acc = (acc + (metric_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_67_1) & 63;
  aux_2 = (aux_2 + damping_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_14_1 = local_arr_1[aux_1 % 3];
  int cursor_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_14_2 * 2)) & 127;
  int parity_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_29_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_29_1 * 2)) + 5) & 127;
    aux_1 ^= parity_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_29_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_29_2 * 2)) + 5) & 127;
    aux_2 ^= parity_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_67_1 == damping_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_14_1 == cursor_14_2);
  assert(parity_29_1 == parity_29_2);
}

int fn_R001795_9513_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_14 = local_arr[aux % 3];
  acc = (acc + (cursor_14 * 2)) & 127;
  int parity_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_29 > 13)
  {
    acc = ((acc + (parity_29 * 2)) + 5) & 127;
    aux ^= parity_29 & 15;
  }
  else
  {
    acc = ((acc - parity_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001795_9513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_23_1 > 23)
  {
    acc_1 = ((acc_1 + (threshold_23_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_23_2 > 23)
  {
    acc_2 = ((acc_2 + (threshold_23_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_36_1 = 0;
  int anchor_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_36_1 = ((anchor_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_36_2 = ((anchor_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_36_1) & 127;
    acc_2 = (acc_2 + anchor_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_23_1 == threshold_23_2);
  assert(anchor_36_1 == anchor_36_2);
}

int fn_R001795_9513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_23 > 23)
  {
    acc = ((acc + (threshold_23 * 2)) + 5) & 127;
    aux ^= threshold_23 & 15;
  }
  else
  {
    acc = ((acc - threshold_23) + 11) & 127;
    aux += 3;
  }
  int anchor_36 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_36 = ((anchor_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001795_9513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st_1 = {0};
  struct AudioFrame_R001795_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_69_1)
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

  switch (offset_69_2)
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
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.rms == st_2.rms);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_69_1 == offset_69_2);
}

int fn_R001795_9513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001795_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_69 = (aux + st.buffer[1]) & 3;
  switch (offset_69)
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

void fn_R001795_9513_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int scale_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_70_1 > 29)
  {
    acc_1 = ((acc_1 + (scale_70_1 * 2)) + 5) & 127;
    aux_1 ^= scale_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_70_2 > 29)
  {
    acc_2 = ((acc_2 + (scale_70_2 * 2)) + 5) & 127;
    aux_2 ^= scale_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_25_1 = 0;
  int tally_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_25_1 = ((tally_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_25_2 = ((tally_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_25_1) & 127;
    acc_2 = (acc_2 + tally_25_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_40_1 = local_arr_1[aux_1 % 3];
  int phase_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_40_2 * 2)) & 127;
  int sample_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_23_1) & 63;
  aux_2 = (aux_2 + sample_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(tally_25_1 == tally_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_40_1 == phase_40_2);
  assert(sample_23_1 == sample_23_2);
}

int fn_R001795_9513_13(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int scale_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_70 > 29)
  {
    acc = ((acc + (scale_70 * 2)) + 5) & 127;
    aux ^= scale_70 & 15;
  }
  else
  {
    acc = ((acc - scale_70) + 11) & 127;
    aux += 3;
  }
  int tally_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_25 = ((tally_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_25) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_40 = local_arr[aux % 3];
  acc = (acc + (phase_40 * 2)) & 127;
  int sample_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_23) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001795_9513_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int quantum_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_89_1) & 63;
  aux_2 = (aux_2 + quantum_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_13_1 = 0;
  int parity_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_13_1 = ((parity_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_13_2 = ((parity_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_13_1) & 127;
    acc_2 = (acc_2 + parity_13_2) & 127;
  }

  int scale_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_66_1)
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

  switch (scale_66_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_89_1 == quantum_89_2);
  assert(parity_13_1 == parity_13_2);
  assert(scale_66_1 == scale_66_2);
}

int fn_R001795_9513_14(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int quantum_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_89) & 63;
  acc ^= aux;
  int parity_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_13 = ((parity_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_13) & 127;
  }

  int scale_66 = (aux + st.buffer[1]) & 3;
  switch (scale_66)
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

void fn_R001795_9513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int mask_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_11_1) & 63;
  aux_2 = (aux_2 + mask_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_46_1 > 41)
  {
    acc_1 = ((acc_1 + (sample_46_1 * 2)) + 5) & 127;
    aux_1 ^= sample_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_46_2 > 41)
  {
    acc_2 = ((acc_2 + (sample_46_2 * 2)) + 5) & 127;
    aux_2 ^= sample_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_78_1)
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

  switch (stride_78_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_11_1 == mask_11_2);
  assert(sample_46_1 == sample_46_2);
  assert(stride_78_1 == stride_78_2);
}

int fn_R001795_9513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int mask_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_11) & 63;
  acc ^= aux;
  int sample_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_46 > 41)
  {
    acc = ((acc + (sample_46 * 2)) + 5) & 127;
    aux ^= sample_46 & 15;
  }
  else
  {
    acc = ((acc - sample_46) + 11) & 127;
    aux += 3;
  }
  int stride_78 = (aux + st.buffer[1]) & 3;
  switch (stride_78)
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

void fn_R001795_9513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_75_1 = local_arr_1[aux_1 % 3];
  int coefficient_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_75_2 * 2)) & 127;
  int cursor_89_1 = 0;
  int cursor_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_89_1 = ((cursor_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_89_2 = ((cursor_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_89_1) & 127;
    acc_2 = (acc_2 + cursor_89_2) & 127;
  }

  int segment_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_17_1) & 63;
  aux_2 = (aux_2 + segment_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_75_1 == coefficient_75_2);
  assert(cursor_89_1 == cursor_89_2);
  assert(segment_17_1 == segment_17_2);
}

int fn_R001795_9513_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int coefficient_75 = local_arr[aux % 3];
  acc = (acc + (coefficient_75 * 2)) & 127;
  int cursor_89 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_89 = ((cursor_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_89) & 127;
  }

  int segment_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001795_9513_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_93_1) & 63;
  aux_2 = (aux_2 + cursor_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_96_1 = local_arr_1[aux_1 % 3];
  int bound_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_96_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_93_1 == cursor_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_96_1 == bound_96_2);
}

int fn_R001795_9513_17(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_93) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_96 = local_arr[aux % 3];
  acc = (acc + (bound_96 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001795_9513_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st_1 = {0};
  struct EventLog_R001795_9513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int offset_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_58_1 > 12)
  {
    acc_1 = ((acc_1 + (offset_58_1 * 2)) + 5) & 127;
    aux_1 ^= offset_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_58_2 > 12)
  {
    acc_2 = ((acc_2 + (offset_58_2 * 2)) + 5) & 127;
    aux_2 ^= offset_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_58_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_69_1) & 63;
  aux_2 = (aux_2 + weight_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_33_1)
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

  switch (coefficient_33_2)
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
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_58_1 == offset_58_2);
  assert(weight_69_1 == weight_69_2);
  assert(coefficient_33_1 == coefficient_33_2);
}

int fn_R001795_9513_18(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001795_9513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int offset_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_58 > 12)
  {
    acc = ((acc + (offset_58 * 2)) + 5) & 127;
    aux ^= offset_58 & 15;
  }
  else
  {
    acc = ((acc - offset_58) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_69) & 63;
  acc ^= aux;
  int coefficient_33 = (aux + st.buffer[1]) & 3;
  switch (coefficient_33)
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

void fn_R001795_9513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st_1 = {0};
  struct FilterState_R001795_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_83_1 = 0;
  int pivot_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_83_1 = ((pivot_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_83_2 = ((pivot_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_83_1) & 127;
    acc_2 = (acc_2 + pivot_83_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_16_1) & 63;
  aux_2 = (aux_2 + sample_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_83_1 == pivot_83_2);
  assert(sample_16_1 == sample_16_2);
}

int fn_R001795_9513_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001795_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_83 = ((pivot_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_83) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001795_9513_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_19_1) & 63;
  aux_2 = (aux_2 + checksum_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_19_1 == checksum_19_2);
}

int fn_R001795_9513_20(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001795_9513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_19) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001795_0_1;
  int sec_r001795_0_2;
  int sec_r001795_1_1;
  int sec_r001795_1_2;
  int sec_r001795_2_1;
  int sec_r001795_2_2;
  int sec_r001795_3_1;
  int sec_r001795_3_2;
  int sec_r001795_4_1;
  int sec_r001795_4_2;
  int sec_r001795_5_1;
  int sec_r001795_5_2;
  int sec_r001795_6_1;
  int sec_r001795_6_2;
  int sec_r001795_7_1;
  int sec_r001795_7_2;
  int sec_r001795_8_1;
  int sec_r001795_8_2;
  int sec_r001795_9_1;
  int sec_r001795_9_2;
  int sec_r001795_10_1;
  int sec_r001795_10_2;
  int sec_r001795_11_1;
  int sec_r001795_11_2;
  int sec_r001795_12_1;
  int sec_r001795_12_2;
  int sec_r001795_13_1;
  int sec_r001795_13_2;
  int sec_r001795_14_1;
  int sec_r001795_14_2;
  int sec_r001795_15_1;
  int sec_r001795_15_2;
  int sec_r001795_16_1;
  int sec_r001795_16_2;
  int pub_r001795_0_1;
  int pub_r001795_0_2;
  int pub_r001795_1_1;
  int pub_r001795_1_2;
  int pub_r001795_2_1;
  int pub_r001795_2_2;
  int pub_r001795_3_1;
  int pub_r001795_3_2;
  int pub_r001795_4_1;
  int pub_r001795_4_2;
  int pub_r001795_5_1;
  int pub_r001795_5_2;
  int pub_r001795_6_1;
  int pub_r001795_6_2;
  int pub_r001795_7_1;
  int pub_r001795_7_2;
  int pub_r001795_8_1;
  int pub_r001795_8_2;
  int pub_r001795_9_1;
  int pub_r001795_9_2;
  int pub_r001795_10_1;
  int pub_r001795_10_2;
  int pub_r001795_11_1;
  int pub_r001795_11_2;
  int pub_r001795_12_1;
  int pub_r001795_12_2;
  int pub_r001795_13_1;
  int pub_r001795_13_2;
  int pub_r001795_14_1;
  int pub_r001795_14_2;
  int pub_r001795_15_1;
  int pub_r001795_15_2;
  int pub_r001795_16_1;
  int pub_r001795_16_2;
  int pub_r001795_17_1;
  int pub_r001795_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001795_0_1 >= (-100)) && (pub_r001795_0_1 <= 100));
  __CPROVER_assume((pub_r001795_0_2 >= (-100)) && (pub_r001795_0_2 <= 100));
  __CPROVER_assume((pub_r001795_1_1 >= (-100)) && (pub_r001795_1_1 <= 100));
  __CPROVER_assume((pub_r001795_1_2 >= (-100)) && (pub_r001795_1_2 <= 100));
  __CPROVER_assume((pub_r001795_2_1 >= (-100)) && (pub_r001795_2_1 <= 100));
  __CPROVER_assume((pub_r001795_2_2 >= (-100)) && (pub_r001795_2_2 <= 100));
  __CPROVER_assume((pub_r001795_3_1 >= (-100)) && (pub_r001795_3_1 <= 100));
  __CPROVER_assume((pub_r001795_3_2 >= (-100)) && (pub_r001795_3_2 <= 100));
  __CPROVER_assume((pub_r001795_4_1 >= (-100)) && (pub_r001795_4_1 <= 100));
  __CPROVER_assume((pub_r001795_4_2 >= (-100)) && (pub_r001795_4_2 <= 100));
  __CPROVER_assume((pub_r001795_5_1 >= (-100)) && (pub_r001795_5_1 <= 100));
  __CPROVER_assume((pub_r001795_5_2 >= (-100)) && (pub_r001795_5_2 <= 100));
  __CPROVER_assume((pub_r001795_6_1 >= (-100)) && (pub_r001795_6_1 <= 100));
  __CPROVER_assume((pub_r001795_6_2 >= (-100)) && (pub_r001795_6_2 <= 100));
  __CPROVER_assume((pub_r001795_7_1 >= (-100)) && (pub_r001795_7_1 <= 100));
  __CPROVER_assume((pub_r001795_7_2 >= (-100)) && (pub_r001795_7_2 <= 100));
  __CPROVER_assume((pub_r001795_8_1 >= (-100)) && (pub_r001795_8_1 <= 100));
  __CPROVER_assume((pub_r001795_8_2 >= (-100)) && (pub_r001795_8_2 <= 100));
  __CPROVER_assume((pub_r001795_9_1 >= (-100)) && (pub_r001795_9_1 <= 100));
  __CPROVER_assume((pub_r001795_9_2 >= (-100)) && (pub_r001795_9_2 <= 100));
  __CPROVER_assume((pub_r001795_10_1 >= (-100)) && (pub_r001795_10_1 <= 100));
  __CPROVER_assume((pub_r001795_10_2 >= (-100)) && (pub_r001795_10_2 <= 100));
  __CPROVER_assume((pub_r001795_11_1 >= (-100)) && (pub_r001795_11_1 <= 100));
  __CPROVER_assume((pub_r001795_11_2 >= (-100)) && (pub_r001795_11_2 <= 100));
  __CPROVER_assume((pub_r001795_12_1 >= (-100)) && (pub_r001795_12_1 <= 100));
  __CPROVER_assume((pub_r001795_12_2 >= (-100)) && (pub_r001795_12_2 <= 100));
  __CPROVER_assume((pub_r001795_13_1 >= (-100)) && (pub_r001795_13_1 <= 100));
  __CPROVER_assume((pub_r001795_13_2 >= (-100)) && (pub_r001795_13_2 <= 100));
  __CPROVER_assume((pub_r001795_14_1 >= (-100)) && (pub_r001795_14_1 <= 100));
  __CPROVER_assume((pub_r001795_14_2 >= (-100)) && (pub_r001795_14_2 <= 100));
  __CPROVER_assume((pub_r001795_15_1 >= (-100)) && (pub_r001795_15_1 <= 100));
  __CPROVER_assume((pub_r001795_15_2 >= (-100)) && (pub_r001795_15_2 <= 100));
  __CPROVER_assume((pub_r001795_16_1 >= (-100)) && (pub_r001795_16_1 <= 100));
  __CPROVER_assume((pub_r001795_16_2 >= (-100)) && (pub_r001795_16_2 <= 100));
  __CPROVER_assume((pub_r001795_17_1 >= (-100)) && (pub_r001795_17_1 <= 100));
  __CPROVER_assume((pub_r001795_17_2 >= (-100)) && (pub_r001795_17_2 <= 100));
  __CPROVER_assume((sec_r001795_0_1 >= 0) && (sec_r001795_0_1 <= 255));
  __CPROVER_assume((sec_r001795_0_2 >= 0) && (sec_r001795_0_2 <= 255));
  __CPROVER_assume((sec_r001795_1_1 >= 0) && (sec_r001795_1_1 <= 255));
  __CPROVER_assume((sec_r001795_1_2 >= 0) && (sec_r001795_1_2 <= 255));
  __CPROVER_assume((sec_r001795_2_1 >= 0) && (sec_r001795_2_1 <= 255));
  __CPROVER_assume((sec_r001795_2_2 >= 0) && (sec_r001795_2_2 <= 255));
  __CPROVER_assume((sec_r001795_3_1 >= 0) && (sec_r001795_3_1 <= 255));
  __CPROVER_assume((sec_r001795_3_2 >= 0) && (sec_r001795_3_2 <= 255));
  __CPROVER_assume((sec_r001795_4_1 >= 0) && (sec_r001795_4_1 <= 255));
  __CPROVER_assume((sec_r001795_4_2 >= 0) && (sec_r001795_4_2 <= 255));
  __CPROVER_assume((sec_r001795_5_1 >= 0) && (sec_r001795_5_1 <= 255));
  __CPROVER_assume((sec_r001795_5_2 >= 0) && (sec_r001795_5_2 <= 255));
  __CPROVER_assume((sec_r001795_6_1 >= 0) && (sec_r001795_6_1 <= 255));
  __CPROVER_assume((sec_r001795_6_2 >= 0) && (sec_r001795_6_2 <= 255));
  __CPROVER_assume((sec_r001795_7_1 >= 0) && (sec_r001795_7_1 <= 255));
  __CPROVER_assume((sec_r001795_7_2 >= 0) && (sec_r001795_7_2 <= 255));
  __CPROVER_assume((sec_r001795_8_1 >= 0) && (sec_r001795_8_1 <= 255));
  __CPROVER_assume((sec_r001795_8_2 >= 0) && (sec_r001795_8_2 <= 255));
  __CPROVER_assume((sec_r001795_9_1 >= 0) && (sec_r001795_9_1 <= 255));
  __CPROVER_assume((sec_r001795_9_2 >= 0) && (sec_r001795_9_2 <= 255));
  __CPROVER_assume((sec_r001795_10_1 >= 0) && (sec_r001795_10_1 <= 255));
  __CPROVER_assume((sec_r001795_10_2 >= 0) && (sec_r001795_10_2 <= 255));
  __CPROVER_assume((sec_r001795_11_1 >= 0) && (sec_r001795_11_1 <= 255));
  __CPROVER_assume((sec_r001795_11_2 >= 0) && (sec_r001795_11_2 <= 255));
  __CPROVER_assume((sec_r001795_12_1 >= 0) && (sec_r001795_12_1 <= 255));
  __CPROVER_assume((sec_r001795_12_2 >= 0) && (sec_r001795_12_2 <= 255));
  __CPROVER_assume((sec_r001795_13_1 >= 0) && (sec_r001795_13_1 <= 255));
  __CPROVER_assume((sec_r001795_13_2 >= 0) && (sec_r001795_13_2 <= 255));
  __CPROVER_assume((sec_r001795_14_1 >= 0) && (sec_r001795_14_1 <= 255));
  __CPROVER_assume((sec_r001795_14_2 >= 0) && (sec_r001795_14_2 <= 255));
  __CPROVER_assume((sec_r001795_15_1 >= 0) && (sec_r001795_15_1 <= 255));
  __CPROVER_assume((sec_r001795_15_2 >= 0) && (sec_r001795_15_2 <= 255));
  __CPROVER_assume((sec_r001795_16_1 >= 0) && (sec_r001795_16_1 <= 255));
  __CPROVER_assume((sec_r001795_16_2 >= 0) && (sec_r001795_16_2 <= 255));
  struct AudioFrame_R001795_9513_0 st_var_0_1 = {0};
  struct AudioFrame_R001795_9513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001795_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001795_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001795_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001795_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001795_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001795_0_2 + 7) & 15;
  struct FilterState_R001795_9513_1 st_var_1_1 = {0};
  struct FilterState_R001795_9513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001795_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001795_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001795_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001795_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001795_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001795_0_2 + 9) & 15;
  struct MatrixBlock_R001795_9513_2 st_var_2_1 = {0};
  struct MatrixBlock_R001795_9513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001795_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001795_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001795_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001795_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001795_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001795_0_2 + 11) & 15;
  struct EventLog_R001795_9513_3 st_var_3_1 = {0};
  struct EventLog_R001795_9513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001795_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001795_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001795_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001795_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001795_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001795_0_2 + 13) & 15;
  union PacketPayload_R001795_9513_0 u_var_1;
  union PacketPayload_R001795_9513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001795_9513_0(sec_r001795_0_1, sec_r001795_1_1, pub_r001795_2_1, pub_r001795_3_1);
  int helper_flow_0_2 = fn_R001795_9513_0(sec_r001795_0_2, sec_r001795_1_2, pub_r001795_2_2, pub_r001795_3_2);
  fn_R001795_9513_0_2(sec_r001795_0_1, sec_r001795_1_1, pub_r001795_2_1, pub_r001795_3_1, sec_r001795_0_2, sec_r001795_1_2, pub_r001795_2_2, pub_r001795_3_2);
  int helper_flow_1_1 = fn_R001795_9513_1(sec_r001795_1_1, pub_r001795_2_1, pub_r001795_3_1, pub_r001795_4_1);
  int helper_flow_1_2 = fn_R001795_9513_1(sec_r001795_1_2, pub_r001795_2_2, pub_r001795_3_2, pub_r001795_4_2);
  fn_R001795_9513_1_2(sec_r001795_1_1, pub_r001795_2_1, pub_r001795_3_1, pub_r001795_4_1, sec_r001795_1_2, pub_r001795_2_2, pub_r001795_3_2, pub_r001795_4_2);
  int helper_flow_2_1 = fn_R001795_9513_2(sec_r001795_2_1, sec_r001795_3_1, pub_r001795_4_1, pub_r001795_5_1);
  int helper_flow_2_2 = fn_R001795_9513_2(sec_r001795_2_2, sec_r001795_3_2, pub_r001795_4_2, pub_r001795_5_2);
  fn_R001795_9513_2_2(sec_r001795_2_1, sec_r001795_3_1, pub_r001795_4_1, pub_r001795_5_1, sec_r001795_2_2, sec_r001795_3_2, pub_r001795_4_2, pub_r001795_5_2);
  int helper_flow_3_1 = fn_R001795_9513_3(sec_r001795_3_1, sec_r001795_4_1, pub_r001795_5_1, pub_r001795_6_1);
  int helper_flow_3_2 = fn_R001795_9513_3(sec_r001795_3_2, sec_r001795_4_2, pub_r001795_5_2, pub_r001795_6_2);
  fn_R001795_9513_3_2(sec_r001795_3_1, sec_r001795_4_1, pub_r001795_5_1, pub_r001795_6_1, sec_r001795_3_2, sec_r001795_4_2, pub_r001795_5_2, pub_r001795_6_2);
  int helper_flow_4_1 = fn_R001795_9513_4(sec_r001795_4_1, sec_r001795_5_1, pub_r001795_6_1, pub_r001795_7_1);
  int helper_flow_4_2 = fn_R001795_9513_4(sec_r001795_4_2, sec_r001795_5_2, pub_r001795_6_2, pub_r001795_7_2);
  fn_R001795_9513_4_2(sec_r001795_4_1, sec_r001795_5_1, pub_r001795_6_1, pub_r001795_7_1, sec_r001795_4_2, sec_r001795_5_2, pub_r001795_6_2, pub_r001795_7_2);
  int helper_flow_5_1 = fn_R001795_9513_5(sec_r001795_5_1, sec_r001795_6_1, pub_r001795_7_1, pub_r001795_8_1);
  int helper_flow_5_2 = fn_R001795_9513_5(sec_r001795_5_2, sec_r001795_6_2, pub_r001795_7_2, pub_r001795_8_2);
  fn_R001795_9513_5_2(sec_r001795_5_1, sec_r001795_6_1, pub_r001795_7_1, pub_r001795_8_1, sec_r001795_5_2, sec_r001795_6_2, pub_r001795_7_2, pub_r001795_8_2);
  int stage_v_0_1 = ((helper_flow_1_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_0_2 = ((helper_flow_1_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((sec_r001795_2_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_1_2 = ((sec_r001795_2_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((pub_r001795_0_1 * 2) + 19) & 63;
  int stage_v_2_2 = ((pub_r001795_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001795_2_1 * 2) + 43) & 63;
  int stage_v_3_2 = ((pub_r001795_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001795_14_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_4_2 = ((sec_r001795_14_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((sec_r001795_9_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_5_2 = ((sec_r001795_9_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((pub_r001795_6_1 * 2) + 28) & 63;
  int stage_v_6_2 = ((pub_r001795_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001795_2_1 * 2) + 44) & 63;
  int stage_v_7_2 = ((pub_r001795_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001795_2_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001795_2_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001795_11_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001795_11_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((pub_r001795_8_1 * 2) + 23) & 63;
  int stage_v_10_2 = ((pub_r001795_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001795_2_1 * 2) + 12) & 63;
  int stage_v_11_2 = ((pub_r001795_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001795_7_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001795_7_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((pub_r001795_17_1 * 2) + 12) & 63;
  int stage_v_13_2 = ((pub_r001795_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001795_4_1 * 2) + 19) & 63;
  int stage_v_14_2 = ((pub_r001795_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001795_11_1 * 2) + 35) & 63;
  int stage_v_15_2 = ((pub_r001795_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001795_8_1 * 2) + 5) & 63;
  int stage_v_16_2 = ((pub_r001795_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001795_12_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_17_2 = ((sec_r001795_12_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((pub_r001795_8_1 * 2) + 39) & 63;
  int stage_v_18_2 = ((pub_r001795_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((stage_v_17_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_19_2 = ((stage_v_17_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_19_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_19_2 + 1) & 15;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = ((sec_r001795_3_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001795_3_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001795_8_1 * 2) + 22) & 63;
  int stage_v_21_2 = ((pub_r001795_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((helper_flow_5_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_22_2 = ((helper_flow_5_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((helper_flow_0_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_23_2 = ((helper_flow_0_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((stage_v_22_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_24_2 = ((stage_v_22_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((pub_r001795_6_1 * 2) + 28) & 63;
  int stage_v_25_2 = ((pub_r001795_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001795_9_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_26_2 = ((sec_r001795_9_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((sec_r001795_4_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_27_2 = ((sec_r001795_4_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((pub_r001795_12_1 * 2) + 25) & 63;
  int stage_v_28_2 = ((pub_r001795_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((stage_v_1_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_29_2 = ((stage_v_1_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001795_13_1 * 2) + 7) & 63;
  int stage_v_30_2 = ((pub_r001795_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_27_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_31_2 = ((stage_v_27_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((stage_v_22_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_32_2 = ((stage_v_22_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_32_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_32_2 + 1) & 15;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = ((pub_r001795_4_1 * 2) + 29) & 63;
  int stage_v_33_2 = ((pub_r001795_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001795_6_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001795_6_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((stage_v_27_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_35_2 = ((stage_v_27_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((stage_v_29_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_36_2 = ((stage_v_29_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((pub_r001795_12_1 * 2) + 48) & 63;
  int stage_v_37_2 = ((pub_r001795_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001795_5_1 * 2) + 46) & 63;
  int stage_v_38_2 = ((pub_r001795_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001795_14_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_39_2 = ((sec_r001795_14_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((pub_r001795_0_1 * 2) + 27) & 63;
  int stage_v_40_2 = ((pub_r001795_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((stage_v_24_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_41_2 = ((stage_v_24_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((stage_v_9_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_42_2 = ((stage_v_9_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((pub_r001795_8_1 * 2) + 19) & 63;
  int stage_v_43_2 = ((pub_r001795_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((stage_v_27_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_27_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((pub_r001795_11_1 * 2) + 14) & 63;
  int stage_v_45_2 = ((pub_r001795_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((stage_v_26_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_26_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001795_7_1 * 2) + 18) & 63;
  int stage_v_47_2 = ((pub_r001795_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001795_15_1 * 2) + 20) & 63;
  int stage_v_48_2 = ((pub_r001795_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001795_13_1 * 2) + 11) & 63;
  int stage_v_49_2 = ((pub_r001795_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((helper_flow_2_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_50_2 = ((helper_flow_2_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((stage_v_27_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_51_2 = ((stage_v_27_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((pub_r001795_14_1 * 2) + 20) & 63;
  int stage_v_52_2 = ((pub_r001795_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001795_12_1 * 2) + 10) & 63;
  int stage_v_53_2 = ((pub_r001795_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001795_16_1 * 2) + 10) & 63;
  int stage_v_54_2 = ((pub_r001795_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001795_14_1 * 2) + 28) & 63;
  int stage_v_55_2 = ((pub_r001795_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001795_10_1 * 2) + 16) & 63;
  int stage_v_56_2 = ((pub_r001795_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001795_3_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_57_2 = ((sec_r001795_3_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((stage_v_0_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_58_2 = ((stage_v_0_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((pub_r001795_15_1 * 2) + 50) & 63;
  int stage_v_59_2 = ((pub_r001795_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((sec_r001795_2_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_60_2 = ((sec_r001795_2_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((sec_r001795_5_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_61_2 = ((sec_r001795_5_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_51_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_51_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((pub_r001795_3_1 * 2) + 47) & 63;
  int stage_v_63_2 = ((pub_r001795_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001795_11_1 * 2) + 15) & 63;
  int stage_v_64_2 = ((pub_r001795_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_23_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_65_2 = ((stage_v_23_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((pub_r001795_3_1 * 2) + 18) & 63;
  int stage_v_66_2 = ((pub_r001795_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((sec_r001795_7_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_67_2 = ((sec_r001795_7_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001795_1_1 * 2) + 41) & 63;
  int stage_v_68_2 = ((pub_r001795_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((stage_v_4_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_69_2 = ((stage_v_4_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((pub_r001795_8_1 * 2) + 16) & 63;
  int stage_v_70_2 = ((pub_r001795_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_60_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_71_2 = ((stage_v_60_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_71_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_71_2 + 1) & 15;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = ((stage_v_50_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_50_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001795_5_1 * 2) + 12) & 63;
  int stage_v_73_2 = ((pub_r001795_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001795_9_1 * 2) + 20) & 63;
  int stage_v_74_2 = ((pub_r001795_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_41_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_41_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((pub_r001795_17_1 * 2) + 15) & 63;
  int stage_v_76_2 = ((pub_r001795_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001795_5_1 * 2) + 10) & 63;
  int stage_v_77_2 = ((pub_r001795_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001795_4_1 * 2) + 29) & 63;
  int stage_v_78_2 = ((pub_r001795_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((sec_r001795_16_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_79_2 = ((sec_r001795_16_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((stage_v_42_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_42_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((sec_r001795_0_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_81_2 = ((sec_r001795_0_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((sec_r001795_4_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_82_2 = ((sec_r001795_4_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((sec_r001795_5_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_83_2 = ((sec_r001795_5_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((pub_r001795_0_1 * 2) + 43) & 63;
  int stage_v_84_2 = ((pub_r001795_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_24_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_24_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((pub_r001795_2_1 * 2) + 21) & 63;
  int stage_v_86_2 = ((pub_r001795_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((sec_r001795_13_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_87_2 = ((sec_r001795_13_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_87_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_87_2 + 1) & 15;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = ((pub_r001795_15_1 * 2) + 35) & 63;
  int stage_v_88_2 = ((pub_r001795_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_75_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_89_2 = ((stage_v_75_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((pub_r001795_15_1 * 2) + 28) & 63;
  int stage_v_90_2 = ((pub_r001795_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((sec_r001795_6_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_91_2 = ((sec_r001795_6_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((pub_r001795_7_1 * 2) + 42) & 63;
  int stage_v_92_2 = ((pub_r001795_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((stage_v_9_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_9_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((helper_flow_3_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_94_2 = ((helper_flow_3_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((stage_v_42_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_95_2 = ((stage_v_42_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((stage_v_94_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_94_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001795_12_1 * 2) + 33) & 63;
  int stage_v_97_2 = ((pub_r001795_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_26_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_26_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001795_10_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001795_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((sec_r001795_3_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_100_2 = ((sec_r001795_3_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((pub_r001795_14_1 * 2) + 14) & 63;
  int stage_v_101_2 = ((pub_r001795_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001795_14_1 * 2) + 14) & 63;
  int stage_v_102_2 = ((pub_r001795_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_96_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_96_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((stage_v_60_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_104_2 = ((stage_v_60_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001795_6_1 * 2) + 36) & 63;
  int stage_v_105_2 = ((pub_r001795_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001795_2_1 * 2) + 41) & 63;
  int stage_v_106_2 = ((pub_r001795_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_46_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_46_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001795_14_1 * 2) + 15) & 63;
  int stage_v_108_2 = ((pub_r001795_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_24_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_24_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((sec_r001795_13_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_110_2 = ((sec_r001795_13_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((sec_r001795_8_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_111_2 = ((sec_r001795_8_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((sec_r001795_5_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_112_2 = ((sec_r001795_5_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((pub_r001795_11_1 * 2) + 19) & 63;
  int stage_v_113_2 = ((pub_r001795_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001795_17_1 * 2) + 31) & 63;
  int stage_v_114_2 = ((pub_r001795_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_5_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_5_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((stage_v_98_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_98_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((pub_r001795_3_1 * 2) + 45) & 63;
  int stage_v_117_2 = ((pub_r001795_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_115_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_118_2 = ((stage_v_115_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_118_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_118_2 + 1) & 15;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = ((pub_r001795_4_1 * 2) + 12) & 63;
  int stage_v_119_2 = ((pub_r001795_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001795_11_1 * 2) + 35) & 63;
  int stage_v_120_2 = ((pub_r001795_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001795_7_1 * 2) + 39) & 63;
  int stage_v_121_2 = ((pub_r001795_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((stage_v_109_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_109_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((stage_v_34_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_123_2 = ((stage_v_34_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_123_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_123_2 + 1) & 15;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = ((stage_v_100_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_100_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((stage_v_82_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_82_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((sec_r001795_6_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_126_2 = ((sec_r001795_6_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((pub_r001795_16_1 * 2) + 46) & 63;
  int stage_v_127_2 = ((pub_r001795_16_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001795_6_1 * 2) + 43) & 63;
  int stage_v_128_2 = ((pub_r001795_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((stage_v_72_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_129_2 = ((stage_v_72_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001795_6_1 * 2) + 6) & 63;
  int stage_v_130_2 = ((pub_r001795_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001795_14_1 * 2) + 38) & 63;
  int stage_v_131_2 = ((pub_r001795_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_104_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_132_2 = ((stage_v_104_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((pub_r001795_13_1 * 2) + 45) & 63;
  int stage_v_133_2 = ((pub_r001795_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_20_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_134_2 = ((stage_v_20_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((pub_r001795_13_1 * 2) + 24) & 63;
  int stage_v_135_2 = ((pub_r001795_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_134_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_134_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((sec_r001795_11_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_137_2 = ((sec_r001795_11_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((pub_r001795_7_1 * 2) + 18) & 63;
  int stage_v_138_2 = ((pub_r001795_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((stage_v_9_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_9_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((pub_r001795_16_1 * 2) + 18) & 63;
  int stage_v_140_2 = ((pub_r001795_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001795_13_1 * 2) + 33) & 63;
  int stage_v_141_2 = ((pub_r001795_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001795_0_1 * 2) + 49) & 63;
  int stage_v_142_2 = ((pub_r001795_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001795_11_1 * 2) + 41) & 63;
  int stage_v_143_2 = ((pub_r001795_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_93_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_93_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_67_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_67_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((sec_r001795_14_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_146_2 = ((sec_r001795_14_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_34_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_34_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001795_0_1 * 2) + 30) & 63;
  int stage_v_148_2 = ((pub_r001795_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001795_8_1 * 2) + 43) & 63;
  int stage_v_149_2 = ((pub_r001795_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001795_17_1 * 2) + 22) & 63;
  int stage_v_150_2 = ((pub_r001795_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_125_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_125_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((stage_v_107_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_107_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((stage_v_94_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_94_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((sec_r001795_2_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_154_2 = ((sec_r001795_2_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_61_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_61_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((stage_v_72_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_156_2 = ((stage_v_72_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((pub_r001795_4_1 * 2) + 35) & 63;
  int stage_v_157_2 = ((pub_r001795_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_80_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_80_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((pub_r001795_0_1 * 2) + 29) & 63;
  int stage_v_159_2 = ((pub_r001795_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001795_2_1 * 2) + 38) & 63;
  int stage_v_160_2 = ((pub_r001795_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_65_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_65_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((stage_v_91_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_91_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001795_2_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001795_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001795_15_1 * 2) + 8) & 63;
  int stage_v_164_2 = ((pub_r001795_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_24_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_24_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((stage_v_20_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_20_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((pub_r001795_4_1 * 2) + 29) & 63;
  int stage_v_167_2 = ((pub_r001795_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001795_3_1 * 2) + 49) & 63;
  int stage_v_168_2 = ((pub_r001795_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((stage_v_4_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_4_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_112_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_112_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((sec_r001795_8_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_171_2 = ((sec_r001795_8_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001795_6_1 * 2) + 26) & 63;
  int stage_v_172_2 = ((pub_r001795_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((stage_v_44_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_173_2 = ((stage_v_44_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_173_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_173_2 + 1) & 15;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = ((sec_r001795_13_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_174_2 = ((sec_r001795_13_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((pub_r001795_5_1 * 2) + 22) & 63;
  int stage_v_175_2 = ((pub_r001795_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((sec_r001795_1_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_176_2 = ((sec_r001795_1_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_176_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_176_2 + 1) & 15;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = ((pub_r001795_5_1 * 2) + 35) & 63;
  int stage_v_177_2 = ((pub_r001795_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_107_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_107_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((stage_v_93_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_93_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((stage_v_20_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_180_2 = ((stage_v_20_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001795_15_1 * 2) + 40) & 63;
  int stage_v_181_2 = ((pub_r001795_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_180_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_180_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((pub_r001795_9_1 * 2) + 28) & 63;
  int stage_v_183_2 = ((pub_r001795_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001795_1_1 * 2) + 8) & 63;
  int stage_v_184_2 = ((pub_r001795_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001795_7_1 * 2) + 11) & 63;
  int stage_v_185_2 = ((pub_r001795_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_145_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_186_2 = ((stage_v_145_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_186_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_186_2 + 1) & 15;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = ((stage_v_147_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_147_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_98_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_98_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001795_1_1 * 2) + 12) & 63;
  int stage_v_189_2 = ((pub_r001795_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001795_6_1 * 2) + 31) & 63;
  int stage_v_190_2 = ((pub_r001795_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_187_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_187_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((stage_v_39_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_192_2 = ((stage_v_39_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((pub_r001795_9_1 * 2) + 24) & 63;
  int stage_v_193_2 = ((pub_r001795_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_17_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_17_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001795_3_1 * 2) + 19) & 63;
  int stage_v_195_2 = ((pub_r001795_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001795_0_1 * 2) + 16) & 63;
  int stage_v_196_2 = ((pub_r001795_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001795_5_1 * 2) + 38) & 63;
  int stage_v_197_2 = ((pub_r001795_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001795_8_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001795_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_96_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_96_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((sec_r001795_7_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_200_2 = ((sec_r001795_7_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((pub_r001795_9_1 * 2) + 11) & 63;
  int stage_v_201_2 = ((pub_r001795_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001795_6_1 * 2) + 14) & 63;
  int stage_v_202_2 = ((pub_r001795_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((stage_v_75_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_203_2 = ((stage_v_75_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_203_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_203_2 + 1) & 15;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = ((pub_r001795_6_1 * 2) + 48) & 63;
  int stage_v_204_2 = ((pub_r001795_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((pub_r001795_12_1 * 2) + 40) & 63;
  int stage_v_205_2 = ((pub_r001795_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((stage_v_139_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_206_2 = ((stage_v_139_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001795_2_1 * 2) + 6) & 63;
  int stage_v_207_2 = ((pub_r001795_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001795_14_1 * 2) + 32) & 63;
  int stage_v_208_2 = ((pub_r001795_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001795_15_1 * 2) + 25) & 63;
  int stage_v_209_2 = ((pub_r001795_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_98_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_98_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_12_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_12_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((pub_r001795_0_1 * 2) + 37) & 63;
  int stage_v_212_2 = ((pub_r001795_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001795_3_1 * 2) + 39) & 63;
  int stage_v_213_2 = ((pub_r001795_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_46_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_46_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((pub_r001795_16_1 * 2) + 30) & 63;
  int stage_v_215_2 = ((pub_r001795_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((helper_flow_1_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_216_2 = ((helper_flow_1_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_176_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_176_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((pub_r001795_17_1 * 2) + 30) & 63;
  int stage_v_218_2 = ((pub_r001795_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001795_2_1 * 2) + 26) & 63;
  int stage_v_219_2 = ((pub_r001795_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001795_7_1 * 2) + 49) & 63;
  int stage_v_220_2 = ((pub_r001795_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001795_1_1 * 2) + 21) & 63;
  int stage_v_221_2 = ((pub_r001795_1_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_69_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_69_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001795_15_1 * 2) + 7) & 63;
  int stage_v_223_2 = ((pub_r001795_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001795_10_1 * 2) + 15) & 63;
  int stage_v_224_2 = ((pub_r001795_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001795_12_1 * 2) + 48) & 63;
  int stage_v_225_2 = ((pub_r001795_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((sec_r001795_1_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_226_2 = ((sec_r001795_1_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((stage_v_180_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_180_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_12_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_12_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((stage_v_191_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_191_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((helper_flow_4_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_230_2 = ((helper_flow_4_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((pub_r001795_17_1 * 2) + 18) & 63;
  int stage_v_231_2 = ((pub_r001795_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001795_2_1 * 2) + 29) & 63;
  int stage_v_232_2 = ((pub_r001795_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001795_0_1 * 2) + 18) & 63;
  int stage_v_233_2 = ((pub_r001795_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_31_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_31_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_182_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_182_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_165_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_165_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((pub_r001795_0_1 * 2) + 28) & 63;
  int stage_v_237_2 = ((pub_r001795_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001795_8_1 * 2) + 48) & 63;
  int stage_v_238_2 = ((pub_r001795_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_27_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_27_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((pub_r001795_17_1 * 2) + 43) & 63;
  int stage_v_240_2 = ((pub_r001795_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((stage_v_104_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_104_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001795_9_1 * 2) + 20) & 63;
  int stage_v_242_2 = ((pub_r001795_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_41_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_41_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_227_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_227_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((stage_v_26_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_245_2 = ((stage_v_26_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001795_1_1 * 2) + 17) & 63;
  int stage_v_246_2 = ((pub_r001795_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001795_15_1 * 2) + 37) & 63;
  int stage_v_247_2 = ((pub_r001795_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((sec_r001795_7_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_248_2 = ((sec_r001795_7_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_216_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_216_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((stage_v_67_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_250_2 = ((stage_v_67_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((pub_r001795_7_1 * 2) + 36) & 63;
  int stage_v_251_2 = ((pub_r001795_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((sec_r001795_6_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_252_2 = ((sec_r001795_6_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_243_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_243_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((pub_r001795_4_1 * 2) + 25) & 63;
  int stage_v_254_2 = ((pub_r001795_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((stage_v_112_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_112_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_122_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_122_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((stage_v_23_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_257_2 = ((stage_v_23_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((stage_v_29_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_29_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((sec_r001795_13_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_259_2 = ((sec_r001795_13_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001795_1_1 * 2) + 28) & 63;
  int stage_v_260_2 = ((pub_r001795_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001795_12_1 * 2) + 5) & 63;
  int stage_v_261_2 = ((pub_r001795_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((stage_v_214_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_262_2 = ((stage_v_214_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_262_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_262_2 + 1) & 15;
  out_sink_1 ^= stage_v_262_1 & 63;
  out_sink_2 ^= stage_v_262_2 & 63;
  int stage_v_263_1 = ((pub_r001795_0_1 * 2) + 20) & 63;
  int stage_v_263_2 = ((pub_r001795_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_139_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_139_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((pub_r001795_12_1 * 2) + 33) & 63;
  int stage_v_265_2 = ((pub_r001795_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((stage_v_98_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_98_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((pub_r001795_12_1 * 2) + 8) & 63;
  int stage_v_267_2 = ((pub_r001795_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001795_1_1 * 2) + 14) & 63;
  int stage_v_268_2 = ((pub_r001795_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001795_12_1 * 2) + 9) & 63;
  int stage_v_269_2 = ((pub_r001795_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001795_14_1 * 2) + 8) & 63;
  int stage_v_270_2 = ((pub_r001795_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001795_0_1 * 2) + 19) & 63;
  int stage_v_271_2 = ((pub_r001795_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_255_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_255_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_41_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_41_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((stage_v_61_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_274_2 = ((stage_v_61_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_274_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_274_2 + 1) & 15;
  out_sink_1 ^= stage_v_274_1 & 63;
  out_sink_2 ^= stage_v_274_2 & 63;
  int stage_v_275_1 = ((pub_r001795_1_1 * 2) + 18) & 63;
  int stage_v_275_2 = ((pub_r001795_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001795_6_1 * 2) + 17) & 63;
  int stage_v_276_2 = ((pub_r001795_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((stage_v_123_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_123_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001795_13_1 * 2) + 5) & 63;
  int stage_v_278_2 = ((pub_r001795_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001795_4_1 * 2) + 37) & 63;
  int stage_v_279_2 = ((pub_r001795_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001795_4_1 * 2) + 35) & 63;
  int stage_v_280_2 = ((pub_r001795_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001795_1_1 * 2) + 31) & 63;
  int stage_v_281_2 = ((pub_r001795_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_191_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_191_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((pub_r001795_6_1 * 2) + 26) & 63;
  int stage_v_283_2 = ((pub_r001795_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001795_10_1 * 2) + 21) & 63;
  int stage_v_284_2 = ((pub_r001795_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((stage_v_136_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_136_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((pub_r001795_9_1 * 2) + 25) & 63;
  int stage_v_286_2 = ((pub_r001795_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((stage_v_156_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_287_2 = ((stage_v_156_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001795_17_1 * 2) + 13) & 63;
  int stage_v_288_2 = ((pub_r001795_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001795_5_1 * 2) + 15) & 63;
  int stage_v_289_2 = ((pub_r001795_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((stage_v_272_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_272_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((sec_r001795_10_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_291_2 = ((sec_r001795_10_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((pub_r001795_14_1 * 2) + 22) & 63;
  int stage_v_292_2 = ((pub_r001795_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((stage_v_79_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_79_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((pub_r001795_16_1 * 2) + 10) & 63;
  int stage_v_294_2 = ((pub_r001795_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001795_2_1 * 2) + 34) & 63;
  int stage_v_295_2 = ((pub_r001795_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((stage_v_272_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_272_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((stage_v_191_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_297_2 = ((stage_v_191_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_51_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_51_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_134_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_134_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_199_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_199_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001795_0_1 * 2) + 49) & 63;
  int stage_v_301_2 = ((pub_r001795_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001795_14_1 * 2) + 12) & 63;
  int stage_v_302_2 = ((pub_r001795_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((stage_v_103_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_103_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001795_5_1 * 2) + 5) & 63;
  int stage_v_304_2 = ((pub_r001795_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001795_12_1 * 2) + 34) & 63;
  int stage_v_305_2 = ((pub_r001795_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_44_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_44_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((stage_v_300_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_307_2 = ((stage_v_300_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((stage_v_226_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_226_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_154_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_154_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_65_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_65_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((pub_r001795_14_1 * 2) + 48) & 63;
  int stage_v_311_2 = ((pub_r001795_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001795_0_1 * 2) + 12) & 63;
  int stage_v_312_2 = ((pub_r001795_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001795_4_1 * 2) + 33) & 63;
  int stage_v_313_2 = ((pub_r001795_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001795_14_1 * 2) + 15) & 63;
  int stage_v_314_2 = ((pub_r001795_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001795_13_1 * 2) + 31) & 63;
  int stage_v_315_2 = ((pub_r001795_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001795_12_1 * 2) + 7) & 63;
  int stage_v_316_2 = ((pub_r001795_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001795_0_1 * 2) + 14) & 63;
  int stage_v_317_2 = ((pub_r001795_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001795_17_1 * 2) + 20) & 63;
  int stage_v_318_2 = ((pub_r001795_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((stage_v_62_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_62_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((pub_r001795_9_1 * 2) + 25) & 63;
  int stage_v_320_2 = ((pub_r001795_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001795_17_1 * 2) + 14) & 63;
  int stage_v_321_2 = ((pub_r001795_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001795_13_1 * 2) + 46) & 63;
  int stage_v_322_2 = ((pub_r001795_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((stage_v_236_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_236_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001795_7_1 * 2) + 7) & 63;
  int stage_v_324_2 = ((pub_r001795_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001795_9_1 * 2) + 36) & 63;
  int stage_v_325_2 = ((pub_r001795_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((stage_v_1_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_1_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((stage_v_24_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_24_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((stage_v_46_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_46_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((pub_r001795_12_1 * 2) + 26) & 63;
  int stage_v_329_2 = ((pub_r001795_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_62_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_62_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((stage_v_79_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_331_2 = ((stage_v_79_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_331_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_331_2 + 1) & 15;
  out_sink_1 ^= stage_v_331_1 & 63;
  out_sink_2 ^= stage_v_331_2 & 63;
  int stage_v_332_1 = ((stage_v_8_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_8_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((pub_r001795_10_1 * 2) + 20) & 63;
  int stage_v_333_2 = ((pub_r001795_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((stage_v_194_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_194_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((helper_flow_2_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_335_2 = ((helper_flow_2_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001795_8_1 * 2) + 16) & 63;
  int stage_v_336_2 = ((pub_r001795_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((stage_v_229_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_337_2 = ((stage_v_229_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_337_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_337_2 + 1) & 15;
  out_sink_1 ^= stage_v_337_1 & 63;
  out_sink_2 ^= stage_v_337_2 & 63;
  int stage_v_338_1 = ((pub_r001795_11_1 * 2) + 17) & 63;
  int stage_v_338_2 = ((pub_r001795_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001795_5_1 * 2) + 28) & 63;
  int stage_v_339_2 = ((pub_r001795_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001795_11_1 * 2) + 13) & 63;
  int stage_v_340_2 = ((pub_r001795_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((stage_v_191_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_191_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((stage_v_75_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_75_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((pub_r001795_11_1 * 2) + 39) & 63;
  int stage_v_343_2 = ((pub_r001795_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001795_9_1 * 2) + 37) & 63;
  int stage_v_344_2 = ((pub_r001795_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001795_7_1 * 2) + 30) & 63;
  int stage_v_345_2 = ((pub_r001795_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((stage_v_110_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_110_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((pub_r001795_5_1 * 2) + 50) & 63;
  int stage_v_347_2 = ((pub_r001795_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001795_10_1 * 2) + 32) & 63;
  int stage_v_348_2 = ((pub_r001795_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((stage_v_236_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_236_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_170_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_170_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_155_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_155_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((stage_v_227_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_227_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((stage_v_126_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_353_2 = ((stage_v_126_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_353_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_353_2 + 1) & 15;
  out_sink_1 ^= stage_v_353_1 & 63;
  out_sink_2 ^= stage_v_353_2 & 63;
  int stage_v_354_1 = ((stage_v_155_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_354_2 = ((stage_v_155_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_354_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_354_2 + 1) & 15;
  out_sink_1 ^= stage_v_354_1 & 63;
  out_sink_2 ^= stage_v_354_2 & 63;
  int stage_v_355_1 = ((pub_r001795_14_1 * 2) + 30) & 63;
  int stage_v_355_2 = ((pub_r001795_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((helper_flow_1_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_356_2 = ((helper_flow_1_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_356_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_356_2 + 1) & 15;
  out_sink_1 ^= stage_v_356_1 & 63;
  out_sink_2 ^= stage_v_356_2 & 63;
  int stage_v_357_1 = ((stage_v_319_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_319_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((pub_r001795_17_1 * 2) + 19) & 63;
  int stage_v_358_2 = ((pub_r001795_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001795_3_1 * 2) + 19) & 63;
  int stage_v_359_2 = ((pub_r001795_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((stage_v_346_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_346_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001795_3_1 * 2) + 27) & 63;
  int stage_v_361_2 = ((pub_r001795_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_360_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_360_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((sec_r001795_1_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_363_2 = ((sec_r001795_1_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_110_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_110_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_360_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_360_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_91_1 << 1) ^ (pub_r001795_7_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_91_2 << 1) ^ (pub_r001795_7_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((stage_v_266_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_266_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((helper_flow_5_1 << 1) ^ (pub_r001795_13_1 >> 1)) & 127;
  int stage_v_368_2 = ((helper_flow_5_2 << 1) ^ (pub_r001795_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_368_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_368_2 + 1) & 15;
  out_sink_1 ^= stage_v_368_1 & 63;
  out_sink_2 ^= stage_v_368_2 & 63;
  int stage_v_369_1 = ((pub_r001795_12_1 * 2) + 47) & 63;
  int stage_v_369_2 = ((pub_r001795_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_241_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_241_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_57_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_57_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((pub_r001795_6_1 * 2) + 15) & 63;
  int stage_v_372_2 = ((pub_r001795_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((stage_v_306_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_306_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((stage_v_176_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_176_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001795_16_1 * 2) + 42) & 63;
  int stage_v_375_2 = ((pub_r001795_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_351_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_351_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((stage_v_362_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_362_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((pub_r001795_17_1 * 2) + 6) & 63;
  int stage_v_378_2 = ((pub_r001795_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001795_12_1 * 2) + 19) & 63;
  int stage_v_379_2 = ((pub_r001795_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((stage_v_362_1 << 1) ^ (pub_r001795_9_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_362_2 << 1) ^ (pub_r001795_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_111_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_111_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((stage_v_236_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_382_2 = ((stage_v_236_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_382_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_382_2 + 1) & 15;
  out_sink_1 ^= stage_v_382_1 & 63;
  out_sink_2 ^= stage_v_382_2 & 63;
  int stage_v_383_1 = ((pub_r001795_4_1 * 2) + 32) & 63;
  int stage_v_383_2 = ((pub_r001795_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001795_3_1 * 2) + 19) & 63;
  int stage_v_384_2 = ((pub_r001795_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001795_0_1 * 2) + 17) & 63;
  int stage_v_385_2 = ((pub_r001795_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((stage_v_236_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_236_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((stage_v_158_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_387_2 = ((stage_v_158_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_387_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_387_2 + 1) & 15;
  out_sink_1 ^= stage_v_387_1 & 63;
  out_sink_2 ^= stage_v_387_2 & 63;
  int stage_v_388_1 = ((stage_v_80_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_388_2 = ((stage_v_80_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_388_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_388_2 + 1) & 15;
  out_sink_1 ^= stage_v_388_1 & 63;
  out_sink_2 ^= stage_v_388_2 & 63;
  int stage_v_389_1 = ((stage_v_307_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_307_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((stage_v_349_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_390_2 = ((stage_v_349_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_390_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_390_2 + 1) & 15;
  out_sink_1 ^= stage_v_390_1 & 63;
  out_sink_2 ^= stage_v_390_2 & 63;
  int stage_v_391_1 = ((stage_v_67_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_67_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((pub_r001795_2_1 * 2) + 14) & 63;
  int stage_v_392_2 = ((pub_r001795_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((stage_v_226_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_226_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((pub_r001795_16_1 * 2) + 25) & 63;
  int stage_v_394_2 = ((pub_r001795_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((stage_v_72_1 << 1) ^ (pub_r001795_5_1 >> 1)) & 127;
  int stage_v_395_2 = ((stage_v_72_2 << 1) ^ (pub_r001795_5_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_395_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_395_2 + 1) & 15;
  out_sink_1 ^= stage_v_395_1 & 63;
  out_sink_2 ^= stage_v_395_2 & 63;
  int stage_v_396_1 = ((stage_v_309_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_309_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001795_11_1 * 2) + 36) & 63;
  int stage_v_397_2 = ((pub_r001795_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001795_6_1 * 2) + 17) & 63;
  int stage_v_398_2 = ((pub_r001795_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((stage_v_83_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_83_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((stage_v_274_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_400_2 = ((stage_v_274_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_400_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_400_2 + 1) & 15;
  out_sink_1 ^= stage_v_400_1 & 63;
  out_sink_2 ^= stage_v_400_2 & 63;
  int stage_v_401_1 = ((stage_v_107_1 << 1) ^ (pub_r001795_11_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_107_2 << 1) ^ (pub_r001795_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((pub_r001795_1_1 * 2) + 23) & 63;
  int stage_v_402_2 = ((pub_r001795_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((stage_v_94_1 << 1) ^ (pub_r001795_1_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_94_2 << 1) ^ (pub_r001795_1_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_171_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_171_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((stage_v_377_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_405_2 = ((stage_v_377_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_405_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_405_2 + 1) & 15;
  out_sink_1 ^= stage_v_405_1 & 63;
  out_sink_2 ^= stage_v_405_2 & 63;
  int stage_v_406_1 = ((stage_v_61_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_61_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((helper_flow_5_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_407_2 = ((helper_flow_5_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_407_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_407_2 + 1) & 15;
  out_sink_1 ^= stage_v_407_1 & 63;
  out_sink_2 ^= stage_v_407_2 & 63;
  int stage_v_408_1 = ((pub_r001795_4_1 * 2) + 36) & 63;
  int stage_v_408_2 = ((pub_r001795_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001795_9_1 * 2) + 49) & 63;
  int stage_v_409_2 = ((pub_r001795_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((stage_v_387_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_387_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((stage_v_191_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_411_2 = ((stage_v_191_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_411_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_411_2 + 1) & 15;
  out_sink_1 ^= stage_v_411_1 & 63;
  out_sink_2 ^= stage_v_411_2 & 63;
  int stage_v_412_1 = ((stage_v_17_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_17_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((pub_r001795_14_1 * 2) + 44) & 63;
  int stage_v_413_2 = ((pub_r001795_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001795_17_1 * 2) + 9) & 63;
  int stage_v_414_2 = ((pub_r001795_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((stage_v_35_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_35_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((stage_v_290_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_290_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001795_13_1 * 2) + 23) & 63;
  int stage_v_417_2 = ((pub_r001795_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001795_16_1 * 2) + 50) & 63;
  int stage_v_418_2 = ((pub_r001795_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((stage_v_365_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_365_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_323_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_323_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_352_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_352_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((stage_v_310_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_310_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((pub_r001795_7_1 * 2) + 45) & 63;
  int stage_v_423_2 = ((pub_r001795_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001795_8_1 * 2) + 12) & 63;
  int stage_v_424_2 = ((pub_r001795_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((stage_v_136_1 << 1) ^ (pub_r001795_4_1 >> 1)) & 127;
  int stage_v_425_2 = ((stage_v_136_2 << 1) ^ (pub_r001795_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_425_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_425_2 + 1) & 15;
  out_sink_1 ^= stage_v_425_1 & 63;
  out_sink_2 ^= stage_v_425_2 & 63;
  int stage_v_426_1 = ((stage_v_296_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_426_2 = ((stage_v_296_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_2_1.buffer[0] = (stage_v_426_1 + 1) & 15;
  st_var_2_2.buffer[0] = (stage_v_426_2 + 1) & 15;
  out_sink_1 ^= stage_v_426_1 & 63;
  out_sink_2 ^= stage_v_426_2 & 63;
  int stage_v_427_1 = ((stage_v_299_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_427_2 = ((stage_v_299_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((pub_r001795_3_1 * 2) + 44) & 63;
  int stage_v_428_2 = ((pub_r001795_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001795_17_1 * 2) + 37) & 63;
  int stage_v_429_2 = ((pub_r001795_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((stage_v_391_1 << 1) ^ (pub_r001795_14_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_391_2 << 1) ^ (pub_r001795_14_2 >> 1)) & 127;
  st_var_2_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_2_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((stage_v_103_1 << 1) ^ (pub_r001795_10_1 >> 1)) & 127;
  int stage_v_431_2 = ((stage_v_103_2 << 1) ^ (pub_r001795_10_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((pub_r001795_2_1 * 2) + 24) & 63;
  int stage_v_432_2 = ((pub_r001795_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((stage_v_122_1 << 1) ^ (pub_r001795_16_1 >> 1)) & 127;
  int stage_v_433_2 = ((stage_v_122_2 << 1) ^ (pub_r001795_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_433_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_433_2 + 1) & 15;
  out_sink_1 ^= stage_v_433_1 & 63;
  out_sink_2 ^= stage_v_433_2 & 63;
  int stage_v_434_1 = ((pub_r001795_15_1 * 2) + 26) & 63;
  int stage_v_434_2 = ((pub_r001795_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((stage_v_75_1 << 1) ^ (pub_r001795_15_1 >> 1)) & 127;
  int stage_v_435_2 = ((stage_v_75_2 << 1) ^ (pub_r001795_15_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_435_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_435_2 + 1) & 15;
  out_sink_1 ^= stage_v_435_1 & 63;
  out_sink_2 ^= stage_v_435_2 & 63;
  int stage_v_436_1 = ((pub_r001795_5_1 * 2) + 42) & 63;
  int stage_v_436_2 = ((pub_r001795_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001795_6_1 * 2) + 37) & 63;
  int stage_v_437_2 = ((pub_r001795_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001795_9_1 * 2) + 32) & 63;
  int stage_v_438_2 = ((pub_r001795_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001795_5_1 * 2) + 12) & 63;
  int stage_v_439_2 = ((pub_r001795_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001795_15_1 * 2) + 25) & 63;
  int stage_v_440_2 = ((pub_r001795_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001795_10_1 * 2) + 33) & 63;
  int stage_v_441_2 = ((pub_r001795_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001795_16_1 * 2) + 44) & 63;
  int stage_v_442_2 = ((pub_r001795_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((stage_v_129_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_443_2 = ((stage_v_129_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_3_1.buffer[2] = (stage_v_443_1 + 1) & 15;
  st_var_3_2.buffer[2] = (stage_v_443_2 + 1) & 15;
  out_sink_1 ^= stage_v_443_1 & 63;
  out_sink_2 ^= stage_v_443_2 & 63;
  int stage_v_444_1 = ((stage_v_309_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_444_2 = ((stage_v_309_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((pub_r001795_10_1 * 2) + 20) & 63;
  int stage_v_445_2 = ((pub_r001795_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((stage_v_129_1 << 1) ^ (pub_r001795_17_1 >> 1)) & 127;
  int stage_v_446_2 = ((stage_v_129_2 << 1) ^ (pub_r001795_17_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_446_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_446_2 + 1) & 15;
  out_sink_1 ^= stage_v_446_1 & 63;
  out_sink_2 ^= stage_v_446_2 & 63;
  int stage_v_447_1 = ((stage_v_144_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_447_2 = ((stage_v_144_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_447_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_447_2 + 1) & 15;
  out_sink_1 ^= stage_v_447_1 & 63;
  out_sink_2 ^= stage_v_447_2 & 63;
  int stage_v_448_1 = ((pub_r001795_3_1 * 2) + 27) & 63;
  int stage_v_448_2 = ((pub_r001795_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = ((stage_v_274_1 << 1) ^ (pub_r001795_8_1 >> 1)) & 127;
  int stage_v_449_2 = ((stage_v_274_2 << 1) ^ (pub_r001795_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_449_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_449_2 + 1) & 15;
  out_sink_1 ^= stage_v_449_1 & 63;
  out_sink_2 ^= stage_v_449_2 & 63;
  int stage_v_450_1 = ((pub_r001795_2_1 * 2) + 10) & 63;
  int stage_v_450_2 = ((pub_r001795_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((stage_v_67_1 << 1) ^ (pub_r001795_2_1 >> 1)) & 127;
  int stage_v_451_2 = ((stage_v_67_2 << 1) ^ (pub_r001795_2_2 >> 1)) & 127;
  st_var_3_1.buffer[1] = (stage_v_451_1 + 1) & 15;
  st_var_3_2.buffer[1] = (stage_v_451_2 + 1) & 15;
  out_sink_1 ^= stage_v_451_1 & 63;
  out_sink_2 ^= stage_v_451_2 & 63;
  int stage_v_452_1 = ((pub_r001795_14_1 * 2) + 18) & 63;
  int stage_v_452_2 = ((pub_r001795_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001795_17_1 * 2) + 21) & 63;
  int stage_v_453_2 = ((pub_r001795_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001795_8_1 * 2) + 43) & 63;
  int stage_v_454_2 = ((pub_r001795_8_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001795_0_1 * 2) + 23) & 63;
  int stage_v_455_2 = ((pub_r001795_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((helper_flow_0_1 << 1) ^ (pub_r001795_0_1 >> 1)) & 127;
  int stage_v_456_2 = ((helper_flow_0_2 << 1) ^ (pub_r001795_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_456_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_456_2 + 1) & 15;
  out_sink_1 ^= stage_v_456_1 & 63;
  out_sink_2 ^= stage_v_456_2 & 63;
  int stage_v_457_1 = ((pub_r001795_6_1 * 2) + 13) & 63;
  int stage_v_457_2 = ((pub_r001795_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001795_16_1 * 2) + 26) & 63;
  int stage_v_458_2 = ((pub_r001795_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((stage_v_110_1 << 1) ^ (pub_r001795_12_1 >> 1)) & 127;
  int stage_v_459_2 = ((stage_v_110_2 << 1) ^ (pub_r001795_12_2 >> 1)) & 127;
  st_var_3_1.buffer[0] = (stage_v_459_1 + 1) & 15;
  st_var_3_2.buffer[0] = (stage_v_459_2 + 1) & 15;
  out_sink_1 ^= stage_v_459_1 & 63;
  out_sink_2 ^= stage_v_459_2 & 63;
  int stage_v_460_1 = ((stage_v_146_1 << 1) ^ (pub_r001795_3_1 >> 1)) & 127;
  int stage_v_460_2 = ((stage_v_146_2 << 1) ^ (pub_r001795_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_460_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_460_2 + 1) & 15;
  out_sink_1 ^= stage_v_460_1 & 63;
  out_sink_2 ^= stage_v_460_2 & 63;
  int stage_v_461_1 = ((stage_v_42_1 << 1) ^ (pub_r001795_6_1 >> 1)) & 127;
  int stage_v_461_2 = ((stage_v_42_2 << 1) ^ (pub_r001795_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_461_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_461_2 + 1) & 15;
  out_sink_1 ^= stage_v_461_1 & 63;
  out_sink_2 ^= stage_v_461_2 & 63;
  int stage_v_462_1 = ((pub_r001795_8_1 * 2) + 9) & 63;
  int stage_v_462_2 = ((pub_r001795_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001795_9_1 != sec_r001795_9_2);
  __CPROVER_assume(sec_r001795_6_1 != sec_r001795_6_2);
  __CPROVER_assume(pub_r001795_4_1 == pub_r001795_4_2);
  __CPROVER_assume(sec_r001795_5_1 != sec_r001795_5_2);
  __CPROVER_assume(sec_r001795_14_1 != sec_r001795_14_2);
  __CPROVER_assume(pub_r001795_10_1 == pub_r001795_10_2);
  __CPROVER_assume(sec_r001795_0_1 != sec_r001795_0_2);
  __CPROVER_assume(sec_r001795_12_1 != sec_r001795_12_2);
  __CPROVER_assume(sec_r001795_7_1 != sec_r001795_7_2);
  __CPROVER_assume(pub_r001795_14_1 == pub_r001795_14_2);
  __CPROVER_assume(sec_r001795_8_1 != sec_r001795_8_2);
  __CPROVER_assume(pub_r001795_9_1 == pub_r001795_9_2);
  __CPROVER_assume(pub_r001795_1_1 == pub_r001795_1_2);
  __CPROVER_assume(sec_r001795_4_1 != sec_r001795_4_2);
  __CPROVER_assume(sec_r001795_11_1 != sec_r001795_11_2);
  __CPROVER_assume(sec_r001795_16_1 != sec_r001795_16_2);
  __CPROVER_assume(pub_r001795_15_1 == pub_r001795_15_2);
  __CPROVER_assume(pub_r001795_13_1 == pub_r001795_13_2);
  __CPROVER_assume(sec_r001795_3_1 != sec_r001795_3_2);
  __CPROVER_assume(pub_r001795_0_1 == pub_r001795_0_2);
  __CPROVER_assume(pub_r001795_7_1 == pub_r001795_7_2);
  __CPROVER_assume(sec_r001795_2_1 != sec_r001795_2_2);
  __CPROVER_assume(sec_r001795_15_1 != sec_r001795_15_2);
  __CPROVER_assume(pub_r001795_6_1 == pub_r001795_6_2);
  __CPROVER_assume(sec_r001795_1_1 != sec_r001795_1_2);
  __CPROVER_assume(pub_r001795_12_1 == pub_r001795_12_2);
  __CPROVER_assume(sec_r001795_13_1 != sec_r001795_13_2);
  __CPROVER_assume(pub_r001795_5_1 == pub_r001795_5_2);
  __CPROVER_assume(pub_r001795_16_1 == pub_r001795_16_2);
  __CPROVER_assume(pub_r001795_17_1 == pub_r001795_17_2);
  __CPROVER_assume(sec_r001795_10_1 != sec_r001795_10_2);
  __CPROVER_assume(pub_r001795_2_1 == pub_r001795_2_2);
  __CPROVER_assume(pub_r001795_8_1 == pub_r001795_8_2);
  __CPROVER_assume(pub_r001795_3_1 == pub_r001795_3_2);
  __CPROVER_assume(pub_r001795_11_1 == pub_r001795_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.trace == st_var_2_2.trace);
  assert(st_var_2_1.stride == st_var_2_2.stride);
  assert(st_var_2_1.density == st_var_2_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
  assert(st_var_3_1.code == st_var_3_2.code);
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
}


