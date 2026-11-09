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
struct MatrixBlock_R001623_2313_0
{
  int trace;
  unsigned char scale;
  int density;
  int buffer[3];
};
struct SensorNode_R001623_2313_1
{
  unsigned char gain;
  int calib;
  short status;
  short reading;
  int buffer[3];
};
struct Vector3D_R001623_2313_2
{
  int pitch;
  unsigned char heading;
  int norm_sq;
  unsigned char coord_y;
  int coord_z;
  short coord_x;
  int buffer[3];
};
struct Transaction_R001623_2313_3
{
  unsigned char rate;
  int fee;
  int status;
  int buffer[3];
};
union ColorPixel_R001623_2313_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001623_2313_1
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
void fn_R001623_2313_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st_1 = {0};
  struct SensorNode_R001623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int threshold_51_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_51_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_51_1 > 20)
  {
    acc_1 = ((acc_1 + (threshold_51_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_51_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_51_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_51_2 > 20)
  {
    acc_2 = ((acc_2 + (threshold_51_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_51_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_51_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_71_1 = 0;
  int window_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_71_1 = ((window_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_71_2 = ((window_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_71_1) & 127;
    acc_2 = (acc_2 + window_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_51_1 == threshold_51_2);
  assert(window_71_1 == window_71_2);
}

int fn_R001623_2313_0(int p0, int p1, int p2)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int threshold_51 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_51 > 20)
  {
    acc = ((acc + (threshold_51 * 2)) + 5) & 127;
    aux ^= threshold_51 & 15;
  }
  else
  {
    acc = ((acc - threshold_51) + 11) & 127;
    aux += 3;
  }
  int window_71 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_71 = ((window_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 5) & 127;
  int acc_2 = (p0_2 + 5) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_35_1 = local_arr_1[aux_1 % 3];
  int quantum_35_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_35_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_35_2 * 2)) & 127;
  int bound_14_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_14_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_14_1)
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

  switch (bound_14_2)
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

  int tally_67_1 = 0;
  int tally_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_67_1 = ((tally_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_67_2 = ((tally_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_67_1) & 127;
    acc_2 = (acc_2 + tally_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_35_1 == quantum_35_2);
  assert(bound_14_1 == bound_14_2);
  assert(tally_67_1 == tally_67_2);
}

int fn_R001623_2313_1(int p0, int p1, int p2)
{
  int acc = (p0 + 5) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int quantum_35 = local_arr[aux % 3];
  acc = (acc + (quantum_35 * 2)) & 127;
  int bound_14 = (aux + st.buffer[1]) & 3;
  switch (bound_14)
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

  int tally_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_67 = ((tally_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int bound_78_1 = 0;
  int bound_78_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    bound_78_1 = ((bound_78_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_78_2 = ((bound_78_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_78_1) & 127;
    acc_2 = (acc_2 + bound_78_2) & 127;
  }

  int offset_10_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_10_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_10_1 > 21)
  {
    acc_1 = ((acc_1 + (offset_10_1 * 2)) + 5) & 127;
    aux_1 ^= offset_10_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_10_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_10_2 > 21)
  {
    acc_2 = ((acc_2 + (offset_10_2 * 2)) + 5) & 127;
    aux_2 ^= offset_10_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_10_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_78_1 == bound_78_2);
  assert(offset_10_1 == offset_10_2);
}

int fn_R001623_2313_2(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int bound_78 = 0;
  for (int k = 0; k < 3; k++)
  {
    bound_78 = ((bound_78 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_78) & 127;
  }

  int offset_10 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_10 > 21)
  {
    acc = ((acc + (offset_10 * 2)) + 5) & 127;
    aux ^= offset_10 & 15;
  }
  else
  {
    acc = ((acc - offset_10) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001623_2313_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 12) & 127;
  int acc_2 = (p0_2 + 12) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st_1 = {0};
  struct Vector3D_R001623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_65_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_65_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_65_1)
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

  switch (mask_65_2)
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

  int damping_59_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_59_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_59_1 > 48)
  {
    acc_1 = ((acc_1 + (damping_59_1 * 2)) + 5) & 127;
    aux_1 ^= damping_59_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_59_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_59_2 > 48)
  {
    acc_2 = ((acc_2 + (damping_59_2 * 2)) + 5) & 127;
    aux_2 ^= damping_59_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_59_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_65_1 == mask_65_2);
  assert(damping_59_1 == damping_59_2);
}

int fn_R001623_2313_3(int p0, int p1, int p2)
{
  int acc = (p0 + 12) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_65 = (aux + st.buffer[1]) & 3;
  switch (mask_65)
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

  int damping_59 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_59 > 48)
  {
    acc = ((acc + (damping_59 * 2)) + 5) & 127;
    aux ^= damping_59 & 15;
  }
  else
  {
    acc = ((acc - damping_59) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001623_2313_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_55_1 = local_arr_1[aux_1 % 3];
  int delta_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_55_2 * 2)) & 127;
  int threshold_50_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_50_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_50_1) & 63;
  aux_2 = (aux_2 + threshold_50_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int damping_31_1 = 0;
  int damping_31_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    damping_31_1 = ((damping_31_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    damping_31_2 = ((damping_31_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + damping_31_1) & 127;
    acc_2 = (acc_2 + damping_31_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_55_1 == delta_55_2);
  assert(threshold_50_1 == threshold_50_2);
  assert(damping_31_1 == damping_31_2);
}

int fn_R001623_2313_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int delta_55 = local_arr[aux % 3];
  acc = (acc + (delta_55 * 2)) & 127;
  int threshold_50 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_50) & 63;
  acc ^= aux;
  int damping_31 = 0;
  for (int k = 0; k < 3; k++)
  {
    damping_31 = ((damping_31 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + damping_31) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_5_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 41) & 127;
  int acc_2 = (p0_2 + 41) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st_1 = {0};
  struct Vector3D_R001623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int stride_26_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_26_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_26_1 > 44)
  {
    acc_1 = ((acc_1 + (stride_26_1 * 2)) + 5) & 127;
    aux_1 ^= stride_26_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_26_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_26_2 > 44)
  {
    acc_2 = ((acc_2 + (stride_26_2 * 2)) + 5) & 127;
    aux_2 ^= stride_26_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_26_2) + 11) & 127;
    aux_2 += 3;
  }
  int quotient_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int quotient_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + quotient_19_1) & 63;
  aux_2 = (aux_2 + quotient_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_26_1 == stride_26_2);
  assert(quotient_19_1 == quotient_19_2);
}

int fn_R001623_2313_5(int p0, int p1)
{
  int acc = (p0 + 41) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int stride_26 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_26 > 44)
  {
    acc = ((acc + (stride_26 * 2)) + 5) & 127;
    aux ^= stride_26 & 15;
  }
  else
  {
    acc = ((acc - stride_26) + 11) & 127;
    aux += 3;
  }
  int quotient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + quotient_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_6_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 14;
  st_2.buffer[2] = 14;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int cursor_49_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_49_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_49_1 > 19)
  {
    acc_1 = ((acc_1 + (cursor_49_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_49_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_49_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_49_2 > 19)
  {
    acc_2 = ((acc_2 + (cursor_49_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_49_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_49_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_95_1 = local_arr_1[aux_1 % 3];
  int scale_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_95_2 * 2)) & 127;
  int sample_90_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_90_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_90_1)
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

  switch (sample_90_2)
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
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(cursor_49_1 == cursor_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_95_1 == scale_95_2);
  assert(sample_90_1 == sample_90_2);
}

int fn_R001623_2313_6(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 14;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int cursor_49 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_49 > 19)
  {
    acc = ((acc + (cursor_49 * 2)) + 5) & 127;
    aux ^= cursor_49 & 15;
  }
  else
  {
    acc = ((acc - cursor_49) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int scale_95 = local_arr[aux % 3];
  acc = (acc + (scale_95 * 2)) & 127;
  int sample_90 = (aux + st.buffer[1]) & 3;
  switch (sample_90)
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

void fn_R001623_2313_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 11) & 127;
  int acc_2 = (p0_2 + 11) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st_1 = {0};
  struct SensorNode_R001623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int tracker_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_43_1) & 63;
  aux_2 = (aux_2 + tracker_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_40_1 > 15)
  {
    acc_1 = ((acc_1 + (threshold_40_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_40_2 > 15)
  {
    acc_2 = ((acc_2 + (threshold_40_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_40_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_43_1 == tracker_43_2);
  assert(threshold_40_1 == threshold_40_2);
}

int fn_R001623_2313_7(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 11) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int tracker_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_43) & 63;
  acc ^= aux;
  int threshold_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_40 > 15)
  {
    acc = ((acc + (threshold_40 * 2)) + 5) & 127;
    aux ^= threshold_40 & 15;
  }
  else
  {
    acc = ((acc - threshold_40) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001623_2313_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int anchor_41_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_41_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_41_1 > 26)
  {
    acc_1 = ((acc_1 + (anchor_41_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_41_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_41_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_41_2 > 26)
  {
    acc_2 = ((acc_2 + (anchor_41_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_41_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_41_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_29_1 = 0;
  int residue_29_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    residue_29_1 = ((residue_29_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_29_2 = ((residue_29_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_29_1) & 127;
    acc_2 = (acc_2 + residue_29_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_41_1 == anchor_41_2);
  assert(residue_29_1 == residue_29_2);
}

int fn_R001623_2313_8(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int anchor_41 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_41 > 26)
  {
    acc = ((acc + (anchor_41 * 2)) + 5) & 127;
    aux ^= anchor_41 & 15;
  }
  else
  {
    acc = ((acc - anchor_41) + 11) & 127;
    aux += 3;
  }
  int residue_29 = 0;
  for (int k = 0; k < 3; k++)
  {
    residue_29 = ((residue_29 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_29) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int accumulator_68_1 = 0;
  int accumulator_68_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_68_1 = ((accumulator_68_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_68_2 = ((accumulator_68_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_68_1) & 127;
    acc_2 = (acc_2 + accumulator_68_2) & 127;
  }

  int parity_42_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_42_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_42_1 > 32)
  {
    acc_1 = ((acc_1 + (parity_42_1 * 2)) + 5) & 127;
    aux_1 ^= parity_42_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_42_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_42_2 > 32)
  {
    acc_2 = ((acc_2 + (parity_42_2 * 2)) + 5) & 127;
    aux_2 ^= parity_42_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_42_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tally_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_99_1) & 63;
  aux_2 = (aux_2 + tally_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(accumulator_68_1 == accumulator_68_2);
  assert(parity_42_1 == parity_42_2);
  assert(tally_99_1 == tally_99_2);
}

int fn_R001623_2313_9(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int accumulator_68 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_68 = ((accumulator_68 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_68) & 127;
  }

  int parity_42 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_42 > 32)
  {
    acc = ((acc + (parity_42 * 2)) + 5) & 127;
    aux ^= parity_42 & 15;
  }
  else
  {
    acc = ((acc - parity_42) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tally_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int residue_82_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_82_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_82_1 > 36)
  {
    acc_1 = ((acc_1 + (residue_82_1 * 2)) + 5) & 127;
    aux_1 ^= residue_82_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_82_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_82_2 > 36)
  {
    acc_2 = ((acc_2 + (residue_82_2 * 2)) + 5) & 127;
    aux_2 ^= residue_82_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_82_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_44_1 = local_arr_1[aux_1 % 3];
  int pivot_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_44_2 * 2)) & 127;
  int window_79_1 = 0;
  int window_79_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_79_1 = ((window_79_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_79_2 = ((window_79_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_79_1) & 127;
    acc_2 = (acc_2 + window_79_2) & 127;
  }

  int weight_85_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_85_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_85_1)
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

  switch (weight_85_2)
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
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_82_1 == residue_82_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(pivot_44_1 == pivot_44_2);
  assert(window_79_1 == window_79_2);
  assert(weight_85_1 == weight_85_2);
}

int fn_R001623_2313_10(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int residue_82 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_82 > 36)
  {
    acc = ((acc + (residue_82 * 2)) + 5) & 127;
    aux ^= residue_82 & 15;
  }
  else
  {
    acc = ((acc - residue_82) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int pivot_44 = local_arr[aux % 3];
  acc = (acc + (pivot_44 * 2)) & 127;
  int window_79 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_79 = ((window_79 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_79) & 127;
  }

  int weight_85 = (aux + st.buffer[1]) & 3;
  switch (weight_85)
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

void fn_R001623_2313_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int vector_77_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_77_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_77_1 > 37)
  {
    acc_1 = ((acc_1 + (vector_77_1 * 2)) + 5) & 127;
    aux_1 ^= vector_77_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_77_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_77_2 > 37)
  {
    acc_2 = ((acc_2 + (vector_77_2 * 2)) + 5) & 127;
    aux_2 ^= vector_77_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_77_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_38_1) & 63;
  aux_2 = (aux_2 + delta_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_77_1 == vector_77_2);
  assert(delta_38_1 == delta_38_2);
}

int fn_R001623_2313_11(int p0, int p1)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int vector_77 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_77 > 37)
  {
    acc = ((acc + (vector_77 * 2)) + 5) & 127;
    aux ^= vector_77 & 15;
  }
  else
  {
    acc = ((acc - vector_77) + 11) & 127;
    aux += 3;
  }
  int delta_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_38) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_44_1) & 63;
  aux_2 = (aux_2 + residue_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_72_1 = local_arr_1[aux_1 % 3];
  int cursor_72_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_72_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_72_2 * 2)) & 127;
  int accumulator_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int accumulator_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (accumulator_69_1 > 21)
  {
    acc_1 = ((acc_1 + (accumulator_69_1 * 2)) + 5) & 127;
    aux_1 ^= accumulator_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - accumulator_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (accumulator_69_2 > 21)
  {
    acc_2 = ((acc_2 + (accumulator_69_2 * 2)) + 5) & 127;
    aux_2 ^= accumulator_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - accumulator_69_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_44_1 == residue_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_72_1 == cursor_72_2);
  assert(accumulator_69_1 == accumulator_69_2);
}

int fn_R001623_2313_12(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_44) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_72 = local_arr[aux % 3];
  acc = (acc + (cursor_72 * 2)) & 127;
  int accumulator_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (accumulator_69 > 21)
  {
    acc = ((acc + (accumulator_69 * 2)) + 5) & 127;
    aux ^= accumulator_69 & 15;
  }
  else
  {
    acc = ((acc - accumulator_69) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001623_2313_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st_1 = {0};
  struct SensorNode_R001623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int tally_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_91_1) & 63;
  aux_2 = (aux_2 + tally_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_56_1)
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

  switch (tracker_56_2)
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

  int window_71_1 = 0;
  int window_71_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    window_71_1 = ((window_71_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_71_2 = ((window_71_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_71_1) & 127;
    acc_2 = (acc_2 + window_71_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_91_1 == tally_91_2);
  assert(tracker_56_1 == tracker_56_2);
  assert(window_71_1 == window_71_2);
}

int fn_R001623_2313_13(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int tally_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_56 = (aux + st.buffer[1]) & 3;
  switch (tracker_56)
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

  int window_71 = 0;
  for (int k = 0; k < 2; k++)
  {
    window_71 = ((window_71 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_71) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int window_81_1 = 0;
  int window_81_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_81_1 = ((window_81_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_81_2 = ((window_81_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_81_1) & 127;
    acc_2 = (acc_2 + window_81_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int tally_14_1 = local_arr_1[aux_1 % 3];
  int tally_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (tally_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (tally_14_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_81_1 == window_81_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(tally_14_1 == tally_14_2);
}

int fn_R001623_2313_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int window_81 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_81 = ((window_81 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_81) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int tally_14 = local_arr[aux % 3];
  acc = (acc + (tally_14 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001623_2313_15_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st_1 = {0};
  struct SensorNode_R001623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tracker_60_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_60_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_60_1) & 63;
  aux_2 = (aux_2 + tracker_60_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int weight_43_1 = 0;
  int weight_43_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    weight_43_1 = ((weight_43_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    weight_43_2 = ((weight_43_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + weight_43_1) & 127;
    acc_2 = (acc_2 + weight_43_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_60_1 == tracker_60_2);
  assert(weight_43_1 == weight_43_2);
}

int fn_R001623_2313_15(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tracker_60 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_60) & 63;
  acc ^= aux;
  int weight_43 = 0;
  for (int k = 0; k < 3; k++)
  {
    weight_43 = ((weight_43 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + weight_43) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int tally_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_33_1) & 63;
  aux_2 = (aux_2 + tally_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_88_1 = local_arr_1[aux_1 % 3];
  int bound_88_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_88_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_88_2 * 2)) & 127;
  int mask_12_1 = 0;
  int mask_12_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_12_1 = ((mask_12_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_12_2 = ((mask_12_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_12_1) & 127;
    acc_2 = (acc_2 + mask_12_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_33_1 == tally_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_88_1 == bound_88_2);
  assert(mask_12_1 == mask_12_2);
}

int fn_R001623_2313_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int tally_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_33) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int bound_88 = local_arr[aux % 3];
  acc = (acc + (bound_88 * 2)) & 127;
  int mask_12 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_12 = ((mask_12 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_12) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001623_2313_17_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st_1 = {0};
  struct SensorNode_R001623_2313_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int index_reg_33_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_33_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_33_1 > 31)
  {
    acc_1 = ((acc_1 + (index_reg_33_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_33_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_33_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_33_2 > 31)
  {
    acc_2 = ((acc_2 + (index_reg_33_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_33_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_33_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_23_1 = local_arr_1[aux_1 % 3];
  int vector_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_23_2 * 2)) & 127;
  int tally_82_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tally_82_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tally_82_1) & 63;
  aux_2 = (aux_2 + tally_82_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain == st_2.gain);
  assert(st_1.calib == st_2.calib);
  assert(st_1.status == st_2.status);
  assert(st_1.reading == st_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_33_1 == index_reg_33_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_23_1 == vector_23_2);
  assert(tally_82_1 == tally_82_2);
}

int fn_R001623_2313_17(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct SensorNode_R001623_2313_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int index_reg_33 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_33 > 31)
  {
    acc = ((acc + (index_reg_33 * 2)) + 5) & 127;
    aux ^= index_reg_33 & 15;
  }
  else
  {
    acc = ((acc - index_reg_33) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_23 = local_arr[aux % 3];
  acc = (acc + (vector_23 * 2)) & 127;
  int tally_82 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tally_82) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st_1 = {0};
  struct Transaction_R001623_2313_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int sample_56_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_56_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_56_1 > 11)
  {
    acc_1 = ((acc_1 + (sample_56_1 * 2)) + 5) & 127;
    aux_1 ^= sample_56_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_56_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_56_2 > 11)
  {
    acc_2 = ((acc_2 + (sample_56_2 * 2)) + 5) & 127;
    aux_2 ^= sample_56_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_56_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_14_1 = local_arr_1[aux_1 % 3];
  int residue_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_14_2 * 2)) & 127;
  int threshold_19_1 = 0;
  int threshold_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    threshold_19_1 = ((threshold_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    threshold_19_2 = ((threshold_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + threshold_19_1) & 127;
    acc_2 = (acc_2 + threshold_19_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.rate == st_2.rate);
  assert(st_1.fee == st_2.fee);
  assert(st_1.status == st_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_56_1 == sample_56_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_14_1 == residue_14_2);
  assert(threshold_19_1 == threshold_19_2);
}

int fn_R001623_2313_18(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Transaction_R001623_2313_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int sample_56 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_56 > 11)
  {
    acc = ((acc + (sample_56 * 2)) + 5) & 127;
    aux ^= sample_56 & 15;
  }
  else
  {
    acc = ((acc - sample_56) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int residue_14 = local_arr[aux % 3];
  acc = (acc + (residue_14 * 2)) & 127;
  int threshold_19 = 0;
  for (int k = 0; k < 2; k++)
  {
    threshold_19 = ((threshold_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + threshold_19) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001623_2313_19_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st_1 = {0};
  struct Vector3D_R001623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_52_1 = 0;
  int tracker_52_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    tracker_52_1 = ((tracker_52_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tracker_52_2 = ((tracker_52_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tracker_52_1) & 127;
    acc_2 = (acc_2 + tracker_52_2) & 127;
  }

  int index_reg_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int index_reg_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + index_reg_34_1) & 63;
  aux_2 = (aux_2 + index_reg_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_52_1 == tracker_52_2);
  assert(index_reg_34_1 == index_reg_34_2);
}

int fn_R001623_2313_19(int p0, int p1, int p2)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_52 = 0;
  for (int k = 0; k < 3; k++)
  {
    tracker_52 = ((tracker_52 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tracker_52) & 127;
  }

  int index_reg_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + index_reg_34) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int segment_94_1 = 0;
  int segment_94_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    segment_94_1 = ((segment_94_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_94_2 = ((segment_94_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_94_1) & 127;
    acc_2 = (acc_2 + segment_94_2) & 127;
  }

  int factor_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_57_1) & 63;
  aux_2 = (aux_2 + factor_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.trace == st_2.trace);
  assert(st_1.scale == st_2.scale);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_94_1 == segment_94_2);
  assert(factor_57_1 == factor_57_2);
}

int fn_R001623_2313_20(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R001623_2313_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int segment_94 = 0;
  for (int k = 0; k < 2; k++)
  {
    segment_94 = ((segment_94 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_94) & 127;
  }

  int factor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_57) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001623_2313_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st_1 = {0};
  struct Vector3D_R001623_2313_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int scale_49_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int scale_49_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + scale_49_1) & 63;
  aux_2 = (aux_2 + scale_49_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int parity_23_1 = 0;
  int parity_23_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    parity_23_1 = ((parity_23_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    parity_23_2 = ((parity_23_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + parity_23_1) & 127;
    acc_2 = (acc_2 + parity_23_2) & 127;
  }

  int mask_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_77_1)
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

  switch (mask_77_2)
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
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.heading == st_2.heading);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(scale_49_1 == scale_49_2);
  assert(parity_23_1 == parity_23_2);
  assert(mask_77_1 == mask_77_2);
}

int fn_R001623_2313_21(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001623_2313_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int scale_49 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + scale_49) & 63;
  acc ^= aux;
  int parity_23 = 0;
  for (int k = 0; k < 3; k++)
  {
    parity_23 = ((parity_23 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + parity_23) & 127;
  }

  int mask_77 = (aux + st.buffer[1]) & 3;
  switch (mask_77)
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

void main()
{
  int sec_r001623_0_1;
  int sec_r001623_0_2;
  int sec_r001623_1_1;
  int sec_r001623_1_2;
  int sec_r001623_2_1;
  int sec_r001623_2_2;
  int sec_r001623_3_1;
  int sec_r001623_3_2;
  int sec_r001623_4_1;
  int sec_r001623_4_2;
  int sec_r001623_5_1;
  int sec_r001623_5_2;
  int sec_r001623_6_1;
  int sec_r001623_6_2;
  int sec_r001623_7_1;
  int sec_r001623_7_2;
  int sec_r001623_8_1;
  int sec_r001623_8_2;
  int sec_r001623_9_1;
  int sec_r001623_9_2;
  int sec_r001623_10_1;
  int sec_r001623_10_2;
  int sec_r001623_11_1;
  int sec_r001623_11_2;
  int sec_r001623_12_1;
  int sec_r001623_12_2;
  int sec_r001623_13_1;
  int sec_r001623_13_2;
  int sec_r001623_14_1;
  int sec_r001623_14_2;
  int sec_r001623_15_1;
  int sec_r001623_15_2;
  int sec_r001623_16_1;
  int sec_r001623_16_2;
  int sec_r001623_17_1;
  int sec_r001623_17_2;
  int sec_r001623_18_1;
  int sec_r001623_18_2;
  int sec_r001623_19_1;
  int sec_r001623_19_2;
  int sec_r001623_20_1;
  int sec_r001623_20_2;
  int pub_r001623_0_1;
  int pub_r001623_0_2;
  int pub_r001623_1_1;
  int pub_r001623_1_2;
  int pub_r001623_2_1;
  int pub_r001623_2_2;
  int pub_r001623_3_1;
  int pub_r001623_3_2;
  int pub_r001623_4_1;
  int pub_r001623_4_2;
  int pub_r001623_5_1;
  int pub_r001623_5_2;
  int pub_r001623_6_1;
  int pub_r001623_6_2;
  int pub_r001623_7_1;
  int pub_r001623_7_2;
  int pub_r001623_8_1;
  int pub_r001623_8_2;
  int pub_r001623_9_1;
  int pub_r001623_9_2;
  int pub_r001623_10_1;
  int pub_r001623_10_2;
  int pub_r001623_11_1;
  int pub_r001623_11_2;
  int pub_r001623_12_1;
  int pub_r001623_12_2;
  int pub_r001623_13_1;
  int pub_r001623_13_2;
  int pub_r001623_14_1;
  int pub_r001623_14_2;
  int pub_r001623_15_1;
  int pub_r001623_15_2;
  int pub_r001623_16_1;
  int pub_r001623_16_2;
  int pub_r001623_17_1;
  int pub_r001623_17_2;
  int pub_r001623_18_1;
  int pub_r001623_18_2;
  int pub_r001623_19_1;
  int pub_r001623_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001623_0_1 >= (-100)) && (pub_r001623_0_1 <= 100));
  __CPROVER_assume((pub_r001623_0_2 >= (-100)) && (pub_r001623_0_2 <= 100));
  __CPROVER_assume((pub_r001623_1_1 >= (-100)) && (pub_r001623_1_1 <= 100));
  __CPROVER_assume((pub_r001623_1_2 >= (-100)) && (pub_r001623_1_2 <= 100));
  __CPROVER_assume((pub_r001623_2_1 >= (-100)) && (pub_r001623_2_1 <= 100));
  __CPROVER_assume((pub_r001623_2_2 >= (-100)) && (pub_r001623_2_2 <= 100));
  __CPROVER_assume((pub_r001623_3_1 >= (-100)) && (pub_r001623_3_1 <= 100));
  __CPROVER_assume((pub_r001623_3_2 >= (-100)) && (pub_r001623_3_2 <= 100));
  __CPROVER_assume((pub_r001623_4_1 >= (-100)) && (pub_r001623_4_1 <= 100));
  __CPROVER_assume((pub_r001623_4_2 >= (-100)) && (pub_r001623_4_2 <= 100));
  __CPROVER_assume((pub_r001623_5_1 >= (-100)) && (pub_r001623_5_1 <= 100));
  __CPROVER_assume((pub_r001623_5_2 >= (-100)) && (pub_r001623_5_2 <= 100));
  __CPROVER_assume((pub_r001623_6_1 >= (-100)) && (pub_r001623_6_1 <= 100));
  __CPROVER_assume((pub_r001623_6_2 >= (-100)) && (pub_r001623_6_2 <= 100));
  __CPROVER_assume((pub_r001623_7_1 >= (-100)) && (pub_r001623_7_1 <= 100));
  __CPROVER_assume((pub_r001623_7_2 >= (-100)) && (pub_r001623_7_2 <= 100));
  __CPROVER_assume((pub_r001623_8_1 >= (-100)) && (pub_r001623_8_1 <= 100));
  __CPROVER_assume((pub_r001623_8_2 >= (-100)) && (pub_r001623_8_2 <= 100));
  __CPROVER_assume((pub_r001623_9_1 >= (-100)) && (pub_r001623_9_1 <= 100));
  __CPROVER_assume((pub_r001623_9_2 >= (-100)) && (pub_r001623_9_2 <= 100));
  __CPROVER_assume((pub_r001623_10_1 >= (-100)) && (pub_r001623_10_1 <= 100));
  __CPROVER_assume((pub_r001623_10_2 >= (-100)) && (pub_r001623_10_2 <= 100));
  __CPROVER_assume((pub_r001623_11_1 >= (-100)) && (pub_r001623_11_1 <= 100));
  __CPROVER_assume((pub_r001623_11_2 >= (-100)) && (pub_r001623_11_2 <= 100));
  __CPROVER_assume((pub_r001623_12_1 >= (-100)) && (pub_r001623_12_1 <= 100));
  __CPROVER_assume((pub_r001623_12_2 >= (-100)) && (pub_r001623_12_2 <= 100));
  __CPROVER_assume((pub_r001623_13_1 >= (-100)) && (pub_r001623_13_1 <= 100));
  __CPROVER_assume((pub_r001623_13_2 >= (-100)) && (pub_r001623_13_2 <= 100));
  __CPROVER_assume((pub_r001623_14_1 >= (-100)) && (pub_r001623_14_1 <= 100));
  __CPROVER_assume((pub_r001623_14_2 >= (-100)) && (pub_r001623_14_2 <= 100));
  __CPROVER_assume((pub_r001623_15_1 >= (-100)) && (pub_r001623_15_1 <= 100));
  __CPROVER_assume((pub_r001623_15_2 >= (-100)) && (pub_r001623_15_2 <= 100));
  __CPROVER_assume((pub_r001623_16_1 >= (-100)) && (pub_r001623_16_1 <= 100));
  __CPROVER_assume((pub_r001623_16_2 >= (-100)) && (pub_r001623_16_2 <= 100));
  __CPROVER_assume((pub_r001623_17_1 >= (-100)) && (pub_r001623_17_1 <= 100));
  __CPROVER_assume((pub_r001623_17_2 >= (-100)) && (pub_r001623_17_2 <= 100));
  __CPROVER_assume((pub_r001623_18_1 >= (-100)) && (pub_r001623_18_1 <= 100));
  __CPROVER_assume((pub_r001623_18_2 >= (-100)) && (pub_r001623_18_2 <= 100));
  __CPROVER_assume((pub_r001623_19_1 >= (-100)) && (pub_r001623_19_1 <= 100));
  __CPROVER_assume((pub_r001623_19_2 >= (-100)) && (pub_r001623_19_2 <= 100));
  __CPROVER_assume((sec_r001623_0_1 >= 0) && (sec_r001623_0_1 <= 255));
  __CPROVER_assume((sec_r001623_0_2 >= 0) && (sec_r001623_0_2 <= 255));
  __CPROVER_assume((sec_r001623_1_1 >= 0) && (sec_r001623_1_1 <= 255));
  __CPROVER_assume((sec_r001623_1_2 >= 0) && (sec_r001623_1_2 <= 255));
  __CPROVER_assume((sec_r001623_2_1 >= 0) && (sec_r001623_2_1 <= 255));
  __CPROVER_assume((sec_r001623_2_2 >= 0) && (sec_r001623_2_2 <= 255));
  __CPROVER_assume((sec_r001623_3_1 >= 0) && (sec_r001623_3_1 <= 255));
  __CPROVER_assume((sec_r001623_3_2 >= 0) && (sec_r001623_3_2 <= 255));
  __CPROVER_assume((sec_r001623_4_1 >= 0) && (sec_r001623_4_1 <= 255));
  __CPROVER_assume((sec_r001623_4_2 >= 0) && (sec_r001623_4_2 <= 255));
  __CPROVER_assume((sec_r001623_5_1 >= 0) && (sec_r001623_5_1 <= 255));
  __CPROVER_assume((sec_r001623_5_2 >= 0) && (sec_r001623_5_2 <= 255));
  __CPROVER_assume((sec_r001623_6_1 >= 0) && (sec_r001623_6_1 <= 255));
  __CPROVER_assume((sec_r001623_6_2 >= 0) && (sec_r001623_6_2 <= 255));
  __CPROVER_assume((sec_r001623_7_1 >= 0) && (sec_r001623_7_1 <= 255));
  __CPROVER_assume((sec_r001623_7_2 >= 0) && (sec_r001623_7_2 <= 255));
  __CPROVER_assume((sec_r001623_8_1 >= 0) && (sec_r001623_8_1 <= 255));
  __CPROVER_assume((sec_r001623_8_2 >= 0) && (sec_r001623_8_2 <= 255));
  __CPROVER_assume((sec_r001623_9_1 >= 0) && (sec_r001623_9_1 <= 255));
  __CPROVER_assume((sec_r001623_9_2 >= 0) && (sec_r001623_9_2 <= 255));
  __CPROVER_assume((sec_r001623_10_1 >= 0) && (sec_r001623_10_1 <= 255));
  __CPROVER_assume((sec_r001623_10_2 >= 0) && (sec_r001623_10_2 <= 255));
  __CPROVER_assume((sec_r001623_11_1 >= 0) && (sec_r001623_11_1 <= 255));
  __CPROVER_assume((sec_r001623_11_2 >= 0) && (sec_r001623_11_2 <= 255));
  __CPROVER_assume((sec_r001623_12_1 >= 0) && (sec_r001623_12_1 <= 255));
  __CPROVER_assume((sec_r001623_12_2 >= 0) && (sec_r001623_12_2 <= 255));
  __CPROVER_assume((sec_r001623_13_1 >= 0) && (sec_r001623_13_1 <= 255));
  __CPROVER_assume((sec_r001623_13_2 >= 0) && (sec_r001623_13_2 <= 255));
  __CPROVER_assume((sec_r001623_14_1 >= 0) && (sec_r001623_14_1 <= 255));
  __CPROVER_assume((sec_r001623_14_2 >= 0) && (sec_r001623_14_2 <= 255));
  __CPROVER_assume((sec_r001623_15_1 >= 0) && (sec_r001623_15_1 <= 255));
  __CPROVER_assume((sec_r001623_15_2 >= 0) && (sec_r001623_15_2 <= 255));
  __CPROVER_assume((sec_r001623_16_1 >= 0) && (sec_r001623_16_1 <= 255));
  __CPROVER_assume((sec_r001623_16_2 >= 0) && (sec_r001623_16_2 <= 255));
  __CPROVER_assume((sec_r001623_17_1 >= 0) && (sec_r001623_17_1 <= 255));
  __CPROVER_assume((sec_r001623_17_2 >= 0) && (sec_r001623_17_2 <= 255));
  __CPROVER_assume((sec_r001623_18_1 >= 0) && (sec_r001623_18_1 <= 255));
  __CPROVER_assume((sec_r001623_18_2 >= 0) && (sec_r001623_18_2 <= 255));
  __CPROVER_assume((sec_r001623_19_1 >= 0) && (sec_r001623_19_1 <= 255));
  __CPROVER_assume((sec_r001623_19_2 >= 0) && (sec_r001623_19_2 <= 255));
  __CPROVER_assume((sec_r001623_20_1 >= 0) && (sec_r001623_20_1 <= 255));
  __CPROVER_assume((sec_r001623_20_2 >= 0) && (sec_r001623_20_2 <= 255));
  struct MatrixBlock_R001623_2313_0 st_var_0_1 = {0};
  struct MatrixBlock_R001623_2313_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001623_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001623_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001623_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001623_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001623_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001623_0_2 + 7) & 15;
  struct SensorNode_R001623_2313_1 st_var_1_1 = {0};
  struct SensorNode_R001623_2313_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001623_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001623_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001623_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001623_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001623_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001623_0_2 + 9) & 15;
  struct Vector3D_R001623_2313_2 st_var_2_1 = {0};
  struct Vector3D_R001623_2313_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r001623_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r001623_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r001623_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r001623_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r001623_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r001623_0_2 + 11) & 15;
  struct Transaction_R001623_2313_3 st_var_3_1 = {0};
  struct Transaction_R001623_2313_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r001623_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r001623_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r001623_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r001623_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r001623_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r001623_0_2 + 13) & 15;
  union ColorPixel_R001623_2313_0 u_var_1;
  union ColorPixel_R001623_2313_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001623_2313_0(sec_r001623_0_1, pub_r001623_1_1, pub_r001623_2_1);
  int helper_flow_0_2 = fn_R001623_2313_0(sec_r001623_0_2, pub_r001623_1_2, pub_r001623_2_2);
  fn_R001623_2313_0_2(sec_r001623_0_1, pub_r001623_1_1, pub_r001623_2_1, sec_r001623_0_2, pub_r001623_1_2, pub_r001623_2_2);
  int helper_flow_1_1 = fn_R001623_2313_1(sec_r001623_1_1, sec_r001623_2_1, pub_r001623_3_1);
  int helper_flow_1_2 = fn_R001623_2313_1(sec_r001623_1_2, sec_r001623_2_2, pub_r001623_3_2);
  fn_R001623_2313_1_2(sec_r001623_1_1, sec_r001623_2_1, pub_r001623_3_1, sec_r001623_1_2, sec_r001623_2_2, pub_r001623_3_2);
  int helper_flow_2_1 = fn_R001623_2313_2(sec_r001623_2_1, sec_r001623_3_1, pub_r001623_4_1, pub_r001623_5_1, pub_r001623_6_1);
  int helper_flow_2_2 = fn_R001623_2313_2(sec_r001623_2_2, sec_r001623_3_2, pub_r001623_4_2, pub_r001623_5_2, pub_r001623_6_2);
  fn_R001623_2313_2_2(sec_r001623_2_1, sec_r001623_3_1, pub_r001623_4_1, pub_r001623_5_1, pub_r001623_6_1, sec_r001623_2_2, sec_r001623_3_2, pub_r001623_4_2, pub_r001623_5_2, pub_r001623_6_2);
  int helper_flow_3_1 = fn_R001623_2313_3(sec_r001623_3_1, pub_r001623_4_1, pub_r001623_5_1);
  int helper_flow_3_2 = fn_R001623_2313_3(sec_r001623_3_2, pub_r001623_4_2, pub_r001623_5_2);
  fn_R001623_2313_3_2(sec_r001623_3_1, pub_r001623_4_1, pub_r001623_5_1, sec_r001623_3_2, pub_r001623_4_2, pub_r001623_5_2);
  int helper_flow_4_1 = fn_R001623_2313_4(sec_r001623_4_1, pub_r001623_5_1, pub_r001623_6_1, pub_r001623_7_1);
  int helper_flow_4_2 = fn_R001623_2313_4(sec_r001623_4_2, pub_r001623_5_2, pub_r001623_6_2, pub_r001623_7_2);
  fn_R001623_2313_4_2(sec_r001623_4_1, pub_r001623_5_1, pub_r001623_6_1, pub_r001623_7_1, sec_r001623_4_2, pub_r001623_5_2, pub_r001623_6_2, pub_r001623_7_2);
  int helper_flow_5_1 = fn_R001623_2313_5(sec_r001623_5_1, pub_r001623_6_1);
  int helper_flow_5_2 = fn_R001623_2313_5(sec_r001623_5_2, pub_r001623_6_2);
  fn_R001623_2313_5_2(sec_r001623_5_1, pub_r001623_6_1, sec_r001623_5_2, pub_r001623_6_2);
  int helper_flow_6_1 = fn_R001623_2313_6(sec_r001623_6_1, pub_r001623_7_1);
  int helper_flow_6_2 = fn_R001623_2313_6(sec_r001623_6_2, pub_r001623_7_2);
  fn_R001623_2313_6_2(sec_r001623_6_1, pub_r001623_7_1, sec_r001623_6_2, pub_r001623_7_2);
  int helper_flow_7_1 = fn_R001623_2313_7(sec_r001623_7_1, pub_r001623_8_1, pub_r001623_9_1, pub_r001623_10_1, pub_r001623_11_1);
  int helper_flow_7_2 = fn_R001623_2313_7(sec_r001623_7_2, pub_r001623_8_2, pub_r001623_9_2, pub_r001623_10_2, pub_r001623_11_2);
  fn_R001623_2313_7_2(sec_r001623_7_1, pub_r001623_8_1, pub_r001623_9_1, pub_r001623_10_1, pub_r001623_11_1, sec_r001623_7_2, pub_r001623_8_2, pub_r001623_9_2, pub_r001623_10_2, pub_r001623_11_2);
  int stage_v_0_1 = (((sec_r001623_5_1 * 3) + pub_r001623_12_1) + 6) & 127;
  int stage_v_0_2 = (((sec_r001623_5_2 * 3) + pub_r001623_12_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = ((pub_r001623_14_1 * 2) + 33) & 63;
  int stage_v_1_2 = ((pub_r001623_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_1_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_1_2) & 127;
  int stage_v_2_1 = (((sec_r001623_11_1 * 3) + pub_r001623_12_1) + 29) & 127;
  int stage_v_2_2 = (((sec_r001623_11_2 * 3) + pub_r001623_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_2_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_2_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_2_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_2_2 * 2)) & 255;
  int stage_v_3_1 = ((pub_r001623_0_1 * 2) + 27) & 63;
  int stage_v_3_2 = ((pub_r001623_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_3_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_3_2) & 127;
  int stage_v_4_1 = (((sec_r001623_2_1 * 3) + pub_r001623_10_1) + 6) & 127;
  int stage_v_4_2 = (((sec_r001623_2_2 * 3) + pub_r001623_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_4_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_4_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_4_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_4_2 * 2)) & 255;
  int stage_v_5_1 = ((pub_r001623_6_1 * 2) + 25) & 63;
  int stage_v_5_2 = ((pub_r001623_6_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_5_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_5_2) & 127;
  int stage_v_6_1 = ((pub_r001623_14_1 * 2) + 40) & 63;
  int stage_v_6_2 = ((pub_r001623_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = ((pub_r001623_16_1 * 2) + 42) & 63;
  int stage_v_7_2 = ((pub_r001623_16_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_7_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_7_2) & 127;
  int stage_v_8_1 = (((sec_r001623_16_1 * 3) + pub_r001623_14_1) + 6) & 127;
  int stage_v_8_2 = (((sec_r001623_16_2 * 3) + pub_r001623_14_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_8_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_8_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_8_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_8_2 * 2)) & 255;
  int stage_v_9_1 = ((pub_r001623_11_1 * 2) + 9) & 63;
  int stage_v_9_2 = ((pub_r001623_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((helper_flow_3_1 * 3) + pub_r001623_2_1) + 39) & 127;
  int stage_v_10_2 = (((helper_flow_3_2 * 3) + pub_r001623_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = ((pub_r001623_12_1 * 2) + 15) & 63;
  int stage_v_11_2 = ((pub_r001623_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_11_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_11_2) & 127;
  int stage_v_12_1 = ((pub_r001623_17_1 * 2) + 27) & 63;
  int stage_v_12_2 = ((pub_r001623_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_12_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_12_2) & 127;
  int stage_v_13_1 = (((sec_r001623_16_1 * 3) + pub_r001623_18_1) + 30) & 127;
  int stage_v_13_2 = (((sec_r001623_16_2 * 3) + pub_r001623_18_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_13_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_13_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_13_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_13_2 * 2)) & 255;
  int stage_v_14_1 = (((stage_v_8_1 * 3) + pub_r001623_2_1) + 22) & 127;
  int stage_v_14_2 = (((stage_v_8_2 * 3) + pub_r001623_2_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_14_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_14_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_14_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_14_2 * 2)) & 255;
  int stage_v_15_1 = (((sec_r001623_15_1 * 3) + pub_r001623_8_1) + 25) & 127;
  int stage_v_15_2 = (((sec_r001623_15_2 * 3) + pub_r001623_8_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_15_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_15_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_15_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_15_2 * 2)) & 255;
  int stage_v_16_1 = (((helper_flow_2_1 * 3) + pub_r001623_4_1) + 21) & 127;
  int stage_v_16_2 = (((helper_flow_2_2 * 3) + pub_r001623_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001623_0_1 * 2) + 27) & 63;
  int stage_v_17_2 = ((pub_r001623_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((helper_flow_4_1 * 3) + pub_r001623_5_1) + 17) & 127;
  int stage_v_18_2 = (((helper_flow_4_2 * 3) + pub_r001623_5_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = ((pub_r001623_4_1 * 2) + 18) & 63;
  int stage_v_19_2 = ((pub_r001623_4_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_19_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_19_2) & 127;
  int stage_v_20_1 = (((sec_r001623_17_1 * 3) + pub_r001623_14_1) + 4) & 127;
  int stage_v_20_2 = (((sec_r001623_17_2 * 3) + pub_r001623_14_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_20_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_20_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_20_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_20_2 * 2)) & 255;
  int stage_v_21_1 = ((pub_r001623_0_1 * 2) + 48) & 63;
  int stage_v_21_2 = ((pub_r001623_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001623_17_1 * 2) + 6) & 63;
  int stage_v_22_2 = ((pub_r001623_17_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = (((stage_v_4_1 * 3) + pub_r001623_13_1) + 21) & 127;
  int stage_v_23_2 = (((stage_v_4_2 * 3) + pub_r001623_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_23_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_23_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_23_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_23_2 * 2)) & 255;
  int stage_v_24_1 = (((stage_v_13_1 * 3) + pub_r001623_4_1) + 35) & 127;
  int stage_v_24_2 = (((stage_v_13_2 * 3) + pub_r001623_4_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_24_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_24_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_24_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_24_2 * 2)) & 255;
  int stage_v_25_1 = ((pub_r001623_13_1 * 2) + 47) & 63;
  int stage_v_25_2 = ((pub_r001623_13_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001623_1_1 * 2) + 50) & 63;
  int stage_v_26_2 = ((pub_r001623_1_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = ((pub_r001623_9_1 * 2) + 38) & 63;
  int stage_v_27_2 = ((pub_r001623_9_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_27_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_27_2) & 127;
  int stage_v_28_1 = (((helper_flow_2_1 * 3) + pub_r001623_3_1) + 28) & 127;
  int stage_v_28_2 = (((helper_flow_2_2 * 3) + pub_r001623_3_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_28_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_28_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_28_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_28_2 * 2)) & 255;
  int stage_v_29_1 = (((sec_r001623_9_1 * 3) + pub_r001623_1_1) + 22) & 127;
  int stage_v_29_2 = (((sec_r001623_9_2 * 3) + pub_r001623_1_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = ((pub_r001623_1_1 * 2) + 13) & 63;
  int stage_v_30_2 = ((pub_r001623_1_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_30_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_30_2) & 127;
  int stage_v_31_1 = (((sec_r001623_6_1 * 3) + pub_r001623_17_1) + 39) & 127;
  int stage_v_31_2 = (((sec_r001623_6_2 * 3) + pub_r001623_17_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_31_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_31_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_31_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_31_2 * 2)) & 255;
  int stage_v_32_1 = (((helper_flow_3_1 * 3) + pub_r001623_11_1) + 14) & 127;
  int stage_v_32_2 = (((helper_flow_3_2 * 3) + pub_r001623_11_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = ((pub_r001623_3_1 * 2) + 24) & 63;
  int stage_v_33_2 = ((pub_r001623_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_33_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_33_2) & 127;
  int stage_v_34_1 = (((helper_flow_3_1 * 3) + pub_r001623_3_1) + 17) & 127;
  int stage_v_34_2 = (((helper_flow_3_2 * 3) + pub_r001623_3_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001623_13_1 * 2) + 12) & 63;
  int stage_v_35_2 = ((pub_r001623_13_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (((sec_r001623_17_1 * 3) + pub_r001623_2_1) + 6) & 127;
  int stage_v_36_2 = (((sec_r001623_17_2 * 3) + pub_r001623_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_36_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_36_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_36_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_36_2 * 2)) & 255;
  int stage_v_37_1 = ((pub_r001623_1_1 * 2) + 19) & 63;
  int stage_v_37_2 = ((pub_r001623_1_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_37_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_37_2) & 127;
  int stage_v_38_1 = ((pub_r001623_7_1 * 2) + 18) & 63;
  int stage_v_38_2 = ((pub_r001623_7_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = ((pub_r001623_9_1 * 2) + 28) & 63;
  int stage_v_39_2 = ((pub_r001623_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_39_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_39_2) & 127;
  int stage_v_40_1 = (((helper_flow_2_1 * 3) + pub_r001623_19_1) + 37) & 127;
  int stage_v_40_2 = (((helper_flow_2_2 * 3) + pub_r001623_19_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_40_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_40_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_40_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_40_2 * 2)) & 255;
  int stage_v_41_1 = (((stage_v_31_1 * 3) + pub_r001623_7_1) + 4) & 127;
  int stage_v_41_2 = (((stage_v_31_2 * 3) + pub_r001623_7_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_41_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_41_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_41_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_41_2 * 2)) & 255;
  int stage_v_42_1 = (((helper_flow_2_1 * 3) + pub_r001623_16_1) + 11) & 127;
  int stage_v_42_2 = (((helper_flow_2_2 * 3) + pub_r001623_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_42_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_42_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_42_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_42_2 * 2)) & 255;
  int stage_v_43_1 = ((pub_r001623_5_1 * 2) + 48) & 63;
  int stage_v_43_2 = ((pub_r001623_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (((sec_r001623_12_1 * 3) + pub_r001623_19_1) + 33) & 127;
  int stage_v_44_2 = (((sec_r001623_12_2 * 3) + pub_r001623_19_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_44_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_44_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_44_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_44_2 * 2)) & 255;
  int stage_v_45_1 = (((stage_v_0_1 * 3) + pub_r001623_12_1) + 18) & 127;
  int stage_v_45_2 = (((stage_v_0_2 * 3) + pub_r001623_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = (((sec_r001623_18_1 * 3) + pub_r001623_8_1) + 35) & 127;
  int stage_v_46_2 = (((sec_r001623_18_2 * 3) + pub_r001623_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_46_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_46_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_46_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_46_2 * 2)) & 255;
  int stage_v_47_1 = ((pub_r001623_2_1 * 2) + 41) & 63;
  int stage_v_47_2 = ((pub_r001623_2_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_47_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_47_2) & 127;
  int stage_v_48_1 = ((pub_r001623_2_1 * 2) + 13) & 63;
  int stage_v_48_2 = ((pub_r001623_2_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = (((sec_r001623_4_1 * 3) + pub_r001623_3_1) + 24) & 127;
  int stage_v_49_2 = (((sec_r001623_4_2 * 3) + pub_r001623_3_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_49_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_49_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_49_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_49_2 * 2)) & 255;
  int stage_v_50_1 = ((pub_r001623_16_1 * 2) + 19) & 63;
  int stage_v_50_2 = ((pub_r001623_16_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001623_12_1 * 2) + 14) & 63;
  int stage_v_51_2 = ((pub_r001623_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = (((stage_v_18_1 * 3) + pub_r001623_2_1) + 30) & 127;
  int stage_v_52_2 = (((stage_v_18_2 * 3) + pub_r001623_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_52_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_52_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_52_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_52_2 * 2)) & 255;
  int stage_v_53_1 = ((pub_r001623_8_1 * 2) + 23) & 63;
  int stage_v_53_2 = ((pub_r001623_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (((stage_v_42_1 * 3) + pub_r001623_3_1) + 31) & 127;
  int stage_v_54_2 = (((stage_v_42_2 * 3) + pub_r001623_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_54_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_54_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_54_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_54_2 * 2)) & 255;
  int stage_v_55_1 = ((pub_r001623_1_1 * 2) + 37) & 63;
  int stage_v_55_2 = ((pub_r001623_1_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  int stage_v_56_1 = (((stage_v_54_1 * 3) + pub_r001623_2_1) + 5) & 127;
  int stage_v_56_2 = (((stage_v_54_2 * 3) + pub_r001623_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_56_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_56_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_56_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_56_2 * 2)) & 255;
  int stage_v_57_1 = (((sec_r001623_4_1 * 3) + pub_r001623_17_1) + 33) & 127;
  int stage_v_57_2 = (((sec_r001623_4_2 * 3) + pub_r001623_17_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_57_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_57_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_57_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_57_2 * 2)) & 255;
  int stage_v_58_1 = (((helper_flow_7_1 * 3) + pub_r001623_6_1) + 18) & 127;
  int stage_v_58_2 = (((helper_flow_7_2 * 3) + pub_r001623_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_58_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_58_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_58_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_58_2 * 2)) & 255;
  int stage_v_59_1 = (((helper_flow_0_1 * 3) + pub_r001623_0_1) + 21) & 127;
  int stage_v_59_2 = (((helper_flow_0_2 * 3) + pub_r001623_0_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_59_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_59_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_59_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_59_2 * 2)) & 255;
  int stage_v_60_1 = ((pub_r001623_19_1 * 2) + 36) & 63;
  int stage_v_60_2 = ((pub_r001623_19_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001623_11_1 * 2) + 9) & 63;
  int stage_v_61_2 = ((pub_r001623_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = (((stage_v_29_1 * 3) + pub_r001623_8_1) + 32) & 127;
  int stage_v_62_2 = (((stage_v_29_2 * 3) + pub_r001623_8_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_62_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_62_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_62_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_62_2 * 2)) & 255;
  int stage_v_63_1 = (((stage_v_45_1 * 3) + pub_r001623_18_1) + 34) & 127;
  int stage_v_63_2 = (((stage_v_45_2 * 3) + pub_r001623_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = ((pub_r001623_15_1 * 2) + 9) & 63;
  int stage_v_64_2 = ((pub_r001623_15_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = (((stage_v_63_1 * 3) + pub_r001623_1_1) + 39) & 127;
  int stage_v_65_2 = (((stage_v_63_2 * 3) + pub_r001623_1_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_65_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_65_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_65_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_65_2 * 2)) & 255;
  int stage_v_66_1 = (((stage_v_45_1 * 3) + pub_r001623_10_1) + 6) & 127;
  int stage_v_66_2 = (((stage_v_45_2 * 3) + pub_r001623_10_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_66_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_66_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_66_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_66_2 * 2)) & 255;
  int stage_v_67_1 = (((sec_r001623_19_1 * 3) + pub_r001623_3_1) + 4) & 127;
  int stage_v_67_2 = (((sec_r001623_19_2 * 3) + pub_r001623_3_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_44_1 * 3) + pub_r001623_4_1) + 22) & 127;
  int stage_v_68_2 = (((stage_v_44_2 * 3) + pub_r001623_4_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = ((pub_r001623_0_1 * 2) + 31) & 63;
  int stage_v_69_2 = ((pub_r001623_0_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_69_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_69_2) & 127;
  int stage_v_70_1 = (((sec_r001623_0_1 * 3) + pub_r001623_13_1) + 32) & 127;
  int stage_v_70_2 = (((sec_r001623_0_2 * 3) + pub_r001623_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((stage_v_4_1 * 3) + pub_r001623_4_1) + 40) & 127;
  int stage_v_71_2 = (((stage_v_4_2 * 3) + pub_r001623_4_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = ((pub_r001623_5_1 * 2) + 46) & 63;
  int stage_v_72_2 = ((pub_r001623_5_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  int stage_v_73_1 = (((stage_v_29_1 * 3) + pub_r001623_8_1) + 45) & 127;
  int stage_v_73_2 = (((stage_v_29_2 * 3) + pub_r001623_8_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_73_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_73_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_73_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_73_2 * 2)) & 255;
  int stage_v_74_1 = ((pub_r001623_18_1 * 2) + 10) & 63;
  int stage_v_74_2 = ((pub_r001623_18_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (((helper_flow_5_1 * 3) + pub_r001623_13_1) + 24) & 127;
  int stage_v_75_2 = (((helper_flow_5_2 * 3) + pub_r001623_13_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_75_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_75_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_75_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_75_2 * 2)) & 255;
  int stage_v_76_1 = ((pub_r001623_16_1 * 2) + 12) & 63;
  int stage_v_76_2 = ((pub_r001623_16_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001623_4_1 * 2) + 46) & 63;
  int stage_v_77_2 = ((pub_r001623_4_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_41_1 * 3) + pub_r001623_13_1) + 37) & 127;
  int stage_v_78_2 = (((stage_v_41_2 * 3) + pub_r001623_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001623_1_1 * 2) + 40) & 63;
  int stage_v_79_2 = ((pub_r001623_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001623_16_1 * 2) + 40) & 63;
  int stage_v_80_2 = ((pub_r001623_16_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (((sec_r001623_11_1 * 3) + pub_r001623_18_1) + 27) & 127;
  int stage_v_81_2 = (((sec_r001623_11_2 * 3) + pub_r001623_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_81_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_81_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_81_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_81_2 * 2)) & 255;
  int stage_v_82_1 = (((sec_r001623_19_1 * 3) + pub_r001623_12_1) + 32) & 127;
  int stage_v_82_2 = (((sec_r001623_19_2 * 3) + pub_r001623_12_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = ((pub_r001623_6_1 * 2) + 48) & 63;
  int stage_v_83_2 = ((pub_r001623_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_83_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_83_2) & 127;
  int stage_v_84_1 = (((stage_v_62_1 * 3) + pub_r001623_17_1) + 44) & 127;
  int stage_v_84_2 = (((stage_v_62_2 * 3) + pub_r001623_17_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_84_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_84_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_84_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_84_2 * 2)) & 255;
  int stage_v_85_1 = ((pub_r001623_0_1 * 2) + 25) & 63;
  int stage_v_85_2 = ((pub_r001623_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_29_1 * 3) + pub_r001623_12_1) + 34) & 127;
  int stage_v_86_2 = (((stage_v_29_2 * 3) + pub_r001623_12_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001623_9_1 * 2) + 41) & 63;
  int stage_v_87_2 = ((pub_r001623_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_71_1 * 3) + pub_r001623_12_1) + 27) & 127;
  int stage_v_88_2 = (((stage_v_71_2 * 3) + pub_r001623_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001623_17_1 * 2) + 25) & 63;
  int stage_v_89_2 = ((pub_r001623_17_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (((stage_v_28_1 * 3) + pub_r001623_11_1) + 21) & 127;
  int stage_v_90_2 = (((stage_v_28_2 * 3) + pub_r001623_11_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_90_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_90_2 * 2)) & 255;
  int stage_v_91_1 = ((pub_r001623_6_1 * 2) + 34) & 63;
  int stage_v_91_2 = ((pub_r001623_6_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001623_19_1 * 2) + 42) & 63;
  int stage_v_92_2 = ((pub_r001623_19_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001623_7_1 * 2) + 49) & 63;
  int stage_v_93_2 = ((pub_r001623_7_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = (((stage_v_63_1 * 3) + pub_r001623_0_1) + 10) & 127;
  int stage_v_94_2 = (((stage_v_63_2 * 3) + pub_r001623_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_94_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_94_2 * 2)) & 255;
  int stage_v_95_1 = ((pub_r001623_3_1 * 2) + 20) & 63;
  int stage_v_95_2 = ((pub_r001623_3_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_42_1 * 3) + pub_r001623_14_1) + 8) & 127;
  int stage_v_96_2 = (((stage_v_42_2 * 3) + pub_r001623_14_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = (((sec_r001623_15_1 * 3) + pub_r001623_19_1) + 40) & 127;
  int stage_v_97_2 = (((sec_r001623_15_2 * 3) + pub_r001623_19_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_97_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_97_2 * 2)) & 255;
  int stage_v_98_1 = (((stage_v_13_1 * 3) + pub_r001623_11_1) + 19) & 127;
  int stage_v_98_2 = (((stage_v_13_2 * 3) + pub_r001623_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((sec_r001623_10_1 * 3) + pub_r001623_5_1) + 43) & 127;
  int stage_v_99_2 = (((sec_r001623_10_2 * 3) + pub_r001623_5_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001623_0_1 * 2) + 40) & 63;
  int stage_v_100_2 = ((pub_r001623_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001623_11_1 * 2) + 29) & 63;
  int stage_v_101_2 = ((pub_r001623_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = (((stage_v_68_1 * 3) + pub_r001623_7_1) + 33) & 127;
  int stage_v_102_2 = (((stage_v_68_2 * 3) + pub_r001623_7_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_102_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_102_2 * 2)) & 255;
  int stage_v_103_1 = ((pub_r001623_0_1 * 2) + 40) & 63;
  int stage_v_103_2 = ((pub_r001623_0_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001623_7_1 * 3) + pub_r001623_0_1) + 4) & 127;
  int stage_v_104_2 = (((sec_r001623_7_2 * 3) + pub_r001623_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001623_8_1 * 2) + 23) & 63;
  int stage_v_105_2 = ((pub_r001623_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001623_11_1 * 2) + 50) & 63;
  int stage_v_106_2 = ((pub_r001623_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = (((stage_v_8_1 * 3) + pub_r001623_13_1) + 36) & 127;
  int stage_v_107_2 = (((stage_v_8_2 * 3) + pub_r001623_13_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_107_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_107_2 * 2)) & 255;
  int stage_v_108_1 = (((stage_v_10_1 * 3) + pub_r001623_19_1) + 5) & 127;
  int stage_v_108_2 = (((stage_v_10_2 * 3) + pub_r001623_19_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_108_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_108_2 * 2)) & 255;
  int stage_v_109_1 = ((pub_r001623_16_1 * 2) + 14) & 63;
  int stage_v_109_2 = ((pub_r001623_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = (((stage_v_59_1 * 3) + pub_r001623_15_1) + 15) & 127;
  int stage_v_110_2 = (((stage_v_59_2 * 3) + pub_r001623_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_110_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_110_2 * 2)) & 255;
  int stage_v_111_1 = ((pub_r001623_3_1 * 2) + 22) & 63;
  int stage_v_111_2 = ((pub_r001623_3_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = (((stage_v_99_1 * 3) + pub_r001623_17_1) + 27) & 127;
  int stage_v_112_2 = (((stage_v_99_2 * 3) + pub_r001623_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_112_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_112_2 * 2)) & 255;
  int stage_v_113_1 = (((stage_v_8_1 * 3) + pub_r001623_15_1) + 22) & 127;
  int stage_v_113_2 = (((stage_v_8_2 * 3) + pub_r001623_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001623_5_1 * 2) + 39) & 63;
  int stage_v_114_2 = ((pub_r001623_5_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001623_11_1 * 2) + 50) & 63;
  int stage_v_115_2 = ((pub_r001623_11_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = (((stage_v_56_1 * 3) + pub_r001623_7_1) + 31) & 127;
  int stage_v_116_2 = (((stage_v_56_2 * 3) + pub_r001623_7_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_116_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_116_2 * 2)) & 255;
  int stage_v_117_1 = (((helper_flow_7_1 * 3) + pub_r001623_16_1) + 4) & 127;
  int stage_v_117_2 = (((helper_flow_7_2 * 3) + pub_r001623_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_117_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_117_2 * 2)) & 255;
  int stage_v_118_1 = (((stage_v_54_1 * 3) + pub_r001623_5_1) + 31) & 127;
  int stage_v_118_2 = (((stage_v_54_2 * 3) + pub_r001623_5_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_118_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_118_2 * 2)) & 255;
  int stage_v_119_1 = ((pub_r001623_1_1 * 2) + 12) & 63;
  int stage_v_119_2 = ((pub_r001623_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_86_1 * 3) + pub_r001623_18_1) + 40) & 127;
  int stage_v_120_2 = (((stage_v_86_2 * 3) + pub_r001623_18_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = (((sec_r001623_11_1 * 3) + pub_r001623_6_1) + 25) & 127;
  int stage_v_121_2 = (((sec_r001623_11_2 * 3) + pub_r001623_6_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_121_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_121_2 * 2)) & 255;
  int stage_v_122_1 = ((pub_r001623_2_1 * 2) + 43) & 63;
  int stage_v_122_2 = ((pub_r001623_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001623_19_1 * 2) + 10) & 63;
  int stage_v_123_2 = ((pub_r001623_19_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001623_9_1 * 2) + 19) & 63;
  int stage_v_124_2 = ((pub_r001623_9_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001623_11_1 * 2) + 30) & 63;
  int stage_v_125_2 = ((pub_r001623_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = (((stage_v_32_1 * 3) + pub_r001623_10_1) + 44) & 127;
  int stage_v_126_2 = (((stage_v_32_2 * 3) + pub_r001623_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_126_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_126_2 * 2)) & 255;
  int stage_v_127_1 = ((pub_r001623_16_1 * 2) + 43) & 63;
  int stage_v_127_2 = ((pub_r001623_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (((stage_v_116_1 * 3) + pub_r001623_15_1) + 5) & 127;
  int stage_v_128_2 = (((stage_v_116_2 * 3) + pub_r001623_15_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_128_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_128_2 * 2)) & 255;
  int stage_v_129_1 = (((stage_v_75_1 * 3) + pub_r001623_9_1) + 15) & 127;
  int stage_v_129_2 = (((stage_v_75_2 * 3) + pub_r001623_9_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((sec_r001623_3_1 * 3) + pub_r001623_15_1) + 22) & 127;
  int stage_v_130_2 = (((sec_r001623_3_2 * 3) + pub_r001623_15_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = (((stage_v_107_1 * 3) + pub_r001623_9_1) + 28) & 127;
  int stage_v_131_2 = (((stage_v_107_2 * 3) + pub_r001623_9_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_131_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_131_2 * 2)) & 255;
  int stage_v_132_1 = ((pub_r001623_11_1 * 2) + 6) & 63;
  int stage_v_132_2 = ((pub_r001623_11_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((sec_r001623_16_1 * 3) + pub_r001623_1_1) + 45) & 127;
  int stage_v_133_2 = (((sec_r001623_16_2 * 3) + pub_r001623_1_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = (((stage_v_40_1 * 3) + pub_r001623_2_1) + 42) & 127;
  int stage_v_134_2 = (((stage_v_40_2 * 3) + pub_r001623_2_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_134_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_134_2 * 2)) & 255;
  int stage_v_135_1 = (((stage_v_73_1 * 3) + pub_r001623_18_1) + 37) & 127;
  int stage_v_135_2 = (((stage_v_73_2 * 3) + pub_r001623_18_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_135_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_135_2 * 2)) & 255;
  int stage_v_136_1 = ((pub_r001623_18_1 * 2) + 49) & 63;
  int stage_v_136_2 = ((pub_r001623_18_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001623_9_1 * 2) + 33) & 63;
  int stage_v_137_2 = ((pub_r001623_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001623_3_1 * 2) + 11) & 63;
  int stage_v_138_2 = ((pub_r001623_3_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = (((stage_v_120_1 * 3) + pub_r001623_8_1) + 19) & 127;
  int stage_v_139_2 = (((stage_v_120_2 * 3) + pub_r001623_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_139_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_139_2 * 2)) & 255;
  int stage_v_140_1 = (((stage_v_56_1 * 3) + pub_r001623_16_1) + 11) & 127;
  int stage_v_140_2 = (((stage_v_56_2 * 3) + pub_r001623_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_8_1 * 3) + pub_r001623_7_1) + 38) & 127;
  int stage_v_141_2 = (((stage_v_8_2 * 3) + pub_r001623_7_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_56_1 * 3) + pub_r001623_15_1) + 30) & 127;
  int stage_v_142_2 = (((stage_v_56_2 * 3) + pub_r001623_15_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = (((stage_v_2_1 * 3) + pub_r001623_17_1) + 14) & 127;
  int stage_v_143_2 = (((stage_v_2_2 * 3) + pub_r001623_17_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_143_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_143_2 * 2)) & 255;
  int stage_v_144_1 = (((stage_v_128_1 * 3) + pub_r001623_16_1) + 30) & 127;
  int stage_v_144_2 = (((stage_v_128_2 * 3) + pub_r001623_16_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = (((stage_v_66_1 * 3) + pub_r001623_5_1) + 29) & 127;
  int stage_v_145_2 = (((stage_v_66_2 * 3) + pub_r001623_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_145_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_145_2 * 2)) & 255;
  int stage_v_146_1 = ((pub_r001623_14_1 * 2) + 45) & 63;
  int stage_v_146_2 = ((pub_r001623_14_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = (((sec_r001623_7_1 * 3) + pub_r001623_17_1) + 24) & 127;
  int stage_v_147_2 = (((sec_r001623_7_2 * 3) + pub_r001623_17_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_147_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_147_2 * 2)) & 255;
  int stage_v_148_1 = (((sec_r001623_4_1 * 3) + pub_r001623_17_1) + 9) & 127;
  int stage_v_148_2 = (((sec_r001623_4_2 * 3) + pub_r001623_17_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_148_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_148_2 * 2)) & 255;
  int stage_v_149_1 = ((pub_r001623_11_1 * 2) + 5) & 63;
  int stage_v_149_2 = ((pub_r001623_11_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = ((pub_r001623_1_1 * 2) + 25) & 63;
  int stage_v_150_2 = ((pub_r001623_1_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_150_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_150_2) & 127;
  int stage_v_151_1 = ((pub_r001623_10_1 * 2) + 49) & 63;
  int stage_v_151_2 = ((pub_r001623_10_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((stage_v_86_1 * 3) + pub_r001623_14_1) + 18) & 127;
  int stage_v_152_2 = (((stage_v_86_2 * 3) + pub_r001623_14_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = (((stage_v_45_1 * 3) + pub_r001623_9_1) + 29) & 127;
  int stage_v_153_2 = (((stage_v_45_2 * 3) + pub_r001623_9_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_153_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_153_2 * 2)) & 255;
  int stage_v_154_1 = (((sec_r001623_4_1 * 3) + pub_r001623_9_1) + 11) & 127;
  int stage_v_154_2 = (((sec_r001623_4_2 * 3) + pub_r001623_9_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_154_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_154_2 * 2)) & 255;
  int stage_v_155_1 = (((stage_v_52_1 * 3) + pub_r001623_7_1) + 41) & 127;
  int stage_v_155_2 = (((stage_v_52_2 * 3) + pub_r001623_7_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_155_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_155_2 * 2)) & 255;
  int stage_v_156_1 = (((helper_flow_5_1 * 3) + pub_r001623_12_1) + 33) & 127;
  int stage_v_156_2 = (((helper_flow_5_2 * 3) + pub_r001623_12_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_156_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_156_2 * 2)) & 255;
  int stage_v_157_1 = (((stage_v_4_1 * 3) + pub_r001623_16_1) + 42) & 127;
  int stage_v_157_2 = (((stage_v_4_2 * 3) + pub_r001623_16_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = (((stage_v_14_1 * 3) + pub_r001623_13_1) + 14) & 127;
  int stage_v_158_2 = (((stage_v_14_2 * 3) + pub_r001623_13_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_158_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_158_2 * 2)) & 255;
  int stage_v_159_1 = (((stage_v_157_1 * 3) + pub_r001623_8_1) + 19) & 127;
  int stage_v_159_2 = (((stage_v_157_2 * 3) + pub_r001623_8_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_159_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_159_2 * 2)) & 255;
  int stage_v_160_1 = (((stage_v_141_1 * 3) + pub_r001623_17_1) + 16) & 127;
  int stage_v_160_2 = (((stage_v_141_2 * 3) + pub_r001623_17_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_160_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_160_2 * 2)) & 255;
  int stage_v_161_1 = ((pub_r001623_18_1 * 2) + 37) & 63;
  int stage_v_161_2 = ((pub_r001623_18_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = (((stage_v_152_1 * 3) + pub_r001623_9_1) + 5) & 127;
  int stage_v_162_2 = (((stage_v_152_2 * 3) + pub_r001623_9_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_162_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_162_2 * 2)) & 255;
  int stage_v_163_1 = (((stage_v_78_1 * 3) + pub_r001623_7_1) + 8) & 127;
  int stage_v_163_2 = (((stage_v_78_2 * 3) + pub_r001623_7_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_163_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_163_2 * 2)) & 255;
  int stage_v_164_1 = ((pub_r001623_3_1 * 2) + 42) & 63;
  int stage_v_164_2 = ((pub_r001623_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001623_12_1 * 2) + 37) & 63;
  int stage_v_165_2 = ((pub_r001623_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_75_1 * 3) + pub_r001623_9_1) + 10) & 127;
  int stage_v_166_2 = (((stage_v_75_2 * 3) + pub_r001623_9_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = ((pub_r001623_5_1 * 2) + 48) & 63;
  int stage_v_167_2 = ((pub_r001623_5_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_167_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_167_2) & 127;
  int stage_v_168_1 = (((helper_flow_6_1 * 3) + pub_r001623_1_1) + 38) & 127;
  int stage_v_168_2 = (((helper_flow_6_2 * 3) + pub_r001623_1_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((stage_v_142_1 * 3) + pub_r001623_8_1) + 41) & 127;
  int stage_v_169_2 = (((stage_v_142_2 * 3) + pub_r001623_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = (((stage_v_15_1 * 3) + pub_r001623_10_1) + 40) & 127;
  int stage_v_170_2 = (((stage_v_15_2 * 3) + pub_r001623_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_170_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_170_2 * 2)) & 255;
  int stage_v_171_1 = ((pub_r001623_15_1 * 2) + 47) & 63;
  int stage_v_171_2 = ((pub_r001623_15_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_169_1 * 3) + pub_r001623_9_1) + 33) & 127;
  int stage_v_172_2 = (((stage_v_169_2 * 3) + pub_r001623_9_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001623_18_1 * 2) + 16) & 63;
  int stage_v_173_2 = ((pub_r001623_18_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = (((stage_v_75_1 * 3) + pub_r001623_8_1) + 36) & 127;
  int stage_v_174_2 = (((stage_v_75_2 * 3) + pub_r001623_8_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_174_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_174_2 * 2)) & 255;
  int stage_v_175_1 = (((stage_v_104_1 * 3) + pub_r001623_8_1) + 13) & 127;
  int stage_v_175_2 = (((stage_v_104_2 * 3) + pub_r001623_8_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_175_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_175_2 * 2)) & 255;
  int stage_v_176_1 = (((sec_r001623_9_1 * 3) + pub_r001623_8_1) + 39) & 127;
  int stage_v_176_2 = (((sec_r001623_9_2 * 3) + pub_r001623_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_176_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_176_2 * 2)) & 255;
  int stage_v_177_1 = (((stage_v_170_1 * 3) + pub_r001623_15_1) + 15) & 127;
  int stage_v_177_2 = (((stage_v_170_2 * 3) + pub_r001623_15_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_177_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_177_2 * 2)) & 255;
  int stage_v_178_1 = (((stage_v_88_1 * 3) + pub_r001623_9_1) + 22) & 127;
  int stage_v_178_2 = (((stage_v_88_2 * 3) + pub_r001623_9_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = (((sec_r001623_0_1 * 3) + pub_r001623_6_1) + 11) & 127;
  int stage_v_179_2 = (((sec_r001623_0_2 * 3) + pub_r001623_6_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_179_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_179_2 * 2)) & 255;
  int stage_v_180_1 = (((stage_v_67_1 * 3) + pub_r001623_3_1) + 33) & 127;
  int stage_v_180_2 = (((stage_v_67_2 * 3) + pub_r001623_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = (((sec_r001623_9_1 * 3) + pub_r001623_18_1) + 3) & 127;
  int stage_v_181_2 = (((sec_r001623_9_2 * 3) + pub_r001623_18_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_181_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_181_2 * 2)) & 255;
  int stage_v_182_1 = (((stage_v_63_1 * 3) + pub_r001623_13_1) + 3) & 127;
  int stage_v_182_2 = (((stage_v_63_2 * 3) + pub_r001623_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_182_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_182_2 * 2)) & 255;
  int stage_v_183_1 = ((pub_r001623_14_1 * 2) + 28) & 63;
  int stage_v_183_2 = ((pub_r001623_14_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = (((stage_v_34_1 * 3) + pub_r001623_2_1) + 20) & 127;
  int stage_v_184_2 = (((stage_v_34_2 * 3) + pub_r001623_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_184_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_184_2 * 2)) & 255;
  int stage_v_185_1 = (((stage_v_169_1 * 3) + pub_r001623_19_1) + 31) & 127;
  int stage_v_185_2 = (((stage_v_169_2 * 3) + pub_r001623_19_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_185_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_185_2 * 2)) & 255;
  int stage_v_186_1 = ((pub_r001623_0_1 * 2) + 30) & 63;
  int stage_v_186_2 = ((pub_r001623_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_186_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_186_2) & 127;
  int stage_v_187_1 = (((stage_v_20_1 * 3) + pub_r001623_5_1) + 3) & 127;
  int stage_v_187_2 = (((stage_v_20_2 * 3) + pub_r001623_5_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = (((stage_v_66_1 * 3) + pub_r001623_0_1) + 26) & 127;
  int stage_v_188_2 = (((stage_v_66_2 * 3) + pub_r001623_0_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_188_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_188_2 * 2)) & 255;
  int stage_v_189_1 = ((pub_r001623_6_1 * 2) + 46) & 63;
  int stage_v_189_2 = ((pub_r001623_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = (((stage_v_99_1 * 3) + pub_r001623_5_1) + 38) & 127;
  int stage_v_190_2 = (((stage_v_99_2 * 3) + pub_r001623_5_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_190_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_190_2 * 2)) & 255;
  int stage_v_191_1 = ((pub_r001623_6_1 * 2) + 23) & 63;
  int stage_v_191_2 = ((pub_r001623_6_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_191_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_191_2) & 127;
  int stage_v_192_1 = ((pub_r001623_19_1 * 2) + 12) & 63;
  int stage_v_192_2 = ((pub_r001623_19_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_192_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_192_2) & 127;
  int stage_v_193_1 = (((stage_v_184_1 * 3) + pub_r001623_0_1) + 43) & 127;
  int stage_v_193_2 = (((stage_v_184_2 * 3) + pub_r001623_0_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_193_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_193_2 * 2)) & 255;
  int stage_v_194_1 = (((sec_r001623_16_1 * 3) + pub_r001623_8_1) + 16) & 127;
  int stage_v_194_2 = (((sec_r001623_16_2 * 3) + pub_r001623_8_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_194_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_194_2 * 2)) & 255;
  int stage_v_195_1 = ((pub_r001623_1_1 * 2) + 38) & 63;
  int stage_v_195_2 = ((pub_r001623_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001623_4_1 * 3) + pub_r001623_17_1) + 27) & 127;
  int stage_v_196_2 = (((sec_r001623_4_2 * 3) + pub_r001623_17_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001623_16_1 * 2) + 11) & 63;
  int stage_v_197_2 = ((pub_r001623_16_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = ((pub_r001623_13_1 * 2) + 26) & 63;
  int stage_v_198_2 = ((pub_r001623_13_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_198_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_198_2) & 127;
  int stage_v_199_1 = (((helper_flow_1_1 * 3) + pub_r001623_6_1) + 42) & 127;
  int stage_v_199_2 = (((helper_flow_1_2 * 3) + pub_r001623_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_199_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_199_2 * 2)) & 255;
  int stage_v_200_1 = ((pub_r001623_8_1 * 2) + 17) & 63;
  int stage_v_200_2 = ((pub_r001623_8_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = ((pub_r001623_14_1 * 2) + 8) & 63;
  int stage_v_201_2 = ((pub_r001623_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_201_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_201_2) & 127;
  int stage_v_202_1 = (((stage_v_187_1 * 3) + pub_r001623_6_1) + 42) & 127;
  int stage_v_202_2 = (((stage_v_187_2 * 3) + pub_r001623_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_202_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_202_2 * 2)) & 255;
  int stage_v_203_1 = (((stage_v_182_1 * 3) + pub_r001623_15_1) + 25) & 127;
  int stage_v_203_2 = (((stage_v_182_2 * 3) + pub_r001623_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_203_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_203_2 * 2)) & 255;
  int stage_v_204_1 = (((stage_v_202_1 * 3) + pub_r001623_10_1) + 44) & 127;
  int stage_v_204_2 = (((stage_v_202_2 * 3) + pub_r001623_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_204_1 * 3) + pub_r001623_6_1) + 42) & 127;
  int stage_v_205_2 = (((stage_v_204_2 * 3) + pub_r001623_6_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_84_1 * 3) + pub_r001623_19_1) + 39) & 127;
  int stage_v_206_2 = (((stage_v_84_2 * 3) + pub_r001623_19_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = ((pub_r001623_10_1 * 2) + 21) & 63;
  int stage_v_207_2 = ((pub_r001623_10_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_207_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_207_2) & 127;
  int stage_v_208_1 = ((pub_r001623_0_1 * 2) + 34) & 63;
  int stage_v_208_2 = ((pub_r001623_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = (((stage_v_172_1 * 3) + pub_r001623_7_1) + 40) & 127;
  int stage_v_209_2 = (((stage_v_172_2 * 3) + pub_r001623_7_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_209_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_209_2 * 2)) & 255;
  int stage_v_210_1 = (((stage_v_176_1 * 3) + pub_r001623_8_1) + 35) & 127;
  int stage_v_210_2 = (((stage_v_176_2 * 3) + pub_r001623_8_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_210_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_210_2 * 2)) & 255;
  int stage_v_211_1 = (((stage_v_63_1 * 3) + pub_r001623_10_1) + 44) & 127;
  int stage_v_211_2 = (((stage_v_63_2 * 3) + pub_r001623_10_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_211_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_211_2 * 2)) & 255;
  int stage_v_212_1 = ((pub_r001623_10_1 * 2) + 24) & 63;
  int stage_v_212_2 = ((pub_r001623_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_84_1 * 3) + pub_r001623_15_1) + 19) & 127;
  int stage_v_213_2 = (((stage_v_84_2 * 3) + pub_r001623_15_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = (((stage_v_75_1 * 3) + pub_r001623_2_1) + 38) & 127;
  int stage_v_214_2 = (((stage_v_75_2 * 3) + pub_r001623_2_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_214_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_214_2 * 2)) & 255;
  int stage_v_215_1 = ((pub_r001623_16_1 * 2) + 20) & 63;
  int stage_v_215_2 = ((pub_r001623_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_215_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_215_2) & 127;
  int stage_v_216_1 = ((pub_r001623_13_1 * 2) + 43) & 63;
  int stage_v_216_2 = ((pub_r001623_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_216_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_216_2) & 127;
  int stage_v_217_1 = ((pub_r001623_8_1 * 2) + 15) & 63;
  int stage_v_217_2 = ((pub_r001623_8_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_217_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_217_2) & 127;
  int stage_v_218_1 = ((pub_r001623_12_1 * 2) + 14) & 63;
  int stage_v_218_2 = ((pub_r001623_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = (((stage_v_57_1 * 3) + pub_r001623_16_1) + 23) & 127;
  int stage_v_219_2 = (((stage_v_57_2 * 3) + pub_r001623_16_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_219_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_219_2 * 2)) & 255;
  int stage_v_220_1 = (((sec_r001623_9_1 * 3) + pub_r001623_7_1) + 39) & 127;
  int stage_v_220_2 = (((sec_r001623_9_2 * 3) + pub_r001623_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = (((stage_v_177_1 * 3) + pub_r001623_12_1) + 8) & 127;
  int stage_v_221_2 = (((stage_v_177_2 * 3) + pub_r001623_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_221_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_221_2 * 2)) & 255;
  int stage_v_222_1 = (((stage_v_199_1 * 3) + pub_r001623_7_1) + 43) & 127;
  int stage_v_222_2 = (((stage_v_199_2 * 3) + pub_r001623_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001623_5_1 * 2) + 16) & 63;
  int stage_v_223_2 = ((pub_r001623_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = (((stage_v_29_1 * 3) + pub_r001623_7_1) + 23) & 127;
  int stage_v_224_2 = (((stage_v_29_2 * 3) + pub_r001623_7_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_224_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_224_2 * 2)) & 255;
  int stage_v_225_1 = ((pub_r001623_7_1 * 2) + 33) & 63;
  int stage_v_225_2 = ((pub_r001623_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_225_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_225_2) & 127;
  int stage_v_226_1 = ((pub_r001623_0_1 * 2) + 24) & 63;
  int stage_v_226_2 = ((pub_r001623_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_226_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_226_2) & 127;
  int stage_v_227_1 = (((stage_v_15_1 * 3) + pub_r001623_3_1) + 34) & 127;
  int stage_v_227_2 = (((stage_v_15_2 * 3) + pub_r001623_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = (((stage_v_108_1 * 3) + pub_r001623_12_1) + 30) & 127;
  int stage_v_228_2 = (((stage_v_108_2 * 3) + pub_r001623_12_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_228_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_228_2 * 2)) & 255;
  int stage_v_229_1 = ((pub_r001623_17_1 * 2) + 27) & 63;
  int stage_v_229_2 = ((pub_r001623_17_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_229_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_229_2) & 127;
  int stage_v_230_1 = ((pub_r001623_0_1 * 2) + 42) & 63;
  int stage_v_230_2 = ((pub_r001623_0_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((sec_r001623_16_1 * 3) + pub_r001623_11_1) + 42) & 127;
  int stage_v_231_2 = (((sec_r001623_16_2 * 3) + pub_r001623_11_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((stage_v_117_1 * 3) + pub_r001623_1_1) + 28) & 127;
  int stage_v_232_2 = (((stage_v_117_2 * 3) + pub_r001623_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = ((pub_r001623_0_1 * 2) + 6) & 63;
  int stage_v_233_2 = ((pub_r001623_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_233_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_233_2) & 127;
  int stage_v_234_1 = (((stage_v_143_1 * 3) + pub_r001623_16_1) + 44) & 127;
  int stage_v_234_2 = (((stage_v_143_2 * 3) + pub_r001623_16_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_234_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_234_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_234_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_234_2 * 2)) & 255;
  int stage_v_235_1 = (((stage_v_190_1 * 3) + pub_r001623_18_1) + 27) & 127;
  int stage_v_235_2 = (((stage_v_190_2 * 3) + pub_r001623_18_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_235_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_235_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_235_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_235_2 * 2)) & 255;
  int stage_v_236_1 = (((stage_v_36_1 * 3) + pub_r001623_10_1) + 10) & 127;
  int stage_v_236_2 = (((stage_v_36_2 * 3) + pub_r001623_10_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_236_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_236_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_236_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_236_2 * 2)) & 255;
  int stage_v_237_1 = ((pub_r001623_13_1 * 2) + 21) & 63;
  int stage_v_237_2 = ((pub_r001623_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001623_14_1 * 2) + 39) & 63;
  int stage_v_238_2 = ((pub_r001623_14_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001623_2_1 * 2) + 14) & 63;
  int stage_v_239_2 = ((pub_r001623_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = (((stage_v_193_1 * 3) + pub_r001623_3_1) + 30) & 127;
  int stage_v_240_2 = (((stage_v_193_2 * 3) + pub_r001623_3_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_240_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_240_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_240_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_240_2 * 2)) & 255;
  int stage_v_241_1 = (((stage_v_128_1 * 3) + pub_r001623_2_1) + 6) & 127;
  int stage_v_241_2 = (((stage_v_128_2 * 3) + pub_r001623_2_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = (((stage_v_131_1 * 3) + pub_r001623_2_1) + 17) & 127;
  int stage_v_242_2 = (((stage_v_131_2 * 3) + pub_r001623_2_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_242_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_242_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_242_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_242_2 * 2)) & 255;
  int stage_v_243_1 = (((stage_v_71_1 * 3) + pub_r001623_15_1) + 10) & 127;
  int stage_v_243_2 = (((stage_v_71_2 * 3) + pub_r001623_15_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_243_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_243_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_243_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_243_2 * 2)) & 255;
  int stage_v_244_1 = (((stage_v_65_1 * 3) + pub_r001623_17_1) + 7) & 127;
  int stage_v_244_2 = (((stage_v_65_2 * 3) + pub_r001623_17_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_244_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_244_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_244_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_244_2 * 2)) & 255;
  int stage_v_245_1 = (((stage_v_112_1 * 3) + pub_r001623_12_1) + 27) & 127;
  int stage_v_245_2 = (((stage_v_112_2 * 3) + pub_r001623_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_245_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_245_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_245_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_245_2 * 2)) & 255;
  int stage_v_246_1 = ((pub_r001623_5_1 * 2) + 6) & 63;
  int stage_v_246_2 = ((pub_r001623_5_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001623_9_1 * 2) + 33) & 63;
  int stage_v_247_2 = ((pub_r001623_9_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = (((stage_v_236_1 * 3) + pub_r001623_12_1) + 12) & 127;
  int stage_v_248_2 = (((stage_v_236_2 * 3) + pub_r001623_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_248_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_248_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_248_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_248_2 * 2)) & 255;
  int stage_v_249_1 = (((stage_v_40_1 * 3) + pub_r001623_3_1) + 32) & 127;
  int stage_v_249_2 = (((stage_v_40_2 * 3) + pub_r001623_3_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_249_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_249_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_249_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_249_2 * 2)) & 255;
  int stage_v_250_1 = ((pub_r001623_1_1 * 2) + 14) & 63;
  int stage_v_250_2 = ((pub_r001623_1_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_250_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_250_2) & 127;
  int stage_v_251_1 = (((stage_v_182_1 * 3) + pub_r001623_5_1) + 10) & 127;
  int stage_v_251_2 = (((stage_v_182_2 * 3) + pub_r001623_5_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_251_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_251_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_251_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_251_2 * 2)) & 255;
  int stage_v_252_1 = (((stage_v_179_1 * 3) + pub_r001623_9_1) + 23) & 127;
  int stage_v_252_2 = (((stage_v_179_2 * 3) + pub_r001623_9_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_252_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_252_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_252_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_252_2 * 2)) & 255;
  int stage_v_253_1 = (((stage_v_163_1 * 3) + pub_r001623_6_1) + 23) & 127;
  int stage_v_253_2 = (((stage_v_163_2 * 3) + pub_r001623_6_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_253_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_253_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_253_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_253_2 * 2)) & 255;
  int stage_v_254_1 = (((stage_v_236_1 * 3) + pub_r001623_15_1) + 40) & 127;
  int stage_v_254_2 = (((stage_v_236_2 * 3) + pub_r001623_15_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_254_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_254_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_254_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_254_2 * 2)) & 255;
  int stage_v_255_1 = ((pub_r001623_7_1 * 2) + 24) & 63;
  int stage_v_255_2 = ((pub_r001623_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001623_18_1 * 2) + 35) & 63;
  int stage_v_256_2 = ((pub_r001623_18_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = (((helper_flow_6_1 * 3) + pub_r001623_6_1) + 31) & 127;
  int stage_v_257_2 = (((helper_flow_6_2 * 3) + pub_r001623_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_257_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_257_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_257_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_257_2 * 2)) & 255;
  int stage_v_258_1 = ((pub_r001623_9_1 * 2) + 41) & 63;
  int stage_v_258_2 = ((pub_r001623_9_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001623_18_1 * 2) + 39) & 63;
  int stage_v_259_2 = ((pub_r001623_18_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = (((stage_v_98_1 * 3) + pub_r001623_0_1) + 8) & 127;
  int stage_v_260_2 = (((stage_v_98_2 * 3) + pub_r001623_0_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_260_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_260_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_260_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_260_2 * 2)) & 255;
  int stage_v_261_1 = (((stage_v_86_1 * 3) + pub_r001623_0_1) + 4) & 127;
  int stage_v_261_2 = (((stage_v_86_2 * 3) + pub_r001623_0_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_261_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_261_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_261_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_261_2 * 2)) & 255;
  int stage_v_262_1 = ((pub_r001623_12_1 * 2) + 34) & 63;
  int stage_v_262_2 = ((pub_r001623_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_58_1 * 3) + pub_r001623_5_1) + 42) & 127;
  int stage_v_263_2 = (((stage_v_58_2 * 3) + pub_r001623_5_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = (((stage_v_145_1 * 3) + pub_r001623_19_1) + 20) & 127;
  int stage_v_264_2 = (((stage_v_145_2 * 3) + pub_r001623_19_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_264_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_264_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_264_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_264_2 * 2)) & 255;
  int stage_v_265_1 = (((stage_v_142_1 * 3) + pub_r001623_16_1) + 36) & 127;
  int stage_v_265_2 = (((stage_v_142_2 * 3) + pub_r001623_16_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = ((pub_r001623_9_1 * 2) + 44) & 63;
  int stage_v_266_2 = ((pub_r001623_9_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_266_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_266_2) & 127;
  int stage_v_267_1 = ((pub_r001623_14_1 * 2) + 48) & 63;
  int stage_v_267_2 = ((pub_r001623_14_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_267_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_267_2) & 127;
  int stage_v_268_1 = (((stage_v_236_1 * 3) + pub_r001623_13_1) + 21) & 127;
  int stage_v_268_2 = (((stage_v_236_2 * 3) + pub_r001623_13_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_8_1 * 3) + pub_r001623_15_1) + 25) & 127;
  int stage_v_269_2 = (((stage_v_8_2 * 3) + pub_r001623_15_2) + 25) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001623_0_1 * 2) + 34) & 63;
  int stage_v_270_2 = ((pub_r001623_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = (((stage_v_172_1 * 3) + pub_r001623_12_1) + 27) & 127;
  int stage_v_271_2 = (((stage_v_172_2 * 3) + pub_r001623_12_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_271_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_271_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_271_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_271_2 * 2)) & 255;
  int stage_v_272_1 = ((pub_r001623_2_1 * 2) + 22) & 63;
  int stage_v_272_2 = ((pub_r001623_2_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_152_1 * 3) + pub_r001623_3_1) + 35) & 127;
  int stage_v_273_2 = (((stage_v_152_2 * 3) + pub_r001623_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = (((sec_r001623_9_1 * 3) + pub_r001623_2_1) + 11) & 127;
  int stage_v_274_2 = (((sec_r001623_9_2 * 3) + pub_r001623_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_274_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_274_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_274_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_274_2 * 2)) & 255;
  int stage_v_275_1 = ((pub_r001623_11_1 * 2) + 31) & 63;
  int stage_v_275_2 = ((pub_r001623_11_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001623_14_1 * 2) + 8) & 63;
  int stage_v_276_2 = ((pub_r001623_14_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = (((stage_v_157_1 * 3) + pub_r001623_3_1) + 33) & 127;
  int stage_v_277_2 = (((stage_v_157_2 * 3) + pub_r001623_3_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_277_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_277_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_277_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_277_2 * 2)) & 255;
  int stage_v_278_1 = (((stage_v_29_1 * 3) + pub_r001623_15_1) + 29) & 127;
  int stage_v_278_2 = (((stage_v_29_2 * 3) + pub_r001623_15_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = (((stage_v_235_1 * 3) + pub_r001623_6_1) + 6) & 127;
  int stage_v_279_2 = (((stage_v_235_2 * 3) + pub_r001623_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_279_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_279_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_279_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_279_2 * 2)) & 255;
  int stage_v_280_1 = (((stage_v_135_1 * 3) + pub_r001623_8_1) + 12) & 127;
  int stage_v_280_2 = (((stage_v_135_2 * 3) + pub_r001623_8_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = ((pub_r001623_11_1 * 2) + 24) & 63;
  int stage_v_281_2 = ((pub_r001623_11_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_281_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_281_2) & 127;
  int stage_v_282_1 = (((stage_v_148_1 * 3) + pub_r001623_11_1) + 40) & 127;
  int stage_v_282_2 = (((stage_v_148_2 * 3) + pub_r001623_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_282_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_282_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_282_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_282_2 * 2)) & 255;
  int stage_v_283_1 = (((sec_r001623_14_1 * 3) + pub_r001623_18_1) + 34) & 127;
  int stage_v_283_2 = (((sec_r001623_14_2 * 3) + pub_r001623_18_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = (((stage_v_268_1 * 3) + pub_r001623_13_1) + 4) & 127;
  int stage_v_284_2 = (((stage_v_268_2 * 3) + pub_r001623_13_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_284_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_284_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_284_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_284_2 * 2)) & 255;
  int stage_v_285_1 = ((pub_r001623_13_1 * 2) + 16) & 63;
  int stage_v_285_2 = ((pub_r001623_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001623_16_1 * 2) + 24) & 63;
  int stage_v_286_2 = ((pub_r001623_16_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_90_1 * 3) + pub_r001623_0_1) + 10) & 127;
  int stage_v_287_2 = (((stage_v_90_2 * 3) + pub_r001623_0_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001623_9_1 * 2) + 15) & 63;
  int stage_v_288_2 = ((pub_r001623_9_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = (((stage_v_282_1 * 3) + pub_r001623_8_1) + 7) & 127;
  int stage_v_289_2 = (((stage_v_282_2 * 3) + pub_r001623_8_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_289_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_289_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_289_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_289_2 * 2)) & 255;
  int stage_v_290_1 = ((pub_r001623_2_1 * 2) + 10) & 63;
  int stage_v_290_2 = ((pub_r001623_2_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = (((stage_v_121_1 * 3) + pub_r001623_16_1) + 39) & 127;
  int stage_v_291_2 = (((stage_v_121_2 * 3) + pub_r001623_16_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_291_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_291_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_291_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_291_2 * 2)) & 255;
  int stage_v_292_1 = (((stage_v_206_1 * 3) + pub_r001623_11_1) + 16) & 127;
  int stage_v_292_2 = (((stage_v_206_2 * 3) + pub_r001623_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_292_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_292_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_292_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_292_2 * 2)) & 255;
  int stage_v_293_1 = (((stage_v_273_1 * 3) + pub_r001623_0_1) + 6) & 127;
  int stage_v_293_2 = (((stage_v_273_2 * 3) + pub_r001623_0_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_293_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_293_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_293_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_293_2 * 2)) & 255;
  int stage_v_294_1 = ((pub_r001623_16_1 * 2) + 31) & 63;
  int stage_v_294_2 = ((pub_r001623_16_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_70_1 * 3) + pub_r001623_18_1) + 31) & 127;
  int stage_v_295_2 = (((stage_v_70_2 * 3) + pub_r001623_18_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = ((pub_r001623_10_1 * 2) + 41) & 63;
  int stage_v_296_2 = ((pub_r001623_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_296_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_296_2) & 127;
  int stage_v_297_1 = ((pub_r001623_11_1 * 2) + 46) & 63;
  int stage_v_297_2 = ((pub_r001623_11_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = (((stage_v_148_1 * 3) + pub_r001623_16_1) + 4) & 127;
  int stage_v_298_2 = (((stage_v_148_2 * 3) + pub_r001623_16_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_298_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_298_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_298_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_298_2 * 2)) & 255;
  int stage_v_299_1 = ((pub_r001623_1_1 * 2) + 24) & 63;
  int stage_v_299_2 = ((pub_r001623_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001623_7_1 * 2) + 22) & 63;
  int stage_v_300_2 = ((pub_r001623_7_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = ((pub_r001623_11_1 * 2) + 41) & 63;
  int stage_v_301_2 = ((pub_r001623_11_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_301_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_301_2) & 127;
  int stage_v_302_1 = (((stage_v_278_1 * 3) + pub_r001623_3_1) + 9) & 127;
  int stage_v_302_2 = (((stage_v_278_2 * 3) + pub_r001623_3_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_302_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_302_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_302_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_302_2 * 2)) & 255;
  int stage_v_303_1 = (((stage_v_163_1 * 3) + pub_r001623_6_1) + 13) & 127;
  int stage_v_303_2 = (((stage_v_163_2 * 3) + pub_r001623_6_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = ((pub_r001623_19_1 * 2) + 28) & 63;
  int stage_v_304_2 = ((pub_r001623_19_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_304_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_304_2) & 127;
  int stage_v_305_1 = (((stage_v_152_1 * 3) + pub_r001623_14_1) + 45) & 127;
  int stage_v_305_2 = (((stage_v_152_2 * 3) + pub_r001623_14_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_305_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_305_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_305_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_305_2 * 2)) & 255;
  int stage_v_306_1 = ((pub_r001623_5_1 * 2) + 12) & 63;
  int stage_v_306_2 = ((pub_r001623_5_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001623_1_1 * 2) + 47) & 63;
  int stage_v_307_2 = ((pub_r001623_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = ((pub_r001623_3_1 * 2) + 50) & 63;
  int stage_v_308_2 = ((pub_r001623_3_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_308_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_308_2) & 127;
  int stage_v_309_1 = (((stage_v_153_1 * 3) + pub_r001623_19_1) + 7) & 127;
  int stage_v_309_2 = (((stage_v_153_2 * 3) + pub_r001623_19_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_309_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_309_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_309_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_309_2 * 2)) & 255;
  int stage_v_310_1 = ((pub_r001623_5_1 * 2) + 27) & 63;
  int stage_v_310_2 = ((pub_r001623_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = ((pub_r001623_18_1 * 2) + 41) & 63;
  int stage_v_311_2 = ((pub_r001623_18_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_311_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_311_2) & 127;
  int stage_v_312_1 = (((stage_v_160_1 * 3) + pub_r001623_12_1) + 8) & 127;
  int stage_v_312_2 = (((stage_v_160_2 * 3) + pub_r001623_12_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001623_11_1 * 2) + 48) & 63;
  int stage_v_313_2 = ((pub_r001623_11_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_44_1 * 3) + pub_r001623_12_1) + 26) & 127;
  int stage_v_314_2 = (((stage_v_44_2 * 3) + pub_r001623_12_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_305_1 * 3) + pub_r001623_0_1) + 13) & 127;
  int stage_v_315_2 = (((stage_v_305_2 * 3) + pub_r001623_0_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = ((pub_r001623_6_1 * 2) + 6) & 63;
  int stage_v_316_2 = ((pub_r001623_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_316_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_316_2) & 127;
  int stage_v_317_1 = ((pub_r001623_3_1 * 2) + 5) & 63;
  int stage_v_317_2 = ((pub_r001623_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((sec_r001623_1_1 * 3) + pub_r001623_14_1) + 21) & 127;
  int stage_v_318_2 = (((sec_r001623_1_2 * 3) + pub_r001623_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = ((pub_r001623_14_1 * 2) + 46) & 63;
  int stage_v_319_2 = ((pub_r001623_14_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_319_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_319_2) & 127;
  int stage_v_320_1 = (((stage_v_16_1 * 3) + pub_r001623_7_1) + 39) & 127;
  int stage_v_320_2 = (((stage_v_16_2 * 3) + pub_r001623_7_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_320_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_320_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_320_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_320_2 * 2)) & 255;
  int stage_v_321_1 = ((pub_r001623_13_1 * 2) + 43) & 63;
  int stage_v_321_2 = ((pub_r001623_13_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001623_18_1 * 2) + 45) & 63;
  int stage_v_322_2 = ((pub_r001623_18_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = (((stage_v_117_1 * 3) + pub_r001623_1_1) + 14) & 127;
  int stage_v_323_2 = (((stage_v_117_2 * 3) + pub_r001623_1_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_323_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_323_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_323_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_323_2 * 2)) & 255;
  int stage_v_324_1 = (((stage_v_58_1 * 3) + pub_r001623_4_1) + 15) & 127;
  int stage_v_324_2 = (((stage_v_58_2 * 3) + pub_r001623_4_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_324_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_324_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_324_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_324_2 * 2)) & 255;
  int stage_v_325_1 = (((stage_v_126_1 * 3) + pub_r001623_12_1) + 37) & 127;
  int stage_v_325_2 = (((stage_v_126_2 * 3) + pub_r001623_12_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_325_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_325_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_325_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_325_2 * 2)) & 255;
  int stage_v_326_1 = ((pub_r001623_11_1 * 2) + 16) & 63;
  int stage_v_326_2 = ((pub_r001623_11_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = (((stage_v_13_1 * 3) + pub_r001623_17_1) + 22) & 127;
  int stage_v_327_2 = (((stage_v_13_2 * 3) + pub_r001623_17_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_327_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_327_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_327_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_327_2 * 2)) & 255;
  int stage_v_328_1 = (((stage_v_90_1 * 3) + pub_r001623_6_1) + 6) & 127;
  int stage_v_328_2 = (((stage_v_90_2 * 3) + pub_r001623_6_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_328_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_328_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_328_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_328_2 * 2)) & 255;
  int stage_v_329_1 = (((stage_v_166_1 * 3) + pub_r001623_9_1) + 16) & 127;
  int stage_v_329_2 = (((stage_v_166_2 * 3) + pub_r001623_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_329_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_329_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_329_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_329_2 * 2)) & 255;
  int stage_v_330_1 = (((stage_v_329_1 * 3) + pub_r001623_18_1) + 29) & 127;
  int stage_v_330_2 = (((stage_v_329_2 * 3) + pub_r001623_18_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_330_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_330_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_330_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_330_2 * 2)) & 255;
  int stage_v_331_1 = (((stage_v_254_1 * 3) + pub_r001623_3_1) + 40) & 127;
  int stage_v_331_2 = (((stage_v_254_2 * 3) + pub_r001623_3_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_331_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_331_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_331_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_331_2 * 2)) & 255;
  int stage_v_332_1 = ((pub_r001623_2_1 * 2) + 23) & 63;
  int stage_v_332_2 = ((pub_r001623_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_332_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_332_2) & 127;
  int stage_v_333_1 = ((pub_r001623_4_1 * 2) + 10) & 63;
  int stage_v_333_2 = ((pub_r001623_4_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_330_1 * 3) + pub_r001623_8_1) + 17) & 127;
  int stage_v_334_2 = (((stage_v_330_2 * 3) + pub_r001623_8_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((sec_r001623_6_1 * 3) + pub_r001623_11_1) + 19) & 127;
  int stage_v_335_2 = (((sec_r001623_6_2 * 3) + pub_r001623_11_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = ((pub_r001623_9_1 * 2) + 31) & 63;
  int stage_v_336_2 = ((pub_r001623_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_336_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_336_2) & 127;
  int stage_v_337_1 = ((pub_r001623_11_1 * 2) + 44) & 63;
  int stage_v_337_2 = ((pub_r001623_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = ((pub_r001623_10_1 * 2) + 32) & 63;
  int stage_v_338_2 = ((pub_r001623_10_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_338_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_338_2) & 127;
  int stage_v_339_1 = (((sec_r001623_16_1 * 3) + pub_r001623_9_1) + 42) & 127;
  int stage_v_339_2 = (((sec_r001623_16_2 * 3) + pub_r001623_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_339_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_339_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_339_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_339_2 * 2)) & 255;
  int stage_v_340_1 = (((stage_v_196_1 * 3) + pub_r001623_13_1) + 37) & 127;
  int stage_v_340_2 = (((stage_v_196_2 * 3) + pub_r001623_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_240_1 * 3) + pub_r001623_3_1) + 36) & 127;
  int stage_v_341_2 = (((stage_v_240_2 * 3) + pub_r001623_3_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = ((pub_r001623_14_1 * 2) + 18) & 63;
  int stage_v_342_2 = ((pub_r001623_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_342_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_342_2) & 127;
  int stage_v_343_1 = (((stage_v_188_1 * 3) + pub_r001623_17_1) + 15) & 127;
  int stage_v_343_2 = (((stage_v_188_2 * 3) + pub_r001623_17_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((sec_r001623_5_1 * 3) + pub_r001623_6_1) + 18) & 127;
  int stage_v_344_2 = (((sec_r001623_5_2 * 3) + pub_r001623_6_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001623_3_1 * 2) + 37) & 63;
  int stage_v_345_2 = ((pub_r001623_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = (((stage_v_175_1 * 3) + pub_r001623_13_1) + 37) & 127;
  int stage_v_346_2 = (((stage_v_175_2 * 3) + pub_r001623_13_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_346_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_346_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_346_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_346_2 * 2)) & 255;
  int stage_v_347_1 = ((pub_r001623_13_1 * 2) + 16) & 63;
  int stage_v_347_2 = ((pub_r001623_13_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_347_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_347_2) & 127;
  int stage_v_348_1 = (((stage_v_73_1 * 3) + pub_r001623_16_1) + 40) & 127;
  int stage_v_348_2 = (((stage_v_73_2 * 3) + pub_r001623_16_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_348_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_348_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_348_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_348_2 * 2)) & 255;
  int stage_v_349_1 = (((stage_v_0_1 * 3) + pub_r001623_15_1) + 24) & 127;
  int stage_v_349_2 = (((stage_v_0_2 * 3) + pub_r001623_15_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_58_1 * 3) + pub_r001623_4_1) + 37) & 127;
  int stage_v_350_2 = (((stage_v_58_2 * 3) + pub_r001623_4_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_110_1 * 3) + pub_r001623_5_1) + 35) & 127;
  int stage_v_351_2 = (((stage_v_110_2 * 3) + pub_r001623_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001623_17_1 * 2) + 43) & 63;
  int stage_v_352_2 = ((pub_r001623_17_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_118_1 * 3) + pub_r001623_10_1) + 41) & 127;
  int stage_v_353_2 = (((stage_v_118_2 * 3) + pub_r001623_10_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = (((helper_flow_3_1 * 3) + pub_r001623_19_1) + 21) & 127;
  int stage_v_354_2 = (((helper_flow_3_2 * 3) + pub_r001623_19_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_354_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_354_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_354_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_354_2 * 2)) & 255;
  int stage_v_355_1 = (((stage_v_177_1 * 3) + pub_r001623_10_1) + 30) & 127;
  int stage_v_355_2 = (((stage_v_177_2 * 3) + pub_r001623_10_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_355_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_355_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_355_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_355_2 * 2)) & 255;
  int stage_v_356_1 = ((pub_r001623_6_1 * 2) + 50) & 63;
  int stage_v_356_2 = ((pub_r001623_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_356_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_356_2) & 127;
  int stage_v_357_1 = (((helper_flow_7_1 * 3) + pub_r001623_7_1) + 37) & 127;
  int stage_v_357_2 = (((helper_flow_7_2 * 3) + pub_r001623_7_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_357_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_357_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_357_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_357_2 * 2)) & 255;
  int stage_v_358_1 = ((pub_r001623_9_1 * 2) + 8) & 63;
  int stage_v_358_2 = ((pub_r001623_9_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_358_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_358_2) & 127;
  int stage_v_359_1 = ((pub_r001623_19_1 * 2) + 29) & 63;
  int stage_v_359_2 = ((pub_r001623_19_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_359_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_359_2) & 127;
  int stage_v_360_1 = (((stage_v_335_1 * 3) + pub_r001623_15_1) + 18) & 127;
  int stage_v_360_2 = (((stage_v_335_2 * 3) + pub_r001623_15_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_32_1 * 3) + pub_r001623_7_1) + 28) & 127;
  int stage_v_361_2 = (((stage_v_32_2 * 3) + pub_r001623_7_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_160_1 * 3) + pub_r001623_16_1) + 11) & 127;
  int stage_v_362_2 = (((stage_v_160_2 * 3) + pub_r001623_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001623_4_1 * 2) + 5) & 63;
  int stage_v_363_2 = ((pub_r001623_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_257_1 * 3) + pub_r001623_4_1) + 9) & 127;
  int stage_v_364_2 = (((stage_v_257_2 * 3) + pub_r001623_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = ((pub_r001623_0_1 * 2) + 30) & 63;
  int stage_v_365_2 = ((pub_r001623_0_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_365_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_365_2) & 127;
  int stage_v_366_1 = (((stage_v_8_1 * 3) + pub_r001623_8_1) + 15) & 127;
  int stage_v_366_2 = (((stage_v_8_2 * 3) + pub_r001623_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_366_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_366_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_366_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_366_2 * 2)) & 255;
  int stage_v_367_1 = (((sec_r001623_4_1 * 3) + pub_r001623_6_1) + 24) & 127;
  int stage_v_367_2 = (((sec_r001623_4_2 * 3) + pub_r001623_6_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = (((stage_v_280_1 * 3) + pub_r001623_6_1) + 31) & 127;
  int stage_v_368_2 = (((stage_v_280_2 * 3) + pub_r001623_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_368_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_368_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_368_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_368_2 * 2)) & 255;
  int stage_v_369_1 = ((pub_r001623_1_1 * 2) + 12) & 63;
  int stage_v_369_2 = ((pub_r001623_1_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001623_12_1 * 2) + 8) & 63;
  int stage_v_370_2 = ((pub_r001623_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001623_1_1 * 2) + 47) & 63;
  int stage_v_371_2 = ((pub_r001623_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = (((stage_v_52_1 * 3) + pub_r001623_16_1) + 45) & 127;
  int stage_v_372_2 = (((stage_v_52_2 * 3) + pub_r001623_16_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_372_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_372_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_372_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_372_2 * 2)) & 255;
  int stage_v_373_1 = (((stage_v_271_1 * 3) + pub_r001623_4_1) + 11) & 127;
  int stage_v_373_2 = (((stage_v_271_2 * 3) + pub_r001623_4_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = (((stage_v_284_1 * 3) + pub_r001623_15_1) + 38) & 127;
  int stage_v_374_2 = (((stage_v_284_2 * 3) + pub_r001623_15_2) + 38) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_374_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_374_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_374_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_374_2 * 2)) & 255;
  int stage_v_375_1 = ((pub_r001623_2_1 * 2) + 21) & 63;
  int stage_v_375_2 = ((pub_r001623_2_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = ((pub_r001623_16_1 * 2) + 14) & 63;
  int stage_v_376_2 = ((pub_r001623_16_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_376_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_376_2) & 127;
  int stage_v_377_1 = ((pub_r001623_12_1 * 2) + 14) & 63;
  int stage_v_377_2 = ((pub_r001623_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001623_18_1 == pub_r001623_18_2);
  __CPROVER_assume(pub_r001623_9_1 == pub_r001623_9_2);
  __CPROVER_assume(sec_r001623_15_1 != sec_r001623_15_2);
  __CPROVER_assume(pub_r001623_3_1 == pub_r001623_3_2);
  __CPROVER_assume(sec_r001623_14_1 != sec_r001623_14_2);
  __CPROVER_assume(pub_r001623_19_1 == pub_r001623_19_2);
  __CPROVER_assume(sec_r001623_0_1 != sec_r001623_0_2);
  __CPROVER_assume(sec_r001623_10_1 != sec_r001623_10_2);
  __CPROVER_assume(pub_r001623_7_1 == pub_r001623_7_2);
  __CPROVER_assume(pub_r001623_16_1 == pub_r001623_16_2);
  __CPROVER_assume(sec_r001623_20_1 != sec_r001623_20_2);
  __CPROVER_assume(pub_r001623_15_1 == pub_r001623_15_2);
  __CPROVER_assume(pub_r001623_1_1 == pub_r001623_1_2);
  __CPROVER_assume(pub_r001623_8_1 == pub_r001623_8_2);
  __CPROVER_assume(pub_r001623_0_1 == pub_r001623_0_2);
  __CPROVER_assume(sec_r001623_17_1 != sec_r001623_17_2);
  __CPROVER_assume(pub_r001623_4_1 == pub_r001623_4_2);
  __CPROVER_assume(pub_r001623_5_1 == pub_r001623_5_2);
  __CPROVER_assume(sec_r001623_1_1 != sec_r001623_1_2);
  __CPROVER_assume(pub_r001623_13_1 == pub_r001623_13_2);
  __CPROVER_assume(sec_r001623_7_1 != sec_r001623_7_2);
  __CPROVER_assume(pub_r001623_12_1 == pub_r001623_12_2);
  __CPROVER_assume(sec_r001623_3_1 != sec_r001623_3_2);
  __CPROVER_assume(sec_r001623_13_1 != sec_r001623_13_2);
  __CPROVER_assume(sec_r001623_18_1 != sec_r001623_18_2);
  __CPROVER_assume(sec_r001623_9_1 != sec_r001623_9_2);
  __CPROVER_assume(sec_r001623_12_1 != sec_r001623_12_2);
  __CPROVER_assume(sec_r001623_19_1 != sec_r001623_19_2);
  __CPROVER_assume(pub_r001623_11_1 == pub_r001623_11_2);
  __CPROVER_assume(sec_r001623_6_1 != sec_r001623_6_2);
  __CPROVER_assume(pub_r001623_10_1 == pub_r001623_10_2);
  __CPROVER_assume(sec_r001623_11_1 != sec_r001623_11_2);
  __CPROVER_assume(pub_r001623_14_1 == pub_r001623_14_2);
  __CPROVER_assume(pub_r001623_17_1 == pub_r001623_17_2);
  __CPROVER_assume(pub_r001623_2_1 == pub_r001623_2_2);
  __CPROVER_assume(sec_r001623_16_1 != sec_r001623_16_2);
  __CPROVER_assume(sec_r001623_4_1 != sec_r001623_4_2);
  __CPROVER_assume(sec_r001623_2_1 != sec_r001623_2_2);
  __CPROVER_assume(sec_r001623_8_1 != sec_r001623_8_2);
  __CPROVER_assume(sec_r001623_5_1 != sec_r001623_5_2);
  __CPROVER_assume(pub_r001623_6_1 == pub_r001623_6_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.trace == st_var_0_2.trace);
  assert(st_var_0_1.scale == st_var_0_2.scale);
  assert(st_var_0_1.density == st_var_0_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain == st_var_1_2.gain);
  assert(st_var_1_1.calib == st_var_1_2.calib);
  assert(st_var_1_1.status == st_var_1_2.status);
  assert(st_var_1_1.reading == st_var_1_2.reading);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.pitch == st_var_2_2.pitch);
  assert(st_var_2_1.heading == st_var_2_2.heading);
  assert(st_var_2_1.norm_sq == st_var_2_2.norm_sq);
  assert(st_var_2_1.coord_y == st_var_2_2.coord_y);
  assert(st_var_2_1.coord_z == st_var_2_2.coord_z);
  assert(st_var_2_1.coord_x == st_var_2_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.rate == st_var_3_2.rate);
  assert(st_var_3_1.fee == st_var_3_2.fee);
  assert(st_var_3_1.status == st_var_3_2.status);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_3_1.buffer[i_buffer] == st_var_3_2.buffer[i_buffer]);
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
}


