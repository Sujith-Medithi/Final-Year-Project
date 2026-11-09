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
struct SensorNode_R001876_7613_0
{
  int calib;
  int gain;
  int offset;
  int reading;
  short threshold;
  int status;
  int buffer[3];
};
struct FilterState_R001876_7613_1
{
  int gain_db;
  unsigned char mode;
  short prev_out;
  short prev_in;
  int buffer[3];
};
struct StreamBuffer_R001876_7613_2
{
  short checksum;
  unsigned char head;
  unsigned char tail;
  int buffer[3];
};
struct EventLog_R001876_7613_3
{
  int signature;
  short facility;
  int severity;
  int code;
  int seq;
  unsigned char timestamp;
  int buffer[3];
};
union PacketPayload_R001876_7613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001876_7613_1
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
void fn_R001876_7613_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st_1 = {0};
  struct FilterState_R001876_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int residue_38_1 = 0;
  int residue_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_38_1 = ((residue_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_38_2 = ((residue_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_38_1) & 127;
    acc_2 = (acc_2 + residue_38_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_98_1 = local_arr_1[aux_1 % 3];
  int stride_98_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_98_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_98_2 * 2)) & 127;
  int window_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_71_1)
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

  switch (window_71_2)
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

  int margin_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_46_1 > 35)
  {
    acc_1 = ((acc_1 + (margin_46_1 * 2)) + 5) & 127;
    aux_1 ^= margin_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_46_2 > 35)
  {
    acc_2 = ((acc_2 + (margin_46_2 * 2)) + 5) & 127;
    aux_2 ^= margin_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_46_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_38_1 == residue_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_98_1 == stride_98_2);
  assert(window_71_1 == window_71_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R001876_7613_0(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int residue_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_38 = ((residue_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_38) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int stride_98 = local_arr[aux % 3];
  acc = (acc + (stride_98 * 2)) & 127;
  int window_71 = (aux + st.buffer[1]) & 3;
  switch (window_71)
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

  int margin_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_46 > 35)
  {
    acc = ((acc + (margin_46 * 2)) + 5) & 127;
    aux ^= margin_46 & 15;
  }
  else
  {
    acc = ((acc - margin_46) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001876_7613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st_1 = {0};
  struct StreamBuffer_R001876_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_66_1)
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

  switch (residue_66_2)
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

  int vector_32_1 = 0;
  int vector_32_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_32_1 = ((vector_32_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_32_2 = ((vector_32_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_32_1) & 127;
    acc_2 = (acc_2 + vector_32_2) & 127;
  }

  int threshold_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_62_1) & 63;
  aux_2 = (aux_2 + threshold_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_66_1 == residue_66_2);
  assert(vector_32_1 == vector_32_2);
  assert(threshold_62_1 == threshold_62_2);
}

int fn_R001876_7613_1(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_66 = (aux + st.buffer[1]) & 3;
  switch (residue_66)
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

  int vector_32 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_32 = ((vector_32 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_32) & 127;
  }

  int threshold_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001876_7613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st_1 = {0};
  struct SensorNode_R001876_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int threshold_25_1 = 0;
  int threshold_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_25_1 = ((threshold_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_25_2 = ((threshold_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_25_1) & 127;
    acc_2 = (acc_2 + threshold_25_2) & 127;
  }

  int bound_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_14_1 > 19)
  {
    acc_1 = ((acc_1 + (bound_14_1 * 2)) + 5) & 127;
    aux_1 ^= bound_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_14_2 > 19)
  {
    acc_2 = ((acc_2 + (bound_14_2 * 2)) + 5) & 127;
    aux_2 ^= bound_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_14_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_25_1 == threshold_25_2);
  assert(bound_14_1 == bound_14_2);
}

int fn_R001876_7613_2(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int threshold_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_25 = ((threshold_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_25) & 127;
  }

  int bound_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_14 > 19)
  {
    acc = ((acc + (bound_14 * 2)) + 5) & 127;
    aux ^= bound_14 & 15;
  }
  else
  {
    acc = ((acc - bound_14) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001876_7613_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st_1 = {0};
  struct SensorNode_R001876_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int quotient_59_1 = 0;
  int quotient_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_59_1 = ((quotient_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_59_2 = ((quotient_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_59_1) & 127;
    acc_2 = (acc_2 + quotient_59_2) & 127;
  }

  int checksum_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_26_1) & 63;
  aux_2 = (aux_2 + checksum_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_34_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_34_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_34_1)
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

  switch (sample_34_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_59_1 == quotient_59_2);
  assert(checksum_26_1 == checksum_26_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001876_7613_3(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int quotient_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_59 = ((quotient_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_59) & 127;
  }

  int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_26) & 63;
  acc ^= aux;
  int sample_34 = (aux + st.buffer[1]) & 3;
  switch (sample_34)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001876_7613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st_1 = {0};
  struct StreamBuffer_R001876_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_24_1) & 63;
  aux_2 = (aux_2 + checksum_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_71_1 = 0;
  int quantum_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_71_1 = ((quantum_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_71_2 = ((quantum_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_71_1) & 127;
    acc_2 = (acc_2 + quantum_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_24_1 == checksum_24_2);
  assert(quantum_71_1 == quantum_71_2);
}

int fn_R001876_7613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_24) & 63;
  acc ^= aux;
  int quantum_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_71 = ((quantum_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001876_7613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st_1 = {0};
  struct FilterState_R001876_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_25_1 = 0;
  int scale_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_25_1 = ((scale_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_25_2 = ((scale_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_25_1) & 127;
    acc_2 = (acc_2 + scale_25_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_25_1 == scale_25_2);
}

int fn_R001876_7613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_25 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_25 = ((scale_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_25) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001876_7613_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st_1 = {0};
  struct EventLog_R001876_7613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_69_1 = local_arr_1[aux_1 % 3];
  int tally_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_69_2 * 2)) & 127;
  int residue_77_1 = 0;
  int residue_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_77_1 = ((residue_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_77_2 = ((residue_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_77_1) & 127;
    acc_2 = (acc_2 + residue_77_2) & 127;
  }

  int damping_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_25_1 > 40)
  {
    acc_1 = ((acc_1 + (damping_25_1 * 2)) + 5) & 127;
    aux_1 ^= damping_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_25_2 > 40)
  {
    acc_2 = ((acc_2 + (damping_25_2 * 2)) + 5) & 127;
    aux_2 ^= damping_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_69_1 == tally_69_2);
  assert(residue_77_1 == residue_77_2);
  assert(damping_25_1 == damping_25_2);
}

int fn_R001876_7613_6(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int tally_69 = local_arr[aux % 3];
  acc = (acc + (tally_69 * 2)) & 127;
  int residue_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_77 = ((residue_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_77) & 127;
  }

  int damping_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_25 > 40)
  {
    acc = ((acc + (damping_25 * 2)) + 5) & 127;
    aux ^= damping_25 & 15;
  }
  else
  {
    acc = ((acc - damping_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001876_7613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st_1 = {0};
  struct SensorNode_R001876_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int metric_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_96_1) & 63;
  aux_2 = (aux_2 + metric_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_70_1 = local_arr_1[aux_1 % 3];
  int cursor_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_70_2 * 2)) & 127;
  int stride_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_24_1 > 42)
  {
    acc_1 = ((acc_1 + (stride_24_1 * 2)) + 5) & 127;
    aux_1 ^= stride_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_24_2 > 42)
  {
    acc_2 = ((acc_2 + (stride_24_2 * 2)) + 5) & 127;
    aux_2 ^= stride_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_58_1)
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

  switch (accumulator_58_2)
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
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_96_1 == metric_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_70_1 == cursor_70_2);
  assert(stride_24_1 == stride_24_2);
  assert(accumulator_58_1 == accumulator_58_2);
}

int fn_R001876_7613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int metric_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_96) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_70 = local_arr[aux % 3];
  acc = (acc + (cursor_70 * 2)) & 127;
  int stride_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_24 > 42)
  {
    acc = ((acc + (stride_24 * 2)) + 5) & 127;
    aux ^= stride_24 & 15;
  }
  else
  {
    acc = ((acc - stride_24) + 11) & 127;
    aux += 3;
  }
  int accumulator_58 = (aux + st.buffer[1]) & 3;
  switch (accumulator_58)
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

void fn_R001876_7613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st_1 = {0};
  struct FilterState_R001876_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int sample_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_45_1 > 41)
  {
    acc_1 = ((acc_1 + (sample_45_1 * 2)) + 5) & 127;
    aux_1 ^= sample_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_45_2 > 41)
  {
    acc_2 = ((acc_2 + (sample_45_2 * 2)) + 5) & 127;
    aux_2 ^= sample_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_45_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_57_1)
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

  switch (window_57_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_74_1 = local_arr_1[aux_1 % 3];
  int threshold_74_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_74_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_74_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_45_1 == sample_45_2);
  assert(window_57_1 == window_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_74_1 == threshold_74_2);
}

int fn_R001876_7613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int sample_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_45 > 41)
  {
    acc = ((acc + (sample_45 * 2)) + 5) & 127;
    aux ^= sample_45 & 15;
  }
  else
  {
    acc = ((acc - sample_45) + 11) & 127;
    aux += 3;
  }
  int window_57 = (aux + st.buffer[1]) & 3;
  switch (window_57)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_74 = local_arr[aux % 3];
  acc = (acc + (threshold_74 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001876_7613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st_1 = {0};
  struct EventLog_R001876_7613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int coefficient_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_69_1) & 63;
  aux_2 = (aux_2 + coefficient_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_67_1)
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

  switch (margin_67_2)
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

  int quotient_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_87_1 > 40)
  {
    acc_1 = ((acc_1 + (quotient_87_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_87_2 > 40)
  {
    acc_2 = ((acc_2 + (quotient_87_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_69_1 == coefficient_69_2);
  assert(margin_67_1 == margin_67_2);
  assert(quotient_87_1 == quotient_87_2);
}

int fn_R001876_7613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int coefficient_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_69) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_67 = (aux + st.buffer[1]) & 3;
  switch (margin_67)
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

  int quotient_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_87 > 40)
  {
    acc = ((acc + (quotient_87 * 2)) + 5) & 127;
    aux ^= quotient_87 & 15;
  }
  else
  {
    acc = ((acc - quotient_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001876_7613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st_1 = {0};
  struct StreamBuffer_R001876_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_75_1 = local_arr_1[aux_1 % 3];
  int cursor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_95_1 > 38)
  {
    acc_1 = ((acc_1 + (bound_95_1 * 2)) + 5) & 127;
    aux_1 ^= bound_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_95_2 > 38)
  {
    acc_2 = ((acc_2 + (bound_95_2 * 2)) + 5) & 127;
    aux_2 ^= bound_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_95_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_55_1 = 0;
  int phase_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_55_1 = ((phase_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_55_2 = ((phase_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_55_1) & 127;
    acc_2 = (acc_2 + phase_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_75_1 == cursor_75_2);
  assert(bound_95_1 == bound_95_2);
  assert(phase_55_1 == phase_55_2);
}

int fn_R001876_7613_10(int p0, int p1)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int cursor_75 = local_arr[aux % 3];
  acc = (acc + (cursor_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_95 > 38)
  {
    acc = ((acc + (bound_95 * 2)) + 5) & 127;
    aux ^= bound_95 & 15;
  }
  else
  {
    acc = ((acc - bound_95) + 11) & 127;
    aux += 3;
  }
  int phase_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_55 = ((phase_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001876_7613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st_1 = {0};
  struct StreamBuffer_R001876_7613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_16_1)
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

  switch (damping_16_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_65_1 = local_arr_1[aux_1 % 3];
  int accumulator_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_65_2 * 2)) & 127;
  int segment_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_21_1) & 63;
  aux_2 = (aux_2 + segment_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.head == st_2.head);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_16_1 == damping_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
  assert(segment_21_1 == segment_21_2);
}

int fn_R001876_7613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001876_7613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_16 = (aux + st.buffer[1]) & 3;
  switch (damping_16)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_65 = local_arr[aux % 3];
  acc = (acc + (accumulator_65 * 2)) & 127;
  int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001876_7613_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st_1 = {0};
  struct SensorNode_R001876_7613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_17_1 = local_arr_1[aux_1 % 3];
  int delta_17_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_17_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_17_2 * 2)) & 127;
  int mask_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_31_1) & 63;
  aux_2 = (aux_2 + mask_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_76_1 = 0;
  int anchor_76_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_76_1 = ((anchor_76_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_76_2 = ((anchor_76_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_76_1) & 127;
    acc_2 = (acc_2 + anchor_76_2) & 127;
  }

  int offset_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_44_1 > 35)
  {
    acc_1 = ((acc_1 + (offset_44_1 * 2)) + 5) & 127;
    aux_1 ^= offset_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_44_2 > 35)
  {
    acc_2 = ((acc_2 + (offset_44_2 * 2)) + 5) & 127;
    aux_2 ^= offset_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.reading == st_2.reading);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_17_1 == delta_17_2);
  assert(mask_31_1 == mask_31_2);
  assert(anchor_76_1 == anchor_76_2);
  assert(offset_44_1 == offset_44_2);
}

int fn_R001876_7613_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001876_7613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int delta_17 = local_arr[aux % 3];
  acc = (acc + (delta_17 * 2)) & 127;
  int mask_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_31) & 63;
  acc ^= aux;
  int anchor_76 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_76 = ((anchor_76 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_76) & 127;
  }

  int offset_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_44 > 35)
  {
    acc = ((acc + (offset_44 * 2)) + 5) & 127;
    aux ^= offset_44 & 15;
  }
  else
  {
    acc = ((acc - offset_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001876_7613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st_1 = {0};
  struct EventLog_R001876_7613_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_29_1 > 34)
  {
    acc_1 = ((acc_1 + (anchor_29_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_29_2 > 34)
  {
    acc_2 = ((acc_2 + (anchor_29_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int threshold_55_1 = 0;
  int threshold_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_55_1 = ((threshold_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_55_2 = ((threshold_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_55_1) & 127;
    acc_2 = (acc_2 + threshold_55_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_29_1 == anchor_29_2);
  assert(threshold_55_1 == threshold_55_2);
}

int fn_R001876_7613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001876_7613_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_29 > 34)
  {
    acc = ((acc + (anchor_29 * 2)) + 5) & 127;
    aux ^= anchor_29 & 15;
  }
  else
  {
    acc = ((acc - anchor_29) + 11) & 127;
    aux += 3;
  }
  int threshold_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_55 = ((threshold_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_55) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001876_7613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st_1 = {0};
  struct FilterState_R001876_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int vector_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_27_1)
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

  switch (vector_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_39_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_39_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_39_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_39_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_27_1 == vector_27_2);
  assert(anchor_39_1 == anchor_39_2);
}

int fn_R001876_7613_14(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int vector_27 = (aux + st.buffer[1]) & 3;
  switch (vector_27)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_39 > 36)
  {
    acc = ((acc + (anchor_39 * 2)) + 5) & 127;
    aux ^= anchor_39 & 15;
  }
  else
  {
    acc = ((acc - anchor_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001876_7613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st_1 = {0};
  struct FilterState_R001876_7613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int sample_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_18_1 > 18)
  {
    acc_1 = ((acc_1 + (sample_18_1 * 2)) + 5) & 127;
    aux_1 ^= sample_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_18_2 > 18)
  {
    acc_2 = ((acc_2 + (sample_18_2 * 2)) + 5) & 127;
    aux_2 ^= sample_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_18_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_19_1 = local_arr_1[aux_1 % 3];
  int threshold_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_18_1 == sample_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_19_1 == threshold_19_2);
}

int fn_R001876_7613_15(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001876_7613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int sample_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_18 > 18)
  {
    acc = ((acc + (sample_18 * 2)) + 5) & 127;
    aux ^= sample_18 & 15;
  }
  else
  {
    acc = ((acc - sample_18) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_19 = local_arr[aux % 3];
  acc = (acc + (threshold_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001876_0_1;
  int sec_r001876_0_2;
  int sec_r001876_1_1;
  int sec_r001876_1_2;
  int sec_r001876_2_1;
  int sec_r001876_2_2;
  int sec_r001876_3_1;
  int sec_r001876_3_2;
  int sec_r001876_4_1;
  int sec_r001876_4_2;
  int sec_r001876_5_1;
  int sec_r001876_5_2;
  int sec_r001876_6_1;
  int sec_r001876_6_2;
  int sec_r001876_7_1;
  int sec_r001876_7_2;
  int sec_r001876_8_1;
  int sec_r001876_8_2;
  int sec_r001876_9_1;
  int sec_r001876_9_2;
  int sec_r001876_10_1;
  int sec_r001876_10_2;
  int sec_r001876_11_1;
  int sec_r001876_11_2;
  int sec_r001876_12_1;
  int sec_r001876_12_2;
  int sec_r001876_13_1;
  int sec_r001876_13_2;
  int sec_r001876_14_1;
  int sec_r001876_14_2;
  int sec_r001876_15_1;
  int sec_r001876_15_2;
  int sec_r001876_16_1;
  int sec_r001876_16_2;
  int sec_r001876_17_1;
  int sec_r001876_17_2;
  int sec_r001876_18_1;
  int sec_r001876_18_2;
  int sec_r001876_19_1;
  int sec_r001876_19_2;
  int sec_r001876_20_1;
  int sec_r001876_20_2;
  int sec_r001876_21_1;
  int sec_r001876_21_2;
  int pub_r001876_0_1;
  int pub_r001876_0_2;
  int pub_r001876_1_1;
  int pub_r001876_1_2;
  int pub_r001876_2_1;
  int pub_r001876_2_2;
  int pub_r001876_3_1;
  int pub_r001876_3_2;
  int pub_r001876_4_1;
  int pub_r001876_4_2;
  int pub_r001876_5_1;
  int pub_r001876_5_2;
  int pub_r001876_6_1;
  int pub_r001876_6_2;
  int pub_r001876_7_1;
  int pub_r001876_7_2;
  int pub_r001876_8_1;
  int pub_r001876_8_2;
  int pub_r001876_9_1;
  int pub_r001876_9_2;
  int pub_r001876_10_1;
  int pub_r001876_10_2;
  int pub_r001876_11_1;
  int pub_r001876_11_2;
  int pub_r001876_12_1;
  int pub_r001876_12_2;
  int pub_r001876_13_1;
  int pub_r001876_13_2;
  int pub_r001876_14_1;
  int pub_r001876_14_2;
  int pub_r001876_15_1;
  int pub_r001876_15_2;
  int pub_r001876_16_1;
  int pub_r001876_16_2;
  int pub_r001876_17_1;
  int pub_r001876_17_2;
  int pub_r001876_18_1;
  int pub_r001876_18_2;
  int pub_r001876_19_1;
  int pub_r001876_19_2;
  int pub_r001876_20_1;
  int pub_r001876_20_2;
  int pub_r001876_21_1;
  int pub_r001876_21_2;
  int pub_r001876_22_1;
  int pub_r001876_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001876_0_1 >= (-100)) && (pub_r001876_0_1 <= 100));
  __CPROVER_assume((pub_r001876_0_2 >= (-100)) && (pub_r001876_0_2 <= 100));
  __CPROVER_assume((pub_r001876_1_1 >= (-100)) && (pub_r001876_1_1 <= 100));
  __CPROVER_assume((pub_r001876_1_2 >= (-100)) && (pub_r001876_1_2 <= 100));
  __CPROVER_assume((pub_r001876_2_1 >= (-100)) && (pub_r001876_2_1 <= 100));
  __CPROVER_assume((pub_r001876_2_2 >= (-100)) && (pub_r001876_2_2 <= 100));
  __CPROVER_assume((pub_r001876_3_1 >= (-100)) && (pub_r001876_3_1 <= 100));
  __CPROVER_assume((pub_r001876_3_2 >= (-100)) && (pub_r001876_3_2 <= 100));
  __CPROVER_assume((pub_r001876_4_1 >= (-100)) && (pub_r001876_4_1 <= 100));
  __CPROVER_assume((pub_r001876_4_2 >= (-100)) && (pub_r001876_4_2 <= 100));
  __CPROVER_assume((pub_r001876_5_1 >= (-100)) && (pub_r001876_5_1 <= 100));
  __CPROVER_assume((pub_r001876_5_2 >= (-100)) && (pub_r001876_5_2 <= 100));
  __CPROVER_assume((pub_r001876_6_1 >= (-100)) && (pub_r001876_6_1 <= 100));
  __CPROVER_assume((pub_r001876_6_2 >= (-100)) && (pub_r001876_6_2 <= 100));
  __CPROVER_assume((pub_r001876_7_1 >= (-100)) && (pub_r001876_7_1 <= 100));
  __CPROVER_assume((pub_r001876_7_2 >= (-100)) && (pub_r001876_7_2 <= 100));
  __CPROVER_assume((pub_r001876_8_1 >= (-100)) && (pub_r001876_8_1 <= 100));
  __CPROVER_assume((pub_r001876_8_2 >= (-100)) && (pub_r001876_8_2 <= 100));
  __CPROVER_assume((pub_r001876_9_1 >= (-100)) && (pub_r001876_9_1 <= 100));
  __CPROVER_assume((pub_r001876_9_2 >= (-100)) && (pub_r001876_9_2 <= 100));
  __CPROVER_assume((pub_r001876_10_1 >= (-100)) && (pub_r001876_10_1 <= 100));
  __CPROVER_assume((pub_r001876_10_2 >= (-100)) && (pub_r001876_10_2 <= 100));
  __CPROVER_assume((pub_r001876_11_1 >= (-100)) && (pub_r001876_11_1 <= 100));
  __CPROVER_assume((pub_r001876_11_2 >= (-100)) && (pub_r001876_11_2 <= 100));
  __CPROVER_assume((pub_r001876_12_1 >= (-100)) && (pub_r001876_12_1 <= 100));
  __CPROVER_assume((pub_r001876_12_2 >= (-100)) && (pub_r001876_12_2 <= 100));
  __CPROVER_assume((pub_r001876_13_1 >= (-100)) && (pub_r001876_13_1 <= 100));
  __CPROVER_assume((pub_r001876_13_2 >= (-100)) && (pub_r001876_13_2 <= 100));
  __CPROVER_assume((pub_r001876_14_1 >= (-100)) && (pub_r001876_14_1 <= 100));
  __CPROVER_assume((pub_r001876_14_2 >= (-100)) && (pub_r001876_14_2 <= 100));
  __CPROVER_assume((pub_r001876_15_1 >= (-100)) && (pub_r001876_15_1 <= 100));
  __CPROVER_assume((pub_r001876_15_2 >= (-100)) && (pub_r001876_15_2 <= 100));
  __CPROVER_assume((pub_r001876_16_1 >= (-100)) && (pub_r001876_16_1 <= 100));
  __CPROVER_assume((pub_r001876_16_2 >= (-100)) && (pub_r001876_16_2 <= 100));
  __CPROVER_assume((pub_r001876_17_1 >= (-100)) && (pub_r001876_17_1 <= 100));
  __CPROVER_assume((pub_r001876_17_2 >= (-100)) && (pub_r001876_17_2 <= 100));
  __CPROVER_assume((pub_r001876_18_1 >= (-100)) && (pub_r001876_18_1 <= 100));
  __CPROVER_assume((pub_r001876_18_2 >= (-100)) && (pub_r001876_18_2 <= 100));
  __CPROVER_assume((pub_r001876_19_1 >= (-100)) && (pub_r001876_19_1 <= 100));
  __CPROVER_assume((pub_r001876_19_2 >= (-100)) && (pub_r001876_19_2 <= 100));
  __CPROVER_assume((pub_r001876_20_1 >= (-100)) && (pub_r001876_20_1 <= 100));
  __CPROVER_assume((pub_r001876_20_2 >= (-100)) && (pub_r001876_20_2 <= 100));
  __CPROVER_assume((pub_r001876_21_1 >= (-100)) && (pub_r001876_21_1 <= 100));
  __CPROVER_assume((pub_r001876_21_2 >= (-100)) && (pub_r001876_21_2 <= 100));
  __CPROVER_assume((pub_r001876_22_1 >= (-100)) && (pub_r001876_22_1 <= 100));
  __CPROVER_assume((pub_r001876_22_2 >= (-100)) && (pub_r001876_22_2 <= 100));
  __CPROVER_assume((sec_r001876_0_1 >= 0) && (sec_r001876_0_1 <= 255));
  __CPROVER_assume((sec_r001876_0_2 >= 0) && (sec_r001876_0_2 <= 255));
  __CPROVER_assume((sec_r001876_1_1 >= 0) && (sec_r001876_1_1 <= 255));
  __CPROVER_assume((sec_r001876_1_2 >= 0) && (sec_r001876_1_2 <= 255));
  __CPROVER_assume((sec_r001876_2_1 >= 0) && (sec_r001876_2_1 <= 255));
  __CPROVER_assume((sec_r001876_2_2 >= 0) && (sec_r001876_2_2 <= 255));
  __CPROVER_assume((sec_r001876_3_1 >= 0) && (sec_r001876_3_1 <= 255));
  __CPROVER_assume((sec_r001876_3_2 >= 0) && (sec_r001876_3_2 <= 255));
  __CPROVER_assume((sec_r001876_4_1 >= 0) && (sec_r001876_4_1 <= 255));
  __CPROVER_assume((sec_r001876_4_2 >= 0) && (sec_r001876_4_2 <= 255));
  __CPROVER_assume((sec_r001876_5_1 >= 0) && (sec_r001876_5_1 <= 255));
  __CPROVER_assume((sec_r001876_5_2 >= 0) && (sec_r001876_5_2 <= 255));
  __CPROVER_assume((sec_r001876_6_1 >= 0) && (sec_r001876_6_1 <= 255));
  __CPROVER_assume((sec_r001876_6_2 >= 0) && (sec_r001876_6_2 <= 255));
  __CPROVER_assume((sec_r001876_7_1 >= 0) && (sec_r001876_7_1 <= 255));
  __CPROVER_assume((sec_r001876_7_2 >= 0) && (sec_r001876_7_2 <= 255));
  __CPROVER_assume((sec_r001876_8_1 >= 0) && (sec_r001876_8_1 <= 255));
  __CPROVER_assume((sec_r001876_8_2 >= 0) && (sec_r001876_8_2 <= 255));
  __CPROVER_assume((sec_r001876_9_1 >= 0) && (sec_r001876_9_1 <= 255));
  __CPROVER_assume((sec_r001876_9_2 >= 0) && (sec_r001876_9_2 <= 255));
  __CPROVER_assume((sec_r001876_10_1 >= 0) && (sec_r001876_10_1 <= 255));
  __CPROVER_assume((sec_r001876_10_2 >= 0) && (sec_r001876_10_2 <= 255));
  __CPROVER_assume((sec_r001876_11_1 >= 0) && (sec_r001876_11_1 <= 255));
  __CPROVER_assume((sec_r001876_11_2 >= 0) && (sec_r001876_11_2 <= 255));
  __CPROVER_assume((sec_r001876_12_1 >= 0) && (sec_r001876_12_1 <= 255));
  __CPROVER_assume((sec_r001876_12_2 >= 0) && (sec_r001876_12_2 <= 255));
  __CPROVER_assume((sec_r001876_13_1 >= 0) && (sec_r001876_13_1 <= 255));
  __CPROVER_assume((sec_r001876_13_2 >= 0) && (sec_r001876_13_2 <= 255));
  __CPROVER_assume((sec_r001876_14_1 >= 0) && (sec_r001876_14_1 <= 255));
  __CPROVER_assume((sec_r001876_14_2 >= 0) && (sec_r001876_14_2 <= 255));
  __CPROVER_assume((sec_r001876_15_1 >= 0) && (sec_r001876_15_1 <= 255));
  __CPROVER_assume((sec_r001876_15_2 >= 0) && (sec_r001876_15_2 <= 255));
  __CPROVER_assume((sec_r001876_16_1 >= 0) && (sec_r001876_16_1 <= 255));
  __CPROVER_assume((sec_r001876_16_2 >= 0) && (sec_r001876_16_2 <= 255));
  __CPROVER_assume((sec_r001876_17_1 >= 0) && (sec_r001876_17_1 <= 255));
  __CPROVER_assume((sec_r001876_17_2 >= 0) && (sec_r001876_17_2 <= 255));
  __CPROVER_assume((sec_r001876_18_1 >= 0) && (sec_r001876_18_1 <= 255));
  __CPROVER_assume((sec_r001876_18_2 >= 0) && (sec_r001876_18_2 <= 255));
  __CPROVER_assume((sec_r001876_19_1 >= 0) && (sec_r001876_19_1 <= 255));
  __CPROVER_assume((sec_r001876_19_2 >= 0) && (sec_r001876_19_2 <= 255));
  __CPROVER_assume((sec_r001876_20_1 >= 0) && (sec_r001876_20_1 <= 255));
  __CPROVER_assume((sec_r001876_20_2 >= 0) && (sec_r001876_20_2 <= 255));
  __CPROVER_assume((sec_r001876_21_1 >= 0) && (sec_r001876_21_1 <= 255));
  __CPROVER_assume((sec_r001876_21_2 >= 0) && (sec_r001876_21_2 <= 255));
  struct SensorNode_R001876_7613_0 st_var_0_1 = {0};
  struct SensorNode_R001876_7613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001876_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001876_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001876_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001876_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001876_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001876_0_2 + 7) & 15;
  struct FilterState_R001876_7613_1 st_var_1_1 = {0};
  struct FilterState_R001876_7613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001876_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001876_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001876_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001876_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001876_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001876_0_2 + 9) & 15;
  struct StreamBuffer_R001876_7613_2 st_var_2_1 = {0};
  struct StreamBuffer_R001876_7613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001876_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001876_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001876_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001876_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001876_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001876_0_2 + 11) & 15;
  struct EventLog_R001876_7613_3 st_var_3_1 = {0};
  struct EventLog_R001876_7613_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001876_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001876_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001876_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001876_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001876_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001876_0_2 + 13) & 15;
  union PacketPayload_R001876_7613_0 u_var_1;
  union PacketPayload_R001876_7613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001876_7613_0(sec_r001876_0_1, sec_r001876_1_1);
  int helper_flow_0_2 = fn_R001876_7613_0(sec_r001876_0_2, sec_r001876_1_2);
  fn_R001876_7613_0_2(sec_r001876_0_1, sec_r001876_1_1, sec_r001876_0_2, sec_r001876_1_2);
  int helper_flow_1_1 = fn_R001876_7613_1(sec_r001876_1_1, sec_r001876_2_1);
  int helper_flow_1_2 = fn_R001876_7613_1(sec_r001876_1_2, sec_r001876_2_2);
  fn_R001876_7613_1_2(sec_r001876_1_1, sec_r001876_2_1, sec_r001876_1_2, sec_r001876_2_2);
  int helper_flow_2_1 = fn_R001876_7613_2(sec_r001876_2_1, pub_r001876_3_1);
  int helper_flow_2_2 = fn_R001876_7613_2(sec_r001876_2_2, pub_r001876_3_2);
  fn_R001876_7613_2_2(sec_r001876_2_1, pub_r001876_3_1, sec_r001876_2_2, pub_r001876_3_2);
  int helper_flow_3_1 = fn_R001876_7613_3(sec_r001876_3_1, pub_r001876_4_1);
  int helper_flow_3_2 = fn_R001876_7613_3(sec_r001876_3_2, pub_r001876_4_2);
  fn_R001876_7613_3_2(sec_r001876_3_1, pub_r001876_4_1, sec_r001876_3_2, pub_r001876_4_2);
  int helper_flow_4_1 = fn_R001876_7613_4(sec_r001876_4_1, pub_r001876_5_1, pub_r001876_6_1, pub_r001876_7_1);
  int helper_flow_4_2 = fn_R001876_7613_4(sec_r001876_4_2, pub_r001876_5_2, pub_r001876_6_2, pub_r001876_7_2);
  fn_R001876_7613_4_2(sec_r001876_4_1, pub_r001876_5_1, pub_r001876_6_1, pub_r001876_7_1, sec_r001876_4_2, pub_r001876_5_2, pub_r001876_6_2, pub_r001876_7_2);
  int helper_flow_5_1 = fn_R001876_7613_5(sec_r001876_5_1, sec_r001876_6_1, pub_r001876_7_1);
  int helper_flow_5_2 = fn_R001876_7613_5(sec_r001876_5_2, sec_r001876_6_2, pub_r001876_7_2);
  fn_R001876_7613_5_2(sec_r001876_5_1, sec_r001876_6_1, pub_r001876_7_1, sec_r001876_5_2, sec_r001876_6_2, pub_r001876_7_2);
  int helper_flow_6_1 = fn_R001876_7613_6(sec_r001876_6_1, pub_r001876_7_1);
  int helper_flow_6_2 = fn_R001876_7613_6(sec_r001876_6_2, pub_r001876_7_2);
  fn_R001876_7613_6_2(sec_r001876_6_1, pub_r001876_7_1, sec_r001876_6_2, pub_r001876_7_2);
  int helper_flow_7_1 = fn_R001876_7613_7(sec_r001876_7_1, sec_r001876_8_1, pub_r001876_9_1, pub_r001876_10_1);
  int helper_flow_7_2 = fn_R001876_7613_7(sec_r001876_7_2, sec_r001876_8_2, pub_r001876_9_2, pub_r001876_10_2);
  fn_R001876_7613_7_2(sec_r001876_7_1, sec_r001876_8_1, pub_r001876_9_1, pub_r001876_10_1, sec_r001876_7_2, sec_r001876_8_2, pub_r001876_9_2, pub_r001876_10_2);
  int helper_flow_8_1 = fn_R001876_7613_8(sec_r001876_8_1, pub_r001876_9_1, pub_r001876_10_1);
  int helper_flow_8_2 = fn_R001876_7613_8(sec_r001876_8_2, pub_r001876_9_2, pub_r001876_10_2);
  fn_R001876_7613_8_2(sec_r001876_8_1, pub_r001876_9_1, pub_r001876_10_1, sec_r001876_8_2, pub_r001876_9_2, pub_r001876_10_2);
  int stage_v_0_1 = ((sec_r001876_12_1 + (pub_r001876_5_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001876_12_2 + (pub_r001876_5_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((sec_r001876_13_1 + (pub_r001876_4_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001876_13_2 + (pub_r001876_4_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001876_19_1 + (pub_r001876_9_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001876_19_2 + (pub_r001876_9_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((sec_r001876_2_1 + (pub_r001876_18_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((sec_r001876_2_2 + (pub_r001876_18_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((pub_r001876_4_1 * 2) + 44) & 63;
  int stage_v_4_2 = ((pub_r001876_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((helper_flow_0_1 + (pub_r001876_7_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_0_2 + (pub_r001876_7_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001876_15_1 + (pub_r001876_15_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001876_15_2 + (pub_r001876_15_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001876_12_1 * 2) + 39) & 63;
  int stage_v_7_2 = ((pub_r001876_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((stage_v_6_1 + (pub_r001876_2_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((stage_v_6_2 + (pub_r001876_2_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((helper_flow_8_1 + (pub_r001876_17_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((helper_flow_8_2 + (pub_r001876_17_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((pub_r001876_3_1 * 2) + 14) & 63;
  int stage_v_10_2 = ((pub_r001876_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001876_19_1 * 2) + 34) & 63;
  int stage_v_11_2 = ((pub_r001876_19_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((helper_flow_2_1 + (pub_r001876_8_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_2_2 + (pub_r001876_8_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((sec_r001876_4_1 + (pub_r001876_0_1 * 2)) + 44) & 127;
  int stage_v_13_2 = ((sec_r001876_4_2 + (pub_r001876_0_2 * 2)) + 44) & 127;
  if (stage_v_13_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_13_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_13_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_13_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_14_1 = ((helper_flow_4_1 + (pub_r001876_3_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((helper_flow_4_2 + (pub_r001876_3_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001876_20_1 + (pub_r001876_12_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001876_20_2 + (pub_r001876_12_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((sec_r001876_8_1 + (pub_r001876_12_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((sec_r001876_8_2 + (pub_r001876_12_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001876_20_1 + (pub_r001876_3_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001876_20_2 + (pub_r001876_3_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((pub_r001876_5_1 * 2) + 30) & 63;
  int stage_v_18_2 = ((pub_r001876_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001876_6_1 * 2) + 15) & 63;
  int stage_v_19_2 = ((pub_r001876_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((helper_flow_1_1 + (pub_r001876_11_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((helper_flow_1_2 + (pub_r001876_11_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((stage_v_8_1 + (pub_r001876_11_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((stage_v_8_2 + (pub_r001876_11_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001876_8_1 + (pub_r001876_5_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001876_8_2 + (pub_r001876_5_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001876_19_1 * 2) + 33) & 63;
  int stage_v_23_2 = ((pub_r001876_19_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001876_15_1 + (pub_r001876_8_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001876_15_2 + (pub_r001876_8_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001876_11_1 * 2) + 38) & 63;
  int stage_v_25_2 = ((pub_r001876_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001876_3_1 * 2) + 11) & 63;
  int stage_v_26_2 = ((pub_r001876_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((helper_flow_0_1 + (pub_r001876_16_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((helper_flow_0_2 + (pub_r001876_16_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001876_15_1 * 2) + 19) & 63;
  int stage_v_28_2 = ((pub_r001876_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001876_9_1 + (pub_r001876_1_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001876_9_2 + (pub_r001876_1_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_3_1 + (pub_r001876_2_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_3_2 + (pub_r001876_2_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((helper_flow_1_1 + (pub_r001876_10_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((helper_flow_1_2 + (pub_r001876_10_2 * 2)) + 98) & 127;
  if (stage_v_31_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_31_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_31_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_31_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_32_1 = ((pub_r001876_15_1 * 2) + 13) & 63;
  int stage_v_32_2 = ((pub_r001876_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001876_20_1 * 2) + 47) & 63;
  int stage_v_33_2 = ((pub_r001876_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((helper_flow_5_1 + (pub_r001876_17_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((helper_flow_5_2 + (pub_r001876_17_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_15_1 + (pub_r001876_12_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_15_2 + (pub_r001876_12_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((helper_flow_1_1 + (pub_r001876_19_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((helper_flow_1_2 + (pub_r001876_19_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001876_19_1 * 2) + 26) & 63;
  int stage_v_37_2 = ((pub_r001876_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_21_1 + (pub_r001876_15_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_21_2 + (pub_r001876_15_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001876_9_1 * 2) + 34) & 63;
  int stage_v_39_2 = ((pub_r001876_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001876_19_1 * 2) + 7) & 63;
  int stage_v_40_2 = ((pub_r001876_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001876_7_1 * 2) + 24) & 63;
  int stage_v_41_2 = ((pub_r001876_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001876_16_1 * 2) + 45) & 63;
  int stage_v_42_2 = ((pub_r001876_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((helper_flow_8_1 + (pub_r001876_12_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((helper_flow_8_2 + (pub_r001876_12_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001876_6_1 + (pub_r001876_14_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001876_6_2 + (pub_r001876_14_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_16_1 + (pub_r001876_6_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_16_2 + (pub_r001876_6_2 * 2)) + 140) & 127;
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
  int stage_v_46_1 = ((pub_r001876_16_1 * 2) + 34) & 63;
  int stage_v_46_2 = ((pub_r001876_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001876_17_1 * 2) + 9) & 63;
  int stage_v_47_2 = ((pub_r001876_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((sec_r001876_13_1 + (pub_r001876_15_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001876_13_2 + (pub_r001876_15_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001876_20_1 + (pub_r001876_19_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001876_20_2 + (pub_r001876_19_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_44_1 + (pub_r001876_2_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_44_2 + (pub_r001876_2_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((helper_flow_4_1 + (pub_r001876_16_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((helper_flow_4_2 + (pub_r001876_16_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001876_17_1 + (pub_r001876_11_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001876_17_2 + (pub_r001876_11_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001876_0_1 * 2) + 33) & 63;
  int stage_v_53_2 = ((pub_r001876_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001876_3_1 * 2) + 32) & 63;
  int stage_v_54_2 = ((pub_r001876_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((sec_r001876_18_1 + (pub_r001876_3_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((sec_r001876_18_2 + (pub_r001876_3_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001876_20_1 * 2) + 47) & 63;
  int stage_v_56_2 = ((pub_r001876_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_17_1 + (pub_r001876_7_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_17_2 + (pub_r001876_7_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((sec_r001876_6_1 + (pub_r001876_15_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001876_6_2 + (pub_r001876_15_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((sec_r001876_14_1 + (pub_r001876_9_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((sec_r001876_14_2 + (pub_r001876_9_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((sec_r001876_11_1 + (pub_r001876_22_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001876_11_2 + (pub_r001876_22_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((pub_r001876_10_1 * 2) + 13) & 63;
  int stage_v_61_2 = ((pub_r001876_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((sec_r001876_4_1 + (pub_r001876_21_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((sec_r001876_4_2 + (pub_r001876_21_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_31_1 + (pub_r001876_8_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_31_2 + (pub_r001876_8_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001876_16_1 * 2) + 19) & 63;
  int stage_v_64_2 = ((pub_r001876_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((stage_v_35_1 + (pub_r001876_9_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_35_2 + (pub_r001876_9_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001876_12_1 * 2) + 37) & 63;
  int stage_v_66_2 = ((pub_r001876_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001876_15_1 * 2) + 31) & 63;
  int stage_v_67_2 = ((pub_r001876_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001876_18_1 * 2) + 39) & 63;
  int stage_v_68_2 = ((pub_r001876_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((sec_r001876_9_1 + (pub_r001876_21_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001876_9_2 + (pub_r001876_21_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((pub_r001876_12_1 * 2) + 5) & 63;
  int stage_v_70_2 = ((pub_r001876_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((sec_r001876_14_1 + (pub_r001876_17_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001876_14_2 + (pub_r001876_17_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((stage_v_71_1 + (pub_r001876_8_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((stage_v_71_2 + (pub_r001876_8_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((pub_r001876_9_1 * 2) + 15) & 63;
  int stage_v_73_2 = ((pub_r001876_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001876_19_1 * 2) + 43) & 63;
  int stage_v_74_2 = ((pub_r001876_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((sec_r001876_6_1 + (pub_r001876_5_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((sec_r001876_6_2 + (pub_r001876_5_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_60_1 + (pub_r001876_14_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_60_2 + (pub_r001876_14_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_34_1 + (pub_r001876_11_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_34_2 + (pub_r001876_11_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_31_1 + (pub_r001876_9_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_31_2 + (pub_r001876_9_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((sec_r001876_21_1 + (pub_r001876_19_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((sec_r001876_21_2 + (pub_r001876_19_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((pub_r001876_21_1 * 2) + 7) & 63;
  int stage_v_80_2 = ((pub_r001876_21_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((stage_v_43_1 + (pub_r001876_10_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_43_2 + (pub_r001876_10_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001876_4_1 * 2) + 21) & 63;
  int stage_v_82_2 = ((pub_r001876_4_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001876_20_1 * 2) + 47) & 63;
  int stage_v_83_2 = ((pub_r001876_20_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_58_1 + (pub_r001876_1_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_58_2 + (pub_r001876_1_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((stage_v_63_1 + (pub_r001876_14_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_63_2 + (pub_r001876_14_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_21_1 + (pub_r001876_19_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_21_2 + (pub_r001876_19_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_44_1 + (pub_r001876_16_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_44_2 + (pub_r001876_16_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_5_1 + (pub_r001876_11_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_5_2 + (pub_r001876_11_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((pub_r001876_0_1 * 2) + 50) & 63;
  int stage_v_89_2 = ((pub_r001876_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001876_12_1 * 2) + 19) & 63;
  int stage_v_90_2 = ((pub_r001876_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((sec_r001876_5_1 + (pub_r001876_2_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001876_5_2 + (pub_r001876_2_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001876_2_1 * 2) + 22) & 63;
  int stage_v_92_2 = ((pub_r001876_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001876_2_1 * 2) + 23) & 63;
  int stage_v_93_2 = ((pub_r001876_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((stage_v_69_1 + (pub_r001876_19_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_69_2 + (pub_r001876_19_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((pub_r001876_6_1 * 2) + 36) & 63;
  int stage_v_95_2 = ((pub_r001876_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((stage_v_13_1 + (pub_r001876_17_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((stage_v_13_2 + (pub_r001876_17_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_58_1 + (pub_r001876_19_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_58_2 + (pub_r001876_19_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001876_18_1 * 2) + 26) & 63;
  int stage_v_98_2 = ((pub_r001876_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001876_14_1 * 2) + 35) & 63;
  int stage_v_99_2 = ((pub_r001876_14_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001876_18_1 * 2) + 44) & 63;
  int stage_v_100_2 = ((pub_r001876_18_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_30_1 + (pub_r001876_11_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_30_2 + (pub_r001876_11_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001876_18_1 * 2) + 25) & 63;
  int stage_v_102_2 = ((pub_r001876_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((sec_r001876_5_1 + (pub_r001876_16_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001876_5_2 + (pub_r001876_16_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((sec_r001876_17_1 + (pub_r001876_8_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((sec_r001876_17_2 + (pub_r001876_8_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_97_1 + (pub_r001876_15_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_97_2 + (pub_r001876_15_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_20_1 + (pub_r001876_22_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_20_2 + (pub_r001876_22_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((sec_r001876_8_1 + (pub_r001876_0_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((sec_r001876_8_2 + (pub_r001876_0_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001876_22_1 * 2) + 7) & 63;
  int stage_v_108_2 = ((pub_r001876_22_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001876_21_1 * 2) + 36) & 63;
  int stage_v_109_2 = ((pub_r001876_21_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((stage_v_17_1 + (pub_r001876_4_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_17_2 + (pub_r001876_4_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_27_1 + (pub_r001876_20_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_27_2 + (pub_r001876_20_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_43_1 + (pub_r001876_20_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_43_2 + (pub_r001876_20_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((helper_flow_3_1 + (pub_r001876_20_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((helper_flow_3_2 + (pub_r001876_20_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((pub_r001876_9_1 * 2) + 31) & 63;
  int stage_v_114_2 = ((pub_r001876_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((stage_v_101_1 + (pub_r001876_22_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_101_2 + (pub_r001876_22_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_31_1 + (pub_r001876_15_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_31_2 + (pub_r001876_15_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_65_1 + (pub_r001876_17_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_65_2 + (pub_r001876_17_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((sec_r001876_4_1 + (pub_r001876_1_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001876_4_2 + (pub_r001876_1_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_8_1 + (pub_r001876_12_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_8_2 + (pub_r001876_12_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((pub_r001876_13_1 * 2) + 26) & 63;
  int stage_v_120_2 = ((pub_r001876_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((stage_v_104_1 + (pub_r001876_14_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_104_2 + (pub_r001876_14_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_97_1 + (pub_r001876_1_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_97_2 + (pub_r001876_1_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((helper_flow_3_1 + (pub_r001876_22_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((helper_flow_3_2 + (pub_r001876_22_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001876_1_1 * 2) + 35) & 63;
  int stage_v_124_2 = ((pub_r001876_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001876_20_1 * 2) + 28) & 63;
  int stage_v_125_2 = ((pub_r001876_20_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_55_1 + (pub_r001876_11_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_55_2 + (pub_r001876_11_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((pub_r001876_22_1 * 2) + 41) & 63;
  int stage_v_127_2 = ((pub_r001876_22_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((stage_v_105_1 + (pub_r001876_19_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_105_2 + (pub_r001876_19_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_116_1 + (pub_r001876_8_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_116_2 + (pub_r001876_8_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((pub_r001876_1_1 * 2) + 10) & 63;
  int stage_v_130_2 = ((pub_r001876_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001876_15_1 * 2) + 12) & 63;
  int stage_v_131_2 = ((pub_r001876_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001876_11_1 * 2) + 37) & 63;
  int stage_v_132_2 = ((pub_r001876_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_59_1 + (pub_r001876_4_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_59_2 + (pub_r001876_4_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001876_19_1 * 2) + 50) & 63;
  int stage_v_134_2 = ((pub_r001876_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001876_8_1 * 2) + 17) & 63;
  int stage_v_135_2 = ((pub_r001876_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_117_1 + (pub_r001876_11_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_117_2 + (pub_r001876_11_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_34_1 + (pub_r001876_22_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_34_2 + (pub_r001876_22_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((sec_r001876_6_1 + (pub_r001876_9_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((sec_r001876_6_2 + (pub_r001876_9_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((helper_flow_4_1 + (pub_r001876_8_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((helper_flow_4_2 + (pub_r001876_8_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((pub_r001876_16_1 * 2) + 17) & 63;
  int stage_v_140_2 = ((pub_r001876_16_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((stage_v_136_1 + (pub_r001876_16_1 * 2)) + 428) & 127;
  int stage_v_141_2 = ((stage_v_136_2 + (pub_r001876_16_2 * 2)) + 428) & 127;
  if (stage_v_141_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_141_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_141_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_141_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_142_1 = ((stage_v_55_1 + (pub_r001876_20_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_55_2 + (pub_r001876_20_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001876_0_1 * 2) + 23) & 63;
  int stage_v_143_2 = ((pub_r001876_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001876_12_1 * 2) + 34) & 63;
  int stage_v_144_2 = ((pub_r001876_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_81_1 + (pub_r001876_11_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_81_2 + (pub_r001876_11_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_52_1 + (pub_r001876_15_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_52_2 + (pub_r001876_15_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((sec_r001876_8_1 + (pub_r001876_2_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((sec_r001876_8_2 + (pub_r001876_2_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_59_1 + (pub_r001876_9_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_59_2 + (pub_r001876_9_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((pub_r001876_10_1 * 2) + 23) & 63;
  int stage_v_149_2 = ((pub_r001876_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001876_7_1 * 2) + 24) & 63;
  int stage_v_150_2 = ((pub_r001876_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((stage_v_9_1 + (pub_r001876_13_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((stage_v_9_2 + (pub_r001876_13_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_38_1 + (pub_r001876_18_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_38_2 + (pub_r001876_18_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001876_7_1 * 2) + 43) & 63;
  int stage_v_153_2 = ((pub_r001876_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001876_13_1 * 2) + 48) & 63;
  int stage_v_154_2 = ((pub_r001876_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001876_11_1 * 2) + 26) & 63;
  int stage_v_155_2 = ((pub_r001876_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_119_1 + (pub_r001876_10_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_119_2 + (pub_r001876_10_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_145_1 + (pub_r001876_0_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_145_2 + (pub_r001876_0_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_112_1 + (pub_r001876_12_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_112_2 + (pub_r001876_12_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_94_1 + (pub_r001876_10_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_94_2 + (pub_r001876_10_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_65_1 + (pub_r001876_8_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_65_2 + (pub_r001876_8_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001876_22_1 * 2) + 21) & 63;
  int stage_v_161_2 = ((pub_r001876_22_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_119_1 + (pub_r001876_22_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_119_2 + (pub_r001876_22_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((stage_v_63_1 + (pub_r001876_21_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((stage_v_63_2 + (pub_r001876_21_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001876_9_1 * 2) + 43) & 63;
  int stage_v_164_2 = ((pub_r001876_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((stage_v_111_1 + (pub_r001876_2_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_111_2 + (pub_r001876_2_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001876_9_1 * 2) + 38) & 63;
  int stage_v_166_2 = ((pub_r001876_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001876_12_1 * 2) + 21) & 63;
  int stage_v_167_2 = ((pub_r001876_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_21_1 + (pub_r001876_0_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_21_2 + (pub_r001876_0_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_107_1 + (pub_r001876_20_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_107_2 + (pub_r001876_20_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001876_22_1 * 2) + 16) & 63;
  int stage_v_170_2 = ((pub_r001876_22_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((stage_v_31_1 + (pub_r001876_21_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_31_2 + (pub_r001876_21_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((stage_v_45_1 + (pub_r001876_11_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_45_2 + (pub_r001876_11_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((stage_v_59_1 + (pub_r001876_13_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((stage_v_59_2 + (pub_r001876_13_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((stage_v_30_1 + (pub_r001876_12_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_30_2 + (pub_r001876_12_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_168_1 + (pub_r001876_19_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_168_2 + (pub_r001876_19_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_115_1 + (pub_r001876_9_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_115_2 + (pub_r001876_9_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_115_1 + (pub_r001876_11_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_115_2 + (pub_r001876_11_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_101_1 + (pub_r001876_20_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_101_2 + (pub_r001876_20_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_6_1 + (pub_r001876_7_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_6_2 + (pub_r001876_7_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_36_1 + (pub_r001876_7_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_36_2 + (pub_r001876_7_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001876_5_1 * 2) + 31) & 63;
  int stage_v_181_2 = ((pub_r001876_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_71_1 + (pub_r001876_6_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_71_2 + (pub_r001876_6_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_59_1 + (pub_r001876_22_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_59_2 + (pub_r001876_22_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_69_1 + (pub_r001876_9_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_69_2 + (pub_r001876_9_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((pub_r001876_8_1 * 2) + 40) & 63;
  int stage_v_185_2 = ((pub_r001876_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((pub_r001876_13_1 * 2) + 36) & 63;
  int stage_v_186_2 = ((pub_r001876_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_20_1 + (pub_r001876_10_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_20_2 + (pub_r001876_10_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_133_1 + (pub_r001876_12_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_133_2 + (pub_r001876_12_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((stage_v_35_1 + (pub_r001876_10_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_35_2 + (pub_r001876_10_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001876_7_1 * 2) + 25) & 63;
  int stage_v_190_2 = ((pub_r001876_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((sec_r001876_2_1 + (pub_r001876_10_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001876_2_2 + (pub_r001876_10_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_86_1 + (pub_r001876_16_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_86_2 + (pub_r001876_16_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((pub_r001876_22_1 * 2) + 19) & 63;
  int stage_v_193_2 = ((pub_r001876_22_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((helper_flow_5_1 + (pub_r001876_2_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((helper_flow_5_2 + (pub_r001876_2_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((sec_r001876_21_1 + (pub_r001876_15_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((sec_r001876_21_2 + (pub_r001876_15_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((pub_r001876_18_1 * 2) + 29) & 63;
  int stage_v_196_2 = ((pub_r001876_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001876_14_1 * 2) + 28) & 63;
  int stage_v_197_2 = ((pub_r001876_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((stage_v_103_1 + (pub_r001876_15_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_103_2 + (pub_r001876_15_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((sec_r001876_17_1 + (pub_r001876_3_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((sec_r001876_17_2 + (pub_r001876_3_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_104_1 + (pub_r001876_21_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_104_2 + (pub_r001876_21_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((sec_r001876_17_1 + (pub_r001876_7_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001876_17_2 + (pub_r001876_7_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_85_1 + (pub_r001876_0_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_85_2 + (pub_r001876_0_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((pub_r001876_2_1 * 2) + 28) & 63;
  int stage_v_203_2 = ((pub_r001876_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((sec_r001876_8_1 + (pub_r001876_7_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((sec_r001876_8_2 + (pub_r001876_7_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_159_1 + (pub_r001876_4_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_159_2 + (pub_r001876_4_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_48_1 + (pub_r001876_6_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_48_2 + (pub_r001876_6_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((pub_r001876_4_1 * 2) + 19) & 63;
  int stage_v_207_2 = ((pub_r001876_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_59_1 + (pub_r001876_20_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_59_2 + (pub_r001876_20_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_118_1 + (pub_r001876_19_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_118_2 + (pub_r001876_19_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001876_20_1 * 2) + 29) & 63;
  int stage_v_210_2 = ((pub_r001876_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001876_10_1 * 2) + 25) & 63;
  int stage_v_211_2 = ((pub_r001876_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001876_20_1 * 2) + 8) & 63;
  int stage_v_212_2 = ((pub_r001876_20_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001876_7_1 * 2) + 19) & 63;
  int stage_v_213_2 = ((pub_r001876_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_202_1 + (pub_r001876_20_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_202_2 + (pub_r001876_20_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((sec_r001876_4_1 + (pub_r001876_16_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((sec_r001876_4_2 + (pub_r001876_16_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((pub_r001876_14_1 * 2) + 6) & 63;
  int stage_v_216_2 = ((pub_r001876_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((stage_v_202_1 + (pub_r001876_12_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_202_2 + (pub_r001876_12_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_5_1 + (pub_r001876_21_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_5_2 + (pub_r001876_21_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_17_1 + (pub_r001876_12_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_17_2 + (pub_r001876_12_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_58_1 + (pub_r001876_12_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_58_2 + (pub_r001876_12_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((stage_v_60_1 + (pub_r001876_16_1 * 2)) + 668) & 127;
  int stage_v_221_2 = ((stage_v_60_2 + (pub_r001876_16_2 * 2)) + 668) & 127;
  if (stage_v_221_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_221_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_221_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_221_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_222_1 = ((stage_v_137_1 + (pub_r001876_5_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_137_2 + (pub_r001876_5_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_110_1 + (pub_r001876_1_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_110_2 + (pub_r001876_1_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((stage_v_205_1 + (pub_r001876_5_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_205_2 + (pub_r001876_5_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((pub_r001876_19_1 * 2) + 39) & 63;
  int stage_v_225_2 = ((pub_r001876_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001876_7_1 * 2) + 25) & 63;
  int stage_v_226_2 = ((pub_r001876_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((sec_r001876_8_1 + (pub_r001876_17_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((sec_r001876_8_2 + (pub_r001876_17_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_16_1 + (pub_r001876_14_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_16_2 + (pub_r001876_14_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((pub_r001876_18_1 * 2) + 18) & 63;
  int stage_v_229_2 = ((pub_r001876_18_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((stage_v_198_1 + (pub_r001876_1_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_198_2 + (pub_r001876_1_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((pub_r001876_9_1 * 2) + 50) & 63;
  int stage_v_231_2 = ((pub_r001876_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((stage_v_107_1 + (pub_r001876_2_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_107_2 + (pub_r001876_2_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((stage_v_133_1 + (pub_r001876_20_1 * 2)) + 704) & 127;
  int stage_v_233_2 = ((stage_v_133_2 + (pub_r001876_20_2 * 2)) + 704) & 127;
  if (stage_v_233_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_233_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_233_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_233_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_233_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_233_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_233_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_233_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_234_1 = ((pub_r001876_7_1 * 2) + 13) & 63;
  int stage_v_234_2 = ((pub_r001876_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((stage_v_118_1 + (pub_r001876_16_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_118_2 + (pub_r001876_16_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((stage_v_38_1 + (pub_r001876_8_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_38_2 + (pub_r001876_8_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((stage_v_148_1 + (pub_r001876_8_1 * 2)) + 716) & 127;
  int stage_v_237_2 = ((stage_v_148_2 + (pub_r001876_8_2 * 2)) + 716) & 127;
  if (stage_v_237_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_237_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_237_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_237_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_237_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_237_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_237_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_237_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_238_1 = ((pub_r001876_10_1 * 2) + 25) & 63;
  int stage_v_238_2 = ((pub_r001876_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001876_18_1 * 2) + 38) & 63;
  int stage_v_239_2 = ((pub_r001876_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((sec_r001876_15_1 + (pub_r001876_22_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((sec_r001876_15_2 + (pub_r001876_22_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_76_1 + (pub_r001876_7_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_76_2 + (pub_r001876_7_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((pub_r001876_20_1 * 2) + 15) & 63;
  int stage_v_242_2 = ((pub_r001876_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((stage_v_148_1 + (pub_r001876_3_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_148_2 + (pub_r001876_3_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_244_1 = ((pub_r001876_14_1 * 2) + 33) & 63;
  int stage_v_244_2 = ((pub_r001876_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((stage_v_133_1 + (pub_r001876_6_1 * 2)) + 740) & 127;
  int stage_v_245_2 = ((stage_v_133_2 + (pub_r001876_6_2 * 2)) + 740) & 127;
  if (stage_v_245_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_245_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_245_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_245_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_245_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_245_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_245_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_245_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_246_1 = ((pub_r001876_14_1 * 2) + 15) & 63;
  int stage_v_246_2 = ((pub_r001876_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001876_1_1 * 2) + 13) & 63;
  int stage_v_247_2 = ((pub_r001876_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001876_5_1 * 2) + 28) & 63;
  int stage_v_248_2 = ((pub_r001876_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((stage_v_217_1 + (pub_r001876_11_1 * 2)) + 752) & 127;
  int stage_v_249_2 = ((stage_v_217_2 + (pub_r001876_11_2 * 2)) + 752) & 127;
  if (stage_v_249_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_249_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_249_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_249_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_249_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_249_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_249_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_249_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_250_1 = ((stage_v_121_1 + (pub_r001876_16_1 * 2)) + 755) & 127;
  int stage_v_250_2 = ((stage_v_121_2 + (pub_r001876_16_2 * 2)) + 755) & 127;
  if (stage_v_250_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_250_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_250_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_250_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_250_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_250_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_250_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_250_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_251_1 = ((sec_r001876_7_1 + (pub_r001876_10_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((sec_r001876_7_2 + (pub_r001876_10_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((stage_v_76_1 + (pub_r001876_3_1 * 2)) + 761) & 127;
  int stage_v_252_2 = ((stage_v_76_2 + (pub_r001876_3_2 * 2)) + 761) & 127;
  if (stage_v_252_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_252_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_252_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_252_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_253_1 = ((stage_v_86_1 + (pub_r001876_15_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((stage_v_86_2 + (pub_r001876_15_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_254_1 = ((stage_v_21_1 + (pub_r001876_6_1 * 2)) + 767) & 127;
  int stage_v_254_2 = ((stage_v_21_2 + (pub_r001876_6_2 * 2)) + 767) & 127;
  if (stage_v_254_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_254_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_254_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_254_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_255_1 = ((sec_r001876_17_1 + (pub_r001876_12_1 * 2)) + 770) & 127;
  int stage_v_255_2 = ((sec_r001876_17_2 + (pub_r001876_12_2 * 2)) + 770) & 127;
  if (stage_v_255_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_255_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_255_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_255_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_255_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_255_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_255_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_255_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_256_1 = ((pub_r001876_14_1 * 2) + 28) & 63;
  int stage_v_256_2 = ((pub_r001876_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001876_6_1 * 2) + 13) & 63;
  int stage_v_257_2 = ((pub_r001876_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001876_9_1 * 2) + 23) & 63;
  int stage_v_258_2 = ((pub_r001876_9_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001876_18_1 * 2) + 26) & 63;
  int stage_v_259_2 = ((pub_r001876_18_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001876_16_1 * 2) + 44) & 63;
  int stage_v_260_2 = ((pub_r001876_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((stage_v_205_1 + (pub_r001876_15_1 * 2)) + 788) & 127;
  int stage_v_261_2 = ((stage_v_205_2 + (pub_r001876_15_2 * 2)) + 788) & 127;
  if (stage_v_261_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_261_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_261_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_261_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_261_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_261_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_261_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_261_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_262_1 = ((stage_v_159_1 + (pub_r001876_0_1 * 2)) + 791) & 127;
  int stage_v_262_2 = ((stage_v_159_2 + (pub_r001876_0_2 * 2)) + 791) & 127;
  if (stage_v_262_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_262_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_262_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_262_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_262_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_262_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_262_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_262_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_263_1 = ((stage_v_14_1 + (pub_r001876_4_1 * 2)) + 794) & 127;
  int stage_v_263_2 = ((stage_v_14_2 + (pub_r001876_4_2 * 2)) + 794) & 127;
  if (stage_v_263_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_263_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_263_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_263_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_263_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_263_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_263_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_263_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_264_1 = ((pub_r001876_4_1 * 2) + 43) & 63;
  int stage_v_264_2 = ((pub_r001876_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001876_10_1 * 2) + 47) & 63;
  int stage_v_265_2 = ((pub_r001876_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001876_8_1 * 2) + 28) & 63;
  int stage_v_266_2 = ((pub_r001876_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((stage_v_1_1 + (pub_r001876_17_1 * 2)) + 806) & 127;
  int stage_v_267_2 = ((stage_v_1_2 + (pub_r001876_17_2 * 2)) + 806) & 127;
  if (stage_v_267_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_267_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_267_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_267_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_267_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_267_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_267_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_267_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_268_1 = ((stage_v_5_1 + (pub_r001876_2_1 * 2)) + 809) & 127;
  int stage_v_268_2 = ((stage_v_5_2 + (pub_r001876_2_2 * 2)) + 809) & 127;
  if (stage_v_268_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_268_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_268_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_268_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_268_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_268_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_268_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_268_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_269_1 = ((stage_v_163_1 + (pub_r001876_1_1 * 2)) + 812) & 127;
  int stage_v_269_2 = ((stage_v_163_2 + (pub_r001876_1_2 * 2)) + 812) & 127;
  if (stage_v_269_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_269_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_269_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_269_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_269_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_269_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_269_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_269_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_270_1 = ((stage_v_21_1 + (pub_r001876_15_1 * 2)) + 815) & 127;
  int stage_v_270_2 = ((stage_v_21_2 + (pub_r001876_15_2 * 2)) + 815) & 127;
  if (stage_v_270_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_270_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_270_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_270_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_270_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_270_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_270_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_270_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_271_1 = ((stage_v_71_1 + (pub_r001876_3_1 * 2)) + 818) & 127;
  int stage_v_271_2 = ((stage_v_71_2 + (pub_r001876_3_2 * 2)) + 818) & 127;
  if (stage_v_271_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_271_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_271_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_271_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_271_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_271_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_271_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_271_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001876_11_1 != sec_r001876_11_2);
  __CPROVER_assume(sec_r001876_0_1 != sec_r001876_0_2);
  __CPROVER_assume(pub_r001876_18_1 == pub_r001876_18_2);
  __CPROVER_assume(pub_r001876_19_1 == pub_r001876_19_2);
  __CPROVER_assume(pub_r001876_9_1 == pub_r001876_9_2);
  __CPROVER_assume(pub_r001876_20_1 == pub_r001876_20_2);
  __CPROVER_assume(pub_r001876_21_1 == pub_r001876_21_2);
  __CPROVER_assume(pub_r001876_8_1 == pub_r001876_8_2);
  __CPROVER_assume(pub_r001876_4_1 == pub_r001876_4_2);
  __CPROVER_assume(pub_r001876_12_1 == pub_r001876_12_2);
  __CPROVER_assume(pub_r001876_14_1 == pub_r001876_14_2);
  __CPROVER_assume(sec_r001876_4_1 != sec_r001876_4_2);
  __CPROVER_assume(sec_r001876_8_1 != sec_r001876_8_2);
  __CPROVER_assume(pub_r001876_6_1 == pub_r001876_6_2);
  __CPROVER_assume(pub_r001876_5_1 == pub_r001876_5_2);
  __CPROVER_assume(sec_r001876_9_1 != sec_r001876_9_2);
  __CPROVER_assume(sec_r001876_3_1 != sec_r001876_3_2);
  __CPROVER_assume(sec_r001876_5_1 != sec_r001876_5_2);
  __CPROVER_assume(pub_r001876_1_1 == pub_r001876_1_2);
  __CPROVER_assume(sec_r001876_15_1 != sec_r001876_15_2);
  __CPROVER_assume(sec_r001876_21_1 != sec_r001876_21_2);
  __CPROVER_assume(pub_r001876_22_1 == pub_r001876_22_2);
  __CPROVER_assume(pub_r001876_11_1 == pub_r001876_11_2);
  __CPROVER_assume(pub_r001876_16_1 == pub_r001876_16_2);
  __CPROVER_assume(sec_r001876_18_1 != sec_r001876_18_2);
  __CPROVER_assume(sec_r001876_2_1 != sec_r001876_2_2);
  __CPROVER_assume(sec_r001876_1_1 != sec_r001876_1_2);
  __CPROVER_assume(sec_r001876_10_1 != sec_r001876_10_2);
  __CPROVER_assume(sec_r001876_16_1 != sec_r001876_16_2);
  __CPROVER_assume(sec_r001876_6_1 != sec_r001876_6_2);
  __CPROVER_assume(sec_r001876_17_1 != sec_r001876_17_2);
  __CPROVER_assume(pub_r001876_2_1 == pub_r001876_2_2);
  __CPROVER_assume(pub_r001876_13_1 == pub_r001876_13_2);
  __CPROVER_assume(pub_r001876_3_1 == pub_r001876_3_2);
  __CPROVER_assume(sec_r001876_7_1 != sec_r001876_7_2);
  __CPROVER_assume(sec_r001876_19_1 != sec_r001876_19_2);
  __CPROVER_assume(pub_r001876_7_1 == pub_r001876_7_2);
  __CPROVER_assume(sec_r001876_13_1 != sec_r001876_13_2);
  __CPROVER_assume(pub_r001876_15_1 == pub_r001876_15_2);
  __CPROVER_assume(sec_r001876_12_1 != sec_r001876_12_2);
  __CPROVER_assume(sec_r001876_14_1 != sec_r001876_14_2);
  __CPROVER_assume(pub_r001876_10_1 == pub_r001876_10_2);
  __CPROVER_assume(pub_r001876_0_1 == pub_r001876_0_2);
  __CPROVER_assume(sec_r001876_20_1 != sec_r001876_20_2);
  __CPROVER_assume(pub_r001876_17_1 == pub_r001876_17_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.offset == st_var_0_2.offset);
  assert(st_var_0_1.reading == st_var_0_2.reading);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.status == st_var_0_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.head == st_var_2_2.head);
  assert(st_var_2_1.tail == st_var_2_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.signature == st_var_3_2.signature);
  assert(st_var_3_1.facility == st_var_3_2.facility);
  assert(st_var_3_1.severity == st_var_3_2.severity);
  assert(st_var_3_1.code == st_var_3_2.code);
  assert(st_var_3_1.seq == st_var_3_2.seq);
  assert(st_var_3_1.timestamp == st_var_3_2.timestamp);
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
}


