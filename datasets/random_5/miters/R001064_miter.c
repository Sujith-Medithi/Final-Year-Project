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
struct EventLog_R001064_6413_0
{
  short timestamp;
  unsigned char facility;
  int severity;
  int buffer[3];
};
struct AudioFrame_R001064_6413_1
{
  unsigned char gain;
  int sample_rate;
  int channels;
  unsigned char peak;
  int envelope;
  int buffer[3];
};
struct CipherContext_R001064_6413_2
{
  short iv;
  int flags;
  short counter;
  short nonce;
  int buffer[3];
};
struct StreamBuffer_R001064_6413_3
{
  int state;
  int tail;
  int head;
  int watermark;
  int buffer[3];
};
union PacketPayload_R001064_6413_0
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
void fn_R001064_6413_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int residue_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_87_1) & 63;
  aux_2 = (aux_2 + residue_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_87_1 == residue_87_2);
}

int fn_R001064_6413_0(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int residue_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_87) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001064_6413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_48_1) & 63;
  aux_2 = (aux_2 + scale_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_86_1 = 0;
  int index_reg_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_86_1 = ((index_reg_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_86_2 = ((index_reg_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_86_1) & 127;
    acc_2 = (acc_2 + index_reg_86_2) & 127;
  }

  int accumulator_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_11_1 > 20)
  {
    acc_1 = ((acc_1 + (accumulator_11_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_11_2 > 20)
  {
    acc_2 = ((acc_2 + (accumulator_11_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_11_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_48_1 == scale_48_2);
  assert(index_reg_86_1 == index_reg_86_2);
  assert(accumulator_11_1 == accumulator_11_2);
}

int fn_R001064_6413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_48) & 63;
  acc ^= aux;
  int index_reg_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_86 = ((index_reg_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_86) & 127;
  }

  int accumulator_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_11 > 20)
  {
    acc = ((acc + (accumulator_11 * 2)) + 5) & 127;
    aux ^= accumulator_11 & 15;
  }
  else
  {
    acc = ((acc - accumulator_11) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st_1 = {0};
  struct EventLog_R001064_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int mask_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_61_1)
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

  switch (mask_61_2)
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

  int weight_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_65_1 > 40)
  {
    acc_1 = ((acc_1 + (weight_65_1 * 2)) + 5) & 127;
    aux_1 ^= weight_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_65_2 > 40)
  {
    acc_2 = ((acc_2 + (weight_65_2 * 2)) + 5) & 127;
    aux_2 ^= weight_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_61_1 == mask_61_2);
  assert(weight_65_1 == weight_65_2);
}

int fn_R001064_6413_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int mask_61 = (aux + st.buffer[1]) & 3;
  switch (mask_61)
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

  int weight_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_65 > 40)
  {
    acc = ((acc + (weight_65 * 2)) + 5) & 127;
    aux ^= weight_65 & 15;
  }
  else
  {
    acc = ((acc - weight_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int margin_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_44_1)
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

  switch (margin_44_2)
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

  int residue_12_1 = 0;
  int residue_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_12_1 = ((residue_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_12_2 = ((residue_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_12_1) & 127;
    acc_2 = (acc_2 + residue_12_2) & 127;
  }

  int phase_20_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_20_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_20_1 > 44)
  {
    acc_1 = ((acc_1 + (phase_20_1 * 2)) + 5) & 127;
    aux_1 ^= phase_20_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_20_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_20_2 > 44)
  {
    acc_2 = ((acc_2 + (phase_20_2 * 2)) + 5) & 127;
    aux_2 ^= phase_20_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_20_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(residue_12_1 == residue_12_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R001064_6413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int margin_44 = (aux + st.buffer[1]) & 3;
  switch (margin_44)
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

  int residue_12 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_12 = ((residue_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_12) & 127;
  }

  int phase_20 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_20 > 44)
  {
    acc = ((acc + (phase_20 * 2)) + 5) & 127;
    aux ^= phase_20 & 15;
  }
  else
  {
    acc = ((acc - phase_20) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int factor_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_49_1) & 63;
  aux_2 = (aux_2 + factor_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_23_1 = local_arr_1[aux_1 % 3];
  int offset_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_23_2 * 2)) & 127;
  int factor_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_37_1 > 40)
  {
    acc_1 = ((acc_1 + (factor_37_1 * 2)) + 5) & 127;
    aux_1 ^= factor_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_37_2 > 40)
  {
    acc_2 = ((acc_2 + (factor_37_2 * 2)) + 5) & 127;
    aux_2 ^= factor_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_26_1 = 0;
  int bound_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_26_1 = ((bound_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_26_2 = ((bound_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_26_1) & 127;
    acc_2 = (acc_2 + bound_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_49_1 == factor_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_23_1 == offset_23_2);
  assert(factor_37_1 == factor_37_2);
  assert(bound_26_1 == bound_26_2);
}

int fn_R001064_6413_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_49) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_23 = local_arr[aux % 3];
  acc = (acc + (offset_23 * 2)) & 127;
  int factor_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_37 > 40)
  {
    acc = ((acc + (factor_37 * 2)) + 5) & 127;
    aux ^= factor_37 & 15;
  }
  else
  {
    acc = ((acc - factor_37) + 11) & 127;
    aux += 3;
  }
  int bound_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_26 = ((bound_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001064_6413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st_1 = {0};
  struct EventLog_R001064_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int quotient_75_1 = 0;
  int quotient_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_75_1 = ((quotient_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_75_2 = ((quotient_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_75_1) & 127;
    acc_2 = (acc_2 + quotient_75_2) & 127;
  }

  int parity_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_50_1)
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

  switch (parity_50_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_75_1 == quotient_75_2);
  assert(parity_50_1 == parity_50_2);
}

int fn_R001064_6413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int quotient_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_75 = ((quotient_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_75) & 127;
  }

  int parity_50 = (aux + st.buffer[1]) & 3;
  switch (parity_50)
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

void fn_R001064_6413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001064_6413_2 st_1 = {0};
  struct CipherContext_R001064_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_18_1 = local_arr_1[aux_1 % 3];
  int mask_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_18_2 * 2)) & 127;
  int factor_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_45_1)
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

  switch (factor_45_2)
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

  int weight_14_1 = 0;
  int weight_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_14_1 = ((weight_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_14_2 = ((weight_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_14_1) & 127;
    acc_2 = (acc_2 + weight_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_18_1 == mask_18_2);
  assert(factor_45_1 == factor_45_2);
  assert(weight_14_1 == weight_14_2);
}

int fn_R001064_6413_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001064_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_18 = local_arr[aux % 3];
  acc = (acc + (mask_18 * 2)) & 127;
  int factor_45 = (aux + st.buffer[1]) & 3;
  switch (factor_45)
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

  int weight_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_14 = ((weight_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001064_6413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_30_1 = 0;
  int stride_30_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_30_1 = ((stride_30_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_30_2 = ((stride_30_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_30_1) & 127;
    acc_2 = (acc_2 + stride_30_2) & 127;
  }

  int coefficient_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_77_1 > 31)
  {
    acc_1 = ((acc_1 + (coefficient_77_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_77_2 > 31)
  {
    acc_2 = ((acc_2 + (coefficient_77_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_30_1 == stride_30_2);
  assert(coefficient_77_1 == coefficient_77_2);
}

int fn_R001064_6413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_30 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_30 = ((stride_30 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_30) & 127;
  }

  int coefficient_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_77 > 31)
  {
    acc = ((acc + (coefficient_77 * 2)) + 5) & 127;
    aux ^= coefficient_77 & 15;
  }
  else
  {
    acc = ((acc - coefficient_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001064_6413_2 st_1 = {0};
  struct CipherContext_R001064_6413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quotient_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_40_1)
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

  switch (quotient_40_2)
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

  int checksum_52_1 = 0;
  int checksum_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_52_1 = ((checksum_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_52_2 = ((checksum_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_52_1) & 127;
    acc_2 = (acc_2 + checksum_52_2) & 127;
  }

  int tally_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_85_1 > 30)
  {
    acc_1 = ((acc_1 + (tally_85_1 * 2)) + 5) & 127;
    aux_1 ^= tally_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_85_2 > 30)
  {
    acc_2 = ((acc_2 + (tally_85_2 * 2)) + 5) & 127;
    aux_2 ^= tally_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_85_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.flags == st_2.flags);
  assert(st_1.counter == st_2.counter);
  assert(st_1.nonce == st_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_40_1 == quotient_40_2);
  assert(checksum_52_1 == checksum_52_2);
  assert(tally_85_1 == tally_85_2);
}

int fn_R001064_6413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001064_6413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quotient_40 = (aux + st.buffer[1]) & 3;
  switch (quotient_40)
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

  int checksum_52 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_52 = ((checksum_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_52) & 127;
  }

  int tally_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_85 > 30)
  {
    acc = ((acc + (tally_85 * 2)) + 5) & 127;
    aux ^= tally_85 & 15;
  }
  else
  {
    acc = ((acc - tally_85) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001064_6413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001064_6413_3 st_1 = {0};
  struct StreamBuffer_R001064_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_79_1 = 0;
  int damping_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_79_1 = ((damping_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_79_2 = ((damping_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_79_1) & 127;
    acc_2 = (acc_2 + damping_79_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_14_1 = local_arr_1[aux_1 % 3];
  int segment_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_14_2 * 2)) & 127;
  int index_reg_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_83_1) & 63;
  aux_2 = (aux_2 + index_reg_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_79_1 == damping_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_14_1 == segment_14_2);
  assert(index_reg_83_1 == index_reg_83_2);
}

int fn_R001064_6413_9(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001064_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_79 = ((damping_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_79) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int segment_14 = local_arr[aux % 3];
  acc = (acc + (segment_14 * 2)) & 127;
  int index_reg_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001064_6413_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int cursor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_21_1) & 63;
  aux_2 = (aux_2 + cursor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_93_1 > 16)
  {
    acc_1 = ((acc_1 + (checksum_93_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_93_2 > 16)
  {
    acc_2 = ((acc_2 + (checksum_93_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_93_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_21_1 == cursor_21_2);
  assert(checksum_93_1 == checksum_93_2);
}

int fn_R001064_6413_10(int p0, int p1)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int cursor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_21) & 63;
  acc ^= aux;
  int checksum_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_93 > 16)
  {
    acc = ((acc + (checksum_93 * 2)) + 5) & 127;
    aux ^= checksum_93 & 15;
  }
  else
  {
    acc = ((acc - checksum_93) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st_1 = {0};
  struct EventLog_R001064_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_40_1 = local_arr_1[aux_1 % 3];
  int quantum_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_40_2 * 2)) & 127;
  int index_reg_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_46_1)
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

  switch (index_reg_46_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_40_1 == quantum_40_2);
  assert(index_reg_46_1 == index_reg_46_2);
}

int fn_R001064_6413_11(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int quantum_40 = local_arr[aux % 3];
  acc = (acc + (quantum_40 * 2)) & 127;
  int index_reg_46 = (aux + st.buffer[1]) & 3;
  switch (index_reg_46)
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

void fn_R001064_6413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_77_1) & 63;
  aux_2 = (aux_2 + parity_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_21_1)
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

  switch (stride_21_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_77_1 == parity_77_2);
  assert(stride_21_1 == stride_21_2);
}

int fn_R001064_6413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_77) & 63;
  acc ^= aux;
  int stride_21 = (aux + st.buffer[1]) & 3;
  switch (stride_21)
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

void fn_R001064_6413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st_1 = {0};
  struct EventLog_R001064_6413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int accumulator_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_15_1) & 63;
  aux_2 = (aux_2 + accumulator_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_65_1 > 21)
  {
    acc_1 = ((acc_1 + (pivot_65_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_65_2 > 21)
  {
    acc_2 = ((acc_2 + (pivot_65_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_15_1 == accumulator_15_2);
  assert(pivot_65_1 == pivot_65_2);
}

int fn_R001064_6413_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001064_6413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int accumulator_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_15) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_65 > 21)
  {
    acc = ((acc + (pivot_65 * 2)) + 5) & 127;
    aux ^= pivot_65 & 15;
  }
  else
  {
    acc = ((acc - pivot_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001064_6413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001064_6413_3 st_1 = {0};
  struct StreamBuffer_R001064_6413_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int parity_55_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_55_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_55_1)
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

  switch (parity_55_2)
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

  int offset_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_13_1) & 63;
  aux_2 = (aux_2 + offset_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_55_1 == parity_55_2);
  assert(offset_13_1 == offset_13_2);
}

int fn_R001064_6413_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001064_6413_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int parity_55 = (aux + st.buffer[1]) & 3;
  switch (parity_55)
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

  int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001064_6413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st_1 = {0};
  struct AudioFrame_R001064_6413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int margin_80_1 = 0;
  int margin_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_80_1 = ((margin_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_80_2 = ((margin_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_80_1) & 127;
    acc_2 = (acc_2 + margin_80_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_83_1 = local_arr_1[aux_1 % 3];
  int margin_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_83_2 * 2)) & 127;
  int segment_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_72_1) & 63;
  aux_2 = (aux_2 + segment_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_69_1)
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

  switch (scale_69_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_80_1 == margin_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_83_1 == margin_83_2);
  assert(segment_72_1 == segment_72_2);
  assert(scale_69_1 == scale_69_2);
}

int fn_R001064_6413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001064_6413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int margin_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_80 = ((margin_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_80) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int margin_83 = local_arr[aux % 3];
  acc = (acc + (margin_83 * 2)) & 127;
  int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_72) & 63;
  acc ^= aux;
  int scale_69 = (aux + st.buffer[1]) & 3;
  switch (scale_69)
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

void main()
{
  int sec_r001064_0_1;
  int sec_r001064_0_2;
  int sec_r001064_1_1;
  int sec_r001064_1_2;
  int sec_r001064_2_1;
  int sec_r001064_2_2;
  int sec_r001064_3_1;
  int sec_r001064_3_2;
  int sec_r001064_4_1;
  int sec_r001064_4_2;
  int sec_r001064_5_1;
  int sec_r001064_5_2;
  int sec_r001064_6_1;
  int sec_r001064_6_2;
  int sec_r001064_7_1;
  int sec_r001064_7_2;
  int sec_r001064_8_1;
  int sec_r001064_8_2;
  int sec_r001064_9_1;
  int sec_r001064_9_2;
  int sec_r001064_10_1;
  int sec_r001064_10_2;
  int sec_r001064_11_1;
  int sec_r001064_11_2;
  int sec_r001064_12_1;
  int sec_r001064_12_2;
  int sec_r001064_13_1;
  int sec_r001064_13_2;
  int sec_r001064_14_1;
  int sec_r001064_14_2;
  int sec_r001064_15_1;
  int sec_r001064_15_2;
  int sec_r001064_16_1;
  int sec_r001064_16_2;
  int sec_r001064_17_1;
  int sec_r001064_17_2;
  int sec_r001064_18_1;
  int sec_r001064_18_2;
  int sec_r001064_19_1;
  int sec_r001064_19_2;
  int sec_r001064_20_1;
  int sec_r001064_20_2;
  int sec_r001064_21_1;
  int sec_r001064_21_2;
  int pub_r001064_0_1;
  int pub_r001064_0_2;
  int pub_r001064_1_1;
  int pub_r001064_1_2;
  int pub_r001064_2_1;
  int pub_r001064_2_2;
  int pub_r001064_3_1;
  int pub_r001064_3_2;
  int pub_r001064_4_1;
  int pub_r001064_4_2;
  int pub_r001064_5_1;
  int pub_r001064_5_2;
  int pub_r001064_6_1;
  int pub_r001064_6_2;
  int pub_r001064_7_1;
  int pub_r001064_7_2;
  int pub_r001064_8_1;
  int pub_r001064_8_2;
  int pub_r001064_9_1;
  int pub_r001064_9_2;
  int pub_r001064_10_1;
  int pub_r001064_10_2;
  int pub_r001064_11_1;
  int pub_r001064_11_2;
  int pub_r001064_12_1;
  int pub_r001064_12_2;
  int pub_r001064_13_1;
  int pub_r001064_13_2;
  int pub_r001064_14_1;
  int pub_r001064_14_2;
  int pub_r001064_15_1;
  int pub_r001064_15_2;
  int pub_r001064_16_1;
  int pub_r001064_16_2;
  int pub_r001064_17_1;
  int pub_r001064_17_2;
  int pub_r001064_18_1;
  int pub_r001064_18_2;
  int pub_r001064_19_1;
  int pub_r001064_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001064_0_1 >= (-100)) && (pub_r001064_0_1 <= 100));
  __CPROVER_assume((pub_r001064_0_2 >= (-100)) && (pub_r001064_0_2 <= 100));
  __CPROVER_assume((pub_r001064_1_1 >= (-100)) && (pub_r001064_1_1 <= 100));
  __CPROVER_assume((pub_r001064_1_2 >= (-100)) && (pub_r001064_1_2 <= 100));
  __CPROVER_assume((pub_r001064_2_1 >= (-100)) && (pub_r001064_2_1 <= 100));
  __CPROVER_assume((pub_r001064_2_2 >= (-100)) && (pub_r001064_2_2 <= 100));
  __CPROVER_assume((pub_r001064_3_1 >= (-100)) && (pub_r001064_3_1 <= 100));
  __CPROVER_assume((pub_r001064_3_2 >= (-100)) && (pub_r001064_3_2 <= 100));
  __CPROVER_assume((pub_r001064_4_1 >= (-100)) && (pub_r001064_4_1 <= 100));
  __CPROVER_assume((pub_r001064_4_2 >= (-100)) && (pub_r001064_4_2 <= 100));
  __CPROVER_assume((pub_r001064_5_1 >= (-100)) && (pub_r001064_5_1 <= 100));
  __CPROVER_assume((pub_r001064_5_2 >= (-100)) && (pub_r001064_5_2 <= 100));
  __CPROVER_assume((pub_r001064_6_1 >= (-100)) && (pub_r001064_6_1 <= 100));
  __CPROVER_assume((pub_r001064_6_2 >= (-100)) && (pub_r001064_6_2 <= 100));
  __CPROVER_assume((pub_r001064_7_1 >= (-100)) && (pub_r001064_7_1 <= 100));
  __CPROVER_assume((pub_r001064_7_2 >= (-100)) && (pub_r001064_7_2 <= 100));
  __CPROVER_assume((pub_r001064_8_1 >= (-100)) && (pub_r001064_8_1 <= 100));
  __CPROVER_assume((pub_r001064_8_2 >= (-100)) && (pub_r001064_8_2 <= 100));
  __CPROVER_assume((pub_r001064_9_1 >= (-100)) && (pub_r001064_9_1 <= 100));
  __CPROVER_assume((pub_r001064_9_2 >= (-100)) && (pub_r001064_9_2 <= 100));
  __CPROVER_assume((pub_r001064_10_1 >= (-100)) && (pub_r001064_10_1 <= 100));
  __CPROVER_assume((pub_r001064_10_2 >= (-100)) && (pub_r001064_10_2 <= 100));
  __CPROVER_assume((pub_r001064_11_1 >= (-100)) && (pub_r001064_11_1 <= 100));
  __CPROVER_assume((pub_r001064_11_2 >= (-100)) && (pub_r001064_11_2 <= 100));
  __CPROVER_assume((pub_r001064_12_1 >= (-100)) && (pub_r001064_12_1 <= 100));
  __CPROVER_assume((pub_r001064_12_2 >= (-100)) && (pub_r001064_12_2 <= 100));
  __CPROVER_assume((pub_r001064_13_1 >= (-100)) && (pub_r001064_13_1 <= 100));
  __CPROVER_assume((pub_r001064_13_2 >= (-100)) && (pub_r001064_13_2 <= 100));
  __CPROVER_assume((pub_r001064_14_1 >= (-100)) && (pub_r001064_14_1 <= 100));
  __CPROVER_assume((pub_r001064_14_2 >= (-100)) && (pub_r001064_14_2 <= 100));
  __CPROVER_assume((pub_r001064_15_1 >= (-100)) && (pub_r001064_15_1 <= 100));
  __CPROVER_assume((pub_r001064_15_2 >= (-100)) && (pub_r001064_15_2 <= 100));
  __CPROVER_assume((pub_r001064_16_1 >= (-100)) && (pub_r001064_16_1 <= 100));
  __CPROVER_assume((pub_r001064_16_2 >= (-100)) && (pub_r001064_16_2 <= 100));
  __CPROVER_assume((pub_r001064_17_1 >= (-100)) && (pub_r001064_17_1 <= 100));
  __CPROVER_assume((pub_r001064_17_2 >= (-100)) && (pub_r001064_17_2 <= 100));
  __CPROVER_assume((pub_r001064_18_1 >= (-100)) && (pub_r001064_18_1 <= 100));
  __CPROVER_assume((pub_r001064_18_2 >= (-100)) && (pub_r001064_18_2 <= 100));
  __CPROVER_assume((pub_r001064_19_1 >= (-100)) && (pub_r001064_19_1 <= 100));
  __CPROVER_assume((pub_r001064_19_2 >= (-100)) && (pub_r001064_19_2 <= 100));
  __CPROVER_assume((sec_r001064_0_1 >= 0) && (sec_r001064_0_1 <= 255));
  __CPROVER_assume((sec_r001064_0_2 >= 0) && (sec_r001064_0_2 <= 255));
  __CPROVER_assume((sec_r001064_1_1 >= 0) && (sec_r001064_1_1 <= 255));
  __CPROVER_assume((sec_r001064_1_2 >= 0) && (sec_r001064_1_2 <= 255));
  __CPROVER_assume((sec_r001064_2_1 >= 0) && (sec_r001064_2_1 <= 255));
  __CPROVER_assume((sec_r001064_2_2 >= 0) && (sec_r001064_2_2 <= 255));
  __CPROVER_assume((sec_r001064_3_1 >= 0) && (sec_r001064_3_1 <= 255));
  __CPROVER_assume((sec_r001064_3_2 >= 0) && (sec_r001064_3_2 <= 255));
  __CPROVER_assume((sec_r001064_4_1 >= 0) && (sec_r001064_4_1 <= 255));
  __CPROVER_assume((sec_r001064_4_2 >= 0) && (sec_r001064_4_2 <= 255));
  __CPROVER_assume((sec_r001064_5_1 >= 0) && (sec_r001064_5_1 <= 255));
  __CPROVER_assume((sec_r001064_5_2 >= 0) && (sec_r001064_5_2 <= 255));
  __CPROVER_assume((sec_r001064_6_1 >= 0) && (sec_r001064_6_1 <= 255));
  __CPROVER_assume((sec_r001064_6_2 >= 0) && (sec_r001064_6_2 <= 255));
  __CPROVER_assume((sec_r001064_7_1 >= 0) && (sec_r001064_7_1 <= 255));
  __CPROVER_assume((sec_r001064_7_2 >= 0) && (sec_r001064_7_2 <= 255));
  __CPROVER_assume((sec_r001064_8_1 >= 0) && (sec_r001064_8_1 <= 255));
  __CPROVER_assume((sec_r001064_8_2 >= 0) && (sec_r001064_8_2 <= 255));
  __CPROVER_assume((sec_r001064_9_1 >= 0) && (sec_r001064_9_1 <= 255));
  __CPROVER_assume((sec_r001064_9_2 >= 0) && (sec_r001064_9_2 <= 255));
  __CPROVER_assume((sec_r001064_10_1 >= 0) && (sec_r001064_10_1 <= 255));
  __CPROVER_assume((sec_r001064_10_2 >= 0) && (sec_r001064_10_2 <= 255));
  __CPROVER_assume((sec_r001064_11_1 >= 0) && (sec_r001064_11_1 <= 255));
  __CPROVER_assume((sec_r001064_11_2 >= 0) && (sec_r001064_11_2 <= 255));
  __CPROVER_assume((sec_r001064_12_1 >= 0) && (sec_r001064_12_1 <= 255));
  __CPROVER_assume((sec_r001064_12_2 >= 0) && (sec_r001064_12_2 <= 255));
  __CPROVER_assume((sec_r001064_13_1 >= 0) && (sec_r001064_13_1 <= 255));
  __CPROVER_assume((sec_r001064_13_2 >= 0) && (sec_r001064_13_2 <= 255));
  __CPROVER_assume((sec_r001064_14_1 >= 0) && (sec_r001064_14_1 <= 255));
  __CPROVER_assume((sec_r001064_14_2 >= 0) && (sec_r001064_14_2 <= 255));
  __CPROVER_assume((sec_r001064_15_1 >= 0) && (sec_r001064_15_1 <= 255));
  __CPROVER_assume((sec_r001064_15_2 >= 0) && (sec_r001064_15_2 <= 255));
  __CPROVER_assume((sec_r001064_16_1 >= 0) && (sec_r001064_16_1 <= 255));
  __CPROVER_assume((sec_r001064_16_2 >= 0) && (sec_r001064_16_2 <= 255));
  __CPROVER_assume((sec_r001064_17_1 >= 0) && (sec_r001064_17_1 <= 255));
  __CPROVER_assume((sec_r001064_17_2 >= 0) && (sec_r001064_17_2 <= 255));
  __CPROVER_assume((sec_r001064_18_1 >= 0) && (sec_r001064_18_1 <= 255));
  __CPROVER_assume((sec_r001064_18_2 >= 0) && (sec_r001064_18_2 <= 255));
  __CPROVER_assume((sec_r001064_19_1 >= 0) && (sec_r001064_19_1 <= 255));
  __CPROVER_assume((sec_r001064_19_2 >= 0) && (sec_r001064_19_2 <= 255));
  __CPROVER_assume((sec_r001064_20_1 >= 0) && (sec_r001064_20_1 <= 255));
  __CPROVER_assume((sec_r001064_20_2 >= 0) && (sec_r001064_20_2 <= 255));
  __CPROVER_assume((sec_r001064_21_1 >= 0) && (sec_r001064_21_1 <= 255));
  __CPROVER_assume((sec_r001064_21_2 >= 0) && (sec_r001064_21_2 <= 255));
  struct EventLog_R001064_6413_0 st_var_0_1 = {0};
  struct EventLog_R001064_6413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001064_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001064_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001064_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001064_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001064_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001064_0_2 + 7) & 15;
  struct AudioFrame_R001064_6413_1 st_var_1_1 = {0};
  struct AudioFrame_R001064_6413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001064_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001064_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001064_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001064_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001064_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001064_0_2 + 9) & 15;
  struct CipherContext_R001064_6413_2 st_var_2_1 = {0};
  struct CipherContext_R001064_6413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001064_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001064_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001064_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001064_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001064_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001064_0_2 + 11) & 15;
  struct StreamBuffer_R001064_6413_3 st_var_3_1 = {0};
  struct StreamBuffer_R001064_6413_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001064_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001064_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001064_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001064_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001064_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001064_0_2 + 13) & 15;
  union PacketPayload_R001064_6413_0 u_var_1;
  union PacketPayload_R001064_6413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001064_6413_0(sec_r001064_0_1, sec_r001064_1_1);
  int helper_flow_0_2 = fn_R001064_6413_0(sec_r001064_0_2, sec_r001064_1_2);
  fn_R001064_6413_0_2(sec_r001064_0_1, sec_r001064_1_1, sec_r001064_0_2, sec_r001064_1_2);
  int helper_flow_1_1 = fn_R001064_6413_1(sec_r001064_1_1, pub_r001064_2_1, pub_r001064_3_1, pub_r001064_4_1);
  int helper_flow_1_2 = fn_R001064_6413_1(sec_r001064_1_2, pub_r001064_2_2, pub_r001064_3_2, pub_r001064_4_2);
  fn_R001064_6413_1_2(sec_r001064_1_1, pub_r001064_2_1, pub_r001064_3_1, pub_r001064_4_1, sec_r001064_1_2, pub_r001064_2_2, pub_r001064_3_2, pub_r001064_4_2);
  int helper_flow_2_1 = fn_R001064_6413_2(sec_r001064_2_1, pub_r001064_3_1, pub_r001064_4_1, pub_r001064_5_1);
  int helper_flow_2_2 = fn_R001064_6413_2(sec_r001064_2_2, pub_r001064_3_2, pub_r001064_4_2, pub_r001064_5_2);
  fn_R001064_6413_2_2(sec_r001064_2_1, pub_r001064_3_1, pub_r001064_4_1, pub_r001064_5_1, sec_r001064_2_2, pub_r001064_3_2, pub_r001064_4_2, pub_r001064_5_2);
  int helper_flow_3_1 = fn_R001064_6413_3(sec_r001064_3_1, pub_r001064_4_1, pub_r001064_5_1, pub_r001064_6_1, pub_r001064_7_1);
  int helper_flow_3_2 = fn_R001064_6413_3(sec_r001064_3_2, pub_r001064_4_2, pub_r001064_5_2, pub_r001064_6_2, pub_r001064_7_2);
  fn_R001064_6413_3_2(sec_r001064_3_1, pub_r001064_4_1, pub_r001064_5_1, pub_r001064_6_1, pub_r001064_7_1, sec_r001064_3_2, pub_r001064_4_2, pub_r001064_5_2, pub_r001064_6_2, pub_r001064_7_2);
  int helper_flow_4_1 = fn_R001064_6413_4(sec_r001064_4_1, sec_r001064_5_1, pub_r001064_6_1, pub_r001064_7_1);
  int helper_flow_4_2 = fn_R001064_6413_4(sec_r001064_4_2, sec_r001064_5_2, pub_r001064_6_2, pub_r001064_7_2);
  fn_R001064_6413_4_2(sec_r001064_4_1, sec_r001064_5_1, pub_r001064_6_1, pub_r001064_7_1, sec_r001064_4_2, sec_r001064_5_2, pub_r001064_6_2, pub_r001064_7_2);
  int stage_v_0_1 = (((helper_flow_1_1 * 3) + pub_r001064_8_1) + 40) & 127;
  int stage_v_0_2 = (((helper_flow_1_2 * 3) + pub_r001064_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((helper_flow_3_1 * 3) + pub_r001064_6_1) + 16) & 127;
  int stage_v_1_2 = (((helper_flow_3_2 * 3) + pub_r001064_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001064_13_1 * 3) + pub_r001064_19_1) + 16) & 127;
  int stage_v_2_2 = (((sec_r001064_13_2 * 3) + pub_r001064_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001064_7_1 * 3) + pub_r001064_9_1) + 44) & 127;
  int stage_v_3_2 = (((sec_r001064_7_2 * 3) + pub_r001064_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((sec_r001064_12_1 * 3) + pub_r001064_18_1) + 9) & 127;
  int stage_v_4_2 = (((sec_r001064_12_2 * 3) + pub_r001064_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001064_5_1 * 2) + 18) & 63;
  int stage_v_5_2 = ((pub_r001064_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001064_13_1 * 2) + 37) & 63;
  int stage_v_6_2 = ((pub_r001064_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001064_15_1 * 3) + pub_r001064_0_1) + 15) & 127;
  int stage_v_7_2 = (((sec_r001064_15_2 * 3) + pub_r001064_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001064_3_1 * 2) + 8) & 63;
  int stage_v_8_2 = ((pub_r001064_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001064_17_1 * 2) + 34) & 63;
  int stage_v_9_2 = ((pub_r001064_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001064_10_1 * 3) + pub_r001064_1_1) + 10) & 127;
  int stage_v_10_2 = (((sec_r001064_10_2 * 3) + pub_r001064_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001064_7_1 * 2) + 35) & 63;
  int stage_v_11_2 = ((pub_r001064_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001064_4_1 * 2) + 34) & 63;
  int stage_v_12_2 = ((pub_r001064_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001064_5_1 * 3) + pub_r001064_14_1) + 13) & 127;
  int stage_v_13_2 = (((sec_r001064_5_2 * 3) + pub_r001064_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001064_4_1 * 3) + pub_r001064_19_1) + 21) & 127;
  int stage_v_14_2 = (((sec_r001064_4_2 * 3) + pub_r001064_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_0_1 * 3) + pub_r001064_2_1) + 32) & 127;
  int stage_v_15_2 = (((stage_v_0_2 * 3) + pub_r001064_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001064_18_1 * 2) + 33) & 63;
  int stage_v_16_2 = ((pub_r001064_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001064_4_1 * 2) + 50) & 63;
  int stage_v_17_2 = ((pub_r001064_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((sec_r001064_8_1 * 3) + pub_r001064_17_1) + 4) & 127;
  int stage_v_18_2 = (((sec_r001064_8_2 * 3) + pub_r001064_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((sec_r001064_21_1 * 3) + pub_r001064_8_1) + 23) & 127;
  int stage_v_19_2 = (((sec_r001064_21_2 * 3) + pub_r001064_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001064_18_1 * 2) + 5) & 63;
  int stage_v_20_2 = ((pub_r001064_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001064_0_1 * 2) + 11) & 63;
  int stage_v_21_2 = ((pub_r001064_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001064_12_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001064_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001064_15_1 * 2) + 34) & 63;
  int stage_v_23_2 = ((pub_r001064_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001064_16_1 * 2) + 31) & 63;
  int stage_v_24_2 = ((pub_r001064_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((stage_v_1_1 * 3) + pub_r001064_10_1) + 41) & 127;
  int stage_v_25_2 = (((stage_v_1_2 * 3) + pub_r001064_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001064_16_1 * 3) + pub_r001064_7_1) + 11) & 127;
  int stage_v_26_2 = (((sec_r001064_16_2 * 3) + pub_r001064_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001064_3_1 * 2) + 6) & 63;
  int stage_v_27_2 = ((pub_r001064_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001064_19_1 * 2) + 20) & 63;
  int stage_v_28_2 = ((pub_r001064_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001064_6_1 * 2) + 26) & 63;
  int stage_v_29_2 = ((pub_r001064_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_25_1 * 3) + pub_r001064_2_1) + 11) & 127;
  int stage_v_30_2 = (((stage_v_25_2 * 3) + pub_r001064_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001064_17_1 * 2) + 36) & 63;
  int stage_v_31_2 = ((pub_r001064_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001064_7_1 * 3) + pub_r001064_6_1) + 6) & 127;
  int stage_v_32_2 = (((sec_r001064_7_2 * 3) + pub_r001064_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001064_3_1 * 3) + pub_r001064_3_1) + 15) & 127;
  int stage_v_33_2 = (((sec_r001064_3_2 * 3) + pub_r001064_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001064_13_1 * 2) + 25) & 63;
  int stage_v_34_2 = ((pub_r001064_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_1_1 * 3) + pub_r001064_15_1) + 27) & 127;
  int stage_v_35_2 = (((stage_v_1_2 * 3) + pub_r001064_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_7_1 * 3) + pub_r001064_14_1) + 25) & 127;
  int stage_v_36_2 = (((stage_v_7_2 * 3) + pub_r001064_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((stage_v_4_1 * 3) + pub_r001064_3_1) + 33) & 127;
  int stage_v_37_2 = (((stage_v_4_2 * 3) + pub_r001064_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001064_7_1 * 2) + 20) & 63;
  int stage_v_38_2 = ((pub_r001064_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((stage_v_1_1 * 3) + pub_r001064_19_1) + 38) & 127;
  int stage_v_39_2 = (((stage_v_1_2 * 3) + pub_r001064_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((sec_r001064_3_1 * 3) + pub_r001064_6_1) + 18) & 127;
  int stage_v_40_2 = (((sec_r001064_3_2 * 3) + pub_r001064_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_13_1 * 3) + pub_r001064_11_1) + 6) & 127;
  int stage_v_41_2 = (((stage_v_13_2 * 3) + pub_r001064_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = ((pub_r001064_1_1 * 2) + 49) & 63;
  int stage_v_42_2 = ((pub_r001064_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((stage_v_2_1 * 3) + pub_r001064_3_1) + 6) & 127;
  int stage_v_43_2 = (((stage_v_2_2 * 3) + pub_r001064_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((sec_r001064_17_1 * 3) + pub_r001064_16_1) + 12) & 127;
  int stage_v_44_2 = (((sec_r001064_17_2 * 3) + pub_r001064_16_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001064_11_1 * 2) + 11) & 63;
  int stage_v_45_2 = ((pub_r001064_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001064_2_1 * 3) + pub_r001064_15_1) + 15) & 127;
  int stage_v_46_2 = (((sec_r001064_2_2 * 3) + pub_r001064_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001064_12_1 * 2) + 37) & 63;
  int stage_v_47_2 = ((pub_r001064_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_18_1 * 3) + pub_r001064_10_1) + 28) & 127;
  int stage_v_48_2 = (((stage_v_18_2 * 3) + pub_r001064_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001064_18_1 * 2) + 46) & 63;
  int stage_v_49_2 = ((pub_r001064_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001064_1_1 * 3) + pub_r001064_2_1) + 14) & 127;
  int stage_v_50_2 = (((sec_r001064_1_2 * 3) + pub_r001064_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((helper_flow_3_1 * 3) + pub_r001064_8_1) + 18) & 127;
  int stage_v_51_2 = (((helper_flow_3_2 * 3) + pub_r001064_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((stage_v_25_1 * 3) + pub_r001064_17_1) + 22) & 127;
  int stage_v_52_2 = (((stage_v_25_2 * 3) + pub_r001064_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001064_10_1 * 2) + 37) & 63;
  int stage_v_53_2 = ((pub_r001064_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001064_7_1 * 3) + pub_r001064_15_1) + 21) & 127;
  int stage_v_54_2 = (((sec_r001064_7_2 * 3) + pub_r001064_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((helper_flow_1_1 * 3) + pub_r001064_10_1) + 34) & 127;
  int stage_v_55_2 = (((helper_flow_1_2 * 3) + pub_r001064_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_10_1 * 3) + pub_r001064_11_1) + 32) & 127;
  int stage_v_56_2 = (((stage_v_10_2 * 3) + pub_r001064_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = ((pub_r001064_2_1 * 2) + 43) & 63;
  int stage_v_57_2 = ((pub_r001064_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_56_1 * 3) + pub_r001064_7_1) + 4) & 127;
  int stage_v_58_2 = (((stage_v_56_2 * 3) + pub_r001064_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((sec_r001064_8_1 * 3) + pub_r001064_4_1) + 38) & 127;
  int stage_v_59_2 = (((sec_r001064_8_2 * 3) + pub_r001064_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001064_17_1 * 2) + 9) & 63;
  int stage_v_60_2 = ((pub_r001064_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001064_7_1 * 2) + 15) & 63;
  int stage_v_61_2 = ((pub_r001064_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((helper_flow_3_1 * 3) + pub_r001064_7_1) + 21) & 127;
  int stage_v_62_2 = (((helper_flow_3_2 * 3) + pub_r001064_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001064_15_1 * 2) + 36) & 63;
  int stage_v_63_2 = ((pub_r001064_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_3_1 * 3) + pub_r001064_3_1) + 22) & 127;
  int stage_v_64_2 = (((stage_v_3_2 * 3) + pub_r001064_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_26_1 * 3) + pub_r001064_16_1) + 20) & 127;
  int stage_v_65_2 = (((stage_v_26_2 * 3) + pub_r001064_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((stage_v_36_1 * 3) + pub_r001064_8_1) + 4) & 127;
  int stage_v_66_2 = (((stage_v_36_2 * 3) + pub_r001064_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001064_13_1 * 3) + pub_r001064_15_1) + 23) & 127;
  int stage_v_67_2 = (((sec_r001064_13_2 * 3) + pub_r001064_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001064_12_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001064_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001064_17_1 * 2) + 25) & 63;
  int stage_v_69_2 = ((pub_r001064_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001064_5_1 * 3) + pub_r001064_18_1) + 41) & 127;
  int stage_v_70_2 = (((sec_r001064_5_2 * 3) + pub_r001064_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((stage_v_14_1 * 3) + pub_r001064_15_1) + 11) & 127;
  int stage_v_71_2 = (((stage_v_14_2 * 3) + pub_r001064_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001064_7_1 * 2) + 42) & 63;
  int stage_v_72_2 = ((pub_r001064_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001064_0_1 * 2) + 18) & 63;
  int stage_v_73_2 = ((pub_r001064_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001064_12_1 * 3) + pub_r001064_9_1) + 4) & 127;
  int stage_v_74_2 = (((sec_r001064_12_2 * 3) + pub_r001064_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_37_1 * 3) + pub_r001064_15_1) + 11) & 127;
  int stage_v_75_2 = (((stage_v_37_2 * 3) + pub_r001064_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001064_10_1 * 2) + 12) & 63;
  int stage_v_76_2 = ((pub_r001064_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001064_16_1 * 3) + pub_r001064_9_1) + 36) & 127;
  int stage_v_77_2 = (((sec_r001064_16_2 * 3) + pub_r001064_9_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001064_13_1 * 2) + 15) & 63;
  int stage_v_78_2 = ((pub_r001064_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001064_13_1 * 2) + 9) & 63;
  int stage_v_79_2 = ((pub_r001064_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001064_3_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001064_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_15_1 * 3) + pub_r001064_9_1) + 29) & 127;
  int stage_v_81_2 = (((stage_v_15_2 * 3) + pub_r001064_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_46_1 * 3) + pub_r001064_12_1) + 38) & 127;
  int stage_v_82_2 = (((stage_v_46_2 * 3) + pub_r001064_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001064_0_1 * 2) + 6) & 63;
  int stage_v_83_2 = ((pub_r001064_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_56_1 * 3) + pub_r001064_7_1) + 15) & 127;
  int stage_v_84_2 = (((stage_v_56_2 * 3) + pub_r001064_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001064_15_1 * 2) + 46) & 63;
  int stage_v_85_2 = ((pub_r001064_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001064_1_1 * 2) + 19) & 63;
  int stage_v_86_2 = ((pub_r001064_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_71_1 * 3) + pub_r001064_3_1) + 30) & 127;
  int stage_v_87_2 = (((stage_v_71_2 * 3) + pub_r001064_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_55_1 * 3) + pub_r001064_2_1) + 40) & 127;
  int stage_v_88_2 = (((stage_v_55_2 * 3) + pub_r001064_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001064_7_1 * 2) + 39) & 63;
  int stage_v_89_2 = ((pub_r001064_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_25_1 * 3) + pub_r001064_2_1) + 17) & 127;
  int stage_v_90_2 = (((stage_v_25_2 * 3) + pub_r001064_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((stage_v_66_1 * 3) + pub_r001064_12_1) + 18) & 127;
  int stage_v_91_2 = (((stage_v_66_2 * 3) + pub_r001064_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_37_1 * 3) + pub_r001064_16_1) + 28) & 127;
  int stage_v_92_2 = (((stage_v_37_2 * 3) + pub_r001064_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001064_2_1 * 2) + 23) & 63;
  int stage_v_93_2 = ((pub_r001064_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001064_8_1 * 2) + 14) & 63;
  int stage_v_94_2 = ((pub_r001064_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001064_3_1 * 2) + 28) & 63;
  int stage_v_95_2 = ((pub_r001064_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((sec_r001064_11_1 * 3) + pub_r001064_4_1) + 25) & 127;
  int stage_v_96_2 = (((sec_r001064_11_2 * 3) + pub_r001064_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001064_11_1 * 2) + 12) & 63;
  int stage_v_97_2 = ((pub_r001064_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_67_1 * 3) + pub_r001064_0_1) + 40) & 127;
  int stage_v_98_2 = (((stage_v_67_2 * 3) + pub_r001064_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((helper_flow_2_1 * 3) + pub_r001064_2_1) + 15) & 127;
  int stage_v_99_2 = (((helper_flow_2_2 * 3) + pub_r001064_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001064_9_1 * 2) + 14) & 63;
  int stage_v_100_2 = ((pub_r001064_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_37_1 * 3) + pub_r001064_5_1) + 8) & 127;
  int stage_v_101_2 = (((stage_v_37_2 * 3) + pub_r001064_5_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((sec_r001064_4_1 * 3) + pub_r001064_3_1) + 36) & 127;
  int stage_v_102_2 = (((sec_r001064_4_2 * 3) + pub_r001064_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001064_10_1 * 2) + 12) & 63;
  int stage_v_103_2 = ((pub_r001064_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_92_1 * 3) + pub_r001064_11_1) + 9) & 127;
  int stage_v_104_2 = (((stage_v_92_2 * 3) + pub_r001064_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001064_16_1 * 2) + 22) & 63;
  int stage_v_105_2 = ((pub_r001064_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001064_18_1 * 2) + 10) & 63;
  int stage_v_106_2 = ((pub_r001064_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001064_17_1 * 2) + 41) & 63;
  int stage_v_107_2 = ((pub_r001064_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001064_15_1 * 2) + 20) & 63;
  int stage_v_108_2 = ((pub_r001064_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((sec_r001064_18_1 * 3) + pub_r001064_17_1) + 23) & 127;
  int stage_v_109_2 = (((sec_r001064_18_2 * 3) + pub_r001064_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((sec_r001064_21_1 * 3) + pub_r001064_0_1) + 13) & 127;
  int stage_v_110_2 = (((sec_r001064_21_2 * 3) + pub_r001064_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_66_1 * 3) + pub_r001064_7_1) + 25) & 127;
  int stage_v_111_2 = (((stage_v_66_2 * 3) + pub_r001064_7_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001064_10_1 * 2) + 34) & 63;
  int stage_v_112_2 = ((pub_r001064_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001064_11_1 * 2) + 18) & 63;
  int stage_v_113_2 = ((pub_r001064_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001064_10_1 * 2) + 44) & 63;
  int stage_v_114_2 = ((pub_r001064_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001064_9_1 * 2) + 14) & 63;
  int stage_v_115_2 = ((pub_r001064_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001064_17_1 * 2) + 12) & 63;
  int stage_v_116_2 = ((pub_r001064_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001064_14_1 * 2) + 9) & 63;
  int stage_v_117_2 = ((pub_r001064_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001064_5_1 * 3) + pub_r001064_15_1) + 19) & 127;
  int stage_v_118_2 = (((sec_r001064_5_2 * 3) + pub_r001064_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001064_3_1 * 2) + 36) & 63;
  int stage_v_119_2 = ((pub_r001064_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001064_16_1 * 2) + 44) & 63;
  int stage_v_120_2 = ((pub_r001064_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = (((stage_v_30_1 * 3) + pub_r001064_16_1) + 24) & 127;
  int stage_v_121_2 = (((stage_v_30_2 * 3) + pub_r001064_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((sec_r001064_16_1 * 3) + pub_r001064_19_1) + 20) & 127;
  int stage_v_122_2 = (((sec_r001064_16_2 * 3) + pub_r001064_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001064_19_1 * 2) + 44) & 63;
  int stage_v_123_2 = ((pub_r001064_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((sec_r001064_3_1 * 3) + pub_r001064_2_1) + 29) & 127;
  int stage_v_124_2 = (((sec_r001064_3_2 * 3) + pub_r001064_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001064_5_1 * 2) + 18) & 63;
  int stage_v_125_2 = ((pub_r001064_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_44_1 * 3) + pub_r001064_13_1) + 12) & 127;
  int stage_v_126_2 = (((stage_v_44_2 * 3) + pub_r001064_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((stage_v_4_1 * 3) + pub_r001064_17_1) + 27) & 127;
  int stage_v_127_2 = (((stage_v_4_2 * 3) + pub_r001064_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = ((pub_r001064_18_1 * 2) + 11) & 63;
  int stage_v_128_2 = ((pub_r001064_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001064_13_1 * 2) + 36) & 63;
  int stage_v_129_2 = ((pub_r001064_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001064_0_1 * 2) + 40) & 63;
  int stage_v_130_2 = ((pub_r001064_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_127_1 * 3) + pub_r001064_13_1) + 13) & 127;
  int stage_v_131_2 = (((stage_v_127_2 * 3) + pub_r001064_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((stage_v_66_1 * 3) + pub_r001064_4_1) + 21) & 127;
  int stage_v_132_2 = (((stage_v_66_2 * 3) + pub_r001064_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_77_1 * 3) + pub_r001064_3_1) + 37) & 127;
  int stage_v_133_2 = (((stage_v_77_2 * 3) + pub_r001064_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_10_1 * 3) + pub_r001064_10_1) + 23) & 127;
  int stage_v_134_2 = (((stage_v_10_2 * 3) + pub_r001064_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001064_8_1 * 2) + 50) & 63;
  int stage_v_135_2 = ((pub_r001064_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((sec_r001064_11_1 * 3) + pub_r001064_13_1) + 29) & 127;
  int stage_v_136_2 = (((sec_r001064_11_2 * 3) + pub_r001064_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = ((pub_r001064_9_1 * 2) + 28) & 63;
  int stage_v_137_2 = ((pub_r001064_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((sec_r001064_9_1 * 3) + pub_r001064_16_1) + 30) & 127;
  int stage_v_138_2 = (((sec_r001064_9_2 * 3) + pub_r001064_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((stage_v_65_1 * 3) + pub_r001064_7_1) + 11) & 127;
  int stage_v_139_2 = (((stage_v_65_2 * 3) + pub_r001064_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001064_9_1 * 2) + 10) & 63;
  int stage_v_140_2 = ((pub_r001064_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_54_1 * 3) + pub_r001064_15_1) + 10) & 127;
  int stage_v_141_2 = (((stage_v_54_2 * 3) + pub_r001064_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = ((pub_r001064_4_1 * 2) + 14) & 63;
  int stage_v_142_2 = ((pub_r001064_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001064_1_1 * 2) + 35) & 63;
  int stage_v_143_2 = ((pub_r001064_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_132_1 * 3) + pub_r001064_16_1) + 37) & 127;
  int stage_v_144_2 = (((stage_v_132_2 * 3) + pub_r001064_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_90_1 * 3) + pub_r001064_0_1) + 40) & 127;
  int stage_v_145_2 = (((stage_v_90_2 * 3) + pub_r001064_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_67_1 * 3) + pub_r001064_7_1) + 5) & 127;
  int stage_v_146_2 = (((stage_v_67_2 * 3) + pub_r001064_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = ((pub_r001064_4_1 * 2) + 14) & 63;
  int stage_v_147_2 = ((pub_r001064_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_0_1 * 3) + pub_r001064_1_1) + 28) & 127;
  int stage_v_148_2 = (((stage_v_0_2 * 3) + pub_r001064_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_48_1 * 3) + pub_r001064_16_1) + 35) & 127;
  int stage_v_149_2 = (((stage_v_48_2 * 3) + pub_r001064_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_40_1 * 3) + pub_r001064_9_1) + 29) & 127;
  int stage_v_150_2 = (((stage_v_40_2 * 3) + pub_r001064_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = (((stage_v_64_1 * 3) + pub_r001064_8_1) + 18) & 127;
  int stage_v_151_2 = (((stage_v_64_2 * 3) + pub_r001064_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001064_10_1 * 2) + 45) & 63;
  int stage_v_152_2 = ((pub_r001064_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_136_1 * 3) + pub_r001064_14_1) + 37) & 127;
  int stage_v_153_2 = (((stage_v_136_2 * 3) + pub_r001064_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001064_18_1 * 2) + 16) & 63;
  int stage_v_154_2 = ((pub_r001064_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001064_13_1 * 2) + 22) & 63;
  int stage_v_155_2 = ((pub_r001064_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_146_1 * 3) + pub_r001064_15_1) + 15) & 127;
  int stage_v_156_2 = (((stage_v_146_2 * 3) + pub_r001064_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((sec_r001064_18_1 * 3) + pub_r001064_10_1) + 23) & 127;
  int stage_v_157_2 = (((sec_r001064_18_2 * 3) + pub_r001064_10_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_96_1 * 3) + pub_r001064_1_1) + 18) & 127;
  int stage_v_158_2 = (((stage_v_96_2 * 3) + pub_r001064_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_74_1 * 3) + pub_r001064_3_1) + 3) & 127;
  int stage_v_159_2 = (((stage_v_74_2 * 3) + pub_r001064_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = ((pub_r001064_19_1 * 2) + 32) & 63;
  int stage_v_160_2 = ((pub_r001064_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_65_1 * 3) + pub_r001064_18_1) + 33) & 127;
  int stage_v_161_2 = (((stage_v_65_2 * 3) + pub_r001064_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001064_14_1 * 2) + 33) & 63;
  int stage_v_162_2 = ((pub_r001064_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = (((sec_r001064_1_1 * 3) + pub_r001064_10_1) + 15) & 127;
  int stage_v_163_2 = (((sec_r001064_1_2 * 3) + pub_r001064_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((stage_v_15_1 * 3) + pub_r001064_2_1) + 42) & 127;
  int stage_v_164_2 = (((stage_v_15_2 * 3) + pub_r001064_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_64_1 * 3) + pub_r001064_19_1) + 13) & 127;
  int stage_v_165_2 = (((stage_v_64_2 * 3) + pub_r001064_19_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_35_1 * 3) + pub_r001064_10_1) + 26) & 127;
  int stage_v_166_2 = (((stage_v_35_2 * 3) + pub_r001064_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_166_1 * 3) + pub_r001064_5_1) + 32) & 127;
  int stage_v_167_2 = (((stage_v_166_2 * 3) + pub_r001064_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_127_1 * 3) + pub_r001064_0_1) + 42) & 127;
  int stage_v_168_2 = (((stage_v_127_2 * 3) + pub_r001064_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_126_1 * 3) + pub_r001064_14_1) + 15) & 127;
  int stage_v_169_2 = (((stage_v_126_2 * 3) + pub_r001064_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001064_2_1 * 2) + 34) & 63;
  int stage_v_170_2 = ((pub_r001064_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001064_10_1 * 2) + 20) & 63;
  int stage_v_171_2 = ((pub_r001064_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001064_1_1 * 2) + 46) & 63;
  int stage_v_172_2 = ((pub_r001064_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_77_1 * 3) + pub_r001064_9_1) + 15) & 127;
  int stage_v_173_2 = (((stage_v_77_2 * 3) + pub_r001064_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((sec_r001064_4_1 * 3) + pub_r001064_14_1) + 6) & 127;
  int stage_v_174_2 = (((sec_r001064_4_2 * 3) + pub_r001064_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001064_14_1 * 2) + 36) & 63;
  int stage_v_175_2 = ((pub_r001064_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = (((stage_v_43_1 * 3) + pub_r001064_7_1) + 13) & 127;
  int stage_v_176_2 = (((stage_v_43_2 * 3) + pub_r001064_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_110_1 * 3) + pub_r001064_11_1) + 17) & 127;
  int stage_v_177_2 = (((stage_v_110_2 * 3) + pub_r001064_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001064_12_1 * 2) + 30) & 63;
  int stage_v_178_2 = ((pub_r001064_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001064_14_1 * 2) + 20) & 63;
  int stage_v_179_2 = ((pub_r001064_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((sec_r001064_2_1 * 3) + pub_r001064_7_1) + 5) & 127;
  int stage_v_180_2 = (((sec_r001064_2_2 * 3) + pub_r001064_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_58_1 * 3) + pub_r001064_5_1) + 13) & 127;
  int stage_v_181_2 = (((stage_v_58_2 * 3) + pub_r001064_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001064_10_1 * 2) + 20) & 63;
  int stage_v_182_2 = ((pub_r001064_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_88_1 * 3) + pub_r001064_4_1) + 30) & 127;
  int stage_v_183_2 = (((stage_v_88_2 * 3) + pub_r001064_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_102_1 * 3) + pub_r001064_4_1) + 40) & 127;
  int stage_v_184_2 = (((stage_v_102_2 * 3) + pub_r001064_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = ((pub_r001064_7_1 * 2) + 38) & 63;
  int stage_v_185_2 = ((pub_r001064_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001064_1_1 * 2) + 27) & 63;
  int stage_v_186_2 = ((pub_r001064_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((sec_r001064_17_1 * 3) + pub_r001064_19_1) + 19) & 127;
  int stage_v_187_2 = (((sec_r001064_17_2 * 3) + pub_r001064_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_70_1 * 3) + pub_r001064_18_1) + 4) & 127;
  int stage_v_188_2 = (((stage_v_70_2 * 3) + pub_r001064_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001064_3_1 * 2) + 5) & 63;
  int stage_v_189_2 = ((pub_r001064_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_136_1 * 3) + pub_r001064_1_1) + 24) & 127;
  int stage_v_190_2 = (((stage_v_136_2 * 3) + pub_r001064_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_166_1 * 3) + pub_r001064_16_1) + 4) & 127;
  int stage_v_191_2 = (((stage_v_166_2 * 3) + pub_r001064_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001064_2_1 * 2) + 43) & 63;
  int stage_v_192_2 = ((pub_r001064_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((sec_r001064_17_1 * 3) + pub_r001064_14_1) + 40) & 127;
  int stage_v_193_2 = (((sec_r001064_17_2 * 3) + pub_r001064_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001064_12_1 * 2) + 37) & 63;
  int stage_v_194_2 = ((pub_r001064_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001064_0_1 * 2) + 9) & 63;
  int stage_v_195_2 = ((pub_r001064_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((stage_v_91_1 * 3) + pub_r001064_17_1) + 15) & 127;
  int stage_v_196_2 = (((stage_v_91_2 * 3) + pub_r001064_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_181_1 * 3) + pub_r001064_2_1) + 19) & 127;
  int stage_v_197_2 = (((stage_v_181_2 * 3) + pub_r001064_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001064_3_1 * 2) + 10) & 63;
  int stage_v_198_2 = ((pub_r001064_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_163_1 * 3) + pub_r001064_1_1) + 43) & 127;
  int stage_v_199_2 = (((stage_v_163_2 * 3) + pub_r001064_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_118_1 * 3) + pub_r001064_11_1) + 13) & 127;
  int stage_v_200_2 = (((stage_v_118_2 * 3) + pub_r001064_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_4_1 * 3) + pub_r001064_6_1) + 35) & 127;
  int stage_v_201_2 = (((stage_v_4_2 * 3) + pub_r001064_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001064_17_1 * 2) + 48) & 63;
  int stage_v_202_2 = ((pub_r001064_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001064_5_1 * 2) + 21) & 63;
  int stage_v_203_2 = ((pub_r001064_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_163_1 * 3) + pub_r001064_9_1) + 33) & 127;
  int stage_v_204_2 = (((stage_v_163_2 * 3) + pub_r001064_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001064_12_1 * 2) + 28) & 63;
  int stage_v_205_2 = ((pub_r001064_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001064_1_1 * 2) + 47) & 63;
  int stage_v_206_2 = ((pub_r001064_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_104_1 * 3) + pub_r001064_11_1) + 20) & 127;
  int stage_v_207_2 = (((stage_v_104_2 * 3) + pub_r001064_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001064_15_1 * 2) + 14) & 63;
  int stage_v_208_2 = ((pub_r001064_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001064_16_1 * 2) + 49) & 63;
  int stage_v_209_2 = ((pub_r001064_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((sec_r001064_18_1 * 3) + pub_r001064_9_1) + 25) & 127;
  int stage_v_210_2 = (((sec_r001064_18_2 * 3) + pub_r001064_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_104_1 * 3) + pub_r001064_16_1) + 22) & 127;
  int stage_v_211_2 = (((stage_v_104_2 * 3) + pub_r001064_16_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_165_1 * 3) + pub_r001064_13_1) + 8) & 127;
  int stage_v_212_2 = (((stage_v_165_2 * 3) + pub_r001064_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = ((pub_r001064_17_1 * 2) + 45) & 63;
  int stage_v_213_2 = ((pub_r001064_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_131_1 * 3) + pub_r001064_1_1) + 38) & 127;
  int stage_v_214_2 = (((stage_v_131_2 * 3) + pub_r001064_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_176_1 * 3) + pub_r001064_9_1) + 31) & 127;
  int stage_v_215_2 = (((stage_v_176_2 * 3) + pub_r001064_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_96_1 * 3) + pub_r001064_10_1) + 14) & 127;
  int stage_v_216_2 = (((stage_v_96_2 * 3) + pub_r001064_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001064_5_1 * 2) + 45) & 63;
  int stage_v_217_2 = ((pub_r001064_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((sec_r001064_12_1 * 3) + pub_r001064_7_1) + 3) & 127;
  int stage_v_218_2 = (((sec_r001064_12_2 * 3) + pub_r001064_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = ((pub_r001064_4_1 * 2) + 42) & 63;
  int stage_v_219_2 = ((pub_r001064_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_96_1 * 3) + pub_r001064_6_1) + 42) & 127;
  int stage_v_220_2 = (((stage_v_96_2 * 3) + pub_r001064_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001064_6_1 * 2) + 37) & 63;
  int stage_v_221_2 = ((pub_r001064_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001064_10_1 * 2) + 11) & 63;
  int stage_v_222_2 = ((pub_r001064_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_0_1 * 3) + pub_r001064_9_1) + 45) & 127;
  int stage_v_223_2 = (((stage_v_0_2 * 3) + pub_r001064_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001064_1_1 * 2) + 18) & 63;
  int stage_v_224_2 = ((pub_r001064_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_0_1 * 3) + pub_r001064_6_1) + 22) & 127;
  int stage_v_225_2 = (((stage_v_0_2 * 3) + pub_r001064_6_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_41_1 * 3) + pub_r001064_5_1) + 17) & 127;
  int stage_v_226_2 = (((stage_v_41_2 * 3) + pub_r001064_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_4_1 * 3) + pub_r001064_0_1) + 17) & 127;
  int stage_v_227_2 = (((stage_v_4_2 * 3) + pub_r001064_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001064_13_1 * 2) + 49) & 63;
  int stage_v_228_2 = ((pub_r001064_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001064_10_1 * 2) + 46) & 63;
  int stage_v_229_2 = ((pub_r001064_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001064_18_1 * 2) + 5) & 63;
  int stage_v_230_2 = ((pub_r001064_18_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001064_9_1 * 2) + 33) & 63;
  int stage_v_231_2 = ((pub_r001064_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_187_1 * 3) + pub_r001064_7_1) + 27) & 127;
  int stage_v_232_2 = (((stage_v_187_2 * 3) + pub_r001064_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001064_17_1 * 2) + 38) & 63;
  int stage_v_233_2 = ((pub_r001064_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001064_2_1 * 2) + 22) & 63;
  int stage_v_234_2 = ((pub_r001064_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_52_1 * 3) + pub_r001064_17_1) + 34) & 127;
  int stage_v_235_2 = (((stage_v_52_2 * 3) + pub_r001064_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_99_1 * 3) + pub_r001064_13_1) + 28) & 127;
  int stage_v_236_2 = (((stage_v_99_2 * 3) + pub_r001064_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001064_12_1 * 2) + 26) & 63;
  int stage_v_237_2 = ((pub_r001064_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_214_1 * 3) + pub_r001064_1_1) + 3) & 127;
  int stage_v_238_2 = (((stage_v_214_2 * 3) + pub_r001064_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001064_9_1 * 2) + 16) & 63;
  int stage_v_239_2 = ((pub_r001064_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_173_1 * 3) + pub_r001064_17_1) + 25) & 127;
  int stage_v_240_2 = (((stage_v_173_2 * 3) + pub_r001064_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001064_16_1 * 2) + 17) & 63;
  int stage_v_241_2 = ((pub_r001064_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_220_1 * 3) + pub_r001064_4_1) + 32) & 127;
  int stage_v_242_2 = (((stage_v_220_2 * 3) + pub_r001064_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_240_1 * 3) + pub_r001064_19_1) + 3) & 127;
  int stage_v_243_2 = (((stage_v_240_2 * 3) + pub_r001064_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_127_1 * 3) + pub_r001064_13_1) + 5) & 127;
  int stage_v_244_2 = (((stage_v_127_2 * 3) + pub_r001064_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_35_1 * 3) + pub_r001064_7_1) + 41) & 127;
  int stage_v_245_2 = (((stage_v_35_2 * 3) + pub_r001064_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_197_1 * 3) + pub_r001064_18_1) + 44) & 127;
  int stage_v_246_2 = (((stage_v_197_2 * 3) + pub_r001064_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((stage_v_14_1 * 3) + pub_r001064_16_1) + 44) & 127;
  int stage_v_247_2 = (((stage_v_14_2 * 3) + pub_r001064_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_188_1 * 3) + pub_r001064_11_1) + 5) & 127;
  int stage_v_248_2 = (((stage_v_188_2 * 3) + pub_r001064_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_235_1 * 3) + pub_r001064_16_1) + 38) & 127;
  int stage_v_249_2 = (((stage_v_235_2 * 3) + pub_r001064_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001064_18_1 * 2) + 43) & 63;
  int stage_v_250_2 = ((pub_r001064_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001064_8_1 * 2) + 31) & 63;
  int stage_v_251_2 = ((pub_r001064_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_133_1 * 3) + pub_r001064_14_1) + 16) & 127;
  int stage_v_252_2 = (((stage_v_133_2 * 3) + pub_r001064_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001064_3_1 * 2) + 16) & 63;
  int stage_v_253_2 = ((pub_r001064_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_184_1 * 3) + pub_r001064_19_1) + 30) & 127;
  int stage_v_254_2 = (((stage_v_184_2 * 3) + pub_r001064_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001064_7_1 * 2) + 30) & 63;
  int stage_v_255_2 = ((pub_r001064_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001064_10_1 * 2) + 35) & 63;
  int stage_v_256_2 = ((pub_r001064_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001064_0_1 * 2) + 43) & 63;
  int stage_v_257_2 = ((pub_r001064_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_122_1 * 3) + pub_r001064_4_1) + 25) & 127;
  int stage_v_258_2 = (((stage_v_122_2 * 3) + pub_r001064_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = ((pub_r001064_0_1 * 2) + 41) & 63;
  int stage_v_259_2 = ((pub_r001064_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_134_1 * 3) + pub_r001064_16_1) + 36) & 127;
  int stage_v_260_2 = (((stage_v_134_2 * 3) + pub_r001064_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_122_1 * 3) + pub_r001064_14_1) + 29) & 127;
  int stage_v_261_2 = (((stage_v_122_2 * 3) + pub_r001064_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001064_16_1 * 2) + 6) & 63;
  int stage_v_262_2 = ((pub_r001064_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_191_1 * 3) + pub_r001064_1_1) + 3) & 127;
  int stage_v_263_2 = (((stage_v_191_2 * 3) + pub_r001064_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001064_13_1 * 2) + 32) & 63;
  int stage_v_264_2 = ((pub_r001064_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001064_18_1 * 2) + 11) & 63;
  int stage_v_265_2 = ((pub_r001064_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_51_1 * 3) + pub_r001064_6_1) + 14) & 127;
  int stage_v_266_2 = (((stage_v_51_2 * 3) + pub_r001064_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((sec_r001064_0_1 * 3) + pub_r001064_0_1) + 31) & 127;
  int stage_v_267_2 = (((sec_r001064_0_2 * 3) + pub_r001064_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_48_1 * 3) + pub_r001064_17_1) + 34) & 127;
  int stage_v_268_2 = (((stage_v_48_2 * 3) + pub_r001064_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_210_1 * 3) + pub_r001064_8_1) + 36) & 127;
  int stage_v_269_2 = (((stage_v_210_2 * 3) + pub_r001064_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_157_1 * 3) + pub_r001064_8_1) + 25) & 127;
  int stage_v_270_2 = (((stage_v_157_2 * 3) + pub_r001064_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = (((stage_v_191_1 * 3) + pub_r001064_19_1) + 8) & 127;
  int stage_v_271_2 = (((stage_v_191_2 * 3) + pub_r001064_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((sec_r001064_19_1 * 3) + pub_r001064_17_1) + 45) & 127;
  int stage_v_272_2 = (((sec_r001064_19_2 * 3) + pub_r001064_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = ((pub_r001064_5_1 * 2) + 47) & 63;
  int stage_v_273_2 = ((pub_r001064_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = (((stage_v_212_1 * 3) + pub_r001064_1_1) + 33) & 127;
  int stage_v_274_2 = (((stage_v_212_2 * 3) + pub_r001064_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001064_8_1 * 2) + 28) & 63;
  int stage_v_275_2 = ((pub_r001064_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001064_14_1 * 2) + 30) & 63;
  int stage_v_276_2 = ((pub_r001064_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001064_15_1 * 2) + 26) & 63;
  int stage_v_277_2 = ((pub_r001064_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_272_1 * 3) + pub_r001064_12_1) + 27) & 127;
  int stage_v_278_2 = (((stage_v_272_2 * 3) + pub_r001064_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001064_8_1 * 2) + 17) & 63;
  int stage_v_279_2 = ((pub_r001064_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_210_1 * 3) + pub_r001064_16_1) + 10) & 127;
  int stage_v_280_2 = (((stage_v_210_2 * 3) + pub_r001064_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001064_16_1 * 2) + 42) & 63;
  int stage_v_281_2 = ((pub_r001064_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_41_1 * 3) + pub_r001064_9_1) + 45) & 127;
  int stage_v_282_2 = (((stage_v_41_2 * 3) + pub_r001064_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001064_12_1 * 2) + 25) & 63;
  int stage_v_283_2 = ((pub_r001064_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((stage_v_180_1 * 3) + pub_r001064_10_1) + 42) & 127;
  int stage_v_284_2 = (((stage_v_180_2 * 3) + pub_r001064_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_163_1 * 3) + pub_r001064_11_1) + 15) & 127;
  int stage_v_285_2 = (((stage_v_163_2 * 3) + pub_r001064_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = ((pub_r001064_1_1 * 2) + 23) & 63;
  int stage_v_286_2 = ((pub_r001064_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_40_1 * 3) + pub_r001064_19_1) + 28) & 127;
  int stage_v_287_2 = (((stage_v_40_2 * 3) + pub_r001064_19_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((stage_v_52_1 * 3) + pub_r001064_12_1) + 38) & 127;
  int stage_v_288_2 = (((stage_v_52_2 * 3) + pub_r001064_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_215_1 * 3) + pub_r001064_14_1) + 29) & 127;
  int stage_v_289_2 = (((stage_v_215_2 * 3) + pub_r001064_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_67_1 * 3) + pub_r001064_8_1) + 32) & 127;
  int stage_v_290_2 = (((stage_v_67_2 * 3) + pub_r001064_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_25_1 * 3) + pub_r001064_3_1) + 13) & 127;
  int stage_v_291_2 = (((stage_v_25_2 * 3) + pub_r001064_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001064_10_1 * 2) + 6) & 63;
  int stage_v_292_2 = ((pub_r001064_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_226_1 * 3) + pub_r001064_13_1) + 35) & 127;
  int stage_v_293_2 = (((stage_v_226_2 * 3) + pub_r001064_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001064_5_1 * 2) + 49) & 63;
  int stage_v_294_2 = ((pub_r001064_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_54_1 * 3) + pub_r001064_17_1) + 15) & 127;
  int stage_v_295_2 = (((stage_v_54_2 * 3) + pub_r001064_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_56_1 * 3) + pub_r001064_14_1) + 45) & 127;
  int stage_v_296_2 = (((stage_v_56_2 * 3) + pub_r001064_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_88_1 * 3) + pub_r001064_16_1) + 11) & 127;
  int stage_v_297_2 = (((stage_v_88_2 * 3) + pub_r001064_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_62_1 * 3) + pub_r001064_1_1) + 18) & 127;
  int stage_v_298_2 = (((stage_v_62_2 * 3) + pub_r001064_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001064_5_1 * 2) + 13) & 63;
  int stage_v_299_2 = ((pub_r001064_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001064_7_1 * 2) + 31) & 63;
  int stage_v_300_2 = ((pub_r001064_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001064_8_1 * 2) + 23) & 63;
  int stage_v_301_2 = ((pub_r001064_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001064_18_1 * 2) + 8) & 63;
  int stage_v_302_2 = ((pub_r001064_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_197_1 * 3) + pub_r001064_14_1) + 12) & 127;
  int stage_v_303_2 = (((stage_v_197_2 * 3) + pub_r001064_14_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001064_0_1 * 2) + 38) & 63;
  int stage_v_304_2 = ((pub_r001064_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001064_1_1 * 2) + 29) & 63;
  int stage_v_305_2 = ((pub_r001064_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001064_14_1 * 2) + 23) & 63;
  int stage_v_306_2 = ((pub_r001064_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001064_4_1 * 2) + 43) & 63;
  int stage_v_307_2 = ((pub_r001064_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_15_1 * 3) + pub_r001064_18_1) + 18) & 127;
  int stage_v_308_2 = (((stage_v_15_2 * 3) + pub_r001064_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001064_11_1 * 2) + 28) & 63;
  int stage_v_309_2 = ((pub_r001064_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001064_17_1 * 2) + 35) & 63;
  int stage_v_310_2 = ((pub_r001064_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001064_6_1 * 2) + 25) & 63;
  int stage_v_311_2 = ((pub_r001064_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001064_6_1 * 2) + 18) & 63;
  int stage_v_312_2 = ((pub_r001064_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((sec_r001064_4_1 * 3) + pub_r001064_12_1) + 40) & 127;
  int stage_v_313_2 = (((sec_r001064_4_2 * 3) + pub_r001064_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((sec_r001064_19_1 * 3) + pub_r001064_15_1) + 12) & 127;
  int stage_v_314_2 = (((sec_r001064_19_2 * 3) + pub_r001064_15_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001064_7_1 * 2) + 29) & 63;
  int stage_v_315_2 = ((pub_r001064_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_267_1 * 3) + pub_r001064_9_1) + 33) & 127;
  int stage_v_316_2 = (((stage_v_267_2 * 3) + pub_r001064_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001064_8_1 * 2) + 42) & 63;
  int stage_v_317_2 = ((pub_r001064_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_199_1 * 3) + pub_r001064_6_1) + 19) & 127;
  int stage_v_318_2 = (((stage_v_199_2 * 3) + pub_r001064_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001064_5_1 * 2) + 38) & 63;
  int stage_v_319_2 = ((pub_r001064_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_218_1 * 3) + pub_r001064_17_1) + 14) & 127;
  int stage_v_320_2 = (((stage_v_218_2 * 3) + pub_r001064_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_236_1 * 3) + pub_r001064_8_1) + 3) & 127;
  int stage_v_321_2 = (((stage_v_236_2 * 3) + pub_r001064_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_122_1 * 3) + pub_r001064_13_1) + 41) & 127;
  int stage_v_322_2 = (((stage_v_122_2 * 3) + pub_r001064_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_62_1 * 3) + pub_r001064_5_1) + 21) & 127;
  int stage_v_323_2 = (((stage_v_62_2 * 3) + pub_r001064_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_196_1 * 3) + pub_r001064_13_1) + 5) & 127;
  int stage_v_324_2 = (((stage_v_196_2 * 3) + pub_r001064_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_37_1 * 3) + pub_r001064_6_1) + 23) & 127;
  int stage_v_325_2 = (((stage_v_37_2 * 3) + pub_r001064_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_193_1 * 3) + pub_r001064_16_1) + 21) & 127;
  int stage_v_326_2 = (((stage_v_193_2 * 3) + pub_r001064_16_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001064_0_1 * 2) + 20) & 63;
  int stage_v_327_2 = ((pub_r001064_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001064_15_1 * 2) + 5) & 63;
  int stage_v_328_2 = ((pub_r001064_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001064_17_1 * 2) + 20) & 63;
  int stage_v_329_2 = ((pub_r001064_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001064_8_1 * 2) + 44) & 63;
  int stage_v_330_2 = ((pub_r001064_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((helper_flow_0_1 * 3) + pub_r001064_2_1) + 14) & 127;
  int stage_v_331_2 = (((helper_flow_0_2 * 3) + pub_r001064_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_225_1 * 3) + pub_r001064_7_1) + 6) & 127;
  int stage_v_332_2 = (((stage_v_225_2 * 3) + pub_r001064_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((sec_r001064_11_1 * 3) + pub_r001064_14_1) + 36) & 127;
  int stage_v_333_2 = (((sec_r001064_11_2 * 3) + pub_r001064_14_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = (((stage_v_4_1 * 3) + pub_r001064_6_1) + 4) & 127;
  int stage_v_334_2 = (((stage_v_4_2 * 3) + pub_r001064_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001064_1_1 * 2) + 8) & 63;
  int stage_v_335_2 = ((pub_r001064_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_62_1 * 3) + pub_r001064_15_1) + 15) & 127;
  int stage_v_336_2 = (((stage_v_62_2 * 3) + pub_r001064_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001064_14_1 * 2) + 41) & 63;
  int stage_v_337_2 = ((pub_r001064_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_199_1 * 3) + pub_r001064_7_1) + 28) & 127;
  int stage_v_338_2 = (((stage_v_199_2 * 3) + pub_r001064_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001064_1_1 * 2) + 33) & 63;
  int stage_v_339_2 = ((pub_r001064_1_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001064_16_1 * 2) + 17) & 63;
  int stage_v_340_2 = ((pub_r001064_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_258_1 * 3) + pub_r001064_15_1) + 9) & 127;
  int stage_v_341_2 = (((stage_v_258_2 * 3) + pub_r001064_15_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_30_1 * 3) + pub_r001064_1_1) + 25) & 127;
  int stage_v_342_2 = (((stage_v_30_2 * 3) + pub_r001064_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_13_1 * 3) + pub_r001064_7_1) + 4) & 127;
  int stage_v_343_2 = (((stage_v_13_2 * 3) + pub_r001064_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_212_1 * 3) + pub_r001064_7_1) + 20) & 127;
  int stage_v_344_2 = (((stage_v_212_2 * 3) + pub_r001064_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_320_1 * 3) + pub_r001064_17_1) + 42) & 127;
  int stage_v_345_2 = (((stage_v_320_2 * 3) + pub_r001064_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001064_0_1 * 2) + 28) & 63;
  int stage_v_346_2 = ((pub_r001064_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001064_12_1 * 2) + 48) & 63;
  int stage_v_347_2 = ((pub_r001064_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001064_11_1 * 2) + 38) & 63;
  int stage_v_348_2 = ((pub_r001064_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_238_1 * 3) + pub_r001064_10_1) + 45) & 127;
  int stage_v_349_2 = (((stage_v_238_2 * 3) + pub_r001064_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_243_1 * 3) + pub_r001064_15_1) + 27) & 127;
  int stage_v_350_2 = (((stage_v_243_2 * 3) + pub_r001064_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_87_1 * 3) + pub_r001064_2_1) + 17) & 127;
  int stage_v_351_2 = (((stage_v_87_2 * 3) + pub_r001064_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_344_1 * 3) + pub_r001064_1_1) + 30) & 127;
  int stage_v_352_2 = (((stage_v_344_2 * 3) + pub_r001064_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = ((pub_r001064_9_1 * 2) + 43) & 63;
  int stage_v_353_2 = ((pub_r001064_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_48_1 * 3) + pub_r001064_19_1) + 40) & 127;
  int stage_v_354_2 = (((stage_v_48_2 * 3) + pub_r001064_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001064_2_1 * 2) + 19) & 63;
  int stage_v_355_2 = ((pub_r001064_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001064_14_1 * 2) + 9) & 63;
  int stage_v_356_2 = ((pub_r001064_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001064_3_1 * 2) + 5) & 63;
  int stage_v_357_2 = ((pub_r001064_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001064_18_1 * 2) + 22) & 63;
  int stage_v_358_2 = ((pub_r001064_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001064_12_1 * 2) + 17) & 63;
  int stage_v_359_2 = ((pub_r001064_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001064_5_1 * 2) + 25) & 63;
  int stage_v_360_2 = ((pub_r001064_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001064_0_1 * 2) + 19) & 63;
  int stage_v_361_2 = ((pub_r001064_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_150_1 * 3) + pub_r001064_14_1) + 34) & 127;
  int stage_v_362_2 = (((stage_v_150_2 * 3) + pub_r001064_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001064_17_1 * 2) + 45) & 63;
  int stage_v_363_2 = ((pub_r001064_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001064_4_1 * 2) + 23) & 63;
  int stage_v_364_2 = ((pub_r001064_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001064_0_1 * 2) + 9) & 63;
  int stage_v_365_2 = ((pub_r001064_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_260_1 * 3) + pub_r001064_12_1) + 25) & 127;
  int stage_v_366_2 = (((stage_v_260_2 * 3) + pub_r001064_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((sec_r001064_14_1 * 3) + pub_r001064_8_1) + 15) & 127;
  int stage_v_367_2 = (((sec_r001064_14_2 * 3) + pub_r001064_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001064_0_1 * 2) + 34) & 63;
  int stage_v_368_2 = ((pub_r001064_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001064_19_1 * 2) + 27) & 63;
  int stage_v_369_2 = ((pub_r001064_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001064_1_1 * 2) + 18) & 63;
  int stage_v_370_2 = ((pub_r001064_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_324_1 * 3) + pub_r001064_12_1) + 26) & 127;
  int stage_v_371_2 = (((stage_v_324_2 * 3) + pub_r001064_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001064_18_1 * 2) + 18) & 63;
  int stage_v_372_2 = ((pub_r001064_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001064_6_1 * 2) + 22) & 63;
  int stage_v_373_2 = ((pub_r001064_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_252_1 * 3) + pub_r001064_3_1) + 14) & 127;
  int stage_v_374_2 = (((stage_v_252_2 * 3) + pub_r001064_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_131_1 * 3) + pub_r001064_6_1) + 3) & 127;
  int stage_v_375_2 = (((stage_v_131_2 * 3) + pub_r001064_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_153_1 * 3) + pub_r001064_12_1) + 13) & 127;
  int stage_v_376_2 = (((stage_v_153_2 * 3) + pub_r001064_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = (((stage_v_271_1 * 3) + pub_r001064_19_1) + 44) & 127;
  int stage_v_377_2 = (((stage_v_271_2 * 3) + pub_r001064_19_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001064_11_1 * 2) + 50) & 63;
  int stage_v_378_2 = ((pub_r001064_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_13_1 * 3) + pub_r001064_17_1) + 26) & 127;
  int stage_v_379_2 = (((stage_v_13_2 * 3) + pub_r001064_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001064_1_1 * 2) + 7) & 63;
  int stage_v_380_2 = ((pub_r001064_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001064_11_1 * 2) + 43) & 63;
  int stage_v_381_2 = ((pub_r001064_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_165_1 * 3) + pub_r001064_10_1) + 43) & 127;
  int stage_v_382_2 = (((stage_v_165_2 * 3) + pub_r001064_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001064_11_1 * 2) + 12) & 63;
  int stage_v_383_2 = ((pub_r001064_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001064_0_1 * 2) + 26) & 63;
  int stage_v_384_2 = ((pub_r001064_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_268_1 * 3) + pub_r001064_15_1) + 40) & 127;
  int stage_v_385_2 = (((stage_v_268_2 * 3) + pub_r001064_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_184_1 * 3) + pub_r001064_5_1) + 9) & 127;
  int stage_v_386_2 = (((stage_v_184_2 * 3) + pub_r001064_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_252_1 * 3) + pub_r001064_8_1) + 7) & 127;
  int stage_v_387_2 = (((stage_v_252_2 * 3) + pub_r001064_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001064_19_1 * 2) + 47) & 63;
  int stage_v_388_2 = ((pub_r001064_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((sec_r001064_21_1 * 3) + pub_r001064_16_1) + 17) & 127;
  int stage_v_389_2 = (((sec_r001064_21_2 * 3) + pub_r001064_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_184_1 * 3) + pub_r001064_19_1) + 9) & 127;
  int stage_v_390_2 = (((stage_v_184_2 * 3) + pub_r001064_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001064_17_1 * 2) + 22) & 63;
  int stage_v_391_2 = ((pub_r001064_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001064_6_1 * 2) + 28) & 63;
  int stage_v_392_2 = ((pub_r001064_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001064_9_1 * 2) + 43) & 63;
  int stage_v_393_2 = ((pub_r001064_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = (((sec_r001064_1_1 * 3) + pub_r001064_11_1) + 31) & 127;
  int stage_v_394_2 = (((sec_r001064_1_2 * 3) + pub_r001064_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001064_11_1 * 2) + 19) & 63;
  int stage_v_395_2 = ((pub_r001064_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001064_5_1 * 2) + 19) & 63;
  int stage_v_396_2 = ((pub_r001064_5_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001064_10_1 * 2) + 12) & 63;
  int stage_v_397_2 = ((pub_r001064_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_173_1 * 3) + pub_r001064_3_1) + 17) & 127;
  int stage_v_398_2 = (((stage_v_173_2 * 3) + pub_r001064_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_326_1 * 3) + pub_r001064_19_1) + 38) & 127;
  int stage_v_399_2 = (((stage_v_326_2 * 3) + pub_r001064_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001064_1_1 * 2) + 9) & 63;
  int stage_v_400_2 = ((pub_r001064_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_284_1 * 3) + pub_r001064_5_1) + 18) & 127;
  int stage_v_401_2 = (((stage_v_284_2 * 3) + pub_r001064_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001064_5_1 * 2) + 36) & 63;
  int stage_v_402_2 = ((pub_r001064_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001064_5_1 * 2) + 7) & 63;
  int stage_v_403_2 = ((pub_r001064_5_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_59_1 * 3) + pub_r001064_14_1) + 4) & 127;
  int stage_v_404_2 = (((stage_v_59_2 * 3) + pub_r001064_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001064_1_1 * 2) + 46) & 63;
  int stage_v_405_2 = ((pub_r001064_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((stage_v_48_1 * 3) + pub_r001064_1_1) + 23) & 127;
  int stage_v_406_2 = (((stage_v_48_2 * 3) + pub_r001064_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = (((stage_v_50_1 * 3) + pub_r001064_15_1) + 14) & 127;
  int stage_v_407_2 = (((stage_v_50_2 * 3) + pub_r001064_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_124_1 * 3) + pub_r001064_6_1) + 18) & 127;
  int stage_v_408_2 = (((stage_v_124_2 * 3) + pub_r001064_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((sec_r001064_14_1 * 3) + pub_r001064_6_1) + 23) & 127;
  int stage_v_409_2 = (((sec_r001064_14_2 * 3) + pub_r001064_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001064_8_1 * 2) + 45) & 63;
  int stage_v_410_2 = ((pub_r001064_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001064_2_1 * 2) + 45) & 63;
  int stage_v_411_2 = ((pub_r001064_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_145_1 * 3) + pub_r001064_7_1) + 20) & 127;
  int stage_v_412_2 = (((stage_v_145_2 * 3) + pub_r001064_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001064_4_1 * 2) + 16) & 63;
  int stage_v_413_2 = ((pub_r001064_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((stage_v_409_1 * 3) + pub_r001064_7_1) + 27) & 127;
  int stage_v_414_2 = (((stage_v_409_2 * 3) + pub_r001064_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001064_7_1 * 2) + 40) & 63;
  int stage_v_415_2 = ((pub_r001064_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_200_1 * 3) + pub_r001064_10_1) + 14) & 127;
  int stage_v_416_2 = (((stage_v_200_2 * 3) + pub_r001064_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_127_1 * 3) + pub_r001064_11_1) + 5) & 127;
  int stage_v_417_2 = (((stage_v_127_2 * 3) + pub_r001064_11_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001064_4_1 * 2) + 22) & 63;
  int stage_v_418_2 = ((pub_r001064_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_210_1 * 3) + pub_r001064_1_1) + 15) & 127;
  int stage_v_419_2 = (((stage_v_210_2 * 3) + pub_r001064_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_37_1 * 3) + pub_r001064_18_1) + 16) & 127;
  int stage_v_420_2 = (((stage_v_37_2 * 3) + pub_r001064_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_14_1 * 3) + pub_r001064_6_1) + 4) & 127;
  int stage_v_421_2 = (((stage_v_14_2 * 3) + pub_r001064_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_258_1 * 3) + pub_r001064_4_1) + 23) & 127;
  int stage_v_422_2 = (((stage_v_258_2 * 3) + pub_r001064_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001064_0_1 * 2) + 50) & 63;
  int stage_v_423_2 = ((pub_r001064_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001064_13_1 * 2) + 27) & 63;
  int stage_v_424_2 = ((pub_r001064_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_126_1 * 3) + pub_r001064_12_1) + 18) & 127;
  int stage_v_425_2 = (((stage_v_126_2 * 3) + pub_r001064_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001064_10_1 * 2) + 50) & 63;
  int stage_v_426_2 = ((pub_r001064_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_163_1 * 3) + pub_r001064_14_1) + 18) & 127;
  int stage_v_427_2 = (((stage_v_163_2 * 3) + pub_r001064_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001064_0_1 * 2) + 47) & 63;
  int stage_v_428_2 = ((pub_r001064_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001064_6_1 * 2) + 23) & 63;
  int stage_v_429_2 = ((pub_r001064_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_331_1 * 3) + pub_r001064_14_1) + 39) & 127;
  int stage_v_430_2 = (((stage_v_331_2 * 3) + pub_r001064_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((stage_v_43_1 * 3) + pub_r001064_10_1) + 25) & 127;
  int stage_v_431_2 = (((stage_v_43_2 * 3) + pub_r001064_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_122_1 * 3) + pub_r001064_14_1) + 16) & 127;
  int stage_v_432_2 = (((stage_v_122_2 * 3) + pub_r001064_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001064_12_1 * 2) + 43) & 63;
  int stage_v_433_2 = ((pub_r001064_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001064_9_1 * 2) + 16) & 63;
  int stage_v_434_2 = ((pub_r001064_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((stage_v_65_1 * 3) + pub_r001064_16_1) + 7) & 127;
  int stage_v_435_2 = (((stage_v_65_2 * 3) + pub_r001064_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = (((stage_v_124_1 * 3) + pub_r001064_11_1) + 29) & 127;
  int stage_v_436_2 = (((stage_v_124_2 * 3) + pub_r001064_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = ((pub_r001064_4_1 * 2) + 33) & 63;
  int stage_v_437_2 = ((pub_r001064_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = (((stage_v_406_1 * 3) + pub_r001064_15_1) + 31) & 127;
  int stage_v_438_2 = (((stage_v_406_2 * 3) + pub_r001064_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = (((stage_v_156_1 * 3) + pub_r001064_12_1) + 7) & 127;
  int stage_v_439_2 = (((stage_v_156_2 * 3) + pub_r001064_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001064_12_1 * 2) + 12) & 63;
  int stage_v_440_2 = ((pub_r001064_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001064_5_1 * 2) + 33) & 63;
  int stage_v_441_2 = ((pub_r001064_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((pub_r001064_6_1 * 2) + 10) & 63;
  int stage_v_442_2 = ((pub_r001064_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001064_11_1 * 2) + 44) & 63;
  int stage_v_443_2 = ((pub_r001064_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001064_7_1 * 2) + 45) & 63;
  int stage_v_444_2 = ((pub_r001064_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001064_2_1 * 2) + 48) & 63;
  int stage_v_445_2 = ((pub_r001064_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_382_1 * 3) + pub_r001064_13_1) + 43) & 127;
  int stage_v_446_2 = (((stage_v_382_2 * 3) + pub_r001064_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((sec_r001064_2_1 * 3) + pub_r001064_2_1) + 35) & 127;
  int stage_v_447_2 = (((sec_r001064_2_2 * 3) + pub_r001064_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_51_1 * 3) + pub_r001064_1_1) + 17) & 127;
  int stage_v_448_2 = (((stage_v_51_2 * 3) + pub_r001064_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = ((pub_r001064_13_1 * 2) + 5) & 63;
  int stage_v_449_2 = ((pub_r001064_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_272_1 * 3) + pub_r001064_10_1) + 25) & 127;
  int stage_v_450_2 = (((stage_v_272_2 * 3) + pub_r001064_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_165_1 * 3) + pub_r001064_5_1) + 41) & 127;
  int stage_v_451_2 = (((stage_v_165_2 * 3) + pub_r001064_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001064_18_1 * 2) + 23) & 63;
  int stage_v_452_2 = ((pub_r001064_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001064_4_1 * 2) + 34) & 63;
  int stage_v_453_2 = ((pub_r001064_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001064_11_1 * 2) + 50) & 63;
  int stage_v_454_2 = ((pub_r001064_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001064_12_1 * 2) + 44) & 63;
  int stage_v_455_2 = ((pub_r001064_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_168_1 * 3) + pub_r001064_11_1) + 18) & 127;
  int stage_v_456_2 = (((stage_v_168_2 * 3) + pub_r001064_11_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001064_18_1 * 2) + 41) & 63;
  int stage_v_457_2 = ((pub_r001064_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = (((stage_v_66_1 * 3) + pub_r001064_5_1) + 44) & 127;
  int stage_v_458_2 = (((stage_v_66_2 * 3) + pub_r001064_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((helper_flow_4_1 * 3) + pub_r001064_15_1) + 37) & 127;
  int stage_v_459_2 = (((helper_flow_4_2 * 3) + pub_r001064_15_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001064_19_1 * 2) + 32) & 63;
  int stage_v_460_2 = ((pub_r001064_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = (((stage_v_174_1 * 3) + pub_r001064_18_1) + 12) & 127;
  int stage_v_461_2 = (((stage_v_174_2 * 3) + pub_r001064_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = ((pub_r001064_10_1 * 2) + 23) & 63;
  int stage_v_462_2 = ((pub_r001064_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((stage_v_124_1 * 3) + pub_r001064_18_1) + 39) & 127;
  int stage_v_463_2 = (((stage_v_124_2 * 3) + pub_r001064_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001064_15_1 * 2) + 36) & 63;
  int stage_v_464_2 = ((pub_r001064_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = (((stage_v_245_1 * 3) + pub_r001064_13_1) + 17) & 127;
  int stage_v_465_2 = (((stage_v_245_2 * 3) + pub_r001064_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = ((pub_r001064_0_1 * 2) + 29) & 63;
  int stage_v_466_2 = ((pub_r001064_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((pub_r001064_13_1 * 2) + 8) & 63;
  int stage_v_467_2 = ((pub_r001064_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_92_1 * 3) + pub_r001064_12_1) + 10) & 127;
  int stage_v_468_2 = (((stage_v_92_2 * 3) + pub_r001064_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001064_3_1 * 2) + 32) & 63;
  int stage_v_469_2 = ((pub_r001064_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_184_1 * 3) + pub_r001064_12_1) + 13) & 127;
  int stage_v_470_2 = (((stage_v_184_2 * 3) + pub_r001064_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001064_7_1 * 2) + 34) & 63;
  int stage_v_471_2 = ((pub_r001064_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = (((stage_v_245_1 * 3) + pub_r001064_11_1) + 21) & 127;
  int stage_v_472_2 = (((stage_v_245_2 * 3) + pub_r001064_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = (((stage_v_109_1 * 3) + pub_r001064_8_1) + 42) & 127;
  int stage_v_473_2 = (((stage_v_109_2 * 3) + pub_r001064_8_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = (((sec_r001064_4_1 * 3) + pub_r001064_15_1) + 19) & 127;
  int stage_v_474_2 = (((sec_r001064_4_2 * 3) + pub_r001064_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((stage_v_320_1 * 3) + pub_r001064_7_1) + 14) & 127;
  int stage_v_475_2 = (((stage_v_320_2 * 3) + pub_r001064_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = (((stage_v_134_1 * 3) + pub_r001064_16_1) + 28) & 127;
  int stage_v_476_2 = (((stage_v_134_2 * 3) + pub_r001064_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_133_1 * 3) + pub_r001064_5_1) + 30) & 127;
  int stage_v_477_2 = (((stage_v_133_2 * 3) + pub_r001064_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001064_16_1 * 2) + 45) & 63;
  int stage_v_478_2 = ((pub_r001064_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001064_14_1 * 2) + 40) & 63;
  int stage_v_479_2 = ((pub_r001064_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = (((stage_v_414_1 * 3) + pub_r001064_6_1) + 30) & 127;
  int stage_v_480_2 = (((stage_v_414_2 * 3) + pub_r001064_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = ((pub_r001064_9_1 * 2) + 20) & 63;
  int stage_v_481_2 = ((pub_r001064_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = (((stage_v_252_1 * 3) + pub_r001064_19_1) + 39) & 127;
  int stage_v_482_2 = (((stage_v_252_2 * 3) + pub_r001064_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_482_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_482_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_482_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_482_2 * 2)) & 255;
  int stage_v_483_1 = ((pub_r001064_0_1 * 2) + 23) & 63;
  int stage_v_483_2 = ((pub_r001064_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = (((stage_v_174_1 * 3) + pub_r001064_8_1) + 34) & 127;
  int stage_v_484_2 = (((stage_v_174_2 * 3) + pub_r001064_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  int stage_v_485_1 = (((stage_v_133_1 * 3) + pub_r001064_1_1) + 3) & 127;
  int stage_v_485_2 = (((stage_v_133_2 * 3) + pub_r001064_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = (((stage_v_204_1 * 3) + pub_r001064_3_1) + 14) & 127;
  int stage_v_486_2 = (((stage_v_204_2 * 3) + pub_r001064_3_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = (((stage_v_254_1 * 3) + pub_r001064_13_1) + 5) & 127;
  int stage_v_487_2 = (((stage_v_254_2 * 3) + pub_r001064_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_487_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_487_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_487_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_487_2 * 2)) & 255;
  int stage_v_488_1 = (((stage_v_271_1 * 3) + pub_r001064_1_1) + 40) & 127;
  int stage_v_488_2 = (((stage_v_271_2 * 3) + pub_r001064_1_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = (((stage_v_36_1 * 3) + pub_r001064_4_1) + 38) & 127;
  int stage_v_489_2 = (((stage_v_36_2 * 3) + pub_r001064_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_489_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_489_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_489_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_489_2 * 2)) & 255;
  int stage_v_490_1 = (((stage_v_401_1 * 3) + pub_r001064_15_1) + 35) & 127;
  int stage_v_490_2 = (((stage_v_401_2 * 3) + pub_r001064_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = (((stage_v_385_1 * 3) + pub_r001064_9_1) + 18) & 127;
  int stage_v_491_2 = (((stage_v_385_2 * 3) + pub_r001064_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_491_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_491_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_491_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_491_2 * 2)) & 255;
  int stage_v_492_1 = (((stage_v_491_1 * 3) + pub_r001064_8_1) + 13) & 127;
  int stage_v_492_2 = (((stage_v_491_2 * 3) + pub_r001064_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = ((pub_r001064_17_1 * 2) + 40) & 63;
  int stage_v_493_2 = ((pub_r001064_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = ((pub_r001064_7_1 * 2) + 6) & 63;
  int stage_v_494_2 = ((pub_r001064_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_494_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_494_2) & 127;
  int stage_v_495_1 = ((pub_r001064_2_1 * 2) + 20) & 63;
  int stage_v_495_2 = ((pub_r001064_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001064_19_1 == pub_r001064_19_2);
  __CPROVER_assume(sec_r001064_0_1 != sec_r001064_0_2);
  __CPROVER_assume(sec_r001064_8_1 != sec_r001064_8_2);
  __CPROVER_assume(pub_r001064_8_1 == pub_r001064_8_2);
  __CPROVER_assume(sec_r001064_4_1 != sec_r001064_4_2);
  __CPROVER_assume(pub_r001064_0_1 == pub_r001064_0_2);
  __CPROVER_assume(sec_r001064_13_1 != sec_r001064_13_2);
  __CPROVER_assume(sec_r001064_11_1 != sec_r001064_11_2);
  __CPROVER_assume(pub_r001064_2_1 == pub_r001064_2_2);
  __CPROVER_assume(sec_r001064_10_1 != sec_r001064_10_2);
  __CPROVER_assume(pub_r001064_5_1 == pub_r001064_5_2);
  __CPROVER_assume(sec_r001064_12_1 != sec_r001064_12_2);
  __CPROVER_assume(sec_r001064_5_1 != sec_r001064_5_2);
  __CPROVER_assume(sec_r001064_17_1 != sec_r001064_17_2);
  __CPROVER_assume(sec_r001064_18_1 != sec_r001064_18_2);
  __CPROVER_assume(sec_r001064_9_1 != sec_r001064_9_2);
  __CPROVER_assume(pub_r001064_9_1 == pub_r001064_9_2);
  __CPROVER_assume(pub_r001064_12_1 == pub_r001064_12_2);
  __CPROVER_assume(pub_r001064_4_1 == pub_r001064_4_2);
  __CPROVER_assume(sec_r001064_16_1 != sec_r001064_16_2);
  __CPROVER_assume(pub_r001064_15_1 == pub_r001064_15_2);
  __CPROVER_assume(pub_r001064_11_1 == pub_r001064_11_2);
  __CPROVER_assume(sec_r001064_14_1 != sec_r001064_14_2);
  __CPROVER_assume(sec_r001064_19_1 != sec_r001064_19_2);
  __CPROVER_assume(sec_r001064_3_1 != sec_r001064_3_2);
  __CPROVER_assume(pub_r001064_3_1 == pub_r001064_3_2);
  __CPROVER_assume(pub_r001064_14_1 == pub_r001064_14_2);
  __CPROVER_assume(pub_r001064_10_1 == pub_r001064_10_2);
  __CPROVER_assume(sec_r001064_7_1 != sec_r001064_7_2);
  __CPROVER_assume(pub_r001064_18_1 == pub_r001064_18_2);
  __CPROVER_assume(sec_r001064_20_1 != sec_r001064_20_2);
  __CPROVER_assume(pub_r001064_7_1 == pub_r001064_7_2);
  __CPROVER_assume(pub_r001064_17_1 == pub_r001064_17_2);
  __CPROVER_assume(sec_r001064_6_1 != sec_r001064_6_2);
  __CPROVER_assume(sec_r001064_2_1 != sec_r001064_2_2);
  __CPROVER_assume(pub_r001064_16_1 == pub_r001064_16_2);
  __CPROVER_assume(pub_r001064_1_1 == pub_r001064_1_2);
  __CPROVER_assume(sec_r001064_1_1 != sec_r001064_1_2);
  __CPROVER_assume(sec_r001064_21_1 != sec_r001064_21_2);
  __CPROVER_assume(pub_r001064_13_1 == pub_r001064_13_2);
  __CPROVER_assume(sec_r001064_15_1 != sec_r001064_15_2);
  __CPROVER_assume(pub_r001064_6_1 == pub_r001064_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.iv == st_var_2_2.iv);
  assert(st_var_2_1.flags == st_var_2_2.flags);
  assert(st_var_2_1.counter == st_var_2_2.counter);
  assert(st_var_2_1.nonce == st_var_2_2.nonce);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.state == st_var_3_2.state);
  assert(st_var_3_1.tail == st_var_3_2.tail);
  assert(st_var_3_1.head == st_var_3_2.head);
  assert(st_var_3_1.watermark == st_var_3_2.watermark);
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
  assert(stage_v_463_1 == stage_v_463_2);
  assert(stage_v_464_1 == stage_v_464_2);
  assert(stage_v_465_1 == stage_v_465_2);
  assert(stage_v_466_1 == stage_v_466_2);
  assert(stage_v_467_1 == stage_v_467_2);
  assert(stage_v_468_1 == stage_v_468_2);
  assert(stage_v_469_1 == stage_v_469_2);
  assert(stage_v_470_1 == stage_v_470_2);
  assert(stage_v_471_1 == stage_v_471_2);
  assert(stage_v_472_1 == stage_v_472_2);
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
}


