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
struct StreamBuffer_R000137_3713_0
{
  int capacity;
  int state;
  short tail;
  int buffer[3];
};
struct Vector3D_R000137_3713_1
{
  short heading;
  unsigned char norm_sq;
  short coord_x;
  int coord_y;
  short coord_z;
  int pitch;
  int buffer[3];
};
union TelemetryField_R000137_3713_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union PacketPayload_R000137_3713_1
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
void fn_R000137_3713_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_12_1 = local_arr_1[aux_1 % 3];
  int checksum_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_12_2 * 2)) & 127;
  int margin_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int margin_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (margin_89_1 > 49)
  {
    acc_1 = ((acc_1 + (margin_89_1 * 2)) + 5) & 127;
    aux_1 ^= margin_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - margin_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (margin_89_2 > 49)
  {
    acc_2 = ((acc_2 + (margin_89_2 * 2)) + 5) & 127;
    aux_2 ^= margin_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - margin_89_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_12_1 == checksum_12_2);
  assert(margin_89_1 == margin_89_2);
}

int fn_R000137_3713_0(int p0, int p1, int p2)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int checksum_12 = local_arr[aux % 3];
  acc = (acc + (checksum_12 * 2)) & 127;
  int margin_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (margin_89 > 49)
  {
    acc = ((acc + (margin_89 * 2)) + 5) & 127;
    aux ^= margin_89 & 15;
  }
  else
  {
    acc = ((acc - margin_89) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000137_3713_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_99_1 = local_arr_1[aux_1 % 3];
  int damping_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_99_1 == damping_99_2);
}

int fn_R000137_3713_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_99 = local_arr[aux % 3];
  acc = (acc + (damping_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int threshold_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_81_1 > 20)
  {
    acc_1 = ((acc_1 + (threshold_81_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_81_2 > 20)
  {
    acc_2 = ((acc_2 + (threshold_81_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int bound_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + bound_20_1) & 63;
  aux_2 = (aux_2 + bound_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_78_1 = local_arr_1[aux_1 % 3];
  int bound_78_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_78_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_78_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_81_1 == threshold_81_2);
  assert(bound_20_1 == bound_20_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_78_1 == bound_78_2);
}

int fn_R000137_3713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int threshold_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_81 > 20)
  {
    acc = ((acc + (threshold_81 * 2)) + 5) & 127;
    aux ^= threshold_81 & 15;
  }
  else
  {
    acc = ((acc - threshold_81) + 11) & 127;
    aux += 3;
  }
  int bound_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + bound_20) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_78 = local_arr[aux % 3];
  acc = (acc + (bound_78 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_3_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int quantum_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_89_1 > 31)
  {
    acc_1 = ((acc_1 + (quantum_89_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_89_2 > 31)
  {
    acc_2 = ((acc_2 + (quantum_89_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_89_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int accumulator_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_99_1) & 63;
  aux_2 = (aux_2 + accumulator_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_45_1 = local_arr_1[aux_1 % 3];
  int bound_45_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_45_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_45_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_89_1 == quantum_89_2);
  assert(accumulator_99_1 == accumulator_99_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_45_1 == bound_45_2);
}

int fn_R000137_3713_3(int p0, int p1)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int quantum_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_89 > 31)
  {
    acc = ((acc + (quantum_89 * 2)) + 5) & 127;
    aux ^= quantum_89 & 15;
  }
  else
  {
    acc = ((acc - quantum_89) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_99) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int bound_45 = local_arr[aux % 3];
  acc = (acc + (bound_45 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_31_1 = local_arr_1[aux_1 % 3];
  int pivot_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_31_2 * 2)) & 127;
  int stride_47_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_47_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_47_1)
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

  switch (stride_47_2)
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
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_31_1 == pivot_31_2);
  assert(stride_47_1 == stride_47_2);
}

int fn_R000137_3713_4(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int pivot_31 = local_arr[aux % 3];
  acc = (acc + (pivot_31 * 2)) & 127;
  int stride_47 = (aux + st.buffer[1]) & 3;
  switch (stride_47)
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

void fn_R000137_3713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_81_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_81_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_81_1)
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

  switch (segment_81_2)
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

  int delta_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_62_1) & 63;
  aux_2 = (aux_2 + delta_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_81_1 == segment_81_2);
  assert(delta_62_1 == delta_62_2);
}

int fn_R000137_3713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_81 = (aux + st.buffer[1]) & 3;
  switch (segment_81)
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

  int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_62) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000137_3713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int segment_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_41_1 > 25)
  {
    acc_1 = ((acc_1 + (segment_41_1 * 2)) + 5) & 127;
    aux_1 ^= segment_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_41_2 > 25)
  {
    acc_2 = ((acc_2 + (segment_41_2 * 2)) + 5) & 127;
    aux_2 ^= segment_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_41_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_12_1)
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

  switch (threshold_12_2)
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

  int phase_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_34_1) & 63;
  aux_2 = (aux_2 + phase_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_41_1 == segment_41_2);
  assert(threshold_12_1 == threshold_12_2);
  assert(phase_34_1 == phase_34_2);
}

int fn_R000137_3713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int segment_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_41 > 25)
  {
    acc = ((acc + (segment_41 * 2)) + 5) & 127;
    aux ^= segment_41 & 15;
  }
  else
  {
    acc = ((acc - segment_41) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_12 = (aux + st.buffer[1]) & 3;
  switch (threshold_12)
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

  int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000137_3713_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int cursor_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_74_1 > 33)
  {
    acc_1 = ((acc_1 + (cursor_74_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_74_2 > 33)
  {
    acc_2 = ((acc_2 + (cursor_74_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_74_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_90_1)
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

  switch (delta_90_2)
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

  int mask_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_57_1) & 63;
  aux_2 = (aux_2 + mask_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_74_1 == cursor_74_2);
  assert(delta_90_1 == delta_90_2);
  assert(mask_57_1 == mask_57_2);
}

int fn_R000137_3713_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int cursor_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_74 > 33)
  {
    acc = ((acc + (cursor_74 * 2)) + 5) & 127;
    aux ^= cursor_74 & 15;
  }
  else
  {
    acc = ((acc - cursor_74) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_90 = (aux + st.buffer[1]) & 3;
  switch (delta_90)
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

  int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000137_3713_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int anchor_86_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_86_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_86_1)
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

  switch (anchor_86_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_86_1 == anchor_86_2);
}

int fn_R000137_3713_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int anchor_86 = (aux + st.buffer[1]) & 3;
  switch (anchor_86)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int factor_18_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_18_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_18_1) & 63;
  aux_2 = (aux_2 + factor_18_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_22_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_22_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_22_1 > 42)
  {
    acc_1 = ((acc_1 + (threshold_22_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_22_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_22_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_22_2 > 42)
  {
    acc_2 = ((acc_2 + (threshold_22_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_22_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_22_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_91_1)
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

  switch (delta_91_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_49_1 = local_arr_1[aux_1 % 3];
  int accumulator_49_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_49_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_49_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_18_1 == factor_18_2);
  assert(threshold_22_1 == threshold_22_2);
  assert(delta_91_1 == delta_91_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_49_1 == accumulator_49_2);
}

int fn_R000137_3713_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int factor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_18) & 63;
  acc ^= aux;
  int threshold_22 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_22 > 42)
  {
    acc = ((acc + (threshold_22 * 2)) + 5) & 127;
    aux ^= threshold_22 & 15;
  }
  else
  {
    acc = ((acc - threshold_22) + 11) & 127;
    aux += 3;
  }
  int delta_91 = (aux + st.buffer[1]) & 3;
  switch (delta_91)
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

  int local_arr[3] = {4, 9, 15};
  int accumulator_49 = local_arr[aux % 3];
  acc = (acc + (accumulator_49 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_96_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_96_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_96_1 > 49)
  {
    acc_1 = ((acc_1 + (tracker_96_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_96_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_96_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_96_2 > 49)
  {
    acc_2 = ((acc_2 + (tracker_96_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_96_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_96_2) + 11) & 127;
    aux_2 += 3;
  }
  int weight_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_99_1) & 63;
  aux_2 = (aux_2 + weight_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_96_1 == tracker_96_2);
  assert(weight_99_1 == weight_99_2);
}

int fn_R000137_3713_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_96 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_96 > 49)
  {
    acc = ((acc + (tracker_96 * 2)) + 5) & 127;
    aux ^= tracker_96 & 15;
  }
  else
  {
    acc = ((acc - tracker_96) + 11) & 127;
    aux += 3;
  }
  int weight_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000137_3713_11_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int damping_35_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_35_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_35_1 > 22)
  {
    acc_1 = ((acc_1 + (damping_35_1 * 2)) + 5) & 127;
    aux_1 ^= damping_35_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_35_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_35_2 > 22)
  {
    acc_2 = ((acc_2 + (damping_35_2 * 2)) + 5) & 127;
    aux_2 ^= damping_35_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_35_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_35_1 == damping_35_2);
}

int fn_R000137_3713_11(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int damping_35 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_35 > 22)
  {
    acc = ((acc + (damping_35 * 2)) + 5) & 127;
    aux ^= damping_35 & 15;
  }
  else
  {
    acc = ((acc - damping_35) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_44_1)
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

  switch (quotient_44_2)
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

  int residue_79_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_79_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_79_1 > 24)
  {
    acc_1 = ((acc_1 + (residue_79_1 * 2)) + 5) & 127;
    aux_1 ^= residue_79_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_79_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_79_2 > 24)
  {
    acc_2 = ((acc_2 + (residue_79_2 * 2)) + 5) & 127;
    aux_2 ^= residue_79_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_79_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_37_1 = local_arr_1[aux_1 % 3];
  int delta_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_44_1 == quotient_44_2);
  assert(residue_79_1 == residue_79_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_37_1 == delta_37_2);
}

int fn_R000137_3713_12(int p0, int p1, int p2)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_44 = (aux + st.buffer[1]) & 3;
  switch (quotient_44)
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

  int residue_79 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_79 > 24)
  {
    acc = ((acc + (residue_79 * 2)) + 5) & 127;
    aux ^= residue_79 & 15;
  }
  else
  {
    acc = ((acc - residue_79) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_37 = local_arr[aux % 3];
  acc = (acc + (delta_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_41_1 = local_arr_1[aux_1 % 3];
  int sample_41_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_41_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_41_2 * 2)) & 127;
  int tracker_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_84_1 > 39)
  {
    acc_1 = ((acc_1 + (tracker_84_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_84_2 > 39)
  {
    acc_2 = ((acc_2 + (tracker_84_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_41_1 == sample_41_2);
  assert(tracker_84_1 == tracker_84_2);
}

int fn_R000137_3713_13(int p0, int p1)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int sample_41 = local_arr[aux % 3];
  acc = (acc + (sample_41 * 2)) & 127;
  int tracker_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_84 > 39)
  {
    acc = ((acc + (tracker_84 * 2)) + 5) & 127;
    aux ^= tracker_84 & 15;
  }
  else
  {
    acc = ((acc - tracker_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000137_3713_14_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int parity_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_28_1 > 35)
  {
    acc_1 = ((acc_1 + (parity_28_1 * 2)) + 5) & 127;
    aux_1 ^= parity_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_28_2 > 35)
  {
    acc_2 = ((acc_2 + (parity_28_2 * 2)) + 5) & 127;
    aux_2 ^= parity_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_28_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_28_1 == parity_28_2);
}

int fn_R000137_3713_14(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int parity_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_28 > 35)
  {
    acc = ((acc + (parity_28 * 2)) + 5) & 127;
    aux ^= parity_28 & 15;
  }
  else
  {
    acc = ((acc - parity_28) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int offset_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_46_1 > 20)
  {
    acc_1 = ((acc_1 + (offset_46_1 * 2)) + 5) & 127;
    aux_1 ^= offset_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_46_2 > 20)
  {
    acc_2 = ((acc_2 + (offset_46_2 * 2)) + 5) & 127;
    aux_2 ^= offset_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_46_2) + 11) & 127;
    aux_2 += 3;
  }
  int pivot_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_44_1)
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

  switch (pivot_44_2)
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

  int coefficient_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_44_1) & 63;
  aux_2 = (aux_2 + coefficient_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_96_1 = local_arr_1[aux_1 % 3];
  int phase_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_96_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_46_1 == offset_46_2);
  assert(pivot_44_1 == pivot_44_2);
  assert(coefficient_44_1 == coefficient_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_96_1 == phase_96_2);
}

int fn_R000137_3713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int offset_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_46 > 20)
  {
    acc = ((acc + (offset_46 * 2)) + 5) & 127;
    aux ^= offset_46 & 15;
  }
  else
  {
    acc = ((acc - offset_46) + 11) & 127;
    aux += 3;
  }
  int pivot_44 = (aux + st.buffer[1]) & 3;
  switch (pivot_44)
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

  int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int phase_96 = local_arr[aux % 3];
  acc = (acc + (phase_96 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int phase_87_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_87_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_87_1)
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

  switch (phase_87_2)
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
  int mask_34_1 = local_arr_1[aux_1 % 3];
  int mask_34_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_34_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_34_2 * 2)) & 127;
  int threshold_39_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_39_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_39_1) & 63;
  aux_2 = (aux_2 + threshold_39_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_87_1 == phase_87_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_34_1 == mask_34_2);
  assert(threshold_39_1 == threshold_39_2);
}

int fn_R000137_3713_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int phase_87 = (aux + st.buffer[1]) & 3;
  switch (phase_87)
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
  int mask_34 = local_arr[aux % 3];
  acc = (acc + (mask_34 * 2)) & 127;
  int threshold_39 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_39) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int metric_31_1 = local_arr_1[aux_1 % 3];
  int metric_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_31_2 * 2)) & 127;
  int accumulator_36_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_36_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_36_1) & 63;
  aux_2 = (aux_2 + accumulator_36_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int cursor_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (cursor_51_1)
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

  switch (cursor_51_2)
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

  int factor_63_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_63_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_63_1 > 21)
  {
    acc_1 = ((acc_1 + (factor_63_1 * 2)) + 5) & 127;
    aux_1 ^= factor_63_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_63_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_63_2 > 21)
  {
    acc_2 = ((acc_2 + (factor_63_2 * 2)) + 5) & 127;
    aux_2 ^= factor_63_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_63_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_31_1 == metric_31_2);
  assert(accumulator_36_1 == accumulator_36_2);
  assert(cursor_51_1 == cursor_51_2);
  assert(factor_63_1 == factor_63_2);
}

int fn_R000137_3713_17(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int metric_31 = local_arr[aux % 3];
  acc = (acc + (metric_31 * 2)) & 127;
  int accumulator_36 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_36) & 63;
  acc ^= aux;
  int cursor_51 = (aux + st.buffer[1]) & 3;
  switch (cursor_51)
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

  int factor_63 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_63 > 21)
  {
    acc = ((acc + (factor_63 * 2)) + 5) & 127;
    aux ^= factor_63 & 15;
  }
  else
  {
    acc = ((acc - factor_63) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000137_3713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int mask_38_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_38_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_38_1 > 45)
  {
    acc_1 = ((acc_1 + (mask_38_1 * 2)) + 5) & 127;
    aux_1 ^= mask_38_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_38_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_38_2 > 45)
  {
    acc_2 = ((acc_2 + (mask_38_2 * 2)) + 5) & 127;
    aux_2 ^= mask_38_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_38_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_95_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_95_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_95_1) & 63;
  aux_2 = (aux_2 + tally_95_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_38_1 == mask_38_2);
  assert(tally_95_1 == tally_95_2);
}

int fn_R000137_3713_18(int p0, int p1)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int mask_38 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_38 > 45)
  {
    acc = ((acc + (mask_38 * 2)) + 5) & 127;
    aux ^= mask_38 & 15;
  }
  else
  {
    acc = ((acc - mask_38) + 11) & 127;
    aux += 3;
  }
  int tally_95 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_95) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int delta_83_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_83_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_83_1)
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

  switch (delta_83_2)
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

  int quantum_66_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quantum_66_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quantum_66_1) & 63;
  aux_2 = (aux_2 + quantum_66_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_31_1 > 37)
  {
    acc_1 = ((acc_1 + (metric_31_1 * 2)) + 5) & 127;
    aux_1 ^= metric_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_31_2 > 37)
  {
    acc_2 = ((acc_2 + (metric_31_2 * 2)) + 5) & 127;
    aux_2 ^= metric_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_83_1 == delta_83_2);
  assert(quantum_66_1 == quantum_66_2);
  assert(metric_31_1 == metric_31_2);
}

int fn_R000137_3713_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int delta_83 = (aux + st.buffer[1]) & 3;
  switch (delta_83)
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

  int quantum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quantum_66) & 63;
  acc ^= aux;
  int metric_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_31 > 37)
  {
    acc = ((acc + (metric_31 * 2)) + 5) & 127;
    aux ^= metric_31 & 15;
  }
  else
  {
    acc = ((acc - metric_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000137_3713_20_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_89_1 = local_arr_1[aux_1 % 3];
  int factor_89_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_89_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_89_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_89_1 == factor_89_2);
}

int fn_R000137_3713_20(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_89 = local_arr[aux % 3];
  acc = (acc + (factor_89 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_70_1 = local_arr_1[aux_1 % 3];
  int damping_70_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_70_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_70_2 * 2)) & 127;
  int weight_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_13_1) & 63;
  aux_2 = (aux_2 + weight_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.capacity == st_2.capacity);
  assert(st_1.state == st_2.state);
  assert(st_1.tail == st_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_70_1 == damping_70_2);
  assert(weight_13_1 == weight_13_2);
}

int fn_R000137_3713_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R000137_3713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int damping_70 = local_arr[aux % 3];
  acc = (acc + (damping_70 * 2)) & 127;
  int weight_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000137_3713_22_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int delta_55_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_55_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_55_1) & 63;
  aux_2 = (aux_2 + delta_55_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_29_1 > 12)
  {
    acc_1 = ((acc_1 + (parity_29_1 * 2)) + 5) & 127;
    aux_1 ^= parity_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_29_2 > 12)
  {
    acc_2 = ((acc_2 + (parity_29_2 * 2)) + 5) & 127;
    aux_2 ^= parity_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(parity_29_1 == parity_29_2);
}

int fn_R000137_3713_22(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_55) & 63;
  acc ^= aux;
  int parity_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_29 > 12)
  {
    acc = ((acc + (parity_29 * 2)) + 5) & 127;
    aux ^= parity_29 & 15;
  }
  else
  {
    acc = ((acc - parity_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000137_3713_23_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st_1 = {0};
  struct Vector3D_R000137_3713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int coefficient_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int coefficient_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (coefficient_51_1 > 33)
  {
    acc_1 = ((acc_1 + (coefficient_51_1 * 2)) + 5) & 127;
    aux_1 ^= coefficient_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - coefficient_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (coefficient_51_2 > 33)
  {
    acc_2 = ((acc_2 + (coefficient_51_2 * 2)) + 5) & 127;
    aux_2 ^= coefficient_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - coefficient_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_36_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_36_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_36_1)
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

  switch (coefficient_36_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_22_1 = local_arr_1[aux_1 % 3];
  int margin_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_22_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_51_1 == coefficient_51_2);
  assert(coefficient_36_1 == coefficient_36_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_22_1 == margin_22_2);
}

int fn_R000137_3713_23(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000137_3713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int coefficient_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (coefficient_51 > 33)
  {
    acc = ((acc + (coefficient_51 * 2)) + 5) & 127;
    aux ^= coefficient_51 & 15;
  }
  else
  {
    acc = ((acc - coefficient_51) + 11) & 127;
    aux += 3;
  }
  int coefficient_36 = (aux + st.buffer[1]) & 3;
  switch (coefficient_36)
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

  int local_arr[3] = {4, 9, 15};
  int margin_22 = local_arr[aux % 3];
  acc = (acc + (margin_22 * 2)) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000137_0_1;
  int sec_r000137_0_2;
  int sec_r000137_1_1;
  int sec_r000137_1_2;
  int sec_r000137_2_1;
  int sec_r000137_2_2;
  int sec_r000137_3_1;
  int sec_r000137_3_2;
  int sec_r000137_4_1;
  int sec_r000137_4_2;
  int sec_r000137_5_1;
  int sec_r000137_5_2;
  int sec_r000137_6_1;
  int sec_r000137_6_2;
  int sec_r000137_7_1;
  int sec_r000137_7_2;
  int sec_r000137_8_1;
  int sec_r000137_8_2;
  int sec_r000137_9_1;
  int sec_r000137_9_2;
  int sec_r000137_10_1;
  int sec_r000137_10_2;
  int sec_r000137_11_1;
  int sec_r000137_11_2;
  int sec_r000137_12_1;
  int sec_r000137_12_2;
  int sec_r000137_13_1;
  int sec_r000137_13_2;
  int sec_r000137_14_1;
  int sec_r000137_14_2;
  int sec_r000137_15_1;
  int sec_r000137_15_2;
  int sec_r000137_16_1;
  int sec_r000137_16_2;
  int sec_r000137_17_1;
  int sec_r000137_17_2;
  int sec_r000137_18_1;
  int sec_r000137_18_2;
  int pub_r000137_0_1;
  int pub_r000137_0_2;
  int pub_r000137_1_1;
  int pub_r000137_1_2;
  int pub_r000137_2_1;
  int pub_r000137_2_2;
  int pub_r000137_3_1;
  int pub_r000137_3_2;
  int pub_r000137_4_1;
  int pub_r000137_4_2;
  int pub_r000137_5_1;
  int pub_r000137_5_2;
  int pub_r000137_6_1;
  int pub_r000137_6_2;
  int pub_r000137_7_1;
  int pub_r000137_7_2;
  int pub_r000137_8_1;
  int pub_r000137_8_2;
  int pub_r000137_9_1;
  int pub_r000137_9_2;
  int pub_r000137_10_1;
  int pub_r000137_10_2;
  int pub_r000137_11_1;
  int pub_r000137_11_2;
  int pub_r000137_12_1;
  int pub_r000137_12_2;
  int pub_r000137_13_1;
  int pub_r000137_13_2;
  int pub_r000137_14_1;
  int pub_r000137_14_2;
  int pub_r000137_15_1;
  int pub_r000137_15_2;
  int pub_r000137_16_1;
  int pub_r000137_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000137_0_1 >= (-100)) && (pub_r000137_0_1 <= 100));
  __CPROVER_assume((pub_r000137_0_2 >= (-100)) && (pub_r000137_0_2 <= 100));
  __CPROVER_assume((pub_r000137_1_1 >= (-100)) && (pub_r000137_1_1 <= 100));
  __CPROVER_assume((pub_r000137_1_2 >= (-100)) && (pub_r000137_1_2 <= 100));
  __CPROVER_assume((pub_r000137_2_1 >= (-100)) && (pub_r000137_2_1 <= 100));
  __CPROVER_assume((pub_r000137_2_2 >= (-100)) && (pub_r000137_2_2 <= 100));
  __CPROVER_assume((pub_r000137_3_1 >= (-100)) && (pub_r000137_3_1 <= 100));
  __CPROVER_assume((pub_r000137_3_2 >= (-100)) && (pub_r000137_3_2 <= 100));
  __CPROVER_assume((pub_r000137_4_1 >= (-100)) && (pub_r000137_4_1 <= 100));
  __CPROVER_assume((pub_r000137_4_2 >= (-100)) && (pub_r000137_4_2 <= 100));
  __CPROVER_assume((pub_r000137_5_1 >= (-100)) && (pub_r000137_5_1 <= 100));
  __CPROVER_assume((pub_r000137_5_2 >= (-100)) && (pub_r000137_5_2 <= 100));
  __CPROVER_assume((pub_r000137_6_1 >= (-100)) && (pub_r000137_6_1 <= 100));
  __CPROVER_assume((pub_r000137_6_2 >= (-100)) && (pub_r000137_6_2 <= 100));
  __CPROVER_assume((pub_r000137_7_1 >= (-100)) && (pub_r000137_7_1 <= 100));
  __CPROVER_assume((pub_r000137_7_2 >= (-100)) && (pub_r000137_7_2 <= 100));
  __CPROVER_assume((pub_r000137_8_1 >= (-100)) && (pub_r000137_8_1 <= 100));
  __CPROVER_assume((pub_r000137_8_2 >= (-100)) && (pub_r000137_8_2 <= 100));
  __CPROVER_assume((pub_r000137_9_1 >= (-100)) && (pub_r000137_9_1 <= 100));
  __CPROVER_assume((pub_r000137_9_2 >= (-100)) && (pub_r000137_9_2 <= 100));
  __CPROVER_assume((pub_r000137_10_1 >= (-100)) && (pub_r000137_10_1 <= 100));
  __CPROVER_assume((pub_r000137_10_2 >= (-100)) && (pub_r000137_10_2 <= 100));
  __CPROVER_assume((pub_r000137_11_1 >= (-100)) && (pub_r000137_11_1 <= 100));
  __CPROVER_assume((pub_r000137_11_2 >= (-100)) && (pub_r000137_11_2 <= 100));
  __CPROVER_assume((pub_r000137_12_1 >= (-100)) && (pub_r000137_12_1 <= 100));
  __CPROVER_assume((pub_r000137_12_2 >= (-100)) && (pub_r000137_12_2 <= 100));
  __CPROVER_assume((pub_r000137_13_1 >= (-100)) && (pub_r000137_13_1 <= 100));
  __CPROVER_assume((pub_r000137_13_2 >= (-100)) && (pub_r000137_13_2 <= 100));
  __CPROVER_assume((pub_r000137_14_1 >= (-100)) && (pub_r000137_14_1 <= 100));
  __CPROVER_assume((pub_r000137_14_2 >= (-100)) && (pub_r000137_14_2 <= 100));
  __CPROVER_assume((pub_r000137_15_1 >= (-100)) && (pub_r000137_15_1 <= 100));
  __CPROVER_assume((pub_r000137_15_2 >= (-100)) && (pub_r000137_15_2 <= 100));
  __CPROVER_assume((pub_r000137_16_1 >= (-100)) && (pub_r000137_16_1 <= 100));
  __CPROVER_assume((pub_r000137_16_2 >= (-100)) && (pub_r000137_16_2 <= 100));
  __CPROVER_assume((sec_r000137_0_1 >= 0) && (sec_r000137_0_1 <= 255));
  __CPROVER_assume((sec_r000137_0_2 >= 0) && (sec_r000137_0_2 <= 255));
  __CPROVER_assume((sec_r000137_1_1 >= 0) && (sec_r000137_1_1 <= 255));
  __CPROVER_assume((sec_r000137_1_2 >= 0) && (sec_r000137_1_2 <= 255));
  __CPROVER_assume((sec_r000137_2_1 >= 0) && (sec_r000137_2_1 <= 255));
  __CPROVER_assume((sec_r000137_2_2 >= 0) && (sec_r000137_2_2 <= 255));
  __CPROVER_assume((sec_r000137_3_1 >= 0) && (sec_r000137_3_1 <= 255));
  __CPROVER_assume((sec_r000137_3_2 >= 0) && (sec_r000137_3_2 <= 255));
  __CPROVER_assume((sec_r000137_4_1 >= 0) && (sec_r000137_4_1 <= 255));
  __CPROVER_assume((sec_r000137_4_2 >= 0) && (sec_r000137_4_2 <= 255));
  __CPROVER_assume((sec_r000137_5_1 >= 0) && (sec_r000137_5_1 <= 255));
  __CPROVER_assume((sec_r000137_5_2 >= 0) && (sec_r000137_5_2 <= 255));
  __CPROVER_assume((sec_r000137_6_1 >= 0) && (sec_r000137_6_1 <= 255));
  __CPROVER_assume((sec_r000137_6_2 >= 0) && (sec_r000137_6_2 <= 255));
  __CPROVER_assume((sec_r000137_7_1 >= 0) && (sec_r000137_7_1 <= 255));
  __CPROVER_assume((sec_r000137_7_2 >= 0) && (sec_r000137_7_2 <= 255));
  __CPROVER_assume((sec_r000137_8_1 >= 0) && (sec_r000137_8_1 <= 255));
  __CPROVER_assume((sec_r000137_8_2 >= 0) && (sec_r000137_8_2 <= 255));
  __CPROVER_assume((sec_r000137_9_1 >= 0) && (sec_r000137_9_1 <= 255));
  __CPROVER_assume((sec_r000137_9_2 >= 0) && (sec_r000137_9_2 <= 255));
  __CPROVER_assume((sec_r000137_10_1 >= 0) && (sec_r000137_10_1 <= 255));
  __CPROVER_assume((sec_r000137_10_2 >= 0) && (sec_r000137_10_2 <= 255));
  __CPROVER_assume((sec_r000137_11_1 >= 0) && (sec_r000137_11_1 <= 255));
  __CPROVER_assume((sec_r000137_11_2 >= 0) && (sec_r000137_11_2 <= 255));
  __CPROVER_assume((sec_r000137_12_1 >= 0) && (sec_r000137_12_1 <= 255));
  __CPROVER_assume((sec_r000137_12_2 >= 0) && (sec_r000137_12_2 <= 255));
  __CPROVER_assume((sec_r000137_13_1 >= 0) && (sec_r000137_13_1 <= 255));
  __CPROVER_assume((sec_r000137_13_2 >= 0) && (sec_r000137_13_2 <= 255));
  __CPROVER_assume((sec_r000137_14_1 >= 0) && (sec_r000137_14_1 <= 255));
  __CPROVER_assume((sec_r000137_14_2 >= 0) && (sec_r000137_14_2 <= 255));
  __CPROVER_assume((sec_r000137_15_1 >= 0) && (sec_r000137_15_1 <= 255));
  __CPROVER_assume((sec_r000137_15_2 >= 0) && (sec_r000137_15_2 <= 255));
  __CPROVER_assume((sec_r000137_16_1 >= 0) && (sec_r000137_16_1 <= 255));
  __CPROVER_assume((sec_r000137_16_2 >= 0) && (sec_r000137_16_2 <= 255));
  __CPROVER_assume((sec_r000137_17_1 >= 0) && (sec_r000137_17_1 <= 255));
  __CPROVER_assume((sec_r000137_17_2 >= 0) && (sec_r000137_17_2 <= 255));
  __CPROVER_assume((sec_r000137_18_1 >= 0) && (sec_r000137_18_1 <= 255));
  __CPROVER_assume((sec_r000137_18_2 >= 0) && (sec_r000137_18_2 <= 255));
  struct StreamBuffer_R000137_3713_0 st_var_0_1 = {0};
  struct StreamBuffer_R000137_3713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000137_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000137_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000137_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000137_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000137_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000137_0_2 + 7) & 15;
  struct Vector3D_R000137_3713_1 st_var_1_1 = {0};
  struct Vector3D_R000137_3713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000137_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000137_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000137_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000137_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000137_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000137_0_2 + 9) & 15;
  union TelemetryField_R000137_3713_0 u_var_1;
  union TelemetryField_R000137_3713_0 u_var_2;
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
  int stage_v_1_1 = 0;
  int stage_v_1_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_1_1 = ((stage_v_1_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_1_2 = ((stage_v_1_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  int stage_v_2_1 = table_1[2];
  int stage_v_2_2 = table_2[2];
  table_1[2] = (table_1[3] + 5) & 63;
  table_2[2] = (table_2[3] + 5) & 63;
  out_sink_1 = (out_sink_1 + stage_v_2_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_2_2) & 255;
  int stage_v_3_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_3_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_3_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_3_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 5) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 5) & 15;
  int stage_v_4_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_4_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  chk_sum_1 ^= stage_v_4_1;
  chk_sum_2 ^= stage_v_4_2;
  int stage_v_5_1 = ((st_var_1_1.buffer[2] * 2) + 22) & 63;
  int stage_v_5_2 = ((st_var_1_2.buffer[2] * 2) + 22) & 63;
  if (stage_v_5_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + stage_v_5_1) - 5) & 255;
    if (stage_v_5_1 > 38)
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
  if (stage_v_5_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + stage_v_5_2) - 5) & 255;
    if (stage_v_5_2 > 38)
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
  int stage_v_6_1 = 0;
  int stage_v_6_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_6_1 = ((stage_v_6_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_6_2 = ((stage_v_6_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 8) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 8) & 15;
  int stage_v_7_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_7_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_7_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_7_2) & 255;
  chk_sum_1 ^= stage_v_7_1;
  chk_sum_2 ^= stage_v_7_2;
  int stage_v_8_1 = 0;
  int stage_v_8_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_8_1 = ((stage_v_8_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_8_2 = ((stage_v_8_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  int stage_v_9_1 = table_1[1];
  int stage_v_9_2 = table_2[1];
  table_1[1] = (table_1[2] + 19) & 63;
  table_2[1] = (table_2[2] + 19) & 63;
  out_sink_1 = (out_sink_1 + stage_v_9_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_9_2) & 255;
  int stage_v_10_1 = table_1[2];
  int stage_v_10_2 = table_2[2];
  table_1[2] = (table_1[3] + 21) & 63;
  table_2[2] = (table_2[3] + 21) & 63;
  out_sink_1 = (out_sink_1 + stage_v_10_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_10_2) & 255;
  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
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

  switch (stage_v_11_2)
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

  int stage_v_12_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (17 & 31);
  int stage_v_12_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (17 & 31);
  out_sink_1 = (out_sink_1 + stage_v_12_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_12_2) & 255;
  chk_sum_1 ^= (stage_v_12_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_12_2 << 1) & 127;
  int stage_v_13_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_13_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
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
  int stage_v_15_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (20 & 31);
  int stage_v_15_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (20 & 31);
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  chk_sum_1 ^= (stage_v_15_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_15_2 << 1) & 127;
  int stage_v_16_1 = ((st_var_0_1.buffer[1] * 2) + 55) & 63;
  int stage_v_16_2 = ((st_var_0_2.buffer[1] * 2) + 55) & 63;
  if (stage_v_16_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_16_1) - 5) & 255;
    if (stage_v_16_1 > 33)
    {
      chk_sum_1 ^= stage_v_16_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_16_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_16_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_16_2) - 5) & 255;
    if (stage_v_16_2 > 33)
    {
      chk_sum_2 ^= stage_v_16_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_16_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_17_1 = (st_var_1_1.buffer[0] ^ 20) & 3;
  int stage_v_17_2 = (st_var_1_2.buffer[0] ^ 20) & 3;
  switch (stage_v_17_1)
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

  switch (stage_v_17_2)
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
  if (stage_v_19_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + stage_v_19_1) - 5) & 255;
    if (stage_v_19_1 > 54)
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
  if (stage_v_19_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + stage_v_19_2) - 5) & 255;
    if (stage_v_19_2 > 54)
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
  int stage_v_20_1 = table_1[0];
  int stage_v_20_2 = table_2[0];
  table_1[0] = (table_1[1] + 41) & 63;
  table_2[0] = (table_2[1] + 41) & 63;
  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (26 & 31);
  int stage_v_21_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (26 & 31);
  out_sink_1 = (out_sink_1 + stage_v_21_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_21_2) & 255;
  chk_sum_1 ^= (stage_v_21_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_21_2 << 1) & 127;
  int stage_v_22_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (27 & 31);
  int stage_v_22_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (27 & 31);
  out_sink_1 = (out_sink_1 + stage_v_22_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_22_2) & 255;
  chk_sum_1 ^= (stage_v_22_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_22_2 << 1) & 127;
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
  int stage_v_24_1 = 0;
  int stage_v_24_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_24_1 = ((stage_v_24_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_24_2 = ((stage_v_24_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_24_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_24_2) & 255;
  int stage_v_25_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_25_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_26_1 = table_1[2];
  int stage_v_26_2 = table_2[2];
  table_1[2] = (table_1[3] + 53) & 63;
  table_2[2] = (table_2[3] + 53) & 63;
  out_sink_1 = (out_sink_1 + stage_v_26_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_26_2) & 255;
  int stage_v_27_1 = 0;
  int stage_v_27_2 = 0;
  if ((sec_r000137_8_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_27_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_27_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((sec_r000137_8_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_27_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_27_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_27_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_27_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_27_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  if ((sec_r000137_2_1 & 1) != 0)
  {
    if ((sec_r000137_15_1 & 2) != 0)
    {
      stage_v_28_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_28_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((sec_r000137_2_2 & 1) != 0)
  {
    if ((sec_r000137_15_2 & 2) != 0)
    {
      stage_v_28_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_28_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_28_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_29_1 = (pub_r000137_15_1 + 31) & 127;
    }
    else
    {
      stage_v_29_1 = (pub_r000137_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_1 = (pub_r000137_15_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_29_2 = (pub_r000137_15_2 + 31) & 127;
    }
    else
    {
      stage_v_29_2 = (pub_r000137_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_29_2 = (pub_r000137_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  int stage_v_30_1 = 0;
  int stage_v_30_2 = 0;
  if ((sec_r000137_3_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_30_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_30_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((sec_r000137_3_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_30_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_30_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_30_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  int stage_v_31_1 = 0;
  int stage_v_31_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000137_8_1 & 2) != 0)
    {
      stage_v_31_1 = (pub_r000137_13_1 + 31) & 127;
    }
    else
    {
      stage_v_31_1 = (pub_r000137_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_1 = (pub_r000137_13_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000137_8_2 & 2) != 0)
    {
      stage_v_31_2 = (pub_r000137_13_2 + 31) & 127;
    }
    else
    {
      stage_v_31_2 = (pub_r000137_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_31_2 = (pub_r000137_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  int stage_v_32_1 = 0;
  int stage_v_32_2 = 0;
  if ((sec_r000137_16_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_32_1 = (pub_r000137_13_1 + 31) & 127;
    }
    else
    {
      stage_v_32_1 = (pub_r000137_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_1 = (pub_r000137_13_1 + 7) & 127;
  }
  if ((sec_r000137_16_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_32_2 = (pub_r000137_13_2 + 31) & 127;
    }
    else
    {
      stage_v_32_2 = (pub_r000137_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_32_2 = (pub_r000137_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_32_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_32_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  int stage_v_33_1 = 0;
  int stage_v_33_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_33_1 = (pub_r000137_16_1 + 31) & 127;
    }
    else
    {
      stage_v_33_1 = (pub_r000137_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_1 = (pub_r000137_16_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_33_2 = (pub_r000137_16_2 + 31) & 127;
    }
    else
    {
      stage_v_33_2 = (pub_r000137_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_33_2 = (pub_r000137_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  int stage_v_34_1 = 0;
  int stage_v_34_2 = 0;
  if ((sec_r000137_6_1 & 1) != 0)
  {
    if ((sec_r000137_12_1 & 2) != 0)
    {
      stage_v_34_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_34_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((sec_r000137_6_2 & 1) != 0)
  {
    if ((sec_r000137_12_2 & 2) != 0)
    {
      stage_v_34_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_34_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_34_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_34_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_34_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  int stage_v_35_1 = 0;
  int stage_v_35_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_35_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_35_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_35_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_35_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_35_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_35_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_35_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_35_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_35_2) & 255;
  int stage_v_36_1 = 0;
  int stage_v_36_2 = 0;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((sec_r000137_10_1 & 2) != 0)
    {
      stage_v_36_1 = (pub_r000137_15_1 + 31) & 127;
    }
    else
    {
      stage_v_36_1 = (pub_r000137_15_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_1 = (pub_r000137_15_1 + 7) & 127;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((sec_r000137_10_2 & 2) != 0)
    {
      stage_v_36_2 = (pub_r000137_15_2 + 31) & 127;
    }
    else
    {
      stage_v_36_2 = (pub_r000137_15_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_36_2 = (pub_r000137_15_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_36_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_36_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  int stage_v_37_1 = 0;
  int stage_v_37_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_37_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_37_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_37_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_37_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_37_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = 0;
  int stage_v_38_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000137_0_1 & 2) != 0)
    {
      stage_v_38_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_38_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000137_0_2 & 2) != 0)
    {
      stage_v_38_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_38_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_38_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_38_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_38_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_38_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_38_2) & 255;
  int stage_v_39_1 = 0;
  int stage_v_39_2 = 0;
  if ((sec_r000137_13_1 & 1) != 0)
  {
    if ((sec_r000137_9_1 & 2) != 0)
    {
      stage_v_39_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_39_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((sec_r000137_13_2 & 1) != 0)
  {
    if ((sec_r000137_9_2 & 2) != 0)
    {
      stage_v_39_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_39_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_39_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = 0;
  int stage_v_40_2 = 0;
  if ((sec_r000137_18_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_40_1 = (pub_r000137_11_1 + 31) & 127;
    }
    else
    {
      stage_v_40_1 = (pub_r000137_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_1 = (pub_r000137_11_1 + 7) & 127;
  }
  if ((sec_r000137_18_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_40_2 = (pub_r000137_11_2 + 31) & 127;
    }
    else
    {
      stage_v_40_2 = (pub_r000137_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_40_2 = (pub_r000137_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_40_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_40_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  int stage_v_41_1 = 0;
  int stage_v_41_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_41_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_41_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_41_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_41_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_41_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_41_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_41_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  int stage_v_42_1 = 0;
  int stage_v_42_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_42_1 = (pub_r000137_10_1 + 31) & 127;
    }
    else
    {
      stage_v_42_1 = (pub_r000137_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_1 = (pub_r000137_10_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_42_2 = (pub_r000137_10_2 + 31) & 127;
    }
    else
    {
      stage_v_42_2 = (pub_r000137_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_42_2 = (pub_r000137_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_42_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_42_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_43_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_43_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_43_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_43_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_43_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_43_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = 0;
  int stage_v_44_2 = 0;
  if ((stage_v_29_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_44_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_44_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((stage_v_29_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_44_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_44_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_44_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = 0;
  int stage_v_45_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_45_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_45_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_45_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_45_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_45_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_45_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_45_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  int stage_v_46_1 = 0;
  int stage_v_46_2 = 0;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_46_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_46_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_46_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_46_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_46_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  int stage_v_47_1 = 0;
  int stage_v_47_2 = 0;
  if ((sec_r000137_0_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_47_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_47_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((sec_r000137_0_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_47_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_47_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_47_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_47_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_47_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  int stage_v_48_1 = 0;
  int stage_v_48_2 = 0;
  if ((sec_r000137_3_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_48_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_48_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((sec_r000137_3_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_48_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_48_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_48_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_48_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_48_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_48_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_48_2) & 255;
  int stage_v_49_1 = 0;
  int stage_v_49_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000137_5_1 & 2) != 0)
    {
      stage_v_49_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_49_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000137_5_2 & 2) != 0)
    {
      stage_v_49_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_49_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_49_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_49_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_49_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  int stage_v_50_1 = 0;
  int stage_v_50_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_50_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_50_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_50_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_50_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_50_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_50_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = 0;
  int stage_v_51_2 = 0;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_51_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_51_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_51_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_51_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_51_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_51_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = 0;
  int stage_v_52_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000137_8_1 & 2) != 0)
    {
      stage_v_52_1 = (pub_r000137_11_1 + 31) & 127;
    }
    else
    {
      stage_v_52_1 = (pub_r000137_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_1 = (pub_r000137_11_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000137_8_2 & 2) != 0)
    {
      stage_v_52_2 = (pub_r000137_11_2 + 31) & 127;
    }
    else
    {
      stage_v_52_2 = (pub_r000137_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_52_2 = (pub_r000137_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_52_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_52_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  int stage_v_53_1 = 0;
  int stage_v_53_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_53_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_53_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_53_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_53_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_53_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_53_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_53_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_53_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_53_2) & 255;
  int stage_v_54_1 = 0;
  int stage_v_54_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_54_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_54_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_54_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_54_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_54_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_54_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_54_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000137_6_1 & 2) != 0)
    {
      stage_v_55_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_55_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000137_6_2 & 2) != 0)
    {
      stage_v_55_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_55_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_55_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = 0;
  int stage_v_56_2 = 0;
  if ((sec_r000137_16_1 & 1) != 0)
  {
    if ((sec_r000137_12_1 & 2) != 0)
    {
      stage_v_56_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_56_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((sec_r000137_16_2 & 1) != 0)
  {
    if ((sec_r000137_12_2 & 2) != 0)
    {
      stage_v_56_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_56_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_56_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_56_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_56_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  int stage_v_57_1 = 0;
  int stage_v_57_2 = 0;
  if ((sec_r000137_4_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_57_1 = (pub_r000137_10_1 + 31) & 127;
    }
    else
    {
      stage_v_57_1 = (pub_r000137_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_1 = (pub_r000137_10_1 + 7) & 127;
  }
  if ((sec_r000137_4_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_57_2 = (pub_r000137_10_2 + 31) & 127;
    }
    else
    {
      stage_v_57_2 = (pub_r000137_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_57_2 = (pub_r000137_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_57_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_57_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  int stage_v_58_1 = 0;
  int stage_v_58_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000137_0_1 & 2) != 0)
    {
      stage_v_58_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_58_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000137_0_2 & 2) != 0)
    {
      stage_v_58_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_58_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_58_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  if ((sec_r000137_8_1 & 1) != 0)
  {
    if ((sec_r000137_8_1 & 2) != 0)
    {
      stage_v_59_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_59_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((sec_r000137_8_2 & 1) != 0)
  {
    if ((sec_r000137_8_2 & 2) != 0)
    {
      stage_v_59_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_59_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_59_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = 0;
  int stage_v_60_2 = 0;
  if ((sec_r000137_10_1 & 1) != 0)
  {
    if ((sec_r000137_17_1 & 2) != 0)
    {
      stage_v_60_1 = (pub_r000137_16_1 + 31) & 127;
    }
    else
    {
      stage_v_60_1 = (pub_r000137_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_1 = (pub_r000137_16_1 + 7) & 127;
  }
  if ((sec_r000137_10_2 & 1) != 0)
  {
    if ((sec_r000137_17_2 & 2) != 0)
    {
      stage_v_60_2 = (pub_r000137_16_2 + 31) & 127;
    }
    else
    {
      stage_v_60_2 = (pub_r000137_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_60_2 = (pub_r000137_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_60_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = 0;
  int stage_v_61_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_61_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_61_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_61_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_61_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_61_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_61_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_61_2) & 255;
  int stage_v_62_1 = 0;
  int stage_v_62_2 = 0;
  if ((stage_v_45_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_62_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_62_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_45_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_62_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_62_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_62_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  int stage_v_63_1 = 0;
  int stage_v_63_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_63_1 = (pub_r000137_14_1 + 31) & 127;
    }
    else
    {
      stage_v_63_1 = (pub_r000137_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_1 = (pub_r000137_14_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_63_2 = (pub_r000137_14_2 + 31) & 127;
    }
    else
    {
      stage_v_63_2 = (pub_r000137_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_63_2 = (pub_r000137_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  int stage_v_64_1 = 0;
  int stage_v_64_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_64_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_64_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_64_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_64_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_64_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  int stage_v_65_1 = 0;
  int stage_v_65_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_65_1 = (pub_r000137_16_1 + 31) & 127;
    }
    else
    {
      stage_v_65_1 = (pub_r000137_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_1 = (pub_r000137_16_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_65_2 = (pub_r000137_16_2 + 31) & 127;
    }
    else
    {
      stage_v_65_2 = (pub_r000137_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_65_2 = (pub_r000137_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  int stage_v_66_1 = 0;
  int stage_v_66_2 = 0;
  if ((sec_r000137_2_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_66_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_66_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((sec_r000137_2_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_66_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_66_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_66_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = 0;
  int stage_v_67_2 = 0;
  if ((sec_r000137_13_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_67_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_67_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((sec_r000137_13_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_67_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_67_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_67_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_67_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_67_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  int stage_v_68_1 = 0;
  int stage_v_68_2 = 0;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_68_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_68_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_68_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_68_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_68_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  int stage_v_69_1 = 0;
  int stage_v_69_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_69_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_69_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_69_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_69_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_69_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_69_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_69_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  int stage_v_70_1 = 0;
  int stage_v_70_2 = 0;
  if ((sec_r000137_16_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_70_1 = (pub_r000137_0_1 + 31) & 127;
    }
    else
    {
      stage_v_70_1 = (pub_r000137_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_1 = (pub_r000137_0_1 + 7) & 127;
  }
  if ((sec_r000137_16_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_70_2 = (pub_r000137_0_2 + 31) & 127;
    }
    else
    {
      stage_v_70_2 = (pub_r000137_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_70_2 = (pub_r000137_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_70_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_70_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r000137_0_1 & 2) != 0)
    {
      stage_v_71_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_71_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r000137_0_2 & 2) != 0)
    {
      stage_v_71_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_71_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_71_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  if ((sec_r000137_8_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_72_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_72_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((sec_r000137_8_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_72_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_72_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_72_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = 0;
  int stage_v_73_2 = 0;
  if ((sec_r000137_15_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_73_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_73_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((sec_r000137_15_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_73_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_73_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_73_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = 0;
  int stage_v_74_2 = 0;
  if ((sec_r000137_18_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_74_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_74_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((sec_r000137_18_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_74_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_74_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_74_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_74_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_74_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_74_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_74_2) & 255;
  int stage_v_75_1 = 0;
  int stage_v_75_2 = 0;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((sec_r000137_9_1 & 2) != 0)
    {
      stage_v_75_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_75_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((sec_r000137_9_2 & 2) != 0)
    {
      stage_v_75_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_75_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_75_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_75_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_75_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  int stage_v_76_1 = 0;
  int stage_v_76_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_76_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_76_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_76_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_76_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_76_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_76_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_76_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_76_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_76_2) & 255;
  int stage_v_77_1 = 0;
  int stage_v_77_2 = 0;
  if ((sec_r000137_4_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_77_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_77_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((sec_r000137_4_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_77_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_77_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_77_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_77_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  if ((sec_r000137_18_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_78_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_78_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((sec_r000137_18_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_78_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_78_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_78_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = 0;
  int stage_v_79_2 = 0;
  if ((sec_r000137_1_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_79_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_79_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((sec_r000137_1_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_79_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_79_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_79_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_79_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_79_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_79_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_79_2) & 255;
  int stage_v_80_1 = 0;
  int stage_v_80_2 = 0;
  if ((sec_r000137_3_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_80_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_80_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((sec_r000137_3_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_80_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_80_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_80_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_80_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_80_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_80_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_80_2) & 255;
  int stage_v_81_1 = 0;
  int stage_v_81_2 = 0;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((sec_r000137_11_1 & 2) != 0)
    {
      stage_v_81_1 = (pub_r000137_13_1 + 31) & 127;
    }
    else
    {
      stage_v_81_1 = (pub_r000137_13_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_1 = (pub_r000137_13_1 + 7) & 127;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((sec_r000137_11_2 & 2) != 0)
    {
      stage_v_81_2 = (pub_r000137_13_2 + 31) & 127;
    }
    else
    {
      stage_v_81_2 = (pub_r000137_13_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_81_2 = (pub_r000137_13_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  int stage_v_82_1 = 0;
  int stage_v_82_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_82_1 = (pub_r000137_11_1 + 31) & 127;
    }
    else
    {
      stage_v_82_1 = (pub_r000137_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_1 = (pub_r000137_11_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_82_2 = (pub_r000137_11_2 + 31) & 127;
    }
    else
    {
      stage_v_82_2 = (pub_r000137_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_82_2 = (pub_r000137_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  int stage_v_83_1 = 0;
  int stage_v_83_2 = 0;
  if ((stage_v_74_1 & 1) != 0)
  {
    if ((sec_r000137_15_1 & 2) != 0)
    {
      stage_v_83_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_83_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_74_2 & 1) != 0)
  {
    if ((sec_r000137_15_2 & 2) != 0)
    {
      stage_v_83_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_83_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_83_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = 0;
  int stage_v_84_2 = 0;
  if ((stage_v_53_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_84_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_84_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_53_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_84_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_84_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_84_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_84_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_84_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  int stage_v_85_1 = 0;
  int stage_v_85_2 = 0;
  if ((sec_r000137_12_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_85_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_85_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((sec_r000137_12_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_85_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_85_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_85_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_85_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = 0;
  int stage_v_86_2 = 0;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_86_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_86_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_86_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_86_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_86_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_86_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_86_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  int stage_v_87_1 = 0;
  int stage_v_87_2 = 0;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((sec_r000137_12_1 & 2) != 0)
    {
      stage_v_87_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_87_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((sec_r000137_12_2 & 2) != 0)
    {
      stage_v_87_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_87_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_87_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_87_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_87_2) & 255;
  int stage_v_88_1 = 0;
  int stage_v_88_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000137_5_1 & 2) != 0)
    {
      stage_v_88_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_88_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000137_5_2 & 2) != 0)
    {
      stage_v_88_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_88_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_88_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_88_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_88_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = 0;
  int stage_v_89_2 = 0;
  if ((sec_r000137_0_1 & 1) != 0)
  {
    if ((sec_r000137_10_1 & 2) != 0)
    {
      stage_v_89_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_89_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((sec_r000137_0_2 & 1) != 0)
  {
    if ((sec_r000137_10_2 & 2) != 0)
    {
      stage_v_89_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_89_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_89_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_89_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_89_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = 0;
  int stage_v_90_2 = 0;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_90_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_90_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_90_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_90_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_90_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_90_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_90_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = 0;
  int stage_v_91_2 = 0;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_91_1 = (pub_r000137_0_1 + 31) & 127;
    }
    else
    {
      stage_v_91_1 = (pub_r000137_0_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_1 = (pub_r000137_0_1 + 7) & 127;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_91_2 = (pub_r000137_0_2 + 31) & 127;
    }
    else
    {
      stage_v_91_2 = (pub_r000137_0_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_91_2 = (pub_r000137_0_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_91_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_91_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = 0;
  int stage_v_92_2 = 0;
  if ((stage_v_68_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_92_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_92_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((stage_v_68_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_92_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_92_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_92_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_92_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_92_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = 0;
  int stage_v_93_2 = 0;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r000137_10_1 & 2) != 0)
    {
      stage_v_93_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_93_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r000137_10_2 & 2) != 0)
    {
      stage_v_93_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_93_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_93_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_93_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_93_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = 0;
  int stage_v_94_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000137_0_1 & 2) != 0)
    {
      stage_v_94_1 = (pub_r000137_9_1 + 31) & 127;
    }
    else
    {
      stage_v_94_1 = (pub_r000137_9_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_1 = (pub_r000137_9_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000137_0_2 & 2) != 0)
    {
      stage_v_94_2 = (pub_r000137_9_2 + 31) & 127;
    }
    else
    {
      stage_v_94_2 = (pub_r000137_9_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_94_2 = (pub_r000137_9_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_94_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_94_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = 0;
  int stage_v_95_2 = 0;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_95_1 = (pub_r000137_10_1 + 31) & 127;
    }
    else
    {
      stage_v_95_1 = (pub_r000137_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_1 = (pub_r000137_10_1 + 7) & 127;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_95_2 = (pub_r000137_10_2 + 31) & 127;
    }
    else
    {
      stage_v_95_2 = (pub_r000137_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_95_2 = (pub_r000137_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_95_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_95_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = 0;
  int stage_v_96_2 = 0;
  if ((stage_v_82_1 & 1) != 0)
  {
    if ((sec_r000137_0_1 & 2) != 0)
    {
      stage_v_96_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_96_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((stage_v_82_2 & 1) != 0)
  {
    if ((sec_r000137_0_2 & 2) != 0)
    {
      stage_v_96_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_96_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_96_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_96_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_96_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = 0;
  int stage_v_97_2 = 0;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_97_1 = (pub_r000137_16_1 + 31) & 127;
    }
    else
    {
      stage_v_97_1 = (pub_r000137_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_1 = (pub_r000137_16_1 + 7) & 127;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_97_2 = (pub_r000137_16_2 + 31) & 127;
    }
    else
    {
      stage_v_97_2 = (pub_r000137_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_97_2 = (pub_r000137_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_97_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_97_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = 0;
  int stage_v_98_2 = 0;
  if ((stage_v_63_1 & 1) != 0)
  {
    if ((sec_r000137_18_1 & 2) != 0)
    {
      stage_v_98_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_98_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_63_2 & 1) != 0)
  {
    if ((sec_r000137_18_2 & 2) != 0)
    {
      stage_v_98_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_98_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_98_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_98_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_98_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = 0;
  int stage_v_99_2 = 0;
  if ((stage_v_41_1 & 1) != 0)
  {
    if ((sec_r000137_8_1 & 2) != 0)
    {
      stage_v_99_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_99_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((stage_v_41_2 & 1) != 0)
  {
    if ((sec_r000137_8_2 & 2) != 0)
    {
      stage_v_99_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_99_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_99_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_99_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_99_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = 0;
  int stage_v_100_2 = 0;
  if ((sec_r000137_6_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_100_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_100_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((sec_r000137_6_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_100_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_100_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_100_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_100_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_100_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = 0;
  int stage_v_101_2 = 0;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_101_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_101_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_101_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_101_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_101_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_101_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_101_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = 0;
  int stage_v_102_2 = 0;
  if ((sec_r000137_12_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_102_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_102_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((sec_r000137_12_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_102_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_102_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_102_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_102_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_102_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = 0;
  int stage_v_103_2 = 0;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((sec_r000137_6_1 & 2) != 0)
    {
      stage_v_103_1 = (pub_r000137_8_1 + 31) & 127;
    }
    else
    {
      stage_v_103_1 = (pub_r000137_8_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_1 = (pub_r000137_8_1 + 7) & 127;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((sec_r000137_6_2 & 2) != 0)
    {
      stage_v_103_2 = (pub_r000137_8_2 + 31) & 127;
    }
    else
    {
      stage_v_103_2 = (pub_r000137_8_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_103_2 = (pub_r000137_8_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_103_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_103_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = 0;
  int stage_v_104_2 = 0;
  if ((sec_r000137_14_1 & 1) != 0)
  {
    if ((sec_r000137_7_1 & 2) != 0)
    {
      stage_v_104_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_104_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((sec_r000137_14_2 & 1) != 0)
  {
    if ((sec_r000137_7_2 & 2) != 0)
    {
      stage_v_104_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_104_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_104_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_104_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_104_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = 0;
  int stage_v_105_2 = 0;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_105_1 = (pub_r000137_14_1 + 31) & 127;
    }
    else
    {
      stage_v_105_1 = (pub_r000137_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_1 = (pub_r000137_14_1 + 7) & 127;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_105_2 = (pub_r000137_14_2 + 31) & 127;
    }
    else
    {
      stage_v_105_2 = (pub_r000137_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_105_2 = (pub_r000137_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_105_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_105_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = 0;
  int stage_v_106_2 = 0;
  if ((sec_r000137_17_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_106_1 = (pub_r000137_12_1 + 31) & 127;
    }
    else
    {
      stage_v_106_1 = (pub_r000137_12_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_1 = (pub_r000137_12_1 + 7) & 127;
  }
  if ((sec_r000137_17_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_106_2 = (pub_r000137_12_2 + 31) & 127;
    }
    else
    {
      stage_v_106_2 = (pub_r000137_12_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_106_2 = (pub_r000137_12_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_106_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_106_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = 0;
  int stage_v_107_2 = 0;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r000137_6_1 & 2) != 0)
    {
      stage_v_107_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_107_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r000137_6_2 & 2) != 0)
    {
      stage_v_107_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_107_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_107_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_107_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_107_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = 0;
  int stage_v_108_2 = 0;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r000137_10_1 & 2) != 0)
    {
      stage_v_108_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_108_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r000137_10_2 & 2) != 0)
    {
      stage_v_108_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_108_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_108_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_108_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_108_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = 0;
  int stage_v_109_2 = 0;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r000137_2_1 & 2) != 0)
    {
      stage_v_109_1 = (pub_r000137_7_1 + 31) & 127;
    }
    else
    {
      stage_v_109_1 = (pub_r000137_7_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_1 = (pub_r000137_7_1 + 7) & 127;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r000137_2_2 & 2) != 0)
    {
      stage_v_109_2 = (pub_r000137_7_2 + 31) & 127;
    }
    else
    {
      stage_v_109_2 = (pub_r000137_7_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_109_2 = (pub_r000137_7_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_109_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_109_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = 0;
  int stage_v_110_2 = 0;
  if ((sec_r000137_0_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_110_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_110_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((sec_r000137_0_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_110_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_110_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_110_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_110_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_110_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = 0;
  int stage_v_111_2 = 0;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((sec_r000137_6_1 & 2) != 0)
    {
      stage_v_111_1 = (pub_r000137_16_1 + 31) & 127;
    }
    else
    {
      stage_v_111_1 = (pub_r000137_16_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_1 = (pub_r000137_16_1 + 7) & 127;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((sec_r000137_6_2 & 2) != 0)
    {
      stage_v_111_2 = (pub_r000137_16_2 + 31) & 127;
    }
    else
    {
      stage_v_111_2 = (pub_r000137_16_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_111_2 = (pub_r000137_16_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_111_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_111_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = 0;
  int stage_v_112_2 = 0;
  if ((stage_v_35_1 & 1) != 0)
  {
    if ((sec_r000137_10_1 & 2) != 0)
    {
      stage_v_112_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_112_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((stage_v_35_2 & 1) != 0)
  {
    if ((sec_r000137_10_2 & 2) != 0)
    {
      stage_v_112_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_112_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_112_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_112_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_112_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = 0;
  int stage_v_113_2 = 0;
  if ((sec_r000137_13_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_113_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_113_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((sec_r000137_13_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_113_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_113_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_113_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_113_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_113_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = 0;
  int stage_v_114_2 = 0;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_114_1 = (pub_r000137_2_1 + 31) & 127;
    }
    else
    {
      stage_v_114_1 = (pub_r000137_2_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_1 = (pub_r000137_2_1 + 7) & 127;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_114_2 = (pub_r000137_2_2 + 31) & 127;
    }
    else
    {
      stage_v_114_2 = (pub_r000137_2_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_114_2 = (pub_r000137_2_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_114_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_114_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = 0;
  int stage_v_115_2 = 0;
  if ((stage_v_64_1 & 1) != 0)
  {
    if ((sec_r000137_5_1 & 2) != 0)
    {
      stage_v_115_1 = (pub_r000137_6_1 + 31) & 127;
    }
    else
    {
      stage_v_115_1 = (pub_r000137_6_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_1 = (pub_r000137_6_1 + 7) & 127;
  }
  if ((stage_v_64_2 & 1) != 0)
  {
    if ((sec_r000137_5_2 & 2) != 0)
    {
      stage_v_115_2 = (pub_r000137_6_2 + 31) & 127;
    }
    else
    {
      stage_v_115_2 = (pub_r000137_6_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_115_2 = (pub_r000137_6_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_115_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_115_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = 0;
  int stage_v_116_2 = 0;
  if ((sec_r000137_3_1 & 1) != 0)
  {
    if ((sec_r000137_9_1 & 2) != 0)
    {
      stage_v_116_1 = (pub_r000137_10_1 + 31) & 127;
    }
    else
    {
      stage_v_116_1 = (pub_r000137_10_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_1 = (pub_r000137_10_1 + 7) & 127;
  }
  if ((sec_r000137_3_2 & 1) != 0)
  {
    if ((sec_r000137_9_2 & 2) != 0)
    {
      stage_v_116_2 = (pub_r000137_10_2 + 31) & 127;
    }
    else
    {
      stage_v_116_2 = (pub_r000137_10_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_116_2 = (pub_r000137_10_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_116_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_116_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = 0;
  int stage_v_117_2 = 0;
  if ((stage_v_109_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_117_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_117_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((stage_v_109_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_117_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_117_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_117_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_117_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_117_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = 0;
  int stage_v_118_2 = 0;
  if ((sec_r000137_0_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_118_1 = (pub_r000137_14_1 + 31) & 127;
    }
    else
    {
      stage_v_118_1 = (pub_r000137_14_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_1 = (pub_r000137_14_1 + 7) & 127;
  }
  if ((sec_r000137_0_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_118_2 = (pub_r000137_14_2 + 31) & 127;
    }
    else
    {
      stage_v_118_2 = (pub_r000137_14_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_118_2 = (pub_r000137_14_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_118_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_118_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = 0;
  int stage_v_119_2 = 0;
  if ((sec_r000137_14_1 & 1) != 0)
  {
    if ((sec_r000137_14_1 & 2) != 0)
    {
      stage_v_119_1 = (pub_r000137_5_1 + 31) & 127;
    }
    else
    {
      stage_v_119_1 = (pub_r000137_5_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_1 = (pub_r000137_5_1 + 7) & 127;
  }
  if ((sec_r000137_14_2 & 1) != 0)
  {
    if ((sec_r000137_14_2 & 2) != 0)
    {
      stage_v_119_2 = (pub_r000137_5_2 + 31) & 127;
    }
    else
    {
      stage_v_119_2 = (pub_r000137_5_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_119_2 = (pub_r000137_5_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_119_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_119_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = 0;
  int stage_v_120_2 = 0;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((sec_r000137_3_1 & 2) != 0)
    {
      stage_v_120_1 = (pub_r000137_3_1 + 31) & 127;
    }
    else
    {
      stage_v_120_1 = (pub_r000137_3_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_1 = (pub_r000137_3_1 + 7) & 127;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((sec_r000137_3_2 & 2) != 0)
    {
      stage_v_120_2 = (pub_r000137_3_2 + 31) & 127;
    }
    else
    {
      stage_v_120_2 = (pub_r000137_3_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_120_2 = (pub_r000137_3_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_120_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_120_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = 0;
  int stage_v_121_2 = 0;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r000137_8_1 & 2) != 0)
    {
      stage_v_121_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_121_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r000137_8_2 & 2) != 0)
    {
      stage_v_121_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_121_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_121_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_121_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_121_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = 0;
  int stage_v_122_2 = 0;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((sec_r000137_5_1 & 2) != 0)
    {
      stage_v_122_1 = (pub_r000137_11_1 + 31) & 127;
    }
    else
    {
      stage_v_122_1 = (pub_r000137_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_1 = (pub_r000137_11_1 + 7) & 127;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((sec_r000137_5_2 & 2) != 0)
    {
      stage_v_122_2 = (pub_r000137_11_2 + 31) & 127;
    }
    else
    {
      stage_v_122_2 = (pub_r000137_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_122_2 = (pub_r000137_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_122_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_122_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = 0;
  int stage_v_123_2 = 0;
  if ((sec_r000137_17_1 & 1) != 0)
  {
    if ((sec_r000137_13_1 & 2) != 0)
    {
      stage_v_123_1 = (pub_r000137_4_1 + 31) & 127;
    }
    else
    {
      stage_v_123_1 = (pub_r000137_4_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_1 = (pub_r000137_4_1 + 7) & 127;
  }
  if ((sec_r000137_17_2 & 1) != 0)
  {
    if ((sec_r000137_13_2 & 2) != 0)
    {
      stage_v_123_2 = (pub_r000137_4_2 + 31) & 127;
    }
    else
    {
      stage_v_123_2 = (pub_r000137_4_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_123_2 = (pub_r000137_4_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_123_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_123_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = 0;
  int stage_v_124_2 = 0;
  if ((sec_r000137_2_1 & 1) != 0)
  {
    if ((sec_r000137_1_1 & 2) != 0)
    {
      stage_v_124_1 = (pub_r000137_1_1 + 31) & 127;
    }
    else
    {
      stage_v_124_1 = (pub_r000137_1_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_1 = (pub_r000137_1_1 + 7) & 127;
  }
  if ((sec_r000137_2_2 & 1) != 0)
  {
    if ((sec_r000137_1_2 & 2) != 0)
    {
      stage_v_124_2 = (pub_r000137_1_2 + 31) & 127;
    }
    else
    {
      stage_v_124_2 = (pub_r000137_1_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_124_2 = (pub_r000137_1_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_124_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_124_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = 0;
  int stage_v_125_2 = 0;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((sec_r000137_16_1 & 2) != 0)
    {
      stage_v_125_1 = (pub_r000137_11_1 + 31) & 127;
    }
    else
    {
      stage_v_125_1 = (pub_r000137_11_1 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_1 = (pub_r000137_11_1 + 7) & 127;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((sec_r000137_16_2 & 2) != 0)
    {
      stage_v_125_2 = (pub_r000137_11_2 + 31) & 127;
    }
    else
    {
      stage_v_125_2 = (pub_r000137_11_2 + 13) & 127;
    }
  }
  else
  {
    stage_v_125_2 = (pub_r000137_11_2 + 7) & 127;
  }
  out_sink_1 = (out_sink_1 + stage_v_125_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_125_2) & 255;
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000137_14_1 != sec_r000137_14_2);
  __CPROVER_assume(sec_r000137_11_1 != sec_r000137_11_2);
  __CPROVER_assume(pub_r000137_4_1 == pub_r000137_4_2);
  __CPROVER_assume(sec_r000137_4_1 != sec_r000137_4_2);
  __CPROVER_assume(sec_r000137_15_1 != sec_r000137_15_2);
  __CPROVER_assume(pub_r000137_11_1 == pub_r000137_11_2);
  __CPROVER_assume(pub_r000137_12_1 == pub_r000137_12_2);
  __CPROVER_assume(pub_r000137_1_1 == pub_r000137_1_2);
  __CPROVER_assume(pub_r000137_2_1 == pub_r000137_2_2);
  __CPROVER_assume(sec_r000137_6_1 != sec_r000137_6_2);
  __CPROVER_assume(sec_r000137_1_1 != sec_r000137_1_2);
  __CPROVER_assume(sec_r000137_2_1 != sec_r000137_2_2);
  __CPROVER_assume(sec_r000137_16_1 != sec_r000137_16_2);
  __CPROVER_assume(sec_r000137_17_1 != sec_r000137_17_2);
  __CPROVER_assume(pub_r000137_14_1 == pub_r000137_14_2);
  __CPROVER_assume(sec_r000137_7_1 != sec_r000137_7_2);
  __CPROVER_assume(pub_r000137_10_1 == pub_r000137_10_2);
  __CPROVER_assume(sec_r000137_8_1 != sec_r000137_8_2);
  __CPROVER_assume(pub_r000137_13_1 == pub_r000137_13_2);
  __CPROVER_assume(pub_r000137_15_1 == pub_r000137_15_2);
  __CPROVER_assume(pub_r000137_0_1 == pub_r000137_0_2);
  __CPROVER_assume(pub_r000137_6_1 == pub_r000137_6_2);
  __CPROVER_assume(pub_r000137_16_1 == pub_r000137_16_2);
  __CPROVER_assume(pub_r000137_9_1 == pub_r000137_9_2);
  __CPROVER_assume(sec_r000137_3_1 != sec_r000137_3_2);
  __CPROVER_assume(pub_r000137_8_1 == pub_r000137_8_2);
  __CPROVER_assume(sec_r000137_0_1 != sec_r000137_0_2);
  __CPROVER_assume(sec_r000137_10_1 != sec_r000137_10_2);
  __CPROVER_assume(sec_r000137_13_1 != sec_r000137_13_2);
  __CPROVER_assume(pub_r000137_7_1 == pub_r000137_7_2);
  __CPROVER_assume(pub_r000137_5_1 == pub_r000137_5_2);
  __CPROVER_assume(sec_r000137_9_1 != sec_r000137_9_2);
  __CPROVER_assume(sec_r000137_12_1 != sec_r000137_12_2);
  __CPROVER_assume(sec_r000137_18_1 != sec_r000137_18_2);
  __CPROVER_assume(pub_r000137_3_1 == pub_r000137_3_2);
  __CPROVER_assume(sec_r000137_5_1 != sec_r000137_5_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.capacity == st_var_0_2.capacity);
  assert(st_var_0_1.state == st_var_0_2.state);
  assert(st_var_0_1.tail == st_var_0_2.tail);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.heading == st_var_1_2.heading);
  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.pitch == st_var_1_2.pitch);
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
}


