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
struct StreamBuffer_R001195_9513_0
{
  int watermark;
  int state;
  int capacity;
  int checksum;
  int tail;
  int buffer[3];
};
struct AudioFrame_R001195_9513_1
{
  unsigned char peak;
  unsigned char sample_rate;
  unsigned char channels;
  unsigned char rms;
  unsigned char gain;
  unsigned char envelope;
  int buffer[3];
};
union TelemetryField_R001195_9513_0
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
void fn_R001195_9513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_65_1 > 36)
  {
    acc_1 = ((acc_1 + (metric_65_1 * 2)) + 5) & 127;
    aux_1 ^= metric_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_65_2 > 36)
  {
    acc_2 = ((acc_2 + (metric_65_2 * 2)) + 5) & 127;
    aux_2 ^= metric_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_37_1) & 63;
  aux_2 = (aux_2 + sample_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_81_1 = local_arr_1[aux_1 % 3];
  int quantum_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_65_1 == metric_65_2);
  assert(sample_37_1 == sample_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_81_1 == quantum_81_2);
}

int fn_R001195_9513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_65 > 36)
  {
    acc = ((acc + (metric_65 * 2)) + 5) & 127;
    aux ^= metric_65 & 15;
  }
  else
  {
    acc = ((acc - metric_65) + 11) & 127;
    aux += 3;
  }
  int sample_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_37) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_81 = local_arr[aux % 3];
  acc = (acc + (quantum_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int offset_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_56_1)
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

  switch (offset_56_2)
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

  int margin_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_59_1 > 31)
  {
    acc_1 = ((acc_1 + (margin_59_1 * 2)) + 5) & 127;
    aux_1 ^= margin_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_59_2 > 31)
  {
    acc_2 = ((acc_2 + (margin_59_2 * 2)) + 5) & 127;
    aux_2 ^= margin_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_20_1 = local_arr_1[aux_1 % 3];
  int index_reg_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_56_1 == offset_56_2);
  assert(margin_59_1 == margin_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_20_1 == index_reg_20_2);
}

int fn_R001195_9513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int offset_56 = (aux + st.buffer[1]) & 3;
  switch (offset_56)
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

  int margin_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_59 > 31)
  {
    acc = ((acc + (margin_59 * 2)) + 5) & 127;
    aux ^= margin_59 & 15;
  }
  else
  {
    acc = ((acc - margin_59) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_20 = local_arr[aux % 3];
  acc = (acc + (index_reg_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_33_1)
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

  switch (margin_33_2)
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

  int delta_61_1 = 0;
  int delta_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_61_1 = ((delta_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_61_2 = ((delta_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_61_1) & 127;
    acc_2 = (acc_2 + delta_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_33_1 == margin_33_2);
  assert(delta_61_1 == delta_61_2);
}

int fn_R001195_9513_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_33 = (aux + st.buffer[1]) & 3;
  switch (margin_33)
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

  int delta_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_61 = ((delta_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_18_1)
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

  switch (factor_18_2)
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

  int vector_48_1 = 0;
  int vector_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    vector_48_1 = ((vector_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_48_2 = ((vector_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_48_1) & 127;
    acc_2 = (acc_2 + vector_48_2) & 127;
  }

  int segment_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_66_1) & 63;
  aux_2 = (aux_2 + segment_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_18_1 == factor_18_2);
  assert(vector_48_1 == vector_48_2);
  assert(segment_66_1 == segment_66_2);
}

int fn_R001195_9513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_18 = (aux + st.buffer[1]) & 3;
  switch (factor_18)
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

  int vector_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    vector_48 = ((vector_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_48) & 127;
  }

  int segment_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001195_9513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_89_1 = 0;
  int tally_89_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_89_1 = ((tally_89_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_89_2 = ((tally_89_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_89_1) & 127;
    acc_2 = (acc_2 + tally_89_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_89_1 == tally_89_2);
}

int fn_R001195_9513_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_89 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_89 = ((tally_89 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_89) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_55_1 > 19)
  {
    acc_1 = ((acc_1 + (delta_55_1 * 2)) + 5) & 127;
    aux_1 ^= delta_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_55_2 > 19)
  {
    acc_2 = ((acc_2 + (delta_55_2 * 2)) + 5) & 127;
    aux_2 ^= delta_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
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

  int cursor_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_84_1) & 63;
  aux_2 = (aux_2 + cursor_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(residue_65_1 == residue_65_2);
  assert(cursor_84_1 == cursor_84_2);
}

int fn_R001195_9513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_55 > 19)
  {
    acc = ((acc + (delta_55 * 2)) + 5) & 127;
    aux ^= delta_55 & 15;
  }
  else
  {
    acc = ((acc - delta_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
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

  int cursor_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001195_9513_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_41_1)
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

  switch (scale_41_2)
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
  int scale_21_1 = local_arr_1[aux_1 % 3];
  int scale_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_41_1 == scale_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_21_1 == scale_21_2);
}

int fn_R001195_9513_6(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_41 = (aux + st.buffer[1]) & 3;
  switch (scale_41)
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
  int scale_21 = local_arr[aux % 3];
  acc = (acc + (scale_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int threshold_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_92_1 > 18)
  {
    acc_1 = ((acc_1 + (threshold_92_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_92_2 > 18)
  {
    acc_2 = ((acc_2 + (threshold_92_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_74_1) & 63;
  aux_2 = (aux_2 + pivot_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_82_1 = local_arr_1[aux_1 % 3];
  int mask_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_92_1 == threshold_92_2);
  assert(pivot_74_1 == pivot_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_82_1 == mask_82_2);
}

int fn_R001195_9513_7(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int threshold_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_92 > 18)
  {
    acc = ((acc + (threshold_92 * 2)) + 5) & 127;
    aux ^= threshold_92 & 15;
  }
  else
  {
    acc = ((acc - threshold_92) + 11) & 127;
    aux += 3;
  }
  int pivot_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_82 = local_arr[aux % 3];
  acc = (acc + (mask_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_40_1 = local_arr_1[aux_1 % 3];
  int mask_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_40_2 * 2)) & 127;
  int quantum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_35_1 > 41)
  {
    acc_1 = ((acc_1 + (quantum_35_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_35_2 > 41)
  {
    acc_2 = ((acc_2 + (quantum_35_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_40_1 == mask_40_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R001195_9513_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int mask_40 = local_arr[aux % 3];
  acc = (acc + (mask_40 * 2)) & 127;
  int quantum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_35 > 41)
  {
    acc = ((acc + (quantum_35 * 2)) + 5) & 127;
    aux ^= quantum_35 & 15;
  }
  else
  {
    acc = ((acc - quantum_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int weight_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_76_1)
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

  switch (weight_76_2)
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
  int scale_65_1 = local_arr_1[aux_1 % 3];
  int scale_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_65_2 * 2)) & 127;
  int window_82_1 = 0;
  int window_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_82_1 = ((window_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_82_2 = ((window_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_82_1) & 127;
    acc_2 = (acc_2 + window_82_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_76_1 == weight_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_65_1 == scale_65_2);
  assert(window_82_1 == window_82_2);
}

int fn_R001195_9513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int weight_76 = (aux + st.buffer[1]) & 3;
  switch (weight_76)
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
  int scale_65 = local_arr[aux % 3];
  acc = (acc + (scale_65 * 2)) & 127;
  int window_82 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_82 = ((window_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_82) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_40_1) & 63;
  aux_2 = (aux_2 + damping_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_79_1 > 49)
  {
    acc_1 = ((acc_1 + (tally_79_1 * 2)) + 5) & 127;
    aux_1 ^= tally_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_79_2 > 49)
  {
    acc_2 = ((acc_2 + (tally_79_2 * 2)) + 5) & 127;
    aux_2 ^= tally_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_42_1 = 0;
  int factor_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_42_1 = ((factor_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_42_2 = ((factor_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_42_1) & 127;
    acc_2 = (acc_2 + factor_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_40_1 == damping_40_2);
  assert(tally_79_1 == tally_79_2);
  assert(factor_42_1 == factor_42_2);
}

int fn_R001195_9513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_40) & 63;
  acc ^= aux;
  int tally_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_79 > 49)
  {
    acc = ((acc + (tally_79 * 2)) + 5) & 127;
    aux ^= tally_79 & 15;
  }
  else
  {
    acc = ((acc - tally_79) + 11) & 127;
    aux += 3;
  }
  int factor_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_42 = ((factor_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_26_1 = local_arr_1[aux_1 % 3];
  int bound_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_26_2 * 2)) & 127;
  int bound_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_44_1 > 30)
  {
    acc_1 = ((acc_1 + (bound_44_1 * 2)) + 5) & 127;
    aux_1 ^= bound_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_44_2 > 30)
  {
    acc_2 = ((acc_2 + (bound_44_2 * 2)) + 5) & 127;
    aux_2 ^= bound_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_25_1 = 0;
  int metric_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_25_1 = ((metric_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_25_2 = ((metric_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_25_1) & 127;
    acc_2 = (acc_2 + metric_25_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_26_1 == bound_26_2);
  assert(bound_44_1 == bound_44_2);
  assert(metric_25_1 == metric_25_2);
}

int fn_R001195_9513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int bound_26 = local_arr[aux % 3];
  acc = (acc + (bound_26 * 2)) & 127;
  int bound_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_44 > 30)
  {
    acc = ((acc + (bound_44 * 2)) + 5) & 127;
    aux ^= bound_44 & 15;
  }
  else
  {
    acc = ((acc - bound_44) + 11) & 127;
    aux += 3;
  }
  int metric_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_25 = ((metric_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_25) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_85_1)
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

  switch (anchor_85_2)
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

  int damping_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_57_1 > 40)
  {
    acc_1 = ((acc_1 + (damping_57_1 * 2)) + 5) & 127;
    aux_1 ^= damping_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_57_2 > 40)
  {
    acc_2 = ((acc_2 + (damping_57_2 * 2)) + 5) & 127;
    aux_2 ^= damping_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_19_1 = 0;
  int coefficient_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_19_1 = ((coefficient_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_19_2 = ((coefficient_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_19_1) & 127;
    acc_2 = (acc_2 + coefficient_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_85_1 == anchor_85_2);
  assert(damping_57_1 == damping_57_2);
  assert(coefficient_19_1 == coefficient_19_2);
}

int fn_R001195_9513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_85 = (aux + st.buffer[1]) & 3;
  switch (anchor_85)
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

  int damping_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_57 > 40)
  {
    acc = ((acc + (damping_57 * 2)) + 5) & 127;
    aux ^= damping_57 & 15;
  }
  else
  {
    acc = ((acc - damping_57) + 11) & 127;
    aux += 3;
  }
  int coefficient_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_19 = ((coefficient_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int threshold_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_84_1) & 63;
  aux_2 = (aux_2 + threshold_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_72_1 = 0;
  int threshold_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_72_1 = ((threshold_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_72_2 = ((threshold_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_72_1) & 127;
    acc_2 = (acc_2 + threshold_72_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_85_1 = local_arr_1[aux_1 % 3];
  int sample_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_84_1 == threshold_84_2);
  assert(threshold_72_1 == threshold_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_85_1 == sample_85_2);
}

int fn_R001195_9513_13(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int threshold_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_84) & 63;
  acc ^= aux;
  int threshold_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_72 = ((threshold_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_72) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int sample_85 = local_arr[aux % 3];
  acc = (acc + (sample_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_86_1)
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

  switch (factor_86_2)
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

  int delta_87_1 = 0;
  int delta_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_87_1 = ((delta_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_87_2 = ((delta_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_87_1) & 127;
    acc_2 = (acc_2 + delta_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_86_1 == factor_86_2);
  assert(delta_87_1 == delta_87_2);
}

int fn_R001195_9513_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_86 = (aux + st.buffer[1]) & 3;
  switch (factor_86)
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

  int delta_87 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_87 = ((delta_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quantum_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_97_1)
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

  switch (quantum_97_2)
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

  int sample_73_1 = 0;
  int sample_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_73_1 = ((sample_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_73_2 = ((sample_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_73_1) & 127;
    acc_2 = (acc_2 + sample_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_97_1 == quantum_97_2);
  assert(sample_73_1 == sample_73_2);
}

int fn_R001195_9513_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quantum_97 = (aux + st.buffer[1]) & 3;
  switch (quantum_97)
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

  int sample_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_73 = ((sample_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_54_1) & 63;
  aux_2 = (aux_2 + anchor_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_65_1)
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

  switch (stride_65_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_54_1 == anchor_54_2);
  assert(stride_65_1 == stride_65_2);
}

int fn_R001195_9513_16(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_54) & 63;
  acc ^= aux;
  int stride_65 = (aux + st.buffer[1]) & 3;
  switch (stride_65)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001195_9513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_33_1 = local_arr_1[aux_1 % 3];
  int vector_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_33_2 * 2)) & 127;
  int tracker_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_45_1) & 63;
  aux_2 = (aux_2 + tracker_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_33_1 == vector_33_2);
  assert(tracker_45_1 == tracker_45_2);
}

int fn_R001195_9513_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int vector_33 = local_arr[aux % 3];
  acc = (acc + (vector_33 * 2)) & 127;
  int tracker_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001195_9513_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_84_1 = local_arr_1[aux_1 % 3];
  int mask_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_84_2 * 2)) & 127;
  int tally_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_84_1 > 44)
  {
    acc_1 = ((acc_1 + (tally_84_1 * 2)) + 5) & 127;
    aux_1 ^= tally_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_84_2 > 44)
  {
    acc_2 = ((acc_2 + (tally_84_2 * 2)) + 5) & 127;
    aux_2 ^= tally_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_84_1 == mask_84_2);
  assert(tally_84_1 == tally_84_2);
}

int fn_R001195_9513_18(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int mask_84 = local_arr[aux % 3];
  acc = (acc + (mask_84 * 2)) & 127;
  int tally_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_84 > 44)
  {
    acc = ((acc + (tally_84 * 2)) + 5) & 127;
    aux ^= tally_84 & 15;
  }
  else
  {
    acc = ((acc - tally_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001195_9513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_91_1)
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

  switch (stride_91_2)
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

  int phase_50_1 = 0;
  int phase_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_50_1 = ((phase_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_50_2 = ((phase_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_50_1) & 127;
    acc_2 = (acc_2 + phase_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_91_1 == stride_91_2);
  assert(phase_50_1 == phase_50_2);
}

int fn_R001195_9513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_91 = (aux + st.buffer[1]) & 3;
  switch (stride_91)
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

  int phase_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_50 = ((phase_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_24_1 = local_arr_1[aux_1 % 3];
  int damping_24_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_24_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_24_2 * 2)) & 127;
  int checksum_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_77_1 > 42)
  {
    acc_1 = ((acc_1 + (checksum_77_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_77_2 > 42)
  {
    acc_2 = ((acc_2 + (checksum_77_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_99_1) & 63;
  aux_2 = (aux_2 + tally_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_24_1 == damping_24_2);
  assert(checksum_77_1 == checksum_77_2);
  assert(tally_99_1 == tally_99_2);
}

int fn_R001195_9513_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int damping_24 = local_arr[aux % 3];
  acc = (acc + (damping_24 * 2)) & 127;
  int checksum_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_77 > 42)
  {
    acc = ((acc + (checksum_77 * 2)) + 5) & 127;
    aux ^= checksum_77 & 15;
  }
  else
  {
    acc = ((acc - checksum_77) + 11) & 127;
    aux += 3;
  }
  int tally_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001195_9513_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_35_1 = local_arr_1[aux_1 % 3];
  int weight_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_35_2 * 2)) & 127;
  int factor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_83_1 > 35)
  {
    acc_1 = ((acc_1 + (factor_83_1 * 2)) + 5) & 127;
    aux_1 ^= factor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_83_2 > 35)
  {
    acc_2 = ((acc_2 + (factor_83_2 * 2)) + 5) & 127;
    aux_2 ^= factor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_82_1 = 0;
  int metric_82_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_82_1 = ((metric_82_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_82_2 = ((metric_82_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_82_1) & 127;
    acc_2 = (acc_2 + metric_82_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_35_1 == weight_35_2);
  assert(factor_83_1 == factor_83_2);
  assert(metric_82_1 == metric_82_2);
}

int fn_R001195_9513_21(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001195_9513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int weight_35 = local_arr[aux % 3];
  acc = (acc + (weight_35 * 2)) & 127;
  int factor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_83 > 35)
  {
    acc = ((acc + (factor_83 * 2)) + 5) & 127;
    aux ^= factor_83 & 15;
  }
  else
  {
    acc = ((acc - factor_83) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_82 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_82 = ((metric_82 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_82) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001195_9513_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st_1 = {0};
  struct AudioFrame_R001195_9513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_31_1 > 16)
  {
    acc_1 = ((acc_1 + (offset_31_1 * 2)) + 5) & 127;
    aux_1 ^= offset_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_31_2 > 16)
  {
    acc_2 = ((acc_2 + (offset_31_2 * 2)) + 5) & 127;
    aux_2 ^= offset_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_57_1 = 0;
  int margin_57_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_57_1 = ((margin_57_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_57_2 = ((margin_57_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_57_1) & 127;
    acc_2 = (acc_2 + margin_57_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  assert(st_1.gain == st_2.gain);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_31_1 == offset_31_2);
  assert(margin_57_1 == margin_57_2);
}

int fn_R001195_9513_22(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001195_9513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_31 > 16)
  {
    acc = ((acc + (offset_31 * 2)) + 5) & 127;
    aux ^= offset_31 & 15;
  }
  else
  {
    acc = ((acc - offset_31) + 11) & 127;
    aux += 3;
  }
  int margin_57 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_57 = ((margin_57 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_57) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001195_0_1;
  int sec_r001195_0_2;
  int sec_r001195_1_1;
  int sec_r001195_1_2;
  int sec_r001195_2_1;
  int sec_r001195_2_2;
  int sec_r001195_3_1;
  int sec_r001195_3_2;
  int sec_r001195_4_1;
  int sec_r001195_4_2;
  int sec_r001195_5_1;
  int sec_r001195_5_2;
  int sec_r001195_6_1;
  int sec_r001195_6_2;
  int sec_r001195_7_1;
  int sec_r001195_7_2;
  int sec_r001195_8_1;
  int sec_r001195_8_2;
  int sec_r001195_9_1;
  int sec_r001195_9_2;
  int sec_r001195_10_1;
  int sec_r001195_10_2;
  int sec_r001195_11_1;
  int sec_r001195_11_2;
  int sec_r001195_12_1;
  int sec_r001195_12_2;
  int sec_r001195_13_1;
  int sec_r001195_13_2;
  int sec_r001195_14_1;
  int sec_r001195_14_2;
  int sec_r001195_15_1;
  int sec_r001195_15_2;
  int sec_r001195_16_1;
  int sec_r001195_16_2;
  int sec_r001195_17_1;
  int sec_r001195_17_2;
  int sec_r001195_18_1;
  int sec_r001195_18_2;
  int sec_r001195_19_1;
  int sec_r001195_19_2;
  int sec_r001195_20_1;
  int sec_r001195_20_2;
  int sec_r001195_21_1;
  int sec_r001195_21_2;
  int sec_r001195_22_1;
  int sec_r001195_22_2;
  int sec_r001195_23_1;
  int sec_r001195_23_2;
  int pub_r001195_0_1;
  int pub_r001195_0_2;
  int pub_r001195_1_1;
  int pub_r001195_1_2;
  int pub_r001195_2_1;
  int pub_r001195_2_2;
  int pub_r001195_3_1;
  int pub_r001195_3_2;
  int pub_r001195_4_1;
  int pub_r001195_4_2;
  int pub_r001195_5_1;
  int pub_r001195_5_2;
  int pub_r001195_6_1;
  int pub_r001195_6_2;
  int pub_r001195_7_1;
  int pub_r001195_7_2;
  int pub_r001195_8_1;
  int pub_r001195_8_2;
  int pub_r001195_9_1;
  int pub_r001195_9_2;
  int pub_r001195_10_1;
  int pub_r001195_10_2;
  int pub_r001195_11_1;
  int pub_r001195_11_2;
  int pub_r001195_12_1;
  int pub_r001195_12_2;
  int pub_r001195_13_1;
  int pub_r001195_13_2;
  int pub_r001195_14_1;
  int pub_r001195_14_2;
  int pub_r001195_15_1;
  int pub_r001195_15_2;
  int pub_r001195_16_1;
  int pub_r001195_16_2;
  int pub_r001195_17_1;
  int pub_r001195_17_2;
  int pub_r001195_18_1;
  int pub_r001195_18_2;
  int pub_r001195_19_1;
  int pub_r001195_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001195_0_1 >= (-100)) && (pub_r001195_0_1 <= 100));
  __CPROVER_assume((pub_r001195_0_2 >= (-100)) && (pub_r001195_0_2 <= 100));
  __CPROVER_assume((pub_r001195_1_1 >= (-100)) && (pub_r001195_1_1 <= 100));
  __CPROVER_assume((pub_r001195_1_2 >= (-100)) && (pub_r001195_1_2 <= 100));
  __CPROVER_assume((pub_r001195_2_1 >= (-100)) && (pub_r001195_2_1 <= 100));
  __CPROVER_assume((pub_r001195_2_2 >= (-100)) && (pub_r001195_2_2 <= 100));
  __CPROVER_assume((pub_r001195_3_1 >= (-100)) && (pub_r001195_3_1 <= 100));
  __CPROVER_assume((pub_r001195_3_2 >= (-100)) && (pub_r001195_3_2 <= 100));
  __CPROVER_assume((pub_r001195_4_1 >= (-100)) && (pub_r001195_4_1 <= 100));
  __CPROVER_assume((pub_r001195_4_2 >= (-100)) && (pub_r001195_4_2 <= 100));
  __CPROVER_assume((pub_r001195_5_1 >= (-100)) && (pub_r001195_5_1 <= 100));
  __CPROVER_assume((pub_r001195_5_2 >= (-100)) && (pub_r001195_5_2 <= 100));
  __CPROVER_assume((pub_r001195_6_1 >= (-100)) && (pub_r001195_6_1 <= 100));
  __CPROVER_assume((pub_r001195_6_2 >= (-100)) && (pub_r001195_6_2 <= 100));
  __CPROVER_assume((pub_r001195_7_1 >= (-100)) && (pub_r001195_7_1 <= 100));
  __CPROVER_assume((pub_r001195_7_2 >= (-100)) && (pub_r001195_7_2 <= 100));
  __CPROVER_assume((pub_r001195_8_1 >= (-100)) && (pub_r001195_8_1 <= 100));
  __CPROVER_assume((pub_r001195_8_2 >= (-100)) && (pub_r001195_8_2 <= 100));
  __CPROVER_assume((pub_r001195_9_1 >= (-100)) && (pub_r001195_9_1 <= 100));
  __CPROVER_assume((pub_r001195_9_2 >= (-100)) && (pub_r001195_9_2 <= 100));
  __CPROVER_assume((pub_r001195_10_1 >= (-100)) && (pub_r001195_10_1 <= 100));
  __CPROVER_assume((pub_r001195_10_2 >= (-100)) && (pub_r001195_10_2 <= 100));
  __CPROVER_assume((pub_r001195_11_1 >= (-100)) && (pub_r001195_11_1 <= 100));
  __CPROVER_assume((pub_r001195_11_2 >= (-100)) && (pub_r001195_11_2 <= 100));
  __CPROVER_assume((pub_r001195_12_1 >= (-100)) && (pub_r001195_12_1 <= 100));
  __CPROVER_assume((pub_r001195_12_2 >= (-100)) && (pub_r001195_12_2 <= 100));
  __CPROVER_assume((pub_r001195_13_1 >= (-100)) && (pub_r001195_13_1 <= 100));
  __CPROVER_assume((pub_r001195_13_2 >= (-100)) && (pub_r001195_13_2 <= 100));
  __CPROVER_assume((pub_r001195_14_1 >= (-100)) && (pub_r001195_14_1 <= 100));
  __CPROVER_assume((pub_r001195_14_2 >= (-100)) && (pub_r001195_14_2 <= 100));
  __CPROVER_assume((pub_r001195_15_1 >= (-100)) && (pub_r001195_15_1 <= 100));
  __CPROVER_assume((pub_r001195_15_2 >= (-100)) && (pub_r001195_15_2 <= 100));
  __CPROVER_assume((pub_r001195_16_1 >= (-100)) && (pub_r001195_16_1 <= 100));
  __CPROVER_assume((pub_r001195_16_2 >= (-100)) && (pub_r001195_16_2 <= 100));
  __CPROVER_assume((pub_r001195_17_1 >= (-100)) && (pub_r001195_17_1 <= 100));
  __CPROVER_assume((pub_r001195_17_2 >= (-100)) && (pub_r001195_17_2 <= 100));
  __CPROVER_assume((pub_r001195_18_1 >= (-100)) && (pub_r001195_18_1 <= 100));
  __CPROVER_assume((pub_r001195_18_2 >= (-100)) && (pub_r001195_18_2 <= 100));
  __CPROVER_assume((pub_r001195_19_1 >= (-100)) && (pub_r001195_19_1 <= 100));
  __CPROVER_assume((pub_r001195_19_2 >= (-100)) && (pub_r001195_19_2 <= 100));
  __CPROVER_assume((sec_r001195_0_1 >= 0) && (sec_r001195_0_1 <= 255));
  __CPROVER_assume((sec_r001195_0_2 >= 0) && (sec_r001195_0_2 <= 255));
  __CPROVER_assume((sec_r001195_1_1 >= 0) && (sec_r001195_1_1 <= 255));
  __CPROVER_assume((sec_r001195_1_2 >= 0) && (sec_r001195_1_2 <= 255));
  __CPROVER_assume((sec_r001195_2_1 >= 0) && (sec_r001195_2_1 <= 255));
  __CPROVER_assume((sec_r001195_2_2 >= 0) && (sec_r001195_2_2 <= 255));
  __CPROVER_assume((sec_r001195_3_1 >= 0) && (sec_r001195_3_1 <= 255));
  __CPROVER_assume((sec_r001195_3_2 >= 0) && (sec_r001195_3_2 <= 255));
  __CPROVER_assume((sec_r001195_4_1 >= 0) && (sec_r001195_4_1 <= 255));
  __CPROVER_assume((sec_r001195_4_2 >= 0) && (sec_r001195_4_2 <= 255));
  __CPROVER_assume((sec_r001195_5_1 >= 0) && (sec_r001195_5_1 <= 255));
  __CPROVER_assume((sec_r001195_5_2 >= 0) && (sec_r001195_5_2 <= 255));
  __CPROVER_assume((sec_r001195_6_1 >= 0) && (sec_r001195_6_1 <= 255));
  __CPROVER_assume((sec_r001195_6_2 >= 0) && (sec_r001195_6_2 <= 255));
  __CPROVER_assume((sec_r001195_7_1 >= 0) && (sec_r001195_7_1 <= 255));
  __CPROVER_assume((sec_r001195_7_2 >= 0) && (sec_r001195_7_2 <= 255));
  __CPROVER_assume((sec_r001195_8_1 >= 0) && (sec_r001195_8_1 <= 255));
  __CPROVER_assume((sec_r001195_8_2 >= 0) && (sec_r001195_8_2 <= 255));
  __CPROVER_assume((sec_r001195_9_1 >= 0) && (sec_r001195_9_1 <= 255));
  __CPROVER_assume((sec_r001195_9_2 >= 0) && (sec_r001195_9_2 <= 255));
  __CPROVER_assume((sec_r001195_10_1 >= 0) && (sec_r001195_10_1 <= 255));
  __CPROVER_assume((sec_r001195_10_2 >= 0) && (sec_r001195_10_2 <= 255));
  __CPROVER_assume((sec_r001195_11_1 >= 0) && (sec_r001195_11_1 <= 255));
  __CPROVER_assume((sec_r001195_11_2 >= 0) && (sec_r001195_11_2 <= 255));
  __CPROVER_assume((sec_r001195_12_1 >= 0) && (sec_r001195_12_1 <= 255));
  __CPROVER_assume((sec_r001195_12_2 >= 0) && (sec_r001195_12_2 <= 255));
  __CPROVER_assume((sec_r001195_13_1 >= 0) && (sec_r001195_13_1 <= 255));
  __CPROVER_assume((sec_r001195_13_2 >= 0) && (sec_r001195_13_2 <= 255));
  __CPROVER_assume((sec_r001195_14_1 >= 0) && (sec_r001195_14_1 <= 255));
  __CPROVER_assume((sec_r001195_14_2 >= 0) && (sec_r001195_14_2 <= 255));
  __CPROVER_assume((sec_r001195_15_1 >= 0) && (sec_r001195_15_1 <= 255));
  __CPROVER_assume((sec_r001195_15_2 >= 0) && (sec_r001195_15_2 <= 255));
  __CPROVER_assume((sec_r001195_16_1 >= 0) && (sec_r001195_16_1 <= 255));
  __CPROVER_assume((sec_r001195_16_2 >= 0) && (sec_r001195_16_2 <= 255));
  __CPROVER_assume((sec_r001195_17_1 >= 0) && (sec_r001195_17_1 <= 255));
  __CPROVER_assume((sec_r001195_17_2 >= 0) && (sec_r001195_17_2 <= 255));
  __CPROVER_assume((sec_r001195_18_1 >= 0) && (sec_r001195_18_1 <= 255));
  __CPROVER_assume((sec_r001195_18_2 >= 0) && (sec_r001195_18_2 <= 255));
  __CPROVER_assume((sec_r001195_19_1 >= 0) && (sec_r001195_19_1 <= 255));
  __CPROVER_assume((sec_r001195_19_2 >= 0) && (sec_r001195_19_2 <= 255));
  __CPROVER_assume((sec_r001195_20_1 >= 0) && (sec_r001195_20_1 <= 255));
  __CPROVER_assume((sec_r001195_20_2 >= 0) && (sec_r001195_20_2 <= 255));
  __CPROVER_assume((sec_r001195_21_1 >= 0) && (sec_r001195_21_1 <= 255));
  __CPROVER_assume((sec_r001195_21_2 >= 0) && (sec_r001195_21_2 <= 255));
  __CPROVER_assume((sec_r001195_22_1 >= 0) && (sec_r001195_22_1 <= 255));
  __CPROVER_assume((sec_r001195_22_2 >= 0) && (sec_r001195_22_2 <= 255));
  __CPROVER_assume((sec_r001195_23_1 >= 0) && (sec_r001195_23_1 <= 255));
  __CPROVER_assume((sec_r001195_23_2 >= 0) && (sec_r001195_23_2 <= 255));
  struct StreamBuffer_R001195_9513_0 st_var_0_1 = {0};
  struct StreamBuffer_R001195_9513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001195_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001195_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001195_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001195_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001195_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001195_0_2 + 7) & 15;
  struct AudioFrame_R001195_9513_1 st_var_1_1 = {0};
  struct AudioFrame_R001195_9513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001195_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001195_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001195_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001195_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001195_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001195_0_2 + 9) & 15;
  union TelemetryField_R001195_9513_0 u_var_1;
  union TelemetryField_R001195_9513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001195_9513_0(sec_r001195_0_1, sec_r001195_1_1, pub_r001195_2_1);
  int helper_flow_0_2 = fn_R001195_9513_0(sec_r001195_0_2, sec_r001195_1_2, pub_r001195_2_2);
  fn_R001195_9513_0_2(sec_r001195_0_1, sec_r001195_1_1, pub_r001195_2_1, sec_r001195_0_2, sec_r001195_1_2, pub_r001195_2_2);
  int helper_flow_1_1 = fn_R001195_9513_1(sec_r001195_1_1, pub_r001195_2_1, pub_r001195_3_1);
  int helper_flow_1_2 = fn_R001195_9513_1(sec_r001195_1_2, pub_r001195_2_2, pub_r001195_3_2);
  fn_R001195_9513_1_2(sec_r001195_1_1, pub_r001195_2_1, pub_r001195_3_1, sec_r001195_1_2, pub_r001195_2_2, pub_r001195_3_2);
  int helper_flow_2_1 = fn_R001195_9513_2(sec_r001195_2_1, sec_r001195_3_1, pub_r001195_4_1, pub_r001195_5_1, pub_r001195_6_1);
  int helper_flow_2_2 = fn_R001195_9513_2(sec_r001195_2_2, sec_r001195_3_2, pub_r001195_4_2, pub_r001195_5_2, pub_r001195_6_2);
  fn_R001195_9513_2_2(sec_r001195_2_1, sec_r001195_3_1, pub_r001195_4_1, pub_r001195_5_1, pub_r001195_6_1, sec_r001195_2_2, sec_r001195_3_2, pub_r001195_4_2, pub_r001195_5_2, pub_r001195_6_2);
  int helper_flow_3_1 = fn_R001195_9513_3(sec_r001195_3_1, pub_r001195_4_1, pub_r001195_5_1, pub_r001195_6_1);
  int helper_flow_3_2 = fn_R001195_9513_3(sec_r001195_3_2, pub_r001195_4_2, pub_r001195_5_2, pub_r001195_6_2);
  fn_R001195_9513_3_2(sec_r001195_3_1, pub_r001195_4_1, pub_r001195_5_1, pub_r001195_6_1, sec_r001195_3_2, pub_r001195_4_2, pub_r001195_5_2, pub_r001195_6_2);
  int helper_flow_4_1 = fn_R001195_9513_4(sec_r001195_4_1, sec_r001195_5_1, pub_r001195_6_1, pub_r001195_7_1, pub_r001195_8_1);
  int helper_flow_4_2 = fn_R001195_9513_4(sec_r001195_4_2, sec_r001195_5_2, pub_r001195_6_2, pub_r001195_7_2, pub_r001195_8_2);
  fn_R001195_9513_4_2(sec_r001195_4_1, sec_r001195_5_1, pub_r001195_6_1, pub_r001195_7_1, pub_r001195_8_1, sec_r001195_4_2, sec_r001195_5_2, pub_r001195_6_2, pub_r001195_7_2, pub_r001195_8_2);
  int helper_flow_5_1 = fn_R001195_9513_5(sec_r001195_5_1, pub_r001195_6_1, pub_r001195_7_1);
  int helper_flow_5_2 = fn_R001195_9513_5(sec_r001195_5_2, pub_r001195_6_2, pub_r001195_7_2);
  fn_R001195_9513_5_2(sec_r001195_5_1, pub_r001195_6_1, pub_r001195_7_1, sec_r001195_5_2, pub_r001195_6_2, pub_r001195_7_2);
  int helper_flow_6_1 = fn_R001195_9513_6(sec_r001195_6_1, sec_r001195_7_1, pub_r001195_8_1);
  int helper_flow_6_2 = fn_R001195_9513_6(sec_r001195_6_2, sec_r001195_7_2, pub_r001195_8_2);
  fn_R001195_9513_6_2(sec_r001195_6_1, sec_r001195_7_1, pub_r001195_8_1, sec_r001195_6_2, sec_r001195_7_2, pub_r001195_8_2);
  int helper_flow_7_1 = fn_R001195_9513_7(sec_r001195_7_1, sec_r001195_8_1);
  int helper_flow_7_2 = fn_R001195_9513_7(sec_r001195_7_2, sec_r001195_8_2);
  fn_R001195_9513_7_2(sec_r001195_7_1, sec_r001195_8_1, sec_r001195_7_2, sec_r001195_8_2);
  int helper_flow_8_1 = fn_R001195_9513_8(sec_r001195_8_1, pub_r001195_9_1, pub_r001195_10_1, pub_r001195_11_1);
  int helper_flow_8_2 = fn_R001195_9513_8(sec_r001195_8_2, pub_r001195_9_2, pub_r001195_10_2, pub_r001195_11_2);
  fn_R001195_9513_8_2(sec_r001195_8_1, pub_r001195_9_1, pub_r001195_10_1, pub_r001195_11_1, sec_r001195_8_2, pub_r001195_9_2, pub_r001195_10_2, pub_r001195_11_2);
  int stage_v_0_1 = ((sec_r001195_4_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_0_2 = ((sec_r001195_4_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_0_2 + 1) & 15;
  out_sink_1 ^= stage_v_0_1 & 63;
  out_sink_2 ^= stage_v_0_2 & 63;
  int stage_v_1_1 = ((helper_flow_6_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_1_2 = ((helper_flow_6_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_1_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_1_2 + 1) & 15;
  out_sink_1 ^= stage_v_1_1 & 63;
  out_sink_2 ^= stage_v_1_2 & 63;
  int stage_v_2_1 = ((sec_r001195_19_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001195_19_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((pub_r001195_4_1 * 2) + 21) & 63;
  int stage_v_3_2 = ((pub_r001195_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001195_6_1 * 2) + 21) & 63;
  int stage_v_4_2 = ((pub_r001195_6_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001195_5_1 * 2) + 44) & 63;
  int stage_v_5_2 = ((pub_r001195_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001195_0_1 * 2) + 44) & 63;
  int stage_v_6_2 = ((pub_r001195_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001195_8_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_7_2 = ((sec_r001195_8_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((stage_v_7_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_8_2 = ((stage_v_7_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((pub_r001195_19_1 * 2) + 28) & 63;
  int stage_v_9_2 = ((pub_r001195_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001195_7_1 * 2) + 39) & 63;
  int stage_v_10_2 = ((pub_r001195_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((sec_r001195_8_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001195_8_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((sec_r001195_6_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001195_6_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((sec_r001195_17_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_13_2 = ((sec_r001195_17_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((pub_r001195_11_1 * 2) + 40) & 63;
  int stage_v_14_2 = ((pub_r001195_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((stage_v_12_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_15_2 = ((stage_v_12_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_15_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_15_2 + 1) & 15;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = ((pub_r001195_9_1 * 2) + 17) & 63;
  int stage_v_16_2 = ((pub_r001195_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((stage_v_7_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_17_2 = ((stage_v_7_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((sec_r001195_14_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_18_2 = ((sec_r001195_14_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((pub_r001195_8_1 * 2) + 8) & 63;
  int stage_v_19_2 = ((pub_r001195_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((sec_r001195_14_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001195_14_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001195_9_1 * 2) + 20) & 63;
  int stage_v_21_2 = ((pub_r001195_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((sec_r001195_14_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_22_2 = ((sec_r001195_14_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_22_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_22_2 + 1) & 15;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = ((pub_r001195_4_1 * 2) + 41) & 63;
  int stage_v_23_2 = ((pub_r001195_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001195_22_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_24_2 = ((sec_r001195_22_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_24_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_24_2 + 1) & 15;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = ((pub_r001195_5_1 * 2) + 12) & 63;
  int stage_v_25_2 = ((pub_r001195_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((stage_v_20_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_26_2 = ((stage_v_20_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_26_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_26_2 + 1) & 15;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = ((pub_r001195_18_1 * 2) + 28) & 63;
  int stage_v_27_2 = ((pub_r001195_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((sec_r001195_11_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001195_11_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((stage_v_20_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_29_2 = ((stage_v_20_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001195_4_1 * 2) + 34) & 63;
  int stage_v_30_2 = ((pub_r001195_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001195_17_1 * 2) + 12) & 63;
  int stage_v_31_2 = ((pub_r001195_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001195_9_1 * 2) + 28) & 63;
  int stage_v_32_2 = ((pub_r001195_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001195_0_1 * 2) + 10) & 63;
  int stage_v_33_2 = ((pub_r001195_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((sec_r001195_16_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001195_16_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((pub_r001195_5_1 * 2) + 30) & 63;
  int stage_v_35_2 = ((pub_r001195_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001195_17_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001195_17_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((stage_v_15_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_37_2 = ((stage_v_15_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((sec_r001195_22_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_38_2 = ((sec_r001195_22_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((sec_r001195_23_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_39_2 = ((sec_r001195_23_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_39_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_39_2 + 1) & 15;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = ((sec_r001195_8_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_40_2 = ((sec_r001195_8_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((helper_flow_5_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_41_2 = ((helper_flow_5_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((sec_r001195_9_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_42_2 = ((sec_r001195_9_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_42_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_42_2 + 1) & 15;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = ((stage_v_13_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_13_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((pub_r001195_9_1 * 2) + 34) & 63;
  int stage_v_44_2 = ((pub_r001195_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001195_16_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_45_2 = ((sec_r001195_16_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((stage_v_7_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_46_2 = ((stage_v_7_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((pub_r001195_3_1 * 2) + 11) & 63;
  int stage_v_47_2 = ((pub_r001195_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((sec_r001195_23_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_48_2 = ((sec_r001195_23_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((pub_r001195_3_1 * 2) + 21) & 63;
  int stage_v_49_2 = ((pub_r001195_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((sec_r001195_6_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_50_2 = ((sec_r001195_6_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((helper_flow_4_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_51_2 = ((helper_flow_4_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_51_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_51_2 + 1) & 15;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = ((stage_v_50_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_52_2 = ((stage_v_50_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((sec_r001195_22_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001195_22_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((stage_v_43_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_43_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001195_10_1 * 2) + 37) & 63;
  int stage_v_55_2 = ((pub_r001195_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((helper_flow_2_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_56_2 = ((helper_flow_2_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((pub_r001195_3_1 * 2) + 6) & 63;
  int stage_v_57_2 = ((pub_r001195_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((helper_flow_3_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_58_2 = ((helper_flow_3_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((sec_r001195_15_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_59_2 = ((sec_r001195_15_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((sec_r001195_21_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_60_2 = ((sec_r001195_21_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((pub_r001195_18_1 * 2) + 30) & 63;
  int stage_v_61_2 = ((pub_r001195_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001195_9_1 * 2) + 26) & 63;
  int stage_v_62_2 = ((pub_r001195_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001195_10_1 * 2) + 35) & 63;
  int stage_v_63_2 = ((pub_r001195_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((sec_r001195_3_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_64_2 = ((sec_r001195_3_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((pub_r001195_16_1 * 2) + 10) & 63;
  int stage_v_65_2 = ((pub_r001195_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((sec_r001195_16_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_66_2 = ((sec_r001195_16_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((pub_r001195_17_1 * 2) + 36) & 63;
  int stage_v_67_2 = ((pub_r001195_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((helper_flow_6_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_68_2 = ((helper_flow_6_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((sec_r001195_0_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_69_2 = ((sec_r001195_0_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_69_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_69_2 + 1) & 15;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = ((sec_r001195_14_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_70_2 = ((sec_r001195_14_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001195_17_1 * 2) + 28) & 63;
  int stage_v_71_2 = ((pub_r001195_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001195_4_1 * 2) + 46) & 63;
  int stage_v_72_2 = ((pub_r001195_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001195_8_1 * 2) + 29) & 63;
  int stage_v_73_2 = ((pub_r001195_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001195_11_1 * 2) + 26) & 63;
  int stage_v_74_2 = ((pub_r001195_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001195_19_1 * 2) + 28) & 63;
  int stage_v_75_2 = ((pub_r001195_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_66_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_76_2 = ((stage_v_66_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((helper_flow_7_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_77_2 = ((helper_flow_7_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001195_7_1 * 2) + 25) & 63;
  int stage_v_78_2 = ((pub_r001195_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001195_10_1 * 2) + 17) & 63;
  int stage_v_79_2 = ((pub_r001195_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_41_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_41_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((sec_r001195_1_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_81_2 = ((sec_r001195_1_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((sec_r001195_9_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_82_2 = ((sec_r001195_9_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((pub_r001195_17_1 * 2) + 28) & 63;
  int stage_v_83_2 = ((pub_r001195_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((pub_r001195_12_1 * 2) + 28) & 63;
  int stage_v_84_2 = ((pub_r001195_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001195_7_1 * 2) + 11) & 63;
  int stage_v_85_2 = ((pub_r001195_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((sec_r001195_20_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_86_2 = ((sec_r001195_20_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001195_4_1 * 2) + 16) & 63;
  int stage_v_87_2 = ((pub_r001195_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((stage_v_7_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_88_2 = ((stage_v_7_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((pub_r001195_11_1 * 2) + 7) & 63;
  int stage_v_89_2 = ((pub_r001195_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((stage_v_11_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_90_2 = ((stage_v_11_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_90_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_90_2 + 1) & 15;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = ((helper_flow_5_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_91_2 = ((helper_flow_5_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((pub_r001195_15_1 * 2) + 47) & 63;
  int stage_v_92_2 = ((pub_r001195_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001195_8_1 * 2) + 33) & 63;
  int stage_v_93_2 = ((pub_r001195_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_13_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_13_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((helper_flow_6_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_95_2 = ((helper_flow_6_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_95_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_95_2 + 1) & 15;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = ((stage_v_76_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_96_2 = ((stage_v_76_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_96_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_96_2 + 1) & 15;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = ((pub_r001195_13_1 * 2) + 12) & 63;
  int stage_v_97_2 = ((pub_r001195_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((helper_flow_7_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_98_2 = ((helper_flow_7_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((stage_v_82_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_82_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((stage_v_7_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_7_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((sec_r001195_9_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_101_2 = ((sec_r001195_9_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((helper_flow_4_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_102_2 = ((helper_flow_4_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_102_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_102_2 + 1) & 15;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = ((pub_r001195_4_1 * 2) + 20) & 63;
  int stage_v_103_2 = ((pub_r001195_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((sec_r001195_1_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_104_2 = ((sec_r001195_1_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((pub_r001195_9_1 * 2) + 28) & 63;
  int stage_v_105_2 = ((pub_r001195_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001195_19_1 * 2) + 48) & 63;
  int stage_v_106_2 = ((pub_r001195_19_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_52_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_52_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((helper_flow_2_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_108_2 = ((helper_flow_2_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((pub_r001195_1_1 * 2) + 22) & 63;
  int stage_v_109_2 = ((pub_r001195_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001195_16_1 * 2) + 45) & 63;
  int stage_v_110_2 = ((pub_r001195_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_81_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_111_2 = ((stage_v_81_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((pub_r001195_2_1 * 2) + 9) & 63;
  int stage_v_112_2 = ((pub_r001195_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001195_19_1 * 2) + 28) & 63;
  int stage_v_113_2 = ((pub_r001195_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001195_15_1 * 2) + 25) & 63;
  int stage_v_114_2 = ((pub_r001195_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_50_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_115_2 = ((stage_v_50_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_115_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_115_2 + 1) & 15;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = ((pub_r001195_10_1 * 2) + 43) & 63;
  int stage_v_116_2 = ((pub_r001195_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001195_9_1 * 2) + 39) & 63;
  int stage_v_117_2 = ((pub_r001195_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001195_0_1 * 2) + 18) & 63;
  int stage_v_118_2 = ((pub_r001195_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001195_17_1 * 2) + 12) & 63;
  int stage_v_119_2 = ((pub_r001195_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_50_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_50_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((stage_v_17_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_121_2 = ((stage_v_17_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((pub_r001195_19_1 * 2) + 5) & 63;
  int stage_v_122_2 = ((pub_r001195_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001195_15_1 * 2) + 21) & 63;
  int stage_v_123_2 = ((pub_r001195_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001195_1_1 * 2) + 37) & 63;
  int stage_v_124_2 = ((pub_r001195_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_121_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_121_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_28_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_28_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((helper_flow_6_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_127_2 = ((helper_flow_6_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((pub_r001195_12_1 * 2) + 21) & 63;
  int stage_v_128_2 = ((pub_r001195_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((sec_r001195_2_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_129_2 = ((sec_r001195_2_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((pub_r001195_3_1 * 2) + 33) & 63;
  int stage_v_130_2 = ((pub_r001195_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001195_0_1 * 2) + 40) & 63;
  int stage_v_131_2 = ((pub_r001195_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((sec_r001195_9_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_132_2 = ((sec_r001195_9_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_132_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_132_2 + 1) & 15;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = ((sec_r001195_21_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_133_2 = ((sec_r001195_21_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((pub_r001195_11_1 * 2) + 29) & 63;
  int stage_v_134_2 = ((pub_r001195_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001195_17_1 * 2) + 29) & 63;
  int stage_v_135_2 = ((pub_r001195_17_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_111_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_111_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((stage_v_108_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_108_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((pub_r001195_2_1 * 2) + 22) & 63;
  int stage_v_138_2 = ((pub_r001195_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((sec_r001195_10_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_139_2 = ((sec_r001195_10_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((pub_r001195_14_1 * 2) + 33) & 63;
  int stage_v_140_2 = ((pub_r001195_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_50_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_50_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((stage_v_88_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_142_2 = ((stage_v_88_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_142_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_142_2 + 1) & 15;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = ((sec_r001195_6_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_143_2 = ((sec_r001195_6_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((pub_r001195_3_1 * 2) + 34) & 63;
  int stage_v_144_2 = ((pub_r001195_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_141_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_141_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((sec_r001195_1_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_146_2 = ((sec_r001195_1_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((pub_r001195_17_1 * 2) + 23) & 63;
  int stage_v_147_2 = ((pub_r001195_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((helper_flow_1_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_148_2 = ((helper_flow_1_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((pub_r001195_12_1 * 2) + 35) & 63;
  int stage_v_149_2 = ((pub_r001195_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001195_15_1 * 2) + 48) & 63;
  int stage_v_150_2 = ((pub_r001195_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((sec_r001195_18_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_151_2 = ((sec_r001195_18_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((sec_r001195_0_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_152_2 = ((sec_r001195_0_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001195_6_1 * 2) + 20) & 63;
  int stage_v_153_2 = ((pub_r001195_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001195_0_1 * 2) + 41) & 63;
  int stage_v_154_2 = ((pub_r001195_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((stage_v_51_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_51_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001195_9_1 * 2) + 19) & 63;
  int stage_v_156_2 = ((pub_r001195_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001195_6_1 * 2) + 22) & 63;
  int stage_v_157_2 = ((pub_r001195_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001195_19_1 * 2) + 36) & 63;
  int stage_v_158_2 = ((pub_r001195_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001195_2_1 * 2) + 30) & 63;
  int stage_v_159_2 = ((pub_r001195_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001195_0_1 * 2) + 6) & 63;
  int stage_v_160_2 = ((pub_r001195_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001195_5_1 * 2) + 19) & 63;
  int stage_v_161_2 = ((pub_r001195_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001195_6_1 * 2) + 39) & 63;
  int stage_v_162_2 = ((pub_r001195_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((sec_r001195_23_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_163_2 = ((sec_r001195_23_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((stage_v_139_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_139_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001195_2_1 * 2) + 21) & 63;
  int stage_v_165_2 = ((pub_r001195_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001195_1_1 * 2) + 24) & 63;
  int stage_v_166_2 = ((pub_r001195_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001195_9_1 * 2) + 45) & 63;
  int stage_v_167_2 = ((pub_r001195_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_42_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_42_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((helper_flow_1_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_169_2 = ((helper_flow_1_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_80_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_80_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((stage_v_129_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_171_2 = ((stage_v_129_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_171_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_171_2 + 1) & 15;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = ((pub_r001195_0_1 * 2) + 9) & 63;
  int stage_v_172_2 = ((pub_r001195_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001195_9_1 * 2) + 49) & 63;
  int stage_v_173_2 = ((pub_r001195_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_51_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_51_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((pub_r001195_4_1 * 2) + 50) & 63;
  int stage_v_175_2 = ((pub_r001195_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001195_4_1 * 2) + 37) & 63;
  int stage_v_176_2 = ((pub_r001195_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_64_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_177_2 = ((stage_v_64_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_177_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_177_2 + 1) & 15;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = ((stage_v_86_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_178_2 = ((stage_v_86_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_178_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_178_2 + 1) & 15;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = ((sec_r001195_5_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_179_2 = ((sec_r001195_5_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((helper_flow_8_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_180_2 = ((helper_flow_8_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001195_15_1 * 2) + 5) & 63;
  int stage_v_181_2 = ((pub_r001195_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001195_5_1 * 2) + 50) & 63;
  int stage_v_182_2 = ((pub_r001195_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_101_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_183_2 = ((stage_v_101_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((pub_r001195_6_1 * 2) + 33) & 63;
  int stage_v_184_2 = ((pub_r001195_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((stage_v_58_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_58_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001195_18_1 * 2) + 33) & 63;
  int stage_v_186_2 = ((pub_r001195_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((helper_flow_8_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_187_2 = ((helper_flow_8_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_40_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_40_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001195_19_1 * 2) + 29) & 63;
  int stage_v_189_2 = ((pub_r001195_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001195_16_1 * 2) + 34) & 63;
  int stage_v_190_2 = ((pub_r001195_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((stage_v_168_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_191_2 = ((stage_v_168_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((sec_r001195_4_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_192_2 = ((sec_r001195_4_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((stage_v_146_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_146_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001195_13_1 * 2) + 38) & 63;
  int stage_v_194_2 = ((pub_r001195_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_46_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_195_2 = ((stage_v_46_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_195_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_195_2 + 1) & 15;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = ((pub_r001195_1_1 * 2) + 19) & 63;
  int stage_v_196_2 = ((pub_r001195_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_143_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_143_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001195_2_1 * 2) + 28) & 63;
  int stage_v_198_2 = ((pub_r001195_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((sec_r001195_9_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_199_2 = ((sec_r001195_9_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((sec_r001195_22_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_200_2 = ((sec_r001195_22_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_200_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_200_2 + 1) & 15;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = ((stage_v_169_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_169_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_155_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_155_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001195_10_1 * 2) + 41) & 63;
  int stage_v_203_2 = ((pub_r001195_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_82_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_82_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((stage_v_60_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_205_2 = ((stage_v_60_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((stage_v_132_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_206_2 = ((stage_v_132_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_206_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_206_2 + 1) & 15;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = ((pub_r001195_11_1 * 2) + 15) & 63;
  int stage_v_207_2 = ((pub_r001195_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((sec_r001195_7_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_208_2 = ((sec_r001195_7_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((pub_r001195_3_1 * 2) + 43) & 63;
  int stage_v_209_2 = ((pub_r001195_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_168_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_168_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((stage_v_98_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_98_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((stage_v_54_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_54_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((stage_v_2_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_213_2 = ((stage_v_2_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001195_13_1 * 2) + 50) & 63;
  int stage_v_214_2 = ((pub_r001195_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001195_1_1 * 2) + 20) & 63;
  int stage_v_215_2 = ((pub_r001195_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((stage_v_129_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_129_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((stage_v_213_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_217_2 = ((stage_v_213_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_217_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_217_2 + 1) & 15;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = ((stage_v_77_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_218_2 = ((stage_v_77_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_218_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_218_2 + 1) & 15;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = ((pub_r001195_16_1 * 2) + 45) & 63;
  int stage_v_219_2 = ((pub_r001195_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((stage_v_217_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_220_2 = ((stage_v_217_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((stage_v_95_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_221_2 = ((stage_v_95_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((pub_r001195_9_1 * 2) + 19) & 63;
  int stage_v_222_2 = ((pub_r001195_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001195_18_1 * 2) + 48) & 63;
  int stage_v_223_2 = ((pub_r001195_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001195_10_1 * 2) + 27) & 63;
  int stage_v_224_2 = ((pub_r001195_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((sec_r001195_2_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_225_2 = ((sec_r001195_2_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001195_9_1 * 2) + 18) & 63;
  int stage_v_226_2 = ((pub_r001195_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((sec_r001195_16_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_227_2 = ((sec_r001195_16_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((pub_r001195_13_1 * 2) + 39) & 63;
  int stage_v_228_2 = ((pub_r001195_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((stage_v_188_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_229_2 = ((stage_v_188_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_229_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_229_2 + 1) & 15;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = ((pub_r001195_17_1 * 2) + 9) & 63;
  int stage_v_230_2 = ((pub_r001195_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001195_18_1 * 2) + 6) & 63;
  int stage_v_231_2 = ((pub_r001195_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_183_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_183_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((stage_v_206_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_233_2 = ((stage_v_206_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_233_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_233_2 + 1) & 15;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = ((stage_v_104_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_234_2 = ((stage_v_104_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_52_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_52_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((pub_r001195_7_1 * 2) + 26) & 63;
  int stage_v_236_2 = ((pub_r001195_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001195_15_1 * 2) + 6) & 63;
  int stage_v_237_2 = ((pub_r001195_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((stage_v_38_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_238_2 = ((stage_v_38_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((stage_v_38_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_38_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((stage_v_59_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_240_2 = ((stage_v_59_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_240_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_240_2 + 1) & 15;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = ((stage_v_18_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_18_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001195_12_1 * 2) + 7) & 63;
  int stage_v_242_2 = ((pub_r001195_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_20_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_20_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_136_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_136_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001195_3_1 * 2) + 15) & 63;
  int stage_v_245_2 = ((pub_r001195_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001195_6_1 * 2) + 42) & 63;
  int stage_v_246_2 = ((pub_r001195_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((sec_r001195_11_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_247_2 = ((sec_r001195_11_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((stage_v_155_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_248_2 = ((stage_v_155_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_248_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_248_2 + 1) & 15;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = ((stage_v_54_1 << 1) ^ (pub_r001195_18_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_54_2 << 1) ^ (pub_r001195_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((stage_v_197_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_250_2 = ((stage_v_197_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((stage_v_227_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_251_2 = ((stage_v_227_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_251_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_251_2 + 1) & 15;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = ((pub_r001195_11_1 * 2) + 42) & 63;
  int stage_v_252_2 = ((pub_r001195_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((stage_v_26_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_26_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((stage_v_163_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_163_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((stage_v_125_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_125_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((stage_v_17_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_17_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001195_3_1 * 2) + 38) & 63;
  int stage_v_257_2 = ((pub_r001195_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((stage_v_127_1 << 1) ^ (pub_r001195_4_1 >> 1)) & 127;
  int stage_v_258_2 = ((stage_v_127_2 << 1) ^ (pub_r001195_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_258_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_258_2 + 1) & 15;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = ((sec_r001195_14_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_259_2 = ((sec_r001195_14_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((stage_v_115_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_260_2 = ((stage_v_115_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_260_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_260_2 + 1) & 15;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  int stage_v_261_1 = ((stage_v_185_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_261_2 = ((stage_v_185_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_261_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_261_2 + 1) & 15;
  out_sink_1 ^= stage_v_261_1 & 63;
  out_sink_2 ^= stage_v_261_2 & 63;
  int stage_v_262_1 = ((pub_r001195_10_1 * 2) + 10) & 63;
  int stage_v_262_2 = ((pub_r001195_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001195_11_1 * 2) + 44) & 63;
  int stage_v_263_2 = ((pub_r001195_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((stage_v_200_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_264_2 = ((stage_v_200_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_46_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_46_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001195_2_1 * 2) + 40) & 63;
  int stage_v_266_2 = ((pub_r001195_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001195_15_1 * 2) + 31) & 63;
  int stage_v_267_2 = ((pub_r001195_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001195_15_1 * 2) + 16) & 63;
  int stage_v_268_2 = ((pub_r001195_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001195_11_1 * 2) + 7) & 63;
  int stage_v_269_2 = ((pub_r001195_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001195_16_1 * 2) + 40) & 63;
  int stage_v_270_2 = ((pub_r001195_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((stage_v_188_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_271_2 = ((stage_v_188_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((pub_r001195_9_1 * 2) + 9) & 63;
  int stage_v_272_2 = ((pub_r001195_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001195_15_1 * 2) + 22) & 63;
  int stage_v_273_2 = ((pub_r001195_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001195_19_1 * 2) + 46) & 63;
  int stage_v_274_2 = ((pub_r001195_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((stage_v_15_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_275_2 = ((stage_v_15_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((pub_r001195_6_1 * 2) + 19) & 63;
  int stage_v_276_2 = ((pub_r001195_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001195_18_1 * 2) + 41) & 63;
  int stage_v_277_2 = ((pub_r001195_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001195_13_1 * 2) + 12) & 63;
  int stage_v_278_2 = ((pub_r001195_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001195_7_1 * 2) + 19) & 63;
  int stage_v_279_2 = ((pub_r001195_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((stage_v_52_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_52_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001195_2_1 * 2) + 12) & 63;
  int stage_v_281_2 = ((pub_r001195_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_217_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_217_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_69_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_69_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((pub_r001195_9_1 * 2) + 13) & 63;
  int stage_v_284_2 = ((pub_r001195_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((stage_v_248_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_285_2 = ((stage_v_248_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_285_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_285_2 + 1) & 15;
  out_sink_1 ^= stage_v_285_1 & 63;
  out_sink_2 ^= stage_v_285_2 & 63;
  int stage_v_286_1 = ((pub_r001195_4_1 * 2) + 15) & 63;
  int stage_v_286_2 = ((pub_r001195_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((sec_r001195_11_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_287_2 = ((sec_r001195_11_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_287_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_287_2 + 1) & 15;
  out_sink_1 ^= stage_v_287_1 & 63;
  out_sink_2 ^= stage_v_287_2 & 63;
  int stage_v_288_1 = ((pub_r001195_14_1 * 2) + 28) & 63;
  int stage_v_288_2 = ((pub_r001195_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_249_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_249_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((pub_r001195_0_1 * 2) + 34) & 63;
  int stage_v_290_2 = ((pub_r001195_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001195_17_1 * 2) + 25) & 63;
  int stage_v_291_2 = ((pub_r001195_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((stage_v_36_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_36_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((stage_v_199_1 << 1) ^ (pub_r001195_0_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_199_2 << 1) ^ (pub_r001195_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((stage_v_13_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_13_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((stage_v_240_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_295_2 = ((stage_v_240_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((pub_r001195_14_1 * 2) + 6) & 63;
  int stage_v_296_2 = ((pub_r001195_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001195_15_1 * 2) + 21) & 63;
  int stage_v_297_2 = ((pub_r001195_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001195_0_1 * 2) + 25) & 63;
  int stage_v_298_2 = ((pub_r001195_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((stage_v_240_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_240_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_52_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_52_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((sec_r001195_16_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_301_2 = ((sec_r001195_16_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_301_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_301_2 + 1) & 15;
  out_sink_1 ^= stage_v_301_1 & 63;
  out_sink_2 ^= stage_v_301_2 & 63;
  int stage_v_302_1 = ((sec_r001195_21_1 << 1) ^ (pub_r001195_1_1 >> 1)) & 127;
  int stage_v_302_2 = ((sec_r001195_21_2 << 1) ^ (pub_r001195_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_302_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_302_2 + 1) & 15;
  out_sink_1 ^= stage_v_302_1 & 63;
  out_sink_2 ^= stage_v_302_2 & 63;
  int stage_v_303_1 = ((stage_v_233_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_303_2 = ((stage_v_233_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_303_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_303_2 + 1) & 15;
  out_sink_1 ^= stage_v_303_1 & 63;
  out_sink_2 ^= stage_v_303_2 & 63;
  int stage_v_304_1 = ((pub_r001195_16_1 * 2) + 32) & 63;
  int stage_v_304_2 = ((pub_r001195_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001195_11_1 * 2) + 31) & 63;
  int stage_v_305_2 = ((pub_r001195_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_275_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_275_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((pub_r001195_13_1 * 2) + 33) & 63;
  int stage_v_307_2 = ((pub_r001195_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_54_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_54_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001195_3_1 * 2) + 38) & 63;
  int stage_v_309_2 = ((pub_r001195_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001195_6_1 * 2) + 42) & 63;
  int stage_v_310_2 = ((pub_r001195_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((stage_v_302_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_302_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((pub_r001195_19_1 * 2) + 42) & 63;
  int stage_v_312_2 = ((pub_r001195_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((stage_v_170_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_170_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001195_10_1 * 2) + 20) & 63;
  int stage_v_314_2 = ((pub_r001195_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001195_6_1 * 2) + 32) & 63;
  int stage_v_315_2 = ((pub_r001195_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001195_7_1 * 2) + 34) & 63;
  int stage_v_316_2 = ((pub_r001195_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((stage_v_40_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_317_2 = ((stage_v_40_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_317_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_317_2 + 1) & 15;
  out_sink_1 ^= stage_v_317_1 & 63;
  out_sink_2 ^= stage_v_317_2 & 63;
  int stage_v_318_1 = ((pub_r001195_16_1 * 2) + 33) & 63;
  int stage_v_318_2 = ((pub_r001195_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001195_11_1 * 2) + 18) & 63;
  int stage_v_319_2 = ((pub_r001195_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001195_17_1 * 2) + 45) & 63;
  int stage_v_320_2 = ((pub_r001195_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001195_8_1 * 2) + 8) & 63;
  int stage_v_321_2 = ((pub_r001195_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((stage_v_248_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_248_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((pub_r001195_3_1 * 2) + 49) & 63;
  int stage_v_323_2 = ((pub_r001195_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001195_2_1 * 2) + 31) & 63;
  int stage_v_324_2 = ((pub_r001195_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001195_19_1 * 2) + 8) & 63;
  int stage_v_325_2 = ((pub_r001195_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((stage_v_139_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_139_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((pub_r001195_10_1 * 2) + 36) & 63;
  int stage_v_327_2 = ((pub_r001195_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001195_2_1 * 2) + 46) & 63;
  int stage_v_328_2 = ((pub_r001195_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((stage_v_197_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_197_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((stage_v_177_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_177_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001195_17_1 * 2) + 48) & 63;
  int stage_v_331_2 = ((pub_r001195_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((stage_v_329_1 << 1) ^ (pub_r001195_13_1 >> 1)) & 127;
  int stage_v_332_2 = ((stage_v_329_2 << 1) ^ (pub_r001195_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_332_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_332_2 + 1) & 15;
  out_sink_1 ^= stage_v_332_1 & 63;
  out_sink_2 ^= stage_v_332_2 & 63;
  int stage_v_333_1 = ((pub_r001195_7_1 * 2) + 20) & 63;
  int stage_v_333_2 = ((pub_r001195_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001195_19_1 * 2) + 11) & 63;
  int stage_v_334_2 = ((pub_r001195_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((stage_v_68_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_68_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((stage_v_56_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_56_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001195_2_1 * 2) + 35) & 63;
  int stage_v_337_2 = ((pub_r001195_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((stage_v_306_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_338_2 = ((stage_v_306_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001195_15_1 * 2) + 6) & 63;
  int stage_v_339_2 = ((pub_r001195_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001195_2_1 * 2) + 37) & 63;
  int stage_v_340_2 = ((pub_r001195_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((stage_v_259_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_259_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((pub_r001195_2_1 * 2) + 39) & 63;
  int stage_v_342_2 = ((pub_r001195_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((stage_v_15_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_343_2 = ((stage_v_15_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_343_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_343_2 + 1) & 15;
  out_sink_1 ^= stage_v_343_1 & 63;
  out_sink_2 ^= stage_v_343_2 & 63;
  int stage_v_344_1 = ((stage_v_249_1 << 1) ^ (pub_r001195_10_1 >> 1)) & 127;
  int stage_v_344_2 = ((stage_v_249_2 << 1) ^ (pub_r001195_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_344_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_344_2 + 1) & 15;
  out_sink_1 ^= stage_v_344_1 & 63;
  out_sink_2 ^= stage_v_344_2 & 63;
  int stage_v_345_1 = ((pub_r001195_5_1 * 2) + 23) & 63;
  int stage_v_345_2 = ((pub_r001195_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001195_10_1 * 2) + 30) & 63;
  int stage_v_346_2 = ((pub_r001195_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((sec_r001195_13_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_347_2 = ((sec_r001195_13_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((pub_r001195_1_1 * 2) + 26) & 63;
  int stage_v_348_2 = ((pub_r001195_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001195_5_1 * 2) + 38) & 63;
  int stage_v_349_2 = ((pub_r001195_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((stage_v_17_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_17_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((sec_r001195_21_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_351_2 = ((sec_r001195_21_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((pub_r001195_16_1 * 2) + 36) & 63;
  int stage_v_352_2 = ((pub_r001195_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001195_0_1 * 2) + 22) & 63;
  int stage_v_353_2 = ((pub_r001195_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001195_13_1 * 2) + 26) & 63;
  int stage_v_354_2 = ((pub_r001195_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001195_4_1 * 2) + 24) & 63;
  int stage_v_355_2 = ((pub_r001195_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001195_5_1 * 2) + 20) & 63;
  int stage_v_356_2 = ((pub_r001195_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((stage_v_1_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_357_2 = ((stage_v_1_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_357_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_357_2 + 1) & 15;
  out_sink_1 ^= stage_v_357_1 & 63;
  out_sink_2 ^= stage_v_357_2 & 63;
  int stage_v_358_1 = ((stage_v_28_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_358_2 = ((stage_v_28_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_358_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_358_2 + 1) & 15;
  out_sink_1 ^= stage_v_358_1 & 63;
  out_sink_2 ^= stage_v_358_2 & 63;
  int stage_v_359_1 = ((helper_flow_6_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_359_2 = ((helper_flow_6_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((pub_r001195_8_1 * 2) + 11) & 63;
  int stage_v_360_2 = ((pub_r001195_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001195_14_1 * 2) + 39) & 63;
  int stage_v_361_2 = ((pub_r001195_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((stage_v_38_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_362_2 = ((stage_v_38_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_362_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_362_2 + 1) & 15;
  out_sink_1 ^= stage_v_362_1 & 63;
  out_sink_2 ^= stage_v_362_2 & 63;
  int stage_v_363_1 = ((stage_v_80_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_80_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((pub_r001195_2_1 * 2) + 7) & 63;
  int stage_v_364_2 = ((pub_r001195_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001195_6_1 * 2) + 26) & 63;
  int stage_v_365_2 = ((pub_r001195_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((stage_v_255_1 << 1) ^ (pub_r001195_12_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_255_2 << 1) ^ (pub_r001195_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((stage_v_259_1 << 1) ^ (pub_r001195_11_1 >> 1)) & 127;
  int stage_v_367_2 = ((stage_v_259_2 << 1) ^ (pub_r001195_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_367_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_367_2 + 1) & 15;
  out_sink_1 ^= stage_v_367_1 & 63;
  out_sink_2 ^= stage_v_367_2 & 63;
  int stage_v_368_1 = ((pub_r001195_11_1 * 2) + 47) & 63;
  int stage_v_368_2 = ((pub_r001195_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001195_7_1 * 2) + 24) & 63;
  int stage_v_369_2 = ((pub_r001195_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_96_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_96_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001195_2_1 * 2) + 36) & 63;
  int stage_v_371_2 = ((pub_r001195_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001195_12_1 * 2) + 23) & 63;
  int stage_v_372_2 = ((pub_r001195_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((stage_v_282_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_373_2 = ((stage_v_282_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_373_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_373_2 + 1) & 15;
  out_sink_1 ^= stage_v_373_1 & 63;
  out_sink_2 ^= stage_v_373_2 & 63;
  int stage_v_374_1 = ((helper_flow_3_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_374_2 = ((helper_flow_3_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001195_9_1 * 2) + 34) & 63;
  int stage_v_375_2 = ((pub_r001195_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001195_15_1 * 2) + 23) & 63;
  int stage_v_376_2 = ((pub_r001195_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_174_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_174_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((stage_v_91_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_91_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_378_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_378_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((pub_r001195_16_1 * 2) + 27) & 63;
  int stage_v_380_2 = ((pub_r001195_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001195_4_1 * 2) + 14) & 63;
  int stage_v_381_2 = ((pub_r001195_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001195_2_1 * 2) + 9) & 63;
  int stage_v_382_2 = ((pub_r001195_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((stage_v_350_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_350_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((stage_v_299_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_299_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((stage_v_192_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_385_2 = ((stage_v_192_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_385_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_385_2 + 1) & 15;
  out_sink_1 ^= stage_v_385_1 & 63;
  out_sink_2 ^= stage_v_385_2 & 63;
  int stage_v_386_1 = ((stage_v_385_1 << 1) ^ (pub_r001195_9_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_385_2 << 1) ^ (pub_r001195_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((pub_r001195_6_1 * 2) + 27) & 63;
  int stage_v_387_2 = ((pub_r001195_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001195_7_1 * 2) + 23) & 63;
  int stage_v_388_2 = ((pub_r001195_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001195_12_1 * 2) + 11) & 63;
  int stage_v_389_2 = ((pub_r001195_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001195_4_1 * 2) + 12) & 63;
  int stage_v_390_2 = ((pub_r001195_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001195_9_1 * 2) + 36) & 63;
  int stage_v_391_2 = ((pub_r001195_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001195_3_1 * 2) + 34) & 63;
  int stage_v_392_2 = ((pub_r001195_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001195_0_1 * 2) + 41) & 63;
  int stage_v_393_2 = ((pub_r001195_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((helper_flow_2_1 << 1) ^ (pub_r001195_6_1 >> 1)) & 127;
  int stage_v_394_2 = ((helper_flow_2_2 << 1) ^ (pub_r001195_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_394_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_394_2 + 1) & 15;
  out_sink_1 ^= stage_v_394_1 & 63;
  out_sink_2 ^= stage_v_394_2 & 63;
  int stage_v_395_1 = ((pub_r001195_1_1 * 2) + 19) & 63;
  int stage_v_395_2 = ((pub_r001195_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_295_1 << 1) ^ (pub_r001195_8_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_295_2 << 1) ^ (pub_r001195_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((stage_v_96_1 << 1) ^ (pub_r001195_14_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_96_2 << 1) ^ (pub_r001195_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((pub_r001195_15_1 * 2) + 48) & 63;
  int stage_v_398_2 = ((pub_r001195_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001195_10_1 * 2) + 31) & 63;
  int stage_v_399_2 = ((pub_r001195_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001195_16_1 * 2) + 31) & 63;
  int stage_v_400_2 = ((pub_r001195_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_180_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_180_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_225_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_225_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((stage_v_208_1 << 1) ^ (pub_r001195_7_1 >> 1)) & 127;
  int stage_v_403_2 = ((stage_v_208_2 << 1) ^ (pub_r001195_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_13_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_13_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001195_1_1 * 2) + 42) & 63;
  int stage_v_405_2 = ((pub_r001195_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_38_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_38_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((pub_r001195_10_1 * 2) + 48) & 63;
  int stage_v_407_2 = ((pub_r001195_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001195_16_1 * 2) + 18) & 63;
  int stage_v_408_2 = ((pub_r001195_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001195_1_1 * 2) + 20) & 63;
  int stage_v_409_2 = ((pub_r001195_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((sec_r001195_17_1 << 1) ^ (pub_r001195_5_1 >> 1)) & 127;
  int stage_v_410_2 = ((sec_r001195_17_2 << 1) ^ (pub_r001195_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((pub_r001195_2_1 * 2) + 38) & 63;
  int stage_v_411_2 = ((pub_r001195_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001195_3_1 * 2) + 24) & 63;
  int stage_v_412_2 = ((pub_r001195_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((stage_v_213_1 << 1) ^ (pub_r001195_17_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_213_2 << 1) ^ (pub_r001195_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((stage_v_141_1 << 1) ^ (pub_r001195_3_1 >> 1)) & 127;
  int stage_v_414_2 = ((stage_v_141_2 << 1) ^ (pub_r001195_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_414_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_414_2 + 1) & 15;
  out_sink_1 ^= stage_v_414_1 & 63;
  out_sink_2 ^= stage_v_414_2 & 63;
  int stage_v_415_1 = ((pub_r001195_11_1 * 2) + 14) & 63;
  int stage_v_415_2 = ((pub_r001195_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001195_5_1 * 2) + 20) & 63;
  int stage_v_416_2 = ((pub_r001195_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001195_1_1 * 2) + 47) & 63;
  int stage_v_417_2 = ((pub_r001195_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((stage_v_111_1 << 1) ^ (pub_r001195_16_1 >> 1)) & 127;
  int stage_v_418_2 = ((stage_v_111_2 << 1) ^ (pub_r001195_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_418_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_418_2 + 1) & 15;
  out_sink_1 ^= stage_v_418_1 & 63;
  out_sink_2 ^= stage_v_418_2 & 63;
  int stage_v_419_1 = ((stage_v_96_1 << 1) ^ (pub_r001195_2_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_96_2 << 1) ^ (pub_r001195_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_326_1 << 1) ^ (pub_r001195_15_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_326_2 << 1) ^ (pub_r001195_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((stage_v_239_1 << 1) ^ (pub_r001195_19_1 >> 1)) & 127;
  int stage_v_421_2 = ((stage_v_239_2 << 1) ^ (pub_r001195_19_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_421_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_421_2 + 1) & 15;
  out_sink_1 ^= stage_v_421_1 & 63;
  out_sink_2 ^= stage_v_421_2 & 63;
  int stage_v_422_1 = ((pub_r001195_5_1 * 2) + 47) & 63;
  int stage_v_422_2 = ((pub_r001195_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001195_7_1 * 2) + 33) & 63;
  int stage_v_423_2 = ((pub_r001195_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001195_8_1 * 2) + 27) & 63;
  int stage_v_424_2 = ((pub_r001195_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001195_22_1 != sec_r001195_22_2);
  __CPROVER_assume(pub_r001195_12_1 == pub_r001195_12_2);
  __CPROVER_assume(pub_r001195_16_1 == pub_r001195_16_2);
  __CPROVER_assume(sec_r001195_6_1 != sec_r001195_6_2);
  __CPROVER_assume(pub_r001195_18_1 == pub_r001195_18_2);
  __CPROVER_assume(pub_r001195_6_1 == pub_r001195_6_2);
  __CPROVER_assume(sec_r001195_19_1 != sec_r001195_19_2);
  __CPROVER_assume(pub_r001195_11_1 == pub_r001195_11_2);
  __CPROVER_assume(pub_r001195_3_1 == pub_r001195_3_2);
  __CPROVER_assume(sec_r001195_4_1 != sec_r001195_4_2);
  __CPROVER_assume(sec_r001195_14_1 != sec_r001195_14_2);
  __CPROVER_assume(sec_r001195_0_1 != sec_r001195_0_2);
  __CPROVER_assume(sec_r001195_8_1 != sec_r001195_8_2);
  __CPROVER_assume(sec_r001195_20_1 != sec_r001195_20_2);
  __CPROVER_assume(pub_r001195_4_1 == pub_r001195_4_2);
  __CPROVER_assume(pub_r001195_19_1 == pub_r001195_19_2);
  __CPROVER_assume(sec_r001195_18_1 != sec_r001195_18_2);
  __CPROVER_assume(pub_r001195_14_1 == pub_r001195_14_2);
  __CPROVER_assume(sec_r001195_5_1 != sec_r001195_5_2);
  __CPROVER_assume(pub_r001195_15_1 == pub_r001195_15_2);
  __CPROVER_assume(sec_r001195_9_1 != sec_r001195_9_2);
  __CPROVER_assume(pub_r001195_9_1 == pub_r001195_9_2);
  __CPROVER_assume(sec_r001195_2_1 != sec_r001195_2_2);
  __CPROVER_assume(sec_r001195_17_1 != sec_r001195_17_2);
  __CPROVER_assume(pub_r001195_5_1 == pub_r001195_5_2);
  __CPROVER_assume(sec_r001195_12_1 != sec_r001195_12_2);
  __CPROVER_assume(pub_r001195_10_1 == pub_r001195_10_2);
  __CPROVER_assume(pub_r001195_17_1 == pub_r001195_17_2);
  __CPROVER_assume(sec_r001195_11_1 != sec_r001195_11_2);
  __CPROVER_assume(sec_r001195_13_1 != sec_r001195_13_2);
  __CPROVER_assume(pub_r001195_8_1 == pub_r001195_8_2);
  __CPROVER_assume(sec_r001195_23_1 != sec_r001195_23_2);
  __CPROVER_assume(pub_r001195_7_1 == pub_r001195_7_2);
  __CPROVER_assume(sec_r001195_7_1 != sec_r001195_7_2);
  __CPROVER_assume(pub_r001195_0_1 == pub_r001195_0_2);
  __CPROVER_assume(pub_r001195_1_1 == pub_r001195_1_2);
  __CPROVER_assume(sec_r001195_15_1 != sec_r001195_15_2);
  __CPROVER_assume(sec_r001195_10_1 != sec_r001195_10_2);
  __CPROVER_assume(sec_r001195_3_1 != sec_r001195_3_2);
  __CPROVER_assume(sec_r001195_1_1 != sec_r001195_1_2);
  __CPROVER_assume(pub_r001195_13_1 == pub_r001195_13_2);
  __CPROVER_assume(sec_r001195_21_1 != sec_r001195_21_2);
  __CPROVER_assume(pub_r001195_2_1 == pub_r001195_2_2);
  __CPROVER_assume(sec_r001195_16_1 != sec_r001195_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
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
}


