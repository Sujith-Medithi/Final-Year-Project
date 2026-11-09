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
struct MatrixBlock_R001323_2313_0
{
  short scale;
  short stride;
  int density;
  short dim;
  unsigned char determinant;
  short trace;
  int buffer[3];
};
struct Vector3D_R001323_2313_1
{
  int pitch;
  int heading;
  unsigned char coord_y;
  short coord_z;
  int coord_x;
  int buffer[3];
};
struct SensorNode_R001323_2313_2
{
  int threshold;
  int calib;
  unsigned char gain;
  unsigned char offset;
  int status;
  int reading;
  int buffer[3];
};
union RegisterBank_R001323_2313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R001323_2313_1
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
void fn_R001323_2313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st_1 = {0};
  struct SensorNode_R001323_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_63_1)
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

  switch (index_reg_63_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_63_1 == index_reg_63_2);
}

int fn_R001323_2313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_63 = (aux + st.buffer[1]) & 3;
  switch (index_reg_63)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st_1 = {0};
  struct Vector3D_R001323_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int threshold_66_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_66_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_66_1)
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

  switch (threshold_66_2)
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

  int coefficient_11_1 = 0;
  int coefficient_11_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_11_1 = ((coefficient_11_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_11_2 = ((coefficient_11_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_11_1) & 127;
    acc_2 = (acc_2 + coefficient_11_2) & 127;
  }

  int bound_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_42_1 > 40)
  {
    acc_1 = ((acc_1 + (bound_42_1 * 2)) + 5) & 127;
    aux_1 ^= bound_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_42_2 > 40)
  {
    acc_2 = ((acc_2 + (bound_42_2 * 2)) + 5) & 127;
    aux_2 ^= bound_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_42_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_66_1 == threshold_66_2);
  assert(coefficient_11_1 == coefficient_11_2);
  assert(bound_42_1 == bound_42_2);
}

int fn_R001323_2313_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int threshold_66 = (aux + st.buffer[1]) & 3;
  switch (threshold_66)
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

  int coefficient_11 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_11 = ((coefficient_11 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_11) & 127;
  }

  int bound_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_42 > 40)
  {
    acc = ((acc + (bound_42 * 2)) + 5) & 127;
    aux ^= bound_42 & 15;
  }
  else
  {
    acc = ((acc - bound_42) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001323_2313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st_1 = {0};
  struct MatrixBlock_R001323_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_12_1 > 39)
  {
    acc_1 = ((acc_1 + (phase_12_1 * 2)) + 5) & 127;
    aux_1 ^= phase_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_12_2 > 39)
  {
    acc_2 = ((acc_2 + (phase_12_2 * 2)) + 5) & 127;
    aux_2 ^= phase_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_12_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_80_1) & 63;
  aux_2 = (aux_2 + margin_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_27_1 = local_arr_1[aux_1 % 3];
  int window_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_27_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_12_1 == phase_12_2);
  assert(margin_80_1 == margin_80_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_27_1 == window_27_2);
}

int fn_R001323_2313_2(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_12 > 39)
  {
    acc = ((acc + (phase_12 * 2)) + 5) & 127;
    aux ^= phase_12 & 15;
  }
  else
  {
    acc = ((acc - phase_12) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_80) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int window_27 = local_arr[aux % 3];
  acc = (acc + (window_27 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st_1 = {0};
  struct MatrixBlock_R001323_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int margin_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_73_1)
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

  switch (margin_73_2)
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

  int parity_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_23_1 > 39)
  {
    acc_1 = ((acc_1 + (parity_23_1 * 2)) + 5) & 127;
    aux_1 ^= parity_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_23_2 > 39)
  {
    acc_2 = ((acc_2 + (parity_23_2 * 2)) + 5) & 127;
    aux_2 ^= parity_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_27_1) & 63;
  aux_2 = (aux_2 + coefficient_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_73_1 == margin_73_2);
  assert(parity_23_1 == parity_23_2);
  assert(coefficient_27_1 == coefficient_27_2);
}

int fn_R001323_2313_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int margin_73 = (aux + st.buffer[1]) & 3;
  switch (margin_73)
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

  int parity_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_23 > 39)
  {
    acc = ((acc + (parity_23 * 2)) + 5) & 127;
    aux ^= parity_23 & 15;
  }
  else
  {
    acc = ((acc - parity_23) + 11) & 127;
    aux += 3;
  }
  int coefficient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001323_2313_4_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st_1 = {0};
  struct MatrixBlock_R001323_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int accumulator_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_67_1 > 50)
  {
    acc_1 = ((acc_1 + (accumulator_67_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_67_2 > 50)
  {
    acc_2 = ((acc_2 + (accumulator_67_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int phase_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_11_1) & 63;
  aux_2 = (aux_2 + phase_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_33_1 = 0;
  int weight_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    weight_33_1 = ((weight_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_33_2 = ((weight_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_33_1) & 127;
    acc_2 = (acc_2 + weight_33_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_67_1 == accumulator_67_2);
  assert(phase_11_1 == phase_11_2);
  assert(weight_33_1 == weight_33_2);
}

int fn_R001323_2313_4(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int accumulator_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_67 > 50)
  {
    acc = ((acc + (accumulator_67 * 2)) + 5) & 127;
    aux ^= accumulator_67 & 15;
  }
  else
  {
    acc = ((acc - accumulator_67) + 11) & 127;
    aux += 3;
  }
  int phase_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_11) & 63;
  acc ^= aux;
  int weight_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    weight_33 = ((weight_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_33) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st_1 = {0};
  struct MatrixBlock_R001323_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_64_1 > 34)
  {
    acc_1 = ((acc_1 + (delta_64_1 * 2)) + 5) & 127;
    aux_1 ^= delta_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_64_2 > 34)
  {
    acc_2 = ((acc_2 + (delta_64_2 * 2)) + 5) & 127;
    aux_2 ^= delta_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_64_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  assert(st_1.dim == st_2.dim);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_64_1 == delta_64_2);
}

int fn_R001323_2313_5(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001323_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_64 > 34)
  {
    acc = ((acc + (delta_64 * 2)) + 5) & 127;
    aux ^= delta_64 & 15;
  }
  else
  {
    acc = ((acc - delta_64) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001323_2313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st_1 = {0};
  struct SensorNode_R001323_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int factor_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_68_1) & 63;
  aux_2 = (aux_2 + factor_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int margin_70_1 = 0;
  int margin_70_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    margin_70_1 = ((margin_70_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_70_2 = ((margin_70_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_70_1) & 127;
    acc_2 = (acc_2 + margin_70_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_62_1 = local_arr_1[aux_1 % 3];
  int pivot_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_62_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
  assert(st_1.offset == st_2.offset);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_68_1 == factor_68_2);
  assert(margin_70_1 == margin_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_62_1 == pivot_62_2);
}

int fn_R001323_2313_6(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int factor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_68) & 63;
  acc ^= aux;
  int margin_70 = 0;
  for (int k = 0; k < 3; k++)
  {
    margin_70 = ((margin_70 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_70) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int pivot_62 = local_arr[aux % 3];
  acc = (acc + (pivot_62 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st_1 = {0};
  struct Vector3D_R001323_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_46_1)
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

  switch (quantum_46_2)
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

  int quotient_49_1 = 0;
  int quotient_49_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_49_1 = ((quotient_49_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_49_2 = ((quotient_49_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_49_1) & 127;
    acc_2 = (acc_2 + quotient_49_2) & 127;
  }

  int quantum_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_66_1) & 63;
  aux_2 = (aux_2 + quantum_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_82_1 = local_arr_1[aux_1 % 3];
  int quotient_82_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_82_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_82_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_46_1 == quantum_46_2);
  assert(quotient_49_1 == quotient_49_2);
  assert(quantum_66_1 == quantum_66_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_82_1 == quotient_82_2);
}

int fn_R001323_2313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_46 = (aux + st.buffer[1]) & 3;
  switch (quantum_46)
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

  int quotient_49 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_49 = ((quotient_49 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_49) & 127;
  }

  int quantum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_66) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int quotient_82 = local_arr[aux % 3];
  acc = (acc + (quotient_82 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st_1 = {0};
  struct Vector3D_R001323_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int delta_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_21_1)
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

  switch (delta_21_2)
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
  int mask_18_1 = local_arr_1[aux_1 % 3];
  int mask_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_18_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_21_1 == delta_21_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_18_1 == mask_18_2);
}

int fn_R001323_2313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int delta_21 = (aux + st.buffer[1]) & 3;
  switch (delta_21)
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
  int mask_18 = local_arr[aux % 3];
  acc = (acc + (mask_18 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001323_2313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st_1 = {0};
  struct Vector3D_R001323_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_18_1)
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

  switch (tally_18_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_18_1 == tally_18_2);
}

int fn_R001323_2313_9(int p0, int p1)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_18 = (aux + st.buffer[1]) & 3;
  switch (tally_18)
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
  return (acc + aux) & 255;
}

void fn_R001323_2313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st_1 = {0};
  struct SensorNode_R001323_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_75_1 = local_arr_1[aux_1 % 3];
  int stride_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_75_2 * 2)) & 127;
  int metric_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_98_1 > 20)
  {
    acc_1 = ((acc_1 + (metric_98_1 * 2)) + 5) & 127;
    aux_1 ^= metric_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_98_2 > 20)
  {
    acc_2 = ((acc_2 + (metric_98_2 * 2)) + 5) & 127;
    aux_2 ^= metric_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_98_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
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

  assert(stride_75_1 == stride_75_2);
  assert(metric_98_1 == metric_98_2);
}

int fn_R001323_2313_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int stride_75 = local_arr[aux % 3];
  acc = (acc + (stride_75 * 2)) & 127;
  int metric_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_98 > 20)
  {
    acc = ((acc + (metric_98 * 2)) + 5) & 127;
    aux ^= metric_98 & 15;
  }
  else
  {
    acc = ((acc - metric_98) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001323_2313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st_1 = {0};
  struct Vector3D_R001323_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int factor_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_26_1 > 48)
  {
    acc_1 = ((acc_1 + (factor_26_1 * 2)) + 5) & 127;
    aux_1 ^= factor_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_26_2 > 48)
  {
    acc_2 = ((acc_2 + (factor_26_2 * 2)) + 5) & 127;
    aux_2 ^= factor_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tally_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tally_78_1)
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

  switch (tally_78_2)
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

  int sample_68_1 = 0;
  int sample_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_68_1 = ((sample_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_68_2 = ((sample_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_68_1) & 127;
    acc_2 = (acc_2 + sample_68_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_26_1 == factor_26_2);
  assert(tally_78_1 == tally_78_2);
  assert(sample_68_1 == sample_68_2);
}

int fn_R001323_2313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001323_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int factor_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_26 > 48)
  {
    acc = ((acc + (factor_26 * 2)) + 5) & 127;
    aux ^= factor_26 & 15;
  }
  else
  {
    acc = ((acc - factor_26) + 11) & 127;
    aux += 3;
  }
  int tally_78 = (aux + st.buffer[1]) & 3;
  switch (tally_78)
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

  int sample_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_68 = ((sample_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_68) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001323_2313_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st_1 = {0};
  struct SensorNode_R001323_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_57_1 = local_arr_1[aux_1 % 3];
  int coefficient_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_57_2 * 2)) & 127;
  int threshold_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_61_1) & 63;
  aux_2 = (aux_2 + threshold_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
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

  assert(coefficient_57_1 == coefficient_57_2);
  assert(threshold_61_1 == threshold_61_2);
}

int fn_R001323_2313_12(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int local_arr[3] = {4, 9, 15};
  int coefficient_57 = local_arr[aux % 3];
  acc = (acc + (coefficient_57 * 2)) & 127;
  int threshold_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001323_2313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st_1 = {0};
  struct SensorNode_R001323_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_19_1 = local_arr_1[aux_1 % 3];
  int factor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_19_2 * 2)) & 127;
  int stride_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_69_1 > 37)
  {
    acc_1 = ((acc_1 + (stride_69_1 * 2)) + 5) & 127;
    aux_1 ^= stride_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_69_2 > 37)
  {
    acc_2 = ((acc_2 + (stride_69_2 * 2)) + 5) & 127;
    aux_2 ^= stride_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_69_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.calib == st_2.calib);
  assert(st_1.gain == st_2.gain);
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

  assert(factor_19_1 == factor_19_2);
  assert(stride_69_1 == stride_69_2);
}

int fn_R001323_2313_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001323_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int factor_19 = local_arr[aux % 3];
  acc = (acc + (factor_19 * 2)) & 127;
  int stride_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_69 > 37)
  {
    acc = ((acc + (stride_69 * 2)) + 5) & 127;
    aux ^= stride_69 & 15;
  }
  else
  {
    acc = ((acc - stride_69) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001323_0_1;
  int sec_r001323_0_2;
  int sec_r001323_1_1;
  int sec_r001323_1_2;
  int sec_r001323_2_1;
  int sec_r001323_2_2;
  int sec_r001323_3_1;
  int sec_r001323_3_2;
  int sec_r001323_4_1;
  int sec_r001323_4_2;
  int sec_r001323_5_1;
  int sec_r001323_5_2;
  int sec_r001323_6_1;
  int sec_r001323_6_2;
  int sec_r001323_7_1;
  int sec_r001323_7_2;
  int sec_r001323_8_1;
  int sec_r001323_8_2;
  int sec_r001323_9_1;
  int sec_r001323_9_2;
  int sec_r001323_10_1;
  int sec_r001323_10_2;
  int sec_r001323_11_1;
  int sec_r001323_11_2;
  int sec_r001323_12_1;
  int sec_r001323_12_2;
  int sec_r001323_13_1;
  int sec_r001323_13_2;
  int sec_r001323_14_1;
  int sec_r001323_14_2;
  int sec_r001323_15_1;
  int sec_r001323_15_2;
  int sec_r001323_16_1;
  int sec_r001323_16_2;
  int sec_r001323_17_1;
  int sec_r001323_17_2;
  int sec_r001323_18_1;
  int sec_r001323_18_2;
  int sec_r001323_19_1;
  int sec_r001323_19_2;
  int sec_r001323_20_1;
  int sec_r001323_20_2;
  int pub_r001323_0_1;
  int pub_r001323_0_2;
  int pub_r001323_1_1;
  int pub_r001323_1_2;
  int pub_r001323_2_1;
  int pub_r001323_2_2;
  int pub_r001323_3_1;
  int pub_r001323_3_2;
  int pub_r001323_4_1;
  int pub_r001323_4_2;
  int pub_r001323_5_1;
  int pub_r001323_5_2;
  int pub_r001323_6_1;
  int pub_r001323_6_2;
  int pub_r001323_7_1;
  int pub_r001323_7_2;
  int pub_r001323_8_1;
  int pub_r001323_8_2;
  int pub_r001323_9_1;
  int pub_r001323_9_2;
  int pub_r001323_10_1;
  int pub_r001323_10_2;
  int pub_r001323_11_1;
  int pub_r001323_11_2;
  int pub_r001323_12_1;
  int pub_r001323_12_2;
  int pub_r001323_13_1;
  int pub_r001323_13_2;
  int pub_r001323_14_1;
  int pub_r001323_14_2;
  int pub_r001323_15_1;
  int pub_r001323_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001323_0_1 >= (-100)) && (pub_r001323_0_1 <= 100));
  __CPROVER_assume((pub_r001323_0_2 >= (-100)) && (pub_r001323_0_2 <= 100));
  __CPROVER_assume((pub_r001323_1_1 >= (-100)) && (pub_r001323_1_1 <= 100));
  __CPROVER_assume((pub_r001323_1_2 >= (-100)) && (pub_r001323_1_2 <= 100));
  __CPROVER_assume((pub_r001323_2_1 >= (-100)) && (pub_r001323_2_1 <= 100));
  __CPROVER_assume((pub_r001323_2_2 >= (-100)) && (pub_r001323_2_2 <= 100));
  __CPROVER_assume((pub_r001323_3_1 >= (-100)) && (pub_r001323_3_1 <= 100));
  __CPROVER_assume((pub_r001323_3_2 >= (-100)) && (pub_r001323_3_2 <= 100));
  __CPROVER_assume((pub_r001323_4_1 >= (-100)) && (pub_r001323_4_1 <= 100));
  __CPROVER_assume((pub_r001323_4_2 >= (-100)) && (pub_r001323_4_2 <= 100));
  __CPROVER_assume((pub_r001323_5_1 >= (-100)) && (pub_r001323_5_1 <= 100));
  __CPROVER_assume((pub_r001323_5_2 >= (-100)) && (pub_r001323_5_2 <= 100));
  __CPROVER_assume((pub_r001323_6_1 >= (-100)) && (pub_r001323_6_1 <= 100));
  __CPROVER_assume((pub_r001323_6_2 >= (-100)) && (pub_r001323_6_2 <= 100));
  __CPROVER_assume((pub_r001323_7_1 >= (-100)) && (pub_r001323_7_1 <= 100));
  __CPROVER_assume((pub_r001323_7_2 >= (-100)) && (pub_r001323_7_2 <= 100));
  __CPROVER_assume((pub_r001323_8_1 >= (-100)) && (pub_r001323_8_1 <= 100));
  __CPROVER_assume((pub_r001323_8_2 >= (-100)) && (pub_r001323_8_2 <= 100));
  __CPROVER_assume((pub_r001323_9_1 >= (-100)) && (pub_r001323_9_1 <= 100));
  __CPROVER_assume((pub_r001323_9_2 >= (-100)) && (pub_r001323_9_2 <= 100));
  __CPROVER_assume((pub_r001323_10_1 >= (-100)) && (pub_r001323_10_1 <= 100));
  __CPROVER_assume((pub_r001323_10_2 >= (-100)) && (pub_r001323_10_2 <= 100));
  __CPROVER_assume((pub_r001323_11_1 >= (-100)) && (pub_r001323_11_1 <= 100));
  __CPROVER_assume((pub_r001323_11_2 >= (-100)) && (pub_r001323_11_2 <= 100));
  __CPROVER_assume((pub_r001323_12_1 >= (-100)) && (pub_r001323_12_1 <= 100));
  __CPROVER_assume((pub_r001323_12_2 >= (-100)) && (pub_r001323_12_2 <= 100));
  __CPROVER_assume((pub_r001323_13_1 >= (-100)) && (pub_r001323_13_1 <= 100));
  __CPROVER_assume((pub_r001323_13_2 >= (-100)) && (pub_r001323_13_2 <= 100));
  __CPROVER_assume((pub_r001323_14_1 >= (-100)) && (pub_r001323_14_1 <= 100));
  __CPROVER_assume((pub_r001323_14_2 >= (-100)) && (pub_r001323_14_2 <= 100));
  __CPROVER_assume((pub_r001323_15_1 >= (-100)) && (pub_r001323_15_1 <= 100));
  __CPROVER_assume((pub_r001323_15_2 >= (-100)) && (pub_r001323_15_2 <= 100));
  __CPROVER_assume((sec_r001323_0_1 >= 0) && (sec_r001323_0_1 <= 255));
  __CPROVER_assume((sec_r001323_0_2 >= 0) && (sec_r001323_0_2 <= 255));
  __CPROVER_assume((sec_r001323_1_1 >= 0) && (sec_r001323_1_1 <= 255));
  __CPROVER_assume((sec_r001323_1_2 >= 0) && (sec_r001323_1_2 <= 255));
  __CPROVER_assume((sec_r001323_2_1 >= 0) && (sec_r001323_2_1 <= 255));
  __CPROVER_assume((sec_r001323_2_2 >= 0) && (sec_r001323_2_2 <= 255));
  __CPROVER_assume((sec_r001323_3_1 >= 0) && (sec_r001323_3_1 <= 255));
  __CPROVER_assume((sec_r001323_3_2 >= 0) && (sec_r001323_3_2 <= 255));
  __CPROVER_assume((sec_r001323_4_1 >= 0) && (sec_r001323_4_1 <= 255));
  __CPROVER_assume((sec_r001323_4_2 >= 0) && (sec_r001323_4_2 <= 255));
  __CPROVER_assume((sec_r001323_5_1 >= 0) && (sec_r001323_5_1 <= 255));
  __CPROVER_assume((sec_r001323_5_2 >= 0) && (sec_r001323_5_2 <= 255));
  __CPROVER_assume((sec_r001323_6_1 >= 0) && (sec_r001323_6_1 <= 255));
  __CPROVER_assume((sec_r001323_6_2 >= 0) && (sec_r001323_6_2 <= 255));
  __CPROVER_assume((sec_r001323_7_1 >= 0) && (sec_r001323_7_1 <= 255));
  __CPROVER_assume((sec_r001323_7_2 >= 0) && (sec_r001323_7_2 <= 255));
  __CPROVER_assume((sec_r001323_8_1 >= 0) && (sec_r001323_8_1 <= 255));
  __CPROVER_assume((sec_r001323_8_2 >= 0) && (sec_r001323_8_2 <= 255));
  __CPROVER_assume((sec_r001323_9_1 >= 0) && (sec_r001323_9_1 <= 255));
  __CPROVER_assume((sec_r001323_9_2 >= 0) && (sec_r001323_9_2 <= 255));
  __CPROVER_assume((sec_r001323_10_1 >= 0) && (sec_r001323_10_1 <= 255));
  __CPROVER_assume((sec_r001323_10_2 >= 0) && (sec_r001323_10_2 <= 255));
  __CPROVER_assume((sec_r001323_11_1 >= 0) && (sec_r001323_11_1 <= 255));
  __CPROVER_assume((sec_r001323_11_2 >= 0) && (sec_r001323_11_2 <= 255));
  __CPROVER_assume((sec_r001323_12_1 >= 0) && (sec_r001323_12_1 <= 255));
  __CPROVER_assume((sec_r001323_12_2 >= 0) && (sec_r001323_12_2 <= 255));
  __CPROVER_assume((sec_r001323_13_1 >= 0) && (sec_r001323_13_1 <= 255));
  __CPROVER_assume((sec_r001323_13_2 >= 0) && (sec_r001323_13_2 <= 255));
  __CPROVER_assume((sec_r001323_14_1 >= 0) && (sec_r001323_14_1 <= 255));
  __CPROVER_assume((sec_r001323_14_2 >= 0) && (sec_r001323_14_2 <= 255));
  __CPROVER_assume((sec_r001323_15_1 >= 0) && (sec_r001323_15_1 <= 255));
  __CPROVER_assume((sec_r001323_15_2 >= 0) && (sec_r001323_15_2 <= 255));
  __CPROVER_assume((sec_r001323_16_1 >= 0) && (sec_r001323_16_1 <= 255));
  __CPROVER_assume((sec_r001323_16_2 >= 0) && (sec_r001323_16_2 <= 255));
  __CPROVER_assume((sec_r001323_17_1 >= 0) && (sec_r001323_17_1 <= 255));
  __CPROVER_assume((sec_r001323_17_2 >= 0) && (sec_r001323_17_2 <= 255));
  __CPROVER_assume((sec_r001323_18_1 >= 0) && (sec_r001323_18_1 <= 255));
  __CPROVER_assume((sec_r001323_18_2 >= 0) && (sec_r001323_18_2 <= 255));
  __CPROVER_assume((sec_r001323_19_1 >= 0) && (sec_r001323_19_1 <= 255));
  __CPROVER_assume((sec_r001323_19_2 >= 0) && (sec_r001323_19_2 <= 255));
  __CPROVER_assume((sec_r001323_20_1 >= 0) && (sec_r001323_20_1 <= 255));
  __CPROVER_assume((sec_r001323_20_2 >= 0) && (sec_r001323_20_2 <= 255));
  struct MatrixBlock_R001323_2313_0 st_var_0_1 = {0};
  struct MatrixBlock_R001323_2313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001323_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001323_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001323_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001323_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001323_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001323_0_2 + 7) & 15;
  struct Vector3D_R001323_2313_1 st_var_1_1 = {0};
  struct Vector3D_R001323_2313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001323_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001323_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001323_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001323_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001323_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001323_0_2 + 9) & 15;
  struct SensorNode_R001323_2313_2 st_var_2_1 = {0};
  struct SensorNode_R001323_2313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001323_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001323_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001323_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001323_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001323_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001323_0_2 + 11) & 15;
  union RegisterBank_R001323_2313_0 u_var_1;
  union RegisterBank_R001323_2313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001323_2313_0(sec_r001323_0_1, sec_r001323_1_1, pub_r001323_2_1);
  int helper_flow_0_2 = fn_R001323_2313_0(sec_r001323_0_2, sec_r001323_1_2, pub_r001323_2_2);
  fn_R001323_2313_0_2(sec_r001323_0_1, sec_r001323_1_1, pub_r001323_2_1, sec_r001323_0_2, sec_r001323_1_2, pub_r001323_2_2);
  int helper_flow_1_1 = fn_R001323_2313_1(sec_r001323_1_1, sec_r001323_2_1, pub_r001323_3_1, pub_r001323_4_1);
  int helper_flow_1_2 = fn_R001323_2313_1(sec_r001323_1_2, sec_r001323_2_2, pub_r001323_3_2, pub_r001323_4_2);
  fn_R001323_2313_1_2(sec_r001323_1_1, sec_r001323_2_1, pub_r001323_3_1, pub_r001323_4_1, sec_r001323_1_2, sec_r001323_2_2, pub_r001323_3_2, pub_r001323_4_2);
  int helper_flow_2_1 = fn_R001323_2313_2(sec_r001323_2_1, pub_r001323_3_1);
  int helper_flow_2_2 = fn_R001323_2313_2(sec_r001323_2_2, pub_r001323_3_2);
  fn_R001323_2313_2_2(sec_r001323_2_1, pub_r001323_3_1, sec_r001323_2_2, pub_r001323_3_2);
  int helper_flow_3_1 = fn_R001323_2313_3(sec_r001323_3_1, pub_r001323_4_1, pub_r001323_5_1, pub_r001323_6_1);
  int helper_flow_3_2 = fn_R001323_2313_3(sec_r001323_3_2, pub_r001323_4_2, pub_r001323_5_2, pub_r001323_6_2);
  fn_R001323_2313_3_2(sec_r001323_3_1, pub_r001323_4_1, pub_r001323_5_1, pub_r001323_6_1, sec_r001323_3_2, pub_r001323_4_2, pub_r001323_5_2, pub_r001323_6_2);
  int helper_flow_4_1 = fn_R001323_2313_4(sec_r001323_4_1, pub_r001323_5_1);
  int helper_flow_4_2 = fn_R001323_2313_4(sec_r001323_4_2, pub_r001323_5_2);
  fn_R001323_2313_4_2(sec_r001323_4_1, pub_r001323_5_1, sec_r001323_4_2, pub_r001323_5_2);
  int helper_flow_5_1 = fn_R001323_2313_5(sec_r001323_5_1, pub_r001323_6_1, pub_r001323_7_1);
  int helper_flow_5_2 = fn_R001323_2313_5(sec_r001323_5_2, pub_r001323_6_2, pub_r001323_7_2);
  fn_R001323_2313_5_2(sec_r001323_5_1, pub_r001323_6_1, pub_r001323_7_1, sec_r001323_5_2, pub_r001323_6_2, pub_r001323_7_2);
  int stage_v_0_1 = (((sec_r001323_16_1 * 3) + pub_r001323_9_1) + 40) & 127;
  int stage_v_0_2 = (((sec_r001323_16_2 * 3) + pub_r001323_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001323_8_1 * 3) + pub_r001323_10_1) + 32) & 127;
  int stage_v_1_2 = (((sec_r001323_8_2 * 3) + pub_r001323_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001323_14_1 * 2) + 49) & 63;
  int stage_v_2_2 = ((pub_r001323_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001323_8_1 * 2) + 34) & 63;
  int stage_v_3_2 = ((pub_r001323_8_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001323_5_1 * 2) + 41) & 63;
  int stage_v_4_2 = ((pub_r001323_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001323_7_1 * 3) + pub_r001323_6_1) + 16) & 127;
  int stage_v_5_2 = (((sec_r001323_7_2 * 3) + pub_r001323_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = (((stage_v_1_1 * 3) + pub_r001323_2_1) + 3) & 127;
  int stage_v_6_2 = (((stage_v_1_2 * 3) + pub_r001323_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((helper_flow_5_1 * 3) + pub_r001323_8_1) + 41) & 127;
  int stage_v_7_2 = (((helper_flow_5_2 * 3) + pub_r001323_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001323_12_1 * 2) + 40) & 63;
  int stage_v_8_2 = ((pub_r001323_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001323_1_1 * 2) + 19) & 63;
  int stage_v_9_2 = ((pub_r001323_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001323_3_1 * 3) + pub_r001323_0_1) + 4) & 127;
  int stage_v_10_2 = (((sec_r001323_3_2 * 3) + pub_r001323_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001323_8_1 * 3) + pub_r001323_9_1) + 14) & 127;
  int stage_v_11_2 = (((sec_r001323_8_2 * 3) + pub_r001323_9_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((helper_flow_1_1 * 3) + pub_r001323_10_1) + 11) & 127;
  int stage_v_12_2 = (((helper_flow_1_2 * 3) + pub_r001323_10_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_5_1 * 3) + pub_r001323_1_1) + 41) & 127;
  int stage_v_13_2 = (((stage_v_5_2 * 3) + pub_r001323_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((sec_r001323_8_1 * 3) + pub_r001323_14_1) + 6) & 127;
  int stage_v_14_2 = (((sec_r001323_8_2 * 3) + pub_r001323_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001323_1_1 * 3) + pub_r001323_12_1) + 8) & 127;
  int stage_v_15_2 = (((sec_r001323_1_2 * 3) + pub_r001323_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((stage_v_14_1 * 3) + pub_r001323_0_1) + 37) & 127;
  int stage_v_16_2 = (((stage_v_14_2 * 3) + pub_r001323_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001323_14_1 * 2) + 14) & 63;
  int stage_v_17_2 = ((pub_r001323_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = ((pub_r001323_10_1 * 2) + 25) & 63;
  int stage_v_18_2 = ((pub_r001323_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (((sec_r001323_16_1 * 3) + pub_r001323_5_1) + 44) & 127;
  int stage_v_19_2 = (((sec_r001323_16_2 * 3) + pub_r001323_5_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = (((stage_v_1_1 * 3) + pub_r001323_6_1) + 34) & 127;
  int stage_v_20_2 = (((stage_v_1_2 * 3) + pub_r001323_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001323_12_1 * 2) + 37) & 63;
  int stage_v_21_2 = ((pub_r001323_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001323_3_1 * 2) + 7) & 63;
  int stage_v_22_2 = ((pub_r001323_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_7_1 * 3) + pub_r001323_4_1) + 40) & 127;
  int stage_v_23_2 = (((stage_v_7_2 * 3) + pub_r001323_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((helper_flow_3_1 * 3) + pub_r001323_3_1) + 23) & 127;
  int stage_v_24_2 = (((helper_flow_3_2 * 3) + pub_r001323_3_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = (((sec_r001323_18_1 * 3) + pub_r001323_15_1) + 16) & 127;
  int stage_v_25_2 = (((sec_r001323_18_2 * 3) + pub_r001323_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((sec_r001323_20_1 * 3) + pub_r001323_7_1) + 31) & 127;
  int stage_v_26_2 = (((sec_r001323_20_2 * 3) + pub_r001323_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((helper_flow_5_1 * 3) + pub_r001323_11_1) + 32) & 127;
  int stage_v_27_2 = (((helper_flow_5_2 * 3) + pub_r001323_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001323_1_1 * 2) + 26) & 63;
  int stage_v_28_2 = ((pub_r001323_1_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((stage_v_10_1 * 3) + pub_r001323_14_1) + 22) & 127;
  int stage_v_29_2 = (((stage_v_10_2 * 3) + pub_r001323_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((sec_r001323_12_1 * 3) + pub_r001323_8_1) + 40) & 127;
  int stage_v_30_2 = (((sec_r001323_12_2 * 3) + pub_r001323_8_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((sec_r001323_9_1 * 3) + pub_r001323_0_1) + 40) & 127;
  int stage_v_31_2 = (((sec_r001323_9_2 * 3) + pub_r001323_0_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001323_6_1 * 2) + 25) & 63;
  int stage_v_32_2 = ((pub_r001323_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001323_15_1 * 2) + 6) & 63;
  int stage_v_33_2 = ((pub_r001323_15_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((sec_r001323_4_1 * 3) + pub_r001323_13_1) + 40) & 127;
  int stage_v_34_2 = (((sec_r001323_4_2 * 3) + pub_r001323_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = (((sec_r001323_13_1 * 3) + pub_r001323_3_1) + 11) & 127;
  int stage_v_35_2 = (((sec_r001323_13_2 * 3) + pub_r001323_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_35_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_35_2 * 2)) & 255;
  int stage_v_36_1 = (((sec_r001323_10_1 * 3) + pub_r001323_5_1) + 6) & 127;
  int stage_v_36_2 = (((sec_r001323_10_2 * 3) + pub_r001323_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001323_2_1 * 2) + 31) & 63;
  int stage_v_37_2 = ((pub_r001323_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = (((stage_v_16_1 * 3) + pub_r001323_11_1) + 3) & 127;
  int stage_v_38_2 = (((stage_v_16_2 * 3) + pub_r001323_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_38_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_38_2 * 2)) & 255;
  int stage_v_39_1 = ((pub_r001323_8_1 * 2) + 12) & 63;
  int stage_v_39_2 = ((pub_r001323_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001323_0_1 * 2) + 17) & 63;
  int stage_v_40_2 = ((pub_r001323_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001323_10_1 * 2) + 23) & 63;
  int stage_v_41_2 = ((pub_r001323_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((stage_v_7_1 * 3) + pub_r001323_1_1) + 17) & 127;
  int stage_v_42_2 = (((stage_v_7_2 * 3) + pub_r001323_1_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001323_2_1 * 2) + 24) & 63;
  int stage_v_43_2 = ((pub_r001323_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((stage_v_24_1 * 3) + pub_r001323_11_1) + 25) & 127;
  int stage_v_44_2 = (((stage_v_24_2 * 3) + pub_r001323_11_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = ((pub_r001323_9_1 * 2) + 22) & 63;
  int stage_v_45_2 = ((pub_r001323_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((sec_r001323_14_1 * 3) + pub_r001323_11_1) + 19) & 127;
  int stage_v_46_2 = (((sec_r001323_14_2 * 3) + pub_r001323_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001323_12_1 * 2) + 26) & 63;
  int stage_v_47_2 = ((pub_r001323_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((sec_r001323_4_1 * 3) + pub_r001323_8_1) + 20) & 127;
  int stage_v_48_2 = (((sec_r001323_4_2 * 3) + pub_r001323_8_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_1_1 * 3) + pub_r001323_10_1) + 24) & 127;
  int stage_v_49_2 = (((stage_v_1_2 * 3) + pub_r001323_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = (((stage_v_29_1 * 3) + pub_r001323_14_1) + 22) & 127;
  int stage_v_50_2 = (((stage_v_29_2 * 3) + pub_r001323_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_11_1 * 3) + pub_r001323_7_1) + 20) & 127;
  int stage_v_51_2 = (((stage_v_11_2 * 3) + pub_r001323_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = (((stage_v_31_1 * 3) + pub_r001323_3_1) + 7) & 127;
  int stage_v_52_2 = (((stage_v_31_2 * 3) + pub_r001323_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001323_13_1 * 2) + 22) & 63;
  int stage_v_53_2 = ((pub_r001323_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((sec_r001323_15_1 * 3) + pub_r001323_10_1) + 28) & 127;
  int stage_v_54_2 = (((sec_r001323_15_2 * 3) + pub_r001323_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001323_14_1 * 2) + 36) & 63;
  int stage_v_55_2 = ((pub_r001323_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001323_1_1 * 2) + 9) & 63;
  int stage_v_56_2 = ((pub_r001323_1_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001323_14_1 * 2) + 18) & 63;
  int stage_v_57_2 = ((pub_r001323_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001323_11_1 * 2) + 40) & 63;
  int stage_v_58_2 = ((pub_r001323_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001323_3_1 * 2) + 35) & 63;
  int stage_v_59_2 = ((pub_r001323_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_23_1 * 3) + pub_r001323_4_1) + 23) & 127;
  int stage_v_60_2 = (((stage_v_23_2 * 3) + pub_r001323_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_6_1 * 3) + pub_r001323_2_1) + 30) & 127;
  int stage_v_61_2 = (((stage_v_6_2 * 3) + pub_r001323_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = (((stage_v_6_1 * 3) + pub_r001323_14_1) + 29) & 127;
  int stage_v_62_2 = (((stage_v_6_2 * 3) + pub_r001323_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_62_1 * 3) + pub_r001323_2_1) + 11) & 127;
  int stage_v_63_2 = (((stage_v_62_2 * 3) + pub_r001323_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_48_1 * 3) + pub_r001323_4_1) + 27) & 127;
  int stage_v_64_2 = (((stage_v_48_2 * 3) + pub_r001323_4_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001323_8_1 * 2) + 27) & 63;
  int stage_v_65_2 = ((pub_r001323_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001323_7_1 * 2) + 17) & 63;
  int stage_v_66_2 = ((pub_r001323_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001323_2_1 * 2) + 6) & 63;
  int stage_v_67_2 = ((pub_r001323_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001323_4_1 * 2) + 37) & 63;
  int stage_v_68_2 = ((pub_r001323_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (((stage_v_26_1 * 3) + pub_r001323_13_1) + 45) & 127;
  int stage_v_69_2 = (((stage_v_26_2 * 3) + pub_r001323_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = ((pub_r001323_0_1 * 2) + 50) & 63;
  int stage_v_70_2 = ((pub_r001323_0_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (((sec_r001323_14_1 * 3) + pub_r001323_13_1) + 43) & 127;
  int stage_v_71_2 = (((sec_r001323_14_2 * 3) + pub_r001323_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001323_1_1 * 2) + 40) & 63;
  int stage_v_72_2 = ((pub_r001323_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_64_1 * 3) + pub_r001323_4_1) + 43) & 127;
  int stage_v_73_2 = (((stage_v_64_2 * 3) + pub_r001323_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = (((sec_r001323_5_1 * 3) + pub_r001323_1_1) + 10) & 127;
  int stage_v_74_2 = (((sec_r001323_5_2 * 3) + pub_r001323_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((sec_r001323_12_1 * 3) + pub_r001323_15_1) + 43) & 127;
  int stage_v_75_2 = (((sec_r001323_12_2 * 3) + pub_r001323_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001323_11_1 * 2) + 46) & 63;
  int stage_v_76_2 = ((pub_r001323_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = (((stage_v_64_1 * 3) + pub_r001323_9_1) + 42) & 127;
  int stage_v_77_2 = (((stage_v_64_2 * 3) + pub_r001323_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_77_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_77_2 * 2)) & 255;
  int stage_v_78_1 = ((pub_r001323_4_1 * 2) + 13) & 63;
  int stage_v_78_2 = ((pub_r001323_4_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = (((stage_v_50_1 * 3) + pub_r001323_6_1) + 20) & 127;
  int stage_v_79_2 = (((stage_v_50_2 * 3) + pub_r001323_6_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001323_4_1 * 2) + 28) & 63;
  int stage_v_80_2 = ((pub_r001323_4_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001323_15_1 * 3) + pub_r001323_12_1) + 11) & 127;
  int stage_v_81_2 = (((sec_r001323_15_2 * 3) + pub_r001323_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_29_1 * 3) + pub_r001323_8_1) + 12) & 127;
  int stage_v_82_2 = (((stage_v_29_2 * 3) + pub_r001323_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((sec_r001323_8_1 * 3) + pub_r001323_8_1) + 23) & 127;
  int stage_v_83_2 = (((sec_r001323_8_2 * 3) + pub_r001323_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001323_14_1 * 2) + 28) & 63;
  int stage_v_84_2 = ((pub_r001323_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001323_13_1 * 2) + 40) & 63;
  int stage_v_85_2 = ((pub_r001323_13_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_71_1 * 3) + pub_r001323_8_1) + 4) & 127;
  int stage_v_86_2 = (((stage_v_71_2 * 3) + pub_r001323_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = (((sec_r001323_11_1 * 3) + pub_r001323_9_1) + 39) & 127;
  int stage_v_87_2 = (((sec_r001323_11_2 * 3) + pub_r001323_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_34_1 * 3) + pub_r001323_2_1) + 21) & 127;
  int stage_v_88_2 = (((stage_v_34_2 * 3) + pub_r001323_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((sec_r001323_7_1 * 3) + pub_r001323_12_1) + 30) & 127;
  int stage_v_89_2 = (((sec_r001323_7_2 * 3) + pub_r001323_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = (((stage_v_13_1 * 3) + pub_r001323_0_1) + 11) & 127;
  int stage_v_90_2 = (((stage_v_13_2 * 3) + pub_r001323_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = (((helper_flow_1_1 * 3) + pub_r001323_7_1) + 9) & 127;
  int stage_v_91_2 = (((helper_flow_1_2 * 3) + pub_r001323_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = (((stage_v_24_1 * 3) + pub_r001323_12_1) + 27) & 127;
  int stage_v_92_2 = (((stage_v_24_2 * 3) + pub_r001323_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((stage_v_77_1 * 3) + pub_r001323_5_1) + 6) & 127;
  int stage_v_93_2 = (((stage_v_77_2 * 3) + pub_r001323_5_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001323_0_1 * 2) + 31) & 63;
  int stage_v_94_2 = ((pub_r001323_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((stage_v_38_1 * 3) + pub_r001323_3_1) + 16) & 127;
  int stage_v_95_2 = (((stage_v_38_2 * 3) + pub_r001323_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001323_10_1 * 2) + 41) & 63;
  int stage_v_96_2 = ((pub_r001323_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((sec_r001323_7_1 * 3) + pub_r001323_9_1) + 7) & 127;
  int stage_v_97_2 = (((sec_r001323_7_2 * 3) + pub_r001323_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_75_1 * 3) + pub_r001323_12_1) + 32) & 127;
  int stage_v_98_2 = (((stage_v_75_2 * 3) + pub_r001323_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = ((pub_r001323_1_1 * 2) + 27) & 63;
  int stage_v_99_2 = ((pub_r001323_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001323_7_1 * 2) + 27) & 63;
  int stage_v_100_2 = ((pub_r001323_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_10_1 * 3) + pub_r001323_11_1) + 20) & 127;
  int stage_v_101_2 = (((stage_v_10_2 * 3) + pub_r001323_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((sec_r001323_10_1 * 3) + pub_r001323_8_1) + 39) & 127;
  int stage_v_102_2 = (((sec_r001323_10_2 * 3) + pub_r001323_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_93_1 * 3) + pub_r001323_0_1) + 44) & 127;
  int stage_v_103_2 = (((stage_v_93_2 * 3) + pub_r001323_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = (((stage_v_35_1 * 3) + pub_r001323_14_1) + 35) & 127;
  int stage_v_104_2 = (((stage_v_35_2 * 3) + pub_r001323_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001323_1_1 * 2) + 10) & 63;
  int stage_v_105_2 = ((pub_r001323_1_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001323_14_1 * 2) + 10) & 63;
  int stage_v_106_2 = ((pub_r001323_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001323_6_1 * 2) + 43) & 63;
  int stage_v_107_2 = ((pub_r001323_6_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001323_0_1 * 2) + 26) & 63;
  int stage_v_108_2 = ((pub_r001323_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((stage_v_75_1 * 3) + pub_r001323_8_1) + 35) & 127;
  int stage_v_109_2 = (((stage_v_75_2 * 3) + pub_r001323_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((sec_r001323_3_1 * 3) + pub_r001323_5_1) + 11) & 127;
  int stage_v_110_2 = (((sec_r001323_3_2 * 3) + pub_r001323_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_38_1 * 3) + pub_r001323_5_1) + 34) & 127;
  int stage_v_111_2 = (((stage_v_38_2 * 3) + pub_r001323_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = (((stage_v_89_1 * 3) + pub_r001323_14_1) + 31) & 127;
  int stage_v_112_2 = (((stage_v_89_2 * 3) + pub_r001323_14_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_82_1 * 3) + pub_r001323_15_1) + 42) & 127;
  int stage_v_113_2 = (((stage_v_82_2 * 3) + pub_r001323_15_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001323_13_1 * 2) + 37) & 63;
  int stage_v_114_2 = ((pub_r001323_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001323_9_1 * 2) + 16) & 63;
  int stage_v_115_2 = ((pub_r001323_9_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001323_11_1 * 2) + 10) & 63;
  int stage_v_116_2 = ((pub_r001323_11_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001323_11_1 * 2) + 46) & 63;
  int stage_v_117_2 = ((pub_r001323_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = (((sec_r001323_12_1 * 3) + pub_r001323_6_1) + 37) & 127;
  int stage_v_118_2 = (((sec_r001323_12_2 * 3) + pub_r001323_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = (((stage_v_110_1 * 3) + pub_r001323_11_1) + 3) & 127;
  int stage_v_119_2 = (((stage_v_110_2 * 3) + pub_r001323_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001323_8_1 * 3) + pub_r001323_9_1) + 12) & 127;
  int stage_v_120_2 = (((sec_r001323_8_2 * 3) + pub_r001323_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((helper_flow_5_1 * 3) + pub_r001323_15_1) + 34) & 127;
  int stage_v_121_2 = (((helper_flow_5_2 * 3) + pub_r001323_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = (((stage_v_5_1 * 3) + pub_r001323_7_1) + 44) & 127;
  int stage_v_122_2 = (((stage_v_5_2 * 3) + pub_r001323_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_111_1 * 3) + pub_r001323_12_1) + 39) & 127;
  int stage_v_123_2 = (((stage_v_111_2 * 3) + pub_r001323_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_30_1 * 3) + pub_r001323_13_1) + 29) & 127;
  int stage_v_124_2 = (((stage_v_30_2 * 3) + pub_r001323_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = (((stage_v_122_1 * 3) + pub_r001323_8_1) + 27) & 127;
  int stage_v_125_2 = (((stage_v_122_2 * 3) + pub_r001323_8_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = ((pub_r001323_7_1 * 2) + 8) & 63;
  int stage_v_126_2 = ((pub_r001323_7_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001323_1_1 * 2) + 25) & 63;
  int stage_v_127_2 = ((pub_r001323_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001323_8_1 * 2) + 31) & 63;
  int stage_v_128_2 = ((pub_r001323_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_71_1 * 3) + pub_r001323_3_1) + 33) & 127;
  int stage_v_129_2 = (((stage_v_71_2 * 3) + pub_r001323_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = ((pub_r001323_13_1 * 2) + 29) & 63;
  int stage_v_130_2 = ((pub_r001323_13_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = (((stage_v_27_1 * 3) + pub_r001323_14_1) + 14) & 127;
  int stage_v_131_2 = (((stage_v_27_2 * 3) + pub_r001323_14_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001323_6_1 * 2) + 8) & 63;
  int stage_v_132_2 = ((pub_r001323_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_95_1 * 3) + pub_r001323_1_1) + 42) & 127;
  int stage_v_133_2 = (((stage_v_95_2 * 3) + pub_r001323_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_44_1 * 3) + pub_r001323_7_1) + 4) & 127;
  int stage_v_134_2 = (((stage_v_44_2 * 3) + pub_r001323_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = ((pub_r001323_3_1 * 2) + 32) & 63;
  int stage_v_135_2 = ((pub_r001323_3_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (((stage_v_20_1 * 3) + pub_r001323_9_1) + 3) & 127;
  int stage_v_136_2 = (((stage_v_20_2 * 3) + pub_r001323_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_51_1 * 3) + pub_r001323_15_1) + 41) & 127;
  int stage_v_137_2 = (((stage_v_51_2 * 3) + pub_r001323_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_113_1 * 3) + pub_r001323_4_1) + 14) & 127;
  int stage_v_138_2 = (((stage_v_113_2 * 3) + pub_r001323_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001323_11_1 * 2) + 34) & 63;
  int stage_v_139_2 = ((pub_r001323_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((sec_r001323_8_1 * 3) + pub_r001323_9_1) + 38) & 127;
  int stage_v_140_2 = (((sec_r001323_8_2 * 3) + pub_r001323_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001323_14_1 * 2) + 38) & 63;
  int stage_v_141_2 = ((pub_r001323_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001323_5_1 * 2) + 13) & 63;
  int stage_v_142_2 = ((pub_r001323_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = ((pub_r001323_12_1 * 2) + 41) & 63;
  int stage_v_143_2 = ((pub_r001323_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_86_1 * 3) + pub_r001323_10_1) + 16) & 127;
  int stage_v_144_2 = (((stage_v_86_2 * 3) + pub_r001323_10_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_64_1 * 3) + pub_r001323_3_1) + 43) & 127;
  int stage_v_145_2 = (((stage_v_64_2 * 3) + pub_r001323_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001323_4_1 * 2) + 6) & 63;
  int stage_v_146_2 = ((pub_r001323_4_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001323_0_1 * 2) + 11) & 63;
  int stage_v_147_2 = ((pub_r001323_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001323_4_1 * 2) + 41) & 63;
  int stage_v_148_2 = ((pub_r001323_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = (((stage_v_129_1 * 3) + pub_r001323_12_1) + 17) & 127;
  int stage_v_149_2 = (((stage_v_129_2 * 3) + pub_r001323_12_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = (((stage_v_90_1 * 3) + pub_r001323_9_1) + 10) & 127;
  int stage_v_150_2 = (((stage_v_90_2 * 3) + pub_r001323_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001323_11_1 * 2) + 29) & 63;
  int stage_v_151_2 = ((pub_r001323_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001323_13_1 * 2) + 43) & 63;
  int stage_v_152_2 = ((pub_r001323_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((pub_r001323_9_1 * 2) + 8) & 63;
  int stage_v_153_2 = ((pub_r001323_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001323_15_1 * 2) + 32) & 63;
  int stage_v_154_2 = ((pub_r001323_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001323_4_1 * 2) + 49) & 63;
  int stage_v_155_2 = ((pub_r001323_4_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001323_3_1 * 2) + 29) & 63;
  int stage_v_156_2 = ((pub_r001323_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((stage_v_71_1 * 3) + pub_r001323_13_1) + 29) & 127;
  int stage_v_157_2 = (((stage_v_71_2 * 3) + pub_r001323_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_71_1 * 3) + pub_r001323_1_1) + 21) & 127;
  int stage_v_158_2 = (((stage_v_71_2 * 3) + pub_r001323_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_42_1 * 3) + pub_r001323_13_1) + 25) & 127;
  int stage_v_159_2 = (((stage_v_42_2 * 3) + pub_r001323_13_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_24_1 * 3) + pub_r001323_2_1) + 27) & 127;
  int stage_v_160_2 = (((stage_v_24_2 * 3) + pub_r001323_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001323_7_1 * 2) + 49) & 63;
  int stage_v_161_2 = ((pub_r001323_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((sec_r001323_8_1 * 3) + pub_r001323_7_1) + 32) & 127;
  int stage_v_162_2 = (((sec_r001323_8_2 * 3) + pub_r001323_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = ((pub_r001323_2_1 * 2) + 18) & 63;
  int stage_v_163_2 = ((pub_r001323_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001323_12_1 * 2) + 32) & 63;
  int stage_v_164_2 = ((pub_r001323_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((stage_v_60_1 * 3) + pub_r001323_2_1) + 39) & 127;
  int stage_v_165_2 = (((stage_v_60_2 * 3) + pub_r001323_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_6_1 * 3) + pub_r001323_8_1) + 6) & 127;
  int stage_v_166_2 = (((stage_v_6_2 * 3) + pub_r001323_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_88_1 * 3) + pub_r001323_14_1) + 15) & 127;
  int stage_v_167_2 = (((stage_v_88_2 * 3) + pub_r001323_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_54_1 * 3) + pub_r001323_4_1) + 22) & 127;
  int stage_v_168_2 = (((stage_v_54_2 * 3) + pub_r001323_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = ((pub_r001323_8_1 * 2) + 48) & 63;
  int stage_v_169_2 = ((pub_r001323_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001323_8_1 * 2) + 18) & 63;
  int stage_v_170_2 = ((pub_r001323_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_23_1 * 3) + pub_r001323_9_1) + 34) & 127;
  int stage_v_171_2 = (((stage_v_23_2 * 3) + pub_r001323_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((sec_r001323_11_1 * 3) + pub_r001323_6_1) + 40) & 127;
  int stage_v_172_2 = (((sec_r001323_11_2 * 3) + pub_r001323_6_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001323_1_1 * 2) + 30) & 63;
  int stage_v_173_2 = ((pub_r001323_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001323_5_1 * 2) + 27) & 63;
  int stage_v_174_2 = ((pub_r001323_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((sec_r001323_20_1 * 3) + pub_r001323_11_1) + 8) & 127;
  int stage_v_175_2 = (((sec_r001323_20_2 * 3) + pub_r001323_11_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_36_1 * 3) + pub_r001323_13_1) + 42) & 127;
  int stage_v_176_2 = (((stage_v_36_2 * 3) + pub_r001323_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = ((pub_r001323_6_1 * 2) + 28) & 63;
  int stage_v_177_2 = ((pub_r001323_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001323_6_1 * 2) + 13) & 63;
  int stage_v_178_2 = ((pub_r001323_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001323_5_1 * 2) + 31) & 63;
  int stage_v_179_2 = ((pub_r001323_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001323_11_1 * 2) + 31) & 63;
  int stage_v_180_2 = ((pub_r001323_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((stage_v_75_1 * 3) + pub_r001323_10_1) + 41) & 127;
  int stage_v_181_2 = (((stage_v_75_2 * 3) + pub_r001323_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001323_8_1 * 2) + 24) & 63;
  int stage_v_182_2 = ((pub_r001323_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_82_1 * 3) + pub_r001323_7_1) + 22) & 127;
  int stage_v_183_2 = (((stage_v_82_2 * 3) + pub_r001323_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_86_1 * 3) + pub_r001323_4_1) + 7) & 127;
  int stage_v_184_2 = (((stage_v_86_2 * 3) + pub_r001323_4_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_24_1 * 3) + pub_r001323_1_1) + 43) & 127;
  int stage_v_185_2 = (((stage_v_24_2 * 3) + pub_r001323_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_185_1 * 3) + pub_r001323_4_1) + 28) & 127;
  int stage_v_186_2 = (((stage_v_185_2 * 3) + pub_r001323_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001323_11_1 * 2) + 8) & 63;
  int stage_v_187_2 = ((pub_r001323_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001323_8_1 * 2) + 40) & 63;
  int stage_v_188_2 = ((pub_r001323_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((stage_v_119_1 * 3) + pub_r001323_9_1) + 18) & 127;
  int stage_v_189_2 = (((stage_v_119_2 * 3) + pub_r001323_9_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_183_1 * 3) + pub_r001323_1_1) + 21) & 127;
  int stage_v_190_2 = (((stage_v_183_2 * 3) + pub_r001323_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_79_1 * 3) + pub_r001323_13_1) + 42) & 127;
  int stage_v_191_2 = (((stage_v_79_2 * 3) + pub_r001323_13_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001323_6_1 * 2) + 15) & 63;
  int stage_v_192_2 = ((pub_r001323_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_6_1 * 3) + pub_r001323_5_1) + 22) & 127;
  int stage_v_193_2 = (((stage_v_6_2 * 3) + pub_r001323_5_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001323_4_1 * 2) + 26) & 63;
  int stage_v_194_2 = ((pub_r001323_4_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_71_1 * 3) + pub_r001323_2_1) + 28) & 127;
  int stage_v_195_2 = (((stage_v_71_2 * 3) + pub_r001323_2_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((stage_v_73_1 * 3) + pub_r001323_7_1) + 17) & 127;
  int stage_v_196_2 = (((stage_v_73_2 * 3) + pub_r001323_7_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((stage_v_64_1 * 3) + pub_r001323_0_1) + 19) & 127;
  int stage_v_197_2 = (((stage_v_64_2 * 3) + pub_r001323_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = (((stage_v_7_1 * 3) + pub_r001323_12_1) + 3) & 127;
  int stage_v_198_2 = (((stage_v_7_2 * 3) + pub_r001323_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = (((stage_v_63_1 * 3) + pub_r001323_3_1) + 29) & 127;
  int stage_v_199_2 = (((stage_v_63_2 * 3) + pub_r001323_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001323_14_1 * 2) + 45) & 63;
  int stage_v_200_2 = ((pub_r001323_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001323_11_1 * 2) + 39) & 63;
  int stage_v_201_2 = ((pub_r001323_11_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = ((pub_r001323_5_1 * 2) + 26) & 63;
  int stage_v_202_2 = ((pub_r001323_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001323_0_1 * 2) + 45) & 63;
  int stage_v_203_2 = ((pub_r001323_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001323_0_1 * 2) + 14) & 63;
  int stage_v_204_2 = ((pub_r001323_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = (((stage_v_79_1 * 3) + pub_r001323_14_1) + 33) & 127;
  int stage_v_205_2 = (((stage_v_79_2 * 3) + pub_r001323_14_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001323_7_1 * 2) + 14) & 63;
  int stage_v_206_2 = ((pub_r001323_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = (((stage_v_134_1 * 3) + pub_r001323_3_1) + 36) & 127;
  int stage_v_207_2 = (((stage_v_134_2 * 3) + pub_r001323_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = (((stage_v_82_1 * 3) + pub_r001323_1_1) + 30) & 127;
  int stage_v_208_2 = (((stage_v_82_2 * 3) + pub_r001323_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_208_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_208_2 * 2)) & 255;
  int stage_v_209_1 = (((stage_v_24_1 * 3) + pub_r001323_4_1) + 14) & 127;
  int stage_v_209_2 = (((stage_v_24_2 * 3) + pub_r001323_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001323_9_1 * 2) + 19) & 63;
  int stage_v_210_2 = ((pub_r001323_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = (((stage_v_20_1 * 3) + pub_r001323_2_1) + 37) & 127;
  int stage_v_211_2 = (((stage_v_20_2 * 3) + pub_r001323_2_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = (((stage_v_181_1 * 3) + pub_r001323_4_1) + 37) & 127;
  int stage_v_212_2 = (((stage_v_181_2 * 3) + pub_r001323_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_27_1 * 3) + pub_r001323_15_1) + 23) & 127;
  int stage_v_213_2 = (((stage_v_27_2 * 3) + pub_r001323_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_0_1 * 3) + pub_r001323_13_1) + 28) & 127;
  int stage_v_214_2 = (((stage_v_0_2 * 3) + pub_r001323_13_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_5_1 * 3) + pub_r001323_6_1) + 27) & 127;
  int stage_v_215_2 = (((stage_v_5_2 * 3) + pub_r001323_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_166_1 * 3) + pub_r001323_5_1) + 33) & 127;
  int stage_v_216_2 = (((stage_v_166_2 * 3) + pub_r001323_5_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((sec_r001323_17_1 * 3) + pub_r001323_9_1) + 39) & 127;
  int stage_v_217_2 = (((sec_r001323_17_2 * 3) + pub_r001323_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001323_13_1 * 2) + 24) & 63;
  int stage_v_218_2 = ((pub_r001323_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_20_1 * 3) + pub_r001323_7_1) + 40) & 127;
  int stage_v_219_2 = (((stage_v_20_2 * 3) + pub_r001323_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_145_1 * 3) + pub_r001323_5_1) + 10) & 127;
  int stage_v_220_2 = (((stage_v_145_2 * 3) + pub_r001323_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001323_15_1 * 2) + 49) & 63;
  int stage_v_221_2 = ((pub_r001323_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001323_0_1 * 2) + 6) & 63;
  int stage_v_222_2 = ((pub_r001323_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((sec_r001323_1_1 * 3) + pub_r001323_10_1) + 29) & 127;
  int stage_v_223_2 = (((sec_r001323_1_2 * 3) + pub_r001323_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = ((pub_r001323_8_1 * 2) + 39) & 63;
  int stage_v_224_2 = ((pub_r001323_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((pub_r001323_0_1 * 2) + 33) & 63;
  int stage_v_225_2 = ((pub_r001323_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_168_1 * 3) + pub_r001323_6_1) + 16) & 127;
  int stage_v_226_2 = (((stage_v_168_2 * 3) + pub_r001323_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_10_1 * 3) + pub_r001323_1_1) + 38) & 127;
  int stage_v_227_2 = (((stage_v_10_2 * 3) + pub_r001323_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001323_15_1 * 2) + 31) & 63;
  int stage_v_228_2 = ((pub_r001323_15_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_189_1 * 3) + pub_r001323_7_1) + 44) & 127;
  int stage_v_229_2 = (((stage_v_189_2 * 3) + pub_r001323_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = (((sec_r001323_17_1 * 3) + pub_r001323_3_1) + 41) & 127;
  int stage_v_230_2 = (((sec_r001323_17_2 * 3) + pub_r001323_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_230_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_230_2 * 2)) & 255;
  int stage_v_231_1 = (((stage_v_62_1 * 3) + pub_r001323_3_1) + 16) & 127;
  int stage_v_231_2 = (((stage_v_62_2 * 3) + pub_r001323_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001323_9_1 * 2) + 47) & 63;
  int stage_v_232_2 = ((pub_r001323_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_162_1 * 3) + pub_r001323_12_1) + 20) & 127;
  int stage_v_233_2 = (((stage_v_162_2 * 3) + pub_r001323_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001323_0_1 * 2) + 34) & 63;
  int stage_v_234_2 = ((pub_r001323_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = (((stage_v_46_1 * 3) + pub_r001323_6_1) + 24) & 127;
  int stage_v_235_2 = (((stage_v_46_2 * 3) + pub_r001323_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = ((pub_r001323_2_1 * 2) + 25) & 63;
  int stage_v_236_2 = ((pub_r001323_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001323_2_1 * 2) + 8) & 63;
  int stage_v_237_2 = ((pub_r001323_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = (((stage_v_79_1 * 3) + pub_r001323_5_1) + 34) & 127;
  int stage_v_238_2 = (((stage_v_79_2 * 3) + pub_r001323_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((sec_r001323_4_1 * 3) + pub_r001323_8_1) + 14) & 127;
  int stage_v_239_2 = (((sec_r001323_4_2 * 3) + pub_r001323_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_223_1 * 3) + pub_r001323_11_1) + 21) & 127;
  int stage_v_240_2 = (((stage_v_223_2 * 3) + pub_r001323_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001323_3_1 * 2) + 43) & 63;
  int stage_v_241_2 = ((pub_r001323_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = (((stage_v_103_1 * 3) + pub_r001323_3_1) + 15) & 127;
  int stage_v_242_2 = (((stage_v_103_2 * 3) + pub_r001323_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = ((pub_r001323_14_1 * 2) + 49) & 63;
  int stage_v_243_2 = ((pub_r001323_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = (((stage_v_113_1 * 3) + pub_r001323_15_1) + 15) & 127;
  int stage_v_244_2 = (((stage_v_113_2 * 3) + pub_r001323_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((sec_r001323_2_1 * 3) + pub_r001323_6_1) + 25) & 127;
  int stage_v_245_2 = (((sec_r001323_2_2 * 3) + pub_r001323_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_82_1 * 3) + pub_r001323_0_1) + 25) & 127;
  int stage_v_246_2 = (((stage_v_82_2 * 3) + pub_r001323_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((stage_v_42_1 * 3) + pub_r001323_10_1) + 12) & 127;
  int stage_v_247_2 = (((stage_v_42_2 * 3) + pub_r001323_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_87_1 * 3) + pub_r001323_2_1) + 14) & 127;
  int stage_v_248_2 = (((stage_v_87_2 * 3) + pub_r001323_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_0_1 * 3) + pub_r001323_15_1) + 23) & 127;
  int stage_v_249_2 = (((stage_v_0_2 * 3) + pub_r001323_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001323_12_1 * 2) + 27) & 63;
  int stage_v_250_2 = ((pub_r001323_12_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((sec_r001323_10_1 * 3) + pub_r001323_4_1) + 6) & 127;
  int stage_v_251_2 = (((sec_r001323_10_2 * 3) + pub_r001323_4_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((sec_r001323_4_1 * 3) + pub_r001323_12_1) + 30) & 127;
  int stage_v_252_2 = (((sec_r001323_4_2 * 3) + pub_r001323_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_245_1 * 3) + pub_r001323_9_1) + 11) & 127;
  int stage_v_253_2 = (((stage_v_245_2 * 3) + pub_r001323_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_129_1 * 3) + pub_r001323_12_1) + 37) & 127;
  int stage_v_254_2 = (((stage_v_129_2 * 3) + pub_r001323_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001323_11_1 * 2) + 37) & 63;
  int stage_v_255_2 = ((pub_r001323_11_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = (((stage_v_104_1 * 3) + pub_r001323_7_1) + 40) & 127;
  int stage_v_256_2 = (((stage_v_104_2 * 3) + pub_r001323_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = ((pub_r001323_12_1 * 2) + 40) & 63;
  int stage_v_257_2 = ((pub_r001323_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = (((stage_v_229_1 * 3) + pub_r001323_2_1) + 32) & 127;
  int stage_v_258_2 = (((stage_v_229_2 * 3) + pub_r001323_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_258_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_258_2 * 2)) & 255;
  int stage_v_259_1 = (((sec_r001323_14_1 * 3) + pub_r001323_15_1) + 11) & 127;
  int stage_v_259_2 = (((sec_r001323_14_2 * 3) + pub_r001323_15_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_205_1 * 3) + pub_r001323_15_1) + 26) & 127;
  int stage_v_260_2 = (((stage_v_205_2 * 3) + pub_r001323_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_86_1 * 3) + pub_r001323_11_1) + 28) & 127;
  int stage_v_261_2 = (((stage_v_86_2 * 3) + pub_r001323_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001323_6_1 * 2) + 12) & 63;
  int stage_v_262_2 = ((pub_r001323_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = ((pub_r001323_3_1 * 2) + 22) & 63;
  int stage_v_263_2 = ((pub_r001323_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_263_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_263_2) & 127;
  int stage_v_264_1 = (((stage_v_240_1 * 3) + pub_r001323_14_1) + 5) & 127;
  int stage_v_264_2 = (((stage_v_240_2 * 3) + pub_r001323_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001323_7_1 * 2) + 5) & 63;
  int stage_v_265_2 = ((pub_r001323_7_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001323_2_1 * 2) + 32) & 63;
  int stage_v_266_2 = ((pub_r001323_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_165_1 * 3) + pub_r001323_12_1) + 35) & 127;
  int stage_v_267_2 = (((stage_v_165_2 * 3) + pub_r001323_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_15_1 * 3) + pub_r001323_15_1) + 32) & 127;
  int stage_v_268_2 = (((stage_v_15_2 * 3) + pub_r001323_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001323_12_1 * 2) + 15) & 63;
  int stage_v_269_2 = ((pub_r001323_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001323_2_1 * 2) + 44) & 63;
  int stage_v_270_2 = ((pub_r001323_2_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_254_1 * 3) + pub_r001323_7_1) + 33) & 127;
  int stage_v_271_2 = (((stage_v_254_2 * 3) + pub_r001323_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001323_11_1 * 2) + 47) & 63;
  int stage_v_272_2 = ((pub_r001323_11_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_112_1 * 3) + pub_r001323_3_1) + 27) & 127;
  int stage_v_273_2 = (((stage_v_112_2 * 3) + pub_r001323_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((stage_v_131_1 * 3) + pub_r001323_15_1) + 10) & 127;
  int stage_v_274_2 = (((stage_v_131_2 * 3) + pub_r001323_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = (((stage_v_31_1 * 3) + pub_r001323_3_1) + 42) & 127;
  int stage_v_275_2 = (((stage_v_31_2 * 3) + pub_r001323_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((stage_v_184_1 * 3) + pub_r001323_1_1) + 26) & 127;
  int stage_v_276_2 = (((stage_v_184_2 * 3) + pub_r001323_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = ((pub_r001323_12_1 * 2) + 18) & 63;
  int stage_v_277_2 = ((pub_r001323_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((sec_r001323_3_1 * 3) + pub_r001323_4_1) + 5) & 127;
  int stage_v_278_2 = (((sec_r001323_3_2 * 3) + pub_r001323_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001323_8_1 * 2) + 8) & 63;
  int stage_v_279_2 = ((pub_r001323_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001323_14_1 * 2) + 31) & 63;
  int stage_v_280_2 = ((pub_r001323_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = (((stage_v_7_1 * 3) + pub_r001323_11_1) + 33) & 127;
  int stage_v_281_2 = (((stage_v_7_2 * 3) + pub_r001323_11_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001323_13_1 * 2) + 35) & 63;
  int stage_v_282_2 = ((pub_r001323_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_229_1 * 3) + pub_r001323_13_1) + 36) & 127;
  int stage_v_283_2 = (((stage_v_229_2 * 3) + pub_r001323_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_118_1 * 3) + pub_r001323_10_1) + 36) & 127;
  int stage_v_284_2 = (((stage_v_118_2 * 3) + pub_r001323_10_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001323_11_1 * 2) + 7) & 63;
  int stage_v_285_2 = ((pub_r001323_11_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_113_1 * 3) + pub_r001323_0_1) + 18) & 127;
  int stage_v_286_2 = (((stage_v_113_2 * 3) + pub_r001323_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_119_1 * 3) + pub_r001323_4_1) + 45) & 127;
  int stage_v_287_2 = (((stage_v_119_2 * 3) + pub_r001323_4_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001323_14_1 * 2) + 42) & 63;
  int stage_v_288_2 = ((pub_r001323_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001323_9_1 * 2) + 22) & 63;
  int stage_v_289_2 = ((pub_r001323_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((helper_flow_4_1 * 3) + pub_r001323_13_1) + 34) & 127;
  int stage_v_290_2 = (((helper_flow_4_2 * 3) + pub_r001323_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((stage_v_149_1 * 3) + pub_r001323_14_1) + 43) & 127;
  int stage_v_291_2 = (((stage_v_149_2 * 3) + pub_r001323_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_238_1 * 3) + pub_r001323_11_1) + 45) & 127;
  int stage_v_292_2 = (((stage_v_238_2 * 3) + pub_r001323_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001323_13_1 * 2) + 49) & 63;
  int stage_v_293_2 = ((pub_r001323_13_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001323_3_1 * 2) + 5) & 63;
  int stage_v_294_2 = ((pub_r001323_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_230_1 * 3) + pub_r001323_5_1) + 27) & 127;
  int stage_v_295_2 = (((stage_v_230_2 * 3) + pub_r001323_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((sec_r001323_9_1 * 3) + pub_r001323_6_1) + 4) & 127;
  int stage_v_296_2 = (((sec_r001323_9_2 * 3) + pub_r001323_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001323_1_1 * 2) + 25) & 63;
  int stage_v_297_2 = ((pub_r001323_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001323_10_1 * 2) + 41) & 63;
  int stage_v_298_2 = ((pub_r001323_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001323_13_1 * 2) + 10) & 63;
  int stage_v_299_2 = ((pub_r001323_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = (((sec_r001323_16_1 * 3) + pub_r001323_12_1) + 19) & 127;
  int stage_v_300_2 = (((sec_r001323_16_2 * 3) + pub_r001323_12_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_217_1 * 3) + pub_r001323_6_1) + 32) & 127;
  int stage_v_301_2 = (((stage_v_217_2 * 3) + pub_r001323_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((stage_v_190_1 * 3) + pub_r001323_13_1) + 40) & 127;
  int stage_v_302_2 = (((stage_v_190_2 * 3) + pub_r001323_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_251_1 * 3) + pub_r001323_6_1) + 36) & 127;
  int stage_v_303_2 = (((stage_v_251_2 * 3) + pub_r001323_6_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001323_2_1 * 2) + 31) & 63;
  int stage_v_304_2 = ((pub_r001323_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001323_14_1 * 2) + 49) & 63;
  int stage_v_305_2 = ((pub_r001323_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = (((stage_v_166_1 * 3) + pub_r001323_0_1) + 5) & 127;
  int stage_v_306_2 = (((stage_v_166_2 * 3) + pub_r001323_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = ((pub_r001323_4_1 * 2) + 37) & 63;
  int stage_v_307_2 = ((pub_r001323_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001323_10_1 * 2) + 26) & 63;
  int stage_v_308_2 = ((pub_r001323_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((sec_r001323_5_1 * 3) + pub_r001323_14_1) + 40) & 127;
  int stage_v_309_2 = (((sec_r001323_5_2 * 3) + pub_r001323_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001323_14_1 * 2) + 6) & 63;
  int stage_v_310_2 = ((pub_r001323_14_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001323_8_1 * 2) + 42) & 63;
  int stage_v_311_2 = ((pub_r001323_8_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001323_14_1 * 2) + 20) & 63;
  int stage_v_312_2 = ((pub_r001323_14_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((stage_v_6_1 * 3) + pub_r001323_15_1) + 28) & 127;
  int stage_v_313_2 = (((stage_v_6_2 * 3) + pub_r001323_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_258_1 * 3) + pub_r001323_2_1) + 10) & 127;
  int stage_v_314_2 = (((stage_v_258_2 * 3) + pub_r001323_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_223_1 * 3) + pub_r001323_8_1) + 35) & 127;
  int stage_v_315_2 = (((stage_v_223_2 * 3) + pub_r001323_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001323_14_1 * 2) + 17) & 63;
  int stage_v_316_2 = ((pub_r001323_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001323_8_1 * 2) + 33) & 63;
  int stage_v_317_2 = ((pub_r001323_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001323_13_1 * 2) + 6) & 63;
  int stage_v_318_2 = ((pub_r001323_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001323_10_1 * 2) + 36) & 63;
  int stage_v_319_2 = ((pub_r001323_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_71_1 * 3) + pub_r001323_10_1) + 17) & 127;
  int stage_v_320_2 = (((stage_v_71_2 * 3) + pub_r001323_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001323_12_1 * 2) + 28) & 63;
  int stage_v_321_2 = ((pub_r001323_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = (((stage_v_124_1 * 3) + pub_r001323_5_1) + 21) & 127;
  int stage_v_322_2 = (((stage_v_124_2 * 3) + pub_r001323_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = ((pub_r001323_6_1 * 2) + 49) & 63;
  int stage_v_323_2 = ((pub_r001323_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = (((stage_v_46_1 * 3) + pub_r001323_1_1) + 10) & 127;
  int stage_v_324_2 = (((stage_v_46_2 * 3) + pub_r001323_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = ((pub_r001323_14_1 * 2) + 24) & 63;
  int stage_v_325_2 = ((pub_r001323_14_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = (((sec_r001323_6_1 * 3) + pub_r001323_14_1) + 37) & 127;
  int stage_v_326_2 = (((sec_r001323_6_2 * 3) + pub_r001323_14_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = (((stage_v_125_1 * 3) + pub_r001323_0_1) + 32) & 127;
  int stage_v_327_2 = (((stage_v_125_2 * 3) + pub_r001323_0_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_11_1 * 3) + pub_r001323_11_1) + 7) & 127;
  int stage_v_328_2 = (((stage_v_11_2 * 3) + pub_r001323_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_214_1 * 3) + pub_r001323_7_1) + 41) & 127;
  int stage_v_329_2 = (((stage_v_214_2 * 3) + pub_r001323_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_11_1 * 3) + pub_r001323_2_1) + 35) & 127;
  int stage_v_330_2 = (((stage_v_11_2 * 3) + pub_r001323_2_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = ((pub_r001323_3_1 * 2) + 39) & 63;
  int stage_v_331_2 = ((pub_r001323_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001323_10_1 * 2) + 19) & 63;
  int stage_v_332_2 = ((pub_r001323_10_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001323_4_1 * 2) + 17) & 63;
  int stage_v_333_2 = ((pub_r001323_4_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_273_1 * 3) + pub_r001323_0_1) + 5) & 127;
  int stage_v_334_2 = (((stage_v_273_2 * 3) + pub_r001323_0_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_273_1 * 3) + pub_r001323_3_1) + 10) & 127;
  int stage_v_335_2 = (((stage_v_273_2 * 3) + pub_r001323_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001323_13_1 * 2) + 6) & 63;
  int stage_v_336_2 = ((pub_r001323_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001323_0_1 * 2) + 37) & 63;
  int stage_v_337_2 = ((pub_r001323_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001323_4_1 * 2) + 48) & 63;
  int stage_v_338_2 = ((pub_r001323_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001323_10_1 * 2) + 27) & 63;
  int stage_v_339_2 = ((pub_r001323_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_34_1 * 3) + pub_r001323_0_1) + 42) & 127;
  int stage_v_340_2 = (((stage_v_34_2 * 3) + pub_r001323_0_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_133_1 * 3) + pub_r001323_6_1) + 39) & 127;
  int stage_v_341_2 = (((stage_v_133_2 * 3) + pub_r001323_6_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001323_0_1 * 2) + 29) & 63;
  int stage_v_342_2 = ((pub_r001323_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001323_4_1 * 2) + 36) & 63;
  int stage_v_343_2 = ((pub_r001323_4_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = (((stage_v_278_1 * 3) + pub_r001323_4_1) + 19) & 127;
  int stage_v_344_2 = (((stage_v_278_2 * 3) + pub_r001323_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = (((stage_v_274_1 * 3) + pub_r001323_3_1) + 41) & 127;
  int stage_v_345_2 = (((stage_v_274_2 * 3) + pub_r001323_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_113_1 * 3) + pub_r001323_1_1) + 41) & 127;
  int stage_v_346_2 = (((stage_v_113_2 * 3) + pub_r001323_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001323_12_1 * 2) + 20) & 63;
  int stage_v_347_2 = ((pub_r001323_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_213_1 * 3) + pub_r001323_13_1) + 40) & 127;
  int stage_v_348_2 = (((stage_v_213_2 * 3) + pub_r001323_13_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((sec_r001323_11_1 * 3) + pub_r001323_11_1) + 40) & 127;
  int stage_v_349_2 = (((sec_r001323_11_2 * 3) + pub_r001323_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_166_1 * 3) + pub_r001323_1_1) + 38) & 127;
  int stage_v_350_2 = (((stage_v_166_2 * 3) + pub_r001323_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_220_1 * 3) + pub_r001323_11_1) + 35) & 127;
  int stage_v_351_2 = (((stage_v_220_2 * 3) + pub_r001323_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001323_8_1 * 2) + 44) & 63;
  int stage_v_352_2 = ((pub_r001323_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001323_7_1 * 2) + 28) & 63;
  int stage_v_353_2 = ((pub_r001323_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = (((stage_v_327_1 * 3) + pub_r001323_15_1) + 23) & 127;
  int stage_v_354_2 = (((stage_v_327_2 * 3) + pub_r001323_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_93_1 * 3) + pub_r001323_11_1) + 13) & 127;
  int stage_v_355_2 = (((stage_v_93_2 * 3) + pub_r001323_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001323_0_1 * 2) + 7) & 63;
  int stage_v_356_2 = ((pub_r001323_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_157_1 * 3) + pub_r001323_10_1) + 13) & 127;
  int stage_v_357_2 = (((stage_v_157_2 * 3) + pub_r001323_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((stage_v_260_1 * 3) + pub_r001323_13_1) + 31) & 127;
  int stage_v_358_2 = (((stage_v_260_2 * 3) + pub_r001323_13_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = ((pub_r001323_13_1 * 2) + 47) & 63;
  int stage_v_359_2 = ((pub_r001323_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_11_1 * 3) + pub_r001323_15_1) + 44) & 127;
  int stage_v_360_2 = (((stage_v_11_2 * 3) + pub_r001323_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = ((pub_r001323_13_1 * 2) + 14) & 63;
  int stage_v_361_2 = ((pub_r001323_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = (((stage_v_301_1 * 3) + pub_r001323_3_1) + 7) & 127;
  int stage_v_362_2 = (((stage_v_301_2 * 3) + pub_r001323_3_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = (((stage_v_216_1 * 3) + pub_r001323_14_1) + 29) & 127;
  int stage_v_363_2 = (((stage_v_216_2 * 3) + pub_r001323_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_344_1 * 3) + pub_r001323_8_1) + 13) & 127;
  int stage_v_364_2 = (((stage_v_344_2 * 3) + pub_r001323_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_26_1 * 3) + pub_r001323_14_1) + 35) & 127;
  int stage_v_365_2 = (((stage_v_26_2 * 3) + pub_r001323_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = (((sec_r001323_4_1 * 3) + pub_r001323_9_1) + 34) & 127;
  int stage_v_366_2 = (((sec_r001323_4_2 * 3) + pub_r001323_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = ((pub_r001323_15_1 * 2) + 47) & 63;
  int stage_v_367_2 = ((pub_r001323_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_367_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_367_2) & 127;
  int stage_v_368_1 = ((pub_r001323_13_1 * 2) + 11) & 63;
  int stage_v_368_2 = ((pub_r001323_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001323_1_1 * 2) + 19) & 63;
  int stage_v_369_2 = ((pub_r001323_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = (((stage_v_254_1 * 3) + pub_r001323_6_1) + 35) & 127;
  int stage_v_370_2 = (((stage_v_254_2 * 3) + pub_r001323_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_370_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_370_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_370_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_370_2 * 2)) & 255;
  int stage_v_371_1 = (((stage_v_348_1 * 3) + pub_r001323_2_1) + 32) & 127;
  int stage_v_371_2 = (((stage_v_348_2 * 3) + pub_r001323_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = (((stage_v_81_1 * 3) + pub_r001323_4_1) + 29) & 127;
  int stage_v_372_2 = (((stage_v_81_2 * 3) + pub_r001323_4_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_74_1 * 3) + pub_r001323_15_1) + 19) & 127;
  int stage_v_373_2 = (((stage_v_74_2 * 3) + pub_r001323_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_121_1 * 3) + pub_r001323_13_1) + 45) & 127;
  int stage_v_374_2 = (((stage_v_121_2 * 3) + pub_r001323_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = (((stage_v_44_1 * 3) + pub_r001323_0_1) + 14) & 127;
  int stage_v_375_2 = (((stage_v_44_2 * 3) + pub_r001323_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = ((pub_r001323_0_1 * 2) + 6) & 63;
  int stage_v_376_2 = ((pub_r001323_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = (((stage_v_268_1 * 3) + pub_r001323_11_1) + 32) & 127;
  int stage_v_377_2 = (((stage_v_268_2 * 3) + pub_r001323_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_377_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_377_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_377_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_377_2 * 2)) & 255;
  int stage_v_378_1 = ((pub_r001323_14_1 * 2) + 12) & 63;
  int stage_v_378_2 = ((pub_r001323_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001323_4_1 * 2) + 46) & 63;
  int stage_v_379_2 = ((pub_r001323_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = (((stage_v_349_1 * 3) + pub_r001323_1_1) + 45) & 127;
  int stage_v_380_2 = (((stage_v_349_2 * 3) + pub_r001323_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_171_1 * 3) + pub_r001323_0_1) + 10) & 127;
  int stage_v_381_2 = (((stage_v_171_2 * 3) + pub_r001323_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001323_12_1 * 2) + 6) & 63;
  int stage_v_382_2 = ((pub_r001323_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = (((stage_v_253_1 * 3) + pub_r001323_0_1) + 11) & 127;
  int stage_v_383_2 = (((stage_v_253_2 * 3) + pub_r001323_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((stage_v_36_1 * 3) + pub_r001323_12_1) + 44) & 127;
  int stage_v_384_2 = (((stage_v_36_2 * 3) + pub_r001323_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = (((stage_v_360_1 * 3) + pub_r001323_10_1) + 6) & 127;
  int stage_v_385_2 = (((stage_v_360_2 * 3) + pub_r001323_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_385_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_385_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_385_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_385_2 * 2)) & 255;
  int stage_v_386_1 = (((stage_v_246_1 * 3) + pub_r001323_4_1) + 23) & 127;
  int stage_v_386_2 = (((stage_v_246_2 * 3) + pub_r001323_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_386_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_386_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_386_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_386_2 * 2)) & 255;
  int stage_v_387_1 = (((stage_v_167_1 * 3) + pub_r001323_11_1) + 31) & 127;
  int stage_v_387_2 = (((stage_v_167_2 * 3) + pub_r001323_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((sec_r001323_0_1 * 3) + pub_r001323_10_1) + 34) & 127;
  int stage_v_388_2 = (((sec_r001323_0_2 * 3) + pub_r001323_10_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001323_10_1 * 2) + 24) & 63;
  int stage_v_389_2 = ((pub_r001323_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = (((stage_v_181_1 * 3) + pub_r001323_15_1) + 31) & 127;
  int stage_v_390_2 = (((stage_v_181_2 * 3) + pub_r001323_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_390_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_390_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_390_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_390_2 * 2)) & 255;
  int stage_v_391_1 = (((stage_v_186_1 * 3) + pub_r001323_12_1) + 13) & 127;
  int stage_v_391_2 = (((stage_v_186_2 * 3) + pub_r001323_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((sec_r001323_0_1 * 3) + pub_r001323_9_1) + 45) & 127;
  int stage_v_392_2 = (((sec_r001323_0_2 * 3) + pub_r001323_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_27_1 * 3) + pub_r001323_6_1) + 27) & 127;
  int stage_v_393_2 = (((stage_v_27_2 * 3) + pub_r001323_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = (((stage_v_185_1 * 3) + pub_r001323_8_1) + 38) & 127;
  int stage_v_394_2 = (((stage_v_185_2 * 3) + pub_r001323_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_394_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_394_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_394_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_394_2 * 2)) & 255;
  int stage_v_395_1 = ((pub_r001323_14_1 * 2) + 36) & 63;
  int stage_v_395_2 = ((pub_r001323_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_185_1 * 3) + pub_r001323_6_1) + 5) & 127;
  int stage_v_396_2 = (((stage_v_185_2 * 3) + pub_r001323_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001323_7_1 * 2) + 6) & 63;
  int stage_v_397_2 = ((pub_r001323_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001323_13_1 * 2) + 42) & 63;
  int stage_v_398_2 = ((pub_r001323_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = (((stage_v_35_1 * 3) + pub_r001323_13_1) + 18) & 127;
  int stage_v_399_2 = (((stage_v_35_2 * 3) + pub_r001323_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001323_9_1 * 2) + 21) & 63;
  int stage_v_400_2 = ((pub_r001323_9_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_10_1 * 3) + pub_r001323_6_1) + 30) & 127;
  int stage_v_401_2 = (((stage_v_10_2 * 3) + pub_r001323_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001323_3_1 * 2) + 20) & 63;
  int stage_v_402_2 = ((pub_r001323_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = (((stage_v_326_1 * 3) + pub_r001323_1_1) + 24) & 127;
  int stage_v_403_2 = (((stage_v_326_2 * 3) + pub_r001323_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = ((pub_r001323_2_1 * 2) + 16) & 63;
  int stage_v_404_2 = ((pub_r001323_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = (((stage_v_87_1 * 3) + pub_r001323_6_1) + 25) & 127;
  int stage_v_405_2 = (((stage_v_87_2 * 3) + pub_r001323_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = ((pub_r001323_2_1 * 2) + 9) & 63;
  int stage_v_406_2 = ((pub_r001323_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = (((stage_v_75_1 * 3) + pub_r001323_3_1) + 36) & 127;
  int stage_v_407_2 = (((stage_v_75_2 * 3) + pub_r001323_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_407_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_407_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_407_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_407_2 * 2)) & 255;
  int stage_v_408_1 = (((stage_v_51_1 * 3) + pub_r001323_10_1) + 25) & 127;
  int stage_v_408_2 = (((stage_v_51_2 * 3) + pub_r001323_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = (((stage_v_286_1 * 3) + pub_r001323_0_1) + 19) & 127;
  int stage_v_409_2 = (((stage_v_286_2 * 3) + pub_r001323_0_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001323_2_1 * 2) + 19) & 63;
  int stage_v_410_2 = ((pub_r001323_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001323_13_1 * 2) + 41) & 63;
  int stage_v_411_2 = ((pub_r001323_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_380_1 * 3) + pub_r001323_6_1) + 12) & 127;
  int stage_v_412_2 = (((stage_v_380_2 * 3) + pub_r001323_6_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = (((stage_v_75_1 * 3) + pub_r001323_11_1) + 31) & 127;
  int stage_v_413_2 = (((stage_v_75_2 * 3) + pub_r001323_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = (((stage_v_13_1 * 3) + pub_r001323_14_1) + 11) & 127;
  int stage_v_414_2 = (((stage_v_13_2 * 3) + pub_r001323_14_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = (((stage_v_6_1 * 3) + pub_r001323_10_1) + 26) & 127;
  int stage_v_415_2 = (((stage_v_6_2 * 3) + pub_r001323_10_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001323_15_1 * 2) + 44) & 63;
  int stage_v_416_2 = ((pub_r001323_15_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_383_1 * 3) + pub_r001323_11_1) + 30) & 127;
  int stage_v_417_2 = (((stage_v_383_2 * 3) + pub_r001323_11_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001323_4_1 * 2) + 47) & 63;
  int stage_v_418_2 = ((pub_r001323_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001323_13_1 * 2) + 12) & 63;
  int stage_v_419_2 = ((pub_r001323_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_407_1 * 3) + pub_r001323_13_1) + 6) & 127;
  int stage_v_420_2 = (((stage_v_407_2 * 3) + pub_r001323_13_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001323_0_1 * 2) + 27) & 63;
  int stage_v_421_2 = ((pub_r001323_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001323_9_1 * 2) + 15) & 63;
  int stage_v_422_2 = ((pub_r001323_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_247_1 * 3) + pub_r001323_13_1) + 32) & 127;
  int stage_v_423_2 = (((stage_v_247_2 * 3) + pub_r001323_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001323_6_1 * 2) + 10) & 63;
  int stage_v_424_2 = ((pub_r001323_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_278_1 * 3) + pub_r001323_5_1) + 13) & 127;
  int stage_v_425_2 = (((stage_v_278_2 * 3) + pub_r001323_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001323_14_1 * 2) + 9) & 63;
  int stage_v_426_2 = ((pub_r001323_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = (((stage_v_136_1 * 3) + pub_r001323_8_1) + 44) & 127;
  int stage_v_427_2 = (((stage_v_136_2 * 3) + pub_r001323_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001323_5_1 * 2) + 23) & 63;
  int stage_v_428_2 = ((pub_r001323_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001323_11_1 * 2) + 6) & 63;
  int stage_v_429_2 = ((pub_r001323_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = ((pub_r001323_14_1 * 2) + 49) & 63;
  int stage_v_430_2 = ((pub_r001323_14_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((stage_v_256_1 * 3) + pub_r001323_15_1) + 43) & 127;
  int stage_v_431_2 = (((stage_v_256_2 * 3) + pub_r001323_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = (((stage_v_274_1 * 3) + pub_r001323_7_1) + 39) & 127;
  int stage_v_432_2 = (((stage_v_274_2 * 3) + pub_r001323_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = (((stage_v_256_1 * 3) + pub_r001323_4_1) + 42) & 127;
  int stage_v_433_2 = (((stage_v_256_2 * 3) + pub_r001323_4_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001323_3_1 * 2) + 38) & 63;
  int stage_v_434_2 = ((pub_r001323_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001323_4_1 * 2) + 38) & 63;
  int stage_v_435_2 = ((pub_r001323_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_354_1 * 3) + pub_r001323_8_1) + 6) & 127;
  int stage_v_436_2 = (((stage_v_354_2 * 3) + pub_r001323_8_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = ((pub_r001323_1_1 * 2) + 32) & 63;
  int stage_v_437_2 = ((pub_r001323_1_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = (((stage_v_16_1 * 3) + pub_r001323_6_1) + 21) & 127;
  int stage_v_438_2 = (((stage_v_16_2 * 3) + pub_r001323_6_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = ((pub_r001323_2_1 * 2) + 16) & 63;
  int stage_v_439_2 = ((pub_r001323_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = (((stage_v_120_1 * 3) + pub_r001323_6_1) + 25) & 127;
  int stage_v_440_2 = (((stage_v_120_2 * 3) + pub_r001323_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_101_1 * 3) + pub_r001323_6_1) + 4) & 127;
  int stage_v_441_2 = (((stage_v_101_2 * 3) + pub_r001323_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((sec_r001323_3_1 * 3) + pub_r001323_12_1) + 31) & 127;
  int stage_v_442_2 = (((sec_r001323_3_2 * 3) + pub_r001323_12_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = ((pub_r001323_8_1 * 2) + 14) & 63;
  int stage_v_443_2 = ((pub_r001323_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001323_11_1 * 2) + 17) & 63;
  int stage_v_444_2 = ((pub_r001323_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = (((stage_v_329_1 * 3) + pub_r001323_4_1) + 28) & 127;
  int stage_v_445_2 = (((stage_v_329_2 * 3) + pub_r001323_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_445_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_445_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_445_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_445_2 * 2)) & 255;
  int stage_v_446_1 = (((helper_flow_5_1 * 3) + pub_r001323_14_1) + 23) & 127;
  int stage_v_446_2 = (((helper_flow_5_2 * 3) + pub_r001323_14_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = ((pub_r001323_3_1 * 2) + 49) & 63;
  int stage_v_447_2 = ((pub_r001323_3_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_447_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_447_2) & 127;
  int stage_v_448_1 = ((pub_r001323_2_1 * 2) + 17) & 63;
  int stage_v_448_2 = ((pub_r001323_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_448_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_448_2) & 127;
  int stage_v_449_1 = (((stage_v_14_1 * 3) + pub_r001323_9_1) + 27) & 127;
  int stage_v_449_2 = (((stage_v_14_2 * 3) + pub_r001323_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001323_11_1 * 2) + 36) & 63;
  int stage_v_450_2 = ((pub_r001323_11_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = ((pub_r001323_10_1 * 2) + 42) & 63;
  int stage_v_451_2 = ((pub_r001323_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = (((stage_v_327_1 * 3) + pub_r001323_5_1) + 29) & 127;
  int stage_v_452_2 = (((stage_v_327_2 * 3) + pub_r001323_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_252_1 * 3) + pub_r001323_0_1) + 45) & 127;
  int stage_v_453_2 = (((stage_v_252_2 * 3) + pub_r001323_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = ((pub_r001323_3_1 * 2) + 20) & 63;
  int stage_v_454_2 = ((pub_r001323_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_454_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_454_2) & 127;
  int stage_v_455_1 = (((stage_v_104_1 * 3) + pub_r001323_11_1) + 15) & 127;
  int stage_v_455_2 = (((stage_v_104_2 * 3) + pub_r001323_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_455_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_455_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_455_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_455_2 * 2)) & 255;
  int stage_v_456_1 = (((stage_v_354_1 * 3) + pub_r001323_9_1) + 7) & 127;
  int stage_v_456_2 = (((stage_v_354_2 * 3) + pub_r001323_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001323_0_1 * 2) + 33) & 63;
  int stage_v_457_2 = ((pub_r001323_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001323_14_1 * 2) + 12) & 63;
  int stage_v_458_2 = ((pub_r001323_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = ((pub_r001323_0_1 * 2) + 44) & 63;
  int stage_v_459_2 = ((pub_r001323_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = (((stage_v_69_1 * 3) + pub_r001323_7_1) + 20) & 127;
  int stage_v_460_2 = (((stage_v_69_2 * 3) + pub_r001323_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_460_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_460_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_460_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_460_2 * 2)) & 255;
  int stage_v_461_1 = ((pub_r001323_0_1 * 2) + 32) & 63;
  int stage_v_461_2 = ((pub_r001323_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = ((pub_r001323_6_1 * 2) + 28) & 63;
  int stage_v_462_2 = ((pub_r001323_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_462_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_462_2) & 127;
  int stage_v_463_1 = ((pub_r001323_1_1 * 2) + 28) & 63;
  int stage_v_463_2 = ((pub_r001323_1_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001323_2_1 * 2) + 45) & 63;
  int stage_v_464_2 = ((pub_r001323_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001323_13_1 * 2) + 28) & 63;
  int stage_v_465_2 = ((pub_r001323_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_283_1 * 3) + pub_r001323_14_1) + 34) & 127;
  int stage_v_466_2 = (((stage_v_283_2 * 3) + pub_r001323_14_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = (((stage_v_14_1 * 3) + pub_r001323_12_1) + 40) & 127;
  int stage_v_467_2 = (((stage_v_14_2 * 3) + pub_r001323_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = (((stage_v_120_1 * 3) + pub_r001323_4_1) + 44) & 127;
  int stage_v_468_2 = (((stage_v_120_2 * 3) + pub_r001323_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_468_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_468_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_468_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_468_2 * 2)) & 255;
  int stage_v_469_1 = ((pub_r001323_2_1 * 2) + 24) & 63;
  int stage_v_469_2 = ((pub_r001323_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_469_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_469_2) & 127;
  int stage_v_470_1 = (((stage_v_1_1 * 3) + pub_r001323_0_1) + 14) & 127;
  int stage_v_470_2 = (((stage_v_1_2 * 3) + pub_r001323_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001323_10_1 * 2) + 41) & 63;
  int stage_v_471_2 = ((pub_r001323_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001323_15_1 * 2) + 49) & 63;
  int stage_v_472_2 = ((pub_r001323_15_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = (((stage_v_6_1 * 3) + pub_r001323_4_1) + 43) & 127;
  int stage_v_473_2 = (((stage_v_6_2 * 3) + pub_r001323_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = ((pub_r001323_15_1 * 2) + 14) & 63;
  int stage_v_474_2 = ((pub_r001323_15_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = (((stage_v_193_1 * 3) + pub_r001323_8_1) + 22) & 127;
  int stage_v_475_2 = (((stage_v_193_2 * 3) + pub_r001323_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = ((pub_r001323_10_1 * 2) + 40) & 63;
  int stage_v_476_2 = ((pub_r001323_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001323_9_1 * 2) + 33) & 63;
  int stage_v_477_2 = ((pub_r001323_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = (((stage_v_320_1 * 3) + pub_r001323_2_1) + 23) & 127;
  int stage_v_478_2 = (((stage_v_320_2 * 3) + pub_r001323_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_478_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_478_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_478_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_478_2 * 2)) & 255;
  int stage_v_479_1 = (((stage_v_137_1 * 3) + pub_r001323_8_1) + 41) & 127;
  int stage_v_479_2 = (((stage_v_137_2 * 3) + pub_r001323_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = (((stage_v_63_1 * 3) + pub_r001323_3_1) + 15) & 127;
  int stage_v_480_2 = (((stage_v_63_2 * 3) + pub_r001323_3_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = ((pub_r001323_8_1 * 2) + 39) & 63;
  int stage_v_481_2 = ((pub_r001323_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_481_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_481_2) & 127;
  int stage_v_482_1 = (((stage_v_260_1 * 3) + pub_r001323_7_1) + 21) & 127;
  int stage_v_482_2 = (((stage_v_260_2 * 3) + pub_r001323_7_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_482_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_482_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_482_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_482_2 * 2)) & 255;
  int stage_v_483_1 = (((stage_v_69_1 * 3) + pub_r001323_13_1) + 35) & 127;
  int stage_v_483_2 = (((stage_v_69_2 * 3) + pub_r001323_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_483_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_483_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_483_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_483_2 * 2)) & 255;
  int stage_v_484_1 = (((stage_v_466_1 * 3) + pub_r001323_9_1) + 7) & 127;
  int stage_v_484_2 = (((stage_v_466_2 * 3) + pub_r001323_9_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  int stage_v_485_1 = (((stage_v_14_1 * 3) + pub_r001323_8_1) + 29) & 127;
  int stage_v_485_2 = (((stage_v_14_2 * 3) + pub_r001323_8_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = ((pub_r001323_9_1 * 2) + 26) & 63;
  int stage_v_486_2 = ((pub_r001323_9_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((pub_r001323_12_1 * 2) + 6) & 63;
  int stage_v_487_2 = ((pub_r001323_12_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = (((stage_v_387_1 * 3) + pub_r001323_4_1) + 25) & 127;
  int stage_v_488_2 = (((stage_v_387_2 * 3) + pub_r001323_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = (((stage_v_473_1 * 3) + pub_r001323_10_1) + 7) & 127;
  int stage_v_489_2 = (((stage_v_473_2 * 3) + pub_r001323_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_489_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_489_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_489_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_489_2 * 2)) & 255;
  int stage_v_490_1 = ((pub_r001323_13_1 * 2) + 6) & 63;
  int stage_v_490_2 = ((pub_r001323_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001323_6_1 * 2) + 23) & 63;
  int stage_v_491_2 = ((pub_r001323_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = (((stage_v_233_1 * 3) + pub_r001323_1_1) + 24) & 127;
  int stage_v_492_2 = (((stage_v_233_2 * 3) + pub_r001323_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = ((pub_r001323_7_1 * 2) + 15) & 63;
  int stage_v_493_2 = ((pub_r001323_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_493_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_493_2) & 127;
  int stage_v_494_1 = (((stage_v_50_1 * 3) + pub_r001323_1_1) + 20) & 127;
  int stage_v_494_2 = (((stage_v_50_2 * 3) + pub_r001323_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = (((stage_v_417_1 * 3) + pub_r001323_4_1) + 38) & 127;
  int stage_v_495_2 = (((stage_v_417_2 * 3) + pub_r001323_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_495_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_495_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_495_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_495_2 * 2)) & 255;
  int stage_v_496_1 = (((stage_v_306_1 * 3) + pub_r001323_2_1) + 23) & 127;
  int stage_v_496_2 = (((stage_v_306_2 * 3) + pub_r001323_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = (((sec_r001323_20_1 * 3) + pub_r001323_2_1) + 30) & 127;
  int stage_v_497_2 = (((sec_r001323_20_2 * 3) + pub_r001323_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_497_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_497_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_497_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_497_2 * 2)) & 255;
  int stage_v_498_1 = ((pub_r001323_1_1 * 2) + 15) & 63;
  int stage_v_498_2 = ((pub_r001323_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = ((pub_r001323_3_1 * 2) + 28) & 63;
  int stage_v_499_2 = ((pub_r001323_3_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = (((stage_v_242_1 * 3) + pub_r001323_12_1) + 37) & 127;
  int stage_v_500_2 = (((stage_v_242_2 * 3) + pub_r001323_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = ((pub_r001323_11_1 * 2) + 46) & 63;
  int stage_v_501_2 = ((pub_r001323_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_501_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_501_2) & 127;
  int stage_v_502_1 = ((pub_r001323_11_1 * 2) + 41) & 63;
  int stage_v_502_2 = ((pub_r001323_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((pub_r001323_4_1 * 2) + 38) & 63;
  int stage_v_503_2 = ((pub_r001323_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = ((pub_r001323_14_1 * 2) + 5) & 63;
  int stage_v_504_2 = ((pub_r001323_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_504_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_504_2) & 127;
  int stage_v_505_1 = (((stage_v_30_1 * 3) + pub_r001323_8_1) + 30) & 127;
  int stage_v_505_2 = (((stage_v_30_2 * 3) + pub_r001323_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_505_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_505_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_505_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_505_2 * 2)) & 255;
  int stage_v_506_1 = ((pub_r001323_1_1 * 2) + 8) & 63;
  int stage_v_506_2 = ((pub_r001323_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_506_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_506_2) & 127;
  int stage_v_507_1 = (((stage_v_291_1 * 3) + pub_r001323_1_1) + 21) & 127;
  int stage_v_507_2 = (((stage_v_291_2 * 3) + pub_r001323_1_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_507_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_507_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_507_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_507_2 * 2)) & 255;
  int stage_v_508_1 = (((stage_v_120_1 * 3) + pub_r001323_14_1) + 43) & 127;
  int stage_v_508_2 = (((stage_v_120_2 * 3) + pub_r001323_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_508_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_508_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_508_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_508_2 * 2)) & 255;
  int stage_v_509_1 = (((stage_v_484_1 * 3) + pub_r001323_11_1) + 31) & 127;
  int stage_v_509_2 = (((stage_v_484_2 * 3) + pub_r001323_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_509_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_509_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_509_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_509_2 * 2)) & 255;
  int stage_v_510_1 = (((stage_v_209_1 * 3) + pub_r001323_13_1) + 38) & 127;
  int stage_v_510_2 = (((stage_v_209_2 * 3) + pub_r001323_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_510_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_510_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_510_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_510_2 * 2)) & 255;
  int stage_v_511_1 = ((pub_r001323_6_1 * 2) + 29) & 63;
  int stage_v_511_2 = ((pub_r001323_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_511_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_511_2) & 127;
  int stage_v_512_1 = ((pub_r001323_2_1 * 2) + 41) & 63;
  int stage_v_512_2 = ((pub_r001323_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_512_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_512_2) & 127;
  int stage_v_513_1 = (((stage_v_186_1 * 3) + pub_r001323_11_1) + 32) & 127;
  int stage_v_513_2 = (((stage_v_186_2 * 3) + pub_r001323_11_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_513_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_513_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_513_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_513_2 * 2)) & 255;
  int stage_v_514_1 = ((pub_r001323_7_1 * 2) + 10) & 63;
  int stage_v_514_2 = ((pub_r001323_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_514_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_514_2) & 127;
  int stage_v_515_1 = ((pub_r001323_4_1 * 2) + 24) & 63;
  int stage_v_515_2 = ((pub_r001323_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_515_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_515_2) & 127;
  int stage_v_516_1 = ((pub_r001323_12_1 * 2) + 10) & 63;
  int stage_v_516_2 = ((pub_r001323_12_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_516_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_516_2) & 127;
  int stage_v_517_1 = (((stage_v_505_1 * 3) + pub_r001323_0_1) + 45) & 127;
  int stage_v_517_2 = (((stage_v_505_2 * 3) + pub_r001323_0_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_517_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_517_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_517_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_517_2 * 2)) & 255;
  int stage_v_518_1 = (((stage_v_284_1 * 3) + pub_r001323_1_1) + 32) & 127;
  int stage_v_518_2 = (((stage_v_284_2 * 3) + pub_r001323_1_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_518_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_518_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_518_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_518_2 * 2)) & 255;
  int stage_v_519_1 = (((stage_v_485_1 * 3) + pub_r001323_10_1) + 24) & 127;
  int stage_v_519_2 = (((stage_v_485_2 * 3) + pub_r001323_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_519_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_519_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_519_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_519_2 * 2)) & 255;
  int stage_v_520_1 = (((stage_v_375_1 * 3) + pub_r001323_12_1) + 29) & 127;
  int stage_v_520_2 = (((stage_v_375_2 * 3) + pub_r001323_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_520_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_520_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_520_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_520_2 * 2)) & 255;
  int stage_v_521_1 = (((stage_v_291_1 * 3) + pub_r001323_12_1) + 35) & 127;
  int stage_v_521_2 = (((stage_v_291_2 * 3) + pub_r001323_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_521_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_521_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_521_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_521_2 * 2)) & 255;
  int stage_v_522_1 = (((stage_v_449_1 * 3) + pub_r001323_0_1) + 22) & 127;
  int stage_v_522_2 = (((stage_v_449_2 * 3) + pub_r001323_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_522_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_522_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_522_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_522_2 * 2)) & 255;
  int stage_v_523_1 = ((pub_r001323_4_1 * 2) + 16) & 63;
  int stage_v_523_2 = ((pub_r001323_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_523_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_523_2) & 127;
  int stage_v_524_1 = (((stage_v_112_1 * 3) + pub_r001323_2_1) + 32) & 127;
  int stage_v_524_2 = (((stage_v_112_2 * 3) + pub_r001323_2_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_524_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_524_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_524_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_524_2 * 2)) & 255;
  int stage_v_525_1 = ((pub_r001323_14_1 * 2) + 9) & 63;
  int stage_v_525_2 = ((pub_r001323_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_525_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_525_2) & 127;
  int stage_v_526_1 = (((stage_v_273_1 * 3) + pub_r001323_10_1) + 5) & 127;
  int stage_v_526_2 = (((stage_v_273_2 * 3) + pub_r001323_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_526_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_526_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_526_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_526_2 * 2)) & 255;
  int stage_v_527_1 = (((stage_v_276_1 * 3) + pub_r001323_14_1) + 18) & 127;
  int stage_v_527_2 = (((stage_v_276_2 * 3) + pub_r001323_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_527_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_527_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_527_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_527_2 * 2)) & 255;
  int stage_v_528_1 = (((stage_v_131_1 * 3) + pub_r001323_0_1) + 25) & 127;
  int stage_v_528_2 = (((stage_v_131_2 * 3) + pub_r001323_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_528_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_528_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_528_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_528_2 * 2)) & 255;
  int stage_v_529_1 = ((pub_r001323_8_1 * 2) + 39) & 63;
  int stage_v_529_2 = ((pub_r001323_8_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_529_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_529_2) & 127;
  int stage_v_530_1 = ((pub_r001323_15_1 * 2) + 46) & 63;
  int stage_v_530_2 = ((pub_r001323_15_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_530_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_530_2) & 127;
  int stage_v_531_1 = ((pub_r001323_0_1 * 2) + 38) & 63;
  int stage_v_531_2 = ((pub_r001323_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_531_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_531_2) & 127;
  int stage_v_532_1 = (((stage_v_223_1 * 3) + pub_r001323_2_1) + 14) & 127;
  int stage_v_532_2 = (((stage_v_223_2 * 3) + pub_r001323_2_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_532_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_532_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_532_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_532_2 * 2)) & 255;
  int stage_v_533_1 = (((stage_v_518_1 * 3) + pub_r001323_11_1) + 20) & 127;
  int stage_v_533_2 = (((stage_v_518_2 * 3) + pub_r001323_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_533_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_533_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_533_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_533_2 * 2)) & 255;
  int stage_v_534_1 = ((pub_r001323_3_1 * 2) + 13) & 63;
  int stage_v_534_2 = ((pub_r001323_3_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_534_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_534_2) & 127;
  int stage_v_535_1 = ((pub_r001323_3_1 * 2) + 46) & 63;
  int stage_v_535_2 = ((pub_r001323_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_535_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_535_2) & 127;
  int stage_v_536_1 = (((stage_v_50_1 * 3) + pub_r001323_6_1) + 29) & 127;
  int stage_v_536_2 = (((stage_v_50_2 * 3) + pub_r001323_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_536_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_536_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_536_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_536_2 * 2)) & 255;
  int stage_v_537_1 = (((stage_v_186_1 * 3) + pub_r001323_4_1) + 11) & 127;
  int stage_v_537_2 = (((stage_v_186_2 * 3) + pub_r001323_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_537_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_537_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_537_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_537_2 * 2)) & 255;
  int stage_v_538_1 = (((stage_v_242_1 * 3) + pub_r001323_2_1) + 19) & 127;
  int stage_v_538_2 = (((stage_v_242_2 * 3) + pub_r001323_2_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_538_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_538_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_538_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_538_2 * 2)) & 255;
  int stage_v_539_1 = ((pub_r001323_11_1 * 2) + 43) & 63;
  int stage_v_539_2 = ((pub_r001323_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_539_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_539_2) & 127;
  int stage_v_540_1 = (((stage_v_131_1 * 3) + pub_r001323_0_1) + 14) & 127;
  int stage_v_540_2 = (((stage_v_131_2 * 3) + pub_r001323_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_540_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_540_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_540_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_540_2 * 2)) & 255;
  int stage_v_541_1 = ((pub_r001323_6_1 * 2) + 31) & 63;
  int stage_v_541_2 = ((pub_r001323_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_541_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_541_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001323_16_1 != sec_r001323_16_2);
  __CPROVER_assume(sec_r001323_20_1 != sec_r001323_20_2);
  __CPROVER_assume(pub_r001323_9_1 == pub_r001323_9_2);
  __CPROVER_assume(pub_r001323_5_1 == pub_r001323_5_2);
  __CPROVER_assume(sec_r001323_18_1 != sec_r001323_18_2);
  __CPROVER_assume(pub_r001323_0_1 == pub_r001323_0_2);
  __CPROVER_assume(pub_r001323_11_1 == pub_r001323_11_2);
  __CPROVER_assume(pub_r001323_2_1 == pub_r001323_2_2);
  __CPROVER_assume(sec_r001323_5_1 != sec_r001323_5_2);
  __CPROVER_assume(sec_r001323_4_1 != sec_r001323_4_2);
  __CPROVER_assume(pub_r001323_4_1 == pub_r001323_4_2);
  __CPROVER_assume(sec_r001323_8_1 != sec_r001323_8_2);
  __CPROVER_assume(sec_r001323_6_1 != sec_r001323_6_2);
  __CPROVER_assume(sec_r001323_7_1 != sec_r001323_7_2);
  __CPROVER_assume(pub_r001323_10_1 == pub_r001323_10_2);
  __CPROVER_assume(pub_r001323_15_1 == pub_r001323_15_2);
  __CPROVER_assume(sec_r001323_15_1 != sec_r001323_15_2);
  __CPROVER_assume(pub_r001323_8_1 == pub_r001323_8_2);
  __CPROVER_assume(sec_r001323_12_1 != sec_r001323_12_2);
  __CPROVER_assume(pub_r001323_1_1 == pub_r001323_1_2);
  __CPROVER_assume(sec_r001323_13_1 != sec_r001323_13_2);
  __CPROVER_assume(sec_r001323_0_1 != sec_r001323_0_2);
  __CPROVER_assume(sec_r001323_9_1 != sec_r001323_9_2);
  __CPROVER_assume(pub_r001323_7_1 == pub_r001323_7_2);
  __CPROVER_assume(sec_r001323_17_1 != sec_r001323_17_2);
  __CPROVER_assume(pub_r001323_6_1 == pub_r001323_6_2);
  __CPROVER_assume(pub_r001323_3_1 == pub_r001323_3_2);
  __CPROVER_assume(sec_r001323_19_1 != sec_r001323_19_2);
  __CPROVER_assume(sec_r001323_14_1 != sec_r001323_14_2);
  __CPROVER_assume(sec_r001323_10_1 != sec_r001323_10_2);
  __CPROVER_assume(sec_r001323_1_1 != sec_r001323_1_2);
  __CPROVER_assume(sec_r001323_11_1 != sec_r001323_11_2);
  __CPROVER_assume(sec_r001323_3_1 != sec_r001323_3_2);
  __CPROVER_assume(pub_r001323_13_1 == pub_r001323_13_2);
  __CPROVER_assume(sec_r001323_2_1 != sec_r001323_2_2);
  __CPROVER_assume(pub_r001323_12_1 == pub_r001323_12_2);
  __CPROVER_assume(pub_r001323_14_1 == pub_r001323_14_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.stride == st_var_0_2.stride);
  assert(st_var_0_1.density == st_var_0_2.density);
  assert(st_var_0_1.dim == st_var_0_2.dim);
  assert(st_var_0_1.determinant == st_var_0_2.determinant);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.threshold == st_var_2_2.threshold);
  assert(st_var_2_1.calib == st_var_2_2.calib);
  assert(st_var_2_1.gain == st_var_2_2.gain);
  assert(st_var_2_1.offset == st_var_2_2.offset);
  assert(st_var_2_1.status == st_var_2_2.status);
  assert(st_var_2_1.reading == st_var_2_2.reading);
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
  assert(stage_v_473_1 == stage_v_473_2);
  assert(stage_v_474_1 == stage_v_474_2);
  assert(stage_v_475_1 == stage_v_475_2);
  assert(stage_v_476_1 == stage_v_476_2);
  assert(stage_v_477_1 == stage_v_477_2);
  assert(stage_v_478_1 == stage_v_478_2);
  assert(stage_v_479_1 == stage_v_479_2);
  assert(stage_v_480_1 == stage_v_480_2);
  assert(stage_v_481_1 == stage_v_481_2);
  assert(stage_v_482_1 == stage_v_482_2);
  assert(stage_v_483_1 == stage_v_483_2);
  assert(stage_v_484_1 == stage_v_484_2);
  assert(stage_v_485_1 == stage_v_485_2);
  assert(stage_v_486_1 == stage_v_486_2);
  assert(stage_v_487_1 == stage_v_487_2);
  assert(stage_v_488_1 == stage_v_488_2);
  assert(stage_v_489_1 == stage_v_489_2);
  assert(stage_v_490_1 == stage_v_490_2);
  assert(stage_v_491_1 == stage_v_491_2);
  assert(stage_v_492_1 == stage_v_492_2);
  assert(stage_v_493_1 == stage_v_493_2);
  assert(stage_v_494_1 == stage_v_494_2);
  assert(stage_v_495_1 == stage_v_495_2);
  assert(stage_v_496_1 == stage_v_496_2);
  assert(stage_v_497_1 == stage_v_497_2);
  assert(stage_v_498_1 == stage_v_498_2);
  assert(stage_v_499_1 == stage_v_499_2);
  assert(stage_v_500_1 == stage_v_500_2);
  assert(stage_v_501_1 == stage_v_501_2);
  assert(stage_v_502_1 == stage_v_502_2);
  assert(stage_v_503_1 == stage_v_503_2);
  assert(stage_v_504_1 == stage_v_504_2);
  assert(stage_v_505_1 == stage_v_505_2);
  assert(stage_v_506_1 == stage_v_506_2);
  assert(stage_v_507_1 == stage_v_507_2);
  assert(stage_v_508_1 == stage_v_508_2);
  assert(stage_v_509_1 == stage_v_509_2);
  assert(stage_v_510_1 == stage_v_510_2);
  assert(stage_v_511_1 == stage_v_511_2);
  assert(stage_v_512_1 == stage_v_512_2);
  assert(stage_v_513_1 == stage_v_513_2);
  assert(stage_v_514_1 == stage_v_514_2);
  assert(stage_v_515_1 == stage_v_515_2);
  assert(stage_v_516_1 == stage_v_516_2);
  assert(stage_v_517_1 == stage_v_517_2);
  assert(stage_v_518_1 == stage_v_518_2);
  assert(stage_v_519_1 == stage_v_519_2);
  assert(stage_v_520_1 == stage_v_520_2);
  assert(stage_v_521_1 == stage_v_521_2);
  assert(stage_v_522_1 == stage_v_522_2);
  assert(stage_v_523_1 == stage_v_523_2);
  assert(stage_v_524_1 == stage_v_524_2);
  assert(stage_v_525_1 == stage_v_525_2);
  assert(stage_v_526_1 == stage_v_526_2);
  assert(stage_v_527_1 == stage_v_527_2);
  assert(stage_v_528_1 == stage_v_528_2);
  assert(stage_v_529_1 == stage_v_529_2);
  assert(stage_v_530_1 == stage_v_530_2);
  assert(stage_v_531_1 == stage_v_531_2);
  assert(stage_v_532_1 == stage_v_532_2);
  assert(stage_v_533_1 == stage_v_533_2);
  assert(stage_v_534_1 == stage_v_534_2);
  assert(stage_v_535_1 == stage_v_535_2);
  assert(stage_v_536_1 == stage_v_536_2);
  assert(stage_v_537_1 == stage_v_537_2);
  assert(stage_v_538_1 == stage_v_538_2);
  assert(stage_v_539_1 == stage_v_539_2);
  assert(stage_v_540_1 == stage_v_540_2);
  assert(stage_v_541_1 == stage_v_541_2);
}


