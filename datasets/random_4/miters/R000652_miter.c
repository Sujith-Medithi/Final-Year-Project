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
struct FilterState_R000652_5213_0
{
  int prev_out;
  int gain_db;
  int cutoff;
  int prev_in;
  short damping;
  int mode;
  int buffer[3];
};
struct AudioFrame_R000652_5213_1
{
  unsigned char rms;
  unsigned char envelope;
  unsigned char gain;
  short peak;
  unsigned char channels;
  int buffer[3];
};
struct DeviceConfig_R000652_5213_2
{
  unsigned char timeout;
  unsigned char baud_rate;
  int parity;
  int buffer[3];
};
union TelemetryField_R000652_5213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000652_5213_1
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
void fn_R000652_5213_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int index_reg_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_18_1 > 45)
  {
    acc_1 = ((acc_1 + (index_reg_18_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_18_2 > 45)
  {
    acc_2 = ((acc_2 + (index_reg_18_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_28_1 = local_arr_1[aux_1 % 3];
  int vector_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_28_2 * 2)) & 127;
  int phase_88_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_88_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_88_1)
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

  switch (phase_88_2)
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

  int sample_53_1 = 0;
  int sample_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_53_1 = ((sample_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_53_2 = ((sample_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_53_1) & 127;
    acc_2 = (acc_2 + sample_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_18_1 == index_reg_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_28_1 == vector_28_2);
  assert(phase_88_1 == phase_88_2);
  assert(sample_53_1 == sample_53_2);
}

int fn_R000652_5213_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int index_reg_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_18 > 45)
  {
    acc = ((acc + (index_reg_18 * 2)) + 5) & 127;
    aux ^= index_reg_18 & 15;
  }
  else
  {
    acc = ((acc - index_reg_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_28 = local_arr[aux % 3];
  acc = (acc + (vector_28 * 2)) & 127;
  int phase_88 = (aux + st.buffer[1]) & 3;
  switch (phase_88)
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

  int sample_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_53 = ((sample_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int anchor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_99_1 > 33)
  {
    acc_1 = ((acc_1 + (anchor_99_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_99_2 > 33)
  {
    acc_2 = ((acc_2 + (anchor_99_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_74_1) & 63;
  aux_2 = (aux_2 + tracker_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_39_1 = 0;
  int margin_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_39_1 = ((margin_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_39_2 = ((margin_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_39_1) & 127;
    acc_2 = (acc_2 + margin_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_99_1 == anchor_99_2);
  assert(tracker_74_1 == tracker_74_2);
  assert(margin_39_1 == margin_39_2);
}

int fn_R000652_5213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int anchor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_99 > 33)
  {
    acc = ((acc + (anchor_99 * 2)) + 5) & 127;
    aux ^= anchor_99 & 15;
  }
  else
  {
    acc = ((acc - anchor_99) + 11) & 127;
    aux += 3;
  }
  int tracker_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_74) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_39 = ((margin_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int factor_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_11_1)
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

  switch (factor_11_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_10_1 = local_arr_1[aux_1 % 3];
  int offset_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_10_2 * 2)) & 127;
  int scale_17_1 = 0;
  int scale_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_17_1 = ((scale_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_17_2 = ((scale_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_17_1) & 127;
    acc_2 = (acc_2 + scale_17_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_11_1 == factor_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_10_1 == offset_10_2);
  assert(scale_17_1 == scale_17_2);
}

int fn_R000652_5213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int factor_11 = (aux + st.buffer[1]) & 3;
  switch (factor_11)
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

  int local_arr[3] = {4, 9, 15};
  int offset_10 = local_arr[aux % 3];
  acc = (acc + (offset_10 * 2)) & 127;
  int scale_17 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_17 = ((scale_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_17) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int offset_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_44_1) & 63;
  aux_2 = (aux_2 + offset_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_64_1 = 0;
  int residue_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_64_1 = ((residue_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_64_2 = ((residue_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_64_1) & 127;
    acc_2 = (acc_2 + residue_64_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_25_1 = local_arr_1[aux_1 % 3];
  int metric_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_25_2 * 2)) & 127;
  int offset_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_97_1 > 18)
  {
    acc_1 = ((acc_1 + (offset_97_1 * 2)) + 5) & 127;
    aux_1 ^= offset_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_97_2 > 18)
  {
    acc_2 = ((acc_2 + (offset_97_2 * 2)) + 5) & 127;
    aux_2 ^= offset_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_97_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_44_1 == offset_44_2);
  assert(residue_64_1 == residue_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_25_1 == metric_25_2);
  assert(offset_97_1 == offset_97_2);
}

int fn_R000652_5213_3(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int offset_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_44) & 63;
  acc ^= aux;
  int residue_64 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_64 = ((residue_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_64) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_25 = local_arr[aux % 3];
  acc = (acc + (metric_25 * 2)) & 127;
  int offset_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_97 > 18)
  {
    acc = ((acc + (offset_97 * 2)) + 5) & 127;
    aux ^= offset_97 & 15;
  }
  else
  {
    acc = ((acc - offset_97) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int checksum_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_72_1)
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

  switch (checksum_72_2)
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

  int residue_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_96_1 > 45)
  {
    acc_1 = ((acc_1 + (residue_96_1 * 2)) + 5) & 127;
    aux_1 ^= residue_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_96_2 > 45)
  {
    acc_2 = ((acc_2 + (residue_96_2 * 2)) + 5) & 127;
    aux_2 ^= residue_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_96_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_72_1 == checksum_72_2);
  assert(residue_96_1 == residue_96_2);
}

int fn_R000652_5213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int checksum_72 = (aux + st.buffer[1]) & 3;
  switch (checksum_72)
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

  int residue_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_96 > 45)
  {
    acc = ((acc + (residue_96 * 2)) + 5) & 127;
    aux ^= residue_96 & 15;
  }
  else
  {
    acc = ((acc - residue_96) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_31_1 = local_arr_1[aux_1 % 3];
  int offset_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_31_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_31_1 == offset_31_2);
}

int fn_R000652_5213_5(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int offset_31 = local_arr[aux % 3];
  acc = (acc + (offset_31 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_65_1 > 46)
  {
    acc_1 = ((acc_1 + (tally_65_1 * 2)) + 5) & 127;
    aux_1 ^= tally_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_65_2 > 46)
  {
    acc_2 = ((acc_2 + (tally_65_2 * 2)) + 5) & 127;
    aux_2 ^= tally_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_81_1 = 0;
  int weight_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_81_1 = ((weight_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_81_2 = ((weight_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_81_1) & 127;
    acc_2 = (acc_2 + weight_81_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_28_1 = local_arr_1[aux_1 % 3];
  int tally_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_65_1 == tally_65_2);
  assert(weight_81_1 == weight_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_28_1 == tally_28_2);
}

int fn_R000652_5213_6(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_65 > 46)
  {
    acc = ((acc + (tally_65 * 2)) + 5) & 127;
    aux ^= tally_65 & 15;
  }
  else
  {
    acc = ((acc - tally_65) + 11) & 127;
    aux += 3;
  }
  int weight_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_81 = ((weight_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_81) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_28 = local_arr[aux % 3];
  acc = (acc + (tally_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int margin_20_1 = 0;
  int margin_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_20_1 = ((margin_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_20_2 = ((margin_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_20_1) & 127;
    acc_2 = (acc_2 + margin_20_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_17_1 = local_arr_1[aux_1 % 3];
  int cursor_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_17_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_20_1 == margin_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_17_1 == cursor_17_2);
}

int fn_R000652_5213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int margin_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_20 = ((margin_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_20) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int cursor_17 = local_arr[aux % 3];
  acc = (acc + (cursor_17 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int tracker_81_1 = 0;
  int tracker_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_81_1 = ((tracker_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_81_2 = ((tracker_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_81_1) & 127;
    acc_2 = (acc_2 + tracker_81_2) & 127;
  }

  int threshold_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_56_1 > 26)
  {
    acc_1 = ((acc_1 + (threshold_56_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_56_2 > 26)
  {
    acc_2 = ((acc_2 + (threshold_56_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_81_1 == tracker_81_2);
  assert(threshold_56_1 == threshold_56_2);
}

int fn_R000652_5213_8(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int tracker_81 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_81 = ((tracker_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_81) & 127;
  }

  int threshold_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_56 > 26)
  {
    acc = ((acc + (threshold_56 * 2)) + 5) & 127;
    aux ^= threshold_56 & 15;
  }
  else
  {
    acc = ((acc - threshold_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_16_1 = 0;
  int offset_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_16_1 = ((offset_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_16_2 = ((offset_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_16_1) & 127;
    acc_2 = (acc_2 + offset_16_2) & 127;
  }

  int stride_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_34_1) & 63;
  aux_2 = (aux_2 + stride_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_16_1 == offset_16_2);
  assert(stride_34_1 == stride_34_2);
}

int fn_R000652_5213_9(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_16 = ((offset_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_16) & 127;
  }

  int stride_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_34) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_44_1 = local_arr_1[aux_1 % 3];
  int tracker_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_44_1 == tracker_44_2);
}

int fn_R000652_5213_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int tracker_44 = local_arr[aux % 3];
  acc = (acc + (tracker_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st_1 = {0};
  struct FilterState_R000652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int stride_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_31_1 > 26)
  {
    acc_1 = ((acc_1 + (stride_31_1 * 2)) + 5) & 127;
    aux_1 ^= stride_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_31_2 > 26)
  {
    acc_2 = ((acc_2 + (stride_31_2 * 2)) + 5) & 127;
    aux_2 ^= stride_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_57_1)
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

  switch (tracker_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_48_1 = 0;
  int damping_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_48_1 = ((damping_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_48_2 = ((damping_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_48_1) & 127;
    acc_2 = (acc_2 + damping_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_31_1 == stride_31_2);
  assert(tracker_57_1 == tracker_57_2);
  assert(damping_48_1 == damping_48_2);
}

int fn_R000652_5213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int stride_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_31 > 26)
  {
    acc = ((acc + (stride_31 * 2)) + 5) & 127;
    aux ^= stride_31 & 15;
  }
  else
  {
    acc = ((acc - stride_31) + 11) & 127;
    aux += 3;
  }
  int tracker_57 = (aux + st.buffer[1]) & 3;
  switch (tracker_57)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_48 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_48 = ((damping_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int cursor_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_77_1) & 63;
  aux_2 = (aux_2 + cursor_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_95_1 = 0;
  int metric_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_95_1 = ((metric_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_95_2 = ((metric_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_95_1) & 127;
    acc_2 = (acc_2 + metric_95_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_77_1 == cursor_77_2);
  assert(metric_95_1 == metric_95_2);
}

int fn_R000652_5213_12(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int cursor_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_77) & 63;
  acc ^= aux;
  int metric_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_95 = ((metric_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_95) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_19_1 = 0;
  int sample_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_19_1 = ((sample_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_19_2 = ((sample_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_19_1) & 127;
    acc_2 = (acc_2 + sample_19_2) & 127;
  }

  int segment_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_45_1) & 63;
  aux_2 = (aux_2 + segment_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_46_1)
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

  switch (threshold_46_2)
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

  int cursor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_24_1 > 27)
  {
    acc_1 = ((acc_1 + (cursor_24_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_24_2 > 27)
  {
    acc_2 = ((acc_2 + (cursor_24_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_19_1 == sample_19_2);
  assert(segment_45_1 == segment_45_2);
  assert(threshold_46_1 == threshold_46_2);
  assert(cursor_24_1 == cursor_24_2);
}

int fn_R000652_5213_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_19 = ((sample_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_19) & 127;
  }

  int segment_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_45) & 63;
  acc ^= aux;
  int threshold_46 = (aux + st.buffer[1]) & 3;
  switch (threshold_46)
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

  int cursor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_24 > 27)
  {
    acc = ((acc + (cursor_24 * 2)) + 5) & 127;
    aux ^= cursor_24 & 15;
  }
  else
  {
    acc = ((acc - cursor_24) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st_1 = {0};
  struct FilterState_R000652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_98_1 = 0;
  int cursor_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_98_1 = ((cursor_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_98_2 = ((cursor_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_98_1) & 127;
    acc_2 = (acc_2 + cursor_98_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_30_1 = local_arr_1[aux_1 % 3];
  int window_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_30_2 * 2)) & 127;
  int pivot_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_12_1 > 21)
  {
    acc_1 = ((acc_1 + (pivot_12_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_12_2 > 21)
  {
    acc_2 = ((acc_2 + (pivot_12_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_98_1 == cursor_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_30_1 == window_30_2);
  assert(pivot_12_1 == pivot_12_2);
}

int fn_R000652_5213_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_98 = ((cursor_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_98) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int window_30 = local_arr[aux % 3];
  acc = (acc + (window_30 * 2)) & 127;
  int pivot_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_12 > 21)
  {
    acc = ((acc + (pivot_12 * 2)) + 5) & 127;
    aux ^= pivot_12 & 15;
  }
  else
  {
    acc = ((acc - pivot_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_24_1) & 63;
  aux_2 = (aux_2 + tally_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_82_1 > 11)
  {
    acc_1 = ((acc_1 + (margin_82_1 * 2)) + 5) & 127;
    aux_1 ^= margin_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_82_2 > 11)
  {
    acc_2 = ((acc_2 + (margin_82_2 * 2)) + 5) & 127;
    aux_2 ^= margin_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int mask_98_1 = 0;
  int mask_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_98_1 = ((mask_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_98_2 = ((mask_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_98_1) & 127;
    acc_2 = (acc_2 + mask_98_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_24_1 == tally_24_2);
  assert(margin_82_1 == margin_82_2);
  assert(mask_98_1 == mask_98_2);
}

int fn_R000652_5213_15(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_24) & 63;
  acc ^= aux;
  int margin_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_82 > 11)
  {
    acc = ((acc + (margin_82 * 2)) + 5) & 127;
    aux ^= margin_82 & 15;
  }
  else
  {
    acc = ((acc - margin_82) + 11) & 127;
    aux += 3;
  }
  int mask_98 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_98 = ((mask_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_98) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000652_5213_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st_1 = {0};
  struct FilterState_R000652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int sample_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_38_1) & 63;
  aux_2 = (aux_2 + sample_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_39_1 > 45)
  {
    acc_1 = ((acc_1 + (pivot_39_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_39_2 > 45)
  {
    acc_2 = ((acc_2 + (pivot_39_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_82_1 = local_arr_1[aux_1 % 3];
  int checksum_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_38_1 == sample_38_2);
  assert(pivot_39_1 == pivot_39_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_82_1 == checksum_82_2);
}

int fn_R000652_5213_16(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int sample_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_38) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_39 > 45)
  {
    acc = ((acc + (pivot_39 * 2)) + 5) & 127;
    aux ^= pivot_39 & 15;
  }
  else
  {
    acc = ((acc - pivot_39) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_82 = local_arr[aux % 3];
  acc = (acc + (checksum_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_43_1 = 0;
  int metric_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_43_1 = ((metric_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_43_2 = ((metric_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_43_1) & 127;
    acc_2 = (acc_2 + metric_43_2) & 127;
  }

  int damping_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_11_1) & 63;
  aux_2 = (aux_2 + damping_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_49_1 > 35)
  {
    acc_1 = ((acc_1 + (segment_49_1 * 2)) + 5) & 127;
    aux_1 ^= segment_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_49_2 > 35)
  {
    acc_2 = ((acc_2 + (segment_49_2 * 2)) + 5) & 127;
    aux_2 ^= segment_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_43_1 == metric_43_2);
  assert(damping_11_1 == damping_11_2);
  assert(segment_49_1 == segment_49_2);
}

int fn_R000652_5213_17(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_43 = ((metric_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_43) & 127;
  }

  int damping_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_11) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_49 > 35)
  {
    acc = ((acc + (segment_49 * 2)) + 5) & 127;
    aux ^= segment_49 & 15;
  }
  else
  {
    acc = ((acc - segment_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quantum_44_1 = 0;
  int quantum_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_44_1 = ((quantum_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_44_2 = ((quantum_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_44_1) & 127;
    acc_2 = (acc_2 + quantum_44_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_11_1 > 45)
  {
    acc_1 = ((acc_1 + (quotient_11_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_11_2 > 45)
  {
    acc_2 = ((acc_2 + (quotient_11_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_44_1 == quantum_44_2);
  assert(quotient_11_1 == quotient_11_2);
}

int fn_R000652_5213_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quantum_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_44 = ((quantum_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_44) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_11 > 45)
  {
    acc = ((acc + (quotient_11 * 2)) + 5) & 127;
    aux ^= quotient_11 & 15;
  }
  else
  {
    acc = ((acc - quotient_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_57_1 = local_arr_1[aux_1 % 3];
  int delta_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_57_2 * 2)) & 127;
  int quantum_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_64_1)
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

  switch (quantum_64_2)
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

  int window_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_46_1 > 13)
  {
    acc_1 = ((acc_1 + (window_46_1 * 2)) + 5) & 127;
    aux_1 ^= window_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_46_2 > 13)
  {
    acc_2 = ((acc_2 + (window_46_2 * 2)) + 5) & 127;
    aux_2 ^= window_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_57_1 == delta_57_2);
  assert(quantum_64_1 == quantum_64_2);
  assert(window_46_1 == window_46_2);
}

int fn_R000652_5213_19(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int delta_57 = local_arr[aux % 3];
  acc = (acc + (delta_57 * 2)) & 127;
  int quantum_64 = (aux + st.buffer[1]) & 3;
  switch (quantum_64)
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

  int window_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_46 > 13)
  {
    acc = ((acc + (window_46 * 2)) + 5) & 127;
    aux ^= window_46 & 15;
  }
  else
  {
    acc = ((acc - window_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int window_78_1 = 0;
  int window_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_78_1 = ((window_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_78_2 = ((window_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_78_1) & 127;
    acc_2 = (acc_2 + window_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
}

int fn_R000652_5213_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int window_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_78 = ((window_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_21_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_83_1)
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

  switch (delta_83_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_56_1 > 36)
  {
    acc_1 = ((acc_1 + (tracker_56_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_56_2 > 36)
  {
    acc_2 = ((acc_2 + (tracker_56_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_83_1 == delta_83_2);
  assert(tracker_56_1 == tracker_56_2);
}

int fn_R000652_5213_21(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000652_5213_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_83 = (aux + st.buffer[1]) & 3;
  switch (delta_83)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_56 > 36)
  {
    acc = ((acc + (tracker_56 * 2)) + 5) & 127;
    aux ^= tracker_56 & 15;
  }
  else
  {
    acc = ((acc - tracker_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000652_5213_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st_1 = {0};
  struct FilterState_R000652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_19_1 = local_arr_1[aux_1 % 3];
  int weight_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_19_2 * 2)) & 127;
  int parity_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_75_1)
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

  switch (parity_75_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_19_1 == weight_19_2);
  assert(parity_75_1 == parity_75_2);
}

int fn_R000652_5213_22(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_19 = local_arr[aux % 3];
  acc = (acc + (weight_19 * 2)) & 127;
  int parity_75 = (aux + st.buffer[1]) & 3;
  switch (parity_75)
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

void fn_R000652_5213_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st_1 = {0};
  struct AudioFrame_R000652_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int segment_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_44_1) & 63;
  aux_2 = (aux_2 + segment_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_60_1 > 30)
  {
    acc_1 = ((acc_1 + (factor_60_1 * 2)) + 5) & 127;
    aux_1 ^= factor_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_60_2 > 30)
  {
    acc_2 = ((acc_2 + (factor_60_2 * 2)) + 5) & 127;
    aux_2 ^= factor_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_81_1 = local_arr_1[aux_1 % 3];
  int residue_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(factor_60_1 == factor_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_81_1 == residue_81_2);
}

int fn_R000652_5213_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000652_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int segment_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_44) & 63;
  acc ^= aux;
  int factor_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_60 > 30)
  {
    acc = ((acc + (factor_60 * 2)) + 5) & 127;
    aux ^= factor_60 & 15;
  }
  else
  {
    acc = ((acc - factor_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_81 = local_arr[aux % 3];
  acc = (acc + (residue_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000652_5213_24_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st_1 = {0};
  struct FilterState_R000652_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_68_1 > 33)
  {
    acc_1 = ((acc_1 + (stride_68_1 * 2)) + 5) & 127;
    aux_1 ^= stride_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_68_2 > 33)
  {
    acc_2 = ((acc_2 + (stride_68_2 * 2)) + 5) & 127;
    aux_2 ^= stride_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int segment_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_69_1)
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

  switch (segment_69_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_34_1 = local_arr_1[aux_1 % 3];
  int tally_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_34_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_68_1 == stride_68_2);
  assert(segment_69_1 == segment_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_34_1 == tally_34_2);
}

int fn_R000652_5213_24(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000652_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_68 > 33)
  {
    acc = ((acc + (stride_68 * 2)) + 5) & 127;
    aux ^= stride_68 & 15;
  }
  else
  {
    acc = ((acc - stride_68) + 11) & 127;
    aux += 3;
  }
  int segment_69 = (aux + st.buffer[1]) & 3;
  switch (segment_69)
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

  int local_arr[3] = {4, 9, 15};
  int tally_34 = local_arr[aux % 3];
  acc = (acc + (tally_34 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000652_0_1;
  int sec_r000652_0_2;
  int sec_r000652_1_1;
  int sec_r000652_1_2;
  int sec_r000652_2_1;
  int sec_r000652_2_2;
  int sec_r000652_3_1;
  int sec_r000652_3_2;
  int sec_r000652_4_1;
  int sec_r000652_4_2;
  int sec_r000652_5_1;
  int sec_r000652_5_2;
  int sec_r000652_6_1;
  int sec_r000652_6_2;
  int sec_r000652_7_1;
  int sec_r000652_7_2;
  int sec_r000652_8_1;
  int sec_r000652_8_2;
  int sec_r000652_9_1;
  int sec_r000652_9_2;
  int sec_r000652_10_1;
  int sec_r000652_10_2;
  int sec_r000652_11_1;
  int sec_r000652_11_2;
  int sec_r000652_12_1;
  int sec_r000652_12_2;
  int sec_r000652_13_1;
  int sec_r000652_13_2;
  int sec_r000652_14_1;
  int sec_r000652_14_2;
  int sec_r000652_15_1;
  int sec_r000652_15_2;
  int sec_r000652_16_1;
  int sec_r000652_16_2;
  int pub_r000652_0_1;
  int pub_r000652_0_2;
  int pub_r000652_1_1;
  int pub_r000652_1_2;
  int pub_r000652_2_1;
  int pub_r000652_2_2;
  int pub_r000652_3_1;
  int pub_r000652_3_2;
  int pub_r000652_4_1;
  int pub_r000652_4_2;
  int pub_r000652_5_1;
  int pub_r000652_5_2;
  int pub_r000652_6_1;
  int pub_r000652_6_2;
  int pub_r000652_7_1;
  int pub_r000652_7_2;
  int pub_r000652_8_1;
  int pub_r000652_8_2;
  int pub_r000652_9_1;
  int pub_r000652_9_2;
  int pub_r000652_10_1;
  int pub_r000652_10_2;
  int pub_r000652_11_1;
  int pub_r000652_11_2;
  int pub_r000652_12_1;
  int pub_r000652_12_2;
  int pub_r000652_13_1;
  int pub_r000652_13_2;
  int pub_r000652_14_1;
  int pub_r000652_14_2;
  int pub_r000652_15_1;
  int pub_r000652_15_2;
  int pub_r000652_16_1;
  int pub_r000652_16_2;
  int pub_r000652_17_1;
  int pub_r000652_17_2;
  int pub_r000652_18_1;
  int pub_r000652_18_2;
  int pub_r000652_19_1;
  int pub_r000652_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000652_0_1 >= (-100)) && (pub_r000652_0_1 <= 100));
  __CPROVER_assume((pub_r000652_0_2 >= (-100)) && (pub_r000652_0_2 <= 100));
  __CPROVER_assume((pub_r000652_1_1 >= (-100)) && (pub_r000652_1_1 <= 100));
  __CPROVER_assume((pub_r000652_1_2 >= (-100)) && (pub_r000652_1_2 <= 100));
  __CPROVER_assume((pub_r000652_2_1 >= (-100)) && (pub_r000652_2_1 <= 100));
  __CPROVER_assume((pub_r000652_2_2 >= (-100)) && (pub_r000652_2_2 <= 100));
  __CPROVER_assume((pub_r000652_3_1 >= (-100)) && (pub_r000652_3_1 <= 100));
  __CPROVER_assume((pub_r000652_3_2 >= (-100)) && (pub_r000652_3_2 <= 100));
  __CPROVER_assume((pub_r000652_4_1 >= (-100)) && (pub_r000652_4_1 <= 100));
  __CPROVER_assume((pub_r000652_4_2 >= (-100)) && (pub_r000652_4_2 <= 100));
  __CPROVER_assume((pub_r000652_5_1 >= (-100)) && (pub_r000652_5_1 <= 100));
  __CPROVER_assume((pub_r000652_5_2 >= (-100)) && (pub_r000652_5_2 <= 100));
  __CPROVER_assume((pub_r000652_6_1 >= (-100)) && (pub_r000652_6_1 <= 100));
  __CPROVER_assume((pub_r000652_6_2 >= (-100)) && (pub_r000652_6_2 <= 100));
  __CPROVER_assume((pub_r000652_7_1 >= (-100)) && (pub_r000652_7_1 <= 100));
  __CPROVER_assume((pub_r000652_7_2 >= (-100)) && (pub_r000652_7_2 <= 100));
  __CPROVER_assume((pub_r000652_8_1 >= (-100)) && (pub_r000652_8_1 <= 100));
  __CPROVER_assume((pub_r000652_8_2 >= (-100)) && (pub_r000652_8_2 <= 100));
  __CPROVER_assume((pub_r000652_9_1 >= (-100)) && (pub_r000652_9_1 <= 100));
  __CPROVER_assume((pub_r000652_9_2 >= (-100)) && (pub_r000652_9_2 <= 100));
  __CPROVER_assume((pub_r000652_10_1 >= (-100)) && (pub_r000652_10_1 <= 100));
  __CPROVER_assume((pub_r000652_10_2 >= (-100)) && (pub_r000652_10_2 <= 100));
  __CPROVER_assume((pub_r000652_11_1 >= (-100)) && (pub_r000652_11_1 <= 100));
  __CPROVER_assume((pub_r000652_11_2 >= (-100)) && (pub_r000652_11_2 <= 100));
  __CPROVER_assume((pub_r000652_12_1 >= (-100)) && (pub_r000652_12_1 <= 100));
  __CPROVER_assume((pub_r000652_12_2 >= (-100)) && (pub_r000652_12_2 <= 100));
  __CPROVER_assume((pub_r000652_13_1 >= (-100)) && (pub_r000652_13_1 <= 100));
  __CPROVER_assume((pub_r000652_13_2 >= (-100)) && (pub_r000652_13_2 <= 100));
  __CPROVER_assume((pub_r000652_14_1 >= (-100)) && (pub_r000652_14_1 <= 100));
  __CPROVER_assume((pub_r000652_14_2 >= (-100)) && (pub_r000652_14_2 <= 100));
  __CPROVER_assume((pub_r000652_15_1 >= (-100)) && (pub_r000652_15_1 <= 100));
  __CPROVER_assume((pub_r000652_15_2 >= (-100)) && (pub_r000652_15_2 <= 100));
  __CPROVER_assume((pub_r000652_16_1 >= (-100)) && (pub_r000652_16_1 <= 100));
  __CPROVER_assume((pub_r000652_16_2 >= (-100)) && (pub_r000652_16_2 <= 100));
  __CPROVER_assume((pub_r000652_17_1 >= (-100)) && (pub_r000652_17_1 <= 100));
  __CPROVER_assume((pub_r000652_17_2 >= (-100)) && (pub_r000652_17_2 <= 100));
  __CPROVER_assume((pub_r000652_18_1 >= (-100)) && (pub_r000652_18_1 <= 100));
  __CPROVER_assume((pub_r000652_18_2 >= (-100)) && (pub_r000652_18_2 <= 100));
  __CPROVER_assume((pub_r000652_19_1 >= (-100)) && (pub_r000652_19_1 <= 100));
  __CPROVER_assume((pub_r000652_19_2 >= (-100)) && (pub_r000652_19_2 <= 100));
  __CPROVER_assume((sec_r000652_0_1 >= 0) && (sec_r000652_0_1 <= 255));
  __CPROVER_assume((sec_r000652_0_2 >= 0) && (sec_r000652_0_2 <= 255));
  __CPROVER_assume((sec_r000652_1_1 >= 0) && (sec_r000652_1_1 <= 255));
  __CPROVER_assume((sec_r000652_1_2 >= 0) && (sec_r000652_1_2 <= 255));
  __CPROVER_assume((sec_r000652_2_1 >= 0) && (sec_r000652_2_1 <= 255));
  __CPROVER_assume((sec_r000652_2_2 >= 0) && (sec_r000652_2_2 <= 255));
  __CPROVER_assume((sec_r000652_3_1 >= 0) && (sec_r000652_3_1 <= 255));
  __CPROVER_assume((sec_r000652_3_2 >= 0) && (sec_r000652_3_2 <= 255));
  __CPROVER_assume((sec_r000652_4_1 >= 0) && (sec_r000652_4_1 <= 255));
  __CPROVER_assume((sec_r000652_4_2 >= 0) && (sec_r000652_4_2 <= 255));
  __CPROVER_assume((sec_r000652_5_1 >= 0) && (sec_r000652_5_1 <= 255));
  __CPROVER_assume((sec_r000652_5_2 >= 0) && (sec_r000652_5_2 <= 255));
  __CPROVER_assume((sec_r000652_6_1 >= 0) && (sec_r000652_6_1 <= 255));
  __CPROVER_assume((sec_r000652_6_2 >= 0) && (sec_r000652_6_2 <= 255));
  __CPROVER_assume((sec_r000652_7_1 >= 0) && (sec_r000652_7_1 <= 255));
  __CPROVER_assume((sec_r000652_7_2 >= 0) && (sec_r000652_7_2 <= 255));
  __CPROVER_assume((sec_r000652_8_1 >= 0) && (sec_r000652_8_1 <= 255));
  __CPROVER_assume((sec_r000652_8_2 >= 0) && (sec_r000652_8_2 <= 255));
  __CPROVER_assume((sec_r000652_9_1 >= 0) && (sec_r000652_9_1 <= 255));
  __CPROVER_assume((sec_r000652_9_2 >= 0) && (sec_r000652_9_2 <= 255));
  __CPROVER_assume((sec_r000652_10_1 >= 0) && (sec_r000652_10_1 <= 255));
  __CPROVER_assume((sec_r000652_10_2 >= 0) && (sec_r000652_10_2 <= 255));
  __CPROVER_assume((sec_r000652_11_1 >= 0) && (sec_r000652_11_1 <= 255));
  __CPROVER_assume((sec_r000652_11_2 >= 0) && (sec_r000652_11_2 <= 255));
  __CPROVER_assume((sec_r000652_12_1 >= 0) && (sec_r000652_12_1 <= 255));
  __CPROVER_assume((sec_r000652_12_2 >= 0) && (sec_r000652_12_2 <= 255));
  __CPROVER_assume((sec_r000652_13_1 >= 0) && (sec_r000652_13_1 <= 255));
  __CPROVER_assume((sec_r000652_13_2 >= 0) && (sec_r000652_13_2 <= 255));
  __CPROVER_assume((sec_r000652_14_1 >= 0) && (sec_r000652_14_1 <= 255));
  __CPROVER_assume((sec_r000652_14_2 >= 0) && (sec_r000652_14_2 <= 255));
  __CPROVER_assume((sec_r000652_15_1 >= 0) && (sec_r000652_15_1 <= 255));
  __CPROVER_assume((sec_r000652_15_2 >= 0) && (sec_r000652_15_2 <= 255));
  __CPROVER_assume((sec_r000652_16_1 >= 0) && (sec_r000652_16_1 <= 255));
  __CPROVER_assume((sec_r000652_16_2 >= 0) && (sec_r000652_16_2 <= 255));
  struct FilterState_R000652_5213_0 st_var_0_1 = {0};
  struct FilterState_R000652_5213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000652_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000652_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000652_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000652_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000652_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000652_0_2 + 7) & 15;
  struct AudioFrame_R000652_5213_1 st_var_1_1 = {0};
  struct AudioFrame_R000652_5213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000652_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000652_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000652_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000652_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000652_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000652_0_2 + 9) & 15;
  struct DeviceConfig_R000652_5213_2 st_var_2_1 = {0};
  struct DeviceConfig_R000652_5213_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000652_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000652_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000652_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000652_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000652_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000652_0_2 + 11) & 15;
  union TelemetryField_R000652_5213_0 u_var_1;
  union TelemetryField_R000652_5213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = (st_var_1_1.buffer[0] ^ 4) & 3;
  int stage_v_1_2 = (st_var_1_2.buffer[0] ^ 4) & 3;
  switch (stage_v_1_1)
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

  switch (stage_v_1_2)
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

  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_0_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_0_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
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

  switch (stage_v_6_2)
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

  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 10) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

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

  int stage_v_15_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_15_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 17) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = table_1[3];
  int stage_v_19_2 = table_2[3];
  table_1[3] = (table_1[0] + 39) & 63;
  table_2[3] = (table_2[0] + 39) & 63;
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (st_var_2_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_2_2.buffer[0] ^ 23) & 3;
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

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_22_1 = ((stage_v_22_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_22_2 = ((stage_v_22_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_26_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = table_1[0];
  int stage_v_28_2 = table_2[0];
  table_1[0] = (table_1[1] + 57) & 63;
  table_2[0] = (table_2[1] + 57) & 63;
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
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

  switch (stage_v_29_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = (st_var_1_1.buffer[0] ^ 34) & 3;
  int stage_v_31_2 = (st_var_1_2.buffer[0] ^ 34) & 3;
  switch (stage_v_31_1)
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

  switch (stage_v_31_2)
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

  int stage_v_32_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (37 & 31);
  int stage_v_32_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (37 & 31);
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= (stage_v_32_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_32_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 34) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 34) & 15;
  int stage_v_33_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_33_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= stage_v_33_1;
  chk_sum_2 ^= stage_v_33_2;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (st_var_2_1.buffer[0] ^ 38) & 3;
  int stage_v_35_2 = (st_var_2_2.buffer[0] ^ 38) & 3;
  switch (stage_v_35_1)
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

  switch (stage_v_35_2)
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

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_37_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_40_1 = ((st_var_1_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_1_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 54)
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
  if (stage_v_40_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 54)
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
  int stage_v_41_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (46 & 31);
  int stage_v_41_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (46 & 31);
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  chk_sum_1 ^= (stage_v_41_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_41_2 << 1) & 127;
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = ((st_var_2_1.buffer[2] * 2) + 139) & 63;
  int stage_v_44_2 = ((st_var_2_2.buffer[2] * 2) + 139) & 63;
  if (stage_v_44_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_44_1) - 5) & 255;
    if (stage_v_44_1 > 55)
    {
      chk_sum_1 ^= stage_v_44_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_44_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_44_2) - 5) & 255;
    if (stage_v_44_2 > 55)
    {
      chk_sum_2 ^= stage_v_44_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 46) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (54 & 31);
  int stage_v_49_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (54 & 31);
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= (stage_v_49_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_49_2 << 1) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (57 & 31);
  int stage_v_52_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (57 & 31);
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  chk_sum_1 ^= (stage_v_52_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_52_2 << 1) & 127;
  int stage_v_53_1 = (st_var_2_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_2_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = table_1[2];
  int stage_v_54_2 = table_2[2];
  table_1[2] = (table_1[3] + 109) & 63;
  table_2[2] = (table_2[3] + 109) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_58_1 = ((stage_v_58_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_58_2 = ((stage_v_58_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_59_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 64) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
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
  int stage_v_70_1 = ((st_var_1_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_1_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 28)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 28)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((st_var_0_1.buffer[0] * 2) + 223) & 63;
  int stage_v_72_2 = ((st_var_0_2.buffer[0] * 2) + 223) & 63;
  if (stage_v_72_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_72_1) - 5) & 255;
    if (stage_v_72_1 > 30)
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
  if (stage_v_72_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_72_2) - 5) & 255;
    if (stage_v_72_2 > 30)
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
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = ((st_var_2_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_2_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 34)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 34)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((st_var_1_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_1_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 34)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 34)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_77_1 = (st_var_2_1.buffer[0] ^ 80) & 3;
  int stage_v_77_2 = (st_var_2_2.buffer[0] ^ 80) & 3;
  switch (stage_v_77_1)
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

  switch (stage_v_77_2)
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

  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
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

  switch (stage_v_79_2)
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

  int stage_v_80_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (85 & 31);
  int stage_v_80_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (85 & 31);
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  chk_sum_1 ^= (stage_v_80_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_80_2 << 1) & 127;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 84) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 84) & 15;
  int stage_v_83_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_83_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= stage_v_83_1;
  chk_sum_2 ^= stage_v_83_2;
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (90 & 31);
  int stage_v_85_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (90 & 31);
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  chk_sum_1 ^= (stage_v_85_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_85_2 << 1) & 127;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_86_1 = ((stage_v_86_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_86_2 = ((stage_v_86_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 89) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 89) & 15;
  int stage_v_88_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_88_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  chk_sum_1 ^= stage_v_88_1;
  chk_sum_2 ^= stage_v_88_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 90) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 90) & 15;
  int stage_v_89_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_89_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  chk_sum_1 ^= stage_v_89_1;
  chk_sum_2 ^= stage_v_89_2;
  int stage_v_90_1 = table_1[2];
  int stage_v_90_2 = table_2[2];
  table_1[2] = (table_1[3] + 181) & 63;
  table_2[2] = (table_2[3] + 181) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((st_var_2_1.buffer[2] * 2) + 283) & 63;
  int stage_v_92_2 = ((st_var_2_2.buffer[2] * 2) + 283) & 63;
  if (stage_v_92_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_92_1) - 5) & 255;
    if (stage_v_92_1 > 54)
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
  if (stage_v_92_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_92_2) - 5) & 255;
    if (stage_v_92_2 > 54)
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
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_93_1 = ((stage_v_93_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_93_2 = ((stage_v_93_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((st_var_2_1.buffer[2] * 2) + 292) & 63;
  int stage_v_95_2 = ((st_var_2_2.buffer[2] * 2) + 292) & 63;
  if (stage_v_95_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_95_1) - 5) & 255;
    if (stage_v_95_1 > 55)
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
  if (stage_v_95_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_95_2) - 5) & 255;
    if (stage_v_95_2 > 55)
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
  int stage_v_97_1 = (st_var_1_1.buffer[0] ^ 100) & 3;
  int stage_v_97_2 = (st_var_1_2.buffer[0] ^ 100) & 3;
  switch (stage_v_97_1)
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

  switch (stage_v_97_2)
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 99) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 99) & 15;
  int stage_v_98_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_98_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  chk_sum_1 ^= stage_v_98_1;
  chk_sum_2 ^= stage_v_98_2;
  int stage_v_99_1 = (st_var_0_1.buffer[0] ^ 102) & 3;
  int stage_v_99_2 = (st_var_0_2.buffer[0] ^ 102) & 3;
  switch (stage_v_99_1)
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

  switch (stage_v_99_2)
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

  int stage_v_100_1 = (st_var_1_1.buffer[0] ^ 103) & 3;
  int stage_v_100_2 = (st_var_1_2.buffer[0] ^ 103) & 3;
  switch (stage_v_100_1)
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

  switch (stage_v_100_2)
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

  int stage_v_101_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_101_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_102_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (107 & 31);
  int stage_v_102_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (107 & 31);
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  chk_sum_1 ^= (stage_v_102_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_102_2 << 1) & 127;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_103_1 = ((stage_v_103_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_103_2 = ((stage_v_103_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (109 & 31);
  int stage_v_104_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (109 & 31);
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= (stage_v_104_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_104_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 106) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 106) & 15;
  int stage_v_105_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_105_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  chk_sum_1 ^= stage_v_105_1;
  chk_sum_2 ^= stage_v_105_2;
  int stage_v_106_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (111 & 31);
  int stage_v_106_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (111 & 31);
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  chk_sum_1 ^= (stage_v_106_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_106_2 << 1) & 127;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = table_1[0];
  int stage_v_108_2 = table_2[0];
  table_1[0] = (table_1[1] + 217) & 63;
  table_2[0] = (table_2[1] + 217) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((st_var_1_1.buffer[1] * 2) + 334) & 63;
  int stage_v_109_2 = ((st_var_1_2.buffer[1] * 2) + 334) & 63;
  if (stage_v_109_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_109_1) - 5) & 255;
    if (stage_v_109_1 > 42)
    {
      chk_sum_1 ^= stage_v_109_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_109_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_109_2) - 5) & 255;
    if (stage_v_109_2 > 42)
    {
      chk_sum_2 ^= stage_v_109_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (119 & 31);
  int stage_v_114_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (119 & 31);
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= (stage_v_114_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_114_2 << 1) & 127;
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = table_1[0];
  int stage_v_116_2 = table_2[0];
  table_1[0] = (table_1[1] + 233) & 63;
  table_2[0] = (table_2[1] + 233) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = table_1[2];
  int stage_v_118_2 = table_2[2];
  table_1[2] = (table_1[3] + 237) & 63;
  table_2[2] = (table_2[3] + 237) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
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
  int stage_v_121_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (126 & 31);
  int stage_v_121_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (126 & 31);
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= (stage_v_121_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_121_2 << 1) & 127;
  int stage_v_122_1 = (st_var_2_1.buffer[0] ^ 125) & 3;
  int stage_v_122_2 = (st_var_2_2.buffer[0] ^ 125) & 3;
  switch (stage_v_122_1)
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

  switch (stage_v_122_2)
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

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (129 & 31);
  int stage_v_124_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (129 & 31);
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= (stage_v_124_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_124_2 << 1) & 127;
  int stage_v_125_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_125_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
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

  switch (stage_v_126_2)
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

  int stage_v_127_1 = ((st_var_1_1.buffer[1] * 2) + 388) & 63;
  int stage_v_127_2 = ((st_var_1_2.buffer[1] * 2) + 388) & 63;
  if (stage_v_127_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_127_1) - 5) & 255;
    if (stage_v_127_1 > 34)
    {
      chk_sum_1 ^= stage_v_127_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_127_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_127_2) - 5) & 255;
    if (stage_v_127_2 > 34)
    {
      chk_sum_2 ^= stage_v_127_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_128_1 = table_1[0];
  int stage_v_128_2 = table_2[0];
  table_1[0] = (table_1[1] + 257) & 63;
  table_2[0] = (table_2[1] + 257) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (134 & 31);
  int stage_v_129_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (134 & 31);
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  chk_sum_1 ^= (stage_v_129_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_129_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 131) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 131) & 15;
  int stage_v_130_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_130_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  chk_sum_1 ^= stage_v_130_1;
  chk_sum_2 ^= stage_v_130_2;
  int stage_v_131_1 = (st_var_2_1.buffer[0] ^ 134) & 3;
  int stage_v_131_2 = (st_var_2_2.buffer[0] ^ 134) & 3;
  switch (stage_v_131_1)
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

  switch (stage_v_131_2)
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

  int stage_v_132_1 = ((st_var_0_1.buffer[0] * 2) + 403) & 63;
  int stage_v_132_2 = ((st_var_0_2.buffer[0] * 2) + 403) & 63;
  if (stage_v_132_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_132_1) - 5) & 255;
    if (stage_v_132_1 > 27)
    {
      chk_sum_1 ^= stage_v_132_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_132_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_132_2) - 5) & 255;
    if (stage_v_132_2 > 27)
    {
      chk_sum_2 ^= stage_v_132_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_133_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_133_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 135) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 135) & 15;
  int stage_v_134_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_134_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  chk_sum_1 ^= stage_v_134_1;
  chk_sum_2 ^= stage_v_134_2;
  int stage_v_135_1 = table_1[3];
  int stage_v_135_2 = table_2[3];
  table_1[3] = (table_1[0] + 271) & 63;
  table_2[3] = (table_2[0] + 271) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((st_var_1_1.buffer[1] * 2) + 415) & 63;
  int stage_v_136_2 = ((st_var_1_2.buffer[1] * 2) + 415) & 63;
  if (stage_v_136_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_136_1) - 5) & 255;
    if (stage_v_136_1 > 42)
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
  if (stage_v_136_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_136_2) - 5) & 255;
    if (stage_v_136_2 > 42)
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
  int stage_v_137_1 = table_1[1];
  int stage_v_137_2 = table_2[1];
  table_1[1] = (table_1[2] + 275) & 63;
  table_2[1] = (table_2[2] + 275) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_138_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_140_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (145 & 31);
  int stage_v_140_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (145 & 31);
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= (stage_v_140_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_140_2 << 1) & 127;
  int stage_v_141_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (146 & 31);
  int stage_v_141_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (146 & 31);
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= (stage_v_141_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_141_2 << 1) & 127;
  int stage_v_142_1 = (st_var_1_1.buffer[0] ^ 145) & 3;
  int stage_v_142_2 = (st_var_1_2.buffer[0] ^ 145) & 3;
  switch (stage_v_142_1)
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

  switch (stage_v_142_2)
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

  int stage_v_143_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (148 & 31);
  int stage_v_143_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (148 & 31);
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  chk_sum_1 ^= (stage_v_143_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_143_2 << 1) & 127;
  int stage_v_144_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_144_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_145_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_145_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = table_1[3];
  int stage_v_147_2 = table_2[3];
  table_1[3] = (table_1[0] + 295) & 63;
  table_2[3] = (table_2[0] + 295) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_148_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 30)
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
  if (stage_v_149_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 30)
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
  int stage_v_150_1 = 0;
  int stage_v_150_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_150_1 = ((stage_v_150_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_150_2 = ((stage_v_150_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((st_var_1_1.buffer[1] * 2) + 460) & 63;
  int stage_v_151_2 = ((st_var_1_2.buffer[1] * 2) + 460) & 63;
  if (stage_v_151_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_151_1) - 5) & 255;
    if (stage_v_151_1 > 34)
    {
      chk_sum_1 ^= stage_v_151_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_151_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_151_2) - 5) & 255;
    if (stage_v_151_2 > 34)
    {
      chk_sum_2 ^= stage_v_151_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_152_1 = (st_var_2_1.buffer[0] ^ 155) & 3;
  int stage_v_152_2 = (st_var_2_2.buffer[0] ^ 155) & 3;
  switch (stage_v_152_1)
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

  switch (stage_v_152_2)
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

  int stage_v_153_1 = table_1[1];
  int stage_v_153_2 = table_2[1];
  table_1[1] = (table_1[2] + 307) & 63;
  table_2[1] = (table_2[2] + 307) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 156) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = (st_var_0_1.buffer[0] ^ 159) & 3;
  int stage_v_156_2 = (st_var_0_2.buffer[0] ^ 159) & 3;
  switch (stage_v_156_1)
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

  switch (stage_v_156_2)
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

  int stage_v_157_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_157_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_158_1 = (st_var_2_1.buffer[0] ^ 161) & 3;
  int stage_v_158_2 = (st_var_2_2.buffer[0] ^ 161) & 3;
  switch (stage_v_158_1)
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

  switch (stage_v_158_2)
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

  if ((sec_r000652_14_1 & 1) != 0)
  {
    if ((sec_r000652_1_1 & 2) != 0)
    {
      out_sink_1 += 44;
    }
    else
    {
      out_sink_1 += 16;
    }
  }
  else
  {
    if ((sec_r000652_14_1 & 4) != 0)
    {
      out_sink_1 -= 23;
    }
    else
    {
      out_sink_1 -= 51;
    }
  }
  if ((sec_r000652_14_2 & 1) != 0)
  {
    if ((sec_r000652_1_2 & 2) != 0)
    {
      out_sink_2 += 44;
    }
    else
    {
      out_sink_2 += 16;
    }
  }
  else
  {
    if ((sec_r000652_14_2 & 4) != 0)
    {
      out_sink_2 -= 23;
    }
    else
    {
      out_sink_2 -= 51;
    }
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(pub_r000652_5_1 == pub_r000652_5_2);
  __CPROVER_assume(sec_r000652_12_1 != sec_r000652_12_2);
  __CPROVER_assume(sec_r000652_4_1 != sec_r000652_4_2);
  __CPROVER_assume(sec_r000652_7_1 != sec_r000652_7_2);
  __CPROVER_assume(pub_r000652_7_1 == pub_r000652_7_2);
  __CPROVER_assume(pub_r000652_0_1 == pub_r000652_0_2);
  __CPROVER_assume(sec_r000652_9_1 != sec_r000652_9_2);
  __CPROVER_assume(sec_r000652_5_1 != sec_r000652_5_2);
  __CPROVER_assume(sec_r000652_8_1 != sec_r000652_8_2);
  __CPROVER_assume(pub_r000652_13_1 == pub_r000652_13_2);
  __CPROVER_assume(pub_r000652_8_1 == pub_r000652_8_2);
  __CPROVER_assume(pub_r000652_12_1 == pub_r000652_12_2);
  __CPROVER_assume(sec_r000652_16_1 != sec_r000652_16_2);
  __CPROVER_assume(sec_r000652_15_1 != sec_r000652_15_2);
  __CPROVER_assume(sec_r000652_6_1 != sec_r000652_6_2);
  __CPROVER_assume(pub_r000652_18_1 == pub_r000652_18_2);
  __CPROVER_assume(pub_r000652_2_1 == pub_r000652_2_2);
  __CPROVER_assume(sec_r000652_1_1 != sec_r000652_1_2);
  __CPROVER_assume(sec_r000652_14_1 != sec_r000652_14_2);
  __CPROVER_assume(pub_r000652_19_1 == pub_r000652_19_2);
  __CPROVER_assume(pub_r000652_9_1 == pub_r000652_9_2);
  __CPROVER_assume(sec_r000652_11_1 != sec_r000652_11_2);
  __CPROVER_assume(pub_r000652_3_1 == pub_r000652_3_2);
  __CPROVER_assume(sec_r000652_13_1 != sec_r000652_13_2);
  __CPROVER_assume(pub_r000652_1_1 == pub_r000652_1_2);
  __CPROVER_assume(pub_r000652_17_1 == pub_r000652_17_2);
  __CPROVER_assume(sec_r000652_2_1 != sec_r000652_2_2);
  __CPROVER_assume(sec_r000652_0_1 != sec_r000652_0_2);
  __CPROVER_assume(pub_r000652_11_1 == pub_r000652_11_2);
  __CPROVER_assume(pub_r000652_10_1 == pub_r000652_10_2);
  __CPROVER_assume(sec_r000652_3_1 != sec_r000652_3_2);
  __CPROVER_assume(sec_r000652_10_1 != sec_r000652_10_2);
  __CPROVER_assume(pub_r000652_4_1 == pub_r000652_4_2);
  __CPROVER_assume(pub_r000652_15_1 == pub_r000652_15_2);
  __CPROVER_assume(pub_r000652_16_1 == pub_r000652_16_2);
  __CPROVER_assume(pub_r000652_14_1 == pub_r000652_14_2);
  __CPROVER_assume(pub_r000652_6_1 == pub_r000652_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timeout == st_var_2_2.timeout);
  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.parity == st_var_2_2.parity);
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
}


