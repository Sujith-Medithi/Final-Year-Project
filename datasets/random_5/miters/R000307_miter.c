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
struct MatrixBlock_R000307_713_0
{
  int dim;
  int trace;
  short determinant;
  short scale;
  unsigned char stride;
  short density;
  int buffer[3];
};
struct FilterState_R000307_713_1
{
  int prev_out;
  int damping;
  unsigned char cutoff;
  short prev_in;
  int gain_db;
  short mode;
  int buffer[3];
};
union PacketPayload_R000307_713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R000307_713_1
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
void fn_R000307_713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int mask_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_57_1) & 63;
  aux_2 = (aux_2 + mask_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_92_1 > 43)
  {
    acc_1 = ((acc_1 + (threshold_92_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_92_2 > 43)
  {
    acc_2 = ((acc_2 + (threshold_92_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_18_1)
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

  switch (metric_18_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_57_1 == mask_57_2);
  assert(threshold_92_1 == threshold_92_2);
  assert(metric_18_1 == metric_18_2);
}

int fn_R000307_713_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_57) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_92 > 43)
  {
    acc = ((acc + (threshold_92 * 2)) + 5) & 127;
    aux ^= threshold_92 & 15;
  }
  else
  {
    acc = ((acc - threshold_92) + 11) & 127;
    aux += 3;
  }
  int metric_18 = (aux + st.buffer[1]) & 3;
  switch (metric_18)
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

void fn_R000307_713_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int segment_32_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int segment_32_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + segment_32_1) & 63;
  aux_2 = (aux_2 + segment_32_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_37_1 > 11)
  {
    acc_1 = ((acc_1 + (scale_37_1 * 2)) + 5) & 127;
    aux_1 ^= scale_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_37_2 > 11)
  {
    acc_2 = ((acc_2 + (scale_37_2 * 2)) + 5) & 127;
    aux_2 ^= scale_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_37_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_66_1 = local_arr_1[aux_1 % 3];
  int stride_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_32_1 == segment_32_2);
  assert(scale_37_1 == scale_37_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_66_1 == stride_66_2);
}

int fn_R000307_713_1(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int segment_32 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + segment_32) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_37 > 11)
  {
    acc = ((acc + (scale_37 * 2)) + 5) & 127;
    aux ^= scale_37 & 15;
  }
  else
  {
    acc = ((acc - scale_37) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_66 = local_arr[aux % 3];
  acc = (acc + (stride_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_47_1 = local_arr_1[aux_1 % 3];
  int stride_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_47_1 == stride_47_2);
}

int fn_R000307_713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int stride_47 = local_arr[aux % 3];
  acc = (acc + (stride_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_93_1 = local_arr_1[aux_1 % 3];
  int sample_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_93_2 * 2)) & 127;
  int margin_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_34_1 > 29)
  {
    acc_1 = ((acc_1 + (margin_34_1 * 2)) + 5) & 127;
    aux_1 ^= margin_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_34_2 > 29)
  {
    acc_2 = ((acc_2 + (margin_34_2 * 2)) + 5) & 127;
    aux_2 ^= margin_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_34_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_93_1 == sample_93_2);
  assert(margin_34_1 == margin_34_2);
}

int fn_R000307_713_3(int p0, int p1)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int sample_93 = local_arr[aux % 3];
  acc = (acc + (sample_93 * 2)) & 127;
  int margin_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_34 > 29)
  {
    acc = ((acc + (margin_34 * 2)) + 5) & 127;
    aux ^= margin_34 & 15;
  }
  else
  {
    acc = ((acc - margin_34) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_49_1 = local_arr_1[aux_1 % 3];
  int scale_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_49_2 * 2)) & 127;
  int damping_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_49_1 > 23)
  {
    acc_1 = ((acc_1 + (damping_49_1 * 2)) + 5) & 127;
    aux_1 ^= damping_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_49_2 > 23)
  {
    acc_2 = ((acc_2 + (damping_49_2 * 2)) + 5) & 127;
    aux_2 ^= damping_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_49_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_49_1 == scale_49_2);
  assert(damping_49_1 == damping_49_2);
}

int fn_R000307_713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int scale_49 = local_arr[aux % 3];
  acc = (acc + (scale_49 * 2)) & 127;
  int damping_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_49 > 23)
  {
    acc = ((acc + (damping_49 * 2)) + 5) & 127;
    aux ^= damping_49 & 15;
  }
  else
  {
    acc = ((acc - damping_49) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int tracker_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_56_1) & 63;
  aux_2 = (aux_2 + tracker_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_75_1 > 18)
  {
    acc_1 = ((acc_1 + (threshold_75_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_75_2 > 18)
  {
    acc_2 = ((acc_2 + (threshold_75_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_32_1 = local_arr_1[aux_1 % 3];
  int coefficient_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_32_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_56_1 == tracker_56_2);
  assert(threshold_75_1 == threshold_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_32_1 == coefficient_32_2);
}

int fn_R000307_713_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_56) & 63;
  acc ^= aux;
  int threshold_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_75 > 18)
  {
    acc = ((acc + (threshold_75 * 2)) + 5) & 127;
    aux ^= threshold_75 & 15;
  }
  else
  {
    acc = ((acc - threshold_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int coefficient_32 = local_arr[aux % 3];
  acc = (acc + (coefficient_32 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_71_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_71_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_71_1) & 63;
  aux_2 = (aux_2 + vector_71_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_71_1 == vector_71_2);
}

int fn_R000307_713_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_71 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_71) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000307_713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_31_1 = local_arr_1[aux_1 % 3];
  int accumulator_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_31_2 * 2)) & 127;
  int bound_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_64_1 > 35)
  {
    acc_1 = ((acc_1 + (bound_64_1 * 2)) + 5) & 127;
    aux_1 ^= bound_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_64_2 > 35)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_31_1 == accumulator_31_2);
  assert(bound_64_1 == bound_64_2);
}

int fn_R000307_713_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_31 = local_arr[aux % 3];
  acc = (acc + (accumulator_31 * 2)) & 127;
  int bound_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_64 > 35)
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

void fn_R000307_713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_44_1 = local_arr_1[aux_1 % 3];
  int pivot_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_44_2 * 2)) & 127;
  int parity_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_56_1) & 63;
  aux_2 = (aux_2 + parity_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_44_1 == pivot_44_2);
  assert(parity_56_1 == parity_56_2);
}

int fn_R000307_713_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int pivot_44 = local_arr[aux % 3];
  acc = (acc + (pivot_44 * 2)) & 127;
  int parity_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_56) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000307_713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int margin_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_44_1) & 63;
  aux_2 = (aux_2 + margin_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_77_1 > 31)
  {
    acc_1 = ((acc_1 + (cursor_77_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_77_2 > 31)
  {
    acc_2 = ((acc_2 + (cursor_77_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_77_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_44_1 == margin_44_2);
  assert(cursor_77_1 == cursor_77_2);
}

int fn_R000307_713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_44) & 63;
  acc ^= aux;
  int cursor_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_77 > 31)
  {
    acc = ((acc + (cursor_77 * 2)) + 5) & 127;
    aux ^= cursor_77 & 15;
  }
  else
  {
    acc = ((acc - cursor_77) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int phase_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_44_1) & 63;
  aux_2 = (aux_2 + phase_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_67_1)
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

  switch (window_67_2)
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

  int checksum_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_79_1 > 28)
  {
    acc_1 = ((acc_1 + (checksum_79_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_79_2 > 28)
  {
    acc_2 = ((acc_2 + (checksum_79_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_69_1 = local_arr_1[aux_1 % 3];
  int tally_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_44_1 == phase_44_2);
  assert(window_67_1 == window_67_2);
  assert(checksum_79_1 == checksum_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_69_1 == tally_69_2);
}

int fn_R000307_713_10(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int phase_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_44) & 63;
  acc ^= aux;
  int window_67 = (aux + st.buffer[1]) & 3;
  switch (window_67)
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

  int checksum_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_79 > 28)
  {
    acc = ((acc + (checksum_79 * 2)) + 5) & 127;
    aux ^= checksum_79 & 15;
  }
  else
  {
    acc = ((acc - checksum_79) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int tally_69 = local_arr[aux % 3];
  acc = (acc + (tally_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_85_1 = local_arr_1[aux_1 % 3];
  int scale_85_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_85_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_85_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
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

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_85_1 == scale_85_2);
  assert(damping_11_1 == damping_11_2);
}

int fn_R000307_713_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int local_arr[3] = {4, 9, 15};
  int scale_85 = local_arr[aux % 3];
  acc = (acc + (scale_85 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
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

  return (acc + aux) & 255;
}

void fn_R000307_713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int damping_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_65_1)
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

  switch (damping_65_2)
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

  int stride_52_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_52_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_52_1 > 21)
  {
    acc_1 = ((acc_1 + (stride_52_1 * 2)) + 5) & 127;
    aux_1 ^= stride_52_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_52_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_52_2 > 21)
  {
    acc_2 = ((acc_2 + (stride_52_2 * 2)) + 5) & 127;
    aux_2 ^= stride_52_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_52_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_65_1 == damping_65_2);
  assert(stride_52_1 == stride_52_2);
}

int fn_R000307_713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int damping_65 = (aux + st.buffer[1]) & 3;
  switch (damping_65)
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

  int stride_52 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_52 > 21)
  {
    acc = ((acc + (stride_52 * 2)) + 5) & 127;
    aux ^= stride_52 & 15;
  }
  else
  {
    acc = ((acc - stride_52) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int offset_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_87_1)
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

  switch (offset_87_2)
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

  int delta_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_62_1) & 63;
  aux_2 = (aux_2 + delta_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_99_1 > 44)
  {
    acc_1 = ((acc_1 + (cursor_99_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_99_2 > 44)
  {
    acc_2 = ((acc_2 + (cursor_99_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_99_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_87_1 == offset_87_2);
  assert(delta_62_1 == delta_62_2);
  assert(cursor_99_1 == cursor_99_2);
}

int fn_R000307_713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int offset_87 = (aux + st.buffer[1]) & 3;
  switch (offset_87)
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

  int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_62) & 63;
  acc ^= aux;
  int cursor_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_99 > 44)
  {
    acc = ((acc + (cursor_99 * 2)) + 5) & 127;
    aux ^= cursor_99 & 15;
  }
  else
  {
    acc = ((acc - cursor_99) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_20_1 = local_arr_1[aux_1 % 3];
  int offset_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_20_2 * 2)) & 127;
  int index_reg_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_11_1)
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

  switch (index_reg_11_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_20_1 == offset_20_2);
  assert(index_reg_11_1 == index_reg_11_2);
}

int fn_R000307_713_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_20 = local_arr[aux % 3];
  acc = (acc + (offset_20 * 2)) & 127;
  int index_reg_11 = (aux + st.buffer[1]) & 3;
  switch (index_reg_11)
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

void fn_R000307_713_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int scale_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_84_1) & 63;
  aux_2 = (aux_2 + scale_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_34_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_34_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_34_1 > 48)
  {
    acc_1 = ((acc_1 + (mask_34_1 * 2)) + 5) & 127;
    aux_1 ^= mask_34_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_34_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_34_2 > 48)
  {
    acc_2 = ((acc_2 + (mask_34_2 * 2)) + 5) & 127;
    aux_2 ^= mask_34_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_34_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_84_1 == scale_84_2);
  assert(mask_34_1 == mask_34_2);
}

int fn_R000307_713_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_84) & 63;
  acc ^= aux;
  int mask_34 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_34 > 48)
  {
    acc = ((acc + (mask_34 * 2)) + 5) & 127;
    aux ^= mask_34 & 15;
  }
  else
  {
    acc = ((acc - mask_34) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_16_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_98_1) & 63;
  aux_2 = (aux_2 + coefficient_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_62_1 = local_arr_1[aux_1 % 3];
  int margin_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_62_2 * 2)) & 127;
  int mask_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_92_1 > 39)
  {
    acc_1 = ((acc_1 + (mask_92_1 * 2)) + 5) & 127;
    aux_1 ^= mask_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_92_2 > 39)
  {
    acc_2 = ((acc_2 + (mask_92_2 * 2)) + 5) & 127;
    aux_2 ^= mask_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_92_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_98_1 == coefficient_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_62_1 == margin_62_2);
  assert(mask_92_1 == mask_92_2);
}

int fn_R000307_713_16(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_98) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int margin_62 = local_arr[aux % 3];
  acc = (acc + (margin_62 * 2)) & 127;
  int mask_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_92 > 39)
  {
    acc = ((acc + (mask_92 * 2)) + 5) & 127;
    aux ^= mask_92 & 15;
  }
  else
  {
    acc = ((acc - mask_92) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int stride_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_92_1 > 11)
  {
    acc_1 = ((acc_1 + (stride_92_1 * 2)) + 5) & 127;
    aux_1 ^= stride_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_92_2 > 11)
  {
    acc_2 = ((acc_2 + (stride_92_2 * 2)) + 5) & 127;
    aux_2 ^= stride_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_92_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_60_1) & 63;
  aux_2 = (aux_2 + coefficient_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_85_1)
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

  switch (weight_85_2)
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
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_92_1 == stride_92_2);
  assert(coefficient_60_1 == coefficient_60_2);
  assert(weight_85_1 == weight_85_2);
}

int fn_R000307_713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int stride_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_92 > 11)
  {
    acc = ((acc + (stride_92 * 2)) + 5) & 127;
    aux ^= stride_92 & 15;
  }
  else
  {
    acc = ((acc - stride_92) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_60) & 63;
  acc ^= aux;
  int weight_85 = (aux + st.buffer[1]) & 3;
  switch (weight_85)
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

void fn_R000307_713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int mask_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_56_1)
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

  switch (mask_56_2)
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

  int bound_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_92_1) & 63;
  aux_2 = (aux_2 + bound_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_56_1 == mask_56_2);
  assert(bound_92_1 == bound_92_2);
}

int fn_R000307_713_18(int p0, int p1)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int mask_56 = (aux + st.buffer[1]) & 3;
  switch (mask_56)
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

  int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int parity_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_43_1)
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

  switch (parity_43_2)
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

  int cursor_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_80_1 > 32)
  {
    acc_1 = ((acc_1 + (cursor_80_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_80_2 > 32)
  {
    acc_2 = ((acc_2 + (cursor_80_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_80_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_87_1 = local_arr_1[aux_1 % 3];
  int threshold_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_87_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_43_1 == parity_43_2);
  assert(cursor_80_1 == cursor_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_87_1 == threshold_87_2);
}

int fn_R000307_713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int parity_43 = (aux + st.buffer[1]) & 3;
  switch (parity_43)
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

  int cursor_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_80 > 32)
  {
    acc = ((acc + (cursor_80 * 2)) + 5) & 127;
    aux ^= cursor_80 & 15;
  }
  else
  {
    acc = ((acc - cursor_80) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_87 = local_arr[aux % 3];
  acc = (acc + (threshold_87 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int phase_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_35_1 > 19)
  {
    acc_1 = ((acc_1 + (phase_35_1 * 2)) + 5) & 127;
    aux_1 ^= phase_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_35_2 > 19)
  {
    acc_2 = ((acc_2 + (phase_35_2 * 2)) + 5) & 127;
    aux_2 ^= phase_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_35_1 == phase_35_2);
}

int fn_R000307_713_20(int p0, int p1)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int phase_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_35 > 19)
  {
    acc = ((acc + (phase_35 * 2)) + 5) & 127;
    aux ^= phase_35 & 15;
  }
  else
  {
    acc = ((acc - phase_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_70_1 = local_arr_1[aux_1 % 3];
  int checksum_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_70_2 * 2)) & 127;
  int anchor_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_73_1 > 35)
  {
    acc_1 = ((acc_1 + (anchor_73_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_73_2 > 35)
  {
    acc_2 = ((acc_2 + (anchor_73_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_70_1 == checksum_70_2);
  assert(anchor_73_1 == anchor_73_2);
}

int fn_R000307_713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int local_arr[3] = {4, 9, 15};
  int checksum_70 = local_arr[aux % 3];
  acc = (acc + (checksum_70 * 2)) & 127;
  int anchor_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_73 > 35)
  {
    acc = ((acc + (anchor_73 * 2)) + 5) & 127;
    aux ^= anchor_73 & 15;
  }
  else
  {
    acc = ((acc - anchor_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000307_713_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st_1 = {0};
  struct MatrixBlock_R000307_713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int bound_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_11_1) & 63;
  aux_2 = (aux_2 + bound_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_56_1 = local_arr_1[aux_1 % 3];
  int threshold_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_56_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.dim == st_2.dim);
  assert(st_1.trace == st_2.trace);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_11_1 == bound_11_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_56_1 == threshold_56_2);
}

int fn_R000307_713_22(int p0, int p1)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000307_713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int bound_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_11) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int threshold_56 = local_arr[aux % 3];
  acc = (acc + (threshold_56 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000307_713_23_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st_1 = {0};
  struct FilterState_R000307_713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int mask_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_63_1)
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

  switch (mask_63_2)
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

  int coefficient_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_39_1 > 24)
  {
    acc_1 = ((acc_1 + (coefficient_39_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_39_2 > 24)
  {
    acc_2 = ((acc_2 + (coefficient_39_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.mode == st_2.mode);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_63_1 == mask_63_2);
  assert(coefficient_39_1 == coefficient_39_2);
}

int fn_R000307_713_23(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000307_713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int mask_63 = (aux + st.buffer[1]) & 3;
  switch (mask_63)
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

  int coefficient_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_39 > 24)
  {
    acc = ((acc + (coefficient_39 * 2)) + 5) & 127;
    aux ^= coefficient_39 & 15;
  }
  else
  {
    acc = ((acc - coefficient_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000307_0_1;
  int sec_r000307_0_2;
  int sec_r000307_1_1;
  int sec_r000307_1_2;
  int sec_r000307_2_1;
  int sec_r000307_2_2;
  int sec_r000307_3_1;
  int sec_r000307_3_2;
  int sec_r000307_4_1;
  int sec_r000307_4_2;
  int sec_r000307_5_1;
  int sec_r000307_5_2;
  int sec_r000307_6_1;
  int sec_r000307_6_2;
  int sec_r000307_7_1;
  int sec_r000307_7_2;
  int sec_r000307_8_1;
  int sec_r000307_8_2;
  int sec_r000307_9_1;
  int sec_r000307_9_2;
  int sec_r000307_10_1;
  int sec_r000307_10_2;
  int sec_r000307_11_1;
  int sec_r000307_11_2;
  int sec_r000307_12_1;
  int sec_r000307_12_2;
  int sec_r000307_13_1;
  int sec_r000307_13_2;
  int sec_r000307_14_1;
  int sec_r000307_14_2;
  int sec_r000307_15_1;
  int sec_r000307_15_2;
  int pub_r000307_0_1;
  int pub_r000307_0_2;
  int pub_r000307_1_1;
  int pub_r000307_1_2;
  int pub_r000307_2_1;
  int pub_r000307_2_2;
  int pub_r000307_3_1;
  int pub_r000307_3_2;
  int pub_r000307_4_1;
  int pub_r000307_4_2;
  int pub_r000307_5_1;
  int pub_r000307_5_2;
  int pub_r000307_6_1;
  int pub_r000307_6_2;
  int pub_r000307_7_1;
  int pub_r000307_7_2;
  int pub_r000307_8_1;
  int pub_r000307_8_2;
  int pub_r000307_9_1;
  int pub_r000307_9_2;
  int pub_r000307_10_1;
  int pub_r000307_10_2;
  int pub_r000307_11_1;
  int pub_r000307_11_2;
  int pub_r000307_12_1;
  int pub_r000307_12_2;
  int pub_r000307_13_1;
  int pub_r000307_13_2;
  int pub_r000307_14_1;
  int pub_r000307_14_2;
  int pub_r000307_15_1;
  int pub_r000307_15_2;
  int pub_r000307_16_1;
  int pub_r000307_16_2;
  int pub_r000307_17_1;
  int pub_r000307_17_2;
  int pub_r000307_18_1;
  int pub_r000307_18_2;
  int pub_r000307_19_1;
  int pub_r000307_19_2;
  int pub_r000307_20_1;
  int pub_r000307_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000307_0_1 >= (-100)) && (pub_r000307_0_1 <= 100));
  __CPROVER_assume((pub_r000307_0_2 >= (-100)) && (pub_r000307_0_2 <= 100));
  __CPROVER_assume((pub_r000307_1_1 >= (-100)) && (pub_r000307_1_1 <= 100));
  __CPROVER_assume((pub_r000307_1_2 >= (-100)) && (pub_r000307_1_2 <= 100));
  __CPROVER_assume((pub_r000307_2_1 >= (-100)) && (pub_r000307_2_1 <= 100));
  __CPROVER_assume((pub_r000307_2_2 >= (-100)) && (pub_r000307_2_2 <= 100));
  __CPROVER_assume((pub_r000307_3_1 >= (-100)) && (pub_r000307_3_1 <= 100));
  __CPROVER_assume((pub_r000307_3_2 >= (-100)) && (pub_r000307_3_2 <= 100));
  __CPROVER_assume((pub_r000307_4_1 >= (-100)) && (pub_r000307_4_1 <= 100));
  __CPROVER_assume((pub_r000307_4_2 >= (-100)) && (pub_r000307_4_2 <= 100));
  __CPROVER_assume((pub_r000307_5_1 >= (-100)) && (pub_r000307_5_1 <= 100));
  __CPROVER_assume((pub_r000307_5_2 >= (-100)) && (pub_r000307_5_2 <= 100));
  __CPROVER_assume((pub_r000307_6_1 >= (-100)) && (pub_r000307_6_1 <= 100));
  __CPROVER_assume((pub_r000307_6_2 >= (-100)) && (pub_r000307_6_2 <= 100));
  __CPROVER_assume((pub_r000307_7_1 >= (-100)) && (pub_r000307_7_1 <= 100));
  __CPROVER_assume((pub_r000307_7_2 >= (-100)) && (pub_r000307_7_2 <= 100));
  __CPROVER_assume((pub_r000307_8_1 >= (-100)) && (pub_r000307_8_1 <= 100));
  __CPROVER_assume((pub_r000307_8_2 >= (-100)) && (pub_r000307_8_2 <= 100));
  __CPROVER_assume((pub_r000307_9_1 >= (-100)) && (pub_r000307_9_1 <= 100));
  __CPROVER_assume((pub_r000307_9_2 >= (-100)) && (pub_r000307_9_2 <= 100));
  __CPROVER_assume((pub_r000307_10_1 >= (-100)) && (pub_r000307_10_1 <= 100));
  __CPROVER_assume((pub_r000307_10_2 >= (-100)) && (pub_r000307_10_2 <= 100));
  __CPROVER_assume((pub_r000307_11_1 >= (-100)) && (pub_r000307_11_1 <= 100));
  __CPROVER_assume((pub_r000307_11_2 >= (-100)) && (pub_r000307_11_2 <= 100));
  __CPROVER_assume((pub_r000307_12_1 >= (-100)) && (pub_r000307_12_1 <= 100));
  __CPROVER_assume((pub_r000307_12_2 >= (-100)) && (pub_r000307_12_2 <= 100));
  __CPROVER_assume((pub_r000307_13_1 >= (-100)) && (pub_r000307_13_1 <= 100));
  __CPROVER_assume((pub_r000307_13_2 >= (-100)) && (pub_r000307_13_2 <= 100));
  __CPROVER_assume((pub_r000307_14_1 >= (-100)) && (pub_r000307_14_1 <= 100));
  __CPROVER_assume((pub_r000307_14_2 >= (-100)) && (pub_r000307_14_2 <= 100));
  __CPROVER_assume((pub_r000307_15_1 >= (-100)) && (pub_r000307_15_1 <= 100));
  __CPROVER_assume((pub_r000307_15_2 >= (-100)) && (pub_r000307_15_2 <= 100));
  __CPROVER_assume((pub_r000307_16_1 >= (-100)) && (pub_r000307_16_1 <= 100));
  __CPROVER_assume((pub_r000307_16_2 >= (-100)) && (pub_r000307_16_2 <= 100));
  __CPROVER_assume((pub_r000307_17_1 >= (-100)) && (pub_r000307_17_1 <= 100));
  __CPROVER_assume((pub_r000307_17_2 >= (-100)) && (pub_r000307_17_2 <= 100));
  __CPROVER_assume((pub_r000307_18_1 >= (-100)) && (pub_r000307_18_1 <= 100));
  __CPROVER_assume((pub_r000307_18_2 >= (-100)) && (pub_r000307_18_2 <= 100));
  __CPROVER_assume((pub_r000307_19_1 >= (-100)) && (pub_r000307_19_1 <= 100));
  __CPROVER_assume((pub_r000307_19_2 >= (-100)) && (pub_r000307_19_2 <= 100));
  __CPROVER_assume((pub_r000307_20_1 >= (-100)) && (pub_r000307_20_1 <= 100));
  __CPROVER_assume((pub_r000307_20_2 >= (-100)) && (pub_r000307_20_2 <= 100));
  __CPROVER_assume((sec_r000307_0_1 >= 0) && (sec_r000307_0_1 <= 255));
  __CPROVER_assume((sec_r000307_0_2 >= 0) && (sec_r000307_0_2 <= 255));
  __CPROVER_assume((sec_r000307_1_1 >= 0) && (sec_r000307_1_1 <= 255));
  __CPROVER_assume((sec_r000307_1_2 >= 0) && (sec_r000307_1_2 <= 255));
  __CPROVER_assume((sec_r000307_2_1 >= 0) && (sec_r000307_2_1 <= 255));
  __CPROVER_assume((sec_r000307_2_2 >= 0) && (sec_r000307_2_2 <= 255));
  __CPROVER_assume((sec_r000307_3_1 >= 0) && (sec_r000307_3_1 <= 255));
  __CPROVER_assume((sec_r000307_3_2 >= 0) && (sec_r000307_3_2 <= 255));
  __CPROVER_assume((sec_r000307_4_1 >= 0) && (sec_r000307_4_1 <= 255));
  __CPROVER_assume((sec_r000307_4_2 >= 0) && (sec_r000307_4_2 <= 255));
  __CPROVER_assume((sec_r000307_5_1 >= 0) && (sec_r000307_5_1 <= 255));
  __CPROVER_assume((sec_r000307_5_2 >= 0) && (sec_r000307_5_2 <= 255));
  __CPROVER_assume((sec_r000307_6_1 >= 0) && (sec_r000307_6_1 <= 255));
  __CPROVER_assume((sec_r000307_6_2 >= 0) && (sec_r000307_6_2 <= 255));
  __CPROVER_assume((sec_r000307_7_1 >= 0) && (sec_r000307_7_1 <= 255));
  __CPROVER_assume((sec_r000307_7_2 >= 0) && (sec_r000307_7_2 <= 255));
  __CPROVER_assume((sec_r000307_8_1 >= 0) && (sec_r000307_8_1 <= 255));
  __CPROVER_assume((sec_r000307_8_2 >= 0) && (sec_r000307_8_2 <= 255));
  __CPROVER_assume((sec_r000307_9_1 >= 0) && (sec_r000307_9_1 <= 255));
  __CPROVER_assume((sec_r000307_9_2 >= 0) && (sec_r000307_9_2 <= 255));
  __CPROVER_assume((sec_r000307_10_1 >= 0) && (sec_r000307_10_1 <= 255));
  __CPROVER_assume((sec_r000307_10_2 >= 0) && (sec_r000307_10_2 <= 255));
  __CPROVER_assume((sec_r000307_11_1 >= 0) && (sec_r000307_11_1 <= 255));
  __CPROVER_assume((sec_r000307_11_2 >= 0) && (sec_r000307_11_2 <= 255));
  __CPROVER_assume((sec_r000307_12_1 >= 0) && (sec_r000307_12_1 <= 255));
  __CPROVER_assume((sec_r000307_12_2 >= 0) && (sec_r000307_12_2 <= 255));
  __CPROVER_assume((sec_r000307_13_1 >= 0) && (sec_r000307_13_1 <= 255));
  __CPROVER_assume((sec_r000307_13_2 >= 0) && (sec_r000307_13_2 <= 255));
  __CPROVER_assume((sec_r000307_14_1 >= 0) && (sec_r000307_14_1 <= 255));
  __CPROVER_assume((sec_r000307_14_2 >= 0) && (sec_r000307_14_2 <= 255));
  __CPROVER_assume((sec_r000307_15_1 >= 0) && (sec_r000307_15_1 <= 255));
  __CPROVER_assume((sec_r000307_15_2 >= 0) && (sec_r000307_15_2 <= 255));
  struct MatrixBlock_R000307_713_0 st_var_0_1 = {0};
  struct MatrixBlock_R000307_713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000307_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000307_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000307_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000307_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000307_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000307_0_2 + 7) & 15;
  struct FilterState_R000307_713_1 st_var_1_1 = {0};
  struct FilterState_R000307_713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000307_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000307_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000307_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000307_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000307_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000307_0_2 + 9) & 15;
  union PacketPayload_R000307_713_0 u_var_1;
  union PacketPayload_R000307_713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (5 & 31);
  int stage_v_0_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (5 & 31);
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  chk_sum_1 ^= (stage_v_0_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_0_2 << 1) & 127;
  int stage_v_1_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_1_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_1_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_1_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = 0;
  int stage_v_5_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_5_1 = ((stage_v_5_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_5_2 = ((stage_v_5_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  int stage_v_6_1 = ((st_var_0_1.buffer[0] * 2) + 25) & 63;
  int stage_v_6_2 = ((st_var_0_2.buffer[0] * 2) + 25) & 63;
  if (stage_v_6_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 50)
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
  if (stage_v_6_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 50)
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 53)
    {
      chk_sum_1 ^= stage_v_8_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_8_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 53)
    {
      chk_sum_2 ^= stage_v_8_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_9_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_9_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_9_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_9_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = (st_var_1_1.buffer[0] ^ 16) & 3;
  int stage_v_13_2 = (st_var_1_2.buffer[0] ^ 16) & 3;
  switch (stage_v_13_1)
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

  switch (stage_v_13_2)
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

  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = (st_var_0_1.buffer[0] ^ 19) & 3;
  int stage_v_16_2 = (st_var_0_2.buffer[0] ^ 19) & 3;
  switch (stage_v_16_1)
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

  switch (stage_v_16_2)
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

  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  int stage_v_20_1 = ((st_var_0_1.buffer[2] * 2) + 67) & 63;
  int stage_v_20_2 = ((st_var_0_2.buffer[2] * 2) + 67) & 63;
  if (stage_v_20_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_20_1) - 5) & 255;
    if (stage_v_20_1 > 38)
    {
      chk_sum_1 ^= stage_v_20_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_20_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_20_2) - 5) & 255;
    if (stage_v_20_2 > 38)
    {
      chk_sum_2 ^= stage_v_20_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
  int stage_v_23_1 = ((st_var_1_1.buffer[2] * 2) + 76) & 63;
  int stage_v_23_2 = ((st_var_1_2.buffer[2] * 2) + 76) & 63;
  if (stage_v_23_1 > 13)
  {
    out_sink_1 = ((out_sink_1 + stage_v_23_1) - 5) & 255;
    if (stage_v_23_1 > 28)
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
  if (stage_v_23_2 > 13)
  {
    out_sink_2 = ((out_sink_2 + stage_v_23_2) - 5) & 255;
    if (stage_v_23_2 > 28)
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
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

  switch (stage_v_26_2)
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

  int stage_v_27_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (32 & 31);
  int stage_v_27_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (32 & 31);
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= (stage_v_27_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_27_2 << 1) & 127;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = ((st_var_1_1.buffer[2] * 2) + 94) & 63;
  int stage_v_29_2 = ((st_var_1_2.buffer[2] * 2) + 94) & 63;
  if (stage_v_29_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_29_1) - 5) & 255;
    if (stage_v_29_1 > 25)
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
  if (stage_v_29_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_29_2) - 5) & 255;
    if (stage_v_29_2 > 25)
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
  int stage_v_30_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (35 & 31);
  int stage_v_30_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (35 & 31);
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= (stage_v_30_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_30_2 << 1) & 127;
  int stage_v_31_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (36 & 31);
  int stage_v_31_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (36 & 31);
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= (stage_v_31_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_31_2 << 1) & 127;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 33) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 33) & 15;
  int stage_v_32_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_32_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  chk_sum_1 ^= stage_v_32_1;
  chk_sum_2 ^= stage_v_32_2;
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
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 35) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 35) & 15;
  int stage_v_34_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_34_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  chk_sum_1 ^= stage_v_34_1;
  chk_sum_2 ^= stage_v_34_2;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
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

  int stage_v_37_1 = (st_var_1_1.buffer[0] ^ 40) & 3;
  int stage_v_37_2 = (st_var_1_2.buffer[0] ^ 40) & 3;
  switch (stage_v_37_1)
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

  switch (stage_v_37_2)
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

  int stage_v_38_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (43 & 31);
  int stage_v_38_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (43 & 31);
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  chk_sum_1 ^= (stage_v_38_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_38_2 << 1) & 127;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_39_1 = ((stage_v_39_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_39_2 = ((stage_v_39_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_40_1 = ((stage_v_40_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_40_2 = ((stage_v_40_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_41_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_42_1 = ((st_var_0_1.buffer[0] * 2) + 133) & 63;
  int stage_v_42_2 = ((st_var_0_2.buffer[0] * 2) + 133) & 63;
  if (stage_v_42_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + stage_v_42_1) - 5) & 255;
    if (stage_v_42_1 > 53)
    {
      chk_sum_1 ^= stage_v_42_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_42_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + stage_v_42_2) - 5) & 255;
    if (stage_v_42_2 > 53)
    {
      chk_sum_2 ^= stage_v_42_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_43_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_43_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_44_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (49 & 31);
  int stage_v_44_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (49 & 31);
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  chk_sum_1 ^= (stage_v_44_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_44_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 46) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 46) & 15;
  int stage_v_45_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_45_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  chk_sum_1 ^= stage_v_45_1;
  chk_sum_2 ^= stage_v_45_2;
  int stage_v_46_1 = table_1[2];
  int stage_v_46_2 = table_2[2];
  table_1[2] = (table_1[3] + 93) & 63;
  table_2[2] = (table_2[3] + 93) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (52 & 31);
  int stage_v_47_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (52 & 31);
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  chk_sum_1 ^= (stage_v_47_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_47_2 << 1) & 127;
  int stage_v_48_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (53 & 31);
  int stage_v_48_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (53 & 31);
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  chk_sum_1 ^= (stage_v_48_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_48_2 << 1) & 127;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 50) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 50) & 15;
  int stage_v_49_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_49_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  chk_sum_1 ^= stage_v_49_1;
  chk_sum_2 ^= stage_v_49_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 51) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 51) & 15;
  int stage_v_50_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_50_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  chk_sum_1 ^= stage_v_50_1;
  chk_sum_2 ^= stage_v_50_2;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((sec_r000307_14_1 & 1) != 0)
  {
    if ((sec_r000307_15_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((sec_r000307_14_2 & 1) != 0)
  {
    if ((sec_r000307_15_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000307_0_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000307_0_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((sec_r000307_14_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((sec_r000307_14_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((sec_r000307_13_1 & 1) != 0)
  {
    if ((sec_r000307_6_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000307_1_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000307_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000307_1_1 + 7) & 127;
  }
  if ((sec_r000307_13_2 & 1) != 0)
  {
    if ((sec_r000307_6_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000307_1_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000307_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000307_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000307_1_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000307_1_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000307_6_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000307_6_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000307_6_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000307_6_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((sec_r000307_2_1 & 1) != 0)
  {
    if ((sec_r000307_15_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((sec_r000307_2_2 & 1) != 0)
  {
    if ((sec_r000307_15_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000307_12_1 & 1) != 0)
  {
    if ((sec_r000307_15_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((sec_r000307_12_2 & 1) != 0)
  {
    if ((sec_r000307_15_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000307_10_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000307_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000307_10_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000307_10_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000307_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000307_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((sec_r000307_6_1 & 1) != 0)
  {
    if ((sec_r000307_0_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000307_2_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000307_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000307_2_1 + 7) & 127;
  }
  if ((sec_r000307_6_2 & 1) != 0)
  {
    if ((sec_r000307_0_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000307_2_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000307_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000307_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000307_6_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000307_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000307_6_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000307_6_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000307_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000307_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000307_5_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000307_9_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000307_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000307_9_1 + 7) & 127;
  }
  if ((sec_r000307_5_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000307_9_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000307_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000307_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000307_10_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((sec_r000307_10_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((sec_r000307_12_1 & 1) != 0)
  {
    if ((sec_r000307_11_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((sec_r000307_12_2 & 1) != 0)
  {
    if ((sec_r000307_11_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000307_5_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000307_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000307_5_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000307_5_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000307_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000307_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000307_10_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000307_10_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000307_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000307_10_1 + 7) & 127;
  }
  if ((sec_r000307_10_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000307_10_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000307_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000307_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000307_10_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000307_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000307_10_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000307_10_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000307_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000307_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000307_8_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000307_1_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000307_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000307_1_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000307_8_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000307_1_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000307_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000307_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((sec_r000307_3_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((sec_r000307_3_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000307_4_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((sec_r000307_4_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000307_15_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000307_15_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000307_0_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000307_0_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((sec_r000307_13_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((sec_r000307_13_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000307_11_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000307_11_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((sec_r000307_11_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000307_0_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000307_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000307_0_1 + 7) & 127;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((sec_r000307_11_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000307_0_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000307_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000307_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000307_15_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000307_15_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((sec_r000307_7_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((sec_r000307_7_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000307_9_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000307_9_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((sec_r000307_5_1 & 1) != 0)
  {
    if ((sec_r000307_1_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((sec_r000307_5_2 & 1) != 0)
  {
    if ((sec_r000307_1_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((stage_v_65_1 & 1) != 0)
  {
    if ((sec_r000307_1_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_65_2 & 1) != 0)
  {
    if ((sec_r000307_1_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000307_18_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000307_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000307_18_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000307_18_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000307_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000307_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((sec_r000307_4_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000307_0_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000307_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000307_0_1 + 7) & 127;
  }
  if ((sec_r000307_4_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000307_0_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000307_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000307_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_56_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000307_5_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000307_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000307_5_1 + 7) & 127;
  }
  if ((stage_v_56_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000307_5_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000307_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000307_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((sec_r000307_3_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000307_18_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000307_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000307_18_1 + 7) & 127;
  }
  if ((sec_r000307_3_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000307_18_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000307_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000307_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000307_5_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000307_13_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000307_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000307_13_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000307_5_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000307_13_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000307_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000307_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000307_0_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000307_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000307_0_1 + 7) & 127;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000307_0_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000307_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000307_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((sec_r000307_1_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((sec_r000307_1_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000307_6_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000307_13_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000307_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000307_13_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000307_6_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000307_13_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000307_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000307_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000307_0_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000307_16_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000307_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000307_16_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000307_0_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000307_16_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000307_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000307_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000307_12_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000307_6_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000307_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000307_6_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000307_12_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000307_6_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000307_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000307_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((sec_r000307_2_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((sec_r000307_2_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((sec_r000307_10_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((sec_r000307_10_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((sec_r000307_4_1 & 1) != 0)
  {
    if ((sec_r000307_5_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000307_4_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000307_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000307_4_1 + 7) & 127;
  }
  if ((sec_r000307_4_2 & 1) != 0)
  {
    if ((sec_r000307_5_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000307_4_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000307_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000307_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((sec_r000307_14_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((sec_r000307_14_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_102_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000307_10_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000307_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000307_10_1 + 7) & 127;
  }
  if ((stage_v_102_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000307_10_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000307_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000307_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((sec_r000307_1_1 & 1) != 0)
  {
    if ((sec_r000307_1_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000307_9_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000307_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000307_9_1 + 7) & 127;
  }
  if ((sec_r000307_1_2 & 1) != 0)
  {
    if ((sec_r000307_1_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000307_9_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000307_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000307_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((sec_r000307_11_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((sec_r000307_11_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_99_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000307_2_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000307_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000307_2_1 + 7) & 127;
  }
  if ((stage_v_99_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000307_2_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000307_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000307_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_59_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000307_1_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000307_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000307_1_1 + 7) & 127;
  }
  if ((stage_v_59_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000307_1_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000307_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000307_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000307_12_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((sec_r000307_12_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_91_1 & 1) != 0)
  {
    if ((sec_r000307_10_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000307_1_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000307_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000307_1_1 + 7) & 127;
  }
  if ((stage_v_91_2 & 1) != 0)
  {
    if ((sec_r000307_10_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000307_1_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000307_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000307_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000307_13_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000307_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000307_13_1 + 7) & 127;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000307_13_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000307_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000307_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((sec_r000307_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000307_2_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000307_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000307_2_1 + 7) & 127;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((sec_r000307_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000307_2_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000307_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000307_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((sec_r000307_11_1 & 1) != 0)
  {
    if ((sec_r000307_9_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000307_18_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000307_18_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000307_18_1 + 7) & 127;
  }
  if ((sec_r000307_11_2 & 1) != 0)
  {
    if ((sec_r000307_9_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000307_18_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000307_18_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000307_18_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000307_5_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000307_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000307_5_1 + 7) & 127;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000307_5_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000307_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000307_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000307_2_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((sec_r000307_2_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((sec_r000307_12_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((sec_r000307_12_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000307_11_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000307_9_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000307_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000307_9_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000307_11_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000307_9_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000307_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000307_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((sec_r000307_9_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000307_1_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000307_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000307_1_1 + 7) & 127;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((sec_r000307_9_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000307_1_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000307_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000307_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000307_1_1 & 1) != 0)
  {
    if ((sec_r000307_7_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000307_5_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000307_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000307_5_1 + 7) & 127;
  }
  if ((sec_r000307_1_2 & 1) != 0)
  {
    if ((sec_r000307_7_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000307_5_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000307_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000307_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000307_13_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000307_13_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000307_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000307_13_1 + 7) & 127;
  }
  if ((sec_r000307_13_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000307_13_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000307_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000307_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((sec_r000307_13_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000307_7_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000307_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000307_7_1 + 7) & 127;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((sec_r000307_13_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000307_7_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000307_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000307_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000307_9_1 & 2) != 0)
    {
      stage_v_126_1 = (pub_r000307_6_1 + 31) & 127;
    }
    else
    {
      stage_v_126_1 = (pub_r000307_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_1 = (pub_r000307_6_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000307_9_2 & 2) != 0)
    {
      stage_v_126_2 = (pub_r000307_6_2 + 31) & 127;
    }
    else
    {
      stage_v_126_2 = (pub_r000307_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_126_2 = (pub_r000307_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = 0;
  int stage_v_127_2 = 0;
  if ((stage_v_110_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_127_1 = (pub_r000307_8_1 + 31) & 127;
    }
    else
    {
      stage_v_127_1 = (pub_r000307_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_1 = (pub_r000307_8_1 + 7) & 127;
  }
  if ((stage_v_110_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_127_2 = (pub_r000307_8_2 + 31) & 127;
    }
    else
    {
      stage_v_127_2 = (pub_r000307_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_127_2 = (pub_r000307_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r000307_14_1 & 2) != 0)
    {
      stage_v_128_1 = (pub_r000307_20_1 + 31) & 127;
    }
    else
    {
      stage_v_128_1 = (pub_r000307_20_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_1 = (pub_r000307_20_1 + 7) & 127;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r000307_14_2 & 2) != 0)
    {
      stage_v_128_2 = (pub_r000307_20_2 + 31) & 127;
    }
    else
    {
      stage_v_128_2 = (pub_r000307_20_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_128_2 = (pub_r000307_20_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_129_1 = (pub_r000307_19_1 + 31) & 127;
    }
    else
    {
      stage_v_129_1 = (pub_r000307_19_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_1 = (pub_r000307_19_1 + 7) & 127;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_129_2 = (pub_r000307_19_2 + 31) & 127;
    }
    else
    {
      stage_v_129_2 = (pub_r000307_19_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_129_2 = (pub_r000307_19_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = 0;
  int stage_v_130_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000307_4_1 & 2) != 0)
    {
      stage_v_130_1 = (pub_r000307_15_1 + 31) & 127;
    }
    else
    {
      stage_v_130_1 = (pub_r000307_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_1 = (pub_r000307_15_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000307_4_2 & 2) != 0)
    {
      stage_v_130_2 = (pub_r000307_15_2 + 31) & 127;
    }
    else
    {
      stage_v_130_2 = (pub_r000307_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_130_2 = (pub_r000307_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  if ((sec_r000307_11_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_131_1 = (pub_r000307_13_1 + 31) & 127;
    }
    else
    {
      stage_v_131_1 = (pub_r000307_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_1 = (pub_r000307_13_1 + 7) & 127;
  }
  if ((sec_r000307_11_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_131_2 = (pub_r000307_13_2 + 31) & 127;
    }
    else
    {
      stage_v_131_2 = (pub_r000307_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_131_2 = (pub_r000307_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = 0;
  int stage_v_132_2 = 0;
  if ((stage_v_89_1 & 1) != 0)
  {
    if ((sec_r000307_2_1 & 2) != 0)
    {
      stage_v_132_1 = (pub_r000307_3_1 + 31) & 127;
    }
    else
    {
      stage_v_132_1 = (pub_r000307_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_1 = (pub_r000307_3_1 + 7) & 127;
  }
  if ((stage_v_89_2 & 1) != 0)
  {
    if ((sec_r000307_2_2 & 2) != 0)
    {
      stage_v_132_2 = (pub_r000307_3_2 + 31) & 127;
    }
    else
    {
      stage_v_132_2 = (pub_r000307_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_132_2 = (pub_r000307_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  if ((sec_r000307_1_1 & 1) != 0)
  {
    if ((sec_r000307_8_1 & 2) != 0)
    {
      stage_v_133_1 = (pub_r000307_16_1 + 31) & 127;
    }
    else
    {
      stage_v_133_1 = (pub_r000307_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_1 = (pub_r000307_16_1 + 7) & 127;
  }
  if ((sec_r000307_1_2 & 1) != 0)
  {
    if ((sec_r000307_8_2 & 2) != 0)
    {
      stage_v_133_2 = (pub_r000307_16_2 + 31) & 127;
    }
    else
    {
      stage_v_133_2 = (pub_r000307_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_133_2 = (pub_r000307_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = 0;
  int stage_v_134_2 = 0;
  if ((stage_v_131_1 & 1) != 0)
  {
    if ((sec_r000307_3_1 & 2) != 0)
    {
      stage_v_134_1 = (pub_r000307_11_1 + 31) & 127;
    }
    else
    {
      stage_v_134_1 = (pub_r000307_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_1 = (pub_r000307_11_1 + 7) & 127;
  }
  if ((stage_v_131_2 & 1) != 0)
  {
    if ((sec_r000307_3_2 & 2) != 0)
    {
      stage_v_134_2 = (pub_r000307_11_2 + 31) & 127;
    }
    else
    {
      stage_v_134_2 = (pub_r000307_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_134_2 = (pub_r000307_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000307_11_1 != sec_r000307_11_2);
  __CPROVER_assume(sec_r000307_5_1 != sec_r000307_5_2);
  __CPROVER_assume(pub_r000307_7_1 == pub_r000307_7_2);
  __CPROVER_assume(pub_r000307_5_1 == pub_r000307_5_2);
  __CPROVER_assume(sec_r000307_4_1 != sec_r000307_4_2);
  __CPROVER_assume(sec_r000307_10_1 != sec_r000307_10_2);
  __CPROVER_assume(sec_r000307_2_1 != sec_r000307_2_2);
  __CPROVER_assume(pub_r000307_20_1 == pub_r000307_20_2);
  __CPROVER_assume(pub_r000307_19_1 == pub_r000307_19_2);
  __CPROVER_assume(pub_r000307_0_1 == pub_r000307_0_2);
  __CPROVER_assume(sec_r000307_6_1 != sec_r000307_6_2);
  __CPROVER_assume(pub_r000307_12_1 == pub_r000307_12_2);
  __CPROVER_assume(pub_r000307_1_1 == pub_r000307_1_2);
  __CPROVER_assume(pub_r000307_16_1 == pub_r000307_16_2);
  __CPROVER_assume(pub_r000307_4_1 == pub_r000307_4_2);
  __CPROVER_assume(sec_r000307_13_1 != sec_r000307_13_2);
  __CPROVER_assume(pub_r000307_15_1 == pub_r000307_15_2);
  __CPROVER_assume(sec_r000307_8_1 != sec_r000307_8_2);
  __CPROVER_assume(sec_r000307_15_1 != sec_r000307_15_2);
  __CPROVER_assume(pub_r000307_8_1 == pub_r000307_8_2);
  __CPROVER_assume(pub_r000307_2_1 == pub_r000307_2_2);
  __CPROVER_assume(sec_r000307_1_1 != sec_r000307_1_2);
  __CPROVER_assume(pub_r000307_14_1 == pub_r000307_14_2);
  __CPROVER_assume(pub_r000307_17_1 == pub_r000307_17_2);
  __CPROVER_assume(pub_r000307_13_1 == pub_r000307_13_2);
  __CPROVER_assume(sec_r000307_14_1 != sec_r000307_14_2);
  __CPROVER_assume(pub_r000307_3_1 == pub_r000307_3_2);
  __CPROVER_assume(pub_r000307_9_1 == pub_r000307_9_2);
  __CPROVER_assume(sec_r000307_0_1 != sec_r000307_0_2);
  __CPROVER_assume(sec_r000307_7_1 != sec_r000307_7_2);
  __CPROVER_assume(pub_r000307_11_1 == pub_r000307_11_2);
  __CPROVER_assume(pub_r000307_18_1 == pub_r000307_18_2);
  __CPROVER_assume(pub_r000307_10_1 == pub_r000307_10_2);
  __CPROVER_assume(sec_r000307_3_1 != sec_r000307_3_2);
  __CPROVER_assume(sec_r000307_9_1 != sec_r000307_9_2);
  __CPROVER_assume(pub_r000307_6_1 == pub_r000307_6_2);
  __CPROVER_assume(sec_r000307_12_1 != sec_r000307_12_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.mode == st_var_1_2.mode);
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
}


