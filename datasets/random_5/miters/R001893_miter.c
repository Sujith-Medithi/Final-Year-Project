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
struct Transaction_R001893_9313_0
{
  int fee;
  short balance;
  short status;
  short auth_code;
  int rate;
  int account_id;
  int buffer[3];
};
struct EventLog_R001893_9313_1
{
  int code;
  short signature;
  int severity;
  short facility;
  int buffer[3];
};
union TelemetryField_R001893_9313_0
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
void fn_R001893_9313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_97_1 = local_arr_1[aux_1 % 3];
  int pivot_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_97_2 * 2)) & 127;
  int accumulator_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_71_1) & 63;
  aux_2 = (aux_2 + accumulator_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
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

  assert(pivot_97_1 == pivot_97_2);
  assert(accumulator_71_1 == accumulator_71_2);
}

int fn_R001893_9313_0(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int pivot_97 = local_arr[aux % 3];
  acc = (acc + (pivot_97 * 2)) & 127;
  int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_71) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_41_1 = local_arr_1[aux_1 % 3];
  int bound_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_41_2 * 2)) & 127;
  int mask_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_27_1) & 63;
  aux_2 = (aux_2 + mask_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_73_1 > 42)
  {
    acc_1 = ((acc_1 + (factor_73_1 * 2)) + 5) & 127;
    aux_1 ^= factor_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_73_2 > 42)
  {
    acc_2 = ((acc_2 + (factor_73_2 * 2)) + 5) & 127;
    aux_2 ^= factor_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_46_1)
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

  switch (margin_46_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_41_1 == bound_41_2);
  assert(mask_27_1 == mask_27_2);
  assert(factor_73_1 == factor_73_2);
  assert(margin_46_1 == margin_46_2);
}

int fn_R001893_9313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int local_arr[3] = {4, 9, 15};
  int bound_41 = local_arr[aux % 3];
  acc = (acc + (bound_41 * 2)) & 127;
  int mask_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_27) & 63;
  acc ^= aux;
  int factor_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_73 > 42)
  {
    acc = ((acc + (factor_73 * 2)) + 5) & 127;
    aux ^= factor_73 & 15;
  }
  else
  {
    acc = ((acc - factor_73) + 11) & 127;
    aux += 3;
  }
  int margin_46 = (aux + st.buffer[1]) & 3;
  switch (margin_46)
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

void fn_R001893_9313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_22_1) & 63;
  aux_2 = (aux_2 + stride_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_16_1)
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

  switch (checksum_16_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_22_1 == stride_22_2);
  assert(checksum_16_1 == checksum_16_2);
}

int fn_R001893_9313_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_22) & 63;
  acc ^= aux;
  int checksum_16 = (aux + st.buffer[1]) & 3;
  switch (checksum_16)
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

void fn_R001893_9313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_63_1) & 63;
  aux_2 = (aux_2 + delta_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_98_1)
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

  switch (stride_98_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_63_1 == delta_63_2);
  assert(stride_98_1 == stride_98_2);
}

int fn_R001893_9313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_63) & 63;
  acc ^= aux;
  int stride_98 = (aux + st.buffer[1]) & 3;
  switch (stride_98)
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

void fn_R001893_9313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int pivot_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_98_1) & 63;
  aux_2 = (aux_2 + pivot_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_49_1 > 50)
  {
    acc_1 = ((acc_1 + (vector_49_1 * 2)) + 5) & 127;
    aux_1 ^= vector_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_49_2 > 50)
  {
    acc_2 = ((acc_2 + (vector_49_2 * 2)) + 5) & 127;
    aux_2 ^= vector_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_98_1 == pivot_98_2);
  assert(vector_49_1 == vector_49_2);
}

int fn_R001893_9313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int pivot_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_98) & 63;
  acc ^= aux;
  int vector_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_49 > 50)
  {
    acc = ((acc + (vector_49 * 2)) + 5) & 127;
    aux ^= vector_49 & 15;
  }
  else
  {
    acc = ((acc - vector_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001893_9313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_68_1 = local_arr_1[aux_1 % 3];
  int cursor_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_68_2 * 2)) & 127;
  int residue_44_1 = 0;
  int residue_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_44_1 = ((residue_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_44_2 = ((residue_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_44_1) & 127;
    acc_2 = (acc_2 + residue_44_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_64_1 > 20)
  {
    acc_1 = ((acc_1 + (factor_64_1 * 2)) + 5) & 127;
    aux_1 ^= factor_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_64_2 > 20)
  {
    acc_2 = ((acc_2 + (factor_64_2 * 2)) + 5) & 127;
    aux_2 ^= factor_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_68_1 == cursor_68_2);
  assert(residue_44_1 == residue_44_2);
  assert(factor_64_1 == factor_64_2);
}

int fn_R001893_9313_5(int p0, int p1)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int cursor_68 = local_arr[aux % 3];
  acc = (acc + (cursor_68 * 2)) & 127;
  int residue_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_44 = ((residue_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_44) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_64 > 20)
  {
    acc = ((acc + (factor_64 * 2)) + 5) & 127;
    aux ^= factor_64 & 15;
  }
  else
  {
    acc = ((acc - factor_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001893_9313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int scale_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_24_1) & 63;
  aux_2 = (aux_2 + scale_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_93_1 = 0;
  int margin_93_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_93_1 = ((margin_93_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_93_2 = ((margin_93_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_93_1) & 127;
    acc_2 = (acc_2 + margin_93_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_24_1 == scale_24_2);
  assert(margin_93_1 == margin_93_2);
}

int fn_R001893_9313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int scale_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_24) & 63;
  acc ^= aux;
  int margin_93 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_93 = ((margin_93 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_93) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001893_9313_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_63_1 = local_arr_1[aux_1 % 3];
  int parity_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_63_2 * 2)) & 127;
  int tally_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_37_1) & 63;
  aux_2 = (aux_2 + tally_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_14_1 = 0;
  int offset_14_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    offset_14_1 = ((offset_14_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    offset_14_2 = ((offset_14_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + offset_14_1) & 127;
    acc_2 = (acc_2 + offset_14_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
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

  assert(parity_63_1 == parity_63_2);
  assert(tally_37_1 == tally_37_2);
  assert(offset_14_1 == offset_14_2);
}

int fn_R001893_9313_7(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_63 = local_arr[aux % 3];
  acc = (acc + (parity_63 * 2)) & 127;
  int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_37) & 63;
  acc ^= aux;
  int offset_14 = 0;
  for (int k = 0; k < 2; k++)
  {
    offset_14 = ((offset_14 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + offset_14) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001893_9313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int threshold_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_23_1 > 14)
  {
    acc_1 = ((acc_1 + (threshold_23_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_23_2 > 14)
  {
    acc_2 = ((acc_2 + (threshold_23_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_23_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_89_1) & 63;
  aux_2 = (aux_2 + phase_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_23_1 == threshold_23_2);
  assert(phase_89_1 == phase_89_2);
}

int fn_R001893_9313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int threshold_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_23 > 14)
  {
    acc = ((acc + (threshold_23 * 2)) + 5) & 127;
    aux ^= threshold_23 & 15;
  }
  else
  {
    acc = ((acc - threshold_23) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_89) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001893_9313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_13_1 = 0;
  int checksum_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    checksum_13_1 = ((checksum_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_13_2 = ((checksum_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_13_1) & 127;
    acc_2 = (acc_2 + checksum_13_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_13_1 == checksum_13_2);
}

int fn_R001893_9313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    checksum_13 = ((checksum_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_13) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001893_9313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_16_1 = local_arr_1[aux_1 % 3];
  int pivot_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_16_2 * 2)) & 127;
  int tracker_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_14_1) & 63;
  aux_2 = (aux_2 + tracker_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_99_1 > 47)
  {
    acc_1 = ((acc_1 + (scale_99_1 * 2)) + 5) & 127;
    aux_1 ^= scale_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_99_2 > 47)
  {
    acc_2 = ((acc_2 + (scale_99_2 * 2)) + 5) & 127;
    aux_2 ^= scale_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
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

  assert(pivot_16_1 == pivot_16_2);
  assert(tracker_14_1 == tracker_14_2);
  assert(scale_99_1 == scale_99_2);
}

int fn_R001893_9313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int pivot_16 = local_arr[aux % 3];
  acc = (acc + (pivot_16 * 2)) & 127;
  int tracker_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_14) & 63;
  acc ^= aux;
  int scale_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_99 > 47)
  {
    acc = ((acc + (scale_99 * 2)) + 5) & 127;
    aux ^= scale_99 & 15;
  }
  else
  {
    acc = ((acc - scale_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_85_1 > 47)
  {
    acc_1 = ((acc_1 + (factor_85_1 * 2)) + 5) & 127;
    aux_1 ^= factor_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_85_2 > 47)
  {
    acc_2 = ((acc_2 + (factor_85_2 * 2)) + 5) & 127;
    aux_2 ^= factor_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_85_1 == factor_85_2);
}

int fn_R001893_9313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_85 > 47)
  {
    acc = ((acc + (factor_85 * 2)) + 5) & 127;
    aux ^= factor_85 & 15;
  }
  else
  {
    acc = ((acc - factor_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001893_9313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quotient_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_60_1 > 42)
  {
    acc_1 = ((acc_1 + (quotient_60_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_60_2 > 42)
  {
    acc_2 = ((acc_2 + (quotient_60_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_67_1)
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

  switch (stride_67_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_60_1 == quotient_60_2);
  assert(stride_67_1 == stride_67_2);
}

int fn_R001893_9313_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quotient_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_60 > 42)
  {
    acc = ((acc + (quotient_60 * 2)) + 5) & 127;
    aux ^= quotient_60 & 15;
  }
  else
  {
    acc = ((acc - quotient_60) + 11) & 127;
    aux += 3;
  }
  int stride_67 = (aux + st.buffer[1]) & 3;
  switch (stride_67)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int scale_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_69_1)
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

  switch (scale_69_2)
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
  int cursor_82_1 = local_arr_1[aux_1 % 3];
  int cursor_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_82_2 * 2)) & 127;
  int anchor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_49_1 > 22)
  {
    acc_1 = ((acc_1 + (anchor_49_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_49_2 > 22)
  {
    acc_2 = ((acc_2 + (anchor_49_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_69_1 == scale_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_82_1 == cursor_82_2);
  assert(anchor_49_1 == anchor_49_2);
}

int fn_R001893_9313_13(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int scale_69 = (aux + st.buffer[1]) & 3;
  switch (scale_69)
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
  int cursor_82 = local_arr[aux % 3];
  acc = (acc + (cursor_82 * 2)) & 127;
  int anchor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_49 > 22)
  {
    acc = ((acc + (anchor_49 * 2)) + 5) & 127;
    aux ^= anchor_49 & 15;
  }
  else
  {
    acc = ((acc - anchor_49) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int stride_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_24_1 > 20)
  {
    acc_1 = ((acc_1 + (stride_24_1 * 2)) + 5) & 127;
    aux_1 ^= stride_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_24_2 > 20)
  {
    acc_2 = ((acc_2 + (stride_24_2 * 2)) + 5) & 127;
    aux_2 ^= stride_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_24_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_29_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_29_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_29_1) & 63;
  aux_2 = (aux_2 + mask_29_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_87_1 = 0;
  int pivot_87_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_87_1 = ((pivot_87_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_87_2 = ((pivot_87_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_87_1) & 127;
    acc_2 = (acc_2 + pivot_87_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_24_1 == stride_24_2);
  assert(mask_29_1 == mask_29_2);
  assert(pivot_87_1 == pivot_87_2);
}

int fn_R001893_9313_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int stride_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_24 > 20)
  {
    acc = ((acc + (stride_24 * 2)) + 5) & 127;
    aux ^= stride_24 & 15;
  }
  else
  {
    acc = ((acc - stride_24) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_29 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_29) & 63;
  acc ^= aux;
  int pivot_87 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_87 = ((pivot_87 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_87) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001893_9313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int sample_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_27_1)
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

  switch (sample_27_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_71_1 > 50)
  {
    acc_1 = ((acc_1 + (damping_71_1 * 2)) + 5) & 127;
    aux_1 ^= damping_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_71_2 > 50)
  {
    acc_2 = ((acc_2 + (damping_71_2 * 2)) + 5) & 127;
    aux_2 ^= damping_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_20_1 = 0;
  int phase_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    phase_20_1 = ((phase_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_20_2 = ((phase_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_20_1) & 127;
    acc_2 = (acc_2 + phase_20_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_27_1 == sample_27_2);
  assert(damping_71_1 == damping_71_2);
  assert(phase_20_1 == phase_20_2);
}

int fn_R001893_9313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int sample_27 = (aux + st.buffer[1]) & 3;
  switch (sample_27)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_71 > 50)
  {
    acc = ((acc + (damping_71 * 2)) + 5) & 127;
    aux ^= damping_71 & 15;
  }
  else
  {
    acc = ((acc - damping_71) + 11) & 127;
    aux += 3;
  }
  int phase_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    phase_20 = ((phase_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_20) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001893_9313_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_13_1)
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

  switch (mask_13_2)
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
  int offset_45_1 = local_arr_1[aux_1 % 3];
  int offset_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_45_2 * 2)) & 127;
  int accumulator_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_80_1) & 63;
  aux_2 = (aux_2 + accumulator_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_13_1 == mask_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_45_1 == offset_45_2);
  assert(accumulator_80_1 == accumulator_80_2);
}

int fn_R001893_9313_16(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_13 = (aux + st.buffer[1]) & 3;
  switch (mask_13)
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
  int offset_45 = local_arr[aux % 3];
  acc = (acc + (offset_45 * 2)) & 127;
  int accumulator_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_80) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001893_9313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_95_1 = local_arr_1[aux_1 % 3];
  int index_reg_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_95_2 * 2)) & 127;
  int threshold_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_96_1) & 63;
  aux_2 = (aux_2 + threshold_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
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

  assert(index_reg_95_1 == index_reg_95_2);
  assert(threshold_96_1 == threshold_96_2);
}

int fn_R001893_9313_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int index_reg_95 = local_arr[aux % 3];
  acc = (acc + (index_reg_95 * 2)) & 127;
  int threshold_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_96) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int coefficient_65_1 = 0;
  int coefficient_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_65_1 = ((coefficient_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_65_2 = ((coefficient_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_65_1) & 127;
    acc_2 = (acc_2 + coefficient_65_2) & 127;
  }

  int quantum_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_74_1)
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

  switch (quantum_74_2)
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
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_65_1 == coefficient_65_2);
  assert(quantum_74_1 == quantum_74_2);
}

int fn_R001893_9313_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int coefficient_65 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_65 = ((coefficient_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_65) & 127;
  }

  int quantum_74 = (aux + st.buffer[1]) & 3;
  switch (quantum_74)
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

void fn_R001893_9313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st_1 = {0};
  struct Transaction_R001893_9313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_40_1 > 23)
  {
    acc_1 = ((acc_1 + (quantum_40_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_40_2 > 23)
  {
    acc_2 = ((acc_2 + (quantum_40_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_28_1 = local_arr_1[aux_1 % 3];
  int quotient_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.fee == st_2.fee);
  assert(st_1.balance == st_2.balance);
  assert(st_1.status == st_2.status);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.rate == st_2.rate);
  assert(st_1.account_id == st_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_40_1 == quantum_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_28_1 == quotient_28_2);
}

int fn_R001893_9313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001893_9313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_40 > 23)
  {
    acc = ((acc + (quantum_40 * 2)) + 5) & 127;
    aux ^= quantum_40 & 15;
  }
  else
  {
    acc = ((acc - quantum_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_28 = local_arr[aux % 3];
  acc = (acc + (quotient_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001893_9313_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st_1 = {0};
  struct EventLog_R001893_9313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_35_1 = 0;
  int metric_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_35_1 = ((metric_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_35_2 = ((metric_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_35_1) & 127;
    acc_2 = (acc_2 + metric_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_35_1 == metric_35_2);
}

int fn_R001893_9313_20(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001893_9313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_35 = ((metric_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_35) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001893_0_1;
  int sec_r001893_0_2;
  int sec_r001893_1_1;
  int sec_r001893_1_2;
  int sec_r001893_2_1;
  int sec_r001893_2_2;
  int sec_r001893_3_1;
  int sec_r001893_3_2;
  int sec_r001893_4_1;
  int sec_r001893_4_2;
  int sec_r001893_5_1;
  int sec_r001893_5_2;
  int sec_r001893_6_1;
  int sec_r001893_6_2;
  int sec_r001893_7_1;
  int sec_r001893_7_2;
  int sec_r001893_8_1;
  int sec_r001893_8_2;
  int sec_r001893_9_1;
  int sec_r001893_9_2;
  int sec_r001893_10_1;
  int sec_r001893_10_2;
  int sec_r001893_11_1;
  int sec_r001893_11_2;
  int sec_r001893_12_1;
  int sec_r001893_12_2;
  int sec_r001893_13_1;
  int sec_r001893_13_2;
  int sec_r001893_14_1;
  int sec_r001893_14_2;
  int sec_r001893_15_1;
  int sec_r001893_15_2;
  int sec_r001893_16_1;
  int sec_r001893_16_2;
  int sec_r001893_17_1;
  int sec_r001893_17_2;
  int sec_r001893_18_1;
  int sec_r001893_18_2;
  int pub_r001893_0_1;
  int pub_r001893_0_2;
  int pub_r001893_1_1;
  int pub_r001893_1_2;
  int pub_r001893_2_1;
  int pub_r001893_2_2;
  int pub_r001893_3_1;
  int pub_r001893_3_2;
  int pub_r001893_4_1;
  int pub_r001893_4_2;
  int pub_r001893_5_1;
  int pub_r001893_5_2;
  int pub_r001893_6_1;
  int pub_r001893_6_2;
  int pub_r001893_7_1;
  int pub_r001893_7_2;
  int pub_r001893_8_1;
  int pub_r001893_8_2;
  int pub_r001893_9_1;
  int pub_r001893_9_2;
  int pub_r001893_10_1;
  int pub_r001893_10_2;
  int pub_r001893_11_1;
  int pub_r001893_11_2;
  int pub_r001893_12_1;
  int pub_r001893_12_2;
  int pub_r001893_13_1;
  int pub_r001893_13_2;
  int pub_r001893_14_1;
  int pub_r001893_14_2;
  int pub_r001893_15_1;
  int pub_r001893_15_2;
  int pub_r001893_16_1;
  int pub_r001893_16_2;
  int pub_r001893_17_1;
  int pub_r001893_17_2;
  int pub_r001893_18_1;
  int pub_r001893_18_2;
  int pub_r001893_19_1;
  int pub_r001893_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001893_0_1 >= (-100)) && (pub_r001893_0_1 <= 100));
  __CPROVER_assume((pub_r001893_0_2 >= (-100)) && (pub_r001893_0_2 <= 100));
  __CPROVER_assume((pub_r001893_1_1 >= (-100)) && (pub_r001893_1_1 <= 100));
  __CPROVER_assume((pub_r001893_1_2 >= (-100)) && (pub_r001893_1_2 <= 100));
  __CPROVER_assume((pub_r001893_2_1 >= (-100)) && (pub_r001893_2_1 <= 100));
  __CPROVER_assume((pub_r001893_2_2 >= (-100)) && (pub_r001893_2_2 <= 100));
  __CPROVER_assume((pub_r001893_3_1 >= (-100)) && (pub_r001893_3_1 <= 100));
  __CPROVER_assume((pub_r001893_3_2 >= (-100)) && (pub_r001893_3_2 <= 100));
  __CPROVER_assume((pub_r001893_4_1 >= (-100)) && (pub_r001893_4_1 <= 100));
  __CPROVER_assume((pub_r001893_4_2 >= (-100)) && (pub_r001893_4_2 <= 100));
  __CPROVER_assume((pub_r001893_5_1 >= (-100)) && (pub_r001893_5_1 <= 100));
  __CPROVER_assume((pub_r001893_5_2 >= (-100)) && (pub_r001893_5_2 <= 100));
  __CPROVER_assume((pub_r001893_6_1 >= (-100)) && (pub_r001893_6_1 <= 100));
  __CPROVER_assume((pub_r001893_6_2 >= (-100)) && (pub_r001893_6_2 <= 100));
  __CPROVER_assume((pub_r001893_7_1 >= (-100)) && (pub_r001893_7_1 <= 100));
  __CPROVER_assume((pub_r001893_7_2 >= (-100)) && (pub_r001893_7_2 <= 100));
  __CPROVER_assume((pub_r001893_8_1 >= (-100)) && (pub_r001893_8_1 <= 100));
  __CPROVER_assume((pub_r001893_8_2 >= (-100)) && (pub_r001893_8_2 <= 100));
  __CPROVER_assume((pub_r001893_9_1 >= (-100)) && (pub_r001893_9_1 <= 100));
  __CPROVER_assume((pub_r001893_9_2 >= (-100)) && (pub_r001893_9_2 <= 100));
  __CPROVER_assume((pub_r001893_10_1 >= (-100)) && (pub_r001893_10_1 <= 100));
  __CPROVER_assume((pub_r001893_10_2 >= (-100)) && (pub_r001893_10_2 <= 100));
  __CPROVER_assume((pub_r001893_11_1 >= (-100)) && (pub_r001893_11_1 <= 100));
  __CPROVER_assume((pub_r001893_11_2 >= (-100)) && (pub_r001893_11_2 <= 100));
  __CPROVER_assume((pub_r001893_12_1 >= (-100)) && (pub_r001893_12_1 <= 100));
  __CPROVER_assume((pub_r001893_12_2 >= (-100)) && (pub_r001893_12_2 <= 100));
  __CPROVER_assume((pub_r001893_13_1 >= (-100)) && (pub_r001893_13_1 <= 100));
  __CPROVER_assume((pub_r001893_13_2 >= (-100)) && (pub_r001893_13_2 <= 100));
  __CPROVER_assume((pub_r001893_14_1 >= (-100)) && (pub_r001893_14_1 <= 100));
  __CPROVER_assume((pub_r001893_14_2 >= (-100)) && (pub_r001893_14_2 <= 100));
  __CPROVER_assume((pub_r001893_15_1 >= (-100)) && (pub_r001893_15_1 <= 100));
  __CPROVER_assume((pub_r001893_15_2 >= (-100)) && (pub_r001893_15_2 <= 100));
  __CPROVER_assume((pub_r001893_16_1 >= (-100)) && (pub_r001893_16_1 <= 100));
  __CPROVER_assume((pub_r001893_16_2 >= (-100)) && (pub_r001893_16_2 <= 100));
  __CPROVER_assume((pub_r001893_17_1 >= (-100)) && (pub_r001893_17_1 <= 100));
  __CPROVER_assume((pub_r001893_17_2 >= (-100)) && (pub_r001893_17_2 <= 100));
  __CPROVER_assume((pub_r001893_18_1 >= (-100)) && (pub_r001893_18_1 <= 100));
  __CPROVER_assume((pub_r001893_18_2 >= (-100)) && (pub_r001893_18_2 <= 100));
  __CPROVER_assume((pub_r001893_19_1 >= (-100)) && (pub_r001893_19_1 <= 100));
  __CPROVER_assume((pub_r001893_19_2 >= (-100)) && (pub_r001893_19_2 <= 100));
  __CPROVER_assume((sec_r001893_0_1 >= 0) && (sec_r001893_0_1 <= 255));
  __CPROVER_assume((sec_r001893_0_2 >= 0) && (sec_r001893_0_2 <= 255));
  __CPROVER_assume((sec_r001893_1_1 >= 0) && (sec_r001893_1_1 <= 255));
  __CPROVER_assume((sec_r001893_1_2 >= 0) && (sec_r001893_1_2 <= 255));
  __CPROVER_assume((sec_r001893_2_1 >= 0) && (sec_r001893_2_1 <= 255));
  __CPROVER_assume((sec_r001893_2_2 >= 0) && (sec_r001893_2_2 <= 255));
  __CPROVER_assume((sec_r001893_3_1 >= 0) && (sec_r001893_3_1 <= 255));
  __CPROVER_assume((sec_r001893_3_2 >= 0) && (sec_r001893_3_2 <= 255));
  __CPROVER_assume((sec_r001893_4_1 >= 0) && (sec_r001893_4_1 <= 255));
  __CPROVER_assume((sec_r001893_4_2 >= 0) && (sec_r001893_4_2 <= 255));
  __CPROVER_assume((sec_r001893_5_1 >= 0) && (sec_r001893_5_1 <= 255));
  __CPROVER_assume((sec_r001893_5_2 >= 0) && (sec_r001893_5_2 <= 255));
  __CPROVER_assume((sec_r001893_6_1 >= 0) && (sec_r001893_6_1 <= 255));
  __CPROVER_assume((sec_r001893_6_2 >= 0) && (sec_r001893_6_2 <= 255));
  __CPROVER_assume((sec_r001893_7_1 >= 0) && (sec_r001893_7_1 <= 255));
  __CPROVER_assume((sec_r001893_7_2 >= 0) && (sec_r001893_7_2 <= 255));
  __CPROVER_assume((sec_r001893_8_1 >= 0) && (sec_r001893_8_1 <= 255));
  __CPROVER_assume((sec_r001893_8_2 >= 0) && (sec_r001893_8_2 <= 255));
  __CPROVER_assume((sec_r001893_9_1 >= 0) && (sec_r001893_9_1 <= 255));
  __CPROVER_assume((sec_r001893_9_2 >= 0) && (sec_r001893_9_2 <= 255));
  __CPROVER_assume((sec_r001893_10_1 >= 0) && (sec_r001893_10_1 <= 255));
  __CPROVER_assume((sec_r001893_10_2 >= 0) && (sec_r001893_10_2 <= 255));
  __CPROVER_assume((sec_r001893_11_1 >= 0) && (sec_r001893_11_1 <= 255));
  __CPROVER_assume((sec_r001893_11_2 >= 0) && (sec_r001893_11_2 <= 255));
  __CPROVER_assume((sec_r001893_12_1 >= 0) && (sec_r001893_12_1 <= 255));
  __CPROVER_assume((sec_r001893_12_2 >= 0) && (sec_r001893_12_2 <= 255));
  __CPROVER_assume((sec_r001893_13_1 >= 0) && (sec_r001893_13_1 <= 255));
  __CPROVER_assume((sec_r001893_13_2 >= 0) && (sec_r001893_13_2 <= 255));
  __CPROVER_assume((sec_r001893_14_1 >= 0) && (sec_r001893_14_1 <= 255));
  __CPROVER_assume((sec_r001893_14_2 >= 0) && (sec_r001893_14_2 <= 255));
  __CPROVER_assume((sec_r001893_15_1 >= 0) && (sec_r001893_15_1 <= 255));
  __CPROVER_assume((sec_r001893_15_2 >= 0) && (sec_r001893_15_2 <= 255));
  __CPROVER_assume((sec_r001893_16_1 >= 0) && (sec_r001893_16_1 <= 255));
  __CPROVER_assume((sec_r001893_16_2 >= 0) && (sec_r001893_16_2 <= 255));
  __CPROVER_assume((sec_r001893_17_1 >= 0) && (sec_r001893_17_1 <= 255));
  __CPROVER_assume((sec_r001893_17_2 >= 0) && (sec_r001893_17_2 <= 255));
  __CPROVER_assume((sec_r001893_18_1 >= 0) && (sec_r001893_18_1 <= 255));
  __CPROVER_assume((sec_r001893_18_2 >= 0) && (sec_r001893_18_2 <= 255));
  struct Transaction_R001893_9313_0 st_var_0_1 = {0};
  struct Transaction_R001893_9313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001893_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001893_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001893_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001893_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001893_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001893_0_2 + 7) & 15;
  struct EventLog_R001893_9313_1 st_var_1_1 = {0};
  struct EventLog_R001893_9313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001893_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001893_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001893_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001893_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001893_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001893_0_2 + 9) & 15;
  union TelemetryField_R001893_9313_0 u_var_1;
  union TelemetryField_R001893_9313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001893_9313_0(sec_r001893_0_1, sec_r001893_1_1);
  int helper_flow_0_2 = fn_R001893_9313_0(sec_r001893_0_2, sec_r001893_1_2);
  fn_R001893_9313_0_2(sec_r001893_0_1, sec_r001893_1_1, sec_r001893_0_2, sec_r001893_1_2);
  int helper_flow_1_1 = fn_R001893_9313_1(sec_r001893_1_1, pub_r001893_2_1, pub_r001893_3_1, pub_r001893_4_1);
  int helper_flow_1_2 = fn_R001893_9313_1(sec_r001893_1_2, pub_r001893_2_2, pub_r001893_3_2, pub_r001893_4_2);
  fn_R001893_9313_1_2(sec_r001893_1_1, pub_r001893_2_1, pub_r001893_3_1, pub_r001893_4_1, sec_r001893_1_2, pub_r001893_2_2, pub_r001893_3_2, pub_r001893_4_2);
  int helper_flow_2_1 = fn_R001893_9313_2(sec_r001893_2_1, pub_r001893_3_1, pub_r001893_4_1, pub_r001893_5_1);
  int helper_flow_2_2 = fn_R001893_9313_2(sec_r001893_2_2, pub_r001893_3_2, pub_r001893_4_2, pub_r001893_5_2);
  fn_R001893_9313_2_2(sec_r001893_2_1, pub_r001893_3_1, pub_r001893_4_1, pub_r001893_5_1, sec_r001893_2_2, pub_r001893_3_2, pub_r001893_4_2, pub_r001893_5_2);
  int helper_flow_3_1 = fn_R001893_9313_3(sec_r001893_3_1, pub_r001893_4_1, pub_r001893_5_1);
  int helper_flow_3_2 = fn_R001893_9313_3(sec_r001893_3_2, pub_r001893_4_2, pub_r001893_5_2);
  fn_R001893_9313_3_2(sec_r001893_3_1, pub_r001893_4_1, pub_r001893_5_1, sec_r001893_3_2, pub_r001893_4_2, pub_r001893_5_2);
  int helper_flow_4_1 = fn_R001893_9313_4(sec_r001893_4_1, pub_r001893_5_1, pub_r001893_6_1, pub_r001893_7_1, pub_r001893_8_1);
  int helper_flow_4_2 = fn_R001893_9313_4(sec_r001893_4_2, pub_r001893_5_2, pub_r001893_6_2, pub_r001893_7_2, pub_r001893_8_2);
  fn_R001893_9313_4_2(sec_r001893_4_1, pub_r001893_5_1, pub_r001893_6_1, pub_r001893_7_1, pub_r001893_8_1, sec_r001893_4_2, pub_r001893_5_2, pub_r001893_6_2, pub_r001893_7_2, pub_r001893_8_2);
  int stage_v_0_1 = (((sec_r001893_9_1 * 3) + pub_r001893_12_1) + 8) & 127;
  int stage_v_0_2 = (((sec_r001893_9_2 * 3) + pub_r001893_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001893_12_1 * 2) + 23) & 63;
  int stage_v_1_2 = ((pub_r001893_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001893_6_1 * 2) + 37) & 63;
  int stage_v_2_2 = ((pub_r001893_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001893_5_1 * 3) + pub_r001893_15_1) + 15) & 127;
  int stage_v_3_2 = (((sec_r001893_5_2 * 3) + pub_r001893_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001893_0_1 * 2) + 34) & 63;
  int stage_v_4_2 = ((pub_r001893_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001893_14_1 * 3) + pub_r001893_14_1) + 23) & 127;
  int stage_v_5_2 = (((sec_r001893_14_2 * 3) + pub_r001893_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((sec_r001893_1_1 * 3) + pub_r001893_17_1) + 10) & 127;
  int stage_v_6_2 = (((sec_r001893_1_2 * 3) + pub_r001893_17_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001893_19_1 * 2) + 24) & 63;
  int stage_v_7_2 = ((pub_r001893_19_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001893_6_1 * 2) + 6) & 63;
  int stage_v_8_2 = ((pub_r001893_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001893_6_1 * 2) + 18) & 63;
  int stage_v_9_2 = ((pub_r001893_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((pub_r001893_16_1 * 2) + 25) & 63;
  int stage_v_10_2 = ((pub_r001893_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (((sec_r001893_0_1 * 3) + pub_r001893_13_1) + 22) & 127;
  int stage_v_11_2 = (((sec_r001893_0_2 * 3) + pub_r001893_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = ((pub_r001893_18_1 * 2) + 21) & 63;
  int stage_v_12_2 = ((pub_r001893_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((helper_flow_3_1 * 3) + pub_r001893_14_1) + 24) & 127;
  int stage_v_13_2 = (((helper_flow_3_2 * 3) + pub_r001893_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001893_16_1 * 2) + 5) & 63;
  int stage_v_14_2 = ((pub_r001893_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001893_6_1 * 3) + pub_r001893_17_1) + 7) & 127;
  int stage_v_15_2 = (((sec_r001893_6_2 * 3) + pub_r001893_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001893_6_1 * 2) + 43) & 63;
  int stage_v_16_2 = ((pub_r001893_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (((helper_flow_4_1 * 3) + pub_r001893_14_1) + 35) & 127;
  int stage_v_17_2 = (((helper_flow_4_2 * 3) + pub_r001893_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_17_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_17_2 * 2)) & 255;
  int stage_v_18_1 = ((pub_r001893_14_1 * 2) + 5) & 63;
  int stage_v_18_2 = ((pub_r001893_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001893_4_1 * 3) + pub_r001893_3_1) + 29) & 127;
  int stage_v_19_2 = (((sec_r001893_4_2 * 3) + pub_r001893_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((sec_r001893_7_1 * 3) + pub_r001893_1_1) + 37) & 127;
  int stage_v_20_2 = (((sec_r001893_7_2 * 3) + pub_r001893_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001893_4_1 * 2) + 44) & 63;
  int stage_v_21_2 = ((pub_r001893_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001893_4_1 * 2) + 8) & 63;
  int stage_v_22_2 = ((pub_r001893_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_11_1 * 3) + pub_r001893_10_1) + 14) & 127;
  int stage_v_23_2 = (((stage_v_11_2 * 3) + pub_r001893_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((sec_r001893_2_1 * 3) + pub_r001893_2_1) + 13) & 127;
  int stage_v_24_2 = (((sec_r001893_2_2 * 3) + pub_r001893_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001893_4_1 * 3) + pub_r001893_17_1) + 28) & 127;
  int stage_v_25_2 = (((sec_r001893_4_2 * 3) + pub_r001893_17_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((stage_v_19_1 * 3) + pub_r001893_8_1) + 25) & 127;
  int stage_v_26_2 = (((stage_v_19_2 * 3) + pub_r001893_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001893_8_1 * 2) + 19) & 63;
  int stage_v_27_2 = ((pub_r001893_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((stage_v_26_1 * 3) + pub_r001893_5_1) + 16) & 127;
  int stage_v_28_2 = (((stage_v_26_2 * 3) + pub_r001893_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001893_2_1 * 3) + pub_r001893_5_1) + 23) & 127;
  int stage_v_29_2 = (((sec_r001893_2_2 * 3) + pub_r001893_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((sec_r001893_0_1 * 3) + pub_r001893_8_1) + 17) & 127;
  int stage_v_30_2 = (((sec_r001893_0_2 * 3) + pub_r001893_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001893_16_1 * 3) + pub_r001893_0_1) + 35) & 127;
  int stage_v_31_2 = (((sec_r001893_16_2 * 3) + pub_r001893_0_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001893_11_1 * 2) + 33) & 63;
  int stage_v_32_2 = ((pub_r001893_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_11_1 * 3) + pub_r001893_8_1) + 5) & 127;
  int stage_v_33_2 = (((stage_v_11_2 * 3) + pub_r001893_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001893_8_1 * 3) + pub_r001893_6_1) + 43) & 127;
  int stage_v_34_2 = (((sec_r001893_8_2 * 3) + pub_r001893_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((stage_v_34_1 * 3) + pub_r001893_10_1) + 15) & 127;
  int stage_v_35_2 = (((stage_v_34_2 * 3) + pub_r001893_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((stage_v_34_1 * 3) + pub_r001893_4_1) + 16) & 127;
  int stage_v_36_2 = (((stage_v_34_2 * 3) + pub_r001893_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = (((stage_v_26_1 * 3) + pub_r001893_11_1) + 39) & 127;
  int stage_v_37_2 = (((stage_v_26_2 * 3) + pub_r001893_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = (((stage_v_25_1 * 3) + pub_r001893_15_1) + 16) & 127;
  int stage_v_38_2 = (((stage_v_25_2 * 3) + pub_r001893_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = (((stage_v_31_1 * 3) + pub_r001893_6_1) + 27) & 127;
  int stage_v_39_2 = (((stage_v_31_2 * 3) + pub_r001893_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = (((stage_v_6_1 * 3) + pub_r001893_10_1) + 26) & 127;
  int stage_v_40_2 = (((stage_v_6_2 * 3) + pub_r001893_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001893_0_1 * 2) + 45) & 63;
  int stage_v_41_2 = ((pub_r001893_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001893_15_1 * 2) + 14) & 63;
  int stage_v_42_2 = ((pub_r001893_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = (((sec_r001893_12_1 * 3) + pub_r001893_3_1) + 3) & 127;
  int stage_v_43_2 = (((sec_r001893_12_2 * 3) + pub_r001893_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001893_6_1 * 2) + 11) & 63;
  int stage_v_44_2 = ((pub_r001893_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001893_17_1 * 2) + 18) & 63;
  int stage_v_45_2 = ((pub_r001893_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_23_1 * 3) + pub_r001893_11_1) + 6) & 127;
  int stage_v_46_2 = (((stage_v_23_2 * 3) + pub_r001893_11_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001893_8_1 * 2) + 9) & 63;
  int stage_v_47_2 = ((pub_r001893_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_43_1 * 3) + pub_r001893_2_1) + 40) & 127;
  int stage_v_48_2 = (((stage_v_43_2 * 3) + pub_r001893_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001893_11_1 * 2) + 49) & 63;
  int stage_v_49_2 = ((pub_r001893_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001893_15_1 * 2) + 43) & 63;
  int stage_v_50_2 = ((pub_r001893_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_11_1 * 3) + pub_r001893_10_1) + 6) & 127;
  int stage_v_51_2 = (((stage_v_11_2 * 3) + pub_r001893_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001893_12_1 * 2) + 26) & 63;
  int stage_v_52_2 = ((pub_r001893_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001893_16_1 * 2) + 19) & 63;
  int stage_v_53_2 = ((pub_r001893_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((helper_flow_2_1 * 3) + pub_r001893_0_1) + 31) & 127;
  int stage_v_54_2 = (((helper_flow_2_2 * 3) + pub_r001893_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001893_17_1 * 2) + 28) & 63;
  int stage_v_55_2 = ((pub_r001893_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001893_10_1 * 2) + 26) & 63;
  int stage_v_56_2 = ((pub_r001893_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((sec_r001893_16_1 * 3) + pub_r001893_12_1) + 44) & 127;
  int stage_v_57_2 = (((sec_r001893_16_2 * 3) + pub_r001893_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001893_7_1 * 3) + pub_r001893_15_1) + 20) & 127;
  int stage_v_58_2 = (((sec_r001893_7_2 * 3) + pub_r001893_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001893_13_1 * 2) + 16) & 63;
  int stage_v_59_2 = ((pub_r001893_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001893_0_1 * 2) + 35) & 63;
  int stage_v_60_2 = ((pub_r001893_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_34_1 * 3) + pub_r001893_0_1) + 42) & 127;
  int stage_v_61_2 = (((stage_v_34_2 * 3) + pub_r001893_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((stage_v_11_1 * 3) + pub_r001893_17_1) + 37) & 127;
  int stage_v_62_2 = (((stage_v_11_2 * 3) + pub_r001893_17_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = ((pub_r001893_7_1 * 2) + 26) & 63;
  int stage_v_63_2 = ((pub_r001893_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = (((stage_v_38_1 * 3) + pub_r001893_17_1) + 34) & 127;
  int stage_v_64_2 = (((stage_v_38_2 * 3) + pub_r001893_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = (((stage_v_35_1 * 3) + pub_r001893_5_1) + 40) & 127;
  int stage_v_65_2 = (((stage_v_35_2 * 3) + pub_r001893_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((stage_v_17_1 * 3) + pub_r001893_9_1) + 32) & 127;
  int stage_v_66_2 = (((stage_v_17_2 * 3) + pub_r001893_9_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((stage_v_11_1 * 3) + pub_r001893_7_1) + 42) & 127;
  int stage_v_67_2 = (((stage_v_11_2 * 3) + pub_r001893_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = ((pub_r001893_10_1 * 2) + 34) & 63;
  int stage_v_68_2 = ((pub_r001893_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001893_4_1 * 2) + 8) & 63;
  int stage_v_69_2 = ((pub_r001893_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001893_7_1 * 2) + 10) & 63;
  int stage_v_70_2 = ((pub_r001893_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001893_13_1 * 2) + 46) & 63;
  int stage_v_71_2 = ((pub_r001893_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_28_1 * 3) + pub_r001893_19_1) + 19) & 127;
  int stage_v_72_2 = (((stage_v_28_2 * 3) + pub_r001893_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_40_1 * 3) + pub_r001893_3_1) + 23) & 127;
  int stage_v_73_2 = (((stage_v_40_2 * 3) + pub_r001893_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((stage_v_54_1 * 3) + pub_r001893_12_1) + 45) & 127;
  int stage_v_74_2 = (((stage_v_54_2 * 3) + pub_r001893_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_3_1 * 3) + pub_r001893_5_1) + 6) & 127;
  int stage_v_75_2 = (((stage_v_3_2 * 3) + pub_r001893_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001893_15_1 * 2) + 15) & 63;
  int stage_v_76_2 = ((pub_r001893_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((sec_r001893_4_1 * 3) + pub_r001893_2_1) + 15) & 127;
  int stage_v_77_2 = (((sec_r001893_4_2 * 3) + pub_r001893_2_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = (((sec_r001893_13_1 * 3) + pub_r001893_3_1) + 34) & 127;
  int stage_v_78_2 = (((sec_r001893_13_2 * 3) + pub_r001893_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001893_9_1 * 2) + 18) & 63;
  int stage_v_79_2 = ((pub_r001893_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001893_3_1 * 2) + 41) & 63;
  int stage_v_80_2 = ((pub_r001893_3_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001893_17_1 * 3) + pub_r001893_0_1) + 34) & 127;
  int stage_v_81_2 = (((sec_r001893_17_2 * 3) + pub_r001893_0_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_48_1 * 3) + pub_r001893_15_1) + 43) & 127;
  int stage_v_82_2 = (((stage_v_48_2 * 3) + pub_r001893_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((stage_v_3_1 * 3) + pub_r001893_3_1) + 11) & 127;
  int stage_v_83_2 = (((stage_v_3_2 * 3) + pub_r001893_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((sec_r001893_2_1 * 3) + pub_r001893_12_1) + 32) & 127;
  int stage_v_84_2 = (((sec_r001893_2_2 * 3) + pub_r001893_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((sec_r001893_15_1 * 3) + pub_r001893_0_1) + 31) & 127;
  int stage_v_85_2 = (((sec_r001893_15_2 * 3) + pub_r001893_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = (((stage_v_24_1 * 3) + pub_r001893_3_1) + 40) & 127;
  int stage_v_86_2 = (((stage_v_24_2 * 3) + pub_r001893_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((sec_r001893_6_1 * 3) + pub_r001893_15_1) + 36) & 127;
  int stage_v_87_2 = (((sec_r001893_6_2 * 3) + pub_r001893_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = ((pub_r001893_18_1 * 2) + 16) & 63;
  int stage_v_88_2 = ((pub_r001893_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001893_12_1 * 2) + 18) & 63;
  int stage_v_89_2 = ((pub_r001893_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_31_1 * 3) + pub_r001893_4_1) + 36) & 127;
  int stage_v_90_2 = (((stage_v_31_2 * 3) + pub_r001893_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001893_5_1 * 2) + 20) & 63;
  int stage_v_91_2 = ((pub_r001893_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((helper_flow_3_1 * 3) + pub_r001893_11_1) + 19) & 127;
  int stage_v_92_2 = (((helper_flow_3_2 * 3) + pub_r001893_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = ((pub_r001893_8_1 * 2) + 49) & 63;
  int stage_v_93_2 = ((pub_r001893_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_31_1 * 3) + pub_r001893_10_1) + 22) & 127;
  int stage_v_94_2 = (((stage_v_31_2 * 3) + pub_r001893_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001893_16_1 * 2) + 22) & 63;
  int stage_v_95_2 = ((pub_r001893_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001893_12_1 * 2) + 23) & 63;
  int stage_v_96_2 = ((pub_r001893_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_87_1 * 3) + pub_r001893_18_1) + 40) & 127;
  int stage_v_97_2 = (((stage_v_87_2 * 3) + pub_r001893_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001893_10_1 * 2) + 22) & 63;
  int stage_v_98_2 = ((pub_r001893_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001893_11_1 * 2) + 34) & 63;
  int stage_v_99_2 = ((pub_r001893_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001893_18_1 * 2) + 13) & 63;
  int stage_v_100_2 = ((pub_r001893_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((sec_r001893_11_1 * 3) + pub_r001893_7_1) + 10) & 127;
  int stage_v_101_2 = (((sec_r001893_11_2 * 3) + pub_r001893_7_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = ((pub_r001893_4_1 * 2) + 32) & 63;
  int stage_v_102_2 = ((pub_r001893_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001893_18_1 * 2) + 25) & 63;
  int stage_v_103_2 = ((pub_r001893_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_26_1 * 3) + pub_r001893_19_1) + 18) & 127;
  int stage_v_104_2 = (((stage_v_26_2 * 3) + pub_r001893_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001893_16_1 * 2) + 37) & 63;
  int stage_v_105_2 = ((pub_r001893_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = (((sec_r001893_6_1 * 3) + pub_r001893_16_1) + 25) & 127;
  int stage_v_106_2 = (((sec_r001893_6_2 * 3) + pub_r001893_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = ((pub_r001893_3_1 * 2) + 21) & 63;
  int stage_v_107_2 = ((pub_r001893_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = (((stage_v_13_1 * 3) + pub_r001893_2_1) + 30) & 127;
  int stage_v_108_2 = (((stage_v_13_2 * 3) + pub_r001893_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001893_16_1 * 2) + 38) & 63;
  int stage_v_109_2 = ((pub_r001893_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((sec_r001893_16_1 * 3) + pub_r001893_6_1) + 38) & 127;
  int stage_v_110_2 = (((sec_r001893_16_2 * 3) + pub_r001893_6_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_13_1 * 3) + pub_r001893_19_1) + 37) & 127;
  int stage_v_111_2 = (((stage_v_13_2 * 3) + pub_r001893_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001893_7_1 * 2) + 13) & 63;
  int stage_v_112_2 = ((pub_r001893_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_82_1 * 3) + pub_r001893_3_1) + 17) & 127;
  int stage_v_113_2 = (((stage_v_82_2 * 3) + pub_r001893_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = (((stage_v_86_1 * 3) + pub_r001893_10_1) + 8) & 127;
  int stage_v_114_2 = (((stage_v_86_2 * 3) + pub_r001893_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = ((pub_r001893_12_1 * 2) + 38) & 63;
  int stage_v_115_2 = ((pub_r001893_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_0_1 * 3) + pub_r001893_1_1) + 33) & 127;
  int stage_v_116_2 = (((stage_v_0_2 * 3) + pub_r001893_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = ((pub_r001893_7_1 * 2) + 45) & 63;
  int stage_v_117_2 = ((pub_r001893_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001893_18_1 * 2) + 33) & 63;
  int stage_v_118_2 = ((pub_r001893_18_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_74_1 * 3) + pub_r001893_14_1) + 10) & 127;
  int stage_v_119_2 = (((stage_v_74_2 * 3) + pub_r001893_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = ((pub_r001893_18_1 * 2) + 30) & 63;
  int stage_v_120_2 = ((pub_r001893_18_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001893_14_1 * 2) + 16) & 63;
  int stage_v_121_2 = ((pub_r001893_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_34_1 * 3) + pub_r001893_17_1) + 35) & 127;
  int stage_v_122_2 = (((stage_v_34_2 * 3) + pub_r001893_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = ((pub_r001893_16_1 * 2) + 6) & 63;
  int stage_v_123_2 = ((pub_r001893_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = (((stage_v_28_1 * 3) + pub_r001893_14_1) + 41) & 127;
  int stage_v_124_2 = (((stage_v_28_2 * 3) + pub_r001893_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_13_1 * 3) + pub_r001893_13_1) + 4) & 127;
  int stage_v_125_2 = (((stage_v_13_2 * 3) + pub_r001893_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((sec_r001893_16_1 * 3) + pub_r001893_15_1) + 17) & 127;
  int stage_v_126_2 = (((sec_r001893_16_2 * 3) + pub_r001893_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001893_1_1 * 2) + 14) & 63;
  int stage_v_127_2 = ((pub_r001893_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001893_0_1 * 2) + 36) & 63;
  int stage_v_128_2 = ((pub_r001893_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001893_6_1 * 2) + 37) & 63;
  int stage_v_129_2 = ((pub_r001893_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001893_6_1 * 2) + 13) & 63;
  int stage_v_130_2 = ((pub_r001893_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001893_7_1 * 2) + 32) & 63;
  int stage_v_131_2 = ((pub_r001893_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((stage_v_37_1 * 3) + pub_r001893_7_1) + 13) & 127;
  int stage_v_132_2 = (((stage_v_37_2 * 3) + pub_r001893_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_48_1 * 3) + pub_r001893_18_1) + 36) & 127;
  int stage_v_133_2 = (((stage_v_48_2 * 3) + pub_r001893_18_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((helper_flow_0_1 * 3) + pub_r001893_19_1) + 24) & 127;
  int stage_v_134_2 = (((helper_flow_0_2 * 3) + pub_r001893_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_34_1 * 3) + pub_r001893_1_1) + 26) & 127;
  int stage_v_135_2 = (((stage_v_34_2 * 3) + pub_r001893_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((stage_v_3_1 * 3) + pub_r001893_7_1) + 41) & 127;
  int stage_v_136_2 = (((stage_v_3_2 * 3) + pub_r001893_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_29_1 * 3) + pub_r001893_0_1) + 11) & 127;
  int stage_v_137_2 = (((stage_v_29_2 * 3) + pub_r001893_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((sec_r001893_2_1 * 3) + pub_r001893_4_1) + 24) & 127;
  int stage_v_138_2 = (((sec_r001893_2_2 * 3) + pub_r001893_4_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = (((helper_flow_1_1 * 3) + pub_r001893_9_1) + 28) & 127;
  int stage_v_139_2 = (((helper_flow_1_2 * 3) + pub_r001893_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((helper_flow_4_1 * 3) + pub_r001893_4_1) + 31) & 127;
  int stage_v_140_2 = (((helper_flow_4_2 * 3) + pub_r001893_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((sec_r001893_1_1 * 3) + pub_r001893_0_1) + 14) & 127;
  int stage_v_141_2 = (((sec_r001893_1_2 * 3) + pub_r001893_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_113_1 * 3) + pub_r001893_8_1) + 23) & 127;
  int stage_v_142_2 = (((stage_v_113_2 * 3) + pub_r001893_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001893_11_1 * 2) + 30) & 63;
  int stage_v_143_2 = ((pub_r001893_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = ((pub_r001893_17_1 * 2) + 15) & 63;
  int stage_v_144_2 = ((pub_r001893_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_36_1 * 3) + pub_r001893_17_1) + 15) & 127;
  int stage_v_145_2 = (((stage_v_36_2 * 3) + pub_r001893_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001893_1_1 * 2) + 6) & 63;
  int stage_v_146_2 = ((pub_r001893_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001893_8_1 * 2) + 36) & 63;
  int stage_v_147_2 = ((pub_r001893_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_83_1 * 3) + pub_r001893_3_1) + 25) & 127;
  int stage_v_148_2 = (((stage_v_83_2 * 3) + pub_r001893_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_116_1 * 3) + pub_r001893_14_1) + 33) & 127;
  int stage_v_149_2 = (((stage_v_116_2 * 3) + pub_r001893_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001893_15_1 * 2) + 28) & 63;
  int stage_v_150_2 = ((pub_r001893_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_34_1 * 3) + pub_r001893_4_1) + 37) & 127;
  int stage_v_151_2 = (((stage_v_34_2 * 3) + pub_r001893_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_151_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_151_2 * 2)) & 255;
  int stage_v_152_1 = ((pub_r001893_7_1 * 2) + 34) & 63;
  int stage_v_152_2 = ((pub_r001893_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = (((stage_v_24_1 * 3) + pub_r001893_12_1) + 21) & 127;
  int stage_v_153_2 = (((stage_v_24_2 * 3) + pub_r001893_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((stage_v_94_1 * 3) + pub_r001893_19_1) + 21) & 127;
  int stage_v_154_2 = (((stage_v_94_2 * 3) + pub_r001893_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_51_1 * 3) + pub_r001893_11_1) + 9) & 127;
  int stage_v_155_2 = (((stage_v_51_2 * 3) + pub_r001893_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((sec_r001893_17_1 * 3) + pub_r001893_13_1) + 36) & 127;
  int stage_v_156_2 = (((sec_r001893_17_2 * 3) + pub_r001893_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001893_8_1 * 2) + 35) & 63;
  int stage_v_157_2 = ((pub_r001893_8_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_11_1 * 3) + pub_r001893_3_1) + 21) & 127;
  int stage_v_158_2 = (((stage_v_11_2 * 3) + pub_r001893_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001893_9_1 * 2) + 5) & 63;
  int stage_v_159_2 = ((pub_r001893_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001893_9_1 * 2) + 49) & 63;
  int stage_v_160_2 = ((pub_r001893_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((helper_flow_4_1 * 3) + pub_r001893_9_1) + 35) & 127;
  int stage_v_161_2 = (((helper_flow_4_2 * 3) + pub_r001893_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_54_1 * 3) + pub_r001893_19_1) + 27) & 127;
  int stage_v_162_2 = (((stage_v_54_2 * 3) + pub_r001893_19_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001893_12_1 * 2) + 43) & 63;
  int stage_v_163_2 = ((pub_r001893_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((sec_r001893_9_1 * 3) + pub_r001893_5_1) + 15) & 127;
  int stage_v_164_2 = (((sec_r001893_9_2 * 3) + pub_r001893_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((stage_v_94_1 * 3) + pub_r001893_13_1) + 41) & 127;
  int stage_v_165_2 = (((stage_v_94_2 * 3) + pub_r001893_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_15_1 * 3) + pub_r001893_8_1) + 44) & 127;
  int stage_v_166_2 = (((stage_v_15_2 * 3) + pub_r001893_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_148_1 * 3) + pub_r001893_4_1) + 27) & 127;
  int stage_v_167_2 = (((stage_v_148_2 * 3) + pub_r001893_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = ((pub_r001893_7_1 * 2) + 23) & 63;
  int stage_v_168_2 = ((pub_r001893_7_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001893_11_1 * 2) + 49) & 63;
  int stage_v_169_2 = ((pub_r001893_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = (((stage_v_3_1 * 3) + pub_r001893_2_1) + 45) & 127;
  int stage_v_170_2 = (((stage_v_3_2 * 3) + pub_r001893_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001893_15_1 * 2) + 17) & 63;
  int stage_v_171_2 = ((pub_r001893_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001893_3_1 * 2) + 14) & 63;
  int stage_v_172_2 = ((pub_r001893_3_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_106_1 * 3) + pub_r001893_2_1) + 14) & 127;
  int stage_v_173_2 = (((stage_v_106_2 * 3) + pub_r001893_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001893_1_1 * 2) + 40) & 63;
  int stage_v_174_2 = ((pub_r001893_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((sec_r001893_18_1 * 3) + pub_r001893_0_1) + 23) & 127;
  int stage_v_175_2 = (((sec_r001893_18_2 * 3) + pub_r001893_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_38_1 * 3) + pub_r001893_18_1) + 9) & 127;
  int stage_v_176_2 = (((stage_v_38_2 * 3) + pub_r001893_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001893_19_1 * 2) + 29) & 63;
  int stage_v_177_2 = ((pub_r001893_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001893_1_1 * 2) + 7) & 63;
  int stage_v_178_2 = ((pub_r001893_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001893_9_1 * 2) + 25) & 63;
  int stage_v_179_2 = ((pub_r001893_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001893_2_1 * 2) + 20) & 63;
  int stage_v_180_2 = ((pub_r001893_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_74_1 * 3) + pub_r001893_14_1) + 16) & 127;
  int stage_v_181_2 = (((stage_v_74_2 * 3) + pub_r001893_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_82_1 * 3) + pub_r001893_16_1) + 20) & 127;
  int stage_v_182_2 = (((stage_v_82_2 * 3) + pub_r001893_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = (((sec_r001893_6_1 * 3) + pub_r001893_7_1) + 39) & 127;
  int stage_v_183_2 = (((sec_r001893_6_2 * 3) + pub_r001893_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_87_1 * 3) + pub_r001893_7_1) + 21) & 127;
  int stage_v_184_2 = (((stage_v_87_2 * 3) + pub_r001893_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_40_1 * 3) + pub_r001893_12_1) + 32) & 127;
  int stage_v_185_2 = (((stage_v_40_2 * 3) + pub_r001893_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_173_1 * 3) + pub_r001893_11_1) + 45) & 127;
  int stage_v_186_2 = (((stage_v_173_2 * 3) + pub_r001893_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001893_3_1 * 2) + 36) & 63;
  int stage_v_187_2 = ((pub_r001893_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001893_15_1 * 2) + 42) & 63;
  int stage_v_188_2 = ((pub_r001893_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001893_8_1 * 2) + 7) & 63;
  int stage_v_189_2 = ((pub_r001893_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_92_1 * 3) + pub_r001893_18_1) + 3) & 127;
  int stage_v_190_2 = (((stage_v_92_2 * 3) + pub_r001893_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001893_1_1 * 2) + 19) & 63;
  int stage_v_191_2 = ((pub_r001893_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001893_5_1 * 2) + 41) & 63;
  int stage_v_192_2 = ((pub_r001893_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_62_1 * 3) + pub_r001893_11_1) + 19) & 127;
  int stage_v_193_2 = (((stage_v_62_2 * 3) + pub_r001893_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001893_6_1 * 2) + 22) & 63;
  int stage_v_194_2 = ((pub_r001893_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001893_9_1 * 2) + 31) & 63;
  int stage_v_195_2 = ((pub_r001893_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001893_12_1 * 2) + 9) & 63;
  int stage_v_196_2 = ((pub_r001893_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001893_13_1 * 2) + 20) & 63;
  int stage_v_197_2 = ((pub_r001893_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_17_1 * 3) + pub_r001893_0_1) + 31) & 127;
  int stage_v_198_2 = (((stage_v_17_2 * 3) + pub_r001893_0_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001893_7_1 * 2) + 16) & 63;
  int stage_v_199_2 = ((pub_r001893_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001893_12_1 * 2) + 14) & 63;
  int stage_v_200_2 = ((pub_r001893_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001893_2_1 * 2) + 12) & 63;
  int stage_v_201_2 = ((pub_r001893_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001893_15_1 * 2) + 32) & 63;
  int stage_v_202_2 = ((pub_r001893_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001893_19_1 * 2) + 46) & 63;
  int stage_v_203_2 = ((pub_r001893_19_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_158_1 * 3) + pub_r001893_2_1) + 20) & 127;
  int stage_v_204_2 = (((stage_v_158_2 * 3) + pub_r001893_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = ((pub_r001893_3_1 * 2) + 17) & 63;
  int stage_v_205_2 = ((pub_r001893_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001893_4_1 * 2) + 40) & 63;
  int stage_v_206_2 = ((pub_r001893_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001893_1_1 * 2) + 14) & 63;
  int stage_v_207_2 = ((pub_r001893_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = (((stage_v_181_1 * 3) + pub_r001893_3_1) + 23) & 127;
  int stage_v_208_2 = (((stage_v_181_2 * 3) + pub_r001893_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = ((pub_r001893_17_1 * 2) + 43) & 63;
  int stage_v_209_2 = ((pub_r001893_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = (((stage_v_87_1 * 3) + pub_r001893_12_1) + 43) & 127;
  int stage_v_210_2 = (((stage_v_87_2 * 3) + pub_r001893_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_72_1 * 3) + pub_r001893_10_1) + 36) & 127;
  int stage_v_211_2 = (((stage_v_72_2 * 3) + pub_r001893_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001893_14_1 * 2) + 11) & 63;
  int stage_v_212_2 = ((pub_r001893_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_116_1 * 3) + pub_r001893_12_1) + 43) & 127;
  int stage_v_213_2 = (((stage_v_116_2 * 3) + pub_r001893_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001893_1_1 * 2) + 14) & 63;
  int stage_v_214_2 = ((pub_r001893_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((sec_r001893_1_1 * 3) + pub_r001893_18_1) + 18) & 127;
  int stage_v_215_2 = (((sec_r001893_1_2 * 3) + pub_r001893_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = ((pub_r001893_7_1 * 2) + 24) & 63;
  int stage_v_216_2 = ((pub_r001893_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001893_19_1 * 2) + 47) & 63;
  int stage_v_217_2 = ((pub_r001893_19_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001893_14_1 * 2) + 29) & 63;
  int stage_v_218_2 = ((pub_r001893_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_170_1 * 3) + pub_r001893_8_1) + 37) & 127;
  int stage_v_219_2 = (((stage_v_170_2 * 3) + pub_r001893_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_208_1 * 3) + pub_r001893_1_1) + 43) & 127;
  int stage_v_220_2 = (((stage_v_208_2 * 3) + pub_r001893_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_145_1 * 3) + pub_r001893_3_1) + 44) & 127;
  int stage_v_221_2 = (((stage_v_145_2 * 3) + pub_r001893_3_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((sec_r001893_8_1 * 3) + pub_r001893_14_1) + 11) & 127;
  int stage_v_222_2 = (((sec_r001893_8_2 * 3) + pub_r001893_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001893_13_1 * 2) + 13) & 63;
  int stage_v_223_2 = ((pub_r001893_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_166_1 * 3) + pub_r001893_15_1) + 7) & 127;
  int stage_v_224_2 = (((stage_v_166_2 * 3) + pub_r001893_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = (((sec_r001893_16_1 * 3) + pub_r001893_15_1) + 32) & 127;
  int stage_v_225_2 = (((sec_r001893_16_2 * 3) + pub_r001893_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_165_1 * 3) + pub_r001893_9_1) + 43) & 127;
  int stage_v_226_2 = (((stage_v_165_2 * 3) + pub_r001893_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = ((pub_r001893_11_1 * 2) + 13) & 63;
  int stage_v_227_2 = ((pub_r001893_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_34_1 * 3) + pub_r001893_4_1) + 18) & 127;
  int stage_v_228_2 = (((stage_v_34_2 * 3) + pub_r001893_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_101_1 * 3) + pub_r001893_16_1) + 35) & 127;
  int stage_v_229_2 = (((stage_v_101_2 * 3) + pub_r001893_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((stage_v_57_1 * 3) + pub_r001893_16_1) + 19) & 127;
  int stage_v_230_2 = (((stage_v_57_2 * 3) + pub_r001893_16_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = ((pub_r001893_16_1 * 2) + 27) & 63;
  int stage_v_231_2 = ((pub_r001893_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = (((sec_r001893_12_1 * 3) + pub_r001893_8_1) + 38) & 127;
  int stage_v_232_2 = (((sec_r001893_12_2 * 3) + pub_r001893_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001893_6_1 * 2) + 38) & 63;
  int stage_v_233_2 = ((pub_r001893_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_48_1 * 3) + pub_r001893_2_1) + 29) & 127;
  int stage_v_234_2 = (((stage_v_48_2 * 3) + pub_r001893_2_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = ((pub_r001893_16_1 * 2) + 48) & 63;
  int stage_v_235_2 = ((pub_r001893_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001893_4_1 * 2) + 25) & 63;
  int stage_v_236_2 = ((pub_r001893_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = (((stage_v_220_1 * 3) + pub_r001893_9_1) + 15) & 127;
  int stage_v_237_2 = (((stage_v_220_2 * 3) + pub_r001893_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_114_1 * 3) + pub_r001893_11_1) + 42) & 127;
  int stage_v_238_2 = (((stage_v_114_2 * 3) + pub_r001893_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = ((pub_r001893_10_1 * 2) + 9) & 63;
  int stage_v_239_2 = ((pub_r001893_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001893_5_1 * 2) + 24) & 63;
  int stage_v_240_2 = ((pub_r001893_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_176_1 * 3) + pub_r001893_10_1) + 17) & 127;
  int stage_v_241_2 = (((stage_v_176_2 * 3) + pub_r001893_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_186_1 * 3) + pub_r001893_1_1) + 7) & 127;
  int stage_v_242_2 = (((stage_v_186_2 * 3) + pub_r001893_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_183_1 * 3) + pub_r001893_1_1) + 13) & 127;
  int stage_v_243_2 = (((stage_v_183_2 * 3) + pub_r001893_1_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001893_4_1 * 2) + 45) & 63;
  int stage_v_244_2 = ((pub_r001893_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = (((stage_v_137_1 * 3) + pub_r001893_4_1) + 36) & 127;
  int stage_v_245_2 = (((stage_v_137_2 * 3) + pub_r001893_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_184_1 * 3) + pub_r001893_14_1) + 11) & 127;
  int stage_v_246_2 = (((stage_v_184_2 * 3) + pub_r001893_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = ((pub_r001893_2_1 * 2) + 35) & 63;
  int stage_v_247_2 = ((pub_r001893_2_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001893_12_1 * 2) + 36) & 63;
  int stage_v_248_2 = ((pub_r001893_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001893_17_1 * 2) + 38) & 63;
  int stage_v_249_2 = ((pub_r001893_17_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001893_2_1 * 2) + 33) & 63;
  int stage_v_250_2 = ((pub_r001893_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001893_9_1 * 2) + 42) & 63;
  int stage_v_251_2 = ((pub_r001893_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((stage_v_3_1 * 3) + pub_r001893_5_1) + 18) & 127;
  int stage_v_252_2 = (((stage_v_3_2 * 3) + pub_r001893_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = ((pub_r001893_19_1 * 2) + 20) & 63;
  int stage_v_253_2 = ((pub_r001893_19_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_145_1 * 3) + pub_r001893_11_1) + 17) & 127;
  int stage_v_254_2 = (((stage_v_145_2 * 3) + pub_r001893_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((sec_r001893_8_1 * 3) + pub_r001893_1_1) + 38) & 127;
  int stage_v_255_2 = (((sec_r001893_8_2 * 3) + pub_r001893_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_77_1 * 3) + pub_r001893_14_1) + 18) & 127;
  int stage_v_256_2 = (((stage_v_77_2 * 3) + pub_r001893_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((stage_v_113_1 * 3) + pub_r001893_6_1) + 20) & 127;
  int stage_v_257_2 = (((stage_v_113_2 * 3) + pub_r001893_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = (((stage_v_215_1 * 3) + pub_r001893_3_1) + 7) & 127;
  int stage_v_258_2 = (((stage_v_215_2 * 3) + pub_r001893_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((stage_v_0_1 * 3) + pub_r001893_1_1) + 9) & 127;
  int stage_v_259_2 = (((stage_v_0_2 * 3) + pub_r001893_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = ((pub_r001893_2_1 * 2) + 46) & 63;
  int stage_v_260_2 = ((pub_r001893_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = (((sec_r001893_12_1 * 3) + pub_r001893_4_1) + 34) & 127;
  int stage_v_261_2 = (((sec_r001893_12_2 * 3) + pub_r001893_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = (((stage_v_162_1 * 3) + pub_r001893_1_1) + 28) & 127;
  int stage_v_262_2 = (((stage_v_162_2 * 3) + pub_r001893_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = ((pub_r001893_17_1 * 2) + 16) & 63;
  int stage_v_263_2 = ((pub_r001893_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_252_1 * 3) + pub_r001893_16_1) + 10) & 127;
  int stage_v_264_2 = (((stage_v_252_2 * 3) + pub_r001893_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001893_0_1 * 2) + 25) & 63;
  int stage_v_265_2 = ((pub_r001893_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_261_1 * 3) + pub_r001893_1_1) + 33) & 127;
  int stage_v_266_2 = (((stage_v_261_2 * 3) + pub_r001893_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_61_1 * 3) + pub_r001893_3_1) + 43) & 127;
  int stage_v_267_2 = (((stage_v_61_2 * 3) + pub_r001893_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001893_10_1 * 2) + 45) & 63;
  int stage_v_268_2 = ((pub_r001893_10_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = ((pub_r001893_6_1 * 2) + 24) & 63;
  int stage_v_269_2 = ((pub_r001893_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001893_14_1 * 2) + 31) & 63;
  int stage_v_270_2 = ((pub_r001893_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_167_1 * 3) + pub_r001893_1_1) + 12) & 127;
  int stage_v_271_2 = (((stage_v_167_2 * 3) + pub_r001893_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = (((stage_v_132_1 * 3) + pub_r001893_14_1) + 31) & 127;
  int stage_v_272_2 = (((stage_v_132_2 * 3) + pub_r001893_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_213_1 * 3) + pub_r001893_13_1) + 41) & 127;
  int stage_v_273_2 = (((stage_v_213_2 * 3) + pub_r001893_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_234_1 * 3) + pub_r001893_17_1) + 32) & 127;
  int stage_v_274_2 = (((stage_v_234_2 * 3) + pub_r001893_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_43_1 * 3) + pub_r001893_17_1) + 41) & 127;
  int stage_v_275_2 = (((stage_v_43_2 * 3) + pub_r001893_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = ((pub_r001893_2_1 * 2) + 32) & 63;
  int stage_v_276_2 = ((pub_r001893_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_111_1 * 3) + pub_r001893_8_1) + 4) & 127;
  int stage_v_277_2 = (((stage_v_111_2 * 3) + pub_r001893_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_126_1 * 3) + pub_r001893_4_1) + 6) & 127;
  int stage_v_278_2 = (((stage_v_126_2 * 3) + pub_r001893_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_48_1 * 3) + pub_r001893_0_1) + 27) & 127;
  int stage_v_279_2 = (((stage_v_48_2 * 3) + pub_r001893_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_257_1 * 3) + pub_r001893_14_1) + 31) & 127;
  int stage_v_280_2 = (((stage_v_257_2 * 3) + pub_r001893_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001893_4_1 * 2) + 35) & 63;
  int stage_v_281_2 = ((pub_r001893_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = ((pub_r001893_17_1 * 2) + 18) & 63;
  int stage_v_282_2 = ((pub_r001893_17_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001893_13_1 * 2) + 10) & 63;
  int stage_v_283_2 = ((pub_r001893_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001893_5_1 * 2) + 44) & 63;
  int stage_v_284_2 = ((pub_r001893_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001893_16_1 * 2) + 22) & 63;
  int stage_v_285_2 = ((pub_r001893_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001893_11_1 * 2) + 22) & 63;
  int stage_v_286_2 = ((pub_r001893_11_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = ((pub_r001893_10_1 * 2) + 5) & 63;
  int stage_v_287_2 = ((pub_r001893_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = ((pub_r001893_14_1 * 2) + 16) & 63;
  int stage_v_288_2 = ((pub_r001893_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_232_1 * 3) + pub_r001893_17_1) + 21) & 127;
  int stage_v_289_2 = (((stage_v_232_2 * 3) + pub_r001893_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_238_1 * 3) + pub_r001893_8_1) + 15) & 127;
  int stage_v_290_2 = (((stage_v_238_2 * 3) + pub_r001893_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_183_1 * 3) + pub_r001893_8_1) + 8) & 127;
  int stage_v_291_2 = (((stage_v_183_2 * 3) + pub_r001893_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_185_1 * 3) + pub_r001893_9_1) + 43) & 127;
  int stage_v_292_2 = (((stage_v_185_2 * 3) + pub_r001893_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_254_1 * 3) + pub_r001893_8_1) + 33) & 127;
  int stage_v_293_2 = (((stage_v_254_2 * 3) + pub_r001893_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001893_16_1 * 2) + 30) & 63;
  int stage_v_294_2 = ((pub_r001893_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_166_1 * 3) + pub_r001893_0_1) + 5) & 127;
  int stage_v_295_2 = (((stage_v_166_2 * 3) + pub_r001893_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((helper_flow_1_1 * 3) + pub_r001893_10_1) + 10) & 127;
  int stage_v_296_2 = (((helper_flow_1_2 * 3) + pub_r001893_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = (((stage_v_122_1 * 3) + pub_r001893_13_1) + 37) & 127;
  int stage_v_297_2 = (((stage_v_122_2 * 3) + pub_r001893_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_30_1 * 3) + pub_r001893_17_1) + 3) & 127;
  int stage_v_298_2 = (((stage_v_30_2 * 3) + pub_r001893_17_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_116_1 * 3) + pub_r001893_6_1) + 20) & 127;
  int stage_v_299_2 = (((stage_v_116_2 * 3) + pub_r001893_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001893_3_1 * 2) + 13) & 63;
  int stage_v_300_2 = ((pub_r001893_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((stage_v_245_1 * 3) + pub_r001893_14_1) + 34) & 127;
  int stage_v_301_2 = (((stage_v_245_2 * 3) + pub_r001893_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001893_7_1 * 2) + 26) & 63;
  int stage_v_302_2 = ((pub_r001893_7_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = ((pub_r001893_0_1 * 2) + 23) & 63;
  int stage_v_303_2 = ((pub_r001893_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = (((stage_v_111_1 * 3) + pub_r001893_18_1) + 31) & 127;
  int stage_v_304_2 = (((stage_v_111_2 * 3) + pub_r001893_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001893_10_1 * 2) + 21) & 63;
  int stage_v_305_2 = ((pub_r001893_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001893_2_1 * 2) + 36) & 63;
  int stage_v_306_2 = ((pub_r001893_2_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_153_1 * 3) + pub_r001893_13_1) + 10) & 127;
  int stage_v_307_2 = (((stage_v_153_2 * 3) + pub_r001893_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001893_11_1 * 2) + 23) & 63;
  int stage_v_308_2 = ((pub_r001893_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001893_13_1 * 2) + 46) & 63;
  int stage_v_309_2 = ((pub_r001893_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_140_1 * 3) + pub_r001893_14_1) + 22) & 127;
  int stage_v_310_2 = (((stage_v_140_2 * 3) + pub_r001893_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = ((pub_r001893_5_1 * 2) + 46) & 63;
  int stage_v_311_2 = ((pub_r001893_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_6_1 * 3) + pub_r001893_9_1) + 24) & 127;
  int stage_v_312_2 = (((stage_v_6_2 * 3) + pub_r001893_9_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((stage_v_224_1 * 3) + pub_r001893_8_1) + 12) & 127;
  int stage_v_313_2 = (((stage_v_224_2 * 3) + pub_r001893_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_0_1 * 3) + pub_r001893_18_1) + 12) & 127;
  int stage_v_314_2 = (((stage_v_0_2 * 3) + pub_r001893_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_81_1 * 3) + pub_r001893_0_1) + 39) & 127;
  int stage_v_315_2 = (((stage_v_81_2 * 3) + pub_r001893_0_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001893_19_1 * 2) + 28) & 63;
  int stage_v_316_2 = ((pub_r001893_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((stage_v_262_1 * 3) + pub_r001893_19_1) + 45) & 127;
  int stage_v_317_2 = (((stage_v_262_2 * 3) + pub_r001893_19_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001893_5_1 * 2) + 25) & 63;
  int stage_v_318_2 = ((pub_r001893_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_307_1 * 3) + pub_r001893_9_1) + 23) & 127;
  int stage_v_319_2 = (((stage_v_307_2 * 3) + pub_r001893_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001893_9_1 * 2) + 12) & 63;
  int stage_v_320_2 = ((pub_r001893_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = (((stage_v_119_1 * 3) + pub_r001893_17_1) + 45) & 127;
  int stage_v_321_2 = (((stage_v_119_2 * 3) + pub_r001893_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_279_1 * 3) + pub_r001893_15_1) + 33) & 127;
  int stage_v_322_2 = (((stage_v_279_2 * 3) + pub_r001893_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001893_19_1 * 2) + 18) & 63;
  int stage_v_323_2 = ((pub_r001893_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001893_10_1 * 2) + 38) & 63;
  int stage_v_324_2 = ((pub_r001893_10_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((sec_r001893_13_1 * 3) + pub_r001893_19_1) + 30) & 127;
  int stage_v_325_2 = (((sec_r001893_13_2 * 3) + pub_r001893_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001893_13_1 * 2) + 6) & 63;
  int stage_v_326_2 = ((pub_r001893_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001893_1_1 * 2) + 37) & 63;
  int stage_v_327_2 = ((pub_r001893_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((helper_flow_2_1 * 3) + pub_r001893_16_1) + 26) & 127;
  int stage_v_328_2 = (((helper_flow_2_2 * 3) + pub_r001893_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_274_1 * 3) + pub_r001893_4_1) + 3) & 127;
  int stage_v_329_2 = (((stage_v_274_2 * 3) + pub_r001893_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_295_1 * 3) + pub_r001893_1_1) + 19) & 127;
  int stage_v_330_2 = (((stage_v_295_2 * 3) + pub_r001893_1_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_228_1 * 3) + pub_r001893_12_1) + 23) & 127;
  int stage_v_331_2 = (((stage_v_228_2 * 3) + pub_r001893_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001893_9_1 * 2) + 20) & 63;
  int stage_v_332_2 = ((pub_r001893_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = (((stage_v_6_1 * 3) + pub_r001893_12_1) + 43) & 127;
  int stage_v_333_2 = (((stage_v_6_2 * 3) + pub_r001893_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001893_5_1 * 2) + 20) & 63;
  int stage_v_334_2 = ((pub_r001893_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_66_1 * 3) + pub_r001893_9_1) + 35) & 127;
  int stage_v_335_2 = (((stage_v_66_2 * 3) + pub_r001893_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_92_1 * 3) + pub_r001893_13_1) + 11) & 127;
  int stage_v_336_2 = (((stage_v_92_2 * 3) + pub_r001893_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = (((stage_v_87_1 * 3) + pub_r001893_18_1) + 19) & 127;
  int stage_v_337_2 = (((stage_v_87_2 * 3) + pub_r001893_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = (((stage_v_228_1 * 3) + pub_r001893_4_1) + 27) & 127;
  int stage_v_338_2 = (((stage_v_228_2 * 3) + pub_r001893_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001893_15_1 * 2) + 22) & 63;
  int stage_v_339_2 = ((pub_r001893_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_278_1 * 3) + pub_r001893_7_1) + 24) & 127;
  int stage_v_340_2 = (((stage_v_278_2 * 3) + pub_r001893_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001893_4_1 * 2) + 31) & 63;
  int stage_v_341_2 = ((pub_r001893_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = (((sec_r001893_10_1 * 3) + pub_r001893_2_1) + 3) & 127;
  int stage_v_342_2 = (((sec_r001893_10_2 * 3) + pub_r001893_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_113_1 * 3) + pub_r001893_1_1) + 6) & 127;
  int stage_v_343_2 = (((stage_v_113_2 * 3) + pub_r001893_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_92_1 * 3) + pub_r001893_3_1) + 29) & 127;
  int stage_v_344_2 = (((stage_v_92_2 * 3) + pub_r001893_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001893_4_1 * 2) + 7) & 63;
  int stage_v_345_2 = ((pub_r001893_4_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_141_1 * 3) + pub_r001893_12_1) + 33) & 127;
  int stage_v_346_2 = (((stage_v_141_2 * 3) + pub_r001893_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((stage_v_87_1 * 3) + pub_r001893_15_1) + 3) & 127;
  int stage_v_347_2 = (((stage_v_87_2 * 3) + pub_r001893_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001893_5_1 * 2) + 39) & 63;
  int stage_v_348_2 = ((pub_r001893_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = ((pub_r001893_6_1 * 2) + 38) & 63;
  int stage_v_349_2 = ((pub_r001893_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_252_1 * 3) + pub_r001893_10_1) + 16) & 127;
  int stage_v_350_2 = (((stage_v_252_2 * 3) + pub_r001893_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_166_1 * 3) + pub_r001893_16_1) + 8) & 127;
  int stage_v_351_2 = (((stage_v_166_2 * 3) + pub_r001893_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = (((stage_v_267_1 * 3) + pub_r001893_0_1) + 26) & 127;
  int stage_v_352_2 = (((stage_v_267_2 * 3) + pub_r001893_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((sec_r001893_5_1 * 3) + pub_r001893_13_1) + 16) & 127;
  int stage_v_353_2 = (((sec_r001893_5_2 * 3) + pub_r001893_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_149_1 * 3) + pub_r001893_0_1) + 45) & 127;
  int stage_v_354_2 = (((stage_v_149_2 * 3) + pub_r001893_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_296_1 * 3) + pub_r001893_3_1) + 19) & 127;
  int stage_v_355_2 = (((stage_v_296_2 * 3) + pub_r001893_3_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001893_19_1 * 2) + 29) & 63;
  int stage_v_356_2 = ((pub_r001893_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_156_1 * 3) + pub_r001893_15_1) + 10) & 127;
  int stage_v_357_2 = (((stage_v_156_2 * 3) + pub_r001893_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_183_1 * 3) + pub_r001893_14_1) + 32) & 127;
  int stage_v_358_2 = (((stage_v_183_2 * 3) + pub_r001893_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001893_12_1 * 2) + 15) & 63;
  int stage_v_359_2 = ((pub_r001893_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_54_1 * 3) + pub_r001893_4_1) + 12) & 127;
  int stage_v_360_2 = (((stage_v_54_2 * 3) + pub_r001893_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_343_1 * 3) + pub_r001893_11_1) + 19) & 127;
  int stage_v_361_2 = (((stage_v_343_2 * 3) + pub_r001893_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = ((pub_r001893_2_1 * 2) + 28) & 63;
  int stage_v_362_2 = ((pub_r001893_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_40_1 * 3) + pub_r001893_8_1) + 8) & 127;
  int stage_v_363_2 = (((stage_v_40_2 * 3) + pub_r001893_8_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_64_1 * 3) + pub_r001893_13_1) + 41) & 127;
  int stage_v_364_2 = (((stage_v_64_2 * 3) + pub_r001893_13_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_5_1 * 3) + pub_r001893_3_1) + 43) & 127;
  int stage_v_365_2 = (((stage_v_5_2 * 3) + pub_r001893_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((stage_v_243_1 * 3) + pub_r001893_10_1) + 24) & 127;
  int stage_v_366_2 = (((stage_v_243_2 * 3) + pub_r001893_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((stage_v_204_1 * 3) + pub_r001893_18_1) + 22) & 127;
  int stage_v_367_2 = (((stage_v_204_2 * 3) + pub_r001893_18_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001893_12_1 * 2) + 10) & 63;
  int stage_v_368_2 = ((pub_r001893_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001893_6_1 * 2) + 28) & 63;
  int stage_v_369_2 = ((pub_r001893_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_145_1 * 3) + pub_r001893_3_1) + 7) & 127;
  int stage_v_370_2 = (((stage_v_145_2 * 3) + pub_r001893_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_353_1 * 3) + pub_r001893_8_1) + 31) & 127;
  int stage_v_371_2 = (((stage_v_353_2 * 3) + pub_r001893_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001893_5_1 * 2) + 32) & 63;
  int stage_v_372_2 = ((pub_r001893_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001893_9_1 * 2) + 35) & 63;
  int stage_v_373_2 = ((pub_r001893_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = (((stage_v_28_1 * 3) + pub_r001893_19_1) + 31) & 127;
  int stage_v_374_2 = (((stage_v_28_2 * 3) + pub_r001893_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = ((pub_r001893_19_1 * 2) + 30) & 63;
  int stage_v_375_2 = ((pub_r001893_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001893_13_1 * 2) + 25) & 63;
  int stage_v_376_2 = ((pub_r001893_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_190_1 * 3) + pub_r001893_11_1) + 4) & 127;
  int stage_v_377_2 = (((stage_v_190_2 * 3) + pub_r001893_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = (((stage_v_84_1 * 3) + pub_r001893_13_1) + 44) & 127;
  int stage_v_378_2 = (((stage_v_84_2 * 3) + pub_r001893_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_354_1 * 3) + pub_r001893_15_1) + 43) & 127;
  int stage_v_379_2 = (((stage_v_354_2 * 3) + pub_r001893_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_181_1 * 3) + pub_r001893_7_1) + 6) & 127;
  int stage_v_380_2 = (((stage_v_181_2 * 3) + pub_r001893_7_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_371_1 * 3) + pub_r001893_4_1) + 3) & 127;
  int stage_v_381_2 = (((stage_v_371_2 * 3) + pub_r001893_4_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001893_13_1 * 2) + 40) & 63;
  int stage_v_382_2 = ((pub_r001893_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((stage_v_175_1 * 3) + pub_r001893_14_1) + 22) & 127;
  int stage_v_383_2 = (((stage_v_175_2 * 3) + pub_r001893_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_364_1 * 3) + pub_r001893_5_1) + 3) & 127;
  int stage_v_384_2 = (((stage_v_364_2 * 3) + pub_r001893_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001893_13_1 * 2) + 21) & 63;
  int stage_v_385_2 = ((pub_r001893_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001893_1_1 * 2) + 11) & 63;
  int stage_v_386_2 = ((pub_r001893_1_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_234_1 * 3) + pub_r001893_2_1) + 22) & 127;
  int stage_v_387_2 = (((stage_v_234_2 * 3) + pub_r001893_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001893_14_1 * 2) + 40) & 63;
  int stage_v_388_2 = ((pub_r001893_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_142_1 * 3) + pub_r001893_1_1) + 6) & 127;
  int stage_v_389_2 = (((stage_v_142_2 * 3) + pub_r001893_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001893_13_1 * 2) + 28) & 63;
  int stage_v_390_2 = ((pub_r001893_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_322_1 * 3) + pub_r001893_1_1) + 35) & 127;
  int stage_v_391_2 = (((stage_v_322_2 * 3) + pub_r001893_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_77_1 * 3) + pub_r001893_4_1) + 38) & 127;
  int stage_v_392_2 = (((stage_v_77_2 * 3) + pub_r001893_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_336_1 * 3) + pub_r001893_18_1) + 44) & 127;
  int stage_v_393_2 = (((stage_v_336_2 * 3) + pub_r001893_18_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_64_1 * 3) + pub_r001893_6_1) + 29) & 127;
  int stage_v_394_2 = (((stage_v_64_2 * 3) + pub_r001893_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001893_15_1 * 2) + 24) & 63;
  int stage_v_395_2 = ((pub_r001893_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = ((pub_r001893_5_1 * 2) + 46) & 63;
  int stage_v_396_2 = ((pub_r001893_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001893_6_1 * 2) + 49) & 63;
  int stage_v_397_2 = ((pub_r001893_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001893_5_1 * 2) + 31) & 63;
  int stage_v_398_2 = ((pub_r001893_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001893_10_1 * 2) + 30) & 63;
  int stage_v_399_2 = ((pub_r001893_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = (((stage_v_307_1 * 3) + pub_r001893_19_1) + 34) & 127;
  int stage_v_400_2 = (((stage_v_307_2 * 3) + pub_r001893_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_400_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_400_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_400_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_400_2 * 2)) & 255;
  int stage_v_401_1 = ((pub_r001893_15_1 * 2) + 20) & 63;
  int stage_v_401_2 = ((pub_r001893_15_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_116_1 * 3) + pub_r001893_11_1) + 20) & 127;
  int stage_v_402_2 = (((stage_v_116_2 * 3) + pub_r001893_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_402_1 * 3) + pub_r001893_12_1) + 9) & 127;
  int stage_v_403_2 = (((stage_v_402_2 * 3) + pub_r001893_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((sec_r001893_5_1 * 3) + pub_r001893_0_1) + 3) & 127;
  int stage_v_404_2 = (((sec_r001893_5_2 * 3) + pub_r001893_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001893_1_1 * 2) + 44) & 63;
  int stage_v_405_2 = ((pub_r001893_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001893_9_1 * 2) + 43) & 63;
  int stage_v_406_2 = ((pub_r001893_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001893_7_1 * 2) + 10) & 63;
  int stage_v_407_2 = ((pub_r001893_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001893_4_1 * 2) + 5) & 63;
  int stage_v_408_2 = ((pub_r001893_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001893_14_1 * 2) + 47) & 63;
  int stage_v_409_2 = ((pub_r001893_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = (((stage_v_226_1 * 3) + pub_r001893_13_1) + 22) & 127;
  int stage_v_410_2 = (((stage_v_226_2 * 3) + pub_r001893_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_410_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_410_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_410_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_410_2 * 2)) & 255;
  int stage_v_411_1 = ((pub_r001893_17_1 * 2) + 28) & 63;
  int stage_v_411_2 = ((pub_r001893_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = ((pub_r001893_7_1 * 2) + 37) & 63;
  int stage_v_412_2 = ((pub_r001893_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_278_1 * 3) + pub_r001893_18_1) + 18) & 127;
  int stage_v_413_2 = (((stage_v_278_2 * 3) + pub_r001893_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_122_1 * 3) + pub_r001893_7_1) + 44) & 127;
  int stage_v_414_2 = (((stage_v_122_2 * 3) + pub_r001893_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = (((stage_v_296_1 * 3) + pub_r001893_11_1) + 29) & 127;
  int stage_v_415_2 = (((stage_v_296_2 * 3) + pub_r001893_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001893_4_1 * 2) + 14) & 63;
  int stage_v_416_2 = ((pub_r001893_4_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_378_1 * 3) + pub_r001893_16_1) + 30) & 127;
  int stage_v_417_2 = (((stage_v_378_2 * 3) + pub_r001893_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = (((stage_v_11_1 * 3) + pub_r001893_4_1) + 22) & 127;
  int stage_v_418_2 = (((stage_v_11_2 * 3) + pub_r001893_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_418_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_418_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_418_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_418_2 * 2)) & 255;
  int stage_v_419_1 = ((pub_r001893_10_1 * 2) + 39) & 63;
  int stage_v_419_2 = ((pub_r001893_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_43_1 * 3) + pub_r001893_17_1) + 6) & 127;
  int stage_v_420_2 = (((stage_v_43_2 * 3) + pub_r001893_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = (((stage_v_400_1 * 3) + pub_r001893_7_1) + 40) & 127;
  int stage_v_421_2 = (((stage_v_400_2 * 3) + pub_r001893_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = (((stage_v_312_1 * 3) + pub_r001893_17_1) + 7) & 127;
  int stage_v_422_2 = (((stage_v_312_2 * 3) + pub_r001893_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_422_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_422_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_422_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_422_2 * 2)) & 255;
  int stage_v_423_1 = (((stage_v_43_1 * 3) + pub_r001893_3_1) + 25) & 127;
  int stage_v_423_2 = (((stage_v_43_2 * 3) + pub_r001893_3_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001893_15_1 * 2) + 27) & 63;
  int stage_v_424_2 = ((pub_r001893_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001893_8_1 * 2) + 24) & 63;
  int stage_v_425_2 = ((pub_r001893_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_322_1 * 3) + pub_r001893_6_1) + 25) & 127;
  int stage_v_426_2 = (((stage_v_322_2 * 3) + pub_r001893_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_422_1 * 3) + pub_r001893_0_1) + 28) & 127;
  int stage_v_427_2 = (((stage_v_422_2 * 3) + pub_r001893_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_423_1 * 3) + pub_r001893_9_1) + 37) & 127;
  int stage_v_428_2 = (((stage_v_423_2 * 3) + pub_r001893_9_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_335_1 * 3) + pub_r001893_5_1) + 22) & 127;
  int stage_v_429_2 = (((stage_v_335_2 * 3) + pub_r001893_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_125_1 * 3) + pub_r001893_9_1) + 44) & 127;
  int stage_v_430_2 = (((stage_v_125_2 * 3) + pub_r001893_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = (((stage_v_222_1 * 3) + pub_r001893_10_1) + 42) & 127;
  int stage_v_431_2 = (((stage_v_222_2 * 3) + pub_r001893_10_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_272_1 * 3) + pub_r001893_4_1) + 9) & 127;
  int stage_v_432_2 = (((stage_v_272_2 * 3) + pub_r001893_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_17_1 * 3) + pub_r001893_6_1) + 21) & 127;
  int stage_v_433_2 = (((stage_v_17_2 * 3) + pub_r001893_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = (((stage_v_166_1 * 3) + pub_r001893_10_1) + 6) & 127;
  int stage_v_434_2 = (((stage_v_166_2 * 3) + pub_r001893_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = ((pub_r001893_4_1 * 2) + 24) & 63;
  int stage_v_435_2 = ((pub_r001893_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = ((pub_r001893_19_1 * 2) + 25) & 63;
  int stage_v_436_2 = ((pub_r001893_19_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_97_1 * 3) + pub_r001893_10_1) + 5) & 127;
  int stage_v_437_2 = (((stage_v_97_2 * 3) + pub_r001893_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001893_8_1 * 2) + 31) & 63;
  int stage_v_438_2 = ((pub_r001893_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_11_1 * 3) + pub_r001893_4_1) + 42) & 127;
  int stage_v_439_2 = (((stage_v_11_2 * 3) + pub_r001893_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_297_1 * 3) + pub_r001893_9_1) + 20) & 127;
  int stage_v_440_2 = (((stage_v_297_2 * 3) + pub_r001893_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_37_1 * 3) + pub_r001893_11_1) + 7) & 127;
  int stage_v_441_2 = (((stage_v_37_2 * 3) + pub_r001893_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((stage_v_61_1 * 3) + pub_r001893_15_1) + 45) & 127;
  int stage_v_442_2 = (((stage_v_61_2 * 3) + pub_r001893_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_290_1 * 3) + pub_r001893_12_1) + 18) & 127;
  int stage_v_443_2 = (((stage_v_290_2 * 3) + pub_r001893_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001893_16_1 * 2) + 15) & 63;
  int stage_v_444_2 = ((pub_r001893_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((stage_v_252_1 * 3) + pub_r001893_11_1) + 35) & 127;
  int stage_v_445_2 = (((stage_v_252_2 * 3) + pub_r001893_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = ((pub_r001893_11_1 * 2) + 11) & 63;
  int stage_v_446_2 = ((pub_r001893_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = (((stage_v_15_1 * 3) + pub_r001893_4_1) + 22) & 127;
  int stage_v_447_2 = (((stage_v_15_2 * 3) + pub_r001893_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_38_1 * 3) + pub_r001893_2_1) + 20) & 127;
  int stage_v_448_2 = (((stage_v_38_2 * 3) + pub_r001893_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = (((stage_v_433_1 * 3) + pub_r001893_1_1) + 29) & 127;
  int stage_v_449_2 = (((stage_v_433_2 * 3) + pub_r001893_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001893_5_1 * 2) + 35) & 63;
  int stage_v_450_2 = ((pub_r001893_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_299_1 * 3) + pub_r001893_2_1) + 7) & 127;
  int stage_v_451_2 = (((stage_v_299_2 * 3) + pub_r001893_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_417_1 * 3) + pub_r001893_13_1) + 9) & 127;
  int stage_v_452_2 = (((stage_v_417_2 * 3) + pub_r001893_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_441_1 * 3) + pub_r001893_5_1) + 42) & 127;
  int stage_v_453_2 = (((stage_v_441_2 * 3) + pub_r001893_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = (((stage_v_441_1 * 3) + pub_r001893_4_1) + 31) & 127;
  int stage_v_454_2 = (((stage_v_441_2 * 3) + pub_r001893_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = ((pub_r001893_12_1 * 2) + 22) & 63;
  int stage_v_455_2 = ((pub_r001893_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_434_1 * 3) + pub_r001893_17_1) + 41) & 127;
  int stage_v_456_2 = (((stage_v_434_2 * 3) + pub_r001893_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = (((stage_v_5_1 * 3) + pub_r001893_10_1) + 41) & 127;
  int stage_v_457_2 = (((stage_v_5_2 * 3) + pub_r001893_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_457_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_457_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_457_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_457_2 * 2)) & 255;
  int stage_v_458_1 = (((stage_v_422_1 * 3) + pub_r001893_14_1) + 44) & 127;
  int stage_v_458_2 = (((stage_v_422_2 * 3) + pub_r001893_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = (((stage_v_228_1 * 3) + pub_r001893_5_1) + 37) & 127;
  int stage_v_459_2 = (((stage_v_228_2 * 3) + pub_r001893_5_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = (((stage_v_310_1 * 3) + pub_r001893_7_1) + 28) & 127;
  int stage_v_460_2 = (((stage_v_310_2 * 3) + pub_r001893_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = (((stage_v_135_1 * 3) + pub_r001893_0_1) + 27) & 127;
  int stage_v_461_2 = (((stage_v_135_2 * 3) + pub_r001893_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = (((stage_v_428_1 * 3) + pub_r001893_18_1) + 24) & 127;
  int stage_v_462_2 = (((stage_v_428_2 * 3) + pub_r001893_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((stage_v_198_1 * 3) + pub_r001893_13_1) + 23) & 127;
  int stage_v_463_2 = (((stage_v_198_2 * 3) + pub_r001893_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((stage_v_443_1 * 3) + pub_r001893_1_1) + 16) & 127;
  int stage_v_464_2 = (((stage_v_443_2 * 3) + pub_r001893_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = (((stage_v_380_1 * 3) + pub_r001893_17_1) + 4) & 127;
  int stage_v_465_2 = (((stage_v_380_2 * 3) + pub_r001893_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_465_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_465_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_465_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_465_2 * 2)) & 255;
  int stage_v_466_1 = (((stage_v_13_1 * 3) + pub_r001893_5_1) + 3) & 127;
  int stage_v_466_2 = (((stage_v_13_2 * 3) + pub_r001893_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = (((stage_v_363_1 * 3) + pub_r001893_2_1) + 20) & 127;
  int stage_v_467_2 = (((stage_v_363_2 * 3) + pub_r001893_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = (((stage_v_110_1 * 3) + pub_r001893_12_1) + 10) & 127;
  int stage_v_468_2 = (((stage_v_110_2 * 3) + pub_r001893_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001893_3_1 * 2) + 19) & 63;
  int stage_v_469_2 = ((pub_r001893_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_440_1 * 3) + pub_r001893_14_1) + 26) & 127;
  int stage_v_470_2 = (((stage_v_440_2 * 3) + pub_r001893_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = (((stage_v_365_1 * 3) + pub_r001893_8_1) + 40) & 127;
  int stage_v_471_2 = (((stage_v_365_2 * 3) + pub_r001893_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_471_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_471_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_471_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_471_2 * 2)) & 255;
  int stage_v_472_1 = (((stage_v_261_1 * 3) + pub_r001893_0_1) + 40) & 127;
  int stage_v_472_2 = (((stage_v_261_2 * 3) + pub_r001893_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001893_10_1 == pub_r001893_10_2);
  __CPROVER_assume(sec_r001893_17_1 != sec_r001893_17_2);
  __CPROVER_assume(sec_r001893_11_1 != sec_r001893_11_2);
  __CPROVER_assume(pub_r001893_3_1 == pub_r001893_3_2);
  __CPROVER_assume(sec_r001893_6_1 != sec_r001893_6_2);
  __CPROVER_assume(sec_r001893_7_1 != sec_r001893_7_2);
  __CPROVER_assume(pub_r001893_7_1 == pub_r001893_7_2);
  __CPROVER_assume(pub_r001893_14_1 == pub_r001893_14_2);
  __CPROVER_assume(pub_r001893_1_1 == pub_r001893_1_2);
  __CPROVER_assume(sec_r001893_15_1 != sec_r001893_15_2);
  __CPROVER_assume(pub_r001893_18_1 == pub_r001893_18_2);
  __CPROVER_assume(pub_r001893_5_1 == pub_r001893_5_2);
  __CPROVER_assume(sec_r001893_2_1 != sec_r001893_2_2);
  __CPROVER_assume(sec_r001893_3_1 != sec_r001893_3_2);
  __CPROVER_assume(pub_r001893_13_1 == pub_r001893_13_2);
  __CPROVER_assume(pub_r001893_15_1 == pub_r001893_15_2);
  __CPROVER_assume(pub_r001893_2_1 == pub_r001893_2_2);
  __CPROVER_assume(pub_r001893_12_1 == pub_r001893_12_2);
  __CPROVER_assume(pub_r001893_6_1 == pub_r001893_6_2);
  __CPROVER_assume(sec_r001893_12_1 != sec_r001893_12_2);
  __CPROVER_assume(sec_r001893_10_1 != sec_r001893_10_2);
  __CPROVER_assume(sec_r001893_5_1 != sec_r001893_5_2);
  __CPROVER_assume(sec_r001893_18_1 != sec_r001893_18_2);
  __CPROVER_assume(pub_r001893_17_1 == pub_r001893_17_2);
  __CPROVER_assume(pub_r001893_19_1 == pub_r001893_19_2);
  __CPROVER_assume(pub_r001893_4_1 == pub_r001893_4_2);
  __CPROVER_assume(sec_r001893_8_1 != sec_r001893_8_2);
  __CPROVER_assume(sec_r001893_4_1 != sec_r001893_4_2);
  __CPROVER_assume(pub_r001893_0_1 == pub_r001893_0_2);
  __CPROVER_assume(sec_r001893_9_1 != sec_r001893_9_2);
  __CPROVER_assume(pub_r001893_16_1 == pub_r001893_16_2);
  __CPROVER_assume(sec_r001893_16_1 != sec_r001893_16_2);
  __CPROVER_assume(sec_r001893_1_1 != sec_r001893_1_2);
  __CPROVER_assume(sec_r001893_14_1 != sec_r001893_14_2);
  __CPROVER_assume(pub_r001893_8_1 == pub_r001893_8_2);
  __CPROVER_assume(sec_r001893_0_1 != sec_r001893_0_2);
  __CPROVER_assume(pub_r001893_11_1 == pub_r001893_11_2);
  __CPROVER_assume(sec_r001893_13_1 != sec_r001893_13_2);
  __CPROVER_assume(pub_r001893_9_1 == pub_r001893_9_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.fee == st_var_0_2.fee);
  assert(st_var_0_1.balance == st_var_0_2.balance);
  assert(st_var_0_1.status == st_var_0_2.status);
  assert(st_var_0_1.auth_code == st_var_0_2.auth_code);
  assert(st_var_0_1.rate == st_var_0_2.rate);
  assert(st_var_0_1.account_id == st_var_0_2.account_id);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.code == st_var_1_2.code);
  assert(st_var_1_1.signature == st_var_1_2.signature);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.facility == st_var_1_2.facility);
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
}


