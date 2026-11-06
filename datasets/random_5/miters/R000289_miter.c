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
struct MatrixBlock_R000289_8913_0
{
  short dim;
  int density;
  short scale;
  short trace;
  int buffer[3];
};
struct AudioFrame_R000289_8913_1
{
  unsigned char envelope;
  int rms;
  short sample_rate;
  int channels;
  int peak;
  int gain;
  int buffer[3];
};
struct Transaction_R000289_8913_2
{
  int account_id;
  unsigned char rate;
  short fee;
  int buffer[3];
};
struct SensorNode_R000289_8913_3
{
  unsigned char threshold;
  short offset;
  int status;
  int reading;
  int buffer[3];
};
union ColorPixel_R000289_8913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000289_8913_1
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
void fn_R000289_8913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_75_1 > 32)
  {
    acc_1 = ((acc_1 + (anchor_75_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_75_2 > 32)
  {
    acc_2 = ((acc_2 + (anchor_75_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int parity_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_60_1)
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

  switch (parity_60_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_75_1 == anchor_75_2);
  assert(parity_60_1 == parity_60_2);
}

int fn_R000289_8913_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_75 > 32)
  {
    acc = ((acc + (anchor_75 * 2)) + 5) & 127;
    aux ^= anchor_75 & 15;
  }
  else
  {
    acc = ((acc - anchor_75) + 11) & 127;
    aux += 3;
  }
  int parity_60 = (aux + st.buffer[1]) & 3;
  switch (parity_60)
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

void fn_R000289_8913_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_56_1 = local_arr_1[aux_1 % 3];
  int tally_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_56_1 == tally_56_2);
}

int fn_R000289_8913_1(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_56 = local_arr[aux % 3];
  acc = (acc + (tally_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_48_1) & 63;
  aux_2 = (aux_2 + stride_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_84_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_84_1 * 2)) + 5) & 127;
    aux_1 ^= metric_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_84_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_84_2 * 2)) + 5) & 127;
    aux_2 ^= metric_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_84_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_36_1 = local_arr_1[aux_1 % 3];
  int cursor_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_48_1 == stride_48_2);
  assert(metric_84_1 == metric_84_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_36_1 == cursor_36_2);
}

int fn_R000289_8913_2(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_48) & 63;
  acc ^= aux;
  int metric_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_84 > 16)
  {
    acc = ((acc + (metric_84 * 2)) + 5) & 127;
    aux ^= metric_84 & 15;
  }
  else
  {
    acc = ((acc - metric_84) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_36 = local_arr[aux % 3];
  acc = (acc + (cursor_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st_1 = {0};
  struct Transaction_R000289_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_10_1)
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

  switch (pivot_10_2)
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

  int index_reg_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_17_1) & 63;
  aux_2 = (aux_2 + index_reg_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_10_1 == pivot_10_2);
  assert(index_reg_17_1 == index_reg_17_2);
}

int fn_R000289_8913_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_10 = (aux + st.buffer[1]) & 3;
  switch (pivot_10)
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

  int index_reg_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000289_8913_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st_1 = {0};
  struct MatrixBlock_R000289_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
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
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_76_1 = local_arr_1[aux_1 % 3];
  int mask_76_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_76_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_76_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_49_1 == vector_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_76_1 == mask_76_2);
}

int fn_R000289_8913_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
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
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_76 = local_arr[aux % 3];
  acc = (acc + (mask_76 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st_1 = {0};
  struct Transaction_R000289_8913_2 st_2 = {0};
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
  int index_reg_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_10_1)
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

  switch (index_reg_10_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_85_1 = local_arr_1[aux_1 % 3];
  int index_reg_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_85_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_10_1 == index_reg_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_85_1 == index_reg_85_2);
}

int fn_R000289_8913_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_10 = (aux + st.buffer[1]) & 3;
  switch (index_reg_10)
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

  int local_arr[3] = {4, 9, 15};
  int index_reg_85 = local_arr[aux % 3];
  acc = (acc + (index_reg_85 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st_1 = {0};
  struct Transaction_R000289_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int checksum_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_20_1) & 63;
  aux_2 = (aux_2 + checksum_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_29_1 = local_arr_1[aux_1 % 3];
  int tally_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_29_2 * 2)) & 127;
  int damping_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_18_1)
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

  switch (damping_18_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_20_1 == checksum_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_29_1 == tally_29_2);
  assert(damping_18_1 == damping_18_2);
}

int fn_R000289_8913_6(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int checksum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int tally_29 = local_arr[aux % 3];
  acc = (acc + (tally_29 * 2)) & 127;
  int damping_18 = (aux + st.buffer[1]) & 3;
  switch (damping_18)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tracker_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_91_1) & 63;
  aux_2 = (aux_2 + tracker_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_59_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_59_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_59_1)
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

  switch (accumulator_59_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_91_1 == tracker_91_2);
  assert(accumulator_59_1 == accumulator_59_2);
}

int fn_R000289_8913_7(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tracker_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_59 = (aux + st.buffer[1]) & 3;
  switch (accumulator_59)
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

void fn_R000289_8913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st_1 = {0};
  struct Transaction_R000289_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_74_1) & 63;
  aux_2 = (aux_2 + phase_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_91_1)
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

  switch (tally_91_2)
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
  int bound_93_1 = local_arr_1[aux_1 % 3];
  int bound_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_74_1 == phase_74_2);
  assert(tally_91_1 == tally_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_93_1 == bound_93_2);
}

int fn_R000289_8913_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_74) & 63;
  acc ^= aux;
  int tally_91 = (aux + st.buffer[1]) & 3;
  switch (tally_91)
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
  int bound_93 = local_arr[aux % 3];
  acc = (acc + (bound_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int residue_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_50_1) & 63;
  aux_2 = (aux_2 + residue_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_67_1 > 15)
  {
    acc_1 = ((acc_1 + (cursor_67_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_67_2 > 15)
  {
    acc_2 = ((acc_2 + (cursor_67_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_96_1 = local_arr_1[aux_1 % 3];
  int coefficient_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_50_1 == residue_50_2);
  assert(cursor_67_1 == cursor_67_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_96_1 == coefficient_96_2);
}

int fn_R000289_8913_9(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int residue_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_50) & 63;
  acc ^= aux;
  int cursor_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_67 > 15)
  {
    acc = ((acc + (cursor_67 * 2)) + 5) & 127;
    aux ^= cursor_67 & 15;
  }
  else
  {
    acc = ((acc - cursor_67) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int coefficient_96 = local_arr[aux % 3];
  acc = (acc + (coefficient_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st_1 = {0};
  struct Transaction_R000289_8913_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_45_1 > 11)
  {
    acc_1 = ((acc_1 + (residue_45_1 * 2)) + 5) & 127;
    aux_1 ^= residue_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_45_2 > 11)
  {
    acc_2 = ((acc_2 + (residue_45_2 * 2)) + 5) & 127;
    aux_2 ^= residue_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_45_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_33_1 = local_arr_1[aux_1 % 3];
  int mask_33_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_33_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_33_2 * 2)) & 127;
  int threshold_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_81_1)
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

  switch (threshold_81_2)
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
  assert(st_1.account_id == st_2.account_id);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_45_1 == residue_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_33_1 == mask_33_2);
  assert(threshold_81_1 == threshold_81_2);
}

int fn_R000289_8913_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R000289_8913_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_45 > 11)
  {
    acc = ((acc + (residue_45 * 2)) + 5) & 127;
    aux ^= residue_45 & 15;
  }
  else
  {
    acc = ((acc - residue_45) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int mask_33 = local_arr[aux % 3];
  acc = (acc + (mask_33 * 2)) & 127;
  int threshold_81 = (aux + st.buffer[1]) & 3;
  switch (threshold_81)
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

void fn_R000289_8913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct AudioFrame_R000289_8913_1 st_1 = {0};
  struct AudioFrame_R000289_8913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int accumulator_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_65_1) & 63;
  aux_2 = (aux_2 + accumulator_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_44_1)
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

  switch (segment_44_2)
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
  int delta_90_1 = local_arr_1[aux_1 % 3];
  int delta_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_90_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.envelope == st_2.envelope);
  assert(st_1.rms == st_2.rms);
  assert(st_1.sample_rate == st_2.sample_rate);
  assert(st_1.channels == st_2.channels);
  assert(st_1.peak == st_2.peak);
  assert(st_1.gain == st_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
  assert(segment_44_1 == segment_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_90_1 == delta_90_2);
}

int fn_R000289_8913_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct AudioFrame_R000289_8913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int accumulator_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_65) & 63;
  acc ^= aux;
  int segment_44 = (aux + st.buffer[1]) & 3;
  switch (segment_44)
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
  int delta_90 = local_arr[aux % 3];
  acc = (acc + (delta_90 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000289_8913_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st_1 = {0};
  struct MatrixBlock_R000289_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int damping_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_18_1) & 63;
  aux_2 = (aux_2 + damping_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_13_1 = local_arr_1[aux_1 % 3];
  int sample_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_13_2 * 2)) & 127;
  int bound_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_76_1)
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

  switch (bound_76_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  assert(st_1.scale == st_2.scale);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_18_1 == damping_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_13_1 == sample_13_2);
  assert(bound_76_1 == bound_76_2);
}

int fn_R000289_8913_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int damping_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_18) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_13 = local_arr[aux % 3];
  acc = (acc + (sample_13 * 2)) & 127;
  int bound_76 = (aux + st.buffer[1]) & 3;
  switch (bound_76)
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

void fn_R000289_8913_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_60_1 > 40)
  {
    acc_1 = ((acc_1 + (mask_60_1 * 2)) + 5) & 127;
    aux_1 ^= mask_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_60_2 > 40)
  {
    acc_2 = ((acc_2 + (mask_60_2 * 2)) + 5) & 127;
    aux_2 ^= mask_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_91_1 = local_arr_1[aux_1 % 3];
  int margin_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_91_2 * 2)) & 127;
  int margin_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_81_1)
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

  switch (margin_81_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_60_1 == mask_60_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_91_1 == margin_91_2);
  assert(margin_81_1 == margin_81_2);
}

int fn_R000289_8913_13(int p0, int p1, int p2)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_60 > 40)
  {
    acc = ((acc + (mask_60 * 2)) + 5) & 127;
    aux ^= mask_60 & 15;
  }
  else
  {
    acc = ((acc - mask_60) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int margin_91 = local_arr[aux % 3];
  acc = (acc + (margin_91 * 2)) & 127;
  int margin_81 = (aux + st.buffer[1]) & 3;
  switch (margin_81)
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

void fn_R000289_8913_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st_1 = {0};
  struct MatrixBlock_R000289_8913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_70_1 = local_arr_1[aux_1 % 3];
  int phase_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_70_2 * 2)) & 127;
  int phase_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_57_1) & 63;
  aux_2 = (aux_2 + phase_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_29_1 > 20)
  {
    acc_1 = ((acc_1 + (metric_29_1 * 2)) + 5) & 127;
    aux_1 ^= metric_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_29_2 > 20)
  {
    acc_2 = ((acc_2 + (metric_29_2 * 2)) + 5) & 127;
    aux_2 ^= metric_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_29_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_66_1)
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

  switch (tracker_66_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
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

  assert(phase_70_1 == phase_70_2);
  assert(phase_57_1 == phase_57_2);
  assert(metric_29_1 == metric_29_2);
  assert(tracker_66_1 == tracker_66_2);
}

int fn_R000289_8913_14(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000289_8913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int phase_70 = local_arr[aux % 3];
  acc = (acc + (phase_70 * 2)) & 127;
  int phase_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_57) & 63;
  acc ^= aux;
  int metric_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_29 > 20)
  {
    acc = ((acc + (metric_29 * 2)) + 5) & 127;
    aux ^= metric_29 & 15;
  }
  else
  {
    acc = ((acc - metric_29) + 11) & 127;
    aux += 3;
  }
  int tracker_66 = (aux + st.buffer[1]) & 3;
  switch (tracker_66)
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

void fn_R000289_8913_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st_1 = {0};
  struct SensorNode_R000289_8913_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int cursor_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_68_1) & 63;
  aux_2 = (aux_2 + cursor_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_63_1 > 31)
  {
    acc_1 = ((acc_1 + (coefficient_63_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_63_2 > 31)
  {
    acc_2 = ((acc_2 + (coefficient_63_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_63_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int sample_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_32_1)
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

  switch (sample_32_2)
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
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_68_1 == cursor_68_2);
  assert(coefficient_63_1 == coefficient_63_2);
  assert(sample_32_1 == sample_32_2);
}

int fn_R000289_8913_15(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R000289_8913_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int cursor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_68) & 63;
  acc ^= aux;
  int coefficient_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_63 > 31)
  {
    acc = ((acc + (coefficient_63 * 2)) + 5) & 127;
    aux ^= coefficient_63 & 15;
  }
  else
  {
    acc = ((acc - coefficient_63) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int sample_32 = (aux + st.buffer[1]) & 3;
  switch (sample_32)
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
  int sec_r000289_0_1;
  int sec_r000289_0_2;
  int sec_r000289_1_1;
  int sec_r000289_1_2;
  int sec_r000289_2_1;
  int sec_r000289_2_2;
  int sec_r000289_3_1;
  int sec_r000289_3_2;
  int sec_r000289_4_1;
  int sec_r000289_4_2;
  int sec_r000289_5_1;
  int sec_r000289_5_2;
  int sec_r000289_6_1;
  int sec_r000289_6_2;
  int sec_r000289_7_1;
  int sec_r000289_7_2;
  int sec_r000289_8_1;
  int sec_r000289_8_2;
  int sec_r000289_9_1;
  int sec_r000289_9_2;
  int sec_r000289_10_1;
  int sec_r000289_10_2;
  int sec_r000289_11_1;
  int sec_r000289_11_2;
  int sec_r000289_12_1;
  int sec_r000289_12_2;
  int sec_r000289_13_1;
  int sec_r000289_13_2;
  int sec_r000289_14_1;
  int sec_r000289_14_2;
  int sec_r000289_15_1;
  int sec_r000289_15_2;
  int sec_r000289_16_1;
  int sec_r000289_16_2;
  int sec_r000289_17_1;
  int sec_r000289_17_2;
  int sec_r000289_18_1;
  int sec_r000289_18_2;
  int sec_r000289_19_1;
  int sec_r000289_19_2;
  int pub_r000289_0_1;
  int pub_r000289_0_2;
  int pub_r000289_1_1;
  int pub_r000289_1_2;
  int pub_r000289_2_1;
  int pub_r000289_2_2;
  int pub_r000289_3_1;
  int pub_r000289_3_2;
  int pub_r000289_4_1;
  int pub_r000289_4_2;
  int pub_r000289_5_1;
  int pub_r000289_5_2;
  int pub_r000289_6_1;
  int pub_r000289_6_2;
  int pub_r000289_7_1;
  int pub_r000289_7_2;
  int pub_r000289_8_1;
  int pub_r000289_8_2;
  int pub_r000289_9_1;
  int pub_r000289_9_2;
  int pub_r000289_10_1;
  int pub_r000289_10_2;
  int pub_r000289_11_1;
  int pub_r000289_11_2;
  int pub_r000289_12_1;
  int pub_r000289_12_2;
  int pub_r000289_13_1;
  int pub_r000289_13_2;
  int pub_r000289_14_1;
  int pub_r000289_14_2;
  int pub_r000289_15_1;
  int pub_r000289_15_2;
  int pub_r000289_16_1;
  int pub_r000289_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000289_0_1 >= (-100)) && (pub_r000289_0_1 <= 100));
  __CPROVER_assume((pub_r000289_0_2 >= (-100)) && (pub_r000289_0_2 <= 100));
  __CPROVER_assume((pub_r000289_1_1 >= (-100)) && (pub_r000289_1_1 <= 100));
  __CPROVER_assume((pub_r000289_1_2 >= (-100)) && (pub_r000289_1_2 <= 100));
  __CPROVER_assume((pub_r000289_2_1 >= (-100)) && (pub_r000289_2_1 <= 100));
  __CPROVER_assume((pub_r000289_2_2 >= (-100)) && (pub_r000289_2_2 <= 100));
  __CPROVER_assume((pub_r000289_3_1 >= (-100)) && (pub_r000289_3_1 <= 100));
  __CPROVER_assume((pub_r000289_3_2 >= (-100)) && (pub_r000289_3_2 <= 100));
  __CPROVER_assume((pub_r000289_4_1 >= (-100)) && (pub_r000289_4_1 <= 100));
  __CPROVER_assume((pub_r000289_4_2 >= (-100)) && (pub_r000289_4_2 <= 100));
  __CPROVER_assume((pub_r000289_5_1 >= (-100)) && (pub_r000289_5_1 <= 100));
  __CPROVER_assume((pub_r000289_5_2 >= (-100)) && (pub_r000289_5_2 <= 100));
  __CPROVER_assume((pub_r000289_6_1 >= (-100)) && (pub_r000289_6_1 <= 100));
  __CPROVER_assume((pub_r000289_6_2 >= (-100)) && (pub_r000289_6_2 <= 100));
  __CPROVER_assume((pub_r000289_7_1 >= (-100)) && (pub_r000289_7_1 <= 100));
  __CPROVER_assume((pub_r000289_7_2 >= (-100)) && (pub_r000289_7_2 <= 100));
  __CPROVER_assume((pub_r000289_8_1 >= (-100)) && (pub_r000289_8_1 <= 100));
  __CPROVER_assume((pub_r000289_8_2 >= (-100)) && (pub_r000289_8_2 <= 100));
  __CPROVER_assume((pub_r000289_9_1 >= (-100)) && (pub_r000289_9_1 <= 100));
  __CPROVER_assume((pub_r000289_9_2 >= (-100)) && (pub_r000289_9_2 <= 100));
  __CPROVER_assume((pub_r000289_10_1 >= (-100)) && (pub_r000289_10_1 <= 100));
  __CPROVER_assume((pub_r000289_10_2 >= (-100)) && (pub_r000289_10_2 <= 100));
  __CPROVER_assume((pub_r000289_11_1 >= (-100)) && (pub_r000289_11_1 <= 100));
  __CPROVER_assume((pub_r000289_11_2 >= (-100)) && (pub_r000289_11_2 <= 100));
  __CPROVER_assume((pub_r000289_12_1 >= (-100)) && (pub_r000289_12_1 <= 100));
  __CPROVER_assume((pub_r000289_12_2 >= (-100)) && (pub_r000289_12_2 <= 100));
  __CPROVER_assume((pub_r000289_13_1 >= (-100)) && (pub_r000289_13_1 <= 100));
  __CPROVER_assume((pub_r000289_13_2 >= (-100)) && (pub_r000289_13_2 <= 100));
  __CPROVER_assume((pub_r000289_14_1 >= (-100)) && (pub_r000289_14_1 <= 100));
  __CPROVER_assume((pub_r000289_14_2 >= (-100)) && (pub_r000289_14_2 <= 100));
  __CPROVER_assume((pub_r000289_15_1 >= (-100)) && (pub_r000289_15_1 <= 100));
  __CPROVER_assume((pub_r000289_15_2 >= (-100)) && (pub_r000289_15_2 <= 100));
  __CPROVER_assume((pub_r000289_16_1 >= (-100)) && (pub_r000289_16_1 <= 100));
  __CPROVER_assume((pub_r000289_16_2 >= (-100)) && (pub_r000289_16_2 <= 100));
  __CPROVER_assume((sec_r000289_0_1 >= 0) && (sec_r000289_0_1 <= 255));
  __CPROVER_assume((sec_r000289_0_2 >= 0) && (sec_r000289_0_2 <= 255));
  __CPROVER_assume((sec_r000289_1_1 >= 0) && (sec_r000289_1_1 <= 255));
  __CPROVER_assume((sec_r000289_1_2 >= 0) && (sec_r000289_1_2 <= 255));
  __CPROVER_assume((sec_r000289_2_1 >= 0) && (sec_r000289_2_1 <= 255));
  __CPROVER_assume((sec_r000289_2_2 >= 0) && (sec_r000289_2_2 <= 255));
  __CPROVER_assume((sec_r000289_3_1 >= 0) && (sec_r000289_3_1 <= 255));
  __CPROVER_assume((sec_r000289_3_2 >= 0) && (sec_r000289_3_2 <= 255));
  __CPROVER_assume((sec_r000289_4_1 >= 0) && (sec_r000289_4_1 <= 255));
  __CPROVER_assume((sec_r000289_4_2 >= 0) && (sec_r000289_4_2 <= 255));
  __CPROVER_assume((sec_r000289_5_1 >= 0) && (sec_r000289_5_1 <= 255));
  __CPROVER_assume((sec_r000289_5_2 >= 0) && (sec_r000289_5_2 <= 255));
  __CPROVER_assume((sec_r000289_6_1 >= 0) && (sec_r000289_6_1 <= 255));
  __CPROVER_assume((sec_r000289_6_2 >= 0) && (sec_r000289_6_2 <= 255));
  __CPROVER_assume((sec_r000289_7_1 >= 0) && (sec_r000289_7_1 <= 255));
  __CPROVER_assume((sec_r000289_7_2 >= 0) && (sec_r000289_7_2 <= 255));
  __CPROVER_assume((sec_r000289_8_1 >= 0) && (sec_r000289_8_1 <= 255));
  __CPROVER_assume((sec_r000289_8_2 >= 0) && (sec_r000289_8_2 <= 255));
  __CPROVER_assume((sec_r000289_9_1 >= 0) && (sec_r000289_9_1 <= 255));
  __CPROVER_assume((sec_r000289_9_2 >= 0) && (sec_r000289_9_2 <= 255));
  __CPROVER_assume((sec_r000289_10_1 >= 0) && (sec_r000289_10_1 <= 255));
  __CPROVER_assume((sec_r000289_10_2 >= 0) && (sec_r000289_10_2 <= 255));
  __CPROVER_assume((sec_r000289_11_1 >= 0) && (sec_r000289_11_1 <= 255));
  __CPROVER_assume((sec_r000289_11_2 >= 0) && (sec_r000289_11_2 <= 255));
  __CPROVER_assume((sec_r000289_12_1 >= 0) && (sec_r000289_12_1 <= 255));
  __CPROVER_assume((sec_r000289_12_2 >= 0) && (sec_r000289_12_2 <= 255));
  __CPROVER_assume((sec_r000289_13_1 >= 0) && (sec_r000289_13_1 <= 255));
  __CPROVER_assume((sec_r000289_13_2 >= 0) && (sec_r000289_13_2 <= 255));
  __CPROVER_assume((sec_r000289_14_1 >= 0) && (sec_r000289_14_1 <= 255));
  __CPROVER_assume((sec_r000289_14_2 >= 0) && (sec_r000289_14_2 <= 255));
  __CPROVER_assume((sec_r000289_15_1 >= 0) && (sec_r000289_15_1 <= 255));
  __CPROVER_assume((sec_r000289_15_2 >= 0) && (sec_r000289_15_2 <= 255));
  __CPROVER_assume((sec_r000289_16_1 >= 0) && (sec_r000289_16_1 <= 255));
  __CPROVER_assume((sec_r000289_16_2 >= 0) && (sec_r000289_16_2 <= 255));
  __CPROVER_assume((sec_r000289_17_1 >= 0) && (sec_r000289_17_1 <= 255));
  __CPROVER_assume((sec_r000289_17_2 >= 0) && (sec_r000289_17_2 <= 255));
  __CPROVER_assume((sec_r000289_18_1 >= 0) && (sec_r000289_18_1 <= 255));
  __CPROVER_assume((sec_r000289_18_2 >= 0) && (sec_r000289_18_2 <= 255));
  __CPROVER_assume((sec_r000289_19_1 >= 0) && (sec_r000289_19_1 <= 255));
  __CPROVER_assume((sec_r000289_19_2 >= 0) && (sec_r000289_19_2 <= 255));
  struct MatrixBlock_R000289_8913_0 st_var_0_1 = {0};
  struct MatrixBlock_R000289_8913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000289_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000289_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000289_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000289_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000289_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000289_0_2 + 7) & 15;
  struct AudioFrame_R000289_8913_1 st_var_1_1 = {0};
  struct AudioFrame_R000289_8913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000289_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000289_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000289_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000289_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000289_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000289_0_2 + 9) & 15;
  struct Transaction_R000289_8913_2 st_var_2_1 = {0};
  struct Transaction_R000289_8913_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000289_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000289_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000289_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000289_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000289_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000289_0_2 + 11) & 15;
  struct SensorNode_R000289_8913_3 st_var_3_1 = {0};
  struct SensorNode_R000289_8913_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000289_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000289_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000289_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000289_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000289_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000289_0_2 + 13) & 15;
  union ColorPixel_R000289_8913_0 u_var_1;
  union ColorPixel_R000289_8913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = 0;
  int stage_v_0_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_0_1 = ((stage_v_0_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_0_2 = ((stage_v_0_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (8 & 31);
  int stage_v_3_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (8 & 31);
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= (stage_v_3_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_3_2 << 1) & 127;
  int stage_v_4_1 = (st_var_0_1.buffer[0] ^ 7) & 3;
  int stage_v_4_2 = (st_var_0_2.buffer[0] ^ 7) & 3;
  switch (stage_v_4_1)
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

  switch (stage_v_4_2)
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

  int stage_v_5_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_5_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_5_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_5_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_6_1 = ((st_var_2_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_2_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 47)
    {
      chk_sum_1 ^= stage_v_6_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_6_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 47)
    {
      chk_sum_2 ^= stage_v_6_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 42)
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
  if (stage_v_7_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 42)
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
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 10) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 10) & 15;
  int stage_v_9_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_9_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  chk_sum_1 ^= stage_v_9_1;
  chk_sum_2 ^= stage_v_9_2;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (16 & 31);
  int stage_v_11_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (16 & 31);
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  chk_sum_1 ^= (stage_v_11_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_11_2 << 1) & 127;
  int stage_v_12_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_12_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_13_1 = ((st_var_1_1.buffer[1] * 2) + 46) & 63;
  int stage_v_13_2 = ((st_var_1_2.buffer[1] * 2) + 46) & 63;
  if (stage_v_13_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + stage_v_13_1) - 5) & 255;
    if (stage_v_13_1 > 30)
    {
      chk_sum_1 ^= stage_v_13_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_13_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_13_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + stage_v_13_2) - 5) & 255;
    if (stage_v_13_2 > 30)
    {
      chk_sum_2 ^= stage_v_13_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_13_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_14_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_14_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (st_var_2_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_2_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
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

  switch (stage_v_18_2)
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

  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (25 & 31);
  int stage_v_20_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (25 & 31);
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  chk_sum_1 ^= (stage_v_20_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_20_2 << 1) & 127;
  int stage_v_21_1 = table_1[1];
  int stage_v_21_2 = table_2[1];
  table_1[1] = (table_1[2] + 43) & 63;
  table_2[1] = (table_2[2] + 43) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = table_1[2];
  int stage_v_22_2 = table_2[2];
  table_1[2] = (table_1[3] + 45) & 63;
  table_2[2] = (table_2[3] + 45) & 63;
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  int stage_v_23_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_23_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_24_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_24_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_25_1 = (st_var_1_1.buffer[0] ^ 28) & 3;
  int stage_v_25_2 = (st_var_1_2.buffer[0] ^ 28) & 3;
  switch (stage_v_25_1)
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

  switch (stage_v_25_2)
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

  int stage_v_26_1 = ((st_var_2_1.buffer[2] * 2) + 85) & 63;
  int stage_v_26_2 = ((st_var_2_2.buffer[2] * 2) + 85) & 63;
  if (stage_v_26_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_26_1) - 5) & 255;
    if (stage_v_26_1 > 28)
    {
      chk_sum_1 ^= stage_v_26_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_26_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_26_2) - 5) & 255;
    if (stage_v_26_2 > 28)
    {
      chk_sum_2 ^= stage_v_26_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_27_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_27_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 37)
    {
      chk_sum_1 ^= stage_v_29_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_29_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 37)
    {
      chk_sum_2 ^= stage_v_29_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_30_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_30_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  int stage_v_32_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_32_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (41 & 31);
  int stage_v_36_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (41 & 31);
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  chk_sum_1 ^= (stage_v_36_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_36_2 << 1) & 127;
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 40) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 40) & 15;
  int stage_v_39_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_39_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  chk_sum_1 ^= stage_v_39_1;
  chk_sum_2 ^= stage_v_39_2;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 34)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 34)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_42_1 = ((stage_v_42_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_42_2 = ((stage_v_42_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = (st_var_3_1.buffer[0] ^ 46) & 3;
  int stage_v_43_2 = (st_var_3_2.buffer[0] ^ 46) & 3;
  switch (stage_v_43_1)
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

  switch (stage_v_43_2)
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

  int stage_v_44_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_44_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  st_var_2_1.buffer[1] = (st_var_2_1.buffer[1] + 47) & 15;
  st_var_2_2.buffer[1] = (st_var_2_2.buffer[1] + 47) & 15;
  int stage_v_46_1 = (st_var_2_1.buffer[1] * 3) & 63;
  int stage_v_46_2 = (st_var_2_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= stage_v_46_1;
  chk_sum_2 ^= stage_v_46_2;
  int stage_v_47_1 = table_1[3];
  int stage_v_47_2 = table_2[3];
  table_1[3] = (table_1[0] + 95) & 63;
  table_2[3] = (table_2[0] + 95) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  int stage_v_49_1 = ((st_var_1_1.buffer[1] * 2) + 154) & 63;
  int stage_v_49_2 = ((st_var_1_2.buffer[1] * 2) + 154) & 63;
  if (stage_v_49_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + stage_v_49_1) - 5) & 255;
    if (stage_v_49_1 > 36)
    {
      chk_sum_1 ^= stage_v_49_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_49_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + stage_v_49_2) - 5) & 255;
    if (stage_v_49_2 > 36)
    {
      chk_sum_2 ^= stage_v_49_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_51_1 = ((stage_v_51_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_51_2 = ((stage_v_51_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_52_1 = ((stage_v_52_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_52_2 = ((stage_v_52_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (58 & 31);
  int stage_v_53_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (58 & 31);
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  chk_sum_1 ^= (stage_v_53_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_53_2 << 1) & 127;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_55_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_56_1 = table_1[0];
  int stage_v_56_2 = table_2[0];
  table_1[0] = (table_1[1] + 113) & 63;
  table_2[0] = (table_2[1] + 113) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (st_var_2_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_2_2.buffer[0] ^ 61) & 3;
  switch (stage_v_58_1)
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

  switch (stage_v_58_2)
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

  int stage_v_59_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (64 & 31);
  int stage_v_59_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (64 & 31);
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  chk_sum_1 ^= (stage_v_59_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_59_2 << 1) & 127;
  int stage_v_60_1 = (st_var_0_1.buffer[0] ^ 63) & 3;
  int stage_v_60_2 = (st_var_0_2.buffer[0] ^ 63) & 3;
  switch (stage_v_60_1)
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

  switch (stage_v_60_2)
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

  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 62) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 62) & 15;
  int stage_v_61_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_61_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= stage_v_61_1;
  chk_sum_2 ^= stage_v_61_2;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_63_1 = ((stage_v_63_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_63_2 = ((stage_v_63_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 28)
    {
      chk_sum_1 ^= stage_v_64_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_64_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 28)
    {
      chk_sum_2 ^= stage_v_64_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_65_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_65_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  st_var_3_1.buffer[1] = (st_var_3_1.buffer[1] + 68) & 15;
  st_var_3_2.buffer[1] = (st_var_3_2.buffer[1] + 68) & 15;
  int stage_v_67_1 = (st_var_3_1.buffer[1] * 3) & 63;
  int stage_v_67_2 = (st_var_3_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  chk_sum_1 ^= stage_v_67_1;
  chk_sum_2 ^= stage_v_67_2;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 70) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 70) & 15;
  int stage_v_69_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_69_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  chk_sum_1 ^= stage_v_69_1;
  chk_sum_2 ^= stage_v_69_2;
  int stage_v_70_1 = table_1[2];
  int stage_v_70_2 = table_2[2];
  table_1[2] = (table_1[3] + 141) & 63;
  table_2[2] = (table_2[3] + 141) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_71_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_72_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_72_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_73_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_73_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_2_1.buffer[2] = (st_var_2_1.buffer[2] + 75) & 15;
  st_var_2_2.buffer[2] = (st_var_2_2.buffer[2] + 75) & 15;
  int stage_v_74_1 = (st_var_2_1.buffer[2] * 3) & 63;
  int stage_v_74_2 = (st_var_2_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  chk_sum_1 ^= stage_v_74_1;
  chk_sum_2 ^= stage_v_74_2;
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = sec_r000289_3_1 & 3;
  int s_idx_78_2 = sec_r000289_3_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000289_8_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = stage_v_78_1 & 3;
  int s_idx_79_2 = stage_v_78_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000289_10_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = sec_r000289_16_1 & 3;
  int s_idx_80_2 = sec_r000289_16_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000289_0_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = stage_v_80_1 & 3;
  int s_idx_81_2 = stage_v_80_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000289_16_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = stage_v_78_1 & 3;
  int s_idx_82_2 = stage_v_78_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000289_11_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = stage_v_81_1 & 3;
  int s_idx_83_2 = stage_v_81_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000289_5_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = stage_v_81_1 & 3;
  int s_idx_84_2 = stage_v_81_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000289_8_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = stage_v_83_1 & 3;
  int s_idx_85_2 = stage_v_83_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000289_13_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_80_1 & 3;
  int s_idx_86_2 = stage_v_80_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000289_12_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = sec_r000289_7_1 & 3;
  int s_idx_87_2 = sec_r000289_7_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000289_5_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = sec_r000289_16_1 & 3;
  int s_idx_88_2 = sec_r000289_16_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000289_12_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = stage_v_81_1 & 3;
  int s_idx_89_2 = stage_v_81_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000289_5_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = sec_r000289_6_1 & 3;
  int s_idx_90_2 = sec_r000289_6_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000289_9_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = stage_v_84_1 & 3;
  int s_idx_91_2 = stage_v_84_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000289_16_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = stage_v_79_1 & 3;
  int s_idx_92_2 = stage_v_79_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000289_12_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_82_1 & 3;
  int s_idx_93_2 = stage_v_82_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000289_4_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = stage_v_91_1 & 3;
  int s_idx_94_2 = stage_v_91_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000289_16_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = stage_v_83_1 & 3;
  int s_idx_95_2 = stage_v_83_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000289_10_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = stage_v_86_1 & 3;
  int s_idx_96_2 = stage_v_86_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000289_8_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_83_1 & 3;
  int s_idx_97_2 = stage_v_83_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000289_6_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = stage_v_90_1 & 3;
  int s_idx_98_2 = stage_v_90_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000289_9_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = sec_r000289_15_1 & 3;
  int s_idx_99_2 = sec_r000289_15_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000289_3_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = stage_v_81_1 & 3;
  int s_idx_100_2 = stage_v_81_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000289_9_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = stage_v_83_1 & 3;
  int s_idx_101_2 = stage_v_83_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000289_14_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = stage_v_80_1 & 3;
  int s_idx_102_2 = stage_v_80_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000289_12_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_101_1 & 3;
  int s_idx_103_2 = stage_v_101_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000289_10_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_96_1 & 3;
  int s_idx_104_2 = stage_v_96_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000289_16_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = sec_r000289_0_1 & 3;
  int s_idx_105_2 = sec_r000289_0_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000289_13_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_95_1 & 3;
  int s_idx_106_2 = stage_v_95_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000289_10_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = stage_v_98_1 & 3;
  int s_idx_107_2 = stage_v_98_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000289_0_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = stage_v_98_1 & 3;
  int s_idx_108_2 = stage_v_98_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000289_16_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = stage_v_106_1 & 3;
  int s_idx_109_2 = stage_v_106_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000289_1_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = sec_r000289_15_1 & 3;
  int s_idx_110_2 = sec_r000289_15_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000289_14_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_110_1 & 3;
  int s_idx_111_2 = stage_v_110_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000289_3_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = stage_v_79_1 & 3;
  int s_idx_112_2 = stage_v_79_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000289_1_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = stage_v_104_1 & 3;
  int s_idx_113_2 = stage_v_104_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000289_2_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = stage_v_102_1 & 3;
  int s_idx_114_2 = stage_v_102_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000289_15_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = sec_r000289_2_1 & 3;
  int s_idx_115_2 = sec_r000289_2_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000289_3_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_110_1 & 3;
  int s_idx_116_2 = stage_v_110_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000289_15_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = sec_r000289_11_1 & 3;
  int s_idx_117_2 = sec_r000289_11_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000289_2_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = sec_r000289_16_1 & 3;
  int s_idx_118_2 = sec_r000289_16_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000289_10_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = sec_r000289_0_1 & 3;
  int s_idx_119_2 = sec_r000289_0_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000289_15_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = stage_v_106_1 & 3;
  int s_idx_120_2 = stage_v_106_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000289_9_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = sec_r000289_11_1 & 3;
  int s_idx_121_2 = sec_r000289_11_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000289_5_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = stage_v_104_1 & 3;
  int s_idx_122_2 = stage_v_104_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000289_0_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = stage_v_78_1 & 3;
  int s_idx_123_2 = stage_v_78_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000289_11_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = stage_v_95_1 & 3;
  int s_idx_124_2 = stage_v_95_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000289_16_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_108_1 & 3;
  int s_idx_125_2 = stage_v_108_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000289_7_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = stage_v_112_1 & 3;
  int s_idx_126_2 = stage_v_112_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000289_8_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = stage_v_100_1 & 3;
  int s_idx_127_2 = stage_v_100_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000289_16_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = sec_r000289_6_1 & 3;
  int s_idx_128_2 = sec_r000289_6_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000289_12_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = sec_r000289_17_1 & 3;
  int s_idx_129_2 = sec_r000289_17_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000289_2_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000289_13_1 & 3;
  int s_idx_130_2 = sec_r000289_13_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000289_7_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = sec_r000289_16_1 & 3;
  int s_idx_131_2 = sec_r000289_16_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000289_13_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = sec_r000289_6_1 & 3;
  int s_idx_132_2 = sec_r000289_6_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000289_0_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = stage_v_124_1 & 3;
  int s_idx_133_2 = stage_v_124_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000289_2_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = stage_v_99_1 & 3;
  int s_idx_134_2 = stage_v_99_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000289_15_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = sec_r000289_5_1 & 3;
  int s_idx_135_2 = sec_r000289_5_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000289_14_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = stage_v_133_1 & 3;
  int s_idx_136_2 = stage_v_133_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000289_2_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_98_1 & 3;
  int s_idx_137_2 = stage_v_98_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000289_15_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = sec_r000289_15_1 & 3;
  int s_idx_138_2 = sec_r000289_15_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000289_9_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = sec_r000289_12_1 & 3;
  int s_idx_139_2 = sec_r000289_12_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000289_2_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = stage_v_129_1 & 3;
  int s_idx_140_2 = stage_v_129_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000289_8_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = sec_r000289_12_1 & 3;
  int s_idx_141_2 = sec_r000289_12_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000289_16_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = sec_r000289_12_1 & 3;
  int s_idx_142_2 = sec_r000289_12_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000289_7_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_134_1 & 3;
  int s_idx_143_2 = stage_v_134_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000289_11_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = stage_v_83_1 & 3;
  int s_idx_144_2 = stage_v_83_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000289_11_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = stage_v_141_1 & 3;
  int s_idx_145_2 = stage_v_141_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000289_9_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = sec_r000289_17_1 & 3;
  int s_idx_146_2 = sec_r000289_17_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000289_5_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = stage_v_144_1 & 3;
  int s_idx_147_2 = stage_v_144_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000289_16_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = sec_r000289_5_1 & 3;
  int s_idx_148_2 = sec_r000289_5_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000289_12_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = stage_v_93_1 & 3;
  int s_idx_149_2 = stage_v_93_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000289_7_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = stage_v_134_1 & 3;
  int s_idx_150_2 = stage_v_134_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000289_16_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = stage_v_142_1 & 3;
  int s_idx_151_2 = stage_v_142_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000289_11_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = stage_v_113_1 & 3;
  int s_idx_152_2 = stage_v_113_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000289_8_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = sec_r000289_0_1 & 3;
  int s_idx_153_2 = sec_r000289_0_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000289_0_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = stage_v_147_1 & 3;
  int s_idx_154_2 = stage_v_147_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000289_7_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000289_6_1 & 3;
  int s_idx_155_2 = sec_r000289_6_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000289_13_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = sec_r000289_0_1 & 3;
  int s_idx_156_2 = sec_r000289_0_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000289_13_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = stage_v_86_1 & 3;
  int s_idx_157_2 = stage_v_86_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000289_1_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = stage_v_96_1 & 3;
  int s_idx_158_2 = stage_v_96_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000289_7_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = stage_v_93_1 & 3;
  int s_idx_159_2 = stage_v_93_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000289_11_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = stage_v_93_1 & 3;
  int s_idx_160_2 = stage_v_93_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000289_7_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = stage_v_110_1 & 3;
  int s_idx_161_2 = stage_v_110_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000289_9_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = stage_v_100_1 & 3;
  int s_idx_162_2 = stage_v_100_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000289_0_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_147_1 & 3;
  int s_idx_163_2 = stage_v_147_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000289_13_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_83_1 & 3;
  int s_idx_164_2 = stage_v_83_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000289_7_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = sec_r000289_5_1 & 3;
  int s_idx_165_2 = sec_r000289_5_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000289_10_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = sec_r000289_3_1 & 3;
  int s_idx_166_2 = sec_r000289_3_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000289_0_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = sec_r000289_6_1 & 3;
  int s_idx_167_2 = sec_r000289_6_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000289_5_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = sec_r000289_11_1 & 3;
  int s_idx_168_2 = sec_r000289_11_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000289_7_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = stage_v_147_1 & 3;
  int s_idx_169_2 = stage_v_147_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000289_5_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = sec_r000289_1_1 & 3;
  int s_idx_170_2 = sec_r000289_1_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000289_15_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = sec_r000289_7_1 & 3;
  int s_idx_171_2 = sec_r000289_7_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000289_11_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = stage_v_161_1 & 3;
  int s_idx_172_2 = stage_v_161_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000289_0_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = sec_r000289_11_1 & 3;
  int s_idx_173_2 = sec_r000289_11_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000289_5_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = sec_r000289_18_1 & 3;
  int s_idx_174_2 = sec_r000289_18_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000289_12_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = stage_v_169_1 & 3;
  int s_idx_175_2 = stage_v_169_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000289_16_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = sec_r000289_3_1 & 3;
  int s_idx_176_2 = sec_r000289_3_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000289_9_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = stage_v_148_1 & 3;
  int s_idx_177_2 = stage_v_148_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000289_12_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_154_1 & 3;
  int s_idx_178_2 = stage_v_154_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000289_7_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = sec_r000289_17_1 & 3;
  int s_idx_179_2 = sec_r000289_17_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000289_5_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = stage_v_92_1 & 3;
  int s_idx_180_2 = stage_v_92_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000289_9_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = stage_v_114_1 & 3;
  int s_idx_181_2 = stage_v_114_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000289_15_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = stage_v_136_1 & 3;
  int s_idx_182_2 = stage_v_136_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000289_0_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_144_1 & 3;
  int s_idx_183_2 = stage_v_144_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000289_4_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = sec_r000289_2_1 & 3;
  int s_idx_184_2 = sec_r000289_2_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000289_15_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_183_1 & 3;
  int s_idx_185_2 = stage_v_183_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000289_10_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_134_1 & 3;
  int s_idx_186_2 = stage_v_134_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000289_14_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = stage_v_98_1 & 3;
  int s_idx_187_2 = stage_v_98_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000289_16_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = stage_v_87_1 & 3;
  int s_idx_188_2 = stage_v_87_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000289_5_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = sec_r000289_8_1 & 3;
  int s_idx_189_2 = sec_r000289_8_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000289_1_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = stage_v_85_1 & 3;
  int s_idx_190_2 = stage_v_85_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000289_1_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = sec_r000289_5_1 & 3;
  int s_idx_191_2 = sec_r000289_5_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000289_2_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = sec_r000289_8_1 & 3;
  int s_idx_192_2 = sec_r000289_8_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000289_4_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = stage_v_165_1 & 3;
  int s_idx_193_2 = stage_v_165_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000289_15_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = sec_r000289_14_1 & 3;
  int s_idx_194_2 = sec_r000289_14_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000289_7_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = stage_v_130_1 & 3;
  int s_idx_195_2 = stage_v_130_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000289_14_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = stage_v_146_1 & 3;
  int s_idx_196_2 = stage_v_146_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000289_8_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = sec_r000289_0_1 & 3;
  int s_idx_197_2 = sec_r000289_0_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000289_2_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = stage_v_83_1 & 3;
  int s_idx_198_2 = stage_v_83_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000289_6_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = stage_v_128_1 & 3;
  int s_idx_199_2 = stage_v_128_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000289_5_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_117_1 & 3;
  int s_idx_200_2 = stage_v_117_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000289_12_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = stage_v_156_1 & 3;
  int s_idx_201_2 = stage_v_156_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000289_9_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_201_1 & 3;
  int s_idx_202_2 = stage_v_201_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000289_8_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = sec_r000289_17_1 & 3;
  int s_idx_203_2 = sec_r000289_17_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000289_10_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = stage_v_136_1 & 3;
  int s_idx_204_2 = stage_v_136_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000289_3_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = stage_v_91_1 & 3;
  int s_idx_205_2 = stage_v_91_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000289_15_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = stage_v_136_1 & 3;
  int s_idx_206_2 = stage_v_136_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000289_8_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = stage_v_82_1 & 3;
  int s_idx_207_2 = stage_v_82_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000289_13_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_180_1 & 3;
  int s_idx_208_2 = stage_v_180_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000289_8_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = sec_r000289_6_1 & 3;
  int s_idx_209_2 = sec_r000289_6_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000289_9_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_104_1 & 3;
  int s_idx_210_2 = stage_v_104_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000289_5_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = sec_r000289_6_1 & 3;
  int s_idx_211_2 = sec_r000289_6_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000289_14_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = stage_v_79_1 & 3;
  int s_idx_212_2 = stage_v_79_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000289_3_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = sec_r000289_3_1 & 3;
  int s_idx_213_2 = sec_r000289_3_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000289_9_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = stage_v_143_1 & 3;
  int s_idx_214_2 = stage_v_143_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000289_3_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = stage_v_85_1 & 3;
  int s_idx_215_2 = stage_v_85_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000289_8_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = stage_v_131_1 & 3;
  int s_idx_216_2 = stage_v_131_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000289_12_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = sec_r000289_17_1 & 3;
  int s_idx_217_2 = sec_r000289_17_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000289_11_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = sec_r000289_10_1 & 3;
  int s_idx_218_2 = sec_r000289_10_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000289_4_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = stage_v_87_1 & 3;
  int s_idx_219_2 = stage_v_87_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000289_15_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = sec_r000289_3_1 & 3;
  int s_idx_220_2 = sec_r000289_3_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000289_2_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_156_1 & 3;
  int s_idx_221_2 = stage_v_156_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000289_0_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = stage_v_81_1 & 3;
  int s_idx_222_2 = stage_v_81_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000289_12_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = sec_r000289_13_1 & 3;
  int s_idx_223_2 = sec_r000289_13_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000289_2_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = stage_v_82_1 & 3;
  int s_idx_224_2 = stage_v_82_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000289_4_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = stage_v_164_1 & 3;
  int s_idx_225_2 = stage_v_164_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000289_6_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = sec_r000289_16_1 & 3;
  int s_idx_226_2 = sec_r000289_16_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000289_14_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = stage_v_212_1 & 3;
  int s_idx_227_2 = stage_v_212_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000289_2_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int s_idx_228_1 = stage_v_200_1 & 3;
  int s_idx_228_2 = stage_v_200_2 & 3;
  int stage_v_228_1 = (table_1[s_idx_228_1] + pub_r000289_13_1) & 127;
  int stage_v_228_2 = (table_2[s_idx_228_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_228_1] = (stage_v_228_1 + 7) & 63;
  table_2[s_idx_228_2] = (stage_v_228_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int s_idx_229_1 = stage_v_94_1 & 3;
  int s_idx_229_2 = stage_v_94_2 & 3;
  int stage_v_229_1 = (table_1[s_idx_229_1] + pub_r000289_10_1) & 127;
  int stage_v_229_2 = (table_2[s_idx_229_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_229_1] = (stage_v_229_1 + 7) & 63;
  table_2[s_idx_229_2] = (stage_v_229_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int s_idx_230_1 = stage_v_213_1 & 3;
  int s_idx_230_2 = stage_v_213_2 & 3;
  int stage_v_230_1 = (table_1[s_idx_230_1] + pub_r000289_11_1) & 127;
  int stage_v_230_2 = (table_2[s_idx_230_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_230_1] = (stage_v_230_1 + 7) & 63;
  table_2[s_idx_230_2] = (stage_v_230_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int s_idx_231_1 = stage_v_184_1 & 3;
  int s_idx_231_2 = stage_v_184_2 & 3;
  int stage_v_231_1 = (table_1[s_idx_231_1] + pub_r000289_5_1) & 127;
  int stage_v_231_2 = (table_2[s_idx_231_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_231_1] = (stage_v_231_1 + 7) & 63;
  table_2[s_idx_231_2] = (stage_v_231_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int s_idx_232_1 = sec_r000289_10_1 & 3;
  int s_idx_232_2 = sec_r000289_10_2 & 3;
  int stage_v_232_1 = (table_1[s_idx_232_1] + pub_r000289_9_1) & 127;
  int stage_v_232_2 = (table_2[s_idx_232_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_232_1] = (stage_v_232_1 + 7) & 63;
  table_2[s_idx_232_2] = (stage_v_232_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int s_idx_233_1 = sec_r000289_13_1 & 3;
  int s_idx_233_2 = sec_r000289_13_2 & 3;
  int stage_v_233_1 = (table_1[s_idx_233_1] + pub_r000289_3_1) & 127;
  int stage_v_233_2 = (table_2[s_idx_233_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_233_1] = (stage_v_233_1 + 7) & 63;
  table_2[s_idx_233_2] = (stage_v_233_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int s_idx_234_1 = sec_r000289_19_1 & 3;
  int s_idx_234_2 = sec_r000289_19_2 & 3;
  int stage_v_234_1 = (table_1[s_idx_234_1] + pub_r000289_4_1) & 127;
  int stage_v_234_2 = (table_2[s_idx_234_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_234_1] = (stage_v_234_1 + 7) & 63;
  table_2[s_idx_234_2] = (stage_v_234_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int s_idx_235_1 = stage_v_187_1 & 3;
  int s_idx_235_2 = stage_v_187_2 & 3;
  int stage_v_235_1 = (table_1[s_idx_235_1] + pub_r000289_1_1) & 127;
  int stage_v_235_2 = (table_2[s_idx_235_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_235_1] = (stage_v_235_1 + 7) & 63;
  table_2[s_idx_235_2] = (stage_v_235_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int s_idx_236_1 = sec_r000289_6_1 & 3;
  int s_idx_236_2 = sec_r000289_6_2 & 3;
  int stage_v_236_1 = (table_1[s_idx_236_1] + pub_r000289_9_1) & 127;
  int stage_v_236_2 = (table_2[s_idx_236_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_236_1] = (stage_v_236_1 + 7) & 63;
  table_2[s_idx_236_2] = (stage_v_236_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int s_idx_237_1 = sec_r000289_2_1 & 3;
  int s_idx_237_2 = sec_r000289_2_2 & 3;
  int stage_v_237_1 = (table_1[s_idx_237_1] + pub_r000289_13_1) & 127;
  int stage_v_237_2 = (table_2[s_idx_237_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_237_1] = (stage_v_237_1 + 7) & 63;
  table_2[s_idx_237_2] = (stage_v_237_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int s_idx_238_1 = stage_v_203_1 & 3;
  int s_idx_238_2 = stage_v_203_2 & 3;
  int stage_v_238_1 = (table_1[s_idx_238_1] + pub_r000289_8_1) & 127;
  int stage_v_238_2 = (table_2[s_idx_238_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_238_1] = (stage_v_238_1 + 7) & 63;
  table_2[s_idx_238_2] = (stage_v_238_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int s_idx_239_1 = sec_r000289_10_1 & 3;
  int s_idx_239_2 = sec_r000289_10_2 & 3;
  int stage_v_239_1 = (table_1[s_idx_239_1] + pub_r000289_7_1) & 127;
  int stage_v_239_2 = (table_2[s_idx_239_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_239_1] = (stage_v_239_1 + 7) & 63;
  table_2[s_idx_239_2] = (stage_v_239_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int s_idx_240_1 = sec_r000289_14_1 & 3;
  int s_idx_240_2 = sec_r000289_14_2 & 3;
  int stage_v_240_1 = (table_1[s_idx_240_1] + pub_r000289_7_1) & 127;
  int stage_v_240_2 = (table_2[s_idx_240_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_240_1] = (stage_v_240_1 + 7) & 63;
  table_2[s_idx_240_2] = (stage_v_240_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int s_idx_241_1 = stage_v_201_1 & 3;
  int s_idx_241_2 = stage_v_201_2 & 3;
  int stage_v_241_1 = (table_1[s_idx_241_1] + pub_r000289_8_1) & 127;
  int stage_v_241_2 = (table_2[s_idx_241_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_241_1] = (stage_v_241_1 + 7) & 63;
  table_2[s_idx_241_2] = (stage_v_241_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int s_idx_242_1 = stage_v_109_1 & 3;
  int s_idx_242_2 = stage_v_109_2 & 3;
  int stage_v_242_1 = (table_1[s_idx_242_1] + pub_r000289_8_1) & 127;
  int stage_v_242_2 = (table_2[s_idx_242_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_242_1] = (stage_v_242_1 + 7) & 63;
  table_2[s_idx_242_2] = (stage_v_242_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int s_idx_243_1 = stage_v_158_1 & 3;
  int s_idx_243_2 = stage_v_158_2 & 3;
  int stage_v_243_1 = (table_1[s_idx_243_1] + pub_r000289_1_1) & 127;
  int stage_v_243_2 = (table_2[s_idx_243_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_243_1] = (stage_v_243_1 + 7) & 63;
  table_2[s_idx_243_2] = (stage_v_243_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int s_idx_244_1 = sec_r000289_6_1 & 3;
  int s_idx_244_2 = sec_r000289_6_2 & 3;
  int stage_v_244_1 = (table_1[s_idx_244_1] + pub_r000289_0_1) & 127;
  int stage_v_244_2 = (table_2[s_idx_244_2] + pub_r000289_0_2) & 127;
  table_1[s_idx_244_1] = (stage_v_244_1 + 7) & 63;
  table_2[s_idx_244_2] = (stage_v_244_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int s_idx_245_1 = sec_r000289_10_1 & 3;
  int s_idx_245_2 = sec_r000289_10_2 & 3;
  int stage_v_245_1 = (table_1[s_idx_245_1] + pub_r000289_13_1) & 127;
  int stage_v_245_2 = (table_2[s_idx_245_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_245_1] = (stage_v_245_1 + 7) & 63;
  table_2[s_idx_245_2] = (stage_v_245_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int s_idx_246_1 = sec_r000289_14_1 & 3;
  int s_idx_246_2 = sec_r000289_14_2 & 3;
  int stage_v_246_1 = (table_1[s_idx_246_1] + pub_r000289_15_1) & 127;
  int stage_v_246_2 = (table_2[s_idx_246_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_246_1] = (stage_v_246_1 + 7) & 63;
  table_2[s_idx_246_2] = (stage_v_246_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int s_idx_247_1 = sec_r000289_10_1 & 3;
  int s_idx_247_2 = sec_r000289_10_2 & 3;
  int stage_v_247_1 = (table_1[s_idx_247_1] + pub_r000289_15_1) & 127;
  int stage_v_247_2 = (table_2[s_idx_247_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_247_1] = (stage_v_247_1 + 7) & 63;
  table_2[s_idx_247_2] = (stage_v_247_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int s_idx_248_1 = stage_v_107_1 & 3;
  int s_idx_248_2 = stage_v_107_2 & 3;
  int stage_v_248_1 = (table_1[s_idx_248_1] + pub_r000289_2_1) & 127;
  int stage_v_248_2 = (table_2[s_idx_248_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_248_1] = (stage_v_248_1 + 7) & 63;
  table_2[s_idx_248_2] = (stage_v_248_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int s_idx_249_1 = stage_v_134_1 & 3;
  int s_idx_249_2 = stage_v_134_2 & 3;
  int stage_v_249_1 = (table_1[s_idx_249_1] + pub_r000289_13_1) & 127;
  int stage_v_249_2 = (table_2[s_idx_249_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_249_1] = (stage_v_249_1 + 7) & 63;
  table_2[s_idx_249_2] = (stage_v_249_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int s_idx_250_1 = stage_v_95_1 & 3;
  int s_idx_250_2 = stage_v_95_2 & 3;
  int stage_v_250_1 = (table_1[s_idx_250_1] + pub_r000289_6_1) & 127;
  int stage_v_250_2 = (table_2[s_idx_250_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_250_1] = (stage_v_250_1 + 7) & 63;
  table_2[s_idx_250_2] = (stage_v_250_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int s_idx_251_1 = stage_v_220_1 & 3;
  int s_idx_251_2 = stage_v_220_2 & 3;
  int stage_v_251_1 = (table_1[s_idx_251_1] + pub_r000289_11_1) & 127;
  int stage_v_251_2 = (table_2[s_idx_251_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_251_1] = (stage_v_251_1 + 7) & 63;
  table_2[s_idx_251_2] = (stage_v_251_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int s_idx_252_1 = stage_v_202_1 & 3;
  int s_idx_252_2 = stage_v_202_2 & 3;
  int stage_v_252_1 = (table_1[s_idx_252_1] + pub_r000289_10_1) & 127;
  int stage_v_252_2 = (table_2[s_idx_252_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_252_1] = (stage_v_252_1 + 7) & 63;
  table_2[s_idx_252_2] = (stage_v_252_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int s_idx_253_1 = stage_v_90_1 & 3;
  int s_idx_253_2 = stage_v_90_2 & 3;
  int stage_v_253_1 = (table_1[s_idx_253_1] + pub_r000289_8_1) & 127;
  int stage_v_253_2 = (table_2[s_idx_253_2] + pub_r000289_8_2) & 127;
  table_1[s_idx_253_1] = (stage_v_253_1 + 7) & 63;
  table_2[s_idx_253_2] = (stage_v_253_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int s_idx_254_1 = stage_v_95_1 & 3;
  int s_idx_254_2 = stage_v_95_2 & 3;
  int stage_v_254_1 = (table_1[s_idx_254_1] + pub_r000289_4_1) & 127;
  int stage_v_254_2 = (table_2[s_idx_254_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_254_1] = (stage_v_254_1 + 7) & 63;
  table_2[s_idx_254_2] = (stage_v_254_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int s_idx_255_1 = stage_v_214_1 & 3;
  int s_idx_255_2 = stage_v_214_2 & 3;
  int stage_v_255_1 = (table_1[s_idx_255_1] + pub_r000289_9_1) & 127;
  int stage_v_255_2 = (table_2[s_idx_255_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_255_1] = (stage_v_255_1 + 7) & 63;
  table_2[s_idx_255_2] = (stage_v_255_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int s_idx_256_1 = stage_v_249_1 & 3;
  int s_idx_256_2 = stage_v_249_2 & 3;
  int stage_v_256_1 = (table_1[s_idx_256_1] + pub_r000289_1_1) & 127;
  int stage_v_256_2 = (table_2[s_idx_256_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_256_1] = (stage_v_256_1 + 7) & 63;
  table_2[s_idx_256_2] = (stage_v_256_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  int s_idx_257_1 = stage_v_153_1 & 3;
  int s_idx_257_2 = stage_v_153_2 & 3;
  int stage_v_257_1 = (table_1[s_idx_257_1] + pub_r000289_2_1) & 127;
  int stage_v_257_2 = (table_2[s_idx_257_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_257_1] = (stage_v_257_1 + 7) & 63;
  table_2[s_idx_257_2] = (stage_v_257_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  int s_idx_258_1 = sec_r000289_13_1 & 3;
  int s_idx_258_2 = sec_r000289_13_2 & 3;
  int stage_v_258_1 = (table_1[s_idx_258_1] + pub_r000289_7_1) & 127;
  int stage_v_258_2 = (table_2[s_idx_258_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_258_1] = (stage_v_258_1 + 7) & 63;
  table_2[s_idx_258_2] = (stage_v_258_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int s_idx_259_1 = stage_v_175_1 & 3;
  int s_idx_259_2 = stage_v_175_2 & 3;
  int stage_v_259_1 = (table_1[s_idx_259_1] + pub_r000289_5_1) & 127;
  int stage_v_259_2 = (table_2[s_idx_259_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_259_1] = (stage_v_259_1 + 7) & 63;
  table_2[s_idx_259_2] = (stage_v_259_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int s_idx_260_1 = sec_r000289_10_1 & 3;
  int s_idx_260_2 = sec_r000289_10_2 & 3;
  int stage_v_260_1 = (table_1[s_idx_260_1] + pub_r000289_11_1) & 127;
  int stage_v_260_2 = (table_2[s_idx_260_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_260_1] = (stage_v_260_1 + 7) & 63;
  table_2[s_idx_260_2] = (stage_v_260_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  int s_idx_261_1 = stage_v_175_1 & 3;
  int s_idx_261_2 = stage_v_175_2 & 3;
  int stage_v_261_1 = (table_1[s_idx_261_1] + pub_r000289_15_1) & 127;
  int stage_v_261_2 = (table_2[s_idx_261_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_261_1] = (stage_v_261_1 + 7) & 63;
  table_2[s_idx_261_2] = (stage_v_261_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  int s_idx_262_1 = stage_v_79_1 & 3;
  int s_idx_262_2 = stage_v_79_2 & 3;
  int stage_v_262_1 = (table_1[s_idx_262_1] + pub_r000289_10_1) & 127;
  int stage_v_262_2 = (table_2[s_idx_262_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_262_1] = (stage_v_262_1 + 7) & 63;
  table_2[s_idx_262_2] = (stage_v_262_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int s_idx_263_1 = sec_r000289_18_1 & 3;
  int s_idx_263_2 = sec_r000289_18_2 & 3;
  int stage_v_263_1 = (table_1[s_idx_263_1] + pub_r000289_6_1) & 127;
  int stage_v_263_2 = (table_2[s_idx_263_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_263_1] = (stage_v_263_1 + 7) & 63;
  table_2[s_idx_263_2] = (stage_v_263_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int s_idx_264_1 = stage_v_250_1 & 3;
  int s_idx_264_2 = stage_v_250_2 & 3;
  int stage_v_264_1 = (table_1[s_idx_264_1] + pub_r000289_11_1) & 127;
  int stage_v_264_2 = (table_2[s_idx_264_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_264_1] = (stage_v_264_1 + 7) & 63;
  table_2[s_idx_264_2] = (stage_v_264_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  int s_idx_265_1 = sec_r000289_0_1 & 3;
  int s_idx_265_2 = sec_r000289_0_2 & 3;
  int stage_v_265_1 = (table_1[s_idx_265_1] + pub_r000289_14_1) & 127;
  int stage_v_265_2 = (table_2[s_idx_265_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_265_1] = (stage_v_265_1 + 7) & 63;
  table_2[s_idx_265_2] = (stage_v_265_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  int s_idx_266_1 = sec_r000289_17_1 & 3;
  int s_idx_266_2 = sec_r000289_17_2 & 3;
  int stage_v_266_1 = (table_1[s_idx_266_1] + pub_r000289_9_1) & 127;
  int stage_v_266_2 = (table_2[s_idx_266_2] + pub_r000289_9_2) & 127;
  table_1[s_idx_266_1] = (stage_v_266_1 + 7) & 63;
  table_2[s_idx_266_2] = (stage_v_266_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  int s_idx_267_1 = stage_v_175_1 & 3;
  int s_idx_267_2 = stage_v_175_2 & 3;
  int stage_v_267_1 = (table_1[s_idx_267_1] + pub_r000289_13_1) & 127;
  int stage_v_267_2 = (table_2[s_idx_267_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_267_1] = (stage_v_267_1 + 7) & 63;
  table_2[s_idx_267_2] = (stage_v_267_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  int s_idx_268_1 = stage_v_162_1 & 3;
  int s_idx_268_2 = stage_v_162_2 & 3;
  int stage_v_268_1 = (table_1[s_idx_268_1] + pub_r000289_12_1) & 127;
  int stage_v_268_2 = (table_2[s_idx_268_2] + pub_r000289_12_2) & 127;
  table_1[s_idx_268_1] = (stage_v_268_1 + 7) & 63;
  table_2[s_idx_268_2] = (stage_v_268_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  int s_idx_269_1 = sec_r000289_17_1 & 3;
  int s_idx_269_2 = sec_r000289_17_2 & 3;
  int stage_v_269_1 = (table_1[s_idx_269_1] + pub_r000289_5_1) & 127;
  int stage_v_269_2 = (table_2[s_idx_269_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_269_1] = (stage_v_269_1 + 7) & 63;
  table_2[s_idx_269_2] = (stage_v_269_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  int s_idx_270_1 = stage_v_232_1 & 3;
  int s_idx_270_2 = stage_v_232_2 & 3;
  int stage_v_270_1 = (table_1[s_idx_270_1] + pub_r000289_16_1) & 127;
  int stage_v_270_2 = (table_2[s_idx_270_2] + pub_r000289_16_2) & 127;
  table_1[s_idx_270_1] = (stage_v_270_1 + 7) & 63;
  table_2[s_idx_270_2] = (stage_v_270_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  int s_idx_271_1 = sec_r000289_8_1 & 3;
  int s_idx_271_2 = sec_r000289_8_2 & 3;
  int stage_v_271_1 = (table_1[s_idx_271_1] + pub_r000289_15_1) & 127;
  int stage_v_271_2 = (table_2[s_idx_271_2] + pub_r000289_15_2) & 127;
  table_1[s_idx_271_1] = (stage_v_271_1 + 7) & 63;
  table_2[s_idx_271_2] = (stage_v_271_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  int s_idx_272_1 = sec_r000289_7_1 & 3;
  int s_idx_272_2 = sec_r000289_7_2 & 3;
  int stage_v_272_1 = (table_1[s_idx_272_1] + pub_r000289_7_1) & 127;
  int stage_v_272_2 = (table_2[s_idx_272_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_272_1] = (stage_v_272_1 + 7) & 63;
  table_2[s_idx_272_2] = (stage_v_272_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  int s_idx_273_1 = stage_v_136_1 & 3;
  int s_idx_273_2 = stage_v_136_2 & 3;
  int stage_v_273_1 = (table_1[s_idx_273_1] + pub_r000289_1_1) & 127;
  int stage_v_273_2 = (table_2[s_idx_273_2] + pub_r000289_1_2) & 127;
  table_1[s_idx_273_1] = (stage_v_273_1 + 7) & 63;
  table_2[s_idx_273_2] = (stage_v_273_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  int s_idx_274_1 = stage_v_216_1 & 3;
  int s_idx_274_2 = stage_v_216_2 & 3;
  int stage_v_274_1 = (table_1[s_idx_274_1] + pub_r000289_5_1) & 127;
  int stage_v_274_2 = (table_2[s_idx_274_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_274_1] = (stage_v_274_1 + 7) & 63;
  table_2[s_idx_274_2] = (stage_v_274_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  int s_idx_275_1 = stage_v_119_1 & 3;
  int s_idx_275_2 = stage_v_119_2 & 3;
  int stage_v_275_1 = (table_1[s_idx_275_1] + pub_r000289_14_1) & 127;
  int stage_v_275_2 = (table_2[s_idx_275_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_275_1] = (stage_v_275_1 + 7) & 63;
  table_2[s_idx_275_2] = (stage_v_275_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  int s_idx_276_1 = stage_v_108_1 & 3;
  int s_idx_276_2 = stage_v_108_2 & 3;
  int stage_v_276_1 = (table_1[s_idx_276_1] + pub_r000289_13_1) & 127;
  int stage_v_276_2 = (table_2[s_idx_276_2] + pub_r000289_13_2) & 127;
  table_1[s_idx_276_1] = (stage_v_276_1 + 7) & 63;
  table_2[s_idx_276_2] = (stage_v_276_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  int s_idx_277_1 = sec_r000289_13_1 & 3;
  int s_idx_277_2 = sec_r000289_13_2 & 3;
  int stage_v_277_1 = (table_1[s_idx_277_1] + pub_r000289_4_1) & 127;
  int stage_v_277_2 = (table_2[s_idx_277_2] + pub_r000289_4_2) & 127;
  table_1[s_idx_277_1] = (stage_v_277_1 + 7) & 63;
  table_2[s_idx_277_2] = (stage_v_277_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  int s_idx_278_1 = stage_v_162_1 & 3;
  int s_idx_278_2 = stage_v_162_2 & 3;
  int stage_v_278_1 = (table_1[s_idx_278_1] + pub_r000289_11_1) & 127;
  int stage_v_278_2 = (table_2[s_idx_278_2] + pub_r000289_11_2) & 127;
  table_1[s_idx_278_1] = (stage_v_278_1 + 7) & 63;
  table_2[s_idx_278_2] = (stage_v_278_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  int s_idx_279_1 = stage_v_200_1 & 3;
  int s_idx_279_2 = stage_v_200_2 & 3;
  int stage_v_279_1 = (table_1[s_idx_279_1] + pub_r000289_7_1) & 127;
  int stage_v_279_2 = (table_2[s_idx_279_2] + pub_r000289_7_2) & 127;
  table_1[s_idx_279_1] = (stage_v_279_1 + 7) & 63;
  table_2[s_idx_279_2] = (stage_v_279_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  int s_idx_280_1 = stage_v_191_1 & 3;
  int s_idx_280_2 = stage_v_191_2 & 3;
  int stage_v_280_1 = (table_1[s_idx_280_1] + pub_r000289_5_1) & 127;
  int stage_v_280_2 = (table_2[s_idx_280_2] + pub_r000289_5_2) & 127;
  table_1[s_idx_280_1] = (stage_v_280_1 + 7) & 63;
  table_2[s_idx_280_2] = (stage_v_280_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  int s_idx_281_1 = stage_v_181_1 & 3;
  int s_idx_281_2 = stage_v_181_2 & 3;
  int stage_v_281_1 = (table_1[s_idx_281_1] + pub_r000289_2_1) & 127;
  int stage_v_281_2 = (table_2[s_idx_281_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_281_1] = (stage_v_281_1 + 7) & 63;
  table_2[s_idx_281_2] = (stage_v_281_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  int s_idx_282_1 = sec_r000289_16_1 & 3;
  int s_idx_282_2 = sec_r000289_16_2 & 3;
  int stage_v_282_1 = (table_1[s_idx_282_1] + pub_r000289_10_1) & 127;
  int stage_v_282_2 = (table_2[s_idx_282_2] + pub_r000289_10_2) & 127;
  table_1[s_idx_282_1] = (stage_v_282_1 + 7) & 63;
  table_2[s_idx_282_2] = (stage_v_282_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  int s_idx_283_1 = sec_r000289_12_1 & 3;
  int s_idx_283_2 = sec_r000289_12_2 & 3;
  int stage_v_283_1 = (table_1[s_idx_283_1] + pub_r000289_3_1) & 127;
  int stage_v_283_2 = (table_2[s_idx_283_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_283_1] = (stage_v_283_1 + 7) & 63;
  table_2[s_idx_283_2] = (stage_v_283_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  int s_idx_284_1 = stage_v_280_1 & 3;
  int s_idx_284_2 = stage_v_280_2 & 3;
  int stage_v_284_1 = (table_1[s_idx_284_1] + pub_r000289_6_1) & 127;
  int stage_v_284_2 = (table_2[s_idx_284_2] + pub_r000289_6_2) & 127;
  table_1[s_idx_284_1] = (stage_v_284_1 + 7) & 63;
  table_2[s_idx_284_2] = (stage_v_284_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  int s_idx_285_1 = stage_v_270_1 & 3;
  int s_idx_285_2 = stage_v_270_2 & 3;
  int stage_v_285_1 = (table_1[s_idx_285_1] + pub_r000289_14_1) & 127;
  int stage_v_285_2 = (table_2[s_idx_285_2] + pub_r000289_14_2) & 127;
  table_1[s_idx_285_1] = (stage_v_285_1 + 7) & 63;
  table_2[s_idx_285_2] = (stage_v_285_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  int s_idx_286_1 = stage_v_241_1 & 3;
  int s_idx_286_2 = stage_v_241_2 & 3;
  int stage_v_286_1 = (table_1[s_idx_286_1] + pub_r000289_3_1) & 127;
  int stage_v_286_2 = (table_2[s_idx_286_2] + pub_r000289_3_2) & 127;
  table_1[s_idx_286_1] = (stage_v_286_1 + 7) & 63;
  table_2[s_idx_286_2] = (stage_v_286_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  int s_idx_287_1 = stage_v_282_1 & 3;
  int s_idx_287_2 = stage_v_282_2 & 3;
  int stage_v_287_1 = (table_1[s_idx_287_1] + pub_r000289_2_1) & 127;
  int stage_v_287_2 = (table_2[s_idx_287_2] + pub_r000289_2_2) & 127;
  table_1[s_idx_287_1] = (stage_v_287_1 + 7) & 63;
  table_2[s_idx_287_2] = (stage_v_287_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000289_10_1 == pub_r000289_10_2);
  __CPROVER_assume(sec_r000289_1_1 != sec_r000289_1_2);
  __CPROVER_assume(pub_r000289_16_1 == pub_r000289_16_2);
  __CPROVER_assume(sec_r000289_7_1 != sec_r000289_7_2);
  __CPROVER_assume(sec_r000289_17_1 != sec_r000289_17_2);
  __CPROVER_assume(pub_r000289_4_1 == pub_r000289_4_2);
  __CPROVER_assume(sec_r000289_19_1 != sec_r000289_19_2);
  __CPROVER_assume(pub_r000289_15_1 == pub_r000289_15_2);
  __CPROVER_assume(pub_r000289_13_1 == pub_r000289_13_2);
  __CPROVER_assume(sec_r000289_4_1 != sec_r000289_4_2);
  __CPROVER_assume(sec_r000289_5_1 != sec_r000289_5_2);
  __CPROVER_assume(pub_r000289_12_1 == pub_r000289_12_2);
  __CPROVER_assume(sec_r000289_6_1 != sec_r000289_6_2);
  __CPROVER_assume(sec_r000289_0_1 != sec_r000289_0_2);
  __CPROVER_assume(pub_r000289_3_1 == pub_r000289_3_2);
  __CPROVER_assume(sec_r000289_11_1 != sec_r000289_11_2);
  __CPROVER_assume(pub_r000289_1_1 == pub_r000289_1_2);
  __CPROVER_assume(pub_r000289_0_1 == pub_r000289_0_2);
  __CPROVER_assume(sec_r000289_9_1 != sec_r000289_9_2);
  __CPROVER_assume(pub_r000289_5_1 == pub_r000289_5_2);
  __CPROVER_assume(pub_r000289_6_1 == pub_r000289_6_2);
  __CPROVER_assume(sec_r000289_10_1 != sec_r000289_10_2);
  __CPROVER_assume(sec_r000289_16_1 != sec_r000289_16_2);
  __CPROVER_assume(pub_r000289_2_1 == pub_r000289_2_2);
  __CPROVER_assume(sec_r000289_15_1 != sec_r000289_15_2);
  __CPROVER_assume(sec_r000289_12_1 != sec_r000289_12_2);
  __CPROVER_assume(sec_r000289_14_1 != sec_r000289_14_2);
  __CPROVER_assume(sec_r000289_2_1 != sec_r000289_2_2);
  __CPROVER_assume(pub_r000289_7_1 == pub_r000289_7_2);
  __CPROVER_assume(pub_r000289_8_1 == pub_r000289_8_2);
  __CPROVER_assume(pub_r000289_11_1 == pub_r000289_11_2);
  __CPROVER_assume(sec_r000289_3_1 != sec_r000289_3_2);
  __CPROVER_assume(pub_r000289_9_1 == pub_r000289_9_2);
  __CPROVER_assume(sec_r000289_18_1 != sec_r000289_18_2);
  __CPROVER_assume(sec_r000289_13_1 != sec_r000289_13_2);
  __CPROVER_assume(pub_r000289_14_1 == pub_r000289_14_2);
  __CPROVER_assume(sec_r000289_8_1 != sec_r000289_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.envelope == st_var_1_2.envelope);
  assert(st_var_1_1.rms == st_var_1_2.rms);
  assert(st_var_1_1.sample_rate == st_var_1_2.sample_rate);
  assert(st_var_1_1.channels == st_var_1_2.channels);
  assert(st_var_1_1.peak == st_var_1_2.peak);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.account_id == st_var_2_2.account_id);
  assert(st_var_2_1.rate == st_var_2_2.rate);
  assert(st_var_2_1.fee == st_var_2_2.fee);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.threshold == st_var_3_2.threshold);
  assert(st_var_3_1.offset == st_var_3_2.offset);
  assert(st_var_3_1.status == st_var_3_2.status);
  assert(st_var_3_1.reading == st_var_3_2.reading);
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
  assert(s_idx_78_1 == s_idx_78_2);
  assert(stage_v_78_1 == stage_v_78_2);
  assert(s_idx_79_1 == s_idx_79_2);
  assert(stage_v_79_1 == stage_v_79_2);
  assert(s_idx_80_1 == s_idx_80_2);
  assert(stage_v_80_1 == stage_v_80_2);
  assert(s_idx_81_1 == s_idx_81_2);
  assert(stage_v_81_1 == stage_v_81_2);
  assert(s_idx_82_1 == s_idx_82_2);
  assert(stage_v_82_1 == stage_v_82_2);
  assert(s_idx_83_1 == s_idx_83_2);
  assert(stage_v_83_1 == stage_v_83_2);
  assert(s_idx_84_1 == s_idx_84_2);
  assert(stage_v_84_1 == stage_v_84_2);
  assert(s_idx_85_1 == s_idx_85_2);
  assert(stage_v_85_1 == stage_v_85_2);
  assert(s_idx_86_1 == s_idx_86_2);
  assert(stage_v_86_1 == stage_v_86_2);
  assert(s_idx_87_1 == s_idx_87_2);
  assert(stage_v_87_1 == stage_v_87_2);
  assert(s_idx_88_1 == s_idx_88_2);
  assert(stage_v_88_1 == stage_v_88_2);
  assert(s_idx_89_1 == s_idx_89_2);
  assert(stage_v_89_1 == stage_v_89_2);
  assert(s_idx_90_1 == s_idx_90_2);
  assert(stage_v_90_1 == stage_v_90_2);
  assert(s_idx_91_1 == s_idx_91_2);
  assert(stage_v_91_1 == stage_v_91_2);
  assert(s_idx_92_1 == s_idx_92_2);
  assert(stage_v_92_1 == stage_v_92_2);
  assert(s_idx_93_1 == s_idx_93_2);
  assert(stage_v_93_1 == stage_v_93_2);
  assert(s_idx_94_1 == s_idx_94_2);
  assert(stage_v_94_1 == stage_v_94_2);
  assert(s_idx_95_1 == s_idx_95_2);
  assert(stage_v_95_1 == stage_v_95_2);
  assert(s_idx_96_1 == s_idx_96_2);
  assert(stage_v_96_1 == stage_v_96_2);
  assert(s_idx_97_1 == s_idx_97_2);
  assert(stage_v_97_1 == stage_v_97_2);
  assert(s_idx_98_1 == s_idx_98_2);
  assert(stage_v_98_1 == stage_v_98_2);
  assert(s_idx_99_1 == s_idx_99_2);
  assert(stage_v_99_1 == stage_v_99_2);
  assert(s_idx_100_1 == s_idx_100_2);
  assert(stage_v_100_1 == stage_v_100_2);
  assert(s_idx_101_1 == s_idx_101_2);
  assert(stage_v_101_1 == stage_v_101_2);
  assert(s_idx_102_1 == s_idx_102_2);
  assert(stage_v_102_1 == stage_v_102_2);
  assert(s_idx_103_1 == s_idx_103_2);
  assert(stage_v_103_1 == stage_v_103_2);
  assert(s_idx_104_1 == s_idx_104_2);
  assert(stage_v_104_1 == stage_v_104_2);
  assert(s_idx_105_1 == s_idx_105_2);
  assert(stage_v_105_1 == stage_v_105_2);
  assert(s_idx_106_1 == s_idx_106_2);
  assert(stage_v_106_1 == stage_v_106_2);
  assert(s_idx_107_1 == s_idx_107_2);
  assert(stage_v_107_1 == stage_v_107_2);
  assert(s_idx_108_1 == s_idx_108_2);
  assert(stage_v_108_1 == stage_v_108_2);
  assert(s_idx_109_1 == s_idx_109_2);
  assert(stage_v_109_1 == stage_v_109_2);
  assert(s_idx_110_1 == s_idx_110_2);
  assert(stage_v_110_1 == stage_v_110_2);
  assert(s_idx_111_1 == s_idx_111_2);
  assert(stage_v_111_1 == stage_v_111_2);
  assert(s_idx_112_1 == s_idx_112_2);
  assert(stage_v_112_1 == stage_v_112_2);
  assert(s_idx_113_1 == s_idx_113_2);
  assert(stage_v_113_1 == stage_v_113_2);
  assert(s_idx_114_1 == s_idx_114_2);
  assert(stage_v_114_1 == stage_v_114_2);
  assert(s_idx_115_1 == s_idx_115_2);
  assert(stage_v_115_1 == stage_v_115_2);
  assert(s_idx_116_1 == s_idx_116_2);
  assert(stage_v_116_1 == stage_v_116_2);
  assert(s_idx_117_1 == s_idx_117_2);
  assert(stage_v_117_1 == stage_v_117_2);
  assert(s_idx_118_1 == s_idx_118_2);
  assert(stage_v_118_1 == stage_v_118_2);
  assert(s_idx_119_1 == s_idx_119_2);
  assert(stage_v_119_1 == stage_v_119_2);
  assert(s_idx_120_1 == s_idx_120_2);
  assert(stage_v_120_1 == stage_v_120_2);
  assert(s_idx_121_1 == s_idx_121_2);
  assert(stage_v_121_1 == stage_v_121_2);
  assert(s_idx_122_1 == s_idx_122_2);
  assert(stage_v_122_1 == stage_v_122_2);
  assert(s_idx_123_1 == s_idx_123_2);
  assert(stage_v_123_1 == stage_v_123_2);
  assert(s_idx_124_1 == s_idx_124_2);
  assert(stage_v_124_1 == stage_v_124_2);
  assert(s_idx_125_1 == s_idx_125_2);
  assert(stage_v_125_1 == stage_v_125_2);
  assert(s_idx_126_1 == s_idx_126_2);
  assert(stage_v_126_1 == stage_v_126_2);
  assert(s_idx_127_1 == s_idx_127_2);
  assert(stage_v_127_1 == stage_v_127_2);
  assert(s_idx_128_1 == s_idx_128_2);
  assert(stage_v_128_1 == stage_v_128_2);
  assert(s_idx_129_1 == s_idx_129_2);
  assert(stage_v_129_1 == stage_v_129_2);
  assert(s_idx_130_1 == s_idx_130_2);
  assert(stage_v_130_1 == stage_v_130_2);
  assert(s_idx_131_1 == s_idx_131_2);
  assert(stage_v_131_1 == stage_v_131_2);
  assert(s_idx_132_1 == s_idx_132_2);
  assert(stage_v_132_1 == stage_v_132_2);
  assert(s_idx_133_1 == s_idx_133_2);
  assert(stage_v_133_1 == stage_v_133_2);
  assert(s_idx_134_1 == s_idx_134_2);
  assert(stage_v_134_1 == stage_v_134_2);
  assert(s_idx_135_1 == s_idx_135_2);
  assert(stage_v_135_1 == stage_v_135_2);
  assert(s_idx_136_1 == s_idx_136_2);
  assert(stage_v_136_1 == stage_v_136_2);
  assert(s_idx_137_1 == s_idx_137_2);
  assert(stage_v_137_1 == stage_v_137_2);
  assert(s_idx_138_1 == s_idx_138_2);
  assert(stage_v_138_1 == stage_v_138_2);
  assert(s_idx_139_1 == s_idx_139_2);
  assert(stage_v_139_1 == stage_v_139_2);
  assert(s_idx_140_1 == s_idx_140_2);
  assert(stage_v_140_1 == stage_v_140_2);
  assert(s_idx_141_1 == s_idx_141_2);
  assert(stage_v_141_1 == stage_v_141_2);
  assert(s_idx_142_1 == s_idx_142_2);
  assert(stage_v_142_1 == stage_v_142_2);
  assert(s_idx_143_1 == s_idx_143_2);
  assert(stage_v_143_1 == stage_v_143_2);
  assert(s_idx_144_1 == s_idx_144_2);
  assert(stage_v_144_1 == stage_v_144_2);
  assert(s_idx_145_1 == s_idx_145_2);
  assert(stage_v_145_1 == stage_v_145_2);
  assert(s_idx_146_1 == s_idx_146_2);
  assert(stage_v_146_1 == stage_v_146_2);
  assert(s_idx_147_1 == s_idx_147_2);
  assert(stage_v_147_1 == stage_v_147_2);
  assert(s_idx_148_1 == s_idx_148_2);
  assert(stage_v_148_1 == stage_v_148_2);
  assert(s_idx_149_1 == s_idx_149_2);
  assert(stage_v_149_1 == stage_v_149_2);
  assert(s_idx_150_1 == s_idx_150_2);
  assert(stage_v_150_1 == stage_v_150_2);
  assert(s_idx_151_1 == s_idx_151_2);
  assert(stage_v_151_1 == stage_v_151_2);
  assert(s_idx_152_1 == s_idx_152_2);
  assert(stage_v_152_1 == stage_v_152_2);
  assert(s_idx_153_1 == s_idx_153_2);
  assert(stage_v_153_1 == stage_v_153_2);
  assert(s_idx_154_1 == s_idx_154_2);
  assert(stage_v_154_1 == stage_v_154_2);
  assert(s_idx_155_1 == s_idx_155_2);
  assert(stage_v_155_1 == stage_v_155_2);
  assert(s_idx_156_1 == s_idx_156_2);
  assert(stage_v_156_1 == stage_v_156_2);
  assert(s_idx_157_1 == s_idx_157_2);
  assert(stage_v_157_1 == stage_v_157_2);
  assert(s_idx_158_1 == s_idx_158_2);
  assert(stage_v_158_1 == stage_v_158_2);
  assert(s_idx_159_1 == s_idx_159_2);
  assert(stage_v_159_1 == stage_v_159_2);
  assert(s_idx_160_1 == s_idx_160_2);
  assert(stage_v_160_1 == stage_v_160_2);
  assert(s_idx_161_1 == s_idx_161_2);
  assert(stage_v_161_1 == stage_v_161_2);
  assert(s_idx_162_1 == s_idx_162_2);
  assert(stage_v_162_1 == stage_v_162_2);
  assert(s_idx_163_1 == s_idx_163_2);
  assert(stage_v_163_1 == stage_v_163_2);
  assert(s_idx_164_1 == s_idx_164_2);
  assert(stage_v_164_1 == stage_v_164_2);
  assert(s_idx_165_1 == s_idx_165_2);
  assert(stage_v_165_1 == stage_v_165_2);
  assert(s_idx_166_1 == s_idx_166_2);
  assert(stage_v_166_1 == stage_v_166_2);
  assert(s_idx_167_1 == s_idx_167_2);
  assert(stage_v_167_1 == stage_v_167_2);
  assert(s_idx_168_1 == s_idx_168_2);
  assert(stage_v_168_1 == stage_v_168_2);
  assert(s_idx_169_1 == s_idx_169_2);
  assert(stage_v_169_1 == stage_v_169_2);
  assert(s_idx_170_1 == s_idx_170_2);
  assert(stage_v_170_1 == stage_v_170_2);
  assert(s_idx_171_1 == s_idx_171_2);
  assert(stage_v_171_1 == stage_v_171_2);
  assert(s_idx_172_1 == s_idx_172_2);
  assert(stage_v_172_1 == stage_v_172_2);
  assert(s_idx_173_1 == s_idx_173_2);
  assert(stage_v_173_1 == stage_v_173_2);
  assert(s_idx_174_1 == s_idx_174_2);
  assert(stage_v_174_1 == stage_v_174_2);
  assert(s_idx_175_1 == s_idx_175_2);
  assert(stage_v_175_1 == stage_v_175_2);
  assert(s_idx_176_1 == s_idx_176_2);
  assert(stage_v_176_1 == stage_v_176_2);
  assert(s_idx_177_1 == s_idx_177_2);
  assert(stage_v_177_1 == stage_v_177_2);
  assert(s_idx_178_1 == s_idx_178_2);
  assert(stage_v_178_1 == stage_v_178_2);
  assert(s_idx_179_1 == s_idx_179_2);
  assert(stage_v_179_1 == stage_v_179_2);
  assert(s_idx_180_1 == s_idx_180_2);
  assert(stage_v_180_1 == stage_v_180_2);
  assert(s_idx_181_1 == s_idx_181_2);
  assert(stage_v_181_1 == stage_v_181_2);
  assert(s_idx_182_1 == s_idx_182_2);
  assert(stage_v_182_1 == stage_v_182_2);
  assert(s_idx_183_1 == s_idx_183_2);
  assert(stage_v_183_1 == stage_v_183_2);
  assert(s_idx_184_1 == s_idx_184_2);
  assert(stage_v_184_1 == stage_v_184_2);
  assert(s_idx_185_1 == s_idx_185_2);
  assert(stage_v_185_1 == stage_v_185_2);
  assert(s_idx_186_1 == s_idx_186_2);
  assert(stage_v_186_1 == stage_v_186_2);
  assert(s_idx_187_1 == s_idx_187_2);
  assert(stage_v_187_1 == stage_v_187_2);
  assert(s_idx_188_1 == s_idx_188_2);
  assert(stage_v_188_1 == stage_v_188_2);
  assert(s_idx_189_1 == s_idx_189_2);
  assert(stage_v_189_1 == stage_v_189_2);
  assert(s_idx_190_1 == s_idx_190_2);
  assert(stage_v_190_1 == stage_v_190_2);
  assert(s_idx_191_1 == s_idx_191_2);
  assert(stage_v_191_1 == stage_v_191_2);
  assert(s_idx_192_1 == s_idx_192_2);
  assert(stage_v_192_1 == stage_v_192_2);
  assert(s_idx_193_1 == s_idx_193_2);
  assert(stage_v_193_1 == stage_v_193_2);
  assert(s_idx_194_1 == s_idx_194_2);
  assert(stage_v_194_1 == stage_v_194_2);
  assert(s_idx_195_1 == s_idx_195_2);
  assert(stage_v_195_1 == stage_v_195_2);
  assert(s_idx_196_1 == s_idx_196_2);
  assert(stage_v_196_1 == stage_v_196_2);
  assert(s_idx_197_1 == s_idx_197_2);
  assert(stage_v_197_1 == stage_v_197_2);
  assert(s_idx_198_1 == s_idx_198_2);
  assert(stage_v_198_1 == stage_v_198_2);
  assert(s_idx_199_1 == s_idx_199_2);
  assert(stage_v_199_1 == stage_v_199_2);
  assert(s_idx_200_1 == s_idx_200_2);
  assert(stage_v_200_1 == stage_v_200_2);
  assert(s_idx_201_1 == s_idx_201_2);
  assert(stage_v_201_1 == stage_v_201_2);
  assert(s_idx_202_1 == s_idx_202_2);
  assert(stage_v_202_1 == stage_v_202_2);
  assert(s_idx_203_1 == s_idx_203_2);
  assert(stage_v_203_1 == stage_v_203_2);
  assert(s_idx_204_1 == s_idx_204_2);
  assert(stage_v_204_1 == stage_v_204_2);
  assert(s_idx_205_1 == s_idx_205_2);
  assert(stage_v_205_1 == stage_v_205_2);
  assert(s_idx_206_1 == s_idx_206_2);
  assert(stage_v_206_1 == stage_v_206_2);
  assert(s_idx_207_1 == s_idx_207_2);
  assert(stage_v_207_1 == stage_v_207_2);
  assert(s_idx_208_1 == s_idx_208_2);
  assert(stage_v_208_1 == stage_v_208_2);
  assert(s_idx_209_1 == s_idx_209_2);
  assert(stage_v_209_1 == stage_v_209_2);
  assert(s_idx_210_1 == s_idx_210_2);
  assert(stage_v_210_1 == stage_v_210_2);
  assert(s_idx_211_1 == s_idx_211_2);
  assert(stage_v_211_1 == stage_v_211_2);
  assert(s_idx_212_1 == s_idx_212_2);
  assert(stage_v_212_1 == stage_v_212_2);
  assert(s_idx_213_1 == s_idx_213_2);
  assert(stage_v_213_1 == stage_v_213_2);
  assert(s_idx_214_1 == s_idx_214_2);
  assert(stage_v_214_1 == stage_v_214_2);
  assert(s_idx_215_1 == s_idx_215_2);
  assert(stage_v_215_1 == stage_v_215_2);
  assert(s_idx_216_1 == s_idx_216_2);
  assert(stage_v_216_1 == stage_v_216_2);
  assert(s_idx_217_1 == s_idx_217_2);
  assert(stage_v_217_1 == stage_v_217_2);
  assert(s_idx_218_1 == s_idx_218_2);
  assert(stage_v_218_1 == stage_v_218_2);
  assert(s_idx_219_1 == s_idx_219_2);
  assert(stage_v_219_1 == stage_v_219_2);
  assert(s_idx_220_1 == s_idx_220_2);
  assert(stage_v_220_1 == stage_v_220_2);
  assert(s_idx_221_1 == s_idx_221_2);
  assert(stage_v_221_1 == stage_v_221_2);
  assert(s_idx_222_1 == s_idx_222_2);
  assert(stage_v_222_1 == stage_v_222_2);
  assert(s_idx_223_1 == s_idx_223_2);
  assert(stage_v_223_1 == stage_v_223_2);
  assert(s_idx_224_1 == s_idx_224_2);
  assert(stage_v_224_1 == stage_v_224_2);
  assert(s_idx_225_1 == s_idx_225_2);
  assert(stage_v_225_1 == stage_v_225_2);
  assert(s_idx_226_1 == s_idx_226_2);
  assert(stage_v_226_1 == stage_v_226_2);
  assert(s_idx_227_1 == s_idx_227_2);
  assert(stage_v_227_1 == stage_v_227_2);
  assert(s_idx_228_1 == s_idx_228_2);
  assert(stage_v_228_1 == stage_v_228_2);
  assert(s_idx_229_1 == s_idx_229_2);
  assert(stage_v_229_1 == stage_v_229_2);
  assert(s_idx_230_1 == s_idx_230_2);
  assert(stage_v_230_1 == stage_v_230_2);
  assert(s_idx_231_1 == s_idx_231_2);
  assert(stage_v_231_1 == stage_v_231_2);
  assert(s_idx_232_1 == s_idx_232_2);
  assert(stage_v_232_1 == stage_v_232_2);
  assert(s_idx_233_1 == s_idx_233_2);
  assert(stage_v_233_1 == stage_v_233_2);
  assert(s_idx_234_1 == s_idx_234_2);
  assert(stage_v_234_1 == stage_v_234_2);
  assert(s_idx_235_1 == s_idx_235_2);
  assert(stage_v_235_1 == stage_v_235_2);
  assert(s_idx_236_1 == s_idx_236_2);
  assert(stage_v_236_1 == stage_v_236_2);
  assert(s_idx_237_1 == s_idx_237_2);
  assert(stage_v_237_1 == stage_v_237_2);
  assert(s_idx_238_1 == s_idx_238_2);
  assert(stage_v_238_1 == stage_v_238_2);
  assert(s_idx_239_1 == s_idx_239_2);
  assert(stage_v_239_1 == stage_v_239_2);
  assert(s_idx_240_1 == s_idx_240_2);
  assert(stage_v_240_1 == stage_v_240_2);
  assert(s_idx_241_1 == s_idx_241_2);
  assert(stage_v_241_1 == stage_v_241_2);
  assert(s_idx_242_1 == s_idx_242_2);
  assert(stage_v_242_1 == stage_v_242_2);
  assert(s_idx_243_1 == s_idx_243_2);
  assert(stage_v_243_1 == stage_v_243_2);
  assert(s_idx_244_1 == s_idx_244_2);
  assert(stage_v_244_1 == stage_v_244_2);
  assert(s_idx_245_1 == s_idx_245_2);
  assert(stage_v_245_1 == stage_v_245_2);
  assert(s_idx_246_1 == s_idx_246_2);
  assert(stage_v_246_1 == stage_v_246_2);
  assert(s_idx_247_1 == s_idx_247_2);
  assert(stage_v_247_1 == stage_v_247_2);
  assert(s_idx_248_1 == s_idx_248_2);
  assert(stage_v_248_1 == stage_v_248_2);
  assert(s_idx_249_1 == s_idx_249_2);
  assert(stage_v_249_1 == stage_v_249_2);
  assert(s_idx_250_1 == s_idx_250_2);
  assert(stage_v_250_1 == stage_v_250_2);
  assert(s_idx_251_1 == s_idx_251_2);
  assert(stage_v_251_1 == stage_v_251_2);
  assert(s_idx_252_1 == s_idx_252_2);
  assert(stage_v_252_1 == stage_v_252_2);
  assert(s_idx_253_1 == s_idx_253_2);
  assert(stage_v_253_1 == stage_v_253_2);
  assert(s_idx_254_1 == s_idx_254_2);
  assert(stage_v_254_1 == stage_v_254_2);
  assert(s_idx_255_1 == s_idx_255_2);
  assert(stage_v_255_1 == stage_v_255_2);
  assert(s_idx_256_1 == s_idx_256_2);
  assert(stage_v_256_1 == stage_v_256_2);
  assert(s_idx_257_1 == s_idx_257_2);
  assert(stage_v_257_1 == stage_v_257_2);
  assert(s_idx_258_1 == s_idx_258_2);
  assert(stage_v_258_1 == stage_v_258_2);
  assert(s_idx_259_1 == s_idx_259_2);
  assert(stage_v_259_1 == stage_v_259_2);
  assert(s_idx_260_1 == s_idx_260_2);
  assert(stage_v_260_1 == stage_v_260_2);
  assert(s_idx_261_1 == s_idx_261_2);
  assert(stage_v_261_1 == stage_v_261_2);
  assert(s_idx_262_1 == s_idx_262_2);
  assert(stage_v_262_1 == stage_v_262_2);
  assert(s_idx_263_1 == s_idx_263_2);
  assert(stage_v_263_1 == stage_v_263_2);
  assert(s_idx_264_1 == s_idx_264_2);
  assert(stage_v_264_1 == stage_v_264_2);
  assert(s_idx_265_1 == s_idx_265_2);
  assert(stage_v_265_1 == stage_v_265_2);
  assert(s_idx_266_1 == s_idx_266_2);
  assert(stage_v_266_1 == stage_v_266_2);
  assert(s_idx_267_1 == s_idx_267_2);
  assert(stage_v_267_1 == stage_v_267_2);
  assert(s_idx_268_1 == s_idx_268_2);
  assert(stage_v_268_1 == stage_v_268_2);
  assert(s_idx_269_1 == s_idx_269_2);
  assert(stage_v_269_1 == stage_v_269_2);
  assert(s_idx_270_1 == s_idx_270_2);
  assert(stage_v_270_1 == stage_v_270_2);
  assert(s_idx_271_1 == s_idx_271_2);
  assert(stage_v_271_1 == stage_v_271_2);
  assert(s_idx_272_1 == s_idx_272_2);
  assert(stage_v_272_1 == stage_v_272_2);
  assert(s_idx_273_1 == s_idx_273_2);
  assert(stage_v_273_1 == stage_v_273_2);
  assert(s_idx_274_1 == s_idx_274_2);
  assert(stage_v_274_1 == stage_v_274_2);
  assert(s_idx_275_1 == s_idx_275_2);
  assert(stage_v_275_1 == stage_v_275_2);
  assert(s_idx_276_1 == s_idx_276_2);
  assert(stage_v_276_1 == stage_v_276_2);
  assert(s_idx_277_1 == s_idx_277_2);
  assert(stage_v_277_1 == stage_v_277_2);
  assert(s_idx_278_1 == s_idx_278_2);
  assert(stage_v_278_1 == stage_v_278_2);
  assert(s_idx_279_1 == s_idx_279_2);
  assert(stage_v_279_1 == stage_v_279_2);
  assert(s_idx_280_1 == s_idx_280_2);
  assert(stage_v_280_1 == stage_v_280_2);
  assert(s_idx_281_1 == s_idx_281_2);
  assert(stage_v_281_1 == stage_v_281_2);
  assert(s_idx_282_1 == s_idx_282_2);
  assert(stage_v_282_1 == stage_v_282_2);
  assert(s_idx_283_1 == s_idx_283_2);
  assert(stage_v_283_1 == stage_v_283_2);
  assert(s_idx_284_1 == s_idx_284_2);
  assert(stage_v_284_1 == stage_v_284_2);
  assert(s_idx_285_1 == s_idx_285_2);
  assert(stage_v_285_1 == stage_v_285_2);
  assert(s_idx_286_1 == s_idx_286_2);
  assert(stage_v_286_1 == stage_v_286_2);
  assert(s_idx_287_1 == s_idx_287_2);
  assert(stage_v_287_1 == stage_v_287_2);
}


