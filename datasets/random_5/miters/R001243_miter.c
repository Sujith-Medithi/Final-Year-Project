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
struct Vector3D_R001243_4313_0
{
  int coord_y;
  short heading;
  int norm_sq;
  int buffer[3];
};
struct SensorNode_R001243_4313_1
{
  int offset;
  unsigned char gain;
  int threshold;
  int buffer[3];
};
union PacketPayload_R001243_4313_0
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
void fn_R001243_4313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int sample_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_87_1)
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

  switch (sample_87_2)
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

  int bound_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_74_1) & 63;
  aux_2 = (aux_2 + bound_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_18_1 = 0;
  int window_18_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_18_1 = ((window_18_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_18_2 = ((window_18_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_18_1) & 127;
    acc_2 = (acc_2 + window_18_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_87_1 == sample_87_2);
  assert(bound_74_1 == bound_74_2);
  assert(window_18_1 == window_18_2);
}

int fn_R001243_4313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int sample_87 = (aux + st.buffer[1]) & 3;
  switch (sample_87)
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

  int bound_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_74) & 63;
  acc ^= aux;
  int window_18 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_18 = ((window_18 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_18) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int quantum_78_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_78_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_78_1)
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

  switch (quantum_78_2)
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

  int coefficient_19_1 = 0;
  int coefficient_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_19_1 = ((coefficient_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_19_2 = ((coefficient_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_19_1) & 127;
    acc_2 = (acc_2 + coefficient_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_45_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_45_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_45_1 > 10)
  {
    acc_1 = ((acc_1 + (bound_45_1 * 2)) + 5) & 127;
    aux_1 ^= bound_45_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_45_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_45_2 > 10)
  {
    acc_2 = ((acc_2 + (bound_45_2 * 2)) + 5) & 127;
    aux_2 ^= bound_45_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_45_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_78_1 == quantum_78_2);
  assert(coefficient_19_1 == coefficient_19_2);
  assert(bound_45_1 == bound_45_2);
}

int fn_R001243_4313_1(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int quantum_78 = (aux + st.buffer[1]) & 3;
  switch (quantum_78)
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

  int coefficient_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_19 = ((coefficient_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_45 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_45 > 10)
  {
    acc = ((acc + (bound_45 * 2)) + 5) & 127;
    aux ^= bound_45 & 15;
  }
  else
  {
    acc = ((acc - bound_45) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001243_4313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_70_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_70_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_70_1) & 63;
  aux_2 = (aux_2 + scale_70_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_59_1 > 25)
  {
    acc_1 = ((acc_1 + (cursor_59_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_59_2 > 25)
  {
    acc_2 = ((acc_2 + (cursor_59_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_59_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_26_1 = 0;
  int metric_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_26_1 = ((metric_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_26_2 = ((metric_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_26_1) & 127;
    acc_2 = (acc_2 + metric_26_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  assert(cursor_59_1 == cursor_59_2);
  assert(metric_26_1 == metric_26_2);
}

int fn_R001243_4313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_70 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_70) & 63;
  acc ^= aux;
  int cursor_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_59 > 25)
  {
    acc = ((acc + (cursor_59 * 2)) + 5) & 127;
    aux ^= cursor_59 & 15;
  }
  else
  {
    acc = ((acc - cursor_59) + 11) & 127;
    aux += 3;
  }
  int metric_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_26 = ((metric_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_26) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001243_4313_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int damping_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_72_1)
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

  switch (damping_72_2)
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

  int damping_47_1 = 0;
  int damping_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_47_1 = ((damping_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_47_2 = ((damping_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_47_1) & 127;
    acc_2 = (acc_2 + damping_47_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_59_1 > 50)
  {
    acc_1 = ((acc_1 + (quotient_59_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_59_2 > 50)
  {
    acc_2 = ((acc_2 + (quotient_59_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_59_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_72_1 == damping_72_2);
  assert(damping_47_1 == damping_47_2);
  assert(quotient_59_1 == quotient_59_2);
}

int fn_R001243_4313_3(int p0, int p1)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int damping_72 = (aux + st.buffer[1]) & 3;
  switch (damping_72)
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

  int damping_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_47 = ((damping_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_47) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_59 > 50)
  {
    acc = ((acc + (quotient_59 * 2)) + 5) & 127;
    aux ^= quotient_59 & 15;
  }
  else
  {
    acc = ((acc - quotient_59) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001243_4313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 46) & 127;
  int acc_2 = (p0_2 + 46) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int quotient_28_1 = 0;
  int quotient_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    quotient_28_1 = ((quotient_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_28_2 = ((quotient_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_28_1) & 127;
    acc_2 = (acc_2 + quotient_28_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_50_1 = local_arr_1[aux_1 % 3];
  int mask_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_50_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_28_1 == quotient_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_50_1 == mask_50_2);
}

int fn_R001243_4313_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 46) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int quotient_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    quotient_28 = ((quotient_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_28) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int mask_50 = local_arr[aux % 3];
  acc = (acc + (mask_50 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_97_1 = 0;
  int delta_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_97_1 = ((delta_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_97_2 = ((delta_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_97_1) & 127;
    acc_2 = (acc_2 + delta_97_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_71_1 = local_arr_1[aux_1 % 3];
  int scale_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_71_2 * 2)) & 127;
  int mask_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_82_1 > 48)
  {
    acc_1 = ((acc_1 + (mask_82_1 * 2)) + 5) & 127;
    aux_1 ^= mask_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_82_2 > 48)
  {
    acc_2 = ((acc_2 + (mask_82_2 * 2)) + 5) & 127;
    aux_2 ^= mask_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_82_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_97_1 == delta_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_71_1 == scale_71_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R001243_4313_5(int p0, int p1)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_97 = ((delta_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_97) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int scale_71 = local_arr[aux % 3];
  acc = (acc + (scale_71 * 2)) & 127;
  int mask_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_82 > 48)
  {
    acc = ((acc + (mask_82 * 2)) + 5) & 127;
    aux ^= mask_82 & 15;
  }
  else
  {
    acc = ((acc - mask_82) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001243_4313_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int pivot_17_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_17_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_17_1 > 48)
  {
    acc_1 = ((acc_1 + (pivot_17_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_17_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_17_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_17_2 > 48)
  {
    acc_2 = ((acc_2 + (pivot_17_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_17_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_17_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_51_1 = local_arr_1[aux_1 % 3];
  int threshold_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_51_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_17_1 == pivot_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_51_1 == threshold_51_2);
}

int fn_R001243_4313_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int pivot_17 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_17 > 48)
  {
    acc = ((acc + (pivot_17 * 2)) + 5) & 127;
    aux ^= pivot_17 & 15;
  }
  else
  {
    acc = ((acc - pivot_17) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int threshold_51 = local_arr[aux % 3];
  acc = (acc + (threshold_51 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int anchor_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_87_1)
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

  switch (anchor_87_2)
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

  int quotient_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_83_1) & 63;
  aux_2 = (aux_2 + quotient_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_44_1 = 0;
  int quantum_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_44_1 = ((quantum_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_44_2 = ((quantum_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_44_1) & 127;
    acc_2 = (acc_2 + quantum_44_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_87_1 == anchor_87_2);
  assert(quotient_83_1 == quotient_83_2);
  assert(quantum_44_1 == quantum_44_2);
}

int fn_R001243_4313_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int anchor_87 = (aux + st.buffer[1]) & 3;
  switch (anchor_87)
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

  int quotient_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_83) & 63;
  acc ^= aux;
  int quantum_44 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_44 = ((quantum_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_44) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001243_4313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_57_1 > 34)
  {
    acc_1 = ((acc_1 + (damping_57_1 * 2)) + 5) & 127;
    aux_1 ^= damping_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_57_2 > 34)
  {
    acc_2 = ((acc_2 + (damping_57_2 * 2)) + 5) & 127;
    aux_2 ^= damping_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_17_1) & 63;
  aux_2 = (aux_2 + metric_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_57_1 == damping_57_2);
  assert(metric_17_1 == metric_17_2);
}

int fn_R001243_4313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_57 > 34)
  {
    acc = ((acc + (damping_57 * 2)) + 5) & 127;
    aux ^= damping_57 & 15;
  }
  else
  {
    acc = ((acc - damping_57) + 11) & 127;
    aux += 3;
  }
  int metric_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001243_4313_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_56_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_56_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_56_1) & 63;
  aux_2 = (aux_2 + pivot_56_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int stride_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_86_1 > 45)
  {
    acc_1 = ((acc_1 + (stride_86_1 * 2)) + 5) & 127;
    aux_1 ^= stride_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_86_2 > 45)
  {
    acc_2 = ((acc_2 + (stride_86_2 * 2)) + 5) & 127;
    aux_2 ^= stride_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_40_1 = local_arr_1[aux_1 % 3];
  int metric_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_40_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_56_1 == pivot_56_2);
  assert(stride_86_1 == stride_86_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_40_1 == metric_40_2);
}

int fn_R001243_4313_9(int p0, int p1)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_56 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_56) & 63;
  acc ^= aux;
  int stride_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_86 > 45)
  {
    acc = ((acc + (stride_86 * 2)) + 5) & 127;
    aux ^= stride_86 & 15;
  }
  else
  {
    acc = ((acc - stride_86) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_40 = local_arr[aux % 3];
  acc = (acc + (metric_40 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_13_1)
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

  switch (bound_13_2)
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

  int delta_80_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_80_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_80_1 > 36)
  {
    acc_1 = ((acc_1 + (delta_80_1 * 2)) + 5) & 127;
    aux_1 ^= delta_80_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_80_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_80_2 > 36)
  {
    acc_2 = ((acc_2 + (delta_80_2 * 2)) + 5) & 127;
    aux_2 ^= delta_80_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_80_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_13_1 == bound_13_2);
  assert(delta_80_1 == delta_80_2);
}

int fn_R001243_4313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_13 = (aux + st.buffer[1]) & 3;
  switch (bound_13)
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

  int delta_80 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_80 > 36)
  {
    acc = ((acc + (delta_80 * 2)) + 5) & 127;
    aux ^= delta_80 & 15;
  }
  else
  {
    acc = ((acc - delta_80) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001243_4313_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int mask_46_1 = 0;
  int mask_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_46_1 = ((mask_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_46_2 = ((mask_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_46_1) & 127;
    acc_2 = (acc_2 + mask_46_2) & 127;
  }

  int coefficient_22_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_22_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_22_1)
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

  switch (coefficient_22_2)
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

  int sample_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_34_1) & 63;
  aux_2 = (aux_2 + sample_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_46_1 == mask_46_2);
  assert(coefficient_22_1 == coefficient_22_2);
  assert(sample_34_1 == sample_34_2);
}

int fn_R001243_4313_11(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int mask_46 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_46 = ((mask_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_46) & 127;
  }

  int coefficient_22 = (aux + st.buffer[1]) & 3;
  switch (coefficient_22)
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

  int sample_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001243_4313_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int checksum_68_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_68_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_68_1) & 63;
  aux_2 = (aux_2 + checksum_68_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_45_1 = local_arr_1[aux_1 % 3];
  int index_reg_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_45_2 * 2)) & 127;
  int tracker_97_1 = 0;
  int tracker_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_97_1 = ((tracker_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_97_2 = ((tracker_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_97_1) & 127;
    acc_2 = (acc_2 + tracker_97_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_68_1 == checksum_68_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_45_1 == index_reg_45_2);
  assert(tracker_97_1 == tracker_97_2);
}

int fn_R001243_4313_12(int p0, int p1, int p2)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int checksum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_68) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_45 = local_arr[aux % 3];
  acc = (acc + (index_reg_45 * 2)) & 127;
  int tracker_97 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_97 = ((tracker_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_97) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int metric_28_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_28_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_28_1) & 63;
  aux_2 = (aux_2 + metric_28_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_97_1 = 0;
  int damping_97_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_97_1 = ((damping_97_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_97_2 = ((damping_97_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_97_1) & 127;
    acc_2 = (acc_2 + damping_97_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_21_1 = local_arr_1[aux_1 % 3];
  int coefficient_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_28_1 == metric_28_2);
  assert(damping_97_1 == damping_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_21_1 == coefficient_21_2);
}

int fn_R001243_4313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int metric_28 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_28) & 63;
  acc ^= aux;
  int damping_97 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_97 = ((damping_97 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_97) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int coefficient_21 = local_arr[aux % 3];
  acc = (acc + (coefficient_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int quantum_16_1 = 0;
  int quantum_16_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_16_1 = ((quantum_16_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_16_2 = ((quantum_16_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_16_1) & 127;
    acc_2 = (acc_2 + quantum_16_2) & 127;
  }

  int pivot_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_74_1) & 63;
  aux_2 = (aux_2 + pivot_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_16_1 == quantum_16_2);
  assert(pivot_74_1 == pivot_74_2);
}

int fn_R001243_4313_14(int p0, int p1)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int quantum_16 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_16 = ((quantum_16 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_16) & 127;
  }

  int pivot_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_74) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001243_4313_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int stride_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_28_1 > 28)
  {
    acc_1 = ((acc_1 + (stride_28_1 * 2)) + 5) & 127;
    aux_1 ^= stride_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_28_2 > 28)
  {
    acc_2 = ((acc_2 + (stride_28_2 * 2)) + 5) & 127;
    aux_2 ^= stride_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_61_1)
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

  switch (bound_61_2)
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
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_28_1 == stride_28_2);
  assert(bound_61_1 == bound_61_2);
}

int fn_R001243_4313_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int stride_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_28 > 28)
  {
    acc = ((acc + (stride_28 * 2)) + 5) & 127;
    aux ^= stride_28 & 15;
  }
  else
  {
    acc = ((acc - stride_28) + 11) & 127;
    aux += 3;
  }
  int bound_61 = (aux + st.buffer[1]) & 3;
  switch (bound_61)
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

void fn_R001243_4313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int quotient_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_17_1) & 63;
  aux_2 = (aux_2 + quotient_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_72_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_72_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_72_1 > 48)
  {
    acc_1 = ((acc_1 + (bound_72_1 * 2)) + 5) & 127;
    aux_1 ^= bound_72_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_72_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_72_2 > 48)
  {
    acc_2 = ((acc_2 + (bound_72_2 * 2)) + 5) & 127;
    aux_2 ^= bound_72_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_72_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_93_1 = local_arr_1[aux_1 % 3];
  int segment_93_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_93_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_93_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_17_1 == quotient_17_2);
  assert(bound_72_1 == bound_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_93_1 == segment_93_2);
}

int fn_R001243_4313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int quotient_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_17) & 63;
  acc ^= aux;
  int bound_72 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_72 > 48)
  {
    acc = ((acc + (bound_72 * 2)) + 5) & 127;
    aux ^= bound_72 & 15;
  }
  else
  {
    acc = ((acc - bound_72) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int segment_93 = local_arr[aux % 3];
  acc = (acc + (segment_93 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st_1 = {0};
  struct SensorNode_R001243_4313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int stride_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_90_1 > 43)
  {
    acc_1 = ((acc_1 + (stride_90_1 * 2)) + 5) & 127;
    aux_1 ^= stride_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_90_2 > 43)
  {
    acc_2 = ((acc_2 + (stride_90_2 * 2)) + 5) & 127;
    aux_2 ^= stride_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_95_1 = local_arr_1[aux_1 % 3];
  int sample_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_95_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.offset == st_2.offset);
  assert(st_1.gain == st_2.gain);
  assert(st_1.threshold == st_2.threshold);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_90_1 == stride_90_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_95_1 == sample_95_2);
}

int fn_R001243_4313_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001243_4313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int stride_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_90 > 43)
  {
    acc = ((acc + (stride_90 * 2)) + 5) & 127;
    aux ^= stride_90 & 15;
  }
  else
  {
    acc = ((acc - stride_90) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_95 = local_arr[aux % 3];
  acc = (acc + (sample_95 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001243_4313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int accumulator_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_76_1)
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

  switch (accumulator_76_2)
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

  int residue_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_24_1) & 63;
  aux_2 = (aux_2 + residue_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_76_1 == accumulator_76_2);
  assert(residue_24_1 == residue_24_2);
}

int fn_R001243_4313_18(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int accumulator_76 = (aux + st.buffer[1]) & 3;
  switch (accumulator_76)
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

  int residue_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001243_4313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int accumulator_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_99_1 > 25)
  {
    acc_1 = ((acc_1 + (accumulator_99_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_99_2 > 25)
  {
    acc_2 = ((acc_2 + (accumulator_99_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_99_2) + 11) & 127;
    aux_2 += 3;
  }
  int factor_44_1 = 0;
  int factor_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_44_1 = ((factor_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_44_2 = ((factor_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_44_1) & 127;
    acc_2 = (acc_2 + factor_44_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_71_1 = local_arr_1[aux_1 % 3];
  int accumulator_71_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_71_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_71_2 * 2)) & 127;
  int stride_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_60_1) & 63;
  aux_2 = (aux_2 + stride_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_99_1 == accumulator_99_2);
  assert(factor_44_1 == factor_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_71_1 == accumulator_71_2);
  assert(stride_60_1 == stride_60_2);
}

int fn_R001243_4313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int accumulator_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_99 > 25)
  {
    acc = ((acc + (accumulator_99 * 2)) + 5) & 127;
    aux ^= accumulator_99 & 15;
  }
  else
  {
    acc = ((acc - accumulator_99) + 11) & 127;
    aux += 3;
  }
  int factor_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_44 = ((factor_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_44) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int accumulator_71 = local_arr[aux % 3];
  acc = (acc + (accumulator_71 * 2)) & 127;
  int stride_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_60) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001243_4313_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st_1 = {0};
  struct Vector3D_R001243_4313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int sample_30_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_30_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_30_1)
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

  switch (sample_30_2)
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
  int tally_61_1 = local_arr_1[aux_1 % 3];
  int tally_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_61_2 * 2)) & 127;
  int residue_85_1 = 0;
  int residue_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_85_1 = ((residue_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_85_2 = ((residue_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_85_1) & 127;
    acc_2 = (acc_2 + residue_85_2) & 127;
  }

  int anchor_12_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_12_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_12_1 > 25)
  {
    acc_1 = ((acc_1 + (anchor_12_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_12_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_12_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_12_2 > 25)
  {
    acc_2 = ((acc_2 + (anchor_12_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_12_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_12_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_30_1 == sample_30_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_61_1 == tally_61_2);
  assert(residue_85_1 == residue_85_2);
  assert(anchor_12_1 == anchor_12_2);
}

int fn_R001243_4313_20(int p0, int p1)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001243_4313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int sample_30 = (aux + st.buffer[1]) & 3;
  switch (sample_30)
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
  int tally_61 = local_arr[aux % 3];
  acc = (acc + (tally_61 * 2)) & 127;
  int residue_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_85 = ((residue_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_85) & 127;
  }

  int anchor_12 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_12 > 25)
  {
    acc = ((acc + (anchor_12 * 2)) + 5) & 127;
    aux ^= anchor_12 & 15;
  }
  else
  {
    acc = ((acc - anchor_12) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001243_0_1;
  int sec_r001243_0_2;
  int sec_r001243_1_1;
  int sec_r001243_1_2;
  int sec_r001243_2_1;
  int sec_r001243_2_2;
  int sec_r001243_3_1;
  int sec_r001243_3_2;
  int sec_r001243_4_1;
  int sec_r001243_4_2;
  int sec_r001243_5_1;
  int sec_r001243_5_2;
  int sec_r001243_6_1;
  int sec_r001243_6_2;
  int sec_r001243_7_1;
  int sec_r001243_7_2;
  int sec_r001243_8_1;
  int sec_r001243_8_2;
  int sec_r001243_9_1;
  int sec_r001243_9_2;
  int sec_r001243_10_1;
  int sec_r001243_10_2;
  int sec_r001243_11_1;
  int sec_r001243_11_2;
  int sec_r001243_12_1;
  int sec_r001243_12_2;
  int sec_r001243_13_1;
  int sec_r001243_13_2;
  int sec_r001243_14_1;
  int sec_r001243_14_2;
  int sec_r001243_15_1;
  int sec_r001243_15_2;
  int pub_r001243_0_1;
  int pub_r001243_0_2;
  int pub_r001243_1_1;
  int pub_r001243_1_2;
  int pub_r001243_2_1;
  int pub_r001243_2_2;
  int pub_r001243_3_1;
  int pub_r001243_3_2;
  int pub_r001243_4_1;
  int pub_r001243_4_2;
  int pub_r001243_5_1;
  int pub_r001243_5_2;
  int pub_r001243_6_1;
  int pub_r001243_6_2;
  int pub_r001243_7_1;
  int pub_r001243_7_2;
  int pub_r001243_8_1;
  int pub_r001243_8_2;
  int pub_r001243_9_1;
  int pub_r001243_9_2;
  int pub_r001243_10_1;
  int pub_r001243_10_2;
  int pub_r001243_11_1;
  int pub_r001243_11_2;
  int pub_r001243_12_1;
  int pub_r001243_12_2;
  int pub_r001243_13_1;
  int pub_r001243_13_2;
  int pub_r001243_14_1;
  int pub_r001243_14_2;
  int pub_r001243_15_1;
  int pub_r001243_15_2;
  int pub_r001243_16_1;
  int pub_r001243_16_2;
  int pub_r001243_17_1;
  int pub_r001243_17_2;
  int pub_r001243_18_1;
  int pub_r001243_18_2;
  int pub_r001243_19_1;
  int pub_r001243_19_2;
  int pub_r001243_20_1;
  int pub_r001243_20_2;
  int pub_r001243_21_1;
  int pub_r001243_21_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001243_0_1 >= (-100)) && (pub_r001243_0_1 <= 100));
  __CPROVER_assume((pub_r001243_0_2 >= (-100)) && (pub_r001243_0_2 <= 100));
  __CPROVER_assume((pub_r001243_1_1 >= (-100)) && (pub_r001243_1_1 <= 100));
  __CPROVER_assume((pub_r001243_1_2 >= (-100)) && (pub_r001243_1_2 <= 100));
  __CPROVER_assume((pub_r001243_2_1 >= (-100)) && (pub_r001243_2_1 <= 100));
  __CPROVER_assume((pub_r001243_2_2 >= (-100)) && (pub_r001243_2_2 <= 100));
  __CPROVER_assume((pub_r001243_3_1 >= (-100)) && (pub_r001243_3_1 <= 100));
  __CPROVER_assume((pub_r001243_3_2 >= (-100)) && (pub_r001243_3_2 <= 100));
  __CPROVER_assume((pub_r001243_4_1 >= (-100)) && (pub_r001243_4_1 <= 100));
  __CPROVER_assume((pub_r001243_4_2 >= (-100)) && (pub_r001243_4_2 <= 100));
  __CPROVER_assume((pub_r001243_5_1 >= (-100)) && (pub_r001243_5_1 <= 100));
  __CPROVER_assume((pub_r001243_5_2 >= (-100)) && (pub_r001243_5_2 <= 100));
  __CPROVER_assume((pub_r001243_6_1 >= (-100)) && (pub_r001243_6_1 <= 100));
  __CPROVER_assume((pub_r001243_6_2 >= (-100)) && (pub_r001243_6_2 <= 100));
  __CPROVER_assume((pub_r001243_7_1 >= (-100)) && (pub_r001243_7_1 <= 100));
  __CPROVER_assume((pub_r001243_7_2 >= (-100)) && (pub_r001243_7_2 <= 100));
  __CPROVER_assume((pub_r001243_8_1 >= (-100)) && (pub_r001243_8_1 <= 100));
  __CPROVER_assume((pub_r001243_8_2 >= (-100)) && (pub_r001243_8_2 <= 100));
  __CPROVER_assume((pub_r001243_9_1 >= (-100)) && (pub_r001243_9_1 <= 100));
  __CPROVER_assume((pub_r001243_9_2 >= (-100)) && (pub_r001243_9_2 <= 100));
  __CPROVER_assume((pub_r001243_10_1 >= (-100)) && (pub_r001243_10_1 <= 100));
  __CPROVER_assume((pub_r001243_10_2 >= (-100)) && (pub_r001243_10_2 <= 100));
  __CPROVER_assume((pub_r001243_11_1 >= (-100)) && (pub_r001243_11_1 <= 100));
  __CPROVER_assume((pub_r001243_11_2 >= (-100)) && (pub_r001243_11_2 <= 100));
  __CPROVER_assume((pub_r001243_12_1 >= (-100)) && (pub_r001243_12_1 <= 100));
  __CPROVER_assume((pub_r001243_12_2 >= (-100)) && (pub_r001243_12_2 <= 100));
  __CPROVER_assume((pub_r001243_13_1 >= (-100)) && (pub_r001243_13_1 <= 100));
  __CPROVER_assume((pub_r001243_13_2 >= (-100)) && (pub_r001243_13_2 <= 100));
  __CPROVER_assume((pub_r001243_14_1 >= (-100)) && (pub_r001243_14_1 <= 100));
  __CPROVER_assume((pub_r001243_14_2 >= (-100)) && (pub_r001243_14_2 <= 100));
  __CPROVER_assume((pub_r001243_15_1 >= (-100)) && (pub_r001243_15_1 <= 100));
  __CPROVER_assume((pub_r001243_15_2 >= (-100)) && (pub_r001243_15_2 <= 100));
  __CPROVER_assume((pub_r001243_16_1 >= (-100)) && (pub_r001243_16_1 <= 100));
  __CPROVER_assume((pub_r001243_16_2 >= (-100)) && (pub_r001243_16_2 <= 100));
  __CPROVER_assume((pub_r001243_17_1 >= (-100)) && (pub_r001243_17_1 <= 100));
  __CPROVER_assume((pub_r001243_17_2 >= (-100)) && (pub_r001243_17_2 <= 100));
  __CPROVER_assume((pub_r001243_18_1 >= (-100)) && (pub_r001243_18_1 <= 100));
  __CPROVER_assume((pub_r001243_18_2 >= (-100)) && (pub_r001243_18_2 <= 100));
  __CPROVER_assume((pub_r001243_19_1 >= (-100)) && (pub_r001243_19_1 <= 100));
  __CPROVER_assume((pub_r001243_19_2 >= (-100)) && (pub_r001243_19_2 <= 100));
  __CPROVER_assume((pub_r001243_20_1 >= (-100)) && (pub_r001243_20_1 <= 100));
  __CPROVER_assume((pub_r001243_20_2 >= (-100)) && (pub_r001243_20_2 <= 100));
  __CPROVER_assume((pub_r001243_21_1 >= (-100)) && (pub_r001243_21_1 <= 100));
  __CPROVER_assume((pub_r001243_21_2 >= (-100)) && (pub_r001243_21_2 <= 100));
  __CPROVER_assume((sec_r001243_0_1 >= 0) && (sec_r001243_0_1 <= 255));
  __CPROVER_assume((sec_r001243_0_2 >= 0) && (sec_r001243_0_2 <= 255));
  __CPROVER_assume((sec_r001243_1_1 >= 0) && (sec_r001243_1_1 <= 255));
  __CPROVER_assume((sec_r001243_1_2 >= 0) && (sec_r001243_1_2 <= 255));
  __CPROVER_assume((sec_r001243_2_1 >= 0) && (sec_r001243_2_1 <= 255));
  __CPROVER_assume((sec_r001243_2_2 >= 0) && (sec_r001243_2_2 <= 255));
  __CPROVER_assume((sec_r001243_3_1 >= 0) && (sec_r001243_3_1 <= 255));
  __CPROVER_assume((sec_r001243_3_2 >= 0) && (sec_r001243_3_2 <= 255));
  __CPROVER_assume((sec_r001243_4_1 >= 0) && (sec_r001243_4_1 <= 255));
  __CPROVER_assume((sec_r001243_4_2 >= 0) && (sec_r001243_4_2 <= 255));
  __CPROVER_assume((sec_r001243_5_1 >= 0) && (sec_r001243_5_1 <= 255));
  __CPROVER_assume((sec_r001243_5_2 >= 0) && (sec_r001243_5_2 <= 255));
  __CPROVER_assume((sec_r001243_6_1 >= 0) && (sec_r001243_6_1 <= 255));
  __CPROVER_assume((sec_r001243_6_2 >= 0) && (sec_r001243_6_2 <= 255));
  __CPROVER_assume((sec_r001243_7_1 >= 0) && (sec_r001243_7_1 <= 255));
  __CPROVER_assume((sec_r001243_7_2 >= 0) && (sec_r001243_7_2 <= 255));
  __CPROVER_assume((sec_r001243_8_1 >= 0) && (sec_r001243_8_1 <= 255));
  __CPROVER_assume((sec_r001243_8_2 >= 0) && (sec_r001243_8_2 <= 255));
  __CPROVER_assume((sec_r001243_9_1 >= 0) && (sec_r001243_9_1 <= 255));
  __CPROVER_assume((sec_r001243_9_2 >= 0) && (sec_r001243_9_2 <= 255));
  __CPROVER_assume((sec_r001243_10_1 >= 0) && (sec_r001243_10_1 <= 255));
  __CPROVER_assume((sec_r001243_10_2 >= 0) && (sec_r001243_10_2 <= 255));
  __CPROVER_assume((sec_r001243_11_1 >= 0) && (sec_r001243_11_1 <= 255));
  __CPROVER_assume((sec_r001243_11_2 >= 0) && (sec_r001243_11_2 <= 255));
  __CPROVER_assume((sec_r001243_12_1 >= 0) && (sec_r001243_12_1 <= 255));
  __CPROVER_assume((sec_r001243_12_2 >= 0) && (sec_r001243_12_2 <= 255));
  __CPROVER_assume((sec_r001243_13_1 >= 0) && (sec_r001243_13_1 <= 255));
  __CPROVER_assume((sec_r001243_13_2 >= 0) && (sec_r001243_13_2 <= 255));
  __CPROVER_assume((sec_r001243_14_1 >= 0) && (sec_r001243_14_1 <= 255));
  __CPROVER_assume((sec_r001243_14_2 >= 0) && (sec_r001243_14_2 <= 255));
  __CPROVER_assume((sec_r001243_15_1 >= 0) && (sec_r001243_15_1 <= 255));
  __CPROVER_assume((sec_r001243_15_2 >= 0) && (sec_r001243_15_2 <= 255));
  struct Vector3D_R001243_4313_0 st_var_0_1 = {0};
  struct Vector3D_R001243_4313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001243_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001243_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001243_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001243_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001243_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001243_0_2 + 7) & 15;
  struct SensorNode_R001243_4313_1 st_var_1_1 = {0};
  struct SensorNode_R001243_4313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001243_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001243_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001243_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001243_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001243_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001243_0_2 + 9) & 15;
  union PacketPayload_R001243_4313_0 u_var_1;
  union PacketPayload_R001243_4313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001243_4313_0(sec_r001243_0_1, pub_r001243_1_1, pub_r001243_2_1);
  int helper_flow_0_2 = fn_R001243_4313_0(sec_r001243_0_2, pub_r001243_1_2, pub_r001243_2_2);
  fn_R001243_4313_0_2(sec_r001243_0_1, pub_r001243_1_1, pub_r001243_2_1, sec_r001243_0_2, pub_r001243_1_2, pub_r001243_2_2);
  int helper_flow_1_1 = fn_R001243_4313_1(sec_r001243_1_1, sec_r001243_2_1);
  int helper_flow_1_2 = fn_R001243_4313_1(sec_r001243_1_2, sec_r001243_2_2);
  fn_R001243_4313_1_2(sec_r001243_1_1, sec_r001243_2_1, sec_r001243_1_2, sec_r001243_2_2);
  int helper_flow_2_1 = fn_R001243_4313_2(sec_r001243_2_1, pub_r001243_3_1, pub_r001243_4_1, pub_r001243_5_1, pub_r001243_6_1);
  int helper_flow_2_2 = fn_R001243_4313_2(sec_r001243_2_2, pub_r001243_3_2, pub_r001243_4_2, pub_r001243_5_2, pub_r001243_6_2);
  fn_R001243_4313_2_2(sec_r001243_2_1, pub_r001243_3_1, pub_r001243_4_1, pub_r001243_5_1, pub_r001243_6_1, sec_r001243_2_2, pub_r001243_3_2, pub_r001243_4_2, pub_r001243_5_2, pub_r001243_6_2);
  int helper_flow_3_1 = fn_R001243_4313_3(sec_r001243_3_1, pub_r001243_4_1);
  int helper_flow_3_2 = fn_R001243_4313_3(sec_r001243_3_2, pub_r001243_4_2);
  fn_R001243_4313_3_2(sec_r001243_3_1, pub_r001243_4_1, sec_r001243_3_2, pub_r001243_4_2);
  int helper_flow_4_1 = fn_R001243_4313_4(sec_r001243_4_1, pub_r001243_5_1, pub_r001243_6_1, pub_r001243_7_1, pub_r001243_8_1);
  int helper_flow_4_2 = fn_R001243_4313_4(sec_r001243_4_2, pub_r001243_5_2, pub_r001243_6_2, pub_r001243_7_2, pub_r001243_8_2);
  fn_R001243_4313_4_2(sec_r001243_4_1, pub_r001243_5_1, pub_r001243_6_1, pub_r001243_7_1, pub_r001243_8_1, sec_r001243_4_2, pub_r001243_5_2, pub_r001243_6_2, pub_r001243_7_2, pub_r001243_8_2);
  int stage_v_0_1 = (((helper_flow_3_1 * 3) + pub_r001243_10_1) + 37) & 127;
  int stage_v_0_2 = (((helper_flow_3_2 * 3) + pub_r001243_10_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001243_1_1 * 2) + 7) & 63;
  int stage_v_1_2 = ((pub_r001243_1_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001243_9_1 * 3) + pub_r001243_7_1) + 29) & 127;
  int stage_v_2_2 = (((sec_r001243_9_2 * 3) + pub_r001243_7_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001243_7_1 * 2) + 38) & 63;
  int stage_v_3_2 = ((pub_r001243_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001243_9_1 * 3) + pub_r001243_11_1) + 39) & 127;
  int stage_v_4_2 = (((sec_r001243_9_2 * 3) + pub_r001243_11_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001243_15_1 * 2) + 50) & 63;
  int stage_v_5_2 = ((pub_r001243_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = (((sec_r001243_14_1 * 3) + pub_r001243_0_1) + 12) & 127;
  int stage_v_6_2 = (((sec_r001243_14_2 * 3) + pub_r001243_0_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_6_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_6_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_6_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_6_2 * 2)) & 255;
  int stage_v_7_1 = ((pub_r001243_14_1 * 2) + 25) & 63;
  int stage_v_7_2 = ((pub_r001243_14_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001243_11_1 * 3) + pub_r001243_9_1) + 12) & 127;
  int stage_v_8_2 = (((sec_r001243_11_2 * 3) + pub_r001243_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001243_13_1 * 2) + 13) & 63;
  int stage_v_9_2 = ((pub_r001243_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((stage_v_2_1 * 3) + pub_r001243_21_1) + 42) & 127;
  int stage_v_10_2 = (((stage_v_2_2 * 3) + pub_r001243_21_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001243_3_1 * 2) + 37) & 63;
  int stage_v_11_2 = ((pub_r001243_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((sec_r001243_9_1 * 3) + pub_r001243_19_1) + 10) & 127;
  int stage_v_12_2 = (((sec_r001243_9_2 * 3) + pub_r001243_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001243_3_1 * 2) + 8) & 63;
  int stage_v_13_2 = ((pub_r001243_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001243_1_1 * 2) + 6) & 63;
  int stage_v_14_2 = ((pub_r001243_1_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001243_2_1 * 3) + pub_r001243_2_1) + 16) & 127;
  int stage_v_15_2 = (((sec_r001243_2_2 * 3) + pub_r001243_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001243_1_1 * 2) + 29) & 63;
  int stage_v_16_2 = ((pub_r001243_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001243_7_1 * 2) + 44) & 63;
  int stage_v_17_2 = ((pub_r001243_7_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((helper_flow_2_1 * 3) + pub_r001243_8_1) + 10) & 127;
  int stage_v_18_2 = (((helper_flow_2_2 * 3) + pub_r001243_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001243_10_1 * 2) + 12) & 63;
  int stage_v_19_2 = ((pub_r001243_10_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001243_1_1 * 3) + pub_r001243_18_1) + 43) & 127;
  int stage_v_20_2 = (((sec_r001243_1_2 * 3) + pub_r001243_18_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001243_19_1 * 2) + 5) & 63;
  int stage_v_21_2 = ((pub_r001243_19_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001243_8_1 * 2) + 48) & 63;
  int stage_v_22_2 = ((pub_r001243_8_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001243_8_1 * 2) + 19) & 63;
  int stage_v_23_2 = ((pub_r001243_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001243_2_1 * 2) + 32) & 63;
  int stage_v_24_2 = ((pub_r001243_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001243_20_1 * 2) + 34) & 63;
  int stage_v_25_2 = ((pub_r001243_20_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001243_3_1 * 3) + pub_r001243_0_1) + 14) & 127;
  int stage_v_26_2 = (((sec_r001243_3_2 * 3) + pub_r001243_0_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001243_1_1 * 2) + 49) & 63;
  int stage_v_27_2 = ((pub_r001243_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = ((pub_r001243_5_1 * 2) + 32) & 63;
  int stage_v_28_2 = ((pub_r001243_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001243_0_1 * 2) + 13) & 63;
  int stage_v_29_2 = ((pub_r001243_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001243_2_1 * 2) + 16) & 63;
  int stage_v_30_2 = ((pub_r001243_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001243_3_1 * 3) + pub_r001243_10_1) + 12) & 127;
  int stage_v_31_2 = (((sec_r001243_3_2 * 3) + pub_r001243_10_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001243_7_1 * 2) + 17) & 63;
  int stage_v_32_2 = ((pub_r001243_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = (((stage_v_18_1 * 3) + pub_r001243_21_1) + 9) & 127;
  int stage_v_33_2 = (((stage_v_18_2 * 3) + pub_r001243_21_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((sec_r001243_12_1 * 3) + pub_r001243_13_1) + 38) & 127;
  int stage_v_34_2 = (((sec_r001243_12_2 * 3) + pub_r001243_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001243_12_1 * 2) + 49) & 63;
  int stage_v_35_2 = ((pub_r001243_12_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001243_7_1 * 2) + 31) & 63;
  int stage_v_36_2 = ((pub_r001243_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((stage_v_2_1 * 3) + pub_r001243_13_1) + 35) & 127;
  int stage_v_37_2 = (((stage_v_2_2 * 3) + pub_r001243_13_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001243_13_1 * 2) + 18) & 63;
  int stage_v_38_2 = ((pub_r001243_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001243_6_1 * 2) + 48) & 63;
  int stage_v_39_2 = ((pub_r001243_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((stage_v_12_1 * 3) + pub_r001243_11_1) + 27) & 127;
  int stage_v_40_2 = (((stage_v_12_2 * 3) + pub_r001243_11_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((sec_r001243_5_1 * 3) + pub_r001243_0_1) + 26) & 127;
  int stage_v_41_2 = (((sec_r001243_5_2 * 3) + pub_r001243_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((stage_v_0_1 * 3) + pub_r001243_21_1) + 30) & 127;
  int stage_v_42_2 = (((stage_v_0_2 * 3) + pub_r001243_21_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = (((helper_flow_2_1 * 3) + pub_r001243_6_1) + 24) & 127;
  int stage_v_43_2 = (((helper_flow_2_2 * 3) + pub_r001243_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_43_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_43_2 * 2)) & 255;
  int stage_v_44_1 = ((pub_r001243_8_1 * 2) + 13) & 63;
  int stage_v_44_2 = ((pub_r001243_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((sec_r001243_2_1 * 3) + pub_r001243_11_1) + 7) & 127;
  int stage_v_45_2 = (((sec_r001243_2_2 * 3) + pub_r001243_11_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((sec_r001243_6_1 * 3) + pub_r001243_9_1) + 38) & 127;
  int stage_v_46_2 = (((sec_r001243_6_2 * 3) + pub_r001243_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001243_21_1 * 2) + 34) & 63;
  int stage_v_47_2 = ((pub_r001243_21_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = (((stage_v_8_1 * 3) + pub_r001243_21_1) + 13) & 127;
  int stage_v_48_2 = (((stage_v_8_2 * 3) + pub_r001243_21_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_48_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_48_2 * 2)) & 255;
  int stage_v_49_1 = (((stage_v_42_1 * 3) + pub_r001243_13_1) + 11) & 127;
  int stage_v_49_2 = (((stage_v_42_2 * 3) + pub_r001243_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001243_8_1 * 2) + 38) & 63;
  int stage_v_50_2 = ((pub_r001243_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((sec_r001243_12_1 * 3) + pub_r001243_5_1) + 21) & 127;
  int stage_v_51_2 = (((sec_r001243_12_2 * 3) + pub_r001243_5_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001243_5_1 * 2) + 30) & 63;
  int stage_v_52_2 = ((pub_r001243_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = (((stage_v_45_1 * 3) + pub_r001243_3_1) + 43) & 127;
  int stage_v_53_2 = (((stage_v_45_2 * 3) + pub_r001243_3_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_53_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_53_2 * 2)) & 255;
  int stage_v_54_1 = (((stage_v_26_1 * 3) + pub_r001243_1_1) + 42) & 127;
  int stage_v_54_2 = (((stage_v_26_2 * 3) + pub_r001243_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = (((stage_v_15_1 * 3) + pub_r001243_14_1) + 20) & 127;
  int stage_v_55_2 = (((stage_v_15_2 * 3) + pub_r001243_14_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = (((sec_r001243_8_1 * 3) + pub_r001243_5_1) + 42) & 127;
  int stage_v_56_2 = (((sec_r001243_8_2 * 3) + pub_r001243_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001243_11_1 * 3) + pub_r001243_6_1) + 19) & 127;
  int stage_v_57_2 = (((sec_r001243_11_2 * 3) + pub_r001243_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((sec_r001243_12_1 * 3) + pub_r001243_0_1) + 8) & 127;
  int stage_v_58_2 = (((sec_r001243_12_2 * 3) + pub_r001243_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = ((pub_r001243_0_1 * 2) + 11) & 63;
  int stage_v_59_2 = ((pub_r001243_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001243_4_1 * 2) + 20) & 63;
  int stage_v_60_2 = ((pub_r001243_4_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((sec_r001243_12_1 * 3) + pub_r001243_8_1) + 23) & 127;
  int stage_v_61_2 = (((sec_r001243_12_2 * 3) + pub_r001243_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001243_3_1 * 2) + 23) & 63;
  int stage_v_62_2 = ((pub_r001243_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = ((pub_r001243_9_1 * 2) + 7) & 63;
  int stage_v_63_2 = ((pub_r001243_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001243_8_1 * 2) + 22) & 63;
  int stage_v_64_2 = ((pub_r001243_8_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_10_1 * 3) + pub_r001243_7_1) + 27) & 127;
  int stage_v_65_2 = (((stage_v_10_2 * 3) + pub_r001243_7_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001243_7_1 * 2) + 10) & 63;
  int stage_v_66_2 = ((pub_r001243_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001243_2_1 * 2) + 5) & 63;
  int stage_v_67_2 = ((pub_r001243_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = (((stage_v_53_1 * 3) + pub_r001243_20_1) + 42) & 127;
  int stage_v_68_2 = (((stage_v_53_2 * 3) + pub_r001243_20_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((stage_v_33_1 * 3) + pub_r001243_4_1) + 39) & 127;
  int stage_v_69_2 = (((stage_v_33_2 * 3) + pub_r001243_4_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((stage_v_69_1 * 3) + pub_r001243_10_1) + 5) & 127;
  int stage_v_70_2 = (((stage_v_69_2 * 3) + pub_r001243_10_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001243_18_1 * 2) + 36) & 63;
  int stage_v_71_2 = ((pub_r001243_18_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001243_4_1 * 2) + 46) & 63;
  int stage_v_72_2 = ((pub_r001243_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001243_8_1 * 2) + 16) & 63;
  int stage_v_73_2 = ((pub_r001243_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = (((sec_r001243_14_1 * 3) + pub_r001243_20_1) + 10) & 127;
  int stage_v_74_2 = (((sec_r001243_14_2 * 3) + pub_r001243_20_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_74_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_74_2 * 2)) & 255;
  int stage_v_75_1 = (((stage_v_8_1 * 3) + pub_r001243_6_1) + 25) & 127;
  int stage_v_75_2 = (((stage_v_8_2 * 3) + pub_r001243_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001243_10_1 * 2) + 41) & 63;
  int stage_v_76_2 = ((pub_r001243_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001243_18_1 * 2) + 8) & 63;
  int stage_v_77_2 = ((pub_r001243_18_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((sec_r001243_6_1 * 3) + pub_r001243_4_1) + 14) & 127;
  int stage_v_78_2 = (((sec_r001243_6_2 * 3) + pub_r001243_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = (((sec_r001243_13_1 * 3) + pub_r001243_3_1) + 16) & 127;
  int stage_v_79_2 = (((sec_r001243_13_2 * 3) + pub_r001243_3_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_79_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_79_2 * 2)) & 255;
  int stage_v_80_1 = ((pub_r001243_9_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001243_9_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001243_17_1 * 2) + 41) & 63;
  int stage_v_81_2 = ((pub_r001243_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_75_1 * 3) + pub_r001243_20_1) + 8) & 127;
  int stage_v_82_2 = (((stage_v_75_2 * 3) + pub_r001243_20_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((sec_r001243_11_1 * 3) + pub_r001243_6_1) + 14) & 127;
  int stage_v_83_2 = (((sec_r001243_11_2 * 3) + pub_r001243_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = (((stage_v_31_1 * 3) + pub_r001243_12_1) + 8) & 127;
  int stage_v_84_2 = (((stage_v_31_2 * 3) + pub_r001243_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = (((sec_r001243_2_1 * 3) + pub_r001243_0_1) + 26) & 127;
  int stage_v_85_2 = (((sec_r001243_2_2 * 3) + pub_r001243_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_85_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_85_2 * 2)) & 255;
  int stage_v_86_1 = ((pub_r001243_21_1 * 2) + 28) & 63;
  int stage_v_86_2 = ((pub_r001243_21_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_86_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_86_2) & 127;
  int stage_v_87_1 = ((pub_r001243_17_1 * 2) + 9) & 63;
  int stage_v_87_2 = ((pub_r001243_17_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_0_1 * 3) + pub_r001243_13_1) + 22) & 127;
  int stage_v_88_2 = (((stage_v_0_2 * 3) + pub_r001243_13_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001243_2_1 * 2) + 48) & 63;
  int stage_v_89_2 = ((pub_r001243_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_34_1 * 3) + pub_r001243_15_1) + 24) & 127;
  int stage_v_90_2 = (((stage_v_34_2 * 3) + pub_r001243_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001243_13_1 * 2) + 22) & 63;
  int stage_v_91_2 = ((pub_r001243_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001243_16_1 * 2) + 33) & 63;
  int stage_v_92_2 = ((pub_r001243_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((stage_v_54_1 * 3) + pub_r001243_1_1) + 22) & 127;
  int stage_v_93_2 = (((stage_v_54_2 * 3) + pub_r001243_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001243_16_1 * 2) + 44) & 63;
  int stage_v_94_2 = ((pub_r001243_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = (((helper_flow_3_1 * 3) + pub_r001243_5_1) + 30) & 127;
  int stage_v_95_2 = (((helper_flow_3_2 * 3) + pub_r001243_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_95_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_95_2 * 2)) & 255;
  int stage_v_96_1 = ((pub_r001243_12_1 * 2) + 25) & 63;
  int stage_v_96_2 = ((pub_r001243_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((stage_v_56_1 * 3) + pub_r001243_13_1) + 7) & 127;
  int stage_v_97_2 = (((stage_v_56_2 * 3) + pub_r001243_13_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = ((pub_r001243_17_1 * 2) + 41) & 63;
  int stage_v_98_2 = ((pub_r001243_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((pub_r001243_12_1 * 2) + 24) & 63;
  int stage_v_99_2 = ((pub_r001243_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001243_19_1 * 2) + 32) & 63;
  int stage_v_100_2 = ((pub_r001243_19_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = (((stage_v_51_1 * 3) + pub_r001243_7_1) + 5) & 127;
  int stage_v_101_2 = (((stage_v_51_2 * 3) + pub_r001243_7_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_101_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_101_2 * 2)) & 255;
  int stage_v_102_1 = (((stage_v_68_1 * 3) + pub_r001243_4_1) + 37) & 127;
  int stage_v_102_2 = (((stage_v_68_2 * 3) + pub_r001243_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001243_1_1 * 2) + 29) & 63;
  int stage_v_103_2 = ((pub_r001243_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_31_1 * 3) + pub_r001243_8_1) + 34) & 127;
  int stage_v_104_2 = (((stage_v_31_2 * 3) + pub_r001243_8_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = (((stage_v_95_1 * 3) + pub_r001243_3_1) + 37) & 127;
  int stage_v_105_2 = (((stage_v_95_2 * 3) + pub_r001243_3_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_105_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_105_2 * 2)) & 255;
  int stage_v_106_1 = ((pub_r001243_19_1 * 2) + 6) & 63;
  int stage_v_106_2 = ((pub_r001243_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_2_1 * 3) + pub_r001243_15_1) + 26) & 127;
  int stage_v_107_2 = (((stage_v_2_2 * 3) + pub_r001243_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_6_1 * 3) + pub_r001243_19_1) + 38) & 127;
  int stage_v_108_2 = (((stage_v_6_2 * 3) + pub_r001243_19_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = (((stage_v_102_1 * 3) + pub_r001243_0_1) + 28) & 127;
  int stage_v_109_2 = (((stage_v_102_2 * 3) + pub_r001243_0_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_109_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_109_2 * 2)) & 255;
  int stage_v_110_1 = ((pub_r001243_9_1 * 2) + 34) & 63;
  int stage_v_110_2 = ((pub_r001243_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001243_5_1 * 2) + 10) & 63;
  int stage_v_111_2 = ((pub_r001243_5_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_34_1 * 3) + pub_r001243_1_1) + 20) & 127;
  int stage_v_112_2 = (((stage_v_34_2 * 3) + pub_r001243_1_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = ((pub_r001243_5_1 * 2) + 34) & 63;
  int stage_v_113_2 = ((pub_r001243_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (((stage_v_102_1 * 3) + pub_r001243_5_1) + 40) & 127;
  int stage_v_114_2 = (((stage_v_102_2 * 3) + pub_r001243_5_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_114_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_114_2 * 2)) & 255;
  int stage_v_115_1 = (((stage_v_40_1 * 3) + pub_r001243_17_1) + 14) & 127;
  int stage_v_115_2 = (((stage_v_40_2 * 3) + pub_r001243_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = (((stage_v_18_1 * 3) + pub_r001243_10_1) + 41) & 127;
  int stage_v_116_2 = (((stage_v_18_2 * 3) + pub_r001243_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((stage_v_108_1 * 3) + pub_r001243_0_1) + 44) & 127;
  int stage_v_117_2 = (((stage_v_108_2 * 3) + pub_r001243_0_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((helper_flow_1_1 * 3) + pub_r001243_19_1) + 41) & 127;
  int stage_v_118_2 = (((helper_flow_1_2 * 3) + pub_r001243_19_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001243_15_1 * 2) + 25) & 63;
  int stage_v_119_2 = ((pub_r001243_15_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((pub_r001243_5_1 * 2) + 45) & 63;
  int stage_v_120_2 = ((pub_r001243_5_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_120_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_120_2) & 127;
  int stage_v_121_1 = ((pub_r001243_0_1 * 2) + 7) & 63;
  int stage_v_121_2 = ((pub_r001243_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (((stage_v_46_1 * 3) + pub_r001243_17_1) + 16) & 127;
  int stage_v_122_2 = (((stage_v_46_2 * 3) + pub_r001243_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_122_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_122_2 * 2)) & 255;
  int stage_v_123_1 = (((stage_v_12_1 * 3) + pub_r001243_10_1) + 22) & 127;
  int stage_v_123_2 = (((stage_v_12_2 * 3) + pub_r001243_10_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((sec_r001243_11_1 * 3) + pub_r001243_0_1) + 15) & 127;
  int stage_v_124_2 = (((sec_r001243_11_2 * 3) + pub_r001243_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001243_5_1 * 2) + 46) & 63;
  int stage_v_125_2 = ((pub_r001243_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_40_1 * 3) + pub_r001243_1_1) + 31) & 127;
  int stage_v_126_2 = (((stage_v_40_2 * 3) + pub_r001243_1_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001243_13_1 * 2) + 11) & 63;
  int stage_v_127_2 = ((pub_r001243_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_54_1 * 3) + pub_r001243_20_1) + 40) & 127;
  int stage_v_128_2 = (((stage_v_54_2 * 3) + pub_r001243_20_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001243_4_1 * 2) + 12) & 63;
  int stage_v_129_2 = ((pub_r001243_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = (((stage_v_104_1 * 3) + pub_r001243_20_1) + 26) & 127;
  int stage_v_130_2 = (((stage_v_104_2 * 3) + pub_r001243_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_53_1 * 3) + pub_r001243_18_1) + 20) & 127;
  int stage_v_131_2 = (((stage_v_53_2 * 3) + pub_r001243_18_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001243_1_1 * 2) + 30) & 63;
  int stage_v_132_2 = ((pub_r001243_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_75_1 * 3) + pub_r001243_13_1) + 32) & 127;
  int stage_v_133_2 = (((stage_v_75_2 * 3) + pub_r001243_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001243_10_1 * 2) + 40) & 63;
  int stage_v_134_2 = ((pub_r001243_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = (((stage_v_70_1 * 3) + pub_r001243_0_1) + 16) & 127;
  int stage_v_135_2 = (((stage_v_70_2 * 3) + pub_r001243_0_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = (((sec_r001243_10_1 * 3) + pub_r001243_10_1) + 27) & 127;
  int stage_v_136_2 = (((sec_r001243_10_2 * 3) + pub_r001243_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_136_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_136_2 * 2)) & 255;
  int stage_v_137_1 = (((stage_v_97_1 * 3) + pub_r001243_12_1) + 14) & 127;
  int stage_v_137_2 = (((stage_v_97_2 * 3) + pub_r001243_12_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_137_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_137_2 * 2)) & 255;
  int stage_v_138_1 = (((stage_v_10_1 * 3) + pub_r001243_20_1) + 25) & 127;
  int stage_v_138_2 = (((stage_v_10_2 * 3) + pub_r001243_20_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001243_9_1 * 2) + 9) & 63;
  int stage_v_139_2 = ((pub_r001243_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((stage_v_130_1 * 3) + pub_r001243_21_1) + 25) & 127;
  int stage_v_140_2 = (((stage_v_130_2 * 3) + pub_r001243_21_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = ((pub_r001243_6_1 * 2) + 47) & 63;
  int stage_v_141_2 = ((pub_r001243_6_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((pub_r001243_7_1 * 2) + 10) & 63;
  int stage_v_142_2 = ((pub_r001243_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_142_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_142_2) & 127;
  int stage_v_143_1 = (((stage_v_34_1 * 3) + pub_r001243_18_1) + 25) & 127;
  int stage_v_143_2 = (((stage_v_34_2 * 3) + pub_r001243_18_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001243_8_1 * 2) + 6) & 63;
  int stage_v_144_2 = ((pub_r001243_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((stage_v_37_1 * 3) + pub_r001243_21_1) + 8) & 127;
  int stage_v_145_2 = (((stage_v_37_2 * 3) + pub_r001243_21_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001243_3_1 * 2) + 50) & 63;
  int stage_v_146_2 = ((pub_r001243_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001243_20_1 * 2) + 26) & 63;
  int stage_v_147_2 = ((pub_r001243_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001243_21_1 * 2) + 27) & 63;
  int stage_v_148_2 = ((pub_r001243_21_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001243_3_1 * 2) + 46) & 63;
  int stage_v_149_2 = ((pub_r001243_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_115_1 * 3) + pub_r001243_20_1) + 26) & 127;
  int stage_v_150_2 = (((stage_v_115_2 * 3) + pub_r001243_20_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001243_8_1 * 2) + 38) & 63;
  int stage_v_151_2 = ((pub_r001243_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_54_1 * 3) + pub_r001243_19_1) + 10) & 127;
  int stage_v_152_2 = (((stage_v_54_2 * 3) + pub_r001243_19_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001243_16_1 * 2) + 11) & 63;
  int stage_v_153_2 = ((pub_r001243_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = (((sec_r001243_8_1 * 3) + pub_r001243_7_1) + 9) & 127;
  int stage_v_154_2 = (((sec_r001243_8_2 * 3) + pub_r001243_7_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_6_1 * 3) + pub_r001243_0_1) + 13) & 127;
  int stage_v_155_2 = (((stage_v_6_2 * 3) + pub_r001243_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((stage_v_79_1 * 3) + pub_r001243_13_1) + 30) & 127;
  int stage_v_156_2 = (((stage_v_79_2 * 3) + pub_r001243_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = ((pub_r001243_4_1 * 2) + 25) & 63;
  int stage_v_157_2 = ((pub_r001243_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((sec_r001243_0_1 * 3) + pub_r001243_10_1) + 45) & 127;
  int stage_v_158_2 = (((sec_r001243_0_2 * 3) + pub_r001243_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001243_13_1 * 2) + 6) & 63;
  int stage_v_159_2 = ((pub_r001243_13_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_124_1 * 3) + pub_r001243_14_1) + 9) & 127;
  int stage_v_160_2 = (((stage_v_124_2 * 3) + pub_r001243_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001243_7_1 * 2) + 20) & 63;
  int stage_v_161_2 = ((pub_r001243_7_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001243_19_1 * 2) + 14) & 63;
  int stage_v_162_2 = ((pub_r001243_19_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001243_5_1 * 2) + 41) & 63;
  int stage_v_163_2 = ((pub_r001243_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (((stage_v_150_1 * 3) + pub_r001243_19_1) + 22) & 127;
  int stage_v_164_2 = (((stage_v_150_2 * 3) + pub_r001243_19_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_164_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_164_2 * 2)) & 255;
  int stage_v_165_1 = ((pub_r001243_11_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001243_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((helper_flow_2_1 * 3) + pub_r001243_18_1) + 33) & 127;
  int stage_v_166_2 = (((helper_flow_2_2 * 3) + pub_r001243_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001243_2_1 * 2) + 25) & 63;
  int stage_v_167_2 = ((pub_r001243_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001243_1_1 * 2) + 8) & 63;
  int stage_v_168_2 = ((pub_r001243_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = ((pub_r001243_0_1 * 2) + 26) & 63;
  int stage_v_169_2 = ((pub_r001243_0_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_169_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_169_2) & 127;
  int stage_v_170_1 = ((pub_r001243_10_1 * 2) + 5) & 63;
  int stage_v_170_2 = ((pub_r001243_10_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = (((stage_v_97_1 * 3) + pub_r001243_10_1) + 45) & 127;
  int stage_v_171_2 = (((stage_v_97_2 * 3) + pub_r001243_10_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_171_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_171_2 * 2)) & 255;
  int stage_v_172_1 = (((stage_v_2_1 * 3) + pub_r001243_2_1) + 10) & 127;
  int stage_v_172_2 = (((stage_v_2_2 * 3) + pub_r001243_2_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001243_19_1 * 2) + 45) & 63;
  int stage_v_173_2 = ((pub_r001243_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_135_1 * 3) + pub_r001243_17_1) + 45) & 127;
  int stage_v_174_2 = (((stage_v_135_2 * 3) + pub_r001243_17_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_42_1 * 3) + pub_r001243_14_1) + 41) & 127;
  int stage_v_175_2 = (((stage_v_42_2 * 3) + pub_r001243_14_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = ((pub_r001243_18_1 * 2) + 15) & 63;
  int stage_v_176_2 = ((pub_r001243_18_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001243_21_1 * 2) + 38) & 63;
  int stage_v_177_2 = ((pub_r001243_21_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = ((pub_r001243_1_1 * 2) + 47) & 63;
  int stage_v_178_2 = ((pub_r001243_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = (((stage_v_15_1 * 3) + pub_r001243_13_1) + 26) & 127;
  int stage_v_179_2 = (((stage_v_15_2 * 3) + pub_r001243_13_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_43_1 * 3) + pub_r001243_8_1) + 14) & 127;
  int stage_v_180_2 = (((stage_v_43_2 * 3) + pub_r001243_8_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001243_8_1 * 2) + 24) & 63;
  int stage_v_181_2 = ((pub_r001243_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001243_7_1 * 2) + 45) & 63;
  int stage_v_182_2 = ((pub_r001243_7_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = (((stage_v_8_1 * 3) + pub_r001243_12_1) + 23) & 127;
  int stage_v_183_2 = (((stage_v_8_2 * 3) + pub_r001243_12_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_183_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_183_2 * 2)) & 255;
  int stage_v_184_1 = (((stage_v_115_1 * 3) + pub_r001243_7_1) + 31) & 127;
  int stage_v_184_2 = (((stage_v_115_2 * 3) + pub_r001243_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_8_1 * 3) + pub_r001243_15_1) + 35) & 127;
  int stage_v_185_2 = (((stage_v_8_2 * 3) + pub_r001243_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001243_3_1 * 2) + 47) & 63;
  int stage_v_186_2 = ((pub_r001243_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_85_1 * 3) + pub_r001243_13_1) + 44) & 127;
  int stage_v_187_2 = (((stage_v_85_2 * 3) + pub_r001243_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001243_2_1 * 2) + 48) & 63;
  int stage_v_188_2 = ((pub_r001243_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = (((sec_r001243_11_1 * 3) + pub_r001243_13_1) + 38) & 127;
  int stage_v_189_2 = (((sec_r001243_11_2 * 3) + pub_r001243_13_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_189_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_189_2 * 2)) & 255;
  int stage_v_190_1 = (((stage_v_83_1 * 3) + pub_r001243_18_1) + 42) & 127;
  int stage_v_190_2 = (((stage_v_83_2 * 3) + pub_r001243_18_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = (((stage_v_10_1 * 3) + pub_r001243_0_1) + 33) & 127;
  int stage_v_191_2 = (((stage_v_10_2 * 3) + pub_r001243_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_0_1 * 3) + pub_r001243_15_1) + 32) & 127;
  int stage_v_192_2 = (((stage_v_0_2 * 3) + pub_r001243_15_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((stage_v_137_1 * 3) + pub_r001243_5_1) + 15) & 127;
  int stage_v_193_2 = (((stage_v_137_2 * 3) + pub_r001243_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001243_2_1 * 2) + 31) & 63;
  int stage_v_194_2 = ((pub_r001243_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = (((stage_v_184_1 * 3) + pub_r001243_6_1) + 15) & 127;
  int stage_v_195_2 = (((stage_v_184_2 * 3) + pub_r001243_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_195_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_195_2 * 2)) & 255;
  int stage_v_196_1 = ((pub_r001243_17_1 * 2) + 17) & 63;
  int stage_v_196_2 = ((pub_r001243_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001243_20_1 * 2) + 29) & 63;
  int stage_v_197_2 = ((pub_r001243_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((sec_r001243_12_1 * 3) + pub_r001243_4_1) + 14) & 127;
  int stage_v_198_2 = (((sec_r001243_12_2 * 3) + pub_r001243_4_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001243_6_1 * 2) + 6) & 63;
  int stage_v_199_2 = ((pub_r001243_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = (((sec_r001243_15_1 * 3) + pub_r001243_6_1) + 10) & 127;
  int stage_v_200_2 = (((sec_r001243_15_2 * 3) + pub_r001243_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_200_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_200_2 * 2)) & 255;
  int stage_v_201_1 = (((stage_v_155_1 * 3) + pub_r001243_0_1) + 11) & 127;
  int stage_v_201_2 = (((stage_v_155_2 * 3) + pub_r001243_0_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001243_14_1 * 2) + 22) & 63;
  int stage_v_202_2 = ((pub_r001243_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = (((stage_v_84_1 * 3) + pub_r001243_8_1) + 18) & 127;
  int stage_v_203_2 = (((stage_v_84_2 * 3) + pub_r001243_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_83_1 * 3) + pub_r001243_3_1) + 24) & 127;
  int stage_v_204_2 = (((stage_v_83_2 * 3) + pub_r001243_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_160_1 * 3) + pub_r001243_2_1) + 13) & 127;
  int stage_v_205_2 = (((stage_v_160_2 * 3) + pub_r001243_2_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_12_1 * 3) + pub_r001243_6_1) + 34) & 127;
  int stage_v_206_2 = (((stage_v_12_2 * 3) + pub_r001243_6_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_20_1 * 3) + pub_r001243_15_1) + 8) & 127;
  int stage_v_207_2 = (((stage_v_20_2 * 3) + pub_r001243_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001243_3_1 * 2) + 15) & 63;
  int stage_v_208_2 = ((pub_r001243_3_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001243_4_1 * 2) + 50) & 63;
  int stage_v_209_2 = ((pub_r001243_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001243_19_1 * 2) + 6) & 63;
  int stage_v_210_2 = ((pub_r001243_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001243_19_1 * 2) + 15) & 63;
  int stage_v_211_2 = ((pub_r001243_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = (((stage_v_204_1 * 3) + pub_r001243_11_1) + 44) & 127;
  int stage_v_212_2 = (((stage_v_204_2 * 3) + pub_r001243_11_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_212_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_212_2 * 2)) & 255;
  int stage_v_213_1 = (((stage_v_70_1 * 3) + pub_r001243_11_1) + 38) & 127;
  int stage_v_213_2 = (((stage_v_70_2 * 3) + pub_r001243_11_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_4_1 * 3) + pub_r001243_16_1) + 16) & 127;
  int stage_v_214_2 = (((stage_v_4_2 * 3) + pub_r001243_16_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_26_1 * 3) + pub_r001243_1_1) + 4) & 127;
  int stage_v_215_2 = (((stage_v_26_2 * 3) + pub_r001243_1_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((sec_r001243_2_1 * 3) + pub_r001243_4_1) + 5) & 127;
  int stage_v_216_2 = (((sec_r001243_2_2 * 3) + pub_r001243_4_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001243_19_1 * 2) + 39) & 63;
  int stage_v_217_2 = ((pub_r001243_19_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = (((stage_v_190_1 * 3) + pub_r001243_6_1) + 32) & 127;
  int stage_v_218_2 = (((stage_v_190_2 * 3) + pub_r001243_6_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_218_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_218_2 * 2)) & 255;
  int stage_v_219_1 = (((stage_v_65_1 * 3) + pub_r001243_18_1) + 39) & 127;
  int stage_v_219_2 = (((stage_v_65_2 * 3) + pub_r001243_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((stage_v_8_1 * 3) + pub_r001243_7_1) + 44) & 127;
  int stage_v_220_2 = (((stage_v_8_2 * 3) + pub_r001243_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001243_20_1 * 2) + 16) & 63;
  int stage_v_221_2 = ((pub_r001243_20_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_90_1 * 3) + pub_r001243_9_1) + 25) & 127;
  int stage_v_222_2 = (((stage_v_90_2 * 3) + pub_r001243_9_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001243_18_1 * 2) + 32) & 63;
  int stage_v_223_2 = ((pub_r001243_18_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((sec_r001243_15_1 * 3) + pub_r001243_20_1) + 32) & 127;
  int stage_v_224_2 = (((sec_r001243_15_2 * 3) + pub_r001243_20_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001243_18_1 * 2) + 24) & 63;
  int stage_v_225_2 = ((pub_r001243_18_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = (((stage_v_185_1 * 3) + pub_r001243_18_1) + 39) & 127;
  int stage_v_226_2 = (((stage_v_185_2 * 3) + pub_r001243_18_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_122_1 * 3) + pub_r001243_21_1) + 4) & 127;
  int stage_v_227_2 = (((stage_v_122_2 * 3) + pub_r001243_21_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001243_5_1 * 2) + 41) & 63;
  int stage_v_228_2 = ((pub_r001243_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001243_3_1 * 2) + 21) & 63;
  int stage_v_229_2 = ((pub_r001243_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001243_21_1 * 2) + 31) & 63;
  int stage_v_230_2 = ((pub_r001243_21_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_70_1 * 3) + pub_r001243_19_1) + 18) & 127;
  int stage_v_231_2 = (((stage_v_70_2 * 3) + pub_r001243_19_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001243_4_1 * 2) + 33) & 63;
  int stage_v_232_2 = ((pub_r001243_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = (((stage_v_102_1 * 3) + pub_r001243_15_1) + 45) & 127;
  int stage_v_233_2 = (((stage_v_102_2 * 3) + pub_r001243_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001243_15_1 * 2) + 47) & 63;
  int stage_v_234_2 = ((pub_r001243_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001243_5_1 * 2) + 31) & 63;
  int stage_v_235_2 = ((pub_r001243_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_155_1 * 3) + pub_r001243_14_1) + 26) & 127;
  int stage_v_236_2 = (((stage_v_155_2 * 3) + pub_r001243_14_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001243_2_1 * 2) + 13) & 63;
  int stage_v_237_2 = ((pub_r001243_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001243_18_1 * 2) + 49) & 63;
  int stage_v_238_2 = ((pub_r001243_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001243_6_1 * 2) + 19) & 63;
  int stage_v_239_2 = ((pub_r001243_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_171_1 * 3) + pub_r001243_14_1) + 28) & 127;
  int stage_v_240_2 = (((stage_v_171_2 * 3) + pub_r001243_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = ((pub_r001243_13_1 * 2) + 30) & 63;
  int stage_v_241_2 = ((pub_r001243_13_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_241_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_241_2) & 127;
  int stage_v_242_1 = ((pub_r001243_14_1 * 2) + 7) & 63;
  int stage_v_242_2 = ((pub_r001243_14_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = (((sec_r001243_9_1 * 3) + pub_r001243_11_1) + 22) & 127;
  int stage_v_243_2 = (((sec_r001243_9_2 * 3) + pub_r001243_11_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_140_1 * 3) + pub_r001243_0_1) + 8) & 127;
  int stage_v_244_2 = (((stage_v_140_2 * 3) + pub_r001243_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_75_1 * 3) + pub_r001243_15_1) + 7) & 127;
  int stage_v_245_2 = (((stage_v_75_2 * 3) + pub_r001243_15_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001243_19_1 * 2) + 15) & 63;
  int stage_v_246_2 = ((pub_r001243_19_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001243_13_1 * 2) + 14) & 63;
  int stage_v_247_2 = ((pub_r001243_13_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_61_1 * 3) + pub_r001243_3_1) + 11) & 127;
  int stage_v_248_2 = (((stage_v_61_2 * 3) + pub_r001243_3_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_104_1 * 3) + pub_r001243_5_1) + 39) & 127;
  int stage_v_249_2 = (((stage_v_104_2 * 3) + pub_r001243_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001243_18_1 * 2) + 11) & 63;
  int stage_v_250_2 = ((pub_r001243_18_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001243_13_1 * 2) + 5) & 63;
  int stage_v_251_2 = ((pub_r001243_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = (((sec_r001243_9_1 * 3) + pub_r001243_5_1) + 9) & 127;
  int stage_v_252_2 = (((sec_r001243_9_2 * 3) + pub_r001243_5_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_130_1 * 3) + pub_r001243_14_1) + 39) & 127;
  int stage_v_253_2 = (((stage_v_130_2 * 3) + pub_r001243_14_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_55_1 * 3) + pub_r001243_17_1) + 17) & 127;
  int stage_v_254_2 = (((stage_v_55_2 * 3) + pub_r001243_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = (((stage_v_252_1 * 3) + pub_r001243_18_1) + 33) & 127;
  int stage_v_255_2 = (((stage_v_252_2 * 3) + pub_r001243_18_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_255_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_255_2 * 2)) & 255;
  int stage_v_256_1 = (((stage_v_240_1 * 3) + pub_r001243_12_1) + 22) & 127;
  int stage_v_256_2 = (((stage_v_240_2 * 3) + pub_r001243_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_256_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_256_2 * 2)) & 255;
  int stage_v_257_1 = (((helper_flow_3_1 * 3) + pub_r001243_12_1) + 27) & 127;
  int stage_v_257_2 = (((helper_flow_3_2 * 3) + pub_r001243_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001243_13_1 * 2) + 24) & 63;
  int stage_v_258_2 = ((pub_r001243_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001243_7_1 * 2) + 15) & 63;
  int stage_v_259_2 = ((pub_r001243_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001243_5_1 * 2) + 14) & 63;
  int stage_v_260_2 = ((pub_r001243_5_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001243_17_1 * 2) + 24) & 63;
  int stage_v_261_2 = ((pub_r001243_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = (((stage_v_207_1 * 3) + pub_r001243_18_1) + 8) & 127;
  int stage_v_262_2 = (((stage_v_207_2 * 3) + pub_r001243_18_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_262_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_262_2 * 2)) & 255;
  int stage_v_263_1 = (((stage_v_143_1 * 3) + pub_r001243_20_1) + 30) & 127;
  int stage_v_263_2 = (((stage_v_143_2 * 3) + pub_r001243_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001243_10_1 * 2) + 14) & 63;
  int stage_v_264_2 = ((pub_r001243_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001243_7_1 * 2) + 36) & 63;
  int stage_v_265_2 = ((pub_r001243_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = ((pub_r001243_1_1 * 2) + 42) & 63;
  int stage_v_266_2 = ((pub_r001243_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = (((stage_v_18_1 * 3) + pub_r001243_16_1) + 32) & 127;
  int stage_v_267_2 = (((stage_v_18_2 * 3) + pub_r001243_16_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = ((pub_r001243_4_1 * 2) + 5) & 63;
  int stage_v_268_2 = ((pub_r001243_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_268_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_268_2) & 127;
  int stage_v_269_1 = (((stage_v_97_1 * 3) + pub_r001243_2_1) + 16) & 127;
  int stage_v_269_2 = (((stage_v_97_2 * 3) + pub_r001243_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = (((helper_flow_1_1 * 3) + pub_r001243_18_1) + 4) & 127;
  int stage_v_270_2 = (((helper_flow_1_2 * 3) + pub_r001243_18_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_270_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_270_2 * 2)) & 255;
  int stage_v_271_1 = ((pub_r001243_0_1 * 2) + 10) & 63;
  int stage_v_271_2 = ((pub_r001243_0_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001243_1_1 * 2) + 12) & 63;
  int stage_v_272_2 = ((pub_r001243_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = ((pub_r001243_5_1 * 2) + 11) & 63;
  int stage_v_273_2 = ((pub_r001243_5_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_273_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_273_2) & 127;
  int stage_v_274_1 = ((pub_r001243_2_1 * 2) + 6) & 63;
  int stage_v_274_2 = ((pub_r001243_2_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001243_12_1 * 2) + 33) & 63;
  int stage_v_275_2 = ((pub_r001243_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001243_0_1 * 2) + 17) & 63;
  int stage_v_276_2 = ((pub_r001243_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_46_1 * 3) + pub_r001243_11_1) + 19) & 127;
  int stage_v_277_2 = (((stage_v_46_2 * 3) + pub_r001243_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_4_1 * 3) + pub_r001243_19_1) + 3) & 127;
  int stage_v_278_2 = (((stage_v_4_2 * 3) + pub_r001243_19_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001243_20_1 * 2) + 26) & 63;
  int stage_v_279_2 = ((pub_r001243_20_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_150_1 * 3) + pub_r001243_13_1) + 5) & 127;
  int stage_v_280_2 = (((stage_v_150_2 * 3) + pub_r001243_13_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_53_1 * 3) + pub_r001243_15_1) + 31) & 127;
  int stage_v_281_2 = (((stage_v_53_2 * 3) + pub_r001243_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001243_15_1 * 2) + 27) & 63;
  int stage_v_282_2 = ((pub_r001243_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((sec_r001243_12_1 * 3) + pub_r001243_12_1) + 40) & 127;
  int stage_v_283_2 = (((sec_r001243_12_2 * 3) + pub_r001243_12_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((helper_flow_0_1 * 3) + pub_r001243_16_1) + 8) & 127;
  int stage_v_284_2 = (((helper_flow_0_2 * 3) + pub_r001243_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = (((stage_v_269_1 * 3) + pub_r001243_3_1) + 42) & 127;
  int stage_v_285_2 = (((stage_v_269_2 * 3) + pub_r001243_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_285_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_285_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_285_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_285_2 * 2)) & 255;
  int stage_v_286_1 = (((helper_flow_4_1 * 3) + pub_r001243_2_1) + 30) & 127;
  int stage_v_286_2 = (((helper_flow_4_2 * 3) + pub_r001243_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_286_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_286_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_286_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_286_2 * 2)) & 255;
  int stage_v_287_1 = ((pub_r001243_1_1 * 2) + 17) & 63;
  int stage_v_287_2 = ((pub_r001243_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_287_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_287_2) & 127;
  int stage_v_288_1 = (((stage_v_79_1 * 3) + pub_r001243_15_1) + 24) & 127;
  int stage_v_288_2 = (((stage_v_79_2 * 3) + pub_r001243_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = ((pub_r001243_19_1 * 2) + 7) & 63;
  int stage_v_289_2 = ((pub_r001243_19_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = (((stage_v_254_1 * 3) + pub_r001243_11_1) + 35) & 127;
  int stage_v_290_2 = (((stage_v_254_2 * 3) + pub_r001243_11_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = (((sec_r001243_7_1 * 3) + pub_r001243_3_1) + 27) & 127;
  int stage_v_291_2 = (((sec_r001243_7_2 * 3) + pub_r001243_3_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_224_1 * 3) + pub_r001243_11_1) + 15) & 127;
  int stage_v_292_2 = (((stage_v_224_2 * 3) + pub_r001243_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001243_10_1 * 2) + 27) & 63;
  int stage_v_293_2 = ((pub_r001243_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001243_16_1 * 2) + 33) & 63;
  int stage_v_294_2 = ((pub_r001243_16_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((sec_r001243_15_1 * 3) + pub_r001243_16_1) + 24) & 127;
  int stage_v_295_2 = (((sec_r001243_15_2 * 3) + pub_r001243_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001243_11_1 * 2) + 49) & 63;
  int stage_v_296_2 = ((pub_r001243_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = (((stage_v_53_1 * 3) + pub_r001243_9_1) + 39) & 127;
  int stage_v_297_2 = (((stage_v_53_2 * 3) + pub_r001243_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_297_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_297_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_297_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_297_2 * 2)) & 255;
  int stage_v_298_1 = (((stage_v_180_1 * 3) + pub_r001243_5_1) + 18) & 127;
  int stage_v_298_2 = (((stage_v_180_2 * 3) + pub_r001243_5_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = (((stage_v_18_1 * 3) + pub_r001243_18_1) + 19) & 127;
  int stage_v_299_2 = (((stage_v_18_2 * 3) + pub_r001243_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_299_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_299_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_299_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_299_2 * 2)) & 255;
  int stage_v_300_1 = (((stage_v_68_1 * 3) + pub_r001243_7_1) + 42) & 127;
  int stage_v_300_2 = (((stage_v_68_2 * 3) + pub_r001243_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_300_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_300_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_300_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_300_2 * 2)) & 255;
  int stage_v_301_1 = (((stage_v_156_1 * 3) + pub_r001243_11_1) + 12) & 127;
  int stage_v_301_2 = (((stage_v_156_2 * 3) + pub_r001243_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = (((stage_v_267_1 * 3) + pub_r001243_4_1) + 23) & 127;
  int stage_v_302_2 = (((stage_v_267_2 * 3) + pub_r001243_4_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001243_16_1 * 2) + 20) & 63;
  int stage_v_303_2 = ((pub_r001243_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001243_11_1 * 2) + 35) & 63;
  int stage_v_304_2 = ((pub_r001243_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_10_1 * 3) + pub_r001243_1_1) + 30) & 127;
  int stage_v_305_2 = (((stage_v_10_2 * 3) + pub_r001243_1_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = (((stage_v_54_1 * 3) + pub_r001243_13_1) + 11) & 127;
  int stage_v_306_2 = (((stage_v_54_2 * 3) + pub_r001243_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_306_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_306_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_306_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_306_2 * 2)) & 255;
  int stage_v_307_1 = (((stage_v_160_1 * 3) + pub_r001243_15_1) + 25) & 127;
  int stage_v_307_2 = (((stage_v_160_2 * 3) + pub_r001243_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_307_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_307_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_307_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_307_2 * 2)) & 255;
  int stage_v_308_1 = ((pub_r001243_2_1 * 2) + 9) & 63;
  int stage_v_308_2 = ((pub_r001243_2_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_58_1 * 3) + pub_r001243_20_1) + 15) & 127;
  int stage_v_309_2 = (((stage_v_58_2 * 3) + pub_r001243_20_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001243_15_1 * 2) + 11) & 63;
  int stage_v_310_2 = ((pub_r001243_15_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_137_1 * 3) + pub_r001243_9_1) + 39) & 127;
  int stage_v_311_2 = (((stage_v_137_2 * 3) + pub_r001243_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_189_1 * 3) + pub_r001243_0_1) + 23) & 127;
  int stage_v_312_2 = (((stage_v_189_2 * 3) + pub_r001243_0_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001243_2_1 * 2) + 24) & 63;
  int stage_v_313_2 = ((pub_r001243_2_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_136_1 * 3) + pub_r001243_17_1) + 32) & 127;
  int stage_v_314_2 = (((stage_v_136_2 * 3) + pub_r001243_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = ((pub_r001243_18_1 * 2) + 13) & 63;
  int stage_v_315_2 = ((pub_r001243_18_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_184_1 * 3) + pub_r001243_10_1) + 17) & 127;
  int stage_v_316_2 = (((stage_v_184_2 * 3) + pub_r001243_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001243_7_1 * 2) + 50) & 63;
  int stage_v_317_2 = ((pub_r001243_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001243_8_1 * 2) + 14) & 63;
  int stage_v_318_2 = ((pub_r001243_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = ((pub_r001243_14_1 * 2) + 47) & 63;
  int stage_v_319_2 = ((pub_r001243_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_10_1 * 3) + pub_r001243_20_1) + 18) & 127;
  int stage_v_320_2 = (((stage_v_10_2 * 3) + pub_r001243_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = (((stage_v_42_1 * 3) + pub_r001243_11_1) + 3) & 127;
  int stage_v_321_2 = (((stage_v_42_2 * 3) + pub_r001243_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_321_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_321_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_321_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_321_2 * 2)) & 255;
  int stage_v_322_1 = (((stage_v_138_1 * 3) + pub_r001243_14_1) + 35) & 127;
  int stage_v_322_2 = (((stage_v_138_2 * 3) + pub_r001243_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_322_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_322_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_322_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_322_2 * 2)) & 255;
  int stage_v_323_1 = (((sec_r001243_4_1 * 3) + pub_r001243_20_1) + 9) & 127;
  int stage_v_323_2 = (((sec_r001243_4_2 * 3) + pub_r001243_20_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = ((pub_r001243_1_1 * 2) + 42) & 63;
  int stage_v_324_2 = ((pub_r001243_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = (((helper_flow_3_1 * 3) + pub_r001243_13_1) + 16) & 127;
  int stage_v_325_2 = (((helper_flow_3_2 * 3) + pub_r001243_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = (((stage_v_10_1 * 3) + pub_r001243_17_1) + 14) & 127;
  int stage_v_326_2 = (((stage_v_10_2 * 3) + pub_r001243_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_326_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_326_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_326_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_326_2 * 2)) & 255;
  int stage_v_327_1 = ((pub_r001243_12_1 * 2) + 17) & 63;
  int stage_v_327_2 = ((pub_r001243_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001243_4_1 * 2) + 27) & 63;
  int stage_v_328_2 = ((pub_r001243_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001243_12_1 * 2) + 22) & 63;
  int stage_v_329_2 = ((pub_r001243_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001243_3_1 * 2) + 40) & 63;
  int stage_v_330_2 = ((pub_r001243_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = (((stage_v_222_1 * 3) + pub_r001243_14_1) + 9) & 127;
  int stage_v_331_2 = (((stage_v_222_2 * 3) + pub_r001243_14_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001243_14_1 * 2) + 42) & 63;
  int stage_v_332_2 = ((pub_r001243_14_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001243_2_1 * 2) + 12) & 63;
  int stage_v_333_2 = ((pub_r001243_2_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_255_1 * 3) + pub_r001243_8_1) + 22) & 127;
  int stage_v_334_2 = (((stage_v_255_2 * 3) + pub_r001243_8_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = ((pub_r001243_11_1 * 2) + 21) & 63;
  int stage_v_335_2 = ((pub_r001243_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001243_5_1 * 2) + 34) & 63;
  int stage_v_336_2 = ((pub_r001243_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001243_16_1 * 2) + 38) & 63;
  int stage_v_337_2 = ((pub_r001243_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001243_15_1 * 2) + 18) & 63;
  int stage_v_338_2 = ((pub_r001243_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001243_0_1 * 2) + 7) & 63;
  int stage_v_339_2 = ((pub_r001243_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_253_1 * 3) + pub_r001243_5_1) + 34) & 127;
  int stage_v_340_2 = (((stage_v_253_2 * 3) + pub_r001243_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = ((pub_r001243_13_1 * 2) + 32) & 63;
  int stage_v_341_2 = ((pub_r001243_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001243_3_1 * 2) + 34) & 63;
  int stage_v_342_2 = ((pub_r001243_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_224_1 * 3) + pub_r001243_8_1) + 33) & 127;
  int stage_v_343_2 = (((stage_v_224_2 * 3) + pub_r001243_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_320_1 * 3) + pub_r001243_1_1) + 12) & 127;
  int stage_v_344_2 = (((stage_v_320_2 * 3) + pub_r001243_1_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001243_21_1 * 2) + 42) & 63;
  int stage_v_345_2 = ((pub_r001243_21_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001243_13_1 * 2) + 23) & 63;
  int stage_v_346_2 = ((pub_r001243_13_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = ((pub_r001243_3_1 * 2) + 43) & 63;
  int stage_v_347_2 = ((pub_r001243_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_78_1 * 3) + pub_r001243_18_1) + 26) & 127;
  int stage_v_348_2 = (((stage_v_78_2 * 3) + pub_r001243_18_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_334_1 * 3) + pub_r001243_17_1) + 7) & 127;
  int stage_v_349_2 = (((stage_v_334_2 * 3) + pub_r001243_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_179_1 * 3) + pub_r001243_20_1) + 28) & 127;
  int stage_v_350_2 = (((stage_v_179_2 * 3) + pub_r001243_20_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = ((pub_r001243_5_1 * 2) + 18) & 63;
  int stage_v_351_2 = ((pub_r001243_5_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_351_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_351_2) & 127;
  int stage_v_352_1 = (((sec_r001243_2_1 * 3) + pub_r001243_20_1) + 18) & 127;
  int stage_v_352_2 = (((sec_r001243_2_2 * 3) + pub_r001243_20_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_352_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_352_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_352_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_352_2 * 2)) & 255;
  int stage_v_353_1 = (((stage_v_51_1 * 3) + pub_r001243_8_1) + 38) & 127;
  int stage_v_353_2 = (((stage_v_51_2 * 3) + pub_r001243_8_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((stage_v_348_1 * 3) + pub_r001243_18_1) + 6) & 127;
  int stage_v_354_2 = (((stage_v_348_2 * 3) + pub_r001243_18_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = ((pub_r001243_3_1 * 2) + 34) & 63;
  int stage_v_355_2 = ((pub_r001243_3_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = ((pub_r001243_4_1 * 2) + 12) & 63;
  int stage_v_356_2 = ((pub_r001243_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((stage_v_240_1 * 3) + pub_r001243_16_1) + 41) & 127;
  int stage_v_357_2 = (((stage_v_240_2 * 3) + pub_r001243_16_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001243_0_1 * 2) + 33) & 63;
  int stage_v_358_2 = ((pub_r001243_0_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001243_16_1 * 2) + 48) & 63;
  int stage_v_359_2 = ((pub_r001243_16_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = ((pub_r001243_0_1 * 2) + 47) & 63;
  int stage_v_360_2 = ((pub_r001243_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_360_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_360_2) & 127;
  int stage_v_361_1 = ((pub_r001243_6_1 * 2) + 8) & 63;
  int stage_v_361_2 = ((pub_r001243_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_361_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_361_2) & 127;
  int stage_v_362_1 = ((pub_r001243_10_1 * 2) + 14) & 63;
  int stage_v_362_2 = ((pub_r001243_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_362_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_362_2) & 127;
  int stage_v_363_1 = (((stage_v_301_1 * 3) + pub_r001243_21_1) + 11) & 127;
  int stage_v_363_2 = (((stage_v_301_2 * 3) + pub_r001243_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_363_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_363_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_363_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_363_2 * 2)) & 255;
  int stage_v_364_1 = (((stage_v_212_1 * 3) + pub_r001243_15_1) + 26) & 127;
  int stage_v_364_2 = (((stage_v_212_2 * 3) + pub_r001243_15_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((stage_v_124_1 * 3) + pub_r001243_21_1) + 14) & 127;
  int stage_v_365_2 = (((stage_v_124_2 * 3) + pub_r001243_21_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001243_5_1 * 2) + 17) & 63;
  int stage_v_366_2 = ((pub_r001243_5_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_323_1 * 3) + pub_r001243_2_1) + 36) & 127;
  int stage_v_367_2 = (((stage_v_323_2 * 3) + pub_r001243_2_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001243_11_1 * 2) + 15) & 63;
  int stage_v_368_2 = ((pub_r001243_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001243_6_1 * 2) + 24) & 63;
  int stage_v_369_2 = ((pub_r001243_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001243_12_1 * 2) + 46) & 63;
  int stage_v_370_2 = ((pub_r001243_12_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001243_16_1 * 2) + 44) & 63;
  int stage_v_371_2 = ((pub_r001243_16_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001243_13_1 * 2) + 22) & 63;
  int stage_v_372_2 = ((pub_r001243_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = ((pub_r001243_20_1 * 2) + 11) & 63;
  int stage_v_373_2 = ((pub_r001243_20_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_373_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_373_2) & 127;
  int stage_v_374_1 = ((pub_r001243_0_1 * 2) + 45) & 63;
  int stage_v_374_2 = ((pub_r001243_0_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001243_5_1 * 2) + 16) & 63;
  int stage_v_375_2 = ((pub_r001243_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001243_13_1 * 2) + 41) & 63;
  int stage_v_376_2 = ((pub_r001243_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001243_8_1 * 2) + 5) & 63;
  int stage_v_377_2 = ((pub_r001243_8_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001243_16_1 * 2) + 31) & 63;
  int stage_v_378_2 = ((pub_r001243_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = (((stage_v_156_1 * 3) + pub_r001243_2_1) + 43) & 127;
  int stage_v_379_2 = (((stage_v_156_2 * 3) + pub_r001243_2_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_379_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_379_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_379_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_379_2 * 2)) & 255;
  int stage_v_380_1 = (((stage_v_45_1 * 3) + pub_r001243_13_1) + 30) & 127;
  int stage_v_380_2 = (((stage_v_45_2 * 3) + pub_r001243_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_380_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_380_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_380_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_380_2 * 2)) & 255;
  int stage_v_381_1 = (((stage_v_137_1 * 3) + pub_r001243_2_1) + 12) & 127;
  int stage_v_381_2 = (((stage_v_137_2 * 3) + pub_r001243_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = (((stage_v_155_1 * 3) + pub_r001243_7_1) + 33) & 127;
  int stage_v_382_2 = (((stage_v_155_2 * 3) + pub_r001243_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_382_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_382_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_382_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_382_2 * 2)) & 255;
  int stage_v_383_1 = (((stage_v_334_1 * 3) + pub_r001243_20_1) + 7) & 127;
  int stage_v_383_2 = (((stage_v_334_2 * 3) + pub_r001243_20_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_383_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_383_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_383_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_383_2 * 2)) & 255;
  int stage_v_384_1 = (((sec_r001243_7_1 * 3) + pub_r001243_7_1) + 11) & 127;
  int stage_v_384_2 = (((sec_r001243_7_2 * 3) + pub_r001243_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001243_8_1 * 2) + 16) & 63;
  int stage_v_385_2 = ((pub_r001243_8_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001243_2_1 * 2) + 8) & 63;
  int stage_v_386_2 = ((pub_r001243_2_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = (((stage_v_262_1 * 3) + pub_r001243_13_1) + 36) & 127;
  int stage_v_387_2 = (((stage_v_262_2 * 3) + pub_r001243_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_387_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_387_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_387_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_387_2 * 2)) & 255;
  int stage_v_388_1 = ((pub_r001243_5_1 * 2) + 22) & 63;
  int stage_v_388_2 = ((pub_r001243_5_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = (((stage_v_112_1 * 3) + pub_r001243_0_1) + 29) & 127;
  int stage_v_389_2 = (((stage_v_112_2 * 3) + pub_r001243_0_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_389_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_389_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_389_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_389_2 * 2)) & 255;
  int stage_v_390_1 = ((pub_r001243_14_1 * 2) + 21) & 63;
  int stage_v_390_2 = ((pub_r001243_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_207_1 * 3) + pub_r001243_7_1) + 32) & 127;
  int stage_v_391_2 = (((stage_v_207_2 * 3) + pub_r001243_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = ((pub_r001243_10_1 * 2) + 44) & 63;
  int stage_v_392_2 = ((pub_r001243_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_126_1 * 3) + pub_r001243_7_1) + 8) & 127;
  int stage_v_393_2 = (((stage_v_126_2 * 3) + pub_r001243_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001243_13_1 * 2) + 8) & 63;
  int stage_v_394_2 = ((pub_r001243_13_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_138_1 * 3) + pub_r001243_15_1) + 45) & 127;
  int stage_v_395_2 = (((stage_v_138_2 * 3) + pub_r001243_15_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = ((pub_r001243_16_1 * 2) + 47) & 63;
  int stage_v_396_2 = ((pub_r001243_16_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_396_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_396_2) & 127;
  int stage_v_397_1 = ((pub_r001243_13_1 * 2) + 28) & 63;
  int stage_v_397_2 = ((pub_r001243_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_216_1 * 3) + pub_r001243_19_1) + 17) & 127;
  int stage_v_398_2 = (((stage_v_216_2 * 3) + pub_r001243_19_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001243_21_1 * 2) + 32) & 63;
  int stage_v_399_2 = ((pub_r001243_21_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001243_21_1 * 2) + 17) & 63;
  int stage_v_400_2 = ((pub_r001243_21_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001243_0_1 * 2) + 13) & 63;
  int stage_v_401_2 = ((pub_r001243_0_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = (((stage_v_41_1 * 3) + pub_r001243_11_1) + 3) & 127;
  int stage_v_402_2 = (((stage_v_41_2 * 3) + pub_r001243_11_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_402_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_402_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_402_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_402_2 * 2)) & 255;
  int stage_v_403_1 = (((stage_v_175_1 * 3) + pub_r001243_12_1) + 45) & 127;
  int stage_v_403_2 = (((stage_v_175_2 * 3) + pub_r001243_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_403_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_403_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_403_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_403_2 * 2)) & 255;
  int stage_v_404_1 = (((sec_r001243_10_1 * 3) + pub_r001243_12_1) + 8) & 127;
  int stage_v_404_2 = (((sec_r001243_10_2 * 3) + pub_r001243_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001243_21_1 * 2) + 21) & 63;
  int stage_v_405_2 = ((pub_r001243_21_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((stage_v_156_1 * 3) + pub_r001243_20_1) + 38) & 127;
  int stage_v_406_2 = (((stage_v_156_2 * 3) + pub_r001243_20_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001243_15_1 * 2) + 18) & 63;
  int stage_v_407_2 = ((pub_r001243_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001243_2_1 * 2) + 37) & 63;
  int stage_v_408_2 = ((pub_r001243_2_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = (((stage_v_354_1 * 3) + pub_r001243_21_1) + 11) & 127;
  int stage_v_409_2 = (((stage_v_354_2 * 3) + pub_r001243_21_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_409_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_409_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_409_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_409_2 * 2)) & 255;
  int stage_v_410_1 = ((pub_r001243_15_1 * 2) + 37) & 63;
  int stage_v_410_2 = ((pub_r001243_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = ((pub_r001243_5_1 * 2) + 20) & 63;
  int stage_v_411_2 = ((pub_r001243_5_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_411_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_411_2) & 127;
  int stage_v_412_1 = (((stage_v_45_1 * 3) + pub_r001243_17_1) + 12) & 127;
  int stage_v_412_2 = (((stage_v_45_2 * 3) + pub_r001243_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001243_21_1 * 2) + 46) & 63;
  int stage_v_413_2 = ((pub_r001243_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((sec_r001243_0_1 * 3) + pub_r001243_19_1) + 16) & 127;
  int stage_v_414_2 = (((sec_r001243_0_2 * 3) + pub_r001243_19_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001243_21_1 * 2) + 46) & 63;
  int stage_v_415_2 = ((pub_r001243_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((sec_r001243_12_1 * 3) + pub_r001243_13_1) + 12) & 127;
  int stage_v_416_2 = (((sec_r001243_12_2 * 3) + pub_r001243_13_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = (((stage_v_236_1 * 3) + pub_r001243_4_1) + 12) & 127;
  int stage_v_417_2 = (((stage_v_236_2 * 3) + pub_r001243_4_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_417_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_417_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_417_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_417_2 * 2)) & 255;
  int stage_v_418_1 = ((pub_r001243_17_1 * 2) + 27) & 63;
  int stage_v_418_2 = ((pub_r001243_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_233_1 * 3) + pub_r001243_20_1) + 35) & 127;
  int stage_v_419_2 = (((stage_v_233_2 * 3) + pub_r001243_20_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = (((stage_v_270_1 * 3) + pub_r001243_18_1) + 19) & 127;
  int stage_v_420_2 = (((stage_v_270_2 * 3) + pub_r001243_18_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001243_12_1 * 2) + 44) & 63;
  int stage_v_421_2 = ((pub_r001243_12_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001243_14_1 * 2) + 27) & 63;
  int stage_v_422_2 = ((pub_r001243_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_128_1 * 3) + pub_r001243_13_1) + 45) & 127;
  int stage_v_423_2 = (((stage_v_128_2 * 3) + pub_r001243_13_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = (((stage_v_226_1 * 3) + pub_r001243_18_1) + 12) & 127;
  int stage_v_424_2 = (((stage_v_226_2 * 3) + pub_r001243_18_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_424_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_424_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_424_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_424_2 * 2)) & 255;
  int stage_v_425_1 = (((stage_v_219_1 * 3) + pub_r001243_13_1) + 13) & 127;
  int stage_v_425_2 = (((stage_v_219_2 * 3) + pub_r001243_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = (((stage_v_334_1 * 3) + pub_r001243_16_1) + 45) & 127;
  int stage_v_426_2 = (((stage_v_334_2 * 3) + pub_r001243_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_292_1 * 3) + pub_r001243_5_1) + 29) & 127;
  int stage_v_427_2 = (((stage_v_292_2 * 3) + pub_r001243_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = ((pub_r001243_1_1 * 2) + 39) & 63;
  int stage_v_428_2 = ((pub_r001243_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = (((stage_v_2_1 * 3) + pub_r001243_3_1) + 12) & 127;
  int stage_v_429_2 = (((stage_v_2_2 * 3) + pub_r001243_3_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = ((pub_r001243_10_1 * 2) + 8) & 63;
  int stage_v_430_2 = ((pub_r001243_10_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_430_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_430_2) & 127;
  int stage_v_431_1 = ((pub_r001243_2_1 * 2) + 48) & 63;
  int stage_v_431_2 = ((pub_r001243_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = ((pub_r001243_18_1 * 2) + 14) & 63;
  int stage_v_432_2 = ((pub_r001243_18_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_432_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_432_2) & 127;
  int stage_v_433_1 = (((stage_v_145_1 * 3) + pub_r001243_4_1) + 8) & 127;
  int stage_v_433_2 = (((stage_v_145_2 * 3) + pub_r001243_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_433_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_433_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_433_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_433_2 * 2)) & 255;
  int stage_v_434_1 = ((pub_r001243_17_1 * 2) + 44) & 63;
  int stage_v_434_2 = ((pub_r001243_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_434_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_434_2) & 127;
  int stage_v_435_1 = ((pub_r001243_6_1 * 2) + 11) & 63;
  int stage_v_435_2 = ((pub_r001243_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_435_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_435_2) & 127;
  int stage_v_436_1 = (((stage_v_352_1 * 3) + pub_r001243_15_1) + 41) & 127;
  int stage_v_436_2 = (((stage_v_352_2 * 3) + pub_r001243_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_436_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_436_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_436_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_436_2 * 2)) & 255;
  int stage_v_437_1 = (((stage_v_344_1 * 3) + pub_r001243_4_1) + 19) & 127;
  int stage_v_437_2 = (((stage_v_344_2 * 3) + pub_r001243_4_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = ((pub_r001243_2_1 * 2) + 25) & 63;
  int stage_v_438_2 = ((pub_r001243_2_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = ((pub_r001243_13_1 * 2) + 9) & 63;
  int stage_v_439_2 = ((pub_r001243_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001243_21_1 * 2) + 26) & 63;
  int stage_v_440_2 = ((pub_r001243_21_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = (((stage_v_295_1 * 3) + pub_r001243_17_1) + 42) & 127;
  int stage_v_441_2 = (((stage_v_295_2 * 3) + pub_r001243_17_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((stage_v_118_1 * 3) + pub_r001243_18_1) + 41) & 127;
  int stage_v_442_2 = (((stage_v_118_2 * 3) + pub_r001243_18_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_193_1 * 3) + pub_r001243_16_1) + 8) & 127;
  int stage_v_443_2 = (((stage_v_193_2 * 3) + pub_r001243_16_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001243_11_1 * 2) + 19) & 63;
  int stage_v_444_2 = ((pub_r001243_11_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001243_17_1 * 2) + 10) & 63;
  int stage_v_445_2 = ((pub_r001243_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001243_20_1 * 2) + 29) & 63;
  int stage_v_446_2 = ((pub_r001243_20_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = (((stage_v_227_1 * 3) + pub_r001243_19_1) + 14) & 127;
  int stage_v_447_2 = (((stage_v_227_2 * 3) + pub_r001243_19_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  int stage_v_448_1 = (((stage_v_83_1 * 3) + pub_r001243_19_1) + 26) & 127;
  int stage_v_448_2 = (((stage_v_83_2 * 3) + pub_r001243_19_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_448_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_448_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_448_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_448_2 * 2)) & 255;
  int stage_v_449_1 = (((stage_v_180_1 * 3) + pub_r001243_18_1) + 18) & 127;
  int stage_v_449_2 = (((stage_v_180_2 * 3) + pub_r001243_18_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_449_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_449_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_449_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_449_2 * 2)) & 255;
  int stage_v_450_1 = ((pub_r001243_21_1 * 2) + 46) & 63;
  int stage_v_450_2 = ((pub_r001243_21_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_450_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_450_2) & 127;
  int stage_v_451_1 = (((stage_v_109_1 * 3) + pub_r001243_3_1) + 21) & 127;
  int stage_v_451_2 = (((stage_v_109_2 * 3) + pub_r001243_3_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_451_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_451_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_451_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_451_2 * 2)) & 255;
  int stage_v_452_1 = (((stage_v_105_1 * 3) + pub_r001243_10_1) + 39) & 127;
  int stage_v_452_2 = (((stage_v_105_2 * 3) + pub_r001243_10_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_452_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_452_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_452_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_452_2 * 2)) & 255;
  int stage_v_453_1 = ((pub_r001243_14_1 * 2) + 37) & 63;
  int stage_v_453_2 = ((pub_r001243_14_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_453_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_453_2) & 127;
  int stage_v_454_1 = (((stage_v_379_1 * 3) + pub_r001243_11_1) + 20) & 127;
  int stage_v_454_2 = (((stage_v_379_2 * 3) + pub_r001243_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_454_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_454_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_454_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_454_2 * 2)) & 255;
  int stage_v_455_1 = ((pub_r001243_20_1 * 2) + 10) & 63;
  int stage_v_455_2 = ((pub_r001243_20_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_455_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_455_2) & 127;
  int stage_v_456_1 = (((stage_v_172_1 * 3) + pub_r001243_6_1) + 16) & 127;
  int stage_v_456_2 = (((stage_v_172_2 * 3) + pub_r001243_6_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_456_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_456_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_456_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_456_2 * 2)) & 255;
  int stage_v_457_1 = ((pub_r001243_6_1 * 2) + 48) & 63;
  int stage_v_457_2 = ((pub_r001243_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_457_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_457_2) & 127;
  int stage_v_458_1 = (((stage_v_301_1 * 3) + pub_r001243_7_1) + 39) & 127;
  int stage_v_458_2 = (((stage_v_301_2 * 3) + pub_r001243_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_458_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_458_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_458_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_458_2 * 2)) & 255;
  int stage_v_459_1 = ((pub_r001243_15_1 * 2) + 32) & 63;
  int stage_v_459_2 = ((pub_r001243_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_459_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_459_2) & 127;
  int stage_v_460_1 = ((pub_r001243_0_1 * 2) + 48) & 63;
  int stage_v_460_2 = ((pub_r001243_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_460_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_460_2) & 127;
  int stage_v_461_1 = (((stage_v_218_1 * 3) + pub_r001243_17_1) + 22) & 127;
  int stage_v_461_2 = (((stage_v_218_2 * 3) + pub_r001243_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_461_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_461_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_461_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_461_2 * 2)) & 255;
  int stage_v_462_1 = (((sec_r001243_11_1 * 3) + pub_r001243_6_1) + 35) & 127;
  int stage_v_462_2 = (((sec_r001243_11_2 * 3) + pub_r001243_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_462_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_462_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_462_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_462_2 * 2)) & 255;
  int stage_v_463_1 = ((pub_r001243_3_1 * 2) + 17) & 63;
  int stage_v_463_2 = ((pub_r001243_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_463_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_463_2) & 127;
  int stage_v_464_1 = ((pub_r001243_19_1 * 2) + 50) & 63;
  int stage_v_464_2 = ((pub_r001243_19_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_464_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_464_2) & 127;
  int stage_v_465_1 = ((pub_r001243_5_1 * 2) + 25) & 63;
  int stage_v_465_2 = ((pub_r001243_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_465_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_465_2) & 127;
  int stage_v_466_1 = ((pub_r001243_2_1 * 2) + 11) & 63;
  int stage_v_466_2 = ((pub_r001243_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_466_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_466_2) & 127;
  int stage_v_467_1 = (((stage_v_285_1 * 3) + pub_r001243_9_1) + 12) & 127;
  int stage_v_467_2 = (((stage_v_285_2 * 3) + pub_r001243_9_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_467_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_467_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_467_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_467_2 * 2)) & 255;
  int stage_v_468_1 = ((pub_r001243_6_1 * 2) + 7) & 63;
  int stage_v_468_2 = ((pub_r001243_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_468_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_468_2) & 127;
  int stage_v_469_1 = (((stage_v_218_1 * 3) + pub_r001243_7_1) + 20) & 127;
  int stage_v_469_2 = (((stage_v_218_2 * 3) + pub_r001243_7_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_469_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_469_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_469_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_469_2 * 2)) & 255;
  int stage_v_470_1 = (((stage_v_456_1 * 3) + pub_r001243_19_1) + 30) & 127;
  int stage_v_470_2 = (((stage_v_456_2 * 3) + pub_r001243_19_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_470_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_470_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_470_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_470_2 * 2)) & 255;
  int stage_v_471_1 = ((pub_r001243_0_1 * 2) + 46) & 63;
  int stage_v_471_2 = ((pub_r001243_0_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_471_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_471_2) & 127;
  int stage_v_472_1 = ((pub_r001243_15_1 * 2) + 38) & 63;
  int stage_v_472_2 = ((pub_r001243_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_472_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_472_2) & 127;
  int stage_v_473_1 = (((sec_r001243_0_1 * 3) + pub_r001243_11_1) + 19) & 127;
  int stage_v_473_2 = (((sec_r001243_0_2 * 3) + pub_r001243_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_473_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_473_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_473_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_473_2 * 2)) & 255;
  int stage_v_474_1 = (((stage_v_391_1 * 3) + pub_r001243_14_1) + 45) & 127;
  int stage_v_474_2 = (((stage_v_391_2 * 3) + pub_r001243_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_474_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_474_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_474_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_474_2 * 2)) & 255;
  int stage_v_475_1 = (((stage_v_389_1 * 3) + pub_r001243_13_1) + 43) & 127;
  int stage_v_475_2 = (((stage_v_389_2 * 3) + pub_r001243_13_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_475_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_475_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_475_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_475_2 * 2)) & 255;
  int stage_v_476_1 = (((stage_v_105_1 * 3) + pub_r001243_12_1) + 24) & 127;
  int stage_v_476_2 = (((stage_v_105_2 * 3) + pub_r001243_12_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_476_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_476_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_476_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_476_2 * 2)) & 255;
  int stage_v_477_1 = (((stage_v_322_1 * 3) + pub_r001243_1_1) + 29) & 127;
  int stage_v_477_2 = (((stage_v_322_2 * 3) + pub_r001243_1_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_477_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_477_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_477_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_477_2 * 2)) & 255;
  int stage_v_478_1 = ((pub_r001243_5_1 * 2) + 29) & 63;
  int stage_v_478_2 = ((pub_r001243_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_478_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_478_2) & 127;
  int stage_v_479_1 = (((stage_v_245_1 * 3) + pub_r001243_11_1) + 43) & 127;
  int stage_v_479_2 = (((stage_v_245_2 * 3) + pub_r001243_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_479_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_479_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_479_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_479_2 * 2)) & 255;
  int stage_v_480_1 = (((stage_v_204_1 * 3) + pub_r001243_12_1) + 29) & 127;
  int stage_v_480_2 = (((stage_v_204_2 * 3) + pub_r001243_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_480_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_480_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_480_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_480_2 * 2)) & 255;
  int stage_v_481_1 = (((sec_r001243_4_1 * 3) + pub_r001243_20_1) + 30) & 127;
  int stage_v_481_2 = (((sec_r001243_4_2 * 3) + pub_r001243_20_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_481_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_481_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_481_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_481_2 * 2)) & 255;
  int stage_v_482_1 = (((stage_v_97_1 * 3) + pub_r001243_20_1) + 34) & 127;
  int stage_v_482_2 = (((stage_v_97_2 * 3) + pub_r001243_20_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_482_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_482_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_482_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_482_2 * 2)) & 255;
  int stage_v_483_1 = ((pub_r001243_4_1 * 2) + 15) & 63;
  int stage_v_483_2 = ((pub_r001243_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_483_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_483_2) & 127;
  int stage_v_484_1 = (((stage_v_42_1 * 3) + pub_r001243_7_1) + 14) & 127;
  int stage_v_484_2 = (((stage_v_42_2 * 3) + pub_r001243_7_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_484_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_484_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_484_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_484_2 * 2)) & 255;
  int stage_v_485_1 = (((stage_v_300_1 * 3) + pub_r001243_0_1) + 15) & 127;
  int stage_v_485_2 = (((stage_v_300_2 * 3) + pub_r001243_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_485_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_485_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_485_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_485_2 * 2)) & 255;
  int stage_v_486_1 = ((pub_r001243_16_1 * 2) + 29) & 63;
  int stage_v_486_2 = ((pub_r001243_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_486_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_486_2) & 127;
  int stage_v_487_1 = ((pub_r001243_7_1 * 2) + 18) & 63;
  int stage_v_487_2 = ((pub_r001243_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_487_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_487_2) & 127;
  int stage_v_488_1 = (((stage_v_462_1 * 3) + pub_r001243_10_1) + 40) & 127;
  int stage_v_488_2 = (((stage_v_462_2 * 3) + pub_r001243_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_488_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_488_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_488_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_488_2 * 2)) & 255;
  int stage_v_489_1 = (((stage_v_207_1 * 3) + pub_r001243_21_1) + 5) & 127;
  int stage_v_489_2 = (((stage_v_207_2 * 3) + pub_r001243_21_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_489_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_489_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_489_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_489_2 * 2)) & 255;
  int stage_v_490_1 = (((stage_v_236_1 * 3) + pub_r001243_13_1) + 23) & 127;
  int stage_v_490_2 = (((stage_v_236_2 * 3) + pub_r001243_13_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_490_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_490_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_490_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_490_2 * 2)) & 255;
  int stage_v_491_1 = ((pub_r001243_4_1 * 2) + 42) & 63;
  int stage_v_491_2 = ((pub_r001243_4_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_491_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_491_2) & 127;
  int stage_v_492_1 = ((pub_r001243_11_1 * 2) + 6) & 63;
  int stage_v_492_2 = ((pub_r001243_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_492_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_492_2) & 127;
  int stage_v_493_1 = (((stage_v_107_1 * 3) + pub_r001243_4_1) + 20) & 127;
  int stage_v_493_2 = (((stage_v_107_2 * 3) + pub_r001243_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_493_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_493_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_493_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_493_2 * 2)) & 255;
  int stage_v_494_1 = (((stage_v_248_1 * 3) + pub_r001243_20_1) + 22) & 127;
  int stage_v_494_2 = (((stage_v_248_2 * 3) + pub_r001243_20_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_494_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_494_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_494_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_494_2 * 2)) & 255;
  int stage_v_495_1 = ((pub_r001243_3_1 * 2) + 30) & 63;
  int stage_v_495_2 = ((pub_r001243_3_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_495_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_495_2) & 127;
  int stage_v_496_1 = (((stage_v_311_1 * 3) + pub_r001243_21_1) + 23) & 127;
  int stage_v_496_2 = (((stage_v_311_2 * 3) + pub_r001243_21_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_496_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_496_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_496_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_496_2 * 2)) & 255;
  int stage_v_497_1 = ((pub_r001243_5_1 * 2) + 43) & 63;
  int stage_v_497_2 = ((pub_r001243_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_497_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_497_2) & 127;
  int stage_v_498_1 = (((stage_v_213_1 * 3) + pub_r001243_9_1) + 38) & 127;
  int stage_v_498_2 = (((stage_v_213_2 * 3) + pub_r001243_9_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_498_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_498_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_498_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_498_2 * 2)) & 255;
  int stage_v_499_1 = (((helper_flow_1_1 * 3) + pub_r001243_7_1) + 11) & 127;
  int stage_v_499_2 = (((helper_flow_1_2 * 3) + pub_r001243_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_499_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_499_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_499_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_499_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001243_2_1 == pub_r001243_2_2);
  __CPROVER_assume(sec_r001243_1_1 != sec_r001243_1_2);
  __CPROVER_assume(pub_r001243_4_1 == pub_r001243_4_2);
  __CPROVER_assume(pub_r001243_5_1 == pub_r001243_5_2);
  __CPROVER_assume(sec_r001243_3_1 != sec_r001243_3_2);
  __CPROVER_assume(sec_r001243_14_1 != sec_r001243_14_2);
  __CPROVER_assume(sec_r001243_0_1 != sec_r001243_0_2);
  __CPROVER_assume(pub_r001243_17_1 == pub_r001243_17_2);
  __CPROVER_assume(pub_r001243_14_1 == pub_r001243_14_2);
  __CPROVER_assume(sec_r001243_8_1 != sec_r001243_8_2);
  __CPROVER_assume(pub_r001243_20_1 == pub_r001243_20_2);
  __CPROVER_assume(sec_r001243_9_1 != sec_r001243_9_2);
  __CPROVER_assume(pub_r001243_7_1 == pub_r001243_7_2);
  __CPROVER_assume(pub_r001243_19_1 == pub_r001243_19_2);
  __CPROVER_assume(pub_r001243_9_1 == pub_r001243_9_2);
  __CPROVER_assume(sec_r001243_6_1 != sec_r001243_6_2);
  __CPROVER_assume(pub_r001243_0_1 == pub_r001243_0_2);
  __CPROVER_assume(pub_r001243_18_1 == pub_r001243_18_2);
  __CPROVER_assume(sec_r001243_13_1 != sec_r001243_13_2);
  __CPROVER_assume(sec_r001243_4_1 != sec_r001243_4_2);
  __CPROVER_assume(pub_r001243_13_1 == pub_r001243_13_2);
  __CPROVER_assume(sec_r001243_7_1 != sec_r001243_7_2);
  __CPROVER_assume(pub_r001243_16_1 == pub_r001243_16_2);
  __CPROVER_assume(pub_r001243_12_1 == pub_r001243_12_2);
  __CPROVER_assume(pub_r001243_15_1 == pub_r001243_15_2);
  __CPROVER_assume(pub_r001243_8_1 == pub_r001243_8_2);
  __CPROVER_assume(sec_r001243_15_1 != sec_r001243_15_2);
  __CPROVER_assume(sec_r001243_5_1 != sec_r001243_5_2);
  __CPROVER_assume(pub_r001243_21_1 == pub_r001243_21_2);
  __CPROVER_assume(sec_r001243_12_1 != sec_r001243_12_2);
  __CPROVER_assume(pub_r001243_3_1 == pub_r001243_3_2);
  __CPROVER_assume(pub_r001243_6_1 == pub_r001243_6_2);
  __CPROVER_assume(sec_r001243_10_1 != sec_r001243_10_2);
  __CPROVER_assume(pub_r001243_1_1 == pub_r001243_1_2);
  __CPROVER_assume(sec_r001243_2_1 != sec_r001243_2_2);
  __CPROVER_assume(sec_r001243_11_1 != sec_r001243_11_2);
  __CPROVER_assume(pub_r001243_11_1 == pub_r001243_11_2);
  __CPROVER_assume(pub_r001243_10_1 == pub_r001243_10_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
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
}


