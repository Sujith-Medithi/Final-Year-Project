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
struct Vector3D_R000690_9013_0
{
  int coord_x;
  int coord_z;
  unsigned char norm_sq;
  int pitch;
  int buffer[3];
};
struct EventLog_R000690_9013_1
{
  int seq;
  int timestamp;
  short facility;
  unsigned char severity;
  int code;
  int buffer[3];
};
struct Transaction_R000690_9013_2
{
  unsigned char balance;
  int account_id;
  unsigned char fee;
  int status;
  int rate;
  int buffer[3];
};
union PacketPayload_R000690_9013_0
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
void fn_R000690_9013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_19_1 = local_arr_1[aux_1 % 3];
  int index_reg_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_19_2 * 2)) & 127;
  int quotient_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_63_1) & 63;
  aux_2 = (aux_2 + quotient_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_96_1 = 0;
  int margin_96_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_96_1 = ((margin_96_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_96_2 = ((margin_96_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_96_1) & 127;
    acc_2 = (acc_2 + margin_96_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_19_1 == index_reg_19_2);
  assert(quotient_63_1 == quotient_63_2);
  assert(margin_96_1 == margin_96_2);
}

int fn_R000690_9013_0(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int index_reg_19 = local_arr[aux % 3];
  acc = (acc + (index_reg_19 * 2)) & 127;
  int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_63) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_96 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_96 = ((margin_96 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_96) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000690_9013_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st_1 = {0};
  struct Vector3D_R000690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int parity_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_48_1) & 63;
  aux_2 = (aux_2 + parity_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_59_1)
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

  switch (parity_59_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_48_1 == parity_48_2);
  assert(parity_59_1 == parity_59_2);
}

int fn_R000690_9013_1(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int parity_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_48) & 63;
  acc ^= aux;
  int parity_59 = (aux + st.buffer[1]) & 3;
  switch (parity_59)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int pivot_95_1 = 0;
  int pivot_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_95_1 = ((pivot_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_95_2 = ((pivot_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_95_1) & 127;
    acc_2 = (acc_2 + pivot_95_2) & 127;
  }

  int parity_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_22_1) & 63;
  aux_2 = (aux_2 + parity_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_27_1 = local_arr_1[aux_1 % 3];
  int parity_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_95_1 == pivot_95_2);
  assert(parity_22_1 == parity_22_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_27_1 == parity_27_2);
}

int fn_R000690_9013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int pivot_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_95 = ((pivot_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_95) & 127;
  }

  int parity_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_22) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int parity_27 = local_arr[aux % 3];
  acc = (acc + (parity_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tally_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_88_1) & 63;
  aux_2 = (aux_2 + tally_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_81_1 > 20)
  {
    acc_1 = ((acc_1 + (stride_81_1 * 2)) + 5) & 127;
    aux_1 ^= stride_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_81_2 > 20)
  {
    acc_2 = ((acc_2 + (stride_81_2 * 2)) + 5) & 127;
    aux_2 ^= stride_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_88_1 == tally_88_2);
  assert(stride_81_1 == stride_81_2);
}

int fn_R000690_9013_3(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tally_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_88) & 63;
  acc ^= aux;
  int stride_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_81 > 20)
  {
    acc = ((acc + (stride_81 * 2)) + 5) & 127;
    aux ^= stride_81 & 15;
  }
  else
  {
    acc = ((acc - stride_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int coefficient_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_37_1)
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

  switch (coefficient_37_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_26_1 = local_arr_1[aux_1 % 3];
  int segment_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_26_2 * 2)) & 127;
  int delta_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_86_1 > 43)
  {
    acc_1 = ((acc_1 + (delta_86_1 * 2)) + 5) & 127;
    aux_1 ^= delta_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_86_2 > 43)
  {
    acc_2 = ((acc_2 + (delta_86_2 * 2)) + 5) & 127;
    aux_2 ^= delta_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_37_1 == coefficient_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_26_1 == segment_26_2);
  assert(delta_86_1 == delta_86_2);
}

int fn_R000690_9013_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int coefficient_37 = (aux + st.buffer[1]) & 3;
  switch (coefficient_37)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int segment_26 = local_arr[aux % 3];
  acc = (acc + (segment_26 * 2)) & 127;
  int delta_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_86 > 43)
  {
    acc = ((acc + (delta_86 * 2)) + 5) & 127;
    aux ^= delta_86 & 15;
  }
  else
  {
    acc = ((acc - delta_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st_1 = {0};
  struct Vector3D_R000690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int metric_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_42_1)
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

  switch (metric_42_2)
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

  int tally_68_1 = 0;
  int tally_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_68_1 = ((tally_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_68_2 = ((tally_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_68_1) & 127;
    acc_2 = (acc_2 + tally_68_2) & 127;
  }

  int parity_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_76_1 > 48)
  {
    acc_1 = ((acc_1 + (parity_76_1 * 2)) + 5) & 127;
    aux_1 ^= parity_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_76_2 > 48)
  {
    acc_2 = ((acc_2 + (parity_76_2 * 2)) + 5) & 127;
    aux_2 ^= parity_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_32_1) & 63;
  aux_2 = (aux_2 + bound_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_42_1 == metric_42_2);
  assert(tally_68_1 == tally_68_2);
  assert(parity_76_1 == parity_76_2);
  assert(bound_32_1 == bound_32_2);
}

int fn_R000690_9013_5(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int metric_42 = (aux + st.buffer[1]) & 3;
  switch (metric_42)
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

  int tally_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_68 = ((tally_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_68) & 127;
  }

  int parity_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_76 > 48)
  {
    acc = ((acc + (parity_76 * 2)) + 5) & 127;
    aux ^= parity_76 & 15;
  }
  else
  {
    acc = ((acc - parity_76) + 11) & 127;
    aux += 3;
  }
  int bound_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_32) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000690_9013_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tracker_44_1 = 0;
  int tracker_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_44_1 = ((tracker_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_44_2 = ((tracker_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_44_1) & 127;
    acc_2 = (acc_2 + tracker_44_2) & 127;
  }

  int index_reg_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_36_1) & 63;
  aux_2 = (aux_2 + index_reg_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_47_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_47_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_47_1 > 19)
  {
    acc_1 = ((acc_1 + (damping_47_1 * 2)) + 5) & 127;
    aux_1 ^= damping_47_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_47_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_47_2 > 19)
  {
    acc_2 = ((acc_2 + (damping_47_2 * 2)) + 5) & 127;
    aux_2 ^= damping_47_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_47_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_44_1 == tracker_44_2);
  assert(index_reg_36_1 == index_reg_36_2);
  assert(damping_47_1 == damping_47_2);
}

int fn_R000690_9013_6(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tracker_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_44 = ((tracker_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_44) & 127;
  }

  int index_reg_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_36) & 63;
  acc ^= aux;
  int damping_47 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_47 > 19)
  {
    acc = ((acc + (damping_47 * 2)) + 5) & 127;
    aux ^= damping_47 & 15;
  }
  else
  {
    acc = ((acc - damping_47) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_60_1 = local_arr_1[aux_1 % 3];
  int margin_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_60_2 * 2)) & 127;
  int damping_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_46_1)
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

  switch (damping_46_2)
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

  int quotient_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_23_1) & 63;
  aux_2 = (aux_2 + quotient_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_53_1 = 0;
  int mask_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_53_1 = ((mask_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_53_2 = ((mask_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_53_1) & 127;
    acc_2 = (acc_2 + mask_53_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_60_1 == margin_60_2);
  assert(damping_46_1 == damping_46_2);
  assert(quotient_23_1 == quotient_23_2);
  assert(mask_53_1 == mask_53_2);
}

int fn_R000690_9013_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int margin_60 = local_arr[aux % 3];
  acc = (acc + (margin_60 * 2)) & 127;
  int damping_46 = (aux + st.buffer[1]) & 3;
  switch (damping_46)
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

  int quotient_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_23) & 63;
  acc ^= aux;
  int mask_53 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_53 = ((mask_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_53) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000690_9013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_16_1 = local_arr_1[aux_1 % 3];
  int pivot_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_16_2 * 2)) & 127;
  int window_13_1 = 0;
  int window_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_13_1 = ((window_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_13_2 = ((window_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_13_1) & 127;
    acc_2 = (acc_2 + window_13_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_16_1 == pivot_16_2);
  assert(window_13_1 == window_13_2);
}

int fn_R000690_9013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_16 = local_arr[aux % 3];
  acc = (acc + (pivot_16 * 2)) & 127;
  int window_13 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_13 = ((window_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_13) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000690_9013_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int residue_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_24_1) & 63;
  aux_2 = (aux_2 + residue_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_66_1 > 45)
  {
    acc_1 = ((acc_1 + (damping_66_1 * 2)) + 5) & 127;
    aux_1 ^= damping_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_66_2 > 45)
  {
    acc_2 = ((acc_2 + (damping_66_2 * 2)) + 5) & 127;
    aux_2 ^= damping_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_66_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_28_1 = local_arr_1[aux_1 % 3];
  int anchor_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_24_1 == residue_24_2);
  assert(damping_66_1 == damping_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_28_1 == anchor_28_2);
}

int fn_R000690_9013_9(int p0, int p1, int p2)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_24) & 63;
  acc ^= aux;
  int damping_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_66 > 45)
  {
    acc = ((acc + (damping_66 * 2)) + 5) & 127;
    aux ^= damping_66 & 15;
  }
  else
  {
    acc = ((acc - damping_66) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_28 = local_arr[aux % 3];
  acc = (acc + (anchor_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_69_1)
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

  switch (offset_69_2)
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

  int margin_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_12_1 > 13)
  {
    acc_1 = ((acc_1 + (margin_12_1 * 2)) + 5) & 127;
    aux_1 ^= margin_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_12_2 > 13)
  {
    acc_2 = ((acc_2 + (margin_12_2 * 2)) + 5) & 127;
    aux_2 ^= margin_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_12_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_44_1 = local_arr_1[aux_1 % 3];
  int quotient_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_44_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_69_1 == offset_69_2);
  assert(margin_12_1 == margin_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_44_1 == quotient_44_2);
}

int fn_R000690_9013_10(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_69 = (aux + st.buffer[1]) & 3;
  switch (offset_69)
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

  int margin_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_12 > 13)
  {
    acc = ((acc + (margin_12 * 2)) + 5) & 127;
    aux ^= margin_12 & 15;
  }
  else
  {
    acc = ((acc - margin_12) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int quotient_44 = local_arr[aux % 3];
  acc = (acc + (quotient_44 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_37_1 = local_arr_1[aux_1 % 3];
  int index_reg_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_37_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_37_1 == index_reg_37_2);
}

int fn_R000690_9013_11(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int index_reg_37 = local_arr[aux % 3];
  acc = (acc + (index_reg_37 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_28_1 = local_arr_1[aux_1 % 3];
  int margin_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_28_2 * 2)) & 127;
  int weight_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_50_1)
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

  switch (weight_50_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_34_1 = 0;
  int threshold_34_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_34_1 = ((threshold_34_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_34_2 = ((threshold_34_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_34_1) & 127;
    acc_2 = (acc_2 + threshold_34_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_28_1 == margin_28_2);
  assert(weight_50_1 == weight_50_2);
  assert(threshold_34_1 == threshold_34_2);
}

int fn_R000690_9013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int margin_28 = local_arr[aux % 3];
  acc = (acc + (margin_28 * 2)) & 127;
  int weight_50 = (aux + st.buffer[1]) & 3;
  switch (weight_50)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_34 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_34 = ((threshold_34 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_34) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R000690_9013_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_29_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_29_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_29_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_29_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_29_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_29_1 == anchor_29_2);
}

int fn_R000690_9013_13(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_29 > 49)
  {
    acc = ((acc + (anchor_29 * 2)) + 5) & 127;
    aux ^= anchor_29 & 15;
  }
  else
  {
    acc = ((acc - anchor_29) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_51_1 = 0;
  int weight_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_51_1 = ((weight_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_51_2 = ((weight_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_51_1) & 127;
    acc_2 = (acc_2 + weight_51_2) & 127;
  }

  int threshold_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_51_1 > 40)
  {
    acc_1 = ((acc_1 + (threshold_51_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_51_2 > 40)
  {
    acc_2 = ((acc_2 + (threshold_51_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_51_1 == weight_51_2);
  assert(threshold_51_1 == threshold_51_2);
}

int fn_R000690_9013_14(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_51 = ((weight_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_51) & 127;
  }

  int threshold_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_51 > 40)
  {
    acc = ((acc + (threshold_51 * 2)) + 5) & 127;
    aux ^= threshold_51 & 15;
  }
  else
  {
    acc = ((acc - threshold_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_61_1 = local_arr_1[aux_1 % 3];
  int sample_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_61_2 * 2)) & 127;
  int tally_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_73_1 > 19)
  {
    acc_1 = ((acc_1 + (tally_73_1 * 2)) + 5) & 127;
    aux_1 ^= tally_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_73_2 > 19)
  {
    acc_2 = ((acc_2 + (tally_73_2 * 2)) + 5) & 127;
    aux_2 ^= tally_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_59_1) & 63;
  aux_2 = (aux_2 + stride_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_61_1 == sample_61_2);
  assert(tally_73_1 == tally_73_2);
  assert(stride_59_1 == stride_59_2);
}

int fn_R000690_9013_15(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_61 = local_arr[aux % 3];
  acc = (acc + (sample_61 * 2)) & 127;
  int tally_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_73 > 19)
  {
    acc = ((acc + (tally_73 * 2)) + 5) & 127;
    aux ^= tally_73 & 15;
  }
  else
  {
    acc = ((acc - tally_73) + 11) & 127;
    aux += 3;
  }
  int stride_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_59) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st_1 = {0};
  struct Vector3D_R000690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int damping_16_1 = 0;
  int damping_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_16_1 = ((damping_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_16_2 = ((damping_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_16_1) & 127;
    acc_2 = (acc_2 + damping_16_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_30_1 = local_arr_1[aux_1 % 3];
  int anchor_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_30_2 * 2)) & 127;
  int residue_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_22_1)
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

  switch (residue_22_2)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_16_1 == damping_16_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_30_1 == anchor_30_2);
  assert(residue_22_1 == residue_22_2);
}

int fn_R000690_9013_16(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int damping_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_16 = ((damping_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_16) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_30 = local_arr[aux % 3];
  acc = (acc + (anchor_30 * 2)) & 127;
  int residue_22 = (aux + st.buffer[1]) & 3;
  switch (residue_22)
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

void fn_R000690_9013_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_91_1 = local_arr_1[aux_1 % 3];
  int residue_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_91_2 * 2)) & 127;
  int phase_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_85_1) & 63;
  aux_2 = (aux_2 + phase_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_68_1)
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

  switch (cursor_68_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_91_1 == residue_91_2);
  assert(phase_85_1 == phase_85_2);
  assert(cursor_68_1 == cursor_68_2);
}

int fn_R000690_9013_17(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int residue_91 = local_arr[aux % 3];
  acc = (acc + (residue_91 * 2)) & 127;
  int phase_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_85) & 63;
  acc ^= aux;
  int cursor_68 = (aux + st.buffer[1]) & 3;
  switch (cursor_68)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000690_9013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_39_1 = local_arr_1[aux_1 % 3];
  int bound_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_39_2 * 2)) & 127;
  int stride_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_81_1 > 37)
  {
    acc_1 = ((acc_1 + (stride_81_1 * 2)) + 5) & 127;
    aux_1 ^= stride_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_81_2 > 37)
  {
    acc_2 = ((acc_2 + (stride_81_2 * 2)) + 5) & 127;
    aux_2 ^= stride_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_81_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_39_1 == bound_39_2);
  assert(stride_81_1 == stride_81_2);
}

int fn_R000690_9013_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_39 = local_arr[aux % 3];
  acc = (acc + (bound_39 * 2)) & 127;
  int stride_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_81 > 37)
  {
    acc = ((acc + (stride_81 * 2)) + 5) & 127;
    aux ^= stride_81 & 15;
  }
  else
  {
    acc = ((acc - stride_81) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_12_1 > 33)
  {
    acc_1 = ((acc_1 + (residue_12_1 * 2)) + 5) & 127;
    aux_1 ^= residue_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_12_2 > 33)
  {
    acc_2 = ((acc_2 + (residue_12_2 * 2)) + 5) & 127;
    aux_2 ^= residue_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_67_1 = local_arr_1[aux_1 % 3];
  int quantum_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_67_2 * 2)) & 127;
  int metric_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_63_1) & 63;
  aux_2 = (aux_2 + metric_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_12_1 == residue_12_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_67_1 == quantum_67_2);
  assert(metric_63_1 == metric_63_2);
}

int fn_R000690_9013_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_12 > 33)
  {
    acc = ((acc + (residue_12 * 2)) + 5) & 127;
    aux ^= residue_12 & 15;
  }
  else
  {
    acc = ((acc - residue_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_67 = local_arr[aux % 3];
  acc = (acc + (quantum_67 * 2)) & 127;
  int metric_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000690_9013_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st_1 = {0};
  struct EventLog_R000690_9013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_46_1) & 63;
  aux_2 = (aux_2 + pivot_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_88_1 > 20)
  {
    acc_1 = ((acc_1 + (stride_88_1 * 2)) + 5) & 127;
    aux_1 ^= stride_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_88_2 > 20)
  {
    acc_2 = ((acc_2 + (stride_88_2 * 2)) + 5) & 127;
    aux_2 ^= stride_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_88_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.seq == st_2.seq);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_46_1 == pivot_46_2);
  assert(stride_88_1 == stride_88_2);
}

int fn_R000690_9013_20(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000690_9013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_46) & 63;
  acc ^= aux;
  int stride_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_88 > 20)
  {
    acc = ((acc + (stride_88 * 2)) + 5) & 127;
    aux ^= stride_88 & 15;
  }
  else
  {
    acc = ((acc - stride_88) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st_1 = {0};
  struct Vector3D_R000690_9013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_25_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_25_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_25_1) & 63;
  aux_2 = (aux_2 + sample_25_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_48_1)
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

  switch (weight_48_2)
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

  int checksum_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_82_1 > 48)
  {
    acc_1 = ((acc_1 + (checksum_82_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_82_2 > 48)
  {
    acc_2 = ((acc_2 + (checksum_82_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_25_1 == sample_25_2);
  assert(weight_48_1 == weight_48_2);
  assert(checksum_82_1 == checksum_82_2);
}

int fn_R000690_9013_21(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000690_9013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_25 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_25) & 63;
  acc ^= aux;
  int weight_48 = (aux + st.buffer[1]) & 3;
  switch (weight_48)
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

  int checksum_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_82 > 48)
  {
    acc = ((acc + (checksum_82 * 2)) + 5) & 127;
    aux ^= checksum_82 & 15;
  }
  else
  {
    acc = ((acc - checksum_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000690_9013_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st_1 = {0};
  struct Transaction_R000690_9013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int tracker_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_17_1 > 17)
  {
    acc_1 = ((acc_1 + (tracker_17_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_17_2 > 17)
  {
    acc_2 = ((acc_2 + (tracker_17_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_17_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.balance == st_2.balance);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  assert(st_1.rate == st_2.rate);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_17_1 == tracker_17_2);
}

int fn_R000690_9013_22(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000690_9013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int tracker_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_17 > 17)
  {
    acc = ((acc + (tracker_17 * 2)) + 5) & 127;
    aux ^= tracker_17 & 15;
  }
  else
  {
    acc = ((acc - tracker_17) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000690_0_1;
  int sec_r000690_0_2;
  int sec_r000690_1_1;
  int sec_r000690_1_2;
  int sec_r000690_2_1;
  int sec_r000690_2_2;
  int sec_r000690_3_1;
  int sec_r000690_3_2;
  int sec_r000690_4_1;
  int sec_r000690_4_2;
  int sec_r000690_5_1;
  int sec_r000690_5_2;
  int sec_r000690_6_1;
  int sec_r000690_6_2;
  int sec_r000690_7_1;
  int sec_r000690_7_2;
  int sec_r000690_8_1;
  int sec_r000690_8_2;
  int sec_r000690_9_1;
  int sec_r000690_9_2;
  int sec_r000690_10_1;
  int sec_r000690_10_2;
  int sec_r000690_11_1;
  int sec_r000690_11_2;
  int sec_r000690_12_1;
  int sec_r000690_12_2;
  int sec_r000690_13_1;
  int sec_r000690_13_2;
  int sec_r000690_14_1;
  int sec_r000690_14_2;
  int sec_r000690_15_1;
  int sec_r000690_15_2;
  int sec_r000690_16_1;
  int sec_r000690_16_2;
  int pub_r000690_0_1;
  int pub_r000690_0_2;
  int pub_r000690_1_1;
  int pub_r000690_1_2;
  int pub_r000690_2_1;
  int pub_r000690_2_2;
  int pub_r000690_3_1;
  int pub_r000690_3_2;
  int pub_r000690_4_1;
  int pub_r000690_4_2;
  int pub_r000690_5_1;
  int pub_r000690_5_2;
  int pub_r000690_6_1;
  int pub_r000690_6_2;
  int pub_r000690_7_1;
  int pub_r000690_7_2;
  int pub_r000690_8_1;
  int pub_r000690_8_2;
  int pub_r000690_9_1;
  int pub_r000690_9_2;
  int pub_r000690_10_1;
  int pub_r000690_10_2;
  int pub_r000690_11_1;
  int pub_r000690_11_2;
  int pub_r000690_12_1;
  int pub_r000690_12_2;
  int pub_r000690_13_1;
  int pub_r000690_13_2;
  int pub_r000690_14_1;
  int pub_r000690_14_2;
  int pub_r000690_15_1;
  int pub_r000690_15_2;
  int pub_r000690_16_1;
  int pub_r000690_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  __CPROVER_assume((pub_r000690_0_1 >= (-100)) && (pub_r000690_0_1 <= 100));
  __CPROVER_assume((pub_r000690_0_2 >= (-100)) && (pub_r000690_0_2 <= 100));
  __CPROVER_assume((pub_r000690_1_1 >= (-100)) && (pub_r000690_1_1 <= 100));
  __CPROVER_assume((pub_r000690_1_2 >= (-100)) && (pub_r000690_1_2 <= 100));
  __CPROVER_assume((pub_r000690_2_1 >= (-100)) && (pub_r000690_2_1 <= 100));
  __CPROVER_assume((pub_r000690_2_2 >= (-100)) && (pub_r000690_2_2 <= 100));
  __CPROVER_assume((pub_r000690_3_1 >= (-100)) && (pub_r000690_3_1 <= 100));
  __CPROVER_assume((pub_r000690_3_2 >= (-100)) && (pub_r000690_3_2 <= 100));
  __CPROVER_assume((pub_r000690_4_1 >= (-100)) && (pub_r000690_4_1 <= 100));
  __CPROVER_assume((pub_r000690_4_2 >= (-100)) && (pub_r000690_4_2 <= 100));
  __CPROVER_assume((pub_r000690_5_1 >= (-100)) && (pub_r000690_5_1 <= 100));
  __CPROVER_assume((pub_r000690_5_2 >= (-100)) && (pub_r000690_5_2 <= 100));
  __CPROVER_assume((pub_r000690_6_1 >= (-100)) && (pub_r000690_6_1 <= 100));
  __CPROVER_assume((pub_r000690_6_2 >= (-100)) && (pub_r000690_6_2 <= 100));
  __CPROVER_assume((pub_r000690_7_1 >= (-100)) && (pub_r000690_7_1 <= 100));
  __CPROVER_assume((pub_r000690_7_2 >= (-100)) && (pub_r000690_7_2 <= 100));
  __CPROVER_assume((pub_r000690_8_1 >= (-100)) && (pub_r000690_8_1 <= 100));
  __CPROVER_assume((pub_r000690_8_2 >= (-100)) && (pub_r000690_8_2 <= 100));
  __CPROVER_assume((pub_r000690_9_1 >= (-100)) && (pub_r000690_9_1 <= 100));
  __CPROVER_assume((pub_r000690_9_2 >= (-100)) && (pub_r000690_9_2 <= 100));
  __CPROVER_assume((pub_r000690_10_1 >= (-100)) && (pub_r000690_10_1 <= 100));
  __CPROVER_assume((pub_r000690_10_2 >= (-100)) && (pub_r000690_10_2 <= 100));
  __CPROVER_assume((pub_r000690_11_1 >= (-100)) && (pub_r000690_11_1 <= 100));
  __CPROVER_assume((pub_r000690_11_2 >= (-100)) && (pub_r000690_11_2 <= 100));
  __CPROVER_assume((pub_r000690_12_1 >= (-100)) && (pub_r000690_12_1 <= 100));
  __CPROVER_assume((pub_r000690_12_2 >= (-100)) && (pub_r000690_12_2 <= 100));
  __CPROVER_assume((pub_r000690_13_1 >= (-100)) && (pub_r000690_13_1 <= 100));
  __CPROVER_assume((pub_r000690_13_2 >= (-100)) && (pub_r000690_13_2 <= 100));
  __CPROVER_assume((pub_r000690_14_1 >= (-100)) && (pub_r000690_14_1 <= 100));
  __CPROVER_assume((pub_r000690_14_2 >= (-100)) && (pub_r000690_14_2 <= 100));
  __CPROVER_assume((pub_r000690_15_1 >= (-100)) && (pub_r000690_15_1 <= 100));
  __CPROVER_assume((pub_r000690_15_2 >= (-100)) && (pub_r000690_15_2 <= 100));
  __CPROVER_assume((pub_r000690_16_1 >= (-100)) && (pub_r000690_16_1 <= 100));
  __CPROVER_assume((pub_r000690_16_2 >= (-100)) && (pub_r000690_16_2 <= 100));
  __CPROVER_assume((sec_r000690_0_1 >= 0) && (sec_r000690_0_1 <= 255));
  __CPROVER_assume((sec_r000690_0_2 >= 0) && (sec_r000690_0_2 <= 255));
  __CPROVER_assume((sec_r000690_1_1 >= 0) && (sec_r000690_1_1 <= 255));
  __CPROVER_assume((sec_r000690_1_2 >= 0) && (sec_r000690_1_2 <= 255));
  __CPROVER_assume((sec_r000690_2_1 >= 0) && (sec_r000690_2_1 <= 255));
  __CPROVER_assume((sec_r000690_2_2 >= 0) && (sec_r000690_2_2 <= 255));
  __CPROVER_assume((sec_r000690_3_1 >= 0) && (sec_r000690_3_1 <= 255));
  __CPROVER_assume((sec_r000690_3_2 >= 0) && (sec_r000690_3_2 <= 255));
  __CPROVER_assume((sec_r000690_4_1 >= 0) && (sec_r000690_4_1 <= 255));
  __CPROVER_assume((sec_r000690_4_2 >= 0) && (sec_r000690_4_2 <= 255));
  __CPROVER_assume((sec_r000690_5_1 >= 0) && (sec_r000690_5_1 <= 255));
  __CPROVER_assume((sec_r000690_5_2 >= 0) && (sec_r000690_5_2 <= 255));
  __CPROVER_assume((sec_r000690_6_1 >= 0) && (sec_r000690_6_1 <= 255));
  __CPROVER_assume((sec_r000690_6_2 >= 0) && (sec_r000690_6_2 <= 255));
  __CPROVER_assume((sec_r000690_7_1 >= 0) && (sec_r000690_7_1 <= 255));
  __CPROVER_assume((sec_r000690_7_2 >= 0) && (sec_r000690_7_2 <= 255));
  __CPROVER_assume((sec_r000690_8_1 >= 0) && (sec_r000690_8_1 <= 255));
  __CPROVER_assume((sec_r000690_8_2 >= 0) && (sec_r000690_8_2 <= 255));
  __CPROVER_assume((sec_r000690_9_1 >= 0) && (sec_r000690_9_1 <= 255));
  __CPROVER_assume((sec_r000690_9_2 >= 0) && (sec_r000690_9_2 <= 255));
  __CPROVER_assume((sec_r000690_10_1 >= 0) && (sec_r000690_10_1 <= 255));
  __CPROVER_assume((sec_r000690_10_2 >= 0) && (sec_r000690_10_2 <= 255));
  __CPROVER_assume((sec_r000690_11_1 >= 0) && (sec_r000690_11_1 <= 255));
  __CPROVER_assume((sec_r000690_11_2 >= 0) && (sec_r000690_11_2 <= 255));
  __CPROVER_assume((sec_r000690_12_1 >= 0) && (sec_r000690_12_1 <= 255));
  __CPROVER_assume((sec_r000690_12_2 >= 0) && (sec_r000690_12_2 <= 255));
  __CPROVER_assume((sec_r000690_13_1 >= 0) && (sec_r000690_13_1 <= 255));
  __CPROVER_assume((sec_r000690_13_2 >= 0) && (sec_r000690_13_2 <= 255));
  __CPROVER_assume((sec_r000690_14_1 >= 0) && (sec_r000690_14_1 <= 255));
  __CPROVER_assume((sec_r000690_14_2 >= 0) && (sec_r000690_14_2 <= 255));
  __CPROVER_assume((sec_r000690_15_1 >= 0) && (sec_r000690_15_1 <= 255));
  __CPROVER_assume((sec_r000690_15_2 >= 0) && (sec_r000690_15_2 <= 255));
  __CPROVER_assume((sec_r000690_16_1 >= 0) && (sec_r000690_16_1 <= 255));
  __CPROVER_assume((sec_r000690_16_2 >= 0) && (sec_r000690_16_2 <= 255));
  struct Vector3D_R000690_9013_0 st_var_0_1 = {0};
  struct Vector3D_R000690_9013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000690_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000690_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000690_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000690_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000690_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000690_0_2 + 7) & 15;
  struct EventLog_R000690_9013_1 st_var_1_1 = {0};
  struct EventLog_R000690_9013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000690_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000690_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000690_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000690_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000690_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000690_0_2 + 9) & 15;
  struct Transaction_R000690_9013_2 st_var_2_1 = {0};
  struct Transaction_R000690_9013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000690_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000690_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000690_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000690_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000690_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000690_0_2 + 11) & 15;
  union PacketPayload_R000690_9013_0 u_var_1;
  union PacketPayload_R000690_9013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_1_1 = table_1[1];
  int stage_v_1_2 = table_2[1];
  table_1[1] = (table_1[2] + 3) & 63;
  table_2[1] = (table_2[2] + 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 4) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (9 & 31);
  int stage_v_4_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (9 & 31);
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= (stage_v_4_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_4_2 << 1) & 127;
  int stage_v_5_1 = (st_var_2_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_2_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
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

  switch (stage_v_5_2)
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

  int stage_v_6_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (11 & 31);
  int stage_v_6_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (11 & 31);
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= (stage_v_6_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_6_2 << 1) & 127;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 37)
    {
      chk_sum_1 ^= stage_v_7_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_7_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 37)
    {
      chk_sum_2 ^= stage_v_7_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_8_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (13 & 31);
  int stage_v_8_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (13 & 31);
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= (stage_v_8_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_8_2 << 1) & 127;
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = ((st_var_2_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_2_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 40)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 40)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 16) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 16) & 15;
  int stage_v_15_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_15_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= stage_v_15_1;
  chk_sum_2 ^= stage_v_15_2;
  int stage_v_16_1 = (st_var_1_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_1_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_18_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 33)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 33)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = (st_var_0_1.buffer[0] ^ 24) & 3;
  int stage_v_21_2 = (st_var_0_2.buffer[0] ^ 24) & 3;
  switch (stage_v_21_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_21_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_22_1 = ((st_var_1_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_1_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 44)
    {
      chk_sum_1 ^= stage_v_22_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_22_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 44)
    {
      chk_sum_2 ^= stage_v_22_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_25_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 28) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (st_var_2_1.buffer[0] ^ 32) & 3;
  int stage_v_29_2 = (st_var_2_2.buffer[0] ^ 32) & 3;
  switch (stage_v_29_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_29_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_31_1 = ((stage_v_31_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_31_2 = ((stage_v_31_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (st_var_2_1.buffer[0] ^ 35) & 3;
  int stage_v_32_2 = (st_var_2_2.buffer[0] ^ 35) & 3;
  switch (stage_v_32_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_32_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_33_1 = ((stage_v_33_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_33_2 = ((stage_v_33_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (39 & 31);
  int stage_v_34_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (39 & 31);
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= (stage_v_34_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_34_2 << 1) & 127;
  int stage_v_35_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (40 & 31);
  int stage_v_35_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (40 & 31);
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  chk_sum_1 ^= (stage_v_35_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_35_2 << 1) & 127;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (44 & 31);
  int stage_v_39_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (44 & 31);
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= (stage_v_39_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_39_2 << 1) & 127;
  int stage_v_40_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (45 & 31);
  int stage_v_40_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (45 & 31);
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= (stage_v_40_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_40_2 << 1) & 127;
  int stage_v_41_1 = table_1[1];
  int stage_v_41_2 = table_2[1];
  table_1[1] = (table_1[2] + 83) & 63;
  table_2[1] = (table_2[2] + 83) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = table_1[2];
  int stage_v_42_2 = table_2[2];
  table_1[2] = (table_1[3] + 85) & 63;
  table_2[2] = (table_2[3] + 85) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_1_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_1_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_43_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = (st_var_1_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_1_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_46_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_49_1 = ((stage_v_49_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_49_2 = ((stage_v_49_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (55 & 31);
  int stage_v_50_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (55 & 31);
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= (stage_v_50_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_50_2 << 1) & 127;
  int stage_v_51_1 = ((st_var_0_1.buffer[0] * 2) + 160) & 63;
  int stage_v_51_2 = ((st_var_0_2.buffer[0] * 2) + 160) & 63;
  if (stage_v_51_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + stage_v_51_1) - 5) & 255;
    if (stage_v_51_1 > 46)
    {
      chk_sum_1 ^= stage_v_51_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_51_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + stage_v_51_2) - 5) & 255;
    if (stage_v_51_2 > 46)
    {
      chk_sum_2 ^= stage_v_51_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_52_1 = (st_var_1_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_1_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
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

  switch (stage_v_52_2)
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

  int stage_v_53_1 = (st_var_2_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_2_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_53_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_54_1 = (st_var_0_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_0_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_54_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
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

  switch (stage_v_55_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
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

  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_58_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_59_1 = (st_var_2_1.buffer[0] ^ 62) & 3;
  int stage_v_59_2 = (st_var_2_2.buffer[0] ^ 62) & 3;
  switch (stage_v_59_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 8) & 255;
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

  switch (stage_v_59_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 8) & 255;
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

  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 33)
    {
      chk_sum_1 ^= stage_v_60_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_60_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 33)
    {
      chk_sum_2 ^= stage_v_60_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 63) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 63) & 15;
  int stage_v_62_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_62_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= stage_v_62_1;
  chk_sum_2 ^= stage_v_62_2;
  int stage_v_63_1 = ((st_var_0_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_0_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 44)
    {
      chk_sum_1 ^= stage_v_63_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_63_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 44)
    {
      chk_sum_2 ^= stage_v_63_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_64_1 = (st_var_1_1.buffer[0] ^ 67) & 3;
  int stage_v_64_2 = (st_var_1_2.buffer[0] ^ 67) & 3;
  switch (stage_v_64_1)
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

  switch (stage_v_64_2)
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

  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_65_1 = ((stage_v_65_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_65_2 = ((stage_v_65_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_66_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  int stage_v_68_1 = (st_var_2_1.buffer[0] ^ 71) & 3;
  int stage_v_68_2 = (st_var_2_2.buffer[0] ^ 71) & 3;
  switch (stage_v_68_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 2) & 255;
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

  switch (stage_v_68_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 2) & 255;
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

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (st_var_1_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_1_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_70_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 72) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 72) & 15;
  int stage_v_71_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_71_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  chk_sum_1 ^= stage_v_71_1;
  chk_sum_2 ^= stage_v_71_2;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_73_1 = ((stage_v_73_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_73_2 = ((stage_v_73_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_74_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_75_1 = ((st_var_0_1.buffer[0] * 2) + 232) & 63;
  int stage_v_75_2 = ((st_var_0_2.buffer[0] * 2) + 232) & 63;
  if (stage_v_75_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_75_1) - 5) & 255;
    if (stage_v_75_1 > 51)
    {
      chk_sum_1 ^= stage_v_75_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_75_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_75_2) - 5) & 255;
    if (stage_v_75_2 > 51)
    {
      chk_sum_2 ^= stage_v_75_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_77_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_78_1 = table_1[2];
  int stage_v_78_2 = table_2[2];
  table_1[2] = (table_1[3] + 157) & 63;
  table_2[2] = (table_2[3] + 157) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_79_1 = ((stage_v_79_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_79_2 = ((stage_v_79_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (st_var_2_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_2_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_80_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (87 & 31);
  int stage_v_82_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (87 & 31);
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= (stage_v_82_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_82_2 << 1) & 127;
  int stage_v_83_1 = ((st_var_2_1.buffer[2] * 2) + 256) & 63;
  int stage_v_83_2 = ((st_var_2_2.buffer[2] * 2) + 256) & 63;
  if (stage_v_83_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_83_1) - 5) & 255;
    if (stage_v_83_1 > 25)
    {
      chk_sum_1 ^= stage_v_83_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_83_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_83_2) - 5) & 255;
    if (stage_v_83_2 > 25)
    {
      chk_sum_2 ^= stage_v_83_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_84_1 = table_1[0];
  int stage_v_84_2 = table_2[0];
  table_1[0] = (table_1[1] + 169) & 63;
  table_2[0] = (table_2[1] + 169) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (st_var_1_1.buffer[0] ^ 88) & 3;
  int stage_v_85_2 = (st_var_1_2.buffer[0] ^ 88) & 3;
  switch (stage_v_85_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_85_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 87) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 87) & 15;
  int stage_v_86_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_86_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  chk_sum_1 ^= stage_v_86_1;
  chk_sum_2 ^= stage_v_86_2;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (st_var_1_1.buffer[0] ^ 91) & 3;
  int stage_v_88_2 = (st_var_1_2.buffer[0] ^ 91) & 3;
  switch (stage_v_88_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_88_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_89_1 = table_1[1];
  int stage_v_89_2 = table_2[1];
  table_1[1] = (table_1[2] + 179) & 63;
  table_2[1] = (table_2[2] + 179) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (95 & 31);
  int stage_v_90_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (95 & 31);
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  chk_sum_1 ^= (stage_v_90_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_90_2 << 1) & 127;
  int stage_v_91_1 = table_1[3];
  int stage_v_91_2 = table_2[3];
  table_1[3] = (table_1[0] + 183) & 63;
  table_2[3] = (table_2[0] + 183) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_92_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_93_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_93_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_94_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_94_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_95_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_95_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_96_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (101 & 31);
  int stage_v_96_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (101 & 31);
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  chk_sum_1 ^= (stage_v_96_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_96_2 << 1) & 127;
  int stage_v_97_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (102 & 31);
  int stage_v_97_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (102 & 31);
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  chk_sum_1 ^= (stage_v_97_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_97_2 << 1) & 127;
  int stage_v_98_1 = ((st_var_2_1.buffer[2] * 2) + 301) & 63;
  int stage_v_98_2 = ((st_var_2_2.buffer[2] * 2) + 301) & 63;
  if (stage_v_98_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_98_1) - 5) & 255;
    if (stage_v_98_1 > 39)
    {
      chk_sum_1 ^= stage_v_98_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_98_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_98_2) - 5) & 255;
    if (stage_v_98_2 > 39)
    {
      chk_sum_2 ^= stage_v_98_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_99_1 = ((st_var_0_1.buffer[0] * 2) + 304) & 63;
  int stage_v_99_2 = ((st_var_0_2.buffer[0] * 2) + 304) & 63;
  if (stage_v_99_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + stage_v_99_1) - 5) & 255;
    if (stage_v_99_1 > 39)
    {
      chk_sum_1 ^= stage_v_99_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_99_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + stage_v_99_2) - 5) & 255;
    if (stage_v_99_2 > 39)
    {
      chk_sum_2 ^= stage_v_99_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_100_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_100_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_101_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (106 & 31);
  int stage_v_101_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (106 & 31);
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  chk_sum_1 ^= (stage_v_101_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_101_2 << 1) & 127;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_102_1 = ((stage_v_102_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_102_2 = ((stage_v_102_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((st_var_1_1.buffer[1] * 2) + 316) & 63;
  int stage_v_103_2 = ((st_var_1_2.buffer[1] * 2) + 316) & 63;
  if (stage_v_103_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_103_1) - 5) & 255;
    if (stage_v_103_1 > 26)
    {
      chk_sum_1 ^= stage_v_103_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_103_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_103_2) - 5) & 255;
    if (stage_v_103_2 > 26)
    {
      chk_sum_2 ^= stage_v_103_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 105) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 105) & 15;
  int stage_v_104_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_104_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  chk_sum_1 ^= stage_v_104_1;
  chk_sum_2 ^= stage_v_104_2;
  int stage_v_105_1 = ((st_var_0_1.buffer[0] * 2) + 322) & 63;
  int stage_v_105_2 = ((st_var_0_2.buffer[0] * 2) + 322) & 63;
  if (stage_v_105_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_105_1) - 5) & 255;
    if (stage_v_105_1 > 47)
    {
      chk_sum_1 ^= stage_v_105_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_105_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_105_2) - 5) & 255;
    if (stage_v_105_2 > 47)
    {
      chk_sum_2 ^= stage_v_105_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_106_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_106_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 108) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 108) & 15;
  int stage_v_107_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_107_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  chk_sum_1 ^= stage_v_107_1;
  chk_sum_2 ^= stage_v_107_2;
  int stage_v_108_1 = (st_var_0_1.buffer[0] ^ 111) & 3;
  int stage_v_108_2 = (st_var_0_2.buffer[0] ^ 111) & 3;
  switch (stage_v_108_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_108_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  int stage_v_109_1 = (st_var_1_1.buffer[0] ^ 112) & 3;
  int stage_v_109_2 = (st_var_1_2.buffer[0] ^ 112) & 3;
  switch (stage_v_109_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
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

  switch (stage_v_109_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
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

  int stage_v_110_1 = table_1[2];
  int stage_v_110_2 = table_2[2];
  table_1[2] = (table_1[3] + 221) & 63;
  table_2[2] = (table_2[3] + 221) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (116 & 31);
  int stage_v_111_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (116 & 31);
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  chk_sum_1 ^= (stage_v_111_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_111_2 << 1) & 127;
  int stage_v_112_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (117 & 31);
  int stage_v_112_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (117 & 31);
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  chk_sum_1 ^= (stage_v_112_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_112_2 << 1) & 127;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_113_1 = ((stage_v_113_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_113_2 = ((stage_v_113_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 115) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 115) & 15;
  int stage_v_114_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_114_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  chk_sum_1 ^= stage_v_114_1;
  chk_sum_2 ^= stage_v_114_2;
  int stage_v_115_1 = table_1[3];
  int stage_v_115_2 = table_2[3];
  table_1[3] = (table_1[0] + 231) & 63;
  table_2[3] = (table_2[0] + 231) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_116_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_117_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (122 & 31);
  int stage_v_117_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (122 & 31);
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  chk_sum_1 ^= (stage_v_117_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_117_2 << 1) & 127;
  int stage_v_118_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (123 & 31);
  int stage_v_118_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (123 & 31);
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  chk_sum_1 ^= (stage_v_118_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_118_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 120) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 120) & 15;
  int stage_v_119_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_119_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  chk_sum_1 ^= stage_v_119_1;
  chk_sum_2 ^= stage_v_119_2;
  int stage_v_120_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (125 & 31);
  int stage_v_120_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (125 & 31);
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  chk_sum_1 ^= (stage_v_120_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_120_2 << 1) & 127;
  int stage_v_121_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (126 & 31);
  int stage_v_121_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (126 & 31);
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  chk_sum_1 ^= (stage_v_121_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_121_2 << 1) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 123) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 123) & 15;
  int stage_v_122_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_122_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  chk_sum_1 ^= stage_v_122_1;
  chk_sum_2 ^= stage_v_122_2;
  int stage_v_123_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (128 & 31);
  int stage_v_123_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (128 & 31);
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  chk_sum_1 ^= (stage_v_123_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_123_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 125) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 125) & 15;
  int stage_v_124_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_124_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  chk_sum_1 ^= stage_v_124_1;
  chk_sum_2 ^= stage_v_124_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 126) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 126) & 15;
  int stage_v_125_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_125_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  chk_sum_1 ^= stage_v_125_1;
  chk_sum_2 ^= stage_v_125_2;
  int stage_v_126_1 = (st_var_0_1.buffer[0] ^ 129) & 3;
  int stage_v_126_2 = (st_var_0_2.buffer[0] ^ 129) & 3;
  switch (stage_v_126_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 7) & 255;
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

  switch (stage_v_126_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 7) & 255;
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

  int stage_v_127_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (132 & 31);
  int stage_v_127_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (132 & 31);
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  chk_sum_1 ^= (stage_v_127_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_127_2 << 1) & 127;
  int stage_v_128_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (133 & 31);
  int stage_v_128_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (133 & 31);
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  chk_sum_1 ^= (stage_v_128_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_128_2 << 1) & 127;
  int stage_v_129_1 = table_1[1];
  int stage_v_129_2 = table_2[1];
  table_1[1] = (table_1[2] + 259) & 63;
  table_2[1] = (table_2[2] + 259) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((st_var_1_1.buffer[1] * 2) + 397) & 63;
  int stage_v_130_2 = ((st_var_1_2.buffer[1] * 2) + 397) & 63;
  if (stage_v_130_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_130_1) - 5) & 255;
    if (stage_v_130_1 > 36)
    {
      chk_sum_1 ^= stage_v_130_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_130_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_130_2) - 5) & 255;
    if (stage_v_130_2 > 36)
    {
      chk_sum_2 ^= stage_v_130_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_131_1 = table_1[3];
  int stage_v_131_2 = table_2[3];
  table_1[3] = (table_1[0] + 263) & 63;
  table_2[3] = (table_2[0] + 263) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_132_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_133_1 = ((st_var_1_1.buffer[1] * 2) + 406) & 63;
  int stage_v_133_2 = ((st_var_1_2.buffer[1] * 2) + 406) & 63;
  if (stage_v_133_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_133_1) - 5) & 255;
    if (stage_v_133_1 > 27)
    {
      chk_sum_1 ^= stage_v_133_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_133_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_133_2) - 5) & 255;
    if (stage_v_133_2 > 27)
    {
      chk_sum_2 ^= stage_v_133_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_134_1 = ((stage_v_134_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_134_2 = ((stage_v_134_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = table_1[3];
  int stage_v_135_2 = table_2[3];
  table_1[3] = (table_1[0] + 271) & 63;
  table_2[3] = (table_2[0] + 271) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_136_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_137_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (142 & 31);
  int stage_v_137_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (142 & 31);
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  chk_sum_1 ^= (stage_v_137_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_137_2 << 1) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_139_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 141) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 141) & 15;
  int stage_v_140_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_140_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  chk_sum_1 ^= stage_v_140_1;
  chk_sum_2 ^= stage_v_140_2;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 142) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 142) & 15;
  int stage_v_141_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_141_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  chk_sum_1 ^= stage_v_141_1;
  chk_sum_2 ^= stage_v_141_2;
  int stage_v_142_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (147 & 31);
  int stage_v_142_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (147 & 31);
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  chk_sum_1 ^= (stage_v_142_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_142_2 << 1) & 127;
  int stage_v_143_1 = table_1[3];
  int stage_v_143_2 = table_2[3];
  table_1[3] = (table_1[0] + 287) & 63;
  table_2[3] = (table_2[0] + 287) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((st_var_1_1.buffer[1] * 2) + 442) & 63;
  int stage_v_145_2 = ((st_var_1_2.buffer[1] * 2) + 442) & 63;
  if (stage_v_145_1 > 14)
  {
    out_sink_1 = ((out_sink_1 + stage_v_145_1) - 5) & 255;
    if (stage_v_145_1 > 29)
    {
      chk_sum_1 ^= stage_v_145_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_145_2 > 14)
  {
    out_sink_2 = ((out_sink_2 + stage_v_145_2) - 5) & 255;
    if (stage_v_145_2 > 29)
    {
      chk_sum_2 ^= stage_v_145_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_146_1 = table_1[2];
  int stage_v_146_2 = table_2[2];
  table_1[2] = (table_1[3] + 293) & 63;
  table_2[2] = (table_2[3] + 293) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = (st_var_0_1.buffer[0] ^ 150) & 3;
  int stage_v_147_2 = (st_var_0_2.buffer[0] ^ 150) & 3;
  switch (stage_v_147_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_147_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_148_1 = ((st_var_1_1.buffer[1] * 2) + 451) & 63;
  int stage_v_148_2 = ((st_var_1_2.buffer[1] * 2) + 451) & 63;
  if (stage_v_148_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_148_1) - 5) & 255;
    if (stage_v_148_1 > 37)
    {
      chk_sum_1 ^= stage_v_148_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_148_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_148_2) - 5) & 255;
    if (stage_v_148_2 > 37)
    {
      chk_sum_2 ^= stage_v_148_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_149_1 = ((st_var_2_1.buffer[2] * 2) + 454) & 63;
  int stage_v_149_2 = ((st_var_2_2.buffer[2] * 2) + 454) & 63;
  if (stage_v_149_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_149_1) - 5) & 255;
    if (stage_v_149_1 > 28)
    {
      chk_sum_1 ^= stage_v_149_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_149_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_149_2) - 5) & 255;
    if (stage_v_149_2 > 28)
    {
      chk_sum_2 ^= stage_v_149_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_150_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_150_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_151_1 = table_1[3];
  int stage_v_151_2 = table_2[3];
  table_1[3] = (table_1[0] + 303) & 63;
  table_2[3] = (table_2[0] + 303) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_152_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 154) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 154) & 15;
  int stage_v_153_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_153_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  chk_sum_1 ^= stage_v_153_1;
  chk_sum_2 ^= stage_v_153_2;
  int stage_v_154_1 = table_1[2];
  int stage_v_154_2 = table_2[2];
  table_1[2] = (table_1[3] + 309) & 63;
  table_2[2] = (table_2[3] + 309) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 156) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 156) & 15;
  int stage_v_155_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_155_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  chk_sum_1 ^= stage_v_155_1;
  chk_sum_2 ^= stage_v_155_2;
  int stage_v_156_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_156_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_157_1 = 0;
  int stage_v_157_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_157_1 = ((stage_v_157_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_157_2 = ((stage_v_157_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 159) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 159) & 15;
  int stage_v_158_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_158_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  chk_sum_1 ^= stage_v_158_1;
  chk_sum_2 ^= stage_v_158_2;
  int stage_v_159_1 = table_1[3];
  int stage_v_159_2 = table_2[3];
  table_1[3] = (table_1[0] + 319) & 63;
  table_2[3] = (table_2[0] + 319) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 161) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 161) & 15;
  int stage_v_160_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_160_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  chk_sum_1 ^= stage_v_160_1;
  chk_sum_2 ^= stage_v_160_2;
  int stage_v_161_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (166 & 31);
  int stage_v_161_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (166 & 31);
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  chk_sum_1 ^= (stage_v_161_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_161_2 << 1) & 127;
  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_163_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_164_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (169 & 31);
  int stage_v_164_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (169 & 31);
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  chk_sum_1 ^= (stage_v_164_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_164_2 << 1) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 166) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 166) & 15;
  int stage_v_165_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_165_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  chk_sum_1 ^= stage_v_165_1;
  chk_sum_2 ^= stage_v_165_2;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_167_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_168_1 = table_1[0];
  int stage_v_168_2 = table_2[0];
  table_1[0] = (table_1[1] + 337) & 63;
  table_2[0] = (table_2[1] + 337) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_169_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_170_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (175 & 31);
  int stage_v_170_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (175 & 31);
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  chk_sum_1 ^= (stage_v_170_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_170_2 << 1) & 127;
  int stage_v_171_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (176 & 31);
  int stage_v_171_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (176 & 31);
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  chk_sum_1 ^= (stage_v_171_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_171_2 << 1) & 127;
  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (st_var_2_1.buffer[0] ^ 176) & 3;
  int stage_v_173_2 = (st_var_2_2.buffer[0] ^ 176) & 3;
  switch (stage_v_173_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_173_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 175) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 175) & 15;
  int stage_v_174_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_174_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  chk_sum_1 ^= stage_v_174_1;
  chk_sum_2 ^= stage_v_174_2;
  int stage_v_175_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_175_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_176_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_176_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_177_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (182 & 31);
  int stage_v_177_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (182 & 31);
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  chk_sum_1 ^= (stage_v_177_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_177_2 << 1) & 127;
  int stage_v_178_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (183 & 31);
  int stage_v_178_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (183 & 31);
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  chk_sum_1 ^= (stage_v_178_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_178_2 << 1) & 127;
  int stage_v_179_1 = table_1[3];
  int stage_v_179_2 = table_2[3];
  table_1[3] = (table_1[0] + 359) & 63;
  table_2[3] = (table_2[0] + 359) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((st_var_0_1.buffer[0] * 2) + 547) & 63;
  int stage_v_180_2 = ((st_var_0_2.buffer[0] * 2) + 547) & 63;
  if (stage_v_180_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_180_1) - 5) & 255;
    if (stage_v_180_1 > 31)
    {
      chk_sum_1 ^= stage_v_180_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_180_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_180_2) - 5) & 255;
    if (stage_v_180_2 > 31)
    {
      chk_sum_2 ^= stage_v_180_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_181_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (186 & 31);
  int stage_v_181_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (186 & 31);
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  chk_sum_1 ^= (stage_v_181_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_181_2 << 1) & 127;
  int stage_v_182_1 = 0;
  int stage_v_182_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_182_1 = ((stage_v_182_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_182_2 = ((stage_v_182_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (188 & 31);
  int stage_v_183_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (188 & 31);
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  chk_sum_1 ^= (stage_v_183_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_183_2 << 1) & 127;
  int stage_v_184_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (189 & 31);
  int stage_v_184_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (189 & 31);
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  chk_sum_1 ^= (stage_v_184_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_184_2 << 1) & 127;
  int stage_v_185_1 = ((st_var_2_1.buffer[2] * 2) + 562) & 63;
  int stage_v_185_2 = ((st_var_2_2.buffer[2] * 2) + 562) & 63;
  if (stage_v_185_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_185_1) - 5) & 255;
    if (stage_v_185_1 > 54)
    {
      chk_sum_1 ^= stage_v_185_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_185_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_185_2) - 5) & 255;
    if (stage_v_185_2 > 54)
    {
      chk_sum_2 ^= stage_v_185_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_186_1 = table_1[2];
  int stage_v_186_2 = table_2[2];
  table_1[2] = (table_1[3] + 373) & 63;
  table_2[2] = (table_2[3] + 373) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (192 & 31);
  int stage_v_187_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (192 & 31);
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  chk_sum_1 ^= (stage_v_187_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_187_2 << 1) & 127;
  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 3) && (step_2 < 3); step_1++, step_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = table_1[1];
  int stage_v_189_2 = table_2[1];
  table_1[1] = (table_1[2] + 379) & 63;
  table_2[1] = (table_2[2] + 379) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (195 & 31);
  int stage_v_190_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (195 & 31);
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  chk_sum_1 ^= (stage_v_190_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_190_2 << 1) & 127;
  int stage_v_191_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_191_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 193) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 193) & 15;
  int stage_v_192_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_192_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  chk_sum_1 ^= stage_v_192_1;
  chk_sum_2 ^= stage_v_192_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 194) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 194) & 15;
  int stage_v_193_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_193_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  chk_sum_1 ^= stage_v_193_1;
  chk_sum_2 ^= stage_v_193_2;
  int stage_v_194_1 = table_1[2];
  int stage_v_194_2 = table_2[2];
  table_1[2] = (table_1[3] + 389) & 63;
  table_2[2] = (table_2[3] + 389) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = table_1[3];
  int stage_v_195_2 = table_2[3];
  table_1[3] = (table_1[0] + 391) & 63;
  table_2[3] = (table_2[0] + 391) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (st_var_1_1.buffer[0] ^ 199) & 3;
  int stage_v_196_2 = (st_var_1_2.buffer[0] ^ 199) & 3;
  switch (stage_v_196_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 3) & 255;
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

  switch (stage_v_196_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 3) & 255;
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

  int stage_v_197_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_197_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_198_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (203 & 31);
  int stage_v_198_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (203 & 31);
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  chk_sum_1 ^= (stage_v_198_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_198_2 << 1) & 127;
  int stage_v_199_1 = ((st_var_1_1.buffer[1] * 2) + 604) & 63;
  int stage_v_199_2 = ((st_var_1_2.buffer[1] * 2) + 604) & 63;
  if (stage_v_199_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_199_1) - 5) & 255;
    if (stage_v_199_1 > 43)
    {
      chk_sum_1 ^= stage_v_199_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_199_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_199_2) - 5) & 255;
    if (stage_v_199_2 > 43)
    {
      chk_sum_2 ^= stage_v_199_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  if ((sec_r000690_14_1 & 1) != 0)
  {
    if ((sec_r000690_6_1 & 2) != 0)
    {
      out_sink_1 += 26;
    }
    else
    {
      out_sink_1 += 19;
    }
  }
  else
  {
    if ((sec_r000690_2_1 & 4) != 0)
    {
      out_sink_1 -= 15;
    }
    else
    {
      out_sink_1 -= 40;
    }
  }
  if ((sec_r000690_14_2 & 1) != 0)
  {
    if ((sec_r000690_6_2 & 2) != 0)
    {
      out_sink_2 += 26;
    }
    else
    {
      out_sink_2 += 19;
    }
  }
  else
  {
    if ((sec_r000690_2_2 & 4) != 0)
    {
      out_sink_2 -= 15;
    }
    else
    {
      out_sink_2 -= 40;
    }
  }
  g_out_1 = out_sink_1;
  g_out_2 = out_sink_2;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  __CPROVER_assume(sec_r000690_3_1 != sec_r000690_3_2);
  __CPROVER_assume(sec_r000690_16_1 != sec_r000690_16_2);
  __CPROVER_assume(sec_r000690_9_1 != sec_r000690_9_2);
  __CPROVER_assume(sec_r000690_7_1 != sec_r000690_7_2);
  __CPROVER_assume(pub_r000690_4_1 == pub_r000690_4_2);
  __CPROVER_assume(sec_r000690_0_1 != sec_r000690_0_2);
  __CPROVER_assume(pub_r000690_0_1 == pub_r000690_0_2);
  __CPROVER_assume(sec_r000690_11_1 != sec_r000690_11_2);
  __CPROVER_assume(pub_r000690_10_1 == pub_r000690_10_2);
  __CPROVER_assume(pub_r000690_1_1 == pub_r000690_1_2);
  __CPROVER_assume(sec_r000690_5_1 != sec_r000690_5_2);
  __CPROVER_assume(sec_r000690_15_1 != sec_r000690_15_2);
  __CPROVER_assume(pub_r000690_12_1 == pub_r000690_12_2);
  __CPROVER_assume(pub_r000690_13_1 == pub_r000690_13_2);
  __CPROVER_assume(sec_r000690_12_1 != sec_r000690_12_2);
  __CPROVER_assume(sec_r000690_8_1 != sec_r000690_8_2);
  __CPROVER_assume(pub_r000690_7_1 == pub_r000690_7_2);
  __CPROVER_assume(pub_r000690_9_1 == pub_r000690_9_2);
  __CPROVER_assume(sec_r000690_1_1 != sec_r000690_1_2);
  __CPROVER_assume(sec_r000690_14_1 != sec_r000690_14_2);
  __CPROVER_assume(sec_r000690_4_1 != sec_r000690_4_2);
  __CPROVER_assume(pub_r000690_5_1 == pub_r000690_5_2);
  __CPROVER_assume(pub_r000690_11_1 == pub_r000690_11_2);
  __CPROVER_assume(pub_r000690_2_1 == pub_r000690_2_2);
  __CPROVER_assume(pub_r000690_15_1 == pub_r000690_15_2);
  __CPROVER_assume(sec_r000690_6_1 != sec_r000690_6_2);
  __CPROVER_assume(pub_r000690_8_1 == pub_r000690_8_2);
  __CPROVER_assume(sec_r000690_2_1 != sec_r000690_2_2);
  __CPROVER_assume(pub_r000690_16_1 == pub_r000690_16_2);
  __CPROVER_assume(sec_r000690_13_1 != sec_r000690_13_2);
  __CPROVER_assume(pub_r000690_6_1 == pub_r000690_6_2);
  __CPROVER_assume(sec_r000690_10_1 != sec_r000690_10_2);
  __CPROVER_assume(pub_r000690_14_1 == pub_r000690_14_2);
  __CPROVER_assume(pub_r000690_3_1 == pub_r000690_3_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.balance == st_var_2_2.balance);
  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.rate == st_var_2_2.rate);
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
}


