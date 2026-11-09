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
struct DeviceConfig_R001834_3413_0
{
  short baud_rate;
  unsigned char stop_bits;
  unsigned char timeout;
  int port;
  short parity;
  int id;
  int buffer[3];
};
struct AudioFrame_R001834_3413_1
{
  unsigned char peak;
  int sample_rate;
  unsigned char envelope;
  unsigned char channels;
  unsigned char gain;
  int buffer[3];
};
struct FilterState_R001834_3413_2
{
  int cutoff;
  int mode;
  unsigned char gain_db;
  int prev_in;
  int prev_out;
  int buffer[3];
};
union PacketPayload_R001834_3413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001834_3413_1
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
void fn_R001834_3413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_58_1 = 0;
  int segment_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_58_1 = ((segment_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_58_2 = ((segment_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_58_1) & 127;
    acc_2 = (acc_2 + segment_58_2) & 127;
  }

  int accumulator_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_80_1)
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

  switch (accumulator_80_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_58_1 == segment_58_2);
  assert(accumulator_80_1 == accumulator_80_2);
}

int fn_R001834_3413_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_58 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_58 = ((segment_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_58) & 127;
  }

  int accumulator_80 = (aux + st.buffer[1]) & 3;
  switch (accumulator_80)
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

void fn_R001834_3413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int offset_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_57_1) & 63;
  aux_2 = (aux_2 + offset_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_73_1 > 38)
  {
    acc_1 = ((acc_1 + (scale_73_1 * 2)) + 5) & 127;
    aux_1 ^= scale_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_73_2 > 38)
  {
    acc_2 = ((acc_2 + (scale_73_2 * 2)) + 5) & 127;
    aux_2 ^= scale_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_73_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_89_1)
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

  switch (factor_89_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_57_1 == offset_57_2);
  assert(scale_73_1 == scale_73_2);
  assert(factor_89_1 == factor_89_2);
}

int fn_R001834_3413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int offset_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_57) & 63;
  acc ^= aux;
  int scale_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_73 > 38)
  {
    acc = ((acc + (scale_73 * 2)) + 5) & 127;
    aux ^= scale_73 & 15;
  }
  else
  {
    acc = ((acc - scale_73) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_89 = (aux + st.buffer[1]) & 3;
  switch (factor_89)
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

void fn_R001834_3413_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_90_1 > 41)
  {
    acc_1 = ((acc_1 + (window_90_1 * 2)) + 5) & 127;
    aux_1 ^= window_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_90_2 > 41)
  {
    acc_2 = ((acc_2 + (window_90_2 * 2)) + 5) & 127;
    aux_2 ^= window_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_90_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_25_1) & 63;
  aux_2 = (aux_2 + residue_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_90_1 = local_arr_1[aux_1 % 3];
  int margin_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_90_1 == window_90_2);
  assert(residue_25_1 == residue_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_90_1 == margin_90_2);
}

int fn_R001834_3413_2(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_90 > 41)
  {
    acc = ((acc + (window_90 * 2)) + 5) & 127;
    aux ^= window_90 & 15;
  }
  else
  {
    acc = ((acc - window_90) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_90 = local_arr[aux % 3];
  acc = (acc + (margin_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001834_3413_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_53_1 = 0;
  int cursor_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_53_1 = ((cursor_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_53_2 = ((cursor_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_53_1) & 127;
    acc_2 = (acc_2 + cursor_53_2) & 127;
  }

  int phase_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_81_1) & 63;
  aux_2 = (aux_2 + phase_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_53_1 == cursor_53_2);
  assert(phase_81_1 == phase_81_2);
}

int fn_R001834_3413_3(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_53 = ((cursor_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_53) & 127;
  }

  int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_81) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001834_3413_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_89_1 = local_arr_1[aux_1 % 3];
  int anchor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_89_2 * 2)) & 127;
  int parity_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_84_1)
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

  switch (parity_84_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_89_1 == anchor_89_2);
  assert(parity_84_1 == parity_84_2);
}

int fn_R001834_3413_4(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int anchor_89 = local_arr[aux % 3];
  acc = (acc + (anchor_89 * 2)) & 127;
  int parity_84 = (aux + st.buffer[1]) & 3;
  switch (parity_84)
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

void fn_R001834_3413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
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
  int coefficient_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_38_1)
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

  switch (coefficient_38_2)
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

  int parity_91_1 = 0;
  int parity_91_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_91_1 = ((parity_91_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_91_2 = ((parity_91_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_91_1) & 127;
    acc_2 = (acc_2 + parity_91_2) & 127;
  }

  int index_reg_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_37_1 > 20)
  {
    acc_1 = ((acc_1 + (index_reg_37_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_37_2 > 20)
  {
    acc_2 = ((acc_2 + (index_reg_37_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_38_1 == coefficient_38_2);
  assert(parity_91_1 == parity_91_2);
  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R001834_3413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_38 = (aux + st.buffer[1]) & 3;
  switch (coefficient_38)
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

  int parity_91 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_91 = ((parity_91 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_91) & 127;
  }

  int index_reg_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_37 > 20)
  {
    acc = ((acc + (index_reg_37 * 2)) + 5) & 127;
    aux ^= index_reg_37 & 15;
  }
  else
  {
    acc = ((acc - index_reg_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int index_reg_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_66_1) & 63;
  aux_2 = (aux_2 + index_reg_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_98_1 > 43)
  {
    acc_1 = ((acc_1 + (phase_98_1 * 2)) + 5) & 127;
    aux_1 ^= phase_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_98_2 > 43)
  {
    acc_2 = ((acc_2 + (phase_98_2 * 2)) + 5) & 127;
    aux_2 ^= phase_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_63_1 = local_arr_1[aux_1 % 3];
  int mask_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_66_1 == index_reg_66_2);
  assert(phase_98_1 == phase_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_63_1 == mask_63_2);
}

int fn_R001834_3413_6(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int index_reg_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_66) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_98 > 43)
  {
    acc = ((acc + (phase_98 * 2)) + 5) & 127;
    aux ^= phase_98 & 15;
  }
  else
  {
    acc = ((acc - phase_98) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_63 = local_arr[aux % 3];
  acc = (acc + (mask_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001834_3413_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_77_1 = local_arr_1[aux_1 % 3];
  int margin_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_77_2 * 2)) & 127;
  int window_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_51_1 > 43)
  {
    acc_1 = ((acc_1 + (window_51_1 * 2)) + 5) & 127;
    aux_1 ^= window_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_51_2 > 43)
  {
    acc_2 = ((acc_2 + (window_51_2 * 2)) + 5) & 127;
    aux_2 ^= window_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_77_1 == margin_77_2);
  assert(window_51_1 == window_51_2);
}

int fn_R001834_3413_7(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int margin_77 = local_arr[aux % 3];
  acc = (acc + (margin_77 * 2)) & 127;
  int window_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_51 > 43)
  {
    acc = ((acc + (window_51 * 2)) + 5) & 127;
    aux ^= window_51 & 15;
  }
  else
  {
    acc = ((acc - window_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int parity_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_26_1)
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

  switch (parity_26_2)
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

  int phase_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_29_1) & 63;
  aux_2 = (aux_2 + phase_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_26_1 == parity_26_2);
  assert(phase_29_1 == phase_29_2);
}

int fn_R001834_3413_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int parity_26 = (aux + st.buffer[1]) & 3;
  switch (parity_26)
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

  int phase_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_29) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001834_3413_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st_1 = {0};
  struct FilterState_R001834_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int damping_35_1 = 0;
  int damping_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_35_1 = ((damping_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_35_2 = ((damping_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_35_1) & 127;
    acc_2 = (acc_2 + damping_35_2) & 127;
  }

  int margin_64_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_64_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_64_1) & 63;
  aux_2 = (aux_2 + margin_64_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_74_1 = local_arr_1[aux_1 % 3];
  int sample_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_74_2 * 2)) & 127;
  int checksum_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_53_1 > 18)
  {
    acc_1 = ((acc_1 + (checksum_53_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_53_2 > 18)
  {
    acc_2 = ((acc_2 + (checksum_53_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_35_1 == damping_35_2);
  assert(margin_64_1 == margin_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_74_1 == sample_74_2);
  assert(checksum_53_1 == checksum_53_2);
}

int fn_R001834_3413_9(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int damping_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_35 = ((damping_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_35) & 127;
  }

  int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_64) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_74 = local_arr[aux % 3];
  acc = (acc + (sample_74 * 2)) & 127;
  int checksum_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_53 > 18)
  {
    acc = ((acc + (checksum_53 * 2)) + 5) & 127;
    aux ^= checksum_53 & 15;
  }
  else
  {
    acc = ((acc - checksum_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int vector_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_65_1 > 45)
  {
    acc_1 = ((acc_1 + (vector_65_1 * 2)) + 5) & 127;
    aux_1 ^= vector_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_65_2 > 45)
  {
    acc_2 = ((acc_2 + (vector_65_2 * 2)) + 5) & 127;
    aux_2 ^= vector_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_65_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_50_1) & 63;
  aux_2 = (aux_2 + metric_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_20_1 = local_arr_1[aux_1 % 3];
  int coefficient_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_20_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_65_1 == vector_65_2);
  assert(metric_50_1 == metric_50_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_20_1 == coefficient_20_2);
}

int fn_R001834_3413_10(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int vector_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_65 > 45)
  {
    acc = ((acc + (vector_65 * 2)) + 5) & 127;
    aux ^= vector_65 & 15;
  }
  else
  {
    acc = ((acc - vector_65) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_50) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_20 = local_arr[aux % 3];
  acc = (acc + (coefficient_20 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001834_3413_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st_1 = {0};
  struct FilterState_R001834_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_52_1 = local_arr_1[aux_1 % 3];
  int anchor_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_52_2 * 2)) & 127;
  int parity_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_11_1) & 63;
  aux_2 = (aux_2 + parity_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_30_1 > 48)
  {
    acc_1 = ((acc_1 + (damping_30_1 * 2)) + 5) & 127;
    aux_1 ^= damping_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_30_2 > 48)
  {
    acc_2 = ((acc_2 + (damping_30_2 * 2)) + 5) & 127;
    aux_2 ^= damping_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_30_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_52_1 == anchor_52_2);
  assert(parity_11_1 == parity_11_2);
  assert(damping_30_1 == damping_30_2);
}

int fn_R001834_3413_11(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int anchor_52 = local_arr[aux % 3];
  acc = (acc + (anchor_52 * 2)) & 127;
  int parity_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_11) & 63;
  acc ^= aux;
  int damping_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_30 > 48)
  {
    acc = ((acc + (damping_30 * 2)) + 5) & 127;
    aux ^= damping_30 & 15;
  }
  else
  {
    acc = ((acc - damping_30) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_77_1 = local_arr_1[aux_1 % 3];
  int scale_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_77_2 * 2)) & 127;
  int checksum_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_10_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_10_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_10_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_10_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_20_1)
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

  switch (parity_20_2)
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
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_77_1 == scale_77_2);
  assert(checksum_10_1 == checksum_10_2);
  assert(parity_20_1 == parity_20_2);
}

int fn_R001834_3413_12(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int scale_77 = local_arr[aux % 3];
  acc = (acc + (scale_77 * 2)) & 127;
  int checksum_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_10 > 30)
  {
    acc = ((acc + (checksum_10 * 2)) + 5) & 127;
    aux ^= checksum_10 & 15;
  }
  else
  {
    acc = ((acc - checksum_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_20 = (aux + st.buffer[1]) & 3;
  switch (parity_20)
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

void fn_R001834_3413_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_25_1) & 63;
  aux_2 = (aux_2 + stride_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_31_1)
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

  switch (checksum_31_2)
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
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_25_1 == stride_25_2);
  assert(checksum_31_1 == checksum_31_2);
}

int fn_R001834_3413_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001834_3413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_25) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_31 = (aux + st.buffer[1]) & 3;
  switch (checksum_31)
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

void fn_R001834_3413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st_1 = {0};
  struct FilterState_R001834_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_83_1 = 0;
  int stride_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_83_1 = ((stride_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_83_2 = ((stride_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_83_1) & 127;
    acc_2 = (acc_2 + stride_83_2) & 127;
  }

  int tally_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_98_1) & 63;
  aux_2 = (aux_2 + tally_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_19_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_19_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_19_1 > 26)
  {
    acc_1 = ((acc_1 + (delta_19_1 * 2)) + 5) & 127;
    aux_1 ^= delta_19_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_19_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_19_2 > 26)
  {
    acc_2 = ((acc_2 + (delta_19_2 * 2)) + 5) & 127;
    aux_2 ^= delta_19_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_19_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_83_1 == stride_83_2);
  assert(tally_98_1 == tally_98_2);
  assert(delta_19_1 == delta_19_2);
}

int fn_R001834_3413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_83 = ((stride_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_83) & 127;
  }

  int tally_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_98) & 63;
  acc ^= aux;
  int delta_19 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_19 > 26)
  {
    acc = ((acc + (delta_19 * 2)) + 5) & 127;
    aux ^= delta_19 & 15;
  }
  else
  {
    acc = ((acc - delta_19) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st_1 = {0};
  struct FilterState_R001834_3413_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_91_1)
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

  switch (checksum_91_2)
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

  int sample_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_53_1 > 10)
  {
    acc_1 = ((acc_1 + (sample_53_1 * 2)) + 5) & 127;
    aux_1 ^= sample_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_53_2 > 10)
  {
    acc_2 = ((acc_2 + (sample_53_2 * 2)) + 5) & 127;
    aux_2 ^= sample_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_53_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.mode == st_2.mode);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_91_1 == checksum_91_2);
  assert(sample_53_1 == sample_53_2);
}

int fn_R001834_3413_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001834_3413_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_91 = (aux + st.buffer[1]) & 3;
  switch (checksum_91)
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

  int sample_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_53 > 10)
  {
    acc = ((acc + (sample_53 * 2)) + 5) & 127;
    aux ^= sample_53 & 15;
  }
  else
  {
    acc = ((acc - sample_53) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001834_3413_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st_1 = {0};
  struct AudioFrame_R001834_3413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_51_1 > 47)
  {
    acc_1 = ((acc_1 + (anchor_51_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_51_2 > 47)
  {
    acc_2 = ((acc_2 + (anchor_51_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_18_1)
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

  switch (index_reg_18_2)
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
  int index_reg_13_1 = local_arr_1[aux_1 % 3];
  int index_reg_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.peak == st_2.peak);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.channels == st_2.channels);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_51_1 == anchor_51_2);
  assert(index_reg_18_1 == index_reg_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_13_1 == index_reg_13_2);
}

int fn_R001834_3413_16(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001834_3413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_51 > 47)
  {
    acc = ((acc + (anchor_51 * 2)) + 5) & 127;
    aux ^= anchor_51 & 15;
  }
  else
  {
    acc = ((acc - anchor_51) + 11) & 127;
    aux += 3;
  }
  int index_reg_18 = (aux + st.buffer[1]) & 3;
  switch (index_reg_18)
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
  int index_reg_13 = local_arr[aux % 3];
  acc = (acc + (index_reg_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001834_0_1;
  int sec_r001834_0_2;
  int sec_r001834_1_1;
  int sec_r001834_1_2;
  int sec_r001834_2_1;
  int sec_r001834_2_2;
  int sec_r001834_3_1;
  int sec_r001834_3_2;
  int sec_r001834_4_1;
  int sec_r001834_4_2;
  int sec_r001834_5_1;
  int sec_r001834_5_2;
  int sec_r001834_6_1;
  int sec_r001834_6_2;
  int sec_r001834_7_1;
  int sec_r001834_7_2;
  int sec_r001834_8_1;
  int sec_r001834_8_2;
  int sec_r001834_9_1;
  int sec_r001834_9_2;
  int sec_r001834_10_1;
  int sec_r001834_10_2;
  int sec_r001834_11_1;
  int sec_r001834_11_2;
  int sec_r001834_12_1;
  int sec_r001834_12_2;
  int sec_r001834_13_1;
  int sec_r001834_13_2;
  int sec_r001834_14_1;
  int sec_r001834_14_2;
  int sec_r001834_15_1;
  int sec_r001834_15_2;
  int sec_r001834_16_1;
  int sec_r001834_16_2;
  int sec_r001834_17_1;
  int sec_r001834_17_2;
  int sec_r001834_18_1;
  int sec_r001834_18_2;
  int sec_r001834_19_1;
  int sec_r001834_19_2;
  int sec_r001834_20_1;
  int sec_r001834_20_2;
  int sec_r001834_21_1;
  int sec_r001834_21_2;
  int sec_r001834_22_1;
  int sec_r001834_22_2;
  int pub_r001834_0_1;
  int pub_r001834_0_2;
  int pub_r001834_1_1;
  int pub_r001834_1_2;
  int pub_r001834_2_1;
  int pub_r001834_2_2;
  int pub_r001834_3_1;
  int pub_r001834_3_2;
  int pub_r001834_4_1;
  int pub_r001834_4_2;
  int pub_r001834_5_1;
  int pub_r001834_5_2;
  int pub_r001834_6_1;
  int pub_r001834_6_2;
  int pub_r001834_7_1;
  int pub_r001834_7_2;
  int pub_r001834_8_1;
  int pub_r001834_8_2;
  int pub_r001834_9_1;
  int pub_r001834_9_2;
  int pub_r001834_10_1;
  int pub_r001834_10_2;
  int pub_r001834_11_1;
  int pub_r001834_11_2;
  int pub_r001834_12_1;
  int pub_r001834_12_2;
  int pub_r001834_13_1;
  int pub_r001834_13_2;
  int pub_r001834_14_1;
  int pub_r001834_14_2;
  int pub_r001834_15_1;
  int pub_r001834_15_2;
  int pub_r001834_16_1;
  int pub_r001834_16_2;
  int pub_r001834_17_1;
  int pub_r001834_17_2;
  int pub_r001834_18_1;
  int pub_r001834_18_2;
  int pub_r001834_19_1;
  int pub_r001834_19_2;
  int pub_r001834_20_1;
  int pub_r001834_20_2;
  int pub_r001834_21_1;
  int pub_r001834_21_2;
  int pub_r001834_22_1;
  int pub_r001834_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001834_0_1 >= (-100)) && (pub_r001834_0_1 <= 100));
  __CPROVER_assume((pub_r001834_0_2 >= (-100)) && (pub_r001834_0_2 <= 100));
  __CPROVER_assume((pub_r001834_1_1 >= (-100)) && (pub_r001834_1_1 <= 100));
  __CPROVER_assume((pub_r001834_1_2 >= (-100)) && (pub_r001834_1_2 <= 100));
  __CPROVER_assume((pub_r001834_2_1 >= (-100)) && (pub_r001834_2_1 <= 100));
  __CPROVER_assume((pub_r001834_2_2 >= (-100)) && (pub_r001834_2_2 <= 100));
  __CPROVER_assume((pub_r001834_3_1 >= (-100)) && (pub_r001834_3_1 <= 100));
  __CPROVER_assume((pub_r001834_3_2 >= (-100)) && (pub_r001834_3_2 <= 100));
  __CPROVER_assume((pub_r001834_4_1 >= (-100)) && (pub_r001834_4_1 <= 100));
  __CPROVER_assume((pub_r001834_4_2 >= (-100)) && (pub_r001834_4_2 <= 100));
  __CPROVER_assume((pub_r001834_5_1 >= (-100)) && (pub_r001834_5_1 <= 100));
  __CPROVER_assume((pub_r001834_5_2 >= (-100)) && (pub_r001834_5_2 <= 100));
  __CPROVER_assume((pub_r001834_6_1 >= (-100)) && (pub_r001834_6_1 <= 100));
  __CPROVER_assume((pub_r001834_6_2 >= (-100)) && (pub_r001834_6_2 <= 100));
  __CPROVER_assume((pub_r001834_7_1 >= (-100)) && (pub_r001834_7_1 <= 100));
  __CPROVER_assume((pub_r001834_7_2 >= (-100)) && (pub_r001834_7_2 <= 100));
  __CPROVER_assume((pub_r001834_8_1 >= (-100)) && (pub_r001834_8_1 <= 100));
  __CPROVER_assume((pub_r001834_8_2 >= (-100)) && (pub_r001834_8_2 <= 100));
  __CPROVER_assume((pub_r001834_9_1 >= (-100)) && (pub_r001834_9_1 <= 100));
  __CPROVER_assume((pub_r001834_9_2 >= (-100)) && (pub_r001834_9_2 <= 100));
  __CPROVER_assume((pub_r001834_10_1 >= (-100)) && (pub_r001834_10_1 <= 100));
  __CPROVER_assume((pub_r001834_10_2 >= (-100)) && (pub_r001834_10_2 <= 100));
  __CPROVER_assume((pub_r001834_11_1 >= (-100)) && (pub_r001834_11_1 <= 100));
  __CPROVER_assume((pub_r001834_11_2 >= (-100)) && (pub_r001834_11_2 <= 100));
  __CPROVER_assume((pub_r001834_12_1 >= (-100)) && (pub_r001834_12_1 <= 100));
  __CPROVER_assume((pub_r001834_12_2 >= (-100)) && (pub_r001834_12_2 <= 100));
  __CPROVER_assume((pub_r001834_13_1 >= (-100)) && (pub_r001834_13_1 <= 100));
  __CPROVER_assume((pub_r001834_13_2 >= (-100)) && (pub_r001834_13_2 <= 100));
  __CPROVER_assume((pub_r001834_14_1 >= (-100)) && (pub_r001834_14_1 <= 100));
  __CPROVER_assume((pub_r001834_14_2 >= (-100)) && (pub_r001834_14_2 <= 100));
  __CPROVER_assume((pub_r001834_15_1 >= (-100)) && (pub_r001834_15_1 <= 100));
  __CPROVER_assume((pub_r001834_15_2 >= (-100)) && (pub_r001834_15_2 <= 100));
  __CPROVER_assume((pub_r001834_16_1 >= (-100)) && (pub_r001834_16_1 <= 100));
  __CPROVER_assume((pub_r001834_16_2 >= (-100)) && (pub_r001834_16_2 <= 100));
  __CPROVER_assume((pub_r001834_17_1 >= (-100)) && (pub_r001834_17_1 <= 100));
  __CPROVER_assume((pub_r001834_17_2 >= (-100)) && (pub_r001834_17_2 <= 100));
  __CPROVER_assume((pub_r001834_18_1 >= (-100)) && (pub_r001834_18_1 <= 100));
  __CPROVER_assume((pub_r001834_18_2 >= (-100)) && (pub_r001834_18_2 <= 100));
  __CPROVER_assume((pub_r001834_19_1 >= (-100)) && (pub_r001834_19_1 <= 100));
  __CPROVER_assume((pub_r001834_19_2 >= (-100)) && (pub_r001834_19_2 <= 100));
  __CPROVER_assume((pub_r001834_20_1 >= (-100)) && (pub_r001834_20_1 <= 100));
  __CPROVER_assume((pub_r001834_20_2 >= (-100)) && (pub_r001834_20_2 <= 100));
  __CPROVER_assume((pub_r001834_21_1 >= (-100)) && (pub_r001834_21_1 <= 100));
  __CPROVER_assume((pub_r001834_21_2 >= (-100)) && (pub_r001834_21_2 <= 100));
  __CPROVER_assume((pub_r001834_22_1 >= (-100)) && (pub_r001834_22_1 <= 100));
  __CPROVER_assume((pub_r001834_22_2 >= (-100)) && (pub_r001834_22_2 <= 100));
  __CPROVER_assume((sec_r001834_0_1 >= 0) && (sec_r001834_0_1 <= 255));
  __CPROVER_assume((sec_r001834_0_2 >= 0) && (sec_r001834_0_2 <= 255));
  __CPROVER_assume((sec_r001834_1_1 >= 0) && (sec_r001834_1_1 <= 255));
  __CPROVER_assume((sec_r001834_1_2 >= 0) && (sec_r001834_1_2 <= 255));
  __CPROVER_assume((sec_r001834_2_1 >= 0) && (sec_r001834_2_1 <= 255));
  __CPROVER_assume((sec_r001834_2_2 >= 0) && (sec_r001834_2_2 <= 255));
  __CPROVER_assume((sec_r001834_3_1 >= 0) && (sec_r001834_3_1 <= 255));
  __CPROVER_assume((sec_r001834_3_2 >= 0) && (sec_r001834_3_2 <= 255));
  __CPROVER_assume((sec_r001834_4_1 >= 0) && (sec_r001834_4_1 <= 255));
  __CPROVER_assume((sec_r001834_4_2 >= 0) && (sec_r001834_4_2 <= 255));
  __CPROVER_assume((sec_r001834_5_1 >= 0) && (sec_r001834_5_1 <= 255));
  __CPROVER_assume((sec_r001834_5_2 >= 0) && (sec_r001834_5_2 <= 255));
  __CPROVER_assume((sec_r001834_6_1 >= 0) && (sec_r001834_6_1 <= 255));
  __CPROVER_assume((sec_r001834_6_2 >= 0) && (sec_r001834_6_2 <= 255));
  __CPROVER_assume((sec_r001834_7_1 >= 0) && (sec_r001834_7_1 <= 255));
  __CPROVER_assume((sec_r001834_7_2 >= 0) && (sec_r001834_7_2 <= 255));
  __CPROVER_assume((sec_r001834_8_1 >= 0) && (sec_r001834_8_1 <= 255));
  __CPROVER_assume((sec_r001834_8_2 >= 0) && (sec_r001834_8_2 <= 255));
  __CPROVER_assume((sec_r001834_9_1 >= 0) && (sec_r001834_9_1 <= 255));
  __CPROVER_assume((sec_r001834_9_2 >= 0) && (sec_r001834_9_2 <= 255));
  __CPROVER_assume((sec_r001834_10_1 >= 0) && (sec_r001834_10_1 <= 255));
  __CPROVER_assume((sec_r001834_10_2 >= 0) && (sec_r001834_10_2 <= 255));
  __CPROVER_assume((sec_r001834_11_1 >= 0) && (sec_r001834_11_1 <= 255));
  __CPROVER_assume((sec_r001834_11_2 >= 0) && (sec_r001834_11_2 <= 255));
  __CPROVER_assume((sec_r001834_12_1 >= 0) && (sec_r001834_12_1 <= 255));
  __CPROVER_assume((sec_r001834_12_2 >= 0) && (sec_r001834_12_2 <= 255));
  __CPROVER_assume((sec_r001834_13_1 >= 0) && (sec_r001834_13_1 <= 255));
  __CPROVER_assume((sec_r001834_13_2 >= 0) && (sec_r001834_13_2 <= 255));
  __CPROVER_assume((sec_r001834_14_1 >= 0) && (sec_r001834_14_1 <= 255));
  __CPROVER_assume((sec_r001834_14_2 >= 0) && (sec_r001834_14_2 <= 255));
  __CPROVER_assume((sec_r001834_15_1 >= 0) && (sec_r001834_15_1 <= 255));
  __CPROVER_assume((sec_r001834_15_2 >= 0) && (sec_r001834_15_2 <= 255));
  __CPROVER_assume((sec_r001834_16_1 >= 0) && (sec_r001834_16_1 <= 255));
  __CPROVER_assume((sec_r001834_16_2 >= 0) && (sec_r001834_16_2 <= 255));
  __CPROVER_assume((sec_r001834_17_1 >= 0) && (sec_r001834_17_1 <= 255));
  __CPROVER_assume((sec_r001834_17_2 >= 0) && (sec_r001834_17_2 <= 255));
  __CPROVER_assume((sec_r001834_18_1 >= 0) && (sec_r001834_18_1 <= 255));
  __CPROVER_assume((sec_r001834_18_2 >= 0) && (sec_r001834_18_2 <= 255));
  __CPROVER_assume((sec_r001834_19_1 >= 0) && (sec_r001834_19_1 <= 255));
  __CPROVER_assume((sec_r001834_19_2 >= 0) && (sec_r001834_19_2 <= 255));
  __CPROVER_assume((sec_r001834_20_1 >= 0) && (sec_r001834_20_1 <= 255));
  __CPROVER_assume((sec_r001834_20_2 >= 0) && (sec_r001834_20_2 <= 255));
  __CPROVER_assume((sec_r001834_21_1 >= 0) && (sec_r001834_21_1 <= 255));
  __CPROVER_assume((sec_r001834_21_2 >= 0) && (sec_r001834_21_2 <= 255));
  __CPROVER_assume((sec_r001834_22_1 >= 0) && (sec_r001834_22_1 <= 255));
  __CPROVER_assume((sec_r001834_22_2 >= 0) && (sec_r001834_22_2 <= 255));
  struct DeviceConfig_R001834_3413_0 st_var_0_1 = {0};
  struct DeviceConfig_R001834_3413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001834_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001834_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001834_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001834_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001834_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001834_0_2 + 7) & 15;
  struct AudioFrame_R001834_3413_1 st_var_1_1 = {0};
  struct AudioFrame_R001834_3413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001834_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001834_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001834_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001834_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001834_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001834_0_2 + 9) & 15;
  struct FilterState_R001834_3413_2 st_var_2_1 = {0};
  struct FilterState_R001834_3413_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001834_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001834_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001834_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001834_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001834_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001834_0_2 + 11) & 15;
  union PacketPayload_R001834_3413_0 u_var_1;
  union PacketPayload_R001834_3413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001834_3413_0(sec_r001834_0_1, pub_r001834_1_1, pub_r001834_2_1, pub_r001834_3_1);
  int helper_flow_0_2 = fn_R001834_3413_0(sec_r001834_0_2, pub_r001834_1_2, pub_r001834_2_2, pub_r001834_3_2);
  fn_R001834_3413_0_2(sec_r001834_0_1, pub_r001834_1_1, pub_r001834_2_1, pub_r001834_3_1, sec_r001834_0_2, pub_r001834_1_2, pub_r001834_2_2, pub_r001834_3_2);
  int helper_flow_1_1 = fn_R001834_3413_1(sec_r001834_1_1, sec_r001834_2_1, pub_r001834_3_1, pub_r001834_4_1);
  int helper_flow_1_2 = fn_R001834_3413_1(sec_r001834_1_2, sec_r001834_2_2, pub_r001834_3_2, pub_r001834_4_2);
  fn_R001834_3413_1_2(sec_r001834_1_1, sec_r001834_2_1, pub_r001834_3_1, pub_r001834_4_1, sec_r001834_1_2, sec_r001834_2_2, pub_r001834_3_2, pub_r001834_4_2);
  int helper_flow_2_1 = fn_R001834_3413_2(sec_r001834_2_1, pub_r001834_3_1, pub_r001834_4_1);
  int helper_flow_2_2 = fn_R001834_3413_2(sec_r001834_2_2, pub_r001834_3_2, pub_r001834_4_2);
  fn_R001834_3413_2_2(sec_r001834_2_1, pub_r001834_3_1, pub_r001834_4_1, sec_r001834_2_2, pub_r001834_3_2, pub_r001834_4_2);
  int helper_flow_3_1 = fn_R001834_3413_3(sec_r001834_3_1, sec_r001834_4_1, pub_r001834_5_1);
  int helper_flow_3_2 = fn_R001834_3413_3(sec_r001834_3_2, sec_r001834_4_2, pub_r001834_5_2);
  fn_R001834_3413_3_2(sec_r001834_3_1, sec_r001834_4_1, pub_r001834_5_1, sec_r001834_3_2, sec_r001834_4_2, pub_r001834_5_2);
  int helper_flow_4_1 = fn_R001834_3413_4(sec_r001834_4_1, sec_r001834_5_1);
  int helper_flow_4_2 = fn_R001834_3413_4(sec_r001834_4_2, sec_r001834_5_2);
  fn_R001834_3413_4_2(sec_r001834_4_1, sec_r001834_5_1, sec_r001834_4_2, sec_r001834_5_2);
  int stage_v_0_1 = ((pub_r001834_20_1 * 2) + 7) & 63;
  int stage_v_0_2 = ((pub_r001834_20_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001834_21_1 * 2) + 39) & 63;
  int stage_v_1_2 = ((pub_r001834_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001834_20_1 * 3) + pub_r001834_22_1) + 13) & 127;
  int stage_v_2_2 = (((sec_r001834_20_2 * 3) + pub_r001834_22_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001834_16_1 * 3) + pub_r001834_8_1) + 14) & 127;
  int stage_v_3_2 = (((sec_r001834_16_2 * 3) + pub_r001834_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((helper_flow_4_1 * 3) + pub_r001834_13_1) + 15) & 127;
  int stage_v_4_2 = (((helper_flow_4_2 * 3) + pub_r001834_13_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001834_17_1 * 2) + 30) & 63;
  int stage_v_5_2 = ((pub_r001834_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001834_21_1 * 2) + 7) & 63;
  int stage_v_6_2 = ((pub_r001834_21_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001834_10_1 * 3) + pub_r001834_13_1) + 20) & 127;
  int stage_v_7_2 = (((sec_r001834_10_2 * 3) + pub_r001834_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = (((stage_v_2_1 * 3) + pub_r001834_20_1) + 14) & 127;
  int stage_v_8_2 = (((stage_v_2_2 * 3) + pub_r001834_20_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001834_21_1 * 2) + 39) & 63;
  int stage_v_9_2 = ((pub_r001834_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_7_1 * 3) + pub_r001834_10_1) + 41) & 127;
  int stage_v_10_2 = (((stage_v_7_2 * 3) + pub_r001834_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001834_10_1 * 3) + pub_r001834_3_1) + 17) & 127;
  int stage_v_11_2 = (((sec_r001834_10_2 * 3) + pub_r001834_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((helper_flow_2_1 * 3) + pub_r001834_6_1) + 4) & 127;
  int stage_v_12_2 = (((helper_flow_2_2 * 3) + pub_r001834_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((sec_r001834_5_1 * 3) + pub_r001834_2_1) + 43) & 127;
  int stage_v_13_2 = (((sec_r001834_5_2 * 3) + pub_r001834_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001834_17_1 * 2) + 39) & 63;
  int stage_v_14_2 = ((pub_r001834_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((stage_v_7_1 * 3) + pub_r001834_1_1) + 43) & 127;
  int stage_v_15_2 = (((stage_v_7_2 * 3) + pub_r001834_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_3_1 * 3) + pub_r001834_0_1) + 35) & 127;
  int stage_v_16_2 = (((helper_flow_3_2 * 3) + pub_r001834_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((stage_v_10_1 * 3) + pub_r001834_1_1) + 21) & 127;
  int stage_v_17_2 = (((stage_v_10_2 * 3) + pub_r001834_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001834_3_1 * 2) + 35) & 63;
  int stage_v_18_2 = ((pub_r001834_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001834_0_1 * 3) + pub_r001834_12_1) + 12) & 127;
  int stage_v_19_2 = (((sec_r001834_0_2 * 3) + pub_r001834_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001834_20_1 * 2) + 13) & 63;
  int stage_v_20_2 = ((pub_r001834_20_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((stage_v_16_1 * 3) + pub_r001834_18_1) + 20) & 127;
  int stage_v_21_2 = (((stage_v_16_2 * 3) + pub_r001834_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = (((stage_v_21_1 * 3) + pub_r001834_9_1) + 38) & 127;
  int stage_v_22_2 = (((stage_v_21_2 * 3) + pub_r001834_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001834_2_1 * 2) + 43) & 63;
  int stage_v_23_2 = ((pub_r001834_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001834_1_1 * 2) + 24) & 63;
  int stage_v_24_2 = ((pub_r001834_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((stage_v_8_1 * 3) + pub_r001834_2_1) + 11) & 127;
  int stage_v_25_2 = (((stage_v_8_2 * 3) + pub_r001834_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001834_17_1 * 2) + 8) & 63;
  int stage_v_26_2 = ((pub_r001834_17_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001834_2_1 * 2) + 19) & 63;
  int stage_v_27_2 = ((pub_r001834_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001834_2_1 * 3) + pub_r001834_2_1) + 44) & 127;
  int stage_v_28_2 = (((sec_r001834_2_2 * 3) + pub_r001834_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001834_20_1 * 3) + pub_r001834_2_1) + 39) & 127;
  int stage_v_29_2 = (((sec_r001834_20_2 * 3) + pub_r001834_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((sec_r001834_10_1 * 3) + pub_r001834_18_1) + 42) & 127;
  int stage_v_30_2 = (((sec_r001834_10_2 * 3) + pub_r001834_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001834_15_1 * 2) + 21) & 63;
  int stage_v_31_2 = ((pub_r001834_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001834_0_1 * 3) + pub_r001834_17_1) + 41) & 127;
  int stage_v_32_2 = (((sec_r001834_0_2 * 3) + pub_r001834_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((stage_v_17_1 * 3) + pub_r001834_7_1) + 38) & 127;
  int stage_v_33_2 = (((stage_v_17_2 * 3) + pub_r001834_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001834_12_1 * 3) + pub_r001834_4_1) + 29) & 127;
  int stage_v_34_2 = (((sec_r001834_12_2 * 3) + pub_r001834_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001834_16_1 * 2) + 34) & 63;
  int stage_v_35_2 = ((pub_r001834_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001834_22_1 * 3) + pub_r001834_8_1) + 31) & 127;
  int stage_v_36_2 = (((sec_r001834_22_2 * 3) + pub_r001834_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001834_20_1 * 2) + 37) & 63;
  int stage_v_37_2 = ((pub_r001834_20_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_12_1 * 3) + pub_r001834_10_1) + 25) & 127;
  int stage_v_38_2 = (((stage_v_12_2 * 3) + pub_r001834_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001834_16_1 * 2) + 30) & 63;
  int stage_v_39_2 = ((pub_r001834_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_22_1 * 3) + pub_r001834_6_1) + 3) & 127;
  int stage_v_40_2 = (((stage_v_22_2 * 3) + pub_r001834_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001834_10_1 * 2) + 46) & 63;
  int stage_v_41_2 = ((pub_r001834_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001834_18_1 * 2) + 38) & 63;
  int stage_v_42_2 = ((pub_r001834_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001834_4_1 * 2) + 25) & 63;
  int stage_v_43_2 = ((pub_r001834_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_3_1 * 3) + pub_r001834_22_1) + 17) & 127;
  int stage_v_44_2 = (((stage_v_3_2 * 3) + pub_r001834_22_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((sec_r001834_12_1 * 3) + pub_r001834_11_1) + 11) & 127;
  int stage_v_45_2 = (((sec_r001834_12_2 * 3) + pub_r001834_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((helper_flow_0_1 * 3) + pub_r001834_16_1) + 3) & 127;
  int stage_v_46_2 = (((helper_flow_0_2 * 3) + pub_r001834_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((helper_flow_0_1 * 3) + pub_r001834_20_1) + 39) & 127;
  int stage_v_47_2 = (((helper_flow_0_2 * 3) + pub_r001834_20_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((stage_v_29_1 * 3) + pub_r001834_20_1) + 42) & 127;
  int stage_v_48_2 = (((stage_v_29_2 * 3) + pub_r001834_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_29_1 * 3) + pub_r001834_21_1) + 45) & 127;
  int stage_v_49_2 = (((stage_v_29_2 * 3) + pub_r001834_21_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001834_10_1 * 2) + 8) & 63;
  int stage_v_50_2 = ((pub_r001834_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001834_12_1 * 2) + 30) & 63;
  int stage_v_51_2 = ((pub_r001834_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_47_1 * 3) + pub_r001834_13_1) + 19) & 127;
  int stage_v_52_2 = (((stage_v_47_2 * 3) + pub_r001834_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001834_4_1 * 2) + 36) & 63;
  int stage_v_53_2 = ((pub_r001834_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001834_13_1 * 3) + pub_r001834_7_1) + 45) & 127;
  int stage_v_54_2 = (((sec_r001834_13_2 * 3) + pub_r001834_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((sec_r001834_10_1 * 3) + pub_r001834_3_1) + 23) & 127;
  int stage_v_55_2 = (((sec_r001834_10_2 * 3) + pub_r001834_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((stage_v_32_1 * 3) + pub_r001834_22_1) + 32) & 127;
  int stage_v_56_2 = (((stage_v_32_2 * 3) + pub_r001834_22_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_12_1 * 3) + pub_r001834_10_1) + 20) & 127;
  int stage_v_57_2 = (((stage_v_12_2 * 3) + pub_r001834_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001834_10_1 * 2) + 33) & 63;
  int stage_v_58_2 = ((pub_r001834_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001834_12_1 * 2) + 19) & 63;
  int stage_v_59_2 = ((pub_r001834_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001834_14_1 * 2) + 37) & 63;
  int stage_v_60_2 = ((pub_r001834_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001834_12_1 * 3) + pub_r001834_8_1) + 34) & 127;
  int stage_v_61_2 = (((sec_r001834_12_2 * 3) + pub_r001834_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001834_6_1 * 2) + 46) & 63;
  int stage_v_62_2 = ((pub_r001834_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_44_1 * 3) + pub_r001834_6_1) + 5) & 127;
  int stage_v_63_2 = (((stage_v_44_2 * 3) + pub_r001834_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_40_1 * 3) + pub_r001834_8_1) + 27) & 127;
  int stage_v_64_2 = (((stage_v_40_2 * 3) + pub_r001834_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001834_3_1 * 2) + 50) & 63;
  int stage_v_65_2 = ((pub_r001834_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((sec_r001834_4_1 * 3) + pub_r001834_20_1) + 7) & 127;
  int stage_v_66_2 = (((sec_r001834_4_2 * 3) + pub_r001834_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = ((pub_r001834_20_1 * 2) + 43) & 63;
  int stage_v_67_2 = ((pub_r001834_20_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001834_9_1 * 3) + pub_r001834_20_1) + 42) & 127;
  int stage_v_68_2 = (((sec_r001834_9_2 * 3) + pub_r001834_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((helper_flow_1_1 * 3) + pub_r001834_10_1) + 6) & 127;
  int stage_v_69_2 = (((helper_flow_1_2 * 3) + pub_r001834_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001834_1_1 * 2) + 26) & 63;
  int stage_v_70_2 = ((pub_r001834_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((stage_v_57_1 * 3) + pub_r001834_14_1) + 37) & 127;
  int stage_v_71_2 = (((stage_v_57_2 * 3) + pub_r001834_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((stage_v_10_1 * 3) + pub_r001834_2_1) + 18) & 127;
  int stage_v_72_2 = (((stage_v_10_2 * 3) + pub_r001834_2_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_17_1 * 3) + pub_r001834_12_1) + 21) & 127;
  int stage_v_73_2 = (((stage_v_17_2 * 3) + pub_r001834_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((stage_v_40_1 * 3) + pub_r001834_12_1) + 37) & 127;
  int stage_v_74_2 = (((stage_v_40_2 * 3) + pub_r001834_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((helper_flow_1_1 * 3) + pub_r001834_15_1) + 26) & 127;
  int stage_v_75_2 = (((helper_flow_1_2 * 3) + pub_r001834_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001834_15_1 * 2) + 48) & 63;
  int stage_v_76_2 = ((pub_r001834_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001834_22_1 * 3) + pub_r001834_22_1) + 31) & 127;
  int stage_v_77_2 = (((sec_r001834_22_2 * 3) + pub_r001834_22_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((helper_flow_1_1 * 3) + pub_r001834_16_1) + 36) & 127;
  int stage_v_78_2 = (((helper_flow_1_2 * 3) + pub_r001834_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_16_1 * 3) + pub_r001834_11_1) + 27) & 127;
  int stage_v_79_2 = (((stage_v_16_2 * 3) + pub_r001834_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001834_7_1 * 2) + 46) & 63;
  int stage_v_80_2 = ((pub_r001834_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001834_0_1 * 2) + 33) & 63;
  int stage_v_81_2 = ((pub_r001834_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_34_1 * 3) + pub_r001834_8_1) + 3) & 127;
  int stage_v_82_2 = (((stage_v_34_2 * 3) + pub_r001834_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001834_4_1 * 2) + 32) & 63;
  int stage_v_83_2 = ((pub_r001834_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_22_1 * 3) + pub_r001834_11_1) + 17) & 127;
  int stage_v_84_2 = (((stage_v_22_2 * 3) + pub_r001834_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001834_3_1 * 2) + 49) & 63;
  int stage_v_85_2 = ((pub_r001834_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001834_4_1 * 2) + 45) & 63;
  int stage_v_86_2 = ((pub_r001834_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_71_1 * 3) + pub_r001834_17_1) + 13) & 127;
  int stage_v_87_2 = (((stage_v_71_2 * 3) + pub_r001834_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((sec_r001834_9_1 * 3) + pub_r001834_1_1) + 13) & 127;
  int stage_v_88_2 = (((sec_r001834_9_2 * 3) + pub_r001834_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_48_1 * 3) + pub_r001834_4_1) + 35) & 127;
  int stage_v_89_2 = (((stage_v_48_2 * 3) + pub_r001834_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001834_19_1 * 2) + 9) & 63;
  int stage_v_90_2 = ((pub_r001834_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_38_1 * 3) + pub_r001834_17_1) + 14) & 127;
  int stage_v_91_2 = (((stage_v_38_2 * 3) + pub_r001834_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001834_8_1 * 2) + 50) & 63;
  int stage_v_92_2 = ((pub_r001834_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001834_10_1 * 2) + 36) & 63;
  int stage_v_93_2 = ((pub_r001834_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001834_7_1 * 2) + 14) & 63;
  int stage_v_94_2 = ((pub_r001834_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001834_6_1 * 2) + 43) & 63;
  int stage_v_95_2 = ((pub_r001834_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_16_1 * 3) + pub_r001834_13_1) + 41) & 127;
  int stage_v_96_2 = (((stage_v_16_2 * 3) + pub_r001834_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001834_0_1 * 2) + 37) & 63;
  int stage_v_97_2 = ((pub_r001834_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_64_1 * 3) + pub_r001834_21_1) + 26) & 127;
  int stage_v_98_2 = (((stage_v_64_2 * 3) + pub_r001834_21_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_78_1 * 3) + pub_r001834_13_1) + 20) & 127;
  int stage_v_99_2 = (((stage_v_78_2 * 3) + pub_r001834_13_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((sec_r001834_0_1 * 3) + pub_r001834_20_1) + 11) & 127;
  int stage_v_100_2 = (((sec_r001834_0_2 * 3) + pub_r001834_20_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = ((pub_r001834_15_1 * 2) + 9) & 63;
  int stage_v_101_2 = ((pub_r001834_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((sec_r001834_8_1 * 3) + pub_r001834_21_1) + 16) & 127;
  int stage_v_102_2 = (((sec_r001834_8_2 * 3) + pub_r001834_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001834_9_1 * 2) + 6) & 63;
  int stage_v_103_2 = ((pub_r001834_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001834_10_1 * 3) + pub_r001834_8_1) + 38) & 127;
  int stage_v_104_2 = (((sec_r001834_10_2 * 3) + pub_r001834_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_49_1 * 3) + pub_r001834_2_1) + 37) & 127;
  int stage_v_105_2 = (((stage_v_49_2 * 3) + pub_r001834_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_61_1 * 3) + pub_r001834_11_1) + 21) & 127;
  int stage_v_106_2 = (((stage_v_61_2 * 3) + pub_r001834_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((sec_r001834_20_1 * 3) + pub_r001834_0_1) + 3) & 127;
  int stage_v_107_2 = (((sec_r001834_20_2 * 3) + pub_r001834_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((sec_r001834_2_1 * 3) + pub_r001834_21_1) + 17) & 127;
  int stage_v_108_2 = (((sec_r001834_2_2 * 3) + pub_r001834_21_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001834_7_1 * 2) + 35) & 63;
  int stage_v_109_2 = ((pub_r001834_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001834_7_1 * 2) + 48) & 63;
  int stage_v_110_2 = ((pub_r001834_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001834_1_1 * 2) + 19) & 63;
  int stage_v_111_2 = ((pub_r001834_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_33_1 * 3) + pub_r001834_18_1) + 17) & 127;
  int stage_v_112_2 = (((stage_v_33_2 * 3) + pub_r001834_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_74_1 * 3) + pub_r001834_12_1) + 29) & 127;
  int stage_v_113_2 = (((stage_v_74_2 * 3) + pub_r001834_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_19_1 * 3) + pub_r001834_10_1) + 13) & 127;
  int stage_v_114_2 = (((stage_v_19_2 * 3) + pub_r001834_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_12_1 * 3) + pub_r001834_18_1) + 42) & 127;
  int stage_v_115_2 = (((stage_v_12_2 * 3) + pub_r001834_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001834_11_1 * 2) + 18) & 63;
  int stage_v_116_2 = ((pub_r001834_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001834_15_1 * 2) + 35) & 63;
  int stage_v_117_2 = ((pub_r001834_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001834_4_1 * 3) + pub_r001834_17_1) + 7) & 127;
  int stage_v_118_2 = (((sec_r001834_4_2 * 3) + pub_r001834_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_44_1 * 3) + pub_r001834_22_1) + 15) & 127;
  int stage_v_119_2 = (((stage_v_44_2 * 3) + pub_r001834_22_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001834_2_1 * 3) + pub_r001834_2_1) + 37) & 127;
  int stage_v_120_2 = (((sec_r001834_2_2 * 3) + pub_r001834_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001834_22_1 * 2) + 13) & 63;
  int stage_v_121_2 = ((pub_r001834_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((sec_r001834_17_1 * 3) + pub_r001834_18_1) + 36) & 127;
  int stage_v_122_2 = (((sec_r001834_17_2 * 3) + pub_r001834_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_112_1 * 3) + pub_r001834_8_1) + 29) & 127;
  int stage_v_123_2 = (((stage_v_112_2 * 3) + pub_r001834_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = ((pub_r001834_4_1 * 2) + 18) & 63;
  int stage_v_124_2 = ((pub_r001834_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001834_20_1 * 2) + 11) & 63;
  int stage_v_125_2 = ((pub_r001834_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_13_1 * 3) + pub_r001834_5_1) + 13) & 127;
  int stage_v_126_2 = (((stage_v_13_2 * 3) + pub_r001834_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = (((helper_flow_1_1 * 3) + pub_r001834_19_1) + 8) & 127;
  int stage_v_127_2 = (((helper_flow_1_2 * 3) + pub_r001834_19_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_127_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_127_2 * 2)) & 255;
  int stage_v_128_1 = (((stage_v_106_1 * 3) + pub_r001834_5_1) + 30) & 127;
  int stage_v_128_2 = (((stage_v_106_2 * 3) + pub_r001834_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_77_1 * 3) + pub_r001834_6_1) + 30) & 127;
  int stage_v_129_2 = (((stage_v_77_2 * 3) + pub_r001834_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001834_4_1 * 2) + 20) & 63;
  int stage_v_130_2 = ((pub_r001834_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001834_17_1 * 2) + 46) & 63;
  int stage_v_131_2 = ((pub_r001834_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_129_1 * 3) + pub_r001834_14_1) + 8) & 127;
  int stage_v_132_2 = (((stage_v_129_2 * 3) + pub_r001834_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_48_1 * 3) + pub_r001834_5_1) + 9) & 127;
  int stage_v_133_2 = (((stage_v_48_2 * 3) + pub_r001834_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((sec_r001834_12_1 * 3) + pub_r001834_9_1) + 43) & 127;
  int stage_v_134_2 = (((sec_r001834_12_2 * 3) + pub_r001834_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001834_15_1 * 2) + 14) & 63;
  int stage_v_135_2 = ((pub_r001834_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((sec_r001834_5_1 * 3) + pub_r001834_9_1) + 42) & 127;
  int stage_v_136_2 = (((sec_r001834_5_2 * 3) + pub_r001834_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_61_1 * 3) + pub_r001834_4_1) + 14) & 127;
  int stage_v_137_2 = (((stage_v_61_2 * 3) + pub_r001834_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001834_2_1 * 2) + 6) & 63;
  int stage_v_138_2 = ((pub_r001834_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_2_1 * 3) + pub_r001834_16_1) + 37) & 127;
  int stage_v_139_2 = (((stage_v_2_2 * 3) + pub_r001834_16_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001834_13_1 * 2) + 17) & 63;
  int stage_v_140_2 = ((pub_r001834_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((sec_r001834_3_1 * 3) + pub_r001834_21_1) + 3) & 127;
  int stage_v_141_2 = (((sec_r001834_3_2 * 3) + pub_r001834_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_120_1 * 3) + pub_r001834_6_1) + 28) & 127;
  int stage_v_142_2 = (((stage_v_120_2 * 3) + pub_r001834_6_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001834_21_1 * 2) + 12) & 63;
  int stage_v_143_2 = ((pub_r001834_21_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001834_0_1 * 2) + 31) & 63;
  int stage_v_144_2 = ((pub_r001834_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((helper_flow_0_1 * 3) + pub_r001834_10_1) + 40) & 127;
  int stage_v_145_2 = (((helper_flow_0_2 * 3) + pub_r001834_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001834_9_1 * 2) + 30) & 63;
  int stage_v_146_2 = ((pub_r001834_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001834_3_1 * 2) + 9) & 63;
  int stage_v_147_2 = ((pub_r001834_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((sec_r001834_4_1 * 3) + pub_r001834_16_1) + 19) & 127;
  int stage_v_148_2 = (((sec_r001834_4_2 * 3) + pub_r001834_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_113_1 * 3) + pub_r001834_3_1) + 29) & 127;
  int stage_v_149_2 = (((stage_v_113_2 * 3) + pub_r001834_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001834_11_1 * 2) + 6) & 63;
  int stage_v_150_2 = ((pub_r001834_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001834_13_1 * 2) + 40) & 63;
  int stage_v_151_2 = ((pub_r001834_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_36_1 * 3) + pub_r001834_21_1) + 3) & 127;
  int stage_v_152_2 = (((stage_v_36_2 * 3) + pub_r001834_21_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_106_1 * 3) + pub_r001834_6_1) + 10) & 127;
  int stage_v_153_2 = (((stage_v_106_2 * 3) + pub_r001834_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = ((pub_r001834_15_1 * 2) + 27) & 63;
  int stage_v_154_2 = ((pub_r001834_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001834_20_1 * 2) + 42) & 63;
  int stage_v_155_2 = ((pub_r001834_20_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001834_21_1 * 2) + 41) & 63;
  int stage_v_156_2 = ((pub_r001834_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_119_1 * 3) + pub_r001834_13_1) + 12) & 127;
  int stage_v_157_2 = (((stage_v_119_2 * 3) + pub_r001834_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_114_1 * 3) + pub_r001834_15_1) + 39) & 127;
  int stage_v_158_2 = (((stage_v_114_2 * 3) + pub_r001834_15_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001834_11_1 * 2) + 45) & 63;
  int stage_v_159_2 = ((pub_r001834_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001834_8_1 * 2) + 17) & 63;
  int stage_v_160_2 = ((pub_r001834_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((stage_v_8_1 * 3) + pub_r001834_9_1) + 21) & 127;
  int stage_v_161_2 = (((stage_v_8_2 * 3) + pub_r001834_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001834_16_1 * 2) + 29) & 63;
  int stage_v_162_2 = ((pub_r001834_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001834_4_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001834_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001834_12_1 * 2) + 45) & 63;
  int stage_v_164_2 = ((pub_r001834_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001834_21_1 * 2) + 39) & 63;
  int stage_v_165_2 = ((pub_r001834_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_16_1 * 3) + pub_r001834_3_1) + 43) & 127;
  int stage_v_166_2 = (((stage_v_16_2 * 3) + pub_r001834_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001834_20_1 * 2) + 21) & 63;
  int stage_v_167_2 = ((pub_r001834_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((sec_r001834_19_1 * 3) + pub_r001834_19_1) + 12) & 127;
  int stage_v_168_2 = (((sec_r001834_19_2 * 3) + pub_r001834_19_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_152_1 * 3) + pub_r001834_5_1) + 24) & 127;
  int stage_v_169_2 = (((stage_v_152_2 * 3) + pub_r001834_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_119_1 * 3) + pub_r001834_8_1) + 10) & 127;
  int stage_v_170_2 = (((stage_v_119_2 * 3) + pub_r001834_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = (((helper_flow_4_1 * 3) + pub_r001834_2_1) + 26) & 127;
  int stage_v_171_2 = (((helper_flow_4_2 * 3) + pub_r001834_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_171_1 * 3) + pub_r001834_16_1) + 34) & 127;
  int stage_v_172_2 = (((stage_v_171_2 * 3) + pub_r001834_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_17_1 * 3) + pub_r001834_7_1) + 36) & 127;
  int stage_v_173_2 = (((stage_v_17_2 * 3) + pub_r001834_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = (((stage_v_40_1 * 3) + pub_r001834_20_1) + 29) & 127;
  int stage_v_174_2 = (((stage_v_40_2 * 3) + pub_r001834_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_29_1 * 3) + pub_r001834_3_1) + 4) & 127;
  int stage_v_175_2 = (((stage_v_29_2 * 3) + pub_r001834_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001834_2_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001834_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_82_1 * 3) + pub_r001834_5_1) + 13) & 127;
  int stage_v_177_2 = (((stage_v_82_2 * 3) + pub_r001834_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_22_1 * 3) + pub_r001834_10_1) + 8) & 127;
  int stage_v_178_2 = (((stage_v_22_2 * 3) + pub_r001834_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_174_1 * 3) + pub_r001834_1_1) + 6) & 127;
  int stage_v_179_2 = (((stage_v_174_2 * 3) + pub_r001834_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((helper_flow_4_1 * 3) + pub_r001834_5_1) + 24) & 127;
  int stage_v_180_2 = (((helper_flow_4_2 * 3) + pub_r001834_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_30_1 * 3) + pub_r001834_13_1) + 21) & 127;
  int stage_v_181_2 = (((stage_v_30_2 * 3) + pub_r001834_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001834_5_1 * 2) + 17) & 63;
  int stage_v_182_2 = ((pub_r001834_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001834_8_1 * 2) + 30) & 63;
  int stage_v_183_2 = ((pub_r001834_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001834_7_1 * 2) + 28) & 63;
  int stage_v_184_2 = ((pub_r001834_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001834_19_1 * 2) + 10) & 63;
  int stage_v_185_2 = ((pub_r001834_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001834_9_1 * 2) + 29) & 63;
  int stage_v_186_2 = ((pub_r001834_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001834_15_1 * 2) + 24) & 63;
  int stage_v_187_2 = ((pub_r001834_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_33_1 * 3) + pub_r001834_12_1) + 19) & 127;
  int stage_v_188_2 = (((stage_v_33_2 * 3) + pub_r001834_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((sec_r001834_20_1 * 3) + pub_r001834_1_1) + 41) & 127;
  int stage_v_189_2 = (((sec_r001834_20_2 * 3) + pub_r001834_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = ((pub_r001834_9_1 * 2) + 12) & 63;
  int stage_v_190_2 = ((pub_r001834_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001834_12_1 * 2) + 34) & 63;
  int stage_v_191_2 = ((pub_r001834_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001834_13_1 * 2) + 32) & 63;
  int stage_v_192_2 = ((pub_r001834_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001834_9_1 * 2) + 20) & 63;
  int stage_v_193_2 = ((pub_r001834_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_47_1 * 3) + pub_r001834_19_1) + 9) & 127;
  int stage_v_194_2 = (((stage_v_47_2 * 3) + pub_r001834_19_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((stage_v_63_1 * 3) + pub_r001834_10_1) + 44) & 127;
  int stage_v_195_2 = (((stage_v_63_2 * 3) + pub_r001834_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_108_1 * 3) + pub_r001834_12_1) + 19) & 127;
  int stage_v_196_2 = (((stage_v_108_2 * 3) + pub_r001834_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_153_1 * 3) + pub_r001834_20_1) + 4) & 127;
  int stage_v_197_2 = (((stage_v_153_2 * 3) + pub_r001834_20_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_108_1 * 3) + pub_r001834_2_1) + 6) & 127;
  int stage_v_198_2 = (((stage_v_108_2 * 3) + pub_r001834_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001834_22_1 * 2) + 29) & 63;
  int stage_v_199_2 = ((pub_r001834_22_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((sec_r001834_15_1 * 3) + pub_r001834_12_1) + 45) & 127;
  int stage_v_200_2 = (((sec_r001834_15_2 * 3) + pub_r001834_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001834_13_1 * 2) + 45) & 63;
  int stage_v_201_2 = ((pub_r001834_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_148_1 * 3) + pub_r001834_3_1) + 30) & 127;
  int stage_v_202_2 = (((stage_v_148_2 * 3) + pub_r001834_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_8_1 * 3) + pub_r001834_18_1) + 11) & 127;
  int stage_v_203_2 = (((stage_v_8_2 * 3) + pub_r001834_18_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_66_1 * 3) + pub_r001834_6_1) + 33) & 127;
  int stage_v_204_2 = (((stage_v_66_2 * 3) + pub_r001834_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001834_17_1 * 2) + 47) & 63;
  int stage_v_205_2 = ((pub_r001834_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001834_19_1 * 2) + 7) & 63;
  int stage_v_206_2 = ((pub_r001834_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001834_21_1 * 2) + 48) & 63;
  int stage_v_207_2 = ((pub_r001834_21_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001834_2_1 * 2) + 38) & 63;
  int stage_v_208_2 = ((pub_r001834_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001834_6_1 * 2) + 22) & 63;
  int stage_v_209_2 = ((pub_r001834_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001834_14_1 * 2) + 49) & 63;
  int stage_v_210_2 = ((pub_r001834_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_55_1 * 3) + pub_r001834_2_1) + 44) & 127;
  int stage_v_211_2 = (((stage_v_55_2 * 3) + pub_r001834_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001834_13_1 * 2) + 26) & 63;
  int stage_v_212_2 = ((pub_r001834_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001834_0_1 * 2) + 46) & 63;
  int stage_v_213_2 = ((pub_r001834_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_44_1 * 3) + pub_r001834_3_1) + 22) & 127;
  int stage_v_214_2 = (((stage_v_44_2 * 3) + pub_r001834_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_12_1 * 3) + pub_r001834_16_1) + 7) & 127;
  int stage_v_215_2 = (((stage_v_12_2 * 3) + pub_r001834_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((sec_r001834_9_1 * 3) + pub_r001834_21_1) + 18) & 127;
  int stage_v_216_2 = (((sec_r001834_9_2 * 3) + pub_r001834_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001834_11_1 * 2) + 7) & 63;
  int stage_v_217_2 = ((pub_r001834_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_148_1 * 3) + pub_r001834_11_1) + 4) & 127;
  int stage_v_218_2 = (((stage_v_148_2 * 3) + pub_r001834_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_132_1 * 3) + pub_r001834_9_1) + 19) & 127;
  int stage_v_219_2 = (((stage_v_132_2 * 3) + pub_r001834_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_132_1 * 3) + pub_r001834_17_1) + 24) & 127;
  int stage_v_220_2 = (((stage_v_132_2 * 3) + pub_r001834_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_78_1 * 3) + pub_r001834_7_1) + 14) & 127;
  int stage_v_221_2 = (((stage_v_78_2 * 3) + pub_r001834_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((helper_flow_3_1 * 3) + pub_r001834_3_1) + 4) & 127;
  int stage_v_222_2 = (((helper_flow_3_2 * 3) + pub_r001834_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001834_7_1 * 2) + 32) & 63;
  int stage_v_223_2 = ((pub_r001834_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001834_1_1 * 2) + 25) & 63;
  int stage_v_224_2 = ((pub_r001834_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001834_13_1 * 2) + 27) & 63;
  int stage_v_225_2 = ((pub_r001834_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001834_5_1 * 2) + 22) & 63;
  int stage_v_226_2 = ((pub_r001834_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_127_1 * 3) + pub_r001834_10_1) + 17) & 127;
  int stage_v_227_2 = (((stage_v_127_2 * 3) + pub_r001834_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001834_8_1 * 2) + 48) & 63;
  int stage_v_228_2 = ((pub_r001834_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001834_3_1 * 2) + 18) & 63;
  int stage_v_229_2 = ((pub_r001834_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = (((stage_v_32_1 * 3) + pub_r001834_8_1) + 28) & 127;
  int stage_v_230_2 = (((stage_v_32_2 * 3) + pub_r001834_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001834_16_1 * 2) + 36) & 63;
  int stage_v_231_2 = ((pub_r001834_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_175_1 * 3) + pub_r001834_14_1) + 4) & 127;
  int stage_v_232_2 = (((stage_v_175_2 * 3) + pub_r001834_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((sec_r001834_9_1 * 3) + pub_r001834_14_1) + 40) & 127;
  int stage_v_233_2 = (((sec_r001834_9_2 * 3) + pub_r001834_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((sec_r001834_19_1 * 3) + pub_r001834_16_1) + 30) & 127;
  int stage_v_234_2 = (((sec_r001834_19_2 * 3) + pub_r001834_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001834_12_1 * 2) + 8) & 63;
  int stage_v_235_2 = ((pub_r001834_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001834_0_1 * 2) + 48) & 63;
  int stage_v_236_2 = ((pub_r001834_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_115_1 * 3) + pub_r001834_4_1) + 39) & 127;
  int stage_v_237_2 = (((stage_v_115_2 * 3) + pub_r001834_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_19_1 * 3) + pub_r001834_8_1) + 18) & 127;
  int stage_v_238_2 = (((stage_v_19_2 * 3) + pub_r001834_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((stage_v_174_1 * 3) + pub_r001834_20_1) + 20) & 127;
  int stage_v_239_2 = (((stage_v_174_2 * 3) + pub_r001834_20_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((sec_r001834_17_1 * 3) + pub_r001834_7_1) + 17) & 127;
  int stage_v_240_2 = (((sec_r001834_17_2 * 3) + pub_r001834_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((sec_r001834_5_1 * 3) + pub_r001834_0_1) + 19) & 127;
  int stage_v_241_2 = (((sec_r001834_5_2 * 3) + pub_r001834_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_227_1 * 3) + pub_r001834_5_1) + 33) & 127;
  int stage_v_242_2 = (((stage_v_227_2 * 3) + pub_r001834_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001834_21_1 * 2) + 8) & 63;
  int stage_v_243_2 = ((pub_r001834_21_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001834_13_1 * 2) + 43) & 63;
  int stage_v_244_2 = ((pub_r001834_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_196_1 * 3) + pub_r001834_2_1) + 3) & 127;
  int stage_v_245_2 = (((stage_v_196_2 * 3) + pub_r001834_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_141_1 * 3) + pub_r001834_7_1) + 29) & 127;
  int stage_v_246_2 = (((stage_v_141_2 * 3) + pub_r001834_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001834_10_1 * 2) + 13) & 63;
  int stage_v_247_2 = ((pub_r001834_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_77_1 * 3) + pub_r001834_14_1) + 39) & 127;
  int stage_v_248_2 = (((stage_v_77_2 * 3) + pub_r001834_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_77_1 * 3) + pub_r001834_10_1) + 12) & 127;
  int stage_v_249_2 = (((stage_v_77_2 * 3) + pub_r001834_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_40_1 * 3) + pub_r001834_12_1) + 15) & 127;
  int stage_v_250_2 = (((stage_v_40_2 * 3) + pub_r001834_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = ((pub_r001834_7_1 * 2) + 28) & 63;
  int stage_v_251_2 = ((pub_r001834_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001834_12_1 * 2) + 44) & 63;
  int stage_v_252_2 = ((pub_r001834_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001834_1_1 * 2) + 47) & 63;
  int stage_v_253_2 = ((pub_r001834_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((sec_r001834_14_1 * 3) + pub_r001834_3_1) + 41) & 127;
  int stage_v_254_2 = (((sec_r001834_14_2 * 3) + pub_r001834_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_44_1 * 3) + pub_r001834_3_1) + 29) & 127;
  int stage_v_255_2 = (((stage_v_44_2 * 3) + pub_r001834_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001834_1_1 * 2) + 35) & 63;
  int stage_v_256_2 = ((pub_r001834_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((sec_r001834_14_1 * 3) + pub_r001834_5_1) + 19) & 127;
  int stage_v_257_2 = (((sec_r001834_14_2 * 3) + pub_r001834_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_48_1 * 3) + pub_r001834_19_1) + 12) & 127;
  int stage_v_258_2 = (((stage_v_48_2 * 3) + pub_r001834_19_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_118_1 * 3) + pub_r001834_11_1) + 22) & 127;
  int stage_v_259_2 = (((stage_v_118_2 * 3) + pub_r001834_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_13_1 * 3) + pub_r001834_12_1) + 14) & 127;
  int stage_v_260_2 = (((stage_v_13_2 * 3) + pub_r001834_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_179_1 * 3) + pub_r001834_18_1) + 8) & 127;
  int stage_v_261_2 = (((stage_v_179_2 * 3) + pub_r001834_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_99_1 * 3) + pub_r001834_22_1) + 19) & 127;
  int stage_v_262_2 = (((stage_v_99_2 * 3) + pub_r001834_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001834_7_1 * 2) + 20) & 63;
  int stage_v_263_2 = ((pub_r001834_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_17_1 * 3) + pub_r001834_2_1) + 10) & 127;
  int stage_v_264_2 = (((stage_v_17_2 * 3) + pub_r001834_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_215_1 * 3) + pub_r001834_20_1) + 28) & 127;
  int stage_v_265_2 = (((stage_v_215_2 * 3) + pub_r001834_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001834_17_1 * 2) + 41) & 63;
  int stage_v_266_2 = ((pub_r001834_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001834_9_1 * 2) + 24) & 63;
  int stage_v_267_2 = ((pub_r001834_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001834_0_1 * 2) + 39) & 63;
  int stage_v_268_2 = ((pub_r001834_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001834_7_1 * 2) + 31) & 63;
  int stage_v_269_2 = ((pub_r001834_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001834_14_1 * 2) + 28) & 63;
  int stage_v_270_2 = ((pub_r001834_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_216_1 * 3) + pub_r001834_8_1) + 16) & 127;
  int stage_v_271_2 = (((stage_v_216_2 * 3) + pub_r001834_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_262_1 * 3) + pub_r001834_22_1) + 12) & 127;
  int stage_v_272_2 = (((stage_v_262_2 * 3) + pub_r001834_22_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_69_1 * 3) + pub_r001834_13_1) + 34) & 127;
  int stage_v_273_2 = (((stage_v_69_2 * 3) + pub_r001834_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_174_1 * 3) + pub_r001834_2_1) + 12) & 127;
  int stage_v_274_2 = (((stage_v_174_2 * 3) + pub_r001834_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_28_1 * 3) + pub_r001834_17_1) + 44) & 127;
  int stage_v_275_2 = (((stage_v_28_2 * 3) + pub_r001834_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_248_1 * 3) + pub_r001834_8_1) + 9) & 127;
  int stage_v_276_2 = (((stage_v_248_2 * 3) + pub_r001834_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001834_15_1 * 2) + 44) & 63;
  int stage_v_277_2 = ((pub_r001834_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((stage_v_105_1 * 3) + pub_r001834_8_1) + 25) & 127;
  int stage_v_278_2 = (((stage_v_105_2 * 3) + pub_r001834_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_46_1 * 3) + pub_r001834_0_1) + 6) & 127;
  int stage_v_279_2 = (((stage_v_46_2 * 3) + pub_r001834_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_260_1 * 3) + pub_r001834_20_1) + 24) & 127;
  int stage_v_280_2 = (((stage_v_260_2 * 3) + pub_r001834_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001834_17_1 * 2) + 22) & 63;
  int stage_v_281_2 = ((pub_r001834_17_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_78_1 * 3) + pub_r001834_7_1) + 14) & 127;
  int stage_v_282_2 = (((stage_v_78_2 * 3) + pub_r001834_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001834_22_1 * 2) + 41) & 63;
  int stage_v_283_2 = ((pub_r001834_22_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001834_20_1 * 2) + 26) & 63;
  int stage_v_284_2 = ((pub_r001834_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = (((stage_v_77_1 * 3) + pub_r001834_16_1) + 38) & 127;
  int stage_v_285_2 = (((stage_v_77_2 * 3) + pub_r001834_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((stage_v_82_1 * 3) + pub_r001834_1_1) + 16) & 127;
  int stage_v_286_2 = (((stage_v_82_2 * 3) + pub_r001834_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_17_1 * 3) + pub_r001834_14_1) + 11) & 127;
  int stage_v_287_2 = (((stage_v_17_2 * 3) + pub_r001834_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((helper_flow_4_1 * 3) + pub_r001834_22_1) + 21) & 127;
  int stage_v_288_2 = (((helper_flow_4_2 * 3) + pub_r001834_22_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((helper_flow_2_1 * 3) + pub_r001834_1_1) + 39) & 127;
  int stage_v_289_2 = (((helper_flow_2_2 * 3) + pub_r001834_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001834_21_1 * 2) + 9) & 63;
  int stage_v_290_2 = ((pub_r001834_21_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_72_1 * 3) + pub_r001834_15_1) + 40) & 127;
  int stage_v_291_2 = (((stage_v_72_2 * 3) + pub_r001834_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_73_1 * 3) + pub_r001834_0_1) + 31) & 127;
  int stage_v_292_2 = (((stage_v_73_2 * 3) + pub_r001834_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001834_19_1 * 2) + 40) & 63;
  int stage_v_293_2 = ((pub_r001834_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = (((stage_v_218_1 * 3) + pub_r001834_6_1) + 44) & 127;
  int stage_v_294_2 = (((stage_v_218_2 * 3) + pub_r001834_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_84_1 * 3) + pub_r001834_3_1) + 16) & 127;
  int stage_v_295_2 = (((stage_v_84_2 * 3) + pub_r001834_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001834_0_1 * 2) + 35) & 63;
  int stage_v_296_2 = ((pub_r001834_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001834_15_1 * 2) + 49) & 63;
  int stage_v_297_2 = ((pub_r001834_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_66_1 * 3) + pub_r001834_3_1) + 3) & 127;
  int stage_v_298_2 = (((stage_v_66_2 * 3) + pub_r001834_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001834_6_1 * 2) + 47) & 63;
  int stage_v_299_2 = ((pub_r001834_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((stage_v_254_1 * 3) + pub_r001834_15_1) + 27) & 127;
  int stage_v_300_2 = (((stage_v_254_2 * 3) + pub_r001834_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = ((pub_r001834_19_1 * 2) + 21) & 63;
  int stage_v_301_2 = ((pub_r001834_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((sec_r001834_21_1 * 3) + pub_r001834_4_1) + 26) & 127;
  int stage_v_302_2 = (((sec_r001834_21_2 * 3) + pub_r001834_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_49_1 * 3) + pub_r001834_1_1) + 38) & 127;
  int stage_v_303_2 = (((stage_v_49_2 * 3) + pub_r001834_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_161_1 * 3) + pub_r001834_6_1) + 27) & 127;
  int stage_v_304_2 = (((stage_v_161_2 * 3) + pub_r001834_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = (((stage_v_46_1 * 3) + pub_r001834_7_1) + 44) & 127;
  int stage_v_305_2 = (((stage_v_46_2 * 3) + pub_r001834_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001834_21_1 * 2) + 47) & 63;
  int stage_v_306_2 = ((pub_r001834_21_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((sec_r001834_16_1 * 3) + pub_r001834_3_1) + 6) & 127;
  int stage_v_307_2 = (((sec_r001834_16_2 * 3) + pub_r001834_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001834_2_1 * 2) + 28) & 63;
  int stage_v_308_2 = ((pub_r001834_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_36_1 * 3) + pub_r001834_15_1) + 3) & 127;
  int stage_v_309_2 = (((stage_v_36_2 * 3) + pub_r001834_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001834_1_1 * 2) + 32) & 63;
  int stage_v_310_2 = ((pub_r001834_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_298_1 * 3) + pub_r001834_22_1) + 12) & 127;
  int stage_v_311_2 = (((stage_v_298_2 * 3) + pub_r001834_22_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001834_6_1 * 2) + 31) & 63;
  int stage_v_312_2 = ((pub_r001834_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_114_1 * 3) + pub_r001834_13_1) + 30) & 127;
  int stage_v_313_2 = (((stage_v_114_2 * 3) + pub_r001834_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001834_21_1 * 2) + 34) & 63;
  int stage_v_314_2 = ((pub_r001834_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_161_1 * 3) + pub_r001834_19_1) + 42) & 127;
  int stage_v_315_2 = (((stage_v_161_2 * 3) + pub_r001834_19_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_106_1 * 3) + pub_r001834_7_1) + 45) & 127;
  int stage_v_316_2 = (((stage_v_106_2 * 3) + pub_r001834_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001834_0_1 * 2) + 18) & 63;
  int stage_v_317_2 = ((pub_r001834_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001834_10_1 * 2) + 37) & 63;
  int stage_v_318_2 = ((pub_r001834_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001834_18_1 * 2) + 46) & 63;
  int stage_v_319_2 = ((pub_r001834_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001834_3_1 * 2) + 30) & 63;
  int stage_v_320_2 = ((pub_r001834_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_219_1 * 3) + pub_r001834_3_1) + 24) & 127;
  int stage_v_321_2 = (((stage_v_219_2 * 3) + pub_r001834_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_68_1 * 3) + pub_r001834_18_1) + 16) & 127;
  int stage_v_322_2 = (((stage_v_68_2 * 3) + pub_r001834_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((stage_v_280_1 * 3) + pub_r001834_22_1) + 5) & 127;
  int stage_v_323_2 = (((stage_v_280_2 * 3) + pub_r001834_22_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_274_1 * 3) + pub_r001834_4_1) + 29) & 127;
  int stage_v_324_2 = (((stage_v_274_2 * 3) + pub_r001834_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_234_1 * 3) + pub_r001834_19_1) + 17) & 127;
  int stage_v_325_2 = (((stage_v_234_2 * 3) + pub_r001834_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_202_1 * 3) + pub_r001834_19_1) + 23) & 127;
  int stage_v_326_2 = (((stage_v_202_2 * 3) + pub_r001834_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001834_19_1 * 2) + 28) & 63;
  int stage_v_327_2 = ((pub_r001834_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_322_1 * 3) + pub_r001834_20_1) + 36) & 127;
  int stage_v_328_2 = (((stage_v_322_2 * 3) + pub_r001834_20_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_168_1 * 3) + pub_r001834_16_1) + 23) & 127;
  int stage_v_329_2 = (((stage_v_168_2 * 3) + pub_r001834_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001834_17_1 * 2) + 20) & 63;
  int stage_v_330_2 = ((pub_r001834_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_257_1 * 3) + pub_r001834_15_1) + 21) & 127;
  int stage_v_331_2 = (((stage_v_257_2 * 3) + pub_r001834_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = (((stage_v_170_1 * 3) + pub_r001834_19_1) + 11) & 127;
  int stage_v_332_2 = (((stage_v_170_2 * 3) + pub_r001834_19_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_61_1 * 3) + pub_r001834_11_1) + 7) & 127;
  int stage_v_333_2 = (((stage_v_61_2 * 3) + pub_r001834_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001834_22_1 * 2) + 5) & 63;
  int stage_v_334_2 = ((pub_r001834_22_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001834_18_1 * 2) + 32) & 63;
  int stage_v_335_2 = ((pub_r001834_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_275_1 * 3) + pub_r001834_3_1) + 35) & 127;
  int stage_v_336_2 = (((stage_v_275_2 * 3) + pub_r001834_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001834_11_1 * 2) + 47) & 63;
  int stage_v_337_2 = ((pub_r001834_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001834_18_1 * 2) + 23) & 63;
  int stage_v_338_2 = ((pub_r001834_18_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_227_1 * 3) + pub_r001834_0_1) + 19) & 127;
  int stage_v_339_2 = (((stage_v_227_2 * 3) + pub_r001834_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_142_1 * 3) + pub_r001834_11_1) + 27) & 127;
  int stage_v_340_2 = (((stage_v_142_2 * 3) + pub_r001834_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_49_1 * 3) + pub_r001834_2_1) + 24) & 127;
  int stage_v_341_2 = (((stage_v_49_2 * 3) + pub_r001834_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001834_19_1 * 2) + 5) & 63;
  int stage_v_342_2 = ((pub_r001834_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001834_12_1 * 2) + 11) & 63;
  int stage_v_343_2 = ((pub_r001834_12_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001834_12_1 * 2) + 23) & 63;
  int stage_v_344_2 = ((pub_r001834_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_189_1 * 3) + pub_r001834_13_1) + 10) & 127;
  int stage_v_345_2 = (((stage_v_189_2 * 3) + pub_r001834_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = ((pub_r001834_10_1 * 2) + 27) & 63;
  int stage_v_346_2 = ((pub_r001834_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001834_14_1 * 2) + 47) & 63;
  int stage_v_347_2 = ((pub_r001834_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_82_1 * 3) + pub_r001834_6_1) + 36) & 127;
  int stage_v_348_2 = (((stage_v_82_2 * 3) + pub_r001834_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_345_1 * 3) + pub_r001834_6_1) + 23) & 127;
  int stage_v_349_2 = (((stage_v_345_2 * 3) + pub_r001834_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((sec_r001834_6_1 * 3) + pub_r001834_2_1) + 38) & 127;
  int stage_v_350_2 = (((sec_r001834_6_2 * 3) + pub_r001834_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_303_1 * 3) + pub_r001834_22_1) + 19) & 127;
  int stage_v_351_2 = (((stage_v_303_2 * 3) + pub_r001834_22_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_96_1 * 3) + pub_r001834_6_1) + 36) & 127;
  int stage_v_352_2 = (((stage_v_96_2 * 3) + pub_r001834_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_2_1 * 3) + pub_r001834_17_1) + 28) & 127;
  int stage_v_353_2 = (((stage_v_2_2 * 3) + pub_r001834_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((sec_r001834_12_1 * 3) + pub_r001834_2_1) + 22) & 127;
  int stage_v_354_2 = (((sec_r001834_12_2 * 3) + pub_r001834_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001834_19_1 * 2) + 24) & 63;
  int stage_v_355_2 = ((pub_r001834_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((stage_v_238_1 * 3) + pub_r001834_11_1) + 19) & 127;
  int stage_v_356_2 = (((stage_v_238_2 * 3) + pub_r001834_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001834_1_1 * 2) + 14) & 63;
  int stage_v_357_2 = ((pub_r001834_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001834_21_1 * 2) + 19) & 63;
  int stage_v_358_2 = ((pub_r001834_21_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = (((stage_v_285_1 * 3) + pub_r001834_2_1) + 4) & 127;
  int stage_v_359_2 = (((stage_v_285_2 * 3) + pub_r001834_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((stage_v_175_1 * 3) + pub_r001834_22_1) + 44) & 127;
  int stage_v_360_2 = (((stage_v_175_2 * 3) + pub_r001834_22_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_17_1 * 3) + pub_r001834_19_1) + 19) & 127;
  int stage_v_361_2 = (((stage_v_17_2 * 3) + pub_r001834_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_238_1 * 3) + pub_r001834_16_1) + 15) & 127;
  int stage_v_362_2 = (((stage_v_238_2 * 3) + pub_r001834_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001834_11_1 * 2) + 37) & 63;
  int stage_v_363_2 = ((pub_r001834_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001834_8_1 * 2) + 31) & 63;
  int stage_v_364_2 = ((pub_r001834_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001834_9_1 * 2) + 26) & 63;
  int stage_v_365_2 = ((pub_r001834_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001834_17_1 * 2) + 41) & 63;
  int stage_v_366_2 = ((pub_r001834_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = ((pub_r001834_17_1 * 2) + 25) & 63;
  int stage_v_367_2 = ((pub_r001834_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = (((stage_v_84_1 * 3) + pub_r001834_14_1) + 15) & 127;
  int stage_v_368_2 = (((stage_v_84_2 * 3) + pub_r001834_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001834_18_1 * 2) + 40) & 63;
  int stage_v_369_2 = ((pub_r001834_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_341_1 * 3) + pub_r001834_13_1) + 13) & 127;
  int stage_v_370_2 = (((stage_v_341_2 * 3) + pub_r001834_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_311_1 * 3) + pub_r001834_12_1) + 19) & 127;
  int stage_v_371_2 = (((stage_v_311_2 * 3) + pub_r001834_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_71_1 * 3) + pub_r001834_1_1) + 11) & 127;
  int stage_v_372_2 = (((stage_v_71_2 * 3) + pub_r001834_1_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_371_1 * 3) + pub_r001834_0_1) + 19) & 127;
  int stage_v_373_2 = (((stage_v_371_2 * 3) + pub_r001834_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_250_1 * 3) + pub_r001834_18_1) + 17) & 127;
  int stage_v_374_2 = (((stage_v_250_2 * 3) + pub_r001834_18_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_261_1 * 3) + pub_r001834_16_1) + 13) & 127;
  int stage_v_375_2 = (((stage_v_261_2 * 3) + pub_r001834_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_370_1 * 3) + pub_r001834_12_1) + 23) & 127;
  int stage_v_376_2 = (((stage_v_370_2 * 3) + pub_r001834_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001834_18_1 * 2) + 48) & 63;
  int stage_v_377_2 = ((pub_r001834_18_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001834_7_1 * 2) + 41) & 63;
  int stage_v_378_2 = ((pub_r001834_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001834_8_1 * 2) + 18) & 63;
  int stage_v_379_2 = ((pub_r001834_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((sec_r001834_2_1 * 3) + pub_r001834_2_1) + 37) & 127;
  int stage_v_380_2 = (((sec_r001834_2_2 * 3) + pub_r001834_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_115_1 * 3) + pub_r001834_0_1) + 3) & 127;
  int stage_v_381_2 = (((stage_v_115_2 * 3) + pub_r001834_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_173_1 * 3) + pub_r001834_4_1) + 33) & 127;
  int stage_v_382_2 = (((stage_v_173_2 * 3) + pub_r001834_4_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_302_1 * 3) + pub_r001834_7_1) + 24) & 127;
  int stage_v_383_2 = (((stage_v_302_2 * 3) + pub_r001834_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_294_1 * 3) + pub_r001834_20_1) + 6) & 127;
  int stage_v_384_2 = (((stage_v_294_2 * 3) + pub_r001834_20_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_241_1 * 3) + pub_r001834_22_1) + 27) & 127;
  int stage_v_385_2 = (((stage_v_241_2 * 3) + pub_r001834_22_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001834_15_1 * 2) + 31) & 63;
  int stage_v_386_2 = ((pub_r001834_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001834_11_1 * 2) + 17) & 63;
  int stage_v_387_2 = ((pub_r001834_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((sec_r001834_15_1 * 3) + pub_r001834_9_1) + 41) & 127;
  int stage_v_388_2 = (((sec_r001834_15_2 * 3) + pub_r001834_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = (((stage_v_54_1 * 3) + pub_r001834_2_1) + 3) & 127;
  int stage_v_389_2 = (((stage_v_54_2 * 3) + pub_r001834_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = (((stage_v_276_1 * 3) + pub_r001834_7_1) + 12) & 127;
  int stage_v_390_2 = (((stage_v_276_2 * 3) + pub_r001834_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_248_1 * 3) + pub_r001834_2_1) + 30) & 127;
  int stage_v_391_2 = (((stage_v_248_2 * 3) + pub_r001834_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_261_1 * 3) + pub_r001834_1_1) + 6) & 127;
  int stage_v_392_2 = (((stage_v_261_2 * 3) + pub_r001834_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001834_1_1 * 2) + 34) & 63;
  int stage_v_393_2 = ((pub_r001834_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001834_15_1 * 2) + 22) & 63;
  int stage_v_394_2 = ((pub_r001834_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_391_1 * 3) + pub_r001834_10_1) + 12) & 127;
  int stage_v_395_2 = (((stage_v_391_2 * 3) + pub_r001834_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001834_13_1 * 2) + 39) & 63;
  int stage_v_396_2 = ((pub_r001834_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001834_5_1 * 2) + 15) & 63;
  int stage_v_397_2 = ((pub_r001834_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_361_1 * 3) + pub_r001834_19_1) + 33) & 127;
  int stage_v_398_2 = (((stage_v_361_2 * 3) + pub_r001834_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001834_1_1 * 2) + 45) & 63;
  int stage_v_399_2 = ((pub_r001834_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001834_15_1 * 2) + 31) & 63;
  int stage_v_400_2 = ((pub_r001834_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_25_1 * 3) + pub_r001834_5_1) + 3) & 127;
  int stage_v_401_2 = (((stage_v_25_2 * 3) + pub_r001834_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_132_1 * 3) + pub_r001834_0_1) + 3) & 127;
  int stage_v_402_2 = (((stage_v_132_2 * 3) + pub_r001834_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((sec_r001834_12_1 * 3) + pub_r001834_15_1) + 41) & 127;
  int stage_v_403_2 = (((sec_r001834_12_2 * 3) + pub_r001834_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((stage_v_289_1 * 3) + pub_r001834_6_1) + 34) & 127;
  int stage_v_404_2 = (((stage_v_289_2 * 3) + pub_r001834_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_298_1 * 3) + pub_r001834_4_1) + 30) & 127;
  int stage_v_405_2 = (((stage_v_298_2 * 3) + pub_r001834_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001834_1_1 * 2) + 38) & 63;
  int stage_v_406_2 = ((pub_r001834_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = (((stage_v_230_1 * 3) + pub_r001834_21_1) + 14) & 127;
  int stage_v_407_2 = (((stage_v_230_2 * 3) + pub_r001834_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_106_1 * 3) + pub_r001834_21_1) + 13) & 127;
  int stage_v_408_2 = (((stage_v_106_2 * 3) + pub_r001834_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_166_1 * 3) + pub_r001834_10_1) + 44) & 127;
  int stage_v_409_2 = (((stage_v_166_2 * 3) + pub_r001834_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001834_13_1 * 2) + 30) & 63;
  int stage_v_410_2 = ((pub_r001834_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_398_1 * 3) + pub_r001834_0_1) + 8) & 127;
  int stage_v_411_2 = (((stage_v_398_2 * 3) + pub_r001834_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001834_11_1 * 2) + 10) & 63;
  int stage_v_412_2 = ((pub_r001834_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_275_1 * 3) + pub_r001834_6_1) + 37) & 127;
  int stage_v_413_2 = (((stage_v_275_2 * 3) + pub_r001834_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001834_22_1 * 2) + 35) & 63;
  int stage_v_414_2 = ((pub_r001834_22_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_311_1 * 3) + pub_r001834_9_1) + 24) & 127;
  int stage_v_415_2 = (((stage_v_311_2 * 3) + pub_r001834_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = (((stage_v_29_1 * 3) + pub_r001834_1_1) + 16) & 127;
  int stage_v_416_2 = (((stage_v_29_2 * 3) + pub_r001834_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_112_1 * 3) + pub_r001834_3_1) + 24) & 127;
  int stage_v_417_2 = (((stage_v_112_2 * 3) + pub_r001834_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001834_1_1 * 2) + 19) & 63;
  int stage_v_418_2 = ((pub_r001834_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001834_9_1 * 2) + 28) & 63;
  int stage_v_419_2 = ((pub_r001834_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_148_1 * 3) + pub_r001834_7_1) + 6) & 127;
  int stage_v_420_2 = (((stage_v_148_2 * 3) + pub_r001834_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001834_4_1 * 2) + 38) & 63;
  int stage_v_421_2 = ((pub_r001834_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = (((stage_v_250_1 * 3) + pub_r001834_5_1) + 44) & 127;
  int stage_v_422_2 = (((stage_v_250_2 * 3) + pub_r001834_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = ((pub_r001834_3_1 * 2) + 12) & 63;
  int stage_v_423_2 = ((pub_r001834_3_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_305_1 * 3) + pub_r001834_7_1) + 16) & 127;
  int stage_v_424_2 = (((stage_v_305_2 * 3) + pub_r001834_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((stage_v_211_1 * 3) + pub_r001834_13_1) + 14) & 127;
  int stage_v_425_2 = (((stage_v_211_2 * 3) + pub_r001834_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001834_9_1 * 2) + 33) & 63;
  int stage_v_426_2 = ((pub_r001834_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_64_1 * 3) + pub_r001834_22_1) + 12) & 127;
  int stage_v_427_2 = (((stage_v_64_2 * 3) + pub_r001834_22_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001834_4_1 * 2) + 29) & 63;
  int stage_v_428_2 = ((pub_r001834_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_249_1 * 3) + pub_r001834_6_1) + 3) & 127;
  int stage_v_429_2 = (((stage_v_249_2 * 3) + pub_r001834_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001834_11_1 * 2) + 22) & 63;
  int stage_v_430_2 = ((pub_r001834_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_361_1 * 3) + pub_r001834_6_1) + 41) & 127;
  int stage_v_431_2 = (((stage_v_361_2 * 3) + pub_r001834_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001834_6_1 * 2) + 40) & 63;
  int stage_v_432_2 = ((pub_r001834_6_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_276_1 * 3) + pub_r001834_12_1) + 41) & 127;
  int stage_v_433_2 = (((stage_v_276_2 * 3) + pub_r001834_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001834_9_1 * 2) + 47) & 63;
  int stage_v_434_2 = ((pub_r001834_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = (((sec_r001834_11_1 * 3) + pub_r001834_6_1) + 13) & 127;
  int stage_v_435_2 = (((sec_r001834_11_2 * 3) + pub_r001834_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = (((stage_v_249_1 * 3) + pub_r001834_13_1) + 12) & 127;
  int stage_v_436_2 = (((stage_v_249_2 * 3) + pub_r001834_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_239_1 * 3) + pub_r001834_4_1) + 8) & 127;
  int stage_v_437_2 = (((stage_v_239_2 * 3) + pub_r001834_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001834_4_1 * 2) + 27) & 63;
  int stage_v_438_2 = ((pub_r001834_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001834_21_1 * 2) + 24) & 63;
  int stage_v_439_2 = ((pub_r001834_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001834_15_1 * 2) + 48) & 63;
  int stage_v_440_2 = ((pub_r001834_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001834_13_1 * 2) + 44) & 63;
  int stage_v_441_2 = ((pub_r001834_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((sec_r001834_8_1 * 3) + pub_r001834_8_1) + 23) & 127;
  int stage_v_442_2 = (((sec_r001834_8_2 * 3) + pub_r001834_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_389_1 * 3) + pub_r001834_19_1) + 41) & 127;
  int stage_v_443_2 = (((stage_v_389_2 * 3) + pub_r001834_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001834_22_1 * 2) + 17) & 63;
  int stage_v_444_2 = ((pub_r001834_22_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((stage_v_380_1 * 3) + pub_r001834_0_1) + 5) & 127;
  int stage_v_445_2 = (((stage_v_380_2 * 3) + pub_r001834_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = ((pub_r001834_20_1 * 2) + 48) & 63;
  int stage_v_446_2 = ((pub_r001834_20_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001834_4_1 * 2) + 12) & 63;
  int stage_v_447_2 = ((pub_r001834_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001834_6_1 * 2) + 38) & 63;
  int stage_v_448_2 = ((pub_r001834_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_274_1 * 3) + pub_r001834_2_1) + 4) & 127;
  int stage_v_449_2 = (((stage_v_274_2 * 3) + pub_r001834_2_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001834_15_1 * 2) + 43) & 63;
  int stage_v_450_2 = ((pub_r001834_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001834_21_1 * 2) + 12) & 63;
  int stage_v_451_2 = ((pub_r001834_21_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = (((stage_v_72_1 * 3) + pub_r001834_12_1) + 11) & 127;
  int stage_v_452_2 = (((stage_v_72_2 * 3) + pub_r001834_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = ((pub_r001834_21_1 * 2) + 44) & 63;
  int stage_v_453_2 = ((pub_r001834_21_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((stage_v_174_1 * 3) + pub_r001834_17_1) + 29) & 127;
  int stage_v_454_2 = (((stage_v_174_2 * 3) + pub_r001834_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = (((stage_v_391_1 * 3) + pub_r001834_16_1) + 30) & 127;
  int stage_v_455_2 = (((stage_v_391_2 * 3) + pub_r001834_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_326_1 * 3) + pub_r001834_21_1) + 15) & 127;
  int stage_v_456_2 = (((stage_v_326_2 * 3) + pub_r001834_21_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001834_3_1 * 2) + 31) & 63;
  int stage_v_457_2 = ((pub_r001834_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001834_20_1 * 2) + 25) & 63;
  int stage_v_458_2 = ((pub_r001834_20_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_61_1 * 3) + pub_r001834_17_1) + 24) & 127;
  int stage_v_459_2 = (((stage_v_61_2 * 3) + pub_r001834_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001834_5_1 * 2) + 50) & 63;
  int stage_v_460_2 = ((pub_r001834_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001834_18_1 * 2) + 15) & 63;
  int stage_v_461_2 = ((pub_r001834_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001834_12_1 * 2) + 5) & 63;
  int stage_v_462_2 = ((pub_r001834_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = (((stage_v_383_1 * 3) + pub_r001834_7_1) + 42) & 127;
  int stage_v_463_2 = (((stage_v_383_2 * 3) + pub_r001834_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = ((pub_r001834_1_1 * 2) + 12) & 63;
  int stage_v_464_2 = ((pub_r001834_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001834_0_1 * 2) + 36) & 63;
  int stage_v_465_2 = ((pub_r001834_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_120_1 * 3) + pub_r001834_15_1) + 32) & 127;
  int stage_v_466_2 = (((stage_v_120_2 * 3) + pub_r001834_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001834_8_1 * 2) + 5) & 63;
  int stage_v_467_2 = ((pub_r001834_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = (((stage_v_370_1 * 3) + pub_r001834_0_1) + 37) & 127;
  int stage_v_468_2 = (((stage_v_370_2 * 3) + pub_r001834_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001834_21_1 * 2) + 14) & 63;
  int stage_v_469_2 = ((pub_r001834_21_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_276_1 * 3) + pub_r001834_4_1) + 30) & 127;
  int stage_v_470_2 = (((stage_v_276_2 * 3) + pub_r001834_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((stage_v_466_1 * 3) + pub_r001834_5_1) + 40) & 127;
  int stage_v_471_2 = (((stage_v_466_2 * 3) + pub_r001834_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = ((pub_r001834_9_1 * 2) + 28) & 63;
  int stage_v_472_2 = ((pub_r001834_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = ((pub_r001834_14_1 * 2) + 36) & 63;
  int stage_v_473_2 = ((pub_r001834_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((pub_r001834_0_1 * 2) + 17) & 63;
  int stage_v_474_2 = ((pub_r001834_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = (((stage_v_38_1 * 3) + pub_r001834_17_1) + 5) & 127;
  int stage_v_475_2 = (((stage_v_38_2 * 3) + pub_r001834_17_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = (((stage_v_345_1 * 3) + pub_r001834_9_1) + 15) & 127;
  int stage_v_476_2 = (((stage_v_345_2 * 3) + pub_r001834_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((sec_r001834_0_1 * 3) + pub_r001834_4_1) + 17) & 127;
  int stage_v_477_2 = (((sec_r001834_0_2 * 3) + pub_r001834_4_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001834_22_1 * 2) + 16) & 63;
  int stage_v_478_2 = ((pub_r001834_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = (((stage_v_413_1 * 3) + pub_r001834_17_1) + 30) & 127;
  int stage_v_479_2 = (((stage_v_413_2 * 3) + pub_r001834_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = ((pub_r001834_12_1 * 2) + 42) & 63;
  int stage_v_480_2 = ((pub_r001834_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001834_22_1 == pub_r001834_22_2);
  __CPROVER_assume(pub_r001834_10_1 == pub_r001834_10_2);
  __CPROVER_assume(pub_r001834_21_1 == pub_r001834_21_2);
  __CPROVER_assume(sec_r001834_18_1 != sec_r001834_18_2);
  __CPROVER_assume(sec_r001834_2_1 != sec_r001834_2_2);
  __CPROVER_assume(pub_r001834_14_1 == pub_r001834_14_2);
  __CPROVER_assume(sec_r001834_4_1 != sec_r001834_4_2);
  __CPROVER_assume(pub_r001834_13_1 == pub_r001834_13_2);
  __CPROVER_assume(sec_r001834_21_1 != sec_r001834_21_2);
  __CPROVER_assume(pub_r001834_3_1 == pub_r001834_3_2);
  __CPROVER_assume(sec_r001834_8_1 != sec_r001834_8_2);
  __CPROVER_assume(sec_r001834_20_1 != sec_r001834_20_2);
  __CPROVER_assume(pub_r001834_1_1 == pub_r001834_1_2);
  __CPROVER_assume(sec_r001834_6_1 != sec_r001834_6_2);
  __CPROVER_assume(sec_r001834_5_1 != sec_r001834_5_2);
  __CPROVER_assume(sec_r001834_0_1 != sec_r001834_0_2);
  __CPROVER_assume(pub_r001834_7_1 == pub_r001834_7_2);
  __CPROVER_assume(pub_r001834_8_1 == pub_r001834_8_2);
  __CPROVER_assume(pub_r001834_2_1 == pub_r001834_2_2);
  __CPROVER_assume(sec_r001834_13_1 != sec_r001834_13_2);
  __CPROVER_assume(sec_r001834_16_1 != sec_r001834_16_2);
  __CPROVER_assume(sec_r001834_10_1 != sec_r001834_10_2);
  __CPROVER_assume(pub_r001834_17_1 == pub_r001834_17_2);
  __CPROVER_assume(pub_r001834_11_1 == pub_r001834_11_2);
  __CPROVER_assume(pub_r001834_5_1 == pub_r001834_5_2);
  __CPROVER_assume(sec_r001834_7_1 != sec_r001834_7_2);
  __CPROVER_assume(pub_r001834_6_1 == pub_r001834_6_2);
  __CPROVER_assume(sec_r001834_1_1 != sec_r001834_1_2);
  __CPROVER_assume(sec_r001834_11_1 != sec_r001834_11_2);
  __CPROVER_assume(pub_r001834_9_1 == pub_r001834_9_2);
  __CPROVER_assume(pub_r001834_18_1 == pub_r001834_18_2);
  __CPROVER_assume(pub_r001834_20_1 == pub_r001834_20_2);
  __CPROVER_assume(pub_r001834_12_1 == pub_r001834_12_2);
  __CPROVER_assume(sec_r001834_14_1 != sec_r001834_14_2);
  __CPROVER_assume(sec_r001834_19_1 != sec_r001834_19_2);
  __CPROVER_assume(pub_r001834_19_1 == pub_r001834_19_2);
  __CPROVER_assume(pub_r001834_16_1 == pub_r001834_16_2);
  __CPROVER_assume(sec_r001834_17_1 != sec_r001834_17_2);
  __CPROVER_assume(sec_r001834_9_1 != sec_r001834_9_2);
  __CPROVER_assume(sec_r001834_3_1 != sec_r001834_3_2);
  __CPROVER_assume(pub_r001834_15_1 == pub_r001834_15_2);
  __CPROVER_assume(sec_r001834_12_1 != sec_r001834_12_2);
  __CPROVER_assume(pub_r001834_4_1 == pub_r001834_4_2);
  __CPROVER_assume(sec_r001834_15_1 != sec_r001834_15_2);
  __CPROVER_assume(sec_r001834_22_1 != sec_r001834_22_2);
  __CPROVER_assume(pub_r001834_0_1 == pub_r001834_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  assert(st_var_0_1.stop_bits == st_var_0_2.stop_bits);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.id == st_var_0_2.id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
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
}


