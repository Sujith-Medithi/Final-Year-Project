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
struct EventLog_R001536_3613_0
{
  int signature;
  int code;
  int timestamp;
  short facility;
  int severity;
  unsigned char seq;
  int buffer[3];
};
struct Transaction_R001536_3613_1
{
  short status;
  int auth_code;
  int rate;
  short fee;
  int account_id;
  int buffer[3];
};
struct AudioFrame_R001536_3613_2
{
  short envelope;
  int gain;
  unsigned char peak;
  int buffer[3];
};
union RegisterBank_R001536_3613_0
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
void fn_R001536_3613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_42_1 > 21)
  {
    acc_1 = ((acc_1 + (quotient_42_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_42_2 > 21)
  {
    acc_2 = ((acc_2 + (quotient_42_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_39_1 = 0;
  int vector_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_39_1 = ((vector_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_39_2 = ((vector_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_39_1) & 127;
    acc_2 = (acc_2 + vector_39_2) & 127;
  }

  int stride_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_96_1) & 63;
  aux_2 = (aux_2 + stride_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_42_1 == quotient_42_2);
  assert(vector_39_1 == vector_39_2);
  assert(stride_96_1 == stride_96_2);
}

int fn_R001536_3613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_42 > 21)
  {
    acc = ((acc + (quotient_42 * 2)) + 5) & 127;
    aux ^= quotient_42 & 15;
  }
  else
  {
    acc = ((acc - quotient_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_39 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_39 = ((vector_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_39) & 127;
  }

  int stride_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001536_3613_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_50_1 = local_arr_1[aux_1 % 3];
  int stride_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_50_2 * 2)) & 127;
  int parity_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_69_1)
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

  switch (parity_69_2)
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

  int stride_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_26_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_26_1 * 2)) + 5) & 127;
    aux_1 ^= stride_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_26_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_26_2 * 2)) + 5) & 127;
    aux_2 ^= stride_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_26_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_50_1 == stride_50_2);
  assert(parity_69_1 == parity_69_2);
  assert(stride_26_1 == stride_26_2);
}

int fn_R001536_3613_1(int p0, int p1, int p2)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int stride_50 = local_arr[aux % 3];
  acc = (acc + (stride_50 * 2)) & 127;
  int parity_69 = (aux + st.buffer[1]) & 3;
  switch (parity_69)
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

  int stride_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_26 > 45)
  {
    acc = ((acc + (stride_26 * 2)) + 5) & 127;
    aux ^= stride_26 & 15;
  }
  else
  {
    acc = ((acc - stride_26) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int damping_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_11_1)
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

  switch (damping_11_2)
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

  int offset_27_1 = 0;
  int offset_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_27_1 = ((offset_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_27_2 = ((offset_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_27_1) & 127;
    acc_2 = (acc_2 + offset_27_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_55_1 = local_arr_1[aux_1 % 3];
  int bound_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_11_1 == damping_11_2);
  assert(offset_27_1 == offset_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_55_1 == bound_55_2);
}

int fn_R001536_3613_2(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int damping_11 = (aux + st.buffer[1]) & 3;
  switch (damping_11)
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

  int offset_27 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_27 = ((offset_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_27) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int bound_55 = local_arr[aux % 3];
  acc = (acc + (bound_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_51_1 > 11)
  {
    acc_1 = ((acc_1 + (offset_51_1 * 2)) + 5) & 127;
    aux_1 ^= offset_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_51_2 > 11)
  {
    acc_2 = ((acc_2 + (offset_51_2 * 2)) + 5) & 127;
    aux_2 ^= offset_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_51_1 == offset_51_2);
}

int fn_R001536_3613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_51 > 11)
  {
    acc = ((acc + (offset_51 * 2)) + 5) & 127;
    aux ^= offset_51 & 15;
  }
  else
  {
    acc = ((acc - offset_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001536_3613_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int phase_33_1 = 0;
  int phase_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_33_1 = ((phase_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_33_2 = ((phase_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_33_1) & 127;
    acc_2 = (acc_2 + phase_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_69_1)
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

  switch (segment_69_2)
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

  int anchor_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_26_1) & 63;
  aux_2 = (aux_2 + anchor_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_33_1 == phase_33_2);
  assert(segment_69_1 == segment_69_2);
  assert(anchor_26_1 == anchor_26_2);
}

int fn_R001536_3613_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int phase_33 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_33 = ((phase_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_69 = (aux + st.buffer[1]) & 3;
  switch (segment_69)
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

  int anchor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_26) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001536_3613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int sample_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_10_1) & 63;
  aux_2 = (aux_2 + sample_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_66_1 > 38)
  {
    acc_1 = ((acc_1 + (factor_66_1 * 2)) + 5) & 127;
    aux_1 ^= factor_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_66_2 > 38)
  {
    acc_2 = ((acc_2 + (factor_66_2 * 2)) + 5) & 127;
    aux_2 ^= factor_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_10_1 == sample_10_2);
  assert(factor_66_1 == factor_66_2);
}

int fn_R001536_3613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int sample_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_10) & 63;
  acc ^= aux;
  int factor_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_66 > 38)
  {
    acc = ((acc + (factor_66 * 2)) + 5) & 127;
    aux ^= factor_66 & 15;
  }
  else
  {
    acc = ((acc - factor_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001536_3613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st_1 = {0};
  struct AudioFrame_R001536_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int accumulator_54_1 = 0;
  int accumulator_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_54_1 = ((accumulator_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_54_2 = ((accumulator_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_54_1) & 127;
    acc_2 = (acc_2 + accumulator_54_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_64_1 = local_arr_1[aux_1 % 3];
  int anchor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_54_1 == accumulator_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_64_1 == anchor_64_2);
}

int fn_R001536_3613_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int accumulator_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_54 = ((accumulator_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_54) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_64 = local_arr[aux % 3];
  acc = (acc + (anchor_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st_1 = {0};
  struct EventLog_R001536_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int weight_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_70_1 > 38)
  {
    acc_1 = ((acc_1 + (weight_70_1 * 2)) + 5) & 127;
    aux_1 ^= weight_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_70_2 > 38)
  {
    acc_2 = ((acc_2 + (weight_70_2 * 2)) + 5) & 127;
    aux_2 ^= weight_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_51_1) & 63;
  aux_2 = (aux_2 + quotient_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_79_1 = 0;
  int segment_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_79_1 = ((segment_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_79_2 = ((segment_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_79_1) & 127;
    acc_2 = (acc_2 + segment_79_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_70_1 == weight_70_2);
  assert(quotient_51_1 == quotient_51_2);
  assert(segment_79_1 == segment_79_2);
}

int fn_R001536_3613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int weight_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_70 > 38)
  {
    acc = ((acc + (weight_70 * 2)) + 5) & 127;
    aux ^= weight_70 & 15;
  }
  else
  {
    acc = ((acc - weight_70) + 11) & 127;
    aux += 3;
  }
  int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_51) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_79 = ((segment_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_79) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001536_3613_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_39_1 = local_arr_1[aux_1 % 3];
  int metric_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_39_2 * 2)) & 127;
  int bound_36_1 = 0;
  int bound_36_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_36_1 = ((bound_36_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_36_2 = ((bound_36_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_36_1) & 127;
    acc_2 = (acc_2 + bound_36_2) & 127;
  }

  int phase_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_63_1)
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

  switch (phase_63_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_39_1 == metric_39_2);
  assert(bound_36_1 == bound_36_2);
  assert(phase_63_1 == phase_63_2);
}

int fn_R001536_3613_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int metric_39 = local_arr[aux % 3];
  acc = (acc + (metric_39 * 2)) & 127;
  int bound_36 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_36 = ((bound_36 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_36) & 127;
  }

  int phase_63 = (aux + st.buffer[1]) & 3;
  switch (phase_63)
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

void fn_R001536_3613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_75_1 = local_arr_1[aux_1 % 3];
  int tracker_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_75_2 * 2)) & 127;
  int offset_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_23_1) & 63;
  aux_2 = (aux_2 + offset_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_25_1)
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

  switch (segment_25_2)
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

  int accumulator_10_1 = 0;
  int accumulator_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_10_1 = ((accumulator_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_10_2 = ((accumulator_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_10_1) & 127;
    acc_2 = (acc_2 + accumulator_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_75_1 == tracker_75_2);
  assert(offset_23_1 == offset_23_2);
  assert(segment_25_1 == segment_25_2);
  assert(accumulator_10_1 == accumulator_10_2);
}

int fn_R001536_3613_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int tracker_75 = local_arr[aux % 3];
  acc = (acc + (tracker_75 * 2)) & 127;
  int offset_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_23) & 63;
  acc ^= aux;
  int segment_25 = (aux + st.buffer[1]) & 3;
  switch (segment_25)
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

  int accumulator_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_10 = ((accumulator_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001536_3613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st_1 = {0};
  struct EventLog_R001536_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_10_1 = local_arr_1[aux_1 % 3];
  int damping_10_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_10_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_10_2 * 2)) & 127;
  int checksum_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_46_1 > 20)
  {
    acc_1 = ((acc_1 + (checksum_46_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_46_2 > 20)
  {
    acc_2 = ((acc_2 + (checksum_46_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_10_1 == damping_10_2);
  assert(checksum_46_1 == checksum_46_2);
}

int fn_R001536_3613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int damping_10 = local_arr[aux % 3];
  acc = (acc + (damping_10 * 2)) & 127;
  int checksum_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_46 > 20)
  {
    acc = ((acc + (checksum_46 * 2)) + 5) & 127;
    aux ^= checksum_46 & 15;
  }
  else
  {
    acc = ((acc - checksum_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st_1 = {0};
  struct AudioFrame_R001536_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int index_reg_26_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_26_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_26_1)
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

  switch (index_reg_26_2)
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

  int weight_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_17_1) & 63;
  aux_2 = (aux_2 + weight_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_92_1 > 13)
  {
    acc_1 = ((acc_1 + (parity_92_1 * 2)) + 5) & 127;
    aux_1 ^= parity_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_92_2 > 13)
  {
    acc_2 = ((acc_2 + (parity_92_2 * 2)) + 5) & 127;
    aux_2 ^= parity_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_92_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_26_1 == index_reg_26_2);
  assert(weight_17_1 == weight_17_2);
  assert(parity_92_1 == parity_92_2);
}

int fn_R001536_3613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int index_reg_26 = (aux + st.buffer[1]) & 3;
  switch (index_reg_26)
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

  int weight_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_17) & 63;
  acc ^= aux;
  int parity_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_92 > 13)
  {
    acc = ((acc + (parity_92 * 2)) + 5) & 127;
    aux ^= parity_92 & 15;
  }
  else
  {
    acc = ((acc - parity_92) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int sample_98_1 = 0;
  int sample_98_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    sample_98_1 = ((sample_98_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_98_2 = ((sample_98_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_98_1) & 127;
    acc_2 = (acc_2 + sample_98_2) & 127;
  }

  int bound_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_98_1) & 63;
  aux_2 = (aux_2 + bound_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_18_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_18_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_18_1 > 48)
  {
    acc_1 = ((acc_1 + (weight_18_1 * 2)) + 5) & 127;
    aux_1 ^= weight_18_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_18_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_18_2 > 48)
  {
    acc_2 = ((acc_2 + (weight_18_2 * 2)) + 5) & 127;
    aux_2 ^= weight_18_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_18_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_98_1 == sample_98_2);
  assert(bound_98_1 == bound_98_2);
  assert(weight_18_1 == weight_18_2);
}

int fn_R001536_3613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int sample_98 = 0;
  for (int k = 0; k < 3; k++)
  {
    sample_98 = ((sample_98 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_98) & 127;
  }

  int bound_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_98) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_18 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_18 > 48)
  {
    acc = ((acc + (weight_18 * 2)) + 5) & 127;
    aux ^= weight_18 & 15;
  }
  else
  {
    acc = ((acc - weight_18) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001536_3613_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st_1 = {0};
  struct EventLog_R001536_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int anchor_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_21_1) & 63;
  aux_2 = (aux_2 + anchor_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_38_1 = 0;
  int offset_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    offset_38_1 = ((offset_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_38_2 = ((offset_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_38_1) & 127;
    acc_2 = (acc_2 + offset_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_21_1 == anchor_21_2);
  assert(offset_38_1 == offset_38_2);
}

int fn_R001536_3613_13(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_21) & 63;
  acc ^= aux;
  int offset_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    offset_38 = ((offset_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001536_3613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st_1 = {0};
  struct EventLog_R001536_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int threshold_31_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_31_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_31_1)
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

  switch (threshold_31_2)
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

  int margin_15_1 = 0;
  int margin_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_15_1 = ((margin_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_15_2 = ((margin_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_15_1) & 127;
    acc_2 = (acc_2 + margin_15_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_31_1 == threshold_31_2);
  assert(margin_15_1 == margin_15_2);
}

int fn_R001536_3613_14(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int threshold_31 = (aux + st.buffer[1]) & 3;
  switch (threshold_31)
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

  int margin_15 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_15 = ((margin_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_15) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001536_3613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st_1 = {0};
  struct AudioFrame_R001536_3613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int segment_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_49_1 > 27)
  {
    acc_1 = ((acc_1 + (segment_49_1 * 2)) + 5) & 127;
    aux_1 ^= segment_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_49_2 > 27)
  {
    acc_2 = ((acc_2 + (segment_49_2 * 2)) + 5) & 127;
    aux_2 ^= segment_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_70_1) & 63;
  aux_2 = (aux_2 + tally_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.gain == st_2.gain);
  assert(st_1.peak == st_2.peak);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_49_1 == segment_49_2);
  assert(tally_70_1 == tally_70_2);
}

int fn_R001536_3613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R001536_3613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int segment_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_49 > 27)
  {
    acc = ((acc + (segment_49 * 2)) + 5) & 127;
    aux ^= segment_49 & 15;
  }
  else
  {
    acc = ((acc - segment_49) + 11) & 127;
    aux += 3;
  }
  int tally_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_70) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_48_1 = local_arr_1[aux_1 % 3];
  int quotient_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_48_2 * 2)) & 127;
  int sample_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_12_1)
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

  switch (sample_12_2)
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

  int quotient_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_55_1) & 63;
  aux_2 = (aux_2 + quotient_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_48_1 == quotient_48_2);
  assert(sample_12_1 == sample_12_2);
  assert(quotient_55_1 == quotient_55_2);
}

int fn_R001536_3613_16(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int local_arr[3] = {4, 9, 15};
  int quotient_48 = local_arr[aux % 3];
  acc = (acc + (quotient_48 * 2)) & 127;
  int sample_12 = (aux + st.buffer[1]) & 3;
  switch (sample_12)
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

  int quotient_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001536_3613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st_1 = {0};
  struct Transaction_R001536_3613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int tally_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_91_1)
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

  switch (tally_91_2)
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

  int parity_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_55_1 > 22)
  {
    acc_1 = ((acc_1 + (parity_55_1 * 2)) + 5) & 127;
    aux_1 ^= parity_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_55_2 > 22)
  {
    acc_2 = ((acc_2 + (parity_55_2 * 2)) + 5) & 127;
    aux_2 ^= parity_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_55_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_91_1 == tally_91_2);
  assert(parity_55_1 == parity_55_2);
}

int fn_R001536_3613_17(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001536_3613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int tally_91 = (aux + st.buffer[1]) & 3;
  switch (tally_91)
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

  int parity_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_55 > 22)
  {
    acc = ((acc + (parity_55 * 2)) + 5) & 127;
    aux ^= parity_55 & 15;
  }
  else
  {
    acc = ((acc - parity_55) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001536_3613_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st_1 = {0};
  struct EventLog_R001536_3613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_38_1 = local_arr_1[aux_1 % 3];
  int pivot_38_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_38_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_38_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_29_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_29_1 * 2)) + 5) & 127;
    aux_1 ^= stride_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_29_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_29_2 * 2)) + 5) & 127;
    aux_2 ^= stride_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_66_1 = 0;
  int weight_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_66_1 = ((weight_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_66_2 = ((weight_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_66_1) & 127;
    acc_2 = (acc_2 + weight_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.signature == st_2.signature);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_38_1 == pivot_38_2);
  assert(stride_29_1 == stride_29_2);
  assert(weight_66_1 == weight_66_2);
}

int fn_R001536_3613_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001536_3613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int pivot_38 = local_arr[aux % 3];
  acc = (acc + (pivot_38 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_29 > 30)
  {
    acc = ((acc + (stride_29 * 2)) + 5) & 127;
    aux ^= stride_29 & 15;
  }
  else
  {
    acc = ((acc - stride_29) + 11) & 127;
    aux += 3;
  }
  int weight_66 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_66 = ((weight_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_66) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001536_0_1;
  int sec_r001536_0_2;
  int sec_r001536_1_1;
  int sec_r001536_1_2;
  int sec_r001536_2_1;
  int sec_r001536_2_2;
  int sec_r001536_3_1;
  int sec_r001536_3_2;
  int sec_r001536_4_1;
  int sec_r001536_4_2;
  int sec_r001536_5_1;
  int sec_r001536_5_2;
  int sec_r001536_6_1;
  int sec_r001536_6_2;
  int sec_r001536_7_1;
  int sec_r001536_7_2;
  int sec_r001536_8_1;
  int sec_r001536_8_2;
  int sec_r001536_9_1;
  int sec_r001536_9_2;
  int sec_r001536_10_1;
  int sec_r001536_10_2;
  int sec_r001536_11_1;
  int sec_r001536_11_2;
  int sec_r001536_12_1;
  int sec_r001536_12_2;
  int sec_r001536_13_1;
  int sec_r001536_13_2;
  int sec_r001536_14_1;
  int sec_r001536_14_2;
  int sec_r001536_15_1;
  int sec_r001536_15_2;
  int sec_r001536_16_1;
  int sec_r001536_16_2;
  int sec_r001536_17_1;
  int sec_r001536_17_2;
  int sec_r001536_18_1;
  int sec_r001536_18_2;
  int pub_r001536_0_1;
  int pub_r001536_0_2;
  int pub_r001536_1_1;
  int pub_r001536_1_2;
  int pub_r001536_2_1;
  int pub_r001536_2_2;
  int pub_r001536_3_1;
  int pub_r001536_3_2;
  int pub_r001536_4_1;
  int pub_r001536_4_2;
  int pub_r001536_5_1;
  int pub_r001536_5_2;
  int pub_r001536_6_1;
  int pub_r001536_6_2;
  int pub_r001536_7_1;
  int pub_r001536_7_2;
  int pub_r001536_8_1;
  int pub_r001536_8_2;
  int pub_r001536_9_1;
  int pub_r001536_9_2;
  int pub_r001536_10_1;
  int pub_r001536_10_2;
  int pub_r001536_11_1;
  int pub_r001536_11_2;
  int pub_r001536_12_1;
  int pub_r001536_12_2;
  int pub_r001536_13_1;
  int pub_r001536_13_2;
  int pub_r001536_14_1;
  int pub_r001536_14_2;
  int pub_r001536_15_1;
  int pub_r001536_15_2;
  int pub_r001536_16_1;
  int pub_r001536_16_2;
  int pub_r001536_17_1;
  int pub_r001536_17_2;
  int pub_r001536_18_1;
  int pub_r001536_18_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001536_0_1 >= (-100)) && (pub_r001536_0_1 <= 100));
  __CPROVER_assume((pub_r001536_0_2 >= (-100)) && (pub_r001536_0_2 <= 100));
  __CPROVER_assume((pub_r001536_1_1 >= (-100)) && (pub_r001536_1_1 <= 100));
  __CPROVER_assume((pub_r001536_1_2 >= (-100)) && (pub_r001536_1_2 <= 100));
  __CPROVER_assume((pub_r001536_2_1 >= (-100)) && (pub_r001536_2_1 <= 100));
  __CPROVER_assume((pub_r001536_2_2 >= (-100)) && (pub_r001536_2_2 <= 100));
  __CPROVER_assume((pub_r001536_3_1 >= (-100)) && (pub_r001536_3_1 <= 100));
  __CPROVER_assume((pub_r001536_3_2 >= (-100)) && (pub_r001536_3_2 <= 100));
  __CPROVER_assume((pub_r001536_4_1 >= (-100)) && (pub_r001536_4_1 <= 100));
  __CPROVER_assume((pub_r001536_4_2 >= (-100)) && (pub_r001536_4_2 <= 100));
  __CPROVER_assume((pub_r001536_5_1 >= (-100)) && (pub_r001536_5_1 <= 100));
  __CPROVER_assume((pub_r001536_5_2 >= (-100)) && (pub_r001536_5_2 <= 100));
  __CPROVER_assume((pub_r001536_6_1 >= (-100)) && (pub_r001536_6_1 <= 100));
  __CPROVER_assume((pub_r001536_6_2 >= (-100)) && (pub_r001536_6_2 <= 100));
  __CPROVER_assume((pub_r001536_7_1 >= (-100)) && (pub_r001536_7_1 <= 100));
  __CPROVER_assume((pub_r001536_7_2 >= (-100)) && (pub_r001536_7_2 <= 100));
  __CPROVER_assume((pub_r001536_8_1 >= (-100)) && (pub_r001536_8_1 <= 100));
  __CPROVER_assume((pub_r001536_8_2 >= (-100)) && (pub_r001536_8_2 <= 100));
  __CPROVER_assume((pub_r001536_9_1 >= (-100)) && (pub_r001536_9_1 <= 100));
  __CPROVER_assume((pub_r001536_9_2 >= (-100)) && (pub_r001536_9_2 <= 100));
  __CPROVER_assume((pub_r001536_10_1 >= (-100)) && (pub_r001536_10_1 <= 100));
  __CPROVER_assume((pub_r001536_10_2 >= (-100)) && (pub_r001536_10_2 <= 100));
  __CPROVER_assume((pub_r001536_11_1 >= (-100)) && (pub_r001536_11_1 <= 100));
  __CPROVER_assume((pub_r001536_11_2 >= (-100)) && (pub_r001536_11_2 <= 100));
  __CPROVER_assume((pub_r001536_12_1 >= (-100)) && (pub_r001536_12_1 <= 100));
  __CPROVER_assume((pub_r001536_12_2 >= (-100)) && (pub_r001536_12_2 <= 100));
  __CPROVER_assume((pub_r001536_13_1 >= (-100)) && (pub_r001536_13_1 <= 100));
  __CPROVER_assume((pub_r001536_13_2 >= (-100)) && (pub_r001536_13_2 <= 100));
  __CPROVER_assume((pub_r001536_14_1 >= (-100)) && (pub_r001536_14_1 <= 100));
  __CPROVER_assume((pub_r001536_14_2 >= (-100)) && (pub_r001536_14_2 <= 100));
  __CPROVER_assume((pub_r001536_15_1 >= (-100)) && (pub_r001536_15_1 <= 100));
  __CPROVER_assume((pub_r001536_15_2 >= (-100)) && (pub_r001536_15_2 <= 100));
  __CPROVER_assume((pub_r001536_16_1 >= (-100)) && (pub_r001536_16_1 <= 100));
  __CPROVER_assume((pub_r001536_16_2 >= (-100)) && (pub_r001536_16_2 <= 100));
  __CPROVER_assume((pub_r001536_17_1 >= (-100)) && (pub_r001536_17_1 <= 100));
  __CPROVER_assume((pub_r001536_17_2 >= (-100)) && (pub_r001536_17_2 <= 100));
  __CPROVER_assume((pub_r001536_18_1 >= (-100)) && (pub_r001536_18_1 <= 100));
  __CPROVER_assume((pub_r001536_18_2 >= (-100)) && (pub_r001536_18_2 <= 100));
  __CPROVER_assume((sec_r001536_0_1 >= 0) && (sec_r001536_0_1 <= 255));
  __CPROVER_assume((sec_r001536_0_2 >= 0) && (sec_r001536_0_2 <= 255));
  __CPROVER_assume((sec_r001536_1_1 >= 0) && (sec_r001536_1_1 <= 255));
  __CPROVER_assume((sec_r001536_1_2 >= 0) && (sec_r001536_1_2 <= 255));
  __CPROVER_assume((sec_r001536_2_1 >= 0) && (sec_r001536_2_1 <= 255));
  __CPROVER_assume((sec_r001536_2_2 >= 0) && (sec_r001536_2_2 <= 255));
  __CPROVER_assume((sec_r001536_3_1 >= 0) && (sec_r001536_3_1 <= 255));
  __CPROVER_assume((sec_r001536_3_2 >= 0) && (sec_r001536_3_2 <= 255));
  __CPROVER_assume((sec_r001536_4_1 >= 0) && (sec_r001536_4_1 <= 255));
  __CPROVER_assume((sec_r001536_4_2 >= 0) && (sec_r001536_4_2 <= 255));
  __CPROVER_assume((sec_r001536_5_1 >= 0) && (sec_r001536_5_1 <= 255));
  __CPROVER_assume((sec_r001536_5_2 >= 0) && (sec_r001536_5_2 <= 255));
  __CPROVER_assume((sec_r001536_6_1 >= 0) && (sec_r001536_6_1 <= 255));
  __CPROVER_assume((sec_r001536_6_2 >= 0) && (sec_r001536_6_2 <= 255));
  __CPROVER_assume((sec_r001536_7_1 >= 0) && (sec_r001536_7_1 <= 255));
  __CPROVER_assume((sec_r001536_7_2 >= 0) && (sec_r001536_7_2 <= 255));
  __CPROVER_assume((sec_r001536_8_1 >= 0) && (sec_r001536_8_1 <= 255));
  __CPROVER_assume((sec_r001536_8_2 >= 0) && (sec_r001536_8_2 <= 255));
  __CPROVER_assume((sec_r001536_9_1 >= 0) && (sec_r001536_9_1 <= 255));
  __CPROVER_assume((sec_r001536_9_2 >= 0) && (sec_r001536_9_2 <= 255));
  __CPROVER_assume((sec_r001536_10_1 >= 0) && (sec_r001536_10_1 <= 255));
  __CPROVER_assume((sec_r001536_10_2 >= 0) && (sec_r001536_10_2 <= 255));
  __CPROVER_assume((sec_r001536_11_1 >= 0) && (sec_r001536_11_1 <= 255));
  __CPROVER_assume((sec_r001536_11_2 >= 0) && (sec_r001536_11_2 <= 255));
  __CPROVER_assume((sec_r001536_12_1 >= 0) && (sec_r001536_12_1 <= 255));
  __CPROVER_assume((sec_r001536_12_2 >= 0) && (sec_r001536_12_2 <= 255));
  __CPROVER_assume((sec_r001536_13_1 >= 0) && (sec_r001536_13_1 <= 255));
  __CPROVER_assume((sec_r001536_13_2 >= 0) && (sec_r001536_13_2 <= 255));
  __CPROVER_assume((sec_r001536_14_1 >= 0) && (sec_r001536_14_1 <= 255));
  __CPROVER_assume((sec_r001536_14_2 >= 0) && (sec_r001536_14_2 <= 255));
  __CPROVER_assume((sec_r001536_15_1 >= 0) && (sec_r001536_15_1 <= 255));
  __CPROVER_assume((sec_r001536_15_2 >= 0) && (sec_r001536_15_2 <= 255));
  __CPROVER_assume((sec_r001536_16_1 >= 0) && (sec_r001536_16_1 <= 255));
  __CPROVER_assume((sec_r001536_16_2 >= 0) && (sec_r001536_16_2 <= 255));
  __CPROVER_assume((sec_r001536_17_1 >= 0) && (sec_r001536_17_1 <= 255));
  __CPROVER_assume((sec_r001536_17_2 >= 0) && (sec_r001536_17_2 <= 255));
  __CPROVER_assume((sec_r001536_18_1 >= 0) && (sec_r001536_18_1 <= 255));
  __CPROVER_assume((sec_r001536_18_2 >= 0) && (sec_r001536_18_2 <= 255));
  struct EventLog_R001536_3613_0 st_var_0_1 = {0};
  struct EventLog_R001536_3613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001536_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001536_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001536_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001536_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001536_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001536_0_2 + 7) & 15;
  struct Transaction_R001536_3613_1 st_var_1_1 = {0};
  struct Transaction_R001536_3613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001536_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001536_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001536_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001536_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001536_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001536_0_2 + 9) & 15;
  struct AudioFrame_R001536_3613_2 st_var_2_1 = {0};
  struct AudioFrame_R001536_3613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001536_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001536_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001536_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001536_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001536_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001536_0_2 + 11) & 15;
  union RegisterBank_R001536_3613_0 u_var_1;
  union RegisterBank_R001536_3613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001536_3613_0(sec_r001536_0_1, sec_r001536_1_1, pub_r001536_2_1, pub_r001536_3_1);
  int helper_flow_0_2 = fn_R001536_3613_0(sec_r001536_0_2, sec_r001536_1_2, pub_r001536_2_2, pub_r001536_3_2);
  fn_R001536_3613_0_2(sec_r001536_0_1, sec_r001536_1_1, pub_r001536_2_1, pub_r001536_3_1, sec_r001536_0_2, sec_r001536_1_2, pub_r001536_2_2, pub_r001536_3_2);
  int helper_flow_1_1 = fn_R001536_3613_1(sec_r001536_1_1, pub_r001536_2_1, pub_r001536_3_1);
  int helper_flow_1_2 = fn_R001536_3613_1(sec_r001536_1_2, pub_r001536_2_2, pub_r001536_3_2);
  fn_R001536_3613_1_2(sec_r001536_1_1, pub_r001536_2_1, pub_r001536_3_1, sec_r001536_1_2, pub_r001536_2_2, pub_r001536_3_2);
  int helper_flow_2_1 = fn_R001536_3613_2(sec_r001536_2_1, sec_r001536_3_1);
  int helper_flow_2_2 = fn_R001536_3613_2(sec_r001536_2_2, sec_r001536_3_2);
  fn_R001536_3613_2_2(sec_r001536_2_1, sec_r001536_3_1, sec_r001536_2_2, sec_r001536_3_2);
  int helper_flow_3_1 = fn_R001536_3613_3(sec_r001536_3_1, pub_r001536_4_1, pub_r001536_5_1, pub_r001536_6_1);
  int helper_flow_3_2 = fn_R001536_3613_3(sec_r001536_3_2, pub_r001536_4_2, pub_r001536_5_2, pub_r001536_6_2);
  fn_R001536_3613_3_2(sec_r001536_3_1, pub_r001536_4_1, pub_r001536_5_1, pub_r001536_6_1, sec_r001536_3_2, pub_r001536_4_2, pub_r001536_5_2, pub_r001536_6_2);
  int helper_flow_4_1 = fn_R001536_3613_4(sec_r001536_4_1, sec_r001536_5_1, pub_r001536_6_1, pub_r001536_7_1);
  int helper_flow_4_2 = fn_R001536_3613_4(sec_r001536_4_2, sec_r001536_5_2, pub_r001536_6_2, pub_r001536_7_2);
  fn_R001536_3613_4_2(sec_r001536_4_1, sec_r001536_5_1, pub_r001536_6_1, pub_r001536_7_1, sec_r001536_4_2, sec_r001536_5_2, pub_r001536_6_2, pub_r001536_7_2);
  int helper_flow_5_1 = fn_R001536_3613_5(sec_r001536_5_1, sec_r001536_6_1, pub_r001536_7_1, pub_r001536_8_1, pub_r001536_9_1);
  int helper_flow_5_2 = fn_R001536_3613_5(sec_r001536_5_2, sec_r001536_6_2, pub_r001536_7_2, pub_r001536_8_2, pub_r001536_9_2);
  fn_R001536_3613_5_2(sec_r001536_5_1, sec_r001536_6_1, pub_r001536_7_1, pub_r001536_8_1, pub_r001536_9_1, sec_r001536_5_2, sec_r001536_6_2, pub_r001536_7_2, pub_r001536_8_2, pub_r001536_9_2);
  int helper_flow_6_1 = fn_R001536_3613_6(sec_r001536_6_1, sec_r001536_7_1, pub_r001536_8_1, pub_r001536_9_1);
  int helper_flow_6_2 = fn_R001536_3613_6(sec_r001536_6_2, sec_r001536_7_2, pub_r001536_8_2, pub_r001536_9_2);
  fn_R001536_3613_6_2(sec_r001536_6_1, sec_r001536_7_1, pub_r001536_8_1, pub_r001536_9_1, sec_r001536_6_2, sec_r001536_7_2, pub_r001536_8_2, pub_r001536_9_2);
  int helper_flow_7_1 = fn_R001536_3613_7(sec_r001536_7_1, sec_r001536_8_1, pub_r001536_9_1, pub_r001536_10_1);
  int helper_flow_7_2 = fn_R001536_3613_7(sec_r001536_7_2, sec_r001536_8_2, pub_r001536_9_2, pub_r001536_10_2);
  fn_R001536_3613_7_2(sec_r001536_7_1, sec_r001536_8_1, pub_r001536_9_1, pub_r001536_10_1, sec_r001536_7_2, sec_r001536_8_2, pub_r001536_9_2, pub_r001536_10_2);
  int helper_flow_8_1 = fn_R001536_3613_8(sec_r001536_8_1, pub_r001536_9_1, pub_r001536_10_1, pub_r001536_11_1);
  int helper_flow_8_2 = fn_R001536_3613_8(sec_r001536_8_2, pub_r001536_9_2, pub_r001536_10_2, pub_r001536_11_2);
  fn_R001536_3613_8_2(sec_r001536_8_1, pub_r001536_9_1, pub_r001536_10_1, pub_r001536_11_1, sec_r001536_8_2, pub_r001536_9_2, pub_r001536_10_2, pub_r001536_11_2);
  int helper_flow_9_1 = fn_R001536_3613_9(sec_r001536_9_1, sec_r001536_10_1, pub_r001536_11_1, pub_r001536_12_1, pub_r001536_13_1);
  int helper_flow_9_2 = fn_R001536_3613_9(sec_r001536_9_2, sec_r001536_10_2, pub_r001536_11_2, pub_r001536_12_2, pub_r001536_13_2);
  fn_R001536_3613_9_2(sec_r001536_9_1, sec_r001536_10_1, pub_r001536_11_1, pub_r001536_12_1, pub_r001536_13_1, sec_r001536_9_2, sec_r001536_10_2, pub_r001536_11_2, pub_r001536_12_2, pub_r001536_13_2);
  int stage_v_0_1 = ((helper_flow_4_1 + (pub_r001536_14_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((helper_flow_4_2 + (pub_r001536_14_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001536_6_1 * 2) + 19) & 63;
  int stage_v_1_2 = ((pub_r001536_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((helper_flow_8_1 + (pub_r001536_0_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((helper_flow_8_2 + (pub_r001536_0_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((pub_r001536_16_1 * 2) + 33) & 63;
  int stage_v_3_2 = ((pub_r001536_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((sec_r001536_18_1 + (pub_r001536_6_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001536_18_2 + (pub_r001536_6_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((sec_r001536_7_1 + (pub_r001536_1_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001536_7_2 + (pub_r001536_1_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001536_17_1 * 2) + 49) & 63;
  int stage_v_6_2 = ((pub_r001536_17_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((helper_flow_4_1 + (pub_r001536_18_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((helper_flow_4_2 + (pub_r001536_18_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((sec_r001536_18_1 + (pub_r001536_6_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((sec_r001536_18_2 + (pub_r001536_6_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((stage_v_5_1 + (pub_r001536_13_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((stage_v_5_2 + (pub_r001536_13_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001536_7_1 + (pub_r001536_11_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001536_7_2 + (pub_r001536_11_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001536_4_1 + (pub_r001536_14_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001536_4_2 + (pub_r001536_14_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((helper_flow_5_1 + (pub_r001536_1_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((helper_flow_5_2 + (pub_r001536_1_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001536_6_1 * 2) + 28) & 63;
  int stage_v_13_2 = ((pub_r001536_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001536_1_1 + (pub_r001536_9_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001536_1_2 + (pub_r001536_9_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((pub_r001536_11_1 * 2) + 8) & 63;
  int stage_v_15_2 = ((pub_r001536_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((helper_flow_0_1 + (pub_r001536_14_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((helper_flow_0_2 + (pub_r001536_14_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((sec_r001536_12_1 + (pub_r001536_14_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001536_12_2 + (pub_r001536_14_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001536_18_1 + (pub_r001536_5_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001536_18_2 + (pub_r001536_5_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((sec_r001536_0_1 + (pub_r001536_11_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001536_0_2 + (pub_r001536_11_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((sec_r001536_5_1 + (pub_r001536_16_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001536_5_2 + (pub_r001536_16_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((helper_flow_7_1 + (pub_r001536_10_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_7_2 + (pub_r001536_10_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((pub_r001536_13_1 * 2) + 40) & 63;
  int stage_v_22_2 = ((pub_r001536_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((stage_v_16_1 + (pub_r001536_8_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((stage_v_16_2 + (pub_r001536_8_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((pub_r001536_10_1 * 2) + 14) & 63;
  int stage_v_24_2 = ((pub_r001536_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((helper_flow_1_1 + (pub_r001536_18_1 * 2)) + 80) & 127;
  int stage_v_25_2 = ((helper_flow_1_2 + (pub_r001536_18_2 * 2)) + 80) & 127;
  if (stage_v_25_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_25_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_25_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_25_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_26_1 = ((pub_r001536_15_1 * 2) + 48) & 63;
  int stage_v_26_2 = ((pub_r001536_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001536_8_1 * 2) + 20) & 63;
  int stage_v_27_2 = ((pub_r001536_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((stage_v_8_1 + (pub_r001536_15_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((stage_v_8_2 + (pub_r001536_15_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001536_1_1 + (pub_r001536_4_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001536_1_2 + (pub_r001536_4_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_9_1 + (pub_r001536_10_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_9_2 + (pub_r001536_10_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001536_16_1 * 2) + 14) & 63;
  int stage_v_31_2 = ((pub_r001536_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((stage_v_18_1 + (pub_r001536_4_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((stage_v_18_2 + (pub_r001536_4_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((sec_r001536_3_1 + (pub_r001536_14_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001536_3_2 + (pub_r001536_14_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((sec_r001536_11_1 + (pub_r001536_14_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((sec_r001536_11_2 + (pub_r001536_14_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((stage_v_11_1 + (pub_r001536_6_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((stage_v_11_2 + (pub_r001536_6_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((sec_r001536_11_1 + (pub_r001536_5_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001536_11_2 + (pub_r001536_5_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001536_13_1 * 2) + 34) & 63;
  int stage_v_37_2 = ((pub_r001536_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((stage_v_14_1 + (pub_r001536_4_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_14_2 + (pub_r001536_4_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001536_14_1 * 2) + 8) & 63;
  int stage_v_39_2 = ((pub_r001536_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_36_1 + (pub_r001536_3_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_36_2 + (pub_r001536_3_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((helper_flow_5_1 + (pub_r001536_12_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((helper_flow_5_2 + (pub_r001536_12_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((pub_r001536_16_1 * 2) + 45) & 63;
  int stage_v_42_2 = ((pub_r001536_16_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((stage_v_36_1 + (pub_r001536_13_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((stage_v_36_2 + (pub_r001536_13_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((sec_r001536_16_1 + (pub_r001536_4_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001536_16_2 + (pub_r001536_4_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((stage_v_10_1 + (pub_r001536_6_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((stage_v_10_2 + (pub_r001536_6_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001536_2_1 * 2) + 10) & 63;
  int stage_v_46_2 = ((pub_r001536_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_9_1 + (pub_r001536_11_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_9_2 + (pub_r001536_11_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_18_1 + (pub_r001536_14_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_18_2 + (pub_r001536_14_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_18_1 + (pub_r001536_17_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_18_2 + (pub_r001536_17_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((stage_v_32_1 + (pub_r001536_12_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_32_2 + (pub_r001536_12_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_12_1 + (pub_r001536_16_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_12_2 + (pub_r001536_16_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001536_2_1 + (pub_r001536_11_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001536_2_2 + (pub_r001536_11_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((pub_r001536_4_1 * 2) + 37) & 63;
  int stage_v_53_2 = ((pub_r001536_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((sec_r001536_9_1 + (pub_r001536_14_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001536_9_2 + (pub_r001536_14_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((helper_flow_3_1 + (pub_r001536_8_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((helper_flow_3_2 + (pub_r001536_8_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001536_2_1 * 2) + 36) & 63;
  int stage_v_56_2 = ((pub_r001536_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((stage_v_44_1 + (pub_r001536_5_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((stage_v_44_2 + (pub_r001536_5_2 * 2)) + 176) & 127;
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
  int stage_v_58_1 = ((stage_v_21_1 + (pub_r001536_5_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_21_2 + (pub_r001536_5_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((helper_flow_9_1 + (pub_r001536_18_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((helper_flow_9_2 + (pub_r001536_18_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001536_12_1 * 2) + 24) & 63;
  int stage_v_60_2 = ((pub_r001536_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001536_1_1 * 2) + 13) & 63;
  int stage_v_61_2 = ((pub_r001536_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001536_14_1 * 2) + 15) & 63;
  int stage_v_62_2 = ((pub_r001536_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((stage_v_34_1 + (pub_r001536_12_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_34_2 + (pub_r001536_12_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_28_1 + (pub_r001536_9_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_28_2 + (pub_r001536_9_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((sec_r001536_5_1 + (pub_r001536_7_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((sec_r001536_5_2 + (pub_r001536_7_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((pub_r001536_8_1 * 2) + 41) & 63;
  int stage_v_66_2 = ((pub_r001536_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_29_1 + (pub_r001536_9_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_29_2 + (pub_r001536_9_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_51_1 + (pub_r001536_14_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_51_2 + (pub_r001536_14_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((pub_r001536_7_1 * 2) + 7) & 63;
  int stage_v_69_2 = ((pub_r001536_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001536_8_1 * 2) + 10) & 63;
  int stage_v_70_2 = ((pub_r001536_8_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((stage_v_18_1 + (pub_r001536_10_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_18_2 + (pub_r001536_10_2 * 2)) + 218) & 127;
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
  int stage_v_72_1 = ((pub_r001536_7_1 * 2) + 41) & 63;
  int stage_v_72_2 = ((pub_r001536_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((stage_v_33_1 + (pub_r001536_1_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_33_2 + (pub_r001536_1_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_12_1 + (pub_r001536_6_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_12_2 + (pub_r001536_6_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_35_1 + (pub_r001536_5_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_35_2 + (pub_r001536_5_2 * 2)) + 230) & 127;
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
  int stage_v_76_1 = ((stage_v_68_1 + (pub_r001536_8_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_68_2 + (pub_r001536_8_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((stage_v_59_1 + (pub_r001536_12_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((stage_v_59_2 + (pub_r001536_12_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((pub_r001536_18_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001536_18_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001536_7_1 * 2) + 22) & 63;
  int stage_v_79_2 = ((pub_r001536_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((helper_flow_4_1 + (pub_r001536_9_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((helper_flow_4_2 + (pub_r001536_9_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((pub_r001536_0_1 * 2) + 29) & 63;
  int stage_v_81_2 = ((pub_r001536_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = ((pub_r001536_11_1 * 2) + 16) & 63;
  int stage_v_82_2 = ((pub_r001536_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001536_7_1 * 2) + 25) & 63;
  int stage_v_83_2 = ((pub_r001536_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((stage_v_43_1 + (pub_r001536_18_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_43_2 + (pub_r001536_18_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001536_13_1 * 2) + 18) & 63;
  int stage_v_85_2 = ((pub_r001536_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((stage_v_71_1 + (pub_r001536_12_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_71_2 + (pub_r001536_12_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_35_1 + (pub_r001536_17_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_35_2 + (pub_r001536_17_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001536_6_1 * 2) + 39) & 63;
  int stage_v_88_2 = ((pub_r001536_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((stage_v_38_1 + (pub_r001536_4_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_38_2 + (pub_r001536_4_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((stage_v_14_1 + (pub_r001536_13_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((stage_v_14_2 + (pub_r001536_13_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((sec_r001536_2_1 + (pub_r001536_10_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((sec_r001536_2_2 + (pub_r001536_10_2 * 2)) + 278) & 127;
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
  int stage_v_92_1 = ((stage_v_75_1 + (pub_r001536_1_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_75_2 + (pub_r001536_1_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_33_1 + (pub_r001536_8_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_33_2 + (pub_r001536_8_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_21_1 + (pub_r001536_8_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_21_2 + (pub_r001536_8_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_12_1 + (pub_r001536_0_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_12_2 + (pub_r001536_0_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001536_18_1 * 2) + 43) & 63;
  int stage_v_96_2 = ((pub_r001536_18_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((pub_r001536_11_1 * 2) + 17) & 63;
  int stage_v_97_2 = ((pub_r001536_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = ((pub_r001536_11_1 * 2) + 34) & 63;
  int stage_v_98_2 = ((pub_r001536_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_48_1 + (pub_r001536_16_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_48_2 + (pub_r001536_16_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((pub_r001536_0_1 * 2) + 8) & 63;
  int stage_v_100_2 = ((pub_r001536_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_64_1 + (pub_r001536_0_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_64_2 + (pub_r001536_0_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_18_1 + (pub_r001536_9_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_18_2 + (pub_r001536_9_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_89_1 + (pub_r001536_5_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_89_2 + (pub_r001536_5_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_48_1 + (pub_r001536_5_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_48_2 + (pub_r001536_5_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((pub_r001536_18_1 * 2) + 12) & 63;
  int stage_v_105_2 = ((pub_r001536_18_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001536_1_1 * 2) + 7) & 63;
  int stage_v_106_2 = ((pub_r001536_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((stage_v_90_1 + (pub_r001536_9_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((stage_v_90_2 + (pub_r001536_9_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001536_2_1 * 2) + 17) & 63;
  int stage_v_108_2 = ((pub_r001536_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_20_1 + (pub_r001536_3_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_20_2 + (pub_r001536_3_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((stage_v_94_1 + (pub_r001536_12_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((stage_v_94_2 + (pub_r001536_12_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((pub_r001536_0_1 * 2) + 18) & 63;
  int stage_v_111_2 = ((pub_r001536_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001536_4_1 * 2) + 47) & 63;
  int stage_v_112_2 = ((pub_r001536_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001536_15_1 * 2) + 33) & 63;
  int stage_v_113_2 = ((pub_r001536_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_109_1 + (pub_r001536_5_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_109_2 + (pub_r001536_5_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((pub_r001536_5_1 * 2) + 24) & 63;
  int stage_v_115_2 = ((pub_r001536_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((stage_v_54_1 + (pub_r001536_2_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_54_2 + (pub_r001536_2_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_57_1 + (pub_r001536_13_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_57_2 + (pub_r001536_13_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((sec_r001536_6_1 + (pub_r001536_2_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((sec_r001536_6_2 + (pub_r001536_2_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((sec_r001536_10_1 + (pub_r001536_2_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((sec_r001536_10_2 + (pub_r001536_2_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001536_0_1 + (pub_r001536_2_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001536_0_2 + (pub_r001536_2_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((pub_r001536_18_1 * 2) + 13) & 63;
  int stage_v_121_2 = ((pub_r001536_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001536_2_1 * 2) + 19) & 63;
  int stage_v_122_2 = ((pub_r001536_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001536_14_1 * 2) + 15) & 63;
  int stage_v_123_2 = ((pub_r001536_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((helper_flow_8_1 + (pub_r001536_9_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((helper_flow_8_2 + (pub_r001536_9_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((sec_r001536_11_1 + (pub_r001536_2_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((sec_r001536_11_2 + (pub_r001536_2_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((pub_r001536_5_1 * 2) + 40) & 63;
  int stage_v_126_2 = ((pub_r001536_5_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((stage_v_114_1 + (pub_r001536_8_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_114_2 + (pub_r001536_8_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_76_1 + (pub_r001536_14_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_76_2 + (pub_r001536_14_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_57_1 + (pub_r001536_14_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_57_2 + (pub_r001536_14_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_80_1 + (pub_r001536_2_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_80_2 + (pub_r001536_2_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((stage_v_75_1 + (pub_r001536_5_1 * 2)) + 398) & 127;
  int stage_v_131_2 = ((stage_v_75_2 + (pub_r001536_5_2 * 2)) + 398) & 127;
  if (stage_v_131_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_131_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_131_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_131_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_132_1 = ((stage_v_28_1 + (pub_r001536_4_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_28_2 + (pub_r001536_4_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((pub_r001536_16_1 * 2) + 31) & 63;
  int stage_v_133_2 = ((pub_r001536_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((stage_v_35_1 + (pub_r001536_7_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_35_2 + (pub_r001536_7_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001536_6_1 * 2) + 30) & 63;
  int stage_v_135_2 = ((pub_r001536_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_91_1 + (pub_r001536_18_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_91_2 + (pub_r001536_18_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_127_1 + (pub_r001536_0_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_127_2 + (pub_r001536_0_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((stage_v_14_1 + (pub_r001536_10_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_14_2 + (pub_r001536_10_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((pub_r001536_9_1 * 2) + 30) & 63;
  int stage_v_139_2 = ((pub_r001536_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_51_1 + (pub_r001536_17_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_51_2 + (pub_r001536_17_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001536_3_1 * 2) + 27) & 63;
  int stage_v_141_2 = ((pub_r001536_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_73_1 + (pub_r001536_18_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_73_2 + (pub_r001536_18_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((pub_r001536_12_1 * 2) + 27) & 63;
  int stage_v_143_2 = ((pub_r001536_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((stage_v_47_1 + (pub_r001536_13_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_47_2 + (pub_r001536_13_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((sec_r001536_17_1 + (pub_r001536_6_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((sec_r001536_17_2 + (pub_r001536_6_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_137_1 + (pub_r001536_13_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_137_2 + (pub_r001536_13_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_51_1 + (pub_r001536_1_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_51_2 + (pub_r001536_1_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((pub_r001536_10_1 * 2) + 17) & 63;
  int stage_v_148_2 = ((pub_r001536_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001536_4_1 * 2) + 47) & 63;
  int stage_v_149_2 = ((pub_r001536_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((sec_r001536_1_1 + (pub_r001536_1_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((sec_r001536_1_2 + (pub_r001536_1_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((helper_flow_8_1 + (pub_r001536_15_1 * 2)) + 458) & 127;
  int stage_v_151_2 = ((helper_flow_8_2 + (pub_r001536_15_2 * 2)) + 458) & 127;
  if (stage_v_151_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_151_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_151_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_151_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_152_1 = ((stage_v_118_1 + (pub_r001536_6_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_118_2 + (pub_r001536_6_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001536_11_1 * 2) + 10) & 63;
  int stage_v_153_2 = ((pub_r001536_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((sec_r001536_2_1 + (pub_r001536_12_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((sec_r001536_2_2 + (pub_r001536_12_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((stage_v_80_1 + (pub_r001536_3_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((stage_v_80_2 + (pub_r001536_3_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((pub_r001536_6_1 * 2) + 38) & 63;
  int stage_v_156_2 = ((pub_r001536_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001536_16_1 * 2) + 7) & 63;
  int stage_v_157_2 = ((pub_r001536_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((stage_v_59_1 + (pub_r001536_3_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_59_2 + (pub_r001536_3_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_54_1 + (pub_r001536_9_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_54_2 + (pub_r001536_9_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((stage_v_58_1 + (pub_r001536_11_1 * 2)) + 485) & 127;
  int stage_v_160_2 = ((stage_v_58_2 + (pub_r001536_11_2 * 2)) + 485) & 127;
  if (stage_v_160_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_160_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_160_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_160_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_161_1 = ((pub_r001536_15_1 * 2) + 21) & 63;
  int stage_v_161_2 = ((pub_r001536_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_64_1 + (pub_r001536_5_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_64_2 + (pub_r001536_5_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001536_16_1 * 2) + 20) & 63;
  int stage_v_163_2 = ((pub_r001536_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001536_5_1 * 2) + 43) & 63;
  int stage_v_164_2 = ((pub_r001536_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001536_13_1 * 2) + 27) & 63;
  int stage_v_165_2 = ((pub_r001536_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((sec_r001536_2_1 + (pub_r001536_5_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((sec_r001536_2_2 + (pub_r001536_5_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001536_13_1 * 2) + 33) & 63;
  int stage_v_167_2 = ((pub_r001536_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_102_1 + (pub_r001536_14_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_102_2 + (pub_r001536_14_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_63_1 + (pub_r001536_0_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_63_2 + (pub_r001536_0_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001536_14_1 * 2) + 34) & 63;
  int stage_v_170_2 = ((pub_r001536_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001536_5_1 * 2) + 35) & 63;
  int stage_v_171_2 = ((pub_r001536_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_158_1 + (pub_r001536_13_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_158_2 + (pub_r001536_13_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001536_1_1 * 2) + 43) & 63;
  int stage_v_173_2 = ((pub_r001536_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_67_1 + (pub_r001536_4_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_67_2 + (pub_r001536_4_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_18_1 + (pub_r001536_8_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_18_2 + (pub_r001536_8_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_124_1 + (pub_r001536_0_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_124_2 + (pub_r001536_0_2 * 2)) + 533) & 127;
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
  int stage_v_177_1 = ((pub_r001536_7_1 * 2) + 18) & 63;
  int stage_v_177_2 = ((pub_r001536_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((stage_v_104_1 + (pub_r001536_10_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_104_2 + (pub_r001536_10_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((pub_r001536_10_1 * 2) + 46) & 63;
  int stage_v_179_2 = ((pub_r001536_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001536_12_1 * 2) + 38) & 63;
  int stage_v_180_2 = ((pub_r001536_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((stage_v_36_1 + (pub_r001536_15_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((stage_v_36_2 + (pub_r001536_15_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((sec_r001536_14_1 + (pub_r001536_15_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((sec_r001536_14_2 + (pub_r001536_15_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_2_1 + (pub_r001536_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_2_2 + (pub_r001536_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_95_1 + (pub_r001536_2_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_95_2 + (pub_r001536_2_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_9_1 + (pub_r001536_10_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_9_2 + (pub_r001536_10_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((stage_v_9_1 + (pub_r001536_1_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_9_2 + (pub_r001536_1_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_93_1 + (pub_r001536_9_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_93_2 + (pub_r001536_9_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001536_0_1 * 2) + 28) & 63;
  int stage_v_188_2 = ((pub_r001536_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((stage_v_45_1 + (pub_r001536_2_1 * 2)) + 572) & 127;
  int stage_v_189_2 = ((stage_v_45_2 + (pub_r001536_2_2 * 2)) + 572) & 127;
  if (stage_v_189_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_189_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_189_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_189_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_190_1 = ((pub_r001536_9_1 * 2) + 28) & 63;
  int stage_v_190_2 = ((pub_r001536_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((sec_r001536_16_1 + (pub_r001536_17_1 * 2)) + 578) & 127;
  int stage_v_191_2 = ((sec_r001536_16_2 + (pub_r001536_17_2 * 2)) + 578) & 127;
  if (stage_v_191_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_191_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_191_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_191_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_192_1 = ((stage_v_166_1 + (pub_r001536_16_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_166_2 + (pub_r001536_16_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_144_1 + (pub_r001536_8_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_144_2 + (pub_r001536_8_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_102_1 + (pub_r001536_11_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_102_2 + (pub_r001536_11_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((sec_r001536_8_1 + (pub_r001536_17_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((sec_r001536_8_2 + (pub_r001536_17_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((sec_r001536_3_1 + (pub_r001536_12_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((sec_r001536_3_2 + (pub_r001536_12_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001536_15_1 * 2) + 18) & 63;
  int stage_v_197_2 = ((pub_r001536_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001536_1_1 * 2) + 22) & 63;
  int stage_v_198_2 = ((pub_r001536_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_93_1 + (pub_r001536_2_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_93_2 + (pub_r001536_2_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_138_1 + (pub_r001536_1_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_138_2 + (pub_r001536_1_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_129_1 + (pub_r001536_13_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_129_2 + (pub_r001536_13_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_151_1 + (pub_r001536_8_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_151_2 + (pub_r001536_8_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_8_1 + (pub_r001536_14_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_8_2 + (pub_r001536_14_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_50_1 + (pub_r001536_10_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_50_2 + (pub_r001536_10_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001536_13_1 * 2) + 14) & 63;
  int stage_v_205_2 = ((pub_r001536_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001536_7_1 * 2) + 46) & 63;
  int stage_v_206_2 = ((pub_r001536_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001536_15_1 * 2) + 44) & 63;
  int stage_v_207_2 = ((pub_r001536_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((stage_v_47_1 + (pub_r001536_16_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_47_2 + (pub_r001536_16_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001536_7_1 == pub_r001536_7_2);
  __CPROVER_assume(pub_r001536_12_1 == pub_r001536_12_2);
  __CPROVER_assume(pub_r001536_14_1 == pub_r001536_14_2);
  __CPROVER_assume(sec_r001536_1_1 != sec_r001536_1_2);
  __CPROVER_assume(sec_r001536_6_1 != sec_r001536_6_2);
  __CPROVER_assume(sec_r001536_13_1 != sec_r001536_13_2);
  __CPROVER_assume(pub_r001536_16_1 == pub_r001536_16_2);
  __CPROVER_assume(sec_r001536_11_1 != sec_r001536_11_2);
  __CPROVER_assume(pub_r001536_5_1 == pub_r001536_5_2);
  __CPROVER_assume(sec_r001536_5_1 != sec_r001536_5_2);
  __CPROVER_assume(pub_r001536_10_1 == pub_r001536_10_2);
  __CPROVER_assume(sec_r001536_0_1 != sec_r001536_0_2);
  __CPROVER_assume(pub_r001536_17_1 == pub_r001536_17_2);
  __CPROVER_assume(pub_r001536_13_1 == pub_r001536_13_2);
  __CPROVER_assume(pub_r001536_3_1 == pub_r001536_3_2);
  __CPROVER_assume(sec_r001536_3_1 != sec_r001536_3_2);
  __CPROVER_assume(pub_r001536_2_1 == pub_r001536_2_2);
  __CPROVER_assume(sec_r001536_9_1 != sec_r001536_9_2);
  __CPROVER_assume(pub_r001536_11_1 == pub_r001536_11_2);
  __CPROVER_assume(sec_r001536_12_1 != sec_r001536_12_2);
  __CPROVER_assume(pub_r001536_6_1 == pub_r001536_6_2);
  __CPROVER_assume(sec_r001536_2_1 != sec_r001536_2_2);
  __CPROVER_assume(pub_r001536_1_1 == pub_r001536_1_2);
  __CPROVER_assume(sec_r001536_16_1 != sec_r001536_16_2);
  __CPROVER_assume(sec_r001536_14_1 != sec_r001536_14_2);
  __CPROVER_assume(sec_r001536_18_1 != sec_r001536_18_2);
  __CPROVER_assume(sec_r001536_8_1 != sec_r001536_8_2);
  __CPROVER_assume(sec_r001536_4_1 != sec_r001536_4_2);
  __CPROVER_assume(pub_r001536_8_1 == pub_r001536_8_2);
  __CPROVER_assume(sec_r001536_7_1 != sec_r001536_7_2);
  __CPROVER_assume(sec_r001536_10_1 != sec_r001536_10_2);
  __CPROVER_assume(sec_r001536_15_1 != sec_r001536_15_2);
  __CPROVER_assume(sec_r001536_17_1 != sec_r001536_17_2);
  __CPROVER_assume(pub_r001536_15_1 == pub_r001536_15_2);
  __CPROVER_assume(pub_r001536_0_1 == pub_r001536_0_2);
  __CPROVER_assume(pub_r001536_4_1 == pub_r001536_4_2);
  __CPROVER_assume(pub_r001536_9_1 == pub_r001536_9_2);
  __CPROVER_assume(pub_r001536_18_1 == pub_r001536_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.auth_code == st_var_1_2.auth_code);
  assert(st_var_1_1.rate == st_var_1_2.rate);
  assert(st_var_1_1.fee == st_var_1_2.fee);
  assert(st_var_1_1.account_id == st_var_1_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.envelope == st_var_2_2.envelope);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.peak == st_var_2_2.peak);
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
}


