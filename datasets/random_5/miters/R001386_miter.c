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
struct Vector3D_R001386_8613_0
{
  int norm_sq;
  int pitch;
  int coord_z;
  int heading;
  int coord_x;
  int coord_y;
  int buffer[3];
};
struct SensorNode_R001386_8613_1
{
  int status;
  int offset;
  unsigned char threshold;
  int gain;
  int calib;
  int buffer[3];
};
struct FilterState_R001386_8613_2
{
  short mode;
  unsigned char prev_in;
  unsigned char damping;
  short gain_db;
  int prev_out;
  int cutoff;
  int buffer[3];
};
union TelemetryField_R001386_8613_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union ColorPixel_R001386_8613_1
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
void fn_R001386_8613_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st_1 = {0};
  struct Vector3D_R001386_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int delta_89_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_89_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_89_1 > 46)
  {
    acc_1 = ((acc_1 + (delta_89_1 * 2)) + 5) & 127;
    aux_1 ^= delta_89_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_89_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_89_2 > 46)
  {
    acc_2 = ((acc_2 + (delta_89_2 * 2)) + 5) & 127;
    aux_2 ^= delta_89_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_89_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_89_1 == delta_89_2);
}

int fn_R001386_8613_0(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int delta_89 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_89 > 46)
  {
    acc = ((acc + (delta_89 * 2)) + 5) & 127;
    aux ^= delta_89 & 15;
  }
  else
  {
    acc = ((acc - delta_89) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001386_8613_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st_1 = {0};
  struct SensorNode_R001386_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int coefficient_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_97_1)
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

  switch (coefficient_97_2)
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
  int metric_30_1 = local_arr_1[aux_1 % 3];
  int metric_30_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (metric_30_1 * 2)) & 127;
  acc_2 = (acc_2 + (metric_30_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_97_1 == coefficient_97_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(metric_30_1 == metric_30_2);
}

int fn_R001386_8613_1(int p0, int p1)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int coefficient_97 = (aux + st.buffer[1]) & 3;
  switch (coefficient_97)
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
  int metric_30 = local_arr[aux % 3];
  acc = (acc + (metric_30 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001386_8613_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st_1 = {0};
  struct Vector3D_R001386_8613_0 st_2 = {0};
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
  int tally_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tally_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tally_55_1 > 33)
  {
    acc_1 = ((acc_1 + (tally_55_1 * 2)) + 5) & 127;
    aux_1 ^= tally_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tally_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tally_55_2 > 33)
  {
    acc_2 = ((acc_2 + (tally_55_2 * 2)) + 5) & 127;
    aux_2 ^= tally_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tally_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int offset_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_13_1) & 63;
  aux_2 = (aux_2 + offset_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_55_1 == tally_55_2);
  assert(offset_13_1 == offset_13_2);
}

int fn_R001386_8613_2(int p0, int p1, int p2)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (tally_55 > 33)
  {
    acc = ((acc + (tally_55 * 2)) + 5) & 127;
    aux ^= tally_55 & 15;
  }
  else
  {
    acc = ((acc - tally_55) + 11) & 127;
    aux += 3;
  }
  int offset_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_13) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001386_8613_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st_1 = {0};
  struct SensorNode_R001386_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int coefficient_15_1 = local_arr_1[aux_1 % 3];
  int coefficient_15_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (coefficient_15_1 * 2)) & 127;
  acc_2 = (acc_2 + (coefficient_15_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_17_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_17_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_17_1) & 63;
  aux_2 = (aux_2 + mask_17_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(coefficient_15_1 == coefficient_15_2);
  assert(mask_17_1 == mask_17_2);
}

int fn_R001386_8613_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int local_arr[3] = {4, 9, 15};
  int coefficient_15 = local_arr[aux % 3];
  acc = (acc + (coefficient_15 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_17 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_17) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001386_8613_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st_1 = {0};
  struct SensorNode_R001386_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int cursor_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_42_1 > 30)
  {
    acc_1 = ((acc_1 + (cursor_42_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_42_2 > 30)
  {
    acc_2 = ((acc_2 + (cursor_42_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_42_2) + 11) & 127;
    aux_2 += 3;
  }
  int quantum_23_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_23_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_23_1)
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

  switch (quantum_23_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_42_1 == cursor_42_2);
  assert(quantum_23_1 == quantum_23_2);
}

int fn_R001386_8613_4(int p0, int p1, int p2)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int cursor_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_42 > 30)
  {
    acc = ((acc + (cursor_42 * 2)) + 5) & 127;
    aux ^= cursor_42 & 15;
  }
  else
  {
    acc = ((acc - cursor_42) + 11) & 127;
    aux += 3;
  }
  int quantum_23 = (aux + st.buffer[1]) & 3;
  switch (quantum_23)
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

void fn_R001386_8613_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int quantum_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_75_1 > 24)
  {
    acc_1 = ((acc_1 + (quantum_75_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_75_2 > 24)
  {
    acc_2 = ((acc_2 + (quantum_75_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_75_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_72_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int mask_72_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + mask_72_1) & 63;
  aux_2 = (aux_2 + mask_72_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_99_1 = local_arr_1[aux_1 % 3];
  int delta_99_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_99_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_99_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_75_1 == quantum_75_2);
  assert(mask_72_1 == mask_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_99_1 == delta_99_2);
}

int fn_R001386_8613_5(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int quantum_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_75 > 24)
  {
    acc = ((acc + (quantum_75 * 2)) + 5) & 127;
    aux ^= quantum_75 & 15;
  }
  else
  {
    acc = ((acc - quantum_75) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_72 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + mask_72) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int delta_99 = local_arr[aux % 3];
  acc = (acc + (delta_99 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001386_8613_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_20_1 = 0;
  int delta_20_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    delta_20_1 = ((delta_20_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_20_2 = ((delta_20_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_20_1) & 127;
    acc_2 = (acc_2 + delta_20_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_20_1 == delta_20_2);
}

int fn_R001386_8613_6(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_20 = 0;
  for (int k = 0; k < 2; k++)
  {
    delta_20 = ((delta_20 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_20) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001386_8613_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st_1 = {0};
  struct Vector3D_R001386_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int delta_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_65_1 > 50)
  {
    acc_1 = ((acc_1 + (delta_65_1 * 2)) + 5) & 127;
    aux_1 ^= delta_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_65_2 > 50)
  {
    acc_2 = ((acc_2 + (delta_65_2 * 2)) + 5) & 127;
    aux_2 ^= delta_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_65_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_28_1 = local_arr_1[aux_1 % 3];
  int offset_28_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_28_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_28_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quotient_27_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_27_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_27_1) & 63;
  aux_2 = (aux_2 + quotient_27_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_65_1 == delta_65_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_28_1 == offset_28_2);
  assert(quotient_27_1 == quotient_27_2);
}

int fn_R001386_8613_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int delta_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_65 > 50)
  {
    acc = ((acc + (delta_65 * 2)) + 5) & 127;
    aux ^= delta_65 & 15;
  }
  else
  {
    acc = ((acc - delta_65) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_28 = local_arr[aux % 3];
  acc = (acc + (offset_28 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quotient_27 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_27) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001386_8613_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int coefficient_66_1 = 0;
  int coefficient_66_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    coefficient_66_1 = ((coefficient_66_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_66_2 = ((coefficient_66_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_66_1) & 127;
    acc_2 = (acc_2 + coefficient_66_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_66_1 == coefficient_66_2);
}

int fn_R001386_8613_8(int p0, int p1, int p2)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int coefficient_66 = 0;
  for (int k = 0; k < 3; k++)
  {
    coefficient_66 = ((coefficient_66 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_66) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001386_8613_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st_1 = {0};
  struct Vector3D_R001386_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int index_reg_39_1 = (aux_1 + st_1.buffer[1]) & 3;
  int index_reg_39_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (index_reg_39_1)
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

  switch (index_reg_39_2)
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

  int coefficient_80_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_80_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_80_1) & 63;
  aux_2 = (aux_2 + coefficient_80_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int mask_46_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int mask_46_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (mask_46_1 > 44)
  {
    acc_1 = ((acc_1 + (mask_46_1 * 2)) + 5) & 127;
    aux_1 ^= mask_46_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - mask_46_1) + 11) & 127;
    aux_1 += 3;
  }
  if (mask_46_2 > 44)
  {
    acc_2 = ((acc_2 + (mask_46_2 * 2)) + 5) & 127;
    aux_2 ^= mask_46_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - mask_46_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_39_1 == index_reg_39_2);
  assert(coefficient_80_1 == coefficient_80_2);
  assert(mask_46_1 == mask_46_2);
}

int fn_R001386_8613_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int index_reg_39 = (aux + st.buffer[1]) & 3;
  switch (index_reg_39)
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

  int coefficient_80 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_80) & 63;
  acc ^= aux;
  int mask_46 = ((st.buffer[0] * 3) + aux) & 63;
  if (mask_46 > 44)
  {
    acc = ((acc + (mask_46 * 2)) + 5) & 127;
    aux ^= mask_46 & 15;
  }
  else
  {
    acc = ((acc - mask_46) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001386_8613_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st_1 = {0};
  struct Vector3D_R001386_8613_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int delta_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_61_1) & 63;
  aux_2 = (aux_2 + delta_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tally_99_1 = 0;
  int tally_99_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_99_1 = ((tally_99_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_99_2 = ((tally_99_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_99_1) & 127;
    acc_2 = (acc_2 + tally_99_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_61_1 == delta_61_2);
  assert(tally_99_1 == tally_99_2);
}

int fn_R001386_8613_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001386_8613_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int delta_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_61) & 63;
  acc ^= aux;
  int tally_99 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_99 = ((tally_99 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_99) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001386_8613_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st_1 = {0};
  struct SensorNode_R001386_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int delta_95_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_95_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_95_1 > 20)
  {
    acc_1 = ((acc_1 + (delta_95_1 * 2)) + 5) & 127;
    aux_1 ^= delta_95_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_95_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_95_2 > 20)
  {
    acc_2 = ((acc_2 + (delta_95_2 * 2)) + 5) & 127;
    aux_2 ^= delta_95_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_95_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_26_1 = 0;
  int tracker_26_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tracker_26_1 = ((tracker_26_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_26_2 = ((tracker_26_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_26_1) & 127;
    acc_2 = (acc_2 + tracker_26_2) & 127;
  }

  int scale_71_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_71_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_71_1)
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

  switch (scale_71_2)
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
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_95_1 == delta_95_2);
  assert(tracker_26_1 == tracker_26_2);
  assert(scale_71_1 == scale_71_2);
}

int fn_R001386_8613_11(int p0, int p1)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int delta_95 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_95 > 20)
  {
    acc = ((acc + (delta_95 * 2)) + 5) & 127;
    aux ^= delta_95 & 15;
  }
  else
  {
    acc = ((acc - delta_95) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_26 = 0;
  for (int k = 0; k < 2; k++)
  {
    tracker_26 = ((tracker_26 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_26) & 127;
  }

  int scale_71 = (aux + st.buffer[1]) & 3;
  switch (scale_71)
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

void fn_R001386_8613_12_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int scale_70_1 = (aux_1 + st_1.buffer[1]) & 3;
  int scale_70_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (scale_70_1)
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

  switch (scale_70_2)
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
  int mask_27_1 = local_arr_1[aux_1 % 3];
  int mask_27_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_27_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_27_2 * 2)) & 127;
  int threshold_61_1 = 0;
  int threshold_61_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_61_1 = ((threshold_61_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_61_2 = ((threshold_61_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_61_1) & 127;
    acc_2 = (acc_2 + threshold_61_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_70_1 == scale_70_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_27_1 == mask_27_2);
  assert(threshold_61_1 == threshold_61_2);
}

int fn_R001386_8613_12(int p0, int p1)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int scale_70 = (aux + st.buffer[1]) & 3;
  switch (scale_70)
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
  int mask_27 = local_arr[aux % 3];
  acc = (acc + (mask_27 * 2)) & 127;
  int threshold_61 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_61 = ((threshold_61 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_61) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001386_8613_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int tracker_27_1 = 0;
  int tracker_27_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_27_1 = ((tracker_27_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_27_2 = ((tracker_27_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_27_1) & 127;
    acc_2 = (acc_2 + tracker_27_2) & 127;
  }

  int checksum_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_49_1) & 63;
  aux_2 = (aux_2 + checksum_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_97_1 > 30)
  {
    acc_1 = ((acc_1 + (checksum_97_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_97_2 > 30)
  {
    acc_2 = ((acc_2 + (checksum_97_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int sample_24_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_24_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_24_1)
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

  switch (sample_24_2)
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
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_27_1 == tracker_27_2);
  assert(checksum_49_1 == checksum_49_2);
  assert(checksum_97_1 == checksum_97_2);
  assert(sample_24_1 == sample_24_2);
}

int fn_R001386_8613_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int tracker_27 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_27 = ((tracker_27 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_27) & 127;
  }

  int checksum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_49) & 63;
  acc ^= aux;
  int checksum_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_97 > 30)
  {
    acc = ((acc + (checksum_97 * 2)) + 5) & 127;
    aux ^= checksum_97 & 15;
  }
  else
  {
    acc = ((acc - checksum_97) + 11) & 127;
    aux += 3;
  }
  int sample_24 = (aux + st.buffer[1]) & 3;
  switch (sample_24)
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

void fn_R001386_8613_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st_1 = {0};
  struct SensorNode_R001386_8613_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int checksum_23_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_23_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_23_1) & 63;
  aux_2 = (aux_2 + checksum_23_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_88_1 = local_arr_1[aux_1 % 3];
  int weight_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_88_2 * 2)) & 127;
  int index_reg_73_1 = 0;
  int index_reg_73_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    index_reg_73_1 = ((index_reg_73_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_73_2 = ((index_reg_73_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_73_1) & 127;
    acc_2 = (acc_2 + index_reg_73_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.status == st_2.status);
  assert(st_1.offset == st_2.offset);
  assert(st_1.threshold == st_2.threshold);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(checksum_23_1 == checksum_23_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_88_1 == weight_88_2);
  assert(index_reg_73_1 == index_reg_73_2);
}

int fn_R001386_8613_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001386_8613_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int checksum_23 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_23) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int weight_88 = local_arr[aux % 3];
  acc = (acc + (weight_88 * 2)) & 127;
  int index_reg_73 = 0;
  for (int k = 0; k < 3; k++)
  {
    index_reg_73 = ((index_reg_73 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_73) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001386_8613_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st_1 = {0};
  struct FilterState_R001386_8613_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int index_reg_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_19_1) & 63;
  aux_2 = (aux_2 + index_reg_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.damping == st_2.damping);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_19_1 == index_reg_19_2);
}

int fn_R001386_8613_15(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001386_8613_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int index_reg_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001386_0_1;
  int sec_r001386_0_2;
  int sec_r001386_1_1;
  int sec_r001386_1_2;
  int sec_r001386_2_1;
  int sec_r001386_2_2;
  int sec_r001386_3_1;
  int sec_r001386_3_2;
  int sec_r001386_4_1;
  int sec_r001386_4_2;
  int sec_r001386_5_1;
  int sec_r001386_5_2;
  int sec_r001386_6_1;
  int sec_r001386_6_2;
  int sec_r001386_7_1;
  int sec_r001386_7_2;
  int sec_r001386_8_1;
  int sec_r001386_8_2;
  int sec_r001386_9_1;
  int sec_r001386_9_2;
  int sec_r001386_10_1;
  int sec_r001386_10_2;
  int sec_r001386_11_1;
  int sec_r001386_11_2;
  int sec_r001386_12_1;
  int sec_r001386_12_2;
  int sec_r001386_13_1;
  int sec_r001386_13_2;
  int sec_r001386_14_1;
  int sec_r001386_14_2;
  int sec_r001386_15_1;
  int sec_r001386_15_2;
  int sec_r001386_16_1;
  int sec_r001386_16_2;
  int sec_r001386_17_1;
  int sec_r001386_17_2;
  int sec_r001386_18_1;
  int sec_r001386_18_2;
  int sec_r001386_19_1;
  int sec_r001386_19_2;
  int sec_r001386_20_1;
  int sec_r001386_20_2;
  int pub_r001386_0_1;
  int pub_r001386_0_2;
  int pub_r001386_1_1;
  int pub_r001386_1_2;
  int pub_r001386_2_1;
  int pub_r001386_2_2;
  int pub_r001386_3_1;
  int pub_r001386_3_2;
  int pub_r001386_4_1;
  int pub_r001386_4_2;
  int pub_r001386_5_1;
  int pub_r001386_5_2;
  int pub_r001386_6_1;
  int pub_r001386_6_2;
  int pub_r001386_7_1;
  int pub_r001386_7_2;
  int pub_r001386_8_1;
  int pub_r001386_8_2;
  int pub_r001386_9_1;
  int pub_r001386_9_2;
  int pub_r001386_10_1;
  int pub_r001386_10_2;
  int pub_r001386_11_1;
  int pub_r001386_11_2;
  int pub_r001386_12_1;
  int pub_r001386_12_2;
  int pub_r001386_13_1;
  int pub_r001386_13_2;
  int pub_r001386_14_1;
  int pub_r001386_14_2;
  int pub_r001386_15_1;
  int pub_r001386_15_2;
  int pub_r001386_16_1;
  int pub_r001386_16_2;
  int pub_r001386_17_1;
  int pub_r001386_17_2;
  int pub_r001386_18_1;
  int pub_r001386_18_2;
  int pub_r001386_19_1;
  int pub_r001386_19_2;
  int pub_r001386_20_1;
  int pub_r001386_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001386_0_1 >= (-100)) && (pub_r001386_0_1 <= 100));
  __CPROVER_assume((pub_r001386_0_2 >= (-100)) && (pub_r001386_0_2 <= 100));
  __CPROVER_assume((pub_r001386_1_1 >= (-100)) && (pub_r001386_1_1 <= 100));
  __CPROVER_assume((pub_r001386_1_2 >= (-100)) && (pub_r001386_1_2 <= 100));
  __CPROVER_assume((pub_r001386_2_1 >= (-100)) && (pub_r001386_2_1 <= 100));
  __CPROVER_assume((pub_r001386_2_2 >= (-100)) && (pub_r001386_2_2 <= 100));
  __CPROVER_assume((pub_r001386_3_1 >= (-100)) && (pub_r001386_3_1 <= 100));
  __CPROVER_assume((pub_r001386_3_2 >= (-100)) && (pub_r001386_3_2 <= 100));
  __CPROVER_assume((pub_r001386_4_1 >= (-100)) && (pub_r001386_4_1 <= 100));
  __CPROVER_assume((pub_r001386_4_2 >= (-100)) && (pub_r001386_4_2 <= 100));
  __CPROVER_assume((pub_r001386_5_1 >= (-100)) && (pub_r001386_5_1 <= 100));
  __CPROVER_assume((pub_r001386_5_2 >= (-100)) && (pub_r001386_5_2 <= 100));
  __CPROVER_assume((pub_r001386_6_1 >= (-100)) && (pub_r001386_6_1 <= 100));
  __CPROVER_assume((pub_r001386_6_2 >= (-100)) && (pub_r001386_6_2 <= 100));
  __CPROVER_assume((pub_r001386_7_1 >= (-100)) && (pub_r001386_7_1 <= 100));
  __CPROVER_assume((pub_r001386_7_2 >= (-100)) && (pub_r001386_7_2 <= 100));
  __CPROVER_assume((pub_r001386_8_1 >= (-100)) && (pub_r001386_8_1 <= 100));
  __CPROVER_assume((pub_r001386_8_2 >= (-100)) && (pub_r001386_8_2 <= 100));
  __CPROVER_assume((pub_r001386_9_1 >= (-100)) && (pub_r001386_9_1 <= 100));
  __CPROVER_assume((pub_r001386_9_2 >= (-100)) && (pub_r001386_9_2 <= 100));
  __CPROVER_assume((pub_r001386_10_1 >= (-100)) && (pub_r001386_10_1 <= 100));
  __CPROVER_assume((pub_r001386_10_2 >= (-100)) && (pub_r001386_10_2 <= 100));
  __CPROVER_assume((pub_r001386_11_1 >= (-100)) && (pub_r001386_11_1 <= 100));
  __CPROVER_assume((pub_r001386_11_2 >= (-100)) && (pub_r001386_11_2 <= 100));
  __CPROVER_assume((pub_r001386_12_1 >= (-100)) && (pub_r001386_12_1 <= 100));
  __CPROVER_assume((pub_r001386_12_2 >= (-100)) && (pub_r001386_12_2 <= 100));
  __CPROVER_assume((pub_r001386_13_1 >= (-100)) && (pub_r001386_13_1 <= 100));
  __CPROVER_assume((pub_r001386_13_2 >= (-100)) && (pub_r001386_13_2 <= 100));
  __CPROVER_assume((pub_r001386_14_1 >= (-100)) && (pub_r001386_14_1 <= 100));
  __CPROVER_assume((pub_r001386_14_2 >= (-100)) && (pub_r001386_14_2 <= 100));
  __CPROVER_assume((pub_r001386_15_1 >= (-100)) && (pub_r001386_15_1 <= 100));
  __CPROVER_assume((pub_r001386_15_2 >= (-100)) && (pub_r001386_15_2 <= 100));
  __CPROVER_assume((pub_r001386_16_1 >= (-100)) && (pub_r001386_16_1 <= 100));
  __CPROVER_assume((pub_r001386_16_2 >= (-100)) && (pub_r001386_16_2 <= 100));
  __CPROVER_assume((pub_r001386_17_1 >= (-100)) && (pub_r001386_17_1 <= 100));
  __CPROVER_assume((pub_r001386_17_2 >= (-100)) && (pub_r001386_17_2 <= 100));
  __CPROVER_assume((pub_r001386_18_1 >= (-100)) && (pub_r001386_18_1 <= 100));
  __CPROVER_assume((pub_r001386_18_2 >= (-100)) && (pub_r001386_18_2 <= 100));
  __CPROVER_assume((pub_r001386_19_1 >= (-100)) && (pub_r001386_19_1 <= 100));
  __CPROVER_assume((pub_r001386_19_2 >= (-100)) && (pub_r001386_19_2 <= 100));
  __CPROVER_assume((pub_r001386_20_1 >= (-100)) && (pub_r001386_20_1 <= 100));
  __CPROVER_assume((pub_r001386_20_2 >= (-100)) && (pub_r001386_20_2 <= 100));
  __CPROVER_assume((sec_r001386_0_1 >= 0) && (sec_r001386_0_1 <= 255));
  __CPROVER_assume((sec_r001386_0_2 >= 0) && (sec_r001386_0_2 <= 255));
  __CPROVER_assume((sec_r001386_1_1 >= 0) && (sec_r001386_1_1 <= 255));
  __CPROVER_assume((sec_r001386_1_2 >= 0) && (sec_r001386_1_2 <= 255));
  __CPROVER_assume((sec_r001386_2_1 >= 0) && (sec_r001386_2_1 <= 255));
  __CPROVER_assume((sec_r001386_2_2 >= 0) && (sec_r001386_2_2 <= 255));
  __CPROVER_assume((sec_r001386_3_1 >= 0) && (sec_r001386_3_1 <= 255));
  __CPROVER_assume((sec_r001386_3_2 >= 0) && (sec_r001386_3_2 <= 255));
  __CPROVER_assume((sec_r001386_4_1 >= 0) && (sec_r001386_4_1 <= 255));
  __CPROVER_assume((sec_r001386_4_2 >= 0) && (sec_r001386_4_2 <= 255));
  __CPROVER_assume((sec_r001386_5_1 >= 0) && (sec_r001386_5_1 <= 255));
  __CPROVER_assume((sec_r001386_5_2 >= 0) && (sec_r001386_5_2 <= 255));
  __CPROVER_assume((sec_r001386_6_1 >= 0) && (sec_r001386_6_1 <= 255));
  __CPROVER_assume((sec_r001386_6_2 >= 0) && (sec_r001386_6_2 <= 255));
  __CPROVER_assume((sec_r001386_7_1 >= 0) && (sec_r001386_7_1 <= 255));
  __CPROVER_assume((sec_r001386_7_2 >= 0) && (sec_r001386_7_2 <= 255));
  __CPROVER_assume((sec_r001386_8_1 >= 0) && (sec_r001386_8_1 <= 255));
  __CPROVER_assume((sec_r001386_8_2 >= 0) && (sec_r001386_8_2 <= 255));
  __CPROVER_assume((sec_r001386_9_1 >= 0) && (sec_r001386_9_1 <= 255));
  __CPROVER_assume((sec_r001386_9_2 >= 0) && (sec_r001386_9_2 <= 255));
  __CPROVER_assume((sec_r001386_10_1 >= 0) && (sec_r001386_10_1 <= 255));
  __CPROVER_assume((sec_r001386_10_2 >= 0) && (sec_r001386_10_2 <= 255));
  __CPROVER_assume((sec_r001386_11_1 >= 0) && (sec_r001386_11_1 <= 255));
  __CPROVER_assume((sec_r001386_11_2 >= 0) && (sec_r001386_11_2 <= 255));
  __CPROVER_assume((sec_r001386_12_1 >= 0) && (sec_r001386_12_1 <= 255));
  __CPROVER_assume((sec_r001386_12_2 >= 0) && (sec_r001386_12_2 <= 255));
  __CPROVER_assume((sec_r001386_13_1 >= 0) && (sec_r001386_13_1 <= 255));
  __CPROVER_assume((sec_r001386_13_2 >= 0) && (sec_r001386_13_2 <= 255));
  __CPROVER_assume((sec_r001386_14_1 >= 0) && (sec_r001386_14_1 <= 255));
  __CPROVER_assume((sec_r001386_14_2 >= 0) && (sec_r001386_14_2 <= 255));
  __CPROVER_assume((sec_r001386_15_1 >= 0) && (sec_r001386_15_1 <= 255));
  __CPROVER_assume((sec_r001386_15_2 >= 0) && (sec_r001386_15_2 <= 255));
  __CPROVER_assume((sec_r001386_16_1 >= 0) && (sec_r001386_16_1 <= 255));
  __CPROVER_assume((sec_r001386_16_2 >= 0) && (sec_r001386_16_2 <= 255));
  __CPROVER_assume((sec_r001386_17_1 >= 0) && (sec_r001386_17_1 <= 255));
  __CPROVER_assume((sec_r001386_17_2 >= 0) && (sec_r001386_17_2 <= 255));
  __CPROVER_assume((sec_r001386_18_1 >= 0) && (sec_r001386_18_1 <= 255));
  __CPROVER_assume((sec_r001386_18_2 >= 0) && (sec_r001386_18_2 <= 255));
  __CPROVER_assume((sec_r001386_19_1 >= 0) && (sec_r001386_19_1 <= 255));
  __CPROVER_assume((sec_r001386_19_2 >= 0) && (sec_r001386_19_2 <= 255));
  __CPROVER_assume((sec_r001386_20_1 >= 0) && (sec_r001386_20_1 <= 255));
  __CPROVER_assume((sec_r001386_20_2 >= 0) && (sec_r001386_20_2 <= 255));
  struct Vector3D_R001386_8613_0 st_var_0_1 = {0};
  struct Vector3D_R001386_8613_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001386_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001386_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001386_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001386_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001386_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001386_0_2 + 7) & 15;
  struct SensorNode_R001386_8613_1 st_var_1_1 = {0};
  struct SensorNode_R001386_8613_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001386_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001386_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001386_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001386_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001386_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001386_0_2 + 9) & 15;
  struct FilterState_R001386_8613_2 st_var_2_1 = {0};
  struct FilterState_R001386_8613_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001386_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001386_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001386_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001386_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001386_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001386_0_2 + 11) & 15;
  union TelemetryField_R001386_8613_0 u_var_1;
  union TelemetryField_R001386_8613_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001386_8613_0(sec_r001386_0_1, sec_r001386_1_1, pub_r001386_2_1, pub_r001386_3_1);
  int helper_flow_0_2 = fn_R001386_8613_0(sec_r001386_0_2, sec_r001386_1_2, pub_r001386_2_2, pub_r001386_3_2);
  fn_R001386_8613_0_2(sec_r001386_0_1, sec_r001386_1_1, pub_r001386_2_1, pub_r001386_3_1, sec_r001386_0_2, sec_r001386_1_2, pub_r001386_2_2, pub_r001386_3_2);
  int helper_flow_1_1 = fn_R001386_8613_1(sec_r001386_1_1, sec_r001386_2_1);
  int helper_flow_1_2 = fn_R001386_8613_1(sec_r001386_1_2, sec_r001386_2_2);
  fn_R001386_8613_1_2(sec_r001386_1_1, sec_r001386_2_1, sec_r001386_1_2, sec_r001386_2_2);
  int helper_flow_2_1 = fn_R001386_8613_2(sec_r001386_2_1, sec_r001386_3_1, pub_r001386_4_1);
  int helper_flow_2_2 = fn_R001386_8613_2(sec_r001386_2_2, sec_r001386_3_2, pub_r001386_4_2);
  fn_R001386_8613_2_2(sec_r001386_2_1, sec_r001386_3_1, pub_r001386_4_1, sec_r001386_2_2, sec_r001386_3_2, pub_r001386_4_2);
  int helper_flow_3_1 = fn_R001386_8613_3(sec_r001386_3_1, pub_r001386_4_1, pub_r001386_5_1, pub_r001386_6_1, pub_r001386_7_1);
  int helper_flow_3_2 = fn_R001386_8613_3(sec_r001386_3_2, pub_r001386_4_2, pub_r001386_5_2, pub_r001386_6_2, pub_r001386_7_2);
  fn_R001386_8613_3_2(sec_r001386_3_1, pub_r001386_4_1, pub_r001386_5_1, pub_r001386_6_1, pub_r001386_7_1, sec_r001386_3_2, pub_r001386_4_2, pub_r001386_5_2, pub_r001386_6_2, pub_r001386_7_2);
  int helper_flow_4_1 = fn_R001386_8613_4(sec_r001386_4_1, pub_r001386_5_1, pub_r001386_6_1);
  int helper_flow_4_2 = fn_R001386_8613_4(sec_r001386_4_2, pub_r001386_5_2, pub_r001386_6_2);
  fn_R001386_8613_4_2(sec_r001386_4_1, pub_r001386_5_1, pub_r001386_6_1, sec_r001386_4_2, pub_r001386_5_2, pub_r001386_6_2);
  int helper_flow_5_1 = fn_R001386_8613_5(sec_r001386_5_1, pub_r001386_6_1, pub_r001386_7_1);
  int helper_flow_5_2 = fn_R001386_8613_5(sec_r001386_5_2, pub_r001386_6_2, pub_r001386_7_2);
  fn_R001386_8613_5_2(sec_r001386_5_1, pub_r001386_6_1, pub_r001386_7_1, sec_r001386_5_2, pub_r001386_6_2, pub_r001386_7_2);
  int helper_flow_6_1 = fn_R001386_8613_6(sec_r001386_6_1, pub_r001386_7_1, pub_r001386_8_1, pub_r001386_9_1, pub_r001386_10_1);
  int helper_flow_6_2 = fn_R001386_8613_6(sec_r001386_6_2, pub_r001386_7_2, pub_r001386_8_2, pub_r001386_9_2, pub_r001386_10_2);
  fn_R001386_8613_6_2(sec_r001386_6_1, pub_r001386_7_1, pub_r001386_8_1, pub_r001386_9_1, pub_r001386_10_1, sec_r001386_6_2, pub_r001386_7_2, pub_r001386_8_2, pub_r001386_9_2, pub_r001386_10_2);
  int helper_flow_7_1 = fn_R001386_8613_7(sec_r001386_7_1, pub_r001386_8_1, pub_r001386_9_1, pub_r001386_10_1, pub_r001386_11_1);
  int helper_flow_7_2 = fn_R001386_8613_7(sec_r001386_7_2, pub_r001386_8_2, pub_r001386_9_2, pub_r001386_10_2, pub_r001386_11_2);
  fn_R001386_8613_7_2(sec_r001386_7_1, pub_r001386_8_1, pub_r001386_9_1, pub_r001386_10_1, pub_r001386_11_1, sec_r001386_7_2, pub_r001386_8_2, pub_r001386_9_2, pub_r001386_10_2, pub_r001386_11_2);
  int stage_v_0_1 = ((pub_r001386_4_1 * 2) + 35) & 63;
  int stage_v_0_2 = ((pub_r001386_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_0_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_0_2) & 127;
  int stage_v_1_1 = ((sec_r001386_8_1 + (pub_r001386_18_1 * 2)) + 8) & 127;
  int stage_v_1_2 = ((sec_r001386_8_2 + (pub_r001386_18_2 * 2)) + 8) & 127;
  if (stage_v_1_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_1_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_1_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_1_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_2_1 = ((pub_r001386_14_1 * 2) + 39) & 63;
  int stage_v_2_2 = ((pub_r001386_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = ((pub_r001386_7_1 * 2) + 18) & 63;
  int stage_v_3_2 = ((pub_r001386_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = ((pub_r001386_10_1 * 2) + 26) & 63;
  int stage_v_4_2 = ((pub_r001386_10_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = ((sec_r001386_10_1 + (pub_r001386_17_1 * 2)) + 20) & 127;
  int stage_v_5_2 = ((sec_r001386_10_2 + (pub_r001386_17_2 * 2)) + 20) & 127;
  if (stage_v_5_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_5_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_5_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_5_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_5_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_5_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_6_1 = ((sec_r001386_20_1 + (pub_r001386_12_1 * 2)) + 23) & 127;
  int stage_v_6_2 = ((sec_r001386_20_2 + (pub_r001386_12_2 * 2)) + 23) & 127;
  if (stage_v_6_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_6_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_6_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_6_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_6_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_6_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_7_1 = ((sec_r001386_6_1 + (pub_r001386_13_1 * 2)) + 26) & 127;
  int stage_v_7_2 = ((sec_r001386_6_2 + (pub_r001386_13_2 * 2)) + 26) & 127;
  if (stage_v_7_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_7_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_7_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_7_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_7_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_7_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_8_1 = ((helper_flow_7_1 + (pub_r001386_2_1 * 2)) + 29) & 127;
  int stage_v_8_2 = ((helper_flow_7_2 + (pub_r001386_2_2 * 2)) + 29) & 127;
  if (stage_v_8_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_8_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_8_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_8_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_8_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_8_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_8_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_8_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_9_1 = ((pub_r001386_17_1 * 2) + 7) & 63;
  int stage_v_9_2 = ((pub_r001386_17_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = ((helper_flow_1_1 + (pub_r001386_8_1 * 2)) + 35) & 127;
  int stage_v_10_2 = ((helper_flow_1_2 + (pub_r001386_8_2 * 2)) + 35) & 127;
  if (stage_v_10_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_10_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_10_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_10_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_10_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_10_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_11_1 = ((sec_r001386_18_1 + (pub_r001386_3_1 * 2)) + 38) & 127;
  int stage_v_11_2 = ((sec_r001386_18_2 + (pub_r001386_3_2 * 2)) + 38) & 127;
  if (stage_v_11_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_11_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_11_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_11_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_11_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_11_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_12_1 = ((pub_r001386_1_1 * 2) + 29) & 63;
  int stage_v_12_2 = ((pub_r001386_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = ((pub_r001386_10_1 * 2) + 6) & 63;
  int stage_v_13_2 = ((pub_r001386_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((sec_r001386_19_1 + (pub_r001386_16_1 * 2)) + 47) & 127;
  int stage_v_14_2 = ((sec_r001386_19_2 + (pub_r001386_16_2 * 2)) + 47) & 127;
  if (stage_v_14_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_14_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_14_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_14_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_14_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_14_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_14_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_14_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_15_1 = ((sec_r001386_20_1 + (pub_r001386_8_1 * 2)) + 50) & 127;
  int stage_v_15_2 = ((sec_r001386_20_2 + (pub_r001386_8_2 * 2)) + 50) & 127;
  if (stage_v_15_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_15_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_15_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_15_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_15_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_15_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_15_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_15_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_16_1 = ((pub_r001386_15_1 * 2) + 36) & 63;
  int stage_v_16_2 = ((pub_r001386_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = ((stage_v_6_1 + (pub_r001386_1_1 * 2)) + 56) & 127;
  int stage_v_17_2 = ((stage_v_6_2 + (pub_r001386_1_2 * 2)) + 56) & 127;
  if (stage_v_17_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_17_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_17_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_17_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_17_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_17_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_18_1 = ((sec_r001386_20_1 + (pub_r001386_8_1 * 2)) + 59) & 127;
  int stage_v_18_2 = ((sec_r001386_20_2 + (pub_r001386_8_2 * 2)) + 59) & 127;
  if (stage_v_18_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_18_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_18_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_18_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_18_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_18_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_18_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_18_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_19_1 = ((pub_r001386_2_1 * 2) + 30) & 63;
  int stage_v_19_2 = ((pub_r001386_2_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = ((stage_v_7_1 + (pub_r001386_6_1 * 2)) + 65) & 127;
  int stage_v_20_2 = ((stage_v_7_2 + (pub_r001386_6_2 * 2)) + 65) & 127;
  if (stage_v_20_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_20_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_20_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_20_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_20_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_20_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_21_1 = ((sec_r001386_15_1 + (pub_r001386_5_1 * 2)) + 68) & 127;
  int stage_v_21_2 = ((sec_r001386_15_2 + (pub_r001386_5_2 * 2)) + 68) & 127;
  if (stage_v_21_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_21_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_21_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_21_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_21_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_21_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_22_1 = ((sec_r001386_8_1 + (pub_r001386_13_1 * 2)) + 71) & 127;
  int stage_v_22_2 = ((sec_r001386_8_2 + (pub_r001386_13_2 * 2)) + 71) & 127;
  if (stage_v_22_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_22_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_22_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_22_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_22_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_22_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_23_1 = ((sec_r001386_8_1 + (pub_r001386_8_1 * 2)) + 74) & 127;
  int stage_v_23_2 = ((sec_r001386_8_2 + (pub_r001386_8_2 * 2)) + 74) & 127;
  if (stage_v_23_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_23_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_23_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_23_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_23_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_23_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_23_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_23_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_24_1 = ((sec_r001386_8_1 + (pub_r001386_12_1 * 2)) + 77) & 127;
  int stage_v_24_2 = ((sec_r001386_8_2 + (pub_r001386_12_2 * 2)) + 77) & 127;
  if (stage_v_24_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_24_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_24_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_24_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_25_1 = ((pub_r001386_16_1 * 2) + 38) & 63;
  int stage_v_25_2 = ((pub_r001386_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((stage_v_10_1 + (pub_r001386_7_1 * 2)) + 83) & 127;
  int stage_v_26_2 = ((stage_v_10_2 + (pub_r001386_7_2 * 2)) + 83) & 127;
  if (stage_v_26_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_26_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_26_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_26_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_26_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_26_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_27_1 = ((sec_r001386_8_1 + (pub_r001386_10_1 * 2)) + 86) & 127;
  int stage_v_27_2 = ((sec_r001386_8_2 + (pub_r001386_10_2 * 2)) + 86) & 127;
  if (stage_v_27_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_27_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_27_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_27_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_27_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_27_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_28_1 = ((pub_r001386_6_1 * 2) + 8) & 63;
  int stage_v_28_2 = ((pub_r001386_6_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001386_12_1 * 2) + 50) & 63;
  int stage_v_29_2 = ((pub_r001386_12_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = ((pub_r001386_8_1 * 2) + 11) & 63;
  int stage_v_30_2 = ((pub_r001386_8_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = ((pub_r001386_4_1 * 2) + 25) & 63;
  int stage_v_31_2 = ((pub_r001386_4_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = ((sec_r001386_18_1 + (pub_r001386_17_1 * 2)) + 101) & 127;
  int stage_v_32_2 = ((sec_r001386_18_2 + (pub_r001386_17_2 * 2)) + 101) & 127;
  if (stage_v_32_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_32_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_32_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_32_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_33_1 = ((pub_r001386_0_1 * 2) + 24) & 63;
  int stage_v_33_2 = ((pub_r001386_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = ((helper_flow_4_1 + (pub_r001386_7_1 * 2)) + 107) & 127;
  int stage_v_34_2 = ((helper_flow_4_2 + (pub_r001386_7_2 * 2)) + 107) & 127;
  if (stage_v_34_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_34_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_34_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_34_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_34_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_34_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_35_1 = ((sec_r001386_9_1 + (pub_r001386_11_1 * 2)) + 110) & 127;
  int stage_v_35_2 = ((sec_r001386_9_2 + (pub_r001386_11_2 * 2)) + 110) & 127;
  if (stage_v_35_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_35_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_35_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_35_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_35_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_35_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_35_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_35_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_36_1 = ((pub_r001386_9_1 * 2) + 11) & 63;
  int stage_v_36_2 = ((pub_r001386_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = ((helper_flow_3_1 + (pub_r001386_2_1 * 2)) + 116) & 127;
  int stage_v_37_2 = ((helper_flow_3_2 + (pub_r001386_2_2 * 2)) + 116) & 127;
  if (stage_v_37_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_37_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_37_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_37_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_37_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_37_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_38_1 = ((pub_r001386_15_1 * 2) + 16) & 63;
  int stage_v_38_2 = ((pub_r001386_15_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((sec_r001386_8_1 + (pub_r001386_1_1 * 2)) + 122) & 127;
  int stage_v_39_2 = ((sec_r001386_8_2 + (pub_r001386_1_2 * 2)) + 122) & 127;
  if (stage_v_39_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_39_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_39_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_39_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_39_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_39_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_40_1 = ((sec_r001386_11_1 + (pub_r001386_19_1 * 2)) + 125) & 127;
  int stage_v_40_2 = ((sec_r001386_11_2 + (pub_r001386_19_2 * 2)) + 125) & 127;
  if (stage_v_40_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_40_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_40_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_40_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_41_1 = ((sec_r001386_11_1 + (pub_r001386_12_1 * 2)) + 128) & 127;
  int stage_v_41_2 = ((sec_r001386_11_2 + (pub_r001386_12_2 * 2)) + 128) & 127;
  if (stage_v_41_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_41_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_41_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_41_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_41_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_41_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_42_1 = ((stage_v_11_1 + (pub_r001386_0_1 * 2)) + 131) & 127;
  int stage_v_42_2 = ((stage_v_11_2 + (pub_r001386_0_2 * 2)) + 131) & 127;
  if (stage_v_42_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_42_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_42_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_42_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_42_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_42_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_43_1 = ((sec_r001386_18_1 + (pub_r001386_14_1 * 2)) + 134) & 127;
  int stage_v_43_2 = ((sec_r001386_18_2 + (pub_r001386_14_2 * 2)) + 134) & 127;
  if (stage_v_43_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_43_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_43_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_43_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_43_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_43_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_43_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_43_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_44_1 = ((stage_v_14_1 + (pub_r001386_3_1 * 2)) + 137) & 127;
  int stage_v_44_2 = ((stage_v_14_2 + (pub_r001386_3_2 * 2)) + 137) & 127;
  if (stage_v_44_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_44_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_44_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_44_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_44_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_44_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_45_1 = ((pub_r001386_11_1 * 2) + 27) & 63;
  int stage_v_45_2 = ((pub_r001386_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = ((sec_r001386_11_1 + (pub_r001386_9_1 * 2)) + 143) & 127;
  int stage_v_46_2 = ((sec_r001386_11_2 + (pub_r001386_9_2 * 2)) + 143) & 127;
  if (stage_v_46_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_46_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_46_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_46_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_46_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_46_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_47_1 = ((stage_v_10_1 + (pub_r001386_4_1 * 2)) + 146) & 127;
  int stage_v_47_2 = ((stage_v_10_2 + (pub_r001386_4_2 * 2)) + 146) & 127;
  if (stage_v_47_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_47_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_47_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_47_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_47_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_47_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_48_1 = ((sec_r001386_7_1 + (pub_r001386_19_1 * 2)) + 149) & 127;
  int stage_v_48_2 = ((sec_r001386_7_2 + (pub_r001386_19_2 * 2)) + 149) & 127;
  if (stage_v_48_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_48_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_48_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_48_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_48_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_48_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_49_1 = ((sec_r001386_18_1 + (pub_r001386_20_1 * 2)) + 152) & 127;
  int stage_v_49_2 = ((sec_r001386_18_2 + (pub_r001386_20_2 * 2)) + 152) & 127;
  if (stage_v_49_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_49_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_49_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_49_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_49_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_49_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_50_1 = ((pub_r001386_19_1 * 2) + 6) & 63;
  int stage_v_50_2 = ((pub_r001386_19_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((stage_v_10_1 + (pub_r001386_4_1 * 2)) + 158) & 127;
  int stage_v_51_2 = ((stage_v_10_2 + (pub_r001386_4_2 * 2)) + 158) & 127;
  if (stage_v_51_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_51_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_51_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_51_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_51_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_51_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_52_1 = ((sec_r001386_12_1 + (pub_r001386_15_1 * 2)) + 161) & 127;
  int stage_v_52_2 = ((sec_r001386_12_2 + (pub_r001386_15_2 * 2)) + 161) & 127;
  if (stage_v_52_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_52_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_52_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_52_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_52_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_52_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_53_1 = ((sec_r001386_4_1 + (pub_r001386_8_1 * 2)) + 164) & 127;
  int stage_v_53_2 = ((sec_r001386_4_2 + (pub_r001386_8_2 * 2)) + 164) & 127;
  if (stage_v_53_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_53_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_53_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_53_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_53_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_53_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_53_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_53_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_54_1 = ((pub_r001386_17_1 * 2) + 11) & 63;
  int stage_v_54_2 = ((pub_r001386_17_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = ((stage_v_41_1 + (pub_r001386_0_1 * 2)) + 170) & 127;
  int stage_v_55_2 = ((stage_v_41_2 + (pub_r001386_0_2 * 2)) + 170) & 127;
  if (stage_v_55_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_55_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_55_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_55_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_55_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_55_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_56_1 = ((pub_r001386_5_1 * 2) + 31) & 63;
  int stage_v_56_2 = ((pub_r001386_5_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001386_4_1 * 2) + 34) & 63;
  int stage_v_57_2 = ((pub_r001386_4_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((sec_r001386_15_1 + (pub_r001386_5_1 * 2)) + 179) & 127;
  int stage_v_58_2 = ((sec_r001386_15_2 + (pub_r001386_5_2 * 2)) + 179) & 127;
  if (stage_v_58_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_58_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_58_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_58_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_58_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_58_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_59_1 = ((stage_v_5_1 + (pub_r001386_13_1 * 2)) + 182) & 127;
  int stage_v_59_2 = ((stage_v_5_2 + (pub_r001386_13_2 * 2)) + 182) & 127;
  if (stage_v_59_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_59_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_59_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_59_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_59_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_59_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_59_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_59_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_60_1 = ((sec_r001386_17_1 + (pub_r001386_16_1 * 2)) + 185) & 127;
  int stage_v_60_2 = ((sec_r001386_17_2 + (pub_r001386_16_2 * 2)) + 185) & 127;
  if (stage_v_60_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_60_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_60_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_60_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_60_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_60_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_61_1 = ((sec_r001386_4_1 + (pub_r001386_9_1 * 2)) + 188) & 127;
  int stage_v_61_2 = ((sec_r001386_4_2 + (pub_r001386_9_2 * 2)) + 188) & 127;
  if (stage_v_61_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_61_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_61_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_61_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_61_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_61_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_62_1 = ((helper_flow_7_1 + (pub_r001386_9_1 * 2)) + 191) & 127;
  int stage_v_62_2 = ((helper_flow_7_2 + (pub_r001386_9_2 * 2)) + 191) & 127;
  if (stage_v_62_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_62_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_62_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_62_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_62_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_62_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_63_1 = ((stage_v_18_1 + (pub_r001386_10_1 * 2)) + 194) & 127;
  int stage_v_63_2 = ((stage_v_18_2 + (pub_r001386_10_2 * 2)) + 194) & 127;
  if (stage_v_63_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_63_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_63_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_63_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_63_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_63_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_63_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_63_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_64_1 = ((pub_r001386_13_1 * 2) + 48) & 63;
  int stage_v_64_2 = ((pub_r001386_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001386_19_1 * 2) + 42) & 63;
  int stage_v_65_2 = ((pub_r001386_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001386_2_1 * 2) + 16) & 63;
  int stage_v_66_2 = ((pub_r001386_2_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((stage_v_63_1 + (pub_r001386_4_1 * 2)) + 206) & 127;
  int stage_v_67_2 = ((stage_v_63_2 + (pub_r001386_4_2 * 2)) + 206) & 127;
  if (stage_v_67_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_67_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_67_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_67_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_67_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_67_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_67_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_67_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_68_1 = ((stage_v_47_1 + (pub_r001386_11_1 * 2)) + 209) & 127;
  int stage_v_68_2 = ((stage_v_47_2 + (pub_r001386_11_2 * 2)) + 209) & 127;
  if (stage_v_68_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_68_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_68_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_68_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_68_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_68_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_68_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_68_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_69_1 = ((sec_r001386_16_1 + (pub_r001386_11_1 * 2)) + 212) & 127;
  int stage_v_69_2 = ((sec_r001386_16_2 + (pub_r001386_11_2 * 2)) + 212) & 127;
  if (stage_v_69_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_69_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_69_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_69_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_69_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_69_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_70_1 = ((stage_v_61_1 + (pub_r001386_11_1 * 2)) + 215) & 127;
  int stage_v_70_2 = ((stage_v_61_2 + (pub_r001386_11_2 * 2)) + 215) & 127;
  if (stage_v_70_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_70_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_70_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_70_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_70_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_70_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_70_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_70_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_71_1 = ((stage_v_6_1 + (pub_r001386_14_1 * 2)) + 218) & 127;
  int stage_v_71_2 = ((stage_v_6_2 + (pub_r001386_14_2 * 2)) + 218) & 127;
  if (stage_v_71_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_71_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_71_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_71_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_71_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_71_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_72_1 = ((helper_flow_6_1 + (pub_r001386_9_1 * 2)) + 221) & 127;
  int stage_v_72_2 = ((helper_flow_6_2 + (pub_r001386_9_2 * 2)) + 221) & 127;
  if (stage_v_72_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_72_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_72_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_72_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_72_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_72_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_73_1 = ((stage_v_60_1 + (pub_r001386_17_1 * 2)) + 224) & 127;
  int stage_v_73_2 = ((stage_v_60_2 + (pub_r001386_17_2 * 2)) + 224) & 127;
  if (stage_v_73_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_73_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_73_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_73_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_73_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_73_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_74_1 = ((pub_r001386_2_1 * 2) + 32) & 63;
  int stage_v_74_2 = ((pub_r001386_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((stage_v_47_1 + (pub_r001386_18_1 * 2)) + 230) & 127;
  int stage_v_75_2 = ((stage_v_47_2 + (pub_r001386_18_2 * 2)) + 230) & 127;
  if (stage_v_75_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_75_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_75_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_75_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_75_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_75_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_76_1 = ((sec_r001386_13_1 + (pub_r001386_11_1 * 2)) + 233) & 127;
  int stage_v_76_2 = ((sec_r001386_13_2 + (pub_r001386_11_2 * 2)) + 233) & 127;
  if (stage_v_76_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_76_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_76_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_76_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_76_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_76_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_77_1 = ((pub_r001386_19_1 * 2) + 26) & 63;
  int stage_v_77_2 = ((pub_r001386_19_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = ((stage_v_49_1 + (pub_r001386_11_1 * 2)) + 239) & 127;
  int stage_v_78_2 = ((stage_v_49_2 + (pub_r001386_11_2 * 2)) + 239) & 127;
  if (stage_v_78_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_78_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_78_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_78_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_78_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_78_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_79_1 = ((stage_v_69_1 + (pub_r001386_8_1 * 2)) + 242) & 127;
  int stage_v_79_2 = ((stage_v_69_2 + (pub_r001386_8_2 * 2)) + 242) & 127;
  if (stage_v_79_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_79_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_79_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_79_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_79_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_79_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_79_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_79_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_80_1 = ((stage_v_34_1 + (pub_r001386_3_1 * 2)) + 245) & 127;
  int stage_v_80_2 = ((stage_v_34_2 + (pub_r001386_3_2 * 2)) + 245) & 127;
  if (stage_v_80_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_80_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_80_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_80_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_80_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_80_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_80_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_80_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_81_1 = ((stage_v_73_1 + (pub_r001386_16_1 * 2)) + 248) & 127;
  int stage_v_81_2 = ((stage_v_73_2 + (pub_r001386_16_2 * 2)) + 248) & 127;
  if (stage_v_81_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_81_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_81_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_81_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_81_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_81_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_82_1 = ((stage_v_58_1 + (pub_r001386_2_1 * 2)) + 251) & 127;
  int stage_v_82_2 = ((stage_v_58_2 + (pub_r001386_2_2 * 2)) + 251) & 127;
  if (stage_v_82_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_82_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_82_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_82_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_82_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_82_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_82_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_82_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_83_1 = ((sec_r001386_5_1 + (pub_r001386_11_1 * 2)) + 254) & 127;
  int stage_v_83_2 = ((sec_r001386_5_2 + (pub_r001386_11_2 * 2)) + 254) & 127;
  if (stage_v_83_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_83_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_83_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_83_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_83_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_83_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_84_1 = ((pub_r001386_0_1 * 2) + 37) & 63;
  int stage_v_84_2 = ((pub_r001386_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((stage_v_8_1 + (pub_r001386_17_1 * 2)) + 260) & 127;
  int stage_v_85_2 = ((stage_v_8_2 + (pub_r001386_17_2 * 2)) + 260) & 127;
  if (stage_v_85_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_85_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_85_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_85_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_85_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_85_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_86_1 = ((stage_v_76_1 + (pub_r001386_7_1 * 2)) + 263) & 127;
  int stage_v_86_2 = ((stage_v_76_2 + (pub_r001386_7_2 * 2)) + 263) & 127;
  if (stage_v_86_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_86_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_86_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_86_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_86_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_86_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_87_1 = ((stage_v_8_1 + (pub_r001386_8_1 * 2)) + 266) & 127;
  int stage_v_87_2 = ((stage_v_8_2 + (pub_r001386_8_2 * 2)) + 266) & 127;
  if (stage_v_87_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_87_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_87_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_87_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_87_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_87_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_88_1 = ((stage_v_35_1 + (pub_r001386_10_1 * 2)) + 269) & 127;
  int stage_v_88_2 = ((stage_v_35_2 + (pub_r001386_10_2 * 2)) + 269) & 127;
  if (stage_v_88_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_88_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_88_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_88_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_89_1 = ((stage_v_87_1 + (pub_r001386_3_1 * 2)) + 272) & 127;
  int stage_v_89_2 = ((stage_v_87_2 + (pub_r001386_3_2 * 2)) + 272) & 127;
  if (stage_v_89_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_89_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_89_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_89_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_90_1 = ((pub_r001386_1_1 * 2) + 35) & 63;
  int stage_v_90_2 = ((pub_r001386_1_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = ((stage_v_35_1 + (pub_r001386_16_1 * 2)) + 278) & 127;
  int stage_v_91_2 = ((stage_v_35_2 + (pub_r001386_16_2 * 2)) + 278) & 127;
  if (stage_v_91_1 > 52)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_91_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_91_2 > 52)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_91_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_92_1 = ((pub_r001386_19_1 * 2) + 30) & 63;
  int stage_v_92_2 = ((pub_r001386_19_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((helper_flow_0_1 + (pub_r001386_13_1 * 2)) + 284) & 127;
  int stage_v_93_2 = ((helper_flow_0_2 + (pub_r001386_13_2 * 2)) + 284) & 127;
  if (stage_v_93_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_93_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_93_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_93_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_94_1 = ((pub_r001386_20_1 * 2) + 12) & 63;
  int stage_v_94_2 = ((pub_r001386_20_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((sec_r001386_3_1 + (pub_r001386_9_1 * 2)) + 290) & 127;
  int stage_v_95_2 = ((sec_r001386_3_2 + (pub_r001386_9_2 * 2)) + 290) & 127;
  if (stage_v_95_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_95_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_95_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_95_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_96_1 = ((sec_r001386_11_1 + (pub_r001386_13_1 * 2)) + 293) & 127;
  int stage_v_96_2 = ((sec_r001386_11_2 + (pub_r001386_13_2 * 2)) + 293) & 127;
  if (stage_v_96_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_96_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_96_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_96_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_97_1 = ((stage_v_8_1 + (pub_r001386_1_1 * 2)) + 296) & 127;
  int stage_v_97_2 = ((stage_v_8_2 + (pub_r001386_1_2 * 2)) + 296) & 127;
  if (stage_v_97_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_97_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_97_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_97_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_98_1 = ((pub_r001386_9_1 * 2) + 17) & 63;
  int stage_v_98_2 = ((pub_r001386_9_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_98_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_98_2) & 127;
  int stage_v_99_1 = ((stage_v_96_1 + (pub_r001386_19_1 * 2)) + 302) & 127;
  int stage_v_99_2 = ((stage_v_96_2 + (pub_r001386_19_2 * 2)) + 302) & 127;
  if (stage_v_99_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_99_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_99_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_99_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_100_1 = ((sec_r001386_10_1 + (pub_r001386_17_1 * 2)) + 305) & 127;
  int stage_v_100_2 = ((sec_r001386_10_2 + (pub_r001386_17_2 * 2)) + 305) & 127;
  if (stage_v_100_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_100_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_100_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_100_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_101_1 = ((pub_r001386_13_1 * 2) + 41) & 63;
  int stage_v_101_2 = ((pub_r001386_13_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001386_5_1 * 2) + 26) & 63;
  int stage_v_102_2 = ((pub_r001386_5_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((sec_r001386_3_1 + (pub_r001386_5_1 * 2)) + 314) & 127;
  int stage_v_103_2 = ((sec_r001386_3_2 + (pub_r001386_5_2 * 2)) + 314) & 127;
  if (stage_v_103_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_103_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_103_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_103_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_104_1 = ((stage_v_95_1 + (pub_r001386_15_1 * 2)) + 317) & 127;
  int stage_v_104_2 = ((stage_v_95_2 + (pub_r001386_15_2 * 2)) + 317) & 127;
  if (stage_v_104_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_104_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_104_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_104_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_105_1 = ((stage_v_86_1 + (pub_r001386_0_1 * 2)) + 320) & 127;
  int stage_v_105_2 = ((stage_v_86_2 + (pub_r001386_0_2 * 2)) + 320) & 127;
  if (stage_v_105_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_105_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_105_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_105_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_106_1 = ((stage_v_17_1 + (pub_r001386_20_1 * 2)) + 323) & 127;
  int stage_v_106_2 = ((stage_v_17_2 + (pub_r001386_20_2 * 2)) + 323) & 127;
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
  int stage_v_107_1 = ((pub_r001386_0_1 * 2) + 12) & 63;
  int stage_v_107_2 = ((pub_r001386_0_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((stage_v_79_1 + (pub_r001386_5_1 * 2)) + 329) & 127;
  int stage_v_108_2 = ((stage_v_79_2 + (pub_r001386_5_2 * 2)) + 329) & 127;
  if (stage_v_108_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_108_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_108_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_108_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_109_1 = ((stage_v_46_1 + (pub_r001386_2_1 * 2)) + 332) & 127;
  int stage_v_109_2 = ((stage_v_46_2 + (pub_r001386_2_2 * 2)) + 332) & 127;
  if (stage_v_109_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_109_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_109_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_109_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_110_1 = ((pub_r001386_10_1 * 2) + 36) & 63;
  int stage_v_110_2 = ((pub_r001386_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((stage_v_62_1 + (pub_r001386_1_1 * 2)) + 338) & 127;
  int stage_v_111_2 = ((stage_v_62_2 + (pub_r001386_1_2 * 2)) + 338) & 127;
  if (stage_v_111_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_111_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_111_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_111_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_112_1 = ((pub_r001386_9_1 * 2) + 46) & 63;
  int stage_v_112_2 = ((pub_r001386_9_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = ((sec_r001386_11_1 + (pub_r001386_0_1 * 2)) + 344) & 127;
  int stage_v_113_2 = ((sec_r001386_11_2 + (pub_r001386_0_2 * 2)) + 344) & 127;
  if (stage_v_113_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_113_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_113_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_113_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_114_1 = ((helper_flow_4_1 + (pub_r001386_9_1 * 2)) + 347) & 127;
  int stage_v_114_2 = ((helper_flow_4_2 + (pub_r001386_9_2 * 2)) + 347) & 127;
  if (stage_v_114_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_114_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_114_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_114_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_115_1 = ((helper_flow_1_1 + (pub_r001386_13_1 * 2)) + 350) & 127;
  int stage_v_115_2 = ((helper_flow_1_2 + (pub_r001386_13_2 * 2)) + 350) & 127;
  if (stage_v_115_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_115_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_115_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_115_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_116_1 = ((sec_r001386_17_1 + (pub_r001386_13_1 * 2)) + 353) & 127;
  int stage_v_116_2 = ((sec_r001386_17_2 + (pub_r001386_13_2 * 2)) + 353) & 127;
  if (stage_v_116_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_116_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_116_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_116_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_117_1 = ((stage_v_35_1 + (pub_r001386_18_1 * 2)) + 356) & 127;
  int stage_v_117_2 = ((stage_v_35_2 + (pub_r001386_18_2 * 2)) + 356) & 127;
  if (stage_v_117_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_117_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_117_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_117_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_118_1 = ((stage_v_69_1 + (pub_r001386_1_1 * 2)) + 359) & 127;
  int stage_v_118_2 = ((stage_v_69_2 + (pub_r001386_1_2 * 2)) + 359) & 127;
  if (stage_v_118_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_118_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_118_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_118_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_119_1 = ((pub_r001386_10_1 * 2) + 10) & 63;
  int stage_v_119_2 = ((pub_r001386_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = ((sec_r001386_5_1 + (pub_r001386_11_1 * 2)) + 365) & 127;
  int stage_v_120_2 = ((sec_r001386_5_2 + (pub_r001386_11_2 * 2)) + 365) & 127;
  if (stage_v_120_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_120_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_120_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_120_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_121_1 = ((stage_v_24_1 + (pub_r001386_1_1 * 2)) + 368) & 127;
  int stage_v_121_2 = ((stage_v_24_2 + (pub_r001386_1_2 * 2)) + 368) & 127;
  if (stage_v_121_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_121_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_121_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_121_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_122_1 = ((stage_v_97_1 + (pub_r001386_16_1 * 2)) + 371) & 127;
  int stage_v_122_2 = ((stage_v_97_2 + (pub_r001386_16_2 * 2)) + 371) & 127;
  if (stage_v_122_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_122_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_122_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_122_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_123_1 = ((stage_v_73_1 + (pub_r001386_3_1 * 2)) + 374) & 127;
  int stage_v_123_2 = ((stage_v_73_2 + (pub_r001386_3_2 * 2)) + 374) & 127;
  if (stage_v_123_1 > 56)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_123_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_123_2 > 56)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_123_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_124_1 = ((pub_r001386_5_1 * 2) + 34) & 63;
  int stage_v_124_2 = ((pub_r001386_5_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001386_13_1 * 2) + 12) & 63;
  int stage_v_125_2 = ((pub_r001386_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((stage_v_37_1 + (pub_r001386_20_1 * 2)) + 383) & 127;
  int stage_v_126_2 = ((stage_v_37_2 + (pub_r001386_20_2 * 2)) + 383) & 127;
  if (stage_v_126_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_126_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_126_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_126_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_127_1 = ((stage_v_6_1 + (pub_r001386_16_1 * 2)) + 386) & 127;
  int stage_v_127_2 = ((stage_v_6_2 + (pub_r001386_16_2 * 2)) + 386) & 127;
  if (stage_v_127_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_127_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_127_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_127_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_128_1 = ((pub_r001386_18_1 * 2) + 39) & 63;
  int stage_v_128_2 = ((pub_r001386_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = ((pub_r001386_17_1 * 2) + 37) & 63;
  int stage_v_129_2 = ((pub_r001386_17_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_129_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_129_2) & 127;
  int stage_v_130_1 = ((stage_v_26_1 + (pub_r001386_15_1 * 2)) + 395) & 127;
  int stage_v_130_2 = ((stage_v_26_2 + (pub_r001386_15_2 * 2)) + 395) & 127;
  if (stage_v_130_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_130_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_130_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_130_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_131_1 = ((pub_r001386_20_1 * 2) + 22) & 63;
  int stage_v_131_2 = ((pub_r001386_20_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((stage_v_105_1 + (pub_r001386_12_1 * 2)) + 401) & 127;
  int stage_v_132_2 = ((stage_v_105_2 + (pub_r001386_12_2 * 2)) + 401) & 127;
  if (stage_v_132_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_132_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_132_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_132_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_133_1 = ((stage_v_113_1 + (pub_r001386_2_1 * 2)) + 404) & 127;
  int stage_v_133_2 = ((stage_v_113_2 + (pub_r001386_2_2 * 2)) + 404) & 127;
  if (stage_v_133_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_133_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_133_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_133_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_134_1 = ((pub_r001386_13_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001386_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001386_3_1 * 2) + 38) & 63;
  int stage_v_135_2 = ((pub_r001386_3_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((sec_r001386_4_1 + (pub_r001386_16_1 * 2)) + 413) & 127;
  int stage_v_136_2 = ((sec_r001386_4_2 + (pub_r001386_16_2 * 2)) + 413) & 127;
  if (stage_v_136_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_136_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_136_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_136_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_137_1 = ((stage_v_126_1 + (pub_r001386_18_1 * 2)) + 416) & 127;
  int stage_v_137_2 = ((stage_v_126_2 + (pub_r001386_18_2 * 2)) + 416) & 127;
  if (stage_v_137_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_137_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_137_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_137_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_138_1 = ((pub_r001386_7_1 * 2) + 32) & 63;
  int stage_v_138_2 = ((pub_r001386_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001386_16_1 * 2) + 15) & 63;
  int stage_v_139_2 = ((pub_r001386_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = ((stage_v_113_1 + (pub_r001386_8_1 * 2)) + 425) & 127;
  int stage_v_140_2 = ((stage_v_113_2 + (pub_r001386_8_2 * 2)) + 425) & 127;
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
  int stage_v_141_1 = ((pub_r001386_17_1 * 2) + 24) & 63;
  int stage_v_141_2 = ((pub_r001386_17_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_141_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_141_2) & 127;
  int stage_v_142_1 = ((helper_flow_5_1 + (pub_r001386_1_1 * 2)) + 431) & 127;
  int stage_v_142_2 = ((helper_flow_5_2 + (pub_r001386_1_2 * 2)) + 431) & 127;
  if (stage_v_142_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_142_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_142_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_142_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_143_1 = ((stage_v_142_1 + (pub_r001386_19_1 * 2)) + 434) & 127;
  int stage_v_143_2 = ((stage_v_142_2 + (pub_r001386_19_2 * 2)) + 434) & 127;
  if (stage_v_143_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_143_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_143_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_143_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_144_1 = ((stage_v_46_1 + (pub_r001386_13_1 * 2)) + 437) & 127;
  int stage_v_144_2 = ((stage_v_46_2 + (pub_r001386_13_2 * 2)) + 437) & 127;
  if (stage_v_144_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_144_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_144_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_144_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_145_1 = ((stage_v_121_1 + (pub_r001386_10_1 * 2)) + 440) & 127;
  int stage_v_145_2 = ((stage_v_121_2 + (pub_r001386_10_2 * 2)) + 440) & 127;
  if (stage_v_145_1 > 15)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_145_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_145_2 > 15)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_145_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_146_1 = ((stage_v_130_1 + (pub_r001386_8_1 * 2)) + 443) & 127;
  int stage_v_146_2 = ((stage_v_130_2 + (pub_r001386_8_2 * 2)) + 443) & 127;
  if (stage_v_146_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_146_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_146_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_146_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_147_1 = ((sec_r001386_9_1 + (pub_r001386_20_1 * 2)) + 446) & 127;
  int stage_v_147_2 = ((sec_r001386_9_2 + (pub_r001386_20_2 * 2)) + 446) & 127;
  if (stage_v_147_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_147_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_147_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_147_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_148_1 = ((helper_flow_0_1 + (pub_r001386_19_1 * 2)) + 449) & 127;
  int stage_v_148_2 = ((helper_flow_0_2 + (pub_r001386_19_2 * 2)) + 449) & 127;
  if (stage_v_148_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_148_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_148_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_148_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_149_1 = ((stage_v_7_1 + (pub_r001386_10_1 * 2)) + 452) & 127;
  int stage_v_149_2 = ((stage_v_7_2 + (pub_r001386_10_2 * 2)) + 452) & 127;
  if (stage_v_149_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_149_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_149_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_149_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_150_1 = ((pub_r001386_2_1 * 2) + 33) & 63;
  int stage_v_150_2 = ((pub_r001386_2_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001386_11_1 * 2) + 49) & 63;
  int stage_v_151_2 = ((pub_r001386_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = ((pub_r001386_6_1 * 2) + 28) & 63;
  int stage_v_152_2 = ((pub_r001386_6_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_152_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_152_2) & 127;
  int stage_v_153_1 = ((stage_v_99_1 + (pub_r001386_2_1 * 2)) + 464) & 127;
  int stage_v_153_2 = ((stage_v_99_2 + (pub_r001386_2_2 * 2)) + 464) & 127;
  if (stage_v_153_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_153_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_153_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_153_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_154_1 = ((stage_v_140_1 + (pub_r001386_14_1 * 2)) + 467) & 127;
  int stage_v_154_2 = ((stage_v_140_2 + (pub_r001386_14_2 * 2)) + 467) & 127;
  if (stage_v_154_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_154_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_154_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_154_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_155_1 = ((pub_r001386_9_1 * 2) + 25) & 63;
  int stage_v_155_2 = ((pub_r001386_9_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((stage_v_117_1 + (pub_r001386_7_1 * 2)) + 473) & 127;
  int stage_v_156_2 = ((stage_v_117_2 + (pub_r001386_7_2 * 2)) + 473) & 127;
  if (stage_v_156_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_156_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_156_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_156_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_157_1 = ((sec_r001386_7_1 + (pub_r001386_0_1 * 2)) + 476) & 127;
  int stage_v_157_2 = ((sec_r001386_7_2 + (pub_r001386_0_2 * 2)) + 476) & 127;
  if (stage_v_157_1 > 57)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_157_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_157_2 > 57)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_157_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_158_1 = ((stage_v_73_1 + (pub_r001386_16_1 * 2)) + 479) & 127;
  int stage_v_158_2 = ((stage_v_73_2 + (pub_r001386_16_2 * 2)) + 479) & 127;
  if (stage_v_158_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_158_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_158_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_158_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_159_1 = ((pub_r001386_7_1 * 2) + 16) & 63;
  int stage_v_159_2 = ((pub_r001386_7_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001386_9_1 * 2) + 14) & 63;
  int stage_v_160_2 = ((pub_r001386_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001386_15_1 * 2) + 50) & 63;
  int stage_v_161_2 = ((pub_r001386_15_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((stage_v_32_1 + (pub_r001386_3_1 * 2)) + 491) & 127;
  int stage_v_162_2 = ((stage_v_32_2 + (pub_r001386_3_2 * 2)) + 491) & 127;
  if (stage_v_162_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_162_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_162_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_162_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_163_1 = ((pub_r001386_19_1 * 2) + 45) & 63;
  int stage_v_163_2 = ((pub_r001386_19_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((stage_v_99_1 + (pub_r001386_9_1 * 2)) + 497) & 127;
  int stage_v_164_2 = ((stage_v_99_2 + (pub_r001386_9_2 * 2)) + 497) & 127;
  if (stage_v_164_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_164_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_164_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_164_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_165_1 = ((stage_v_103_1 + (pub_r001386_17_1 * 2)) + 500) & 127;
  int stage_v_165_2 = ((stage_v_103_2 + (pub_r001386_17_2 * 2)) + 500) & 127;
  if (stage_v_165_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_165_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_165_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_165_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_166_1 = ((stage_v_55_1 + (pub_r001386_12_1 * 2)) + 503) & 127;
  int stage_v_166_2 = ((stage_v_55_2 + (pub_r001386_12_2 * 2)) + 503) & 127;
  if (stage_v_166_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_166_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_166_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_166_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_167_1 = ((pub_r001386_20_1 * 2) + 23) & 63;
  int stage_v_167_2 = ((pub_r001386_20_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = ((stage_v_143_1 + (pub_r001386_4_1 * 2)) + 509) & 127;
  int stage_v_168_2 = ((stage_v_143_2 + (pub_r001386_4_2 * 2)) + 509) & 127;
  if (stage_v_168_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_168_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_168_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_168_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_169_1 = ((stage_v_132_1 + (pub_r001386_15_1 * 2)) + 512) & 127;
  int stage_v_169_2 = ((stage_v_132_2 + (pub_r001386_15_2 * 2)) + 512) & 127;
  if (stage_v_169_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_169_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_169_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_169_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_170_1 = ((stage_v_96_1 + (pub_r001386_2_1 * 2)) + 515) & 127;
  int stage_v_170_2 = ((stage_v_96_2 + (pub_r001386_2_2 * 2)) + 515) & 127;
  if (stage_v_170_1 > 59)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_170_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_170_2 > 59)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_170_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_171_1 = ((pub_r001386_16_1 * 2) + 36) & 63;
  int stage_v_171_2 = ((pub_r001386_16_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = ((stage_v_81_1 + (pub_r001386_6_1 * 2)) + 521) & 127;
  int stage_v_172_2 = ((stage_v_81_2 + (pub_r001386_6_2 * 2)) + 521) & 127;
  if (stage_v_172_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_172_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_172_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_172_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_173_1 = ((pub_r001386_14_1 * 2) + 34) & 63;
  int stage_v_173_2 = ((pub_r001386_14_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((stage_v_85_1 + (pub_r001386_18_1 * 2)) + 527) & 127;
  int stage_v_174_2 = ((stage_v_85_2 + (pub_r001386_18_2 * 2)) + 527) & 127;
  if (stage_v_174_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_174_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_174_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_174_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_175_1 = ((helper_flow_2_1 + (pub_r001386_2_1 * 2)) + 530) & 127;
  int stage_v_175_2 = ((helper_flow_2_2 + (pub_r001386_2_2 * 2)) + 530) & 127;
  if (stage_v_175_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_175_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_175_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_175_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_176_1 = ((stage_v_5_1 + (pub_r001386_5_1 * 2)) + 533) & 127;
  int stage_v_176_2 = ((stage_v_5_2 + (pub_r001386_5_2 * 2)) + 533) & 127;
  if (stage_v_176_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_176_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_176_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_176_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_177_1 = ((stage_v_24_1 + (pub_r001386_15_1 * 2)) + 536) & 127;
  int stage_v_177_2 = ((stage_v_24_2 + (pub_r001386_15_2 * 2)) + 536) & 127;
  if (stage_v_177_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_177_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_177_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_177_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_178_1 = ((stage_v_164_1 + (pub_r001386_8_1 * 2)) + 539) & 127;
  int stage_v_178_2 = ((stage_v_164_2 + (pub_r001386_8_2 * 2)) + 539) & 127;
  if (stage_v_178_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_178_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_178_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_178_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_179_1 = ((stage_v_156_1 + (pub_r001386_0_1 * 2)) + 542) & 127;
  int stage_v_179_2 = ((stage_v_156_2 + (pub_r001386_0_2 * 2)) + 542) & 127;
  if (stage_v_179_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_179_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_179_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_179_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_180_1 = ((pub_r001386_6_1 * 2) + 10) & 63;
  int stage_v_180_2 = ((pub_r001386_6_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_180_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_180_2) & 127;
  int stage_v_181_1 = ((pub_r001386_8_1 * 2) + 41) & 63;
  int stage_v_181_2 = ((pub_r001386_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((stage_v_179_1 + (pub_r001386_17_1 * 2)) + 551) & 127;
  int stage_v_182_2 = ((stage_v_179_2 + (pub_r001386_17_2 * 2)) + 551) & 127;
  if (stage_v_182_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_182_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_182_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_182_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_183_1 = ((helper_flow_3_1 + (pub_r001386_2_1 * 2)) + 554) & 127;
  int stage_v_183_2 = ((helper_flow_3_2 + (pub_r001386_2_2 * 2)) + 554) & 127;
  if (stage_v_183_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_183_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_183_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_183_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_184_1 = ((pub_r001386_13_1 * 2) + 11) & 63;
  int stage_v_184_2 = ((pub_r001386_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001386_11_1 * 2) + 34) & 63;
  int stage_v_185_2 = ((pub_r001386_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = ((sec_r001386_11_1 + (pub_r001386_20_1 * 2)) + 563) & 127;
  int stage_v_186_2 = ((sec_r001386_11_2 + (pub_r001386_20_2 * 2)) + 563) & 127;
  if (stage_v_186_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_186_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_186_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_186_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_187_1 = ((stage_v_83_1 + (pub_r001386_1_1 * 2)) + 566) & 127;
  int stage_v_187_2 = ((stage_v_83_2 + (pub_r001386_1_2 * 2)) + 566) & 127;
  if (stage_v_187_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_187_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_187_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_187_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_188_1 = ((stage_v_146_1 + (pub_r001386_11_1 * 2)) + 569) & 127;
  int stage_v_188_2 = ((stage_v_146_2 + (pub_r001386_11_2 * 2)) + 569) & 127;
  if (stage_v_188_1 > 55)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_188_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_188_2 > 55)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_188_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_189_1 = ((pub_r001386_15_1 * 2) + 12) & 63;
  int stage_v_189_2 = ((pub_r001386_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((sec_r001386_6_1 + (pub_r001386_16_1 * 2)) + 575) & 127;
  int stage_v_190_2 = ((sec_r001386_6_2 + (pub_r001386_16_2 * 2)) + 575) & 127;
  if (stage_v_190_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_190_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_190_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_190_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_191_1 = ((pub_r001386_17_1 * 2) + 15) & 63;
  int stage_v_191_2 = ((pub_r001386_17_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((stage_v_22_1 + (pub_r001386_1_1 * 2)) + 581) & 127;
  int stage_v_192_2 = ((stage_v_22_2 + (pub_r001386_1_2 * 2)) + 581) & 127;
  if (stage_v_192_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_192_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_192_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_192_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_193_1 = ((stage_v_24_1 + (pub_r001386_14_1 * 2)) + 584) & 127;
  int stage_v_193_2 = ((stage_v_24_2 + (pub_r001386_14_2 * 2)) + 584) & 127;
  if (stage_v_193_1 > 58)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_193_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_193_2 > 58)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_193_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_194_1 = ((pub_r001386_2_1 * 2) + 23) & 63;
  int stage_v_194_2 = ((pub_r001386_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((stage_v_127_1 + (pub_r001386_17_1 * 2)) + 590) & 127;
  int stage_v_195_2 = ((stage_v_127_2 + (pub_r001386_17_2 * 2)) + 590) & 127;
  if (stage_v_195_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_195_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_195_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_195_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_196_1 = ((stage_v_172_1 + (pub_r001386_7_1 * 2)) + 593) & 127;
  int stage_v_196_2 = ((stage_v_172_2 + (pub_r001386_7_2 * 2)) + 593) & 127;
  if (stage_v_196_1 > 51)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_196_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_196_2 > 51)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_196_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_197_1 = ((stage_v_114_1 + (pub_r001386_8_1 * 2)) + 596) & 127;
  int stage_v_197_2 = ((stage_v_114_2 + (pub_r001386_8_2 * 2)) + 596) & 127;
  if (stage_v_197_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_197_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_197_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_197_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_198_1 = ((pub_r001386_5_1 * 2) + 16) & 63;
  int stage_v_198_2 = ((pub_r001386_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = ((stage_v_196_1 + (pub_r001386_14_1 * 2)) + 602) & 127;
  int stage_v_199_2 = ((stage_v_196_2 + (pub_r001386_14_2 * 2)) + 602) & 127;
  if (stage_v_199_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_199_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_199_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_199_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_200_1 = ((stage_v_21_1 + (pub_r001386_14_1 * 2)) + 605) & 127;
  int stage_v_200_2 = ((stage_v_21_2 + (pub_r001386_14_2 * 2)) + 605) & 127;
  if (stage_v_200_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_200_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_200_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_200_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_201_1 = ((sec_r001386_19_1 + (pub_r001386_2_1 * 2)) + 608) & 127;
  int stage_v_201_2 = ((sec_r001386_19_2 + (pub_r001386_2_2 * 2)) + 608) & 127;
  if (stage_v_201_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_201_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_201_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_201_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_202_1 = ((pub_r001386_0_1 * 2) + 47) & 63;
  int stage_v_202_2 = ((pub_r001386_0_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001386_0_1 * 2) + 9) & 63;
  int stage_v_203_2 = ((pub_r001386_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = ((pub_r001386_12_1 * 2) + 26) & 63;
  int stage_v_204_2 = ((pub_r001386_12_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_204_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_204_2) & 127;
  int stage_v_205_1 = ((stage_v_81_1 + (pub_r001386_8_1 * 2)) + 620) & 127;
  int stage_v_205_2 = ((stage_v_81_2 + (pub_r001386_8_2 * 2)) + 620) & 127;
  if (stage_v_205_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_205_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_205_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_205_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_206_1 = ((stage_v_177_1 + (pub_r001386_15_1 * 2)) + 623) & 127;
  int stage_v_206_2 = ((stage_v_177_2 + (pub_r001386_15_2 * 2)) + 623) & 127;
  if (stage_v_206_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_206_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_206_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_206_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_207_1 = ((stage_v_87_1 + (pub_r001386_17_1 * 2)) + 626) & 127;
  int stage_v_207_2 = ((stage_v_87_2 + (pub_r001386_17_2 * 2)) + 626) & 127;
  if (stage_v_207_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_207_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_207_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_207_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_208_1 = ((helper_flow_1_1 + (pub_r001386_14_1 * 2)) + 629) & 127;
  int stage_v_208_2 = ((helper_flow_1_2 + (pub_r001386_14_2 * 2)) + 629) & 127;
  if (stage_v_208_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_208_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_208_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_208_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_209_1 = ((sec_r001386_16_1 + (pub_r001386_0_1 * 2)) + 632) & 127;
  int stage_v_209_2 = ((sec_r001386_16_2 + (pub_r001386_0_2 * 2)) + 632) & 127;
  if (stage_v_209_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_209_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_209_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_209_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_210_1 = ((stage_v_81_1 + (pub_r001386_14_1 * 2)) + 635) & 127;
  int stage_v_210_2 = ((stage_v_81_2 + (pub_r001386_14_2 * 2)) + 635) & 127;
  if (stage_v_210_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_210_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_210_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_210_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_211_1 = ((stage_v_207_1 + (pub_r001386_17_1 * 2)) + 638) & 127;
  int stage_v_211_2 = ((stage_v_207_2 + (pub_r001386_17_2 * 2)) + 638) & 127;
  if (stage_v_211_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_211_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_211_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_211_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_212_1 = ((stage_v_71_1 + (pub_r001386_19_1 * 2)) + 641) & 127;
  int stage_v_212_2 = ((stage_v_71_2 + (pub_r001386_19_2 * 2)) + 641) & 127;
  if (stage_v_212_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_212_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_212_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_212_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_213_1 = ((helper_flow_3_1 + (pub_r001386_0_1 * 2)) + 644) & 127;
  int stage_v_213_2 = ((helper_flow_3_2 + (pub_r001386_0_2 * 2)) + 644) & 127;
  if (stage_v_213_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_213_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_213_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_213_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_214_1 = ((pub_r001386_4_1 * 2) + 45) & 63;
  int stage_v_214_2 = ((pub_r001386_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = ((pub_r001386_17_1 * 2) + 32) & 63;
  int stage_v_215_2 = ((pub_r001386_17_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001386_7_1 * 2) + 36) & 63;
  int stage_v_216_2 = ((pub_r001386_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001386_12_1 * 2) + 22) & 63;
  int stage_v_217_2 = ((pub_r001386_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((stage_v_60_1 + (pub_r001386_8_1 * 2)) + 659) & 127;
  int stage_v_218_2 = ((stage_v_60_2 + (pub_r001386_8_2 * 2)) + 659) & 127;
  if (stage_v_218_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_218_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_218_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_218_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_219_1 = ((pub_r001386_18_1 * 2) + 39) & 63;
  int stage_v_219_2 = ((pub_r001386_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = ((pub_r001386_3_1 * 2) + 50) & 63;
  int stage_v_220_2 = ((pub_r001386_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_220_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_220_2) & 127;
  int stage_v_221_1 = ((pub_r001386_14_1 * 2) + 5) & 63;
  int stage_v_221_2 = ((pub_r001386_14_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = ((helper_flow_6_1 + (pub_r001386_10_1 * 2)) + 671) & 127;
  int stage_v_222_2 = ((helper_flow_6_2 + (pub_r001386_10_2 * 2)) + 671) & 127;
  if (stage_v_222_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_222_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_222_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_222_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_223_1 = ((pub_r001386_19_1 * 2) + 18) & 63;
  int stage_v_223_2 = ((pub_r001386_19_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((stage_v_48_1 + (pub_r001386_19_1 * 2)) + 677) & 127;
  int stage_v_224_2 = ((stage_v_48_2 + (pub_r001386_19_2 * 2)) + 677) & 127;
  if (stage_v_224_1 > 54)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_224_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_224_2 > 54)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_224_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_225_1 = ((stage_v_93_1 + (pub_r001386_2_1 * 2)) + 680) & 127;
  int stage_v_225_2 = ((stage_v_93_2 + (pub_r001386_2_2 * 2)) + 680) & 127;
  if (stage_v_225_1 > 60)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_225_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_225_2 > 60)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_225_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_226_1 = ((sec_r001386_12_1 + (pub_r001386_16_1 * 2)) + 683) & 127;
  int stage_v_226_2 = ((sec_r001386_12_2 + (pub_r001386_16_2 * 2)) + 683) & 127;
  if (stage_v_226_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_226_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_226_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_226_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_227_1 = ((stage_v_47_1 + (pub_r001386_12_1 * 2)) + 686) & 127;
  int stage_v_227_2 = ((stage_v_47_2 + (pub_r001386_12_2 * 2)) + 686) & 127;
  if (stage_v_227_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_227_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_227_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_227_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_228_1 = ((pub_r001386_5_1 * 2) + 32) & 63;
  int stage_v_228_2 = ((pub_r001386_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = ((pub_r001386_7_1 * 2) + 15) & 63;
  int stage_v_229_2 = ((pub_r001386_7_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001386_1_1 * 2) + 41) & 63;
  int stage_v_230_2 = ((pub_r001386_1_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = ((stage_v_178_1 + (pub_r001386_6_1 * 2)) + 698) & 127;
  int stage_v_231_2 = ((stage_v_178_2 + (pub_r001386_6_2 * 2)) + 698) & 127;
  if (stage_v_231_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_231_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_231_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_231_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_231_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_231_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_231_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_231_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_232_1 = ((pub_r001386_6_1 * 2) + 39) & 63;
  int stage_v_232_2 = ((pub_r001386_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_232_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_232_2) & 127;
  int stage_v_233_1 = ((pub_r001386_14_1 * 2) + 41) & 63;
  int stage_v_233_2 = ((pub_r001386_14_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = ((stage_v_133_1 + (pub_r001386_8_1 * 2)) + 707) & 127;
  int stage_v_234_2 = ((stage_v_133_2 + (pub_r001386_8_2 * 2)) + 707) & 127;
  if (stage_v_234_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_234_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_234_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_234_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_234_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_234_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_234_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_234_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_235_1 = ((pub_r001386_10_1 * 2) + 29) & 63;
  int stage_v_235_2 = ((pub_r001386_10_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((stage_v_20_1 + (pub_r001386_15_1 * 2)) + 713) & 127;
  int stage_v_236_2 = ((stage_v_20_2 + (pub_r001386_15_2 * 2)) + 713) & 127;
  if (stage_v_236_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_236_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_236_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_236_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_236_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_236_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_236_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_236_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_237_1 = ((pub_r001386_8_1 * 2) + 23) & 63;
  int stage_v_237_2 = ((pub_r001386_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001386_10_1 * 2) + 34) & 63;
  int stage_v_238_2 = ((pub_r001386_10_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001386_3_1 * 2) + 35) & 63;
  int stage_v_239_2 = ((pub_r001386_3_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((helper_flow_3_1 + (pub_r001386_17_1 * 2)) + 725) & 127;
  int stage_v_240_2 = ((helper_flow_3_2 + (pub_r001386_17_2 * 2)) + 725) & 127;
  if (stage_v_240_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_240_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_240_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_240_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_240_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_240_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_240_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_240_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_241_1 = ((sec_r001386_2_1 + (pub_r001386_13_1 * 2)) + 728) & 127;
  int stage_v_241_2 = ((sec_r001386_2_2 + (pub_r001386_13_2 * 2)) + 728) & 127;
  if (stage_v_241_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_241_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_241_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_241_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_241_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_241_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_241_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_241_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_242_1 = ((stage_v_86_1 + (pub_r001386_3_1 * 2)) + 731) & 127;
  int stage_v_242_2 = ((stage_v_86_2 + (pub_r001386_3_2 * 2)) + 731) & 127;
  if (stage_v_242_1 > 17)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_242_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_242_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_242_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_242_2 > 17)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_242_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_242_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_242_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  int stage_v_243_1 = ((stage_v_169_1 + (pub_r001386_1_1 * 2)) + 734) & 127;
  int stage_v_243_2 = ((stage_v_169_2 + (pub_r001386_1_2 * 2)) + 734) & 127;
  if (stage_v_243_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_243_1 * 2)) + 7) & 255;
    sec_accum_1 ^= stage_v_243_1 & 31;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_243_1) + 13) & 255;
    sec_accum_1 += 5;
  }
  if (stage_v_243_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_243_2 * 2)) + 7) & 255;
    sec_accum_2 ^= stage_v_243_2 & 31;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_243_2) + 13) & 255;
    sec_accum_2 += 5;
  }
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001386_0_1 != sec_r001386_0_2);
  __CPROVER_assume(pub_r001386_6_1 == pub_r001386_6_2);
  __CPROVER_assume(pub_r001386_20_1 == pub_r001386_20_2);
  __CPROVER_assume(sec_r001386_8_1 != sec_r001386_8_2);
  __CPROVER_assume(pub_r001386_8_1 == pub_r001386_8_2);
  __CPROVER_assume(pub_r001386_9_1 == pub_r001386_9_2);
  __CPROVER_assume(pub_r001386_17_1 == pub_r001386_17_2);
  __CPROVER_assume(pub_r001386_10_1 == pub_r001386_10_2);
  __CPROVER_assume(pub_r001386_3_1 == pub_r001386_3_2);
  __CPROVER_assume(pub_r001386_2_1 == pub_r001386_2_2);
  __CPROVER_assume(sec_r001386_20_1 != sec_r001386_20_2);
  __CPROVER_assume(sec_r001386_13_1 != sec_r001386_13_2);
  __CPROVER_assume(sec_r001386_5_1 != sec_r001386_5_2);
  __CPROVER_assume(sec_r001386_19_1 != sec_r001386_19_2);
  __CPROVER_assume(sec_r001386_14_1 != sec_r001386_14_2);
  __CPROVER_assume(pub_r001386_18_1 == pub_r001386_18_2);
  __CPROVER_assume(sec_r001386_9_1 != sec_r001386_9_2);
  __CPROVER_assume(sec_r001386_4_1 != sec_r001386_4_2);
  __CPROVER_assume(pub_r001386_7_1 == pub_r001386_7_2);
  __CPROVER_assume(sec_r001386_10_1 != sec_r001386_10_2);
  __CPROVER_assume(pub_r001386_16_1 == pub_r001386_16_2);
  __CPROVER_assume(pub_r001386_0_1 == pub_r001386_0_2);
  __CPROVER_assume(pub_r001386_14_1 == pub_r001386_14_2);
  __CPROVER_assume(sec_r001386_11_1 != sec_r001386_11_2);
  __CPROVER_assume(pub_r001386_13_1 == pub_r001386_13_2);
  __CPROVER_assume(sec_r001386_3_1 != sec_r001386_3_2);
  __CPROVER_assume(pub_r001386_19_1 == pub_r001386_19_2);
  __CPROVER_assume(sec_r001386_2_1 != sec_r001386_2_2);
  __CPROVER_assume(pub_r001386_15_1 == pub_r001386_15_2);
  __CPROVER_assume(pub_r001386_1_1 == pub_r001386_1_2);
  __CPROVER_assume(sec_r001386_17_1 != sec_r001386_17_2);
  __CPROVER_assume(sec_r001386_16_1 != sec_r001386_16_2);
  __CPROVER_assume(sec_r001386_1_1 != sec_r001386_1_2);
  __CPROVER_assume(pub_r001386_5_1 == pub_r001386_5_2);
  __CPROVER_assume(pub_r001386_12_1 == pub_r001386_12_2);
  __CPROVER_assume(sec_r001386_7_1 != sec_r001386_7_2);
  __CPROVER_assume(sec_r001386_12_1 != sec_r001386_12_2);
  __CPROVER_assume(sec_r001386_15_1 != sec_r001386_15_2);
  __CPROVER_assume(sec_r001386_6_1 != sec_r001386_6_2);
  __CPROVER_assume(pub_r001386_11_1 == pub_r001386_11_2);
  __CPROVER_assume(pub_r001386_4_1 == pub_r001386_4_2);
  __CPROVER_assume(sec_r001386_18_1 != sec_r001386_18_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.offset == st_var_1_2.offset);
  assert(st_var_1_1.threshold == st_var_1_2.threshold);
  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.mode == st_var_2_2.mode);
  assert(st_var_2_1.prev_in == st_var_2_2.prev_in);
  assert(st_var_2_1.damping == st_var_2_2.damping);
  assert(st_var_2_1.gain_db == st_var_2_2.gain_db);
  assert(st_var_2_1.prev_out == st_var_2_2.prev_out);
  assert(st_var_2_1.cutoff == st_var_2_2.cutoff);
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
}


