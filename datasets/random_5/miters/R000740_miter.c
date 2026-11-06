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
struct FilterState_R000740_4013_0
{
  int cutoff;
  int prev_in;
  short gain_db;
  int damping;
  int mode;
  int prev_out;
  int buffer[3];
};
struct Vector3D_R000740_4013_1
{
  unsigned char coord_x;
  int coord_z;
  unsigned char coord_y;
  int buffer[3];
};
union ColorPixel_R000740_4013_0
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
void fn_R000740_4013_0_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int damping_42_1 = local_arr_1[aux_1 % 3];
  int damping_42_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (damping_42_1 * 2)) & 127;
  acc_2 = (acc_2 + (damping_42_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(damping_42_1 == damping_42_2);
}

int fn_R000740_4013_0(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int damping_42 = local_arr[aux % 3];
  acc = (acc + (damping_42 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000740_4013_1_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 42) & 127;
  int acc_2 = (p0_2 + 42) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int mask_20_1 = local_arr_1[aux_1 % 3];
  int mask_20_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (mask_20_1 * 2)) & 127;
  acc_2 = (acc_2 + (mask_20_2 * 2)) & 127;
  int offset_31_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int offset_31_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + offset_31_1) & 63;
  aux_2 = (aux_2 + offset_31_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(mask_20_1 == mask_20_2);
  assert(offset_31_1 == offset_31_2);
}

int fn_R000740_4013_1(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 42) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int local_arr[3] = {4, 9, 15};
  int mask_20 = local_arr[aux % 3];
  acc = (acc + (mask_20 * 2)) & 127;
  int offset_31 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + offset_31) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000740_4013_2_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 13) & 127;
  int acc_2 = (p0_2 + 13) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_73_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_73_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_73_1) & 63;
  aux_2 = (aux_2 + parity_73_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_73_1 == parity_73_2);
}

int fn_R000740_4013_2(int p0, int p1)
{
  int acc = (p0 + 13) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_73 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_73) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000740_4013_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 27) & 127;
  int acc_2 = (p0_2 + 27) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int sample_46_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_46_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_46_1)
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

  switch (sample_46_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_79_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int factor_79_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + factor_79_1) & 63;
  aux_2 = (aux_2 + factor_79_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int index_reg_78_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_78_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_78_1 > 34)
  {
    acc_1 = ((acc_1 + (index_reg_78_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_78_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_78_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_78_2 > 34)
  {
    acc_2 = ((acc_2 + (index_reg_78_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_78_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_78_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_46_1 == sample_46_2);
  assert(factor_79_1 == factor_79_2);
  assert(index_reg_78_1 == index_reg_78_2);
}

int fn_R000740_4013_3(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 27) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int sample_46 = (aux + st.buffer[1]) & 3;
  switch (sample_46)
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

  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + factor_79) & 63;
  acc ^= aux;
  int index_reg_78 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_78 > 34)
  {
    acc = ((acc + (index_reg_78 * 2)) + 5) & 127;
    aux ^= index_reg_78 & 15;
  }
  else
  {
    acc = ((acc - index_reg_78) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 6) & 127;
  int acc_2 = (p0_2 + 6) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int delta_23_1 = local_arr_1[aux_1 % 3];
  int delta_23_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (delta_23_1 * 2)) & 127;
  acc_2 = (acc_2 + (delta_23_2 * 2)) & 127;
  int metric_44_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int metric_44_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + metric_44_1) & 63;
  aux_2 = (aux_2 + metric_44_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int segment_17_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_17_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_17_1)
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

  switch (segment_17_2)
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

  int bound_31_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int bound_31_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (bound_31_1 > 47)
  {
    acc_1 = ((acc_1 + (bound_31_1 * 2)) + 5) & 127;
    aux_1 ^= bound_31_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - bound_31_1) + 11) & 127;
    aux_1 += 3;
  }
  if (bound_31_2 > 47)
  {
    acc_2 = ((acc_2 + (bound_31_2 * 2)) + 5) & 127;
    aux_2 ^= bound_31_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - bound_31_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(delta_23_1 == delta_23_2);
  assert(metric_44_1 == metric_44_2);
  assert(segment_17_1 == segment_17_2);
  assert(bound_31_1 == bound_31_2);
}

int fn_R000740_4013_4(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 6) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int local_arr[3] = {4, 9, 15};
  int delta_23 = local_arr[aux % 3];
  acc = (acc + (delta_23 * 2)) & 127;
  int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + metric_44) & 63;
  acc ^= aux;
  int segment_17 = (aux + st.buffer[1]) & 3;
  switch (segment_17)
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

  int bound_31 = ((st.buffer[0] * 3) + aux) & 63;
  if (bound_31 > 47)
  {
    acc = ((acc + (bound_31 * 2)) + 5) & 127;
    aux ^= bound_31 & 15;
  }
  else
  {
    acc = ((acc - bound_31) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 23) & 127;
  int acc_2 = (p0_2 + 23) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int weight_55_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_55_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_55_1 > 31)
  {
    acc_1 = ((acc_1 + (weight_55_1 * 2)) + 5) & 127;
    aux_1 ^= weight_55_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_55_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_55_2 > 31)
  {
    acc_2 = ((acc_2 + (weight_55_2 * 2)) + 5) & 127;
    aux_2 ^= weight_55_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_55_2) + 11) & 127;
    aux_2 += 3;
  }
  int margin_43_1 = (aux_1 + st_1.buffer[1]) & 3;
  int margin_43_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (margin_43_1)
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

  switch (margin_43_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int window_99_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_99_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_99_1) & 63;
  aux_2 = (aux_2 + window_99_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_55_1 == weight_55_2);
  assert(margin_43_1 == margin_43_2);
  assert(window_99_1 == window_99_2);
}

int fn_R000740_4013_5(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 23) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int weight_55 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_55 > 31)
  {
    acc = ((acc + (weight_55 * 2)) + 5) & 127;
    aux ^= weight_55 & 15;
  }
  else
  {
    acc = ((acc - weight_55) + 11) & 127;
    aux += 3;
  }
  int margin_43 = (aux + st.buffer[1]) & 3;
  switch (margin_43)
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

  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int window_99 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_99) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000740_4013_6_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 5;
  st_2.buffer[2] = 5;
  int pivot_98_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int pivot_98_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + pivot_98_1) & 63;
  aux_2 = (aux_2 + pivot_98_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_62_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int sample_62_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (sample_62_1 > 30)
  {
    acc_1 = ((acc_1 + (sample_62_1 * 2)) + 5) & 127;
    aux_1 ^= sample_62_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - sample_62_1) + 11) & 127;
    aux_1 += 3;
  }
  if (sample_62_2 > 30)
  {
    acc_2 = ((acc_2 + (sample_62_2 * 2)) + 5) & 127;
    aux_2 ^= sample_62_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - sample_62_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(pivot_98_1 == pivot_98_2);
  assert(sample_62_1 == sample_62_2);
}

int fn_R000740_4013_6(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 5;
  int pivot_98 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + pivot_98) & 63;
  acc ^= aux;
  int sample_62 = ((st.buffer[0] * 3) + aux) & 63;
  if (sample_62 > 30)
  {
    acc = ((acc + (sample_62 * 2)) + 5) & 127;
    aux ^= sample_62 & 15;
  }
  else
  {
    acc = ((acc - sample_62) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  int weight_53_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int weight_53_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (weight_53_1 > 34)
  {
    acc_1 = ((acc_1 + (weight_53_1 * 2)) + 5) & 127;
    aux_1 ^= weight_53_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - weight_53_1) + 11) & 127;
    aux_1 += 3;
  }
  if (weight_53_2 > 34)
  {
    acc_2 = ((acc_2 + (weight_53_2 * 2)) + 5) & 127;
    aux_2 ^= weight_53_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - weight_53_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int vector_21_1 = local_arr_1[aux_1 % 3];
  int vector_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (vector_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (vector_21_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(weight_53_1 == weight_53_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(vector_21_1 == vector_21_2);
}

int fn_R000740_4013_7(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  int weight_53 = ((st.buffer[0] * 3) + aux) & 63;
  if (weight_53 > 34)
  {
    acc = ((acc + (weight_53 * 2)) + 5) & 127;
    aux ^= weight_53 & 15;
  }
  else
  {
    acc = ((acc - weight_53) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int vector_21 = local_arr[aux % 3];
  acc = (acc + (vector_21 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R000740_4013_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 47) & 127;
  int acc_2 = (p0_2 + 47) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quotient_14_1 = local_arr_1[aux_1 % 3];
  int quotient_14_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quotient_14_1 * 2)) & 127;
  acc_2 = (acc_2 + (quotient_14_2 * 2)) & 127;
  int vector_57_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_57_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_57_1) & 63;
  aux_2 = (aux_2 + vector_57_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_21_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_21_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_21_1 > 19)
  {
    acc_1 = ((acc_1 + (checksum_21_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_21_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_21_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_21_2 > 19)
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
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quotient_14_1 == quotient_14_2);
  assert(vector_57_1 == vector_57_2);
  assert(checksum_21_1 == checksum_21_2);
}

int fn_R000740_4013_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 47) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int quotient_14 = local_arr[aux % 3];
  acc = (acc + (quotient_14 * 2)) & 127;
  int vector_57 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_57) & 63;
  acc ^= aux;
  int checksum_21 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_21 > 19)
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

void fn_R000740_4013_9_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 2) & 127;
  int acc_2 = (p0_2 + 2) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int vector_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_38_1) & 63;
  aux_2 = (aux_2 + vector_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int index_reg_44_1 = local_arr_1[aux_1 % 3];
  int index_reg_44_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (index_reg_44_1 * 2)) & 127;
  acc_2 = (acc_2 + (index_reg_44_2 * 2)) & 127;
  int checksum_69_1 = (aux_1 + st_1.buffer[1]) & 3;
  int checksum_69_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (checksum_69_1)
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

  switch (checksum_69_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_38_1 == vector_38_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(index_reg_44_1 == index_reg_44_2);
  assert(checksum_69_1 == checksum_69_2);
}

int fn_R000740_4013_9(int p0, int p1)
{
  int acc = (p0 + 2) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int vector_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_38) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int index_reg_44 = local_arr[aux % 3];
  acc = (acc + (index_reg_44 * 2)) & 127;
  int checksum_69 = (aux + st.buffer[1]) & 3;
  switch (checksum_69)
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

void fn_R000740_4013_10_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 9;
  st_2.buffer[2] = 9;
  int factor_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_75_1 > 31)
  {
    acc_1 = ((acc_1 + (factor_75_1 * 2)) + 5) & 127;
    aux_1 ^= factor_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_75_2 > 31)
  {
    acc_2 = ((acc_2 + (factor_75_2 * 2)) + 5) & 127;
    aux_2 ^= factor_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_75_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_53_1 = local_arr_1[aux_1 % 3];
  int offset_53_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_53_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_53_2 * 2)) & 127;
  int anchor_61_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int anchor_61_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + anchor_61_1) & 63;
  aux_2 = (aux_2 + anchor_61_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(factor_75_1 == factor_75_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_53_1 == offset_53_2);
  assert(anchor_61_1 == anchor_61_2);
}

int fn_R000740_4013_10(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 9;
  int factor_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_75 > 31)
  {
    acc = ((acc + (factor_75 * 2)) + 5) & 127;
    aux ^= factor_75 & 15;
  }
  else
  {
    acc = ((acc - factor_75) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int offset_53 = local_arr[aux % 3];
  acc = (acc + (offset_53 * 2)) & 127;
  int anchor_61 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + anchor_61) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000740_4013_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 8) & 127;
  int acc_2 = (p0_2 + 8) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  int damping_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int damping_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (damping_60_1)
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

  switch (damping_60_2)
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

  int accumulator_46_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int accumulator_46_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + accumulator_46_1) & 63;
  aux_2 = (aux_2 + accumulator_46_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int factor_74_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int factor_74_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (factor_74_1 > 32)
  {
    acc_1 = ((acc_1 + (factor_74_1 * 2)) + 5) & 127;
    aux_1 ^= factor_74_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - factor_74_1) + 11) & 127;
    aux_1 += 3;
  }
  if (factor_74_2 > 32)
  {
    acc_2 = ((acc_2 + (factor_74_2 * 2)) + 5) & 127;
    aux_2 ^= factor_74_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - factor_74_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(damping_60_1 == damping_60_2);
  assert(accumulator_46_1 == accumulator_46_2);
  assert(factor_74_1 == factor_74_2);
}

int fn_R000740_4013_11(int p0, int p1)
{
  int acc = (p0 + 8) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  int damping_60 = (aux + st.buffer[1]) & 3;
  switch (damping_60)
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

  int accumulator_46 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + accumulator_46) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int factor_74 = ((st.buffer[0] * 3) + aux) & 63;
  if (factor_74 > 32)
  {
    acc = ((acc + (factor_74 * 2)) + 5) & 127;
    aux ^= factor_74 & 15;
  }
  else
  {
    acc = ((acc - factor_74) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_12_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 23;
  st_2.buffer[2] = 23;
  int threshold_60_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_60_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_60_1)
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

  switch (threshold_60_2)
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

  int parity_76_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int parity_76_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + parity_76_1) & 63;
  aux_2 = (aux_2 + parity_76_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int cursor_19_1 = local_arr_1[aux_1 % 3];
  int cursor_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (cursor_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (cursor_19_2 * 2)) & 127;
  int window_75_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_75_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_75_1 > 19)
  {
    acc_1 = ((acc_1 + (window_75_1 * 2)) + 5) & 127;
    aux_1 ^= window_75_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_75_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_75_2 > 19)
  {
    acc_2 = ((acc_2 + (window_75_2 * 2)) + 5) & 127;
    aux_2 ^= window_75_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_75_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_60_1 == threshold_60_2);
  assert(parity_76_1 == parity_76_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(cursor_19_1 == cursor_19_2);
  assert(window_75_1 == window_75_2);
}

int fn_R000740_4013_12(int p0, int p1, int p2)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 23;
  int threshold_60 = (aux + st.buffer[1]) & 3;
  switch (threshold_60)
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

  int parity_76 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + parity_76) & 63;
  acc ^= aux;
  int local_arr[3] = {4, 9, 15};
  int cursor_19 = local_arr[aux % 3];
  acc = (acc + (cursor_19 * 2)) & 127;
  int window_75 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_75 > 19)
  {
    acc = ((acc + (window_75 * 2)) + 5) & 127;
    aux ^= window_75 & 15;
  }
  else
  {
    acc = ((acc - window_75) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_13_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 49) & 127;
  int acc_2 = (p0_2 + 49) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int parity_27_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_27_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_27_1 > 16)
  {
    acc_1 = ((acc_1 + (parity_27_1 * 2)) + 5) & 127;
    aux_1 ^= parity_27_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_27_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_27_2 > 16)
  {
    acc_2 = ((acc_2 + (parity_27_2 * 2)) + 5) & 127;
    aux_2 ^= parity_27_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_27_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int stride_26_1 = local_arr_1[aux_1 % 3];
  int stride_26_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (stride_26_1 * 2)) & 127;
  acc_2 = (acc_2 + (stride_26_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(parity_27_1 == parity_27_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(stride_26_1 == stride_26_2);
}

int fn_R000740_4013_13(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 49) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int parity_27 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_27 > 16)
  {
    acc = ((acc + (parity_27 * 2)) + 5) & 127;
    aux ^= parity_27 & 15;
  }
  else
  {
    acc = ((acc - parity_27) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int stride_26 = local_arr[aux % 3];
  acc = (acc + (stride_26 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R000740_4013_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  st_1.buffer[1] = (st_1.buffer[1] + 7) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 7) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int quantum_35_1 = (aux_1 + st_1.buffer[1]) & 3;
  int quantum_35_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (quantum_35_1)
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

  switch (quantum_35_2)
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

  int window_48_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_48_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_48_1) & 63;
  aux_2 = (aux_2 + window_48_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int checksum_44_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int checksum_44_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (checksum_44_1 > 27)
  {
    acc_1 = ((acc_1 + (checksum_44_1 * 2)) + 5) & 127;
    aux_1 ^= checksum_44_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - checksum_44_1) + 11) & 127;
    aux_1 += 3;
  }
  if (checksum_44_2 > 27)
  {
    acc_2 = ((acc_2 + (checksum_44_2 * 2)) + 5) & 127;
    aux_2 ^= checksum_44_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - checksum_44_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_35_1 == quantum_35_2);
  assert(window_48_1 == window_48_2);
  assert(checksum_44_1 == checksum_44_2);
}

int fn_R000740_4013_14(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  st.buffer[1] = (st.buffer[1] + 7) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int quantum_35 = (aux + st.buffer[1]) & 3;
  switch (quantum_35)
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

  int window_48 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_48) & 63;
  acc ^= aux;
  int checksum_44 = ((st.buffer[0] * 3) + aux) & 63;
  if (checksum_44 > 27)
  {
    acc = ((acc + (checksum_44 * 2)) + 5) & 127;
    aux ^= checksum_44 & 15;
  }
  else
  {
    acc = ((acc - checksum_44) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R000740_4013_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 33) & 127;
  int acc_2 = (p0_2 + 33) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 24;
  st_2.buffer[2] = 24;
  int sample_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int sample_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + sample_92_1) & 63;
  aux_2 = (aux_2 + sample_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int delta_29_1 = (aux_1 + st_1.buffer[1]) & 3;
  int delta_29_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (delta_29_1)
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

  switch (delta_29_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(sample_92_1 == sample_92_2);
  assert(delta_29_1 == delta_29_2);
}

int fn_R000740_4013_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 33) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 24;
  int sample_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + sample_92) & 63;
  acc ^= aux;
  int delta_29 = (aux + st.buffer[1]) & 3;
  switch (delta_29)
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

void fn_R000740_4013_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st_1 = {0};
  struct Vector3D_R000740_4013_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int quotient_58_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quotient_58_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quotient_58_1 > 12)
  {
    acc_1 = ((acc_1 + (quotient_58_1 * 2)) + 5) & 127;
    aux_1 ^= quotient_58_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quotient_58_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quotient_58_2 > 12)
  {
    acc_2 = ((acc_2 + (quotient_58_2 * 2)) + 5) & 127;
    aux_2 ^= quotient_58_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quotient_58_2) + 11) & 127;
    aux_2 += 3;
  }
  int window_58_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int window_58_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + window_58_1) & 63;
  aux_2 = (aux_2 + window_58_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quotient_58_1 == quotient_58_2);
  assert(window_58_1 == window_58_2);
}

int fn_R000740_4013_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R000740_4013_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int quotient_58 = ((st.buffer[0] * 3) + aux) & 63;
  if (quotient_58 > 12)
  {
    acc = ((acc + (quotient_58 * 2)) + 5) & 127;
    aux ^= quotient_58 & 15;
  }
  else
  {
    acc = ((acc - quotient_58) + 11) & 127;
    aux += 3;
  }
  int window_58 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + window_58) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R000740_4013_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st_1 = {0};
  struct FilterState_R000740_4013_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int quantum_97_1 = local_arr_1[aux_1 % 3];
  int quantum_97_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (quantum_97_1 * 2)) & 127;
  acc_2 = (acc_2 + (quantum_97_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 2) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 2) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.prev_in == st_2.prev_in);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.mode == st_2.mode);
  assert(st_1.prev_out == st_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(quantum_97_1 == quantum_97_2);
}

int fn_R000740_4013_17(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R000740_4013_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int local_arr[3] = {4, 9, 15};
  int quantum_97 = local_arr[aux % 3];
  acc = (acc + (quantum_97 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 2) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void main()
{
  int sec_r000740_0_1;
  int sec_r000740_0_2;
  int sec_r000740_1_1;
  int sec_r000740_1_2;
  int sec_r000740_2_1;
  int sec_r000740_2_2;
  int sec_r000740_3_1;
  int sec_r000740_3_2;
  int sec_r000740_4_1;
  int sec_r000740_4_2;
  int sec_r000740_5_1;
  int sec_r000740_5_2;
  int sec_r000740_6_1;
  int sec_r000740_6_2;
  int sec_r000740_7_1;
  int sec_r000740_7_2;
  int sec_r000740_8_1;
  int sec_r000740_8_2;
  int sec_r000740_9_1;
  int sec_r000740_9_2;
  int sec_r000740_10_1;
  int sec_r000740_10_2;
  int sec_r000740_11_1;
  int sec_r000740_11_2;
  int sec_r000740_12_1;
  int sec_r000740_12_2;
  int sec_r000740_13_1;
  int sec_r000740_13_2;
  int sec_r000740_14_1;
  int sec_r000740_14_2;
  int sec_r000740_15_1;
  int sec_r000740_15_2;
  int sec_r000740_16_1;
  int sec_r000740_16_2;
  int sec_r000740_17_1;
  int sec_r000740_17_2;
  int sec_r000740_18_1;
  int sec_r000740_18_2;
  int sec_r000740_19_1;
  int sec_r000740_19_2;
  int sec_r000740_20_1;
  int sec_r000740_20_2;
  int sec_r000740_21_1;
  int sec_r000740_21_2;
  int pub_r000740_0_1;
  int pub_r000740_0_2;
  int pub_r000740_1_1;
  int pub_r000740_1_2;
  int pub_r000740_2_1;
  int pub_r000740_2_2;
  int pub_r000740_3_1;
  int pub_r000740_3_2;
  int pub_r000740_4_1;
  int pub_r000740_4_2;
  int pub_r000740_5_1;
  int pub_r000740_5_2;
  int pub_r000740_6_1;
  int pub_r000740_6_2;
  int pub_r000740_7_1;
  int pub_r000740_7_2;
  int pub_r000740_8_1;
  int pub_r000740_8_2;
  int pub_r000740_9_1;
  int pub_r000740_9_2;
  int pub_r000740_10_1;
  int pub_r000740_10_2;
  int pub_r000740_11_1;
  int pub_r000740_11_2;
  int pub_r000740_12_1;
  int pub_r000740_12_2;
  int pub_r000740_13_1;
  int pub_r000740_13_2;
  int pub_r000740_14_1;
  int pub_r000740_14_2;
  int pub_r000740_15_1;
  int pub_r000740_15_2;
  int pub_r000740_16_1;
  int pub_r000740_16_2;
  int pub_r000740_17_1;
  int pub_r000740_17_2;
  int pub_r000740_18_1;
  int pub_r000740_18_2;
  int pub_r000740_19_1;
  int pub_r000740_19_2;
  int pub_r000740_20_1;
  int pub_r000740_20_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r000740_0_1 >= (-100)) && (pub_r000740_0_1 <= 100));
  __CPROVER_assume((pub_r000740_0_2 >= (-100)) && (pub_r000740_0_2 <= 100));
  __CPROVER_assume((pub_r000740_1_1 >= (-100)) && (pub_r000740_1_1 <= 100));
  __CPROVER_assume((pub_r000740_1_2 >= (-100)) && (pub_r000740_1_2 <= 100));
  __CPROVER_assume((pub_r000740_2_1 >= (-100)) && (pub_r000740_2_1 <= 100));
  __CPROVER_assume((pub_r000740_2_2 >= (-100)) && (pub_r000740_2_2 <= 100));
  __CPROVER_assume((pub_r000740_3_1 >= (-100)) && (pub_r000740_3_1 <= 100));
  __CPROVER_assume((pub_r000740_3_2 >= (-100)) && (pub_r000740_3_2 <= 100));
  __CPROVER_assume((pub_r000740_4_1 >= (-100)) && (pub_r000740_4_1 <= 100));
  __CPROVER_assume((pub_r000740_4_2 >= (-100)) && (pub_r000740_4_2 <= 100));
  __CPROVER_assume((pub_r000740_5_1 >= (-100)) && (pub_r000740_5_1 <= 100));
  __CPROVER_assume((pub_r000740_5_2 >= (-100)) && (pub_r000740_5_2 <= 100));
  __CPROVER_assume((pub_r000740_6_1 >= (-100)) && (pub_r000740_6_1 <= 100));
  __CPROVER_assume((pub_r000740_6_2 >= (-100)) && (pub_r000740_6_2 <= 100));
  __CPROVER_assume((pub_r000740_7_1 >= (-100)) && (pub_r000740_7_1 <= 100));
  __CPROVER_assume((pub_r000740_7_2 >= (-100)) && (pub_r000740_7_2 <= 100));
  __CPROVER_assume((pub_r000740_8_1 >= (-100)) && (pub_r000740_8_1 <= 100));
  __CPROVER_assume((pub_r000740_8_2 >= (-100)) && (pub_r000740_8_2 <= 100));
  __CPROVER_assume((pub_r000740_9_1 >= (-100)) && (pub_r000740_9_1 <= 100));
  __CPROVER_assume((pub_r000740_9_2 >= (-100)) && (pub_r000740_9_2 <= 100));
  __CPROVER_assume((pub_r000740_10_1 >= (-100)) && (pub_r000740_10_1 <= 100));
  __CPROVER_assume((pub_r000740_10_2 >= (-100)) && (pub_r000740_10_2 <= 100));
  __CPROVER_assume((pub_r000740_11_1 >= (-100)) && (pub_r000740_11_1 <= 100));
  __CPROVER_assume((pub_r000740_11_2 >= (-100)) && (pub_r000740_11_2 <= 100));
  __CPROVER_assume((pub_r000740_12_1 >= (-100)) && (pub_r000740_12_1 <= 100));
  __CPROVER_assume((pub_r000740_12_2 >= (-100)) && (pub_r000740_12_2 <= 100));
  __CPROVER_assume((pub_r000740_13_1 >= (-100)) && (pub_r000740_13_1 <= 100));
  __CPROVER_assume((pub_r000740_13_2 >= (-100)) && (pub_r000740_13_2 <= 100));
  __CPROVER_assume((pub_r000740_14_1 >= (-100)) && (pub_r000740_14_1 <= 100));
  __CPROVER_assume((pub_r000740_14_2 >= (-100)) && (pub_r000740_14_2 <= 100));
  __CPROVER_assume((pub_r000740_15_1 >= (-100)) && (pub_r000740_15_1 <= 100));
  __CPROVER_assume((pub_r000740_15_2 >= (-100)) && (pub_r000740_15_2 <= 100));
  __CPROVER_assume((pub_r000740_16_1 >= (-100)) && (pub_r000740_16_1 <= 100));
  __CPROVER_assume((pub_r000740_16_2 >= (-100)) && (pub_r000740_16_2 <= 100));
  __CPROVER_assume((pub_r000740_17_1 >= (-100)) && (pub_r000740_17_1 <= 100));
  __CPROVER_assume((pub_r000740_17_2 >= (-100)) && (pub_r000740_17_2 <= 100));
  __CPROVER_assume((pub_r000740_18_1 >= (-100)) && (pub_r000740_18_1 <= 100));
  __CPROVER_assume((pub_r000740_18_2 >= (-100)) && (pub_r000740_18_2 <= 100));
  __CPROVER_assume((pub_r000740_19_1 >= (-100)) && (pub_r000740_19_1 <= 100));
  __CPROVER_assume((pub_r000740_19_2 >= (-100)) && (pub_r000740_19_2 <= 100));
  __CPROVER_assume((pub_r000740_20_1 >= (-100)) && (pub_r000740_20_1 <= 100));
  __CPROVER_assume((pub_r000740_20_2 >= (-100)) && (pub_r000740_20_2 <= 100));
  __CPROVER_assume((sec_r000740_0_1 >= 0) && (sec_r000740_0_1 <= 255));
  __CPROVER_assume((sec_r000740_0_2 >= 0) && (sec_r000740_0_2 <= 255));
  __CPROVER_assume((sec_r000740_1_1 >= 0) && (sec_r000740_1_1 <= 255));
  __CPROVER_assume((sec_r000740_1_2 >= 0) && (sec_r000740_1_2 <= 255));
  __CPROVER_assume((sec_r000740_2_1 >= 0) && (sec_r000740_2_1 <= 255));
  __CPROVER_assume((sec_r000740_2_2 >= 0) && (sec_r000740_2_2 <= 255));
  __CPROVER_assume((sec_r000740_3_1 >= 0) && (sec_r000740_3_1 <= 255));
  __CPROVER_assume((sec_r000740_3_2 >= 0) && (sec_r000740_3_2 <= 255));
  __CPROVER_assume((sec_r000740_4_1 >= 0) && (sec_r000740_4_1 <= 255));
  __CPROVER_assume((sec_r000740_4_2 >= 0) && (sec_r000740_4_2 <= 255));
  __CPROVER_assume((sec_r000740_5_1 >= 0) && (sec_r000740_5_1 <= 255));
  __CPROVER_assume((sec_r000740_5_2 >= 0) && (sec_r000740_5_2 <= 255));
  __CPROVER_assume((sec_r000740_6_1 >= 0) && (sec_r000740_6_1 <= 255));
  __CPROVER_assume((sec_r000740_6_2 >= 0) && (sec_r000740_6_2 <= 255));
  __CPROVER_assume((sec_r000740_7_1 >= 0) && (sec_r000740_7_1 <= 255));
  __CPROVER_assume((sec_r000740_7_2 >= 0) && (sec_r000740_7_2 <= 255));
  __CPROVER_assume((sec_r000740_8_1 >= 0) && (sec_r000740_8_1 <= 255));
  __CPROVER_assume((sec_r000740_8_2 >= 0) && (sec_r000740_8_2 <= 255));
  __CPROVER_assume((sec_r000740_9_1 >= 0) && (sec_r000740_9_1 <= 255));
  __CPROVER_assume((sec_r000740_9_2 >= 0) && (sec_r000740_9_2 <= 255));
  __CPROVER_assume((sec_r000740_10_1 >= 0) && (sec_r000740_10_1 <= 255));
  __CPROVER_assume((sec_r000740_10_2 >= 0) && (sec_r000740_10_2 <= 255));
  __CPROVER_assume((sec_r000740_11_1 >= 0) && (sec_r000740_11_1 <= 255));
  __CPROVER_assume((sec_r000740_11_2 >= 0) && (sec_r000740_11_2 <= 255));
  __CPROVER_assume((sec_r000740_12_1 >= 0) && (sec_r000740_12_1 <= 255));
  __CPROVER_assume((sec_r000740_12_2 >= 0) && (sec_r000740_12_2 <= 255));
  __CPROVER_assume((sec_r000740_13_1 >= 0) && (sec_r000740_13_1 <= 255));
  __CPROVER_assume((sec_r000740_13_2 >= 0) && (sec_r000740_13_2 <= 255));
  __CPROVER_assume((sec_r000740_14_1 >= 0) && (sec_r000740_14_1 <= 255));
  __CPROVER_assume((sec_r000740_14_2 >= 0) && (sec_r000740_14_2 <= 255));
  __CPROVER_assume((sec_r000740_15_1 >= 0) && (sec_r000740_15_1 <= 255));
  __CPROVER_assume((sec_r000740_15_2 >= 0) && (sec_r000740_15_2 <= 255));
  __CPROVER_assume((sec_r000740_16_1 >= 0) && (sec_r000740_16_1 <= 255));
  __CPROVER_assume((sec_r000740_16_2 >= 0) && (sec_r000740_16_2 <= 255));
  __CPROVER_assume((sec_r000740_17_1 >= 0) && (sec_r000740_17_1 <= 255));
  __CPROVER_assume((sec_r000740_17_2 >= 0) && (sec_r000740_17_2 <= 255));
  __CPROVER_assume((sec_r000740_18_1 >= 0) && (sec_r000740_18_1 <= 255));
  __CPROVER_assume((sec_r000740_18_2 >= 0) && (sec_r000740_18_2 <= 255));
  __CPROVER_assume((sec_r000740_19_1 >= 0) && (sec_r000740_19_1 <= 255));
  __CPROVER_assume((sec_r000740_19_2 >= 0) && (sec_r000740_19_2 <= 255));
  __CPROVER_assume((sec_r000740_20_1 >= 0) && (sec_r000740_20_1 <= 255));
  __CPROVER_assume((sec_r000740_20_2 >= 0) && (sec_r000740_20_2 <= 255));
  __CPROVER_assume((sec_r000740_21_1 >= 0) && (sec_r000740_21_1 <= 255));
  __CPROVER_assume((sec_r000740_21_2 >= 0) && (sec_r000740_21_2 <= 255));
  struct FilterState_R000740_4013_0 st_var_0_1 = {0};
  struct FilterState_R000740_4013_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r000740_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r000740_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r000740_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r000740_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r000740_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r000740_0_2 + 7) & 15;
  struct Vector3D_R000740_4013_1 st_var_1_1 = {0};
  struct Vector3D_R000740_4013_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r000740_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r000740_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r000740_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r000740_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r000740_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r000740_0_2 + 9) & 15;
  union ColorPixel_R000740_4013_0 u_var_1;
  union ColorPixel_R000740_4013_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int stage_v_0_1 = table_1[0];
  int stage_v_0_2 = table_2[0];
  table_1[0] = (table_1[1] + 1) & 63;
  table_2[0] = (table_2[1] + 1) & 63;
  out_sink_1 = (out_sink_1 + stage_v_0_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_0_2) & 255;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 2) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 2) & 15;
  int stage_v_1_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_1_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_1_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_1_2) & 255;
  chk_sum_1 ^= stage_v_1_1;
  chk_sum_2 ^= stage_v_1_2;
  int stage_v_2_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_2_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_2_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_2_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_3_1 = (st_var_1_1.buffer[0] ^ 6) & 3;
  int stage_v_3_2 = (st_var_1_2.buffer[0] ^ 6) & 3;
  switch (stage_v_3_1)
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

  switch (stage_v_3_2)
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

  int stage_v_4_1 = table_1[0];
  int stage_v_4_2 = table_2[0];
  table_1[0] = (table_1[1] + 9) & 63;
  table_2[0] = (table_2[1] + 9) & 63;
  out_sink_1 = (out_sink_1 + stage_v_4_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_4_2) & 255;
  int stage_v_5_1 = (st_var_1_1.buffer[0] ^ 8) & 3;
  int stage_v_5_2 = (st_var_1_2.buffer[0] ^ 8) & 3;
  switch (stage_v_5_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_5_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_6_1 = (st_var_0_1.buffer[0] ^ 9) & 3;
  int stage_v_6_2 = (st_var_0_2.buffer[0] ^ 9) & 3;
  switch (stage_v_6_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_6_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_7_1 = (st_var_1_1.buffer[0] ^ 10) & 3;
  int stage_v_7_2 = (st_var_1_2.buffer[0] ^ 10) & 3;
  switch (stage_v_7_1)
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

  switch (stage_v_7_2)
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

  int stage_v_8_1 = (st_var_0_1.buffer[0] ^ 11) & 3;
  int stage_v_8_2 = (st_var_0_2.buffer[0] ^ 11) & 3;
  switch (stage_v_8_1)
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

  switch (stage_v_8_2)
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

  int stage_v_9_1 = (st_var_1_1.buffer[0] ^ 12) & 3;
  int stage_v_9_2 = (st_var_1_2.buffer[0] ^ 12) & 3;
  switch (stage_v_9_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
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

  switch (stage_v_9_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
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

  int stage_v_10_1 = ((st_var_0_1.buffer[1] * 2) + 37) & 63;
  int stage_v_10_2 = ((st_var_0_2.buffer[1] * 2) + 37) & 63;
  if (stage_v_10_1 > 18)
  {
    out_sink_1 = ((out_sink_1 + stage_v_10_1) - 5) & 255;
    if (stage_v_10_1 > 33)
    {
      chk_sum_1 ^= stage_v_10_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_10_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_10_2 > 18)
  {
    out_sink_2 = ((out_sink_2 + stage_v_10_2) - 5) & 255;
    if (stage_v_10_2 > 33)
    {
      chk_sum_2 ^= stage_v_10_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_10_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_11_1 = (st_var_1_1.buffer[0] ^ 14) & 3;
  int stage_v_11_2 = (st_var_1_2.buffer[0] ^ 14) & 3;
  switch (stage_v_11_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_12_1 = ((st_var_0_1.buffer[0] * 2) + 43) & 63;
  int stage_v_12_2 = ((st_var_0_2.buffer[0] * 2) + 43) & 63;
  if (stage_v_12_1 > 10)
  {
    out_sink_1 = ((out_sink_1 + stage_v_12_1) - 5) & 255;
    if (stage_v_12_1 > 25)
    {
      chk_sum_1 ^= stage_v_12_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_12_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_12_2 > 10)
  {
    out_sink_2 = ((out_sink_2 + stage_v_12_2) - 5) & 255;
    if (stage_v_12_2 > 25)
    {
      chk_sum_2 ^= stage_v_12_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_12_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 14) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 14) & 15;
  int stage_v_13_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_13_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_13_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_13_2) & 255;
  chk_sum_1 ^= stage_v_13_1;
  chk_sum_2 ^= stage_v_13_2;
  int stage_v_14_1 = table_1[2];
  int stage_v_14_2 = table_2[2];
  table_1[2] = (table_1[3] + 29) & 63;
  table_2[2] = (table_2[3] + 29) & 63;
  out_sink_1 = (out_sink_1 + stage_v_14_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_14_2) & 255;
  int stage_v_15_1 = table_1[3];
  int stage_v_15_2 = table_2[3];
  table_1[3] = (table_1[0] + 31) & 63;
  table_2[3] = (table_2[0] + 31) & 63;
  out_sink_1 = (out_sink_1 + stage_v_15_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_15_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 17) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 17) & 15;
  int stage_v_16_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_16_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_16_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_16_2) & 255;
  chk_sum_1 ^= stage_v_16_1;
  chk_sum_2 ^= stage_v_16_2;
  int stage_v_17_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_17_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_17_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_17_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_18_1 = (st_var_0_1.buffer[0] ^ 21) & 3;
  int stage_v_18_2 = (st_var_0_2.buffer[0] ^ 21) & 3;
  switch (stage_v_18_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_18_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_19_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_19_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_19_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_19_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_20_1 = 0;
  int stage_v_20_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_20_1 = ((stage_v_20_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_20_2 = ((stage_v_20_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_20_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_20_2) & 255;
  int stage_v_21_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_21_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_21_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_21_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_22_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_22_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_22_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_22_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  st_var_1_1.buffer[2] = (st_var_1_1.buffer[2] + 24) & 15;
  st_var_1_2.buffer[2] = (st_var_1_2.buffer[2] + 24) & 15;
  int stage_v_23_1 = (st_var_1_1.buffer[2] * 3) & 63;
  int stage_v_23_2 = (st_var_1_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_23_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_23_2) & 255;
  chk_sum_1 ^= stage_v_23_1;
  chk_sum_2 ^= stage_v_23_2;
  int stage_v_24_1 = ((st_var_0_1.buffer[0] * 2) + 79) & 63;
  int stage_v_24_2 = ((st_var_0_2.buffer[0] * 2) + 79) & 63;
  if (stage_v_24_1 > 16)
  {
    out_sink_1 = ((out_sink_1 + stage_v_24_1) - 5) & 255;
    if (stage_v_24_1 > 31)
    {
      chk_sum_1 ^= stage_v_24_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_24_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_24_2 > 16)
  {
    out_sink_2 = ((out_sink_2 + stage_v_24_2) - 5) & 255;
    if (stage_v_24_2 > 31)
    {
      chk_sum_2 ^= stage_v_24_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_24_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_25_1 = 0;
  int stage_v_25_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_25_1 = ((stage_v_25_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_25_2 = ((stage_v_25_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_25_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_25_2) & 255;
  int stage_v_26_1 = (st_var_0_1.buffer[0] ^ 29) & 3;
  int stage_v_26_2 = (st_var_0_2.buffer[0] ^ 29) & 3;
  switch (stage_v_26_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
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

  switch (stage_v_26_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
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

  int stage_v_27_1 = (st_var_1_1.buffer[0] ^ 30) & 3;
  int stage_v_27_2 = (st_var_1_2.buffer[0] ^ 30) & 3;
  switch (stage_v_27_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_27_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_28_1 = 0;
  int stage_v_28_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_28_1 = ((stage_v_28_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_28_2 = ((stage_v_28_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_28_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_28_2) & 255;
  int stage_v_29_1 = 0;
  int stage_v_29_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_29_1 = ((stage_v_29_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_29_2 = ((stage_v_29_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_29_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_29_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_29_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_29_2) & 255;
  st_var_0_1.buffer[0] = (st_var_0_1.buffer[0] + 31) & 15;
  st_var_0_2.buffer[0] = (st_var_0_2.buffer[0] + 31) & 15;
  int stage_v_30_1 = (st_var_0_1.buffer[0] * 3) & 63;
  int stage_v_30_2 = (st_var_0_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_30_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_30_2) & 255;
  chk_sum_1 ^= stage_v_30_1;
  chk_sum_2 ^= stage_v_30_2;
  st_var_1_1.buffer[1] = (st_var_1_1.buffer[1] + 32) & 15;
  st_var_1_2.buffer[1] = (st_var_1_2.buffer[1] + 32) & 15;
  int stage_v_31_1 = (st_var_1_1.buffer[1] * 3) & 63;
  int stage_v_31_2 = (st_var_1_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_31_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_31_2) & 255;
  chk_sum_1 ^= stage_v_31_1;
  chk_sum_2 ^= stage_v_31_2;
  int stage_v_32_1 = ((st_var_0_1.buffer[2] * 2) + 103) & 63;
  int stage_v_32_2 = ((st_var_0_2.buffer[2] * 2) + 103) & 63;
  if (stage_v_32_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + stage_v_32_1) - 5) & 255;
    if (stage_v_32_1 > 45)
    {
      chk_sum_1 ^= stage_v_32_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_32_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_32_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + stage_v_32_2) - 5) & 255;
    if (stage_v_32_2 > 45)
    {
      chk_sum_2 ^= stage_v_32_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_32_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_33_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (38 & 31);
  int stage_v_33_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (38 & 31);
  out_sink_1 = (out_sink_1 + stage_v_33_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_33_2) & 255;
  chk_sum_1 ^= (stage_v_33_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_33_2 << 1) & 127;
  int stage_v_34_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_34_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_34_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_34_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_35_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_35_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_35_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_35_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_36_1 = ((st_var_0_1.buffer[0] * 2) + 115) & 63;
  int stage_v_36_2 = ((st_var_0_2.buffer[0] * 2) + 115) & 63;
  if (stage_v_36_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + stage_v_36_1) - 5) & 255;
    if (stage_v_36_1 > 50)
    {
      chk_sum_1 ^= stage_v_36_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_36_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_36_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + stage_v_36_2) - 5) & 255;
    if (stage_v_36_2 > 50)
    {
      chk_sum_2 ^= stage_v_36_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_36_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_37_1 = table_1[1];
  int stage_v_37_2 = table_2[1];
  table_1[1] = (table_1[2] + 75) & 63;
  table_2[1] = (table_2[2] + 75) & 63;
  out_sink_1 = (out_sink_1 + stage_v_37_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_37_2) & 255;
  int stage_v_38_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_38_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_38_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_38_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_39_1 = table_1[3];
  int stage_v_39_2 = table_2[3];
  table_1[3] = (table_1[0] + 79) & 63;
  table_2[3] = (table_2[0] + 79) & 63;
  out_sink_1 = (out_sink_1 + stage_v_39_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_39_2) & 255;
  int stage_v_40_1 = ((st_var_0_1.buffer[1] * 2) + 127) & 63;
  int stage_v_40_2 = ((st_var_0_2.buffer[1] * 2) + 127) & 63;
  if (stage_v_40_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_40_1) - 5) & 255;
    if (stage_v_40_1 > 27)
    {
      chk_sum_1 ^= stage_v_40_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_40_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_40_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_40_2) - 5) & 255;
    if (stage_v_40_2 > 27)
    {
      chk_sum_2 ^= stage_v_40_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_40_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_41_1 = ((st_var_1_1.buffer[2] * 2) + 130) & 63;
  int stage_v_41_2 = ((st_var_1_2.buffer[2] * 2) + 130) & 63;
  if (stage_v_41_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + stage_v_41_1) - 5) & 255;
    if (stage_v_41_1 > 52)
    {
      chk_sum_1 ^= stage_v_41_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_41_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_41_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + stage_v_41_2) - 5) & 255;
    if (stage_v_41_2 > 52)
    {
      chk_sum_2 ^= stage_v_41_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_41_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_42_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_42_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_42_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_42_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_43_1 = 0;
  int stage_v_43_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_43_1 = ((stage_v_43_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_43_2 = ((stage_v_43_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_43_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_43_2) & 255;
  int stage_v_44_1 = table_1[0];
  int stage_v_44_2 = table_2[0];
  table_1[0] = (table_1[1] + 89) & 63;
  table_2[0] = (table_2[1] + 89) & 63;
  out_sink_1 = (out_sink_1 + stage_v_44_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_44_2) & 255;
  int stage_v_45_1 = ((st_var_1_1.buffer[0] * 2) + 142) & 63;
  int stage_v_45_2 = ((st_var_1_2.buffer[0] * 2) + 142) & 63;
  if (stage_v_45_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + stage_v_45_1) - 5) & 255;
    if (stage_v_45_1 > 35)
    {
      chk_sum_1 ^= stage_v_45_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_45_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_45_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + stage_v_45_2) - 5) & 255;
    if (stage_v_45_2 > 35)
    {
      chk_sum_2 ^= stage_v_45_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_45_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_46_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (51 & 31);
  int stage_v_46_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (51 & 31);
  out_sink_1 = (out_sink_1 + stage_v_46_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_46_2) & 255;
  chk_sum_1 ^= (stage_v_46_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_46_2 << 1) & 127;
  int stage_v_47_1 = (st_var_1_1.buffer[0] ^ 50) & 3;
  int stage_v_47_2 = (st_var_1_2.buffer[0] ^ 50) & 3;
  switch (stage_v_47_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 4) & 255;
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

  switch (stage_v_47_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 4) & 255;
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

  int stage_v_48_1 = (st_var_0_1.buffer[0] ^ 51) & 3;
  int stage_v_48_2 = (st_var_0_2.buffer[0] ^ 51) & 3;
  switch (stage_v_48_1)
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

  switch (stage_v_48_2)
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

  int stage_v_49_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_49_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_49_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_49_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_50_1 = table_1[2];
  int stage_v_50_2 = table_2[2];
  table_1[2] = (table_1[3] + 101) & 63;
  table_2[2] = (table_2[3] + 101) & 63;
  out_sink_1 = (out_sink_1 + stage_v_50_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_50_2) & 255;
  int stage_v_51_1 = table_1[3];
  int stage_v_51_2 = table_2[3];
  table_1[3] = (table_1[0] + 103) & 63;
  table_2[3] = (table_2[0] + 103) & 63;
  out_sink_1 = (out_sink_1 + stage_v_51_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_51_2) & 255;
  int stage_v_52_1 = (st_var_0_1.buffer[0] ^ 55) & 3;
  int stage_v_52_2 = (st_var_0_2.buffer[0] ^ 55) & 3;
  switch (stage_v_52_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_52_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_53_1 = (st_var_1_1.buffer[0] ^ 56) & 3;
  int stage_v_53_2 = (st_var_1_2.buffer[0] ^ 56) & 3;
  switch (stage_v_53_1)
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

  switch (stage_v_53_2)
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

  int stage_v_54_1 = ((st_var_0_1.buffer[0] * 2) + 169) & 63;
  int stage_v_54_2 = ((st_var_0_2.buffer[0] * 2) + 169) & 63;
  if (stage_v_54_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + stage_v_54_1) - 5) & 255;
    if (stage_v_54_1 > 48)
    {
      chk_sum_1 ^= stage_v_54_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_54_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_54_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + stage_v_54_2) - 5) & 255;
    if (stage_v_54_2 > 48)
    {
      chk_sum_2 ^= stage_v_54_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_54_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_55_1 = 0;
  int stage_v_55_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_55_1 = ((stage_v_55_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_55_2 = ((stage_v_55_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_55_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_55_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_55_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_55_2) & 255;
  int stage_v_56_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_56_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[0] = (unsigned char) (stage_v_56_1 & 255);
  u_var_2.raw[0] = (unsigned char) (stage_v_56_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[0]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[0]) & 127;
  int stage_v_57_1 = ((st_var_1_1.buffer[0] * 2) + 178) & 63;
  int stage_v_57_2 = ((st_var_1_2.buffer[0] * 2) + 178) & 63;
  if (stage_v_57_1 > 19)
  {
    out_sink_1 = ((out_sink_1 + stage_v_57_1) - 5) & 255;
    if (stage_v_57_1 > 34)
    {
      chk_sum_1 ^= stage_v_57_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_57_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_57_2 > 19)
  {
    out_sink_2 = ((out_sink_2 + stage_v_57_2) - 5) & 255;
    if (stage_v_57_2 > 34)
    {
      chk_sum_2 ^= stage_v_57_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_57_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_58_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (63 & 31);
  int stage_v_58_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (63 & 31);
  out_sink_1 = (out_sink_1 + stage_v_58_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_58_2) & 255;
  chk_sum_1 ^= (stage_v_58_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_58_2 << 1) & 127;
  int stage_v_59_1 = 0;
  int stage_v_59_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_59_1 = ((stage_v_59_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_59_2 = ((stage_v_59_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_59_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_59_2) & 255;
  int stage_v_60_1 = table_1[0];
  int stage_v_60_2 = table_2[0];
  table_1[0] = (table_1[1] + 121) & 63;
  table_2[0] = (table_2[1] + 121) & 63;
  out_sink_1 = (out_sink_1 + stage_v_60_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_60_2) & 255;
  int stage_v_61_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (66 & 31);
  int stage_v_61_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (66 & 31);
  out_sink_1 = (out_sink_1 + stage_v_61_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_61_2) & 255;
  chk_sum_1 ^= (stage_v_61_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_61_2 << 1) & 127;
  int stage_v_62_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (67 & 31);
  int stage_v_62_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (67 & 31);
  out_sink_1 = (out_sink_1 + stage_v_62_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_62_2) & 255;
  chk_sum_1 ^= (stage_v_62_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_62_2 << 1) & 127;
  st_var_1_1.buffer[0] = (st_var_1_1.buffer[0] + 64) & 15;
  st_var_1_2.buffer[0] = (st_var_1_2.buffer[0] + 64) & 15;
  int stage_v_63_1 = (st_var_1_1.buffer[0] * 3) & 63;
  int stage_v_63_2 = (st_var_1_2.buffer[0] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_63_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_63_2) & 255;
  chk_sum_1 ^= stage_v_63_1;
  chk_sum_2 ^= stage_v_63_2;
  int stage_v_64_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (69 & 31);
  int stage_v_64_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (69 & 31);
  out_sink_1 = (out_sink_1 + stage_v_64_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_64_2) & 255;
  chk_sum_1 ^= (stage_v_64_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_64_2 << 1) & 127;
  int stage_v_65_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (70 & 31);
  int stage_v_65_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (70 & 31);
  out_sink_1 = (out_sink_1 + stage_v_65_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_65_2) & 255;
  chk_sum_1 ^= (stage_v_65_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_65_2 << 1) & 127;
  int stage_v_66_1 = table_1[2];
  int stage_v_66_2 = table_2[2];
  table_1[2] = (table_1[3] + 133) & 63;
  table_2[2] = (table_2[3] + 133) & 63;
  out_sink_1 = (out_sink_1 + stage_v_66_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_66_2) & 255;
  int stage_v_67_1 = (st_var_1_1.buffer[0] ^ 70) & 3;
  int stage_v_67_2 = (st_var_1_2.buffer[0] ^ 70) & 3;
  switch (stage_v_67_1)
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

  switch (stage_v_67_2)
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

  st_var_0_1.buffer[2] = (st_var_0_1.buffer[2] + 69) & 15;
  st_var_0_2.buffer[2] = (st_var_0_2.buffer[2] + 69) & 15;
  int stage_v_68_1 = (st_var_0_1.buffer[2] * 3) & 63;
  int stage_v_68_2 = (st_var_0_2.buffer[2] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_68_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_68_2) & 255;
  chk_sum_1 ^= stage_v_68_1;
  chk_sum_2 ^= stage_v_68_2;
  int stage_v_69_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_69_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[1] = (unsigned char) (stage_v_69_1 & 255);
  u_var_2.raw[1] = (unsigned char) (stage_v_69_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[1]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[1]) & 127;
  int stage_v_70_1 = (st_var_0_1.buffer[0] ^ 73) & 3;
  int stage_v_70_2 = (st_var_0_2.buffer[0] ^ 73) & 3;
  switch (stage_v_70_1)
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

  switch (stage_v_70_2)
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

  int stage_v_71_1 = 0;
  int stage_v_71_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_71_1 = ((stage_v_71_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_71_2 = ((stage_v_71_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_71_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_71_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_71_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_71_2) & 255;
  int stage_v_72_1 = 0;
  int stage_v_72_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_72_1 = ((stage_v_72_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_72_2 = ((stage_v_72_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_72_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_72_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_72_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_72_2) & 255;
  int stage_v_73_1 = table_1[1];
  int stage_v_73_2 = table_2[1];
  table_1[1] = (table_1[2] + 147) & 63;
  table_2[1] = (table_2[2] + 147) & 63;
  out_sink_1 = (out_sink_1 + stage_v_73_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_73_2) & 255;
  int stage_v_74_1 = (st_var_0_1.buffer[0] ^ 77) & 3;
  int stage_v_74_2 = (st_var_0_2.buffer[0] ^ 77) & 3;
  switch (stage_v_74_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 6) & 255;
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

  switch (stage_v_74_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 6) & 255;
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

  int stage_v_75_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_75_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[3] = (unsigned char) (stage_v_75_1 & 255);
  u_var_2.raw[3] = (unsigned char) (stage_v_75_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[3]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[3]) & 127;
  int stage_v_76_1 = (st_var_0_1.buffer[0] ^ 79) & 3;
  int stage_v_76_2 = (st_var_0_2.buffer[0] ^ 79) & 3;
  switch (stage_v_76_1)
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

  switch (stage_v_76_2)
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

  int stage_v_77_1 = table_1[1];
  int stage_v_77_2 = table_2[1];
  table_1[1] = (table_1[2] + 155) & 63;
  table_2[1] = (table_2[2] + 155) & 63;
  out_sink_1 = (out_sink_1 + stage_v_77_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_77_2) & 255;
  int stage_v_78_1 = 0;
  int stage_v_78_2 = 0;
  for (int step_1 = 0, step_2 = 0; (step_1 < 2) && (step_2 < 2); step_1++, step_2++)
  {
    stage_v_78_1 = ((stage_v_78_1 + (step_1 * 5)) + table_1[step_1]) & 63;
    stage_v_78_2 = ((stage_v_78_2 + (step_2 * 5)) + table_2[step_2]) & 63;
    chk_sum_1 = (chk_sum_1 + stage_v_78_1) & 127;
    chk_sum_2 = (chk_sum_2 + stage_v_78_2) & 127;
  }

  out_sink_1 = (out_sink_1 + stage_v_78_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_78_2) & 255;
  int stage_v_79_1 = (st_var_1_1.buffer[0] ^ 82) & 3;
  int stage_v_79_2 = (st_var_1_2.buffer[0] ^ 82) & 3;
  switch (stage_v_79_1)
  {
    case 0:
      out_sink_1 = (out_sink_1 + 9) & 255;
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

  switch (stage_v_79_2)
  {
    case 0:
      out_sink_2 = (out_sink_2 + 9) & 255;
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

  int stage_v_80_1 = (st_var_0_1.buffer[0] ^ 83) & 3;
  int stage_v_80_2 = (st_var_0_2.buffer[0] ^ 83) & 3;
  switch (stage_v_80_1)
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

  switch (stage_v_80_2)
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

  int stage_v_81_1 = table_1[1];
  int stage_v_81_2 = table_2[1];
  table_1[1] = (table_1[2] + 163) & 63;
  table_2[1] = (table_2[2] + 163) & 63;
  out_sink_1 = (out_sink_1 + stage_v_81_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_81_2) & 255;
  st_var_0_1.buffer[1] = (st_var_0_1.buffer[1] + 83) & 15;
  st_var_0_2.buffer[1] = (st_var_0_2.buffer[1] + 83) & 15;
  int stage_v_82_1 = (st_var_0_1.buffer[1] * 3) & 63;
  int stage_v_82_2 = (st_var_0_2.buffer[1] * 3) & 63;
  out_sink_1 = (out_sink_1 + stage_v_82_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_82_2) & 255;
  chk_sum_1 ^= stage_v_82_1;
  chk_sum_2 ^= stage_v_82_2;
  int stage_v_83_1 = table_1[3];
  int stage_v_83_2 = table_2[3];
  table_1[3] = (table_1[0] + 167) & 63;
  table_2[3] = (table_2[0] + 167) & 63;
  out_sink_1 = (out_sink_1 + stage_v_83_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_83_2) & 255;
  int stage_v_84_1 = ((st_var_0_1.buffer[0] * 2) + 259) & 63;
  int stage_v_84_2 = ((st_var_0_2.buffer[0] * 2) + 259) & 63;
  if (stage_v_84_1 > 12)
  {
    out_sink_1 = ((out_sink_1 + stage_v_84_1) - 5) & 255;
    if (stage_v_84_1 > 27)
    {
      chk_sum_1 ^= stage_v_84_1 & 31;
    }
    else
    {
      chk_sum_1 = (chk_sum_1 + 3) & 127;
    }
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_84_1) + 9) & 255;
    chk_sum_1 ^= 0x1A;
  }
  if (stage_v_84_2 > 12)
  {
    out_sink_2 = ((out_sink_2 + stage_v_84_2) - 5) & 255;
    if (stage_v_84_2 > 27)
    {
      chk_sum_2 ^= stage_v_84_2 & 31;
    }
    else
    {
      chk_sum_2 = (chk_sum_2 + 3) & 127;
    }
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_84_2) + 9) & 255;
    chk_sum_2 ^= 0x1A;
  }
  int stage_v_85_1 = table_1[1];
  int stage_v_85_2 = table_2[1];
  table_1[1] = (table_1[2] + 171) & 63;
  table_2[1] = (table_2[2] + 171) & 63;
  out_sink_1 = (out_sink_1 + stage_v_85_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_85_2) & 255;
  int stage_v_86_1 = ((out_sink_1 << 1) ^ (chk_sum_1 >> 1)) & 63;
  int stage_v_86_2 = ((out_sink_2 << 1) ^ (chk_sum_2 >> 1)) & 63;
  u_var_1.raw[2] = (unsigned char) (stage_v_86_1 & 255);
  u_var_2.raw[2] = (unsigned char) (stage_v_86_2 & 255);
  chk_sum_1 = (chk_sum_1 ^ u_var_1.raw[2]) & 127;
  chk_sum_2 = (chk_sum_2 ^ u_var_2.raw[2]) & 127;
  int stage_v_87_1 = (out_sink_1 > 100) ? (chk_sum_1 & 31) : (92 & 31);
  int stage_v_87_2 = (out_sink_2 > 100) ? (chk_sum_2 & 31) : (92 & 31);
  out_sink_1 = (out_sink_1 + stage_v_87_1) & 255;
  out_sink_2 = (out_sink_2 + stage_v_87_2) & 255;
  chk_sum_1 ^= (stage_v_87_1 << 1) & 127;
  chk_sum_2 ^= (stage_v_87_2 << 1) & 127;
  int stage_v_88_1 = ((sec_r000740_10_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_88_2 = ((sec_r000740_10_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_88_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_88_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_88_1) + 13) & 255;
  }
  if (stage_v_88_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_88_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_88_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  int stage_v_89_1 = ((stage_v_88_1 ^ 0x2A) + pub_r000740_17_1) & 127;
  int stage_v_89_2 = ((stage_v_88_2 ^ 0x2A) + pub_r000740_17_2) & 127;
  if (stage_v_89_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_89_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_89_1) + 13) & 255;
  }
  if (stage_v_89_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_89_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_89_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_89_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_89_2) & 255;
  int stage_v_90_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_90_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_90_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_90_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_90_1) + 13) & 255;
  }
  if (stage_v_90_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_90_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_90_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_90_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_90_2) & 255;
  int stage_v_91_1 = ((sec_r000740_0_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_91_2 = ((sec_r000740_0_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_91_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_91_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_91_1) + 13) & 255;
  }
  if (stage_v_91_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_91_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_91_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  int stage_v_92_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_92_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_92_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_92_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_92_1) + 13) & 255;
  }
  if (stage_v_92_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_92_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_92_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_92_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_92_2) & 255;
  int stage_v_93_1 = ((sec_r000740_8_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_93_2 = ((sec_r000740_8_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_93_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_93_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_93_1) + 13) & 255;
  }
  if (stage_v_93_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_93_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_93_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_93_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_93_2) & 255;
  int stage_v_94_1 = ((stage_v_88_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_94_2 = ((stage_v_88_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_94_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_94_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_94_1) + 13) & 255;
  }
  if (stage_v_94_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_94_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_94_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_94_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_94_2) & 255;
  int stage_v_95_1 = ((sec_r000740_13_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_95_2 = ((sec_r000740_13_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_95_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_95_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_95_1) + 13) & 255;
  }
  if (stage_v_95_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_95_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_95_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_95_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_95_2) & 255;
  int stage_v_96_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_96_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_96_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_96_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_96_1) + 13) & 255;
  }
  if (stage_v_96_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_96_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_96_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  int stage_v_97_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_97_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_97_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_97_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_97_1) + 13) & 255;
  }
  if (stage_v_97_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_97_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_97_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_97_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_97_2) & 255;
  int stage_v_98_1 = ((stage_v_91_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_98_2 = ((stage_v_91_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_98_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_98_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_98_1) + 13) & 255;
  }
  if (stage_v_98_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_98_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_98_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  int stage_v_99_1 = ((sec_r000740_21_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_99_2 = ((sec_r000740_21_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_99_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_99_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_99_1) + 13) & 255;
  }
  if (stage_v_99_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_99_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_99_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  int stage_v_100_1 = ((sec_r000740_10_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_100_2 = ((sec_r000740_10_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_100_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_100_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_100_1) + 13) & 255;
  }
  if (stage_v_100_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_100_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_100_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_100_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_100_2) & 255;
  int stage_v_101_1 = ((stage_v_91_1 ^ 0x2A) + pub_r000740_10_1) & 127;
  int stage_v_101_2 = ((stage_v_91_2 ^ 0x2A) + pub_r000740_10_2) & 127;
  if (stage_v_101_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_101_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_101_1) + 13) & 255;
  }
  if (stage_v_101_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_101_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_101_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_101_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_101_2) & 255;
  int stage_v_102_1 = ((stage_v_88_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_102_2 = ((stage_v_88_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_102_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_102_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_102_1) + 13) & 255;
  }
  if (stage_v_102_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_102_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_102_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_102_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_102_2) & 255;
  int stage_v_103_1 = ((stage_v_98_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_103_2 = ((stage_v_98_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_103_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_103_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_103_1) + 13) & 255;
  }
  if (stage_v_103_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_103_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_103_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_103_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_103_2) & 255;
  int stage_v_104_1 = ((sec_r000740_10_1 ^ 0x2A) + pub_r000740_17_1) & 127;
  int stage_v_104_2 = ((sec_r000740_10_2 ^ 0x2A) + pub_r000740_17_2) & 127;
  if (stage_v_104_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_104_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_104_1) + 13) & 255;
  }
  if (stage_v_104_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_104_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_104_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  int stage_v_105_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_105_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_105_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_105_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_105_1) + 13) & 255;
  }
  if (stage_v_105_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_105_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_105_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_105_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_105_2) & 255;
  int stage_v_106_1 = ((stage_v_95_1 ^ 0x2A) + pub_r000740_6_1) & 127;
  int stage_v_106_2 = ((stage_v_95_2 ^ 0x2A) + pub_r000740_6_2) & 127;
  if (stage_v_106_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_106_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_106_1) + 13) & 255;
  }
  if (stage_v_106_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_106_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_106_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_106_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_106_2) & 255;
  int stage_v_107_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_107_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_107_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_107_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_107_1) + 13) & 255;
  }
  if (stage_v_107_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_107_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_107_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_107_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_107_2) & 255;
  int stage_v_108_1 = ((sec_r000740_12_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_108_2 = ((sec_r000740_12_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_108_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_108_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_108_1) + 13) & 255;
  }
  if (stage_v_108_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_108_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_108_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_108_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_108_2) & 255;
  int stage_v_109_1 = ((stage_v_105_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_109_2 = ((stage_v_105_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_109_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_109_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_109_1) + 13) & 255;
  }
  if (stage_v_109_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_109_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_109_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_109_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_109_2) & 255;
  int stage_v_110_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_110_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_110_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_110_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_110_1) + 13) & 255;
  }
  if (stage_v_110_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_110_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_110_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_110_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_110_2) & 255;
  int stage_v_111_1 = ((stage_v_106_1 ^ 0x2A) + pub_r000740_0_1) & 127;
  int stage_v_111_2 = ((stage_v_106_2 ^ 0x2A) + pub_r000740_0_2) & 127;
  if (stage_v_111_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_111_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_111_1) + 13) & 255;
  }
  if (stage_v_111_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_111_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_111_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_111_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_111_2) & 255;
  int stage_v_112_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000740_19_1) & 127;
  int stage_v_112_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000740_19_2) & 127;
  if (stage_v_112_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_112_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_112_1) + 13) & 255;
  }
  if (stage_v_112_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_112_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_112_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_112_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_112_2) & 255;
  int stage_v_113_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_113_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_113_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_113_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_113_1) + 13) & 255;
  }
  if (stage_v_113_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_113_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_113_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  int stage_v_114_1 = ((sec_r000740_0_1 ^ 0x2A) + pub_r000740_2_1) & 127;
  int stage_v_114_2 = ((sec_r000740_0_2 ^ 0x2A) + pub_r000740_2_2) & 127;
  if (stage_v_114_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_114_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_114_1) + 13) & 255;
  }
  if (stage_v_114_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_114_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_114_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_114_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_114_2) & 255;
  int stage_v_115_1 = ((sec_r000740_2_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_115_2 = ((sec_r000740_2_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_115_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_115_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_115_1) + 13) & 255;
  }
  if (stage_v_115_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_115_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_115_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_115_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_115_2) & 255;
  int stage_v_116_1 = ((stage_v_101_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_116_2 = ((stage_v_101_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_116_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_116_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_116_1) + 13) & 255;
  }
  if (stage_v_116_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_116_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_116_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_116_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_116_2) & 255;
  int stage_v_117_1 = ((sec_r000740_16_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_117_2 = ((sec_r000740_16_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_117_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_117_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_117_1) + 13) & 255;
  }
  if (stage_v_117_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_117_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_117_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_117_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_117_2) & 255;
  int stage_v_118_1 = ((sec_r000740_15_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_118_2 = ((sec_r000740_15_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_118_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_118_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_118_1) + 13) & 255;
  }
  if (stage_v_118_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_118_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_118_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_118_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_118_2) & 255;
  int stage_v_119_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_119_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_119_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_119_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_119_1) + 13) & 255;
  }
  if (stage_v_119_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_119_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_119_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_119_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_119_2) & 255;
  int stage_v_120_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_120_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_120_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_120_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_120_1) + 13) & 255;
  }
  if (stage_v_120_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_120_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_120_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  int stage_v_121_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_121_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_121_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_121_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_121_1) + 13) & 255;
  }
  if (stage_v_121_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_121_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_121_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_121_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_121_2) & 255;
  int stage_v_122_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_122_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_122_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_122_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_122_1) + 13) & 255;
  }
  if (stage_v_122_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_122_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_122_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_122_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_122_2) & 255;
  int stage_v_123_1 = ((stage_v_119_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_123_2 = ((stage_v_119_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_123_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_123_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_123_1) + 13) & 255;
  }
  if (stage_v_123_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_123_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_123_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_123_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_123_2) & 255;
  int stage_v_124_1 = ((sec_r000740_11_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_124_2 = ((sec_r000740_11_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_124_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_124_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_124_1) + 13) & 255;
  }
  if (stage_v_124_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_124_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_124_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_124_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_124_2) & 255;
  int stage_v_125_1 = ((stage_v_119_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_125_2 = ((stage_v_119_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_125_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_125_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_125_1) + 13) & 255;
  }
  if (stage_v_125_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_125_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_125_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_125_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_125_2) & 255;
  int stage_v_126_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_126_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_126_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_126_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_126_1) + 13) & 255;
  }
  if (stage_v_126_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_126_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_126_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_126_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_126_2) & 255;
  int stage_v_127_1 = ((stage_v_109_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_127_2 = ((stage_v_109_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_127_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_127_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_127_1) + 13) & 255;
  }
  if (stage_v_127_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_127_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_127_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_127_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_127_2) & 255;
  int stage_v_128_1 = ((stage_v_102_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_128_2 = ((stage_v_102_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_128_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_128_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_128_1) + 13) & 255;
  }
  if (stage_v_128_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_128_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_128_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_128_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_128_2) & 255;
  int stage_v_129_1 = ((sec_r000740_15_1 ^ 0x2A) + pub_r000740_10_1) & 127;
  int stage_v_129_2 = ((sec_r000740_15_2 ^ 0x2A) + pub_r000740_10_2) & 127;
  if (stage_v_129_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_129_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_129_1) + 13) & 255;
  }
  if (stage_v_129_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_129_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_129_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  int stage_v_130_1 = ((sec_r000740_6_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_130_2 = ((sec_r000740_6_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_130_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_130_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_130_1) + 13) & 255;
  }
  if (stage_v_130_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_130_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_130_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  int stage_v_131_1 = ((sec_r000740_17_1 ^ 0x2A) + pub_r000740_2_1) & 127;
  int stage_v_131_2 = ((sec_r000740_17_2 ^ 0x2A) + pub_r000740_2_2) & 127;
  if (stage_v_131_1 > 27)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_131_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_131_1) + 13) & 255;
  }
  if (stage_v_131_2 > 27)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_131_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_131_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_131_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_131_2) & 255;
  int stage_v_132_1 = ((sec_r000740_4_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_132_2 = ((sec_r000740_4_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_132_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_132_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_132_1) + 13) & 255;
  }
  if (stage_v_132_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_132_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_132_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_132_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_132_2) & 255;
  int stage_v_133_1 = ((sec_r000740_21_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_133_2 = ((sec_r000740_21_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_133_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_133_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_133_1) + 13) & 255;
  }
  if (stage_v_133_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_133_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_133_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  int stage_v_134_1 = ((sec_r000740_0_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_134_2 = ((sec_r000740_0_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_134_1 > 23)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_134_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_134_1) + 13) & 255;
  }
  if (stage_v_134_2 > 23)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_134_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_134_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_134_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_134_2) & 255;
  int stage_v_135_1 = ((sec_r000740_6_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_135_2 = ((sec_r000740_6_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_135_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_135_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_135_1) + 13) & 255;
  }
  if (stage_v_135_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_135_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_135_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_135_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_135_2) & 255;
  int stage_v_136_1 = ((stage_v_117_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_136_2 = ((stage_v_117_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_136_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_136_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_136_1) + 13) & 255;
  }
  if (stage_v_136_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_136_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_136_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_136_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_136_2) & 255;
  int stage_v_137_1 = ((stage_v_110_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_137_2 = ((stage_v_110_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_137_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_137_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_137_1) + 13) & 255;
  }
  if (stage_v_137_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_137_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_137_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_137_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_137_2) & 255;
  int stage_v_138_1 = ((stage_v_97_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_138_2 = ((stage_v_97_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_138_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_138_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_138_1) + 13) & 255;
  }
  if (stage_v_138_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_138_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_138_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_138_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_138_2) & 255;
  int stage_v_139_1 = ((stage_v_135_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_139_2 = ((stage_v_135_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_139_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_139_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_139_1) + 13) & 255;
  }
  if (stage_v_139_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_139_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_139_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_139_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_139_2) & 255;
  int stage_v_140_1 = ((stage_v_130_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_140_2 = ((stage_v_130_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_140_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_140_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_140_1) + 13) & 255;
  }
  if (stage_v_140_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_140_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_140_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  int stage_v_141_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_0_1) & 127;
  int stage_v_141_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_0_2) & 127;
  if (stage_v_141_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_141_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_141_1) + 13) & 255;
  }
  if (stage_v_141_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_141_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_141_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  int stage_v_142_1 = ((stage_v_126_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_142_2 = ((stage_v_126_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_142_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_142_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_142_1) + 13) & 255;
  }
  if (stage_v_142_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_142_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_142_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  int stage_v_143_1 = ((stage_v_136_1 ^ 0x2A) + pub_r000740_6_1) & 127;
  int stage_v_143_2 = ((stage_v_136_2 ^ 0x2A) + pub_r000740_6_2) & 127;
  if (stage_v_143_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_143_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_143_1) + 13) & 255;
  }
  if (stage_v_143_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_143_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_143_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_143_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_143_2) & 255;
  int stage_v_144_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000740_6_1) & 127;
  int stage_v_144_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000740_6_2) & 127;
  if (stage_v_144_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_144_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_144_1) + 13) & 255;
  }
  if (stage_v_144_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_144_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_144_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  int stage_v_145_1 = ((stage_v_121_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_145_2 = ((stage_v_121_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_145_1 > 21)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_145_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_145_1) + 13) & 255;
  }
  if (stage_v_145_2 > 21)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_145_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_145_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_145_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_145_2) & 255;
  int stage_v_146_1 = ((sec_r000740_11_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_146_2 = ((sec_r000740_11_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_146_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_146_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_146_1) + 13) & 255;
  }
  if (stage_v_146_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_146_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_146_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_146_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_146_2) & 255;
  int stage_v_147_1 = ((sec_r000740_10_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_147_2 = ((sec_r000740_10_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_147_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_147_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_147_1) + 13) & 255;
  }
  if (stage_v_147_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_147_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_147_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_147_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_147_2) & 255;
  int stage_v_148_1 = ((stage_v_124_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_148_2 = ((stage_v_124_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_148_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_148_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_148_1) + 13) & 255;
  }
  if (stage_v_148_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_148_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_148_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_148_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_148_2) & 255;
  int stage_v_149_1 = ((sec_r000740_13_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_149_2 = ((sec_r000740_13_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_149_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_149_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_149_1) + 13) & 255;
  }
  if (stage_v_149_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_149_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_149_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_149_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_149_2) & 255;
  int stage_v_150_1 = ((stage_v_134_1 ^ 0x2A) + pub_r000740_16_1) & 127;
  int stage_v_150_2 = ((stage_v_134_2 ^ 0x2A) + pub_r000740_16_2) & 127;
  if (stage_v_150_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_150_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_150_1) + 13) & 255;
  }
  if (stage_v_150_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_150_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_150_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  int stage_v_151_1 = ((sec_r000740_1_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_151_2 = ((sec_r000740_1_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_151_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_151_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_151_1) + 13) & 255;
  }
  if (stage_v_151_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_151_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_151_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_151_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_151_2) & 255;
  int stage_v_152_1 = ((stage_v_105_1 ^ 0x2A) + pub_r000740_17_1) & 127;
  int stage_v_152_2 = ((stage_v_105_2 ^ 0x2A) + pub_r000740_17_2) & 127;
  if (stage_v_152_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_152_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_152_1) + 13) & 255;
  }
  if (stage_v_152_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_152_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_152_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  int stage_v_153_1 = ((stage_v_143_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_153_2 = ((stage_v_143_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_153_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_153_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_153_1) + 13) & 255;
  }
  if (stage_v_153_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_153_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_153_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_153_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_153_2) & 255;
  int stage_v_154_1 = ((stage_v_132_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_154_2 = ((stage_v_132_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_154_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_154_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_154_1) + 13) & 255;
  }
  if (stage_v_154_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_154_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_154_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_154_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_154_2) & 255;
  int stage_v_155_1 = ((stage_v_145_1 ^ 0x2A) + pub_r000740_2_1) & 127;
  int stage_v_155_2 = ((stage_v_145_2 ^ 0x2A) + pub_r000740_2_2) & 127;
  if (stage_v_155_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_155_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_155_1) + 13) & 255;
  }
  if (stage_v_155_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_155_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_155_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_155_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_155_2) & 255;
  int stage_v_156_1 = ((sec_r000740_19_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_156_2 = ((sec_r000740_19_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_156_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_156_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_156_1) + 13) & 255;
  }
  if (stage_v_156_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_156_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_156_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_156_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_156_2) & 255;
  int stage_v_157_1 = ((sec_r000740_7_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_157_2 = ((sec_r000740_7_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_157_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_157_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_157_1) + 13) & 255;
  }
  if (stage_v_157_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_157_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_157_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  int stage_v_158_1 = ((sec_r000740_11_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_158_2 = ((sec_r000740_11_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_158_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_158_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_158_1) + 13) & 255;
  }
  if (stage_v_158_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_158_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_158_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_158_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_158_2) & 255;
  int stage_v_159_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000740_16_1) & 127;
  int stage_v_159_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000740_16_2) & 127;
  if (stage_v_159_1 > 41)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_159_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_159_1) + 13) & 255;
  }
  if (stage_v_159_2 > 41)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_159_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_159_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_159_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_159_2) & 255;
  int stage_v_160_1 = ((stage_v_121_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_160_2 = ((stage_v_121_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_160_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_160_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_160_1) + 13) & 255;
  }
  if (stage_v_160_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_160_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_160_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_160_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_160_2) & 255;
  int stage_v_161_1 = ((sec_r000740_7_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_161_2 = ((sec_r000740_7_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_161_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_161_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_161_1) + 13) & 255;
  }
  if (stage_v_161_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_161_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_161_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_161_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_161_2) & 255;
  int stage_v_162_1 = ((stage_v_123_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_162_2 = ((stage_v_123_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_162_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_162_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_162_1) + 13) & 255;
  }
  if (stage_v_162_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_162_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_162_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_162_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_162_2) & 255;
  int stage_v_163_1 = ((stage_v_112_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_163_2 = ((stage_v_112_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_163_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_163_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_163_1) + 13) & 255;
  }
  if (stage_v_163_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_163_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_163_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_163_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_163_2) & 255;
  int stage_v_164_1 = ((stage_v_143_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_164_2 = ((stage_v_143_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_164_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_164_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_164_1) + 13) & 255;
  }
  if (stage_v_164_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_164_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_164_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_164_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_164_2) & 255;
  int stage_v_165_1 = ((sec_r000740_15_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_165_2 = ((sec_r000740_15_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_165_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_165_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_165_1) + 13) & 255;
  }
  if (stage_v_165_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_165_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_165_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_165_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_165_2) & 255;
  int stage_v_166_1 = ((sec_r000740_20_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_166_2 = ((sec_r000740_20_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_166_1 > 25)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_166_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_166_1) + 13) & 255;
  }
  if (stage_v_166_2 > 25)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_166_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_166_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  int stage_v_167_1 = ((sec_r000740_18_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_167_2 = ((sec_r000740_18_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_167_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_167_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_167_1) + 13) & 255;
  }
  if (stage_v_167_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_167_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_167_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  int stage_v_168_1 = ((stage_v_113_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_168_2 = ((stage_v_113_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_168_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_168_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_168_1) + 13) & 255;
  }
  if (stage_v_168_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_168_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_168_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  int stage_v_169_1 = ((stage_v_155_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_169_2 = ((stage_v_155_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_169_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_169_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_169_1) + 13) & 255;
  }
  if (stage_v_169_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_169_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_169_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  int stage_v_170_1 = ((stage_v_157_1 ^ 0x2A) + pub_r000740_16_1) & 127;
  int stage_v_170_2 = ((stage_v_157_2 ^ 0x2A) + pub_r000740_16_2) & 127;
  if (stage_v_170_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_170_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_170_1) + 13) & 255;
  }
  if (stage_v_170_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_170_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_170_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_170_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_170_2) & 255;
  int stage_v_171_1 = ((sec_r000740_19_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_171_2 = ((sec_r000740_19_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_171_1 > 22)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_171_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_171_1) + 13) & 255;
  }
  if (stage_v_171_2 > 22)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_171_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_171_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_171_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_171_2) & 255;
  int stage_v_172_1 = ((sec_r000740_19_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_172_2 = ((sec_r000740_19_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_172_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_172_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_172_1) + 13) & 255;
  }
  if (stage_v_172_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_172_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_172_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  int stage_v_173_1 = ((stage_v_154_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_173_2 = ((stage_v_154_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_173_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_173_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_173_1) + 13) & 255;
  }
  if (stage_v_173_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_173_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_173_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_173_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_173_2) & 255;
  int stage_v_174_1 = ((sec_r000740_8_1 ^ 0x2A) + pub_r000740_17_1) & 127;
  int stage_v_174_2 = ((sec_r000740_8_2 ^ 0x2A) + pub_r000740_17_2) & 127;
  if (stage_v_174_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_174_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_174_1) + 13) & 255;
  }
  if (stage_v_174_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_174_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_174_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_174_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_174_2) & 255;
  int stage_v_175_1 = ((sec_r000740_0_1 ^ 0x2A) + pub_r000740_1_1) & 127;
  int stage_v_175_2 = ((sec_r000740_0_2 ^ 0x2A) + pub_r000740_1_2) & 127;
  if (stage_v_175_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_175_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_175_1) + 13) & 255;
  }
  if (stage_v_175_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_175_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_175_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_175_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_175_2) & 255;
  int stage_v_176_1 = ((stage_v_108_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_176_2 = ((stage_v_108_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_176_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_176_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_176_1) + 13) & 255;
  }
  if (stage_v_176_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_176_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_176_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_176_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_176_2) & 255;
  int stage_v_177_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_6_1) & 127;
  int stage_v_177_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_6_2) & 127;
  if (stage_v_177_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_177_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_177_1) + 13) & 255;
  }
  if (stage_v_177_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_177_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_177_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_177_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_177_2) & 255;
  int stage_v_178_1 = ((sec_r000740_5_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_178_2 = ((sec_r000740_5_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_178_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_178_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_178_1) + 13) & 255;
  }
  if (stage_v_178_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_178_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_178_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  int stage_v_179_1 = ((stage_v_151_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_179_2 = ((stage_v_151_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_179_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_179_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_179_1) + 13) & 255;
  }
  if (stage_v_179_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_179_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_179_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_179_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_179_2) & 255;
  int stage_v_180_1 = ((stage_v_107_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_180_2 = ((stage_v_107_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_180_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_180_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_180_1) + 13) & 255;
  }
  if (stage_v_180_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_180_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_180_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  int stage_v_181_1 = ((stage_v_165_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_181_2 = ((stage_v_165_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_181_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_181_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_181_1) + 13) & 255;
  }
  if (stage_v_181_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_181_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_181_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_181_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_181_2) & 255;
  int stage_v_182_1 = ((stage_v_146_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_182_2 = ((stage_v_146_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_182_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_182_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_182_1) + 13) & 255;
  }
  if (stage_v_182_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_182_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_182_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_182_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_182_2) & 255;
  int stage_v_183_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_183_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_183_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_183_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_183_1) + 13) & 255;
  }
  if (stage_v_183_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_183_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_183_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_183_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_183_2) & 255;
  int stage_v_184_1 = ((stage_v_183_1 ^ 0x2A) + pub_r000740_3_1) & 127;
  int stage_v_184_2 = ((stage_v_183_2 ^ 0x2A) + pub_r000740_3_2) & 127;
  if (stage_v_184_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_184_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_184_1) + 13) & 255;
  }
  if (stage_v_184_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_184_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_184_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_184_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_184_2) & 255;
  int stage_v_185_1 = ((sec_r000740_17_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_185_2 = ((sec_r000740_17_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_185_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_185_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_185_1) + 13) & 255;
  }
  if (stage_v_185_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_185_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_185_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_185_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_185_2) & 255;
  int stage_v_186_1 = ((stage_v_147_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_186_2 = ((stage_v_147_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_186_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_186_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_186_1) + 13) & 255;
  }
  if (stage_v_186_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_186_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_186_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  int stage_v_187_1 = ((stage_v_137_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_187_2 = ((stage_v_137_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_187_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_187_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_187_1) + 13) & 255;
  }
  if (stage_v_187_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_187_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_187_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  int stage_v_188_1 = ((stage_v_129_1 ^ 0x2A) + pub_r000740_13_1) & 127;
  int stage_v_188_2 = ((stage_v_129_2 ^ 0x2A) + pub_r000740_13_2) & 127;
  if (stage_v_188_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_188_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_188_1) + 13) & 255;
  }
  if (stage_v_188_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_188_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_188_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_188_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_188_2) & 255;
  int stage_v_189_1 = ((sec_r000740_6_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_189_2 = ((sec_r000740_6_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_189_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_189_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_189_1) + 13) & 255;
  }
  if (stage_v_189_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_189_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_189_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_189_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_189_2) & 255;
  int stage_v_190_1 = ((stage_v_174_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_190_2 = ((stage_v_174_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_190_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_190_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_190_1) + 13) & 255;
  }
  if (stage_v_190_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_190_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_190_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_190_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_190_2) & 255;
  int stage_v_191_1 = ((sec_r000740_3_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_191_2 = ((sec_r000740_3_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_191_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_191_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_191_1) + 13) & 255;
  }
  if (stage_v_191_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_191_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_191_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  int stage_v_192_1 = ((stage_v_143_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_192_2 = ((stage_v_143_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_192_1 > 32)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_192_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_192_1) + 13) & 255;
  }
  if (stage_v_192_2 > 32)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_192_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_192_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  int stage_v_193_1 = ((stage_v_162_1 ^ 0x2A) + pub_r000740_6_1) & 127;
  int stage_v_193_2 = ((stage_v_162_2 ^ 0x2A) + pub_r000740_6_2) & 127;
  if (stage_v_193_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_193_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_193_1) + 13) & 255;
  }
  if (stage_v_193_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_193_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_193_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_193_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_193_2) & 255;
  int stage_v_194_1 = ((stage_v_137_1 ^ 0x2A) + pub_r000740_19_1) & 127;
  int stage_v_194_2 = ((stage_v_137_2 ^ 0x2A) + pub_r000740_19_2) & 127;
  if (stage_v_194_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_194_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_194_1) + 13) & 255;
  }
  if (stage_v_194_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_194_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_194_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_194_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_194_2) & 255;
  int stage_v_195_1 = ((stage_v_118_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_195_2 = ((stage_v_118_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_195_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_195_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_195_1) + 13) & 255;
  }
  if (stage_v_195_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_195_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_195_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_195_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_195_2) & 255;
  int stage_v_196_1 = ((sec_r000740_5_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_196_2 = ((sec_r000740_5_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_196_1 > 39)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_196_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_196_1) + 13) & 255;
  }
  if (stage_v_196_2 > 39)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_196_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_196_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  int stage_v_197_1 = ((sec_r000740_14_1 ^ 0x2A) + pub_r000740_10_1) & 127;
  int stage_v_197_2 = ((sec_r000740_14_2 ^ 0x2A) + pub_r000740_10_2) & 127;
  if (stage_v_197_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_197_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_197_1) + 13) & 255;
  }
  if (stage_v_197_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_197_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_197_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_197_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_197_2) & 255;
  int stage_v_198_1 = ((stage_v_138_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_198_2 = ((stage_v_138_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_198_1 > 31)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_198_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_198_1) + 13) & 255;
  }
  if (stage_v_198_2 > 31)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_198_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_198_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  int stage_v_199_1 = ((stage_v_94_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_199_2 = ((stage_v_94_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_199_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_199_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_199_1) + 13) & 255;
  }
  if (stage_v_199_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_199_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_199_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_199_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_199_2) & 255;
  int stage_v_200_1 = ((stage_v_92_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_200_2 = ((stage_v_92_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_200_1 > 47)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_200_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_200_1) + 13) & 255;
  }
  if (stage_v_200_2 > 47)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_200_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_200_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_200_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_200_2) & 255;
  int stage_v_201_1 = ((sec_r000740_17_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_201_2 = ((sec_r000740_17_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_201_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_201_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_201_1) + 13) & 255;
  }
  if (stage_v_201_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_201_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_201_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  int stage_v_202_1 = ((stage_v_121_1 ^ 0x2A) + pub_r000740_19_1) & 127;
  int stage_v_202_2 = ((stage_v_121_2 ^ 0x2A) + pub_r000740_19_2) & 127;
  if (stage_v_202_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_202_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_202_1) + 13) & 255;
  }
  if (stage_v_202_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_202_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_202_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_202_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_202_2) & 255;
  int stage_v_203_1 = ((sec_r000740_2_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_203_2 = ((sec_r000740_2_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_203_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_203_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_203_1) + 13) & 255;
  }
  if (stage_v_203_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_203_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_203_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_203_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_203_2) & 255;
  int stage_v_204_1 = ((stage_v_93_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_204_2 = ((stage_v_93_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_204_1 > 24)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_204_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_204_1) + 13) & 255;
  }
  if (stage_v_204_2 > 24)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_204_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_204_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  int stage_v_205_1 = ((sec_r000740_18_1 ^ 0x2A) + pub_r000740_11_1) & 127;
  int stage_v_205_2 = ((sec_r000740_18_2 ^ 0x2A) + pub_r000740_11_2) & 127;
  if (stage_v_205_1 > 26)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_205_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_205_1) + 13) & 255;
  }
  if (stage_v_205_2 > 26)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_205_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_205_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  int stage_v_206_1 = ((sec_r000740_12_1 ^ 0x2A) + pub_r000740_19_1) & 127;
  int stage_v_206_2 = ((sec_r000740_12_2 ^ 0x2A) + pub_r000740_19_2) & 127;
  if (stage_v_206_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_206_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_206_1) + 13) & 255;
  }
  if (stage_v_206_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_206_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_206_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  int stage_v_207_1 = ((stage_v_89_1 ^ 0x2A) + pub_r000740_10_1) & 127;
  int stage_v_207_2 = ((stage_v_89_2 ^ 0x2A) + pub_r000740_10_2) & 127;
  if (stage_v_207_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_207_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_207_1) + 13) & 255;
  }
  if (stage_v_207_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_207_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_207_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  int stage_v_208_1 = ((sec_r000740_10_1 ^ 0x2A) + pub_r000740_19_1) & 127;
  int stage_v_208_2 = ((sec_r000740_10_2 ^ 0x2A) + pub_r000740_19_2) & 127;
  if (stage_v_208_1 > 40)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_208_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_208_1) + 13) & 255;
  }
  if (stage_v_208_2 > 40)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_208_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_208_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_208_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_208_2) & 255;
  int stage_v_209_1 = ((stage_v_181_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_209_2 = ((stage_v_181_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_209_1 > 28)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_209_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_209_1) + 13) & 255;
  }
  if (stage_v_209_2 > 28)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_209_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_209_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_209_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_209_2) & 255;
  int stage_v_210_1 = ((stage_v_178_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_210_2 = ((stage_v_178_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_210_1 > 37)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_210_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_210_1) + 13) & 255;
  }
  if (stage_v_210_2 > 37)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_210_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_210_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_210_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_210_2) & 255;
  int stage_v_211_1 = ((stage_v_131_1 ^ 0x2A) + pub_r000740_9_1) & 127;
  int stage_v_211_2 = ((stage_v_131_2 ^ 0x2A) + pub_r000740_9_2) & 127;
  if (stage_v_211_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_211_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_211_1) + 13) & 255;
  }
  if (stage_v_211_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_211_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_211_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_211_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_211_2) & 255;
  int stage_v_212_1 = ((stage_v_114_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_212_2 = ((stage_v_114_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_212_1 > 50)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_212_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_212_1) + 13) & 255;
  }
  if (stage_v_212_2 > 50)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_212_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_212_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_212_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_212_2) & 255;
  int stage_v_213_1 = ((sec_r000740_15_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_213_2 = ((sec_r000740_15_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_213_1 > 42)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_213_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_213_1) + 13) & 255;
  }
  if (stage_v_213_2 > 42)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_213_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_213_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  int stage_v_214_1 = ((sec_r000740_6_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_214_2 = ((sec_r000740_6_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_214_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_214_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_214_1) + 13) & 255;
  }
  if (stage_v_214_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_214_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_214_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_214_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_214_2) & 255;
  int stage_v_215_1 = ((sec_r000740_0_1 ^ 0x2A) + pub_r000740_18_1) & 127;
  int stage_v_215_2 = ((sec_r000740_0_2 ^ 0x2A) + pub_r000740_18_2) & 127;
  if (stage_v_215_1 > 45)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_215_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_215_1) + 13) & 255;
  }
  if (stage_v_215_2 > 45)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_215_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_215_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  int stage_v_216_1 = ((stage_v_126_1 ^ 0x2A) + pub_r000740_2_1) & 127;
  int stage_v_216_2 = ((stage_v_126_2 ^ 0x2A) + pub_r000740_2_2) & 127;
  if (stage_v_216_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_216_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_216_1) + 13) & 255;
  }
  if (stage_v_216_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_216_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_216_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  int stage_v_217_1 = ((stage_v_150_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_217_2 = ((stage_v_150_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_217_1 > 33)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_217_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_217_1) + 13) & 255;
  }
  if (stage_v_217_2 > 33)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_217_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_217_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  int stage_v_218_1 = ((stage_v_116_1 ^ 0x2A) + pub_r000740_16_1) & 127;
  int stage_v_218_2 = ((stage_v_116_2 ^ 0x2A) + pub_r000740_16_2) & 127;
  if (stage_v_218_1 > 30)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_218_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_218_1) + 13) & 255;
  }
  if (stage_v_218_2 > 30)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_218_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_218_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_218_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_218_2) & 255;
  int stage_v_219_1 = ((stage_v_218_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_219_2 = ((stage_v_218_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_219_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_219_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_219_1) + 13) & 255;
  }
  if (stage_v_219_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_219_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_219_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_219_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_219_2) & 255;
  int stage_v_220_1 = ((stage_v_130_1 ^ 0x2A) + pub_r000740_14_1) & 127;
  int stage_v_220_2 = ((stage_v_130_2 ^ 0x2A) + pub_r000740_14_2) & 127;
  if (stage_v_220_1 > 20)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_220_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_220_1) + 13) & 255;
  }
  if (stage_v_220_2 > 20)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_220_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_220_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  int stage_v_221_1 = ((stage_v_136_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_221_2 = ((stage_v_136_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_221_1 > 48)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_221_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_221_1) + 13) & 255;
  }
  if (stage_v_221_2 > 48)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_221_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_221_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_221_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_221_2) & 255;
  int stage_v_222_1 = ((sec_r000740_11_1 ^ 0x2A) + pub_r000740_4_1) & 127;
  int stage_v_222_2 = ((sec_r000740_11_2 ^ 0x2A) + pub_r000740_4_2) & 127;
  if (stage_v_222_1 > 44)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_222_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_222_1) + 13) & 255;
  }
  if (stage_v_222_2 > 44)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_222_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_222_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  int stage_v_223_1 = ((stage_v_100_1 ^ 0x2A) + pub_r000740_8_1) & 127;
  int stage_v_223_2 = ((stage_v_100_2 ^ 0x2A) + pub_r000740_8_2) & 127;
  if (stage_v_223_1 > 34)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_223_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_223_1) + 13) & 255;
  }
  if (stage_v_223_2 > 34)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_223_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_223_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_223_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_223_2) & 255;
  int stage_v_224_1 = ((stage_v_149_1 ^ 0x2A) + pub_r000740_7_1) & 127;
  int stage_v_224_2 = ((stage_v_149_2 ^ 0x2A) + pub_r000740_7_2) & 127;
  if (stage_v_224_1 > 29)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_224_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_224_1) + 13) & 255;
  }
  if (stage_v_224_2 > 29)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_224_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_224_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_224_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_224_2) & 255;
  int stage_v_225_1 = ((stage_v_171_1 ^ 0x2A) + pub_r000740_20_1) & 127;
  int stage_v_225_2 = ((stage_v_171_2 ^ 0x2A) + pub_r000740_20_2) & 127;
  if (stage_v_225_1 > 35)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_225_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_225_1) + 13) & 255;
  }
  if (stage_v_225_2 > 35)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_225_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_225_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  int stage_v_226_1 = ((stage_v_217_1 ^ 0x2A) + pub_r000740_12_1) & 127;
  int stage_v_226_2 = ((stage_v_217_2 ^ 0x2A) + pub_r000740_12_2) & 127;
  if (stage_v_226_1 > 49)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_226_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_226_1) + 13) & 255;
  }
  if (stage_v_226_2 > 49)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_226_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_226_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  int stage_v_227_1 = ((stage_v_138_1 ^ 0x2A) + pub_r000740_5_1) & 127;
  int stage_v_227_2 = ((stage_v_138_2 ^ 0x2A) + pub_r000740_5_2) & 127;
  if (stage_v_227_1 > 46)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_227_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_227_1) + 13) & 255;
  }
  if (stage_v_227_2 > 46)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_227_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_227_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  int stage_v_228_1 = ((sec_r000740_18_1 ^ 0x2A) + pub_r000740_15_1) & 127;
  int stage_v_228_2 = ((sec_r000740_18_2 ^ 0x2A) + pub_r000740_15_2) & 127;
  if (stage_v_228_1 > 43)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_228_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_228_1) + 13) & 255;
  }
  if (stage_v_228_2 > 43)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_228_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_228_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_228_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_228_2) & 255;
  int stage_v_229_1 = ((sec_r000740_3_1 ^ 0x2A) + pub_r000740_16_1) & 127;
  int stage_v_229_2 = ((sec_r000740_3_2 ^ 0x2A) + pub_r000740_16_2) & 127;
  if (stage_v_229_1 > 38)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_229_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_229_1) + 13) & 255;
  }
  if (stage_v_229_2 > 38)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_229_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_229_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  int stage_v_230_1 = ((stage_v_174_1 ^ 0x2A) + pub_r000740_0_1) & 127;
  int stage_v_230_2 = ((stage_v_174_2 ^ 0x2A) + pub_r000740_0_2) & 127;
  if (stage_v_230_1 > 36)
  {
    out_sink_1 = ((out_sink_1 + (stage_v_230_1 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_1 = ((out_sink_1 - stage_v_230_1) + 13) & 255;
  }
  if (stage_v_230_2 > 36)
  {
    out_sink_2 = ((out_sink_2 + (stage_v_230_2 * 2)) + 7) & 255;
  }
  else
  {
    out_sink_2 = ((out_sink_2 - stage_v_230_2) + 13) & 255;
  }
  sec_accum_1 = (sec_accum_1 + stage_v_230_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_230_2) & 255;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r000740_19_1 == pub_r000740_19_2);
  __CPROVER_assume(sec_r000740_7_1 != sec_r000740_7_2);
  __CPROVER_assume(sec_r000740_9_1 != sec_r000740_9_2);
  __CPROVER_assume(pub_r000740_0_1 == pub_r000740_0_2);
  __CPROVER_assume(pub_r000740_12_1 == pub_r000740_12_2);
  __CPROVER_assume(pub_r000740_18_1 == pub_r000740_18_2);
  __CPROVER_assume(pub_r000740_8_1 == pub_r000740_8_2);
  __CPROVER_assume(sec_r000740_8_1 != sec_r000740_8_2);
  __CPROVER_assume(pub_r000740_7_1 == pub_r000740_7_2);
  __CPROVER_assume(sec_r000740_4_1 != sec_r000740_4_2);
  __CPROVER_assume(sec_r000740_1_1 != sec_r000740_1_2);
  __CPROVER_assume(pub_r000740_11_1 == pub_r000740_11_2);
  __CPROVER_assume(sec_r000740_11_1 != sec_r000740_11_2);
  __CPROVER_assume(pub_r000740_3_1 == pub_r000740_3_2);
  __CPROVER_assume(sec_r000740_5_1 != sec_r000740_5_2);
  __CPROVER_assume(sec_r000740_14_1 != sec_r000740_14_2);
  __CPROVER_assume(pub_r000740_5_1 == pub_r000740_5_2);
  __CPROVER_assume(sec_r000740_0_1 != sec_r000740_0_2);
  __CPROVER_assume(sec_r000740_20_1 != sec_r000740_20_2);
  __CPROVER_assume(sec_r000740_3_1 != sec_r000740_3_2);
  __CPROVER_assume(sec_r000740_16_1 != sec_r000740_16_2);
  __CPROVER_assume(pub_r000740_17_1 == pub_r000740_17_2);
  __CPROVER_assume(pub_r000740_1_1 == pub_r000740_1_2);
  __CPROVER_assume(pub_r000740_9_1 == pub_r000740_9_2);
  __CPROVER_assume(sec_r000740_2_1 != sec_r000740_2_2);
  __CPROVER_assume(pub_r000740_10_1 == pub_r000740_10_2);
  __CPROVER_assume(pub_r000740_14_1 == pub_r000740_14_2);
  __CPROVER_assume(pub_r000740_16_1 == pub_r000740_16_2);
  __CPROVER_assume(sec_r000740_21_1 != sec_r000740_21_2);
  __CPROVER_assume(pub_r000740_4_1 == pub_r000740_4_2);
  __CPROVER_assume(sec_r000740_13_1 != sec_r000740_13_2);
  __CPROVER_assume(pub_r000740_2_1 == pub_r000740_2_2);
  __CPROVER_assume(pub_r000740_6_1 == pub_r000740_6_2);
  __CPROVER_assume(pub_r000740_15_1 == pub_r000740_15_2);
  __CPROVER_assume(sec_r000740_17_1 != sec_r000740_17_2);
  __CPROVER_assume(sec_r000740_6_1 != sec_r000740_6_2);
  __CPROVER_assume(sec_r000740_18_1 != sec_r000740_18_2);
  __CPROVER_assume(sec_r000740_12_1 != sec_r000740_12_2);
  __CPROVER_assume(sec_r000740_10_1 != sec_r000740_10_2);
  __CPROVER_assume(sec_r000740_19_1 != sec_r000740_19_2);
  __CPROVER_assume(pub_r000740_20_1 == pub_r000740_20_2);
  __CPROVER_assume(pub_r000740_13_1 == pub_r000740_13_2);
  __CPROVER_assume(sec_r000740_15_1 != sec_r000740_15_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.cutoff == st_var_0_2.cutoff);
  assert(st_var_0_1.prev_in == st_var_0_2.prev_in);
  assert(st_var_0_1.gain_db == st_var_0_2.gain_db);
  assert(st_var_0_1.damping == st_var_0_2.damping);
  assert(st_var_0_1.mode == st_var_0_2.mode);
  assert(st_var_0_1.prev_out == st_var_0_2.prev_out);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.coord_x == st_var_1_2.coord_x);
  assert(st_var_1_1.coord_z == st_var_1_2.coord_z);
  assert(st_var_1_1.coord_y == st_var_1_2.coord_y);
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
}


