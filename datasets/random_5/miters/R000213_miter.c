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
struct EventLog_R000213_1313_0
{
  int code;
  int timestamp;
  int signature;
  int buffer[3];
};
struct Vector3D_R000213_1313_1
{
  unsigned char norm_sq;
  short pitch;
  short coord_y;
  short coord_x;
  int buffer[3];
};
struct StreamBuffer_R000213_1313_2
{
  int tail;
  short checksum;
  int watermark;
  int buffer[3];
};
struct MatrixBlock_R000213_1313_3
{
  short determinant;
  unsigned char stride;
  int density;
  int dim;
  int scale;
  int trace;
  int buffer[3];
};
union RegisterBank_R000213_1313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000213_1313_1
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
void fn_R000213_1313_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int checksum_75_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_75_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_75_1)
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

  switch (checksum_75_2)
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

  int phase_21_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_21_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_21_1) & 63;
  aux_2 = (aux_2 + phase_21_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_75_1 == checksum_75_2);
  assert(phase_21_1 == phase_21_2);
}

int fn_R000213_1313_0(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int checksum_75 = (aux + st.buffer[1]) & 3;
  switch (checksum_75)
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

  int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_21) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000213_1313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st_1 = {0};
  struct MatrixBlock_R000213_1313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_80_1)
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

  switch (tally_80_2)
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

  int tracker_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_40_1 > 43)
  {
    acc_1 = ((acc_1 + (tracker_40_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_40_2 > 43)
  {
    acc_2 = ((acc_2 + (tracker_40_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_36_1 = local_arr_1[aux_1 % 3];
  int tally_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_80_1 == tally_80_2);
  assert(tracker_40_1 == tracker_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_36_1 == tally_36_2);
}

int fn_R000213_1313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_80 = (aux + st.buffer[1]) & 3;
  switch (tally_80)
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

  int tracker_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_40 > 43)
  {
    acc = ((acc + (tracker_40 * 2)) + 5) & 127;
    aux ^= tracker_40 & 15;
  }
  else
  {
    acc = ((acc - tracker_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_36 = local_arr[aux % 3];
  acc = (acc + (tally_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000213_1313_2 st_1 = {0};
  struct StreamBuffer_R000213_1313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_56_1 > 30)
  {
    acc_1 = ((acc_1 + (pivot_56_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_56_2 > 30)
  {
    acc_2 = ((acc_2 + (pivot_56_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_85_1 = local_arr_1[aux_1 % 3];
  int metric_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_85_2 * 2)) & 127;
  int stride_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_94_1) & 63;
  aux_2 = (aux_2 + stride_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_56_1 == pivot_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_85_1 == metric_85_2);
  assert(stride_94_1 == stride_94_2);
}

int fn_R000213_1313_2(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000213_1313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_56 > 30)
  {
    acc = ((acc + (pivot_56 * 2)) + 5) & 127;
    aux ^= pivot_56 & 15;
  }
  else
  {
    acc = ((acc - pivot_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_85 = local_arr[aux % 3];
  acc = (acc + (metric_85 * 2)) & 127;
  int stride_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_94) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st_1 = {0};
  struct MatrixBlock_R000213_1313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_96_1 = local_arr_1[aux_1 % 3];
  int cursor_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_96_2 * 2)) & 127;
  int factor_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_81_1)
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

  switch (factor_81_2)
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

  int checksum_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_40_1 > 45)
  {
    acc_1 = ((acc_1 + (checksum_40_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_40_2 > 45)
  {
    acc_2 = ((acc_2 + (checksum_40_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_96_1 == cursor_96_2);
  assert(factor_81_1 == factor_81_2);
  assert(checksum_40_1 == checksum_40_2);
}

int fn_R000213_1313_3(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int cursor_96 = local_arr[aux % 3];
  acc = (acc + (cursor_96 * 2)) & 127;
  int factor_81 = (aux + st.buffer[1]) & 3;
  switch (factor_81)
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

  int checksum_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_40 > 45)
  {
    acc = ((acc + (checksum_40 * 2)) + 5) & 127;
    aux ^= checksum_40 & 15;
  }
  else
  {
    acc = ((acc - checksum_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000213_1313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int cursor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_68_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_68_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_68_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_68_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_56_1 = local_arr_1[aux_1 % 3];
  int phase_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_68_1 == cursor_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_56_1 == phase_56_2);
}

int fn_R000213_1313_4(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int cursor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_68 > 19)
  {
    acc = ((acc + (cursor_68 * 2)) + 5) & 127;
    aux ^= cursor_68 & 15;
  }
  else
  {
    acc = ((acc - cursor_68) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int phase_56 = local_arr[aux % 3];
  acc = (acc + (phase_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_24_1) & 63;
  aux_2 = (aux_2 + quantum_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_89_1 > 45)
  {
    acc_1 = ((acc_1 + (cursor_89_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_89_2 > 45)
  {
    acc_2 = ((acc_2 + (cursor_89_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_33_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_33_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_33_1)
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

  switch (factor_33_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_24_1 == quantum_24_2);
  assert(cursor_89_1 == cursor_89_2);
  assert(factor_33_1 == factor_33_2);
}

int fn_R000213_1313_5(int p0, int p1)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_24) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_89 > 45)
  {
    acc = ((acc + (cursor_89 * 2)) + 5) & 127;
    aux ^= cursor_89 & 15;
  }
  else
  {
    acc = ((acc - cursor_89) + 11) & 127;
    aux += 3;
  }
  int factor_33 = (aux + st.buffer[1]) & 3;
  switch (factor_33)
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

void fn_R000213_1313_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_41_1 = local_arr_1[aux_1 % 3];
  int mask_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_41_2 * 2)) & 127;
  int tracker_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_23_1)
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

  switch (tracker_23_2)
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

  int mask_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_91_1) & 63;
  aux_2 = (aux_2 + mask_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_41_1 == mask_41_2);
  assert(tracker_23_1 == tracker_23_2);
  assert(mask_91_1 == mask_91_2);
}

int fn_R000213_1313_6(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int mask_41 = local_arr[aux % 3];
  acc = (acc + (mask_41 * 2)) & 127;
  int tracker_23 = (aux + st.buffer[1]) & 3;
  switch (tracker_23)
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

  int mask_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000213_1313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tally_30_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_30_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_30_1 > 48)
  {
    acc_1 = ((acc_1 + (tally_30_1 * 2)) + 5) & 127;
    aux_1 ^= tally_30_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_30_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_30_2 > 48)
  {
    acc_2 = ((acc_2 + (tally_30_2 * 2)) + 5) & 127;
    aux_2 ^= tally_30_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_30_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_27_1 = local_arr_1[aux_1 % 3];
  int tally_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_27_2 * 2)) & 127;
  int index_reg_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_51_1)
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

  switch (index_reg_51_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_30_1 == tally_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_27_1 == tally_27_2);
  assert(index_reg_51_1 == index_reg_51_2);
}

int fn_R000213_1313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tally_30 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_30 > 48)
  {
    acc = ((acc + (tally_30 * 2)) + 5) & 127;
    aux ^= tally_30 & 15;
  }
  else
  {
    acc = ((acc - tally_30) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_27 = local_arr[aux % 3];
  acc = (acc + (tally_27 * 2)) & 127;
  int index_reg_51 = (aux + st.buffer[1]) & 3;
  switch (index_reg_51)
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

void fn_R000213_1313_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000213_1313_2 st_1 = {0};
  struct StreamBuffer_R000213_1313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int coefficient_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_34_1 > 50)
  {
    acc_1 = ((acc_1 + (coefficient_34_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_34_2 > 50)
  {
    acc_2 = ((acc_2 + (coefficient_34_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_55_1) & 63;
  aux_2 = (aux_2 + damping_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_34_1 == coefficient_34_2);
  assert(damping_55_1 == damping_55_2);
}

int fn_R000213_1313_8(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000213_1313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int coefficient_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_34 > 50)
  {
    acc = ((acc + (coefficient_34 * 2)) + 5) & 127;
    aux ^= coefficient_34 & 15;
  }
  else
  {
    acc = ((acc - coefficient_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_55) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000213_1313_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int stride_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_85_1 > 15)
  {
    acc_1 = ((acc_1 + (stride_85_1 * 2)) + 5) & 127;
    aux_1 ^= stride_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_85_2 > 15)
  {
    acc_2 = ((acc_2 + (stride_85_2 * 2)) + 5) & 127;
    aux_2 ^= stride_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_85_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_68_1)
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

  switch (tally_68_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_85_1 == stride_85_2);
  assert(tally_68_1 == tally_68_2);
}

int fn_R000213_1313_9(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int stride_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_85 > 15)
  {
    acc = ((acc + (stride_85 * 2)) + 5) & 127;
    aux ^= stride_85 & 15;
  }
  else
  {
    acc = ((acc - stride_85) + 11) & 127;
    aux += 3;
  }
  int tally_68 = (aux + st.buffer[1]) & 3;
  switch (tally_68)
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
  return (acc + aux) & 255;
}

void fn_R000213_1313_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int pivot_51_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_51_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_51_1) & 63;
  aux_2 = (aux_2 + pivot_51_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_42_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_42_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_42_1)
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

  switch (weight_42_2)
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

  int weight_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_74_1 > 25)
  {
    acc_1 = ((acc_1 + (weight_74_1 * 2)) + 5) & 127;
    aux_1 ^= weight_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_74_2 > 25)
  {
    acc_2 = ((acc_2 + (weight_74_2 * 2)) + 5) & 127;
    aux_2 ^= weight_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_51_1 == pivot_51_2);
  assert(weight_42_1 == weight_42_2);
  assert(weight_74_1 == weight_74_2);
}

int fn_R000213_1313_10(int p0, int p1, int p2)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_51) & 63;
  acc ^= aux;
  int weight_42 = (aux + st.buffer[1]) & 3;
  switch (weight_42)
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

  int weight_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_74 > 25)
  {
    acc = ((acc + (weight_74 * 2)) + 5) & 127;
    aux ^= weight_74 & 15;
  }
  else
  {
    acc = ((acc - weight_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000213_1313_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int scale_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_35_1 > 14)
  {
    acc_1 = ((acc_1 + (scale_35_1 * 2)) + 5) & 127;
    aux_1 ^= scale_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_35_2 > 14)
  {
    acc_2 = ((acc_2 + (scale_35_2 * 2)) + 5) & 127;
    aux_2 ^= scale_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_35_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_67_1)
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

  switch (cursor_67_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_35_1 == scale_35_2);
  assert(cursor_67_1 == cursor_67_2);
}

int fn_R000213_1313_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int scale_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_35 > 14)
  {
    acc = ((acc + (scale_35 * 2)) + 5) & 127;
    aux ^= scale_35 & 15;
  }
  else
  {
    acc = ((acc - scale_35) + 11) & 127;
    aux += 3;
  }
  int cursor_67 = (aux + st.buffer[1]) & 3;
  switch (cursor_67)
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

void fn_R000213_1313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_91_1) & 63;
  aux_2 = (aux_2 + weight_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_69_1 = local_arr_1[aux_1 % 3];
  int cursor_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_69_2 * 2)) & 127;
  int mask_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_81_1)
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

  switch (mask_81_2)
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
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_91_1 == weight_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_69_1 == cursor_69_2);
  assert(mask_81_1 == mask_81_2);
}

int fn_R000213_1313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_69 = local_arr[aux % 3];
  acc = (acc + (cursor_69 * 2)) & 127;
  int mask_81 = (aux + st.buffer[1]) & 3;
  switch (mask_81)
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

void fn_R000213_1313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int damping_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_46_1 > 24)
  {
    acc_1 = ((acc_1 + (damping_46_1 * 2)) + 5) & 127;
    aux_1 ^= damping_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_46_2 > 24)
  {
    acc_2 = ((acc_2 + (damping_46_2 * 2)) + 5) & 127;
    aux_2 ^= damping_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_95_1)
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

  switch (coefficient_95_2)
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

  int index_reg_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_35_1) & 63;
  aux_2 = (aux_2 + index_reg_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_46_1 == damping_46_2);
  assert(coefficient_95_1 == coefficient_95_2);
  assert(index_reg_35_1 == index_reg_35_2);
}

int fn_R000213_1313_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int damping_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_46 > 24)
  {
    acc = ((acc + (damping_46 * 2)) + 5) & 127;
    aux ^= damping_46 & 15;
  }
  else
  {
    acc = ((acc - damping_46) + 11) & 127;
    aux += 3;
  }
  int coefficient_95 = (aux + st.buffer[1]) & 3;
  switch (coefficient_95)
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

  int index_reg_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_35) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int sample_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_80_1 > 37)
  {
    acc_1 = ((acc_1 + (sample_80_1 * 2)) + 5) & 127;
    aux_1 ^= sample_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_80_2 > 37)
  {
    acc_2 = ((acc_2 + (sample_80_2 * 2)) + 5) & 127;
    aux_2 ^= sample_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_16_1) & 63;
  aux_2 = (aux_2 + index_reg_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_80_1 == sample_80_2);
  assert(index_reg_16_1 == index_reg_16_2);
}

int fn_R000213_1313_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int sample_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_80 > 37)
  {
    acc = ((acc + (sample_80 * 2)) + 5) & 127;
    aux ^= sample_80 & 15;
  }
  else
  {
    acc = ((acc - sample_80) + 11) & 127;
    aux += 3;
  }
  int index_reg_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_16) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st_1 = {0};
  struct EventLog_R000213_1313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int threshold_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_32_1)
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

  switch (threshold_32_2)
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

  int window_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_39_1 > 11)
  {
    acc_1 = ((acc_1 + (window_39_1 * 2)) + 5) & 127;
    aux_1 ^= window_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_39_2 > 11)
  {
    acc_2 = ((acc_2 + (window_39_2 * 2)) + 5) & 127;
    aux_2 ^= window_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_39_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_62_1) & 63;
  aux_2 = (aux_2 + index_reg_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.code == st_2.code);
  assert(st_1.timestamp == st_2.timestamp);
  assert(st_1.signature == st_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_32_1 == threshold_32_2);
  assert(window_39_1 == window_39_2);
  assert(index_reg_62_1 == index_reg_62_2);
}

int fn_R000213_1313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct EventLog_R000213_1313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int threshold_32 = (aux + st.buffer[1]) & 3;
  switch (threshold_32)
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

  int window_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_39 > 11)
  {
    acc = ((acc + (window_39 * 2)) + 5) & 127;
    aux ^= window_39 & 15;
  }
  else
  {
    acc = ((acc - window_39) + 11) & 127;
    aux += 3;
  }
  int index_reg_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000213_1313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st_1 = {0};
  struct MatrixBlock_R000213_1313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int window_14_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_14_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_14_1 > 13)
  {
    acc_1 = ((acc_1 + (window_14_1 * 2)) + 5) & 127;
    aux_1 ^= window_14_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_14_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_14_2 > 13)
  {
    acc_2 = ((acc_2 + (window_14_2 * 2)) + 5) & 127;
    aux_2 ^= window_14_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_14_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_35_1)
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

  switch (pivot_35_2)
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

  int parity_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_10_1) & 63;
  aux_2 = (aux_2 + parity_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_14_1 == window_14_2);
  assert(pivot_35_1 == pivot_35_2);
  assert(parity_10_1 == parity_10_2);
}

int fn_R000213_1313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int window_14 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_14 > 13)
  {
    acc = ((acc + (window_14 * 2)) + 5) & 127;
    aux ^= window_14 & 15;
  }
  else
  {
    acc = ((acc - window_14) + 11) & 127;
    aux += 3;
  }
  int pivot_35 = (aux + st.buffer[1]) & 3;
  switch (pivot_35)
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

  int parity_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000213_1313_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st_1 = {0};
  struct Vector3D_R000213_1313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int segment_89_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_89_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_89_1) & 63;
  aux_2 = (aux_2 + segment_89_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_18_1)
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

  switch (margin_18_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_15_1 = local_arr_1[aux_1 % 3];
  int bound_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_89_1 == segment_89_2);
  assert(margin_18_1 == margin_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_15_1 == bound_15_2);
}

int fn_R000213_1313_17(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000213_1313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int segment_89 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_89) & 63;
  acc ^= aux;
  int margin_18 = (aux + st.buffer[1]) & 3;
  switch (margin_18)
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

  int local_arr[3] = {4, 9, 15};
  int bound_15 = local_arr[aux % 3];
  acc = (acc + (bound_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000213_1313_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st_1 = {0};
  struct MatrixBlock_R000213_1313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_20_1 = local_arr_1[aux_1 % 3];
  int tally_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_20_2 * 2)) & 127;
  int phase_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_75_1 > 44)
  {
    acc_1 = ((acc_1 + (phase_75_1 * 2)) + 5) & 127;
    aux_1 ^= phase_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_75_2 > 44)
  {
    acc_2 = ((acc_2 + (phase_75_2 * 2)) + 5) & 127;
    aux_2 ^= phase_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_60_1)
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

  switch (parity_60_2)
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_20_1 == tally_20_2);
  assert(phase_75_1 == phase_75_2);
  assert(parity_60_1 == parity_60_2);
}

int fn_R000213_1313_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000213_1313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int tally_20 = local_arr[aux % 3];
  acc = (acc + (tally_20 * 2)) & 127;
  int phase_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_75 > 44)
  {
    acc = ((acc + (phase_75 * 2)) + 5) & 127;
    aux ^= phase_75 & 15;
  }
  else
  {
    acc = ((acc - phase_75) + 11) & 127;
    aux += 3;
  }
  int parity_60 = (aux + st.buffer[1]) & 3;
  switch (parity_60)
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

  return (acc + aux) & 255;
}

void main()
{
  int sec_r000213_0_1;
  int sec_r000213_0_2;
  int sec_r000213_1_1;
  int sec_r000213_1_2;
  int sec_r000213_2_1;
  int sec_r000213_2_2;
  int sec_r000213_3_1;
  int sec_r000213_3_2;
  int sec_r000213_4_1;
  int sec_r000213_4_2;
  int sec_r000213_5_1;
  int sec_r000213_5_2;
  int sec_r000213_6_1;
  int sec_r000213_6_2;
  int sec_r000213_7_1;
  int sec_r000213_7_2;
  int sec_r000213_8_1;
  int sec_r000213_8_2;
  int sec_r000213_9_1;
  int sec_r000213_9_2;
  int sec_r000213_10_1;
  int sec_r000213_10_2;
  int sec_r000213_11_1;
  int sec_r000213_11_2;
  int sec_r000213_12_1;
  int sec_r000213_12_2;
  int sec_r000213_13_1;
  int sec_r000213_13_2;
  int sec_r000213_14_1;
  int sec_r000213_14_2;
  int sec_r000213_15_1;
  int sec_r000213_15_2;
  int sec_r000213_16_1;
  int sec_r000213_16_2;
  int sec_r000213_17_1;
  int sec_r000213_17_2;
  int sec_r000213_18_1;
  int sec_r000213_18_2;
  int pub_r000213_0_1;
  int pub_r000213_0_2;
  int pub_r000213_1_1;
  int pub_r000213_1_2;
  int pub_r000213_2_1;
  int pub_r000213_2_2;
  int pub_r000213_3_1;
  int pub_r000213_3_2;
  int pub_r000213_4_1;
  int pub_r000213_4_2;
  int pub_r000213_5_1;
  int pub_r000213_5_2;
  int pub_r000213_6_1;
  int pub_r000213_6_2;
  int pub_r000213_7_1;
  int pub_r000213_7_2;
  int pub_r000213_8_1;
  int pub_r000213_8_2;
  int pub_r000213_9_1;
  int pub_r000213_9_2;
  int pub_r000213_10_1;
  int pub_r000213_10_2;
  int pub_r000213_11_1;
  int pub_r000213_11_2;
  int pub_r000213_12_1;
  int pub_r000213_12_2;
  int pub_r000213_13_1;
  int pub_r000213_13_2;
  int pub_r000213_14_1;
  int pub_r000213_14_2;
  int pub_r000213_15_1;
  int pub_r000213_15_2;
  int pub_r000213_16_1;
  int pub_r000213_16_2;
  int pub_r000213_17_1;
  int pub_r000213_17_2;
  int pub_r000213_18_1;
  int pub_r000213_18_2;
  int pub_r000213_19_1;
  int pub_r000213_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000213_0_1 >= (-100)) && (pub_r000213_0_1 <= 100));
  __CPROVER_assume((pub_r000213_0_2 >= (-100)) && (pub_r000213_0_2 <= 100));
  __CPROVER_assume((pub_r000213_1_1 >= (-100)) && (pub_r000213_1_1 <= 100));
  __CPROVER_assume((pub_r000213_1_2 >= (-100)) && (pub_r000213_1_2 <= 100));
  __CPROVER_assume((pub_r000213_2_1 >= (-100)) && (pub_r000213_2_1 <= 100));
  __CPROVER_assume((pub_r000213_2_2 >= (-100)) && (pub_r000213_2_2 <= 100));
  __CPROVER_assume((pub_r000213_3_1 >= (-100)) && (pub_r000213_3_1 <= 100));
  __CPROVER_assume((pub_r000213_3_2 >= (-100)) && (pub_r000213_3_2 <= 100));
  __CPROVER_assume((pub_r000213_4_1 >= (-100)) && (pub_r000213_4_1 <= 100));
  __CPROVER_assume((pub_r000213_4_2 >= (-100)) && (pub_r000213_4_2 <= 100));
  __CPROVER_assume((pub_r000213_5_1 >= (-100)) && (pub_r000213_5_1 <= 100));
  __CPROVER_assume((pub_r000213_5_2 >= (-100)) && (pub_r000213_5_2 <= 100));
  __CPROVER_assume((pub_r000213_6_1 >= (-100)) && (pub_r000213_6_1 <= 100));
  __CPROVER_assume((pub_r000213_6_2 >= (-100)) && (pub_r000213_6_2 <= 100));
  __CPROVER_assume((pub_r000213_7_1 >= (-100)) && (pub_r000213_7_1 <= 100));
  __CPROVER_assume((pub_r000213_7_2 >= (-100)) && (pub_r000213_7_2 <= 100));
  __CPROVER_assume((pub_r000213_8_1 >= (-100)) && (pub_r000213_8_1 <= 100));
  __CPROVER_assume((pub_r000213_8_2 >= (-100)) && (pub_r000213_8_2 <= 100));
  __CPROVER_assume((pub_r000213_9_1 >= (-100)) && (pub_r000213_9_1 <= 100));
  __CPROVER_assume((pub_r000213_9_2 >= (-100)) && (pub_r000213_9_2 <= 100));
  __CPROVER_assume((pub_r000213_10_1 >= (-100)) && (pub_r000213_10_1 <= 100));
  __CPROVER_assume((pub_r000213_10_2 >= (-100)) && (pub_r000213_10_2 <= 100));
  __CPROVER_assume((pub_r000213_11_1 >= (-100)) && (pub_r000213_11_1 <= 100));
  __CPROVER_assume((pub_r000213_11_2 >= (-100)) && (pub_r000213_11_2 <= 100));
  __CPROVER_assume((pub_r000213_12_1 >= (-100)) && (pub_r000213_12_1 <= 100));
  __CPROVER_assume((pub_r000213_12_2 >= (-100)) && (pub_r000213_12_2 <= 100));
  __CPROVER_assume((pub_r000213_13_1 >= (-100)) && (pub_r000213_13_1 <= 100));
  __CPROVER_assume((pub_r000213_13_2 >= (-100)) && (pub_r000213_13_2 <= 100));
  __CPROVER_assume((pub_r000213_14_1 >= (-100)) && (pub_r000213_14_1 <= 100));
  __CPROVER_assume((pub_r000213_14_2 >= (-100)) && (pub_r000213_14_2 <= 100));
  __CPROVER_assume((pub_r000213_15_1 >= (-100)) && (pub_r000213_15_1 <= 100));
  __CPROVER_assume((pub_r000213_15_2 >= (-100)) && (pub_r000213_15_2 <= 100));
  __CPROVER_assume((pub_r000213_16_1 >= (-100)) && (pub_r000213_16_1 <= 100));
  __CPROVER_assume((pub_r000213_16_2 >= (-100)) && (pub_r000213_16_2 <= 100));
  __CPROVER_assume((pub_r000213_17_1 >= (-100)) && (pub_r000213_17_1 <= 100));
  __CPROVER_assume((pub_r000213_17_2 >= (-100)) && (pub_r000213_17_2 <= 100));
  __CPROVER_assume((pub_r000213_18_1 >= (-100)) && (pub_r000213_18_1 <= 100));
  __CPROVER_assume((pub_r000213_18_2 >= (-100)) && (pub_r000213_18_2 <= 100));
  __CPROVER_assume((pub_r000213_19_1 >= (-100)) && (pub_r000213_19_1 <= 100));
  __CPROVER_assume((pub_r000213_19_2 >= (-100)) && (pub_r000213_19_2 <= 100));
  __CPROVER_assume((sec_r000213_0_1 >= 0) && (sec_r000213_0_1 <= 255));
  __CPROVER_assume((sec_r000213_0_2 >= 0) && (sec_r000213_0_2 <= 255));
  __CPROVER_assume((sec_r000213_1_1 >= 0) && (sec_r000213_1_1 <= 255));
  __CPROVER_assume((sec_r000213_1_2 >= 0) && (sec_r000213_1_2 <= 255));
  __CPROVER_assume((sec_r000213_2_1 >= 0) && (sec_r000213_2_1 <= 255));
  __CPROVER_assume((sec_r000213_2_2 >= 0) && (sec_r000213_2_2 <= 255));
  __CPROVER_assume((sec_r000213_3_1 >= 0) && (sec_r000213_3_1 <= 255));
  __CPROVER_assume((sec_r000213_3_2 >= 0) && (sec_r000213_3_2 <= 255));
  __CPROVER_assume((sec_r000213_4_1 >= 0) && (sec_r000213_4_1 <= 255));
  __CPROVER_assume((sec_r000213_4_2 >= 0) && (sec_r000213_4_2 <= 255));
  __CPROVER_assume((sec_r000213_5_1 >= 0) && (sec_r000213_5_1 <= 255));
  __CPROVER_assume((sec_r000213_5_2 >= 0) && (sec_r000213_5_2 <= 255));
  __CPROVER_assume((sec_r000213_6_1 >= 0) && (sec_r000213_6_1 <= 255));
  __CPROVER_assume((sec_r000213_6_2 >= 0) && (sec_r000213_6_2 <= 255));
  __CPROVER_assume((sec_r000213_7_1 >= 0) && (sec_r000213_7_1 <= 255));
  __CPROVER_assume((sec_r000213_7_2 >= 0) && (sec_r000213_7_2 <= 255));
  __CPROVER_assume((sec_r000213_8_1 >= 0) && (sec_r000213_8_1 <= 255));
  __CPROVER_assume((sec_r000213_8_2 >= 0) && (sec_r000213_8_2 <= 255));
  __CPROVER_assume((sec_r000213_9_1 >= 0) && (sec_r000213_9_1 <= 255));
  __CPROVER_assume((sec_r000213_9_2 >= 0) && (sec_r000213_9_2 <= 255));
  __CPROVER_assume((sec_r000213_10_1 >= 0) && (sec_r000213_10_1 <= 255));
  __CPROVER_assume((sec_r000213_10_2 >= 0) && (sec_r000213_10_2 <= 255));
  __CPROVER_assume((sec_r000213_11_1 >= 0) && (sec_r000213_11_1 <= 255));
  __CPROVER_assume((sec_r000213_11_2 >= 0) && (sec_r000213_11_2 <= 255));
  __CPROVER_assume((sec_r000213_12_1 >= 0) && (sec_r000213_12_1 <= 255));
  __CPROVER_assume((sec_r000213_12_2 >= 0) && (sec_r000213_12_2 <= 255));
  __CPROVER_assume((sec_r000213_13_1 >= 0) && (sec_r000213_13_1 <= 255));
  __CPROVER_assume((sec_r000213_13_2 >= 0) && (sec_r000213_13_2 <= 255));
  __CPROVER_assume((sec_r000213_14_1 >= 0) && (sec_r000213_14_1 <= 255));
  __CPROVER_assume((sec_r000213_14_2 >= 0) && (sec_r000213_14_2 <= 255));
  __CPROVER_assume((sec_r000213_15_1 >= 0) && (sec_r000213_15_1 <= 255));
  __CPROVER_assume((sec_r000213_15_2 >= 0) && (sec_r000213_15_2 <= 255));
  __CPROVER_assume((sec_r000213_16_1 >= 0) && (sec_r000213_16_1 <= 255));
  __CPROVER_assume((sec_r000213_16_2 >= 0) && (sec_r000213_16_2 <= 255));
  __CPROVER_assume((sec_r000213_17_1 >= 0) && (sec_r000213_17_1 <= 255));
  __CPROVER_assume((sec_r000213_17_2 >= 0) && (sec_r000213_17_2 <= 255));
  __CPROVER_assume((sec_r000213_18_1 >= 0) && (sec_r000213_18_1 <= 255));
  __CPROVER_assume((sec_r000213_18_2 >= 0) && (sec_r000213_18_2 <= 255));
  struct EventLog_R000213_1313_0 st_var_0_1 = {0};
  struct EventLog_R000213_1313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000213_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000213_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000213_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000213_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000213_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000213_0_2 + 7) & 15;
  struct Vector3D_R000213_1313_1 st_var_1_1 = {0};
  struct Vector3D_R000213_1313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000213_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000213_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000213_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000213_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000213_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000213_0_2 + 9) & 15;
  struct StreamBuffer_R000213_1313_2 st_var_2_1 = {0};
  struct StreamBuffer_R000213_1313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000213_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000213_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000213_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000213_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000213_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000213_0_2 + 11) & 15;
  struct MatrixBlock_R000213_1313_3 st_var_3_1 = {0};
  struct MatrixBlock_R000213_1313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000213_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000213_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000213_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000213_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000213_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000213_0_2 + 13) & 15;
  union RegisterBank_R000213_1313_0 u_var_1;
  union RegisterBank_R000213_1313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (st_var_0_1.buffer[0] ^ 3) & 3;
  int stage_v_0_2 = (st_var_0_2.buffer[0] ^ 3) & 3;
  switch (stage_v_0_1)
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

  switch (stage_v_0_2)
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

  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 53)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 53)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
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
  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = table_1[3];
  int stage_v_7_2 = table_2[3];
  table_1[3] = (table_1[0] + 15) & 63;
  table_2[3] = (table_2[0] + 15) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  int stage_v_8_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_8_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_8_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_8_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
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

  switch (stage_v_9_2)
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

  int stage_v_10_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (15 & 31);
  int stage_v_10_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (15 & 31);
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  chk_sum_1 ^= (stage_v_10_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_10_2 << 1) & 127;
  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 52)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 52)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_13_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (18 & 31);
  int stage_v_13_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (18 & 31);
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= (stage_v_13_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_13_2 << 1) & 127;
  int stage_v_14_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (19 & 31);
  int stage_v_14_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (19 & 31);
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  chk_sum_1 ^= (stage_v_14_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_14_2 << 1) & 127;
  int stage_v_15_1 = 0;
  int stage_v_15_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_15_1 = ((stage_v_15_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_15_2 = ((stage_v_15_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_16_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_18_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_19_1 = (st_var_3_1.buffer[0] ^ 22) & 3;
  int stage_v_19_2 = (st_var_3_2.buffer[0] ^ 22) & 3;
  switch (stage_v_19_1)
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

  switch (stage_v_19_2)
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

  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = (st_var_2_1.buffer[0] ^ 25) & 3;
  int stage_v_22_2 = (st_var_2_2.buffer[0] ^ 25) & 3;
  switch (stage_v_22_1)
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

  switch (stage_v_22_2)
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

  int stage_v_23_1 = ((st_var_3_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_3_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 51)
    {
      chk_sum_1 ^= stage_v_23_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_23_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 51)
    {
      chk_sum_2 ^= stage_v_23_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_24_1 = table_1[0];
  int stage_v_24_2 = table_2[0];
  table_1[0] = (table_1[1] + 49) & 63;
  table_2[0] = (table_2[1] + 49) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = 0;
  int stage_v_26_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_26_1 = ((stage_v_26_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_26_2 = ((stage_v_26_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_28_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_29_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (34 & 31);
  int stage_v_29_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (34 & 31);
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  chk_sum_1 ^= (stage_v_29_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_29_2 << 1) & 127;
  int stage_v_30_1 = table_1[2];
  int stage_v_30_2 = table_2[2];
  table_1[2] = (table_1[3] + 61) & 63;
  table_2[2] = (table_2[3] + 61) & 63;
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
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = (st_var_1_1.buffer[0] ^ 36) & 3;
  int stage_v_33_2 = (st_var_1_2.buffer[0] ^ 36) & 3;
  switch (stage_v_33_1)
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

  switch (stage_v_33_2)
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

  int stage_v_34_1 = ((st_var_2_1.buffer[1] * 2) + 109) & 63;
  int stage_v_34_2 = ((st_var_2_2.buffer[1] * 2) + 109) & 63;
  if (stage_v_34_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_34_1) - 5) & 255;
    if (stage_v_34_1 > 28)
    {
      chk_sum_1 ^= stage_v_34_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_34_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_34_2) - 5) & 255;
    if (stage_v_34_2 > 28)
    {
      chk_sum_2 ^= stage_v_34_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (st_var_0_1.buffer[0] ^ 39) & 3;
  int stage_v_36_2 = (st_var_0_2.buffer[0] ^ 39) & 3;
  switch (stage_v_36_1)
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

  switch (stage_v_36_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 38) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 38) & 15;
  int stage_v_37_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_37_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= stage_v_37_1;
  chk_sum_2 ^= stage_v_37_2;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 39) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 39) & 15;
  int stage_v_38_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_38_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= stage_v_38_1;
  chk_sum_2 ^= stage_v_38_2;
  int stage_v_39_1 = ((st_var_3_1.buffer[0] * 2) + 124) & 63;
  int stage_v_39_2 = ((st_var_3_2.buffer[0] * 2) + 124) & 63;
  if (stage_v_39_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + stage_v_39_1) - 5) & 255;
    if (stage_v_39_1 > 32)
    {
      chk_sum_1 ^= stage_v_39_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_39_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + stage_v_39_2) - 5) & 255;
    if (stage_v_39_2 > 32)
    {
      chk_sum_2 ^= stage_v_39_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_40_1 = (st_var_0_1.buffer[0] ^ 43) & 3;
  int stage_v_40_2 = (st_var_0_2.buffer[0] ^ 43) & 3;
  switch (stage_v_40_1)
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

  switch (stage_v_40_2)
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

  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  int stage_v_42_1 = (st_var_2_1.buffer[0] ^ 45) & 3;
  int stage_v_42_2 = (st_var_2_2.buffer[0] ^ 45) & 3;
  switch (stage_v_42_1)
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

  switch (stage_v_42_2)
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

  int stage_v_43_1 = ((st_var_3_1.buffer[1] * 2) + 136) & 63;
  int stage_v_43_2 = ((st_var_3_2.buffer[1] * 2) + 136) & 63;
  if (stage_v_43_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_43_1) - 5) & 255;
    if (stage_v_43_1 > 50)
    {
      chk_sum_1 ^= stage_v_43_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_43_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_43_2) - 5) & 255;
    if (stage_v_43_2 > 50)
    {
      chk_sum_2 ^= stage_v_43_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = (st_var_1_1.buffer[0] ^ 48) & 3;
  int stage_v_45_2 = (st_var_1_2.buffer[0] ^ 48) & 3;
  switch (stage_v_45_1)
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

  switch (stage_v_45_2)
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

  int stage_v_46_1 = (st_var_2_1.buffer[0] ^ 49) & 3;
  int stage_v_46_2 = (st_var_2_2.buffer[0] ^ 49) & 3;
  switch (stage_v_46_1)
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

  switch (stage_v_46_2)
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

  int stage_v_47_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_47_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = (st_var_1_1.buffer[0] ^ 52) & 3;
  int stage_v_49_2 = (st_var_1_2.buffer[0] ^ 52) & 3;
  switch (stage_v_49_1)
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = (st_var_2_1.buffer[0] ^ 53) & 3;
  int stage_v_50_2 = (st_var_2_2.buffer[0] ^ 53) & 3;
  switch (stage_v_50_1)
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

  switch (stage_v_50_2)
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

  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
  int stage_v_52_1 = ((st_var_0_1.buffer[1] * 2) + 163) & 63;
  int stage_v_52_2 = ((st_var_0_2.buffer[1] * 2) + 163) & 63;
  if (stage_v_52_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_52_1) - 5) & 255;
    if (stage_v_52_1 > 33)
    {
      chk_sum_1 ^= stage_v_52_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_52_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_52_2) - 5) & 255;
    if (stage_v_52_2 > 33)
    {
      chk_sum_2 ^= stage_v_52_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = (st_var_2_1.buffer[0] ^ 57) & 3;
  int stage_v_54_2 = (st_var_2_2.buffer[0] ^ 57) & 3;
  switch (stage_v_54_1)
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

  switch (stage_v_54_2)
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

  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 57) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 57) & 15;
  int stage_v_56_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_56_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= stage_v_56_1;
  chk_sum_2 ^= stage_v_56_2;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 58) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 58) & 15;
  int stage_v_57_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_57_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= stage_v_57_1;
  chk_sum_2 ^= stage_v_57_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 59) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 59) & 15;
  int stage_v_58_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_58_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= stage_v_58_1;
  chk_sum_2 ^= stage_v_58_2;
  int stage_v_59_1 = ((st_var_3_1.buffer[2] * 2) + 184) & 63;
  int stage_v_59_2 = ((st_var_3_2.buffer[2] * 2) + 184) & 63;
  if (stage_v_59_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_59_1) - 5) & 255;
    if (stage_v_59_1 > 42)
    {
      chk_sum_1 ^= stage_v_59_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_59_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_59_2) - 5) & 255;
    if (stage_v_59_2 > 42)
    {
      chk_sum_2 ^= stage_v_59_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_60_1 = ((st_var_0_1.buffer[0] * 2) + 187) & 63;
  int stage_v_60_2 = ((st_var_0_2.buffer[0] * 2) + 187) & 63;
  if (stage_v_60_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_60_1) - 5) & 255;
    if (stage_v_60_1 > 34)
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
  if (stage_v_60_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_60_2) - 5) & 255;
    if (stage_v_60_2 > 34)
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
  int stage_v_61_1 = ((st_var_1_1.buffer[1] * 2) + 190) & 63;
  int stage_v_61_2 = ((st_var_1_2.buffer[1] * 2) + 190) & 63;
  if (stage_v_61_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_61_1) - 5) & 255;
    if (stage_v_61_1 > 50)
    {
      chk_sum_1 ^= stage_v_61_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_61_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_61_2) - 5) & 255;
    if (stage_v_61_2 > 50)
    {
      chk_sum_2 ^= stage_v_61_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_62_1 = table_1[2];
  int stage_v_62_2 = table_2[2];
  table_1[2] = (table_1[3] + 125) & 63;
  table_2[2] = (table_2[3] + 125) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = ((st_var_3_1.buffer[0] * 2) + 196) & 63;
  int stage_v_63_2 = ((st_var_3_2.buffer[0] * 2) + 196) & 63;
  if (stage_v_63_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_63_1) - 5) & 255;
    if (stage_v_63_1 > 40)
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
  if (stage_v_63_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_63_2) - 5) & 255;
    if (stage_v_63_2 > 40)
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
  int stage_v_64_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_64_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_66_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (71 & 31);
  int stage_v_66_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (71 & 31);
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  chk_sum_1 ^= (stage_v_66_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_66_2 << 1) & 127;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (73 & 31);
  int stage_v_68_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (73 & 31);
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= (stage_v_68_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_68_2 << 1) & 127;
  int stage_v_69_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (74 & 31);
  int stage_v_69_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (74 & 31);
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= (stage_v_69_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_69_2 << 1) & 127;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = table_1[3];
  int stage_v_71_2 = table_2[3];
  table_1[3] = (table_1[0] + 143) & 63;
  table_2[3] = (table_2[0] + 143) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = (st_var_0_1.buffer[0] ^ 75) & 3;
  int stage_v_72_2 = (st_var_0_2.buffer[0] ^ 75) & 3;
  switch (stage_v_72_1)
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

  switch (stage_v_72_2)
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

  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_2_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_2_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
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

  switch (stage_v_74_2)
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

  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 76) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 76) & 15;
  int stage_v_75_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_75_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  chk_sum_1 ^= stage_v_75_1;
  chk_sum_2 ^= stage_v_75_2;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_76_1 = ((stage_v_76_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_76_2 = ((stage_v_76_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = ((st_var_1_1.buffer[2] * 2) + 238) & 63;
  int stage_v_77_2 = ((st_var_1_2.buffer[2] * 2) + 238) & 63;
  if (stage_v_77_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + stage_v_77_1) - 5) & 255;
    if (stage_v_77_1 > 44)
    {
      chk_sum_1 ^= stage_v_77_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_77_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + stage_v_77_2) - 5) & 255;
    if (stage_v_77_2 > 44)
    {
      chk_sum_2 ^= stage_v_77_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_78_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_78_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_79_1 = table_1[3];
  int stage_v_79_2 = table_2[3];
  table_1[3] = (table_1[0] + 159) & 63;
  table_2[3] = (table_2[0] + 159) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_80_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_81_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_81_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_82_1 = table_1[2];
  int stage_v_82_2 = table_2[2];
  table_1[2] = (table_1[3] + 165) & 63;
  table_2[2] = (table_2[3] + 165) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (88 & 31);
  int stage_v_83_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (88 & 31);
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  chk_sum_1 ^= (stage_v_83_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_83_2 << 1) & 127;
  int stage_v_84_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (89 & 31);
  int stage_v_84_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (89 & 31);
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  chk_sum_1 ^= (stage_v_84_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_84_2 << 1) & 127;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((st_var_2_1.buffer[2] * 2) + 265) & 63;
  int stage_v_86_2 = ((st_var_2_2.buffer[2] * 2) + 265) & 63;
  if (stage_v_86_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_86_1) - 5) & 255;
    if (stage_v_86_1 > 48)
    {
      chk_sum_1 ^= stage_v_86_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_86_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_86_2) - 5) & 255;
    if (stage_v_86_2 > 48)
    {
      chk_sum_2 ^= stage_v_86_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_87_1 = (st_var_3_1.buffer[0] ^ 90) & 3;
  int stage_v_87_2 = (st_var_3_2.buffer[0] ^ 90) & 3;
  switch (stage_v_87_1)
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

  switch (stage_v_87_2)
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

  int stage_v_88_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_88_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_89_1 = (st_var_1_1.buffer[0] ^ 92) & 3;
  int stage_v_89_2 = (st_var_1_2.buffer[0] ^ 92) & 3;
  switch (stage_v_89_1)
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

  switch (stage_v_89_2)
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

  int sub_step_90_1 = ((sec_r000213_4_1 + pub_r000213_15_1) + 29) & 127;
  int sub_step_90_2 = ((sec_r000213_4_2 + pub_r000213_15_2) + 29) & 127;
  int stage_v_90_1 = ((sub_step_90_1 * 2) + pub_r000213_11_1) & 127;
  int stage_v_90_2 = ((sub_step_90_2 * 2) + pub_r000213_11_2) & 127;
  st_var_2_1.buffer[0] = stage_v_90_1 & 15;
  st_var_2_2.buffer[0] = stage_v_90_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int sub_step_91_1 = ((stage_v_90_1 + pub_r000213_15_1) + 21) & 127;
  int sub_step_91_2 = ((stage_v_90_2 + pub_r000213_15_2) + 21) & 127;
  int stage_v_91_1 = ((sub_step_91_1 * 2) + pub_r000213_15_1) & 127;
  int stage_v_91_2 = ((sub_step_91_2 * 2) + pub_r000213_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_91_1 & 15;
  st_var_3_2.buffer[1] = stage_v_91_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int sub_step_92_1 = ((stage_v_91_1 + pub_r000213_8_1) + 5) & 127;
  int sub_step_92_2 = ((stage_v_91_2 + pub_r000213_8_2) + 5) & 127;
  int stage_v_92_1 = ((sub_step_92_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_92_2 = ((sub_step_92_2 * 2) + pub_r000213_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_92_1 & 15;
  st_var_0_2.buffer[2] = stage_v_92_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int sub_step_93_1 = ((stage_v_90_1 + pub_r000213_6_1) + 35) & 127;
  int sub_step_93_2 = ((stage_v_90_2 + pub_r000213_6_2) + 35) & 127;
  int stage_v_93_1 = ((sub_step_93_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_93_2 = ((sub_step_93_2 * 2) + pub_r000213_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_93_1 & 15;
  st_var_1_2.buffer[0] = stage_v_93_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int sub_step_94_1 = ((stage_v_93_1 + pub_r000213_18_1) + 11) & 127;
  int sub_step_94_2 = ((stage_v_93_2 + pub_r000213_18_2) + 11) & 127;
  int stage_v_94_1 = ((sub_step_94_1 * 2) + pub_r000213_11_1) & 127;
  int stage_v_94_2 = ((sub_step_94_2 * 2) + pub_r000213_11_2) & 127;
  st_var_2_1.buffer[1] = stage_v_94_1 & 15;
  st_var_2_2.buffer[1] = stage_v_94_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int sub_step_95_1 = ((sec_r000213_9_1 + pub_r000213_8_1) + 15) & 127;
  int sub_step_95_2 = ((sec_r000213_9_2 + pub_r000213_8_2) + 15) & 127;
  int stage_v_95_1 = ((sub_step_95_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_95_2 = ((sub_step_95_2 * 2) + pub_r000213_18_2) & 127;
  st_var_3_1.buffer[2] = stage_v_95_1 & 15;
  st_var_3_2.buffer[2] = stage_v_95_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int sub_step_96_1 = ((sec_r000213_6_1 + pub_r000213_6_1) + 21) & 127;
  int sub_step_96_2 = ((sec_r000213_6_2 + pub_r000213_6_2) + 21) & 127;
  int stage_v_96_1 = ((sub_step_96_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_96_2 = ((sub_step_96_2 * 2) + pub_r000213_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_96_1 & 15;
  st_var_0_2.buffer[0] = stage_v_96_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int sub_step_97_1 = ((sec_r000213_18_1 + pub_r000213_5_1) + 6) & 127;
  int sub_step_97_2 = ((sec_r000213_18_2 + pub_r000213_5_2) + 6) & 127;
  int stage_v_97_1 = ((sub_step_97_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_97_2 = ((sub_step_97_2 * 2) + pub_r000213_6_2) & 127;
  st_var_1_1.buffer[1] = stage_v_97_1 & 15;
  st_var_1_2.buffer[1] = stage_v_97_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int sub_step_98_1 = ((sec_r000213_6_1 + pub_r000213_2_1) + 16) & 127;
  int sub_step_98_2 = ((sec_r000213_6_2 + pub_r000213_2_2) + 16) & 127;
  int stage_v_98_1 = ((sub_step_98_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_98_2 = ((sub_step_98_2 * 2) + pub_r000213_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_98_1 & 15;
  st_var_2_2.buffer[2] = stage_v_98_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int sub_step_99_1 = ((stage_v_92_1 + pub_r000213_4_1) + 34) & 127;
  int sub_step_99_2 = ((stage_v_92_2 + pub_r000213_4_2) + 34) & 127;
  int stage_v_99_1 = ((sub_step_99_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_99_2 = ((sub_step_99_2 * 2) + pub_r000213_8_2) & 127;
  st_var_3_1.buffer[0] = stage_v_99_1 & 15;
  st_var_3_2.buffer[0] = stage_v_99_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int sub_step_100_1 = ((sec_r000213_6_1 + pub_r000213_14_1) + 8) & 127;
  int sub_step_100_2 = ((sec_r000213_6_2 + pub_r000213_14_2) + 8) & 127;
  int stage_v_100_1 = ((sub_step_100_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_100_2 = ((sub_step_100_2 * 2) + pub_r000213_13_2) & 127;
  st_var_0_1.buffer[1] = stage_v_100_1 & 15;
  st_var_0_2.buffer[1] = stage_v_100_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int sub_step_101_1 = ((stage_v_100_1 + pub_r000213_4_1) + 33) & 127;
  int sub_step_101_2 = ((stage_v_100_2 + pub_r000213_4_2) + 33) & 127;
  int stage_v_101_1 = ((sub_step_101_1 * 2) + pub_r000213_5_1) & 127;
  int stage_v_101_2 = ((sub_step_101_2 * 2) + pub_r000213_5_2) & 127;
  st_var_1_1.buffer[2] = stage_v_101_1 & 15;
  st_var_1_2.buffer[2] = stage_v_101_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int sub_step_102_1 = ((stage_v_95_1 + pub_r000213_6_1) + 23) & 127;
  int sub_step_102_2 = ((stage_v_95_2 + pub_r000213_6_2) + 23) & 127;
  int stage_v_102_1 = ((sub_step_102_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_102_2 = ((sub_step_102_2 * 2) + pub_r000213_7_2) & 127;
  st_var_2_1.buffer[0] = stage_v_102_1 & 15;
  st_var_2_2.buffer[0] = stage_v_102_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int sub_step_103_1 = ((sec_r000213_1_1 + pub_r000213_6_1) + 12) & 127;
  int sub_step_103_2 = ((sec_r000213_1_2 + pub_r000213_6_2) + 12) & 127;
  int stage_v_103_1 = ((sub_step_103_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_103_2 = ((sub_step_103_2 * 2) + pub_r000213_12_2) & 127;
  st_var_3_1.buffer[1] = stage_v_103_1 & 15;
  st_var_3_2.buffer[1] = stage_v_103_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int sub_step_104_1 = ((stage_v_93_1 + pub_r000213_14_1) + 13) & 127;
  int sub_step_104_2 = ((stage_v_93_2 + pub_r000213_14_2) + 13) & 127;
  int stage_v_104_1 = ((sub_step_104_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_104_2 = ((sub_step_104_2 * 2) + pub_r000213_17_2) & 127;
  st_var_0_1.buffer[2] = stage_v_104_1 & 15;
  st_var_0_2.buffer[2] = stage_v_104_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int sub_step_105_1 = ((sec_r000213_12_1 + pub_r000213_6_1) + 28) & 127;
  int sub_step_105_2 = ((sec_r000213_12_2 + pub_r000213_6_2) + 28) & 127;
  int stage_v_105_1 = ((sub_step_105_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_105_2 = ((sub_step_105_2 * 2) + pub_r000213_12_2) & 127;
  st_var_1_1.buffer[0] = stage_v_105_1 & 15;
  st_var_1_2.buffer[0] = stage_v_105_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int sub_step_106_1 = ((stage_v_94_1 + pub_r000213_12_1) + 18) & 127;
  int sub_step_106_2 = ((stage_v_94_2 + pub_r000213_12_2) + 18) & 127;
  int stage_v_106_1 = ((sub_step_106_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_106_2 = ((sub_step_106_2 * 2) + pub_r000213_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_106_1 & 15;
  st_var_2_2.buffer[1] = stage_v_106_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int sub_step_107_1 = ((sub_step_101_1 + pub_r000213_13_1) + 10) & 127;
  int sub_step_107_2 = ((sub_step_101_2 + pub_r000213_13_2) + 10) & 127;
  int stage_v_107_1 = ((sub_step_107_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_107_2 = ((sub_step_107_2 * 2) + pub_r000213_17_2) & 127;
  st_var_3_1.buffer[2] = stage_v_107_1 & 15;
  st_var_3_2.buffer[2] = stage_v_107_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int sub_step_108_1 = ((stage_v_93_1 + pub_r000213_19_1) + 33) & 127;
  int sub_step_108_2 = ((stage_v_93_2 + pub_r000213_19_2) + 33) & 127;
  int stage_v_108_1 = ((sub_step_108_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_108_2 = ((sub_step_108_2 * 2) + pub_r000213_13_2) & 127;
  st_var_0_1.buffer[0] = stage_v_108_1 & 15;
  st_var_0_2.buffer[0] = stage_v_108_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int sub_step_109_1 = ((sec_r000213_18_1 + pub_r000213_7_1) + 21) & 127;
  int sub_step_109_2 = ((sec_r000213_18_2 + pub_r000213_7_2) + 21) & 127;
  int stage_v_109_1 = ((sub_step_109_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_109_2 = ((sub_step_109_2 * 2) + pub_r000213_8_2) & 127;
  st_var_1_1.buffer[1] = stage_v_109_1 & 15;
  st_var_1_2.buffer[1] = stage_v_109_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int sub_step_110_1 = ((stage_v_94_1 + pub_r000213_4_1) + 18) & 127;
  int sub_step_110_2 = ((stage_v_94_2 + pub_r000213_4_2) + 18) & 127;
  int stage_v_110_1 = ((sub_step_110_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_110_2 = ((sub_step_110_2 * 2) + pub_r000213_18_2) & 127;
  st_var_2_1.buffer[2] = stage_v_110_1 & 15;
  st_var_2_2.buffer[2] = stage_v_110_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int sub_step_111_1 = ((stage_v_90_1 + pub_r000213_6_1) + 18) & 127;
  int sub_step_111_2 = ((stage_v_90_2 + pub_r000213_6_2) + 18) & 127;
  int stage_v_111_1 = ((sub_step_111_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_111_2 = ((sub_step_111_2 * 2) + pub_r000213_6_2) & 127;
  st_var_3_1.buffer[0] = stage_v_111_1 & 15;
  st_var_3_2.buffer[0] = stage_v_111_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int sub_step_112_1 = ((stage_v_111_1 + pub_r000213_12_1) + 32) & 127;
  int sub_step_112_2 = ((stage_v_111_2 + pub_r000213_12_2) + 32) & 127;
  int stage_v_112_1 = ((sub_step_112_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_112_2 = ((sub_step_112_2 * 2) + pub_r000213_4_2) & 127;
  st_var_0_1.buffer[1] = stage_v_112_1 & 15;
  st_var_0_2.buffer[1] = stage_v_112_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int sub_step_113_1 = ((sec_r000213_4_1 + pub_r000213_7_1) + 20) & 127;
  int sub_step_113_2 = ((sec_r000213_4_2 + pub_r000213_7_2) + 20) & 127;
  int stage_v_113_1 = ((sub_step_113_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_113_2 = ((sub_step_113_2 * 2) + pub_r000213_19_2) & 127;
  st_var_1_1.buffer[2] = stage_v_113_1 & 15;
  st_var_1_2.buffer[2] = stage_v_113_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int sub_step_114_1 = ((stage_v_91_1 + pub_r000213_17_1) + 9) & 127;
  int sub_step_114_2 = ((stage_v_91_2 + pub_r000213_17_2) + 9) & 127;
  int stage_v_114_1 = ((sub_step_114_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_114_2 = ((sub_step_114_2 * 2) + pub_r000213_18_2) & 127;
  st_var_2_1.buffer[0] = stage_v_114_1 & 15;
  st_var_2_2.buffer[0] = stage_v_114_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int sub_step_115_1 = ((sub_step_112_1 + pub_r000213_15_1) + 31) & 127;
  int sub_step_115_2 = ((sub_step_112_2 + pub_r000213_15_2) + 31) & 127;
  int stage_v_115_1 = ((sub_step_115_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_115_2 = ((sub_step_115_2 * 2) + pub_r000213_17_2) & 127;
  st_var_3_1.buffer[1] = stage_v_115_1 & 15;
  st_var_3_2.buffer[1] = stage_v_115_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int sub_step_116_1 = ((sec_r000213_8_1 + pub_r000213_11_1) + 22) & 127;
  int sub_step_116_2 = ((sec_r000213_8_2 + pub_r000213_11_2) + 22) & 127;
  int stage_v_116_1 = ((sub_step_116_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_116_2 = ((sub_step_116_2 * 2) + pub_r000213_1_2) & 127;
  st_var_0_1.buffer[2] = stage_v_116_1 & 15;
  st_var_0_2.buffer[2] = stage_v_116_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int sub_step_117_1 = ((sec_r000213_2_1 + pub_r000213_10_1) + 26) & 127;
  int sub_step_117_2 = ((sec_r000213_2_2 + pub_r000213_10_2) + 26) & 127;
  int stage_v_117_1 = ((sub_step_117_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_117_2 = ((sub_step_117_2 * 2) + pub_r000213_8_2) & 127;
  st_var_1_1.buffer[0] = stage_v_117_1 & 15;
  st_var_1_2.buffer[0] = stage_v_117_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int sub_step_118_1 = ((stage_v_95_1 + pub_r000213_15_1) + 33) & 127;
  int sub_step_118_2 = ((stage_v_95_2 + pub_r000213_15_2) + 33) & 127;
  int stage_v_118_1 = ((sub_step_118_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_118_2 = ((sub_step_118_2 * 2) + pub_r000213_18_2) & 127;
  st_var_2_1.buffer[1] = stage_v_118_1 & 15;
  st_var_2_2.buffer[1] = stage_v_118_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int sub_step_119_1 = ((stage_v_114_1 + pub_r000213_10_1) + 19) & 127;
  int sub_step_119_2 = ((stage_v_114_2 + pub_r000213_10_2) + 19) & 127;
  int stage_v_119_1 = ((sub_step_119_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_119_2 = ((sub_step_119_2 * 2) + pub_r000213_10_2) & 127;
  st_var_3_1.buffer[2] = stage_v_119_1 & 15;
  st_var_3_2.buffer[2] = stage_v_119_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int sub_step_120_1 = ((sub_step_109_1 + pub_r000213_17_1) + 21) & 127;
  int sub_step_120_2 = ((sub_step_109_2 + pub_r000213_17_2) + 21) & 127;
  int stage_v_120_1 = ((sub_step_120_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_120_2 = ((sub_step_120_2 * 2) + pub_r000213_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_120_1 & 15;
  st_var_0_2.buffer[0] = stage_v_120_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int sub_step_121_1 = ((sub_step_91_1 + pub_r000213_8_1) + 15) & 127;
  int sub_step_121_2 = ((sub_step_91_2 + pub_r000213_8_2) + 15) & 127;
  int stage_v_121_1 = ((sub_step_121_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_121_2 = ((sub_step_121_2 * 2) + pub_r000213_19_2) & 127;
  st_var_1_1.buffer[1] = stage_v_121_1 & 15;
  st_var_1_2.buffer[1] = stage_v_121_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int sub_step_122_1 = ((sec_r000213_9_1 + pub_r000213_13_1) + 34) & 127;
  int sub_step_122_2 = ((sec_r000213_9_2 + pub_r000213_13_2) + 34) & 127;
  int stage_v_122_1 = ((sub_step_122_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_122_2 = ((sub_step_122_2 * 2) + pub_r000213_8_2) & 127;
  st_var_2_1.buffer[2] = stage_v_122_1 & 15;
  st_var_2_2.buffer[2] = stage_v_122_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int sub_step_123_1 = ((sec_r000213_3_1 + pub_r000213_13_1) + 20) & 127;
  int sub_step_123_2 = ((sec_r000213_3_2 + pub_r000213_13_2) + 20) & 127;
  int stage_v_123_1 = ((sub_step_123_1 * 2) + pub_r000213_0_1) & 127;
  int stage_v_123_2 = ((sub_step_123_2 * 2) + pub_r000213_0_2) & 127;
  st_var_3_1.buffer[0] = stage_v_123_1 & 15;
  st_var_3_2.buffer[0] = stage_v_123_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int sub_step_124_1 = ((sec_r000213_15_1 + pub_r000213_8_1) + 6) & 127;
  int sub_step_124_2 = ((sec_r000213_15_2 + pub_r000213_8_2) + 6) & 127;
  int stage_v_124_1 = ((sub_step_124_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_124_2 = ((sub_step_124_2 * 2) + pub_r000213_19_2) & 127;
  st_var_0_1.buffer[1] = stage_v_124_1 & 15;
  st_var_0_2.buffer[1] = stage_v_124_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int sub_step_125_1 = ((stage_v_98_1 + pub_r000213_10_1) + 18) & 127;
  int sub_step_125_2 = ((stage_v_98_2 + pub_r000213_10_2) + 18) & 127;
  int stage_v_125_1 = ((sub_step_125_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_125_2 = ((sub_step_125_2 * 2) + pub_r000213_9_2) & 127;
  st_var_1_1.buffer[2] = stage_v_125_1 & 15;
  st_var_1_2.buffer[2] = stage_v_125_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int sub_step_126_1 = ((sub_step_118_1 + pub_r000213_4_1) + 16) & 127;
  int sub_step_126_2 = ((sub_step_118_2 + pub_r000213_4_2) + 16) & 127;
  int stage_v_126_1 = ((sub_step_126_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_126_2 = ((sub_step_126_2 * 2) + pub_r000213_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_126_1 & 15;
  st_var_2_2.buffer[0] = stage_v_126_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int sub_step_127_1 = ((stage_v_111_1 + pub_r000213_18_1) + 19) & 127;
  int sub_step_127_2 = ((stage_v_111_2 + pub_r000213_18_2) + 19) & 127;
  int stage_v_127_1 = ((sub_step_127_1 * 2) + pub_r000213_0_1) & 127;
  int stage_v_127_2 = ((sub_step_127_2 * 2) + pub_r000213_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_127_1 & 15;
  st_var_3_2.buffer[1] = stage_v_127_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int sub_step_128_1 = ((stage_v_125_1 + pub_r000213_6_1) + 16) & 127;
  int sub_step_128_2 = ((stage_v_125_2 + pub_r000213_6_2) + 16) & 127;
  int stage_v_128_1 = ((sub_step_128_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_128_2 = ((sub_step_128_2 * 2) + pub_r000213_10_2) & 127;
  st_var_0_1.buffer[2] = stage_v_128_1 & 15;
  st_var_0_2.buffer[2] = stage_v_128_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int sub_step_129_1 = ((stage_v_120_1 + pub_r000213_0_1) + 33) & 127;
  int sub_step_129_2 = ((stage_v_120_2 + pub_r000213_0_2) + 33) & 127;
  int stage_v_129_1 = ((sub_step_129_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_129_2 = ((sub_step_129_2 * 2) + pub_r000213_9_2) & 127;
  st_var_1_1.buffer[0] = stage_v_129_1 & 15;
  st_var_1_2.buffer[0] = stage_v_129_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int sub_step_130_1 = ((sub_step_102_1 + pub_r000213_6_1) + 31) & 127;
  int sub_step_130_2 = ((sub_step_102_2 + pub_r000213_6_2) + 31) & 127;
  int stage_v_130_1 = ((sub_step_130_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_130_2 = ((sub_step_130_2 * 2) + pub_r000213_10_2) & 127;
  st_var_2_1.buffer[1] = stage_v_130_1 & 15;
  st_var_2_2.buffer[1] = stage_v_130_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int sub_step_131_1 = ((sec_r000213_0_1 + pub_r000213_18_1) + 32) & 127;
  int sub_step_131_2 = ((sec_r000213_0_2 + pub_r000213_18_2) + 32) & 127;
  int stage_v_131_1 = ((sub_step_131_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_131_2 = ((sub_step_131_2 * 2) + pub_r000213_1_2) & 127;
  st_var_3_1.buffer[2] = stage_v_131_1 & 15;
  st_var_3_2.buffer[2] = stage_v_131_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int sub_step_132_1 = ((stage_v_93_1 + pub_r000213_12_1) + 7) & 127;
  int sub_step_132_2 = ((stage_v_93_2 + pub_r000213_12_2) + 7) & 127;
  int stage_v_132_1 = ((sub_step_132_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_132_2 = ((sub_step_132_2 * 2) + pub_r000213_8_2) & 127;
  st_var_0_1.buffer[0] = stage_v_132_1 & 15;
  st_var_0_2.buffer[0] = stage_v_132_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int sub_step_133_1 = ((stage_v_109_1 + pub_r000213_10_1) + 11) & 127;
  int sub_step_133_2 = ((stage_v_109_2 + pub_r000213_10_2) + 11) & 127;
  int stage_v_133_1 = ((sub_step_133_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_133_2 = ((sub_step_133_2 * 2) + pub_r000213_18_2) & 127;
  st_var_1_1.buffer[1] = stage_v_133_1 & 15;
  st_var_1_2.buffer[1] = stage_v_133_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int sub_step_134_1 = ((sec_r000213_15_1 + pub_r000213_8_1) + 31) & 127;
  int sub_step_134_2 = ((sec_r000213_15_2 + pub_r000213_8_2) + 31) & 127;
  int stage_v_134_1 = ((sub_step_134_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_134_2 = ((sub_step_134_2 * 2) + pub_r000213_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_134_1 & 15;
  st_var_2_2.buffer[2] = stage_v_134_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int sub_step_135_1 = ((stage_v_120_1 + pub_r000213_7_1) + 20) & 127;
  int sub_step_135_2 = ((stage_v_120_2 + pub_r000213_7_2) + 20) & 127;
  int stage_v_135_1 = ((sub_step_135_1 * 2) + pub_r000213_16_1) & 127;
  int stage_v_135_2 = ((sub_step_135_2 * 2) + pub_r000213_16_2) & 127;
  st_var_3_1.buffer[0] = stage_v_135_1 & 15;
  st_var_3_2.buffer[0] = stage_v_135_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int sub_step_136_1 = ((stage_v_114_1 + pub_r000213_15_1) + 21) & 127;
  int sub_step_136_2 = ((stage_v_114_2 + pub_r000213_15_2) + 21) & 127;
  int stage_v_136_1 = ((sub_step_136_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_136_2 = ((sub_step_136_2 * 2) + pub_r000213_1_2) & 127;
  st_var_0_1.buffer[1] = stage_v_136_1 & 15;
  st_var_0_2.buffer[1] = stage_v_136_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int sub_step_137_1 = ((sec_r000213_7_1 + pub_r000213_1_1) + 11) & 127;
  int sub_step_137_2 = ((sec_r000213_7_2 + pub_r000213_1_2) + 11) & 127;
  int stage_v_137_1 = ((sub_step_137_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_137_2 = ((sub_step_137_2 * 2) + pub_r000213_2_2) & 127;
  st_var_1_1.buffer[2] = stage_v_137_1 & 15;
  st_var_1_2.buffer[2] = stage_v_137_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int sub_step_138_1 = ((stage_v_98_1 + pub_r000213_0_1) + 12) & 127;
  int sub_step_138_2 = ((stage_v_98_2 + pub_r000213_0_2) + 12) & 127;
  int stage_v_138_1 = ((sub_step_138_1 * 2) + pub_r000213_16_1) & 127;
  int stage_v_138_2 = ((sub_step_138_2 * 2) + pub_r000213_16_2) & 127;
  st_var_2_1.buffer[0] = stage_v_138_1 & 15;
  st_var_2_2.buffer[0] = stage_v_138_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int sub_step_139_1 = ((sub_step_129_1 + pub_r000213_6_1) + 16) & 127;
  int sub_step_139_2 = ((sub_step_129_2 + pub_r000213_6_2) + 16) & 127;
  int stage_v_139_1 = ((sub_step_139_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_139_2 = ((sub_step_139_2 * 2) + pub_r000213_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_139_1 & 15;
  st_var_3_2.buffer[1] = stage_v_139_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int sub_step_140_1 = ((sub_step_130_1 + pub_r000213_12_1) + 16) & 127;
  int sub_step_140_2 = ((sub_step_130_2 + pub_r000213_12_2) + 16) & 127;
  int stage_v_140_1 = ((sub_step_140_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_140_2 = ((sub_step_140_2 * 2) + pub_r000213_6_2) & 127;
  st_var_0_1.buffer[2] = stage_v_140_1 & 15;
  st_var_0_2.buffer[2] = stage_v_140_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int sub_step_141_1 = ((sec_r000213_18_1 + pub_r000213_0_1) + 13) & 127;
  int sub_step_141_2 = ((sec_r000213_18_2 + pub_r000213_0_2) + 13) & 127;
  int stage_v_141_1 = ((sub_step_141_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_141_2 = ((sub_step_141_2 * 2) + pub_r000213_2_2) & 127;
  st_var_1_1.buffer[0] = stage_v_141_1 & 15;
  st_var_1_2.buffer[0] = stage_v_141_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int sub_step_142_1 = ((sub_step_90_1 + pub_r000213_11_1) + 26) & 127;
  int sub_step_142_2 = ((sub_step_90_2 + pub_r000213_11_2) + 26) & 127;
  int stage_v_142_1 = ((sub_step_142_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_142_2 = ((sub_step_142_2 * 2) + pub_r000213_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_142_1 & 15;
  st_var_2_2.buffer[1] = stage_v_142_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int sub_step_143_1 = ((sec_r000213_4_1 + pub_r000213_16_1) + 34) & 127;
  int sub_step_143_2 = ((sec_r000213_4_2 + pub_r000213_16_2) + 34) & 127;
  int stage_v_143_1 = ((sub_step_143_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_143_2 = ((sub_step_143_2 * 2) + pub_r000213_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_143_1 & 15;
  st_var_3_2.buffer[2] = stage_v_143_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int sub_step_144_1 = ((stage_v_100_1 + pub_r000213_16_1) + 23) & 127;
  int sub_step_144_2 = ((stage_v_100_2 + pub_r000213_16_2) + 23) & 127;
  int stage_v_144_1 = ((sub_step_144_1 * 2) + pub_r000213_14_1) & 127;
  int stage_v_144_2 = ((sub_step_144_2 * 2) + pub_r000213_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_144_1 & 15;
  st_var_0_2.buffer[0] = stage_v_144_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int sub_step_145_1 = ((sec_r000213_14_1 + pub_r000213_1_1) + 24) & 127;
  int sub_step_145_2 = ((sec_r000213_14_2 + pub_r000213_1_2) + 24) & 127;
  int stage_v_145_1 = ((sub_step_145_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_145_2 = ((sub_step_145_2 * 2) + pub_r000213_4_2) & 127;
  st_var_1_1.buffer[1] = stage_v_145_1 & 15;
  st_var_1_2.buffer[1] = stage_v_145_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int sub_step_146_1 = ((stage_v_101_1 + pub_r000213_9_1) + 12) & 127;
  int sub_step_146_2 = ((stage_v_101_2 + pub_r000213_9_2) + 12) & 127;
  int stage_v_146_1 = ((sub_step_146_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_146_2 = ((sub_step_146_2 * 2) + pub_r000213_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_146_1 & 15;
  st_var_2_2.buffer[2] = stage_v_146_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int sub_step_147_1 = ((sub_step_146_1 + pub_r000213_13_1) + 27) & 127;
  int sub_step_147_2 = ((sub_step_146_2 + pub_r000213_13_2) + 27) & 127;
  int stage_v_147_1 = ((sub_step_147_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_147_2 = ((sub_step_147_2 * 2) + pub_r000213_6_2) & 127;
  st_var_3_1.buffer[0] = stage_v_147_1 & 15;
  st_var_3_2.buffer[0] = stage_v_147_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int sub_step_148_1 = ((sec_r000213_5_1 + pub_r000213_13_1) + 20) & 127;
  int sub_step_148_2 = ((sec_r000213_5_2 + pub_r000213_13_2) + 20) & 127;
  int stage_v_148_1 = ((sub_step_148_1 * 2) + pub_r000213_11_1) & 127;
  int stage_v_148_2 = ((sub_step_148_2 * 2) + pub_r000213_11_2) & 127;
  st_var_0_1.buffer[1] = stage_v_148_1 & 15;
  st_var_0_2.buffer[1] = stage_v_148_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int sub_step_149_1 = ((sec_r000213_3_1 + pub_r000213_17_1) + 8) & 127;
  int sub_step_149_2 = ((sec_r000213_3_2 + pub_r000213_17_2) + 8) & 127;
  int stage_v_149_1 = ((sub_step_149_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_149_2 = ((sub_step_149_2 * 2) + pub_r000213_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_149_1 & 15;
  st_var_1_2.buffer[2] = stage_v_149_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int sub_step_150_1 = ((sub_step_111_1 + pub_r000213_8_1) + 24) & 127;
  int sub_step_150_2 = ((sub_step_111_2 + pub_r000213_8_2) + 24) & 127;
  int stage_v_150_1 = ((sub_step_150_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_150_2 = ((sub_step_150_2 * 2) + pub_r000213_12_2) & 127;
  st_var_2_1.buffer[0] = stage_v_150_1 & 15;
  st_var_2_2.buffer[0] = stage_v_150_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int sub_step_151_1 = ((sec_r000213_0_1 + pub_r000213_4_1) + 23) & 127;
  int sub_step_151_2 = ((sec_r000213_0_2 + pub_r000213_4_2) + 23) & 127;
  int stage_v_151_1 = ((sub_step_151_1 * 2) + pub_r000213_0_1) & 127;
  int stage_v_151_2 = ((sub_step_151_2 * 2) + pub_r000213_0_2) & 127;
  st_var_3_1.buffer[1] = stage_v_151_1 & 15;
  st_var_3_2.buffer[1] = stage_v_151_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int sub_step_152_1 = ((stage_v_116_1 + pub_r000213_18_1) + 18) & 127;
  int sub_step_152_2 = ((stage_v_116_2 + pub_r000213_18_2) + 18) & 127;
  int stage_v_152_1 = ((sub_step_152_1 * 2) + pub_r000213_14_1) & 127;
  int stage_v_152_2 = ((sub_step_152_2 * 2) + pub_r000213_14_2) & 127;
  st_var_0_1.buffer[2] = stage_v_152_1 & 15;
  st_var_0_2.buffer[2] = stage_v_152_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int sub_step_153_1 = ((sub_step_132_1 + pub_r000213_5_1) + 14) & 127;
  int sub_step_153_2 = ((sub_step_132_2 + pub_r000213_5_2) + 14) & 127;
  int stage_v_153_1 = ((sub_step_153_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_153_2 = ((sub_step_153_2 * 2) + pub_r000213_4_2) & 127;
  st_var_1_1.buffer[0] = stage_v_153_1 & 15;
  st_var_1_2.buffer[0] = stage_v_153_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int sub_step_154_1 = ((stage_v_135_1 + pub_r000213_1_1) + 24) & 127;
  int sub_step_154_2 = ((stage_v_135_2 + pub_r000213_1_2) + 24) & 127;
  int stage_v_154_1 = ((sub_step_154_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_154_2 = ((sub_step_154_2 * 2) + pub_r000213_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_154_1 & 15;
  st_var_2_2.buffer[1] = stage_v_154_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int sub_step_155_1 = ((sec_r000213_2_1 + pub_r000213_14_1) + 35) & 127;
  int sub_step_155_2 = ((sec_r000213_2_2 + pub_r000213_14_2) + 35) & 127;
  int stage_v_155_1 = ((sub_step_155_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_155_2 = ((sub_step_155_2 * 2) + pub_r000213_6_2) & 127;
  st_var_3_1.buffer[2] = stage_v_155_1 & 15;
  st_var_3_2.buffer[2] = stage_v_155_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int sub_step_156_1 = ((sec_r000213_14_1 + pub_r000213_15_1) + 17) & 127;
  int sub_step_156_2 = ((sec_r000213_14_2 + pub_r000213_15_2) + 17) & 127;
  int stage_v_156_1 = ((sub_step_156_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_156_2 = ((sub_step_156_2 * 2) + pub_r000213_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_156_1 & 15;
  st_var_0_2.buffer[0] = stage_v_156_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int sub_step_157_1 = ((stage_v_153_1 + pub_r000213_10_1) + 18) & 127;
  int sub_step_157_2 = ((stage_v_153_2 + pub_r000213_10_2) + 18) & 127;
  int stage_v_157_1 = ((sub_step_157_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_157_2 = ((sub_step_157_2 * 2) + pub_r000213_13_2) & 127;
  st_var_1_1.buffer[1] = stage_v_157_1 & 15;
  st_var_1_2.buffer[1] = stage_v_157_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int sub_step_158_1 = ((stage_v_95_1 + pub_r000213_16_1) + 9) & 127;
  int sub_step_158_2 = ((stage_v_95_2 + pub_r000213_16_2) + 9) & 127;
  int stage_v_158_1 = ((sub_step_158_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_158_2 = ((sub_step_158_2 * 2) + pub_r000213_17_2) & 127;
  st_var_2_1.buffer[2] = stage_v_158_1 & 15;
  st_var_2_2.buffer[2] = stage_v_158_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int sub_step_159_1 = ((sec_r000213_17_1 + pub_r000213_10_1) + 25) & 127;
  int sub_step_159_2 = ((sec_r000213_17_2 + pub_r000213_10_2) + 25) & 127;
  int stage_v_159_1 = ((sub_step_159_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_159_2 = ((sub_step_159_2 * 2) + pub_r000213_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_159_1 & 15;
  st_var_3_2.buffer[0] = stage_v_159_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int sub_step_160_1 = ((sub_step_95_1 + pub_r000213_8_1) + 10) & 127;
  int sub_step_160_2 = ((sub_step_95_2 + pub_r000213_8_2) + 10) & 127;
  int stage_v_160_1 = ((sub_step_160_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_160_2 = ((sub_step_160_2 * 2) + pub_r000213_7_2) & 127;
  st_var_0_1.buffer[1] = stage_v_160_1 & 15;
  st_var_0_2.buffer[1] = stage_v_160_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int sub_step_161_1 = ((stage_v_96_1 + pub_r000213_15_1) + 9) & 127;
  int sub_step_161_2 = ((stage_v_96_2 + pub_r000213_15_2) + 9) & 127;
  int stage_v_161_1 = ((sub_step_161_1 * 2) + pub_r000213_15_1) & 127;
  int stage_v_161_2 = ((sub_step_161_2 * 2) + pub_r000213_15_2) & 127;
  st_var_1_1.buffer[2] = stage_v_161_1 & 15;
  st_var_1_2.buffer[2] = stage_v_161_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int sub_step_162_1 = ((stage_v_152_1 + pub_r000213_18_1) + 19) & 127;
  int sub_step_162_2 = ((stage_v_152_2 + pub_r000213_18_2) + 19) & 127;
  int stage_v_162_1 = ((sub_step_162_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_162_2 = ((sub_step_162_2 * 2) + pub_r000213_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_162_1 & 15;
  st_var_2_2.buffer[0] = stage_v_162_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int sub_step_163_1 = ((sub_step_99_1 + pub_r000213_3_1) + 27) & 127;
  int sub_step_163_2 = ((sub_step_99_2 + pub_r000213_3_2) + 27) & 127;
  int stage_v_163_1 = ((sub_step_163_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_163_2 = ((sub_step_163_2 * 2) + pub_r000213_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_163_1 & 15;
  st_var_3_2.buffer[1] = stage_v_163_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int sub_step_164_1 = ((sec_r000213_4_1 + pub_r000213_19_1) + 13) & 127;
  int sub_step_164_2 = ((sec_r000213_4_2 + pub_r000213_19_2) + 13) & 127;
  int stage_v_164_1 = ((sub_step_164_1 * 2) + pub_r000213_3_1) & 127;
  int stage_v_164_2 = ((sub_step_164_2 * 2) + pub_r000213_3_2) & 127;
  st_var_0_1.buffer[2] = stage_v_164_1 & 15;
  st_var_0_2.buffer[2] = stage_v_164_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int sub_step_165_1 = ((stage_v_127_1 + pub_r000213_10_1) + 6) & 127;
  int sub_step_165_2 = ((stage_v_127_2 + pub_r000213_10_2) + 6) & 127;
  int stage_v_165_1 = ((sub_step_165_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_165_2 = ((sub_step_165_2 * 2) + pub_r000213_17_2) & 127;
  st_var_1_1.buffer[0] = stage_v_165_1 & 15;
  st_var_1_2.buffer[0] = stage_v_165_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int sub_step_166_1 = ((sub_step_116_1 + pub_r000213_1_1) + 32) & 127;
  int sub_step_166_2 = ((sub_step_116_2 + pub_r000213_1_2) + 32) & 127;
  int stage_v_166_1 = ((sub_step_166_1 * 2) + pub_r000213_5_1) & 127;
  int stage_v_166_2 = ((sub_step_166_2 * 2) + pub_r000213_5_2) & 127;
  st_var_2_1.buffer[1] = stage_v_166_1 & 15;
  st_var_2_2.buffer[1] = stage_v_166_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int sub_step_167_1 = ((stage_v_94_1 + pub_r000213_15_1) + 33) & 127;
  int sub_step_167_2 = ((stage_v_94_2 + pub_r000213_15_2) + 33) & 127;
  int stage_v_167_1 = ((sub_step_167_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_167_2 = ((sub_step_167_2 * 2) + pub_r000213_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_167_1 & 15;
  st_var_3_2.buffer[2] = stage_v_167_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int sub_step_168_1 = ((sub_step_143_1 + pub_r000213_14_1) + 10) & 127;
  int sub_step_168_2 = ((sub_step_143_2 + pub_r000213_14_2) + 10) & 127;
  int stage_v_168_1 = ((sub_step_168_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_168_2 = ((sub_step_168_2 * 2) + pub_r000213_17_2) & 127;
  st_var_0_1.buffer[0] = stage_v_168_1 & 15;
  st_var_0_2.buffer[0] = stage_v_168_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int sub_step_169_1 = ((sub_step_105_1 + pub_r000213_2_1) + 32) & 127;
  int sub_step_169_2 = ((sub_step_105_2 + pub_r000213_2_2) + 32) & 127;
  int stage_v_169_1 = ((sub_step_169_1 * 2) + pub_r000213_11_1) & 127;
  int stage_v_169_2 = ((sub_step_169_2 * 2) + pub_r000213_11_2) & 127;
  st_var_1_1.buffer[1] = stage_v_169_1 & 15;
  st_var_1_2.buffer[1] = stage_v_169_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int sub_step_170_1 = ((sub_step_124_1 + pub_r000213_9_1) + 27) & 127;
  int sub_step_170_2 = ((sub_step_124_2 + pub_r000213_9_2) + 27) & 127;
  int stage_v_170_1 = ((sub_step_170_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_170_2 = ((sub_step_170_2 * 2) + pub_r000213_2_2) & 127;
  st_var_2_1.buffer[2] = stage_v_170_1 & 15;
  st_var_2_2.buffer[2] = stage_v_170_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int sub_step_171_1 = ((stage_v_105_1 + pub_r000213_18_1) + 34) & 127;
  int sub_step_171_2 = ((stage_v_105_2 + pub_r000213_18_2) + 34) & 127;
  int stage_v_171_1 = ((sub_step_171_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_171_2 = ((sub_step_171_2 * 2) + pub_r000213_2_2) & 127;
  st_var_3_1.buffer[0] = stage_v_171_1 & 15;
  st_var_3_2.buffer[0] = stage_v_171_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int sub_step_172_1 = ((stage_v_96_1 + pub_r000213_19_1) + 22) & 127;
  int sub_step_172_2 = ((stage_v_96_2 + pub_r000213_19_2) + 22) & 127;
  int stage_v_172_1 = ((sub_step_172_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_172_2 = ((sub_step_172_2 * 2) + pub_r000213_1_2) & 127;
  st_var_0_1.buffer[1] = stage_v_172_1 & 15;
  st_var_0_2.buffer[1] = stage_v_172_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int sub_step_173_1 = ((sub_step_149_1 + pub_r000213_17_1) + 25) & 127;
  int sub_step_173_2 = ((sub_step_149_2 + pub_r000213_17_2) + 25) & 127;
  int stage_v_173_1 = ((sub_step_173_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_173_2 = ((sub_step_173_2 * 2) + pub_r000213_19_2) & 127;
  st_var_1_1.buffer[2] = stage_v_173_1 & 15;
  st_var_1_2.buffer[2] = stage_v_173_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int sub_step_174_1 = ((sub_step_103_1 + pub_r000213_16_1) + 17) & 127;
  int sub_step_174_2 = ((sub_step_103_2 + pub_r000213_16_2) + 17) & 127;
  int stage_v_174_1 = ((sub_step_174_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_174_2 = ((sub_step_174_2 * 2) + pub_r000213_10_2) & 127;
  st_var_2_1.buffer[0] = stage_v_174_1 & 15;
  st_var_2_2.buffer[0] = stage_v_174_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int sub_step_175_1 = ((stage_v_152_1 + pub_r000213_14_1) + 11) & 127;
  int sub_step_175_2 = ((stage_v_152_2 + pub_r000213_14_2) + 11) & 127;
  int stage_v_175_1 = ((sub_step_175_1 * 2) + pub_r000213_15_1) & 127;
  int stage_v_175_2 = ((sub_step_175_2 * 2) + pub_r000213_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_175_1 & 15;
  st_var_3_2.buffer[1] = stage_v_175_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int sub_step_176_1 = ((sec_r000213_17_1 + pub_r000213_4_1) + 5) & 127;
  int sub_step_176_2 = ((sec_r000213_17_2 + pub_r000213_4_2) + 5) & 127;
  int stage_v_176_1 = ((sub_step_176_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_176_2 = ((sub_step_176_2 * 2) + pub_r000213_2_2) & 127;
  st_var_0_1.buffer[2] = stage_v_176_1 & 15;
  st_var_0_2.buffer[2] = stage_v_176_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int sub_step_177_1 = ((sec_r000213_4_1 + pub_r000213_2_1) + 16) & 127;
  int sub_step_177_2 = ((sec_r000213_4_2 + pub_r000213_2_2) + 16) & 127;
  int stage_v_177_1 = ((sub_step_177_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_177_2 = ((sub_step_177_2 * 2) + pub_r000213_10_2) & 127;
  st_var_1_1.buffer[0] = stage_v_177_1 & 15;
  st_var_1_2.buffer[0] = stage_v_177_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int sub_step_178_1 = ((sub_step_140_1 + pub_r000213_7_1) + 24) & 127;
  int sub_step_178_2 = ((sub_step_140_2 + pub_r000213_7_2) + 24) & 127;
  int stage_v_178_1 = ((sub_step_178_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_178_2 = ((sub_step_178_2 * 2) + pub_r000213_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_178_1 & 15;
  st_var_2_2.buffer[1] = stage_v_178_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int sub_step_179_1 = ((sec_r000213_17_1 + pub_r000213_1_1) + 24) & 127;
  int sub_step_179_2 = ((sec_r000213_17_2 + pub_r000213_1_2) + 24) & 127;
  int stage_v_179_1 = ((sub_step_179_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_179_2 = ((sub_step_179_2 * 2) + pub_r000213_7_2) & 127;
  st_var_3_1.buffer[2] = stage_v_179_1 & 15;
  st_var_3_2.buffer[2] = stage_v_179_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int sub_step_180_1 = ((stage_v_177_1 + pub_r000213_9_1) + 18) & 127;
  int sub_step_180_2 = ((stage_v_177_2 + pub_r000213_9_2) + 18) & 127;
  int stage_v_180_1 = ((sub_step_180_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_180_2 = ((sub_step_180_2 * 2) + pub_r000213_19_2) & 127;
  st_var_0_1.buffer[0] = stage_v_180_1 & 15;
  st_var_0_2.buffer[0] = stage_v_180_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int sub_step_181_1 = ((sec_r000213_1_1 + pub_r000213_12_1) + 10) & 127;
  int sub_step_181_2 = ((sec_r000213_1_2 + pub_r000213_12_2) + 10) & 127;
  int stage_v_181_1 = ((sub_step_181_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_181_2 = ((sub_step_181_2 * 2) + pub_r000213_9_2) & 127;
  st_var_1_1.buffer[1] = stage_v_181_1 & 15;
  st_var_1_2.buffer[1] = stage_v_181_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int sub_step_182_1 = ((sub_step_118_1 + pub_r000213_8_1) + 30) & 127;
  int sub_step_182_2 = ((sub_step_118_2 + pub_r000213_8_2) + 30) & 127;
  int stage_v_182_1 = ((sub_step_182_1 * 2) + pub_r000213_14_1) & 127;
  int stage_v_182_2 = ((sub_step_182_2 * 2) + pub_r000213_14_2) & 127;
  st_var_2_1.buffer[2] = stage_v_182_1 & 15;
  st_var_2_2.buffer[2] = stage_v_182_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int sub_step_183_1 = ((sub_step_130_1 + pub_r000213_16_1) + 24) & 127;
  int sub_step_183_2 = ((sub_step_130_2 + pub_r000213_16_2) + 24) & 127;
  int stage_v_183_1 = ((sub_step_183_1 * 2) + pub_r000213_3_1) & 127;
  int stage_v_183_2 = ((sub_step_183_2 * 2) + pub_r000213_3_2) & 127;
  st_var_3_1.buffer[0] = stage_v_183_1 & 15;
  st_var_3_2.buffer[0] = stage_v_183_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int sub_step_184_1 = ((stage_v_183_1 + pub_r000213_10_1) + 15) & 127;
  int sub_step_184_2 = ((stage_v_183_2 + pub_r000213_10_2) + 15) & 127;
  int stage_v_184_1 = ((sub_step_184_1 * 2) + pub_r000213_10_1) & 127;
  int stage_v_184_2 = ((sub_step_184_2 * 2) + pub_r000213_10_2) & 127;
  st_var_0_1.buffer[1] = stage_v_184_1 & 15;
  st_var_0_2.buffer[1] = stage_v_184_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int sub_step_185_1 = ((sec_r000213_5_1 + pub_r000213_17_1) + 35) & 127;
  int sub_step_185_2 = ((sec_r000213_5_2 + pub_r000213_17_2) + 35) & 127;
  int stage_v_185_1 = ((sub_step_185_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_185_2 = ((sub_step_185_2 * 2) + pub_r000213_13_2) & 127;
  st_var_1_1.buffer[2] = stage_v_185_1 & 15;
  st_var_1_2.buffer[2] = stage_v_185_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int sub_step_186_1 = ((stage_v_183_1 + pub_r000213_7_1) + 33) & 127;
  int sub_step_186_2 = ((stage_v_183_2 + pub_r000213_7_2) + 33) & 127;
  int stage_v_186_1 = ((sub_step_186_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_186_2 = ((sub_step_186_2 * 2) + pub_r000213_6_2) & 127;
  st_var_2_1.buffer[0] = stage_v_186_1 & 15;
  st_var_2_2.buffer[0] = stage_v_186_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int sub_step_187_1 = ((stage_v_169_1 + pub_r000213_15_1) + 7) & 127;
  int sub_step_187_2 = ((stage_v_169_2 + pub_r000213_15_2) + 7) & 127;
  int stage_v_187_1 = ((sub_step_187_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_187_2 = ((sub_step_187_2 * 2) + pub_r000213_7_2) & 127;
  st_var_3_1.buffer[1] = stage_v_187_1 & 15;
  st_var_3_2.buffer[1] = stage_v_187_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int sub_step_188_1 = ((sub_step_186_1 + pub_r000213_14_1) + 32) & 127;
  int sub_step_188_2 = ((sub_step_186_2 + pub_r000213_14_2) + 32) & 127;
  int stage_v_188_1 = ((sub_step_188_1 * 2) + pub_r000213_3_1) & 127;
  int stage_v_188_2 = ((sub_step_188_2 * 2) + pub_r000213_3_2) & 127;
  st_var_0_1.buffer[2] = stage_v_188_1 & 15;
  st_var_0_2.buffer[2] = stage_v_188_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int sub_step_189_1 = ((sec_r000213_10_1 + pub_r000213_14_1) + 24) & 127;
  int sub_step_189_2 = ((sec_r000213_10_2 + pub_r000213_14_2) + 24) & 127;
  int stage_v_189_1 = ((sub_step_189_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_189_2 = ((sub_step_189_2 * 2) + pub_r000213_2_2) & 127;
  st_var_1_1.buffer[0] = stage_v_189_1 & 15;
  st_var_1_2.buffer[0] = stage_v_189_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int sub_step_190_1 = ((stage_v_107_1 + pub_r000213_3_1) + 30) & 127;
  int sub_step_190_2 = ((stage_v_107_2 + pub_r000213_3_2) + 30) & 127;
  int stage_v_190_1 = ((sub_step_190_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_190_2 = ((sub_step_190_2 * 2) + pub_r000213_9_2) & 127;
  st_var_2_1.buffer[1] = stage_v_190_1 & 15;
  st_var_2_2.buffer[1] = stage_v_190_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int sub_step_191_1 = ((sub_step_151_1 + pub_r000213_7_1) + 27) & 127;
  int sub_step_191_2 = ((sub_step_151_2 + pub_r000213_7_2) + 27) & 127;
  int stage_v_191_1 = ((sub_step_191_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_191_2 = ((sub_step_191_2 * 2) + pub_r000213_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_191_1 & 15;
  st_var_3_2.buffer[2] = stage_v_191_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int sub_step_192_1 = ((stage_v_153_1 + pub_r000213_12_1) + 29) & 127;
  int sub_step_192_2 = ((stage_v_153_2 + pub_r000213_12_2) + 29) & 127;
  int stage_v_192_1 = ((sub_step_192_1 * 2) + pub_r000213_14_1) & 127;
  int stage_v_192_2 = ((sub_step_192_2 * 2) + pub_r000213_14_2) & 127;
  st_var_0_1.buffer[0] = stage_v_192_1 & 15;
  st_var_0_2.buffer[0] = stage_v_192_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int sub_step_193_1 = ((sec_r000213_17_1 + pub_r000213_10_1) + 5) & 127;
  int sub_step_193_2 = ((sec_r000213_17_2 + pub_r000213_10_2) + 5) & 127;
  int stage_v_193_1 = ((sub_step_193_1 * 2) + pub_r000213_3_1) & 127;
  int stage_v_193_2 = ((sub_step_193_2 * 2) + pub_r000213_3_2) & 127;
  st_var_1_1.buffer[1] = stage_v_193_1 & 15;
  st_var_1_2.buffer[1] = stage_v_193_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int sub_step_194_1 = ((stage_v_143_1 + pub_r000213_19_1) + 9) & 127;
  int sub_step_194_2 = ((stage_v_143_2 + pub_r000213_19_2) + 9) & 127;
  int stage_v_194_1 = ((sub_step_194_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_194_2 = ((sub_step_194_2 * 2) + pub_r000213_7_2) & 127;
  st_var_2_1.buffer[2] = stage_v_194_1 & 15;
  st_var_2_2.buffer[2] = stage_v_194_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int sub_step_195_1 = ((sec_r000213_11_1 + pub_r000213_15_1) + 19) & 127;
  int sub_step_195_2 = ((sec_r000213_11_2 + pub_r000213_15_2) + 19) & 127;
  int stage_v_195_1 = ((sub_step_195_1 * 2) + pub_r000213_19_1) & 127;
  int stage_v_195_2 = ((sub_step_195_2 * 2) + pub_r000213_19_2) & 127;
  st_var_3_1.buffer[0] = stage_v_195_1 & 15;
  st_var_3_2.buffer[0] = stage_v_195_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int sub_step_196_1 = ((sub_step_119_1 + pub_r000213_16_1) + 27) & 127;
  int sub_step_196_2 = ((sub_step_119_2 + pub_r000213_16_2) + 27) & 127;
  int stage_v_196_1 = ((sub_step_196_1 * 2) + pub_r000213_0_1) & 127;
  int stage_v_196_2 = ((sub_step_196_2 * 2) + pub_r000213_0_2) & 127;
  st_var_0_1.buffer[1] = stage_v_196_1 & 15;
  st_var_0_2.buffer[1] = stage_v_196_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int sub_step_197_1 = ((sub_step_98_1 + pub_r000213_13_1) + 26) & 127;
  int sub_step_197_2 = ((sub_step_98_2 + pub_r000213_13_2) + 26) & 127;
  int stage_v_197_1 = ((sub_step_197_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_197_2 = ((sub_step_197_2 * 2) + pub_r000213_6_2) & 127;
  st_var_1_1.buffer[2] = stage_v_197_1 & 15;
  st_var_1_2.buffer[2] = stage_v_197_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int sub_step_198_1 = ((sec_r000213_16_1 + pub_r000213_6_1) + 24) & 127;
  int sub_step_198_2 = ((sec_r000213_16_2 + pub_r000213_6_2) + 24) & 127;
  int stage_v_198_1 = ((sub_step_198_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_198_2 = ((sub_step_198_2 * 2) + pub_r000213_8_2) & 127;
  st_var_2_1.buffer[0] = stage_v_198_1 & 15;
  st_var_2_2.buffer[0] = stage_v_198_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int sub_step_199_1 = ((stage_v_191_1 + pub_r000213_0_1) + 9) & 127;
  int sub_step_199_2 = ((stage_v_191_2 + pub_r000213_0_2) + 9) & 127;
  int stage_v_199_1 = ((sub_step_199_1 * 2) + pub_r000213_3_1) & 127;
  int stage_v_199_2 = ((sub_step_199_2 * 2) + pub_r000213_3_2) & 127;
  st_var_3_1.buffer[1] = stage_v_199_1 & 15;
  st_var_3_2.buffer[1] = stage_v_199_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int sub_step_200_1 = ((sub_step_169_1 + pub_r000213_8_1) + 34) & 127;
  int sub_step_200_2 = ((sub_step_169_2 + pub_r000213_8_2) + 34) & 127;
  int stage_v_200_1 = ((sub_step_200_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_200_2 = ((sub_step_200_2 * 2) + pub_r000213_12_2) & 127;
  st_var_0_1.buffer[2] = stage_v_200_1 & 15;
  st_var_0_2.buffer[2] = stage_v_200_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int sub_step_201_1 = ((sec_r000213_0_1 + pub_r000213_1_1) + 6) & 127;
  int sub_step_201_2 = ((sec_r000213_0_2 + pub_r000213_1_2) + 6) & 127;
  int stage_v_201_1 = ((sub_step_201_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_201_2 = ((sub_step_201_2 * 2) + pub_r000213_17_2) & 127;
  st_var_1_1.buffer[0] = stage_v_201_1 & 15;
  st_var_1_2.buffer[0] = stage_v_201_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int sub_step_202_1 = ((sub_step_99_1 + pub_r000213_14_1) + 6) & 127;
  int sub_step_202_2 = ((sub_step_99_2 + pub_r000213_14_2) + 6) & 127;
  int stage_v_202_1 = ((sub_step_202_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_202_2 = ((sub_step_202_2 * 2) + pub_r000213_6_2) & 127;
  st_var_2_1.buffer[1] = stage_v_202_1 & 15;
  st_var_2_2.buffer[1] = stage_v_202_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int sub_step_203_1 = ((stage_v_115_1 + pub_r000213_4_1) + 30) & 127;
  int sub_step_203_2 = ((stage_v_115_2 + pub_r000213_4_2) + 30) & 127;
  int stage_v_203_1 = ((sub_step_203_1 * 2) + pub_r000213_7_1) & 127;
  int stage_v_203_2 = ((sub_step_203_2 * 2) + pub_r000213_7_2) & 127;
  st_var_3_1.buffer[2] = stage_v_203_1 & 15;
  st_var_3_2.buffer[2] = stage_v_203_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int sub_step_204_1 = ((sec_r000213_2_1 + pub_r000213_16_1) + 10) & 127;
  int sub_step_204_2 = ((sec_r000213_2_2 + pub_r000213_16_2) + 10) & 127;
  int stage_v_204_1 = ((sub_step_204_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_204_2 = ((sub_step_204_2 * 2) + pub_r000213_12_2) & 127;
  st_var_0_1.buffer[0] = stage_v_204_1 & 15;
  st_var_0_2.buffer[0] = stage_v_204_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int sub_step_205_1 = ((sec_r000213_5_1 + pub_r000213_4_1) + 28) & 127;
  int sub_step_205_2 = ((sec_r000213_5_2 + pub_r000213_4_2) + 28) & 127;
  int stage_v_205_1 = ((sub_step_205_1 * 2) + pub_r000213_14_1) & 127;
  int stage_v_205_2 = ((sub_step_205_2 * 2) + pub_r000213_14_2) & 127;
  st_var_1_1.buffer[1] = stage_v_205_1 & 15;
  st_var_1_2.buffer[1] = stage_v_205_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int sub_step_206_1 = ((sub_step_198_1 + pub_r000213_8_1) + 22) & 127;
  int sub_step_206_2 = ((sub_step_198_2 + pub_r000213_8_2) + 22) & 127;
  int stage_v_206_1 = ((sub_step_206_1 * 2) + pub_r000213_5_1) & 127;
  int stage_v_206_2 = ((sub_step_206_2 * 2) + pub_r000213_5_2) & 127;
  st_var_2_1.buffer[2] = stage_v_206_1 & 15;
  st_var_2_2.buffer[2] = stage_v_206_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int sub_step_207_1 = ((stage_v_181_1 + pub_r000213_8_1) + 34) & 127;
  int sub_step_207_2 = ((stage_v_181_2 + pub_r000213_8_2) + 34) & 127;
  int stage_v_207_1 = ((sub_step_207_1 * 2) + pub_r000213_5_1) & 127;
  int stage_v_207_2 = ((sub_step_207_2 * 2) + pub_r000213_5_2) & 127;
  st_var_3_1.buffer[0] = stage_v_207_1 & 15;
  st_var_3_2.buffer[0] = stage_v_207_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int sub_step_208_1 = ((stage_v_189_1 + pub_r000213_5_1) + 14) & 127;
  int sub_step_208_2 = ((stage_v_189_2 + pub_r000213_5_2) + 14) & 127;
  int stage_v_208_1 = ((sub_step_208_1 * 2) + pub_r000213_17_1) & 127;
  int stage_v_208_2 = ((sub_step_208_2 * 2) + pub_r000213_17_2) & 127;
  st_var_0_1.buffer[1] = stage_v_208_1 & 15;
  st_var_0_2.buffer[1] = stage_v_208_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int sub_step_209_1 = ((sec_r000213_17_1 + pub_r000213_13_1) + 9) & 127;
  int sub_step_209_2 = ((sec_r000213_17_2 + pub_r000213_13_2) + 9) & 127;
  int stage_v_209_1 = ((sub_step_209_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_209_2 = ((sub_step_209_2 * 2) + pub_r000213_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_209_1 & 15;
  st_var_1_2.buffer[2] = stage_v_209_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int sub_step_210_1 = ((sec_r000213_10_1 + pub_r000213_1_1) + 25) & 127;
  int sub_step_210_2 = ((sec_r000213_10_2 + pub_r000213_1_2) + 25) & 127;
  int stage_v_210_1 = ((sub_step_210_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_210_2 = ((sub_step_210_2 * 2) + pub_r000213_1_2) & 127;
  st_var_2_1.buffer[0] = stage_v_210_1 & 15;
  st_var_2_2.buffer[0] = stage_v_210_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int sub_step_211_1 = ((sec_r000213_10_1 + pub_r000213_11_1) + 10) & 127;
  int sub_step_211_2 = ((sec_r000213_10_2 + pub_r000213_11_2) + 10) & 127;
  int stage_v_211_1 = ((sub_step_211_1 * 2) + pub_r000213_12_1) & 127;
  int stage_v_211_2 = ((sub_step_211_2 * 2) + pub_r000213_12_2) & 127;
  st_var_3_1.buffer[1] = stage_v_211_1 & 15;
  st_var_3_2.buffer[1] = stage_v_211_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int sub_step_212_1 = ((stage_v_108_1 + pub_r000213_7_1) + 8) & 127;
  int sub_step_212_2 = ((stage_v_108_2 + pub_r000213_7_2) + 8) & 127;
  int stage_v_212_1 = ((sub_step_212_1 * 2) + pub_r000213_8_1) & 127;
  int stage_v_212_2 = ((sub_step_212_2 * 2) + pub_r000213_8_2) & 127;
  st_var_0_1.buffer[2] = stage_v_212_1 & 15;
  st_var_0_2.buffer[2] = stage_v_212_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int sub_step_213_1 = ((sub_step_124_1 + pub_r000213_16_1) + 19) & 127;
  int sub_step_213_2 = ((sub_step_124_2 + pub_r000213_16_2) + 19) & 127;
  int stage_v_213_1 = ((sub_step_213_1 * 2) + pub_r000213_16_1) & 127;
  int stage_v_213_2 = ((sub_step_213_2 * 2) + pub_r000213_16_2) & 127;
  st_var_1_1.buffer[0] = stage_v_213_1 & 15;
  st_var_1_2.buffer[0] = stage_v_213_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int sub_step_214_1 = ((stage_v_176_1 + pub_r000213_1_1) + 25) & 127;
  int sub_step_214_2 = ((stage_v_176_2 + pub_r000213_1_2) + 25) & 127;
  int stage_v_214_1 = ((sub_step_214_1 * 2) + pub_r000213_13_1) & 127;
  int stage_v_214_2 = ((sub_step_214_2 * 2) + pub_r000213_13_2) & 127;
  st_var_2_1.buffer[1] = stage_v_214_1 & 15;
  st_var_2_2.buffer[1] = stage_v_214_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int sub_step_215_1 = ((stage_v_181_1 + pub_r000213_0_1) + 7) & 127;
  int sub_step_215_2 = ((stage_v_181_2 + pub_r000213_0_2) + 7) & 127;
  int stage_v_215_1 = ((sub_step_215_1 * 2) + pub_r000213_9_1) & 127;
  int stage_v_215_2 = ((sub_step_215_2 * 2) + pub_r000213_9_2) & 127;
  st_var_3_1.buffer[2] = stage_v_215_1 & 15;
  st_var_3_2.buffer[2] = stage_v_215_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int sub_step_216_1 = ((stage_v_147_1 + pub_r000213_12_1) + 18) & 127;
  int sub_step_216_2 = ((stage_v_147_2 + pub_r000213_12_2) + 18) & 127;
  int stage_v_216_1 = ((sub_step_216_1 * 2) + pub_r000213_6_1) & 127;
  int stage_v_216_2 = ((sub_step_216_2 * 2) + pub_r000213_6_2) & 127;
  st_var_0_1.buffer[0] = stage_v_216_1 & 15;
  st_var_0_2.buffer[0] = stage_v_216_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int sub_step_217_1 = ((sec_r000213_18_1 + pub_r000213_0_1) + 8) & 127;
  int sub_step_217_2 = ((sec_r000213_18_2 + pub_r000213_0_2) + 8) & 127;
  int stage_v_217_1 = ((sub_step_217_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_217_2 = ((sub_step_217_2 * 2) + pub_r000213_2_2) & 127;
  st_var_1_1.buffer[1] = stage_v_217_1 & 15;
  st_var_1_2.buffer[1] = stage_v_217_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int sub_step_218_1 = ((stage_v_205_1 + pub_r000213_19_1) + 12) & 127;
  int sub_step_218_2 = ((stage_v_205_2 + pub_r000213_19_2) + 12) & 127;
  int stage_v_218_1 = ((sub_step_218_1 * 2) + pub_r000213_1_1) & 127;
  int stage_v_218_2 = ((sub_step_218_2 * 2) + pub_r000213_1_2) & 127;
  st_var_2_1.buffer[2] = stage_v_218_1 & 15;
  st_var_2_2.buffer[2] = stage_v_218_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int sub_step_219_1 = ((sec_r000213_13_1 + pub_r000213_2_1) + 19) & 127;
  int sub_step_219_2 = ((sec_r000213_13_2 + pub_r000213_2_2) + 19) & 127;
  int stage_v_219_1 = ((sub_step_219_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_219_2 = ((sub_step_219_2 * 2) + pub_r000213_4_2) & 127;
  st_var_3_1.buffer[0] = stage_v_219_1 & 15;
  st_var_3_2.buffer[0] = stage_v_219_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int sub_step_220_1 = ((sub_step_101_1 + pub_r000213_5_1) + 35) & 127;
  int sub_step_220_2 = ((sub_step_101_2 + pub_r000213_5_2) + 35) & 127;
  int stage_v_220_1 = ((sub_step_220_1 * 2) + pub_r000213_18_1) & 127;
  int stage_v_220_2 = ((sub_step_220_2 * 2) + pub_r000213_18_2) & 127;
  st_var_0_1.buffer[1] = stage_v_220_1 & 15;
  st_var_0_2.buffer[1] = stage_v_220_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int sub_step_221_1 = ((sub_step_185_1 + pub_r000213_1_1) + 28) & 127;
  int sub_step_221_2 = ((sub_step_185_2 + pub_r000213_1_2) + 28) & 127;
  int stage_v_221_1 = ((sub_step_221_1 * 2) + pub_r000213_4_1) & 127;
  int stage_v_221_2 = ((sub_step_221_2 * 2) + pub_r000213_4_2) & 127;
  st_var_1_1.buffer[2] = stage_v_221_1 & 15;
  st_var_1_2.buffer[2] = stage_v_221_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int sub_step_222_1 = ((sub_step_110_1 + pub_r000213_19_1) + 22) & 127;
  int sub_step_222_2 = ((sub_step_110_2 + pub_r000213_19_2) + 22) & 127;
  int stage_v_222_1 = ((sub_step_222_1 * 2) + pub_r000213_0_1) & 127;
  int stage_v_222_2 = ((sub_step_222_2 * 2) + pub_r000213_0_2) & 127;
  st_var_2_1.buffer[0] = stage_v_222_1 & 15;
  st_var_2_2.buffer[0] = stage_v_222_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int sub_step_223_1 = ((sec_r000213_15_1 + pub_r000213_12_1) + 19) & 127;
  int sub_step_223_2 = ((sec_r000213_15_2 + pub_r000213_12_2) + 19) & 127;
  int stage_v_223_1 = ((sub_step_223_1 * 2) + pub_r000213_15_1) & 127;
  int stage_v_223_2 = ((sub_step_223_2 * 2) + pub_r000213_15_2) & 127;
  st_var_3_1.buffer[1] = stage_v_223_1 & 15;
  st_var_3_2.buffer[1] = stage_v_223_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int sub_step_224_1 = ((sec_r000213_0_1 + pub_r000213_3_1) + 11) & 127;
  int sub_step_224_2 = ((sec_r000213_0_2 + pub_r000213_3_2) + 11) & 127;
  int stage_v_224_1 = ((sub_step_224_1 * 2) + pub_r000213_5_1) & 127;
  int stage_v_224_2 = ((sub_step_224_2 * 2) + pub_r000213_5_2) & 127;
  st_var_0_1.buffer[2] = stage_v_224_1 & 15;
  st_var_0_2.buffer[2] = stage_v_224_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int sub_step_225_1 = ((sub_step_108_1 + pub_r000213_7_1) + 34) & 127;
  int sub_step_225_2 = ((sub_step_108_2 + pub_r000213_7_2) + 34) & 127;
  int stage_v_225_1 = ((sub_step_225_1 * 2) + pub_r000213_2_1) & 127;
  int stage_v_225_2 = ((sub_step_225_2 * 2) + pub_r000213_2_2) & 127;
  st_var_1_1.buffer[0] = stage_v_225_1 & 15;
  st_var_1_2.buffer[0] = stage_v_225_2 & 15;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000213_13_1 == pub_r000213_13_2);
  __CPROVER_assume(pub_r000213_3_1 == pub_r000213_3_2);
  __CPROVER_assume(sec_r000213_8_1 != sec_r000213_8_2);
  __CPROVER_assume(pub_r000213_17_1 == pub_r000213_17_2);
  __CPROVER_assume(sec_r000213_11_1 != sec_r000213_11_2);
  __CPROVER_assume(pub_r000213_18_1 == pub_r000213_18_2);
  __CPROVER_assume(pub_r000213_15_1 == pub_r000213_15_2);
  __CPROVER_assume(sec_r000213_12_1 != sec_r000213_12_2);
  __CPROVER_assume(sec_r000213_18_1 != sec_r000213_18_2);
  __CPROVER_assume(sec_r000213_4_1 != sec_r000213_4_2);
  __CPROVER_assume(sec_r000213_16_1 != sec_r000213_16_2);
  __CPROVER_assume(pub_r000213_9_1 == pub_r000213_9_2);
  __CPROVER_assume(sec_r000213_7_1 != sec_r000213_7_2);
  __CPROVER_assume(pub_r000213_8_1 == pub_r000213_8_2);
  __CPROVER_assume(sec_r000213_3_1 != sec_r000213_3_2);
  __CPROVER_assume(sec_r000213_15_1 != sec_r000213_15_2);
  __CPROVER_assume(sec_r000213_14_1 != sec_r000213_14_2);
  __CPROVER_assume(pub_r000213_2_1 == pub_r000213_2_2);
  __CPROVER_assume(sec_r000213_9_1 != sec_r000213_9_2);
  __CPROVER_assume(pub_r000213_14_1 == pub_r000213_14_2);
  __CPROVER_assume(sec_r000213_0_1 != sec_r000213_0_2);
  __CPROVER_assume(pub_r000213_6_1 == pub_r000213_6_2);
  __CPROVER_assume(sec_r000213_17_1 != sec_r000213_17_2);
  __CPROVER_assume(pub_r000213_19_1 == pub_r000213_19_2);
  __CPROVER_assume(pub_r000213_10_1 == pub_r000213_10_2);
  __CPROVER_assume(sec_r000213_1_1 != sec_r000213_1_2);
  __CPROVER_assume(pub_r000213_4_1 == pub_r000213_4_2);
  __CPROVER_assume(sec_r000213_13_1 != sec_r000213_13_2);
  __CPROVER_assume(sec_r000213_5_1 != sec_r000213_5_2);
  __CPROVER_assume(sec_r000213_2_1 != sec_r000213_2_2);
  __CPROVER_assume(pub_r000213_1_1 == pub_r000213_1_2);
  __CPROVER_assume(pub_r000213_5_1 == pub_r000213_5_2);
  __CPROVER_assume(sec_r000213_6_1 != sec_r000213_6_2);
  __CPROVER_assume(pub_r000213_7_1 == pub_r000213_7_2);
  __CPROVER_assume(pub_r000213_12_1 == pub_r000213_12_2);
  __CPROVER_assume(sec_r000213_10_1 != sec_r000213_10_2);
  __CPROVER_assume(pub_r000213_0_1 == pub_r000213_0_2);
  __CPROVER_assume(pub_r000213_11_1 == pub_r000213_11_2);
  __CPROVER_assume(pub_r000213_16_1 == pub_r000213_16_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.code == st_var_0_2.code);
  assert(st_var_0_1.timestamp == st_var_0_2.timestamp);
  assert(st_var_0_1.signature == st_var_0_2.signature);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.tail == st_var_2_2.tail);
  assert(st_var_2_1.checksum == st_var_2_2.checksum);
  assert(st_var_2_1.watermark == st_var_2_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.density == st_var_3_2.density);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.trace == st_var_3_2.trace);
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
  assert(sub_step_90_1 == sub_step_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(sub_step_91_1 == sub_step_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(sub_step_92_1 == sub_step_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(sub_step_93_1 == sub_step_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(sub_step_94_1 == sub_step_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(sub_step_95_1 == sub_step_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(sub_step_96_1 == sub_step_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(sub_step_97_1 == sub_step_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(sub_step_98_1 == sub_step_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(sub_step_99_1 == sub_step_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(sub_step_100_1 == sub_step_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(sub_step_101_1 == sub_step_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(sub_step_102_1 == sub_step_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(sub_step_103_1 == sub_step_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(sub_step_104_1 == sub_step_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(sub_step_105_1 == sub_step_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(sub_step_106_1 == sub_step_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(sub_step_107_1 == sub_step_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(sub_step_108_1 == sub_step_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(sub_step_109_1 == sub_step_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(sub_step_110_1 == sub_step_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(sub_step_111_1 == sub_step_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(sub_step_112_1 == sub_step_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(sub_step_113_1 == sub_step_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(sub_step_114_1 == sub_step_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(sub_step_115_1 == sub_step_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(sub_step_116_1 == sub_step_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(sub_step_117_1 == sub_step_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(sub_step_118_1 == sub_step_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(sub_step_119_1 == sub_step_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(sub_step_120_1 == sub_step_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(sub_step_121_1 == sub_step_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(sub_step_122_1 == sub_step_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(sub_step_123_1 == sub_step_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(sub_step_124_1 == sub_step_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(sub_step_125_1 == sub_step_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(sub_step_126_1 == sub_step_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(sub_step_127_1 == sub_step_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(sub_step_128_1 == sub_step_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(sub_step_129_1 == sub_step_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(sub_step_130_1 == sub_step_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(sub_step_131_1 == sub_step_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(sub_step_132_1 == sub_step_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(sub_step_133_1 == sub_step_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(sub_step_134_1 == sub_step_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(sub_step_135_1 == sub_step_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(sub_step_136_1 == sub_step_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(sub_step_137_1 == sub_step_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(sub_step_138_1 == sub_step_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(sub_step_139_1 == sub_step_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(sub_step_140_1 == sub_step_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(sub_step_141_1 == sub_step_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(sub_step_142_1 == sub_step_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(sub_step_143_1 == sub_step_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(sub_step_144_1 == sub_step_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(sub_step_145_1 == sub_step_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(sub_step_146_1 == sub_step_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(sub_step_147_1 == sub_step_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(sub_step_148_1 == sub_step_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(sub_step_149_1 == sub_step_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(sub_step_150_1 == sub_step_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(sub_step_151_1 == sub_step_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(sub_step_152_1 == sub_step_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(sub_step_153_1 == sub_step_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(sub_step_154_1 == sub_step_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(sub_step_155_1 == sub_step_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(sub_step_156_1 == sub_step_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(sub_step_157_1 == sub_step_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(sub_step_158_1 == sub_step_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(sub_step_159_1 == sub_step_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(sub_step_160_1 == sub_step_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(sub_step_161_1 == sub_step_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(sub_step_162_1 == sub_step_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(sub_step_163_1 == sub_step_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(sub_step_164_1 == sub_step_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(sub_step_165_1 == sub_step_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(sub_step_166_1 == sub_step_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(sub_step_167_1 == sub_step_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(sub_step_168_1 == sub_step_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(sub_step_169_1 == sub_step_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(sub_step_170_1 == sub_step_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(sub_step_171_1 == sub_step_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(sub_step_172_1 == sub_step_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(sub_step_173_1 == sub_step_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(sub_step_174_1 == sub_step_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(sub_step_175_1 == sub_step_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(sub_step_176_1 == sub_step_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(sub_step_177_1 == sub_step_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(sub_step_178_1 == sub_step_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(sub_step_179_1 == sub_step_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(sub_step_180_1 == sub_step_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(sub_step_181_1 == sub_step_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(sub_step_182_1 == sub_step_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(sub_step_183_1 == sub_step_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(sub_step_184_1 == sub_step_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(sub_step_185_1 == sub_step_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(sub_step_186_1 == sub_step_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(sub_step_187_1 == sub_step_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(sub_step_188_1 == sub_step_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(sub_step_189_1 == sub_step_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(sub_step_190_1 == sub_step_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(sub_step_191_1 == sub_step_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(sub_step_192_1 == sub_step_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(sub_step_193_1 == sub_step_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(sub_step_194_1 == sub_step_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(sub_step_195_1 == sub_step_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(sub_step_196_1 == sub_step_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(sub_step_197_1 == sub_step_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(sub_step_198_1 == sub_step_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(sub_step_199_1 == sub_step_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(sub_step_200_1 == sub_step_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(sub_step_201_1 == sub_step_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(sub_step_202_1 == sub_step_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(sub_step_203_1 == sub_step_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(sub_step_204_1 == sub_step_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(sub_step_205_1 == sub_step_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(sub_step_206_1 == sub_step_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(sub_step_207_1 == sub_step_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(sub_step_208_1 == sub_step_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(sub_step_209_1 == sub_step_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(sub_step_210_1 == sub_step_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(sub_step_211_1 == sub_step_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(sub_step_212_1 == sub_step_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(sub_step_213_1 == sub_step_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(sub_step_214_1 == sub_step_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(sub_step_215_1 == sub_step_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(sub_step_216_1 == sub_step_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(sub_step_217_1 == sub_step_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(sub_step_218_1 == sub_step_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(sub_step_219_1 == sub_step_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(sub_step_220_1 == sub_step_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(sub_step_221_1 == sub_step_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(sub_step_222_1 == sub_step_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(sub_step_223_1 == sub_step_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(sub_step_224_1 == sub_step_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(sub_step_225_1 == sub_step_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
}


