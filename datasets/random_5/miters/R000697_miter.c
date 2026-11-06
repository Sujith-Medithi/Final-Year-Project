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
struct AudioFrame_R000697_9713_0
{
  int channels;
  int sample_rate;
  int peak;
  int envelope;
  int buffer[3];
};
struct MatrixBlock_R000697_9713_1
{
  int stride;
  int scale;
  int determinant;
  unsigned char density;
  int trace;
  int buffer[3];
};
struct EventLog_R000697_9713_2
{
  int severity;
  unsigned char code;
  int timestamp;
  unsigned char signature;
  int buffer[3];
};
struct DeviceConfig_R000697_9713_3
{
  int port;
  short parity;
  short id;
  int timeout;
  int stop_bits;
  int buffer[3];
};
union TelemetryField_R000697_9713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000697_9713_1
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
void fn_R000697_9713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int metric_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_62_1 > 24)
  {
    acc_1 = ((acc_1 + (metric_62_1 * 2)) + 5) & 127;
    aux_1 ^= metric_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_62_2 > 24)
  {
    acc_2 = ((acc_2 + (metric_62_2 * 2)) + 5) & 127;
    aux_2 ^= metric_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_77_1 = local_arr_1[aux_1 % 3];
  int quotient_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_77_2 * 2)) & 127;
  int checksum_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_66_1)
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

  switch (checksum_66_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_62_1 == metric_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_77_1 == quotient_77_2);
  assert(checksum_66_1 == checksum_66_2);
}

int fn_R000697_9713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int metric_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_62 > 24)
  {
    acc = ((acc + (metric_62 * 2)) + 5) & 127;
    aux ^= metric_62 & 15;
  }
  else
  {
    acc = ((acc - metric_62) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_77 = local_arr[aux % 3];
  acc = (acc + (quotient_77 * 2)) & 127;
  int checksum_66 = (aux + st.buffer[1]) & 3;
  switch (checksum_66)
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

void fn_R000697_9713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_96_1) & 63;
  aux_2 = (aux_2 + anchor_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_74_1 = local_arr_1[aux_1 % 3];
  int pivot_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_74_2 * 2)) & 127;
  int tracker_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_38_1)
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

  switch (tracker_38_2)
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
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_96_1 == anchor_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_74_1 == pivot_74_2);
  assert(tracker_38_1 == tracker_38_2);
}

int fn_R000697_9713_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_74 = local_arr[aux % 3];
  acc = (acc + (pivot_74 * 2)) & 127;
  int tracker_38 = (aux + st.buffer[1]) & 3;
  switch (tracker_38)
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

void fn_R000697_9713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int anchor_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_50_1)
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

  switch (anchor_50_2)
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

  int residue_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_11_1 > 34)
  {
    acc_1 = ((acc_1 + (residue_11_1 * 2)) + 5) & 127;
    aux_1 ^= residue_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_11_2 > 34)
  {
    acc_2 = ((acc_2 + (residue_11_2 * 2)) + 5) & 127;
    aux_2 ^= residue_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_38_1) & 63;
  aux_2 = (aux_2 + index_reg_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_50_1 == anchor_50_2);
  assert(residue_11_1 == residue_11_2);
  assert(index_reg_38_1 == index_reg_38_2);
}

int fn_R000697_9713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int anchor_50 = (aux + st.buffer[1]) & 3;
  switch (anchor_50)
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

  int residue_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_11 > 34)
  {
    acc = ((acc + (residue_11 * 2)) + 5) & 127;
    aux ^= residue_11 & 15;
  }
  else
  {
    acc = ((acc - residue_11) + 11) & 127;
    aux += 3;
  }
  int index_reg_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000697_9713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_40_1 = local_arr_1[aux_1 % 3];
  int segment_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_40_2 * 2)) & 127;
  int pivot_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_12_1)
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

  switch (pivot_12_2)
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

  int quantum_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_18_1) & 63;
  aux_2 = (aux_2 + quantum_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_29_1 > 11)
  {
    acc_1 = ((acc_1 + (window_29_1 * 2)) + 5) & 127;
    aux_1 ^= window_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_29_2 > 11)
  {
    acc_2 = ((acc_2 + (window_29_2 * 2)) + 5) & 127;
    aux_2 ^= window_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_40_1 == segment_40_2);
  assert(pivot_12_1 == pivot_12_2);
  assert(quantum_18_1 == quantum_18_2);
  assert(window_29_1 == window_29_2);
}

int fn_R000697_9713_3(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int local_arr[3] = {4, 9, 15};
  int segment_40 = local_arr[aux % 3];
  acc = (acc + (segment_40 * 2)) & 127;
  int pivot_12 = (aux + st.buffer[1]) & 3;
  switch (pivot_12)
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

  int quantum_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_18) & 63;
  acc ^= aux;
  int window_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_29 > 11)
  {
    acc = ((acc + (window_29 * 2)) + 5) & 127;
    aux ^= window_29 & 15;
  }
  else
  {
    acc = ((acc - window_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000697_9713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_72_1) & 63;
  aux_2 = (aux_2 + pivot_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_33_1)
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

  switch (residue_33_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_72_1 == pivot_72_2);
  assert(residue_33_1 == residue_33_2);
}

int fn_R000697_9713_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_72) & 63;
  acc ^= aux;
  int residue_33 = (aux + st.buffer[1]) & 3;
  switch (residue_33)
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

void fn_R000697_9713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st_1 = {0};
  struct DeviceConfig_R000697_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int phase_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_63_1 > 26)
  {
    acc_1 = ((acc_1 + (phase_63_1 * 2)) + 5) & 127;
    aux_1 ^= phase_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_63_2 > 26)
  {
    acc_2 = ((acc_2 + (phase_63_2 * 2)) + 5) & 127;
    aux_2 ^= phase_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_63_1)
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

  switch (vector_63_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_63_1 == phase_63_2);
  assert(vector_63_1 == vector_63_2);
}

int fn_R000697_9713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int phase_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_63 > 26)
  {
    acc = ((acc + (phase_63 * 2)) + 5) & 127;
    aux ^= phase_63 & 15;
  }
  else
  {
    acc = ((acc - phase_63) + 11) & 127;
    aux += 3;
  }
  int vector_63 = (aux + st.buffer[1]) & 3;
  switch (vector_63)
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

void fn_R000697_9713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_35_1 > 23)
  {
    acc_1 = ((acc_1 + (accumulator_35_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_35_2 > 23)
  {
    acc_2 = ((acc_2 + (accumulator_35_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_65_1 = local_arr_1[aux_1 % 3];
  int mask_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_65_2 * 2)) & 127;
  int factor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_33_1)
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

  switch (factor_33_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_35_1 == accumulator_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(factor_33_1 == factor_33_2);
}

int fn_R000697_9713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_35 > 23)
  {
    acc = ((acc + (accumulator_35 * 2)) + 5) & 127;
    aux ^= accumulator_35 & 15;
  }
  else
  {
    acc = ((acc - accumulator_35) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int mask_65 = local_arr[aux % 3];
  acc = (acc + (mask_65 * 2)) & 127;
  int factor_33 = (aux + st.buffer[1]) & 3;
  switch (factor_33)
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

void fn_R000697_9713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_10_1 = local_arr_1[aux_1 % 3];
  int tracker_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_10_2 * 2)) & 127;
  int stride_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_42_1)
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

  switch (stride_42_2)
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

  int segment_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_48_1 > 14)
  {
    acc_1 = ((acc_1 + (segment_48_1 * 2)) + 5) & 127;
    aux_1 ^= segment_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_48_2 > 14)
  {
    acc_2 = ((acc_2 + (segment_48_2 * 2)) + 5) & 127;
    aux_2 ^= segment_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_48_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_10_1 == tracker_10_2);
  assert(stride_42_1 == stride_42_2);
  assert(segment_48_1 == segment_48_2);
}

int fn_R000697_9713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int tracker_10 = local_arr[aux % 3];
  acc = (acc + (tracker_10 * 2)) & 127;
  int stride_42 = (aux + st.buffer[1]) & 3;
  switch (stride_42)
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

  int segment_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_48 > 14)
  {
    acc = ((acc + (segment_48 * 2)) + 5) & 127;
    aux ^= segment_48 & 15;
  }
  else
  {
    acc = ((acc - segment_48) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000697_9713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st_1 = {0};
  struct DeviceConfig_R000697_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_46_1 = local_arr_1[aux_1 % 3];
  int parity_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_46_2 * 2)) & 127;
  int parity_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_54_1)
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

  switch (parity_54_2)
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
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
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

  assert(parity_46_1 == parity_46_2);
  assert(parity_54_1 == parity_54_2);
}

int fn_R000697_9713_8(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int parity_46 = local_arr[aux % 3];
  acc = (acc + (parity_46 * 2)) & 127;
  int parity_54 = (aux + st.buffer[1]) & 3;
  switch (parity_54)
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

void fn_R000697_9713_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int offset_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_87_1)
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

  switch (offset_87_2)
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

  int vector_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_76_1) & 63;
  aux_2 = (aux_2 + vector_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_75_1 > 32)
  {
    acc_1 = ((acc_1 + (vector_75_1 * 2)) + 5) & 127;
    aux_1 ^= vector_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_75_2 > 32)
  {
    acc_2 = ((acc_2 + (vector_75_2 * 2)) + 5) & 127;
    aux_2 ^= vector_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_87_1 == offset_87_2);
  assert(vector_76_1 == vector_76_2);
  assert(vector_75_1 == vector_75_2);
}

int fn_R000697_9713_9(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int offset_87 = (aux + st.buffer[1]) & 3;
  switch (offset_87)
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

  int vector_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_76) & 63;
  acc ^= aux;
  int vector_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_75 > 32)
  {
    acc = ((acc + (vector_75 * 2)) + 5) & 127;
    aux ^= vector_75 & 15;
  }
  else
  {
    acc = ((acc - vector_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000697_9713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st_1 = {0};
  struct DeviceConfig_R000697_9713_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_26_1)
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

  switch (accumulator_26_2)
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
  int metric_38_1 = local_arr_1[aux_1 % 3];
  int metric_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_38_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  assert(st_1.id == st_2.id);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.stop_bits == st_2.stop_bits);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_26_1 == accumulator_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_38_1 == metric_38_2);
}

int fn_R000697_9713_10(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000697_9713_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_26 = (aux + st.buffer[1]) & 3;
  switch (accumulator_26)
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
  int metric_38 = local_arr[aux % 3];
  acc = (acc + (metric_38 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int scale_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_95_1 > 33)
  {
    acc_1 = ((acc_1 + (scale_95_1 * 2)) + 5) & 127;
    aux_1 ^= scale_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_95_2 > 33)
  {
    acc_2 = ((acc_2 + (scale_95_2 * 2)) + 5) & 127;
    aux_2 ^= scale_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_99_1) & 63;
  aux_2 = (aux_2 + residue_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_58_1)
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

  switch (metric_58_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_95_1 == scale_95_2);
  assert(residue_99_1 == residue_99_2);
  assert(metric_58_1 == metric_58_2);
}

int fn_R000697_9713_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int scale_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_95 > 33)
  {
    acc = ((acc + (scale_95 * 2)) + 5) & 127;
    aux ^= scale_95 & 15;
  }
  else
  {
    acc = ((acc - scale_95) + 11) & 127;
    aux += 3;
  }
  int residue_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_99) & 63;
  acc ^= aux;
  int metric_58 = (aux + st.buffer[1]) & 3;
  switch (metric_58)
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

void fn_R000697_9713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int index_reg_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_99_1 > 38)
  {
    acc_1 = ((acc_1 + (index_reg_99_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_99_2 > 38)
  {
    acc_2 = ((acc_2 + (index_reg_99_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int anchor_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_72_1) & 63;
  aux_2 = (aux_2 + anchor_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_99_1 == index_reg_99_2);
  assert(anchor_72_1 == anchor_72_2);
}

int fn_R000697_9713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int index_reg_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_99 > 38)
  {
    acc = ((acc + (index_reg_99 * 2)) + 5) & 127;
    aux ^= index_reg_99 & 15;
  }
  else
  {
    acc = ((acc - index_reg_99) + 11) & 127;
    aux += 3;
  }
  int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_72) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int factor_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_75_1 > 11)
  {
    acc_1 = ((acc_1 + (factor_75_1 * 2)) + 5) & 127;
    aux_1 ^= factor_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_75_2 > 11)
  {
    acc_2 = ((acc_2 + (factor_75_2 * 2)) + 5) & 127;
    aux_2 ^= factor_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_66_1) & 63;
  aux_2 = (aux_2 + bound_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_75_1 == factor_75_2);
  assert(bound_66_1 == bound_66_2);
}

int fn_R000697_9713_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int factor_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_75 > 11)
  {
    acc = ((acc + (factor_75 * 2)) + 5) & 127;
    aux ^= factor_75 & 15;
  }
  else
  {
    acc = ((acc - factor_75) + 11) & 127;
    aux += 3;
  }
  int bound_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_66) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000697_9713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int mask_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_10_1) & 63;
  aux_2 = (aux_2 + mask_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_31_1 = local_arr_1[aux_1 % 3];
  int quantum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_31_2 * 2)) & 127;
  int damping_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_99_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_99_1 * 2)) + 5) & 127;
    aux_1 ^= damping_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_99_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_99_2 * 2)) + 5) & 127;
    aux_2 ^= damping_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_10_1 == mask_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_31_1 == quantum_31_2);
  assert(damping_99_1 == damping_99_2);
}

int fn_R000697_9713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int mask_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_10) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quantum_31 = local_arr[aux % 3];
  acc = (acc + (quantum_31 * 2)) & 127;
  int damping_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_99 > 45)
  {
    acc = ((acc + (damping_99 * 2)) + 5) & 127;
    aux ^= damping_99 & 15;
  }
  else
  {
    acc = ((acc - damping_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int threshold_41_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_41_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_41_1)
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

  switch (threshold_41_2)
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
  int bound_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_84_1 > 45)
  {
    acc_1 = ((acc_1 + (bound_84_1 * 2)) + 5) & 127;
    aux_1 ^= bound_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_84_2 > 45)
  {
    acc_2 = ((acc_2 + (bound_84_2 * 2)) + 5) & 127;
    aux_2 ^= bound_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_70_1 = local_arr_1[aux_1 % 3];
  int damping_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_70_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_41_1 == threshold_41_2);
  assert(bound_84_1 == bound_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_70_1 == damping_70_2);
}

int fn_R000697_9713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int threshold_41 = (aux + st.buffer[1]) & 3;
  switch (threshold_41)
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
  int bound_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_84 > 45)
  {
    acc = ((acc + (bound_84 * 2)) + 5) & 127;
    aux ^= bound_84 & 15;
  }
  else
  {
    acc = ((acc - bound_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int damping_70 = local_arr[aux % 3];
  acc = (acc + (damping_70 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int stride_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_49_1) & 63;
  aux_2 = (aux_2 + stride_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_71_1)
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

  switch (cursor_71_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_49_1 == stride_49_2);
  assert(cursor_71_1 == cursor_71_2);
}

int fn_R000697_9713_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int stride_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_49) & 63;
  acc ^= aux;
  int cursor_71 = (aux + st.buffer[1]) & 3;
  switch (cursor_71)
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

void fn_R000697_9713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_27_1 = local_arr_1[aux_1 % 3];
  int accumulator_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_27_2 * 2)) & 127;
  int anchor_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_16_1) & 63;
  aux_2 = (aux_2 + anchor_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_95_1)
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

  switch (quantum_95_2)
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

  int phase_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_98_1 > 17)
  {
    acc_1 = ((acc_1 + (phase_98_1 * 2)) + 5) & 127;
    aux_1 ^= phase_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_98_2 > 17)
  {
    acc_2 = ((acc_2 + (phase_98_2 * 2)) + 5) & 127;
    aux_2 ^= phase_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_27_1 == accumulator_27_2);
  assert(anchor_16_1 == anchor_16_2);
  assert(quantum_95_1 == quantum_95_2);
  assert(phase_98_1 == phase_98_2);
}

int fn_R000697_9713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int accumulator_27 = local_arr[aux % 3];
  acc = (acc + (accumulator_27 * 2)) & 127;
  int anchor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_16) & 63;
  acc ^= aux;
  int quantum_95 = (aux + st.buffer[1]) & 3;
  switch (quantum_95)
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

  int phase_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_98 > 17)
  {
    acc = ((acc + (phase_98 * 2)) + 5) & 127;
    aux ^= phase_98 & 15;
  }
  else
  {
    acc = ((acc - phase_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000697_9713_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st_1 = {0};
  struct AudioFrame_R000697_9713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int factor_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_94_1) & 63;
  aux_2 = (aux_2 + factor_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_54_1 = local_arr_1[aux_1 % 3];
  int cursor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_54_2 * 2)) & 127;
  int weight_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_22_1)
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

  switch (weight_22_2)
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

  int parity_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_58_1 > 20)
  {
    acc_1 = ((acc_1 + (parity_58_1 * 2)) + 5) & 127;
    aux_1 ^= parity_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_58_2 > 20)
  {
    acc_2 = ((acc_2 + (parity_58_2 * 2)) + 5) & 127;
    aux_2 ^= parity_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.channels == st_2.channels);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.peak == st_2.peak);
  assert(st_1.envelope == st_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_94_1 == factor_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_54_1 == cursor_54_2);
  assert(weight_22_1 == weight_22_2);
  assert(parity_58_1 == parity_58_2);
}

int fn_R000697_9713_18(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000697_9713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int factor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_94) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_54 = local_arr[aux % 3];
  acc = (acc + (cursor_54 * 2)) & 127;
  int weight_22 = (aux + st.buffer[1]) & 3;
  switch (weight_22)
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

  int parity_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_58 > 20)
  {
    acc = ((acc + (parity_58 * 2)) + 5) & 127;
    aux ^= parity_58 & 15;
  }
  else
  {
    acc = ((acc - parity_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000697_9713_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int scale_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_61_1) & 63;
  aux_2 = (aux_2 + scale_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_34_1 > 42)
  {
    acc_1 = ((acc_1 + (factor_34_1 * 2)) + 5) & 127;
    aux_1 ^= factor_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_34_2 > 42)
  {
    acc_2 = ((acc_2 + (factor_34_2 * 2)) + 5) & 127;
    aux_2 ^= factor_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_40_1 = local_arr_1[aux_1 % 3];
  int delta_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_40_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_61_1 == scale_61_2);
  assert(factor_34_1 == factor_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_40_1 == delta_40_2);
}

int fn_R000697_9713_19(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int scale_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_61) & 63;
  acc ^= aux;
  int factor_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_34 > 42)
  {
    acc = ((acc + (factor_34 * 2)) + 5) & 127;
    aux ^= factor_34 & 15;
  }
  else
  {
    acc = ((acc - factor_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_40 = local_arr[aux % 3];
  acc = (acc + (delta_40 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_88_1 = local_arr_1[aux_1 % 3];
  int parity_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_88_1 == parity_88_2);
}

int fn_R000697_9713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_88 = local_arr[aux % 3];
  acc = (acc + (parity_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000697_9713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st_1 = {0};
  struct EventLog_R000697_9713_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int segment_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_10_1 > 29)
  {
    acc_1 = ((acc_1 + (segment_10_1 * 2)) + 5) & 127;
    aux_1 ^= segment_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_10_2 > 29)
  {
    acc_2 = ((acc_2 + (segment_10_2 * 2)) + 5) & 127;
    aux_2 ^= segment_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_69_1 = local_arr_1[aux_1 % 3];
  int quantum_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_69_2 * 2)) & 127;
  int metric_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_60_1) & 63;
  aux_2 = (aux_2 + metric_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_10_1 == segment_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_69_1 == quantum_69_2);
  assert(metric_60_1 == metric_60_2);
}

int fn_R000697_9713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000697_9713_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int segment_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_10 > 29)
  {
    acc = ((acc + (segment_10 * 2)) + 5) & 127;
    aux ^= segment_10 & 15;
  }
  else
  {
    acc = ((acc - segment_10) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_69 = local_arr[aux % 3];
  acc = (acc + (quantum_69 * 2)) & 127;
  int metric_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000697_9713_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_37_1 > 35)
  {
    acc_1 = ((acc_1 + (offset_37_1 * 2)) + 5) & 127;
    aux_1 ^= offset_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_37_2 > 35)
  {
    acc_2 = ((acc_2 + (offset_37_2 * 2)) + 5) & 127;
    aux_2 ^= offset_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_26_1 = local_arr_1[aux_1 % 3];
  int residue_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_26_2 * 2)) & 127;
  int weight_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_29_1) & 63;
  aux_2 = (aux_2 + weight_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.density == st_2.density);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_37_1 == offset_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_26_1 == residue_26_2);
  assert(weight_29_1 == weight_29_2);
}

int fn_R000697_9713_22(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000697_9713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_37 > 35)
  {
    acc = ((acc + (offset_37 * 2)) + 5) & 127;
    aux ^= offset_37 & 15;
  }
  else
  {
    acc = ((acc - offset_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_26 = local_arr[aux % 3];
  acc = (acc + (residue_26 * 2)) & 127;
  int weight_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_29) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000697_0_1;
  int sec_r000697_0_2;
  int sec_r000697_1_1;
  int sec_r000697_1_2;
  int sec_r000697_2_1;
  int sec_r000697_2_2;
  int sec_r000697_3_1;
  int sec_r000697_3_2;
  int sec_r000697_4_1;
  int sec_r000697_4_2;
  int sec_r000697_5_1;
  int sec_r000697_5_2;
  int sec_r000697_6_1;
  int sec_r000697_6_2;
  int sec_r000697_7_1;
  int sec_r000697_7_2;
  int sec_r000697_8_1;
  int sec_r000697_8_2;
  int sec_r000697_9_1;
  int sec_r000697_9_2;
  int sec_r000697_10_1;
  int sec_r000697_10_2;
  int sec_r000697_11_1;
  int sec_r000697_11_2;
  int sec_r000697_12_1;
  int sec_r000697_12_2;
  int sec_r000697_13_1;
  int sec_r000697_13_2;
  int sec_r000697_14_1;
  int sec_r000697_14_2;
  int sec_r000697_15_1;
  int sec_r000697_15_2;
  int sec_r000697_16_1;
  int sec_r000697_16_2;
  int sec_r000697_17_1;
  int sec_r000697_17_2;
  int sec_r000697_18_1;
  int sec_r000697_18_2;
  int sec_r000697_19_1;
  int sec_r000697_19_2;
  int sec_r000697_20_1;
  int sec_r000697_20_2;
  int pub_r000697_0_1;
  int pub_r000697_0_2;
  int pub_r000697_1_1;
  int pub_r000697_1_2;
  int pub_r000697_2_1;
  int pub_r000697_2_2;
  int pub_r000697_3_1;
  int pub_r000697_3_2;
  int pub_r000697_4_1;
  int pub_r000697_4_2;
  int pub_r000697_5_1;
  int pub_r000697_5_2;
  int pub_r000697_6_1;
  int pub_r000697_6_2;
  int pub_r000697_7_1;
  int pub_r000697_7_2;
  int pub_r000697_8_1;
  int pub_r000697_8_2;
  int pub_r000697_9_1;
  int pub_r000697_9_2;
  int pub_r000697_10_1;
  int pub_r000697_10_2;
  int pub_r000697_11_1;
  int pub_r000697_11_2;
  int pub_r000697_12_1;
  int pub_r000697_12_2;
  int pub_r000697_13_1;
  int pub_r000697_13_2;
  int pub_r000697_14_1;
  int pub_r000697_14_2;
  int pub_r000697_15_1;
  int pub_r000697_15_2;
  int pub_r000697_16_1;
  int pub_r000697_16_2;
  int pub_r000697_17_1;
  int pub_r000697_17_2;
  int pub_r000697_18_1;
  int pub_r000697_18_2;
  int pub_r000697_19_1;
  int pub_r000697_19_2;
  int pub_r000697_20_1;
  int pub_r000697_20_2;
  int pub_r000697_21_1;
  int pub_r000697_21_2;
  int pub_r000697_22_1;
  int pub_r000697_22_2;
  int pub_r000697_23_1;
  int pub_r000697_23_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000697_0_1 >= (-100)) && (pub_r000697_0_1 <= 100));
  __CPROVER_assume((pub_r000697_0_2 >= (-100)) && (pub_r000697_0_2 <= 100));
  __CPROVER_assume((pub_r000697_1_1 >= (-100)) && (pub_r000697_1_1 <= 100));
  __CPROVER_assume((pub_r000697_1_2 >= (-100)) && (pub_r000697_1_2 <= 100));
  __CPROVER_assume((pub_r000697_2_1 >= (-100)) && (pub_r000697_2_1 <= 100));
  __CPROVER_assume((pub_r000697_2_2 >= (-100)) && (pub_r000697_2_2 <= 100));
  __CPROVER_assume((pub_r000697_3_1 >= (-100)) && (pub_r000697_3_1 <= 100));
  __CPROVER_assume((pub_r000697_3_2 >= (-100)) && (pub_r000697_3_2 <= 100));
  __CPROVER_assume((pub_r000697_4_1 >= (-100)) && (pub_r000697_4_1 <= 100));
  __CPROVER_assume((pub_r000697_4_2 >= (-100)) && (pub_r000697_4_2 <= 100));
  __CPROVER_assume((pub_r000697_5_1 >= (-100)) && (pub_r000697_5_1 <= 100));
  __CPROVER_assume((pub_r000697_5_2 >= (-100)) && (pub_r000697_5_2 <= 100));
  __CPROVER_assume((pub_r000697_6_1 >= (-100)) && (pub_r000697_6_1 <= 100));
  __CPROVER_assume((pub_r000697_6_2 >= (-100)) && (pub_r000697_6_2 <= 100));
  __CPROVER_assume((pub_r000697_7_1 >= (-100)) && (pub_r000697_7_1 <= 100));
  __CPROVER_assume((pub_r000697_7_2 >= (-100)) && (pub_r000697_7_2 <= 100));
  __CPROVER_assume((pub_r000697_8_1 >= (-100)) && (pub_r000697_8_1 <= 100));
  __CPROVER_assume((pub_r000697_8_2 >= (-100)) && (pub_r000697_8_2 <= 100));
  __CPROVER_assume((pub_r000697_9_1 >= (-100)) && (pub_r000697_9_1 <= 100));
  __CPROVER_assume((pub_r000697_9_2 >= (-100)) && (pub_r000697_9_2 <= 100));
  __CPROVER_assume((pub_r000697_10_1 >= (-100)) && (pub_r000697_10_1 <= 100));
  __CPROVER_assume((pub_r000697_10_2 >= (-100)) && (pub_r000697_10_2 <= 100));
  __CPROVER_assume((pub_r000697_11_1 >= (-100)) && (pub_r000697_11_1 <= 100));
  __CPROVER_assume((pub_r000697_11_2 >= (-100)) && (pub_r000697_11_2 <= 100));
  __CPROVER_assume((pub_r000697_12_1 >= (-100)) && (pub_r000697_12_1 <= 100));
  __CPROVER_assume((pub_r000697_12_2 >= (-100)) && (pub_r000697_12_2 <= 100));
  __CPROVER_assume((pub_r000697_13_1 >= (-100)) && (pub_r000697_13_1 <= 100));
  __CPROVER_assume((pub_r000697_13_2 >= (-100)) && (pub_r000697_13_2 <= 100));
  __CPROVER_assume((pub_r000697_14_1 >= (-100)) && (pub_r000697_14_1 <= 100));
  __CPROVER_assume((pub_r000697_14_2 >= (-100)) && (pub_r000697_14_2 <= 100));
  __CPROVER_assume((pub_r000697_15_1 >= (-100)) && (pub_r000697_15_1 <= 100));
  __CPROVER_assume((pub_r000697_15_2 >= (-100)) && (pub_r000697_15_2 <= 100));
  __CPROVER_assume((pub_r000697_16_1 >= (-100)) && (pub_r000697_16_1 <= 100));
  __CPROVER_assume((pub_r000697_16_2 >= (-100)) && (pub_r000697_16_2 <= 100));
  __CPROVER_assume((pub_r000697_17_1 >= (-100)) && (pub_r000697_17_1 <= 100));
  __CPROVER_assume((pub_r000697_17_2 >= (-100)) && (pub_r000697_17_2 <= 100));
  __CPROVER_assume((pub_r000697_18_1 >= (-100)) && (pub_r000697_18_1 <= 100));
  __CPROVER_assume((pub_r000697_18_2 >= (-100)) && (pub_r000697_18_2 <= 100));
  __CPROVER_assume((pub_r000697_19_1 >= (-100)) && (pub_r000697_19_1 <= 100));
  __CPROVER_assume((pub_r000697_19_2 >= (-100)) && (pub_r000697_19_2 <= 100));
  __CPROVER_assume((pub_r000697_20_1 >= (-100)) && (pub_r000697_20_1 <= 100));
  __CPROVER_assume((pub_r000697_20_2 >= (-100)) && (pub_r000697_20_2 <= 100));
  __CPROVER_assume((pub_r000697_21_1 >= (-100)) && (pub_r000697_21_1 <= 100));
  __CPROVER_assume((pub_r000697_21_2 >= (-100)) && (pub_r000697_21_2 <= 100));
  __CPROVER_assume((pub_r000697_22_1 >= (-100)) && (pub_r000697_22_1 <= 100));
  __CPROVER_assume((pub_r000697_22_2 >= (-100)) && (pub_r000697_22_2 <= 100));
  __CPROVER_assume((pub_r000697_23_1 >= (-100)) && (pub_r000697_23_1 <= 100));
  __CPROVER_assume((pub_r000697_23_2 >= (-100)) && (pub_r000697_23_2 <= 100));
  __CPROVER_assume((sec_r000697_0_1 >= 0) && (sec_r000697_0_1 <= 255));
  __CPROVER_assume((sec_r000697_0_2 >= 0) && (sec_r000697_0_2 <= 255));
  __CPROVER_assume((sec_r000697_1_1 >= 0) && (sec_r000697_1_1 <= 255));
  __CPROVER_assume((sec_r000697_1_2 >= 0) && (sec_r000697_1_2 <= 255));
  __CPROVER_assume((sec_r000697_2_1 >= 0) && (sec_r000697_2_1 <= 255));
  __CPROVER_assume((sec_r000697_2_2 >= 0) && (sec_r000697_2_2 <= 255));
  __CPROVER_assume((sec_r000697_3_1 >= 0) && (sec_r000697_3_1 <= 255));
  __CPROVER_assume((sec_r000697_3_2 >= 0) && (sec_r000697_3_2 <= 255));
  __CPROVER_assume((sec_r000697_4_1 >= 0) && (sec_r000697_4_1 <= 255));
  __CPROVER_assume((sec_r000697_4_2 >= 0) && (sec_r000697_4_2 <= 255));
  __CPROVER_assume((sec_r000697_5_1 >= 0) && (sec_r000697_5_1 <= 255));
  __CPROVER_assume((sec_r000697_5_2 >= 0) && (sec_r000697_5_2 <= 255));
  __CPROVER_assume((sec_r000697_6_1 >= 0) && (sec_r000697_6_1 <= 255));
  __CPROVER_assume((sec_r000697_6_2 >= 0) && (sec_r000697_6_2 <= 255));
  __CPROVER_assume((sec_r000697_7_1 >= 0) && (sec_r000697_7_1 <= 255));
  __CPROVER_assume((sec_r000697_7_2 >= 0) && (sec_r000697_7_2 <= 255));
  __CPROVER_assume((sec_r000697_8_1 >= 0) && (sec_r000697_8_1 <= 255));
  __CPROVER_assume((sec_r000697_8_2 >= 0) && (sec_r000697_8_2 <= 255));
  __CPROVER_assume((sec_r000697_9_1 >= 0) && (sec_r000697_9_1 <= 255));
  __CPROVER_assume((sec_r000697_9_2 >= 0) && (sec_r000697_9_2 <= 255));
  __CPROVER_assume((sec_r000697_10_1 >= 0) && (sec_r000697_10_1 <= 255));
  __CPROVER_assume((sec_r000697_10_2 >= 0) && (sec_r000697_10_2 <= 255));
  __CPROVER_assume((sec_r000697_11_1 >= 0) && (sec_r000697_11_1 <= 255));
  __CPROVER_assume((sec_r000697_11_2 >= 0) && (sec_r000697_11_2 <= 255));
  __CPROVER_assume((sec_r000697_12_1 >= 0) && (sec_r000697_12_1 <= 255));
  __CPROVER_assume((sec_r000697_12_2 >= 0) && (sec_r000697_12_2 <= 255));
  __CPROVER_assume((sec_r000697_13_1 >= 0) && (sec_r000697_13_1 <= 255));
  __CPROVER_assume((sec_r000697_13_2 >= 0) && (sec_r000697_13_2 <= 255));
  __CPROVER_assume((sec_r000697_14_1 >= 0) && (sec_r000697_14_1 <= 255));
  __CPROVER_assume((sec_r000697_14_2 >= 0) && (sec_r000697_14_2 <= 255));
  __CPROVER_assume((sec_r000697_15_1 >= 0) && (sec_r000697_15_1 <= 255));
  __CPROVER_assume((sec_r000697_15_2 >= 0) && (sec_r000697_15_2 <= 255));
  __CPROVER_assume((sec_r000697_16_1 >= 0) && (sec_r000697_16_1 <= 255));
  __CPROVER_assume((sec_r000697_16_2 >= 0) && (sec_r000697_16_2 <= 255));
  __CPROVER_assume((sec_r000697_17_1 >= 0) && (sec_r000697_17_1 <= 255));
  __CPROVER_assume((sec_r000697_17_2 >= 0) && (sec_r000697_17_2 <= 255));
  __CPROVER_assume((sec_r000697_18_1 >= 0) && (sec_r000697_18_1 <= 255));
  __CPROVER_assume((sec_r000697_18_2 >= 0) && (sec_r000697_18_2 <= 255));
  __CPROVER_assume((sec_r000697_19_1 >= 0) && (sec_r000697_19_1 <= 255));
  __CPROVER_assume((sec_r000697_19_2 >= 0) && (sec_r000697_19_2 <= 255));
  __CPROVER_assume((sec_r000697_20_1 >= 0) && (sec_r000697_20_1 <= 255));
  __CPROVER_assume((sec_r000697_20_2 >= 0) && (sec_r000697_20_2 <= 255));
  struct AudioFrame_R000697_9713_0 st_var_0_1 = {0};
  struct AudioFrame_R000697_9713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000697_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000697_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000697_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000697_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000697_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000697_0_2 + 7) & 15;
  struct MatrixBlock_R000697_9713_1 st_var_1_1 = {0};
  struct MatrixBlock_R000697_9713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000697_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000697_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000697_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000697_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000697_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000697_0_2 + 9) & 15;
  struct EventLog_R000697_9713_2 st_var_2_1 = {0};
  struct EventLog_R000697_9713_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000697_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000697_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000697_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000697_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000697_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000697_0_2 + 11) & 15;
  struct DeviceConfig_R000697_9713_3 st_var_3_1 = {0};
  struct DeviceConfig_R000697_9713_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000697_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000697_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000697_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000697_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000697_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000697_0_2 + 13) & 15;
  union TelemetryField_R000697_9713_0 u_var_1;
  union TelemetryField_R000697_9713_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (st_var_3_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_3_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
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
  int stage_v_6_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_6_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_6_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_6_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 8) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
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
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 31)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 31)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 38)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 38)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  if ((sec_r000697_12_1 & 1) != 0)
  {
    if ((sec_r000697_11_1 & 2) != 0)
    {
      stage_v_15_1 = (pub_r000697_5_1 + 31) & 127;
    }
    else
    {
      stage_v_15_1 = (pub_r000697_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_1 = (pub_r000697_5_1 + 7) & 127;
  }
  if ((sec_r000697_12_2 & 1) != 0)
  {
    if ((sec_r000697_11_2 & 2) != 0)
    {
      stage_v_15_2 = (pub_r000697_5_2 + 31) & 127;
    }
    else
    {
      stage_v_15_2 = (pub_r000697_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_15_2 = (pub_r000697_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_16_1 = (pub_r000697_8_1 + 31) & 127;
    }
    else
    {
      stage_v_16_1 = (pub_r000697_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_1 = (pub_r000697_8_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_16_2 = (pub_r000697_8_2 + 31) & 127;
    }
    else
    {
      stage_v_16_2 = (pub_r000697_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_16_2 = (pub_r000697_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  if ((sec_r000697_15_1 & 1) != 0)
  {
    if ((sec_r000697_17_1 & 2) != 0)
    {
      stage_v_17_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_17_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((sec_r000697_15_2 & 1) != 0)
  {
    if ((sec_r000697_17_2 & 2) != 0)
    {
      stage_v_17_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_17_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_17_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  if ((sec_r000697_2_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_18_1 = (pub_r000697_10_1 + 31) & 127;
    }
    else
    {
      stage_v_18_1 = (pub_r000697_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_1 = (pub_r000697_10_1 + 7) & 127;
  }
  if ((sec_r000697_2_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_18_2 = (pub_r000697_10_2 + 31) & 127;
    }
    else
    {
      stage_v_18_2 = (pub_r000697_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_18_2 = (pub_r000697_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  if ((sec_r000697_14_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_19_1 = (pub_r000697_2_1 + 31) & 127;
    }
    else
    {
      stage_v_19_1 = (pub_r000697_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_1 = (pub_r000697_2_1 + 7) & 127;
  }
  if ((sec_r000697_14_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_19_2 = (pub_r000697_2_2 + 31) & 127;
    }
    else
    {
      stage_v_19_2 = (pub_r000697_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_19_2 = (pub_r000697_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  if ((sec_r000697_7_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_20_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_20_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_7_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_20_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_20_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_20_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000697_5_1 & 2) != 0)
    {
      stage_v_21_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_21_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000697_5_2 & 2) != 0)
    {
      stage_v_21_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_21_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_21_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = 0;
  int stage_v_22_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_22_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_22_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_22_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_22_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_22_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000697_4_1 & 2) != 0)
    {
      stage_v_23_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_23_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000697_4_2 & 2) != 0)
    {
      stage_v_23_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_23_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_23_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000697_2_1 & 2) != 0)
    {
      stage_v_24_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_24_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000697_2_2 & 2) != 0)
    {
      stage_v_24_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_24_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_24_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000697_1_1 & 2) != 0)
    {
      stage_v_25_1 = (pub_r000697_12_1 + 31) & 127;
    }
    else
    {
      stage_v_25_1 = (pub_r000697_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_1 = (pub_r000697_12_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000697_1_2 & 2) != 0)
    {
      stage_v_25_2 = (pub_r000697_12_2 + 31) & 127;
    }
    else
    {
      stage_v_25_2 = (pub_r000697_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_25_2 = (pub_r000697_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000697_1_1 & 2) != 0)
    {
      stage_v_26_1 = (pub_r000697_19_1 + 31) & 127;
    }
    else
    {
      stage_v_26_1 = (pub_r000697_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_1 = (pub_r000697_19_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000697_1_2 & 2) != 0)
    {
      stage_v_26_2 = (pub_r000697_19_2 + 31) & 127;
    }
    else
    {
      stage_v_26_2 = (pub_r000697_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_26_2 = (pub_r000697_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000697_11_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000697_16_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000697_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000697_16_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000697_11_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000697_16_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000697_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000697_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000697_7_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000697_7_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000697_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000697_7_1 + 7) & 127;
  }
  if ((sec_r000697_7_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000697_7_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000697_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000697_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000697_9_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000697_16_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000697_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000697_16_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000697_9_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000697_16_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000697_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000697_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((stage_v_16_1 & 1) != 0)
  {
    if ((sec_r000697_6_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((stage_v_16_2 & 1) != 0)
  {
    if ((sec_r000697_6_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000697_9_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000697_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000697_9_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000697_9_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000697_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000697_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000697_0_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000697_20_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000697_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000697_20_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000697_0_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000697_20_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000697_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000697_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000697_2_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000697_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000697_2_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000697_2_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000697_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000697_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000697_9_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000697_3_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000697_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000697_3_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000697_9_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000697_3_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000697_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000697_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((sec_r000697_6_1 & 1) != 0)
  {
    if ((sec_r000697_0_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((sec_r000697_6_2 & 1) != 0)
  {
    if ((sec_r000697_0_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r000697_2_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r000697_2_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000697_8_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((sec_r000697_8_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000697_20_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000697_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000697_20_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000697_20_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000697_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000697_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000697_12_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000697_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000697_12_1 + 7) & 127;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000697_12_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000697_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000697_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000697_11_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000697_2_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000697_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000697_2_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000697_11_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000697_2_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000697_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000697_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_38_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000697_22_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000697_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000697_22_1 + 7) & 127;
  }
  if ((stage_v_38_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000697_22_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000697_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000697_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((sec_r000697_19_1 & 1) != 0)
  {
    if ((sec_r000697_18_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_19_2 & 1) != 0)
  {
    if ((sec_r000697_18_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000697_11_1 & 1) != 0)
  {
    if ((sec_r000697_14_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000697_5_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000697_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000697_5_1 + 7) & 127;
  }
  if ((sec_r000697_11_2 & 1) != 0)
  {
    if ((sec_r000697_14_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000697_5_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000697_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000697_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((sec_r000697_6_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000697_6_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000697_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000697_6_1 + 7) & 127;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((sec_r000697_6_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000697_6_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000697_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000697_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((sec_r000697_9_1 & 1) != 0)
  {
    if ((sec_r000697_5_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000697_3_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000697_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000697_3_1 + 7) & 127;
  }
  if ((sec_r000697_9_2 & 1) != 0)
  {
    if ((sec_r000697_5_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000697_3_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000697_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000697_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000697_5_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000697_5_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((sec_r000697_9_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000697_8_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000697_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000697_8_1 + 7) & 127;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((sec_r000697_9_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000697_8_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000697_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000697_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000697_1_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000697_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000697_1_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000697_1_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000697_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000697_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((sec_r000697_5_1 & 1) != 0)
  {
    if ((sec_r000697_11_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000697_21_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000697_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000697_21_1 + 7) & 127;
  }
  if ((sec_r000697_5_2 & 1) != 0)
  {
    if ((sec_r000697_11_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000697_21_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000697_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000697_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000697_14_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000697_16_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000697_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000697_16_1 + 7) & 127;
  }
  if ((sec_r000697_14_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000697_16_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000697_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000697_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000697_22_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000697_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000697_22_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000697_22_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000697_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000697_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000697_20_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000697_8_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000697_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000697_8_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000697_20_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000697_8_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000697_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000697_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000697_8_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000697_6_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000697_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000697_6_1 + 7) & 127;
  }
  if ((sec_r000697_8_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000697_6_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000697_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000697_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000697_10_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000697_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000697_10_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000697_10_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000697_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000697_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_15_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000697_1_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000697_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000697_1_1 + 7) & 127;
  }
  if ((stage_v_15_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000697_1_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000697_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000697_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000697_6_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000697_6_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000697_10_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000697_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000697_10_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000697_10_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000697_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000697_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((sec_r000697_1_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000697_16_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000697_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000697_16_1 + 7) & 127;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((sec_r000697_1_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000697_16_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000697_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000697_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((sec_r000697_4_1 & 1) != 0)
  {
    if ((sec_r000697_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000697_12_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000697_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000697_12_1 + 7) & 127;
  }
  if ((sec_r000697_4_2 & 1) != 0)
  {
    if ((sec_r000697_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000697_12_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000697_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000697_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000697_19_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000697_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000697_19_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000697_19_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000697_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000697_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000697_16_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000697_1_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000697_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000697_1_1 + 7) & 127;
  }
  if ((sec_r000697_16_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000697_1_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000697_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000697_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000697_16_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000697_16_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((sec_r000697_18_1 & 1) != 0)
  {
    if ((sec_r000697_2_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000697_13_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000697_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000697_13_1 + 7) & 127;
  }
  if ((sec_r000697_18_2 & 1) != 0)
  {
    if ((sec_r000697_2_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000697_13_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000697_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000697_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000697_20_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000697_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000697_20_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000697_20_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000697_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000697_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((sec_r000697_20_1 & 1) != 0)
  {
    if ((sec_r000697_2_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((sec_r000697_20_2 & 1) != 0)
  {
    if ((sec_r000697_2_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000697_10_1 & 1) != 0)
  {
    if ((sec_r000697_20_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000697_9_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000697_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000697_9_1 + 7) & 127;
  }
  if ((sec_r000697_10_2 & 1) != 0)
  {
    if ((sec_r000697_20_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000697_9_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000697_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000697_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000697_18_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000697_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000697_18_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000697_18_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000697_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000697_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000697_11_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_11_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000697_3_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000697_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000697_3_1 + 7) & 127;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000697_3_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000697_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000697_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_23_1 & 1) != 0)
  {
    if ((sec_r000697_0_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_23_2 & 1) != 0)
  {
    if ((sec_r000697_0_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r000697_4_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000697_3_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000697_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000697_3_1 + 7) & 127;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r000697_4_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000697_3_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000697_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000697_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_18_1 & 1) != 0)
  {
    if ((sec_r000697_3_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_18_2 & 1) != 0)
  {
    if ((sec_r000697_3_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000697_6_1 & 1) != 0)
  {
    if ((sec_r000697_14_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000697_1_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000697_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000697_1_1 + 7) & 127;
  }
  if ((sec_r000697_6_2 & 1) != 0)
  {
    if ((sec_r000697_14_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000697_1_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000697_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000697_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000697_3_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000697_3_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000697_17_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000697_5_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000697_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000697_5_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000697_17_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000697_5_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000697_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000697_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000697_22_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000697_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000697_22_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000697_22_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000697_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000697_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((sec_r000697_17_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000697_8_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000697_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000697_8_1 + 7) & 127;
  }
  if ((sec_r000697_17_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000697_8_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000697_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000697_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000697_17_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000697_15_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000697_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000697_15_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000697_17_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000697_15_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000697_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000697_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000697_3_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((sec_r000697_3_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((sec_r000697_11_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((sec_r000697_11_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_28_1 & 1) != 0)
  {
    if ((sec_r000697_5_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000697_18_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000697_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000697_18_1 + 7) & 127;
  }
  if ((stage_v_28_2 & 1) != 0)
  {
    if ((sec_r000697_5_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000697_18_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000697_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000697_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000697_12_1 & 1) != 0)
  {
    if ((sec_r000697_20_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000697_21_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000697_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000697_21_1 + 7) & 127;
  }
  if ((sec_r000697_12_2 & 1) != 0)
  {
    if ((sec_r000697_20_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000697_21_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000697_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000697_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((sec_r000697_13_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_13_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000697_6_1 & 1) != 0)
  {
    if ((sec_r000697_0_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000697_22_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000697_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000697_22_1 + 7) & 127;
  }
  if ((sec_r000697_6_2 & 1) != 0)
  {
    if ((sec_r000697_0_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000697_22_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000697_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000697_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000697_19_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000697_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000697_19_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000697_19_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000697_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000697_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000697_20_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000697_3_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000697_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000697_3_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000697_20_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000697_3_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000697_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000697_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000697_14_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000697_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000697_14_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000697_14_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000697_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000697_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((sec_r000697_5_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_5_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000697_10_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000697_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000697_10_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000697_10_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000697_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000697_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((sec_r000697_13_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000697_5_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000697_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000697_5_1 + 7) & 127;
  }
  if ((sec_r000697_13_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000697_5_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000697_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000697_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((sec_r000697_9_1 & 1) != 0)
  {
    if ((sec_r000697_11_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000697_21_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000697_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000697_21_1 + 7) & 127;
  }
  if ((sec_r000697_9_2 & 1) != 0)
  {
    if ((sec_r000697_11_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000697_21_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000697_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000697_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000697_10_1 & 1) != 0)
  {
    if ((sec_r000697_9_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000697_7_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000697_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000697_7_1 + 7) & 127;
  }
  if ((sec_r000697_10_2 & 1) != 0)
  {
    if ((sec_r000697_9_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000697_7_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000697_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000697_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000697_2_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000697_18_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000697_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000697_18_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000697_2_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000697_18_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000697_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000697_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000697_22_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000697_22_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000697_22_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000697_22_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000697_22_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000697_22_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((sec_r000697_4_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000697_13_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000697_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000697_13_1 + 7) & 127;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((sec_r000697_4_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000697_13_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000697_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000697_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000697_13_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000697_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000697_13_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000697_13_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000697_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000697_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000697_7_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000697_8_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000697_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000697_8_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000697_7_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000697_8_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000697_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000697_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000697_12_1 & 1) != 0)
  {
    if ((sec_r000697_10_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000697_12_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000697_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000697_12_1 + 7) & 127;
  }
  if ((sec_r000697_12_2 & 1) != 0)
  {
    if ((sec_r000697_10_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000697_12_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000697_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000697_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000697_6_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000697_2_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000697_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000697_2_1 + 7) & 127;
  }
  if ((sec_r000697_6_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000697_2_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000697_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000697_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((sec_r000697_6_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000697_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000697_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000697_6_1 + 7) & 127;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((sec_r000697_6_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000697_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000697_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000697_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000697_0_1 & 1) != 0)
  {
    if ((sec_r000697_18_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((sec_r000697_0_2 & 1) != 0)
  {
    if ((sec_r000697_18_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000697_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000697_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000697_1_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000697_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000697_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000697_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((sec_r000697_18_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000697_9_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000697_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000697_9_1 + 7) & 127;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((sec_r000697_18_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000697_9_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000697_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000697_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((sec_r000697_15_1 & 1) != 0)
  {
    if ((sec_r000697_1_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000697_23_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000697_23_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000697_23_1 + 7) & 127;
  }
  if ((sec_r000697_15_2 & 1) != 0)
  {
    if ((sec_r000697_1_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000697_23_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000697_23_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000697_23_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r000697_0_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000697_2_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000697_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000697_2_1 + 7) & 127;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r000697_0_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000697_2_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000697_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000697_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000697_9_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000697_11_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000697_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000697_11_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000697_9_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000697_11_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000697_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000697_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((sec_r000697_11_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000697_21_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000697_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000697_21_1 + 7) & 127;
  }
  if ((sec_r000697_11_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000697_21_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000697_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000697_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_67_1 & 1) != 0)
  {
    if ((sec_r000697_8_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000697_17_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000697_17_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000697_17_1 + 7) & 127;
  }
  if ((stage_v_67_2 & 1) != 0)
  {
    if ((sec_r000697_8_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000697_17_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000697_17_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000697_17_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000697_17_1 & 1) != 0)
  {
    if ((sec_r000697_1_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000697_13_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000697_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000697_13_1 + 7) & 127;
  }
  if ((sec_r000697_17_2 & 1) != 0)
  {
    if ((sec_r000697_1_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000697_13_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000697_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000697_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000697_20_1 & 1) != 0)
  {
    if ((sec_r000697_15_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((sec_r000697_20_2 & 1) != 0)
  {
    if ((sec_r000697_15_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000697_21_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000697_21_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000697_21_1 + 7) & 127;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000697_21_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000697_21_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000697_21_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000697_4_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000697_7_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000697_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000697_7_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000697_4_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000697_7_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000697_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000697_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((sec_r000697_20_1 & 1) != 0)
  {
    if ((sec_r000697_12_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((sec_r000697_20_2 & 1) != 0)
  {
    if ((sec_r000697_12_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((sec_r000697_4_1 & 1) != 0)
  {
    if ((sec_r000697_18_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000697_13_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000697_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000697_13_1 + 7) & 127;
  }
  if ((sec_r000697_4_2 & 1) != 0)
  {
    if ((sec_r000697_18_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000697_13_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000697_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000697_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000697_19_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000697_16_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000697_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000697_16_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000697_19_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000697_16_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000697_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000697_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000697_16_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000697_4_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000697_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000697_4_1 + 7) & 127;
  }
  if ((sec_r000697_16_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000697_4_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000697_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000697_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((sec_r000697_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000697_12_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000697_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000697_12_1 + 7) & 127;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((sec_r000697_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000697_12_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000697_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000697_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((sec_r000697_11_1 & 1) != 0)
  {
    if ((sec_r000697_17_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000697_0_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000697_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000697_0_1 + 7) & 127;
  }
  if ((sec_r000697_11_2 & 1) != 0)
  {
    if ((sec_r000697_17_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000697_0_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000697_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000697_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000697_5_1 != sec_r000697_5_2);
  __CPROVER_assume(sec_r000697_15_1 != sec_r000697_15_2);
  __CPROVER_assume(pub_r000697_7_1 == pub_r000697_7_2);
  __CPROVER_assume(pub_r000697_22_1 == pub_r000697_22_2);
  __CPROVER_assume(sec_r000697_9_1 != sec_r000697_9_2);
  __CPROVER_assume(sec_r000697_13_1 != sec_r000697_13_2);
  __CPROVER_assume(pub_r000697_13_1 == pub_r000697_13_2);
  __CPROVER_assume(sec_r000697_11_1 != sec_r000697_11_2);
  __CPROVER_assume(pub_r000697_9_1 == pub_r000697_9_2);
  __CPROVER_assume(pub_r000697_12_1 == pub_r000697_12_2);
  __CPROVER_assume(sec_r000697_17_1 != sec_r000697_17_2);
  __CPROVER_assume(sec_r000697_19_1 != sec_r000697_19_2);
  __CPROVER_assume(pub_r000697_11_1 == pub_r000697_11_2);
  __CPROVER_assume(pub_r000697_3_1 == pub_r000697_3_2);
  __CPROVER_assume(sec_r000697_7_1 != sec_r000697_7_2);
  __CPROVER_assume(pub_r000697_14_1 == pub_r000697_14_2);
  __CPROVER_assume(sec_r000697_14_1 != sec_r000697_14_2);
  __CPROVER_assume(pub_r000697_4_1 == pub_r000697_4_2);
  __CPROVER_assume(pub_r000697_0_1 == pub_r000697_0_2);
  __CPROVER_assume(pub_r000697_1_1 == pub_r000697_1_2);
  __CPROVER_assume(sec_r000697_10_1 != sec_r000697_10_2);
  __CPROVER_assume(pub_r000697_16_1 == pub_r000697_16_2);
  __CPROVER_assume(pub_r000697_23_1 == pub_r000697_23_2);
  __CPROVER_assume(pub_r000697_21_1 == pub_r000697_21_2);
  __CPROVER_assume(sec_r000697_6_1 != sec_r000697_6_2);
  __CPROVER_assume(sec_r000697_1_1 != sec_r000697_1_2);
  __CPROVER_assume(pub_r000697_10_1 == pub_r000697_10_2);
  __CPROVER_assume(pub_r000697_15_1 == pub_r000697_15_2);
  __CPROVER_assume(sec_r000697_3_1 != sec_r000697_3_2);
  __CPROVER_assume(sec_r000697_16_1 != sec_r000697_16_2);
  __CPROVER_assume(sec_r000697_4_1 != sec_r000697_4_2);
  __CPROVER_assume(pub_r000697_19_1 == pub_r000697_19_2);
  __CPROVER_assume(pub_r000697_20_1 == pub_r000697_20_2);
  __CPROVER_assume(pub_r000697_2_1 == pub_r000697_2_2);
  __CPROVER_assume(sec_r000697_0_1 != sec_r000697_0_2);
  __CPROVER_assume(pub_r000697_6_1 == pub_r000697_6_2);
  __CPROVER_assume(sec_r000697_20_1 != sec_r000697_20_2);
  __CPROVER_assume(pub_r000697_17_1 == pub_r000697_17_2);
  __CPROVER_assume(sec_r000697_18_1 != sec_r000697_18_2);
  __CPROVER_assume(pub_r000697_5_1 == pub_r000697_5_2);
  __CPROVER_assume(pub_r000697_8_1 == pub_r000697_8_2);
  __CPROVER_assume(sec_r000697_2_1 != sec_r000697_2_2);
  __CPROVER_assume(sec_r000697_8_1 != sec_r000697_8_2);
  __CPROVER_assume(sec_r000697_12_1 != sec_r000697_12_2);
  __CPROVER_assume(pub_r000697_18_1 == pub_r000697_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.channels == st_var_0_2.channels);
  assert(st_var_0_1.sample_rate == st_var_0_2.sample_rate);
  assert(st_var_0_1.peak == st_var_0_2.peak);
  assert(st_var_0_1.envelope == st_var_0_2.envelope);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.stride == st_var_1_2.stride);
  assert(st_var_1_1.scale == st_var_1_2.scale);
  assert(st_var_1_1.determinant == st_var_1_2.determinant);
  assert(st_var_1_1.density == st_var_1_2.density);
  assert(st_var_1_1.trace == st_var_1_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.port == st_var_3_2.port);
  assert(st_var_3_1.parity == st_var_3_2.parity);
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
}


