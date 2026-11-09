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
struct Transaction_R001760_6013_0
{
  int rate;
  unsigned char account_id;
  short balance;
  int buffer[3];
};
struct StreamBuffer_R001760_6013_1
{
  short checksum;
  int state;
  unsigned char head;
  unsigned char capacity;
  short watermark;
  int buffer[3];
};
struct EventLog_R001760_6013_2
{
  int seq;
  int severity;
  int facility;
  int buffer[3];
};
union ColorPixel_R001760_6013_0
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
void fn_R001760_6013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_67_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_67_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_67_1) & 63;
  aux_2 = (aux_2 + window_67_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_97_1 = local_arr_1[aux_1 % 3];
  int metric_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_97_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_67_1 == window_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_97_1 == metric_97_2);
}

int fn_R001760_6013_0(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_67 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_67) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int metric_97 = local_arr[aux % 3];
  acc = (acc + (metric_97 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int checksum_21_1 = 0;
  int checksum_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_21_1 = ((checksum_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_21_2 = ((checksum_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_21_1) & 127;
    acc_2 = (acc_2 + checksum_21_2) & 127;
  }

  int margin_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_68_1 > 24)
  {
    acc_1 = ((acc_1 + (margin_68_1 * 2)) + 5) & 127;
    aux_1 ^= margin_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_68_2 > 24)
  {
    acc_2 = ((acc_2 + (margin_68_2 * 2)) + 5) & 127;
    aux_2 ^= margin_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_68_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_21_1 == checksum_21_2);
  assert(margin_68_1 == margin_68_2);
}

int fn_R001760_6013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int checksum_21 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_21 = ((checksum_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_21) & 127;
  }

  int margin_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_68 > 24)
  {
    acc = ((acc + (margin_68 * 2)) + 5) & 127;
    aux ^= margin_68 & 15;
  }
  else
  {
    acc = ((acc - margin_68) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int threshold_27_1 = 0;
  int threshold_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_27_1 = ((threshold_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_27_2 = ((threshold_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_27_1) & 127;
    acc_2 = (acc_2 + threshold_27_2) & 127;
  }

  int weight_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_83_1)
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

  switch (weight_83_2)
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
  int quantum_57_1 = local_arr_1[aux_1 % 3];
  int quantum_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_57_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_27_1 == threshold_27_2);
  assert(weight_83_1 == weight_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_57_1 == quantum_57_2);
}

int fn_R001760_6013_2(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int threshold_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_27 = ((threshold_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_27) & 127;
  }

  int weight_83 = (aux + st.buffer[1]) & 3;
  switch (weight_83)
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
  int quantum_57 = local_arr[aux % 3];
  acc = (acc + (quantum_57 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_82_1) & 63;
  aux_2 = (aux_2 + accumulator_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_57_1 = local_arr_1[aux_1 % 3];
  int phase_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_57_2 * 2)) & 127;
  int metric_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_72_1 > 33)
  {
    acc_1 = ((acc_1 + (metric_72_1 * 2)) + 5) & 127;
    aux_1 ^= metric_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_72_2 > 33)
  {
    acc_2 = ((acc_2 + (metric_72_2 * 2)) + 5) & 127;
    aux_2 ^= metric_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_72_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_82_1 == accumulator_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_57_1 == phase_57_2);
  assert(metric_72_1 == metric_72_2);
}

int fn_R001760_6013_3(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_82) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_57 = local_arr[aux % 3];
  acc = (acc + (phase_57 * 2)) & 127;
  int metric_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_72 > 33)
  {
    acc = ((acc + (metric_72 * 2)) + 5) & 127;
    aux ^= metric_72 & 15;
  }
  else
  {
    acc = ((acc - metric_72) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001760_6013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int vector_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_80_1)
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

  switch (vector_80_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_80_1 == vector_80_2);
}

int fn_R001760_6013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int vector_80 = (aux + st.buffer[1]) & 3;
  switch (vector_80)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int parity_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_44_1) & 63;
  aux_2 = (aux_2 + parity_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_50_1 = local_arr_1[aux_1 % 3];
  int coefficient_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_50_2 * 2)) & 127;
  int cursor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_33_1)
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

  switch (cursor_33_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_44_1 == parity_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_50_1 == coefficient_50_2);
  assert(cursor_33_1 == cursor_33_2);
}

int fn_R001760_6013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int parity_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int coefficient_50 = local_arr[aux % 3];
  acc = (acc + (coefficient_50 * 2)) & 127;
  int cursor_33 = (aux + st.buffer[1]) & 3;
  switch (cursor_33)
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

void fn_R001760_6013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_78_1 = 0;
  int margin_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_78_1 = ((margin_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_78_2 = ((margin_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_78_1) & 127;
    acc_2 = (acc_2 + margin_78_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_93_1) & 63;
  aux_2 = (aux_2 + tracker_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_63_1 > 11)
  {
    acc_1 = ((acc_1 + (tracker_63_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_63_2 > 11)
  {
    acc_2 = ((acc_2 + (tracker_63_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_78_1 == margin_78_2);
  assert(tracker_93_1 == tracker_93_2);
  assert(tracker_63_1 == tracker_63_2);
}

int fn_R001760_6013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_78 = ((margin_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_78) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_93) & 63;
  acc ^= aux;
  int tracker_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_63 > 11)
  {
    acc = ((acc + (tracker_63 * 2)) + 5) & 127;
    aux ^= tracker_63 & 15;
  }
  else
  {
    acc = ((acc - tracker_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001760_6013_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_89_1 = local_arr_1[aux_1 % 3];
  int weight_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_89_2 * 2)) & 127;
  int delta_93_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_93_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_93_1 > 36)
  {
    acc_1 = ((acc_1 + (delta_93_1 * 2)) + 5) & 127;
    aux_1 ^= delta_93_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_93_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_93_2 > 36)
  {
    acc_2 = ((acc_2 + (delta_93_2 * 2)) + 5) & 127;
    aux_2 ^= delta_93_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_93_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_65_1) & 63;
  aux_2 = (aux_2 + bound_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_89_1 == weight_89_2);
  assert(delta_93_1 == delta_93_2);
  assert(bound_65_1 == bound_65_2);
}

int fn_R001760_6013_7(int p0, int p1)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int weight_89 = local_arr[aux % 3];
  acc = (acc + (weight_89 * 2)) & 127;
  int delta_93 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_93 > 36)
  {
    acc = ((acc + (delta_93 * 2)) + 5) & 127;
    aux ^= delta_93 & 15;
  }
  else
  {
    acc = ((acc - delta_93) + 11) & 127;
    aux += 3;
  }
  int bound_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_65) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001760_6013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int damping_28_1 = 0;
  int damping_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_28_1 = ((damping_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_28_2 = ((damping_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_28_1) & 127;
    acc_2 = (acc_2 + damping_28_2) & 127;
  }

  int segment_45_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_45_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_45_1)
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

  switch (segment_45_2)
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

  int checksum_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_17_1 > 14)
  {
    acc_1 = ((acc_1 + (checksum_17_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_17_2 > 14)
  {
    acc_2 = ((acc_2 + (checksum_17_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_18_1) & 63;
  aux_2 = (aux_2 + index_reg_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_28_1 == damping_28_2);
  assert(segment_45_1 == segment_45_2);
  assert(checksum_17_1 == checksum_17_2);
  assert(index_reg_18_1 == index_reg_18_2);
}

int fn_R001760_6013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int damping_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_28 = ((damping_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_28) & 127;
  }

  int segment_45 = (aux + st.buffer[1]) & 3;
  switch (segment_45)
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

  int checksum_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_17 > 14)
  {
    acc = ((acc + (checksum_17 * 2)) + 5) & 127;
    aux ^= checksum_17 & 15;
  }
  else
  {
    acc = ((acc - checksum_17) + 11) & 127;
    aux += 3;
  }
  int index_reg_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001760_6013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_19_1) & 63;
  aux_2 = (aux_2 + scale_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_50_1 > 50)
  {
    acc_1 = ((acc_1 + (delta_50_1 * 2)) + 5) & 127;
    aux_1 ^= delta_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_50_2 > 50)
  {
    acc_2 = ((acc_2 + (delta_50_2 * 2)) + 5) & 127;
    aux_2 ^= delta_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_50_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_19_1 == scale_19_2);
  assert(delta_50_1 == delta_50_2);
}

int fn_R001760_6013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_19) & 63;
  acc ^= aux;
  int delta_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_50 > 50)
  {
    acc = ((acc + (delta_50 * 2)) + 5) & 127;
    aux ^= delta_50 & 15;
  }
  else
  {
    acc = ((acc - delta_50) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001760_6013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_94_1 = local_arr_1[aux_1 % 3];
  int damping_94_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_94_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_94_2 * 2)) & 127;
  int bound_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_64_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_64_1 * 2)) + 5) & 127;
    aux_1 ^= bound_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_64_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_64_2 * 2)) + 5) & 127;
    aux_2 ^= bound_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_94_1 == damping_94_2);
  assert(bound_64_1 == bound_64_2);
}

int fn_R001760_6013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int damping_94 = local_arr[aux % 3];
  acc = (acc + (damping_94 * 2)) & 127;
  int bound_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_64 > 10)
  {
    acc = ((acc + (bound_64 * 2)) + 5) & 127;
    aux ^= bound_64 & 15;
  }
  else
  {
    acc = ((acc - bound_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001760_6013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int index_reg_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_97_1)
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

  switch (index_reg_97_2)
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
  int residue_80_1 = 0;
  int residue_80_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_80_1 = ((residue_80_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_80_2 = ((residue_80_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_80_1) & 127;
    acc_2 = (acc_2 + residue_80_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_97_1 == index_reg_97_2);
  assert(residue_80_1 == residue_80_2);
}

int fn_R001760_6013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int index_reg_97 = (aux + st.buffer[1]) & 3;
  switch (index_reg_97)
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
  int residue_80 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_80 = ((residue_80 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_80) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001760_6013_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_96_1) & 63;
  aux_2 = (aux_2 + weight_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_18_1)
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

  switch (sample_18_2)
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

  int cursor_83_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_83_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_83_1 > 18)
  {
    acc_1 = ((acc_1 + (cursor_83_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_83_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_83_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_83_2 > 18)
  {
    acc_2 = ((acc_2 + (cursor_83_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_83_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_83_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_19_1 = local_arr_1[aux_1 % 3];
  int margin_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_96_1 == weight_96_2);
  assert(sample_18_1 == sample_18_2);
  assert(cursor_83_1 == cursor_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_19_1 == margin_19_2);
}

int fn_R001760_6013_12(int p0, int p1)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_96) & 63;
  acc ^= aux;
  int sample_18 = (aux + st.buffer[1]) & 3;
  switch (sample_18)
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

  int cursor_83 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_83 > 18)
  {
    acc = ((acc + (cursor_83 * 2)) + 5) & 127;
    aux ^= cursor_83 & 15;
  }
  else
  {
    acc = ((acc - cursor_83) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_19 = local_arr[aux % 3];
  acc = (acc + (margin_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_46_1) & 63;
  aux_2 = (aux_2 + index_reg_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_82_1 = local_arr_1[aux_1 % 3];
  int margin_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_46_1 == index_reg_46_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_82_1 == margin_82_2);
}

int fn_R001760_6013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_46) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_82 = local_arr[aux % 3];
  acc = (acc + (margin_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int margin_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_12_1)
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

  switch (margin_12_2)
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

  int segment_23_1 = 0;
  int segment_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_23_1 = ((segment_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_23_2 = ((segment_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_23_1) & 127;
    acc_2 = (acc_2 + segment_23_2) & 127;
  }

  int delta_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_80_1) & 63;
  aux_2 = (aux_2 + delta_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_12_1 == margin_12_2);
  assert(segment_23_1 == segment_23_2);
  assert(delta_80_1 == delta_80_2);
}

int fn_R001760_6013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int margin_12 = (aux + st.buffer[1]) & 3;
  switch (margin_12)
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

  int segment_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_23 = ((segment_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_23) & 127;
  }

  int delta_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001760_6013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st_1 = {0};
  struct EventLog_R001760_6013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int bound_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_45_1) & 63;
  aux_2 = (aux_2 + bound_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_45_1 == bound_45_2);
}

int fn_R001760_6013_15(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001760_6013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int bound_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_45) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001760_6013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st_1 = {0};
  struct Transaction_R001760_6013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int damping_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_49_1)
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

  switch (damping_49_2)
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
  int sample_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_49_1) & 63;
  aux_2 = (aux_2 + sample_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_34_1 = 0;
  int pivot_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_34_1 = ((pivot_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_34_2 = ((pivot_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_34_1) & 127;
    acc_2 = (acc_2 + pivot_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_49_1 == damping_49_2);
  assert(sample_49_1 == sample_49_2);
  assert(pivot_34_1 == pivot_34_2);
}

int fn_R001760_6013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001760_6013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int damping_49 = (aux + st.buffer[1]) & 3;
  switch (damping_49)
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
  int sample_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_49) & 63;
  acc ^= aux;
  int pivot_34 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_34 = ((pivot_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001760_6013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_26_1 = local_arr_1[aux_1 % 3];
  int quantum_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_26_2 * 2)) & 127;
  int vector_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_33_1 > 33)
  {
    acc_1 = ((acc_1 + (vector_33_1 * 2)) + 5) & 127;
    aux_1 ^= vector_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_33_2 > 33)
  {
    acc_2 = ((acc_2 + (vector_33_2 * 2)) + 5) & 127;
    aux_2 ^= vector_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_33_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_26_1 == quantum_26_2);
  assert(vector_33_1 == vector_33_2);
}

int fn_R001760_6013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001760_6013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int quantum_26 = local_arr[aux % 3];
  acc = (acc + (quantum_26 * 2)) & 127;
  int vector_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_33 > 33)
  {
    acc = ((acc + (vector_33 * 2)) + 5) & 127;
    aux ^= vector_33 & 15;
  }
  else
  {
    acc = ((acc - vector_33) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001760_0_1;
  int sec_r001760_0_2;
  int sec_r001760_1_1;
  int sec_r001760_1_2;
  int sec_r001760_2_1;
  int sec_r001760_2_2;
  int sec_r001760_3_1;
  int sec_r001760_3_2;
  int sec_r001760_4_1;
  int sec_r001760_4_2;
  int sec_r001760_5_1;
  int sec_r001760_5_2;
  int sec_r001760_6_1;
  int sec_r001760_6_2;
  int sec_r001760_7_1;
  int sec_r001760_7_2;
  int sec_r001760_8_1;
  int sec_r001760_8_2;
  int sec_r001760_9_1;
  int sec_r001760_9_2;
  int sec_r001760_10_1;
  int sec_r001760_10_2;
  int sec_r001760_11_1;
  int sec_r001760_11_2;
  int sec_r001760_12_1;
  int sec_r001760_12_2;
  int sec_r001760_13_1;
  int sec_r001760_13_2;
  int sec_r001760_14_1;
  int sec_r001760_14_2;
  int sec_r001760_15_1;
  int sec_r001760_15_2;
  int sec_r001760_16_1;
  int sec_r001760_16_2;
  int sec_r001760_17_1;
  int sec_r001760_17_2;
  int sec_r001760_18_1;
  int sec_r001760_18_2;
  int sec_r001760_19_1;
  int sec_r001760_19_2;
  int pub_r001760_0_1;
  int pub_r001760_0_2;
  int pub_r001760_1_1;
  int pub_r001760_1_2;
  int pub_r001760_2_1;
  int pub_r001760_2_2;
  int pub_r001760_3_1;
  int pub_r001760_3_2;
  int pub_r001760_4_1;
  int pub_r001760_4_2;
  int pub_r001760_5_1;
  int pub_r001760_5_2;
  int pub_r001760_6_1;
  int pub_r001760_6_2;
  int pub_r001760_7_1;
  int pub_r001760_7_2;
  int pub_r001760_8_1;
  int pub_r001760_8_2;
  int pub_r001760_9_1;
  int pub_r001760_9_2;
  int pub_r001760_10_1;
  int pub_r001760_10_2;
  int pub_r001760_11_1;
  int pub_r001760_11_2;
  int pub_r001760_12_1;
  int pub_r001760_12_2;
  int pub_r001760_13_1;
  int pub_r001760_13_2;
  int pub_r001760_14_1;
  int pub_r001760_14_2;
  int pub_r001760_15_1;
  int pub_r001760_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001760_0_1 >= (-100)) && (pub_r001760_0_1 <= 100));
  __CPROVER_assume((pub_r001760_0_2 >= (-100)) && (pub_r001760_0_2 <= 100));
  __CPROVER_assume((pub_r001760_1_1 >= (-100)) && (pub_r001760_1_1 <= 100));
  __CPROVER_assume((pub_r001760_1_2 >= (-100)) && (pub_r001760_1_2 <= 100));
  __CPROVER_assume((pub_r001760_2_1 >= (-100)) && (pub_r001760_2_1 <= 100));
  __CPROVER_assume((pub_r001760_2_2 >= (-100)) && (pub_r001760_2_2 <= 100));
  __CPROVER_assume((pub_r001760_3_1 >= (-100)) && (pub_r001760_3_1 <= 100));
  __CPROVER_assume((pub_r001760_3_2 >= (-100)) && (pub_r001760_3_2 <= 100));
  __CPROVER_assume((pub_r001760_4_1 >= (-100)) && (pub_r001760_4_1 <= 100));
  __CPROVER_assume((pub_r001760_4_2 >= (-100)) && (pub_r001760_4_2 <= 100));
  __CPROVER_assume((pub_r001760_5_1 >= (-100)) && (pub_r001760_5_1 <= 100));
  __CPROVER_assume((pub_r001760_5_2 >= (-100)) && (pub_r001760_5_2 <= 100));
  __CPROVER_assume((pub_r001760_6_1 >= (-100)) && (pub_r001760_6_1 <= 100));
  __CPROVER_assume((pub_r001760_6_2 >= (-100)) && (pub_r001760_6_2 <= 100));
  __CPROVER_assume((pub_r001760_7_1 >= (-100)) && (pub_r001760_7_1 <= 100));
  __CPROVER_assume((pub_r001760_7_2 >= (-100)) && (pub_r001760_7_2 <= 100));
  __CPROVER_assume((pub_r001760_8_1 >= (-100)) && (pub_r001760_8_1 <= 100));
  __CPROVER_assume((pub_r001760_8_2 >= (-100)) && (pub_r001760_8_2 <= 100));
  __CPROVER_assume((pub_r001760_9_1 >= (-100)) && (pub_r001760_9_1 <= 100));
  __CPROVER_assume((pub_r001760_9_2 >= (-100)) && (pub_r001760_9_2 <= 100));
  __CPROVER_assume((pub_r001760_10_1 >= (-100)) && (pub_r001760_10_1 <= 100));
  __CPROVER_assume((pub_r001760_10_2 >= (-100)) && (pub_r001760_10_2 <= 100));
  __CPROVER_assume((pub_r001760_11_1 >= (-100)) && (pub_r001760_11_1 <= 100));
  __CPROVER_assume((pub_r001760_11_2 >= (-100)) && (pub_r001760_11_2 <= 100));
  __CPROVER_assume((pub_r001760_12_1 >= (-100)) && (pub_r001760_12_1 <= 100));
  __CPROVER_assume((pub_r001760_12_2 >= (-100)) && (pub_r001760_12_2 <= 100));
  __CPROVER_assume((pub_r001760_13_1 >= (-100)) && (pub_r001760_13_1 <= 100));
  __CPROVER_assume((pub_r001760_13_2 >= (-100)) && (pub_r001760_13_2 <= 100));
  __CPROVER_assume((pub_r001760_14_1 >= (-100)) && (pub_r001760_14_1 <= 100));
  __CPROVER_assume((pub_r001760_14_2 >= (-100)) && (pub_r001760_14_2 <= 100));
  __CPROVER_assume((pub_r001760_15_1 >= (-100)) && (pub_r001760_15_1 <= 100));
  __CPROVER_assume((pub_r001760_15_2 >= (-100)) && (pub_r001760_15_2 <= 100));
  __CPROVER_assume((sec_r001760_0_1 >= 0) && (sec_r001760_0_1 <= 255));
  __CPROVER_assume((sec_r001760_0_2 >= 0) && (sec_r001760_0_2 <= 255));
  __CPROVER_assume((sec_r001760_1_1 >= 0) && (sec_r001760_1_1 <= 255));
  __CPROVER_assume((sec_r001760_1_2 >= 0) && (sec_r001760_1_2 <= 255));
  __CPROVER_assume((sec_r001760_2_1 >= 0) && (sec_r001760_2_1 <= 255));
  __CPROVER_assume((sec_r001760_2_2 >= 0) && (sec_r001760_2_2 <= 255));
  __CPROVER_assume((sec_r001760_3_1 >= 0) && (sec_r001760_3_1 <= 255));
  __CPROVER_assume((sec_r001760_3_2 >= 0) && (sec_r001760_3_2 <= 255));
  __CPROVER_assume((sec_r001760_4_1 >= 0) && (sec_r001760_4_1 <= 255));
  __CPROVER_assume((sec_r001760_4_2 >= 0) && (sec_r001760_4_2 <= 255));
  __CPROVER_assume((sec_r001760_5_1 >= 0) && (sec_r001760_5_1 <= 255));
  __CPROVER_assume((sec_r001760_5_2 >= 0) && (sec_r001760_5_2 <= 255));
  __CPROVER_assume((sec_r001760_6_1 >= 0) && (sec_r001760_6_1 <= 255));
  __CPROVER_assume((sec_r001760_6_2 >= 0) && (sec_r001760_6_2 <= 255));
  __CPROVER_assume((sec_r001760_7_1 >= 0) && (sec_r001760_7_1 <= 255));
  __CPROVER_assume((sec_r001760_7_2 >= 0) && (sec_r001760_7_2 <= 255));
  __CPROVER_assume((sec_r001760_8_1 >= 0) && (sec_r001760_8_1 <= 255));
  __CPROVER_assume((sec_r001760_8_2 >= 0) && (sec_r001760_8_2 <= 255));
  __CPROVER_assume((sec_r001760_9_1 >= 0) && (sec_r001760_9_1 <= 255));
  __CPROVER_assume((sec_r001760_9_2 >= 0) && (sec_r001760_9_2 <= 255));
  __CPROVER_assume((sec_r001760_10_1 >= 0) && (sec_r001760_10_1 <= 255));
  __CPROVER_assume((sec_r001760_10_2 >= 0) && (sec_r001760_10_2 <= 255));
  __CPROVER_assume((sec_r001760_11_1 >= 0) && (sec_r001760_11_1 <= 255));
  __CPROVER_assume((sec_r001760_11_2 >= 0) && (sec_r001760_11_2 <= 255));
  __CPROVER_assume((sec_r001760_12_1 >= 0) && (sec_r001760_12_1 <= 255));
  __CPROVER_assume((sec_r001760_12_2 >= 0) && (sec_r001760_12_2 <= 255));
  __CPROVER_assume((sec_r001760_13_1 >= 0) && (sec_r001760_13_1 <= 255));
  __CPROVER_assume((sec_r001760_13_2 >= 0) && (sec_r001760_13_2 <= 255));
  __CPROVER_assume((sec_r001760_14_1 >= 0) && (sec_r001760_14_1 <= 255));
  __CPROVER_assume((sec_r001760_14_2 >= 0) && (sec_r001760_14_2 <= 255));
  __CPROVER_assume((sec_r001760_15_1 >= 0) && (sec_r001760_15_1 <= 255));
  __CPROVER_assume((sec_r001760_15_2 >= 0) && (sec_r001760_15_2 <= 255));
  __CPROVER_assume((sec_r001760_16_1 >= 0) && (sec_r001760_16_1 <= 255));
  __CPROVER_assume((sec_r001760_16_2 >= 0) && (sec_r001760_16_2 <= 255));
  __CPROVER_assume((sec_r001760_17_1 >= 0) && (sec_r001760_17_1 <= 255));
  __CPROVER_assume((sec_r001760_17_2 >= 0) && (sec_r001760_17_2 <= 255));
  __CPROVER_assume((sec_r001760_18_1 >= 0) && (sec_r001760_18_1 <= 255));
  __CPROVER_assume((sec_r001760_18_2 >= 0) && (sec_r001760_18_2 <= 255));
  __CPROVER_assume((sec_r001760_19_1 >= 0) && (sec_r001760_19_1 <= 255));
  __CPROVER_assume((sec_r001760_19_2 >= 0) && (sec_r001760_19_2 <= 255));
  struct Transaction_R001760_6013_0 st_var_0_1 = {0};
  struct Transaction_R001760_6013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001760_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001760_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001760_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001760_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001760_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001760_0_2 + 7) & 15;
  struct StreamBuffer_R001760_6013_1 st_var_1_1 = {0};
  struct StreamBuffer_R001760_6013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001760_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001760_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001760_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001760_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001760_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001760_0_2 + 9) & 15;
  struct EventLog_R001760_6013_2 st_var_2_1 = {0};
  struct EventLog_R001760_6013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001760_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001760_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001760_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001760_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001760_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001760_0_2 + 11) & 15;
  union ColorPixel_R001760_6013_0 u_var_1;
  union ColorPixel_R001760_6013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001760_6013_0(sec_r001760_0_1, pub_r001760_1_1);
  int helper_flow_0_2 = fn_R001760_6013_0(sec_r001760_0_2, pub_r001760_1_2);
  fn_R001760_6013_0_2(sec_r001760_0_1, pub_r001760_1_1, sec_r001760_0_2, pub_r001760_1_2);
  int helper_flow_1_1 = fn_R001760_6013_1(sec_r001760_1_1, pub_r001760_2_1, pub_r001760_3_1);
  int helper_flow_1_2 = fn_R001760_6013_1(sec_r001760_1_2, pub_r001760_2_2, pub_r001760_3_2);
  fn_R001760_6013_1_2(sec_r001760_1_1, pub_r001760_2_1, pub_r001760_3_1, sec_r001760_1_2, pub_r001760_2_2, pub_r001760_3_2);
  int helper_flow_2_1 = fn_R001760_6013_2(sec_r001760_2_1, sec_r001760_3_1);
  int helper_flow_2_2 = fn_R001760_6013_2(sec_r001760_2_2, sec_r001760_3_2);
  fn_R001760_6013_2_2(sec_r001760_2_1, sec_r001760_3_1, sec_r001760_2_2, sec_r001760_3_2);
  int helper_flow_3_1 = fn_R001760_6013_3(sec_r001760_3_1, pub_r001760_4_1, pub_r001760_5_1);
  int helper_flow_3_2 = fn_R001760_6013_3(sec_r001760_3_2, pub_r001760_4_2, pub_r001760_5_2);
  fn_R001760_6013_3_2(sec_r001760_3_1, pub_r001760_4_1, pub_r001760_5_1, sec_r001760_3_2, pub_r001760_4_2, pub_r001760_5_2);
  int helper_flow_4_1 = fn_R001760_6013_4(sec_r001760_4_1, pub_r001760_5_1, pub_r001760_6_1, pub_r001760_7_1, pub_r001760_8_1);
  int helper_flow_4_2 = fn_R001760_6013_4(sec_r001760_4_2, pub_r001760_5_2, pub_r001760_6_2, pub_r001760_7_2, pub_r001760_8_2);
  fn_R001760_6013_4_2(sec_r001760_4_1, pub_r001760_5_1, pub_r001760_6_1, pub_r001760_7_1, pub_r001760_8_1, sec_r001760_4_2, pub_r001760_5_2, pub_r001760_6_2, pub_r001760_7_2, pub_r001760_8_2);
  int helper_flow_5_1 = fn_R001760_6013_5(sec_r001760_5_1, pub_r001760_6_1, pub_r001760_7_1, pub_r001760_8_1);
  int helper_flow_5_2 = fn_R001760_6013_5(sec_r001760_5_2, pub_r001760_6_2, pub_r001760_7_2, pub_r001760_8_2);
  fn_R001760_6013_5_2(sec_r001760_5_1, pub_r001760_6_1, pub_r001760_7_1, pub_r001760_8_1, sec_r001760_5_2, pub_r001760_6_2, pub_r001760_7_2, pub_r001760_8_2);
  int helper_flow_6_1 = fn_R001760_6013_6(sec_r001760_6_1, sec_r001760_7_1, pub_r001760_8_1, pub_r001760_9_1);
  int helper_flow_6_2 = fn_R001760_6013_6(sec_r001760_6_2, sec_r001760_7_2, pub_r001760_8_2, pub_r001760_9_2);
  fn_R001760_6013_6_2(sec_r001760_6_1, sec_r001760_7_1, pub_r001760_8_1, pub_r001760_9_1, sec_r001760_6_2, sec_r001760_7_2, pub_r001760_8_2, pub_r001760_9_2);
  int helper_flow_7_1 = fn_R001760_6013_7(sec_r001760_7_1, pub_r001760_8_1);
  int helper_flow_7_2 = fn_R001760_6013_7(sec_r001760_7_2, pub_r001760_8_2);
  fn_R001760_6013_7_2(sec_r001760_7_1, pub_r001760_8_1, sec_r001760_7_2, pub_r001760_8_2);
  int helper_flow_8_1 = fn_R001760_6013_8(sec_r001760_8_1, sec_r001760_9_1, pub_r001760_10_1, pub_r001760_11_1);
  int helper_flow_8_2 = fn_R001760_6013_8(sec_r001760_8_2, sec_r001760_9_2, pub_r001760_10_2, pub_r001760_11_2);
  fn_R001760_6013_8_2(sec_r001760_8_1, sec_r001760_9_1, pub_r001760_10_1, pub_r001760_11_1, sec_r001760_8_2, sec_r001760_9_2, pub_r001760_10_2, pub_r001760_11_2);
  int helper_flow_9_1 = fn_R001760_6013_9(sec_r001760_9_1, pub_r001760_10_1, pub_r001760_11_1);
  int helper_flow_9_2 = fn_R001760_6013_9(sec_r001760_9_2, pub_r001760_10_2, pub_r001760_11_2);
  fn_R001760_6013_9_2(sec_r001760_9_1, pub_r001760_10_1, pub_r001760_11_1, sec_r001760_9_2, pub_r001760_10_2, pub_r001760_11_2);
  int helper_flow_10_1 = fn_R001760_6013_10(sec_r001760_10_1, sec_r001760_11_1, pub_r001760_12_1, pub_r001760_13_1, pub_r001760_14_1);
  int helper_flow_10_2 = fn_R001760_6013_10(sec_r001760_10_2, sec_r001760_11_2, pub_r001760_12_2, pub_r001760_13_2, pub_r001760_14_2);
  fn_R001760_6013_10_2(sec_r001760_10_1, sec_r001760_11_1, pub_r001760_12_1, pub_r001760_13_1, pub_r001760_14_1, sec_r001760_10_2, sec_r001760_11_2, pub_r001760_12_2, pub_r001760_13_2, pub_r001760_14_2);
  int helper_flow_11_1 = fn_R001760_6013_11(sec_r001760_11_1, pub_r001760_12_1, pub_r001760_13_1, pub_r001760_14_1);
  int helper_flow_11_2 = fn_R001760_6013_11(sec_r001760_11_2, pub_r001760_12_2, pub_r001760_13_2, pub_r001760_14_2);
  fn_R001760_6013_11_2(sec_r001760_11_1, pub_r001760_12_1, pub_r001760_13_1, pub_r001760_14_1, sec_r001760_11_2, pub_r001760_12_2, pub_r001760_13_2, pub_r001760_14_2);
  int helper_flow_12_1 = fn_R001760_6013_12(sec_r001760_12_1, sec_r001760_13_1);
  int helper_flow_12_2 = fn_R001760_6013_12(sec_r001760_12_2, sec_r001760_13_2);
  fn_R001760_6013_12_2(sec_r001760_12_1, sec_r001760_13_1, sec_r001760_12_2, sec_r001760_13_2);
  int helper_flow_13_1 = fn_R001760_6013_13(sec_r001760_13_1, sec_r001760_14_1, pub_r001760_15_1, pub_r001760_0_1, pub_r001760_1_1);
  int helper_flow_13_2 = fn_R001760_6013_13(sec_r001760_13_2, sec_r001760_14_2, pub_r001760_15_2, pub_r001760_0_2, pub_r001760_1_2);
  fn_R001760_6013_13_2(sec_r001760_13_1, sec_r001760_14_1, pub_r001760_15_1, pub_r001760_0_1, pub_r001760_1_1, sec_r001760_13_2, sec_r001760_14_2, pub_r001760_15_2, pub_r001760_0_2, pub_r001760_1_2);
  int stage_v_0_1 = (((sec_r001760_18_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_0_2 = (((sec_r001760_18_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_0_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_1_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_1_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((pub_r001760_4_1 * 2) + 28) & 63;
  int stage_v_2_2 = ((pub_r001760_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001760_11_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_3_2 = (((sec_r001760_11_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_3_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_4_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_4_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = ((pub_r001760_1_1 * 2) + 28) & 63;
  int stage_v_5_2 = ((pub_r001760_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001760_12_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_6_2 = (((sec_r001760_12_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_6_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((pub_r001760_8_1 * 2) + 5) & 63;
  int stage_v_7_2 = ((pub_r001760_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001760_1_1 * 2) + 15) & 63;
  int stage_v_8_2 = ((pub_r001760_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_9_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_9_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((pub_r001760_14_1 * 2) + 30) & 63;
  int stage_v_10_2 = ((pub_r001760_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001760_0_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_11_2 = (((sec_r001760_0_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_11_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
  }
  if (stage_v_11_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_12_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_12_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_13_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_13_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_14_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_14_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001760_6_1 * 2) + 5) & 63;
  int stage_v_15_2 = ((pub_r001760_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_16_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_16_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_17_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_17_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_18_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_18_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
  }
  if (stage_v_18_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  int stage_v_19_1 = ((pub_r001760_12_1 * 2) + 7) & 63;
  int stage_v_19_2 = ((pub_r001760_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001760_18_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_20_2 = (((sec_r001760_18_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_20_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_21_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_21_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_22_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_22_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_23_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_23_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = ((pub_r001760_6_1 * 2) + 33) & 63;
  int stage_v_24_2 = ((pub_r001760_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001760_13_1 * 2) + 26) & 63;
  int stage_v_25_2 = ((pub_r001760_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001760_1_1 * 2) + 6) & 63;
  int stage_v_26_2 = ((pub_r001760_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001760_7_1 * 2) + 7) & 63;
  int stage_v_27_2 = ((pub_r001760_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_23_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_28_2 = (((stage_v_23_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_28_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((sec_r001760_17_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_29_2 = (((sec_r001760_17_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_29_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((pub_r001760_7_1 * 2) + 13) & 63;
  int stage_v_30_2 = ((pub_r001760_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001760_14_1 * 2) + 50) & 63;
  int stage_v_31_2 = ((pub_r001760_14_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001760_13_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_32_2 = (((sec_r001760_13_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_32_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((sec_r001760_13_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_33_2 = (((sec_r001760_13_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_33_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = ((pub_r001760_1_1 * 2) + 41) & 63;
  int stage_v_34_2 = ((pub_r001760_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_35_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_35_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_36_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_36_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((pub_r001760_13_1 * 2) + 29) & 63;
  int stage_v_37_2 = ((pub_r001760_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_38_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_38_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = ((pub_r001760_15_1 * 2) + 30) & 63;
  int stage_v_39_2 = ((pub_r001760_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001760_10_1 * 2) + 48) & 63;
  int stage_v_40_2 = ((pub_r001760_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_41_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_41_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_42_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_42_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001760_14_1 * 2) + 22) & 63;
  int stage_v_43_2 = ((pub_r001760_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_44_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_44_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((pub_r001760_2_1 * 2) + 36) & 63;
  int stage_v_45_2 = ((pub_r001760_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_46_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_46_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_47_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_47_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_48_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_48_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = ((pub_r001760_3_1 * 2) + 9) & 63;
  int stage_v_49_2 = ((pub_r001760_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001760_18_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_50_2 = (((sec_r001760_18_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_50_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_51_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_51_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((sec_r001760_5_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_52_2 = (((sec_r001760_5_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_52_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_53_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_53_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = ((pub_r001760_5_1 * 2) + 42) & 63;
  int stage_v_54_2 = ((pub_r001760_5_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_55_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_55_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_56_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_56_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_57_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_57_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_51_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_58_2 = (((stage_v_51_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_58_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_59_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_59_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
  }
  if (stage_v_59_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = (((sec_r001760_17_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_60_2 = (((sec_r001760_17_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_60_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((sec_r001760_10_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_61_2 = (((sec_r001760_10_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_61_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((sec_r001760_2_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_62_2 = (((sec_r001760_2_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_62_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((pub_r001760_3_1 * 2) + 38) & 63;
  int stage_v_63_2 = ((pub_r001760_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((sec_r001760_7_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_64_2 = (((sec_r001760_7_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_64_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_46_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_65_2 = (((stage_v_46_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_65_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (((sec_r001760_15_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_66_2 = (((sec_r001760_15_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_66_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = ((pub_r001760_12_1 * 2) + 21) & 63;
  int stage_v_67_2 = ((pub_r001760_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((sec_r001760_9_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_68_2 = (((sec_r001760_9_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_68_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_69_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_69_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_70_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_70_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_71_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_71_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = ((pub_r001760_2_1 * 2) + 19) & 63;
  int stage_v_72_2 = ((pub_r001760_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_73_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_73_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_74_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_74_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((sec_r001760_5_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_75_2 = (((sec_r001760_5_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_75_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_76_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_76_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_77_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_77_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_78_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_78_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (((sec_r001760_15_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_79_2 = (((sec_r001760_15_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_79_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((pub_r001760_1_1 * 2) + 15) & 63;
  int stage_v_80_2 = ((pub_r001760_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_81_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_81_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_82_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_82_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((pub_r001760_8_1 * 2) + 6) & 63;
  int stage_v_83_2 = ((pub_r001760_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_84_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_84_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((stage_v_41_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_85_2 = (((stage_v_41_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_85_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001760_14_1) & 127;
  int stage_v_86_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001760_14_2) & 127;
  if (stage_v_86_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_87_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_87_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_88_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_88_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((sec_r001760_16_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_89_2 = (((sec_r001760_16_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_89_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (((sec_r001760_6_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_90_2 = (((sec_r001760_6_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_90_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_91_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_91_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_92_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_92_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((pub_r001760_6_1 * 2) + 32) & 63;
  int stage_v_93_2 = ((pub_r001760_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001760_6_1 * 2) + 39) & 63;
  int stage_v_94_2 = ((pub_r001760_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_95_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_95_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_96_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_96_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001760_14_1 * 2) + 7) & 63;
  int stage_v_97_2 = ((pub_r001760_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_98_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_98_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_99_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_99_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((pub_r001760_11_1 * 2) + 33) & 63;
  int stage_v_100_2 = ((pub_r001760_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_101_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_101_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001760_14_1) & 127;
  int stage_v_102_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001760_14_2) & 127;
  if (stage_v_102_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_103_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_103_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((pub_r001760_7_1 * 2) + 12) & 63;
  int stage_v_104_2 = ((pub_r001760_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_105_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_105_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_106_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_106_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((pub_r001760_5_1 * 2) + 34) & 63;
  int stage_v_107_2 = ((pub_r001760_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_108_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_108_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_86_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_109_2 = (((stage_v_86_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_109_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_110_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_110_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_111_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_111_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001760_9_1 * 2) + 38) & 63;
  int stage_v_112_2 = ((pub_r001760_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_113_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_113_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_114_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_114_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((pub_r001760_1_1 * 2) + 34) & 63;
  int stage_v_115_2 = ((pub_r001760_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((sec_r001760_0_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_116_2 = (((sec_r001760_0_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_116_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((pub_r001760_15_1 * 2) + 44) & 63;
  int stage_v_117_2 = ((pub_r001760_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((stage_v_62_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_118_2 = (((stage_v_62_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_118_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_119_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_119_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_120_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_120_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_121_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_121_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_122_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_122_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_123_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_123_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_124_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_124_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((pub_r001760_2_1 * 2) + 50) & 63;
  int stage_v_125_2 = ((pub_r001760_2_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_126_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_126_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((sec_r001760_13_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_127_2 = (((sec_r001760_13_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_127_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_128_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_128_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001760_1_1 * 2) + 18) & 63;
  int stage_v_129_2 = ((pub_r001760_1_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_130_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_130_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_59_1 ^ 0x2A) * 2) + pub_r001760_14_1) & 127;
  int stage_v_131_2 = (((stage_v_59_2 ^ 0x2A) * 2) + pub_r001760_14_2) & 127;
  if (stage_v_131_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_81_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_132_2 = (((stage_v_81_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_132_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_133_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_133_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_126_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_134_2 = (((stage_v_126_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_134_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001760_9_1 * 2) + 50) & 63;
  int stage_v_135_2 = ((pub_r001760_9_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_136_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_136_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_137_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_137_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_138_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_138_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_139_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_139_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_140_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_140_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001760_9_1 * 2) + 26) & 63;
  int stage_v_141_2 = ((pub_r001760_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_142_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_142_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_143_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_143_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((pub_r001760_3_1 * 2) + 19) & 63;
  int stage_v_144_2 = ((pub_r001760_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001760_7_1 * 2) + 36) & 63;
  int stage_v_145_2 = ((pub_r001760_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = (((sec_r001760_14_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_146_2 = (((sec_r001760_14_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_146_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001760_8_1 * 2) + 42) & 63;
  int stage_v_147_2 = ((pub_r001760_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_148_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_148_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_149_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_149_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((pub_r001760_13_1 * 2) + 29) & 63;
  int stage_v_150_2 = ((pub_r001760_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001760_13_1 * 2) + 41) & 63;
  int stage_v_151_2 = ((pub_r001760_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_152_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_152_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((sec_r001760_9_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_153_2 = (((sec_r001760_9_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_153_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((pub_r001760_7_1 * 2) + 29) & 63;
  int stage_v_154_2 = ((pub_r001760_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_155_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_155_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((stage_v_109_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_156_2 = (((stage_v_109_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_156_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_157_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_157_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((pub_r001760_2_1 * 2) + 48) & 63;
  int stage_v_158_2 = ((pub_r001760_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_159_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_159_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_160_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_160_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_161_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_161_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((helper_flow_12_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_162_2 = (((helper_flow_12_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_162_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001760_8_1 * 2) + 40) & 63;
  int stage_v_163_2 = ((pub_r001760_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001760_6_1 * 2) + 8) & 63;
  int stage_v_164_2 = ((pub_r001760_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001760_12_1 * 2) + 17) & 63;
  int stage_v_165_2 = ((pub_r001760_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((helper_flow_13_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_166_2 = (((helper_flow_13_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_166_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_161_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_167_2 = (((stage_v_161_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_167_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((sec_r001760_10_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_168_2 = (((sec_r001760_10_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_168_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_169_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_169_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_170_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_170_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_171_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_171_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001760_0_1 * 2) + 27) & 63;
  int stage_v_172_2 = ((pub_r001760_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((sec_r001760_11_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_173_2 = (((sec_r001760_11_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_173_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_174_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_174_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_175_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_175_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((pub_r001760_3_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001760_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_177_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_177_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_178_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_178_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_179_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_179_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_180_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_180_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_146_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_181_2 = (((stage_v_146_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_181_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((pub_r001760_5_1 * 2) + 16) & 63;
  int stage_v_182_2 = ((pub_r001760_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001760_14_1) & 127;
  int stage_v_183_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001760_14_2) & 127;
  if (stage_v_183_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((pub_r001760_5_1 * 2) + 44) & 63;
  int stage_v_184_2 = ((pub_r001760_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001760_5_1) & 127;
  int stage_v_185_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001760_5_2) & 127;
  if (stage_v_185_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_186_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_186_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((pub_r001760_3_1 * 2) + 29) & 63;
  int stage_v_187_2 = ((pub_r001760_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_188_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_188_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_189_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_189_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_79_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_190_2 = (((stage_v_79_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_190_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_191_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_191_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_167_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_192_2 = (((stage_v_167_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_192_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_193_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_193_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((sec_r001760_4_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_194_2 = (((sec_r001760_4_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_194_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((pub_r001760_4_1 * 2) + 6) & 63;
  int stage_v_195_2 = ((pub_r001760_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001760_3_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_196_2 = (((sec_r001760_3_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_196_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((pub_r001760_13_1 * 2) + 38) & 63;
  int stage_v_197_2 = ((pub_r001760_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_198_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_198_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((pub_r001760_0_1 * 2) + 6) & 63;
  int stage_v_199_2 = ((pub_r001760_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001760_9_1) & 127;
  int stage_v_200_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001760_9_2) & 127;
  if (stage_v_200_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001760_6_1 * 2) + 30) & 63;
  int stage_v_201_2 = ((pub_r001760_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001760_9_1 * 2) + 22) & 63;
  int stage_v_202_2 = ((pub_r001760_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001760_3_1 * 2) + 34) & 63;
  int stage_v_203_2 = ((pub_r001760_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((sec_r001760_17_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_204_2 = (((sec_r001760_17_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_204_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_205_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_205_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((pub_r001760_9_1 * 2) + 19) & 63;
  int stage_v_206_2 = ((pub_r001760_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_207_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_207_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((pub_r001760_10_1 * 2) + 34) & 63;
  int stage_v_208_2 = ((pub_r001760_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_209_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_209_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001760_7_1) & 127;
  int stage_v_210_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001760_7_2) & 127;
  if (stage_v_210_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_138_1 ^ 0x2A) * 2) + pub_r001760_0_1) & 127;
  int stage_v_211_2 = (((stage_v_138_2 ^ 0x2A) * 2) + pub_r001760_0_2) & 127;
  if (stage_v_211_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_212_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_212_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_213_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_213_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_193_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_214_2 = (((stage_v_193_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_214_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((pub_r001760_2_1 * 2) + 46) & 63;
  int stage_v_215_2 = ((pub_r001760_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = (((stage_v_92_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_216_2 = (((stage_v_92_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_216_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001760_2_1) & 127;
  int stage_v_217_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001760_2_2) & 127;
  if (stage_v_217_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001760_3_1) & 127;
  int stage_v_218_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001760_3_2) & 127;
  if (stage_v_218_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((pub_r001760_14_1 * 2) + 14) & 63;
  int stage_v_219_2 = ((pub_r001760_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_11_1 ^ 0x2A) * 2) + pub_r001760_15_1) & 127;
  int stage_v_220_2 = (((stage_v_11_2 ^ 0x2A) * 2) + pub_r001760_15_2) & 127;
  if (stage_v_220_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001760_14_1) & 127;
  int stage_v_221_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001760_14_2) & 127;
  if (stage_v_221_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001760_10_1) & 127;
  int stage_v_222_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001760_10_2) & 127;
  if (stage_v_222_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = (((helper_flow_11_1 ^ 0x2A) * 2) + pub_r001760_1_1) & 127;
  int stage_v_223_2 = (((helper_flow_11_2 ^ 0x2A) * 2) + pub_r001760_1_2) & 127;
  if (stage_v_223_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001760_6_1) & 127;
  int stage_v_224_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001760_6_2) & 127;
  if (stage_v_224_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_225_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_225_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = (((stage_v_84_1 ^ 0x2A) * 2) + pub_r001760_12_1) & 127;
  int stage_v_226_2 = (((stage_v_84_2 ^ 0x2A) * 2) + pub_r001760_12_2) & 127;
  if (stage_v_226_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((pub_r001760_3_1 * 2) + 38) & 63;
  int stage_v_227_2 = ((pub_r001760_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001760_4_1) & 127;
  int stage_v_228_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001760_4_2) & 127;
  if (stage_v_228_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = (((stage_v_168_1 ^ 0x2A) * 2) + pub_r001760_11_1) & 127;
  int stage_v_229_2 = (((stage_v_168_2 ^ 0x2A) * 2) + pub_r001760_11_2) & 127;
  if (stage_v_229_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = (((stage_v_66_1 ^ 0x2A) * 2) + pub_r001760_13_1) & 127;
  int stage_v_230_2 = (((stage_v_66_2 ^ 0x2A) * 2) + pub_r001760_13_2) & 127;
  if (stage_v_230_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = (((stage_v_119_1 ^ 0x2A) * 2) + pub_r001760_8_1) & 127;
  int stage_v_231_2 = (((stage_v_119_2 ^ 0x2A) * 2) + pub_r001760_8_2) & 127;
  if (stage_v_231_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
  }
  if (stage_v_231_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001760_13_1 != sec_r001760_13_2);
  __CPROVER_assume(sec_r001760_17_1 != sec_r001760_17_2);
  __CPROVER_assume(sec_r001760_18_1 != sec_r001760_18_2);
  __CPROVER_assume(pub_r001760_3_1 == pub_r001760_3_2);
  __CPROVER_assume(sec_r001760_11_1 != sec_r001760_11_2);
  __CPROVER_assume(sec_r001760_8_1 != sec_r001760_8_2);
  __CPROVER_assume(sec_r001760_12_1 != sec_r001760_12_2);
  __CPROVER_assume(sec_r001760_2_1 != sec_r001760_2_2);
  __CPROVER_assume(sec_r001760_16_1 != sec_r001760_16_2);
  __CPROVER_assume(pub_r001760_1_1 == pub_r001760_1_2);
  __CPROVER_assume(sec_r001760_7_1 != sec_r001760_7_2);
  __CPROVER_assume(sec_r001760_3_1 != sec_r001760_3_2);
  __CPROVER_assume(sec_r001760_10_1 != sec_r001760_10_2);
  __CPROVER_assume(pub_r001760_4_1 == pub_r001760_4_2);
  __CPROVER_assume(pub_r001760_9_1 == pub_r001760_9_2);
  __CPROVER_assume(sec_r001760_6_1 != sec_r001760_6_2);
  __CPROVER_assume(pub_r001760_15_1 == pub_r001760_15_2);
  __CPROVER_assume(sec_r001760_14_1 != sec_r001760_14_2);
  __CPROVER_assume(pub_r001760_10_1 == pub_r001760_10_2);
  __CPROVER_assume(pub_r001760_11_1 == pub_r001760_11_2);
  __CPROVER_assume(sec_r001760_19_1 != sec_r001760_19_2);
  __CPROVER_assume(sec_r001760_4_1 != sec_r001760_4_2);
  __CPROVER_assume(sec_r001760_9_1 != sec_r001760_9_2);
  __CPROVER_assume(pub_r001760_5_1 == pub_r001760_5_2);
  __CPROVER_assume(pub_r001760_6_1 == pub_r001760_6_2);
  __CPROVER_assume(pub_r001760_13_1 == pub_r001760_13_2);
  __CPROVER_assume(sec_r001760_0_1 != sec_r001760_0_2);
  __CPROVER_assume(sec_r001760_1_1 != sec_r001760_1_2);
  __CPROVER_assume(pub_r001760_14_1 == pub_r001760_14_2);
  __CPROVER_assume(sec_r001760_15_1 != sec_r001760_15_2);
  __CPROVER_assume(pub_r001760_7_1 == pub_r001760_7_2);
  __CPROVER_assume(sec_r001760_5_1 != sec_r001760_5_2);
  __CPROVER_assume(pub_r001760_8_1 == pub_r001760_8_2);
  __CPROVER_assume(pub_r001760_2_1 == pub_r001760_2_2);
  __CPROVER_assume(pub_r001760_12_1 == pub_r001760_12_2);
  __CPROVER_assume(pub_r001760_0_1 == pub_r001760_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.seq == st_var_2_2.seq);
  assert(st_var_2_1.severity == st_var_2_2.severity);
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
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
  assert(helper_flow_8_1 == helper_flow_8_2);
  assert(helper_flow_9_1 == helper_flow_9_2);
  assert(helper_flow_10_1 == helper_flow_10_2);
  assert(helper_flow_11_1 == helper_flow_11_2);
  assert(helper_flow_12_1 == helper_flow_12_2);
  assert(helper_flow_13_1 == helper_flow_13_2);
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
}


