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
struct EventLog_R001246_4613_0
{
  int timestamp;
  unsigned char facility;
  short code;
  int signature;
  int seq;
  int buffer[3];
};
struct FilterState_R001246_4613_1
{
  unsigned char prev_in;
  unsigned char gain_db;
  int mode;
  short prev_out;
  int damping;
  int cutoff;
  int buffer[3];
};
struct Transaction_R001246_4613_2
{
  int status;
  int fee;
  unsigned char account_id;
  int auth_code;
  unsigned char balance;
  int buffer[3];
};
union PacketPayload_R001246_4613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001246_4613_1
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
void fn_R001246_4613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int index_reg_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_62_1 > 25)
  {
    acc_1 = ((acc_1 + (index_reg_62_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_62_2 > 25)
  {
    acc_2 = ((acc_2 + (index_reg_62_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_62_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_52_1 = 0;
  int quotient_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_52_1 = ((quotient_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_52_2 = ((quotient_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_52_1) & 127;
    acc_2 = (acc_2 + quotient_52_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_62_1 == index_reg_62_2);
  assert(quotient_52_1 == quotient_52_2);
}

int fn_R001246_4613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int index_reg_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_62 > 25)
  {
    acc = ((acc + (index_reg_62 * 2)) + 5) & 127;
    aux ^= index_reg_62 & 15;
  }
  else
  {
    acc = ((acc - index_reg_62) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_52 = ((quotient_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_52) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001246_4613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int damping_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_86_1)
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

  switch (damping_86_2)
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

  int accumulator_67_1 = 0;
  int accumulator_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_67_1 = ((accumulator_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_67_2 = ((accumulator_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_67_1) & 127;
    acc_2 = (acc_2 + accumulator_67_2) & 127;
  }

  int accumulator_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_89_1 > 45)
  {
    acc_1 = ((acc_1 + (accumulator_89_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_89_2 > 45)
  {
    acc_2 = ((acc_2 + (accumulator_89_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_73_1 = local_arr_1[aux_1 % 3];
  int quotient_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_86_1 == damping_86_2);
  assert(accumulator_67_1 == accumulator_67_2);
  assert(accumulator_89_1 == accumulator_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_73_1 == quotient_73_2);
}

int fn_R001246_4613_1(int p0, int p1)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int damping_86 = (aux + st.buffer[1]) & 3;
  switch (damping_86)
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

  int accumulator_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_67 = ((accumulator_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_67) & 127;
  }

  int accumulator_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_89 > 45)
  {
    acc = ((acc + (accumulator_89 * 2)) + 5) & 127;
    aux ^= accumulator_89 & 15;
  }
  else
  {
    acc = ((acc - accumulator_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_73 = local_arr[aux % 3];
  acc = (acc + (quotient_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int mask_23_1 = 0;
  int mask_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_23_1 = ((mask_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_23_2 = ((mask_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_23_1) & 127;
    acc_2 = (acc_2 + mask_23_2) & 127;
  }

  int margin_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_64_1 > 15)
  {
    acc_1 = ((acc_1 + (margin_64_1 * 2)) + 5) & 127;
    aux_1 ^= margin_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_64_2 > 15)
  {
    acc_2 = ((acc_2 + (margin_64_2 * 2)) + 5) & 127;
    aux_2 ^= margin_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_23_1 == mask_23_2);
  assert(margin_64_1 == margin_64_2);
}

int fn_R001246_4613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int mask_23 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_23 = ((mask_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_23) & 127;
  }

  int margin_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_64 > 15)
  {
    acc = ((acc + (margin_64 * 2)) + 5) & 127;
    aux ^= margin_64 & 15;
  }
  else
  {
    acc = ((acc - margin_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001246_4613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_42_1 = local_arr_1[aux_1 % 3];
  int cursor_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_42_2 * 2)) & 127;
  int tracker_70_1 = 0;
  int tracker_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_70_1 = ((tracker_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_70_2 = ((tracker_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_70_1) & 127;
    acc_2 = (acc_2 + tracker_70_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_91_1) & 63;
  aux_2 = (aux_2 + vector_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
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

  assert(cursor_42_1 == cursor_42_2);
  assert(tracker_70_1 == tracker_70_2);
  assert(vector_91_1 == vector_91_2);
}

int fn_R001246_4613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int cursor_42 = local_arr[aux % 3];
  acc = (acc + (cursor_42 * 2)) & 127;
  int tracker_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_70 = ((tracker_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_70) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001246_4613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int vector_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_43_1 > 33)
  {
    acc_1 = ((acc_1 + (vector_43_1 * 2)) + 5) & 127;
    aux_1 ^= vector_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_43_2 > 33)
  {
    acc_2 = ((acc_2 + (vector_43_2 * 2)) + 5) & 127;
    aux_2 ^= vector_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_45_1 = local_arr_1[aux_1 % 3];
  int quantum_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_43_1 == vector_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_45_1 == quantum_45_2);
}

int fn_R001246_4613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int vector_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_43 > 33)
  {
    acc = ((acc + (vector_43 * 2)) + 5) & 127;
    aux ^= vector_43 & 15;
  }
  else
  {
    acc = ((acc - vector_43) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quantum_45 = local_arr[aux % 3];
  acc = (acc + (quantum_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_31_1 = local_arr_1[aux_1 % 3];
  int index_reg_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_31_2 * 2)) & 127;
  int phase_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_27_1 > 25)
  {
    acc_1 = ((acc_1 + (phase_27_1 * 2)) + 5) & 127;
    aux_1 ^= phase_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_27_2 > 25)
  {
    acc_2 = ((acc_2 + (phase_27_2 * 2)) + 5) & 127;
    aux_2 ^= phase_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_31_1 = 0;
  int metric_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_31_1 = ((metric_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_31_2 = ((metric_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_31_1) & 127;
    acc_2 = (acc_2 + metric_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_31_1 == index_reg_31_2);
  assert(phase_27_1 == phase_27_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R001246_4613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int index_reg_31 = local_arr[aux % 3];
  acc = (acc + (index_reg_31 * 2)) & 127;
  int phase_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_27 > 25)
  {
    acc = ((acc + (phase_27 * 2)) + 5) & 127;
    aux ^= phase_27 & 15;
  }
  else
  {
    acc = ((acc - phase_27) + 11) & 127;
    aux += 3;
  }
  int metric_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_31 = ((metric_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001246_4613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int phase_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_23_1) & 63;
  aux_2 = (aux_2 + phase_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_49_1)
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

  switch (accumulator_49_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_23_1 == phase_23_2);
  assert(accumulator_49_1 == accumulator_49_2);
}

int fn_R001246_4613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int phase_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_23) & 63;
  acc ^= aux;
  int accumulator_49 = (aux + st.buffer[1]) & 3;
  switch (accumulator_49)
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

void fn_R001246_4613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int threshold_67_1 = 0;
  int threshold_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_67_1 = ((threshold_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_67_2 = ((threshold_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_67_1) & 127;
    acc_2 = (acc_2 + threshold_67_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.code == st_2.code);
  assert(st_1.signature == st_2.signature);
  assert(st_1.seq == st_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_67_1 == threshold_67_2);
}

int fn_R001246_4613_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int threshold_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_67 = ((threshold_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_67) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int checksum_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_98_1)
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

  switch (checksum_98_2)
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

  int anchor_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_58_1) & 63;
  aux_2 = (aux_2 + anchor_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_34_1 = 0;
  int stride_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_34_1 = ((stride_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_34_2 = ((stride_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_34_1) & 127;
    acc_2 = (acc_2 + stride_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_98_1 == checksum_98_2);
  assert(anchor_58_1 == anchor_58_2);
  assert(stride_34_1 == stride_34_2);
}

int fn_R001246_4613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int checksum_98 = (aux + st.buffer[1]) & 3;
  switch (checksum_98)
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

  int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_58) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_34 = ((stride_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001246_4613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int phase_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_60_1)
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

  switch (phase_60_2)
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
  int tracker_12_1 = local_arr_1[aux_1 % 3];
  int tracker_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_91_1) & 63;
  aux_2 = (aux_2 + quotient_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_60_1 == phase_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_12_1 == tracker_12_2);
  assert(quotient_91_1 == quotient_91_2);
}

int fn_R001246_4613_9(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int phase_60 = (aux + st.buffer[1]) & 3;
  switch (phase_60)
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
  int tracker_12 = local_arr[aux % 3];
  acc = (acc + (tracker_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001246_4613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_61_1 > 49)
  {
    acc_1 = ((acc_1 + (index_reg_61_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_61_2 > 49)
  {
    acc_2 = ((acc_2 + (index_reg_61_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_10_1 = 0;
  int margin_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_10_1 = ((margin_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_10_2 = ((margin_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_10_1) & 127;
    acc_2 = (acc_2 + margin_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_61_1 == index_reg_61_2);
  assert(margin_10_1 == margin_10_2);
}

int fn_R001246_4613_10(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_61 > 49)
  {
    acc = ((acc + (index_reg_61 * 2)) + 5) & 127;
    aux ^= index_reg_61 & 15;
  }
  else
  {
    acc = ((acc - index_reg_61) + 11) & 127;
    aux += 3;
  }
  int margin_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_10 = ((margin_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001246_4613_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int stride_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_54_1)
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

  switch (stride_54_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_16_1 = local_arr_1[aux_1 % 3];
  int factor_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_54_1 == stride_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_16_1 == factor_16_2);
}

int fn_R001246_4613_11(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int stride_54 = (aux + st.buffer[1]) & 3;
  switch (stride_54)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_16 = local_arr[aux % 3];
  acc = (acc + (factor_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_72_1 = local_arr_1[aux_1 % 3];
  int weight_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_72_2 * 2)) & 127;
  int mask_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_46_1)
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

  switch (mask_46_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_72_1 == weight_72_2);
  assert(mask_46_1 == mask_46_2);
}

int fn_R001246_4613_12(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int weight_72 = local_arr[aux % 3];
  acc = (acc + (weight_72 * 2)) & 127;
  int mask_46 = (aux + st.buffer[1]) & 3;
  switch (mask_46)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_90_1) & 63;
  aux_2 = (aux_2 + phase_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_55_1 = local_arr_1[aux_1 % 3];
  int window_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_55_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_90_1 == phase_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_55_1 == window_55_2);
}

int fn_R001246_4613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_90) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_55 = local_arr[aux % 3];
  acc = (acc + (window_55 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_73_1 = local_arr_1[aux_1 % 3];
  int coefficient_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_73_1 == coefficient_73_2);
}

int fn_R001246_4613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_73 = local_arr[aux % 3];
  acc = (acc + (coefficient_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int weight_15_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_15_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_15_1 > 16)
  {
    acc_1 = ((acc_1 + (weight_15_1 * 2)) + 5) & 127;
    aux_1 ^= weight_15_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_15_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_15_2 > 16)
  {
    acc_2 = ((acc_2 + (weight_15_2 * 2)) + 5) & 127;
    aux_2 ^= weight_15_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_15_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_18_1 = local_arr_1[aux_1 % 3];
  int parity_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_18_2 * 2)) & 127;
  int tally_38_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_38_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_38_1)
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

  switch (tally_38_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_15_1 == weight_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_18_1 == parity_18_2);
  assert(tally_38_1 == tally_38_2);
}

int fn_R001246_4613_15(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int weight_15 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_15 > 16)
  {
    acc = ((acc + (weight_15 * 2)) + 5) & 127;
    aux ^= weight_15 & 15;
  }
  else
  {
    acc = ((acc - weight_15) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_18 = local_arr[aux % 3];
  acc = (acc + (parity_18 * 2)) & 127;
  int tally_38 = (aux + st.buffer[1]) & 3;
  switch (tally_38)
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

void fn_R001246_4613_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st_1 = {0};
  struct EventLog_R001246_4613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_52_1 = local_arr_1[aux_1 % 3];
  int factor_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_52_2 * 2)) & 127;
  int delta_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_86_1) & 63;
  aux_2 = (aux_2 + delta_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_19_1)
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

  switch (pivot_19_2)
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

  int anchor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_44_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_44_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_44_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_44_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
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

  assert(factor_52_1 == factor_52_2);
  assert(delta_86_1 == delta_86_2);
  assert(pivot_19_1 == pivot_19_2);
  assert(anchor_44_1 == anchor_44_2);
}

int fn_R001246_4613_16(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001246_4613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int factor_52 = local_arr[aux % 3];
  acc = (acc + (factor_52 * 2)) & 127;
  int delta_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_86) & 63;
  acc ^= aux;
  int pivot_19 = (aux + st.buffer[1]) & 3;
  switch (pivot_19)
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

  int anchor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_44 > 49)
  {
    acc = ((acc + (anchor_44 * 2)) + 5) & 127;
    aux ^= anchor_44 & 15;
  }
  else
  {
    acc = ((acc - anchor_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001246_4613_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_60_1 = 0;
  int factor_60_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_60_1 = ((factor_60_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_60_2 = ((factor_60_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_60_1) & 127;
    acc_2 = (acc_2 + factor_60_2) & 127;
  }

  int quantum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_75_1)
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

  switch (quantum_75_2)
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
  int damping_33_1 = local_arr_1[aux_1 % 3];
  int damping_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_33_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_60_1 == factor_60_2);
  assert(quantum_75_1 == quantum_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_33_1 == damping_33_2);
}

int fn_R001246_4613_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_60 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_60 = ((factor_60 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_60) & 127;
  }

  int quantum_75 = (aux + st.buffer[1]) & 3;
  switch (quantum_75)
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
  int damping_33 = local_arr[aux % 3];
  acc = (acc + (damping_33 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_16_1 = local_arr_1[aux_1 % 3];
  int margin_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_16_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_77_1 = 0;
  int anchor_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_77_1 = ((anchor_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_77_2 = ((anchor_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_77_1) & 127;
    acc_2 = (acc_2 + anchor_77_2) & 127;
  }

  int pivot_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_17_1 > 38)
  {
    acc_1 = ((acc_1 + (pivot_17_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_17_2 > 38)
  {
    acc_2 = ((acc_2 + (pivot_17_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_16_1 == margin_16_2);
  assert(anchor_77_1 == anchor_77_2);
  assert(pivot_17_1 == pivot_17_2);
}

int fn_R001246_4613_18(int p0, int p1, int p2)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int margin_16 = local_arr[aux % 3];
  acc = (acc + (margin_16 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_77 = ((anchor_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_77) & 127;
  }

  int pivot_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_17 > 38)
  {
    acc = ((acc + (pivot_17 * 2)) + 5) & 127;
    aux ^= pivot_17 & 15;
  }
  else
  {
    acc = ((acc - pivot_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001246_4613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st_1 = {0};
  struct Transaction_R001246_4613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_10_1 > 20)
  {
    acc_1 = ((acc_1 + (cursor_10_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_10_2 > 20)
  {
    acc_2 = ((acc_2 + (cursor_10_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.fee == st_2.fee);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.auth_code == st_2.auth_code);
  assert(st_1.balance == st_2.balance);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_10_1 == cursor_10_2);
}

int fn_R001246_4613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001246_4613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_10 > 20)
  {
    acc = ((acc + (cursor_10 * 2)) + 5) & 127;
    aux ^= cursor_10 & 15;
  }
  else
  {
    acc = ((acc - cursor_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001246_4613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int damping_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_12_1 > 40)
  {
    acc_1 = ((acc_1 + (damping_12_1 * 2)) + 5) & 127;
    aux_1 ^= damping_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_12_2 > 40)
  {
    acc_2 = ((acc_2 + (damping_12_2 * 2)) + 5) & 127;
    aux_2 ^= damping_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_12_1 == damping_12_2);
}

int fn_R001246_4613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int damping_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_12 > 40)
  {
    acc = ((acc + (damping_12 * 2)) + 5) & 127;
    aux ^= damping_12 & 15;
  }
  else
  {
    acc = ((acc - damping_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001246_4613_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st_1 = {0};
  struct FilterState_R001246_4613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_79_1 = local_arr_1[aux_1 % 3];
  int accumulator_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_79_2 * 2)) & 127;
  int delta_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_74_1) & 63;
  aux_2 = (aux_2 + delta_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_66_1)
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

  switch (bound_66_2)
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
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_79_1 == accumulator_79_2);
  assert(delta_74_1 == delta_74_2);
  assert(bound_66_1 == bound_66_2);
}

int fn_R001246_4613_21(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001246_4613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int accumulator_79 = local_arr[aux % 3];
  acc = (acc + (accumulator_79 * 2)) & 127;
  int delta_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_74) & 63;
  acc ^= aux;
  int bound_66 = (aux + st.buffer[1]) & 3;
  switch (bound_66)
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

void main()
{
  int sec_r001246_0_1;
  int sec_r001246_0_2;
  int sec_r001246_1_1;
  int sec_r001246_1_2;
  int sec_r001246_2_1;
  int sec_r001246_2_2;
  int sec_r001246_3_1;
  int sec_r001246_3_2;
  int sec_r001246_4_1;
  int sec_r001246_4_2;
  int sec_r001246_5_1;
  int sec_r001246_5_2;
  int sec_r001246_6_1;
  int sec_r001246_6_2;
  int sec_r001246_7_1;
  int sec_r001246_7_2;
  int sec_r001246_8_1;
  int sec_r001246_8_2;
  int sec_r001246_9_1;
  int sec_r001246_9_2;
  int sec_r001246_10_1;
  int sec_r001246_10_2;
  int sec_r001246_11_1;
  int sec_r001246_11_2;
  int sec_r001246_12_1;
  int sec_r001246_12_2;
  int sec_r001246_13_1;
  int sec_r001246_13_2;
  int sec_r001246_14_1;
  int sec_r001246_14_2;
  int sec_r001246_15_1;
  int sec_r001246_15_2;
  int sec_r001246_16_1;
  int sec_r001246_16_2;
  int sec_r001246_17_1;
  int sec_r001246_17_2;
  int sec_r001246_18_1;
  int sec_r001246_18_2;
  int sec_r001246_19_1;
  int sec_r001246_19_2;
  int sec_r001246_20_1;
  int sec_r001246_20_2;
  int sec_r001246_21_1;
  int sec_r001246_21_2;
  int sec_r001246_22_1;
  int sec_r001246_22_2;
  int pub_r001246_0_1;
  int pub_r001246_0_2;
  int pub_r001246_1_1;
  int pub_r001246_1_2;
  int pub_r001246_2_1;
  int pub_r001246_2_2;
  int pub_r001246_3_1;
  int pub_r001246_3_2;
  int pub_r001246_4_1;
  int pub_r001246_4_2;
  int pub_r001246_5_1;
  int pub_r001246_5_2;
  int pub_r001246_6_1;
  int pub_r001246_6_2;
  int pub_r001246_7_1;
  int pub_r001246_7_2;
  int pub_r001246_8_1;
  int pub_r001246_8_2;
  int pub_r001246_9_1;
  int pub_r001246_9_2;
  int pub_r001246_10_1;
  int pub_r001246_10_2;
  int pub_r001246_11_1;
  int pub_r001246_11_2;
  int pub_r001246_12_1;
  int pub_r001246_12_2;
  int pub_r001246_13_1;
  int pub_r001246_13_2;
  int pub_r001246_14_1;
  int pub_r001246_14_2;
  int pub_r001246_15_1;
  int pub_r001246_15_2;
  int pub_r001246_16_1;
  int pub_r001246_16_2;
  int pub_r001246_17_1;
  int pub_r001246_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001246_0_1 >= (-100)) && (pub_r001246_0_1 <= 100));
  __CPROVER_assume((pub_r001246_0_2 >= (-100)) && (pub_r001246_0_2 <= 100));
  __CPROVER_assume((pub_r001246_1_1 >= (-100)) && (pub_r001246_1_1 <= 100));
  __CPROVER_assume((pub_r001246_1_2 >= (-100)) && (pub_r001246_1_2 <= 100));
  __CPROVER_assume((pub_r001246_2_1 >= (-100)) && (pub_r001246_2_1 <= 100));
  __CPROVER_assume((pub_r001246_2_2 >= (-100)) && (pub_r001246_2_2 <= 100));
  __CPROVER_assume((pub_r001246_3_1 >= (-100)) && (pub_r001246_3_1 <= 100));
  __CPROVER_assume((pub_r001246_3_2 >= (-100)) && (pub_r001246_3_2 <= 100));
  __CPROVER_assume((pub_r001246_4_1 >= (-100)) && (pub_r001246_4_1 <= 100));
  __CPROVER_assume((pub_r001246_4_2 >= (-100)) && (pub_r001246_4_2 <= 100));
  __CPROVER_assume((pub_r001246_5_1 >= (-100)) && (pub_r001246_5_1 <= 100));
  __CPROVER_assume((pub_r001246_5_2 >= (-100)) && (pub_r001246_5_2 <= 100));
  __CPROVER_assume((pub_r001246_6_1 >= (-100)) && (pub_r001246_6_1 <= 100));
  __CPROVER_assume((pub_r001246_6_2 >= (-100)) && (pub_r001246_6_2 <= 100));
  __CPROVER_assume((pub_r001246_7_1 >= (-100)) && (pub_r001246_7_1 <= 100));
  __CPROVER_assume((pub_r001246_7_2 >= (-100)) && (pub_r001246_7_2 <= 100));
  __CPROVER_assume((pub_r001246_8_1 >= (-100)) && (pub_r001246_8_1 <= 100));
  __CPROVER_assume((pub_r001246_8_2 >= (-100)) && (pub_r001246_8_2 <= 100));
  __CPROVER_assume((pub_r001246_9_1 >= (-100)) && (pub_r001246_9_1 <= 100));
  __CPROVER_assume((pub_r001246_9_2 >= (-100)) && (pub_r001246_9_2 <= 100));
  __CPROVER_assume((pub_r001246_10_1 >= (-100)) && (pub_r001246_10_1 <= 100));
  __CPROVER_assume((pub_r001246_10_2 >= (-100)) && (pub_r001246_10_2 <= 100));
  __CPROVER_assume((pub_r001246_11_1 >= (-100)) && (pub_r001246_11_1 <= 100));
  __CPROVER_assume((pub_r001246_11_2 >= (-100)) && (pub_r001246_11_2 <= 100));
  __CPROVER_assume((pub_r001246_12_1 >= (-100)) && (pub_r001246_12_1 <= 100));
  __CPROVER_assume((pub_r001246_12_2 >= (-100)) && (pub_r001246_12_2 <= 100));
  __CPROVER_assume((pub_r001246_13_1 >= (-100)) && (pub_r001246_13_1 <= 100));
  __CPROVER_assume((pub_r001246_13_2 >= (-100)) && (pub_r001246_13_2 <= 100));
  __CPROVER_assume((pub_r001246_14_1 >= (-100)) && (pub_r001246_14_1 <= 100));
  __CPROVER_assume((pub_r001246_14_2 >= (-100)) && (pub_r001246_14_2 <= 100));
  __CPROVER_assume((pub_r001246_15_1 >= (-100)) && (pub_r001246_15_1 <= 100));
  __CPROVER_assume((pub_r001246_15_2 >= (-100)) && (pub_r001246_15_2 <= 100));
  __CPROVER_assume((pub_r001246_16_1 >= (-100)) && (pub_r001246_16_1 <= 100));
  __CPROVER_assume((pub_r001246_16_2 >= (-100)) && (pub_r001246_16_2 <= 100));
  __CPROVER_assume((pub_r001246_17_1 >= (-100)) && (pub_r001246_17_1 <= 100));
  __CPROVER_assume((pub_r001246_17_2 >= (-100)) && (pub_r001246_17_2 <= 100));
  __CPROVER_assume((sec_r001246_0_1 >= 0) && (sec_r001246_0_1 <= 255));
  __CPROVER_assume((sec_r001246_0_2 >= 0) && (sec_r001246_0_2 <= 255));
  __CPROVER_assume((sec_r001246_1_1 >= 0) && (sec_r001246_1_1 <= 255));
  __CPROVER_assume((sec_r001246_1_2 >= 0) && (sec_r001246_1_2 <= 255));
  __CPROVER_assume((sec_r001246_2_1 >= 0) && (sec_r001246_2_1 <= 255));
  __CPROVER_assume((sec_r001246_2_2 >= 0) && (sec_r001246_2_2 <= 255));
  __CPROVER_assume((sec_r001246_3_1 >= 0) && (sec_r001246_3_1 <= 255));
  __CPROVER_assume((sec_r001246_3_2 >= 0) && (sec_r001246_3_2 <= 255));
  __CPROVER_assume((sec_r001246_4_1 >= 0) && (sec_r001246_4_1 <= 255));
  __CPROVER_assume((sec_r001246_4_2 >= 0) && (sec_r001246_4_2 <= 255));
  __CPROVER_assume((sec_r001246_5_1 >= 0) && (sec_r001246_5_1 <= 255));
  __CPROVER_assume((sec_r001246_5_2 >= 0) && (sec_r001246_5_2 <= 255));
  __CPROVER_assume((sec_r001246_6_1 >= 0) && (sec_r001246_6_1 <= 255));
  __CPROVER_assume((sec_r001246_6_2 >= 0) && (sec_r001246_6_2 <= 255));
  __CPROVER_assume((sec_r001246_7_1 >= 0) && (sec_r001246_7_1 <= 255));
  __CPROVER_assume((sec_r001246_7_2 >= 0) && (sec_r001246_7_2 <= 255));
  __CPROVER_assume((sec_r001246_8_1 >= 0) && (sec_r001246_8_1 <= 255));
  __CPROVER_assume((sec_r001246_8_2 >= 0) && (sec_r001246_8_2 <= 255));
  __CPROVER_assume((sec_r001246_9_1 >= 0) && (sec_r001246_9_1 <= 255));
  __CPROVER_assume((sec_r001246_9_2 >= 0) && (sec_r001246_9_2 <= 255));
  __CPROVER_assume((sec_r001246_10_1 >= 0) && (sec_r001246_10_1 <= 255));
  __CPROVER_assume((sec_r001246_10_2 >= 0) && (sec_r001246_10_2 <= 255));
  __CPROVER_assume((sec_r001246_11_1 >= 0) && (sec_r001246_11_1 <= 255));
  __CPROVER_assume((sec_r001246_11_2 >= 0) && (sec_r001246_11_2 <= 255));
  __CPROVER_assume((sec_r001246_12_1 >= 0) && (sec_r001246_12_1 <= 255));
  __CPROVER_assume((sec_r001246_12_2 >= 0) && (sec_r001246_12_2 <= 255));
  __CPROVER_assume((sec_r001246_13_1 >= 0) && (sec_r001246_13_1 <= 255));
  __CPROVER_assume((sec_r001246_13_2 >= 0) && (sec_r001246_13_2 <= 255));
  __CPROVER_assume((sec_r001246_14_1 >= 0) && (sec_r001246_14_1 <= 255));
  __CPROVER_assume((sec_r001246_14_2 >= 0) && (sec_r001246_14_2 <= 255));
  __CPROVER_assume((sec_r001246_15_1 >= 0) && (sec_r001246_15_1 <= 255));
  __CPROVER_assume((sec_r001246_15_2 >= 0) && (sec_r001246_15_2 <= 255));
  __CPROVER_assume((sec_r001246_16_1 >= 0) && (sec_r001246_16_1 <= 255));
  __CPROVER_assume((sec_r001246_16_2 >= 0) && (sec_r001246_16_2 <= 255));
  __CPROVER_assume((sec_r001246_17_1 >= 0) && (sec_r001246_17_1 <= 255));
  __CPROVER_assume((sec_r001246_17_2 >= 0) && (sec_r001246_17_2 <= 255));
  __CPROVER_assume((sec_r001246_18_1 >= 0) && (sec_r001246_18_1 <= 255));
  __CPROVER_assume((sec_r001246_18_2 >= 0) && (sec_r001246_18_2 <= 255));
  __CPROVER_assume((sec_r001246_19_1 >= 0) && (sec_r001246_19_1 <= 255));
  __CPROVER_assume((sec_r001246_19_2 >= 0) && (sec_r001246_19_2 <= 255));
  __CPROVER_assume((sec_r001246_20_1 >= 0) && (sec_r001246_20_1 <= 255));
  __CPROVER_assume((sec_r001246_20_2 >= 0) && (sec_r001246_20_2 <= 255));
  __CPROVER_assume((sec_r001246_21_1 >= 0) && (sec_r001246_21_1 <= 255));
  __CPROVER_assume((sec_r001246_21_2 >= 0) && (sec_r001246_21_2 <= 255));
  __CPROVER_assume((sec_r001246_22_1 >= 0) && (sec_r001246_22_1 <= 255));
  __CPROVER_assume((sec_r001246_22_2 >= 0) && (sec_r001246_22_2 <= 255));
  struct EventLog_R001246_4613_0 st_var_0_1 = {0};
  struct EventLog_R001246_4613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001246_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001246_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001246_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001246_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001246_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001246_0_2 + 7) & 15;
  struct FilterState_R001246_4613_1 st_var_1_1 = {0};
  struct FilterState_R001246_4613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001246_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001246_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001246_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001246_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001246_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001246_0_2 + 9) & 15;
  struct Transaction_R001246_4613_2 st_var_2_1 = {0};
  struct Transaction_R001246_4613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001246_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001246_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001246_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001246_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001246_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001246_0_2 + 11) & 15;
  union PacketPayload_R001246_4613_0 u_var_1;
  union PacketPayload_R001246_4613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001246_4613_0(sec_r001246_0_1, sec_r001246_1_1, pub_r001246_2_1, pub_r001246_3_1);
  int helper_flow_0_2 = fn_R001246_4613_0(sec_r001246_0_2, sec_r001246_1_2, pub_r001246_2_2, pub_r001246_3_2);
  fn_R001246_4613_0_2(sec_r001246_0_1, sec_r001246_1_1, pub_r001246_2_1, pub_r001246_3_1, sec_r001246_0_2, sec_r001246_1_2, pub_r001246_2_2, pub_r001246_3_2);
  int helper_flow_1_1 = fn_R001246_4613_1(sec_r001246_1_1, sec_r001246_2_1);
  int helper_flow_1_2 = fn_R001246_4613_1(sec_r001246_1_2, sec_r001246_2_2);
  fn_R001246_4613_1_2(sec_r001246_1_1, sec_r001246_2_1, sec_r001246_1_2, sec_r001246_2_2);
  int helper_flow_2_1 = fn_R001246_4613_2(sec_r001246_2_1, sec_r001246_3_1, pub_r001246_4_1);
  int helper_flow_2_2 = fn_R001246_4613_2(sec_r001246_2_2, sec_r001246_3_2, pub_r001246_4_2);
  fn_R001246_4613_2_2(sec_r001246_2_1, sec_r001246_3_1, pub_r001246_4_1, sec_r001246_2_2, sec_r001246_3_2, pub_r001246_4_2);
  int helper_flow_3_1 = fn_R001246_4613_3(sec_r001246_3_1, sec_r001246_4_1, pub_r001246_5_1, pub_r001246_6_1);
  int helper_flow_3_2 = fn_R001246_4613_3(sec_r001246_3_2, sec_r001246_4_2, pub_r001246_5_2, pub_r001246_6_2);
  fn_R001246_4613_3_2(sec_r001246_3_1, sec_r001246_4_1, pub_r001246_5_1, pub_r001246_6_1, sec_r001246_3_2, sec_r001246_4_2, pub_r001246_5_2, pub_r001246_6_2);
  int helper_flow_4_1 = fn_R001246_4613_4(sec_r001246_4_1, sec_r001246_5_1, pub_r001246_6_1);
  int helper_flow_4_2 = fn_R001246_4613_4(sec_r001246_4_2, sec_r001246_5_2, pub_r001246_6_2);
  fn_R001246_4613_4_2(sec_r001246_4_1, sec_r001246_5_1, pub_r001246_6_1, sec_r001246_4_2, sec_r001246_5_2, pub_r001246_6_2);
  int helper_flow_5_1 = fn_R001246_4613_5(sec_r001246_5_1, pub_r001246_6_1, pub_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1);
  int helper_flow_5_2 = fn_R001246_4613_5(sec_r001246_5_2, pub_r001246_6_2, pub_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2);
  fn_R001246_4613_5_2(sec_r001246_5_1, pub_r001246_6_1, pub_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1, sec_r001246_5_2, pub_r001246_6_2, pub_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2);
  int helper_flow_6_1 = fn_R001246_4613_6(sec_r001246_6_1, pub_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1);
  int helper_flow_6_2 = fn_R001246_4613_6(sec_r001246_6_2, pub_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  fn_R001246_4613_6_2(sec_r001246_6_1, pub_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1, sec_r001246_6_2, pub_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  int helper_flow_7_1 = fn_R001246_4613_7(sec_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1);
  int helper_flow_7_2 = fn_R001246_4613_7(sec_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  fn_R001246_4613_7_2(sec_r001246_7_1, pub_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1, sec_r001246_7_2, pub_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  int helper_flow_8_1 = fn_R001246_4613_8(sec_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1);
  int helper_flow_8_2 = fn_R001246_4613_8(sec_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  fn_R001246_4613_8_2(sec_r001246_8_1, pub_r001246_9_1, pub_r001246_10_1, sec_r001246_8_2, pub_r001246_9_2, pub_r001246_10_2);
  int helper_flow_9_1 = fn_R001246_4613_9(sec_r001246_9_1, sec_r001246_10_1);
  int helper_flow_9_2 = fn_R001246_4613_9(sec_r001246_9_2, sec_r001246_10_2);
  fn_R001246_4613_9_2(sec_r001246_9_1, sec_r001246_10_1, sec_r001246_9_2, sec_r001246_10_2);
  int helper_flow_10_1 = fn_R001246_4613_10(sec_r001246_10_1, pub_r001246_11_1);
  int helper_flow_10_2 = fn_R001246_4613_10(sec_r001246_10_2, pub_r001246_11_2);
  fn_R001246_4613_10_2(sec_r001246_10_1, pub_r001246_11_1, sec_r001246_10_2, pub_r001246_11_2);
  int stage_v_0_1 = ((pub_r001246_13_1 * 2) + 7) & 63;
  int stage_v_0_2 = ((pub_r001246_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001246_22_1 + (pub_r001246_17_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001246_22_2 + (pub_r001246_17_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((sec_r001246_19_1 + (pub_r001246_12_1 * 2)) + 11) & 127;
  int stage_v_2_2 = ((sec_r001246_19_2 + (pub_r001246_12_2 * 2)) + 11) & 127;
  if (stage_v_2_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_2_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_2_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_2_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_3_1 = ((helper_flow_8_1 + (pub_r001246_0_1 * 2)) + 14) & 127;
  int stage_v_3_2 = ((helper_flow_8_2 + (pub_r001246_0_2 * 2)) + 14) & 127;
  if (stage_v_3_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_3_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_3_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_3_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_4_1 = ((sec_r001246_22_1 + (pub_r001246_13_1 * 2)) + 17) & 127;
  int stage_v_4_2 = ((sec_r001246_22_2 + (pub_r001246_13_2 * 2)) + 17) & 127;
  if (stage_v_4_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_4_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_4_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_4_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_5_1 = ((helper_flow_10_1 + (pub_r001246_1_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((helper_flow_10_2 + (pub_r001246_1_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((pub_r001246_8_1 * 2) + 23) & 63;
  int stage_v_6_2 = ((pub_r001246_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((sec_r001246_20_1 + (pub_r001246_7_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001246_20_2 + (pub_r001246_7_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((pub_r001246_12_1 * 2) + 40) & 63;
  int stage_v_8_2 = ((pub_r001246_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((helper_flow_10_1 + (pub_r001246_17_1 * 2)) + 32) & 127;
  int stage_v_9_2 = ((helper_flow_10_2 + (pub_r001246_17_2 * 2)) + 32) & 127;
  if (stage_v_9_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_9_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_9_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_9_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_10_1 = ((sec_r001246_8_1 + (pub_r001246_4_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((sec_r001246_8_2 + (pub_r001246_4_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001246_9_1 + (pub_r001246_5_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001246_9_2 + (pub_r001246_5_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((sec_r001246_14_1 + (pub_r001246_0_1 * 2)) + 41) & 127;
  int stage_v_12_2 = ((sec_r001246_14_2 + (pub_r001246_0_2 * 2)) + 41) & 127;
  if (stage_v_12_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_12_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_12_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_12_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_13_1 = ((pub_r001246_10_1 * 2) + 28) & 63;
  int stage_v_13_2 = ((pub_r001246_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001246_22_1 + (pub_r001246_14_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001246_22_2 + (pub_r001246_14_2 * 2)) + 47) & 127;
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
  int stage_v_15_1 = ((sec_r001246_17_1 + (pub_r001246_12_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001246_17_2 + (pub_r001246_12_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((stage_v_15_1 + (pub_r001246_14_1 * 2)) + 53) & 127;
  int stage_v_16_2 = ((stage_v_15_2 + (pub_r001246_14_2 * 2)) + 53) & 127;
  if (stage_v_16_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_16_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_16_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_16_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_17_1 = ((pub_r001246_11_1 * 2) + 49) & 63;
  int stage_v_17_2 = ((pub_r001246_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((helper_flow_10_1 + (pub_r001246_8_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_10_2 + (pub_r001246_8_2 * 2)) + 59) & 127;
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
  int stage_v_19_1 = ((sec_r001246_20_1 + (pub_r001246_17_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((sec_r001246_20_2 + (pub_r001246_17_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((sec_r001246_0_1 + (pub_r001246_0_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((sec_r001246_0_2 + (pub_r001246_0_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((helper_flow_10_1 + (pub_r001246_2_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((helper_flow_10_2 + (pub_r001246_2_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((stage_v_7_1 + (pub_r001246_13_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((stage_v_7_2 + (pub_r001246_13_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((pub_r001246_9_1 * 2) + 17) & 63;
  int stage_v_23_2 = ((pub_r001246_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((sec_r001246_3_1 + (pub_r001246_5_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001246_3_2 + (pub_r001246_5_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001246_12_1 * 2) + 20) & 63;
  int stage_v_25_2 = ((pub_r001246_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((sec_r001246_20_1 + (pub_r001246_11_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((sec_r001246_20_2 + (pub_r001246_11_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((stage_v_4_1 + (pub_r001246_6_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((stage_v_4_2 + (pub_r001246_6_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((sec_r001246_20_1 + (pub_r001246_1_1 * 2)) + 89) & 127;
  int stage_v_28_2 = ((sec_r001246_20_2 + (pub_r001246_1_2 * 2)) + 89) & 127;
  if (stage_v_28_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_28_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_28_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_28_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_29_1 = ((sec_r001246_3_1 + (pub_r001246_3_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001246_3_2 + (pub_r001246_3_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_20_1 + (pub_r001246_16_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_20_2 + (pub_r001246_16_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((stage_v_24_1 + (pub_r001246_6_1 * 2)) + 98) & 127;
  int stage_v_31_2 = ((stage_v_24_2 + (pub_r001246_6_2 * 2)) + 98) & 127;
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
  int stage_v_32_1 = ((sec_r001246_9_1 + (pub_r001246_13_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001246_9_2 + (pub_r001246_13_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001246_8_1 * 2) + 13) & 63;
  int stage_v_33_2 = ((pub_r001246_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001246_11_1 * 2) + 49) & 63;
  int stage_v_34_2 = ((pub_r001246_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001246_0_1 * 2) + 40) & 63;
  int stage_v_35_2 = ((pub_r001246_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((sec_r001246_3_1 + (pub_r001246_4_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((sec_r001246_3_2 + (pub_r001246_4_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((pub_r001246_13_1 * 2) + 34) & 63;
  int stage_v_37_2 = ((pub_r001246_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((sec_r001246_2_1 + (pub_r001246_14_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((sec_r001246_2_2 + (pub_r001246_14_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((sec_r001246_19_1 + (pub_r001246_0_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001246_19_2 + (pub_r001246_0_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((stage_v_1_1 + (pub_r001246_16_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_1_2 + (pub_r001246_16_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((helper_flow_3_1 + (pub_r001246_17_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((helper_flow_3_2 + (pub_r001246_17_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((sec_r001246_5_1 + (pub_r001246_0_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((sec_r001246_5_2 + (pub_r001246_0_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001246_16_1 * 2) + 13) & 63;
  int stage_v_43_2 = ((pub_r001246_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((sec_r001246_4_1 + (pub_r001246_11_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((sec_r001246_4_2 + (pub_r001246_11_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001246_2_1 * 2) + 28) & 63;
  int stage_v_45_2 = ((pub_r001246_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((pub_r001246_6_1 * 2) + 30) & 63;
  int stage_v_46_2 = ((pub_r001246_6_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((stage_v_39_1 + (pub_r001246_17_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_39_2 + (pub_r001246_17_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((stage_v_10_1 + (pub_r001246_13_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_10_2 + (pub_r001246_13_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((pub_r001246_9_1 * 2) + 7) & 63;
  int stage_v_49_2 = ((pub_r001246_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((stage_v_16_1 + (pub_r001246_7_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((stage_v_16_2 + (pub_r001246_7_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((stage_v_7_1 + (pub_r001246_8_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_7_2 + (pub_r001246_8_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((pub_r001246_12_1 * 2) + 10) & 63;
  int stage_v_52_2 = ((pub_r001246_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001246_17_1 * 2) + 40) & 63;
  int stage_v_53_2 = ((pub_r001246_17_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((sec_r001246_21_1 + (pub_r001246_10_1 * 2)) + 167) & 127;
  int stage_v_54_2 = ((sec_r001246_21_2 + (pub_r001246_10_2 * 2)) + 167) & 127;
  if (stage_v_54_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_54_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_54_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_54_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_55_1 = ((stage_v_29_1 + (pub_r001246_3_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_29_2 + (pub_r001246_3_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((stage_v_21_1 + (pub_r001246_3_1 * 2)) + 173) & 127;
  int stage_v_56_2 = ((stage_v_21_2 + (pub_r001246_3_2 * 2)) + 173) & 127;
  if (stage_v_56_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_56_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_56_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_56_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_57_1 = ((pub_r001246_17_1 * 2) + 14) & 63;
  int stage_v_57_2 = ((pub_r001246_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((sec_r001246_11_1 + (pub_r001246_4_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001246_11_2 + (pub_r001246_4_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((pub_r001246_5_1 * 2) + 35) & 63;
  int stage_v_59_2 = ((pub_r001246_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((sec_r001246_0_1 + (pub_r001246_4_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001246_0_2 + (pub_r001246_4_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((helper_flow_10_1 + (pub_r001246_4_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((helper_flow_10_2 + (pub_r001246_4_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((stage_v_47_1 + (pub_r001246_5_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_47_2 + (pub_r001246_5_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_44_1 + (pub_r001246_13_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_44_2 + (pub_r001246_13_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((stage_v_36_1 + (pub_r001246_13_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((stage_v_36_2 + (pub_r001246_13_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((pub_r001246_12_1 * 2) + 47) & 63;
  int stage_v_65_2 = ((pub_r001246_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((stage_v_12_1 + (pub_r001246_4_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_12_2 + (pub_r001246_4_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((pub_r001246_16_1 * 2) + 5) & 63;
  int stage_v_67_2 = ((pub_r001246_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001246_14_1 * 2) + 36) & 63;
  int stage_v_68_2 = ((pub_r001246_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001246_15_1 * 2) + 26) & 63;
  int stage_v_69_2 = ((pub_r001246_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((stage_v_41_1 + (pub_r001246_12_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_41_2 + (pub_r001246_12_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((sec_r001246_13_1 + (pub_r001246_9_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((sec_r001246_13_2 + (pub_r001246_9_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((sec_r001246_11_1 + (pub_r001246_7_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((sec_r001246_11_2 + (pub_r001246_7_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_5_1 + (pub_r001246_3_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_5_2 + (pub_r001246_3_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((stage_v_21_1 + (pub_r001246_9_1 * 2)) + 227) & 127;
  int stage_v_74_2 = ((stage_v_21_2 + (pub_r001246_9_2 * 2)) + 227) & 127;
  if (stage_v_74_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_74_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_74_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_74_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_75_1 = ((stage_v_72_1 + (pub_r001246_1_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_72_2 + (pub_r001246_1_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((stage_v_20_1 + (pub_r001246_5_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_20_2 + (pub_r001246_5_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((helper_flow_5_1 + (pub_r001246_7_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_5_2 + (pub_r001246_7_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_15_1 + (pub_r001246_3_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_15_2 + (pub_r001246_3_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((sec_r001246_11_1 + (pub_r001246_15_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((sec_r001246_11_2 + (pub_r001246_15_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((pub_r001246_7_1 * 2) + 34) & 63;
  int stage_v_80_2 = ((pub_r001246_7_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((sec_r001246_22_1 + (pub_r001246_7_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((sec_r001246_22_2 + (pub_r001246_7_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((pub_r001246_6_1 * 2) + 20) & 63;
  int stage_v_82_2 = ((pub_r001246_6_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = ((pub_r001246_11_1 * 2) + 38) & 63;
  int stage_v_83_2 = ((pub_r001246_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = ((sec_r001246_4_1 + (pub_r001246_0_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((sec_r001246_4_2 + (pub_r001246_0_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((sec_r001246_22_1 + (pub_r001246_4_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((sec_r001246_22_2 + (pub_r001246_4_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_47_1 + (pub_r001246_0_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_47_2 + (pub_r001246_0_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((sec_r001246_13_1 + (pub_r001246_7_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((sec_r001246_13_2 + (pub_r001246_7_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((pub_r001246_17_1 * 2) + 48) & 63;
  int stage_v_88_2 = ((pub_r001246_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001246_0_1 * 2) + 14) & 63;
  int stage_v_89_2 = ((pub_r001246_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001246_18_1 + (pub_r001246_0_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001246_18_2 + (pub_r001246_0_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_29_1 + (pub_r001246_9_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_29_2 + (pub_r001246_9_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_90_1 + (pub_r001246_3_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_90_2 + (pub_r001246_3_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((helper_flow_7_1 + (pub_r001246_16_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((helper_flow_7_2 + (pub_r001246_16_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((sec_r001246_0_1 + (pub_r001246_9_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((sec_r001246_0_2 + (pub_r001246_9_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((stage_v_48_1 + (pub_r001246_1_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((stage_v_48_2 + (pub_r001246_1_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001246_16_1 * 2) + 8) & 63;
  int stage_v_96_2 = ((pub_r001246_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((stage_v_54_1 + (pub_r001246_9_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_54_2 + (pub_r001246_9_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((helper_flow_1_1 + (pub_r001246_6_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((helper_flow_1_2 + (pub_r001246_6_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001246_14_1 * 2) + 37) & 63;
  int stage_v_99_2 = ((pub_r001246_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001246_0_1 * 2) + 18) & 63;
  int stage_v_100_2 = ((pub_r001246_0_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((sec_r001246_6_1 + (pub_r001246_1_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((sec_r001246_6_2 + (pub_r001246_1_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((pub_r001246_7_1 * 2) + 30) & 63;
  int stage_v_102_2 = ((pub_r001246_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((stage_v_64_1 + (pub_r001246_11_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_64_2 + (pub_r001246_11_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001246_12_1 * 2) + 43) & 63;
  int stage_v_104_2 = ((pub_r001246_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((stage_v_60_1 + (pub_r001246_4_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_60_2 + (pub_r001246_4_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((pub_r001246_11_1 * 2) + 35) & 63;
  int stage_v_106_2 = ((pub_r001246_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001246_9_1 * 2) + 11) & 63;
  int stage_v_107_2 = ((pub_r001246_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_75_1 + (pub_r001246_13_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_75_2 + (pub_r001246_13_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((pub_r001246_7_1 * 2) + 42) & 63;
  int stage_v_109_2 = ((pub_r001246_7_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001246_11_1 * 2) + 17) & 63;
  int stage_v_110_2 = ((pub_r001246_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001246_1_1 * 2) + 22) & 63;
  int stage_v_111_2 = ((pub_r001246_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001246_1_1 * 2) + 37) & 63;
  int stage_v_112_2 = ((pub_r001246_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((stage_v_81_1 + (pub_r001246_2_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((stage_v_81_2 + (pub_r001246_2_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((sec_r001246_13_1 + (pub_r001246_3_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((sec_r001246_13_2 + (pub_r001246_3_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_73_1 + (pub_r001246_1_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_73_2 + (pub_r001246_1_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_72_1 + (pub_r001246_8_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_72_2 + (pub_r001246_8_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((sec_r001246_0_1 + (pub_r001246_9_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((sec_r001246_0_2 + (pub_r001246_9_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_115_1 + (pub_r001246_8_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_115_2 + (pub_r001246_8_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((stage_v_41_1 + (pub_r001246_5_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((stage_v_41_2 + (pub_r001246_5_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((sec_r001246_8_1 + (pub_r001246_11_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001246_8_2 + (pub_r001246_11_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_115_1 + (pub_r001246_0_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_115_2 + (pub_r001246_0_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_28_1 + (pub_r001246_5_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_28_2 + (pub_r001246_5_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_113_1 + (pub_r001246_8_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_113_2 + (pub_r001246_8_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((helper_flow_2_1 + (pub_r001246_12_1 * 2)) + 377) & 127;
  int stage_v_124_2 = ((helper_flow_2_2 + (pub_r001246_12_2 * 2)) + 377) & 127;
  if (stage_v_124_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_124_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_124_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_124_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_125_1 = ((sec_r001246_8_1 + (pub_r001246_0_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((sec_r001246_8_2 + (pub_r001246_0_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_50_1 + (pub_r001246_5_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_50_2 + (pub_r001246_5_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_61_1 + (pub_r001246_1_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_61_2 + (pub_r001246_1_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((stage_v_70_1 + (pub_r001246_2_1 * 2)) + 389) & 127;
  int stage_v_128_2 = ((stage_v_70_2 + (pub_r001246_2_2 * 2)) + 389) & 127;
  if (stage_v_128_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_128_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_128_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_128_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_129_1 = ((stage_v_61_1 + (pub_r001246_8_1 * 2)) + 392) & 127;
  int stage_v_129_2 = ((stage_v_61_2 + (pub_r001246_8_2 * 2)) + 392) & 127;
  if (stage_v_129_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_129_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_129_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_129_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_130_1 = ((stage_v_54_1 + (pub_r001246_14_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_54_2 + (pub_r001246_14_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001246_14_1 * 2) + 6) & 63;
  int stage_v_131_2 = ((pub_r001246_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_101_1 + (pub_r001246_10_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_101_2 + (pub_r001246_10_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((sec_r001246_21_1 + (pub_r001246_9_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((sec_r001246_21_2 + (pub_r001246_9_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((stage_v_63_1 + (pub_r001246_16_1 * 2)) + 407) & 127;
  int stage_v_134_2 = ((stage_v_63_2 + (pub_r001246_16_2 * 2)) + 407) & 127;
  if (stage_v_134_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_134_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_134_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_134_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_135_1 = ((pub_r001246_3_1 * 2) + 31) & 63;
  int stage_v_135_2 = ((pub_r001246_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((stage_v_124_1 + (pub_r001246_16_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_124_2 + (pub_r001246_16_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((sec_r001246_10_1 + (pub_r001246_13_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((sec_r001246_10_2 + (pub_r001246_13_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001246_16_1 * 2) + 27) & 63;
  int stage_v_138_2 = ((pub_r001246_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((helper_flow_6_1 + (pub_r001246_0_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((helper_flow_6_2 + (pub_r001246_0_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_29_1 + (pub_r001246_8_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_29_2 + (pub_r001246_8_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001246_3_1 * 2) + 36) & 63;
  int stage_v_141_2 = ((pub_r001246_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001246_4_1 * 2) + 38) & 63;
  int stage_v_142_2 = ((pub_r001246_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((stage_v_117_1 + (pub_r001246_4_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_117_2 + (pub_r001246_4_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001246_0_1 * 2) + 16) & 63;
  int stage_v_144_2 = ((pub_r001246_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((stage_v_73_1 + (pub_r001246_2_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_73_2 + (pub_r001246_2_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((helper_flow_2_1 + (pub_r001246_0_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((helper_flow_2_2 + (pub_r001246_0_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_70_1 + (pub_r001246_11_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_70_2 + (pub_r001246_11_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((stage_v_98_1 + (pub_r001246_7_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((stage_v_98_2 + (pub_r001246_7_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_79_1 + (pub_r001246_14_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_79_2 + (pub_r001246_14_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_98_1 + (pub_r001246_8_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_98_2 + (pub_r001246_8_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001246_5_1 * 2) + 6) & 63;
  int stage_v_151_2 = ((pub_r001246_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_14_1 + (pub_r001246_16_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_14_2 + (pub_r001246_16_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((sec_r001246_4_1 + (pub_r001246_6_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((sec_r001246_4_2 + (pub_r001246_6_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((helper_flow_10_1 + (pub_r001246_1_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((helper_flow_10_2 + (pub_r001246_1_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((sec_r001246_0_1 + (pub_r001246_0_1 * 2)) + 470) & 127;
  int stage_v_155_2 = ((sec_r001246_0_2 + (pub_r001246_0_2 * 2)) + 470) & 127;
  if (stage_v_155_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_155_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_155_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_155_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_156_1 = ((stage_v_26_1 + (pub_r001246_7_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_26_2 + (pub_r001246_7_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((helper_flow_5_1 + (pub_r001246_11_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((helper_flow_5_2 + (pub_r001246_11_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((sec_r001246_6_1 + (pub_r001246_0_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((sec_r001246_6_2 + (pub_r001246_0_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001246_14_1 * 2) + 38) & 63;
  int stage_v_159_2 = ((pub_r001246_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001246_1_1 * 2) + 37) & 63;
  int stage_v_160_2 = ((pub_r001246_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_15_1 + (pub_r001246_1_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_15_2 + (pub_r001246_1_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((pub_r001246_14_1 * 2) + 7) & 63;
  int stage_v_162_2 = ((pub_r001246_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001246_8_1 * 2) + 48) & 63;
  int stage_v_163_2 = ((pub_r001246_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_38_1 + (pub_r001246_4_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_38_2 + (pub_r001246_4_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((helper_flow_7_1 + (pub_r001246_9_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((helper_flow_7_2 + (pub_r001246_9_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((pub_r001246_12_1 * 2) + 17) & 63;
  int stage_v_166_2 = ((pub_r001246_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001246_16_1 * 2) + 23) & 63;
  int stage_v_167_2 = ((pub_r001246_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001246_17_1 * 2) + 23) & 63;
  int stage_v_168_2 = ((pub_r001246_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001246_5_1 * 2) + 6) & 63;
  int stage_v_169_2 = ((pub_r001246_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((stage_v_155_1 + (pub_r001246_17_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_155_2 + (pub_r001246_17_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((stage_v_66_1 + (pub_r001246_14_1 * 2)) + 518) & 127;
  int stage_v_171_2 = ((stage_v_66_2 + (pub_r001246_14_2 * 2)) + 518) & 127;
  if (stage_v_171_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_171_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_171_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_171_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_172_1 = ((pub_r001246_2_1 * 2) + 5) & 63;
  int stage_v_172_2 = ((pub_r001246_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001246_7_1 * 2) + 18) & 63;
  int stage_v_173_2 = ((pub_r001246_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_36_1 + (pub_r001246_0_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_36_2 + (pub_r001246_0_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((stage_v_154_1 + (pub_r001246_4_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_154_2 + (pub_r001246_4_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((pub_r001246_10_1 * 2) + 19) & 63;
  int stage_v_176_2 = ((pub_r001246_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001246_14_1 * 2) + 25) & 63;
  int stage_v_177_2 = ((pub_r001246_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((helper_flow_6_1 + (pub_r001246_17_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((helper_flow_6_2 + (pub_r001246_17_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_36_1 + (pub_r001246_12_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_36_2 + (pub_r001246_12_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((stage_v_103_1 + (pub_r001246_16_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((stage_v_103_2 + (pub_r001246_16_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((helper_flow_2_1 + (pub_r001246_16_1 * 2)) + 548) & 127;
  int stage_v_181_2 = ((helper_flow_2_2 + (pub_r001246_16_2 * 2)) + 548) & 127;
  if (stage_v_181_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_181_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_181_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_181_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_182_1 = ((pub_r001246_0_1 * 2) + 36) & 63;
  int stage_v_182_2 = ((pub_r001246_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((stage_v_39_1 + (pub_r001246_5_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_39_2 + (pub_r001246_5_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001246_15_1 * 2) + 32) & 63;
  int stage_v_184_2 = ((pub_r001246_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001246_12_1 * 2) + 42) & 63;
  int stage_v_185_2 = ((pub_r001246_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((stage_v_156_1 + (pub_r001246_11_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((stage_v_156_2 + (pub_r001246_11_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((pub_r001246_15_1 * 2) + 31) & 63;
  int stage_v_187_2 = ((pub_r001246_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((helper_flow_0_1 + (pub_r001246_16_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((helper_flow_0_2 + (pub_r001246_16_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001246_2_1 * 2) + 28) & 63;
  int stage_v_189_2 = ((pub_r001246_2_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((stage_v_10_1 + (pub_r001246_17_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((stage_v_10_2 + (pub_r001246_17_2 * 2)) + 575) & 127;
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
  int stage_v_191_1 = ((pub_r001246_0_1 * 2) + 12) & 63;
  int stage_v_191_2 = ((pub_r001246_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001246_0_1 * 2) + 34) & 63;
  int stage_v_192_2 = ((pub_r001246_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((sec_r001246_22_1 + (pub_r001246_14_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((sec_r001246_22_2 + (pub_r001246_14_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_3_1 + (pub_r001246_4_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_3_2 + (pub_r001246_4_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((pub_r001246_16_1 * 2) + 44) & 63;
  int stage_v_195_2 = ((pub_r001246_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001246_17_1 * 2) + 45) & 63;
  int stage_v_196_2 = ((pub_r001246_17_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((stage_v_116_1 + (pub_r001246_9_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_116_2 + (pub_r001246_9_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((stage_v_105_1 + (pub_r001246_1_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((stage_v_105_2 + (pub_r001246_1_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_108_1 + (pub_r001246_13_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_108_2 + (pub_r001246_13_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((pub_r001246_10_1 * 2) + 36) & 63;
  int stage_v_200_2 = ((pub_r001246_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((sec_r001246_0_1 + (pub_r001246_3_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001246_0_2 + (pub_r001246_3_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001246_7_1 * 2) + 7) & 63;
  int stage_v_202_2 = ((pub_r001246_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001246_6_1 * 2) + 25) & 63;
  int stage_v_203_2 = ((pub_r001246_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((stage_v_105_1 + (pub_r001246_17_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_105_2 + (pub_r001246_17_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((stage_v_15_1 + (pub_r001246_4_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_15_2 + (pub_r001246_4_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((sec_r001246_18_1 + (pub_r001246_7_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((sec_r001246_18_2 + (pub_r001246_7_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((sec_r001246_7_1 + (pub_r001246_15_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001246_7_2 + (pub_r001246_15_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_133_1 + (pub_r001246_9_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_133_2 + (pub_r001246_9_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_5_1 + (pub_r001246_9_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_5_2 + (pub_r001246_9_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((pub_r001246_12_1 * 2) + 45) & 63;
  int stage_v_210_2 = ((pub_r001246_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((stage_v_32_1 + (pub_r001246_12_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_32_2 + (pub_r001246_12_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001246_16_1 * 2) + 6) & 63;
  int stage_v_212_2 = ((pub_r001246_16_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((stage_v_137_1 + (pub_r001246_7_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((stage_v_137_2 + (pub_r001246_7_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((stage_v_16_1 + (pub_r001246_0_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_16_2 + (pub_r001246_0_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((helper_flow_0_1 + (pub_r001246_16_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((helper_flow_0_2 + (pub_r001246_16_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_11_1 + (pub_r001246_10_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_11_2 + (pub_r001246_10_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001246_10_1 == pub_r001246_10_2);
  __CPROVER_assume(pub_r001246_4_1 == pub_r001246_4_2);
  __CPROVER_assume(sec_r001246_13_1 != sec_r001246_13_2);
  __CPROVER_assume(pub_r001246_14_1 == pub_r001246_14_2);
  __CPROVER_assume(pub_r001246_5_1 == pub_r001246_5_2);
  __CPROVER_assume(pub_r001246_16_1 == pub_r001246_16_2);
  __CPROVER_assume(pub_r001246_7_1 == pub_r001246_7_2);
  __CPROVER_assume(sec_r001246_11_1 != sec_r001246_11_2);
  __CPROVER_assume(pub_r001246_0_1 == pub_r001246_0_2);
  __CPROVER_assume(pub_r001246_11_1 == pub_r001246_11_2);
  __CPROVER_assume(sec_r001246_12_1 != sec_r001246_12_2);
  __CPROVER_assume(pub_r001246_13_1 == pub_r001246_13_2);
  __CPROVER_assume(sec_r001246_6_1 != sec_r001246_6_2);
  __CPROVER_assume(sec_r001246_15_1 != sec_r001246_15_2);
  __CPROVER_assume(sec_r001246_17_1 != sec_r001246_17_2);
  __CPROVER_assume(sec_r001246_7_1 != sec_r001246_7_2);
  __CPROVER_assume(sec_r001246_22_1 != sec_r001246_22_2);
  __CPROVER_assume(sec_r001246_9_1 != sec_r001246_9_2);
  __CPROVER_assume(sec_r001246_10_1 != sec_r001246_10_2);
  __CPROVER_assume(sec_r001246_8_1 != sec_r001246_8_2);
  __CPROVER_assume(sec_r001246_19_1 != sec_r001246_19_2);
  __CPROVER_assume(pub_r001246_6_1 == pub_r001246_6_2);
  __CPROVER_assume(pub_r001246_8_1 == pub_r001246_8_2);
  __CPROVER_assume(sec_r001246_4_1 != sec_r001246_4_2);
  __CPROVER_assume(sec_r001246_14_1 != sec_r001246_14_2);
  __CPROVER_assume(pub_r001246_3_1 == pub_r001246_3_2);
  __CPROVER_assume(sec_r001246_1_1 != sec_r001246_1_2);
  __CPROVER_assume(sec_r001246_0_1 != sec_r001246_0_2);
  __CPROVER_assume(sec_r001246_20_1 != sec_r001246_20_2);
  __CPROVER_assume(sec_r001246_2_1 != sec_r001246_2_2);
  __CPROVER_assume(sec_r001246_16_1 != sec_r001246_16_2);
  __CPROVER_assume(sec_r001246_21_1 != sec_r001246_21_2);
  __CPROVER_assume(pub_r001246_12_1 == pub_r001246_12_2);
  __CPROVER_assume(pub_r001246_1_1 == pub_r001246_1_2);
  __CPROVER_assume(pub_r001246_17_1 == pub_r001246_17_2);
  __CPROVER_assume(pub_r001246_9_1 == pub_r001246_9_2);
  __CPROVER_assume(sec_r001246_3_1 != sec_r001246_3_2);
  __CPROVER_assume(sec_r001246_5_1 != sec_r001246_5_2);
  __CPROVER_assume(sec_r001246_18_1 != sec_r001246_18_2);
  __CPROVER_assume(pub_r001246_15_1 == pub_r001246_15_2);
  __CPROVER_assume(pub_r001246_2_1 == pub_r001246_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  assert(st_var_0_1.seq == st_var_0_2.seq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.auth_code == st_var_2_2.auth_code);
  assert(st_var_2_1.balance == st_var_2_2.balance);
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
}


