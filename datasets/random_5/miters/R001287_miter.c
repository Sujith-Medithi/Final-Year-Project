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
struct FilterState_R001287_8713_0
{
  int prev_out;
  int damping;
  int prev_in;
  int gain_db;
  int buffer[3];
};
struct Vector3D_R001287_8713_1
{
  int norm_sq;
  int coord_y;
  int coord_x;
  int heading;
  unsigned char coord_z;
  int pitch;
  int buffer[3];
};
union ColorPixel_R001287_8713_0
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
void fn_R001287_8713_0_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 9) & 127;
  int acc_2 = (p0_2 + 9) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int segment_71_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int segment_71_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (segment_71_1 > 41)
  {
    acc_1 = ((acc_1 + (segment_71_1 * 2)) + 5) & 127;
    aux_1 ^= segment_71_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - segment_71_1) + 11) & 127;
    aux_1 += 3;
  }
  if (segment_71_2 > 41)
  {
    acc_2 = ((acc_2 + (segment_71_2 * 2)) + 5) & 127;
    aux_2 ^= segment_71_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - segment_71_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int anchor_12_1 = local_arr_1[aux_1 % 3];
  int anchor_12_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (anchor_12_1 * 2)) & 127;
  acc_2 = (acc_2 + (anchor_12_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(segment_71_1 == segment_71_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(anchor_12_1 == anchor_12_2);
}

int fn_R001287_8713_0(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 9) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int segment_71 = ((st.buffer[0] * 3) + aux) & 63;
  if (segment_71 > 41)
  {
    acc = ((acc + (segment_71 * 2)) + 5) & 127;
    aux ^= segment_71 & 15;
  }
  else
  {
    acc = ((acc - segment_71) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int anchor_12 = local_arr[aux % 3];
  acc = (acc + (anchor_12 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001287_8713_1_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int margin_22_1 = local_arr_1[aux_1 % 3];
  int margin_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_22_2 * 2)) & 127;
  int parity_12_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_12_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_12_1)
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

  switch (parity_12_2)
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

  int residue_99_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int residue_99_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (residue_99_1 > 45)
  {
    acc_1 = ((acc_1 + (residue_99_1 * 2)) + 5) & 127;
    aux_1 ^= residue_99_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - residue_99_1) + 11) & 127;
    aux_1 += 3;
  }
  if (residue_99_2 > 45)
  {
    acc_2 = ((acc_2 + (residue_99_2 * 2)) + 5) & 127;
    aux_2 ^= residue_99_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - residue_99_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
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

  assert(margin_22_1 == margin_22_2);
  assert(parity_12_1 == parity_12_2);
  assert(residue_99_1 == residue_99_2);
}

int fn_R001287_8713_1(int p0, int p1)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int margin_22 = local_arr[aux % 3];
  acc = (acc + (margin_22 * 2)) & 127;
  int parity_12 = (aux + st.buffer[1]) & 3;
  switch (parity_12)
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

  int residue_99 = ((st.buffer[0] * 3) + aux) & 63;
  if (residue_99 > 45)
  {
    acc = ((acc + (residue_99 * 2)) + 5) & 127;
    aux ^= residue_99 & 15;
  }
  else
  {
    acc = ((acc - residue_99) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_2_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 37) & 127;
  int acc_2 = (p0_2 + 37) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int mask_75_1 = 0;
  int mask_75_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    mask_75_1 = ((mask_75_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_75_2 = ((mask_75_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_75_1) & 127;
    acc_2 = (acc_2 + mask_75_2) & 127;
  }

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_75_1 == mask_75_2);
}

int fn_R001287_8713_2(int p0, int p1, int p2)
{
  int acc = (p0 + 37) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int mask_75 = 0;
  for (int k = 0; k < 2; k++)
  {
    mask_75 = ((mask_75 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_75) & 127;
  }

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001287_8713_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 1) & 127;
  int acc_2 = (p0_2 + 1) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int damping_82_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_82_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_82_1)
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

  switch (damping_82_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_82_1 == damping_82_2);
}

int fn_R001287_8713_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 1) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int damping_82 = (aux + st.buffer[1]) & 3;
  switch (damping_82)
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

void fn_R001287_8713_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 3) & 127;
  int acc_2 = (p0_2 + 3) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int metric_44_1 = 0;
  int metric_44_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    metric_44_1 = ((metric_44_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    metric_44_2 = ((metric_44_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + metric_44_1) & 127;
    acc_2 = (acc_2 + metric_44_2) & 127;
  }

  int pivot_10_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_10_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_10_1) & 63;
  aux_2 = (aux_2 + pivot_10_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(metric_44_1 == metric_44_2);
  assert(pivot_10_1 == pivot_10_2);
}

int fn_R001287_8713_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 3) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int metric_44 = 0;
  for (int k = 0; k < 2; k++)
  {
    metric_44 = ((metric_44 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + metric_44) & 127;
  }

  int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_10) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001287_8713_5_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 25;
  st_2.buffer[2] = 25;
  int anchor_35_1 = 0;
  int anchor_35_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    anchor_35_1 = ((anchor_35_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    anchor_35_2 = ((anchor_35_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + anchor_35_1) & 127;
    acc_2 = (acc_2 + anchor_35_2) & 127;
  }

  int coefficient_35_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_35_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_35_1) & 63;
  aux_2 = (aux_2 + coefficient_35_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int sample_96_1 = local_arr_1[aux_1 % 3];
  int sample_96_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (sample_96_1 * 2)) & 127;
  acc_2 = (acc_2 + (sample_96_2 * 2)) & 127;
  int weight_50_1 = (aux_1 + st_1.buffer[1]) & 3;
  int weight_50_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (weight_50_1)
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

  switch (weight_50_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_35_1 == anchor_35_2);
  assert(coefficient_35_1 == coefficient_35_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(sample_96_1 == sample_96_2);
  assert(weight_50_1 == weight_50_2);
}

int fn_R001287_8713_5(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 25;
  int anchor_35 = 0;
  for (int k = 0; k < 2; k++)
  {
    anchor_35 = ((anchor_35 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + anchor_35) & 127;
  }

  int coefficient_35 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_35) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int sample_96 = local_arr[aux % 3];
  acc = (acc + (sample_96 * 2)) & 127;
  int weight_50 = (aux + st.buffer[1]) & 3;
  switch (weight_50)
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

void fn_R001287_8713_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 21) & 127;
  int acc_2 = (p0_2 + 21) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_11_1 = local_arr_1[aux_1 % 3];
  int residue_11_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_11_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_11_2 * 2)) & 127;
  int cursor_54_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int cursor_54_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (cursor_54_1 > 38)
  {
    acc_1 = ((acc_1 + (cursor_54_1 * 2)) + 5) & 127;
    aux_1 ^= cursor_54_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - cursor_54_1) + 11) & 127;
    aux_1 += 3;
  }
  if (cursor_54_2 > 38)
  {
    acc_2 = ((acc_2 + (cursor_54_2 * 2)) + 5) & 127;
    aux_2 ^= cursor_54_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - cursor_54_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
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

  assert(residue_11_1 == residue_11_2);
  assert(cursor_54_1 == cursor_54_2);
}

int fn_R001287_8713_6(int p0, int p1, int p2)
{
  int acc = (p0 + 21) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int local_arr[3] = {4, 9, 15};
  int residue_11 = local_arr[aux % 3];
  acc = (acc + (residue_11 * 2)) & 127;
  int cursor_54 = ((st.buffer[0] * 3) + aux) & 63;
  if (cursor_54 > 38)
  {
    acc = ((acc + (cursor_54 * 2)) + 5) & 127;
    aux ^= cursor_54 & 15;
  }
  else
  {
    acc = ((acc - cursor_54) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 20) & 127;
  int acc_2 = (p0_2 + 20) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int pivot_67_1 = (aux_1 + st_1.buffer[1]) & 3;
  int pivot_67_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (pivot_67_1)
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

  switch (pivot_67_2)
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

  int stride_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_46_1) & 63;
  aux_2 = (aux_2 + stride_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_67_1 == pivot_67_2);
  assert(stride_46_1 == stride_46_2);
}

int fn_R001287_8713_7(int p0, int p1, int p2)
{
  int acc = (p0 + 20) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int pivot_67 = (aux + st.buffer[1]) & 3;
  switch (pivot_67)
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

  int stride_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_46) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001287_8713_8_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_83_1 = local_arr_1[aux_1 % 3];
  int bound_83_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_83_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_83_2 * 2)) & 127;
  int scale_87_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int scale_87_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (scale_87_1 > 23)
  {
    acc_1 = ((acc_1 + (scale_87_1 * 2)) + 5) & 127;
    aux_1 ^= scale_87_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - scale_87_1) + 11) & 127;
    aux_1 += 3;
  }
  if (scale_87_2 > 23)
  {
    acc_2 = ((acc_2 + (scale_87_2 * 2)) + 5) & 127;
    aux_2 ^= scale_87_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - scale_87_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
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

  assert(bound_83_1 == bound_83_2);
  assert(scale_87_1 == scale_87_2);
}

int fn_R001287_8713_8(int p0, int p1)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int local_arr[3] = {4, 9, 15};
  int bound_83 = local_arr[aux % 3];
  acc = (acc + (bound_83 * 2)) & 127;
  int scale_87 = ((st.buffer[0] * 3) + aux) & 63;
  if (scale_87 > 23)
  {
    acc = ((acc + (scale_87 * 2)) + 5) & 127;
    aux ^= scale_87 & 15;
  }
  else
  {
    acc = ((acc - scale_87) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_9_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 22;
  st_2.buffer[2] = 22;
  int factor_41_1 = 0;
  int factor_41_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    factor_41_1 = ((factor_41_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_41_2 = ((factor_41_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_41_1) & 127;
    acc_2 = (acc_2 + factor_41_2) & 127;
  }

  int vector_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_92_1) & 63;
  aux_2 = (aux_2 + vector_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_41_1 == factor_41_2);
  assert(vector_92_1 == vector_92_2);
}

int fn_R001287_8713_9(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 22;
  int factor_41 = 0;
  for (int k = 0; k < 2; k++)
  {
    factor_41 = ((factor_41 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_41) & 127;
  }

  int vector_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_92) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001287_8713_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int phase_81_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int phase_81_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + phase_81_1) & 63;
  aux_2 = (aux_2 + phase_81_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_62_1)
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

  switch (threshold_62_2)
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

  int threshold_37_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_37_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_37_1 > 40)
  {
    acc_1 = ((acc_1 + (threshold_37_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_37_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_37_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_37_2 > 40)
  {
    acc_2 = ((acc_2 + (threshold_37_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_37_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_37_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(phase_81_1 == phase_81_2);
  assert(threshold_62_1 == threshold_62_2);
  assert(threshold_37_1 == threshold_37_2);
}

int fn_R001287_8713_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + phase_81) & 63;
  acc ^= aux;
  int threshold_62 = (aux + st.buffer[1]) & 3;
  switch (threshold_62)
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

  int threshold_37 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_37 > 40)
  {
    acc = ((acc + (threshold_37 * 2)) + 5) & 127;
    aux ^= threshold_37 & 15;
  }
  else
  {
    acc = ((acc - threshold_37) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 34) & 127;
  int acc_2 = (p0_2 + 34) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int sample_63_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_63_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_63_1)
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

  switch (sample_63_2)
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
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_42_1 = local_arr_1[aux_1 % 3];
  int damping_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_42_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_63_1 == sample_63_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_42_1 == damping_42_2);
}

int fn_R001287_8713_11(int p0, int p1)
{
  int acc = (p0 + 34) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int sample_63 = (aux + st.buffer[1]) & 3;
  switch (sample_63)
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
  int local_arr[3] = {4, 9, 15};
  int damping_42 = local_arr[aux % 3];
  acc = (acc + (damping_42 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001287_8713_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int anchor_68_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int anchor_68_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (anchor_68_1 > 49)
  {
    acc_1 = ((acc_1 + (anchor_68_1 * 2)) + 5) & 127;
    aux_1 ^= anchor_68_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - anchor_68_1) + 11) & 127;
    aux_1 += 3;
  }
  if (anchor_68_2 > 49)
  {
    acc_2 = ((acc_2 + (anchor_68_2 * 2)) + 5) & 127;
    aux_2 ^= anchor_68_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - anchor_68_2) + 11) & 127;
    aux_2 += 3;
  }
  int bound_53_1 = (aux_1 + st_1.buffer[1]) & 3;
  int bound_53_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (bound_53_1)
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

  switch (bound_53_2)
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
  int margin_68_1 = local_arr_1[aux_1 % 3];
  int margin_68_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (margin_68_1 * 2)) & 127;
  acc_2 = (acc_2 + (margin_68_2 * 2)) & 127;
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_68_1 == anchor_68_2);
  assert(bound_53_1 == bound_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(margin_68_1 == margin_68_2);
  assert(factor_45_1 == factor_45_2);
}

int fn_R001287_8713_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int anchor_68 = ((st.buffer[0] * 3) + aux) & 63;
  if (anchor_68 > 49)
  {
    acc = ((acc + (anchor_68 * 2)) + 5) & 127;
    aux ^= anchor_68 & 15;
  }
  else
  {
    acc = ((acc - anchor_68) + 11) & 127;
    aux += 3;
  }
  int bound_53 = (aux + st.buffer[1]) & 3;
  switch (bound_53)
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
  int margin_68 = local_arr[aux % 3];
  acc = (acc + (margin_68 * 2)) & 127;
  int factor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_45) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001287_8713_13_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_62_1 = local_arr_1[aux_1 % 3];
  int parity_62_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_62_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_62_2 * 2)) & 127;
  int index_reg_63_1 = 0;
  int index_reg_63_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    index_reg_63_1 = ((index_reg_63_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    index_reg_63_2 = ((index_reg_63_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + index_reg_63_1) & 127;
    acc_2 = (acc_2 + index_reg_63_2) & 127;
  }

  int damping_84_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int damping_84_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (damping_84_1 > 23)
  {
    acc_1 = ((acc_1 + (damping_84_1 * 2)) + 5) & 127;
    aux_1 ^= damping_84_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - damping_84_1) + 11) & 127;
    aux_1 += 3;
  }
  if (damping_84_2 > 23)
  {
    acc_2 = ((acc_2 + (damping_84_2 * 2)) + 5) & 127;
    aux_2 ^= damping_84_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - damping_84_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
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

  assert(parity_62_1 == parity_62_2);
  assert(index_reg_63_1 == index_reg_63_2);
  assert(damping_84_1 == damping_84_2);
}

int fn_R001287_8713_13(int p0, int p1, int p2)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_62 = local_arr[aux % 3];
  acc = (acc + (parity_62 * 2)) & 127;
  int index_reg_63 = 0;
  for (int k = 0; k < 2; k++)
  {
    index_reg_63 = ((index_reg_63 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + index_reg_63) & 127;
  }

  int damping_84 = ((st.buffer[0] * 3) + aux) & 63;
  if (damping_84 > 23)
  {
    acc = ((acc + (damping_84 * 2)) + 5) & 127;
    aux ^= damping_84 & 15;
  }
  else
  {
    acc = ((acc - damping_84) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 20;
  st_2.buffer[2] = 20;
  int tally_33_1 = 0;
  int tally_33_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    tally_33_1 = ((tally_33_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    tally_33_2 = ((tally_33_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + tally_33_1) & 127;
    acc_2 = (acc_2 + tally_33_2) & 127;
  }

  int coefficient_19_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_19_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_19_1)
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

  switch (coefficient_19_2)
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

  int vector_14_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_14_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_14_1) & 63;
  aux_2 = (aux_2 + vector_14_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int metric_66_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int metric_66_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (metric_66_1 > 16)
  {
    acc_1 = ((acc_1 + (metric_66_1 * 2)) + 5) & 127;
    aux_1 ^= metric_66_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - metric_66_1) + 11) & 127;
    aux_1 += 3;
  }
  if (metric_66_2 > 16)
  {
    acc_2 = ((acc_2 + (metric_66_2 * 2)) + 5) & 127;
    aux_2 ^= metric_66_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - metric_66_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tally_33_1 == tally_33_2);
  assert(coefficient_19_1 == coefficient_19_2);
  assert(vector_14_1 == vector_14_2);
  assert(metric_66_1 == metric_66_2);
}

int fn_R001287_8713_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 20;
  int tally_33 = 0;
  for (int k = 0; k < 2; k++)
  {
    tally_33 = ((tally_33 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + tally_33) & 127;
  }

  int coefficient_19 = (aux + st.buffer[1]) & 3;
  switch (coefficient_19)
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

  int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_14) & 63;
  acc ^= aux;
  int metric_66 = ((st.buffer[0] * 3) + aux) & 63;
  if (metric_66 > 16)
  {
    acc = ((acc + (metric_66 * 2)) + 5) & 127;
    aux ^= metric_66 & 15;
  }
  else
  {
    acc = ((acc - metric_66) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001287_8713_15_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int vector_61_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_61_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_61_1 > 15)
  {
    acc_1 = ((acc_1 + (vector_61_1 * 2)) + 5) & 127;
    aux_1 ^= vector_61_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_61_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_61_2 > 15)
  {
    acc_2 = ((acc_2 + (vector_61_2 * 2)) + 5) & 127;
    aux_2 ^= vector_61_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_61_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_31_1 = local_arr_1[aux_1 % 3];
  int bound_31_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_31_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_31_2 * 2)) & 127;
  int sample_13_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_13_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_13_1) & 63;
  aux_2 = (aux_2 + sample_13_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int anchor_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_97_1)
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

  switch (anchor_97_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_61_1 == vector_61_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_31_1 == bound_31_2);
  assert(sample_13_1 == sample_13_2);
  assert(anchor_97_1 == anchor_97_2);
}

int fn_R001287_8713_15(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int vector_61 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_61 > 15)
  {
    acc = ((acc + (vector_61 * 2)) + 5) & 127;
    aux ^= vector_61 & 15;
  }
  else
  {
    acc = ((acc - vector_61) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int bound_31 = local_arr[aux % 3];
  acc = (acc + (bound_31 * 2)) & 127;
  int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_13) & 63;
  acc ^= aux;
  int anchor_97 = (aux + st.buffer[1]) & 3;
  switch (anchor_97)
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

void fn_R001287_8713_16_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st_1 = {0};
  struct FilterState_R001287_8713_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_37_1 = local_arr_1[aux_1 % 3];
  int weight_37_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_37_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_37_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_37_1 == weight_37_2);
}

int fn_R001287_8713_16(int p0, int p1, int p2)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001287_8713_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int weight_37 = local_arr[aux % 3];
  acc = (acc + (weight_37 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001287_8713_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int pivot_22_1 = local_arr_1[aux_1 % 3];
  int pivot_22_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (pivot_22_1 * 2)) & 127;
  acc_2 = (acc_2 + (pivot_22_2 * 2)) & 127;
  int parity_94_1 = (aux_1 + st_1.buffer[1]) & 3;
  int parity_94_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (parity_94_1)
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

  switch (parity_94_2)
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

  int accumulator_85_1 = 0;
  int accumulator_85_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    accumulator_85_1 = ((accumulator_85_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    accumulator_85_2 = ((accumulator_85_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + accumulator_85_1) & 127;
    acc_2 = (acc_2 + accumulator_85_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
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

  assert(pivot_22_1 == pivot_22_2);
  assert(parity_94_1 == parity_94_2);
  assert(accumulator_85_1 == accumulator_85_2);
}

int fn_R001287_8713_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int local_arr[3] = {4, 9, 15};
  int pivot_22 = local_arr[aux % 3];
  acc = (acc + (pivot_22 * 2)) & 127;
  int parity_94 = (aux + st.buffer[1]) & 3;
  switch (parity_94)
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

  int accumulator_85 = 0;
  for (int k = 0; k < 2; k++)
  {
    accumulator_85 = ((accumulator_85 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + accumulator_85) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001287_8713_18_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 26) & 127;
  int acc_2 = (p0_2 + 26) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st_1 = {0};
  struct Vector3D_R001287_8713_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int tracker_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int tracker_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (tracker_44_1)
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

  switch (tracker_44_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 5) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 5) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int residue_33_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_33_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_33_1) & 63;
  aux_2 = (aux_2 + residue_33_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_y == st_2.coord_y);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.pitch == st_2.pitch);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(tracker_44_1 == tracker_44_2);
  assert(residue_33_1 == residue_33_2);
}

int fn_R001287_8713_18(int p0, int p1)
{
  int acc = (p0 + 26) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001287_8713_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int tracker_44 = (aux + st.buffer[1]) & 3;
  switch (tracker_44)
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

  st.buffer[1] = (st.buffer[1] + 5) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int residue_33 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_33) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r001287_0_1;
  int sec_r001287_0_2;
  int sec_r001287_1_1;
  int sec_r001287_1_2;
  int sec_r001287_2_1;
  int sec_r001287_2_2;
  int sec_r001287_3_1;
  int sec_r001287_3_2;
  int sec_r001287_4_1;
  int sec_r001287_4_2;
  int sec_r001287_5_1;
  int sec_r001287_5_2;
  int sec_r001287_6_1;
  int sec_r001287_6_2;
  int sec_r001287_7_1;
  int sec_r001287_7_2;
  int sec_r001287_8_1;
  int sec_r001287_8_2;
  int sec_r001287_9_1;
  int sec_r001287_9_2;
  int sec_r001287_10_1;
  int sec_r001287_10_2;
  int sec_r001287_11_1;
  int sec_r001287_11_2;
  int sec_r001287_12_1;
  int sec_r001287_12_2;
  int sec_r001287_13_1;
  int sec_r001287_13_2;
  int sec_r001287_14_1;
  int sec_r001287_14_2;
  int sec_r001287_15_1;
  int sec_r001287_15_2;
  int sec_r001287_16_1;
  int sec_r001287_16_2;
  int sec_r001287_17_1;
  int sec_r001287_17_2;
  int sec_r001287_18_1;
  int sec_r001287_18_2;
  int sec_r001287_19_1;
  int sec_r001287_19_2;
  int sec_r001287_20_1;
  int sec_r001287_20_2;
  int pub_r001287_0_1;
  int pub_r001287_0_2;
  int pub_r001287_1_1;
  int pub_r001287_1_2;
  int pub_r001287_2_1;
  int pub_r001287_2_2;
  int pub_r001287_3_1;
  int pub_r001287_3_2;
  int pub_r001287_4_1;
  int pub_r001287_4_2;
  int pub_r001287_5_1;
  int pub_r001287_5_2;
  int pub_r001287_6_1;
  int pub_r001287_6_2;
  int pub_r001287_7_1;
  int pub_r001287_7_2;
  int pub_r001287_8_1;
  int pub_r001287_8_2;
  int pub_r001287_9_1;
  int pub_r001287_9_2;
  int pub_r001287_10_1;
  int pub_r001287_10_2;
  int pub_r001287_11_1;
  int pub_r001287_11_2;
  int pub_r001287_12_1;
  int pub_r001287_12_2;
  int pub_r001287_13_1;
  int pub_r001287_13_2;
  int pub_r001287_14_1;
  int pub_r001287_14_2;
  int pub_r001287_15_1;
  int pub_r001287_15_2;
  int pub_r001287_16_1;
  int pub_r001287_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001287_0_1 >= (-100)) && (pub_r001287_0_1 <= 100));
  __CPROVER_assume((pub_r001287_0_2 >= (-100)) && (pub_r001287_0_2 <= 100));
  __CPROVER_assume((pub_r001287_1_1 >= (-100)) && (pub_r001287_1_1 <= 100));
  __CPROVER_assume((pub_r001287_1_2 >= (-100)) && (pub_r001287_1_2 <= 100));
  __CPROVER_assume((pub_r001287_2_1 >= (-100)) && (pub_r001287_2_1 <= 100));
  __CPROVER_assume((pub_r001287_2_2 >= (-100)) && (pub_r001287_2_2 <= 100));
  __CPROVER_assume((pub_r001287_3_1 >= (-100)) && (pub_r001287_3_1 <= 100));
  __CPROVER_assume((pub_r001287_3_2 >= (-100)) && (pub_r001287_3_2 <= 100));
  __CPROVER_assume((pub_r001287_4_1 >= (-100)) && (pub_r001287_4_1 <= 100));
  __CPROVER_assume((pub_r001287_4_2 >= (-100)) && (pub_r001287_4_2 <= 100));
  __CPROVER_assume((pub_r001287_5_1 >= (-100)) && (pub_r001287_5_1 <= 100));
  __CPROVER_assume((pub_r001287_5_2 >= (-100)) && (pub_r001287_5_2 <= 100));
  __CPROVER_assume((pub_r001287_6_1 >= (-100)) && (pub_r001287_6_1 <= 100));
  __CPROVER_assume((pub_r001287_6_2 >= (-100)) && (pub_r001287_6_2 <= 100));
  __CPROVER_assume((pub_r001287_7_1 >= (-100)) && (pub_r001287_7_1 <= 100));
  __CPROVER_assume((pub_r001287_7_2 >= (-100)) && (pub_r001287_7_2 <= 100));
  __CPROVER_assume((pub_r001287_8_1 >= (-100)) && (pub_r001287_8_1 <= 100));
  __CPROVER_assume((pub_r001287_8_2 >= (-100)) && (pub_r001287_8_2 <= 100));
  __CPROVER_assume((pub_r001287_9_1 >= (-100)) && (pub_r001287_9_1 <= 100));
  __CPROVER_assume((pub_r001287_9_2 >= (-100)) && (pub_r001287_9_2 <= 100));
  __CPROVER_assume((pub_r001287_10_1 >= (-100)) && (pub_r001287_10_1 <= 100));
  __CPROVER_assume((pub_r001287_10_2 >= (-100)) && (pub_r001287_10_2 <= 100));
  __CPROVER_assume((pub_r001287_11_1 >= (-100)) && (pub_r001287_11_1 <= 100));
  __CPROVER_assume((pub_r001287_11_2 >= (-100)) && (pub_r001287_11_2 <= 100));
  __CPROVER_assume((pub_r001287_12_1 >= (-100)) && (pub_r001287_12_1 <= 100));
  __CPROVER_assume((pub_r001287_12_2 >= (-100)) && (pub_r001287_12_2 <= 100));
  __CPROVER_assume((pub_r001287_13_1 >= (-100)) && (pub_r001287_13_1 <= 100));
  __CPROVER_assume((pub_r001287_13_2 >= (-100)) && (pub_r001287_13_2 <= 100));
  __CPROVER_assume((pub_r001287_14_1 >= (-100)) && (pub_r001287_14_1 <= 100));
  __CPROVER_assume((pub_r001287_14_2 >= (-100)) && (pub_r001287_14_2 <= 100));
  __CPROVER_assume((pub_r001287_15_1 >= (-100)) && (pub_r001287_15_1 <= 100));
  __CPROVER_assume((pub_r001287_15_2 >= (-100)) && (pub_r001287_15_2 <= 100));
  __CPROVER_assume((pub_r001287_16_1 >= (-100)) && (pub_r001287_16_1 <= 100));
  __CPROVER_assume((pub_r001287_16_2 >= (-100)) && (pub_r001287_16_2 <= 100));
  __CPROVER_assume((sec_r001287_0_1 >= 0) && (sec_r001287_0_1 <= 255));
  __CPROVER_assume((sec_r001287_0_2 >= 0) && (sec_r001287_0_2 <= 255));
  __CPROVER_assume((sec_r001287_1_1 >= 0) && (sec_r001287_1_1 <= 255));
  __CPROVER_assume((sec_r001287_1_2 >= 0) && (sec_r001287_1_2 <= 255));
  __CPROVER_assume((sec_r001287_2_1 >= 0) && (sec_r001287_2_1 <= 255));
  __CPROVER_assume((sec_r001287_2_2 >= 0) && (sec_r001287_2_2 <= 255));
  __CPROVER_assume((sec_r001287_3_1 >= 0) && (sec_r001287_3_1 <= 255));
  __CPROVER_assume((sec_r001287_3_2 >= 0) && (sec_r001287_3_2 <= 255));
  __CPROVER_assume((sec_r001287_4_1 >= 0) && (sec_r001287_4_1 <= 255));
  __CPROVER_assume((sec_r001287_4_2 >= 0) && (sec_r001287_4_2 <= 255));
  __CPROVER_assume((sec_r001287_5_1 >= 0) && (sec_r001287_5_1 <= 255));
  __CPROVER_assume((sec_r001287_5_2 >= 0) && (sec_r001287_5_2 <= 255));
  __CPROVER_assume((sec_r001287_6_1 >= 0) && (sec_r001287_6_1 <= 255));
  __CPROVER_assume((sec_r001287_6_2 >= 0) && (sec_r001287_6_2 <= 255));
  __CPROVER_assume((sec_r001287_7_1 >= 0) && (sec_r001287_7_1 <= 255));
  __CPROVER_assume((sec_r001287_7_2 >= 0) && (sec_r001287_7_2 <= 255));
  __CPROVER_assume((sec_r001287_8_1 >= 0) && (sec_r001287_8_1 <= 255));
  __CPROVER_assume((sec_r001287_8_2 >= 0) && (sec_r001287_8_2 <= 255));
  __CPROVER_assume((sec_r001287_9_1 >= 0) && (sec_r001287_9_1 <= 255));
  __CPROVER_assume((sec_r001287_9_2 >= 0) && (sec_r001287_9_2 <= 255));
  __CPROVER_assume((sec_r001287_10_1 >= 0) && (sec_r001287_10_1 <= 255));
  __CPROVER_assume((sec_r001287_10_2 >= 0) && (sec_r001287_10_2 <= 255));
  __CPROVER_assume((sec_r001287_11_1 >= 0) && (sec_r001287_11_1 <= 255));
  __CPROVER_assume((sec_r001287_11_2 >= 0) && (sec_r001287_11_2 <= 255));
  __CPROVER_assume((sec_r001287_12_1 >= 0) && (sec_r001287_12_1 <= 255));
  __CPROVER_assume((sec_r001287_12_2 >= 0) && (sec_r001287_12_2 <= 255));
  __CPROVER_assume((sec_r001287_13_1 >= 0) && (sec_r001287_13_1 <= 255));
  __CPROVER_assume((sec_r001287_13_2 >= 0) && (sec_r001287_13_2 <= 255));
  __CPROVER_assume((sec_r001287_14_1 >= 0) && (sec_r001287_14_1 <= 255));
  __CPROVER_assume((sec_r001287_14_2 >= 0) && (sec_r001287_14_2 <= 255));
  __CPROVER_assume((sec_r001287_15_1 >= 0) && (sec_r001287_15_1 <= 255));
  __CPROVER_assume((sec_r001287_15_2 >= 0) && (sec_r001287_15_2 <= 255));
  __CPROVER_assume((sec_r001287_16_1 >= 0) && (sec_r001287_16_1 <= 255));
  __CPROVER_assume((sec_r001287_16_2 >= 0) && (sec_r001287_16_2 <= 255));
  __CPROVER_assume((sec_r001287_17_1 >= 0) && (sec_r001287_17_1 <= 255));
  __CPROVER_assume((sec_r001287_17_2 >= 0) && (sec_r001287_17_2 <= 255));
  __CPROVER_assume((sec_r001287_18_1 >= 0) && (sec_r001287_18_1 <= 255));
  __CPROVER_assume((sec_r001287_18_2 >= 0) && (sec_r001287_18_2 <= 255));
  __CPROVER_assume((sec_r001287_19_1 >= 0) && (sec_r001287_19_1 <= 255));
  __CPROVER_assume((sec_r001287_19_2 >= 0) && (sec_r001287_19_2 <= 255));
  __CPROVER_assume((sec_r001287_20_1 >= 0) && (sec_r001287_20_1 <= 255));
  __CPROVER_assume((sec_r001287_20_2 >= 0) && (sec_r001287_20_2 <= 255));
  struct FilterState_R001287_8713_0 st_var_0_1 = {0};
  struct FilterState_R001287_8713_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001287_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001287_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001287_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001287_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001287_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001287_0_2 + 7) & 15;
  struct Vector3D_R001287_8713_1 st_var_1_1 = {0};
  struct Vector3D_R001287_8713_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001287_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001287_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001287_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001287_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001287_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001287_0_2 + 9) & 15;
  union ColorPixel_R001287_8713_0 u_var_1;
  union ColorPixel_R001287_8713_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001287_8713_0(sec_r001287_0_1, sec_r001287_1_1, pub_r001287_2_1, pub_r001287_3_1, pub_r001287_4_1);
  int helper_flow_0_2 = fn_R001287_8713_0(sec_r001287_0_2, sec_r001287_1_2, pub_r001287_2_2, pub_r001287_3_2, pub_r001287_4_2);
  fn_R001287_8713_0_2(sec_r001287_0_1, sec_r001287_1_1, pub_r001287_2_1, pub_r001287_3_1, pub_r001287_4_1, sec_r001287_0_2, sec_r001287_1_2, pub_r001287_2_2, pub_r001287_3_2, pub_r001287_4_2);
  int helper_flow_1_1 = fn_R001287_8713_1(sec_r001287_1_1, sec_r001287_2_1);
  int helper_flow_1_2 = fn_R001287_8713_1(sec_r001287_1_2, sec_r001287_2_2);
  fn_R001287_8713_1_2(sec_r001287_1_1, sec_r001287_2_1, sec_r001287_1_2, sec_r001287_2_2);
  int helper_flow_2_1 = fn_R001287_8713_2(sec_r001287_2_1, pub_r001287_3_1, pub_r001287_4_1);
  int helper_flow_2_2 = fn_R001287_8713_2(sec_r001287_2_2, pub_r001287_3_2, pub_r001287_4_2);
  fn_R001287_8713_2_2(sec_r001287_2_1, pub_r001287_3_1, pub_r001287_4_1, sec_r001287_2_2, pub_r001287_3_2, pub_r001287_4_2);
  int helper_flow_3_1 = fn_R001287_8713_3(sec_r001287_3_1, pub_r001287_4_1, pub_r001287_5_1, pub_r001287_6_1);
  int helper_flow_3_2 = fn_R001287_8713_3(sec_r001287_3_2, pub_r001287_4_2, pub_r001287_5_2, pub_r001287_6_2);
  fn_R001287_8713_3_2(sec_r001287_3_1, pub_r001287_4_1, pub_r001287_5_1, pub_r001287_6_1, sec_r001287_3_2, pub_r001287_4_2, pub_r001287_5_2, pub_r001287_6_2);
  int helper_flow_4_1 = fn_R001287_8713_4(sec_r001287_4_1, sec_r001287_5_1, pub_r001287_6_1, pub_r001287_7_1);
  int helper_flow_4_2 = fn_R001287_8713_4(sec_r001287_4_2, sec_r001287_5_2, pub_r001287_6_2, pub_r001287_7_2);
  fn_R001287_8713_4_2(sec_r001287_4_1, sec_r001287_5_1, pub_r001287_6_1, pub_r001287_7_1, sec_r001287_4_2, sec_r001287_5_2, pub_r001287_6_2, pub_r001287_7_2);
  int helper_flow_5_1 = fn_R001287_8713_5(sec_r001287_5_1, sec_r001287_6_1, pub_r001287_7_1);
  int helper_flow_5_2 = fn_R001287_8713_5(sec_r001287_5_2, sec_r001287_6_2, pub_r001287_7_2);
  fn_R001287_8713_5_2(sec_r001287_5_1, sec_r001287_6_1, pub_r001287_7_1, sec_r001287_5_2, sec_r001287_6_2, pub_r001287_7_2);
  int helper_flow_6_1 = fn_R001287_8713_6(sec_r001287_6_1, sec_r001287_7_1, pub_r001287_8_1);
  int helper_flow_6_2 = fn_R001287_8713_6(sec_r001287_6_2, sec_r001287_7_2, pub_r001287_8_2);
  fn_R001287_8713_6_2(sec_r001287_6_1, sec_r001287_7_1, pub_r001287_8_1, sec_r001287_6_2, sec_r001287_7_2, pub_r001287_8_2);
  int helper_flow_7_1 = fn_R001287_8713_7(sec_r001287_7_1, pub_r001287_8_1, pub_r001287_9_1);
  int helper_flow_7_2 = fn_R001287_8713_7(sec_r001287_7_2, pub_r001287_8_2, pub_r001287_9_2);
  fn_R001287_8713_7_2(sec_r001287_7_1, pub_r001287_8_1, pub_r001287_9_1, sec_r001287_7_2, pub_r001287_8_2, pub_r001287_9_2);
  int stage_v_0_1 = (sec_r001287_2_1 ^ pub_r001287_2_1) & 63;
  int stage_v_0_2 = (sec_r001287_2_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_0_1 & 1) != 0)
  {
    if ((sec_r001287_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_0_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_0_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_0_1 * 2)) & 255;
  }
  if ((stage_v_0_2 & 1) != 0)
  {
    if ((sec_r001287_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_0_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_0_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_0_2 * 2)) & 255;
  }
  int stage_v_1_1 = (helper_flow_3_1 ^ pub_r001287_5_1) & 63;
  int stage_v_1_2 = (helper_flow_3_2 ^ pub_r001287_5_2) & 63;
  if ((stage_v_1_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_1_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_1_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_1_1 * 2)) & 255;
  }
  if ((stage_v_1_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_1_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_1_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_1_2 * 2)) & 255;
  }
  int stage_v_2_1 = (sec_r001287_3_1 ^ pub_r001287_6_1) & 63;
  int stage_v_2_2 = (sec_r001287_3_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_2_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_2_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_2_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_2_1 * 2)) & 255;
  }
  if ((stage_v_2_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_2_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_2_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_2_2 * 2)) & 255;
  }
  int stage_v_3_1 = (sec_r001287_4_1 ^ pub_r001287_2_1) & 63;
  int stage_v_3_2 = (sec_r001287_4_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_3_1 & 1) != 0)
  {
    if ((sec_r001287_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_3_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_3_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_3_1 * 2)) & 255;
  }
  if ((stage_v_3_2 & 1) != 0)
  {
    if ((sec_r001287_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_3_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_3_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_3_2 * 2)) & 255;
  }
  int stage_v_4_1 = (helper_flow_0_1 ^ pub_r001287_9_1) & 63;
  int stage_v_4_2 = (helper_flow_0_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_4_1 & 1) != 0)
  {
    if ((sec_r001287_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_4_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_4_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_4_1 * 2)) & 255;
  }
  if ((stage_v_4_2 & 1) != 0)
  {
    if ((sec_r001287_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_4_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_4_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_4_2 * 2)) & 255;
  }
  int stage_v_5_1 = (helper_flow_2_1 ^ pub_r001287_7_1) & 63;
  int stage_v_5_2 = (helper_flow_2_2 ^ pub_r001287_7_2) & 63;
  if ((stage_v_5_1 & 1) != 0)
  {
    if ((sec_r001287_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_5_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_5_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_5_1 * 2)) & 255;
  }
  if ((stage_v_5_2 & 1) != 0)
  {
    if ((sec_r001287_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_5_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_5_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_5_2 * 2)) & 255;
  }
  int stage_v_6_1 = (sec_r001287_16_1 ^ pub_r001287_2_1) & 63;
  int stage_v_6_2 = (sec_r001287_16_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_6_1 & 1) != 0)
  {
    if ((sec_r001287_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_6_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_6_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_6_1 * 2)) & 255;
  }
  if ((stage_v_6_2 & 1) != 0)
  {
    if ((sec_r001287_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_6_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_6_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_6_2 * 2)) & 255;
  }
  int stage_v_7_1 = (sec_r001287_0_1 ^ pub_r001287_0_1) & 63;
  int stage_v_7_2 = (sec_r001287_0_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_7_1 & 1) != 0)
  {
    if ((sec_r001287_17_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_7_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_7_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_7_1 * 2)) & 255;
  }
  if ((stage_v_7_2 & 1) != 0)
  {
    if ((sec_r001287_17_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_7_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_7_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_7_2 * 2)) & 255;
  }
  int stage_v_8_1 = ((pub_r001287_2_1 * 2) + 48) & 63;
  int stage_v_8_2 = ((pub_r001287_2_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = (sec_r001287_1_1 ^ pub_r001287_0_1) & 63;
  int stage_v_9_2 = (sec_r001287_1_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_9_1 & 1) != 0)
  {
    if ((sec_r001287_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_9_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_9_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_9_1 * 2)) & 255;
  }
  if ((stage_v_9_2 & 1) != 0)
  {
    if ((sec_r001287_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_9_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_9_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_9_2 * 2)) & 255;
  }
  int stage_v_10_1 = ((pub_r001287_11_1 * 2) + 35) & 63;
  int stage_v_10_2 = ((pub_r001287_11_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_10_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_10_2) & 127;
  int stage_v_11_1 = (sec_r001287_0_1 ^ pub_r001287_16_1) & 63;
  int stage_v_11_2 = (sec_r001287_0_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_11_1 & 1) != 0)
  {
    if ((helper_flow_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_11_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_11_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_11_1 * 2)) & 255;
  }
  if ((stage_v_11_2 & 1) != 0)
  {
    if ((helper_flow_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_11_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_11_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_11_2 * 2)) & 255;
  }
  int stage_v_12_1 = (helper_flow_6_1 ^ pub_r001287_10_1) & 63;
  int stage_v_12_2 = (helper_flow_6_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_12_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_12_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_12_1 * 2)) & 255;
  }
  if ((stage_v_12_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_12_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_12_2 * 2)) & 255;
  }
  int stage_v_13_1 = ((pub_r001287_15_1 * 2) + 12) & 63;
  int stage_v_13_2 = ((pub_r001287_15_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001287_13_1 * 2) + 21) & 63;
  int stage_v_14_2 = ((pub_r001287_13_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001287_7_1 * 2) + 17) & 63;
  int stage_v_15_2 = ((pub_r001287_7_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = ((pub_r001287_2_1 * 2) + 14) & 63;
  int stage_v_16_2 = ((pub_r001287_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_16_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_16_2) & 127;
  int stage_v_17_1 = (stage_v_3_1 ^ pub_r001287_11_1) & 63;
  int stage_v_17_2 = (stage_v_3_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_17_1 & 1) != 0)
  {
    if ((sec_r001287_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_17_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_17_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_17_1 * 2)) & 255;
  }
  if ((stage_v_17_2 & 1) != 0)
  {
    if ((sec_r001287_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_17_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_17_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_17_2 * 2)) & 255;
  }
  int stage_v_18_1 = ((pub_r001287_11_1 * 2) + 27) & 63;
  int stage_v_18_2 = ((pub_r001287_11_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_18_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_18_2) & 127;
  int stage_v_19_1 = (helper_flow_3_1 ^ pub_r001287_11_1) & 63;
  int stage_v_19_2 = (helper_flow_3_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_19_1 & 1) != 0)
  {
    if ((sec_r001287_16_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_19_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_19_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_19_1 * 2)) & 255;
  }
  if ((stage_v_19_2 & 1) != 0)
  {
    if ((sec_r001287_16_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_19_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_19_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_19_2 * 2)) & 255;
  }
  int stage_v_20_1 = (helper_flow_3_1 ^ pub_r001287_10_1) & 63;
  int stage_v_20_2 = (helper_flow_3_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_20_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_20_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_20_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_20_1 * 2)) & 255;
  }
  if ((stage_v_20_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_20_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_20_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_20_2 * 2)) & 255;
  }
  int stage_v_21_1 = (helper_flow_6_1 ^ pub_r001287_5_1) & 63;
  int stage_v_21_2 = (helper_flow_6_2 ^ pub_r001287_5_2) & 63;
  if ((stage_v_21_1 & 1) != 0)
  {
    if ((sec_r001287_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_21_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_21_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_21_1 * 2)) & 255;
  }
  if ((stage_v_21_2 & 1) != 0)
  {
    if ((sec_r001287_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_21_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_21_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_21_2 * 2)) & 255;
  }
  int stage_v_22_1 = (sec_r001287_11_1 ^ pub_r001287_9_1) & 63;
  int stage_v_22_2 = (sec_r001287_11_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_22_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_22_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_22_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_22_1 * 2)) & 255;
  }
  if ((stage_v_22_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_22_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_22_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_22_2 * 2)) & 255;
  }
  int stage_v_23_1 = ((pub_r001287_8_1 * 2) + 50) & 63;
  int stage_v_23_2 = ((pub_r001287_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = (helper_flow_7_1 ^ pub_r001287_8_1) & 63;
  int stage_v_24_2 = (helper_flow_7_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_24_1 & 1) != 0)
  {
    if ((sec_r001287_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_24_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_24_1 * 2)) & 255;
  }
  if ((stage_v_24_2 & 1) != 0)
  {
    if ((sec_r001287_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_24_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_24_2 * 2)) & 255;
  }
  int stage_v_25_1 = (sec_r001287_6_1 ^ pub_r001287_14_1) & 63;
  int stage_v_25_2 = (sec_r001287_6_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_25_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_25_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_25_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_25_1 * 2)) & 255;
  }
  if ((stage_v_25_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_25_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_25_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_25_2 * 2)) & 255;
  }
  int stage_v_26_1 = (stage_v_21_1 ^ pub_r001287_3_1) & 63;
  int stage_v_26_2 = (stage_v_21_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_26_1 & 1) != 0)
  {
    if ((sec_r001287_18_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_26_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_26_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_26_1 * 2)) & 255;
  }
  if ((stage_v_26_2 & 1) != 0)
  {
    if ((sec_r001287_18_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_26_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_26_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_26_2 * 2)) & 255;
  }
  int stage_v_27_1 = (sec_r001287_18_1 ^ pub_r001287_3_1) & 63;
  int stage_v_27_2 = (sec_r001287_18_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_27_1 & 1) != 0)
  {
    if ((sec_r001287_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_27_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_27_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_27_1 * 2)) & 255;
  }
  if ((stage_v_27_2 & 1) != 0)
  {
    if ((sec_r001287_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_27_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_27_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_27_2 * 2)) & 255;
  }
  int stage_v_28_1 = ((pub_r001287_3_1 * 2) + 42) & 63;
  int stage_v_28_2 = ((pub_r001287_3_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = ((pub_r001287_8_1 * 2) + 13) & 63;
  int stage_v_29_2 = ((pub_r001287_8_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  int stage_v_30_1 = (sec_r001287_1_1 ^ pub_r001287_12_1) & 63;
  int stage_v_30_2 = (sec_r001287_1_2 ^ pub_r001287_12_2) & 63;
  if ((stage_v_30_1 & 1) != 0)
  {
    if ((stage_v_2_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_30_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_30_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_30_1 * 2)) & 255;
  }
  if ((stage_v_30_2 & 1) != 0)
  {
    if ((stage_v_2_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_30_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_30_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_30_2 * 2)) & 255;
  }
  int stage_v_31_1 = (stage_v_4_1 ^ pub_r001287_11_1) & 63;
  int stage_v_31_2 = (stage_v_4_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_31_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_31_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_31_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_31_1 * 2)) & 255;
  }
  if ((stage_v_31_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_31_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_31_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_31_2 * 2)) & 255;
  }
  int stage_v_32_1 = (sec_r001287_18_1 ^ pub_r001287_11_1) & 63;
  int stage_v_32_2 = (sec_r001287_18_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_32_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_32_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_32_1 * 2)) & 255;
  }
  if ((stage_v_32_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_32_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_32_2 * 2)) & 255;
  }
  int stage_v_33_1 = (sec_r001287_5_1 ^ pub_r001287_4_1) & 63;
  int stage_v_33_2 = (sec_r001287_5_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_33_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_33_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_33_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_33_1 * 2)) & 255;
  }
  if ((stage_v_33_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_33_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_33_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_33_2 * 2)) & 255;
  }
  int stage_v_34_1 = (stage_v_3_1 ^ pub_r001287_0_1) & 63;
  int stage_v_34_2 = (stage_v_3_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_34_1 & 1) != 0)
  {
    if ((sec_r001287_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_34_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_34_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_34_1 * 2)) & 255;
  }
  if ((stage_v_34_2 & 1) != 0)
  {
    if ((sec_r001287_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_34_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_34_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_34_2 * 2)) & 255;
  }
  int stage_v_35_1 = ((pub_r001287_15_1 * 2) + 21) & 63;
  int stage_v_35_2 = ((pub_r001287_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = (stage_v_2_1 ^ pub_r001287_8_1) & 63;
  int stage_v_36_2 = (stage_v_2_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_36_1 & 1) != 0)
  {
    if ((stage_v_31_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_36_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_36_1 * 2)) & 255;
  }
  if ((stage_v_36_2 & 1) != 0)
  {
    if ((stage_v_31_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_36_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_36_2 * 2)) & 255;
  }
  int stage_v_37_1 = (stage_v_34_1 ^ pub_r001287_14_1) & 63;
  int stage_v_37_2 = (stage_v_34_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_37_1 & 1) != 0)
  {
    if ((sec_r001287_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_37_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_37_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_37_1 * 2)) & 255;
  }
  if ((stage_v_37_2 & 1) != 0)
  {
    if ((sec_r001287_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_37_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_37_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_37_2 * 2)) & 255;
  }
  int stage_v_38_1 = ((pub_r001287_2_1 * 2) + 34) & 63;
  int stage_v_38_2 = ((pub_r001287_2_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (stage_v_24_1 ^ pub_r001287_14_1) & 63;
  int stage_v_39_2 = (stage_v_24_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_39_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_39_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_39_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_39_1 * 2)) & 255;
  }
  if ((stage_v_39_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_39_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_39_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_39_2 * 2)) & 255;
  }
  int stage_v_40_1 = (sec_r001287_5_1 ^ pub_r001287_11_1) & 63;
  int stage_v_40_2 = (sec_r001287_5_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_40_1 & 1) != 0)
  {
    if ((stage_v_0_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_40_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_40_1 * 2)) & 255;
  }
  if ((stage_v_40_2 & 1) != 0)
  {
    if ((stage_v_0_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_40_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_40_2 * 2)) & 255;
  }
  int stage_v_41_1 = ((pub_r001287_2_1 * 2) + 15) & 63;
  int stage_v_41_2 = ((pub_r001287_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = (stage_v_26_1 ^ pub_r001287_13_1) & 63;
  int stage_v_42_2 = (stage_v_26_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_42_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_42_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_42_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_42_1 * 2)) & 255;
  }
  if ((stage_v_42_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_42_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_42_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_42_2 * 2)) & 255;
  }
  int stage_v_43_1 = ((pub_r001287_9_1 * 2) + 20) & 63;
  int stage_v_43_2 = ((pub_r001287_9_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = (sec_r001287_17_1 ^ pub_r001287_1_1) & 63;
  int stage_v_44_2 = (sec_r001287_17_2 ^ pub_r001287_1_2) & 63;
  if ((stage_v_44_1 & 1) != 0)
  {
    if ((sec_r001287_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_44_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_44_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_44_1 * 2)) & 255;
  }
  if ((stage_v_44_2 & 1) != 0)
  {
    if ((sec_r001287_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_44_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_44_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_44_2 * 2)) & 255;
  }
  int stage_v_45_1 = ((pub_r001287_7_1 * 2) + 32) & 63;
  int stage_v_45_2 = ((pub_r001287_7_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_45_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_45_2) & 127;
  int stage_v_46_1 = (helper_flow_1_1 ^ pub_r001287_7_1) & 63;
  int stage_v_46_2 = (helper_flow_1_2 ^ pub_r001287_7_2) & 63;
  if ((stage_v_46_1 & 1) != 0)
  {
    if ((sec_r001287_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_46_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_46_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_46_1 * 2)) & 255;
  }
  if ((stage_v_46_2 & 1) != 0)
  {
    if ((sec_r001287_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_46_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_46_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_46_2 * 2)) & 255;
  }
  int stage_v_47_1 = (stage_v_32_1 ^ pub_r001287_3_1) & 63;
  int stage_v_47_2 = (stage_v_32_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_47_1 & 1) != 0)
  {
    if ((stage_v_40_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_47_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_47_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_47_1 * 2)) & 255;
  }
  if ((stage_v_47_2 & 1) != 0)
  {
    if ((stage_v_40_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_47_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_47_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_47_2 * 2)) & 255;
  }
  int stage_v_48_1 = (sec_r001287_14_1 ^ pub_r001287_8_1) & 63;
  int stage_v_48_2 = (sec_r001287_14_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_48_1 & 1) != 0)
  {
    if ((sec_r001287_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_48_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_48_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_48_1 * 2)) & 255;
  }
  if ((stage_v_48_2 & 1) != 0)
  {
    if ((sec_r001287_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_48_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_48_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_48_2 * 2)) & 255;
  }
  int stage_v_49_1 = (helper_flow_0_1 ^ pub_r001287_8_1) & 63;
  int stage_v_49_2 = (helper_flow_0_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_49_1 & 1) != 0)
  {
    if ((helper_flow_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_49_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_49_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_49_1 * 2)) & 255;
  }
  if ((stage_v_49_2 & 1) != 0)
  {
    if ((helper_flow_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_49_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_49_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_49_2 * 2)) & 255;
  }
  int stage_v_50_1 = (helper_flow_4_1 ^ pub_r001287_9_1) & 63;
  int stage_v_50_2 = (helper_flow_4_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_50_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_50_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_50_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_50_1 * 2)) & 255;
  }
  if ((stage_v_50_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_50_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_50_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_50_2 * 2)) & 255;
  }
  int stage_v_51_1 = (stage_v_48_1 ^ pub_r001287_14_1) & 63;
  int stage_v_51_2 = (stage_v_48_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_51_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_51_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_51_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_51_1 * 2)) & 255;
  }
  if ((stage_v_51_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_51_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_51_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_51_2 * 2)) & 255;
  }
  int stage_v_52_1 = (stage_v_17_1 ^ pub_r001287_11_1) & 63;
  int stage_v_52_2 = (stage_v_17_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_52_1 & 1) != 0)
  {
    if ((sec_r001287_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_52_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_52_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_52_1 * 2)) & 255;
  }
  if ((stage_v_52_2 & 1) != 0)
  {
    if ((sec_r001287_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_52_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_52_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_52_2 * 2)) & 255;
  }
  int stage_v_53_1 = ((pub_r001287_13_1 * 2) + 11) & 63;
  int stage_v_53_2 = ((pub_r001287_13_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = (stage_v_22_1 ^ pub_r001287_15_1) & 63;
  int stage_v_54_2 = (stage_v_22_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_54_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_54_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_54_1 * 2)) & 255;
  }
  if ((stage_v_54_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_54_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_54_2 * 2)) & 255;
  }
  int stage_v_55_1 = (sec_r001287_7_1 ^ pub_r001287_1_1) & 63;
  int stage_v_55_2 = (sec_r001287_7_2 ^ pub_r001287_1_2) & 63;
  if ((stage_v_55_1 & 1) != 0)
  {
    if ((sec_r001287_14_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_55_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_55_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_55_1 * 2)) & 255;
  }
  if ((stage_v_55_2 & 1) != 0)
  {
    if ((sec_r001287_14_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_55_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_55_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_55_2 * 2)) & 255;
  }
  int stage_v_56_1 = ((pub_r001287_5_1 * 2) + 16) & 63;
  int stage_v_56_2 = ((pub_r001287_5_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = (sec_r001287_3_1 ^ pub_r001287_2_1) & 63;
  int stage_v_57_2 = (sec_r001287_3_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_57_1 & 1) != 0)
  {
    if ((stage_v_33_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_57_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_57_1 * 2)) & 255;
  }
  if ((stage_v_57_2 & 1) != 0)
  {
    if ((stage_v_33_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_57_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_57_2 * 2)) & 255;
  }
  int stage_v_58_1 = (helper_flow_7_1 ^ pub_r001287_6_1) & 63;
  int stage_v_58_2 = (helper_flow_7_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_58_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_58_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_58_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_58_1 * 2)) & 255;
  }
  if ((stage_v_58_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_58_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_58_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_58_2 * 2)) & 255;
  }
  int stage_v_59_1 = ((pub_r001287_4_1 * 2) + 15) & 63;
  int stage_v_59_2 = ((pub_r001287_4_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = (stage_v_17_1 ^ pub_r001287_10_1) & 63;
  int stage_v_60_2 = (stage_v_17_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_60_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_60_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_60_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_60_1 * 2)) & 255;
  }
  if ((stage_v_60_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_60_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_60_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_60_2 * 2)) & 255;
  }
  int stage_v_61_1 = (sec_r001287_16_1 ^ pub_r001287_2_1) & 63;
  int stage_v_61_2 = (sec_r001287_16_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_61_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_61_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_61_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_61_1 * 2)) & 255;
  }
  if ((stage_v_61_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_61_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_61_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_61_2 * 2)) & 255;
  }
  int stage_v_62_1 = (stage_v_25_1 ^ pub_r001287_3_1) & 63;
  int stage_v_62_2 = (stage_v_25_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_62_1 & 1) != 0)
  {
    if ((sec_r001287_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_62_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_62_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_62_1 * 2)) & 255;
  }
  if ((stage_v_62_2 & 1) != 0)
  {
    if ((sec_r001287_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_62_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_62_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_62_2 * 2)) & 255;
  }
  int stage_v_63_1 = ((pub_r001287_10_1 * 2) + 17) & 63;
  int stage_v_63_2 = ((pub_r001287_10_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_63_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_63_2) & 127;
  int stage_v_64_1 = ((pub_r001287_16_1 * 2) + 9) & 63;
  int stage_v_64_2 = ((pub_r001287_16_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_64_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_64_2) & 127;
  int stage_v_65_1 = ((pub_r001287_14_1 * 2) + 10) & 63;
  int stage_v_65_2 = ((pub_r001287_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001287_0_1 * 2) + 32) & 63;
  int stage_v_66_2 = ((pub_r001287_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = ((pub_r001287_10_1 * 2) + 16) & 63;
  int stage_v_67_2 = ((pub_r001287_10_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_67_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_67_2) & 127;
  int stage_v_68_1 = ((pub_r001287_5_1 * 2) + 27) & 63;
  int stage_v_68_2 = ((pub_r001287_5_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_68_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_68_2) & 127;
  int stage_v_69_1 = (stage_v_39_1 ^ pub_r001287_6_1) & 63;
  int stage_v_69_2 = (stage_v_39_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_69_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_69_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_69_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_69_1 * 2)) & 255;
  }
  if ((stage_v_69_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_69_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_69_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_69_2 * 2)) & 255;
  }
  int stage_v_70_1 = ((pub_r001287_7_1 * 2) + 11) & 63;
  int stage_v_70_2 = ((pub_r001287_7_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_70_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_70_2) & 127;
  int stage_v_71_1 = (stage_v_44_1 ^ pub_r001287_14_1) & 63;
  int stage_v_71_2 = (stage_v_44_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_71_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_71_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_71_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_71_1 * 2)) & 255;
  }
  if ((stage_v_71_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_71_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_71_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_71_2 * 2)) & 255;
  }
  int stage_v_72_1 = (stage_v_54_1 ^ pub_r001287_8_1) & 63;
  int stage_v_72_2 = (stage_v_54_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_72_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_72_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_72_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_72_1 * 2)) & 255;
  }
  if ((stage_v_72_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_72_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_72_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_72_2 * 2)) & 255;
  }
  int stage_v_73_1 = (stage_v_3_1 ^ pub_r001287_11_1) & 63;
  int stage_v_73_2 = (stage_v_3_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_73_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_73_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_73_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_73_1 * 2)) & 255;
  }
  if ((stage_v_73_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_73_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_73_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_73_2 * 2)) & 255;
  }
  int stage_v_74_1 = ((pub_r001287_0_1 * 2) + 37) & 63;
  int stage_v_74_2 = ((pub_r001287_0_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = (stage_v_24_1 ^ pub_r001287_16_1) & 63;
  int stage_v_75_2 = (stage_v_24_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_75_1 & 1) != 0)
  {
    if ((sec_r001287_13_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_75_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_75_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_75_1 * 2)) & 255;
  }
  if ((stage_v_75_2 & 1) != 0)
  {
    if ((sec_r001287_13_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_75_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_75_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_75_2 * 2)) & 255;
  }
  int stage_v_76_1 = (sec_r001287_15_1 ^ pub_r001287_15_1) & 63;
  int stage_v_76_2 = (sec_r001287_15_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_76_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_76_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_76_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_76_1 * 2)) & 255;
  }
  if ((stage_v_76_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_76_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_76_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_76_2 * 2)) & 255;
  }
  int stage_v_77_1 = (helper_flow_7_1 ^ pub_r001287_16_1) & 63;
  int stage_v_77_2 = (helper_flow_7_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_77_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_77_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_77_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_77_1 * 2)) & 255;
  }
  if ((stage_v_77_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_77_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_77_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_77_2 * 2)) & 255;
  }
  int stage_v_78_1 = (stage_v_72_1 ^ pub_r001287_10_1) & 63;
  int stage_v_78_2 = (stage_v_72_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_78_1 & 1) != 0)
  {
    if ((sec_r001287_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_78_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_78_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_78_1 * 2)) & 255;
  }
  if ((stage_v_78_2 & 1) != 0)
  {
    if ((sec_r001287_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_78_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_78_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_78_2 * 2)) & 255;
  }
  int stage_v_79_1 = ((pub_r001287_11_1 * 2) + 21) & 63;
  int stage_v_79_2 = ((pub_r001287_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001287_8_1 * 2) + 27) & 63;
  int stage_v_80_2 = ((pub_r001287_8_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = (sec_r001287_8_1 ^ pub_r001287_8_1) & 63;
  int stage_v_81_2 = (sec_r001287_8_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_81_1 & 1) != 0)
  {
    if ((stage_v_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_81_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_81_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_81_1 * 2)) & 255;
  }
  if ((stage_v_81_2 & 1) != 0)
  {
    if ((stage_v_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_81_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_81_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_81_2 * 2)) & 255;
  }
  int stage_v_82_1 = ((pub_r001287_13_1 * 2) + 34) & 63;
  int stage_v_82_2 = ((pub_r001287_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_82_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_82_2) & 127;
  int stage_v_83_1 = (sec_r001287_9_1 ^ pub_r001287_9_1) & 63;
  int stage_v_83_2 = (sec_r001287_9_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_83_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_83_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_83_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_83_1 * 2)) & 255;
  }
  if ((stage_v_83_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_83_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_83_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_83_2 * 2)) & 255;
  }
  int stage_v_84_1 = (stage_v_26_1 ^ pub_r001287_14_1) & 63;
  int stage_v_84_2 = (stage_v_26_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_84_1 & 1) != 0)
  {
    if ((stage_v_19_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_84_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_84_1 * 2)) & 255;
  }
  if ((stage_v_84_2 & 1) != 0)
  {
    if ((stage_v_19_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_84_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_84_2 * 2)) & 255;
  }
  int stage_v_85_1 = (sec_r001287_17_1 ^ pub_r001287_7_1) & 63;
  int stage_v_85_2 = (sec_r001287_17_2 ^ pub_r001287_7_2) & 63;
  if ((stage_v_85_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_85_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_85_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_85_1 * 2)) & 255;
  }
  if ((stage_v_85_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_85_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_85_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_85_2 * 2)) & 255;
  }
  int stage_v_86_1 = (sec_r001287_20_1 ^ pub_r001287_8_1) & 63;
  int stage_v_86_2 = (sec_r001287_20_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_86_1 & 1) != 0)
  {
    if ((stage_v_81_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_86_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_86_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_86_1 * 2)) & 255;
  }
  if ((stage_v_86_2 & 1) != 0)
  {
    if ((stage_v_81_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_86_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_86_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_86_2 * 2)) & 255;
  }
  int stage_v_87_1 = (stage_v_6_1 ^ pub_r001287_11_1) & 63;
  int stage_v_87_2 = (stage_v_6_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_87_1 & 1) != 0)
  {
    if ((stage_v_21_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_87_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_87_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_87_1 * 2)) & 255;
  }
  if ((stage_v_87_2 & 1) != 0)
  {
    if ((stage_v_21_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_87_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_87_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_87_2 * 2)) & 255;
  }
  int stage_v_88_1 = (stage_v_69_1 ^ pub_r001287_4_1) & 63;
  int stage_v_88_2 = (stage_v_69_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_88_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_88_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_88_1 * 2)) & 255;
  }
  if ((stage_v_88_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_88_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_88_2 * 2)) & 255;
  }
  int stage_v_89_1 = ((pub_r001287_11_1 * 2) + 26) & 63;
  int stage_v_89_2 = ((pub_r001287_11_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = (stage_v_3_1 ^ pub_r001287_13_1) & 63;
  int stage_v_90_2 = (stage_v_3_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_90_1 & 1) != 0)
  {
    if ((stage_v_51_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_90_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_90_1 * 2)) & 255;
  }
  if ((stage_v_90_2 & 1) != 0)
  {
    if ((stage_v_51_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_90_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_90_2 * 2)) & 255;
  }
  int stage_v_91_1 = ((pub_r001287_7_1 * 2) + 43) & 63;
  int stage_v_91_2 = ((pub_r001287_7_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_91_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_91_2) & 127;
  int stage_v_92_1 = ((pub_r001287_16_1 * 2) + 49) & 63;
  int stage_v_92_2 = ((pub_r001287_16_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = (helper_flow_6_1 ^ pub_r001287_1_1) & 63;
  int stage_v_93_2 = (helper_flow_6_2 ^ pub_r001287_1_2) & 63;
  if ((stage_v_93_1 & 1) != 0)
  {
    if ((stage_v_83_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_93_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_93_1 * 2)) & 255;
  }
  if ((stage_v_93_2 & 1) != 0)
  {
    if ((stage_v_83_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_93_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_93_2 * 2)) & 255;
  }
  int stage_v_94_1 = (helper_flow_5_1 ^ pub_r001287_7_1) & 63;
  int stage_v_94_2 = (helper_flow_5_2 ^ pub_r001287_7_2) & 63;
  if ((stage_v_94_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_94_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_94_1 * 2)) & 255;
  }
  if ((stage_v_94_2 & 1) != 0)
  {
    if ((stage_v_61_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_94_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_94_2 * 2)) & 255;
  }
  int stage_v_95_1 = (stage_v_31_1 ^ pub_r001287_7_1) & 63;
  int stage_v_95_2 = (stage_v_31_2 ^ pub_r001287_7_2) & 63;
  if ((stage_v_95_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_95_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_95_1 * 2)) & 255;
  }
  if ((stage_v_95_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_95_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_95_2 * 2)) & 255;
  }
  int stage_v_96_1 = (stage_v_90_1 ^ pub_r001287_10_1) & 63;
  int stage_v_96_2 = (stage_v_90_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_96_1 & 1) != 0)
  {
    if ((stage_v_73_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_96_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_96_1 * 2)) & 255;
  }
  if ((stage_v_96_2 & 1) != 0)
  {
    if ((stage_v_73_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_96_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_96_2 * 2)) & 255;
  }
  int stage_v_97_1 = (stage_v_90_1 ^ pub_r001287_15_1) & 63;
  int stage_v_97_2 = (stage_v_90_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_97_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_97_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_97_1 * 2)) & 255;
  }
  if ((stage_v_97_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_97_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_97_2 * 2)) & 255;
  }
  int stage_v_98_1 = (stage_v_21_1 ^ pub_r001287_11_1) & 63;
  int stage_v_98_2 = (stage_v_21_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_98_1 & 1) != 0)
  {
    if ((stage_v_46_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_98_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_98_1 * 2)) & 255;
  }
  if ((stage_v_98_2 & 1) != 0)
  {
    if ((stage_v_46_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_98_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_98_2 * 2)) & 255;
  }
  int stage_v_99_1 = ((pub_r001287_13_1 * 2) + 5) & 63;
  int stage_v_99_2 = ((pub_r001287_13_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_99_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_99_2) & 127;
  int stage_v_100_1 = (helper_flow_2_1 ^ pub_r001287_13_1) & 63;
  int stage_v_100_2 = (helper_flow_2_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_100_1 & 1) != 0)
  {
    if ((sec_r001287_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_100_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_100_1 * 2)) & 255;
  }
  if ((stage_v_100_2 & 1) != 0)
  {
    if ((sec_r001287_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_100_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_100_2 * 2)) & 255;
  }
  int stage_v_101_1 = (stage_v_4_1 ^ pub_r001287_10_1) & 63;
  int stage_v_101_2 = (stage_v_4_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_101_1 & 1) != 0)
  {
    if ((sec_r001287_15_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_101_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_101_1 * 2)) & 255;
  }
  if ((stage_v_101_2 & 1) != 0)
  {
    if ((sec_r001287_15_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_101_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_101_2 * 2)) & 255;
  }
  int stage_v_102_1 = ((pub_r001287_15_1 * 2) + 41) & 63;
  int stage_v_102_2 = ((pub_r001287_15_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001287_1_1 * 2) + 38) & 63;
  int stage_v_103_2 = ((pub_r001287_1_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (sec_r001287_2_1 ^ pub_r001287_15_1) & 63;
  int stage_v_104_2 = (sec_r001287_2_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_104_1 & 1) != 0)
  {
    if ((stage_v_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_104_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_104_1 * 2)) & 255;
  }
  if ((stage_v_104_2 & 1) != 0)
  {
    if ((stage_v_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_104_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_104_2 * 2)) & 255;
  }
  int stage_v_105_1 = (stage_v_97_1 ^ pub_r001287_11_1) & 63;
  int stage_v_105_2 = (stage_v_97_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_105_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_105_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_105_1 * 2)) & 255;
  }
  if ((stage_v_105_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_105_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_105_2 * 2)) & 255;
  }
  int stage_v_106_1 = (stage_v_24_1 ^ pub_r001287_0_1) & 63;
  int stage_v_106_2 = (stage_v_24_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_106_1 & 1) != 0)
  {
    if ((sec_r001287_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_106_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_106_1 * 2)) & 255;
  }
  if ((stage_v_106_2 & 1) != 0)
  {
    if ((sec_r001287_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_106_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_106_2 * 2)) & 255;
  }
  int stage_v_107_1 = (stage_v_78_1 ^ pub_r001287_15_1) & 63;
  int stage_v_107_2 = (stage_v_78_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_107_1 & 1) != 0)
  {
    if ((stage_v_42_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_107_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_107_1 * 2)) & 255;
  }
  if ((stage_v_107_2 & 1) != 0)
  {
    if ((stage_v_42_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_107_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_107_2 * 2)) & 255;
  }
  int stage_v_108_1 = ((pub_r001287_3_1 * 2) + 6) & 63;
  int stage_v_108_2 = ((pub_r001287_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001287_4_1 * 2) + 41) & 63;
  int stage_v_109_2 = ((pub_r001287_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001287_16_1 * 2) + 21) & 63;
  int stage_v_110_2 = ((pub_r001287_16_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = (stage_v_50_1 ^ pub_r001287_4_1) & 63;
  int stage_v_111_2 = (stage_v_50_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_111_1 & 1) != 0)
  {
    if ((stage_v_25_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_111_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_111_1 * 2)) & 255;
  }
  if ((stage_v_111_2 & 1) != 0)
  {
    if ((stage_v_25_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_111_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_111_2 * 2)) & 255;
  }
  int stage_v_112_1 = (stage_v_100_1 ^ pub_r001287_14_1) & 63;
  int stage_v_112_2 = (stage_v_100_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_112_1 & 1) != 0)
  {
    if ((stage_v_97_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_112_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_112_1 * 2)) & 255;
  }
  if ((stage_v_112_2 & 1) != 0)
  {
    if ((stage_v_97_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_112_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_112_2 * 2)) & 255;
  }
  int stage_v_113_1 = ((pub_r001287_13_1 * 2) + 19) & 63;
  int stage_v_113_2 = ((pub_r001287_13_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_113_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_113_2) & 127;
  int stage_v_114_1 = (sec_r001287_5_1 ^ pub_r001287_2_1) & 63;
  int stage_v_114_2 = (sec_r001287_5_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_114_1 & 1) != 0)
  {
    if ((sec_r001287_8_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_114_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_114_1 * 2)) & 255;
  }
  if ((stage_v_114_2 & 1) != 0)
  {
    if ((sec_r001287_8_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_114_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_114_2 * 2)) & 255;
  }
  int stage_v_115_1 = (sec_r001287_3_1 ^ pub_r001287_16_1) & 63;
  int stage_v_115_2 = (sec_r001287_3_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_115_1 & 1) != 0)
  {
    if ((stage_v_58_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_115_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_115_1 * 2)) & 255;
  }
  if ((stage_v_115_2 & 1) != 0)
  {
    if ((stage_v_58_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_115_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_115_2 * 2)) & 255;
  }
  int stage_v_116_1 = ((pub_r001287_5_1 * 2) + 43) & 63;
  int stage_v_116_2 = ((pub_r001287_5_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001287_2_1 * 2) + 49) & 63;
  int stage_v_117_2 = ((pub_r001287_2_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001287_2_1 * 2) + 43) & 63;
  int stage_v_118_2 = ((pub_r001287_2_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = (sec_r001287_16_1 ^ pub_r001287_5_1) & 63;
  int stage_v_119_2 = (sec_r001287_16_2 ^ pub_r001287_5_2) & 63;
  if ((stage_v_119_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_119_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_119_1 * 2)) & 255;
  }
  if ((stage_v_119_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_119_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_119_2 * 2)) & 255;
  }
  int stage_v_120_1 = (helper_flow_2_1 ^ pub_r001287_12_1) & 63;
  int stage_v_120_2 = (helper_flow_2_2 ^ pub_r001287_12_2) & 63;
  if ((stage_v_120_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_120_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_120_1 * 2)) & 255;
  }
  if ((stage_v_120_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_120_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_120_2 * 2)) & 255;
  }
  int stage_v_121_1 = ((pub_r001287_13_1 * 2) + 36) & 63;
  int stage_v_121_2 = ((pub_r001287_13_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = (stage_v_71_1 ^ pub_r001287_3_1) & 63;
  int stage_v_122_2 = (stage_v_71_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_122_1 & 1) != 0)
  {
    if ((stage_v_47_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_122_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_122_1 * 2)) & 255;
  }
  if ((stage_v_122_2 & 1) != 0)
  {
    if ((stage_v_47_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_122_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_122_2 * 2)) & 255;
  }
  int stage_v_123_1 = (stage_v_27_1 ^ pub_r001287_15_1) & 63;
  int stage_v_123_2 = (stage_v_27_2 ^ pub_r001287_15_2) & 63;
  if ((stage_v_123_1 & 1) != 0)
  {
    if ((stage_v_106_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_123_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_123_1 * 2)) & 255;
  }
  if ((stage_v_123_2 & 1) != 0)
  {
    if ((stage_v_106_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_123_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_123_2 * 2)) & 255;
  }
  int stage_v_124_1 = (stage_v_32_1 ^ pub_r001287_16_1) & 63;
  int stage_v_124_2 = (stage_v_32_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_124_1 & 1) != 0)
  {
    if ((stage_v_5_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_124_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_124_1 * 2)) & 255;
  }
  if ((stage_v_124_2 & 1) != 0)
  {
    if ((stage_v_5_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_124_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_124_2 * 2)) & 255;
  }
  int stage_v_125_1 = (helper_flow_2_1 ^ pub_r001287_3_1) & 63;
  int stage_v_125_2 = (helper_flow_2_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_125_1 & 1) != 0)
  {
    if ((stage_v_26_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_125_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_125_1 * 2)) & 255;
  }
  if ((stage_v_125_2 & 1) != 0)
  {
    if ((stage_v_26_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_125_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_125_2 * 2)) & 255;
  }
  int stage_v_126_1 = (stage_v_95_1 ^ pub_r001287_4_1) & 63;
  int stage_v_126_2 = (stage_v_95_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_126_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_126_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_126_1 * 2)) & 255;
  }
  if ((stage_v_126_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_126_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_126_2 * 2)) & 255;
  }
  int stage_v_127_1 = ((pub_r001287_4_1 * 2) + 44) & 63;
  int stage_v_127_2 = ((pub_r001287_4_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = (stage_v_24_1 ^ pub_r001287_5_1) & 63;
  int stage_v_128_2 = (stage_v_24_2 ^ pub_r001287_5_2) & 63;
  if ((stage_v_128_1 & 1) != 0)
  {
    if ((stage_v_124_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_128_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_128_1 * 2)) & 255;
  }
  if ((stage_v_128_2 & 1) != 0)
  {
    if ((stage_v_124_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_128_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_128_2 * 2)) & 255;
  }
  int stage_v_129_1 = (stage_v_40_1 ^ pub_r001287_8_1) & 63;
  int stage_v_129_2 = (stage_v_40_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_129_1 & 1) != 0)
  {
    if ((stage_v_7_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_129_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_129_1 * 2)) & 255;
  }
  if ((stage_v_129_2 & 1) != 0)
  {
    if ((stage_v_7_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_129_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_129_2 * 2)) & 255;
  }
  int stage_v_130_1 = ((pub_r001287_1_1 * 2) + 16) & 63;
  int stage_v_130_2 = ((pub_r001287_1_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_130_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_130_2) & 127;
  int stage_v_131_1 = ((pub_r001287_0_1 * 2) + 22) & 63;
  int stage_v_131_2 = ((pub_r001287_0_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = (stage_v_88_1 ^ pub_r001287_4_1) & 63;
  int stage_v_132_2 = (stage_v_88_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_132_1 & 1) != 0)
  {
    if ((sec_r001287_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_132_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_132_1 * 2)) & 255;
  }
  if ((stage_v_132_2 & 1) != 0)
  {
    if ((sec_r001287_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_132_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_132_2 * 2)) & 255;
  }
  int stage_v_133_1 = (stage_v_98_1 ^ pub_r001287_8_1) & 63;
  int stage_v_133_2 = (stage_v_98_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_133_1 & 1) != 0)
  {
    if ((stage_v_49_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_133_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_133_1 * 2)) & 255;
  }
  if ((stage_v_133_2 & 1) != 0)
  {
    if ((stage_v_49_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_133_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_133_2 * 2)) & 255;
  }
  int stage_v_134_1 = ((pub_r001287_4_1 * 2) + 45) & 63;
  int stage_v_134_2 = ((pub_r001287_4_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001287_7_1 * 2) + 10) & 63;
  int stage_v_135_2 = ((pub_r001287_7_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = (stage_v_22_1 ^ pub_r001287_11_1) & 63;
  int stage_v_136_2 = (stage_v_22_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_136_1 & 1) != 0)
  {
    if ((stage_v_60_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_136_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_136_1 * 2)) & 255;
  }
  if ((stage_v_136_2 & 1) != 0)
  {
    if ((stage_v_60_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_136_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_136_2 * 2)) & 255;
  }
  int stage_v_137_1 = (stage_v_0_1 ^ pub_r001287_14_1) & 63;
  int stage_v_137_2 = (stage_v_0_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_137_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_137_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_137_1 * 2)) & 255;
  }
  if ((stage_v_137_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_137_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_137_2 * 2)) & 255;
  }
  int stage_v_138_1 = (sec_r001287_18_1 ^ pub_r001287_3_1) & 63;
  int stage_v_138_2 = (sec_r001287_18_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_138_1 & 1) != 0)
  {
    if ((stage_v_39_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_138_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_138_1 * 2)) & 255;
  }
  if ((stage_v_138_2 & 1) != 0)
  {
    if ((stage_v_39_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_138_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_138_2 * 2)) & 255;
  }
  int stage_v_139_1 = (sec_r001287_18_1 ^ pub_r001287_12_1) & 63;
  int stage_v_139_2 = (sec_r001287_18_2 ^ pub_r001287_12_2) & 63;
  if ((stage_v_139_1 & 1) != 0)
  {
    if ((stage_v_87_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_139_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_139_1 * 2)) & 255;
  }
  if ((stage_v_139_2 & 1) != 0)
  {
    if ((stage_v_87_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_139_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_139_2 * 2)) & 255;
  }
  int stage_v_140_1 = (sec_r001287_15_1 ^ pub_r001287_9_1) & 63;
  int stage_v_140_2 = (sec_r001287_15_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_140_1 & 1) != 0)
  {
    if ((stage_v_61_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_140_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_140_1 * 2)) & 255;
  }
  if ((stage_v_140_2 & 1) != 0)
  {
    if ((stage_v_61_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_140_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_140_2 * 2)) & 255;
  }
  int stage_v_141_1 = (helper_flow_4_1 ^ pub_r001287_13_1) & 63;
  int stage_v_141_2 = (helper_flow_4_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_141_1 & 1) != 0)
  {
    if ((stage_v_77_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_141_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_141_1 * 2)) & 255;
  }
  if ((stage_v_141_2 & 1) != 0)
  {
    if ((stage_v_77_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_141_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_141_2 * 2)) & 255;
  }
  int stage_v_142_1 = (stage_v_77_1 ^ pub_r001287_6_1) & 63;
  int stage_v_142_2 = (stage_v_77_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_142_1 & 1) != 0)
  {
    if ((stage_v_34_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_142_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_142_1 * 2)) & 255;
  }
  if ((stage_v_142_2 & 1) != 0)
  {
    if ((stage_v_34_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_142_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_142_2 * 2)) & 255;
  }
  int stage_v_143_1 = (stage_v_22_1 ^ pub_r001287_8_1) & 63;
  int stage_v_143_2 = (stage_v_22_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_143_1 & 1) != 0)
  {
    if ((stage_v_44_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_143_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_143_1 * 2)) & 255;
  }
  if ((stage_v_143_2 & 1) != 0)
  {
    if ((stage_v_44_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_143_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_143_2 * 2)) & 255;
  }
  int stage_v_144_1 = (sec_r001287_1_1 ^ pub_r001287_11_1) & 63;
  int stage_v_144_2 = (sec_r001287_1_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_144_1 & 1) != 0)
  {
    if ((stage_v_105_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_144_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_144_1 * 2)) & 255;
  }
  if ((stage_v_144_2 & 1) != 0)
  {
    if ((stage_v_105_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_144_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_144_2 * 2)) & 255;
  }
  int stage_v_145_1 = (stage_v_124_1 ^ pub_r001287_3_1) & 63;
  int stage_v_145_2 = (stage_v_124_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_145_1 & 1) != 0)
  {
    if ((sec_r001287_20_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_145_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_145_1 * 2)) & 255;
  }
  if ((stage_v_145_2 & 1) != 0)
  {
    if ((sec_r001287_20_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_145_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_145_2 * 2)) & 255;
  }
  int stage_v_146_1 = (sec_r001287_19_1 ^ pub_r001287_5_1) & 63;
  int stage_v_146_2 = (sec_r001287_19_2 ^ pub_r001287_5_2) & 63;
  if ((stage_v_146_1 & 1) != 0)
  {
    if ((stage_v_76_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_146_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_146_1 * 2)) & 255;
  }
  if ((stage_v_146_2 & 1) != 0)
  {
    if ((stage_v_76_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_146_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_146_2 * 2)) & 255;
  }
  int stage_v_147_1 = (stage_v_2_1 ^ pub_r001287_6_1) & 63;
  int stage_v_147_2 = (stage_v_2_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_147_1 & 1) != 0)
  {
    if ((stage_v_126_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_147_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_147_1 * 2)) & 255;
  }
  if ((stage_v_147_2 & 1) != 0)
  {
    if ((stage_v_126_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_147_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_147_2 * 2)) & 255;
  }
  int stage_v_148_1 = ((pub_r001287_10_1 * 2) + 6) & 63;
  int stage_v_148_2 = ((pub_r001287_10_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001287_8_1 * 2) + 38) & 63;
  int stage_v_149_2 = ((pub_r001287_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (stage_v_76_1 ^ pub_r001287_2_1) & 63;
  int stage_v_150_2 = (stage_v_76_2 ^ pub_r001287_2_2) & 63;
  if ((stage_v_150_1 & 1) != 0)
  {
    if ((stage_v_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_150_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_150_1 * 2)) & 255;
  }
  if ((stage_v_150_2 & 1) != 0)
  {
    if ((stage_v_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_150_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_150_2 * 2)) & 255;
  }
  int stage_v_151_1 = (stage_v_12_1 ^ pub_r001287_11_1) & 63;
  int stage_v_151_2 = (stage_v_12_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_151_1 & 1) != 0)
  {
    if ((stage_v_32_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_151_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_151_1 * 2)) & 255;
  }
  if ((stage_v_151_2 & 1) != 0)
  {
    if ((stage_v_32_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_151_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_151_2 * 2)) & 255;
  }
  int stage_v_152_1 = (stage_v_0_1 ^ pub_r001287_8_1) & 63;
  int stage_v_152_2 = (stage_v_0_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_152_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_152_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_152_1 * 2)) & 255;
  }
  if ((stage_v_152_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_152_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_152_2 * 2)) & 255;
  }
  int stage_v_153_1 = (stage_v_9_1 ^ pub_r001287_0_1) & 63;
  int stage_v_153_2 = (stage_v_9_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_153_1 & 1) != 0)
  {
    if ((sec_r001287_10_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_153_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_153_1 * 2)) & 255;
  }
  if ((stage_v_153_2 & 1) != 0)
  {
    if ((sec_r001287_10_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_153_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_153_2 * 2)) & 255;
  }
  int stage_v_154_1 = (stage_v_19_1 ^ pub_r001287_16_1) & 63;
  int stage_v_154_2 = (stage_v_19_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_154_1 & 1) != 0)
  {
    if ((stage_v_12_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_154_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_154_1 * 2)) & 255;
  }
  if ((stage_v_154_2 & 1) != 0)
  {
    if ((stage_v_12_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_154_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_154_2 * 2)) & 255;
  }
  int stage_v_155_1 = (stage_v_78_1 ^ pub_r001287_13_1) & 63;
  int stage_v_155_2 = (stage_v_78_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_155_1 & 1) != 0)
  {
    if ((stage_v_94_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_155_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_155_1 * 2)) & 255;
  }
  if ((stage_v_155_2 & 1) != 0)
  {
    if ((stage_v_94_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_155_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_155_2 * 2)) & 255;
  }
  int stage_v_156_1 = ((pub_r001287_10_1 * 2) + 24) & 63;
  int stage_v_156_2 = ((pub_r001287_10_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (stage_v_40_1 ^ pub_r001287_13_1) & 63;
  int stage_v_157_2 = (stage_v_40_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_157_1 & 1) != 0)
  {
    if ((stage_v_93_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_157_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_157_1 * 2)) & 255;
  }
  if ((stage_v_157_2 & 1) != 0)
  {
    if ((stage_v_93_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_157_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_157_2 * 2)) & 255;
  }
  int stage_v_158_1 = ((pub_r001287_0_1 * 2) + 11) & 63;
  int stage_v_158_2 = ((pub_r001287_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = (helper_flow_7_1 ^ pub_r001287_9_1) & 63;
  int stage_v_159_2 = (helper_flow_7_2 ^ pub_r001287_9_2) & 63;
  if ((stage_v_159_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_159_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_159_1 * 2)) & 255;
  }
  if ((stage_v_159_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_159_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_159_2 * 2)) & 255;
  }
  int stage_v_160_1 = (stage_v_101_1 ^ pub_r001287_3_1) & 63;
  int stage_v_160_2 = (stage_v_101_2 ^ pub_r001287_3_2) & 63;
  if ((stage_v_160_1 & 1) != 0)
  {
    if ((helper_flow_1_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_160_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_160_1 * 2)) & 255;
  }
  if ((stage_v_160_2 & 1) != 0)
  {
    if ((helper_flow_1_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_160_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_160_2 * 2)) & 255;
  }
  int stage_v_161_1 = (stage_v_86_1 ^ pub_r001287_10_1) & 63;
  int stage_v_161_2 = (stage_v_86_2 ^ pub_r001287_10_2) & 63;
  if ((stage_v_161_1 & 1) != 0)
  {
    if ((helper_flow_4_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_161_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_161_1 * 2)) & 255;
  }
  if ((stage_v_161_2 & 1) != 0)
  {
    if ((helper_flow_4_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_161_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_161_2 * 2)) & 255;
  }
  int stage_v_162_1 = (stage_v_143_1 ^ pub_r001287_14_1) & 63;
  int stage_v_162_2 = (stage_v_143_2 ^ pub_r001287_14_2) & 63;
  if ((stage_v_162_1 & 1) != 0)
  {
    if ((stage_v_161_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_162_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_162_1 * 2)) & 255;
  }
  if ((stage_v_162_2 & 1) != 0)
  {
    if ((stage_v_161_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_162_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_162_2 * 2)) & 255;
  }
  int stage_v_163_1 = ((pub_r001287_11_1 * 2) + 29) & 63;
  int stage_v_163_2 = ((pub_r001287_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = (stage_v_61_1 ^ pub_r001287_11_1) & 63;
  int stage_v_164_2 = (stage_v_61_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_164_1 & 1) != 0)
  {
    if ((stage_v_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_164_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_164_1 * 2)) & 255;
  }
  if ((stage_v_164_2 & 1) != 0)
  {
    if ((stage_v_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_164_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_164_2 * 2)) & 255;
  }
  int stage_v_165_1 = (stage_v_26_1 ^ pub_r001287_11_1) & 63;
  int stage_v_165_2 = (stage_v_26_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_165_1 & 1) != 0)
  {
    if ((stage_v_85_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_165_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_165_1 * 2)) & 255;
  }
  if ((stage_v_165_2 & 1) != 0)
  {
    if ((stage_v_85_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_165_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_165_2 * 2)) & 255;
  }
  int stage_v_166_1 = (stage_v_69_1 ^ pub_r001287_6_1) & 63;
  int stage_v_166_2 = (stage_v_69_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_166_1 & 1) != 0)
  {
    if ((stage_v_52_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_166_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_166_1 * 2)) & 255;
  }
  if ((stage_v_166_2 & 1) != 0)
  {
    if ((stage_v_52_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_166_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_166_2 * 2)) & 255;
  }
  int stage_v_167_1 = (stage_v_25_1 ^ pub_r001287_4_1) & 63;
  int stage_v_167_2 = (stage_v_25_2 ^ pub_r001287_4_2) & 63;
  if ((stage_v_167_1 & 1) != 0)
  {
    if ((stage_v_71_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_167_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_167_1 * 2)) & 255;
  }
  if ((stage_v_167_2 & 1) != 0)
  {
    if ((stage_v_71_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_167_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_167_2 * 2)) & 255;
  }
  int stage_v_168_1 = ((pub_r001287_15_1 * 2) + 33) & 63;
  int stage_v_168_2 = ((pub_r001287_15_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_168_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_168_2) & 127;
  int stage_v_169_1 = (stage_v_151_1 ^ pub_r001287_13_1) & 63;
  int stage_v_169_2 = (stage_v_151_2 ^ pub_r001287_13_2) & 63;
  if ((stage_v_169_1 & 1) != 0)
  {
    if ((stage_v_27_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_169_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_169_1 * 2)) & 255;
  }
  if ((stage_v_169_2 & 1) != 0)
  {
    if ((stage_v_27_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_169_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_169_2 * 2)) & 255;
  }
  int stage_v_170_1 = (stage_v_94_1 ^ pub_r001287_6_1) & 63;
  int stage_v_170_2 = (stage_v_94_2 ^ pub_r001287_6_2) & 63;
  if ((stage_v_170_1 & 1) != 0)
  {
    if ((stage_v_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_170_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_170_1 * 2)) & 255;
  }
  if ((stage_v_170_2 & 1) != 0)
  {
    if ((stage_v_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_170_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_170_2 * 2)) & 255;
  }
  int stage_v_171_1 = (helper_flow_4_1 ^ pub_r001287_11_1) & 63;
  int stage_v_171_2 = (helper_flow_4_2 ^ pub_r001287_11_2) & 63;
  if ((stage_v_171_1 & 1) != 0)
  {
    if ((sec_r001287_6_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_171_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_171_1 * 2)) & 255;
  }
  if ((stage_v_171_2 & 1) != 0)
  {
    if ((sec_r001287_6_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_171_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_171_2 * 2)) & 255;
  }
  int stage_v_172_1 = (helper_flow_3_1 ^ pub_r001287_12_1) & 63;
  int stage_v_172_2 = (helper_flow_3_2 ^ pub_r001287_12_2) & 63;
  if ((stage_v_172_1 & 1) != 0)
  {
    if ((stage_v_72_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_172_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_172_1 * 2)) & 255;
  }
  if ((stage_v_172_2 & 1) != 0)
  {
    if ((stage_v_72_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_172_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_172_2 * 2)) & 255;
  }
  int stage_v_173_1 = (stage_v_95_1 ^ pub_r001287_8_1) & 63;
  int stage_v_173_2 = (stage_v_95_2 ^ pub_r001287_8_2) & 63;
  if ((stage_v_173_1 & 1) != 0)
  {
    if ((sec_r001287_11_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_173_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_173_1 * 2)) & 255;
  }
  if ((stage_v_173_2 & 1) != 0)
  {
    if ((sec_r001287_11_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_173_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_173_2 * 2)) & 255;
  }
  int stage_v_174_1 = (sec_r001287_6_1 ^ pub_r001287_16_1) & 63;
  int stage_v_174_2 = (sec_r001287_6_2 ^ pub_r001287_16_2) & 63;
  if ((stage_v_174_1 & 1) != 0)
  {
    if ((helper_flow_3_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_174_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_174_1 * 2)) & 255;
  }
  if ((stage_v_174_2 & 1) != 0)
  {
    if ((helper_flow_3_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_174_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_174_2 * 2)) & 255;
  }
  int stage_v_175_1 = (stage_v_140_1 ^ pub_r001287_0_1) & 63;
  int stage_v_175_2 = (stage_v_140_2 ^ pub_r001287_0_2) & 63;
  if ((stage_v_175_1 & 1) != 0)
  {
    if ((stage_v_104_1 & 2) != 0)
    {
      out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_1 = ((out_sink_1 - stage_v_175_1) + 9) & 255;
    }
  }
  else
  {
    sec_accum_1 = (sec_accum_1 + (stage_v_175_1 * 2)) & 255;
  }
  if ((stage_v_175_2 & 1) != 0)
  {
    if ((stage_v_104_2 & 2) != 0)
    {
      out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 3)) + 1) & 255;
    }
    else
    {
      out_sink_2 = ((out_sink_2 - stage_v_175_2) + 9) & 255;
    }
  }
  else
  {
    sec_accum_2 = (sec_accum_2 + (stage_v_175_2 * 2)) & 255;
  }
  int stage_v_176_1 = ((pub_r001287_12_1 * 2) + 8) & 63;
  int stage_v_176_2 = ((pub_r001287_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(sec_r001287_11_1 != sec_r001287_11_2);
  __CPROVER_assume(pub_r001287_9_1 == pub_r001287_9_2);
  __CPROVER_assume(pub_r001287_4_1 == pub_r001287_4_2);
  __CPROVER_assume(pub_r001287_15_1 == pub_r001287_15_2);
  __CPROVER_assume(pub_r001287_5_1 == pub_r001287_5_2);
  __CPROVER_assume(sec_r001287_8_1 != sec_r001287_8_2);
  __CPROVER_assume(sec_r001287_10_1 != sec_r001287_10_2);
  __CPROVER_assume(sec_r001287_6_1 != sec_r001287_6_2);
  __CPROVER_assume(sec_r001287_5_1 != sec_r001287_5_2);
  __CPROVER_assume(sec_r001287_3_1 != sec_r001287_3_2);
  __CPROVER_assume(pub_r001287_8_1 == pub_r001287_8_2);
  __CPROVER_assume(sec_r001287_18_1 != sec_r001287_18_2);
  __CPROVER_assume(sec_r001287_14_1 != sec_r001287_14_2);
  __CPROVER_assume(pub_r001287_7_1 == pub_r001287_7_2);
  __CPROVER_assume(pub_r001287_10_1 == pub_r001287_10_2);
  __CPROVER_assume(pub_r001287_11_1 == pub_r001287_11_2);
  __CPROVER_assume(sec_r001287_7_1 != sec_r001287_7_2);
  __CPROVER_assume(sec_r001287_15_1 != sec_r001287_15_2);
  __CPROVER_assume(pub_r001287_1_1 == pub_r001287_1_2);
  __CPROVER_assume(pub_r001287_12_1 == pub_r001287_12_2);
  __CPROVER_assume(pub_r001287_3_1 == pub_r001287_3_2);
  __CPROVER_assume(sec_r001287_13_1 != sec_r001287_13_2);
  __CPROVER_assume(pub_r001287_16_1 == pub_r001287_16_2);
  __CPROVER_assume(pub_r001287_2_1 == pub_r001287_2_2);
  __CPROVER_assume(sec_r001287_17_1 != sec_r001287_17_2);
  __CPROVER_assume(sec_r001287_9_1 != sec_r001287_9_2);
  __CPROVER_assume(sec_r001287_16_1 != sec_r001287_16_2);
  __CPROVER_assume(pub_r001287_6_1 == pub_r001287_6_2);
  __CPROVER_assume(sec_r001287_19_1 != sec_r001287_19_2);
  __CPROVER_assume(pub_r001287_13_1 == pub_r001287_13_2);
  __CPROVER_assume(sec_r001287_4_1 != sec_r001287_4_2);
  __CPROVER_assume(pub_r001287_0_1 == pub_r001287_0_2);
  __CPROVER_assume(sec_r001287_12_1 != sec_r001287_12_2);
  __CPROVER_assume(sec_r001287_1_1 != sec_r001287_1_2);
  __CPROVER_assume(pub_r001287_14_1 == pub_r001287_14_2);
  __CPROVER_assume(sec_r001287_20_1 != sec_r001287_20_2);
  __CPROVER_assume(sec_r001287_0_1 != sec_r001287_0_2);
  __CPROVER_assume(sec_r001287_2_1 != sec_r001287_2_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.norm_sq == st_var_1_2.norm_sq);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.heading == st_var_1_2.heading);
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
}


