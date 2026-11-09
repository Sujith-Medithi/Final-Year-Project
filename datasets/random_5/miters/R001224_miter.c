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
struct AudioFrame_R001224_2413_0
{
  int peak;
  int gain;
  unsigned char channels;
  int rms;
  int buffer[3];
};
struct DeviceConfig_R001224_2413_1
{
  int baud_rate;
  int timeout;
  unsigned char id;
  int buffer[3];
};
union TelemetryField_R001224_2413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001224_2413_1
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
void fn_R001224_2413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int stride_17_1 = 0;
  int stride_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_17_1 = ((stride_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_17_2 = ((stride_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_17_1) & 127;
    acc_2 = (acc_2 + stride_17_2) & 127;
  }

  int checksum_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_45_1) & 63;
  aux_2 = (aux_2 + checksum_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_45_1 > 23)
  {
    acc_1 = ((acc_1 + (window_45_1 * 2)) + 5) & 127;
    aux_1 ^= window_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_45_2 > 23)
  {
    acc_2 = ((acc_2 + (window_45_2 * 2)) + 5) & 127;
    aux_2 ^= window_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_23_1)
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

  switch (segment_23_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_17_1 == stride_17_2);
  assert(checksum_45_1 == checksum_45_2);
  assert(window_45_1 == window_45_2);
  assert(segment_23_1 == segment_23_2);
}

int fn_R001224_2413_0(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int stride_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_17 = ((stride_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_17) & 127;
  }

  int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_45) & 63;
  acc ^= aux;
  int window_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_45 > 23)
  {
    acc = ((acc + (window_45 * 2)) + 5) & 127;
    aux ^= window_45 & 15;
  }
  else
  {
    acc = ((acc - window_45) + 11) & 127;
    aux += 3;
  }
  int segment_23 = (aux + st.buffer[1]) & 3;
  switch (segment_23)
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

void fn_R001224_2413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int tally_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_85_1) & 63;
  aux_2 = (aux_2 + tally_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_45_1 = 0;
  int bound_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_45_1 = ((bound_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_45_2 = ((bound_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_45_1) & 127;
    acc_2 = (acc_2 + bound_45_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_85_1 == tally_85_2);
  assert(bound_45_1 == bound_45_2);
}

int fn_R001224_2413_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int tally_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_85) & 63;
  acc ^= aux;
  int bound_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_45 = ((bound_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_45) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int weight_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_93_1) & 63;
  aux_2 = (aux_2 + weight_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_13_1 = local_arr_1[aux_1 % 3];
  int index_reg_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_93_1 == weight_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_13_1 == index_reg_13_2);
}

int fn_R001224_2413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int weight_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_93) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int index_reg_13 = local_arr[aux % 3];
  acc = (acc + (index_reg_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int bound_61_1 = 0;
  int bound_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_61_1 = ((bound_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_61_2 = ((bound_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_61_1) & 127;
    acc_2 = (acc_2 + bound_61_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_73_1) & 63;
  aux_2 = (aux_2 + sample_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_57_1 > 50)
  {
    acc_1 = ((acc_1 + (residue_57_1 * 2)) + 5) & 127;
    aux_1 ^= residue_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_57_2 > 50)
  {
    acc_2 = ((acc_2 + (residue_57_2 * 2)) + 5) & 127;
    aux_2 ^= residue_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_61_1 == bound_61_2);
  assert(sample_73_1 == sample_73_2);
  assert(residue_57_1 == residue_57_2);
}

int fn_R001224_2413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int bound_61 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_61 = ((bound_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_61) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_73) & 63;
  acc ^= aux;
  int residue_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_57 > 50)
  {
    acc = ((acc + (residue_57 * 2)) + 5) & 127;
    aux ^= residue_57 & 15;
  }
  else
  {
    acc = ((acc - residue_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001224_2413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int factor_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_87_1 > 31)
  {
    acc_1 = ((acc_1 + (factor_87_1 * 2)) + 5) & 127;
    aux_1 ^= factor_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_87_2 > 31)
  {
    acc_2 = ((acc_2 + (factor_87_2 * 2)) + 5) & 127;
    aux_2 ^= factor_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_86_1) & 63;
  aux_2 = (aux_2 + damping_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_94_1 = local_arr_1[aux_1 % 3];
  int scale_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_94_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_87_1 == factor_87_2);
  assert(damping_86_1 == damping_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_94_1 == scale_94_2);
}

int fn_R001224_2413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int factor_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_87 > 31)
  {
    acc = ((acc + (factor_87 * 2)) + 5) & 127;
    aux ^= factor_87 & 15;
  }
  else
  {
    acc = ((acc - factor_87) + 11) & 127;
    aux += 3;
  }
  int damping_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_86) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_94 = local_arr[aux % 3];
  acc = (acc + (scale_94 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int tally_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_17_1) & 63;
  aux_2 = (aux_2 + tally_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_43_1 > 28)
  {
    acc_1 = ((acc_1 + (bound_43_1 * 2)) + 5) & 127;
    aux_1 ^= bound_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_43_2 > 28)
  {
    acc_2 = ((acc_2 + (bound_43_2 * 2)) + 5) & 127;
    aux_2 ^= bound_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_21_1)
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

  switch (residue_21_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_17_1 == tally_17_2);
  assert(bound_43_1 == bound_43_2);
  assert(residue_21_1 == residue_21_2);
}

int fn_R001224_2413_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_17) & 63;
  acc ^= aux;
  int bound_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_43 > 28)
  {
    acc = ((acc + (bound_43 * 2)) + 5) & 127;
    aux ^= bound_43 & 15;
  }
  else
  {
    acc = ((acc - bound_43) + 11) & 127;
    aux += 3;
  }
  int residue_21 = (aux + st.buffer[1]) & 3;
  switch (residue_21)
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

void fn_R001224_2413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int weight_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_19_1)
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

  switch (weight_19_2)
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
  int metric_25_1 = local_arr_1[aux_1 % 3];
  int metric_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_25_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_19_1 == weight_19_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_25_1 == metric_25_2);
}

int fn_R001224_2413_6(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int weight_19 = (aux + st.buffer[1]) & 3;
  switch (weight_19)
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
  int metric_25 = local_arr[aux % 3];
  acc = (acc + (metric_25 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_48_1 > 12)
  {
    acc_1 = ((acc_1 + (vector_48_1 * 2)) + 5) & 127;
    aux_1 ^= vector_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_48_2 > 12)
  {
    acc_2 = ((acc_2 + (vector_48_2 * 2)) + 5) & 127;
    aux_2 ^= vector_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_48_1 == vector_48_2);
}

int fn_R001224_2413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_48 > 12)
  {
    acc = ((acc + (vector_48 * 2)) + 5) & 127;
    aux ^= vector_48 & 15;
  }
  else
  {
    acc = ((acc - vector_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_85_1)
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

  switch (segment_85_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_85_1 == segment_85_2);
}

int fn_R001224_2413_8(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_85 = (aux + st.buffer[1]) & 3;
  switch (segment_85)
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

void fn_R001224_2413_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_59_1 > 33)
  {
    acc_1 = ((acc_1 + (damping_59_1 * 2)) + 5) & 127;
    aux_1 ^= damping_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_59_2 > 33)
  {
    acc_2 = ((acc_2 + (damping_59_2 * 2)) + 5) & 127;
    aux_2 ^= damping_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_86_1) & 63;
  aux_2 = (aux_2 + phase_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_48_1 = 0;
  int anchor_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_48_1 = ((anchor_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_48_2 = ((anchor_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_48_1) & 127;
    acc_2 = (acc_2 + anchor_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_59_1 == damping_59_2);
  assert(phase_86_1 == phase_86_2);
  assert(anchor_48_1 == anchor_48_2);
}

int fn_R001224_2413_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_59 > 33)
  {
    acc = ((acc + (damping_59 * 2)) + 5) & 127;
    aux ^= damping_59 & 15;
  }
  else
  {
    acc = ((acc - damping_59) + 11) & 127;
    aux += 3;
  }
  int phase_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_86) & 63;
  acc ^= aux;
  int anchor_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_48 = ((anchor_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_93_1 = local_arr_1[aux_1 % 3];
  int weight_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_93_2 * 2)) & 127;
  int tracker_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_22_1) & 63;
  aux_2 = (aux_2 + tracker_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_81_1 = 0;
  int mask_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_81_1 = ((mask_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_81_2 = ((mask_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_81_1) & 127;
    acc_2 = (acc_2 + mask_81_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
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

  assert(weight_93_1 == weight_93_2);
  assert(tracker_22_1 == tracker_22_2);
  assert(mask_81_1 == mask_81_2);
}

int fn_R001224_2413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int weight_93 = local_arr[aux % 3];
  acc = (acc + (weight_93 * 2)) & 127;
  int tracker_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_22) & 63;
  acc ^= aux;
  int mask_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_81 = ((mask_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_81) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_22_1) & 63;
  aux_2 = (aux_2 + vector_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_84_1 = 0;
  int offset_84_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_84_1 = ((offset_84_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_84_2 = ((offset_84_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_84_1) & 127;
    acc_2 = (acc_2 + offset_84_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_22_1 == vector_22_2);
  assert(offset_84_1 == offset_84_2);
}

int fn_R001224_2413_11(int p0, int p1)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_22) & 63;
  acc ^= aux;
  int offset_84 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_84 = ((offset_84 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_84) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_87_1 = 0;
  int bound_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_87_1 = ((bound_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_87_2 = ((bound_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_87_1) & 127;
    acc_2 = (acc_2 + bound_87_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_78_1 > 46)
  {
    acc_1 = ((acc_1 + (quotient_78_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_78_2 > 46)
  {
    acc_2 = ((acc_2 + (quotient_78_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_87_1 == bound_87_2);
  assert(quotient_78_1 == quotient_78_2);
}

int fn_R001224_2413_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_87 = ((bound_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_87) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_78 > 46)
  {
    acc = ((acc + (quotient_78 * 2)) + 5) & 127;
    aux ^= quotient_78 & 15;
  }
  else
  {
    acc = ((acc - quotient_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001224_2413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int pivot_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_62_1) & 63;
  aux_2 = (aux_2 + pivot_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_29_1 > 18)
  {
    acc_1 = ((acc_1 + (checksum_29_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_29_2 > 18)
  {
    acc_2 = ((acc_2 + (checksum_29_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_37_1 = 0;
  int checksum_37_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_37_1 = ((checksum_37_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_37_2 = ((checksum_37_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_37_1) & 127;
    acc_2 = (acc_2 + checksum_37_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_62_1 == pivot_62_2);
  assert(checksum_29_1 == checksum_29_2);
  assert(checksum_37_1 == checksum_37_2);
}

int fn_R001224_2413_13(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int pivot_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_62) & 63;
  acc ^= aux;
  int checksum_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_29 > 18)
  {
    acc = ((acc + (checksum_29 * 2)) + 5) & 127;
    aux ^= checksum_29 & 15;
  }
  else
  {
    acc = ((acc - checksum_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_37 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_37 = ((checksum_37 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_37) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_23_1 = 0;
  int sample_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_23_1 = ((sample_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_23_2 = ((sample_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_23_1) & 127;
    acc_2 = (acc_2 + sample_23_2) & 127;
  }

  int sample_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_65_1)
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

  switch (sample_65_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_23_1 == sample_23_2);
  assert(sample_65_1 == sample_65_2);
}

int fn_R001224_2413_14(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_23 = ((sample_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_23) & 127;
  }

  int sample_65 = (aux + st.buffer[1]) & 3;
  switch (sample_65)
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

void fn_R001224_2413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int cursor_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_24_1)
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

  switch (cursor_24_2)
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

  int offset_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_36_1 > 44)
  {
    acc_1 = ((acc_1 + (offset_36_1 * 2)) + 5) & 127;
    aux_1 ^= offset_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_36_2 > 44)
  {
    acc_2 = ((acc_2 + (offset_36_2 * 2)) + 5) & 127;
    aux_2 ^= offset_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_36_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_24_1 == cursor_24_2);
  assert(offset_36_1 == offset_36_2);
}

int fn_R001224_2413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int cursor_24 = (aux + st.buffer[1]) & 3;
  switch (cursor_24)
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

  int offset_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_36 > 44)
  {
    acc = ((acc + (offset_36 * 2)) + 5) & 127;
    aux ^= offset_36 & 15;
  }
  else
  {
    acc = ((acc - offset_36) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001224_2413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_49_1 = 0;
  int offset_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_49_1 = ((offset_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_49_2 = ((offset_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_49_1) & 127;
    acc_2 = (acc_2 + offset_49_2) & 127;
  }

  int quantum_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_25_1) & 63;
  aux_2 = (aux_2 + quantum_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_98_1 = local_arr_1[aux_1 % 3];
  int tracker_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_98_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_49_1 == offset_49_2);
  assert(quantum_25_1 == quantum_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_98_1 == tracker_98_2);
}

int fn_R001224_2413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_49 = ((offset_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_49) & 127;
  }

  int quantum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tracker_98 = local_arr[aux % 3];
  acc = (acc + (tracker_98 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int residue_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_11_1)
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

  switch (residue_11_2)
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

  int cursor_50_1 = 0;
  int cursor_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_50_1 = ((cursor_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_50_2 = ((cursor_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_50_1) & 127;
    acc_2 = (acc_2 + cursor_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_11_1 == residue_11_2);
  assert(cursor_50_1 == cursor_50_2);
}

int fn_R001224_2413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int residue_11 = (aux + st.buffer[1]) & 3;
  switch (residue_11)
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

  int cursor_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_50 = ((cursor_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_50) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_87_1)
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

  switch (delta_87_2)
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

  int phase_88_1 = 0;
  int phase_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_88_1 = ((phase_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_88_2 = ((phase_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_88_1) & 127;
    acc_2 = (acc_2 + phase_88_2) & 127;
  }

  int threshold_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_18_1 > 43)
  {
    acc_1 = ((acc_1 + (threshold_18_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_18_2 > 43)
  {
    acc_2 = ((acc_2 + (threshold_18_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_87_1 == delta_87_2);
  assert(phase_88_1 == phase_88_2);
  assert(threshold_18_1 == threshold_18_2);
}

int fn_R001224_2413_18(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_87 = (aux + st.buffer[1]) & 3;
  switch (delta_87)
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

  int phase_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_88 = ((phase_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_88) & 127;
  }

  int threshold_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_18 > 43)
  {
    acc = ((acc + (threshold_18 * 2)) + 5) & 127;
    aux ^= threshold_18 & 15;
  }
  else
  {
    acc = ((acc - threshold_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001224_2413_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_54_1)
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

  switch (sample_54_2)
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
  int accumulator_63_1 = 0;
  int accumulator_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_63_1 = ((accumulator_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_63_2 = ((accumulator_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_63_1) & 127;
    acc_2 = (acc_2 + accumulator_63_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_54_1 == sample_54_2);
  assert(accumulator_63_1 == accumulator_63_2);
}

int fn_R001224_2413_19(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001224_2413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_54 = (aux + st.buffer[1]) & 3;
  switch (sample_54)
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
  int accumulator_63 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_63 = ((accumulator_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_63) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001224_2413_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_69_1 = 0;
  int damping_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_69_1 = ((damping_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_69_2 = ((damping_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_69_1) & 127;
    acc_2 = (acc_2 + damping_69_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_73_1 = local_arr_1[aux_1 % 3];
  int quotient_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_73_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_69_1 == damping_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_73_1 == quotient_73_2);
}

int fn_R001224_2413_20(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_69 = ((damping_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_69) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_73 = local_arr[aux % 3];
  acc = (acc + (quotient_73 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001224_2413_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st_1 = {0};
  struct AudioFrame_R001224_2413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_36_1) & 63;
  aux_2 = (aux_2 + coefficient_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_25_1 > 27)
  {
    acc_1 = ((acc_1 + (threshold_25_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_25_2 > 27)
  {
    acc_2 = ((acc_2 + (threshold_25_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_25_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_50_1 = 0;
  int segment_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_50_1 = ((segment_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_50_2 = ((segment_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_50_1) & 127;
    acc_2 = (acc_2 + segment_50_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  assert(st_1.channels == st_2.channels);
  assert(st_1.rms == st_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_36_1 == coefficient_36_2);
  assert(threshold_25_1 == threshold_25_2);
  assert(segment_50_1 == segment_50_2);
}

int fn_R001224_2413_21(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001224_2413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_36) & 63;
  acc ^= aux;
  int threshold_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_25 > 27)
  {
    acc = ((acc + (threshold_25 * 2)) + 5) & 127;
    aux ^= threshold_25 & 15;
  }
  else
  {
    acc = ((acc - threshold_25) + 11) & 127;
    aux += 3;
  }
  int segment_50 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_50 = ((segment_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_50) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001224_0_1;
  int sec_r001224_0_2;
  int sec_r001224_1_1;
  int sec_r001224_1_2;
  int sec_r001224_2_1;
  int sec_r001224_2_2;
  int sec_r001224_3_1;
  int sec_r001224_3_2;
  int sec_r001224_4_1;
  int sec_r001224_4_2;
  int sec_r001224_5_1;
  int sec_r001224_5_2;
  int sec_r001224_6_1;
  int sec_r001224_6_2;
  int sec_r001224_7_1;
  int sec_r001224_7_2;
  int sec_r001224_8_1;
  int sec_r001224_8_2;
  int sec_r001224_9_1;
  int sec_r001224_9_2;
  int sec_r001224_10_1;
  int sec_r001224_10_2;
  int sec_r001224_11_1;
  int sec_r001224_11_2;
  int sec_r001224_12_1;
  int sec_r001224_12_2;
  int sec_r001224_13_1;
  int sec_r001224_13_2;
  int sec_r001224_14_1;
  int sec_r001224_14_2;
  int sec_r001224_15_1;
  int sec_r001224_15_2;
  int sec_r001224_16_1;
  int sec_r001224_16_2;
  int pub_r001224_0_1;
  int pub_r001224_0_2;
  int pub_r001224_1_1;
  int pub_r001224_1_2;
  int pub_r001224_2_1;
  int pub_r001224_2_2;
  int pub_r001224_3_1;
  int pub_r001224_3_2;
  int pub_r001224_4_1;
  int pub_r001224_4_2;
  int pub_r001224_5_1;
  int pub_r001224_5_2;
  int pub_r001224_6_1;
  int pub_r001224_6_2;
  int pub_r001224_7_1;
  int pub_r001224_7_2;
  int pub_r001224_8_1;
  int pub_r001224_8_2;
  int pub_r001224_9_1;
  int pub_r001224_9_2;
  int pub_r001224_10_1;
  int pub_r001224_10_2;
  int pub_r001224_11_1;
  int pub_r001224_11_2;
  int pub_r001224_12_1;
  int pub_r001224_12_2;
  int pub_r001224_13_1;
  int pub_r001224_13_2;
  int pub_r001224_14_1;
  int pub_r001224_14_2;
  int pub_r001224_15_1;
  int pub_r001224_15_2;
  int pub_r001224_16_1;
  int pub_r001224_16_2;
  int pub_r001224_17_1;
  int pub_r001224_17_2;
  int pub_r001224_18_1;
  int pub_r001224_18_2;
  int pub_r001224_19_1;
  int pub_r001224_19_2;
  int pub_r001224_20_1;
  int pub_r001224_20_2;
  int pub_r001224_21_1;
  int pub_r001224_21_2;
  int pub_r001224_22_1;
  int pub_r001224_22_2;
  int pub_r001224_23_1;
  int pub_r001224_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001224_0_1 >= (-100)) && (pub_r001224_0_1 <= 100));
  __CPROVER_assume((pub_r001224_0_2 >= (-100)) && (pub_r001224_0_2 <= 100));
  __CPROVER_assume((pub_r001224_1_1 >= (-100)) && (pub_r001224_1_1 <= 100));
  __CPROVER_assume((pub_r001224_1_2 >= (-100)) && (pub_r001224_1_2 <= 100));
  __CPROVER_assume((pub_r001224_2_1 >= (-100)) && (pub_r001224_2_1 <= 100));
  __CPROVER_assume((pub_r001224_2_2 >= (-100)) && (pub_r001224_2_2 <= 100));
  __CPROVER_assume((pub_r001224_3_1 >= (-100)) && (pub_r001224_3_1 <= 100));
  __CPROVER_assume((pub_r001224_3_2 >= (-100)) && (pub_r001224_3_2 <= 100));
  __CPROVER_assume((pub_r001224_4_1 >= (-100)) && (pub_r001224_4_1 <= 100));
  __CPROVER_assume((pub_r001224_4_2 >= (-100)) && (pub_r001224_4_2 <= 100));
  __CPROVER_assume((pub_r001224_5_1 >= (-100)) && (pub_r001224_5_1 <= 100));
  __CPROVER_assume((pub_r001224_5_2 >= (-100)) && (pub_r001224_5_2 <= 100));
  __CPROVER_assume((pub_r001224_6_1 >= (-100)) && (pub_r001224_6_1 <= 100));
  __CPROVER_assume((pub_r001224_6_2 >= (-100)) && (pub_r001224_6_2 <= 100));
  __CPROVER_assume((pub_r001224_7_1 >= (-100)) && (pub_r001224_7_1 <= 100));
  __CPROVER_assume((pub_r001224_7_2 >= (-100)) && (pub_r001224_7_2 <= 100));
  __CPROVER_assume((pub_r001224_8_1 >= (-100)) && (pub_r001224_8_1 <= 100));
  __CPROVER_assume((pub_r001224_8_2 >= (-100)) && (pub_r001224_8_2 <= 100));
  __CPROVER_assume((pub_r001224_9_1 >= (-100)) && (pub_r001224_9_1 <= 100));
  __CPROVER_assume((pub_r001224_9_2 >= (-100)) && (pub_r001224_9_2 <= 100));
  __CPROVER_assume((pub_r001224_10_1 >= (-100)) && (pub_r001224_10_1 <= 100));
  __CPROVER_assume((pub_r001224_10_2 >= (-100)) && (pub_r001224_10_2 <= 100));
  __CPROVER_assume((pub_r001224_11_1 >= (-100)) && (pub_r001224_11_1 <= 100));
  __CPROVER_assume((pub_r001224_11_2 >= (-100)) && (pub_r001224_11_2 <= 100));
  __CPROVER_assume((pub_r001224_12_1 >= (-100)) && (pub_r001224_12_1 <= 100));
  __CPROVER_assume((pub_r001224_12_2 >= (-100)) && (pub_r001224_12_2 <= 100));
  __CPROVER_assume((pub_r001224_13_1 >= (-100)) && (pub_r001224_13_1 <= 100));
  __CPROVER_assume((pub_r001224_13_2 >= (-100)) && (pub_r001224_13_2 <= 100));
  __CPROVER_assume((pub_r001224_14_1 >= (-100)) && (pub_r001224_14_1 <= 100));
  __CPROVER_assume((pub_r001224_14_2 >= (-100)) && (pub_r001224_14_2 <= 100));
  __CPROVER_assume((pub_r001224_15_1 >= (-100)) && (pub_r001224_15_1 <= 100));
  __CPROVER_assume((pub_r001224_15_2 >= (-100)) && (pub_r001224_15_2 <= 100));
  __CPROVER_assume((pub_r001224_16_1 >= (-100)) && (pub_r001224_16_1 <= 100));
  __CPROVER_assume((pub_r001224_16_2 >= (-100)) && (pub_r001224_16_2 <= 100));
  __CPROVER_assume((pub_r001224_17_1 >= (-100)) && (pub_r001224_17_1 <= 100));
  __CPROVER_assume((pub_r001224_17_2 >= (-100)) && (pub_r001224_17_2 <= 100));
  __CPROVER_assume((pub_r001224_18_1 >= (-100)) && (pub_r001224_18_1 <= 100));
  __CPROVER_assume((pub_r001224_18_2 >= (-100)) && (pub_r001224_18_2 <= 100));
  __CPROVER_assume((pub_r001224_19_1 >= (-100)) && (pub_r001224_19_1 <= 100));
  __CPROVER_assume((pub_r001224_19_2 >= (-100)) && (pub_r001224_19_2 <= 100));
  __CPROVER_assume((pub_r001224_20_1 >= (-100)) && (pub_r001224_20_1 <= 100));
  __CPROVER_assume((pub_r001224_20_2 >= (-100)) && (pub_r001224_20_2 <= 100));
  __CPROVER_assume((pub_r001224_21_1 >= (-100)) && (pub_r001224_21_1 <= 100));
  __CPROVER_assume((pub_r001224_21_2 >= (-100)) && (pub_r001224_21_2 <= 100));
  __CPROVER_assume((pub_r001224_22_1 >= (-100)) && (pub_r001224_22_1 <= 100));
  __CPROVER_assume((pub_r001224_22_2 >= (-100)) && (pub_r001224_22_2 <= 100));
  __CPROVER_assume((pub_r001224_23_1 >= (-100)) && (pub_r001224_23_1 <= 100));
  __CPROVER_assume((pub_r001224_23_2 >= (-100)) && (pub_r001224_23_2 <= 100));
  __CPROVER_assume((sec_r001224_0_1 >= 0) && (sec_r001224_0_1 <= 255));
  __CPROVER_assume((sec_r001224_0_2 >= 0) && (sec_r001224_0_2 <= 255));
  __CPROVER_assume((sec_r001224_1_1 >= 0) && (sec_r001224_1_1 <= 255));
  __CPROVER_assume((sec_r001224_1_2 >= 0) && (sec_r001224_1_2 <= 255));
  __CPROVER_assume((sec_r001224_2_1 >= 0) && (sec_r001224_2_1 <= 255));
  __CPROVER_assume((sec_r001224_2_2 >= 0) && (sec_r001224_2_2 <= 255));
  __CPROVER_assume((sec_r001224_3_1 >= 0) && (sec_r001224_3_1 <= 255));
  __CPROVER_assume((sec_r001224_3_2 >= 0) && (sec_r001224_3_2 <= 255));
  __CPROVER_assume((sec_r001224_4_1 >= 0) && (sec_r001224_4_1 <= 255));
  __CPROVER_assume((sec_r001224_4_2 >= 0) && (sec_r001224_4_2 <= 255));
  __CPROVER_assume((sec_r001224_5_1 >= 0) && (sec_r001224_5_1 <= 255));
  __CPROVER_assume((sec_r001224_5_2 >= 0) && (sec_r001224_5_2 <= 255));
  __CPROVER_assume((sec_r001224_6_1 >= 0) && (sec_r001224_6_1 <= 255));
  __CPROVER_assume((sec_r001224_6_2 >= 0) && (sec_r001224_6_2 <= 255));
  __CPROVER_assume((sec_r001224_7_1 >= 0) && (sec_r001224_7_1 <= 255));
  __CPROVER_assume((sec_r001224_7_2 >= 0) && (sec_r001224_7_2 <= 255));
  __CPROVER_assume((sec_r001224_8_1 >= 0) && (sec_r001224_8_1 <= 255));
  __CPROVER_assume((sec_r001224_8_2 >= 0) && (sec_r001224_8_2 <= 255));
  __CPROVER_assume((sec_r001224_9_1 >= 0) && (sec_r001224_9_1 <= 255));
  __CPROVER_assume((sec_r001224_9_2 >= 0) && (sec_r001224_9_2 <= 255));
  __CPROVER_assume((sec_r001224_10_1 >= 0) && (sec_r001224_10_1 <= 255));
  __CPROVER_assume((sec_r001224_10_2 >= 0) && (sec_r001224_10_2 <= 255));
  __CPROVER_assume((sec_r001224_11_1 >= 0) && (sec_r001224_11_1 <= 255));
  __CPROVER_assume((sec_r001224_11_2 >= 0) && (sec_r001224_11_2 <= 255));
  __CPROVER_assume((sec_r001224_12_1 >= 0) && (sec_r001224_12_1 <= 255));
  __CPROVER_assume((sec_r001224_12_2 >= 0) && (sec_r001224_12_2 <= 255));
  __CPROVER_assume((sec_r001224_13_1 >= 0) && (sec_r001224_13_1 <= 255));
  __CPROVER_assume((sec_r001224_13_2 >= 0) && (sec_r001224_13_2 <= 255));
  __CPROVER_assume((sec_r001224_14_1 >= 0) && (sec_r001224_14_1 <= 255));
  __CPROVER_assume((sec_r001224_14_2 >= 0) && (sec_r001224_14_2 <= 255));
  __CPROVER_assume((sec_r001224_15_1 >= 0) && (sec_r001224_15_1 <= 255));
  __CPROVER_assume((sec_r001224_15_2 >= 0) && (sec_r001224_15_2 <= 255));
  __CPROVER_assume((sec_r001224_16_1 >= 0) && (sec_r001224_16_1 <= 255));
  __CPROVER_assume((sec_r001224_16_2 >= 0) && (sec_r001224_16_2 <= 255));
  struct AudioFrame_R001224_2413_0 st_var_0_1 = {0};
  struct AudioFrame_R001224_2413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001224_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001224_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001224_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001224_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001224_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001224_0_2 + 7) & 15;
  struct DeviceConfig_R001224_2413_1 st_var_1_1 = {0};
  struct DeviceConfig_R001224_2413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001224_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001224_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001224_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001224_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001224_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001224_0_2 + 9) & 15;
  union TelemetryField_R001224_2413_0 u_var_1;
  union TelemetryField_R001224_2413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001224_2413_0(sec_r001224_0_1, sec_r001224_1_1);
  int helper_flow_0_2 = fn_R001224_2413_0(sec_r001224_0_2, sec_r001224_1_2);
  fn_R001224_2413_0_2(sec_r001224_0_1, sec_r001224_1_1, sec_r001224_0_2, sec_r001224_1_2);
  int helper_flow_1_1 = fn_R001224_2413_1(sec_r001224_1_1, pub_r001224_2_1, pub_r001224_3_1, pub_r001224_4_1, pub_r001224_5_1);
  int helper_flow_1_2 = fn_R001224_2413_1(sec_r001224_1_2, pub_r001224_2_2, pub_r001224_3_2, pub_r001224_4_2, pub_r001224_5_2);
  fn_R001224_2413_1_2(sec_r001224_1_1, pub_r001224_2_1, pub_r001224_3_1, pub_r001224_4_1, pub_r001224_5_1, sec_r001224_1_2, pub_r001224_2_2, pub_r001224_3_2, pub_r001224_4_2, pub_r001224_5_2);
  int helper_flow_2_1 = fn_R001224_2413_2(sec_r001224_2_1, pub_r001224_3_1, pub_r001224_4_1, pub_r001224_5_1, pub_r001224_6_1);
  int helper_flow_2_2 = fn_R001224_2413_2(sec_r001224_2_2, pub_r001224_3_2, pub_r001224_4_2, pub_r001224_5_2, pub_r001224_6_2);
  fn_R001224_2413_2_2(sec_r001224_2_1, pub_r001224_3_1, pub_r001224_4_1, pub_r001224_5_1, pub_r001224_6_1, sec_r001224_2_2, pub_r001224_3_2, pub_r001224_4_2, pub_r001224_5_2, pub_r001224_6_2);
  int helper_flow_3_1 = fn_R001224_2413_3(sec_r001224_3_1, sec_r001224_4_1, pub_r001224_5_1, pub_r001224_6_1, pub_r001224_7_1);
  int helper_flow_3_2 = fn_R001224_2413_3(sec_r001224_3_2, sec_r001224_4_2, pub_r001224_5_2, pub_r001224_6_2, pub_r001224_7_2);
  fn_R001224_2413_3_2(sec_r001224_3_1, sec_r001224_4_1, pub_r001224_5_1, pub_r001224_6_1, pub_r001224_7_1, sec_r001224_3_2, sec_r001224_4_2, pub_r001224_5_2, pub_r001224_6_2, pub_r001224_7_2);
  int helper_flow_4_1 = fn_R001224_2413_4(sec_r001224_4_1, sec_r001224_5_1, pub_r001224_6_1, pub_r001224_7_1);
  int helper_flow_4_2 = fn_R001224_2413_4(sec_r001224_4_2, sec_r001224_5_2, pub_r001224_6_2, pub_r001224_7_2);
  fn_R001224_2413_4_2(sec_r001224_4_1, sec_r001224_5_1, pub_r001224_6_1, pub_r001224_7_1, sec_r001224_4_2, sec_r001224_5_2, pub_r001224_6_2, pub_r001224_7_2);
  int helper_flow_5_1 = fn_R001224_2413_5(sec_r001224_5_1, sec_r001224_6_1, pub_r001224_7_1, pub_r001224_8_1);
  int helper_flow_5_2 = fn_R001224_2413_5(sec_r001224_5_2, sec_r001224_6_2, pub_r001224_7_2, pub_r001224_8_2);
  fn_R001224_2413_5_2(sec_r001224_5_1, sec_r001224_6_1, pub_r001224_7_1, pub_r001224_8_1, sec_r001224_5_2, sec_r001224_6_2, pub_r001224_7_2, pub_r001224_8_2);
  int helper_flow_6_1 = fn_R001224_2413_6(sec_r001224_6_1, sec_r001224_7_1);
  int helper_flow_6_2 = fn_R001224_2413_6(sec_r001224_6_2, sec_r001224_7_2);
  fn_R001224_2413_6_2(sec_r001224_6_1, sec_r001224_7_1, sec_r001224_6_2, sec_r001224_7_2);
  int helper_flow_7_1 = fn_R001224_2413_7(sec_r001224_7_1, pub_r001224_8_1, pub_r001224_9_1, pub_r001224_10_1, pub_r001224_11_1);
  int helper_flow_7_2 = fn_R001224_2413_7(sec_r001224_7_2, pub_r001224_8_2, pub_r001224_9_2, pub_r001224_10_2, pub_r001224_11_2);
  fn_R001224_2413_7_2(sec_r001224_7_1, pub_r001224_8_1, pub_r001224_9_1, pub_r001224_10_1, pub_r001224_11_1, sec_r001224_7_2, pub_r001224_8_2, pub_r001224_9_2, pub_r001224_10_2, pub_r001224_11_2);
  int stage_v_0_1 = ((pub_r001224_9_1 * 2) + 29) & 63;
  int stage_v_0_2 = ((pub_r001224_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001224_21_1 * 2) + 7) & 63;
  int stage_v_1_2 = ((pub_r001224_21_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001224_4_1 * 2) + 12) & 63;
  int stage_v_2_2 = ((pub_r001224_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001224_5_1 * 3) + pub_r001224_19_1) + 21) & 127;
  int stage_v_3_2 = (((sec_r001224_5_2 * 3) + pub_r001224_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001224_0_1 * 2) + 15) & 63;
  int stage_v_4_2 = ((pub_r001224_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001224_1_1 * 2) + 33) & 63;
  int stage_v_5_2 = ((pub_r001224_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001224_11_1 * 3) + pub_r001224_23_1) + 37) & 127;
  int stage_v_6_2 = (((sec_r001224_11_2 * 3) + pub_r001224_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((sec_r001224_12_1 * 3) + pub_r001224_14_1) + 12) & 127;
  int stage_v_7_2 = (((sec_r001224_12_2 * 3) + pub_r001224_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((sec_r001224_5_1 * 3) + pub_r001224_20_1) + 36) & 127;
  int stage_v_8_2 = (((sec_r001224_5_2 * 3) + pub_r001224_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001224_5_1 * 3) + pub_r001224_23_1) + 23) & 127;
  int stage_v_9_2 = (((sec_r001224_5_2 * 3) + pub_r001224_23_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((stage_v_8_1 * 3) + pub_r001224_15_1) + 12) & 127;
  int stage_v_10_2 = (((stage_v_8_2 * 3) + pub_r001224_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001224_2_1 * 2) + 35) & 63;
  int stage_v_11_2 = ((pub_r001224_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001224_5_1 * 3) + pub_r001224_21_1) + 17) & 127;
  int stage_v_12_2 = (((sec_r001224_5_2 * 3) + pub_r001224_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001224_4_1 * 3) + pub_r001224_21_1) + 42) & 127;
  int stage_v_13_2 = (((sec_r001224_4_2 * 3) + pub_r001224_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((helper_flow_6_1 * 3) + pub_r001224_13_1) + 30) & 127;
  int stage_v_14_2 = (((helper_flow_6_2 * 3) + pub_r001224_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((helper_flow_4_1 * 3) + pub_r001224_1_1) + 12) & 127;
  int stage_v_15_2 = (((helper_flow_4_2 * 3) + pub_r001224_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_4_1 * 3) + pub_r001224_22_1) + 16) & 127;
  int stage_v_16_2 = (((helper_flow_4_2 * 3) + pub_r001224_22_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((helper_flow_0_1 * 3) + pub_r001224_23_1) + 16) & 127;
  int stage_v_17_2 = (((helper_flow_0_2 * 3) + pub_r001224_23_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((stage_v_16_1 * 3) + pub_r001224_0_1) + 40) & 127;
  int stage_v_18_2 = (((stage_v_16_2 * 3) + pub_r001224_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001224_16_1 * 2) + 31) & 63;
  int stage_v_19_2 = ((pub_r001224_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((pub_r001224_7_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001224_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001224_0_1 * 2) + 27) & 63;
  int stage_v_21_2 = ((pub_r001224_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001224_20_1 * 2) + 18) & 63;
  int stage_v_22_2 = ((pub_r001224_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((sec_r001224_16_1 * 3) + pub_r001224_19_1) + 35) & 127;
  int stage_v_23_2 = (((sec_r001224_16_2 * 3) + pub_r001224_19_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((helper_flow_6_1 * 3) + pub_r001224_13_1) + 45) & 127;
  int stage_v_24_2 = (((helper_flow_6_2 * 3) + pub_r001224_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001224_6_1 * 2) + 50) & 63;
  int stage_v_25_2 = ((pub_r001224_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001224_4_1 * 3) + pub_r001224_0_1) + 24) & 127;
  int stage_v_26_2 = (((sec_r001224_4_2 * 3) + pub_r001224_0_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001224_5_1 * 2) + 29) & 63;
  int stage_v_27_2 = ((pub_r001224_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001224_15_1 * 3) + pub_r001224_20_1) + 6) & 127;
  int stage_v_28_2 = (((sec_r001224_15_2 * 3) + pub_r001224_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001224_23_1 * 2) + 50) & 63;
  int stage_v_29_2 = ((pub_r001224_23_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((sec_r001224_6_1 * 3) + pub_r001224_13_1) + 23) & 127;
  int stage_v_30_2 = (((sec_r001224_6_2 * 3) + pub_r001224_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001224_19_1 * 2) + 9) & 63;
  int stage_v_31_2 = ((pub_r001224_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001224_16_1 * 3) + pub_r001224_14_1) + 43) & 127;
  int stage_v_32_2 = (((sec_r001224_16_2 * 3) + pub_r001224_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((stage_v_12_1 * 3) + pub_r001224_20_1) + 26) & 127;
  int stage_v_33_2 = (((stage_v_12_2 * 3) + pub_r001224_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001224_21_1 * 2) + 34) & 63;
  int stage_v_34_2 = ((pub_r001224_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001224_16_1 * 2) + 21) & 63;
  int stage_v_35_2 = ((pub_r001224_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001224_18_1 * 2) + 6) & 63;
  int stage_v_36_2 = ((pub_r001224_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001224_6_1 * 3) + pub_r001224_9_1) + 8) & 127;
  int stage_v_37_2 = (((sec_r001224_6_2 * 3) + pub_r001224_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((sec_r001224_8_1 * 3) + pub_r001224_16_1) + 41) & 127;
  int stage_v_38_2 = (((sec_r001224_8_2 * 3) + pub_r001224_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_38_1 * 3) + pub_r001224_10_1) + 18) & 127;
  int stage_v_39_2 = (((stage_v_38_2 * 3) + pub_r001224_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001224_12_1 * 2) + 48) & 63;
  int stage_v_40_2 = ((pub_r001224_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001224_1_1 * 2) + 31) & 63;
  int stage_v_41_2 = ((pub_r001224_1_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001224_3_1 * 2) + 16) & 63;
  int stage_v_42_2 = ((pub_r001224_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_10_1 * 3) + pub_r001224_16_1) + 13) & 127;
  int stage_v_43_2 = (((stage_v_10_2 * 3) + pub_r001224_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001224_2_1 * 3) + pub_r001224_12_1) + 19) & 127;
  int stage_v_44_2 = (((sec_r001224_2_2 * 3) + pub_r001224_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((helper_flow_4_1 * 3) + pub_r001224_5_1) + 32) & 127;
  int stage_v_45_2 = (((helper_flow_4_2 * 3) + pub_r001224_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_28_1 * 3) + pub_r001224_3_1) + 9) & 127;
  int stage_v_46_2 = (((stage_v_28_2 * 3) + pub_r001224_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001224_22_1 * 2) + 8) & 63;
  int stage_v_47_2 = ((pub_r001224_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001224_20_1 * 2) + 50) & 63;
  int stage_v_48_2 = ((pub_r001224_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001224_3_1 * 2) + 26) & 63;
  int stage_v_49_2 = ((pub_r001224_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001224_10_1 * 2) + 22) & 63;
  int stage_v_50_2 = ((pub_r001224_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001224_1_1 * 2) + 42) & 63;
  int stage_v_51_2 = ((pub_r001224_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((sec_r001224_13_1 * 3) + pub_r001224_21_1) + 29) & 127;
  int stage_v_52_2 = (((sec_r001224_13_2 * 3) + pub_r001224_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001224_17_1 * 2) + 17) & 63;
  int stage_v_53_2 = ((pub_r001224_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_28_1 * 3) + pub_r001224_10_1) + 21) & 127;
  int stage_v_54_2 = (((stage_v_28_2 * 3) + pub_r001224_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((helper_flow_3_1 * 3) + pub_r001224_2_1) + 17) & 127;
  int stage_v_55_2 = (((helper_flow_3_2 * 3) + pub_r001224_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001224_17_1 * 2) + 19) & 63;
  int stage_v_56_2 = ((pub_r001224_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001224_1_1 * 3) + pub_r001224_20_1) + 41) & 127;
  int stage_v_57_2 = (((sec_r001224_1_2 * 3) + pub_r001224_20_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((stage_v_54_1 * 3) + pub_r001224_10_1) + 27) & 127;
  int stage_v_58_2 = (((stage_v_54_2 * 3) + pub_r001224_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_24_1 * 3) + pub_r001224_14_1) + 26) & 127;
  int stage_v_59_2 = (((stage_v_24_2 * 3) + pub_r001224_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001224_1_1 * 2) + 43) & 63;
  int stage_v_60_2 = ((pub_r001224_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_3_1 * 3) + pub_r001224_6_1) + 24) & 127;
  int stage_v_61_2 = (((stage_v_3_2 * 3) + pub_r001224_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((stage_v_6_1 * 3) + pub_r001224_17_1) + 44) & 127;
  int stage_v_62_2 = (((stage_v_6_2 * 3) + pub_r001224_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_15_1 * 3) + pub_r001224_16_1) + 9) & 127;
  int stage_v_63_2 = (((stage_v_15_2 * 3) + pub_r001224_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001224_18_1 * 2) + 43) & 63;
  int stage_v_64_2 = ((pub_r001224_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((helper_flow_6_1 * 3) + pub_r001224_22_1) + 28) & 127;
  int stage_v_65_2 = (((helper_flow_6_2 * 3) + pub_r001224_22_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((helper_flow_1_1 * 3) + pub_r001224_23_1) + 36) & 127;
  int stage_v_66_2 = (((helper_flow_1_2 * 3) + pub_r001224_23_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((stage_v_3_1 * 3) + pub_r001224_12_1) + 42) & 127;
  int stage_v_67_2 = (((stage_v_3_2 * 3) + pub_r001224_12_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001224_3_1 * 2) + 42) & 63;
  int stage_v_68_2 = ((pub_r001224_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_39_1 * 3) + pub_r001224_15_1) + 29) & 127;
  int stage_v_69_2 = (((stage_v_39_2 * 3) + pub_r001224_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001224_0_1 * 2) + 10) & 63;
  int stage_v_70_2 = ((pub_r001224_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001224_3_1 * 2) + 7) & 63;
  int stage_v_71_2 = ((pub_r001224_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001224_2_1 * 2) + 31) & 63;
  int stage_v_72_2 = ((pub_r001224_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_67_1 * 3) + pub_r001224_8_1) + 3) & 127;
  int stage_v_73_2 = (((stage_v_67_2 * 3) + pub_r001224_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001224_0_1 * 2) + 40) & 63;
  int stage_v_74_2 = ((pub_r001224_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((helper_flow_1_1 * 3) + pub_r001224_10_1) + 37) & 127;
  int stage_v_75_2 = (((helper_flow_1_2 * 3) + pub_r001224_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001224_13_1 * 2) + 11) & 63;
  int stage_v_76_2 = ((pub_r001224_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001224_14_1 * 2) + 36) & 63;
  int stage_v_77_2 = ((pub_r001224_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001224_18_1 * 2) + 12) & 63;
  int stage_v_78_2 = ((pub_r001224_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001224_19_1 * 2) + 27) & 63;
  int stage_v_79_2 = ((pub_r001224_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001224_4_1 * 2) + 36) & 63;
  int stage_v_80_2 = ((pub_r001224_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_33_1 * 3) + pub_r001224_0_1) + 27) & 127;
  int stage_v_81_2 = (((stage_v_33_2 * 3) + pub_r001224_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_59_1 * 3) + pub_r001224_7_1) + 17) & 127;
  int stage_v_82_2 = (((stage_v_59_2 * 3) + pub_r001224_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((sec_r001224_6_1 * 3) + pub_r001224_8_1) + 29) & 127;
  int stage_v_83_2 = (((sec_r001224_6_2 * 3) + pub_r001224_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001224_8_1 * 2) + 32) & 63;
  int stage_v_84_2 = ((pub_r001224_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001224_8_1 * 2) + 49) & 63;
  int stage_v_85_2 = ((pub_r001224_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((helper_flow_6_1 * 3) + pub_r001224_16_1) + 26) & 127;
  int stage_v_86_2 = (((helper_flow_6_2 * 3) + pub_r001224_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((stage_v_17_1 * 3) + pub_r001224_8_1) + 38) & 127;
  int stage_v_87_2 = (((stage_v_17_2 * 3) + pub_r001224_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((sec_r001224_1_1 * 3) + pub_r001224_4_1) + 32) & 127;
  int stage_v_88_2 = (((sec_r001224_1_2 * 3) + pub_r001224_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001224_23_1 * 2) + 18) & 63;
  int stage_v_89_2 = ((pub_r001224_23_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_45_1 * 3) + pub_r001224_20_1) + 22) & 127;
  int stage_v_90_2 = (((stage_v_45_2 * 3) + pub_r001224_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_83_1 * 3) + pub_r001224_3_1) + 22) & 127;
  int stage_v_91_2 = (((stage_v_83_2 * 3) + pub_r001224_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001224_18_1 * 2) + 28) & 63;
  int stage_v_92_2 = ((pub_r001224_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001224_22_1 * 2) + 42) & 63;
  int stage_v_93_2 = ((pub_r001224_22_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001224_15_1 * 2) + 5) & 63;
  int stage_v_94_2 = ((pub_r001224_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_18_1 * 3) + pub_r001224_9_1) + 20) & 127;
  int stage_v_95_2 = (((stage_v_18_2 * 3) + pub_r001224_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001224_8_1 * 2) + 14) & 63;
  int stage_v_96_2 = ((pub_r001224_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((helper_flow_4_1 * 3) + pub_r001224_12_1) + 45) & 127;
  int stage_v_97_2 = (((helper_flow_4_2 * 3) + pub_r001224_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001224_7_1 * 2) + 41) & 63;
  int stage_v_98_2 = ((pub_r001224_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001224_3_1 * 2) + 12) & 63;
  int stage_v_99_2 = ((pub_r001224_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (((stage_v_59_1 * 3) + pub_r001224_23_1) + 37) & 127;
  int stage_v_100_2 = (((stage_v_59_2 * 3) + pub_r001224_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_52_1 * 3) + pub_r001224_14_1) + 34) & 127;
  int stage_v_101_2 = (((stage_v_52_2 * 3) + pub_r001224_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((helper_flow_0_1 * 3) + pub_r001224_13_1) + 35) & 127;
  int stage_v_102_2 = (((helper_flow_0_2 * 3) + pub_r001224_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_90_1 * 3) + pub_r001224_4_1) + 30) & 127;
  int stage_v_103_2 = (((stage_v_90_2 * 3) + pub_r001224_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_82_1 * 3) + pub_r001224_23_1) + 17) & 127;
  int stage_v_104_2 = (((stage_v_82_2 * 3) + pub_r001224_23_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001224_7_1 * 2) + 39) & 63;
  int stage_v_105_2 = ((pub_r001224_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001224_15_1 * 3) + pub_r001224_2_1) + 20) & 127;
  int stage_v_106_2 = (((sec_r001224_15_2 * 3) + pub_r001224_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((stage_v_8_1 * 3) + pub_r001224_17_1) + 43) & 127;
  int stage_v_107_2 = (((stage_v_8_2 * 3) + pub_r001224_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_65_1 * 3) + pub_r001224_23_1) + 42) & 127;
  int stage_v_108_2 = (((stage_v_65_2 * 3) + pub_r001224_23_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_63_1 * 3) + pub_r001224_16_1) + 9) & 127;
  int stage_v_109_2 = (((stage_v_63_2 * 3) + pub_r001224_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001224_3_1 * 2) + 23) & 63;
  int stage_v_110_2 = ((pub_r001224_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001224_14_1 * 2) + 23) & 63;
  int stage_v_111_2 = ((pub_r001224_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001224_14_1 * 2) + 44) & 63;
  int stage_v_112_2 = ((pub_r001224_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((helper_flow_5_1 * 3) + pub_r001224_15_1) + 20) & 127;
  int stage_v_113_2 = (((helper_flow_5_2 * 3) + pub_r001224_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_97_1 * 3) + pub_r001224_13_1) + 7) & 127;
  int stage_v_114_2 = (((stage_v_97_2 * 3) + pub_r001224_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001224_15_1 * 2) + 34) & 63;
  int stage_v_115_2 = ((pub_r001224_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_91_1 * 3) + pub_r001224_23_1) + 41) & 127;
  int stage_v_116_2 = (((stage_v_91_2 * 3) + pub_r001224_23_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001224_7_1 * 2) + 25) & 63;
  int stage_v_117_2 = ((pub_r001224_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001224_16_1 * 2) + 18) & 63;
  int stage_v_118_2 = ((pub_r001224_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001224_6_1 * 2) + 48) & 63;
  int stage_v_119_2 = ((pub_r001224_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_104_1 * 3) + pub_r001224_10_1) + 40) & 127;
  int stage_v_120_2 = (((stage_v_104_2 * 3) + pub_r001224_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_62_1 * 3) + pub_r001224_1_1) + 18) & 127;
  int stage_v_121_2 = (((stage_v_62_2 * 3) + pub_r001224_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_86_1 * 3) + pub_r001224_17_1) + 34) & 127;
  int stage_v_122_2 = (((stage_v_86_2 * 3) + pub_r001224_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((sec_r001224_15_1 * 3) + pub_r001224_22_1) + 32) & 127;
  int stage_v_123_2 = (((sec_r001224_15_2 * 3) + pub_r001224_22_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001224_9_1 * 2) + 31) & 63;
  int stage_v_124_2 = ((pub_r001224_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_43_1 * 3) + pub_r001224_23_1) + 37) & 127;
  int stage_v_125_2 = (((stage_v_43_2 * 3) + pub_r001224_23_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001224_17_1 * 2) + 28) & 63;
  int stage_v_126_2 = ((pub_r001224_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = (((stage_v_101_1 * 3) + pub_r001224_9_1) + 10) & 127;
  int stage_v_127_2 = (((stage_v_101_2 * 3) + pub_r001224_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_75_1 * 3) + pub_r001224_10_1) + 6) & 127;
  int stage_v_128_2 = (((stage_v_75_2 * 3) + pub_r001224_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((sec_r001224_15_1 * 3) + pub_r001224_22_1) + 11) & 127;
  int stage_v_129_2 = (((sec_r001224_15_2 * 3) + pub_r001224_22_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001224_4_1 * 2) + 14) & 63;
  int stage_v_130_2 = ((pub_r001224_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_127_1 * 3) + pub_r001224_17_1) + 19) & 127;
  int stage_v_131_2 = (((stage_v_127_2 * 3) + pub_r001224_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((stage_v_129_1 * 3) + pub_r001224_1_1) + 19) & 127;
  int stage_v_132_2 = (((stage_v_129_2 * 3) + pub_r001224_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001224_23_1 * 2) + 29) & 63;
  int stage_v_133_2 = ((pub_r001224_23_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001224_18_1 * 2) + 35) & 63;
  int stage_v_134_2 = ((pub_r001224_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001224_0_1 * 2) + 37) & 63;
  int stage_v_135_2 = ((pub_r001224_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((sec_r001224_2_1 * 3) + pub_r001224_6_1) + 9) & 127;
  int stage_v_136_2 = (((sec_r001224_2_2 * 3) + pub_r001224_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_75_1 * 3) + pub_r001224_22_1) + 31) & 127;
  int stage_v_137_2 = (((stage_v_75_2 * 3) + pub_r001224_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_103_1 * 3) + pub_r001224_7_1) + 21) & 127;
  int stage_v_138_2 = (((stage_v_103_2 * 3) + pub_r001224_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_90_1 * 3) + pub_r001224_4_1) + 18) & 127;
  int stage_v_139_2 = (((stage_v_90_2 * 3) + pub_r001224_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_132_1 * 3) + pub_r001224_2_1) + 16) & 127;
  int stage_v_140_2 = (((stage_v_132_2 * 3) + pub_r001224_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((sec_r001224_13_1 * 3) + pub_r001224_2_1) + 41) & 127;
  int stage_v_141_2 = (((sec_r001224_13_2 * 3) + pub_r001224_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_106_1 * 3) + pub_r001224_13_1) + 44) & 127;
  int stage_v_142_2 = (((stage_v_106_2 * 3) + pub_r001224_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_106_1 * 3) + pub_r001224_6_1) + 36) & 127;
  int stage_v_143_2 = (((stage_v_106_2 * 3) + pub_r001224_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_129_1 * 3) + pub_r001224_17_1) + 15) & 127;
  int stage_v_144_2 = (((stage_v_129_2 * 3) + pub_r001224_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((helper_flow_0_1 * 3) + pub_r001224_13_1) + 18) & 127;
  int stage_v_145_2 = (((helper_flow_0_2 * 3) + pub_r001224_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001224_8_1 * 2) + 21) & 63;
  int stage_v_146_2 = ((pub_r001224_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001224_4_1 * 2) + 11) & 63;
  int stage_v_147_2 = ((pub_r001224_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_63_1 * 3) + pub_r001224_0_1) + 43) & 127;
  int stage_v_148_2 = (((stage_v_63_2 * 3) + pub_r001224_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001224_5_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001224_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_15_1 * 3) + pub_r001224_13_1) + 15) & 127;
  int stage_v_150_2 = (((stage_v_15_2 * 3) + pub_r001224_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001224_10_1 * 2) + 17) & 63;
  int stage_v_151_2 = ((pub_r001224_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001224_13_1 * 2) + 8) & 63;
  int stage_v_152_2 = ((pub_r001224_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001224_12_1 * 2) + 25) & 63;
  int stage_v_153_2 = ((pub_r001224_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((stage_v_121_1 * 3) + pub_r001224_15_1) + 23) & 127;
  int stage_v_154_2 = (((stage_v_121_2 * 3) + pub_r001224_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001224_15_1 * 2) + 23) & 63;
  int stage_v_155_2 = ((pub_r001224_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001224_11_1 * 2) + 47) & 63;
  int stage_v_156_2 = ((pub_r001224_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001224_10_1 * 2) + 24) & 63;
  int stage_v_157_2 = ((pub_r001224_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((helper_flow_2_1 * 3) + pub_r001224_19_1) + 29) & 127;
  int stage_v_158_2 = (((helper_flow_2_2 * 3) + pub_r001224_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001224_9_1 * 2) + 11) & 63;
  int stage_v_159_2 = ((pub_r001224_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((sec_r001224_15_1 * 3) + pub_r001224_0_1) + 43) & 127;
  int stage_v_160_2 = (((sec_r001224_15_2 * 3) + pub_r001224_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001224_5_1 * 2) + 35) & 63;
  int stage_v_161_2 = ((pub_r001224_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_101_1 * 3) + pub_r001224_14_1) + 14) & 127;
  int stage_v_162_2 = (((stage_v_101_2 * 3) + pub_r001224_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001224_15_1 * 2) + 40) & 63;
  int stage_v_163_2 = ((pub_r001224_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((sec_r001224_0_1 * 3) + pub_r001224_18_1) + 44) & 127;
  int stage_v_164_2 = (((sec_r001224_0_2 * 3) + pub_r001224_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001224_14_1 * 2) + 46) & 63;
  int stage_v_165_2 = ((pub_r001224_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001224_22_1 * 2) + 14) & 63;
  int stage_v_166_2 = ((pub_r001224_22_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001224_11_1 * 2) + 31) & 63;
  int stage_v_167_2 = ((pub_r001224_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_67_1 * 3) + pub_r001224_20_1) + 24) & 127;
  int stage_v_168_2 = (((stage_v_67_2 * 3) + pub_r001224_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001224_12_1 * 2) + 34) & 63;
  int stage_v_169_2 = ((pub_r001224_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001224_8_1 * 2) + 6) & 63;
  int stage_v_170_2 = ((pub_r001224_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_142_1 * 3) + pub_r001224_21_1) + 43) & 127;
  int stage_v_171_2 = (((stage_v_142_2 * 3) + pub_r001224_21_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_9_1 * 3) + pub_r001224_3_1) + 40) & 127;
  int stage_v_172_2 = (((stage_v_9_2 * 3) + pub_r001224_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_32_1 * 3) + pub_r001224_11_1) + 17) & 127;
  int stage_v_173_2 = (((stage_v_32_2 * 3) + pub_r001224_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_66_1 * 3) + pub_r001224_9_1) + 24) & 127;
  int stage_v_174_2 = (((stage_v_66_2 * 3) + pub_r001224_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001224_8_1 * 2) + 26) & 63;
  int stage_v_175_2 = ((pub_r001224_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_127_1 * 3) + pub_r001224_4_1) + 3) & 127;
  int stage_v_176_2 = (((stage_v_127_2 * 3) + pub_r001224_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001224_7_1 * 2) + 50) & 63;
  int stage_v_177_2 = ((pub_r001224_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_46_1 * 3) + pub_r001224_19_1) + 10) & 127;
  int stage_v_178_2 = (((stage_v_46_2 * 3) + pub_r001224_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001224_13_1 * 2) + 48) & 63;
  int stage_v_179_2 = ((pub_r001224_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001224_10_1 * 2) + 22) & 63;
  int stage_v_180_2 = ((pub_r001224_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001224_5_1 * 2) + 15) & 63;
  int stage_v_181_2 = ((pub_r001224_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001224_11_1 * 2) + 12) & 63;
  int stage_v_182_2 = ((pub_r001224_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_129_1 * 3) + pub_r001224_15_1) + 18) & 127;
  int stage_v_183_2 = (((stage_v_129_2 * 3) + pub_r001224_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001224_4_1 * 2) + 18) & 63;
  int stage_v_184_2 = ((pub_r001224_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_106_1 * 3) + pub_r001224_9_1) + 19) & 127;
  int stage_v_185_2 = (((stage_v_106_2 * 3) + pub_r001224_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001224_18_1 * 2) + 25) & 63;
  int stage_v_186_2 = ((pub_r001224_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_6_1 * 3) + pub_r001224_17_1) + 41) & 127;
  int stage_v_187_2 = (((stage_v_6_2 * 3) + pub_r001224_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_57_1 * 3) + pub_r001224_19_1) + 28) & 127;
  int stage_v_188_2 = (((stage_v_57_2 * 3) + pub_r001224_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001224_12_1 * 2) + 10) & 63;
  int stage_v_189_2 = ((pub_r001224_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((sec_r001224_6_1 * 3) + pub_r001224_3_1) + 16) & 127;
  int stage_v_190_2 = (((sec_r001224_6_2 * 3) + pub_r001224_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001224_5_1 * 2) + 17) & 63;
  int stage_v_191_2 = ((pub_r001224_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_86_1 * 3) + pub_r001224_19_1) + 45) & 127;
  int stage_v_192_2 = (((stage_v_86_2 * 3) + pub_r001224_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_37_1 * 3) + pub_r001224_0_1) + 16) & 127;
  int stage_v_193_2 = (((stage_v_37_2 * 3) + pub_r001224_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((stage_v_23_1 * 3) + pub_r001224_12_1) + 19) & 127;
  int stage_v_194_2 = (((stage_v_23_2 * 3) + pub_r001224_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001224_12_1 * 2) + 32) & 63;
  int stage_v_195_2 = ((pub_r001224_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_87_1 * 3) + pub_r001224_9_1) + 8) & 127;
  int stage_v_196_2 = (((stage_v_87_2 * 3) + pub_r001224_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001224_7_1 * 2) + 24) & 63;
  int stage_v_197_2 = ((pub_r001224_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_7_1 * 3) + pub_r001224_8_1) + 6) & 127;
  int stage_v_198_2 = (((stage_v_7_2 * 3) + pub_r001224_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((sec_r001224_11_1 * 3) + pub_r001224_15_1) + 14) & 127;
  int stage_v_199_2 = (((sec_r001224_11_2 * 3) + pub_r001224_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001224_7_1 * 2) + 24) & 63;
  int stage_v_200_2 = ((pub_r001224_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001224_3_1 * 2) + 25) & 63;
  int stage_v_201_2 = ((pub_r001224_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001224_1_1 * 2) + 8) & 63;
  int stage_v_202_2 = ((pub_r001224_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((sec_r001224_8_1 * 3) + pub_r001224_20_1) + 20) & 127;
  int stage_v_203_2 = (((sec_r001224_8_2 * 3) + pub_r001224_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_32_1 * 3) + pub_r001224_13_1) + 42) & 127;
  int stage_v_204_2 = (((stage_v_32_2 * 3) + pub_r001224_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001224_1_1 * 2) + 33) & 63;
  int stage_v_205_2 = ((pub_r001224_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001224_11_1 * 2) + 13) & 63;
  int stage_v_206_2 = ((pub_r001224_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_160_1 * 3) + pub_r001224_16_1) + 27) & 127;
  int stage_v_207_2 = (((stage_v_160_2 * 3) + pub_r001224_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001224_19_1 * 2) + 16) & 63;
  int stage_v_208_2 = ((pub_r001224_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_13_1 * 3) + pub_r001224_11_1) + 34) & 127;
  int stage_v_209_2 = (((stage_v_13_2 * 3) + pub_r001224_11_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_44_1 * 3) + pub_r001224_7_1) + 43) & 127;
  int stage_v_210_2 = (((stage_v_44_2 * 3) + pub_r001224_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_38_1 * 3) + pub_r001224_5_1) + 38) & 127;
  int stage_v_211_2 = (((stage_v_38_2 * 3) + pub_r001224_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001224_7_1 * 2) + 23) & 63;
  int stage_v_212_2 = ((pub_r001224_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((helper_flow_3_1 * 3) + pub_r001224_16_1) + 37) & 127;
  int stage_v_213_2 = (((helper_flow_3_2 * 3) + pub_r001224_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001224_11_1 * 2) + 10) & 63;
  int stage_v_214_2 = ((pub_r001224_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_57_1 * 3) + pub_r001224_16_1) + 3) & 127;
  int stage_v_215_2 = (((stage_v_57_2 * 3) + pub_r001224_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001224_18_1 * 2) + 11) & 63;
  int stage_v_216_2 = ((pub_r001224_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((helper_flow_3_1 * 3) + pub_r001224_13_1) + 7) & 127;
  int stage_v_217_2 = (((helper_flow_3_2 * 3) + pub_r001224_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001224_8_1 * 2) + 7) & 63;
  int stage_v_218_2 = ((pub_r001224_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001224_5_1 * 2) + 5) & 63;
  int stage_v_219_2 = ((pub_r001224_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001224_20_1 * 2) + 32) & 63;
  int stage_v_220_2 = ((pub_r001224_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = (((stage_v_44_1 * 3) + pub_r001224_13_1) + 32) & 127;
  int stage_v_221_2 = (((stage_v_44_2 * 3) + pub_r001224_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_62_1 * 3) + pub_r001224_11_1) + 9) & 127;
  int stage_v_222_2 = (((stage_v_62_2 * 3) + pub_r001224_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001224_23_1 * 2) + 13) & 63;
  int stage_v_223_2 = ((pub_r001224_23_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((sec_r001224_13_1 * 3) + pub_r001224_1_1) + 5) & 127;
  int stage_v_224_2 = (((sec_r001224_13_2 * 3) + pub_r001224_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((stage_v_88_1 * 3) + pub_r001224_1_1) + 9) & 127;
  int stage_v_225_2 = (((stage_v_88_2 * 3) + pub_r001224_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = ((pub_r001224_7_1 * 2) + 22) & 63;
  int stage_v_226_2 = ((pub_r001224_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_185_1 * 3) + pub_r001224_4_1) + 32) & 127;
  int stage_v_227_2 = (((stage_v_185_2 * 3) + pub_r001224_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_141_1 * 3) + pub_r001224_13_1) + 37) & 127;
  int stage_v_228_2 = (((stage_v_141_2 * 3) + pub_r001224_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001224_2_1 * 2) + 47) & 63;
  int stage_v_229_2 = ((pub_r001224_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001224_20_1 * 2) + 50) & 63;
  int stage_v_230_2 = ((pub_r001224_20_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001224_0_1 * 2) + 27) & 63;
  int stage_v_231_2 = ((pub_r001224_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_183_1 * 3) + pub_r001224_22_1) + 6) & 127;
  int stage_v_232_2 = (((stage_v_183_2 * 3) + pub_r001224_22_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_82_1 * 3) + pub_r001224_17_1) + 43) & 127;
  int stage_v_233_2 = (((stage_v_82_2 * 3) + pub_r001224_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_90_1 * 3) + pub_r001224_18_1) + 34) & 127;
  int stage_v_234_2 = (((stage_v_90_2 * 3) + pub_r001224_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_86_1 * 3) + pub_r001224_19_1) + 9) & 127;
  int stage_v_235_2 = (((stage_v_86_2 * 3) + pub_r001224_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_142_1 * 3) + pub_r001224_7_1) + 10) & 127;
  int stage_v_236_2 = (((stage_v_142_2 * 3) + pub_r001224_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_88_1 * 3) + pub_r001224_9_1) + 37) & 127;
  int stage_v_237_2 = (((stage_v_88_2 * 3) + pub_r001224_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001224_20_1 * 2) + 18) & 63;
  int stage_v_238_2 = ((pub_r001224_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((stage_v_87_1 * 3) + pub_r001224_19_1) + 19) & 127;
  int stage_v_239_2 = (((stage_v_87_2 * 3) + pub_r001224_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001224_8_1 * 2) + 49) & 63;
  int stage_v_240_2 = ((pub_r001224_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001224_12_1 * 2) + 42) & 63;
  int stage_v_241_2 = ((pub_r001224_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_82_1 * 3) + pub_r001224_20_1) + 27) & 127;
  int stage_v_242_2 = (((stage_v_82_2 * 3) + pub_r001224_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_44_1 * 3) + pub_r001224_6_1) + 9) & 127;
  int stage_v_243_2 = (((stage_v_44_2 * 3) + pub_r001224_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001224_11_1 * 2) + 28) & 63;
  int stage_v_244_2 = ((pub_r001224_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((helper_flow_6_1 * 3) + pub_r001224_16_1) + 35) & 127;
  int stage_v_245_2 = (((helper_flow_6_2 * 3) + pub_r001224_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001224_16_1 * 2) + 43) & 63;
  int stage_v_246_2 = ((pub_r001224_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((helper_flow_1_1 * 3) + pub_r001224_15_1) + 27) & 127;
  int stage_v_247_2 = (((helper_flow_1_2 * 3) + pub_r001224_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001224_10_1 * 2) + 25) & 63;
  int stage_v_248_2 = ((pub_r001224_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((stage_v_81_1 * 3) + pub_r001224_3_1) + 31) & 127;
  int stage_v_249_2 = (((stage_v_81_2 * 3) + pub_r001224_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_55_1 * 3) + pub_r001224_4_1) + 9) & 127;
  int stage_v_250_2 = (((stage_v_55_2 * 3) + pub_r001224_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_26_1 * 3) + pub_r001224_11_1) + 10) & 127;
  int stage_v_251_2 = (((stage_v_26_2 * 3) + pub_r001224_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001224_18_1 * 2) + 25) & 63;
  int stage_v_252_2 = ((pub_r001224_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001224_11_1 * 2) + 32) & 63;
  int stage_v_253_2 = ((pub_r001224_11_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_63_1 * 3) + pub_r001224_5_1) + 27) & 127;
  int stage_v_254_2 = (((stage_v_63_2 * 3) + pub_r001224_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_222_1 * 3) + pub_r001224_13_1) + 38) & 127;
  int stage_v_255_2 = (((stage_v_222_2 * 3) + pub_r001224_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_138_1 * 3) + pub_r001224_11_1) + 17) & 127;
  int stage_v_256_2 = (((stage_v_138_2 * 3) + pub_r001224_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((stage_v_132_1 * 3) + pub_r001224_3_1) + 24) & 127;
  int stage_v_257_2 = (((stage_v_132_2 * 3) + pub_r001224_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_62_1 * 3) + pub_r001224_23_1) + 30) & 127;
  int stage_v_258_2 = (((stage_v_62_2 * 3) + pub_r001224_23_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001224_18_1 * 2) + 36) & 63;
  int stage_v_259_2 = ((pub_r001224_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((helper_flow_3_1 * 3) + pub_r001224_23_1) + 40) & 127;
  int stage_v_260_2 = (((helper_flow_3_2 * 3) + pub_r001224_23_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_138_1 * 3) + pub_r001224_1_1) + 4) & 127;
  int stage_v_261_2 = (((stage_v_138_2 * 3) + pub_r001224_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001224_18_1 * 2) + 29) & 63;
  int stage_v_262_2 = ((pub_r001224_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001224_3_1 * 2) + 25) & 63;
  int stage_v_263_2 = ((pub_r001224_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((pub_r001224_13_1 * 2) + 8) & 63;
  int stage_v_264_2 = ((pub_r001224_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_196_1 * 3) + pub_r001224_3_1) + 9) & 127;
  int stage_v_265_2 = (((stage_v_196_2 * 3) + pub_r001224_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_217_1 * 3) + pub_r001224_9_1) + 38) & 127;
  int stage_v_266_2 = (((stage_v_217_2 * 3) + pub_r001224_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_250_1 * 3) + pub_r001224_3_1) + 25) & 127;
  int stage_v_267_2 = (((stage_v_250_2 * 3) + pub_r001224_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_97_1 * 3) + pub_r001224_18_1) + 6) & 127;
  int stage_v_268_2 = (((stage_v_97_2 * 3) + pub_r001224_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001224_10_1 * 2) + 18) & 63;
  int stage_v_269_2 = ((pub_r001224_10_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = (((stage_v_160_1 * 3) + pub_r001224_2_1) + 43) & 127;
  int stage_v_270_2 = (((stage_v_160_2 * 3) + pub_r001224_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_261_1 * 3) + pub_r001224_10_1) + 18) & 127;
  int stage_v_271_2 = (((stage_v_261_2 * 3) + pub_r001224_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((sec_r001224_12_1 * 3) + pub_r001224_2_1) + 33) & 127;
  int stage_v_272_2 = (((sec_r001224_12_2 * 3) + pub_r001224_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001224_16_1 * 2) + 7) & 63;
  int stage_v_273_2 = ((pub_r001224_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_24_1 * 3) + pub_r001224_23_1) + 22) & 127;
  int stage_v_274_2 = (((stage_v_24_2 * 3) + pub_r001224_23_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_270_1 * 3) + pub_r001224_9_1) + 12) & 127;
  int stage_v_275_2 = (((stage_v_270_2 * 3) + pub_r001224_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001224_20_1 * 2) + 28) & 63;
  int stage_v_276_2 = ((pub_r001224_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001224_9_1 * 2) + 17) & 63;
  int stage_v_277_2 = ((pub_r001224_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_233_1 * 3) + pub_r001224_19_1) + 36) & 127;
  int stage_v_278_2 = (((stage_v_233_2 * 3) + pub_r001224_19_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001224_23_1 * 2) + 35) & 63;
  int stage_v_279_2 = ((pub_r001224_23_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_83_1 * 3) + pub_r001224_3_1) + 21) & 127;
  int stage_v_280_2 = (((stage_v_83_2 * 3) + pub_r001224_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_250_1 * 3) + pub_r001224_1_1) + 37) & 127;
  int stage_v_281_2 = (((stage_v_250_2 * 3) + pub_r001224_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = (((stage_v_82_1 * 3) + pub_r001224_3_1) + 4) & 127;
  int stage_v_282_2 = (((stage_v_82_2 * 3) + pub_r001224_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((stage_v_261_1 * 3) + pub_r001224_17_1) + 37) & 127;
  int stage_v_283_2 = (((stage_v_261_2 * 3) + pub_r001224_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001224_21_1 * 2) + 15) & 63;
  int stage_v_284_2 = ((pub_r001224_21_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_87_1 * 3) + pub_r001224_7_1) + 38) & 127;
  int stage_v_285_2 = (((stage_v_87_2 * 3) + pub_r001224_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001224_13_1 * 2) + 37) & 63;
  int stage_v_286_2 = ((pub_r001224_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001224_16_1 * 2) + 24) & 63;
  int stage_v_287_2 = ((pub_r001224_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_145_1 * 3) + pub_r001224_20_1) + 41) & 127;
  int stage_v_288_2 = (((stage_v_145_2 * 3) + pub_r001224_20_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_123_1 * 3) + pub_r001224_8_1) + 29) & 127;
  int stage_v_289_2 = (((stage_v_123_2 * 3) + pub_r001224_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001224_18_1 * 2) + 17) & 63;
  int stage_v_290_2 = ((pub_r001224_18_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((sec_r001224_3_1 * 3) + pub_r001224_11_1) + 4) & 127;
  int stage_v_291_2 = (((sec_r001224_3_2 * 3) + pub_r001224_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_258_1 * 3) + pub_r001224_7_1) + 31) & 127;
  int stage_v_292_2 = (((stage_v_258_2 * 3) + pub_r001224_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_128_1 * 3) + pub_r001224_2_1) + 16) & 127;
  int stage_v_293_2 = (((stage_v_128_2 * 3) + pub_r001224_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_204_1 * 3) + pub_r001224_21_1) + 5) & 127;
  int stage_v_294_2 = (((stage_v_204_2 * 3) + pub_r001224_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_224_1 * 3) + pub_r001224_23_1) + 45) & 127;
  int stage_v_295_2 = (((stage_v_224_2 * 3) + pub_r001224_23_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001224_19_1 * 2) + 21) & 63;
  int stage_v_296_2 = ((pub_r001224_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001224_17_1 * 2) + 17) & 63;
  int stage_v_297_2 = ((pub_r001224_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_237_1 * 3) + pub_r001224_6_1) + 12) & 127;
  int stage_v_298_2 = (((stage_v_237_2 * 3) + pub_r001224_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001224_18_1 * 2) + 35) & 63;
  int stage_v_299_2 = ((pub_r001224_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001224_13_1 * 2) + 42) & 63;
  int stage_v_300_2 = ((pub_r001224_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001224_23_1 * 2) + 41) & 63;
  int stage_v_301_2 = ((pub_r001224_23_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_160_1 * 3) + pub_r001224_19_1) + 34) & 127;
  int stage_v_302_2 = (((stage_v_160_2 * 3) + pub_r001224_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_7_1 * 3) + pub_r001224_10_1) + 4) & 127;
  int stage_v_303_2 = (((stage_v_7_2 * 3) + pub_r001224_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001224_22_1 * 2) + 45) & 63;
  int stage_v_304_2 = ((pub_r001224_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001224_10_1 * 2) + 7) & 63;
  int stage_v_305_2 = ((pub_r001224_10_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_258_1 * 3) + pub_r001224_22_1) + 19) & 127;
  int stage_v_306_2 = (((stage_v_258_2 * 3) + pub_r001224_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001224_10_1 * 2) + 41) & 63;
  int stage_v_307_2 = ((pub_r001224_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001224_9_1 * 2) + 19) & 63;
  int stage_v_308_2 = ((pub_r001224_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001224_19_1 * 2) + 15) & 63;
  int stage_v_309_2 = ((pub_r001224_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_198_1 * 3) + pub_r001224_15_1) + 28) & 127;
  int stage_v_310_2 = (((stage_v_198_2 * 3) + pub_r001224_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_67_1 * 3) + pub_r001224_19_1) + 14) & 127;
  int stage_v_311_2 = (((stage_v_67_2 * 3) + pub_r001224_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001224_4_1 * 2) + 43) & 63;
  int stage_v_312_2 = ((pub_r001224_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_44_1 * 3) + pub_r001224_10_1) + 32) & 127;
  int stage_v_313_2 = (((stage_v_44_2 * 3) + pub_r001224_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001224_23_1 * 2) + 19) & 63;
  int stage_v_314_2 = ((pub_r001224_23_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001224_16_1 * 2) + 8) & 63;
  int stage_v_315_2 = ((pub_r001224_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_6_1 * 3) + pub_r001224_19_1) + 37) & 127;
  int stage_v_316_2 = (((stage_v_6_2 * 3) + pub_r001224_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((sec_r001224_0_1 * 3) + pub_r001224_16_1) + 9) & 127;
  int stage_v_317_2 = (((sec_r001224_0_2 * 3) + pub_r001224_16_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = (((stage_v_207_1 * 3) + pub_r001224_8_1) + 43) & 127;
  int stage_v_318_2 = (((stage_v_207_2 * 3) + pub_r001224_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_271_1 * 3) + pub_r001224_0_1) + 16) & 127;
  int stage_v_319_2 = (((stage_v_271_2 * 3) + pub_r001224_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_316_1 * 3) + pub_r001224_4_1) + 10) & 127;
  int stage_v_320_2 = (((stage_v_316_2 * 3) + pub_r001224_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001224_13_1 * 2) + 22) & 63;
  int stage_v_321_2 = ((pub_r001224_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001224_10_1 * 2) + 28) & 63;
  int stage_v_322_2 = ((pub_r001224_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_183_1 * 3) + pub_r001224_6_1) + 29) & 127;
  int stage_v_323_2 = (((stage_v_183_2 * 3) + pub_r001224_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001224_14_1 * 2) + 50) & 63;
  int stage_v_324_2 = ((pub_r001224_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_141_1 * 3) + pub_r001224_4_1) + 36) & 127;
  int stage_v_325_2 = (((stage_v_141_2 * 3) + pub_r001224_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_43_1 * 3) + pub_r001224_3_1) + 21) & 127;
  int stage_v_326_2 = (((stage_v_43_2 * 3) + pub_r001224_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((sec_r001224_8_1 * 3) + pub_r001224_17_1) + 24) & 127;
  int stage_v_327_2 = (((sec_r001224_8_2 * 3) + pub_r001224_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((sec_r001224_0_1 * 3) + pub_r001224_11_1) + 30) & 127;
  int stage_v_328_2 = (((sec_r001224_0_2 * 3) + pub_r001224_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = ((pub_r001224_20_1 * 2) + 43) & 63;
  int stage_v_329_2 = ((pub_r001224_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = (((stage_v_213_1 * 3) + pub_r001224_0_1) + 19) & 127;
  int stage_v_330_2 = (((stage_v_213_2 * 3) + pub_r001224_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001224_2_1 * 2) + 23) & 63;
  int stage_v_331_2 = ((pub_r001224_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_143_1 * 3) + pub_r001224_20_1) + 29) & 127;
  int stage_v_332_2 = (((stage_v_143_2 * 3) + pub_r001224_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001224_23_1 * 2) + 43) & 63;
  int stage_v_333_2 = ((pub_r001224_23_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_255_1 * 3) + pub_r001224_7_1) + 22) & 127;
  int stage_v_334_2 = (((stage_v_255_2 * 3) + pub_r001224_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001224_3_1 * 2) + 12) & 63;
  int stage_v_335_2 = ((pub_r001224_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_227_1 * 3) + pub_r001224_7_1) + 38) & 127;
  int stage_v_336_2 = (((stage_v_227_2 * 3) + pub_r001224_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_15_1 * 3) + pub_r001224_5_1) + 26) & 127;
  int stage_v_337_2 = (((stage_v_15_2 * 3) + pub_r001224_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001224_13_1 * 2) + 48) & 63;
  int stage_v_338_2 = ((pub_r001224_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_270_1 * 3) + pub_r001224_4_1) + 35) & 127;
  int stage_v_339_2 = (((stage_v_270_2 * 3) + pub_r001224_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_247_1 * 3) + pub_r001224_9_1) + 25) & 127;
  int stage_v_340_2 = (((stage_v_247_2 * 3) + pub_r001224_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_73_1 * 3) + pub_r001224_7_1) + 18) & 127;
  int stage_v_341_2 = (((stage_v_73_2 * 3) + pub_r001224_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001224_1_1 * 2) + 25) & 63;
  int stage_v_342_2 = ((pub_r001224_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001224_22_1 * 2) + 43) & 63;
  int stage_v_343_2 = ((pub_r001224_22_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_61_1 * 3) + pub_r001224_17_1) + 39) & 127;
  int stage_v_344_2 = (((stage_v_61_2 * 3) + pub_r001224_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001224_1_1 * 2) + 33) & 63;
  int stage_v_345_2 = ((pub_r001224_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_144_1 * 3) + pub_r001224_10_1) + 32) & 127;
  int stage_v_346_2 = (((stage_v_144_2 * 3) + pub_r001224_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001224_7_1 * 2) + 38) & 63;
  int stage_v_347_2 = ((pub_r001224_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_313_1 * 3) + pub_r001224_18_1) + 12) & 127;
  int stage_v_348_2 = (((stage_v_313_2 * 3) + pub_r001224_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_141_1 * 3) + pub_r001224_0_1) + 43) & 127;
  int stage_v_349_2 = (((stage_v_141_2 * 3) + pub_r001224_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_288_1 * 3) + pub_r001224_6_1) + 3) & 127;
  int stage_v_350_2 = (((stage_v_288_2 * 3) + pub_r001224_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001224_13_1 * 2) + 20) & 63;
  int stage_v_351_2 = ((pub_r001224_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((pub_r001224_14_1 * 2) + 6) & 63;
  int stage_v_352_2 = ((pub_r001224_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001224_14_1 * 2) + 16) & 63;
  int stage_v_353_2 = ((pub_r001224_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_87_1 * 3) + pub_r001224_6_1) + 40) & 127;
  int stage_v_354_2 = (((stage_v_87_2 * 3) + pub_r001224_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_340_1 * 3) + pub_r001224_6_1) + 15) & 127;
  int stage_v_355_2 = (((stage_v_340_2 * 3) + pub_r001224_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001224_6_1 * 2) + 16) & 63;
  int stage_v_356_2 = ((pub_r001224_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001224_12_1 * 2) + 6) & 63;
  int stage_v_357_2 = ((pub_r001224_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001224_19_1 * 2) + 42) & 63;
  int stage_v_358_2 = ((pub_r001224_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_61_1 * 3) + pub_r001224_11_1) + 7) & 127;
  int stage_v_359_2 = (((stage_v_61_2 * 3) + pub_r001224_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_254_1 * 3) + pub_r001224_23_1) + 21) & 127;
  int stage_v_360_2 = (((stage_v_254_2 * 3) + pub_r001224_23_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_233_1 * 3) + pub_r001224_9_1) + 6) & 127;
  int stage_v_361_2 = (((stage_v_233_2 * 3) + pub_r001224_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((sec_r001224_0_1 * 3) + pub_r001224_6_1) + 10) & 127;
  int stage_v_362_2 = (((sec_r001224_0_2 * 3) + pub_r001224_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_39_1 * 3) + pub_r001224_13_1) + 18) & 127;
  int stage_v_363_2 = (((stage_v_39_2 * 3) + pub_r001224_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_13_1 * 3) + pub_r001224_11_1) + 29) & 127;
  int stage_v_364_2 = (((stage_v_13_2 * 3) + pub_r001224_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_271_1 * 3) + pub_r001224_14_1) + 24) & 127;
  int stage_v_365_2 = (((stage_v_271_2 * 3) + pub_r001224_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_281_1 * 3) + pub_r001224_17_1) + 33) & 127;
  int stage_v_366_2 = (((stage_v_281_2 * 3) + pub_r001224_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_228_1 * 3) + pub_r001224_6_1) + 38) & 127;
  int stage_v_367_2 = (((stage_v_228_2 * 3) + pub_r001224_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001224_23_1 * 2) + 38) & 63;
  int stage_v_368_2 = ((pub_r001224_23_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001224_9_1 * 2) + 10) & 63;
  int stage_v_369_2 = ((pub_r001224_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_125_1 * 3) + pub_r001224_4_1) + 36) & 127;
  int stage_v_370_2 = (((stage_v_125_2 * 3) + pub_r001224_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((sec_r001224_5_1 * 3) + pub_r001224_1_1) + 6) & 127;
  int stage_v_371_2 = (((sec_r001224_5_2 * 3) + pub_r001224_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001224_8_1 * 2) + 28) & 63;
  int stage_v_372_2 = ((pub_r001224_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001224_12_1 * 2) + 37) & 63;
  int stage_v_373_2 = ((pub_r001224_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_52_1 * 3) + pub_r001224_8_1) + 3) & 127;
  int stage_v_374_2 = (((stage_v_52_2 * 3) + pub_r001224_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_121_1 * 3) + pub_r001224_22_1) + 5) & 127;
  int stage_v_375_2 = (((stage_v_121_2 * 3) + pub_r001224_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001224_10_1 * 2) + 44) & 63;
  int stage_v_376_2 = ((pub_r001224_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_3_1 * 3) + pub_r001224_10_1) + 29) & 127;
  int stage_v_377_2 = (((stage_v_3_2 * 3) + pub_r001224_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_319_1 * 3) + pub_r001224_21_1) + 5) & 127;
  int stage_v_378_2 = (((stage_v_319_2 * 3) + pub_r001224_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001224_3_1 * 2) + 26) & 63;
  int stage_v_379_2 = ((pub_r001224_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((helper_flow_0_1 * 3) + pub_r001224_21_1) + 10) & 127;
  int stage_v_380_2 = (((helper_flow_0_2 * 3) + pub_r001224_21_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = ((pub_r001224_7_1 * 2) + 12) & 63;
  int stage_v_381_2 = ((pub_r001224_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_210_1 * 3) + pub_r001224_22_1) + 41) & 127;
  int stage_v_382_2 = (((stage_v_210_2 * 3) + pub_r001224_22_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001224_3_1 * 2) + 25) & 63;
  int stage_v_383_2 = ((pub_r001224_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_293_1 * 3) + pub_r001224_0_1) + 17) & 127;
  int stage_v_384_2 = (((stage_v_293_2 * 3) + pub_r001224_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_16_1 * 3) + pub_r001224_23_1) + 20) & 127;
  int stage_v_385_2 = (((stage_v_16_2 * 3) + pub_r001224_23_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001224_5_1 * 2) + 19) & 63;
  int stage_v_386_2 = ((pub_r001224_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_228_1 * 3) + pub_r001224_8_1) + 23) & 127;
  int stage_v_387_2 = (((stage_v_228_2 * 3) + pub_r001224_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001224_16_1 * 2) + 42) & 63;
  int stage_v_388_2 = ((pub_r001224_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_102_1 * 3) + pub_r001224_1_1) + 21) & 127;
  int stage_v_389_2 = (((stage_v_102_2 * 3) + pub_r001224_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001224_11_1 * 2) + 24) & 63;
  int stage_v_390_2 = ((pub_r001224_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001224_20_1 * 2) + 39) & 63;
  int stage_v_391_2 = ((pub_r001224_20_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001224_18_1 * 2) + 35) & 63;
  int stage_v_392_2 = ((pub_r001224_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_318_1 * 3) + pub_r001224_19_1) + 24) & 127;
  int stage_v_393_2 = (((stage_v_318_2 * 3) + pub_r001224_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001224_16_1 * 2) + 15) & 63;
  int stage_v_394_2 = ((pub_r001224_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001224_22_1 * 2) + 6) & 63;
  int stage_v_395_2 = ((pub_r001224_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((sec_r001224_2_1 * 3) + pub_r001224_20_1) + 7) & 127;
  int stage_v_396_2 = (((sec_r001224_2_2 * 3) + pub_r001224_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001224_23_1 * 2) + 28) & 63;
  int stage_v_397_2 = ((pub_r001224_23_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001224_4_1 * 2) + 31) & 63;
  int stage_v_398_2 = ((pub_r001224_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001224_13_1 * 2) + 46) & 63;
  int stage_v_399_2 = ((pub_r001224_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_250_1 * 3) + pub_r001224_19_1) + 45) & 127;
  int stage_v_400_2 = (((stage_v_250_2 * 3) + pub_r001224_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001224_1_1 * 2) + 26) & 63;
  int stage_v_401_2 = ((pub_r001224_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((sec_r001224_10_1 * 3) + pub_r001224_23_1) + 42) & 127;
  int stage_v_402_2 = (((sec_r001224_10_2 * 3) + pub_r001224_23_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_254_1 * 3) + pub_r001224_16_1) + 5) & 127;
  int stage_v_403_2 = (((stage_v_254_2 * 3) + pub_r001224_16_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_90_1 * 3) + pub_r001224_3_1) + 27) & 127;
  int stage_v_404_2 = (((stage_v_90_2 * 3) + pub_r001224_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001224_17_1 * 2) + 44) & 63;
  int stage_v_405_2 = ((pub_r001224_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001224_5_1 * 2) + 13) & 63;
  int stage_v_406_2 = ((pub_r001224_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001224_8_1 * 2) + 13) & 63;
  int stage_v_407_2 = ((pub_r001224_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_374_1 * 3) + pub_r001224_11_1) + 19) & 127;
  int stage_v_408_2 = (((stage_v_374_2 * 3) + pub_r001224_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_364_1 * 3) + pub_r001224_10_1) + 16) & 127;
  int stage_v_409_2 = (((stage_v_364_2 * 3) + pub_r001224_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = (((stage_v_174_1 * 3) + pub_r001224_9_1) + 14) & 127;
  int stage_v_410_2 = (((stage_v_174_2 * 3) + pub_r001224_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = (((sec_r001224_0_1 * 3) + pub_r001224_22_1) + 24) & 127;
  int stage_v_411_2 = (((sec_r001224_0_2 * 3) + pub_r001224_22_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = (((stage_v_389_1 * 3) + pub_r001224_7_1) + 25) & 127;
  int stage_v_412_2 = (((stage_v_389_2 * 3) + pub_r001224_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001224_10_1 * 2) + 35) & 63;
  int stage_v_413_2 = ((pub_r001224_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001224_9_1 * 2) + 47) & 63;
  int stage_v_414_2 = ((pub_r001224_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001224_16_1 * 2) + 11) & 63;
  int stage_v_415_2 = ((pub_r001224_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001224_19_1 * 2) + 44) & 63;
  int stage_v_416_2 = ((pub_r001224_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001224_0_1 * 2) + 26) & 63;
  int stage_v_417_2 = ((pub_r001224_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = (((stage_v_122_1 * 3) + pub_r001224_1_1) + 7) & 127;
  int stage_v_418_2 = (((stage_v_122_2 * 3) + pub_r001224_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001224_13_1 * 2) + 38) & 63;
  int stage_v_419_2 = ((pub_r001224_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = ((pub_r001224_11_1 * 2) + 14) & 63;
  int stage_v_420_2 = ((pub_r001224_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_361_1 * 3) + pub_r001224_7_1) + 7) & 127;
  int stage_v_421_2 = (((stage_v_361_2 * 3) + pub_r001224_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((sec_r001224_12_1 * 3) + pub_r001224_8_1) + 25) & 127;
  int stage_v_422_2 = (((sec_r001224_12_2 * 3) + pub_r001224_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001224_7_1 * 2) + 30) & 63;
  int stage_v_423_2 = ((pub_r001224_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_57_1 * 3) + pub_r001224_16_1) + 6) & 127;
  int stage_v_424_2 = (((stage_v_57_2 * 3) + pub_r001224_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((stage_v_336_1 * 3) + pub_r001224_22_1) + 39) & 127;
  int stage_v_425_2 = (((stage_v_336_2 * 3) + pub_r001224_22_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = (((stage_v_224_1 * 3) + pub_r001224_17_1) + 39) & 127;
  int stage_v_426_2 = (((stage_v_224_2 * 3) + pub_r001224_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = ((pub_r001224_5_1 * 2) + 14) & 63;
  int stage_v_427_2 = ((pub_r001224_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = (((stage_v_254_1 * 3) + pub_r001224_20_1) + 43) & 127;
  int stage_v_428_2 = (((stage_v_254_2 * 3) + pub_r001224_20_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_91_1 * 3) + pub_r001224_14_1) + 35) & 127;
  int stage_v_429_2 = (((stage_v_91_2 * 3) + pub_r001224_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001224_20_1 * 2) + 15) & 63;
  int stage_v_430_2 = ((pub_r001224_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001224_23_1 * 2) + 13) & 63;
  int stage_v_431_2 = ((pub_r001224_23_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001224_15_1 * 2) + 12) & 63;
  int stage_v_432_2 = ((pub_r001224_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_422_1 * 3) + pub_r001224_10_1) + 41) & 127;
  int stage_v_433_2 = (((stage_v_422_2 * 3) + pub_r001224_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_251_1 * 3) + pub_r001224_11_1) + 31) & 127;
  int stage_v_434_2 = (((stage_v_251_2 * 3) + pub_r001224_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001224_18_1 * 2) + 9) & 63;
  int stage_v_435_2 = ((pub_r001224_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001224_7_1 * 2) + 40) & 63;
  int stage_v_436_2 = ((pub_r001224_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_101_1 * 3) + pub_r001224_3_1) + 31) & 127;
  int stage_v_437_2 = (((stage_v_101_2 * 3) + pub_r001224_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001224_17_1 * 2) + 32) & 63;
  int stage_v_438_2 = ((pub_r001224_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001224_10_1 * 2) + 38) & 63;
  int stage_v_439_2 = ((pub_r001224_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_266_1 * 3) + pub_r001224_8_1) + 45) & 127;
  int stage_v_440_2 = (((stage_v_266_2 * 3) + pub_r001224_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_190_1 * 3) + pub_r001224_18_1) + 30) & 127;
  int stage_v_441_2 = (((stage_v_190_2 * 3) + pub_r001224_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = ((pub_r001224_5_1 * 2) + 47) & 63;
  int stage_v_442_2 = ((pub_r001224_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001224_8_1 * 2) + 31) & 63;
  int stage_v_443_2 = ((pub_r001224_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = (((stage_v_207_1 * 3) + pub_r001224_23_1) + 7) & 127;
  int stage_v_444_2 = (((stage_v_207_2 * 3) + pub_r001224_23_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = (((stage_v_33_1 * 3) + pub_r001224_18_1) + 9) & 127;
  int stage_v_445_2 = (((stage_v_33_2 * 3) + pub_r001224_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((stage_v_158_1 * 3) + pub_r001224_16_1) + 42) & 127;
  int stage_v_446_2 = (((stage_v_158_2 * 3) + pub_r001224_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((sec_r001224_8_1 * 3) + pub_r001224_21_1) + 13) & 127;
  int stage_v_447_2 = (((sec_r001224_8_2 * 3) + pub_r001224_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001224_14_1 != sec_r001224_14_2);
  __CPROVER_assume(sec_r001224_6_1 != sec_r001224_6_2);
  __CPROVER_assume(pub_r001224_5_1 == pub_r001224_5_2);
  __CPROVER_assume(pub_r001224_14_1 == pub_r001224_14_2);
  __CPROVER_assume(pub_r001224_21_1 == pub_r001224_21_2);
  __CPROVER_assume(pub_r001224_22_1 == pub_r001224_22_2);
  __CPROVER_assume(pub_r001224_4_1 == pub_r001224_4_2);
  __CPROVER_assume(sec_r001224_16_1 != sec_r001224_16_2);
  __CPROVER_assume(sec_r001224_4_1 != sec_r001224_4_2);
  __CPROVER_assume(sec_r001224_3_1 != sec_r001224_3_2);
  __CPROVER_assume(pub_r001224_1_1 == pub_r001224_1_2);
  __CPROVER_assume(sec_r001224_1_1 != sec_r001224_1_2);
  __CPROVER_assume(sec_r001224_0_1 != sec_r001224_0_2);
  __CPROVER_assume(pub_r001224_13_1 == pub_r001224_13_2);
  __CPROVER_assume(pub_r001224_16_1 == pub_r001224_16_2);
  __CPROVER_assume(sec_r001224_15_1 != sec_r001224_15_2);
  __CPROVER_assume(pub_r001224_15_1 == pub_r001224_15_2);
  __CPROVER_assume(pub_r001224_18_1 == pub_r001224_18_2);
  __CPROVER_assume(pub_r001224_2_1 == pub_r001224_2_2);
  __CPROVER_assume(pub_r001224_9_1 == pub_r001224_9_2);
  __CPROVER_assume(sec_r001224_2_1 != sec_r001224_2_2);
  __CPROVER_assume(pub_r001224_7_1 == pub_r001224_7_2);
  __CPROVER_assume(pub_r001224_20_1 == pub_r001224_20_2);
  __CPROVER_assume(sec_r001224_9_1 != sec_r001224_9_2);
  __CPROVER_assume(sec_r001224_11_1 != sec_r001224_11_2);
  __CPROVER_assume(sec_r001224_5_1 != sec_r001224_5_2);
  __CPROVER_assume(pub_r001224_6_1 == pub_r001224_6_2);
  __CPROVER_assume(sec_r001224_7_1 != sec_r001224_7_2);
  __CPROVER_assume(pub_r001224_19_1 == pub_r001224_19_2);
  __CPROVER_assume(pub_r001224_23_1 == pub_r001224_23_2);
  __CPROVER_assume(sec_r001224_10_1 != sec_r001224_10_2);
  __CPROVER_assume(pub_r001224_17_1 == pub_r001224_17_2);
  __CPROVER_assume(pub_r001224_0_1 == pub_r001224_0_2);
  __CPROVER_assume(pub_r001224_10_1 == pub_r001224_10_2);
  __CPROVER_assume(pub_r001224_8_1 == pub_r001224_8_2);
  __CPROVER_assume(pub_r001224_11_1 == pub_r001224_11_2);
  __CPROVER_assume(pub_r001224_3_1 == pub_r001224_3_2);
  __CPROVER_assume(sec_r001224_8_1 != sec_r001224_8_2);
  __CPROVER_assume(pub_r001224_12_1 == pub_r001224_12_2);
  __CPROVER_assume(sec_r001224_13_1 != sec_r001224_13_2);
  __CPROVER_assume(sec_r001224_12_1 != sec_r001224_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.rms == st_var_0_2.rms);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.id == st_var_1_2.id);
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
}


