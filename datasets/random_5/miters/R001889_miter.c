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
struct EventLog_R001889_8913_0
{
  int code;
  short severity;
  int signature;
  unsigned char facility;
  int buffer[3];
};
struct AudioFrame_R001889_8913_1
{
  short rms;
  int sample_rate;
  short peak;
  int channels;
  unsigned char envelope;
  int gain;
  int buffer[3];
};
struct FilterState_R001889_8913_2
{
  unsigned char prev_out;
  short damping;
  unsigned char gain_db;
  unsigned char mode;
  int cutoff;
  int buffer[3];
};
struct DeviceConfig_R001889_8913_3
{
  int port;
  int id;
  unsigned char timeout;
  int stop_bits;
  int buffer[3];
};
union PacketPayload_R001889_8913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001889_8913_1
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
void fn_R001889_8913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int mask_88_1 = 0;
  int mask_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_88_1 = ((mask_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_88_2 = ((mask_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_88_1) & 127;
    acc_2 = (acc_2 + mask_88_2) & 127;
  }

  int phase_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_88_1) & 63;
  aux_2 = (aux_2 + phase_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_78_1)
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

  switch (stride_78_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_88_1 == mask_88_2);
  assert(phase_88_1 == phase_88_2);
  assert(stride_78_1 == stride_78_2);
}

int fn_R001889_8913_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int mask_88 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_88 = ((mask_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_88) & 127;
  }

  int phase_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_88) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_78 = (aux + st.buffer[1]) & 3;
  switch (stride_78)
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

void fn_R001889_8913_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st_1 = {0};
  struct FilterState_R001889_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int delta_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_58_1) & 63;
  aux_2 = (aux_2 + delta_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_51_1)
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

  switch (stride_51_2)
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
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_58_1 == delta_58_2);
  assert(stride_51_1 == stride_51_2);
}

int fn_R001889_8913_1(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_58) & 63;
  acc ^= aux;
  int stride_51 = (aux + st.buffer[1]) & 3;
  switch (stride_51)
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

void fn_R001889_8913_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int factor_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_82_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_82_1 * 2)) + 5) & 127;
    aux_1 ^= factor_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_82_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_82_2 * 2)) + 5) & 127;
    aux_2 ^= factor_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_82_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_82_1 == factor_82_2);
}

int fn_R001889_8913_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int factor_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_82 > 48)
  {
    acc = ((acc + (factor_82 * 2)) + 5) & 127;
    aux ^= factor_82 & 15;
  }
  else
  {
    acc = ((acc - factor_82) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int phase_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_93_1)
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

  switch (phase_93_2)
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

  int phase_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_73_1) & 63;
  aux_2 = (aux_2 + phase_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_93_1 == phase_93_2);
  assert(phase_73_1 == phase_73_2);
}

int fn_R001889_8913_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int phase_93 = (aux + st.buffer[1]) & 3;
  switch (phase_93)
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

  int phase_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001889_8913_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int segment_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_29_1)
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

  switch (segment_29_2)
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

  int delta_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_34_1) & 63;
  aux_2 = (aux_2 + delta_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_59_1 = 0;
  int coefficient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_59_1 = ((coefficient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_59_2 = ((coefficient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_59_1) & 127;
    acc_2 = (acc_2 + coefficient_59_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_58_1 = local_arr_1[aux_1 % 3];
  int offset_58_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_58_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_58_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_29_1 == segment_29_2);
  assert(delta_34_1 == delta_34_2);
  assert(coefficient_59_1 == coefficient_59_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_58_1 == offset_58_2);
}

int fn_R001889_8913_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int segment_29 = (aux + st.buffer[1]) & 3;
  switch (segment_29)
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

  int delta_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_34) & 63;
  acc ^= aux;
  int coefficient_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_59 = ((coefficient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_59) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_58 = local_arr[aux % 3];
  acc = (acc + (offset_58 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_73_1)
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

  switch (pivot_73_2)
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

  int tally_69_1 = 0;
  int tally_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_69_1 = ((tally_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_69_2 = ((tally_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_69_1) & 127;
    acc_2 = (acc_2 + tally_69_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_44_1 = local_arr_1[aux_1 % 3];
  int tracker_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_73_1 == pivot_73_2);
  assert(tally_69_1 == tally_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_44_1 == tracker_44_2);
}

int fn_R001889_8913_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_73 = (aux + st.buffer[1]) & 3;
  switch (pivot_73)
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

  int tally_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_69 = ((tally_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_69) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tracker_44 = local_arr[aux % 3];
  acc = (acc + (tracker_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st_1 = {0};
  struct FilterState_R001889_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_82_1 = local_arr_1[aux_1 % 3];
  int damping_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_82_2 * 2)) & 127;
  int mask_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_36_1 > 41)
  {
    acc_1 = ((acc_1 + (mask_36_1 * 2)) + 5) & 127;
    aux_1 ^= mask_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_36_2 > 41)
  {
    acc_2 = ((acc_2 + (mask_36_2 * 2)) + 5) & 127;
    aux_2 ^= mask_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_36_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_82_1 == damping_82_2);
  assert(mask_36_1 == mask_36_2);
}

int fn_R001889_8913_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int damping_82 = local_arr[aux % 3];
  acc = (acc + (damping_82 * 2)) & 127;
  int mask_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_36 > 41)
  {
    acc = ((acc + (mask_36 * 2)) + 5) & 127;
    aux ^= mask_36 & 15;
  }
  else
  {
    acc = ((acc - mask_36) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_47_1 = local_arr_1[aux_1 % 3];
  int sample_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_47_2 * 2)) & 127;
  int sample_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_72_1) & 63;
  aux_2 = (aux_2 + sample_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_33_1 > 47)
  {
    acc_1 = ((acc_1 + (scale_33_1 * 2)) + 5) & 127;
    aux_1 ^= scale_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_33_2 > 47)
  {
    acc_2 = ((acc_2 + (scale_33_2 * 2)) + 5) & 127;
    aux_2 ^= scale_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_47_1 == sample_47_2);
  assert(sample_72_1 == sample_72_2);
  assert(scale_33_1 == scale_33_2);
}

int fn_R001889_8913_7(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int sample_47 = local_arr[aux % 3];
  acc = (acc + (sample_47 * 2)) & 127;
  int sample_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_33 > 47)
  {
    acc = ((acc + (scale_33 * 2)) + 5) & 127;
    aux ^= scale_33 & 15;
  }
  else
  {
    acc = ((acc - scale_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001889_8913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st_1 = {0};
  struct AudioFrame_R001889_8913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int factor_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_14_1)
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

  switch (factor_14_2)
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
  int residue_72_1 = local_arr_1[aux_1 % 3];
  int residue_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_72_2 * 2)) & 127;
  int checksum_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_84_1) & 63;
  aux_2 = (aux_2 + checksum_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_14_1 == factor_14_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_72_1 == residue_72_2);
  assert(checksum_84_1 == checksum_84_2);
}

int fn_R001889_8913_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int factor_14 = (aux + st.buffer[1]) & 3;
  switch (factor_14)
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
  int residue_72 = local_arr[aux % 3];
  acc = (acc + (residue_72 * 2)) & 127;
  int checksum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_84) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001889_8913_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int factor_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_30_1 > 25)
  {
    acc_1 = ((acc_1 + (factor_30_1 * 2)) + 5) & 127;
    aux_1 ^= factor_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_30_2 > 25)
  {
    acc_2 = ((acc_2 + (factor_30_2 * 2)) + 5) & 127;
    aux_2 ^= factor_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_30_1 == factor_30_2);
}

int fn_R001889_8913_9(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int factor_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_30 > 25)
  {
    acc = ((acc + (factor_30 * 2)) + 5) & 127;
    aux ^= factor_30 & 15;
  }
  else
  {
    acc = ((acc - factor_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_37_1 = local_arr_1[aux_1 % 3];
  int anchor_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_37_1 == anchor_37_2);
}

int fn_R001889_8913_10(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_37 = local_arr[aux % 3];
  acc = (acc + (anchor_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int quotient_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_26_1)
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

  switch (quotient_26_2)
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

  int sample_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_22_1 > 42)
  {
    acc_1 = ((acc_1 + (sample_22_1 * 2)) + 5) & 127;
    aux_1 ^= sample_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_22_2 > 42)
  {
    acc_2 = ((acc_2 + (sample_22_2 * 2)) + 5) & 127;
    aux_2 ^= sample_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_63_1 = local_arr_1[aux_1 % 3];
  int offset_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_26_1 == quotient_26_2);
  assert(sample_22_1 == sample_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_63_1 == offset_63_2);
}

int fn_R001889_8913_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int quotient_26 = (aux + st.buffer[1]) & 3;
  switch (quotient_26)
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

  int sample_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_22 > 42)
  {
    acc = ((acc + (sample_22 * 2)) + 5) & 127;
    aux ^= sample_22 & 15;
  }
  else
  {
    acc = ((acc - sample_22) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_63 = local_arr[aux % 3];
  acc = (acc + (offset_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_68_1)
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

  switch (cursor_68_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_52_1 = local_arr_1[aux_1 % 3];
  int offset_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_52_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_68_1 == cursor_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_52_1 == offset_52_2);
}

int fn_R001889_8913_12(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_68 = (aux + st.buffer[1]) & 3;
  switch (cursor_68)
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

  int local_arr[3] = {4, 9, 15};
  int offset_52 = local_arr[aux % 3];
  acc = (acc + (offset_52 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st_1 = {0};
  struct FilterState_R001889_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int mask_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_47_1)
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

  switch (mask_47_2)
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

  int window_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_98_1 > 19)
  {
    acc_1 = ((acc_1 + (window_98_1 * 2)) + 5) & 127;
    aux_1 ^= window_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_98_2 > 19)
  {
    acc_2 = ((acc_2 + (window_98_2 * 2)) + 5) & 127;
    aux_2 ^= window_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_14_1) & 63;
  aux_2 = (aux_2 + pivot_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_47_1 == mask_47_2);
  assert(window_98_1 == window_98_2);
  assert(pivot_14_1 == pivot_14_2);
}

int fn_R001889_8913_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int mask_47 = (aux + st.buffer[1]) & 3;
  switch (mask_47)
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

  int window_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_98 > 19)
  {
    acc = ((acc + (window_98 * 2)) + 5) & 127;
    aux ^= window_98 & 15;
  }
  else
  {
    acc = ((acc - window_98) + 11) & 127;
    aux += 3;
  }
  int pivot_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_14) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_23_1 = local_arr_1[aux_1 % 3];
  int stride_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_23_2 * 2)) & 127;
  int quotient_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_55_1) & 63;
  aux_2 = (aux_2 + quotient_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_23_1 == stride_23_2);
  assert(quotient_55_1 == quotient_55_2);
}

int fn_R001889_8913_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int stride_23 = local_arr[aux % 3];
  acc = (acc + (stride_23 * 2)) & 127;
  int quotient_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001889_8913_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int margin_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_89_1) & 63;
  aux_2 = (aux_2 + margin_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_50_1 = local_arr_1[aux_1 % 3];
  int margin_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_50_2 * 2)) & 127;
  int tally_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_70_1 > 47)
  {
    acc_1 = ((acc_1 + (tally_70_1 * 2)) + 5) & 127;
    aux_1 ^= tally_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_70_2 > 47)
  {
    acc_2 = ((acc_2 + (tally_70_2 * 2)) + 5) & 127;
    aux_2 ^= tally_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_75_1)
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

  switch (damping_75_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_89_1 == margin_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_50_1 == margin_50_2);
  assert(tally_70_1 == tally_70_2);
  assert(damping_75_1 == damping_75_2);
}

int fn_R001889_8913_15(int p0, int p1, int p2)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int margin_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_89) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_50 = local_arr[aux % 3];
  acc = (acc + (margin_50 * 2)) & 127;
  int tally_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_70 > 47)
  {
    acc = ((acc + (tally_70 * 2)) + 5) & 127;
    aux ^= tally_70 & 15;
  }
  else
  {
    acc = ((acc - tally_70) + 11) & 127;
    aux += 3;
  }
  int damping_75 = (aux + st.buffer[1]) & 3;
  switch (damping_75)
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

void fn_R001889_8913_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st_1 = {0};
  struct FilterState_R001889_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_15_1) & 63;
  aux_2 = (aux_2 + quotient_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_26_1 = local_arr_1[aux_1 % 3];
  int tracker_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_15_1 == quotient_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_26_1 == tracker_26_2);
}

int fn_R001889_8913_16(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001889_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_15) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_26 = local_arr[aux % 3];
  acc = (acc + (tracker_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st_1 = {0};
  struct AudioFrame_R001889_8913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quotient_52_1 = 0;
  int quotient_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_52_1 = ((quotient_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_52_2 = ((quotient_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_52_1) & 127;
    acc_2 = (acc_2 + quotient_52_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_82_1 = local_arr_1[aux_1 % 3];
  int quotient_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_23_1)
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

  switch (segment_23_2)
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
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_52_1 == quotient_52_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_82_1 == quotient_82_2);
  assert(segment_23_1 == segment_23_2);
}

int fn_R001889_8913_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quotient_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_52 = ((quotient_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_52) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_82 = local_arr[aux % 3];
  acc = (acc + (quotient_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_23 = (aux + st.buffer[1]) & 3;
  switch (segment_23)
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

void fn_R001889_8913_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int anchor_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_24_1 > 37)
  {
    acc_1 = ((acc_1 + (anchor_24_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_24_2 > 37)
  {
    acc_2 = ((acc_2 + (anchor_24_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_94_1)
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

  switch (tracker_94_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_24_1 == anchor_24_2);
  assert(tracker_94_1 == tracker_94_2);
}

int fn_R001889_8913_18(int p0, int p1, int p2)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int anchor_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_24 > 37)
  {
    acc = ((acc + (anchor_24 * 2)) + 5) & 127;
    aux ^= anchor_24 & 15;
  }
  else
  {
    acc = ((acc - anchor_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_94 = (aux + st.buffer[1]) & 3;
  switch (tracker_94)
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

void fn_R001889_8913_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st_1 = {0};
  struct AudioFrame_R001889_8913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_12_1)
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

  switch (parity_12_2)
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

  int weight_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_67_1 > 15)
  {
    acc_1 = ((acc_1 + (weight_67_1 * 2)) + 5) & 127;
    aux_1 ^= weight_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_67_2 > 15)
  {
    acc_2 = ((acc_2 + (weight_67_2 * 2)) + 5) & 127;
    aux_2 ^= weight_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_12_1 == parity_12_2);
  assert(weight_67_1 == weight_67_2);
}

int fn_R001889_8913_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_12 = (aux + st.buffer[1]) & 3;
  switch (parity_12)
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

  int weight_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_67 > 15)
  {
    acc = ((acc + (weight_67 * 2)) + 5) & 127;
    aux ^= weight_67 & 15;
  }
  else
  {
    acc = ((acc - weight_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001889_8913_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int parity_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_13_1)
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

  switch (parity_13_2)
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
  int threshold_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_25_1) & 63;
  aux_2 = (aux_2 + threshold_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_88_1 = local_arr_1[aux_1 % 3];
  int anchor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_13_1 == parity_13_2);
  assert(threshold_25_1 == threshold_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_88_1 == anchor_88_2);
}

int fn_R001889_8913_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int parity_13 = (aux + st.buffer[1]) & 3;
  switch (parity_13)
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
  int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_25) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int anchor_88 = local_arr[aux % 3];
  acc = (acc + (anchor_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001889_8913_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st_1 = {0};
  struct EventLog_R001889_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int bound_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_75_1) & 63;
  aux_2 = (aux_2 + bound_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_42_1 = 0;
  int delta_42_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_42_1 = ((delta_42_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_42_2 = ((delta_42_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_42_1) & 127;
    acc_2 = (acc_2 + delta_42_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_75_1 == bound_75_2);
  assert(delta_42_1 == delta_42_2);
}

int fn_R001889_8913_21(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001889_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int bound_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_75) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_42 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_42 = ((delta_42 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_42) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001889_8913_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_84_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_84_1 * 2)) + 5) & 127;
    aux_1 ^= residue_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_84_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_84_2 * 2)) + 5) & 127;
    aux_2 ^= residue_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_24_1) & 63;
  aux_2 = (aux_2 + quantum_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_28_1)
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

  switch (stride_28_2)
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

  int factor_35_1 = 0;
  int factor_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_35_1 = ((factor_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_35_2 = ((factor_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_35_1) & 127;
    acc_2 = (acc_2 + factor_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_84_1 == residue_84_2);
  assert(quantum_24_1 == quantum_24_2);
  assert(stride_28_1 == stride_28_2);
  assert(factor_35_1 == factor_35_2);
}

int fn_R001889_8913_22(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001889_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_84 > 40)
  {
    acc = ((acc + (residue_84 * 2)) + 5) & 127;
    aux ^= residue_84 & 15;
  }
  else
  {
    acc = ((acc - residue_84) + 11) & 127;
    aux += 3;
  }
  int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_24) & 63;
  acc ^= aux;
  int stride_28 = (aux + st.buffer[1]) & 3;
  switch (stride_28)
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

  int factor_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_35 = ((factor_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001889_8913_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st_1 = {0};
  struct AudioFrame_R001889_8913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int sample_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_19_1)
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

  switch (sample_19_2)
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

  int index_reg_96_1 = 0;
  int index_reg_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_96_1 = ((index_reg_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_96_2 = ((index_reg_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_96_1) & 127;
    acc_2 = (acc_2 + index_reg_96_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_18_1 = local_arr_1[aux_1 % 3];
  int quotient_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_18_2 * 2)) & 127;
  int pivot_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_68_1 > 47)
  {
    acc_1 = ((acc_1 + (pivot_68_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_68_2 > 47)
  {
    acc_2 = ((acc_2 + (pivot_68_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.channels == st_2.channels);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_19_1 == sample_19_2);
  assert(index_reg_96_1 == index_reg_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_18_1 == quotient_18_2);
  assert(pivot_68_1 == pivot_68_2);
}

int fn_R001889_8913_23(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001889_8913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int sample_19 = (aux + st.buffer[1]) & 3;
  switch (sample_19)
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

  int index_reg_96 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_96 = ((index_reg_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_96) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int quotient_18 = local_arr[aux % 3];
  acc = (acc + (quotient_18 * 2)) & 127;
  int pivot_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_68 > 47)
  {
    acc = ((acc + (pivot_68 * 2)) + 5) & 127;
    aux ^= pivot_68 & 15;
  }
  else
  {
    acc = ((acc - pivot_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001889_0_1;
  int sec_r001889_0_2;
  int sec_r001889_1_1;
  int sec_r001889_1_2;
  int sec_r001889_2_1;
  int sec_r001889_2_2;
  int sec_r001889_3_1;
  int sec_r001889_3_2;
  int sec_r001889_4_1;
  int sec_r001889_4_2;
  int sec_r001889_5_1;
  int sec_r001889_5_2;
  int sec_r001889_6_1;
  int sec_r001889_6_2;
  int sec_r001889_7_1;
  int sec_r001889_7_2;
  int sec_r001889_8_1;
  int sec_r001889_8_2;
  int sec_r001889_9_1;
  int sec_r001889_9_2;
  int sec_r001889_10_1;
  int sec_r001889_10_2;
  int sec_r001889_11_1;
  int sec_r001889_11_2;
  int sec_r001889_12_1;
  int sec_r001889_12_2;
  int sec_r001889_13_1;
  int sec_r001889_13_2;
  int sec_r001889_14_1;
  int sec_r001889_14_2;
  int sec_r001889_15_1;
  int sec_r001889_15_2;
  int sec_r001889_16_1;
  int sec_r001889_16_2;
  int sec_r001889_17_1;
  int sec_r001889_17_2;
  int sec_r001889_18_1;
  int sec_r001889_18_2;
  int sec_r001889_19_1;
  int sec_r001889_19_2;
  int sec_r001889_20_1;
  int sec_r001889_20_2;
  int pub_r001889_0_1;
  int pub_r001889_0_2;
  int pub_r001889_1_1;
  int pub_r001889_1_2;
  int pub_r001889_2_1;
  int pub_r001889_2_2;
  int pub_r001889_3_1;
  int pub_r001889_3_2;
  int pub_r001889_4_1;
  int pub_r001889_4_2;
  int pub_r001889_5_1;
  int pub_r001889_5_2;
  int pub_r001889_6_1;
  int pub_r001889_6_2;
  int pub_r001889_7_1;
  int pub_r001889_7_2;
  int pub_r001889_8_1;
  int pub_r001889_8_2;
  int pub_r001889_9_1;
  int pub_r001889_9_2;
  int pub_r001889_10_1;
  int pub_r001889_10_2;
  int pub_r001889_11_1;
  int pub_r001889_11_2;
  int pub_r001889_12_1;
  int pub_r001889_12_2;
  int pub_r001889_13_1;
  int pub_r001889_13_2;
  int pub_r001889_14_1;
  int pub_r001889_14_2;
  int pub_r001889_15_1;
  int pub_r001889_15_2;
  int pub_r001889_16_1;
  int pub_r001889_16_2;
  int pub_r001889_17_1;
  int pub_r001889_17_2;
  int pub_r001889_18_1;
  int pub_r001889_18_2;
  int pub_r001889_19_1;
  int pub_r001889_19_2;
  int pub_r001889_20_1;
  int pub_r001889_20_2;
  int pub_r001889_21_1;
  int pub_r001889_21_2;
  int pub_r001889_22_1;
  int pub_r001889_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001889_0_1 >= (-100)) && (pub_r001889_0_1 <= 100));
  __CPROVER_assume((pub_r001889_0_2 >= (-100)) && (pub_r001889_0_2 <= 100));
  __CPROVER_assume((pub_r001889_1_1 >= (-100)) && (pub_r001889_1_1 <= 100));
  __CPROVER_assume((pub_r001889_1_2 >= (-100)) && (pub_r001889_1_2 <= 100));
  __CPROVER_assume((pub_r001889_2_1 >= (-100)) && (pub_r001889_2_1 <= 100));
  __CPROVER_assume((pub_r001889_2_2 >= (-100)) && (pub_r001889_2_2 <= 100));
  __CPROVER_assume((pub_r001889_3_1 >= (-100)) && (pub_r001889_3_1 <= 100));
  __CPROVER_assume((pub_r001889_3_2 >= (-100)) && (pub_r001889_3_2 <= 100));
  __CPROVER_assume((pub_r001889_4_1 >= (-100)) && (pub_r001889_4_1 <= 100));
  __CPROVER_assume((pub_r001889_4_2 >= (-100)) && (pub_r001889_4_2 <= 100));
  __CPROVER_assume((pub_r001889_5_1 >= (-100)) && (pub_r001889_5_1 <= 100));
  __CPROVER_assume((pub_r001889_5_2 >= (-100)) && (pub_r001889_5_2 <= 100));
  __CPROVER_assume((pub_r001889_6_1 >= (-100)) && (pub_r001889_6_1 <= 100));
  __CPROVER_assume((pub_r001889_6_2 >= (-100)) && (pub_r001889_6_2 <= 100));
  __CPROVER_assume((pub_r001889_7_1 >= (-100)) && (pub_r001889_7_1 <= 100));
  __CPROVER_assume((pub_r001889_7_2 >= (-100)) && (pub_r001889_7_2 <= 100));
  __CPROVER_assume((pub_r001889_8_1 >= (-100)) && (pub_r001889_8_1 <= 100));
  __CPROVER_assume((pub_r001889_8_2 >= (-100)) && (pub_r001889_8_2 <= 100));
  __CPROVER_assume((pub_r001889_9_1 >= (-100)) && (pub_r001889_9_1 <= 100));
  __CPROVER_assume((pub_r001889_9_2 >= (-100)) && (pub_r001889_9_2 <= 100));
  __CPROVER_assume((pub_r001889_10_1 >= (-100)) && (pub_r001889_10_1 <= 100));
  __CPROVER_assume((pub_r001889_10_2 >= (-100)) && (pub_r001889_10_2 <= 100));
  __CPROVER_assume((pub_r001889_11_1 >= (-100)) && (pub_r001889_11_1 <= 100));
  __CPROVER_assume((pub_r001889_11_2 >= (-100)) && (pub_r001889_11_2 <= 100));
  __CPROVER_assume((pub_r001889_12_1 >= (-100)) && (pub_r001889_12_1 <= 100));
  __CPROVER_assume((pub_r001889_12_2 >= (-100)) && (pub_r001889_12_2 <= 100));
  __CPROVER_assume((pub_r001889_13_1 >= (-100)) && (pub_r001889_13_1 <= 100));
  __CPROVER_assume((pub_r001889_13_2 >= (-100)) && (pub_r001889_13_2 <= 100));
  __CPROVER_assume((pub_r001889_14_1 >= (-100)) && (pub_r001889_14_1 <= 100));
  __CPROVER_assume((pub_r001889_14_2 >= (-100)) && (pub_r001889_14_2 <= 100));
  __CPROVER_assume((pub_r001889_15_1 >= (-100)) && (pub_r001889_15_1 <= 100));
  __CPROVER_assume((pub_r001889_15_2 >= (-100)) && (pub_r001889_15_2 <= 100));
  __CPROVER_assume((pub_r001889_16_1 >= (-100)) && (pub_r001889_16_1 <= 100));
  __CPROVER_assume((pub_r001889_16_2 >= (-100)) && (pub_r001889_16_2 <= 100));
  __CPROVER_assume((pub_r001889_17_1 >= (-100)) && (pub_r001889_17_1 <= 100));
  __CPROVER_assume((pub_r001889_17_2 >= (-100)) && (pub_r001889_17_2 <= 100));
  __CPROVER_assume((pub_r001889_18_1 >= (-100)) && (pub_r001889_18_1 <= 100));
  __CPROVER_assume((pub_r001889_18_2 >= (-100)) && (pub_r001889_18_2 <= 100));
  __CPROVER_assume((pub_r001889_19_1 >= (-100)) && (pub_r001889_19_1 <= 100));
  __CPROVER_assume((pub_r001889_19_2 >= (-100)) && (pub_r001889_19_2 <= 100));
  __CPROVER_assume((pub_r001889_20_1 >= (-100)) && (pub_r001889_20_1 <= 100));
  __CPROVER_assume((pub_r001889_20_2 >= (-100)) && (pub_r001889_20_2 <= 100));
  __CPROVER_assume((pub_r001889_21_1 >= (-100)) && (pub_r001889_21_1 <= 100));
  __CPROVER_assume((pub_r001889_21_2 >= (-100)) && (pub_r001889_21_2 <= 100));
  __CPROVER_assume((pub_r001889_22_1 >= (-100)) && (pub_r001889_22_1 <= 100));
  __CPROVER_assume((pub_r001889_22_2 >= (-100)) && (pub_r001889_22_2 <= 100));
  __CPROVER_assume((sec_r001889_0_1 >= 0) && (sec_r001889_0_1 <= 255));
  __CPROVER_assume((sec_r001889_0_2 >= 0) && (sec_r001889_0_2 <= 255));
  __CPROVER_assume((sec_r001889_1_1 >= 0) && (sec_r001889_1_1 <= 255));
  __CPROVER_assume((sec_r001889_1_2 >= 0) && (sec_r001889_1_2 <= 255));
  __CPROVER_assume((sec_r001889_2_1 >= 0) && (sec_r001889_2_1 <= 255));
  __CPROVER_assume((sec_r001889_2_2 >= 0) && (sec_r001889_2_2 <= 255));
  __CPROVER_assume((sec_r001889_3_1 >= 0) && (sec_r001889_3_1 <= 255));
  __CPROVER_assume((sec_r001889_3_2 >= 0) && (sec_r001889_3_2 <= 255));
  __CPROVER_assume((sec_r001889_4_1 >= 0) && (sec_r001889_4_1 <= 255));
  __CPROVER_assume((sec_r001889_4_2 >= 0) && (sec_r001889_4_2 <= 255));
  __CPROVER_assume((sec_r001889_5_1 >= 0) && (sec_r001889_5_1 <= 255));
  __CPROVER_assume((sec_r001889_5_2 >= 0) && (sec_r001889_5_2 <= 255));
  __CPROVER_assume((sec_r001889_6_1 >= 0) && (sec_r001889_6_1 <= 255));
  __CPROVER_assume((sec_r001889_6_2 >= 0) && (sec_r001889_6_2 <= 255));
  __CPROVER_assume((sec_r001889_7_1 >= 0) && (sec_r001889_7_1 <= 255));
  __CPROVER_assume((sec_r001889_7_2 >= 0) && (sec_r001889_7_2 <= 255));
  __CPROVER_assume((sec_r001889_8_1 >= 0) && (sec_r001889_8_1 <= 255));
  __CPROVER_assume((sec_r001889_8_2 >= 0) && (sec_r001889_8_2 <= 255));
  __CPROVER_assume((sec_r001889_9_1 >= 0) && (sec_r001889_9_1 <= 255));
  __CPROVER_assume((sec_r001889_9_2 >= 0) && (sec_r001889_9_2 <= 255));
  __CPROVER_assume((sec_r001889_10_1 >= 0) && (sec_r001889_10_1 <= 255));
  __CPROVER_assume((sec_r001889_10_2 >= 0) && (sec_r001889_10_2 <= 255));
  __CPROVER_assume((sec_r001889_11_1 >= 0) && (sec_r001889_11_1 <= 255));
  __CPROVER_assume((sec_r001889_11_2 >= 0) && (sec_r001889_11_2 <= 255));
  __CPROVER_assume((sec_r001889_12_1 >= 0) && (sec_r001889_12_1 <= 255));
  __CPROVER_assume((sec_r001889_12_2 >= 0) && (sec_r001889_12_2 <= 255));
  __CPROVER_assume((sec_r001889_13_1 >= 0) && (sec_r001889_13_1 <= 255));
  __CPROVER_assume((sec_r001889_13_2 >= 0) && (sec_r001889_13_2 <= 255));
  __CPROVER_assume((sec_r001889_14_1 >= 0) && (sec_r001889_14_1 <= 255));
  __CPROVER_assume((sec_r001889_14_2 >= 0) && (sec_r001889_14_2 <= 255));
  __CPROVER_assume((sec_r001889_15_1 >= 0) && (sec_r001889_15_1 <= 255));
  __CPROVER_assume((sec_r001889_15_2 >= 0) && (sec_r001889_15_2 <= 255));
  __CPROVER_assume((sec_r001889_16_1 >= 0) && (sec_r001889_16_1 <= 255));
  __CPROVER_assume((sec_r001889_16_2 >= 0) && (sec_r001889_16_2 <= 255));
  __CPROVER_assume((sec_r001889_17_1 >= 0) && (sec_r001889_17_1 <= 255));
  __CPROVER_assume((sec_r001889_17_2 >= 0) && (sec_r001889_17_2 <= 255));
  __CPROVER_assume((sec_r001889_18_1 >= 0) && (sec_r001889_18_1 <= 255));
  __CPROVER_assume((sec_r001889_18_2 >= 0) && (sec_r001889_18_2 <= 255));
  __CPROVER_assume((sec_r001889_19_1 >= 0) && (sec_r001889_19_1 <= 255));
  __CPROVER_assume((sec_r001889_19_2 >= 0) && (sec_r001889_19_2 <= 255));
  __CPROVER_assume((sec_r001889_20_1 >= 0) && (sec_r001889_20_1 <= 255));
  __CPROVER_assume((sec_r001889_20_2 >= 0) && (sec_r001889_20_2 <= 255));
  struct EventLog_R001889_8913_0 st_var_0_1 = {0};
  struct EventLog_R001889_8913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001889_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001889_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001889_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001889_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001889_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001889_0_2 + 7) & 15;
  struct AudioFrame_R001889_8913_1 st_var_1_1 = {0};
  struct AudioFrame_R001889_8913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001889_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001889_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001889_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001889_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001889_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001889_0_2 + 9) & 15;
  struct FilterState_R001889_8913_2 st_var_2_1 = {0};
  struct FilterState_R001889_8913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001889_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001889_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001889_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001889_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001889_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001889_0_2 + 11) & 15;
  struct DeviceConfig_R001889_8913_3 st_var_3_1 = {0};
  struct DeviceConfig_R001889_8913_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001889_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001889_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001889_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001889_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001889_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001889_0_2 + 13) & 15;
  union PacketPayload_R001889_8913_0 u_var_1;
  union PacketPayload_R001889_8913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001889_8913_0(sec_r001889_0_1, pub_r001889_1_1, pub_r001889_2_1, pub_r001889_3_1);
  int helper_flow_0_2 = fn_R001889_8913_0(sec_r001889_0_2, pub_r001889_1_2, pub_r001889_2_2, pub_r001889_3_2);
  fn_R001889_8913_0_2(sec_r001889_0_1, pub_r001889_1_1, pub_r001889_2_1, pub_r001889_3_1, sec_r001889_0_2, pub_r001889_1_2, pub_r001889_2_2, pub_r001889_3_2);
  int helper_flow_1_1 = fn_R001889_8913_1(sec_r001889_1_1, sec_r001889_2_1, pub_r001889_3_1);
  int helper_flow_1_2 = fn_R001889_8913_1(sec_r001889_1_2, sec_r001889_2_2, pub_r001889_3_2);
  fn_R001889_8913_1_2(sec_r001889_1_1, sec_r001889_2_1, pub_r001889_3_1, sec_r001889_1_2, sec_r001889_2_2, pub_r001889_3_2);
  int helper_flow_2_1 = fn_R001889_8913_2(sec_r001889_2_1, pub_r001889_3_1, pub_r001889_4_1, pub_r001889_5_1);
  int helper_flow_2_2 = fn_R001889_8913_2(sec_r001889_2_2, pub_r001889_3_2, pub_r001889_4_2, pub_r001889_5_2);
  fn_R001889_8913_2_2(sec_r001889_2_1, pub_r001889_3_1, pub_r001889_4_1, pub_r001889_5_1, sec_r001889_2_2, pub_r001889_3_2, pub_r001889_4_2, pub_r001889_5_2);
  int helper_flow_3_1 = fn_R001889_8913_3(sec_r001889_3_1, pub_r001889_4_1, pub_r001889_5_1, pub_r001889_6_1, pub_r001889_7_1);
  int helper_flow_3_2 = fn_R001889_8913_3(sec_r001889_3_2, pub_r001889_4_2, pub_r001889_5_2, pub_r001889_6_2, pub_r001889_7_2);
  fn_R001889_8913_3_2(sec_r001889_3_1, pub_r001889_4_1, pub_r001889_5_1, pub_r001889_6_1, pub_r001889_7_1, sec_r001889_3_2, pub_r001889_4_2, pub_r001889_5_2, pub_r001889_6_2, pub_r001889_7_2);
  int helper_flow_4_1 = fn_R001889_8913_4(sec_r001889_4_1, pub_r001889_5_1, pub_r001889_6_1, pub_r001889_7_1);
  int helper_flow_4_2 = fn_R001889_8913_4(sec_r001889_4_2, pub_r001889_5_2, pub_r001889_6_2, pub_r001889_7_2);
  fn_R001889_8913_4_2(sec_r001889_4_1, pub_r001889_5_1, pub_r001889_6_1, pub_r001889_7_1, sec_r001889_4_2, pub_r001889_5_2, pub_r001889_6_2, pub_r001889_7_2);
  int stage_v_0_1 = table_1[0] + (sec_r001889_4_1 & 7);
  int stage_v_0_2 = table_2[0] + (sec_r001889_4_2 & 7);
  table_1[0] = (stage_v_0_1 + pub_r001889_0_1) & 63;
  table_2[0] = (stage_v_0_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_0_1 & 127;
  out_sink_2 ^= stage_v_0_2 & 127;
  int stage_v_1_1 = ((pub_r001889_0_1 * 2) + 19) & 63;
  int stage_v_1_2 = ((pub_r001889_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001889_2_1 * 2) + 24) & 63;
  int stage_v_2_2 = ((pub_r001889_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = table_1[3] + (sec_r001889_17_1 & 7);
  int stage_v_3_2 = table_2[3] + (sec_r001889_17_2 & 7);
  table_1[3] = (stage_v_3_1 + pub_r001889_17_1) & 63;
  table_2[3] = (stage_v_3_2 + pub_r001889_17_2) & 63;
  out_sink_1 ^= stage_v_3_1 & 127;
  out_sink_2 ^= stage_v_3_2 & 127;
  int stage_v_4_1 = ((pub_r001889_0_1 * 2) + 49) & 63;
  int stage_v_4_2 = ((pub_r001889_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = table_1[1] + (helper_flow_1_1 & 7);
  int stage_v_5_2 = table_2[1] + (helper_flow_1_2 & 7);
  table_1[1] = (stage_v_5_1 + pub_r001889_18_1) & 63;
  table_2[1] = (stage_v_5_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_5_1 & 127;
  out_sink_2 ^= stage_v_5_2 & 127;
  int stage_v_6_1 = ((pub_r001889_17_1 * 2) + 34) & 63;
  int stage_v_6_2 = ((pub_r001889_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = table_1[3] + (sec_r001889_20_1 & 7);
  int stage_v_7_2 = table_2[3] + (sec_r001889_20_2 & 7);
  table_1[3] = (stage_v_7_1 + pub_r001889_9_1) & 63;
  table_2[3] = (stage_v_7_2 + pub_r001889_9_2) & 63;
  out_sink_1 ^= stage_v_7_1 & 127;
  out_sink_2 ^= stage_v_7_2 & 127;
  int stage_v_8_1 = table_1[0] + (sec_r001889_13_1 & 7);
  int stage_v_8_2 = table_2[0] + (sec_r001889_13_2 & 7);
  table_1[0] = (stage_v_8_1 + pub_r001889_11_1) & 63;
  table_2[0] = (stage_v_8_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_8_1 & 127;
  out_sink_2 ^= stage_v_8_2 & 127;
  int stage_v_9_1 = ((pub_r001889_4_1 * 2) + 41) & 63;
  int stage_v_9_2 = ((pub_r001889_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001889_0_1 * 2) + 49) & 63;
  int stage_v_10_2 = ((pub_r001889_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = table_1[3] + (sec_r001889_12_1 & 7);
  int stage_v_11_2 = table_2[3] + (sec_r001889_12_2 & 7);
  table_1[3] = (stage_v_11_1 + pub_r001889_15_1) & 63;
  table_2[3] = (stage_v_11_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_11_1 & 127;
  out_sink_2 ^= stage_v_11_2 & 127;
  int stage_v_12_1 = table_1[0] + (sec_r001889_10_1 & 7);
  int stage_v_12_2 = table_2[0] + (sec_r001889_10_2 & 7);
  table_1[0] = (stage_v_12_1 + pub_r001889_13_1) & 63;
  table_2[0] = (stage_v_12_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_12_1 & 127;
  out_sink_2 ^= stage_v_12_2 & 127;
  int stage_v_13_1 = ((pub_r001889_19_1 * 2) + 28) & 63;
  int stage_v_13_2 = ((pub_r001889_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = table_1[2] + (sec_r001889_3_1 & 7);
  int stage_v_14_2 = table_2[2] + (sec_r001889_3_2 & 7);
  table_1[2] = (stage_v_14_1 + pub_r001889_7_1) & 63;
  table_2[2] = (stage_v_14_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_14_1 & 127;
  out_sink_2 ^= stage_v_14_2 & 127;
  int stage_v_15_1 = ((pub_r001889_17_1 * 2) + 34) & 63;
  int stage_v_15_2 = ((pub_r001889_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001889_3_1 * 2) + 33) & 63;
  int stage_v_16_2 = ((pub_r001889_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001889_0_1 * 2) + 5) & 63;
  int stage_v_17_2 = ((pub_r001889_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = table_1[2] + (sec_r001889_3_1 & 7);
  int stage_v_18_2 = table_2[2] + (sec_r001889_3_2 & 7);
  table_1[2] = (stage_v_18_1 + pub_r001889_22_1) & 63;
  table_2[2] = (stage_v_18_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_18_1 & 127;
  out_sink_2 ^= stage_v_18_2 & 127;
  int stage_v_19_1 = table_1[3] + (sec_r001889_13_1 & 7);
  int stage_v_19_2 = table_2[3] + (sec_r001889_13_2 & 7);
  table_1[3] = (stage_v_19_1 + pub_r001889_13_1) & 63;
  table_2[3] = (stage_v_19_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_19_1 & 127;
  out_sink_2 ^= stage_v_19_2 & 127;
  int stage_v_20_1 = ((pub_r001889_7_1 * 2) + 49) & 63;
  int stage_v_20_2 = ((pub_r001889_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001889_12_1 * 2) + 5) & 63;
  int stage_v_21_2 = ((pub_r001889_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = table_1[2] + (stage_v_14_1 & 7);
  int stage_v_22_2 = table_2[2] + (stage_v_14_2 & 7);
  table_1[2] = (stage_v_22_1 + pub_r001889_21_1) & 63;
  table_2[2] = (stage_v_22_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_22_1 & 127;
  out_sink_2 ^= stage_v_22_2 & 127;
  int stage_v_23_1 = ((pub_r001889_16_1 * 2) + 45) & 63;
  int stage_v_23_2 = ((pub_r001889_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001889_9_1 * 2) + 19) & 63;
  int stage_v_24_2 = ((pub_r001889_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = table_1[1] + (sec_r001889_12_1 & 7);
  int stage_v_25_2 = table_2[1] + (sec_r001889_12_2 & 7);
  table_1[1] = (stage_v_25_1 + pub_r001889_15_1) & 63;
  table_2[1] = (stage_v_25_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_25_1 & 127;
  out_sink_2 ^= stage_v_25_2 & 127;
  int stage_v_26_1 = table_1[2] + (sec_r001889_6_1 & 7);
  int stage_v_26_2 = table_2[2] + (sec_r001889_6_2 & 7);
  table_1[2] = (stage_v_26_1 + pub_r001889_16_1) & 63;
  table_2[2] = (stage_v_26_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_26_1 & 127;
  out_sink_2 ^= stage_v_26_2 & 127;
  int stage_v_27_1 = table_1[3] + (sec_r001889_4_1 & 7);
  int stage_v_27_2 = table_2[3] + (sec_r001889_4_2 & 7);
  table_1[3] = (stage_v_27_1 + pub_r001889_8_1) & 63;
  table_2[3] = (stage_v_27_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_27_1 & 127;
  out_sink_2 ^= stage_v_27_2 & 127;
  int stage_v_28_1 = ((pub_r001889_0_1 * 2) + 23) & 63;
  int stage_v_28_2 = ((pub_r001889_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001889_4_1 * 2) + 36) & 63;
  int stage_v_29_2 = ((pub_r001889_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = table_1[2] + (stage_v_0_1 & 7);
  int stage_v_30_2 = table_2[2] + (stage_v_0_2 & 7);
  table_1[2] = (stage_v_30_1 + pub_r001889_22_1) & 63;
  table_2[2] = (stage_v_30_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_30_1 & 127;
  out_sink_2 ^= stage_v_30_2 & 127;
  int stage_v_31_1 = ((pub_r001889_2_1 * 2) + 36) & 63;
  int stage_v_31_2 = ((pub_r001889_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = table_1[0] + (sec_r001889_1_1 & 7);
  int stage_v_32_2 = table_2[0] + (sec_r001889_1_2 & 7);
  table_1[0] = (stage_v_32_1 + pub_r001889_22_1) & 63;
  table_2[0] = (stage_v_32_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_32_1 & 127;
  out_sink_2 ^= stage_v_32_2 & 127;
  int stage_v_33_1 = ((pub_r001889_7_1 * 2) + 15) & 63;
  int stage_v_33_2 = ((pub_r001889_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001889_3_1 * 2) + 34) & 63;
  int stage_v_34_2 = ((pub_r001889_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = table_1[3] + (stage_v_0_1 & 7);
  int stage_v_35_2 = table_2[3] + (stage_v_0_2 & 7);
  table_1[3] = (stage_v_35_1 + pub_r001889_20_1) & 63;
  table_2[3] = (stage_v_35_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_35_1 & 127;
  out_sink_2 ^= stage_v_35_2 & 127;
  int stage_v_36_1 = ((pub_r001889_12_1 * 2) + 32) & 63;
  int stage_v_36_2 = ((pub_r001889_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = table_1[1] + (stage_v_27_1 & 7);
  int stage_v_37_2 = table_2[1] + (stage_v_27_2 & 7);
  table_1[1] = (stage_v_37_1 + pub_r001889_13_1) & 63;
  table_2[1] = (stage_v_37_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_37_1 & 127;
  out_sink_2 ^= stage_v_37_2 & 127;
  int stage_v_38_1 = table_1[2] + (stage_v_37_1 & 7);
  int stage_v_38_2 = table_2[2] + (stage_v_37_2 & 7);
  table_1[2] = (stage_v_38_1 + pub_r001889_5_1) & 63;
  table_2[2] = (stage_v_38_2 + pub_r001889_5_2) & 63;
  out_sink_1 ^= stage_v_38_1 & 127;
  out_sink_2 ^= stage_v_38_2 & 127;
  int stage_v_39_1 = ((pub_r001889_19_1 * 2) + 50) & 63;
  int stage_v_39_2 = ((pub_r001889_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = table_1[0] + (sec_r001889_6_1 & 7);
  int stage_v_40_2 = table_2[0] + (sec_r001889_6_2 & 7);
  table_1[0] = (stage_v_40_1 + pub_r001889_8_1) & 63;
  table_2[0] = (stage_v_40_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_40_1 & 127;
  out_sink_2 ^= stage_v_40_2 & 127;
  int stage_v_41_1 = ((pub_r001889_2_1 * 2) + 23) & 63;
  int stage_v_41_2 = ((pub_r001889_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001889_8_1 * 2) + 41) & 63;
  int stage_v_42_2 = ((pub_r001889_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001889_3_1 * 2) + 48) & 63;
  int stage_v_43_2 = ((pub_r001889_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = table_1[0] + (sec_r001889_13_1 & 7);
  int stage_v_44_2 = table_2[0] + (sec_r001889_13_2 & 7);
  table_1[0] = (stage_v_44_1 + pub_r001889_14_1) & 63;
  table_2[0] = (stage_v_44_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_44_1 & 127;
  out_sink_2 ^= stage_v_44_2 & 127;
  int stage_v_45_1 = table_1[1] + (stage_v_22_1 & 7);
  int stage_v_45_2 = table_2[1] + (stage_v_22_2 & 7);
  table_1[1] = (stage_v_45_1 + pub_r001889_16_1) & 63;
  table_2[1] = (stage_v_45_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_45_1 & 127;
  out_sink_2 ^= stage_v_45_2 & 127;
  int stage_v_46_1 = ((pub_r001889_9_1 * 2) + 9) & 63;
  int stage_v_46_2 = ((pub_r001889_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001889_9_1 * 2) + 18) & 63;
  int stage_v_47_2 = ((pub_r001889_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001889_20_1 * 2) + 46) & 63;
  int stage_v_48_2 = ((pub_r001889_20_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = table_1[1] + (sec_r001889_9_1 & 7);
  int stage_v_49_2 = table_2[1] + (sec_r001889_9_2 & 7);
  table_1[1] = (stage_v_49_1 + pub_r001889_16_1) & 63;
  table_2[1] = (stage_v_49_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_49_1 & 127;
  out_sink_2 ^= stage_v_49_2 & 127;
  int stage_v_50_1 = ((pub_r001889_2_1 * 2) + 49) & 63;
  int stage_v_50_2 = ((pub_r001889_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = table_1[3] + (stage_v_35_1 & 7);
  int stage_v_51_2 = table_2[3] + (stage_v_35_2 & 7);
  table_1[3] = (stage_v_51_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_51_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_51_1 & 127;
  out_sink_2 ^= stage_v_51_2 & 127;
  int stage_v_52_1 = ((pub_r001889_5_1 * 2) + 49) & 63;
  int stage_v_52_2 = ((pub_r001889_5_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = table_1[1] + (stage_v_51_1 & 7);
  int stage_v_53_2 = table_2[1] + (stage_v_51_2 & 7);
  table_1[1] = (stage_v_53_1 + pub_r001889_13_1) & 63;
  table_2[1] = (stage_v_53_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_53_1 & 127;
  out_sink_2 ^= stage_v_53_2 & 127;
  int stage_v_54_1 = ((pub_r001889_4_1 * 2) + 26) & 63;
  int stage_v_54_2 = ((pub_r001889_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = table_1[3] + (sec_r001889_4_1 & 7);
  int stage_v_55_2 = table_2[3] + (sec_r001889_4_2 & 7);
  table_1[3] = (stage_v_55_1 + pub_r001889_4_1) & 63;
  table_2[3] = (stage_v_55_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_55_1 & 127;
  out_sink_2 ^= stage_v_55_2 & 127;
  int stage_v_56_1 = table_1[0] + (stage_v_30_1 & 7);
  int stage_v_56_2 = table_2[0] + (stage_v_30_2 & 7);
  table_1[0] = (stage_v_56_1 + pub_r001889_16_1) & 63;
  table_2[0] = (stage_v_56_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_56_1 & 127;
  out_sink_2 ^= stage_v_56_2 & 127;
  int stage_v_57_1 = table_1[1] + (stage_v_11_1 & 7);
  int stage_v_57_2 = table_2[1] + (stage_v_11_2 & 7);
  table_1[1] = (stage_v_57_1 + pub_r001889_2_1) & 63;
  table_2[1] = (stage_v_57_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_57_1 & 127;
  out_sink_2 ^= stage_v_57_2 & 127;
  int stage_v_58_1 = ((pub_r001889_2_1 * 2) + 37) & 63;
  int stage_v_58_2 = ((pub_r001889_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = table_1[3] + (stage_v_19_1 & 7);
  int stage_v_59_2 = table_2[3] + (stage_v_19_2 & 7);
  table_1[3] = (stage_v_59_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_59_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_59_1 & 127;
  out_sink_2 ^= stage_v_59_2 & 127;
  int stage_v_60_1 = ((pub_r001889_18_1 * 2) + 6) & 63;
  int stage_v_60_2 = ((pub_r001889_18_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = table_1[1] + (helper_flow_0_1 & 7);
  int stage_v_61_2 = table_2[1] + (helper_flow_0_2 & 7);
  table_1[1] = (stage_v_61_1 + pub_r001889_19_1) & 63;
  table_2[1] = (stage_v_61_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_61_1 & 127;
  out_sink_2 ^= stage_v_61_2 & 127;
  int stage_v_62_1 = ((pub_r001889_8_1 * 2) + 31) & 63;
  int stage_v_62_2 = ((pub_r001889_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001889_14_1 * 2) + 7) & 63;
  int stage_v_63_2 = ((pub_r001889_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = table_1[0] + (sec_r001889_10_1 & 7);
  int stage_v_64_2 = table_2[0] + (sec_r001889_10_2 & 7);
  table_1[0] = (stage_v_64_1 + pub_r001889_10_1) & 63;
  table_2[0] = (stage_v_64_2 + pub_r001889_10_2) & 63;
  out_sink_1 ^= stage_v_64_1 & 127;
  out_sink_2 ^= stage_v_64_2 & 127;
  int stage_v_65_1 = table_1[1] + (sec_r001889_4_1 & 7);
  int stage_v_65_2 = table_2[1] + (sec_r001889_4_2 & 7);
  table_1[1] = (stage_v_65_1 + pub_r001889_11_1) & 63;
  table_2[1] = (stage_v_65_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_65_1 & 127;
  out_sink_2 ^= stage_v_65_2 & 127;
  int stage_v_66_1 = ((pub_r001889_7_1 * 2) + 16) & 63;
  int stage_v_66_2 = ((pub_r001889_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = table_1[3] + (sec_r001889_19_1 & 7);
  int stage_v_67_2 = table_2[3] + (sec_r001889_19_2 & 7);
  table_1[3] = (stage_v_67_1 + pub_r001889_13_1) & 63;
  table_2[3] = (stage_v_67_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_67_1 & 127;
  out_sink_2 ^= stage_v_67_2 & 127;
  int stage_v_68_1 = table_1[0] + (stage_v_53_1 & 7);
  int stage_v_68_2 = table_2[0] + (stage_v_53_2 & 7);
  table_1[0] = (stage_v_68_1 + pub_r001889_19_1) & 63;
  table_2[0] = (stage_v_68_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_68_1 & 127;
  out_sink_2 ^= stage_v_68_2 & 127;
  int stage_v_69_1 = ((pub_r001889_3_1 * 2) + 8) & 63;
  int stage_v_69_2 = ((pub_r001889_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001889_20_1 * 2) + 20) & 63;
  int stage_v_70_2 = ((pub_r001889_20_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001889_2_1 * 2) + 13) & 63;
  int stage_v_71_2 = ((pub_r001889_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001889_11_1 * 2) + 26) & 63;
  int stage_v_72_2 = ((pub_r001889_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = table_1[1] + (stage_v_61_1 & 7);
  int stage_v_73_2 = table_2[1] + (stage_v_61_2 & 7);
  table_1[1] = (stage_v_73_1 + pub_r001889_20_1) & 63;
  table_2[1] = (stage_v_73_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_73_1 & 127;
  out_sink_2 ^= stage_v_73_2 & 127;
  int stage_v_74_1 = table_1[2] + (stage_v_57_1 & 7);
  int stage_v_74_2 = table_2[2] + (stage_v_57_2 & 7);
  table_1[2] = (stage_v_74_1 + pub_r001889_3_1) & 63;
  table_2[2] = (stage_v_74_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_74_1 & 127;
  out_sink_2 ^= stage_v_74_2 & 127;
  int stage_v_75_1 = ((pub_r001889_4_1 * 2) + 10) & 63;
  int stage_v_75_2 = ((pub_r001889_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001889_9_1 * 2) + 6) & 63;
  int stage_v_76_2 = ((pub_r001889_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001889_18_1 * 2) + 20) & 63;
  int stage_v_77_2 = ((pub_r001889_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = table_1[2] + (stage_v_8_1 & 7);
  int stage_v_78_2 = table_2[2] + (stage_v_8_2 & 7);
  table_1[2] = (stage_v_78_1 + pub_r001889_5_1) & 63;
  table_2[2] = (stage_v_78_2 + pub_r001889_5_2) & 63;
  out_sink_1 ^= stage_v_78_1 & 127;
  out_sink_2 ^= stage_v_78_2 & 127;
  int stage_v_79_1 = table_1[3] + (stage_v_68_1 & 7);
  int stage_v_79_2 = table_2[3] + (stage_v_68_2 & 7);
  table_1[3] = (stage_v_79_1 + pub_r001889_3_1) & 63;
  table_2[3] = (stage_v_79_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_79_1 & 127;
  out_sink_2 ^= stage_v_79_2 & 127;
  int stage_v_80_1 = ((pub_r001889_1_1 * 2) + 36) & 63;
  int stage_v_80_2 = ((pub_r001889_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = table_1[1] + (stage_v_78_1 & 7);
  int stage_v_81_2 = table_2[1] + (stage_v_78_2 & 7);
  table_1[1] = (stage_v_81_1 + pub_r001889_10_1) & 63;
  table_2[1] = (stage_v_81_2 + pub_r001889_10_2) & 63;
  out_sink_1 ^= stage_v_81_1 & 127;
  out_sink_2 ^= stage_v_81_2 & 127;
  int stage_v_82_1 = ((pub_r001889_15_1 * 2) + 43) & 63;
  int stage_v_82_2 = ((pub_r001889_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = table_1[3] + (stage_v_57_1 & 7);
  int stage_v_83_2 = table_2[3] + (stage_v_57_2 & 7);
  table_1[3] = (stage_v_83_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_83_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_83_1 & 127;
  out_sink_2 ^= stage_v_83_2 & 127;
  int stage_v_84_1 = table_1[0] + (stage_v_38_1 & 7);
  int stage_v_84_2 = table_2[0] + (stage_v_38_2 & 7);
  table_1[0] = (stage_v_84_1 + pub_r001889_1_1) & 63;
  table_2[0] = (stage_v_84_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_84_1 & 127;
  out_sink_2 ^= stage_v_84_2 & 127;
  int stage_v_85_1 = ((pub_r001889_21_1 * 2) + 41) & 63;
  int stage_v_85_2 = ((pub_r001889_21_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((pub_r001889_5_1 * 2) + 13) & 63;
  int stage_v_86_2 = ((pub_r001889_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001889_21_1 * 2) + 13) & 63;
  int stage_v_87_2 = ((pub_r001889_21_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001889_21_1 * 2) + 50) & 63;
  int stage_v_88_2 = ((pub_r001889_21_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001889_4_1 * 2) + 21) & 63;
  int stage_v_89_2 = ((pub_r001889_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = table_1[2] + (sec_r001889_11_1 & 7);
  int stage_v_90_2 = table_2[2] + (sec_r001889_11_2 & 7);
  table_1[2] = (stage_v_90_1 + pub_r001889_15_1) & 63;
  table_2[2] = (stage_v_90_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_90_1 & 127;
  out_sink_2 ^= stage_v_90_2 & 127;
  int stage_v_91_1 = table_1[3] + (sec_r001889_12_1 & 7);
  int stage_v_91_2 = table_2[3] + (sec_r001889_12_2 & 7);
  table_1[3] = (stage_v_91_1 + pub_r001889_20_1) & 63;
  table_2[3] = (stage_v_91_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_91_1 & 127;
  out_sink_2 ^= stage_v_91_2 & 127;
  int stage_v_92_1 = table_1[0] + (sec_r001889_1_1 & 7);
  int stage_v_92_2 = table_2[0] + (sec_r001889_1_2 & 7);
  table_1[0] = (stage_v_92_1 + pub_r001889_1_1) & 63;
  table_2[0] = (stage_v_92_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_92_1 & 127;
  out_sink_2 ^= stage_v_92_2 & 127;
  int stage_v_93_1 = table_1[1] + (stage_v_26_1 & 7);
  int stage_v_93_2 = table_2[1] + (stage_v_26_2 & 7);
  table_1[1] = (stage_v_93_1 + pub_r001889_15_1) & 63;
  table_2[1] = (stage_v_93_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_93_1 & 127;
  out_sink_2 ^= stage_v_93_2 & 127;
  int stage_v_94_1 = table_1[2] + (helper_flow_3_1 & 7);
  int stage_v_94_2 = table_2[2] + (helper_flow_3_2 & 7);
  table_1[2] = (stage_v_94_1 + pub_r001889_4_1) & 63;
  table_2[2] = (stage_v_94_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_94_1 & 127;
  out_sink_2 ^= stage_v_94_2 & 127;
  int stage_v_95_1 = ((pub_r001889_8_1 * 2) + 7) & 63;
  int stage_v_95_2 = ((pub_r001889_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001889_22_1 * 2) + 8) & 63;
  int stage_v_96_2 = ((pub_r001889_22_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001889_17_1 * 2) + 36) & 63;
  int stage_v_97_2 = ((pub_r001889_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001889_0_1 * 2) + 20) & 63;
  int stage_v_98_2 = ((pub_r001889_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001889_14_1 * 2) + 13) & 63;
  int stage_v_99_2 = ((pub_r001889_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = table_1[0] + (stage_v_37_1 & 7);
  int stage_v_100_2 = table_2[0] + (stage_v_37_2 & 7);
  table_1[0] = (stage_v_100_1 + pub_r001889_22_1) & 63;
  table_2[0] = (stage_v_100_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_100_1 & 127;
  out_sink_2 ^= stage_v_100_2 & 127;
  int stage_v_101_1 = table_1[1] + (sec_r001889_15_1 & 7);
  int stage_v_101_2 = table_2[1] + (sec_r001889_15_2 & 7);
  table_1[1] = (stage_v_101_1 + pub_r001889_20_1) & 63;
  table_2[1] = (stage_v_101_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_101_1 & 127;
  out_sink_2 ^= stage_v_101_2 & 127;
  int stage_v_102_1 = table_1[2] + (stage_v_38_1 & 7);
  int stage_v_102_2 = table_2[2] + (stage_v_38_2 & 7);
  table_1[2] = (stage_v_102_1 + pub_r001889_20_1) & 63;
  table_2[2] = (stage_v_102_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_102_1 & 127;
  out_sink_2 ^= stage_v_102_2 & 127;
  int stage_v_103_1 = ((pub_r001889_21_1 * 2) + 18) & 63;
  int stage_v_103_2 = ((pub_r001889_21_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = table_1[0] + (sec_r001889_5_1 & 7);
  int stage_v_104_2 = table_2[0] + (sec_r001889_5_2 & 7);
  table_1[0] = (stage_v_104_1 + pub_r001889_18_1) & 63;
  table_2[0] = (stage_v_104_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_104_1 & 127;
  out_sink_2 ^= stage_v_104_2 & 127;
  int stage_v_105_1 = ((pub_r001889_2_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001889_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001889_13_1 * 2) + 38) & 63;
  int stage_v_106_2 = ((pub_r001889_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001889_9_1 * 2) + 36) & 63;
  int stage_v_107_2 = ((pub_r001889_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001889_4_1 * 2) + 44) & 63;
  int stage_v_108_2 = ((pub_r001889_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001889_20_1 * 2) + 12) & 63;
  int stage_v_109_2 = ((pub_r001889_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001889_13_1 * 2) + 44) & 63;
  int stage_v_110_2 = ((pub_r001889_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = table_1[3] + (stage_v_94_1 & 7);
  int stage_v_111_2 = table_2[3] + (stage_v_94_2 & 7);
  table_1[3] = (stage_v_111_1 + pub_r001889_22_1) & 63;
  table_2[3] = (stage_v_111_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_111_1 & 127;
  out_sink_2 ^= stage_v_111_2 & 127;
  int stage_v_112_1 = table_1[0] + (sec_r001889_3_1 & 7);
  int stage_v_112_2 = table_2[0] + (sec_r001889_3_2 & 7);
  table_1[0] = (stage_v_112_1 + pub_r001889_2_1) & 63;
  table_2[0] = (stage_v_112_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_112_1 & 127;
  out_sink_2 ^= stage_v_112_2 & 127;
  int stage_v_113_1 = ((pub_r001889_13_1 * 2) + 10) & 63;
  int stage_v_113_2 = ((pub_r001889_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001889_15_1 * 2) + 15) & 63;
  int stage_v_114_2 = ((pub_r001889_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001889_3_1 * 2) + 25) & 63;
  int stage_v_115_2 = ((pub_r001889_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001889_1_1 * 2) + 41) & 63;
  int stage_v_116_2 = ((pub_r001889_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001889_9_1 * 2) + 5) & 63;
  int stage_v_117_2 = ((pub_r001889_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001889_8_1 * 2) + 16) & 63;
  int stage_v_118_2 = ((pub_r001889_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = table_1[3] + (stage_v_100_1 & 7);
  int stage_v_119_2 = table_2[3] + (stage_v_100_2 & 7);
  table_1[3] = (stage_v_119_1 + pub_r001889_8_1) & 63;
  table_2[3] = (stage_v_119_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_119_1 & 127;
  out_sink_2 ^= stage_v_119_2 & 127;
  int stage_v_120_1 = ((pub_r001889_3_1 * 2) + 50) & 63;
  int stage_v_120_2 = ((pub_r001889_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001889_11_1 * 2) + 41) & 63;
  int stage_v_121_2 = ((pub_r001889_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001889_0_1 * 2) + 26) & 63;
  int stage_v_122_2 = ((pub_r001889_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001889_14_1 * 2) + 19) & 63;
  int stage_v_123_2 = ((pub_r001889_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001889_14_1 * 2) + 27) & 63;
  int stage_v_124_2 = ((pub_r001889_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = table_1[1] + (stage_v_78_1 & 7);
  int stage_v_125_2 = table_2[1] + (stage_v_78_2 & 7);
  table_1[1] = (stage_v_125_1 + pub_r001889_15_1) & 63;
  table_2[1] = (stage_v_125_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_125_1 & 127;
  out_sink_2 ^= stage_v_125_2 & 127;
  int stage_v_126_1 = ((pub_r001889_12_1 * 2) + 18) & 63;
  int stage_v_126_2 = ((pub_r001889_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = table_1[3] + (stage_v_93_1 & 7);
  int stage_v_127_2 = table_2[3] + (stage_v_93_2 & 7);
  table_1[3] = (stage_v_127_1 + pub_r001889_11_1) & 63;
  table_2[3] = (stage_v_127_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_127_1 & 127;
  out_sink_2 ^= stage_v_127_2 & 127;
  int stage_v_128_1 = table_1[0] + (stage_v_91_1 & 7);
  int stage_v_128_2 = table_2[0] + (stage_v_91_2 & 7);
  table_1[0] = (stage_v_128_1 + pub_r001889_6_1) & 63;
  table_2[0] = (stage_v_128_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_128_1 & 127;
  out_sink_2 ^= stage_v_128_2 & 127;
  int stage_v_129_1 = ((pub_r001889_9_1 * 2) + 22) & 63;
  int stage_v_129_2 = ((pub_r001889_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001889_1_1 * 2) + 14) & 63;
  int stage_v_130_2 = ((pub_r001889_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001889_6_1 * 2) + 26) & 63;
  int stage_v_131_2 = ((pub_r001889_6_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001889_6_1 * 2) + 12) & 63;
  int stage_v_132_2 = ((pub_r001889_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001889_12_1 * 2) + 35) & 63;
  int stage_v_133_2 = ((pub_r001889_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001889_14_1 * 2) + 20) & 63;
  int stage_v_134_2 = ((pub_r001889_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = table_1[3] + (stage_v_55_1 & 7);
  int stage_v_135_2 = table_2[3] + (stage_v_55_2 & 7);
  table_1[3] = (stage_v_135_1 + pub_r001889_6_1) & 63;
  table_2[3] = (stage_v_135_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_135_1 & 127;
  out_sink_2 ^= stage_v_135_2 & 127;
  int stage_v_136_1 = ((pub_r001889_18_1 * 2) + 20) & 63;
  int stage_v_136_2 = ((pub_r001889_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001889_20_1 * 2) + 6) & 63;
  int stage_v_137_2 = ((pub_r001889_20_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = table_1[2] + (stage_v_112_1 & 7);
  int stage_v_138_2 = table_2[2] + (stage_v_112_2 & 7);
  table_1[2] = (stage_v_138_1 + pub_r001889_10_1) & 63;
  table_2[2] = (stage_v_138_2 + pub_r001889_10_2) & 63;
  out_sink_1 ^= stage_v_138_1 & 127;
  out_sink_2 ^= stage_v_138_2 & 127;
  int stage_v_139_1 = ((pub_r001889_16_1 * 2) + 43) & 63;
  int stage_v_139_2 = ((pub_r001889_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001889_8_1 * 2) + 30) & 63;
  int stage_v_140_2 = ((pub_r001889_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001889_12_1 * 2) + 32) & 63;
  int stage_v_141_2 = ((pub_r001889_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = table_1[2] + (helper_flow_0_1 & 7);
  int stage_v_142_2 = table_2[2] + (helper_flow_0_2 & 7);
  table_1[2] = (stage_v_142_1 + pub_r001889_10_1) & 63;
  table_2[2] = (stage_v_142_2 + pub_r001889_10_2) & 63;
  out_sink_1 ^= stage_v_142_1 & 127;
  out_sink_2 ^= stage_v_142_2 & 127;
  int stage_v_143_1 = ((pub_r001889_4_1 * 2) + 25) & 63;
  int stage_v_143_2 = ((pub_r001889_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001889_12_1 * 2) + 13) & 63;
  int stage_v_144_2 = ((pub_r001889_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001889_19_1 * 2) + 23) & 63;
  int stage_v_145_2 = ((pub_r001889_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001889_6_1 * 2) + 18) & 63;
  int stage_v_146_2 = ((pub_r001889_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = table_1[3] + (stage_v_49_1 & 7);
  int stage_v_147_2 = table_2[3] + (stage_v_49_2 & 7);
  table_1[3] = (stage_v_147_1 + pub_r001889_22_1) & 63;
  table_2[3] = (stage_v_147_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_147_1 & 127;
  out_sink_2 ^= stage_v_147_2 & 127;
  int stage_v_148_1 = ((pub_r001889_10_1 * 2) + 5) & 63;
  int stage_v_148_2 = ((pub_r001889_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001889_14_1 * 2) + 36) & 63;
  int stage_v_149_2 = ((pub_r001889_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001889_15_1 * 2) + 38) & 63;
  int stage_v_150_2 = ((pub_r001889_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = table_1[3] + (stage_v_45_1 & 7);
  int stage_v_151_2 = table_2[3] + (stage_v_45_2 & 7);
  table_1[3] = (stage_v_151_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_151_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_151_1 & 127;
  out_sink_2 ^= stage_v_151_2 & 127;
  int stage_v_152_1 = table_1[0] + (stage_v_45_1 & 7);
  int stage_v_152_2 = table_2[0] + (stage_v_45_2 & 7);
  table_1[0] = (stage_v_152_1 + pub_r001889_22_1) & 63;
  table_2[0] = (stage_v_152_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_152_1 & 127;
  out_sink_2 ^= stage_v_152_2 & 127;
  int stage_v_153_1 = table_1[1] + (stage_v_40_1 & 7);
  int stage_v_153_2 = table_2[1] + (stage_v_40_2 & 7);
  table_1[1] = (stage_v_153_1 + pub_r001889_20_1) & 63;
  table_2[1] = (stage_v_153_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_153_1 & 127;
  out_sink_2 ^= stage_v_153_2 & 127;
  int stage_v_154_1 = ((pub_r001889_4_1 * 2) + 31) & 63;
  int stage_v_154_2 = ((pub_r001889_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = table_1[3] + (stage_v_151_1 & 7);
  int stage_v_155_2 = table_2[3] + (stage_v_151_2 & 7);
  table_1[3] = (stage_v_155_1 + pub_r001889_3_1) & 63;
  table_2[3] = (stage_v_155_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_155_1 & 127;
  out_sink_2 ^= stage_v_155_2 & 127;
  int stage_v_156_1 = ((pub_r001889_0_1 * 2) + 30) & 63;
  int stage_v_156_2 = ((pub_r001889_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001889_18_1 * 2) + 12) & 63;
  int stage_v_157_2 = ((pub_r001889_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001889_8_1 * 2) + 49) & 63;
  int stage_v_158_2 = ((pub_r001889_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001889_18_1 * 2) + 20) & 63;
  int stage_v_159_2 = ((pub_r001889_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001889_22_1 * 2) + 11) & 63;
  int stage_v_160_2 = ((pub_r001889_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = table_1[1] + (stage_v_12_1 & 7);
  int stage_v_161_2 = table_2[1] + (stage_v_12_2 & 7);
  table_1[1] = (stage_v_161_1 + pub_r001889_14_1) & 63;
  table_2[1] = (stage_v_161_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_161_1 & 127;
  out_sink_2 ^= stage_v_161_2 & 127;
  int stage_v_162_1 = ((pub_r001889_22_1 * 2) + 43) & 63;
  int stage_v_162_2 = ((pub_r001889_22_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = table_1[3] + (stage_v_65_1 & 7);
  int stage_v_163_2 = table_2[3] + (stage_v_65_2 & 7);
  table_1[3] = (stage_v_163_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_163_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_163_1 & 127;
  out_sink_2 ^= stage_v_163_2 & 127;
  int stage_v_164_1 = ((pub_r001889_8_1 * 2) + 42) & 63;
  int stage_v_164_2 = ((pub_r001889_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001889_5_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001889_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001889_14_1 * 2) + 12) & 63;
  int stage_v_166_2 = ((pub_r001889_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = table_1[3] + (helper_flow_1_1 & 7);
  int stage_v_167_2 = table_2[3] + (helper_flow_1_2 & 7);
  table_1[3] = (stage_v_167_1 + pub_r001889_4_1) & 63;
  table_2[3] = (stage_v_167_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_167_1 & 127;
  out_sink_2 ^= stage_v_167_2 & 127;
  int stage_v_168_1 = ((pub_r001889_2_1 * 2) + 17) & 63;
  int stage_v_168_2 = ((pub_r001889_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001889_22_1 * 2) + 6) & 63;
  int stage_v_169_2 = ((pub_r001889_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001889_7_1 * 2) + 20) & 63;
  int stage_v_170_2 = ((pub_r001889_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = table_1[3] + (stage_v_163_1 & 7);
  int stage_v_171_2 = table_2[3] + (stage_v_163_2 & 7);
  table_1[3] = (stage_v_171_1 + pub_r001889_8_1) & 63;
  table_2[3] = (stage_v_171_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_171_1 & 127;
  out_sink_2 ^= stage_v_171_2 & 127;
  int stage_v_172_1 = table_1[0] + (stage_v_14_1 & 7);
  int stage_v_172_2 = table_2[0] + (stage_v_14_2 & 7);
  table_1[0] = (stage_v_172_1 + pub_r001889_16_1) & 63;
  table_2[0] = (stage_v_172_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_172_1 & 127;
  out_sink_2 ^= stage_v_172_2 & 127;
  int stage_v_173_1 = ((pub_r001889_20_1 * 2) + 36) & 63;
  int stage_v_173_2 = ((pub_r001889_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = table_1[2] + (stage_v_73_1 & 7);
  int stage_v_174_2 = table_2[2] + (stage_v_73_2 & 7);
  table_1[2] = (stage_v_174_1 + pub_r001889_0_1) & 63;
  table_2[2] = (stage_v_174_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_174_1 & 127;
  out_sink_2 ^= stage_v_174_2 & 127;
  int stage_v_175_1 = ((pub_r001889_6_1 * 2) + 37) & 63;
  int stage_v_175_2 = ((pub_r001889_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = table_1[0] + (stage_v_55_1 & 7);
  int stage_v_176_2 = table_2[0] + (stage_v_55_2 & 7);
  table_1[0] = (stage_v_176_1 + pub_r001889_20_1) & 63;
  table_2[0] = (stage_v_176_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_176_1 & 127;
  out_sink_2 ^= stage_v_176_2 & 127;
  int stage_v_177_1 = ((pub_r001889_4_1 * 2) + 37) & 63;
  int stage_v_177_2 = ((pub_r001889_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001889_20_1 * 2) + 27) & 63;
  int stage_v_178_2 = ((pub_r001889_20_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = table_1[3] + (sec_r001889_16_1 & 7);
  int stage_v_179_2 = table_2[3] + (sec_r001889_16_2 & 7);
  table_1[3] = (stage_v_179_1 + pub_r001889_7_1) & 63;
  table_2[3] = (stage_v_179_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_179_1 & 127;
  out_sink_2 ^= stage_v_179_2 & 127;
  int stage_v_180_1 = table_1[0] + (stage_v_12_1 & 7);
  int stage_v_180_2 = table_2[0] + (stage_v_12_2 & 7);
  table_1[0] = (stage_v_180_1 + pub_r001889_3_1) & 63;
  table_2[0] = (stage_v_180_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_180_1 & 127;
  out_sink_2 ^= stage_v_180_2 & 127;
  int stage_v_181_1 = table_1[1] + (stage_v_22_1 & 7);
  int stage_v_181_2 = table_2[1] + (stage_v_22_2 & 7);
  table_1[1] = (stage_v_181_1 + pub_r001889_1_1) & 63;
  table_2[1] = (stage_v_181_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_181_1 & 127;
  out_sink_2 ^= stage_v_181_2 & 127;
  int stage_v_182_1 = ((pub_r001889_9_1 * 2) + 48) & 63;
  int stage_v_182_2 = ((pub_r001889_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001889_20_1 * 2) + 21) & 63;
  int stage_v_183_2 = ((pub_r001889_20_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = table_1[0] + (stage_v_56_1 & 7);
  int stage_v_184_2 = table_2[0] + (stage_v_56_2 & 7);
  table_1[0] = (stage_v_184_1 + pub_r001889_11_1) & 63;
  table_2[0] = (stage_v_184_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_184_1 & 127;
  out_sink_2 ^= stage_v_184_2 & 127;
  int stage_v_185_1 = ((pub_r001889_15_1 * 2) + 6) & 63;
  int stage_v_185_2 = ((pub_r001889_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001889_6_1 * 2) + 7) & 63;
  int stage_v_186_2 = ((pub_r001889_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001889_7_1 * 2) + 46) & 63;
  int stage_v_187_2 = ((pub_r001889_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = table_1[0] + (stage_v_111_1 & 7);
  int stage_v_188_2 = table_2[0] + (stage_v_111_2 & 7);
  table_1[0] = (stage_v_188_1 + pub_r001889_6_1) & 63;
  table_2[0] = (stage_v_188_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_188_1 & 127;
  out_sink_2 ^= stage_v_188_2 & 127;
  int stage_v_189_1 = table_1[1] + (stage_v_90_1 & 7);
  int stage_v_189_2 = table_2[1] + (stage_v_90_2 & 7);
  table_1[1] = (stage_v_189_1 + pub_r001889_9_1) & 63;
  table_2[1] = (stage_v_189_2 + pub_r001889_9_2) & 63;
  out_sink_1 ^= stage_v_189_1 & 127;
  out_sink_2 ^= stage_v_189_2 & 127;
  int stage_v_190_1 = ((pub_r001889_7_1 * 2) + 33) & 63;
  int stage_v_190_2 = ((pub_r001889_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = table_1[3] + (stage_v_26_1 & 7);
  int stage_v_191_2 = table_2[3] + (stage_v_26_2 & 7);
  table_1[3] = (stage_v_191_1 + pub_r001889_20_1) & 63;
  table_2[3] = (stage_v_191_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_191_1 & 127;
  out_sink_2 ^= stage_v_191_2 & 127;
  int stage_v_192_1 = ((pub_r001889_4_1 * 2) + 27) & 63;
  int stage_v_192_2 = ((pub_r001889_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001889_3_1 * 2) + 21) & 63;
  int stage_v_193_2 = ((pub_r001889_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001889_11_1 * 2) + 19) & 63;
  int stage_v_194_2 = ((pub_r001889_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001889_10_1 * 2) + 9) & 63;
  int stage_v_195_2 = ((pub_r001889_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = table_1[0] + (stage_v_184_1 & 7);
  int stage_v_196_2 = table_2[0] + (stage_v_184_2 & 7);
  table_1[0] = (stage_v_196_1 + pub_r001889_7_1) & 63;
  table_2[0] = (stage_v_196_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_196_1 & 127;
  out_sink_2 ^= stage_v_196_2 & 127;
  int stage_v_197_1 = table_1[1] + (stage_v_167_1 & 7);
  int stage_v_197_2 = table_2[1] + (stage_v_167_2 & 7);
  table_1[1] = (stage_v_197_1 + pub_r001889_12_1) & 63;
  table_2[1] = (stage_v_197_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_197_1 & 127;
  out_sink_2 ^= stage_v_197_2 & 127;
  int stage_v_198_1 = ((pub_r001889_0_1 * 2) + 43) & 63;
  int stage_v_198_2 = ((pub_r001889_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = table_1[3] + (stage_v_61_1 & 7);
  int stage_v_199_2 = table_2[3] + (stage_v_61_2 & 7);
  table_1[3] = (stage_v_199_1 + pub_r001889_22_1) & 63;
  table_2[3] = (stage_v_199_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_199_1 & 127;
  out_sink_2 ^= stage_v_199_2 & 127;
  int stage_v_200_1 = ((pub_r001889_13_1 * 2) + 40) & 63;
  int stage_v_200_2 = ((pub_r001889_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = table_1[1] + (stage_v_51_1 & 7);
  int stage_v_201_2 = table_2[1] + (stage_v_51_2 & 7);
  table_1[1] = (stage_v_201_1 + pub_r001889_17_1) & 63;
  table_2[1] = (stage_v_201_2 + pub_r001889_17_2) & 63;
  out_sink_1 ^= stage_v_201_1 & 127;
  out_sink_2 ^= stage_v_201_2 & 127;
  int stage_v_202_1 = table_1[2] + (stage_v_151_1 & 7);
  int stage_v_202_2 = table_2[2] + (stage_v_151_2 & 7);
  table_1[2] = (stage_v_202_1 + pub_r001889_21_1) & 63;
  table_2[2] = (stage_v_202_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_202_1 & 127;
  out_sink_2 ^= stage_v_202_2 & 127;
  int stage_v_203_1 = ((pub_r001889_4_1 * 2) + 24) & 63;
  int stage_v_203_2 = ((pub_r001889_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = table_1[0] + (helper_flow_4_1 & 7);
  int stage_v_204_2 = table_2[0] + (helper_flow_4_2 & 7);
  table_1[0] = (stage_v_204_1 + pub_r001889_14_1) & 63;
  table_2[0] = (stage_v_204_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_204_1 & 127;
  out_sink_2 ^= stage_v_204_2 & 127;
  int stage_v_205_1 = ((pub_r001889_17_1 * 2) + 9) & 63;
  int stage_v_205_2 = ((pub_r001889_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001889_22_1 * 2) + 45) & 63;
  int stage_v_206_2 = ((pub_r001889_22_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001889_10_1 * 2) + 9) & 63;
  int stage_v_207_2 = ((pub_r001889_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001889_16_1 * 2) + 15) & 63;
  int stage_v_208_2 = ((pub_r001889_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = table_1[1] + (stage_v_201_1 & 7);
  int stage_v_209_2 = table_2[1] + (stage_v_201_2 & 7);
  table_1[1] = (stage_v_209_1 + pub_r001889_15_1) & 63;
  table_2[1] = (stage_v_209_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_209_1 & 127;
  out_sink_2 ^= stage_v_209_2 & 127;
  int stage_v_210_1 = ((pub_r001889_17_1 * 2) + 13) & 63;
  int stage_v_210_2 = ((pub_r001889_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = table_1[3] + (stage_v_55_1 & 7);
  int stage_v_211_2 = table_2[3] + (stage_v_55_2 & 7);
  table_1[3] = (stage_v_211_1 + pub_r001889_5_1) & 63;
  table_2[3] = (stage_v_211_2 + pub_r001889_5_2) & 63;
  out_sink_1 ^= stage_v_211_1 & 127;
  out_sink_2 ^= stage_v_211_2 & 127;
  int stage_v_212_1 = ((pub_r001889_19_1 * 2) + 11) & 63;
  int stage_v_212_2 = ((pub_r001889_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001889_21_1 * 2) + 17) & 63;
  int stage_v_213_2 = ((pub_r001889_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001889_12_1 * 2) + 29) & 63;
  int stage_v_214_2 = ((pub_r001889_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = table_1[3] + (stage_v_102_1 & 7);
  int stage_v_215_2 = table_2[3] + (stage_v_102_2 & 7);
  table_1[3] = (stage_v_215_1 + pub_r001889_19_1) & 63;
  table_2[3] = (stage_v_215_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_215_1 & 127;
  out_sink_2 ^= stage_v_215_2 & 127;
  int stage_v_216_1 = table_1[0] + (stage_v_3_1 & 7);
  int stage_v_216_2 = table_2[0] + (stage_v_3_2 & 7);
  table_1[0] = (stage_v_216_1 + pub_r001889_22_1) & 63;
  table_2[0] = (stage_v_216_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_216_1 & 127;
  out_sink_2 ^= stage_v_216_2 & 127;
  int stage_v_217_1 = table_1[1] + (stage_v_84_1 & 7);
  int stage_v_217_2 = table_2[1] + (stage_v_84_2 & 7);
  table_1[1] = (stage_v_217_1 + pub_r001889_0_1) & 63;
  table_2[1] = (stage_v_217_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_217_1 & 127;
  out_sink_2 ^= stage_v_217_2 & 127;
  int stage_v_218_1 = ((pub_r001889_3_1 * 2) + 9) & 63;
  int stage_v_218_2 = ((pub_r001889_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = table_1[3] + (stage_v_171_1 & 7);
  int stage_v_219_2 = table_2[3] + (stage_v_171_2 & 7);
  table_1[3] = (stage_v_219_1 + pub_r001889_6_1) & 63;
  table_2[3] = (stage_v_219_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_219_1 & 127;
  out_sink_2 ^= stage_v_219_2 & 127;
  int stage_v_220_1 = ((pub_r001889_7_1 * 2) + 30) & 63;
  int stage_v_220_2 = ((pub_r001889_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001889_9_1 * 2) + 6) & 63;
  int stage_v_221_2 = ((pub_r001889_9_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = table_1[2] + (stage_v_5_1 & 7);
  int stage_v_222_2 = table_2[2] + (stage_v_5_2 & 7);
  table_1[2] = (stage_v_222_1 + pub_r001889_4_1) & 63;
  table_2[2] = (stage_v_222_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_222_1 & 127;
  out_sink_2 ^= stage_v_222_2 & 127;
  int stage_v_223_1 = ((pub_r001889_13_1 * 2) + 44) & 63;
  int stage_v_223_2 = ((pub_r001889_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = table_1[0] + (stage_v_201_1 & 7);
  int stage_v_224_2 = table_2[0] + (stage_v_201_2 & 7);
  table_1[0] = (stage_v_224_1 + pub_r001889_20_1) & 63;
  table_2[0] = (stage_v_224_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_224_1 & 127;
  out_sink_2 ^= stage_v_224_2 & 127;
  int stage_v_225_1 = ((pub_r001889_21_1 * 2) + 8) & 63;
  int stage_v_225_2 = ((pub_r001889_21_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001889_7_1 * 2) + 36) & 63;
  int stage_v_226_2 = ((pub_r001889_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = table_1[3] + (helper_flow_3_1 & 7);
  int stage_v_227_2 = table_2[3] + (helper_flow_3_2 & 7);
  table_1[3] = (stage_v_227_1 + pub_r001889_0_1) & 63;
  table_2[3] = (stage_v_227_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_227_1 & 127;
  out_sink_2 ^= stage_v_227_2 & 127;
  int stage_v_228_1 = table_1[0] + (sec_r001889_1_1 & 7);
  int stage_v_228_2 = table_2[0] + (sec_r001889_1_2 & 7);
  table_1[0] = (stage_v_228_1 + pub_r001889_13_1) & 63;
  table_2[0] = (stage_v_228_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_228_1 & 127;
  out_sink_2 ^= stage_v_228_2 & 127;
  int stage_v_229_1 = ((pub_r001889_6_1 * 2) + 20) & 63;
  int stage_v_229_2 = ((pub_r001889_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001889_2_1 * 2) + 7) & 63;
  int stage_v_230_2 = ((pub_r001889_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001889_2_1 * 2) + 37) & 63;
  int stage_v_231_2 = ((pub_r001889_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001889_10_1 * 2) + 45) & 63;
  int stage_v_232_2 = ((pub_r001889_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001889_0_1 * 2) + 15) & 63;
  int stage_v_233_2 = ((pub_r001889_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001889_5_1 * 2) + 41) & 63;
  int stage_v_234_2 = ((pub_r001889_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001889_11_1 * 2) + 36) & 63;
  int stage_v_235_2 = ((pub_r001889_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = table_1[0] + (stage_v_53_1 & 7);
  int stage_v_236_2 = table_2[0] + (stage_v_53_2 & 7);
  table_1[0] = (stage_v_236_1 + pub_r001889_21_1) & 63;
  table_2[0] = (stage_v_236_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_236_1 & 127;
  out_sink_2 ^= stage_v_236_2 & 127;
  int stage_v_237_1 = ((pub_r001889_1_1 * 2) + 34) & 63;
  int stage_v_237_2 = ((pub_r001889_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = table_1[2] + (stage_v_100_1 & 7);
  int stage_v_238_2 = table_2[2] + (stage_v_100_2 & 7);
  table_1[2] = (stage_v_238_1 + pub_r001889_14_1) & 63;
  table_2[2] = (stage_v_238_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_238_1 & 127;
  out_sink_2 ^= stage_v_238_2 & 127;
  int stage_v_239_1 = ((pub_r001889_10_1 * 2) + 19) & 63;
  int stage_v_239_2 = ((pub_r001889_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = table_1[0] + (sec_r001889_5_1 & 7);
  int stage_v_240_2 = table_2[0] + (sec_r001889_5_2 & 7);
  table_1[0] = (stage_v_240_1 + pub_r001889_18_1) & 63;
  table_2[0] = (stage_v_240_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_240_1 & 127;
  out_sink_2 ^= stage_v_240_2 & 127;
  int stage_v_241_1 = ((pub_r001889_11_1 * 2) + 7) & 63;
  int stage_v_241_2 = ((pub_r001889_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001889_11_1 * 2) + 45) & 63;
  int stage_v_242_2 = ((pub_r001889_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = table_1[3] + (stage_v_68_1 & 7);
  int stage_v_243_2 = table_2[3] + (stage_v_68_2 & 7);
  table_1[3] = (stage_v_243_1 + pub_r001889_21_1) & 63;
  table_2[3] = (stage_v_243_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_243_1 & 127;
  out_sink_2 ^= stage_v_243_2 & 127;
  int stage_v_244_1 = ((pub_r001889_21_1 * 2) + 32) & 63;
  int stage_v_244_2 = ((pub_r001889_21_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001889_18_1 * 2) + 39) & 63;
  int stage_v_245_2 = ((pub_r001889_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001889_8_1 * 2) + 24) & 63;
  int stage_v_246_2 = ((pub_r001889_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001889_11_1 * 2) + 23) & 63;
  int stage_v_247_2 = ((pub_r001889_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001889_21_1 * 2) + 24) & 63;
  int stage_v_248_2 = ((pub_r001889_21_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = table_1[1] + (stage_v_155_1 & 7);
  int stage_v_249_2 = table_2[1] + (stage_v_155_2 & 7);
  table_1[1] = (stage_v_249_1 + pub_r001889_7_1) & 63;
  table_2[1] = (stage_v_249_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_249_1 & 127;
  out_sink_2 ^= stage_v_249_2 & 127;
  int stage_v_250_1 = ((pub_r001889_14_1 * 2) + 19) & 63;
  int stage_v_250_2 = ((pub_r001889_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = table_1[3] + (stage_v_51_1 & 7);
  int stage_v_251_2 = table_2[3] + (stage_v_51_2 & 7);
  table_1[3] = (stage_v_251_1 + pub_r001889_5_1) & 63;
  table_2[3] = (stage_v_251_2 + pub_r001889_5_2) & 63;
  out_sink_1 ^= stage_v_251_1 & 127;
  out_sink_2 ^= stage_v_251_2 & 127;
  int stage_v_252_1 = table_1[0] + (stage_v_147_1 & 7);
  int stage_v_252_2 = table_2[0] + (stage_v_147_2 & 7);
  table_1[0] = (stage_v_252_1 + pub_r001889_8_1) & 63;
  table_2[0] = (stage_v_252_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_252_1 & 127;
  out_sink_2 ^= stage_v_252_2 & 127;
  int stage_v_253_1 = ((pub_r001889_12_1 * 2) + 8) & 63;
  int stage_v_253_2 = ((pub_r001889_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001889_20_1 * 2) + 28) & 63;
  int stage_v_254_2 = ((pub_r001889_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = table_1[3] + (stage_v_68_1 & 7);
  int stage_v_255_2 = table_2[3] + (stage_v_68_2 & 7);
  table_1[3] = (stage_v_255_1 + pub_r001889_18_1) & 63;
  table_2[3] = (stage_v_255_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_255_1 & 127;
  out_sink_2 ^= stage_v_255_2 & 127;
  int stage_v_256_1 = ((pub_r001889_12_1 * 2) + 37) & 63;
  int stage_v_256_2 = ((pub_r001889_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001889_14_1 * 2) + 21) & 63;
  int stage_v_257_2 = ((pub_r001889_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001889_13_1 * 2) + 22) & 63;
  int stage_v_258_2 = ((pub_r001889_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001889_19_1 * 2) + 49) & 63;
  int stage_v_259_2 = ((pub_r001889_19_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = table_1[0] + (stage_v_27_1 & 7);
  int stage_v_260_2 = table_2[0] + (stage_v_27_2 & 7);
  table_1[0] = (stage_v_260_1 + pub_r001889_4_1) & 63;
  table_2[0] = (stage_v_260_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_260_1 & 127;
  out_sink_2 ^= stage_v_260_2 & 127;
  int stage_v_261_1 = table_1[1] + (helper_flow_3_1 & 7);
  int stage_v_261_2 = table_2[1] + (helper_flow_3_2 & 7);
  table_1[1] = (stage_v_261_1 + pub_r001889_2_1) & 63;
  table_2[1] = (stage_v_261_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_261_1 & 127;
  out_sink_2 ^= stage_v_261_2 & 127;
  int stage_v_262_1 = ((pub_r001889_6_1 * 2) + 34) & 63;
  int stage_v_262_2 = ((pub_r001889_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = table_1[3] + (stage_v_7_1 & 7);
  int stage_v_263_2 = table_2[3] + (stage_v_7_2 & 7);
  table_1[3] = (stage_v_263_1 + pub_r001889_19_1) & 63;
  table_2[3] = (stage_v_263_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_263_1 & 127;
  out_sink_2 ^= stage_v_263_2 & 127;
  int stage_v_264_1 = ((pub_r001889_6_1 * 2) + 25) & 63;
  int stage_v_264_2 = ((pub_r001889_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = table_1[1] + (stage_v_255_1 & 7);
  int stage_v_265_2 = table_2[1] + (stage_v_255_2 & 7);
  table_1[1] = (stage_v_265_1 + pub_r001889_7_1) & 63;
  table_2[1] = (stage_v_265_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_265_1 & 127;
  out_sink_2 ^= stage_v_265_2 & 127;
  int stage_v_266_1 = table_1[2] + (sec_r001889_1_1 & 7);
  int stage_v_266_2 = table_2[2] + (sec_r001889_1_2 & 7);
  table_1[2] = (stage_v_266_1 + pub_r001889_14_1) & 63;
  table_2[2] = (stage_v_266_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_266_1 & 127;
  out_sink_2 ^= stage_v_266_2 & 127;
  int stage_v_267_1 = table_1[3] + (stage_v_161_1 & 7);
  int stage_v_267_2 = table_2[3] + (stage_v_161_2 & 7);
  table_1[3] = (stage_v_267_1 + pub_r001889_1_1) & 63;
  table_2[3] = (stage_v_267_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_267_1 & 127;
  out_sink_2 ^= stage_v_267_2 & 127;
  int stage_v_268_1 = ((pub_r001889_5_1 * 2) + 39) & 63;
  int stage_v_268_2 = ((pub_r001889_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = table_1[1] + (stage_v_219_1 & 7);
  int stage_v_269_2 = table_2[1] + (stage_v_219_2 & 7);
  table_1[1] = (stage_v_269_1 + pub_r001889_1_1) & 63;
  table_2[1] = (stage_v_269_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_269_1 & 127;
  out_sink_2 ^= stage_v_269_2 & 127;
  int stage_v_270_1 = ((pub_r001889_12_1 * 2) + 6) & 63;
  int stage_v_270_2 = ((pub_r001889_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001889_14_1 * 2) + 7) & 63;
  int stage_v_271_2 = ((pub_r001889_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001889_15_1 * 2) + 36) & 63;
  int stage_v_272_2 = ((pub_r001889_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001889_7_1 * 2) + 39) & 63;
  int stage_v_273_2 = ((pub_r001889_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001889_12_1 * 2) + 43) & 63;
  int stage_v_274_2 = ((pub_r001889_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = table_1[3] + (stage_v_79_1 & 7);
  int stage_v_275_2 = table_2[3] + (stage_v_79_2 & 7);
  table_1[3] = (stage_v_275_1 + pub_r001889_4_1) & 63;
  table_2[3] = (stage_v_275_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_275_1 & 127;
  out_sink_2 ^= stage_v_275_2 & 127;
  int stage_v_276_1 = table_1[0] + (stage_v_252_1 & 7);
  int stage_v_276_2 = table_2[0] + (stage_v_252_2 & 7);
  table_1[0] = (stage_v_276_1 + pub_r001889_2_1) & 63;
  table_2[0] = (stage_v_276_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_276_1 & 127;
  out_sink_2 ^= stage_v_276_2 & 127;
  int stage_v_277_1 = table_1[1] + (stage_v_67_1 & 7);
  int stage_v_277_2 = table_2[1] + (stage_v_67_2 & 7);
  table_1[1] = (stage_v_277_1 + pub_r001889_20_1) & 63;
  table_2[1] = (stage_v_277_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_277_1 & 127;
  out_sink_2 ^= stage_v_277_2 & 127;
  int stage_v_278_1 = ((pub_r001889_22_1 * 2) + 23) & 63;
  int stage_v_278_2 = ((pub_r001889_22_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001889_20_1 * 2) + 18) & 63;
  int stage_v_279_2 = ((pub_r001889_20_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = table_1[0] + (stage_v_135_1 & 7);
  int stage_v_280_2 = table_2[0] + (stage_v_135_2 & 7);
  table_1[0] = (stage_v_280_1 + pub_r001889_5_1) & 63;
  table_2[0] = (stage_v_280_2 + pub_r001889_5_2) & 63;
  out_sink_1 ^= stage_v_280_1 & 127;
  out_sink_2 ^= stage_v_280_2 & 127;
  int stage_v_281_1 = table_1[1] + (sec_r001889_18_1 & 7);
  int stage_v_281_2 = table_2[1] + (sec_r001889_18_2 & 7);
  table_1[1] = (stage_v_281_1 + pub_r001889_19_1) & 63;
  table_2[1] = (stage_v_281_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_281_1 & 127;
  out_sink_2 ^= stage_v_281_2 & 127;
  int stage_v_282_1 = table_1[2] + (stage_v_37_1 & 7);
  int stage_v_282_2 = table_2[2] + (stage_v_37_2 & 7);
  table_1[2] = (stage_v_282_1 + pub_r001889_13_1) & 63;
  table_2[2] = (stage_v_282_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_282_1 & 127;
  out_sink_2 ^= stage_v_282_2 & 127;
  int stage_v_283_1 = ((pub_r001889_8_1 * 2) + 47) & 63;
  int stage_v_283_2 = ((pub_r001889_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001889_6_1 * 2) + 46) & 63;
  int stage_v_284_2 = ((pub_r001889_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001889_22_1 * 2) + 11) & 63;
  int stage_v_285_2 = ((pub_r001889_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001889_21_1 * 2) + 21) & 63;
  int stage_v_286_2 = ((pub_r001889_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001889_11_1 * 2) + 30) & 63;
  int stage_v_287_2 = ((pub_r001889_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = table_1[0] + (stage_v_197_1 & 7);
  int stage_v_288_2 = table_2[0] + (stage_v_197_2 & 7);
  table_1[0] = (stage_v_288_1 + pub_r001889_13_1) & 63;
  table_2[0] = (stage_v_288_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_288_1 & 127;
  out_sink_2 ^= stage_v_288_2 & 127;
  int stage_v_289_1 = ((pub_r001889_16_1 * 2) + 50) & 63;
  int stage_v_289_2 = ((pub_r001889_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001889_0_1 * 2) + 7) & 63;
  int stage_v_290_2 = ((pub_r001889_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = table_1[3] + (helper_flow_0_1 & 7);
  int stage_v_291_2 = table_2[3] + (helper_flow_0_2 & 7);
  table_1[3] = (stage_v_291_1 + pub_r001889_8_1) & 63;
  table_2[3] = (stage_v_291_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_291_1 & 127;
  out_sink_2 ^= stage_v_291_2 & 127;
  int stage_v_292_1 = ((pub_r001889_4_1 * 2) + 29) & 63;
  int stage_v_292_2 = ((pub_r001889_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = table_1[1] + (sec_r001889_11_1 & 7);
  int stage_v_293_2 = table_2[1] + (sec_r001889_11_2 & 7);
  table_1[1] = (stage_v_293_1 + pub_r001889_21_1) & 63;
  table_2[1] = (stage_v_293_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_293_1 & 127;
  out_sink_2 ^= stage_v_293_2 & 127;
  int stage_v_294_1 = ((pub_r001889_1_1 * 2) + 14) & 63;
  int stage_v_294_2 = ((pub_r001889_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001889_3_1 * 2) + 6) & 63;
  int stage_v_295_2 = ((pub_r001889_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = table_1[0] + (stage_v_26_1 & 7);
  int stage_v_296_2 = table_2[0] + (stage_v_26_2 & 7);
  table_1[0] = (stage_v_296_1 + pub_r001889_6_1) & 63;
  table_2[0] = (stage_v_296_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_296_1 & 127;
  out_sink_2 ^= stage_v_296_2 & 127;
  int stage_v_297_1 = ((pub_r001889_19_1 * 2) + 35) & 63;
  int stage_v_297_2 = ((pub_r001889_19_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001889_8_1 * 2) + 20) & 63;
  int stage_v_298_2 = ((pub_r001889_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001889_21_1 * 2) + 28) & 63;
  int stage_v_299_2 = ((pub_r001889_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001889_0_1 * 2) + 29) & 63;
  int stage_v_300_2 = ((pub_r001889_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001889_14_1 * 2) + 50) & 63;
  int stage_v_301_2 = ((pub_r001889_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001889_12_1 * 2) + 42) & 63;
  int stage_v_302_2 = ((pub_r001889_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001889_21_1 * 2) + 17) & 63;
  int stage_v_303_2 = ((pub_r001889_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001889_1_1 * 2) + 19) & 63;
  int stage_v_304_2 = ((pub_r001889_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = table_1[1] + (stage_v_45_1 & 7);
  int stage_v_305_2 = table_2[1] + (stage_v_45_2 & 7);
  table_1[1] = (stage_v_305_1 + pub_r001889_18_1) & 63;
  table_2[1] = (stage_v_305_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_305_1 & 127;
  out_sink_2 ^= stage_v_305_2 & 127;
  int stage_v_306_1 = ((pub_r001889_3_1 * 2) + 32) & 63;
  int stage_v_306_2 = ((pub_r001889_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001889_0_1 * 2) + 25) & 63;
  int stage_v_307_2 = ((pub_r001889_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001889_14_1 * 2) + 11) & 63;
  int stage_v_308_2 = ((pub_r001889_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001889_8_1 * 2) + 12) & 63;
  int stage_v_309_2 = ((pub_r001889_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001889_4_1 * 2) + 49) & 63;
  int stage_v_310_2 = ((pub_r001889_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = table_1[3] + (stage_v_3_1 & 7);
  int stage_v_311_2 = table_2[3] + (stage_v_3_2 & 7);
  table_1[3] = (stage_v_311_1 + pub_r001889_21_1) & 63;
  table_2[3] = (stage_v_311_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_311_1 & 127;
  out_sink_2 ^= stage_v_311_2 & 127;
  int stage_v_312_1 = table_1[0] + (stage_v_180_1 & 7);
  int stage_v_312_2 = table_2[0] + (stage_v_180_2 & 7);
  table_1[0] = (stage_v_312_1 + pub_r001889_12_1) & 63;
  table_2[0] = (stage_v_312_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_312_1 & 127;
  out_sink_2 ^= stage_v_312_2 & 127;
  int stage_v_313_1 = ((pub_r001889_8_1 * 2) + 47) & 63;
  int stage_v_313_2 = ((pub_r001889_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = table_1[2] + (stage_v_125_1 & 7);
  int stage_v_314_2 = table_2[2] + (stage_v_125_2 & 7);
  table_1[2] = (stage_v_314_1 + pub_r001889_3_1) & 63;
  table_2[2] = (stage_v_314_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_314_1 & 127;
  out_sink_2 ^= stage_v_314_2 & 127;
  int stage_v_315_1 = ((pub_r001889_16_1 * 2) + 48) & 63;
  int stage_v_315_2 = ((pub_r001889_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001889_7_1 * 2) + 16) & 63;
  int stage_v_316_2 = ((pub_r001889_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = table_1[1] + (sec_r001889_15_1 & 7);
  int stage_v_317_2 = table_2[1] + (sec_r001889_15_2 & 7);
  table_1[1] = (stage_v_317_1 + pub_r001889_2_1) & 63;
  table_2[1] = (stage_v_317_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_317_1 & 127;
  out_sink_2 ^= stage_v_317_2 & 127;
  int stage_v_318_1 = ((pub_r001889_17_1 * 2) + 38) & 63;
  int stage_v_318_2 = ((pub_r001889_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = table_1[3] + (stage_v_119_1 & 7);
  int stage_v_319_2 = table_2[3] + (stage_v_119_2 & 7);
  table_1[3] = (stage_v_319_1 + pub_r001889_18_1) & 63;
  table_2[3] = (stage_v_319_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_319_1 & 127;
  out_sink_2 ^= stage_v_319_2 & 127;
  int stage_v_320_1 = ((pub_r001889_14_1 * 2) + 43) & 63;
  int stage_v_320_2 = ((pub_r001889_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = table_1[1] + (stage_v_147_1 & 7);
  int stage_v_321_2 = table_2[1] + (stage_v_147_2 & 7);
  table_1[1] = (stage_v_321_1 + pub_r001889_13_1) & 63;
  table_2[1] = (stage_v_321_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_321_1 & 127;
  out_sink_2 ^= stage_v_321_2 & 127;
  int stage_v_322_1 = ((pub_r001889_0_1 * 2) + 11) & 63;
  int stage_v_322_2 = ((pub_r001889_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001889_0_1 * 2) + 8) & 63;
  int stage_v_323_2 = ((pub_r001889_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = table_1[0] + (stage_v_282_1 & 7);
  int stage_v_324_2 = table_2[0] + (stage_v_282_2 & 7);
  table_1[0] = (stage_v_324_1 + pub_r001889_6_1) & 63;
  table_2[0] = (stage_v_324_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_324_1 & 127;
  out_sink_2 ^= stage_v_324_2 & 127;
  int stage_v_325_1 = table_1[1] + (stage_v_92_1 & 7);
  int stage_v_325_2 = table_2[1] + (stage_v_92_2 & 7);
  table_1[1] = (stage_v_325_1 + pub_r001889_17_1) & 63;
  table_2[1] = (stage_v_325_2 + pub_r001889_17_2) & 63;
  out_sink_1 ^= stage_v_325_1 & 127;
  out_sink_2 ^= stage_v_325_2 & 127;
  int stage_v_326_1 = ((pub_r001889_20_1 * 2) + 29) & 63;
  int stage_v_326_2 = ((pub_r001889_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001889_11_1 * 2) + 14) & 63;
  int stage_v_327_2 = ((pub_r001889_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = table_1[0] + (sec_r001889_12_1 & 7);
  int stage_v_328_2 = table_2[0] + (sec_r001889_12_2 & 7);
  table_1[0] = (stage_v_328_1 + pub_r001889_3_1) & 63;
  table_2[0] = (stage_v_328_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_328_1 & 127;
  out_sink_2 ^= stage_v_328_2 & 127;
  int stage_v_329_1 = ((pub_r001889_14_1 * 2) + 48) & 63;
  int stage_v_329_2 = ((pub_r001889_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001889_4_1 * 2) + 50) & 63;
  int stage_v_330_2 = ((pub_r001889_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001889_12_1 * 2) + 16) & 63;
  int stage_v_331_2 = ((pub_r001889_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001889_3_1 * 2) + 17) & 63;
  int stage_v_332_2 = ((pub_r001889_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = table_1[1] + (stage_v_240_1 & 7);
  int stage_v_333_2 = table_2[1] + (stage_v_240_2 & 7);
  table_1[1] = (stage_v_333_1 + pub_r001889_12_1) & 63;
  table_2[1] = (stage_v_333_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_333_1 & 127;
  out_sink_2 ^= stage_v_333_2 & 127;
  int stage_v_334_1 = ((pub_r001889_2_1 * 2) + 46) & 63;
  int stage_v_334_2 = ((pub_r001889_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = table_1[3] + (stage_v_12_1 & 7);
  int stage_v_335_2 = table_2[3] + (stage_v_12_2 & 7);
  table_1[3] = (stage_v_335_1 + pub_r001889_3_1) & 63;
  table_2[3] = (stage_v_335_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_335_1 & 127;
  out_sink_2 ^= stage_v_335_2 & 127;
  int stage_v_336_1 = ((pub_r001889_10_1 * 2) + 31) & 63;
  int stage_v_336_2 = ((pub_r001889_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001889_4_1 * 2) + 37) & 63;
  int stage_v_337_2 = ((pub_r001889_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001889_1_1 * 2) + 27) & 63;
  int stage_v_338_2 = ((pub_r001889_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = table_1[3] + (stage_v_311_1 & 7);
  int stage_v_339_2 = table_2[3] + (stage_v_311_2 & 7);
  table_1[3] = (stage_v_339_1 + pub_r001889_22_1) & 63;
  table_2[3] = (stage_v_339_2 + pub_r001889_22_2) & 63;
  out_sink_1 ^= stage_v_339_1 & 127;
  out_sink_2 ^= stage_v_339_2 & 127;
  int stage_v_340_1 = ((pub_r001889_17_1 * 2) + 47) & 63;
  int stage_v_340_2 = ((pub_r001889_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001889_21_1 * 2) + 40) & 63;
  int stage_v_341_2 = ((pub_r001889_21_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001889_14_1 * 2) + 19) & 63;
  int stage_v_342_2 = ((pub_r001889_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001889_9_1 * 2) + 34) & 63;
  int stage_v_343_2 = ((pub_r001889_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001889_1_1 * 2) + 30) & 63;
  int stage_v_344_2 = ((pub_r001889_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((pub_r001889_13_1 * 2) + 26) & 63;
  int stage_v_345_2 = ((pub_r001889_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = table_1[2] + (stage_v_26_1 & 7);
  int stage_v_346_2 = table_2[2] + (stage_v_26_2 & 7);
  table_1[2] = (stage_v_346_1 + pub_r001889_18_1) & 63;
  table_2[2] = (stage_v_346_2 + pub_r001889_18_2) & 63;
  out_sink_1 ^= stage_v_346_1 & 127;
  out_sink_2 ^= stage_v_346_2 & 127;
  int stage_v_347_1 = ((pub_r001889_17_1 * 2) + 40) & 63;
  int stage_v_347_2 = ((pub_r001889_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001889_10_1 * 2) + 24) & 63;
  int stage_v_348_2 = ((pub_r001889_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001889_4_1 * 2) + 30) & 63;
  int stage_v_349_2 = ((pub_r001889_4_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = ((pub_r001889_16_1 * 2) + 45) & 63;
  int stage_v_350_2 = ((pub_r001889_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_350_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_350_2) & 127;
  int stage_v_351_1 = ((pub_r001889_13_1 * 2) + 39) & 63;
  int stage_v_351_2 = ((pub_r001889_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = table_1[0] + (stage_v_7_1 & 7);
  int stage_v_352_2 = table_2[0] + (stage_v_7_2 & 7);
  table_1[0] = (stage_v_352_1 + pub_r001889_15_1) & 63;
  table_2[0] = (stage_v_352_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_352_1 & 127;
  out_sink_2 ^= stage_v_352_2 & 127;
  int stage_v_353_1 = ((pub_r001889_15_1 * 2) + 29) & 63;
  int stage_v_353_2 = ((pub_r001889_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001889_15_1 * 2) + 11) & 63;
  int stage_v_354_2 = ((pub_r001889_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001889_7_1 * 2) + 32) & 63;
  int stage_v_355_2 = ((pub_r001889_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001889_10_1 * 2) + 49) & 63;
  int stage_v_356_2 = ((pub_r001889_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = table_1[1] + (helper_flow_4_1 & 7);
  int stage_v_357_2 = table_2[1] + (helper_flow_4_2 & 7);
  table_1[1] = (stage_v_357_1 + pub_r001889_3_1) & 63;
  table_2[1] = (stage_v_357_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_357_1 & 127;
  out_sink_2 ^= stage_v_357_2 & 127;
  int stage_v_358_1 = ((pub_r001889_17_1 * 2) + 28) & 63;
  int stage_v_358_2 = ((pub_r001889_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001889_3_1 * 2) + 8) & 63;
  int stage_v_359_2 = ((pub_r001889_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001889_14_1 * 2) + 18) & 63;
  int stage_v_360_2 = ((pub_r001889_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = table_1[1] + (stage_v_255_1 & 7);
  int stage_v_361_2 = table_2[1] + (stage_v_255_2 & 7);
  table_1[1] = (stage_v_361_1 + pub_r001889_11_1) & 63;
  table_2[1] = (stage_v_361_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_361_1 & 127;
  out_sink_2 ^= stage_v_361_2 & 127;
  int stage_v_362_1 = table_1[2] + (stage_v_53_1 & 7);
  int stage_v_362_2 = table_2[2] + (stage_v_53_2 & 7);
  table_1[2] = (stage_v_362_1 + pub_r001889_2_1) & 63;
  table_2[2] = (stage_v_362_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_362_1 & 127;
  out_sink_2 ^= stage_v_362_2 & 127;
  int stage_v_363_1 = table_1[3] + (stage_v_155_1 & 7);
  int stage_v_363_2 = table_2[3] + (stage_v_155_2 & 7);
  table_1[3] = (stage_v_363_1 + pub_r001889_3_1) & 63;
  table_2[3] = (stage_v_363_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_363_1 & 127;
  out_sink_2 ^= stage_v_363_2 & 127;
  int stage_v_364_1 = table_1[0] + (sec_r001889_13_1 & 7);
  int stage_v_364_2 = table_2[0] + (sec_r001889_13_2 & 7);
  table_1[0] = (stage_v_364_1 + pub_r001889_0_1) & 63;
  table_2[0] = (stage_v_364_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_364_1 & 127;
  out_sink_2 ^= stage_v_364_2 & 127;
  int stage_v_365_1 = ((pub_r001889_5_1 * 2) + 32) & 63;
  int stage_v_365_2 = ((pub_r001889_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001889_11_1 * 2) + 41) & 63;
  int stage_v_366_2 = ((pub_r001889_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = table_1[3] + (stage_v_25_1 & 7);
  int stage_v_367_2 = table_2[3] + (stage_v_25_2 & 7);
  table_1[3] = (stage_v_367_1 + pub_r001889_13_1) & 63;
  table_2[3] = (stage_v_367_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_367_1 & 127;
  out_sink_2 ^= stage_v_367_2 & 127;
  int stage_v_368_1 = table_1[0] + (stage_v_269_1 & 7);
  int stage_v_368_2 = table_2[0] + (stage_v_269_2 & 7);
  table_1[0] = (stage_v_368_1 + pub_r001889_19_1) & 63;
  table_2[0] = (stage_v_368_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_368_1 & 127;
  out_sink_2 ^= stage_v_368_2 & 127;
  int stage_v_369_1 = table_1[1] + (helper_flow_2_1 & 7);
  int stage_v_369_2 = table_2[1] + (helper_flow_2_2 & 7);
  table_1[1] = (stage_v_369_1 + pub_r001889_3_1) & 63;
  table_2[1] = (stage_v_369_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_369_1 & 127;
  out_sink_2 ^= stage_v_369_2 & 127;
  int stage_v_370_1 = ((pub_r001889_3_1 * 2) + 42) & 63;
  int stage_v_370_2 = ((pub_r001889_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001889_19_1 * 2) + 29) & 63;
  int stage_v_371_2 = ((pub_r001889_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001889_15_1 * 2) + 45) & 63;
  int stage_v_372_2 = ((pub_r001889_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001889_22_1 * 2) + 13) & 63;
  int stage_v_373_2 = ((pub_r001889_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001889_21_1 * 2) + 29) & 63;
  int stage_v_374_2 = ((pub_r001889_21_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = table_1[3] + (stage_v_228_1 & 7);
  int stage_v_375_2 = table_2[3] + (stage_v_228_2 & 7);
  table_1[3] = (stage_v_375_1 + pub_r001889_16_1) & 63;
  table_2[3] = (stage_v_375_2 + pub_r001889_16_2) & 63;
  out_sink_1 ^= stage_v_375_1 & 127;
  out_sink_2 ^= stage_v_375_2 & 127;
  int stage_v_376_1 = ((pub_r001889_6_1 * 2) + 34) & 63;
  int stage_v_376_2 = ((pub_r001889_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001889_12_1 * 2) + 49) & 63;
  int stage_v_377_2 = ((pub_r001889_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001889_16_1 * 2) + 40) & 63;
  int stage_v_378_2 = ((pub_r001889_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001889_3_1 * 2) + 49) & 63;
  int stage_v_379_2 = ((pub_r001889_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001889_6_1 * 2) + 17) & 63;
  int stage_v_380_2 = ((pub_r001889_6_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001889_22_1 * 2) + 13) & 63;
  int stage_v_381_2 = ((pub_r001889_22_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = table_1[2] + (stage_v_176_1 & 7);
  int stage_v_382_2 = table_2[2] + (stage_v_176_2 & 7);
  table_1[2] = (stage_v_382_1 + pub_r001889_6_1) & 63;
  table_2[2] = (stage_v_382_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_382_1 & 127;
  out_sink_2 ^= stage_v_382_2 & 127;
  int stage_v_383_1 = table_1[3] + (stage_v_224_1 & 7);
  int stage_v_383_2 = table_2[3] + (stage_v_224_2 & 7);
  table_1[3] = (stage_v_383_1 + pub_r001889_0_1) & 63;
  table_2[3] = (stage_v_383_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_383_1 & 127;
  out_sink_2 ^= stage_v_383_2 & 127;
  int stage_v_384_1 = table_1[0] + (stage_v_227_1 & 7);
  int stage_v_384_2 = table_2[0] + (stage_v_227_2 & 7);
  table_1[0] = (stage_v_384_1 + pub_r001889_14_1) & 63;
  table_2[0] = (stage_v_384_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_384_1 & 127;
  out_sink_2 ^= stage_v_384_2 & 127;
  int stage_v_385_1 = ((pub_r001889_16_1 * 2) + 16) & 63;
  int stage_v_385_2 = ((pub_r001889_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = table_1[2] + (stage_v_78_1 & 7);
  int stage_v_386_2 = table_2[2] + (stage_v_78_2 & 7);
  table_1[2] = (stage_v_386_1 + pub_r001889_2_1) & 63;
  table_2[2] = (stage_v_386_2 + pub_r001889_2_2) & 63;
  out_sink_1 ^= stage_v_386_1 & 127;
  out_sink_2 ^= stage_v_386_2 & 127;
  int stage_v_387_1 = ((pub_r001889_22_1 * 2) + 23) & 63;
  int stage_v_387_2 = ((pub_r001889_22_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001889_10_1 * 2) + 12) & 63;
  int stage_v_388_2 = ((pub_r001889_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = table_1[1] + (stage_v_224_1 & 7);
  int stage_v_389_2 = table_2[1] + (stage_v_224_2 & 7);
  table_1[1] = (stage_v_389_1 + pub_r001889_21_1) & 63;
  table_2[1] = (stage_v_389_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_389_1 & 127;
  out_sink_2 ^= stage_v_389_2 & 127;
  int stage_v_390_1 = table_1[2] + (stage_v_228_1 & 7);
  int stage_v_390_2 = table_2[2] + (stage_v_228_2 & 7);
  table_1[2] = (stage_v_390_1 + pub_r001889_8_1) & 63;
  table_2[2] = (stage_v_390_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_390_1 & 127;
  out_sink_2 ^= stage_v_390_2 & 127;
  int stage_v_391_1 = ((pub_r001889_6_1 * 2) + 24) & 63;
  int stage_v_391_2 = ((pub_r001889_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001889_20_1 * 2) + 32) & 63;
  int stage_v_392_2 = ((pub_r001889_20_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((pub_r001889_16_1 * 2) + 35) & 63;
  int stage_v_393_2 = ((pub_r001889_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = table_1[2] + (stage_v_211_1 & 7);
  int stage_v_394_2 = table_2[2] + (stage_v_211_2 & 7);
  table_1[2] = (stage_v_394_1 + pub_r001889_8_1) & 63;
  table_2[2] = (stage_v_394_2 + pub_r001889_8_2) & 63;
  out_sink_1 ^= stage_v_394_1 & 127;
  out_sink_2 ^= stage_v_394_2 & 127;
  int stage_v_395_1 = ((pub_r001889_0_1 * 2) + 5) & 63;
  int stage_v_395_2 = ((pub_r001889_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001889_17_1 * 2) + 26) & 63;
  int stage_v_396_2 = ((pub_r001889_17_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001889_9_1 * 2) + 36) & 63;
  int stage_v_397_2 = ((pub_r001889_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001889_14_1 * 2) + 27) & 63;
  int stage_v_398_2 = ((pub_r001889_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001889_17_1 * 2) + 34) & 63;
  int stage_v_399_2 = ((pub_r001889_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = table_1[0] + (stage_v_30_1 & 7);
  int stage_v_400_2 = table_2[0] + (stage_v_30_2 & 7);
  table_1[0] = (stage_v_400_1 + pub_r001889_12_1) & 63;
  table_2[0] = (stage_v_400_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_400_1 & 127;
  out_sink_2 ^= stage_v_400_2 & 127;
  int stage_v_401_1 = ((pub_r001889_9_1 * 2) + 33) & 63;
  int stage_v_401_2 = ((pub_r001889_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = table_1[2] + (stage_v_104_1 & 7);
  int stage_v_402_2 = table_2[2] + (stage_v_104_2 & 7);
  table_1[2] = (stage_v_402_1 + pub_r001889_12_1) & 63;
  table_2[2] = (stage_v_402_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_402_1 & 127;
  out_sink_2 ^= stage_v_402_2 & 127;
  int stage_v_403_1 = table_1[3] + (stage_v_38_1 & 7);
  int stage_v_403_2 = table_2[3] + (stage_v_38_2 & 7);
  table_1[3] = (stage_v_403_1 + pub_r001889_15_1) & 63;
  table_2[3] = (stage_v_403_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_403_1 & 127;
  out_sink_2 ^= stage_v_403_2 & 127;
  int stage_v_404_1 = table_1[0] + (stage_v_305_1 & 7);
  int stage_v_404_2 = table_2[0] + (stage_v_305_2 & 7);
  table_1[0] = (stage_v_404_1 + pub_r001889_3_1) & 63;
  table_2[0] = (stage_v_404_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_404_1 & 127;
  out_sink_2 ^= stage_v_404_2 & 127;
  int stage_v_405_1 = ((pub_r001889_6_1 * 2) + 39) & 63;
  int stage_v_405_2 = ((pub_r001889_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001889_22_1 * 2) + 11) & 63;
  int stage_v_406_2 = ((pub_r001889_22_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = table_1[3] + (stage_v_328_1 & 7);
  int stage_v_407_2 = table_2[3] + (stage_v_328_2 & 7);
  table_1[3] = (stage_v_407_1 + pub_r001889_13_1) & 63;
  table_2[3] = (stage_v_407_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_407_1 & 127;
  out_sink_2 ^= stage_v_407_2 & 127;
  int stage_v_408_1 = table_1[0] + (stage_v_277_1 & 7);
  int stage_v_408_2 = table_2[0] + (stage_v_277_2 & 7);
  table_1[0] = (stage_v_408_1 + pub_r001889_13_1) & 63;
  table_2[0] = (stage_v_408_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_408_1 & 127;
  out_sink_2 ^= stage_v_408_2 & 127;
  int stage_v_409_1 = ((pub_r001889_3_1 * 2) + 42) & 63;
  int stage_v_409_2 = ((pub_r001889_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = table_1[2] + (stage_v_163_1 & 7);
  int stage_v_410_2 = table_2[2] + (stage_v_163_2 & 7);
  table_1[2] = (stage_v_410_1 + pub_r001889_7_1) & 63;
  table_2[2] = (stage_v_410_2 + pub_r001889_7_2) & 63;
  out_sink_1 ^= stage_v_410_1 & 127;
  out_sink_2 ^= stage_v_410_2 & 127;
  int stage_v_411_1 = ((pub_r001889_14_1 * 2) + 20) & 63;
  int stage_v_411_2 = ((pub_r001889_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = table_1[0] + (stage_v_11_1 & 7);
  int stage_v_412_2 = table_2[0] + (stage_v_11_2 & 7);
  table_1[0] = (stage_v_412_1 + pub_r001889_3_1) & 63;
  table_2[0] = (stage_v_412_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_412_1 & 127;
  out_sink_2 ^= stage_v_412_2 & 127;
  int stage_v_413_1 = ((pub_r001889_12_1 * 2) + 23) & 63;
  int stage_v_413_2 = ((pub_r001889_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001889_18_1 * 2) + 38) & 63;
  int stage_v_414_2 = ((pub_r001889_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001889_2_1 * 2) + 7) & 63;
  int stage_v_415_2 = ((pub_r001889_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001889_15_1 * 2) + 19) & 63;
  int stage_v_416_2 = ((pub_r001889_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001889_5_1 * 2) + 15) & 63;
  int stage_v_417_2 = ((pub_r001889_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001889_18_1 * 2) + 13) & 63;
  int stage_v_418_2 = ((pub_r001889_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001889_20_1 * 2) + 49) & 63;
  int stage_v_419_2 = ((pub_r001889_20_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = table_1[0] + (stage_v_12_1 & 7);
  int stage_v_420_2 = table_2[0] + (stage_v_12_2 & 7);
  table_1[0] = (stage_v_420_1 + pub_r001889_15_1) & 63;
  table_2[0] = (stage_v_420_2 + pub_r001889_15_2) & 63;
  out_sink_1 ^= stage_v_420_1 & 127;
  out_sink_2 ^= stage_v_420_2 & 127;
  int stage_v_421_1 = ((pub_r001889_4_1 * 2) + 5) & 63;
  int stage_v_421_2 = ((pub_r001889_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = table_1[2] + (stage_v_35_1 & 7);
  int stage_v_422_2 = table_2[2] + (stage_v_35_2 & 7);
  table_1[2] = (stage_v_422_1 + pub_r001889_14_1) & 63;
  table_2[2] = (stage_v_422_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_422_1 & 127;
  out_sink_2 ^= stage_v_422_2 & 127;
  int stage_v_423_1 = ((pub_r001889_9_1 * 2) + 21) & 63;
  int stage_v_423_2 = ((pub_r001889_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((pub_r001889_0_1 * 2) + 15) & 63;
  int stage_v_424_2 = ((pub_r001889_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001889_8_1 * 2) + 29) & 63;
  int stage_v_425_2 = ((pub_r001889_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = table_1[2] + (stage_v_422_1 & 7);
  int stage_v_426_2 = table_2[2] + (stage_v_422_2 & 7);
  table_1[2] = (stage_v_426_1 + pub_r001889_11_1) & 63;
  table_2[2] = (stage_v_426_2 + pub_r001889_11_2) & 63;
  out_sink_1 ^= stage_v_426_1 & 127;
  out_sink_2 ^= stage_v_426_2 & 127;
  int stage_v_427_1 = ((pub_r001889_20_1 * 2) + 29) & 63;
  int stage_v_427_2 = ((pub_r001889_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001889_8_1 * 2) + 28) & 63;
  int stage_v_428_2 = ((pub_r001889_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001889_2_1 * 2) + 37) & 63;
  int stage_v_429_2 = ((pub_r001889_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001889_12_1 * 2) + 38) & 63;
  int stage_v_430_2 = ((pub_r001889_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = table_1[3] + (stage_v_26_1 & 7);
  int stage_v_431_2 = table_2[3] + (stage_v_26_2 & 7);
  table_1[3] = (stage_v_431_1 + pub_r001889_0_1) & 63;
  table_2[3] = (stage_v_431_2 + pub_r001889_0_2) & 63;
  out_sink_1 ^= stage_v_431_1 & 127;
  out_sink_2 ^= stage_v_431_2 & 127;
  int stage_v_432_1 = ((pub_r001889_13_1 * 2) + 44) & 63;
  int stage_v_432_2 = ((pub_r001889_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001889_15_1 * 2) + 19) & 63;
  int stage_v_433_2 = ((pub_r001889_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = table_1[2] + (stage_v_280_1 & 7);
  int stage_v_434_2 = table_2[2] + (stage_v_280_2 & 7);
  table_1[2] = (stage_v_434_1 + pub_r001889_6_1) & 63;
  table_2[2] = (stage_v_434_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_434_1 & 127;
  out_sink_2 ^= stage_v_434_2 & 127;
  int stage_v_435_1 = ((pub_r001889_7_1 * 2) + 41) & 63;
  int stage_v_435_2 = ((pub_r001889_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = table_1[0] + (sec_r001889_16_1 & 7);
  int stage_v_436_2 = table_2[0] + (sec_r001889_16_2 & 7);
  table_1[0] = (stage_v_436_1 + pub_r001889_12_1) & 63;
  table_2[0] = (stage_v_436_2 + pub_r001889_12_2) & 63;
  out_sink_1 ^= stage_v_436_1 & 127;
  out_sink_2 ^= stage_v_436_2 & 127;
  int stage_v_437_1 = table_1[1] + (stage_v_209_1 & 7);
  int stage_v_437_2 = table_2[1] + (stage_v_209_2 & 7);
  table_1[1] = (stage_v_437_1 + pub_r001889_1_1) & 63;
  table_2[1] = (stage_v_437_2 + pub_r001889_1_2) & 63;
  out_sink_1 ^= stage_v_437_1 & 127;
  out_sink_2 ^= stage_v_437_2 & 127;
  int stage_v_438_1 = table_1[2] + (stage_v_281_1 & 7);
  int stage_v_438_2 = table_2[2] + (stage_v_281_2 & 7);
  table_1[2] = (stage_v_438_1 + pub_r001889_3_1) & 63;
  table_2[2] = (stage_v_438_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_438_1 & 127;
  out_sink_2 ^= stage_v_438_2 & 127;
  int stage_v_439_1 = table_1[3] + (stage_v_240_1 & 7);
  int stage_v_439_2 = table_2[3] + (stage_v_240_2 & 7);
  table_1[3] = (stage_v_439_1 + pub_r001889_13_1) & 63;
  table_2[3] = (stage_v_439_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_439_1 & 127;
  out_sink_2 ^= stage_v_439_2 & 127;
  int stage_v_440_1 = ((pub_r001889_17_1 * 2) + 41) & 63;
  int stage_v_440_2 = ((pub_r001889_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001889_1_1 * 2) + 50) & 63;
  int stage_v_441_2 = ((pub_r001889_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = table_1[2] + (stage_v_100_1 & 7);
  int stage_v_442_2 = table_2[2] + (stage_v_100_2 & 7);
  table_1[2] = (stage_v_442_1 + pub_r001889_4_1) & 63;
  table_2[2] = (stage_v_442_2 + pub_r001889_4_2) & 63;
  out_sink_1 ^= stage_v_442_1 & 127;
  out_sink_2 ^= stage_v_442_2 & 127;
  int stage_v_443_1 = ((pub_r001889_21_1 * 2) + 39) & 63;
  int stage_v_443_2 = ((pub_r001889_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001889_5_1 * 2) + 17) & 63;
  int stage_v_444_2 = ((pub_r001889_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001889_8_1 * 2) + 44) & 63;
  int stage_v_445_2 = ((pub_r001889_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001889_3_1 * 2) + 26) & 63;
  int stage_v_446_2 = ((pub_r001889_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001889_9_1 * 2) + 29) & 63;
  int stage_v_447_2 = ((pub_r001889_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001889_22_1 * 2) + 9) & 63;
  int stage_v_448_2 = ((pub_r001889_22_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = table_1[1] + (stage_v_275_1 & 7);
  int stage_v_449_2 = table_2[1] + (stage_v_275_2 & 7);
  table_1[1] = (stage_v_449_1 + pub_r001889_20_1) & 63;
  table_2[1] = (stage_v_449_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_449_1 & 127;
  out_sink_2 ^= stage_v_449_2 & 127;
  int stage_v_450_1 = ((pub_r001889_22_1 * 2) + 26) & 63;
  int stage_v_450_2 = ((pub_r001889_22_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = table_1[3] + (stage_v_147_1 & 7);
  int stage_v_451_2 = table_2[3] + (stage_v_147_2 & 7);
  table_1[3] = (stage_v_451_1 + pub_r001889_14_1) & 63;
  table_2[3] = (stage_v_451_2 + pub_r001889_14_2) & 63;
  out_sink_1 ^= stage_v_451_1 & 127;
  out_sink_2 ^= stage_v_451_2 & 127;
  int stage_v_452_1 = ((pub_r001889_21_1 * 2) + 46) & 63;
  int stage_v_452_2 = ((pub_r001889_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001889_15_1 * 2) + 25) & 63;
  int stage_v_453_2 = ((pub_r001889_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = ((pub_r001889_1_1 * 2) + 32) & 63;
  int stage_v_454_2 = ((pub_r001889_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((pub_r001889_17_1 * 2) + 49) & 63;
  int stage_v_455_2 = ((pub_r001889_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = table_1[0] + (stage_v_171_1 & 7);
  int stage_v_456_2 = table_2[0] + (stage_v_171_2 & 7);
  table_1[0] = (stage_v_456_1 + pub_r001889_17_1) & 63;
  table_2[0] = (stage_v_456_2 + pub_r001889_17_2) & 63;
  out_sink_1 ^= stage_v_456_1 & 127;
  out_sink_2 ^= stage_v_456_2 & 127;
  int stage_v_457_1 = ((pub_r001889_22_1 * 2) + 6) & 63;
  int stage_v_457_2 = ((pub_r001889_22_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = table_1[2] + (stage_v_314_1 & 7);
  int stage_v_458_2 = table_2[2] + (stage_v_314_2 & 7);
  table_1[2] = (stage_v_458_1 + pub_r001889_19_1) & 63;
  table_2[2] = (stage_v_458_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_458_1 & 127;
  out_sink_2 ^= stage_v_458_2 & 127;
  int stage_v_459_1 = ((pub_r001889_20_1 * 2) + 23) & 63;
  int stage_v_459_2 = ((pub_r001889_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001889_6_1 * 2) + 13) & 63;
  int stage_v_460_2 = ((pub_r001889_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001889_19_1 * 2) + 16) & 63;
  int stage_v_461_2 = ((pub_r001889_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = table_1[2] + (stage_v_321_1 & 7);
  int stage_v_462_2 = table_2[2] + (stage_v_321_2 & 7);
  table_1[2] = (stage_v_462_1 + pub_r001889_20_1) & 63;
  table_2[2] = (stage_v_462_2 + pub_r001889_20_2) & 63;
  out_sink_1 ^= stage_v_462_1 & 127;
  out_sink_2 ^= stage_v_462_2 & 127;
  int stage_v_463_1 = ((pub_r001889_0_1 * 2) + 32) & 63;
  int stage_v_463_2 = ((pub_r001889_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = table_1[0] + (stage_v_83_1 & 7);
  int stage_v_464_2 = table_2[0] + (stage_v_83_2 & 7);
  table_1[0] = (stage_v_464_1 + pub_r001889_13_1) & 63;
  table_2[0] = (stage_v_464_2 + pub_r001889_13_2) & 63;
  out_sink_1 ^= stage_v_464_1 & 127;
  out_sink_2 ^= stage_v_464_2 & 127;
  int stage_v_465_1 = ((pub_r001889_2_1 * 2) + 21) & 63;
  int stage_v_465_2 = ((pub_r001889_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001889_1_1 * 2) + 7) & 63;
  int stage_v_466_2 = ((pub_r001889_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((pub_r001889_2_1 * 2) + 9) & 63;
  int stage_v_467_2 = ((pub_r001889_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = ((pub_r001889_1_1 * 2) + 14) & 63;
  int stage_v_468_2 = ((pub_r001889_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = table_1[1] + (stage_v_260_1 & 7);
  int stage_v_469_2 = table_2[1] + (stage_v_260_2 & 7);
  table_1[1] = (stage_v_469_1 + pub_r001889_6_1) & 63;
  table_2[1] = (stage_v_469_2 + pub_r001889_6_2) & 63;
  out_sink_1 ^= stage_v_469_1 & 127;
  out_sink_2 ^= stage_v_469_2 & 127;
  int stage_v_470_1 = ((pub_r001889_9_1 * 2) + 26) & 63;
  int stage_v_470_2 = ((pub_r001889_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = table_1[3] + (stage_v_14_1 & 7);
  int stage_v_471_2 = table_2[3] + (stage_v_14_2 & 7);
  table_1[3] = (stage_v_471_1 + pub_r001889_21_1) & 63;
  table_2[3] = (stage_v_471_2 + pub_r001889_21_2) & 63;
  out_sink_1 ^= stage_v_471_1 & 127;
  out_sink_2 ^= stage_v_471_2 & 127;
  int stage_v_472_1 = table_1[0] + (stage_v_152_1 & 7);
  int stage_v_472_2 = table_2[0] + (stage_v_152_2 & 7);
  table_1[0] = (stage_v_472_1 + pub_r001889_19_1) & 63;
  table_2[0] = (stage_v_472_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_472_1 & 127;
  out_sink_2 ^= stage_v_472_2 & 127;
  int stage_v_473_1 = table_1[1] + (stage_v_434_1 & 7);
  int stage_v_473_2 = table_2[1] + (stage_v_434_2 & 7);
  table_1[1] = (stage_v_473_1 + pub_r001889_19_1) & 63;
  table_2[1] = (stage_v_473_2 + pub_r001889_19_2) & 63;
  out_sink_1 ^= stage_v_473_1 & 127;
  out_sink_2 ^= stage_v_473_2 & 127;
  int stage_v_474_1 = table_1[2] + (stage_v_102_1 & 7);
  int stage_v_474_2 = table_2[2] + (stage_v_102_2 & 7);
  table_1[2] = (stage_v_474_1 + pub_r001889_9_1) & 63;
  table_2[2] = (stage_v_474_2 + pub_r001889_9_2) & 63;
  out_sink_1 ^= stage_v_474_1 & 127;
  out_sink_2 ^= stage_v_474_2 & 127;
  int stage_v_475_1 = ((pub_r001889_13_1 * 2) + 31) & 63;
  int stage_v_475_2 = ((pub_r001889_13_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = table_1[0] + (stage_v_12_1 & 7);
  int stage_v_476_2 = table_2[0] + (stage_v_12_2 & 7);
  table_1[0] = (stage_v_476_1 + pub_r001889_3_1) & 63;
  table_2[0] = (stage_v_476_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_476_1 & 127;
  out_sink_2 ^= stage_v_476_2 & 127;
  int stage_v_477_1 = ((pub_r001889_18_1 * 2) + 49) & 63;
  int stage_v_477_2 = ((pub_r001889_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = table_1[2] + (stage_v_155_1 & 7);
  int stage_v_478_2 = table_2[2] + (stage_v_155_2 & 7);
  table_1[2] = (stage_v_478_1 + pub_r001889_3_1) & 63;
  table_2[2] = (stage_v_478_2 + pub_r001889_3_2) & 63;
  out_sink_1 ^= stage_v_478_1 & 127;
  out_sink_2 ^= stage_v_478_2 & 127;
  int stage_v_479_1 = ((pub_r001889_14_1 * 2) + 34) & 63;
  int stage_v_479_2 = ((pub_r001889_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((pub_r001889_20_1 * 2) + 11) & 63;
  int stage_v_480_2 = ((pub_r001889_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_480_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_480_2) & 127;
  int stage_v_481_1 = ((pub_r001889_0_1 * 2) + 20) & 63;
  int stage_v_481_2 = ((pub_r001889_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001889_18_1 == pub_r001889_18_2);
  __CPROVER_assume(sec_r001889_15_1 != sec_r001889_15_2);
  __CPROVER_assume(sec_r001889_16_1 != sec_r001889_16_2);
  __CPROVER_assume(pub_r001889_19_1 == pub_r001889_19_2);
  __CPROVER_assume(pub_r001889_10_1 == pub_r001889_10_2);
  __CPROVER_assume(pub_r001889_4_1 == pub_r001889_4_2);
  __CPROVER_assume(sec_r001889_7_1 != sec_r001889_7_2);
  __CPROVER_assume(sec_r001889_10_1 != sec_r001889_10_2);
  __CPROVER_assume(pub_r001889_17_1 == pub_r001889_17_2);
  __CPROVER_assume(sec_r001889_4_1 != sec_r001889_4_2);
  __CPROVER_assume(pub_r001889_11_1 == pub_r001889_11_2);
  __CPROVER_assume(pub_r001889_15_1 == pub_r001889_15_2);
  __CPROVER_assume(pub_r001889_6_1 == pub_r001889_6_2);
  __CPROVER_assume(pub_r001889_5_1 == pub_r001889_5_2);
  __CPROVER_assume(pub_r001889_8_1 == pub_r001889_8_2);
  __CPROVER_assume(sec_r001889_11_1 != sec_r001889_11_2);
  __CPROVER_assume(pub_r001889_20_1 == pub_r001889_20_2);
  __CPROVER_assume(sec_r001889_2_1 != sec_r001889_2_2);
  __CPROVER_assume(sec_r001889_6_1 != sec_r001889_6_2);
  __CPROVER_assume(pub_r001889_3_1 == pub_r001889_3_2);
  __CPROVER_assume(pub_r001889_21_1 == pub_r001889_21_2);
  __CPROVER_assume(sec_r001889_13_1 != sec_r001889_13_2);
  __CPROVER_assume(pub_r001889_7_1 == pub_r001889_7_2);
  __CPROVER_assume(pub_r001889_16_1 == pub_r001889_16_2);
  __CPROVER_assume(pub_r001889_14_1 == pub_r001889_14_2);
  __CPROVER_assume(sec_r001889_5_1 != sec_r001889_5_2);
  __CPROVER_assume(pub_r001889_12_1 == pub_r001889_12_2);
  __CPROVER_assume(sec_r001889_14_1 != sec_r001889_14_2);
  __CPROVER_assume(sec_r001889_19_1 != sec_r001889_19_2);
  __CPROVER_assume(pub_r001889_1_1 == pub_r001889_1_2);
  __CPROVER_assume(sec_r001889_12_1 != sec_r001889_12_2);
  __CPROVER_assume(sec_r001889_0_1 != sec_r001889_0_2);
  __CPROVER_assume(pub_r001889_22_1 == pub_r001889_22_2);
  __CPROVER_assume(pub_r001889_13_1 == pub_r001889_13_2);
  __CPROVER_assume(sec_r001889_1_1 != sec_r001889_1_2);
  __CPROVER_assume(sec_r001889_3_1 != sec_r001889_3_2);
  __CPROVER_assume(sec_r001889_9_1 != sec_r001889_9_2);
  __CPROVER_assume(sec_r001889_8_1 != sec_r001889_8_2);
  __CPROVER_assume(pub_r001889_0_1 == pub_r001889_0_2);
  __CPROVER_assume(pub_r001889_2_1 == pub_r001889_2_2);
  __CPROVER_assume(sec_r001889_20_1 != sec_r001889_20_2);
  __CPROVER_assume(sec_r001889_17_1 != sec_r001889_17_2);
  __CPROVER_assume(sec_r001889_18_1 != sec_r001889_18_2);
  __CPROVER_assume(pub_r001889_9_1 == pub_r001889_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.id == st_var_3_2.id);
  assert(st_var_3_1.timeout == st_var_3_2.timeout);
  assert(st_var_3_1.stop_bits == st_var_3_2.stop_bits);
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
}


