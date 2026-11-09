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
struct Vector3D_R001116_1613_0
{
  int heading;
  short pitch;
  int coord_y;
  unsigned char coord_z;
  int buffer[3];
};
struct StreamBuffer_R001116_1613_1
{
  int watermark;
  int head;
  short state;
  short checksum;
  short capacity;
  int buffer[3];
};
union TelemetryField_R001116_1613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001116_1613_1
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
void fn_R001116_1613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int delta_92_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_92_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_92_1)
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

  switch (delta_92_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_98_1) & 63;
  aux_2 = (aux_2 + phase_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_92_1 == delta_92_2);
  assert(phase_98_1 == phase_98_2);
}

int fn_R001116_1613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int delta_92 = (aux + st.buffer[1]) & 3;
  switch (delta_92)
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

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_98) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_51_1 = 0;
  int quantum_51_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quantum_51_1 = ((quantum_51_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quantum_51_2 = ((quantum_51_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quantum_51_1) & 127;
    acc_2 = (acc_2 + quantum_51_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_51_1 == quantum_51_2);
}

int fn_R001116_1613_1(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_51 = 0;
  for (int k = 0; k < 3; k++)
  {
    quantum_51 = ((quantum_51 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quantum_51) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001116_1613_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_84_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_84_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_84_1)
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

  switch (metric_84_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_75_1 = 0;
  int coefficient_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_75_1 = ((coefficient_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_75_2 = ((coefficient_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_75_1) & 127;
    acc_2 = (acc_2 + coefficient_75_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_84_1 == metric_84_2);
  assert(coefficient_75_1 == coefficient_75_2);
}

int fn_R001116_1613_2(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_84 = (aux + st.buffer[1]) & 3;
  switch (metric_84)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_75 = ((coefficient_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_75) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001116_1613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int accumulator_28_1 = 0;
  int accumulator_28_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_28_1 = ((accumulator_28_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_28_2 = ((accumulator_28_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_28_1) & 127;
    acc_2 = (acc_2 + accumulator_28_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_40_1 = local_arr_1[aux_1 % 3];
  int phase_40_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_40_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_40_2 * 2)) & 127;
  int checksum_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_83_1) & 63;
  aux_2 = (aux_2 + checksum_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_28_1 == accumulator_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_40_1 == phase_40_2);
  assert(checksum_83_1 == checksum_83_2);
}

int fn_R001116_1613_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int accumulator_28 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_28 = ((accumulator_28 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_28) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_40 = local_arr[aux % 3];
  acc = (acc + (phase_40 * 2)) & 127;
  int checksum_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_83) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_44_1 = local_arr_1[aux_1 % 3];
  int tally_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_44_2 * 2)) & 127;
  int delta_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_92_1) & 63;
  aux_2 = (aux_2 + delta_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_44_1 == tally_44_2);
  assert(delta_92_1 == delta_92_2);
}

int fn_R001116_1613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int tally_44 = local_arr[aux % 3];
  acc = (acc + (tally_44 * 2)) & 127;
  int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_89_1 > 47)
  {
    acc_1 = ((acc_1 + (delta_89_1 * 2)) + 5) & 127;
    aux_1 ^= delta_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_89_2 > 47)
  {
    acc_2 = ((acc_2 + (delta_89_2 * 2)) + 5) & 127;
    aux_2 ^= delta_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_89_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_32_1 = local_arr_1[aux_1 % 3];
  int index_reg_32_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_32_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_32_2 * 2)) & 127;
  int quotient_85_1 = 0;
  int quotient_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    quotient_85_1 = ((quotient_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    quotient_85_2 = ((quotient_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + quotient_85_1) & 127;
    acc_2 = (acc_2 + quotient_85_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_32_1 == index_reg_32_2);
  assert(quotient_85_1 == quotient_85_2);
}

int fn_R001116_1613_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_89 > 47)
  {
    acc = ((acc + (delta_89 * 2)) + 5) & 127;
    aux ^= delta_89 & 15;
  }
  else
  {
    acc = ((acc - delta_89) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_32 = local_arr[aux % 3];
  acc = (acc + (index_reg_32 * 2)) & 127;
  int quotient_85 = 0;
  for (int k = 0; k < 3; k++)
  {
    quotient_85 = ((quotient_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + quotient_85) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001116_1613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int window_53_1 = 0;
  int window_53_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_53_1 = ((window_53_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_53_2 = ((window_53_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_53_1) & 127;
    acc_2 = (acc_2 + window_53_2) & 127;
  }

  int segment_28_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_28_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_28_1 > 23)
  {
    acc_1 = ((acc_1 + (segment_28_1 * 2)) + 5) & 127;
    aux_1 ^= segment_28_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_28_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_28_2 > 23)
  {
    acc_2 = ((acc_2 + (segment_28_2 * 2)) + 5) & 127;
    aux_2 ^= segment_28_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_28_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_47_1 = local_arr_1[aux_1 % 3];
  int cursor_47_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_47_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_47_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_53_1 == window_53_2);
  assert(segment_28_1 == segment_28_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_47_1 == cursor_47_2);
}

int fn_R001116_1613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int window_53 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_53 = ((window_53 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_53) & 127;
  }

  int segment_28 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_28 > 23)
  {
    acc = ((acc + (segment_28 * 2)) + 5) & 127;
    aux ^= segment_28 & 15;
  }
  else
  {
    acc = ((acc - segment_28) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_47 = local_arr[aux % 3];
  acc = (acc + (cursor_47 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001116_1613_7_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int residue_75_1 = 0;
  int residue_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_75_1 = ((residue_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_75_2 = ((residue_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_75_1) & 127;
    acc_2 = (acc_2 + residue_75_2) & 127;
  }

  int delta_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_10_1)
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

  switch (delta_10_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_75_1 == residue_75_2);
  assert(delta_10_1 == delta_10_2);
}

int fn_R001116_1613_7(int p0, int p1)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int residue_75 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_75 = ((residue_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_75) & 127;
  }

  int delta_10 = (aux + st.buffer[1]) & 3;
  switch (delta_10)
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

void fn_R001116_1613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_15_1 = local_arr_1[aux_1 % 3];
  int stride_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_15_2 * 2)) & 127;
  int metric_47_1 = 0;
  int metric_47_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_47_1 = ((metric_47_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_47_2 = ((metric_47_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_47_1) & 127;
    acc_2 = (acc_2 + metric_47_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_15_1 == stride_15_2);
  assert(metric_47_1 == metric_47_2);
}

int fn_R001116_1613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int local_arr[3] = {4, 9, 15};
  int stride_15 = local_arr[aux % 3];
  acc = (acc + (stride_15 * 2)) & 127;
  int metric_47 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_47 = ((metric_47 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_47) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001116_1613_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  int vector_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_23_1) & 63;
  aux_2 = (aux_2 + vector_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_98_1 > 45)
  {
    acc_1 = ((acc_1 + (sample_98_1 * 2)) + 5) & 127;
    aux_1 ^= sample_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_98_2 > 45)
  {
    acc_2 = ((acc_2 + (sample_98_2 * 2)) + 5) & 127;
    aux_2 ^= sample_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int index_reg_48_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_48_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_48_1)
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

  switch (index_reg_48_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(sample_98_1 == sample_98_2);
  assert(index_reg_48_1 == index_reg_48_2);
}

int fn_R001116_1613_9(int p0, int p1)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  int vector_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_23) & 63;
  acc ^= aux;
  int sample_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_98 > 45)
  {
    acc = ((acc + (sample_98 * 2)) + 5) & 127;
    aux ^= sample_98 & 15;
  }
  else
  {
    acc = ((acc - sample_98) + 11) & 127;
    aux += 3;
  }
  int index_reg_48 = (aux + st.buffer[1]) & 3;
  switch (index_reg_48)
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

void fn_R001116_1613_10_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int quotient_91_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_91_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_91_1 > 46)
  {
    acc_1 = ((acc_1 + (quotient_91_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_91_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_91_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_91_2 > 46)
  {
    acc_2 = ((acc_2 + (quotient_91_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_91_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_91_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_98_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_98_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_98_1)
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

  switch (offset_98_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tracker_67_1 = local_arr_1[aux_1 % 3];
  int tracker_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tracker_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (tracker_67_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_91_1 == quotient_91_2);
  assert(offset_98_1 == offset_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tracker_67_1 == tracker_67_2);
}

int fn_R001116_1613_10(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int quotient_91 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_91 > 46)
  {
    acc = ((acc + (quotient_91 * 2)) + 5) & 127;
    aux ^= quotient_91 & 15;
  }
  else
  {
    acc = ((acc - quotient_91) + 11) & 127;
    aux += 3;
  }
  int offset_98 = (aux + st.buffer[1]) & 3;
  switch (offset_98)
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

  int local_arr[3] = {4, 9, 15};
  int tracker_67 = local_arr[aux % 3];
  acc = (acc + (tracker_67 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001116_1613_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_95_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_95_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_95_1)
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

  switch (damping_95_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_95_1 == damping_95_2);
}

int fn_R001116_1613_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_95 = (aux + st.buffer[1]) & 3;
  switch (damping_95)
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

void fn_R001116_1613_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_67_1 = local_arr_1[aux_1 % 3];
  int anchor_67_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_67_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_67_2 * 2)) & 127;
  int anchor_85_1 = 0;
  int anchor_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_85_1 = ((anchor_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_85_2 = ((anchor_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_85_1) & 127;
    acc_2 = (acc_2 + anchor_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_67_1 == anchor_67_2);
  assert(anchor_85_1 == anchor_85_2);
}

int fn_R001116_1613_12(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int anchor_67 = local_arr[aux % 3];
  acc = (acc + (anchor_67 * 2)) & 127;
  int anchor_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_85 = ((anchor_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001116_1613_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_91_1 = local_arr_1[aux_1 % 3];
  int accumulator_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_91_2 * 2)) & 127;
  int sample_15_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_15_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_15_1) & 63;
  aux_2 = (aux_2 + sample_15_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_91_1 == accumulator_91_2);
  assert(sample_15_1 == sample_15_2);
}

int fn_R001116_1613_13(int p0, int p1, int p2)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int accumulator_91 = local_arr[aux % 3];
  acc = (acc + (accumulator_91 * 2)) & 127;
  int sample_15 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_15) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_14_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 28) & 127;
  int acc_2 = (p0_2 + 28) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int index_reg_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_78_1) & 63;
  aux_2 = (aux_2 + index_reg_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_87_1 = local_arr_1[aux_1 % 3];
  int scale_87_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_87_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_87_2 * 2)) & 127;
  int residue_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_52_1)
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

  switch (residue_52_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_78_1 == index_reg_78_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_87_1 == scale_87_2);
  assert(residue_52_1 == residue_52_2);
}

int fn_R001116_1613_14(int p0, int p1)
{
  int acc = (p0 + 28) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int index_reg_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_78) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int scale_87 = local_arr[aux % 3];
  acc = (acc + (scale_87 * 2)) & 127;
  int residue_52 = (aux + st.buffer[1]) & 3;
  switch (residue_52)
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

void fn_R001116_1613_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_81_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_81_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_81_1 > 19)
  {
    acc_1 = ((acc_1 + (window_81_1 * 2)) + 5) & 127;
    aux_1 ^= window_81_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_81_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_81_2 > 19)
  {
    acc_2 = ((acc_2 + (window_81_2 * 2)) + 5) & 127;
    aux_2 ^= window_81_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_81_2) + 11) & 127;
    aux_2 += 3;
  }
  int tally_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_88_1) & 63;
  aux_2 = (aux_2 + tally_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_73_1 = local_arr_1[aux_1 % 3];
  int offset_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_81_1 == window_81_2);
  assert(tally_88_1 == tally_88_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_73_1 == offset_73_2);
}

int fn_R001116_1613_15(int p0, int p1)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_81 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_81 > 19)
  {
    acc = ((acc + (window_81 * 2)) + 5) & 127;
    aux ^= window_81 & 15;
  }
  else
  {
    acc = ((acc - window_81) + 11) & 127;
    aux += 3;
  }
  int tally_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_88) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int offset_73 = local_arr[aux % 3];
  acc = (acc + (offset_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001116_1613_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int vector_74_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_74_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_74_1) & 63;
  aux_2 = (aux_2 + vector_74_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int residue_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_61_1)
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

  switch (residue_61_2)
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
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_74_1 == vector_74_2);
  assert(residue_61_1 == residue_61_2);
}

int fn_R001116_1613_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int vector_74 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_74) & 63;
  acc ^= aux;
  int residue_61 = (aux + st.buffer[1]) & 3;
  switch (residue_61)
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

void fn_R001116_1613_17_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int bound_52_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_52_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_52_1)
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

  switch (bound_52_2)
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

  int residue_86_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_86_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_86_1) & 63;
  aux_2 = (aux_2 + residue_86_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_52_1 == bound_52_2);
  assert(residue_86_1 == residue_86_2);
}

int fn_R001116_1613_17(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int bound_52 = (aux + st.buffer[1]) & 3;
  switch (bound_52)
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

  int residue_86 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_86) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001116_1613_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 25) & 127;
  int acc_2 = (p0_2 + 25) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int cursor_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_61_1 > 46)
  {
    acc_1 = ((acc_1 + (cursor_61_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_61_2 > 46)
  {
    acc_2 = ((acc_2 + (cursor_61_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_86_1 = local_arr_1[aux_1 % 3];
  int delta_86_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_86_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_86_2 * 2)) & 127;
  int weight_52_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int weight_52_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + weight_52_1) & 63;
  aux_2 = (aux_2 + weight_52_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_61_1 == cursor_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_86_1 == delta_86_2);
  assert(weight_52_1 == weight_52_2);
}

int fn_R001116_1613_18(int p0, int p1)
{
  int acc = (p0 + 25) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int cursor_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_61 > 46)
  {
    acc = ((acc + (cursor_61 * 2)) + 5) & 127;
    aux ^= cursor_61 & 15;
  }
  else
  {
    acc = ((acc - cursor_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int delta_86 = local_arr[aux % 3];
  acc = (acc + (delta_86 * 2)) & 127;
  int weight_52 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + weight_52) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_18_1 = local_arr_1[aux_1 % 3];
  int threshold_18_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_18_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_18_2 * 2)) & 127;
  int delta_77_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_77_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_77_1) & 63;
  aux_2 = (aux_2 + delta_77_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.watermark == st_2.watermark);
  assert(st_1.head == st_2.head);
  assert(st_1.state == st_2.state);
  assert(st_1.checksum == st_2.checksum);
  assert(st_1.capacity == st_2.capacity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_18_1 == threshold_18_2);
  assert(delta_77_1 == delta_77_2);
}

int fn_R001116_1613_19(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct StreamBuffer_R001116_1613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int local_arr[3] = {4, 9, 15};
  int threshold_18 = local_arr[aux % 3];
  acc = (acc + (threshold_18 * 2)) & 127;
  int delta_77 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_77) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001116_1613_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int sample_11_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_11_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_11_1) & 63;
  aux_2 = (aux_2 + sample_11_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int pivot_98_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_98_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_98_1 > 24)
  {
    acc_1 = ((acc_1 + (pivot_98_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_98_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_98_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_98_2 > 24)
  {
    acc_2 = ((acc_2 + (pivot_98_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_98_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_98_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_25_1 = local_arr_1[aux_1 % 3];
  int index_reg_25_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_25_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_25_2 * 2)) & 127;
  int parity_38_1 = 0;
  int parity_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_38_1 = ((parity_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_38_2 = ((parity_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_38_1) & 127;
    acc_2 = (acc_2 + parity_38_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_11_1 == sample_11_2);
  assert(pivot_98_1 == pivot_98_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_25_1 == index_reg_25_2);
  assert(parity_38_1 == parity_38_2);
}

int fn_R001116_1613_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int sample_11 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_11) & 63;
  acc ^= aux;
  int pivot_98 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_98 > 24)
  {
    acc = ((acc + (pivot_98 * 2)) + 5) & 127;
    aux ^= pivot_98 & 15;
  }
  else
  {
    acc = ((acc - pivot_98) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int index_reg_25 = local_arr[aux % 3];
  acc = (acc + (index_reg_25 * 2)) & 127;
  int parity_38 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_38 = ((parity_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_38) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001116_1613_21_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 29) & 127;
  int acc_2 = (p0_2 + 29) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st_1 = {0};
  struct Vector3D_R001116_1613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int stride_65_1 = 0;
  int stride_65_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    stride_65_1 = ((stride_65_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    stride_65_2 = ((stride_65_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + stride_65_1) & 127;
    acc_2 = (acc_2 + stride_65_2) & 127;
  }

  int pivot_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_73_1 > 23)
  {
    acc_1 = ((acc_1 + (pivot_73_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_73_2 > 23)
  {
    acc_2 = ((acc_2 + (pivot_73_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_14_1) & 63;
  aux_2 = (aux_2 + vector_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_65_1 == stride_65_2);
  assert(pivot_73_1 == pivot_73_2);
  assert(vector_14_1 == vector_14_2);
}

int fn_R001116_1613_21(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 29) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001116_1613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int stride_65 = 0;
  for (int k = 0; k < 2; k++)
  {
    stride_65 = ((stride_65 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + stride_65) & 127;
  }

  int pivot_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_73 > 23)
  {
    acc = ((acc + (pivot_73 * 2)) + 5) & 127;
    aux ^= pivot_73 & 15;
  }
  else
  {
    acc = ((acc - pivot_73) + 11) & 127;
    aux += 3;
  }
  int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_14) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001116_0_1;
  int sec_r001116_0_2;
  int sec_r001116_1_1;
  int sec_r001116_1_2;
  int sec_r001116_2_1;
  int sec_r001116_2_2;
  int sec_r001116_3_1;
  int sec_r001116_3_2;
  int sec_r001116_4_1;
  int sec_r001116_4_2;
  int sec_r001116_5_1;
  int sec_r001116_5_2;
  int sec_r001116_6_1;
  int sec_r001116_6_2;
  int sec_r001116_7_1;
  int sec_r001116_7_2;
  int sec_r001116_8_1;
  int sec_r001116_8_2;
  int sec_r001116_9_1;
  int sec_r001116_9_2;
  int sec_r001116_10_1;
  int sec_r001116_10_2;
  int sec_r001116_11_1;
  int sec_r001116_11_2;
  int sec_r001116_12_1;
  int sec_r001116_12_2;
  int sec_r001116_13_1;
  int sec_r001116_13_2;
  int sec_r001116_14_1;
  int sec_r001116_14_2;
  int sec_r001116_15_1;
  int sec_r001116_15_2;
  int sec_r001116_16_1;
  int sec_r001116_16_2;
  int sec_r001116_17_1;
  int sec_r001116_17_2;
  int sec_r001116_18_1;
  int sec_r001116_18_2;
  int sec_r001116_19_1;
  int sec_r001116_19_2;
  int sec_r001116_20_1;
  int sec_r001116_20_2;
  int sec_r001116_21_1;
  int sec_r001116_21_2;
  int pub_r001116_0_1;
  int pub_r001116_0_2;
  int pub_r001116_1_1;
  int pub_r001116_1_2;
  int pub_r001116_2_1;
  int pub_r001116_2_2;
  int pub_r001116_3_1;
  int pub_r001116_3_2;
  int pub_r001116_4_1;
  int pub_r001116_4_2;
  int pub_r001116_5_1;
  int pub_r001116_5_2;
  int pub_r001116_6_1;
  int pub_r001116_6_2;
  int pub_r001116_7_1;
  int pub_r001116_7_2;
  int pub_r001116_8_1;
  int pub_r001116_8_2;
  int pub_r001116_9_1;
  int pub_r001116_9_2;
  int pub_r001116_10_1;
  int pub_r001116_10_2;
  int pub_r001116_11_1;
  int pub_r001116_11_2;
  int pub_r001116_12_1;
  int pub_r001116_12_2;
  int pub_r001116_13_1;
  int pub_r001116_13_2;
  int pub_r001116_14_1;
  int pub_r001116_14_2;
  int pub_r001116_15_1;
  int pub_r001116_15_2;
  int pub_r001116_16_1;
  int pub_r001116_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001116_0_1 >= (-100)) && (pub_r001116_0_1 <= 100));
  __CPROVER_assume((pub_r001116_0_2 >= (-100)) && (pub_r001116_0_2 <= 100));
  __CPROVER_assume((pub_r001116_1_1 >= (-100)) && (pub_r001116_1_1 <= 100));
  __CPROVER_assume((pub_r001116_1_2 >= (-100)) && (pub_r001116_1_2 <= 100));
  __CPROVER_assume((pub_r001116_2_1 >= (-100)) && (pub_r001116_2_1 <= 100));
  __CPROVER_assume((pub_r001116_2_2 >= (-100)) && (pub_r001116_2_2 <= 100));
  __CPROVER_assume((pub_r001116_3_1 >= (-100)) && (pub_r001116_3_1 <= 100));
  __CPROVER_assume((pub_r001116_3_2 >= (-100)) && (pub_r001116_3_2 <= 100));
  __CPROVER_assume((pub_r001116_4_1 >= (-100)) && (pub_r001116_4_1 <= 100));
  __CPROVER_assume((pub_r001116_4_2 >= (-100)) && (pub_r001116_4_2 <= 100));
  __CPROVER_assume((pub_r001116_5_1 >= (-100)) && (pub_r001116_5_1 <= 100));
  __CPROVER_assume((pub_r001116_5_2 >= (-100)) && (pub_r001116_5_2 <= 100));
  __CPROVER_assume((pub_r001116_6_1 >= (-100)) && (pub_r001116_6_1 <= 100));
  __CPROVER_assume((pub_r001116_6_2 >= (-100)) && (pub_r001116_6_2 <= 100));
  __CPROVER_assume((pub_r001116_7_1 >= (-100)) && (pub_r001116_7_1 <= 100));
  __CPROVER_assume((pub_r001116_7_2 >= (-100)) && (pub_r001116_7_2 <= 100));
  __CPROVER_assume((pub_r001116_8_1 >= (-100)) && (pub_r001116_8_1 <= 100));
  __CPROVER_assume((pub_r001116_8_2 >= (-100)) && (pub_r001116_8_2 <= 100));
  __CPROVER_assume((pub_r001116_9_1 >= (-100)) && (pub_r001116_9_1 <= 100));
  __CPROVER_assume((pub_r001116_9_2 >= (-100)) && (pub_r001116_9_2 <= 100));
  __CPROVER_assume((pub_r001116_10_1 >= (-100)) && (pub_r001116_10_1 <= 100));
  __CPROVER_assume((pub_r001116_10_2 >= (-100)) && (pub_r001116_10_2 <= 100));
  __CPROVER_assume((pub_r001116_11_1 >= (-100)) && (pub_r001116_11_1 <= 100));
  __CPROVER_assume((pub_r001116_11_2 >= (-100)) && (pub_r001116_11_2 <= 100));
  __CPROVER_assume((pub_r001116_12_1 >= (-100)) && (pub_r001116_12_1 <= 100));
  __CPROVER_assume((pub_r001116_12_2 >= (-100)) && (pub_r001116_12_2 <= 100));
  __CPROVER_assume((pub_r001116_13_1 >= (-100)) && (pub_r001116_13_1 <= 100));
  __CPROVER_assume((pub_r001116_13_2 >= (-100)) && (pub_r001116_13_2 <= 100));
  __CPROVER_assume((pub_r001116_14_1 >= (-100)) && (pub_r001116_14_1 <= 100));
  __CPROVER_assume((pub_r001116_14_2 >= (-100)) && (pub_r001116_14_2 <= 100));
  __CPROVER_assume((pub_r001116_15_1 >= (-100)) && (pub_r001116_15_1 <= 100));
  __CPROVER_assume((pub_r001116_15_2 >= (-100)) && (pub_r001116_15_2 <= 100));
  __CPROVER_assume((pub_r001116_16_1 >= (-100)) && (pub_r001116_16_1 <= 100));
  __CPROVER_assume((pub_r001116_16_2 >= (-100)) && (pub_r001116_16_2 <= 100));
  __CPROVER_assume((sec_r001116_0_1 >= 0) && (sec_r001116_0_1 <= 255));
  __CPROVER_assume((sec_r001116_0_2 >= 0) && (sec_r001116_0_2 <= 255));
  __CPROVER_assume((sec_r001116_1_1 >= 0) && (sec_r001116_1_1 <= 255));
  __CPROVER_assume((sec_r001116_1_2 >= 0) && (sec_r001116_1_2 <= 255));
  __CPROVER_assume((sec_r001116_2_1 >= 0) && (sec_r001116_2_1 <= 255));
  __CPROVER_assume((sec_r001116_2_2 >= 0) && (sec_r001116_2_2 <= 255));
  __CPROVER_assume((sec_r001116_3_1 >= 0) && (sec_r001116_3_1 <= 255));
  __CPROVER_assume((sec_r001116_3_2 >= 0) && (sec_r001116_3_2 <= 255));
  __CPROVER_assume((sec_r001116_4_1 >= 0) && (sec_r001116_4_1 <= 255));
  __CPROVER_assume((sec_r001116_4_2 >= 0) && (sec_r001116_4_2 <= 255));
  __CPROVER_assume((sec_r001116_5_1 >= 0) && (sec_r001116_5_1 <= 255));
  __CPROVER_assume((sec_r001116_5_2 >= 0) && (sec_r001116_5_2 <= 255));
  __CPROVER_assume((sec_r001116_6_1 >= 0) && (sec_r001116_6_1 <= 255));
  __CPROVER_assume((sec_r001116_6_2 >= 0) && (sec_r001116_6_2 <= 255));
  __CPROVER_assume((sec_r001116_7_1 >= 0) && (sec_r001116_7_1 <= 255));
  __CPROVER_assume((sec_r001116_7_2 >= 0) && (sec_r001116_7_2 <= 255));
  __CPROVER_assume((sec_r001116_8_1 >= 0) && (sec_r001116_8_1 <= 255));
  __CPROVER_assume((sec_r001116_8_2 >= 0) && (sec_r001116_8_2 <= 255));
  __CPROVER_assume((sec_r001116_9_1 >= 0) && (sec_r001116_9_1 <= 255));
  __CPROVER_assume((sec_r001116_9_2 >= 0) && (sec_r001116_9_2 <= 255));
  __CPROVER_assume((sec_r001116_10_1 >= 0) && (sec_r001116_10_1 <= 255));
  __CPROVER_assume((sec_r001116_10_2 >= 0) && (sec_r001116_10_2 <= 255));
  __CPROVER_assume((sec_r001116_11_1 >= 0) && (sec_r001116_11_1 <= 255));
  __CPROVER_assume((sec_r001116_11_2 >= 0) && (sec_r001116_11_2 <= 255));
  __CPROVER_assume((sec_r001116_12_1 >= 0) && (sec_r001116_12_1 <= 255));
  __CPROVER_assume((sec_r001116_12_2 >= 0) && (sec_r001116_12_2 <= 255));
  __CPROVER_assume((sec_r001116_13_1 >= 0) && (sec_r001116_13_1 <= 255));
  __CPROVER_assume((sec_r001116_13_2 >= 0) && (sec_r001116_13_2 <= 255));
  __CPROVER_assume((sec_r001116_14_1 >= 0) && (sec_r001116_14_1 <= 255));
  __CPROVER_assume((sec_r001116_14_2 >= 0) && (sec_r001116_14_2 <= 255));
  __CPROVER_assume((sec_r001116_15_1 >= 0) && (sec_r001116_15_1 <= 255));
  __CPROVER_assume((sec_r001116_15_2 >= 0) && (sec_r001116_15_2 <= 255));
  __CPROVER_assume((sec_r001116_16_1 >= 0) && (sec_r001116_16_1 <= 255));
  __CPROVER_assume((sec_r001116_16_2 >= 0) && (sec_r001116_16_2 <= 255));
  __CPROVER_assume((sec_r001116_17_1 >= 0) && (sec_r001116_17_1 <= 255));
  __CPROVER_assume((sec_r001116_17_2 >= 0) && (sec_r001116_17_2 <= 255));
  __CPROVER_assume((sec_r001116_18_1 >= 0) && (sec_r001116_18_1 <= 255));
  __CPROVER_assume((sec_r001116_18_2 >= 0) && (sec_r001116_18_2 <= 255));
  __CPROVER_assume((sec_r001116_19_1 >= 0) && (sec_r001116_19_1 <= 255));
  __CPROVER_assume((sec_r001116_19_2 >= 0) && (sec_r001116_19_2 <= 255));
  __CPROVER_assume((sec_r001116_20_1 >= 0) && (sec_r001116_20_1 <= 255));
  __CPROVER_assume((sec_r001116_20_2 >= 0) && (sec_r001116_20_2 <= 255));
  __CPROVER_assume((sec_r001116_21_1 >= 0) && (sec_r001116_21_1 <= 255));
  __CPROVER_assume((sec_r001116_21_2 >= 0) && (sec_r001116_21_2 <= 255));
  struct Vector3D_R001116_1613_0 st_var_0_1 = {0};
  struct Vector3D_R001116_1613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001116_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001116_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001116_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001116_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001116_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001116_0_2 + 7) & 15;
  struct StreamBuffer_R001116_1613_1 st_var_1_1 = {0};
  struct StreamBuffer_R001116_1613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001116_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001116_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001116_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001116_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001116_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001116_0_2 + 9) & 15;
  union TelemetryField_R001116_1613_0 u_var_1;
  union TelemetryField_R001116_1613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001116_1613_0(sec_r001116_0_1, pub_r001116_1_1, pub_r001116_2_1, pub_r001116_3_1);
  int helper_flow_0_2 = fn_R001116_1613_0(sec_r001116_0_2, pub_r001116_1_2, pub_r001116_2_2, pub_r001116_3_2);
  fn_R001116_1613_0_2(sec_r001116_0_1, pub_r001116_1_1, pub_r001116_2_1, pub_r001116_3_1, sec_r001116_0_2, pub_r001116_1_2, pub_r001116_2_2, pub_r001116_3_2);
  int helper_flow_1_1 = fn_R001116_1613_1(sec_r001116_1_1, sec_r001116_2_1, pub_r001116_3_1, pub_r001116_4_1);
  int helper_flow_1_2 = fn_R001116_1613_1(sec_r001116_1_2, sec_r001116_2_2, pub_r001116_3_2, pub_r001116_4_2);
  fn_R001116_1613_1_2(sec_r001116_1_1, sec_r001116_2_1, pub_r001116_3_1, pub_r001116_4_1, sec_r001116_1_2, sec_r001116_2_2, pub_r001116_3_2, pub_r001116_4_2);
  int helper_flow_2_1 = fn_R001116_1613_2(sec_r001116_2_1, pub_r001116_3_1);
  int helper_flow_2_2 = fn_R001116_1613_2(sec_r001116_2_2, pub_r001116_3_2);
  fn_R001116_1613_2_2(sec_r001116_2_1, pub_r001116_3_1, sec_r001116_2_2, pub_r001116_3_2);
  int helper_flow_3_1 = fn_R001116_1613_3(sec_r001116_3_1, sec_r001116_4_1, pub_r001116_5_1, pub_r001116_6_1);
  int helper_flow_3_2 = fn_R001116_1613_3(sec_r001116_3_2, sec_r001116_4_2, pub_r001116_5_2, pub_r001116_6_2);
  fn_R001116_1613_3_2(sec_r001116_3_1, sec_r001116_4_1, pub_r001116_5_1, pub_r001116_6_1, sec_r001116_3_2, sec_r001116_4_2, pub_r001116_5_2, pub_r001116_6_2);
  int helper_flow_4_1 = fn_R001116_1613_4(sec_r001116_4_1, sec_r001116_5_1, pub_r001116_6_1);
  int helper_flow_4_2 = fn_R001116_1613_4(sec_r001116_4_2, sec_r001116_5_2, pub_r001116_6_2);
  fn_R001116_1613_4_2(sec_r001116_4_1, sec_r001116_5_1, pub_r001116_6_1, sec_r001116_4_2, sec_r001116_5_2, pub_r001116_6_2);
  int helper_flow_5_1 = fn_R001116_1613_5(sec_r001116_5_1, sec_r001116_6_1, pub_r001116_7_1, pub_r001116_8_1, pub_r001116_9_1);
  int helper_flow_5_2 = fn_R001116_1613_5(sec_r001116_5_2, sec_r001116_6_2, pub_r001116_7_2, pub_r001116_8_2, pub_r001116_9_2);
  fn_R001116_1613_5_2(sec_r001116_5_1, sec_r001116_6_1, pub_r001116_7_1, pub_r001116_8_1, pub_r001116_9_1, sec_r001116_5_2, sec_r001116_6_2, pub_r001116_7_2, pub_r001116_8_2, pub_r001116_9_2);
  int helper_flow_6_1 = fn_R001116_1613_6(sec_r001116_6_1, pub_r001116_7_1, pub_r001116_8_1, pub_r001116_9_1, pub_r001116_10_1);
  int helper_flow_6_2 = fn_R001116_1613_6(sec_r001116_6_2, pub_r001116_7_2, pub_r001116_8_2, pub_r001116_9_2, pub_r001116_10_2);
  fn_R001116_1613_6_2(sec_r001116_6_1, pub_r001116_7_1, pub_r001116_8_1, pub_r001116_9_1, pub_r001116_10_1, sec_r001116_6_2, pub_r001116_7_2, pub_r001116_8_2, pub_r001116_9_2, pub_r001116_10_2);
  int helper_flow_7_1 = fn_R001116_1613_7(sec_r001116_7_1, pub_r001116_8_1);
  int helper_flow_7_2 = fn_R001116_1613_7(sec_r001116_7_2, pub_r001116_8_2);
  fn_R001116_1613_7_2(sec_r001116_7_1, pub_r001116_8_1, sec_r001116_7_2, pub_r001116_8_2);
  int helper_flow_8_1 = fn_R001116_1613_8(sec_r001116_8_1, pub_r001116_9_1, pub_r001116_10_1);
  int helper_flow_8_2 = fn_R001116_1613_8(sec_r001116_8_2, pub_r001116_9_2, pub_r001116_10_2);
  fn_R001116_1613_8_2(sec_r001116_8_1, pub_r001116_9_1, pub_r001116_10_1, sec_r001116_8_2, pub_r001116_9_2, pub_r001116_10_2);
  int stage_v_0_1 = ((sec_r001116_18_1 + (pub_r001116_1_1 * 2)) + 5) & 127;
  int stage_v_0_2 = ((sec_r001116_18_2 + (pub_r001116_1_2 * 2)) + 5) & 127;
  if (stage_v_0_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_0_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_0_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_0_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_0_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_0_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_1_1 = ((pub_r001116_0_1 * 2) + 11) & 63;
  int stage_v_1_2 = ((pub_r001116_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = ((pub_r001116_15_1 * 2) + 40) & 63;
  int stage_v_2_2 = ((pub_r001116_15_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001116_9_1 * 2) + 36) & 63;
  int stage_v_3_2 = ((pub_r001116_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001116_3_1 * 2) + 39) & 63;
  int stage_v_4_2 = ((pub_r001116_3_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001116_12_1 + (pub_r001116_13_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001116_12_2 + (pub_r001116_13_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001116_12_1 + (pub_r001116_4_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001116_12_2 + (pub_r001116_4_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((pub_r001116_6_1 * 2) + 5) & 63;
  int stage_v_7_2 = ((pub_r001116_6_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = ((pub_r001116_4_1 * 2) + 37) & 63;
  int stage_v_8_2 = ((pub_r001116_4_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001116_4_1 * 2) + 38) & 63;
  int stage_v_9_2 = ((pub_r001116_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((stage_v_6_1 + (pub_r001116_0_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((stage_v_6_2 + (pub_r001116_0_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001116_5_1 + (pub_r001116_5_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001116_5_2 + (pub_r001116_5_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001116_10_1 * 2) + 43) & 63;
  int stage_v_12_2 = ((pub_r001116_10_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001116_14_1 * 2) + 30) & 63;
  int stage_v_13_2 = ((pub_r001116_14_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001116_21_1 + (pub_r001116_15_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001116_21_2 + (pub_r001116_15_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((stage_v_0_1 + (pub_r001116_6_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((stage_v_0_2 + (pub_r001116_6_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001116_9_1 * 2) + 29) & 63;
  int stage_v_16_2 = ((pub_r001116_9_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((sec_r001116_21_1 + (pub_r001116_9_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((sec_r001116_21_2 + (pub_r001116_9_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((helper_flow_2_1 + (pub_r001116_9_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((helper_flow_2_2 + (pub_r001116_9_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((stage_v_0_1 + (pub_r001116_5_1 * 2)) + 62) & 127;
  int stage_v_19_2 = ((stage_v_0_2 + (pub_r001116_5_2 * 2)) + 62) & 127;
  if (stage_v_19_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_19_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_19_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_19_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_19_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_19_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_20_1 = ((pub_r001116_1_1 * 2) + 12) & 63;
  int stage_v_20_2 = ((pub_r001116_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001116_8_1 * 2) + 44) & 63;
  int stage_v_21_2 = ((pub_r001116_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001116_0_1 * 2) + 20) & 63;
  int stage_v_22_2 = ((pub_r001116_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001116_0_1 * 2) + 14) & 63;
  int stage_v_23_2 = ((pub_r001116_0_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((stage_v_0_1 + (pub_r001116_6_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((stage_v_0_2 + (pub_r001116_6_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001116_3_1 * 2) + 37) & 63;
  int stage_v_25_2 = ((pub_r001116_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((helper_flow_5_1 + (pub_r001116_0_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((helper_flow_5_2 + (pub_r001116_0_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001116_12_1 + (pub_r001116_12_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001116_12_2 + (pub_r001116_12_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001116_1_1 * 2) + 34) & 63;
  int stage_v_28_2 = ((pub_r001116_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((sec_r001116_16_1 + (pub_r001116_5_1 * 2)) + 92) & 127;
  int stage_v_29_2 = ((sec_r001116_16_2 + (pub_r001116_5_2 * 2)) + 92) & 127;
  if (stage_v_29_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_29_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_29_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_29_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_29_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_29_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_29_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_29_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_30_1 = ((stage_v_18_1 + (pub_r001116_8_1 * 2)) + 95) & 127;
  int stage_v_30_2 = ((stage_v_18_2 + (pub_r001116_8_2 * 2)) + 95) & 127;
  if (stage_v_30_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_30_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_30_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_30_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_30_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_30_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_31_1 = ((pub_r001116_13_1 * 2) + 7) & 63;
  int stage_v_31_2 = ((pub_r001116_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((pub_r001116_5_1 * 2) + 44) & 63;
  int stage_v_32_2 = ((pub_r001116_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_32_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_32_2) & 127;
  int stage_v_33_1 = ((sec_r001116_9_1 + (pub_r001116_16_1 * 2)) + 104) & 127;
  int stage_v_33_2 = ((sec_r001116_9_2 + (pub_r001116_16_2 * 2)) + 104) & 127;
  if (stage_v_33_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_33_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_33_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_33_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_33_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_33_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_34_1 = ((pub_r001116_16_1 * 2) + 32) & 63;
  int stage_v_34_2 = ((pub_r001116_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_34_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_34_2) & 127;
  int stage_v_35_1 = ((pub_r001116_6_1 * 2) + 11) & 63;
  int stage_v_35_2 = ((pub_r001116_6_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((stage_v_5_1 + (pub_r001116_14_1 * 2)) + 113) & 127;
  int stage_v_36_2 = ((stage_v_5_2 + (pub_r001116_14_2 * 2)) + 113) & 127;
  if (stage_v_36_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_36_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_36_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_36_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_37_1 = ((stage_v_36_1 + (pub_r001116_13_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((stage_v_36_2 + (pub_r001116_13_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((stage_v_5_1 + (pub_r001116_1_1 * 2)) + 119) & 127;
  int stage_v_38_2 = ((stage_v_5_2 + (pub_r001116_1_2 * 2)) + 119) & 127;
  if (stage_v_38_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_38_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_38_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_38_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_38_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_38_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_38_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_38_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_39_1 = ((pub_r001116_16_1 * 2) + 36) & 63;
  int stage_v_39_2 = ((pub_r001116_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = ((stage_v_15_1 + (pub_r001116_1_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((stage_v_15_2 + (pub_r001116_1_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((pub_r001116_8_1 * 2) + 40) & 63;
  int stage_v_41_2 = ((pub_r001116_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((stage_v_18_1 + (pub_r001116_2_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_18_2 + (pub_r001116_2_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((pub_r001116_14_1 * 2) + 41) & 63;
  int stage_v_43_2 = ((pub_r001116_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001116_3_1 * 2) + 24) & 63;
  int stage_v_44_2 = ((pub_r001116_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = ((sec_r001116_18_1 + (pub_r001116_15_1 * 2)) + 140) & 127;
  int stage_v_45_2 = ((sec_r001116_18_2 + (pub_r001116_15_2 * 2)) + 140) & 127;
  if (stage_v_45_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_45_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_45_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_45_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_45_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_45_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_46_1 = ((pub_r001116_11_1 * 2) + 49) & 63;
  int stage_v_46_2 = ((pub_r001116_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = ((pub_r001116_4_1 * 2) + 25) & 63;
  int stage_v_47_2 = ((pub_r001116_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((stage_v_36_1 + (pub_r001116_2_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((stage_v_36_2 + (pub_r001116_2_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((stage_v_11_1 + (pub_r001116_5_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((stage_v_11_2 + (pub_r001116_5_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((helper_flow_5_1 + (pub_r001116_14_1 * 2)) + 155) & 127;
  int stage_v_50_2 = ((helper_flow_5_2 + (pub_r001116_14_2 * 2)) + 155) & 127;
  if (stage_v_50_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_50_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_50_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_50_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_50_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_50_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_51_1 = ((pub_r001116_12_1 * 2) + 17) & 63;
  int stage_v_51_2 = ((pub_r001116_12_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((stage_v_48_1 + (pub_r001116_15_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((stage_v_48_2 + (pub_r001116_15_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((stage_v_30_1 + (pub_r001116_5_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((stage_v_30_2 + (pub_r001116_5_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001116_11_1 * 2) + 42) & 63;
  int stage_v_54_2 = ((pub_r001116_11_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((stage_v_15_1 + (pub_r001116_16_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_15_2 + (pub_r001116_16_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001116_12_1 * 2) + 38) & 63;
  int stage_v_56_2 = ((pub_r001116_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((sec_r001116_5_1 + (pub_r001116_12_1 * 2)) + 176) & 127;
  int stage_v_57_2 = ((sec_r001116_5_2 + (pub_r001116_12_2 * 2)) + 176) & 127;
  if (stage_v_57_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_57_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_57_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_57_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_58_1 = ((stage_v_14_1 + (pub_r001116_12_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((stage_v_14_2 + (pub_r001116_12_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_45_1 + (pub_r001116_7_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_45_2 + (pub_r001116_7_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((pub_r001116_9_1 * 2) + 13) & 63;
  int stage_v_60_2 = ((pub_r001116_9_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001116_1_1 * 2) + 36) & 63;
  int stage_v_61_2 = ((pub_r001116_1_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((stage_v_17_1 + (pub_r001116_10_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((stage_v_17_2 + (pub_r001116_10_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_50_1 + (pub_r001116_12_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_50_2 + (pub_r001116_12_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((sec_r001116_14_1 + (pub_r001116_16_1 * 2)) + 197) & 127;
  int stage_v_64_2 = ((sec_r001116_14_2 + (pub_r001116_16_2 * 2)) + 197) & 127;
  if (stage_v_64_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_64_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_64_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_64_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_64_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_64_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_64_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_64_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_65_1 = ((stage_v_50_1 + (pub_r001116_5_1 * 2)) + 200) & 127;
  int stage_v_65_2 = ((stage_v_50_2 + (pub_r001116_5_2 * 2)) + 200) & 127;
  if (stage_v_65_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_65_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_65_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_65_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_65_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_65_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_65_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_65_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_66_1 = ((stage_v_49_1 + (pub_r001116_14_1 * 2)) + 203) & 127;
  int stage_v_66_2 = ((stage_v_49_2 + (pub_r001116_14_2 * 2)) + 203) & 127;
  if (stage_v_66_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_66_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_66_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_66_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_66_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_66_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_66_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_66_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_67_1 = ((sec_r001116_12_1 + (pub_r001116_13_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((sec_r001116_12_2 + (pub_r001116_13_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((pub_r001116_1_1 * 2) + 40) & 63;
  int stage_v_68_2 = ((pub_r001116_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = ((pub_r001116_10_1 * 2) + 21) & 63;
  int stage_v_69_2 = ((pub_r001116_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = ((pub_r001116_3_1 * 2) + 43) & 63;
  int stage_v_70_2 = ((pub_r001116_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = ((pub_r001116_8_1 * 2) + 24) & 63;
  int stage_v_71_2 = ((pub_r001116_8_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  int stage_v_72_1 = ((pub_r001116_0_1 * 2) + 16) & 63;
  int stage_v_72_2 = ((pub_r001116_0_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = ((pub_r001116_3_1 * 2) + 38) & 63;
  int stage_v_73_2 = ((pub_r001116_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001116_11_1 * 2) + 29) & 63;
  int stage_v_74_2 = ((pub_r001116_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001116_9_1 * 2) + 41) & 63;
  int stage_v_75_2 = ((pub_r001116_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((stage_v_0_1 + (pub_r001116_9_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((stage_v_0_2 + (pub_r001116_9_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((helper_flow_5_1 + (pub_r001116_14_1 * 2)) + 236) & 127;
  int stage_v_77_2 = ((helper_flow_5_2 + (pub_r001116_14_2 * 2)) + 236) & 127;
  if (stage_v_77_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_77_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_77_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_77_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_77_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_77_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_78_1 = ((stage_v_77_1 + (pub_r001116_7_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_77_2 + (pub_r001116_7_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_58_1 + (pub_r001116_6_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_58_2 + (pub_r001116_6_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((sec_r001116_12_1 + (pub_r001116_11_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((sec_r001116_12_2 + (pub_r001116_11_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((helper_flow_7_1 + (pub_r001116_13_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((helper_flow_7_2 + (pub_r001116_13_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((sec_r001116_9_1 + (pub_r001116_14_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((sec_r001116_9_2 + (pub_r001116_14_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((helper_flow_0_1 + (pub_r001116_16_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((helper_flow_0_2 + (pub_r001116_16_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((stage_v_59_1 + (pub_r001116_10_1 * 2)) + 257) & 127;
  int stage_v_84_2 = ((stage_v_59_2 + (pub_r001116_10_2 * 2)) + 257) & 127;
  if (stage_v_84_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_84_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_84_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_84_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_85_1 = ((pub_r001116_15_1 * 2) + 37) & 63;
  int stage_v_85_2 = ((pub_r001116_15_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = ((helper_flow_1_1 + (pub_r001116_13_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((helper_flow_1_2 + (pub_r001116_13_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((pub_r001116_4_1 * 2) + 15) & 63;
  int stage_v_87_2 = ((pub_r001116_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = ((pub_r001116_5_1 * 2) + 13) & 63;
  int stage_v_88_2 = ((pub_r001116_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_88_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_88_2) & 127;
  int stage_v_89_1 = ((pub_r001116_8_1 * 2) + 8) & 63;
  int stage_v_89_2 = ((pub_r001116_8_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((sec_r001116_19_1 + (pub_r001116_1_1 * 2)) + 275) & 127;
  int stage_v_90_2 = ((sec_r001116_19_2 + (pub_r001116_1_2 * 2)) + 275) & 127;
  if (stage_v_90_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_90_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_90_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_90_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_91_1 = ((stage_v_63_1 + (pub_r001116_15_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_63_2 + (pub_r001116_15_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((stage_v_17_1 + (pub_r001116_14_1 * 2)) + 281) & 127;
  int stage_v_92_2 = ((stage_v_17_2 + (pub_r001116_14_2 * 2)) + 281) & 127;
  if (stage_v_92_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_92_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_92_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_92_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_93_1 = ((stage_v_6_1 + (pub_r001116_1_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((stage_v_6_2 + (pub_r001116_1_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((stage_v_19_1 + (pub_r001116_5_1 * 2)) + 287) & 127;
  int stage_v_94_2 = ((stage_v_19_2 + (pub_r001116_5_2 * 2)) + 287) & 127;
  if (stage_v_94_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_94_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_94_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_94_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_95_1 = ((helper_flow_3_1 + (pub_r001116_6_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((helper_flow_3_2 + (pub_r001116_6_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((pub_r001116_0_1 * 2) + 22) & 63;
  int stage_v_96_2 = ((pub_r001116_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_96_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_96_2) & 127;
  int stage_v_97_1 = ((sec_r001116_1_1 + (pub_r001116_10_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((sec_r001116_1_2 + (pub_r001116_10_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((stage_v_11_1 + (pub_r001116_4_1 * 2)) + 299) & 127;
  int stage_v_98_2 = ((stage_v_11_2 + (pub_r001116_4_2 * 2)) + 299) & 127;
  if (stage_v_98_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_98_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_98_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_98_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_99_1 = ((pub_r001116_10_1 * 2) + 42) & 63;
  int stage_v_99_2 = ((pub_r001116_10_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = ((pub_r001116_7_1 * 2) + 19) & 63;
  int stage_v_100_2 = ((pub_r001116_7_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((stage_v_10_1 + (pub_r001116_5_1 * 2)) + 308) & 127;
  int stage_v_101_2 = ((stage_v_10_2 + (pub_r001116_5_2 * 2)) + 308) & 127;
  if (stage_v_101_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_101_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_101_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_101_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_102_1 = ((stage_v_93_1 + (pub_r001116_13_1 * 2)) + 311) & 127;
  int stage_v_102_2 = ((stage_v_93_2 + (pub_r001116_13_2 * 2)) + 311) & 127;
  if (stage_v_102_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_102_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_102_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_102_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_103_1 = ((stage_v_81_1 + (pub_r001116_1_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((stage_v_81_2 + (pub_r001116_1_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((pub_r001116_6_1 * 2) + 31) & 63;
  int stage_v_104_2 = ((pub_r001116_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_104_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_104_2) & 127;
  int stage_v_105_1 = ((helper_flow_5_1 + (pub_r001116_11_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((helper_flow_5_2 + (pub_r001116_11_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_78_1 + (pub_r001116_1_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_78_2 + (pub_r001116_1_2 * 2)) + 323) & 127;
  if (stage_v_106_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_106_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_106_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_106_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_107_1 = ((helper_flow_0_1 + (pub_r001116_0_1 * 2)) + 326) & 127;
  int stage_v_107_2 = ((helper_flow_0_2 + (pub_r001116_0_2 * 2)) + 326) & 127;
  if (stage_v_107_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_107_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_107_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_107_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_108_1 = ((pub_r001116_11_1 * 2) + 25) & 63;
  int stage_v_108_2 = ((pub_r001116_11_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((stage_v_78_1 + (pub_r001116_13_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_78_2 + (pub_r001116_13_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((sec_r001116_13_1 + (pub_r001116_7_1 * 2)) + 335) & 127;
  int stage_v_110_2 = ((sec_r001116_13_2 + (pub_r001116_7_2 * 2)) + 335) & 127;
  if (stage_v_110_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_110_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_110_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_110_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_111_1 = ((stage_v_65_1 + (pub_r001116_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_65_2 + (pub_r001116_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((stage_v_109_1 + (pub_r001116_8_1 * 2)) + 341) & 127;
  int stage_v_112_2 = ((stage_v_109_2 + (pub_r001116_8_2 * 2)) + 341) & 127;
  if (stage_v_112_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_112_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_112_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_112_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_113_1 = ((pub_r001116_3_1 * 2) + 43) & 63;
  int stage_v_113_2 = ((pub_r001116_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = ((stage_v_82_1 + (pub_r001116_8_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((stage_v_82_2 + (pub_r001116_8_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((stage_v_55_1 + (pub_r001116_9_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((stage_v_55_2 + (pub_r001116_9_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((stage_v_102_1 + (pub_r001116_12_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((stage_v_102_2 + (pub_r001116_12_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((pub_r001116_10_1 * 2) + 27) & 63;
  int stage_v_117_2 = ((pub_r001116_10_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((stage_v_38_1 + (pub_r001116_14_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_38_2 + (pub_r001116_14_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((sec_r001116_13_1 + (pub_r001116_12_1 * 2)) + 362) & 127;
  int stage_v_119_2 = ((sec_r001116_13_2 + (pub_r001116_12_2 * 2)) + 362) & 127;
  if (stage_v_119_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_119_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_119_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_119_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_120_1 = ((helper_flow_3_1 + (pub_r001116_7_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((helper_flow_3_2 + (pub_r001116_7_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_14_1 + (pub_r001116_3_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_14_2 + (pub_r001116_3_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((pub_r001116_0_1 * 2) + 44) & 63;
  int stage_v_122_2 = ((pub_r001116_0_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001116_12_1 * 2) + 42) & 63;
  int stage_v_123_2 = ((pub_r001116_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001116_14_1 * 2) + 33) & 63;
  int stage_v_124_2 = ((pub_r001116_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((stage_v_40_1 + (pub_r001116_13_1 * 2)) + 380) & 127;
  int stage_v_125_2 = ((stage_v_40_2 + (pub_r001116_13_2 * 2)) + 380) & 127;
  if (stage_v_125_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_125_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_125_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_125_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_126_1 = ((stage_v_58_1 + (pub_r001116_12_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_58_2 + (pub_r001116_12_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((helper_flow_4_1 + (pub_r001116_5_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((helper_flow_4_2 + (pub_r001116_5_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001116_4_1 * 2) + 24) & 63;
  int stage_v_128_2 = ((pub_r001116_4_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001116_7_1 * 2) + 24) & 63;
  int stage_v_129_2 = ((pub_r001116_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_5_1 + (pub_r001116_10_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_5_2 + (pub_r001116_10_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001116_6_1 * 2) + 23) & 63;
  int stage_v_131_2 = ((pub_r001116_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001116_6_1 * 2) + 25) & 63;
  int stage_v_132_2 = ((pub_r001116_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = ((stage_v_106_1 + (pub_r001116_2_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_106_2 + (pub_r001116_2_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001116_10_1 * 2) + 17) & 63;
  int stage_v_134_2 = ((pub_r001116_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((helper_flow_8_1 + (pub_r001116_15_1 * 2)) + 410) & 127;
  int stage_v_135_2 = ((helper_flow_8_2 + (pub_r001116_15_2 * 2)) + 410) & 127;
  if (stage_v_135_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_135_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_135_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_135_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_136_1 = ((stage_v_78_1 + (pub_r001116_9_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((stage_v_78_2 + (pub_r001116_9_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((pub_r001116_0_1 * 2) + 7) & 63;
  int stage_v_137_2 = ((pub_r001116_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((stage_v_42_1 + (pub_r001116_15_1 * 2)) + 419) & 127;
  int stage_v_138_2 = ((stage_v_42_2 + (pub_r001116_15_2 * 2)) + 419) & 127;
  if (stage_v_138_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_138_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_138_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_138_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_139_1 = ((stage_v_30_1 + (pub_r001116_16_1 * 2)) + 422) & 127;
  int stage_v_139_2 = ((stage_v_30_2 + (pub_r001116_16_2 * 2)) + 422) & 127;
  if (stage_v_139_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_139_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_139_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_139_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_140_1 = ((stage_v_78_1 + (pub_r001116_14_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_78_2 + (pub_r001116_14_2 * 2)) + 425) & 127;
  if (stage_v_140_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_140_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_140_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_140_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_141_1 = ((pub_r001116_10_1 * 2) + 48) & 63;
  int stage_v_141_2 = ((pub_r001116_10_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((stage_v_77_1 + (pub_r001116_1_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((stage_v_77_2 + (pub_r001116_1_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_140_1 + (pub_r001116_15_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_140_2 + (pub_r001116_15_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((pub_r001116_13_1 * 2) + 38) & 63;
  int stage_v_144_2 = ((pub_r001116_13_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_144_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_144_2) & 127;
  int stage_v_145_1 = ((pub_r001116_15_1 * 2) + 12) & 63;
  int stage_v_145_2 = ((pub_r001116_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((helper_flow_2_1 + (pub_r001116_6_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((helper_flow_2_2 + (pub_r001116_6_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((stage_v_105_1 + (pub_r001116_0_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((stage_v_105_2 + (pub_r001116_0_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((sec_r001116_7_1 + (pub_r001116_16_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((sec_r001116_7_2 + (pub_r001116_16_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_36_1 + (pub_r001116_4_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_36_2 + (pub_r001116_4_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((stage_v_111_1 + (pub_r001116_3_1 * 2)) + 455) & 127;
  int stage_v_150_2 = ((stage_v_111_2 + (pub_r001116_3_2 * 2)) + 455) & 127;
  if (stage_v_150_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_150_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_150_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_150_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_151_1 = ((pub_r001116_16_1 * 2) + 21) & 63;
  int stage_v_151_2 = ((pub_r001116_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((stage_v_53_1 + (pub_r001116_14_1 * 2)) + 461) & 127;
  int stage_v_152_2 = ((stage_v_53_2 + (pub_r001116_14_2 * 2)) + 461) & 127;
  if (stage_v_152_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_152_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_152_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_152_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_153_1 = ((pub_r001116_4_1 * 2) + 40) & 63;
  int stage_v_153_2 = ((pub_r001116_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001116_5_1 * 2) + 43) & 63;
  int stage_v_154_2 = ((pub_r001116_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001116_9_1 * 2) + 28) & 63;
  int stage_v_155_2 = ((pub_r001116_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((helper_flow_5_1 + (pub_r001116_4_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((helper_flow_5_2 + (pub_r001116_4_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((stage_v_82_1 + (pub_r001116_14_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((stage_v_82_2 + (pub_r001116_14_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((helper_flow_5_1 + (pub_r001116_5_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((helper_flow_5_2 + (pub_r001116_5_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((stage_v_67_1 + (pub_r001116_3_1 * 2)) + 482) & 127;
  int stage_v_159_2 = ((stage_v_67_2 + (pub_r001116_3_2 * 2)) + 482) & 127;
  if (stage_v_159_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_159_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_159_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_159_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_160_1 = ((pub_r001116_16_1 * 2) + 22) & 63;
  int stage_v_160_2 = ((pub_r001116_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((stage_v_149_1 + (pub_r001116_15_1 * 2)) + 488) & 127;
  int stage_v_161_2 = ((stage_v_149_2 + (pub_r001116_15_2 * 2)) + 488) & 127;
  if (stage_v_161_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_161_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_161_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_161_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_162_1 = ((sec_r001116_19_1 + (pub_r001116_8_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((sec_r001116_19_2 + (pub_r001116_8_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((sec_r001116_4_1 + (pub_r001116_8_1 * 2)) + 494) & 127;
  int stage_v_163_2 = ((sec_r001116_4_2 + (pub_r001116_8_2 * 2)) + 494) & 127;
  if (stage_v_163_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_163_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_163_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_163_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_164_1 = ((pub_r001116_5_1 * 2) + 8) & 63;
  int stage_v_164_2 = ((pub_r001116_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001116_10_1 * 2) + 33) & 63;
  int stage_v_165_2 = ((pub_r001116_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = ((stage_v_135_1 + (pub_r001116_16_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_135_2 + (pub_r001116_16_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((sec_r001116_19_1 + (pub_r001116_11_1 * 2)) + 506) & 127;
  int stage_v_167_2 = ((sec_r001116_19_2 + (pub_r001116_11_2 * 2)) + 506) & 127;
  if (stage_v_167_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_167_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_167_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_167_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_168_1 = ((sec_r001116_2_1 + (pub_r001116_4_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((sec_r001116_2_2 + (pub_r001116_4_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((helper_flow_6_1 + (pub_r001116_11_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((helper_flow_6_2 + (pub_r001116_11_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((pub_r001116_13_1 * 2) + 16) & 63;
  int stage_v_170_2 = ((pub_r001116_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001116_0_1 * 2) + 29) & 63;
  int stage_v_171_2 = ((pub_r001116_0_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_94_1 + (pub_r001116_14_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_94_2 + (pub_r001116_14_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((helper_flow_5_1 + (pub_r001116_10_1 * 2)) + 524) & 127;
  int stage_v_173_2 = ((helper_flow_5_2 + (pub_r001116_10_2 * 2)) + 524) & 127;
  if (stage_v_173_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_173_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_173_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_173_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_174_1 = ((pub_r001116_12_1 * 2) + 35) & 63;
  int stage_v_174_2 = ((pub_r001116_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((stage_v_58_1 + (pub_r001116_2_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((stage_v_58_2 + (pub_r001116_2_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_142_1 + (pub_r001116_12_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_142_2 + (pub_r001116_12_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_49_1 + (pub_r001116_14_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_49_2 + (pub_r001116_14_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((pub_r001116_16_1 * 2) + 38) & 63;
  int stage_v_178_2 = ((pub_r001116_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_178_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_178_2) & 127;
  int stage_v_179_1 = ((stage_v_29_1 + (pub_r001116_12_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_29_2 + (pub_r001116_12_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((sec_r001116_12_1 + (pub_r001116_10_1 * 2)) + 545) & 127;
  int stage_v_180_2 = ((sec_r001116_12_2 + (pub_r001116_10_2 * 2)) + 545) & 127;
  if (stage_v_180_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_180_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_180_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_180_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_181_1 = ((pub_r001116_4_1 * 2) + 18) & 63;
  int stage_v_181_2 = ((pub_r001116_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_130_1 + (pub_r001116_14_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_130_2 + (pub_r001116_14_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((stage_v_103_1 + (pub_r001116_14_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((stage_v_103_2 + (pub_r001116_14_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((stage_v_19_1 + (pub_r001116_14_1 * 2)) + 557) & 127;
  int stage_v_184_2 = ((stage_v_19_2 + (pub_r001116_14_2 * 2)) + 557) & 127;
  if (stage_v_184_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_184_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_184_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_184_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_185_1 = ((stage_v_78_1 + (pub_r001116_1_1 * 2)) + 560) & 127;
  int stage_v_185_2 = ((stage_v_78_2 + (pub_r001116_1_2 * 2)) + 560) & 127;
  if (stage_v_185_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_185_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_185_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_185_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_186_1 = ((pub_r001116_16_1 * 2) + 16) & 63;
  int stage_v_186_2 = ((pub_r001116_16_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = ((stage_v_14_1 + (pub_r001116_5_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_14_2 + (pub_r001116_5_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((pub_r001116_5_1 * 2) + 30) & 63;
  int stage_v_188_2 = ((pub_r001116_5_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001116_3_1 * 2) + 46) & 63;
  int stage_v_189_2 = ((pub_r001116_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((sec_r001116_8_1 + (pub_r001116_5_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((sec_r001116_8_2 + (pub_r001116_5_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001116_8_1 * 2) + 33) & 63;
  int stage_v_191_2 = ((pub_r001116_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_84_1 + (pub_r001116_5_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_84_2 + (pub_r001116_5_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((sec_r001116_5_1 + (pub_r001116_12_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((sec_r001116_5_2 + (pub_r001116_12_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((stage_v_185_1 + (pub_r001116_1_1 * 2)) + 587) & 127;
  int stage_v_194_2 = ((stage_v_185_2 + (pub_r001116_1_2 * 2)) + 587) & 127;
  if (stage_v_194_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_194_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_194_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_194_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_195_1 = ((stage_v_176_1 + (pub_r001116_13_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_176_2 + (pub_r001116_13_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_63_1 + (pub_r001116_8_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_63_2 + (pub_r001116_8_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((pub_r001116_0_1 * 2) + 28) & 63;
  int stage_v_197_2 = ((pub_r001116_0_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((sec_r001116_19_1 + (pub_r001116_5_1 * 2)) + 599) & 127;
  int stage_v_198_2 = ((sec_r001116_19_2 + (pub_r001116_5_2 * 2)) + 599) & 127;
  if (stage_v_198_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_198_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_198_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_198_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_199_1 = ((stage_v_146_1 + (pub_r001116_16_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_146_2 + (pub_r001116_16_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_192_1 + (pub_r001116_8_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_192_2 + (pub_r001116_8_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((stage_v_19_1 + (pub_r001116_8_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((stage_v_19_2 + (pub_r001116_8_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((stage_v_175_1 + (pub_r001116_3_1 * 2)) + 611) & 127;
  int stage_v_202_2 = ((stage_v_175_2 + (pub_r001116_3_2 * 2)) + 611) & 127;
  if (stage_v_202_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_202_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_202_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_202_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_203_1 = ((stage_v_82_1 + (pub_r001116_8_1 * 2)) + 614) & 127;
  int stage_v_203_2 = ((stage_v_82_2 + (pub_r001116_8_2 * 2)) + 614) & 127;
  if (stage_v_203_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_203_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_203_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_203_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_204_1 = ((stage_v_77_1 + (pub_r001116_1_1 * 2)) + 617) & 127;
  int stage_v_204_2 = ((stage_v_77_2 + (pub_r001116_1_2 * 2)) + 617) & 127;
  if (stage_v_204_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_204_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_204_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_204_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_205_1 = ((pub_r001116_16_1 * 2) + 50) & 63;
  int stage_v_205_2 = ((pub_r001116_16_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_205_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_205_2) & 127;
  int stage_v_206_1 = ((pub_r001116_7_1 * 2) + 6) & 63;
  int stage_v_206_2 = ((pub_r001116_7_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_206_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_206_2) & 127;
  int stage_v_207_1 = ((sec_r001116_21_1 + (pub_r001116_1_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((sec_r001116_21_2 + (pub_r001116_1_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((stage_v_115_1 + (pub_r001116_6_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((stage_v_115_2 + (pub_r001116_6_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((stage_v_82_1 + (pub_r001116_2_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((stage_v_82_2 + (pub_r001116_2_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_149_1 + (pub_r001116_8_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_149_2 + (pub_r001116_8_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_116_1 + (pub_r001116_7_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_116_2 + (pub_r001116_7_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((pub_r001116_10_1 * 2) + 34) & 63;
  int stage_v_212_2 = ((pub_r001116_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = ((pub_r001116_3_1 * 2) + 6) & 63;
  int stage_v_213_2 = ((pub_r001116_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_213_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_213_2) & 127;
  int stage_v_214_1 = ((stage_v_79_1 + (pub_r001116_9_1 * 2)) + 647) & 127;
  int stage_v_214_2 = ((stage_v_79_2 + (pub_r001116_9_2 * 2)) + 647) & 127;
  if (stage_v_214_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_214_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_214_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_214_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_215_1 = ((stage_v_183_1 + (pub_r001116_1_1 * 2)) + 650) & 127;
  int stage_v_215_2 = ((stage_v_183_2 + (pub_r001116_1_2 * 2)) + 650) & 127;
  if (stage_v_215_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_215_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_215_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_215_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_216_1 = ((stage_v_18_1 + (pub_r001116_9_1 * 2)) + 653) & 127;
  int stage_v_216_2 = ((stage_v_18_2 + (pub_r001116_9_2 * 2)) + 653) & 127;
  if (stage_v_216_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_216_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_216_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_216_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_217_1 = ((stage_v_121_1 + (pub_r001116_1_1 * 2)) + 656) & 127;
  int stage_v_217_2 = ((stage_v_121_2 + (pub_r001116_1_2 * 2)) + 656) & 127;
  if (stage_v_217_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_217_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_217_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_217_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_218_1 = ((stage_v_209_1 + (pub_r001116_6_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_209_2 + (pub_r001116_6_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 53)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 53)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((stage_v_180_1 + (pub_r001116_9_1 * 2)) + 662) & 127;
  int stage_v_219_2 = ((stage_v_180_2 + (pub_r001116_9_2 * 2)) + 662) & 127;
  if (stage_v_219_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_219_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_219_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_219_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_220_1 = ((stage_v_112_1 + (pub_r001116_9_1 * 2)) + 665) & 127;
  int stage_v_220_2 = ((stage_v_112_2 + (pub_r001116_9_2 * 2)) + 665) & 127;
  if (stage_v_220_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_220_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_220_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_220_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_221_1 = ((pub_r001116_10_1 * 2) + 35) & 63;
  int stage_v_221_2 = ((pub_r001116_10_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((stage_v_77_1 + (pub_r001116_10_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((stage_v_77_2 + (pub_r001116_10_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((stage_v_114_1 + (pub_r001116_3_1 * 2)) + 674) & 127;
  int stage_v_223_2 = ((stage_v_114_2 + (pub_r001116_3_2 * 2)) + 674) & 127;
  if (stage_v_223_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_223_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_223_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_223_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_224_1 = ((pub_r001116_14_1 * 2) + 16) & 63;
  int stage_v_224_2 = ((pub_r001116_14_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = ((stage_v_118_1 + (pub_r001116_16_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_118_2 + (pub_r001116_16_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((pub_r001116_13_1 * 2) + 21) & 63;
  int stage_v_226_2 = ((pub_r001116_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = ((stage_v_215_1 + (pub_r001116_8_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_215_2 + (pub_r001116_8_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((stage_v_190_1 + (pub_r001116_1_1 * 2)) + 689) & 127;
  int stage_v_228_2 = ((stage_v_190_2 + (pub_r001116_1_2 * 2)) + 689) & 127;
  if (stage_v_228_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_228_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_228_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_228_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_229_1 = ((stage_v_121_1 + (pub_r001116_14_1 * 2)) + 692) & 127;
  int stage_v_229_2 = ((stage_v_121_2 + (pub_r001116_14_2 * 2)) + 692) & 127;
  if (stage_v_229_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_229_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_229_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_229_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_230_1 = ((stage_v_50_1 + (pub_r001116_6_1 * 2)) + 695) & 127;
  int stage_v_230_2 = ((stage_v_50_2 + (pub_r001116_6_2 * 2)) + 695) & 127;
  if (stage_v_230_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_230_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_230_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_230_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_231_1 = ((stage_v_227_1 + (pub_r001116_3_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_227_2 + (pub_r001116_3_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((stage_v_130_1 + (pub_r001116_2_1 * 2)) + 701) & 127;
  int stage_v_232_2 = ((stage_v_130_2 + (pub_r001116_2_2 * 2)) + 701) & 127;
  if (stage_v_232_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_232_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_232_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_232_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_232_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_232_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_232_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_232_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_233_1 = ((pub_r001116_11_1 * 2) + 40) & 63;
  int stage_v_233_2 = ((pub_r001116_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_98_1 + (pub_r001116_3_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_98_2 + (pub_r001116_3_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((stage_v_202_1 + (pub_r001116_4_1 * 2)) + 710) & 127;
  int stage_v_235_2 = ((stage_v_202_2 + (pub_r001116_4_2 * 2)) + 710) & 127;
  if (stage_v_235_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_235_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_235_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_235_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_235_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_235_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_235_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_235_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_236_1 = ((sec_r001116_14_1 + (pub_r001116_15_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((sec_r001116_14_2 + (pub_r001116_15_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((pub_r001116_1_1 * 2) + 8) & 63;
  int stage_v_237_2 = ((pub_r001116_1_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((stage_v_57_1 + (pub_r001116_9_1 * 2)) + 719) & 127;
  int stage_v_238_2 = ((stage_v_57_2 + (pub_r001116_9_2 * 2)) + 719) & 127;
  if (stage_v_238_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_238_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_238_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_238_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_238_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_238_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_238_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_238_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_239_1 = ((stage_v_105_1 + (pub_r001116_0_1 * 2)) + 722) & 127;
  int stage_v_239_2 = ((stage_v_105_2 + (pub_r001116_0_2 * 2)) + 722) & 127;
  if (stage_v_239_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_239_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_239_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_239_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_239_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_239_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_239_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_239_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_240_1 = ((sec_r001116_15_1 + (pub_r001116_9_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((sec_r001116_15_2 + (pub_r001116_9_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((stage_v_223_1 + (pub_r001116_15_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((stage_v_223_2 + (pub_r001116_15_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((pub_r001116_10_1 * 2) + 44) & 63;
  int stage_v_242_2 = ((pub_r001116_10_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001116_7_1 * 2) + 41) & 63;
  int stage_v_243_2 = ((pub_r001116_7_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((stage_v_227_1 + (pub_r001116_9_1 * 2)) + 737) & 127;
  int stage_v_244_2 = ((stage_v_227_2 + (pub_r001116_9_2 * 2)) + 737) & 127;
  if (stage_v_244_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_244_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_244_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_244_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_244_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_244_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_244_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_244_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_245_1 = ((pub_r001116_1_1 * 2) + 27) & 63;
  int stage_v_245_2 = ((pub_r001116_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((stage_v_63_1 + (pub_r001116_5_1 * 2)) + 743) & 127;
  int stage_v_246_2 = ((stage_v_63_2 + (pub_r001116_5_2 * 2)) + 743) & 127;
  if (stage_v_246_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_246_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_246_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_246_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_246_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_246_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_246_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_246_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_247_1 = ((stage_v_37_1 + (pub_r001116_14_1 * 2)) + 746) & 127;
  int stage_v_247_2 = ((stage_v_37_2 + (pub_r001116_14_2 * 2)) + 746) & 127;
  if (stage_v_247_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_247_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_247_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_247_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_247_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_247_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_247_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_247_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_248_1 = ((pub_r001116_15_1 * 2) + 47) & 63;
  int stage_v_248_2 = ((pub_r001116_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001116_13_1 * 2) + 20) & 63;
  int stage_v_249_2 = ((pub_r001116_13_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = ((pub_r001116_15_1 * 2) + 21) & 63;
  int stage_v_250_2 = ((pub_r001116_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = ((sec_r001116_3_1 + (pub_r001116_2_1 * 2)) + 758) & 127;
  int stage_v_251_2 = ((sec_r001116_3_2 + (pub_r001116_2_2 * 2)) + 758) & 127;
  if (stage_v_251_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_251_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_251_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_251_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_251_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_251_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_251_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_251_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_252_1 = ((stage_v_228_1 + (pub_r001116_0_1 * 2)) + 761) & 127;
  int stage_v_252_2 = ((stage_v_228_2 + (pub_r001116_0_2 * 2)) + 761) & 127;
  if (stage_v_252_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_252_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_252_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_252_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_252_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_252_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_252_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_252_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_253_1 = ((stage_v_140_1 + (pub_r001116_9_1 * 2)) + 764) & 127;
  int stage_v_253_2 = ((stage_v_140_2 + (pub_r001116_9_2 * 2)) + 764) & 127;
  if (stage_v_253_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_253_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_253_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_253_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_253_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_253_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_253_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_253_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_254_1 = ((stage_v_26_1 + (pub_r001116_14_1 * 2)) + 767) & 127;
  int stage_v_254_2 = ((stage_v_26_2 + (pub_r001116_14_2 * 2)) + 767) & 127;
  if (stage_v_254_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_254_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_254_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_254_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_254_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_254_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_254_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_254_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001116_8_1 == pub_r001116_8_2);
  __CPROVER_assume(sec_r001116_17_1 != sec_r001116_17_2);
  __CPROVER_assume(sec_r001116_21_1 != sec_r001116_21_2);
  __CPROVER_assume(sec_r001116_8_1 != sec_r001116_8_2);
  __CPROVER_assume(sec_r001116_11_1 != sec_r001116_11_2);
  __CPROVER_assume(sec_r001116_4_1 != sec_r001116_4_2);
  __CPROVER_assume(sec_r001116_0_1 != sec_r001116_0_2);
  __CPROVER_assume(sec_r001116_3_1 != sec_r001116_3_2);
  __CPROVER_assume(sec_r001116_2_1 != sec_r001116_2_2);
  __CPROVER_assume(pub_r001116_4_1 == pub_r001116_4_2);
  __CPROVER_assume(sec_r001116_7_1 != sec_r001116_7_2);
  __CPROVER_assume(pub_r001116_9_1 == pub_r001116_9_2);
  __CPROVER_assume(pub_r001116_16_1 == pub_r001116_16_2);
  __CPROVER_assume(sec_r001116_14_1 != sec_r001116_14_2);
  __CPROVER_assume(pub_r001116_2_1 == pub_r001116_2_2);
  __CPROVER_assume(pub_r001116_1_1 == pub_r001116_1_2);
  __CPROVER_assume(sec_r001116_6_1 != sec_r001116_6_2);
  __CPROVER_assume(pub_r001116_7_1 == pub_r001116_7_2);
  __CPROVER_assume(pub_r001116_15_1 == pub_r001116_15_2);
  __CPROVER_assume(sec_r001116_12_1 != sec_r001116_12_2);
  __CPROVER_assume(sec_r001116_15_1 != sec_r001116_15_2);
  __CPROVER_assume(pub_r001116_3_1 == pub_r001116_3_2);
  __CPROVER_assume(pub_r001116_10_1 == pub_r001116_10_2);
  __CPROVER_assume(sec_r001116_16_1 != sec_r001116_16_2);
  __CPROVER_assume(pub_r001116_13_1 == pub_r001116_13_2);
  __CPROVER_assume(pub_r001116_5_1 == pub_r001116_5_2);
  __CPROVER_assume(pub_r001116_0_1 == pub_r001116_0_2);
  __CPROVER_assume(sec_r001116_13_1 != sec_r001116_13_2);
  __CPROVER_assume(sec_r001116_18_1 != sec_r001116_18_2);
  __CPROVER_assume(pub_r001116_6_1 == pub_r001116_6_2);
  __CPROVER_assume(pub_r001116_11_1 == pub_r001116_11_2);
  __CPROVER_assume(sec_r001116_5_1 != sec_r001116_5_2);
  __CPROVER_assume(pub_r001116_12_1 == pub_r001116_12_2);
  __CPROVER_assume(sec_r001116_9_1 != sec_r001116_9_2);
  __CPROVER_assume(pub_r001116_14_1 == pub_r001116_14_2);
  __CPROVER_assume(sec_r001116_10_1 != sec_r001116_10_2);
  __CPROVER_assume(sec_r001116_1_1 != sec_r001116_1_2);
  __CPROVER_assume(sec_r001116_19_1 != sec_r001116_19_2);
  __CPROVER_assume(sec_r001116_20_1 != sec_r001116_20_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.watermark == st_var_1_2.watermark);
  assert(st_var_1_1.head == st_var_1_2.head);
  assert(st_var_1_1.state == st_var_1_2.state);
  assert(st_var_1_1.checksum == st_var_1_2.checksum);
  assert(st_var_1_1.capacity == st_var_1_2.capacity);
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
  assert(helper_flow_8_1 == helper_flow_8_2);
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
}


