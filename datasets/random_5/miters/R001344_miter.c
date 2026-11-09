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
struct StreamBuffer_R001344_4413_0
{
  unsigned char watermark;
  int head;
  int capacity;
  int checksum;
  int buffer[3];
};
struct EventLog_R001344_4413_1
{
  short facility;
  int timestamp;
  short code;
  short signature;
  int seq;
  int buffer[3];
};
union RegisterBank_R001344_4413_0
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
void fn_R001344_4413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int bound_53_1 = 0;
  int bound_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_53_1 = ((bound_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_53_2 = ((bound_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_53_1) & 127;
    acc_2 = (acc_2 + bound_53_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_83_1 = local_arr_1[aux_1 % 3];
  int anchor_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_83_2 * 2)) & 127;
  int anchor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_49_1 > 46)
  {
    acc_1 = ((acc_1 + (anchor_49_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_49_2 > 46)
  {
    acc_2 = ((acc_2 + (anchor_49_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_53_1 == bound_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_83_1 == anchor_83_2);
  assert(anchor_49_1 == anchor_49_2);
}

int fn_R001344_4413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int bound_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_53 = ((bound_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_53) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_83 = local_arr[aux % 3];
  acc = (acc + (anchor_83 * 2)) & 127;
  int anchor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_49 > 46)
  {
    acc = ((acc + (anchor_49 * 2)) + 5) & 127;
    aux ^= anchor_49 & 15;
  }
  else
  {
    acc = ((acc - anchor_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001344_4413_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_83_1)
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

  switch (segment_83_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_83_1 == segment_83_2);
}

int fn_R001344_4413_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_83 = (aux + st.buffer[1]) & 3;
  switch (segment_83)
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

void fn_R001344_4413_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int tally_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_38_1) & 63;
  aux_2 = (aux_2 + tally_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_43_1 > 27)
  {
    acc_1 = ((acc_1 + (stride_43_1 * 2)) + 5) & 127;
    aux_1 ^= stride_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_43_2 > 27)
  {
    acc_2 = ((acc_2 + (stride_43_2 * 2)) + 5) & 127;
    aux_2 ^= stride_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_59_1)
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

  switch (margin_59_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_38_1 == tally_38_2);
  assert(stride_43_1 == stride_43_2);
  assert(margin_59_1 == margin_59_2);
}

int fn_R001344_4413_2(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int tally_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_38) & 63;
  acc ^= aux;
  int stride_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_43 > 27)
  {
    acc = ((acc + (stride_43 * 2)) + 5) & 127;
    aux ^= stride_43 & 15;
  }
  else
  {
    acc = ((acc - stride_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_59 = (aux + st.buffer[1]) & 3;
  switch (margin_59)
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

void fn_R001344_4413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int metric_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_99_1)
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

  switch (metric_99_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_91_1 = local_arr_1[aux_1 % 3];
  int damping_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_91_2 * 2)) & 127;
  int quantum_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_28_1 > 45)
  {
    acc_1 = ((acc_1 + (quantum_28_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_28_2 > 45)
  {
    acc_2 = ((acc_2 + (quantum_28_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_28_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_99_1 == metric_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_91_1 == damping_91_2);
  assert(quantum_28_1 == quantum_28_2);
}

int fn_R001344_4413_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int metric_99 = (aux + st.buffer[1]) & 3;
  switch (metric_99)
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

  int local_arr[3] = {4, 9, 15};
  int damping_91 = local_arr[aux % 3];
  acc = (acc + (damping_91 * 2)) & 127;
  int quantum_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_28 > 45)
  {
    acc = ((acc + (quantum_28 * 2)) + 5) & 127;
    aux ^= quantum_28 & 15;
  }
  else
  {
    acc = ((acc - quantum_28) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001344_4413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_39_1)
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

  switch (weight_39_2)
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

  int offset_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_70_1 > 46)
  {
    acc_1 = ((acc_1 + (offset_70_1 * 2)) + 5) & 127;
    aux_1 ^= offset_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_70_2 > 46)
  {
    acc_2 = ((acc_2 + (offset_70_2 * 2)) + 5) & 127;
    aux_2 ^= offset_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_73_1 = local_arr_1[aux_1 % 3];
  int index_reg_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_39_1 == weight_39_2);
  assert(offset_70_1 == offset_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_73_1 == index_reg_73_2);
}

int fn_R001344_4413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_39 = (aux + st.buffer[1]) & 3;
  switch (weight_39)
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

  int offset_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_70 > 46)
  {
    acc = ((acc + (offset_70 * 2)) + 5) & 127;
    aux ^= offset_70 & 15;
  }
  else
  {
    acc = ((acc - offset_70) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_73 = local_arr[aux % 3];
  acc = (acc + (index_reg_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001344_4413_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_81_1 = local_arr_1[aux_1 % 3];
  int segment_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_81_2 * 2)) & 127;
  int segment_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_95_1 > 30)
  {
    acc_1 = ((acc_1 + (segment_95_1 * 2)) + 5) & 127;
    aux_1 ^= segment_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_95_2 > 30)
  {
    acc_2 = ((acc_2 + (segment_95_2 * 2)) + 5) & 127;
    aux_2 ^= segment_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_95_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_81_1 == segment_81_2);
  assert(segment_95_1 == segment_95_2);
}

int fn_R001344_4413_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int segment_81 = local_arr[aux % 3];
  acc = (acc + (segment_81 * 2)) & 127;
  int segment_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_95 > 30)
  {
    acc = ((acc + (segment_95 * 2)) + 5) & 127;
    aux ^= segment_95 & 15;
  }
  else
  {
    acc = ((acc - segment_95) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001344_4413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_22_1 = 0;
  int checksum_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_22_1 = ((checksum_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_22_2 = ((checksum_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_22_1) & 127;
    acc_2 = (acc_2 + checksum_22_2) & 127;
  }

  int offset_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_12_1)
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

  switch (offset_12_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_22_1 == checksum_22_2);
  assert(offset_12_1 == offset_12_2);
}

int fn_R001344_4413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_22 = ((checksum_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_22) & 127;
  }

  int offset_12 = (aux + st.buffer[1]) & 3;
  switch (offset_12)
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

void fn_R001344_4413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int sample_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_77_1) & 63;
  aux_2 = (aux_2 + sample_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_55_1 = local_arr_1[aux_1 % 3];
  int tracker_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_55_2 * 2)) & 127;
  int segment_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_49_1)
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

  switch (segment_49_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_77_1 == sample_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_55_1 == tracker_55_2);
  assert(segment_49_1 == segment_49_2);
}

int fn_R001344_4413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int sample_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_77) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tracker_55 = local_arr[aux % 3];
  acc = (acc + (tracker_55 * 2)) & 127;
  int segment_49 = (aux + st.buffer[1]) & 3;
  switch (segment_49)
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

void fn_R001344_4413_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int pivot_95_1 = 0;
  int pivot_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_95_1 = ((pivot_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_95_2 = ((pivot_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_95_1) & 127;
    acc_2 = (acc_2 + pivot_95_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_43_1)
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

  switch (quotient_43_2)
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

  int offset_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_52_1) & 63;
  aux_2 = (aux_2 + offset_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_95_1 == pivot_95_2);
  assert(quotient_43_1 == quotient_43_2);
  assert(offset_52_1 == offset_52_2);
}

int fn_R001344_4413_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int pivot_95 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_95 = ((pivot_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_95) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_43 = (aux + st.buffer[1]) & 3;
  switch (quotient_43)
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

  int offset_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001344_4413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_96_1)
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

  switch (tally_96_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_29_1 = local_arr_1[aux_1 % 3];
  int metric_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_29_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_96_1 == tally_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_29_1 == metric_29_2);
}

int fn_R001344_4413_9(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_96 = (aux + st.buffer[1]) & 3;
  switch (tally_96)
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

  int local_arr[3] = {4, 9, 15};
  int metric_29 = local_arr[aux % 3];
  acc = (acc + (metric_29 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001344_4413_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int damping_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_44_1 > 24)
  {
    acc_1 = ((acc_1 + (damping_44_1 * 2)) + 5) & 127;
    aux_1 ^= damping_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_44_2 > 24)
  {
    acc_2 = ((acc_2 + (damping_44_2 * 2)) + 5) & 127;
    aux_2 ^= damping_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_99_1) & 63;
  aux_2 = (aux_2 + offset_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_71_1)
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

  switch (index_reg_71_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_44_1 == damping_44_2);
  assert(offset_99_1 == offset_99_2);
  assert(index_reg_71_1 == index_reg_71_2);
}

int fn_R001344_4413_10(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int damping_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_44 > 24)
  {
    acc = ((acc + (damping_44 * 2)) + 5) & 127;
    aux ^= damping_44 & 15;
  }
  else
  {
    acc = ((acc - damping_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_99) & 63;
  acc ^= aux;
  int index_reg_71 = (aux + st.buffer[1]) & 3;
  switch (index_reg_71)
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

void fn_R001344_4413_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tracker_49_1 = 0;
  int tracker_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_49_1 = ((tracker_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_49_2 = ((tracker_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_49_1) & 127;
    acc_2 = (acc_2 + tracker_49_2) & 127;
  }

  int pivot_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_93_1)
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

  switch (pivot_93_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_49_1 == tracker_49_2);
  assert(pivot_93_1 == pivot_93_2);
}

int fn_R001344_4413_11(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tracker_49 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_49 = ((tracker_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_49) & 127;
  }

  int pivot_93 = (aux + st.buffer[1]) & 3;
  switch (pivot_93)
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

void fn_R001344_4413_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int quantum_11_1 = 0;
  int quantum_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_11_1 = ((quantum_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_11_2 = ((quantum_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_11_1) & 127;
    acc_2 = (acc_2 + quantum_11_2) & 127;
  }

  int tracker_47_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_47_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_47_1) & 63;
  aux_2 = (aux_2 + tracker_47_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_11_1 == quantum_11_2);
  assert(tracker_47_1 == tracker_47_2);
}

int fn_R001344_4413_12(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int quantum_11 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_11 = ((quantum_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_11) & 127;
  }

  int tracker_47 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_47) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001344_4413_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int window_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_69_1 > 27)
  {
    acc_1 = ((acc_1 + (window_69_1 * 2)) + 5) & 127;
    aux_1 ^= window_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_69_2 > 27)
  {
    acc_2 = ((acc_2 + (window_69_2 * 2)) + 5) & 127;
    aux_2 ^= window_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_96_1 = local_arr_1[aux_1 % 3];
  int tally_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_69_1 == window_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_96_1 == tally_96_2);
}

int fn_R001344_4413_13(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int window_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_69 > 27)
  {
    acc = ((acc + (window_69 * 2)) + 5) & 127;
    aux ^= window_69 & 15;
  }
  else
  {
    acc = ((acc - window_69) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_96 = local_arr[aux % 3];
  acc = (acc + (tally_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001344_4413_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int stride_92_1 = 0;
  int stride_92_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_92_1 = ((stride_92_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_92_2 = ((stride_92_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_92_1) & 127;
    acc_2 = (acc_2 + stride_92_2) & 127;
  }

  int vector_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_70_1)
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

  switch (vector_70_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_92_1 == stride_92_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R001344_4413_14(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int stride_92 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_92 = ((stride_92 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_92) & 127;
  }

  int vector_70 = (aux + st.buffer[1]) & 3;
  switch (vector_70)
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

void fn_R001344_4413_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_96_1)
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

  switch (pivot_96_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_90_1 = local_arr_1[aux_1 % 3];
  int cursor_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_90_2 * 2)) & 127;
  int index_reg_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_82_1 > 45)
  {
    acc_1 = ((acc_1 + (index_reg_82_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_82_2 > 45)
  {
    acc_2 = ((acc_2 + (index_reg_82_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_10_1 = 0;
  int window_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_10_1 = ((window_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_10_2 = ((window_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_10_1) & 127;
    acc_2 = (acc_2 + window_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_96_1 == pivot_96_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_90_1 == cursor_90_2);
  assert(index_reg_82_1 == index_reg_82_2);
  assert(window_10_1 == window_10_2);
}

int fn_R001344_4413_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_96 = (aux + st.buffer[1]) & 3;
  switch (pivot_96)
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

  int local_arr[3] = {4, 9, 15};
  int cursor_90 = local_arr[aux % 3];
  acc = (acc + (cursor_90 * 2)) & 127;
  int index_reg_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_82 > 45)
  {
    acc = ((acc + (index_reg_82 * 2)) + 5) & 127;
    aux ^= index_reg_82 & 15;
  }
  else
  {
    acc = ((acc - index_reg_82) + 11) & 127;
    aux += 3;
  }
  int window_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_10 = ((window_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001344_4413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_22_1 = 0;
  int quantum_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_22_1 = ((quantum_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_22_2 = ((quantum_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_22_1) & 127;
    acc_2 = (acc_2 + quantum_22_2) & 127;
  }

  int residue_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_32_1) & 63;
  aux_2 = (aux_2 + residue_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(residue_32_1 == residue_32_2);
}

int fn_R001344_4413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_22 = ((quantum_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_22) & 127;
  }

  int residue_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001344_4413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int offset_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_62_1) & 63;
  aux_2 = (aux_2 + offset_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_82_1 = local_arr_1[aux_1 % 3];
  int phase_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_82_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_80_1 > 34)
  {
    acc_1 = ((acc_1 + (tracker_80_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_80_2 > 34)
  {
    acc_2 = ((acc_2 + (tracker_80_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_62_1 == offset_62_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_82_1 == phase_82_2);
  assert(tracker_80_1 == tracker_80_2);
}

int fn_R001344_4413_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int offset_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_62) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_82 = local_arr[aux % 3];
  acc = (acc + (phase_82 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_80 > 34)
  {
    acc = ((acc + (tracker_80 * 2)) + 5) & 127;
    aux ^= tracker_80 & 15;
  }
  else
  {
    acc = ((acc - tracker_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001344_4413_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_36_1 = local_arr_1[aux_1 % 3];
  int weight_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_36_2 * 2)) & 127;
  int accumulator_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_98_1 > 36)
  {
    acc_1 = ((acc_1 + (accumulator_98_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_98_2 > 36)
  {
    acc_2 = ((acc_2 + (accumulator_98_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.checksum == st_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_36_1 == weight_36_2);
  assert(accumulator_98_1 == accumulator_98_2);
}

int fn_R001344_4413_18(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001344_4413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int weight_36 = local_arr[aux % 3];
  acc = (acc + (weight_36 * 2)) & 127;
  int accumulator_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_98 > 36)
  {
    acc = ((acc + (accumulator_98 * 2)) + 5) & 127;
    aux ^= accumulator_98 & 15;
  }
  else
  {
    acc = ((acc - accumulator_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001344_4413_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st_1 = {0};
  struct EventLog_R001344_4413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int cursor_50_1 = 0;
  int cursor_50_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    cursor_50_1 = ((cursor_50_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    cursor_50_2 = ((cursor_50_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + cursor_50_1) & 127;
    acc_2 = (acc_2 + cursor_50_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_49_1)
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

  switch (damping_49_2)
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
  assert(st_1.facility == st_2.facility);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_50_1 == cursor_50_2);
  assert(damping_49_1 == damping_49_2);
}

int fn_R001344_4413_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001344_4413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int cursor_50 = 0;
  for (int k = 0; k < 2; k++)
  {
    cursor_50 = ((cursor_50 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + cursor_50) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_49 = (aux + st.buffer[1]) & 3;
  switch (damping_49)
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
  int sec_r001344_0_1;
  int sec_r001344_0_2;
  int sec_r001344_1_1;
  int sec_r001344_1_2;
  int sec_r001344_2_1;
  int sec_r001344_2_2;
  int sec_r001344_3_1;
  int sec_r001344_3_2;
  int sec_r001344_4_1;
  int sec_r001344_4_2;
  int sec_r001344_5_1;
  int sec_r001344_5_2;
  int sec_r001344_6_1;
  int sec_r001344_6_2;
  int sec_r001344_7_1;
  int sec_r001344_7_2;
  int sec_r001344_8_1;
  int sec_r001344_8_2;
  int sec_r001344_9_1;
  int sec_r001344_9_2;
  int sec_r001344_10_1;
  int sec_r001344_10_2;
  int sec_r001344_11_1;
  int sec_r001344_11_2;
  int sec_r001344_12_1;
  int sec_r001344_12_2;
  int sec_r001344_13_1;
  int sec_r001344_13_2;
  int sec_r001344_14_1;
  int sec_r001344_14_2;
  int sec_r001344_15_1;
  int sec_r001344_15_2;
  int pub_r001344_0_1;
  int pub_r001344_0_2;
  int pub_r001344_1_1;
  int pub_r001344_1_2;
  int pub_r001344_2_1;
  int pub_r001344_2_2;
  int pub_r001344_3_1;
  int pub_r001344_3_2;
  int pub_r001344_4_1;
  int pub_r001344_4_2;
  int pub_r001344_5_1;
  int pub_r001344_5_2;
  int pub_r001344_6_1;
  int pub_r001344_6_2;
  int pub_r001344_7_1;
  int pub_r001344_7_2;
  int pub_r001344_8_1;
  int pub_r001344_8_2;
  int pub_r001344_9_1;
  int pub_r001344_9_2;
  int pub_r001344_10_1;
  int pub_r001344_10_2;
  int pub_r001344_11_1;
  int pub_r001344_11_2;
  int pub_r001344_12_1;
  int pub_r001344_12_2;
  int pub_r001344_13_1;
  int pub_r001344_13_2;
  int pub_r001344_14_1;
  int pub_r001344_14_2;
  int pub_r001344_15_1;
  int pub_r001344_15_2;
  int pub_r001344_16_1;
  int pub_r001344_16_2;
  int pub_r001344_17_1;
  int pub_r001344_17_2;
  int pub_r001344_18_1;
  int pub_r001344_18_2;
  int pub_r001344_19_1;
  int pub_r001344_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001344_0_1 >= (-100)) && (pub_r001344_0_1 <= 100));
  __CPROVER_assume((pub_r001344_0_2 >= (-100)) && (pub_r001344_0_2 <= 100));
  __CPROVER_assume((pub_r001344_1_1 >= (-100)) && (pub_r001344_1_1 <= 100));
  __CPROVER_assume((pub_r001344_1_2 >= (-100)) && (pub_r001344_1_2 <= 100));
  __CPROVER_assume((pub_r001344_2_1 >= (-100)) && (pub_r001344_2_1 <= 100));
  __CPROVER_assume((pub_r001344_2_2 >= (-100)) && (pub_r001344_2_2 <= 100));
  __CPROVER_assume((pub_r001344_3_1 >= (-100)) && (pub_r001344_3_1 <= 100));
  __CPROVER_assume((pub_r001344_3_2 >= (-100)) && (pub_r001344_3_2 <= 100));
  __CPROVER_assume((pub_r001344_4_1 >= (-100)) && (pub_r001344_4_1 <= 100));
  __CPROVER_assume((pub_r001344_4_2 >= (-100)) && (pub_r001344_4_2 <= 100));
  __CPROVER_assume((pub_r001344_5_1 >= (-100)) && (pub_r001344_5_1 <= 100));
  __CPROVER_assume((pub_r001344_5_2 >= (-100)) && (pub_r001344_5_2 <= 100));
  __CPROVER_assume((pub_r001344_6_1 >= (-100)) && (pub_r001344_6_1 <= 100));
  __CPROVER_assume((pub_r001344_6_2 >= (-100)) && (pub_r001344_6_2 <= 100));
  __CPROVER_assume((pub_r001344_7_1 >= (-100)) && (pub_r001344_7_1 <= 100));
  __CPROVER_assume((pub_r001344_7_2 >= (-100)) && (pub_r001344_7_2 <= 100));
  __CPROVER_assume((pub_r001344_8_1 >= (-100)) && (pub_r001344_8_1 <= 100));
  __CPROVER_assume((pub_r001344_8_2 >= (-100)) && (pub_r001344_8_2 <= 100));
  __CPROVER_assume((pub_r001344_9_1 >= (-100)) && (pub_r001344_9_1 <= 100));
  __CPROVER_assume((pub_r001344_9_2 >= (-100)) && (pub_r001344_9_2 <= 100));
  __CPROVER_assume((pub_r001344_10_1 >= (-100)) && (pub_r001344_10_1 <= 100));
  __CPROVER_assume((pub_r001344_10_2 >= (-100)) && (pub_r001344_10_2 <= 100));
  __CPROVER_assume((pub_r001344_11_1 >= (-100)) && (pub_r001344_11_1 <= 100));
  __CPROVER_assume((pub_r001344_11_2 >= (-100)) && (pub_r001344_11_2 <= 100));
  __CPROVER_assume((pub_r001344_12_1 >= (-100)) && (pub_r001344_12_1 <= 100));
  __CPROVER_assume((pub_r001344_12_2 >= (-100)) && (pub_r001344_12_2 <= 100));
  __CPROVER_assume((pub_r001344_13_1 >= (-100)) && (pub_r001344_13_1 <= 100));
  __CPROVER_assume((pub_r001344_13_2 >= (-100)) && (pub_r001344_13_2 <= 100));
  __CPROVER_assume((pub_r001344_14_1 >= (-100)) && (pub_r001344_14_1 <= 100));
  __CPROVER_assume((pub_r001344_14_2 >= (-100)) && (pub_r001344_14_2 <= 100));
  __CPROVER_assume((pub_r001344_15_1 >= (-100)) && (pub_r001344_15_1 <= 100));
  __CPROVER_assume((pub_r001344_15_2 >= (-100)) && (pub_r001344_15_2 <= 100));
  __CPROVER_assume((pub_r001344_16_1 >= (-100)) && (pub_r001344_16_1 <= 100));
  __CPROVER_assume((pub_r001344_16_2 >= (-100)) && (pub_r001344_16_2 <= 100));
  __CPROVER_assume((pub_r001344_17_1 >= (-100)) && (pub_r001344_17_1 <= 100));
  __CPROVER_assume((pub_r001344_17_2 >= (-100)) && (pub_r001344_17_2 <= 100));
  __CPROVER_assume((pub_r001344_18_1 >= (-100)) && (pub_r001344_18_1 <= 100));
  __CPROVER_assume((pub_r001344_18_2 >= (-100)) && (pub_r001344_18_2 <= 100));
  __CPROVER_assume((pub_r001344_19_1 >= (-100)) && (pub_r001344_19_1 <= 100));
  __CPROVER_assume((pub_r001344_19_2 >= (-100)) && (pub_r001344_19_2 <= 100));
  __CPROVER_assume((sec_r001344_0_1 >= 0) && (sec_r001344_0_1 <= 255));
  __CPROVER_assume((sec_r001344_0_2 >= 0) && (sec_r001344_0_2 <= 255));
  __CPROVER_assume((sec_r001344_1_1 >= 0) && (sec_r001344_1_1 <= 255));
  __CPROVER_assume((sec_r001344_1_2 >= 0) && (sec_r001344_1_2 <= 255));
  __CPROVER_assume((sec_r001344_2_1 >= 0) && (sec_r001344_2_1 <= 255));
  __CPROVER_assume((sec_r001344_2_2 >= 0) && (sec_r001344_2_2 <= 255));
  __CPROVER_assume((sec_r001344_3_1 >= 0) && (sec_r001344_3_1 <= 255));
  __CPROVER_assume((sec_r001344_3_2 >= 0) && (sec_r001344_3_2 <= 255));
  __CPROVER_assume((sec_r001344_4_1 >= 0) && (sec_r001344_4_1 <= 255));
  __CPROVER_assume((sec_r001344_4_2 >= 0) && (sec_r001344_4_2 <= 255));
  __CPROVER_assume((sec_r001344_5_1 >= 0) && (sec_r001344_5_1 <= 255));
  __CPROVER_assume((sec_r001344_5_2 >= 0) && (sec_r001344_5_2 <= 255));
  __CPROVER_assume((sec_r001344_6_1 >= 0) && (sec_r001344_6_1 <= 255));
  __CPROVER_assume((sec_r001344_6_2 >= 0) && (sec_r001344_6_2 <= 255));
  __CPROVER_assume((sec_r001344_7_1 >= 0) && (sec_r001344_7_1 <= 255));
  __CPROVER_assume((sec_r001344_7_2 >= 0) && (sec_r001344_7_2 <= 255));
  __CPROVER_assume((sec_r001344_8_1 >= 0) && (sec_r001344_8_1 <= 255));
  __CPROVER_assume((sec_r001344_8_2 >= 0) && (sec_r001344_8_2 <= 255));
  __CPROVER_assume((sec_r001344_9_1 >= 0) && (sec_r001344_9_1 <= 255));
  __CPROVER_assume((sec_r001344_9_2 >= 0) && (sec_r001344_9_2 <= 255));
  __CPROVER_assume((sec_r001344_10_1 >= 0) && (sec_r001344_10_1 <= 255));
  __CPROVER_assume((sec_r001344_10_2 >= 0) && (sec_r001344_10_2 <= 255));
  __CPROVER_assume((sec_r001344_11_1 >= 0) && (sec_r001344_11_1 <= 255));
  __CPROVER_assume((sec_r001344_11_2 >= 0) && (sec_r001344_11_2 <= 255));
  __CPROVER_assume((sec_r001344_12_1 >= 0) && (sec_r001344_12_1 <= 255));
  __CPROVER_assume((sec_r001344_12_2 >= 0) && (sec_r001344_12_2 <= 255));
  __CPROVER_assume((sec_r001344_13_1 >= 0) && (sec_r001344_13_1 <= 255));
  __CPROVER_assume((sec_r001344_13_2 >= 0) && (sec_r001344_13_2 <= 255));
  __CPROVER_assume((sec_r001344_14_1 >= 0) && (sec_r001344_14_1 <= 255));
  __CPROVER_assume((sec_r001344_14_2 >= 0) && (sec_r001344_14_2 <= 255));
  __CPROVER_assume((sec_r001344_15_1 >= 0) && (sec_r001344_15_1 <= 255));
  __CPROVER_assume((sec_r001344_15_2 >= 0) && (sec_r001344_15_2 <= 255));
  struct StreamBuffer_R001344_4413_0 st_var_0_1 = {0};
  struct StreamBuffer_R001344_4413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001344_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001344_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001344_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001344_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001344_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001344_0_2 + 7) & 15;
  struct EventLog_R001344_4413_1 st_var_1_1 = {0};
  struct EventLog_R001344_4413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001344_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001344_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001344_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001344_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001344_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001344_0_2 + 9) & 15;
  union RegisterBank_R001344_4413_0 u_var_1;
  union RegisterBank_R001344_4413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001344_4413_0(sec_r001344_0_1, sec_r001344_1_1, pub_r001344_2_1, pub_r001344_3_1, pub_r001344_4_1);
  int helper_flow_0_2 = fn_R001344_4413_0(sec_r001344_0_2, sec_r001344_1_2, pub_r001344_2_2, pub_r001344_3_2, pub_r001344_4_2);
  fn_R001344_4413_0_2(sec_r001344_0_1, sec_r001344_1_1, pub_r001344_2_1, pub_r001344_3_1, pub_r001344_4_1, sec_r001344_0_2, sec_r001344_1_2, pub_r001344_2_2, pub_r001344_3_2, pub_r001344_4_2);
  int helper_flow_1_1 = fn_R001344_4413_1(sec_r001344_1_1, sec_r001344_2_1, pub_r001344_3_1, pub_r001344_4_1);
  int helper_flow_1_2 = fn_R001344_4413_1(sec_r001344_1_2, sec_r001344_2_2, pub_r001344_3_2, pub_r001344_4_2);
  fn_R001344_4413_1_2(sec_r001344_1_1, sec_r001344_2_1, pub_r001344_3_1, pub_r001344_4_1, sec_r001344_1_2, sec_r001344_2_2, pub_r001344_3_2, pub_r001344_4_2);
  int helper_flow_2_1 = fn_R001344_4413_2(sec_r001344_2_1, pub_r001344_3_1);
  int helper_flow_2_2 = fn_R001344_4413_2(sec_r001344_2_2, pub_r001344_3_2);
  fn_R001344_4413_2_2(sec_r001344_2_1, pub_r001344_3_1, sec_r001344_2_2, pub_r001344_3_2);
  int helper_flow_3_1 = fn_R001344_4413_3(sec_r001344_3_1, pub_r001344_4_1, pub_r001344_5_1, pub_r001344_6_1);
  int helper_flow_3_2 = fn_R001344_4413_3(sec_r001344_3_2, pub_r001344_4_2, pub_r001344_5_2, pub_r001344_6_2);
  fn_R001344_4413_3_2(sec_r001344_3_1, pub_r001344_4_1, pub_r001344_5_1, pub_r001344_6_1, sec_r001344_3_2, pub_r001344_4_2, pub_r001344_5_2, pub_r001344_6_2);
  int helper_flow_4_1 = fn_R001344_4413_4(sec_r001344_4_1, sec_r001344_5_1, pub_r001344_6_1, pub_r001344_7_1, pub_r001344_8_1);
  int helper_flow_4_2 = fn_R001344_4413_4(sec_r001344_4_2, sec_r001344_5_2, pub_r001344_6_2, pub_r001344_7_2, pub_r001344_8_2);
  fn_R001344_4413_4_2(sec_r001344_4_1, sec_r001344_5_1, pub_r001344_6_1, pub_r001344_7_1, pub_r001344_8_1, sec_r001344_4_2, sec_r001344_5_2, pub_r001344_6_2, pub_r001344_7_2, pub_r001344_8_2);
  int helper_flow_5_1 = fn_R001344_4413_5(sec_r001344_5_1, pub_r001344_6_1, pub_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1);
  int helper_flow_5_2 = fn_R001344_4413_5(sec_r001344_5_2, pub_r001344_6_2, pub_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2);
  fn_R001344_4413_5_2(sec_r001344_5_1, pub_r001344_6_1, pub_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1, sec_r001344_5_2, pub_r001344_6_2, pub_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2);
  int helper_flow_6_1 = fn_R001344_4413_6(sec_r001344_6_1, sec_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1, pub_r001344_10_1);
  int helper_flow_6_2 = fn_R001344_4413_6(sec_r001344_6_2, sec_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2, pub_r001344_10_2);
  fn_R001344_4413_6_2(sec_r001344_6_1, sec_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1, pub_r001344_10_1, sec_r001344_6_2, sec_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2, pub_r001344_10_2);
  int helper_flow_7_1 = fn_R001344_4413_7(sec_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1, pub_r001344_10_1, pub_r001344_11_1);
  int helper_flow_7_2 = fn_R001344_4413_7(sec_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2, pub_r001344_10_2, pub_r001344_11_2);
  fn_R001344_4413_7_2(sec_r001344_7_1, pub_r001344_8_1, pub_r001344_9_1, pub_r001344_10_1, pub_r001344_11_1, sec_r001344_7_2, pub_r001344_8_2, pub_r001344_9_2, pub_r001344_10_2, pub_r001344_11_2);
  int stage_v_0_1 = ((pub_r001344_4_1 * 2) + 25) & 63;
  int stage_v_0_2 = ((pub_r001344_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = (((sec_r001344_12_1 * 3) + pub_r001344_6_1) + 45) & 127;
  int stage_v_1_2 = (((sec_r001344_12_2 * 3) + pub_r001344_6_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = (((sec_r001344_15_1 * 3) + pub_r001344_14_1) + 26) & 127;
  int stage_v_2_2 = (((sec_r001344_15_2 * 3) + pub_r001344_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = (((sec_r001344_11_1 * 3) + pub_r001344_6_1) + 37) & 127;
  int stage_v_3_2 = (((sec_r001344_11_2 * 3) + pub_r001344_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = (((helper_flow_1_1 * 3) + pub_r001344_11_1) + 3) & 127;
  int stage_v_4_2 = (((helper_flow_1_2 * 3) + pub_r001344_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = (((sec_r001344_15_1 * 3) + pub_r001344_2_1) + 34) & 127;
  int stage_v_5_2 = (((sec_r001344_15_2 * 3) + pub_r001344_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001344_7_1 * 2) + 33) & 63;
  int stage_v_6_2 = ((pub_r001344_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001344_14_1 * 3) + pub_r001344_3_1) + 13) & 127;
  int stage_v_7_2 = (((sec_r001344_14_2 * 3) + pub_r001344_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001344_18_1 * 2) + 14) & 63;
  int stage_v_8_2 = ((pub_r001344_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((sec_r001344_7_1 * 3) + pub_r001344_2_1) + 5) & 127;
  int stage_v_9_2 = (((sec_r001344_7_2 * 3) + pub_r001344_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = (((sec_r001344_1_1 * 3) + pub_r001344_4_1) + 34) & 127;
  int stage_v_10_2 = (((sec_r001344_1_2 * 3) + pub_r001344_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001344_14_1 * 3) + pub_r001344_19_1) + 39) & 127;
  int stage_v_11_2 = (((sec_r001344_14_2 * 3) + pub_r001344_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001344_5_1 * 3) + pub_r001344_7_1) + 30) & 127;
  int stage_v_12_2 = (((sec_r001344_5_2 * 3) + pub_r001344_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001344_6_1 * 2) + 14) & 63;
  int stage_v_13_2 = ((pub_r001344_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((stage_v_3_1 * 3) + pub_r001344_11_1) + 21) & 127;
  int stage_v_14_2 = (((stage_v_3_2 * 3) + pub_r001344_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = ((pub_r001344_15_1 * 2) + 45) & 63;
  int stage_v_15_2 = ((pub_r001344_15_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((stage_v_1_1 * 3) + pub_r001344_12_1) + 24) & 127;
  int stage_v_16_2 = (((stage_v_1_2 * 3) + pub_r001344_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = (((helper_flow_3_1 * 3) + pub_r001344_1_1) + 41) & 127;
  int stage_v_17_2 = (((helper_flow_3_2 * 3) + pub_r001344_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = (((sec_r001344_15_1 * 3) + pub_r001344_19_1) + 23) & 127;
  int stage_v_18_2 = (((sec_r001344_15_2 * 3) + pub_r001344_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((sec_r001344_6_1 * 3) + pub_r001344_12_1) + 6) & 127;
  int stage_v_19_2 = (((sec_r001344_6_2 * 3) + pub_r001344_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001344_18_1 * 2) + 38) & 63;
  int stage_v_20_2 = ((pub_r001344_18_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = (((helper_flow_1_1 * 3) + pub_r001344_10_1) + 37) & 127;
  int stage_v_21_2 = (((helper_flow_1_2 * 3) + pub_r001344_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_21_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_21_2 * 2)) & 255;
  int stage_v_22_1 = ((pub_r001344_4_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001344_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((helper_flow_3_1 * 3) + pub_r001344_12_1) + 40) & 127;
  int stage_v_23_2 = (((helper_flow_3_2 * 3) + pub_r001344_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = ((pub_r001344_2_1 * 2) + 31) & 63;
  int stage_v_24_2 = ((pub_r001344_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((helper_flow_3_1 * 3) + pub_r001344_2_1) + 38) & 127;
  int stage_v_25_2 = (((helper_flow_3_2 * 3) + pub_r001344_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = ((pub_r001344_16_1 * 2) + 15) & 63;
  int stage_v_26_2 = ((pub_r001344_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001344_12_1 * 2) + 48) & 63;
  int stage_v_27_2 = ((pub_r001344_12_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001344_1_1 * 3) + pub_r001344_13_1) + 45) & 127;
  int stage_v_28_2 = (((sec_r001344_1_2 * 3) + pub_r001344_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001344_5_1 * 3) + pub_r001344_5_1) + 18) & 127;
  int stage_v_29_2 = (((sec_r001344_5_2 * 3) + pub_r001344_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001344_12_1 * 2) + 43) & 63;
  int stage_v_30_2 = ((pub_r001344_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((helper_flow_4_1 * 3) + pub_r001344_13_1) + 23) & 127;
  int stage_v_31_2 = (((helper_flow_4_2 * 3) + pub_r001344_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001344_15_1 * 2) + 21) & 63;
  int stage_v_32_2 = ((pub_r001344_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((helper_flow_1_1 * 3) + pub_r001344_18_1) + 41) & 127;
  int stage_v_33_2 = (((helper_flow_1_2 * 3) + pub_r001344_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_9_1 * 3) + pub_r001344_3_1) + 44) & 127;
  int stage_v_34_2 = (((stage_v_9_2 * 3) + pub_r001344_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001344_14_1 * 2) + 23) & 63;
  int stage_v_35_2 = ((pub_r001344_14_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((stage_v_4_1 * 3) + pub_r001344_0_1) + 25) & 127;
  int stage_v_36_2 = (((stage_v_4_2 * 3) + pub_r001344_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001344_9_1 * 2) + 17) & 63;
  int stage_v_37_2 = ((pub_r001344_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001344_14_1 * 2) + 47) & 63;
  int stage_v_38_2 = ((pub_r001344_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001344_12_1 * 2) + 9) & 63;
  int stage_v_39_2 = ((pub_r001344_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((sec_r001344_14_1 * 3) + pub_r001344_1_1) + 22) & 127;
  int stage_v_40_2 = (((sec_r001344_14_2 * 3) + pub_r001344_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001344_0_1 * 2) + 40) & 63;
  int stage_v_41_2 = ((pub_r001344_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001344_3_1 * 3) + pub_r001344_0_1) + 36) & 127;
  int stage_v_42_2 = (((sec_r001344_3_2 * 3) + pub_r001344_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((helper_flow_6_1 * 3) + pub_r001344_13_1) + 23) & 127;
  int stage_v_43_2 = (((helper_flow_6_2 * 3) + pub_r001344_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = (((stage_v_9_1 * 3) + pub_r001344_0_1) + 37) & 127;
  int stage_v_44_2 = (((stage_v_9_2 * 3) + pub_r001344_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_44_1 * 3) + pub_r001344_2_1) + 30) & 127;
  int stage_v_45_2 = (((stage_v_44_2 * 3) + pub_r001344_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_11_1 * 3) + pub_r001344_6_1) + 3) & 127;
  int stage_v_46_2 = (((stage_v_11_2 * 3) + pub_r001344_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001344_18_1 * 2) + 35) & 63;
  int stage_v_47_2 = ((pub_r001344_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001344_7_1 * 2) + 13) & 63;
  int stage_v_48_2 = ((pub_r001344_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((helper_flow_0_1 * 3) + pub_r001344_6_1) + 27) & 127;
  int stage_v_49_2 = (((helper_flow_0_2 * 3) + pub_r001344_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001344_18_1 * 2) + 29) & 63;
  int stage_v_50_2 = ((pub_r001344_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_10_1 * 3) + pub_r001344_3_1) + 27) & 127;
  int stage_v_51_2 = (((stage_v_10_2 * 3) + pub_r001344_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((helper_flow_0_1 * 3) + pub_r001344_17_1) + 30) & 127;
  int stage_v_52_2 = (((helper_flow_0_2 * 3) + pub_r001344_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = (((sec_r001344_3_1 * 3) + pub_r001344_16_1) + 11) & 127;
  int stage_v_53_2 = (((sec_r001344_3_2 * 3) + pub_r001344_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = ((pub_r001344_10_1 * 2) + 38) & 63;
  int stage_v_54_2 = ((pub_r001344_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((sec_r001344_5_1 * 3) + pub_r001344_12_1) + 13) & 127;
  int stage_v_55_2 = (((sec_r001344_5_2 * 3) + pub_r001344_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((helper_flow_0_1 * 3) + pub_r001344_12_1) + 39) & 127;
  int stage_v_56_2 = (((helper_flow_0_2 * 3) + pub_r001344_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((stage_v_11_1 * 3) + pub_r001344_17_1) + 31) & 127;
  int stage_v_57_2 = (((stage_v_11_2 * 3) + pub_r001344_17_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = ((pub_r001344_13_1 * 2) + 22) & 63;
  int stage_v_58_2 = ((pub_r001344_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001344_12_1 * 2) + 19) & 63;
  int stage_v_59_2 = ((pub_r001344_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((helper_flow_2_1 * 3) + pub_r001344_18_1) + 16) & 127;
  int stage_v_60_2 = (((helper_flow_2_2 * 3) + pub_r001344_18_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = ((pub_r001344_14_1 * 2) + 49) & 63;
  int stage_v_61_2 = ((pub_r001344_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((sec_r001344_7_1 * 3) + pub_r001344_13_1) + 3) & 127;
  int stage_v_62_2 = (((sec_r001344_7_2 * 3) + pub_r001344_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((sec_r001344_13_1 * 3) + pub_r001344_3_1) + 13) & 127;
  int stage_v_63_2 = (((sec_r001344_13_2 * 3) + pub_r001344_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_21_1 * 3) + pub_r001344_4_1) + 10) & 127;
  int stage_v_64_2 = (((stage_v_21_2 * 3) + pub_r001344_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_29_1 * 3) + pub_r001344_14_1) + 44) & 127;
  int stage_v_65_2 = (((stage_v_29_2 * 3) + pub_r001344_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001344_19_1 * 2) + 43) & 63;
  int stage_v_66_2 = ((pub_r001344_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001344_0_1 * 2) + 32) & 63;
  int stage_v_67_2 = ((pub_r001344_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001344_18_1 * 2) + 47) & 63;
  int stage_v_68_2 = ((pub_r001344_18_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001344_9_1 * 2) + 19) & 63;
  int stage_v_69_2 = ((pub_r001344_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001344_7_1 * 3) + pub_r001344_9_1) + 44) & 127;
  int stage_v_70_2 = (((sec_r001344_7_2 * 3) + pub_r001344_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((sec_r001344_2_1 * 3) + pub_r001344_10_1) + 13) & 127;
  int stage_v_71_2 = (((sec_r001344_2_2 * 3) + pub_r001344_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001344_12_1 * 2) + 47) & 63;
  int stage_v_72_2 = ((pub_r001344_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_33_1 * 3) + pub_r001344_7_1) + 11) & 127;
  int stage_v_73_2 = (((stage_v_33_2 * 3) + pub_r001344_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((sec_r001344_11_1 * 3) + pub_r001344_11_1) + 40) & 127;
  int stage_v_74_2 = (((sec_r001344_11_2 * 3) + pub_r001344_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_11_1 * 3) + pub_r001344_2_1) + 15) & 127;
  int stage_v_75_2 = (((stage_v_11_2 * 3) + pub_r001344_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((helper_flow_5_1 * 3) + pub_r001344_12_1) + 22) & 127;
  int stage_v_76_2 = (((helper_flow_5_2 * 3) + pub_r001344_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = (((sec_r001344_11_1 * 3) + pub_r001344_11_1) + 36) & 127;
  int stage_v_77_2 = (((sec_r001344_11_2 * 3) + pub_r001344_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001344_8_1 * 2) + 40) & 63;
  int stage_v_78_2 = ((pub_r001344_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_28_1 * 3) + pub_r001344_1_1) + 25) & 127;
  int stage_v_79_2 = (((stage_v_28_2 * 3) + pub_r001344_1_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = (((stage_v_42_1 * 3) + pub_r001344_19_1) + 32) & 127;
  int stage_v_80_2 = (((stage_v_42_2 * 3) + pub_r001344_19_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_80_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_80_2 * 2)) & 255;
  int stage_v_81_1 = (((stage_v_80_1 * 3) + pub_r001344_3_1) + 24) & 127;
  int stage_v_81_2 = (((stage_v_80_2 * 3) + pub_r001344_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = ((pub_r001344_1_1 * 2) + 39) & 63;
  int stage_v_82_2 = ((pub_r001344_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (((stage_v_57_1 * 3) + pub_r001344_10_1) + 45) & 127;
  int stage_v_83_2 = (((stage_v_57_2 * 3) + pub_r001344_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_83_1 * 3) + pub_r001344_2_1) + 21) & 127;
  int stage_v_84_2 = (((stage_v_83_2 * 3) + pub_r001344_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_77_1 * 3) + pub_r001344_2_1) + 25) & 127;
  int stage_v_85_2 = (((stage_v_77_2 * 3) + pub_r001344_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001344_13_1 * 2) + 33) & 63;
  int stage_v_86_2 = ((pub_r001344_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((stage_v_63_1 * 3) + pub_r001344_2_1) + 26) & 127;
  int stage_v_87_2 = (((stage_v_63_2 * 3) + pub_r001344_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_74_1 * 3) + pub_r001344_5_1) + 20) & 127;
  int stage_v_88_2 = (((stage_v_74_2 * 3) + pub_r001344_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_16_1 * 3) + pub_r001344_9_1) + 21) & 127;
  int stage_v_89_2 = (((stage_v_16_2 * 3) + pub_r001344_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_79_1 * 3) + pub_r001344_8_1) + 7) & 127;
  int stage_v_90_2 = (((stage_v_79_2 * 3) + pub_r001344_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001344_0_1 * 2) + 43) & 63;
  int stage_v_91_2 = ((pub_r001344_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001344_18_1 * 2) + 14) & 63;
  int stage_v_92_2 = ((pub_r001344_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_84_1 * 3) + pub_r001344_11_1) + 3) & 127;
  int stage_v_93_2 = (((stage_v_84_2 * 3) + pub_r001344_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_14_1 * 3) + pub_r001344_19_1) + 41) & 127;
  int stage_v_94_2 = (((stage_v_14_2 * 3) + pub_r001344_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001344_10_1 * 3) + pub_r001344_6_1) + 31) & 127;
  int stage_v_95_2 = (((sec_r001344_10_2 * 3) + pub_r001344_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001344_11_1 * 2) + 36) & 63;
  int stage_v_96_2 = ((pub_r001344_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_11_1 * 3) + pub_r001344_17_1) + 30) & 127;
  int stage_v_97_2 = (((stage_v_11_2 * 3) + pub_r001344_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_31_1 * 3) + pub_r001344_17_1) + 45) & 127;
  int stage_v_98_2 = (((stage_v_31_2 * 3) + pub_r001344_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_74_1 * 3) + pub_r001344_11_1) + 37) & 127;
  int stage_v_99_2 = (((stage_v_74_2 * 3) + pub_r001344_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = (((sec_r001344_14_1 * 3) + pub_r001344_18_1) + 41) & 127;
  int stage_v_100_2 = (((sec_r001344_14_2 * 3) + pub_r001344_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_100_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_100_2 * 2)) & 255;
  int stage_v_101_1 = (((stage_v_65_1 * 3) + pub_r001344_8_1) + 34) & 127;
  int stage_v_101_2 = (((stage_v_65_2 * 3) + pub_r001344_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001344_2_1 * 2) + 16) & 63;
  int stage_v_102_2 = ((pub_r001344_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001344_17_1 * 2) + 48) & 63;
  int stage_v_103_2 = ((pub_r001344_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_36_1 * 3) + pub_r001344_7_1) + 8) & 127;
  int stage_v_104_2 = (((stage_v_36_2 * 3) + pub_r001344_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_4_1 * 3) + pub_r001344_14_1) + 7) & 127;
  int stage_v_105_2 = (((stage_v_4_2 * 3) + pub_r001344_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((sec_r001344_15_1 * 3) + pub_r001344_16_1) + 20) & 127;
  int stage_v_106_2 = (((sec_r001344_15_2 * 3) + pub_r001344_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001344_5_1 * 2) + 5) & 63;
  int stage_v_107_2 = ((pub_r001344_5_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_79_1 * 3) + pub_r001344_7_1) + 21) & 127;
  int stage_v_108_2 = (((stage_v_79_2 * 3) + pub_r001344_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((sec_r001344_11_1 * 3) + pub_r001344_4_1) + 28) & 127;
  int stage_v_109_2 = (((sec_r001344_11_2 * 3) + pub_r001344_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((sec_r001344_8_1 * 3) + pub_r001344_10_1) + 38) & 127;
  int stage_v_110_2 = (((sec_r001344_8_2 * 3) + pub_r001344_10_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001344_0_1 * 2) + 33) & 63;
  int stage_v_111_2 = ((pub_r001344_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001344_3_1 * 2) + 46) & 63;
  int stage_v_112_2 = ((pub_r001344_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001344_19_1 * 2) + 23) & 63;
  int stage_v_113_2 = ((pub_r001344_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001344_15_1 * 2) + 8) & 63;
  int stage_v_114_2 = ((pub_r001344_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001344_2_1 * 2) + 43) & 63;
  int stage_v_115_2 = ((pub_r001344_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001344_9_1 * 2) + 30) & 63;
  int stage_v_116_2 = ((pub_r001344_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = (((stage_v_106_1 * 3) + pub_r001344_8_1) + 17) & 127;
  int stage_v_117_2 = (((stage_v_106_2 * 3) + pub_r001344_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_101_1 * 3) + pub_r001344_13_1) + 45) & 127;
  int stage_v_118_2 = (((stage_v_101_2 * 3) + pub_r001344_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001344_5_1 * 2) + 42) & 63;
  int stage_v_119_2 = ((pub_r001344_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((sec_r001344_0_1 * 3) + pub_r001344_18_1) + 20) & 127;
  int stage_v_120_2 = (((sec_r001344_0_2 * 3) + pub_r001344_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001344_10_1 * 2) + 37) & 63;
  int stage_v_121_2 = ((pub_r001344_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001344_12_1 * 2) + 36) & 63;
  int stage_v_122_2 = ((pub_r001344_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_3_1 * 3) + pub_r001344_16_1) + 38) & 127;
  int stage_v_123_2 = (((stage_v_3_2 * 3) + pub_r001344_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_100_1 * 3) + pub_r001344_7_1) + 3) & 127;
  int stage_v_124_2 = (((stage_v_100_2 * 3) + pub_r001344_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001344_3_1 * 2) + 33) & 63;
  int stage_v_125_2 = ((pub_r001344_3_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001344_9_1 * 2) + 14) & 63;
  int stage_v_126_2 = ((pub_r001344_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001344_11_1 * 2) + 48) & 63;
  int stage_v_127_2 = ((pub_r001344_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_52_1 * 3) + pub_r001344_2_1) + 40) & 127;
  int stage_v_128_2 = (((stage_v_52_2 * 3) + pub_r001344_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_108_1 * 3) + pub_r001344_19_1) + 24) & 127;
  int stage_v_129_2 = (((stage_v_108_2 * 3) + pub_r001344_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001344_16_1 * 2) + 38) & 63;
  int stage_v_130_2 = ((pub_r001344_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((sec_r001344_9_1 * 3) + pub_r001344_9_1) + 21) & 127;
  int stage_v_131_2 = (((sec_r001344_9_2 * 3) + pub_r001344_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = (((sec_r001344_8_1 * 3) + pub_r001344_18_1) + 35) & 127;
  int stage_v_132_2 = (((sec_r001344_8_2 * 3) + pub_r001344_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = ((pub_r001344_13_1 * 2) + 34) & 63;
  int stage_v_133_2 = ((pub_r001344_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001344_9_1 * 2) + 19) & 63;
  int stage_v_134_2 = ((pub_r001344_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_12_1 * 3) + pub_r001344_15_1) + 44) & 127;
  int stage_v_135_2 = (((stage_v_12_2 * 3) + pub_r001344_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((sec_r001344_5_1 * 3) + pub_r001344_16_1) + 35) & 127;
  int stage_v_136_2 = (((sec_r001344_5_2 * 3) + pub_r001344_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_45_1 * 3) + pub_r001344_10_1) + 28) & 127;
  int stage_v_137_2 = (((stage_v_45_2 * 3) + pub_r001344_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_55_1 * 3) + pub_r001344_1_1) + 35) & 127;
  int stage_v_138_2 = (((stage_v_55_2 * 3) + pub_r001344_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001344_19_1 * 2) + 44) & 63;
  int stage_v_139_2 = ((pub_r001344_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001344_0_1 * 2) + 42) & 63;
  int stage_v_140_2 = ((pub_r001344_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_16_1 * 3) + pub_r001344_4_1) + 44) & 127;
  int stage_v_141_2 = (((stage_v_16_2 * 3) + pub_r001344_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_138_1 * 3) + pub_r001344_0_1) + 36) & 127;
  int stage_v_142_2 = (((stage_v_138_2 * 3) + pub_r001344_0_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001344_3_1 * 2) + 41) & 63;
  int stage_v_143_2 = ((pub_r001344_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_49_1 * 3) + pub_r001344_2_1) + 37) & 127;
  int stage_v_144_2 = (((stage_v_49_2 * 3) + pub_r001344_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001344_18_1 * 2) + 39) & 63;
  int stage_v_145_2 = ((pub_r001344_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001344_3_1 * 2) + 40) & 63;
  int stage_v_146_2 = ((pub_r001344_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((stage_v_65_1 * 3) + pub_r001344_13_1) + 34) & 127;
  int stage_v_147_2 = (((stage_v_65_2 * 3) + pub_r001344_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = ((pub_r001344_6_1 * 2) + 43) & 63;
  int stage_v_148_2 = ((pub_r001344_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001344_5_1 * 2) + 21) & 63;
  int stage_v_149_2 = ((pub_r001344_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001344_19_1 * 2) + 27) & 63;
  int stage_v_150_2 = ((pub_r001344_19_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_52_1 * 3) + pub_r001344_5_1) + 12) & 127;
  int stage_v_151_2 = (((stage_v_52_2 * 3) + pub_r001344_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = (((stage_v_75_1 * 3) + pub_r001344_4_1) + 21) & 127;
  int stage_v_152_2 = (((stage_v_75_2 * 3) + pub_r001344_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_141_1 * 3) + pub_r001344_1_1) + 37) & 127;
  int stage_v_153_2 = (((stage_v_141_2 * 3) + pub_r001344_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_129_1 * 3) + pub_r001344_1_1) + 21) & 127;
  int stage_v_154_2 = (((stage_v_129_2 * 3) + pub_r001344_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = ((pub_r001344_6_1 * 2) + 13) & 63;
  int stage_v_155_2 = ((pub_r001344_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001344_7_1 * 2) + 7) & 63;
  int stage_v_156_2 = ((pub_r001344_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001344_14_1 * 2) + 40) & 63;
  int stage_v_157_2 = ((pub_r001344_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001344_8_1 * 2) + 29) & 63;
  int stage_v_158_2 = ((pub_r001344_8_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_87_1 * 3) + pub_r001344_16_1) + 19) & 127;
  int stage_v_159_2 = (((stage_v_87_2 * 3) + pub_r001344_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_29_1 * 3) + pub_r001344_10_1) + 39) & 127;
  int stage_v_160_2 = (((stage_v_29_2 * 3) + pub_r001344_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001344_11_1 * 2) + 38) & 63;
  int stage_v_161_2 = ((pub_r001344_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_90_1 * 3) + pub_r001344_17_1) + 24) & 127;
  int stage_v_162_2 = (((stage_v_90_2 * 3) + pub_r001344_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_108_1 * 3) + pub_r001344_0_1) + 27) & 127;
  int stage_v_163_2 = (((stage_v_108_2 * 3) + pub_r001344_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001344_0_1 * 2) + 48) & 63;
  int stage_v_164_2 = ((pub_r001344_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001344_18_1 * 2) + 9) & 63;
  int stage_v_165_2 = ((pub_r001344_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((pub_r001344_3_1 * 2) + 7) & 63;
  int stage_v_166_2 = ((pub_r001344_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001344_11_1 * 2) + 39) & 63;
  int stage_v_167_2 = ((pub_r001344_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((stage_v_12_1 * 3) + pub_r001344_13_1) + 19) & 127;
  int stage_v_168_2 = (((stage_v_12_2 * 3) + pub_r001344_13_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001344_11_1 * 2) + 25) & 63;
  int stage_v_169_2 = ((pub_r001344_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_128_1 * 3) + pub_r001344_0_1) + 10) & 127;
  int stage_v_170_2 = (((stage_v_128_2 * 3) + pub_r001344_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001344_1_1 * 2) + 42) & 63;
  int stage_v_171_2 = ((pub_r001344_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((sec_r001344_14_1 * 3) + pub_r001344_11_1) + 33) & 127;
  int stage_v_172_2 = (((sec_r001344_14_2 * 3) + pub_r001344_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001344_6_1 * 2) + 50) & 63;
  int stage_v_173_2 = ((pub_r001344_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_141_1 * 3) + pub_r001344_1_1) + 23) & 127;
  int stage_v_174_2 = (((stage_v_141_2 * 3) + pub_r001344_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = ((pub_r001344_15_1 * 2) + 29) & 63;
  int stage_v_175_2 = ((pub_r001344_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001344_19_1 * 2) + 23) & 63;
  int stage_v_176_2 = ((pub_r001344_19_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_57_1 * 3) + pub_r001344_2_1) + 21) & 127;
  int stage_v_177_2 = (((stage_v_57_2 * 3) + pub_r001344_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_23_1 * 3) + pub_r001344_5_1) + 29) & 127;
  int stage_v_178_2 = (((stage_v_23_2 * 3) + pub_r001344_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((stage_v_76_1 * 3) + pub_r001344_1_1) + 20) & 127;
  int stage_v_179_2 = (((stage_v_76_2 * 3) + pub_r001344_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_179_1 * 3) + pub_r001344_4_1) + 10) & 127;
  int stage_v_180_2 = (((stage_v_179_2 * 3) + pub_r001344_4_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((stage_v_120_1 * 3) + pub_r001344_15_1) + 4) & 127;
  int stage_v_181_2 = (((stage_v_120_2 * 3) + pub_r001344_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001344_17_1 * 2) + 33) & 63;
  int stage_v_182_2 = ((pub_r001344_17_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_34_1 * 3) + pub_r001344_8_1) + 13) & 127;
  int stage_v_183_2 = (((stage_v_34_2 * 3) + pub_r001344_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = ((pub_r001344_9_1 * 2) + 12) & 63;
  int stage_v_184_2 = ((pub_r001344_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((stage_v_168_1 * 3) + pub_r001344_7_1) + 44) & 127;
  int stage_v_185_2 = (((stage_v_168_2 * 3) + pub_r001344_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_132_1 * 3) + pub_r001344_17_1) + 10) & 127;
  int stage_v_186_2 = (((stage_v_132_2 * 3) + pub_r001344_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001344_13_1 * 2) + 18) & 63;
  int stage_v_187_2 = ((pub_r001344_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((stage_v_94_1 * 3) + pub_r001344_4_1) + 24) & 127;
  int stage_v_188_2 = (((stage_v_94_2 * 3) + pub_r001344_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001344_4_1 * 2) + 18) & 63;
  int stage_v_189_2 = ((pub_r001344_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_142_1 * 3) + pub_r001344_5_1) + 34) & 127;
  int stage_v_190_2 = (((stage_v_142_2 * 3) + pub_r001344_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001344_6_1 * 2) + 22) & 63;
  int stage_v_191_2 = ((pub_r001344_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001344_18_1 * 2) + 15) & 63;
  int stage_v_192_2 = ((pub_r001344_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_100_1 * 3) + pub_r001344_7_1) + 5) & 127;
  int stage_v_193_2 = (((stage_v_100_2 * 3) + pub_r001344_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001344_5_1 * 2) + 42) & 63;
  int stage_v_194_2 = ((pub_r001344_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_44_1 * 3) + pub_r001344_3_1) + 25) & 127;
  int stage_v_195_2 = (((stage_v_44_2 * 3) + pub_r001344_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_31_1 * 3) + pub_r001344_5_1) + 7) & 127;
  int stage_v_196_2 = (((stage_v_31_2 * 3) + pub_r001344_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_141_1 * 3) + pub_r001344_0_1) + 9) & 127;
  int stage_v_197_2 = (((stage_v_141_2 * 3) + pub_r001344_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_123_1 * 3) + pub_r001344_0_1) + 32) & 127;
  int stage_v_198_2 = (((stage_v_123_2 * 3) + pub_r001344_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_7_1 * 3) + pub_r001344_16_1) + 31) & 127;
  int stage_v_199_2 = (((stage_v_7_2 * 3) + pub_r001344_16_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = (((stage_v_147_1 * 3) + pub_r001344_3_1) + 20) & 127;
  int stage_v_200_2 = (((stage_v_147_2 * 3) + pub_r001344_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = ((pub_r001344_12_1 * 2) + 25) & 63;
  int stage_v_201_2 = ((pub_r001344_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_55_1 * 3) + pub_r001344_11_1) + 40) & 127;
  int stage_v_202_2 = (((stage_v_55_2 * 3) + pub_r001344_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001344_1_1 * 2) + 10) & 63;
  int stage_v_203_2 = ((pub_r001344_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((helper_flow_1_1 * 3) + pub_r001344_7_1) + 12) & 127;
  int stage_v_204_2 = (((helper_flow_1_2 * 3) + pub_r001344_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001344_1_1 * 2) + 50) & 63;
  int stage_v_205_2 = ((pub_r001344_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001344_12_1 * 2) + 45) & 63;
  int stage_v_206_2 = ((pub_r001344_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001344_9_1 * 2) + 41) & 63;
  int stage_v_207_2 = ((pub_r001344_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((helper_flow_7_1 * 3) + pub_r001344_19_1) + 3) & 127;
  int stage_v_208_2 = (((helper_flow_7_2 * 3) + pub_r001344_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((sec_r001344_1_1 * 3) + pub_r001344_19_1) + 31) & 127;
  int stage_v_209_2 = (((sec_r001344_1_2 * 3) + pub_r001344_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001344_3_1 * 2) + 36) & 63;
  int stage_v_210_2 = ((pub_r001344_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001344_4_1 * 2) + 38) & 63;
  int stage_v_211_2 = ((pub_r001344_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_12_1 * 3) + pub_r001344_16_1) + 17) & 127;
  int stage_v_212_2 = (((stage_v_12_2 * 3) + pub_r001344_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((helper_flow_4_1 * 3) + pub_r001344_0_1) + 7) & 127;
  int stage_v_213_2 = (((helper_flow_4_2 * 3) + pub_r001344_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_19_1 * 3) + pub_r001344_16_1) + 28) & 127;
  int stage_v_214_2 = (((stage_v_19_2 * 3) + pub_r001344_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((helper_flow_7_1 * 3) + pub_r001344_12_1) + 5) & 127;
  int stage_v_215_2 = (((helper_flow_7_2 * 3) + pub_r001344_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((sec_r001344_12_1 * 3) + pub_r001344_2_1) + 25) & 127;
  int stage_v_216_2 = (((sec_r001344_12_2 * 3) + pub_r001344_2_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001344_14_1 * 2) + 19) & 63;
  int stage_v_217_2 = ((pub_r001344_14_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001344_13_1 * 2) + 30) & 63;
  int stage_v_218_2 = ((pub_r001344_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((sec_r001344_13_1 * 3) + pub_r001344_5_1) + 34) & 127;
  int stage_v_219_2 = (((sec_r001344_13_2 * 3) + pub_r001344_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_43_1 * 3) + pub_r001344_9_1) + 41) & 127;
  int stage_v_220_2 = (((stage_v_43_2 * 3) + pub_r001344_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001344_11_1 * 2) + 16) & 63;
  int stage_v_221_2 = ((pub_r001344_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001344_16_1 * 2) + 16) & 63;
  int stage_v_222_2 = ((pub_r001344_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((stage_v_23_1 * 3) + pub_r001344_0_1) + 40) & 127;
  int stage_v_223_2 = (((stage_v_23_2 * 3) + pub_r001344_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_135_1 * 3) + pub_r001344_9_1) + 21) & 127;
  int stage_v_224_2 = (((stage_v_135_2 * 3) + pub_r001344_9_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001344_11_1 * 2) + 27) & 63;
  int stage_v_225_2 = ((pub_r001344_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_64_1 * 3) + pub_r001344_0_1) + 17) & 127;
  int stage_v_226_2 = (((stage_v_64_2 * 3) + pub_r001344_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001344_19_1 * 2) + 9) & 63;
  int stage_v_227_2 = ((pub_r001344_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001344_13_1 * 2) + 39) & 63;
  int stage_v_228_2 = ((pub_r001344_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001344_6_1 * 2) + 25) & 63;
  int stage_v_229_2 = ((pub_r001344_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001344_5_1 * 2) + 22) & 63;
  int stage_v_230_2 = ((pub_r001344_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001344_12_1 * 2) + 28) & 63;
  int stage_v_231_2 = ((pub_r001344_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((stage_v_46_1 * 3) + pub_r001344_19_1) + 6) & 127;
  int stage_v_232_2 = (((stage_v_46_2 * 3) + pub_r001344_19_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_212_1 * 3) + pub_r001344_7_1) + 35) & 127;
  int stage_v_233_2 = (((stage_v_212_2 * 3) + pub_r001344_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_23_1 * 3) + pub_r001344_0_1) + 31) & 127;
  int stage_v_234_2 = (((stage_v_23_2 * 3) + pub_r001344_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_142_1 * 3) + pub_r001344_14_1) + 11) & 127;
  int stage_v_235_2 = (((stage_v_142_2 * 3) + pub_r001344_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001344_14_1 * 2) + 13) & 63;
  int stage_v_236_2 = ((pub_r001344_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001344_10_1 * 2) + 33) & 63;
  int stage_v_237_2 = ((pub_r001344_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_34_1 * 3) + pub_r001344_8_1) + 29) & 127;
  int stage_v_238_2 = (((stage_v_34_2 * 3) + pub_r001344_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001344_5_1 * 2) + 45) & 63;
  int stage_v_239_2 = ((pub_r001344_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_3_1 * 3) + pub_r001344_10_1) + 4) & 127;
  int stage_v_240_2 = (((stage_v_3_2 * 3) + pub_r001344_10_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((sec_r001344_8_1 * 3) + pub_r001344_18_1) + 42) & 127;
  int stage_v_241_2 = (((sec_r001344_8_2 * 3) + pub_r001344_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_226_1 * 3) + pub_r001344_10_1) + 20) & 127;
  int stage_v_242_2 = (((stage_v_226_2 * 3) + pub_r001344_10_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001344_10_1 * 2) + 46) & 63;
  int stage_v_243_2 = ((pub_r001344_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_208_1 * 3) + pub_r001344_14_1) + 14) & 127;
  int stage_v_244_2 = (((stage_v_208_2 * 3) + pub_r001344_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = ((pub_r001344_10_1 * 2) + 15) & 63;
  int stage_v_245_2 = ((pub_r001344_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001344_7_1 * 2) + 7) & 63;
  int stage_v_246_2 = ((pub_r001344_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001344_9_1 * 2) + 37) & 63;
  int stage_v_247_2 = ((pub_r001344_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_88_1 * 3) + pub_r001344_18_1) + 39) & 127;
  int stage_v_248_2 = (((stage_v_88_2 * 3) + pub_r001344_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = ((pub_r001344_8_1 * 2) + 11) & 63;
  int stage_v_249_2 = ((pub_r001344_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001344_3_1 * 2) + 38) & 63;
  int stage_v_250_2 = ((pub_r001344_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001344_7_1 * 2) + 14) & 63;
  int stage_v_251_2 = ((pub_r001344_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_208_1 * 3) + pub_r001344_7_1) + 41) & 127;
  int stage_v_252_2 = (((stage_v_208_2 * 3) + pub_r001344_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_14_1 * 3) + pub_r001344_12_1) + 16) & 127;
  int stage_v_253_2 = (((stage_v_14_2 * 3) + pub_r001344_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((sec_r001344_4_1 * 3) + pub_r001344_19_1) + 26) & 127;
  int stage_v_254_2 = (((sec_r001344_4_2 * 3) + pub_r001344_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001344_16_1 * 2) + 11) & 63;
  int stage_v_255_2 = ((pub_r001344_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_254_1 * 3) + pub_r001344_18_1) + 21) & 127;
  int stage_v_256_2 = (((stage_v_254_2 * 3) + pub_r001344_18_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((sec_r001344_13_1 * 3) + pub_r001344_4_1) + 39) & 127;
  int stage_v_257_2 = (((sec_r001344_13_2 * 3) + pub_r001344_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001344_18_1 * 2) + 45) & 63;
  int stage_v_258_2 = ((pub_r001344_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_100_1 * 3) + pub_r001344_9_1) + 19) & 127;
  int stage_v_259_2 = (((stage_v_100_2 * 3) + pub_r001344_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_5_1 * 3) + pub_r001344_16_1) + 40) & 127;
  int stage_v_260_2 = (((stage_v_5_2 * 3) + pub_r001344_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_232_1 * 3) + pub_r001344_12_1) + 7) & 127;
  int stage_v_261_2 = (((stage_v_232_2 * 3) + pub_r001344_12_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_80_1 * 3) + pub_r001344_4_1) + 35) & 127;
  int stage_v_262_2 = (((stage_v_80_2 * 3) + pub_r001344_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_154_1 * 3) + pub_r001344_15_1) + 27) & 127;
  int stage_v_263_2 = (((stage_v_154_2 * 3) + pub_r001344_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001344_15_1 * 2) + 28) & 63;
  int stage_v_264_2 = ((pub_r001344_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_151_1 * 3) + pub_r001344_6_1) + 26) & 127;
  int stage_v_265_2 = (((stage_v_151_2 * 3) + pub_r001344_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_193_1 * 3) + pub_r001344_16_1) + 8) & 127;
  int stage_v_266_2 = (((stage_v_193_2 * 3) + pub_r001344_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001344_4_1 * 2) + 19) & 63;
  int stage_v_267_2 = ((pub_r001344_4_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((helper_flow_7_1 * 3) + pub_r001344_3_1) + 6) & 127;
  int stage_v_268_2 = (((helper_flow_7_2 * 3) + pub_r001344_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001344_14_1 * 2) + 46) & 63;
  int stage_v_269_2 = ((pub_r001344_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001344_2_1 * 2) + 21) & 63;
  int stage_v_270_2 = ((pub_r001344_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_232_1 * 3) + pub_r001344_11_1) + 12) & 127;
  int stage_v_271_2 = (((stage_v_232_2 * 3) + pub_r001344_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001344_8_1 * 2) + 17) & 63;
  int stage_v_272_2 = ((pub_r001344_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_181_1 * 3) + pub_r001344_3_1) + 24) & 127;
  int stage_v_273_2 = (((stage_v_181_2 * 3) + pub_r001344_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_95_1 * 3) + pub_r001344_16_1) + 41) & 127;
  int stage_v_274_2 = (((stage_v_95_2 * 3) + pub_r001344_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001344_0_1 * 2) + 50) & 63;
  int stage_v_275_2 = ((pub_r001344_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = (((stage_v_43_1 * 3) + pub_r001344_10_1) + 40) & 127;
  int stage_v_276_2 = (((stage_v_43_2 * 3) + pub_r001344_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001344_7_1 * 2) + 31) & 63;
  int stage_v_277_2 = ((pub_r001344_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = ((pub_r001344_1_1 * 2) + 15) & 63;
  int stage_v_278_2 = ((pub_r001344_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001344_4_1 * 2) + 24) & 63;
  int stage_v_279_2 = ((pub_r001344_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_260_1 * 3) + pub_r001344_2_1) + 40) & 127;
  int stage_v_280_2 = (((stage_v_260_2 * 3) + pub_r001344_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_135_1 * 3) + pub_r001344_0_1) + 12) & 127;
  int stage_v_281_2 = (((stage_v_135_2 * 3) + pub_r001344_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001344_8_1 * 2) + 36) & 63;
  int stage_v_282_2 = ((pub_r001344_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_16_1 * 3) + pub_r001344_11_1) + 28) & 127;
  int stage_v_283_2 = (((stage_v_16_2 * 3) + pub_r001344_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001344_12_1 * 2) + 7) & 63;
  int stage_v_284_2 = ((pub_r001344_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001344_19_1 * 2) + 18) & 63;
  int stage_v_285_2 = ((pub_r001344_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_108_1 * 3) + pub_r001344_11_1) + 11) & 127;
  int stage_v_286_2 = (((stage_v_108_2 * 3) + pub_r001344_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001344_12_1 * 2) + 23) & 63;
  int stage_v_287_2 = ((pub_r001344_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001344_8_1 * 2) + 50) & 63;
  int stage_v_288_2 = ((pub_r001344_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_261_1 * 3) + pub_r001344_15_1) + 45) & 127;
  int stage_v_289_2 = (((stage_v_261_2 * 3) + pub_r001344_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001344_12_1 * 2) + 25) & 63;
  int stage_v_290_2 = ((pub_r001344_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_199_1 * 3) + pub_r001344_2_1) + 41) & 127;
  int stage_v_291_2 = (((stage_v_199_2 * 3) + pub_r001344_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001344_9_1 * 2) + 41) & 63;
  int stage_v_292_2 = ((pub_r001344_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001344_9_1 * 2) + 21) & 63;
  int stage_v_293_2 = ((pub_r001344_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001344_14_1 * 2) + 24) & 63;
  int stage_v_294_2 = ((pub_r001344_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_151_1 * 3) + pub_r001344_11_1) + 13) & 127;
  int stage_v_295_2 = (((stage_v_151_2 * 3) + pub_r001344_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_260_1 * 3) + pub_r001344_18_1) + 37) & 127;
  int stage_v_296_2 = (((stage_v_260_2 * 3) + pub_r001344_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_240_1 * 3) + pub_r001344_11_1) + 45) & 127;
  int stage_v_297_2 = (((stage_v_240_2 * 3) + pub_r001344_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_212_1 * 3) + pub_r001344_8_1) + 41) & 127;
  int stage_v_298_2 = (((stage_v_212_2 * 3) + pub_r001344_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_100_1 * 3) + pub_r001344_19_1) + 43) & 127;
  int stage_v_299_2 = (((stage_v_100_2 * 3) + pub_r001344_19_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001344_19_1 * 2) + 11) & 63;
  int stage_v_300_2 = ((pub_r001344_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((stage_v_70_1 * 3) + pub_r001344_11_1) + 27) & 127;
  int stage_v_301_2 = (((stage_v_70_2 * 3) + pub_r001344_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((stage_v_57_1 * 3) + pub_r001344_15_1) + 32) & 127;
  int stage_v_302_2 = (((stage_v_57_2 * 3) + pub_r001344_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001344_14_1 * 2) + 38) & 63;
  int stage_v_303_2 = ((pub_r001344_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_259_1 * 3) + pub_r001344_11_1) + 31) & 127;
  int stage_v_304_2 = (((stage_v_259_2 * 3) + pub_r001344_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001344_16_1 * 2) + 12) & 63;
  int stage_v_305_2 = ((pub_r001344_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_71_1 * 3) + pub_r001344_1_1) + 31) & 127;
  int stage_v_306_2 = (((stage_v_71_2 * 3) + pub_r001344_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_2_1 * 3) + pub_r001344_1_1) + 27) & 127;
  int stage_v_307_2 = (((stage_v_2_2 * 3) + pub_r001344_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = (((stage_v_77_1 * 3) + pub_r001344_5_1) + 13) & 127;
  int stage_v_308_2 = (((stage_v_77_2 * 3) + pub_r001344_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001344_1_1 * 2) + 22) & 63;
  int stage_v_309_2 = ((pub_r001344_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_214_1 * 3) + pub_r001344_6_1) + 37) & 127;
  int stage_v_310_2 = (((stage_v_214_2 * 3) + pub_r001344_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_310_1 * 3) + pub_r001344_8_1) + 45) & 127;
  int stage_v_311_2 = (((stage_v_310_2 * 3) + pub_r001344_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = ((pub_r001344_5_1 * 2) + 28) & 63;
  int stage_v_312_2 = ((pub_r001344_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = ((pub_r001344_1_1 * 2) + 41) & 63;
  int stage_v_313_2 = ((pub_r001344_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = ((pub_r001344_19_1 * 2) + 18) & 63;
  int stage_v_314_2 = ((pub_r001344_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = (((stage_v_136_1 * 3) + pub_r001344_6_1) + 31) & 127;
  int stage_v_315_2 = (((stage_v_136_2 * 3) + pub_r001344_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((helper_flow_6_1 * 3) + pub_r001344_2_1) + 29) & 127;
  int stage_v_316_2 = (((helper_flow_6_2 * 3) + pub_r001344_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = (((stage_v_118_1 * 3) + pub_r001344_17_1) + 21) & 127;
  int stage_v_317_2 = (((stage_v_118_2 * 3) + pub_r001344_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001344_10_1 * 2) + 37) & 63;
  int stage_v_318_2 = ((pub_r001344_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_117_1 * 3) + pub_r001344_14_1) + 18) & 127;
  int stage_v_319_2 = (((stage_v_117_2 * 3) + pub_r001344_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = (((stage_v_297_1 * 3) + pub_r001344_10_1) + 11) & 127;
  int stage_v_320_2 = (((stage_v_297_2 * 3) + pub_r001344_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_70_1 * 3) + pub_r001344_17_1) + 23) & 127;
  int stage_v_321_2 = (((stage_v_70_2 * 3) + pub_r001344_17_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((helper_flow_0_1 * 3) + pub_r001344_11_1) + 43) & 127;
  int stage_v_322_2 = (((helper_flow_0_2 * 3) + pub_r001344_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001344_6_1 * 2) + 16) & 63;
  int stage_v_323_2 = ((pub_r001344_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001344_9_1 * 2) + 47) & 63;
  int stage_v_324_2 = ((pub_r001344_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_286_1 * 3) + pub_r001344_11_1) + 24) & 127;
  int stage_v_325_2 = (((stage_v_286_2 * 3) + pub_r001344_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_177_1 * 3) + pub_r001344_2_1) + 23) & 127;
  int stage_v_326_2 = (((stage_v_177_2 * 3) + pub_r001344_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001344_6_1 * 2) + 14) & 63;
  int stage_v_327_2 = ((pub_r001344_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_181_1 * 3) + pub_r001344_10_1) + 31) & 127;
  int stage_v_328_2 = (((stage_v_181_2 * 3) + pub_r001344_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_271_1 * 3) + pub_r001344_0_1) + 23) & 127;
  int stage_v_329_2 = (((stage_v_271_2 * 3) + pub_r001344_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001344_11_1 * 2) + 21) & 63;
  int stage_v_330_2 = ((pub_r001344_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001344_16_1 * 2) + 48) & 63;
  int stage_v_331_2 = ((pub_r001344_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001344_3_1 * 2) + 22) & 63;
  int stage_v_332_2 = ((pub_r001344_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001344_0_1 * 2) + 8) & 63;
  int stage_v_333_2 = ((pub_r001344_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_52_1 * 3) + pub_r001344_13_1) + 14) & 127;
  int stage_v_334_2 = (((stage_v_52_2 * 3) + pub_r001344_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001344_7_1 * 2) + 19) & 63;
  int stage_v_335_2 = ((pub_r001344_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = (((stage_v_14_1 * 3) + pub_r001344_14_1) + 35) & 127;
  int stage_v_336_2 = (((stage_v_14_2 * 3) + pub_r001344_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_5_1 * 3) + pub_r001344_7_1) + 31) & 127;
  int stage_v_337_2 = (((stage_v_5_2 * 3) + pub_r001344_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_57_1 * 3) + pub_r001344_14_1) + 9) & 127;
  int stage_v_338_2 = (((stage_v_57_2 * 3) + pub_r001344_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001344_3_1 * 2) + 47) & 63;
  int stage_v_339_2 = ((pub_r001344_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001344_13_1 * 2) + 25) & 63;
  int stage_v_340_2 = ((pub_r001344_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = (((stage_v_135_1 * 3) + pub_r001344_15_1) + 21) & 127;
  int stage_v_341_2 = (((stage_v_135_2 * 3) + pub_r001344_15_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_105_1 * 3) + pub_r001344_10_1) + 11) & 127;
  int stage_v_342_2 = (((stage_v_105_2 * 3) + pub_r001344_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = ((pub_r001344_5_1 * 2) + 25) & 63;
  int stage_v_343_2 = ((pub_r001344_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((sec_r001344_2_1 * 3) + pub_r001344_15_1) + 42) & 127;
  int stage_v_344_2 = (((sec_r001344_2_2 * 3) + pub_r001344_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001344_7_1 * 2) + 48) & 63;
  int stage_v_345_2 = ((pub_r001344_7_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((helper_flow_3_1 * 3) + pub_r001344_1_1) + 22) & 127;
  int stage_v_346_2 = (((helper_flow_3_2 * 3) + pub_r001344_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001344_15_1 * 2) + 33) & 63;
  int stage_v_347_2 = ((pub_r001344_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = ((pub_r001344_14_1 * 2) + 34) & 63;
  int stage_v_348_2 = ((pub_r001344_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001344_17_1 * 2) + 11) & 63;
  int stage_v_349_2 = ((pub_r001344_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_45_1 * 3) + pub_r001344_3_1) + 19) & 127;
  int stage_v_350_2 = (((stage_v_45_2 * 3) + pub_r001344_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_85_1 * 3) + pub_r001344_4_1) + 11) & 127;
  int stage_v_351_2 = (((stage_v_85_2 * 3) + pub_r001344_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001344_8_1 * 2) + 32) & 63;
  int stage_v_352_2 = ((pub_r001344_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001344_8_1 * 2) + 20) & 63;
  int stage_v_353_2 = ((pub_r001344_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001344_4_1 * 2) + 14) & 63;
  int stage_v_354_2 = ((pub_r001344_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_105_1 * 3) + pub_r001344_3_1) + 12) & 127;
  int stage_v_355_2 = (((stage_v_105_2 * 3) + pub_r001344_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_21_1 * 3) + pub_r001344_12_1) + 39) & 127;
  int stage_v_356_2 = (((stage_v_21_2 * 3) + pub_r001344_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_71_1 * 3) + pub_r001344_0_1) + 31) & 127;
  int stage_v_357_2 = (((stage_v_71_2 * 3) + pub_r001344_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_75_1 * 3) + pub_r001344_13_1) + 45) & 127;
  int stage_v_358_2 = (((stage_v_75_2 * 3) + pub_r001344_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001344_11_1 * 2) + 46) & 63;
  int stage_v_359_2 = ((pub_r001344_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001344_13_1 * 2) + 14) & 63;
  int stage_v_360_2 = ((pub_r001344_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = (((stage_v_53_1 * 3) + pub_r001344_17_1) + 38) & 127;
  int stage_v_361_2 = (((stage_v_53_2 * 3) + pub_r001344_17_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_252_1 * 3) + pub_r001344_11_1) + 28) & 127;
  int stage_v_362_2 = (((stage_v_252_2 * 3) + pub_r001344_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_193_1 * 3) + pub_r001344_16_1) + 24) & 127;
  int stage_v_363_2 = (((stage_v_193_2 * 3) + pub_r001344_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_337_1 * 3) + pub_r001344_4_1) + 6) & 127;
  int stage_v_364_2 = (((stage_v_337_2 * 3) + pub_r001344_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001344_11_1 * 2) + 10) & 63;
  int stage_v_365_2 = ((pub_r001344_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_364_1 * 3) + pub_r001344_6_1) + 8) & 127;
  int stage_v_366_2 = (((stage_v_364_2 * 3) + pub_r001344_6_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_361_1 * 3) + pub_r001344_16_1) + 23) & 127;
  int stage_v_367_2 = (((stage_v_361_2 * 3) + pub_r001344_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001344_12_1 * 2) + 35) & 63;
  int stage_v_368_2 = ((pub_r001344_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001344_8_1 * 2) + 36) & 63;
  int stage_v_369_2 = ((pub_r001344_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001344_17_1 * 2) + 31) & 63;
  int stage_v_370_2 = ((pub_r001344_17_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((stage_v_356_1 * 3) + pub_r001344_10_1) + 28) & 127;
  int stage_v_371_2 = (((stage_v_356_2 * 3) + pub_r001344_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001344_18_1 * 2) + 21) & 63;
  int stage_v_372_2 = ((pub_r001344_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_268_1 * 3) + pub_r001344_3_1) + 18) & 127;
  int stage_v_373_2 = (((stage_v_268_2 * 3) + pub_r001344_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001344_13_1 * 2) + 34) & 63;
  int stage_v_374_2 = ((pub_r001344_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001344_10_1 * 2) + 10) & 63;
  int stage_v_375_2 = ((pub_r001344_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = (((helper_flow_4_1 * 3) + pub_r001344_17_1) + 18) & 127;
  int stage_v_376_2 = (((helper_flow_4_2 * 3) + pub_r001344_17_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001344_15_1 * 2) + 24) & 63;
  int stage_v_377_2 = ((pub_r001344_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_49_1 * 3) + pub_r001344_11_1) + 27) & 127;
  int stage_v_378_2 = (((stage_v_49_2 * 3) + pub_r001344_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_271_1 * 3) + pub_r001344_4_1) + 25) & 127;
  int stage_v_379_2 = (((stage_v_271_2 * 3) + pub_r001344_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001344_2_1 * 2) + 6) & 63;
  int stage_v_380_2 = ((pub_r001344_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001344_3_1 * 2) + 27) & 63;
  int stage_v_381_2 = ((pub_r001344_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = (((stage_v_208_1 * 3) + pub_r001344_15_1) + 27) & 127;
  int stage_v_382_2 = (((stage_v_208_2 * 3) + pub_r001344_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = ((pub_r001344_18_1 * 2) + 19) & 63;
  int stage_v_383_2 = ((pub_r001344_18_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001344_10_1 * 2) + 46) & 63;
  int stage_v_384_2 = ((pub_r001344_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = (((stage_v_216_1 * 3) + pub_r001344_8_1) + 28) & 127;
  int stage_v_385_2 = (((stage_v_216_2 * 3) + pub_r001344_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = ((pub_r001344_11_1 * 2) + 42) & 63;
  int stage_v_386_2 = ((pub_r001344_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001344_16_1 * 2) + 20) & 63;
  int stage_v_387_2 = ((pub_r001344_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = (((stage_v_289_1 * 3) + pub_r001344_1_1) + 15) & 127;
  int stage_v_388_2 = (((stage_v_289_2 * 3) + pub_r001344_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001344_3_1 * 2) + 30) & 63;
  int stage_v_389_2 = ((pub_r001344_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((sec_r001344_6_1 * 3) + pub_r001344_13_1) + 9) & 127;
  int stage_v_390_2 = (((sec_r001344_6_2 * 3) + pub_r001344_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = ((pub_r001344_4_1 * 2) + 41) & 63;
  int stage_v_391_2 = ((pub_r001344_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001344_3_1 * 2) + 44) & 63;
  int stage_v_392_2 = ((pub_r001344_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_198_1 * 3) + pub_r001344_0_1) + 25) & 127;
  int stage_v_393_2 = (((stage_v_198_2 * 3) + pub_r001344_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_200_1 * 3) + pub_r001344_14_1) + 33) & 127;
  int stage_v_394_2 = (((stage_v_200_2 * 3) + pub_r001344_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = (((stage_v_123_1 * 3) + pub_r001344_19_1) + 41) & 127;
  int stage_v_395_2 = (((stage_v_123_2 * 3) + pub_r001344_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_129_1 * 3) + pub_r001344_12_1) + 27) & 127;
  int stage_v_396_2 = (((stage_v_129_2 * 3) + pub_r001344_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_142_1 * 3) + pub_r001344_13_1) + 29) & 127;
  int stage_v_397_2 = (((stage_v_142_2 * 3) + pub_r001344_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_373_1 * 3) + pub_r001344_3_1) + 12) & 127;
  int stage_v_398_2 = (((stage_v_373_2 * 3) + pub_r001344_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001344_2_1 * 2) + 32) & 63;
  int stage_v_399_2 = ((pub_r001344_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_57_1 * 3) + pub_r001344_13_1) + 10) & 127;
  int stage_v_400_2 = (((stage_v_57_2 * 3) + pub_r001344_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = (((sec_r001344_0_1 * 3) + pub_r001344_16_1) + 6) & 127;
  int stage_v_401_2 = (((sec_r001344_0_2 * 3) + pub_r001344_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001344_12_1 * 2) + 7) & 63;
  int stage_v_402_2 = ((pub_r001344_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001344_13_1 * 2) + 34) & 63;
  int stage_v_403_2 = ((pub_r001344_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_254_1 * 3) + pub_r001344_2_1) + 16) & 127;
  int stage_v_404_2 = (((stage_v_254_2 * 3) + pub_r001344_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_297_1 * 3) + pub_r001344_5_1) + 23) & 127;
  int stage_v_405_2 = (((stage_v_297_2 * 3) + pub_r001344_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001344_6_1 * 2) + 38) & 63;
  int stage_v_406_2 = ((pub_r001344_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001344_5_1 * 2) + 24) & 63;
  int stage_v_407_2 = ((pub_r001344_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_153_1 * 3) + pub_r001344_13_1) + 8) & 127;
  int stage_v_408_2 = (((stage_v_153_2 * 3) + pub_r001344_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001344_13_1 * 2) + 27) & 63;
  int stage_v_409_2 = ((pub_r001344_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001344_4_1 * 2) + 9) & 63;
  int stage_v_410_2 = ((pub_r001344_4_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001344_18_1 * 2) + 34) & 63;
  int stage_v_411_2 = ((pub_r001344_18_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001344_17_1 * 2) + 49) & 63;
  int stage_v_412_2 = ((pub_r001344_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = ((pub_r001344_15_1 * 2) + 6) & 63;
  int stage_v_413_2 = ((pub_r001344_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001344_19_1 * 2) + 10) & 63;
  int stage_v_414_2 = ((pub_r001344_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_181_1 * 3) + pub_r001344_1_1) + 42) & 127;
  int stage_v_415_2 = (((stage_v_181_2 * 3) + pub_r001344_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001344_17_1 * 2) + 24) & 63;
  int stage_v_416_2 = ((pub_r001344_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_219_1 * 3) + pub_r001344_17_1) + 17) & 127;
  int stage_v_417_2 = (((stage_v_219_2 * 3) + pub_r001344_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001344_1_1 * 2) + 17) & 63;
  int stage_v_418_2 = ((pub_r001344_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_172_1 * 3) + pub_r001344_15_1) + 26) & 127;
  int stage_v_419_2 = (((stage_v_172_2 * 3) + pub_r001344_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_394_1 * 3) + pub_r001344_1_1) + 42) & 127;
  int stage_v_420_2 = (((stage_v_394_2 * 3) + pub_r001344_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_216_1 * 3) + pub_r001344_15_1) + 40) & 127;
  int stage_v_421_2 = (((stage_v_216_2 * 3) + pub_r001344_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001344_11_1 * 2) + 44) & 63;
  int stage_v_422_2 = ((pub_r001344_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = ((pub_r001344_13_1 * 2) + 23) & 63;
  int stage_v_423_2 = ((pub_r001344_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_423_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_423_2) & 127;
  int stage_v_424_1 = (((stage_v_1_1 * 3) + pub_r001344_10_1) + 15) & 127;
  int stage_v_424_2 = (((stage_v_1_2 * 3) + pub_r001344_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((stage_v_5_1 * 3) + pub_r001344_16_1) + 34) & 127;
  int stage_v_425_2 = (((stage_v_5_2 * 3) + pub_r001344_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = (((stage_v_154_1 * 3) + pub_r001344_16_1) + 13) & 127;
  int stage_v_426_2 = (((stage_v_154_2 * 3) + pub_r001344_16_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_266_1 * 3) + pub_r001344_16_1) + 25) & 127;
  int stage_v_427_2 = (((stage_v_266_2 * 3) + pub_r001344_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_49_1 * 3) + pub_r001344_6_1) + 44) & 127;
  int stage_v_428_2 = (((stage_v_49_2 * 3) + pub_r001344_6_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_419_1 * 3) + pub_r001344_12_1) + 38) & 127;
  int stage_v_429_2 = (((stage_v_419_2 * 3) + pub_r001344_12_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_154_1 * 3) + pub_r001344_19_1) + 24) & 127;
  int stage_v_430_2 = (((stage_v_154_2 * 3) + pub_r001344_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001344_14_1 * 2) + 16) & 63;
  int stage_v_431_2 = ((pub_r001344_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001344_17_1 * 2) + 19) & 63;
  int stage_v_432_2 = ((pub_r001344_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = ((pub_r001344_16_1 * 2) + 8) & 63;
  int stage_v_433_2 = ((pub_r001344_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((stage_v_297_1 * 3) + pub_r001344_2_1) + 13) & 127;
  int stage_v_434_2 = (((stage_v_297_2 * 3) + pub_r001344_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = (((stage_v_404_1 * 3) + pub_r001344_13_1) + 30) & 127;
  int stage_v_435_2 = (((stage_v_404_2 * 3) + pub_r001344_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001344_0_1 * 2) + 32) & 63;
  int stage_v_436_2 = ((pub_r001344_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_177_1 * 3) + pub_r001344_11_1) + 32) & 127;
  int stage_v_437_2 = (((stage_v_177_2 * 3) + pub_r001344_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001344_19_1 * 2) + 11) & 63;
  int stage_v_438_2 = ((pub_r001344_19_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_421_1 * 3) + pub_r001344_15_1) + 31) & 127;
  int stage_v_439_2 = (((stage_v_421_2 * 3) + pub_r001344_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_378_1 * 3) + pub_r001344_4_1) + 11) & 127;
  int stage_v_440_2 = (((stage_v_378_2 * 3) + pub_r001344_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_338_1 * 3) + pub_r001344_5_1) + 15) & 127;
  int stage_v_441_2 = (((stage_v_338_2 * 3) + pub_r001344_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((stage_v_181_1 * 3) + pub_r001344_2_1) + 5) & 127;
  int stage_v_442_2 = (((stage_v_181_2 * 3) + pub_r001344_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001344_17_1 * 2) + 37) & 63;
  int stage_v_443_2 = ((pub_r001344_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = (((stage_v_424_1 * 3) + pub_r001344_11_1) + 20) & 127;
  int stage_v_444_2 = (((stage_v_424_2 * 3) + pub_r001344_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_444_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_444_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_444_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_444_2 * 2)) & 255;
  int stage_v_445_1 = ((pub_r001344_6_1 * 2) + 44) & 63;
  int stage_v_445_2 = ((pub_r001344_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_366_1 * 3) + pub_r001344_8_1) + 8) & 127;
  int stage_v_446_2 = (((stage_v_366_2 * 3) + pub_r001344_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((sec_r001344_3_1 * 3) + pub_r001344_14_1) + 19) & 127;
  int stage_v_447_2 = (((sec_r001344_3_2 * 3) + pub_r001344_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_7_1 * 3) + pub_r001344_6_1) + 41) & 127;
  int stage_v_448_2 = (((stage_v_7_2 * 3) + pub_r001344_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = (((stage_v_195_1 * 3) + pub_r001344_17_1) + 30) & 127;
  int stage_v_449_2 = (((stage_v_195_2 * 3) + pub_r001344_17_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = (((stage_v_449_1 * 3) + pub_r001344_8_1) + 34) & 127;
  int stage_v_450_2 = (((stage_v_449_2 * 3) + pub_r001344_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = (((stage_v_212_1 * 3) + pub_r001344_13_1) + 38) & 127;
  int stage_v_451_2 = (((stage_v_212_2 * 3) + pub_r001344_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = ((pub_r001344_9_1 * 2) + 5) & 63;
  int stage_v_452_2 = ((pub_r001344_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_452_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_452_2) & 127;
  int stage_v_453_1 = ((pub_r001344_12_1 * 2) + 25) & 63;
  int stage_v_453_2 = ((pub_r001344_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((stage_v_233_1 * 3) + pub_r001344_0_1) + 22) & 127;
  int stage_v_454_2 = (((stage_v_233_2 * 3) + pub_r001344_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = (((stage_v_415_1 * 3) + pub_r001344_13_1) + 10) & 127;
  int stage_v_455_2 = (((stage_v_415_2 * 3) + pub_r001344_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_248_1 * 3) + pub_r001344_19_1) + 38) & 127;
  int stage_v_456_2 = (((stage_v_248_2 * 3) + pub_r001344_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((stage_v_179_1 * 3) + pub_r001344_1_1) + 8) & 127;
  int stage_v_457_2 = (((stage_v_179_2 * 3) + pub_r001344_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = ((pub_r001344_3_1 * 2) + 30) & 63;
  int stage_v_458_2 = ((pub_r001344_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_44_1 * 3) + pub_r001344_14_1) + 39) & 127;
  int stage_v_459_2 = (((stage_v_44_2 * 3) + pub_r001344_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001344_6_1 * 2) + 24) & 63;
  int stage_v_460_2 = ((pub_r001344_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = (((stage_v_223_1 * 3) + pub_r001344_6_1) + 20) & 127;
  int stage_v_461_2 = (((stage_v_223_2 * 3) + pub_r001344_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = (((stage_v_426_1 * 3) + pub_r001344_17_1) + 15) & 127;
  int stage_v_462_2 = (((stage_v_426_2 * 3) + pub_r001344_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((stage_v_101_1 * 3) + pub_r001344_18_1) + 23) & 127;
  int stage_v_463_2 = (((stage_v_101_2 * 3) + pub_r001344_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((helper_flow_3_1 * 3) + pub_r001344_16_1) + 39) & 127;
  int stage_v_464_2 = (((helper_flow_3_2 * 3) + pub_r001344_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = (((stage_v_358_1 * 3) + pub_r001344_18_1) + 23) & 127;
  int stage_v_465_2 = (((stage_v_358_2 * 3) + pub_r001344_18_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = ((pub_r001344_9_1 * 2) + 43) & 63;
  int stage_v_466_2 = ((pub_r001344_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_34_1 * 3) + pub_r001344_8_1) + 43) & 127;
  int stage_v_467_2 = (((stage_v_34_2 * 3) + pub_r001344_8_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = (((stage_v_425_1 * 3) + pub_r001344_10_1) + 17) & 127;
  int stage_v_468_2 = (((stage_v_425_2 * 3) + pub_r001344_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001344_2_1 * 2) + 20) & 63;
  int stage_v_469_2 = ((pub_r001344_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = ((pub_r001344_12_1 * 2) + 39) & 63;
  int stage_v_470_2 = ((pub_r001344_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001344_16_1 * 2) + 21) & 63;
  int stage_v_471_2 = ((pub_r001344_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = (((stage_v_42_1 * 3) + pub_r001344_7_1) + 5) & 127;
  int stage_v_472_2 = (((stage_v_42_2 * 3) + pub_r001344_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = (((stage_v_430_1 * 3) + pub_r001344_8_1) + 27) & 127;
  int stage_v_473_2 = (((stage_v_430_2 * 3) + pub_r001344_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = (((stage_v_427_1 * 3) + pub_r001344_4_1) + 22) & 127;
  int stage_v_474_2 = (((stage_v_427_2 * 3) + pub_r001344_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = ((pub_r001344_2_1 * 2) + 15) & 63;
  int stage_v_475_2 = ((pub_r001344_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = (((stage_v_421_1 * 3) + pub_r001344_16_1) + 10) & 127;
  int stage_v_476_2 = (((stage_v_421_2 * 3) + pub_r001344_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = ((pub_r001344_17_1 * 2) + 36) & 63;
  int stage_v_477_2 = ((pub_r001344_17_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = (((sec_r001344_12_1 * 3) + pub_r001344_11_1) + 12) & 127;
  int stage_v_478_2 = (((sec_r001344_12_2 * 3) + pub_r001344_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = (((stage_v_152_1 * 3) + pub_r001344_3_1) + 36) & 127;
  int stage_v_479_2 = (((stage_v_152_2 * 3) + pub_r001344_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = (((stage_v_25_1 * 3) + pub_r001344_0_1) + 35) & 127;
  int stage_v_480_2 = (((stage_v_25_2 * 3) + pub_r001344_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = ((pub_r001344_13_1 * 2) + 19) & 63;
  int stage_v_481_2 = ((pub_r001344_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = ((pub_r001344_2_1 * 2) + 15) & 63;
  int stage_v_482_2 = ((pub_r001344_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = (((stage_v_172_1 * 3) + pub_r001344_9_1) + 39) & 127;
  int stage_v_483_2 = (((stage_v_172_2 * 3) + pub_r001344_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_483_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_483_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_483_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_483_2 * 2)) & 255;
  int stage_v_484_1 = ((pub_r001344_9_1 * 2) + 25) & 63;
  int stage_v_484_2 = ((pub_r001344_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_484_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_484_2) & 127;
  int stage_v_485_1 = (((stage_v_479_1 * 3) + pub_r001344_9_1) + 14) & 127;
  int stage_v_485_2 = (((stage_v_479_2 * 3) + pub_r001344_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = ((pub_r001344_17_1 * 2) + 47) & 63;
  int stage_v_486_2 = ((pub_r001344_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((pub_r001344_15_1 * 2) + 13) & 63;
  int stage_v_487_2 = ((pub_r001344_15_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = ((pub_r001344_1_1 * 2) + 18) & 63;
  int stage_v_488_2 = ((pub_r001344_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_488_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_488_2) & 127;
  int stage_v_489_1 = ((pub_r001344_6_1 * 2) + 16) & 63;
  int stage_v_489_2 = ((pub_r001344_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = (((stage_v_202_1 * 3) + pub_r001344_5_1) + 12) & 127;
  int stage_v_490_2 = (((stage_v_202_2 * 3) + pub_r001344_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = (((stage_v_257_1 * 3) + pub_r001344_11_1) + 38) & 127;
  int stage_v_491_2 = (((stage_v_257_2 * 3) + pub_r001344_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_491_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_491_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_491_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_491_2 * 2)) & 255;
  int stage_v_492_1 = (((stage_v_337_1 * 3) + pub_r001344_6_1) + 27) & 127;
  int stage_v_492_2 = (((stage_v_337_2 * 3) + pub_r001344_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = (((stage_v_181_1 * 3) + pub_r001344_9_1) + 11) & 127;
  int stage_v_493_2 = (((stage_v_181_2 * 3) + pub_r001344_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = ((pub_r001344_14_1 * 2) + 13) & 63;
  int stage_v_494_2 = ((pub_r001344_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_494_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_494_2) & 127;
  int stage_v_495_1 = (((stage_v_100_1 * 3) + pub_r001344_14_1) + 5) & 127;
  int stage_v_495_2 = (((stage_v_100_2 * 3) + pub_r001344_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_495_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_495_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_495_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_495_2 * 2)) & 255;
  int stage_v_496_1 = (((stage_v_440_1 * 3) + pub_r001344_3_1) + 41) & 127;
  int stage_v_496_2 = (((stage_v_440_2 * 3) + pub_r001344_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = ((pub_r001344_7_1 * 2) + 9) & 63;
  int stage_v_497_2 = ((pub_r001344_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = (((stage_v_462_1 * 3) + pub_r001344_6_1) + 10) & 127;
  int stage_v_498_2 = (((stage_v_462_2 * 3) + pub_r001344_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_498_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_498_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_498_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_498_2 * 2)) & 255;
  int stage_v_499_1 = ((pub_r001344_15_1 * 2) + 27) & 63;
  int stage_v_499_2 = ((pub_r001344_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = (((stage_v_351_1 * 3) + pub_r001344_8_1) + 10) & 127;
  int stage_v_500_2 = (((stage_v_351_2 * 3) + pub_r001344_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = ((pub_r001344_15_1 * 2) + 11) & 63;
  int stage_v_501_2 = ((pub_r001344_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_501_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_501_2) & 127;
  int stage_v_502_1 = (((stage_v_478_1 * 3) + pub_r001344_11_1) + 40) & 127;
  int stage_v_502_2 = (((stage_v_478_2 * 3) + pub_r001344_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_502_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_502_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_502_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_502_2 * 2)) & 255;
  int stage_v_503_1 = ((pub_r001344_18_1 * 2) + 40) & 63;
  int stage_v_503_2 = ((pub_r001344_18_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = ((pub_r001344_18_1 * 2) + 27) & 63;
  int stage_v_504_2 = ((pub_r001344_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = ((pub_r001344_3_1 * 2) + 35) & 63;
  int stage_v_505_2 = ((pub_r001344_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_505_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_505_2) & 127;
  int stage_v_506_1 = (((stage_v_162_1 * 3) + pub_r001344_5_1) + 28) & 127;
  int stage_v_506_2 = (((stage_v_162_2 * 3) + pub_r001344_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_506_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_506_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_506_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_506_2 * 2)) & 255;
  int stage_v_507_1 = ((pub_r001344_15_1 * 2) + 35) & 63;
  int stage_v_507_2 = ((pub_r001344_15_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_507_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_507_2) & 127;
  int stage_v_508_1 = ((pub_r001344_13_1 * 2) + 33) & 63;
  int stage_v_508_2 = ((pub_r001344_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_508_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_508_2) & 127;
  int stage_v_509_1 = (((stage_v_404_1 * 3) + pub_r001344_19_1) + 23) & 127;
  int stage_v_509_2 = (((stage_v_404_2 * 3) + pub_r001344_19_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_509_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_509_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_509_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_509_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001344_4_1 != sec_r001344_4_2);
  __CPROVER_assume(sec_r001344_9_1 != sec_r001344_9_2);
  __CPROVER_assume(sec_r001344_5_1 != sec_r001344_5_2);
  __CPROVER_assume(pub_r001344_3_1 == pub_r001344_3_2);
  __CPROVER_assume(sec_r001344_3_1 != sec_r001344_3_2);
  __CPROVER_assume(sec_r001344_8_1 != sec_r001344_8_2);
  __CPROVER_assume(pub_r001344_19_1 == pub_r001344_19_2);
  __CPROVER_assume(pub_r001344_2_1 == pub_r001344_2_2);
  __CPROVER_assume(sec_r001344_6_1 != sec_r001344_6_2);
  __CPROVER_assume(sec_r001344_12_1 != sec_r001344_12_2);
  __CPROVER_assume(pub_r001344_17_1 == pub_r001344_17_2);
  __CPROVER_assume(pub_r001344_15_1 == pub_r001344_15_2);
  __CPROVER_assume(pub_r001344_6_1 == pub_r001344_6_2);
  __CPROVER_assume(sec_r001344_10_1 != sec_r001344_10_2);
  __CPROVER_assume(pub_r001344_8_1 == pub_r001344_8_2);
  __CPROVER_assume(pub_r001344_7_1 == pub_r001344_7_2);
  __CPROVER_assume(pub_r001344_10_1 == pub_r001344_10_2);
  __CPROVER_assume(sec_r001344_13_1 != sec_r001344_13_2);
  __CPROVER_assume(sec_r001344_14_1 != sec_r001344_14_2);
  __CPROVER_assume(pub_r001344_12_1 == pub_r001344_12_2);
  __CPROVER_assume(sec_r001344_11_1 != sec_r001344_11_2);
  __CPROVER_assume(pub_r001344_16_1 == pub_r001344_16_2);
  __CPROVER_assume(pub_r001344_13_1 == pub_r001344_13_2);
  __CPROVER_assume(pub_r001344_1_1 == pub_r001344_1_2);
  __CPROVER_assume(pub_r001344_4_1 == pub_r001344_4_2);
  __CPROVER_assume(sec_r001344_1_1 != sec_r001344_1_2);
  __CPROVER_assume(sec_r001344_7_1 != sec_r001344_7_2);
  __CPROVER_assume(pub_r001344_11_1 == pub_r001344_11_2);
  __CPROVER_assume(pub_r001344_9_1 == pub_r001344_9_2);
  __CPROVER_assume(pub_r001344_14_1 == pub_r001344_14_2);
  __CPROVER_assume(sec_r001344_0_1 != sec_r001344_0_2);
  __CPROVER_assume(sec_r001344_2_1 != sec_r001344_2_2);
  __CPROVER_assume(pub_r001344_5_1 == pub_r001344_5_2);
  __CPROVER_assume(pub_r001344_18_1 == pub_r001344_18_2);
  __CPROVER_assume(sec_r001344_15_1 != sec_r001344_15_2);
  __CPROVER_assume(pub_r001344_0_1 == pub_r001344_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.head == st_var_0_2.head);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.checksum == st_var_0_2.checksum);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.seq == st_var_1_2.seq);
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
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
}


