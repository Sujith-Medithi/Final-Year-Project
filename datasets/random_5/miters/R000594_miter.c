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
struct MatrixBlock_R000594_9413_0
{
  int stride;
  unsigned char determinant;
  int dim;
  unsigned char density;
  int buffer[3];
};
struct Vector3D_R000594_9413_1
{
  unsigned char coord_z;
  unsigned char coord_y;
  int heading;
  int pitch;
  unsigned char coord_x;
  int buffer[3];
};
union PacketPayload_R000594_9413_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000594_9413_1
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
void fn_R000594_9413_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_84_1 = local_arr_1[aux_1 % 3];
  int damping_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_84_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_84_1 == damping_84_2);
}

int fn_R000594_9413_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int local_arr[3] = {4, 9, 15};
  int damping_84 = local_arr[aux % 3];
  acc = (acc + (damping_84 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_36_1 = local_arr_1[aux_1 % 3];
  int margin_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_36_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_36_1 == margin_36_2);
}

int fn_R000594_9413_1(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_36 = local_arr[aux % 3];
  acc = (acc + (margin_36 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int residue_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_86_1) & 63;
  aux_2 = (aux_2 + residue_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_84_1 > 12)
  {
    acc_1 = ((acc_1 + (stride_84_1 * 2)) + 5) & 127;
    aux_1 ^= stride_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_84_2 > 12)
  {
    acc_2 = ((acc_2 + (stride_84_2 * 2)) + 5) & 127;
    aux_2 ^= stride_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_86_1 == residue_86_2);
  assert(stride_84_1 == stride_84_2);
}

int fn_R000594_9413_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int residue_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_86) & 63;
  acc ^= aux;
  int stride_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_84 > 12)
  {
    acc = ((acc + (stride_84 * 2)) + 5) & 127;
    aux ^= stride_84 & 15;
  }
  else
  {
    acc = ((acc - stride_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000594_9413_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int phase_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_63_1) & 63;
  aux_2 = (aux_2 + phase_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_19_1 = local_arr_1[aux_1 % 3];
  int factor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_19_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_63_1 == phase_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_19_1 == factor_19_2);
}

int fn_R000594_9413_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int phase_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_63) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int factor_19 = local_arr[aux % 3];
  acc = (acc + (factor_19 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
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
  int phase_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_69_1) & 63;
  aux_2 = (aux_2 + phase_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_60_1)
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

  switch (delta_60_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_69_1 == phase_69_2);
  assert(delta_60_1 == delta_60_2);
}

int fn_R000594_9413_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_69) & 63;
  acc ^= aux;
  int delta_60 = (aux + st.buffer[1]) & 3;
  switch (delta_60)
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

void fn_R000594_9413_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_57_1) & 63;
  aux_2 = (aux_2 + factor_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_44_1)
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

  switch (damping_44_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_57_1 == factor_57_2);
  assert(damping_44_1 == damping_44_2);
}

int fn_R000594_9413_5(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_57) & 63;
  acc ^= aux;
  int damping_44 = (aux + st.buffer[1]) & 3;
  switch (damping_44)
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

void fn_R000594_9413_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_91_1 = local_arr_1[aux_1 % 3];
  int coefficient_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_91_2 * 2)) & 127;
  int quantum_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_48_1 > 14)
  {
    acc_1 = ((acc_1 + (quantum_48_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_48_2 > 14)
  {
    acc_2 = ((acc_2 + (quantum_48_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_48_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_59_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_59_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_59_1) & 63;
  aux_2 = (aux_2 + pivot_59_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_91_1 == coefficient_91_2);
  assert(quantum_48_1 == quantum_48_2);
  assert(pivot_59_1 == pivot_59_2);
}

int fn_R000594_9413_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int local_arr[3] = {4, 9, 15};
  int coefficient_91 = local_arr[aux % 3];
  acc = (acc + (coefficient_91 * 2)) & 127;
  int quantum_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_48 > 14)
  {
    acc = ((acc + (quantum_48 * 2)) + 5) & 127;
    aux ^= quantum_48 & 15;
  }
  else
  {
    acc = ((acc - quantum_48) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_59 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_59) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000594_9413_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int residue_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_97_1)
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

  switch (residue_97_2)
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
  int residue_78_1 = local_arr_1[aux_1 % 3];
  int residue_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_78_2 * 2)) & 127;
  int sample_13_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_13_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_13_1 > 39)
  {
    acc_1 = ((acc_1 + (sample_13_1 * 2)) + 5) & 127;
    aux_1 ^= sample_13_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_13_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_13_2 > 39)
  {
    acc_2 = ((acc_2 + (sample_13_2 * 2)) + 5) & 127;
    aux_2 ^= sample_13_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_13_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_54_1) & 63;
  aux_2 = (aux_2 + pivot_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_97_1 == residue_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_78_1 == residue_78_2);
  assert(sample_13_1 == sample_13_2);
  assert(pivot_54_1 == pivot_54_2);
}

int fn_R000594_9413_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int residue_97 = (aux + st.buffer[1]) & 3;
  switch (residue_97)
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
  int residue_78 = local_arr[aux % 3];
  acc = (acc + (residue_78 * 2)) & 127;
  int sample_13 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_13 > 39)
  {
    acc = ((acc + (sample_13 * 2)) + 5) & 127;
    aux ^= sample_13 & 15;
  }
  else
  {
    acc = ((acc - sample_13) + 11) & 127;
    aux += 3;
  }
  int pivot_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_54) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000594_9413_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int bound_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_43_1)
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

  switch (bound_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_69_1 = local_arr_1[aux_1 % 3];
  int quantum_69_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_69_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_69_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_43_1 == bound_43_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_69_1 == quantum_69_2);
}

int fn_R000594_9413_8(int p0, int p1, int p2)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int bound_43 = (aux + st.buffer[1]) & 3;
  switch (bound_43)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quantum_69 = local_arr[aux % 3];
  acc = (acc + (quantum_69 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int cursor_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_17_1)
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

  switch (cursor_17_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_17_1 == cursor_17_2);
}

int fn_R000594_9413_9(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int cursor_17 = (aux + st.buffer[1]) & 3;
  switch (cursor_17)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int window_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_10_1 > 40)
  {
    acc_1 = ((acc_1 + (window_10_1 * 2)) + 5) & 127;
    aux_1 ^= window_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_10_2 > 40)
  {
    acc_2 = ((acc_2 + (window_10_2 * 2)) + 5) & 127;
    aux_2 ^= window_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_10_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_39_1) & 63;
  aux_2 = (aux_2 + tracker_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_10_1 == window_10_2);
  assert(tracker_39_1 == tracker_39_2);
}

int fn_R000594_9413_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int window_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_10 > 40)
  {
    acc = ((acc + (window_10 * 2)) + 5) & 127;
    aux ^= window_10 & 15;
  }
  else
  {
    acc = ((acc - window_10) + 11) & 127;
    aux += 3;
  }
  int tracker_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_39) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000594_9413_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_63_1 > 26)
  {
    acc_1 = ((acc_1 + (damping_63_1 * 2)) + 5) & 127;
    aux_1 ^= damping_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_63_2 > 26)
  {
    acc_2 = ((acc_2 + (damping_63_2 * 2)) + 5) & 127;
    aux_2 ^= damping_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_63_1 == damping_63_2);
}

int fn_R000594_9413_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_63 > 26)
  {
    acc = ((acc + (damping_63 * 2)) + 5) & 127;
    aux ^= damping_63 & 15;
  }
  else
  {
    acc = ((acc - damping_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000594_9413_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int accumulator_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_77_1) & 63;
  aux_2 = (aux_2 + accumulator_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_54_1)
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

  switch (sample_54_2)
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
  int metric_84_1 = local_arr_1[aux_1 % 3];
  int metric_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_84_2 * 2)) & 127;
  int metric_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_69_1 > 30)
  {
    acc_1 = ((acc_1 + (metric_69_1 * 2)) + 5) & 127;
    aux_1 ^= metric_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_69_2 > 30)
  {
    acc_2 = ((acc_2 + (metric_69_2 * 2)) + 5) & 127;
    aux_2 ^= metric_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_77_1 == accumulator_77_2);
  assert(sample_54_1 == sample_54_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_84_1 == metric_84_2);
  assert(metric_69_1 == metric_69_2);
}

int fn_R000594_9413_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int accumulator_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_77) & 63;
  acc ^= aux;
  int sample_54 = (aux + st.buffer[1]) & 3;
  switch (sample_54)
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
  int metric_84 = local_arr[aux % 3];
  acc = (acc + (metric_84 * 2)) & 127;
  int metric_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_69 > 30)
  {
    acc = ((acc + (metric_69 * 2)) + 5) & 127;
    aux ^= metric_69 & 15;
  }
  else
  {
    acc = ((acc - metric_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000594_9413_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int residue_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_72_1 > 38)
  {
    acc_1 = ((acc_1 + (residue_72_1 * 2)) + 5) & 127;
    aux_1 ^= residue_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_72_2 > 38)
  {
    acc_2 = ((acc_2 + (residue_72_2 * 2)) + 5) & 127;
    aux_2 ^= residue_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_72_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_36_1 = local_arr_1[aux_1 % 3];
  int accumulator_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_36_2 * 2)) & 127;
  int tracker_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_97_1)
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

  switch (tracker_97_2)
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
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_72_1 == residue_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_36_1 == accumulator_36_2);
  assert(tracker_97_1 == tracker_97_2);
}

int fn_R000594_9413_13(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int residue_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_72 > 38)
  {
    acc = ((acc + (residue_72 * 2)) + 5) & 127;
    aux ^= residue_72 & 15;
  }
  else
  {
    acc = ((acc - residue_72) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int accumulator_36 = local_arr[aux % 3];
  acc = (acc + (accumulator_36 * 2)) & 127;
  int tracker_97 = (aux + st.buffer[1]) & 3;
  switch (tracker_97)
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

void fn_R000594_9413_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_95_1 > 44)
  {
    acc_1 = ((acc_1 + (quotient_95_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_95_2 > 44)
  {
    acc_2 = ((acc_2 + (quotient_95_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_26_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_26_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_26_1) & 63;
  aux_2 = (aux_2 + cursor_26_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_56_1 = local_arr_1[aux_1 % 3];
  int offset_56_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_56_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_56_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_95_1 == quotient_95_2);
  assert(cursor_26_1 == cursor_26_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_56_1 == offset_56_2);
}

int fn_R000594_9413_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_95 > 44)
  {
    acc = ((acc + (quotient_95 * 2)) + 5) & 127;
    aux ^= quotient_95 & 15;
  }
  else
  {
    acc = ((acc - quotient_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_26 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_26) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_56 = local_arr[aux % 3];
  acc = (acc + (offset_56 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_84_1) & 63;
  aux_2 = (aux_2 + vector_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_63_1)
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

  switch (factor_63_2)
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

  int metric_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_58_1 > 39)
  {
    acc_1 = ((acc_1 + (metric_58_1 * 2)) + 5) & 127;
    aux_1 ^= metric_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_58_2 > 39)
  {
    acc_2 = ((acc_2 + (metric_58_2 * 2)) + 5) & 127;
    aux_2 ^= metric_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_58_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_84_1 == vector_84_2);
  assert(factor_63_1 == factor_63_2);
  assert(metric_58_1 == metric_58_2);
}

int fn_R000594_9413_15(int p0, int p1, int p2)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_84) & 63;
  acc ^= aux;
  int factor_63 = (aux + st.buffer[1]) & 3;
  switch (factor_63)
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

  int metric_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_58 > 39)
  {
    acc = ((acc + (metric_58 * 2)) + 5) & 127;
    aux ^= metric_58 & 15;
  }
  else
  {
    acc = ((acc - metric_58) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000594_9413_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int bound_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_28_1) & 63;
  aux_2 = (aux_2 + bound_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_86_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_86_1 * 2)) + 5) & 127;
    aux_1 ^= bound_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_86_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_86_2 * 2)) + 5) & 127;
    aux_2 ^= bound_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_50_1)
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

  switch (phase_50_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_28_1 == bound_28_2);
  assert(bound_86_1 == bound_86_2);
  assert(phase_50_1 == phase_50_2);
}

int fn_R000594_9413_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int bound_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_28) & 63;
  acc ^= aux;
  int bound_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_86 > 10)
  {
    acc = ((acc + (bound_86 * 2)) + 5) & 127;
    aux ^= bound_86 & 15;
  }
  else
  {
    acc = ((acc - bound_86) + 11) & 127;
    aux += 3;
  }
  int phase_50 = (aux + st.buffer[1]) & 3;
  switch (phase_50)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_97_1 = local_arr_1[aux_1 % 3];
  int checksum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_97_2 * 2)) & 127;
  int stride_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_69_1 > 40)
  {
    acc_1 = ((acc_1 + (stride_69_1 * 2)) + 5) & 127;
    aux_1 ^= stride_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_69_2 > 40)
  {
    acc_2 = ((acc_2 + (stride_69_2 * 2)) + 5) & 127;
    aux_2 ^= stride_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_16_1) & 63;
  aux_2 = (aux_2 + pivot_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_97_1 == checksum_97_2);
  assert(stride_69_1 == stride_69_2);
  assert(pivot_16_1 == pivot_16_2);
}

int fn_R000594_9413_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_97 = local_arr[aux % 3];
  acc = (acc + (checksum_97 * 2)) & 127;
  int stride_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_69 > 40)
  {
    acc = ((acc + (stride_69 * 2)) + 5) & 127;
    aux ^= stride_69 & 15;
  }
  else
  {
    acc = ((acc - stride_69) + 11) & 127;
    aux += 3;
  }
  int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000594_9413_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int bound_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_68_1)
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

  switch (bound_68_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_35_1) & 63;
  aux_2 = (aux_2 + mask_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_66_1 = local_arr_1[aux_1 % 3];
  int phase_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_68_1 == bound_68_2);
  assert(mask_35_1 == mask_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_66_1 == phase_66_2);
}

int fn_R000594_9413_18(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int bound_68 = (aux + st.buffer[1]) & 3;
  switch (bound_68)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_66 = local_arr[aux % 3];
  acc = (acc + (phase_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000594_9413_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st_1 = {0};
  struct Vector3D_R000594_9413_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int parity_37_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_37_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_37_1)
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

  switch (parity_37_2)
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

  int cursor_16_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_16_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_16_1) & 63;
  aux_2 = (aux_2 + cursor_16_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_37_1 == parity_37_2);
  assert(cursor_16_1 == cursor_16_2);
}

int fn_R000594_9413_19(int p0, int p1)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000594_9413_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int parity_37 = (aux + st.buffer[1]) & 3;
  switch (parity_37)
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

  int cursor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_16) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000594_9413_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int parity_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_78_1 > 11)
  {
    acc_1 = ((acc_1 + (parity_78_1 * 2)) + 5) & 127;
    aux_1 ^= parity_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_78_2 > 11)
  {
    acc_2 = ((acc_2 + (parity_78_2 * 2)) + 5) & 127;
    aux_2 ^= parity_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_78_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_49_1 = local_arr_1[aux_1 % 3];
  int checksum_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_49_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.stride == st_2.stride);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.dim == st_2.dim);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_78_1 == parity_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_49_1 == checksum_49_2);
}

int fn_R000594_9413_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000594_9413_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int parity_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_78 > 11)
  {
    acc = ((acc + (parity_78 * 2)) + 5) & 127;
    aux ^= parity_78 & 15;
  }
  else
  {
    acc = ((acc - parity_78) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int checksum_49 = local_arr[aux % 3];
  acc = (acc + (checksum_49 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000594_0_1;
  int sec_r000594_0_2;
  int sec_r000594_1_1;
  int sec_r000594_1_2;
  int sec_r000594_2_1;
  int sec_r000594_2_2;
  int sec_r000594_3_1;
  int sec_r000594_3_2;
  int sec_r000594_4_1;
  int sec_r000594_4_2;
  int sec_r000594_5_1;
  int sec_r000594_5_2;
  int sec_r000594_6_1;
  int sec_r000594_6_2;
  int sec_r000594_7_1;
  int sec_r000594_7_2;
  int sec_r000594_8_1;
  int sec_r000594_8_2;
  int sec_r000594_9_1;
  int sec_r000594_9_2;
  int sec_r000594_10_1;
  int sec_r000594_10_2;
  int sec_r000594_11_1;
  int sec_r000594_11_2;
  int sec_r000594_12_1;
  int sec_r000594_12_2;
  int sec_r000594_13_1;
  int sec_r000594_13_2;
  int sec_r000594_14_1;
  int sec_r000594_14_2;
  int sec_r000594_15_1;
  int sec_r000594_15_2;
  int sec_r000594_16_1;
  int sec_r000594_16_2;
  int sec_r000594_17_1;
  int sec_r000594_17_2;
  int pub_r000594_0_1;
  int pub_r000594_0_2;
  int pub_r000594_1_1;
  int pub_r000594_1_2;
  int pub_r000594_2_1;
  int pub_r000594_2_2;
  int pub_r000594_3_1;
  int pub_r000594_3_2;
  int pub_r000594_4_1;
  int pub_r000594_4_2;
  int pub_r000594_5_1;
  int pub_r000594_5_2;
  int pub_r000594_6_1;
  int pub_r000594_6_2;
  int pub_r000594_7_1;
  int pub_r000594_7_2;
  int pub_r000594_8_1;
  int pub_r000594_8_2;
  int pub_r000594_9_1;
  int pub_r000594_9_2;
  int pub_r000594_10_1;
  int pub_r000594_10_2;
  int pub_r000594_11_1;
  int pub_r000594_11_2;
  int pub_r000594_12_1;
  int pub_r000594_12_2;
  int pub_r000594_13_1;
  int pub_r000594_13_2;
  int pub_r000594_14_1;
  int pub_r000594_14_2;
  int pub_r000594_15_1;
  int pub_r000594_15_2;
  int pub_r000594_16_1;
  int pub_r000594_16_2;
  int pub_r000594_17_1;
  int pub_r000594_17_2;
  int pub_r000594_18_1;
  int pub_r000594_18_2;
  int pub_r000594_19_1;
  int pub_r000594_19_2;
  int pub_r000594_20_1;
  int pub_r000594_20_2;
  int pub_r000594_21_1;
  int pub_r000594_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000594_0_1 >= (-100)) && (pub_r000594_0_1 <= 100));
  __CPROVER_assume((pub_r000594_0_2 >= (-100)) && (pub_r000594_0_2 <= 100));
  __CPROVER_assume((pub_r000594_1_1 >= (-100)) && (pub_r000594_1_1 <= 100));
  __CPROVER_assume((pub_r000594_1_2 >= (-100)) && (pub_r000594_1_2 <= 100));
  __CPROVER_assume((pub_r000594_2_1 >= (-100)) && (pub_r000594_2_1 <= 100));
  __CPROVER_assume((pub_r000594_2_2 >= (-100)) && (pub_r000594_2_2 <= 100));
  __CPROVER_assume((pub_r000594_3_1 >= (-100)) && (pub_r000594_3_1 <= 100));
  __CPROVER_assume((pub_r000594_3_2 >= (-100)) && (pub_r000594_3_2 <= 100));
  __CPROVER_assume((pub_r000594_4_1 >= (-100)) && (pub_r000594_4_1 <= 100));
  __CPROVER_assume((pub_r000594_4_2 >= (-100)) && (pub_r000594_4_2 <= 100));
  __CPROVER_assume((pub_r000594_5_1 >= (-100)) && (pub_r000594_5_1 <= 100));
  __CPROVER_assume((pub_r000594_5_2 >= (-100)) && (pub_r000594_5_2 <= 100));
  __CPROVER_assume((pub_r000594_6_1 >= (-100)) && (pub_r000594_6_1 <= 100));
  __CPROVER_assume((pub_r000594_6_2 >= (-100)) && (pub_r000594_6_2 <= 100));
  __CPROVER_assume((pub_r000594_7_1 >= (-100)) && (pub_r000594_7_1 <= 100));
  __CPROVER_assume((pub_r000594_7_2 >= (-100)) && (pub_r000594_7_2 <= 100));
  __CPROVER_assume((pub_r000594_8_1 >= (-100)) && (pub_r000594_8_1 <= 100));
  __CPROVER_assume((pub_r000594_8_2 >= (-100)) && (pub_r000594_8_2 <= 100));
  __CPROVER_assume((pub_r000594_9_1 >= (-100)) && (pub_r000594_9_1 <= 100));
  __CPROVER_assume((pub_r000594_9_2 >= (-100)) && (pub_r000594_9_2 <= 100));
  __CPROVER_assume((pub_r000594_10_1 >= (-100)) && (pub_r000594_10_1 <= 100));
  __CPROVER_assume((pub_r000594_10_2 >= (-100)) && (pub_r000594_10_2 <= 100));
  __CPROVER_assume((pub_r000594_11_1 >= (-100)) && (pub_r000594_11_1 <= 100));
  __CPROVER_assume((pub_r000594_11_2 >= (-100)) && (pub_r000594_11_2 <= 100));
  __CPROVER_assume((pub_r000594_12_1 >= (-100)) && (pub_r000594_12_1 <= 100));
  __CPROVER_assume((pub_r000594_12_2 >= (-100)) && (pub_r000594_12_2 <= 100));
  __CPROVER_assume((pub_r000594_13_1 >= (-100)) && (pub_r000594_13_1 <= 100));
  __CPROVER_assume((pub_r000594_13_2 >= (-100)) && (pub_r000594_13_2 <= 100));
  __CPROVER_assume((pub_r000594_14_1 >= (-100)) && (pub_r000594_14_1 <= 100));
  __CPROVER_assume((pub_r000594_14_2 >= (-100)) && (pub_r000594_14_2 <= 100));
  __CPROVER_assume((pub_r000594_15_1 >= (-100)) && (pub_r000594_15_1 <= 100));
  __CPROVER_assume((pub_r000594_15_2 >= (-100)) && (pub_r000594_15_2 <= 100));
  __CPROVER_assume((pub_r000594_16_1 >= (-100)) && (pub_r000594_16_1 <= 100));
  __CPROVER_assume((pub_r000594_16_2 >= (-100)) && (pub_r000594_16_2 <= 100));
  __CPROVER_assume((pub_r000594_17_1 >= (-100)) && (pub_r000594_17_1 <= 100));
  __CPROVER_assume((pub_r000594_17_2 >= (-100)) && (pub_r000594_17_2 <= 100));
  __CPROVER_assume((pub_r000594_18_1 >= (-100)) && (pub_r000594_18_1 <= 100));
  __CPROVER_assume((pub_r000594_18_2 >= (-100)) && (pub_r000594_18_2 <= 100));
  __CPROVER_assume((pub_r000594_19_1 >= (-100)) && (pub_r000594_19_1 <= 100));
  __CPROVER_assume((pub_r000594_19_2 >= (-100)) && (pub_r000594_19_2 <= 100));
  __CPROVER_assume((pub_r000594_20_1 >= (-100)) && (pub_r000594_20_1 <= 100));
  __CPROVER_assume((pub_r000594_20_2 >= (-100)) && (pub_r000594_20_2 <= 100));
  __CPROVER_assume((pub_r000594_21_1 >= (-100)) && (pub_r000594_21_1 <= 100));
  __CPROVER_assume((pub_r000594_21_2 >= (-100)) && (pub_r000594_21_2 <= 100));
  __CPROVER_assume((sec_r000594_0_1 >= 0) && (sec_r000594_0_1 <= 255));
  __CPROVER_assume((sec_r000594_0_2 >= 0) && (sec_r000594_0_2 <= 255));
  __CPROVER_assume((sec_r000594_1_1 >= 0) && (sec_r000594_1_1 <= 255));
  __CPROVER_assume((sec_r000594_1_2 >= 0) && (sec_r000594_1_2 <= 255));
  __CPROVER_assume((sec_r000594_2_1 >= 0) && (sec_r000594_2_1 <= 255));
  __CPROVER_assume((sec_r000594_2_2 >= 0) && (sec_r000594_2_2 <= 255));
  __CPROVER_assume((sec_r000594_3_1 >= 0) && (sec_r000594_3_1 <= 255));
  __CPROVER_assume((sec_r000594_3_2 >= 0) && (sec_r000594_3_2 <= 255));
  __CPROVER_assume((sec_r000594_4_1 >= 0) && (sec_r000594_4_1 <= 255));
  __CPROVER_assume((sec_r000594_4_2 >= 0) && (sec_r000594_4_2 <= 255));
  __CPROVER_assume((sec_r000594_5_1 >= 0) && (sec_r000594_5_1 <= 255));
  __CPROVER_assume((sec_r000594_5_2 >= 0) && (sec_r000594_5_2 <= 255));
  __CPROVER_assume((sec_r000594_6_1 >= 0) && (sec_r000594_6_1 <= 255));
  __CPROVER_assume((sec_r000594_6_2 >= 0) && (sec_r000594_6_2 <= 255));
  __CPROVER_assume((sec_r000594_7_1 >= 0) && (sec_r000594_7_1 <= 255));
  __CPROVER_assume((sec_r000594_7_2 >= 0) && (sec_r000594_7_2 <= 255));
  __CPROVER_assume((sec_r000594_8_1 >= 0) && (sec_r000594_8_1 <= 255));
  __CPROVER_assume((sec_r000594_8_2 >= 0) && (sec_r000594_8_2 <= 255));
  __CPROVER_assume((sec_r000594_9_1 >= 0) && (sec_r000594_9_1 <= 255));
  __CPROVER_assume((sec_r000594_9_2 >= 0) && (sec_r000594_9_2 <= 255));
  __CPROVER_assume((sec_r000594_10_1 >= 0) && (sec_r000594_10_1 <= 255));
  __CPROVER_assume((sec_r000594_10_2 >= 0) && (sec_r000594_10_2 <= 255));
  __CPROVER_assume((sec_r000594_11_1 >= 0) && (sec_r000594_11_1 <= 255));
  __CPROVER_assume((sec_r000594_11_2 >= 0) && (sec_r000594_11_2 <= 255));
  __CPROVER_assume((sec_r000594_12_1 >= 0) && (sec_r000594_12_1 <= 255));
  __CPROVER_assume((sec_r000594_12_2 >= 0) && (sec_r000594_12_2 <= 255));
  __CPROVER_assume((sec_r000594_13_1 >= 0) && (sec_r000594_13_1 <= 255));
  __CPROVER_assume((sec_r000594_13_2 >= 0) && (sec_r000594_13_2 <= 255));
  __CPROVER_assume((sec_r000594_14_1 >= 0) && (sec_r000594_14_1 <= 255));
  __CPROVER_assume((sec_r000594_14_2 >= 0) && (sec_r000594_14_2 <= 255));
  __CPROVER_assume((sec_r000594_15_1 >= 0) && (sec_r000594_15_1 <= 255));
  __CPROVER_assume((sec_r000594_15_2 >= 0) && (sec_r000594_15_2 <= 255));
  __CPROVER_assume((sec_r000594_16_1 >= 0) && (sec_r000594_16_1 <= 255));
  __CPROVER_assume((sec_r000594_16_2 >= 0) && (sec_r000594_16_2 <= 255));
  __CPROVER_assume((sec_r000594_17_1 >= 0) && (sec_r000594_17_1 <= 255));
  __CPROVER_assume((sec_r000594_17_2 >= 0) && (sec_r000594_17_2 <= 255));
  struct MatrixBlock_R000594_9413_0 st_var_0_1 = {0};
  struct MatrixBlock_R000594_9413_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000594_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000594_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000594_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000594_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000594_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000594_0_2 + 7) & 15;
  struct Vector3D_R000594_9413_1 st_var_1_1 = {0};
  struct Vector3D_R000594_9413_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000594_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000594_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000594_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000594_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000594_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000594_0_2 + 9) & 15;
  union PacketPayload_R000594_9413_0 u_var_1;
  union PacketPayload_R000594_9413_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 34)
    {
      chk_sum_1 ^= stage_v_0_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_0_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 34)
    {
      chk_sum_2 ^= stage_v_0_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 3) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 3) & 15;
  int stage_v_2_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_2_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  chk_sum_1 ^= stage_v_2_1;
  chk_sum_2 ^= stage_v_2_2;
  int stage_v_3_1 = 0;
  int stage_v_3_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_3_1 = ((stage_v_3_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_3_2 = ((stage_v_3_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
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
  if (stage_v_6_1 > 11)
  {
    out_sink_1 = ((out_sink_1 + stage_v_6_1) - 5) & 255;
    if (stage_v_6_1 > 26)
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
  if (stage_v_6_2 > 11)
  {
    out_sink_2 = ((out_sink_2 + stage_v_6_2) - 5) & 255;
    if (stage_v_6_2 > 26)
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
  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 35)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 35)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_11_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_11_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_11_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_12_1 = 0;
  int stage_v_12_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_12_1 = ((stage_v_12_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_12_2 = ((stage_v_12_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  int stage_v_13_1 = 0;
  int stage_v_13_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_13_1 = ((stage_v_13_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_13_2 = ((stage_v_13_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = table_1[1];
  int stage_v_17_2 = table_2[1];
  table_1[1] = (table_1[2] + 35) & 63;
  table_2[1] = (table_2[2] + 35) & 63;
  out_sink_1 = (out_sink_1 + stage_v_17_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_17_2) & 255;
  int stage_v_18_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (23 & 31);
  int stage_v_18_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (23 & 31);
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= (stage_v_18_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_18_2 << 1) & 127;
  int stage_v_19_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (24 & 31);
  int stage_v_19_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (24 & 31);
  out_sink_1 = (out_sink_1 + stage_v_19_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_19_2) & 255;
  chk_sum_1 ^= (stage_v_19_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_19_2 << 1) & 127;
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 22) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 22) & 15;
  int stage_v_21_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_21_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= stage_v_21_1;
  chk_sum_2 ^= stage_v_21_2;
  int stage_v_22_1 = ((st_var_0_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_0_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 47)
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
  if (stage_v_22_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 47)
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
  int stage_v_23_1 = 0;
  int stage_v_23_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_23_1 = ((stage_v_23_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_23_2 = ((stage_v_23_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 25) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 25) & 15;
  int stage_v_24_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_24_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  chk_sum_1 ^= stage_v_24_1;
  chk_sum_2 ^= stage_v_24_2;
  int stage_v_25_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (30 & 31);
  int stage_v_25_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (30 & 31);
  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  chk_sum_1 ^= (stage_v_25_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_25_2 << 1) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_27_1 = ((stage_v_27_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_27_2 = ((stage_v_27_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
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
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  int stage_v_31_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_31_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_32_1 = table_1[0];
  int stage_v_32_2 = table_2[0];
  table_1[0] = (table_1[1] + 65) & 63;
  table_2[0] = (table_2[1] + 65) & 63;
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = table_1[1];
  int stage_v_33_2 = table_2[1];
  table_1[1] = (table_1[2] + 67) & 63;
  table_2[1] = (table_2[2] + 67) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = (st_var_0_1.buffer[0] ^ 37) & 3;
  int stage_v_34_2 = (st_var_0_2.buffer[0] ^ 37) & 3;
  switch (stage_v_34_1)
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

  switch (stage_v_34_2)
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

  int stage_v_35_1 = table_1[3];
  int stage_v_35_2 = table_2[3];
  table_1[3] = (table_1[0] + 71) & 63;
  table_2[3] = (table_2[0] + 71) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_36_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_37_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (42 & 31);
  int stage_v_37_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (42 & 31);
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  chk_sum_1 ^= (stage_v_37_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_37_2 << 1) & 127;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = (st_var_1_1.buffer[0] ^ 42) & 3;
  int stage_v_39_2 = (st_var_1_2.buffer[0] ^ 42) & 3;
  switch (stage_v_39_1)
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

  switch (stage_v_39_2)
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

  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 41) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 41) & 15;
  int stage_v_40_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_40_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  chk_sum_1 ^= stage_v_40_1;
  chk_sum_2 ^= stage_v_40_2;
  int stage_v_41_1 = (st_var_1_1.buffer[0] ^ 44) & 3;
  int stage_v_41_2 = (st_var_1_2.buffer[0] ^ 44) & 3;
  switch (stage_v_41_1)
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

  switch (stage_v_41_2)
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

  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 43) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 43) & 15;
  int stage_v_42_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_42_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  chk_sum_1 ^= stage_v_42_1;
  chk_sum_2 ^= stage_v_42_2;
  int stage_v_43_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (48 & 31);
  int stage_v_43_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (48 & 31);
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  chk_sum_1 ^= (stage_v_43_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_43_2 << 1) & 127;
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
  int stage_v_45_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_45_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_46_1 = ((st_var_0_1.buffer[1] * 2) + 145) & 63;
  int stage_v_46_2 = ((st_var_0_2.buffer[1] * 2) + 145) & 63;
  if (stage_v_46_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + stage_v_46_1) - 5) & 255;
    if (stage_v_46_1 > 47)
    {
      chk_sum_1 ^= stage_v_46_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_46_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + stage_v_46_2) - 5) & 255;
    if (stage_v_46_2 > 47)
    {
      chk_sum_2 ^= stage_v_46_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_47_1 = ((stage_v_47_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_47_2 = ((stage_v_47_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
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

  switch (stage_v_49_2)
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

  int stage_v_50_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_50_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_51_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (56 & 31);
  int stage_v_51_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (56 & 31);
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  chk_sum_1 ^= (stage_v_51_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_51_2 << 1) & 127;
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
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_53_1 = ((stage_v_53_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_53_2 = ((stage_v_53_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
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
  int stage_v_55_1 = (st_var_1_1.buffer[0] ^ 58) & 3;
  int stage_v_55_2 = (st_var_1_2.buffer[0] ^ 58) & 3;
  switch (stage_v_55_1)
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

  switch (stage_v_55_2)
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

  int stage_v_56_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (61 & 31);
  int stage_v_56_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (61 & 31);
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  chk_sum_1 ^= (stage_v_56_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_56_2 << 1) & 127;
  int stage_v_57_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (62 & 31);
  int stage_v_57_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (62 & 31);
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  chk_sum_1 ^= (stage_v_57_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_57_2 << 1) & 127;
  int stage_v_58_1 = (st_var_0_1.buffer[0] ^ 61) & 3;
  int stage_v_58_2 = (st_var_0_2.buffer[0] ^ 61) & 3;
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

  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = table_1[1];
  int stage_v_61_2 = table_2[1];
  table_1[1] = (table_1[2] + 123) & 63;
  table_2[1] = (table_2[2] + 123) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = ((st_var_0_1.buffer[2] * 2) + 193) & 63;
  int stage_v_62_2 = ((st_var_0_2.buffer[2] * 2) + 193) & 63;
  if (stage_v_62_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_62_1) - 5) & 255;
    if (stage_v_62_1 > 50)
    {
      chk_sum_1 ^= stage_v_62_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_62_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_62_2) - 5) & 255;
    if (stage_v_62_2 > 50)
    {
      chk_sum_2 ^= stage_v_62_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_63_1 = (st_var_1_1.buffer[0] ^ 66) & 3;
  int stage_v_63_2 = (st_var_1_2.buffer[0] ^ 66) & 3;
  switch (stage_v_63_1)
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

  switch (stage_v_63_2)
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

  int stage_v_64_1 = ((st_var_0_1.buffer[1] * 2) + 199) & 63;
  int stage_v_64_2 = ((st_var_0_2.buffer[1] * 2) + 199) & 63;
  if (stage_v_64_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_64_1) - 5) & 255;
    if (stage_v_64_1 > 42)
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
  if (stage_v_64_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_64_2) - 5) & 255;
    if (stage_v_64_2 > 42)
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
  int stage_v_65_1 = table_1[1];
  int stage_v_65_2 = table_2[1];
  table_1[1] = (table_1[2] + 131) & 63;
  table_2[1] = (table_2[2] + 131) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = (st_var_0_1.buffer[0] ^ 69) & 3;
  int stage_v_66_2 = (st_var_0_2.buffer[0] ^ 69) & 3;
  switch (stage_v_66_1)
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

  switch (stage_v_66_2)
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

  int stage_v_67_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_67_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_68_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_68_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_69_1 = ((st_var_1_1.buffer[0] * 2) + 214) & 63;
  int stage_v_69_2 = ((st_var_1_2.buffer[0] * 2) + 214) & 63;
  if (stage_v_69_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_69_1) - 5) & 255;
    if (stage_v_69_1 > 51)
    {
      chk_sum_1 ^= stage_v_69_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_69_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_69_2) - 5) & 255;
    if (stage_v_69_2 > 51)
    {
      chk_sum_2 ^= stage_v_69_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_70_1 = ((st_var_0_1.buffer[1] * 2) + 217) & 63;
  int stage_v_70_2 = ((st_var_0_2.buffer[1] * 2) + 217) & 63;
  if (stage_v_70_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + stage_v_70_1) - 5) & 255;
    if (stage_v_70_1 > 51)
    {
      chk_sum_1 ^= stage_v_70_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_70_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + stage_v_70_2) - 5) & 255;
    if (stage_v_70_2 > 51)
    {
      chk_sum_2 ^= stage_v_70_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
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
  int stage_v_73_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (78 & 31);
  int stage_v_73_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (78 & 31);
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  chk_sum_1 ^= (stage_v_73_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_73_2 << 1) & 127;
  int stage_v_74_1 = ((st_var_0_1.buffer[2] * 2) + 229) & 63;
  int stage_v_74_2 = ((st_var_0_2.buffer[2] * 2) + 229) & 63;
  if (stage_v_74_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + stage_v_74_1) - 5) & 255;
    if (stage_v_74_1 > 43)
    {
      chk_sum_1 ^= stage_v_74_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_74_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_74_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + stage_v_74_2) - 5) & 255;
    if (stage_v_74_2 > 43)
    {
      chk_sum_2 ^= stage_v_74_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_74_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_75_1 = table_1[3];
  int stage_v_75_2 = table_2[3];
  table_1[3] = (table_1[0] + 151) & 63;
  table_2[3] = (table_2[0] + 151) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = ((st_var_0_1.buffer[1] * 2) + 235) & 63;
  int stage_v_76_2 = ((st_var_0_2.buffer[1] * 2) + 235) & 63;
  if (stage_v_76_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_76_1) - 5) & 255;
    if (stage_v_76_1 > 41)
    {
      chk_sum_1 ^= stage_v_76_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_76_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_76_2) - 5) & 255;
    if (stage_v_76_2 > 41)
    {
      chk_sum_2 ^= stage_v_76_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
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
  int stage_v_78_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_17_1) + 8) & 127;
  int stage_v_78_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_17_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = ((((stage_v_78_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_6_1) + 3) & 127;
  int stage_v_79_2 = ((((stage_v_78_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_79_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_79_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = ((((stage_v_78_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_5_1) + 19) & 127;
  int stage_v_80_2 = ((((stage_v_78_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_5_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_80_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_80_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = ((((sec_r000594_10_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_10_1) + 36) & 127;
  int stage_v_81_2 = ((((sec_r000594_10_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_13_1) + 34) & 127;
  int stage_v_82_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_82_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_82_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = ((((stage_v_80_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_6_1) + 7) & 127;
  int stage_v_83_2 = ((((stage_v_80_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((((stage_v_82_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_18_1) + 18) & 127;
  int stage_v_84_2 = ((((stage_v_82_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_6_1) + 9) & 127;
  int stage_v_85_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((((stage_v_83_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_5_1) + 34) & 127;
  int stage_v_86_2 = ((((stage_v_83_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = ((((stage_v_80_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_11_1) + 27) & 127;
  int stage_v_87_2 = ((((stage_v_80_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = ((((stage_v_80_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_15_1) + 32) & 127;
  int stage_v_88_2 = ((((stage_v_80_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((((stage_v_82_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_2_1) + 28) & 127;
  int stage_v_89_2 = ((((stage_v_82_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_89_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_89_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((((stage_v_87_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_17_1) + 34) & 127;
  int stage_v_90_2 = ((((stage_v_87_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_17_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((((stage_v_80_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_18_1) + 19) & 127;
  int stage_v_91_2 = ((((stage_v_80_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_91_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_91_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((((stage_v_87_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_10_1) + 17) & 127;
  int stage_v_92_2 = ((((stage_v_87_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_92_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_92_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_21_1) + 16) & 127;
  int stage_v_93_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_21_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((((stage_v_91_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_15_1) + 16) & 127;
  int stage_v_94_2 = ((((stage_v_91_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((((stage_v_88_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_5_1) + 30) & 127;
  int stage_v_95_2 = ((((stage_v_88_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((((sec_r000594_3_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_8_1) + 27) & 127;
  int stage_v_96_2 = ((((sec_r000594_3_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((((stage_v_95_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_7_1) + 30) & 127;
  int stage_v_97_2 = ((((stage_v_95_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((((stage_v_91_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_21_1) + 21) & 127;
  int stage_v_98_2 = ((((stage_v_91_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_21_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((((stage_v_89_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_12_1) + 20) & 127;
  int stage_v_99_2 = ((((stage_v_89_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_99_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_99_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((((stage_v_98_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_3_1) + 31) & 127;
  int stage_v_100_2 = ((((stage_v_98_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((((sec_r000594_5_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_4_1) + 31) & 127;
  int stage_v_101_2 = ((((sec_r000594_5_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((((stage_v_96_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_12_1) + 5) & 127;
  int stage_v_102_2 = ((((stage_v_96_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_12_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_102_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_102_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_4_1) + 21) & 127;
  int stage_v_103_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_103_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_103_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((((stage_v_81_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_20_1) + 24) & 127;
  int stage_v_104_2 = ((((stage_v_81_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_20_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_20_1) + 12) & 127;
  int stage_v_105_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_20_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((((stage_v_90_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_20_1) + 16) & 127;
  int stage_v_106_2 = ((((stage_v_90_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_20_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((((sec_r000594_2_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_1_1) + 9) & 127;
  int stage_v_107_2 = ((((sec_r000594_2_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_1_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((((stage_v_102_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_7_1) + 35) & 127;
  int stage_v_108_2 = ((((stage_v_102_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_7_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_108_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_108_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((((stage_v_78_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_6_1) + 34) & 127;
  int stage_v_109_2 = ((((stage_v_78_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_109_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_109_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_4_1) + 26) & 127;
  int stage_v_110_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_110_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_110_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((((sec_r000594_9_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_13_1) + 22) & 127;
  int stage_v_111_2 = ((((sec_r000594_9_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_2_1) + 6) & 127;
  int stage_v_112_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((((stage_v_84_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_4_1) + 22) & 127;
  int stage_v_113_2 = ((((stage_v_84_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_113_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_113_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((((stage_v_108_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_15_1) + 8) & 127;
  int stage_v_114_2 = ((((stage_v_108_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((((stage_v_112_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_15_1) + 15) & 127;
  int stage_v_115_2 = ((((stage_v_112_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((((sec_r000594_7_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_4_1) + 23) & 127;
  int stage_v_116_2 = ((((sec_r000594_7_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_116_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_116_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((((stage_v_113_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_5_1) + 4) & 127;
  int stage_v_117_2 = ((((stage_v_113_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_117_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_117_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((((stage_v_116_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_11_1) + 4) & 127;
  int stage_v_118_2 = ((((stage_v_116_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_11_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_118_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_118_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((((stage_v_78_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_18_1) + 25) & 127;
  int stage_v_119_2 = ((((stage_v_78_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((((sec_r000594_5_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_4_1) + 21) & 127;
  int stage_v_120_2 = ((((sec_r000594_5_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_14_1) + 14) & 127;
  int stage_v_121_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_121_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_121_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((((stage_v_120_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_21_1) + 6) & 127;
  int stage_v_122_2 = ((((stage_v_120_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_21_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((((stage_v_97_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_3_1) + 5) & 127;
  int stage_v_123_2 = ((((stage_v_97_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((((stage_v_105_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_19_1) + 34) & 127;
  int stage_v_124_2 = ((((stage_v_105_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_14_1) + 34) & 127;
  int stage_v_125_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_17_1) + 24) & 127;
  int stage_v_126_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((((stage_v_88_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_7_1) + 16) & 127;
  int stage_v_127_2 = ((((stage_v_88_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_7_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_127_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_127_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((((stage_v_83_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_5_1) + 14) & 127;
  int stage_v_128_2 = ((((stage_v_83_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((((stage_v_87_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_17_1) + 25) & 127;
  int stage_v_129_2 = ((((stage_v_87_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((((stage_v_81_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_2_1) + 24) & 127;
  int stage_v_130_2 = ((((stage_v_81_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_130_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_130_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((((stage_v_112_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_7_1) + 18) & 127;
  int stage_v_131_2 = ((((stage_v_112_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_7_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_131_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_131_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((((stage_v_116_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_14_1) + 9) & 127;
  int stage_v_132_2 = ((((stage_v_116_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((((stage_v_84_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_10_1) + 25) & 127;
  int stage_v_133_2 = ((((stage_v_84_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((((stage_v_101_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_14_1) + 16) & 127;
  int stage_v_134_2 = ((((stage_v_101_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_134_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_134_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_21_1) + 30) & 127;
  int stage_v_135_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_135_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_135_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((((stage_v_94_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_19_1) + 3) & 127;
  int stage_v_136_2 = ((((stage_v_94_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((((stage_v_101_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_10_1) + 5) & 127;
  int stage_v_137_2 = ((((stage_v_101_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((((stage_v_101_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_11_1) + 12) & 127;
  int stage_v_138_2 = ((((stage_v_101_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((((stage_v_94_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_7_1) + 12) & 127;
  int stage_v_139_2 = ((((stage_v_94_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_7_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((((stage_v_102_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_17_1) + 19) & 127;
  int stage_v_140_2 = ((((stage_v_102_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((((stage_v_134_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_21_1) + 33) & 127;
  int stage_v_141_2 = ((((stage_v_134_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_21_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((((stage_v_134_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_2_1) + 17) & 127;
  int stage_v_142_2 = ((((stage_v_134_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((((stage_v_126_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_9_1) + 12) & 127;
  int stage_v_143_2 = ((((stage_v_126_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((((stage_v_84_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_5_1) + 31) & 127;
  int stage_v_144_2 = ((((stage_v_84_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_12_1) + 30) & 127;
  int stage_v_145_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((((stage_v_130_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_13_1) + 34) & 127;
  int stage_v_146_2 = ((((stage_v_130_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((((stage_v_135_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_9_1) + 31) & 127;
  int stage_v_147_2 = ((((stage_v_135_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_9_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((((sec_r000594_1_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_8_1) + 5) & 127;
  int stage_v_148_2 = ((((sec_r000594_1_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_8_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_148_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_148_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((((stage_v_82_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_9_1) + 35) & 127;
  int stage_v_149_2 = ((((stage_v_82_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_9_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_149_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_149_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((((stage_v_80_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_1_1) + 22) & 127;
  int stage_v_150_2 = ((((stage_v_80_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((((sec_r000594_7_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_6_1) + 20) & 127;
  int stage_v_151_2 = ((((sec_r000594_7_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_21_1) + 29) & 127;
  int stage_v_152_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_21_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((((stage_v_117_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_18_1) + 3) & 127;
  int stage_v_153_2 = ((((stage_v_117_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((((stage_v_82_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_14_1) + 10) & 127;
  int stage_v_154_2 = ((((stage_v_82_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((((sec_r000594_8_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_16_1) + 27) & 127;
  int stage_v_155_2 = ((((sec_r000594_8_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_16_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((((stage_v_137_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_1_1) + 15) & 127;
  int stage_v_156_2 = ((((stage_v_137_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_156_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_156_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_7_1) + 24) & 127;
  int stage_v_157_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_7_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_3_1) + 28) & 127;
  int stage_v_158_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_158_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_158_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((((stage_v_123_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_10_1) + 17) & 127;
  int stage_v_159_2 = ((((stage_v_123_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((((stage_v_147_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_15_1) + 20) & 127;
  int stage_v_160_2 = ((((stage_v_147_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((((stage_v_130_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_16_1) + 24) & 127;
  int stage_v_161_2 = ((((stage_v_130_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((((stage_v_155_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_10_1) + 18) & 127;
  int stage_v_162_2 = ((((stage_v_155_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_10_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((((stage_v_115_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_21_1) + 35) & 127;
  int stage_v_163_2 = ((((stage_v_115_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_21_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_163_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_163_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((((stage_v_115_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_2_1) + 9) & 127;
  int stage_v_164_2 = ((((stage_v_115_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((((stage_v_147_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_8_1) + 9) & 127;
  int stage_v_165_2 = ((((stage_v_147_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((((stage_v_122_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_4_1) + 19) & 127;
  int stage_v_166_2 = ((((stage_v_122_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((((stage_v_92_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_14_1) + 3) & 127;
  int stage_v_167_2 = ((((stage_v_92_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((((sec_r000594_11_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_0_1) + 17) & 127;
  int stage_v_168_2 = ((((sec_r000594_11_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_168_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_168_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((((stage_v_166_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_8_1) + 27) & 127;
  int stage_v_169_2 = ((((stage_v_166_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_7_1) + 27) & 127;
  int stage_v_170_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((((stage_v_143_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_3_1) + 13) & 127;
  int stage_v_171_2 = ((((stage_v_143_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_17_1) + 17) & 127;
  int stage_v_172_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((((stage_v_172_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_16_1) + 10) & 127;
  int stage_v_173_2 = ((((stage_v_172_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((((stage_v_80_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_9_1) + 3) & 127;
  int stage_v_174_2 = ((((stage_v_80_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((((sec_r000594_15_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_9_1) + 6) & 127;
  int stage_v_175_2 = ((((sec_r000594_15_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((((stage_v_131_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_5_1) + 15) & 127;
  int stage_v_176_2 = ((((stage_v_131_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_176_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_176_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_14_1) + 18) & 127;
  int stage_v_177_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_177_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_177_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((((stage_v_78_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_4_1) + 30) & 127;
  int stage_v_178_2 = ((((stage_v_78_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_178_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_178_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((((stage_v_149_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_5_1) + 7) & 127;
  int stage_v_179_2 = ((((stage_v_149_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_179_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_179_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((((stage_v_103_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_12_1) + 14) & 127;
  int stage_v_180_2 = ((((stage_v_103_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_180_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_180_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_5_1) + 28) & 127;
  int stage_v_181_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_5_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_181_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_181_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((((stage_v_142_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_6_1) + 3) & 127;
  int stage_v_182_2 = ((((stage_v_142_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_182_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_182_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_2_1) + 5) & 127;
  int stage_v_183_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_183_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_183_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((((sec_r000594_3_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_19_1) + 24) & 127;
  int stage_v_184_2 = ((((sec_r000594_3_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_19_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_184_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_184_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((((sec_r000594_5_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_3_1) + 3) & 127;
  int stage_v_185_2 = ((((sec_r000594_5_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_185_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_185_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((((stage_v_166_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_12_1) + 25) & 127;
  int stage_v_186_2 = ((((stage_v_166_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_186_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_186_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((((stage_v_130_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_7_1) + 27) & 127;
  int stage_v_187_2 = ((((stage_v_130_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_187_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_187_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((((stage_v_172_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_16_1) + 35) & 127;
  int stage_v_188_2 = ((((stage_v_172_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_188_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_188_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((((stage_v_181_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_7_1) + 30) & 127;
  int stage_v_189_2 = ((((stage_v_181_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_189_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_189_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((((stage_v_91_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_9_1) + 23) & 127;
  int stage_v_190_2 = ((((stage_v_91_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_190_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_190_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((((sec_r000594_8_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_6_1) + 20) & 127;
  int stage_v_191_2 = ((((sec_r000594_8_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_191_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_191_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((((stage_v_137_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_12_1) + 25) & 127;
  int stage_v_192_2 = ((((stage_v_137_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_192_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_192_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((((stage_v_154_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_19_1) + 29) & 127;
  int stage_v_193_2 = ((((stage_v_154_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_19_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_193_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_193_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((((stage_v_140_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_5_1) + 15) & 127;
  int stage_v_194_2 = ((((stage_v_140_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_194_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_194_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((((stage_v_79_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_16_1) + 8) & 127;
  int stage_v_195_2 = ((((stage_v_79_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_195_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_195_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((((stage_v_191_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_6_1) + 30) & 127;
  int stage_v_196_2 = ((((stage_v_191_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_196_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_196_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((((sec_r000594_2_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_2_1) + 22) & 127;
  int stage_v_197_2 = ((((sec_r000594_2_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_197_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_197_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((((stage_v_162_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_18_1) + 35) & 127;
  int stage_v_198_2 = ((((stage_v_162_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_18_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_198_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_198_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((((sec_r000594_1_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_3_1) + 22) & 127;
  int stage_v_199_2 = ((((sec_r000594_1_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_199_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_199_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((((stage_v_174_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_6_1) + 14) & 127;
  int stage_v_200_2 = ((((stage_v_174_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_200_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_200_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((((stage_v_105_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_21_1) + 31) & 127;
  int stage_v_201_2 = ((((stage_v_105_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_21_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_201_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_201_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_2_1) + 14) & 127;
  int stage_v_202_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_202_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_202_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((((stage_v_109_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_19_1) + 20) & 127;
  int stage_v_203_2 = ((((stage_v_109_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_203_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_203_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((((stage_v_154_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_16_1) + 34) & 127;
  int stage_v_204_2 = ((((stage_v_154_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_204_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_204_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((((stage_v_85_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_12_1) + 29) & 127;
  int stage_v_205_2 = ((((stage_v_85_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_205_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_205_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_9_1) + 7) & 127;
  int stage_v_206_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_206_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_206_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((((stage_v_85_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_20_1) + 23) & 127;
  int stage_v_207_2 = ((((stage_v_85_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_207_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_207_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((((stage_v_123_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_14_1) + 24) & 127;
  int stage_v_208_2 = ((((stage_v_123_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_14_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_208_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_208_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((((stage_v_108_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_21_1) + 5) & 127;
  int stage_v_209_2 = ((((stage_v_108_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_209_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_209_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((((stage_v_93_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_5_1) + 29) & 127;
  int stage_v_210_2 = ((((stage_v_93_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_210_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_210_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((((stage_v_88_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_1_1) + 37) & 127;
  int stage_v_211_2 = ((((stage_v_88_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_1_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_211_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_211_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_17_1) + 6) & 127;
  int stage_v_212_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_17_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_212_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_212_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((((stage_v_81_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_8_1) + 28) & 127;
  int stage_v_213_2 = ((((stage_v_81_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_8_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_213_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_213_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((((sec_r000594_6_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_16_1) + 8) & 127;
  int stage_v_214_2 = ((((sec_r000594_6_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_214_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_214_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((((stage_v_153_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_5_1) + 9) & 127;
  int stage_v_215_2 = ((((stage_v_153_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_215_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_215_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((((stage_v_95_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_12_1) + 9) & 127;
  int stage_v_216_2 = ((((stage_v_95_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_12_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_216_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_216_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((((stage_v_164_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_15_1) + 17) & 127;
  int stage_v_217_2 = ((((stage_v_164_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_217_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_217_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((((stage_v_212_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_1_1) + 20) & 127;
  int stage_v_218_2 = ((((stage_v_212_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_218_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_218_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((((stage_v_160_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_10_1) + 35) & 127;
  int stage_v_219_2 = ((((stage_v_160_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_219_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_219_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((((stage_v_111_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_10_1) + 31) & 127;
  int stage_v_220_2 = ((((stage_v_111_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_220_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_220_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((((stage_v_182_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_9_1) + 19) & 127;
  int stage_v_221_2 = ((((stage_v_182_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_221_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_221_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((((sec_r000594_2_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_1_1) + 22) & 127;
  int stage_v_222_2 = ((((sec_r000594_2_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_222_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_222_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((((stage_v_192_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_11_1) + 20) & 127;
  int stage_v_223_2 = ((((stage_v_192_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_223_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_223_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((((stage_v_161_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_17_1) + 15) & 127;
  int stage_v_224_2 = ((((stage_v_161_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_224_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_224_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((((stage_v_136_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_14_1) + 6) & 127;
  int stage_v_225_2 = ((((stage_v_136_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_225_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_225_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((((stage_v_81_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_13_1) + 16) & 127;
  int stage_v_226_2 = ((((stage_v_81_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_226_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_226_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((((stage_v_198_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_20_1) + 19) & 127;
  int stage_v_227_2 = ((((stage_v_198_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_20_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_227_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_227_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((((stage_v_201_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_13_1) + 16) & 127;
  int stage_v_228_2 = ((((stage_v_201_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_228_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_228_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_1_1) + 17) & 127;
  int stage_v_229_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_229_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_229_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((((stage_v_149_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_14_1) + 33) & 127;
  int stage_v_230_2 = ((((stage_v_149_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_230_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_230_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  int stage_v_231_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_6_1) + 9) & 127;
  int stage_v_231_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_231_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_231_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  int stage_v_232_1 = ((((sec_r000594_14_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_6_1) + 37) & 127;
  int stage_v_232_2 = ((((sec_r000594_14_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_232_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_232_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  int stage_v_233_1 = ((((stage_v_88_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_16_1) + 20) & 127;
  int stage_v_233_2 = ((((stage_v_88_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_16_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_233_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_233_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  int stage_v_234_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_12_1) + 18) & 127;
  int stage_v_234_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_234_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_234_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  int stage_v_235_1 = ((((stage_v_184_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_9_1) + 25) & 127;
  int stage_v_235_2 = ((((stage_v_184_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_235_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_235_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  int stage_v_236_1 = ((((sec_r000594_12_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_0_1) + 20) & 127;
  int stage_v_236_2 = ((((sec_r000594_12_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_236_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_236_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  int stage_v_237_1 = ((((stage_v_97_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_6_1) + 26) & 127;
  int stage_v_237_2 = ((((stage_v_97_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_237_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_237_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  int stage_v_238_1 = ((((stage_v_84_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_15_1) + 6) & 127;
  int stage_v_238_2 = ((((stage_v_84_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_238_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_238_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  int stage_v_239_1 = ((((stage_v_141_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_5_1) + 25) & 127;
  int stage_v_239_2 = ((((stage_v_141_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_239_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_239_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  int stage_v_240_1 = ((((stage_v_122_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_9_1) + 14) & 127;
  int stage_v_240_2 = ((((stage_v_122_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_240_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_240_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  int stage_v_241_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_7_1) + 32) & 127;
  int stage_v_241_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_241_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_241_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  int stage_v_242_1 = ((((stage_v_211_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_21_1) + 30) & 127;
  int stage_v_242_2 = ((((stage_v_211_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_242_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_242_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  int stage_v_243_1 = ((((stage_v_129_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_20_1) + 5) & 127;
  int stage_v_243_2 = ((((stage_v_129_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_20_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_243_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_243_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  int stage_v_244_1 = ((((stage_v_235_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_18_1) + 24) & 127;
  int stage_v_244_2 = ((((stage_v_235_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_18_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_244_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_244_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  int stage_v_245_1 = ((((stage_v_229_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_18_1) + 9) & 127;
  int stage_v_245_2 = ((((stage_v_229_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_18_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_245_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_245_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  int stage_v_246_1 = ((((stage_v_243_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_7_1) + 13) & 127;
  int stage_v_246_2 = ((((stage_v_243_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_7_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_246_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_246_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  int stage_v_247_1 = ((((sec_r000594_2_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_21_1) + 18) & 127;
  int stage_v_247_2 = ((((sec_r000594_2_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_21_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_247_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_247_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  int stage_v_248_1 = ((((stage_v_169_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_18_1) + 34) & 127;
  int stage_v_248_2 = ((((stage_v_169_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_248_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_248_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  int stage_v_249_1 = ((((stage_v_210_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_15_1) + 19) & 127;
  int stage_v_249_2 = ((((stage_v_210_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_249_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_249_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  int stage_v_250_1 = ((((stage_v_213_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_8_1) + 23) & 127;
  int stage_v_250_2 = ((((stage_v_213_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_250_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_250_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  int stage_v_251_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_11_1) + 28) & 127;
  int stage_v_251_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_251_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_251_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  int stage_v_252_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_20_1) + 32) & 127;
  int stage_v_252_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_252_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_252_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  int stage_v_253_1 = ((((stage_v_83_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_15_1) + 27) & 127;
  int stage_v_253_2 = ((((stage_v_83_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_15_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_253_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_253_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  int stage_v_254_1 = ((((stage_v_86_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_6_1) + 15) & 127;
  int stage_v_254_2 = ((((stage_v_86_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_254_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_254_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  int stage_v_255_1 = ((((stage_v_214_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_0_1) + 23) & 127;
  int stage_v_255_2 = ((((stage_v_214_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_255_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_255_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  int stage_v_256_1 = ((((stage_v_115_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_18_1) + 26) & 127;
  int stage_v_256_2 = ((((stage_v_115_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_256_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_256_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  int stage_v_257_1 = ((((sec_r000594_6_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_19_1) + 34) & 127;
  int stage_v_257_2 = ((((sec_r000594_6_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_19_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_257_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_257_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  int stage_v_258_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_3_1) + 18) & 127;
  int stage_v_258_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_258_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_258_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  int stage_v_259_1 = ((((stage_v_190_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_20_1) + 29) & 127;
  int stage_v_259_2 = ((((stage_v_190_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_20_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_259_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_259_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  int stage_v_260_1 = ((((stage_v_241_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_11_1) + 17) & 127;
  int stage_v_260_2 = ((((stage_v_241_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_11_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_260_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_260_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  int stage_v_261_1 = ((((sec_r000594_9_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_13_1) + 18) & 127;
  int stage_v_261_2 = ((((sec_r000594_9_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_261_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_261_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  int stage_v_262_1 = ((((stage_v_256_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_6_1) + 27) & 127;
  int stage_v_262_2 = ((((stage_v_256_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_262_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_262_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  int stage_v_263_1 = ((((stage_v_126_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_17_1) + 13) & 127;
  int stage_v_263_2 = ((((stage_v_126_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_17_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_263_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_263_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  int stage_v_264_1 = ((((stage_v_93_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_10_1) + 9) & 127;
  int stage_v_264_2 = ((((stage_v_93_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_10_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_264_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_264_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  int stage_v_265_1 = ((((stage_v_241_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_19_1) + 19) & 127;
  int stage_v_265_2 = ((((stage_v_241_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_19_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_265_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_265_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  int stage_v_266_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_5_1) + 18) & 127;
  int stage_v_266_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_266_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_266_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  int stage_v_267_1 = ((((sec_r000594_15_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_6_1) + 5) & 127;
  int stage_v_267_2 = ((((sec_r000594_15_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_267_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_267_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  int stage_v_268_1 = ((((stage_v_90_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_0_1) + 5) & 127;
  int stage_v_268_2 = ((((stage_v_90_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_268_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_268_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  int stage_v_269_1 = ((((stage_v_267_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_14_1) + 20) & 127;
  int stage_v_269_2 = ((((stage_v_267_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_269_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_269_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  int stage_v_270_1 = ((((sec_r000594_9_1 * 3) + (sec_r000594_9_1 * 2)) - pub_r000594_20_1) + 23) & 127;
  int stage_v_270_2 = ((((sec_r000594_9_2 * 3) + (sec_r000594_9_2 * 2)) - pub_r000594_20_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_270_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_270_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  int stage_v_271_1 = ((((sec_r000594_8_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_11_1) + 33) & 127;
  int stage_v_271_2 = ((((sec_r000594_8_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_271_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_271_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  int stage_v_272_1 = ((((sec_r000594_6_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_2_1) + 9) & 127;
  int stage_v_272_2 = ((((sec_r000594_6_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_272_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_272_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  int stage_v_273_1 = ((((stage_v_234_1 * 3) + (sec_r000594_3_1 * 2)) - pub_r000594_8_1) + 4) & 127;
  int stage_v_273_2 = ((((stage_v_234_2 * 3) + (sec_r000594_3_2 * 2)) - pub_r000594_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_273_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_273_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  int stage_v_274_1 = ((((stage_v_167_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_14_1) + 33) & 127;
  int stage_v_274_2 = ((((stage_v_167_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_274_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_274_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_274_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_274_2) & 255;
  int stage_v_275_1 = ((((sec_r000594_8_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_7_1) + 9) & 127;
  int stage_v_275_2 = ((((sec_r000594_8_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_275_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_275_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_275_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_275_2) & 255;
  int stage_v_276_1 = ((((stage_v_188_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_16_1) + 3) & 127;
  int stage_v_276_2 = ((((stage_v_188_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_16_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_276_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_276_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_276_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_276_2) & 255;
  int stage_v_277_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_12_1) + 8) & 127;
  int stage_v_277_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_277_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_277_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_277_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_277_2) & 255;
  int stage_v_278_1 = ((((stage_v_235_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_3_1) + 18) & 127;
  int stage_v_278_2 = ((((stage_v_235_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_278_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_278_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_278_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_278_2) & 255;
  int stage_v_279_1 = ((((stage_v_108_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_5_1) + 14) & 127;
  int stage_v_279_2 = ((((stage_v_108_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_5_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_279_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_279_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_279_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_279_2) & 255;
  int stage_v_280_1 = ((((stage_v_156_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_21_1) + 13) & 127;
  int stage_v_280_2 = ((((stage_v_156_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_280_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_280_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_280_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_280_2) & 255;
  int stage_v_281_1 = ((((stage_v_136_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_15_1) + 4) & 127;
  int stage_v_281_2 = ((((stage_v_136_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_15_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_281_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_281_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_281_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_281_2) & 255;
  int stage_v_282_1 = ((((stage_v_273_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_18_1) + 10) & 127;
  int stage_v_282_2 = ((((stage_v_273_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_18_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_282_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_282_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_282_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_282_2) & 255;
  int stage_v_283_1 = ((((stage_v_243_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_10_1) + 15) & 127;
  int stage_v_283_2 = ((((stage_v_243_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_283_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_283_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_283_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_283_2) & 255;
  int stage_v_284_1 = ((((stage_v_276_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_20_1) + 27) & 127;
  int stage_v_284_2 = ((((stage_v_276_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_20_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_284_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_284_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_284_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_284_2) & 255;
  int stage_v_285_1 = ((((stage_v_207_1 * 3) + (sec_r000594_2_1 * 2)) - pub_r000594_14_1) + 18) & 127;
  int stage_v_285_2 = ((((stage_v_207_2 * 3) + (sec_r000594_2_2 * 2)) - pub_r000594_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_285_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_285_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_285_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_285_2) & 255;
  int stage_v_286_1 = ((((sec_r000594_5_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_18_1) + 33) & 127;
  int stage_v_286_2 = ((((sec_r000594_5_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_286_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_286_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_286_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_286_2) & 255;
  int stage_v_287_1 = ((((stage_v_150_1 * 3) + (sec_r000594_12_1 * 2)) - pub_r000594_16_1) + 36) & 127;
  int stage_v_287_2 = ((((stage_v_150_2 * 3) + (sec_r000594_12_2 * 2)) - pub_r000594_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_287_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_287_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_287_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_287_2) & 255;
  int stage_v_288_1 = ((((stage_v_211_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_2_1) + 22) & 127;
  int stage_v_288_2 = ((((stage_v_211_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_288_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_288_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_288_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_288_2) & 255;
  int stage_v_289_1 = ((((stage_v_275_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_2_1) + 8) & 127;
  int stage_v_289_2 = ((((stage_v_275_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_2_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_289_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_289_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_289_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_289_2) & 255;
  int stage_v_290_1 = ((((sec_r000594_6_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_14_1) + 26) & 127;
  int stage_v_290_2 = ((((sec_r000594_6_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_290_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_290_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_290_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_290_2) & 255;
  int stage_v_291_1 = ((((sec_r000594_10_1 * 3) + (sec_r000594_10_1 * 2)) - pub_r000594_15_1) + 11) & 127;
  int stage_v_291_2 = ((((sec_r000594_10_2 * 3) + (sec_r000594_10_2 * 2)) - pub_r000594_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_291_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_291_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_291_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_291_2) & 255;
  int stage_v_292_1 = ((((stage_v_84_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_4_1) + 26) & 127;
  int stage_v_292_2 = ((((stage_v_84_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_292_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_292_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_292_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_292_2) & 255;
  int stage_v_293_1 = ((((sec_r000594_4_1 * 3) + (sec_r000594_4_1 * 2)) - pub_r000594_13_1) + 14) & 127;
  int stage_v_293_2 = ((((sec_r000594_4_2 * 3) + (sec_r000594_4_2 * 2)) - pub_r000594_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_293_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_293_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_293_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_293_2) & 255;
  int stage_v_294_1 = ((((stage_v_230_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_17_1) + 19) & 127;
  int stage_v_294_2 = ((((stage_v_230_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_294_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_294_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_294_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_294_2) & 255;
  int stage_v_295_1 = ((((stage_v_294_1 * 3) + (sec_r000594_7_1 * 2)) - pub_r000594_1_1) + 21) & 127;
  int stage_v_295_2 = ((((stage_v_294_2 * 3) + (sec_r000594_7_2 * 2)) - pub_r000594_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_295_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_295_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_295_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_295_2) & 255;
  int stage_v_296_1 = ((((sec_r000594_5_1 * 3) + (sec_r000594_5_1 * 2)) - pub_r000594_7_1) + 19) & 127;
  int stage_v_296_2 = ((((sec_r000594_5_2 * 3) + (sec_r000594_5_2 * 2)) - pub_r000594_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_296_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_296_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_296_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_296_2) & 255;
  int stage_v_297_1 = ((((stage_v_235_1 * 3) + (sec_r000594_8_1 * 2)) - pub_r000594_15_1) + 17) & 127;
  int stage_v_297_2 = ((((stage_v_235_2 * 3) + (sec_r000594_8_2 * 2)) - pub_r000594_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_297_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_297_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_297_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_297_2) & 255;
  int stage_v_298_1 = ((((stage_v_94_1 * 3) + (sec_r000594_14_1 * 2)) - pub_r000594_9_1) + 10) & 127;
  int stage_v_298_2 = ((((stage_v_94_2 * 3) + (sec_r000594_14_2 * 2)) - pub_r000594_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_298_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_298_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_298_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_298_2) & 255;
  int stage_v_299_1 = ((((stage_v_294_1 * 3) + (sec_r000594_6_1 * 2)) - pub_r000594_3_1) + 4) & 127;
  int stage_v_299_2 = ((((stage_v_294_2 * 3) + (sec_r000594_6_2 * 2)) - pub_r000594_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_299_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_299_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_299_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_299_2) & 255;
  int stage_v_300_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_15_1) + 8) & 127;
  int stage_v_300_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_300_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_300_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_300_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_300_2) & 255;
  int stage_v_301_1 = ((((stage_v_277_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_18_1) + 12) & 127;
  int stage_v_301_2 = ((((stage_v_277_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_301_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_301_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_301_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_301_2) & 255;
  int stage_v_302_1 = ((((sec_r000594_17_1 * 3) + (sec_r000594_17_1 * 2)) - pub_r000594_7_1) + 37) & 127;
  int stage_v_302_2 = ((((sec_r000594_17_2 * 3) + (sec_r000594_17_2 * 2)) - pub_r000594_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_302_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_302_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_302_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_302_2) & 255;
  int stage_v_303_1 = ((((stage_v_163_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_19_1) + 20) & 127;
  int stage_v_303_2 = ((((stage_v_163_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_303_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_303_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_303_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_303_2) & 255;
  int stage_v_304_1 = ((((stage_v_249_1 * 3) + (sec_r000594_1_1 * 2)) - pub_r000594_2_1) + 12) & 127;
  int stage_v_304_2 = ((((stage_v_249_2 * 3) + (sec_r000594_1_2 * 2)) - pub_r000594_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_304_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_304_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_304_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_304_2) & 255;
  int stage_v_305_1 = ((((sec_r000594_0_1 * 3) + (sec_r000594_0_1 * 2)) - pub_r000594_0_1) + 25) & 127;
  int stage_v_305_2 = ((((sec_r000594_0_2 * 3) + (sec_r000594_0_2 * 2)) - pub_r000594_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_305_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_305_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_305_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_305_2) & 255;
  int stage_v_306_1 = ((((sec_r000594_15_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_16_1) + 7) & 127;
  int stage_v_306_2 = ((((sec_r000594_15_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_16_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_306_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_306_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_306_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_306_2) & 255;
  int stage_v_307_1 = ((((sec_r000594_15_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_3_1) + 26) & 127;
  int stage_v_307_2 = ((((sec_r000594_15_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_3_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_307_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_307_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_307_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_307_2) & 255;
  int stage_v_308_1 = ((((stage_v_261_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_12_1) + 25) & 127;
  int stage_v_308_2 = ((((stage_v_261_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_308_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_308_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_308_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_308_2) & 255;
  int stage_v_309_1 = ((((sec_r000594_16_1 * 3) + (sec_r000594_16_1 * 2)) - pub_r000594_0_1) + 27) & 127;
  int stage_v_309_2 = ((((sec_r000594_16_2 * 3) + (sec_r000594_16_2 * 2)) - pub_r000594_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_309_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_309_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_309_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_309_2) & 255;
  int stage_v_310_1 = ((((stage_v_299_1 * 3) + (sec_r000594_15_1 * 2)) - pub_r000594_13_1) + 31) & 127;
  int stage_v_310_2 = ((((stage_v_299_2 * 3) + (sec_r000594_15_2 * 2)) - pub_r000594_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_310_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_310_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_310_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_310_2) & 255;
  int stage_v_311_1 = ((((stage_v_218_1 * 3) + (sec_r000594_11_1 * 2)) - pub_r000594_15_1) + 36) & 127;
  int stage_v_311_2 = ((((stage_v_218_2 * 3) + (sec_r000594_11_2 * 2)) - pub_r000594_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_311_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_311_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_311_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_311_2) & 255;
  int stage_v_312_1 = ((((sec_r000594_13_1 * 3) + (sec_r000594_13_1 * 2)) - pub_r000594_6_1) + 7) & 127;
  int stage_v_312_2 = ((((sec_r000594_13_2 * 3) + (sec_r000594_13_2 * 2)) - pub_r000594_6_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + (stage_v_312_1 * 2)) & 255;
  sec_accum_2 = (sec_accum_2 + (stage_v_312_2 * 2)) & 255;
  out_sink_1 = (out_sink_1 + stage_v_312_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_312_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000594_3_1 == pub_r000594_3_2);
  __CPROVER_assume(sec_r000594_15_1 != sec_r000594_15_2);
  __CPROVER_assume(pub_r000594_14_1 == pub_r000594_14_2);
  __CPROVER_assume(sec_r000594_17_1 != sec_r000594_17_2);
  __CPROVER_assume(pub_r000594_21_1 == pub_r000594_21_2);
  __CPROVER_assume(pub_r000594_16_1 == pub_r000594_16_2);
  __CPROVER_assume(pub_r000594_18_1 == pub_r000594_18_2);
  __CPROVER_assume(pub_r000594_0_1 == pub_r000594_0_2);
  __CPROVER_assume(sec_r000594_3_1 != sec_r000594_3_2);
  __CPROVER_assume(pub_r000594_13_1 == pub_r000594_13_2);
  __CPROVER_assume(sec_r000594_14_1 != sec_r000594_14_2);
  __CPROVER_assume(sec_r000594_9_1 != sec_r000594_9_2);
  __CPROVER_assume(sec_r000594_2_1 != sec_r000594_2_2);
  __CPROVER_assume(sec_r000594_0_1 != sec_r000594_0_2);
  __CPROVER_assume(sec_r000594_4_1 != sec_r000594_4_2);
  __CPROVER_assume(sec_r000594_11_1 != sec_r000594_11_2);
  __CPROVER_assume(pub_r000594_2_1 == pub_r000594_2_2);
  __CPROVER_assume(pub_r000594_5_1 == pub_r000594_5_2);
  __CPROVER_assume(pub_r000594_8_1 == pub_r000594_8_2);
  __CPROVER_assume(pub_r000594_20_1 == pub_r000594_20_2);
  __CPROVER_assume(sec_r000594_5_1 != sec_r000594_5_2);
  __CPROVER_assume(pub_r000594_1_1 == pub_r000594_1_2);
  __CPROVER_assume(sec_r000594_12_1 != sec_r000594_12_2);
  __CPROVER_assume(pub_r000594_19_1 == pub_r000594_19_2);
  __CPROVER_assume(pub_r000594_10_1 == pub_r000594_10_2);
  __CPROVER_assume(sec_r000594_16_1 != sec_r000594_16_2);
  __CPROVER_assume(pub_r000594_4_1 == pub_r000594_4_2);
  __CPROVER_assume(sec_r000594_8_1 != sec_r000594_8_2);
  __CPROVER_assume(pub_r000594_12_1 == pub_r000594_12_2);
  __CPROVER_assume(sec_r000594_1_1 != sec_r000594_1_2);
  __CPROVER_assume(pub_r000594_15_1 == pub_r000594_15_2);
  __CPROVER_assume(pub_r000594_11_1 == pub_r000594_11_2);
  __CPROVER_assume(sec_r000594_7_1 != sec_r000594_7_2);
  __CPROVER_assume(sec_r000594_6_1 != sec_r000594_6_2);
  __CPROVER_assume(pub_r000594_9_1 == pub_r000594_9_2);
  __CPROVER_assume(pub_r000594_17_1 == pub_r000594_17_2);
  __CPROVER_assume(pub_r000594_6_1 == pub_r000594_6_2);
  __CPROVER_assume(pub_r000594_7_1 == pub_r000594_7_2);
  __CPROVER_assume(sec_r000594_10_1 != sec_r000594_10_2);
  __CPROVER_assume(sec_r000594_13_1 != sec_r000594_13_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
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
}


