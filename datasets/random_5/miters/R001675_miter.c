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
struct Transaction_R001675_7513_0
{
  unsigned char balance;
  int fee;
  int auth_code;
  int account_id;
  int buffer[3];
};
struct SensorNode_R001675_7513_1
{
  unsigned char calib;
  short offset;
  unsigned char threshold;
  int buffer[3];
};
union PacketPayload_R001675_7513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R001675_7513_1
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
void fn_R001675_7513_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int tracker_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_36_1)
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

  switch (tracker_36_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_96_1 > 22)
  {
    acc_1 = ((acc_1 + (factor_96_1 * 2)) + 5) & 127;
    aux_1 ^= factor_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_96_2 > 22)
  {
    acc_2 = ((acc_2 + (factor_96_2 * 2)) + 5) & 127;
    aux_2 ^= factor_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_40_1 = 0;
  int tally_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_40_1 = ((tally_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_40_2 = ((tally_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_40_1) & 127;
    acc_2 = (acc_2 + tally_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_36_1 == tracker_36_2);
  assert(factor_96_1 == factor_96_2);
  assert(tally_40_1 == tally_40_2);
}

int fn_R001675_7513_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int tracker_36 = (aux + st.buffer[1]) & 3;
  switch (tracker_36)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_96 > 22)
  {
    acc = ((acc + (factor_96 * 2)) + 5) & 127;
    aux ^= factor_96 & 15;
  }
  else
  {
    acc = ((acc - factor_96) + 11) & 127;
    aux += 3;
  }
  int tally_40 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_40 = ((tally_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001675_7513_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_25_1 = local_arr_1[aux_1 % 3];
  int sample_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_25_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_25_1 == sample_25_2);
}

int fn_R001675_7513_1(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int sample_25 = local_arr[aux % 3];
  acc = (acc + (sample_25 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_91_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_91_1 * 2)) + 5) & 127;
    aux_1 ^= stride_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_91_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_91_2 * 2)) + 5) & 127;
    aux_2 ^= stride_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_84_1 = local_arr_1[aux_1 % 3];
  int quotient_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_84_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_91_1 == stride_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_84_1 == quotient_84_2);
}

int fn_R001675_7513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_91 > 40)
  {
    acc = ((acc + (stride_91 * 2)) + 5) & 127;
    aux ^= stride_91 & 15;
  }
  else
  {
    acc = ((acc - stride_91) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_84 = local_arr[aux % 3];
  acc = (acc + (quotient_84 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_93_1 > 23)
  {
    acc_1 = ((acc_1 + (quotient_93_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_93_2 > 23)
  {
    acc_2 = ((acc_2 + (quotient_93_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_93_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_44_1 = local_arr_1[aux_1 % 3];
  int segment_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_93_1 == quotient_93_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_44_1 == segment_44_2);
}

int fn_R001675_7513_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_93 > 23)
  {
    acc = ((acc + (quotient_93 * 2)) + 5) & 127;
    aux ^= quotient_93 & 15;
  }
  else
  {
    acc = ((acc - quotient_93) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_44 = local_arr[aux % 3];
  acc = (acc + (segment_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int metric_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_89_1)
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

  switch (metric_89_2)
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

  int checksum_47_1 = 0;
  int checksum_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_47_1 = ((checksum_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_47_2 = ((checksum_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_47_1) & 127;
    acc_2 = (acc_2 + checksum_47_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_89_1 == metric_89_2);
  assert(checksum_47_1 == checksum_47_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_88_1 == parity_88_2);
}

int fn_R001675_7513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int metric_89 = (aux + st.buffer[1]) & 3;
  switch (metric_89)
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

  int checksum_47 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_47 = ((checksum_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_47) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_88 = local_arr[aux % 3];
  acc = (acc + (parity_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_28_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_28_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_28_1)
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

  switch (vector_28_2)
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

  int quotient_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_49_1 > 47)
  {
    acc_1 = ((acc_1 + (quotient_49_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_49_2 > 47)
  {
    acc_2 = ((acc_2 + (quotient_49_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_77_1 = 0;
  int accumulator_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_77_1 = ((accumulator_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_77_2 = ((accumulator_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_77_1) & 127;
    acc_2 = (acc_2 + accumulator_77_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_28_1 == vector_28_2);
  assert(quotient_49_1 == quotient_49_2);
  assert(accumulator_77_1 == accumulator_77_2);
}

int fn_R001675_7513_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_28 = (aux + st.buffer[1]) & 3;
  switch (vector_28)
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

  int quotient_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_49 > 47)
  {
    acc = ((acc + (quotient_49 * 2)) + 5) & 127;
    aux ^= quotient_49 & 15;
  }
  else
  {
    acc = ((acc - quotient_49) + 11) & 127;
    aux += 3;
  }
  int accumulator_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_77 = ((accumulator_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_77) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001675_7513_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int threshold_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_61_1) & 63;
  aux_2 = (aux_2 + threshold_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_61_1 == threshold_61_2);
}

int fn_R001675_7513_6(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int threshold_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_61) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_27_1) & 63;
  aux_2 = (aux_2 + weight_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_16_1 = local_arr_1[aux_1 % 3];
  int quotient_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_16_2 * 2)) & 127;
  int window_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_31_1 > 50)
  {
    acc_1 = ((acc_1 + (window_31_1 * 2)) + 5) & 127;
    aux_1 ^= window_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_31_2 > 50)
  {
    acc_2 = ((acc_2 + (window_31_2 * 2)) + 5) & 127;
    aux_2 ^= window_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_63_1)
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

  switch (offset_63_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_27_1 == weight_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_16_1 == quotient_16_2);
  assert(window_31_1 == window_31_2);
  assert(offset_63_1 == offset_63_2);
}

int fn_R001675_7513_7(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_27) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_16 = local_arr[aux % 3];
  acc = (acc + (quotient_16 * 2)) & 127;
  int window_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_31 > 50)
  {
    acc = ((acc + (window_31 * 2)) + 5) & 127;
    aux ^= window_31 & 15;
  }
  else
  {
    acc = ((acc - window_31) + 11) & 127;
    aux += 3;
  }
  int offset_63 = (aux + st.buffer[1]) & 3;
  switch (offset_63)
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

void fn_R001675_7513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int margin_80_1 = 0;
  int margin_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_80_1 = ((margin_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_80_2 = ((margin_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_80_1) & 127;
    acc_2 = (acc_2 + margin_80_2) & 127;
  }

  int threshold_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_69_1)
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

  switch (threshold_69_2)
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

  int factor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_10_1 > 32)
  {
    acc_1 = ((acc_1 + (factor_10_1 * 2)) + 5) & 127;
    aux_1 ^= factor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_10_2 > 32)
  {
    acc_2 = ((acc_2 + (factor_10_2 * 2)) + 5) & 127;
    aux_2 ^= factor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_17_1) & 63;
  aux_2 = (aux_2 + bound_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_80_1 == margin_80_2);
  assert(threshold_69_1 == threshold_69_2);
  assert(factor_10_1 == factor_10_2);
  assert(bound_17_1 == bound_17_2);
}

int fn_R001675_7513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int margin_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_80 = ((margin_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_80) & 127;
  }

  int threshold_69 = (aux + st.buffer[1]) & 3;
  switch (threshold_69)
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

  int factor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_10 > 32)
  {
    acc = ((acc + (factor_10 * 2)) + 5) & 127;
    aux ^= factor_10 & 15;
  }
  else
  {
    acc = ((acc - factor_10) + 11) & 127;
    aux += 3;
  }
  int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001675_7513_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_17_1)
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

  switch (quantum_17_2)
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

  int quantum_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_63_1 > 47)
  {
    acc_1 = ((acc_1 + (quantum_63_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_63_2 > 47)
  {
    acc_2 = ((acc_2 + (quantum_63_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_63_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_42_1 = local_arr_1[aux_1 % 3];
  int residue_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_42_2 * 2)) & 127;
  int damping_74_1 = 0;
  int damping_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_74_1 = ((damping_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_74_2 = ((damping_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_74_1) & 127;
    acc_2 = (acc_2 + damping_74_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_17_1 == quantum_17_2);
  assert(quantum_63_1 == quantum_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_42_1 == residue_42_2);
  assert(damping_74_1 == damping_74_2);
}

int fn_R001675_7513_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_17 = (aux + st.buffer[1]) & 3;
  switch (quantum_17)
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

  int quantum_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_63 > 47)
  {
    acc = ((acc + (quantum_63 * 2)) + 5) & 127;
    aux ^= quantum_63 & 15;
  }
  else
  {
    acc = ((acc - quantum_63) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_42 = local_arr[aux % 3];
  acc = (acc + (residue_42 * 2)) & 127;
  int damping_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_74 = ((damping_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_74) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001675_7513_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int damping_30_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_30_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_30_1) & 63;
  aux_2 = (aux_2 + damping_30_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_76_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_76_1 * 2)) + 5) & 127;
    aux_1 ^= damping_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_76_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_76_2 * 2)) + 5) & 127;
    aux_2 ^= damping_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_44_1 = local_arr_1[aux_1 % 3];
  int bound_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_30_1 == damping_30_2);
  assert(damping_76_1 == damping_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_44_1 == bound_44_2);
}

int fn_R001675_7513_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int damping_30 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_30) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_76 > 22)
  {
    acc = ((acc + (damping_76 * 2)) + 5) & 127;
    aux ^= damping_76 & 15;
  }
  else
  {
    acc = ((acc - damping_76) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_44 = local_arr[aux % 3];
  acc = (acc + (bound_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_50_1 = local_arr_1[aux_1 % 3];
  int pivot_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_50_1 == pivot_50_2);
}

int fn_R001675_7513_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_50 = local_arr[aux % 3];
  acc = (acc + (pivot_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int parity_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_83_1) & 63;
  aux_2 = (aux_2 + parity_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_79_1 = 0;
  int anchor_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_79_1 = ((anchor_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_79_2 = ((anchor_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_79_1) & 127;
    acc_2 = (acc_2 + anchor_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_83_1 == parity_83_2);
  assert(anchor_79_1 == anchor_79_2);
}

int fn_R001675_7513_12(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int parity_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_83) & 63;
  acc ^= aux;
  int anchor_79 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_79 = ((anchor_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001675_7513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int offset_69_1 = 0;
  int offset_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_69_1 = ((offset_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_69_2 = ((offset_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_69_1) & 127;
    acc_2 = (acc_2 + offset_69_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_69_1 == offset_69_2);
}

int fn_R001675_7513_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int offset_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_69 = ((offset_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_69) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int segment_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_44_1 > 38)
  {
    acc_1 = ((acc_1 + (segment_44_1 * 2)) + 5) & 127;
    aux_1 ^= segment_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_44_2 > 38)
  {
    acc_2 = ((acc_2 + (segment_44_2 * 2)) + 5) & 127;
    aux_2 ^= segment_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_44_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_73_1)
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

  switch (offset_73_2)
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

  int checksum_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_31_1) & 63;
  aux_2 = (aux_2 + checksum_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_44_1 == segment_44_2);
  assert(offset_73_1 == offset_73_2);
  assert(checksum_31_1 == checksum_31_2);
}

int fn_R001675_7513_14(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int segment_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_44 > 38)
  {
    acc = ((acc + (segment_44 * 2)) + 5) & 127;
    aux ^= segment_44 & 15;
  }
  else
  {
    acc = ((acc - segment_44) + 11) & 127;
    aux += 3;
  }
  int offset_73 = (aux + st.buffer[1]) & 3;
  switch (offset_73)
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

  int checksum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001675_7513_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int segment_19_1 = 0;
  int segment_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_19_1 = ((segment_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_19_2 = ((segment_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_19_1) & 127;
    acc_2 = (acc_2 + segment_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_56_1 > 50)
  {
    acc_1 = ((acc_1 + (threshold_56_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_56_2 > 50)
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
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_19_1 == segment_19_2);
  assert(threshold_56_1 == threshold_56_2);
}

int fn_R001675_7513_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int segment_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_19 = ((segment_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_56 > 50)
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

void fn_R001675_7513_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int anchor_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_82_1) & 63;
  aux_2 = (aux_2 + anchor_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_65_1 > 13)
  {
    acc_1 = ((acc_1 + (mask_65_1 * 2)) + 5) & 127;
    aux_1 ^= mask_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_65_2 > 13)
  {
    acc_2 = ((acc_2 + (mask_65_2 * 2)) + 5) & 127;
    aux_2 ^= mask_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_65_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_82_1 == anchor_82_2);
  assert(mask_65_1 == mask_65_2);
}

int fn_R001675_7513_16(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int anchor_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_82) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_65 > 13)
  {
    acc = ((acc + (mask_65 * 2)) + 5) & 127;
    aux ^= mask_65 & 15;
  }
  else
  {
    acc = ((acc - mask_65) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001675_7513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int checksum_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_49_1)
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

  switch (checksum_49_2)
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

  int cursor_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_30_1 > 17)
  {
    acc_1 = ((acc_1 + (cursor_30_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_30_2 > 17)
  {
    acc_2 = ((acc_2 + (cursor_30_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_30_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_49_1 == checksum_49_2);
  assert(cursor_30_1 == cursor_30_2);
}

int fn_R001675_7513_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int checksum_49 = (aux + st.buffer[1]) & 3;
  switch (checksum_49)
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

  int cursor_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_30 > 17)
  {
    acc = ((acc + (cursor_30 * 2)) + 5) & 127;
    aux ^= cursor_30 & 15;
  }
  else
  {
    acc = ((acc - cursor_30) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int phase_78_1 = 0;
  int phase_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_78_1 = ((phase_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_78_2 = ((phase_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_78_1) & 127;
    acc_2 = (acc_2 + phase_78_2) & 127;
  }

  int anchor_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_75_1) & 63;
  aux_2 = (aux_2 + anchor_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_78_1 == phase_78_2);
  assert(anchor_75_1 == anchor_75_2);
}

int fn_R001675_7513_18(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int phase_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_78 = ((phase_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_78) & 127;
  }

  int anchor_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001675_7513_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_16_1 = local_arr_1[aux_1 % 3];
  int segment_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_16_2 * 2)) & 127;
  int residue_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_37_1 > 22)
  {
    acc_1 = ((acc_1 + (residue_37_1 * 2)) + 5) & 127;
    aux_1 ^= residue_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_37_2 > 22)
  {
    acc_2 = ((acc_2 + (residue_37_2 * 2)) + 5) & 127;
    aux_2 ^= residue_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_16_1 == segment_16_2);
  assert(residue_37_1 == residue_37_2);
}

int fn_R001675_7513_19(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int segment_16 = local_arr[aux % 3];
  acc = (acc + (segment_16 * 2)) & 127;
  int residue_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_37 > 22)
  {
    acc = ((acc + (residue_37 * 2)) + 5) & 127;
    aux ^= residue_37 & 15;
  }
  else
  {
    acc = ((acc - residue_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001675_7513_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
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
  int coefficient_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_93_1)
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

  switch (coefficient_93_2)
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

  int offset_21_1 = 0;
  int offset_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_21_1 = ((offset_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_21_2 = ((offset_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_21_1) & 127;
    acc_2 = (acc_2 + offset_21_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_13_1 = local_arr_1[aux_1 % 3];
  int scale_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_93_1 == coefficient_93_2);
  assert(offset_21_1 == offset_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_13_1 == scale_13_2);
}

int fn_R001675_7513_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_93 = (aux + st.buffer[1]) & 3;
  switch (coefficient_93)
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

  int offset_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_21 = ((offset_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_21) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_13 = local_arr[aux % 3];
  acc = (acc + (scale_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_99_1) & 63;
  aux_2 = (aux_2 + accumulator_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_14_1 = 0;
  int threshold_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_14_1 = ((threshold_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_14_2 = ((threshold_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_14_1) & 127;
    acc_2 = (acc_2 + threshold_14_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
  assert(threshold_14_1 == threshold_14_2);
}

int fn_R001675_7513_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_99) & 63;
  acc ^= aux;
  int threshold_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_14 = ((threshold_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_14) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st_1 = {0};
  struct Transaction_R001675_7513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int damping_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_90_1 > 14)
  {
    acc_1 = ((acc_1 + (damping_90_1 * 2)) + 5) & 127;
    aux_1 ^= damping_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_90_2 > 14)
  {
    acc_2 = ((acc_2 + (damping_90_2 * 2)) + 5) & 127;
    aux_2 ^= damping_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_70_1) & 63;
  aux_2 = (aux_2 + metric_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_92_1)
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

  switch (tracker_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.fee == st_2.fee);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_90_1 == damping_90_2);
  assert(metric_70_1 == metric_70_2);
  assert(tracker_92_1 == tracker_92_2);
}

int fn_R001675_7513_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001675_7513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int damping_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_90 > 14)
  {
    acc = ((acc + (damping_90 * 2)) + 5) & 127;
    aux ^= damping_90 & 15;
  }
  else
  {
    acc = ((acc - damping_90) + 11) & 127;
    aux += 3;
  }
  int metric_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_70) & 63;
  acc ^= aux;
  int tracker_92 = (aux + st.buffer[1]) & 3;
  switch (tracker_92)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001675_7513_23_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st_1 = {0};
  struct SensorNode_R001675_7513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_44_1 = local_arr_1[aux_1 % 3];
  int bound_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_44_2 * 2)) & 127;
  int window_95_1 = 0;
  int window_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_95_1 = ((window_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_95_2 = ((window_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_95_1) & 127;
    acc_2 = (acc_2 + window_95_2) & 127;
  }

  int mask_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_67_1 > 47)
  {
    acc_1 = ((acc_1 + (mask_67_1 * 2)) + 5) & 127;
    aux_1 ^= mask_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_67_2 > 47)
  {
    acc_2 = ((acc_2 + (mask_67_2 * 2)) + 5) & 127;
    aux_2 ^= mask_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_99_1) & 63;
  aux_2 = (aux_2 + metric_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_44_1 == bound_44_2);
  assert(window_95_1 == window_95_2);
  assert(mask_67_1 == mask_67_2);
  assert(metric_99_1 == metric_99_2);
}

int fn_R001675_7513_23(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001675_7513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int bound_44 = local_arr[aux % 3];
  acc = (acc + (bound_44 * 2)) & 127;
  int window_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_95 = ((window_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_95) & 127;
  }

  int mask_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_67 > 47)
  {
    acc = ((acc + (mask_67 * 2)) + 5) & 127;
    aux ^= mask_67 & 15;
  }
  else
  {
    acc = ((acc - mask_67) + 11) & 127;
    aux += 3;
  }
  int metric_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001675_0_1;
  int sec_r001675_0_2;
  int sec_r001675_1_1;
  int sec_r001675_1_2;
  int sec_r001675_2_1;
  int sec_r001675_2_2;
  int sec_r001675_3_1;
  int sec_r001675_3_2;
  int sec_r001675_4_1;
  int sec_r001675_4_2;
  int sec_r001675_5_1;
  int sec_r001675_5_2;
  int sec_r001675_6_1;
  int sec_r001675_6_2;
  int sec_r001675_7_1;
  int sec_r001675_7_2;
  int sec_r001675_8_1;
  int sec_r001675_8_2;
  int sec_r001675_9_1;
  int sec_r001675_9_2;
  int sec_r001675_10_1;
  int sec_r001675_10_2;
  int sec_r001675_11_1;
  int sec_r001675_11_2;
  int sec_r001675_12_1;
  int sec_r001675_12_2;
  int sec_r001675_13_1;
  int sec_r001675_13_2;
  int sec_r001675_14_1;
  int sec_r001675_14_2;
  int sec_r001675_15_1;
  int sec_r001675_15_2;
  int sec_r001675_16_1;
  int sec_r001675_16_2;
  int sec_r001675_17_1;
  int sec_r001675_17_2;
  int sec_r001675_18_1;
  int sec_r001675_18_2;
  int sec_r001675_19_1;
  int sec_r001675_19_2;
  int sec_r001675_20_1;
  int sec_r001675_20_2;
  int sec_r001675_21_1;
  int sec_r001675_21_2;
  int pub_r001675_0_1;
  int pub_r001675_0_2;
  int pub_r001675_1_1;
  int pub_r001675_1_2;
  int pub_r001675_2_1;
  int pub_r001675_2_2;
  int pub_r001675_3_1;
  int pub_r001675_3_2;
  int pub_r001675_4_1;
  int pub_r001675_4_2;
  int pub_r001675_5_1;
  int pub_r001675_5_2;
  int pub_r001675_6_1;
  int pub_r001675_6_2;
  int pub_r001675_7_1;
  int pub_r001675_7_2;
  int pub_r001675_8_1;
  int pub_r001675_8_2;
  int pub_r001675_9_1;
  int pub_r001675_9_2;
  int pub_r001675_10_1;
  int pub_r001675_10_2;
  int pub_r001675_11_1;
  int pub_r001675_11_2;
  int pub_r001675_12_1;
  int pub_r001675_12_2;
  int pub_r001675_13_1;
  int pub_r001675_13_2;
  int pub_r001675_14_1;
  int pub_r001675_14_2;
  int pub_r001675_15_1;
  int pub_r001675_15_2;
  int pub_r001675_16_1;
  int pub_r001675_16_2;
  int pub_r001675_17_1;
  int pub_r001675_17_2;
  int pub_r001675_18_1;
  int pub_r001675_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001675_0_1 >= (-100)) && (pub_r001675_0_1 <= 100));
  __CPROVER_assume((pub_r001675_0_2 >= (-100)) && (pub_r001675_0_2 <= 100));
  __CPROVER_assume((pub_r001675_1_1 >= (-100)) && (pub_r001675_1_1 <= 100));
  __CPROVER_assume((pub_r001675_1_2 >= (-100)) && (pub_r001675_1_2 <= 100));
  __CPROVER_assume((pub_r001675_2_1 >= (-100)) && (pub_r001675_2_1 <= 100));
  __CPROVER_assume((pub_r001675_2_2 >= (-100)) && (pub_r001675_2_2 <= 100));
  __CPROVER_assume((pub_r001675_3_1 >= (-100)) && (pub_r001675_3_1 <= 100));
  __CPROVER_assume((pub_r001675_3_2 >= (-100)) && (pub_r001675_3_2 <= 100));
  __CPROVER_assume((pub_r001675_4_1 >= (-100)) && (pub_r001675_4_1 <= 100));
  __CPROVER_assume((pub_r001675_4_2 >= (-100)) && (pub_r001675_4_2 <= 100));
  __CPROVER_assume((pub_r001675_5_1 >= (-100)) && (pub_r001675_5_1 <= 100));
  __CPROVER_assume((pub_r001675_5_2 >= (-100)) && (pub_r001675_5_2 <= 100));
  __CPROVER_assume((pub_r001675_6_1 >= (-100)) && (pub_r001675_6_1 <= 100));
  __CPROVER_assume((pub_r001675_6_2 >= (-100)) && (pub_r001675_6_2 <= 100));
  __CPROVER_assume((pub_r001675_7_1 >= (-100)) && (pub_r001675_7_1 <= 100));
  __CPROVER_assume((pub_r001675_7_2 >= (-100)) && (pub_r001675_7_2 <= 100));
  __CPROVER_assume((pub_r001675_8_1 >= (-100)) && (pub_r001675_8_1 <= 100));
  __CPROVER_assume((pub_r001675_8_2 >= (-100)) && (pub_r001675_8_2 <= 100));
  __CPROVER_assume((pub_r001675_9_1 >= (-100)) && (pub_r001675_9_1 <= 100));
  __CPROVER_assume((pub_r001675_9_2 >= (-100)) && (pub_r001675_9_2 <= 100));
  __CPROVER_assume((pub_r001675_10_1 >= (-100)) && (pub_r001675_10_1 <= 100));
  __CPROVER_assume((pub_r001675_10_2 >= (-100)) && (pub_r001675_10_2 <= 100));
  __CPROVER_assume((pub_r001675_11_1 >= (-100)) && (pub_r001675_11_1 <= 100));
  __CPROVER_assume((pub_r001675_11_2 >= (-100)) && (pub_r001675_11_2 <= 100));
  __CPROVER_assume((pub_r001675_12_1 >= (-100)) && (pub_r001675_12_1 <= 100));
  __CPROVER_assume((pub_r001675_12_2 >= (-100)) && (pub_r001675_12_2 <= 100));
  __CPROVER_assume((pub_r001675_13_1 >= (-100)) && (pub_r001675_13_1 <= 100));
  __CPROVER_assume((pub_r001675_13_2 >= (-100)) && (pub_r001675_13_2 <= 100));
  __CPROVER_assume((pub_r001675_14_1 >= (-100)) && (pub_r001675_14_1 <= 100));
  __CPROVER_assume((pub_r001675_14_2 >= (-100)) && (pub_r001675_14_2 <= 100));
  __CPROVER_assume((pub_r001675_15_1 >= (-100)) && (pub_r001675_15_1 <= 100));
  __CPROVER_assume((pub_r001675_15_2 >= (-100)) && (pub_r001675_15_2 <= 100));
  __CPROVER_assume((pub_r001675_16_1 >= (-100)) && (pub_r001675_16_1 <= 100));
  __CPROVER_assume((pub_r001675_16_2 >= (-100)) && (pub_r001675_16_2 <= 100));
  __CPROVER_assume((pub_r001675_17_1 >= (-100)) && (pub_r001675_17_1 <= 100));
  __CPROVER_assume((pub_r001675_17_2 >= (-100)) && (pub_r001675_17_2 <= 100));
  __CPROVER_assume((pub_r001675_18_1 >= (-100)) && (pub_r001675_18_1 <= 100));
  __CPROVER_assume((pub_r001675_18_2 >= (-100)) && (pub_r001675_18_2 <= 100));
  __CPROVER_assume((sec_r001675_0_1 >= 0) && (sec_r001675_0_1 <= 255));
  __CPROVER_assume((sec_r001675_0_2 >= 0) && (sec_r001675_0_2 <= 255));
  __CPROVER_assume((sec_r001675_1_1 >= 0) && (sec_r001675_1_1 <= 255));
  __CPROVER_assume((sec_r001675_1_2 >= 0) && (sec_r001675_1_2 <= 255));
  __CPROVER_assume((sec_r001675_2_1 >= 0) && (sec_r001675_2_1 <= 255));
  __CPROVER_assume((sec_r001675_2_2 >= 0) && (sec_r001675_2_2 <= 255));
  __CPROVER_assume((sec_r001675_3_1 >= 0) && (sec_r001675_3_1 <= 255));
  __CPROVER_assume((sec_r001675_3_2 >= 0) && (sec_r001675_3_2 <= 255));
  __CPROVER_assume((sec_r001675_4_1 >= 0) && (sec_r001675_4_1 <= 255));
  __CPROVER_assume((sec_r001675_4_2 >= 0) && (sec_r001675_4_2 <= 255));
  __CPROVER_assume((sec_r001675_5_1 >= 0) && (sec_r001675_5_1 <= 255));
  __CPROVER_assume((sec_r001675_5_2 >= 0) && (sec_r001675_5_2 <= 255));
  __CPROVER_assume((sec_r001675_6_1 >= 0) && (sec_r001675_6_1 <= 255));
  __CPROVER_assume((sec_r001675_6_2 >= 0) && (sec_r001675_6_2 <= 255));
  __CPROVER_assume((sec_r001675_7_1 >= 0) && (sec_r001675_7_1 <= 255));
  __CPROVER_assume((sec_r001675_7_2 >= 0) && (sec_r001675_7_2 <= 255));
  __CPROVER_assume((sec_r001675_8_1 >= 0) && (sec_r001675_8_1 <= 255));
  __CPROVER_assume((sec_r001675_8_2 >= 0) && (sec_r001675_8_2 <= 255));
  __CPROVER_assume((sec_r001675_9_1 >= 0) && (sec_r001675_9_1 <= 255));
  __CPROVER_assume((sec_r001675_9_2 >= 0) && (sec_r001675_9_2 <= 255));
  __CPROVER_assume((sec_r001675_10_1 >= 0) && (sec_r001675_10_1 <= 255));
  __CPROVER_assume((sec_r001675_10_2 >= 0) && (sec_r001675_10_2 <= 255));
  __CPROVER_assume((sec_r001675_11_1 >= 0) && (sec_r001675_11_1 <= 255));
  __CPROVER_assume((sec_r001675_11_2 >= 0) && (sec_r001675_11_2 <= 255));
  __CPROVER_assume((sec_r001675_12_1 >= 0) && (sec_r001675_12_1 <= 255));
  __CPROVER_assume((sec_r001675_12_2 >= 0) && (sec_r001675_12_2 <= 255));
  __CPROVER_assume((sec_r001675_13_1 >= 0) && (sec_r001675_13_1 <= 255));
  __CPROVER_assume((sec_r001675_13_2 >= 0) && (sec_r001675_13_2 <= 255));
  __CPROVER_assume((sec_r001675_14_1 >= 0) && (sec_r001675_14_1 <= 255));
  __CPROVER_assume((sec_r001675_14_2 >= 0) && (sec_r001675_14_2 <= 255));
  __CPROVER_assume((sec_r001675_15_1 >= 0) && (sec_r001675_15_1 <= 255));
  __CPROVER_assume((sec_r001675_15_2 >= 0) && (sec_r001675_15_2 <= 255));
  __CPROVER_assume((sec_r001675_16_1 >= 0) && (sec_r001675_16_1 <= 255));
  __CPROVER_assume((sec_r001675_16_2 >= 0) && (sec_r001675_16_2 <= 255));
  __CPROVER_assume((sec_r001675_17_1 >= 0) && (sec_r001675_17_1 <= 255));
  __CPROVER_assume((sec_r001675_17_2 >= 0) && (sec_r001675_17_2 <= 255));
  __CPROVER_assume((sec_r001675_18_1 >= 0) && (sec_r001675_18_1 <= 255));
  __CPROVER_assume((sec_r001675_18_2 >= 0) && (sec_r001675_18_2 <= 255));
  __CPROVER_assume((sec_r001675_19_1 >= 0) && (sec_r001675_19_1 <= 255));
  __CPROVER_assume((sec_r001675_19_2 >= 0) && (sec_r001675_19_2 <= 255));
  __CPROVER_assume((sec_r001675_20_1 >= 0) && (sec_r001675_20_1 <= 255));
  __CPROVER_assume((sec_r001675_20_2 >= 0) && (sec_r001675_20_2 <= 255));
  __CPROVER_assume((sec_r001675_21_1 >= 0) && (sec_r001675_21_1 <= 255));
  __CPROVER_assume((sec_r001675_21_2 >= 0) && (sec_r001675_21_2 <= 255));
  struct Transaction_R001675_7513_0 st_var_0_1 = {0};
  struct Transaction_R001675_7513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001675_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001675_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001675_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001675_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001675_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001675_0_2 + 7) & 15;
  struct SensorNode_R001675_7513_1 st_var_1_1 = {0};
  struct SensorNode_R001675_7513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001675_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001675_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001675_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001675_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001675_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001675_0_2 + 9) & 15;
  union PacketPayload_R001675_7513_0 u_var_1;
  union PacketPayload_R001675_7513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001675_7513_0(sec_r001675_0_1, pub_r001675_1_1, pub_r001675_2_1, pub_r001675_3_1);
  int helper_flow_0_2 = fn_R001675_7513_0(sec_r001675_0_2, pub_r001675_1_2, pub_r001675_2_2, pub_r001675_3_2);
  fn_R001675_7513_0_2(sec_r001675_0_1, pub_r001675_1_1, pub_r001675_2_1, pub_r001675_3_1, sec_r001675_0_2, pub_r001675_1_2, pub_r001675_2_2, pub_r001675_3_2);
  int helper_flow_1_1 = fn_R001675_7513_1(sec_r001675_1_1, sec_r001675_2_1, pub_r001675_3_1);
  int helper_flow_1_2 = fn_R001675_7513_1(sec_r001675_1_2, sec_r001675_2_2, pub_r001675_3_2);
  fn_R001675_7513_1_2(sec_r001675_1_1, sec_r001675_2_1, pub_r001675_3_1, sec_r001675_1_2, sec_r001675_2_2, pub_r001675_3_2);
  int helper_flow_2_1 = fn_R001675_7513_2(sec_r001675_2_1, sec_r001675_3_1, pub_r001675_4_1, pub_r001675_5_1);
  int helper_flow_2_2 = fn_R001675_7513_2(sec_r001675_2_2, sec_r001675_3_2, pub_r001675_4_2, pub_r001675_5_2);
  fn_R001675_7513_2_2(sec_r001675_2_1, sec_r001675_3_1, pub_r001675_4_1, pub_r001675_5_1, sec_r001675_2_2, sec_r001675_3_2, pub_r001675_4_2, pub_r001675_5_2);
  int helper_flow_3_1 = fn_R001675_7513_3(sec_r001675_3_1, sec_r001675_4_1, pub_r001675_5_1, pub_r001675_6_1);
  int helper_flow_3_2 = fn_R001675_7513_3(sec_r001675_3_2, sec_r001675_4_2, pub_r001675_5_2, pub_r001675_6_2);
  fn_R001675_7513_3_2(sec_r001675_3_1, sec_r001675_4_1, pub_r001675_5_1, pub_r001675_6_1, sec_r001675_3_2, sec_r001675_4_2, pub_r001675_5_2, pub_r001675_6_2);
  int helper_flow_4_1 = fn_R001675_7513_4(sec_r001675_4_1, sec_r001675_5_1, pub_r001675_6_1);
  int helper_flow_4_2 = fn_R001675_7513_4(sec_r001675_4_2, sec_r001675_5_2, pub_r001675_6_2);
  fn_R001675_7513_4_2(sec_r001675_4_1, sec_r001675_5_1, pub_r001675_6_1, sec_r001675_4_2, sec_r001675_5_2, pub_r001675_6_2);
  int helper_flow_5_1 = fn_R001675_7513_5(sec_r001675_5_1, pub_r001675_6_1, pub_r001675_7_1, pub_r001675_8_1, pub_r001675_9_1);
  int helper_flow_5_2 = fn_R001675_7513_5(sec_r001675_5_2, pub_r001675_6_2, pub_r001675_7_2, pub_r001675_8_2, pub_r001675_9_2);
  fn_R001675_7513_5_2(sec_r001675_5_1, pub_r001675_6_1, pub_r001675_7_1, pub_r001675_8_1, pub_r001675_9_1, sec_r001675_5_2, pub_r001675_6_2, pub_r001675_7_2, pub_r001675_8_2, pub_r001675_9_2);
  int stage_v_0_1 = ((pub_r001675_15_1 * 2) + 11) & 63;
  int stage_v_0_2 = ((pub_r001675_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001675_3_1 * 2) + 25) & 63;
  int stage_v_1_2 = ((pub_r001675_3_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001675_5_1 * 2) + 41) & 63;
  int stage_v_2_2 = ((pub_r001675_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_3_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_3_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_3_2 + 1) & 15;
  out_sink_1 ^= stage_v_3_1 & 63;
  out_sink_2 ^= stage_v_3_2 & 63;
  int stage_v_4_1 = ((helper_flow_5_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_4_2 = ((helper_flow_5_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_4_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_4_2 + 1) & 15;
  out_sink_1 ^= stage_v_4_1 & 63;
  out_sink_2 ^= stage_v_4_2 & 63;
  int stage_v_5_1 = ((helper_flow_2_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_5_2 = ((helper_flow_2_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_5_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_5_2 + 1) & 15;
  out_sink_1 ^= stage_v_5_1 & 63;
  out_sink_2 ^= stage_v_5_2 & 63;
  int stage_v_6_1 = ((sec_r001675_20_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_6_2 = ((sec_r001675_20_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_6_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_6_2 + 1) & 15;
  out_sink_1 ^= stage_v_6_1 & 63;
  out_sink_2 ^= stage_v_6_2 & 63;
  int stage_v_7_1 = ((pub_r001675_18_1 * 2) + 11) & 63;
  int stage_v_7_2 = ((pub_r001675_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((sec_r001675_17_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_8_2 = ((sec_r001675_17_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_8_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_8_2 + 1) & 15;
  out_sink_1 ^= stage_v_8_1 & 63;
  out_sink_2 ^= stage_v_8_2 & 63;
  int stage_v_9_1 = ((helper_flow_0_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_9_2 = ((helper_flow_0_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_9_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_9_2 + 1) & 15;
  out_sink_1 ^= stage_v_9_1 & 63;
  out_sink_2 ^= stage_v_9_2 & 63;
  int stage_v_10_1 = ((sec_r001675_15_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_10_2 = ((sec_r001675_15_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_10_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_10_2 + 1) & 15;
  out_sink_1 ^= stage_v_10_1 & 63;
  out_sink_2 ^= stage_v_10_2 & 63;
  int stage_v_11_1 = ((sec_r001675_1_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_11_2 = ((sec_r001675_1_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_11_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_11_2 + 1) & 15;
  out_sink_1 ^= stage_v_11_1 & 63;
  out_sink_2 ^= stage_v_11_2 & 63;
  int stage_v_12_1 = ((sec_r001675_2_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_12_2 = ((sec_r001675_2_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_12_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_12_2 + 1) & 15;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = ((helper_flow_4_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_13_2 = ((helper_flow_4_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_13_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_13_2 + 1) & 15;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = ((sec_r001675_7_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_14_2 = ((sec_r001675_7_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_14_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_14_2 + 1) & 15;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = ((pub_r001675_6_1 * 2) + 30) & 63;
  int stage_v_15_2 = ((pub_r001675_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001675_8_1 * 2) + 6) & 63;
  int stage_v_16_2 = ((pub_r001675_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((stage_v_11_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_17_2 = ((stage_v_11_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_17_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_17_2 + 1) & 15;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = ((sec_r001675_2_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_18_2 = ((sec_r001675_2_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_18_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_18_2 + 1) & 15;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = ((pub_r001675_7_1 * 2) + 19) & 63;
  int stage_v_19_2 = ((pub_r001675_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_11_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_20_2 = ((stage_v_11_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_20_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_20_2 + 1) & 15;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = ((pub_r001675_0_1 * 2) + 28) & 63;
  int stage_v_21_2 = ((pub_r001675_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001675_13_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001675_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_6_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_23_2 = ((stage_v_6_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_23_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_23_2 + 1) & 15;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = ((pub_r001675_4_1 * 2) + 32) & 63;
  int stage_v_24_2 = ((pub_r001675_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001675_8_1 * 2) + 10) & 63;
  int stage_v_25_2 = ((pub_r001675_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001675_16_1 * 2) + 6) & 63;
  int stage_v_26_2 = ((pub_r001675_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((sec_r001675_8_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_27_2 = ((sec_r001675_8_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_27_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_27_2 + 1) & 15;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = ((sec_r001675_15_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_28_2 = ((sec_r001675_15_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_28_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_28_2 + 1) & 15;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = ((pub_r001675_2_1 * 2) + 48) & 63;
  int stage_v_29_2 = ((pub_r001675_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001675_11_1 * 2) + 37) & 63;
  int stage_v_30_2 = ((pub_r001675_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((stage_v_13_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_31_2 = ((stage_v_13_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_31_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_31_2 + 1) & 15;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = ((pub_r001675_9_1 * 2) + 31) & 63;
  int stage_v_32_2 = ((pub_r001675_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001675_3_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_33_2 = ((sec_r001675_3_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_33_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_33_2 + 1) & 15;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = ((sec_r001675_12_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_34_2 = ((sec_r001675_12_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_34_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_34_2 + 1) & 15;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = ((sec_r001675_15_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_35_2 = ((sec_r001675_15_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_35_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_35_2 + 1) & 15;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = ((pub_r001675_14_1 * 2) + 45) & 63;
  int stage_v_36_2 = ((pub_r001675_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001675_16_1 * 2) + 24) & 63;
  int stage_v_37_2 = ((pub_r001675_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001675_9_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_38_2 = ((sec_r001675_9_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_38_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_38_2 + 1) & 15;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = ((pub_r001675_13_1 * 2) + 47) & 63;
  int stage_v_39_2 = ((pub_r001675_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_40_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_40_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_40_2 + 1) & 15;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = ((helper_flow_0_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_41_2 = ((helper_flow_0_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_41_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_41_2 + 1) & 15;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = ((pub_r001675_2_1 * 2) + 16) & 63;
  int stage_v_42_2 = ((pub_r001675_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((stage_v_4_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_43_2 = ((stage_v_4_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_43_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_43_2 + 1) & 15;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = ((stage_v_23_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_44_2 = ((stage_v_23_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_44_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_44_2 + 1) & 15;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = ((sec_r001675_21_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_45_2 = ((sec_r001675_21_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_45_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_45_2 + 1) & 15;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = ((sec_r001675_6_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_46_2 = ((sec_r001675_6_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_46_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_46_2 + 1) & 15;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = ((stage_v_11_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_47_2 = ((stage_v_11_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_47_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_47_2 + 1) & 15;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = ((stage_v_20_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_48_2 = ((stage_v_20_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_48_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_48_2 + 1) & 15;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = ((stage_v_5_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_49_2 = ((stage_v_5_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_49_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_49_2 + 1) & 15;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = ((pub_r001675_9_1 * 2) + 30) & 63;
  int stage_v_50_2 = ((pub_r001675_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001675_17_1 * 2) + 34) & 63;
  int stage_v_51_2 = ((pub_r001675_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001675_13_1 * 2) + 26) & 63;
  int stage_v_52_2 = ((pub_r001675_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001675_6_1 * 2) + 44) & 63;
  int stage_v_53_2 = ((pub_r001675_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((stage_v_46_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_54_2 = ((stage_v_46_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_54_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_54_2 + 1) & 15;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = ((stage_v_28_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_55_2 = ((stage_v_28_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_55_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_55_2 + 1) & 15;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = ((stage_v_34_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_56_2 = ((stage_v_34_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_56_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_56_2 + 1) & 15;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = ((stage_v_48_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_57_2 = ((stage_v_48_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_57_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_57_2 + 1) & 15;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = ((sec_r001675_11_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_58_2 = ((sec_r001675_11_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_58_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_58_2 + 1) & 15;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_59_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_59_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_59_2 + 1) & 15;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = ((pub_r001675_5_1 * 2) + 28) & 63;
  int stage_v_60_2 = ((pub_r001675_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001675_18_1 * 2) + 40) & 63;
  int stage_v_61_2 = ((pub_r001675_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001675_14_1 * 2) + 39) & 63;
  int stage_v_62_2 = ((pub_r001675_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001675_10_1 * 2) + 37) & 63;
  int stage_v_63_2 = ((pub_r001675_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001675_0_1 * 2) + 22) & 63;
  int stage_v_64_2 = ((pub_r001675_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001675_4_1 * 2) + 25) & 63;
  int stage_v_65_2 = ((pub_r001675_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_57_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_66_2 = ((stage_v_57_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_66_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_66_2 + 1) & 15;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = ((stage_v_14_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_67_2 = ((stage_v_14_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_67_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_67_2 + 1) & 15;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = ((pub_r001675_17_1 * 2) + 37) & 63;
  int stage_v_68_2 = ((pub_r001675_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001675_16_1 * 2) + 47) & 63;
  int stage_v_69_2 = ((pub_r001675_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_13_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_70_2 = ((stage_v_13_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_70_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_70_2 + 1) & 15;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = ((pub_r001675_3_1 * 2) + 23) & 63;
  int stage_v_71_2 = ((pub_r001675_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001675_3_1 * 2) + 18) & 63;
  int stage_v_72_2 = ((pub_r001675_3_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((sec_r001675_13_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_73_2 = ((sec_r001675_13_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_73_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_73_2 + 1) & 15;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = ((pub_r001675_12_1 * 2) + 23) & 63;
  int stage_v_74_2 = ((pub_r001675_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001675_0_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_75_2 = ((sec_r001675_0_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_75_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_75_2 + 1) & 15;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = ((pub_r001675_1_1 * 2) + 43) & 63;
  int stage_v_76_2 = ((pub_r001675_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((stage_v_4_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_77_2 = ((stage_v_4_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_77_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_77_2 + 1) & 15;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = ((pub_r001675_8_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001675_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001675_14_1 * 2) + 48) & 63;
  int stage_v_79_2 = ((pub_r001675_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001675_16_1 * 2) + 32) & 63;
  int stage_v_80_2 = ((pub_r001675_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_46_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_81_2 = ((stage_v_46_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_81_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_81_2 + 1) & 15;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = ((sec_r001675_8_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_82_2 = ((sec_r001675_8_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_82_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_82_2 + 1) & 15;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = ((stage_v_70_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_83_2 = ((stage_v_70_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_83_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_83_2 + 1) & 15;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = ((pub_r001675_10_1 * 2) + 16) & 63;
  int stage_v_84_2 = ((pub_r001675_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((helper_flow_5_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_85_2 = ((helper_flow_5_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_85_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_85_2 + 1) & 15;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = ((pub_r001675_4_1 * 2) + 19) & 63;
  int stage_v_86_2 = ((pub_r001675_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001675_18_1 * 2) + 28) & 63;
  int stage_v_87_2 = ((pub_r001675_18_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((sec_r001675_15_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_88_2 = ((sec_r001675_15_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_88_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_88_2 + 1) & 15;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = ((sec_r001675_2_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_89_2 = ((sec_r001675_2_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_89_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_89_2 + 1) & 15;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = ((pub_r001675_5_1 * 2) + 24) & 63;
  int stage_v_90_2 = ((pub_r001675_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((sec_r001675_18_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_91_2 = ((sec_r001675_18_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_91_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_91_2 + 1) & 15;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = ((stage_v_85_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_92_2 = ((stage_v_85_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_92_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_92_2 + 1) & 15;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = ((pub_r001675_11_1 * 2) + 28) & 63;
  int stage_v_93_2 = ((pub_r001675_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_75_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_94_2 = ((stage_v_75_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_94_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_94_2 + 1) & 15;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = ((pub_r001675_15_1 * 2) + 7) & 63;
  int stage_v_95_2 = ((pub_r001675_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001675_7_1 * 2) + 36) & 63;
  int stage_v_96_2 = ((pub_r001675_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001675_9_1 * 2) + 10) & 63;
  int stage_v_97_2 = ((pub_r001675_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((stage_v_41_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_98_2 = ((stage_v_41_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_98_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_98_2 + 1) & 15;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = ((pub_r001675_15_1 * 2) + 31) & 63;
  int stage_v_99_2 = ((pub_r001675_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((stage_v_85_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_100_2 = ((stage_v_85_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_100_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_100_2 + 1) & 15;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = ((stage_v_33_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_101_2 = ((stage_v_33_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_101_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_101_2 + 1) & 15;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = ((pub_r001675_13_1 * 2) + 37) & 63;
  int stage_v_102_2 = ((pub_r001675_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_41_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_103_2 = ((stage_v_41_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_103_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_103_2 + 1) & 15;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = ((pub_r001675_10_1 * 2) + 8) & 63;
  int stage_v_104_2 = ((pub_r001675_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((pub_r001675_8_1 * 2) + 32) & 63;
  int stage_v_105_2 = ((pub_r001675_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001675_0_1 * 2) + 44) & 63;
  int stage_v_106_2 = ((pub_r001675_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001675_1_1 * 2) + 40) & 63;
  int stage_v_107_2 = ((pub_r001675_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((sec_r001675_20_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_108_2 = ((sec_r001675_20_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_108_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_108_2 + 1) & 15;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = ((stage_v_92_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_109_2 = ((stage_v_92_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_109_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_109_2 + 1) & 15;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = ((pub_r001675_6_1 * 2) + 50) & 63;
  int stage_v_110_2 = ((pub_r001675_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001675_18_1 * 2) + 50) & 63;
  int stage_v_111_2 = ((pub_r001675_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001675_1_1 * 2) + 13) & 63;
  int stage_v_112_2 = ((pub_r001675_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001675_15_1 * 2) + 23) & 63;
  int stage_v_113_2 = ((pub_r001675_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001675_16_1 * 2) + 45) & 63;
  int stage_v_114_2 = ((pub_r001675_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001675_9_1 * 2) + 16) & 63;
  int stage_v_115_2 = ((pub_r001675_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_47_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_116_2 = ((stage_v_47_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_116_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_116_2 + 1) & 15;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = ((pub_r001675_5_1 * 2) + 13) & 63;
  int stage_v_117_2 = ((pub_r001675_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001675_16_1 * 2) + 40) & 63;
  int stage_v_118_2 = ((pub_r001675_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_119_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_119_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_119_2 + 1) & 15;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = ((pub_r001675_13_1 * 2) + 37) & 63;
  int stage_v_120_2 = ((pub_r001675_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001675_11_1 * 2) + 42) & 63;
  int stage_v_121_2 = ((pub_r001675_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((sec_r001675_21_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_122_2 = ((sec_r001675_21_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_122_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_122_2 + 1) & 15;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = ((pub_r001675_3_1 * 2) + 22) & 63;
  int stage_v_123_2 = ((pub_r001675_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001675_11_1 * 2) + 38) & 63;
  int stage_v_124_2 = ((pub_r001675_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_28_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_125_2 = ((stage_v_28_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_125_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_125_2 + 1) & 15;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = ((stage_v_92_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_126_2 = ((stage_v_92_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_126_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_126_2 + 1) & 15;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = ((stage_v_56_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_127_2 = ((stage_v_56_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_127_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_127_2 + 1) & 15;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = ((stage_v_12_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_128_2 = ((stage_v_12_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_128_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_128_2 + 1) & 15;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = ((sec_r001675_3_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_129_2 = ((sec_r001675_3_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_129_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_129_2 + 1) & 15;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = ((stage_v_85_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_130_2 = ((stage_v_85_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_130_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_130_2 + 1) & 15;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = ((helper_flow_4_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_131_2 = ((helper_flow_4_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_131_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_131_2 + 1) & 15;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = ((pub_r001675_3_1 * 2) + 41) & 63;
  int stage_v_132_2 = ((pub_r001675_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_9_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_133_2 = ((stage_v_9_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_133_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_133_2 + 1) & 15;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = ((stage_v_45_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_134_2 = ((stage_v_45_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_134_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_134_2 + 1) & 15;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = ((pub_r001675_15_1 * 2) + 46) & 63;
  int stage_v_135_2 = ((pub_r001675_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001675_17_1 * 2) + 24) & 63;
  int stage_v_136_2 = ((pub_r001675_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001675_11_1 * 2) + 12) & 63;
  int stage_v_137_2 = ((pub_r001675_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001675_16_1 * 2) + 23) & 63;
  int stage_v_138_2 = ((pub_r001675_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001675_7_1 * 2) + 25) & 63;
  int stage_v_139_2 = ((pub_r001675_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001675_14_1 * 2) + 31) & 63;
  int stage_v_140_2 = ((pub_r001675_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_75_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_141_2 = ((stage_v_75_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_141_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_141_2 + 1) & 15;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = ((pub_r001675_8_1 * 2) + 10) & 63;
  int stage_v_142_2 = ((pub_r001675_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_131_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_143_2 = ((stage_v_131_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_143_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_143_2 + 1) & 15;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = ((stage_v_133_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_144_2 = ((stage_v_133_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_144_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_144_2 + 1) & 15;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = ((stage_v_89_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_145_2 = ((stage_v_89_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_145_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_145_2 + 1) & 15;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = ((stage_v_101_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_146_2 = ((stage_v_101_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_146_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_146_2 + 1) & 15;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = ((stage_v_100_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_147_2 = ((stage_v_100_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_147_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_147_2 + 1) & 15;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = ((pub_r001675_8_1 * 2) + 15) & 63;
  int stage_v_148_2 = ((pub_r001675_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((sec_r001675_18_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_149_2 = ((sec_r001675_18_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_149_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_149_2 + 1) & 15;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = ((pub_r001675_3_1 * 2) + 43) & 63;
  int stage_v_150_2 = ((pub_r001675_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001675_18_1 * 2) + 44) & 63;
  int stage_v_151_2 = ((pub_r001675_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_18_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_152_2 = ((stage_v_18_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_152_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_152_2 + 1) & 15;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = ((stage_v_70_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_153_2 = ((stage_v_70_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_153_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_153_2 + 1) & 15;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = ((pub_r001675_1_1 * 2) + 25) & 63;
  int stage_v_154_2 = ((pub_r001675_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001675_10_1 * 2) + 48) & 63;
  int stage_v_155_2 = ((pub_r001675_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((sec_r001675_2_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_156_2 = ((sec_r001675_2_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_156_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_156_2 + 1) & 15;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = ((pub_r001675_10_1 * 2) + 21) & 63;
  int stage_v_157_2 = ((pub_r001675_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001675_1_1 * 2) + 27) & 63;
  int stage_v_158_2 = ((pub_r001675_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((stage_v_23_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_159_2 = ((stage_v_23_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_159_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_159_2 + 1) & 15;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = ((pub_r001675_16_1 * 2) + 16) & 63;
  int stage_v_160_2 = ((pub_r001675_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_129_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_161_2 = ((stage_v_129_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_161_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_161_2 + 1) & 15;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = ((stage_v_12_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_162_2 = ((stage_v_12_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_162_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_162_2 + 1) & 15;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = ((stage_v_130_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_163_2 = ((stage_v_130_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_163_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_163_2 + 1) & 15;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = ((pub_r001675_2_1 * 2) + 14) & 63;
  int stage_v_164_2 = ((pub_r001675_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_134_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_165_2 = ((stage_v_134_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_165_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_165_2 + 1) & 15;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = ((pub_r001675_4_1 * 2) + 45) & 63;
  int stage_v_166_2 = ((pub_r001675_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((stage_v_108_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_167_2 = ((stage_v_108_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_167_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_167_2 + 1) & 15;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = ((pub_r001675_3_1 * 2) + 17) & 63;
  int stage_v_168_2 = ((pub_r001675_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001675_8_1 * 2) + 30) & 63;
  int stage_v_169_2 = ((pub_r001675_8_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_161_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_170_2 = ((stage_v_161_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_170_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_170_2 + 1) & 15;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = ((pub_r001675_1_1 * 2) + 19) & 63;
  int stage_v_171_2 = ((pub_r001675_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001675_3_1 * 2) + 19) & 63;
  int stage_v_172_2 = ((pub_r001675_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001675_8_1 * 2) + 28) & 63;
  int stage_v_173_2 = ((pub_r001675_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001675_2_1 * 2) + 31) & 63;
  int stage_v_174_2 = ((pub_r001675_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_163_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_175_2 = ((stage_v_163_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_175_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_175_2 + 1) & 15;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = ((pub_r001675_17_1 * 2) + 25) & 63;
  int stage_v_176_2 = ((pub_r001675_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001675_1_1 * 2) + 48) & 63;
  int stage_v_177_2 = ((pub_r001675_1_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001675_5_1 * 2) + 45) & 63;
  int stage_v_178_2 = ((pub_r001675_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001675_16_1 * 2) + 34) & 63;
  int stage_v_179_2 = ((pub_r001675_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001675_14_1 * 2) + 34) & 63;
  int stage_v_180_2 = ((pub_r001675_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001675_15_1 * 2) + 16) & 63;
  int stage_v_181_2 = ((pub_r001675_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_55_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_182_2 = ((stage_v_55_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_182_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_182_2 + 1) & 15;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = ((pub_r001675_7_1 * 2) + 37) & 63;
  int stage_v_183_2 = ((pub_r001675_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((stage_v_40_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_184_2 = ((stage_v_40_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_184_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_184_2 + 1) & 15;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = ((stage_v_119_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_185_2 = ((stage_v_119_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_185_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_185_2 + 1) & 15;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = ((pub_r001675_18_1 * 2) + 19) & 63;
  int stage_v_186_2 = ((pub_r001675_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_55_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_187_2 = ((stage_v_55_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_187_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_187_2 + 1) & 15;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = ((stage_v_81_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_188_2 = ((stage_v_81_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_188_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_188_2 + 1) & 15;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = ((pub_r001675_6_1 * 2) + 37) & 63;
  int stage_v_189_2 = ((pub_r001675_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001675_5_1 * 2) + 12) & 63;
  int stage_v_190_2 = ((pub_r001675_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((sec_r001675_20_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_191_2 = ((sec_r001675_20_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_191_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_191_2 + 1) & 15;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_192_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_192_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_192_2 + 1) & 15;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = ((pub_r001675_14_1 * 2) + 13) & 63;
  int stage_v_193_2 = ((pub_r001675_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((stage_v_41_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_194_2 = ((stage_v_41_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_194_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_194_2 + 1) & 15;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = ((pub_r001675_18_1 * 2) + 24) & 63;
  int stage_v_195_2 = ((pub_r001675_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((stage_v_119_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_196_2 = ((stage_v_119_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_196_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_196_2 + 1) & 15;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = ((stage_v_130_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_197_2 = ((stage_v_130_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_197_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_197_2 + 1) & 15;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = ((sec_r001675_4_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_198_2 = ((sec_r001675_4_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_198_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_198_2 + 1) & 15;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = ((stage_v_108_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_199_2 = ((stage_v_108_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_199_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_199_2 + 1) & 15;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = ((pub_r001675_6_1 * 2) + 30) & 63;
  int stage_v_200_2 = ((pub_r001675_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((stage_v_54_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_201_2 = ((stage_v_54_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_201_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_201_2 + 1) & 15;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = ((stage_v_131_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_202_2 = ((stage_v_131_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_202_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_202_2 + 1) & 15;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = ((pub_r001675_6_1 * 2) + 47) & 63;
  int stage_v_203_2 = ((pub_r001675_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001675_16_1 * 2) + 27) & 63;
  int stage_v_204_2 = ((pub_r001675_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((helper_flow_1_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_205_2 = ((helper_flow_1_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_205_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_205_2 + 1) & 15;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = ((pub_r001675_16_1 * 2) + 13) & 63;
  int stage_v_206_2 = ((pub_r001675_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001675_14_1 * 2) + 14) & 63;
  int stage_v_207_2 = ((pub_r001675_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_134_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_208_2 = ((stage_v_134_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_208_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_208_2 + 1) & 15;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = ((stage_v_12_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_209_2 = ((stage_v_12_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_209_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_209_2 + 1) & 15;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = ((pub_r001675_8_1 * 2) + 20) & 63;
  int stage_v_210_2 = ((pub_r001675_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_146_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_211_2 = ((stage_v_146_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_211_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_211_2 + 1) & 15;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = ((stage_v_191_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_212_2 = ((stage_v_191_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_212_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_212_2 + 1) & 15;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = ((helper_flow_2_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_213_2 = ((helper_flow_2_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_213_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_213_2 + 1) & 15;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = ((pub_r001675_8_1 * 2) + 31) & 63;
  int stage_v_214_2 = ((pub_r001675_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001675_6_1 * 2) + 43) & 63;
  int stage_v_215_2 = ((pub_r001675_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001675_6_1 * 2) + 38) & 63;
  int stage_v_216_2 = ((pub_r001675_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001675_4_1 * 2) + 17) & 63;
  int stage_v_217_2 = ((pub_r001675_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001675_16_1 * 2) + 5) & 63;
  int stage_v_218_2 = ((pub_r001675_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((stage_v_83_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_219_2 = ((stage_v_83_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_219_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_219_2 + 1) & 15;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = ((pub_r001675_7_1 * 2) + 18) & 63;
  int stage_v_220_2 = ((pub_r001675_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((sec_r001675_16_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_221_2 = ((sec_r001675_16_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_221_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_221_2 + 1) & 15;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = ((stage_v_201_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_222_2 = ((stage_v_201_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_222_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_222_2 + 1) & 15;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = ((pub_r001675_15_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001675_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_27_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_224_2 = ((stage_v_27_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_224_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_224_2 + 1) & 15;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = ((sec_r001675_5_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_225_2 = ((sec_r001675_5_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_225_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_225_2 + 1) & 15;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = ((stage_v_17_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_226_2 = ((stage_v_17_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_226_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_226_2 + 1) & 15;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = ((stage_v_170_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_227_2 = ((stage_v_170_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_227_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_227_2 + 1) & 15;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = ((stage_v_126_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_228_2 = ((stage_v_126_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_228_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_228_2 + 1) & 15;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = ((pub_r001675_11_1 * 2) + 50) & 63;
  int stage_v_229_2 = ((pub_r001675_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_116_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_230_2 = ((stage_v_116_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_230_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_230_2 + 1) & 15;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = ((pub_r001675_0_1 * 2) + 40) & 63;
  int stage_v_231_2 = ((pub_r001675_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_38_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_232_2 = ((stage_v_38_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_232_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_232_2 + 1) & 15;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = ((pub_r001675_7_1 * 2) + 22) & 63;
  int stage_v_233_2 = ((pub_r001675_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((helper_flow_5_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_234_2 = ((helper_flow_5_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_234_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_234_2 + 1) & 15;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = ((stage_v_205_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_235_2 = ((stage_v_205_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_235_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_235_2 + 1) & 15;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = ((stage_v_5_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_236_2 = ((stage_v_5_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_236_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_236_2 + 1) & 15;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = ((stage_v_57_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_237_2 = ((stage_v_57_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_237_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_237_2 + 1) & 15;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = ((stage_v_28_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_238_2 = ((stage_v_28_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_238_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_238_2 + 1) & 15;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = ((stage_v_129_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_239_2 = ((stage_v_129_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_239_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_239_2 + 1) & 15;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = ((pub_r001675_8_1 * 2) + 9) & 63;
  int stage_v_240_2 = ((pub_r001675_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = ((pub_r001675_2_1 * 2) + 17) & 63;
  int stage_v_241_2 = ((pub_r001675_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((stage_v_133_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_242_2 = ((stage_v_133_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_242_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_242_2 + 1) & 15;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = ((stage_v_44_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_243_2 = ((stage_v_44_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_243_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_243_2 + 1) & 15;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = ((pub_r001675_13_1 * 2) + 28) & 63;
  int stage_v_244_2 = ((pub_r001675_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((stage_v_234_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_245_2 = ((stage_v_234_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_245_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_245_2 + 1) & 15;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = ((pub_r001675_6_1 * 2) + 14) & 63;
  int stage_v_246_2 = ((pub_r001675_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001675_8_1 * 2) + 19) & 63;
  int stage_v_247_2 = ((pub_r001675_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001675_0_1 * 2) + 18) & 63;
  int stage_v_248_2 = ((pub_r001675_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_196_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_249_2 = ((stage_v_196_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_249_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_249_2 + 1) & 15;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = ((stage_v_122_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_250_2 = ((stage_v_122_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_250_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_250_2 + 1) & 15;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = ((pub_r001675_3_1 * 2) + 7) & 63;
  int stage_v_251_2 = ((pub_r001675_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((stage_v_149_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_252_2 = ((stage_v_149_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_252_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_252_2 + 1) & 15;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = ((stage_v_209_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_253_2 = ((stage_v_209_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_253_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_253_2 + 1) & 15;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = ((stage_v_12_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_254_2 = ((stage_v_12_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_254_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_254_2 + 1) & 15;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = ((stage_v_41_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_255_2 = ((stage_v_41_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_255_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_255_2 + 1) & 15;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = ((pub_r001675_1_1 * 2) + 36) & 63;
  int stage_v_256_2 = ((pub_r001675_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((sec_r001675_11_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_257_2 = ((sec_r001675_11_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_257_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_257_2 + 1) & 15;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = ((pub_r001675_12_1 * 2) + 42) & 63;
  int stage_v_258_2 = ((pub_r001675_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((stage_v_119_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_259_2 = ((stage_v_119_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_259_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_259_2 + 1) & 15;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = ((pub_r001675_3_1 * 2) + 48) & 63;
  int stage_v_260_2 = ((pub_r001675_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001675_7_1 * 2) + 9) & 63;
  int stage_v_261_2 = ((pub_r001675_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001675_8_1 * 2) + 10) & 63;
  int stage_v_262_2 = ((pub_r001675_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001675_15_1 * 2) + 19) & 63;
  int stage_v_263_2 = ((pub_r001675_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = ((sec_r001675_11_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_264_2 = ((sec_r001675_11_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_264_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_264_2 + 1) & 15;
  out_sink_1 ^= stage_v_264_1 & 63;
  out_sink_2 ^= stage_v_264_2 & 63;
  int stage_v_265_1 = ((stage_v_225_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_265_2 = ((stage_v_225_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_265_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_265_2 + 1) & 15;
  out_sink_1 ^= stage_v_265_1 & 63;
  out_sink_2 ^= stage_v_265_2 & 63;
  int stage_v_266_1 = ((pub_r001675_6_1 * 2) + 41) & 63;
  int stage_v_266_2 = ((pub_r001675_6_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_70_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_267_2 = ((stage_v_70_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_267_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_267_2 + 1) & 15;
  out_sink_1 ^= stage_v_267_1 & 63;
  out_sink_2 ^= stage_v_267_2 & 63;
  int stage_v_268_1 = ((pub_r001675_8_1 * 2) + 14) & 63;
  int stage_v_268_2 = ((pub_r001675_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((stage_v_159_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_269_2 = ((stage_v_159_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_269_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_269_2 + 1) & 15;
  out_sink_1 ^= stage_v_269_1 & 63;
  out_sink_2 ^= stage_v_269_2 & 63;
  int stage_v_270_1 = ((pub_r001675_18_1 * 2) + 12) & 63;
  int stage_v_270_2 = ((pub_r001675_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001675_6_1 * 2) + 49) & 63;
  int stage_v_271_2 = ((pub_r001675_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((stage_v_66_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_272_2 = ((stage_v_66_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_272_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_272_2 + 1) & 15;
  out_sink_1 ^= stage_v_272_1 & 63;
  out_sink_2 ^= stage_v_272_2 & 63;
  int stage_v_273_1 = ((stage_v_88_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_273_2 = ((stage_v_88_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_273_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_273_2 + 1) & 15;
  out_sink_1 ^= stage_v_273_1 & 63;
  out_sink_2 ^= stage_v_273_2 & 63;
  int stage_v_274_1 = ((pub_r001675_10_1 * 2) + 8) & 63;
  int stage_v_274_2 = ((pub_r001675_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001675_15_1 * 2) + 44) & 63;
  int stage_v_275_2 = ((pub_r001675_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((stage_v_38_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_276_2 = ((stage_v_38_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_276_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_276_2 + 1) & 15;
  out_sink_1 ^= stage_v_276_1 & 63;
  out_sink_2 ^= stage_v_276_2 & 63;
  int stage_v_277_1 = ((stage_v_40_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_277_2 = ((stage_v_40_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_277_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_277_2 + 1) & 15;
  out_sink_1 ^= stage_v_277_1 & 63;
  out_sink_2 ^= stage_v_277_2 & 63;
  int stage_v_278_1 = ((pub_r001675_13_1 * 2) + 8) & 63;
  int stage_v_278_2 = ((pub_r001675_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001675_13_1 * 2) + 43) & 63;
  int stage_v_279_2 = ((pub_r001675_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001675_12_1 * 2) + 35) & 63;
  int stage_v_280_2 = ((pub_r001675_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001675_11_1 * 2) + 50) & 63;
  int stage_v_281_2 = ((pub_r001675_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((stage_v_225_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_282_2 = ((stage_v_225_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_282_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_282_2 + 1) & 15;
  out_sink_1 ^= stage_v_282_1 & 63;
  out_sink_2 ^= stage_v_282_2 & 63;
  int stage_v_283_1 = ((stage_v_82_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_283_2 = ((stage_v_82_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_283_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_283_2 + 1) & 15;
  out_sink_1 ^= stage_v_283_1 & 63;
  out_sink_2 ^= stage_v_283_2 & 63;
  int stage_v_284_1 = ((pub_r001675_7_1 * 2) + 43) & 63;
  int stage_v_284_2 = ((pub_r001675_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001675_1_1 * 2) + 28) & 63;
  int stage_v_285_2 = ((pub_r001675_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((stage_v_163_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_286_2 = ((stage_v_163_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_286_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_286_2 + 1) & 15;
  out_sink_1 ^= stage_v_286_1 & 63;
  out_sink_2 ^= stage_v_286_2 & 63;
  int stage_v_287_1 = ((pub_r001675_10_1 * 2) + 24) & 63;
  int stage_v_287_2 = ((pub_r001675_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001675_1_1 * 2) + 13) & 63;
  int stage_v_288_2 = ((pub_r001675_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((stage_v_209_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_289_2 = ((stage_v_209_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_289_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_289_2 + 1) & 15;
  out_sink_1 ^= stage_v_289_1 & 63;
  out_sink_2 ^= stage_v_289_2 & 63;
  int stage_v_290_1 = ((stage_v_126_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_290_2 = ((stage_v_126_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_290_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_290_2 + 1) & 15;
  out_sink_1 ^= stage_v_290_1 & 63;
  out_sink_2 ^= stage_v_290_2 & 63;
  int stage_v_291_1 = ((stage_v_18_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_291_2 = ((stage_v_18_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_291_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_291_2 + 1) & 15;
  out_sink_1 ^= stage_v_291_1 & 63;
  out_sink_2 ^= stage_v_291_2 & 63;
  int stage_v_292_1 = ((pub_r001675_9_1 * 2) + 9) & 63;
  int stage_v_292_2 = ((pub_r001675_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001675_11_1 * 2) + 47) & 63;
  int stage_v_293_2 = ((pub_r001675_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001675_15_1 * 2) + 17) & 63;
  int stage_v_294_2 = ((pub_r001675_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((helper_flow_3_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_295_2 = ((helper_flow_3_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_295_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_295_2 + 1) & 15;
  out_sink_1 ^= stage_v_295_1 & 63;
  out_sink_2 ^= stage_v_295_2 & 63;
  int stage_v_296_1 = ((stage_v_198_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_296_2 = ((stage_v_198_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_296_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_296_2 + 1) & 15;
  out_sink_1 ^= stage_v_296_1 & 63;
  out_sink_2 ^= stage_v_296_2 & 63;
  int stage_v_297_1 = ((helper_flow_1_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_297_2 = ((helper_flow_1_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_297_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_297_2 + 1) & 15;
  out_sink_1 ^= stage_v_297_1 & 63;
  out_sink_2 ^= stage_v_297_2 & 63;
  int stage_v_298_1 = ((stage_v_45_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_298_2 = ((stage_v_45_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_298_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_298_2 + 1) & 15;
  out_sink_1 ^= stage_v_298_1 & 63;
  out_sink_2 ^= stage_v_298_2 & 63;
  int stage_v_299_1 = ((stage_v_170_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_299_2 = ((stage_v_170_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_299_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_299_2 + 1) & 15;
  out_sink_1 ^= stage_v_299_1 & 63;
  out_sink_2 ^= stage_v_299_2 & 63;
  int stage_v_300_1 = ((stage_v_8_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_300_2 = ((stage_v_8_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_300_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_300_2 + 1) & 15;
  out_sink_1 ^= stage_v_300_1 & 63;
  out_sink_2 ^= stage_v_300_2 & 63;
  int stage_v_301_1 = ((pub_r001675_3_1 * 2) + 5) & 63;
  int stage_v_301_2 = ((pub_r001675_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = ((pub_r001675_15_1 * 2) + 18) & 63;
  int stage_v_302_2 = ((pub_r001675_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001675_7_1 * 2) + 10) & 63;
  int stage_v_303_2 = ((pub_r001675_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((stage_v_109_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_304_2 = ((stage_v_109_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_304_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_304_2 + 1) & 15;
  out_sink_1 ^= stage_v_304_1 & 63;
  out_sink_2 ^= stage_v_304_2 & 63;
  int stage_v_305_1 = ((pub_r001675_10_1 * 2) + 48) & 63;
  int stage_v_305_2 = ((pub_r001675_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((stage_v_259_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_306_2 = ((stage_v_259_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_306_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_306_2 + 1) & 15;
  out_sink_1 ^= stage_v_306_1 & 63;
  out_sink_2 ^= stage_v_306_2 & 63;
  int stage_v_307_1 = ((sec_r001675_0_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_307_2 = ((sec_r001675_0_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_307_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_307_2 + 1) & 15;
  out_sink_1 ^= stage_v_307_1 & 63;
  out_sink_2 ^= stage_v_307_2 & 63;
  int stage_v_308_1 = ((stage_v_10_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_308_2 = ((stage_v_10_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_308_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_308_2 + 1) & 15;
  out_sink_1 ^= stage_v_308_1 & 63;
  out_sink_2 ^= stage_v_308_2 & 63;
  int stage_v_309_1 = ((pub_r001675_12_1 * 2) + 38) & 63;
  int stage_v_309_2 = ((pub_r001675_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((stage_v_92_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_310_2 = ((stage_v_92_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_310_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_310_2 + 1) & 15;
  out_sink_1 ^= stage_v_310_1 & 63;
  out_sink_2 ^= stage_v_310_2 & 63;
  int stage_v_311_1 = ((pub_r001675_6_1 * 2) + 38) & 63;
  int stage_v_311_2 = ((pub_r001675_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((stage_v_49_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_312_2 = ((stage_v_49_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_312_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_312_2 + 1) & 15;
  out_sink_1 ^= stage_v_312_1 & 63;
  out_sink_2 ^= stage_v_312_2 & 63;
  int stage_v_313_1 = ((stage_v_191_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_313_2 = ((stage_v_191_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_313_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_313_2 + 1) & 15;
  out_sink_1 ^= stage_v_313_1 & 63;
  out_sink_2 ^= stage_v_313_2 & 63;
  int stage_v_314_1 = ((pub_r001675_3_1 * 2) + 32) & 63;
  int stage_v_314_2 = ((pub_r001675_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((stage_v_253_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_315_2 = ((stage_v_253_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_315_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_315_2 + 1) & 15;
  out_sink_1 ^= stage_v_315_1 & 63;
  out_sink_2 ^= stage_v_315_2 & 63;
  int stage_v_316_1 = ((stage_v_10_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_316_2 = ((stage_v_10_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_316_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_316_2 + 1) & 15;
  out_sink_1 ^= stage_v_316_1 & 63;
  out_sink_2 ^= stage_v_316_2 & 63;
  int stage_v_317_1 = ((pub_r001675_17_1 * 2) + 15) & 63;
  int stage_v_317_2 = ((pub_r001675_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((stage_v_237_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_318_2 = ((stage_v_237_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_318_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_318_2 + 1) & 15;
  out_sink_1 ^= stage_v_318_1 & 63;
  out_sink_2 ^= stage_v_318_2 & 63;
  int stage_v_319_1 = ((pub_r001675_6_1 * 2) + 20) & 63;
  int stage_v_319_2 = ((pub_r001675_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((stage_v_156_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_320_2 = ((stage_v_156_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_320_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_320_2 + 1) & 15;
  out_sink_1 ^= stage_v_320_1 & 63;
  out_sink_2 ^= stage_v_320_2 & 63;
  int stage_v_321_1 = ((pub_r001675_6_1 * 2) + 33) & 63;
  int stage_v_321_2 = ((pub_r001675_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((stage_v_48_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_322_2 = ((stage_v_48_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_322_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_322_2 + 1) & 15;
  out_sink_1 ^= stage_v_322_1 & 63;
  out_sink_2 ^= stage_v_322_2 & 63;
  int stage_v_323_1 = ((stage_v_318_1 << 1) ^ (pub_r001675_16_1 >> 1)) & 127;
  int stage_v_323_2 = ((stage_v_318_2 << 1) ^ (pub_r001675_16_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_323_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_323_2 + 1) & 15;
  out_sink_1 ^= stage_v_323_1 & 63;
  out_sink_2 ^= stage_v_323_2 & 63;
  int stage_v_324_1 = ((pub_r001675_8_1 * 2) + 16) & 63;
  int stage_v_324_2 = ((pub_r001675_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((helper_flow_3_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_325_2 = ((helper_flow_3_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_325_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_325_2 + 1) & 15;
  out_sink_1 ^= stage_v_325_1 & 63;
  out_sink_2 ^= stage_v_325_2 & 63;
  int stage_v_326_1 = ((helper_flow_4_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_326_2 = ((helper_flow_4_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_326_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_326_2 + 1) & 15;
  out_sink_1 ^= stage_v_326_1 & 63;
  out_sink_2 ^= stage_v_326_2 & 63;
  int stage_v_327_1 = ((stage_v_11_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_327_2 = ((stage_v_11_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_327_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_327_2 + 1) & 15;
  out_sink_1 ^= stage_v_327_1 & 63;
  out_sink_2 ^= stage_v_327_2 & 63;
  int stage_v_328_1 = ((stage_v_290_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_328_2 = ((stage_v_290_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_328_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_328_2 + 1) & 15;
  out_sink_1 ^= stage_v_328_1 & 63;
  out_sink_2 ^= stage_v_328_2 & 63;
  int stage_v_329_1 = ((stage_v_182_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_329_2 = ((stage_v_182_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_329_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_329_2 + 1) & 15;
  out_sink_1 ^= stage_v_329_1 & 63;
  out_sink_2 ^= stage_v_329_2 & 63;
  int stage_v_330_1 = ((stage_v_56_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_330_2 = ((stage_v_56_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_330_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_330_2 + 1) & 15;
  out_sink_1 ^= stage_v_330_1 & 63;
  out_sink_2 ^= stage_v_330_2 & 63;
  int stage_v_331_1 = ((pub_r001675_12_1 * 2) + 44) & 63;
  int stage_v_331_2 = ((pub_r001675_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001675_16_1 * 2) + 33) & 63;
  int stage_v_332_2 = ((pub_r001675_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001675_6_1 * 2) + 13) & 63;
  int stage_v_333_2 = ((pub_r001675_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((stage_v_265_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_334_2 = ((stage_v_265_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_334_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_334_2 + 1) & 15;
  out_sink_1 ^= stage_v_334_1 & 63;
  out_sink_2 ^= stage_v_334_2 & 63;
  int stage_v_335_1 = ((stage_v_81_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_335_2 = ((stage_v_81_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_335_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_335_2 + 1) & 15;
  out_sink_1 ^= stage_v_335_1 & 63;
  out_sink_2 ^= stage_v_335_2 & 63;
  int stage_v_336_1 = ((pub_r001675_9_1 * 2) + 8) & 63;
  int stage_v_336_2 = ((pub_r001675_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001675_6_1 * 2) + 47) & 63;
  int stage_v_337_2 = ((pub_r001675_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((sec_r001675_19_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_338_2 = ((sec_r001675_19_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_338_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_338_2 + 1) & 15;
  out_sink_1 ^= stage_v_338_1 & 63;
  out_sink_2 ^= stage_v_338_2 & 63;
  int stage_v_339_1 = ((pub_r001675_10_1 * 2) + 41) & 63;
  int stage_v_339_2 = ((pub_r001675_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((stage_v_141_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_340_2 = ((stage_v_141_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_340_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_340_2 + 1) & 15;
  out_sink_1 ^= stage_v_340_1 & 63;
  out_sink_2 ^= stage_v_340_2 & 63;
  int stage_v_341_1 = ((stage_v_335_1 << 1) ^ (pub_r001675_6_1 >> 1)) & 127;
  int stage_v_341_2 = ((stage_v_335_2 << 1) ^ (pub_r001675_6_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_341_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_341_2 + 1) & 15;
  out_sink_1 ^= stage_v_341_1 & 63;
  out_sink_2 ^= stage_v_341_2 & 63;
  int stage_v_342_1 = ((sec_r001675_9_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_342_2 = ((sec_r001675_9_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_342_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_342_2 + 1) & 15;
  out_sink_1 ^= stage_v_342_1 & 63;
  out_sink_2 ^= stage_v_342_2 & 63;
  int stage_v_343_1 = ((pub_r001675_3_1 * 2) + 49) & 63;
  int stage_v_343_2 = ((pub_r001675_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001675_15_1 * 2) + 26) & 63;
  int stage_v_344_2 = ((pub_r001675_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = ((sec_r001675_6_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_345_2 = ((sec_r001675_6_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_345_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_345_2 + 1) & 15;
  out_sink_1 ^= stage_v_345_1 & 63;
  out_sink_2 ^= stage_v_345_2 & 63;
  int stage_v_346_1 = ((pub_r001675_4_1 * 2) + 37) & 63;
  int stage_v_346_2 = ((pub_r001675_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((sec_r001675_6_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_347_2 = ((sec_r001675_6_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_347_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_347_2 + 1) & 15;
  out_sink_1 ^= stage_v_347_1 & 63;
  out_sink_2 ^= stage_v_347_2 & 63;
  int stage_v_348_1 = ((pub_r001675_4_1 * 2) + 14) & 63;
  int stage_v_348_2 = ((pub_r001675_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((stage_v_130_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_349_2 = ((stage_v_130_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_349_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_349_2 + 1) & 15;
  out_sink_1 ^= stage_v_349_1 & 63;
  out_sink_2 ^= stage_v_349_2 & 63;
  int stage_v_350_1 = ((stage_v_252_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_350_2 = ((stage_v_252_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_350_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_350_2 + 1) & 15;
  out_sink_1 ^= stage_v_350_1 & 63;
  out_sink_2 ^= stage_v_350_2 & 63;
  int stage_v_351_1 = ((pub_r001675_17_1 * 2) + 12) & 63;
  int stage_v_351_2 = ((pub_r001675_17_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = ((stage_v_211_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_352_2 = ((stage_v_211_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_352_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_352_2 + 1) & 15;
  out_sink_1 ^= stage_v_352_1 & 63;
  out_sink_2 ^= stage_v_352_2 & 63;
  int stage_v_353_1 = ((pub_r001675_6_1 * 2) + 11) & 63;
  int stage_v_353_2 = ((pub_r001675_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001675_17_1 * 2) + 41) & 63;
  int stage_v_354_2 = ((pub_r001675_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((stage_v_3_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_355_2 = ((stage_v_3_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_355_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_355_2 + 1) & 15;
  out_sink_1 ^= stage_v_355_1 & 63;
  out_sink_2 ^= stage_v_355_2 & 63;
  int stage_v_356_1 = ((pub_r001675_0_1 * 2) + 7) & 63;
  int stage_v_356_2 = ((pub_r001675_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001675_2_1 * 2) + 34) & 63;
  int stage_v_357_2 = ((pub_r001675_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001675_15_1 * 2) + 23) & 63;
  int stage_v_358_2 = ((pub_r001675_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((stage_v_31_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_359_2 = ((stage_v_31_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_359_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_359_2 + 1) & 15;
  out_sink_1 ^= stage_v_359_1 & 63;
  out_sink_2 ^= stage_v_359_2 & 63;
  int stage_v_360_1 = ((helper_flow_0_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_360_2 = ((helper_flow_0_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_360_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_360_2 + 1) & 15;
  out_sink_1 ^= stage_v_360_1 & 63;
  out_sink_2 ^= stage_v_360_2 & 63;
  int stage_v_361_1 = ((pub_r001675_13_1 * 2) + 16) & 63;
  int stage_v_361_2 = ((pub_r001675_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001675_14_1 * 2) + 25) & 63;
  int stage_v_362_2 = ((pub_r001675_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = ((stage_v_149_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_363_2 = ((stage_v_149_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_363_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_363_2 + 1) & 15;
  out_sink_1 ^= stage_v_363_1 & 63;
  out_sink_2 ^= stage_v_363_2 & 63;
  int stage_v_364_1 = ((stage_v_300_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_364_2 = ((stage_v_300_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_364_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_364_2 + 1) & 15;
  out_sink_1 ^= stage_v_364_1 & 63;
  out_sink_2 ^= stage_v_364_2 & 63;
  int stage_v_365_1 = ((stage_v_310_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_365_2 = ((stage_v_310_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_365_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_365_2 + 1) & 15;
  out_sink_1 ^= stage_v_365_1 & 63;
  out_sink_2 ^= stage_v_365_2 & 63;
  int stage_v_366_1 = ((stage_v_9_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_366_2 = ((stage_v_9_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_366_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_366_2 + 1) & 15;
  out_sink_1 ^= stage_v_366_1 & 63;
  out_sink_2 ^= stage_v_366_2 & 63;
  int stage_v_367_1 = ((pub_r001675_12_1 * 2) + 45) & 63;
  int stage_v_367_2 = ((pub_r001675_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001675_9_1 * 2) + 10) & 63;
  int stage_v_368_2 = ((pub_r001675_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001675_8_1 * 2) + 12) & 63;
  int stage_v_369_2 = ((pub_r001675_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((stage_v_286_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_370_2 = ((stage_v_286_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_370_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_370_2 + 1) & 15;
  out_sink_1 ^= stage_v_370_1 & 63;
  out_sink_2 ^= stage_v_370_2 & 63;
  int stage_v_371_1 = ((pub_r001675_6_1 * 2) + 16) & 63;
  int stage_v_371_2 = ((pub_r001675_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((stage_v_14_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_372_2 = ((stage_v_14_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_372_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_372_2 + 1) & 15;
  out_sink_1 ^= stage_v_372_1 & 63;
  out_sink_2 ^= stage_v_372_2 & 63;
  int stage_v_373_1 = ((pub_r001675_3_1 * 2) + 49) & 63;
  int stage_v_373_2 = ((pub_r001675_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((stage_v_290_1 << 1) ^ (pub_r001675_7_1 >> 1)) & 127;
  int stage_v_374_2 = ((stage_v_290_2 << 1) ^ (pub_r001675_7_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_374_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_374_2 + 1) & 15;
  out_sink_1 ^= stage_v_374_1 & 63;
  out_sink_2 ^= stage_v_374_2 & 63;
  int stage_v_375_1 = ((pub_r001675_10_1 * 2) + 25) & 63;
  int stage_v_375_2 = ((pub_r001675_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((stage_v_340_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_376_2 = ((stage_v_340_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_376_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_376_2 + 1) & 15;
  out_sink_1 ^= stage_v_376_1 & 63;
  out_sink_2 ^= stage_v_376_2 & 63;
  int stage_v_377_1 = ((pub_r001675_9_1 * 2) + 8) & 63;
  int stage_v_377_2 = ((pub_r001675_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((stage_v_66_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_378_2 = ((stage_v_66_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_378_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_378_2 + 1) & 15;
  out_sink_1 ^= stage_v_378_1 & 63;
  out_sink_2 ^= stage_v_378_2 & 63;
  int stage_v_379_1 = ((stage_v_108_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_379_2 = ((stage_v_108_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_379_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_379_2 + 1) & 15;
  out_sink_1 ^= stage_v_379_1 & 63;
  out_sink_2 ^= stage_v_379_2 & 63;
  int stage_v_380_1 = ((stage_v_316_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_380_2 = ((stage_v_316_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_380_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_380_2 + 1) & 15;
  out_sink_1 ^= stage_v_380_1 & 63;
  out_sink_2 ^= stage_v_380_2 & 63;
  int stage_v_381_1 = ((stage_v_295_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_381_2 = ((stage_v_295_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_381_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_381_2 + 1) & 15;
  out_sink_1 ^= stage_v_381_1 & 63;
  out_sink_2 ^= stage_v_381_2 & 63;
  int stage_v_382_1 = ((pub_r001675_6_1 * 2) + 47) & 63;
  int stage_v_382_2 = ((pub_r001675_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((stage_v_315_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_383_2 = ((stage_v_315_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_383_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_383_2 + 1) & 15;
  out_sink_1 ^= stage_v_383_1 & 63;
  out_sink_2 ^= stage_v_383_2 & 63;
  int stage_v_384_1 = ((stage_v_259_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_384_2 = ((stage_v_259_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_384_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_384_2 + 1) & 15;
  out_sink_1 ^= stage_v_384_1 & 63;
  out_sink_2 ^= stage_v_384_2 & 63;
  int stage_v_385_1 = ((pub_r001675_8_1 * 2) + 13) & 63;
  int stage_v_385_2 = ((pub_r001675_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001675_1_1 * 2) + 49) & 63;
  int stage_v_386_2 = ((pub_r001675_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001675_10_1 * 2) + 8) & 63;
  int stage_v_387_2 = ((pub_r001675_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001675_18_1 * 2) + 37) & 63;
  int stage_v_388_2 = ((pub_r001675_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((stage_v_77_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_389_2 = ((stage_v_77_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_389_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_389_2 + 1) & 15;
  out_sink_1 ^= stage_v_389_1 & 63;
  out_sink_2 ^= stage_v_389_2 & 63;
  int stage_v_390_1 = ((pub_r001675_16_1 * 2) + 8) & 63;
  int stage_v_390_2 = ((pub_r001675_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((stage_v_222_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_391_2 = ((stage_v_222_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_391_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_391_2 + 1) & 15;
  out_sink_1 ^= stage_v_391_1 & 63;
  out_sink_2 ^= stage_v_391_2 & 63;
  int stage_v_392_1 = ((stage_v_54_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_392_2 = ((stage_v_54_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_392_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_392_2 + 1) & 15;
  out_sink_1 ^= stage_v_392_1 & 63;
  out_sink_2 ^= stage_v_392_2 & 63;
  int stage_v_393_1 = ((stage_v_167_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_393_2 = ((stage_v_167_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_393_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_393_2 + 1) & 15;
  out_sink_1 ^= stage_v_393_1 & 63;
  out_sink_2 ^= stage_v_393_2 & 63;
  int stage_v_394_1 = ((pub_r001675_11_1 * 2) + 10) & 63;
  int stage_v_394_2 = ((pub_r001675_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((stage_v_307_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_395_2 = ((stage_v_307_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_395_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_395_2 + 1) & 15;
  out_sink_1 ^= stage_v_395_1 & 63;
  out_sink_2 ^= stage_v_395_2 & 63;
  int stage_v_396_1 = ((stage_v_10_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_396_2 = ((stage_v_10_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_396_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_396_2 + 1) & 15;
  out_sink_1 ^= stage_v_396_1 & 63;
  out_sink_2 ^= stage_v_396_2 & 63;
  int stage_v_397_1 = ((pub_r001675_10_1 * 2) + 14) & 63;
  int stage_v_397_2 = ((pub_r001675_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((stage_v_222_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_398_2 = ((stage_v_222_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_398_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_398_2 + 1) & 15;
  out_sink_1 ^= stage_v_398_1 & 63;
  out_sink_2 ^= stage_v_398_2 & 63;
  int stage_v_399_1 = ((stage_v_330_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_399_2 = ((stage_v_330_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_399_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_399_2 + 1) & 15;
  out_sink_1 ^= stage_v_399_1 & 63;
  out_sink_2 ^= stage_v_399_2 & 63;
  int stage_v_400_1 = ((pub_r001675_8_1 * 2) + 45) & 63;
  int stage_v_400_2 = ((pub_r001675_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((stage_v_338_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_401_2 = ((stage_v_338_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_401_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_401_2 + 1) & 15;
  out_sink_1 ^= stage_v_401_1 & 63;
  out_sink_2 ^= stage_v_401_2 & 63;
  int stage_v_402_1 = ((stage_v_304_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_402_2 = ((stage_v_304_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_402_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_402_2 + 1) & 15;
  out_sink_1 ^= stage_v_402_1 & 63;
  out_sink_2 ^= stage_v_402_2 & 63;
  int stage_v_403_1 = ((sec_r001675_8_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_403_2 = ((sec_r001675_8_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_403_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_403_2 + 1) & 15;
  out_sink_1 ^= stage_v_403_1 & 63;
  out_sink_2 ^= stage_v_403_2 & 63;
  int stage_v_404_1 = ((stage_v_129_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_404_2 = ((stage_v_129_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_404_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_404_2 + 1) & 15;
  out_sink_1 ^= stage_v_404_1 & 63;
  out_sink_2 ^= stage_v_404_2 & 63;
  int stage_v_405_1 = ((pub_r001675_2_1 * 2) + 14) & 63;
  int stage_v_405_2 = ((pub_r001675_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((stage_v_163_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_406_2 = ((stage_v_163_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_406_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_406_2 + 1) & 15;
  out_sink_1 ^= stage_v_406_1 & 63;
  out_sink_2 ^= stage_v_406_2 & 63;
  int stage_v_407_1 = ((pub_r001675_15_1 * 2) + 23) & 63;
  int stage_v_407_2 = ((pub_r001675_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001675_17_1 * 2) + 49) & 63;
  int stage_v_408_2 = ((pub_r001675_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((stage_v_399_1 << 1) ^ (pub_r001675_18_1 >> 1)) & 127;
  int stage_v_409_2 = ((stage_v_399_2 << 1) ^ (pub_r001675_18_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_409_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_409_2 + 1) & 15;
  out_sink_1 ^= stage_v_409_1 & 63;
  out_sink_2 ^= stage_v_409_2 & 63;
  int stage_v_410_1 = ((stage_v_128_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_410_2 = ((stage_v_128_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_410_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_410_2 + 1) & 15;
  out_sink_1 ^= stage_v_410_1 & 63;
  out_sink_2 ^= stage_v_410_2 & 63;
  int stage_v_411_1 = ((pub_r001675_4_1 * 2) + 16) & 63;
  int stage_v_411_2 = ((pub_r001675_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((stage_v_11_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_412_2 = ((stage_v_11_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_412_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_412_2 + 1) & 15;
  out_sink_1 ^= stage_v_412_1 & 63;
  out_sink_2 ^= stage_v_412_2 & 63;
  int stage_v_413_1 = ((pub_r001675_10_1 * 2) + 42) & 63;
  int stage_v_413_2 = ((pub_r001675_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001675_8_1 * 2) + 48) & 63;
  int stage_v_414_2 = ((pub_r001675_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = ((pub_r001675_12_1 * 2) + 30) & 63;
  int stage_v_415_2 = ((pub_r001675_12_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = ((pub_r001675_10_1 * 2) + 10) & 63;
  int stage_v_416_2 = ((pub_r001675_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001675_16_1 * 2) + 17) & 63;
  int stage_v_417_2 = ((pub_r001675_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001675_0_1 * 2) + 20) & 63;
  int stage_v_418_2 = ((pub_r001675_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((stage_v_58_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_419_2 = ((stage_v_58_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_419_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_419_2 + 1) & 15;
  out_sink_1 ^= stage_v_419_1 & 63;
  out_sink_2 ^= stage_v_419_2 & 63;
  int stage_v_420_1 = ((stage_v_225_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_420_2 = ((stage_v_225_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_420_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_420_2 + 1) & 15;
  out_sink_1 ^= stage_v_420_1 & 63;
  out_sink_2 ^= stage_v_420_2 & 63;
  int stage_v_421_1 = ((pub_r001675_0_1 * 2) + 12) & 63;
  int stage_v_421_2 = ((pub_r001675_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((stage_v_306_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_422_2 = ((stage_v_306_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_422_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_422_2 + 1) & 15;
  out_sink_1 ^= stage_v_422_1 & 63;
  out_sink_2 ^= stage_v_422_2 & 63;
  int stage_v_423_1 = ((pub_r001675_15_1 * 2) + 14) & 63;
  int stage_v_423_2 = ((pub_r001675_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = ((stage_v_38_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_424_2 = ((stage_v_38_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_424_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_424_2 + 1) & 15;
  out_sink_1 ^= stage_v_424_1 & 63;
  out_sink_2 ^= stage_v_424_2 & 63;
  int stage_v_425_1 = ((pub_r001675_18_1 * 2) + 15) & 63;
  int stage_v_425_2 = ((pub_r001675_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = ((pub_r001675_4_1 * 2) + 14) & 63;
  int stage_v_426_2 = ((pub_r001675_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((stage_v_403_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_427_2 = ((stage_v_403_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_427_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_427_2 + 1) & 15;
  out_sink_1 ^= stage_v_427_1 & 63;
  out_sink_2 ^= stage_v_427_2 & 63;
  int stage_v_428_1 = ((pub_r001675_9_1 * 2) + 12) & 63;
  int stage_v_428_2 = ((pub_r001675_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001675_5_1 * 2) + 26) & 63;
  int stage_v_429_2 = ((pub_r001675_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((stage_v_401_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_430_2 = ((stage_v_401_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_430_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_430_2 + 1) & 15;
  out_sink_1 ^= stage_v_430_1 & 63;
  out_sink_2 ^= stage_v_430_2 & 63;
  int stage_v_431_1 = ((stage_v_153_1 << 1) ^ (pub_r001675_12_1 >> 1)) & 127;
  int stage_v_431_2 = ((stage_v_153_2 << 1) ^ (pub_r001675_12_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_431_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_431_2 + 1) & 15;
  out_sink_1 ^= stage_v_431_1 & 63;
  out_sink_2 ^= stage_v_431_2 & 63;
  int stage_v_432_1 = ((stage_v_306_1 << 1) ^ (pub_r001675_14_1 >> 1)) & 127;
  int stage_v_432_2 = ((stage_v_306_2 << 1) ^ (pub_r001675_14_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_432_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_432_2 + 1) & 15;
  out_sink_1 ^= stage_v_432_1 & 63;
  out_sink_2 ^= stage_v_432_2 & 63;
  int stage_v_433_1 = ((pub_r001675_3_1 * 2) + 49) & 63;
  int stage_v_433_2 = ((pub_r001675_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = ((pub_r001675_15_1 * 2) + 33) & 63;
  int stage_v_434_2 = ((pub_r001675_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001675_11_1 * 2) + 10) & 63;
  int stage_v_435_2 = ((pub_r001675_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((stage_v_59_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_436_2 = ((stage_v_59_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_436_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_436_2 + 1) & 15;
  out_sink_1 ^= stage_v_436_1 & 63;
  out_sink_2 ^= stage_v_436_2 & 63;
  int stage_v_437_1 = ((stage_v_34_1 << 1) ^ (pub_r001675_11_1 >> 1)) & 127;
  int stage_v_437_2 = ((stage_v_34_2 << 1) ^ (pub_r001675_11_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_437_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_437_2 + 1) & 15;
  out_sink_1 ^= stage_v_437_1 & 63;
  out_sink_2 ^= stage_v_437_2 & 63;
  int stage_v_438_1 = ((pub_r001675_11_1 * 2) + 19) & 63;
  int stage_v_438_2 = ((pub_r001675_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((stage_v_54_1 << 1) ^ (pub_r001675_10_1 >> 1)) & 127;
  int stage_v_439_2 = ((stage_v_54_2 << 1) ^ (pub_r001675_10_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_439_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_439_2 + 1) & 15;
  out_sink_1 ^= stage_v_439_1 & 63;
  out_sink_2 ^= stage_v_439_2 & 63;
  int stage_v_440_1 = ((stage_v_10_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_440_2 = ((stage_v_10_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_440_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_440_2 + 1) & 15;
  out_sink_1 ^= stage_v_440_1 & 63;
  out_sink_2 ^= stage_v_440_2 & 63;
  int stage_v_441_1 = ((pub_r001675_7_1 * 2) + 46) & 63;
  int stage_v_441_2 = ((pub_r001675_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = ((stage_v_185_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_442_2 = ((stage_v_185_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_442_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_442_2 + 1) & 15;
  out_sink_1 ^= stage_v_442_1 & 63;
  out_sink_2 ^= stage_v_442_2 & 63;
  int stage_v_443_1 = ((stage_v_432_1 << 1) ^ (pub_r001675_0_1 >> 1)) & 127;
  int stage_v_443_2 = ((stage_v_432_2 << 1) ^ (pub_r001675_0_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_443_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_443_2 + 1) & 15;
  out_sink_1 ^= stage_v_443_1 & 63;
  out_sink_2 ^= stage_v_443_2 & 63;
  int stage_v_444_1 = ((stage_v_28_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_444_2 = ((stage_v_28_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_444_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_444_2 + 1) & 15;
  out_sink_1 ^= stage_v_444_1 & 63;
  out_sink_2 ^= stage_v_444_2 & 63;
  int stage_v_445_1 = ((stage_v_228_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_445_2 = ((stage_v_228_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_445_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_445_2 + 1) & 15;
  out_sink_1 ^= stage_v_445_1 & 63;
  out_sink_2 ^= stage_v_445_2 & 63;
  int stage_v_446_1 = ((pub_r001675_5_1 * 2) + 23) & 63;
  int stage_v_446_2 = ((pub_r001675_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = ((pub_r001675_14_1 * 2) + 44) & 63;
  int stage_v_447_2 = ((pub_r001675_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((stage_v_422_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_448_2 = ((stage_v_422_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_448_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_448_2 + 1) & 15;
  out_sink_1 ^= stage_v_448_1 & 63;
  out_sink_2 ^= stage_v_448_2 & 63;
  int stage_v_449_1 = ((stage_v_330_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_449_2 = ((stage_v_330_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_449_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_449_2 + 1) & 15;
  out_sink_1 ^= stage_v_449_1 & 63;
  out_sink_2 ^= stage_v_449_2 & 63;
  int stage_v_450_1 = ((stage_v_296_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_450_2 = ((stage_v_296_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_450_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_450_2 + 1) & 15;
  out_sink_1 ^= stage_v_450_1 & 63;
  out_sink_2 ^= stage_v_450_2 & 63;
  int stage_v_451_1 = ((pub_r001675_1_1 * 2) + 24) & 63;
  int stage_v_451_2 = ((pub_r001675_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = ((stage_v_125_1 << 1) ^ (pub_r001675_15_1 >> 1)) & 127;
  int stage_v_452_2 = ((stage_v_125_2 << 1) ^ (pub_r001675_15_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_452_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_452_2 + 1) & 15;
  out_sink_1 ^= stage_v_452_1 & 63;
  out_sink_2 ^= stage_v_452_2 & 63;
  int stage_v_453_1 = ((stage_v_327_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_453_2 = ((stage_v_327_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_453_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_453_2 + 1) & 15;
  out_sink_1 ^= stage_v_453_1 & 63;
  out_sink_2 ^= stage_v_453_2 & 63;
  int stage_v_454_1 = ((stage_v_364_1 << 1) ^ (pub_r001675_2_1 >> 1)) & 127;
  int stage_v_454_2 = ((stage_v_364_2 << 1) ^ (pub_r001675_2_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_454_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_454_2 + 1) & 15;
  out_sink_1 ^= stage_v_454_1 & 63;
  out_sink_2 ^= stage_v_454_2 & 63;
  int stage_v_455_1 = ((pub_r001675_9_1 * 2) + 17) & 63;
  int stage_v_455_2 = ((pub_r001675_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = ((pub_r001675_5_1 * 2) + 9) & 63;
  int stage_v_456_2 = ((pub_r001675_5_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_456_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_456_2) & 127;
  int stage_v_457_1 = ((stage_v_230_1 << 1) ^ (pub_r001675_4_1 >> 1)) & 127;
  int stage_v_457_2 = ((stage_v_230_2 << 1) ^ (pub_r001675_4_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_457_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_457_2 + 1) & 15;
  out_sink_1 ^= stage_v_457_1 & 63;
  out_sink_2 ^= stage_v_457_2 & 63;
  int stage_v_458_1 = ((stage_v_156_1 << 1) ^ (pub_r001675_1_1 >> 1)) & 127;
  int stage_v_458_2 = ((stage_v_156_2 << 1) ^ (pub_r001675_1_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_458_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_458_2 + 1) & 15;
  out_sink_1 ^= stage_v_458_1 & 63;
  out_sink_2 ^= stage_v_458_2 & 63;
  int stage_v_459_1 = ((pub_r001675_2_1 * 2) + 15) & 63;
  int stage_v_459_2 = ((pub_r001675_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001675_12_1 * 2) + 28) & 63;
  int stage_v_460_2 = ((pub_r001675_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((stage_v_396_1 << 1) ^ (pub_r001675_5_1 >> 1)) & 127;
  int stage_v_461_2 = ((stage_v_396_2 << 1) ^ (pub_r001675_5_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_461_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_461_2 + 1) & 15;
  out_sink_1 ^= stage_v_461_1 & 63;
  out_sink_2 ^= stage_v_461_2 & 63;
  int stage_v_462_1 = ((stage_v_82_1 << 1) ^ (pub_r001675_13_1 >> 1)) & 127;
  int stage_v_462_2 = ((stage_v_82_2 << 1) ^ (pub_r001675_13_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_462_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_462_2 + 1) & 15;
  out_sink_1 ^= stage_v_462_1 & 63;
  out_sink_2 ^= stage_v_462_2 & 63;
  int stage_v_463_1 = ((pub_r001675_7_1 * 2) + 13) & 63;
  int stage_v_463_2 = ((pub_r001675_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001675_3_1 * 2) + 37) & 63;
  int stage_v_464_2 = ((pub_r001675_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((stage_v_401_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_465_2 = ((stage_v_401_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_465_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_465_2 + 1) & 15;
  out_sink_1 ^= stage_v_465_1 & 63;
  out_sink_2 ^= stage_v_465_2 & 63;
  int stage_v_466_1 = ((pub_r001675_18_1 * 2) + 16) & 63;
  int stage_v_466_2 = ((pub_r001675_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = ((stage_v_420_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_467_2 = ((stage_v_420_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_1_1.buffer[2] = (stage_v_467_1 + 1) & 15;
  st_var_1_2.buffer[2] = (stage_v_467_2 + 1) & 15;
  out_sink_1 ^= stage_v_467_1 & 63;
  out_sink_2 ^= stage_v_467_2 & 63;
  int stage_v_468_1 = ((pub_r001675_0_1 * 2) + 19) & 63;
  int stage_v_468_2 = ((pub_r001675_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = ((stage_v_322_1 << 1) ^ (pub_r001675_8_1 >> 1)) & 127;
  int stage_v_469_2 = ((stage_v_322_2 << 1) ^ (pub_r001675_8_2 >> 1)) & 127;
  st_var_1_1.buffer[1] = (stage_v_469_1 + 1) & 15;
  st_var_1_2.buffer[1] = (stage_v_469_2 + 1) & 15;
  out_sink_1 ^= stage_v_469_1 & 63;
  out_sink_2 ^= stage_v_469_2 & 63;
  int stage_v_470_1 = ((stage_v_10_1 << 1) ^ (pub_r001675_3_1 >> 1)) & 127;
  int stage_v_470_2 = ((stage_v_10_2 << 1) ^ (pub_r001675_3_2 >> 1)) & 127;
  st_var_0_1.buffer[2] = (stage_v_470_1 + 1) & 15;
  st_var_0_2.buffer[2] = (stage_v_470_2 + 1) & 15;
  out_sink_1 ^= stage_v_470_1 & 63;
  out_sink_2 ^= stage_v_470_2 & 63;
  int stage_v_471_1 = ((stage_v_323_1 << 1) ^ (pub_r001675_9_1 >> 1)) & 127;
  int stage_v_471_2 = ((stage_v_323_2 << 1) ^ (pub_r001675_9_2 >> 1)) & 127;
  st_var_1_1.buffer[0] = (stage_v_471_1 + 1) & 15;
  st_var_1_2.buffer[0] = (stage_v_471_2 + 1) & 15;
  out_sink_1 ^= stage_v_471_1 & 63;
  out_sink_2 ^= stage_v_471_2 & 63;
  int stage_v_472_1 = ((sec_r001675_11_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_472_2 = ((sec_r001675_11_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[1] = (stage_v_472_1 + 1) & 15;
  st_var_0_2.buffer[1] = (stage_v_472_2 + 1) & 15;
  out_sink_1 ^= stage_v_472_1 & 63;
  out_sink_2 ^= stage_v_472_2 & 63;
  int stage_v_473_1 = ((pub_r001675_7_1 * 2) + 27) & 63;
  int stage_v_473_2 = ((pub_r001675_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_473_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_473_2) & 127;
  int stage_v_474_1 = ((stage_v_298_1 << 1) ^ (pub_r001675_17_1 >> 1)) & 127;
  int stage_v_474_2 = ((stage_v_298_2 << 1) ^ (pub_r001675_17_2 >> 1)) & 127;
  st_var_0_1.buffer[0] = (stage_v_474_1 + 1) & 15;
  st_var_0_2.buffer[0] = (stage_v_474_2 + 1) & 15;
  out_sink_1 ^= stage_v_474_1 & 63;
  out_sink_2 ^= stage_v_474_2 & 63;
  int stage_v_475_1 = ((pub_r001675_4_1 * 2) + 24) & 63;
  int stage_v_475_2 = ((pub_r001675_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001675_4_1 * 2) + 47) & 63;
  int stage_v_476_2 = ((pub_r001675_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001675_8_1 * 2) + 7) & 63;
  int stage_v_477_2 = ((pub_r001675_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((pub_r001675_18_1 * 2) + 10) & 63;
  int stage_v_478_2 = ((pub_r001675_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001675_7_1 != sec_r001675_7_2);
  __CPROVER_assume(pub_r001675_16_1 == pub_r001675_16_2);
  __CPROVER_assume(sec_r001675_15_1 != sec_r001675_15_2);
  __CPROVER_assume(pub_r001675_7_1 == pub_r001675_7_2);
  __CPROVER_assume(sec_r001675_12_1 != sec_r001675_12_2);
  __CPROVER_assume(sec_r001675_2_1 != sec_r001675_2_2);
  __CPROVER_assume(sec_r001675_1_1 != sec_r001675_1_2);
  __CPROVER_assume(pub_r001675_0_1 == pub_r001675_0_2);
  __CPROVER_assume(pub_r001675_10_1 == pub_r001675_10_2);
  __CPROVER_assume(pub_r001675_15_1 == pub_r001675_15_2);
  __CPROVER_assume(sec_r001675_4_1 != sec_r001675_4_2);
  __CPROVER_assume(pub_r001675_6_1 == pub_r001675_6_2);
  __CPROVER_assume(sec_r001675_0_1 != sec_r001675_0_2);
  __CPROVER_assume(pub_r001675_17_1 == pub_r001675_17_2);
  __CPROVER_assume(pub_r001675_9_1 == pub_r001675_9_2);
  __CPROVER_assume(sec_r001675_3_1 != sec_r001675_3_2);
  __CPROVER_assume(sec_r001675_20_1 != sec_r001675_20_2);
  __CPROVER_assume(sec_r001675_19_1 != sec_r001675_19_2);
  __CPROVER_assume(pub_r001675_8_1 == pub_r001675_8_2);
  __CPROVER_assume(pub_r001675_5_1 == pub_r001675_5_2);
  __CPROVER_assume(pub_r001675_1_1 == pub_r001675_1_2);
  __CPROVER_assume(pub_r001675_3_1 == pub_r001675_3_2);
  __CPROVER_assume(sec_r001675_18_1 != sec_r001675_18_2);
  __CPROVER_assume(sec_r001675_10_1 != sec_r001675_10_2);
  __CPROVER_assume(pub_r001675_14_1 == pub_r001675_14_2);
  __CPROVER_assume(sec_r001675_13_1 != sec_r001675_13_2);
  __CPROVER_assume(sec_r001675_8_1 != sec_r001675_8_2);
  __CPROVER_assume(sec_r001675_9_1 != sec_r001675_9_2);
  __CPROVER_assume(pub_r001675_13_1 == pub_r001675_13_2);
  __CPROVER_assume(sec_r001675_16_1 != sec_r001675_16_2);
  __CPROVER_assume(pub_r001675_18_1 == pub_r001675_18_2);
  __CPROVER_assume(pub_r001675_2_1 == pub_r001675_2_2);
  __CPROVER_assume(sec_r001675_14_1 != sec_r001675_14_2);
  __CPROVER_assume(sec_r001675_17_1 != sec_r001675_17_2);
  __CPROVER_assume(sec_r001675_21_1 != sec_r001675_21_2);
  __CPROVER_assume(pub_r001675_4_1 == pub_r001675_4_2);
  __CPROVER_assume(pub_r001675_12_1 == pub_r001675_12_2);
  __CPROVER_assume(pub_r001675_11_1 == pub_r001675_11_2);
  __CPROVER_assume(sec_r001675_11_1 != sec_r001675_11_2);
  __CPROVER_assume(sec_r001675_6_1 != sec_r001675_6_2);
  __CPROVER_assume(sec_r001675_5_1 != sec_r001675_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
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
}


