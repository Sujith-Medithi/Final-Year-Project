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
struct SensorNode_R001646_4613_0
{
  unsigned char gain;
  int calib;
  int reading;
  int status;
  short offset;
  int buffer[3];
};
struct StreamBuffer_R001646_4613_1
{
  int checksum;
  int tail;
  int watermark;
  unsigned char head;
  int buffer[3];
};
struct EventLog_R001646_4613_2
{
  int timestamp;
  int severity;
  int facility;
  int signature;
  int buffer[3];
};
union TelemetryField_R001646_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001646_4613_1
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
void fn_R001646_4613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int pivot_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_42_1) & 63;
  aux_2 = (aux_2 + pivot_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_76_1)
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

  switch (bound_76_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_42_1 == pivot_42_2);
  assert(bound_76_1 == bound_76_2);
}

int fn_R001646_4613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int pivot_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_42) & 63;
  acc ^= aux;
  int bound_76 = (aux + st.buffer[1]) & 3;
  switch (bound_76)
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

void fn_R001646_4613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_89_1 = local_arr_1[aux_1 % 3];
  int segment_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_89_2 * 2)) & 127;
  int checksum_24_1 = 0;
  int checksum_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_24_1 = ((checksum_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_24_2 = ((checksum_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_24_1) & 127;
    acc_2 = (acc_2 + checksum_24_2) & 127;
  }

  int scale_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_73_1) & 63;
  aux_2 = (aux_2 + scale_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_89_1 == segment_89_2);
  assert(checksum_24_1 == checksum_24_2);
  assert(scale_73_1 == scale_73_2);
}

int fn_R001646_4613_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int segment_89 = local_arr[aux % 3];
  acc = (acc + (segment_89 * 2)) & 127;
  int checksum_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_24 = ((checksum_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_24) & 127;
  }

  int scale_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001646_4613_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int coefficient_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_30_1) & 63;
  aux_2 = (aux_2 + coefficient_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_46_1 = local_arr_1[aux_1 % 3];
  int segment_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_46_2 * 2)) & 127;
  int anchor_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_46_1 > 10)
  {
    acc_1 = ((acc_1 + (anchor_46_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_46_2 > 10)
  {
    acc_2 = ((acc_2 + (anchor_46_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_64_1)
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

  switch (phase_64_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_30_1 == coefficient_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_46_1 == segment_46_2);
  assert(anchor_46_1 == anchor_46_2);
  assert(phase_64_1 == phase_64_2);
}

int fn_R001646_4613_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int coefficient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_30) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int segment_46 = local_arr[aux % 3];
  acc = (acc + (segment_46 * 2)) & 127;
  int anchor_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_46 > 10)
  {
    acc = ((acc + (anchor_46 * 2)) + 5) & 127;
    aux ^= anchor_46 & 15;
  }
  else
  {
    acc = ((acc - anchor_46) + 11) & 127;
    aux += 3;
  }
  int phase_64 = (aux + st.buffer[1]) & 3;
  switch (phase_64)
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

void fn_R001646_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st_1 = {0};
  struct EventLog_R001646_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int stride_67_1 = 0;
  int stride_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_67_1 = ((stride_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_67_2 = ((stride_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_67_1) & 127;
    acc_2 = (acc_2 + stride_67_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_67_1 = local_arr_1[aux_1 % 3];
  int metric_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_67_1 == stride_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_67_1 == metric_67_2);
}

int fn_R001646_4613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int stride_67 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_67 = ((stride_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_67) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int metric_67 = local_arr[aux % 3];
  acc = (acc + (metric_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001646_4613_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int residue_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_72_1 > 30)
  {
    acc_1 = ((acc_1 + (residue_72_1 * 2)) + 5) & 127;
    aux_1 ^= residue_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_72_2 > 30)
  {
    acc_2 = ((acc_2 + (residue_72_2 * 2)) + 5) & 127;
    aux_2 ^= residue_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_98_1) & 63;
  aux_2 = (aux_2 + quantum_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_72_1 == residue_72_2);
  assert(quantum_98_1 == quantum_98_2);
}

int fn_R001646_4613_4(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int residue_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_72 > 30)
  {
    acc = ((acc + (residue_72 * 2)) + 5) & 127;
    aux ^= residue_72 & 15;
  }
  else
  {
    acc = ((acc - residue_72) + 11) & 127;
    aux += 3;
  }
  int quantum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001646_4613_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int phase_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_24_1) & 63;
  aux_2 = (aux_2 + phase_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_15_1 > 43)
  {
    acc_1 = ((acc_1 + (checksum_15_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_15_2 > 43)
  {
    acc_2 = ((acc_2 + (checksum_15_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_15_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_24_1 == phase_24_2);
  assert(checksum_15_1 == checksum_15_2);
}

int fn_R001646_4613_5(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_24) & 63;
  acc ^= aux;
  int checksum_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_15 > 43)
  {
    acc = ((acc + (checksum_15 * 2)) + 5) & 127;
    aux ^= checksum_15 & 15;
  }
  else
  {
    acc = ((acc - checksum_15) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001646_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_78_1) & 63;
  aux_2 = (aux_2 + damping_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_36_1 = local_arr_1[aux_1 % 3];
  int threshold_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_36_2 * 2)) & 127;
  int stride_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_68_1)
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

  switch (stride_68_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_78_1 == damping_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_36_1 == threshold_36_2);
  assert(stride_68_1 == stride_68_2);
}

int fn_R001646_4613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_78) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_36 = local_arr[aux % 3];
  acc = (acc + (threshold_36 * 2)) & 127;
  int stride_68 = (aux + st.buffer[1]) & 3;
  switch (stride_68)
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

void fn_R001646_4613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_90_1)
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

  switch (metric_90_2)
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

  int bound_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_35_1) & 63;
  aux_2 = (aux_2 + bound_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_24_1 > 50)
  {
    acc_1 = ((acc_1 + (residue_24_1 * 2)) + 5) & 127;
    aux_1 ^= residue_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_24_2 > 50)
  {
    acc_2 = ((acc_2 + (residue_24_2 * 2)) + 5) & 127;
    aux_2 ^= residue_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_90_1 == metric_90_2);
  assert(bound_35_1 == bound_35_2);
  assert(residue_24_1 == residue_24_2);
}

int fn_R001646_4613_7(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_90 = (aux + st.buffer[1]) & 3;
  switch (metric_90)
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

  int bound_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_35) & 63;
  acc ^= aux;
  int residue_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_24 > 50)
  {
    acc = ((acc + (residue_24 * 2)) + 5) & 127;
    aux ^= residue_24 & 15;
  }
  else
  {
    acc = ((acc - residue_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001646_4613_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int accumulator_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_48_1) & 63;
  aux_2 = (aux_2 + accumulator_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_34_1 > 15)
  {
    acc_1 = ((acc_1 + (segment_34_1 * 2)) + 5) & 127;
    aux_1 ^= segment_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_34_2 > 15)
  {
    acc_2 = ((acc_2 + (segment_34_2 * 2)) + 5) & 127;
    aux_2 ^= segment_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_34_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_73_1 = local_arr_1[aux_1 % 3];
  int phase_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_73_2 * 2)) & 127;
  int threshold_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_28_1)
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

  switch (threshold_28_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_48_1 == accumulator_48_2);
  assert(segment_34_1 == segment_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_73_1 == phase_73_2);
  assert(threshold_28_1 == threshold_28_2);
}

int fn_R001646_4613_8(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int accumulator_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_48) & 63;
  acc ^= aux;
  int segment_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_34 > 15)
  {
    acc = ((acc + (segment_34 * 2)) + 5) & 127;
    aux ^= segment_34 & 15;
  }
  else
  {
    acc = ((acc - segment_34) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_73 = local_arr[aux % 3];
  acc = (acc + (phase_73 * 2)) & 127;
  int threshold_28 = (aux + st.buffer[1]) & 3;
  switch (threshold_28)
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

void fn_R001646_4613_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001646_4613_1 st_1 = {0};
  struct StreamBuffer_R001646_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_16_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_16_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_16_1 > 22)
  {
    acc_1 = ((acc_1 + (cursor_16_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_16_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_16_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_16_2 > 22)
  {
    acc_2 = ((acc_2 + (cursor_16_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_16_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_16_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_22_1) & 63;
  aux_2 = (aux_2 + factor_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_83_1)
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

  switch (segment_83_2)
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
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.tail == st_2.tail);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_16_1 == cursor_16_2);
  assert(factor_22_1 == factor_22_2);
  assert(segment_83_1 == segment_83_2);
}

int fn_R001646_4613_9(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001646_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_16 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_16 > 22)
  {
    acc = ((acc + (cursor_16 * 2)) + 5) & 127;
    aux ^= cursor_16 & 15;
  }
  else
  {
    acc = ((acc - cursor_16) + 11) & 127;
    aux += 3;
  }
  int factor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_22) & 63;
  acc ^= aux;
  int segment_83 = (aux + st.buffer[1]) & 3;
  switch (segment_83)
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

void fn_R001646_4613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_54_1) & 63;
  aux_2 = (aux_2 + residue_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_66_1 = 0;
  int offset_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_66_1 = ((offset_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_66_2 = ((offset_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_66_1) & 127;
    acc_2 = (acc_2 + offset_66_2) & 127;
  }

  int damping_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_55_1 > 43)
  {
    acc_1 = ((acc_1 + (damping_55_1 * 2)) + 5) & 127;
    aux_1 ^= damping_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_55_2 > 43)
  {
    acc_2 = ((acc_2 + (damping_55_2 * 2)) + 5) & 127;
    aux_2 ^= damping_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_86_1)
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

  switch (scale_86_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_54_1 == residue_54_2);
  assert(offset_66_1 == offset_66_2);
  assert(damping_55_1 == damping_55_2);
  assert(scale_86_1 == scale_86_2);
}

int fn_R001646_4613_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_54) & 63;
  acc ^= aux;
  int offset_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_66 = ((offset_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_66) & 127;
  }

  int damping_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_55 > 43)
  {
    acc = ((acc + (damping_55 * 2)) + 5) & 127;
    aux ^= damping_55 & 15;
  }
  else
  {
    acc = ((acc - damping_55) + 11) & 127;
    aux += 3;
  }
  int scale_86 = (aux + st.buffer[1]) & 3;
  switch (scale_86)
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

void fn_R001646_4613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int coefficient_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_43_1) & 63;
  aux_2 = (aux_2 + coefficient_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_88_1 = 0;
  int weight_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_88_1 = ((weight_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_88_2 = ((weight_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_88_1) & 127;
    acc_2 = (acc_2 + weight_88_2) & 127;
  }

  int stride_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_18_1 > 48)
  {
    acc_1 = ((acc_1 + (stride_18_1 * 2)) + 5) & 127;
    aux_1 ^= stride_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_18_2 > 48)
  {
    acc_2 = ((acc_2 + (stride_18_2 * 2)) + 5) & 127;
    aux_2 ^= stride_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_83_1)
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

  switch (coefficient_83_2)
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
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_43_1 == coefficient_43_2);
  assert(weight_88_1 == weight_88_2);
  assert(stride_18_1 == stride_18_2);
  assert(coefficient_83_1 == coefficient_83_2);
}

int fn_R001646_4613_11(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int coefficient_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_43) & 63;
  acc ^= aux;
  int weight_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_88 = ((weight_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_88) & 127;
  }

  int stride_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_18 > 48)
  {
    acc = ((acc + (stride_18 * 2)) + 5) & 127;
    aux ^= stride_18 & 15;
  }
  else
  {
    acc = ((acc - stride_18) + 11) & 127;
    aux += 3;
  }
  int coefficient_83 = (aux + st.buffer[1]) & 3;
  switch (coefficient_83)
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

void fn_R001646_4613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st_1 = {0};
  struct SensorNode_R001646_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_28_1 = local_arr_1[aux_1 % 3];
  int window_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_28_2 * 2)) & 127;
  int factor_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_80_1)
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

  switch (factor_80_2)
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

  int accumulator_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_46_1 > 28)
  {
    acc_1 = ((acc_1 + (accumulator_46_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_46_2 > 28)
  {
    acc_2 = ((acc_2 + (accumulator_46_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.reading == st_2.reading);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_28_1 == window_28_2);
  assert(factor_80_1 == factor_80_2);
  assert(accumulator_46_1 == accumulator_46_2);
}

int fn_R001646_4613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001646_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int window_28 = local_arr[aux % 3];
  acc = (acc + (window_28 * 2)) & 127;
  int factor_80 = (aux + st.buffer[1]) & 3;
  switch (factor_80)
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

  int accumulator_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_46 > 28)
  {
    acc = ((acc + (accumulator_46 * 2)) + 5) & 127;
    aux ^= accumulator_46 & 15;
  }
  else
  {
    acc = ((acc - accumulator_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001646_4613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st_1 = {0};
  struct EventLog_R001646_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_65_1 = local_arr_1[aux_1 % 3];
  int margin_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_65_2 * 2)) & 127;
  int damping_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_38_1) & 63;
  aux_2 = (aux_2 + damping_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_65_1 == margin_65_2);
  assert(damping_38_1 == damping_38_2);
}

int fn_R001646_4613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int margin_65 = local_arr[aux % 3];
  acc = (acc + (margin_65 * 2)) & 127;
  int damping_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001646_4613_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st_1 = {0};
  struct EventLog_R001646_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int anchor_75_1 = 0;
  int anchor_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_75_1 = ((anchor_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_75_2 = ((anchor_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_75_1) & 127;
    acc_2 = (acc_2 + anchor_75_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_54_1) & 63;
  aux_2 = (aux_2 + segment_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_75_1 == anchor_75_2);
  assert(segment_54_1 == segment_54_2);
}

int fn_R001646_4613_14(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int anchor_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_75 = ((anchor_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_75) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001646_4613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st_1 = {0};
  struct EventLog_R001646_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_90_1)
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

  switch (bound_90_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_88_1 = local_arr_1[aux_1 % 3];
  int accumulator_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_88_2 * 2)) & 127;
  int parity_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_78_1) & 63;
  aux_2 = (aux_2 + parity_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_90_1 == bound_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_88_1 == accumulator_88_2);
  assert(parity_78_1 == parity_78_2);
}

int fn_R001646_4613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001646_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_90 = (aux + st.buffer[1]) & 3;
  switch (bound_90)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_88 = local_arr[aux % 3];
  acc = (acc + (accumulator_88 * 2)) & 127;
  int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001646_0_1;
  int sec_r001646_0_2;
  int sec_r001646_1_1;
  int sec_r001646_1_2;
  int sec_r001646_2_1;
  int sec_r001646_2_2;
  int sec_r001646_3_1;
  int sec_r001646_3_2;
  int sec_r001646_4_1;
  int sec_r001646_4_2;
  int sec_r001646_5_1;
  int sec_r001646_5_2;
  int sec_r001646_6_1;
  int sec_r001646_6_2;
  int sec_r001646_7_1;
  int sec_r001646_7_2;
  int sec_r001646_8_1;
  int sec_r001646_8_2;
  int sec_r001646_9_1;
  int sec_r001646_9_2;
  int sec_r001646_10_1;
  int sec_r001646_10_2;
  int sec_r001646_11_1;
  int sec_r001646_11_2;
  int sec_r001646_12_1;
  int sec_r001646_12_2;
  int sec_r001646_13_1;
  int sec_r001646_13_2;
  int sec_r001646_14_1;
  int sec_r001646_14_2;
  int sec_r001646_15_1;
  int sec_r001646_15_2;
  int sec_r001646_16_1;
  int sec_r001646_16_2;
  int sec_r001646_17_1;
  int sec_r001646_17_2;
  int sec_r001646_18_1;
  int sec_r001646_18_2;
  int sec_r001646_19_1;
  int sec_r001646_19_2;
  int sec_r001646_20_1;
  int sec_r001646_20_2;
  int sec_r001646_21_1;
  int sec_r001646_21_2;
  int sec_r001646_22_1;
  int sec_r001646_22_2;
  int sec_r001646_23_1;
  int sec_r001646_23_2;
  int pub_r001646_0_1;
  int pub_r001646_0_2;
  int pub_r001646_1_1;
  int pub_r001646_1_2;
  int pub_r001646_2_1;
  int pub_r001646_2_2;
  int pub_r001646_3_1;
  int pub_r001646_3_2;
  int pub_r001646_4_1;
  int pub_r001646_4_2;
  int pub_r001646_5_1;
  int pub_r001646_5_2;
  int pub_r001646_6_1;
  int pub_r001646_6_2;
  int pub_r001646_7_1;
  int pub_r001646_7_2;
  int pub_r001646_8_1;
  int pub_r001646_8_2;
  int pub_r001646_9_1;
  int pub_r001646_9_2;
  int pub_r001646_10_1;
  int pub_r001646_10_2;
  int pub_r001646_11_1;
  int pub_r001646_11_2;
  int pub_r001646_12_1;
  int pub_r001646_12_2;
  int pub_r001646_13_1;
  int pub_r001646_13_2;
  int pub_r001646_14_1;
  int pub_r001646_14_2;
  int pub_r001646_15_1;
  int pub_r001646_15_2;
  int pub_r001646_16_1;
  int pub_r001646_16_2;
  int pub_r001646_17_1;
  int pub_r001646_17_2;
  int pub_r001646_18_1;
  int pub_r001646_18_2;
  int pub_r001646_19_1;
  int pub_r001646_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001646_0_1 >= (-100)) && (pub_r001646_0_1 <= 100));
  __CPROVER_assume((pub_r001646_0_2 >= (-100)) && (pub_r001646_0_2 <= 100));
  __CPROVER_assume((pub_r001646_1_1 >= (-100)) && (pub_r001646_1_1 <= 100));
  __CPROVER_assume((pub_r001646_1_2 >= (-100)) && (pub_r001646_1_2 <= 100));
  __CPROVER_assume((pub_r001646_2_1 >= (-100)) && (pub_r001646_2_1 <= 100));
  __CPROVER_assume((pub_r001646_2_2 >= (-100)) && (pub_r001646_2_2 <= 100));
  __CPROVER_assume((pub_r001646_3_1 >= (-100)) && (pub_r001646_3_1 <= 100));
  __CPROVER_assume((pub_r001646_3_2 >= (-100)) && (pub_r001646_3_2 <= 100));
  __CPROVER_assume((pub_r001646_4_1 >= (-100)) && (pub_r001646_4_1 <= 100));
  __CPROVER_assume((pub_r001646_4_2 >= (-100)) && (pub_r001646_4_2 <= 100));
  __CPROVER_assume((pub_r001646_5_1 >= (-100)) && (pub_r001646_5_1 <= 100));
  __CPROVER_assume((pub_r001646_5_2 >= (-100)) && (pub_r001646_5_2 <= 100));
  __CPROVER_assume((pub_r001646_6_1 >= (-100)) && (pub_r001646_6_1 <= 100));
  __CPROVER_assume((pub_r001646_6_2 >= (-100)) && (pub_r001646_6_2 <= 100));
  __CPROVER_assume((pub_r001646_7_1 >= (-100)) && (pub_r001646_7_1 <= 100));
  __CPROVER_assume((pub_r001646_7_2 >= (-100)) && (pub_r001646_7_2 <= 100));
  __CPROVER_assume((pub_r001646_8_1 >= (-100)) && (pub_r001646_8_1 <= 100));
  __CPROVER_assume((pub_r001646_8_2 >= (-100)) && (pub_r001646_8_2 <= 100));
  __CPROVER_assume((pub_r001646_9_1 >= (-100)) && (pub_r001646_9_1 <= 100));
  __CPROVER_assume((pub_r001646_9_2 >= (-100)) && (pub_r001646_9_2 <= 100));
  __CPROVER_assume((pub_r001646_10_1 >= (-100)) && (pub_r001646_10_1 <= 100));
  __CPROVER_assume((pub_r001646_10_2 >= (-100)) && (pub_r001646_10_2 <= 100));
  __CPROVER_assume((pub_r001646_11_1 >= (-100)) && (pub_r001646_11_1 <= 100));
  __CPROVER_assume((pub_r001646_11_2 >= (-100)) && (pub_r001646_11_2 <= 100));
  __CPROVER_assume((pub_r001646_12_1 >= (-100)) && (pub_r001646_12_1 <= 100));
  __CPROVER_assume((pub_r001646_12_2 >= (-100)) && (pub_r001646_12_2 <= 100));
  __CPROVER_assume((pub_r001646_13_1 >= (-100)) && (pub_r001646_13_1 <= 100));
  __CPROVER_assume((pub_r001646_13_2 >= (-100)) && (pub_r001646_13_2 <= 100));
  __CPROVER_assume((pub_r001646_14_1 >= (-100)) && (pub_r001646_14_1 <= 100));
  __CPROVER_assume((pub_r001646_14_2 >= (-100)) && (pub_r001646_14_2 <= 100));
  __CPROVER_assume((pub_r001646_15_1 >= (-100)) && (pub_r001646_15_1 <= 100));
  __CPROVER_assume((pub_r001646_15_2 >= (-100)) && (pub_r001646_15_2 <= 100));
  __CPROVER_assume((pub_r001646_16_1 >= (-100)) && (pub_r001646_16_1 <= 100));
  __CPROVER_assume((pub_r001646_16_2 >= (-100)) && (pub_r001646_16_2 <= 100));
  __CPROVER_assume((pub_r001646_17_1 >= (-100)) && (pub_r001646_17_1 <= 100));
  __CPROVER_assume((pub_r001646_17_2 >= (-100)) && (pub_r001646_17_2 <= 100));
  __CPROVER_assume((pub_r001646_18_1 >= (-100)) && (pub_r001646_18_1 <= 100));
  __CPROVER_assume((pub_r001646_18_2 >= (-100)) && (pub_r001646_18_2 <= 100));
  __CPROVER_assume((pub_r001646_19_1 >= (-100)) && (pub_r001646_19_1 <= 100));
  __CPROVER_assume((pub_r001646_19_2 >= (-100)) && (pub_r001646_19_2 <= 100));
  __CPROVER_assume((sec_r001646_0_1 >= 0) && (sec_r001646_0_1 <= 255));
  __CPROVER_assume((sec_r001646_0_2 >= 0) && (sec_r001646_0_2 <= 255));
  __CPROVER_assume((sec_r001646_1_1 >= 0) && (sec_r001646_1_1 <= 255));
  __CPROVER_assume((sec_r001646_1_2 >= 0) && (sec_r001646_1_2 <= 255));
  __CPROVER_assume((sec_r001646_2_1 >= 0) && (sec_r001646_2_1 <= 255));
  __CPROVER_assume((sec_r001646_2_2 >= 0) && (sec_r001646_2_2 <= 255));
  __CPROVER_assume((sec_r001646_3_1 >= 0) && (sec_r001646_3_1 <= 255));
  __CPROVER_assume((sec_r001646_3_2 >= 0) && (sec_r001646_3_2 <= 255));
  __CPROVER_assume((sec_r001646_4_1 >= 0) && (sec_r001646_4_1 <= 255));
  __CPROVER_assume((sec_r001646_4_2 >= 0) && (sec_r001646_4_2 <= 255));
  __CPROVER_assume((sec_r001646_5_1 >= 0) && (sec_r001646_5_1 <= 255));
  __CPROVER_assume((sec_r001646_5_2 >= 0) && (sec_r001646_5_2 <= 255));
  __CPROVER_assume((sec_r001646_6_1 >= 0) && (sec_r001646_6_1 <= 255));
  __CPROVER_assume((sec_r001646_6_2 >= 0) && (sec_r001646_6_2 <= 255));
  __CPROVER_assume((sec_r001646_7_1 >= 0) && (sec_r001646_7_1 <= 255));
  __CPROVER_assume((sec_r001646_7_2 >= 0) && (sec_r001646_7_2 <= 255));
  __CPROVER_assume((sec_r001646_8_1 >= 0) && (sec_r001646_8_1 <= 255));
  __CPROVER_assume((sec_r001646_8_2 >= 0) && (sec_r001646_8_2 <= 255));
  __CPROVER_assume((sec_r001646_9_1 >= 0) && (sec_r001646_9_1 <= 255));
  __CPROVER_assume((sec_r001646_9_2 >= 0) && (sec_r001646_9_2 <= 255));
  __CPROVER_assume((sec_r001646_10_1 >= 0) && (sec_r001646_10_1 <= 255));
  __CPROVER_assume((sec_r001646_10_2 >= 0) && (sec_r001646_10_2 <= 255));
  __CPROVER_assume((sec_r001646_11_1 >= 0) && (sec_r001646_11_1 <= 255));
  __CPROVER_assume((sec_r001646_11_2 >= 0) && (sec_r001646_11_2 <= 255));
  __CPROVER_assume((sec_r001646_12_1 >= 0) && (sec_r001646_12_1 <= 255));
  __CPROVER_assume((sec_r001646_12_2 >= 0) && (sec_r001646_12_2 <= 255));
  __CPROVER_assume((sec_r001646_13_1 >= 0) && (sec_r001646_13_1 <= 255));
  __CPROVER_assume((sec_r001646_13_2 >= 0) && (sec_r001646_13_2 <= 255));
  __CPROVER_assume((sec_r001646_14_1 >= 0) && (sec_r001646_14_1 <= 255));
  __CPROVER_assume((sec_r001646_14_2 >= 0) && (sec_r001646_14_2 <= 255));
  __CPROVER_assume((sec_r001646_15_1 >= 0) && (sec_r001646_15_1 <= 255));
  __CPROVER_assume((sec_r001646_15_2 >= 0) && (sec_r001646_15_2 <= 255));
  __CPROVER_assume((sec_r001646_16_1 >= 0) && (sec_r001646_16_1 <= 255));
  __CPROVER_assume((sec_r001646_16_2 >= 0) && (sec_r001646_16_2 <= 255));
  __CPROVER_assume((sec_r001646_17_1 >= 0) && (sec_r001646_17_1 <= 255));
  __CPROVER_assume((sec_r001646_17_2 >= 0) && (sec_r001646_17_2 <= 255));
  __CPROVER_assume((sec_r001646_18_1 >= 0) && (sec_r001646_18_1 <= 255));
  __CPROVER_assume((sec_r001646_18_2 >= 0) && (sec_r001646_18_2 <= 255));
  __CPROVER_assume((sec_r001646_19_1 >= 0) && (sec_r001646_19_1 <= 255));
  __CPROVER_assume((sec_r001646_19_2 >= 0) && (sec_r001646_19_2 <= 255));
  __CPROVER_assume((sec_r001646_20_1 >= 0) && (sec_r001646_20_1 <= 255));
  __CPROVER_assume((sec_r001646_20_2 >= 0) && (sec_r001646_20_2 <= 255));
  __CPROVER_assume((sec_r001646_21_1 >= 0) && (sec_r001646_21_1 <= 255));
  __CPROVER_assume((sec_r001646_21_2 >= 0) && (sec_r001646_21_2 <= 255));
  __CPROVER_assume((sec_r001646_22_1 >= 0) && (sec_r001646_22_1 <= 255));
  __CPROVER_assume((sec_r001646_22_2 >= 0) && (sec_r001646_22_2 <= 255));
  __CPROVER_assume((sec_r001646_23_1 >= 0) && (sec_r001646_23_1 <= 255));
  __CPROVER_assume((sec_r001646_23_2 >= 0) && (sec_r001646_23_2 <= 255));
  struct SensorNode_R001646_4613_0 st_var_0_1 = {0};
  struct SensorNode_R001646_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001646_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001646_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001646_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001646_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001646_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001646_0_2 + 7) & 15;
  struct StreamBuffer_R001646_4613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001646_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001646_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001646_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001646_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001646_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001646_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001646_0_2 + 9) & 15;
  struct EventLog_R001646_4613_2 st_var_2_1 = {0};
  struct EventLog_R001646_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001646_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001646_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001646_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001646_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001646_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001646_0_2 + 11) & 15;
  union TelemetryField_R001646_4613_0 u_var_1;
  union TelemetryField_R001646_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001646_4613_0(sec_r001646_0_1, pub_r001646_1_1, pub_r001646_2_1, pub_r001646_3_1);
  int helper_flow_0_2 = fn_R001646_4613_0(sec_r001646_0_2, pub_r001646_1_2, pub_r001646_2_2, pub_r001646_3_2);
  fn_R001646_4613_0_2(sec_r001646_0_1, pub_r001646_1_1, pub_r001646_2_1, pub_r001646_3_1, sec_r001646_0_2, pub_r001646_1_2, pub_r001646_2_2, pub_r001646_3_2);
  int helper_flow_1_1 = fn_R001646_4613_1(sec_r001646_1_1, sec_r001646_2_1, pub_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1);
  int helper_flow_1_2 = fn_R001646_4613_1(sec_r001646_1_2, sec_r001646_2_2, pub_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2);
  fn_R001646_4613_1_2(sec_r001646_1_1, sec_r001646_2_1, pub_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1, sec_r001646_1_2, sec_r001646_2_2, pub_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2);
  int helper_flow_2_1 = fn_R001646_4613_2(sec_r001646_2_1, sec_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1, pub_r001646_6_1);
  int helper_flow_2_2 = fn_R001646_4613_2(sec_r001646_2_2, sec_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2, pub_r001646_6_2);
  fn_R001646_4613_2_2(sec_r001646_2_1, sec_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1, pub_r001646_6_1, sec_r001646_2_2, sec_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2, pub_r001646_6_2);
  int helper_flow_3_1 = fn_R001646_4613_3(sec_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1, pub_r001646_6_1, pub_r001646_7_1);
  int helper_flow_3_2 = fn_R001646_4613_3(sec_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2, pub_r001646_6_2, pub_r001646_7_2);
  fn_R001646_4613_3_2(sec_r001646_3_1, pub_r001646_4_1, pub_r001646_5_1, pub_r001646_6_1, pub_r001646_7_1, sec_r001646_3_2, pub_r001646_4_2, pub_r001646_5_2, pub_r001646_6_2, pub_r001646_7_2);
  int helper_flow_4_1 = fn_R001646_4613_4(sec_r001646_4_1, sec_r001646_5_1);
  int helper_flow_4_2 = fn_R001646_4613_4(sec_r001646_4_2, sec_r001646_5_2);
  fn_R001646_4613_4_2(sec_r001646_4_1, sec_r001646_5_1, sec_r001646_4_2, sec_r001646_5_2);
  int helper_flow_5_1 = fn_R001646_4613_5(sec_r001646_5_1, pub_r001646_6_1);
  int helper_flow_5_2 = fn_R001646_4613_5(sec_r001646_5_2, pub_r001646_6_2);
  fn_R001646_4613_5_2(sec_r001646_5_1, pub_r001646_6_1, sec_r001646_5_2, pub_r001646_6_2);
  int helper_flow_6_1 = fn_R001646_4613_6(sec_r001646_6_1, pub_r001646_7_1, pub_r001646_8_1, pub_r001646_9_1, pub_r001646_10_1);
  int helper_flow_6_2 = fn_R001646_4613_6(sec_r001646_6_2, pub_r001646_7_2, pub_r001646_8_2, pub_r001646_9_2, pub_r001646_10_2);
  fn_R001646_4613_6_2(sec_r001646_6_1, pub_r001646_7_1, pub_r001646_8_1, pub_r001646_9_1, pub_r001646_10_1, sec_r001646_6_2, pub_r001646_7_2, pub_r001646_8_2, pub_r001646_9_2, pub_r001646_10_2);
  int helper_flow_7_1 = fn_R001646_4613_7(sec_r001646_7_1, pub_r001646_8_1);
  int helper_flow_7_2 = fn_R001646_4613_7(sec_r001646_7_2, pub_r001646_8_2);
  fn_R001646_4613_7_2(sec_r001646_7_1, pub_r001646_8_1, sec_r001646_7_2, pub_r001646_8_2);
  int helper_flow_8_1 = fn_R001646_4613_8(sec_r001646_8_1, pub_r001646_9_1);
  int helper_flow_8_2 = fn_R001646_4613_8(sec_r001646_8_2, pub_r001646_9_2);
  fn_R001646_4613_8_2(sec_r001646_8_1, pub_r001646_9_1, sec_r001646_8_2, pub_r001646_9_2);
  int helper_flow_9_1 = fn_R001646_4613_9(sec_r001646_9_1, sec_r001646_10_1, pub_r001646_11_1);
  int helper_flow_9_2 = fn_R001646_4613_9(sec_r001646_9_2, sec_r001646_10_2, pub_r001646_11_2);
  fn_R001646_4613_9_2(sec_r001646_9_1, sec_r001646_10_1, pub_r001646_11_1, sec_r001646_9_2, sec_r001646_10_2, pub_r001646_11_2);
  int helper_flow_10_1 = fn_R001646_4613_10(sec_r001646_10_1, sec_r001646_11_1, pub_r001646_12_1, pub_r001646_13_1, pub_r001646_14_1);
  int helper_flow_10_2 = fn_R001646_4613_10(sec_r001646_10_2, sec_r001646_11_2, pub_r001646_12_2, pub_r001646_13_2, pub_r001646_14_2);
  fn_R001646_4613_10_2(sec_r001646_10_1, sec_r001646_11_1, pub_r001646_12_1, pub_r001646_13_1, pub_r001646_14_1, sec_r001646_10_2, sec_r001646_11_2, pub_r001646_12_2, pub_r001646_13_2, pub_r001646_14_2);
  int stage_v_0_1 = ((sec_r001646_9_1 + (pub_r001646_17_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001646_9_2 + (pub_r001646_17_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((helper_flow_9_1 + (pub_r001646_12_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((helper_flow_9_2 + (pub_r001646_12_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((helper_flow_0_1 + (pub_r001646_15_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_0_2 + (pub_r001646_15_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001646_8_1 * 2) + 22) & 63;
  int stage_v_3_2 = ((pub_r001646_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((helper_flow_0_1 + (pub_r001646_8_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((helper_flow_0_2 + (pub_r001646_8_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001646_3_1 + (pub_r001646_18_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001646_3_2 + (pub_r001646_18_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001646_19_1 + (pub_r001646_7_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001646_19_2 + (pub_r001646_7_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((stage_v_6_1 + (pub_r001646_19_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((stage_v_6_2 + (pub_r001646_19_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001646_14_1 * 2) + 11) & 63;
  int stage_v_8_2 = ((pub_r001646_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((stage_v_0_1 + (pub_r001646_13_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_0_2 + (pub_r001646_13_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((helper_flow_1_1 + (pub_r001646_13_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_1_2 + (pub_r001646_13_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((pub_r001646_8_1 * 2) + 12) & 63;
  int stage_v_11_2 = ((pub_r001646_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((sec_r001646_11_1 + (pub_r001646_1_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001646_11_2 + (pub_r001646_1_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((helper_flow_3_1 + (pub_r001646_8_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((helper_flow_3_2 + (pub_r001646_8_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((stage_v_13_1 + (pub_r001646_0_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((stage_v_13_2 + (pub_r001646_0_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_9_1 + (pub_r001646_9_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_9_2 + (pub_r001646_9_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_7_1 + (pub_r001646_3_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_7_2 + (pub_r001646_3_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001646_21_1 + (pub_r001646_0_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001646_21_2 + (pub_r001646_0_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001646_13_1 + (pub_r001646_14_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001646_13_2 + (pub_r001646_14_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001646_15_1 * 2) + 34) & 63;
  int stage_v_19_2 = ((pub_r001646_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_12_1 + (pub_r001646_0_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_12_2 + (pub_r001646_0_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001646_22_1 + (pub_r001646_17_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001646_22_2 + (pub_r001646_17_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001646_2_1 * 2) + 17) & 63;
  int stage_v_22_2 = ((pub_r001646_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001646_4_1 * 2) + 5) & 63;
  int stage_v_23_2 = ((pub_r001646_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001646_4_1 * 2) + 47) & 63;
  int stage_v_24_2 = ((pub_r001646_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((sec_r001646_22_1 + (pub_r001646_19_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((sec_r001646_22_2 + (pub_r001646_19_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((stage_v_0_1 + (pub_r001646_11_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_0_2 + (pub_r001646_11_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_18_1 + (pub_r001646_0_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_18_2 + (pub_r001646_0_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((stage_v_18_1 + (pub_r001646_2_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_18_2 + (pub_r001646_2_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((stage_v_16_1 + (pub_r001646_1_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((stage_v_16_2 + (pub_r001646_1_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((pub_r001646_19_1 * 2) + 6) & 63;
  int stage_v_30_2 = ((pub_r001646_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_5_1 + (pub_r001646_3_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_5_2 + (pub_r001646_3_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001646_15_1 * 2) + 16) & 63;
  int stage_v_32_2 = ((pub_r001646_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((stage_v_9_1 + (pub_r001646_11_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((stage_v_9_2 + (pub_r001646_11_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001646_11_1 * 2) + 23) & 63;
  int stage_v_34_2 = ((pub_r001646_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((stage_v_26_1 + (pub_r001646_17_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_26_2 + (pub_r001646_17_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((stage_v_17_1 + (pub_r001646_0_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_17_2 + (pub_r001646_0_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((sec_r001646_2_1 + (pub_r001646_1_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((sec_r001646_2_2 + (pub_r001646_1_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001646_4_1 * 2) + 11) & 63;
  int stage_v_38_2 = ((pub_r001646_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((stage_v_35_1 + (pub_r001646_11_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((stage_v_35_2 + (pub_r001646_11_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_18_1 + (pub_r001646_16_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_18_2 + (pub_r001646_16_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001646_6_1 * 2) + 42) & 63;
  int stage_v_41_2 = ((pub_r001646_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((sec_r001646_20_1 + (pub_r001646_7_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001646_20_2 + (pub_r001646_7_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((stage_v_17_1 + (pub_r001646_0_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_17_2 + (pub_r001646_0_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001646_2_1 + (pub_r001646_14_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001646_2_2 + (pub_r001646_14_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((sec_r001646_8_1 + (pub_r001646_1_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001646_8_2 + (pub_r001646_1_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((sec_r001646_18_1 + (pub_r001646_8_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001646_18_2 + (pub_r001646_8_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((pub_r001646_5_1 * 2) + 25) & 63;
  int stage_v_47_2 = ((pub_r001646_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((helper_flow_0_1 + (pub_r001646_15_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((helper_flow_0_2 + (pub_r001646_15_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_35_1 + (pub_r001646_7_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_35_2 + (pub_r001646_7_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_28_1 + (pub_r001646_1_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_28_2 + (pub_r001646_1_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((sec_r001646_9_1 + (pub_r001646_18_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((sec_r001646_9_2 + (pub_r001646_18_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((stage_v_7_1 + (pub_r001646_13_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_7_2 + (pub_r001646_13_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_20_1 + (pub_r001646_2_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_20_2 + (pub_r001646_2_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((sec_r001646_9_1 + (pub_r001646_6_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001646_9_2 + (pub_r001646_6_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_36_1 + (pub_r001646_14_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_36_2 + (pub_r001646_14_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((sec_r001646_22_1 + (pub_r001646_6_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((sec_r001646_22_2 + (pub_r001646_6_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((stage_v_37_1 + (pub_r001646_6_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_37_2 + (pub_r001646_6_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_51_1 + (pub_r001646_13_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_51_2 + (pub_r001646_13_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_12_1 + (pub_r001646_13_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_12_2 + (pub_r001646_13_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((stage_v_49_1 + (pub_r001646_11_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((stage_v_49_2 + (pub_r001646_11_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001646_6_1 * 2) + 10) & 63;
  int stage_v_61_2 = ((pub_r001646_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_52_1 + (pub_r001646_0_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_52_2 + (pub_r001646_0_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_60_1 + (pub_r001646_6_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_60_2 + (pub_r001646_6_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_16_1 + (pub_r001646_3_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_16_2 + (pub_r001646_3_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_9_1 + (pub_r001646_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_9_2 + (pub_r001646_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001646_7_1 * 2) + 14) & 63;
  int stage_v_66_2 = ((pub_r001646_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((helper_flow_4_1 + (pub_r001646_5_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((helper_flow_4_2 + (pub_r001646_5_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((sec_r001646_10_1 + (pub_r001646_7_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((sec_r001646_10_2 + (pub_r001646_7_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((stage_v_0_1 + (pub_r001646_2_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((stage_v_0_2 + (pub_r001646_2_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_6_1 + (pub_r001646_3_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_6_2 + (pub_r001646_3_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001646_11_1 + (pub_r001646_2_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001646_11_2 + (pub_r001646_2_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((pub_r001646_0_1 * 2) + 5) & 63;
  int stage_v_72_2 = ((pub_r001646_0_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001646_11_1 * 2) + 35) & 63;
  int stage_v_73_2 = ((pub_r001646_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001646_9_1 * 2) + 7) & 63;
  int stage_v_74_2 = ((pub_r001646_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_51_1 + (pub_r001646_10_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_51_2 + (pub_r001646_10_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((sec_r001646_13_1 + (pub_r001646_18_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001646_13_2 + (pub_r001646_18_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_7_1 + (pub_r001646_17_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_7_2 + (pub_r001646_17_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((helper_flow_2_1 + (pub_r001646_11_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((helper_flow_2_2 + (pub_r001646_11_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((pub_r001646_0_1 * 2) + 14) & 63;
  int stage_v_79_2 = ((pub_r001646_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((stage_v_0_1 + (pub_r001646_3_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_0_2 + (pub_r001646_3_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001646_9_1 * 2) + 47) & 63;
  int stage_v_81_2 = ((pub_r001646_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001646_9_1 * 2) + 24) & 63;
  int stage_v_82_2 = ((pub_r001646_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((stage_v_55_1 + (pub_r001646_4_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((stage_v_55_2 + (pub_r001646_4_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((sec_r001646_4_1 + (pub_r001646_10_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((sec_r001646_4_2 + (pub_r001646_10_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001646_15_1 * 2) + 44) & 63;
  int stage_v_85_2 = ((pub_r001646_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_26_1 + (pub_r001646_16_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_26_2 + (pub_r001646_16_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_65_1 + (pub_r001646_3_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_65_2 + (pub_r001646_3_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((sec_r001646_6_1 + (pub_r001646_11_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((sec_r001646_6_2 + (pub_r001646_11_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((sec_r001646_0_1 + (pub_r001646_2_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((sec_r001646_0_2 + (pub_r001646_2_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((helper_flow_7_1 + (pub_r001646_0_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((helper_flow_7_2 + (pub_r001646_0_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((sec_r001646_15_1 + (pub_r001646_16_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001646_15_2 + (pub_r001646_16_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_36_1 + (pub_r001646_3_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_36_2 + (pub_r001646_3_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((sec_r001646_13_1 + (pub_r001646_15_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((sec_r001646_13_2 + (pub_r001646_15_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_56_1 + (pub_r001646_6_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_56_2 + (pub_r001646_6_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_91_1 + (pub_r001646_4_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_91_2 + (pub_r001646_4_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001646_3_1 + (pub_r001646_0_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001646_3_2 + (pub_r001646_0_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((pub_r001646_17_1 * 2) + 21) & 63;
  int stage_v_97_2 = ((pub_r001646_17_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_50_1 + (pub_r001646_6_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_50_2 + (pub_r001646_6_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001646_14_1 * 2) + 47) & 63;
  int stage_v_99_2 = ((pub_r001646_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_20_1 + (pub_r001646_7_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((stage_v_20_2 + (pub_r001646_7_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((stage_v_98_1 + (pub_r001646_2_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_98_2 + (pub_r001646_2_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001646_4_1 * 2) + 35) & 63;
  int stage_v_102_2 = ((pub_r001646_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((sec_r001646_19_1 + (pub_r001646_16_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001646_19_2 + (pub_r001646_16_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001646_15_1 * 2) + 33) & 63;
  int stage_v_104_2 = ((pub_r001646_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_68_1 + (pub_r001646_0_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_68_2 + (pub_r001646_0_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001646_13_1 * 2) + 27) & 63;
  int stage_v_106_2 = ((pub_r001646_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_101_1 + (pub_r001646_9_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_101_2 + (pub_r001646_9_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((stage_v_80_1 + (pub_r001646_16_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_80_2 + (pub_r001646_16_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_98_1 + (pub_r001646_7_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_98_2 + (pub_r001646_7_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001646_3_1 * 2) + 35) & 63;
  int stage_v_110_2 = ((pub_r001646_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_10_1 + (pub_r001646_16_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_10_2 + (pub_r001646_16_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((sec_r001646_14_1 + (pub_r001646_14_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((sec_r001646_14_2 + (pub_r001646_14_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((stage_v_100_1 + (pub_r001646_18_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_100_2 + (pub_r001646_18_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((sec_r001646_3_1 + (pub_r001646_17_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((sec_r001646_3_2 + (pub_r001646_17_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((helper_flow_1_1 + (pub_r001646_12_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((helper_flow_1_2 + (pub_r001646_12_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((sec_r001646_22_1 + (pub_r001646_5_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001646_22_2 + (pub_r001646_5_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001646_16_1 * 2) + 43) & 63;
  int stage_v_117_2 = ((pub_r001646_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_33_1 + (pub_r001646_15_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_33_2 + (pub_r001646_15_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_69_1 + (pub_r001646_3_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_69_2 + (pub_r001646_3_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001646_23_1 + (pub_r001646_1_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001646_23_2 + (pub_r001646_1_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_111_1 + (pub_r001646_3_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_111_2 + (pub_r001646_3_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_26_1 + (pub_r001646_14_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_26_2 + (pub_r001646_14_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_113_1 + (pub_r001646_13_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_113_2 + (pub_r001646_13_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((sec_r001646_21_1 + (pub_r001646_9_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((sec_r001646_21_2 + (pub_r001646_9_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((pub_r001646_3_1 * 2) + 17) & 63;
  int stage_v_125_2 = ((pub_r001646_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_86_1 + (pub_r001646_8_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_86_2 + (pub_r001646_8_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_60_1 + (pub_r001646_3_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_60_2 + (pub_r001646_3_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001646_2_1 * 2) + 39) & 63;
  int stage_v_128_2 = ((pub_r001646_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((sec_r001646_12_1 + (pub_r001646_6_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((sec_r001646_12_2 + (pub_r001646_6_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_0_1 + (pub_r001646_1_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_0_2 + (pub_r001646_1_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001646_9_1 * 2) + 9) & 63;
  int stage_v_131_2 = ((pub_r001646_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_25_1 + (pub_r001646_8_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_25_2 + (pub_r001646_8_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001646_9_1 * 2) + 30) & 63;
  int stage_v_133_2 = ((pub_r001646_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_9_1 + (pub_r001646_11_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_9_2 + (pub_r001646_11_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((stage_v_91_1 + (pub_r001646_16_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((stage_v_91_2 + (pub_r001646_16_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_93_1 + (pub_r001646_18_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_93_2 + (pub_r001646_18_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001646_18_1 * 2) + 37) & 63;
  int stage_v_137_2 = ((pub_r001646_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001646_0_1 * 2) + 25) & 63;
  int stage_v_138_2 = ((pub_r001646_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((sec_r001646_23_1 + (pub_r001646_8_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((sec_r001646_23_2 + (pub_r001646_8_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((pub_r001646_12_1 * 2) + 24) & 63;
  int stage_v_140_2 = ((pub_r001646_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001646_15_1 * 2) + 15) & 63;
  int stage_v_141_2 = ((pub_r001646_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001646_13_1 * 2) + 37) & 63;
  int stage_v_142_2 = ((pub_r001646_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((sec_r001646_0_1 + (pub_r001646_16_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((sec_r001646_0_2 + (pub_r001646_16_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001646_4_1 * 2) + 23) & 63;
  int stage_v_144_2 = ((pub_r001646_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_124_1 + (pub_r001646_4_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_124_2 + (pub_r001646_4_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_109_1 + (pub_r001646_17_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_109_2 + (pub_r001646_17_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((sec_r001646_1_1 + (pub_r001646_10_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((sec_r001646_1_2 + (pub_r001646_10_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_123_1 + (pub_r001646_3_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_123_2 + (pub_r001646_3_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((sec_r001646_6_1 + (pub_r001646_2_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((sec_r001646_6_2 + (pub_r001646_2_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_145_1 + (pub_r001646_9_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_145_2 + (pub_r001646_9_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001646_9_1 * 2) + 42) & 63;
  int stage_v_151_2 = ((pub_r001646_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_124_1 + (pub_r001646_3_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_124_2 + (pub_r001646_3_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((stage_v_13_1 + (pub_r001646_0_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_13_2 + (pub_r001646_0_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_145_1 + (pub_r001646_14_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_145_2 + (pub_r001646_14_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_77_1 + (pub_r001646_14_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_77_2 + (pub_r001646_14_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001646_7_1 * 2) + 11) & 63;
  int stage_v_156_2 = ((pub_r001646_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_57_1 + (pub_r001646_11_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_57_2 + (pub_r001646_11_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((pub_r001646_15_1 * 2) + 36) & 63;
  int stage_v_158_2 = ((pub_r001646_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001646_0_1 * 2) + 9) & 63;
  int stage_v_159_2 = ((pub_r001646_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((stage_v_116_1 + (pub_r001646_15_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_116_2 + (pub_r001646_15_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001646_11_1 * 2) + 41) & 63;
  int stage_v_161_2 = ((pub_r001646_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001646_19_1 * 2) + 39) & 63;
  int stage_v_162_2 = ((pub_r001646_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001646_3_1 * 2) + 45) & 63;
  int stage_v_163_2 = ((pub_r001646_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001646_14_1 * 2) + 39) & 63;
  int stage_v_164_2 = ((pub_r001646_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((helper_flow_2_1 + (pub_r001646_12_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((helper_flow_2_2 + (pub_r001646_12_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_114_1 + (pub_r001646_12_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_114_2 + (pub_r001646_12_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((stage_v_121_1 + (pub_r001646_4_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((stage_v_121_2 + (pub_r001646_4_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((stage_v_107_1 + (pub_r001646_11_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_107_2 + (pub_r001646_11_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((pub_r001646_1_1 * 2) + 18) & 63;
  int stage_v_169_2 = ((pub_r001646_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001646_3_1 * 2) + 35) & 63;
  int stage_v_170_2 = ((pub_r001646_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001646_17_1 * 2) + 41) & 63;
  int stage_v_171_2 = ((pub_r001646_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_103_1 + (pub_r001646_3_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_103_2 + (pub_r001646_3_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_71_1 + (pub_r001646_19_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_71_2 + (pub_r001646_19_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_130_1 + (pub_r001646_8_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_130_2 + (pub_r001646_8_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_7_1 + (pub_r001646_4_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_7_2 + (pub_r001646_4_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001646_4_1 * 2) + 40) & 63;
  int stage_v_176_2 = ((pub_r001646_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((stage_v_63_1 + (pub_r001646_11_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_63_2 + (pub_r001646_11_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001646_19_1 * 2) + 40) & 63;
  int stage_v_178_2 = ((pub_r001646_19_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001646_14_1 * 2) + 49) & 63;
  int stage_v_179_2 = ((pub_r001646_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((stage_v_126_1 + (pub_r001646_0_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_126_2 + (pub_r001646_0_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((stage_v_48_1 + (pub_r001646_2_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_48_2 + (pub_r001646_2_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((stage_v_145_1 + (pub_r001646_11_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_145_2 + (pub_r001646_11_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((pub_r001646_4_1 * 2) + 13) & 63;
  int stage_v_183_2 = ((pub_r001646_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_15_1 + (pub_r001646_19_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_15_2 + (pub_r001646_19_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001646_6_1 * 2) + 24) & 63;
  int stage_v_185_2 = ((pub_r001646_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_153_1 + (pub_r001646_19_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_153_2 + (pub_r001646_19_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001646_18_1 * 2) + 43) & 63;
  int stage_v_187_2 = ((pub_r001646_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((stage_v_15_1 + (pub_r001646_19_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_15_2 + (pub_r001646_19_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_27_1 + (pub_r001646_8_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_27_2 + (pub_r001646_8_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((stage_v_13_1 + (pub_r001646_7_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_13_2 + (pub_r001646_7_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001646_12_1 * 2) + 21) & 63;
  int stage_v_191_2 = ((pub_r001646_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_120_1 + (pub_r001646_0_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_120_2 + (pub_r001646_0_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_127_1 + (pub_r001646_0_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_127_2 + (pub_r001646_0_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_4_1 + (pub_r001646_19_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_4_2 + (pub_r001646_19_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001646_17_1 * 2) + 40) & 63;
  int stage_v_195_2 = ((pub_r001646_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_146_1 + (pub_r001646_1_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_146_2 + (pub_r001646_1_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_114_1 + (pub_r001646_10_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_114_2 + (pub_r001646_10_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_167_1 + (pub_r001646_0_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_167_2 + (pub_r001646_0_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((pub_r001646_1_1 * 2) + 23) & 63;
  int stage_v_199_2 = ((pub_r001646_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001646_10_1 * 2) + 34) & 63;
  int stage_v_200_2 = ((pub_r001646_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001646_10_1 * 2) + 15) & 63;
  int stage_v_201_2 = ((pub_r001646_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((stage_v_31_1 + (pub_r001646_3_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_31_2 + (pub_r001646_3_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((sec_r001646_9_1 + (pub_r001646_14_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((sec_r001646_9_2 + (pub_r001646_14_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_46_1 + (pub_r001646_14_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_46_2 + (pub_r001646_14_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_194_1 + (pub_r001646_19_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_194_2 + (pub_r001646_19_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((pub_r001646_0_1 * 2) + 32) & 63;
  int stage_v_206_2 = ((pub_r001646_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_70_1 + (pub_r001646_16_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_70_2 + (pub_r001646_16_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((pub_r001646_0_1 * 2) + 21) & 63;
  int stage_v_208_2 = ((pub_r001646_0_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((stage_v_53_1 + (pub_r001646_11_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_53_2 + (pub_r001646_11_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_198_1 + (pub_r001646_0_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_198_2 + (pub_r001646_0_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((pub_r001646_2_1 * 2) + 17) & 63;
  int stage_v_211_2 = ((pub_r001646_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_12_1 + (pub_r001646_17_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_12_2 + (pub_r001646_17_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((stage_v_1_1 + (pub_r001646_18_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_1_2 + (pub_r001646_18_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((pub_r001646_4_1 * 2) + 9) & 63;
  int stage_v_214_2 = ((pub_r001646_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((stage_v_76_1 + (pub_r001646_17_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_76_2 + (pub_r001646_17_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001646_13_1 * 2) + 24) & 63;
  int stage_v_216_2 = ((pub_r001646_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001646_14_1 * 2) + 44) & 63;
  int stage_v_217_2 = ((pub_r001646_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001646_1_1 * 2) + 48) & 63;
  int stage_v_218_2 = ((pub_r001646_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_49_1 + (pub_r001646_10_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_49_2 + (pub_r001646_10_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_129_1 + (pub_r001646_18_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_129_2 + (pub_r001646_18_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((sec_r001646_17_1 + (pub_r001646_18_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((sec_r001646_17_2 + (pub_r001646_18_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((sec_r001646_17_1 + (pub_r001646_8_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((sec_r001646_17_2 + (pub_r001646_8_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((pub_r001646_19_1 * 2) + 7) & 63;
  int stage_v_223_2 = ((pub_r001646_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((sec_r001646_0_1 + (pub_r001646_14_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((sec_r001646_0_2 + (pub_r001646_14_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_202_1 + (pub_r001646_18_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_202_2 + (pub_r001646_18_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001646_12_1 * 2) + 5) & 63;
  int stage_v_226_2 = ((pub_r001646_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_14_1 + (pub_r001646_11_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_14_2 + (pub_r001646_11_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001646_7_1 == pub_r001646_7_2);
  __CPROVER_assume(pub_r001646_8_1 == pub_r001646_8_2);
  __CPROVER_assume(pub_r001646_13_1 == pub_r001646_13_2);
  __CPROVER_assume(pub_r001646_4_1 == pub_r001646_4_2);
  __CPROVER_assume(pub_r001646_9_1 == pub_r001646_9_2);
  __CPROVER_assume(sec_r001646_2_1 != sec_r001646_2_2);
  __CPROVER_assume(sec_r001646_23_1 != sec_r001646_23_2);
  __CPROVER_assume(sec_r001646_13_1 != sec_r001646_13_2);
  __CPROVER_assume(pub_r001646_2_1 == pub_r001646_2_2);
  __CPROVER_assume(pub_r001646_1_1 == pub_r001646_1_2);
  __CPROVER_assume(pub_r001646_6_1 == pub_r001646_6_2);
  __CPROVER_assume(pub_r001646_5_1 == pub_r001646_5_2);
  __CPROVER_assume(sec_r001646_4_1 != sec_r001646_4_2);
  __CPROVER_assume(pub_r001646_12_1 == pub_r001646_12_2);
  __CPROVER_assume(pub_r001646_19_1 == pub_r001646_19_2);
  __CPROVER_assume(pub_r001646_14_1 == pub_r001646_14_2);
  __CPROVER_assume(pub_r001646_16_1 == pub_r001646_16_2);
  __CPROVER_assume(sec_r001646_9_1 != sec_r001646_9_2);
  __CPROVER_assume(pub_r001646_15_1 == pub_r001646_15_2);
  __CPROVER_assume(pub_r001646_11_1 == pub_r001646_11_2);
  __CPROVER_assume(sec_r001646_14_1 != sec_r001646_14_2);
  __CPROVER_assume(sec_r001646_19_1 != sec_r001646_19_2);
  __CPROVER_assume(sec_r001646_17_1 != sec_r001646_17_2);
  __CPROVER_assume(sec_r001646_16_1 != sec_r001646_16_2);
  __CPROVER_assume(sec_r001646_12_1 != sec_r001646_12_2);
  __CPROVER_assume(sec_r001646_18_1 != sec_r001646_18_2);
  __CPROVER_assume(pub_r001646_0_1 == pub_r001646_0_2);
  __CPROVER_assume(sec_r001646_11_1 != sec_r001646_11_2);
  __CPROVER_assume(sec_r001646_0_1 != sec_r001646_0_2);
  __CPROVER_assume(sec_r001646_15_1 != sec_r001646_15_2);
  __CPROVER_assume(pub_r001646_10_1 == pub_r001646_10_2);
  __CPROVER_assume(sec_r001646_1_1 != sec_r001646_1_2);
  __CPROVER_assume(sec_r001646_7_1 != sec_r001646_7_2);
  __CPROVER_assume(sec_r001646_20_1 != sec_r001646_20_2);
  __CPROVER_assume(sec_r001646_22_1 != sec_r001646_22_2);
  __CPROVER_assume(sec_r001646_3_1 != sec_r001646_3_2);
  __CPROVER_assume(pub_r001646_18_1 == pub_r001646_18_2);
  __CPROVER_assume(pub_r001646_17_1 == pub_r001646_17_2);
  __CPROVER_assume(sec_r001646_6_1 != sec_r001646_6_2);
  __CPROVER_assume(pub_r001646_3_1 == pub_r001646_3_2);
  __CPROVER_assume(sec_r001646_8_1 != sec_r001646_8_2);
  __CPROVER_assume(sec_r001646_10_1 != sec_r001646_10_2);
  __CPROVER_assume(sec_r001646_21_1 != sec_r001646_21_2);
  __CPROVER_assume(sec_r001646_5_1 != sec_r001646_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.facility == st_var_2_2.facility);
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
}


