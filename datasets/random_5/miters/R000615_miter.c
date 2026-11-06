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
struct Vector3D_R000615_1513_0
{
  short coord_z;
  int pitch;
  short norm_sq;
  int coord_y;
  int coord_x;
  int buffer[3];
};
struct FilterState_R000615_1513_1
{
  unsigned char gain_db;
  int prev_out;
  short mode;
  int damping;
  short prev_in;
  int cutoff;
  int buffer[3];
};
struct DeviceConfig_R000615_1513_2
{
  short baud_rate;
  int id;
  unsigned char stop_bits;
  unsigned char port;
  int parity;
  int buffer[3];
};
struct MatrixBlock_R000615_1513_3
{
  short scale;
  unsigned char determinant;
  unsigned char trace;
  int dim;
  unsigned char stride;
  int density;
  int buffer[3];
};
union TelemetryField_R000615_1513_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R000615_1513_1
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
void fn_R000615_1513_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_54_1 = local_arr_1[aux_1 % 3];
  int threshold_54_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_54_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_54_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_54_1 == threshold_54_2);
}

int fn_R000615_1513_0(int p0, int p1, int p2)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int threshold_54 = local_arr[aux % 3];
  acc = (acc + (threshold_54 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int window_43_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_43_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_43_1) & 63;
  aux_2 = (aux_2 + window_43_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int tracker_25_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_25_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_25_1)
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

  switch (tracker_25_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int checksum_68_1 = local_arr_1[aux_1 % 3];
  int checksum_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (checksum_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (checksum_68_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_43_1 == window_43_2);
  assert(tracker_25_1 == tracker_25_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(checksum_68_1 == checksum_68_2);
}

int fn_R000615_1513_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_43) & 63;
  acc ^= aux;
  int tracker_25 = (aux + st.buffer[1]) & 3;
  switch (tracker_25)
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

  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int checksum_68 = local_arr[aux % 3];
  acc = (acc + (checksum_68 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int damping_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_97_1) & 63;
  aux_2 = (aux_2 + damping_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int mask_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_82_1)
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

  switch (mask_82_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_97_1 == damping_97_2);
  assert(mask_82_1 == mask_82_2);
}

int fn_R000615_1513_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int damping_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_97) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int mask_82 = (aux + st.buffer[1]) & 3;
  switch (mask_82)
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

void fn_R000615_1513_3_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int pivot_20_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_20_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_20_1) & 63;
  aux_2 = (aux_2 + pivot_20_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int cursor_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_44_1 > 14)
  {
    acc_1 = ((acc_1 + (cursor_44_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_44_2 > 14)
  {
    acc_2 = ((acc_2 + (cursor_44_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_44_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_51_1 = local_arr_1[aux_1 % 3];
  int vector_51_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_51_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_51_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_20_1 == pivot_20_2);
  assert(cursor_44_1 == cursor_44_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_51_1 == vector_51_2);
}

int fn_R000615_1513_3(int p0, int p1, int p2)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int pivot_20 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_20) & 63;
  acc ^= aux;
  int cursor_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_44 > 14)
  {
    acc = ((acc + (cursor_44 * 2)) + 5) & 127;
    aux ^= cursor_44 & 15;
  }
  else
  {
    acc = ((acc - cursor_44) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int vector_51 = local_arr[aux % 3];
  acc = (acc + (vector_51 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_4_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int pivot_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int pivot_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (pivot_40_1 > 35)
  {
    acc_1 = ((acc_1 + (pivot_40_1 * 2)) + 5) & 127;
    aux_1 ^= pivot_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - pivot_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (pivot_40_2 > 35)
  {
    acc_2 = ((acc_2 + (pivot_40_2 * 2)) + 5) & 127;
    aux_2 ^= pivot_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - pivot_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_67_1)
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

  switch (damping_67_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_40_1 == pivot_40_2);
  assert(damping_67_1 == damping_67_2);
}

int fn_R000615_1513_4(int p0, int p1, int p2)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int pivot_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (pivot_40 > 35)
  {
    acc = ((acc + (pivot_40 * 2)) + 5) & 127;
    aux ^= pivot_40 & 15;
  }
  else
  {
    acc = ((acc - pivot_40) + 11) & 127;
    aux += 3;
  }
  int damping_67 = (aux + st.buffer[1]) & 3;
  switch (damping_67)
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

void fn_R000615_1513_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 39) & 127;
  int acc_2 = (p0_2 + 39) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int scale_95_1 = local_arr_1[aux_1 % 3];
  int scale_95_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (scale_95_1 * 2)) & 127;
  acc_2 = (acc_2 + (scale_95_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(scale_95_1 == scale_95_2);
}

int fn_R000615_1513_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 39) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int local_arr[3] = {4, 9, 15};
  int scale_95 = local_arr[aux % 3];
  acc = (acc + (scale_95 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int bound_29_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_29_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_29_1 > 31)
  {
    acc_1 = ((acc_1 + (bound_29_1 * 2)) + 5) & 127;
    aux_1 ^= bound_29_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_29_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_29_2 > 31)
  {
    acc_2 = ((acc_2 + (bound_29_2 * 2)) + 5) & 127;
    aux_2 ^= bound_29_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_29_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int tracker_56_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_56_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_56_1)
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

  switch (tracker_56_2)
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

  int margin_78_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int margin_78_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + margin_78_1) & 63;
  aux_2 = (aux_2 + margin_78_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_29_1 == bound_29_2);
  assert(tracker_56_1 == tracker_56_2);
  assert(margin_78_1 == margin_78_2);
}

int fn_R000615_1513_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int bound_29 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_29 > 31)
  {
    acc = ((acc + (bound_29 * 2)) + 5) & 127;
    aux ^= bound_29 & 15;
  }
  else
  {
    acc = ((acc - bound_29) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int tracker_56 = (aux + st.buffer[1]) & 3;
  switch (tracker_56)
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

  int margin_78 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + margin_78) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000615_1513_7_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_48_1 = local_arr_1[aux_1 % 3];
  int quantum_48_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_48_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_48_2 * 2)) & 127;
  int tracker_11_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int tracker_11_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (tracker_11_1 > 14)
  {
    acc_1 = ((acc_1 + (tracker_11_1 * 2)) + 5) & 127;
    aux_1 ^= tracker_11_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - tracker_11_1) + 11) & 127;
    aux_1 += 3;
  }
  if (tracker_11_2 > 14)
  {
    acc_2 = ((acc_2 + (tracker_11_2 * 2)) + 5) & 127;
    aux_2 ^= tracker_11_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - tracker_11_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int residue_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (residue_46_1)
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

  switch (residue_46_2)
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
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_48_1 == quantum_48_2);
  assert(tracker_11_1 == tracker_11_2);
  assert(residue_46_1 == residue_46_2);
}

int fn_R000615_1513_7(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int quantum_48 = local_arr[aux % 3];
  acc = (acc + (quantum_48 * 2)) & 127;
  int tracker_11 = ((st.buffer[0] * 3) + aux) & 63;
  if (tracker_11 > 14)
  {
    acc = ((acc + (tracker_11 * 2)) + 5) & 127;
    aux ^= tracker_11 & 15;
  }
  else
  {
    acc = ((acc - tracker_11) + 11) & 127;
    aux += 3;
  }
  int residue_46 = (aux + st.buffer[1]) & 3;
  switch (residue_46)
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

void fn_R000615_1513_8_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 48) & 127;
  int acc_2 = (p0_2 + 48) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_91_1 = local_arr_1[aux_1 % 3];
  int mask_91_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_91_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_91_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_91_1 == mask_91_2);
}

int fn_R000615_1513_8(int p0, int p1, int p2)
{
  int acc = (p0 + 48) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int mask_91 = local_arr[aux % 3];
  acc = (acc + (mask_91 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int phase_32_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_32_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_32_1)
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

  switch (phase_32_2)
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

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_16_1 = local_arr_1[aux_1 % 3];
  int threshold_16_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_16_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_16_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_32_1 == phase_32_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_16_1 == threshold_16_2);
}

int fn_R000615_1513_9(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int phase_32 = (aux + st.buffer[1]) & 3;
  switch (phase_32)
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

  int local_arr[3] = {4, 9, 15};
  int threshold_16 = local_arr[aux % 3];
  acc = (acc + (threshold_16 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int delta_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_49_1)
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

  switch (delta_49_2)
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
  int stride_75_1 = local_arr_1[aux_1 % 3];
  int stride_75_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_75_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_75_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_49_1 == delta_49_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_75_1 == stride_75_2);
}

int fn_R000615_1513_10(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int delta_49 = (aux + st.buffer[1]) & 3;
  switch (delta_49)
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
  int stride_75 = local_arr[aux % 3];
  acc = (acc + (stride_75 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_11_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 19) & 127;
  int acc_2 = (p0_2 + 19) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int delta_90_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_90_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_90_1 > 48)
  {
    acc_1 = ((acc_1 + (delta_90_1 * 2)) + 5) & 127;
    aux_1 ^= delta_90_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_90_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_90_2 > 48)
  {
    acc_2 = ((acc_2 + (delta_90_2 * 2)) + 5) & 127;
    aux_2 ^= delta_90_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_90_2) + 11) & 127;
    aux_2 += 3;
  }
  int damping_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_61_1)
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

  switch (damping_61_2)
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

  int residue_19_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_19_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_19_1) & 63;
  aux_2 = (aux_2 + residue_19_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_90_1 == delta_90_2);
  assert(damping_61_1 == damping_61_2);
  assert(residue_19_1 == residue_19_2);
}

int fn_R000615_1513_11(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 19) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int delta_90 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_90 > 48)
  {
    acc = ((acc + (delta_90 * 2)) + 5) & 127;
    aux ^= delta_90 & 15;
  }
  else
  {
    acc = ((acc - delta_90) + 11) & 127;
    aux += 3;
  }
  int damping_61 = (aux + st.buffer[1]) & 3;
  switch (damping_61)
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

  int residue_19 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_19) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000615_1513_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 10) & 127;
  int acc_2 = (p0_2 + 10) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st_1 = {0};
  struct FilterState_R000615_1513_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int metric_69_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_69_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_69_1 > 28)
  {
    acc_1 = ((acc_1 + (metric_69_1 * 2)) + 5) & 127;
    aux_1 ^= metric_69_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_69_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_69_2 > 28)
  {
    acc_2 = ((acc_2 + (metric_69_2 * 2)) + 5) & 127;
    aux_2 ^= metric_69_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_69_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int accumulator_21_1 = local_arr_1[aux_1 % 3];
  int accumulator_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (accumulator_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (accumulator_21_2 * 2)) & 127;
  int tracker_88_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int tracker_88_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + tracker_88_1) & 63;
  aux_2 = (aux_2 + tracker_88_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.mode == st_2.mode);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.cutoff == st_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_69_1 == metric_69_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(accumulator_21_1 == accumulator_21_2);
  assert(tracker_88_1 == tracker_88_2);
}

int fn_R000615_1513_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 10) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000615_1513_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int metric_69 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_69 > 28)
  {
    acc = ((acc + (metric_69 * 2)) + 5) & 127;
    aux ^= metric_69 & 15;
  }
  else
  {
    acc = ((acc - metric_69) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int accumulator_21 = local_arr[aux % 3];
  acc = (acc + (accumulator_21 * 2)) & 127;
  int tracker_88 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + tracker_88) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000615_1513_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 24) & 127;
  int acc_2 = (p0_2 + 24) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct DeviceConfig_R000615_1513_2 st_1 = {0};
  struct DeviceConfig_R000615_1513_2 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int metric_65_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_65_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_65_1 > 27)
  {
    acc_1 = ((acc_1 + (metric_65_1 * 2)) + 5) & 127;
    aux_1 ^= metric_65_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_65_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_65_2 > 27)
  {
    acc_2 = ((acc_2 + (metric_65_2 * 2)) + 5) & 127;
    aux_2 ^= metric_65_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_65_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.baud_rate == st_2.baud_rate);
  assert(st_1.id == st_2.id);
  assert(st_1.stop_bits == st_2.stop_bits);
  assert(st_1.port == st_2.port);
  assert(st_1.parity == st_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_65_1 == metric_65_2);
}

int fn_R000615_1513_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 24) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct DeviceConfig_R000615_1513_2 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int metric_65 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_65 > 27)
  {
    acc = ((acc + (metric_65 * 2)) + 5) & 127;
    aux ^= metric_65 & 15;
  }
  else
  {
    acc = ((acc - metric_65) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int stride_64_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int stride_64_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (stride_64_1 > 18)
  {
    acc_1 = ((acc_1 + (stride_64_1 * 2)) + 5) & 127;
    aux_1 ^= stride_64_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - stride_64_1) + 11) & 127;
    aux_1 += 3;
  }
  if (stride_64_2 > 18)
  {
    acc_2 = ((acc_2 + (stride_64_2 * 2)) + 5) & 127;
    aux_2 ^= stride_64_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - stride_64_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_66_1 = local_arr_1[aux_1 % 3];
  int cursor_66_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_66_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_66_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(stride_64_1 == stride_64_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_66_1 == cursor_66_2);
}

int fn_R000615_1513_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int stride_64 = ((st.buffer[0] * 3) + aux) & 63;
  if (stride_64 > 18)
  {
    acc = ((acc + (stride_64 * 2)) + 5) & 127;
    aux ^= stride_64 & 15;
  }
  else
  {
    acc = ((acc - stride_64) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int cursor_66 = local_arr[aux % 3];
  acc = (acc + (cursor_66 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 31) & 127;
  int acc_2 = (p0_2 + 31) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int threshold_36_1 = local_arr_1[aux_1 % 3];
  int threshold_36_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (threshold_36_1 * 2)) & 127;
  acc_2 = (acc_2 + (threshold_36_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_60_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_60_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_60_1 > 16)
  {
    acc_1 = ((acc_1 + (window_60_1 * 2)) + 5) & 127;
    aux_1 ^= window_60_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_60_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_60_2 > 16)
  {
    acc_2 = ((acc_2 + (window_60_2 * 2)) + 5) & 127;
    aux_2 ^= window_60_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_60_2) + 11) & 127;
    aux_2 += 3;
  }
  int tracker_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_35_1)
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

  switch (tracker_35_2)
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
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(threshold_36_1 == threshold_36_2);
  assert(window_60_1 == window_60_2);
  assert(tracker_35_1 == tracker_35_2);
}

int fn_R000615_1513_15(int p0, int p1, int p2)
{
  int acc = (p0 + 31) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int threshold_36 = local_arr[aux % 3];
  acc = (acc + (threshold_36 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_60 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_60 > 16)
  {
    acc = ((acc + (window_60 * 2)) + 5) & 127;
    aux ^= window_60 & 15;
  }
  else
  {
    acc = ((acc - window_60) + 11) & 127;
    aux += 3;
  }
  int tracker_35 = (aux + st.buffer[1]) & 3;
  switch (tracker_35)
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

void fn_R000615_1513_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 12;
  st_2.buffer[2] = 12;
  int residue_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_37_1 > 40)
  {
    acc_1 = ((acc_1 + (residue_37_1 * 2)) + 5) & 127;
    aux_1 ^= residue_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_37_2 > 40)
  {
    acc_2 = ((acc_2 + (residue_37_2 * 2)) + 5) & 127;
    aux_2 ^= residue_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_37_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_69_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int damping_69_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + damping_69_1) & 63;
  aux_2 = (aux_2 + damping_69_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_37_1 == residue_37_2);
  assert(damping_69_1 == damping_69_2);
}

int fn_R000615_1513_16(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 12;
  int residue_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_37 > 40)
  {
    acc = ((acc + (residue_37 * 2)) + 5) & 127;
    aux ^= residue_37 & 15;
  }
  else
  {
    acc = ((acc - residue_37) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_69 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + damping_69) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000615_1513_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int margin_77_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_77_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_77_1)
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

  switch (margin_77_2)
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

  int quotient_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_57_1 > 30)
  {
    acc_1 = ((acc_1 + (quotient_57_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_57_2 > 30)
  {
    acc_2 = ((acc_2 + (quotient_57_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_77_1 = local_arr_1[aux_1 % 3];
  int sample_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_77_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_77_1 == margin_77_2);
  assert(quotient_57_1 == quotient_57_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_77_1 == sample_77_2);
}

int fn_R000615_1513_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int margin_77 = (aux + st.buffer[1]) & 3;
  switch (margin_77)
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

  int quotient_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_57 > 30)
  {
    acc = ((acc + (quotient_57 * 2)) + 5) & 127;
    aux ^= quotient_57 & 15;
  }
  else
  {
    acc = ((acc - quotient_57) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int sample_77 = local_arr[aux % 3];
  acc = (acc + (sample_77 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_18_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_14_1 = local_arr_1[aux_1 % 3];
  int quantum_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_14_2 * 2)) & 127;
  int parity_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_57_1 > 24)
  {
    acc_1 = ((acc_1 + (parity_57_1 * 2)) + 5) & 127;
    aux_1 ^= parity_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_57_2 > 24)
  {
    acc_2 = ((acc_2 + (parity_57_2 * 2)) + 5) & 127;
    aux_2 ^= parity_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_57_2) + 11) & 127;
    aux_2 += 3;
  }
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int weight_10_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_10_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_10_1)
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

  switch (weight_10_2)
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
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_14_1 == quantum_14_2);
  assert(parity_57_1 == parity_57_2);
  assert(weight_10_1 == weight_10_2);
}

int fn_R000615_1513_18(int p0, int p1, int p2)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int quantum_14 = local_arr[aux % 3];
  acc = (acc + (quantum_14 * 2)) & 127;
  int parity_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_57 > 24)
  {
    acc = ((acc + (parity_57 * 2)) + 5) & 127;
    aux ^= parity_57 & 15;
  }
  else
  {
    acc = ((acc - parity_57) + 11) & 127;
    aux += 3;
  }
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int weight_10 = (aux + st.buffer[1]) & 3;
  switch (weight_10)
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

void fn_R000615_1513_19_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_29_1 = local_arr_1[aux_1 % 3];
  int phase_29_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_29_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_29_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int checksum_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_21_1 > 23)
  {
    acc_1 = ((acc_1 + (checksum_21_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_21_2 > 23)
  {
    acc_2 = ((acc_2 + (checksum_21_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_21_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_21_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_29_1 == phase_29_2);
  assert(checksum_21_1 == checksum_21_2);
}

int fn_R000615_1513_19(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int phase_29 = local_arr[aux % 3];
  acc = (acc + (phase_29 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int checksum_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_21 > 23)
  {
    acc = ((acc + (checksum_21 * 2)) + 5) & 127;
    aux ^= checksum_21 & 15;
  }
  else
  {
    acc = ((acc - checksum_21) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000615_1513_20_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int quotient_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quotient_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quotient_54_1)
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

  switch (quotient_54_2)
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

  int cursor_40_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_40_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_40_1 > 11)
  {
    acc_1 = ((acc_1 + (cursor_40_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_40_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_40_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_40_2 > 11)
  {
    acc_2 = ((acc_2 + (cursor_40_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_40_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_40_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_79_1 = local_arr_1[aux_1 % 3];
  int stride_79_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_79_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_79_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_54_1 == quotient_54_2);
  assert(cursor_40_1 == cursor_40_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_79_1 == stride_79_2);
}

int fn_R000615_1513_20(int p0, int p1)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int quotient_54 = (aux + st.buffer[1]) & 3;
  switch (quotient_54)
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

  int cursor_40 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_40 > 11)
  {
    acc = ((acc + (cursor_40 * 2)) + 5) & 127;
    aux ^= cursor_40 & 15;
  }
  else
  {
    acc = ((acc - cursor_40) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_79 = local_arr[aux % 3];
  acc = (acc + (stride_79 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_21_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 45) & 127;
  int acc_2 = (p0_2 + 45) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int vector_62_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_62_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_62_1) & 63;
  aux_2 = (aux_2 + vector_62_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int phase_72_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_72_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_72_1)
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

  switch (phase_72_2)
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
  int mask_73_1 = local_arr_1[aux_1 % 3];
  int mask_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_73_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 1) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 1) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.scale == st_2.scale);
  assert(st_1.determinant == st_2.determinant);
  assert(st_1.trace == st_2.trace);
  assert(st_1.dim == st_2.dim);
  assert(st_1.stride == st_2.stride);
  assert(st_1.density == st_2.density);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_62_1 == vector_62_2);
  assert(phase_72_1 == phase_72_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_73_1 == mask_73_2);
}

int fn_R000615_1513_21(int p0, int p1, int p2)
{
  int acc = (p0 + 45) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct MatrixBlock_R000615_1513_3 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int vector_62 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_62) & 63;
  acc ^= aux;
  int phase_72 = (aux + st.buffer[1]) & 3;
  switch (phase_72)
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
  int mask_73 = local_arr[aux % 3];
  acc = (acc + (mask_73 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 1) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000615_1513_22_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st_1 = {0};
  struct Vector3D_R000615_1513_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int margin_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_20_1)
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

  switch (margin_20_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(margin_20_1 == margin_20_2);
}

int fn_R000615_1513_22(int p0, int p1)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000615_1513_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int margin_20 = (aux + st.buffer[1]) & 3;
  switch (margin_20)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000615_0_1;
  int sec_r000615_0_2;
  int sec_r000615_1_1;
  int sec_r000615_1_2;
  int sec_r000615_2_1;
  int sec_r000615_2_2;
  int sec_r000615_3_1;
  int sec_r000615_3_2;
  int sec_r000615_4_1;
  int sec_r000615_4_2;
  int sec_r000615_5_1;
  int sec_r000615_5_2;
  int sec_r000615_6_1;
  int sec_r000615_6_2;
  int sec_r000615_7_1;
  int sec_r000615_7_2;
  int sec_r000615_8_1;
  int sec_r000615_8_2;
  int sec_r000615_9_1;
  int sec_r000615_9_2;
  int sec_r000615_10_1;
  int sec_r000615_10_2;
  int sec_r000615_11_1;
  int sec_r000615_11_2;
  int sec_r000615_12_1;
  int sec_r000615_12_2;
  int sec_r000615_13_1;
  int sec_r000615_13_2;
  int sec_r000615_14_1;
  int sec_r000615_14_2;
  int sec_r000615_15_1;
  int sec_r000615_15_2;
  int sec_r000615_16_1;
  int sec_r000615_16_2;
  int sec_r000615_17_1;
  int sec_r000615_17_2;
  int sec_r000615_18_1;
  int sec_r000615_18_2;
  int pub_r000615_0_1;
  int pub_r000615_0_2;
  int pub_r000615_1_1;
  int pub_r000615_1_2;
  int pub_r000615_2_1;
  int pub_r000615_2_2;
  int pub_r000615_3_1;
  int pub_r000615_3_2;
  int pub_r000615_4_1;
  int pub_r000615_4_2;
  int pub_r000615_5_1;
  int pub_r000615_5_2;
  int pub_r000615_6_1;
  int pub_r000615_6_2;
  int pub_r000615_7_1;
  int pub_r000615_7_2;
  int pub_r000615_8_1;
  int pub_r000615_8_2;
  int pub_r000615_9_1;
  int pub_r000615_9_2;
  int pub_r000615_10_1;
  int pub_r000615_10_2;
  int pub_r000615_11_1;
  int pub_r000615_11_2;
  int pub_r000615_12_1;
  int pub_r000615_12_2;
  int pub_r000615_13_1;
  int pub_r000615_13_2;
  int pub_r000615_14_1;
  int pub_r000615_14_2;
  int pub_r000615_15_1;
  int pub_r000615_15_2;
  int pub_r000615_16_1;
  int pub_r000615_16_2;
  int pub_r000615_17_1;
  int pub_r000615_17_2;
  int pub_r000615_18_1;
  int pub_r000615_18_2;
  int pub_r000615_19_1;
  int pub_r000615_19_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000615_0_1 >= (-100)) && (pub_r000615_0_1 <= 100));
  __CPROVER_assume((pub_r000615_0_2 >= (-100)) && (pub_r000615_0_2 <= 100));
  __CPROVER_assume((pub_r000615_1_1 >= (-100)) && (pub_r000615_1_1 <= 100));
  __CPROVER_assume((pub_r000615_1_2 >= (-100)) && (pub_r000615_1_2 <= 100));
  __CPROVER_assume((pub_r000615_2_1 >= (-100)) && (pub_r000615_2_1 <= 100));
  __CPROVER_assume((pub_r000615_2_2 >= (-100)) && (pub_r000615_2_2 <= 100));
  __CPROVER_assume((pub_r000615_3_1 >= (-100)) && (pub_r000615_3_1 <= 100));
  __CPROVER_assume((pub_r000615_3_2 >= (-100)) && (pub_r000615_3_2 <= 100));
  __CPROVER_assume((pub_r000615_4_1 >= (-100)) && (pub_r000615_4_1 <= 100));
  __CPROVER_assume((pub_r000615_4_2 >= (-100)) && (pub_r000615_4_2 <= 100));
  __CPROVER_assume((pub_r000615_5_1 >= (-100)) && (pub_r000615_5_1 <= 100));
  __CPROVER_assume((pub_r000615_5_2 >= (-100)) && (pub_r000615_5_2 <= 100));
  __CPROVER_assume((pub_r000615_6_1 >= (-100)) && (pub_r000615_6_1 <= 100));
  __CPROVER_assume((pub_r000615_6_2 >= (-100)) && (pub_r000615_6_2 <= 100));
  __CPROVER_assume((pub_r000615_7_1 >= (-100)) && (pub_r000615_7_1 <= 100));
  __CPROVER_assume((pub_r000615_7_2 >= (-100)) && (pub_r000615_7_2 <= 100));
  __CPROVER_assume((pub_r000615_8_1 >= (-100)) && (pub_r000615_8_1 <= 100));
  __CPROVER_assume((pub_r000615_8_2 >= (-100)) && (pub_r000615_8_2 <= 100));
  __CPROVER_assume((pub_r000615_9_1 >= (-100)) && (pub_r000615_9_1 <= 100));
  __CPROVER_assume((pub_r000615_9_2 >= (-100)) && (pub_r000615_9_2 <= 100));
  __CPROVER_assume((pub_r000615_10_1 >= (-100)) && (pub_r000615_10_1 <= 100));
  __CPROVER_assume((pub_r000615_10_2 >= (-100)) && (pub_r000615_10_2 <= 100));
  __CPROVER_assume((pub_r000615_11_1 >= (-100)) && (pub_r000615_11_1 <= 100));
  __CPROVER_assume((pub_r000615_11_2 >= (-100)) && (pub_r000615_11_2 <= 100));
  __CPROVER_assume((pub_r000615_12_1 >= (-100)) && (pub_r000615_12_1 <= 100));
  __CPROVER_assume((pub_r000615_12_2 >= (-100)) && (pub_r000615_12_2 <= 100));
  __CPROVER_assume((pub_r000615_13_1 >= (-100)) && (pub_r000615_13_1 <= 100));
  __CPROVER_assume((pub_r000615_13_2 >= (-100)) && (pub_r000615_13_2 <= 100));
  __CPROVER_assume((pub_r000615_14_1 >= (-100)) && (pub_r000615_14_1 <= 100));
  __CPROVER_assume((pub_r000615_14_2 >= (-100)) && (pub_r000615_14_2 <= 100));
  __CPROVER_assume((pub_r000615_15_1 >= (-100)) && (pub_r000615_15_1 <= 100));
  __CPROVER_assume((pub_r000615_15_2 >= (-100)) && (pub_r000615_15_2 <= 100));
  __CPROVER_assume((pub_r000615_16_1 >= (-100)) && (pub_r000615_16_1 <= 100));
  __CPROVER_assume((pub_r000615_16_2 >= (-100)) && (pub_r000615_16_2 <= 100));
  __CPROVER_assume((pub_r000615_17_1 >= (-100)) && (pub_r000615_17_1 <= 100));
  __CPROVER_assume((pub_r000615_17_2 >= (-100)) && (pub_r000615_17_2 <= 100));
  __CPROVER_assume((pub_r000615_18_1 >= (-100)) && (pub_r000615_18_1 <= 100));
  __CPROVER_assume((pub_r000615_18_2 >= (-100)) && (pub_r000615_18_2 <= 100));
  __CPROVER_assume((pub_r000615_19_1 >= (-100)) && (pub_r000615_19_1 <= 100));
  __CPROVER_assume((pub_r000615_19_2 >= (-100)) && (pub_r000615_19_2 <= 100));
  __CPROVER_assume((sec_r000615_0_1 >= 0) && (sec_r000615_0_1 <= 255));
  __CPROVER_assume((sec_r000615_0_2 >= 0) && (sec_r000615_0_2 <= 255));
  __CPROVER_assume((sec_r000615_1_1 >= 0) && (sec_r000615_1_1 <= 255));
  __CPROVER_assume((sec_r000615_1_2 >= 0) && (sec_r000615_1_2 <= 255));
  __CPROVER_assume((sec_r000615_2_1 >= 0) && (sec_r000615_2_1 <= 255));
  __CPROVER_assume((sec_r000615_2_2 >= 0) && (sec_r000615_2_2 <= 255));
  __CPROVER_assume((sec_r000615_3_1 >= 0) && (sec_r000615_3_1 <= 255));
  __CPROVER_assume((sec_r000615_3_2 >= 0) && (sec_r000615_3_2 <= 255));
  __CPROVER_assume((sec_r000615_4_1 >= 0) && (sec_r000615_4_1 <= 255));
  __CPROVER_assume((sec_r000615_4_2 >= 0) && (sec_r000615_4_2 <= 255));
  __CPROVER_assume((sec_r000615_5_1 >= 0) && (sec_r000615_5_1 <= 255));
  __CPROVER_assume((sec_r000615_5_2 >= 0) && (sec_r000615_5_2 <= 255));
  __CPROVER_assume((sec_r000615_6_1 >= 0) && (sec_r000615_6_1 <= 255));
  __CPROVER_assume((sec_r000615_6_2 >= 0) && (sec_r000615_6_2 <= 255));
  __CPROVER_assume((sec_r000615_7_1 >= 0) && (sec_r000615_7_1 <= 255));
  __CPROVER_assume((sec_r000615_7_2 >= 0) && (sec_r000615_7_2 <= 255));
  __CPROVER_assume((sec_r000615_8_1 >= 0) && (sec_r000615_8_1 <= 255));
  __CPROVER_assume((sec_r000615_8_2 >= 0) && (sec_r000615_8_2 <= 255));
  __CPROVER_assume((sec_r000615_9_1 >= 0) && (sec_r000615_9_1 <= 255));
  __CPROVER_assume((sec_r000615_9_2 >= 0) && (sec_r000615_9_2 <= 255));
  __CPROVER_assume((sec_r000615_10_1 >= 0) && (sec_r000615_10_1 <= 255));
  __CPROVER_assume((sec_r000615_10_2 >= 0) && (sec_r000615_10_2 <= 255));
  __CPROVER_assume((sec_r000615_11_1 >= 0) && (sec_r000615_11_1 <= 255));
  __CPROVER_assume((sec_r000615_11_2 >= 0) && (sec_r000615_11_2 <= 255));
  __CPROVER_assume((sec_r000615_12_1 >= 0) && (sec_r000615_12_1 <= 255));
  __CPROVER_assume((sec_r000615_12_2 >= 0) && (sec_r000615_12_2 <= 255));
  __CPROVER_assume((sec_r000615_13_1 >= 0) && (sec_r000615_13_1 <= 255));
  __CPROVER_assume((sec_r000615_13_2 >= 0) && (sec_r000615_13_2 <= 255));
  __CPROVER_assume((sec_r000615_14_1 >= 0) && (sec_r000615_14_1 <= 255));
  __CPROVER_assume((sec_r000615_14_2 >= 0) && (sec_r000615_14_2 <= 255));
  __CPROVER_assume((sec_r000615_15_1 >= 0) && (sec_r000615_15_1 <= 255));
  __CPROVER_assume((sec_r000615_15_2 >= 0) && (sec_r000615_15_2 <= 255));
  __CPROVER_assume((sec_r000615_16_1 >= 0) && (sec_r000615_16_1 <= 255));
  __CPROVER_assume((sec_r000615_16_2 >= 0) && (sec_r000615_16_2 <= 255));
  __CPROVER_assume((sec_r000615_17_1 >= 0) && (sec_r000615_17_1 <= 255));
  __CPROVER_assume((sec_r000615_17_2 >= 0) && (sec_r000615_17_2 <= 255));
  __CPROVER_assume((sec_r000615_18_1 >= 0) && (sec_r000615_18_1 <= 255));
  __CPROVER_assume((sec_r000615_18_2 >= 0) && (sec_r000615_18_2 <= 255));
  struct Vector3D_R000615_1513_0 st_var_0_1 = {0};
  struct Vector3D_R000615_1513_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000615_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000615_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000615_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000615_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000615_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000615_0_2 + 7) & 15;
  struct FilterState_R000615_1513_1 st_var_1_1 = {0};
  struct FilterState_R000615_1513_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000615_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000615_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000615_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000615_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000615_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000615_0_2 + 9) & 15;
  struct DeviceConfig_R000615_1513_2 st_var_2_1 = {0};
  struct DeviceConfig_R000615_1513_2 st_var_2_2 = {0};
  st_var_2_1.buffer[0] = (pub_r000615_0_1 + 7) & 15;
  st_var_2_2.buffer[0] = (pub_r000615_0_2 + 7) & 15;
  st_var_2_1.buffer[1] = (pub_r000615_0_1 + 14) & 15;
  st_var_2_2.buffer[1] = (pub_r000615_0_2 + 14) & 15;
  st_var_2_1.buffer[2] = (pub_r000615_0_1 + 11) & 15;
  st_var_2_2.buffer[2] = (pub_r000615_0_2 + 11) & 15;
  struct MatrixBlock_R000615_1513_3 st_var_3_1 = {0};
  struct MatrixBlock_R000615_1513_3 st_var_3_2 = {0};
  st_var_3_1.buffer[0] = (pub_r000615_0_1 + 10) & 15;
  st_var_3_2.buffer[0] = (pub_r000615_0_2 + 10) & 15;
  st_var_3_1.buffer[1] = (pub_r000615_0_1 + 19) & 15;
  st_var_3_2.buffer[1] = (pub_r000615_0_2 + 19) & 15;
  st_var_3_1.buffer[2] = (pub_r000615_0_1 + 13) & 15;
  st_var_3_2.buffer[2] = (pub_r000615_0_2 + 13) & 15;
  union TelemetryField_R000615_1513_0 u_var_1;
  union TelemetryField_R000615_1513_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = ((st_var_0_1.buffer[0] * 2) + 7) & 63;
  int stage_v_0_2 = ((st_var_0_2.buffer[0] * 2) + 7) & 63;
  if (stage_v_0_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_0_1) - 5) & 255;
    if (stage_v_0_1 > 50)
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
  if (stage_v_0_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_0_2) - 5) & 255;
    if (stage_v_0_2 > 50)
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
  int stage_v_1_1 = ((st_var_1_1.buffer[1] * 2) + 10) & 63;
  int stage_v_1_2 = ((st_var_1_2.buffer[1] * 2) + 10) & 63;
  if (stage_v_1_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + stage_v_1_1) - 5) & 255;
    if (stage_v_1_1 > 41)
    {
      chk_sum_1 ^= stage_v_1_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_1_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + stage_v_1_2) - 5) & 255;
    if (stage_v_1_2 > 41)
    {
      chk_sum_2 ^= stage_v_1_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_2_1 = ((st_var_2_1.buffer[2] * 2) + 13) & 63;
  int stage_v_2_2 = ((st_var_2_2.buffer[2] * 2) + 13) & 63;
  if (stage_v_2_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_2_1) - 5) & 255;
    if (stage_v_2_1 > 40)
    {
      chk_sum_1 ^= stage_v_2_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_2_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_2_2) - 5) & 255;
    if (stage_v_2_2 > 40)
    {
      chk_sum_2 ^= stage_v_2_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_3_1.buffer[0] = (st_var_3_1.buffer[0] + 4) & 15;
  st_var_3_2.buffer[0] = (st_var_3_2.buffer[0] + 4) & 15;
  int stage_v_3_1 = (st_var_3_1.buffer[0] * 3) & 63;
  int stage_v_3_2 = (st_var_3_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_3_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_3_2) & 255;
  chk_sum_1 ^= stage_v_3_1;
  chk_sum_2 ^= stage_v_3_2;
  int stage_v_4_1 = ((st_var_0_1.buffer[1] * 2) + 19) & 63;
  int stage_v_4_2 = ((st_var_0_2.buffer[1] * 2) + 19) & 63;
  if (stage_v_4_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + stage_v_4_1) - 5) & 255;
    if (stage_v_4_1 > 42)
    {
      chk_sum_1 ^= stage_v_4_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_4_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + stage_v_4_2) - 5) & 255;
    if (stage_v_4_2 > 42)
    {
      chk_sum_2 ^= stage_v_4_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_5_1 = table_1[1];
  int stage_v_5_2 = table_2[1];
  table_1[1] = (table_1[2] + 11) & 63;
  table_2[1] = (table_2[2] + 11) & 63;
  out_sink_1 = (out_sink_1 + stage_v_5_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_5_2) & 255;
  st_var_2_1.buffer[0] = (st_var_2_1.buffer[0] + 7) & 15;
  st_var_2_2.buffer[0] = (st_var_2_2.buffer[0] + 7) & 15;
  int stage_v_6_1 = (st_var_2_1.buffer[0] * 3) & 63;
  int stage_v_6_2 = (st_var_2_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_6_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_6_2) & 255;
  chk_sum_1 ^= stage_v_6_1;
  chk_sum_2 ^= stage_v_6_2;
  int stage_v_7_1 = ((st_var_3_1.buffer[1] * 2) + 28) & 63;
  int stage_v_7_2 = ((st_var_3_2.buffer[1] * 2) + 28) & 63;
  if (stage_v_7_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + stage_v_7_1) - 5) & 255;
    if (stage_v_7_1 > 40)
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
  if (stage_v_7_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + stage_v_7_2) - 5) & 255;
    if (stage_v_7_2 > 40)
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
  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 9) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 9) & 15;
  int stage_v_8_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_8_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_8_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_8_2) & 255;
  chk_sum_1 ^= stage_v_8_1;
  chk_sum_2 ^= stage_v_8_2;
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
  int stage_v_11_1 = table_1[3];
  int stage_v_11_2 = table_2[3];
  table_1[3] = (table_1[0] + 23) & 63;
  table_2[3] = (table_2[0] + 23) & 63;
  out_sink_1 = (out_sink_1 + stage_v_11_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_11_2) & 255;
  int stage_v_12_1 = (((sec_r000615_12_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_12_2 = (((sec_r000615_12_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_12_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_12_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_12_1 & 63;
  out_sink_2 ^= stage_v_12_2 & 63;
  int stage_v_13_1 = (((stage_v_12_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_13_2 = (((stage_v_12_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_13_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_13_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_13_1 & 63;
  out_sink_2 ^= stage_v_13_2 & 63;
  int stage_v_14_1 = (((sec_r000615_2_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_14_2 = (((sec_r000615_2_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_14_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_14_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_14_1 & 63;
  out_sink_2 ^= stage_v_14_2 & 63;
  int stage_v_15_1 = (((sec_r000615_13_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_15_2 = (((sec_r000615_13_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_15_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_15_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_15_1 & 63;
  out_sink_2 ^= stage_v_15_2 & 63;
  int stage_v_16_1 = (((stage_v_12_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_16_2 = (((stage_v_12_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_16_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_16_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_16_1 & 63;
  out_sink_2 ^= stage_v_16_2 & 63;
  int stage_v_17_1 = (((stage_v_12_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_17_2 = (((stage_v_12_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_17_1 & 63;
  out_sink_2 ^= stage_v_17_2 & 63;
  int stage_v_18_1 = (((stage_v_12_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_18_2 = (((stage_v_12_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_18_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_18_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_18_1 & 63;
  out_sink_2 ^= stage_v_18_2 & 63;
  int stage_v_19_1 = (((stage_v_16_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_19_2 = (((stage_v_16_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_19_1 & 63;
  out_sink_2 ^= stage_v_19_2 & 63;
  int stage_v_20_1 = (((sec_r000615_18_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_20_2 = (((sec_r000615_18_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_20_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_20_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_20_1 & 63;
  out_sink_2 ^= stage_v_20_2 & 63;
  int stage_v_21_1 = (((stage_v_18_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_21_2 = (((stage_v_18_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_21_1 & 63;
  out_sink_2 ^= stage_v_21_2 & 63;
  int stage_v_22_1 = (((sec_r000615_14_1 << 2) ^ (sec_r000615_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_22_2 = (((sec_r000615_14_2 << 2) ^ (sec_r000615_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_22_1 & 63;
  out_sink_2 ^= stage_v_22_2 & 63;
  int stage_v_23_1 = (((sec_r000615_17_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_23_2 = (((sec_r000615_17_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_23_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_23_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_23_1 & 63;
  out_sink_2 ^= stage_v_23_2 & 63;
  int stage_v_24_1 = (((stage_v_21_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_24_2 = (((stage_v_21_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_24_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_24_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_24_1 & 63;
  out_sink_2 ^= stage_v_24_2 & 63;
  int stage_v_25_1 = (((stage_v_15_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_25_2 = (((stage_v_15_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_25_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_25_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_25_1 & 63;
  out_sink_2 ^= stage_v_25_2 & 63;
  int stage_v_26_1 = (((sec_r000615_18_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_26_2 = (((sec_r000615_18_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_26_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_26_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_26_1 & 63;
  out_sink_2 ^= stage_v_26_2 & 63;
  int stage_v_27_1 = (((stage_v_25_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_27_2 = (((stage_v_25_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_27_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_27_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_27_1 & 63;
  out_sink_2 ^= stage_v_27_2 & 63;
  int stage_v_28_1 = (((stage_v_21_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_28_2 = (((stage_v_21_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_28_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_28_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_28_1 & 63;
  out_sink_2 ^= stage_v_28_2 & 63;
  int stage_v_29_1 = (((sec_r000615_8_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_29_2 = (((sec_r000615_8_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_29_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_29_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_29_1 & 63;
  out_sink_2 ^= stage_v_29_2 & 63;
  int stage_v_30_1 = (((stage_v_16_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_30_2 = (((stage_v_16_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_30_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_30_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_30_1 & 63;
  out_sink_2 ^= stage_v_30_2 & 63;
  int stage_v_31_1 = (((stage_v_29_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_31_2 = (((stage_v_29_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_31_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_31_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_31_1 & 63;
  out_sink_2 ^= stage_v_31_2 & 63;
  int stage_v_32_1 = (((stage_v_12_1 << 2) ^ (sec_r000615_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_32_2 = (((stage_v_12_2 << 2) ^ (sec_r000615_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_32_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_32_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_32_1 & 63;
  out_sink_2 ^= stage_v_32_2 & 63;
  int stage_v_33_1 = (((stage_v_16_1 << 2) ^ (sec_r000615_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_33_2 = (((stage_v_16_2 << 2) ^ (sec_r000615_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_33_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_33_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_33_1 & 63;
  out_sink_2 ^= stage_v_33_2 & 63;
  int stage_v_34_1 = (((stage_v_20_1 << 1) ^ (sec_r000615_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_34_2 = (((stage_v_20_2 << 1) ^ (sec_r000615_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_34_1 & 63;
  out_sink_2 ^= stage_v_34_2 & 63;
  int stage_v_35_1 = (((stage_v_23_1 << 1) ^ (sec_r000615_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_35_2 = (((stage_v_23_2 << 1) ^ (sec_r000615_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_35_1 & 63;
  out_sink_2 ^= stage_v_35_2 & 63;
  int stage_v_36_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_36_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_36_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_36_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_36_1 & 63;
  out_sink_2 ^= stage_v_36_2 & 63;
  int stage_v_37_1 = (((stage_v_24_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_37_2 = (((stage_v_24_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_37_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_37_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_37_1 & 63;
  out_sink_2 ^= stage_v_37_2 & 63;
  int stage_v_38_1 = (((sec_r000615_11_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_38_2 = (((sec_r000615_11_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_38_1 & 63;
  out_sink_2 ^= stage_v_38_2 & 63;
  int stage_v_39_1 = (((stage_v_16_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_39_2 = (((stage_v_16_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_39_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_39_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_39_1 & 63;
  out_sink_2 ^= stage_v_39_2 & 63;
  int stage_v_40_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_40_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_40_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_40_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_40_1 & 63;
  out_sink_2 ^= stage_v_40_2 & 63;
  int stage_v_41_1 = (((sec_r000615_11_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_41_2 = (((sec_r000615_11_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_41_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_41_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_41_1 & 63;
  out_sink_2 ^= stage_v_41_2 & 63;
  int stage_v_42_1 = (((stage_v_27_1 << 1) ^ (sec_r000615_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_42_2 = (((stage_v_27_2 << 1) ^ (sec_r000615_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_42_1 & 63;
  out_sink_2 ^= stage_v_42_2 & 63;
  int stage_v_43_1 = (((stage_v_40_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_43_2 = (((stage_v_40_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_43_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_43_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_43_1 & 63;
  out_sink_2 ^= stage_v_43_2 & 63;
  int stage_v_44_1 = (((sec_r000615_8_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_44_2 = (((sec_r000615_8_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_44_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_44_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_44_1 & 63;
  out_sink_2 ^= stage_v_44_2 & 63;
  int stage_v_45_1 = (((stage_v_22_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_45_2 = (((stage_v_22_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_45_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_45_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_45_1 & 63;
  out_sink_2 ^= stage_v_45_2 & 63;
  int stage_v_46_1 = (((sec_r000615_14_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_46_2 = (((sec_r000615_14_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_46_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_46_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_46_1 & 63;
  out_sink_2 ^= stage_v_46_2 & 63;
  int stage_v_47_1 = (((stage_v_13_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_47_2 = (((stage_v_13_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_47_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_47_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_47_1 & 63;
  out_sink_2 ^= stage_v_47_2 & 63;
  int stage_v_48_1 = (((sec_r000615_10_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_48_2 = (((sec_r000615_10_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_48_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_48_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_48_1 & 63;
  out_sink_2 ^= stage_v_48_2 & 63;
  int stage_v_49_1 = (((stage_v_15_1 << 2) ^ (sec_r000615_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_49_2 = (((stage_v_15_2 << 2) ^ (sec_r000615_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_49_1 & 63;
  out_sink_2 ^= stage_v_49_2 & 63;
  int stage_v_50_1 = (((stage_v_41_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_50_2 = (((stage_v_41_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_50_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_50_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_50_1 & 63;
  out_sink_2 ^= stage_v_50_2 & 63;
  int stage_v_51_1 = (((sec_r000615_10_1 << 1) ^ (sec_r000615_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_51_2 = (((sec_r000615_10_2 << 1) ^ (sec_r000615_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_51_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_51_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_51_1 & 63;
  out_sink_2 ^= stage_v_51_2 & 63;
  int stage_v_52_1 = (((stage_v_18_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_52_2 = (((stage_v_18_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_52_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_52_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_52_1 & 63;
  out_sink_2 ^= stage_v_52_2 & 63;
  int stage_v_53_1 = (((stage_v_13_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_53_2 = (((stage_v_13_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_53_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_53_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_53_1 & 63;
  out_sink_2 ^= stage_v_53_2 & 63;
  int stage_v_54_1 = (((stage_v_15_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_54_2 = (((stage_v_15_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_54_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_54_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_54_1 & 63;
  out_sink_2 ^= stage_v_54_2 & 63;
  int stage_v_55_1 = (((stage_v_24_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_55_2 = (((stage_v_24_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_55_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_55_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_55_1 & 63;
  out_sink_2 ^= stage_v_55_2 & 63;
  int stage_v_56_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_56_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_56_1 & 63;
  out_sink_2 ^= stage_v_56_2 & 63;
  int stage_v_57_1 = (((stage_v_28_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_57_2 = (((stage_v_28_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_57_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_57_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_57_1 & 63;
  out_sink_2 ^= stage_v_57_2 & 63;
  int stage_v_58_1 = (((stage_v_46_1 << 2) ^ (sec_r000615_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_58_2 = (((stage_v_46_2 << 2) ^ (sec_r000615_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_58_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_58_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_58_1 & 63;
  out_sink_2 ^= stage_v_58_2 & 63;
  int stage_v_59_1 = (((stage_v_43_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_59_2 = (((stage_v_43_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_59_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_59_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_59_1 & 63;
  out_sink_2 ^= stage_v_59_2 & 63;
  int stage_v_60_1 = (((stage_v_44_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_60_2 = (((stage_v_44_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_60_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_60_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_60_1 & 63;
  out_sink_2 ^= stage_v_60_2 & 63;
  int stage_v_61_1 = (((sec_r000615_6_1 << 1) ^ (sec_r000615_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_61_2 = (((sec_r000615_6_2 << 1) ^ (sec_r000615_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_61_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_61_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_61_1 & 63;
  out_sink_2 ^= stage_v_61_2 & 63;
  int stage_v_62_1 = (((sec_r000615_4_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_62_2 = (((sec_r000615_4_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_62_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_62_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_62_1 & 63;
  out_sink_2 ^= stage_v_62_2 & 63;
  int stage_v_63_1 = (((sec_r000615_12_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_63_2 = (((sec_r000615_12_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_63_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_63_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_63_1 & 63;
  out_sink_2 ^= stage_v_63_2 & 63;
  int stage_v_64_1 = (((stage_v_28_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_64_2 = (((stage_v_28_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_64_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_64_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_64_1 & 63;
  out_sink_2 ^= stage_v_64_2 & 63;
  int stage_v_65_1 = (((stage_v_24_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_65_2 = (((stage_v_24_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_65_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_65_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_65_1 & 63;
  out_sink_2 ^= stage_v_65_2 & 63;
  int stage_v_66_1 = (((stage_v_40_1 << 1) ^ (sec_r000615_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_66_2 = (((stage_v_40_2 << 1) ^ (sec_r000615_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_66_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_66_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_66_1 & 63;
  out_sink_2 ^= stage_v_66_2 & 63;
  int stage_v_67_1 = (((stage_v_26_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_67_2 = (((stage_v_26_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_67_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_67_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_67_1 & 63;
  out_sink_2 ^= stage_v_67_2 & 63;
  int stage_v_68_1 = (((sec_r000615_4_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_68_2 = (((sec_r000615_4_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_68_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_68_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_68_1 & 63;
  out_sink_2 ^= stage_v_68_2 & 63;
  int stage_v_69_1 = (((stage_v_51_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_69_2 = (((stage_v_51_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_69_1 & 63;
  out_sink_2 ^= stage_v_69_2 & 63;
  int stage_v_70_1 = (((stage_v_30_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_70_2 = (((stage_v_30_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_70_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_70_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_70_1 & 63;
  out_sink_2 ^= stage_v_70_2 & 63;
  int stage_v_71_1 = (((stage_v_21_1 << 1) ^ (sec_r000615_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_71_2 = (((stage_v_21_2 << 1) ^ (sec_r000615_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_71_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_71_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_71_1 & 63;
  out_sink_2 ^= stage_v_71_2 & 63;
  int stage_v_72_1 = (((stage_v_16_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_72_2 = (((stage_v_16_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_72_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_72_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_72_1 & 63;
  out_sink_2 ^= stage_v_72_2 & 63;
  int stage_v_73_1 = (((sec_r000615_12_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_73_2 = (((sec_r000615_12_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_73_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_73_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_73_1 & 63;
  out_sink_2 ^= stage_v_73_2 & 63;
  int stage_v_74_1 = (((stage_v_17_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_74_2 = (((stage_v_17_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_74_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_74_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_74_1 & 63;
  out_sink_2 ^= stage_v_74_2 & 63;
  int stage_v_75_1 = (((sec_r000615_18_1 << 1) ^ (sec_r000615_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_75_2 = (((sec_r000615_18_2 << 1) ^ (sec_r000615_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_75_1 & 63;
  out_sink_2 ^= stage_v_75_2 & 63;
  int stage_v_76_1 = (((stage_v_71_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_76_2 = (((stage_v_71_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_76_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_76_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_76_1 & 63;
  out_sink_2 ^= stage_v_76_2 & 63;
  int stage_v_77_1 = (((stage_v_39_1 << 2) ^ (sec_r000615_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_77_2 = (((stage_v_39_2 << 2) ^ (sec_r000615_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_77_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_77_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_77_1 & 63;
  out_sink_2 ^= stage_v_77_2 & 63;
  int stage_v_78_1 = (((stage_v_77_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_78_2 = (((stage_v_77_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_78_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_78_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_78_1 & 63;
  out_sink_2 ^= stage_v_78_2 & 63;
  int stage_v_79_1 = (((sec_r000615_4_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_79_2 = (((sec_r000615_4_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_79_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_79_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_79_1 & 63;
  out_sink_2 ^= stage_v_79_2 & 63;
  int stage_v_80_1 = (((stage_v_67_1 << 2) ^ (sec_r000615_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_80_2 = (((stage_v_67_2 << 2) ^ (sec_r000615_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_80_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_80_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_80_1 & 63;
  out_sink_2 ^= stage_v_80_2 & 63;
  int stage_v_81_1 = (((stage_v_40_1 << 2) ^ (sec_r000615_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_81_2 = (((stage_v_40_2 << 2) ^ (sec_r000615_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_81_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_81_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_81_1 & 63;
  out_sink_2 ^= stage_v_81_2 & 63;
  int stage_v_82_1 = (((sec_r000615_7_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_82_2 = (((sec_r000615_7_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_82_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_82_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_82_1 & 63;
  out_sink_2 ^= stage_v_82_2 & 63;
  int stage_v_83_1 = (((stage_v_55_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_83_2 = (((stage_v_55_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_83_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_83_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_83_1 & 63;
  out_sink_2 ^= stage_v_83_2 & 63;
  int stage_v_84_1 = (((stage_v_32_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_84_2 = (((stage_v_32_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_84_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_84_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_84_1 & 63;
  out_sink_2 ^= stage_v_84_2 & 63;
  int stage_v_85_1 = (((stage_v_44_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_85_2 = (((stage_v_44_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_85_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_85_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_85_1 & 63;
  out_sink_2 ^= stage_v_85_2 & 63;
  int stage_v_86_1 = (((stage_v_37_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_86_2 = (((stage_v_37_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_86_1 & 63;
  out_sink_2 ^= stage_v_86_2 & 63;
  int stage_v_87_1 = (((sec_r000615_15_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_87_2 = (((sec_r000615_15_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_87_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_87_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_87_1 & 63;
  out_sink_2 ^= stage_v_87_2 & 63;
  int stage_v_88_1 = (((stage_v_42_1 << 2) ^ (sec_r000615_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_88_2 = (((stage_v_42_2 << 2) ^ (sec_r000615_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_88_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_88_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_88_1 & 63;
  out_sink_2 ^= stage_v_88_2 & 63;
  int stage_v_89_1 = (((stage_v_87_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_89_2 = (((stage_v_87_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_89_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_89_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_89_1 & 63;
  out_sink_2 ^= stage_v_89_2 & 63;
  int stage_v_90_1 = (((stage_v_64_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_90_2 = (((stage_v_64_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_90_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_90_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_90_1 & 63;
  out_sink_2 ^= stage_v_90_2 & 63;
  int stage_v_91_1 = (((sec_r000615_8_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_91_2 = (((sec_r000615_8_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_91_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_91_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_91_1 & 63;
  out_sink_2 ^= stage_v_91_2 & 63;
  int stage_v_92_1 = (((stage_v_36_1 << 2) ^ (sec_r000615_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_92_2 = (((stage_v_36_2 << 2) ^ (sec_r000615_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_92_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_92_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_92_1 & 63;
  out_sink_2 ^= stage_v_92_2 & 63;
  int stage_v_93_1 = (((stage_v_25_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_93_2 = (((stage_v_25_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_93_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_93_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_93_1 & 63;
  out_sink_2 ^= stage_v_93_2 & 63;
  int stage_v_94_1 = (((stage_v_41_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_94_2 = (((stage_v_41_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_94_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_94_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_94_1 & 63;
  out_sink_2 ^= stage_v_94_2 & 63;
  int stage_v_95_1 = (((stage_v_65_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_95_2 = (((stage_v_65_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_95_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_95_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_95_1 & 63;
  out_sink_2 ^= stage_v_95_2 & 63;
  int stage_v_96_1 = (((stage_v_75_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_96_2 = (((stage_v_75_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_96_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_96_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_96_1 & 63;
  out_sink_2 ^= stage_v_96_2 & 63;
  int stage_v_97_1 = (((stage_v_75_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_97_2 = (((stage_v_75_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_97_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_97_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_97_1 & 63;
  out_sink_2 ^= stage_v_97_2 & 63;
  int stage_v_98_1 = (((stage_v_81_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_98_2 = (((stage_v_81_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_98_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_98_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_98_1 & 63;
  out_sink_2 ^= stage_v_98_2 & 63;
  int stage_v_99_1 = (((stage_v_47_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_99_2 = (((stage_v_47_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_99_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_99_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_99_1 & 63;
  out_sink_2 ^= stage_v_99_2 & 63;
  int stage_v_100_1 = (((stage_v_33_1 << 1) ^ (sec_r000615_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_100_2 = (((stage_v_33_2 << 1) ^ (sec_r000615_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_100_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_100_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_100_1 & 63;
  out_sink_2 ^= stage_v_100_2 & 63;
  int stage_v_101_1 = (((sec_r000615_9_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_101_2 = (((sec_r000615_9_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_101_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_101_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_101_1 & 63;
  out_sink_2 ^= stage_v_101_2 & 63;
  int stage_v_102_1 = (((stage_v_47_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_102_2 = (((stage_v_47_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_102_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_102_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_102_1 & 63;
  out_sink_2 ^= stage_v_102_2 & 63;
  int stage_v_103_1 = (((stage_v_34_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_103_2 = (((stage_v_34_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_103_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_103_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_103_1 & 63;
  out_sink_2 ^= stage_v_103_2 & 63;
  int stage_v_104_1 = (((sec_r000615_9_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_104_2 = (((sec_r000615_9_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_104_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_104_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_104_1 & 63;
  out_sink_2 ^= stage_v_104_2 & 63;
  int stage_v_105_1 = (((stage_v_71_1 << 1) ^ (sec_r000615_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_105_2 = (((stage_v_71_2 << 1) ^ (sec_r000615_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_105_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_105_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_105_1 & 63;
  out_sink_2 ^= stage_v_105_2 & 63;
  int stage_v_106_1 = (((stage_v_42_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_106_2 = (((stage_v_42_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_106_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_106_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_106_1 & 63;
  out_sink_2 ^= stage_v_106_2 & 63;
  int stage_v_107_1 = (((stage_v_70_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_107_2 = (((stage_v_70_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_107_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_107_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_107_1 & 63;
  out_sink_2 ^= stage_v_107_2 & 63;
  int stage_v_108_1 = (((stage_v_48_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_108_2 = (((stage_v_48_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_108_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_108_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_108_1 & 63;
  out_sink_2 ^= stage_v_108_2 & 63;
  int stage_v_109_1 = (((sec_r000615_14_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_109_2 = (((sec_r000615_14_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_109_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_109_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_109_1 & 63;
  out_sink_2 ^= stage_v_109_2 & 63;
  int stage_v_110_1 = (((sec_r000615_13_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_110_2 = (((sec_r000615_13_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_110_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_110_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_110_1 & 63;
  out_sink_2 ^= stage_v_110_2 & 63;
  int stage_v_111_1 = (((sec_r000615_9_1 << 1) ^ (sec_r000615_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_111_2 = (((sec_r000615_9_2 << 1) ^ (sec_r000615_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_111_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_111_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_111_1 & 63;
  out_sink_2 ^= stage_v_111_2 & 63;
  int stage_v_112_1 = (((sec_r000615_4_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_112_2 = (((sec_r000615_4_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_112_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_112_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_112_1 & 63;
  out_sink_2 ^= stage_v_112_2 & 63;
  int stage_v_113_1 = (((sec_r000615_2_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_113_2 = (((sec_r000615_2_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_113_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_113_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_113_1 & 63;
  out_sink_2 ^= stage_v_113_2 & 63;
  int stage_v_114_1 = (((stage_v_77_1 << 1) ^ (sec_r000615_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_114_2 = (((stage_v_77_2 << 1) ^ (sec_r000615_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_114_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_114_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_114_1 & 63;
  out_sink_2 ^= stage_v_114_2 & 63;
  int stage_v_115_1 = (((stage_v_103_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_115_2 = (((stage_v_103_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_115_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_115_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_115_1 & 63;
  out_sink_2 ^= stage_v_115_2 & 63;
  int stage_v_116_1 = (((stage_v_14_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_116_2 = (((stage_v_14_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_116_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_116_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_116_1 & 63;
  out_sink_2 ^= stage_v_116_2 & 63;
  int stage_v_117_1 = (((sec_r000615_15_1 << 1) ^ (sec_r000615_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_117_2 = (((sec_r000615_15_2 << 1) ^ (sec_r000615_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_117_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_117_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_117_1 & 63;
  out_sink_2 ^= stage_v_117_2 & 63;
  int stage_v_118_1 = (((stage_v_23_1 << 2) ^ (sec_r000615_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_118_2 = (((stage_v_23_2 << 2) ^ (sec_r000615_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_118_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_118_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_118_1 & 63;
  out_sink_2 ^= stage_v_118_2 & 63;
  int stage_v_119_1 = (((stage_v_25_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_119_2 = (((stage_v_25_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_119_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_119_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_119_1 & 63;
  out_sink_2 ^= stage_v_119_2 & 63;
  int stage_v_120_1 = (((stage_v_50_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_120_2 = (((stage_v_50_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_120_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_120_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_120_1 & 63;
  out_sink_2 ^= stage_v_120_2 & 63;
  int stage_v_121_1 = (((sec_r000615_14_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_121_2 = (((sec_r000615_14_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_121_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_121_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_121_1 & 63;
  out_sink_2 ^= stage_v_121_2 & 63;
  int stage_v_122_1 = (((sec_r000615_9_1 << 1) ^ (sec_r000615_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_122_2 = (((sec_r000615_9_2 << 1) ^ (sec_r000615_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_122_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_122_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_122_1 & 63;
  out_sink_2 ^= stage_v_122_2 & 63;
  int stage_v_123_1 = (((stage_v_38_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_123_2 = (((stage_v_38_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_123_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_123_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_123_1 & 63;
  out_sink_2 ^= stage_v_123_2 & 63;
  int stage_v_124_1 = (((stage_v_51_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_124_2 = (((stage_v_51_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_124_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_124_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_124_1 & 63;
  out_sink_2 ^= stage_v_124_2 & 63;
  int stage_v_125_1 = (((stage_v_41_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_125_2 = (((stage_v_41_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_125_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_125_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_125_1 & 63;
  out_sink_2 ^= stage_v_125_2 & 63;
  int stage_v_126_1 = (((stage_v_120_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_126_2 = (((stage_v_120_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_126_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_126_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_126_1 & 63;
  out_sink_2 ^= stage_v_126_2 & 63;
  int stage_v_127_1 = (((stage_v_105_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_127_2 = (((stage_v_105_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_127_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_127_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_127_1 & 63;
  out_sink_2 ^= stage_v_127_2 & 63;
  int stage_v_128_1 = (((stage_v_58_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_128_2 = (((stage_v_58_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_128_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_128_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_128_1 & 63;
  out_sink_2 ^= stage_v_128_2 & 63;
  int stage_v_129_1 = (((sec_r000615_17_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_129_2 = (((sec_r000615_17_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_129_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_129_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_129_1 & 63;
  out_sink_2 ^= stage_v_129_2 & 63;
  int stage_v_130_1 = (((stage_v_85_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_130_2 = (((stage_v_85_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_130_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_130_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_130_1 & 63;
  out_sink_2 ^= stage_v_130_2 & 63;
  int stage_v_131_1 = (((stage_v_14_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_131_2 = (((stage_v_14_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_131_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_131_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_131_1 & 63;
  out_sink_2 ^= stage_v_131_2 & 63;
  int stage_v_132_1 = (((stage_v_61_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_132_2 = (((stage_v_61_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_132_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_132_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_132_1 & 63;
  out_sink_2 ^= stage_v_132_2 & 63;
  int stage_v_133_1 = (((sec_r000615_16_1 << 1) ^ (sec_r000615_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_133_2 = (((sec_r000615_16_2 << 1) ^ (sec_r000615_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_133_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_133_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_133_1 & 63;
  out_sink_2 ^= stage_v_133_2 & 63;
  int stage_v_134_1 = (((stage_v_128_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_134_2 = (((stage_v_128_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_134_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_134_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_134_1 & 63;
  out_sink_2 ^= stage_v_134_2 & 63;
  int stage_v_135_1 = (((sec_r000615_3_1 << 1) ^ (sec_r000615_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_135_2 = (((sec_r000615_3_2 << 1) ^ (sec_r000615_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_135_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_135_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_135_1 & 63;
  out_sink_2 ^= stage_v_135_2 & 63;
  int stage_v_136_1 = (((stage_v_74_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_136_2 = (((stage_v_74_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_136_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_136_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_136_1 & 63;
  out_sink_2 ^= stage_v_136_2 & 63;
  int stage_v_137_1 = (((stage_v_106_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_137_2 = (((stage_v_106_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_137_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_137_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_137_1 & 63;
  out_sink_2 ^= stage_v_137_2 & 63;
  int stage_v_138_1 = (((sec_r000615_1_1 << 1) ^ (sec_r000615_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_138_2 = (((sec_r000615_1_2 << 1) ^ (sec_r000615_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_138_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_138_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_138_1 & 63;
  out_sink_2 ^= stage_v_138_2 & 63;
  int stage_v_139_1 = (((stage_v_113_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_139_2 = (((stage_v_113_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_139_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_139_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_139_1 & 63;
  out_sink_2 ^= stage_v_139_2 & 63;
  int stage_v_140_1 = (((sec_r000615_12_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_140_2 = (((sec_r000615_12_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_140_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_140_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_140_1 & 63;
  out_sink_2 ^= stage_v_140_2 & 63;
  int stage_v_141_1 = (((stage_v_27_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_141_2 = (((stage_v_27_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_141_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_141_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_141_1 & 63;
  out_sink_2 ^= stage_v_141_2 & 63;
  int stage_v_142_1 = (((stage_v_122_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_142_2 = (((stage_v_122_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_142_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_142_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_142_1 & 63;
  out_sink_2 ^= stage_v_142_2 & 63;
  int stage_v_143_1 = (((stage_v_71_1 << 1) ^ (sec_r000615_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_143_2 = (((stage_v_71_2 << 1) ^ (sec_r000615_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_143_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_143_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_143_1 & 63;
  out_sink_2 ^= stage_v_143_2 & 63;
  int stage_v_144_1 = (((stage_v_58_1 << 1) ^ (sec_r000615_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_144_2 = (((stage_v_58_2 << 1) ^ (sec_r000615_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_144_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_144_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_144_1 & 63;
  out_sink_2 ^= stage_v_144_2 & 63;
  int stage_v_145_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_145_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_145_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_145_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_145_1 & 63;
  out_sink_2 ^= stage_v_145_2 & 63;
  int stage_v_146_1 = (((stage_v_69_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_146_2 = (((stage_v_69_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_146_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_146_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_146_1 & 63;
  out_sink_2 ^= stage_v_146_2 & 63;
  int stage_v_147_1 = (((stage_v_83_1 << 1) ^ (sec_r000615_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_147_2 = (((stage_v_83_2 << 1) ^ (sec_r000615_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_147_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_147_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_147_1 & 63;
  out_sink_2 ^= stage_v_147_2 & 63;
  int stage_v_148_1 = (((sec_r000615_6_1 << 1) ^ (sec_r000615_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_148_2 = (((sec_r000615_6_2 << 1) ^ (sec_r000615_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_148_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_148_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_148_1 & 63;
  out_sink_2 ^= stage_v_148_2 & 63;
  int stage_v_149_1 = (((stage_v_84_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_149_2 = (((stage_v_84_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_149_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_149_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_149_1 & 63;
  out_sink_2 ^= stage_v_149_2 & 63;
  int stage_v_150_1 = (((stage_v_71_1 << 1) ^ (sec_r000615_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_150_2 = (((stage_v_71_2 << 1) ^ (sec_r000615_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_150_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_150_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_150_1 & 63;
  out_sink_2 ^= stage_v_150_2 & 63;
  int stage_v_151_1 = (((stage_v_46_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_151_2 = (((stage_v_46_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_151_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_151_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_151_1 & 63;
  out_sink_2 ^= stage_v_151_2 & 63;
  int stage_v_152_1 = (((stage_v_118_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_152_2 = (((stage_v_118_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_152_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_152_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_152_1 & 63;
  out_sink_2 ^= stage_v_152_2 & 63;
  int stage_v_153_1 = (((stage_v_45_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_153_2 = (((stage_v_45_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_153_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_153_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_153_1 & 63;
  out_sink_2 ^= stage_v_153_2 & 63;
  int stage_v_154_1 = (((stage_v_79_1 << 1) ^ (sec_r000615_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_154_2 = (((stage_v_79_2 << 1) ^ (sec_r000615_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_154_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_154_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_154_1 & 63;
  out_sink_2 ^= stage_v_154_2 & 63;
  int stage_v_155_1 = (((stage_v_144_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_155_2 = (((stage_v_144_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_155_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_155_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_155_1 & 63;
  out_sink_2 ^= stage_v_155_2 & 63;
  int stage_v_156_1 = (((sec_r000615_0_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_156_2 = (((sec_r000615_0_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_156_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_156_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_156_1 & 63;
  out_sink_2 ^= stage_v_156_2 & 63;
  int stage_v_157_1 = (((stage_v_110_1 << 1) ^ (sec_r000615_10_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_157_2 = (((stage_v_110_2 << 1) ^ (sec_r000615_10_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_157_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_157_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_157_1 & 63;
  out_sink_2 ^= stage_v_157_2 & 63;
  int stage_v_158_1 = (((stage_v_38_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_158_2 = (((stage_v_38_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_158_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_158_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_158_1 & 63;
  out_sink_2 ^= stage_v_158_2 & 63;
  int stage_v_159_1 = (((sec_r000615_11_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_159_2 = (((sec_r000615_11_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_159_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_159_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_159_1 & 63;
  out_sink_2 ^= stage_v_159_2 & 63;
  int stage_v_160_1 = (((stage_v_135_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_160_2 = (((stage_v_135_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_160_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_160_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_160_1 & 63;
  out_sink_2 ^= stage_v_160_2 & 63;
  int stage_v_161_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_161_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_161_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_161_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_161_1 & 63;
  out_sink_2 ^= stage_v_161_2 & 63;
  int stage_v_162_1 = (((sec_r000615_16_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_162_2 = (((sec_r000615_16_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_162_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_162_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_162_1 & 63;
  out_sink_2 ^= stage_v_162_2 & 63;
  int stage_v_163_1 = (((stage_v_40_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_163_2 = (((stage_v_40_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_163_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_163_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_163_1 & 63;
  out_sink_2 ^= stage_v_163_2 & 63;
  int stage_v_164_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_164_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_164_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_164_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_164_1 & 63;
  out_sink_2 ^= stage_v_164_2 & 63;
  int stage_v_165_1 = (((stage_v_32_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_165_2 = (((stage_v_32_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_165_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_165_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_165_1 & 63;
  out_sink_2 ^= stage_v_165_2 & 63;
  int stage_v_166_1 = (((sec_r000615_1_1 << 1) ^ (sec_r000615_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_166_2 = (((sec_r000615_1_2 << 1) ^ (sec_r000615_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_166_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_166_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_166_1 & 63;
  out_sink_2 ^= stage_v_166_2 & 63;
  int stage_v_167_1 = (((stage_v_50_1 << 1) ^ (sec_r000615_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_167_2 = (((stage_v_50_2 << 1) ^ (sec_r000615_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_167_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_167_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_167_1 & 63;
  out_sink_2 ^= stage_v_167_2 & 63;
  int stage_v_168_1 = (((stage_v_16_1 << 1) ^ (sec_r000615_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_168_2 = (((stage_v_16_2 << 1) ^ (sec_r000615_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_168_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_168_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_168_1 & 63;
  out_sink_2 ^= stage_v_168_2 & 63;
  int stage_v_169_1 = (((stage_v_131_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_169_2 = (((stage_v_131_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_169_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_169_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_169_1 & 63;
  out_sink_2 ^= stage_v_169_2 & 63;
  int stage_v_170_1 = (((stage_v_111_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_170_2 = (((stage_v_111_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_170_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_170_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_170_1 & 63;
  out_sink_2 ^= stage_v_170_2 & 63;
  int stage_v_171_1 = (((stage_v_124_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_171_2 = (((stage_v_124_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_171_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_171_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_171_1 & 63;
  out_sink_2 ^= stage_v_171_2 & 63;
  int stage_v_172_1 = (((stage_v_141_1 << 2) ^ (sec_r000615_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_172_2 = (((stage_v_141_2 << 2) ^ (sec_r000615_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_172_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_172_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_172_1 & 63;
  out_sink_2 ^= stage_v_172_2 & 63;
  int stage_v_173_1 = (((stage_v_78_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_173_2 = (((stage_v_78_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_173_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_173_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_173_1 & 63;
  out_sink_2 ^= stage_v_173_2 & 63;
  int stage_v_174_1 = (((stage_v_142_1 << 1) ^ (sec_r000615_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_174_2 = (((stage_v_142_2 << 1) ^ (sec_r000615_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_174_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_174_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_174_1 & 63;
  out_sink_2 ^= stage_v_174_2 & 63;
  int stage_v_175_1 = (((stage_v_158_1 << 1) ^ (sec_r000615_9_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_175_2 = (((stage_v_158_2 << 1) ^ (sec_r000615_9_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_175_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_175_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_175_1 & 63;
  out_sink_2 ^= stage_v_175_2 & 63;
  int stage_v_176_1 = (((stage_v_153_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_176_2 = (((stage_v_153_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_176_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_176_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_176_1 & 63;
  out_sink_2 ^= stage_v_176_2 & 63;
  int stage_v_177_1 = (((stage_v_63_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_177_2 = (((stage_v_63_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_177_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_177_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_177_1 & 63;
  out_sink_2 ^= stage_v_177_2 & 63;
  int stage_v_178_1 = (((sec_r000615_4_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_178_2 = (((sec_r000615_4_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_178_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_178_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_178_1 & 63;
  out_sink_2 ^= stage_v_178_2 & 63;
  int stage_v_179_1 = (((stage_v_167_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_179_2 = (((stage_v_167_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_179_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_179_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_179_1 & 63;
  out_sink_2 ^= stage_v_179_2 & 63;
  int stage_v_180_1 = (((stage_v_92_1 << 1) ^ (sec_r000615_15_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_180_2 = (((stage_v_92_2 << 1) ^ (sec_r000615_15_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_180_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_180_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_180_1 & 63;
  out_sink_2 ^= stage_v_180_2 & 63;
  int stage_v_181_1 = (((stage_v_156_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_181_2 = (((stage_v_156_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_181_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_181_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_181_1 & 63;
  out_sink_2 ^= stage_v_181_2 & 63;
  int stage_v_182_1 = (((stage_v_71_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_182_2 = (((stage_v_71_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_182_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_182_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_182_1 & 63;
  out_sink_2 ^= stage_v_182_2 & 63;
  int stage_v_183_1 = (((stage_v_24_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_183_2 = (((stage_v_24_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_183_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_183_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_183_1 & 63;
  out_sink_2 ^= stage_v_183_2 & 63;
  int stage_v_184_1 = (((sec_r000615_3_1 << 1) ^ (sec_r000615_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_184_2 = (((sec_r000615_3_2 << 1) ^ (sec_r000615_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_184_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_184_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_184_1 & 63;
  out_sink_2 ^= stage_v_184_2 & 63;
  int stage_v_185_1 = (((stage_v_160_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_185_2 = (((stage_v_160_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_185_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_185_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_185_1 & 63;
  out_sink_2 ^= stage_v_185_2 & 63;
  int stage_v_186_1 = (((sec_r000615_6_1 << 1) ^ (sec_r000615_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_186_2 = (((sec_r000615_6_2 << 1) ^ (sec_r000615_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_186_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_186_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_186_1 & 63;
  out_sink_2 ^= stage_v_186_2 & 63;
  int stage_v_187_1 = (((stage_v_53_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_187_2 = (((stage_v_53_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_187_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_187_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_187_1 & 63;
  out_sink_2 ^= stage_v_187_2 & 63;
  int stage_v_188_1 = (((sec_r000615_11_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_188_2 = (((sec_r000615_11_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_188_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_188_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_188_1 & 63;
  out_sink_2 ^= stage_v_188_2 & 63;
  int stage_v_189_1 = (((stage_v_85_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_189_2 = (((stage_v_85_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_189_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_189_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_189_1 & 63;
  out_sink_2 ^= stage_v_189_2 & 63;
  int stage_v_190_1 = (((sec_r000615_11_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_190_2 = (((sec_r000615_11_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_190_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_190_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_190_1 & 63;
  out_sink_2 ^= stage_v_190_2 & 63;
  int stage_v_191_1 = (((stage_v_60_1 << 2) ^ (sec_r000615_17_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_191_2 = (((stage_v_60_2 << 2) ^ (sec_r000615_17_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_191_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_191_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_191_1 & 63;
  out_sink_2 ^= stage_v_191_2 & 63;
  int stage_v_192_1 = (((stage_v_189_1 << 1) ^ (sec_r000615_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_192_2 = (((stage_v_189_2 << 1) ^ (sec_r000615_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_192_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_192_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_192_1 & 63;
  out_sink_2 ^= stage_v_192_2 & 63;
  int stage_v_193_1 = (((stage_v_148_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_193_2 = (((stage_v_148_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_193_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_193_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_193_1 & 63;
  out_sink_2 ^= stage_v_193_2 & 63;
  int stage_v_194_1 = (((stage_v_80_1 << 1) ^ (sec_r000615_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_194_2 = (((stage_v_80_2 << 1) ^ (sec_r000615_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_194_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_194_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_194_1 & 63;
  out_sink_2 ^= stage_v_194_2 & 63;
  int stage_v_195_1 = (((stage_v_42_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_195_2 = (((stage_v_42_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_195_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_195_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_195_1 & 63;
  out_sink_2 ^= stage_v_195_2 & 63;
  int stage_v_196_1 = (((sec_r000615_17_1 << 1) ^ (sec_r000615_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_196_2 = (((sec_r000615_17_2 << 1) ^ (sec_r000615_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_196_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_196_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_196_1 & 63;
  out_sink_2 ^= stage_v_196_2 & 63;
  int stage_v_197_1 = (((stage_v_100_1 << 1) ^ (sec_r000615_6_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_197_2 = (((stage_v_100_2 << 1) ^ (sec_r000615_6_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_197_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_197_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_197_1 & 63;
  out_sink_2 ^= stage_v_197_2 & 63;
  int stage_v_198_1 = (((stage_v_164_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_198_2 = (((stage_v_164_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_198_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_198_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_198_1 & 63;
  out_sink_2 ^= stage_v_198_2 & 63;
  int stage_v_199_1 = (((stage_v_80_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_199_2 = (((stage_v_80_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_199_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_199_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_199_1 & 63;
  out_sink_2 ^= stage_v_199_2 & 63;
  int stage_v_200_1 = (((stage_v_169_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_200_2 = (((stage_v_169_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_200_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_200_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_200_1 & 63;
  out_sink_2 ^= stage_v_200_2 & 63;
  int stage_v_201_1 = (((sec_r000615_3_1 << 2) ^ (sec_r000615_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_201_2 = (((sec_r000615_3_2 << 2) ^ (sec_r000615_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_201_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_201_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_201_1 & 63;
  out_sink_2 ^= stage_v_201_2 & 63;
  int stage_v_202_1 = (((stage_v_128_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_202_2 = (((stage_v_128_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_202_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_202_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_202_1 & 63;
  out_sink_2 ^= stage_v_202_2 & 63;
  int stage_v_203_1 = (((stage_v_174_1 << 2) ^ (sec_r000615_7_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_203_2 = (((stage_v_174_2 << 2) ^ (sec_r000615_7_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_203_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_203_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_203_1 & 63;
  out_sink_2 ^= stage_v_203_2 & 63;
  int stage_v_204_1 = (((stage_v_138_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_204_2 = (((stage_v_138_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_204_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_204_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_204_1 & 63;
  out_sink_2 ^= stage_v_204_2 & 63;
  int stage_v_205_1 = (((stage_v_68_1 << 1) ^ (sec_r000615_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_205_2 = (((stage_v_68_2 << 1) ^ (sec_r000615_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_205_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_205_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_205_1 & 63;
  out_sink_2 ^= stage_v_205_2 & 63;
  int stage_v_206_1 = (((stage_v_47_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_206_2 = (((stage_v_47_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_206_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_206_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_206_1 & 63;
  out_sink_2 ^= stage_v_206_2 & 63;
  int stage_v_207_1 = (((stage_v_48_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_207_2 = (((stage_v_48_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_207_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_207_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_207_1 & 63;
  out_sink_2 ^= stage_v_207_2 & 63;
  int stage_v_208_1 = (((stage_v_100_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_208_2 = (((stage_v_100_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_208_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_208_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_208_1 & 63;
  out_sink_2 ^= stage_v_208_2 & 63;
  int stage_v_209_1 = (((stage_v_147_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_209_2 = (((stage_v_147_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_209_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_209_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_209_1 & 63;
  out_sink_2 ^= stage_v_209_2 & 63;
  int stage_v_210_1 = (((stage_v_132_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_210_2 = (((stage_v_132_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_210_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_210_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_210_1 & 63;
  out_sink_2 ^= stage_v_210_2 & 63;
  int stage_v_211_1 = (((stage_v_125_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_211_2 = (((stage_v_125_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_211_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_211_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_211_1 & 63;
  out_sink_2 ^= stage_v_211_2 & 63;
  int stage_v_212_1 = (((stage_v_181_1 << 1) ^ (sec_r000615_2_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_212_2 = (((stage_v_181_2 << 1) ^ (sec_r000615_2_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_212_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_212_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_212_1 & 63;
  out_sink_2 ^= stage_v_212_2 & 63;
  int stage_v_213_1 = (((sec_r000615_5_1 << 1) ^ (sec_r000615_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_213_2 = (((sec_r000615_5_2 << 1) ^ (sec_r000615_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_213_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_213_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_213_1 & 63;
  out_sink_2 ^= stage_v_213_2 & 63;
  int stage_v_214_1 = (((sec_r000615_15_1 << 2) ^ (sec_r000615_15_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_214_2 = (((sec_r000615_15_2 << 2) ^ (sec_r000615_15_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_214_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_214_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_214_1 & 63;
  out_sink_2 ^= stage_v_214_2 & 63;
  int stage_v_215_1 = (((sec_r000615_18_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_215_2 = (((sec_r000615_18_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_215_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_215_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_215_1 & 63;
  out_sink_2 ^= stage_v_215_2 & 63;
  int stage_v_216_1 = (((stage_v_45_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_216_2 = (((stage_v_45_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_216_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_216_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_216_1 & 63;
  out_sink_2 ^= stage_v_216_2 & 63;
  int stage_v_217_1 = (((stage_v_87_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_217_2 = (((stage_v_87_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_217_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_217_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_217_1 & 63;
  out_sink_2 ^= stage_v_217_2 & 63;
  int stage_v_218_1 = (((sec_r000615_9_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_218_2 = (((sec_r000615_9_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_218_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_218_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_218_1 & 63;
  out_sink_2 ^= stage_v_218_2 & 63;
  int stage_v_219_1 = (((sec_r000615_1_1 << 2) ^ (sec_r000615_1_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_219_2 = (((sec_r000615_1_2 << 2) ^ (sec_r000615_1_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_219_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_219_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_219_1 & 63;
  out_sink_2 ^= stage_v_219_2 & 63;
  int stage_v_220_1 = (((stage_v_72_1 << 2) ^ (sec_r000615_0_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_220_2 = (((stage_v_72_2 << 2) ^ (sec_r000615_0_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_220_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_220_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_220_1 & 63;
  out_sink_2 ^= stage_v_220_2 & 63;
  int stage_v_221_1 = (((sec_r000615_18_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_221_2 = (((sec_r000615_18_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_221_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_221_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_221_1 & 63;
  out_sink_2 ^= stage_v_221_2 & 63;
  int stage_v_222_1 = (((sec_r000615_7_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_222_2 = (((sec_r000615_7_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_222_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_222_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_222_1 & 63;
  out_sink_2 ^= stage_v_222_2 & 63;
  int stage_v_223_1 = (((stage_v_198_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_223_2 = (((stage_v_198_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_223_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_223_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_223_1 & 63;
  out_sink_2 ^= stage_v_223_2 & 63;
  int stage_v_224_1 = (((stage_v_143_1 << 2) ^ (sec_r000615_2_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_224_2 = (((stage_v_143_2 << 2) ^ (sec_r000615_2_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_224_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_224_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_224_1 & 63;
  out_sink_2 ^= stage_v_224_2 & 63;
  int stage_v_225_1 = (((stage_v_86_1 << 2) ^ (sec_r000615_16_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_225_2 = (((stage_v_86_2 << 2) ^ (sec_r000615_16_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_225_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_225_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_225_1 & 63;
  out_sink_2 ^= stage_v_225_2 & 63;
  int stage_v_226_1 = (((sec_r000615_11_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_226_2 = (((sec_r000615_11_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_226_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_226_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_226_1 & 63;
  out_sink_2 ^= stage_v_226_2 & 63;
  int stage_v_227_1 = (((stage_v_23_1 << 1) ^ (sec_r000615_3_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_227_2 = (((stage_v_23_2 << 1) ^ (sec_r000615_3_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_227_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_227_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_227_1 & 63;
  out_sink_2 ^= stage_v_227_2 & 63;
  int stage_v_228_1 = (((stage_v_210_1 << 2) ^ (sec_r000615_8_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_228_2 = (((stage_v_210_2 << 2) ^ (sec_r000615_8_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_228_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_228_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_228_1 & 63;
  out_sink_2 ^= stage_v_228_2 & 63;
  int stage_v_229_1 = (((sec_r000615_9_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_229_2 = (((sec_r000615_9_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_229_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_229_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_229_1 & 63;
  out_sink_2 ^= stage_v_229_2 & 63;
  int stage_v_230_1 = (((sec_r000615_5_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_230_2 = (((sec_r000615_5_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_230_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_230_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_230_1 & 63;
  out_sink_2 ^= stage_v_230_2 & 63;
  int stage_v_231_1 = (((stage_v_225_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_231_2 = (((stage_v_225_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_231_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_231_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_231_1 & 63;
  out_sink_2 ^= stage_v_231_2 & 63;
  int stage_v_232_1 = (((stage_v_128_1 << 2) ^ (sec_r000615_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_232_2 = (((stage_v_128_2 << 2) ^ (sec_r000615_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_232_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_232_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_232_1 & 63;
  out_sink_2 ^= stage_v_232_2 & 63;
  int stage_v_233_1 = (((stage_v_141_1 << 1) ^ (sec_r000615_5_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_233_2 = (((stage_v_141_2 << 1) ^ (sec_r000615_5_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_233_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_233_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_233_1 & 63;
  out_sink_2 ^= stage_v_233_2 & 63;
  int stage_v_234_1 = (((stage_v_14_1 << 2) ^ (sec_r000615_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_234_2 = (((stage_v_14_2 << 2) ^ (sec_r000615_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_234_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_234_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_234_1 & 63;
  out_sink_2 ^= stage_v_234_2 & 63;
  int stage_v_235_1 = (((stage_v_147_1 << 2) ^ (sec_r000615_4_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_235_2 = (((stage_v_147_2 << 2) ^ (sec_r000615_4_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_235_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_235_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_235_1 & 63;
  out_sink_2 ^= stage_v_235_2 & 63;
  int stage_v_236_1 = (((stage_v_200_1 << 1) ^ (sec_r000615_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_236_2 = (((stage_v_200_2 << 1) ^ (sec_r000615_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_236_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_236_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_236_1 & 63;
  out_sink_2 ^= stage_v_236_2 & 63;
  int stage_v_237_1 = (((sec_r000615_0_1 << 1) ^ (sec_r000615_0_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_237_2 = (((sec_r000615_0_2 << 1) ^ (sec_r000615_0_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_237_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_237_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_237_1 & 63;
  out_sink_2 ^= stage_v_237_2 & 63;
  int stage_v_238_1 = (((stage_v_69_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_238_2 = (((stage_v_69_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_238_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_238_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_238_1 & 63;
  out_sink_2 ^= stage_v_238_2 & 63;
  int stage_v_239_1 = (((sec_r000615_16_1 << 1) ^ (sec_r000615_16_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_239_2 = (((sec_r000615_16_2 << 1) ^ (sec_r000615_16_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_239_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_239_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_239_1 & 63;
  out_sink_2 ^= stage_v_239_2 & 63;
  int stage_v_240_1 = (((sec_r000615_13_1 << 2) ^ (sec_r000615_13_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_240_2 = (((sec_r000615_13_2 << 2) ^ (sec_r000615_13_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_240_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_240_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_240_1 & 63;
  out_sink_2 ^= stage_v_240_2 & 63;
  int stage_v_241_1 = (((stage_v_21_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_241_2 = (((stage_v_21_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_241_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_241_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_241_1 & 63;
  out_sink_2 ^= stage_v_241_2 & 63;
  int stage_v_242_1 = (((sec_r000615_3_1 << 2) ^ (sec_r000615_3_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_242_2 = (((sec_r000615_3_2 << 2) ^ (sec_r000615_3_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_242_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_242_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_242_1 & 63;
  out_sink_2 ^= stage_v_242_2 & 63;
  int stage_v_243_1 = (((stage_v_139_1 << 1) ^ (sec_r000615_8_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_243_2 = (((stage_v_139_2 << 1) ^ (sec_r000615_8_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_243_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_243_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_243_1 & 63;
  out_sink_2 ^= stage_v_243_2 & 63;
  int stage_v_244_1 = (((stage_v_72_1 << 1) ^ (sec_r000615_12_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_244_2 = (((stage_v_72_2 << 1) ^ (sec_r000615_12_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_244_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_244_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_244_1 & 63;
  out_sink_2 ^= stage_v_244_2 & 63;
  int stage_v_245_1 = (((stage_v_53_1 << 1) ^ (sec_r000615_14_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_245_2 = (((stage_v_53_2 << 1) ^ (sec_r000615_14_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_245_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_245_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_245_1 & 63;
  out_sink_2 ^= stage_v_245_2 & 63;
  int stage_v_246_1 = (((stage_v_188_1 << 1) ^ (sec_r000615_17_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_246_2 = (((stage_v_188_2 << 1) ^ (sec_r000615_17_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_246_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_246_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_246_1 & 63;
  out_sink_2 ^= stage_v_246_2 & 63;
  int stage_v_247_1 = (((stage_v_246_1 << 2) ^ (sec_r000615_11_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_247_2 = (((stage_v_246_2 << 2) ^ (sec_r000615_11_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_247_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_247_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_247_1 & 63;
  out_sink_2 ^= stage_v_247_2 & 63;
  int stage_v_248_1 = (((stage_v_179_1 << 2) ^ (sec_r000615_12_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_248_2 = (((stage_v_179_2 << 2) ^ (sec_r000615_12_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_248_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_248_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_248_1 & 63;
  out_sink_2 ^= stage_v_248_2 & 63;
  int stage_v_249_1 = (((stage_v_201_1 << 1) ^ (sec_r000615_13_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_249_2 = (((stage_v_201_2 << 1) ^ (sec_r000615_13_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_249_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_249_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_249_1 & 63;
  out_sink_2 ^= stage_v_249_2 & 63;
  int stage_v_250_1 = (((stage_v_76_1 << 2) ^ (sec_r000615_9_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_250_2 = (((stage_v_76_2 << 2) ^ (sec_r000615_9_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_250_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_250_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_250_1 & 63;
  out_sink_2 ^= stage_v_250_2 & 63;
  int stage_v_251_1 = (((stage_v_102_1 << 2) ^ (sec_r000615_14_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_251_2 = (((stage_v_102_2 << 2) ^ (sec_r000615_14_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_251_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_251_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_251_1 & 63;
  out_sink_2 ^= stage_v_251_2 & 63;
  int stage_v_252_1 = (((stage_v_235_1 << 2) ^ (sec_r000615_10_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_252_2 = (((stage_v_235_2 << 2) ^ (sec_r000615_10_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_252_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_252_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_252_1 & 63;
  out_sink_2 ^= stage_v_252_2 & 63;
  int stage_v_253_1 = (((stage_v_44_1 << 2) ^ (sec_r000615_5_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_253_2 = (((stage_v_44_2 << 2) ^ (sec_r000615_5_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_253_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_253_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_253_1 & 63;
  out_sink_2 ^= stage_v_253_2 & 63;
  int stage_v_254_1 = (((stage_v_55_1 << 1) ^ (sec_r000615_11_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_254_2 = (((stage_v_55_2 << 1) ^ (sec_r000615_11_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_254_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_254_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_254_1 & 63;
  out_sink_2 ^= stage_v_254_2 & 63;
  int stage_v_255_1 = (((sec_r000615_1_1 << 1) ^ (sec_r000615_1_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_255_2 = (((sec_r000615_1_2 << 1) ^ (sec_r000615_1_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_255_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_255_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_255_1 & 63;
  out_sink_2 ^= stage_v_255_2 & 63;
  int stage_v_256_1 = (((sec_r000615_7_1 << 1) ^ (sec_r000615_7_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_256_2 = (((sec_r000615_7_2 << 1) ^ (sec_r000615_7_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_256_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_256_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_256_1 & 63;
  out_sink_2 ^= stage_v_256_2 & 63;
  int stage_v_257_1 = (((stage_v_43_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_257_2 = (((stage_v_43_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[1] = (unsigned char) (stage_v_257_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_257_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  out_sink_1 ^= stage_v_257_1 & 63;
  out_sink_2 ^= stage_v_257_2 & 63;
  int stage_v_258_1 = (((stage_v_81_1 << 2) ^ (sec_r000615_18_1 >> 2)) ^ 0x3C) & 127;
  int stage_v_258_2 = (((stage_v_81_2 << 2) ^ (sec_r000615_18_2 >> 2)) ^ 0x3C) & 127;
  u_var_1.raw[2] = (unsigned char) (stage_v_258_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_258_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  out_sink_1 ^= stage_v_258_1 & 63;
  out_sink_2 ^= stage_v_258_2 & 63;
  int stage_v_259_1 = (((stage_v_127_1 << 1) ^ (sec_r000615_4_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_259_2 = (((stage_v_127_2 << 1) ^ (sec_r000615_4_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[3] = (unsigned char) (stage_v_259_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_259_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  out_sink_1 ^= stage_v_259_1 & 63;
  out_sink_2 ^= stage_v_259_2 & 63;
  int stage_v_260_1 = (((stage_v_43_1 << 1) ^ (sec_r000615_18_1 >> 1)) ^ 0x3C) & 127;
  int stage_v_260_2 = (((stage_v_43_2 << 1) ^ (sec_r000615_18_2 >> 1)) ^ 0x3C) & 127;
  u_var_1.raw[0] = (unsigned char) (stage_v_260_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_260_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  out_sink_1 ^= stage_v_260_1 & 63;
  out_sink_2 ^= stage_v_260_2 & 63;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r000615_0_1 != sec_r000615_0_2);
  __CPROVER_assume(pub_r000615_12_1 == pub_r000615_12_2);
  __CPROVER_assume(sec_r000615_9_1 != sec_r000615_9_2);
  __CPROVER_assume(sec_r000615_6_1 != sec_r000615_6_2);
  __CPROVER_assume(sec_r000615_4_1 != sec_r000615_4_2);
  __CPROVER_assume(pub_r000615_6_1 == pub_r000615_6_2);
  __CPROVER_assume(pub_r000615_8_1 == pub_r000615_8_2);
  __CPROVER_assume(sec_r000615_5_1 != sec_r000615_5_2);
  __CPROVER_assume(pub_r000615_15_1 == pub_r000615_15_2);
  __CPROVER_assume(pub_r000615_17_1 == pub_r000615_17_2);
  __CPROVER_assume(pub_r000615_5_1 == pub_r000615_5_2);
  __CPROVER_assume(pub_r000615_7_1 == pub_r000615_7_2);
  __CPROVER_assume(pub_r000615_2_1 == pub_r000615_2_2);
  __CPROVER_assume(sec_r000615_10_1 != sec_r000615_10_2);
  __CPROVER_assume(sec_r000615_7_1 != sec_r000615_7_2);
  __CPROVER_assume(pub_r000615_9_1 == pub_r000615_9_2);
  __CPROVER_assume(pub_r000615_18_1 == pub_r000615_18_2);
  __CPROVER_assume(sec_r000615_1_1 != sec_r000615_1_2);
  __CPROVER_assume(sec_r000615_11_1 != sec_r000615_11_2);
  __CPROVER_assume(pub_r000615_3_1 == pub_r000615_3_2);
  __CPROVER_assume(sec_r000615_3_1 != sec_r000615_3_2);
  __CPROVER_assume(sec_r000615_16_1 != sec_r000615_16_2);
  __CPROVER_assume(pub_r000615_11_1 == pub_r000615_11_2);
  __CPROVER_assume(pub_r000615_10_1 == pub_r000615_10_2);
  __CPROVER_assume(sec_r000615_17_1 != sec_r000615_17_2);
  __CPROVER_assume(sec_r000615_12_1 != sec_r000615_12_2);
  __CPROVER_assume(sec_r000615_2_1 != sec_r000615_2_2);
  __CPROVER_assume(pub_r000615_16_1 == pub_r000615_16_2);
  __CPROVER_assume(sec_r000615_18_1 != sec_r000615_18_2);
  __CPROVER_assume(pub_r000615_0_1 == pub_r000615_0_2);
  __CPROVER_assume(pub_r000615_19_1 == pub_r000615_19_2);
  __CPROVER_assume(sec_r000615_13_1 != sec_r000615_13_2);
  __CPROVER_assume(sec_r000615_14_1 != sec_r000615_14_2);
  __CPROVER_assume(pub_r000615_13_1 == pub_r000615_13_2);
  __CPROVER_assume(sec_r000615_8_1 != sec_r000615_8_2);
  __CPROVER_assume(pub_r000615_4_1 == pub_r000615_4_2);
  __CPROVER_assume(pub_r000615_1_1 == pub_r000615_1_2);
  __CPROVER_assume(pub_r000615_14_1 == pub_r000615_14_2);
  __CPROVER_assume(sec_r000615_15_1 != sec_r000615_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.mode == st_var_1_2.mode);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_1_1.buffer[i_buffer] == st_var_1_2.buffer[i_buffer]);
  }

  assert(st_var_2_1.baud_rate == st_var_2_2.baud_rate);
  assert(st_var_2_1.id == st_var_2_2.id);
  assert(st_var_2_1.stop_bits == st_var_2_2.stop_bits);
  assert(st_var_2_1.port == st_var_2_2.port);
  assert(st_var_2_1.parity == st_var_2_2.parity);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_2_1.buffer[i_buffer] == st_var_2_2.buffer[i_buffer]);
  }

  assert(st_var_3_1.scale == st_var_3_2.scale);
  assert(st_var_3_1.determinant == st_var_3_2.determinant);
  assert(st_var_3_1.trace == st_var_3_2.trace);
  assert(st_var_3_1.dim == st_var_3_2.dim);
  assert(st_var_3_1.stride == st_var_3_2.stride);
  assert(st_var_3_1.density == st_var_3_2.density);
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
}


