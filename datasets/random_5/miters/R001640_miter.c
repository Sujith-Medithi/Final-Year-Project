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
struct SensorNode_R001640_4013_0
{
  int gain;
  unsigned char threshold;
  short calib;
  int buffer[3];
};
struct EventLog_R001640_4013_1
{
  int timestamp;
  int severity;
  int facility;
  short seq;
  short code;
  int buffer[3];
};
struct Vector3D_R001640_4013_2
{
  unsigned char coord_z;
  short heading;
  short coord_x;
  short coord_y;
  int buffer[3];
};
struct CipherContext_R001640_4013_3
{
  unsigned char iv;
  short nonce;
  int counter;
  int buffer[3];
};
union ColorPixel_R001640_4013_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001640_4013_1
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
void fn_R001640_4013_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st_1 = {0};
  struct CipherContext_R001640_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int pivot_44_1 = 0;
  int pivot_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_44_1 = ((pivot_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_44_2 = ((pivot_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_44_1) & 127;
    acc_2 = (acc_2 + pivot_44_2) & 127;
  }

  int factor_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_23_1)
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

  switch (factor_23_2)
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
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_44_1 == pivot_44_2);
  assert(factor_23_1 == factor_23_2);
}

int fn_R001640_4013_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int pivot_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_44 = ((pivot_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_44) & 127;
  }

  int factor_23 = (aux + st.buffer[1]) & 3;
  switch (factor_23)
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

void fn_R001640_4013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st_1 = {0};
  struct EventLog_R001640_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int cursor_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_43_1 > 11)
  {
    acc_1 = ((acc_1 + (cursor_43_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_43_2 > 11)
  {
    acc_2 = ((acc_2 + (cursor_43_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_43_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_55_1 = 0;
  int parity_55_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_55_1 = ((parity_55_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_55_2 = ((parity_55_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_55_1) & 127;
    acc_2 = (acc_2 + parity_55_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_77_1 = local_arr_1[aux_1 % 3];
  int offset_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_77_2 * 2)) & 127;
  int tally_40_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_40_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_40_1) & 63;
  aux_2 = (aux_2 + tally_40_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_43_1 == cursor_43_2);
  assert(parity_55_1 == parity_55_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(tally_40_1 == tally_40_2);
}

int fn_R001640_4013_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int cursor_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_43 > 11)
  {
    acc = ((acc + (cursor_43 * 2)) + 5) & 127;
    aux ^= cursor_43 & 15;
  }
  else
  {
    acc = ((acc - cursor_43) + 11) & 127;
    aux += 3;
  }
  int parity_55 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_55 = ((parity_55 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_55) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_77 = local_arr[aux % 3];
  acc = (acc + (offset_77 * 2)) & 127;
  int tally_40 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_40) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001640_4013_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st_1 = {0};
  struct Vector3D_R001640_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int index_reg_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_22_1)
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

  switch (index_reg_22_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_83_1 = 0;
  int factor_83_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_83_1 = ((factor_83_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_83_2 = ((factor_83_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_83_1) & 127;
    acc_2 = (acc_2 + factor_83_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_82_1 = local_arr_1[aux_1 % 3];
  int offset_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_22_1 == index_reg_22_2);
  assert(factor_83_1 == factor_83_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_82_1 == offset_82_2);
}

int fn_R001640_4013_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int index_reg_22 = (aux + st.buffer[1]) & 3;
  switch (index_reg_22)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_83 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_83 = ((factor_83 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_83) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_82 = local_arr[aux % 3];
  acc = (acc + (offset_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001640_4013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st_1 = {0};
  struct EventLog_R001640_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int offset_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_60_1 > 16)
  {
    acc_1 = ((acc_1 + (offset_60_1 * 2)) + 5) & 127;
    aux_1 ^= offset_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_60_2 > 16)
  {
    acc_2 = ((acc_2 + (offset_60_2 * 2)) + 5) & 127;
    aux_2 ^= offset_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_81_1 = local_arr_1[aux_1 % 3];
  int delta_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_81_2 * 2)) & 127;
  int segment_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_69_1) & 63;
  aux_2 = (aux_2 + segment_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_71_1)
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

  switch (scale_71_2)
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
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_60_1 == offset_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_81_1 == delta_81_2);
  assert(segment_69_1 == segment_69_2);
  assert(scale_71_1 == scale_71_2);
}

int fn_R001640_4013_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int offset_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_60 > 16)
  {
    acc = ((acc + (offset_60 * 2)) + 5) & 127;
    aux ^= offset_60 & 15;
  }
  else
  {
    acc = ((acc - offset_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_81 = local_arr[aux % 3];
  acc = (acc + (delta_81 * 2)) & 127;
  int segment_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_69) & 63;
  acc ^= aux;
  int scale_71 = (aux + st.buffer[1]) & 3;
  switch (scale_71)
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

void fn_R001640_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st_1 = {0};
  struct Vector3D_R001640_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int phase_58_1 = 0;
  int phase_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    phase_58_1 = ((phase_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    phase_58_2 = ((phase_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + phase_58_1) & 127;
    acc_2 = (acc_2 + phase_58_2) & 127;
  }

  int accumulator_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_51_1 > 44)
  {
    acc_1 = ((acc_1 + (accumulator_51_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_51_2 > 44)
  {
    acc_2 = ((acc_2 + (accumulator_51_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_15_1)
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

  switch (weight_15_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_58_1 == phase_58_2);
  assert(accumulator_51_1 == accumulator_51_2);
  assert(weight_15_1 == weight_15_2);
}

int fn_R001640_4013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int phase_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    phase_58 = ((phase_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + phase_58) & 127;
  }

  int accumulator_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_51 > 44)
  {
    acc = ((acc + (accumulator_51 * 2)) + 5) & 127;
    aux ^= accumulator_51 & 15;
  }
  else
  {
    acc = ((acc - accumulator_51) + 11) & 127;
    aux += 3;
  }
  int weight_15 = (aux + st.buffer[1]) & 3;
  switch (weight_15)
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

  return (acc + aux) & 255;
}

void fn_R001640_4013_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st_1 = {0};
  struct Vector3D_R001640_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_78_1 = 0;
  int bound_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_78_1 = ((bound_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_78_2 = ((bound_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_78_1) & 127;
    acc_2 = (acc_2 + bound_78_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_80_1 = local_arr_1[aux_1 % 3];
  int factor_80_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_80_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_80_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_80_1 == factor_80_2);
}

int fn_R001640_4013_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_78 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_78 = ((bound_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_78) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int factor_80 = local_arr[aux % 3];
  acc = (acc + (factor_80 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001640_4013_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st_1 = {0};
  struct CipherContext_R001640_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_24_1)
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

  switch (window_24_2)
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

  int segment_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_11_1) & 63;
  aux_2 = (aux_2 + segment_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_24_1 == window_24_2);
  assert(segment_11_1 == segment_11_2);
}

int fn_R001640_4013_6(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_24 = (aux + st.buffer[1]) & 3;
  switch (window_24)
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

  int segment_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_11) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001640_4013_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st_1 = {0};
  struct Vector3D_R001640_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_54_1) & 63;
  aux_2 = (aux_2 + anchor_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int accumulator_29_1 = 0;
  int accumulator_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_29_1 = ((accumulator_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_29_2 = ((accumulator_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_29_1) & 127;
    acc_2 = (acc_2 + accumulator_29_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_54_1 == anchor_54_2);
  assert(accumulator_29_1 == accumulator_29_2);
}

int fn_R001640_4013_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_54) & 63;
  acc ^= aux;
  int accumulator_29 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_29 = ((accumulator_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_29) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001640_4013_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st_1 = {0};
  struct EventLog_R001640_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_94_1) & 63;
  aux_2 = (aux_2 + tracker_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_40_1 = 0;
  int damping_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_40_1 = ((damping_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_40_2 = ((damping_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_40_1) & 127;
    acc_2 = (acc_2 + damping_40_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_94_1 == tracker_94_2);
  assert(damping_40_1 == damping_40_2);
}

int fn_R001640_4013_8(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_40 = ((damping_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_40) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001640_4013_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st_1 = {0};
  struct SensorNode_R001640_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_64_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_64_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_64_1)
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

  switch (residue_64_2)
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
  int index_reg_92_1 = local_arr_1[aux_1 % 3];
  int index_reg_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_92_2 * 2)) & 127;
  int factor_40_1 = 0;
  int factor_40_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_40_1 = ((factor_40_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_40_2 = ((factor_40_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_40_1) & 127;
    acc_2 = (acc_2 + factor_40_2) & 127;
  }

  int window_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_76_1 > 18)
  {
    acc_1 = ((acc_1 + (window_76_1 * 2)) + 5) & 127;
    aux_1 ^= window_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_76_2 > 18)
  {
    acc_2 = ((acc_2 + (window_76_2 * 2)) + 5) & 127;
    aux_2 ^= window_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_76_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_64_1 == residue_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_92_1 == index_reg_92_2);
  assert(factor_40_1 == factor_40_2);
  assert(window_76_1 == window_76_2);
}

int fn_R001640_4013_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_64 = (aux + st.buffer[1]) & 3;
  switch (residue_64)
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
  int index_reg_92 = local_arr[aux % 3];
  acc = (acc + (index_reg_92 * 2)) & 127;
  int factor_40 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_40 = ((factor_40 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_40) & 127;
  }

  int window_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_76 > 18)
  {
    acc = ((acc + (window_76 * 2)) + 5) & 127;
    aux ^= window_76 & 15;
  }
  else
  {
    acc = ((acc - window_76) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001640_4013_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st_1 = {0};
  struct EventLog_R001640_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int anchor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_99_1 > 11)
  {
    acc_1 = ((acc_1 + (anchor_99_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_99_2 > 11)
  {
    acc_2 = ((acc_2 + (anchor_99_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_84_1)
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

  switch (window_84_2)
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
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_99_1 == anchor_99_2);
  assert(window_84_1 == window_84_2);
}

int fn_R001640_4013_10(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int anchor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_99 > 11)
  {
    acc = ((acc + (anchor_99 * 2)) + 5) & 127;
    aux ^= anchor_99 & 15;
  }
  else
  {
    acc = ((acc - anchor_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_84 = (aux + st.buffer[1]) & 3;
  switch (window_84)
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

void fn_R001640_4013_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st_1 = {0};
  struct CipherContext_R001640_4013_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int accumulator_20_1 = 0;
  int accumulator_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    accumulator_20_1 = ((accumulator_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_20_2 = ((accumulator_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_20_1) & 127;
    acc_2 = (acc_2 + accumulator_20_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_79_1 = local_arr_1[aux_1 % 3];
  int checksum_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.iv == st_2.iv);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.counter == st_2.counter);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_20_1 == accumulator_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_79_1 == checksum_79_2);
}

int fn_R001640_4013_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001640_4013_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int accumulator_20 = 0;
  for (int k = 0; k < 3; k++)
  {
    accumulator_20 = ((accumulator_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_20) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int checksum_79 = local_arr[aux % 3];
  acc = (acc + (checksum_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001640_4013_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st_1 = {0};
  struct SensorNode_R001640_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int offset_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_77_1 > 24)
  {
    acc_1 = ((acc_1 + (offset_77_1 * 2)) + 5) & 127;
    aux_1 ^= offset_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_77_2 > 24)
  {
    acc_2 = ((acc_2 + (offset_77_2 * 2)) + 5) & 127;
    aux_2 ^= offset_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_74_1)
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

  switch (index_reg_74_2)
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

  int metric_69_1 = 0;
  int metric_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_69_1 = ((metric_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_69_2 = ((metric_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_69_1) & 127;
    acc_2 = (acc_2 + metric_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_77_1 == offset_77_2);
  assert(index_reg_74_1 == index_reg_74_2);
  assert(metric_69_1 == metric_69_2);
}

int fn_R001640_4013_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int offset_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_77 > 24)
  {
    acc = ((acc + (offset_77 * 2)) + 5) & 127;
    aux ^= offset_77 & 15;
  }
  else
  {
    acc = ((acc - offset_77) + 11) & 127;
    aux += 3;
  }
  int index_reg_74 = (aux + st.buffer[1]) & 3;
  switch (index_reg_74)
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

  int metric_69 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_69 = ((metric_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001640_4013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st_1 = {0};
  struct SensorNode_R001640_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int residue_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_55_1 > 32)
  {
    acc_1 = ((acc_1 + (residue_55_1 * 2)) + 5) & 127;
    aux_1 ^= residue_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_55_2 > 32)
  {
    acc_2 = ((acc_2 + (residue_55_2 * 2)) + 5) & 127;
    aux_2 ^= residue_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_42_1)
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

  switch (metric_42_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_63_1 = local_arr_1[aux_1 % 3];
  int vector_63_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_63_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_63_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_55_1 == residue_55_2);
  assert(metric_42_1 == metric_42_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_63_1 == vector_63_2);
}

int fn_R001640_4013_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001640_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int residue_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_55 > 32)
  {
    acc = ((acc + (residue_55 * 2)) + 5) & 127;
    aux ^= residue_55 & 15;
  }
  else
  {
    acc = ((acc - residue_55) + 11) & 127;
    aux += 3;
  }
  int metric_42 = (aux + st.buffer[1]) & 3;
  switch (metric_42)
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

  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_63 = local_arr[aux % 3];
  acc = (acc + (vector_63 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001640_4013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st_1 = {0};
  struct EventLog_R001640_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int damping_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_55_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_55_1 * 2)) + 5) & 127;
    aux_1 ^= damping_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_55_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_55_2 * 2)) + 5) & 127;
    aux_2 ^= damping_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_41_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_41_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_41_1) & 63;
  aux_2 = (aux_2 + stride_41_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_10_1 = 0;
  int delta_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_10_1 = ((delta_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_10_2 = ((delta_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_10_1) & 127;
    acc_2 = (acc_2 + delta_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.severity == st_2.severity);
  assert(st_1.facility == st_2.facility);
  assert(st_1.seq == st_2.seq);
  assert(st_1.code == st_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_55_1 == damping_55_2);
  assert(stride_41_1 == stride_41_2);
  assert(delta_10_1 == delta_10_2);
}

int fn_R001640_4013_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R001640_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int damping_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_55 > 22)
  {
    acc = ((acc + (damping_55 * 2)) + 5) & 127;
    aux ^= damping_55 & 15;
  }
  else
  {
    acc = ((acc - damping_55) + 11) & 127;
    aux += 3;
  }
  int stride_41 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_41) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_10 = ((delta_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001640_4013_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st_1 = {0};
  struct Vector3D_R001640_4013_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_95_1 = local_arr_1[aux_1 % 3];
  int tracker_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_95_1 == tracker_95_2);
}

int fn_R001640_4013_15(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001640_4013_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int tracker_95 = local_arr[aux % 3];
  acc = (acc + (tracker_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001640_0_1;
  int sec_r001640_0_2;
  int sec_r001640_1_1;
  int sec_r001640_1_2;
  int sec_r001640_2_1;
  int sec_r001640_2_2;
  int sec_r001640_3_1;
  int sec_r001640_3_2;
  int sec_r001640_4_1;
  int sec_r001640_4_2;
  int sec_r001640_5_1;
  int sec_r001640_5_2;
  int sec_r001640_6_1;
  int sec_r001640_6_2;
  int sec_r001640_7_1;
  int sec_r001640_7_2;
  int sec_r001640_8_1;
  int sec_r001640_8_2;
  int sec_r001640_9_1;
  int sec_r001640_9_2;
  int sec_r001640_10_1;
  int sec_r001640_10_2;
  int sec_r001640_11_1;
  int sec_r001640_11_2;
  int sec_r001640_12_1;
  int sec_r001640_12_2;
  int sec_r001640_13_1;
  int sec_r001640_13_2;
  int sec_r001640_14_1;
  int sec_r001640_14_2;
  int sec_r001640_15_1;
  int sec_r001640_15_2;
  int sec_r001640_16_1;
  int sec_r001640_16_2;
  int sec_r001640_17_1;
  int sec_r001640_17_2;
  int sec_r001640_18_1;
  int sec_r001640_18_2;
  int sec_r001640_19_1;
  int sec_r001640_19_2;
  int sec_r001640_20_1;
  int sec_r001640_20_2;
  int sec_r001640_21_1;
  int sec_r001640_21_2;
  int pub_r001640_0_1;
  int pub_r001640_0_2;
  int pub_r001640_1_1;
  int pub_r001640_1_2;
  int pub_r001640_2_1;
  int pub_r001640_2_2;
  int pub_r001640_3_1;
  int pub_r001640_3_2;
  int pub_r001640_4_1;
  int pub_r001640_4_2;
  int pub_r001640_5_1;
  int pub_r001640_5_2;
  int pub_r001640_6_1;
  int pub_r001640_6_2;
  int pub_r001640_7_1;
  int pub_r001640_7_2;
  int pub_r001640_8_1;
  int pub_r001640_8_2;
  int pub_r001640_9_1;
  int pub_r001640_9_2;
  int pub_r001640_10_1;
  int pub_r001640_10_2;
  int pub_r001640_11_1;
  int pub_r001640_11_2;
  int pub_r001640_12_1;
  int pub_r001640_12_2;
  int pub_r001640_13_1;
  int pub_r001640_13_2;
  int pub_r001640_14_1;
  int pub_r001640_14_2;
  int pub_r001640_15_1;
  int pub_r001640_15_2;
  int pub_r001640_16_1;
  int pub_r001640_16_2;
  int pub_r001640_17_1;
  int pub_r001640_17_2;
  int pub_r001640_18_1;
  int pub_r001640_18_2;
  int pub_r001640_19_1;
  int pub_r001640_19_2;
  int pub_r001640_20_1;
  int pub_r001640_20_2;
  int pub_r001640_21_1;
  int pub_r001640_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001640_0_1 >= (-100)) && (pub_r001640_0_1 <= 100));
  __CPROVER_assume((pub_r001640_0_2 >= (-100)) && (pub_r001640_0_2 <= 100));
  __CPROVER_assume((pub_r001640_1_1 >= (-100)) && (pub_r001640_1_1 <= 100));
  __CPROVER_assume((pub_r001640_1_2 >= (-100)) && (pub_r001640_1_2 <= 100));
  __CPROVER_assume((pub_r001640_2_1 >= (-100)) && (pub_r001640_2_1 <= 100));
  __CPROVER_assume((pub_r001640_2_2 >= (-100)) && (pub_r001640_2_2 <= 100));
  __CPROVER_assume((pub_r001640_3_1 >= (-100)) && (pub_r001640_3_1 <= 100));
  __CPROVER_assume((pub_r001640_3_2 >= (-100)) && (pub_r001640_3_2 <= 100));
  __CPROVER_assume((pub_r001640_4_1 >= (-100)) && (pub_r001640_4_1 <= 100));
  __CPROVER_assume((pub_r001640_4_2 >= (-100)) && (pub_r001640_4_2 <= 100));
  __CPROVER_assume((pub_r001640_5_1 >= (-100)) && (pub_r001640_5_1 <= 100));
  __CPROVER_assume((pub_r001640_5_2 >= (-100)) && (pub_r001640_5_2 <= 100));
  __CPROVER_assume((pub_r001640_6_1 >= (-100)) && (pub_r001640_6_1 <= 100));
  __CPROVER_assume((pub_r001640_6_2 >= (-100)) && (pub_r001640_6_2 <= 100));
  __CPROVER_assume((pub_r001640_7_1 >= (-100)) && (pub_r001640_7_1 <= 100));
  __CPROVER_assume((pub_r001640_7_2 >= (-100)) && (pub_r001640_7_2 <= 100));
  __CPROVER_assume((pub_r001640_8_1 >= (-100)) && (pub_r001640_8_1 <= 100));
  __CPROVER_assume((pub_r001640_8_2 >= (-100)) && (pub_r001640_8_2 <= 100));
  __CPROVER_assume((pub_r001640_9_1 >= (-100)) && (pub_r001640_9_1 <= 100));
  __CPROVER_assume((pub_r001640_9_2 >= (-100)) && (pub_r001640_9_2 <= 100));
  __CPROVER_assume((pub_r001640_10_1 >= (-100)) && (pub_r001640_10_1 <= 100));
  __CPROVER_assume((pub_r001640_10_2 >= (-100)) && (pub_r001640_10_2 <= 100));
  __CPROVER_assume((pub_r001640_11_1 >= (-100)) && (pub_r001640_11_1 <= 100));
  __CPROVER_assume((pub_r001640_11_2 >= (-100)) && (pub_r001640_11_2 <= 100));
  __CPROVER_assume((pub_r001640_12_1 >= (-100)) && (pub_r001640_12_1 <= 100));
  __CPROVER_assume((pub_r001640_12_2 >= (-100)) && (pub_r001640_12_2 <= 100));
  __CPROVER_assume((pub_r001640_13_1 >= (-100)) && (pub_r001640_13_1 <= 100));
  __CPROVER_assume((pub_r001640_13_2 >= (-100)) && (pub_r001640_13_2 <= 100));
  __CPROVER_assume((pub_r001640_14_1 >= (-100)) && (pub_r001640_14_1 <= 100));
  __CPROVER_assume((pub_r001640_14_2 >= (-100)) && (pub_r001640_14_2 <= 100));
  __CPROVER_assume((pub_r001640_15_1 >= (-100)) && (pub_r001640_15_1 <= 100));
  __CPROVER_assume((pub_r001640_15_2 >= (-100)) && (pub_r001640_15_2 <= 100));
  __CPROVER_assume((pub_r001640_16_1 >= (-100)) && (pub_r001640_16_1 <= 100));
  __CPROVER_assume((pub_r001640_16_2 >= (-100)) && (pub_r001640_16_2 <= 100));
  __CPROVER_assume((pub_r001640_17_1 >= (-100)) && (pub_r001640_17_1 <= 100));
  __CPROVER_assume((pub_r001640_17_2 >= (-100)) && (pub_r001640_17_2 <= 100));
  __CPROVER_assume((pub_r001640_18_1 >= (-100)) && (pub_r001640_18_1 <= 100));
  __CPROVER_assume((pub_r001640_18_2 >= (-100)) && (pub_r001640_18_2 <= 100));
  __CPROVER_assume((pub_r001640_19_1 >= (-100)) && (pub_r001640_19_1 <= 100));
  __CPROVER_assume((pub_r001640_19_2 >= (-100)) && (pub_r001640_19_2 <= 100));
  __CPROVER_assume((pub_r001640_20_1 >= (-100)) && (pub_r001640_20_1 <= 100));
  __CPROVER_assume((pub_r001640_20_2 >= (-100)) && (pub_r001640_20_2 <= 100));
  __CPROVER_assume((pub_r001640_21_1 >= (-100)) && (pub_r001640_21_1 <= 100));
  __CPROVER_assume((pub_r001640_21_2 >= (-100)) && (pub_r001640_21_2 <= 100));
  __CPROVER_assume((sec_r001640_0_1 >= 0) && (sec_r001640_0_1 <= 255));
  __CPROVER_assume((sec_r001640_0_2 >= 0) && (sec_r001640_0_2 <= 255));
  __CPROVER_assume((sec_r001640_1_1 >= 0) && (sec_r001640_1_1 <= 255));
  __CPROVER_assume((sec_r001640_1_2 >= 0) && (sec_r001640_1_2 <= 255));
  __CPROVER_assume((sec_r001640_2_1 >= 0) && (sec_r001640_2_1 <= 255));
  __CPROVER_assume((sec_r001640_2_2 >= 0) && (sec_r001640_2_2 <= 255));
  __CPROVER_assume((sec_r001640_3_1 >= 0) && (sec_r001640_3_1 <= 255));
  __CPROVER_assume((sec_r001640_3_2 >= 0) && (sec_r001640_3_2 <= 255));
  __CPROVER_assume((sec_r001640_4_1 >= 0) && (sec_r001640_4_1 <= 255));
  __CPROVER_assume((sec_r001640_4_2 >= 0) && (sec_r001640_4_2 <= 255));
  __CPROVER_assume((sec_r001640_5_1 >= 0) && (sec_r001640_5_1 <= 255));
  __CPROVER_assume((sec_r001640_5_2 >= 0) && (sec_r001640_5_2 <= 255));
  __CPROVER_assume((sec_r001640_6_1 >= 0) && (sec_r001640_6_1 <= 255));
  __CPROVER_assume((sec_r001640_6_2 >= 0) && (sec_r001640_6_2 <= 255));
  __CPROVER_assume((sec_r001640_7_1 >= 0) && (sec_r001640_7_1 <= 255));
  __CPROVER_assume((sec_r001640_7_2 >= 0) && (sec_r001640_7_2 <= 255));
  __CPROVER_assume((sec_r001640_8_1 >= 0) && (sec_r001640_8_1 <= 255));
  __CPROVER_assume((sec_r001640_8_2 >= 0) && (sec_r001640_8_2 <= 255));
  __CPROVER_assume((sec_r001640_9_1 >= 0) && (sec_r001640_9_1 <= 255));
  __CPROVER_assume((sec_r001640_9_2 >= 0) && (sec_r001640_9_2 <= 255));
  __CPROVER_assume((sec_r001640_10_1 >= 0) && (sec_r001640_10_1 <= 255));
  __CPROVER_assume((sec_r001640_10_2 >= 0) && (sec_r001640_10_2 <= 255));
  __CPROVER_assume((sec_r001640_11_1 >= 0) && (sec_r001640_11_1 <= 255));
  __CPROVER_assume((sec_r001640_11_2 >= 0) && (sec_r001640_11_2 <= 255));
  __CPROVER_assume((sec_r001640_12_1 >= 0) && (sec_r001640_12_1 <= 255));
  __CPROVER_assume((sec_r001640_12_2 >= 0) && (sec_r001640_12_2 <= 255));
  __CPROVER_assume((sec_r001640_13_1 >= 0) && (sec_r001640_13_1 <= 255));
  __CPROVER_assume((sec_r001640_13_2 >= 0) && (sec_r001640_13_2 <= 255));
  __CPROVER_assume((sec_r001640_14_1 >= 0) && (sec_r001640_14_1 <= 255));
  __CPROVER_assume((sec_r001640_14_2 >= 0) && (sec_r001640_14_2 <= 255));
  __CPROVER_assume((sec_r001640_15_1 >= 0) && (sec_r001640_15_1 <= 255));
  __CPROVER_assume((sec_r001640_15_2 >= 0) && (sec_r001640_15_2 <= 255));
  __CPROVER_assume((sec_r001640_16_1 >= 0) && (sec_r001640_16_1 <= 255));
  __CPROVER_assume((sec_r001640_16_2 >= 0) && (sec_r001640_16_2 <= 255));
  __CPROVER_assume((sec_r001640_17_1 >= 0) && (sec_r001640_17_1 <= 255));
  __CPROVER_assume((sec_r001640_17_2 >= 0) && (sec_r001640_17_2 <= 255));
  __CPROVER_assume((sec_r001640_18_1 >= 0) && (sec_r001640_18_1 <= 255));
  __CPROVER_assume((sec_r001640_18_2 >= 0) && (sec_r001640_18_2 <= 255));
  __CPROVER_assume((sec_r001640_19_1 >= 0) && (sec_r001640_19_1 <= 255));
  __CPROVER_assume((sec_r001640_19_2 >= 0) && (sec_r001640_19_2 <= 255));
  __CPROVER_assume((sec_r001640_20_1 >= 0) && (sec_r001640_20_1 <= 255));
  __CPROVER_assume((sec_r001640_20_2 >= 0) && (sec_r001640_20_2 <= 255));
  __CPROVER_assume((sec_r001640_21_1 >= 0) && (sec_r001640_21_1 <= 255));
  __CPROVER_assume((sec_r001640_21_2 >= 0) && (sec_r001640_21_2 <= 255));
  struct SensorNode_R001640_4013_0 st_var_0_1 = {0};
  struct SensorNode_R001640_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001640_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001640_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001640_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001640_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001640_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001640_0_2 + 7) & 15;
  struct EventLog_R001640_4013_1 st_var_1_1 = {0};
  struct EventLog_R001640_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001640_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001640_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001640_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001640_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001640_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001640_0_2 + 9) & 15;
  struct Vector3D_R001640_4013_2 st_var_2_1 = {0};
  struct Vector3D_R001640_4013_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001640_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001640_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001640_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001640_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001640_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001640_0_2 + 11) & 15;
  struct CipherContext_R001640_4013_3 st_var_3_1 = {0};
  struct CipherContext_R001640_4013_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001640_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001640_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001640_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001640_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001640_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001640_0_2 + 13) & 15;
  union ColorPixel_R001640_4013_0 u_var_1;
  union ColorPixel_R001640_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001640_4013_0(sec_r001640_0_1, sec_r001640_1_1, pub_r001640_2_1, pub_r001640_3_1);
  int helper_flow_0_2 = fn_R001640_4013_0(sec_r001640_0_2, sec_r001640_1_2, pub_r001640_2_2, pub_r001640_3_2);
  fn_R001640_4013_0_2(sec_r001640_0_1, sec_r001640_1_1, pub_r001640_2_1, pub_r001640_3_1, sec_r001640_0_2, sec_r001640_1_2, pub_r001640_2_2, pub_r001640_3_2);
  int helper_flow_1_1 = fn_R001640_4013_1(sec_r001640_1_1, pub_r001640_2_1, pub_r001640_3_1, pub_r001640_4_1);
  int helper_flow_1_2 = fn_R001640_4013_1(sec_r001640_1_2, pub_r001640_2_2, pub_r001640_3_2, pub_r001640_4_2);
  fn_R001640_4013_1_2(sec_r001640_1_1, pub_r001640_2_1, pub_r001640_3_1, pub_r001640_4_1, sec_r001640_1_2, pub_r001640_2_2, pub_r001640_3_2, pub_r001640_4_2);
  int helper_flow_2_1 = fn_R001640_4013_2(sec_r001640_2_1, sec_r001640_3_1, pub_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1);
  int helper_flow_2_2 = fn_R001640_4013_2(sec_r001640_2_2, sec_r001640_3_2, pub_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2);
  fn_R001640_4013_2_2(sec_r001640_2_1, sec_r001640_3_1, pub_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1, sec_r001640_2_2, sec_r001640_3_2, pub_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2);
  int helper_flow_3_1 = fn_R001640_4013_3(sec_r001640_3_1, pub_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1);
  int helper_flow_3_2 = fn_R001640_4013_3(sec_r001640_3_2, pub_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2);
  fn_R001640_4013_3_2(sec_r001640_3_1, pub_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1, sec_r001640_3_2, pub_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2);
  int helper_flow_4_1 = fn_R001640_4013_4(sec_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1, pub_r001640_7_1);
  int helper_flow_4_2 = fn_R001640_4013_4(sec_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2, pub_r001640_7_2);
  fn_R001640_4013_4_2(sec_r001640_4_1, pub_r001640_5_1, pub_r001640_6_1, pub_r001640_7_1, sec_r001640_4_2, pub_r001640_5_2, pub_r001640_6_2, pub_r001640_7_2);
  int helper_flow_5_1 = fn_R001640_4013_5(sec_r001640_5_1, sec_r001640_6_1, pub_r001640_7_1);
  int helper_flow_5_2 = fn_R001640_4013_5(sec_r001640_5_2, sec_r001640_6_2, pub_r001640_7_2);
  fn_R001640_4013_5_2(sec_r001640_5_1, sec_r001640_6_1, pub_r001640_7_1, sec_r001640_5_2, sec_r001640_6_2, pub_r001640_7_2);
  int helper_flow_6_1 = fn_R001640_4013_6(sec_r001640_6_1, sec_r001640_7_1, pub_r001640_8_1);
  int helper_flow_6_2 = fn_R001640_4013_6(sec_r001640_6_2, sec_r001640_7_2, pub_r001640_8_2);
  fn_R001640_4013_6_2(sec_r001640_6_1, sec_r001640_7_1, pub_r001640_8_1, sec_r001640_6_2, sec_r001640_7_2, pub_r001640_8_2);
  int helper_flow_7_1 = fn_R001640_4013_7(sec_r001640_7_1, pub_r001640_8_1, pub_r001640_9_1, pub_r001640_10_1);
  int helper_flow_7_2 = fn_R001640_4013_7(sec_r001640_7_2, pub_r001640_8_2, pub_r001640_9_2, pub_r001640_10_2);
  fn_R001640_4013_7_2(sec_r001640_7_1, pub_r001640_8_1, pub_r001640_9_1, pub_r001640_10_1, sec_r001640_7_2, pub_r001640_8_2, pub_r001640_9_2, pub_r001640_10_2);
  int helper_flow_8_1 = fn_R001640_4013_8(sec_r001640_8_1, sec_r001640_9_1);
  int helper_flow_8_2 = fn_R001640_4013_8(sec_r001640_8_2, sec_r001640_9_2);
  fn_R001640_4013_8_2(sec_r001640_8_1, sec_r001640_9_1, sec_r001640_8_2, sec_r001640_9_2);
  int helper_flow_9_1 = fn_R001640_4013_9(sec_r001640_9_1, sec_r001640_10_1, pub_r001640_11_1, pub_r001640_12_1);
  int helper_flow_9_2 = fn_R001640_4013_9(sec_r001640_9_2, sec_r001640_10_2, pub_r001640_11_2, pub_r001640_12_2);
  fn_R001640_4013_9_2(sec_r001640_9_1, sec_r001640_10_1, pub_r001640_11_1, pub_r001640_12_1, sec_r001640_9_2, sec_r001640_10_2, pub_r001640_11_2, pub_r001640_12_2);
  int helper_flow_10_1 = fn_R001640_4013_10(sec_r001640_10_1, pub_r001640_11_1);
  int helper_flow_10_2 = fn_R001640_4013_10(sec_r001640_10_2, pub_r001640_11_2);
  fn_R001640_4013_10_2(sec_r001640_10_1, pub_r001640_11_1, sec_r001640_10_2, pub_r001640_11_2);
  int stage_v_0_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_0_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_0_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
  }
  if (stage_v_0_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_1_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_1_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
  }
  if (stage_v_1_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = ((pub_r001640_6_1 * 2) + 14) & 63;
  int stage_v_2_2 = ((pub_r001640_6_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_3_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_3_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_3_1) + 13) & 255;
  }
  if (stage_v_3_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_3_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = (((sec_r001640_7_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_4_2 = (((sec_r001640_7_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_4_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 13) & 255;
  }
  if (stage_v_4_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (((sec_r001640_6_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_5_2 = (((sec_r001640_6_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_5_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
  }
  if (stage_v_5_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_6_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_6_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
  }
  if (stage_v_6_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_7_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_7_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
  }
  if (stage_v_7_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = (((helper_flow_7_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_8_2 = (((helper_flow_7_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_8_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
  }
  if (stage_v_8_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = (((sec_r001640_2_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_9_2 = (((sec_r001640_2_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_9_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_9_1) + 13) & 255;
  }
  if (stage_v_9_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_9_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = (((sec_r001640_19_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_10_2 = (((sec_r001640_19_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_10_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
  }
  if (stage_v_10_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = ((pub_r001640_12_1 * 2) + 46) & 63;
  int stage_v_11_2 = ((pub_r001640_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001640_14_1) & 127;
  int stage_v_12_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001640_14_2) & 127;
  if (stage_v_12_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 13) & 255;
  }
  if (stage_v_12_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = ((pub_r001640_3_1 * 2) + 19) & 63;
  int stage_v_13_2 = ((pub_r001640_3_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001640_14_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_14_2 = (((sec_r001640_14_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
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
  int stage_v_15_1 = (((sec_r001640_11_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_15_2 = (((sec_r001640_11_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_15_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
  }
  if (stage_v_15_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((pub_r001640_11_1 * 2) + 5) & 63;
  int stage_v_16_2 = ((pub_r001640_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001640_8_1 * 2) + 31) & 63;
  int stage_v_17_2 = ((pub_r001640_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001640_11_1 * 2) + 27) & 63;
  int stage_v_18_2 = ((pub_r001640_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001640_10_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_19_2 = (((sec_r001640_10_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_19_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
  }
  if (stage_v_19_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_20_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_20_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
  }
  if (stage_v_20_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (((sec_r001640_16_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_21_2 = (((sec_r001640_16_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_21_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
  }
  if (stage_v_21_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_21_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_22_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_22_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
  }
  if (stage_v_22_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((pub_r001640_12_1 * 2) + 13) & 63;
  int stage_v_23_2 = ((pub_r001640_12_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (((sec_r001640_14_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_24_2 = (((sec_r001640_14_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_24_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
  }
  if (stage_v_24_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_25_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_25_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 13) & 255;
  }
  if (stage_v_25_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_26_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_26_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
  }
  if (stage_v_26_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = (((stage_v_4_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_27_2 = (((stage_v_4_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_27_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
  }
  if (stage_v_27_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001640_14_1) & 127;
  int stage_v_28_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001640_14_2) & 127;
  if (stage_v_28_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_28_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_28_1) + 13) & 255;
  }
  if (stage_v_28_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_28_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_28_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = (((stage_v_24_1 ^ 0x2A) * 2) + pub_r001640_21_1) & 127;
  int stage_v_29_2 = (((stage_v_24_2 ^ 0x2A) * 2) + pub_r001640_21_2) & 127;
  if (stage_v_29_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
  }
  if (stage_v_29_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = ((pub_r001640_7_1 * 2) + 24) & 63;
  int stage_v_30_2 = ((pub_r001640_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001640_1_1 ^ 0x2A) * 2) + pub_r001640_18_1) & 127;
  int stage_v_31_2 = (((sec_r001640_1_2 ^ 0x2A) * 2) + pub_r001640_18_2) & 127;
  if (stage_v_31_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_31_1) + 13) & 255;
  }
  if (stage_v_31_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_31_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = (((stage_v_7_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_32_2 = (((stage_v_7_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_32_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
  }
  if (stage_v_32_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_33_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
  if (stage_v_33_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
  }
  if (stage_v_33_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (((sec_r001640_12_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_34_2 = (((sec_r001640_12_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_34_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
  }
  if (stage_v_34_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_35_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_35_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
  }
  if (stage_v_35_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_36_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_36_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
  }
  if (stage_v_36_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = ((pub_r001640_11_1 * 2) + 17) & 63;
  int stage_v_37_2 = ((pub_r001640_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001640_19_1 * 2) + 44) & 63;
  int stage_v_38_2 = ((pub_r001640_19_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001640_20_1 * 2) + 33) & 63;
  int stage_v_39_2 = ((pub_r001640_20_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_4_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_40_2 = (((helper_flow_4_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_40_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
  }
  if (stage_v_40_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = (((sec_r001640_3_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_41_2 = (((sec_r001640_3_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_41_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
  }
  if (stage_v_41_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = (((sec_r001640_3_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_42_2 = (((sec_r001640_3_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_42_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
  }
  if (stage_v_42_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = ((pub_r001640_14_1 * 2) + 32) & 63;
  int stage_v_43_2 = ((pub_r001640_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_44_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_44_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
  }
  if (stage_v_44_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_45_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
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
  int stage_v_46_1 = (((stage_v_29_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_46_2 = (((stage_v_29_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_46_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
  }
  if (stage_v_46_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_47_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_47_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
  }
  if (stage_v_47_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (((stage_v_33_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_48_2 = (((stage_v_33_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_48_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
  }
  if (stage_v_48_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_49_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_49_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
  }
  if (stage_v_49_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_50_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_50_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
  }
  if (stage_v_50_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = (((sec_r001640_6_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_51_2 = (((sec_r001640_6_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
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
  int stage_v_52_1 = (((sec_r001640_8_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_52_2 = (((sec_r001640_8_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_52_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
  }
  if (stage_v_52_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_53_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_53_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
  }
  if (stage_v_53_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = (((stage_v_0_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_54_2 = (((stage_v_0_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_54_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 13) & 255;
  }
  if (stage_v_54_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_55_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_55_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
  }
  if (stage_v_55_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = (((sec_r001640_16_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_56_2 = (((sec_r001640_16_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_56_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_56_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_56_1) + 13) & 255;
  }
  if (stage_v_56_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_56_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_56_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_57_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_57_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
  }
  if (stage_v_57_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_58_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_58_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
  }
  if (stage_v_58_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = ((pub_r001640_4_1 * 2) + 37) & 63;
  int stage_v_59_2 = ((pub_r001640_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_20_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_60_2 = (((stage_v_20_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_60_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
  }
  if (stage_v_60_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_61_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_61_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
  }
  if (stage_v_61_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_62_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_62_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
  }
  if (stage_v_62_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = (((sec_r001640_5_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_63_2 = (((sec_r001640_5_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_63_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
  }
  if (stage_v_63_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = (((sec_r001640_18_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_64_2 = (((sec_r001640_18_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_64_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
  }
  if (stage_v_64_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_65_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_65_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
  }
  if (stage_v_65_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = ((pub_r001640_2_1 * 2) + 19) & 63;
  int stage_v_66_2 = ((pub_r001640_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001640_14_1 * 2) + 26) & 63;
  int stage_v_67_2 = ((pub_r001640_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001640_12_1 * 2) + 6) & 63;
  int stage_v_68_2 = ((pub_r001640_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_69_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_69_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
  }
  if (stage_v_69_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = (((helper_flow_0_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_70_2 = (((helper_flow_0_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_70_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
  }
  if (stage_v_70_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((pub_r001640_3_1 * 2) + 26) & 63;
  int stage_v_71_2 = ((pub_r001640_3_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001640_7_1) & 127;
  int stage_v_72_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001640_7_2) & 127;
  if (stage_v_72_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
  }
  if (stage_v_72_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = (((sec_r001640_16_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_73_2 = (((sec_r001640_16_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_73_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
  }
  if (stage_v_73_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (((stage_v_65_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_74_2 = (((stage_v_65_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_74_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_74_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 13) & 255;
  }
  if (stage_v_74_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_74_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = (((sec_r001640_3_1 ^ 0x2A) * 2) + pub_r001640_7_1) & 127;
  int stage_v_75_2 = (((sec_r001640_3_2 ^ 0x2A) * 2) + pub_r001640_7_2) & 127;
  if (stage_v_75_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
  }
  if (stage_v_75_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_76_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_76_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
  }
  if (stage_v_76_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = (((sec_r001640_8_1 ^ 0x2A) * 2) + pub_r001640_14_1) & 127;
  int stage_v_77_2 = (((sec_r001640_8_2 ^ 0x2A) * 2) + pub_r001640_14_2) & 127;
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
  int stage_v_78_1 = (((sec_r001640_3_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_78_2 = (((sec_r001640_3_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_78_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
  }
  if (stage_v_78_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((pub_r001640_17_1 * 2) + 48) & 63;
  int stage_v_79_2 = ((pub_r001640_17_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = (((stage_v_76_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_80_2 = (((stage_v_76_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
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
  int stage_v_81_1 = (((stage_v_55_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_81_2 = (((stage_v_55_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_81_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
  }
  if (stage_v_81_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_82_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_82_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
  }
  if (stage_v_82_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (((stage_v_74_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_83_2 = (((stage_v_74_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_83_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
  }
  if (stage_v_83_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = (((stage_v_54_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_84_2 = (((stage_v_54_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
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
  int stage_v_85_1 = (((sec_r001640_6_1 ^ 0x2A) * 2) + pub_r001640_21_1) & 127;
  int stage_v_85_2 = (((sec_r001640_6_2 ^ 0x2A) * 2) + pub_r001640_21_2) & 127;
  if (stage_v_85_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
  }
  if (stage_v_85_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = (((sec_r001640_4_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_86_2 = (((sec_r001640_4_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_86_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
  }
  if (stage_v_86_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_87_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_87_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
  }
  if (stage_v_87_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_88_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_88_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001640_14_1) & 127;
  int stage_v_89_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001640_14_2) & 127;
  if (stage_v_89_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((pub_r001640_1_1 * 2) + 10) & 63;
  int stage_v_90_2 = ((pub_r001640_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_70_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_91_2 = (((stage_v_70_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
  if (stage_v_91_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = (((stage_v_21_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_92_2 = (((stage_v_21_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_92_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = (((stage_v_69_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_93_2 = (((stage_v_69_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_93_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_94_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_94_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = (((stage_v_36_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_95_2 = (((stage_v_36_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_95_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = (((sec_r001640_9_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_96_2 = (((sec_r001640_9_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_96_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((pub_r001640_16_1 * 2) + 7) & 63;
  int stage_v_97_2 = ((pub_r001640_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((stage_v_96_1 ^ 0x2A) * 2) + pub_r001640_7_1) & 127;
  int stage_v_98_2 = (((stage_v_96_2 ^ 0x2A) * 2) + pub_r001640_7_2) & 127;
  if (stage_v_98_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = (((helper_flow_3_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_99_2 = (((helper_flow_3_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_99_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((pub_r001640_8_1 * 2) + 48) & 63;
  int stage_v_100_2 = ((pub_r001640_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_32_1 ^ 0x2A) * 2) + pub_r001640_18_1) & 127;
  int stage_v_101_2 = (((stage_v_32_2 ^ 0x2A) * 2) + pub_r001640_18_2) & 127;
  if (stage_v_101_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_102_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
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
  int stage_v_103_1 = ((pub_r001640_10_1 * 2) + 8) & 63;
  int stage_v_103_2 = ((pub_r001640_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = ((pub_r001640_5_1 * 2) + 23) & 63;
  int stage_v_104_2 = ((pub_r001640_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_12_1 ^ 0x2A) * 2) + pub_r001640_21_1) & 127;
  int stage_v_105_2 = (((stage_v_12_2 ^ 0x2A) * 2) + pub_r001640_21_2) & 127;
  if (stage_v_105_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = (((stage_v_5_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_106_2 = (((stage_v_5_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_106_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_107_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_107_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_108_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_108_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_109_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_109_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = (((stage_v_22_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_110_2 = (((stage_v_22_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_110_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = (((helper_flow_10_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_111_2 = (((helper_flow_10_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_111_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((pub_r001640_16_1 * 2) + 40) & 63;
  int stage_v_112_2 = ((pub_r001640_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_44_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_113_2 = (((stage_v_44_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_113_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = (((helper_flow_9_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_114_2 = (((helper_flow_9_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_114_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = (((sec_r001640_2_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_115_2 = (((sec_r001640_2_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_115_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_116_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_116_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = (((stage_v_116_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_117_2 = (((stage_v_116_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_117_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = (((sec_r001640_13_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_118_2 = (((sec_r001640_13_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
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
  int stage_v_119_1 = ((pub_r001640_3_1 * 2) + 20) & 63;
  int stage_v_119_2 = ((pub_r001640_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_120_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_120_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = (((stage_v_111_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_121_2 = (((stage_v_111_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_121_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = (((stage_v_114_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_122_2 = (((stage_v_114_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_122_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = (((stage_v_82_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_123_2 = (((stage_v_82_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_123_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((pub_r001640_6_1 * 2) + 23) & 63;
  int stage_v_124_2 = ((pub_r001640_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001640_16_1 * 2) + 30) & 63;
  int stage_v_125_2 = ((pub_r001640_16_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_3_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_126_2 = (((stage_v_3_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_126_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = (((stage_v_99_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_127_2 = (((stage_v_99_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_127_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = (((helper_flow_8_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_128_2 = (((helper_flow_8_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_128_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = (((stage_v_122_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_129_2 = (((stage_v_122_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_129_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((pub_r001640_1_1 * 2) + 40) & 63;
  int stage_v_130_2 = ((pub_r001640_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((sec_r001640_11_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_131_2 = (((sec_r001640_11_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_131_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_132_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_132_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = (((sec_r001640_18_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_133_2 = (((sec_r001640_18_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_133_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = (((stage_v_63_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_134_2 = (((stage_v_63_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_134_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((pub_r001640_0_1 * 2) + 31) & 63;
  int stage_v_135_2 = ((pub_r001640_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_77_1 ^ 0x2A) * 2) + pub_r001640_7_1) & 127;
  int stage_v_136_2 = (((stage_v_77_2 ^ 0x2A) * 2) + pub_r001640_7_2) & 127;
  if (stage_v_136_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = (((sec_r001640_0_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_137_2 = (((sec_r001640_0_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_137_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = (((stage_v_94_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_138_2 = (((stage_v_94_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_138_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = (((stage_v_108_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_139_2 = (((stage_v_108_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_139_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_140_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_140_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((pub_r001640_15_1 * 2) + 29) & 63;
  int stage_v_141_2 = ((pub_r001640_15_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = (((sec_r001640_20_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_142_2 = (((sec_r001640_20_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_142_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = (((stage_v_57_1 ^ 0x2A) * 2) + pub_r001640_18_1) & 127;
  int stage_v_143_2 = (((stage_v_57_2 ^ 0x2A) * 2) + pub_r001640_18_2) & 127;
  if (stage_v_143_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_144_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_144_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_145_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_145_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = (((sec_r001640_20_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_146_2 = (((sec_r001640_20_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_146_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((pub_r001640_2_1 * 2) + 21) & 63;
  int stage_v_147_2 = ((pub_r001640_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = (((stage_v_9_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_148_2 = (((stage_v_9_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_148_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = (((sec_r001640_9_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_149_2 = (((sec_r001640_9_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_149_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((pub_r001640_0_1 * 2) + 40) & 63;
  int stage_v_150_2 = ((pub_r001640_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = (((sec_r001640_1_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_151_2 = (((sec_r001640_1_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_151_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = (((stage_v_35_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_152_2 = (((stage_v_35_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_152_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = (((stage_v_48_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_153_2 = (((stage_v_48_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_153_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = (((stage_v_132_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_154_2 = (((stage_v_132_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_154_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((pub_r001640_14_1 * 2) + 21) & 63;
  int stage_v_155_2 = ((pub_r001640_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((stage_v_101_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_156_2 = (((stage_v_101_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
  if (stage_v_156_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_157_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_157_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((pub_r001640_5_1 * 2) + 34) & 63;
  int stage_v_158_2 = ((pub_r001640_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (((stage_v_60_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_159_2 = (((stage_v_60_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_159_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_160_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_160_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = (((stage_v_149_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_161_2 = (((stage_v_149_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_161_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = (((stage_v_91_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_162_2 = (((stage_v_91_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_162_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((pub_r001640_10_1 * 2) + 14) & 63;
  int stage_v_163_2 = ((pub_r001640_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001640_12_1 * 2) + 22) & 63;
  int stage_v_164_2 = ((pub_r001640_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001640_5_1 * 2) + 11) & 63;
  int stage_v_165_2 = ((pub_r001640_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_40_1 ^ 0x2A) * 2) + pub_r001640_21_1) & 127;
  int stage_v_166_2 = (((stage_v_40_2 ^ 0x2A) * 2) + pub_r001640_21_2) & 127;
  if (stage_v_166_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = (((stage_v_28_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_167_2 = (((stage_v_28_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
  if (stage_v_167_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((pub_r001640_9_1 * 2) + 10) & 63;
  int stage_v_168_2 = ((pub_r001640_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((helper_flow_6_1 ^ 0x2A) * 2) + pub_r001640_20_1) & 127;
  int stage_v_169_2 = (((helper_flow_6_2 ^ 0x2A) * 2) + pub_r001640_20_2) & 127;
  if (stage_v_169_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = (((stage_v_131_1 ^ 0x2A) * 2) + pub_r001640_7_1) & 127;
  int stage_v_170_2 = (((stage_v_131_2 ^ 0x2A) * 2) + pub_r001640_7_2) & 127;
  if (stage_v_170_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = (((stage_v_85_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_171_2 = (((stage_v_85_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_171_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = (((stage_v_25_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_172_2 = (((stage_v_25_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_172_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = (((sec_r001640_0_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_173_2 = (((sec_r001640_0_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_173_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((pub_r001640_13_1 * 2) + 26) & 63;
  int stage_v_174_2 = ((pub_r001640_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_87_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_175_2 = (((stage_v_87_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_175_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((pub_r001640_19_1 * 2) + 45) & 63;
  int stage_v_176_2 = ((pub_r001640_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = (((stage_v_14_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_177_2 = (((stage_v_14_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_177_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = (((stage_v_166_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_178_2 = (((stage_v_166_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_178_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = (((stage_v_61_1 ^ 0x2A) * 2) + pub_r001640_9_1) & 127;
  int stage_v_179_2 = (((stage_v_61_2 ^ 0x2A) * 2) + pub_r001640_9_2) & 127;
  if (stage_v_179_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = (((stage_v_49_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_180_2 = (((stage_v_49_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
  if (stage_v_180_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_181_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_181_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = (((stage_v_52_1 ^ 0x2A) * 2) + pub_r001640_18_1) & 127;
  int stage_v_182_2 = (((stage_v_52_2 ^ 0x2A) * 2) + pub_r001640_18_2) & 127;
  if (stage_v_182_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = (((stage_v_95_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_183_2 = (((stage_v_95_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_183_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = (((helper_flow_2_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_184_2 = (((helper_flow_2_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_184_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = (((stage_v_183_1 ^ 0x2A) * 2) + pub_r001640_18_1) & 127;
  int stage_v_185_2 = (((stage_v_183_2 ^ 0x2A) * 2) + pub_r001640_18_2) & 127;
  if (stage_v_185_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = (((sec_r001640_16_1 ^ 0x2A) * 2) + pub_r001640_20_1) & 127;
  int stage_v_186_2 = (((sec_r001640_16_2 ^ 0x2A) * 2) + pub_r001640_20_2) & 127;
  if (stage_v_186_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = (((stage_v_26_1 ^ 0x2A) * 2) + pub_r001640_11_1) & 127;
  int stage_v_187_2 = (((stage_v_26_2 ^ 0x2A) * 2) + pub_r001640_11_2) & 127;
  if (stage_v_187_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = (((stage_v_6_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_188_2 = (((stage_v_6_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_188_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((pub_r001640_2_1 * 2) + 12) & 63;
  int stage_v_189_2 = ((pub_r001640_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_19_1 ^ 0x2A) * 2) + pub_r001640_2_1) & 127;
  int stage_v_190_2 = (((stage_v_19_2 ^ 0x2A) * 2) + pub_r001640_2_2) & 127;
  if (stage_v_190_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = (((stage_v_31_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_191_2 = (((stage_v_31_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_191_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = (((stage_v_98_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_192_2 = (((stage_v_98_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
  if (stage_v_192_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = (((stage_v_151_1 ^ 0x2A) * 2) + pub_r001640_16_1) & 127;
  int stage_v_193_2 = (((stage_v_151_2 ^ 0x2A) * 2) + pub_r001640_16_2) & 127;
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
  int stage_v_194_1 = (((sec_r001640_13_1 ^ 0x2A) * 2) + pub_r001640_0_1) & 127;
  int stage_v_194_2 = (((sec_r001640_13_2 ^ 0x2A) * 2) + pub_r001640_0_2) & 127;
  if (stage_v_194_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = (((helper_flow_1_1 ^ 0x2A) * 2) + pub_r001640_17_1) & 127;
  int stage_v_195_2 = (((helper_flow_1_2 ^ 0x2A) * 2) + pub_r001640_17_2) & 127;
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
  int stage_v_196_1 = ((pub_r001640_14_1 * 2) + 25) & 63;
  int stage_v_196_2 = ((pub_r001640_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = (((stage_v_128_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_197_2 = (((stage_v_128_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_197_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = (((stage_v_47_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_198_2 = (((stage_v_47_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_198_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001640_6_1) & 127;
  int stage_v_199_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001640_6_2) & 127;
  if (stage_v_199_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = (((stage_v_78_1 ^ 0x2A) * 2) + pub_r001640_3_1) & 127;
  int stage_v_200_2 = (((stage_v_78_2 ^ 0x2A) * 2) + pub_r001640_3_2) & 127;
  if (stage_v_200_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = (((stage_v_156_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_201_2 = (((stage_v_156_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_201_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = (((stage_v_107_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_202_2 = (((stage_v_107_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_202_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = (((stage_v_172_1 ^ 0x2A) * 2) + pub_r001640_19_1) & 127;
  int stage_v_203_2 = (((stage_v_172_2 ^ 0x2A) * 2) + pub_r001640_19_2) & 127;
  if (stage_v_203_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((pub_r001640_9_1 * 2) + 15) & 63;
  int stage_v_204_2 = ((pub_r001640_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_117_1 ^ 0x2A) * 2) + pub_r001640_8_1) & 127;
  int stage_v_205_2 = (((stage_v_117_2 ^ 0x2A) * 2) + pub_r001640_8_2) & 127;
  if (stage_v_205_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = (((stage_v_173_1 ^ 0x2A) * 2) + pub_r001640_12_1) & 127;
  int stage_v_206_2 = (((stage_v_173_2 ^ 0x2A) * 2) + pub_r001640_12_2) & 127;
  if (stage_v_206_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = (((stage_v_185_1 ^ 0x2A) * 2) + pub_r001640_1_1) & 127;
  int stage_v_207_2 = (((stage_v_185_2 ^ 0x2A) * 2) + pub_r001640_1_2) & 127;
  if (stage_v_207_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = (((stage_v_89_1 ^ 0x2A) * 2) + pub_r001640_4_1) & 127;
  int stage_v_208_2 = (((stage_v_89_2 ^ 0x2A) * 2) + pub_r001640_4_2) & 127;
  if (stage_v_208_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = (((sec_r001640_16_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_209_2 = (((sec_r001640_16_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
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
  int stage_v_210_1 = ((pub_r001640_2_1 * 2) + 12) & 63;
  int stage_v_210_2 = ((pub_r001640_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001640_7_1 * 2) + 6) & 63;
  int stage_v_211_2 = ((pub_r001640_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_205_1 ^ 0x2A) * 2) + pub_r001640_15_1) & 127;
  int stage_v_212_2 = (((stage_v_205_2 ^ 0x2A) * 2) + pub_r001640_15_2) & 127;
  if (stage_v_212_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((pub_r001640_5_1 * 2) + 27) & 63;
  int stage_v_213_2 = ((pub_r001640_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = (((stage_v_50_1 ^ 0x2A) * 2) + pub_r001640_20_1) & 127;
  int stage_v_214_2 = (((stage_v_50_2 ^ 0x2A) * 2) + pub_r001640_20_2) & 127;
  if (stage_v_214_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = (((stage_v_171_1 ^ 0x2A) * 2) + pub_r001640_5_1) & 127;
  int stage_v_215_2 = (((stage_v_171_2 ^ 0x2A) * 2) + pub_r001640_5_2) & 127;
  if (stage_v_215_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = (((stage_v_105_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_216_2 = (((stage_v_105_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_216_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = (((stage_v_110_1 ^ 0x2A) * 2) + pub_r001640_13_1) & 127;
  int stage_v_217_2 = (((stage_v_110_2 ^ 0x2A) * 2) + pub_r001640_13_2) & 127;
  if (stage_v_217_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = (((stage_v_136_1 ^ 0x2A) * 2) + pub_r001640_10_1) & 127;
  int stage_v_218_2 = (((stage_v_136_2 ^ 0x2A) * 2) + pub_r001640_10_2) & 127;
  if (stage_v_218_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001640_19_1 != sec_r001640_19_2);
  __CPROVER_assume(sec_r001640_12_1 != sec_r001640_12_2);
  __CPROVER_assume(sec_r001640_13_1 != sec_r001640_13_2);
  __CPROVER_assume(pub_r001640_18_1 == pub_r001640_18_2);
  __CPROVER_assume(pub_r001640_6_1 == pub_r001640_6_2);
  __CPROVER_assume(sec_r001640_5_1 != sec_r001640_5_2);
  __CPROVER_assume(pub_r001640_0_1 == pub_r001640_0_2);
  __CPROVER_assume(sec_r001640_10_1 != sec_r001640_10_2);
  __CPROVER_assume(sec_r001640_16_1 != sec_r001640_16_2);
  __CPROVER_assume(sec_r001640_15_1 != sec_r001640_15_2);
  __CPROVER_assume(pub_r001640_15_1 == pub_r001640_15_2);
  __CPROVER_assume(sec_r001640_7_1 != sec_r001640_7_2);
  __CPROVER_assume(sec_r001640_17_1 != sec_r001640_17_2);
  __CPROVER_assume(pub_r001640_17_1 == pub_r001640_17_2);
  __CPROVER_assume(pub_r001640_19_1 == pub_r001640_19_2);
  __CPROVER_assume(sec_r001640_18_1 != sec_r001640_18_2);
  __CPROVER_assume(pub_r001640_12_1 == pub_r001640_12_2);
  __CPROVER_assume(sec_r001640_20_1 != sec_r001640_20_2);
  __CPROVER_assume(sec_r001640_3_1 != sec_r001640_3_2);
  __CPROVER_assume(pub_r001640_3_1 == pub_r001640_3_2);
  __CPROVER_assume(pub_r001640_9_1 == pub_r001640_9_2);
  __CPROVER_assume(pub_r001640_20_1 == pub_r001640_20_2);
  __CPROVER_assume(pub_r001640_10_1 == pub_r001640_10_2);
  __CPROVER_assume(pub_r001640_14_1 == pub_r001640_14_2);
  __CPROVER_assume(sec_r001640_8_1 != sec_r001640_8_2);
  __CPROVER_assume(pub_r001640_2_1 == pub_r001640_2_2);
  __CPROVER_assume(pub_r001640_11_1 == pub_r001640_11_2);
  __CPROVER_assume(pub_r001640_1_1 == pub_r001640_1_2);
  __CPROVER_assume(pub_r001640_8_1 == pub_r001640_8_2);
  __CPROVER_assume(pub_r001640_7_1 == pub_r001640_7_2);
  __CPROVER_assume(sec_r001640_1_1 != sec_r001640_1_2);
  __CPROVER_assume(sec_r001640_2_1 != sec_r001640_2_2);
  __CPROVER_assume(sec_r001640_11_1 != sec_r001640_11_2);
  __CPROVER_assume(pub_r001640_16_1 == pub_r001640_16_2);
  __CPROVER_assume(sec_r001640_14_1 != sec_r001640_14_2);
  __CPROVER_assume(sec_r001640_21_1 != sec_r001640_21_2);
  __CPROVER_assume(sec_r001640_0_1 != sec_r001640_0_2);
  __CPROVER_assume(sec_r001640_9_1 != sec_r001640_9_2);
  __CPROVER_assume(sec_r001640_6_1 != sec_r001640_6_2);
  __CPROVER_assume(pub_r001640_21_1 == pub_r001640_21_2);
  __CPROVER_assume(pub_r001640_5_1 == pub_r001640_5_2);
  __CPROVER_assume(sec_r001640_4_1 != sec_r001640_4_2);
  __CPROVER_assume(pub_r001640_4_1 == pub_r001640_4_2);
  __CPROVER_assume(pub_r001640_13_1 == pub_r001640_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.gain == st_var_0_2.gain);
  assert(st_var_0_1.threshold == st_var_0_2.threshold);
  assert(st_var_0_1.calib == st_var_0_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.timestamp == st_var_1_2.timestamp);
  assert(st_var_1_1.severity == st_var_1_2.severity);
  assert(st_var_1_1.facility == st_var_1_2.facility);
  assert(st_var_1_1.seq == st_var_1_2.seq);
  assert(st_var_1_1.code == st_var_1_2.code);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.iv == st_var_3_2.iv);
  assert(st_var_3_1.nonce == st_var_3_2.nonce);
  assert(st_var_3_1.counter == st_var_3_2.counter);
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
  assert(stage_v_217_1 == stage_v_217_2);
  assert(stage_v_218_1 == stage_v_218_2);
}


