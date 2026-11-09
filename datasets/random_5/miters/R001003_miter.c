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
struct StreamBuffer_R001003_313_0
{
  int watermark;
  int capacity;
  short state;
  int buffer[3];
};
struct Vector3D_R001003_313_1
{
  short heading;
  int coord_y;
  short pitch;
  int norm_sq;
  unsigned char coord_z;
  int buffer[3];
};
union TelemetryField_R001003_313_0
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
void fn_R001003_313_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_87_1 = local_arr_1[aux_1 % 3];
  int damping_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_87_2 * 2)) & 127;
  int quantum_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_19_1) & 63;
  aux_2 = (aux_2 + quantum_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
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

  assert(damping_87_1 == damping_87_2);
  assert(quantum_19_1 == quantum_19_2);
}

int fn_R001003_313_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_87 = local_arr[aux % 3];
  acc = (acc + (damping_87 * 2)) & 127;
  int quantum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001003_313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int coefficient_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_56_1) & 63;
  aux_2 = (aux_2 + coefficient_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_84_1 = local_arr_1[aux_1 % 3];
  int index_reg_84_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_84_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_84_2 * 2)) & 127;
  int stride_59_1 = 0;
  int stride_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_59_1 = ((stride_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_59_2 = ((stride_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_59_1) & 127;
    acc_2 = (acc_2 + stride_59_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_56_1 == coefficient_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_84_1 == index_reg_84_2);
  assert(stride_59_1 == stride_59_2);
}

int fn_R001003_313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int coefficient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_56) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_84 = local_arr[aux % 3];
  acc = (acc + (index_reg_84 * 2)) & 127;
  int stride_59 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_59 = ((stride_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_59) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001003_313_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int vector_18_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_18_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_18_1)
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

  switch (vector_18_2)
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
  int bound_23_1 = local_arr_1[aux_1 % 3];
  int bound_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_23_2 * 2)) & 127;
  int offset_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_68_1 > 22)
  {
    acc_1 = ((acc_1 + (offset_68_1 * 2)) + 5) & 127;
    aux_1 ^= offset_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_68_2 > 22)
  {
    acc_2 = ((acc_2 + (offset_68_2 * 2)) + 5) & 127;
    aux_2 ^= offset_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_22_1 = 0;
  int vector_22_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    vector_22_1 = ((vector_22_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    vector_22_2 = ((vector_22_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + vector_22_1) & 127;
    acc_2 = (acc_2 + vector_22_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_18_1 == vector_18_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_23_1 == bound_23_2);
  assert(offset_68_1 == offset_68_2);
  assert(vector_22_1 == vector_22_2);
}

int fn_R001003_313_2(int p0, int p1)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int vector_18 = (aux + st.buffer[1]) & 3;
  switch (vector_18)
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
  int bound_23 = local_arr[aux % 3];
  acc = (acc + (bound_23 * 2)) & 127;
  int offset_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_68 > 22)
  {
    acc = ((acc + (offset_68 * 2)) + 5) & 127;
    aux ^= offset_68 & 15;
  }
  else
  {
    acc = ((acc - offset_68) + 11) & 127;
    aux += 3;
  }
  int vector_22 = 0;
  for (int k = 0; k < 2; k++)
  {
    vector_22 = ((vector_22 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + vector_22) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001003_313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int quotient_92_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_92_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_92_1 > 20)
  {
    acc_1 = ((acc_1 + (quotient_92_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_92_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_92_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_92_2 > 20)
  {
    acc_2 = ((acc_2 + (quotient_92_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_92_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_92_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_16_1 = 0;
  int tracker_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_16_1 = ((tracker_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_16_2 = ((tracker_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_16_1) & 127;
    acc_2 = (acc_2 + tracker_16_2) & 127;
  }

  int window_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_72_1)
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

  switch (window_72_2)
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
  int margin_57_1 = local_arr_1[aux_1 % 3];
  int margin_57_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_57_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_57_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_92_1 == quotient_92_2);
  assert(tracker_16_1 == tracker_16_2);
  assert(window_72_1 == window_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_57_1 == margin_57_2);
}

int fn_R001003_313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int quotient_92 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_92 > 20)
  {
    acc = ((acc + (quotient_92 * 2)) + 5) & 127;
    aux ^= quotient_92 & 15;
  }
  else
  {
    acc = ((acc - quotient_92) + 11) & 127;
    aux += 3;
  }
  int tracker_16 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_16 = ((tracker_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_16) & 127;
  }

  int window_72 = (aux + st.buffer[1]) & 3;
  switch (window_72)
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
  int margin_57 = local_arr[aux % 3];
  acc = (acc + (margin_57 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int sample_67_1 = 0;
  int sample_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    sample_67_1 = ((sample_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    sample_67_2 = ((sample_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + sample_67_1) & 127;
    acc_2 = (acc_2 + sample_67_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_67_1 == sample_67_2);
}

int fn_R001003_313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int sample_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    sample_67 = ((sample_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + sample_67) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_54_1 = 0;
  int coefficient_54_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_54_1 = ((coefficient_54_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_54_2 = ((coefficient_54_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_54_1) & 127;
    acc_2 = (acc_2 + coefficient_54_2) & 127;
  }

  int cursor_79_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_79_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_79_1)
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

  switch (cursor_79_2)
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

  int phase_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_74_1) & 63;
  aux_2 = (aux_2 + phase_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_99_1 = local_arr_1[aux_1 % 3];
  int weight_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_54_1 == coefficient_54_2);
  assert(cursor_79_1 == cursor_79_2);
  assert(phase_74_1 == phase_74_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_99_1 == weight_99_2);
}

int fn_R001003_313_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_54 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_54 = ((coefficient_54 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_54) & 127;
  }

  int cursor_79 = (aux + st.buffer[1]) & 3;
  switch (cursor_79)
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

  int phase_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_74) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_99 = local_arr[aux % 3];
  acc = (acc + (weight_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_31_1 = local_arr_1[aux_1 % 3];
  int offset_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_31_2 * 2)) & 127;
  int margin_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_27_1) & 63;
  aux_2 = (aux_2 + margin_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_85_1 > 36)
  {
    acc_1 = ((acc_1 + (mask_85_1 * 2)) + 5) & 127;
    aux_1 ^= mask_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_85_2 > 36)
  {
    acc_2 = ((acc_2 + (mask_85_2 * 2)) + 5) & 127;
    aux_2 ^= mask_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
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

  assert(offset_31_1 == offset_31_2);
  assert(margin_27_1 == margin_27_2);
  assert(mask_85_1 == mask_85_2);
}

int fn_R001003_313_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int offset_31 = local_arr[aux % 3];
  acc = (acc + (offset_31 * 2)) & 127;
  int margin_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_27) & 63;
  acc ^= aux;
  int mask_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_85 > 36)
  {
    acc = ((acc + (mask_85 * 2)) + 5) & 127;
    aux ^= mask_85 & 15;
  }
  else
  {
    acc = ((acc - mask_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001003_313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_52_1 = local_arr_1[aux_1 % 3];
  int quantum_52_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_52_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_52_2 * 2)) & 127;
  int weight_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_13_1) & 63;
  aux_2 = (aux_2 + weight_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
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

  assert(quantum_52_1 == quantum_52_2);
  assert(weight_13_1 == weight_13_2);
}

int fn_R001003_313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int quantum_52 = local_arr[aux % 3];
  acc = (acc + (quantum_52 * 2)) & 127;
  int weight_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_13) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int vector_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int vector_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (vector_58_1)
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

  switch (vector_58_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_58_1 == vector_58_2);
}

int fn_R001003_313_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int vector_58 = (aux + st.buffer[1]) & 3;
  switch (vector_58)
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

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int offset_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_34_1) & 63;
  aux_2 = (aux_2 + offset_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quotient_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_72_1 > 22)
  {
    acc_1 = ((acc_1 + (quotient_72_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_72_2 > 22)
  {
    acc_2 = ((acc_2 + (quotient_72_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_27_1 = 0;
  int factor_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_27_1 = ((factor_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_27_2 = ((factor_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_27_1) & 127;
    acc_2 = (acc_2 + factor_27_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_34_1 == offset_34_2);
  assert(quotient_72_1 == quotient_72_2);
  assert(factor_27_1 == factor_27_2);
}

int fn_R001003_313_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int offset_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_34) & 63;
  acc ^= aux;
  int quotient_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_72 > 22)
  {
    acc = ((acc + (quotient_72 * 2)) + 5) & 127;
    aux ^= quotient_72 & 15;
  }
  else
  {
    acc = ((acc - quotient_72) + 11) & 127;
    aux += 3;
  }
  int factor_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_27 = ((factor_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_27) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001003_313_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_90_1)
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

  switch (factor_90_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_90_1 == factor_90_2);
}

int fn_R001003_313_10(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_90 = (aux + st.buffer[1]) & 3;
  switch (factor_90)
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

void fn_R001003_313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_11_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_11_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_11_1)
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

  switch (sample_11_2)
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

  int scale_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_91_1) & 63;
  aux_2 = (aux_2 + scale_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_11_1 == sample_11_2);
  assert(scale_91_1 == scale_91_2);
}

int fn_R001003_313_11(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_11 = (aux + st.buffer[1]) & 3;
  switch (sample_11)
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

  int scale_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_91) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001003_313_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int metric_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_20_1)
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

  switch (metric_20_2)
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

  int stride_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_10_1 > 27)
  {
    acc_1 = ((acc_1 + (stride_10_1 * 2)) + 5) & 127;
    aux_1 ^= stride_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_10_2 > 27)
  {
    acc_2 = ((acc_2 + (stride_10_2 * 2)) + 5) & 127;
    aux_2 ^= stride_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_71_1 = local_arr_1[aux_1 % 3];
  int cursor_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_71_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_20_1 == metric_20_2);
  assert(stride_10_1 == stride_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_71_1 == cursor_71_2);
}

int fn_R001003_313_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int metric_20 = (aux + st.buffer[1]) & 3;
  switch (metric_20)
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

  int stride_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_10 > 27)
  {
    acc = ((acc + (stride_10 * 2)) + 5) & 127;
    aux ^= stride_10 & 15;
  }
  else
  {
    acc = ((acc - stride_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int cursor_71 = local_arr[aux % 3];
  acc = (acc + (cursor_71 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001003_313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st_1 = {0};
  struct Vector3D_R001003_313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_51_1 = local_arr_1[aux_1 % 3];
  int damping_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_51_2 * 2)) & 127;
  int margin_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_78_1)
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

  switch (margin_78_2)
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

  int tally_97_1 = 0;
  int tally_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_97_1 = ((tally_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_97_2 = ((tally_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_97_1) & 127;
    acc_2 = (acc_2 + tally_97_2) & 127;
  }

  int accumulator_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_67_1 > 48)
  {
    acc_1 = ((acc_1 + (accumulator_67_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_67_2 > 48)
  {
    acc_2 = ((acc_2 + (accumulator_67_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_67_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.pitch == st_2.pitch);
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

  assert(damping_51_1 == damping_51_2);
  assert(margin_78_1 == margin_78_2);
  assert(tally_97_1 == tally_97_2);
  assert(accumulator_67_1 == accumulator_67_2);
}

int fn_R001003_313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001003_313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int damping_51 = local_arr[aux % 3];
  acc = (acc + (damping_51 * 2)) & 127;
  int margin_78 = (aux + st.buffer[1]) & 3;
  switch (margin_78)
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

  int tally_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_97 = ((tally_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_97) & 127;
  }

  int accumulator_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_67 > 48)
  {
    acc = ((acc + (accumulator_67 * 2)) + 5) & 127;
    aux ^= accumulator_67 & 15;
  }
  else
  {
    acc = ((acc - accumulator_67) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001003_313_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_95_1)
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

  switch (parity_95_2)
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

  int pivot_31_1 = 0;
  int pivot_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    pivot_31_1 = ((pivot_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_31_2 = ((pivot_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_31_1) & 127;
    acc_2 = (acc_2 + pivot_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_95_1 == parity_95_2);
  assert(pivot_31_1 == pivot_31_2);
}

int fn_R001003_313_14(int p0, int p1, int p2)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_95 = (aux + st.buffer[1]) & 3;
  switch (parity_95)
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

  int pivot_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    pivot_31 = ((pivot_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001003_313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int damping_58_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_58_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_58_1)
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

  switch (damping_58_2)
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

  int quantum_90_1 = 0;
  int quantum_90_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_90_1 = ((quantum_90_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_90_2 = ((quantum_90_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_90_1) & 127;
    acc_2 = (acc_2 + quantum_90_2) & 127;
  }

  int scale_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_56_1 > 29)
  {
    acc_1 = ((acc_1 + (scale_56_1 * 2)) + 5) & 127;
    aux_1 ^= scale_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_56_2 > 29)
  {
    acc_2 = ((acc_2 + (scale_56_2 * 2)) + 5) & 127;
    aux_2 ^= scale_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_56_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_58_1 == damping_58_2);
  assert(quantum_90_1 == quantum_90_2);
  assert(scale_56_1 == scale_56_2);
}

int fn_R001003_313_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int damping_58 = (aux + st.buffer[1]) & 3;
  switch (damping_58)
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

  int quantum_90 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_90 = ((quantum_90 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_90) & 127;
  }

  int scale_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_56 > 29)
  {
    acc = ((acc + (scale_56 * 2)) + 5) & 127;
    aux ^= scale_56 & 15;
  }
  else
  {
    acc = ((acc - scale_56) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001003_313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st_1 = {0};
  struct StreamBuffer_R001003_313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_51_1 = local_arr_1[aux_1 % 3];
  int pivot_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_51_2 * 2)) & 127;
  int pivot_96_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_96_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_96_1)
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

  switch (pivot_96_2)
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
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_51_1 == pivot_51_2);
  assert(pivot_96_1 == pivot_96_2);
}

int fn_R001003_313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001003_313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int pivot_51 = local_arr[aux % 3];
  acc = (acc + (pivot_51 * 2)) & 127;
  int pivot_96 = (aux + st.buffer[1]) & 3;
  switch (pivot_96)
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

void main()
{
  int sec_r001003_0_1;
  int sec_r001003_0_2;
  int sec_r001003_1_1;
  int sec_r001003_1_2;
  int sec_r001003_2_1;
  int sec_r001003_2_2;
  int sec_r001003_3_1;
  int sec_r001003_3_2;
  int sec_r001003_4_1;
  int sec_r001003_4_2;
  int sec_r001003_5_1;
  int sec_r001003_5_2;
  int sec_r001003_6_1;
  int sec_r001003_6_2;
  int sec_r001003_7_1;
  int sec_r001003_7_2;
  int sec_r001003_8_1;
  int sec_r001003_8_2;
  int sec_r001003_9_1;
  int sec_r001003_9_2;
  int sec_r001003_10_1;
  int sec_r001003_10_2;
  int sec_r001003_11_1;
  int sec_r001003_11_2;
  int sec_r001003_12_1;
  int sec_r001003_12_2;
  int sec_r001003_13_1;
  int sec_r001003_13_2;
  int sec_r001003_14_1;
  int sec_r001003_14_2;
  int sec_r001003_15_1;
  int sec_r001003_15_2;
  int sec_r001003_16_1;
  int sec_r001003_16_2;
  int sec_r001003_17_1;
  int sec_r001003_17_2;
  int sec_r001003_18_1;
  int sec_r001003_18_2;
  int sec_r001003_19_1;
  int sec_r001003_19_2;
  int sec_r001003_20_1;
  int sec_r001003_20_2;
  int sec_r001003_21_1;
  int sec_r001003_21_2;
  int sec_r001003_22_1;
  int sec_r001003_22_2;
  int pub_r001003_0_1;
  int pub_r001003_0_2;
  int pub_r001003_1_1;
  int pub_r001003_1_2;
  int pub_r001003_2_1;
  int pub_r001003_2_2;
  int pub_r001003_3_1;
  int pub_r001003_3_2;
  int pub_r001003_4_1;
  int pub_r001003_4_2;
  int pub_r001003_5_1;
  int pub_r001003_5_2;
  int pub_r001003_6_1;
  int pub_r001003_6_2;
  int pub_r001003_7_1;
  int pub_r001003_7_2;
  int pub_r001003_8_1;
  int pub_r001003_8_2;
  int pub_r001003_9_1;
  int pub_r001003_9_2;
  int pub_r001003_10_1;
  int pub_r001003_10_2;
  int pub_r001003_11_1;
  int pub_r001003_11_2;
  int pub_r001003_12_1;
  int pub_r001003_12_2;
  int pub_r001003_13_1;
  int pub_r001003_13_2;
  int pub_r001003_14_1;
  int pub_r001003_14_2;
  int pub_r001003_15_1;
  int pub_r001003_15_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001003_0_1 >= (-100)) && (pub_r001003_0_1 <= 100));
  __CPROVER_assume((pub_r001003_0_2 >= (-100)) && (pub_r001003_0_2 <= 100));
  __CPROVER_assume((pub_r001003_1_1 >= (-100)) && (pub_r001003_1_1 <= 100));
  __CPROVER_assume((pub_r001003_1_2 >= (-100)) && (pub_r001003_1_2 <= 100));
  __CPROVER_assume((pub_r001003_2_1 >= (-100)) && (pub_r001003_2_1 <= 100));
  __CPROVER_assume((pub_r001003_2_2 >= (-100)) && (pub_r001003_2_2 <= 100));
  __CPROVER_assume((pub_r001003_3_1 >= (-100)) && (pub_r001003_3_1 <= 100));
  __CPROVER_assume((pub_r001003_3_2 >= (-100)) && (pub_r001003_3_2 <= 100));
  __CPROVER_assume((pub_r001003_4_1 >= (-100)) && (pub_r001003_4_1 <= 100));
  __CPROVER_assume((pub_r001003_4_2 >= (-100)) && (pub_r001003_4_2 <= 100));
  __CPROVER_assume((pub_r001003_5_1 >= (-100)) && (pub_r001003_5_1 <= 100));
  __CPROVER_assume((pub_r001003_5_2 >= (-100)) && (pub_r001003_5_2 <= 100));
  __CPROVER_assume((pub_r001003_6_1 >= (-100)) && (pub_r001003_6_1 <= 100));
  __CPROVER_assume((pub_r001003_6_2 >= (-100)) && (pub_r001003_6_2 <= 100));
  __CPROVER_assume((pub_r001003_7_1 >= (-100)) && (pub_r001003_7_1 <= 100));
  __CPROVER_assume((pub_r001003_7_2 >= (-100)) && (pub_r001003_7_2 <= 100));
  __CPROVER_assume((pub_r001003_8_1 >= (-100)) && (pub_r001003_8_1 <= 100));
  __CPROVER_assume((pub_r001003_8_2 >= (-100)) && (pub_r001003_8_2 <= 100));
  __CPROVER_assume((pub_r001003_9_1 >= (-100)) && (pub_r001003_9_1 <= 100));
  __CPROVER_assume((pub_r001003_9_2 >= (-100)) && (pub_r001003_9_2 <= 100));
  __CPROVER_assume((pub_r001003_10_1 >= (-100)) && (pub_r001003_10_1 <= 100));
  __CPROVER_assume((pub_r001003_10_2 >= (-100)) && (pub_r001003_10_2 <= 100));
  __CPROVER_assume((pub_r001003_11_1 >= (-100)) && (pub_r001003_11_1 <= 100));
  __CPROVER_assume((pub_r001003_11_2 >= (-100)) && (pub_r001003_11_2 <= 100));
  __CPROVER_assume((pub_r001003_12_1 >= (-100)) && (pub_r001003_12_1 <= 100));
  __CPROVER_assume((pub_r001003_12_2 >= (-100)) && (pub_r001003_12_2 <= 100));
  __CPROVER_assume((pub_r001003_13_1 >= (-100)) && (pub_r001003_13_1 <= 100));
  __CPROVER_assume((pub_r001003_13_2 >= (-100)) && (pub_r001003_13_2 <= 100));
  __CPROVER_assume((pub_r001003_14_1 >= (-100)) && (pub_r001003_14_1 <= 100));
  __CPROVER_assume((pub_r001003_14_2 >= (-100)) && (pub_r001003_14_2 <= 100));
  __CPROVER_assume((pub_r001003_15_1 >= (-100)) && (pub_r001003_15_1 <= 100));
  __CPROVER_assume((pub_r001003_15_2 >= (-100)) && (pub_r001003_15_2 <= 100));
  __CPROVER_assume((sec_r001003_0_1 >= 0) && (sec_r001003_0_1 <= 255));
  __CPROVER_assume((sec_r001003_0_2 >= 0) && (sec_r001003_0_2 <= 255));
  __CPROVER_assume((sec_r001003_1_1 >= 0) && (sec_r001003_1_1 <= 255));
  __CPROVER_assume((sec_r001003_1_2 >= 0) && (sec_r001003_1_2 <= 255));
  __CPROVER_assume((sec_r001003_2_1 >= 0) && (sec_r001003_2_1 <= 255));
  __CPROVER_assume((sec_r001003_2_2 >= 0) && (sec_r001003_2_2 <= 255));
  __CPROVER_assume((sec_r001003_3_1 >= 0) && (sec_r001003_3_1 <= 255));
  __CPROVER_assume((sec_r001003_3_2 >= 0) && (sec_r001003_3_2 <= 255));
  __CPROVER_assume((sec_r001003_4_1 >= 0) && (sec_r001003_4_1 <= 255));
  __CPROVER_assume((sec_r001003_4_2 >= 0) && (sec_r001003_4_2 <= 255));
  __CPROVER_assume((sec_r001003_5_1 >= 0) && (sec_r001003_5_1 <= 255));
  __CPROVER_assume((sec_r001003_5_2 >= 0) && (sec_r001003_5_2 <= 255));
  __CPROVER_assume((sec_r001003_6_1 >= 0) && (sec_r001003_6_1 <= 255));
  __CPROVER_assume((sec_r001003_6_2 >= 0) && (sec_r001003_6_2 <= 255));
  __CPROVER_assume((sec_r001003_7_1 >= 0) && (sec_r001003_7_1 <= 255));
  __CPROVER_assume((sec_r001003_7_2 >= 0) && (sec_r001003_7_2 <= 255));
  __CPROVER_assume((sec_r001003_8_1 >= 0) && (sec_r001003_8_1 <= 255));
  __CPROVER_assume((sec_r001003_8_2 >= 0) && (sec_r001003_8_2 <= 255));
  __CPROVER_assume((sec_r001003_9_1 >= 0) && (sec_r001003_9_1 <= 255));
  __CPROVER_assume((sec_r001003_9_2 >= 0) && (sec_r001003_9_2 <= 255));
  __CPROVER_assume((sec_r001003_10_1 >= 0) && (sec_r001003_10_1 <= 255));
  __CPROVER_assume((sec_r001003_10_2 >= 0) && (sec_r001003_10_2 <= 255));
  __CPROVER_assume((sec_r001003_11_1 >= 0) && (sec_r001003_11_1 <= 255));
  __CPROVER_assume((sec_r001003_11_2 >= 0) && (sec_r001003_11_2 <= 255));
  __CPROVER_assume((sec_r001003_12_1 >= 0) && (sec_r001003_12_1 <= 255));
  __CPROVER_assume((sec_r001003_12_2 >= 0) && (sec_r001003_12_2 <= 255));
  __CPROVER_assume((sec_r001003_13_1 >= 0) && (sec_r001003_13_1 <= 255));
  __CPROVER_assume((sec_r001003_13_2 >= 0) && (sec_r001003_13_2 <= 255));
  __CPROVER_assume((sec_r001003_14_1 >= 0) && (sec_r001003_14_1 <= 255));
  __CPROVER_assume((sec_r001003_14_2 >= 0) && (sec_r001003_14_2 <= 255));
  __CPROVER_assume((sec_r001003_15_1 >= 0) && (sec_r001003_15_1 <= 255));
  __CPROVER_assume((sec_r001003_15_2 >= 0) && (sec_r001003_15_2 <= 255));
  __CPROVER_assume((sec_r001003_16_1 >= 0) && (sec_r001003_16_1 <= 255));
  __CPROVER_assume((sec_r001003_16_2 >= 0) && (sec_r001003_16_2 <= 255));
  __CPROVER_assume((sec_r001003_17_1 >= 0) && (sec_r001003_17_1 <= 255));
  __CPROVER_assume((sec_r001003_17_2 >= 0) && (sec_r001003_17_2 <= 255));
  __CPROVER_assume((sec_r001003_18_1 >= 0) && (sec_r001003_18_1 <= 255));
  __CPROVER_assume((sec_r001003_18_2 >= 0) && (sec_r001003_18_2 <= 255));
  __CPROVER_assume((sec_r001003_19_1 >= 0) && (sec_r001003_19_1 <= 255));
  __CPROVER_assume((sec_r001003_19_2 >= 0) && (sec_r001003_19_2 <= 255));
  __CPROVER_assume((sec_r001003_20_1 >= 0) && (sec_r001003_20_1 <= 255));
  __CPROVER_assume((sec_r001003_20_2 >= 0) && (sec_r001003_20_2 <= 255));
  __CPROVER_assume((sec_r001003_21_1 >= 0) && (sec_r001003_21_1 <= 255));
  __CPROVER_assume((sec_r001003_21_2 >= 0) && (sec_r001003_21_2 <= 255));
  __CPROVER_assume((sec_r001003_22_1 >= 0) && (sec_r001003_22_1 <= 255));
  __CPROVER_assume((sec_r001003_22_2 >= 0) && (sec_r001003_22_2 <= 255));
  struct StreamBuffer_R001003_313_0 st_var_0_1 = {0};
  struct StreamBuffer_R001003_313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001003_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001003_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001003_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001003_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001003_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001003_0_2 + 7) & 15;
  struct Vector3D_R001003_313_1 st_var_1_1 = {0};
  struct Vector3D_R001003_313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001003_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001003_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001003_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001003_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001003_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001003_0_2 + 9) & 15;
  union TelemetryField_R001003_313_0 u_var_1;
  union TelemetryField_R001003_313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001003_313_0(sec_r001003_0_1, pub_r001003_1_1, pub_r001003_2_1, pub_r001003_3_1);
  int helper_flow_0_2 = fn_R001003_313_0(sec_r001003_0_2, pub_r001003_1_2, pub_r001003_2_2, pub_r001003_3_2);
  fn_R001003_313_0_2(sec_r001003_0_1, pub_r001003_1_1, pub_r001003_2_1, pub_r001003_3_1, sec_r001003_0_2, pub_r001003_1_2, pub_r001003_2_2, pub_r001003_3_2);
  int helper_flow_1_1 = fn_R001003_313_1(sec_r001003_1_1, pub_r001003_2_1, pub_r001003_3_1);
  int helper_flow_1_2 = fn_R001003_313_1(sec_r001003_1_2, pub_r001003_2_2, pub_r001003_3_2);
  fn_R001003_313_1_2(sec_r001003_1_1, pub_r001003_2_1, pub_r001003_3_1, sec_r001003_1_2, pub_r001003_2_2, pub_r001003_3_2);
  int helper_flow_2_1 = fn_R001003_313_2(sec_r001003_2_1, pub_r001003_3_1);
  int helper_flow_2_2 = fn_R001003_313_2(sec_r001003_2_2, pub_r001003_3_2);
  fn_R001003_313_2_2(sec_r001003_2_1, pub_r001003_3_1, sec_r001003_2_2, pub_r001003_3_2);
  int helper_flow_3_1 = fn_R001003_313_3(sec_r001003_3_1, pub_r001003_4_1, pub_r001003_5_1);
  int helper_flow_3_2 = fn_R001003_313_3(sec_r001003_3_2, pub_r001003_4_2, pub_r001003_5_2);
  fn_R001003_313_3_2(sec_r001003_3_1, pub_r001003_4_1, pub_r001003_5_1, sec_r001003_3_2, pub_r001003_4_2, pub_r001003_5_2);
  int helper_flow_4_1 = fn_R001003_313_4(sec_r001003_4_1, sec_r001003_5_1, pub_r001003_6_1, pub_r001003_7_1, pub_r001003_8_1);
  int helper_flow_4_2 = fn_R001003_313_4(sec_r001003_4_2, sec_r001003_5_2, pub_r001003_6_2, pub_r001003_7_2, pub_r001003_8_2);
  fn_R001003_313_4_2(sec_r001003_4_1, sec_r001003_5_1, pub_r001003_6_1, pub_r001003_7_1, pub_r001003_8_1, sec_r001003_4_2, sec_r001003_5_2, pub_r001003_6_2, pub_r001003_7_2, pub_r001003_8_2);
  int helper_flow_5_1 = fn_R001003_313_5(sec_r001003_5_1, sec_r001003_6_1, pub_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1);
  int helper_flow_5_2 = fn_R001003_313_5(sec_r001003_5_2, sec_r001003_6_2, pub_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2);
  fn_R001003_313_5_2(sec_r001003_5_1, sec_r001003_6_1, pub_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1, sec_r001003_5_2, sec_r001003_6_2, pub_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2);
  int helper_flow_6_1 = fn_R001003_313_6(sec_r001003_6_1, sec_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1);
  int helper_flow_6_2 = fn_R001003_313_6(sec_r001003_6_2, sec_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2);
  fn_R001003_313_6_2(sec_r001003_6_1, sec_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1, sec_r001003_6_2, sec_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2);
  int helper_flow_7_1 = fn_R001003_313_7(sec_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1, pub_r001003_10_1, pub_r001003_11_1);
  int helper_flow_7_2 = fn_R001003_313_7(sec_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2, pub_r001003_10_2, pub_r001003_11_2);
  fn_R001003_313_7_2(sec_r001003_7_1, pub_r001003_8_1, pub_r001003_9_1, pub_r001003_10_1, pub_r001003_11_1, sec_r001003_7_2, pub_r001003_8_2, pub_r001003_9_2, pub_r001003_10_2, pub_r001003_11_2);
  int stage_v_0_1 = (((sec_r001003_9_1 * 3) + pub_r001003_11_1) + 28) & 127;
  int stage_v_0_2 = (((sec_r001003_9_2 * 3) + pub_r001003_11_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001003_0_1 * 2) + 45) & 63;
  int stage_v_1_2 = ((pub_r001003_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001003_6_1 * 3) + pub_r001003_7_1) + 8) & 127;
  int stage_v_2_2 = (((sec_r001003_6_2 * 3) + pub_r001003_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001003_7_1 * 2) + 29) & 63;
  int stage_v_3_2 = ((pub_r001003_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001003_6_1 * 2) + 34) & 63;
  int stage_v_4_2 = ((pub_r001003_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((pub_r001003_9_1 * 2) + 45) & 63;
  int stage_v_5_2 = ((pub_r001003_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001003_1_1 * 3) + pub_r001003_11_1) + 40) & 127;
  int stage_v_6_2 = (((sec_r001003_1_2 * 3) + pub_r001003_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = (((stage_v_2_1 * 3) + pub_r001003_4_1) + 13) & 127;
  int stage_v_7_2 = (((stage_v_2_2 * 3) + pub_r001003_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001003_2_1 * 2) + 18) & 63;
  int stage_v_8_2 = ((pub_r001003_2_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001003_3_1 * 2) + 48) & 63;
  int stage_v_9_2 = ((pub_r001003_3_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001003_19_1 * 3) + pub_r001003_9_1) + 33) & 127;
  int stage_v_10_2 = (((sec_r001003_19_2 * 3) + pub_r001003_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((helper_flow_4_1 * 3) + pub_r001003_1_1) + 3) & 127;
  int stage_v_11_2 = (((helper_flow_4_2 * 3) + pub_r001003_1_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001003_0_1 * 3) + pub_r001003_0_1) + 6) & 127;
  int stage_v_12_2 = (((sec_r001003_0_2 * 3) + pub_r001003_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001003_0_1 * 2) + 49) & 63;
  int stage_v_13_2 = ((pub_r001003_0_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = (((sec_r001003_5_1 * 3) + pub_r001003_9_1) + 9) & 127;
  int stage_v_14_2 = (((sec_r001003_5_2 * 3) + pub_r001003_9_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((stage_v_14_1 * 3) + pub_r001003_15_1) + 19) & 127;
  int stage_v_15_2 = (((stage_v_14_2 * 3) + pub_r001003_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_4_1 * 3) + pub_r001003_6_1) + 11) & 127;
  int stage_v_16_2 = (((helper_flow_4_2 * 3) + pub_r001003_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001003_13_1 * 2) + 44) & 63;
  int stage_v_17_2 = ((pub_r001003_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((sec_r001003_0_1 * 3) + pub_r001003_11_1) + 27) & 127;
  int stage_v_18_2 = (((sec_r001003_0_2 * 3) + pub_r001003_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((stage_v_6_1 * 3) + pub_r001003_2_1) + 26) & 127;
  int stage_v_19_2 = (((stage_v_6_2 * 3) + pub_r001003_2_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001003_15_1 * 2) + 24) & 63;
  int stage_v_20_2 = ((pub_r001003_15_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001003_12_1 * 2) + 43) & 63;
  int stage_v_21_2 = ((pub_r001003_12_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001003_5_1 * 2) + 43) & 63;
  int stage_v_22_2 = ((pub_r001003_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_18_1 * 3) + pub_r001003_2_1) + 30) & 127;
  int stage_v_23_2 = (((stage_v_18_2 * 3) + pub_r001003_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = ((pub_r001003_1_1 * 2) + 49) & 63;
  int stage_v_24_2 = ((pub_r001003_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = (((helper_flow_4_1 * 3) + pub_r001003_15_1) + 31) & 127;
  int stage_v_25_2 = (((helper_flow_4_2 * 3) + pub_r001003_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_25_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_25_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_25_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_25_2 * 2)) & 255;
  int stage_v_26_1 = (((stage_v_2_1 * 3) + pub_r001003_5_1) + 3) & 127;
  int stage_v_26_2 = (((stage_v_2_2 * 3) + pub_r001003_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = (((sec_r001003_19_1 * 3) + pub_r001003_14_1) + 21) & 127;
  int stage_v_27_2 = (((sec_r001003_19_2 * 3) + pub_r001003_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = (((stage_v_19_1 * 3) + pub_r001003_13_1) + 26) & 127;
  int stage_v_28_2 = (((stage_v_19_2 * 3) + pub_r001003_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = ((pub_r001003_15_1 * 2) + 42) & 63;
  int stage_v_29_2 = ((pub_r001003_15_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001003_2_1 * 2) + 29) & 63;
  int stage_v_30_2 = ((pub_r001003_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((stage_v_14_1 * 3) + pub_r001003_8_1) + 39) & 127;
  int stage_v_31_2 = (((stage_v_14_2 * 3) + pub_r001003_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001003_5_1 * 2) + 20) & 63;
  int stage_v_32_2 = ((pub_r001003_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_12_1 * 3) + pub_r001003_5_1) + 36) & 127;
  int stage_v_33_2 = (((stage_v_12_2 * 3) + pub_r001003_5_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = ((pub_r001003_9_1 * 2) + 33) & 63;
  int stage_v_34_2 = ((pub_r001003_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001003_10_1 * 2) + 30) & 63;
  int stage_v_35_2 = ((pub_r001003_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001003_10_1 * 2) + 20) & 63;
  int stage_v_36_2 = ((pub_r001003_10_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((helper_flow_6_1 * 3) + pub_r001003_12_1) + 41) & 127;
  int stage_v_37_2 = (((helper_flow_6_2 * 3) + pub_r001003_12_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001003_15_1 * 2) + 34) & 63;
  int stage_v_38_2 = ((pub_r001003_15_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001003_0_1 * 2) + 39) & 63;
  int stage_v_39_2 = ((pub_r001003_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_2_1 * 3) + pub_r001003_4_1) + 34) & 127;
  int stage_v_40_2 = (((helper_flow_2_2 * 3) + pub_r001003_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = ((pub_r001003_6_1 * 2) + 28) & 63;
  int stage_v_41_2 = ((pub_r001003_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (((sec_r001003_4_1 * 3) + pub_r001003_9_1) + 3) & 127;
  int stage_v_42_2 = (((sec_r001003_4_2 * 3) + pub_r001003_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001003_1_1 * 2) + 30) & 63;
  int stage_v_43_2 = ((pub_r001003_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001003_15_1 * 2) + 15) & 63;
  int stage_v_44_2 = ((pub_r001003_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((pub_r001003_6_1 * 2) + 9) & 63;
  int stage_v_45_2 = ((pub_r001003_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (((stage_v_2_1 * 3) + pub_r001003_2_1) + 3) & 127;
  int stage_v_46_2 = (((stage_v_2_2 * 3) + pub_r001003_2_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = (((stage_v_33_1 * 3) + pub_r001003_13_1) + 29) & 127;
  int stage_v_47_2 = (((stage_v_33_2 * 3) + pub_r001003_13_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = (((sec_r001003_0_1 * 3) + pub_r001003_8_1) + 11) & 127;
  int stage_v_48_2 = (((sec_r001003_0_2 * 3) + pub_r001003_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = ((pub_r001003_8_1 * 2) + 27) & 63;
  int stage_v_49_2 = ((pub_r001003_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = (((sec_r001003_1_1 * 3) + pub_r001003_3_1) + 20) & 127;
  int stage_v_50_2 = (((sec_r001003_1_2 * 3) + pub_r001003_3_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_50_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_50_2 * 2)) & 255;
  int stage_v_51_1 = (((stage_v_26_1 * 3) + pub_r001003_14_1) + 9) & 127;
  int stage_v_51_2 = (((stage_v_26_2 * 3) + pub_r001003_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001003_2_1 * 2) + 41) & 63;
  int stage_v_52_2 = ((pub_r001003_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001003_5_1 * 2) + 21) & 63;
  int stage_v_53_2 = ((pub_r001003_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001003_6_1 * 2) + 38) & 63;
  int stage_v_54_2 = ((pub_r001003_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((helper_flow_5_1 * 3) + pub_r001003_8_1) + 9) & 127;
  int stage_v_55_2 = (((helper_flow_5_2 * 3) + pub_r001003_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001003_1_1 * 2) + 44) & 63;
  int stage_v_56_2 = ((pub_r001003_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (((stage_v_27_1 * 3) + pub_r001003_9_1) + 3) & 127;
  int stage_v_57_2 = (((stage_v_27_2 * 3) + pub_r001003_9_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((helper_flow_1_1 * 3) + pub_r001003_2_1) + 41) & 127;
  int stage_v_58_2 = (((helper_flow_1_2 * 3) + pub_r001003_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001003_1_1 * 2) + 35) & 63;
  int stage_v_59_2 = ((pub_r001003_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (((stage_v_11_1 * 3) + pub_r001003_15_1) + 23) & 127;
  int stage_v_60_2 = (((stage_v_11_2 * 3) + pub_r001003_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_60_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_60_2 * 2)) & 255;
  int stage_v_61_1 = (((stage_v_57_1 * 3) + pub_r001003_4_1) + 20) & 127;
  int stage_v_61_2 = (((stage_v_57_2 * 3) + pub_r001003_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001003_14_1 * 2) + 43) & 63;
  int stage_v_62_2 = ((pub_r001003_14_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_48_1 * 3) + pub_r001003_7_1) + 33) & 127;
  int stage_v_63_2 = (((stage_v_48_2 * 3) + pub_r001003_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((sec_r001003_21_1 * 3) + pub_r001003_15_1) + 45) & 127;
  int stage_v_64_2 = (((sec_r001003_21_2 * 3) + pub_r001003_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001003_8_1 * 2) + 9) & 63;
  int stage_v_65_2 = ((pub_r001003_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = (((helper_flow_5_1 * 3) + pub_r001003_13_1) + 17) & 127;
  int stage_v_66_2 = (((helper_flow_5_2 * 3) + pub_r001003_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001003_17_1 * 3) + pub_r001003_12_1) + 35) & 127;
  int stage_v_67_2 = (((sec_r001003_17_2 * 3) + pub_r001003_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((sec_r001003_17_1 * 3) + pub_r001003_9_1) + 27) & 127;
  int stage_v_68_2 = (((sec_r001003_17_2 * 3) + pub_r001003_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((stage_v_47_1 * 3) + pub_r001003_15_1) + 34) & 127;
  int stage_v_69_2 = (((stage_v_47_2 * 3) + pub_r001003_15_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((helper_flow_5_1 * 3) + pub_r001003_7_1) + 45) & 127;
  int stage_v_70_2 = (((helper_flow_5_2 * 3) + pub_r001003_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001003_12_1 * 2) + 9) & 63;
  int stage_v_71_2 = ((pub_r001003_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((sec_r001003_20_1 * 3) + pub_r001003_2_1) + 21) & 127;
  int stage_v_72_2 = (((sec_r001003_20_2 * 3) + pub_r001003_2_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = (((stage_v_33_1 * 3) + pub_r001003_2_1) + 11) & 127;
  int stage_v_73_2 = (((stage_v_33_2 * 3) + pub_r001003_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001003_9_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001003_9_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001003_2_1 * 2) + 47) & 63;
  int stage_v_75_2 = ((pub_r001003_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001003_0_1 * 2) + 48) & 63;
  int stage_v_76_2 = ((pub_r001003_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001003_8_1 * 2) + 11) & 63;
  int stage_v_77_2 = ((pub_r001003_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((sec_r001003_4_1 * 3) + pub_r001003_14_1) + 39) & 127;
  int stage_v_78_2 = (((sec_r001003_4_2 * 3) + pub_r001003_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((stage_v_63_1 * 3) + pub_r001003_3_1) + 39) & 127;
  int stage_v_79_2 = (((stage_v_63_2 * 3) + pub_r001003_3_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001003_9_1 * 2) + 20) & 63;
  int stage_v_80_2 = ((pub_r001003_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((stage_v_51_1 * 3) + pub_r001003_0_1) + 4) & 127;
  int stage_v_81_2 = (((stage_v_51_2 * 3) + pub_r001003_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((stage_v_33_1 * 3) + pub_r001003_6_1) + 27) & 127;
  int stage_v_82_2 = (((stage_v_33_2 * 3) + pub_r001003_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001003_8_1 * 2) + 7) & 63;
  int stage_v_83_2 = ((pub_r001003_8_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_0_1 * 3) + pub_r001003_1_1) + 10) & 127;
  int stage_v_84_2 = (((stage_v_0_2 * 3) + pub_r001003_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((stage_v_67_1 * 3) + pub_r001003_14_1) + 40) & 127;
  int stage_v_85_2 = (((stage_v_67_2 * 3) + pub_r001003_14_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001003_9_1 * 2) + 12) & 63;
  int stage_v_86_2 = ((pub_r001003_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = (((sec_r001003_20_1 * 3) + pub_r001003_5_1) + 34) & 127;
  int stage_v_87_2 = (((sec_r001003_20_2 * 3) + pub_r001003_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_87_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_87_2 * 2)) & 255;
  int stage_v_88_1 = (((stage_v_40_1 * 3) + pub_r001003_10_1) + 14) & 127;
  int stage_v_88_2 = (((stage_v_40_2 * 3) + pub_r001003_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = (((stage_v_40_1 * 3) + pub_r001003_4_1) + 38) & 127;
  int stage_v_89_2 = (((stage_v_40_2 * 3) + pub_r001003_4_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_89_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_89_2 * 2)) & 255;
  int stage_v_90_1 = ((pub_r001003_3_1 * 2) + 15) & 63;
  int stage_v_90_2 = ((pub_r001003_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001003_12_1 * 2) + 36) & 63;
  int stage_v_91_2 = ((pub_r001003_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = (((stage_v_84_1 * 3) + pub_r001003_6_1) + 27) & 127;
  int stage_v_92_2 = (((stage_v_84_2 * 3) + pub_r001003_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_92_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_92_2 * 2)) & 255;
  int stage_v_93_1 = (((sec_r001003_16_1 * 3) + pub_r001003_1_1) + 26) & 127;
  int stage_v_93_2 = (((sec_r001003_16_2 * 3) + pub_r001003_1_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = (((stage_v_85_1 * 3) + pub_r001003_12_1) + 43) & 127;
  int stage_v_94_2 = (((stage_v_85_2 * 3) + pub_r001003_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = (((sec_r001003_6_1 * 3) + pub_r001003_0_1) + 12) & 127;
  int stage_v_95_2 = (((sec_r001003_6_2 * 3) + pub_r001003_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = (((stage_v_51_1 * 3) + pub_r001003_6_1) + 9) & 127;
  int stage_v_96_2 = (((stage_v_51_2 * 3) + pub_r001003_6_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((stage_v_58_1 * 3) + pub_r001003_8_1) + 22) & 127;
  int stage_v_97_2 = (((stage_v_58_2 * 3) + pub_r001003_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001003_5_1 * 2) + 6) & 63;
  int stage_v_98_2 = ((pub_r001003_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = (((stage_v_47_1 * 3) + pub_r001003_5_1) + 4) & 127;
  int stage_v_99_2 = (((stage_v_47_2 * 3) + pub_r001003_5_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001003_12_1 * 2) + 5) & 63;
  int stage_v_100_2 = ((pub_r001003_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001003_0_1 * 2) + 27) & 63;
  int stage_v_101_2 = ((pub_r001003_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_51_1 * 3) + pub_r001003_10_1) + 30) & 127;
  int stage_v_102_2 = (((stage_v_51_2 * 3) + pub_r001003_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = (((stage_v_48_1 * 3) + pub_r001003_10_1) + 35) & 127;
  int stage_v_103_2 = (((stage_v_48_2 * 3) + pub_r001003_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_103_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_103_2 * 2)) & 255;
  int stage_v_104_1 = ((pub_r001003_13_1 * 2) + 5) & 63;
  int stage_v_104_2 = ((pub_r001003_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = (((stage_v_2_1 * 3) + pub_r001003_10_1) + 43) & 127;
  int stage_v_105_2 = (((stage_v_2_2 * 3) + pub_r001003_10_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = (((stage_v_2_1 * 3) + pub_r001003_3_1) + 9) & 127;
  int stage_v_106_2 = (((stage_v_2_2 * 3) + pub_r001003_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_106_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_106_2 * 2)) & 255;
  int stage_v_107_1 = (((sec_r001003_2_1 * 3) + pub_r001003_8_1) + 33) & 127;
  int stage_v_107_2 = (((sec_r001003_2_2 * 3) + pub_r001003_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = ((pub_r001003_3_1 * 2) + 36) & 63;
  int stage_v_108_2 = ((pub_r001003_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = (((helper_flow_1_1 * 3) + pub_r001003_15_1) + 45) & 127;
  int stage_v_109_2 = (((helper_flow_1_2 * 3) + pub_r001003_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = (((stage_v_55_1 * 3) + pub_r001003_5_1) + 23) & 127;
  int stage_v_110_2 = (((stage_v_55_2 * 3) + pub_r001003_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = (((stage_v_99_1 * 3) + pub_r001003_4_1) + 16) & 127;
  int stage_v_111_2 = (((stage_v_99_2 * 3) + pub_r001003_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001003_4_1 * 2) + 32) & 63;
  int stage_v_112_2 = ((pub_r001003_4_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((sec_r001003_14_1 * 3) + pub_r001003_11_1) + 12) & 127;
  int stage_v_113_2 = (((sec_r001003_14_2 * 3) + pub_r001003_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001003_14_1 * 2) + 28) & 63;
  int stage_v_114_2 = ((pub_r001003_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001003_13_1 * 2) + 25) & 63;
  int stage_v_115_2 = ((pub_r001003_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001003_11_1 * 2) + 42) & 63;
  int stage_v_116_2 = ((pub_r001003_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001003_11_1 * 2) + 27) & 63;
  int stage_v_117_2 = ((pub_r001003_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001003_10_1 * 2) + 36) & 63;
  int stage_v_118_2 = ((pub_r001003_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (((stage_v_96_1 * 3) + pub_r001003_4_1) + 19) & 127;
  int stage_v_119_2 = (((stage_v_96_2 * 3) + pub_r001003_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_119_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_119_2 * 2)) & 255;
  int stage_v_120_1 = (((sec_r001003_20_1 * 3) + pub_r001003_14_1) + 29) & 127;
  int stage_v_120_2 = (((sec_r001003_20_2 * 3) + pub_r001003_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((stage_v_68_1 * 3) + pub_r001003_9_1) + 22) & 127;
  int stage_v_121_2 = (((stage_v_68_2 * 3) + pub_r001003_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001003_0_1 * 2) + 27) & 63;
  int stage_v_122_2 = ((pub_r001003_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001003_14_1 * 2) + 31) & 63;
  int stage_v_123_2 = ((pub_r001003_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001003_9_1 * 2) + 35) & 63;
  int stage_v_124_2 = ((pub_r001003_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = (((stage_v_55_1 * 3) + pub_r001003_1_1) + 10) & 127;
  int stage_v_125_2 = (((stage_v_55_2 * 3) + pub_r001003_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_125_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_125_2 * 2)) & 255;
  int stage_v_126_1 = (((stage_v_37_1 * 3) + pub_r001003_2_1) + 34) & 127;
  int stage_v_126_2 = (((stage_v_37_2 * 3) + pub_r001003_2_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001003_3_1 * 2) + 44) & 63;
  int stage_v_127_2 = ((pub_r001003_3_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((sec_r001003_8_1 * 3) + pub_r001003_13_1) + 9) & 127;
  int stage_v_128_2 = (((sec_r001003_8_2 * 3) + pub_r001003_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_84_1 * 3) + pub_r001003_11_1) + 31) & 127;
  int stage_v_129_2 = (((stage_v_84_2 * 3) + pub_r001003_11_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_99_1 * 3) + pub_r001003_7_1) + 32) & 127;
  int stage_v_130_2 = (((stage_v_99_2 * 3) + pub_r001003_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001003_7_1 * 2) + 41) & 63;
  int stage_v_131_2 = ((pub_r001003_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (((sec_r001003_16_1 * 3) + pub_r001003_15_1) + 41) & 127;
  int stage_v_132_2 = (((sec_r001003_16_2 * 3) + pub_r001003_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_132_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_132_2 * 2)) & 255;
  int stage_v_133_1 = (((stage_v_68_1 * 3) + pub_r001003_15_1) + 36) & 127;
  int stage_v_133_2 = (((stage_v_68_2 * 3) + pub_r001003_15_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_128_1 * 3) + pub_r001003_3_1) + 35) & 127;
  int stage_v_134_2 = (((stage_v_128_2 * 3) + pub_r001003_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((sec_r001003_12_1 * 3) + pub_r001003_5_1) + 35) & 127;
  int stage_v_135_2 = (((sec_r001003_12_2 * 3) + pub_r001003_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001003_6_1 * 2) + 22) & 63;
  int stage_v_136_2 = ((pub_r001003_6_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = (((sec_r001003_14_1 * 3) + pub_r001003_14_1) + 6) & 127;
  int stage_v_137_2 = (((sec_r001003_14_2 * 3) + pub_r001003_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = ((pub_r001003_3_1 * 2) + 42) & 63;
  int stage_v_138_2 = ((pub_r001003_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_25_1 * 3) + pub_r001003_11_1) + 35) & 127;
  int stage_v_139_2 = (((stage_v_25_2 * 3) + pub_r001003_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = ((pub_r001003_13_1 * 2) + 8) & 63;
  int stage_v_140_2 = ((pub_r001003_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = ((pub_r001003_6_1 * 2) + 23) & 63;
  int stage_v_141_2 = ((pub_r001003_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001003_6_1 * 2) + 9) & 63;
  int stage_v_142_2 = ((pub_r001003_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_50_1 * 3) + pub_r001003_13_1) + 10) & 127;
  int stage_v_143_2 = (((stage_v_50_2 * 3) + pub_r001003_13_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001003_10_1 * 2) + 50) & 63;
  int stage_v_144_2 = ((pub_r001003_10_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_121_1 * 3) + pub_r001003_11_1) + 24) & 127;
  int stage_v_145_2 = (((stage_v_121_2 * 3) + pub_r001003_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_14_1 * 3) + pub_r001003_13_1) + 34) & 127;
  int stage_v_146_2 = (((stage_v_14_2 * 3) + pub_r001003_13_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = (((stage_v_58_1 * 3) + pub_r001003_15_1) + 45) & 127;
  int stage_v_147_2 = (((stage_v_58_2 * 3) + pub_r001003_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_78_1 * 3) + pub_r001003_12_1) + 3) & 127;
  int stage_v_148_2 = (((stage_v_78_2 * 3) + pub_r001003_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001003_7_1 * 2) + 13) & 63;
  int stage_v_149_2 = ((pub_r001003_7_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001003_15_1 * 2) + 22) & 63;
  int stage_v_150_2 = ((pub_r001003_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001003_5_1 * 2) + 15) & 63;
  int stage_v_151_2 = ((pub_r001003_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((sec_r001003_11_1 * 3) + pub_r001003_8_1) + 45) & 127;
  int stage_v_152_2 = (((sec_r001003_11_2 * 3) + pub_r001003_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001003_15_1 * 2) + 17) & 63;
  int stage_v_153_2 = ((pub_r001003_15_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001003_5_1 * 2) + 36) & 63;
  int stage_v_154_2 = ((pub_r001003_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001003_6_1 * 2) + 15) & 63;
  int stage_v_155_2 = ((pub_r001003_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = (((sec_r001003_1_1 * 3) + pub_r001003_0_1) + 9) & 127;
  int stage_v_156_2 = (((sec_r001003_1_2 * 3) + pub_r001003_0_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001003_7_1 * 2) + 30) & 63;
  int stage_v_157_2 = ((pub_r001003_7_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_130_1 * 3) + pub_r001003_2_1) + 16) & 127;
  int stage_v_158_2 = (((stage_v_130_2 * 3) + pub_r001003_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001003_12_1 * 2) + 45) & 63;
  int stage_v_159_2 = ((pub_r001003_12_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001003_8_1 * 2) + 14) & 63;
  int stage_v_160_2 = ((pub_r001003_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = (((sec_r001003_9_1 * 3) + pub_r001003_14_1) + 7) & 127;
  int stage_v_161_2 = (((sec_r001003_9_2 * 3) + pub_r001003_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = (((stage_v_97_1 * 3) + pub_r001003_0_1) + 7) & 127;
  int stage_v_162_2 = (((stage_v_97_2 * 3) + pub_r001003_0_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_119_1 * 3) + pub_r001003_6_1) + 43) & 127;
  int stage_v_163_2 = (((stage_v_119_2 * 3) + pub_r001003_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = (((sec_r001003_2_1 * 3) + pub_r001003_3_1) + 12) & 127;
  int stage_v_164_2 = (((sec_r001003_2_2 * 3) + pub_r001003_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = (((sec_r001003_14_1 * 3) + pub_r001003_0_1) + 22) & 127;
  int stage_v_165_2 = (((sec_r001003_14_2 * 3) + pub_r001003_0_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = (((stage_v_152_1 * 3) + pub_r001003_14_1) + 43) & 127;
  int stage_v_166_2 = (((stage_v_152_2 * 3) + pub_r001003_14_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((stage_v_48_1 * 3) + pub_r001003_7_1) + 11) & 127;
  int stage_v_167_2 = (((stage_v_48_2 * 3) + pub_r001003_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_133_1 * 3) + pub_r001003_12_1) + 27) & 127;
  int stage_v_168_2 = (((stage_v_133_2 * 3) + pub_r001003_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_46_1 * 3) + pub_r001003_1_1) + 10) & 127;
  int stage_v_169_2 = (((stage_v_46_2 * 3) + pub_r001003_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001003_10_1 * 2) + 22) & 63;
  int stage_v_170_2 = ((pub_r001003_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001003_15_1 * 2) + 18) & 63;
  int stage_v_171_2 = ((pub_r001003_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_106_1 * 3) + pub_r001003_14_1) + 16) & 127;
  int stage_v_172_2 = (((stage_v_106_2 * 3) + pub_r001003_14_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = (((stage_v_19_1 * 3) + pub_r001003_3_1) + 13) & 127;
  int stage_v_173_2 = (((stage_v_19_2 * 3) + pub_r001003_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_173_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_173_2 * 2)) & 255;
  int stage_v_174_1 = ((pub_r001003_11_1 * 2) + 20) & 63;
  int stage_v_174_2 = ((pub_r001003_11_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_148_1 * 3) + pub_r001003_8_1) + 41) & 127;
  int stage_v_175_2 = (((stage_v_148_2 * 3) + pub_r001003_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001003_11_1 * 2) + 38) & 63;
  int stage_v_176_2 = ((pub_r001003_11_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001003_9_1 * 2) + 27) & 63;
  int stage_v_177_2 = ((pub_r001003_9_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_158_1 * 3) + pub_r001003_14_1) + 38) & 127;
  int stage_v_178_2 = (((stage_v_158_2 * 3) + pub_r001003_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((helper_flow_1_1 * 3) + pub_r001003_7_1) + 26) & 127;
  int stage_v_179_2 = (((helper_flow_1_2 * 3) + pub_r001003_7_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((sec_r001003_10_1 * 3) + pub_r001003_13_1) + 22) & 127;
  int stage_v_180_2 = (((sec_r001003_10_2 * 3) + pub_r001003_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001003_9_1 * 2) + 47) & 63;
  int stage_v_181_2 = ((pub_r001003_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001003_2_1 * 2) + 23) & 63;
  int stage_v_182_2 = ((pub_r001003_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_72_1 * 3) + pub_r001003_7_1) + 30) & 127;
  int stage_v_183_2 = (((stage_v_72_2 * 3) + pub_r001003_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((sec_r001003_8_1 * 3) + pub_r001003_5_1) + 34) & 127;
  int stage_v_184_2 = (((sec_r001003_8_2 * 3) + pub_r001003_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((sec_r001003_20_1 * 3) + pub_r001003_2_1) + 42) & 127;
  int stage_v_185_2 = (((sec_r001003_20_2 * 3) + pub_r001003_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = (((stage_v_95_1 * 3) + pub_r001003_7_1) + 36) & 127;
  int stage_v_186_2 = (((stage_v_95_2 * 3) + pub_r001003_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001003_14_1 * 2) + 32) & 63;
  int stage_v_187_2 = ((pub_r001003_14_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = (((sec_r001003_0_1 * 3) + pub_r001003_2_1) + 24) & 127;
  int stage_v_188_2 = (((sec_r001003_0_2 * 3) + pub_r001003_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = (((stage_v_146_1 * 3) + pub_r001003_9_1) + 41) & 127;
  int stage_v_189_2 = (((stage_v_146_2 * 3) + pub_r001003_9_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((sec_r001003_11_1 * 3) + pub_r001003_11_1) + 42) & 127;
  int stage_v_190_2 = (((sec_r001003_11_2 * 3) + pub_r001003_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((sec_r001003_5_1 * 3) + pub_r001003_13_1) + 33) & 127;
  int stage_v_191_2 = (((sec_r001003_5_2 * 3) + pub_r001003_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = ((pub_r001003_0_1 * 2) + 39) & 63;
  int stage_v_192_2 = ((pub_r001003_0_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = ((pub_r001003_10_1 * 2) + 44) & 63;
  int stage_v_193_2 = ((pub_r001003_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = (((stage_v_72_1 * 3) + pub_r001003_7_1) + 33) & 127;
  int stage_v_194_2 = (((stage_v_72_2 * 3) + pub_r001003_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = (((sec_r001003_15_1 * 3) + pub_r001003_7_1) + 36) & 127;
  int stage_v_195_2 = (((sec_r001003_15_2 * 3) + pub_r001003_7_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = (((sec_r001003_10_1 * 3) + pub_r001003_6_1) + 18) & 127;
  int stage_v_196_2 = (((sec_r001003_10_2 * 3) + pub_r001003_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = (((sec_r001003_3_1 * 3) + pub_r001003_0_1) + 37) & 127;
  int stage_v_197_2 = (((sec_r001003_3_2 * 3) + pub_r001003_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_197_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_197_2 * 2)) & 255;
  int stage_v_198_1 = ((pub_r001003_1_1 * 2) + 5) & 63;
  int stage_v_198_2 = ((pub_r001003_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((pub_r001003_3_1 * 2) + 29) & 63;
  int stage_v_199_2 = ((pub_r001003_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((stage_v_106_1 * 3) + pub_r001003_8_1) + 12) & 127;
  int stage_v_200_2 = (((stage_v_106_2 * 3) + pub_r001003_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_168_1 * 3) + pub_r001003_2_1) + 41) & 127;
  int stage_v_201_2 = (((stage_v_168_2 * 3) + pub_r001003_2_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001003_11_1 * 2) + 12) & 63;
  int stage_v_202_2 = ((pub_r001003_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_51_1 * 3) + pub_r001003_15_1) + 20) & 127;
  int stage_v_203_2 = (((stage_v_51_2 * 3) + pub_r001003_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_190_1 * 3) + pub_r001003_3_1) + 31) & 127;
  int stage_v_204_2 = (((stage_v_190_2 * 3) + pub_r001003_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_92_1 * 3) + pub_r001003_7_1) + 3) & 127;
  int stage_v_205_2 = (((stage_v_92_2 * 3) + pub_r001003_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_82_1 * 3) + pub_r001003_2_1) + 40) & 127;
  int stage_v_206_2 = (((stage_v_82_2 * 3) + pub_r001003_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_42_1 * 3) + pub_r001003_9_1) + 23) & 127;
  int stage_v_207_2 = (((stage_v_42_2 * 3) + pub_r001003_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001003_12_1 * 2) + 8) & 63;
  int stage_v_208_2 = ((pub_r001003_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_130_1 * 3) + pub_r001003_9_1) + 8) & 127;
  int stage_v_209_2 = (((stage_v_130_2 * 3) + pub_r001003_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = ((pub_r001003_14_1 * 2) + 34) & 63;
  int stage_v_210_2 = ((pub_r001003_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001003_11_1 * 2) + 12) & 63;
  int stage_v_211_2 = ((pub_r001003_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001003_15_1 * 2) + 26) & 63;
  int stage_v_212_2 = ((pub_r001003_15_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001003_7_1 * 2) + 33) & 63;
  int stage_v_213_2 = ((pub_r001003_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((pub_r001003_9_1 * 2) + 47) & 63;
  int stage_v_214_2 = ((pub_r001003_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001003_6_1 * 2) + 28) & 63;
  int stage_v_215_2 = ((pub_r001003_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001003_6_1 * 2) + 42) & 63;
  int stage_v_216_2 = ((pub_r001003_6_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = (((sec_r001003_7_1 * 3) + pub_r001003_7_1) + 19) & 127;
  int stage_v_217_2 = (((sec_r001003_7_2 * 3) + pub_r001003_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = (((stage_v_189_1 * 3) + pub_r001003_7_1) + 20) & 127;
  int stage_v_218_2 = (((stage_v_189_2 * 3) + pub_r001003_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((helper_flow_7_1 * 3) + pub_r001003_5_1) + 7) & 127;
  int stage_v_219_2 = (((helper_flow_7_2 * 3) + pub_r001003_5_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_128_1 * 3) + pub_r001003_10_1) + 5) & 127;
  int stage_v_220_2 = (((stage_v_128_2 * 3) + pub_r001003_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001003_13_1 * 2) + 33) & 63;
  int stage_v_221_2 = ((pub_r001003_13_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((pub_r001003_12_1 * 2) + 20) & 63;
  int stage_v_222_2 = ((pub_r001003_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = (((sec_r001003_6_1 * 3) + pub_r001003_7_1) + 15) & 127;
  int stage_v_223_2 = (((sec_r001003_6_2 * 3) + pub_r001003_7_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_223_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_223_2 * 2)) & 255;
  int stage_v_224_1 = (((stage_v_121_1 * 3) + pub_r001003_1_1) + 39) & 127;
  int stage_v_224_2 = (((stage_v_121_2 * 3) + pub_r001003_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001003_2_1 * 2) + 16) & 63;
  int stage_v_225_2 = ((pub_r001003_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001003_14_1 * 2) + 46) & 63;
  int stage_v_226_2 = ((pub_r001003_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((helper_flow_6_1 * 3) + pub_r001003_8_1) + 17) & 127;
  int stage_v_227_2 = (((helper_flow_6_2 * 3) + pub_r001003_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_72_1 * 3) + pub_r001003_4_1) + 21) & 127;
  int stage_v_228_2 = (((stage_v_72_2 * 3) + pub_r001003_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = (((stage_v_185_1 * 3) + pub_r001003_15_1) + 23) & 127;
  int stage_v_229_2 = (((stage_v_185_2 * 3) + pub_r001003_15_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001003_9_1 * 2) + 18) & 63;
  int stage_v_230_2 = ((pub_r001003_9_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((pub_r001003_1_1 * 2) + 23) & 63;
  int stage_v_231_2 = ((pub_r001003_1_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_231_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_231_2) & 127;
  int stage_v_232_1 = ((pub_r001003_6_1 * 2) + 25) & 63;
  int stage_v_232_2 = ((pub_r001003_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_197_1 * 3) + pub_r001003_12_1) + 4) & 127;
  int stage_v_233_2 = (((stage_v_197_2 * 3) + pub_r001003_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = (((stage_v_165_1 * 3) + pub_r001003_7_1) + 38) & 127;
  int stage_v_234_2 = (((stage_v_165_2 * 3) + pub_r001003_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_190_1 * 3) + pub_r001003_4_1) + 26) & 127;
  int stage_v_235_2 = (((stage_v_190_2 * 3) + pub_r001003_4_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((sec_r001003_12_1 * 3) + pub_r001003_4_1) + 36) & 127;
  int stage_v_236_2 = (((sec_r001003_12_2 * 3) + pub_r001003_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_14_1 * 3) + pub_r001003_1_1) + 43) & 127;
  int stage_v_237_2 = (((stage_v_14_2 * 3) + pub_r001003_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = ((pub_r001003_9_1 * 2) + 41) & 63;
  int stage_v_238_2 = ((pub_r001003_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = (((helper_flow_0_1 * 3) + pub_r001003_3_1) + 12) & 127;
  int stage_v_239_2 = (((helper_flow_0_2 * 3) + pub_r001003_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = ((pub_r001003_9_1 * 2) + 20) & 63;
  int stage_v_240_2 = ((pub_r001003_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_196_1 * 3) + pub_r001003_8_1) + 38) & 127;
  int stage_v_241_2 = (((stage_v_196_2 * 3) + pub_r001003_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((sec_r001003_16_1 * 3) + pub_r001003_13_1) + 37) & 127;
  int stage_v_242_2 = (((sec_r001003_16_2 * 3) + pub_r001003_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_135_1 * 3) + pub_r001003_7_1) + 7) & 127;
  int stage_v_243_2 = (((stage_v_135_2 * 3) + pub_r001003_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_200_1 * 3) + pub_r001003_14_1) + 7) & 127;
  int stage_v_244_2 = (((stage_v_200_2 * 3) + pub_r001003_14_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_102_1 * 3) + pub_r001003_15_1) + 16) & 127;
  int stage_v_245_2 = (((stage_v_102_2 * 3) + pub_r001003_15_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = (((stage_v_185_1 * 3) + pub_r001003_5_1) + 11) & 127;
  int stage_v_246_2 = (((stage_v_185_2 * 3) + pub_r001003_5_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_246_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_246_2 * 2)) & 255;
  int stage_v_247_1 = (((sec_r001003_5_1 * 3) + pub_r001003_7_1) + 7) & 127;
  int stage_v_247_2 = (((sec_r001003_5_2 * 3) + pub_r001003_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = (((stage_v_111_1 * 3) + pub_r001003_11_1) + 38) & 127;
  int stage_v_248_2 = (((stage_v_111_2 * 3) + pub_r001003_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_23_1 * 3) + pub_r001003_12_1) + 45) & 127;
  int stage_v_249_2 = (((stage_v_23_2 * 3) + pub_r001003_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = (((stage_v_186_1 * 3) + pub_r001003_3_1) + 10) & 127;
  int stage_v_250_2 = (((stage_v_186_2 * 3) + pub_r001003_3_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = (((stage_v_132_1 * 3) + pub_r001003_6_1) + 37) & 127;
  int stage_v_251_2 = (((stage_v_132_2 * 3) + pub_r001003_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = ((pub_r001003_11_1 * 2) + 42) & 63;
  int stage_v_252_2 = ((pub_r001003_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = (((helper_flow_3_1 * 3) + pub_r001003_14_1) + 35) & 127;
  int stage_v_253_2 = (((helper_flow_3_2 * 3) + pub_r001003_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_96_1 * 3) + pub_r001003_12_1) + 4) & 127;
  int stage_v_254_2 = (((stage_v_96_2 * 3) + pub_r001003_12_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_200_1 * 3) + pub_r001003_12_1) + 32) & 127;
  int stage_v_255_2 = (((stage_v_200_2 * 3) + pub_r001003_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = ((pub_r001003_12_1 * 2) + 9) & 63;
  int stage_v_256_2 = ((pub_r001003_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((stage_v_66_1 * 3) + pub_r001003_8_1) + 30) & 127;
  int stage_v_257_2 = (((stage_v_66_2 * 3) + pub_r001003_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001003_7_1 * 2) + 14) & 63;
  int stage_v_258_2 = ((pub_r001003_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = (((stage_v_152_1 * 3) + pub_r001003_5_1) + 17) & 127;
  int stage_v_259_2 = (((stage_v_152_2 * 3) + pub_r001003_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_259_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_259_2 * 2)) & 255;
  int stage_v_260_1 = (((stage_v_163_1 * 3) + pub_r001003_2_1) + 39) & 127;
  int stage_v_260_2 = (((stage_v_163_2 * 3) + pub_r001003_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_63_1 * 3) + pub_r001003_2_1) + 13) & 127;
  int stage_v_261_2 = (((stage_v_63_2 * 3) + pub_r001003_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001003_4_1 * 2) + 8) & 63;
  int stage_v_262_2 = ((pub_r001003_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_165_1 * 3) + pub_r001003_10_1) + 32) & 127;
  int stage_v_263_2 = (((stage_v_165_2 * 3) + pub_r001003_10_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_61_1 * 3) + pub_r001003_8_1) + 9) & 127;
  int stage_v_264_2 = (((stage_v_61_2 * 3) + pub_r001003_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = ((pub_r001003_8_1 * 2) + 18) & 63;
  int stage_v_265_2 = ((pub_r001003_8_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_11_1 * 3) + pub_r001003_6_1) + 32) & 127;
  int stage_v_266_2 = (((stage_v_11_2 * 3) + pub_r001003_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((sec_r001003_20_1 * 3) + pub_r001003_1_1) + 23) & 127;
  int stage_v_267_2 = (((sec_r001003_20_2 * 3) + pub_r001003_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_121_1 * 3) + pub_r001003_0_1) + 8) & 127;
  int stage_v_268_2 = (((stage_v_121_2 * 3) + pub_r001003_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_143_1 * 3) + pub_r001003_8_1) + 44) & 127;
  int stage_v_269_2 = (((stage_v_143_2 * 3) + pub_r001003_8_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((stage_v_31_1 * 3) + pub_r001003_10_1) + 14) & 127;
  int stage_v_270_2 = (((stage_v_31_2 * 3) + pub_r001003_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001003_12_1 * 2) + 32) & 63;
  int stage_v_271_2 = ((pub_r001003_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_99_1 * 3) + pub_r001003_2_1) + 45) & 127;
  int stage_v_272_2 = (((stage_v_99_2 * 3) + pub_r001003_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_209_1 * 3) + pub_r001003_15_1) + 20) & 127;
  int stage_v_273_2 = (((stage_v_209_2 * 3) + pub_r001003_15_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001003_1_1 * 2) + 43) & 63;
  int stage_v_274_2 = ((pub_r001003_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = (((stage_v_169_1 * 3) + pub_r001003_10_1) + 5) & 127;
  int stage_v_275_2 = (((stage_v_169_2 * 3) + pub_r001003_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_275_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_275_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_275_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_275_2 * 2)) & 255;
  int stage_v_276_1 = (((sec_r001003_22_1 * 3) + pub_r001003_8_1) + 17) & 127;
  int stage_v_276_2 = (((sec_r001003_22_2 * 3) + pub_r001003_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_276_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_276_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_276_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_276_2 * 2)) & 255;
  int stage_v_277_1 = (((stage_v_179_1 * 3) + pub_r001003_4_1) + 40) & 127;
  int stage_v_277_2 = (((stage_v_179_2 * 3) + pub_r001003_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001003_6_1 * 2) + 19) & 63;
  int stage_v_278_2 = ((pub_r001003_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = ((pub_r001003_9_1 * 2) + 12) & 63;
  int stage_v_279_2 = ((pub_r001003_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = ((pub_r001003_7_1 * 2) + 50) & 63;
  int stage_v_280_2 = ((pub_r001003_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_280_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_280_2) & 127;
  int stage_v_281_1 = ((pub_r001003_8_1 * 2) + 12) & 63;
  int stage_v_281_2 = ((pub_r001003_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_158_1 * 3) + pub_r001003_12_1) + 18) & 127;
  int stage_v_282_2 = (((stage_v_158_2 * 3) + pub_r001003_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = ((pub_r001003_13_1 * 2) + 45) & 63;
  int stage_v_283_2 = ((pub_r001003_13_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = ((pub_r001003_14_1 * 2) + 34) & 63;
  int stage_v_284_2 = ((pub_r001003_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001003_13_1 * 2) + 35) & 63;
  int stage_v_285_2 = ((pub_r001003_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = (((stage_v_50_1 * 3) + pub_r001003_1_1) + 45) & 127;
  int stage_v_286_2 = (((stage_v_50_2 * 3) + pub_r001003_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = (((stage_v_217_1 * 3) + pub_r001003_6_1) + 27) & 127;
  int stage_v_287_2 = (((stage_v_217_2 * 3) + pub_r001003_6_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001003_14_1 * 2) + 11) & 63;
  int stage_v_288_2 = ((pub_r001003_14_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001003_9_1 * 2) + 5) & 63;
  int stage_v_289_2 = ((pub_r001003_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001003_6_1 * 2) + 18) & 63;
  int stage_v_290_2 = ((pub_r001003_6_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((helper_flow_4_1 * 3) + pub_r001003_6_1) + 42) & 127;
  int stage_v_291_2 = (((helper_flow_4_2 * 3) + pub_r001003_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = ((pub_r001003_3_1 * 2) + 31) & 63;
  int stage_v_292_2 = ((pub_r001003_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = (((stage_v_106_1 * 3) + pub_r001003_1_1) + 28) & 127;
  int stage_v_293_2 = (((stage_v_106_2 * 3) + pub_r001003_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = (((stage_v_37_1 * 3) + pub_r001003_4_1) + 11) & 127;
  int stage_v_294_2 = (((stage_v_37_2 * 3) + pub_r001003_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_294_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_294_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_294_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_294_2 * 2)) & 255;
  int stage_v_295_1 = (((stage_v_92_1 * 3) + pub_r001003_6_1) + 29) & 127;
  int stage_v_295_2 = (((stage_v_92_2 * 3) + pub_r001003_6_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_0_1 * 3) + pub_r001003_9_1) + 28) & 127;
  int stage_v_296_2 = (((stage_v_0_2 * 3) + pub_r001003_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001003_9_1 * 2) + 33) & 63;
  int stage_v_297_2 = ((pub_r001003_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_146_1 * 3) + pub_r001003_4_1) + 30) & 127;
  int stage_v_298_2 = (((stage_v_146_2 * 3) + pub_r001003_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_263_1 * 3) + pub_r001003_1_1) + 39) & 127;
  int stage_v_299_2 = (((stage_v_263_2 * 3) + pub_r001003_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = ((pub_r001003_10_1 * 2) + 5) & 63;
  int stage_v_300_2 = ((pub_r001003_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((sec_r001003_2_1 * 3) + pub_r001003_14_1) + 41) & 127;
  int stage_v_301_2 = (((sec_r001003_2_2 * 3) + pub_r001003_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001003_0_1 * 2) + 23) & 63;
  int stage_v_302_2 = ((pub_r001003_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_165_1 * 3) + pub_r001003_4_1) + 23) & 127;
  int stage_v_303_2 = (((stage_v_165_2 * 3) + pub_r001003_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001003_10_1 * 2) + 14) & 63;
  int stage_v_304_2 = ((pub_r001003_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_129_1 * 3) + pub_r001003_7_1) + 19) & 127;
  int stage_v_305_2 = (((stage_v_129_2 * 3) + pub_r001003_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001003_15_1 * 2) + 10) & 63;
  int stage_v_306_2 = ((pub_r001003_15_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = (((stage_v_184_1 * 3) + pub_r001003_12_1) + 22) & 127;
  int stage_v_307_2 = (((stage_v_184_2 * 3) + pub_r001003_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001003_2_1 * 2) + 22) & 63;
  int stage_v_308_2 = ((pub_r001003_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001003_4_1 * 2) + 39) & 63;
  int stage_v_309_2 = ((pub_r001003_4_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = (((stage_v_23_1 * 3) + pub_r001003_13_1) + 18) & 127;
  int stage_v_310_2 = (((stage_v_23_2 * 3) + pub_r001003_13_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_310_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_310_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_310_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_310_2 * 2)) & 255;
  int stage_v_311_1 = (((stage_v_301_1 * 3) + pub_r001003_12_1) + 36) & 127;
  int stage_v_311_2 = (((stage_v_301_2 * 3) + pub_r001003_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_99_1 * 3) + pub_r001003_8_1) + 17) & 127;
  int stage_v_312_2 = (((stage_v_99_2 * 3) + pub_r001003_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = (((sec_r001003_0_1 * 3) + pub_r001003_14_1) + 38) & 127;
  int stage_v_313_2 = (((sec_r001003_0_2 * 3) + pub_r001003_14_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = (((stage_v_249_1 * 3) + pub_r001003_8_1) + 10) & 127;
  int stage_v_314_2 = (((stage_v_249_2 * 3) + pub_r001003_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001003_9_1 * 2) + 47) & 63;
  int stage_v_315_2 = ((pub_r001003_9_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = ((pub_r001003_8_1 * 2) + 11) & 63;
  int stage_v_316_2 = ((pub_r001003_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = (((sec_r001003_6_1 * 3) + pub_r001003_2_1) + 7) & 127;
  int stage_v_317_2 = (((sec_r001003_6_2 * 3) + pub_r001003_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_317_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_317_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_317_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_317_2 * 2)) & 255;
  int stage_v_318_1 = ((pub_r001003_14_1 * 2) + 14) & 63;
  int stage_v_318_2 = ((pub_r001003_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001003_14_1 * 2) + 29) & 63;
  int stage_v_319_2 = ((pub_r001003_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = ((pub_r001003_3_1 * 2) + 24) & 63;
  int stage_v_320_2 = ((pub_r001003_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001003_7_1 * 2) + 15) & 63;
  int stage_v_321_2 = ((pub_r001003_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001003_2_1 * 2) + 19) & 63;
  int stage_v_322_2 = ((pub_r001003_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001003_0_1 * 2) + 46) & 63;
  int stage_v_323_2 = ((pub_r001003_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001003_0_1 * 2) + 26) & 63;
  int stage_v_324_2 = ((pub_r001003_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((stage_v_255_1 * 3) + pub_r001003_12_1) + 16) & 127;
  int stage_v_325_2 = (((stage_v_255_2 * 3) + pub_r001003_12_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_313_1 * 3) + pub_r001003_12_1) + 20) & 127;
  int stage_v_326_2 = (((stage_v_313_2 * 3) + pub_r001003_12_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001003_5_1 * 2) + 21) & 63;
  int stage_v_327_2 = ((pub_r001003_5_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = (((stage_v_146_1 * 3) + pub_r001003_4_1) + 41) & 127;
  int stage_v_328_2 = (((stage_v_146_2 * 3) + pub_r001003_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((sec_r001003_11_1 * 3) + pub_r001003_5_1) + 39) & 127;
  int stage_v_329_2 = (((sec_r001003_11_2 * 3) + pub_r001003_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = ((pub_r001003_2_1 * 2) + 15) & 63;
  int stage_v_330_2 = ((pub_r001003_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001003_13_1 * 2) + 10) & 63;
  int stage_v_331_2 = ((pub_r001003_13_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_0_1 * 3) + pub_r001003_1_1) + 28) & 127;
  int stage_v_332_2 = (((stage_v_0_2 * 3) + pub_r001003_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = (((stage_v_245_1 * 3) + pub_r001003_4_1) + 30) & 127;
  int stage_v_333_2 = (((stage_v_245_2 * 3) + pub_r001003_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_333_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_333_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_333_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_333_2 * 2)) & 255;
  int stage_v_334_1 = ((pub_r001003_12_1 * 2) + 36) & 63;
  int stage_v_334_2 = ((pub_r001003_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = (((stage_v_132_1 * 3) + pub_r001003_10_1) + 31) & 127;
  int stage_v_335_2 = (((stage_v_132_2 * 3) + pub_r001003_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001003_0_1 * 2) + 40) & 63;
  int stage_v_336_2 = ((pub_r001003_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_14_1 * 3) + pub_r001003_15_1) + 44) & 127;
  int stage_v_337_2 = (((stage_v_14_2 * 3) + pub_r001003_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001003_3_1 * 2) + 37) & 63;
  int stage_v_338_2 = ((pub_r001003_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((stage_v_272_1 * 3) + pub_r001003_3_1) + 22) & 127;
  int stage_v_339_2 = (((stage_v_272_2 * 3) + pub_r001003_3_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((sec_r001003_19_1 * 3) + pub_r001003_12_1) + 34) & 127;
  int stage_v_340_2 = (((sec_r001003_19_2 * 3) + pub_r001003_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_102_1 * 3) + pub_r001003_11_1) + 14) & 127;
  int stage_v_341_2 = (((stage_v_102_2 * 3) + pub_r001003_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_287_1 * 3) + pub_r001003_5_1) + 25) & 127;
  int stage_v_342_2 = (((stage_v_287_2 * 3) + pub_r001003_5_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((sec_r001003_7_1 * 3) + pub_r001003_3_1) + 5) & 127;
  int stage_v_343_2 = (((sec_r001003_7_2 * 3) + pub_r001003_3_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = ((pub_r001003_15_1 * 2) + 19) & 63;
  int stage_v_344_2 = ((pub_r001003_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_89_1 * 3) + pub_r001003_15_1) + 17) & 127;
  int stage_v_345_2 = (((stage_v_89_2 * 3) + pub_r001003_15_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((stage_v_263_1 * 3) + pub_r001003_7_1) + 22) & 127;
  int stage_v_346_2 = (((stage_v_263_2 * 3) + pub_r001003_7_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001003_15_1 * 2) + 16) & 63;
  int stage_v_347_2 = ((pub_r001003_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((helper_flow_5_1 * 3) + pub_r001003_11_1) + 39) & 127;
  int stage_v_348_2 = (((helper_flow_5_2 * 3) + pub_r001003_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001003_10_1 * 2) + 29) & 63;
  int stage_v_349_2 = ((pub_r001003_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((sec_r001003_5_1 * 3) + pub_r001003_8_1) + 45) & 127;
  int stage_v_350_2 = (((sec_r001003_5_2 * 3) + pub_r001003_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_246_1 * 3) + pub_r001003_7_1) + 31) & 127;
  int stage_v_351_2 = (((stage_v_246_2 * 3) + pub_r001003_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001003_12_1 * 2) + 23) & 63;
  int stage_v_352_2 = ((pub_r001003_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_305_1 * 3) + pub_r001003_8_1) + 37) & 127;
  int stage_v_353_2 = (((stage_v_305_2 * 3) + pub_r001003_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((helper_flow_4_1 * 3) + pub_r001003_4_1) + 39) & 127;
  int stage_v_354_2 = (((helper_flow_4_2 * 3) + pub_r001003_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_190_1 * 3) + pub_r001003_10_1) + 17) & 127;
  int stage_v_355_2 = (((stage_v_190_2 * 3) + pub_r001003_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = (((stage_v_273_1 * 3) + pub_r001003_11_1) + 24) & 127;
  int stage_v_356_2 = (((stage_v_273_2 * 3) + pub_r001003_11_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = (((stage_v_107_1 * 3) + pub_r001003_8_1) + 10) & 127;
  int stage_v_357_2 = (((stage_v_107_2 * 3) + pub_r001003_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = (((sec_r001003_12_1 * 3) + pub_r001003_12_1) + 25) & 127;
  int stage_v_358_2 = (((sec_r001003_12_2 * 3) + pub_r001003_12_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((sec_r001003_22_1 * 3) + pub_r001003_14_1) + 5) & 127;
  int stage_v_359_2 = (((sec_r001003_22_2 * 3) + pub_r001003_14_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = ((pub_r001003_7_1 * 2) + 12) & 63;
  int stage_v_360_2 = ((pub_r001003_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001003_2_1 * 2) + 47) & 63;
  int stage_v_361_2 = ((pub_r001003_2_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001003_8_1 * 2) + 47) & 63;
  int stage_v_362_2 = ((pub_r001003_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_178_1 * 3) + pub_r001003_15_1) + 44) & 127;
  int stage_v_363_2 = (((stage_v_178_2 * 3) + pub_r001003_15_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = ((pub_r001003_0_1 * 2) + 45) & 63;
  int stage_v_364_2 = ((pub_r001003_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = ((pub_r001003_1_1 * 2) + 34) & 63;
  int stage_v_365_2 = ((pub_r001003_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = ((pub_r001003_13_1 * 2) + 48) & 63;
  int stage_v_366_2 = ((pub_r001003_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_227_1 * 3) + pub_r001003_3_1) + 41) & 127;
  int stage_v_367_2 = (((stage_v_227_2 * 3) + pub_r001003_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_367_1 * 3) + pub_r001003_14_1) + 25) & 127;
  int stage_v_368_2 = (((stage_v_367_2 * 3) + pub_r001003_14_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001003_6_1 * 2) + 33) & 63;
  int stage_v_369_2 = ((pub_r001003_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001003_10_1 * 2) + 5) & 63;
  int stage_v_370_2 = ((pub_r001003_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001003_6_1 * 2) + 29) & 63;
  int stage_v_371_2 = ((pub_r001003_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001003_9_1 * 2) + 38) & 63;
  int stage_v_372_2 = ((pub_r001003_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_303_1 * 3) + pub_r001003_6_1) + 10) & 127;
  int stage_v_373_2 = (((stage_v_303_2 * 3) + pub_r001003_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001003_12_1 * 2) + 17) & 63;
  int stage_v_374_2 = ((pub_r001003_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = (((stage_v_246_1 * 3) + pub_r001003_12_1) + 44) & 127;
  int stage_v_375_2 = (((stage_v_246_2 * 3) + pub_r001003_12_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_375_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_375_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_375_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_375_2 * 2)) & 255;
  int stage_v_376_1 = (((stage_v_340_1 * 3) + pub_r001003_9_1) + 13) & 127;
  int stage_v_376_2 = (((stage_v_340_2 * 3) + pub_r001003_9_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001003_0_1 * 2) + 8) & 63;
  int stage_v_377_2 = ((pub_r001003_0_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_200_1 * 3) + pub_r001003_12_1) + 3) & 127;
  int stage_v_378_2 = (((stage_v_200_2 * 3) + pub_r001003_12_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = (((stage_v_235_1 * 3) + pub_r001003_7_1) + 45) & 127;
  int stage_v_379_2 = (((stage_v_235_2 * 3) + pub_r001003_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = ((pub_r001003_5_1 * 2) + 25) & 63;
  int stage_v_380_2 = ((pub_r001003_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_293_1 * 3) + pub_r001003_11_1) + 27) & 127;
  int stage_v_381_2 = (((stage_v_293_2 * 3) + pub_r001003_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001003_9_1 * 2) + 43) & 63;
  int stage_v_382_2 = ((pub_r001003_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001003_10_1 * 2) + 40) & 63;
  int stage_v_383_2 = ((pub_r001003_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((sec_r001003_7_1 * 3) + pub_r001003_9_1) + 45) & 127;
  int stage_v_384_2 = (((sec_r001003_7_2 * 3) + pub_r001003_9_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001003_15_1 * 2) + 15) & 63;
  int stage_v_385_2 = ((pub_r001003_15_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001003_12_1 * 2) + 21) & 63;
  int stage_v_386_2 = ((pub_r001003_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_111_1 * 3) + pub_r001003_0_1) + 4) & 127;
  int stage_v_387_2 = (((stage_v_111_2 * 3) + pub_r001003_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = (((stage_v_376_1 * 3) + pub_r001003_8_1) + 21) & 127;
  int stage_v_388_2 = (((stage_v_376_2 * 3) + pub_r001003_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_388_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_388_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_388_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_388_2 * 2)) & 255;
  int stage_v_389_1 = ((pub_r001003_9_1 * 2) + 19) & 63;
  int stage_v_389_2 = ((pub_r001003_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001003_10_1 * 2) + 12) & 63;
  int stage_v_390_2 = ((pub_r001003_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001003_5_1 * 2) + 15) & 63;
  int stage_v_391_2 = ((pub_r001003_5_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = (((stage_v_310_1 * 3) + pub_r001003_5_1) + 16) & 127;
  int stage_v_392_2 = (((stage_v_310_2 * 3) + pub_r001003_5_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = (((stage_v_348_1 * 3) + pub_r001003_4_1) + 43) & 127;
  int stage_v_393_2 = (((stage_v_348_2 * 3) + pub_r001003_4_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001003_11_1 * 2) + 45) & 63;
  int stage_v_394_2 = ((pub_r001003_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001003_12_1 * 2) + 23) & 63;
  int stage_v_395_2 = ((pub_r001003_12_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_31_1 * 3) + pub_r001003_11_1) + 36) & 127;
  int stage_v_396_2 = (((stage_v_31_2 * 3) + pub_r001003_11_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001003_14_1 * 2) + 10) & 63;
  int stage_v_397_2 = ((pub_r001003_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = ((pub_r001003_13_1 * 2) + 5) & 63;
  int stage_v_398_2 = ((pub_r001003_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_398_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_398_2) & 127;
  int stage_v_399_1 = ((pub_r001003_3_1 * 2) + 7) & 63;
  int stage_v_399_2 = ((pub_r001003_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001003_1_1 * 2) + 46) & 63;
  int stage_v_400_2 = ((pub_r001003_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_81_1 * 3) + pub_r001003_5_1) + 18) & 127;
  int stage_v_401_2 = (((stage_v_81_2 * 3) + pub_r001003_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = (((stage_v_317_1 * 3) + pub_r001003_11_1) + 20) & 127;
  int stage_v_402_2 = (((stage_v_317_2 * 3) + pub_r001003_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_0_1 * 3) + pub_r001003_4_1) + 25) & 127;
  int stage_v_403_2 = (((stage_v_0_2 * 3) + pub_r001003_4_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((sec_r001003_21_1 * 3) + pub_r001003_5_1) + 23) & 127;
  int stage_v_404_2 = (((sec_r001003_21_2 * 3) + pub_r001003_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = (((stage_v_135_1 * 3) + pub_r001003_7_1) + 30) & 127;
  int stage_v_405_2 = (((stage_v_135_2 * 3) + pub_r001003_7_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_405_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_405_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_405_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_405_2 * 2)) & 255;
  int stage_v_406_1 = (((stage_v_33_1 * 3) + pub_r001003_6_1) + 30) & 127;
  int stage_v_406_2 = (((stage_v_33_2 * 3) + pub_r001003_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001003_1_1 * 2) + 22) & 63;
  int stage_v_407_2 = ((pub_r001003_1_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001003_2_1 * 2) + 31) & 63;
  int stage_v_408_2 = ((pub_r001003_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001003_11_1 * 2) + 5) & 63;
  int stage_v_409_2 = ((pub_r001003_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001003_4_1 * 2) + 40) & 63;
  int stage_v_410_2 = ((pub_r001003_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001003_3_1 * 2) + 9) & 63;
  int stage_v_411_2 = ((pub_r001003_3_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_247_1 * 3) + pub_r001003_10_1) + 15) & 127;
  int stage_v_412_2 = (((stage_v_247_2 * 3) + pub_r001003_10_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001003_5_1 * 2) + 36) & 63;
  int stage_v_413_2 = ((pub_r001003_5_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = ((pub_r001003_1_1 * 2) + 45) & 63;
  int stage_v_414_2 = ((pub_r001003_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_266_1 * 3) + pub_r001003_5_1) + 26) & 127;
  int stage_v_415_2 = (((stage_v_266_2 * 3) + pub_r001003_5_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001003_9_1 * 2) + 32) & 63;
  int stage_v_416_2 = ((pub_r001003_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = (((stage_v_175_1 * 3) + pub_r001003_10_1) + 7) & 127;
  int stage_v_417_2 = (((stage_v_175_2 * 3) + pub_r001003_10_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001003_13_1 * 2) + 34) & 63;
  int stage_v_418_2 = ((pub_r001003_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_55_1 * 3) + pub_r001003_15_1) + 10) & 127;
  int stage_v_419_2 = (((stage_v_55_2 * 3) + pub_r001003_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001003_13_1 * 2) + 35) & 63;
  int stage_v_420_2 = ((pub_r001003_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((stage_v_2_1 * 3) + pub_r001003_4_1) + 9) & 127;
  int stage_v_421_2 = (((stage_v_2_2 * 3) + pub_r001003_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001003_13_1 * 2) + 15) & 63;
  int stage_v_422_2 = ((pub_r001003_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_223_1 * 3) + pub_r001003_2_1) + 9) & 127;
  int stage_v_423_2 = (((stage_v_223_2 * 3) + pub_r001003_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001003_7_1 * 2) + 20) & 63;
  int stage_v_424_2 = ((pub_r001003_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_244_1 * 3) + pub_r001003_11_1) + 10) & 127;
  int stage_v_425_2 = (((stage_v_244_2 * 3) + pub_r001003_11_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = (((stage_v_313_1 * 3) + pub_r001003_6_1) + 19) & 127;
  int stage_v_426_2 = (((stage_v_313_2 * 3) + pub_r001003_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = ((pub_r001003_15_1 * 2) + 21) & 63;
  int stage_v_427_2 = ((pub_r001003_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001003_11_1 * 2) + 34) & 63;
  int stage_v_428_2 = ((pub_r001003_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_355_1 * 3) + pub_r001003_1_1) + 10) & 127;
  int stage_v_429_2 = (((stage_v_355_2 * 3) + pub_r001003_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001003_12_1 * 2) + 28) & 63;
  int stage_v_430_2 = ((pub_r001003_12_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = (((sec_r001003_10_1 * 3) + pub_r001003_7_1) + 7) & 127;
  int stage_v_431_2 = (((sec_r001003_10_2 * 3) + pub_r001003_7_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_431_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_431_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_431_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_431_2 * 2)) & 255;
  int stage_v_432_1 = ((pub_r001003_8_1 * 2) + 41) & 63;
  int stage_v_432_2 = ((pub_r001003_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((sec_r001003_13_1 * 3) + pub_r001003_11_1) + 20) & 127;
  int stage_v_433_2 = (((sec_r001003_13_2 * 3) + pub_r001003_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001003_11_1 * 2) + 15) & 63;
  int stage_v_434_2 = ((pub_r001003_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001003_11_1 * 2) + 11) & 63;
  int stage_v_435_2 = ((pub_r001003_11_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_161_1 * 3) + pub_r001003_3_1) + 18) & 127;
  int stage_v_436_2 = (((stage_v_161_2 * 3) + pub_r001003_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_68_1 * 3) + pub_r001003_3_1) + 24) & 127;
  int stage_v_437_2 = (((stage_v_68_2 * 3) + pub_r001003_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001003_12_1 * 2) + 22) & 63;
  int stage_v_438_2 = ((pub_r001003_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((stage_v_217_1 * 3) + pub_r001003_5_1) + 23) & 127;
  int stage_v_439_2 = (((stage_v_217_2 * 3) + pub_r001003_5_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = ((pub_r001003_15_1 * 2) + 22) & 63;
  int stage_v_440_2 = ((pub_r001003_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = ((pub_r001003_0_1 * 2) + 41) & 63;
  int stage_v_441_2 = ((pub_r001003_0_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_441_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_441_2) & 127;
  int stage_v_442_1 = (((helper_flow_0_1 * 3) + pub_r001003_4_1) + 12) & 127;
  int stage_v_442_2 = (((helper_flow_0_2 * 3) + pub_r001003_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_266_1 * 3) + pub_r001003_10_1) + 19) & 127;
  int stage_v_443_2 = (((stage_v_266_2 * 3) + pub_r001003_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001003_11_1 * 2) + 12) & 63;
  int stage_v_444_2 = ((pub_r001003_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001003_1_1 * 2) + 43) & 63;
  int stage_v_445_2 = ((pub_r001003_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = (((stage_v_355_1 * 3) + pub_r001003_12_1) + 30) & 127;
  int stage_v_446_2 = (((stage_v_355_2 * 3) + pub_r001003_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_446_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_446_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_446_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_446_2 * 2)) & 255;
  int stage_v_447_1 = (((stage_v_423_1 * 3) + pub_r001003_6_1) + 30) & 127;
  int stage_v_447_2 = (((stage_v_423_2 * 3) + pub_r001003_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_207_1 * 3) + pub_r001003_15_1) + 38) & 127;
  int stage_v_448_2 = (((stage_v_207_2 * 3) + pub_r001003_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = ((pub_r001003_7_1 * 2) + 41) & 63;
  int stage_v_449_2 = ((pub_r001003_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_449_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_449_2) & 127;
  int stage_v_450_1 = (((stage_v_110_1 * 3) + pub_r001003_8_1) + 11) & 127;
  int stage_v_450_2 = (((stage_v_110_2 * 3) + pub_r001003_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_450_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_450_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_450_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_450_2 * 2)) & 255;
  int stage_v_451_1 = ((pub_r001003_4_1 * 2) + 29) & 63;
  int stage_v_451_2 = ((pub_r001003_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_451_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_451_2) & 127;
  int stage_v_452_1 = (((stage_v_18_1 * 3) + pub_r001003_12_1) + 10) & 127;
  int stage_v_452_2 = (((stage_v_18_2 * 3) + pub_r001003_12_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = (((stage_v_263_1 * 3) + pub_r001003_8_1) + 16) & 127;
  int stage_v_453_2 = (((stage_v_263_2 * 3) + pub_r001003_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_453_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_453_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_453_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_453_2 * 2)) & 255;
  int stage_v_454_1 = (((stage_v_84_1 * 3) + pub_r001003_8_1) + 11) & 127;
  int stage_v_454_2 = (((stage_v_84_2 * 3) + pub_r001003_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = ((pub_r001003_10_1 * 2) + 28) & 63;
  int stage_v_455_2 = ((pub_r001003_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_42_1 * 3) + pub_r001003_2_1) + 42) & 127;
  int stage_v_456_2 = (((stage_v_42_2 * 3) + pub_r001003_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001003_12_1 * 2) + 29) & 63;
  int stage_v_457_2 = ((pub_r001003_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = ((pub_r001003_9_1 * 2) + 40) & 63;
  int stage_v_458_2 = ((pub_r001003_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_458_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_458_2) & 127;
  int stage_v_459_1 = (((stage_v_348_1 * 3) + pub_r001003_6_1) + 30) & 127;
  int stage_v_459_2 = (((stage_v_348_2 * 3) + pub_r001003_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_459_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_459_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_459_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_459_2 * 2)) & 255;
  int stage_v_460_1 = ((pub_r001003_7_1 * 2) + 37) & 63;
  int stage_v_460_2 = ((pub_r001003_7_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = ((pub_r001003_5_1 * 2) + 28) & 63;
  int stage_v_461_2 = ((pub_r001003_5_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_461_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_461_2) & 127;
  int stage_v_462_1 = (((sec_r001003_5_1 * 3) + pub_r001003_12_1) + 8) & 127;
  int stage_v_462_2 = (((sec_r001003_5_2 * 3) + pub_r001003_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = (((sec_r001003_20_1 * 3) + pub_r001003_15_1) + 3) & 127;
  int stage_v_463_2 = (((sec_r001003_20_2 * 3) + pub_r001003_15_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_463_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_463_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_463_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_463_2 * 2)) & 255;
  int stage_v_464_1 = (((sec_r001003_17_1 * 3) + pub_r001003_12_1) + 8) & 127;
  int stage_v_464_2 = (((sec_r001003_17_2 * 3) + pub_r001003_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_464_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_464_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_464_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_464_2 * 2)) & 255;
  int stage_v_465_1 = ((pub_r001003_0_1 * 2) + 28) & 63;
  int stage_v_465_2 = ((pub_r001003_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = (((stage_v_342_1 * 3) + pub_r001003_13_1) + 35) & 127;
  int stage_v_466_2 = (((stage_v_342_2 * 3) + pub_r001003_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_466_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_466_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_466_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_466_2 * 2)) & 255;
  int stage_v_467_1 = ((pub_r001003_2_1 * 2) + 5) & 63;
  int stage_v_467_2 = ((pub_r001003_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_467_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_467_2) & 127;
  int stage_v_468_1 = ((pub_r001003_2_1 * 2) + 46) & 63;
  int stage_v_468_2 = ((pub_r001003_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = (((stage_v_466_1 * 3) + pub_r001003_12_1) + 29) & 127;
  int stage_v_469_2 = (((stage_v_466_2 * 3) + pub_r001003_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = ((pub_r001003_13_1 * 2) + 44) & 63;
  int stage_v_470_2 = ((pub_r001003_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_470_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_470_2) & 127;
  int stage_v_471_1 = ((pub_r001003_4_1 * 2) + 33) & 63;
  int stage_v_471_2 = ((pub_r001003_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = (((stage_v_2_1 * 3) + pub_r001003_2_1) + 33) & 127;
  int stage_v_472_2 = (((stage_v_2_2 * 3) + pub_r001003_2_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_472_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_472_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_472_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_472_2 * 2)) & 255;
  int stage_v_473_1 = (((stage_v_242_1 * 3) + pub_r001003_4_1) + 32) & 127;
  int stage_v_473_2 = (((stage_v_242_2 * 3) + pub_r001003_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = ((pub_r001003_4_1 * 2) + 31) & 63;
  int stage_v_474_2 = ((pub_r001003_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_474_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_474_2) & 127;
  int stage_v_475_1 = ((pub_r001003_4_1 * 2) + 12) & 63;
  int stage_v_475_2 = ((pub_r001003_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_475_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_475_2) & 127;
  int stage_v_476_1 = ((pub_r001003_9_1 * 2) + 29) & 63;
  int stage_v_476_2 = ((pub_r001003_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_476_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_476_2) & 127;
  int stage_v_477_1 = ((pub_r001003_10_1 * 2) + 40) & 63;
  int stage_v_477_2 = ((pub_r001003_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_477_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_477_2) & 127;
  int stage_v_478_1 = ((pub_r001003_9_1 * 2) + 32) & 63;
  int stage_v_478_2 = ((pub_r001003_9_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = (((stage_v_245_1 * 3) + pub_r001003_1_1) + 27) & 127;
  int stage_v_479_2 = (((stage_v_245_2 * 3) + pub_r001003_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = (((stage_v_363_1 * 3) + pub_r001003_14_1) + 44) & 127;
  int stage_v_480_2 = (((stage_v_363_2 * 3) + pub_r001003_14_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = (((stage_v_379_1 * 3) + pub_r001003_12_1) + 22) & 127;
  int stage_v_481_2 = (((stage_v_379_2 * 3) + pub_r001003_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_481_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_481_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_481_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_481_2 * 2)) & 255;
  int stage_v_482_1 = ((pub_r001003_6_1 * 2) + 49) & 63;
  int stage_v_482_2 = ((pub_r001003_6_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_482_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_482_2) & 127;
  int stage_v_483_1 = ((pub_r001003_5_1 * 2) + 48) & 63;
  int stage_v_483_2 = ((pub_r001003_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = (((stage_v_78_1 * 3) + pub_r001003_11_1) + 13) & 127;
  int stage_v_484_2 = (((stage_v_78_2 * 3) + pub_r001003_11_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  int stage_v_485_1 = ((pub_r001003_6_1 * 2) + 27) & 63;
  int stage_v_485_2 = ((pub_r001003_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_485_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_485_2) & 127;
  int stage_v_486_1 = (((stage_v_175_1 * 3) + pub_r001003_14_1) + 26) & 127;
  int stage_v_486_2 = (((stage_v_175_2 * 3) + pub_r001003_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_486_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_486_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_486_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_486_2 * 2)) & 255;
  int stage_v_487_1 = ((pub_r001003_1_1 * 2) + 8) & 63;
  int stage_v_487_2 = ((pub_r001003_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = (((stage_v_51_1 * 3) + pub_r001003_3_1) + 34) & 127;
  int stage_v_488_2 = (((stage_v_51_2 * 3) + pub_r001003_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = ((pub_r001003_10_1 * 2) + 28) & 63;
  int stage_v_489_2 = ((pub_r001003_10_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_489_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_489_2) & 127;
  int stage_v_490_1 = ((pub_r001003_5_1 * 2) + 6) & 63;
  int stage_v_490_2 = ((pub_r001003_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_490_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_490_2) & 127;
  int stage_v_491_1 = ((pub_r001003_13_1 * 2) + 46) & 63;
  int stage_v_491_2 = ((pub_r001003_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = (((sec_r001003_12_1 * 3) + pub_r001003_12_1) + 39) & 127;
  int stage_v_492_2 = (((sec_r001003_12_2 * 3) + pub_r001003_12_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_492_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_492_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_492_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_492_2 * 2)) & 255;
  int stage_v_493_1 = (((stage_v_201_1 * 3) + pub_r001003_2_1) + 23) & 127;
  int stage_v_493_2 = (((stage_v_201_2 * 3) + pub_r001003_2_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = ((pub_r001003_7_1 * 2) + 27) & 63;
  int stage_v_494_2 = ((pub_r001003_7_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_494_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_494_2) & 127;
  int stage_v_495_1 = (((stage_v_466_1 * 3) + pub_r001003_0_1) + 20) & 127;
  int stage_v_495_2 = (((stage_v_466_2 * 3) + pub_r001003_0_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_495_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_495_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_495_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_495_2 * 2)) & 255;
  int stage_v_496_1 = ((pub_r001003_7_1 * 2) + 22) & 63;
  int stage_v_496_2 = ((pub_r001003_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_496_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_496_2) & 127;
  int stage_v_497_1 = ((pub_r001003_12_1 * 2) + 47) & 63;
  int stage_v_497_2 = ((pub_r001003_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = ((pub_r001003_4_1 * 2) + 35) & 63;
  int stage_v_498_2 = ((pub_r001003_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_498_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_498_2) & 127;
  int stage_v_499_1 = ((pub_r001003_15_1 * 2) + 18) & 63;
  int stage_v_499_2 = ((pub_r001003_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_499_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_499_2) & 127;
  int stage_v_500_1 = (((stage_v_433_1 * 3) + pub_r001003_2_1) + 16) & 127;
  int stage_v_500_2 = (((stage_v_433_2 * 3) + pub_r001003_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_500_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_500_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_500_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_500_2 * 2)) & 255;
  int stage_v_501_1 = (((stage_v_310_1 * 3) + pub_r001003_10_1) + 24) & 127;
  int stage_v_501_2 = (((stage_v_310_2 * 3) + pub_r001003_10_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_501_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_501_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_501_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_501_2 * 2)) & 255;
  int stage_v_502_1 = ((pub_r001003_0_1 * 2) + 43) & 63;
  int stage_v_502_2 = ((pub_r001003_0_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_502_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_502_2) & 127;
  int stage_v_503_1 = ((pub_r001003_3_1 * 2) + 36) & 63;
  int stage_v_503_2 = ((pub_r001003_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_503_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_503_2) & 127;
  int stage_v_504_1 = (((stage_v_343_1 * 3) + pub_r001003_0_1) + 18) & 127;
  int stage_v_504_2 = (((stage_v_343_2 * 3) + pub_r001003_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_504_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_504_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_504_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_504_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001003_9_1 != sec_r001003_9_2);
  __CPROVER_assume(sec_r001003_5_1 != sec_r001003_5_2);
  __CPROVER_assume(sec_r001003_0_1 != sec_r001003_0_2);
  __CPROVER_assume(sec_r001003_19_1 != sec_r001003_19_2);
  __CPROVER_assume(pub_r001003_7_1 == pub_r001003_7_2);
  __CPROVER_assume(sec_r001003_11_1 != sec_r001003_11_2);
  __CPROVER_assume(pub_r001003_15_1 == pub_r001003_15_2);
  __CPROVER_assume(sec_r001003_21_1 != sec_r001003_21_2);
  __CPROVER_assume(sec_r001003_6_1 != sec_r001003_6_2);
  __CPROVER_assume(pub_r001003_2_1 == pub_r001003_2_2);
  __CPROVER_assume(pub_r001003_12_1 == pub_r001003_12_2);
  __CPROVER_assume(sec_r001003_4_1 != sec_r001003_4_2);
  __CPROVER_assume(sec_r001003_18_1 != sec_r001003_18_2);
  __CPROVER_assume(pub_r001003_0_1 == pub_r001003_0_2);
  __CPROVER_assume(pub_r001003_13_1 == pub_r001003_13_2);
  __CPROVER_assume(pub_r001003_3_1 == pub_r001003_3_2);
  __CPROVER_assume(pub_r001003_10_1 == pub_r001003_10_2);
  __CPROVER_assume(sec_r001003_7_1 != sec_r001003_7_2);
  __CPROVER_assume(pub_r001003_8_1 == pub_r001003_8_2);
  __CPROVER_assume(sec_r001003_15_1 != sec_r001003_15_2);
  __CPROVER_assume(sec_r001003_22_1 != sec_r001003_22_2);
  __CPROVER_assume(sec_r001003_3_1 != sec_r001003_3_2);
  __CPROVER_assume(sec_r001003_17_1 != sec_r001003_17_2);
  __CPROVER_assume(sec_r001003_14_1 != sec_r001003_14_2);
  __CPROVER_assume(sec_r001003_2_1 != sec_r001003_2_2);
  __CPROVER_assume(pub_r001003_4_1 == pub_r001003_4_2);
  __CPROVER_assume(sec_r001003_10_1 != sec_r001003_10_2);
  __CPROVER_assume(pub_r001003_14_1 == pub_r001003_14_2);
  __CPROVER_assume(sec_r001003_16_1 != sec_r001003_16_2);
  __CPROVER_assume(sec_r001003_8_1 != sec_r001003_8_2);
  __CPROVER_assume(sec_r001003_20_1 != sec_r001003_20_2);
  __CPROVER_assume(sec_r001003_12_1 != sec_r001003_12_2);
  __CPROVER_assume(sec_r001003_13_1 != sec_r001003_13_2);
  __CPROVER_assume(pub_r001003_6_1 == pub_r001003_6_2);
  __CPROVER_assume(pub_r001003_9_1 == pub_r001003_9_2);
  __CPROVER_assume(pub_r001003_5_1 == pub_r001003_5_2);
  __CPROVER_assume(pub_r001003_1_1 == pub_r001003_1_2);
  __CPROVER_assume(pub_r001003_11_1 == pub_r001003_11_2);
  __CPROVER_assume(sec_r001003_1_1 != sec_r001003_1_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.watermark == st_var_0_2.watermark);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.state == st_var_0_2.state);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
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

  assert(helper_flow_0_1 == helper_flow_0_2);
  assert(helper_flow_1_1 == helper_flow_1_2);
  assert(helper_flow_2_1 == helper_flow_2_2);
  assert(helper_flow_3_1 == helper_flow_3_2);
  assert(helper_flow_4_1 == helper_flow_4_2);
  assert(helper_flow_5_1 == helper_flow_5_2);
  assert(helper_flow_6_1 == helper_flow_6_2);
  assert(helper_flow_7_1 == helper_flow_7_2);
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
}


