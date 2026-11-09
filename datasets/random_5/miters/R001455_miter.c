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
struct DeviceConfig_R001455_5513_0
{
  int id;
  int parity;
  int port;
  int timeout;
  int baud_rate;
  int buffer[3];
};
struct StreamBuffer_R001455_5513_1
{
  unsigned char watermark;
  int state;
  int tail;
  int head;
  int buffer[3];
};
struct EventLog_R001455_5513_2
{
  int code;
  unsigned char timestamp;
  short severity;
  int signature;
  short facility;
  int buffer[3];
};
union TelemetryField_R001455_5513_0
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
void fn_R001455_5513_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_81_1 = local_arr_1[aux_1 % 3];
  int threshold_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_81_2 * 2)) & 127;
  int scale_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_87_1 > 39)
  {
    acc_1 = ((acc_1 + (scale_87_1 * 2)) + 5) & 127;
    aux_1 ^= scale_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_87_2 > 39)
  {
    acc_2 = ((acc_2 + (scale_87_2 * 2)) + 5) & 127;
    aux_2 ^= scale_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_87_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_45_1 = 0;
  int quotient_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_45_1 = ((quotient_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_45_2 = ((quotient_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_45_1) & 127;
    acc_2 = (acc_2 + quotient_45_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
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

  assert(threshold_81_1 == threshold_81_2);
  assert(scale_87_1 == scale_87_2);
  assert(quotient_45_1 == quotient_45_2);
}

int fn_R001455_5513_0(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int threshold_81 = local_arr[aux % 3];
  acc = (acc + (threshold_81 * 2)) & 127;
  int scale_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_87 > 39)
  {
    acc = ((acc + (scale_87 * 2)) + 5) & 127;
    aux ^= scale_87 & 15;
  }
  else
  {
    acc = ((acc - scale_87) + 11) & 127;
    aux += 3;
  }
  int quotient_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_45 = ((quotient_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_45) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st_1 = {0};
  struct StreamBuffer_R001455_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int offset_83_1 = 0;
  int offset_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_83_1 = ((offset_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_83_2 = ((offset_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_83_1) & 127;
    acc_2 = (acc_2 + offset_83_2) & 127;
  }

  int threshold_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_97_1) & 63;
  aux_2 = (aux_2 + threshold_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_83_1 == offset_83_2);
  assert(threshold_97_1 == threshold_97_2);
}

int fn_R001455_5513_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int offset_83 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_83 = ((offset_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_83) & 127;
  }

  int threshold_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int weight_22_1 = 0;
  int weight_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_22_1 = ((weight_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_22_2 = ((weight_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_22_1) & 127;
    acc_2 = (acc_2 + weight_22_2) & 127;
  }

  int damping_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_93_1) & 63;
  aux_2 = (aux_2 + damping_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_37_1 = local_arr_1[aux_1 % 3];
  int scale_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_37_2 * 2)) & 127;
  int quotient_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_53_1)
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

  switch (quotient_53_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_22_1 == weight_22_2);
  assert(damping_93_1 == damping_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_37_1 == scale_37_2);
  assert(quotient_53_1 == quotient_53_2);
}

int fn_R001455_5513_2(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int weight_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_22 = ((weight_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_22) & 127;
  }

  int damping_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_93) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_37 = local_arr[aux % 3];
  acc = (acc + (scale_37 * 2)) & 127;
  int quotient_53 = (aux + st.buffer[1]) & 3;
  switch (quotient_53)
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

void fn_R001455_5513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_88_1 = 0;
  int quotient_88_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_88_1 = ((quotient_88_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_88_2 = ((quotient_88_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_88_1) & 127;
    acc_2 = (acc_2 + quotient_88_2) & 127;
  }

  int residue_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_31_1) & 63;
  aux_2 = (aux_2 + residue_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_88_1 == quotient_88_2);
  assert(residue_31_1 == residue_31_2);
}

int fn_R001455_5513_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_88 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_88 = ((quotient_88 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_88) & 127;
  }

  int residue_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_74_1 = 0;
  int sample_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_74_1 = ((sample_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_74_2 = ((sample_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_74_1) & 127;
    acc_2 = (acc_2 + sample_74_2) & 127;
  }

  int vector_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_17_1 > 40)
  {
    acc_1 = ((acc_1 + (vector_17_1 * 2)) + 5) & 127;
    aux_1 ^= vector_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_17_2 > 40)
  {
    acc_2 = ((acc_2 + (vector_17_2 * 2)) + 5) & 127;
    aux_2 ^= vector_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_10_1) & 63;
  aux_2 = (aux_2 + checksum_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_74_1 == sample_74_2);
  assert(vector_17_1 == vector_17_2);
  assert(checksum_10_1 == checksum_10_2);
}

int fn_R001455_5513_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_74 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_74 = ((sample_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_74) & 127;
  }

  int vector_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_17 > 40)
  {
    acc = ((acc + (vector_17 * 2)) + 5) & 127;
    aux ^= vector_17 & 15;
  }
  else
  {
    acc = ((acc - vector_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_98_1 = local_arr_1[aux_1 % 3];
  int sample_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_98_2 * 2)) & 127;
  int quotient_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_61_1) & 63;
  aux_2 = (aux_2 + quotient_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
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

  assert(sample_98_1 == sample_98_2);
  assert(quotient_61_1 == quotient_61_2);
}

int fn_R001455_5513_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_98 = local_arr[aux % 3];
  acc = (acc + (sample_98 * 2)) & 127;
  int quotient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int index_reg_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_37_1) & 63;
  aux_2 = (aux_2 + index_reg_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_41_1 > 11)
  {
    acc_1 = ((acc_1 + (margin_41_1 * 2)) + 5) & 127;
    aux_1 ^= margin_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_41_2 > 11)
  {
    acc_2 = ((acc_2 + (margin_41_2 * 2)) + 5) & 127;
    aux_2 ^= margin_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_80_1)
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

  switch (stride_80_2)
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

  int phase_96_1 = 0;
  int phase_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_96_1 = ((phase_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_96_2 = ((phase_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_96_1) & 127;
    acc_2 = (acc_2 + phase_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_37_1 == index_reg_37_2);
  assert(margin_41_1 == margin_41_2);
  assert(stride_80_1 == stride_80_2);
  assert(phase_96_1 == phase_96_2);
}

int fn_R001455_5513_6(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_37) & 63;
  acc ^= aux;
  int margin_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_41 > 11)
  {
    acc = ((acc + (margin_41 * 2)) + 5) & 127;
    aux ^= margin_41 & 15;
  }
  else
  {
    acc = ((acc - margin_41) + 11) & 127;
    aux += 3;
  }
  int stride_80 = (aux + st.buffer[1]) & 3;
  switch (stride_80)
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

  int phase_96 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_96 = ((phase_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001455_5513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int scale_24_1 = 0;
  int scale_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_24_1 = ((scale_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_24_2 = ((scale_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_24_1) & 127;
    acc_2 = (acc_2 + scale_24_2) & 127;
  }

  int coefficient_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_28_1) & 63;
  aux_2 = (aux_2 + coefficient_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_24_1 == scale_24_2);
  assert(coefficient_28_1 == coefficient_28_2);
}

int fn_R001455_5513_7(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int scale_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_24 = ((scale_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_24) & 127;
  }

  int coefficient_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_28) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st_1 = {0};
  struct StreamBuffer_R001455_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_61_1) & 63;
  aux_2 = (aux_2 + bound_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_46_1 = local_arr_1[aux_1 % 3];
  int pivot_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_46_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_61_1 == bound_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_46_1 == pivot_46_2);
}

int fn_R001455_5513_8(int p0, int p1)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_61) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int pivot_46 = local_arr[aux % 3];
  acc = (acc + (pivot_46 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st_1 = {0};
  struct StreamBuffer_R001455_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int checksum_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_42_1)
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

  switch (checksum_42_2)
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

  int vector_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_71_1 > 49)
  {
    acc_1 = ((acc_1 + (vector_71_1 * 2)) + 5) & 127;
    aux_1 ^= vector_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_71_2 > 49)
  {
    acc_2 = ((acc_2 + (vector_71_2 * 2)) + 5) & 127;
    aux_2 ^= vector_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_31_1 = 0;
  int quantum_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_31_1 = ((quantum_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_31_2 = ((quantum_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_31_1) & 127;
    acc_2 = (acc_2 + quantum_31_2) & 127;
  }

  int segment_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_31_1) & 63;
  aux_2 = (aux_2 + segment_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_42_1 == checksum_42_2);
  assert(vector_71_1 == vector_71_2);
  assert(quantum_31_1 == quantum_31_2);
  assert(segment_31_1 == segment_31_2);
}

int fn_R001455_5513_9(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int checksum_42 = (aux + st.buffer[1]) & 3;
  switch (checksum_42)
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

  int vector_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_71 > 49)
  {
    acc = ((acc + (vector_71 * 2)) + 5) & 127;
    aux ^= vector_71 & 15;
  }
  else
  {
    acc = ((acc - vector_71) + 11) & 127;
    aux += 3;
  }
  int quantum_31 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_31 = ((quantum_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_31) & 127;
  }

  int segment_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int damping_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_81_1)
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

  switch (damping_81_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_81_1 == damping_81_2);
}

int fn_R001455_5513_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int damping_81 = (aux + st.buffer[1]) & 3;
  switch (damping_81)
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
  return (acc + aux) & 255;
}

void fn_R001455_5513_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quantum_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_22_1) & 63;
  aux_2 = (aux_2 + quantum_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_34_1)
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

  switch (pivot_34_2)
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

  int accumulator_43_1 = 0;
  int accumulator_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_43_1 = ((accumulator_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_43_2 = ((accumulator_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_43_1) & 127;
    acc_2 = (acc_2 + accumulator_43_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(pivot_34_1 == pivot_34_2);
  assert(accumulator_43_1 == accumulator_43_2);
}

int fn_R001455_5513_11(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quantum_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_22) & 63;
  acc ^= aux;
  int pivot_34 = (aux + st.buffer[1]) & 3;
  switch (pivot_34)
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

  int accumulator_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_43 = ((accumulator_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_43) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001455_5513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_43_1) & 63;
  aux_2 = (aux_2 + weight_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_90_1 = 0;
  int threshold_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_90_1 = ((threshold_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_90_2 = ((threshold_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_90_1) & 127;
    acc_2 = (acc_2 + threshold_90_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_43_1 == weight_43_2);
  assert(threshold_90_1 == threshold_90_2);
}

int fn_R001455_5513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_43) & 63;
  acc ^= aux;
  int threshold_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_90 = ((threshold_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_90) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001455_5513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int margin_75_1 = 0;
  int margin_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_75_1 = ((margin_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_75_2 = ((margin_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_75_1) & 127;
    acc_2 = (acc_2 + margin_75_2) & 127;
  }

  int vector_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_94_1) & 63;
  aux_2 = (aux_2 + vector_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_75_1 == margin_75_2);
  assert(vector_94_1 == vector_94_2);
}

int fn_R001455_5513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int margin_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_75 = ((margin_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_75) & 127;
  }

  int vector_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_29_1 = local_arr_1[aux_1 % 3];
  int mask_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_29_2 * 2)) & 127;
  int parity_39_1 = 0;
  int parity_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_39_1 = ((parity_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_39_2 = ((parity_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_39_1) & 127;
    acc_2 = (acc_2 + parity_39_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
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

  assert(mask_29_1 == mask_29_2);
  assert(parity_39_1 == parity_39_2);
}

int fn_R001455_5513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int mask_29 = local_arr[aux % 3];
  acc = (acc + (mask_29 * 2)) & 127;
  int parity_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_39 = ((parity_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_39) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int cursor_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_82_1)
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

  switch (cursor_82_2)
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
  int segment_65_1 = local_arr_1[aux_1 % 3];
  int segment_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_65_2 * 2)) & 127;
  int tally_86_1 = 0;
  int tally_86_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_86_1 = ((tally_86_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_86_2 = ((tally_86_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_86_1) & 127;
    acc_2 = (acc_2 + tally_86_2) & 127;
  }

  int factor_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_22_1) & 63;
  aux_2 = (aux_2 + factor_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_82_1 == cursor_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_65_1 == segment_65_2);
  assert(tally_86_1 == tally_86_2);
  assert(factor_22_1 == factor_22_2);
}

int fn_R001455_5513_15(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int cursor_82 = (aux + st.buffer[1]) & 3;
  switch (cursor_82)
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
  int segment_65 = local_arr[aux % 3];
  acc = (acc + (segment_65 * 2)) & 127;
  int tally_86 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_86 = ((tally_86 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_86) & 127;
  }

  int factor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_22) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st_1 = {0};
  struct StreamBuffer_R001455_5513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int sample_49_1 = 0;
  int sample_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_49_1 = ((sample_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_49_2 = ((sample_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_49_1) & 127;
    acc_2 = (acc_2 + sample_49_2) & 127;
  }

  int weight_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_41_1) & 63;
  aux_2 = (aux_2 + weight_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_55_1 = local_arr_1[aux_1 % 3];
  int bound_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  assert(st_1.head == st_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_49_1 == sample_49_2);
  assert(weight_41_1 == weight_41_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_55_1 == bound_55_2);
}

int fn_R001455_5513_16(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001455_5513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int sample_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_49 = ((sample_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_49) & 127;
  }

  int weight_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_41) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_55 = local_arr[aux % 3];
  acc = (acc + (bound_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_93_1) & 63;
  aux_2 = (aux_2 + cursor_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_93_1 == cursor_93_2);
}

int fn_R001455_5513_17(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_93) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_30_1)
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

  switch (threshold_30_2)
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

  int cursor_36_1 = 0;
  int cursor_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    cursor_36_1 = ((cursor_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_36_2 = ((cursor_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_36_1) & 127;
    acc_2 = (acc_2 + cursor_36_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_30_1 == threshold_30_2);
  assert(cursor_36_1 == cursor_36_2);
}

int fn_R001455_5513_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_30 = (aux + st.buffer[1]) & 3;
  switch (threshold_30)
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

  int cursor_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    cursor_36 = ((cursor_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_36) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001455_5513_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int mask_52_1 = 0;
  int mask_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_52_1 = ((mask_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_52_2 = ((mask_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_52_1) & 127;
    acc_2 = (acc_2 + mask_52_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_41_1 > 29)
  {
    acc_1 = ((acc_1 + (damping_41_1 * 2)) + 5) & 127;
    aux_1 ^= damping_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_41_2 > 29)
  {
    acc_2 = ((acc_2 + (damping_41_2 * 2)) + 5) & 127;
    aux_2 ^= damping_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_41_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_52_1 == mask_52_2);
  assert(damping_41_1 == damping_41_2);
}

int fn_R001455_5513_19(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int mask_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_52 = ((mask_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_52) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_41 > 29)
  {
    acc = ((acc + (damping_41 * 2)) + 5) & 127;
    aux ^= damping_41 & 15;
  }
  else
  {
    acc = ((acc - damping_41) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001455_5513_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_78_1 > 32)
  {
    acc_1 = ((acc_1 + (phase_78_1 * 2)) + 5) & 127;
    aux_1 ^= phase_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_78_2 > 32)
  {
    acc_2 = ((acc_2 + (phase_78_2 * 2)) + 5) & 127;
    aux_2 ^= phase_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_16_1)
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

  switch (accumulator_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_55_1) & 63;
  aux_2 = (aux_2 + tracker_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_78_1 == phase_78_2);
  assert(accumulator_16_1 == accumulator_16_2);
  assert(tracker_55_1 == tracker_55_2);
}

int fn_R001455_5513_20(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_78 > 32)
  {
    acc = ((acc + (phase_78 * 2)) + 5) & 127;
    aux ^= phase_78 & 15;
  }
  else
  {
    acc = ((acc - phase_78) + 11) & 127;
    aux += 3;
  }
  int accumulator_16 = (aux + st.buffer[1]) & 3;
  switch (accumulator_16)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001455_5513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int accumulator_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_77_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_77_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_77_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_77_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_69_1)
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

  switch (tracker_69_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.id == st_2.id);
  assert(st_1.parity == st_2.parity);
  assert(st_1.port == st_2.port);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.baud_rate == st_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_77_1 == accumulator_77_2);
  assert(tracker_69_1 == tracker_69_2);
}

int fn_R001455_5513_21(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R001455_5513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int accumulator_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_77 > 44)
  {
    acc = ((acc + (accumulator_77 * 2)) + 5) & 127;
    aux ^= accumulator_77 & 15;
  }
  else
  {
    acc = ((acc - accumulator_77) + 11) & 127;
    aux += 3;
  }
  int tracker_69 = (aux + st.buffer[1]) & 3;
  switch (tracker_69)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001455_5513_22_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st_1 = {0};
  struct EventLog_R001455_5513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_71_1 = local_arr_1[aux_1 % 3];
  int threshold_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_71_2 * 2)) & 127;
  int mask_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_43_1) & 63;
  aux_2 = (aux_2 + mask_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_74_1)
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

  switch (delta_74_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
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

  assert(threshold_71_1 == threshold_71_2);
  assert(mask_43_1 == mask_43_2);
  assert(delta_74_1 == delta_74_2);
}

int fn_R001455_5513_22(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001455_5513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_71 = local_arr[aux % 3];
  acc = (acc + (threshold_71 * 2)) & 127;
  int mask_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_43) & 63;
  acc ^= aux;
  int delta_74 = (aux + st.buffer[1]) & 3;
  switch (delta_74)
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

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001455_0_1;
  int sec_r001455_0_2;
  int sec_r001455_1_1;
  int sec_r001455_1_2;
  int sec_r001455_2_1;
  int sec_r001455_2_2;
  int sec_r001455_3_1;
  int sec_r001455_3_2;
  int sec_r001455_4_1;
  int sec_r001455_4_2;
  int sec_r001455_5_1;
  int sec_r001455_5_2;
  int sec_r001455_6_1;
  int sec_r001455_6_2;
  int sec_r001455_7_1;
  int sec_r001455_7_2;
  int sec_r001455_8_1;
  int sec_r001455_8_2;
  int sec_r001455_9_1;
  int sec_r001455_9_2;
  int sec_r001455_10_1;
  int sec_r001455_10_2;
  int sec_r001455_11_1;
  int sec_r001455_11_2;
  int sec_r001455_12_1;
  int sec_r001455_12_2;
  int sec_r001455_13_1;
  int sec_r001455_13_2;
  int sec_r001455_14_1;
  int sec_r001455_14_2;
  int sec_r001455_15_1;
  int sec_r001455_15_2;
  int sec_r001455_16_1;
  int sec_r001455_16_2;
  int sec_r001455_17_1;
  int sec_r001455_17_2;
  int sec_r001455_18_1;
  int sec_r001455_18_2;
  int sec_r001455_19_1;
  int sec_r001455_19_2;
  int pub_r001455_0_1;
  int pub_r001455_0_2;
  int pub_r001455_1_1;
  int pub_r001455_1_2;
  int pub_r001455_2_1;
  int pub_r001455_2_2;
  int pub_r001455_3_1;
  int pub_r001455_3_2;
  int pub_r001455_4_1;
  int pub_r001455_4_2;
  int pub_r001455_5_1;
  int pub_r001455_5_2;
  int pub_r001455_6_1;
  int pub_r001455_6_2;
  int pub_r001455_7_1;
  int pub_r001455_7_2;
  int pub_r001455_8_1;
  int pub_r001455_8_2;
  int pub_r001455_9_1;
  int pub_r001455_9_2;
  int pub_r001455_10_1;
  int pub_r001455_10_2;
  int pub_r001455_11_1;
  int pub_r001455_11_2;
  int pub_r001455_12_1;
  int pub_r001455_12_2;
  int pub_r001455_13_1;
  int pub_r001455_13_2;
  int pub_r001455_14_1;
  int pub_r001455_14_2;
  int pub_r001455_15_1;
  int pub_r001455_15_2;
  int pub_r001455_16_1;
  int pub_r001455_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001455_0_1 >= (-100)) && (pub_r001455_0_1 <= 100));
  __CPROVER_assume((pub_r001455_0_2 >= (-100)) && (pub_r001455_0_2 <= 100));
  __CPROVER_assume((pub_r001455_1_1 >= (-100)) && (pub_r001455_1_1 <= 100));
  __CPROVER_assume((pub_r001455_1_2 >= (-100)) && (pub_r001455_1_2 <= 100));
  __CPROVER_assume((pub_r001455_2_1 >= (-100)) && (pub_r001455_2_1 <= 100));
  __CPROVER_assume((pub_r001455_2_2 >= (-100)) && (pub_r001455_2_2 <= 100));
  __CPROVER_assume((pub_r001455_3_1 >= (-100)) && (pub_r001455_3_1 <= 100));
  __CPROVER_assume((pub_r001455_3_2 >= (-100)) && (pub_r001455_3_2 <= 100));
  __CPROVER_assume((pub_r001455_4_1 >= (-100)) && (pub_r001455_4_1 <= 100));
  __CPROVER_assume((pub_r001455_4_2 >= (-100)) && (pub_r001455_4_2 <= 100));
  __CPROVER_assume((pub_r001455_5_1 >= (-100)) && (pub_r001455_5_1 <= 100));
  __CPROVER_assume((pub_r001455_5_2 >= (-100)) && (pub_r001455_5_2 <= 100));
  __CPROVER_assume((pub_r001455_6_1 >= (-100)) && (pub_r001455_6_1 <= 100));
  __CPROVER_assume((pub_r001455_6_2 >= (-100)) && (pub_r001455_6_2 <= 100));
  __CPROVER_assume((pub_r001455_7_1 >= (-100)) && (pub_r001455_7_1 <= 100));
  __CPROVER_assume((pub_r001455_7_2 >= (-100)) && (pub_r001455_7_2 <= 100));
  __CPROVER_assume((pub_r001455_8_1 >= (-100)) && (pub_r001455_8_1 <= 100));
  __CPROVER_assume((pub_r001455_8_2 >= (-100)) && (pub_r001455_8_2 <= 100));
  __CPROVER_assume((pub_r001455_9_1 >= (-100)) && (pub_r001455_9_1 <= 100));
  __CPROVER_assume((pub_r001455_9_2 >= (-100)) && (pub_r001455_9_2 <= 100));
  __CPROVER_assume((pub_r001455_10_1 >= (-100)) && (pub_r001455_10_1 <= 100));
  __CPROVER_assume((pub_r001455_10_2 >= (-100)) && (pub_r001455_10_2 <= 100));
  __CPROVER_assume((pub_r001455_11_1 >= (-100)) && (pub_r001455_11_1 <= 100));
  __CPROVER_assume((pub_r001455_11_2 >= (-100)) && (pub_r001455_11_2 <= 100));
  __CPROVER_assume((pub_r001455_12_1 >= (-100)) && (pub_r001455_12_1 <= 100));
  __CPROVER_assume((pub_r001455_12_2 >= (-100)) && (pub_r001455_12_2 <= 100));
  __CPROVER_assume((pub_r001455_13_1 >= (-100)) && (pub_r001455_13_1 <= 100));
  __CPROVER_assume((pub_r001455_13_2 >= (-100)) && (pub_r001455_13_2 <= 100));
  __CPROVER_assume((pub_r001455_14_1 >= (-100)) && (pub_r001455_14_1 <= 100));
  __CPROVER_assume((pub_r001455_14_2 >= (-100)) && (pub_r001455_14_2 <= 100));
  __CPROVER_assume((pub_r001455_15_1 >= (-100)) && (pub_r001455_15_1 <= 100));
  __CPROVER_assume((pub_r001455_15_2 >= (-100)) && (pub_r001455_15_2 <= 100));
  __CPROVER_assume((pub_r001455_16_1 >= (-100)) && (pub_r001455_16_1 <= 100));
  __CPROVER_assume((pub_r001455_16_2 >= (-100)) && (pub_r001455_16_2 <= 100));
  __CPROVER_assume((sec_r001455_0_1 >= 0) && (sec_r001455_0_1 <= 255));
  __CPROVER_assume((sec_r001455_0_2 >= 0) && (sec_r001455_0_2 <= 255));
  __CPROVER_assume((sec_r001455_1_1 >= 0) && (sec_r001455_1_1 <= 255));
  __CPROVER_assume((sec_r001455_1_2 >= 0) && (sec_r001455_1_2 <= 255));
  __CPROVER_assume((sec_r001455_2_1 >= 0) && (sec_r001455_2_1 <= 255));
  __CPROVER_assume((sec_r001455_2_2 >= 0) && (sec_r001455_2_2 <= 255));
  __CPROVER_assume((sec_r001455_3_1 >= 0) && (sec_r001455_3_1 <= 255));
  __CPROVER_assume((sec_r001455_3_2 >= 0) && (sec_r001455_3_2 <= 255));
  __CPROVER_assume((sec_r001455_4_1 >= 0) && (sec_r001455_4_1 <= 255));
  __CPROVER_assume((sec_r001455_4_2 >= 0) && (sec_r001455_4_2 <= 255));
  __CPROVER_assume((sec_r001455_5_1 >= 0) && (sec_r001455_5_1 <= 255));
  __CPROVER_assume((sec_r001455_5_2 >= 0) && (sec_r001455_5_2 <= 255));
  __CPROVER_assume((sec_r001455_6_1 >= 0) && (sec_r001455_6_1 <= 255));
  __CPROVER_assume((sec_r001455_6_2 >= 0) && (sec_r001455_6_2 <= 255));
  __CPROVER_assume((sec_r001455_7_1 >= 0) && (sec_r001455_7_1 <= 255));
  __CPROVER_assume((sec_r001455_7_2 >= 0) && (sec_r001455_7_2 <= 255));
  __CPROVER_assume((sec_r001455_8_1 >= 0) && (sec_r001455_8_1 <= 255));
  __CPROVER_assume((sec_r001455_8_2 >= 0) && (sec_r001455_8_2 <= 255));
  __CPROVER_assume((sec_r001455_9_1 >= 0) && (sec_r001455_9_1 <= 255));
  __CPROVER_assume((sec_r001455_9_2 >= 0) && (sec_r001455_9_2 <= 255));
  __CPROVER_assume((sec_r001455_10_1 >= 0) && (sec_r001455_10_1 <= 255));
  __CPROVER_assume((sec_r001455_10_2 >= 0) && (sec_r001455_10_2 <= 255));
  __CPROVER_assume((sec_r001455_11_1 >= 0) && (sec_r001455_11_1 <= 255));
  __CPROVER_assume((sec_r001455_11_2 >= 0) && (sec_r001455_11_2 <= 255));
  __CPROVER_assume((sec_r001455_12_1 >= 0) && (sec_r001455_12_1 <= 255));
  __CPROVER_assume((sec_r001455_12_2 >= 0) && (sec_r001455_12_2 <= 255));
  __CPROVER_assume((sec_r001455_13_1 >= 0) && (sec_r001455_13_1 <= 255));
  __CPROVER_assume((sec_r001455_13_2 >= 0) && (sec_r001455_13_2 <= 255));
  __CPROVER_assume((sec_r001455_14_1 >= 0) && (sec_r001455_14_1 <= 255));
  __CPROVER_assume((sec_r001455_14_2 >= 0) && (sec_r001455_14_2 <= 255));
  __CPROVER_assume((sec_r001455_15_1 >= 0) && (sec_r001455_15_1 <= 255));
  __CPROVER_assume((sec_r001455_15_2 >= 0) && (sec_r001455_15_2 <= 255));
  __CPROVER_assume((sec_r001455_16_1 >= 0) && (sec_r001455_16_1 <= 255));
  __CPROVER_assume((sec_r001455_16_2 >= 0) && (sec_r001455_16_2 <= 255));
  __CPROVER_assume((sec_r001455_17_1 >= 0) && (sec_r001455_17_1 <= 255));
  __CPROVER_assume((sec_r001455_17_2 >= 0) && (sec_r001455_17_2 <= 255));
  __CPROVER_assume((sec_r001455_18_1 >= 0) && (sec_r001455_18_1 <= 255));
  __CPROVER_assume((sec_r001455_18_2 >= 0) && (sec_r001455_18_2 <= 255));
  __CPROVER_assume((sec_r001455_19_1 >= 0) && (sec_r001455_19_1 <= 255));
  __CPROVER_assume((sec_r001455_19_2 >= 0) && (sec_r001455_19_2 <= 255));
  struct DeviceConfig_R001455_5513_0 st_var_0_1 = {0};
  struct DeviceConfig_R001455_5513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001455_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001455_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001455_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001455_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001455_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001455_0_2 + 7) & 15;
  struct StreamBuffer_R001455_5513_1 st_var_1_1 = {0};
  struct StreamBuffer_R001455_5513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001455_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001455_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001455_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001455_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001455_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001455_0_2 + 9) & 15;
  struct EventLog_R001455_5513_2 st_var_2_1 = {0};
  struct EventLog_R001455_5513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001455_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001455_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001455_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001455_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001455_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001455_0_2 + 11) & 15;
  union TelemetryField_R001455_5513_0 u_var_1;
  union TelemetryField_R001455_5513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001455_5513_0(sec_r001455_0_1, pub_r001455_1_1);
  int helper_flow_0_2 = fn_R001455_5513_0(sec_r001455_0_2, pub_r001455_1_2);
  fn_R001455_5513_0_2(sec_r001455_0_1, pub_r001455_1_1, sec_r001455_0_2, pub_r001455_1_2);
  int helper_flow_1_1 = fn_R001455_5513_1(sec_r001455_1_1, pub_r001455_2_1, pub_r001455_3_1, pub_r001455_4_1);
  int helper_flow_1_2 = fn_R001455_5513_1(sec_r001455_1_2, pub_r001455_2_2, pub_r001455_3_2, pub_r001455_4_2);
  fn_R001455_5513_1_2(sec_r001455_1_1, pub_r001455_2_1, pub_r001455_3_1, pub_r001455_4_1, sec_r001455_1_2, pub_r001455_2_2, pub_r001455_3_2, pub_r001455_4_2);
  int helper_flow_2_1 = fn_R001455_5513_2(sec_r001455_2_1, sec_r001455_3_1, pub_r001455_4_1);
  int helper_flow_2_2 = fn_R001455_5513_2(sec_r001455_2_2, sec_r001455_3_2, pub_r001455_4_2);
  fn_R001455_5513_2_2(sec_r001455_2_1, sec_r001455_3_1, pub_r001455_4_1, sec_r001455_2_2, sec_r001455_3_2, pub_r001455_4_2);
  int helper_flow_3_1 = fn_R001455_5513_3(sec_r001455_3_1, pub_r001455_4_1, pub_r001455_5_1, pub_r001455_6_1, pub_r001455_7_1);
  int helper_flow_3_2 = fn_R001455_5513_3(sec_r001455_3_2, pub_r001455_4_2, pub_r001455_5_2, pub_r001455_6_2, pub_r001455_7_2);
  fn_R001455_5513_3_2(sec_r001455_3_1, pub_r001455_4_1, pub_r001455_5_1, pub_r001455_6_1, pub_r001455_7_1, sec_r001455_3_2, pub_r001455_4_2, pub_r001455_5_2, pub_r001455_6_2, pub_r001455_7_2);
  int helper_flow_4_1 = fn_R001455_5513_4(sec_r001455_4_1, pub_r001455_5_1, pub_r001455_6_1, pub_r001455_7_1);
  int helper_flow_4_2 = fn_R001455_5513_4(sec_r001455_4_2, pub_r001455_5_2, pub_r001455_6_2, pub_r001455_7_2);
  fn_R001455_5513_4_2(sec_r001455_4_1, pub_r001455_5_1, pub_r001455_6_1, pub_r001455_7_1, sec_r001455_4_2, pub_r001455_5_2, pub_r001455_6_2, pub_r001455_7_2);
  int stage_v_0_1 = ((pub_r001455_14_1 * 2) + 30) & 63;
  int stage_v_0_2 = ((pub_r001455_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001455_12_1 * 2) + 49) & 63;
  int stage_v_1_2 = ((pub_r001455_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((sec_r001455_18_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_2_2 = ((sec_r001455_18_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_2_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_2_2 + 1) & 15;
  out_sink_1 ^= stage_v_2_1 & 63;
  out_sink_2 ^= stage_v_2_2 & 63;
  int stage_v_3_1 = ((sec_r001455_1_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001455_1_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((pub_r001455_11_1 * 2) + 20) & 63;
  int stage_v_4_2 = ((pub_r001455_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001455_12_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001455_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((sec_r001455_3_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001455_3_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((stage_v_6_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_7_2 = ((stage_v_6_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_7_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_7_2 + 1) & 15;
  out_sink_1 ^= stage_v_7_1 & 63;
  out_sink_2 ^= stage_v_7_2 & 63;
  int stage_v_8_1 = ((sec_r001455_17_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001455_17_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((sec_r001455_5_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_9_2 = ((sec_r001455_5_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((sec_r001455_0_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001455_0_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((sec_r001455_6_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001455_6_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((sec_r001455_9_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001455_9_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((sec_r001455_13_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_13_2 = ((sec_r001455_13_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((sec_r001455_10_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001455_10_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((pub_r001455_16_1 * 2) + 5) & 63;
  int stage_v_15_2 = ((pub_r001455_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001455_2_1 * 2) + 12) & 63;
  int stage_v_16_2 = ((pub_r001455_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001455_8_1 * 2) + 13) & 63;
  int stage_v_17_2 = ((pub_r001455_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001455_3_1 * 2) + 33) & 63;
  int stage_v_18_2 = ((pub_r001455_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001455_2_1 * 2) + 42) & 63;
  int stage_v_19_2 = ((pub_r001455_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((sec_r001455_3_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_20_2 = ((sec_r001455_3_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001455_4_1 * 2) + 20) & 63;
  int stage_v_21_2 = ((pub_r001455_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001455_13_1 * 2) + 50) & 63;
  int stage_v_22_2 = ((pub_r001455_13_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001455_12_1 * 2) + 30) & 63;
  int stage_v_23_2 = ((pub_r001455_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001455_5_1 * 2) + 17) & 63;
  int stage_v_24_2 = ((pub_r001455_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001455_16_1 * 2) + 38) & 63;
  int stage_v_25_2 = ((pub_r001455_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001455_2_1 * 2) + 35) & 63;
  int stage_v_26_2 = ((pub_r001455_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((stage_v_7_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_27_2 = ((stage_v_7_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((helper_flow_4_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_28_2 = ((helper_flow_4_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((stage_v_7_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_29_2 = ((stage_v_7_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_29_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_29_2 + 1) & 15;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = ((pub_r001455_7_1 * 2) + 18) & 63;
  int stage_v_30_2 = ((pub_r001455_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_9_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_31_2 = ((stage_v_9_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((pub_r001455_13_1 * 2) + 42) & 63;
  int stage_v_32_2 = ((pub_r001455_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((stage_v_20_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_33_2 = ((stage_v_20_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((stage_v_31_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_34_2 = ((stage_v_31_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001455_18_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001455_18_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((sec_r001455_10_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_36_2 = ((sec_r001455_10_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_36_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_36_2 + 1) & 15;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = ((sec_r001455_11_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_37_2 = ((sec_r001455_11_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_37_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_37_2 + 1) & 15;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = ((helper_flow_2_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_38_2 = ((helper_flow_2_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((pub_r001455_5_1 * 2) + 14) & 63;
  int stage_v_39_2 = ((pub_r001455_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((helper_flow_4_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_40_2 = ((helper_flow_4_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((pub_r001455_8_1 * 2) + 26) & 63;
  int stage_v_41_2 = ((pub_r001455_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001455_7_1 * 2) + 16) & 63;
  int stage_v_42_2 = ((pub_r001455_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001455_16_1 * 2) + 14) & 63;
  int stage_v_43_2 = ((pub_r001455_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001455_6_1 * 2) + 19) & 63;
  int stage_v_44_2 = ((pub_r001455_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001455_1_1 * 2) + 24) & 63;
  int stage_v_45_2 = ((pub_r001455_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001455_7_1 * 2) + 33) & 63;
  int stage_v_46_2 = ((pub_r001455_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001455_10_1 * 2) + 22) & 63;
  int stage_v_47_2 = ((pub_r001455_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001455_12_1 * 2) + 10) & 63;
  int stage_v_48_2 = ((pub_r001455_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001455_8_1 * 2) + 16) & 63;
  int stage_v_49_2 = ((pub_r001455_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((stage_v_7_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_50_2 = ((stage_v_7_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_50_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_50_2 + 1) & 15;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = ((pub_r001455_7_1 * 2) + 23) & 63;
  int stage_v_51_2 = ((pub_r001455_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((sec_r001455_1_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_52_2 = ((sec_r001455_1_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_52_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_52_2 + 1) & 15;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = ((sec_r001455_2_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_53_2 = ((sec_r001455_2_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_53_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_53_2 + 1) & 15;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = ((stage_v_10_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_10_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((pub_r001455_8_1 * 2) + 15) & 63;
  int stage_v_55_2 = ((pub_r001455_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((sec_r001455_8_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_56_2 = ((sec_r001455_8_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((helper_flow_0_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_57_2 = ((helper_flow_0_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((sec_r001455_8_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_58_2 = ((sec_r001455_8_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((stage_v_11_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_59_2 = ((stage_v_11_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((sec_r001455_13_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_60_2 = ((sec_r001455_13_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_60_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_60_2 + 1) & 15;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = ((stage_v_14_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_61_2 = ((stage_v_14_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_61_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_61_2 + 1) & 15;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = ((stage_v_53_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_62_2 = ((stage_v_53_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_62_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_62_2 + 1) & 15;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = ((stage_v_59_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_63_2 = ((stage_v_59_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_63_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_63_2 + 1) & 15;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = ((stage_v_56_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_64_2 = ((stage_v_56_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_64_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_64_2 + 1) & 15;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = ((sec_r001455_7_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_65_2 = ((sec_r001455_7_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_65_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_65_2 + 1) & 15;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = ((stage_v_52_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_52_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((stage_v_14_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_67_2 = ((stage_v_14_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((stage_v_20_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_68_2 = ((stage_v_20_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_68_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_68_2 + 1) & 15;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = ((pub_r001455_8_1 * 2) + 9) & 63;
  int stage_v_69_2 = ((pub_r001455_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_50_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_50_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001455_12_1 * 2) + 36) & 63;
  int stage_v_71_2 = ((pub_r001455_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((stage_v_12_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_72_2 = ((stage_v_12_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_72_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_72_2 + 1) & 15;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = ((pub_r001455_10_1 * 2) + 13) & 63;
  int stage_v_73_2 = ((pub_r001455_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((stage_v_52_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_74_2 = ((stage_v_52_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_74_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_74_2 + 1) & 15;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = ((stage_v_31_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_75_2 = ((stage_v_31_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((sec_r001455_16_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_76_2 = ((sec_r001455_16_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_76_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_76_2 + 1) & 15;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = ((stage_v_27_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_77_2 = ((stage_v_27_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001455_16_1 * 2) + 16) & 63;
  int stage_v_78_2 = ((pub_r001455_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((stage_v_29_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_79_2 = ((stage_v_29_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_79_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_79_2 + 1) & 15;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = ((stage_v_34_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_80_2 = ((stage_v_34_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_80_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_80_2 + 1) & 15;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = ((sec_r001455_1_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_81_2 = ((sec_r001455_1_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((stage_v_63_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_82_2 = ((stage_v_63_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((stage_v_61_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_83_2 = ((stage_v_61_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((stage_v_54_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_84_2 = ((stage_v_54_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_84_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_84_2 + 1) & 15;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = ((stage_v_35_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_85_2 = ((stage_v_35_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((sec_r001455_9_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_86_2 = ((sec_r001455_9_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_86_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_86_2 + 1) & 15;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = ((pub_r001455_3_1 * 2) + 27) & 63;
  int stage_v_87_2 = ((pub_r001455_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001455_12_1 * 2) + 37) & 63;
  int stage_v_88_2 = ((pub_r001455_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001455_4_1 * 2) + 44) & 63;
  int stage_v_89_2 = ((pub_r001455_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001455_4_1 * 2) + 31) & 63;
  int stage_v_90_2 = ((pub_r001455_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((helper_flow_2_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_91_2 = ((helper_flow_2_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((stage_v_83_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_83_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((stage_v_82_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_93_2 = ((stage_v_82_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_93_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_93_2 + 1) & 15;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = ((pub_r001455_14_1 * 2) + 13) & 63;
  int stage_v_94_2 = ((pub_r001455_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001455_6_1 * 2) + 13) & 63;
  int stage_v_95_2 = ((pub_r001455_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001455_12_1 * 2) + 44) & 63;
  int stage_v_96_2 = ((pub_r001455_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_50_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_97_2 = ((stage_v_50_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_97_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_97_2 + 1) & 15;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = ((stage_v_68_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_68_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((stage_v_74_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_99_2 = ((stage_v_74_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_99_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_99_2 + 1) & 15;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = ((pub_r001455_11_1 * 2) + 23) & 63;
  int stage_v_100_2 = ((pub_r001455_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001455_9_1 * 2) + 44) & 63;
  int stage_v_101_2 = ((pub_r001455_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001455_0_1 * 2) + 28) & 63;
  int stage_v_102_2 = ((pub_r001455_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_35_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_35_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((sec_r001455_16_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_104_2 = ((sec_r001455_16_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_104_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_104_2 + 1) & 15;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = ((sec_r001455_7_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_105_2 = ((sec_r001455_7_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_105_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_105_2 + 1) & 15;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = ((stage_v_52_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_106_2 = ((stage_v_52_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_106_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_106_2 + 1) & 15;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = ((stage_v_3_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_107_2 = ((stage_v_3_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_107_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_107_2 + 1) & 15;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = ((pub_r001455_16_1 * 2) + 10) & 63;
  int stage_v_108_2 = ((pub_r001455_16_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001455_10_1 * 2) + 34) & 63;
  int stage_v_109_2 = ((pub_r001455_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((sec_r001455_15_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_110_2 = ((sec_r001455_15_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_110_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_110_2 + 1) & 15;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = ((sec_r001455_19_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_111_2 = ((sec_r001455_19_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_111_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_111_2 + 1) & 15;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = ((sec_r001455_5_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_112_2 = ((sec_r001455_5_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_112_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_112_2 + 1) & 15;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = ((stage_v_52_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_113_2 = ((stage_v_52_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_113_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_113_2 + 1) & 15;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = ((pub_r001455_14_1 * 2) + 35) & 63;
  int stage_v_114_2 = ((pub_r001455_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001455_3_1 * 2) + 27) & 63;
  int stage_v_115_2 = ((pub_r001455_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_13_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_13_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((stage_v_38_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_117_2 = ((stage_v_38_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_117_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_117_2 + 1) & 15;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = ((pub_r001455_6_1 * 2) + 48) & 63;
  int stage_v_118_2 = ((pub_r001455_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001455_8_1 * 2) + 6) & 63;
  int stage_v_119_2 = ((pub_r001455_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((stage_v_31_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_120_2 = ((stage_v_31_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_120_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_120_2 + 1) & 15;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = ((sec_r001455_11_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_121_2 = ((sec_r001455_11_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_121_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_121_2 + 1) & 15;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = ((stage_v_85_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_122_2 = ((stage_v_85_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((pub_r001455_15_1 * 2) + 15) & 63;
  int stage_v_123_2 = ((pub_r001455_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((stage_v_60_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_124_2 = ((stage_v_60_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_124_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_124_2 + 1) & 15;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = ((pub_r001455_2_1 * 2) + 36) & 63;
  int stage_v_125_2 = ((pub_r001455_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001455_16_1 * 2) + 19) & 63;
  int stage_v_126_2 = ((pub_r001455_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001455_2_1 * 2) + 20) & 63;
  int stage_v_127_2 = ((pub_r001455_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_99_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_99_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((pub_r001455_6_1 * 2) + 49) & 63;
  int stage_v_129_2 = ((pub_r001455_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_63_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_63_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((stage_v_99_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_131_2 = ((stage_v_99_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001455_12_1 * 2) + 18) & 63;
  int stage_v_132_2 = ((pub_r001455_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001455_5_1 * 2) + 34) & 63;
  int stage_v_133_2 = ((pub_r001455_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001455_14_1 * 2) + 46) & 63;
  int stage_v_134_2 = ((pub_r001455_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((stage_v_6_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_135_2 = ((stage_v_6_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_135_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_135_2 + 1) & 15;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = ((stage_v_3_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_136_2 = ((stage_v_3_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_136_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_136_2 + 1) & 15;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = ((stage_v_63_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_137_2 = ((stage_v_63_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_137_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_137_2 + 1) & 15;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = ((stage_v_91_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_138_2 = ((stage_v_91_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_138_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_138_2 + 1) & 15;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = ((stage_v_53_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_139_2 = ((stage_v_53_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_139_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_139_2 + 1) & 15;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = ((stage_v_2_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_140_2 = ((stage_v_2_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_140_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_140_2 + 1) & 15;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = ((stage_v_107_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_107_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((pub_r001455_8_1 * 2) + 47) & 63;
  int stage_v_142_2 = ((pub_r001455_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001455_4_1 * 2) + 22) & 63;
  int stage_v_143_2 = ((pub_r001455_4_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_12_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_12_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_98_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_98_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_144_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_144_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((pub_r001455_12_1 * 2) + 7) & 63;
  int stage_v_147_2 = ((pub_r001455_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((stage_v_112_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_148_2 = ((stage_v_112_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_148_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_148_2 + 1) & 15;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = ((sec_r001455_16_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_149_2 = ((sec_r001455_16_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((helper_flow_4_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_150_2 = ((helper_flow_4_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_150_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_150_2 + 1) & 15;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = ((stage_v_11_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_151_2 = ((stage_v_11_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_151_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_151_2 + 1) & 15;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = ((stage_v_146_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_146_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((pub_r001455_12_1 * 2) + 15) & 63;
  int stage_v_153_2 = ((pub_r001455_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((stage_v_63_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_154_2 = ((stage_v_63_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_154_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_154_2 + 1) & 15;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = ((stage_v_138_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_155_2 = ((stage_v_138_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_155_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_155_2 + 1) & 15;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = ((pub_r001455_2_1 * 2) + 5) & 63;
  int stage_v_156_2 = ((pub_r001455_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((stage_v_116_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_157_2 = ((stage_v_116_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_157_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_157_2 + 1) & 15;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = ((stage_v_144_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_158_2 = ((stage_v_144_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_158_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_158_2 + 1) & 15;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = ((sec_r001455_1_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_159_2 = ((sec_r001455_1_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((stage_v_72_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_160_2 = ((stage_v_72_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_160_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_160_2 + 1) & 15;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = ((stage_v_110_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_110_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((stage_v_10_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_10_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((pub_r001455_8_1 * 2) + 44) & 63;
  int stage_v_163_2 = ((pub_r001455_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_116_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_164_2 = ((stage_v_116_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_164_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_164_2 + 1) & 15;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = ((pub_r001455_0_1 * 2) + 20) & 63;
  int stage_v_165_2 = ((pub_r001455_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_59_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_166_2 = ((stage_v_59_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_166_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_166_2 + 1) & 15;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = ((stage_v_107_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_107_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((stage_v_158_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_168_2 = ((stage_v_158_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_168_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_168_2 + 1) & 15;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = ((stage_v_161_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_169_2 = ((stage_v_161_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_169_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_169_2 + 1) & 15;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001455_2_1 * 2) + 25) & 63;
  int stage_v_171_2 = ((pub_r001455_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001455_8_1 * 2) + 37) & 63;
  int stage_v_172_2 = ((pub_r001455_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001455_7_1 * 2) + 35) & 63;
  int stage_v_173_2 = ((pub_r001455_7_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_111_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_174_2 = ((stage_v_111_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_174_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_174_2 + 1) & 15;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = ((sec_r001455_7_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_175_2 = ((sec_r001455_7_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((pub_r001455_8_1 * 2) + 36) & 63;
  int stage_v_176_2 = ((pub_r001455_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001455_0_1 * 2) + 9) & 63;
  int stage_v_177_2 = ((pub_r001455_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001455_6_1 * 2) + 50) & 63;
  int stage_v_178_2 = ((pub_r001455_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_77_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_179_2 = ((stage_v_77_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_179_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_179_2 + 1) & 15;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = ((helper_flow_3_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_180_2 = ((helper_flow_3_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_180_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_180_2 + 1) & 15;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = ((pub_r001455_9_1 * 2) + 42) & 63;
  int stage_v_181_2 = ((pub_r001455_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_66_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_66_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((helper_flow_2_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_183_2 = ((helper_flow_2_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_183_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_183_2 + 1) & 15;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = ((stage_v_150_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_150_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((stage_v_160_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_160_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001455_8_1 * 2) + 45) & 63;
  int stage_v_186_2 = ((pub_r001455_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((pub_r001455_4_1 * 2) + 23) & 63;
  int stage_v_187_2 = ((pub_r001455_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001455_7_1 * 2) + 10) & 63;
  int stage_v_188_2 = ((pub_r001455_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001455_16_1 * 2) + 31) & 63;
  int stage_v_189_2 = ((pub_r001455_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001455_4_1 * 2) + 25) & 63;
  int stage_v_190_2 = ((pub_r001455_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001455_10_1 * 2) + 37) & 63;
  int stage_v_191_2 = ((pub_r001455_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001455_16_1 * 2) + 22) & 63;
  int stage_v_192_2 = ((pub_r001455_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((stage_v_59_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_193_2 = ((stage_v_59_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_193_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_193_2 + 1) & 15;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = ((pub_r001455_11_1 * 2) + 33) & 63;
  int stage_v_194_2 = ((pub_r001455_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001455_7_1 * 2) + 47) & 63;
  int stage_v_195_2 = ((pub_r001455_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_80_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_80_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_141_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_141_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((pub_r001455_8_1 * 2) + 36) & 63;
  int stage_v_198_2 = ((pub_r001455_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001455_9_1 * 2) + 42) & 63;
  int stage_v_199_2 = ((pub_r001455_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001455_8_1 * 2) + 49) & 63;
  int stage_v_200_2 = ((pub_r001455_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_149_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_149_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_14_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_14_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001455_16_1 * 2) + 5) & 63;
  int stage_v_203_2 = ((pub_r001455_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_184_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_204_2 = ((stage_v_184_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_204_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_204_2 + 1) & 15;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = ((pub_r001455_1_1 * 2) + 44) & 63;
  int stage_v_205_2 = ((pub_r001455_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001455_14_1 * 2) + 38) & 63;
  int stage_v_206_2 = ((pub_r001455_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((stage_v_74_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_207_2 = ((stage_v_74_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_207_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_207_2 + 1) & 15;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = ((stage_v_161_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_161_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((pub_r001455_13_1 * 2) + 45) & 63;
  int stage_v_209_2 = ((pub_r001455_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((stage_v_59_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_210_2 = ((stage_v_59_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_210_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_210_2 + 1) & 15;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = ((pub_r001455_5_1 * 2) + 10) & 63;
  int stage_v_211_2 = ((pub_r001455_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((stage_v_111_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_111_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((pub_r001455_13_1 * 2) + 36) & 63;
  int stage_v_213_2 = ((pub_r001455_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_170_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_214_2 = ((stage_v_170_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_214_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_214_2 + 1) & 15;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_215_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_215_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_215_2 + 1) & 15;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = ((stage_v_29_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_216_2 = ((stage_v_29_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_216_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_216_2 + 1) & 15;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = ((pub_r001455_9_1 * 2) + 19) & 63;
  int stage_v_217_2 = ((pub_r001455_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001455_16_1 * 2) + 45) & 63;
  int stage_v_218_2 = ((pub_r001455_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001455_12_1 * 2) + 14) & 63;
  int stage_v_219_2 = ((pub_r001455_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((sec_r001455_12_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_220_2 = ((sec_r001455_12_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_220_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_220_2 + 1) & 15;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = ((helper_flow_1_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_221_2 = ((helper_flow_1_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_9_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_9_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001455_15_1 * 2) + 6) & 63;
  int stage_v_223_2 = ((pub_r001455_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_103_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_103_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((stage_v_64_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_225_2 = ((stage_v_64_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((pub_r001455_3_1 * 2) + 18) & 63;
  int stage_v_226_2 = ((pub_r001455_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001455_6_1 * 2) + 41) & 63;
  int stage_v_227_2 = ((pub_r001455_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001455_2_1 * 2) + 29) & 63;
  int stage_v_228_2 = ((pub_r001455_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001455_8_1 * 2) + 11) & 63;
  int stage_v_229_2 = ((pub_r001455_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_210_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_210_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((stage_v_152_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_231_2 = ((stage_v_152_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_231_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_231_2 + 1) & 15;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = ((pub_r001455_5_1 * 2) + 24) & 63;
  int stage_v_232_2 = ((pub_r001455_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001455_3_1 * 2) + 25) & 63;
  int stage_v_233_2 = ((pub_r001455_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001455_15_1 * 2) + 34) & 63;
  int stage_v_234_2 = ((pub_r001455_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((sec_r001455_8_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_235_2 = ((sec_r001455_8_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((helper_flow_0_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_236_2 = ((helper_flow_0_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((stage_v_136_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_237_2 = ((stage_v_136_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((pub_r001455_5_1 * 2) + 15) & 63;
  int stage_v_238_2 = ((pub_r001455_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((stage_v_72_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_72_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((pub_r001455_11_1 * 2) + 34) & 63;
  int stage_v_240_2 = ((pub_r001455_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((stage_v_185_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_241_2 = ((stage_v_185_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_241_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_241_2 + 1) & 15;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = ((pub_r001455_6_1 * 2) + 6) & 63;
  int stage_v_242_2 = ((pub_r001455_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_31_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_31_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((stage_v_182_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_244_2 = ((stage_v_182_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_244_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_244_2 + 1) & 15;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = ((pub_r001455_14_1 * 2) + 19) & 63;
  int stage_v_245_2 = ((pub_r001455_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_105_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_246_2 = ((stage_v_105_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_246_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_246_2 + 1) & 15;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = ((stage_v_61_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_247_2 = ((stage_v_61_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_247_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_247_2 + 1) & 15;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = ((pub_r001455_4_1 * 2) + 45) & 63;
  int stage_v_248_2 = ((pub_r001455_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_35_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_35_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((pub_r001455_14_1 * 2) + 27) & 63;
  int stage_v_250_2 = ((pub_r001455_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001455_12_1 * 2) + 29) & 63;
  int stage_v_251_2 = ((pub_r001455_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((stage_v_244_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_244_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_111_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_111_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((stage_v_237_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_237_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((pub_r001455_11_1 * 2) + 7) & 63;
  int stage_v_255_2 = ((pub_r001455_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((stage_v_116_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_256_2 = ((stage_v_116_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_256_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_256_2 + 1) & 15;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = ((pub_r001455_0_1 * 2) + 43) & 63;
  int stage_v_257_2 = ((pub_r001455_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001455_5_1 * 2) + 26) & 63;
  int stage_v_258_2 = ((pub_r001455_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001455_8_1 * 2) + 16) & 63;
  int stage_v_259_2 = ((pub_r001455_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001455_15_1 * 2) + 8) & 63;
  int stage_v_260_2 = ((pub_r001455_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001455_2_1 * 2) + 41) & 63;
  int stage_v_261_2 = ((pub_r001455_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001455_13_1 * 2) + 7) & 63;
  int stage_v_262_2 = ((pub_r001455_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((helper_flow_3_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_263_2 = ((helper_flow_3_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_263_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_263_2 + 1) & 15;
  out_sink_1 ^= stage_v_263_1 & 63;
  out_sink_2 ^= stage_v_263_2 & 63;
  int stage_v_264_1 = ((pub_r001455_3_1 * 2) + 10) & 63;
  int stage_v_264_2 = ((pub_r001455_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((stage_v_121_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_121_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((stage_v_13_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_266_2 = ((stage_v_13_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_266_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_266_2 + 1) & 15;
  out_sink_1 ^= stage_v_266_1 & 63;
  out_sink_2 ^= stage_v_266_2 & 63;
  int stage_v_267_1 = ((pub_r001455_9_1 * 2) + 26) & 63;
  int stage_v_267_2 = ((pub_r001455_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = ((pub_r001455_10_1 * 2) + 11) & 63;
  int stage_v_268_2 = ((pub_r001455_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_37_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_37_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((stage_v_97_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_270_2 = ((stage_v_97_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_270_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_270_2 + 1) & 15;
  out_sink_1 ^= stage_v_270_1 & 63;
  out_sink_2 ^= stage_v_270_2 & 63;
  int stage_v_271_1 = ((helper_flow_1_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_271_2 = ((helper_flow_1_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_271_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_271_2 + 1) & 15;
  out_sink_1 ^= stage_v_271_1 & 63;
  out_sink_2 ^= stage_v_271_2 & 63;
  int stage_v_272_1 = ((stage_v_159_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_159_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_243_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_243_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001455_9_1 * 2) + 32) & 63;
  int stage_v_274_2 = ((pub_r001455_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((sec_r001455_15_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_275_2 = ((sec_r001455_15_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_275_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_275_2 + 1) & 15;
  out_sink_1 ^= stage_v_275_1 & 63;
  out_sink_2 ^= stage_v_275_2 & 63;
  int stage_v_276_1 = ((pub_r001455_15_1 * 2) + 16) & 63;
  int stage_v_276_2 = ((pub_r001455_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001455_3_1 * 2) + 18) & 63;
  int stage_v_277_2 = ((pub_r001455_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((sec_r001455_13_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_278_2 = ((sec_r001455_13_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_278_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_278_2 + 1) & 15;
  out_sink_1 ^= stage_v_278_1 & 63;
  out_sink_2 ^= stage_v_278_2 & 63;
  int stage_v_279_1 = ((pub_r001455_0_1 * 2) + 26) & 63;
  int stage_v_279_2 = ((pub_r001455_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((stage_v_202_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_280_2 = ((stage_v_202_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_280_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_280_2 + 1) & 15;
  out_sink_1 ^= stage_v_280_1 & 63;
  out_sink_2 ^= stage_v_280_2 & 63;
  int stage_v_281_1 = ((pub_r001455_9_1 * 2) + 19) & 63;
  int stage_v_281_2 = ((pub_r001455_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_235_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_235_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_275_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_275_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((stage_v_221_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_284_2 = ((stage_v_221_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_284_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_284_2 + 1) & 15;
  out_sink_1 ^= stage_v_284_1 & 63;
  out_sink_2 ^= stage_v_284_2 & 63;
  int stage_v_285_1 = ((pub_r001455_10_1 * 2) + 9) & 63;
  int stage_v_285_2 = ((pub_r001455_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_170_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_170_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((pub_r001455_11_1 * 2) + 20) & 63;
  int stage_v_287_2 = ((pub_r001455_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001455_0_1 * 2) + 26) & 63;
  int stage_v_288_2 = ((pub_r001455_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_67_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_67_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((pub_r001455_16_1 * 2) + 22) & 63;
  int stage_v_290_2 = ((pub_r001455_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((stage_v_166_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_166_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((stage_v_159_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_292_2 = ((stage_v_159_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_292_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_292_2 + 1) & 15;
  out_sink_1 ^= stage_v_292_1 & 63;
  out_sink_2 ^= stage_v_292_2 & 63;
  int stage_v_293_1 = ((stage_v_145_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_293_2 = ((stage_v_145_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_293_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_293_2 + 1) & 15;
  out_sink_1 ^= stage_v_293_1 & 63;
  out_sink_2 ^= stage_v_293_2 & 63;
  int stage_v_294_1 = ((stage_v_252_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_294_2 = ((stage_v_252_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_294_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_294_2 + 1) & 15;
  out_sink_1 ^= stage_v_294_1 & 63;
  out_sink_2 ^= stage_v_294_2 & 63;
  int stage_v_295_1 = ((pub_r001455_15_1 * 2) + 23) & 63;
  int stage_v_295_2 = ((pub_r001455_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = ((stage_v_84_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_84_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((pub_r001455_13_1 * 2) + 21) & 63;
  int stage_v_297_2 = ((pub_r001455_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001455_6_1 * 2) + 39) & 63;
  int stage_v_298_2 = ((pub_r001455_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((stage_v_254_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_254_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_154_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_154_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001455_11_1 * 2) + 34) & 63;
  int stage_v_301_2 = ((pub_r001455_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001455_8_1 * 2) + 40) & 63;
  int stage_v_302_2 = ((pub_r001455_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001455_1_1 * 2) + 38) & 63;
  int stage_v_303_2 = ((pub_r001455_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001455_0_1 * 2) + 48) & 63;
  int stage_v_304_2 = ((pub_r001455_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((stage_v_2_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_305_2 = ((stage_v_2_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_305_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_305_2 + 1) & 15;
  out_sink_1 ^= stage_v_305_1 & 63;
  out_sink_2 ^= stage_v_305_2 & 63;
  int stage_v_306_1 = ((pub_r001455_1_1 * 2) + 12) & 63;
  int stage_v_306_2 = ((pub_r001455_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001455_16_1 * 2) + 13) & 63;
  int stage_v_307_2 = ((pub_r001455_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((stage_v_160_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_160_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((stage_v_144_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_309_2 = ((stage_v_144_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_309_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_309_2 + 1) & 15;
  out_sink_1 ^= stage_v_309_1 & 63;
  out_sink_2 ^= stage_v_309_2 & 63;
  int stage_v_310_1 = ((stage_v_293_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_293_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((stage_v_75_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_311_2 = ((stage_v_75_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_311_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_311_2 + 1) & 15;
  out_sink_1 ^= stage_v_311_1 & 63;
  out_sink_2 ^= stage_v_311_2 & 63;
  int stage_v_312_1 = ((stage_v_77_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_77_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_193_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_193_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((stage_v_38_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_314_2 = ((stage_v_38_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_314_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_314_2 + 1) & 15;
  out_sink_1 ^= stage_v_314_1 & 63;
  out_sink_2 ^= stage_v_314_2 & 63;
  int stage_v_315_1 = ((sec_r001455_3_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_315_2 = ((sec_r001455_3_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((stage_v_243_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_243_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((pub_r001455_5_1 * 2) + 36) & 63;
  int stage_v_317_2 = ((pub_r001455_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001455_15_1 * 2) + 32) & 63;
  int stage_v_318_2 = ((pub_r001455_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((stage_v_162_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_319_2 = ((stage_v_162_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_319_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_319_2 + 1) & 15;
  out_sink_1 ^= stage_v_319_1 & 63;
  out_sink_2 ^= stage_v_319_2 & 63;
  int stage_v_320_1 = ((stage_v_247_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_247_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001455_14_1 * 2) + 15) & 63;
  int stage_v_321_2 = ((pub_r001455_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((stage_v_70_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_70_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_266_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_266_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((helper_flow_0_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_324_2 = ((helper_flow_0_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_324_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_324_2 + 1) & 15;
  out_sink_1 ^= stage_v_324_1 & 63;
  out_sink_2 ^= stage_v_324_2 & 63;
  int stage_v_325_1 = ((pub_r001455_9_1 * 2) + 50) & 63;
  int stage_v_325_2 = ((pub_r001455_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((stage_v_40_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_326_2 = ((stage_v_40_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((stage_v_122_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_122_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((stage_v_85_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_85_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((pub_r001455_16_1 * 2) + 43) & 63;
  int stage_v_329_2 = ((pub_r001455_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((stage_v_204_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_204_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001455_12_1 * 2) + 25) & 63;
  int stage_v_331_2 = ((pub_r001455_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001455_2_1 * 2) + 49) & 63;
  int stage_v_332_2 = ((pub_r001455_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((stage_v_319_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_333_2 = ((stage_v_319_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_333_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_333_2 + 1) & 15;
  out_sink_1 ^= stage_v_333_1 & 63;
  out_sink_2 ^= stage_v_333_2 & 63;
  int stage_v_334_1 = ((pub_r001455_7_1 * 2) + 32) & 63;
  int stage_v_334_2 = ((pub_r001455_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001455_2_1 * 2) + 5) & 63;
  int stage_v_335_2 = ((pub_r001455_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((stage_v_269_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_336_2 = ((stage_v_269_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_336_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_336_2 + 1) & 15;
  out_sink_1 ^= stage_v_336_1 & 63;
  out_sink_2 ^= stage_v_336_2 & 63;
  int stage_v_337_1 = ((pub_r001455_2_1 * 2) + 25) & 63;
  int stage_v_337_2 = ((pub_r001455_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001455_15_1 * 2) + 38) & 63;
  int stage_v_338_2 = ((pub_r001455_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((stage_v_313_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_339_2 = ((stage_v_313_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_339_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_339_2 + 1) & 15;
  out_sink_1 ^= stage_v_339_1 & 63;
  out_sink_2 ^= stage_v_339_2 & 63;
  int stage_v_340_1 = ((stage_v_309_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_309_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((pub_r001455_14_1 * 2) + 43) & 63;
  int stage_v_341_2 = ((pub_r001455_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((stage_v_105_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_342_2 = ((stage_v_105_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((pub_r001455_3_1 * 2) + 16) & 63;
  int stage_v_343_2 = ((pub_r001455_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001455_10_1 * 2) + 38) & 63;
  int stage_v_344_2 = ((pub_r001455_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((stage_v_91_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_345_2 = ((stage_v_91_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((stage_v_27_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_346_2 = ((stage_v_27_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_346_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_346_2 + 1) & 15;
  out_sink_1 ^= stage_v_346_1 & 63;
  out_sink_2 ^= stage_v_346_2 & 63;
  int stage_v_347_1 = ((stage_v_81_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_347_2 = ((stage_v_81_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((stage_v_300_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_348_2 = ((stage_v_300_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_348_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_348_2 + 1) & 15;
  out_sink_1 ^= stage_v_348_1 & 63;
  out_sink_2 ^= stage_v_348_2 & 63;
  int stage_v_349_1 = ((stage_v_67_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_67_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_137_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_137_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((stage_v_291_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_351_2 = ((stage_v_291_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_351_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_351_2 + 1) & 15;
  out_sink_1 ^= stage_v_351_1 & 63;
  out_sink_2 ^= stage_v_351_2 & 63;
  int stage_v_352_1 = ((stage_v_212_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_212_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((pub_r001455_7_1 * 2) + 16) & 63;
  int stage_v_353_2 = ((pub_r001455_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001455_1_1 * 2) + 23) & 63;
  int stage_v_354_2 = ((pub_r001455_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((stage_v_351_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_351_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((pub_r001455_11_1 * 2) + 17) & 63;
  int stage_v_356_2 = ((pub_r001455_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001455_7_1 * 2) + 34) & 63;
  int stage_v_357_2 = ((pub_r001455_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001455_12_1 * 2) + 35) & 63;
  int stage_v_358_2 = ((pub_r001455_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001455_10_1 * 2) + 14) & 63;
  int stage_v_359_2 = ((pub_r001455_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((stage_v_31_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_360_2 = ((stage_v_31_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001455_0_1 * 2) + 45) & 63;
  int stage_v_361_2 = ((pub_r001455_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001455_13_1 * 2) + 9) & 63;
  int stage_v_362_2 = ((pub_r001455_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((stage_v_52_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_52_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_291_1 << 1) ^ (pub_r001455_16_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_291_2 << 1) ^ (pub_r001455_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_75_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_75_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_136_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_136_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001455_1_1 * 2) + 17) & 63;
  int stage_v_367_2 = ((pub_r001455_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001455_16_1 * 2) + 14) & 63;
  int stage_v_368_2 = ((pub_r001455_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001455_2_1 * 2) + 49) & 63;
  int stage_v_369_2 = ((pub_r001455_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_363_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_363_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((stage_v_76_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_371_2 = ((stage_v_76_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_371_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_371_2 + 1) & 15;
  out_sink_1 ^= stage_v_371_1 & 63;
  out_sink_2 ^= stage_v_371_2 & 63;
  int stage_v_372_1 = ((stage_v_330_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_330_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001455_2_1 * 2) + 47) & 63;
  int stage_v_373_2 = ((pub_r001455_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((stage_v_363_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_363_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001455_8_1 * 2) + 46) & 63;
  int stage_v_375_2 = ((pub_r001455_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001455_13_1 * 2) + 38) & 63;
  int stage_v_376_2 = ((pub_r001455_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((stage_v_2_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_377_2 = ((stage_v_2_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_377_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_377_2 + 1) & 15;
  out_sink_1 ^= stage_v_377_1 & 63;
  out_sink_2 ^= stage_v_377_2 & 63;
  int stage_v_378_1 = ((pub_r001455_5_1 * 2) + 5) & 63;
  int stage_v_378_2 = ((pub_r001455_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((stage_v_122_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_122_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_145_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_145_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((pub_r001455_11_1 * 2) + 47) & 63;
  int stage_v_381_2 = ((pub_r001455_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001455_2_1 * 2) + 25) & 63;
  int stage_v_382_2 = ((pub_r001455_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001455_4_1 * 2) + 10) & 63;
  int stage_v_383_2 = ((pub_r001455_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((sec_r001455_9_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_384_2 = ((sec_r001455_9_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((pub_r001455_10_1 * 2) + 12) & 63;
  int stage_v_385_2 = ((pub_r001455_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((stage_v_149_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_386_2 = ((stage_v_149_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_386_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_386_2 + 1) & 15;
  out_sink_1 ^= stage_v_386_1 & 63;
  out_sink_2 ^= stage_v_386_2 & 63;
  int stage_v_387_1 = ((pub_r001455_11_1 * 2) + 49) & 63;
  int stage_v_387_2 = ((pub_r001455_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001455_2_1 * 2) + 17) & 63;
  int stage_v_388_2 = ((pub_r001455_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001455_15_1 * 2) + 32) & 63;
  int stage_v_389_2 = ((pub_r001455_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((stage_v_36_1 << 1) ^ (pub_r001455_9_1 >> 1)) & 127;
  int stage_v_390_2 = ((stage_v_36_2 << 1) ^ (pub_r001455_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_390_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_390_2 + 1) & 15;
  out_sink_1 ^= stage_v_390_1 & 63;
  out_sink_2 ^= stage_v_390_2 & 63;
  int stage_v_391_1 = ((pub_r001455_10_1 * 2) + 21) & 63;
  int stage_v_391_2 = ((pub_r001455_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001455_15_1 * 2) + 10) & 63;
  int stage_v_392_2 = ((pub_r001455_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = ((stage_v_327_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_327_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((pub_r001455_11_1 * 2) + 19) & 63;
  int stage_v_394_2 = ((pub_r001455_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001455_11_1 * 2) + 25) & 63;
  int stage_v_395_2 = ((pub_r001455_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((stage_v_328_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_328_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((stage_v_309_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_397_2 = ((stage_v_309_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_397_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_397_2 + 1) & 15;
  out_sink_1 ^= stage_v_397_1 & 63;
  out_sink_2 ^= stage_v_397_2 & 63;
  int stage_v_398_1 = ((pub_r001455_1_1 * 2) + 38) & 63;
  int stage_v_398_2 = ((pub_r001455_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((stage_v_8_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_8_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((pub_r001455_1_1 * 2) + 7) & 63;
  int stage_v_400_2 = ((pub_r001455_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_175_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_175_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((pub_r001455_6_1 * 2) + 7) & 63;
  int stage_v_403_2 = ((pub_r001455_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001455_8_1 * 2) + 16) & 63;
  int stage_v_404_2 = ((pub_r001455_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((stage_v_339_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_405_2 = ((stage_v_339_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_405_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_405_2 + 1) & 15;
  out_sink_1 ^= stage_v_405_1 & 63;
  out_sink_2 ^= stage_v_405_2 & 63;
  int stage_v_406_1 = ((pub_r001455_6_1 * 2) + 49) & 63;
  int stage_v_406_2 = ((pub_r001455_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001455_8_1 * 2) + 46) & 63;
  int stage_v_407_2 = ((pub_r001455_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((stage_v_2_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_408_2 = ((stage_v_2_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_408_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_408_2 + 1) & 15;
  out_sink_1 ^= stage_v_408_1 & 63;
  out_sink_2 ^= stage_v_408_2 & 63;
  int stage_v_409_1 = ((stage_v_53_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_53_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((pub_r001455_5_1 * 2) + 37) & 63;
  int stage_v_410_2 = ((pub_r001455_5_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001455_12_1 * 2) + 39) & 63;
  int stage_v_411_2 = ((pub_r001455_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001455_0_1 * 2) + 39) & 63;
  int stage_v_412_2 = ((pub_r001455_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((stage_v_201_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_413_2 = ((stage_v_201_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_413_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_413_2 + 1) & 15;
  out_sink_1 ^= stage_v_413_1 & 63;
  out_sink_2 ^= stage_v_413_2 & 63;
  int stage_v_414_1 = ((pub_r001455_10_1 * 2) + 50) & 63;
  int stage_v_414_2 = ((pub_r001455_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((stage_v_76_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_415_2 = ((stage_v_76_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_415_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_415_2 + 1) & 15;
  out_sink_1 ^= stage_v_415_1 & 63;
  out_sink_2 ^= stage_v_415_2 & 63;
  int stage_v_416_1 = ((stage_v_60_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_416_2 = ((stage_v_60_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_416_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_416_2 + 1) & 15;
  out_sink_1 ^= stage_v_416_1 & 63;
  out_sink_2 ^= stage_v_416_2 & 63;
  int stage_v_417_1 = ((pub_r001455_8_1 * 2) + 23) & 63;
  int stage_v_417_2 = ((pub_r001455_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001455_5_1 * 2) + 20) & 63;
  int stage_v_418_2 = ((pub_r001455_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((stage_v_315_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_315_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((pub_r001455_14_1 * 2) + 27) & 63;
  int stage_v_420_2 = ((pub_r001455_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = ((pub_r001455_11_1 * 2) + 25) & 63;
  int stage_v_421_2 = ((pub_r001455_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001455_0_1 * 2) + 18) & 63;
  int stage_v_422_2 = ((pub_r001455_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((stage_v_139_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_423_2 = ((stage_v_139_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_423_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_423_2 + 1) & 15;
  out_sink_1 ^= stage_v_423_1 & 63;
  out_sink_2 ^= stage_v_423_2 & 63;
  int stage_v_424_1 = ((pub_r001455_7_1 * 2) + 44) & 63;
  int stage_v_424_2 = ((pub_r001455_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001455_9_1 * 2) + 45) & 63;
  int stage_v_425_2 = ((pub_r001455_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001455_10_1 * 2) + 34) & 63;
  int stage_v_426_2 = ((pub_r001455_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((stage_v_320_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_427_2 = ((stage_v_320_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((pub_r001455_9_1 * 2) + 8) & 63;
  int stage_v_428_2 = ((pub_r001455_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((stage_v_86_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_429_2 = ((stage_v_86_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_429_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_429_2 + 1) & 15;
  out_sink_1 ^= stage_v_429_1 & 63;
  out_sink_2 ^= stage_v_429_2 & 63;
  int stage_v_430_1 = ((pub_r001455_1_1 * 2) + 49) & 63;
  int stage_v_430_2 = ((pub_r001455_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001455_14_1 * 2) + 48) & 63;
  int stage_v_431_2 = ((pub_r001455_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001455_9_1 * 2) + 39) & 63;
  int stage_v_432_2 = ((pub_r001455_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001455_12_1 * 2) + 16) & 63;
  int stage_v_433_2 = ((pub_r001455_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((stage_v_146_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_434_2 = ((stage_v_146_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_434_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_434_2 + 1) & 15;
  out_sink_1 ^= stage_v_434_1 & 63;
  out_sink_2 ^= stage_v_434_2 & 63;
  int stage_v_435_1 = ((stage_v_323_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_435_2 = ((stage_v_323_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_435_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_435_2 + 1) & 15;
  out_sink_1 ^= stage_v_435_1 & 63;
  out_sink_2 ^= stage_v_435_2 & 63;
  int stage_v_436_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_436_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_436_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_436_2 + 1) & 15;
  out_sink_1 ^= stage_v_436_1 & 63;
  out_sink_2 ^= stage_v_436_2 & 63;
  int stage_v_437_1 = ((stage_v_92_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_92_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((pub_r001455_9_1 * 2) + 8) & 63;
  int stage_v_438_2 = ((pub_r001455_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((stage_v_216_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_439_2 = ((stage_v_216_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((pub_r001455_4_1 * 2) + 49) & 63;
  int stage_v_440_2 = ((pub_r001455_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001455_3_1 * 2) + 42) & 63;
  int stage_v_441_2 = ((pub_r001455_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((stage_v_185_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_442_2 = ((stage_v_185_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_442_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_442_2 + 1) & 15;
  out_sink_1 ^= stage_v_442_1 & 63;
  out_sink_2 ^= stage_v_442_2 & 63;
  int stage_v_443_1 = ((pub_r001455_16_1 * 2) + 16) & 63;
  int stage_v_443_2 = ((pub_r001455_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((stage_v_278_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_444_2 = ((stage_v_278_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((pub_r001455_1_1 * 2) + 9) & 63;
  int stage_v_445_2 = ((pub_r001455_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001455_8_1 * 2) + 7) & 63;
  int stage_v_446_2 = ((pub_r001455_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001455_10_1 * 2) + 24) & 63;
  int stage_v_447_2 = ((pub_r001455_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((stage_v_76_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_448_2 = ((stage_v_76_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_448_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_448_2 + 1) & 15;
  out_sink_1 ^= stage_v_448_1 & 63;
  out_sink_2 ^= stage_v_448_2 & 63;
  int stage_v_449_1 = ((stage_v_282_1 << 1) ^ (pub_r001455_10_1 >> 1)) & 127;
  int stage_v_449_2 = ((stage_v_282_2 << 1) ^ (pub_r001455_10_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_449_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_449_2 + 1) & 15;
  out_sink_1 ^= stage_v_449_1 & 63;
  out_sink_2 ^= stage_v_449_2 & 63;
  int stage_v_450_1 = ((stage_v_449_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_450_2 = ((stage_v_449_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_450_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_450_2 + 1) & 15;
  out_sink_1 ^= stage_v_450_1 & 63;
  out_sink_2 ^= stage_v_450_2 & 63;
  int stage_v_451_1 = ((pub_r001455_11_1 * 2) + 16) & 63;
  int stage_v_451_2 = ((pub_r001455_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((pub_r001455_3_1 * 2) + 21) & 63;
  int stage_v_452_2 = ((pub_r001455_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((stage_v_174_1 << 1) ^ (pub_r001455_12_1 >> 1)) & 127;
  int stage_v_453_2 = ((stage_v_174_2 << 1) ^ (pub_r001455_12_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_453_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_453_2 + 1) & 15;
  out_sink_1 ^= stage_v_453_1 & 63;
  out_sink_2 ^= stage_v_453_2 & 63;
  int stage_v_454_1 = ((pub_r001455_11_1 * 2) + 46) & 63;
  int stage_v_454_2 = ((pub_r001455_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = ((sec_r001455_11_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_455_2 = ((sec_r001455_11_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_455_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_455_2 + 1) & 15;
  out_sink_1 ^= stage_v_455_1 & 63;
  out_sink_2 ^= stage_v_455_2 & 63;
  int stage_v_456_1 = ((stage_v_107_1 << 1) ^ (pub_r001455_7_1 >> 1)) & 127;
  int stage_v_456_2 = ((stage_v_107_2 << 1) ^ (pub_r001455_7_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_456_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_456_2 + 1) & 15;
  out_sink_1 ^= stage_v_456_1 & 63;
  out_sink_2 ^= stage_v_456_2 & 63;
  int stage_v_457_1 = ((pub_r001455_14_1 * 2) + 46) & 63;
  int stage_v_457_2 = ((pub_r001455_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001455_11_1 * 2) + 41) & 63;
  int stage_v_458_2 = ((pub_r001455_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001455_9_1 * 2) + 47) & 63;
  int stage_v_459_2 = ((pub_r001455_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001455_14_1 * 2) + 45) & 63;
  int stage_v_460_2 = ((pub_r001455_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001455_4_1 * 2) + 12) & 63;
  int stage_v_461_2 = ((pub_r001455_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((stage_v_293_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_462_2 = ((stage_v_293_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_462_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_462_2 + 1) & 15;
  out_sink_1 ^= stage_v_462_1 & 63;
  out_sink_2 ^= stage_v_462_2 & 63;
  int stage_v_463_1 = ((pub_r001455_15_1 * 2) + 35) & 63;
  int stage_v_463_2 = ((pub_r001455_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((stage_v_241_1 << 1) ^ (pub_r001455_3_1 >> 1)) & 127;
  int stage_v_464_2 = ((stage_v_241_2 << 1) ^ (pub_r001455_3_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_464_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_464_2 + 1) & 15;
  out_sink_1 ^= stage_v_464_1 & 63;
  out_sink_2 ^= stage_v_464_2 & 63;
  int stage_v_465_1 = ((pub_r001455_0_1 * 2) + 40) & 63;
  int stage_v_465_2 = ((pub_r001455_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((stage_v_160_1 << 1) ^ (pub_r001455_5_1 >> 1)) & 127;
  int stage_v_466_2 = ((stage_v_160_2 << 1) ^ (pub_r001455_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_466_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_466_2 + 1) & 15;
  out_sink_1 ^= stage_v_466_1 & 63;
  out_sink_2 ^= stage_v_466_2 & 63;
  int stage_v_467_1 = ((pub_r001455_7_1 * 2) + 11) & 63;
  int stage_v_467_2 = ((pub_r001455_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = ((stage_v_464_1 << 1) ^ (pub_r001455_0_1 >> 1)) & 127;
  int stage_v_468_2 = ((stage_v_464_2 << 1) ^ (pub_r001455_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_468_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_468_2 + 1) & 15;
  out_sink_1 ^= stage_v_468_1 & 63;
  out_sink_2 ^= stage_v_468_2 & 63;
  int stage_v_469_1 = ((pub_r001455_5_1 * 2) + 32) & 63;
  int stage_v_469_2 = ((pub_r001455_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001455_3_1 * 2) + 42) & 63;
  int stage_v_470_2 = ((pub_r001455_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((stage_v_14_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_471_2 = ((stage_v_14_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_471_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_471_2 + 1) & 15;
  out_sink_1 ^= stage_v_471_1 & 63;
  out_sink_2 ^= stage_v_471_2 & 63;
  int stage_v_472_1 = ((stage_v_305_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_472_2 = ((stage_v_305_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_472_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_472_2 + 1) & 15;
  out_sink_1 ^= stage_v_472_1 & 63;
  out_sink_2 ^= stage_v_472_2 & 63;
  int stage_v_473_1 = ((stage_v_75_1 << 1) ^ (pub_r001455_14_1 >> 1)) & 127;
  int stage_v_473_2 = ((stage_v_75_2 << 1) ^ (pub_r001455_14_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_473_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_473_2 + 1) & 15;
  out_sink_1 ^= stage_v_473_1 & 63;
  out_sink_2 ^= stage_v_473_2 & 63;
  int stage_v_474_1 = ((stage_v_221_1 << 1) ^ (pub_r001455_15_1 >> 1)) & 127;
  int stage_v_474_2 = ((stage_v_221_2 << 1) ^ (pub_r001455_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_474_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_474_2 + 1) & 15;
  out_sink_1 ^= stage_v_474_1 & 63;
  out_sink_2 ^= stage_v_474_2 & 63;
  int stage_v_475_1 = ((pub_r001455_13_1 * 2) + 48) & 63;
  int stage_v_475_2 = ((pub_r001455_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001455_0_1 * 2) + 29) & 63;
  int stage_v_476_2 = ((pub_r001455_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001455_10_1 * 2) + 29) & 63;
  int stage_v_477_2 = ((pub_r001455_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((pub_r001455_4_1 * 2) + 37) & 63;
  int stage_v_478_2 = ((pub_r001455_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = ((pub_r001455_7_1 * 2) + 34) & 63;
  int stage_v_479_2 = ((pub_r001455_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_479_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_479_2) & 127;
  int stage_v_480_1 = ((stage_v_336_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_480_2 = ((stage_v_336_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_480_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_480_2 + 1) & 15;
  out_sink_1 ^= stage_v_480_1 & 63;
  out_sink_2 ^= stage_v_480_2 & 63;
  int stage_v_481_1 = ((stage_v_471_1 << 1) ^ (pub_r001455_13_1 >> 1)) & 127;
  int stage_v_481_2 = ((stage_v_471_2 << 1) ^ (pub_r001455_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_481_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_481_2 + 1) & 15;
  out_sink_1 ^= stage_v_481_1 & 63;
  out_sink_2 ^= stage_v_481_2 & 63;
  int stage_v_482_1 = ((pub_r001455_15_1 * 2) + 27) & 63;
  int stage_v_482_2 = ((pub_r001455_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001455_0_1 * 2) + 30) & 63;
  int stage_v_483_2 = ((pub_r001455_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = ((pub_r001455_16_1 * 2) + 8) & 63;
  int stage_v_484_2 = ((pub_r001455_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = ((stage_v_145_1 << 1) ^ (pub_r001455_6_1 >> 1)) & 127;
  int stage_v_485_2 = ((stage_v_145_2 << 1) ^ (pub_r001455_6_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_485_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_485_2 + 1) & 15;
  out_sink_1 ^= stage_v_485_1 & 63;
  out_sink_2 ^= stage_v_485_2 & 63;
  int stage_v_486_1 = ((stage_v_50_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_486_2 = ((stage_v_50_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_486_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_486_2 + 1) & 15;
  out_sink_1 ^= stage_v_486_1 & 63;
  out_sink_2 ^= stage_v_486_2 & 63;
  int stage_v_487_1 = ((stage_v_63_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_487_2 = ((stage_v_63_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_487_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_487_2 + 1) & 15;
  out_sink_1 ^= stage_v_487_1 & 63;
  out_sink_2 ^= stage_v_487_2 & 63;
  int stage_v_488_1 = ((pub_r001455_14_1 * 2) + 19) & 63;
  int stage_v_488_2 = ((pub_r001455_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((stage_v_282_1 << 1) ^ (pub_r001455_4_1 >> 1)) & 127;
  int stage_v_489_2 = ((stage_v_282_2 << 1) ^ (pub_r001455_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_489_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_489_2 + 1) & 15;
  out_sink_1 ^= stage_v_489_1 & 63;
  out_sink_2 ^= stage_v_489_2 & 63;
  int stage_v_490_1 = ((stage_v_419_1 << 1) ^ (pub_r001455_2_1 >> 1)) & 127;
  int stage_v_490_2 = ((stage_v_419_2 << 1) ^ (pub_r001455_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_490_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_490_2 + 1) & 15;
  out_sink_1 ^= stage_v_490_1 & 63;
  out_sink_2 ^= stage_v_490_2 & 63;
  int stage_v_491_1 = ((pub_r001455_14_1 * 2) + 11) & 63;
  int stage_v_491_2 = ((pub_r001455_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_492_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_492_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_492_2 + 1) & 15;
  out_sink_1 ^= stage_v_492_1 & 63;
  out_sink_2 ^= stage_v_492_2 & 63;
  int stage_v_493_1 = ((stage_v_135_1 << 1) ^ (pub_r001455_1_1 >> 1)) & 127;
  int stage_v_493_2 = ((stage_v_135_2 << 1) ^ (pub_r001455_1_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_493_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_493_2 + 1) & 15;
  out_sink_1 ^= stage_v_493_1 & 63;
  out_sink_2 ^= stage_v_493_2 & 63;
  int stage_v_494_1 = ((stage_v_282_1 << 1) ^ (pub_r001455_11_1 >> 1)) & 127;
  int stage_v_494_2 = ((stage_v_282_2 << 1) ^ (pub_r001455_11_2 >> 1)) & 127;
  st_var_2_1.buffer[2] = (stage_v_494_1 + 1) & 15;
  st_var_2_2.buffer[2] = (stage_v_494_2 + 1) & 15;
  out_sink_1 ^= stage_v_494_1 & 63;
  out_sink_2 ^= stage_v_494_2 & 63;
  int stage_v_495_1 = ((stage_v_280_1 << 1) ^ (pub_r001455_8_1 >> 1)) & 127;
  int stage_v_495_2 = ((stage_v_280_2 << 1) ^ (pub_r001455_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_495_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_495_2 + 1) & 15;
  out_sink_1 ^= stage_v_495_1 & 63;
  out_sink_2 ^= stage_v_495_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001455_6_1 == pub_r001455_6_2);
  __CPROVER_assume(pub_r001455_15_1 == pub_r001455_15_2);
  __CPROVER_assume(pub_r001455_3_1 == pub_r001455_3_2);
  __CPROVER_assume(pub_r001455_0_1 == pub_r001455_0_2);
  __CPROVER_assume(sec_r001455_17_1 != sec_r001455_17_2);
  __CPROVER_assume(pub_r001455_9_1 == pub_r001455_9_2);
  __CPROVER_assume(sec_r001455_11_1 != sec_r001455_11_2);
  __CPROVER_assume(sec_r001455_14_1 != sec_r001455_14_2);
  __CPROVER_assume(sec_r001455_1_1 != sec_r001455_1_2);
  __CPROVER_assume(pub_r001455_14_1 == pub_r001455_14_2);
  __CPROVER_assume(sec_r001455_10_1 != sec_r001455_10_2);
  __CPROVER_assume(pub_r001455_8_1 == pub_r001455_8_2);
  __CPROVER_assume(sec_r001455_13_1 != sec_r001455_13_2);
  __CPROVER_assume(pub_r001455_13_1 == pub_r001455_13_2);
  __CPROVER_assume(sec_r001455_8_1 != sec_r001455_8_2);
  __CPROVER_assume(pub_r001455_4_1 == pub_r001455_4_2);
  __CPROVER_assume(sec_r001455_12_1 != sec_r001455_12_2);
  __CPROVER_assume(sec_r001455_4_1 != sec_r001455_4_2);
  __CPROVER_assume(sec_r001455_2_1 != sec_r001455_2_2);
  __CPROVER_assume(sec_r001455_18_1 != sec_r001455_18_2);
  __CPROVER_assume(pub_r001455_5_1 == pub_r001455_5_2);
  __CPROVER_assume(sec_r001455_7_1 != sec_r001455_7_2);
  __CPROVER_assume(sec_r001455_19_1 != sec_r001455_19_2);
  __CPROVER_assume(pub_r001455_7_1 == pub_r001455_7_2);
  __CPROVER_assume(sec_r001455_0_1 != sec_r001455_0_2);
  __CPROVER_assume(sec_r001455_3_1 != sec_r001455_3_2);
  __CPROVER_assume(sec_r001455_6_1 != sec_r001455_6_2);
  __CPROVER_assume(pub_r001455_16_1 == pub_r001455_16_2);
  __CPROVER_assume(pub_r001455_12_1 == pub_r001455_12_2);
  __CPROVER_assume(sec_r001455_15_1 != sec_r001455_15_2);
  __CPROVER_assume(sec_r001455_5_1 != sec_r001455_5_2);
  __CPROVER_assume(sec_r001455_9_1 != sec_r001455_9_2);
  __CPROVER_assume(sec_r001455_16_1 != sec_r001455_16_2);
  __CPROVER_assume(pub_r001455_10_1 == pub_r001455_10_2);
  __CPROVER_assume(pub_r001455_11_1 == pub_r001455_11_2);
  __CPROVER_assume(pub_r001455_1_1 == pub_r001455_1_2);
  __CPROVER_assume(pub_r001455_2_1 == pub_r001455_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.id == st_var_0_2.id);
  assert(st_var_0_1.parity == st_var_0_2.parity);
  assert(st_var_0_1.port == st_var_0_2.port);
  assert(st_var_0_1.timeout == st_var_0_2.timeout);
  assert(st_var_0_1.baud_rate == st_var_0_2.baud_rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.head == st_var_1_2.head);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.code == st_var_2_2.code);
  assert(st_var_2_1.timestamp == st_var_2_2.timestamp);
  assert(st_var_2_1.severity == st_var_2_2.severity);
  assert(st_var_2_1.signature == st_var_2_2.signature);
  assert(st_var_2_1.facility == st_var_2_2.facility);
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


