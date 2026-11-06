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
struct Vector3D_R000229_2913_0
{
  unsigned char norm_sq;
  short coord_y;
  unsigned char coord_z;
  int coord_x;
  short heading;
  int pitch;
  int buffer[3];
};
struct DeviceConfig_R000229_2913_1
{
  short baud_rate;
  int timeout;
  int port;
  int buffer[3];
};
union RegisterBank_R000229_2913_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union TelemetryField_R000229_2913_1
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
void fn_R000229_2913_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_22_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_22_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_22_1) & 63;
  aux_2 = (aux_2 + quantum_22_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int bound_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_23_1 > 38)
  {
    acc_1 = ((acc_1 + (bound_23_1 * 2)) + 5) & 127;
    aux_1 ^= bound_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_23_2 > 38)
  {
    acc_2 = ((acc_2 + (bound_23_2 * 2)) + 5) & 127;
    aux_2 ^= bound_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_23_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_15_1 = local_arr_1[aux_1 % 3];
  int bound_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_22_1 == quantum_22_2);
  assert(bound_23_1 == bound_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_15_1 == bound_15_2);
}

int fn_R000229_2913_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_22 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_22) & 63;
  acc ^= aux;
  int bound_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_23 > 38)
  {
    acc = ((acc + (bound_23 * 2)) + 5) & 127;
    aux ^= bound_23 & 15;
  }
  else
  {
    acc = ((acc - bound_23) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_15 = local_arr[aux % 3];
  acc = (acc + (bound_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000229_2913_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_21_1 > 30)
  {
    acc_1 = ((acc_1 + (stride_21_1 * 2)) + 5) & 127;
    aux_1 ^= stride_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_21_2 > 30)
  {
    acc_2 = ((acc_2 + (stride_21_2 * 2)) + 5) & 127;
    aux_2 ^= stride_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_21_2) + 11) & 127;
    aux_2 += 3;
  }
  int cursor_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_46_1)
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

  switch (cursor_46_2)
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

  int accumulator_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_20_1) & 63;
  aux_2 = (aux_2 + accumulator_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_21_1 == stride_21_2);
  assert(cursor_46_1 == cursor_46_2);
  assert(accumulator_20_1 == accumulator_20_2);
}

int fn_R000229_2913_1(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_21 > 30)
  {
    acc = ((acc + (stride_21 * 2)) + 5) & 127;
    aux ^= stride_21 & 15;
  }
  else
  {
    acc = ((acc - stride_21) + 11) & 127;
    aux += 3;
  }
  int cursor_46 = (aux + st.buffer[1]) & 3;
  switch (cursor_46)
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

  int accumulator_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_20) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000229_2913_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int offset_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_73_1) & 63;
  aux_2 = (aux_2 + offset_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_13_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_13_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_13_1)
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

  switch (offset_13_2)
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
  int phase_96_1 = local_arr_1[aux_1 % 3];
  int phase_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_96_2 * 2)) & 127;
  int threshold_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_57_1 > 32)
  {
    acc_1 = ((acc_1 + (threshold_57_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_57_2 > 32)
  {
    acc_2 = ((acc_2 + (threshold_57_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_57_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_73_1 == offset_73_2);
  assert(offset_13_1 == offset_13_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_96_1 == phase_96_2);
  assert(threshold_57_1 == threshold_57_2);
}

int fn_R000229_2913_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int offset_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_73) & 63;
  acc ^= aux;
  int offset_13 = (aux + st.buffer[1]) & 3;
  switch (offset_13)
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
  int phase_96 = local_arr[aux % 3];
  acc = (acc + (phase_96 * 2)) & 127;
  int threshold_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_57 > 32)
  {
    acc = ((acc + (threshold_57 * 2)) + 5) & 127;
    aux ^= threshold_57 & 15;
  }
  else
  {
    acc = ((acc - threshold_57) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000229_2913_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int coefficient_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_71_1)
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

  switch (coefficient_71_2)
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

  int phase_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int phase_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (phase_10_1 > 41)
  {
    acc_1 = ((acc_1 + (phase_10_1 * 2)) + 5) & 127;
    aux_1 ^= phase_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - phase_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (phase_10_2 > 41)
  {
    acc_2 = ((acc_2 + (phase_10_2 * 2)) + 5) & 127;
    aux_2 ^= phase_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - phase_10_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_81_1 = local_arr_1[aux_1 % 3];
  int window_81_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_81_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_81_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_71_1 == coefficient_71_2);
  assert(phase_10_1 == phase_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_81_1 == window_81_2);
}

int fn_R000229_2913_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int coefficient_71 = (aux + st.buffer[1]) & 3;
  switch (coefficient_71)
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

  int phase_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (phase_10 > 41)
  {
    acc = ((acc + (phase_10 * 2)) + 5) & 127;
    aux ^= phase_10 & 15;
  }
  else
  {
    acc = ((acc - phase_10) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int window_81 = local_arr[aux % 3];
  acc = (acc + (window_81 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000229_2913_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_92_1 = local_arr_1[aux_1 % 3];
  int cursor_92_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_92_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_92_2 * 2)) & 127;
  int anchor_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_86_1 > 12)
  {
    acc_1 = ((acc_1 + (anchor_86_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_86_2 > 12)
  {
    acc_2 = ((acc_2 + (anchor_86_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_86_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_92_1 == cursor_92_2);
  assert(anchor_86_1 == anchor_86_2);
}

int fn_R000229_2913_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int local_arr[3] = {4, 9, 15};
  int cursor_92 = local_arr[aux % 3];
  acc = (acc + (cursor_92 * 2)) & 127;
  int anchor_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_86 > 12)
  {
    acc = ((acc + (anchor_86 * 2)) + 5) & 127;
    aux ^= anchor_86 & 15;
  }
  else
  {
    acc = ((acc - anchor_86) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000229_2913_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 15) & 127;
  int acc_2 = (p0_2 + 15) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_82_1)
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

  switch (sample_82_2)
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
  int vector_35_1 = local_arr_1[aux_1 % 3];
  int vector_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_35_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_82_1 == sample_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_35_1 == vector_35_2);
}

int fn_R000229_2913_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 15) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_82 = (aux + st.buffer[1]) & 3;
  switch (sample_82)
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
  int vector_35 = local_arr[aux % 3];
  acc = (acc + (vector_35 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000229_2913_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int quantum_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_23_1)
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

  switch (quantum_23_2)
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

  int weight_43_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_43_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_43_1 > 10)
  {
    acc_1 = ((acc_1 + (weight_43_1 * 2)) + 5) & 127;
    aux_1 ^= weight_43_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_43_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_43_2 > 10)
  {
    acc_2 = ((acc_2 + (weight_43_2 * 2)) + 5) & 127;
    aux_2 ^= weight_43_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_43_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_23_1 == quantum_23_2);
  assert(weight_43_1 == weight_43_2);
}

int fn_R000229_2913_6(int p0, int p1, int p2)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int quantum_23 = (aux + st.buffer[1]) & 3;
  switch (quantum_23)
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

  int weight_43 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_43 > 10)
  {
    acc = ((acc + (weight_43 * 2)) + 5) & 127;
    aux ^= weight_43 & 15;
  }
  else
  {
    acc = ((acc - weight_43) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000229_2913_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int coefficient_63_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_63_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_63_1) & 63;
  aux_2 = (aux_2 + coefficient_63_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int quantum_70_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_70_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_70_1 > 16)
  {
    acc_1 = ((acc_1 + (quantum_70_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_70_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_70_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_70_2 > 16)
  {
    acc_2 = ((acc_2 + (quantum_70_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_70_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_70_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_76_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_76_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_76_1)
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

  switch (bound_76_2)
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
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_63_1 == coefficient_63_2);
  assert(quantum_70_1 == quantum_70_2);
  assert(bound_76_1 == bound_76_2);
}

int fn_R000229_2913_7(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int coefficient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_63) & 63;
  acc ^= aux;
  int quantum_70 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_70 > 16)
  {
    acc = ((acc + (quantum_70 * 2)) + 5) & 127;
    aux ^= quantum_70 & 15;
  }
  else
  {
    acc = ((acc - quantum_70) + 11) & 127;
    aux += 3;
  }
  int bound_76 = (aux + st.buffer[1]) & 3;
  switch (bound_76)
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
  return (acc + aux) & 255;
}

void fn_R000229_2913_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_91_1 = local_arr_1[aux_1 % 3];
  int anchor_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_91_2 * 2)) & 127;
  int tracker_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_51_1 > 31)
  {
    acc_1 = ((acc_1 + (tracker_51_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_51_2 > 31)
  {
    acc_2 = ((acc_2 + (tracker_51_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_51_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_91_1 == anchor_91_2);
  assert(tracker_51_1 == tracker_51_2);
}

int fn_R000229_2913_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int local_arr[3] = {4, 9, 15};
  int anchor_91 = local_arr[aux % 3];
  acc = (acc + (anchor_91 * 2)) & 127;
  int tracker_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_51 > 31)
  {
    acc = ((acc + (tracker_51 * 2)) + 5) & 127;
    aux ^= tracker_51 & 15;
  }
  else
  {
    acc = ((acc - tracker_51) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000229_2913_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_43_1 = local_arr_1[aux_1 % 3];
  int checksum_43_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_43_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_43_2 * 2)) & 127;
  int weight_27_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_27_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_27_1)
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

  switch (weight_27_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_43_1 == checksum_43_2);
  assert(weight_27_1 == weight_27_2);
}

int fn_R000229_2913_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_43 = local_arr[aux % 3];
  acc = (acc + (checksum_43 * 2)) & 127;
  int weight_27 = (aux + st.buffer[1]) & 3;
  switch (weight_27)
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

void fn_R000229_2913_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int checksum_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_78_1) & 63;
  aux_2 = (aux_2 + checksum_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_39_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_39_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_39_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_39_1 * 2)) + 5) & 127;
    aux_1 ^= metric_39_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_39_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_39_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_39_2 * 2)) + 5) & 127;
    aux_2 ^= metric_39_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_39_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_78_1 == checksum_78_2);
  assert(metric_39_1 == metric_39_2);
}

int fn_R000229_2913_10(int p0, int p1)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int checksum_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_78) & 63;
  acc ^= aux;
  int metric_39 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_39 > 16)
  {
    acc = ((acc + (metric_39 * 2)) + 5) & 127;
    aux ^= metric_39 & 15;
  }
  else
  {
    acc = ((acc - metric_39) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000229_2913_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_31_1 > 15)
  {
    acc_1 = ((acc_1 + (sample_31_1 * 2)) + 5) & 127;
    aux_1 ^= sample_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_31_2 > 15)
  {
    acc_2 = ((acc_2 + (sample_31_2 * 2)) + 5) & 127;
    aux_2 ^= sample_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_31_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_21_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_21_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_21_1)
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

  switch (pivot_21_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_31_1 == sample_31_2);
  assert(pivot_21_1 == pivot_21_2);
}

int fn_R000229_2913_11(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_31 > 15)
  {
    acc = ((acc + (sample_31 * 2)) + 5) & 127;
    aux ^= sample_31 & 15;
  }
  else
  {
    acc = ((acc - sample_31) + 11) & 127;
    aux += 3;
  }
  int pivot_21 = (aux + st.buffer[1]) & 3;
  switch (pivot_21)
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

void fn_R000229_2913_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_83_1 = local_arr_1[aux_1 % 3];
  int metric_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_83_2 * 2)) & 127;
  int window_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_31_1) & 63;
  aux_2 = (aux_2 + window_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_50_1 > 37)
  {
    acc_1 = ((acc_1 + (tally_50_1 * 2)) + 5) & 127;
    aux_1 ^= tally_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_50_2 > 37)
  {
    acc_2 = ((acc_2 + (tally_50_2 * 2)) + 5) & 127;
    aux_2 ^= tally_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_50_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_83_1 == metric_83_2);
  assert(window_31_1 == window_31_2);
  assert(tally_50_1 == tally_50_2);
}

int fn_R000229_2913_12(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int metric_83 = local_arr[aux % 3];
  acc = (acc + (metric_83 * 2)) & 127;
  int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_31) & 63;
  acc ^= aux;
  int tally_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_50 > 37)
  {
    acc = ((acc + (tally_50 * 2)) + 5) & 127;
    aux ^= tally_50 & 15;
  }
  else
  {
    acc = ((acc - tally_50) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000229_2913_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int cursor_15_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_15_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_15_1)
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

  switch (cursor_15_2)
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
  int residue_77_1 = local_arr_1[aux_1 % 3];
  int residue_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_45_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_45_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_45_1) & 63;
  aux_2 = (aux_2 + factor_45_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_15_1 == cursor_15_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(factor_45_1 == factor_45_2);
}

int fn_R000229_2913_13(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int cursor_15 = (aux + st.buffer[1]) & 3;
  switch (cursor_15)
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
  int residue_77 = local_arr[aux % 3];
  acc = (acc + (residue_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000229_2913_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_19_1 = local_arr_1[aux_1 % 3];
  int margin_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_19_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_42_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_42_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_42_1) & 63;
  aux_2 = (aux_2 + offset_42_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_19_1 == margin_19_2);
  assert(offset_42_1 == offset_42_2);
}

int fn_R000229_2913_14(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int local_arr[3] = {4, 9, 15};
  int margin_19 = local_arr[aux % 3];
  acc = (acc + (margin_19 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_42 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_42) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000229_2913_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int offset_87_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_87_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_87_1) & 63;
  aux_2 = (aux_2 + offset_87_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_87_1 == offset_87_2);
}

int fn_R000229_2913_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int offset_87 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_87) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000229_2913_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int metric_88_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_88_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_88_1 > 35)
  {
    acc_1 = ((acc_1 + (metric_88_1 * 2)) + 5) & 127;
    aux_1 ^= metric_88_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_88_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_88_2 > 35)
  {
    acc_2 = ((acc_2 + (metric_88_2 * 2)) + 5) & 127;
    aux_2 ^= metric_88_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_88_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_84_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_84_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_84_1) & 63;
  aux_2 = (aux_2 + vector_84_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_93_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_93_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_93_1)
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

  switch (sample_93_2)
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
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.timeout == st_2.timeout);
  assert(st_1.port == st_2.port);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_88_1 == metric_88_2);
  assert(vector_84_1 == vector_84_2);
  assert(sample_93_1 == sample_93_2);
}

int fn_R000229_2913_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000229_2913_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int metric_88 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_88 > 35)
  {
    acc = ((acc + (metric_88 * 2)) + 5) & 127;
    aux ^= metric_88 & 15;
  }
  else
  {
    acc = ((acc - metric_88) + 11) & 127;
    aux += 3;
  }
  int vector_84 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_84) & 63;
  acc ^= aux;
  int sample_93 = (aux + st.buffer[1]) & 3;
  switch (sample_93)
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

void fn_R000229_2913_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 40) & 127;
  int acc_2 = (p0_2 + 40) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st_1 = {0};
  struct Vector3D_R000229_2913_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int quantum_80_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_80_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_80_1)
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

  switch (quantum_80_2)
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

  int residue_67_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_67_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_67_1 > 26)
  {
    acc_1 = ((acc_1 + (residue_67_1 * 2)) + 5) & 127;
    aux_1 ^= residue_67_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_67_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_67_2 > 26)
  {
    acc_2 = ((acc_2 + (residue_67_2 * 2)) + 5) & 127;
    aux_2 ^= residue_67_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_67_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_96_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_96_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_96_1) & 63;
  aux_2 = (aux_2 + quantum_96_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_80_1 == quantum_80_2);
  assert(residue_67_1 == residue_67_2);
  assert(quantum_96_1 == quantum_96_2);
}

int fn_R000229_2913_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 40) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000229_2913_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int quantum_80 = (aux + st.buffer[1]) & 3;
  switch (quantum_80)
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

  int residue_67 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_67 > 26)
  {
    acc = ((acc + (residue_67 * 2)) + 5) & 127;
    aux ^= residue_67 & 15;
  }
  else
  {
    acc = ((acc - residue_67) + 11) & 127;
    aux += 3;
  }
  int quantum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_96) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000229_0_1;
  int sec_r000229_0_2;
  int sec_r000229_1_1;
  int sec_r000229_1_2;
  int sec_r000229_2_1;
  int sec_r000229_2_2;
  int sec_r000229_3_1;
  int sec_r000229_3_2;
  int sec_r000229_4_1;
  int sec_r000229_4_2;
  int sec_r000229_5_1;
  int sec_r000229_5_2;
  int sec_r000229_6_1;
  int sec_r000229_6_2;
  int sec_r000229_7_1;
  int sec_r000229_7_2;
  int sec_r000229_8_1;
  int sec_r000229_8_2;
  int sec_r000229_9_1;
  int sec_r000229_9_2;
  int sec_r000229_10_1;
  int sec_r000229_10_2;
  int sec_r000229_11_1;
  int sec_r000229_11_2;
  int sec_r000229_12_1;
  int sec_r000229_12_2;
  int sec_r000229_13_1;
  int sec_r000229_13_2;
  int sec_r000229_14_1;
  int sec_r000229_14_2;
  int sec_r000229_15_1;
  int sec_r000229_15_2;
  int sec_r000229_16_1;
  int sec_r000229_16_2;
  int sec_r000229_17_1;
  int sec_r000229_17_2;
  int sec_r000229_18_1;
  int sec_r000229_18_2;
  int sec_r000229_19_1;
  int sec_r000229_19_2;
  int sec_r000229_20_1;
  int sec_r000229_20_2;
  int sec_r000229_21_1;
  int sec_r000229_21_2;
  int sec_r000229_22_1;
  int sec_r000229_22_2;
  int sec_r000229_23_1;
  int sec_r000229_23_2;
  int pub_r000229_0_1;
  int pub_r000229_0_2;
  int pub_r000229_1_1;
  int pub_r000229_1_2;
  int pub_r000229_2_1;
  int pub_r000229_2_2;
  int pub_r000229_3_1;
  int pub_r000229_3_2;
  int pub_r000229_4_1;
  int pub_r000229_4_2;
  int pub_r000229_5_1;
  int pub_r000229_5_2;
  int pub_r000229_6_1;
  int pub_r000229_6_2;
  int pub_r000229_7_1;
  int pub_r000229_7_2;
  int pub_r000229_8_1;
  int pub_r000229_8_2;
  int pub_r000229_9_1;
  int pub_r000229_9_2;
  int pub_r000229_10_1;
  int pub_r000229_10_2;
  int pub_r000229_11_1;
  int pub_r000229_11_2;
  int pub_r000229_12_1;
  int pub_r000229_12_2;
  int pub_r000229_13_1;
  int pub_r000229_13_2;
  int pub_r000229_14_1;
  int pub_r000229_14_2;
  int pub_r000229_15_1;
  int pub_r000229_15_2;
  int pub_r000229_16_1;
  int pub_r000229_16_2;
  int pub_r000229_17_1;
  int pub_r000229_17_2;
  int pub_r000229_18_1;
  int pub_r000229_18_2;
  int pub_r000229_19_1;
  int pub_r000229_19_2;
  int pub_r000229_20_1;
  int pub_r000229_20_2;
  int pub_r000229_21_1;
  int pub_r000229_21_2;
  int pub_r000229_22_1;
  int pub_r000229_22_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000229_0_1 >= (-100)) && (pub_r000229_0_1 <= 100));
  __CPROVER_assume((pub_r000229_0_2 >= (-100)) && (pub_r000229_0_2 <= 100));
  __CPROVER_assume((pub_r000229_1_1 >= (-100)) && (pub_r000229_1_1 <= 100));
  __CPROVER_assume((pub_r000229_1_2 >= (-100)) && (pub_r000229_1_2 <= 100));
  __CPROVER_assume((pub_r000229_2_1 >= (-100)) && (pub_r000229_2_1 <= 100));
  __CPROVER_assume((pub_r000229_2_2 >= (-100)) && (pub_r000229_2_2 <= 100));
  __CPROVER_assume((pub_r000229_3_1 >= (-100)) && (pub_r000229_3_1 <= 100));
  __CPROVER_assume((pub_r000229_3_2 >= (-100)) && (pub_r000229_3_2 <= 100));
  __CPROVER_assume((pub_r000229_4_1 >= (-100)) && (pub_r000229_4_1 <= 100));
  __CPROVER_assume((pub_r000229_4_2 >= (-100)) && (pub_r000229_4_2 <= 100));
  __CPROVER_assume((pub_r000229_5_1 >= (-100)) && (pub_r000229_5_1 <= 100));
  __CPROVER_assume((pub_r000229_5_2 >= (-100)) && (pub_r000229_5_2 <= 100));
  __CPROVER_assume((pub_r000229_6_1 >= (-100)) && (pub_r000229_6_1 <= 100));
  __CPROVER_assume((pub_r000229_6_2 >= (-100)) && (pub_r000229_6_2 <= 100));
  __CPROVER_assume((pub_r000229_7_1 >= (-100)) && (pub_r000229_7_1 <= 100));
  __CPROVER_assume((pub_r000229_7_2 >= (-100)) && (pub_r000229_7_2 <= 100));
  __CPROVER_assume((pub_r000229_8_1 >= (-100)) && (pub_r000229_8_1 <= 100));
  __CPROVER_assume((pub_r000229_8_2 >= (-100)) && (pub_r000229_8_2 <= 100));
  __CPROVER_assume((pub_r000229_9_1 >= (-100)) && (pub_r000229_9_1 <= 100));
  __CPROVER_assume((pub_r000229_9_2 >= (-100)) && (pub_r000229_9_2 <= 100));
  __CPROVER_assume((pub_r000229_10_1 >= (-100)) && (pub_r000229_10_1 <= 100));
  __CPROVER_assume((pub_r000229_10_2 >= (-100)) && (pub_r000229_10_2 <= 100));
  __CPROVER_assume((pub_r000229_11_1 >= (-100)) && (pub_r000229_11_1 <= 100));
  __CPROVER_assume((pub_r000229_11_2 >= (-100)) && (pub_r000229_11_2 <= 100));
  __CPROVER_assume((pub_r000229_12_1 >= (-100)) && (pub_r000229_12_1 <= 100));
  __CPROVER_assume((pub_r000229_12_2 >= (-100)) && (pub_r000229_12_2 <= 100));
  __CPROVER_assume((pub_r000229_13_1 >= (-100)) && (pub_r000229_13_1 <= 100));
  __CPROVER_assume((pub_r000229_13_2 >= (-100)) && (pub_r000229_13_2 <= 100));
  __CPROVER_assume((pub_r000229_14_1 >= (-100)) && (pub_r000229_14_1 <= 100));
  __CPROVER_assume((pub_r000229_14_2 >= (-100)) && (pub_r000229_14_2 <= 100));
  __CPROVER_assume((pub_r000229_15_1 >= (-100)) && (pub_r000229_15_1 <= 100));
  __CPROVER_assume((pub_r000229_15_2 >= (-100)) && (pub_r000229_15_2 <= 100));
  __CPROVER_assume((pub_r000229_16_1 >= (-100)) && (pub_r000229_16_1 <= 100));
  __CPROVER_assume((pub_r000229_16_2 >= (-100)) && (pub_r000229_16_2 <= 100));
  __CPROVER_assume((pub_r000229_17_1 >= (-100)) && (pub_r000229_17_1 <= 100));
  __CPROVER_assume((pub_r000229_17_2 >= (-100)) && (pub_r000229_17_2 <= 100));
  __CPROVER_assume((pub_r000229_18_1 >= (-100)) && (pub_r000229_18_1 <= 100));
  __CPROVER_assume((pub_r000229_18_2 >= (-100)) && (pub_r000229_18_2 <= 100));
  __CPROVER_assume((pub_r000229_19_1 >= (-100)) && (pub_r000229_19_1 <= 100));
  __CPROVER_assume((pub_r000229_19_2 >= (-100)) && (pub_r000229_19_2 <= 100));
  __CPROVER_assume((pub_r000229_20_1 >= (-100)) && (pub_r000229_20_1 <= 100));
  __CPROVER_assume((pub_r000229_20_2 >= (-100)) && (pub_r000229_20_2 <= 100));
  __CPROVER_assume((pub_r000229_21_1 >= (-100)) && (pub_r000229_21_1 <= 100));
  __CPROVER_assume((pub_r000229_21_2 >= (-100)) && (pub_r000229_21_2 <= 100));
  __CPROVER_assume((pub_r000229_22_1 >= (-100)) && (pub_r000229_22_1 <= 100));
  __CPROVER_assume((pub_r000229_22_2 >= (-100)) && (pub_r000229_22_2 <= 100));
  __CPROVER_assume((sec_r000229_0_1 >= 0) && (sec_r000229_0_1 <= 255));
  __CPROVER_assume((sec_r000229_0_2 >= 0) && (sec_r000229_0_2 <= 255));
  __CPROVER_assume((sec_r000229_1_1 >= 0) && (sec_r000229_1_1 <= 255));
  __CPROVER_assume((sec_r000229_1_2 >= 0) && (sec_r000229_1_2 <= 255));
  __CPROVER_assume((sec_r000229_2_1 >= 0) && (sec_r000229_2_1 <= 255));
  __CPROVER_assume((sec_r000229_2_2 >= 0) && (sec_r000229_2_2 <= 255));
  __CPROVER_assume((sec_r000229_3_1 >= 0) && (sec_r000229_3_1 <= 255));
  __CPROVER_assume((sec_r000229_3_2 >= 0) && (sec_r000229_3_2 <= 255));
  __CPROVER_assume((sec_r000229_4_1 >= 0) && (sec_r000229_4_1 <= 255));
  __CPROVER_assume((sec_r000229_4_2 >= 0) && (sec_r000229_4_2 <= 255));
  __CPROVER_assume((sec_r000229_5_1 >= 0) && (sec_r000229_5_1 <= 255));
  __CPROVER_assume((sec_r000229_5_2 >= 0) && (sec_r000229_5_2 <= 255));
  __CPROVER_assume((sec_r000229_6_1 >= 0) && (sec_r000229_6_1 <= 255));
  __CPROVER_assume((sec_r000229_6_2 >= 0) && (sec_r000229_6_2 <= 255));
  __CPROVER_assume((sec_r000229_7_1 >= 0) && (sec_r000229_7_1 <= 255));
  __CPROVER_assume((sec_r000229_7_2 >= 0) && (sec_r000229_7_2 <= 255));
  __CPROVER_assume((sec_r000229_8_1 >= 0) && (sec_r000229_8_1 <= 255));
  __CPROVER_assume((sec_r000229_8_2 >= 0) && (sec_r000229_8_2 <= 255));
  __CPROVER_assume((sec_r000229_9_1 >= 0) && (sec_r000229_9_1 <= 255));
  __CPROVER_assume((sec_r000229_9_2 >= 0) && (sec_r000229_9_2 <= 255));
  __CPROVER_assume((sec_r000229_10_1 >= 0) && (sec_r000229_10_1 <= 255));
  __CPROVER_assume((sec_r000229_10_2 >= 0) && (sec_r000229_10_2 <= 255));
  __CPROVER_assume((sec_r000229_11_1 >= 0) && (sec_r000229_11_1 <= 255));
  __CPROVER_assume((sec_r000229_11_2 >= 0) && (sec_r000229_11_2 <= 255));
  __CPROVER_assume((sec_r000229_12_1 >= 0) && (sec_r000229_12_1 <= 255));
  __CPROVER_assume((sec_r000229_12_2 >= 0) && (sec_r000229_12_2 <= 255));
  __CPROVER_assume((sec_r000229_13_1 >= 0) && (sec_r000229_13_1 <= 255));
  __CPROVER_assume((sec_r000229_13_2 >= 0) && (sec_r000229_13_2 <= 255));
  __CPROVER_assume((sec_r000229_14_1 >= 0) && (sec_r000229_14_1 <= 255));
  __CPROVER_assume((sec_r000229_14_2 >= 0) && (sec_r000229_14_2 <= 255));
  __CPROVER_assume((sec_r000229_15_1 >= 0) && (sec_r000229_15_1 <= 255));
  __CPROVER_assume((sec_r000229_15_2 >= 0) && (sec_r000229_15_2 <= 255));
  __CPROVER_assume((sec_r000229_16_1 >= 0) && (sec_r000229_16_1 <= 255));
  __CPROVER_assume((sec_r000229_16_2 >= 0) && (sec_r000229_16_2 <= 255));
  __CPROVER_assume((sec_r000229_17_1 >= 0) && (sec_r000229_17_1 <= 255));
  __CPROVER_assume((sec_r000229_17_2 >= 0) && (sec_r000229_17_2 <= 255));
  __CPROVER_assume((sec_r000229_18_1 >= 0) && (sec_r000229_18_1 <= 255));
  __CPROVER_assume((sec_r000229_18_2 >= 0) && (sec_r000229_18_2 <= 255));
  __CPROVER_assume((sec_r000229_19_1 >= 0) && (sec_r000229_19_1 <= 255));
  __CPROVER_assume((sec_r000229_19_2 >= 0) && (sec_r000229_19_2 <= 255));
  __CPROVER_assume((sec_r000229_20_1 >= 0) && (sec_r000229_20_1 <= 255));
  __CPROVER_assume((sec_r000229_20_2 >= 0) && (sec_r000229_20_2 <= 255));
  __CPROVER_assume((sec_r000229_21_1 >= 0) && (sec_r000229_21_1 <= 255));
  __CPROVER_assume((sec_r000229_21_2 >= 0) && (sec_r000229_21_2 <= 255));
  __CPROVER_assume((sec_r000229_22_1 >= 0) && (sec_r000229_22_1 <= 255));
  __CPROVER_assume((sec_r000229_22_2 >= 0) && (sec_r000229_22_2 <= 255));
  __CPROVER_assume((sec_r000229_23_1 >= 0) && (sec_r000229_23_1 <= 255));
  __CPROVER_assume((sec_r000229_23_2 >= 0) && (sec_r000229_23_2 <= 255));
  struct Vector3D_R000229_2913_0 st_var_0_1 = {0};
  struct Vector3D_R000229_2913_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000229_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000229_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000229_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000229_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000229_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000229_0_2 + 7) & 15;
  struct DeviceConfig_R000229_2913_1 st_var_1_1 = {0};
  struct DeviceConfig_R000229_2913_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000229_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000229_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000229_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000229_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000229_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000229_0_2 + 9) & 15;
  union RegisterBank_R000229_2913_0 u_var_1;
  union RegisterBank_R000229_2913_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_0_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_0_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_0_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
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
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 34)
    {
      chk_sum_1 ^= stage_v_5_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_5_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 34)
    {
      chk_sum_2 ^= stage_v_5_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_6_1 = table_1[2];
  int stage_v_6_2 = table_2[2];
  table_1[2] = (table_1[3] + 13) & 63;
  table_2[2] = (table_2[3] + 13) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  int stage_v_7_1 = ((st_var_1_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_1_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 33)
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
  if (stage_v_7_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 33)
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
  int stage_v_8_1 = ((st_var_0_1.buffer[2] * 2) + 31) & 63;
  int stage_v_8_2 = ((st_var_0_2.buffer[2] * 2) + 31) & 63;
  if (stage_v_8_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_8_1) - 5) & 255;
    if (stage_v_8_1 > 54)
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
  if (stage_v_8_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_8_2) - 5) & 255;
    if (stage_v_8_2 > 54)
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
  int stage_v_9_1 = 0;
  int stage_v_9_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_9_1 = ((stage_v_9_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_9_2 = ((stage_v_9_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_10_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_10_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_10_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
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
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = ((st_var_0_1.buffer[2] * 2) + 49) & 63;
  int stage_v_14_2 = ((st_var_0_2.buffer[2] * 2) + 49) & 63;
  if (stage_v_14_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_14_1) - 5) & 255;
    if (stage_v_14_1 > 25)
    {
      chk_sum_1 ^= stage_v_14_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_14_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_14_2) - 5) & 255;
    if (stage_v_14_2 > 25)
    {
      chk_sum_2 ^= stage_v_14_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  int stage_v_16_1 = table_1[0];
  int stage_v_16_2 = table_2[0];
  table_1[0] = (table_1[1] + 33) & 63;
  table_2[0] = (table_2[1] + 33) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  int stage_v_17_1 = ((st_var_1_1.buffer[2] * 2) + 58) & 63;
  int stage_v_17_2 = ((st_var_1_2.buffer[2] * 2) + 58) & 63;
  if (stage_v_17_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_17_1) - 5) & 255;
    if (stage_v_17_1 > 25)
    {
      chk_sum_1 ^= stage_v_17_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_17_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_17_2) - 5) & 255;
    if (stage_v_17_2 > 25)
    {
      chk_sum_2 ^= stage_v_17_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 19) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 19) & 15;
  int stage_v_18_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_18_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_18_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_18_2) & 255;
  chk_sum_1 ^= stage_v_18_1;
  chk_sum_2 ^= stage_v_18_2;
  int stage_v_19_1 = ((st_var_1_1.buffer[1] * 2) + 64) & 63;
  int stage_v_19_2 = ((st_var_1_2.buffer[1] * 2) + 64) & 63;
  if (stage_v_19_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 42)
    {
      chk_sum_1 ^= stage_v_19_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_19_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 42)
    {
      chk_sum_2 ^= stage_v_19_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_20_1 = (st_var_0_1.buffer[0] ^ 23) & 3;
  int stage_v_20_2 = (st_var_0_2.buffer[0] ^ 23) & 3;
  switch (stage_v_20_1)
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

  switch (stage_v_20_2)
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

  int stage_v_21_1 = 0;
  int stage_v_21_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_21_1 = ((stage_v_21_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_21_2 = ((stage_v_21_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  int stage_v_22_1 = ((st_var_0_1.buffer[1] * 2) + 73) & 63;
  int stage_v_22_2 = ((st_var_0_2.buffer[1] * 2) + 73) & 63;
  if (stage_v_22_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_22_1) - 5) & 255;
    if (stage_v_22_1 > 52)
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
  if (stage_v_22_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_22_2) - 5) & 255;
    if (stage_v_22_2 > 52)
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
  int stage_v_23_1 = table_1[3];
  int stage_v_23_2 = table_2[3];
  table_1[3] = (table_1[0] + 47) & 63;
  table_2[3] = (table_2[0] + 47) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  int stage_v_24_1 = (st_var_0_1.buffer[0] ^ 27) & 3;
  int stage_v_24_2 = (st_var_0_2.buffer[0] ^ 27) & 3;
  switch (stage_v_24_1)
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

  switch (stage_v_24_2)
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

  int stage_v_25_1 = ((st_var_1_1.buffer[1] * 2) + 82) & 63;
  int stage_v_25_2 = ((st_var_1_2.buffer[1] * 2) + 82) & 63;
  if (stage_v_25_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + stage_v_25_1) - 5) & 255;
    if (stage_v_25_1 > 55)
    {
      chk_sum_1 ^= stage_v_25_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_25_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + stage_v_25_2) - 5) & 255;
    if (stage_v_25_2 > 55)
    {
      chk_sum_2 ^= stage_v_25_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_26_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (31 & 31);
  int stage_v_26_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (31 & 31);
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  chk_sum_1 ^= (stage_v_26_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_26_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 28) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 28) & 15;
  int stage_v_27_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_27_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  chk_sum_1 ^= stage_v_27_1;
  chk_sum_2 ^= stage_v_27_2;
  int stage_v_28_1 = (st_var_0_1.buffer[0] ^ 31) & 3;
  int stage_v_28_2 = (st_var_0_2.buffer[0] ^ 31) & 3;
  switch (stage_v_28_1)
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

  switch (stage_v_28_2)
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

  int stage_v_29_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_29_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_30_1 = ((stage_v_30_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_30_2 = ((stage_v_30_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
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
  int s_idx_33_1 = sec_r000229_9_1 & 3;
  int s_idx_33_2 = sec_r000229_9_2 & 3;
  int stage_v_33_1 = (table_1[s_idx_33_1] + pub_r000229_10_1) & 127;
  int stage_v_33_2 = (table_2[s_idx_33_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_33_1] = (stage_v_33_1 + 7) & 63;
  table_2[s_idx_33_2] = (stage_v_33_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int s_idx_34_1 = stage_v_33_1 & 3;
  int s_idx_34_2 = stage_v_33_2 & 3;
  int stage_v_34_1 = (table_1[s_idx_34_1] + pub_r000229_21_1) & 127;
  int stage_v_34_2 = (table_2[s_idx_34_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_34_1] = (stage_v_34_1 + 7) & 63;
  table_2[s_idx_34_2] = (stage_v_34_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int s_idx_35_1 = stage_v_34_1 & 3;
  int s_idx_35_2 = stage_v_34_2 & 3;
  int stage_v_35_1 = (table_1[s_idx_35_1] + pub_r000229_1_1) & 127;
  int stage_v_35_2 = (table_2[s_idx_35_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_35_1] = (stage_v_35_1 + 7) & 63;
  table_2[s_idx_35_2] = (stage_v_35_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int s_idx_36_1 = sec_r000229_23_1 & 3;
  int s_idx_36_2 = sec_r000229_23_2 & 3;
  int stage_v_36_1 = (table_1[s_idx_36_1] + pub_r000229_9_1) & 127;
  int stage_v_36_2 = (table_2[s_idx_36_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_36_1] = (stage_v_36_1 + 7) & 63;
  table_2[s_idx_36_2] = (stage_v_36_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int s_idx_37_1 = stage_v_34_1 & 3;
  int s_idx_37_2 = stage_v_34_2 & 3;
  int stage_v_37_1 = (table_1[s_idx_37_1] + pub_r000229_9_1) & 127;
  int stage_v_37_2 = (table_2[s_idx_37_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_37_1] = (stage_v_37_1 + 7) & 63;
  table_2[s_idx_37_2] = (stage_v_37_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int s_idx_38_1 = stage_v_37_1 & 3;
  int s_idx_38_2 = stage_v_37_2 & 3;
  int stage_v_38_1 = (table_1[s_idx_38_1] + pub_r000229_20_1) & 127;
  int stage_v_38_2 = (table_2[s_idx_38_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_38_1] = (stage_v_38_1 + 7) & 63;
  table_2[s_idx_38_2] = (stage_v_38_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int s_idx_39_1 = stage_v_36_1 & 3;
  int s_idx_39_2 = stage_v_36_2 & 3;
  int stage_v_39_1 = (table_1[s_idx_39_1] + pub_r000229_9_1) & 127;
  int stage_v_39_2 = (table_2[s_idx_39_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_39_1] = (stage_v_39_1 + 7) & 63;
  table_2[s_idx_39_2] = (stage_v_39_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int s_idx_40_1 = stage_v_38_1 & 3;
  int s_idx_40_2 = stage_v_38_2 & 3;
  int stage_v_40_1 = (table_1[s_idx_40_1] + pub_r000229_13_1) & 127;
  int stage_v_40_2 = (table_2[s_idx_40_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_40_1] = (stage_v_40_1 + 7) & 63;
  table_2[s_idx_40_2] = (stage_v_40_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int s_idx_41_1 = stage_v_39_1 & 3;
  int s_idx_41_2 = stage_v_39_2 & 3;
  int stage_v_41_1 = (table_1[s_idx_41_1] + pub_r000229_11_1) & 127;
  int stage_v_41_2 = (table_2[s_idx_41_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_41_1] = (stage_v_41_1 + 7) & 63;
  table_2[s_idx_41_2] = (stage_v_41_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int s_idx_42_1 = sec_r000229_18_1 & 3;
  int s_idx_42_2 = sec_r000229_18_2 & 3;
  int stage_v_42_1 = (table_1[s_idx_42_1] + pub_r000229_10_1) & 127;
  int stage_v_42_2 = (table_2[s_idx_42_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_42_1] = (stage_v_42_1 + 7) & 63;
  table_2[s_idx_42_2] = (stage_v_42_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int s_idx_43_1 = stage_v_39_1 & 3;
  int s_idx_43_2 = stage_v_39_2 & 3;
  int stage_v_43_1 = (table_1[s_idx_43_1] + pub_r000229_17_1) & 127;
  int stage_v_43_2 = (table_2[s_idx_43_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_43_1] = (stage_v_43_1 + 7) & 63;
  table_2[s_idx_43_2] = (stage_v_43_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int s_idx_44_1 = stage_v_37_1 & 3;
  int s_idx_44_2 = stage_v_37_2 & 3;
  int stage_v_44_1 = (table_1[s_idx_44_1] + pub_r000229_17_1) & 127;
  int stage_v_44_2 = (table_2[s_idx_44_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_44_1] = (stage_v_44_1 + 7) & 63;
  table_2[s_idx_44_2] = (stage_v_44_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int s_idx_45_1 = stage_v_35_1 & 3;
  int s_idx_45_2 = stage_v_35_2 & 3;
  int stage_v_45_1 = (table_1[s_idx_45_1] + pub_r000229_6_1) & 127;
  int stage_v_45_2 = (table_2[s_idx_45_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_45_1] = (stage_v_45_1 + 7) & 63;
  table_2[s_idx_45_2] = (stage_v_45_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int s_idx_46_1 = sec_r000229_5_1 & 3;
  int s_idx_46_2 = sec_r000229_5_2 & 3;
  int stage_v_46_1 = (table_1[s_idx_46_1] + pub_r000229_6_1) & 127;
  int stage_v_46_2 = (table_2[s_idx_46_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_46_1] = (stage_v_46_1 + 7) & 63;
  table_2[s_idx_46_2] = (stage_v_46_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int s_idx_47_1 = stage_v_42_1 & 3;
  int s_idx_47_2 = stage_v_42_2 & 3;
  int stage_v_47_1 = (table_1[s_idx_47_1] + pub_r000229_19_1) & 127;
  int stage_v_47_2 = (table_2[s_idx_47_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_47_1] = (stage_v_47_1 + 7) & 63;
  table_2[s_idx_47_2] = (stage_v_47_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int s_idx_48_1 = stage_v_47_1 & 3;
  int s_idx_48_2 = stage_v_47_2 & 3;
  int stage_v_48_1 = (table_1[s_idx_48_1] + pub_r000229_6_1) & 127;
  int stage_v_48_2 = (table_2[s_idx_48_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_48_1] = (stage_v_48_1 + 7) & 63;
  table_2[s_idx_48_2] = (stage_v_48_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int s_idx_49_1 = stage_v_35_1 & 3;
  int s_idx_49_2 = stage_v_35_2 & 3;
  int stage_v_49_1 = (table_1[s_idx_49_1] + pub_r000229_10_1) & 127;
  int stage_v_49_2 = (table_2[s_idx_49_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_49_1] = (stage_v_49_1 + 7) & 63;
  table_2[s_idx_49_2] = (stage_v_49_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int s_idx_50_1 = stage_v_42_1 & 3;
  int s_idx_50_2 = stage_v_42_2 & 3;
  int stage_v_50_1 = (table_1[s_idx_50_1] + pub_r000229_15_1) & 127;
  int stage_v_50_2 = (table_2[s_idx_50_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_50_1] = (stage_v_50_1 + 7) & 63;
  table_2[s_idx_50_2] = (stage_v_50_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int s_idx_51_1 = sec_r000229_17_1 & 3;
  int s_idx_51_2 = sec_r000229_17_2 & 3;
  int stage_v_51_1 = (table_1[s_idx_51_1] + pub_r000229_14_1) & 127;
  int stage_v_51_2 = (table_2[s_idx_51_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_51_1] = (stage_v_51_1 + 7) & 63;
  table_2[s_idx_51_2] = (stage_v_51_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int s_idx_52_1 = sec_r000229_6_1 & 3;
  int s_idx_52_2 = sec_r000229_6_2 & 3;
  int stage_v_52_1 = (table_1[s_idx_52_1] + pub_r000229_11_1) & 127;
  int stage_v_52_2 = (table_2[s_idx_52_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_52_1] = (stage_v_52_1 + 7) & 63;
  table_2[s_idx_52_2] = (stage_v_52_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int s_idx_53_1 = stage_v_41_1 & 3;
  int s_idx_53_2 = stage_v_41_2 & 3;
  int stage_v_53_1 = (table_1[s_idx_53_1] + pub_r000229_22_1) & 127;
  int stage_v_53_2 = (table_2[s_idx_53_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_53_1] = (stage_v_53_1 + 7) & 63;
  table_2[s_idx_53_2] = (stage_v_53_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int s_idx_54_1 = stage_v_50_1 & 3;
  int s_idx_54_2 = stage_v_50_2 & 3;
  int stage_v_54_1 = (table_1[s_idx_54_1] + pub_r000229_21_1) & 127;
  int stage_v_54_2 = (table_2[s_idx_54_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_54_1] = (stage_v_54_1 + 7) & 63;
  table_2[s_idx_54_2] = (stage_v_54_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int s_idx_55_1 = stage_v_40_1 & 3;
  int s_idx_55_2 = stage_v_40_2 & 3;
  int stage_v_55_1 = (table_1[s_idx_55_1] + pub_r000229_16_1) & 127;
  int stage_v_55_2 = (table_2[s_idx_55_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_55_1] = (stage_v_55_1 + 7) & 63;
  table_2[s_idx_55_2] = (stage_v_55_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int s_idx_56_1 = sec_r000229_4_1 & 3;
  int s_idx_56_2 = sec_r000229_4_2 & 3;
  int stage_v_56_1 = (table_1[s_idx_56_1] + pub_r000229_16_1) & 127;
  int stage_v_56_2 = (table_2[s_idx_56_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_56_1] = (stage_v_56_1 + 7) & 63;
  table_2[s_idx_56_2] = (stage_v_56_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int s_idx_57_1 = stage_v_41_1 & 3;
  int s_idx_57_2 = stage_v_41_2 & 3;
  int stage_v_57_1 = (table_1[s_idx_57_1] + pub_r000229_11_1) & 127;
  int stage_v_57_2 = (table_2[s_idx_57_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_57_1] = (stage_v_57_1 + 7) & 63;
  table_2[s_idx_57_2] = (stage_v_57_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int s_idx_58_1 = stage_v_50_1 & 3;
  int s_idx_58_2 = stage_v_50_2 & 3;
  int stage_v_58_1 = (table_1[s_idx_58_1] + pub_r000229_5_1) & 127;
  int stage_v_58_2 = (table_2[s_idx_58_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_58_1] = (stage_v_58_1 + 7) & 63;
  table_2[s_idx_58_2] = (stage_v_58_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int s_idx_59_1 = stage_v_34_1 & 3;
  int s_idx_59_2 = stage_v_34_2 & 3;
  int stage_v_59_1 = (table_1[s_idx_59_1] + pub_r000229_16_1) & 127;
  int stage_v_59_2 = (table_2[s_idx_59_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_59_1] = (stage_v_59_1 + 7) & 63;
  table_2[s_idx_59_2] = (stage_v_59_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int s_idx_60_1 = stage_v_50_1 & 3;
  int s_idx_60_2 = stage_v_50_2 & 3;
  int stage_v_60_1 = (table_1[s_idx_60_1] + pub_r000229_14_1) & 127;
  int stage_v_60_2 = (table_2[s_idx_60_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_60_1] = (stage_v_60_1 + 7) & 63;
  table_2[s_idx_60_2] = (stage_v_60_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int s_idx_61_1 = stage_v_52_1 & 3;
  int s_idx_61_2 = stage_v_52_2 & 3;
  int stage_v_61_1 = (table_1[s_idx_61_1] + pub_r000229_16_1) & 127;
  int stage_v_61_2 = (table_2[s_idx_61_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_61_1] = (stage_v_61_1 + 7) & 63;
  table_2[s_idx_61_2] = (stage_v_61_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int s_idx_62_1 = stage_v_37_1 & 3;
  int s_idx_62_2 = stage_v_37_2 & 3;
  int stage_v_62_1 = (table_1[s_idx_62_1] + pub_r000229_7_1) & 127;
  int stage_v_62_2 = (table_2[s_idx_62_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_62_1] = (stage_v_62_1 + 7) & 63;
  table_2[s_idx_62_2] = (stage_v_62_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int s_idx_63_1 = sec_r000229_15_1 & 3;
  int s_idx_63_2 = sec_r000229_15_2 & 3;
  int stage_v_63_1 = (table_1[s_idx_63_1] + pub_r000229_9_1) & 127;
  int stage_v_63_2 = (table_2[s_idx_63_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_63_1] = (stage_v_63_1 + 7) & 63;
  table_2[s_idx_63_2] = (stage_v_63_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int s_idx_64_1 = stage_v_63_1 & 3;
  int s_idx_64_2 = stage_v_63_2 & 3;
  int stage_v_64_1 = (table_1[s_idx_64_1] + pub_r000229_16_1) & 127;
  int stage_v_64_2 = (table_2[s_idx_64_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_64_1] = (stage_v_64_1 + 7) & 63;
  table_2[s_idx_64_2] = (stage_v_64_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int s_idx_65_1 = stage_v_33_1 & 3;
  int s_idx_65_2 = stage_v_33_2 & 3;
  int stage_v_65_1 = (table_1[s_idx_65_1] + pub_r000229_0_1) & 127;
  int stage_v_65_2 = (table_2[s_idx_65_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_65_1] = (stage_v_65_1 + 7) & 63;
  table_2[s_idx_65_2] = (stage_v_65_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int s_idx_66_1 = stage_v_59_1 & 3;
  int s_idx_66_2 = stage_v_59_2 & 3;
  int stage_v_66_1 = (table_1[s_idx_66_1] + pub_r000229_15_1) & 127;
  int stage_v_66_2 = (table_2[s_idx_66_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_66_1] = (stage_v_66_1 + 7) & 63;
  table_2[s_idx_66_2] = (stage_v_66_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int s_idx_67_1 = stage_v_37_1 & 3;
  int s_idx_67_2 = stage_v_37_2 & 3;
  int stage_v_67_1 = (table_1[s_idx_67_1] + pub_r000229_22_1) & 127;
  int stage_v_67_2 = (table_2[s_idx_67_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_67_1] = (stage_v_67_1 + 7) & 63;
  table_2[s_idx_67_2] = (stage_v_67_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int s_idx_68_1 = sec_r000229_8_1 & 3;
  int s_idx_68_2 = sec_r000229_8_2 & 3;
  int stage_v_68_1 = (table_1[s_idx_68_1] + pub_r000229_17_1) & 127;
  int stage_v_68_2 = (table_2[s_idx_68_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_68_1] = (stage_v_68_1 + 7) & 63;
  table_2[s_idx_68_2] = (stage_v_68_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int s_idx_69_1 = stage_v_53_1 & 3;
  int s_idx_69_2 = stage_v_53_2 & 3;
  int stage_v_69_1 = (table_1[s_idx_69_1] + pub_r000229_11_1) & 127;
  int stage_v_69_2 = (table_2[s_idx_69_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_69_1] = (stage_v_69_1 + 7) & 63;
  table_2[s_idx_69_2] = (stage_v_69_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int s_idx_70_1 = stage_v_35_1 & 3;
  int s_idx_70_2 = stage_v_35_2 & 3;
  int stage_v_70_1 = (table_1[s_idx_70_1] + pub_r000229_5_1) & 127;
  int stage_v_70_2 = (table_2[s_idx_70_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_70_1] = (stage_v_70_1 + 7) & 63;
  table_2[s_idx_70_2] = (stage_v_70_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int s_idx_71_1 = sec_r000229_10_1 & 3;
  int s_idx_71_2 = sec_r000229_10_2 & 3;
  int stage_v_71_1 = (table_1[s_idx_71_1] + pub_r000229_2_1) & 127;
  int stage_v_71_2 = (table_2[s_idx_71_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_71_1] = (stage_v_71_1 + 7) & 63;
  table_2[s_idx_71_2] = (stage_v_71_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int s_idx_72_1 = stage_v_69_1 & 3;
  int s_idx_72_2 = stage_v_69_2 & 3;
  int stage_v_72_1 = (table_1[s_idx_72_1] + pub_r000229_0_1) & 127;
  int stage_v_72_2 = (table_2[s_idx_72_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_72_1] = (stage_v_72_1 + 7) & 63;
  table_2[s_idx_72_2] = (stage_v_72_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int s_idx_73_1 = sec_r000229_15_1 & 3;
  int s_idx_73_2 = sec_r000229_15_2 & 3;
  int stage_v_73_1 = (table_1[s_idx_73_1] + pub_r000229_14_1) & 127;
  int stage_v_73_2 = (table_2[s_idx_73_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_73_1] = (stage_v_73_1 + 7) & 63;
  table_2[s_idx_73_2] = (stage_v_73_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int s_idx_74_1 = stage_v_70_1 & 3;
  int s_idx_74_2 = stage_v_70_2 & 3;
  int stage_v_74_1 = (table_1[s_idx_74_1] + pub_r000229_9_1) & 127;
  int stage_v_74_2 = (table_2[s_idx_74_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_74_1] = (stage_v_74_1 + 7) & 63;
  table_2[s_idx_74_2] = (stage_v_74_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int s_idx_75_1 = sec_r000229_12_1 & 3;
  int s_idx_75_2 = sec_r000229_12_2 & 3;
  int stage_v_75_1 = (table_1[s_idx_75_1] + pub_r000229_1_1) & 127;
  int stage_v_75_2 = (table_2[s_idx_75_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_75_1] = (stage_v_75_1 + 7) & 63;
  table_2[s_idx_75_2] = (stage_v_75_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int s_idx_76_1 = stage_v_63_1 & 3;
  int s_idx_76_2 = stage_v_63_2 & 3;
  int stage_v_76_1 = (table_1[s_idx_76_1] + pub_r000229_13_1) & 127;
  int stage_v_76_2 = (table_2[s_idx_76_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_76_1] = (stage_v_76_1 + 7) & 63;
  table_2[s_idx_76_2] = (stage_v_76_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int s_idx_77_1 = stage_v_69_1 & 3;
  int s_idx_77_2 = stage_v_69_2 & 3;
  int stage_v_77_1 = (table_1[s_idx_77_1] + pub_r000229_6_1) & 127;
  int stage_v_77_2 = (table_2[s_idx_77_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_77_1] = (stage_v_77_1 + 7) & 63;
  table_2[s_idx_77_2] = (stage_v_77_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int s_idx_78_1 = sec_r000229_7_1 & 3;
  int s_idx_78_2 = sec_r000229_7_2 & 3;
  int stage_v_78_1 = (table_1[s_idx_78_1] + pub_r000229_3_1) & 127;
  int stage_v_78_2 = (table_2[s_idx_78_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_78_1] = (stage_v_78_1 + 7) & 63;
  table_2[s_idx_78_2] = (stage_v_78_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int s_idx_79_1 = sec_r000229_2_1 & 3;
  int s_idx_79_2 = sec_r000229_2_2 & 3;
  int stage_v_79_1 = (table_1[s_idx_79_1] + pub_r000229_6_1) & 127;
  int stage_v_79_2 = (table_2[s_idx_79_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_79_1] = (stage_v_79_1 + 7) & 63;
  table_2[s_idx_79_2] = (stage_v_79_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int s_idx_80_1 = sec_r000229_8_1 & 3;
  int s_idx_80_2 = sec_r000229_8_2 & 3;
  int stage_v_80_1 = (table_1[s_idx_80_1] + pub_r000229_21_1) & 127;
  int stage_v_80_2 = (table_2[s_idx_80_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_80_1] = (stage_v_80_1 + 7) & 63;
  table_2[s_idx_80_2] = (stage_v_80_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int s_idx_81_1 = sec_r000229_9_1 & 3;
  int s_idx_81_2 = sec_r000229_9_2 & 3;
  int stage_v_81_1 = (table_1[s_idx_81_1] + pub_r000229_1_1) & 127;
  int stage_v_81_2 = (table_2[s_idx_81_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_81_1] = (stage_v_81_1 + 7) & 63;
  table_2[s_idx_81_2] = (stage_v_81_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int s_idx_82_1 = sec_r000229_4_1 & 3;
  int s_idx_82_2 = sec_r000229_4_2 & 3;
  int stage_v_82_1 = (table_1[s_idx_82_1] + pub_r000229_15_1) & 127;
  int stage_v_82_2 = (table_2[s_idx_82_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_82_1] = (stage_v_82_1 + 7) & 63;
  table_2[s_idx_82_2] = (stage_v_82_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int s_idx_83_1 = stage_v_62_1 & 3;
  int s_idx_83_2 = stage_v_62_2 & 3;
  int stage_v_83_1 = (table_1[s_idx_83_1] + pub_r000229_17_1) & 127;
  int stage_v_83_2 = (table_2[s_idx_83_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_83_1] = (stage_v_83_1 + 7) & 63;
  table_2[s_idx_83_2] = (stage_v_83_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int s_idx_84_1 = sec_r000229_6_1 & 3;
  int s_idx_84_2 = sec_r000229_6_2 & 3;
  int stage_v_84_1 = (table_1[s_idx_84_1] + pub_r000229_0_1) & 127;
  int stage_v_84_2 = (table_2[s_idx_84_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_84_1] = (stage_v_84_1 + 7) & 63;
  table_2[s_idx_84_2] = (stage_v_84_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int s_idx_85_1 = stage_v_52_1 & 3;
  int s_idx_85_2 = stage_v_52_2 & 3;
  int stage_v_85_1 = (table_1[s_idx_85_1] + pub_r000229_20_1) & 127;
  int stage_v_85_2 = (table_2[s_idx_85_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_85_1] = (stage_v_85_1 + 7) & 63;
  table_2[s_idx_85_2] = (stage_v_85_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int s_idx_86_1 = stage_v_75_1 & 3;
  int s_idx_86_2 = stage_v_75_2 & 3;
  int stage_v_86_1 = (table_1[s_idx_86_1] + pub_r000229_8_1) & 127;
  int stage_v_86_2 = (table_2[s_idx_86_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_86_1] = (stage_v_86_1 + 7) & 63;
  table_2[s_idx_86_2] = (stage_v_86_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int s_idx_87_1 = stage_v_65_1 & 3;
  int s_idx_87_2 = stage_v_65_2 & 3;
  int stage_v_87_1 = (table_1[s_idx_87_1] + pub_r000229_11_1) & 127;
  int stage_v_87_2 = (table_2[s_idx_87_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_87_1] = (stage_v_87_1 + 7) & 63;
  table_2[s_idx_87_2] = (stage_v_87_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int s_idx_88_1 = sec_r000229_23_1 & 3;
  int s_idx_88_2 = sec_r000229_23_2 & 3;
  int stage_v_88_1 = (table_1[s_idx_88_1] + pub_r000229_22_1) & 127;
  int stage_v_88_2 = (table_2[s_idx_88_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_88_1] = (stage_v_88_1 + 7) & 63;
  table_2[s_idx_88_2] = (stage_v_88_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int s_idx_89_1 = stage_v_64_1 & 3;
  int s_idx_89_2 = stage_v_64_2 & 3;
  int stage_v_89_1 = (table_1[s_idx_89_1] + pub_r000229_0_1) & 127;
  int stage_v_89_2 = (table_2[s_idx_89_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_89_1] = (stage_v_89_1 + 7) & 63;
  table_2[s_idx_89_2] = (stage_v_89_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int s_idx_90_1 = stage_v_42_1 & 3;
  int s_idx_90_2 = stage_v_42_2 & 3;
  int stage_v_90_1 = (table_1[s_idx_90_1] + pub_r000229_18_1) & 127;
  int stage_v_90_2 = (table_2[s_idx_90_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_90_1] = (stage_v_90_1 + 7) & 63;
  table_2[s_idx_90_2] = (stage_v_90_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int s_idx_91_1 = stage_v_64_1 & 3;
  int s_idx_91_2 = stage_v_64_2 & 3;
  int stage_v_91_1 = (table_1[s_idx_91_1] + pub_r000229_9_1) & 127;
  int stage_v_91_2 = (table_2[s_idx_91_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_91_1] = (stage_v_91_1 + 7) & 63;
  table_2[s_idx_91_2] = (stage_v_91_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int s_idx_92_1 = stage_v_56_1 & 3;
  int s_idx_92_2 = stage_v_56_2 & 3;
  int stage_v_92_1 = (table_1[s_idx_92_1] + pub_r000229_21_1) & 127;
  int stage_v_92_2 = (table_2[s_idx_92_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_92_1] = (stage_v_92_1 + 7) & 63;
  table_2[s_idx_92_2] = (stage_v_92_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int s_idx_93_1 = stage_v_47_1 & 3;
  int s_idx_93_2 = stage_v_47_2 & 3;
  int stage_v_93_1 = (table_1[s_idx_93_1] + pub_r000229_4_1) & 127;
  int stage_v_93_2 = (table_2[s_idx_93_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_93_1] = (stage_v_93_1 + 7) & 63;
  table_2[s_idx_93_2] = (stage_v_93_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int s_idx_94_1 = sec_r000229_10_1 & 3;
  int s_idx_94_2 = sec_r000229_10_2 & 3;
  int stage_v_94_1 = (table_1[s_idx_94_1] + pub_r000229_19_1) & 127;
  int stage_v_94_2 = (table_2[s_idx_94_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_94_1] = (stage_v_94_1 + 7) & 63;
  table_2[s_idx_94_2] = (stage_v_94_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int s_idx_95_1 = sec_r000229_3_1 & 3;
  int s_idx_95_2 = sec_r000229_3_2 & 3;
  int stage_v_95_1 = (table_1[s_idx_95_1] + pub_r000229_9_1) & 127;
  int stage_v_95_2 = (table_2[s_idx_95_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_95_1] = (stage_v_95_1 + 7) & 63;
  table_2[s_idx_95_2] = (stage_v_95_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int s_idx_96_1 = sec_r000229_11_1 & 3;
  int s_idx_96_2 = sec_r000229_11_2 & 3;
  int stage_v_96_1 = (table_1[s_idx_96_1] + pub_r000229_11_1) & 127;
  int stage_v_96_2 = (table_2[s_idx_96_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_96_1] = (stage_v_96_1 + 7) & 63;
  table_2[s_idx_96_2] = (stage_v_96_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int s_idx_97_1 = stage_v_72_1 & 3;
  int s_idx_97_2 = stage_v_72_2 & 3;
  int stage_v_97_1 = (table_1[s_idx_97_1] + pub_r000229_0_1) & 127;
  int stage_v_97_2 = (table_2[s_idx_97_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_97_1] = (stage_v_97_1 + 7) & 63;
  table_2[s_idx_97_2] = (stage_v_97_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int s_idx_98_1 = sec_r000229_9_1 & 3;
  int s_idx_98_2 = sec_r000229_9_2 & 3;
  int stage_v_98_1 = (table_1[s_idx_98_1] + pub_r000229_22_1) & 127;
  int stage_v_98_2 = (table_2[s_idx_98_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_98_1] = (stage_v_98_1 + 7) & 63;
  table_2[s_idx_98_2] = (stage_v_98_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int s_idx_99_1 = sec_r000229_16_1 & 3;
  int s_idx_99_2 = sec_r000229_16_2 & 3;
  int stage_v_99_1 = (table_1[s_idx_99_1] + pub_r000229_0_1) & 127;
  int stage_v_99_2 = (table_2[s_idx_99_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_99_1] = (stage_v_99_1 + 7) & 63;
  table_2[s_idx_99_2] = (stage_v_99_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int s_idx_100_1 = stage_v_71_1 & 3;
  int s_idx_100_2 = stage_v_71_2 & 3;
  int stage_v_100_1 = (table_1[s_idx_100_1] + pub_r000229_16_1) & 127;
  int stage_v_100_2 = (table_2[s_idx_100_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_100_1] = (stage_v_100_1 + 7) & 63;
  table_2[s_idx_100_2] = (stage_v_100_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int s_idx_101_1 = stage_v_54_1 & 3;
  int s_idx_101_2 = stage_v_54_2 & 3;
  int stage_v_101_1 = (table_1[s_idx_101_1] + pub_r000229_2_1) & 127;
  int stage_v_101_2 = (table_2[s_idx_101_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_101_1] = (stage_v_101_1 + 7) & 63;
  table_2[s_idx_101_2] = (stage_v_101_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int s_idx_102_1 = stage_v_85_1 & 3;
  int s_idx_102_2 = stage_v_85_2 & 3;
  int stage_v_102_1 = (table_1[s_idx_102_1] + pub_r000229_17_1) & 127;
  int stage_v_102_2 = (table_2[s_idx_102_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_102_1] = (stage_v_102_1 + 7) & 63;
  table_2[s_idx_102_2] = (stage_v_102_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int s_idx_103_1 = stage_v_55_1 & 3;
  int s_idx_103_2 = stage_v_55_2 & 3;
  int stage_v_103_1 = (table_1[s_idx_103_1] + pub_r000229_9_1) & 127;
  int stage_v_103_2 = (table_2[s_idx_103_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_103_1] = (stage_v_103_1 + 7) & 63;
  table_2[s_idx_103_2] = (stage_v_103_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int s_idx_104_1 = stage_v_75_1 & 3;
  int s_idx_104_2 = stage_v_75_2 & 3;
  int stage_v_104_1 = (table_1[s_idx_104_1] + pub_r000229_8_1) & 127;
  int stage_v_104_2 = (table_2[s_idx_104_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_104_1] = (stage_v_104_1 + 7) & 63;
  table_2[s_idx_104_2] = (stage_v_104_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int s_idx_105_1 = sec_r000229_5_1 & 3;
  int s_idx_105_2 = sec_r000229_5_2 & 3;
  int stage_v_105_1 = (table_1[s_idx_105_1] + pub_r000229_0_1) & 127;
  int stage_v_105_2 = (table_2[s_idx_105_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_105_1] = (stage_v_105_1 + 7) & 63;
  table_2[s_idx_105_2] = (stage_v_105_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int s_idx_106_1 = stage_v_93_1 & 3;
  int s_idx_106_2 = stage_v_93_2 & 3;
  int stage_v_106_1 = (table_1[s_idx_106_1] + pub_r000229_22_1) & 127;
  int stage_v_106_2 = (table_2[s_idx_106_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_106_1] = (stage_v_106_1 + 7) & 63;
  table_2[s_idx_106_2] = (stage_v_106_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int s_idx_107_1 = stage_v_77_1 & 3;
  int s_idx_107_2 = stage_v_77_2 & 3;
  int stage_v_107_1 = (table_1[s_idx_107_1] + pub_r000229_22_1) & 127;
  int stage_v_107_2 = (table_2[s_idx_107_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_107_1] = (stage_v_107_1 + 7) & 63;
  table_2[s_idx_107_2] = (stage_v_107_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int s_idx_108_1 = stage_v_54_1 & 3;
  int s_idx_108_2 = stage_v_54_2 & 3;
  int stage_v_108_1 = (table_1[s_idx_108_1] + pub_r000229_8_1) & 127;
  int stage_v_108_2 = (table_2[s_idx_108_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_108_1] = (stage_v_108_1 + 7) & 63;
  table_2[s_idx_108_2] = (stage_v_108_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int s_idx_109_1 = stage_v_96_1 & 3;
  int s_idx_109_2 = stage_v_96_2 & 3;
  int stage_v_109_1 = (table_1[s_idx_109_1] + pub_r000229_4_1) & 127;
  int stage_v_109_2 = (table_2[s_idx_109_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_109_1] = (stage_v_109_1 + 7) & 63;
  table_2[s_idx_109_2] = (stage_v_109_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int s_idx_110_1 = sec_r000229_12_1 & 3;
  int s_idx_110_2 = sec_r000229_12_2 & 3;
  int stage_v_110_1 = (table_1[s_idx_110_1] + pub_r000229_20_1) & 127;
  int stage_v_110_2 = (table_2[s_idx_110_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_110_1] = (stage_v_110_1 + 7) & 63;
  table_2[s_idx_110_2] = (stage_v_110_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int s_idx_111_1 = stage_v_34_1 & 3;
  int s_idx_111_2 = stage_v_34_2 & 3;
  int stage_v_111_1 = (table_1[s_idx_111_1] + pub_r000229_18_1) & 127;
  int stage_v_111_2 = (table_2[s_idx_111_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_111_1] = (stage_v_111_1 + 7) & 63;
  table_2[s_idx_111_2] = (stage_v_111_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int s_idx_112_1 = stage_v_105_1 & 3;
  int s_idx_112_2 = stage_v_105_2 & 3;
  int stage_v_112_1 = (table_1[s_idx_112_1] + pub_r000229_21_1) & 127;
  int stage_v_112_2 = (table_2[s_idx_112_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_112_1] = (stage_v_112_1 + 7) & 63;
  table_2[s_idx_112_2] = (stage_v_112_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int s_idx_113_1 = stage_v_90_1 & 3;
  int s_idx_113_2 = stage_v_90_2 & 3;
  int stage_v_113_1 = (table_1[s_idx_113_1] + pub_r000229_20_1) & 127;
  int stage_v_113_2 = (table_2[s_idx_113_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_113_1] = (stage_v_113_1 + 7) & 63;
  table_2[s_idx_113_2] = (stage_v_113_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int s_idx_114_1 = sec_r000229_21_1 & 3;
  int s_idx_114_2 = sec_r000229_21_2 & 3;
  int stage_v_114_1 = (table_1[s_idx_114_1] + pub_r000229_1_1) & 127;
  int stage_v_114_2 = (table_2[s_idx_114_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_114_1] = (stage_v_114_1 + 7) & 63;
  table_2[s_idx_114_2] = (stage_v_114_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int s_idx_115_1 = sec_r000229_6_1 & 3;
  int s_idx_115_2 = sec_r000229_6_2 & 3;
  int stage_v_115_1 = (table_1[s_idx_115_1] + pub_r000229_18_1) & 127;
  int stage_v_115_2 = (table_2[s_idx_115_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_115_1] = (stage_v_115_1 + 7) & 63;
  table_2[s_idx_115_2] = (stage_v_115_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int s_idx_116_1 = stage_v_108_1 & 3;
  int s_idx_116_2 = stage_v_108_2 & 3;
  int stage_v_116_1 = (table_1[s_idx_116_1] + pub_r000229_19_1) & 127;
  int stage_v_116_2 = (table_2[s_idx_116_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_116_1] = (stage_v_116_1 + 7) & 63;
  table_2[s_idx_116_2] = (stage_v_116_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int s_idx_117_1 = stage_v_78_1 & 3;
  int s_idx_117_2 = stage_v_78_2 & 3;
  int stage_v_117_1 = (table_1[s_idx_117_1] + pub_r000229_22_1) & 127;
  int stage_v_117_2 = (table_2[s_idx_117_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_117_1] = (stage_v_117_1 + 7) & 63;
  table_2[s_idx_117_2] = (stage_v_117_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int s_idx_118_1 = sec_r000229_22_1 & 3;
  int s_idx_118_2 = sec_r000229_22_2 & 3;
  int stage_v_118_1 = (table_1[s_idx_118_1] + pub_r000229_5_1) & 127;
  int stage_v_118_2 = (table_2[s_idx_118_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_118_1] = (stage_v_118_1 + 7) & 63;
  table_2[s_idx_118_2] = (stage_v_118_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int s_idx_119_1 = stage_v_114_1 & 3;
  int s_idx_119_2 = stage_v_114_2 & 3;
  int stage_v_119_1 = (table_1[s_idx_119_1] + pub_r000229_14_1) & 127;
  int stage_v_119_2 = (table_2[s_idx_119_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_119_1] = (stage_v_119_1 + 7) & 63;
  table_2[s_idx_119_2] = (stage_v_119_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int s_idx_120_1 = stage_v_36_1 & 3;
  int s_idx_120_2 = stage_v_36_2 & 3;
  int stage_v_120_1 = (table_1[s_idx_120_1] + pub_r000229_18_1) & 127;
  int stage_v_120_2 = (table_2[s_idx_120_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_120_1] = (stage_v_120_1 + 7) & 63;
  table_2[s_idx_120_2] = (stage_v_120_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int s_idx_121_1 = sec_r000229_20_1 & 3;
  int s_idx_121_2 = sec_r000229_20_2 & 3;
  int stage_v_121_1 = (table_1[s_idx_121_1] + pub_r000229_22_1) & 127;
  int stage_v_121_2 = (table_2[s_idx_121_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_121_1] = (stage_v_121_1 + 7) & 63;
  table_2[s_idx_121_2] = (stage_v_121_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int s_idx_122_1 = stage_v_97_1 & 3;
  int s_idx_122_2 = stage_v_97_2 & 3;
  int stage_v_122_1 = (table_1[s_idx_122_1] + pub_r000229_3_1) & 127;
  int stage_v_122_2 = (table_2[s_idx_122_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_122_1] = (stage_v_122_1 + 7) & 63;
  table_2[s_idx_122_2] = (stage_v_122_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int s_idx_123_1 = sec_r000229_1_1 & 3;
  int s_idx_123_2 = sec_r000229_1_2 & 3;
  int stage_v_123_1 = (table_1[s_idx_123_1] + pub_r000229_7_1) & 127;
  int stage_v_123_2 = (table_2[s_idx_123_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_123_1] = (stage_v_123_1 + 7) & 63;
  table_2[s_idx_123_2] = (stage_v_123_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int s_idx_124_1 = stage_v_43_1 & 3;
  int s_idx_124_2 = stage_v_43_2 & 3;
  int stage_v_124_1 = (table_1[s_idx_124_1] + pub_r000229_14_1) & 127;
  int stage_v_124_2 = (table_2[s_idx_124_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_124_1] = (stage_v_124_1 + 7) & 63;
  table_2[s_idx_124_2] = (stage_v_124_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int s_idx_125_1 = stage_v_99_1 & 3;
  int s_idx_125_2 = stage_v_99_2 & 3;
  int stage_v_125_1 = (table_1[s_idx_125_1] + pub_r000229_4_1) & 127;
  int stage_v_125_2 = (table_2[s_idx_125_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_125_1] = (stage_v_125_1 + 7) & 63;
  table_2[s_idx_125_2] = (stage_v_125_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int s_idx_126_1 = sec_r000229_2_1 & 3;
  int s_idx_126_2 = sec_r000229_2_2 & 3;
  int stage_v_126_1 = (table_1[s_idx_126_1] + pub_r000229_20_1) & 127;
  int stage_v_126_2 = (table_2[s_idx_126_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_126_1] = (stage_v_126_1 + 7) & 63;
  table_2[s_idx_126_2] = (stage_v_126_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_126_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_126_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int s_idx_127_1 = stage_v_122_1 & 3;
  int s_idx_127_2 = stage_v_122_2 & 3;
  int stage_v_127_1 = (table_1[s_idx_127_1] + pub_r000229_12_1) & 127;
  int stage_v_127_2 = (table_2[s_idx_127_2] + pub_r000229_12_2) & 127;
  table_1[s_idx_127_1] = (stage_v_127_1 + 7) & 63;
  table_2[s_idx_127_2] = (stage_v_127_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_127_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_127_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int s_idx_128_1 = stage_v_39_1 & 3;
  int s_idx_128_2 = stage_v_39_2 & 3;
  int stage_v_128_1 = (table_1[s_idx_128_1] + pub_r000229_0_1) & 127;
  int stage_v_128_2 = (table_2[s_idx_128_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_128_1] = (stage_v_128_1 + 7) & 63;
  table_2[s_idx_128_2] = (stage_v_128_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_128_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_128_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int s_idx_129_1 = stage_v_85_1 & 3;
  int s_idx_129_2 = stage_v_85_2 & 3;
  int stage_v_129_1 = (table_1[s_idx_129_1] + pub_r000229_14_1) & 127;
  int stage_v_129_2 = (table_2[s_idx_129_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_129_1] = (stage_v_129_1 + 7) & 63;
  table_2[s_idx_129_2] = (stage_v_129_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_129_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_129_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int s_idx_130_1 = sec_r000229_2_1 & 3;
  int s_idx_130_2 = sec_r000229_2_2 & 3;
  int stage_v_130_1 = (table_1[s_idx_130_1] + pub_r000229_3_1) & 127;
  int stage_v_130_2 = (table_2[s_idx_130_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_130_1] = (stage_v_130_1 + 7) & 63;
  table_2[s_idx_130_2] = (stage_v_130_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_130_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_130_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int s_idx_131_1 = sec_r000229_7_1 & 3;
  int s_idx_131_2 = sec_r000229_7_2 & 3;
  int stage_v_131_1 = (table_1[s_idx_131_1] + pub_r000229_5_1) & 127;
  int stage_v_131_2 = (table_2[s_idx_131_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_131_1] = (stage_v_131_1 + 7) & 63;
  table_2[s_idx_131_2] = (stage_v_131_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_131_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_131_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int s_idx_132_1 = stage_v_44_1 & 3;
  int s_idx_132_2 = stage_v_44_2 & 3;
  int stage_v_132_1 = (table_1[s_idx_132_1] + pub_r000229_8_1) & 127;
  int stage_v_132_2 = (table_2[s_idx_132_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_132_1] = (stage_v_132_1 + 7) & 63;
  table_2[s_idx_132_2] = (stage_v_132_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_132_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_132_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int s_idx_133_1 = stage_v_73_1 & 3;
  int s_idx_133_2 = stage_v_73_2 & 3;
  int stage_v_133_1 = (table_1[s_idx_133_1] + pub_r000229_0_1) & 127;
  int stage_v_133_2 = (table_2[s_idx_133_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_133_1] = (stage_v_133_1 + 7) & 63;
  table_2[s_idx_133_2] = (stage_v_133_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_133_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_133_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int s_idx_134_1 = stage_v_125_1 & 3;
  int s_idx_134_2 = stage_v_125_2 & 3;
  int stage_v_134_1 = (table_1[s_idx_134_1] + pub_r000229_11_1) & 127;
  int stage_v_134_2 = (table_2[s_idx_134_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_134_1] = (stage_v_134_1 + 7) & 63;
  table_2[s_idx_134_2] = (stage_v_134_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_134_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_134_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int s_idx_135_1 = stage_v_58_1 & 3;
  int s_idx_135_2 = stage_v_58_2 & 3;
  int stage_v_135_1 = (table_1[s_idx_135_1] + pub_r000229_17_1) & 127;
  int stage_v_135_2 = (table_2[s_idx_135_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_135_1] = (stage_v_135_1 + 7) & 63;
  table_2[s_idx_135_2] = (stage_v_135_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_135_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_135_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int s_idx_136_1 = sec_r000229_10_1 & 3;
  int s_idx_136_2 = sec_r000229_10_2 & 3;
  int stage_v_136_1 = (table_1[s_idx_136_1] + pub_r000229_14_1) & 127;
  int stage_v_136_2 = (table_2[s_idx_136_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_136_1] = (stage_v_136_1 + 7) & 63;
  table_2[s_idx_136_2] = (stage_v_136_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_136_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_136_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int s_idx_137_1 = stage_v_53_1 & 3;
  int s_idx_137_2 = stage_v_53_2 & 3;
  int stage_v_137_1 = (table_1[s_idx_137_1] + pub_r000229_15_1) & 127;
  int stage_v_137_2 = (table_2[s_idx_137_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_137_1] = (stage_v_137_1 + 7) & 63;
  table_2[s_idx_137_2] = (stage_v_137_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_137_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_137_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int s_idx_138_1 = stage_v_127_1 & 3;
  int s_idx_138_2 = stage_v_127_2 & 3;
  int stage_v_138_1 = (table_1[s_idx_138_1] + pub_r000229_2_1) & 127;
  int stage_v_138_2 = (table_2[s_idx_138_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_138_1] = (stage_v_138_1 + 7) & 63;
  table_2[s_idx_138_2] = (stage_v_138_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_138_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_138_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int s_idx_139_1 = stage_v_47_1 & 3;
  int s_idx_139_2 = stage_v_47_2 & 3;
  int stage_v_139_1 = (table_1[s_idx_139_1] + pub_r000229_3_1) & 127;
  int stage_v_139_2 = (table_2[s_idx_139_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_139_1] = (stage_v_139_1 + 7) & 63;
  table_2[s_idx_139_2] = (stage_v_139_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_139_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_139_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int s_idx_140_1 = stage_v_46_1 & 3;
  int s_idx_140_2 = stage_v_46_2 & 3;
  int stage_v_140_1 = (table_1[s_idx_140_1] + pub_r000229_18_1) & 127;
  int stage_v_140_2 = (table_2[s_idx_140_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_140_1] = (stage_v_140_1 + 7) & 63;
  table_2[s_idx_140_2] = (stage_v_140_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_140_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_140_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int s_idx_141_1 = stage_v_99_1 & 3;
  int s_idx_141_2 = stage_v_99_2 & 3;
  int stage_v_141_1 = (table_1[s_idx_141_1] + pub_r000229_21_1) & 127;
  int stage_v_141_2 = (table_2[s_idx_141_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_141_1] = (stage_v_141_1 + 7) & 63;
  table_2[s_idx_141_2] = (stage_v_141_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_141_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_141_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int s_idx_142_1 = sec_r000229_21_1 & 3;
  int s_idx_142_2 = sec_r000229_21_2 & 3;
  int stage_v_142_1 = (table_1[s_idx_142_1] + pub_r000229_22_1) & 127;
  int stage_v_142_2 = (table_2[s_idx_142_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_142_1] = (stage_v_142_1 + 7) & 63;
  table_2[s_idx_142_2] = (stage_v_142_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_142_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_142_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int s_idx_143_1 = stage_v_133_1 & 3;
  int s_idx_143_2 = stage_v_133_2 & 3;
  int stage_v_143_1 = (table_1[s_idx_143_1] + pub_r000229_16_1) & 127;
  int stage_v_143_2 = (table_2[s_idx_143_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_143_1] = (stage_v_143_1 + 7) & 63;
  table_2[s_idx_143_2] = (stage_v_143_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_143_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_143_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int s_idx_144_1 = sec_r000229_20_1 & 3;
  int s_idx_144_2 = sec_r000229_20_2 & 3;
  int stage_v_144_1 = (table_1[s_idx_144_1] + pub_r000229_5_1) & 127;
  int stage_v_144_2 = (table_2[s_idx_144_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_144_1] = (stage_v_144_1 + 7) & 63;
  table_2[s_idx_144_2] = (stage_v_144_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_144_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_144_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int s_idx_145_1 = sec_r000229_8_1 & 3;
  int s_idx_145_2 = sec_r000229_8_2 & 3;
  int stage_v_145_1 = (table_1[s_idx_145_1] + pub_r000229_5_1) & 127;
  int stage_v_145_2 = (table_2[s_idx_145_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_145_1] = (stage_v_145_1 + 7) & 63;
  table_2[s_idx_145_2] = (stage_v_145_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_145_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_145_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int s_idx_146_1 = sec_r000229_11_1 & 3;
  int s_idx_146_2 = sec_r000229_11_2 & 3;
  int stage_v_146_1 = (table_1[s_idx_146_1] + pub_r000229_8_1) & 127;
  int stage_v_146_2 = (table_2[s_idx_146_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_146_1] = (stage_v_146_1 + 7) & 63;
  table_2[s_idx_146_2] = (stage_v_146_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_146_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_146_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int s_idx_147_1 = stage_v_47_1 & 3;
  int s_idx_147_2 = stage_v_47_2 & 3;
  int stage_v_147_1 = (table_1[s_idx_147_1] + pub_r000229_6_1) & 127;
  int stage_v_147_2 = (table_2[s_idx_147_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_147_1] = (stage_v_147_1 + 7) & 63;
  table_2[s_idx_147_2] = (stage_v_147_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_147_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_147_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int s_idx_148_1 = stage_v_101_1 & 3;
  int s_idx_148_2 = stage_v_101_2 & 3;
  int stage_v_148_1 = (table_1[s_idx_148_1] + pub_r000229_10_1) & 127;
  int stage_v_148_2 = (table_2[s_idx_148_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_148_1] = (stage_v_148_1 + 7) & 63;
  table_2[s_idx_148_2] = (stage_v_148_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_148_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_148_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int s_idx_149_1 = sec_r000229_4_1 & 3;
  int s_idx_149_2 = sec_r000229_4_2 & 3;
  int stage_v_149_1 = (table_1[s_idx_149_1] + pub_r000229_7_1) & 127;
  int stage_v_149_2 = (table_2[s_idx_149_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_149_1] = (stage_v_149_1 + 7) & 63;
  table_2[s_idx_149_2] = (stage_v_149_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_149_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_149_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int s_idx_150_1 = sec_r000229_5_1 & 3;
  int s_idx_150_2 = sec_r000229_5_2 & 3;
  int stage_v_150_1 = (table_1[s_idx_150_1] + pub_r000229_11_1) & 127;
  int stage_v_150_2 = (table_2[s_idx_150_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_150_1] = (stage_v_150_1 + 7) & 63;
  table_2[s_idx_150_2] = (stage_v_150_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_150_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_150_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int s_idx_151_1 = stage_v_51_1 & 3;
  int s_idx_151_2 = stage_v_51_2 & 3;
  int stage_v_151_1 = (table_1[s_idx_151_1] + pub_r000229_19_1) & 127;
  int stage_v_151_2 = (table_2[s_idx_151_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_151_1] = (stage_v_151_1 + 7) & 63;
  table_2[s_idx_151_2] = (stage_v_151_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_151_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_151_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int s_idx_152_1 = stage_v_94_1 & 3;
  int s_idx_152_2 = stage_v_94_2 & 3;
  int stage_v_152_1 = (table_1[s_idx_152_1] + pub_r000229_6_1) & 127;
  int stage_v_152_2 = (table_2[s_idx_152_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_152_1] = (stage_v_152_1 + 7) & 63;
  table_2[s_idx_152_2] = (stage_v_152_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_152_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_152_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int s_idx_153_1 = stage_v_78_1 & 3;
  int s_idx_153_2 = stage_v_78_2 & 3;
  int stage_v_153_1 = (table_1[s_idx_153_1] + pub_r000229_0_1) & 127;
  int stage_v_153_2 = (table_2[s_idx_153_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_153_1] = (stage_v_153_1 + 7) & 63;
  table_2[s_idx_153_2] = (stage_v_153_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_153_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_153_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int s_idx_154_1 = sec_r000229_16_1 & 3;
  int s_idx_154_2 = sec_r000229_16_2 & 3;
  int stage_v_154_1 = (table_1[s_idx_154_1] + pub_r000229_11_1) & 127;
  int stage_v_154_2 = (table_2[s_idx_154_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_154_1] = (stage_v_154_1 + 7) & 63;
  table_2[s_idx_154_2] = (stage_v_154_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_154_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_154_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int s_idx_155_1 = sec_r000229_18_1 & 3;
  int s_idx_155_2 = sec_r000229_18_2 & 3;
  int stage_v_155_1 = (table_1[s_idx_155_1] + pub_r000229_10_1) & 127;
  int stage_v_155_2 = (table_2[s_idx_155_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_155_1] = (stage_v_155_1 + 7) & 63;
  table_2[s_idx_155_2] = (stage_v_155_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_155_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_155_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int s_idx_156_1 = sec_r000229_18_1 & 3;
  int s_idx_156_2 = sec_r000229_18_2 & 3;
  int stage_v_156_1 = (table_1[s_idx_156_1] + pub_r000229_3_1) & 127;
  int stage_v_156_2 = (table_2[s_idx_156_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_156_1] = (stage_v_156_1 + 7) & 63;
  table_2[s_idx_156_2] = (stage_v_156_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_156_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_156_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int s_idx_157_1 = stage_v_97_1 & 3;
  int s_idx_157_2 = stage_v_97_2 & 3;
  int stage_v_157_1 = (table_1[s_idx_157_1] + pub_r000229_10_1) & 127;
  int stage_v_157_2 = (table_2[s_idx_157_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_157_1] = (stage_v_157_1 + 7) & 63;
  table_2[s_idx_157_2] = (stage_v_157_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_157_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_157_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int s_idx_158_1 = sec_r000229_6_1 & 3;
  int s_idx_158_2 = sec_r000229_6_2 & 3;
  int stage_v_158_1 = (table_1[s_idx_158_1] + pub_r000229_16_1) & 127;
  int stage_v_158_2 = (table_2[s_idx_158_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_158_1] = (stage_v_158_1 + 7) & 63;
  table_2[s_idx_158_2] = (stage_v_158_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_158_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_158_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int s_idx_159_1 = sec_r000229_1_1 & 3;
  int s_idx_159_2 = sec_r000229_1_2 & 3;
  int stage_v_159_1 = (table_1[s_idx_159_1] + pub_r000229_9_1) & 127;
  int stage_v_159_2 = (table_2[s_idx_159_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_159_1] = (stage_v_159_1 + 7) & 63;
  table_2[s_idx_159_2] = (stage_v_159_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_159_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_159_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int s_idx_160_1 = sec_r000229_17_1 & 3;
  int s_idx_160_2 = sec_r000229_17_2 & 3;
  int stage_v_160_1 = (table_1[s_idx_160_1] + pub_r000229_22_1) & 127;
  int stage_v_160_2 = (table_2[s_idx_160_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_160_1] = (stage_v_160_1 + 7) & 63;
  table_2[s_idx_160_2] = (stage_v_160_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_160_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_160_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int s_idx_161_1 = stage_v_107_1 & 3;
  int s_idx_161_2 = stage_v_107_2 & 3;
  int stage_v_161_1 = (table_1[s_idx_161_1] + pub_r000229_3_1) & 127;
  int stage_v_161_2 = (table_2[s_idx_161_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_161_1] = (stage_v_161_1 + 7) & 63;
  table_2[s_idx_161_2] = (stage_v_161_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_161_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_161_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int s_idx_162_1 = sec_r000229_7_1 & 3;
  int s_idx_162_2 = sec_r000229_7_2 & 3;
  int stage_v_162_1 = (table_1[s_idx_162_1] + pub_r000229_4_1) & 127;
  int stage_v_162_2 = (table_2[s_idx_162_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_162_1] = (stage_v_162_1 + 7) & 63;
  table_2[s_idx_162_2] = (stage_v_162_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_162_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_162_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int s_idx_163_1 = stage_v_63_1 & 3;
  int s_idx_163_2 = stage_v_63_2 & 3;
  int stage_v_163_1 = (table_1[s_idx_163_1] + pub_r000229_16_1) & 127;
  int stage_v_163_2 = (table_2[s_idx_163_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_163_1] = (stage_v_163_1 + 7) & 63;
  table_2[s_idx_163_2] = (stage_v_163_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_163_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_163_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int s_idx_164_1 = stage_v_81_1 & 3;
  int s_idx_164_2 = stage_v_81_2 & 3;
  int stage_v_164_1 = (table_1[s_idx_164_1] + pub_r000229_0_1) & 127;
  int stage_v_164_2 = (table_2[s_idx_164_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_164_1] = (stage_v_164_1 + 7) & 63;
  table_2[s_idx_164_2] = (stage_v_164_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_164_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_164_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int s_idx_165_1 = stage_v_142_1 & 3;
  int s_idx_165_2 = stage_v_142_2 & 3;
  int stage_v_165_1 = (table_1[s_idx_165_1] + pub_r000229_15_1) & 127;
  int stage_v_165_2 = (table_2[s_idx_165_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_165_1] = (stage_v_165_1 + 7) & 63;
  table_2[s_idx_165_2] = (stage_v_165_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_165_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_165_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int s_idx_166_1 = stage_v_106_1 & 3;
  int s_idx_166_2 = stage_v_106_2 & 3;
  int stage_v_166_1 = (table_1[s_idx_166_1] + pub_r000229_0_1) & 127;
  int stage_v_166_2 = (table_2[s_idx_166_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_166_1] = (stage_v_166_1 + 7) & 63;
  table_2[s_idx_166_2] = (stage_v_166_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_166_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_166_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int s_idx_167_1 = sec_r000229_10_1 & 3;
  int s_idx_167_2 = sec_r000229_10_2 & 3;
  int stage_v_167_1 = (table_1[s_idx_167_1] + pub_r000229_3_1) & 127;
  int stage_v_167_2 = (table_2[s_idx_167_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_167_1] = (stage_v_167_1 + 7) & 63;
  table_2[s_idx_167_2] = (stage_v_167_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_167_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_167_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int s_idx_168_1 = stage_v_148_1 & 3;
  int s_idx_168_2 = stage_v_148_2 & 3;
  int stage_v_168_1 = (table_1[s_idx_168_1] + pub_r000229_9_1) & 127;
  int stage_v_168_2 = (table_2[s_idx_168_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_168_1] = (stage_v_168_1 + 7) & 63;
  table_2[s_idx_168_2] = (stage_v_168_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_168_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_168_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int s_idx_169_1 = sec_r000229_20_1 & 3;
  int s_idx_169_2 = sec_r000229_20_2 & 3;
  int stage_v_169_1 = (table_1[s_idx_169_1] + pub_r000229_21_1) & 127;
  int stage_v_169_2 = (table_2[s_idx_169_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_169_1] = (stage_v_169_1 + 7) & 63;
  table_2[s_idx_169_2] = (stage_v_169_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_169_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_169_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int s_idx_170_1 = stage_v_57_1 & 3;
  int s_idx_170_2 = stage_v_57_2 & 3;
  int stage_v_170_1 = (table_1[s_idx_170_1] + pub_r000229_3_1) & 127;
  int stage_v_170_2 = (table_2[s_idx_170_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_170_1] = (stage_v_170_1 + 7) & 63;
  table_2[s_idx_170_2] = (stage_v_170_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_170_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_170_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int s_idx_171_1 = sec_r000229_11_1 & 3;
  int s_idx_171_2 = sec_r000229_11_2 & 3;
  int stage_v_171_1 = (table_1[s_idx_171_1] + pub_r000229_12_1) & 127;
  int stage_v_171_2 = (table_2[s_idx_171_2] + pub_r000229_12_2) & 127;
  table_1[s_idx_171_1] = (stage_v_171_1 + 7) & 63;
  table_2[s_idx_171_2] = (stage_v_171_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_171_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_171_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int s_idx_172_1 = stage_v_167_1 & 3;
  int s_idx_172_2 = stage_v_167_2 & 3;
  int stage_v_172_1 = (table_1[s_idx_172_1] + pub_r000229_12_1) & 127;
  int stage_v_172_2 = (table_2[s_idx_172_2] + pub_r000229_12_2) & 127;
  table_1[s_idx_172_1] = (stage_v_172_1 + 7) & 63;
  table_2[s_idx_172_2] = (stage_v_172_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_172_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_172_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int s_idx_173_1 = stage_v_153_1 & 3;
  int s_idx_173_2 = stage_v_153_2 & 3;
  int stage_v_173_1 = (table_1[s_idx_173_1] + pub_r000229_10_1) & 127;
  int stage_v_173_2 = (table_2[s_idx_173_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_173_1] = (stage_v_173_1 + 7) & 63;
  table_2[s_idx_173_2] = (stage_v_173_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_173_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_173_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int s_idx_174_1 = sec_r000229_21_1 & 3;
  int s_idx_174_2 = sec_r000229_21_2 & 3;
  int stage_v_174_1 = (table_1[s_idx_174_1] + pub_r000229_6_1) & 127;
  int stage_v_174_2 = (table_2[s_idx_174_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_174_1] = (stage_v_174_1 + 7) & 63;
  table_2[s_idx_174_2] = (stage_v_174_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_174_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_174_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int s_idx_175_1 = stage_v_169_1 & 3;
  int s_idx_175_2 = stage_v_169_2 & 3;
  int stage_v_175_1 = (table_1[s_idx_175_1] + pub_r000229_6_1) & 127;
  int stage_v_175_2 = (table_2[s_idx_175_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_175_1] = (stage_v_175_1 + 7) & 63;
  table_2[s_idx_175_2] = (stage_v_175_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_175_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_175_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int s_idx_176_1 = stage_v_116_1 & 3;
  int s_idx_176_2 = stage_v_116_2 & 3;
  int stage_v_176_1 = (table_1[s_idx_176_1] + pub_r000229_10_1) & 127;
  int stage_v_176_2 = (table_2[s_idx_176_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_176_1] = (stage_v_176_1 + 7) & 63;
  table_2[s_idx_176_2] = (stage_v_176_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_176_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_176_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int s_idx_177_1 = sec_r000229_7_1 & 3;
  int s_idx_177_2 = sec_r000229_7_2 & 3;
  int stage_v_177_1 = (table_1[s_idx_177_1] + pub_r000229_9_1) & 127;
  int stage_v_177_2 = (table_2[s_idx_177_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_177_1] = (stage_v_177_1 + 7) & 63;
  table_2[s_idx_177_2] = (stage_v_177_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_177_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_177_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int s_idx_178_1 = stage_v_81_1 & 3;
  int s_idx_178_2 = stage_v_81_2 & 3;
  int stage_v_178_1 = (table_1[s_idx_178_1] + pub_r000229_22_1) & 127;
  int stage_v_178_2 = (table_2[s_idx_178_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_178_1] = (stage_v_178_1 + 7) & 63;
  table_2[s_idx_178_2] = (stage_v_178_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_178_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_178_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int s_idx_179_1 = sec_r000229_23_1 & 3;
  int s_idx_179_2 = sec_r000229_23_2 & 3;
  int stage_v_179_1 = (table_1[s_idx_179_1] + pub_r000229_21_1) & 127;
  int stage_v_179_2 = (table_2[s_idx_179_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_179_1] = (stage_v_179_1 + 7) & 63;
  table_2[s_idx_179_2] = (stage_v_179_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_179_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_179_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int s_idx_180_1 = stage_v_155_1 & 3;
  int s_idx_180_2 = stage_v_155_2 & 3;
  int stage_v_180_1 = (table_1[s_idx_180_1] + pub_r000229_0_1) & 127;
  int stage_v_180_2 = (table_2[s_idx_180_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_180_1] = (stage_v_180_1 + 7) & 63;
  table_2[s_idx_180_2] = (stage_v_180_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_180_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_180_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int s_idx_181_1 = stage_v_167_1 & 3;
  int s_idx_181_2 = stage_v_167_2 & 3;
  int stage_v_181_1 = (table_1[s_idx_181_1] + pub_r000229_6_1) & 127;
  int stage_v_181_2 = (table_2[s_idx_181_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_181_1] = (stage_v_181_1 + 7) & 63;
  table_2[s_idx_181_2] = (stage_v_181_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_181_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_181_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int s_idx_182_1 = sec_r000229_22_1 & 3;
  int s_idx_182_2 = sec_r000229_22_2 & 3;
  int stage_v_182_1 = (table_1[s_idx_182_1] + pub_r000229_22_1) & 127;
  int stage_v_182_2 = (table_2[s_idx_182_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_182_1] = (stage_v_182_1 + 7) & 63;
  table_2[s_idx_182_2] = (stage_v_182_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_182_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_182_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int s_idx_183_1 = stage_v_146_1 & 3;
  int s_idx_183_2 = stage_v_146_2 & 3;
  int stage_v_183_1 = (table_1[s_idx_183_1] + pub_r000229_3_1) & 127;
  int stage_v_183_2 = (table_2[s_idx_183_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_183_1] = (stage_v_183_1 + 7) & 63;
  table_2[s_idx_183_2] = (stage_v_183_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_183_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_183_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int s_idx_184_1 = stage_v_82_1 & 3;
  int s_idx_184_2 = stage_v_82_2 & 3;
  int stage_v_184_1 = (table_1[s_idx_184_1] + pub_r000229_9_1) & 127;
  int stage_v_184_2 = (table_2[s_idx_184_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_184_1] = (stage_v_184_1 + 7) & 63;
  table_2[s_idx_184_2] = (stage_v_184_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_184_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_184_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int s_idx_185_1 = stage_v_92_1 & 3;
  int s_idx_185_2 = stage_v_92_2 & 3;
  int stage_v_185_1 = (table_1[s_idx_185_1] + pub_r000229_0_1) & 127;
  int stage_v_185_2 = (table_2[s_idx_185_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_185_1] = (stage_v_185_1 + 7) & 63;
  table_2[s_idx_185_2] = (stage_v_185_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_185_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_185_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int s_idx_186_1 = stage_v_163_1 & 3;
  int s_idx_186_2 = stage_v_163_2 & 3;
  int stage_v_186_1 = (table_1[s_idx_186_1] + pub_r000229_22_1) & 127;
  int stage_v_186_2 = (table_2[s_idx_186_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_186_1] = (stage_v_186_1 + 7) & 63;
  table_2[s_idx_186_2] = (stage_v_186_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_186_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_186_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int s_idx_187_1 = sec_r000229_10_1 & 3;
  int s_idx_187_2 = sec_r000229_10_2 & 3;
  int stage_v_187_1 = (table_1[s_idx_187_1] + pub_r000229_16_1) & 127;
  int stage_v_187_2 = (table_2[s_idx_187_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_187_1] = (stage_v_187_1 + 7) & 63;
  table_2[s_idx_187_2] = (stage_v_187_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_187_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_187_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int s_idx_188_1 = sec_r000229_21_1 & 3;
  int s_idx_188_2 = sec_r000229_21_2 & 3;
  int stage_v_188_1 = (table_1[s_idx_188_1] + pub_r000229_1_1) & 127;
  int stage_v_188_2 = (table_2[s_idx_188_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_188_1] = (stage_v_188_1 + 7) & 63;
  table_2[s_idx_188_2] = (stage_v_188_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_188_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_188_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int s_idx_189_1 = stage_v_62_1 & 3;
  int s_idx_189_2 = stage_v_62_2 & 3;
  int stage_v_189_1 = (table_1[s_idx_189_1] + pub_r000229_5_1) & 127;
  int stage_v_189_2 = (table_2[s_idx_189_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_189_1] = (stage_v_189_1 + 7) & 63;
  table_2[s_idx_189_2] = (stage_v_189_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_189_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_189_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int s_idx_190_1 = sec_r000229_17_1 & 3;
  int s_idx_190_2 = sec_r000229_17_2 & 3;
  int stage_v_190_1 = (table_1[s_idx_190_1] + pub_r000229_11_1) & 127;
  int stage_v_190_2 = (table_2[s_idx_190_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_190_1] = (stage_v_190_1 + 7) & 63;
  table_2[s_idx_190_2] = (stage_v_190_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_190_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_190_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int s_idx_191_1 = sec_r000229_16_1 & 3;
  int s_idx_191_2 = sec_r000229_16_2 & 3;
  int stage_v_191_1 = (table_1[s_idx_191_1] + pub_r000229_15_1) & 127;
  int stage_v_191_2 = (table_2[s_idx_191_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_191_1] = (stage_v_191_1 + 7) & 63;
  table_2[s_idx_191_2] = (stage_v_191_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_191_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_191_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int s_idx_192_1 = stage_v_152_1 & 3;
  int s_idx_192_2 = stage_v_152_2 & 3;
  int stage_v_192_1 = (table_1[s_idx_192_1] + pub_r000229_14_1) & 127;
  int stage_v_192_2 = (table_2[s_idx_192_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_192_1] = (stage_v_192_1 + 7) & 63;
  table_2[s_idx_192_2] = (stage_v_192_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_192_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_192_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int s_idx_193_1 = sec_r000229_23_1 & 3;
  int s_idx_193_2 = sec_r000229_23_2 & 3;
  int stage_v_193_1 = (table_1[s_idx_193_1] + pub_r000229_13_1) & 127;
  int stage_v_193_2 = (table_2[s_idx_193_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_193_1] = (stage_v_193_1 + 7) & 63;
  table_2[s_idx_193_2] = (stage_v_193_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_193_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_193_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int s_idx_194_1 = stage_v_39_1 & 3;
  int s_idx_194_2 = stage_v_39_2 & 3;
  int stage_v_194_1 = (table_1[s_idx_194_1] + pub_r000229_6_1) & 127;
  int stage_v_194_2 = (table_2[s_idx_194_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_194_1] = (stage_v_194_1 + 7) & 63;
  table_2[s_idx_194_2] = (stage_v_194_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_194_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_194_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int s_idx_195_1 = stage_v_164_1 & 3;
  int s_idx_195_2 = stage_v_164_2 & 3;
  int stage_v_195_1 = (table_1[s_idx_195_1] + pub_r000229_3_1) & 127;
  int stage_v_195_2 = (table_2[s_idx_195_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_195_1] = (stage_v_195_1 + 7) & 63;
  table_2[s_idx_195_2] = (stage_v_195_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_195_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_195_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int s_idx_196_1 = stage_v_119_1 & 3;
  int s_idx_196_2 = stage_v_119_2 & 3;
  int stage_v_196_1 = (table_1[s_idx_196_1] + pub_r000229_4_1) & 127;
  int stage_v_196_2 = (table_2[s_idx_196_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_196_1] = (stage_v_196_1 + 7) & 63;
  table_2[s_idx_196_2] = (stage_v_196_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_196_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_196_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int s_idx_197_1 = stage_v_112_1 & 3;
  int s_idx_197_2 = stage_v_112_2 & 3;
  int stage_v_197_1 = (table_1[s_idx_197_1] + pub_r000229_11_1) & 127;
  int stage_v_197_2 = (table_2[s_idx_197_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_197_1] = (stage_v_197_1 + 7) & 63;
  table_2[s_idx_197_2] = (stage_v_197_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_197_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_197_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int s_idx_198_1 = sec_r000229_16_1 & 3;
  int s_idx_198_2 = sec_r000229_16_2 & 3;
  int stage_v_198_1 = (table_1[s_idx_198_1] + pub_r000229_10_1) & 127;
  int stage_v_198_2 = (table_2[s_idx_198_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_198_1] = (stage_v_198_1 + 7) & 63;
  table_2[s_idx_198_2] = (stage_v_198_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_198_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_198_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int s_idx_199_1 = sec_r000229_6_1 & 3;
  int s_idx_199_2 = sec_r000229_6_2 & 3;
  int stage_v_199_1 = (table_1[s_idx_199_1] + pub_r000229_14_1) & 127;
  int stage_v_199_2 = (table_2[s_idx_199_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_199_1] = (stage_v_199_1 + 7) & 63;
  table_2[s_idx_199_2] = (stage_v_199_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_199_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_199_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int s_idx_200_1 = stage_v_101_1 & 3;
  int s_idx_200_2 = stage_v_101_2 & 3;
  int stage_v_200_1 = (table_1[s_idx_200_1] + pub_r000229_11_1) & 127;
  int stage_v_200_2 = (table_2[s_idx_200_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_200_1] = (stage_v_200_1 + 7) & 63;
  table_2[s_idx_200_2] = (stage_v_200_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_200_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_200_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int s_idx_201_1 = sec_r000229_2_1 & 3;
  int s_idx_201_2 = sec_r000229_2_2 & 3;
  int stage_v_201_1 = (table_1[s_idx_201_1] + pub_r000229_4_1) & 127;
  int stage_v_201_2 = (table_2[s_idx_201_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_201_1] = (stage_v_201_1 + 7) & 63;
  table_2[s_idx_201_2] = (stage_v_201_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_201_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_201_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int s_idx_202_1 = stage_v_140_1 & 3;
  int s_idx_202_2 = stage_v_140_2 & 3;
  int stage_v_202_1 = (table_1[s_idx_202_1] + pub_r000229_19_1) & 127;
  int stage_v_202_2 = (table_2[s_idx_202_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_202_1] = (stage_v_202_1 + 7) & 63;
  table_2[s_idx_202_2] = (stage_v_202_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_202_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_202_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int s_idx_203_1 = stage_v_200_1 & 3;
  int s_idx_203_2 = stage_v_200_2 & 3;
  int stage_v_203_1 = (table_1[s_idx_203_1] + pub_r000229_21_1) & 127;
  int stage_v_203_2 = (table_2[s_idx_203_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_203_1] = (stage_v_203_1 + 7) & 63;
  table_2[s_idx_203_2] = (stage_v_203_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_203_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_203_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int s_idx_204_1 = sec_r000229_7_1 & 3;
  int s_idx_204_2 = sec_r000229_7_2 & 3;
  int stage_v_204_1 = (table_1[s_idx_204_1] + pub_r000229_17_1) & 127;
  int stage_v_204_2 = (table_2[s_idx_204_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_204_1] = (stage_v_204_1 + 7) & 63;
  table_2[s_idx_204_2] = (stage_v_204_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_204_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_204_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int s_idx_205_1 = sec_r000229_14_1 & 3;
  int s_idx_205_2 = sec_r000229_14_2 & 3;
  int stage_v_205_1 = (table_1[s_idx_205_1] + pub_r000229_1_1) & 127;
  int stage_v_205_2 = (table_2[s_idx_205_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_205_1] = (stage_v_205_1 + 7) & 63;
  table_2[s_idx_205_2] = (stage_v_205_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_205_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_205_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int s_idx_206_1 = sec_r000229_15_1 & 3;
  int s_idx_206_2 = sec_r000229_15_2 & 3;
  int stage_v_206_1 = (table_1[s_idx_206_1] + pub_r000229_7_1) & 127;
  int stage_v_206_2 = (table_2[s_idx_206_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_206_1] = (stage_v_206_1 + 7) & 63;
  table_2[s_idx_206_2] = (stage_v_206_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_206_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_206_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int s_idx_207_1 = sec_r000229_22_1 & 3;
  int s_idx_207_2 = sec_r000229_22_2 & 3;
  int stage_v_207_1 = (table_1[s_idx_207_1] + pub_r000229_17_1) & 127;
  int stage_v_207_2 = (table_2[s_idx_207_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_207_1] = (stage_v_207_1 + 7) & 63;
  table_2[s_idx_207_2] = (stage_v_207_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_207_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_207_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int s_idx_208_1 = stage_v_121_1 & 3;
  int s_idx_208_2 = stage_v_121_2 & 3;
  int stage_v_208_1 = (table_1[s_idx_208_1] + pub_r000229_15_1) & 127;
  int stage_v_208_2 = (table_2[s_idx_208_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_208_1] = (stage_v_208_1 + 7) & 63;
  table_2[s_idx_208_2] = (stage_v_208_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_208_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_208_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int s_idx_209_1 = stage_v_151_1 & 3;
  int s_idx_209_2 = stage_v_151_2 & 3;
  int stage_v_209_1 = (table_1[s_idx_209_1] + pub_r000229_7_1) & 127;
  int stage_v_209_2 = (table_2[s_idx_209_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_209_1] = (stage_v_209_1 + 7) & 63;
  table_2[s_idx_209_2] = (stage_v_209_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_209_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_209_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int s_idx_210_1 = stage_v_205_1 & 3;
  int s_idx_210_2 = stage_v_205_2 & 3;
  int stage_v_210_1 = (table_1[s_idx_210_1] + pub_r000229_4_1) & 127;
  int stage_v_210_2 = (table_2[s_idx_210_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_210_1] = (stage_v_210_1 + 7) & 63;
  table_2[s_idx_210_2] = (stage_v_210_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_210_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_210_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int s_idx_211_1 = stage_v_178_1 & 3;
  int s_idx_211_2 = stage_v_178_2 & 3;
  int stage_v_211_1 = (table_1[s_idx_211_1] + pub_r000229_11_1) & 127;
  int stage_v_211_2 = (table_2[s_idx_211_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_211_1] = (stage_v_211_1 + 7) & 63;
  table_2[s_idx_211_2] = (stage_v_211_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_211_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_211_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int s_idx_212_1 = stage_v_185_1 & 3;
  int s_idx_212_2 = stage_v_185_2 & 3;
  int stage_v_212_1 = (table_1[s_idx_212_1] + pub_r000229_10_1) & 127;
  int stage_v_212_2 = (table_2[s_idx_212_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_212_1] = (stage_v_212_1 + 7) & 63;
  table_2[s_idx_212_2] = (stage_v_212_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_212_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_212_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int s_idx_213_1 = stage_v_42_1 & 3;
  int s_idx_213_2 = stage_v_42_2 & 3;
  int stage_v_213_1 = (table_1[s_idx_213_1] + pub_r000229_2_1) & 127;
  int stage_v_213_2 = (table_2[s_idx_213_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_213_1] = (stage_v_213_1 + 7) & 63;
  table_2[s_idx_213_2] = (stage_v_213_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_213_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_213_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int s_idx_214_1 = stage_v_121_1 & 3;
  int s_idx_214_2 = stage_v_121_2 & 3;
  int stage_v_214_1 = (table_1[s_idx_214_1] + pub_r000229_1_1) & 127;
  int stage_v_214_2 = (table_2[s_idx_214_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_214_1] = (stage_v_214_1 + 7) & 63;
  table_2[s_idx_214_2] = (stage_v_214_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_214_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_214_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int s_idx_215_1 = stage_v_157_1 & 3;
  int s_idx_215_2 = stage_v_157_2 & 3;
  int stage_v_215_1 = (table_1[s_idx_215_1] + pub_r000229_4_1) & 127;
  int stage_v_215_2 = (table_2[s_idx_215_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_215_1] = (stage_v_215_1 + 7) & 63;
  table_2[s_idx_215_2] = (stage_v_215_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_215_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_215_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int s_idx_216_1 = sec_r000229_1_1 & 3;
  int s_idx_216_2 = sec_r000229_1_2 & 3;
  int stage_v_216_1 = (table_1[s_idx_216_1] + pub_r000229_13_1) & 127;
  int stage_v_216_2 = (table_2[s_idx_216_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_216_1] = (stage_v_216_1 + 7) & 63;
  table_2[s_idx_216_2] = (stage_v_216_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_216_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_216_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int s_idx_217_1 = sec_r000229_19_1 & 3;
  int s_idx_217_2 = sec_r000229_19_2 & 3;
  int stage_v_217_1 = (table_1[s_idx_217_1] + pub_r000229_11_1) & 127;
  int stage_v_217_2 = (table_2[s_idx_217_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_217_1] = (stage_v_217_1 + 7) & 63;
  table_2[s_idx_217_2] = (stage_v_217_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_217_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_217_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int s_idx_218_1 = stage_v_186_1 & 3;
  int s_idx_218_2 = stage_v_186_2 & 3;
  int stage_v_218_1 = (table_1[s_idx_218_1] + pub_r000229_1_1) & 127;
  int stage_v_218_2 = (table_2[s_idx_218_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_218_1] = (stage_v_218_1 + 7) & 63;
  table_2[s_idx_218_2] = (stage_v_218_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_218_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_218_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int s_idx_219_1 = stage_v_203_1 & 3;
  int s_idx_219_2 = stage_v_203_2 & 3;
  int stage_v_219_1 = (table_1[s_idx_219_1] + pub_r000229_13_1) & 127;
  int stage_v_219_2 = (table_2[s_idx_219_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_219_1] = (stage_v_219_1 + 7) & 63;
  table_2[s_idx_219_2] = (stage_v_219_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_219_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_219_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int s_idx_220_1 = sec_r000229_20_1 & 3;
  int s_idx_220_2 = sec_r000229_20_2 & 3;
  int stage_v_220_1 = (table_1[s_idx_220_1] + pub_r000229_6_1) & 127;
  int stage_v_220_2 = (table_2[s_idx_220_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_220_1] = (stage_v_220_1 + 7) & 63;
  table_2[s_idx_220_2] = (stage_v_220_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_220_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_220_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int s_idx_221_1 = stage_v_46_1 & 3;
  int s_idx_221_2 = stage_v_46_2 & 3;
  int stage_v_221_1 = (table_1[s_idx_221_1] + pub_r000229_3_1) & 127;
  int stage_v_221_2 = (table_2[s_idx_221_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_221_1] = (stage_v_221_1 + 7) & 63;
  table_2[s_idx_221_2] = (stage_v_221_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_221_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_221_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int s_idx_222_1 = stage_v_82_1 & 3;
  int s_idx_222_2 = stage_v_82_2 & 3;
  int stage_v_222_1 = (table_1[s_idx_222_1] + pub_r000229_4_1) & 127;
  int stage_v_222_2 = (table_2[s_idx_222_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_222_1] = (stage_v_222_1 + 7) & 63;
  table_2[s_idx_222_2] = (stage_v_222_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_222_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_222_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int s_idx_223_1 = stage_v_85_1 & 3;
  int s_idx_223_2 = stage_v_85_2 & 3;
  int stage_v_223_1 = (table_1[s_idx_223_1] + pub_r000229_6_1) & 127;
  int stage_v_223_2 = (table_2[s_idx_223_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_223_1] = (stage_v_223_1 + 7) & 63;
  table_2[s_idx_223_2] = (stage_v_223_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_223_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_223_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int s_idx_224_1 = stage_v_54_1 & 3;
  int s_idx_224_2 = stage_v_54_2 & 3;
  int stage_v_224_1 = (table_1[s_idx_224_1] + pub_r000229_19_1) & 127;
  int stage_v_224_2 = (table_2[s_idx_224_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_224_1] = (stage_v_224_1 + 7) & 63;
  table_2[s_idx_224_2] = (stage_v_224_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_224_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_224_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int s_idx_225_1 = stage_v_223_1 & 3;
  int s_idx_225_2 = stage_v_223_2 & 3;
  int stage_v_225_1 = (table_1[s_idx_225_1] + pub_r000229_4_1) & 127;
  int stage_v_225_2 = (table_2[s_idx_225_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_225_1] = (stage_v_225_1 + 7) & 63;
  table_2[s_idx_225_2] = (stage_v_225_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_225_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_225_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int s_idx_226_1 = stage_v_203_1 & 3;
  int s_idx_226_2 = stage_v_203_2 & 3;
  int stage_v_226_1 = (table_1[s_idx_226_1] + pub_r000229_1_1) & 127;
  int stage_v_226_2 = (table_2[s_idx_226_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_226_1] = (stage_v_226_1 + 7) & 63;
  table_2[s_idx_226_2] = (stage_v_226_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_226_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_226_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int s_idx_227_1 = stage_v_34_1 & 3;
  int s_idx_227_2 = stage_v_34_2 & 3;
  int stage_v_227_1 = (table_1[s_idx_227_1] + pub_r000229_22_1) & 127;
  int stage_v_227_2 = (table_2[s_idx_227_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_227_1] = (stage_v_227_1 + 7) & 63;
  table_2[s_idx_227_2] = (stage_v_227_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_227_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_227_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int s_idx_228_1 = stage_v_41_1 & 3;
  int s_idx_228_2 = stage_v_41_2 & 3;
  int stage_v_228_1 = (table_1[s_idx_228_1] + pub_r000229_14_1) & 127;
  int stage_v_228_2 = (table_2[s_idx_228_2] + pub_r000229_14_2) & 127;
  table_1[s_idx_228_1] = (stage_v_228_1 + 7) & 63;
  table_2[s_idx_228_2] = (stage_v_228_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_228_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_228_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int s_idx_229_1 = stage_v_134_1 & 3;
  int s_idx_229_2 = stage_v_134_2 & 3;
  int stage_v_229_1 = (table_1[s_idx_229_1] + pub_r000229_20_1) & 127;
  int stage_v_229_2 = (table_2[s_idx_229_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_229_1] = (stage_v_229_1 + 7) & 63;
  table_2[s_idx_229_2] = (stage_v_229_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_229_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_229_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int s_idx_230_1 = sec_r000229_18_1 & 3;
  int s_idx_230_2 = sec_r000229_18_2 & 3;
  int stage_v_230_1 = (table_1[s_idx_230_1] + pub_r000229_22_1) & 127;
  int stage_v_230_2 = (table_2[s_idx_230_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_230_1] = (stage_v_230_1 + 7) & 63;
  table_2[s_idx_230_2] = (stage_v_230_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_230_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_230_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  int s_idx_231_1 = stage_v_193_1 & 3;
  int s_idx_231_2 = stage_v_193_2 & 3;
  int stage_v_231_1 = (table_1[s_idx_231_1] + pub_r000229_21_1) & 127;
  int stage_v_231_2 = (table_2[s_idx_231_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_231_1] = (stage_v_231_1 + 7) & 63;
  table_2[s_idx_231_2] = (stage_v_231_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_231_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_231_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  int s_idx_232_1 = stage_v_137_1 & 3;
  int s_idx_232_2 = stage_v_137_2 & 3;
  int stage_v_232_1 = (table_1[s_idx_232_1] + pub_r000229_0_1) & 127;
  int stage_v_232_2 = (table_2[s_idx_232_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_232_1] = (stage_v_232_1 + 7) & 63;
  table_2[s_idx_232_2] = (stage_v_232_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_232_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_232_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  int s_idx_233_1 = sec_r000229_21_1 & 3;
  int s_idx_233_2 = sec_r000229_21_2 & 3;
  int stage_v_233_1 = (table_1[s_idx_233_1] + pub_r000229_9_1) & 127;
  int stage_v_233_2 = (table_2[s_idx_233_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_233_1] = (stage_v_233_1 + 7) & 63;
  table_2[s_idx_233_2] = (stage_v_233_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_233_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_233_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  int s_idx_234_1 = stage_v_80_1 & 3;
  int s_idx_234_2 = stage_v_80_2 & 3;
  int stage_v_234_1 = (table_1[s_idx_234_1] + pub_r000229_16_1) & 127;
  int stage_v_234_2 = (table_2[s_idx_234_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_234_1] = (stage_v_234_1 + 7) & 63;
  table_2[s_idx_234_2] = (stage_v_234_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_234_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_234_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  int s_idx_235_1 = stage_v_72_1 & 3;
  int s_idx_235_2 = stage_v_72_2 & 3;
  int stage_v_235_1 = (table_1[s_idx_235_1] + pub_r000229_21_1) & 127;
  int stage_v_235_2 = (table_2[s_idx_235_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_235_1] = (stage_v_235_1 + 7) & 63;
  table_2[s_idx_235_2] = (stage_v_235_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_235_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_235_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  int s_idx_236_1 = stage_v_150_1 & 3;
  int s_idx_236_2 = stage_v_150_2 & 3;
  int stage_v_236_1 = (table_1[s_idx_236_1] + pub_r000229_3_1) & 127;
  int stage_v_236_2 = (table_2[s_idx_236_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_236_1] = (stage_v_236_1 + 7) & 63;
  table_2[s_idx_236_2] = (stage_v_236_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_236_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_236_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  int s_idx_237_1 = sec_r000229_17_1 & 3;
  int s_idx_237_2 = sec_r000229_17_2 & 3;
  int stage_v_237_1 = (table_1[s_idx_237_1] + pub_r000229_0_1) & 127;
  int stage_v_237_2 = (table_2[s_idx_237_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_237_1] = (stage_v_237_1 + 7) & 63;
  table_2[s_idx_237_2] = (stage_v_237_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_237_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_237_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_237_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_237_2) & 255;
  int s_idx_238_1 = sec_r000229_21_1 & 3;
  int s_idx_238_2 = sec_r000229_21_2 & 3;
  int stage_v_238_1 = (table_1[s_idx_238_1] + pub_r000229_15_1) & 127;
  int stage_v_238_2 = (table_2[s_idx_238_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_238_1] = (stage_v_238_1 + 7) & 63;
  table_2[s_idx_238_2] = (stage_v_238_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_238_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_238_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_238_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_238_2) & 255;
  int s_idx_239_1 = sec_r000229_17_1 & 3;
  int s_idx_239_2 = sec_r000229_17_2 & 3;
  int stage_v_239_1 = (table_1[s_idx_239_1] + pub_r000229_11_1) & 127;
  int stage_v_239_2 = (table_2[s_idx_239_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_239_1] = (stage_v_239_1 + 7) & 63;
  table_2[s_idx_239_2] = (stage_v_239_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_239_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_239_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_239_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_239_2) & 255;
  int s_idx_240_1 = stage_v_93_1 & 3;
  int s_idx_240_2 = stage_v_93_2 & 3;
  int stage_v_240_1 = (table_1[s_idx_240_1] + pub_r000229_3_1) & 127;
  int stage_v_240_2 = (table_2[s_idx_240_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_240_1] = (stage_v_240_1 + 7) & 63;
  table_2[s_idx_240_2] = (stage_v_240_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_240_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_240_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  int s_idx_241_1 = sec_r000229_15_1 & 3;
  int s_idx_241_2 = sec_r000229_15_2 & 3;
  int stage_v_241_1 = (table_1[s_idx_241_1] + pub_r000229_8_1) & 127;
  int stage_v_241_2 = (table_2[s_idx_241_2] + pub_r000229_8_2) & 127;
  table_1[s_idx_241_1] = (stage_v_241_1 + 7) & 63;
  table_2[s_idx_241_2] = (stage_v_241_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_241_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_241_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  int s_idx_242_1 = stage_v_63_1 & 3;
  int s_idx_242_2 = stage_v_63_2 & 3;
  int stage_v_242_1 = (table_1[s_idx_242_1] + pub_r000229_11_1) & 127;
  int stage_v_242_2 = (table_2[s_idx_242_2] + pub_r000229_11_2) & 127;
  table_1[s_idx_242_1] = (stage_v_242_1 + 7) & 63;
  table_2[s_idx_242_2] = (stage_v_242_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_242_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_242_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  int s_idx_243_1 = sec_r000229_3_1 & 3;
  int s_idx_243_2 = sec_r000229_3_2 & 3;
  int stage_v_243_1 = (table_1[s_idx_243_1] + pub_r000229_20_1) & 127;
  int stage_v_243_2 = (table_2[s_idx_243_2] + pub_r000229_20_2) & 127;
  table_1[s_idx_243_1] = (stage_v_243_1 + 7) & 63;
  table_2[s_idx_243_2] = (stage_v_243_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_243_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_243_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  int s_idx_244_1 = sec_r000229_5_1 & 3;
  int s_idx_244_2 = sec_r000229_5_2 & 3;
  int stage_v_244_1 = (table_1[s_idx_244_1] + pub_r000229_12_1) & 127;
  int stage_v_244_2 = (table_2[s_idx_244_2] + pub_r000229_12_2) & 127;
  table_1[s_idx_244_1] = (stage_v_244_1 + 7) & 63;
  table_2[s_idx_244_2] = (stage_v_244_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_244_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_244_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  int s_idx_245_1 = sec_r000229_23_1 & 3;
  int s_idx_245_2 = sec_r000229_23_2 & 3;
  int stage_v_245_1 = (table_1[s_idx_245_1] + pub_r000229_2_1) & 127;
  int stage_v_245_2 = (table_2[s_idx_245_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_245_1] = (stage_v_245_1 + 7) & 63;
  table_2[s_idx_245_2] = (stage_v_245_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_245_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_245_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  int s_idx_246_1 = stage_v_68_1 & 3;
  int s_idx_246_2 = stage_v_68_2 & 3;
  int stage_v_246_1 = (table_1[s_idx_246_1] + pub_r000229_18_1) & 127;
  int stage_v_246_2 = (table_2[s_idx_246_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_246_1] = (stage_v_246_1 + 7) & 63;
  table_2[s_idx_246_2] = (stage_v_246_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_246_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_246_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_246_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_246_2) & 255;
  int s_idx_247_1 = stage_v_161_1 & 3;
  int s_idx_247_2 = stage_v_161_2 & 3;
  int stage_v_247_1 = (table_1[s_idx_247_1] + pub_r000229_0_1) & 127;
  int stage_v_247_2 = (table_2[s_idx_247_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_247_1] = (stage_v_247_1 + 7) & 63;
  table_2[s_idx_247_2] = (stage_v_247_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_247_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_247_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_247_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_247_2) & 255;
  int s_idx_248_1 = stage_v_44_1 & 3;
  int s_idx_248_2 = stage_v_44_2 & 3;
  int stage_v_248_1 = (table_1[s_idx_248_1] + pub_r000229_9_1) & 127;
  int stage_v_248_2 = (table_2[s_idx_248_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_248_1] = (stage_v_248_1 + 7) & 63;
  table_2[s_idx_248_2] = (stage_v_248_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_248_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_248_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  int s_idx_249_1 = sec_r000229_13_1 & 3;
  int s_idx_249_2 = sec_r000229_13_2 & 3;
  int stage_v_249_1 = (table_1[s_idx_249_1] + pub_r000229_1_1) & 127;
  int stage_v_249_2 = (table_2[s_idx_249_2] + pub_r000229_1_2) & 127;
  table_1[s_idx_249_1] = (stage_v_249_1 + 7) & 63;
  table_2[s_idx_249_2] = (stage_v_249_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_249_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_249_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  int s_idx_250_1 = stage_v_140_1 & 3;
  int s_idx_250_2 = stage_v_140_2 & 3;
  int stage_v_250_1 = (table_1[s_idx_250_1] + pub_r000229_7_1) & 127;
  int stage_v_250_2 = (table_2[s_idx_250_2] + pub_r000229_7_2) & 127;
  table_1[s_idx_250_1] = (stage_v_250_1 + 7) & 63;
  table_2[s_idx_250_2] = (stage_v_250_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_250_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_250_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  int s_idx_251_1 = sec_r000229_7_1 & 3;
  int s_idx_251_2 = sec_r000229_7_2 & 3;
  int stage_v_251_1 = (table_1[s_idx_251_1] + pub_r000229_21_1) & 127;
  int stage_v_251_2 = (table_2[s_idx_251_2] + pub_r000229_21_2) & 127;
  table_1[s_idx_251_1] = (stage_v_251_1 + 7) & 63;
  table_2[s_idx_251_2] = (stage_v_251_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_251_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_251_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  int s_idx_252_1 = sec_r000229_3_1 & 3;
  int s_idx_252_2 = sec_r000229_3_2 & 3;
  int stage_v_252_1 = (table_1[s_idx_252_1] + pub_r000229_18_1) & 127;
  int stage_v_252_2 = (table_2[s_idx_252_2] + pub_r000229_18_2) & 127;
  table_1[s_idx_252_1] = (stage_v_252_1 + 7) & 63;
  table_2[s_idx_252_2] = (stage_v_252_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_252_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_252_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  int s_idx_253_1 = stage_v_210_1 & 3;
  int s_idx_253_2 = stage_v_210_2 & 3;
  int stage_v_253_1 = (table_1[s_idx_253_1] + pub_r000229_13_1) & 127;
  int stage_v_253_2 = (table_2[s_idx_253_2] + pub_r000229_13_2) & 127;
  table_1[s_idx_253_1] = (stage_v_253_1 + 7) & 63;
  table_2[s_idx_253_2] = (stage_v_253_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_253_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_253_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  int s_idx_254_1 = sec_r000229_22_1 & 3;
  int s_idx_254_2 = sec_r000229_22_2 & 3;
  int stage_v_254_1 = (table_1[s_idx_254_1] + pub_r000229_9_1) & 127;
  int stage_v_254_2 = (table_2[s_idx_254_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_254_1] = (stage_v_254_1 + 7) & 63;
  table_2[s_idx_254_2] = (stage_v_254_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_254_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_254_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  int s_idx_255_1 = stage_v_175_1 & 3;
  int s_idx_255_2 = stage_v_175_2 & 3;
  int stage_v_255_1 = (table_1[s_idx_255_1] + pub_r000229_16_1) & 127;
  int stage_v_255_2 = (table_2[s_idx_255_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_255_1] = (stage_v_255_1 + 7) & 63;
  table_2[s_idx_255_2] = (stage_v_255_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_255_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_255_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_255_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_255_2) & 255;
  int s_idx_256_1 = stage_v_236_1 & 3;
  int s_idx_256_2 = stage_v_236_2 & 3;
  int stage_v_256_1 = (table_1[s_idx_256_1] + pub_r000229_12_1) & 127;
  int stage_v_256_2 = (table_2[s_idx_256_2] + pub_r000229_12_2) & 127;
  table_1[s_idx_256_1] = (stage_v_256_1 + 7) & 63;
  table_2[s_idx_256_2] = (stage_v_256_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_256_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_256_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_256_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_256_2) & 255;
  int s_idx_257_1 = stage_v_121_1 & 3;
  int s_idx_257_2 = stage_v_121_2 & 3;
  int stage_v_257_1 = (table_1[s_idx_257_1] + pub_r000229_2_1) & 127;
  int stage_v_257_2 = (table_2[s_idx_257_2] + pub_r000229_2_2) & 127;
  table_1[s_idx_257_1] = (stage_v_257_1 + 7) & 63;
  table_2[s_idx_257_2] = (stage_v_257_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_257_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_257_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  int s_idx_258_1 = stage_v_228_1 & 3;
  int s_idx_258_2 = stage_v_228_2 & 3;
  int stage_v_258_1 = (table_1[s_idx_258_1] + pub_r000229_4_1) & 127;
  int stage_v_258_2 = (table_2[s_idx_258_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_258_1] = (stage_v_258_1 + 7) & 63;
  table_2[s_idx_258_2] = (stage_v_258_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_258_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_258_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_258_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_258_2) & 255;
  int s_idx_259_1 = stage_v_166_1 & 3;
  int s_idx_259_2 = stage_v_166_2 & 3;
  int stage_v_259_1 = (table_1[s_idx_259_1] + pub_r000229_22_1) & 127;
  int stage_v_259_2 = (table_2[s_idx_259_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_259_1] = (stage_v_259_1 + 7) & 63;
  table_2[s_idx_259_2] = (stage_v_259_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_259_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_259_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_259_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_259_2) & 255;
  int s_idx_260_1 = sec_r000229_2_1 & 3;
  int s_idx_260_2 = sec_r000229_2_2 & 3;
  int stage_v_260_1 = (table_1[s_idx_260_1] + pub_r000229_6_1) & 127;
  int stage_v_260_2 = (table_2[s_idx_260_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_260_1] = (stage_v_260_1 + 7) & 63;
  table_2[s_idx_260_2] = (stage_v_260_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_260_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_260_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  int s_idx_261_1 = sec_r000229_0_1 & 3;
  int s_idx_261_2 = sec_r000229_0_2 & 3;
  int stage_v_261_1 = (table_1[s_idx_261_1] + pub_r000229_15_1) & 127;
  int stage_v_261_2 = (table_2[s_idx_261_2] + pub_r000229_15_2) & 127;
  table_1[s_idx_261_1] = (stage_v_261_1 + 7) & 63;
  table_2[s_idx_261_2] = (stage_v_261_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_261_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_261_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  int s_idx_262_1 = stage_v_251_1 & 3;
  int s_idx_262_2 = stage_v_251_2 & 3;
  int stage_v_262_1 = (table_1[s_idx_262_1] + pub_r000229_19_1) & 127;
  int stage_v_262_2 = (table_2[s_idx_262_2] + pub_r000229_19_2) & 127;
  table_1[s_idx_262_1] = (stage_v_262_1 + 7) & 63;
  table_2[s_idx_262_2] = (stage_v_262_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_262_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_262_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_262_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_262_2) & 255;
  int s_idx_263_1 = sec_r000229_9_1 & 3;
  int s_idx_263_2 = sec_r000229_9_2 & 3;
  int stage_v_263_1 = (table_1[s_idx_263_1] + pub_r000229_16_1) & 127;
  int stage_v_263_2 = (table_2[s_idx_263_2] + pub_r000229_16_2) & 127;
  table_1[s_idx_263_1] = (stage_v_263_1 + 7) & 63;
  table_2[s_idx_263_2] = (stage_v_263_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_263_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_263_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  int s_idx_264_1 = stage_v_49_1 & 3;
  int s_idx_264_2 = stage_v_49_2 & 3;
  int stage_v_264_1 = (table_1[s_idx_264_1] + pub_r000229_9_1) & 127;
  int stage_v_264_2 = (table_2[s_idx_264_2] + pub_r000229_9_2) & 127;
  table_1[s_idx_264_1] = (stage_v_264_1 + 7) & 63;
  table_2[s_idx_264_2] = (stage_v_264_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_264_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_264_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  int s_idx_265_1 = stage_v_37_1 & 3;
  int s_idx_265_2 = stage_v_37_2 & 3;
  int stage_v_265_1 = (table_1[s_idx_265_1] + pub_r000229_17_1) & 127;
  int stage_v_265_2 = (table_2[s_idx_265_2] + pub_r000229_17_2) & 127;
  table_1[s_idx_265_1] = (stage_v_265_1 + 7) & 63;
  table_2[s_idx_265_2] = (stage_v_265_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_265_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_265_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  int s_idx_266_1 = sec_r000229_0_1 & 3;
  int s_idx_266_2 = sec_r000229_0_2 & 3;
  int stage_v_266_1 = (table_1[s_idx_266_1] + pub_r000229_3_1) & 127;
  int stage_v_266_2 = (table_2[s_idx_266_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_266_1] = (stage_v_266_1 + 7) & 63;
  table_2[s_idx_266_2] = (stage_v_266_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_266_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_266_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  int s_idx_267_1 = stage_v_58_1 & 3;
  int s_idx_267_2 = stage_v_58_2 & 3;
  int stage_v_267_1 = (table_1[s_idx_267_1] + pub_r000229_6_1) & 127;
  int stage_v_267_2 = (table_2[s_idx_267_2] + pub_r000229_6_2) & 127;
  table_1[s_idx_267_1] = (stage_v_267_1 + 7) & 63;
  table_2[s_idx_267_2] = (stage_v_267_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_267_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_267_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  int s_idx_268_1 = sec_r000229_16_1 & 3;
  int s_idx_268_2 = sec_r000229_16_2 & 3;
  int stage_v_268_1 = (table_1[s_idx_268_1] + pub_r000229_0_1) & 127;
  int stage_v_268_2 = (table_2[s_idx_268_2] + pub_r000229_0_2) & 127;
  table_1[s_idx_268_1] = (stage_v_268_1 + 7) & 63;
  table_2[s_idx_268_2] = (stage_v_268_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_268_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_268_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  int s_idx_269_1 = stage_v_103_1 & 3;
  int s_idx_269_2 = stage_v_103_2 & 3;
  int stage_v_269_1 = (table_1[s_idx_269_1] + pub_r000229_5_1) & 127;
  int stage_v_269_2 = (table_2[s_idx_269_2] + pub_r000229_5_2) & 127;
  table_1[s_idx_269_1] = (stage_v_269_1 + 7) & 63;
  table_2[s_idx_269_2] = (stage_v_269_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_269_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_269_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  int s_idx_270_1 = stage_v_215_1 & 3;
  int s_idx_270_2 = stage_v_215_2 & 3;
  int stage_v_270_1 = (table_1[s_idx_270_1] + pub_r000229_10_1) & 127;
  int stage_v_270_2 = (table_2[s_idx_270_2] + pub_r000229_10_2) & 127;
  table_1[s_idx_270_1] = (stage_v_270_1 + 7) & 63;
  table_2[s_idx_270_2] = (stage_v_270_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_270_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_270_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_270_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_270_2) & 255;
  int s_idx_271_1 = stage_v_224_1 & 3;
  int s_idx_271_2 = stage_v_224_2 & 3;
  int stage_v_271_1 = (table_1[s_idx_271_1] + pub_r000229_22_1) & 127;
  int stage_v_271_2 = (table_2[s_idx_271_2] + pub_r000229_22_2) & 127;
  table_1[s_idx_271_1] = (stage_v_271_1 + 7) & 63;
  table_2[s_idx_271_2] = (stage_v_271_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_271_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_271_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  int s_idx_272_1 = sec_r000229_19_1 & 3;
  int s_idx_272_2 = sec_r000229_19_2 & 3;
  int stage_v_272_1 = (table_1[s_idx_272_1] + pub_r000229_3_1) & 127;
  int stage_v_272_2 = (table_2[s_idx_272_2] + pub_r000229_3_2) & 127;
  table_1[s_idx_272_1] = (stage_v_272_1 + 7) & 63;
  table_2[s_idx_272_2] = (stage_v_272_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_272_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_272_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_272_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_272_2) & 255;
  int s_idx_273_1 = stage_v_55_1 & 3;
  int s_idx_273_2 = stage_v_55_2 & 3;
  int stage_v_273_1 = (table_1[s_idx_273_1] + pub_r000229_4_1) & 127;
  int stage_v_273_2 = (table_2[s_idx_273_2] + pub_r000229_4_2) & 127;
  table_1[s_idx_273_1] = (stage_v_273_1 + 7) & 63;
  table_2[s_idx_273_2] = (stage_v_273_2 + 7) & 63;
  out_sink_1 = (out_sink_1 + stage_v_273_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_273_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000229_7_1 != sec_r000229_7_2);
  __CPROVER_assume(pub_r000229_15_1 == pub_r000229_15_2);
  __CPROVER_assume(pub_r000229_4_1 == pub_r000229_4_2);
  __CPROVER_assume(sec_r000229_10_1 != sec_r000229_10_2);
  __CPROVER_assume(sec_r000229_2_1 != sec_r000229_2_2);
  __CPROVER_assume(pub_r000229_3_1 == pub_r000229_3_2);
  __CPROVER_assume(sec_r000229_0_1 != sec_r000229_0_2);
  __CPROVER_assume(sec_r000229_4_1 != sec_r000229_4_2);
  __CPROVER_assume(pub_r000229_13_1 == pub_r000229_13_2);
  __CPROVER_assume(pub_r000229_7_1 == pub_r000229_7_2);
  __CPROVER_assume(sec_r000229_17_1 != sec_r000229_17_2);
  __CPROVER_assume(sec_r000229_9_1 != sec_r000229_9_2);
  __CPROVER_assume(pub_r000229_18_1 == pub_r000229_18_2);
  __CPROVER_assume(pub_r000229_1_1 == pub_r000229_1_2);
  __CPROVER_assume(pub_r000229_12_1 == pub_r000229_12_2);
  __CPROVER_assume(sec_r000229_3_1 != sec_r000229_3_2);
  __CPROVER_assume(pub_r000229_2_1 == pub_r000229_2_2);
  __CPROVER_assume(sec_r000229_11_1 != sec_r000229_11_2);
  __CPROVER_assume(sec_r000229_16_1 != sec_r000229_16_2);
  __CPROVER_assume(sec_r000229_18_1 != sec_r000229_18_2);
  __CPROVER_assume(pub_r000229_17_1 == pub_r000229_17_2);
  __CPROVER_assume(sec_r000229_19_1 != sec_r000229_19_2);
  __CPROVER_assume(sec_r000229_23_1 != sec_r000229_23_2);
  __CPROVER_assume(pub_r000229_9_1 == pub_r000229_9_2);
  __CPROVER_assume(pub_r000229_5_1 == pub_r000229_5_2);
  __CPROVER_assume(sec_r000229_6_1 != sec_r000229_6_2);
  __CPROVER_assume(sec_r000229_21_1 != sec_r000229_21_2);
  __CPROVER_assume(sec_r000229_1_1 != sec_r000229_1_2);
  __CPROVER_assume(pub_r000229_22_1 == pub_r000229_22_2);
  __CPROVER_assume(pub_r000229_0_1 == pub_r000229_0_2);
  __CPROVER_assume(pub_r000229_16_1 == pub_r000229_16_2);
  __CPROVER_assume(pub_r000229_20_1 == pub_r000229_20_2);
  __CPROVER_assume(sec_r000229_14_1 != sec_r000229_14_2);
  __CPROVER_assume(sec_r000229_13_1 != sec_r000229_13_2);
  __CPROVER_assume(sec_r000229_22_1 != sec_r000229_22_2);
  __CPROVER_assume(sec_r000229_5_1 != sec_r000229_5_2);
  __CPROVER_assume(sec_r000229_20_1 != sec_r000229_20_2);
  __CPROVER_assume(pub_r000229_11_1 == pub_r000229_11_2);
  __CPROVER_assume(pub_r000229_6_1 == pub_r000229_6_2);
  __CPROVER_assume(pub_r000229_10_1 == pub_r000229_10_2);
  __CPROVER_assume(sec_r000229_12_1 != sec_r000229_12_2);
  __CPROVER_assume(sec_r000229_15_1 != sec_r000229_15_2);
  __CPROVER_assume(pub_r000229_14_1 == pub_r000229_14_2);
  __CPROVER_assume(pub_r000229_21_1 == pub_r000229_21_2);
  __CPROVER_assume(pub_r000229_19_1 == pub_r000229_19_2);
  __CPROVER_assume(sec_r000229_8_1 != sec_r000229_8_2);
  __CPROVER_assume(pub_r000229_8_1 == pub_r000229_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.baud_rate == st_var_1_2.baud_rate);
  assert(st_var_1_1.timeout == st_var_1_2.timeout);
  assert(st_var_1_1.port == st_var_1_2.port);
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
  assert(s_idx_33_1 == s_idx_33_2);
  assert(stage_v_33_1 == stage_v_33_2);
  assert(s_idx_34_1 == s_idx_34_2);
  assert(stage_v_34_1 == stage_v_34_2);
  assert(s_idx_35_1 == s_idx_35_2);
  assert(stage_v_35_1 == stage_v_35_2);
  assert(s_idx_36_1 == s_idx_36_2);
  assert(stage_v_36_1 == stage_v_36_2);
  assert(s_idx_37_1 == s_idx_37_2);
  assert(stage_v_37_1 == stage_v_37_2);
  assert(s_idx_38_1 == s_idx_38_2);
  assert(stage_v_38_1 == stage_v_38_2);
  assert(s_idx_39_1 == s_idx_39_2);
  assert(stage_v_39_1 == stage_v_39_2);
  assert(s_idx_40_1 == s_idx_40_2);
  assert(stage_v_40_1 == stage_v_40_2);
  assert(s_idx_41_1 == s_idx_41_2);
  assert(stage_v_41_1 == stage_v_41_2);
  assert(s_idx_42_1 == s_idx_42_2);
  assert(stage_v_42_1 == stage_v_42_2);
  assert(s_idx_43_1 == s_idx_43_2);
  assert(stage_v_43_1 == stage_v_43_2);
  assert(s_idx_44_1 == s_idx_44_2);
  assert(stage_v_44_1 == stage_v_44_2);
  assert(s_idx_45_1 == s_idx_45_2);
  assert(stage_v_45_1 == stage_v_45_2);
  assert(s_idx_46_1 == s_idx_46_2);
  assert(stage_v_46_1 == stage_v_46_2);
  assert(s_idx_47_1 == s_idx_47_2);
  assert(stage_v_47_1 == stage_v_47_2);
  assert(s_idx_48_1 == s_idx_48_2);
  assert(stage_v_48_1 == stage_v_48_2);
  assert(s_idx_49_1 == s_idx_49_2);
  assert(stage_v_49_1 == stage_v_49_2);
  assert(s_idx_50_1 == s_idx_50_2);
  assert(stage_v_50_1 == stage_v_50_2);
  assert(s_idx_51_1 == s_idx_51_2);
  assert(stage_v_51_1 == stage_v_51_2);
  assert(s_idx_52_1 == s_idx_52_2);
  assert(stage_v_52_1 == stage_v_52_2);
  assert(s_idx_53_1 == s_idx_53_2);
  assert(stage_v_53_1 == stage_v_53_2);
  assert(s_idx_54_1 == s_idx_54_2);
  assert(stage_v_54_1 == stage_v_54_2);
  assert(s_idx_55_1 == s_idx_55_2);
  assert(stage_v_55_1 == stage_v_55_2);
  assert(s_idx_56_1 == s_idx_56_2);
  assert(stage_v_56_1 == stage_v_56_2);
  assert(s_idx_57_1 == s_idx_57_2);
  assert(stage_v_57_1 == stage_v_57_2);
  assert(s_idx_58_1 == s_idx_58_2);
  assert(stage_v_58_1 == stage_v_58_2);
  assert(s_idx_59_1 == s_idx_59_2);
  assert(stage_v_59_1 == stage_v_59_2);
  assert(s_idx_60_1 == s_idx_60_2);
  assert(stage_v_60_1 == stage_v_60_2);
  assert(s_idx_61_1 == s_idx_61_2);
  assert(stage_v_61_1 == stage_v_61_2);
  assert(s_idx_62_1 == s_idx_62_2);
  assert(stage_v_62_1 == stage_v_62_2);
  assert(s_idx_63_1 == s_idx_63_2);
  assert(stage_v_63_1 == stage_v_63_2);
  assert(s_idx_64_1 == s_idx_64_2);
  assert(stage_v_64_1 == stage_v_64_2);
  assert(s_idx_65_1 == s_idx_65_2);
  assert(stage_v_65_1 == stage_v_65_2);
  assert(s_idx_66_1 == s_idx_66_2);
  assert(stage_v_66_1 == stage_v_66_2);
  assert(s_idx_67_1 == s_idx_67_2);
  assert(stage_v_67_1 == stage_v_67_2);
  assert(s_idx_68_1 == s_idx_68_2);
  assert(stage_v_68_1 == stage_v_68_2);
  assert(s_idx_69_1 == s_idx_69_2);
  assert(stage_v_69_1 == stage_v_69_2);
  assert(s_idx_70_1 == s_idx_70_2);
  assert(stage_v_70_1 == stage_v_70_2);
  assert(s_idx_71_1 == s_idx_71_2);
  assert(stage_v_71_1 == stage_v_71_2);
  assert(s_idx_72_1 == s_idx_72_2);
  assert(stage_v_72_1 == stage_v_72_2);
  assert(s_idx_73_1 == s_idx_73_2);
  assert(stage_v_73_1 == stage_v_73_2);
  assert(s_idx_74_1 == s_idx_74_2);
  assert(stage_v_74_1 == stage_v_74_2);
  assert(s_idx_75_1 == s_idx_75_2);
  assert(stage_v_75_1 == stage_v_75_2);
  assert(s_idx_76_1 == s_idx_76_2);
  assert(stage_v_76_1 == stage_v_76_2);
  assert(s_idx_77_1 == s_idx_77_2);
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
}


