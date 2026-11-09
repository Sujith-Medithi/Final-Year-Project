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
struct MatrixBlock_R001058_5813_0
{
  int scale;
  int dim;
  unsigned char stride;
  int density;
  short determinant;
  int buffer[3];
};
struct CipherContext_R001058_5813_1
{
  short counter;
  int tag;
  short nonce;
  int round_key;
  int iv;
  int buffer[3];
};
struct Vector3D_R001058_5813_2
{
  short heading;
  short coord_x;
  int norm_sq;
  int coord_z;
  int buffer[3];
};
union PacketPayload_R001058_5813_0
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
void fn_R001058_5813_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st_1 = {0};
  struct MatrixBlock_R001058_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_51_1 = local_arr_1[aux_1 % 3];
  int sample_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_51_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_76_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_76_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_76_1 > 41)
  {
    acc_1 = ((acc_1 + (pivot_76_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_76_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_76_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_76_2 > 41)
  {
    acc_2 = ((acc_2 + (pivot_76_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_76_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_76_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_85_1) & 63;
  aux_2 = (aux_2 + stride_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_51_1 == sample_51_2);
  assert(pivot_76_1 == pivot_76_2);
  assert(stride_85_1 == stride_85_2);
}

int fn_R001058_5813_0(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int local_arr[3] = {4, 9, 15};
  int sample_51 = local_arr[aux % 3];
  acc = (acc + (sample_51 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_76 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_76 > 41)
  {
    acc = ((acc + (pivot_76 * 2)) + 5) & 127;
    aux ^= pivot_76 & 15;
  }
  else
  {
    acc = ((acc - pivot_76) + 11) & 127;
    aux += 3;
  }
  int stride_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_85) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001058_5813_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_14_1) & 63;
  aux_2 = (aux_2 + metric_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_39_1 = 0;
  int tracker_39_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_39_1 = ((tracker_39_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_39_2 = ((tracker_39_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_39_1) & 127;
    acc_2 = (acc_2 + tracker_39_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
  assert(tracker_39_1 == tracker_39_2);
}

int fn_R001058_5813_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_14) & 63;
  acc ^= aux;
  int tracker_39 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_39 = ((tracker_39 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_39) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001058_5813_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st_1 = {0};
  struct MatrixBlock_R001058_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int quantum_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_38_1 > 24)
  {
    acc_1 = ((acc_1 + (quantum_38_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_38_2 > 24)
  {
    acc_2 = ((acc_2 + (quantum_38_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_38_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_38_1 == quantum_38_2);
}

int fn_R001058_5813_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int quantum_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_38 > 24)
  {
    acc = ((acc + (quantum_38 * 2)) + 5) & 127;
    aux ^= quantum_38 & 15;
  }
  else
  {
    acc = ((acc - quantum_38) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001058_5813_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st_1 = {0};
  struct CipherContext_R001058_5813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int segment_74_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_74_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_74_1)
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

  switch (segment_74_2)
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

  int tally_69_1 = 0;
  int tally_69_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tally_69_1 = ((tally_69_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_69_2 = ((tally_69_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_69_1) & 127;
    acc_2 = (acc_2 + tally_69_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_74_1 == segment_74_2);
  assert(tally_69_1 == tally_69_2);
}

int fn_R001058_5813_3(int p0, int p1, int p2)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int segment_74 = (aux + st.buffer[1]) & 3;
  switch (segment_74)
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

  int tally_69 = 0;
  for (int k = 0; k < 3; k++)
  {
    tally_69 = ((tally_69 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_69) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001058_5813_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int metric_77_1 = 0;
  int metric_77_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    metric_77_1 = ((metric_77_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_77_2 = ((metric_77_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_77_1) & 127;
    acc_2 = (acc_2 + metric_77_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_54_1 = local_arr_1[aux_1 % 3];
  int offset_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_77_1 == metric_77_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_54_1 == offset_54_2);
}

int fn_R001058_5813_4(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int metric_77 = 0;
  for (int k = 0; k < 3; k++)
  {
    metric_77 = ((metric_77 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_77) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int offset_54 = local_arr[aux % 3];
  acc = (acc + (offset_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001058_5813_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st_1 = {0};
  struct MatrixBlock_R001058_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_14_1) & 63;
  aux_2 = (aux_2 + metric_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_14_1 == metric_14_2);
}

int fn_R001058_5813_5(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001058_5813_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st_1 = {0};
  struct MatrixBlock_R001058_5813_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_19_1)
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

  switch (delta_19_2)
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

  int checksum_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_74_1) & 63;
  aux_2 = (aux_2 + checksum_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.determinant == st_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_19_1 == delta_19_2);
  assert(checksum_74_1 == checksum_74_2);
}

int fn_R001058_5813_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001058_5813_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_19 = (aux + st.buffer[1]) & 3;
  switch (delta_19)
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

  int checksum_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001058_5813_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_54_1 = local_arr_1[aux_1 % 3];
  int anchor_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_54_2 * 2)) & 127;
  int metric_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_94_1 > 25)
  {
    acc_1 = ((acc_1 + (metric_94_1 * 2)) + 5) & 127;
    aux_1 ^= metric_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_94_2 > 25)
  {
    acc_2 = ((acc_2 + (metric_94_2 * 2)) + 5) & 127;
    aux_2 ^= metric_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_94_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_54_1 == anchor_54_2);
  assert(metric_94_1 == metric_94_2);
}

int fn_R001058_5813_7(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int anchor_54 = local_arr[aux % 3];
  acc = (acc + (anchor_54 * 2)) & 127;
  int metric_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_94 > 25)
  {
    acc = ((acc + (metric_94 * 2)) + 5) & 127;
    aux ^= metric_94 & 15;
  }
  else
  {
    acc = ((acc - metric_94) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001058_5813_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int coefficient_22_1 = 0;
  int coefficient_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_22_1 = ((coefficient_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_22_2 = ((coefficient_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_22_1) & 127;
    acc_2 = (acc_2 + coefficient_22_2) & 127;
  }

  int metric_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_63_1)
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

  switch (metric_63_2)
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

  int segment_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_22_1 > 46)
  {
    acc_1 = ((acc_1 + (segment_22_1 * 2)) + 5) & 127;
    aux_1 ^= segment_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_22_2 > 46)
  {
    acc_2 = ((acc_2 + (segment_22_2 * 2)) + 5) & 127;
    aux_2 ^= segment_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_22_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_22_1 == coefficient_22_2);
  assert(metric_63_1 == metric_63_2);
  assert(segment_22_1 == segment_22_2);
}

int fn_R001058_5813_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int coefficient_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_22 = ((coefficient_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_22) & 127;
  }

  int metric_63 = (aux + st.buffer[1]) & 3;
  switch (metric_63)
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

  int segment_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_22 > 46)
  {
    acc = ((acc + (segment_22 * 2)) + 5) & 127;
    aux ^= segment_22 & 15;
  }
  else
  {
    acc = ((acc - segment_22) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001058_5813_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int tracker_15_1 = 0;
  int tracker_15_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_15_1 = ((tracker_15_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_15_2 = ((tracker_15_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_15_1) & 127;
    acc_2 = (acc_2 + tracker_15_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_54_1)
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

  switch (offset_54_2)
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
  int offset_28_1 = local_arr_1[aux_1 % 3];
  int offset_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_28_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_15_1 == tracker_15_2);
  assert(offset_54_1 == offset_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_28_1 == offset_28_2);
}

int fn_R001058_5813_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int tracker_15 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_15 = ((tracker_15 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_15) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_54 = (aux + st.buffer[1]) & 3;
  switch (offset_54)
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
  int offset_28 = local_arr[aux % 3];
  acc = (acc + (offset_28 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001058_5813_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st_1 = {0};
  struct CipherContext_R001058_5813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int margin_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_97_1) & 63;
  aux_2 = (aux_2 + margin_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_44_1)
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

  switch (sample_44_2)
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
  int scale_93_1 = local_arr_1[aux_1 % 3];
  int scale_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_93_2 * 2)) & 127;
  int threshold_64_1 = 0;
  int threshold_64_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    threshold_64_1 = ((threshold_64_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_64_2 = ((threshold_64_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_64_1) & 127;
    acc_2 = (acc_2 + threshold_64_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_97_1 == margin_97_2);
  assert(sample_44_1 == sample_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_93_1 == scale_93_2);
  assert(threshold_64_1 == threshold_64_2);
}

int fn_R001058_5813_10(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int margin_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_97) & 63;
  acc ^= aux;
  int sample_44 = (aux + st.buffer[1]) & 3;
  switch (sample_44)
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
  int scale_93 = local_arr[aux % 3];
  acc = (acc + (scale_93 * 2)) & 127;
  int threshold_64 = 0;
  for (int k = 0; k < 3; k++)
  {
    threshold_64 = ((threshold_64 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_64) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001058_5813_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_44_1 = local_arr_1[aux_1 % 3];
  int coefficient_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_44_2 * 2)) & 127;
  int accumulator_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_48_1)
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

  switch (accumulator_48_2)
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

  int parity_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_31_1) & 63;
  aux_2 = (aux_2 + parity_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_44_1 == coefficient_44_2);
  assert(accumulator_48_1 == accumulator_48_2);
  assert(parity_31_1 == parity_31_2);
}

int fn_R001058_5813_11(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int coefficient_44 = local_arr[aux % 3];
  acc = (acc + (coefficient_44 * 2)) & 127;
  int accumulator_48 = (aux + st.buffer[1]) & 3;
  switch (accumulator_48)
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

  int parity_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001058_5813_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st_1 = {0};
  struct CipherContext_R001058_5813_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int window_58_1 = 0;
  int window_58_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_58_1 = ((window_58_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_58_2 = ((window_58_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_58_1) & 127;
    acc_2 = (acc_2 + window_58_2) & 127;
  }

  int factor_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_72_1)
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

  switch (factor_72_2)
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
  assert(st_1.counter == st_2.counter);
  assert(st_1.tag == st_2.tag);
  assert(st_1.nonce == st_2.nonce);
  assert(st_1.round_key == st_2.round_key);
  assert(st_1.iv == st_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_58_1 == window_58_2);
  assert(factor_72_1 == factor_72_2);
}

int fn_R001058_5813_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct CipherContext_R001058_5813_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int window_58 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_58 = ((window_58 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_58) & 127;
  }

  int factor_72 = (aux + st.buffer[1]) & 3;
  switch (factor_72)
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

void fn_R001058_5813_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int anchor_25_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_25_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_25_1 > 50)
  {
    acc_1 = ((acc_1 + (anchor_25_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_25_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_25_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_25_2 > 50)
  {
    acc_2 = ((acc_2 + (anchor_25_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_25_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_25_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_46_1)
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

  switch (delta_46_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_25_1 == anchor_25_2);
  assert(delta_46_1 == delta_46_2);
}

int fn_R001058_5813_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int anchor_25 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_25 > 50)
  {
    acc = ((acc + (anchor_25 * 2)) + 5) & 127;
    aux ^= anchor_25 & 15;
  }
  else
  {
    acc = ((acc - anchor_25) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_46 = (aux + st.buffer[1]) & 3;
  switch (delta_46)
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

void fn_R001058_5813_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st_1 = {0};
  struct Vector3D_R001058_5813_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int threshold_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_19_1)
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

  switch (threshold_19_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_27_1) & 63;
  aux_2 = (aux_2 + checksum_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_19_1 == threshold_19_2);
  assert(checksum_27_1 == checksum_27_2);
}

int fn_R001058_5813_14(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001058_5813_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int threshold_19 = (aux + st.buffer[1]) & 3;
  switch (threshold_19)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001058_0_1;
  int sec_r001058_0_2;
  int sec_r001058_1_1;
  int sec_r001058_1_2;
  int sec_r001058_2_1;
  int sec_r001058_2_2;
  int sec_r001058_3_1;
  int sec_r001058_3_2;
  int sec_r001058_4_1;
  int sec_r001058_4_2;
  int sec_r001058_5_1;
  int sec_r001058_5_2;
  int sec_r001058_6_1;
  int sec_r001058_6_2;
  int sec_r001058_7_1;
  int sec_r001058_7_2;
  int sec_r001058_8_1;
  int sec_r001058_8_2;
  int sec_r001058_9_1;
  int sec_r001058_9_2;
  int sec_r001058_10_1;
  int sec_r001058_10_2;
  int sec_r001058_11_1;
  int sec_r001058_11_2;
  int sec_r001058_12_1;
  int sec_r001058_12_2;
  int sec_r001058_13_1;
  int sec_r001058_13_2;
  int sec_r001058_14_1;
  int sec_r001058_14_2;
  int sec_r001058_15_1;
  int sec_r001058_15_2;
  int sec_r001058_16_1;
  int sec_r001058_16_2;
  int sec_r001058_17_1;
  int sec_r001058_17_2;
  int sec_r001058_18_1;
  int sec_r001058_18_2;
  int sec_r001058_19_1;
  int sec_r001058_19_2;
  int sec_r001058_20_1;
  int sec_r001058_20_2;
  int sec_r001058_21_1;
  int sec_r001058_21_2;
  int sec_r001058_22_1;
  int sec_r001058_22_2;
  int pub_r001058_0_1;
  int pub_r001058_0_2;
  int pub_r001058_1_1;
  int pub_r001058_1_2;
  int pub_r001058_2_1;
  int pub_r001058_2_2;
  int pub_r001058_3_1;
  int pub_r001058_3_2;
  int pub_r001058_4_1;
  int pub_r001058_4_2;
  int pub_r001058_5_1;
  int pub_r001058_5_2;
  int pub_r001058_6_1;
  int pub_r001058_6_2;
  int pub_r001058_7_1;
  int pub_r001058_7_2;
  int pub_r001058_8_1;
  int pub_r001058_8_2;
  int pub_r001058_9_1;
  int pub_r001058_9_2;
  int pub_r001058_10_1;
  int pub_r001058_10_2;
  int pub_r001058_11_1;
  int pub_r001058_11_2;
  int pub_r001058_12_1;
  int pub_r001058_12_2;
  int pub_r001058_13_1;
  int pub_r001058_13_2;
  int pub_r001058_14_1;
  int pub_r001058_14_2;
  int pub_r001058_15_1;
  int pub_r001058_15_2;
  int pub_r001058_16_1;
  int pub_r001058_16_2;
  int pub_r001058_17_1;
  int pub_r001058_17_2;
  int pub_r001058_18_1;
  int pub_r001058_18_2;
  int pub_r001058_19_1;
  int pub_r001058_19_2;
  int pub_r001058_20_1;
  int pub_r001058_20_2;
  int pub_r001058_21_1;
  int pub_r001058_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001058_0_1 >= (-100)) && (pub_r001058_0_1 <= 100));
  __CPROVER_assume((pub_r001058_0_2 >= (-100)) && (pub_r001058_0_2 <= 100));
  __CPROVER_assume((pub_r001058_1_1 >= (-100)) && (pub_r001058_1_1 <= 100));
  __CPROVER_assume((pub_r001058_1_2 >= (-100)) && (pub_r001058_1_2 <= 100));
  __CPROVER_assume((pub_r001058_2_1 >= (-100)) && (pub_r001058_2_1 <= 100));
  __CPROVER_assume((pub_r001058_2_2 >= (-100)) && (pub_r001058_2_2 <= 100));
  __CPROVER_assume((pub_r001058_3_1 >= (-100)) && (pub_r001058_3_1 <= 100));
  __CPROVER_assume((pub_r001058_3_2 >= (-100)) && (pub_r001058_3_2 <= 100));
  __CPROVER_assume((pub_r001058_4_1 >= (-100)) && (pub_r001058_4_1 <= 100));
  __CPROVER_assume((pub_r001058_4_2 >= (-100)) && (pub_r001058_4_2 <= 100));
  __CPROVER_assume((pub_r001058_5_1 >= (-100)) && (pub_r001058_5_1 <= 100));
  __CPROVER_assume((pub_r001058_5_2 >= (-100)) && (pub_r001058_5_2 <= 100));
  __CPROVER_assume((pub_r001058_6_1 >= (-100)) && (pub_r001058_6_1 <= 100));
  __CPROVER_assume((pub_r001058_6_2 >= (-100)) && (pub_r001058_6_2 <= 100));
  __CPROVER_assume((pub_r001058_7_1 >= (-100)) && (pub_r001058_7_1 <= 100));
  __CPROVER_assume((pub_r001058_7_2 >= (-100)) && (pub_r001058_7_2 <= 100));
  __CPROVER_assume((pub_r001058_8_1 >= (-100)) && (pub_r001058_8_1 <= 100));
  __CPROVER_assume((pub_r001058_8_2 >= (-100)) && (pub_r001058_8_2 <= 100));
  __CPROVER_assume((pub_r001058_9_1 >= (-100)) && (pub_r001058_9_1 <= 100));
  __CPROVER_assume((pub_r001058_9_2 >= (-100)) && (pub_r001058_9_2 <= 100));
  __CPROVER_assume((pub_r001058_10_1 >= (-100)) && (pub_r001058_10_1 <= 100));
  __CPROVER_assume((pub_r001058_10_2 >= (-100)) && (pub_r001058_10_2 <= 100));
  __CPROVER_assume((pub_r001058_11_1 >= (-100)) && (pub_r001058_11_1 <= 100));
  __CPROVER_assume((pub_r001058_11_2 >= (-100)) && (pub_r001058_11_2 <= 100));
  __CPROVER_assume((pub_r001058_12_1 >= (-100)) && (pub_r001058_12_1 <= 100));
  __CPROVER_assume((pub_r001058_12_2 >= (-100)) && (pub_r001058_12_2 <= 100));
  __CPROVER_assume((pub_r001058_13_1 >= (-100)) && (pub_r001058_13_1 <= 100));
  __CPROVER_assume((pub_r001058_13_2 >= (-100)) && (pub_r001058_13_2 <= 100));
  __CPROVER_assume((pub_r001058_14_1 >= (-100)) && (pub_r001058_14_1 <= 100));
  __CPROVER_assume((pub_r001058_14_2 >= (-100)) && (pub_r001058_14_2 <= 100));
  __CPROVER_assume((pub_r001058_15_1 >= (-100)) && (pub_r001058_15_1 <= 100));
  __CPROVER_assume((pub_r001058_15_2 >= (-100)) && (pub_r001058_15_2 <= 100));
  __CPROVER_assume((pub_r001058_16_1 >= (-100)) && (pub_r001058_16_1 <= 100));
  __CPROVER_assume((pub_r001058_16_2 >= (-100)) && (pub_r001058_16_2 <= 100));
  __CPROVER_assume((pub_r001058_17_1 >= (-100)) && (pub_r001058_17_1 <= 100));
  __CPROVER_assume((pub_r001058_17_2 >= (-100)) && (pub_r001058_17_2 <= 100));
  __CPROVER_assume((pub_r001058_18_1 >= (-100)) && (pub_r001058_18_1 <= 100));
  __CPROVER_assume((pub_r001058_18_2 >= (-100)) && (pub_r001058_18_2 <= 100));
  __CPROVER_assume((pub_r001058_19_1 >= (-100)) && (pub_r001058_19_1 <= 100));
  __CPROVER_assume((pub_r001058_19_2 >= (-100)) && (pub_r001058_19_2 <= 100));
  __CPROVER_assume((pub_r001058_20_1 >= (-100)) && (pub_r001058_20_1 <= 100));
  __CPROVER_assume((pub_r001058_20_2 >= (-100)) && (pub_r001058_20_2 <= 100));
  __CPROVER_assume((pub_r001058_21_1 >= (-100)) && (pub_r001058_21_1 <= 100));
  __CPROVER_assume((pub_r001058_21_2 >= (-100)) && (pub_r001058_21_2 <= 100));
  __CPROVER_assume((sec_r001058_0_1 >= 0) && (sec_r001058_0_1 <= 255));
  __CPROVER_assume((sec_r001058_0_2 >= 0) && (sec_r001058_0_2 <= 255));
  __CPROVER_assume((sec_r001058_1_1 >= 0) && (sec_r001058_1_1 <= 255));
  __CPROVER_assume((sec_r001058_1_2 >= 0) && (sec_r001058_1_2 <= 255));
  __CPROVER_assume((sec_r001058_2_1 >= 0) && (sec_r001058_2_1 <= 255));
  __CPROVER_assume((sec_r001058_2_2 >= 0) && (sec_r001058_2_2 <= 255));
  __CPROVER_assume((sec_r001058_3_1 >= 0) && (sec_r001058_3_1 <= 255));
  __CPROVER_assume((sec_r001058_3_2 >= 0) && (sec_r001058_3_2 <= 255));
  __CPROVER_assume((sec_r001058_4_1 >= 0) && (sec_r001058_4_1 <= 255));
  __CPROVER_assume((sec_r001058_4_2 >= 0) && (sec_r001058_4_2 <= 255));
  __CPROVER_assume((sec_r001058_5_1 >= 0) && (sec_r001058_5_1 <= 255));
  __CPROVER_assume((sec_r001058_5_2 >= 0) && (sec_r001058_5_2 <= 255));
  __CPROVER_assume((sec_r001058_6_1 >= 0) && (sec_r001058_6_1 <= 255));
  __CPROVER_assume((sec_r001058_6_2 >= 0) && (sec_r001058_6_2 <= 255));
  __CPROVER_assume((sec_r001058_7_1 >= 0) && (sec_r001058_7_1 <= 255));
  __CPROVER_assume((sec_r001058_7_2 >= 0) && (sec_r001058_7_2 <= 255));
  __CPROVER_assume((sec_r001058_8_1 >= 0) && (sec_r001058_8_1 <= 255));
  __CPROVER_assume((sec_r001058_8_2 >= 0) && (sec_r001058_8_2 <= 255));
  __CPROVER_assume((sec_r001058_9_1 >= 0) && (sec_r001058_9_1 <= 255));
  __CPROVER_assume((sec_r001058_9_2 >= 0) && (sec_r001058_9_2 <= 255));
  __CPROVER_assume((sec_r001058_10_1 >= 0) && (sec_r001058_10_1 <= 255));
  __CPROVER_assume((sec_r001058_10_2 >= 0) && (sec_r001058_10_2 <= 255));
  __CPROVER_assume((sec_r001058_11_1 >= 0) && (sec_r001058_11_1 <= 255));
  __CPROVER_assume((sec_r001058_11_2 >= 0) && (sec_r001058_11_2 <= 255));
  __CPROVER_assume((sec_r001058_12_1 >= 0) && (sec_r001058_12_1 <= 255));
  __CPROVER_assume((sec_r001058_12_2 >= 0) && (sec_r001058_12_2 <= 255));
  __CPROVER_assume((sec_r001058_13_1 >= 0) && (sec_r001058_13_1 <= 255));
  __CPROVER_assume((sec_r001058_13_2 >= 0) && (sec_r001058_13_2 <= 255));
  __CPROVER_assume((sec_r001058_14_1 >= 0) && (sec_r001058_14_1 <= 255));
  __CPROVER_assume((sec_r001058_14_2 >= 0) && (sec_r001058_14_2 <= 255));
  __CPROVER_assume((sec_r001058_15_1 >= 0) && (sec_r001058_15_1 <= 255));
  __CPROVER_assume((sec_r001058_15_2 >= 0) && (sec_r001058_15_2 <= 255));
  __CPROVER_assume((sec_r001058_16_1 >= 0) && (sec_r001058_16_1 <= 255));
  __CPROVER_assume((sec_r001058_16_2 >= 0) && (sec_r001058_16_2 <= 255));
  __CPROVER_assume((sec_r001058_17_1 >= 0) && (sec_r001058_17_1 <= 255));
  __CPROVER_assume((sec_r001058_17_2 >= 0) && (sec_r001058_17_2 <= 255));
  __CPROVER_assume((sec_r001058_18_1 >= 0) && (sec_r001058_18_1 <= 255));
  __CPROVER_assume((sec_r001058_18_2 >= 0) && (sec_r001058_18_2 <= 255));
  __CPROVER_assume((sec_r001058_19_1 >= 0) && (sec_r001058_19_1 <= 255));
  __CPROVER_assume((sec_r001058_19_2 >= 0) && (sec_r001058_19_2 <= 255));
  __CPROVER_assume((sec_r001058_20_1 >= 0) && (sec_r001058_20_1 <= 255));
  __CPROVER_assume((sec_r001058_20_2 >= 0) && (sec_r001058_20_2 <= 255));
  __CPROVER_assume((sec_r001058_21_1 >= 0) && (sec_r001058_21_1 <= 255));
  __CPROVER_assume((sec_r001058_21_2 >= 0) && (sec_r001058_21_2 <= 255));
  __CPROVER_assume((sec_r001058_22_1 >= 0) && (sec_r001058_22_1 <= 255));
  __CPROVER_assume((sec_r001058_22_2 >= 0) && (sec_r001058_22_2 <= 255));
  struct MatrixBlock_R001058_5813_0 st_var_0_1 = {0};
  struct MatrixBlock_R001058_5813_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001058_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001058_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001058_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001058_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001058_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001058_0_2 + 7) & 15;
  struct CipherContext_R001058_5813_1 st_var_1_1 = {0};
  struct CipherContext_R001058_5813_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001058_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001058_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001058_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001058_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001058_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001058_0_2 + 9) & 15;
  struct Vector3D_R001058_5813_2 st_var_2_1 = {0};
  struct Vector3D_R001058_5813_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001058_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001058_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001058_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001058_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001058_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001058_0_2 + 11) & 15;
  union PacketPayload_R001058_5813_0 u_var_1;
  union PacketPayload_R001058_5813_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001058_5813_0(sec_r001058_0_1, sec_r001058_1_1);
  int helper_flow_0_2 = fn_R001058_5813_0(sec_r001058_0_2, sec_r001058_1_2);
  fn_R001058_5813_0_2(sec_r001058_0_1, sec_r001058_1_1, sec_r001058_0_2, sec_r001058_1_2);
  int helper_flow_1_1 = fn_R001058_5813_1(sec_r001058_1_1, pub_r001058_2_1, pub_r001058_3_1, pub_r001058_4_1, pub_r001058_5_1);
  int helper_flow_1_2 = fn_R001058_5813_1(sec_r001058_1_2, pub_r001058_2_2, pub_r001058_3_2, pub_r001058_4_2, pub_r001058_5_2);
  fn_R001058_5813_1_2(sec_r001058_1_1, pub_r001058_2_1, pub_r001058_3_1, pub_r001058_4_1, pub_r001058_5_1, sec_r001058_1_2, pub_r001058_2_2, pub_r001058_3_2, pub_r001058_4_2, pub_r001058_5_2);
  int helper_flow_2_1 = fn_R001058_5813_2(sec_r001058_2_1, sec_r001058_3_1, pub_r001058_4_1, pub_r001058_5_1);
  int helper_flow_2_2 = fn_R001058_5813_2(sec_r001058_2_2, sec_r001058_3_2, pub_r001058_4_2, pub_r001058_5_2);
  fn_R001058_5813_2_2(sec_r001058_2_1, sec_r001058_3_1, pub_r001058_4_1, pub_r001058_5_1, sec_r001058_2_2, sec_r001058_3_2, pub_r001058_4_2, pub_r001058_5_2);
  int helper_flow_3_1 = fn_R001058_5813_3(sec_r001058_3_1, sec_r001058_4_1, pub_r001058_5_1);
  int helper_flow_3_2 = fn_R001058_5813_3(sec_r001058_3_2, sec_r001058_4_2, pub_r001058_5_2);
  fn_R001058_5813_3_2(sec_r001058_3_1, sec_r001058_4_1, pub_r001058_5_1, sec_r001058_3_2, sec_r001058_4_2, pub_r001058_5_2);
  int helper_flow_4_1 = fn_R001058_5813_4(sec_r001058_4_1, sec_r001058_5_1, pub_r001058_6_1);
  int helper_flow_4_2 = fn_R001058_5813_4(sec_r001058_4_2, sec_r001058_5_2, pub_r001058_6_2);
  fn_R001058_5813_4_2(sec_r001058_4_1, sec_r001058_5_1, pub_r001058_6_1, sec_r001058_4_2, sec_r001058_5_2, pub_r001058_6_2);
  int helper_flow_5_1 = fn_R001058_5813_5(sec_r001058_5_1, sec_r001058_6_1, pub_r001058_7_1);
  int helper_flow_5_2 = fn_R001058_5813_5(sec_r001058_5_2, sec_r001058_6_2, pub_r001058_7_2);
  fn_R001058_5813_5_2(sec_r001058_5_1, sec_r001058_6_1, pub_r001058_7_1, sec_r001058_5_2, sec_r001058_6_2, pub_r001058_7_2);
  int helper_flow_6_1 = fn_R001058_5813_6(sec_r001058_6_1, pub_r001058_7_1, pub_r001058_8_1, pub_r001058_9_1);
  int helper_flow_6_2 = fn_R001058_5813_6(sec_r001058_6_2, pub_r001058_7_2, pub_r001058_8_2, pub_r001058_9_2);
  fn_R001058_5813_6_2(sec_r001058_6_1, pub_r001058_7_1, pub_r001058_8_1, pub_r001058_9_1, sec_r001058_6_2, pub_r001058_7_2, pub_r001058_8_2, pub_r001058_9_2);
  int helper_flow_7_1 = fn_R001058_5813_7(sec_r001058_7_1, pub_r001058_8_1, pub_r001058_9_1);
  int helper_flow_7_2 = fn_R001058_5813_7(sec_r001058_7_2, pub_r001058_8_2, pub_r001058_9_2);
  fn_R001058_5813_7_2(sec_r001058_7_1, pub_r001058_8_1, pub_r001058_9_1, sec_r001058_7_2, pub_r001058_8_2, pub_r001058_9_2);
  int helper_flow_8_1 = fn_R001058_5813_8(sec_r001058_8_1, sec_r001058_9_1, pub_r001058_10_1, pub_r001058_11_1, pub_r001058_12_1);
  int helper_flow_8_2 = fn_R001058_5813_8(sec_r001058_8_2, sec_r001058_9_2, pub_r001058_10_2, pub_r001058_11_2, pub_r001058_12_2);
  fn_R001058_5813_8_2(sec_r001058_8_1, sec_r001058_9_1, pub_r001058_10_1, pub_r001058_11_1, pub_r001058_12_1, sec_r001058_8_2, sec_r001058_9_2, pub_r001058_10_2, pub_r001058_11_2, pub_r001058_12_2);
  int helper_flow_9_1 = fn_R001058_5813_9(sec_r001058_9_1, pub_r001058_10_1, pub_r001058_11_1, pub_r001058_12_1, pub_r001058_13_1);
  int helper_flow_9_2 = fn_R001058_5813_9(sec_r001058_9_2, pub_r001058_10_2, pub_r001058_11_2, pub_r001058_12_2, pub_r001058_13_2);
  fn_R001058_5813_9_2(sec_r001058_9_1, pub_r001058_10_1, pub_r001058_11_1, pub_r001058_12_1, pub_r001058_13_1, sec_r001058_9_2, pub_r001058_10_2, pub_r001058_11_2, pub_r001058_12_2, pub_r001058_13_2);
  int stage_v_0_1 = ((pub_r001058_20_1 * 2) + 9) & 63;
  int stage_v_0_2 = ((pub_r001058_20_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001058_11_1 * 2) + 31) & 63;
  int stage_v_1_2 = ((pub_r001058_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = 0;
  int stage_v_2_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_2_1 = ((stage_v_2_1 + (it_1 * 3)) + (helper_flow_8_1 & 15)) & 63;
    stage_v_2_2 = ((stage_v_2_2 + (it_2 * 3)) + (helper_flow_8_2 & 15)) & 63;
    if ((helper_flow_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_2_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_2_1) + 7) & 255;
    }
    if ((helper_flow_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_2_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_2_2) + 7) & 255;
    }
  }

  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (it_1 * 3)) + (sec_r001058_9_1 & 15)) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (it_2 * 3)) + (sec_r001058_9_2 & 15)) & 63;
    if ((sec_r001058_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_3_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_3_1) + 7) & 255;
    }
    if ((sec_r001058_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_3_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_3_2) + 7) & 255;
    }
  }

  int stage_v_4_1 = 0;
  int stage_v_4_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_4_1 = ((stage_v_4_1 + (it_1 * 3)) + (sec_r001058_2_1 & 15)) & 63;
    stage_v_4_2 = ((stage_v_4_2 + (it_2 * 3)) + (sec_r001058_2_2 & 15)) & 63;
    if ((sec_r001058_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_4_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_4_1) + 7) & 255;
    }
    if ((sec_r001058_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_4_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_4_2) + 7) & 255;
    }
  }

  int stage_v_5_1 = ((pub_r001058_2_1 * 2) + 8) & 63;
  int stage_v_5_2 = ((pub_r001058_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (it_1 * 3)) + (sec_r001058_13_1 & 15)) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (it_2 * 3)) + (sec_r001058_13_2 & 15)) & 63;
    if ((sec_r001058_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_6_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_6_1) + 7) & 255;
    }
    if ((sec_r001058_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_6_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_6_2) + 7) & 255;
    }
  }

  int stage_v_7_1 = ((pub_r001058_11_1 * 2) + 49) & 63;
  int stage_v_7_2 = ((pub_r001058_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001058_16_1 * 2) + 21) & 63;
  int stage_v_8_2 = ((pub_r001058_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001058_19_1 * 2) + 10) & 63;
  int stage_v_9_2 = ((pub_r001058_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = 0;
  int stage_v_10_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_10_1 = ((stage_v_10_1 + (it_1 * 3)) + (sec_r001058_4_1 & 15)) & 63;
    stage_v_10_2 = ((stage_v_10_2 + (it_2 * 3)) + (sec_r001058_4_2 & 15)) & 63;
    if ((sec_r001058_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_10_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_10_1) + 7) & 255;
    }
    if ((sec_r001058_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_10_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_10_2) + 7) & 255;
    }
  }

  int stage_v_11_1 = 0;
  int stage_v_11_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_11_1 = ((stage_v_11_1 + (it_1 * 3)) + (sec_r001058_8_1 & 15)) & 63;
    stage_v_11_2 = ((stage_v_11_2 + (it_2 * 3)) + (sec_r001058_8_2 & 15)) & 63;
    if ((sec_r001058_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_11_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_11_1) + 7) & 255;
    }
    if ((sec_r001058_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_11_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_11_2) + 7) & 255;
    }
  }

  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (it_1 * 3)) + (sec_r001058_13_1 & 15)) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (it_2 * 3)) + (sec_r001058_13_2 & 15)) & 63;
    if ((sec_r001058_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_12_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_12_1) + 7) & 255;
    }
    if ((sec_r001058_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_12_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_12_2) + 7) & 255;
    }
  }

  int stage_v_13_1 = ((pub_r001058_1_1 * 2) + 9) & 63;
  int stage_v_13_2 = ((pub_r001058_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = 0;
  int stage_v_14_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_14_1 = ((stage_v_14_1 + (it_1 * 3)) + (sec_r001058_21_1 & 15)) & 63;
    stage_v_14_2 = ((stage_v_14_2 + (it_2 * 3)) + (sec_r001058_21_2 & 15)) & 63;
    if ((sec_r001058_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_14_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_14_1) + 7) & 255;
    }
    if ((sec_r001058_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_14_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_14_2) + 7) & 255;
    }
  }

  int stage_v_15_1 = ((pub_r001058_16_1 * 2) + 37) & 63;
  int stage_v_15_2 = ((pub_r001058_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = 0;
  int stage_v_16_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_16_1 = ((stage_v_16_1 + (it_1 * 3)) + (helper_flow_4_1 & 15)) & 63;
    stage_v_16_2 = ((stage_v_16_2 + (it_2 * 3)) + (helper_flow_4_2 & 15)) & 63;
    if ((helper_flow_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_16_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_16_1) + 7) & 255;
    }
    if ((helper_flow_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_16_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_16_2) + 7) & 255;
    }
  }

  int stage_v_17_1 = 0;
  int stage_v_17_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_17_1 = ((stage_v_17_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_17_2 = ((stage_v_17_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_17_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_17_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_17_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_17_2) + 7) & 255;
    }
  }

  int stage_v_18_1 = 0;
  int stage_v_18_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_18_1 = ((stage_v_18_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_18_2 = ((stage_v_18_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_18_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_18_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_18_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_18_2) + 7) & 255;
    }
  }

  int stage_v_19_1 = 0;
  int stage_v_19_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_19_1 = ((stage_v_19_1 + (it_1 * 3)) + (sec_r001058_14_1 & 15)) & 63;
    stage_v_19_2 = ((stage_v_19_2 + (it_2 * 3)) + (sec_r001058_14_2 & 15)) & 63;
    if ((sec_r001058_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_19_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_19_1) + 7) & 255;
    }
    if ((sec_r001058_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_19_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_19_2) + 7) & 255;
    }
  }

  int stage_v_20_1 = ((pub_r001058_9_1 * 2) + 24) & 63;
  int stage_v_20_2 = ((pub_r001058_9_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (it_1 * 3)) + (sec_r001058_20_1 & 15)) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (it_2 * 3)) + (sec_r001058_20_2 & 15)) & 63;
    if ((sec_r001058_20_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_21_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_21_1) + 7) & 255;
    }
    if ((sec_r001058_20_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_21_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_21_2) + 7) & 255;
    }
  }

  int stage_v_22_1 = ((pub_r001058_12_1 * 2) + 44) & 63;
  int stage_v_22_2 = ((pub_r001058_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (it_1 * 3)) + (sec_r001058_1_1 & 15)) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (it_2 * 3)) + (sec_r001058_1_2 & 15)) & 63;
    if ((sec_r001058_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_23_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_23_1) + 7) & 255;
    }
    if ((sec_r001058_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_23_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_23_2) + 7) & 255;
    }
  }

  int stage_v_24_1 = ((pub_r001058_11_1 * 2) + 40) & 63;
  int stage_v_24_2 = ((pub_r001058_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (it_1 * 3)) + (sec_r001058_21_1 & 15)) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (it_2 * 3)) + (sec_r001058_21_2 & 15)) & 63;
    if ((sec_r001058_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_25_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_25_1) + 7) & 255;
    }
    if ((sec_r001058_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_25_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_25_2) + 7) & 255;
    }
  }

  int stage_v_26_1 = ((pub_r001058_21_1 * 2) + 39) & 63;
  int stage_v_26_2 = ((pub_r001058_21_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001058_3_1 * 2) + 24) & 63;
  int stage_v_27_2 = ((pub_r001058_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001058_17_1 * 2) + 13) & 63;
  int stage_v_28_2 = ((pub_r001058_17_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001058_12_1 * 2) + 22) & 63;
  int stage_v_29_2 = ((pub_r001058_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (it_1 * 3)) + (sec_r001058_15_1 & 15)) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (it_2 * 3)) + (sec_r001058_15_2 & 15)) & 63;
    if ((sec_r001058_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_30_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_30_1) + 7) & 255;
    }
    if ((sec_r001058_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_30_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_30_2) + 7) & 255;
    }
  }

  int stage_v_31_1 = ((pub_r001058_2_1 * 2) + 16) & 63;
  int stage_v_31_2 = ((pub_r001058_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_32_1 = ((stage_v_32_1 + (it_1 * 3)) + (sec_r001058_6_1 & 15)) & 63;
    stage_v_32_2 = ((stage_v_32_2 + (it_2 * 3)) + (sec_r001058_6_2 & 15)) & 63;
    if ((sec_r001058_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_32_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_32_1) + 7) & 255;
    }
    if ((sec_r001058_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_32_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_32_2) + 7) & 255;
    }
  }

  int stage_v_33_1 = ((pub_r001058_16_1 * 2) + 43) & 63;
  int stage_v_33_2 = ((pub_r001058_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_34_1 = ((stage_v_34_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_34_2 = ((stage_v_34_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_34_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_34_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_34_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_34_2) + 7) & 255;
    }
  }

  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_35_1 = ((stage_v_35_1 + (it_1 * 3)) + (sec_r001058_16_1 & 15)) & 63;
    stage_v_35_2 = ((stage_v_35_2 + (it_2 * 3)) + (sec_r001058_16_2 & 15)) & 63;
    if ((sec_r001058_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_35_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_35_1) + 7) & 255;
    }
    if ((sec_r001058_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_35_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_35_2) + 7) & 255;
    }
  }

  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_36_1 = ((stage_v_36_1 + (it_1 * 3)) + (stage_v_19_1 & 15)) & 63;
    stage_v_36_2 = ((stage_v_36_2 + (it_2 * 3)) + (stage_v_19_2 & 15)) & 63;
    if ((stage_v_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_36_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_36_1) + 7) & 255;
    }
    if ((stage_v_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_36_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_36_2) + 7) & 255;
    }
  }

  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_37_1 = ((stage_v_37_1 + (it_1 * 3)) + (helper_flow_9_1 & 15)) & 63;
    stage_v_37_2 = ((stage_v_37_2 + (it_2 * 3)) + (helper_flow_9_2 & 15)) & 63;
    if ((helper_flow_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_37_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_37_1) + 7) & 255;
    }
    if ((helper_flow_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_37_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_37_2) + 7) & 255;
    }
  }

  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_38_1 = ((stage_v_38_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_38_2 = ((stage_v_38_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_38_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_38_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_38_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_38_2) + 7) & 255;
    }
  }

  int stage_v_39_1 = ((pub_r001058_5_1 * 2) + 28) & 63;
  int stage_v_39_2 = ((pub_r001058_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001058_17_1 * 2) + 10) & 63;
  int stage_v_40_2 = ((pub_r001058_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001058_12_1 * 2) + 31) & 63;
  int stage_v_41_2 = ((pub_r001058_12_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001058_10_1 * 2) + 21) & 63;
  int stage_v_42_2 = ((pub_r001058_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_43_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_43_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_43_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_43_2) + 7) & 255;
    }
  }

  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_44_1 = ((stage_v_44_1 + (it_1 * 3)) + (stage_v_2_1 & 15)) & 63;
    stage_v_44_2 = ((stage_v_44_2 + (it_2 * 3)) + (stage_v_2_2 & 15)) & 63;
    if ((stage_v_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_44_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_44_1) + 7) & 255;
    }
    if ((stage_v_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_44_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_44_2) + 7) & 255;
    }
  }

  int stage_v_45_1 = ((pub_r001058_4_1 * 2) + 47) & 63;
  int stage_v_45_2 = ((pub_r001058_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_46_1 = ((stage_v_46_1 + (it_1 * 3)) + (sec_r001058_9_1 & 15)) & 63;
    stage_v_46_2 = ((stage_v_46_2 + (it_2 * 3)) + (sec_r001058_9_2 & 15)) & 63;
    if ((sec_r001058_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_46_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_46_1) + 7) & 255;
    }
    if ((sec_r001058_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_46_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_46_2) + 7) & 255;
    }
  }

  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_47_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_47_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_47_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_47_2) + 7) & 255;
    }
  }

  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_48_1 = ((stage_v_48_1 + (it_1 * 3)) + (sec_r001058_11_1 & 15)) & 63;
    stage_v_48_2 = ((stage_v_48_2 + (it_2 * 3)) + (sec_r001058_11_2 & 15)) & 63;
    if ((sec_r001058_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_48_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_48_1) + 7) & 255;
    }
    if ((sec_r001058_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_48_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_48_2) + 7) & 255;
    }
  }

  int stage_v_49_1 = ((pub_r001058_3_1 * 2) + 7) & 63;
  int stage_v_49_2 = ((pub_r001058_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_50_1 = ((stage_v_50_1 + (it_1 * 3)) + (stage_v_30_1 & 15)) & 63;
    stage_v_50_2 = ((stage_v_50_2 + (it_2 * 3)) + (stage_v_30_2 & 15)) & 63;
    if ((stage_v_30_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_50_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_50_1) + 7) & 255;
    }
    if ((stage_v_30_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_50_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_50_2) + 7) & 255;
    }
  }

  int stage_v_51_1 = ((pub_r001058_0_1 * 2) + 43) & 63;
  int stage_v_51_2 = ((pub_r001058_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001058_19_1 * 2) + 12) & 63;
  int stage_v_52_2 = ((pub_r001058_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (it_1 * 3)) + (sec_r001058_2_1 & 15)) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (it_2 * 3)) + (sec_r001058_2_2 & 15)) & 63;
    if ((sec_r001058_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_53_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_53_1) + 7) & 255;
    }
    if ((sec_r001058_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_53_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_53_2) + 7) & 255;
    }
  }

  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_54_1 = ((stage_v_54_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_54_2 = ((stage_v_54_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_54_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_54_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_54_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_54_2) + 7) & 255;
    }
  }

  int stage_v_55_1 = ((pub_r001058_14_1 * 2) + 26) & 63;
  int stage_v_55_2 = ((pub_r001058_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001058_10_1 * 2) + 43) & 63;
  int stage_v_56_2 = ((pub_r001058_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_57_1 = ((stage_v_57_1 + (it_1 * 3)) + (sec_r001058_17_1 & 15)) & 63;
    stage_v_57_2 = ((stage_v_57_2 + (it_2 * 3)) + (sec_r001058_17_2 & 15)) & 63;
    if ((sec_r001058_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_57_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_57_1) + 7) & 255;
    }
    if ((sec_r001058_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_57_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_57_2) + 7) & 255;
    }
  }

  int stage_v_58_1 = ((pub_r001058_8_1 * 2) + 25) & 63;
  int stage_v_58_2 = ((pub_r001058_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (it_1 * 3)) + (stage_v_43_1 & 15)) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (it_2 * 3)) + (stage_v_43_2 & 15)) & 63;
    if ((stage_v_43_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_59_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_59_1) + 7) & 255;
    }
    if ((stage_v_43_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_59_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_59_2) + 7) & 255;
    }
  }

  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_60_1 = ((stage_v_60_1 + (it_1 * 3)) + (sec_r001058_7_1 & 15)) & 63;
    stage_v_60_2 = ((stage_v_60_2 + (it_2 * 3)) + (sec_r001058_7_2 & 15)) & 63;
    if ((sec_r001058_7_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_60_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_60_1) + 7) & 255;
    }
    if ((sec_r001058_7_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_60_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_60_2) + 7) & 255;
    }
  }

  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_61_1 = ((stage_v_61_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_61_2 = ((stage_v_61_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_61_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_61_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_61_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_61_2) + 7) & 255;
    }
  }

  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_62_1 = ((stage_v_62_1 + (it_1 * 3)) + (stage_v_59_1 & 15)) & 63;
    stage_v_62_2 = ((stage_v_62_2 + (it_2 * 3)) + (stage_v_59_2 & 15)) & 63;
    if ((stage_v_59_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_62_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_62_1) + 7) & 255;
    }
    if ((stage_v_59_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_62_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_62_2) + 7) & 255;
    }
  }

  int stage_v_63_1 = ((pub_r001058_10_1 * 2) + 15) & 63;
  int stage_v_63_2 = ((pub_r001058_10_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_64_1 = ((stage_v_64_1 + (it_1 * 3)) + (sec_r001058_4_1 & 15)) & 63;
    stage_v_64_2 = ((stage_v_64_2 + (it_2 * 3)) + (sec_r001058_4_2 & 15)) & 63;
    if ((sec_r001058_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_64_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_64_1) + 7) & 255;
    }
    if ((sec_r001058_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_64_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_64_2) + 7) & 255;
    }
  }

  int stage_v_65_1 = ((pub_r001058_2_1 * 2) + 25) & 63;
  int stage_v_65_2 = ((pub_r001058_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_66_1 = ((stage_v_66_1 + (it_1 * 3)) + (stage_v_36_1 & 15)) & 63;
    stage_v_66_2 = ((stage_v_66_2 + (it_2 * 3)) + (stage_v_36_2 & 15)) & 63;
    if ((stage_v_36_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_66_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_66_1) + 7) & 255;
    }
    if ((stage_v_36_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_66_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_66_2) + 7) & 255;
    }
  }

  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_67_1 = ((stage_v_67_1 + (it_1 * 3)) + (sec_r001058_1_1 & 15)) & 63;
    stage_v_67_2 = ((stage_v_67_2 + (it_2 * 3)) + (sec_r001058_1_2 & 15)) & 63;
    if ((sec_r001058_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_67_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_67_1) + 7) & 255;
    }
    if ((sec_r001058_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_67_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_67_2) + 7) & 255;
    }
  }

  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_68_1 = ((stage_v_68_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_68_2 = ((stage_v_68_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_68_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_68_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_68_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_68_2) + 7) & 255;
    }
  }

  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_69_1 = ((stage_v_69_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_69_2 = ((stage_v_69_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_69_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_69_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_69_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_69_2) + 7) & 255;
    }
  }

  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_70_1 = ((stage_v_70_1 + (it_1 * 3)) + (stage_v_18_1 & 15)) & 63;
    stage_v_70_2 = ((stage_v_70_2 + (it_2 * 3)) + (stage_v_18_2 & 15)) & 63;
    if ((stage_v_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_70_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_70_1) + 7) & 255;
    }
    if ((stage_v_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_70_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_70_2) + 7) & 255;
    }
  }

  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_71_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_71_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_71_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_71_2) + 7) & 255;
    }
  }

  int stage_v_72_1 = ((pub_r001058_14_1 * 2) + 8) & 63;
  int stage_v_72_2 = ((pub_r001058_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001058_13_1 * 2) + 47) & 63;
  int stage_v_73_2 = ((pub_r001058_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_74_1 = ((stage_v_74_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_74_2 = ((stage_v_74_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_74_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_74_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_74_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_74_2) + 7) & 255;
    }
  }

  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_75_1 = ((stage_v_75_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_75_2 = ((stage_v_75_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_75_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_75_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_75_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_75_2) + 7) & 255;
    }
  }

  int stage_v_76_1 = ((pub_r001058_1_1 * 2) + 9) & 63;
  int stage_v_76_2 = ((pub_r001058_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_77_1 = ((stage_v_77_1 + (it_1 * 3)) + (sec_r001058_15_1 & 15)) & 63;
    stage_v_77_2 = ((stage_v_77_2 + (it_2 * 3)) + (sec_r001058_15_2 & 15)) & 63;
    if ((sec_r001058_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_77_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_77_1) + 7) & 255;
    }
    if ((sec_r001058_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_77_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_77_2) + 7) & 255;
    }
  }

  int stage_v_78_1 = ((pub_r001058_0_1 * 2) + 9) & 63;
  int stage_v_78_2 = ((pub_r001058_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001058_13_1 * 2) + 6) & 63;
  int stage_v_79_2 = ((pub_r001058_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_80_1 = ((stage_v_80_1 + (it_1 * 3)) + (stage_v_62_1 & 15)) & 63;
    stage_v_80_2 = ((stage_v_80_2 + (it_2 * 3)) + (stage_v_62_2 & 15)) & 63;
    if ((stage_v_62_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_80_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_80_1) + 7) & 255;
    }
    if ((stage_v_62_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_80_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_80_2) + 7) & 255;
    }
  }

  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_81_1 = ((stage_v_81_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_81_2 = ((stage_v_81_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_81_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_81_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_81_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_81_2) + 7) & 255;
    }
  }

  int stage_v_82_1 = ((pub_r001058_8_1 * 2) + 40) & 63;
  int stage_v_82_2 = ((pub_r001058_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_83_1 = ((stage_v_83_1 + (it_1 * 3)) + (sec_r001058_18_1 & 15)) & 63;
    stage_v_83_2 = ((stage_v_83_2 + (it_2 * 3)) + (sec_r001058_18_2 & 15)) & 63;
    if ((sec_r001058_18_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_83_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_83_1) + 7) & 255;
    }
    if ((sec_r001058_18_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_83_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_83_2) + 7) & 255;
    }
  }

  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_84_1 = ((stage_v_84_1 + (it_1 * 3)) + (stage_v_54_1 & 15)) & 63;
    stage_v_84_2 = ((stage_v_84_2 + (it_2 * 3)) + (stage_v_54_2 & 15)) & 63;
    if ((stage_v_54_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_84_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_84_1) + 7) & 255;
    }
    if ((stage_v_54_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_84_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_84_2) + 7) & 255;
    }
  }

  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_85_1 = ((stage_v_85_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_85_2 = ((stage_v_85_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_85_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_85_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_85_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_85_2) + 7) & 255;
    }
  }

  int stage_v_86_1 = ((pub_r001058_10_1 * 2) + 6) & 63;
  int stage_v_86_2 = ((pub_r001058_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_87_1 = ((stage_v_87_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_87_2 = ((stage_v_87_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_87_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_87_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_87_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_87_2) + 7) & 255;
    }
  }

  int stage_v_88_1 = ((pub_r001058_15_1 * 2) + 22) & 63;
  int stage_v_88_2 = ((pub_r001058_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_89_1 = ((stage_v_89_1 + (it_1 * 3)) + (sec_r001058_21_1 & 15)) & 63;
    stage_v_89_2 = ((stage_v_89_2 + (it_2 * 3)) + (sec_r001058_21_2 & 15)) & 63;
    if ((sec_r001058_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_89_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_89_1) + 7) & 255;
    }
    if ((sec_r001058_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_89_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_89_2) + 7) & 255;
    }
  }

  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_90_1 = ((stage_v_90_1 + (it_1 * 3)) + (stage_v_11_1 & 15)) & 63;
    stage_v_90_2 = ((stage_v_90_2 + (it_2 * 3)) + (stage_v_11_2 & 15)) & 63;
    if ((stage_v_11_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_90_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_90_1) + 7) & 255;
    }
    if ((stage_v_11_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_90_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_90_2) + 7) & 255;
    }
  }

  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_91_1 = ((stage_v_91_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_91_2 = ((stage_v_91_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_91_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_91_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_91_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_91_2) + 7) & 255;
    }
  }

  int stage_v_92_1 = ((pub_r001058_8_1 * 2) + 49) & 63;
  int stage_v_92_2 = ((pub_r001058_8_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001058_6_1 * 2) + 42) & 63;
  int stage_v_93_2 = ((pub_r001058_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_94_1 = ((stage_v_94_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_94_2 = ((stage_v_94_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_94_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_94_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_94_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_94_2) + 7) & 255;
    }
  }

  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_95_1 = ((stage_v_95_1 + (it_1 * 3)) + (sec_r001058_5_1 & 15)) & 63;
    stage_v_95_2 = ((stage_v_95_2 + (it_2 * 3)) + (sec_r001058_5_2 & 15)) & 63;
    if ((sec_r001058_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_95_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_95_1) + 7) & 255;
    }
    if ((sec_r001058_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_95_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_95_2) + 7) & 255;
    }
  }

  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_96_1 = ((stage_v_96_1 + (it_1 * 3)) + (stage_v_25_1 & 15)) & 63;
    stage_v_96_2 = ((stage_v_96_2 + (it_2 * 3)) + (stage_v_25_2 & 15)) & 63;
    if ((stage_v_25_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_96_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_96_1) + 7) & 255;
    }
    if ((stage_v_25_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_96_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_96_2) + 7) & 255;
    }
  }

  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_97_1 = ((stage_v_97_1 + (it_1 * 3)) + (helper_flow_3_1 & 15)) & 63;
    stage_v_97_2 = ((stage_v_97_2 + (it_2 * 3)) + (helper_flow_3_2 & 15)) & 63;
    if ((helper_flow_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_97_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_97_1) + 7) & 255;
    }
    if ((helper_flow_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_97_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_97_2) + 7) & 255;
    }
  }

  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_98_1 = ((stage_v_98_1 + (it_1 * 3)) + (sec_r001058_15_1 & 15)) & 63;
    stage_v_98_2 = ((stage_v_98_2 + (it_2 * 3)) + (sec_r001058_15_2 & 15)) & 63;
    if ((sec_r001058_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_98_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_98_1) + 7) & 255;
    }
    if ((sec_r001058_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_98_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_98_2) + 7) & 255;
    }
  }

  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_99_1 = ((stage_v_99_1 + (it_1 * 3)) + (stage_v_89_1 & 15)) & 63;
    stage_v_99_2 = ((stage_v_99_2 + (it_2 * 3)) + (stage_v_89_2 & 15)) & 63;
    if ((stage_v_89_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_99_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_99_1) + 7) & 255;
    }
    if ((stage_v_89_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_99_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_99_2) + 7) & 255;
    }
  }

  int stage_v_100_1 = ((pub_r001058_10_1 * 2) + 14) & 63;
  int stage_v_100_2 = ((pub_r001058_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_101_1 = ((stage_v_101_1 + (it_1 * 3)) + (stage_v_66_1 & 15)) & 63;
    stage_v_101_2 = ((stage_v_101_2 + (it_2 * 3)) + (stage_v_66_2 & 15)) & 63;
    if ((stage_v_66_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_101_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_101_1) + 7) & 255;
    }
    if ((stage_v_66_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_101_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_101_2) + 7) & 255;
    }
  }

  int stage_v_102_1 = ((pub_r001058_17_1 * 2) + 30) & 63;
  int stage_v_102_2 = ((pub_r001058_17_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001058_15_1 * 2) + 32) & 63;
  int stage_v_103_2 = ((pub_r001058_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_104_1 = ((stage_v_104_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_104_2 = ((stage_v_104_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_104_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_104_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_104_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_104_2) + 7) & 255;
    }
  }

  int stage_v_105_1 = ((pub_r001058_9_1 * 2) + 21) & 63;
  int stage_v_105_2 = ((pub_r001058_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_106_1 = ((stage_v_106_1 + (it_1 * 3)) + (stage_v_77_1 & 15)) & 63;
    stage_v_106_2 = ((stage_v_106_2 + (it_2 * 3)) + (stage_v_77_2 & 15)) & 63;
    if ((stage_v_77_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_106_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_106_1) + 7) & 255;
    }
    if ((stage_v_77_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_106_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_106_2) + 7) & 255;
    }
  }

  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_107_1 = ((stage_v_107_1 + (it_1 * 3)) + (stage_v_46_1 & 15)) & 63;
    stage_v_107_2 = ((stage_v_107_2 + (it_2 * 3)) + (stage_v_46_2 & 15)) & 63;
    if ((stage_v_46_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_107_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_107_1) + 7) & 255;
    }
    if ((stage_v_46_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_107_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_107_2) + 7) & 255;
    }
  }

  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_108_1 = ((stage_v_108_1 + (it_1 * 3)) + (stage_v_16_1 & 15)) & 63;
    stage_v_108_2 = ((stage_v_108_2 + (it_2 * 3)) + (stage_v_16_2 & 15)) & 63;
    if ((stage_v_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_108_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_108_1) + 7) & 255;
    }
    if ((stage_v_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_108_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_108_2) + 7) & 255;
    }
  }

  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_109_1 = ((stage_v_109_1 + (it_1 * 3)) + (stage_v_3_1 & 15)) & 63;
    stage_v_109_2 = ((stage_v_109_2 + (it_2 * 3)) + (stage_v_3_2 & 15)) & 63;
    if ((stage_v_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_109_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_109_1) + 7) & 255;
    }
    if ((stage_v_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_109_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_109_2) + 7) & 255;
    }
  }

  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_110_1 = ((stage_v_110_1 + (it_1 * 3)) + (stage_v_37_1 & 15)) & 63;
    stage_v_110_2 = ((stage_v_110_2 + (it_2 * 3)) + (stage_v_37_2 & 15)) & 63;
    if ((stage_v_37_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_110_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_110_1) + 7) & 255;
    }
    if ((stage_v_37_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_110_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_110_2) + 7) & 255;
    }
  }

  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_111_1 = ((stage_v_111_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_111_2 = ((stage_v_111_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_111_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_111_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_111_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_111_2) + 7) & 255;
    }
  }

  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_112_1 = ((stage_v_112_1 + (it_1 * 3)) + (stage_v_35_1 & 15)) & 63;
    stage_v_112_2 = ((stage_v_112_2 + (it_2 * 3)) + (stage_v_35_2 & 15)) & 63;
    if ((stage_v_35_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_112_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_112_1) + 7) & 255;
    }
    if ((stage_v_35_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_112_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_112_2) + 7) & 255;
    }
  }

  int stage_v_113_1 = ((pub_r001058_2_1 * 2) + 24) & 63;
  int stage_v_113_2 = ((pub_r001058_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_114_1 = ((stage_v_114_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_114_2 = ((stage_v_114_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_114_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_114_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_114_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_114_2) + 7) & 255;
    }
  }

  int stage_v_115_1 = ((pub_r001058_3_1 * 2) + 32) & 63;
  int stage_v_115_2 = ((pub_r001058_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001058_20_1 * 2) + 15) & 63;
  int stage_v_116_2 = ((pub_r001058_20_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_117_1 = ((stage_v_117_1 + (it_1 * 3)) + (stage_v_107_1 & 15)) & 63;
    stage_v_117_2 = ((stage_v_117_2 + (it_2 * 3)) + (stage_v_107_2 & 15)) & 63;
    if ((stage_v_107_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_117_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_117_1) + 7) & 255;
    }
    if ((stage_v_107_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_117_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_117_2) + 7) & 255;
    }
  }

  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_118_1 = ((stage_v_118_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_118_2 = ((stage_v_118_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_118_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_118_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_118_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_118_2) + 7) & 255;
    }
  }

  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_119_1 = ((stage_v_119_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_119_2 = ((stage_v_119_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_119_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_119_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_119_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_119_2) + 7) & 255;
    }
  }

  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_120_1 = ((stage_v_120_1 + (it_1 * 3)) + (sec_r001058_13_1 & 15)) & 63;
    stage_v_120_2 = ((stage_v_120_2 + (it_2 * 3)) + (sec_r001058_13_2 & 15)) & 63;
    if ((sec_r001058_13_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_120_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_120_1) + 7) & 255;
    }
    if ((sec_r001058_13_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_120_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_120_2) + 7) & 255;
    }
  }

  int stage_v_121_1 = ((pub_r001058_12_1 * 2) + 29) & 63;
  int stage_v_121_2 = ((pub_r001058_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_122_1 = ((stage_v_122_1 + (it_1 * 3)) + (sec_r001058_10_1 & 15)) & 63;
    stage_v_122_2 = ((stage_v_122_2 + (it_2 * 3)) + (sec_r001058_10_2 & 15)) & 63;
    if ((sec_r001058_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_122_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_122_1) + 7) & 255;
    }
    if ((sec_r001058_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_122_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_122_2) + 7) & 255;
    }
  }

  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_123_1 = ((stage_v_123_1 + (it_1 * 3)) + (stage_v_77_1 & 15)) & 63;
    stage_v_123_2 = ((stage_v_123_2 + (it_2 * 3)) + (stage_v_77_2 & 15)) & 63;
    if ((stage_v_77_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_123_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_123_1) + 7) & 255;
    }
    if ((stage_v_77_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_123_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_123_2) + 7) & 255;
    }
  }

  int stage_v_124_1 = ((pub_r001058_12_1 * 2) + 42) & 63;
  int stage_v_124_2 = ((pub_r001058_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_125_1 = ((stage_v_125_1 + (it_1 * 3)) + (stage_v_35_1 & 15)) & 63;
    stage_v_125_2 = ((stage_v_125_2 + (it_2 * 3)) + (stage_v_35_2 & 15)) & 63;
    if ((stage_v_35_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_125_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_125_1) + 7) & 255;
    }
    if ((stage_v_35_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_125_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_125_2) + 7) & 255;
    }
  }

  int stage_v_126_1 = 0;
  int stage_v_126_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_126_1 = ((stage_v_126_1 + (it_1 * 3)) + (stage_v_12_1 & 15)) & 63;
    stage_v_126_2 = ((stage_v_126_2 + (it_2 * 3)) + (stage_v_12_2 & 15)) & 63;
    if ((stage_v_12_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_126_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_126_1) + 7) & 255;
    }
    if ((stage_v_12_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_126_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_126_2) + 7) & 255;
    }
  }

  int stage_v_127_1 = ((pub_r001058_2_1 * 2) + 6) & 63;
  int stage_v_127_2 = ((pub_r001058_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = 0;
  int stage_v_128_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_128_1 = ((stage_v_128_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_128_2 = ((stage_v_128_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_128_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_128_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_128_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_128_2) + 7) & 255;
    }
  }

  int stage_v_129_1 = 0;
  int stage_v_129_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_129_1 = ((stage_v_129_1 + (it_1 * 3)) + (sec_r001058_16_1 & 15)) & 63;
    stage_v_129_2 = ((stage_v_129_2 + (it_2 * 3)) + (sec_r001058_16_2 & 15)) & 63;
    if ((sec_r001058_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_129_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_129_1) + 7) & 255;
    }
    if ((sec_r001058_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_129_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_129_2) + 7) & 255;
    }
  }

  int stage_v_130_1 = ((pub_r001058_18_1 * 2) + 21) & 63;
  int stage_v_130_2 = ((pub_r001058_18_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = 0;
  int stage_v_131_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_131_1 = ((stage_v_131_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_131_2 = ((stage_v_131_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_131_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_131_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_131_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_131_2) + 7) & 255;
    }
  }

  int stage_v_132_1 = ((pub_r001058_2_1 * 2) + 40) & 63;
  int stage_v_132_2 = ((pub_r001058_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = 0;
  int stage_v_133_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_133_1 = ((stage_v_133_1 + (it_1 * 3)) + (stage_v_95_1 & 15)) & 63;
    stage_v_133_2 = ((stage_v_133_2 + (it_2 * 3)) + (stage_v_95_2 & 15)) & 63;
    if ((stage_v_95_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_133_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_133_1) + 7) & 255;
    }
    if ((stage_v_95_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_133_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_133_2) + 7) & 255;
    }
  }

  int stage_v_134_1 = ((pub_r001058_2_1 * 2) + 42) & 63;
  int stage_v_134_2 = ((pub_r001058_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = 0;
  int stage_v_135_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_135_1 = ((stage_v_135_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_135_2 = ((stage_v_135_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_135_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_135_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_135_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_135_2) + 7) & 255;
    }
  }

  int stage_v_136_1 = 0;
  int stage_v_136_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_136_1 = ((stage_v_136_1 + (it_1 * 3)) + (sec_r001058_3_1 & 15)) & 63;
    stage_v_136_2 = ((stage_v_136_2 + (it_2 * 3)) + (sec_r001058_3_2 & 15)) & 63;
    if ((sec_r001058_3_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_136_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_136_1) + 7) & 255;
    }
    if ((sec_r001058_3_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_136_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_136_2) + 7) & 255;
    }
  }

  int stage_v_137_1 = ((pub_r001058_13_1 * 2) + 20) & 63;
  int stage_v_137_2 = ((pub_r001058_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = 0;
  int stage_v_138_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_138_1 = ((stage_v_138_1 + (it_1 * 3)) + (helper_flow_1_1 & 15)) & 63;
    stage_v_138_2 = ((stage_v_138_2 + (it_2 * 3)) + (helper_flow_1_2 & 15)) & 63;
    if ((helper_flow_1_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_138_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_138_1) + 7) & 255;
    }
    if ((helper_flow_1_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_138_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_138_2) + 7) & 255;
    }
  }

  int stage_v_139_1 = 0;
  int stage_v_139_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_139_1 = ((stage_v_139_1 + (it_1 * 3)) + (stage_v_81_1 & 15)) & 63;
    stage_v_139_2 = ((stage_v_139_2 + (it_2 * 3)) + (stage_v_81_2 & 15)) & 63;
    if ((stage_v_81_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_139_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_139_1) + 7) & 255;
    }
    if ((stage_v_81_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_139_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_139_2) + 7) & 255;
    }
  }

  int stage_v_140_1 = 0;
  int stage_v_140_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_140_1 = ((stage_v_140_1 + (it_1 * 3)) + (stage_v_96_1 & 15)) & 63;
    stage_v_140_2 = ((stage_v_140_2 + (it_2 * 3)) + (stage_v_96_2 & 15)) & 63;
    if ((stage_v_96_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_140_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_140_1) + 7) & 255;
    }
    if ((stage_v_96_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_140_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_140_2) + 7) & 255;
    }
  }

  int stage_v_141_1 = 0;
  int stage_v_141_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_141_1 = ((stage_v_141_1 + (it_1 * 3)) + (stage_v_23_1 & 15)) & 63;
    stage_v_141_2 = ((stage_v_141_2 + (it_2 * 3)) + (stage_v_23_2 & 15)) & 63;
    if ((stage_v_23_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_141_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_141_1) + 7) & 255;
    }
    if ((stage_v_23_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_141_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_141_2) + 7) & 255;
    }
  }

  int stage_v_142_1 = ((pub_r001058_4_1 * 2) + 31) & 63;
  int stage_v_142_2 = ((pub_r001058_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001058_19_1 * 2) + 9) & 63;
  int stage_v_143_2 = ((pub_r001058_19_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = 0;
  int stage_v_144_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_144_1 = ((stage_v_144_1 + (it_1 * 3)) + (sec_r001058_22_1 & 15)) & 63;
    stage_v_144_2 = ((stage_v_144_2 + (it_2 * 3)) + (sec_r001058_22_2 & 15)) & 63;
    if ((sec_r001058_22_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_144_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_144_1) + 7) & 255;
    }
    if ((sec_r001058_22_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_144_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_144_2) + 7) & 255;
    }
  }

  int stage_v_145_1 = ((pub_r001058_7_1 * 2) + 37) & 63;
  int stage_v_145_2 = ((pub_r001058_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = 0;
  int stage_v_146_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_146_1 = ((stage_v_146_1 + (it_1 * 3)) + (stage_v_57_1 & 15)) & 63;
    stage_v_146_2 = ((stage_v_146_2 + (it_2 * 3)) + (stage_v_57_2 & 15)) & 63;
    if ((stage_v_57_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_146_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_146_1) + 7) & 255;
    }
    if ((stage_v_57_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_146_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_146_2) + 7) & 255;
    }
  }

  int stage_v_147_1 = 0;
  int stage_v_147_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_147_1 = ((stage_v_147_1 + (it_1 * 3)) + (stage_v_108_1 & 15)) & 63;
    stage_v_147_2 = ((stage_v_147_2 + (it_2 * 3)) + (stage_v_108_2 & 15)) & 63;
    if ((stage_v_108_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_147_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_147_1) + 7) & 255;
    }
    if ((stage_v_108_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_147_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_147_2) + 7) & 255;
    }
  }

  int stage_v_148_1 = ((pub_r001058_18_1 * 2) + 31) & 63;
  int stage_v_148_2 = ((pub_r001058_18_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = 0;
  int stage_v_149_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_149_1 = ((stage_v_149_1 + (it_1 * 3)) + (stage_v_91_1 & 15)) & 63;
    stage_v_149_2 = ((stage_v_149_2 + (it_2 * 3)) + (stage_v_91_2 & 15)) & 63;
    if ((stage_v_91_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_149_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_149_1) + 7) & 255;
    }
    if ((stage_v_91_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_149_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_149_2) + 7) & 255;
    }
  }

  int stage_v_150_1 = ((pub_r001058_7_1 * 2) + 33) & 63;
  int stage_v_150_2 = ((pub_r001058_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001058_4_1 * 2) + 11) & 63;
  int stage_v_151_2 = ((pub_r001058_4_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = 0;
  int stage_v_152_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_152_1 = ((stage_v_152_1 + (it_1 * 3)) + (stage_v_108_1 & 15)) & 63;
    stage_v_152_2 = ((stage_v_152_2 + (it_2 * 3)) + (stage_v_108_2 & 15)) & 63;
    if ((stage_v_108_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_152_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_152_1) + 7) & 255;
    }
    if ((stage_v_108_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_152_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_152_2) + 7) & 255;
    }
  }

  int stage_v_153_1 = 0;
  int stage_v_153_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_153_1 = ((stage_v_153_1 + (it_1 * 3)) + (sec_r001058_9_1 & 15)) & 63;
    stage_v_153_2 = ((stage_v_153_2 + (it_2 * 3)) + (sec_r001058_9_2 & 15)) & 63;
    if ((sec_r001058_9_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_153_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_153_1) + 7) & 255;
    }
    if ((sec_r001058_9_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_153_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_153_2) + 7) & 255;
    }
  }

  int stage_v_154_1 = ((pub_r001058_14_1 * 2) + 28) & 63;
  int stage_v_154_2 = ((pub_r001058_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = 0;
  int stage_v_155_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_155_1 = ((stage_v_155_1 + (it_1 * 3)) + (sec_r001058_17_1 & 15)) & 63;
    stage_v_155_2 = ((stage_v_155_2 + (it_2 * 3)) + (sec_r001058_17_2 & 15)) & 63;
    if ((sec_r001058_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_155_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_155_1) + 7) & 255;
    }
    if ((sec_r001058_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_155_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_155_2) + 7) & 255;
    }
  }

  int stage_v_156_1 = 0;
  int stage_v_156_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_156_1 = ((stage_v_156_1 + (it_1 * 3)) + (stage_v_111_1 & 15)) & 63;
    stage_v_156_2 = ((stage_v_156_2 + (it_2 * 3)) + (stage_v_111_2 & 15)) & 63;
    if ((stage_v_111_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_156_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_156_1) + 7) & 255;
    }
    if ((stage_v_111_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_156_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_156_2) + 7) & 255;
    }
  }

  int stage_v_157_1 = ((pub_r001058_1_1 * 2) + 28) & 63;
  int stage_v_157_2 = ((pub_r001058_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = 0;
  int stage_v_158_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_158_1 = ((stage_v_158_1 + (it_1 * 3)) + (stage_v_110_1 & 15)) & 63;
    stage_v_158_2 = ((stage_v_158_2 + (it_2 * 3)) + (stage_v_110_2 & 15)) & 63;
    if ((stage_v_110_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_158_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_158_1) + 7) & 255;
    }
    if ((stage_v_110_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_158_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_158_2) + 7) & 255;
    }
  }

  int stage_v_159_1 = 0;
  int stage_v_159_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_159_1 = ((stage_v_159_1 + (it_1 * 3)) + (sec_r001058_14_1 & 15)) & 63;
    stage_v_159_2 = ((stage_v_159_2 + (it_2 * 3)) + (sec_r001058_14_2 & 15)) & 63;
    if ((sec_r001058_14_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_159_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_159_1) + 7) & 255;
    }
    if ((sec_r001058_14_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_159_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_159_2) + 7) & 255;
    }
  }

  int stage_v_160_1 = 0;
  int stage_v_160_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_160_1 = ((stage_v_160_1 + (it_1 * 3)) + (stage_v_153_1 & 15)) & 63;
    stage_v_160_2 = ((stage_v_160_2 + (it_2 * 3)) + (stage_v_153_2 & 15)) & 63;
    if ((stage_v_153_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_160_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_160_1) + 7) & 255;
    }
    if ((stage_v_153_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_160_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_160_2) + 7) & 255;
    }
  }

  int stage_v_161_1 = 0;
  int stage_v_161_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_161_1 = ((stage_v_161_1 + (it_1 * 3)) + (stage_v_10_1 & 15)) & 63;
    stage_v_161_2 = ((stage_v_161_2 + (it_2 * 3)) + (stage_v_10_2 & 15)) & 63;
    if ((stage_v_10_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_161_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_161_1) + 7) & 255;
    }
    if ((stage_v_10_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_161_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_161_2) + 7) & 255;
    }
  }

  int stage_v_162_1 = 0;
  int stage_v_162_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_162_1 = ((stage_v_162_1 + (it_1 * 3)) + (helper_flow_5_1 & 15)) & 63;
    stage_v_162_2 = ((stage_v_162_2 + (it_2 * 3)) + (helper_flow_5_2 & 15)) & 63;
    if ((helper_flow_5_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_162_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_162_1) + 7) & 255;
    }
    if ((helper_flow_5_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_162_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_162_2) + 7) & 255;
    }
  }

  int stage_v_163_1 = 0;
  int stage_v_163_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_163_1 = ((stage_v_163_1 + (it_1 * 3)) + (stage_v_131_1 & 15)) & 63;
    stage_v_163_2 = ((stage_v_163_2 + (it_2 * 3)) + (stage_v_131_2 & 15)) & 63;
    if ((stage_v_131_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_163_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_163_1) + 7) & 255;
    }
    if ((stage_v_131_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_163_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_163_2) + 7) & 255;
    }
  }

  int stage_v_164_1 = 0;
  int stage_v_164_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_164_1 = ((stage_v_164_1 + (it_1 * 3)) + (stage_v_74_1 & 15)) & 63;
    stage_v_164_2 = ((stage_v_164_2 + (it_2 * 3)) + (stage_v_74_2 & 15)) & 63;
    if ((stage_v_74_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_164_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_164_1) + 7) & 255;
    }
    if ((stage_v_74_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_164_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_164_2) + 7) & 255;
    }
  }

  int stage_v_165_1 = ((pub_r001058_18_1 * 2) + 20) & 63;
  int stage_v_165_2 = ((pub_r001058_18_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = 0;
  int stage_v_166_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_166_1 = ((stage_v_166_1 + (it_1 * 3)) + (stage_v_90_1 & 15)) & 63;
    stage_v_166_2 = ((stage_v_166_2 + (it_2 * 3)) + (stage_v_90_2 & 15)) & 63;
    if ((stage_v_90_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_166_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_166_1) + 7) & 255;
    }
    if ((stage_v_90_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_166_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_166_2) + 7) & 255;
    }
  }

  int stage_v_167_1 = ((pub_r001058_2_1 * 2) + 9) & 63;
  int stage_v_167_2 = ((pub_r001058_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = 0;
  int stage_v_168_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_168_1 = ((stage_v_168_1 + (it_1 * 3)) + (stage_v_160_1 & 15)) & 63;
    stage_v_168_2 = ((stage_v_168_2 + (it_2 * 3)) + (stage_v_160_2 & 15)) & 63;
    if ((stage_v_160_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_168_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_168_1) + 7) & 255;
    }
    if ((stage_v_160_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_168_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_168_2) + 7) & 255;
    }
  }

  int stage_v_169_1 = 0;
  int stage_v_169_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_169_1 = ((stage_v_169_1 + (it_1 * 3)) + (sec_r001058_17_1 & 15)) & 63;
    stage_v_169_2 = ((stage_v_169_2 + (it_2 * 3)) + (sec_r001058_17_2 & 15)) & 63;
    if ((sec_r001058_17_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_169_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_169_1) + 7) & 255;
    }
    if ((sec_r001058_17_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_169_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_169_2) + 7) & 255;
    }
  }

  int stage_v_170_1 = ((pub_r001058_13_1 * 2) + 43) & 63;
  int stage_v_170_2 = ((pub_r001058_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = 0;
  int stage_v_171_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_171_1 = ((stage_v_171_1 + (it_1 * 3)) + (helper_flow_2_1 & 15)) & 63;
    stage_v_171_2 = ((stage_v_171_2 + (it_2 * 3)) + (helper_flow_2_2 & 15)) & 63;
    if ((helper_flow_2_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_171_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_171_1) + 7) & 255;
    }
    if ((helper_flow_2_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_171_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_171_2) + 7) & 255;
    }
  }

  int stage_v_172_1 = 0;
  int stage_v_172_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_172_1 = ((stage_v_172_1 + (it_1 * 3)) + (stage_v_25_1 & 15)) & 63;
    stage_v_172_2 = ((stage_v_172_2 + (it_2 * 3)) + (stage_v_25_2 & 15)) & 63;
    if ((stage_v_25_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_172_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_172_1) + 7) & 255;
    }
    if ((stage_v_25_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_172_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_172_2) + 7) & 255;
    }
  }

  int stage_v_173_1 = ((pub_r001058_21_1 * 2) + 34) & 63;
  int stage_v_173_2 = ((pub_r001058_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001058_12_1 * 2) + 23) & 63;
  int stage_v_174_2 = ((pub_r001058_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = 0;
  int stage_v_175_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_175_1 = ((stage_v_175_1 + (it_1 * 3)) + (stage_v_57_1 & 15)) & 63;
    stage_v_175_2 = ((stage_v_175_2 + (it_2 * 3)) + (stage_v_57_2 & 15)) & 63;
    if ((stage_v_57_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_175_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_175_1) + 7) & 255;
    }
    if ((stage_v_57_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_175_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_175_2) + 7) & 255;
    }
  }

  int stage_v_176_1 = 0;
  int stage_v_176_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_176_1 = ((stage_v_176_1 + (it_1 * 3)) + (stage_v_112_1 & 15)) & 63;
    stage_v_176_2 = ((stage_v_176_2 + (it_2 * 3)) + (stage_v_112_2 & 15)) & 63;
    if ((stage_v_112_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_176_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_176_1) + 7) & 255;
    }
    if ((stage_v_112_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_176_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_176_2) + 7) & 255;
    }
  }

  int stage_v_177_1 = 0;
  int stage_v_177_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_177_1 = ((stage_v_177_1 + (it_1 * 3)) + (stage_v_161_1 & 15)) & 63;
    stage_v_177_2 = ((stage_v_177_2 + (it_2 * 3)) + (stage_v_161_2 & 15)) & 63;
    if ((stage_v_161_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_177_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_177_1) + 7) & 255;
    }
    if ((stage_v_161_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_177_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_177_2) + 7) & 255;
    }
  }

  int stage_v_178_1 = ((pub_r001058_18_1 * 2) + 22) & 63;
  int stage_v_178_2 = ((pub_r001058_18_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001058_17_1 * 2) + 20) & 63;
  int stage_v_179_2 = ((pub_r001058_17_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001058_6_1 * 2) + 31) & 63;
  int stage_v_180_2 = ((pub_r001058_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001058_20_1 * 2) + 10) & 63;
  int stage_v_181_2 = ((pub_r001058_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001058_2_1 * 2) + 19) & 63;
  int stage_v_182_2 = ((pub_r001058_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = 0;
  int stage_v_183_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_183_1 = ((stage_v_183_1 + (it_1 * 3)) + (stage_v_32_1 & 15)) & 63;
    stage_v_183_2 = ((stage_v_183_2 + (it_2 * 3)) + (stage_v_32_2 & 15)) & 63;
    if ((stage_v_32_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_183_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_183_1) + 7) & 255;
    }
    if ((stage_v_32_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_183_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_183_2) + 7) & 255;
    }
  }

  int stage_v_184_1 = ((pub_r001058_18_1 * 2) + 46) & 63;
  int stage_v_184_2 = ((pub_r001058_18_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001058_17_1 * 2) + 50) & 63;
  int stage_v_185_2 = ((pub_r001058_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = 0;
  int stage_v_186_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_186_1 = ((stage_v_186_1 + (it_1 * 3)) + (sec_r001058_8_1 & 15)) & 63;
    stage_v_186_2 = ((stage_v_186_2 + (it_2 * 3)) + (sec_r001058_8_2 & 15)) & 63;
    if ((sec_r001058_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_186_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_186_1) + 7) & 255;
    }
    if ((sec_r001058_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_186_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_186_2) + 7) & 255;
    }
  }

  int stage_v_187_1 = 0;
  int stage_v_187_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_187_1 = ((stage_v_187_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_187_2 = ((stage_v_187_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_187_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_187_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_187_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_187_2) + 7) & 255;
    }
  }

  int stage_v_188_1 = 0;
  int stage_v_188_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_188_1 = ((stage_v_188_1 + (it_1 * 3)) + (stage_v_140_1 & 15)) & 63;
    stage_v_188_2 = ((stage_v_188_2 + (it_2 * 3)) + (stage_v_140_2 & 15)) & 63;
    if ((stage_v_140_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_188_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_188_1) + 7) & 255;
    }
    if ((stage_v_140_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_188_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_188_2) + 7) & 255;
    }
  }

  int stage_v_189_1 = ((pub_r001058_12_1 * 2) + 7) & 63;
  int stage_v_189_2 = ((pub_r001058_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001058_14_1 * 2) + 32) & 63;
  int stage_v_190_2 = ((pub_r001058_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001058_16_1 * 2) + 23) & 63;
  int stage_v_191_2 = ((pub_r001058_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = 0;
  int stage_v_192_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_192_1 = ((stage_v_192_1 + (it_1 * 3)) + (sec_r001058_16_1 & 15)) & 63;
    stage_v_192_2 = ((stage_v_192_2 + (it_2 * 3)) + (sec_r001058_16_2 & 15)) & 63;
    if ((sec_r001058_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_192_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_192_1) + 7) & 255;
    }
    if ((sec_r001058_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_192_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_192_2) + 7) & 255;
    }
  }

  int stage_v_193_1 = 0;
  int stage_v_193_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_193_1 = ((stage_v_193_1 + (it_1 * 3)) + (stage_v_74_1 & 15)) & 63;
    stage_v_193_2 = ((stage_v_193_2 + (it_2 * 3)) + (stage_v_74_2 & 15)) & 63;
    if ((stage_v_74_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_193_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_193_1) + 7) & 255;
    }
    if ((stage_v_74_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_193_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_193_2) + 7) & 255;
    }
  }

  int stage_v_194_1 = 0;
  int stage_v_194_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_194_1 = ((stage_v_194_1 + (it_1 * 3)) + (stage_v_193_1 & 15)) & 63;
    stage_v_194_2 = ((stage_v_194_2 + (it_2 * 3)) + (stage_v_193_2 & 15)) & 63;
    if ((stage_v_193_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_194_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_194_1) + 7) & 255;
    }
    if ((stage_v_193_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_194_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_194_2) + 7) & 255;
    }
  }

  int stage_v_195_1 = ((pub_r001058_0_1 * 2) + 43) & 63;
  int stage_v_195_2 = ((pub_r001058_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = 0;
  int stage_v_196_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_196_1 = ((stage_v_196_1 + (it_1 * 3)) + (stage_v_107_1 & 15)) & 63;
    stage_v_196_2 = ((stage_v_196_2 + (it_2 * 3)) + (stage_v_107_2 & 15)) & 63;
    if ((stage_v_107_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_196_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_196_1) + 7) & 255;
    }
    if ((stage_v_107_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_196_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_196_2) + 7) & 255;
    }
  }

  int stage_v_197_1 = ((pub_r001058_21_1 * 2) + 11) & 63;
  int stage_v_197_2 = ((pub_r001058_21_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001058_14_1 * 2) + 39) & 63;
  int stage_v_198_2 = ((pub_r001058_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001058_15_1 * 2) + 14) & 63;
  int stage_v_199_2 = ((pub_r001058_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001058_11_1 * 2) + 21) & 63;
  int stage_v_200_2 = ((pub_r001058_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = 0;
  int stage_v_201_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_201_1 = ((stage_v_201_1 + (it_1 * 3)) + (stage_v_156_1 & 15)) & 63;
    stage_v_201_2 = ((stage_v_201_2 + (it_2 * 3)) + (stage_v_156_2 & 15)) & 63;
    if ((stage_v_156_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_201_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_201_1) + 7) & 255;
    }
    if ((stage_v_156_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_201_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_201_2) + 7) & 255;
    }
  }

  int stage_v_202_1 = ((pub_r001058_3_1 * 2) + 46) & 63;
  int stage_v_202_2 = ((pub_r001058_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = 0;
  int stage_v_203_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_203_1 = ((stage_v_203_1 + (it_1 * 3)) + (stage_v_83_1 & 15)) & 63;
    stage_v_203_2 = ((stage_v_203_2 + (it_2 * 3)) + (stage_v_83_2 & 15)) & 63;
    if ((stage_v_83_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_203_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_203_1) + 7) & 255;
    }
    if ((stage_v_83_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_203_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_203_2) + 7) & 255;
    }
  }

  int stage_v_204_1 = 0;
  int stage_v_204_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_204_1 = ((stage_v_204_1 + (it_1 * 3)) + (stage_v_85_1 & 15)) & 63;
    stage_v_204_2 = ((stage_v_204_2 + (it_2 * 3)) + (stage_v_85_2 & 15)) & 63;
    if ((stage_v_85_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_204_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_204_1) + 7) & 255;
    }
    if ((stage_v_85_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_204_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_204_2) + 7) & 255;
    }
  }

  int stage_v_205_1 = 0;
  int stage_v_205_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_205_1 = ((stage_v_205_1 + (it_1 * 3)) + (sec_r001058_8_1 & 15)) & 63;
    stage_v_205_2 = ((stage_v_205_2 + (it_2 * 3)) + (sec_r001058_8_2 & 15)) & 63;
    if ((sec_r001058_8_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_205_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_205_1) + 7) & 255;
    }
    if ((sec_r001058_8_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_205_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_205_2) + 7) & 255;
    }
  }

  int stage_v_206_1 = ((pub_r001058_13_1 * 2) + 16) & 63;
  int stage_v_206_2 = ((pub_r001058_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001058_10_1 * 2) + 16) & 63;
  int stage_v_207_2 = ((pub_r001058_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = 0;
  int stage_v_208_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_208_1 = ((stage_v_208_1 + (it_1 * 3)) + (stage_v_133_1 & 15)) & 63;
    stage_v_208_2 = ((stage_v_208_2 + (it_2 * 3)) + (stage_v_133_2 & 15)) & 63;
    if ((stage_v_133_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_208_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_208_1) + 7) & 255;
    }
    if ((stage_v_133_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_208_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_208_2) + 7) & 255;
    }
  }

  int stage_v_209_1 = 0;
  int stage_v_209_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_209_1 = ((stage_v_209_1 + (it_1 * 3)) + (stage_v_80_1 & 15)) & 63;
    stage_v_209_2 = ((stage_v_209_2 + (it_2 * 3)) + (stage_v_80_2 & 15)) & 63;
    if ((stage_v_80_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_209_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_209_1) + 7) & 255;
    }
    if ((stage_v_80_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_209_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_209_2) + 7) & 255;
    }
  }

  int stage_v_210_1 = 0;
  int stage_v_210_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_210_1 = ((stage_v_210_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_210_2 = ((stage_v_210_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_210_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_210_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_210_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_210_2) + 7) & 255;
    }
  }

  int stage_v_211_1 = 0;
  int stage_v_211_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_211_1 = ((stage_v_211_1 + (it_1 * 3)) + (stage_v_144_1 & 15)) & 63;
    stage_v_211_2 = ((stage_v_211_2 + (it_2 * 3)) + (stage_v_144_2 & 15)) & 63;
    if ((stage_v_144_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_211_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_211_1) + 7) & 255;
    }
    if ((stage_v_144_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_211_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_211_2) + 7) & 255;
    }
  }

  int stage_v_212_1 = 0;
  int stage_v_212_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_212_1 = ((stage_v_212_1 + (it_1 * 3)) + (stage_v_44_1 & 15)) & 63;
    stage_v_212_2 = ((stage_v_212_2 + (it_2 * 3)) + (stage_v_44_2 & 15)) & 63;
    if ((stage_v_44_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_212_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_212_1) + 7) & 255;
    }
    if ((stage_v_44_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_212_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_212_2) + 7) & 255;
    }
  }

  int stage_v_213_1 = ((pub_r001058_15_1 * 2) + 36) & 63;
  int stage_v_213_2 = ((pub_r001058_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = 0;
  int stage_v_214_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_214_1 = ((stage_v_214_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_214_2 = ((stage_v_214_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_214_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_214_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_214_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_214_2) + 7) & 255;
    }
  }

  int stage_v_215_1 = 0;
  int stage_v_215_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_215_1 = ((stage_v_215_1 + (it_1 * 3)) + (stage_v_94_1 & 15)) & 63;
    stage_v_215_2 = ((stage_v_215_2 + (it_2 * 3)) + (stage_v_94_2 & 15)) & 63;
    if ((stage_v_94_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_215_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_215_1) + 7) & 255;
    }
    if ((stage_v_94_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_215_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_215_2) + 7) & 255;
    }
  }

  int stage_v_216_1 = ((pub_r001058_6_1 * 2) + 6) & 63;
  int stage_v_216_2 = ((pub_r001058_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001058_18_1 * 2) + 29) & 63;
  int stage_v_217_2 = ((pub_r001058_18_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = 0;
  int stage_v_218_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_218_1 = ((stage_v_218_1 + (it_1 * 3)) + (sec_r001058_16_1 & 15)) & 63;
    stage_v_218_2 = ((stage_v_218_2 + (it_2 * 3)) + (sec_r001058_16_2 & 15)) & 63;
    if ((sec_r001058_16_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_218_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_218_1) + 7) & 255;
    }
    if ((sec_r001058_16_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_218_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_218_2) + 7) & 255;
    }
  }

  int stage_v_219_1 = ((pub_r001058_18_1 * 2) + 39) & 63;
  int stage_v_219_2 = ((pub_r001058_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = 0;
  int stage_v_220_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_220_1 = ((stage_v_220_1 + (it_1 * 3)) + (sec_r001058_15_1 & 15)) & 63;
    stage_v_220_2 = ((stage_v_220_2 + (it_2 * 3)) + (sec_r001058_15_2 & 15)) & 63;
    if ((sec_r001058_15_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_220_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_220_1) + 7) & 255;
    }
    if ((sec_r001058_15_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_220_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_220_2) + 7) & 255;
    }
  }

  int stage_v_221_1 = 0;
  int stage_v_221_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_221_1 = ((stage_v_221_1 + (it_1 * 3)) + (helper_flow_6_1 & 15)) & 63;
    stage_v_221_2 = ((stage_v_221_2 + (it_2 * 3)) + (helper_flow_6_2 & 15)) & 63;
    if ((helper_flow_6_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_221_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_221_1) + 7) & 255;
    }
    if ((helper_flow_6_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_221_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_221_2) + 7) & 255;
    }
  }

  int stage_v_222_1 = 0;
  int stage_v_222_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_222_1 = ((stage_v_222_1 + (it_1 * 3)) + (stage_v_21_1 & 15)) & 63;
    stage_v_222_2 = ((stage_v_222_2 + (it_2 * 3)) + (stage_v_21_2 & 15)) & 63;
    if ((stage_v_21_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_222_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_222_1) + 7) & 255;
    }
    if ((stage_v_21_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_222_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_222_2) + 7) & 255;
    }
  }

  int stage_v_223_1 = ((pub_r001058_13_1 * 2) + 40) & 63;
  int stage_v_223_2 = ((pub_r001058_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = 0;
  int stage_v_224_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_224_1 = ((stage_v_224_1 + (it_1 * 3)) + (stage_v_140_1 & 15)) & 63;
    stage_v_224_2 = ((stage_v_224_2 + (it_2 * 3)) + (stage_v_140_2 & 15)) & 63;
    if ((stage_v_140_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_224_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_224_1) + 7) & 255;
    }
    if ((stage_v_140_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_224_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_224_2) + 7) & 255;
    }
  }

  int stage_v_225_1 = 0;
  int stage_v_225_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_225_1 = ((stage_v_225_1 + (it_1 * 3)) + (stage_v_212_1 & 15)) & 63;
    stage_v_225_2 = ((stage_v_225_2 + (it_2 * 3)) + (stage_v_212_2 & 15)) & 63;
    if ((stage_v_212_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_225_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_225_1) + 7) & 255;
    }
    if ((stage_v_212_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_225_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_225_2) + 7) & 255;
    }
  }

  int stage_v_226_1 = 0;
  int stage_v_226_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_226_1 = ((stage_v_226_1 + (it_1 * 3)) + (helper_flow_0_1 & 15)) & 63;
    stage_v_226_2 = ((stage_v_226_2 + (it_2 * 3)) + (helper_flow_0_2 & 15)) & 63;
    if ((helper_flow_0_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_226_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_226_1) + 7) & 255;
    }
    if ((helper_flow_0_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_226_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_226_2) + 7) & 255;
    }
  }

  int stage_v_227_1 = ((pub_r001058_11_1 * 2) + 40) & 63;
  int stage_v_227_2 = ((pub_r001058_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = ((pub_r001058_5_1 * 2) + 21) & 63;
  int stage_v_228_2 = ((pub_r001058_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = 0;
  int stage_v_229_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_229_1 = ((stage_v_229_1 + (it_1 * 3)) + (stage_v_175_1 & 15)) & 63;
    stage_v_229_2 = ((stage_v_229_2 + (it_2 * 3)) + (stage_v_175_2 & 15)) & 63;
    if ((stage_v_175_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_229_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_229_1) + 7) & 255;
    }
    if ((stage_v_175_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_229_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_229_2) + 7) & 255;
    }
  }

  int stage_v_230_1 = ((pub_r001058_1_1 * 2) + 41) & 63;
  int stage_v_230_2 = ((pub_r001058_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = 0;
  int stage_v_231_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_231_1 = ((stage_v_231_1 + (it_1 * 3)) + (stage_v_136_1 & 15)) & 63;
    stage_v_231_2 = ((stage_v_231_2 + (it_2 * 3)) + (stage_v_136_2 & 15)) & 63;
    if ((stage_v_136_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_231_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_231_1) + 7) & 255;
    }
    if ((stage_v_136_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_231_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_231_2) + 7) & 255;
    }
  }

  int stage_v_232_1 = 0;
  int stage_v_232_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_232_1 = ((stage_v_232_1 + (it_1 * 3)) + (stage_v_149_1 & 15)) & 63;
    stage_v_232_2 = ((stage_v_232_2 + (it_2 * 3)) + (stage_v_149_2 & 15)) & 63;
    if ((stage_v_149_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_232_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_232_1) + 7) & 255;
    }
    if ((stage_v_149_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_232_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_232_2) + 7) & 255;
    }
  }

  int stage_v_233_1 = 0;
  int stage_v_233_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_233_1 = ((stage_v_233_1 + (it_1 * 3)) + (stage_v_188_1 & 15)) & 63;
    stage_v_233_2 = ((stage_v_233_2 + (it_2 * 3)) + (stage_v_188_2 & 15)) & 63;
    if ((stage_v_188_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_233_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_233_1) + 7) & 255;
    }
    if ((stage_v_188_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_233_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_233_2) + 7) & 255;
    }
  }

  int stage_v_234_1 = 0;
  int stage_v_234_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_234_1 = ((stage_v_234_1 + (it_1 * 3)) + (stage_v_128_1 & 15)) & 63;
    stage_v_234_2 = ((stage_v_234_2 + (it_2 * 3)) + (stage_v_128_2 & 15)) & 63;
    if ((stage_v_128_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_234_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_234_1) + 7) & 255;
    }
    if ((stage_v_128_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_234_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_234_2) + 7) & 255;
    }
  }

  int stage_v_235_1 = ((pub_r001058_1_1 * 2) + 20) & 63;
  int stage_v_235_2 = ((pub_r001058_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = 0;
  int stage_v_236_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_236_1 = ((stage_v_236_1 + (it_1 * 3)) + (stage_v_186_1 & 15)) & 63;
    stage_v_236_2 = ((stage_v_236_2 + (it_2 * 3)) + (stage_v_186_2 & 15)) & 63;
    if ((stage_v_186_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_236_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_236_1) + 7) & 255;
    }
    if ((stage_v_186_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_236_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_236_2) + 7) & 255;
    }
  }

  int stage_v_237_1 = 0;
  int stage_v_237_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_237_1 = ((stage_v_237_1 + (it_1 * 3)) + (sec_r001058_19_1 & 15)) & 63;
    stage_v_237_2 = ((stage_v_237_2 + (it_2 * 3)) + (sec_r001058_19_2 & 15)) & 63;
    if ((sec_r001058_19_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_237_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_237_1) + 7) & 255;
    }
    if ((sec_r001058_19_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_237_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_237_2) + 7) & 255;
    }
  }

  int stage_v_238_1 = 0;
  int stage_v_238_2 = 0;
  for (int it_1 = 0, it_2 = 0; (it_1 < 2) && (it_2 < 2); it_1++, it_2++)
  {
    stage_v_238_1 = ((stage_v_238_1 + (it_1 * 3)) + (stage_v_4_1 & 15)) & 63;
    stage_v_238_2 = ((stage_v_238_2 + (it_2 * 3)) + (stage_v_4_2 & 15)) & 63;
    if ((stage_v_4_1 & 1) != 0)
    {
      sec_accum_1 = ((sec_accum_1 + stage_v_238_1) + 3) & 255;
    }
    else
    {
      sec_accum_1 = ((sec_accum_1 - stage_v_238_1) + 7) & 255;
    }
    if ((stage_v_4_2 & 1) != 0)
    {
      sec_accum_2 = ((sec_accum_2 + stage_v_238_2) + 3) & 255;
    }
    else
    {
      sec_accum_2 = ((sec_accum_2 - stage_v_238_2) + 7) & 255;
    }
  }

  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001058_3_1 == pub_r001058_3_2);
  __CPROVER_assume(pub_r001058_5_1 == pub_r001058_5_2);
  __CPROVER_assume(sec_r001058_15_1 != sec_r001058_15_2);
  __CPROVER_assume(pub_r001058_1_1 == pub_r001058_1_2);
  __CPROVER_assume(pub_r001058_12_1 == pub_r001058_12_2);
  __CPROVER_assume(sec_r001058_10_1 != sec_r001058_10_2);
  __CPROVER_assume(sec_r001058_19_1 != sec_r001058_19_2);
  __CPROVER_assume(sec_r001058_16_1 != sec_r001058_16_2);
  __CPROVER_assume(sec_r001058_8_1 != sec_r001058_8_2);
  __CPROVER_assume(sec_r001058_9_1 != sec_r001058_9_2);
  __CPROVER_assume(pub_r001058_6_1 == pub_r001058_6_2);
  __CPROVER_assume(sec_r001058_11_1 != sec_r001058_11_2);
  __CPROVER_assume(pub_r001058_8_1 == pub_r001058_8_2);
  __CPROVER_assume(pub_r001058_7_1 == pub_r001058_7_2);
  __CPROVER_assume(pub_r001058_11_1 == pub_r001058_11_2);
  __CPROVER_assume(sec_r001058_20_1 != sec_r001058_20_2);
  __CPROVER_assume(sec_r001058_1_1 != sec_r001058_1_2);
  __CPROVER_assume(pub_r001058_19_1 == pub_r001058_19_2);
  __CPROVER_assume(sec_r001058_14_1 != sec_r001058_14_2);
  __CPROVER_assume(sec_r001058_4_1 != sec_r001058_4_2);
  __CPROVER_assume(sec_r001058_0_1 != sec_r001058_0_2);
  __CPROVER_assume(pub_r001058_13_1 == pub_r001058_13_2);
  __CPROVER_assume(pub_r001058_17_1 == pub_r001058_17_2);
  __CPROVER_assume(pub_r001058_20_1 == pub_r001058_20_2);
  __CPROVER_assume(pub_r001058_2_1 == pub_r001058_2_2);
  __CPROVER_assume(sec_r001058_22_1 != sec_r001058_22_2);
  __CPROVER_assume(sec_r001058_13_1 != sec_r001058_13_2);
  __CPROVER_assume(pub_r001058_15_1 == pub_r001058_15_2);
  __CPROVER_assume(pub_r001058_9_1 == pub_r001058_9_2);
  __CPROVER_assume(sec_r001058_18_1 != sec_r001058_18_2);
  __CPROVER_assume(pub_r001058_21_1 == pub_r001058_21_2);
  __CPROVER_assume(sec_r001058_6_1 != sec_r001058_6_2);
  __CPROVER_assume(sec_r001058_2_1 != sec_r001058_2_2);
  __CPROVER_assume(sec_r001058_12_1 != sec_r001058_12_2);
  __CPROVER_assume(sec_r001058_17_1 != sec_r001058_17_2);
  __CPROVER_assume(pub_r001058_18_1 == pub_r001058_18_2);
  __CPROVER_assume(sec_r001058_3_1 != sec_r001058_3_2);
  __CPROVER_assume(pub_r001058_0_1 == pub_r001058_0_2);
  __CPROVER_assume(pub_r001058_14_1 == pub_r001058_14_2);
  __CPROVER_assume(sec_r001058_21_1 != sec_r001058_21_2);
  __CPROVER_assume(pub_r001058_4_1 == pub_r001058_4_2);
  __CPROVER_assume(pub_r001058_16_1 == pub_r001058_16_2);
  __CPROVER_assume(sec_r001058_5_1 != sec_r001058_5_2);
  __CPROVER_assume(sec_r001058_7_1 != sec_r001058_7_2);
  __CPROVER_assume(pub_r001058_10_1 == pub_r001058_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.counter == st_var_1_2.counter);
  assert(st_var_1_1.tag == st_var_1_2.tag);
  assert(st_var_1_1.nonce == st_var_1_2.nonce);
  assert(st_var_1_1.round_key == st_var_1_2.round_key);
  assert(st_var_1_1.iv == st_var_1_2.iv);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
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
}


