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
struct EventLog_R001030_3013_0
{
  int severity;
  unsigned char code;
  int timestamp;
  int facility;
  int buffer[3];
};
struct CipherContext_R001030_3013_1
{
  int nonce;
  short counter;
  int iv;
  int round_key;
  short tag;
  int buffer[3];
};
struct Vector3D_R001030_3013_2
{
  unsigned char coord_y;
  unsigned char heading;
  short pitch;
  int coord_x;
  int coord_z;
  int buffer[3];
};
union RegisterBank_R001030_3013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001030_3013_1
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
void fn_R001030_3013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_68_1 = 0;
  int vector_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_68_1 = ((vector_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_68_2 = ((vector_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_68_1) & 127;
    acc_2 = (acc_2 + vector_68_2) & 127;
  }

  int weight_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_55_1 > 29)
  {
    acc_1 = ((acc_1 + (weight_55_1 * 2)) + 5) & 127;
    aux_1 ^= weight_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_55_2 > 29)
  {
    acc_2 = ((acc_2 + (weight_55_2 * 2)) + 5) & 127;
    aux_2 ^= weight_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_55_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_68_1 == vector_68_2);
  assert(weight_55_1 == weight_55_2);
}

int fn_R001030_3013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_68 = ((vector_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_68) & 127;
  }

  int weight_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_55 > 29)
  {
    acc = ((acc + (weight_55 * 2)) + 5) & 127;
    aux ^= weight_55 & 15;
  }
  else
  {
    acc = ((acc - weight_55) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001030_3013_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int index_reg_95_1 = 0;
  int index_reg_95_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_95_1 = ((index_reg_95_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_95_2 = ((index_reg_95_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_95_1) & 127;
    acc_2 = (acc_2 + index_reg_95_2) & 127;
  }

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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_95_1 == index_reg_95_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R001030_3013_1(int p0, int p1, int p2)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int index_reg_95 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_95 = ((index_reg_95 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_95) & 127;
  }

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

  return (acc + aux) & 255;
}

void fn_R001030_3013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int window_78_1 = 0;
  int window_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_78_1 = ((window_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_78_2 = ((window_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_78_1) & 127;
    acc_2 = (acc_2 + window_78_2) & 127;
  }

  int tally_99_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_99_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_99_1)
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

  switch (tally_99_2)
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

  int tally_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_94_1 > 11)
  {
    acc_1 = ((acc_1 + (tally_94_1 * 2)) + 5) & 127;
    aux_1 ^= tally_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_94_2 > 11)
  {
    acc_2 = ((acc_2 + (tally_94_2 * 2)) + 5) & 127;
    aux_2 ^= tally_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_88_1 = local_arr_1[aux_1 % 3];
  int anchor_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_88_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_78_1 == window_78_2);
  assert(tally_99_1 == tally_99_2);
  assert(tally_94_1 == tally_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_88_1 == anchor_88_2);
}

int fn_R001030_3013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int window_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_78 = ((window_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_78) & 127;
  }

  int tally_99 = (aux + st.buffer[1]) & 3;
  switch (tally_99)
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

  int tally_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_94 > 11)
  {
    acc = ((acc + (tally_94 * 2)) + 5) & 127;
    aux ^= tally_94 & 15;
  }
  else
  {
    acc = ((acc - tally_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_88 = local_arr[aux % 3];
  acc = (acc + (anchor_88 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int anchor_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_14_1 > 10)
  {
    acc_1 = ((acc_1 + (anchor_14_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_14_2 > 10)
  {
    acc_2 = ((acc_2 + (anchor_14_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_14_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_63_1) & 63;
  aux_2 = (aux_2 + threshold_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_13_1 = local_arr_1[aux_1 % 3];
  int tally_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_13_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_14_1 == anchor_14_2);
  assert(threshold_63_1 == threshold_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_13_1 == tally_13_2);
}

int fn_R001030_3013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int anchor_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_14 > 10)
  {
    acc = ((acc + (anchor_14 * 2)) + 5) & 127;
    aux ^= anchor_14 & 15;
  }
  else
  {
    acc = ((acc - anchor_14) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_63) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_13 = local_arr[aux % 3];
  acc = (acc + (tally_13 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st_1 = {0};
  struct Vector3D_R001030_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_32_1) & 63;
  aux_2 = (aux_2 + metric_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_74_1 = 0;
  int quotient_74_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_74_1 = ((quotient_74_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_74_2 = ((quotient_74_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_74_1) & 127;
    acc_2 = (acc_2 + quotient_74_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_32_1 == metric_32_2);
  assert(quotient_74_1 == quotient_74_2);
}

int fn_R001030_3013_4(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_32) & 63;
  acc ^= aux;
  int quotient_74 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_74 = ((quotient_74 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_74) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001030_3013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int index_reg_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_58_1)
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

  switch (index_reg_58_2)
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
  int cursor_44_1 = local_arr_1[aux_1 % 3];
  int cursor_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_44_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_58_1 == index_reg_58_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_44_1 == cursor_44_2);
}

int fn_R001030_3013_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int index_reg_58 = (aux + st.buffer[1]) & 3;
  switch (index_reg_58)
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
  int cursor_44 = local_arr[aux % 3];
  acc = (acc + (cursor_44 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int factor_22_1 = 0;
  int factor_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_22_1 = ((factor_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_22_2 = ((factor_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_22_1) & 127;
    acc_2 = (acc_2 + factor_22_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_34_1) & 63;
  aux_2 = (aux_2 + threshold_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_75_1 = local_arr_1[aux_1 % 3];
  int factor_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_75_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_22_1 == factor_22_2);
  assert(threshold_34_1 == threshold_34_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_75_1 == factor_75_2);
}

int fn_R001030_3013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int factor_22 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_22 = ((factor_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_22) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_34) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_75 = local_arr[aux % 3];
  acc = (acc + (factor_75 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_31_1 = local_arr_1[aux_1 % 3];
  int checksum_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_31_2 * 2)) & 127;
  int tracker_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_45_1 > 34)
  {
    acc_1 = ((acc_1 + (tracker_45_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_45_2 > 34)
  {
    acc_2 = ((acc_2 + (tracker_45_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_31_1 == checksum_31_2);
  assert(tracker_45_1 == tracker_45_2);
}

int fn_R001030_3013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int checksum_31 = local_arr[aux % 3];
  acc = (acc + (checksum_31 * 2)) & 127;
  int tracker_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_45 > 34)
  {
    acc = ((acc + (tracker_45 * 2)) + 5) & 127;
    aux ^= tracker_45 & 15;
  }
  else
  {
    acc = ((acc - tracker_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001030_3013_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_79_1 = local_arr_1[aux_1 % 3];
  int pivot_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_79_2 * 2)) & 127;
  int delta_72_1 = 0;
  int delta_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_72_1 = ((delta_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_72_2 = ((delta_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_72_1) & 127;
    acc_2 = (acc_2 + delta_72_2) & 127;
  }

  int threshold_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_38_1 > 32)
  {
    acc_1 = ((acc_1 + (threshold_38_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_38_2 > 32)
  {
    acc_2 = ((acc_2 + (threshold_38_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_38_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_79_1 == pivot_79_2);
  assert(delta_72_1 == delta_72_2);
  assert(threshold_38_1 == threshold_38_2);
}

int fn_R001030_3013_8(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int pivot_79 = local_arr[aux % 3];
  acc = (acc + (pivot_79 * 2)) & 127;
  int delta_72 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_72 = ((delta_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_72) & 127;
  }

  int threshold_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_38 > 32)
  {
    acc = ((acc + (threshold_38 * 2)) + 5) & 127;
    aux ^= threshold_38 & 15;
  }
  else
  {
    acc = ((acc - threshold_38) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001030_3013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st_1 = {0};
  struct CipherContext_R001030_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int anchor_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_17_1 > 36)
  {
    acc_1 = ((acc_1 + (anchor_17_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_17_2 > 36)
  {
    acc_2 = ((acc_2 + (anchor_17_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_17_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_17_1 == anchor_17_2);
}

int fn_R001030_3013_9(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int anchor_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_17 > 36)
  {
    acc = ((acc + (anchor_17 * 2)) + 5) & 127;
    aux ^= anchor_17 & 15;
  }
  else
  {
    acc = ((acc - anchor_17) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001030_3013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_76_1 = local_arr_1[aux_1 % 3];
  int coefficient_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_76_2 * 2)) & 127;
  int tracker_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_40_1 > 45)
  {
    acc_1 = ((acc_1 + (tracker_40_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_40_2 > 45)
  {
    acc_2 = ((acc_2 + (tracker_40_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int scale_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_90_1)
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

  switch (scale_90_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_76_1 == coefficient_76_2);
  assert(tracker_40_1 == tracker_40_2);
  assert(scale_90_1 == scale_90_2);
}

int fn_R001030_3013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int coefficient_76 = local_arr[aux % 3];
  acc = (acc + (coefficient_76 * 2)) & 127;
  int tracker_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_40 > 45)
  {
    acc = ((acc + (tracker_40 * 2)) + 5) & 127;
    aux ^= tracker_40 & 15;
  }
  else
  {
    acc = ((acc - tracker_40) + 11) & 127;
    aux += 3;
  }
  int scale_90 = (aux + st.buffer[1]) & 3;
  switch (scale_90)
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

void fn_R001030_3013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_24_1) & 63;
  aux_2 = (aux_2 + margin_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int vector_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_70_1 > 45)
  {
    acc_1 = ((acc_1 + (vector_70_1 * 2)) + 5) & 127;
    aux_1 ^= vector_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_70_2 > 45)
  {
    acc_2 = ((acc_2 + (vector_70_2 * 2)) + 5) & 127;
    aux_2 ^= vector_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_70_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_24_1 == margin_24_2);
  assert(vector_70_1 == vector_70_2);
}

int fn_R001030_3013_11(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_24) & 63;
  acc ^= aux;
  int vector_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_70 > 45)
  {
    acc = ((acc + (vector_70 * 2)) + 5) & 127;
    aux ^= vector_70 & 15;
  }
  else
  {
    acc = ((acc - vector_70) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001030_3013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st_1 = {0};
  struct CipherContext_R001030_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int coefficient_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_84_1 > 26)
  {
    acc_1 = ((acc_1 + (coefficient_84_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_84_2 > 26)
  {
    acc_2 = ((acc_2 + (coefficient_84_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_21_1 = 0;
  int stride_21_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    stride_21_1 = ((stride_21_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_21_2 = ((stride_21_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_21_1) & 127;
    acc_2 = (acc_2 + stride_21_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_39_1 = local_arr_1[aux_1 % 3];
  int quotient_39_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_39_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_39_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_84_1 == coefficient_84_2);
  assert(stride_21_1 == stride_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_39_1 == quotient_39_2);
}

int fn_R001030_3013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int coefficient_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_84 > 26)
  {
    acc = ((acc + (coefficient_84 * 2)) + 5) & 127;
    aux ^= coefficient_84 & 15;
  }
  else
  {
    acc = ((acc - coefficient_84) + 11) & 127;
    aux += 3;
  }
  int stride_21 = 0;
  for (int k = 0; k < 3; k++)
  {
    stride_21 = ((stride_21 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_21) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_39 = local_arr[aux % 3];
  acc = (acc + (quotient_39 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st_1 = {0};
  struct Vector3D_R001030_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int damping_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_64_1)
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

  switch (damping_64_2)
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
  int coefficient_46_1 = local_arr_1[aux_1 % 3];
  int coefficient_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_46_2 * 2)) & 127;
  int delta_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_62_1 > 44)
  {
    acc_1 = ((acc_1 + (delta_62_1 * 2)) + 5) & 127;
    aux_1 ^= delta_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_62_2 > 44)
  {
    acc_2 = ((acc_2 + (delta_62_2 * 2)) + 5) & 127;
    aux_2 ^= delta_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_62_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_75_1) & 63;
  aux_2 = (aux_2 + phase_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_64_1 == damping_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_46_1 == coefficient_46_2);
  assert(delta_62_1 == delta_62_2);
  assert(phase_75_1 == phase_75_2);
}

int fn_R001030_3013_13(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int damping_64 = (aux + st.buffer[1]) & 3;
  switch (damping_64)
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
  int coefficient_46 = local_arr[aux % 3];
  acc = (acc + (coefficient_46 * 2)) & 127;
  int delta_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_62 > 44)
  {
    acc = ((acc + (delta_62 * 2)) + 5) & 127;
    aux ^= delta_62 & 15;
  }
  else
  {
    acc = ((acc - delta_62) + 11) & 127;
    aux += 3;
  }
  int phase_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001030_3013_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_52_1 = local_arr_1[aux_1 % 3];
  int scale_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_52_2 * 2)) & 127;
  int stride_40_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_40_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_40_1)
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

  switch (stride_40_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_52_1 == scale_52_2);
  assert(stride_40_1 == stride_40_2);
}

int fn_R001030_3013_14(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int scale_52 = local_arr[aux % 3];
  acc = (acc + (scale_52 * 2)) & 127;
  int stride_40 = (aux + st.buffer[1]) & 3;
  switch (stride_40)
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

void fn_R001030_3013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st_1 = {0};
  struct CipherContext_R001030_3013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_64_1 = local_arr_1[aux_1 % 3];
  int parity_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_64_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_12_1)
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

  switch (scale_12_2)
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

  int cursor_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_63_1) & 63;
  aux_2 = (aux_2 + cursor_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  assert(st_1.iv == st_2.iv);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.tag == st_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_64_1 == parity_64_2);
  assert(scale_12_1 == scale_12_2);
  assert(cursor_63_1 == cursor_63_2);
}

int fn_R001030_3013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001030_3013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int parity_64 = local_arr[aux % 3];
  acc = (acc + (parity_64 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_12 = (aux + st.buffer[1]) & 3;
  switch (scale_12)
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

  int cursor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_63) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001030_3013_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st_1 = {0};
  struct Vector3D_R001030_3013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int quantum_38_1 = 0;
  int quantum_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quantum_38_1 = ((quantum_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_38_2 = ((quantum_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_38_1) & 127;
    acc_2 = (acc_2 + quantum_38_2) & 127;
  }

  int residue_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_10_1) & 63;
  aux_2 = (aux_2 + residue_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_79_1 > 23)
  {
    acc_1 = ((acc_1 + (tracker_79_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_79_2 > 23)
  {
    acc_2 = ((acc_2 + (tracker_79_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_79_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_38_1 == quantum_38_2);
  assert(residue_10_1 == residue_10_2);
  assert(tracker_79_1 == tracker_79_2);
}

int fn_R001030_3013_16(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001030_3013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int quantum_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    quantum_38 = ((quantum_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_38) & 127;
  }

  int residue_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_10) & 63;
  acc ^= aux;
  int tracker_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_79 > 23)
  {
    acc = ((acc + (tracker_79 * 2)) + 5) & 127;
    aux ^= tracker_79 & 15;
  }
  else
  {
    acc = ((acc - tracker_79) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int weight_90_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_90_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_90_1) & 63;
  aux_2 = (aux_2 + weight_90_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_97_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_97_1 * 2)) + 5) & 127;
    aux_1 ^= damping_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_97_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_97_2 * 2)) + 5) & 127;
    aux_2 ^= damping_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_97_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_92_1 = local_arr_1[aux_1 % 3];
  int threshold_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_92_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_90_1 == weight_90_2);
  assert(damping_97_1 == damping_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_92_1 == threshold_92_2);
}

int fn_R001030_3013_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int weight_90 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_90) & 63;
  acc ^= aux;
  int damping_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_97 > 22)
  {
    acc = ((acc + (damping_97 * 2)) + 5) & 127;
    aux ^= damping_97 & 15;
  }
  else
  {
    acc = ((acc - damping_97) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_92 = local_arr[aux % 3];
  acc = (acc + (threshold_92 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001030_3013_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st_1 = {0};
  struct EventLog_R001030_3013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int weight_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_73_1)
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

  switch (weight_73_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_69_1) & 63;
  aux_2 = (aux_2 + factor_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_95_1 = local_arr_1[aux_1 % 3];
  int delta_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.severity == st_2.severity);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.facility == st_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_73_1 == weight_73_2);
  assert(factor_69_1 == factor_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_95_1 == delta_95_2);
}

int fn_R001030_3013_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001030_3013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int weight_73 = (aux + st.buffer[1]) & 3;
  switch (weight_73)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_69) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_95 = local_arr[aux % 3];
  acc = (acc + (delta_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001030_0_1;
  int sec_r001030_0_2;
  int sec_r001030_1_1;
  int sec_r001030_1_2;
  int sec_r001030_2_1;
  int sec_r001030_2_2;
  int sec_r001030_3_1;
  int sec_r001030_3_2;
  int sec_r001030_4_1;
  int sec_r001030_4_2;
  int sec_r001030_5_1;
  int sec_r001030_5_2;
  int sec_r001030_6_1;
  int sec_r001030_6_2;
  int sec_r001030_7_1;
  int sec_r001030_7_2;
  int sec_r001030_8_1;
  int sec_r001030_8_2;
  int sec_r001030_9_1;
  int sec_r001030_9_2;
  int sec_r001030_10_1;
  int sec_r001030_10_2;
  int sec_r001030_11_1;
  int sec_r001030_11_2;
  int sec_r001030_12_1;
  int sec_r001030_12_2;
  int sec_r001030_13_1;
  int sec_r001030_13_2;
  int sec_r001030_14_1;
  int sec_r001030_14_2;
  int sec_r001030_15_1;
  int sec_r001030_15_2;
  int sec_r001030_16_1;
  int sec_r001030_16_2;
  int sec_r001030_17_1;
  int sec_r001030_17_2;
  int sec_r001030_18_1;
  int sec_r001030_18_2;
  int sec_r001030_19_1;
  int sec_r001030_19_2;
  int pub_r001030_0_1;
  int pub_r001030_0_2;
  int pub_r001030_1_1;
  int pub_r001030_1_2;
  int pub_r001030_2_1;
  int pub_r001030_2_2;
  int pub_r001030_3_1;
  int pub_r001030_3_2;
  int pub_r001030_4_1;
  int pub_r001030_4_2;
  int pub_r001030_5_1;
  int pub_r001030_5_2;
  int pub_r001030_6_1;
  int pub_r001030_6_2;
  int pub_r001030_7_1;
  int pub_r001030_7_2;
  int pub_r001030_8_1;
  int pub_r001030_8_2;
  int pub_r001030_9_1;
  int pub_r001030_9_2;
  int pub_r001030_10_1;
  int pub_r001030_10_2;
  int pub_r001030_11_1;
  int pub_r001030_11_2;
  int pub_r001030_12_1;
  int pub_r001030_12_2;
  int pub_r001030_13_1;
  int pub_r001030_13_2;
  int pub_r001030_14_1;
  int pub_r001030_14_2;
  int pub_r001030_15_1;
  int pub_r001030_15_2;
  int pub_r001030_16_1;
  int pub_r001030_16_2;
  int pub_r001030_17_1;
  int pub_r001030_17_2;
  int pub_r001030_18_1;
  int pub_r001030_18_2;
  int pub_r001030_19_1;
  int pub_r001030_19_2;
  int pub_r001030_20_1;
  int pub_r001030_20_2;
  int pub_r001030_21_1;
  int pub_r001030_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001030_0_1 >= (-100)) && (pub_r001030_0_1 <= 100));
  __CPROVER_assume((pub_r001030_0_2 >= (-100)) && (pub_r001030_0_2 <= 100));
  __CPROVER_assume((pub_r001030_1_1 >= (-100)) && (pub_r001030_1_1 <= 100));
  __CPROVER_assume((pub_r001030_1_2 >= (-100)) && (pub_r001030_1_2 <= 100));
  __CPROVER_assume((pub_r001030_2_1 >= (-100)) && (pub_r001030_2_1 <= 100));
  __CPROVER_assume((pub_r001030_2_2 >= (-100)) && (pub_r001030_2_2 <= 100));
  __CPROVER_assume((pub_r001030_3_1 >= (-100)) && (pub_r001030_3_1 <= 100));
  __CPROVER_assume((pub_r001030_3_2 >= (-100)) && (pub_r001030_3_2 <= 100));
  __CPROVER_assume((pub_r001030_4_1 >= (-100)) && (pub_r001030_4_1 <= 100));
  __CPROVER_assume((pub_r001030_4_2 >= (-100)) && (pub_r001030_4_2 <= 100));
  __CPROVER_assume((pub_r001030_5_1 >= (-100)) && (pub_r001030_5_1 <= 100));
  __CPROVER_assume((pub_r001030_5_2 >= (-100)) && (pub_r001030_5_2 <= 100));
  __CPROVER_assume((pub_r001030_6_1 >= (-100)) && (pub_r001030_6_1 <= 100));
  __CPROVER_assume((pub_r001030_6_2 >= (-100)) && (pub_r001030_6_2 <= 100));
  __CPROVER_assume((pub_r001030_7_1 >= (-100)) && (pub_r001030_7_1 <= 100));
  __CPROVER_assume((pub_r001030_7_2 >= (-100)) && (pub_r001030_7_2 <= 100));
  __CPROVER_assume((pub_r001030_8_1 >= (-100)) && (pub_r001030_8_1 <= 100));
  __CPROVER_assume((pub_r001030_8_2 >= (-100)) && (pub_r001030_8_2 <= 100));
  __CPROVER_assume((pub_r001030_9_1 >= (-100)) && (pub_r001030_9_1 <= 100));
  __CPROVER_assume((pub_r001030_9_2 >= (-100)) && (pub_r001030_9_2 <= 100));
  __CPROVER_assume((pub_r001030_10_1 >= (-100)) && (pub_r001030_10_1 <= 100));
  __CPROVER_assume((pub_r001030_10_2 >= (-100)) && (pub_r001030_10_2 <= 100));
  __CPROVER_assume((pub_r001030_11_1 >= (-100)) && (pub_r001030_11_1 <= 100));
  __CPROVER_assume((pub_r001030_11_2 >= (-100)) && (pub_r001030_11_2 <= 100));
  __CPROVER_assume((pub_r001030_12_1 >= (-100)) && (pub_r001030_12_1 <= 100));
  __CPROVER_assume((pub_r001030_12_2 >= (-100)) && (pub_r001030_12_2 <= 100));
  __CPROVER_assume((pub_r001030_13_1 >= (-100)) && (pub_r001030_13_1 <= 100));
  __CPROVER_assume((pub_r001030_13_2 >= (-100)) && (pub_r001030_13_2 <= 100));
  __CPROVER_assume((pub_r001030_14_1 >= (-100)) && (pub_r001030_14_1 <= 100));
  __CPROVER_assume((pub_r001030_14_2 >= (-100)) && (pub_r001030_14_2 <= 100));
  __CPROVER_assume((pub_r001030_15_1 >= (-100)) && (pub_r001030_15_1 <= 100));
  __CPROVER_assume((pub_r001030_15_2 >= (-100)) && (pub_r001030_15_2 <= 100));
  __CPROVER_assume((pub_r001030_16_1 >= (-100)) && (pub_r001030_16_1 <= 100));
  __CPROVER_assume((pub_r001030_16_2 >= (-100)) && (pub_r001030_16_2 <= 100));
  __CPROVER_assume((pub_r001030_17_1 >= (-100)) && (pub_r001030_17_1 <= 100));
  __CPROVER_assume((pub_r001030_17_2 >= (-100)) && (pub_r001030_17_2 <= 100));
  __CPROVER_assume((pub_r001030_18_1 >= (-100)) && (pub_r001030_18_1 <= 100));
  __CPROVER_assume((pub_r001030_18_2 >= (-100)) && (pub_r001030_18_2 <= 100));
  __CPROVER_assume((pub_r001030_19_1 >= (-100)) && (pub_r001030_19_1 <= 100));
  __CPROVER_assume((pub_r001030_19_2 >= (-100)) && (pub_r001030_19_2 <= 100));
  __CPROVER_assume((pub_r001030_20_1 >= (-100)) && (pub_r001030_20_1 <= 100));
  __CPROVER_assume((pub_r001030_20_2 >= (-100)) && (pub_r001030_20_2 <= 100));
  __CPROVER_assume((pub_r001030_21_1 >= (-100)) && (pub_r001030_21_1 <= 100));
  __CPROVER_assume((pub_r001030_21_2 >= (-100)) && (pub_r001030_21_2 <= 100));
  __CPROVER_assume((sec_r001030_0_1 >= 0) && (sec_r001030_0_1 <= 255));
  __CPROVER_assume((sec_r001030_0_2 >= 0) && (sec_r001030_0_2 <= 255));
  __CPROVER_assume((sec_r001030_1_1 >= 0) && (sec_r001030_1_1 <= 255));
  __CPROVER_assume((sec_r001030_1_2 >= 0) && (sec_r001030_1_2 <= 255));
  __CPROVER_assume((sec_r001030_2_1 >= 0) && (sec_r001030_2_1 <= 255));
  __CPROVER_assume((sec_r001030_2_2 >= 0) && (sec_r001030_2_2 <= 255));
  __CPROVER_assume((sec_r001030_3_1 >= 0) && (sec_r001030_3_1 <= 255));
  __CPROVER_assume((sec_r001030_3_2 >= 0) && (sec_r001030_3_2 <= 255));
  __CPROVER_assume((sec_r001030_4_1 >= 0) && (sec_r001030_4_1 <= 255));
  __CPROVER_assume((sec_r001030_4_2 >= 0) && (sec_r001030_4_2 <= 255));
  __CPROVER_assume((sec_r001030_5_1 >= 0) && (sec_r001030_5_1 <= 255));
  __CPROVER_assume((sec_r001030_5_2 >= 0) && (sec_r001030_5_2 <= 255));
  __CPROVER_assume((sec_r001030_6_1 >= 0) && (sec_r001030_6_1 <= 255));
  __CPROVER_assume((sec_r001030_6_2 >= 0) && (sec_r001030_6_2 <= 255));
  __CPROVER_assume((sec_r001030_7_1 >= 0) && (sec_r001030_7_1 <= 255));
  __CPROVER_assume((sec_r001030_7_2 >= 0) && (sec_r001030_7_2 <= 255));
  __CPROVER_assume((sec_r001030_8_1 >= 0) && (sec_r001030_8_1 <= 255));
  __CPROVER_assume((sec_r001030_8_2 >= 0) && (sec_r001030_8_2 <= 255));
  __CPROVER_assume((sec_r001030_9_1 >= 0) && (sec_r001030_9_1 <= 255));
  __CPROVER_assume((sec_r001030_9_2 >= 0) && (sec_r001030_9_2 <= 255));
  __CPROVER_assume((sec_r001030_10_1 >= 0) && (sec_r001030_10_1 <= 255));
  __CPROVER_assume((sec_r001030_10_2 >= 0) && (sec_r001030_10_2 <= 255));
  __CPROVER_assume((sec_r001030_11_1 >= 0) && (sec_r001030_11_1 <= 255));
  __CPROVER_assume((sec_r001030_11_2 >= 0) && (sec_r001030_11_2 <= 255));
  __CPROVER_assume((sec_r001030_12_1 >= 0) && (sec_r001030_12_1 <= 255));
  __CPROVER_assume((sec_r001030_12_2 >= 0) && (sec_r001030_12_2 <= 255));
  __CPROVER_assume((sec_r001030_13_1 >= 0) && (sec_r001030_13_1 <= 255));
  __CPROVER_assume((sec_r001030_13_2 >= 0) && (sec_r001030_13_2 <= 255));
  __CPROVER_assume((sec_r001030_14_1 >= 0) && (sec_r001030_14_1 <= 255));
  __CPROVER_assume((sec_r001030_14_2 >= 0) && (sec_r001030_14_2 <= 255));
  __CPROVER_assume((sec_r001030_15_1 >= 0) && (sec_r001030_15_1 <= 255));
  __CPROVER_assume((sec_r001030_15_2 >= 0) && (sec_r001030_15_2 <= 255));
  __CPROVER_assume((sec_r001030_16_1 >= 0) && (sec_r001030_16_1 <= 255));
  __CPROVER_assume((sec_r001030_16_2 >= 0) && (sec_r001030_16_2 <= 255));
  __CPROVER_assume((sec_r001030_17_1 >= 0) && (sec_r001030_17_1 <= 255));
  __CPROVER_assume((sec_r001030_17_2 >= 0) && (sec_r001030_17_2 <= 255));
  __CPROVER_assume((sec_r001030_18_1 >= 0) && (sec_r001030_18_1 <= 255));
  __CPROVER_assume((sec_r001030_18_2 >= 0) && (sec_r001030_18_2 <= 255));
  __CPROVER_assume((sec_r001030_19_1 >= 0) && (sec_r001030_19_1 <= 255));
  __CPROVER_assume((sec_r001030_19_2 >= 0) && (sec_r001030_19_2 <= 255));
  struct EventLog_R001030_3013_0 st_var_0_1 = {0};
  struct EventLog_R001030_3013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001030_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001030_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001030_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001030_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001030_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001030_0_2 + 7) & 15;
  struct CipherContext_R001030_3013_1 st_var_1_1 = {0};
  struct CipherContext_R001030_3013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001030_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001030_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001030_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001030_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001030_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001030_0_2 + 9) & 15;
  struct Vector3D_R001030_3013_2 st_var_2_1 = {0};
  struct Vector3D_R001030_3013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001030_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001030_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001030_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001030_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001030_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001030_0_2 + 11) & 15;
  union RegisterBank_R001030_3013_0 u_var_1;
  union RegisterBank_R001030_3013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001030_3013_0(sec_r001030_0_1, sec_r001030_1_1, pub_r001030_2_1, pub_r001030_3_1);
  int helper_flow_0_2 = fn_R001030_3013_0(sec_r001030_0_2, sec_r001030_1_2, pub_r001030_2_2, pub_r001030_3_2);
  fn_R001030_3013_0_2(sec_r001030_0_1, sec_r001030_1_1, pub_r001030_2_1, pub_r001030_3_1, sec_r001030_0_2, sec_r001030_1_2, pub_r001030_2_2, pub_r001030_3_2);
  int helper_flow_1_1 = fn_R001030_3013_1(sec_r001030_1_1, sec_r001030_2_1, pub_r001030_3_1);
  int helper_flow_1_2 = fn_R001030_3013_1(sec_r001030_1_2, sec_r001030_2_2, pub_r001030_3_2);
  fn_R001030_3013_1_2(sec_r001030_1_1, sec_r001030_2_1, pub_r001030_3_1, sec_r001030_1_2, sec_r001030_2_2, pub_r001030_3_2);
  int helper_flow_2_1 = fn_R001030_3013_2(sec_r001030_2_1, pub_r001030_3_1, pub_r001030_4_1, pub_r001030_5_1, pub_r001030_6_1);
  int helper_flow_2_2 = fn_R001030_3013_2(sec_r001030_2_2, pub_r001030_3_2, pub_r001030_4_2, pub_r001030_5_2, pub_r001030_6_2);
  fn_R001030_3013_2_2(sec_r001030_2_1, pub_r001030_3_1, pub_r001030_4_1, pub_r001030_5_1, pub_r001030_6_1, sec_r001030_2_2, pub_r001030_3_2, pub_r001030_4_2, pub_r001030_5_2, pub_r001030_6_2);
  int helper_flow_3_1 = fn_R001030_3013_3(sec_r001030_3_1, sec_r001030_4_1, pub_r001030_5_1, pub_r001030_6_1, pub_r001030_7_1);
  int helper_flow_3_2 = fn_R001030_3013_3(sec_r001030_3_2, sec_r001030_4_2, pub_r001030_5_2, pub_r001030_6_2, pub_r001030_7_2);
  fn_R001030_3013_3_2(sec_r001030_3_1, sec_r001030_4_1, pub_r001030_5_1, pub_r001030_6_1, pub_r001030_7_1, sec_r001030_3_2, sec_r001030_4_2, pub_r001030_5_2, pub_r001030_6_2, pub_r001030_7_2);
  int helper_flow_4_1 = fn_R001030_3013_4(sec_r001030_4_1, sec_r001030_5_1);
  int helper_flow_4_2 = fn_R001030_3013_4(sec_r001030_4_2, sec_r001030_5_2);
  fn_R001030_3013_4_2(sec_r001030_4_1, sec_r001030_5_1, sec_r001030_4_2, sec_r001030_5_2);
  int helper_flow_5_1 = fn_R001030_3013_5(sec_r001030_5_1, pub_r001030_6_1, pub_r001030_7_1, pub_r001030_8_1);
  int helper_flow_5_2 = fn_R001030_3013_5(sec_r001030_5_2, pub_r001030_6_2, pub_r001030_7_2, pub_r001030_8_2);
  fn_R001030_3013_5_2(sec_r001030_5_1, pub_r001030_6_1, pub_r001030_7_1, pub_r001030_8_1, sec_r001030_5_2, pub_r001030_6_2, pub_r001030_7_2, pub_r001030_8_2);
  int helper_flow_6_1 = fn_R001030_3013_6(sec_r001030_6_1, pub_r001030_7_1, pub_r001030_8_1);
  int helper_flow_6_2 = fn_R001030_3013_6(sec_r001030_6_2, pub_r001030_7_2, pub_r001030_8_2);
  fn_R001030_3013_6_2(sec_r001030_6_1, pub_r001030_7_1, pub_r001030_8_1, sec_r001030_6_2, pub_r001030_7_2, pub_r001030_8_2);
  int helper_flow_7_1 = fn_R001030_3013_7(sec_r001030_7_1, sec_r001030_8_1, pub_r001030_9_1);
  int helper_flow_7_2 = fn_R001030_3013_7(sec_r001030_7_2, sec_r001030_8_2, pub_r001030_9_2);
  fn_R001030_3013_7_2(sec_r001030_7_1, sec_r001030_8_1, pub_r001030_9_1, sec_r001030_7_2, sec_r001030_8_2, pub_r001030_9_2);
  int helper_flow_8_1 = fn_R001030_3013_8(sec_r001030_8_1, pub_r001030_9_1, pub_r001030_10_1);
  int helper_flow_8_2 = fn_R001030_3013_8(sec_r001030_8_2, pub_r001030_9_2, pub_r001030_10_2);
  fn_R001030_3013_8_2(sec_r001030_8_1, pub_r001030_9_1, pub_r001030_10_1, sec_r001030_8_2, pub_r001030_9_2, pub_r001030_10_2);
  int helper_flow_9_1 = fn_R001030_3013_9(sec_r001030_9_1, pub_r001030_10_1);
  int helper_flow_9_2 = fn_R001030_3013_9(sec_r001030_9_2, pub_r001030_10_2);
  fn_R001030_3013_9_2(sec_r001030_9_1, pub_r001030_10_1, sec_r001030_9_2, pub_r001030_10_2);
  int helper_flow_10_1 = fn_R001030_3013_10(sec_r001030_10_1, sec_r001030_11_1, pub_r001030_12_1, pub_r001030_13_1, pub_r001030_14_1);
  int helper_flow_10_2 = fn_R001030_3013_10(sec_r001030_10_2, sec_r001030_11_2, pub_r001030_12_2, pub_r001030_13_2, pub_r001030_14_2);
  fn_R001030_3013_10_2(sec_r001030_10_1, sec_r001030_11_1, pub_r001030_12_1, pub_r001030_13_1, pub_r001030_14_1, sec_r001030_10_2, sec_r001030_11_2, pub_r001030_12_2, pub_r001030_13_2, pub_r001030_14_2);
  int stage_v_0_1 = (((sec_r001030_16_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_0_2 = (((sec_r001030_16_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_0_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((sec_r001030_12_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_1_2 = (((sec_r001030_12_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_1_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001030_12_1) & 127;
  int stage_v_2_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001030_12_2) & 127;
  if (stage_v_2_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 13) & 255;
  }
  if (stage_v_2_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((pub_r001030_1_1 * 2) + 16) & 63;
  int stage_v_3_2 = ((pub_r001030_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001030_5_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_4_2 = (((sec_r001030_5_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_4_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001030_10_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_5_2 = (((sec_r001030_10_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_5_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_6_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_6_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((sec_r001030_0_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_7_2 = (((sec_r001030_0_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_7_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((sec_r001030_19_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_8_2 = (((sec_r001030_19_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_8_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001030_12_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_9_2 = (((sec_r001030_12_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
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
  int stage_v_10_1 = ((pub_r001030_19_1 * 2) + 32) & 63;
  int stage_v_10_2 = ((pub_r001030_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001030_14_1 * 2) + 13) & 63;
  int stage_v_11_2 = ((pub_r001030_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_12_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_12_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_13_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_13_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_13_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 13) & 255;
  }
  if (stage_v_13_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_13_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_14_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_14_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
  }
  if (stage_v_14_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = ((pub_r001030_18_1 * 2) + 50) & 63;
  int stage_v_15_2 = ((pub_r001030_18_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((sec_r001030_13_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_16_2 = (((sec_r001030_13_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_16_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_16_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 13) & 255;
  }
  if (stage_v_16_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_16_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_17_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_17_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
  }
  if (stage_v_17_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_17_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = ((pub_r001030_16_1 * 2) + 28) & 63;
  int stage_v_18_2 = ((pub_r001030_16_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = ((pub_r001030_11_1 * 2) + 9) & 63;
  int stage_v_19_2 = ((pub_r001030_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001030_4_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_20_2 = (((sec_r001030_4_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_20_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_21_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_21_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((pub_r001030_16_1 * 2) + 8) & 63;
  int stage_v_22_2 = ((pub_r001030_16_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_23_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_23_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
  }
  if (stage_v_23_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_24_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_24_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((sec_r001030_10_1 ^ 0x2A) * 2) + pub_r001030_16_1) & 127;
  int stage_v_25_2 = (((sec_r001030_10_2 ^ 0x2A) * 2) + pub_r001030_16_2) & 127;
  if (stage_v_25_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001030_6_1) & 127;
  int stage_v_26_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001030_6_2) & 127;
  if (stage_v_26_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((pub_r001030_6_1 * 2) + 29) & 63;
  int stage_v_27_2 = ((pub_r001030_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001030_13_1 * 2) + 10) & 63;
  int stage_v_28_2 = ((pub_r001030_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001030_2_1 * 2) + 24) & 63;
  int stage_v_29_2 = ((pub_r001030_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_30_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_30_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
  }
  if (stage_v_30_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_31_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_31_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_32_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_32_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_33_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_33_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001030_3_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_34_2 = (((sec_r001030_3_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_34_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = ((pub_r001030_18_1 * 2) + 25) & 63;
  int stage_v_35_2 = ((pub_r001030_18_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_36_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_36_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_37_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_37_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
  }
  if (stage_v_37_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = (((sec_r001030_1_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_38_2 = (((sec_r001030_1_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_38_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
  }
  if (stage_v_38_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001030_12_1) & 127;
  int stage_v_39_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001030_12_2) & 127;
  if (stage_v_39_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
  }
  if (stage_v_39_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((pub_r001030_1_1 * 2) + 29) & 63;
  int stage_v_40_2 = ((pub_r001030_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001030_3_1 * 2) + 10) & 63;
  int stage_v_41_2 = ((pub_r001030_3_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((stage_v_1_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_42_2 = (((stage_v_1_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_42_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001030_15_1 * 2) + 14) & 63;
  int stage_v_43_2 = ((pub_r001030_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_44_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_44_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_16_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_45_2 = (((stage_v_16_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_45_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
  }
  if (stage_v_45_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_46_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_46_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_47_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_47_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_48_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_48_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_49_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_49_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_50_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_50_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_51_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_51_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
  }
  if (stage_v_51_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_52_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_52_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_53_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_53_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_54_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_54_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((pub_r001030_10_1 * 2) + 46) & 63;
  int stage_v_55_2 = ((pub_r001030_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_56_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_56_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((sec_r001030_10_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_57_2 = (((sec_r001030_10_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_57_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_58_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_58_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001030_6_1) & 127;
  int stage_v_59_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001030_6_2) & 127;
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
  int stage_v_60_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_60_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_60_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_61_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_61_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((pub_r001030_4_1 * 2) + 49) & 63;
  int stage_v_62_2 = ((pub_r001030_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001030_16_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_63_2 = (((sec_r001030_16_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_63_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_64_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_64_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = ((pub_r001030_11_1 * 2) + 41) & 63;
  int stage_v_65_2 = ((pub_r001030_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_66_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_66_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
  }
  if (stage_v_66_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_67_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_67_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
  }
  if (stage_v_67_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_68_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_68_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
  }
  if (stage_v_68_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_69_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_69_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = ((pub_r001030_3_1 * 2) + 6) & 63;
  int stage_v_70_2 = ((pub_r001030_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((sec_r001030_12_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_71_2 = (((sec_r001030_12_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_71_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
  }
  if (stage_v_71_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_72_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_72_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_73_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_73_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_74_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_74_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_75_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_75_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_76_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_76_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001030_17_1 ^ 0x2A) * 2) + pub_r001030_14_1) & 127;
  int stage_v_77_2 = (((sec_r001030_17_2 ^ 0x2A) * 2) + pub_r001030_14_2) & 127;
  if (stage_v_77_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
  }
  if (stage_v_77_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = ((pub_r001030_17_1 * 2) + 47) & 63;
  int stage_v_78_2 = ((pub_r001030_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_79_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_79_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
  }
  if (stage_v_79_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_80_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_80_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
  }
  if (stage_v_80_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((pub_r001030_19_1 * 2) + 26) & 63;
  int stage_v_81_2 = ((pub_r001030_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001030_14_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_82_2 = (((sec_r001030_14_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_82_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_75_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_83_2 = (((stage_v_75_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_83_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_84_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_84_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
  }
  if (stage_v_84_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = (((sec_r001030_14_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_85_2 = (((sec_r001030_14_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_85_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001030_6_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_86_2 = (((sec_r001030_6_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_86_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((pub_r001030_0_1 * 2) + 12) & 63;
  int stage_v_87_2 = ((pub_r001030_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((sec_r001030_2_1 ^ 0x2A) * 2) + pub_r001030_16_1) & 127;
  int stage_v_88_2 = (((sec_r001030_2_2 ^ 0x2A) * 2) + pub_r001030_16_2) & 127;
  if (stage_v_88_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((pub_r001030_8_1 * 2) + 38) & 63;
  int stage_v_89_2 = ((pub_r001030_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001030_20_1 * 2) + 36) & 63;
  int stage_v_90_2 = ((pub_r001030_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_91_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_91_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((pub_r001030_9_1 * 2) + 17) & 63;
  int stage_v_92_2 = ((pub_r001030_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((sec_r001030_10_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_93_2 = (((sec_r001030_10_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_93_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_13_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_94_2 = (((stage_v_13_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_94_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_95_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_95_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_96_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_96_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001030_15_1 * 2) + 6) & 63;
  int stage_v_97_2 = ((pub_r001030_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_98_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_98_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_99_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_99_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = (((stage_v_30_1 ^ 0x2A) * 2) + pub_r001030_16_1) & 127;
  int stage_v_100_2 = (((stage_v_30_2 ^ 0x2A) * 2) + pub_r001030_16_2) & 127;
  if (stage_v_100_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((pub_r001030_16_1 * 2) + 24) & 63;
  int stage_v_101_2 = ((pub_r001030_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_102_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_102_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001030_14_1) & 127;
  int stage_v_103_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001030_14_2) & 127;
  if (stage_v_103_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_104_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_104_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_105_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_105_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((pub_r001030_1_1 * 2) + 17) & 63;
  int stage_v_106_2 = ((pub_r001030_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_107_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_107_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_108_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_108_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_109_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_109_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_39_1 ^ 0x2A) * 2) + pub_r001030_17_1) & 127;
  int stage_v_110_2 = (((stage_v_39_2 ^ 0x2A) * 2) + pub_r001030_17_2) & 127;
  if (stage_v_110_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((sec_r001030_18_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_111_2 = (((sec_r001030_18_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_111_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = (((sec_r001030_7_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_112_2 = (((sec_r001030_7_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_112_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = (((sec_r001030_3_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_113_2 = (((sec_r001030_3_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_113_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((pub_r001030_8_1 * 2) + 50) & 63;
  int stage_v_114_2 = ((pub_r001030_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_115_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_115_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_116_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_116_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_117_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_117_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_118_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_118_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = (((stage_v_102_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_119_2 = (((stage_v_102_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_119_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = (((stage_v_112_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_120_2 = (((stage_v_112_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_120_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((pub_r001030_12_1 * 2) + 28) & 63;
  int stage_v_121_2 = ((pub_r001030_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001030_11_1 * 2) + 28) & 63;
  int stage_v_122_2 = ((pub_r001030_11_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_123_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_123_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_124_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_124_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001030_16_1) & 127;
  int stage_v_125_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001030_16_2) & 127;
  if (stage_v_125_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001030_6_1) & 127;
  int stage_v_126_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001030_6_2) & 127;
  if (stage_v_126_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_127_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_127_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((sec_r001030_1_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_128_2 = (((sec_r001030_1_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_128_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((pub_r001030_11_1 * 2) + 8) & 63;
  int stage_v_129_2 = ((pub_r001030_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_130_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_130_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = (((stage_v_45_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_131_2 = (((stage_v_45_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_131_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((pub_r001030_13_1 * 2) + 46) & 63;
  int stage_v_132_2 = ((pub_r001030_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_133_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_133_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((sec_r001030_12_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_134_2 = (((sec_r001030_12_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_134_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001030_6_1 * 2) + 39) & 63;
  int stage_v_135_2 = ((pub_r001030_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_136_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_136_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((stage_v_38_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_137_2 = (((stage_v_38_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_137_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((pub_r001030_10_1 * 2) + 33) & 63;
  int stage_v_138_2 = ((pub_r001030_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001030_6_1 * 2) + 27) & 63;
  int stage_v_139_2 = ((pub_r001030_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((sec_r001030_8_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_140_2 = (((sec_r001030_8_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_140_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_141_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_141_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_142_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_142_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_143_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_143_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_144_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_144_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((sec_r001030_1_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_145_2 = (((sec_r001030_1_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_145_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_146_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_146_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001030_1_1 * 2) + 38) & 63;
  int stage_v_147_2 = ((pub_r001030_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((sec_r001030_9_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_148_2 = (((sec_r001030_9_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_148_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((pub_r001030_18_1 * 2) + 27) & 63;
  int stage_v_149_2 = ((pub_r001030_18_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001030_11_1 * 2) + 24) & 63;
  int stage_v_150_2 = ((pub_r001030_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001030_12_1) & 127;
  int stage_v_151_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001030_12_2) & 127;
  if (stage_v_151_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((sec_r001030_10_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_152_2 = (((sec_r001030_10_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_152_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_56_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_153_2 = (((stage_v_56_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_153_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_103_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_154_2 = (((stage_v_103_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_154_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = (((sec_r001030_0_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_155_2 = (((sec_r001030_0_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_155_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_156_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_156_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((pub_r001030_20_1 * 2) + 36) & 63;
  int stage_v_157_2 = ((pub_r001030_20_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = ((pub_r001030_19_1 * 2) + 16) & 63;
  int stage_v_158_2 = ((pub_r001030_19_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001030_16_1 * 2) + 32) & 63;
  int stage_v_159_2 = ((pub_r001030_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((sec_r001030_9_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_160_2 = (((sec_r001030_9_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_160_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_161_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
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
  int stage_v_162_1 = ((pub_r001030_10_1 * 2) + 41) & 63;
  int stage_v_162_2 = ((pub_r001030_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001030_12_1 * 2) + 42) & 63;
  int stage_v_163_2 = ((pub_r001030_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001030_12_1) & 127;
  int stage_v_164_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001030_12_2) & 127;
  if (stage_v_164_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_165_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_165_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = (((stage_v_148_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_166_2 = (((stage_v_148_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_166_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_68_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_167_2 = (((stage_v_68_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_167_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001030_14_1) & 127;
  int stage_v_168_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001030_14_2) & 127;
  if (stage_v_168_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = (((stage_v_123_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_169_2 = (((stage_v_123_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_169_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((pub_r001030_2_1 * 2) + 25) & 63;
  int stage_v_170_2 = ((pub_r001030_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_118_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_171_2 = (((stage_v_118_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_171_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((pub_r001030_19_1 * 2) + 21) & 63;
  int stage_v_172_2 = ((pub_r001030_19_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_173_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_173_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001030_2_1 * 2) + 26) & 63;
  int stage_v_174_2 = ((pub_r001030_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((sec_r001030_17_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_175_2 = (((sec_r001030_17_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_175_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = (((stage_v_67_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_176_2 = (((stage_v_67_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_176_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((pub_r001030_15_1 * 2) + 18) & 63;
  int stage_v_177_2 = ((pub_r001030_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_178_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_178_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((pub_r001030_19_1 * 2) + 43) & 63;
  int stage_v_179_2 = ((pub_r001030_19_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_178_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_180_2 = (((stage_v_178_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_180_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_71_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_181_2 = (((stage_v_71_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_181_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_104_1 ^ 0x2A) * 2) + pub_r001030_18_1) & 127;
  int stage_v_182_2 = (((stage_v_104_2 ^ 0x2A) * 2) + pub_r001030_18_2) & 127;
  if (stage_v_182_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((pub_r001030_7_1 * 2) + 9) & 63;
  int stage_v_183_2 = ((pub_r001030_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_176_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_184_2 = (((stage_v_176_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_184_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((pub_r001030_19_1 * 2) + 8) & 63;
  int stage_v_185_2 = ((pub_r001030_19_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_2_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_186_2 = (((stage_v_2_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_186_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001030_16_1) & 127;
  int stage_v_187_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001030_16_2) & 127;
  if (stage_v_187_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((pub_r001030_4_1 * 2) + 25) & 63;
  int stage_v_188_2 = ((pub_r001030_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_189_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_189_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = (((stage_v_133_1 ^ 0x2A) * 2) + pub_r001030_2_1) & 127;
  int stage_v_190_2 = (((stage_v_133_2 ^ 0x2A) * 2) + pub_r001030_2_2) & 127;
  if (stage_v_190_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_181_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_191_2 = (((stage_v_181_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_191_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_34_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_192_2 = (((stage_v_34_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_192_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_175_1 ^ 0x2A) * 2) + pub_r001030_1_1) & 127;
  int stage_v_193_2 = (((stage_v_175_2 ^ 0x2A) * 2) + pub_r001030_1_2) & 127;
  if (stage_v_193_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = (((helper_flow_5_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_194_2 = (((helper_flow_5_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_194_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001030_4_1) & 127;
  int stage_v_195_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001030_4_2) & 127;
  if (stage_v_195_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = (((stage_v_155_1 ^ 0x2A) * 2) + pub_r001030_15_1) & 127;
  int stage_v_196_2 = (((stage_v_155_2 ^ 0x2A) * 2) + pub_r001030_15_2) & 127;
  if (stage_v_196_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001030_11_1) & 127;
  int stage_v_197_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001030_11_2) & 127;
  if (stage_v_197_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((pub_r001030_8_1 * 2) + 6) & 63;
  int stage_v_198_2 = ((pub_r001030_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((stage_v_53_1 ^ 0x2A) * 2) + pub_r001030_20_1) & 127;
  int stage_v_199_2 = (((stage_v_53_2 ^ 0x2A) * 2) + pub_r001030_20_2) & 127;
  if (stage_v_199_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001030_8_1) & 127;
  int stage_v_200_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001030_8_2) & 127;
  if (stage_v_200_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((pub_r001030_12_1 * 2) + 15) & 63;
  int stage_v_201_2 = ((pub_r001030_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_58_1 ^ 0x2A) * 2) + pub_r001030_0_1) & 127;
  int stage_v_202_2 = (((stage_v_58_2 ^ 0x2A) * 2) + pub_r001030_0_2) & 127;
  if (stage_v_202_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((sec_r001030_13_1 ^ 0x2A) * 2) + pub_r001030_9_1) & 127;
  int stage_v_203_2 = (((sec_r001030_13_2 ^ 0x2A) * 2) + pub_r001030_9_2) & 127;
  if (stage_v_203_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = (((sec_r001030_4_1 ^ 0x2A) * 2) + pub_r001030_19_1) & 127;
  int stage_v_204_2 = (((sec_r001030_4_2 ^ 0x2A) * 2) + pub_r001030_19_2) & 127;
  if (stage_v_204_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = (((stage_v_42_1 ^ 0x2A) * 2) + pub_r001030_3_1) & 127;
  int stage_v_205_2 = (((stage_v_42_2 ^ 0x2A) * 2) + pub_r001030_3_2) & 127;
  if (stage_v_205_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((pub_r001030_7_1 * 2) + 12) & 63;
  int stage_v_206_2 = ((pub_r001030_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001030_21_1) & 127;
  int stage_v_207_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001030_21_2) & 127;
  if (stage_v_207_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001030_10_1) & 127;
  int stage_v_208_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001030_10_2) & 127;
  if (stage_v_208_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((sec_r001030_17_1 ^ 0x2A) * 2) + pub_r001030_13_1) & 127;
  int stage_v_209_2 = (((sec_r001030_17_2 ^ 0x2A) * 2) + pub_r001030_13_2) & 127;
  if (stage_v_209_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = (((sec_r001030_19_1 ^ 0x2A) * 2) + pub_r001030_14_1) & 127;
  int stage_v_210_2 = (((sec_r001030_19_2 ^ 0x2A) * 2) + pub_r001030_14_2) & 127;
  if (stage_v_210_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = (((stage_v_192_1 ^ 0x2A) * 2) + pub_r001030_7_1) & 127;
  int stage_v_211_2 = (((stage_v_192_2 ^ 0x2A) * 2) + pub_r001030_7_2) & 127;
  if (stage_v_211_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((pub_r001030_16_1 * 2) + 5) & 63;
  int stage_v_212_2 = ((pub_r001030_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_124_1 ^ 0x2A) * 2) + pub_r001030_5_1) & 127;
  int stage_v_213_2 = (((stage_v_124_2 ^ 0x2A) * 2) + pub_r001030_5_2) & 127;
  if (stage_v_213_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = (((stage_v_17_1 ^ 0x2A) * 2) + pub_r001030_6_1) & 127;
  int stage_v_214_2 = (((stage_v_17_2 ^ 0x2A) * 2) + pub_r001030_6_2) & 127;
  if (stage_v_214_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001030_13_1 != sec_r001030_13_2);
  __CPROVER_assume(sec_r001030_2_1 != sec_r001030_2_2);
  __CPROVER_assume(sec_r001030_5_1 != sec_r001030_5_2);
  __CPROVER_assume(pub_r001030_8_1 == pub_r001030_8_2);
  __CPROVER_assume(pub_r001030_21_1 == pub_r001030_21_2);
  __CPROVER_assume(sec_r001030_3_1 != sec_r001030_3_2);
  __CPROVER_assume(pub_r001030_4_1 == pub_r001030_4_2);
  __CPROVER_assume(pub_r001030_5_1 == pub_r001030_5_2);
  __CPROVER_assume(pub_r001030_1_1 == pub_r001030_1_2);
  __CPROVER_assume(sec_r001030_10_1 != sec_r001030_10_2);
  __CPROVER_assume(sec_r001030_8_1 != sec_r001030_8_2);
  __CPROVER_assume(pub_r001030_14_1 == pub_r001030_14_2);
  __CPROVER_assume(pub_r001030_16_1 == pub_r001030_16_2);
  __CPROVER_assume(pub_r001030_2_1 == pub_r001030_2_2);
  __CPROVER_assume(sec_r001030_14_1 != sec_r001030_14_2);
  __CPROVER_assume(pub_r001030_19_1 == pub_r001030_19_2);
  __CPROVER_assume(pub_r001030_10_1 == pub_r001030_10_2);
  __CPROVER_assume(sec_r001030_17_1 != sec_r001030_17_2);
  __CPROVER_assume(sec_r001030_16_1 != sec_r001030_16_2);
  __CPROVER_assume(pub_r001030_20_1 == pub_r001030_20_2);
  __CPROVER_assume(pub_r001030_3_1 == pub_r001030_3_2);
  __CPROVER_assume(sec_r001030_0_1 != sec_r001030_0_2);
  __CPROVER_assume(pub_r001030_13_1 == pub_r001030_13_2);
  __CPROVER_assume(sec_r001030_19_1 != sec_r001030_19_2);
  __CPROVER_assume(pub_r001030_12_1 == pub_r001030_12_2);
  __CPROVER_assume(pub_r001030_17_1 == pub_r001030_17_2);
  __CPROVER_assume(sec_r001030_6_1 != sec_r001030_6_2);
  __CPROVER_assume(pub_r001030_6_1 == pub_r001030_6_2);
  __CPROVER_assume(pub_r001030_11_1 == pub_r001030_11_2);
  __CPROVER_assume(pub_r001030_18_1 == pub_r001030_18_2);
  __CPROVER_assume(sec_r001030_9_1 != sec_r001030_9_2);
  __CPROVER_assume(sec_r001030_15_1 != sec_r001030_15_2);
  __CPROVER_assume(pub_r001030_9_1 == pub_r001030_9_2);
  __CPROVER_assume(sec_r001030_18_1 != sec_r001030_18_2);
  __CPROVER_assume(sec_r001030_7_1 != sec_r001030_7_2);
  __CPROVER_assume(sec_r001030_4_1 != sec_r001030_4_2);
  __CPROVER_assume(sec_r001030_11_1 != sec_r001030_11_2);
  __CPROVER_assume(pub_r001030_7_1 == pub_r001030_7_2);
  __CPROVER_assume(pub_r001030_15_1 == pub_r001030_15_2);
  __CPROVER_assume(sec_r001030_1_1 != sec_r001030_1_2);
  __CPROVER_assume(sec_r001030_12_1 != sec_r001030_12_2);
  __CPROVER_assume(pub_r001030_0_1 == pub_r001030_0_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.severity == st_var_0_2.severity);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.facility == st_var_0_2.facility);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
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
}


