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
struct Vector3D_R001552_5213_0
{
  short coord_y;
  unsigned char coord_z;
  int pitch;
  int norm_sq;
  unsigned char coord_x;
  short heading;
  int buffer[3];
};
struct StreamBuffer_R001552_5213_1
{
  int state;
  unsigned char head;
  unsigned char capacity;
  unsigned char tail;
  int checksum;
  unsigned char watermark;
  int buffer[3];
};
union TelemetryField_R001552_5213_0
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
void fn_R001552_5213_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int scale_73_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_73_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_73_1)
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

  switch (scale_73_2)
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

  int weight_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_73_1 > 49)
  {
    acc_1 = ((acc_1 + (weight_73_1 * 2)) + 5) & 127;
    aux_1 ^= weight_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_73_2 > 49)
  {
    acc_2 = ((acc_2 + (weight_73_2 * 2)) + 5) & 127;
    aux_2 ^= weight_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_73_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_73_1 == scale_73_2);
  assert(weight_73_1 == weight_73_2);
}

int fn_R001552_5213_0(int p0, int p1)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int scale_73 = (aux + st.buffer[1]) & 3;
  switch (scale_73)
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

  int weight_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_73 > 49)
  {
    acc = ((acc + (weight_73 * 2)) + 5) & 127;
    aux ^= weight_73 & 15;
  }
  else
  {
    acc = ((acc - weight_73) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001552_5213_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int phase_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_83_1)
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

  switch (phase_83_2)
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

  int anchor_59_1 = 0;
  int anchor_59_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    anchor_59_1 = ((anchor_59_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_59_2 = ((anchor_59_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_59_1) & 127;
    acc_2 = (acc_2 + anchor_59_2) & 127;
  }

  int damping_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_13_1) & 63;
  aux_2 = (aux_2 + damping_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_83_1 == phase_83_2);
  assert(anchor_59_1 == anchor_59_2);
  assert(damping_13_1 == damping_13_2);
}

int fn_R001552_5213_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int phase_83 = (aux + st.buffer[1]) & 3;
  switch (phase_83)
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

  int anchor_59 = 0;
  for (int k = 0; k < 3; k++)
  {
    anchor_59 = ((anchor_59 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_59) & 127;
  }

  int damping_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001552_5213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int cursor_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_31_1 > 44)
  {
    acc_1 = ((acc_1 + (cursor_31_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_31_2 > 44)
  {
    acc_2 = ((acc_2 + (cursor_31_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int accumulator_54_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_54_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_54_1) & 63;
  aux_2 = (aux_2 + accumulator_54_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_57_1 = (aux_1 + st_1.buffer[1]) & 3;
  int factor_57_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (factor_57_1)
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

  switch (factor_57_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_31_1 == cursor_31_2);
  assert(accumulator_54_1 == accumulator_54_2);
  assert(factor_57_1 == factor_57_2);
}

int fn_R001552_5213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int cursor_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_31 > 44)
  {
    acc = ((acc + (cursor_31 * 2)) + 5) & 127;
    aux ^= cursor_31 & 15;
  }
  else
  {
    acc = ((acc - cursor_31) + 11) & 127;
    aux += 3;
  }
  int accumulator_54 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_54) & 63;
  acc ^= aux;
  int factor_57 = (aux + st.buffer[1]) & 3;
  switch (factor_57)
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

void fn_R001552_5213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_72_1) & 63;
  aux_2 = (aux_2 + threshold_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int coefficient_16_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_16_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_16_1)
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

  switch (coefficient_16_2)
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
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_72_1 == threshold_72_2);
  assert(coefficient_16_1 == coefficient_16_2);
}

int fn_R001552_5213_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_72) & 63;
  acc ^= aux;
  int coefficient_16 = (aux + st.buffer[1]) & 3;
  switch (coefficient_16)
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

void fn_R001552_5213_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int pivot_38_1 = 0;
  int pivot_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    pivot_38_1 = ((pivot_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    pivot_38_2 = ((pivot_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + pivot_38_1) & 127;
    acc_2 = (acc_2 + pivot_38_2) & 127;
  }

  int threshold_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_96_1) & 63;
  aux_2 = (aux_2 + threshold_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_43_1 > 30)
  {
    acc_1 = ((acc_1 + (anchor_43_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_43_2 > 30)
  {
    acc_2 = ((acc_2 + (anchor_43_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_43_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_38_1 == pivot_38_2);
  assert(threshold_96_1 == threshold_96_2);
  assert(anchor_43_1 == anchor_43_2);
}

int fn_R001552_5213_4(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int pivot_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    pivot_38 = ((pivot_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + pivot_38) & 127;
  }

  int threshold_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_96) & 63;
  acc ^= aux;
  int anchor_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_43 > 30)
  {
    acc = ((acc + (anchor_43 * 2)) + 5) & 127;
    aux ^= anchor_43 & 15;
  }
  else
  {
    acc = ((acc - anchor_43) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001552_5213_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int anchor_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_13_1)
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

  switch (anchor_13_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_84_1) & 63;
  aux_2 = (aux_2 + index_reg_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_35_1 > 23)
  {
    acc_1 = ((acc_1 + (checksum_35_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_35_2 > 23)
  {
    acc_2 = ((acc_2 + (checksum_35_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_35_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_13_1 == anchor_13_2);
  assert(index_reg_84_1 == index_reg_84_2);
  assert(checksum_35_1 == checksum_35_2);
}

int fn_R001552_5213_5(int p0, int p1, int p2)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int anchor_13 = (aux + st.buffer[1]) & 3;
  switch (anchor_13)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_84) & 63;
  acc ^= aux;
  int checksum_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_35 > 23)
  {
    acc = ((acc + (checksum_35 * 2)) + 5) & 127;
    aux ^= checksum_35 & 15;
  }
  else
  {
    acc = ((acc - checksum_35) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001552_5213_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_93_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_93_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_93_1) & 63;
  aux_2 = (aux_2 + tally_93_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_36_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_36_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_36_1 > 10)
  {
    acc_1 = ((acc_1 + (cursor_36_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_36_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_36_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_36_2 > 10)
  {
    acc_2 = ((acc_2 + (cursor_36_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_36_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_36_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_87_1 = local_arr_1[aux_1 % 3];
  int metric_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_87_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_93_1 == tally_93_2);
  assert(cursor_36_1 == cursor_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_87_1 == metric_87_2);
}

int fn_R001552_5213_6(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_93 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_93) & 63;
  acc ^= aux;
  int cursor_36 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_36 > 10)
  {
    acc = ((acc + (cursor_36 * 2)) + 5) & 127;
    aux ^= cursor_36 & 15;
  }
  else
  {
    acc = ((acc - cursor_36) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int metric_87 = local_arr[aux % 3];
  acc = (acc + (metric_87 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001552_5213_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int phase_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_61_1)
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

  switch (phase_61_2)
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

  int margin_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_18_1) & 63;
  aux_2 = (aux_2 + margin_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_25_1 = 0;
  int mask_25_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_25_1 = ((mask_25_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_25_2 = ((mask_25_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_25_1) & 127;
    acc_2 = (acc_2 + mask_25_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_61_1 = local_arr_1[aux_1 % 3];
  int phase_61_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_61_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_61_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_61_1 == phase_61_2);
  assert(margin_18_1 == margin_18_2);
  assert(mask_25_1 == mask_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

}

int fn_R001552_5213_7(int p0, int p1)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int phase_61 = (aux + st.buffer[1]) & 3;
  switch (phase_61)
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

  int margin_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_18) & 63;
  acc ^= aux;
  int mask_25 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_25 = ((mask_25 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_25) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_61 = local_arr[aux % 3];
  acc = (acc + (phase_61 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001552_5213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int threshold_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_94_1)
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

  switch (threshold_94_2)
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

  int checksum_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_50_1) & 63;
  aux_2 = (aux_2 + checksum_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_51_1 = 0;
  int factor_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_51_1 = ((factor_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_51_2 = ((factor_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_51_1) & 127;
    acc_2 = (acc_2 + factor_51_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_46_1 = local_arr_1[aux_1 % 3];
  int anchor_46_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_46_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_46_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_94_1 == threshold_94_2);
  assert(checksum_50_1 == checksum_50_2);
  assert(factor_51_1 == factor_51_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_46_1 == anchor_46_2);
}

int fn_R001552_5213_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int threshold_94 = (aux + st.buffer[1]) & 3;
  switch (threshold_94)
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

  int checksum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_50) & 63;
  acc ^= aux;
  int factor_51 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_51 = ((factor_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_51) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int anchor_46 = local_arr[aux % 3];
  acc = (acc + (anchor_46 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001552_5213_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int weight_23_1 = 0;
  int weight_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_23_1 = ((weight_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_23_2 = ((weight_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_23_1) & 127;
    acc_2 = (acc_2 + weight_23_2) & 127;
  }

  int offset_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_88_1) & 63;
  aux_2 = (aux_2 + offset_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_23_1 == weight_23_2);
  assert(offset_88_1 == offset_88_2);
}

int fn_R001552_5213_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int weight_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_23 = ((weight_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_23) & 127;
  }

  int offset_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001552_5213_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int factor_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_88_1) & 63;
  aux_2 = (aux_2 + factor_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_25_1 = local_arr_1[aux_1 % 3];
  int scale_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_25_2 * 2)) & 127;
  int quantum_35_1 = 0;
  int quantum_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_35_1 = ((quantum_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_35_2 = ((quantum_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_35_1) & 127;
    acc_2 = (acc_2 + quantum_35_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_88_1 == factor_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_25_1 == scale_25_2);
  assert(quantum_35_1 == quantum_35_2);
}

int fn_R001552_5213_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int factor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_88) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_25 = local_arr[aux % 3];
  acc = (acc + (scale_25 * 2)) & 127;
  int quantum_35 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_35 = ((quantum_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_35) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001552_5213_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int segment_65_1 = local_arr_1[aux_1 % 3];
  int segment_65_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (segment_65_1 * 2)) & 127;
  acc_2 = (acc_2 + (segment_65_2 * 2)) & 127;
  int delta_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_26_1 > 47)
  {
    acc_1 = ((acc_1 + (delta_26_1 * 2)) + 5) & 127;
    aux_1 ^= delta_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_26_2 > 47)
  {
    acc_2 = ((acc_2 + (delta_26_2 * 2)) + 5) & 127;
    aux_2 ^= delta_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_94_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_94_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_94_1) & 63;
  aux_2 = (aux_2 + delta_94_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(segment_65_1 == segment_65_2);
  assert(delta_26_1 == delta_26_2);
  assert(delta_94_1 == delta_94_2);
}

int fn_R001552_5213_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int segment_65 = local_arr[aux % 3];
  acc = (acc + (segment_65 * 2)) & 127;
  int delta_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_26 > 47)
  {
    acc = ((acc + (delta_26 * 2)) + 5) & 127;
    aux ^= delta_26 & 15;
  }
  else
  {
    acc = ((acc - delta_26) + 11) & 127;
    aux += 3;
  }
  int delta_94 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_94) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001552_5213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_43_1 = 0;
  int metric_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_43_1 = ((metric_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_43_2 = ((metric_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_43_1) & 127;
    acc_2 = (acc_2 + metric_43_2) & 127;
  }

  int margin_65_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_65_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_65_1) & 63;
  aux_2 = (aux_2 + margin_65_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_54_1 > 40)
  {
    acc_1 = ((acc_1 + (factor_54_1 * 2)) + 5) & 127;
    aux_1 ^= factor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_54_2 > 40)
  {
    acc_2 = ((acc_2 + (factor_54_2 * 2)) + 5) & 127;
    aux_2 ^= factor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_43_1 == metric_43_2);
  assert(margin_65_1 == margin_65_2);
  assert(factor_54_1 == factor_54_2);
}

int fn_R001552_5213_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_43 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_43 = ((metric_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_43) & 127;
  }

  int margin_65 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_65) & 63;
  acc ^= aux;
  int factor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_54 > 40)
  {
    acc = ((acc + (factor_54 * 2)) + 5) & 127;
    aux ^= factor_54 & 15;
  }
  else
  {
    acc = ((acc - factor_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001552_5213_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int parity_24_1 = 0;
  int parity_24_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    parity_24_1 = ((parity_24_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_24_2 = ((parity_24_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_24_1) & 127;
    acc_2 = (acc_2 + parity_24_2) & 127;
  }

  int delta_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_18_1) & 63;
  aux_2 = (aux_2 + delta_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_24_1 == parity_24_2);
  assert(delta_18_1 == delta_18_2);
}

int fn_R001552_5213_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int parity_24 = 0;
  for (int k = 0; k < 2; k++)
  {
    parity_24 = ((parity_24 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_24) & 127;
  }

  int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_18) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001552_5213_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int sample_48_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_48_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_48_1 > 13)
  {
    acc_1 = ((acc_1 + (sample_48_1 * 2)) + 5) & 127;
    aux_1 ^= sample_48_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_48_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_48_2 > 13)
  {
    acc_2 = ((acc_2 + (sample_48_2 * 2)) + 5) & 127;
    aux_2 ^= sample_48_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_48_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_45_1 = 0;
  int margin_45_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    margin_45_1 = ((margin_45_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    margin_45_2 = ((margin_45_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + margin_45_1) & 127;
    acc_2 = (acc_2 + margin_45_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_50_1 = local_arr_1[aux_1 % 3];
  int vector_50_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_50_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_50_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_48_1 == sample_48_2);
  assert(margin_45_1 == margin_45_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_50_1 == vector_50_2);
}

int fn_R001552_5213_14(int p0, int p1, int p2)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int sample_48 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_48 > 13)
  {
    acc = ((acc + (sample_48 * 2)) + 5) & 127;
    aux ^= sample_48 & 15;
  }
  else
  {
    acc = ((acc - sample_48) + 11) & 127;
    aux += 3;
  }
  int margin_45 = 0;
  for (int k = 0; k < 2; k++)
  {
    margin_45 = ((margin_45 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + margin_45) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int vector_50 = local_arr[aux % 3];
  acc = (acc + (vector_50 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001552_5213_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int accumulator_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_32_1)
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

  switch (accumulator_32_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_32_1 == accumulator_32_2);
}

int fn_R001552_5213_15(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int accumulator_32 = (aux + st.buffer[1]) & 3;
  switch (accumulator_32)
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

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001552_5213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st_1 = {0};
  struct Vector3D_R001552_5213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int scale_12_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_12_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_12_1) & 63;
  aux_2 = (aux_2 + scale_12_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_46_1 = 0;
  int segment_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_46_1 = ((segment_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_46_2 = ((segment_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_46_1) & 127;
    acc_2 = (acc_2 + segment_46_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_12_1 == scale_12_2);
  assert(segment_46_1 == segment_46_2);
}

int fn_R001552_5213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001552_5213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int scale_12 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_12) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_46 = ((segment_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_46) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001552_5213_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int accumulator_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int accumulator_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (accumulator_65_1)
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

  switch (accumulator_65_2)
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

  int sample_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_68_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_68_1 * 2)) + 5) & 127;
    aux_1 ^= sample_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_68_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_68_2 * 2)) + 5) & 127;
    aux_2 ^= sample_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_68_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_65_1 == accumulator_65_2);
  assert(sample_68_1 == sample_68_2);
}

int fn_R001552_5213_17(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int accumulator_65 = (aux + st.buffer[1]) & 3;
  switch (accumulator_65)
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

  int sample_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_68 > 30)
  {
    acc = ((acc + (sample_68 * 2)) + 5) & 127;
    aux ^= sample_68 & 15;
  }
  else
  {
    acc = ((acc - sample_68) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001552_5213_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_99_1 = 0;
  int damping_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    damping_99_1 = ((damping_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_99_2 = ((damping_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_99_1) & 127;
    acc_2 = (acc_2 + damping_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.state == st_2.state);
  assert(st_1.head == st_2.head);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.tail == st_2.tail);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.watermark == st_2.watermark);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_99_1 == damping_99_2);
}

int fn_R001552_5213_18(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001552_5213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    damping_99 = ((damping_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_99) & 127;
  }

  return (acc + aux) & 255;
}

void main()
{
  int sec_r001552_0_1;
  int sec_r001552_0_2;
  int sec_r001552_1_1;
  int sec_r001552_1_2;
  int sec_r001552_2_1;
  int sec_r001552_2_2;
  int sec_r001552_3_1;
  int sec_r001552_3_2;
  int sec_r001552_4_1;
  int sec_r001552_4_2;
  int sec_r001552_5_1;
  int sec_r001552_5_2;
  int sec_r001552_6_1;
  int sec_r001552_6_2;
  int sec_r001552_7_1;
  int sec_r001552_7_2;
  int sec_r001552_8_1;
  int sec_r001552_8_2;
  int sec_r001552_9_1;
  int sec_r001552_9_2;
  int sec_r001552_10_1;
  int sec_r001552_10_2;
  int sec_r001552_11_1;
  int sec_r001552_11_2;
  int sec_r001552_12_1;
  int sec_r001552_12_2;
  int sec_r001552_13_1;
  int sec_r001552_13_2;
  int sec_r001552_14_1;
  int sec_r001552_14_2;
  int sec_r001552_15_1;
  int sec_r001552_15_2;
  int sec_r001552_16_1;
  int sec_r001552_16_2;
  int sec_r001552_17_1;
  int sec_r001552_17_2;
  int sec_r001552_18_1;
  int sec_r001552_18_2;
  int sec_r001552_19_1;
  int sec_r001552_19_2;
  int sec_r001552_20_1;
  int sec_r001552_20_2;
  int sec_r001552_21_1;
  int sec_r001552_21_2;
  int pub_r001552_0_1;
  int pub_r001552_0_2;
  int pub_r001552_1_1;
  int pub_r001552_1_2;
  int pub_r001552_2_1;
  int pub_r001552_2_2;
  int pub_r001552_3_1;
  int pub_r001552_3_2;
  int pub_r001552_4_1;
  int pub_r001552_4_2;
  int pub_r001552_5_1;
  int pub_r001552_5_2;
  int pub_r001552_6_1;
  int pub_r001552_6_2;
  int pub_r001552_7_1;
  int pub_r001552_7_2;
  int pub_r001552_8_1;
  int pub_r001552_8_2;
  int pub_r001552_9_1;
  int pub_r001552_9_2;
  int pub_r001552_10_1;
  int pub_r001552_10_2;
  int pub_r001552_11_1;
  int pub_r001552_11_2;
  int pub_r001552_12_1;
  int pub_r001552_12_2;
  int pub_r001552_13_1;
  int pub_r001552_13_2;
  int pub_r001552_14_1;
  int pub_r001552_14_2;
  int pub_r001552_15_1;
  int pub_r001552_15_2;
  int pub_r001552_16_1;
  int pub_r001552_16_2;
  int pub_r001552_17_1;
  int pub_r001552_17_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001552_0_1 >= (-100)) && (pub_r001552_0_1 <= 100));
  __CPROVER_assume((pub_r001552_0_2 >= (-100)) && (pub_r001552_0_2 <= 100));
  __CPROVER_assume((pub_r001552_1_1 >= (-100)) && (pub_r001552_1_1 <= 100));
  __CPROVER_assume((pub_r001552_1_2 >= (-100)) && (pub_r001552_1_2 <= 100));
  __CPROVER_assume((pub_r001552_2_1 >= (-100)) && (pub_r001552_2_1 <= 100));
  __CPROVER_assume((pub_r001552_2_2 >= (-100)) && (pub_r001552_2_2 <= 100));
  __CPROVER_assume((pub_r001552_3_1 >= (-100)) && (pub_r001552_3_1 <= 100));
  __CPROVER_assume((pub_r001552_3_2 >= (-100)) && (pub_r001552_3_2 <= 100));
  __CPROVER_assume((pub_r001552_4_1 >= (-100)) && (pub_r001552_4_1 <= 100));
  __CPROVER_assume((pub_r001552_4_2 >= (-100)) && (pub_r001552_4_2 <= 100));
  __CPROVER_assume((pub_r001552_5_1 >= (-100)) && (pub_r001552_5_1 <= 100));
  __CPROVER_assume((pub_r001552_5_2 >= (-100)) && (pub_r001552_5_2 <= 100));
  __CPROVER_assume((pub_r001552_6_1 >= (-100)) && (pub_r001552_6_1 <= 100));
  __CPROVER_assume((pub_r001552_6_2 >= (-100)) && (pub_r001552_6_2 <= 100));
  __CPROVER_assume((pub_r001552_7_1 >= (-100)) && (pub_r001552_7_1 <= 100));
  __CPROVER_assume((pub_r001552_7_2 >= (-100)) && (pub_r001552_7_2 <= 100));
  __CPROVER_assume((pub_r001552_8_1 >= (-100)) && (pub_r001552_8_1 <= 100));
  __CPROVER_assume((pub_r001552_8_2 >= (-100)) && (pub_r001552_8_2 <= 100));
  __CPROVER_assume((pub_r001552_9_1 >= (-100)) && (pub_r001552_9_1 <= 100));
  __CPROVER_assume((pub_r001552_9_2 >= (-100)) && (pub_r001552_9_2 <= 100));
  __CPROVER_assume((pub_r001552_10_1 >= (-100)) && (pub_r001552_10_1 <= 100));
  __CPROVER_assume((pub_r001552_10_2 >= (-100)) && (pub_r001552_10_2 <= 100));
  __CPROVER_assume((pub_r001552_11_1 >= (-100)) && (pub_r001552_11_1 <= 100));
  __CPROVER_assume((pub_r001552_11_2 >= (-100)) && (pub_r001552_11_2 <= 100));
  __CPROVER_assume((pub_r001552_12_1 >= (-100)) && (pub_r001552_12_1 <= 100));
  __CPROVER_assume((pub_r001552_12_2 >= (-100)) && (pub_r001552_12_2 <= 100));
  __CPROVER_assume((pub_r001552_13_1 >= (-100)) && (pub_r001552_13_1 <= 100));
  __CPROVER_assume((pub_r001552_13_2 >= (-100)) && (pub_r001552_13_2 <= 100));
  __CPROVER_assume((pub_r001552_14_1 >= (-100)) && (pub_r001552_14_1 <= 100));
  __CPROVER_assume((pub_r001552_14_2 >= (-100)) && (pub_r001552_14_2 <= 100));
  __CPROVER_assume((pub_r001552_15_1 >= (-100)) && (pub_r001552_15_1 <= 100));
  __CPROVER_assume((pub_r001552_15_2 >= (-100)) && (pub_r001552_15_2 <= 100));
  __CPROVER_assume((pub_r001552_16_1 >= (-100)) && (pub_r001552_16_1 <= 100));
  __CPROVER_assume((pub_r001552_16_2 >= (-100)) && (pub_r001552_16_2 <= 100));
  __CPROVER_assume((pub_r001552_17_1 >= (-100)) && (pub_r001552_17_1 <= 100));
  __CPROVER_assume((pub_r001552_17_2 >= (-100)) && (pub_r001552_17_2 <= 100));
  __CPROVER_assume((sec_r001552_0_1 >= 0) && (sec_r001552_0_1 <= 255));
  __CPROVER_assume((sec_r001552_0_2 >= 0) && (sec_r001552_0_2 <= 255));
  __CPROVER_assume((sec_r001552_1_1 >= 0) && (sec_r001552_1_1 <= 255));
  __CPROVER_assume((sec_r001552_1_2 >= 0) && (sec_r001552_1_2 <= 255));
  __CPROVER_assume((sec_r001552_2_1 >= 0) && (sec_r001552_2_1 <= 255));
  __CPROVER_assume((sec_r001552_2_2 >= 0) && (sec_r001552_2_2 <= 255));
  __CPROVER_assume((sec_r001552_3_1 >= 0) && (sec_r001552_3_1 <= 255));
  __CPROVER_assume((sec_r001552_3_2 >= 0) && (sec_r001552_3_2 <= 255));
  __CPROVER_assume((sec_r001552_4_1 >= 0) && (sec_r001552_4_1 <= 255));
  __CPROVER_assume((sec_r001552_4_2 >= 0) && (sec_r001552_4_2 <= 255));
  __CPROVER_assume((sec_r001552_5_1 >= 0) && (sec_r001552_5_1 <= 255));
  __CPROVER_assume((sec_r001552_5_2 >= 0) && (sec_r001552_5_2 <= 255));
  __CPROVER_assume((sec_r001552_6_1 >= 0) && (sec_r001552_6_1 <= 255));
  __CPROVER_assume((sec_r001552_6_2 >= 0) && (sec_r001552_6_2 <= 255));
  __CPROVER_assume((sec_r001552_7_1 >= 0) && (sec_r001552_7_1 <= 255));
  __CPROVER_assume((sec_r001552_7_2 >= 0) && (sec_r001552_7_2 <= 255));
  __CPROVER_assume((sec_r001552_8_1 >= 0) && (sec_r001552_8_1 <= 255));
  __CPROVER_assume((sec_r001552_8_2 >= 0) && (sec_r001552_8_2 <= 255));
  __CPROVER_assume((sec_r001552_9_1 >= 0) && (sec_r001552_9_1 <= 255));
  __CPROVER_assume((sec_r001552_9_2 >= 0) && (sec_r001552_9_2 <= 255));
  __CPROVER_assume((sec_r001552_10_1 >= 0) && (sec_r001552_10_1 <= 255));
  __CPROVER_assume((sec_r001552_10_2 >= 0) && (sec_r001552_10_2 <= 255));
  __CPROVER_assume((sec_r001552_11_1 >= 0) && (sec_r001552_11_1 <= 255));
  __CPROVER_assume((sec_r001552_11_2 >= 0) && (sec_r001552_11_2 <= 255));
  __CPROVER_assume((sec_r001552_12_1 >= 0) && (sec_r001552_12_1 <= 255));
  __CPROVER_assume((sec_r001552_12_2 >= 0) && (sec_r001552_12_2 <= 255));
  __CPROVER_assume((sec_r001552_13_1 >= 0) && (sec_r001552_13_1 <= 255));
  __CPROVER_assume((sec_r001552_13_2 >= 0) && (sec_r001552_13_2 <= 255));
  __CPROVER_assume((sec_r001552_14_1 >= 0) && (sec_r001552_14_1 <= 255));
  __CPROVER_assume((sec_r001552_14_2 >= 0) && (sec_r001552_14_2 <= 255));
  __CPROVER_assume((sec_r001552_15_1 >= 0) && (sec_r001552_15_1 <= 255));
  __CPROVER_assume((sec_r001552_15_2 >= 0) && (sec_r001552_15_2 <= 255));
  __CPROVER_assume((sec_r001552_16_1 >= 0) && (sec_r001552_16_1 <= 255));
  __CPROVER_assume((sec_r001552_16_2 >= 0) && (sec_r001552_16_2 <= 255));
  __CPROVER_assume((sec_r001552_17_1 >= 0) && (sec_r001552_17_1 <= 255));
  __CPROVER_assume((sec_r001552_17_2 >= 0) && (sec_r001552_17_2 <= 255));
  __CPROVER_assume((sec_r001552_18_1 >= 0) && (sec_r001552_18_1 <= 255));
  __CPROVER_assume((sec_r001552_18_2 >= 0) && (sec_r001552_18_2 <= 255));
  __CPROVER_assume((sec_r001552_19_1 >= 0) && (sec_r001552_19_1 <= 255));
  __CPROVER_assume((sec_r001552_19_2 >= 0) && (sec_r001552_19_2 <= 255));
  __CPROVER_assume((sec_r001552_20_1 >= 0) && (sec_r001552_20_1 <= 255));
  __CPROVER_assume((sec_r001552_20_2 >= 0) && (sec_r001552_20_2 <= 255));
  __CPROVER_assume((sec_r001552_21_1 >= 0) && (sec_r001552_21_1 <= 255));
  __CPROVER_assume((sec_r001552_21_2 >= 0) && (sec_r001552_21_2 <= 255));
  struct Vector3D_R001552_5213_0 st_var_0_1 = {0};
  struct Vector3D_R001552_5213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001552_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001552_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001552_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001552_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001552_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001552_0_2 + 7) & 15;
  struct StreamBuffer_R001552_5213_1 st_var_1_1 = {0};
  struct StreamBuffer_R001552_5213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001552_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001552_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001552_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001552_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001552_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001552_0_2 + 9) & 15;
  union TelemetryField_R001552_5213_0 u_var_1;
  union TelemetryField_R001552_5213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001552_5213_0(sec_r001552_0_1, pub_r001552_1_1);
  int helper_flow_0_2 = fn_R001552_5213_0(sec_r001552_0_2, pub_r001552_1_2);
  fn_R001552_5213_0_2(sec_r001552_0_1, pub_r001552_1_1, sec_r001552_0_2, pub_r001552_1_2);
  int helper_flow_1_1 = fn_R001552_5213_1(sec_r001552_1_1, sec_r001552_2_1, pub_r001552_3_1, pub_r001552_4_1, pub_r001552_5_1);
  int helper_flow_1_2 = fn_R001552_5213_1(sec_r001552_1_2, sec_r001552_2_2, pub_r001552_3_2, pub_r001552_4_2, pub_r001552_5_2);
  fn_R001552_5213_1_2(sec_r001552_1_1, sec_r001552_2_1, pub_r001552_3_1, pub_r001552_4_1, pub_r001552_5_1, sec_r001552_1_2, sec_r001552_2_2, pub_r001552_3_2, pub_r001552_4_2, pub_r001552_5_2);
  int helper_flow_2_1 = fn_R001552_5213_2(sec_r001552_2_1, pub_r001552_3_1, pub_r001552_4_1, pub_r001552_5_1);
  int helper_flow_2_2 = fn_R001552_5213_2(sec_r001552_2_2, pub_r001552_3_2, pub_r001552_4_2, pub_r001552_5_2);
  fn_R001552_5213_2_2(sec_r001552_2_1, pub_r001552_3_1, pub_r001552_4_1, pub_r001552_5_1, sec_r001552_2_2, pub_r001552_3_2, pub_r001552_4_2, pub_r001552_5_2);
  int helper_flow_3_1 = fn_R001552_5213_3(sec_r001552_3_1, sec_r001552_4_1, pub_r001552_5_1, pub_r001552_6_1, pub_r001552_7_1);
  int helper_flow_3_2 = fn_R001552_5213_3(sec_r001552_3_2, sec_r001552_4_2, pub_r001552_5_2, pub_r001552_6_2, pub_r001552_7_2);
  fn_R001552_5213_3_2(sec_r001552_3_1, sec_r001552_4_1, pub_r001552_5_1, pub_r001552_6_1, pub_r001552_7_1, sec_r001552_3_2, sec_r001552_4_2, pub_r001552_5_2, pub_r001552_6_2, pub_r001552_7_2);
  int helper_flow_4_1 = fn_R001552_5213_4(sec_r001552_4_1, sec_r001552_5_1, pub_r001552_6_1);
  int helper_flow_4_2 = fn_R001552_5213_4(sec_r001552_4_2, sec_r001552_5_2, pub_r001552_6_2);
  fn_R001552_5213_4_2(sec_r001552_4_1, sec_r001552_5_1, pub_r001552_6_1, sec_r001552_4_2, sec_r001552_5_2, pub_r001552_6_2);
  int stage_v_0_1 = ((pub_r001552_15_1 * 2) + 32) & 63;
  int stage_v_0_2 = ((pub_r001552_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((pub_r001552_3_1 * 2) + 42) & 63;
  int stage_v_1_2 = ((pub_r001552_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001552_2_1 * 3) + pub_r001552_17_1) + 35) & 127;
  int stage_v_2_2 = (((sec_r001552_2_2 * 3) + pub_r001552_17_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001552_14_1 * 2) + 15) & 63;
  int stage_v_3_2 = ((pub_r001552_14_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001552_19_1 * 3) + pub_r001552_2_1) + 40) & 127;
  int stage_v_4_2 = (((sec_r001552_19_2 * 3) + pub_r001552_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001552_14_1 * 2) + 29) & 63;
  int stage_v_5_2 = ((pub_r001552_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001552_9_1 * 2) + 12) & 63;
  int stage_v_6_2 = ((pub_r001552_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001552_15_1 * 2) + 32) & 63;
  int stage_v_7_2 = ((pub_r001552_15_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((helper_flow_0_1 * 3) + pub_r001552_12_1) + 36) & 127;
  int stage_v_8_2 = (((helper_flow_0_2 * 3) + pub_r001552_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = (((sec_r001552_0_1 * 3) + pub_r001552_9_1) + 4) & 127;
  int stage_v_9_2 = (((sec_r001552_0_2 * 3) + pub_r001552_9_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_9_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_9_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_9_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_9_2 * 2)) & 255;
  int stage_v_10_1 = ((pub_r001552_16_1 * 2) + 23) & 63;
  int stage_v_10_2 = ((pub_r001552_16_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = ((pub_r001552_17_1 * 2) + 34) & 63;
  int stage_v_11_2 = ((pub_r001552_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = (((helper_flow_0_1 * 3) + pub_r001552_13_1) + 3) & 127;
  int stage_v_12_2 = (((helper_flow_0_2 * 3) + pub_r001552_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = (((stage_v_9_1 * 3) + pub_r001552_9_1) + 17) & 127;
  int stage_v_13_2 = (((stage_v_9_2 * 3) + pub_r001552_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = ((pub_r001552_16_1 * 2) + 32) & 63;
  int stage_v_14_2 = ((pub_r001552_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = (((sec_r001552_14_1 * 3) + pub_r001552_5_1) + 3) & 127;
  int stage_v_15_2 = (((sec_r001552_14_2 * 3) + pub_r001552_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = ((pub_r001552_1_1 * 2) + 40) & 63;
  int stage_v_16_2 = ((pub_r001552_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((pub_r001552_17_1 * 2) + 23) & 63;
  int stage_v_17_2 = ((pub_r001552_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((helper_flow_0_1 * 3) + pub_r001552_0_1) + 30) & 127;
  int stage_v_18_2 = (((helper_flow_0_2 * 3) + pub_r001552_0_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001552_17_1 * 2) + 37) & 63;
  int stage_v_19_2 = ((pub_r001552_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((helper_flow_2_1 * 3) + pub_r001552_16_1) + 15) & 127;
  int stage_v_20_2 = (((helper_flow_2_2 * 3) + pub_r001552_16_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001552_9_1 * 2) + 22) & 63;
  int stage_v_21_2 = ((pub_r001552_9_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = (((sec_r001552_3_1 * 3) + pub_r001552_17_1) + 25) & 127;
  int stage_v_22_2 = (((sec_r001552_3_2 * 3) + pub_r001552_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_22_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_22_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_22_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_22_2 * 2)) & 255;
  int stage_v_23_1 = ((pub_r001552_12_1 * 2) + 9) & 63;
  int stage_v_23_2 = ((pub_r001552_12_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001552_2_1 * 2) + 5) & 63;
  int stage_v_24_2 = ((pub_r001552_2_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001552_6_1 * 2) + 8) & 63;
  int stage_v_25_2 = ((pub_r001552_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = (((sec_r001552_17_1 * 3) + pub_r001552_13_1) + 37) & 127;
  int stage_v_26_2 = (((sec_r001552_17_2 * 3) + pub_r001552_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_26_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_26_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_26_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_26_2 * 2)) & 255;
  int stage_v_27_1 = ((pub_r001552_6_1 * 2) + 19) & 63;
  int stage_v_27_2 = ((pub_r001552_6_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((sec_r001552_18_1 * 3) + pub_r001552_1_1) + 8) & 127;
  int stage_v_28_2 = (((sec_r001552_18_2 * 3) + pub_r001552_1_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((stage_v_13_1 * 3) + pub_r001552_3_1) + 24) & 127;
  int stage_v_29_2 = (((stage_v_13_2 * 3) + pub_r001552_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((stage_v_18_1 * 3) + pub_r001552_11_1) + 42) & 127;
  int stage_v_30_2 = (((stage_v_18_2 * 3) + pub_r001552_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = (((stage_v_28_1 * 3) + pub_r001552_2_1) + 45) & 127;
  int stage_v_31_2 = (((stage_v_28_2 * 3) + pub_r001552_2_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = ((pub_r001552_0_1 * 2) + 7) & 63;
  int stage_v_32_2 = ((pub_r001552_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((pub_r001552_9_1 * 2) + 17) & 63;
  int stage_v_33_2 = ((pub_r001552_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((pub_r001552_3_1 * 2) + 37) & 63;
  int stage_v_34_2 = ((pub_r001552_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001552_16_1 * 2) + 39) & 63;
  int stage_v_35_2 = ((pub_r001552_16_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001552_2_1 * 2) + 21) & 63;
  int stage_v_36_2 = ((pub_r001552_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((pub_r001552_10_1 * 2) + 23) & 63;
  int stage_v_37_2 = ((pub_r001552_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001552_0_1 * 2) + 47) & 63;
  int stage_v_38_2 = ((pub_r001552_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001552_17_1 * 2) + 39) & 63;
  int stage_v_39_2 = ((pub_r001552_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((pub_r001552_15_1 * 2) + 19) & 63;
  int stage_v_40_2 = ((pub_r001552_15_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001552_10_1 * 2) + 16) & 63;
  int stage_v_41_2 = ((pub_r001552_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001552_12_1 * 2) + 5) & 63;
  int stage_v_42_2 = ((pub_r001552_12_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001552_3_1 * 2) + 16) & 63;
  int stage_v_43_2 = ((pub_r001552_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001552_20_1 * 3) + pub_r001552_0_1) + 33) & 127;
  int stage_v_44_2 = (((sec_r001552_20_2 * 3) + pub_r001552_0_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_9_1 * 3) + pub_r001552_14_1) + 22) & 127;
  int stage_v_45_2 = (((stage_v_9_2 * 3) + pub_r001552_14_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((stage_v_12_1 * 3) + pub_r001552_10_1) + 3) & 127;
  int stage_v_46_2 = (((stage_v_12_2 * 3) + pub_r001552_10_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001552_8_1 * 2) + 17) & 63;
  int stage_v_47_2 = ((pub_r001552_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001552_4_1 * 2) + 18) & 63;
  int stage_v_48_2 = ((pub_r001552_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001552_1_1 * 3) + pub_r001552_9_1) + 27) & 127;
  int stage_v_49_2 = (((sec_r001552_1_2 * 3) + pub_r001552_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001552_13_1 * 2) + 24) & 63;
  int stage_v_50_2 = ((pub_r001552_13_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = (((stage_v_8_1 * 3) + pub_r001552_15_1) + 5) & 127;
  int stage_v_51_2 = (((stage_v_8_2 * 3) + pub_r001552_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_51_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_51_2 * 2)) & 255;
  int stage_v_52_1 = ((pub_r001552_7_1 * 2) + 12) & 63;
  int stage_v_52_2 = ((pub_r001552_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001552_16_1 * 2) + 37) & 63;
  int stage_v_53_2 = ((pub_r001552_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001552_17_1 * 2) + 39) & 63;
  int stage_v_54_2 = ((pub_r001552_17_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((pub_r001552_10_1 * 2) + 48) & 63;
  int stage_v_55_2 = ((pub_r001552_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = ((pub_r001552_16_1 * 2) + 22) & 63;
  int stage_v_56_2 = ((pub_r001552_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001552_0_1 * 2) + 23) & 63;
  int stage_v_57_2 = ((pub_r001552_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = (((stage_v_31_1 * 3) + pub_r001552_8_1) + 17) & 127;
  int stage_v_58_2 = (((stage_v_31_2 * 3) + pub_r001552_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((stage_v_49_1 * 3) + pub_r001552_1_1) + 28) & 127;
  int stage_v_59_2 = (((stage_v_49_2 * 3) + pub_r001552_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001552_12_1 * 2) + 29) & 63;
  int stage_v_60_2 = ((pub_r001552_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = (((stage_v_59_1 * 3) + pub_r001552_14_1) + 35) & 127;
  int stage_v_61_2 = (((stage_v_59_2 * 3) + pub_r001552_14_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_61_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_61_2 * 2)) & 255;
  int stage_v_62_1 = ((pub_r001552_11_1 * 2) + 18) & 63;
  int stage_v_62_2 = ((pub_r001552_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((stage_v_20_1 * 3) + pub_r001552_7_1) + 40) & 127;
  int stage_v_63_2 = (((stage_v_20_2 * 3) + pub_r001552_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001552_2_1 * 2) + 46) & 63;
  int stage_v_64_2 = ((pub_r001552_2_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((sec_r001552_13_1 * 3) + pub_r001552_4_1) + 40) & 127;
  int stage_v_65_2 = (((sec_r001552_13_2 * 3) + pub_r001552_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = ((pub_r001552_16_1 * 2) + 12) & 63;
  int stage_v_66_2 = ((pub_r001552_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001552_8_1 * 2) + 46) & 63;
  int stage_v_67_2 = ((pub_r001552_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001552_15_1 * 2) + 23) & 63;
  int stage_v_68_2 = ((pub_r001552_15_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001552_1_1 * 2) + 36) & 63;
  int stage_v_69_2 = ((pub_r001552_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((stage_v_63_1 * 3) + pub_r001552_17_1) + 17) & 127;
  int stage_v_70_2 = (((stage_v_63_2 * 3) + pub_r001552_17_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = ((pub_r001552_10_1 * 2) + 13) & 63;
  int stage_v_71_2 = ((pub_r001552_10_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = (((stage_v_63_1 * 3) + pub_r001552_16_1) + 33) & 127;
  int stage_v_72_2 = (((stage_v_63_2 * 3) + pub_r001552_16_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001552_1_1 * 2) + 24) & 63;
  int stage_v_73_2 = ((pub_r001552_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001552_7_1 * 2) + 25) & 63;
  int stage_v_74_2 = ((pub_r001552_7_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((stage_v_30_1 * 3) + pub_r001552_16_1) + 35) & 127;
  int stage_v_75_2 = (((stage_v_30_2 * 3) + pub_r001552_16_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = (((sec_r001552_2_1 * 3) + pub_r001552_15_1) + 22) & 127;
  int stage_v_76_2 = (((sec_r001552_2_2 * 3) + pub_r001552_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_76_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_76_2 * 2)) & 255;
  int stage_v_77_1 = ((pub_r001552_0_1 * 2) + 16) & 63;
  int stage_v_77_2 = ((pub_r001552_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((pub_r001552_2_1 * 2) + 40) & 63;
  int stage_v_78_2 = ((pub_r001552_2_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  int stage_v_79_1 = ((pub_r001552_6_1 * 2) + 33) & 63;
  int stage_v_79_2 = ((pub_r001552_6_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001552_10_1 * 2) + 32) & 63;
  int stage_v_80_2 = ((pub_r001552_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001552_17_1 * 2) + 14) & 63;
  int stage_v_81_2 = ((pub_r001552_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((stage_v_28_1 * 3) + pub_r001552_9_1) + 43) & 127;
  int stage_v_82_2 = (((stage_v_28_2 * 3) + pub_r001552_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001552_13_1 * 2) + 9) & 63;
  int stage_v_83_2 = ((pub_r001552_13_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((sec_r001552_1_1 * 3) + pub_r001552_1_1) + 23) & 127;
  int stage_v_84_2 = (((sec_r001552_1_2 * 3) + pub_r001552_1_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001552_16_1 * 2) + 5) & 63;
  int stage_v_85_2 = ((pub_r001552_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((sec_r001552_8_1 * 3) + pub_r001552_6_1) + 35) & 127;
  int stage_v_86_2 = (((sec_r001552_8_2 * 3) + pub_r001552_6_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001552_17_1 * 2) + 44) & 63;
  int stage_v_87_2 = ((pub_r001552_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001552_2_1 * 2) + 26) & 63;
  int stage_v_88_2 = ((pub_r001552_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001552_7_1 * 2) + 49) & 63;
  int stage_v_89_2 = ((pub_r001552_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001552_5_1 * 2) + 38) & 63;
  int stage_v_90_2 = ((pub_r001552_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((pub_r001552_8_1 * 2) + 21) & 63;
  int stage_v_91_2 = ((pub_r001552_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001552_15_1 * 2) + 21) & 63;
  int stage_v_92_2 = ((pub_r001552_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (((helper_flow_0_1 * 3) + pub_r001552_13_1) + 17) & 127;
  int stage_v_93_2 = (((helper_flow_0_2 * 3) + pub_r001552_13_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_93_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_93_2 * 2)) & 255;
  int stage_v_94_1 = ((pub_r001552_16_1 * 2) + 24) & 63;
  int stage_v_94_2 = ((pub_r001552_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001552_17_1 * 2) + 19) & 63;
  int stage_v_95_2 = ((pub_r001552_17_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = ((pub_r001552_2_1 * 2) + 26) & 63;
  int stage_v_96_2 = ((pub_r001552_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = (((sec_r001552_0_1 * 3) + pub_r001552_4_1) + 18) & 127;
  int stage_v_97_2 = (((sec_r001552_0_2 * 3) + pub_r001552_4_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((sec_r001552_4_1 * 3) + pub_r001552_8_1) + 15) & 127;
  int stage_v_98_2 = (((sec_r001552_4_2 * 3) + pub_r001552_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_75_1 * 3) + pub_r001552_15_1) + 41) & 127;
  int stage_v_99_2 = (((stage_v_75_2 * 3) + pub_r001552_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001552_4_1 * 2) + 8) & 63;
  int stage_v_100_2 = ((pub_r001552_4_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001552_15_1 * 2) + 30) & 63;
  int stage_v_101_2 = ((pub_r001552_15_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001552_8_1 * 2) + 20) & 63;
  int stage_v_102_2 = ((pub_r001552_8_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001552_9_1 * 2) + 35) & 63;
  int stage_v_103_2 = ((pub_r001552_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((stage_v_22_1 * 3) + pub_r001552_12_1) + 35) & 127;
  int stage_v_104_2 = (((stage_v_22_2 * 3) + pub_r001552_12_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001552_10_1 * 2) + 11) & 63;
  int stage_v_105_2 = ((pub_r001552_10_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001552_16_1 * 2) + 13) & 63;
  int stage_v_106_2 = ((pub_r001552_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001552_4_1 * 2) + 37) & 63;
  int stage_v_107_2 = ((pub_r001552_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001552_17_1 * 2) + 28) & 63;
  int stage_v_108_2 = ((pub_r001552_17_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001552_7_1 * 2) + 24) & 63;
  int stage_v_109_2 = ((pub_r001552_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001552_4_1 * 2) + 48) & 63;
  int stage_v_110_2 = ((pub_r001552_4_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (((stage_v_44_1 * 3) + pub_r001552_2_1) + 40) & 127;
  int stage_v_111_2 = (((stage_v_44_2 * 3) + pub_r001552_2_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_111_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_111_2 * 2)) & 255;
  int stage_v_112_1 = ((pub_r001552_4_1 * 2) + 41) & 63;
  int stage_v_112_2 = ((pub_r001552_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((pub_r001552_3_1 * 2) + 8) & 63;
  int stage_v_113_2 = ((pub_r001552_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((pub_r001552_7_1 * 2) + 40) & 63;
  int stage_v_114_2 = ((pub_r001552_7_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = (((sec_r001552_7_1 * 3) + pub_r001552_12_1) + 28) & 127;
  int stage_v_115_2 = (((sec_r001552_7_2 * 3) + pub_r001552_12_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_115_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_115_2 * 2)) & 255;
  int stage_v_116_1 = ((pub_r001552_3_1 * 2) + 36) & 63;
  int stage_v_116_2 = ((pub_r001552_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001552_12_1 * 2) + 32) & 63;
  int stage_v_117_2 = ((pub_r001552_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001552_12_1 * 2) + 37) & 63;
  int stage_v_118_2 = ((pub_r001552_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001552_9_1 * 2) + 38) & 63;
  int stage_v_119_2 = ((pub_r001552_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_18_1 * 3) + pub_r001552_15_1) + 8) & 127;
  int stage_v_120_2 = (((stage_v_18_2 * 3) + pub_r001552_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001552_8_1 * 2) + 33) & 63;
  int stage_v_121_2 = ((pub_r001552_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001552_10_1 * 2) + 21) & 63;
  int stage_v_122_2 = ((pub_r001552_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = (((stage_v_15_1 * 3) + pub_r001552_8_1) + 3) & 127;
  int stage_v_123_2 = (((stage_v_15_2 * 3) + pub_r001552_8_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_123_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_123_2 * 2)) & 255;
  int stage_v_124_1 = (((stage_v_93_1 * 3) + pub_r001552_14_1) + 28) & 127;
  int stage_v_124_2 = (((stage_v_93_2 * 3) + pub_r001552_14_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_124_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_124_2 * 2)) & 255;
  int stage_v_125_1 = ((pub_r001552_4_1 * 2) + 23) & 63;
  int stage_v_125_2 = ((pub_r001552_4_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001552_10_1 * 2) + 47) & 63;
  int stage_v_126_2 = ((pub_r001552_10_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001552_16_1 * 2) + 32) & 63;
  int stage_v_127_2 = ((pub_r001552_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_8_1 * 3) + pub_r001552_10_1) + 19) & 127;
  int stage_v_128_2 = (((stage_v_8_2 * 3) + pub_r001552_10_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = ((pub_r001552_7_1 * 2) + 49) & 63;
  int stage_v_129_2 = ((pub_r001552_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((pub_r001552_14_1 * 2) + 18) & 63;
  int stage_v_130_2 = ((pub_r001552_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001552_12_1 * 2) + 7) & 63;
  int stage_v_131_2 = ((pub_r001552_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001552_14_1 * 2) + 36) & 63;
  int stage_v_132_2 = ((pub_r001552_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((pub_r001552_12_1 * 2) + 36) & 63;
  int stage_v_133_2 = ((pub_r001552_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_133_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_133_2) & 127;
  int stage_v_134_1 = ((pub_r001552_8_1 * 2) + 38) & 63;
  int stage_v_134_2 = ((pub_r001552_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001552_14_1 * 2) + 26) & 63;
  int stage_v_135_2 = ((pub_r001552_14_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001552_17_1 * 2) + 41) & 63;
  int stage_v_136_2 = ((pub_r001552_17_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001552_13_1 * 2) + 47) & 63;
  int stage_v_137_2 = ((pub_r001552_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = (((helper_flow_1_1 * 3) + pub_r001552_17_1) + 32) & 127;
  int stage_v_138_2 = (((helper_flow_1_2 * 3) + pub_r001552_17_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_138_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_138_2 * 2)) & 255;
  int stage_v_139_1 = ((pub_r001552_9_1 * 2) + 48) & 63;
  int stage_v_139_2 = ((pub_r001552_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((pub_r001552_11_1 * 2) + 18) & 63;
  int stage_v_140_2 = ((pub_r001552_11_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_140_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_140_2) & 127;
  int stage_v_141_1 = (((stage_v_46_1 * 3) + pub_r001552_0_1) + 15) & 127;
  int stage_v_141_2 = (((stage_v_46_2 * 3) + pub_r001552_0_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_82_1 * 3) + pub_r001552_12_1) + 43) & 127;
  int stage_v_142_2 = (((stage_v_82_2 * 3) + pub_r001552_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_111_1 * 3) + pub_r001552_5_1) + 13) & 127;
  int stage_v_143_2 = (((stage_v_111_2 * 3) + pub_r001552_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = ((pub_r001552_3_1 * 2) + 27) & 63;
  int stage_v_144_2 = ((pub_r001552_3_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = (((sec_r001552_11_1 * 3) + pub_r001552_12_1) + 34) & 127;
  int stage_v_145_2 = (((sec_r001552_11_2 * 3) + pub_r001552_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = (((stage_v_124_1 * 3) + pub_r001552_10_1) + 25) & 127;
  int stage_v_146_2 = (((stage_v_124_2 * 3) + pub_r001552_10_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_146_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_146_2 * 2)) & 255;
  int stage_v_147_1 = (((stage_v_9_1 * 3) + pub_r001552_11_1) + 37) & 127;
  int stage_v_147_2 = (((stage_v_9_2 * 3) + pub_r001552_11_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((stage_v_123_1 * 3) + pub_r001552_0_1) + 27) & 127;
  int stage_v_148_2 = (((stage_v_123_2 * 3) + pub_r001552_0_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = (((stage_v_86_1 * 3) + pub_r001552_10_1) + 10) & 127;
  int stage_v_149_2 = (((stage_v_86_2 * 3) + pub_r001552_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_149_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_149_2 * 2)) & 255;
  int stage_v_150_1 = ((pub_r001552_14_1 * 2) + 30) & 63;
  int stage_v_150_2 = ((pub_r001552_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001552_9_1 * 2) + 35) & 63;
  int stage_v_151_2 = ((pub_r001552_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((helper_flow_1_1 * 3) + pub_r001552_0_1) + 25) & 127;
  int stage_v_152_2 = (((helper_flow_1_2 * 3) + pub_r001552_0_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001552_3_1 * 2) + 7) & 63;
  int stage_v_153_2 = ((pub_r001552_3_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001552_14_1 * 2) + 36) & 63;
  int stage_v_154_2 = ((pub_r001552_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001552_0_1 * 2) + 22) & 63;
  int stage_v_155_2 = ((pub_r001552_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001552_6_1 * 2) + 16) & 63;
  int stage_v_156_2 = ((pub_r001552_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = ((pub_r001552_5_1 * 2) + 23) & 63;
  int stage_v_157_2 = ((pub_r001552_5_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_157_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_157_2) & 127;
  int stage_v_158_1 = (((stage_v_75_1 * 3) + pub_r001552_17_1) + 19) & 127;
  int stage_v_158_2 = (((stage_v_75_2 * 3) + pub_r001552_17_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = ((pub_r001552_16_1 * 2) + 35) & 63;
  int stage_v_159_2 = ((pub_r001552_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = (((stage_v_49_1 * 3) + pub_r001552_17_1) + 27) & 127;
  int stage_v_160_2 = (((stage_v_49_2 * 3) + pub_r001552_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = (((stage_v_20_1 * 3) + pub_r001552_8_1) + 7) & 127;
  int stage_v_161_2 = (((stage_v_20_2 * 3) + pub_r001552_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_161_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_161_2 * 2)) & 255;
  int stage_v_162_1 = ((pub_r001552_11_1 * 2) + 31) & 63;
  int stage_v_162_2 = ((pub_r001552_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001552_14_1 * 2) + 5) & 63;
  int stage_v_163_2 = ((pub_r001552_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001552_13_1 * 2) + 32) & 63;
  int stage_v_164_2 = ((pub_r001552_13_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = (((sec_r001552_4_1 * 3) + pub_r001552_15_1) + 35) & 127;
  int stage_v_165_2 = (((sec_r001552_4_2 * 3) + pub_r001552_15_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_165_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_165_2 * 2)) & 255;
  int stage_v_166_1 = ((pub_r001552_3_1 * 2) + 43) & 63;
  int stage_v_166_2 = ((pub_r001552_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_166_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_166_2) & 127;
  int stage_v_167_1 = ((pub_r001552_14_1 * 2) + 29) & 63;
  int stage_v_167_2 = ((pub_r001552_14_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((pub_r001552_14_1 * 2) + 9) & 63;
  int stage_v_168_2 = ((pub_r001552_14_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (((stage_v_46_1 * 3) + pub_r001552_8_1) + 45) & 127;
  int stage_v_169_2 = (((stage_v_46_2 * 3) + pub_r001552_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((sec_r001552_5_1 * 3) + pub_r001552_15_1) + 43) & 127;
  int stage_v_170_2 = (((sec_r001552_5_2 * 3) + pub_r001552_15_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001552_14_1 * 2) + 14) & 63;
  int stage_v_171_2 = ((pub_r001552_14_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((pub_r001552_14_1 * 2) + 47) & 63;
  int stage_v_172_2 = ((pub_r001552_14_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_172_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_172_2) & 127;
  int stage_v_173_1 = ((pub_r001552_12_1 * 2) + 18) & 63;
  int stage_v_173_2 = ((pub_r001552_12_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001552_1_1 * 2) + 15) & 63;
  int stage_v_174_2 = ((pub_r001552_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = (((stage_v_30_1 * 3) + pub_r001552_16_1) + 25) & 127;
  int stage_v_175_2 = (((stage_v_30_2 * 3) + pub_r001552_16_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((stage_v_170_1 * 3) + pub_r001552_4_1) + 36) & 127;
  int stage_v_176_2 = (((stage_v_170_2 * 3) + pub_r001552_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_63_1 * 3) + pub_r001552_8_1) + 21) & 127;
  int stage_v_177_2 = (((stage_v_63_2 * 3) + pub_r001552_8_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = ((pub_r001552_9_1 * 2) + 13) & 63;
  int stage_v_178_2 = ((pub_r001552_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((pub_r001552_7_1 * 2) + 10) & 63;
  int stage_v_179_2 = ((pub_r001552_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = ((pub_r001552_6_1 * 2) + 16) & 63;
  int stage_v_180_2 = ((pub_r001552_6_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = (((sec_r001552_15_1 * 3) + pub_r001552_11_1) + 20) & 127;
  int stage_v_181_2 = (((sec_r001552_15_2 * 3) + pub_r001552_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = ((pub_r001552_17_1 * 2) + 7) & 63;
  int stage_v_182_2 = ((pub_r001552_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001552_4_1 * 2) + 44) & 63;
  int stage_v_183_2 = ((pub_r001552_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001552_9_1 * 2) + 48) & 63;
  int stage_v_184_2 = ((pub_r001552_9_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001552_16_1 * 2) + 26) & 63;
  int stage_v_185_2 = ((pub_r001552_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((sec_r001552_0_1 * 3) + pub_r001552_15_1) + 28) & 127;
  int stage_v_186_2 = (((sec_r001552_0_2 * 3) + pub_r001552_15_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = ((pub_r001552_9_1 * 2) + 29) & 63;
  int stage_v_187_2 = ((pub_r001552_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_187_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_187_2) & 127;
  int stage_v_188_1 = ((pub_r001552_13_1 * 2) + 25) & 63;
  int stage_v_188_2 = ((pub_r001552_13_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001552_1_1 * 2) + 30) & 63;
  int stage_v_189_2 = ((pub_r001552_1_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001552_4_1 * 2) + 12) & 63;
  int stage_v_190_2 = ((pub_r001552_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = ((pub_r001552_17_1 * 2) + 10) & 63;
  int stage_v_191_2 = ((pub_r001552_17_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = (((stage_v_161_1 * 3) + pub_r001552_7_1) + 41) & 127;
  int stage_v_192_2 = (((stage_v_161_2 * 3) + pub_r001552_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = (((sec_r001552_20_1 * 3) + pub_r001552_14_1) + 10) & 127;
  int stage_v_193_2 = (((sec_r001552_20_2 * 3) + pub_r001552_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = ((pub_r001552_13_1 * 2) + 37) & 63;
  int stage_v_194_2 = ((pub_r001552_13_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001552_14_1 * 2) + 21) & 63;
  int stage_v_195_2 = ((pub_r001552_14_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = ((pub_r001552_2_1 * 2) + 41) & 63;
  int stage_v_196_2 = ((pub_r001552_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_196_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_196_2) & 127;
  int stage_v_197_1 = ((pub_r001552_11_1 * 2) + 21) & 63;
  int stage_v_197_2 = ((pub_r001552_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_169_1 * 3) + pub_r001552_2_1) + 12) & 127;
  int stage_v_198_2 = (((stage_v_169_2 * 3) + pub_r001552_2_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001552_11_1 * 2) + 23) & 63;
  int stage_v_199_2 = ((pub_r001552_11_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001552_5_1 * 2) + 26) & 63;
  int stage_v_200_2 = ((pub_r001552_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001552_8_1 * 2) + 32) & 63;
  int stage_v_201_2 = ((pub_r001552_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_142_1 * 3) + pub_r001552_13_1) + 13) & 127;
  int stage_v_202_2 = (((stage_v_142_2 * 3) + pub_r001552_13_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = ((pub_r001552_10_1 * 2) + 25) & 63;
  int stage_v_203_2 = ((pub_r001552_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((helper_flow_3_1 * 3) + pub_r001552_7_1) + 19) & 127;
  int stage_v_204_2 = (((helper_flow_3_2 * 3) + pub_r001552_7_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_123_1 * 3) + pub_r001552_9_1) + 20) & 127;
  int stage_v_205_2 = (((stage_v_123_2 * 3) + pub_r001552_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = ((pub_r001552_3_1 * 2) + 35) & 63;
  int stage_v_206_2 = ((pub_r001552_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((pub_r001552_0_1 * 2) + 47) & 63;
  int stage_v_207_2 = ((pub_r001552_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001552_15_1 * 2) + 28) & 63;
  int stage_v_208_2 = ((pub_r001552_15_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001552_16_1 * 2) + 38) & 63;
  int stage_v_209_2 = ((pub_r001552_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001552_8_1 * 2) + 6) & 63;
  int stage_v_210_2 = ((pub_r001552_8_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001552_10_1 * 2) + 9) & 63;
  int stage_v_211_2 = ((pub_r001552_10_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001552_1_1 * 2) + 17) & 63;
  int stage_v_212_2 = ((pub_r001552_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_124_1 * 3) + pub_r001552_15_1) + 41) & 127;
  int stage_v_213_2 = (((stage_v_124_2 * 3) + pub_r001552_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((sec_r001552_5_1 * 3) + pub_r001552_6_1) + 15) & 127;
  int stage_v_214_2 = (((sec_r001552_5_2 * 3) + pub_r001552_6_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = (((stage_v_59_1 * 3) + pub_r001552_3_1) + 6) & 127;
  int stage_v_215_2 = (((stage_v_59_2 * 3) + pub_r001552_3_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_152_1 * 3) + pub_r001552_13_1) + 44) & 127;
  int stage_v_216_2 = (((stage_v_152_2 * 3) + pub_r001552_13_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = ((pub_r001552_14_1 * 2) + 31) & 63;
  int stage_v_217_2 = ((pub_r001552_14_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001552_12_1 * 2) + 20) & 63;
  int stage_v_218_2 = ((pub_r001552_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001552_2_1 * 2) + 30) & 63;
  int stage_v_219_2 = ((pub_r001552_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((stage_v_142_1 * 3) + pub_r001552_2_1) + 16) & 127;
  int stage_v_220_2 = (((stage_v_142_2 * 3) + pub_r001552_2_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((sec_r001552_20_1 * 3) + pub_r001552_17_1) + 25) & 127;
  int stage_v_221_2 = (((sec_r001552_20_2 * 3) + pub_r001552_17_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = ((pub_r001552_6_1 * 2) + 8) & 63;
  int stage_v_222_2 = ((pub_r001552_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_222_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_222_2) & 127;
  int stage_v_223_1 = ((pub_r001552_10_1 * 2) + 37) & 63;
  int stage_v_223_2 = ((pub_r001552_10_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_51_1 * 3) + pub_r001552_10_1) + 28) & 127;
  int stage_v_224_2 = (((stage_v_51_2 * 3) + pub_r001552_10_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001552_3_1 * 2) + 23) & 63;
  int stage_v_225_2 = ((pub_r001552_3_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001552_4_1 * 2) + 33) & 63;
  int stage_v_226_2 = ((pub_r001552_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((pub_r001552_1_1 * 2) + 46) & 63;
  int stage_v_227_2 = ((pub_r001552_1_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_227_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_227_2) & 127;
  int stage_v_228_1 = (((stage_v_204_1 * 3) + pub_r001552_14_1) + 6) & 127;
  int stage_v_228_2 = (((stage_v_204_2 * 3) + pub_r001552_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001552_12_1 * 2) + 12) & 63;
  int stage_v_229_2 = ((pub_r001552_12_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001552_17_1 * 2) + 17) & 63;
  int stage_v_230_2 = ((pub_r001552_17_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((sec_r001552_10_1 * 3) + pub_r001552_11_1) + 11) & 127;
  int stage_v_231_2 = (((sec_r001552_10_2 * 3) + pub_r001552_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = ((pub_r001552_6_1 * 2) + 44) & 63;
  int stage_v_232_2 = ((pub_r001552_6_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001552_14_1 * 2) + 45) & 63;
  int stage_v_233_2 = ((pub_r001552_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((pub_r001552_16_1 * 2) + 41) & 63;
  int stage_v_234_2 = ((pub_r001552_16_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001552_8_1 * 2) + 40) & 63;
  int stage_v_235_2 = ((pub_r001552_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = (((stage_v_176_1 * 3) + pub_r001552_5_1) + 15) & 127;
  int stage_v_236_2 = (((stage_v_176_2 * 3) + pub_r001552_5_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = (((stage_v_169_1 * 3) + pub_r001552_3_1) + 34) & 127;
  int stage_v_237_2 = (((stage_v_169_2 * 3) + pub_r001552_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_237_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_237_2 * 2)) & 255;
  int stage_v_238_1 = (((stage_v_104_1 * 3) + pub_r001552_17_1) + 21) & 127;
  int stage_v_238_2 = (((stage_v_104_2 * 3) + pub_r001552_17_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_238_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_238_2 * 2)) & 255;
  int stage_v_239_1 = (((stage_v_148_1 * 3) + pub_r001552_13_1) + 9) & 127;
  int stage_v_239_2 = (((stage_v_148_2 * 3) + pub_r001552_13_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_239_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_239_2 * 2)) & 255;
  int stage_v_240_1 = (((stage_v_141_1 * 3) + pub_r001552_9_1) + 17) & 127;
  int stage_v_240_2 = (((stage_v_141_2 * 3) + pub_r001552_9_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_63_1 * 3) + pub_r001552_6_1) + 10) & 127;
  int stage_v_241_2 = (((stage_v_63_2 * 3) + pub_r001552_6_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_165_1 * 3) + pub_r001552_3_1) + 34) & 127;
  int stage_v_242_2 = (((stage_v_165_2 * 3) + pub_r001552_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_231_1 * 3) + pub_r001552_8_1) + 31) & 127;
  int stage_v_243_2 = (((stage_v_231_2 * 3) + pub_r001552_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = ((pub_r001552_2_1 * 2) + 31) & 63;
  int stage_v_244_2 = ((pub_r001552_2_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001552_1_1 * 2) + 19) & 63;
  int stage_v_245_2 = ((pub_r001552_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001552_17_1 * 2) + 23) & 63;
  int stage_v_246_2 = ((pub_r001552_17_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = (((stage_v_193_1 * 3) + pub_r001552_14_1) + 4) & 127;
  int stage_v_247_2 = (((stage_v_193_2 * 3) + pub_r001552_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_247_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_247_2 * 2)) & 255;
  int stage_v_248_1 = ((pub_r001552_16_1 * 2) + 22) & 63;
  int stage_v_248_2 = ((pub_r001552_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = (((sec_r001552_18_1 * 3) + pub_r001552_5_1) + 17) & 127;
  int stage_v_249_2 = (((sec_r001552_18_2 * 3) + pub_r001552_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001552_17_1 * 2) + 47) & 63;
  int stage_v_250_2 = ((pub_r001552_17_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((pub_r001552_5_1 * 2) + 29) & 63;
  int stage_v_251_2 = ((pub_r001552_5_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001552_3_1 * 2) + 42) & 63;
  int stage_v_252_2 = ((pub_r001552_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001552_9_1 * 2) + 5) & 63;
  int stage_v_253_2 = ((pub_r001552_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = (((stage_v_249_1 * 3) + pub_r001552_17_1) + 36) & 127;
  int stage_v_254_2 = (((stage_v_249_2 * 3) + pub_r001552_17_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001552_3_1 * 2) + 37) & 63;
  int stage_v_255_2 = ((pub_r001552_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001552_11_1 * 2) + 29) & 63;
  int stage_v_256_2 = ((pub_r001552_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001552_16_1 * 2) + 29) & 63;
  int stage_v_257_2 = ((pub_r001552_16_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001552_1_1 * 2) + 25) & 63;
  int stage_v_258_2 = ((pub_r001552_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001552_13_1 * 2) + 19) & 63;
  int stage_v_259_2 = ((pub_r001552_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001552_7_1 * 2) + 39) & 63;
  int stage_v_260_2 = ((pub_r001552_7_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001552_14_1 * 2) + 46) & 63;
  int stage_v_261_2 = ((pub_r001552_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001552_1_1 * 2) + 25) & 63;
  int stage_v_262_2 = ((pub_r001552_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_124_1 * 3) + pub_r001552_4_1) + 28) & 127;
  int stage_v_263_2 = (((stage_v_124_2 * 3) + pub_r001552_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001552_10_1 * 2) + 30) & 63;
  int stage_v_264_2 = ((pub_r001552_10_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = ((pub_r001552_17_1 * 2) + 34) & 63;
  int stage_v_265_2 = ((pub_r001552_17_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_265_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_265_2) & 127;
  int stage_v_266_1 = (((stage_v_177_1 * 3) + pub_r001552_10_1) + 8) & 127;
  int stage_v_266_2 = (((stage_v_177_2 * 3) + pub_r001552_10_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = ((pub_r001552_11_1 * 2) + 17) & 63;
  int stage_v_267_2 = ((pub_r001552_11_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((sec_r001552_18_1 * 3) + pub_r001552_17_1) + 4) & 127;
  int stage_v_268_2 = (((sec_r001552_18_2 * 3) + pub_r001552_17_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = ((pub_r001552_3_1 * 2) + 40) & 63;
  int stage_v_269_2 = ((pub_r001552_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_269_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_269_2) & 127;
  int stage_v_270_1 = ((pub_r001552_12_1 * 2) + 24) & 63;
  int stage_v_270_2 = ((pub_r001552_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001552_7_1 * 2) + 50) & 63;
  int stage_v_271_2 = ((pub_r001552_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = (((stage_v_192_1 * 3) + pub_r001552_11_1) + 16) & 127;
  int stage_v_272_2 = (((stage_v_192_2 * 3) + pub_r001552_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_272_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_272_2 * 2)) & 255;
  int stage_v_273_1 = (((stage_v_49_1 * 3) + pub_r001552_8_1) + 41) & 127;
  int stage_v_273_2 = (((stage_v_49_2 * 3) + pub_r001552_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001552_12_1 * 2) + 47) & 63;
  int stage_v_274_2 = ((pub_r001552_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001552_11_1 * 2) + 48) & 63;
  int stage_v_275_2 = ((pub_r001552_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001552_15_1 * 2) + 7) & 63;
  int stage_v_276_2 = ((pub_r001552_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((helper_flow_4_1 * 3) + pub_r001552_0_1) + 43) & 127;
  int stage_v_277_2 = (((helper_flow_4_2 * 3) + pub_r001552_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = ((pub_r001552_16_1 * 2) + 36) & 63;
  int stage_v_278_2 = ((pub_r001552_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_278_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_278_2) & 127;
  int stage_v_279_1 = (((sec_r001552_19_1 * 3) + pub_r001552_2_1) + 42) & 127;
  int stage_v_279_2 = (((sec_r001552_19_2 * 3) + pub_r001552_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_51_1 * 3) + pub_r001552_13_1) + 37) & 127;
  int stage_v_280_2 = (((stage_v_51_2 * 3) + pub_r001552_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_49_1 * 3) + pub_r001552_7_1) + 44) & 127;
  int stage_v_281_2 = (((stage_v_49_2 * 3) + pub_r001552_7_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001552_14_1 * 2) + 45) & 63;
  int stage_v_282_2 = ((pub_r001552_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = ((pub_r001552_4_1 * 2) + 34) & 63;
  int stage_v_283_2 = ((pub_r001552_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_283_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_283_2) & 127;
  int stage_v_284_1 = (((sec_r001552_20_1 * 3) + pub_r001552_3_1) + 41) & 127;
  int stage_v_284_2 = (((sec_r001552_20_2 * 3) + pub_r001552_3_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001552_11_1 * 2) + 9) & 63;
  int stage_v_285_2 = ((pub_r001552_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001552_13_1 * 2) + 12) & 63;
  int stage_v_286_2 = ((pub_r001552_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_124_1 * 3) + pub_r001552_15_1) + 24) & 127;
  int stage_v_287_2 = (((stage_v_124_2 * 3) + pub_r001552_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = (((sec_r001552_13_1 * 3) + pub_r001552_17_1) + 14) & 127;
  int stage_v_288_2 = (((sec_r001552_13_2 * 3) + pub_r001552_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_288_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_288_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_288_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_288_2 * 2)) & 255;
  int stage_v_289_1 = (((stage_v_216_1 * 3) + pub_r001552_4_1) + 20) & 127;
  int stage_v_289_2 = (((stage_v_216_2 * 3) + pub_r001552_4_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = (((stage_v_272_1 * 3) + pub_r001552_16_1) + 34) & 127;
  int stage_v_290_2 = (((stage_v_272_2 * 3) + pub_r001552_16_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_290_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_290_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_290_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_290_2 * 2)) & 255;
  int stage_v_291_1 = ((pub_r001552_0_1 * 2) + 7) & 63;
  int stage_v_291_2 = ((pub_r001552_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = (((stage_v_220_1 * 3) + pub_r001552_12_1) + 27) & 127;
  int stage_v_292_2 = (((stage_v_220_2 * 3) + pub_r001552_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = ((pub_r001552_15_1 * 2) + 38) & 63;
  int stage_v_293_2 = ((pub_r001552_15_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001552_11_1 * 2) + 25) & 63;
  int stage_v_294_2 = ((pub_r001552_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = ((pub_r001552_1_1 * 2) + 44) & 63;
  int stage_v_295_2 = ((pub_r001552_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_295_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_295_2) & 127;
  int stage_v_296_1 = (((stage_v_181_1 * 3) + pub_r001552_17_1) + 24) & 127;
  int stage_v_296_2 = (((stage_v_181_2 * 3) + pub_r001552_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001552_10_1 * 2) + 17) & 63;
  int stage_v_297_2 = ((pub_r001552_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001552_4_1 * 2) + 44) & 63;
  int stage_v_298_2 = ((pub_r001552_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001552_9_1 * 2) + 5) & 63;
  int stage_v_299_2 = ((pub_r001552_9_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001552_5_1 * 2) + 50) & 63;
  int stage_v_300_2 = ((pub_r001552_5_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001552_4_1 * 2) + 10) & 63;
  int stage_v_301_2 = ((pub_r001552_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_20_1 * 3) + pub_r001552_4_1) + 28) & 127;
  int stage_v_302_2 = (((stage_v_20_2 * 3) + pub_r001552_4_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = ((pub_r001552_0_1 * 2) + 47) & 63;
  int stage_v_303_2 = ((pub_r001552_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_303_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_303_2) & 127;
  int stage_v_304_1 = ((pub_r001552_4_1 * 2) + 50) & 63;
  int stage_v_304_2 = ((pub_r001552_4_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = ((pub_r001552_6_1 * 2) + 48) & 63;
  int stage_v_305_2 = ((pub_r001552_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001552_12_1 * 2) + 39) & 63;
  int stage_v_306_2 = ((pub_r001552_12_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001552_11_1 * 2) + 43) & 63;
  int stage_v_307_2 = ((pub_r001552_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001552_2_1 * 2) + 32) & 63;
  int stage_v_308_2 = ((pub_r001552_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = ((pub_r001552_14_1 * 2) + 34) & 63;
  int stage_v_309_2 = ((pub_r001552_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001552_14_1 * 2) + 44) & 63;
  int stage_v_310_2 = ((pub_r001552_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001552_9_1 * 2) + 49) & 63;
  int stage_v_311_2 = ((pub_r001552_9_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = ((pub_r001552_3_1 * 2) + 31) & 63;
  int stage_v_312_2 = ((pub_r001552_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_312_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_312_2) & 127;
  int stage_v_313_1 = (((sec_r001552_18_1 * 3) + pub_r001552_8_1) + 16) & 127;
  int stage_v_313_2 = (((sec_r001552_18_2 * 3) + pub_r001552_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_313_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_313_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_313_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_313_2 * 2)) & 255;
  int stage_v_314_1 = ((pub_r001552_11_1 * 2) + 6) & 63;
  int stage_v_314_2 = ((pub_r001552_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_314_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_314_2) & 127;
  int stage_v_315_1 = ((pub_r001552_13_1 * 2) + 22) & 63;
  int stage_v_315_2 = ((pub_r001552_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_315_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_315_2) & 127;
  int stage_v_316_1 = (((stage_v_148_1 * 3) + pub_r001552_1_1) + 27) & 127;
  int stage_v_316_2 = (((stage_v_148_2 * 3) + pub_r001552_1_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001552_13_1 * 2) + 12) & 63;
  int stage_v_317_2 = ((pub_r001552_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = ((pub_r001552_1_1 * 2) + 43) & 63;
  int stage_v_318_2 = ((pub_r001552_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_318_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_318_2) & 127;
  int stage_v_319_1 = (((stage_v_72_1 * 3) + pub_r001552_0_1) + 18) & 127;
  int stage_v_319_2 = (((stage_v_72_2 * 3) + pub_r001552_0_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001552_15_1 * 2) + 8) & 63;
  int stage_v_320_2 = ((pub_r001552_15_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001552_3_1 * 2) + 29) & 63;
  int stage_v_321_2 = ((pub_r001552_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001552_17_1 * 2) + 14) & 63;
  int stage_v_322_2 = ((pub_r001552_17_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001552_3_1 * 2) + 8) & 63;
  int stage_v_323_2 = ((pub_r001552_3_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001552_4_1 * 2) + 34) & 63;
  int stage_v_324_2 = ((pub_r001552_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001552_16_1 * 2) + 34) & 63;
  int stage_v_325_2 = ((pub_r001552_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001552_11_1 * 2) + 16) & 63;
  int stage_v_326_2 = ((pub_r001552_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001552_11_1 * 2) + 44) & 63;
  int stage_v_327_2 = ((pub_r001552_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001552_12_1 * 2) + 47) & 63;
  int stage_v_328_2 = ((pub_r001552_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001552_11_1 * 2) + 46) & 63;
  int stage_v_329_2 = ((pub_r001552_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001552_0_1 * 2) + 15) & 63;
  int stage_v_330_2 = ((pub_r001552_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001552_6_1 * 2) + 37) & 63;
  int stage_v_331_2 = ((pub_r001552_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = ((pub_r001552_4_1 * 2) + 31) & 63;
  int stage_v_332_2 = ((pub_r001552_4_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001552_10_1 * 2) + 29) & 63;
  int stage_v_333_2 = ((pub_r001552_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = ((pub_r001552_12_1 * 2) + 37) & 63;
  int stage_v_334_2 = ((pub_r001552_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_334_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_334_2) & 127;
  int stage_v_335_1 = ((pub_r001552_16_1 * 2) + 5) & 63;
  int stage_v_335_2 = ((pub_r001552_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_335_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_335_2) & 127;
  int stage_v_336_1 = ((pub_r001552_6_1 * 2) + 28) & 63;
  int stage_v_336_2 = ((pub_r001552_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = (((stage_v_242_1 * 3) + pub_r001552_15_1) + 14) & 127;
  int stage_v_337_2 = (((stage_v_242_2 * 3) + pub_r001552_15_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_337_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_337_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_337_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_337_2 * 2)) & 255;
  int stage_v_338_1 = ((pub_r001552_15_1 * 2) + 33) & 63;
  int stage_v_338_2 = ((pub_r001552_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = ((pub_r001552_9_1 * 2) + 9) & 63;
  int stage_v_339_2 = ((pub_r001552_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = ((pub_r001552_0_1 * 2) + 15) & 63;
  int stage_v_340_2 = ((pub_r001552_0_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_340_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_340_2) & 127;
  int stage_v_341_1 = ((pub_r001552_11_1 * 2) + 44) & 63;
  int stage_v_341_2 = ((pub_r001552_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_341_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_341_2) & 127;
  int stage_v_342_1 = ((pub_r001552_9_1 * 2) + 42) & 63;
  int stage_v_342_2 = ((pub_r001552_9_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = ((pub_r001552_5_1 * 2) + 43) & 63;
  int stage_v_343_2 = ((pub_r001552_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_343_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_343_2) & 127;
  int stage_v_344_1 = ((pub_r001552_5_1 * 2) + 6) & 63;
  int stage_v_344_2 = ((pub_r001552_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_344_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_344_2) & 127;
  int stage_v_345_1 = (((stage_v_138_1 * 3) + pub_r001552_0_1) + 17) & 127;
  int stage_v_345_2 = (((stage_v_138_2 * 3) + pub_r001552_0_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_345_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_345_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_345_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_345_2 * 2)) & 255;
  int stage_v_346_1 = (((sec_r001552_20_1 * 3) + pub_r001552_1_1) + 6) & 127;
  int stage_v_346_2 = (((sec_r001552_20_2 * 3) + pub_r001552_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = (((sec_r001552_21_1 * 3) + pub_r001552_6_1) + 43) & 127;
  int stage_v_347_2 = (((sec_r001552_21_2 * 3) + pub_r001552_6_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = (((stage_v_147_1 * 3) + pub_r001552_9_1) + 6) & 127;
  int stage_v_348_2 = (((stage_v_147_2 * 3) + pub_r001552_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = ((pub_r001552_5_1 * 2) + 25) & 63;
  int stage_v_349_2 = ((pub_r001552_5_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_349_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_349_2) & 127;
  int stage_v_350_1 = (((stage_v_289_1 * 3) + pub_r001552_17_1) + 12) & 127;
  int stage_v_350_2 = (((stage_v_289_2 * 3) + pub_r001552_17_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_9_1 * 3) + pub_r001552_1_1) + 10) & 127;
  int stage_v_351_2 = (((stage_v_9_2 * 3) + pub_r001552_1_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001552_17_1 * 2) + 50) & 63;
  int stage_v_352_2 = ((pub_r001552_17_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = ((pub_r001552_1_1 * 2) + 20) & 63;
  int stage_v_353_2 = ((pub_r001552_1_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_353_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_353_2) & 127;
  int stage_v_354_1 = ((pub_r001552_15_1 * 2) + 27) & 63;
  int stage_v_354_2 = ((pub_r001552_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = (((stage_v_51_1 * 3) + pub_r001552_15_1) + 41) & 127;
  int stage_v_355_2 = (((stage_v_51_2 * 3) + pub_r001552_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001552_17_1 * 2) + 35) & 63;
  int stage_v_356_2 = ((pub_r001552_17_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = ((pub_r001552_12_1 * 2) + 21) & 63;
  int stage_v_357_2 = ((pub_r001552_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = ((pub_r001552_11_1 * 2) + 9) & 63;
  int stage_v_358_2 = ((pub_r001552_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001552_2_1 * 2) + 20) & 63;
  int stage_v_359_2 = ((pub_r001552_2_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_8_1 * 3) + pub_r001552_9_1) + 27) & 127;
  int stage_v_360_2 = (((stage_v_8_2 * 3) + pub_r001552_9_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_288_1 * 3) + pub_r001552_0_1) + 3) & 127;
  int stage_v_361_2 = (((stage_v_288_2 * 3) + pub_r001552_0_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_202_1 * 3) + pub_r001552_17_1) + 41) & 127;
  int stage_v_362_2 = (((stage_v_202_2 * 3) + pub_r001552_17_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001552_14_1 * 2) + 48) & 63;
  int stage_v_363_2 = ((pub_r001552_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = ((pub_r001552_3_1 * 2) + 42) & 63;
  int stage_v_364_2 = ((pub_r001552_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_364_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_364_2) & 127;
  int stage_v_365_1 = (((stage_v_202_1 * 3) + pub_r001552_12_1) + 27) & 127;
  int stage_v_365_2 = (((stage_v_202_2 * 3) + pub_r001552_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001552_12_1 * 2) + 25) & 63;
  int stage_v_366_2 = ((pub_r001552_12_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_224_1 * 3) + pub_r001552_1_1) + 42) & 127;
  int stage_v_367_2 = (((stage_v_224_2 * 3) + pub_r001552_1_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001552_17_1 * 2) + 16) & 63;
  int stage_v_368_2 = ((pub_r001552_17_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = (((stage_v_169_1 * 3) + pub_r001552_13_1) + 33) & 127;
  int stage_v_369_2 = (((stage_v_169_2 * 3) + pub_r001552_13_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_369_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_369_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_369_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_369_2 * 2)) & 255;
  int stage_v_370_1 = ((pub_r001552_17_1 * 2) + 44) & 63;
  int stage_v_370_2 = ((pub_r001552_17_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = (((sec_r001552_20_1 * 3) + pub_r001552_4_1) + 4) & 127;
  int stage_v_371_2 = (((sec_r001552_20_2 * 3) + pub_r001552_4_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_371_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_371_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_371_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_371_2 * 2)) & 255;
  int stage_v_372_1 = ((pub_r001552_3_1 * 2) + 35) & 63;
  int stage_v_372_2 = ((pub_r001552_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((stage_v_13_1 * 3) + pub_r001552_10_1) + 17) & 127;
  int stage_v_373_2 = (((stage_v_13_2 * 3) + pub_r001552_10_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001552_1_1 * 2) + 34) & 63;
  int stage_v_374_2 = ((pub_r001552_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001552_3_1 * 2) + 17) & 63;
  int stage_v_375_2 = ((pub_r001552_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001552_10_1 * 2) + 34) & 63;
  int stage_v_376_2 = ((pub_r001552_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001552_4_1 * 2) + 47) & 63;
  int stage_v_377_2 = ((pub_r001552_4_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = (((stage_v_75_1 * 3) + pub_r001552_12_1) + 36) & 127;
  int stage_v_378_2 = (((stage_v_75_2 * 3) + pub_r001552_12_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_378_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_378_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_378_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_378_2 * 2)) & 255;
  int stage_v_379_1 = ((pub_r001552_11_1 * 2) + 13) & 63;
  int stage_v_379_2 = ((pub_r001552_11_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001552_10_1 * 2) + 6) & 63;
  int stage_v_380_2 = ((pub_r001552_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = (((stage_v_20_1 * 3) + pub_r001552_10_1) + 21) & 127;
  int stage_v_381_2 = (((stage_v_20_2 * 3) + pub_r001552_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_381_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_381_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_381_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_381_2 * 2)) & 255;
  int stage_v_382_1 = ((pub_r001552_6_1 * 2) + 34) & 63;
  int stage_v_382_2 = ((pub_r001552_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001552_17_1 * 2) + 46) & 63;
  int stage_v_383_2 = ((pub_r001552_17_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = ((pub_r001552_6_1 * 2) + 35) & 63;
  int stage_v_384_2 = ((pub_r001552_6_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_384_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_384_2) & 127;
  int stage_v_385_1 = ((pub_r001552_12_1 * 2) + 16) & 63;
  int stage_v_385_2 = ((pub_r001552_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001552_0_1 * 2) + 44) & 63;
  int stage_v_386_2 = ((pub_r001552_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001552_3_1 * 2) + 17) & 63;
  int stage_v_387_2 = ((pub_r001552_3_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001552_8_1 * 2) + 25) & 63;
  int stage_v_388_2 = ((pub_r001552_8_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001552_11_1 * 2) + 42) & 63;
  int stage_v_389_2 = ((pub_r001552_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001552_10_1 * 2) + 39) & 63;
  int stage_v_390_2 = ((pub_r001552_10_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = ((pub_r001552_16_1 * 2) + 21) & 63;
  int stage_v_391_2 = ((pub_r001552_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_391_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_391_2) & 127;
  int stage_v_392_1 = ((pub_r001552_16_1 * 2) + 7) & 63;
  int stage_v_392_2 = ((pub_r001552_16_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_392_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_392_2) & 127;
  int stage_v_393_1 = (((stage_v_281_1 * 3) + pub_r001552_1_1) + 6) & 127;
  int stage_v_393_2 = (((stage_v_281_2 * 3) + pub_r001552_1_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_393_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_393_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_393_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_393_2 * 2)) & 255;
  int stage_v_394_1 = ((pub_r001552_10_1 * 2) + 25) & 63;
  int stage_v_394_2 = ((pub_r001552_10_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = ((pub_r001552_16_1 * 2) + 20) & 63;
  int stage_v_395_2 = ((pub_r001552_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_395_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_395_2) & 127;
  int stage_v_396_1 = (((stage_v_254_1 * 3) + pub_r001552_3_1) + 28) & 127;
  int stage_v_396_2 = (((stage_v_254_2 * 3) + pub_r001552_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = (((stage_v_158_1 * 3) + pub_r001552_8_1) + 33) & 127;
  int stage_v_397_2 = (((stage_v_158_2 * 3) + pub_r001552_8_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_397_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_397_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_397_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_397_2 * 2)) & 255;
  int stage_v_398_1 = (((stage_v_175_1 * 3) + pub_r001552_6_1) + 4) & 127;
  int stage_v_398_2 = (((stage_v_175_2 * 3) + pub_r001552_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = (((stage_v_70_1 * 3) + pub_r001552_1_1) + 35) & 127;
  int stage_v_399_2 = (((stage_v_70_2 * 3) + pub_r001552_1_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_399_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_399_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_399_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_399_2 * 2)) & 255;
  int stage_v_400_1 = ((pub_r001552_1_1 * 2) + 39) & 63;
  int stage_v_400_2 = ((pub_r001552_1_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = (((stage_v_367_1 * 3) + pub_r001552_3_1) + 42) & 127;
  int stage_v_401_2 = (((stage_v_367_2 * 3) + pub_r001552_3_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_401_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_401_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_401_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_401_2 * 2)) & 255;
  int stage_v_402_1 = ((pub_r001552_4_1 * 2) + 10) & 63;
  int stage_v_402_2 = ((pub_r001552_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001552_16_1 * 2) + 27) & 63;
  int stage_v_403_2 = ((pub_r001552_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = (((stage_v_176_1 * 3) + pub_r001552_17_1) + 43) & 127;
  int stage_v_404_2 = (((stage_v_176_2 * 3) + pub_r001552_17_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_404_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_404_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_404_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_404_2 * 2)) & 255;
  int stage_v_405_1 = ((pub_r001552_10_1 * 2) + 35) & 63;
  int stage_v_405_2 = ((pub_r001552_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = (((stage_v_145_1 * 3) + pub_r001552_8_1) + 4) & 127;
  int stage_v_406_2 = (((stage_v_145_2 * 3) + pub_r001552_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_406_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_406_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_406_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_406_2 * 2)) & 255;
  int stage_v_407_1 = ((pub_r001552_16_1 * 2) + 19) & 63;
  int stage_v_407_2 = ((pub_r001552_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = (((stage_v_205_1 * 3) + pub_r001552_17_1) + 29) & 127;
  int stage_v_408_2 = (((stage_v_205_2 * 3) + pub_r001552_17_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_408_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_408_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_408_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_408_2 * 2)) & 255;
  int stage_v_409_1 = ((pub_r001552_0_1 * 2) + 24) & 63;
  int stage_v_409_2 = ((pub_r001552_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001552_0_1 * 2) + 36) & 63;
  int stage_v_410_2 = ((pub_r001552_0_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((stage_v_220_1 * 3) + pub_r001552_16_1) + 38) & 127;
  int stage_v_411_2 = (((stage_v_220_2 * 3) + pub_r001552_16_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = (((sec_r001552_19_1 * 3) + pub_r001552_3_1) + 9) & 127;
  int stage_v_412_2 = (((sec_r001552_19_2 * 3) + pub_r001552_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_412_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_412_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_412_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_412_2 * 2)) & 255;
  int stage_v_413_1 = ((pub_r001552_6_1 * 2) + 36) & 63;
  int stage_v_413_2 = ((pub_r001552_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_413_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_413_2) & 127;
  int stage_v_414_1 = (((helper_flow_2_1 * 3) + pub_r001552_7_1) + 3) & 127;
  int stage_v_414_2 = (((helper_flow_2_2 * 3) + pub_r001552_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_414_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_414_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_414_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_414_2 * 2)) & 255;
  int stage_v_415_1 = ((pub_r001552_9_1 * 2) + 9) & 63;
  int stage_v_415_2 = ((pub_r001552_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_415_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_415_2) & 127;
  int stage_v_416_1 = (((stage_v_406_1 * 3) + pub_r001552_4_1) + 13) & 127;
  int stage_v_416_2 = (((stage_v_406_2 * 3) + pub_r001552_4_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_416_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_416_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_416_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_416_2 * 2)) & 255;
  int stage_v_417_1 = ((pub_r001552_15_1 * 2) + 22) & 63;
  int stage_v_417_2 = ((pub_r001552_15_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001552_9_1 * 2) + 45) & 63;
  int stage_v_418_2 = ((pub_r001552_9_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = ((pub_r001552_0_1 * 2) + 12) & 63;
  int stage_v_419_2 = ((pub_r001552_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_419_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_419_2) & 127;
  int stage_v_420_1 = (((stage_v_145_1 * 3) + pub_r001552_6_1) + 4) & 127;
  int stage_v_420_2 = (((stage_v_145_2 * 3) + pub_r001552_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_420_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_420_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_420_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_420_2 * 2)) & 255;
  int stage_v_421_1 = ((pub_r001552_2_1 * 2) + 17) & 63;
  int stage_v_421_2 = ((pub_r001552_2_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_421_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_421_2) & 127;
  int stage_v_422_1 = ((pub_r001552_2_1 * 2) + 23) & 63;
  int stage_v_422_2 = ((pub_r001552_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_8_1 * 3) + pub_r001552_10_1) + 21) & 127;
  int stage_v_423_2 = (((stage_v_8_2 * 3) + pub_r001552_10_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001552_11_1 * 2) + 45) & 63;
  int stage_v_424_2 = ((pub_r001552_11_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = (((stage_v_337_1 * 3) + pub_r001552_3_1) + 3) & 127;
  int stage_v_425_2 = (((stage_v_337_2 * 3) + pub_r001552_3_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_425_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_425_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_425_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_425_2 * 2)) & 255;
  int stage_v_426_1 = ((pub_r001552_6_1 * 2) + 15) & 63;
  int stage_v_426_2 = ((pub_r001552_6_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_426_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_426_2) & 127;
  int stage_v_427_1 = ((pub_r001552_15_1 * 2) + 21) & 63;
  int stage_v_427_2 = ((pub_r001552_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_427_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_427_2) & 127;
  int stage_v_428_1 = ((pub_r001552_7_1 * 2) + 9) & 63;
  int stage_v_428_2 = ((pub_r001552_7_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_428_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_428_2) & 127;
  int stage_v_429_1 = ((pub_r001552_1_1 * 2) + 17) & 63;
  int stage_v_429_2 = ((pub_r001552_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_429_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_429_2) & 127;
  int stage_v_430_1 = (((stage_v_279_1 * 3) + pub_r001552_3_1) + 9) & 127;
  int stage_v_430_2 = (((stage_v_279_2 * 3) + pub_r001552_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001552_17_1 * 2) + 15) & 63;
  int stage_v_431_2 = ((pub_r001552_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_273_1 * 3) + pub_r001552_12_1) + 13) & 127;
  int stage_v_432_2 = (((stage_v_273_2 * 3) + pub_r001552_12_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001552_11_1 * 2) + 42) & 63;
  int stage_v_433_2 = ((pub_r001552_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((stage_v_99_1 * 3) + pub_r001552_10_1) + 31) & 127;
  int stage_v_434_2 = (((stage_v_99_2 * 3) + pub_r001552_10_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = (((stage_v_176_1 * 3) + pub_r001552_11_1) + 29) & 127;
  int stage_v_435_2 = (((stage_v_176_2 * 3) + pub_r001552_11_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001552_7_1 * 2) + 7) & 63;
  int stage_v_436_2 = ((pub_r001552_7_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = ((pub_r001552_9_1 * 2) + 44) & 63;
  int stage_v_437_2 = ((pub_r001552_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_437_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_437_2) & 127;
  int stage_v_438_1 = ((pub_r001552_3_1 * 2) + 5) & 63;
  int stage_v_438_2 = ((pub_r001552_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_438_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_438_2) & 127;
  int stage_v_439_1 = (((sec_r001552_14_1 * 3) + pub_r001552_17_1) + 26) & 127;
  int stage_v_439_2 = (((sec_r001552_14_2 * 3) + pub_r001552_17_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_439_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_439_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_439_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_439_2 * 2)) & 255;
  int stage_v_440_1 = (((stage_v_22_1 * 3) + pub_r001552_9_1) + 19) & 127;
  int stage_v_440_2 = (((stage_v_22_2 * 3) + pub_r001552_9_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_440_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_440_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_440_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_440_2 * 2)) & 255;
  int stage_v_441_1 = (((stage_v_345_1 * 3) + pub_r001552_8_1) + 31) & 127;
  int stage_v_441_2 = (((stage_v_345_2 * 3) + pub_r001552_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = (((stage_v_404_1 * 3) + pub_r001552_11_1) + 43) & 127;
  int stage_v_442_2 = (((stage_v_404_2 * 3) + pub_r001552_11_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_442_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_442_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_442_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_442_2 * 2)) & 255;
  int stage_v_443_1 = (((stage_v_289_1 * 3) + pub_r001552_5_1) + 3) & 127;
  int stage_v_443_2 = (((stage_v_289_2 * 3) + pub_r001552_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_443_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_443_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_443_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_443_2 * 2)) & 255;
  int stage_v_444_1 = ((pub_r001552_13_1 * 2) + 20) & 63;
  int stage_v_444_2 = ((pub_r001552_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001552_11_1 * 2) + 44) & 63;
  int stage_v_445_2 = ((pub_r001552_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  int stage_v_446_1 = ((pub_r001552_7_1 * 2) + 28) & 63;
  int stage_v_446_2 = ((pub_r001552_7_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_446_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_446_2) & 127;
  int stage_v_447_1 = (((stage_v_70_1 * 3) + pub_r001552_3_1) + 35) & 127;
  int stage_v_447_2 = (((stage_v_70_2 * 3) + pub_r001552_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_447_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_447_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_447_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_447_2 * 2)) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001552_12_1 != sec_r001552_12_2);
  __CPROVER_assume(sec_r001552_18_1 != sec_r001552_18_2);
  __CPROVER_assume(sec_r001552_13_1 != sec_r001552_13_2);
  __CPROVER_assume(pub_r001552_17_1 == pub_r001552_17_2);
  __CPROVER_assume(sec_r001552_1_1 != sec_r001552_1_2);
  __CPROVER_assume(sec_r001552_20_1 != sec_r001552_20_2);
  __CPROVER_assume(sec_r001552_21_1 != sec_r001552_21_2);
  __CPROVER_assume(pub_r001552_9_1 == pub_r001552_9_2);
  __CPROVER_assume(pub_r001552_6_1 == pub_r001552_6_2);
  __CPROVER_assume(sec_r001552_16_1 != sec_r001552_16_2);
  __CPROVER_assume(pub_r001552_11_1 == pub_r001552_11_2);
  __CPROVER_assume(pub_r001552_16_1 == pub_r001552_16_2);
  __CPROVER_assume(sec_r001552_17_1 != sec_r001552_17_2);
  __CPROVER_assume(pub_r001552_12_1 == pub_r001552_12_2);
  __CPROVER_assume(pub_r001552_13_1 == pub_r001552_13_2);
  __CPROVER_assume(pub_r001552_4_1 == pub_r001552_4_2);
  __CPROVER_assume(sec_r001552_3_1 != sec_r001552_3_2);
  __CPROVER_assume(sec_r001552_10_1 != sec_r001552_10_2);
  __CPROVER_assume(sec_r001552_2_1 != sec_r001552_2_2);
  __CPROVER_assume(pub_r001552_10_1 == pub_r001552_10_2);
  __CPROVER_assume(pub_r001552_8_1 == pub_r001552_8_2);
  __CPROVER_assume(sec_r001552_6_1 != sec_r001552_6_2);
  __CPROVER_assume(sec_r001552_9_1 != sec_r001552_9_2);
  __CPROVER_assume(pub_r001552_14_1 == pub_r001552_14_2);
  __CPROVER_assume(sec_r001552_5_1 != sec_r001552_5_2);
  __CPROVER_assume(sec_r001552_19_1 != sec_r001552_19_2);
  __CPROVER_assume(pub_r001552_15_1 == pub_r001552_15_2);
  __CPROVER_assume(sec_r001552_8_1 != sec_r001552_8_2);
  __CPROVER_assume(sec_r001552_14_1 != sec_r001552_14_2);
  __CPROVER_assume(pub_r001552_5_1 == pub_r001552_5_2);
  __CPROVER_assume(sec_r001552_0_1 != sec_r001552_0_2);
  __CPROVER_assume(pub_r001552_0_1 == pub_r001552_0_2);
  __CPROVER_assume(pub_r001552_3_1 == pub_r001552_3_2);
  __CPROVER_assume(sec_r001552_7_1 != sec_r001552_7_2);
  __CPROVER_assume(sec_r001552_15_1 != sec_r001552_15_2);
  __CPROVER_assume(pub_r001552_2_1 == pub_r001552_2_2);
  __CPROVER_assume(pub_r001552_7_1 == pub_r001552_7_2);
  __CPROVER_assume(sec_r001552_4_1 != sec_r001552_4_2);
  __CPROVER_assume(pub_r001552_1_1 == pub_r001552_1_2);
  __CPROVER_assume(sec_r001552_11_1 != sec_r001552_11_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
  assert(st_var_1_1.tail == st_var_1_2.tail);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.watermark == st_var_1_2.watermark);
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
}


