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
struct Vector3D_R001492_9213_0
{
  short norm_sq;
  int coord_z;
  short coord_x;
  short heading;
  short pitch;
  int coord_y;
  int buffer[3];
};
struct FilterState_R001492_9213_1
{
  int prev_out;
  short cutoff;
  int gain_db;
  int damping;
  int prev_in;
  int buffer[3];
};
union ColorPixel_R001492_9213_0
{
  int word;
  unsigned char raw[4];
  short pairs[2];
};
union RegisterBank_R001492_9213_1
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
void fn_R001492_9213_0_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 22) & 127;
  int acc_2 = (p0_2 + 22) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int quantum_57_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int quantum_57_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (quantum_57_1 > 46)
  {
    acc_1 = ((acc_1 + (quantum_57_1 * 2)) + 5) & 127;
    aux_1 ^= quantum_57_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - quantum_57_1) + 11) & 127;
    aux_1 += 3;
  }
  if (quantum_57_2 > 46)
  {
    acc_2 = ((acc_2 + (quantum_57_2 * 2)) + 5) & 127;
    aux_2 ^= quantum_57_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - quantum_57_2) + 11) & 127;
    aux_2 += 3;
  }
  int delta_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_97_1) & 63;
  aux_2 = (aux_2 + delta_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(quantum_57_1 == quantum_57_2);
  assert(delta_97_1 == delta_97_2);
}

int fn_R001492_9213_0(int p0, int p1, int p2)
{
  int acc = (p0 + 22) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int quantum_57 = ((st.buffer[0] * 3) + aux) & 63;
  if (quantum_57 > 46)
  {
    acc = ((acc + (quantum_57 * 2)) + 5) & 127;
    aux ^= quantum_57 & 15;
  }
  else
  {
    acc = ((acc - quantum_57) + 11) & 127;
    aux += 3;
  }
  int delta_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_97) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001492_9213_1_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 18;
  st_2.buffer[2] = 18;
  int index_reg_50_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int index_reg_50_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (index_reg_50_1 > 41)
  {
    acc_1 = ((acc_1 + (index_reg_50_1 * 2)) + 5) & 127;
    aux_1 ^= index_reg_50_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - index_reg_50_1) + 11) & 127;
    aux_1 += 3;
  }
  if (index_reg_50_2 > 41)
  {
    acc_2 = ((acc_2 + (index_reg_50_2 * 2)) + 5) & 127;
    aux_2 ^= index_reg_50_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - index_reg_50_2) + 11) & 127;
    aux_2 += 3;
  }
  int metric_20_1 = (aux_1 + st_1.buffer[1]) & 3;
  int metric_20_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (metric_20_1)
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

  switch (metric_20_2)
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
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(index_reg_50_1 == index_reg_50_2);
  assert(metric_20_1 == metric_20_2);
}

int fn_R001492_9213_1(int p0, int p1, int p2)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 18;
  int index_reg_50 = ((st.buffer[0] * 3) + aux) & 63;
  if (index_reg_50 > 41)
  {
    acc = ((acc + (index_reg_50 * 2)) + 5) & 127;
    aux ^= index_reg_50 & 15;
  }
  else
  {
    acc = ((acc - index_reg_50) + 11) & 127;
    aux += 3;
  }
  int metric_20 = (aux + st.buffer[1]) & 3;
  switch (metric_20)
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

void fn_R001492_9213_2_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 16;
  st_2.buffer[2] = 16;
  st_1.buffer[1] = (st_1.buffer[1] + 9) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 9) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int factor_64_1 = local_arr_1[aux_1 % 3];
  int factor_64_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (factor_64_1 * 2)) & 127;
  acc_2 = (acc_2 + (factor_64_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(factor_64_1 == factor_64_2);
}

int fn_R001492_9213_2(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 16;
  st.buffer[1] = (st.buffer[1] + 9) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int factor_64 = local_arr[aux % 3];
  acc = (acc + (factor_64 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001492_9213_3_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 17) & 127;
  int acc_2 = (p0_2 + 17) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 10;
  st_2.buffer[2] = 10;
  int vector_24_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int vector_24_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (vector_24_1 > 47)
  {
    acc_1 = ((acc_1 + (vector_24_1 * 2)) + 5) & 127;
    aux_1 ^= vector_24_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - vector_24_1) + 11) & 127;
    aux_1 += 3;
  }
  if (vector_24_2 > 47)
  {
    acc_2 = ((acc_2 + (vector_24_2 * 2)) + 5) & 127;
    aux_2 ^= vector_24_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - vector_24_2) + 11) & 127;
    aux_2 += 3;
  }
  int residue_38_1 = 0;
  int residue_38_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    residue_38_1 = ((residue_38_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    residue_38_2 = ((residue_38_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + residue_38_1) & 127;
    acc_2 = (acc_2 + residue_38_2) & 127;
  }

  int coefficient_83_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int coefficient_83_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + coefficient_83_1) & 63;
  aux_2 = (aux_2 + coefficient_83_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int sample_91_1 = (aux_1 + st_1.buffer[1]) & 3;
  int sample_91_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (sample_91_1)
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

  switch (sample_91_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(vector_24_1 == vector_24_2);
  assert(residue_38_1 == residue_38_2);
  assert(coefficient_83_1 == coefficient_83_2);
  assert(sample_91_1 == sample_91_2);
}

int fn_R001492_9213_3(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 17) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 10;
  int vector_24 = ((st.buffer[0] * 3) + aux) & 63;
  if (vector_24 > 47)
  {
    acc = ((acc + (vector_24 * 2)) + 5) & 127;
    aux ^= vector_24 & 15;
  }
  else
  {
    acc = ((acc - vector_24) + 11) & 127;
    aux += 3;
  }
  int residue_38 = 0;
  for (int k = 0; k < 2; k++)
  {
    residue_38 = ((residue_38 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + residue_38) & 127;
  }

  int coefficient_83 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + coefficient_83) & 63;
  acc ^= aux;
  int sample_91 = (aux + st.buffer[1]) & 3;
  switch (sample_91)
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

void fn_R001492_9213_4_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 28;
  st_2.buffer[2] = 28;
  int delta_94_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int delta_94_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (delta_94_1 > 31)
  {
    acc_1 = ((acc_1 + (delta_94_1 * 2)) + 5) & 127;
    aux_1 ^= delta_94_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - delta_94_1) + 11) & 127;
    aux_1 += 3;
  }
  if (delta_94_2 > 31)
  {
    acc_2 = ((acc_2 + (delta_94_2 * 2)) + 5) & 127;
    aux_2 ^= delta_94_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - delta_94_2) + 11) & 127;
    aux_2 += 3;
  }
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int window_60_1 = local_arr_1[aux_1 % 3];
  int window_60_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (window_60_1 * 2)) & 127;
  acc_2 = (acc_2 + (window_60_2 * 2)) & 127;
  int mask_97_1 = (aux_1 + st_1.buffer[1]) & 3;
  int mask_97_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (mask_97_1)
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

  switch (mask_97_2)
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
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_94_1 == delta_94_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(window_60_1 == window_60_2);
  assert(mask_97_1 == mask_97_2);
}

int fn_R001492_9213_4(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 28;
  int delta_94 = ((st.buffer[0] * 3) + aux) & 63;
  if (delta_94 > 31)
  {
    acc = ((acc + (delta_94 * 2)) + 5) & 127;
    aux ^= delta_94 & 15;
  }
  else
  {
    acc = ((acc - delta_94) + 11) & 127;
    aux += 3;
  }
  int local_arr[3] = {4, 9, 15};
  int window_60 = local_arr[aux % 3];
  acc = (acc + (window_60 * 2)) & 127;
  int mask_97 = (aux + st.buffer[1]) & 3;
  switch (mask_97)
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

void fn_R001492_9213_5_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 4) & 127;
  int acc_2 = (p0_2 + 4) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 30;
  st_2.buffer[2] = 30;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int residue_77_1 = local_arr_1[aux_1 % 3];
  int residue_77_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (residue_77_1 * 2)) & 127;
  acc_2 = (acc_2 + (residue_77_2 * 2)) & 127;
  st_1.buffer[1] = (st_1.buffer[1] + 8) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 8) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int delta_10_1 = 0;
  int delta_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    delta_10_1 = ((delta_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    delta_10_2 = ((delta_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + delta_10_1) & 127;
    acc_2 = (acc_2 + delta_10_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(residue_77_1 == residue_77_2);
  assert(delta_10_1 == delta_10_2);
}

int fn_R001492_9213_5(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 4) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 30;
  int local_arr[3] = {4, 9, 15};
  int residue_77 = local_arr[aux % 3];
  acc = (acc + (residue_77 * 2)) & 127;
  st.buffer[1] = (st.buffer[1] + 8) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int delta_10 = 0;
  for (int k = 0; k < 3; k++)
  {
    delta_10 = ((delta_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + delta_10) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_6_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 43) & 127;
  int acc_2 = (p0_2 + 43) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 8;
  st_2.buffer[2] = 8;
  int mask_62_1 = 0;
  int mask_62_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    mask_62_1 = ((mask_62_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    mask_62_2 = ((mask_62_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + mask_62_1) & 127;
    acc_2 = (acc_2 + mask_62_2) & 127;
  }

  int delta_24_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_24_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_24_1) & 63;
  aux_2 = (aux_2 + delta_24_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(mask_62_1 == mask_62_2);
  assert(delta_24_1 == delta_24_2);
}

int fn_R001492_9213_6(int p0, int p1, int p2)
{
  int acc = (p0 + 43) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 8;
  int mask_62 = 0;
  for (int k = 0; k < 3; k++)
  {
    mask_62 = ((mask_62 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + mask_62) & 127;
  }

  int delta_24 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_24) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001492_9213_7_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 17;
  st_2.buffer[2] = 17;
  int window_46_1 = 0;
  int window_46_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    window_46_1 = ((window_46_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    window_46_2 = ((window_46_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + window_46_1) & 127;
    acc_2 = (acc_2 + window_46_2) & 127;
  }

  int window_23_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_23_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_23_1 > 26)
  {
    acc_1 = ((acc_1 + (window_23_1 * 2)) + 5) & 127;
    aux_1 ^= window_23_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_23_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_23_2 > 26)
  {
    acc_2 = ((acc_2 + (window_23_2 * 2)) + 5) & 127;
    aux_2 ^= window_23_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_23_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_46_1 == window_46_2);
  assert(window_23_1 == window_23_2);
}

int fn_R001492_9213_7(int p0, int p1, int p2)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 17;
  int window_46 = 0;
  for (int k = 0; k < 3; k++)
  {
    window_46 = ((window_46 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + window_46) & 127;
  }

  int window_23 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_23 > 26)
  {
    acc = ((acc + (window_23 * 2)) + 5) & 127;
    aux ^= window_23 & 15;
  }
  else
  {
    acc = ((acc - window_23) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001492_9213_8_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 36) & 127;
  int acc_2 = (p0_2 + 36) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 29;
  st_2.buffer[2] = 29;
  int window_86_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int window_86_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (window_86_1 > 32)
  {
    acc_1 = ((acc_1 + (window_86_1 * 2)) + 5) & 127;
    aux_1 ^= window_86_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - window_86_1) + 11) & 127;
    aux_1 += 3;
  }
  if (window_86_2 > 32)
  {
    acc_2 = ((acc_2 + (window_86_2 * 2)) + 5) & 127;
    aux_2 ^= window_86_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - window_86_2) + 11) & 127;
    aux_2 += 3;
  }
  int coefficient_54_1 = (aux_1 + st_1.buffer[1]) & 3;
  int coefficient_54_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (coefficient_54_1)
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

  switch (coefficient_54_2)
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

  int threshold_92_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_92_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_92_1) & 63;
  aux_2 = (aux_2 + threshold_92_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(window_86_1 == window_86_2);
  assert(coefficient_54_1 == coefficient_54_2);
  assert(threshold_92_1 == threshold_92_2);
}

int fn_R001492_9213_8(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 36) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 29;
  int window_86 = ((st.buffer[0] * 3) + aux) & 63;
  if (window_86 > 32)
  {
    acc = ((acc + (window_86 * 2)) + 5) & 127;
    aux ^= window_86 & 15;
  }
  else
  {
    acc = ((acc - window_86) + 11) & 127;
    aux += 3;
  }
  int coefficient_54 = (aux + st.buffer[1]) & 3;
  switch (coefficient_54)
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

  int threshold_92 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_92) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001492_9213_9_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int threshold_37_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int threshold_37_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + threshold_37_1) & 63;
  aux_2 = (aux_2 + threshold_37_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int threshold_51_1 = (aux_1 + st_1.buffer[1]) & 3;
  int threshold_51_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (threshold_51_1)
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

  switch (threshold_51_2)
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

  st_1.buffer[1] = (st_1.buffer[1] + 3) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 3) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int scale_13_1 = 0;
  int scale_13_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    scale_13_1 = ((scale_13_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_13_2 = ((scale_13_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_13_1) & 127;
    acc_2 = (acc_2 + scale_13_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_37_1 == threshold_37_2);
  assert(threshold_51_1 == threshold_51_2);
  assert(scale_13_1 == scale_13_2);
}

int fn_R001492_9213_9(int p0, int p1, int p2)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int threshold_37 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + threshold_37) & 63;
  acc ^= aux;
  int threshold_51 = (aux + st.buffer[1]) & 3;
  switch (threshold_51)
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

  st.buffer[1] = (st.buffer[1] + 3) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int scale_13 = 0;
  for (int k = 0; k < 3; k++)
  {
    scale_13 = ((scale_13 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_13) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_10_2(int p0_1, int p1_1, int p2_1, int p0_2, int p1_2, int p2_2)
{
  int acc_1 = (p0_1 + 35) & 127;
  int acc_2 = (p0_2 + 35) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int threshold_97_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int threshold_97_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (threshold_97_1 > 10)
  {
    acc_1 = ((acc_1 + (threshold_97_1 * 2)) + 5) & 127;
    aux_1 ^= threshold_97_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - threshold_97_1) + 11) & 127;
    aux_1 += 3;
  }
  if (threshold_97_2 > 10)
  {
    acc_2 = ((acc_2 + (threshold_97_2 * 2)) + 5) & 127;
    aux_2 ^= threshold_97_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - threshold_97_2) + 11) & 127;
    aux_2 += 3;
  }
  int stride_44_1 = (aux_1 + st_1.buffer[1]) & 3;
  int stride_44_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (stride_44_1)
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

  switch (stride_44_2)
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

  int cursor_91_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int cursor_91_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + cursor_91_1) & 63;
  aux_2 = (aux_2 + cursor_91_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  st_1.buffer[1] = (st_1.buffer[1] + 6) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 6) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(threshold_97_1 == threshold_97_2);
  assert(stride_44_1 == stride_44_2);
  assert(cursor_91_1 == cursor_91_2);
}

int fn_R001492_9213_10(int p0, int p1, int p2)
{
  int acc = (p0 + 35) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int threshold_97 = ((st.buffer[0] * 3) + aux) & 63;
  if (threshold_97 > 10)
  {
    acc = ((acc + (threshold_97 * 2)) + 5) & 127;
    aux ^= threshold_97 & 15;
  }
  else
  {
    acc = ((acc - threshold_97) + 11) & 127;
    aux += 3;
  }
  int stride_44 = (aux + st.buffer[1]) & 3;
  switch (stride_44)
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

  int cursor_91 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + cursor_91) & 63;
  acc ^= aux;
  st.buffer[1] = (st.buffer[1] + 6) & 15;
  acc = (acc + st.buffer[1]) & 127;
  return (acc + aux) & 255;
}

void fn_R001492_9213_11_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 50) & 127;
  int acc_2 = (p0_2 + 50) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 6;
  st_2.buffer[2] = 6;
  st_1.buffer[1] = (st_1.buffer[1] + 4) & 15;
  st_2.buffer[1] = (st_2.buffer[1] + 4) & 15;
  acc_1 = (acc_1 + st_1.buffer[1]) & 127;
  acc_2 = (acc_2 + st_2.buffer[1]) & 127;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int parity_21_1 = local_arr_1[aux_1 % 3];
  int parity_21_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (parity_21_1 * 2)) & 127;
  acc_2 = (acc_2 + (parity_21_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(parity_21_1 == parity_21_2);
}

int fn_R001492_9213_11(int p0, int p1)
{
  int acc = (p0 + 50) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 6;
  st.buffer[1] = (st.buffer[1] + 4) & 15;
  acc = (acc + st.buffer[1]) & 127;
  int local_arr[3] = {4, 9, 15};
  int parity_21 = local_arr[aux % 3];
  acc = (acc + (parity_21 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001492_9213_12_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 38) & 127;
  int acc_2 = (p0_2 + 38) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 19;
  st_2.buffer[2] = 19;
  int anchor_61_1 = (aux_1 + st_1.buffer[1]) & 3;
  int anchor_61_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (anchor_61_1)
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

  switch (anchor_61_2)
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

  int parity_85_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int parity_85_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (parity_85_1 > 11)
  {
    acc_1 = ((acc_1 + (parity_85_1 * 2)) + 5) & 127;
    aux_1 ^= parity_85_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - parity_85_1) + 11) & 127;
    aux_1 += 3;
  }
  if (parity_85_2 > 11)
  {
    acc_2 = ((acc_2 + (parity_85_2 * 2)) + 5) & 127;
    aux_2 ^= parity_85_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - parity_85_2) + 11) & 127;
    aux_2 += 3;
  }
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(anchor_61_1 == anchor_61_2);
  assert(parity_85_1 == parity_85_2);
}

int fn_R001492_9213_12(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 38) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 19;
  int anchor_61 = (aux + st.buffer[1]) & 3;
  switch (anchor_61)
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

  int parity_85 = ((st.buffer[0] * 3) + aux) & 63;
  if (parity_85 > 11)
  {
    acc = ((acc + (parity_85 * 2)) + 5) & 127;
    aux ^= parity_85 & 15;
  }
  else
  {
    acc = ((acc - parity_85) + 11) & 127;
    aux += 3;
  }
  return (acc + aux) & 255;
}

void fn_R001492_9213_13_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 16) & 127;
  int acc_2 = (p0_2 + 16) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 26;
  st_2.buffer[2] = 26;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int weight_90_1 = local_arr_1[aux_1 % 3];
  int weight_90_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (weight_90_1 * 2)) & 127;
  acc_2 = (acc_2 + (weight_90_2 * 2)) & 127;
  int phase_49_1 = (aux_1 + st_1.buffer[1]) & 3;
  int phase_49_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (phase_49_1)
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

  switch (phase_49_2)
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

  int checksum_48_1 = 0;
  int checksum_48_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    checksum_48_1 = ((checksum_48_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    checksum_48_2 = ((checksum_48_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + checksum_48_1) & 127;
    acc_2 = (acc_2 + checksum_48_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(weight_90_1 == weight_90_2);
  assert(phase_49_1 == phase_49_2);
  assert(checksum_48_1 == checksum_48_2);
}

int fn_R001492_9213_13(int p0, int p1)
{
  int acc = (p0 + 16) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 26;
  int local_arr[3] = {4, 9, 15};
  int weight_90 = local_arr[aux % 3];
  acc = (acc + (weight_90 * 2)) & 127;
  int phase_49 = (aux + st.buffer[1]) & 3;
  switch (phase_49)
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

  int checksum_48 = 0;
  for (int k = 0; k < 2; k++)
  {
    checksum_48 = ((checksum_48 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + checksum_48) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_14_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 14) & 127;
  int acc_2 = (p0_2 + 14) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 21;
  st_2.buffer[2] = 21;
  int offset_73_1 = ((st_1.buffer[0] * 3) + aux_1) & 63;
  int offset_73_2 = ((st_2.buffer[0] * 3) + aux_2) & 63;
  if (offset_73_1 > 14)
  {
    acc_1 = ((acc_1 + (offset_73_1 * 2)) + 5) & 127;
    aux_1 ^= offset_73_1 & 15;
  }
  else
  {
    acc_1 = ((acc_1 - offset_73_1) + 11) & 127;
    aux_1 += 3;
  }
  if (offset_73_2 > 14)
  {
    acc_2 = ((acc_2 + (offset_73_2 * 2)) + 5) & 127;
    aux_2 ^= offset_73_2 & 15;
  }
  else
  {
    acc_2 = ((acc_2 - offset_73_2) + 11) & 127;
    aux_2 += 3;
  }
  int vector_75_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int vector_75_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + vector_75_1) & 63;
  aux_2 = (aux_2 + vector_75_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(offset_73_1 == offset_73_2);
  assert(vector_75_1 == vector_75_2);
}

int fn_R001492_9213_14(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 14) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 21;
  int offset_73 = ((st.buffer[0] * 3) + aux) & 63;
  if (offset_73 > 14)
  {
    acc = ((acc + (offset_73 * 2)) + 5) & 127;
    aux ^= offset_73 & 15;
  }
  else
  {
    acc = ((acc - offset_73) + 11) & 127;
    aux += 3;
  }
  int vector_75 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + vector_75) & 63;
  acc ^= aux;
  return (acc + aux) & 255;
}

void fn_R001492_9213_15_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int bound_10_1 = 0;
  int bound_10_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    bound_10_1 = ((bound_10_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    bound_10_2 = ((bound_10_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + bound_10_1) & 127;
    acc_2 = (acc_2 + bound_10_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_73_1 = local_arr_1[aux_1 % 3];
  int phase_73_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_73_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_73_2 * 2)) & 127;
  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(bound_10_1 == bound_10_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_73_1 == phase_73_2);
}

int fn_R001492_9213_15(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int bound_10 = 0;
  for (int k = 0; k < 2; k++)
  {
    bound_10 = ((bound_10 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + bound_10) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_73 = local_arr[aux % 3];
  acc = (acc + (phase_73 * 2)) & 127;
  return (acc + aux) & 255;
}

void fn_R001492_9213_16_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 7) & 127;
  int acc_2 = (p0_2 + 7) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 7;
  st_2.buffer[2] = 7;
  int coefficient_17_1 = 0;
  int coefficient_17_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    coefficient_17_1 = ((coefficient_17_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    coefficient_17_2 = ((coefficient_17_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + coefficient_17_1) & 127;
    acc_2 = (acc_2 + coefficient_17_2) & 127;
  }

  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int phase_13_1 = local_arr_1[aux_1 % 3];
  int phase_13_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (phase_13_1 * 2)) & 127;
  acc_2 = (acc_2 + (phase_13_2 * 2)) & 127;
  int checksum_34_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int checksum_34_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + checksum_34_1) & 63;
  aux_2 = (aux_2 + checksum_34_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int offset_68_1 = (aux_1 + st_1.buffer[1]) & 3;
  int offset_68_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (offset_68_1)
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

  switch (offset_68_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(coefficient_17_1 == coefficient_17_2);
  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(phase_13_1 == phase_13_2);
  assert(checksum_34_1 == checksum_34_2);
  assert(offset_68_1 == offset_68_2);
}

int fn_R001492_9213_16(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 7) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 7;
  int coefficient_17 = 0;
  for (int k = 0; k < 2; k++)
  {
    coefficient_17 = ((coefficient_17 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + coefficient_17) & 127;
  }

  int local_arr[3] = {4, 9, 15};
  int phase_13 = local_arr[aux % 3];
  acc = (acc + (phase_13 * 2)) & 127;
  int checksum_34 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + checksum_34) & 63;
  acc ^= aux;
  int offset_68 = (aux + st.buffer[1]) & 3;
  switch (offset_68)
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

void fn_R001492_9213_17_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 44) & 127;
  int acc_2 = (p0_2 + 44) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 27;
  st_2.buffer[2] = 27;
  int residue_85_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int residue_85_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + residue_85_1) & 63;
  aux_2 = (aux_2 + residue_85_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int window_89_1 = (aux_1 + st_1.buffer[1]) & 3;
  int window_89_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (window_89_1)
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

  switch (window_89_2)
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

  int segment_72_1 = 0;
  int segment_72_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    segment_72_1 = ((segment_72_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    segment_72_2 = ((segment_72_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + segment_72_1) & 127;
    acc_2 = (acc_2 + segment_72_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(residue_85_1 == residue_85_2);
  assert(window_89_1 == window_89_2);
  assert(segment_72_1 == segment_72_2);
}

int fn_R001492_9213_17(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 44) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 27;
  int residue_85 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + residue_85) & 63;
  acc ^= aux;
  int window_89 = (aux + st.buffer[1]) & 3;
  switch (window_89)
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

  int segment_72 = 0;
  for (int k = 0; k < 3; k++)
  {
    segment_72 = ((segment_72 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + segment_72) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_18_2(int p0_1, int p1_1, int p2_1, int p3_1, int p4_1, int p0_2, int p1_2, int p2_2, int p3_2, int p4_2)
{
  int acc_1 = (p0_1 + 18) & 127;
  int acc_2 = (p0_2 + 18) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st_1 = {0};
  struct FilterState_R001492_9213_1 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 11;
  st_2.buffer[2] = 11;
  int delta_38_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int delta_38_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + delta_38_1) & 63;
  aux_2 = (aux_2 + delta_38_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int factor_19_1 = 0;
  int factor_19_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 3) && (k_2 < 3); k_1++, k_2++)
  {
    factor_19_1 = ((factor_19_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    factor_19_2 = ((factor_19_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + factor_19_1) & 127;
    acc_2 = (acc_2 + factor_19_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.prev_out == st_2.prev_out);
  assert(st_1.cutoff == st_2.cutoff);
  assert(st_1.gain_db == st_2.gain_db);
  assert(st_1.damping == st_2.damping);
  assert(st_1.prev_in == st_2.prev_in);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  assert(delta_38_1 == delta_38_2);
  assert(factor_19_1 == factor_19_2);
}

int fn_R001492_9213_18(int p0, int p1, int p2, int p3, int p4)
{
  int acc = (p0 + 18) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct FilterState_R001492_9213_1 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 11;
  int delta_38 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + delta_38) & 63;
  acc ^= aux;
  int factor_19 = 0;
  for (int k = 0; k < 3; k++)
  {
    factor_19 = ((factor_19 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + factor_19) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_19_2(int p0_1, int p1_1, int p0_2, int p1_2)
{
  int acc_1 = (p0_1 + 32) & 127;
  int acc_2 = (p0_2 + 32) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 13;
  st_2.buffer[2] = 13;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int bound_55_1 = local_arr_1[aux_1 % 3];
  int bound_55_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (bound_55_1 * 2)) & 127;
  acc_2 = (acc_2 + (bound_55_2 * 2)) & 127;
  int stride_97_1 = ((acc_1 << 1) ^ (aux_1 >> 1)) & 63;
  int stride_97_2 = ((acc_2 << 1) ^ (aux_2 >> 1)) & 63;
  aux_1 = (aux_1 + stride_97_1) & 63;
  aux_2 = (aux_2 + stride_97_2) & 63;
  acc_1 ^= aux_1;
  acc_2 ^= aux_2;
  int scale_67_1 = 0;
  int scale_67_2 = 0;
  for (int k_1 = 0, k_2 = 0; (k_1 < 2) && (k_2 < 2); k_1++, k_2++)
  {
    scale_67_1 = ((scale_67_1 + (k_1 * 4)) + st_1.buffer[k_1 % 3]) & 31;
    scale_67_2 = ((scale_67_2 + (k_2 * 4)) + st_2.buffer[k_2 % 3]) & 31;
    acc_1 = (acc_1 + scale_67_1) & 127;
    acc_2 = (acc_2 + scale_67_2) & 127;
  }

  assert(acc_1 == acc_2);
  assert(aux_1 == aux_2);
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(bound_55_1 == bound_55_2);
  assert(stride_97_1 == stride_97_2);
  assert(scale_67_1 == scale_67_2);
}

int fn_R001492_9213_19(int p0, int p1)
{
  int acc = (p0 + 32) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 13;
  int local_arr[3] = {4, 9, 15};
  int bound_55 = local_arr[aux % 3];
  acc = (acc + (bound_55 * 2)) & 127;
  int stride_97 = ((acc << 1) ^ (aux >> 1)) & 63;
  aux = (aux + stride_97) & 63;
  acc ^= aux;
  int scale_67 = 0;
  for (int k = 0; k < 2; k++)
  {
    scale_67 = ((scale_67 + (k * 4)) + st.buffer[k % 3]) & 31;
    acc = (acc + scale_67) & 127;
  }

  return (acc + aux) & 255;
}

void fn_R001492_9213_20_2(int p0_1, int p1_1, int p2_1, int p3_1, int p0_2, int p1_2, int p2_2, int p3_2)
{
  int acc_1 = (p0_1 + 30) & 127;
  int acc_2 = (p0_2 + 30) & 127;
  int aux_1 = (p1_1 ^ 0x3C) & 63;
  int aux_2 = (p1_2 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st_1 = {0};
  struct Vector3D_R001492_9213_0 st_2 = {0};
  st_1.buffer[0] = (p0_1 + 3) & 15;
  st_2.buffer[0] = (p0_2 + 3) & 15;
  st_1.buffer[1] = (p1_1 + 7) & 15;
  st_2.buffer[1] = (p1_2 + 7) & 15;
  st_1.buffer[2] = 15;
  st_2.buffer[2] = 15;
  int local_arr_1[3] = {4, 9, 15};
  int local_arr_2[3] = {4, 9, 15};
  int offset_19_1 = local_arr_1[aux_1 % 3];
  int offset_19_2 = local_arr_2[aux_2 % 3];
  acc_1 = (acc_1 + (offset_19_1 * 2)) & 127;
  acc_2 = (acc_2 + (offset_19_2 * 2)) & 127;
  int segment_62_1 = (aux_1 + st_1.buffer[1]) & 3;
  int segment_62_2 = (aux_2 + st_2.buffer[1]) & 3;
  switch (segment_62_1)
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

  switch (segment_62_2)
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
  assert(st_1.norm_sq == st_2.norm_sq);
  assert(st_1.coord_z == st_2.coord_z);
  assert(st_1.coord_x == st_2.coord_x);
  assert(st_1.heading == st_2.heading);
  assert(st_1.pitch == st_2.pitch);
  assert(st_1.coord_y == st_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_1.buffer[i_buffer] == st_2.buffer[i_buffer]);
  }

  for (int i_0 = 0; i_0 < 3; i_0++)
  {
    assert(local_arr_1[i_0] == local_arr_2[i_0]);
  }

  assert(offset_19_1 == offset_19_2);
  assert(segment_62_1 == segment_62_2);
}

int fn_R001492_9213_20(int p0, int p1, int p2, int p3)
{
  int acc = (p0 + 30) & 127;
  int aux = (p1 ^ 0x3C) & 63;
  struct Vector3D_R001492_9213_0 st = {0};
  st.buffer[0] = (p0 + 3) & 15;
  st.buffer[1] = (p1 + 7) & 15;
  st.buffer[2] = 15;
  int local_arr[3] = {4, 9, 15};
  int offset_19 = local_arr[aux % 3];
  acc = (acc + (offset_19 * 2)) & 127;
  int segment_62 = (aux + st.buffer[1]) & 3;
  switch (segment_62)
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

void main()
{
  int sec_r001492_0_1;
  int sec_r001492_0_2;
  int sec_r001492_1_1;
  int sec_r001492_1_2;
  int sec_r001492_2_1;
  int sec_r001492_2_2;
  int sec_r001492_3_1;
  int sec_r001492_3_2;
  int sec_r001492_4_1;
  int sec_r001492_4_2;
  int sec_r001492_5_1;
  int sec_r001492_5_2;
  int sec_r001492_6_1;
  int sec_r001492_6_2;
  int sec_r001492_7_1;
  int sec_r001492_7_2;
  int sec_r001492_8_1;
  int sec_r001492_8_2;
  int sec_r001492_9_1;
  int sec_r001492_9_2;
  int sec_r001492_10_1;
  int sec_r001492_10_2;
  int sec_r001492_11_1;
  int sec_r001492_11_2;
  int sec_r001492_12_1;
  int sec_r001492_12_2;
  int sec_r001492_13_1;
  int sec_r001492_13_2;
  int sec_r001492_14_1;
  int sec_r001492_14_2;
  int sec_r001492_15_1;
  int sec_r001492_15_2;
  int sec_r001492_16_1;
  int sec_r001492_16_2;
  int sec_r001492_17_1;
  int sec_r001492_17_2;
  int sec_r001492_18_1;
  int sec_r001492_18_2;
  int pub_r001492_0_1;
  int pub_r001492_0_2;
  int pub_r001492_1_1;
  int pub_r001492_1_2;
  int pub_r001492_2_1;
  int pub_r001492_2_2;
  int pub_r001492_3_1;
  int pub_r001492_3_2;
  int pub_r001492_4_1;
  int pub_r001492_4_2;
  int pub_r001492_5_1;
  int pub_r001492_5_2;
  int pub_r001492_6_1;
  int pub_r001492_6_2;
  int pub_r001492_7_1;
  int pub_r001492_7_2;
  int pub_r001492_8_1;
  int pub_r001492_8_2;
  int pub_r001492_9_1;
  int pub_r001492_9_2;
  int pub_r001492_10_1;
  int pub_r001492_10_2;
  int pub_r001492_11_1;
  int pub_r001492_11_2;
  int pub_r001492_12_1;
  int pub_r001492_12_2;
  int pub_r001492_13_1;
  int pub_r001492_13_2;
  int pub_r001492_14_1;
  int pub_r001492_14_2;
  int pub_r001492_15_1;
  int pub_r001492_15_2;
  int pub_r001492_16_1;
  int pub_r001492_16_2;
  int out_sink_1 = 0;
  int out_sink_2 = 0;
  int chk_sum_1 = 0;
  int chk_sum_2 = 0;
  int sec_accum_1 = 0;
  int sec_accum_2 = 0;
  __CPROVER_assume((pub_r001492_0_1 >= (-100)) && (pub_r001492_0_1 <= 100));
  __CPROVER_assume((pub_r001492_0_2 >= (-100)) && (pub_r001492_0_2 <= 100));
  __CPROVER_assume((pub_r001492_1_1 >= (-100)) && (pub_r001492_1_1 <= 100));
  __CPROVER_assume((pub_r001492_1_2 >= (-100)) && (pub_r001492_1_2 <= 100));
  __CPROVER_assume((pub_r001492_2_1 >= (-100)) && (pub_r001492_2_1 <= 100));
  __CPROVER_assume((pub_r001492_2_2 >= (-100)) && (pub_r001492_2_2 <= 100));
  __CPROVER_assume((pub_r001492_3_1 >= (-100)) && (pub_r001492_3_1 <= 100));
  __CPROVER_assume((pub_r001492_3_2 >= (-100)) && (pub_r001492_3_2 <= 100));
  __CPROVER_assume((pub_r001492_4_1 >= (-100)) && (pub_r001492_4_1 <= 100));
  __CPROVER_assume((pub_r001492_4_2 >= (-100)) && (pub_r001492_4_2 <= 100));
  __CPROVER_assume((pub_r001492_5_1 >= (-100)) && (pub_r001492_5_1 <= 100));
  __CPROVER_assume((pub_r001492_5_2 >= (-100)) && (pub_r001492_5_2 <= 100));
  __CPROVER_assume((pub_r001492_6_1 >= (-100)) && (pub_r001492_6_1 <= 100));
  __CPROVER_assume((pub_r001492_6_2 >= (-100)) && (pub_r001492_6_2 <= 100));
  __CPROVER_assume((pub_r001492_7_1 >= (-100)) && (pub_r001492_7_1 <= 100));
  __CPROVER_assume((pub_r001492_7_2 >= (-100)) && (pub_r001492_7_2 <= 100));
  __CPROVER_assume((pub_r001492_8_1 >= (-100)) && (pub_r001492_8_1 <= 100));
  __CPROVER_assume((pub_r001492_8_2 >= (-100)) && (pub_r001492_8_2 <= 100));
  __CPROVER_assume((pub_r001492_9_1 >= (-100)) && (pub_r001492_9_1 <= 100));
  __CPROVER_assume((pub_r001492_9_2 >= (-100)) && (pub_r001492_9_2 <= 100));
  __CPROVER_assume((pub_r001492_10_1 >= (-100)) && (pub_r001492_10_1 <= 100));
  __CPROVER_assume((pub_r001492_10_2 >= (-100)) && (pub_r001492_10_2 <= 100));
  __CPROVER_assume((pub_r001492_11_1 >= (-100)) && (pub_r001492_11_1 <= 100));
  __CPROVER_assume((pub_r001492_11_2 >= (-100)) && (pub_r001492_11_2 <= 100));
  __CPROVER_assume((pub_r001492_12_1 >= (-100)) && (pub_r001492_12_1 <= 100));
  __CPROVER_assume((pub_r001492_12_2 >= (-100)) && (pub_r001492_12_2 <= 100));
  __CPROVER_assume((pub_r001492_13_1 >= (-100)) && (pub_r001492_13_1 <= 100));
  __CPROVER_assume((pub_r001492_13_2 >= (-100)) && (pub_r001492_13_2 <= 100));
  __CPROVER_assume((pub_r001492_14_1 >= (-100)) && (pub_r001492_14_1 <= 100));
  __CPROVER_assume((pub_r001492_14_2 >= (-100)) && (pub_r001492_14_2 <= 100));
  __CPROVER_assume((pub_r001492_15_1 >= (-100)) && (pub_r001492_15_1 <= 100));
  __CPROVER_assume((pub_r001492_15_2 >= (-100)) && (pub_r001492_15_2 <= 100));
  __CPROVER_assume((pub_r001492_16_1 >= (-100)) && (pub_r001492_16_1 <= 100));
  __CPROVER_assume((pub_r001492_16_2 >= (-100)) && (pub_r001492_16_2 <= 100));
  __CPROVER_assume((sec_r001492_0_1 >= 0) && (sec_r001492_0_1 <= 255));
  __CPROVER_assume((sec_r001492_0_2 >= 0) && (sec_r001492_0_2 <= 255));
  __CPROVER_assume((sec_r001492_1_1 >= 0) && (sec_r001492_1_1 <= 255));
  __CPROVER_assume((sec_r001492_1_2 >= 0) && (sec_r001492_1_2 <= 255));
  __CPROVER_assume((sec_r001492_2_1 >= 0) && (sec_r001492_2_1 <= 255));
  __CPROVER_assume((sec_r001492_2_2 >= 0) && (sec_r001492_2_2 <= 255));
  __CPROVER_assume((sec_r001492_3_1 >= 0) && (sec_r001492_3_1 <= 255));
  __CPROVER_assume((sec_r001492_3_2 >= 0) && (sec_r001492_3_2 <= 255));
  __CPROVER_assume((sec_r001492_4_1 >= 0) && (sec_r001492_4_1 <= 255));
  __CPROVER_assume((sec_r001492_4_2 >= 0) && (sec_r001492_4_2 <= 255));
  __CPROVER_assume((sec_r001492_5_1 >= 0) && (sec_r001492_5_1 <= 255));
  __CPROVER_assume((sec_r001492_5_2 >= 0) && (sec_r001492_5_2 <= 255));
  __CPROVER_assume((sec_r001492_6_1 >= 0) && (sec_r001492_6_1 <= 255));
  __CPROVER_assume((sec_r001492_6_2 >= 0) && (sec_r001492_6_2 <= 255));
  __CPROVER_assume((sec_r001492_7_1 >= 0) && (sec_r001492_7_1 <= 255));
  __CPROVER_assume((sec_r001492_7_2 >= 0) && (sec_r001492_7_2 <= 255));
  __CPROVER_assume((sec_r001492_8_1 >= 0) && (sec_r001492_8_1 <= 255));
  __CPROVER_assume((sec_r001492_8_2 >= 0) && (sec_r001492_8_2 <= 255));
  __CPROVER_assume((sec_r001492_9_1 >= 0) && (sec_r001492_9_1 <= 255));
  __CPROVER_assume((sec_r001492_9_2 >= 0) && (sec_r001492_9_2 <= 255));
  __CPROVER_assume((sec_r001492_10_1 >= 0) && (sec_r001492_10_1 <= 255));
  __CPROVER_assume((sec_r001492_10_2 >= 0) && (sec_r001492_10_2 <= 255));
  __CPROVER_assume((sec_r001492_11_1 >= 0) && (sec_r001492_11_1 <= 255));
  __CPROVER_assume((sec_r001492_11_2 >= 0) && (sec_r001492_11_2 <= 255));
  __CPROVER_assume((sec_r001492_12_1 >= 0) && (sec_r001492_12_1 <= 255));
  __CPROVER_assume((sec_r001492_12_2 >= 0) && (sec_r001492_12_2 <= 255));
  __CPROVER_assume((sec_r001492_13_1 >= 0) && (sec_r001492_13_1 <= 255));
  __CPROVER_assume((sec_r001492_13_2 >= 0) && (sec_r001492_13_2 <= 255));
  __CPROVER_assume((sec_r001492_14_1 >= 0) && (sec_r001492_14_1 <= 255));
  __CPROVER_assume((sec_r001492_14_2 >= 0) && (sec_r001492_14_2 <= 255));
  __CPROVER_assume((sec_r001492_15_1 >= 0) && (sec_r001492_15_1 <= 255));
  __CPROVER_assume((sec_r001492_15_2 >= 0) && (sec_r001492_15_2 <= 255));
  __CPROVER_assume((sec_r001492_16_1 >= 0) && (sec_r001492_16_1 <= 255));
  __CPROVER_assume((sec_r001492_16_2 >= 0) && (sec_r001492_16_2 <= 255));
  __CPROVER_assume((sec_r001492_17_1 >= 0) && (sec_r001492_17_1 <= 255));
  __CPROVER_assume((sec_r001492_17_2 >= 0) && (sec_r001492_17_2 <= 255));
  __CPROVER_assume((sec_r001492_18_1 >= 0) && (sec_r001492_18_1 <= 255));
  __CPROVER_assume((sec_r001492_18_2 >= 0) && (sec_r001492_18_2 <= 255));
  struct Vector3D_R001492_9213_0 st_var_0_1 = {0};
  struct Vector3D_R001492_9213_0 st_var_0_2 = {0};
  st_var_0_1.buffer[0] = (pub_r001492_0_1 + 1) & 15;
  st_var_0_2.buffer[0] = (pub_r001492_0_2 + 1) & 15;
  st_var_0_1.buffer[1] = (pub_r001492_0_1 + 4) & 15;
  st_var_0_2.buffer[1] = (pub_r001492_0_2 + 4) & 15;
  st_var_0_1.buffer[2] = (pub_r001492_0_1 + 7) & 15;
  st_var_0_2.buffer[2] = (pub_r001492_0_2 + 7) & 15;
  struct FilterState_R001492_9213_1 st_var_1_1 = {0};
  struct FilterState_R001492_9213_1 st_var_1_2 = {0};
  st_var_1_1.buffer[0] = (pub_r001492_0_1 + 4) & 15;
  st_var_1_2.buffer[0] = (pub_r001492_0_2 + 4) & 15;
  st_var_1_1.buffer[1] = (pub_r001492_0_1 + 9) & 15;
  st_var_1_2.buffer[1] = (pub_r001492_0_2 + 9) & 15;
  st_var_1_1.buffer[2] = (pub_r001492_0_1 + 9) & 15;
  st_var_1_2.buffer[2] = (pub_r001492_0_2 + 9) & 15;
  union ColorPixel_R001492_9213_0 u_var_1;
  union ColorPixel_R001492_9213_0 u_var_2;
  u_var_1.word = 0;
  u_var_2.word = 0;
  int table_1[4] = {11, 23, 47, 89};
  int table_2[4] = {11, 23, 47, 89};
  int helper_flow_0_1 = fn_R001492_9213_0(sec_r001492_0_1, sec_r001492_1_1, pub_r001492_2_1);
  int helper_flow_0_2 = fn_R001492_9213_0(sec_r001492_0_2, sec_r001492_1_2, pub_r001492_2_2);
  fn_R001492_9213_0_2(sec_r001492_0_1, sec_r001492_1_1, pub_r001492_2_1, sec_r001492_0_2, sec_r001492_1_2, pub_r001492_2_2);
  int helper_flow_1_1 = fn_R001492_9213_1(sec_r001492_1_1, pub_r001492_2_1, pub_r001492_3_1);
  int helper_flow_1_2 = fn_R001492_9213_1(sec_r001492_1_2, pub_r001492_2_2, pub_r001492_3_2);
  fn_R001492_9213_1_2(sec_r001492_1_1, pub_r001492_2_1, pub_r001492_3_1, sec_r001492_1_2, pub_r001492_2_2, pub_r001492_3_2);
  int helper_flow_2_1 = fn_R001492_9213_2(sec_r001492_2_1, pub_r001492_3_1, pub_r001492_4_1, pub_r001492_5_1);
  int helper_flow_2_2 = fn_R001492_9213_2(sec_r001492_2_2, pub_r001492_3_2, pub_r001492_4_2, pub_r001492_5_2);
  fn_R001492_9213_2_2(sec_r001492_2_1, pub_r001492_3_1, pub_r001492_4_1, pub_r001492_5_1, sec_r001492_2_2, pub_r001492_3_2, pub_r001492_4_2, pub_r001492_5_2);
  int helper_flow_3_1 = fn_R001492_9213_3(sec_r001492_3_1, pub_r001492_4_1, pub_r001492_5_1, pub_r001492_6_1);
  int helper_flow_3_2 = fn_R001492_9213_3(sec_r001492_3_2, pub_r001492_4_2, pub_r001492_5_2, pub_r001492_6_2);
  fn_R001492_9213_3_2(sec_r001492_3_1, pub_r001492_4_1, pub_r001492_5_1, pub_r001492_6_1, sec_r001492_3_2, pub_r001492_4_2, pub_r001492_5_2, pub_r001492_6_2);
  int stage_v_0_1 = (((sec_r001492_15_1 * 3) + pub_r001492_8_1) + 18) & 127;
  int stage_v_0_2 = (((sec_r001492_15_2 * 3) + pub_r001492_8_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_0_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_0_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_0_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_0_2 * 2)) & 255;
  int stage_v_1_1 = (((sec_r001492_2_1 * 3) + pub_r001492_13_1) + 16) & 127;
  int stage_v_1_2 = (((sec_r001492_2_2 * 3) + pub_r001492_13_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_1_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_1_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_1_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_1_2 * 2)) & 255;
  int stage_v_2_1 = ((pub_r001492_11_1 * 2) + 21) & 63;
  int stage_v_2_2 = ((pub_r001492_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_2_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_2_2) & 127;
  int stage_v_3_1 = (((sec_r001492_17_1 * 3) + pub_r001492_14_1) + 13) & 127;
  int stage_v_3_2 = (((sec_r001492_17_2 * 3) + pub_r001492_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_3_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_3_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_3_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_3_2 * 2)) & 255;
  int stage_v_4_1 = ((pub_r001492_8_1 * 2) + 40) & 63;
  int stage_v_4_2 = ((pub_r001492_8_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_4_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_4_2) & 127;
  int stage_v_5_1 = (((sec_r001492_8_1 * 3) + pub_r001492_14_1) + 3) & 127;
  int stage_v_5_2 = (((sec_r001492_8_2 * 3) + pub_r001492_14_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_5_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_5_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_5_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_5_2 * 2)) & 255;
  int stage_v_6_1 = ((pub_r001492_6_1 * 2) + 36) & 63;
  int stage_v_6_2 = ((pub_r001492_6_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_6_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_6_2) & 127;
  int stage_v_7_1 = (((sec_r001492_12_1 * 3) + pub_r001492_5_1) + 20) & 127;
  int stage_v_7_2 = (((sec_r001492_12_2 * 3) + pub_r001492_5_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_7_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_7_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_7_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_7_2 * 2)) & 255;
  int stage_v_8_1 = ((pub_r001492_14_1 * 2) + 38) & 63;
  int stage_v_8_2 = ((pub_r001492_14_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_8_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_8_2) & 127;
  int stage_v_9_1 = ((pub_r001492_14_1 * 2) + 40) & 63;
  int stage_v_9_2 = ((pub_r001492_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_9_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_9_2) & 127;
  int stage_v_10_1 = (((sec_r001492_4_1 * 3) + pub_r001492_7_1) + 3) & 127;
  int stage_v_10_2 = (((sec_r001492_4_2 * 3) + pub_r001492_7_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_10_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_10_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_10_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_10_2 * 2)) & 255;
  int stage_v_11_1 = (((sec_r001492_1_1 * 3) + pub_r001492_4_1) + 9) & 127;
  int stage_v_11_2 = (((sec_r001492_1_2 * 3) + pub_r001492_4_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_11_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_11_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_11_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_11_2 * 2)) & 255;
  int stage_v_12_1 = (((sec_r001492_0_1 * 3) + pub_r001492_3_1) + 35) & 127;
  int stage_v_12_2 = (((sec_r001492_0_2 * 3) + pub_r001492_3_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_12_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_12_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_12_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_12_2 * 2)) & 255;
  int stage_v_13_1 = ((pub_r001492_0_1 * 2) + 34) & 63;
  int stage_v_13_2 = ((pub_r001492_0_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_13_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_13_2) & 127;
  int stage_v_14_1 = ((pub_r001492_12_1 * 2) + 33) & 63;
  int stage_v_14_2 = ((pub_r001492_12_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_14_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_14_2) & 127;
  int stage_v_15_1 = ((pub_r001492_2_1 * 2) + 32) & 63;
  int stage_v_15_2 = ((pub_r001492_2_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_15_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_15_2) & 127;
  int stage_v_16_1 = (((stage_v_0_1 * 3) + pub_r001492_12_1) + 15) & 127;
  int stage_v_16_2 = (((stage_v_0_2 * 3) + pub_r001492_12_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_16_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_16_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_16_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_16_2 * 2)) & 255;
  int stage_v_17_1 = ((pub_r001492_12_1 * 2) + 7) & 63;
  int stage_v_17_2 = ((pub_r001492_12_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_17_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_17_2) & 127;
  int stage_v_18_1 = (((sec_r001492_17_1 * 3) + pub_r001492_4_1) + 30) & 127;
  int stage_v_18_2 = (((sec_r001492_17_2 * 3) + pub_r001492_4_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_18_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_18_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_18_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_18_2 * 2)) & 255;
  int stage_v_19_1 = (((stage_v_12_1 * 3) + pub_r001492_2_1) + 44) & 127;
  int stage_v_19_2 = (((stage_v_12_2 * 3) + pub_r001492_2_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_19_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_19_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_19_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_19_2 * 2)) & 255;
  int stage_v_20_1 = ((pub_r001492_7_1 * 2) + 33) & 63;
  int stage_v_20_2 = ((pub_r001492_7_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_20_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_20_2) & 127;
  int stage_v_21_1 = ((pub_r001492_11_1 * 2) + 15) & 63;
  int stage_v_21_2 = ((pub_r001492_11_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_21_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_21_2) & 127;
  int stage_v_22_1 = ((pub_r001492_6_1 * 2) + 46) & 63;
  int stage_v_22_2 = ((pub_r001492_6_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_22_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_22_2) & 127;
  int stage_v_23_1 = ((pub_r001492_13_1 * 2) + 15) & 63;
  int stage_v_23_2 = ((pub_r001492_13_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_23_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_23_2) & 127;
  int stage_v_24_1 = ((pub_r001492_12_1 * 2) + 36) & 63;
  int stage_v_24_2 = ((pub_r001492_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_24_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_24_2) & 127;
  int stage_v_25_1 = ((pub_r001492_0_1 * 2) + 32) & 63;
  int stage_v_25_2 = ((pub_r001492_0_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_25_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_25_2) & 127;
  int stage_v_26_1 = ((pub_r001492_8_1 * 2) + 14) & 63;
  int stage_v_26_2 = ((pub_r001492_8_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_26_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_26_2) & 127;
  int stage_v_27_1 = (((stage_v_12_1 * 3) + pub_r001492_11_1) + 11) & 127;
  int stage_v_27_2 = (((stage_v_12_2 * 3) + pub_r001492_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_27_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_27_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_27_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_27_2 * 2)) & 255;
  int stage_v_28_1 = ((pub_r001492_16_1 * 2) + 27) & 63;
  int stage_v_28_2 = ((pub_r001492_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_28_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_28_2) & 127;
  int stage_v_29_1 = (((sec_r001492_17_1 * 3) + pub_r001492_6_1) + 26) & 127;
  int stage_v_29_2 = (((sec_r001492_17_2 * 3) + pub_r001492_6_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_29_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_29_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_29_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_29_2 * 2)) & 255;
  int stage_v_30_1 = (((stage_v_5_1 * 3) + pub_r001492_8_1) + 23) & 127;
  int stage_v_30_2 = (((stage_v_5_2 * 3) + pub_r001492_8_2) + 23) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_30_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_30_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_30_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_30_2 * 2)) & 255;
  int stage_v_31_1 = ((pub_r001492_16_1 * 2) + 26) & 63;
  int stage_v_31_2 = ((pub_r001492_16_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_31_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_31_2) & 127;
  int stage_v_32_1 = (((sec_r001492_10_1 * 3) + pub_r001492_2_1) + 11) & 127;
  int stage_v_32_2 = (((sec_r001492_10_2 * 3) + pub_r001492_2_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_32_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_32_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_32_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_32_2 * 2)) & 255;
  int stage_v_33_1 = (((sec_r001492_3_1 * 3) + pub_r001492_14_1) + 15) & 127;
  int stage_v_33_2 = (((sec_r001492_3_2 * 3) + pub_r001492_14_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_33_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_33_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_33_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_33_2 * 2)) & 255;
  int stage_v_34_1 = (((stage_v_33_1 * 3) + pub_r001492_8_1) + 30) & 127;
  int stage_v_34_2 = (((stage_v_33_2 * 3) + pub_r001492_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_34_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_34_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_34_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_34_2 * 2)) & 255;
  int stage_v_35_1 = ((pub_r001492_16_1 * 2) + 43) & 63;
  int stage_v_35_2 = ((pub_r001492_16_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_35_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_35_2) & 127;
  int stage_v_36_1 = ((pub_r001492_14_1 * 2) + 33) & 63;
  int stage_v_36_2 = ((pub_r001492_14_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_36_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_36_2) & 127;
  int stage_v_37_1 = (((sec_r001492_9_1 * 3) + pub_r001492_6_1) + 3) & 127;
  int stage_v_37_2 = (((sec_r001492_9_2 * 3) + pub_r001492_6_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_37_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_37_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_37_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_37_2 * 2)) & 255;
  int stage_v_38_1 = ((pub_r001492_11_1 * 2) + 12) & 63;
  int stage_v_38_2 = ((pub_r001492_11_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_38_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_38_2) & 127;
  int stage_v_39_1 = (((sec_r001492_5_1 * 3) + pub_r001492_1_1) + 24) & 127;
  int stage_v_39_2 = (((sec_r001492_5_2 * 3) + pub_r001492_1_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_39_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_39_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_39_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_39_2 * 2)) & 255;
  int stage_v_40_1 = ((pub_r001492_4_1 * 2) + 29) & 63;
  int stage_v_40_2 = ((pub_r001492_4_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_40_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_40_2) & 127;
  int stage_v_41_1 = ((pub_r001492_6_1 * 2) + 37) & 63;
  int stage_v_41_2 = ((pub_r001492_6_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_41_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_41_2) & 127;
  int stage_v_42_1 = ((pub_r001492_6_1 * 2) + 12) & 63;
  int stage_v_42_2 = ((pub_r001492_6_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_42_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_42_2) & 127;
  int stage_v_43_1 = ((pub_r001492_10_1 * 2) + 14) & 63;
  int stage_v_43_2 = ((pub_r001492_10_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_43_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_43_2) & 127;
  int stage_v_44_1 = ((pub_r001492_11_1 * 2) + 30) & 63;
  int stage_v_44_2 = ((pub_r001492_11_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_44_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_44_2) & 127;
  int stage_v_45_1 = (((stage_v_0_1 * 3) + pub_r001492_8_1) + 9) & 127;
  int stage_v_45_2 = (((stage_v_0_2 * 3) + pub_r001492_8_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_45_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_45_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_45_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_45_2 * 2)) & 255;
  int stage_v_46_1 = ((pub_r001492_13_1 * 2) + 34) & 63;
  int stage_v_46_2 = ((pub_r001492_13_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_46_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_46_2) & 127;
  int stage_v_47_1 = (((stage_v_19_1 * 3) + pub_r001492_1_1) + 7) & 127;
  int stage_v_47_2 = (((stage_v_19_2 * 3) + pub_r001492_1_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_47_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_47_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_47_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_47_2 * 2)) & 255;
  int stage_v_48_1 = ((pub_r001492_11_1 * 2) + 49) & 63;
  int stage_v_48_2 = ((pub_r001492_11_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_48_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_48_2) & 127;
  int stage_v_49_1 = ((pub_r001492_12_1 * 2) + 16) & 63;
  int stage_v_49_2 = ((pub_r001492_12_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_49_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_49_2) & 127;
  int stage_v_50_1 = ((pub_r001492_1_1 * 2) + 29) & 63;
  int stage_v_50_2 = ((pub_r001492_1_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_50_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_50_2) & 127;
  int stage_v_51_1 = ((pub_r001492_3_1 * 2) + 37) & 63;
  int stage_v_51_2 = ((pub_r001492_3_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_51_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_51_2) & 127;
  int stage_v_52_1 = ((pub_r001492_0_1 * 2) + 38) & 63;
  int stage_v_52_2 = ((pub_r001492_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_52_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_52_2) & 127;
  int stage_v_53_1 = ((pub_r001492_13_1 * 2) + 13) & 63;
  int stage_v_53_2 = ((pub_r001492_13_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_53_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_53_2) & 127;
  int stage_v_54_1 = ((pub_r001492_5_1 * 2) + 35) & 63;
  int stage_v_54_2 = ((pub_r001492_5_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_54_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_54_2) & 127;
  int stage_v_55_1 = (((sec_r001492_3_1 * 3) + pub_r001492_11_1) + 20) & 127;
  int stage_v_55_2 = (((sec_r001492_3_2 * 3) + pub_r001492_11_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_55_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_55_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_55_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_55_2 * 2)) & 255;
  int stage_v_56_1 = ((pub_r001492_12_1 * 2) + 24) & 63;
  int stage_v_56_2 = ((pub_r001492_12_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_56_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_56_2) & 127;
  int stage_v_57_1 = ((pub_r001492_9_1 * 2) + 39) & 63;
  int stage_v_57_2 = ((pub_r001492_9_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_57_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_57_2) & 127;
  int stage_v_58_1 = ((pub_r001492_0_1 * 2) + 7) & 63;
  int stage_v_58_2 = ((pub_r001492_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_58_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_58_2) & 127;
  int stage_v_59_1 = ((pub_r001492_8_1 * 2) + 44) & 63;
  int stage_v_59_2 = ((pub_r001492_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_59_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_59_2) & 127;
  int stage_v_60_1 = ((pub_r001492_15_1 * 2) + 36) & 63;
  int stage_v_60_2 = ((pub_r001492_15_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_60_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_60_2) & 127;
  int stage_v_61_1 = ((pub_r001492_5_1 * 2) + 24) & 63;
  int stage_v_61_2 = ((pub_r001492_5_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_61_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_61_2) & 127;
  int stage_v_62_1 = ((pub_r001492_16_1 * 2) + 22) & 63;
  int stage_v_62_2 = ((pub_r001492_16_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_62_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_62_2) & 127;
  int stage_v_63_1 = (((sec_r001492_9_1 * 3) + pub_r001492_8_1) + 31) & 127;
  int stage_v_63_2 = (((sec_r001492_9_2 * 3) + pub_r001492_8_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_63_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_63_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_63_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_63_2 * 2)) & 255;
  int stage_v_64_1 = (((stage_v_33_1 * 3) + pub_r001492_16_1) + 10) & 127;
  int stage_v_64_2 = (((stage_v_33_2 * 3) + pub_r001492_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_64_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_64_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_64_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_64_2 * 2)) & 255;
  int stage_v_65_1 = ((pub_r001492_6_1 * 2) + 29) & 63;
  int stage_v_65_2 = ((pub_r001492_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_65_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_65_2) & 127;
  int stage_v_66_1 = ((pub_r001492_0_1 * 2) + 25) & 63;
  int stage_v_66_2 = ((pub_r001492_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_66_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_66_2) & 127;
  int stage_v_67_1 = (((stage_v_34_1 * 3) + pub_r001492_1_1) + 5) & 127;
  int stage_v_67_2 = (((stage_v_34_2 * 3) + pub_r001492_1_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_67_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_67_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_67_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_67_2 * 2)) & 255;
  int stage_v_68_1 = (((stage_v_5_1 * 3) + pub_r001492_2_1) + 27) & 127;
  int stage_v_68_2 = (((stage_v_5_2 * 3) + pub_r001492_2_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_68_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_68_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_68_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_68_2 * 2)) & 255;
  int stage_v_69_1 = (((helper_flow_0_1 * 3) + pub_r001492_11_1) + 9) & 127;
  int stage_v_69_2 = (((helper_flow_0_2 * 3) + pub_r001492_11_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_69_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_69_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_69_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_69_2 * 2)) & 255;
  int stage_v_70_1 = (((sec_r001492_6_1 * 3) + pub_r001492_13_1) + 11) & 127;
  int stage_v_70_2 = (((sec_r001492_6_2 * 3) + pub_r001492_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_70_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_70_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_70_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_70_2 * 2)) & 255;
  int stage_v_71_1 = (((stage_v_27_1 * 3) + pub_r001492_1_1) + 33) & 127;
  int stage_v_71_2 = (((stage_v_27_2 * 3) + pub_r001492_1_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_71_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_71_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_71_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_71_2 * 2)) & 255;
  int stage_v_72_1 = (((sec_r001492_8_1 * 3) + pub_r001492_10_1) + 14) & 127;
  int stage_v_72_2 = (((sec_r001492_8_2 * 3) + pub_r001492_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_72_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_72_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_72_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_72_2 * 2)) & 255;
  int stage_v_73_1 = ((pub_r001492_15_1 * 2) + 27) & 63;
  int stage_v_73_2 = ((pub_r001492_15_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_73_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_73_2) & 127;
  int stage_v_74_1 = ((pub_r001492_11_1 * 2) + 14) & 63;
  int stage_v_74_2 = ((pub_r001492_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_74_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_74_2) & 127;
  int stage_v_75_1 = ((pub_r001492_9_1 * 2) + 28) & 63;
  int stage_v_75_2 = ((pub_r001492_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_75_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_75_2) & 127;
  int stage_v_76_1 = ((pub_r001492_1_1 * 2) + 49) & 63;
  int stage_v_76_2 = ((pub_r001492_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_76_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_76_2) & 127;
  int stage_v_77_1 = ((pub_r001492_4_1 * 2) + 16) & 63;
  int stage_v_77_2 = ((pub_r001492_4_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_77_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_77_2) & 127;
  int stage_v_78_1 = (((stage_v_1_1 * 3) + pub_r001492_11_1) + 16) & 127;
  int stage_v_78_2 = (((stage_v_1_2 * 3) + pub_r001492_11_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_78_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_78_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_78_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_78_2 * 2)) & 255;
  int stage_v_79_1 = ((pub_r001492_13_1 * 2) + 48) & 63;
  int stage_v_79_2 = ((pub_r001492_13_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_79_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_79_2) & 127;
  int stage_v_80_1 = ((pub_r001492_12_1 * 2) + 37) & 63;
  int stage_v_80_2 = ((pub_r001492_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_80_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_80_2) & 127;
  int stage_v_81_1 = ((pub_r001492_10_1 * 2) + 40) & 63;
  int stage_v_81_2 = ((pub_r001492_10_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_81_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_81_2) & 127;
  int stage_v_82_1 = (((sec_r001492_12_1 * 3) + pub_r001492_6_1) + 33) & 127;
  int stage_v_82_2 = (((sec_r001492_12_2 * 3) + pub_r001492_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_82_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_82_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_82_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_82_2 * 2)) & 255;
  int stage_v_83_1 = (((stage_v_67_1 * 3) + pub_r001492_6_1) + 14) & 127;
  int stage_v_83_2 = (((stage_v_67_2 * 3) + pub_r001492_6_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_83_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_83_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_83_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_83_2 * 2)) & 255;
  int stage_v_84_1 = ((pub_r001492_9_1 * 2) + 14) & 63;
  int stage_v_84_2 = ((pub_r001492_9_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_84_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_84_2) & 127;
  int stage_v_85_1 = ((pub_r001492_11_1 * 2) + 44) & 63;
  int stage_v_85_2 = ((pub_r001492_11_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_85_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_85_2) & 127;
  int stage_v_86_1 = (((stage_v_7_1 * 3) + pub_r001492_8_1) + 4) & 127;
  int stage_v_86_2 = (((stage_v_7_2 * 3) + pub_r001492_8_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_86_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_86_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_86_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_86_2 * 2)) & 255;
  int stage_v_87_1 = ((pub_r001492_3_1 * 2) + 5) & 63;
  int stage_v_87_2 = ((pub_r001492_3_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_87_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_87_2) & 127;
  int stage_v_88_1 = (((stage_v_7_1 * 3) + pub_r001492_9_1) + 8) & 127;
  int stage_v_88_2 = (((stage_v_7_2 * 3) + pub_r001492_9_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_88_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_88_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_88_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_88_2 * 2)) & 255;
  int stage_v_89_1 = ((pub_r001492_6_1 * 2) + 24) & 63;
  int stage_v_89_2 = ((pub_r001492_6_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_89_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_89_2) & 127;
  int stage_v_90_1 = ((pub_r001492_2_1 * 2) + 23) & 63;
  int stage_v_90_2 = ((pub_r001492_2_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_90_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_90_2) & 127;
  int stage_v_91_1 = (((stage_v_37_1 * 3) + pub_r001492_2_1) + 30) & 127;
  int stage_v_91_2 = (((stage_v_37_2 * 3) + pub_r001492_2_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_91_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_91_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_91_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_91_2 * 2)) & 255;
  int stage_v_92_1 = ((pub_r001492_8_1 * 2) + 26) & 63;
  int stage_v_92_2 = ((pub_r001492_8_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_92_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_92_2) & 127;
  int stage_v_93_1 = ((pub_r001492_4_1 * 2) + 41) & 63;
  int stage_v_93_2 = ((pub_r001492_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_93_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_93_2) & 127;
  int stage_v_94_1 = ((pub_r001492_13_1 * 2) + 17) & 63;
  int stage_v_94_2 = ((pub_r001492_13_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_94_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_94_2) & 127;
  int stage_v_95_1 = ((pub_r001492_4_1 * 2) + 33) & 63;
  int stage_v_95_2 = ((pub_r001492_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_95_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_95_2) & 127;
  int stage_v_96_1 = (((stage_v_67_1 * 3) + pub_r001492_7_1) + 45) & 127;
  int stage_v_96_2 = (((stage_v_67_2 * 3) + pub_r001492_7_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_96_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_96_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_96_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_96_2 * 2)) & 255;
  int stage_v_97_1 = ((pub_r001492_15_1 * 2) + 7) & 63;
  int stage_v_97_2 = ((pub_r001492_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_97_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_97_2) & 127;
  int stage_v_98_1 = (((sec_r001492_16_1 * 3) + pub_r001492_5_1) + 34) & 127;
  int stage_v_98_2 = (((sec_r001492_16_2 * 3) + pub_r001492_5_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_98_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_98_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_98_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_98_2 * 2)) & 255;
  int stage_v_99_1 = (((stage_v_88_1 * 3) + pub_r001492_13_1) + 11) & 127;
  int stage_v_99_2 = (((stage_v_88_2 * 3) + pub_r001492_13_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_99_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_99_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_99_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_99_2 * 2)) & 255;
  int stage_v_100_1 = ((pub_r001492_5_1 * 2) + 38) & 63;
  int stage_v_100_2 = ((pub_r001492_5_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_100_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_100_2) & 127;
  int stage_v_101_1 = ((pub_r001492_1_1 * 2) + 27) & 63;
  int stage_v_101_2 = ((pub_r001492_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_101_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_101_2) & 127;
  int stage_v_102_1 = ((pub_r001492_4_1 * 2) + 38) & 63;
  int stage_v_102_2 = ((pub_r001492_4_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_102_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_102_2) & 127;
  int stage_v_103_1 = ((pub_r001492_7_1 * 2) + 50) & 63;
  int stage_v_103_2 = ((pub_r001492_7_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_103_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_103_2) & 127;
  int stage_v_104_1 = (((sec_r001492_18_1 * 3) + pub_r001492_3_1) + 29) & 127;
  int stage_v_104_2 = (((sec_r001492_18_2 * 3) + pub_r001492_3_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_104_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_104_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_104_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_104_2 * 2)) & 255;
  int stage_v_105_1 = ((pub_r001492_10_1 * 2) + 31) & 63;
  int stage_v_105_2 = ((pub_r001492_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_105_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_105_2) & 127;
  int stage_v_106_1 = ((pub_r001492_3_1 * 2) + 40) & 63;
  int stage_v_106_2 = ((pub_r001492_3_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_106_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_106_2) & 127;
  int stage_v_107_1 = ((pub_r001492_1_1 * 2) + 49) & 63;
  int stage_v_107_2 = ((pub_r001492_1_2 * 2) + 49) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_107_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_107_2) & 127;
  int stage_v_108_1 = ((pub_r001492_1_1 * 2) + 40) & 63;
  int stage_v_108_2 = ((pub_r001492_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_108_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_108_2) & 127;
  int stage_v_109_1 = ((pub_r001492_3_1 * 2) + 45) & 63;
  int stage_v_109_2 = ((pub_r001492_3_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_109_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_109_2) & 127;
  int stage_v_110_1 = ((pub_r001492_15_1 * 2) + 21) & 63;
  int stage_v_110_2 = ((pub_r001492_15_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_110_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_110_2) & 127;
  int stage_v_111_1 = ((pub_r001492_12_1 * 2) + 14) & 63;
  int stage_v_111_2 = ((pub_r001492_12_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_111_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_111_2) & 127;
  int stage_v_112_1 = ((pub_r001492_8_1 * 2) + 45) & 63;
  int stage_v_112_2 = ((pub_r001492_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_112_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_112_2) & 127;
  int stage_v_113_1 = (((stage_v_96_1 * 3) + pub_r001492_11_1) + 12) & 127;
  int stage_v_113_2 = (((stage_v_96_2 * 3) + pub_r001492_11_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_113_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_113_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_113_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_113_2 * 2)) & 255;
  int stage_v_114_1 = ((pub_r001492_7_1 * 2) + 24) & 63;
  int stage_v_114_2 = ((pub_r001492_7_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_114_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_114_2) & 127;
  int stage_v_115_1 = ((pub_r001492_4_1 * 2) + 41) & 63;
  int stage_v_115_2 = ((pub_r001492_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_115_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_115_2) & 127;
  int stage_v_116_1 = ((pub_r001492_4_1 * 2) + 33) & 63;
  int stage_v_116_2 = ((pub_r001492_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_116_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_116_2) & 127;
  int stage_v_117_1 = ((pub_r001492_4_1 * 2) + 27) & 63;
  int stage_v_117_2 = ((pub_r001492_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_117_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_117_2) & 127;
  int stage_v_118_1 = ((pub_r001492_0_1 * 2) + 23) & 63;
  int stage_v_118_2 = ((pub_r001492_0_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_118_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_118_2) & 127;
  int stage_v_119_1 = ((pub_r001492_12_1 * 2) + 32) & 63;
  int stage_v_119_2 = ((pub_r001492_12_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_119_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_119_2) & 127;
  int stage_v_120_1 = (((stage_v_71_1 * 3) + pub_r001492_9_1) + 44) & 127;
  int stage_v_120_2 = (((stage_v_71_2 * 3) + pub_r001492_9_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_120_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_120_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_120_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_120_2 * 2)) & 255;
  int stage_v_121_1 = ((pub_r001492_6_1 * 2) + 39) & 63;
  int stage_v_121_2 = ((pub_r001492_6_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_121_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_121_2) & 127;
  int stage_v_122_1 = ((pub_r001492_7_1 * 2) + 36) & 63;
  int stage_v_122_2 = ((pub_r001492_7_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_122_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_122_2) & 127;
  int stage_v_123_1 = ((pub_r001492_3_1 * 2) + 43) & 63;
  int stage_v_123_2 = ((pub_r001492_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_123_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_123_2) & 127;
  int stage_v_124_1 = ((pub_r001492_11_1 * 2) + 34) & 63;
  int stage_v_124_2 = ((pub_r001492_11_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_124_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_124_2) & 127;
  int stage_v_125_1 = ((pub_r001492_9_1 * 2) + 43) & 63;
  int stage_v_125_2 = ((pub_r001492_9_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_125_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_125_2) & 127;
  int stage_v_126_1 = ((pub_r001492_12_1 * 2) + 15) & 63;
  int stage_v_126_2 = ((pub_r001492_12_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_126_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_126_2) & 127;
  int stage_v_127_1 = ((pub_r001492_10_1 * 2) + 23) & 63;
  int stage_v_127_2 = ((pub_r001492_10_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_127_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_127_2) & 127;
  int stage_v_128_1 = ((pub_r001492_3_1 * 2) + 29) & 63;
  int stage_v_128_2 = ((pub_r001492_3_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_128_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_128_2) & 127;
  int stage_v_129_1 = (((stage_v_11_1 * 3) + pub_r001492_1_1) + 41) & 127;
  int stage_v_129_2 = (((stage_v_11_2 * 3) + pub_r001492_1_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_129_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_129_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_129_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_129_2 * 2)) & 255;
  int stage_v_130_1 = (((stage_v_5_1 * 3) + pub_r001492_16_1) + 24) & 127;
  int stage_v_130_2 = (((stage_v_5_2 * 3) + pub_r001492_16_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_130_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_130_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_130_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_130_2 * 2)) & 255;
  int stage_v_131_1 = ((pub_r001492_15_1 * 2) + 39) & 63;
  int stage_v_131_2 = ((pub_r001492_15_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_131_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_131_2) & 127;
  int stage_v_132_1 = ((pub_r001492_1_1 * 2) + 24) & 63;
  int stage_v_132_2 = ((pub_r001492_1_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_132_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_132_2) & 127;
  int stage_v_133_1 = (((stage_v_33_1 * 3) + pub_r001492_6_1) + 37) & 127;
  int stage_v_133_2 = (((stage_v_33_2 * 3) + pub_r001492_6_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_133_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_133_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_133_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_133_2 * 2)) & 255;
  int stage_v_134_1 = ((pub_r001492_16_1 * 2) + 27) & 63;
  int stage_v_134_2 = ((pub_r001492_16_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_134_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_134_2) & 127;
  int stage_v_135_1 = ((pub_r001492_1_1 * 2) + 43) & 63;
  int stage_v_135_2 = ((pub_r001492_1_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_135_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_135_2) & 127;
  int stage_v_136_1 = ((pub_r001492_12_1 * 2) + 8) & 63;
  int stage_v_136_2 = ((pub_r001492_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_136_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_136_2) & 127;
  int stage_v_137_1 = ((pub_r001492_13_1 * 2) + 7) & 63;
  int stage_v_137_2 = ((pub_r001492_13_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_137_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_137_2) & 127;
  int stage_v_138_1 = ((pub_r001492_2_1 * 2) + 11) & 63;
  int stage_v_138_2 = ((pub_r001492_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_138_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_138_2) & 127;
  int stage_v_139_1 = ((pub_r001492_14_1 * 2) + 36) & 63;
  int stage_v_139_2 = ((pub_r001492_14_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_139_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_139_2) & 127;
  int stage_v_140_1 = (((helper_flow_2_1 * 3) + pub_r001492_4_1) + 32) & 127;
  int stage_v_140_2 = (((helper_flow_2_2 * 3) + pub_r001492_4_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_140_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_140_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_140_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_140_2 * 2)) & 255;
  int stage_v_141_1 = (((stage_v_68_1 * 3) + pub_r001492_12_1) + 12) & 127;
  int stage_v_141_2 = (((stage_v_68_2 * 3) + pub_r001492_12_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_141_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_141_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_141_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_141_2 * 2)) & 255;
  int stage_v_142_1 = (((stage_v_3_1 * 3) + pub_r001492_13_1) + 8) & 127;
  int stage_v_142_2 = (((stage_v_3_2 * 3) + pub_r001492_13_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_142_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_142_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_142_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_142_2 * 2)) & 255;
  int stage_v_143_1 = ((pub_r001492_9_1 * 2) + 11) & 63;
  int stage_v_143_2 = ((pub_r001492_9_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_143_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_143_2) & 127;
  int stage_v_144_1 = (((stage_v_10_1 * 3) + pub_r001492_6_1) + 5) & 127;
  int stage_v_144_2 = (((stage_v_10_2 * 3) + pub_r001492_6_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_144_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_144_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_144_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_144_2 * 2)) & 255;
  int stage_v_145_1 = ((pub_r001492_15_1 * 2) + 18) & 63;
  int stage_v_145_2 = ((pub_r001492_15_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_145_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_145_2) & 127;
  int stage_v_146_1 = ((pub_r001492_4_1 * 2) + 12) & 63;
  int stage_v_146_2 = ((pub_r001492_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_146_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_146_2) & 127;
  int stage_v_147_1 = ((pub_r001492_1_1 * 2) + 17) & 63;
  int stage_v_147_2 = ((pub_r001492_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_147_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_147_2) & 127;
  int stage_v_148_1 = ((pub_r001492_14_1 * 2) + 22) & 63;
  int stage_v_148_2 = ((pub_r001492_14_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_148_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_148_2) & 127;
  int stage_v_149_1 = ((pub_r001492_8_1 * 2) + 32) & 63;
  int stage_v_149_2 = ((pub_r001492_8_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_149_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_149_2) & 127;
  int stage_v_150_1 = (((stage_v_19_1 * 3) + pub_r001492_2_1) + 9) & 127;
  int stage_v_150_2 = (((stage_v_19_2 * 3) + pub_r001492_2_2) + 9) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_150_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_150_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_150_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_150_2 * 2)) & 255;
  int stage_v_151_1 = ((pub_r001492_1_1 * 2) + 5) & 63;
  int stage_v_151_2 = ((pub_r001492_1_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_151_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_151_2) & 127;
  int stage_v_152_1 = (((helper_flow_2_1 * 3) + pub_r001492_3_1) + 13) & 127;
  int stage_v_152_2 = (((helper_flow_2_2 * 3) + pub_r001492_3_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_152_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_152_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_152_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_152_2 * 2)) & 255;
  int stage_v_153_1 = ((pub_r001492_9_1 * 2) + 31) & 63;
  int stage_v_153_2 = ((pub_r001492_9_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_153_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_153_2) & 127;
  int stage_v_154_1 = ((pub_r001492_16_1 * 2) + 37) & 63;
  int stage_v_154_2 = ((pub_r001492_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_154_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_154_2) & 127;
  int stage_v_155_1 = ((pub_r001492_11_1 * 2) + 9) & 63;
  int stage_v_155_2 = ((pub_r001492_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_155_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_155_2) & 127;
  int stage_v_156_1 = ((pub_r001492_10_1 * 2) + 31) & 63;
  int stage_v_156_2 = ((pub_r001492_10_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_156_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_156_2) & 127;
  int stage_v_157_1 = (((sec_r001492_4_1 * 3) + pub_r001492_1_1) + 44) & 127;
  int stage_v_157_2 = (((sec_r001492_4_2 * 3) + pub_r001492_1_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_157_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_157_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_157_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_157_2 * 2)) & 255;
  int stage_v_158_1 = ((pub_r001492_5_1 * 2) + 13) & 63;
  int stage_v_158_2 = ((pub_r001492_5_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_158_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_158_2) & 127;
  int stage_v_159_1 = ((pub_r001492_7_1 * 2) + 12) & 63;
  int stage_v_159_2 = ((pub_r001492_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_159_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_159_2) & 127;
  int stage_v_160_1 = ((pub_r001492_12_1 * 2) + 38) & 63;
  int stage_v_160_2 = ((pub_r001492_12_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_160_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_160_2) & 127;
  int stage_v_161_1 = ((pub_r001492_16_1 * 2) + 38) & 63;
  int stage_v_161_2 = ((pub_r001492_16_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_161_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_161_2) & 127;
  int stage_v_162_1 = ((pub_r001492_12_1 * 2) + 22) & 63;
  int stage_v_162_2 = ((pub_r001492_12_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_162_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_162_2) & 127;
  int stage_v_163_1 = ((pub_r001492_11_1 * 2) + 8) & 63;
  int stage_v_163_2 = ((pub_r001492_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_163_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_163_2) & 127;
  int stage_v_164_1 = ((pub_r001492_13_1 * 2) + 27) & 63;
  int stage_v_164_2 = ((pub_r001492_13_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_164_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_164_2) & 127;
  int stage_v_165_1 = ((pub_r001492_13_1 * 2) + 18) & 63;
  int stage_v_165_2 = ((pub_r001492_13_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_165_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_165_2) & 127;
  int stage_v_166_1 = (((stage_v_30_1 * 3) + pub_r001492_12_1) + 29) & 127;
  int stage_v_166_2 = (((stage_v_30_2 * 3) + pub_r001492_12_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_166_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_166_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_166_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_166_2 * 2)) & 255;
  int stage_v_167_1 = (((helper_flow_1_1 * 3) + pub_r001492_7_1) + 11) & 127;
  int stage_v_167_2 = (((helper_flow_1_2 * 3) + pub_r001492_7_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_167_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_167_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_167_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_167_2 * 2)) & 255;
  int stage_v_168_1 = (((stage_v_37_1 * 3) + pub_r001492_6_1) + 31) & 127;
  int stage_v_168_2 = (((stage_v_37_2 * 3) + pub_r001492_6_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_168_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_168_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_168_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_168_2 * 2)) & 255;
  int stage_v_169_1 = (((sec_r001492_7_1 * 3) + pub_r001492_16_1) + 11) & 127;
  int stage_v_169_2 = (((sec_r001492_7_2 * 3) + pub_r001492_16_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_169_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_169_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_169_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_169_2 * 2)) & 255;
  int stage_v_170_1 = ((pub_r001492_6_1 * 2) + 38) & 63;
  int stage_v_170_2 = ((pub_r001492_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_170_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_170_2) & 127;
  int stage_v_171_1 = ((pub_r001492_0_1 * 2) + 24) & 63;
  int stage_v_171_2 = ((pub_r001492_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_171_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_171_2) & 127;
  int stage_v_172_1 = (((stage_v_47_1 * 3) + pub_r001492_3_1) + 31) & 127;
  int stage_v_172_2 = (((stage_v_47_2 * 3) + pub_r001492_3_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_172_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_172_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_172_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_172_2 * 2)) & 255;
  int stage_v_173_1 = ((pub_r001492_13_1 * 2) + 22) & 63;
  int stage_v_173_2 = ((pub_r001492_13_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_173_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_173_2) & 127;
  int stage_v_174_1 = ((pub_r001492_12_1 * 2) + 29) & 63;
  int stage_v_174_2 = ((pub_r001492_12_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_174_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_174_2) & 127;
  int stage_v_175_1 = ((pub_r001492_8_1 * 2) + 33) & 63;
  int stage_v_175_2 = ((pub_r001492_8_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_175_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_175_2) & 127;
  int stage_v_176_1 = ((pub_r001492_10_1 * 2) + 41) & 63;
  int stage_v_176_2 = ((pub_r001492_10_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_176_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_176_2) & 127;
  int stage_v_177_1 = ((pub_r001492_3_1 * 2) + 47) & 63;
  int stage_v_177_2 = ((pub_r001492_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_177_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_177_2) & 127;
  int stage_v_178_1 = (((stage_v_169_1 * 3) + pub_r001492_15_1) + 31) & 127;
  int stage_v_178_2 = (((stage_v_169_2 * 3) + pub_r001492_15_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_178_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_178_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_178_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_178_2 * 2)) & 255;
  int stage_v_179_1 = ((pub_r001492_6_1 * 2) + 9) & 63;
  int stage_v_179_2 = ((pub_r001492_6_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_179_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_179_2) & 127;
  int stage_v_180_1 = (((stage_v_67_1 * 3) + pub_r001492_15_1) + 6) & 127;
  int stage_v_180_2 = (((stage_v_67_2 * 3) + pub_r001492_15_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_180_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_180_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_180_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_180_2 * 2)) & 255;
  int stage_v_181_1 = ((pub_r001492_10_1 * 2) + 10) & 63;
  int stage_v_181_2 = ((pub_r001492_10_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_181_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_181_2) & 127;
  int stage_v_182_1 = ((pub_r001492_3_1 * 2) + 31) & 63;
  int stage_v_182_2 = ((pub_r001492_3_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_182_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_182_2) & 127;
  int stage_v_183_1 = ((pub_r001492_13_1 * 2) + 28) & 63;
  int stage_v_183_2 = ((pub_r001492_13_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_183_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_183_2) & 127;
  int stage_v_184_1 = ((pub_r001492_14_1 * 2) + 13) & 63;
  int stage_v_184_2 = ((pub_r001492_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_184_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_184_2) & 127;
  int stage_v_185_1 = ((pub_r001492_0_1 * 2) + 38) & 63;
  int stage_v_185_2 = ((pub_r001492_0_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_185_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_185_2) & 127;
  int stage_v_186_1 = (((stage_v_12_1 * 3) + pub_r001492_10_1) + 13) & 127;
  int stage_v_186_2 = (((stage_v_12_2 * 3) + pub_r001492_10_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_186_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_186_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_186_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_186_2 * 2)) & 255;
  int stage_v_187_1 = (((stage_v_104_1 * 3) + pub_r001492_11_1) + 11) & 127;
  int stage_v_187_2 = (((stage_v_104_2 * 3) + pub_r001492_11_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_187_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_187_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_187_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_187_2 * 2)) & 255;
  int stage_v_188_1 = ((pub_r001492_11_1 * 2) + 29) & 63;
  int stage_v_188_2 = ((pub_r001492_11_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_188_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_188_2) & 127;
  int stage_v_189_1 = ((pub_r001492_8_1 * 2) + 47) & 63;
  int stage_v_189_2 = ((pub_r001492_8_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_189_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_189_2) & 127;
  int stage_v_190_1 = ((pub_r001492_2_1 * 2) + 26) & 63;
  int stage_v_190_2 = ((pub_r001492_2_2 * 2) + 26) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_190_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_190_2) & 127;
  int stage_v_191_1 = (((stage_v_166_1 * 3) + pub_r001492_5_1) + 27) & 127;
  int stage_v_191_2 = (((stage_v_166_2 * 3) + pub_r001492_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_191_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_191_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_191_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_191_2 * 2)) & 255;
  int stage_v_192_1 = (((stage_v_34_1 * 3) + pub_r001492_5_1) + 39) & 127;
  int stage_v_192_2 = (((stage_v_34_2 * 3) + pub_r001492_5_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_192_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_192_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_192_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_192_2 * 2)) & 255;
  int stage_v_193_1 = ((pub_r001492_16_1 * 2) + 5) & 63;
  int stage_v_193_2 = ((pub_r001492_16_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_193_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_193_2) & 127;
  int stage_v_194_1 = ((pub_r001492_7_1 * 2) + 14) & 63;
  int stage_v_194_2 = ((pub_r001492_7_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_194_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_194_2) & 127;
  int stage_v_195_1 = ((pub_r001492_14_1 * 2) + 12) & 63;
  int stage_v_195_2 = ((pub_r001492_14_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_195_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_195_2) & 127;
  int stage_v_196_1 = (((sec_r001492_5_1 * 3) + pub_r001492_2_1) + 5) & 127;
  int stage_v_196_2 = (((sec_r001492_5_2 * 3) + pub_r001492_2_2) + 5) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_196_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_196_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_196_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_196_2 * 2)) & 255;
  int stage_v_197_1 = ((pub_r001492_13_1 * 2) + 35) & 63;
  int stage_v_197_2 = ((pub_r001492_13_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_197_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_197_2) & 127;
  int stage_v_198_1 = (((stage_v_98_1 * 3) + pub_r001492_1_1) + 15) & 127;
  int stage_v_198_2 = (((stage_v_98_2 * 3) + pub_r001492_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_198_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_198_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_198_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_198_2 * 2)) & 255;
  int stage_v_199_1 = ((pub_r001492_1_1 * 2) + 44) & 63;
  int stage_v_199_2 = ((pub_r001492_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_199_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_199_2) & 127;
  int stage_v_200_1 = ((pub_r001492_8_1 * 2) + 12) & 63;
  int stage_v_200_2 = ((pub_r001492_8_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_200_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_200_2) & 127;
  int stage_v_201_1 = (((stage_v_133_1 * 3) + pub_r001492_2_1) + 39) & 127;
  int stage_v_201_2 = (((stage_v_133_2 * 3) + pub_r001492_2_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_201_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_201_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_201_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_201_2 * 2)) & 255;
  int stage_v_202_1 = ((pub_r001492_11_1 * 2) + 43) & 63;
  int stage_v_202_2 = ((pub_r001492_11_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_202_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_202_2) & 127;
  int stage_v_203_1 = ((pub_r001492_0_1 * 2) + 48) & 63;
  int stage_v_203_2 = ((pub_r001492_0_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_203_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_203_2) & 127;
  int stage_v_204_1 = (((stage_v_166_1 * 3) + pub_r001492_1_1) + 28) & 127;
  int stage_v_204_2 = (((stage_v_166_2 * 3) + pub_r001492_1_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_204_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_204_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_204_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_204_2 * 2)) & 255;
  int stage_v_205_1 = (((stage_v_157_1 * 3) + pub_r001492_14_1) + 10) & 127;
  int stage_v_205_2 = (((stage_v_157_2 * 3) + pub_r001492_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_205_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_205_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_205_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_205_2 * 2)) & 255;
  int stage_v_206_1 = (((stage_v_186_1 * 3) + pub_r001492_16_1) + 17) & 127;
  int stage_v_206_2 = (((stage_v_186_2 * 3) + pub_r001492_16_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_206_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_206_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_206_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_206_2 * 2)) & 255;
  int stage_v_207_1 = (((stage_v_3_1 * 3) + pub_r001492_6_1) + 33) & 127;
  int stage_v_207_2 = (((stage_v_3_2 * 3) + pub_r001492_6_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_207_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_207_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_207_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_207_2 * 2)) & 255;
  int stage_v_208_1 = ((pub_r001492_1_1 * 2) + 42) & 63;
  int stage_v_208_2 = ((pub_r001492_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_208_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_208_2) & 127;
  int stage_v_209_1 = ((pub_r001492_16_1 * 2) + 34) & 63;
  int stage_v_209_2 = ((pub_r001492_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_209_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_209_2) & 127;
  int stage_v_210_1 = ((pub_r001492_12_1 * 2) + 35) & 63;
  int stage_v_210_2 = ((pub_r001492_12_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_210_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_210_2) & 127;
  int stage_v_211_1 = ((pub_r001492_2_1 * 2) + 42) & 63;
  int stage_v_211_2 = ((pub_r001492_2_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_211_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_211_2) & 127;
  int stage_v_212_1 = ((pub_r001492_16_1 * 2) + 18) & 63;
  int stage_v_212_2 = ((pub_r001492_16_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_212_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_212_2) & 127;
  int stage_v_213_1 = (((stage_v_166_1 * 3) + pub_r001492_3_1) + 18) & 127;
  int stage_v_213_2 = (((stage_v_166_2 * 3) + pub_r001492_3_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_213_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_213_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_213_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_213_2 * 2)) & 255;
  int stage_v_214_1 = ((pub_r001492_2_1 * 2) + 14) & 63;
  int stage_v_214_2 = ((pub_r001492_2_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_214_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_214_2) & 127;
  int stage_v_215_1 = (((stage_v_98_1 * 3) + pub_r001492_1_1) + 15) & 127;
  int stage_v_215_2 = (((stage_v_98_2 * 3) + pub_r001492_1_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_215_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_215_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_215_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_215_2 * 2)) & 255;
  int stage_v_216_1 = (((stage_v_113_1 * 3) + pub_r001492_13_1) + 30) & 127;
  int stage_v_216_2 = (((stage_v_113_2 * 3) + pub_r001492_13_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_216_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_216_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_216_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_216_2 * 2)) & 255;
  int stage_v_217_1 = (((stage_v_198_1 * 3) + pub_r001492_15_1) + 41) & 127;
  int stage_v_217_2 = (((stage_v_198_2 * 3) + pub_r001492_15_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_217_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_217_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_217_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_217_2 * 2)) & 255;
  int stage_v_218_1 = ((pub_r001492_0_1 * 2) + 11) & 63;
  int stage_v_218_2 = ((pub_r001492_0_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_218_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_218_2) & 127;
  int stage_v_219_1 = ((pub_r001492_0_1 * 2) + 17) & 63;
  int stage_v_219_2 = ((pub_r001492_0_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_219_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_219_2) & 127;
  int stage_v_220_1 = (((sec_r001492_15_1 * 3) + pub_r001492_10_1) + 35) & 127;
  int stage_v_220_2 = (((sec_r001492_15_2 * 3) + pub_r001492_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_220_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_220_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_220_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_220_2 * 2)) & 255;
  int stage_v_221_1 = ((pub_r001492_9_1 * 2) + 30) & 63;
  int stage_v_221_2 = ((pub_r001492_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_221_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_221_2) & 127;
  int stage_v_222_1 = (((stage_v_186_1 * 3) + pub_r001492_11_1) + 45) & 127;
  int stage_v_222_2 = (((stage_v_186_2 * 3) + pub_r001492_11_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_222_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_222_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_222_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_222_2 * 2)) & 255;
  int stage_v_223_1 = ((pub_r001492_5_1 * 2) + 47) & 63;
  int stage_v_223_2 = ((pub_r001492_5_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_223_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_223_2) & 127;
  int stage_v_224_1 = ((pub_r001492_14_1 * 2) + 44) & 63;
  int stage_v_224_2 = ((pub_r001492_14_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_224_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_224_2) & 127;
  int stage_v_225_1 = (((stage_v_150_1 * 3) + pub_r001492_4_1) + 36) & 127;
  int stage_v_225_2 = (((stage_v_150_2 * 3) + pub_r001492_4_2) + 36) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_225_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_225_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_225_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_225_2 * 2)) & 255;
  int stage_v_226_1 = (((stage_v_191_1 * 3) + pub_r001492_5_1) + 12) & 127;
  int stage_v_226_2 = (((stage_v_191_2 * 3) + pub_r001492_5_2) + 12) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_226_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_226_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_226_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_226_2 * 2)) & 255;
  int stage_v_227_1 = (((stage_v_129_1 * 3) + pub_r001492_14_1) + 10) & 127;
  int stage_v_227_2 = (((stage_v_129_2 * 3) + pub_r001492_14_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_227_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_227_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_227_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_227_2 * 2)) & 255;
  int stage_v_228_1 = ((pub_r001492_5_1 * 2) + 41) & 63;
  int stage_v_228_2 = ((pub_r001492_5_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_228_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_228_2) & 127;
  int stage_v_229_1 = (((stage_v_186_1 * 3) + pub_r001492_12_1) + 21) & 127;
  int stage_v_229_2 = (((stage_v_186_2 * 3) + pub_r001492_12_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_229_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_229_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_229_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_229_2 * 2)) & 255;
  int stage_v_230_1 = ((pub_r001492_3_1 * 2) + 21) & 63;
  int stage_v_230_2 = ((pub_r001492_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_230_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_230_2) & 127;
  int stage_v_231_1 = (((stage_v_16_1 * 3) + pub_r001492_6_1) + 19) & 127;
  int stage_v_231_2 = (((stage_v_16_2 * 3) + pub_r001492_6_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_231_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_231_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_231_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_231_2 * 2)) & 255;
  int stage_v_232_1 = (((helper_flow_1_1 * 3) + pub_r001492_7_1) + 32) & 127;
  int stage_v_232_2 = (((helper_flow_1_2 * 3) + pub_r001492_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_232_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_232_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_232_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_232_2 * 2)) & 255;
  int stage_v_233_1 = (((stage_v_39_1 * 3) + pub_r001492_2_1) + 7) & 127;
  int stage_v_233_2 = (((stage_v_39_2 * 3) + pub_r001492_2_2) + 7) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_233_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_233_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_233_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_233_2 * 2)) & 255;
  int stage_v_234_1 = ((pub_r001492_0_1 * 2) + 27) & 63;
  int stage_v_234_2 = ((pub_r001492_0_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_234_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_234_2) & 127;
  int stage_v_235_1 = ((pub_r001492_6_1 * 2) + 48) & 63;
  int stage_v_235_2 = ((pub_r001492_6_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_235_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_235_2) & 127;
  int stage_v_236_1 = ((pub_r001492_12_1 * 2) + 41) & 63;
  int stage_v_236_2 = ((pub_r001492_12_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_236_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_236_2) & 127;
  int stage_v_237_1 = ((pub_r001492_13_1 * 2) + 39) & 63;
  int stage_v_237_2 = ((pub_r001492_13_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_237_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_237_2) & 127;
  int stage_v_238_1 = ((pub_r001492_16_1 * 2) + 32) & 63;
  int stage_v_238_2 = ((pub_r001492_16_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_238_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_238_2) & 127;
  int stage_v_239_1 = ((pub_r001492_8_1 * 2) + 41) & 63;
  int stage_v_239_2 = ((pub_r001492_8_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_239_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_239_2) & 127;
  int stage_v_240_1 = ((pub_r001492_5_1 * 2) + 8) & 63;
  int stage_v_240_2 = ((pub_r001492_5_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_240_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_240_2) & 127;
  int stage_v_241_1 = (((stage_v_186_1 * 3) + pub_r001492_14_1) + 13) & 127;
  int stage_v_241_2 = (((stage_v_186_2 * 3) + pub_r001492_14_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_241_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_241_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_241_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_241_2 * 2)) & 255;
  int stage_v_242_1 = ((pub_r001492_7_1 * 2) + 12) & 63;
  int stage_v_242_2 = ((pub_r001492_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_242_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_242_2) & 127;
  int stage_v_243_1 = ((pub_r001492_14_1 * 2) + 27) & 63;
  int stage_v_243_2 = ((pub_r001492_14_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_243_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_243_2) & 127;
  int stage_v_244_1 = ((pub_r001492_3_1 * 2) + 43) & 63;
  int stage_v_244_2 = ((pub_r001492_3_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_244_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_244_2) & 127;
  int stage_v_245_1 = ((pub_r001492_3_1 * 2) + 36) & 63;
  int stage_v_245_2 = ((pub_r001492_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_245_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_245_2) & 127;
  int stage_v_246_1 = ((pub_r001492_12_1 * 2) + 40) & 63;
  int stage_v_246_2 = ((pub_r001492_12_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_246_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_246_2) & 127;
  int stage_v_247_1 = ((pub_r001492_12_1 * 2) + 47) & 63;
  int stage_v_247_2 = ((pub_r001492_12_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_247_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_247_2) & 127;
  int stage_v_248_1 = ((pub_r001492_8_1 * 2) + 38) & 63;
  int stage_v_248_2 = ((pub_r001492_8_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_248_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_248_2) & 127;
  int stage_v_249_1 = ((pub_r001492_12_1 * 2) + 34) & 63;
  int stage_v_249_2 = ((pub_r001492_12_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_249_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_249_2) & 127;
  int stage_v_250_1 = (((stage_v_98_1 * 3) + pub_r001492_3_1) + 34) & 127;
  int stage_v_250_2 = (((stage_v_98_2 * 3) + pub_r001492_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_250_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_250_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_250_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_250_2 * 2)) & 255;
  int stage_v_251_1 = ((pub_r001492_16_1 * 2) + 35) & 63;
  int stage_v_251_2 = ((pub_r001492_16_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_251_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_251_2) & 127;
  int stage_v_252_1 = ((pub_r001492_9_1 * 2) + 9) & 63;
  int stage_v_252_2 = ((pub_r001492_9_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_252_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_252_2) & 127;
  int stage_v_253_1 = ((pub_r001492_0_1 * 2) + 19) & 63;
  int stage_v_253_2 = ((pub_r001492_0_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_253_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_253_2) & 127;
  int stage_v_254_1 = ((pub_r001492_6_1 * 2) + 27) & 63;
  int stage_v_254_2 = ((pub_r001492_6_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_254_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_254_2) & 127;
  int stage_v_255_1 = ((pub_r001492_6_1 * 2) + 13) & 63;
  int stage_v_255_2 = ((pub_r001492_6_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_255_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_255_2) & 127;
  int stage_v_256_1 = ((pub_r001492_4_1 * 2) + 12) & 63;
  int stage_v_256_2 = ((pub_r001492_4_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_256_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_256_2) & 127;
  int stage_v_257_1 = ((pub_r001492_5_1 * 2) + 33) & 63;
  int stage_v_257_2 = ((pub_r001492_5_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_257_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_257_2) & 127;
  int stage_v_258_1 = ((pub_r001492_9_1 * 2) + 7) & 63;
  int stage_v_258_2 = ((pub_r001492_9_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_258_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_258_2) & 127;
  int stage_v_259_1 = ((pub_r001492_15_1 * 2) + 48) & 63;
  int stage_v_259_2 = ((pub_r001492_15_2 * 2) + 48) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_259_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_259_2) & 127;
  int stage_v_260_1 = ((pub_r001492_2_1 * 2) + 45) & 63;
  int stage_v_260_2 = ((pub_r001492_2_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_260_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_260_2) & 127;
  int stage_v_261_1 = ((pub_r001492_4_1 * 2) + 41) & 63;
  int stage_v_261_2 = ((pub_r001492_4_2 * 2) + 41) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_261_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_261_2) & 127;
  int stage_v_262_1 = ((pub_r001492_6_1 * 2) + 50) & 63;
  int stage_v_262_2 = ((pub_r001492_6_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_262_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_262_2) & 127;
  int stage_v_263_1 = (((stage_v_213_1 * 3) + pub_r001492_9_1) + 39) & 127;
  int stage_v_263_2 = (((stage_v_213_2 * 3) + pub_r001492_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_263_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_263_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_263_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_263_2 * 2)) & 255;
  int stage_v_264_1 = ((pub_r001492_0_1 * 2) + 25) & 63;
  int stage_v_264_2 = ((pub_r001492_0_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_264_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_264_2) & 127;
  int stage_v_265_1 = (((stage_v_141_1 * 3) + pub_r001492_12_1) + 18) & 127;
  int stage_v_265_2 = (((stage_v_141_2 * 3) + pub_r001492_12_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_265_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_265_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_265_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_265_2 * 2)) & 255;
  int stage_v_266_1 = (((stage_v_226_1 * 3) + pub_r001492_8_1) + 30) & 127;
  int stage_v_266_2 = (((stage_v_226_2 * 3) + pub_r001492_8_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_266_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_266_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_266_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_266_2 * 2)) & 255;
  int stage_v_267_1 = (((stage_v_47_1 * 3) + pub_r001492_4_1) + 31) & 127;
  int stage_v_267_2 = (((stage_v_47_2 * 3) + pub_r001492_4_2) + 31) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_267_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_267_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_267_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_267_2 * 2)) & 255;
  int stage_v_268_1 = (((stage_v_192_1 * 3) + pub_r001492_12_1) + 45) & 127;
  int stage_v_268_2 = (((stage_v_192_2 * 3) + pub_r001492_12_2) + 45) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_268_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_268_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_268_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_268_2 * 2)) & 255;
  int stage_v_269_1 = (((stage_v_172_1 * 3) + pub_r001492_8_1) + 37) & 127;
  int stage_v_269_2 = (((stage_v_172_2 * 3) + pub_r001492_8_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_269_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_269_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_269_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_269_2 * 2)) & 255;
  int stage_v_270_1 = ((pub_r001492_1_1 * 2) + 40) & 63;
  int stage_v_270_2 = ((pub_r001492_1_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_270_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_270_2) & 127;
  int stage_v_271_1 = ((pub_r001492_7_1 * 2) + 31) & 63;
  int stage_v_271_2 = ((pub_r001492_7_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_271_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_271_2) & 127;
  int stage_v_272_1 = ((pub_r001492_2_1 * 2) + 15) & 63;
  int stage_v_272_2 = ((pub_r001492_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_272_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_272_2) & 127;
  int stage_v_273_1 = (((stage_v_104_1 * 3) + pub_r001492_1_1) + 43) & 127;
  int stage_v_273_2 = (((stage_v_104_2 * 3) + pub_r001492_1_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_273_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_273_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_273_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_273_2 * 2)) & 255;
  int stage_v_274_1 = ((pub_r001492_4_1 * 2) + 27) & 63;
  int stage_v_274_2 = ((pub_r001492_4_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_274_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_274_2) & 127;
  int stage_v_275_1 = ((pub_r001492_3_1 * 2) + 16) & 63;
  int stage_v_275_2 = ((pub_r001492_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_275_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_275_2) & 127;
  int stage_v_276_1 = ((pub_r001492_16_1 * 2) + 15) & 63;
  int stage_v_276_2 = ((pub_r001492_16_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_276_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_276_2) & 127;
  int stage_v_277_1 = ((pub_r001492_8_1 * 2) + 31) & 63;
  int stage_v_277_2 = ((pub_r001492_8_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_277_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_277_2) & 127;
  int stage_v_278_1 = (((helper_flow_0_1 * 3) + pub_r001492_11_1) + 40) & 127;
  int stage_v_278_2 = (((helper_flow_0_2 * 3) + pub_r001492_11_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_278_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_278_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_278_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_278_2 * 2)) & 255;
  int stage_v_279_1 = ((pub_r001492_2_1 * 2) + 27) & 63;
  int stage_v_279_2 = ((pub_r001492_2_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_279_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_279_2) & 127;
  int stage_v_280_1 = (((stage_v_27_1 * 3) + pub_r001492_12_1) + 43) & 127;
  int stage_v_280_2 = (((stage_v_27_2 * 3) + pub_r001492_12_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_280_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_280_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_280_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_280_2 * 2)) & 255;
  int stage_v_281_1 = (((stage_v_0_1 * 3) + pub_r001492_0_1) + 41) & 127;
  int stage_v_281_2 = (((stage_v_0_2 * 3) + pub_r001492_0_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_281_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_281_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_281_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_281_2 * 2)) & 255;
  int stage_v_282_1 = ((pub_r001492_2_1 * 2) + 39) & 63;
  int stage_v_282_2 = ((pub_r001492_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_282_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_282_2) & 127;
  int stage_v_283_1 = (((stage_v_152_1 * 3) + pub_r001492_6_1) + 4) & 127;
  int stage_v_283_2 = (((stage_v_152_2 * 3) + pub_r001492_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_283_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_283_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_283_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_283_2 * 2)) & 255;
  int stage_v_284_1 = ((pub_r001492_9_1 * 2) + 37) & 63;
  int stage_v_284_2 = ((pub_r001492_9_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_284_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_284_2) & 127;
  int stage_v_285_1 = ((pub_r001492_9_1 * 2) + 12) & 63;
  int stage_v_285_2 = ((pub_r001492_9_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_285_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_285_2) & 127;
  int stage_v_286_1 = ((pub_r001492_2_1 * 2) + 29) & 63;
  int stage_v_286_2 = ((pub_r001492_2_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_286_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_286_2) & 127;
  int stage_v_287_1 = (((stage_v_16_1 * 3) + pub_r001492_14_1) + 29) & 127;
  int stage_v_287_2 = (((stage_v_16_2 * 3) + pub_r001492_14_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_287_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_287_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_287_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_287_2 * 2)) & 255;
  int stage_v_288_1 = ((pub_r001492_1_1 * 2) + 45) & 63;
  int stage_v_288_2 = ((pub_r001492_1_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_288_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_288_2) & 127;
  int stage_v_289_1 = ((pub_r001492_2_1 * 2) + 11) & 63;
  int stage_v_289_2 = ((pub_r001492_2_2 * 2) + 11) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_289_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_289_2) & 127;
  int stage_v_290_1 = ((pub_r001492_2_1 * 2) + 19) & 63;
  int stage_v_290_2 = ((pub_r001492_2_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_290_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_290_2) & 127;
  int stage_v_291_1 = ((pub_r001492_8_1 * 2) + 21) & 63;
  int stage_v_291_2 = ((pub_r001492_8_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_291_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_291_2) & 127;
  int stage_v_292_1 = ((pub_r001492_14_1 * 2) + 13) & 63;
  int stage_v_292_2 = ((pub_r001492_14_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_292_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_292_2) & 127;
  int stage_v_293_1 = ((pub_r001492_2_1 * 2) + 15) & 63;
  int stage_v_293_2 = ((pub_r001492_2_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_293_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_293_2) & 127;
  int stage_v_294_1 = ((pub_r001492_11_1 * 2) + 8) & 63;
  int stage_v_294_2 = ((pub_r001492_11_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_294_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_294_2) & 127;
  int stage_v_295_1 = (((stage_v_68_1 * 3) + pub_r001492_12_1) + 11) & 127;
  int stage_v_295_2 = (((stage_v_68_2 * 3) + pub_r001492_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_295_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_295_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_295_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_295_2 * 2)) & 255;
  int stage_v_296_1 = (((stage_v_0_1 * 3) + pub_r001492_12_1) + 11) & 127;
  int stage_v_296_2 = (((stage_v_0_2 * 3) + pub_r001492_12_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_296_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_296_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_296_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_296_2 * 2)) & 255;
  int stage_v_297_1 = ((pub_r001492_11_1 * 2) + 40) & 63;
  int stage_v_297_2 = ((pub_r001492_11_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_297_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_297_2) & 127;
  int stage_v_298_1 = ((pub_r001492_16_1 * 2) + 34) & 63;
  int stage_v_298_2 = ((pub_r001492_16_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_298_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_298_2) & 127;
  int stage_v_299_1 = ((pub_r001492_0_1 * 2) + 20) & 63;
  int stage_v_299_2 = ((pub_r001492_0_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_299_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_299_2) & 127;
  int stage_v_300_1 = ((pub_r001492_0_1 * 2) + 24) & 63;
  int stage_v_300_2 = ((pub_r001492_0_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_300_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_300_2) & 127;
  int stage_v_301_1 = (((sec_r001492_12_1 * 3) + pub_r001492_9_1) + 42) & 127;
  int stage_v_301_2 = (((sec_r001492_12_2 * 3) + pub_r001492_9_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_301_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_301_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_301_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_301_2 * 2)) & 255;
  int stage_v_302_1 = ((pub_r001492_4_1 * 2) + 5) & 63;
  int stage_v_302_2 = ((pub_r001492_4_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_302_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_302_2) & 127;
  int stage_v_303_1 = (((stage_v_133_1 * 3) + pub_r001492_9_1) + 34) & 127;
  int stage_v_303_2 = (((stage_v_133_2 * 3) + pub_r001492_9_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_303_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_303_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_303_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_303_2 * 2)) & 255;
  int stage_v_304_1 = (((stage_v_267_1 * 3) + pub_r001492_5_1) + 30) & 127;
  int stage_v_304_2 = (((stage_v_267_2 * 3) + pub_r001492_5_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_304_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_304_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_304_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_304_2 * 2)) & 255;
  int stage_v_305_1 = ((pub_r001492_7_1 * 2) + 29) & 63;
  int stage_v_305_2 = ((pub_r001492_7_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_305_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_305_2) & 127;
  int stage_v_306_1 = ((pub_r001492_8_1 * 2) + 23) & 63;
  int stage_v_306_2 = ((pub_r001492_8_2 * 2) + 23) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_306_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_306_2) & 127;
  int stage_v_307_1 = ((pub_r001492_4_1 * 2) + 33) & 63;
  int stage_v_307_2 = ((pub_r001492_4_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_307_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_307_2) & 127;
  int stage_v_308_1 = (((stage_v_229_1 * 3) + pub_r001492_6_1) + 30) & 127;
  int stage_v_308_2 = (((stage_v_229_2 * 3) + pub_r001492_6_2) + 30) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_308_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_308_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_308_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_308_2 * 2)) & 255;
  int stage_v_309_1 = ((pub_r001492_9_1 * 2) + 34) & 63;
  int stage_v_309_2 = ((pub_r001492_9_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_309_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_309_2) & 127;
  int stage_v_310_1 = ((pub_r001492_12_1 * 2) + 21) & 63;
  int stage_v_310_2 = ((pub_r001492_12_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_310_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_310_2) & 127;
  int stage_v_311_1 = (((stage_v_142_1 * 3) + pub_r001492_5_1) + 35) & 127;
  int stage_v_311_2 = (((stage_v_142_2 * 3) + pub_r001492_5_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_311_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_311_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_311_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_311_2 * 2)) & 255;
  int stage_v_312_1 = (((stage_v_226_1 * 3) + pub_r001492_9_1) + 16) & 127;
  int stage_v_312_2 = (((stage_v_226_2 * 3) + pub_r001492_9_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_312_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_312_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_312_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_312_2 * 2)) & 255;
  int stage_v_313_1 = ((pub_r001492_3_1 * 2) + 36) & 63;
  int stage_v_313_2 = ((pub_r001492_3_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_313_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_313_2) & 127;
  int stage_v_314_1 = (((stage_v_55_1 * 3) + pub_r001492_7_1) + 43) & 127;
  int stage_v_314_2 = (((stage_v_55_2 * 3) + pub_r001492_7_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_314_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_314_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_314_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_314_2 * 2)) & 255;
  int stage_v_315_1 = (((stage_v_250_1 * 3) + pub_r001492_4_1) + 41) & 127;
  int stage_v_315_2 = (((stage_v_250_2 * 3) + pub_r001492_4_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_315_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_315_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_315_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_315_2 * 2)) & 255;
  int stage_v_316_1 = (((stage_v_71_1 * 3) + pub_r001492_16_1) + 28) & 127;
  int stage_v_316_2 = (((stage_v_71_2 * 3) + pub_r001492_16_2) + 28) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_316_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_316_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_316_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_316_2 * 2)) & 255;
  int stage_v_317_1 = ((pub_r001492_8_1 * 2) + 19) & 63;
  int stage_v_317_2 = ((pub_r001492_8_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_317_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_317_2) & 127;
  int stage_v_318_1 = (((stage_v_167_1 * 3) + pub_r001492_3_1) + 34) & 127;
  int stage_v_318_2 = (((stage_v_167_2 * 3) + pub_r001492_3_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_318_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_318_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_318_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_318_2 * 2)) & 255;
  int stage_v_319_1 = (((stage_v_19_1 * 3) + pub_r001492_6_1) + 41) & 127;
  int stage_v_319_2 = (((stage_v_19_2 * 3) + pub_r001492_6_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_319_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_319_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_319_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_319_2 * 2)) & 255;
  int stage_v_320_1 = ((pub_r001492_1_1 * 2) + 15) & 63;
  int stage_v_320_2 = ((pub_r001492_1_2 * 2) + 15) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_320_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_320_2) & 127;
  int stage_v_321_1 = ((pub_r001492_16_1 * 2) + 37) & 63;
  int stage_v_321_2 = ((pub_r001492_16_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_321_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_321_2) & 127;
  int stage_v_322_1 = ((pub_r001492_1_1 * 2) + 42) & 63;
  int stage_v_322_2 = ((pub_r001492_1_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_322_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_322_2) & 127;
  int stage_v_323_1 = ((pub_r001492_8_1 * 2) + 36) & 63;
  int stage_v_323_2 = ((pub_r001492_8_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_323_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_323_2) & 127;
  int stage_v_324_1 = ((pub_r001492_16_1 * 2) + 20) & 63;
  int stage_v_324_2 = ((pub_r001492_16_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_324_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_324_2) & 127;
  int stage_v_325_1 = ((pub_r001492_3_1 * 2) + 16) & 63;
  int stage_v_325_2 = ((pub_r001492_3_2 * 2) + 16) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_325_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_325_2) & 127;
  int stage_v_326_1 = ((pub_r001492_6_1 * 2) + 38) & 63;
  int stage_v_326_2 = ((pub_r001492_6_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_326_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_326_2) & 127;
  int stage_v_327_1 = ((pub_r001492_1_1 * 2) + 47) & 63;
  int stage_v_327_2 = ((pub_r001492_1_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_327_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_327_2) & 127;
  int stage_v_328_1 = ((pub_r001492_15_1 * 2) + 7) & 63;
  int stage_v_328_2 = ((pub_r001492_15_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_328_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_328_2) & 127;
  int stage_v_329_1 = ((pub_r001492_8_1 * 2) + 44) & 63;
  int stage_v_329_2 = ((pub_r001492_8_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_329_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_329_2) & 127;
  int stage_v_330_1 = ((pub_r001492_14_1 * 2) + 10) & 63;
  int stage_v_330_2 = ((pub_r001492_14_2 * 2) + 10) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_330_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_330_2) & 127;
  int stage_v_331_1 = ((pub_r001492_11_1 * 2) + 14) & 63;
  int stage_v_331_2 = ((pub_r001492_11_2 * 2) + 14) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_331_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_331_2) & 127;
  int stage_v_332_1 = (((stage_v_180_1 * 3) + pub_r001492_8_1) + 10) & 127;
  int stage_v_332_2 = (((stage_v_180_2 * 3) + pub_r001492_8_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_332_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_332_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_332_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_332_2 * 2)) & 255;
  int stage_v_333_1 = ((pub_r001492_6_1 * 2) + 6) & 63;
  int stage_v_333_2 = ((pub_r001492_6_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_333_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_333_2) & 127;
  int stage_v_334_1 = (((stage_v_104_1 * 3) + pub_r001492_4_1) + 8) & 127;
  int stage_v_334_2 = (((stage_v_104_2 * 3) + pub_r001492_4_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_334_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_334_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_334_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_334_2 * 2)) & 255;
  int stage_v_335_1 = (((stage_v_172_1 * 3) + pub_r001492_9_1) + 40) & 127;
  int stage_v_335_2 = (((stage_v_172_2 * 3) + pub_r001492_9_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_335_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_335_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_335_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_335_2 * 2)) & 255;
  int stage_v_336_1 = (((stage_v_231_1 * 3) + pub_r001492_7_1) + 42) & 127;
  int stage_v_336_2 = (((stage_v_231_2 * 3) + pub_r001492_7_2) + 42) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_336_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_336_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_336_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_336_2 * 2)) & 255;
  int stage_v_337_1 = ((pub_r001492_0_1 * 2) + 6) & 63;
  int stage_v_337_2 = ((pub_r001492_0_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_337_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_337_2) & 127;
  int stage_v_338_1 = (((stage_v_281_1 * 3) + pub_r001492_15_1) + 33) & 127;
  int stage_v_338_2 = (((stage_v_281_2 * 3) + pub_r001492_15_2) + 33) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_338_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_338_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_338_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_338_2 * 2)) & 255;
  int stage_v_339_1 = ((pub_r001492_0_1 * 2) + 9) & 63;
  int stage_v_339_2 = ((pub_r001492_0_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_339_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_339_2) & 127;
  int stage_v_340_1 = (((stage_v_201_1 * 3) + pub_r001492_4_1) + 34) & 127;
  int stage_v_340_2 = (((stage_v_201_2 * 3) + pub_r001492_4_2) + 34) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_340_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_340_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_340_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_340_2 * 2)) & 255;
  int stage_v_341_1 = (((stage_v_304_1 * 3) + pub_r001492_2_1) + 20) & 127;
  int stage_v_341_2 = (((stage_v_304_2 * 3) + pub_r001492_2_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_341_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_341_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_341_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_341_2 * 2)) & 255;
  int stage_v_342_1 = (((stage_v_204_1 * 3) + pub_r001492_13_1) + 32) & 127;
  int stage_v_342_2 = (((stage_v_204_2 * 3) + pub_r001492_13_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_342_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_342_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_342_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_342_2 * 2)) & 255;
  int stage_v_343_1 = (((stage_v_301_1 * 3) + pub_r001492_7_1) + 32) & 127;
  int stage_v_343_2 = (((stage_v_301_2 * 3) + pub_r001492_7_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_343_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_343_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_343_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_343_2 * 2)) & 255;
  int stage_v_344_1 = (((stage_v_314_1 * 3) + pub_r001492_5_1) + 32) & 127;
  int stage_v_344_2 = (((stage_v_314_2 * 3) + pub_r001492_5_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_344_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_344_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_344_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_344_2 * 2)) & 255;
  int stage_v_345_1 = ((pub_r001492_14_1 * 2) + 40) & 63;
  int stage_v_345_2 = ((pub_r001492_14_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_345_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_345_2) & 127;
  int stage_v_346_1 = ((pub_r001492_1_1 * 2) + 44) & 63;
  int stage_v_346_2 = ((pub_r001492_1_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_346_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_346_2) & 127;
  int stage_v_347_1 = (((stage_v_192_1 * 3) + pub_r001492_10_1) + 29) & 127;
  int stage_v_347_2 = (((stage_v_192_2 * 3) + pub_r001492_10_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_347_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_347_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_347_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_347_2 * 2)) & 255;
  int stage_v_348_1 = ((pub_r001492_3_1 * 2) + 24) & 63;
  int stage_v_348_2 = ((pub_r001492_3_2 * 2) + 24) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_348_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_348_2) & 127;
  int stage_v_349_1 = (((stage_v_37_1 * 3) + pub_r001492_9_1) + 20) & 127;
  int stage_v_349_2 = (((stage_v_37_2 * 3) + pub_r001492_9_2) + 20) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_349_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_349_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_349_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_349_2 * 2)) & 255;
  int stage_v_350_1 = (((stage_v_129_1 * 3) + pub_r001492_4_1) + 44) & 127;
  int stage_v_350_2 = (((stage_v_129_2 * 3) + pub_r001492_4_2) + 44) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_350_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_350_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_350_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_350_2 * 2)) & 255;
  int stage_v_351_1 = (((stage_v_198_1 * 3) + pub_r001492_0_1) + 37) & 127;
  int stage_v_351_2 = (((stage_v_198_2 * 3) + pub_r001492_0_2) + 37) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_351_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_351_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_351_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_351_2 * 2)) & 255;
  int stage_v_352_1 = ((pub_r001492_16_1 * 2) + 25) & 63;
  int stage_v_352_2 = ((pub_r001492_16_2 * 2) + 25) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_352_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_352_2) & 127;
  int stage_v_353_1 = (((stage_v_3_1 * 3) + pub_r001492_16_1) + 26) & 127;
  int stage_v_353_2 = (((stage_v_3_2 * 3) + pub_r001492_16_2) + 26) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_353_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_353_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_353_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_353_2 * 2)) & 255;
  int stage_v_354_1 = ((pub_r001492_14_1 * 2) + 18) & 63;
  int stage_v_354_2 = ((pub_r001492_14_2 * 2) + 18) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_354_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_354_2) & 127;
  int stage_v_355_1 = ((pub_r001492_8_1 * 2) + 50) & 63;
  int stage_v_355_2 = ((pub_r001492_8_2 * 2) + 50) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_355_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_355_2) & 127;
  int stage_v_356_1 = (((sec_r001492_0_1 * 3) + pub_r001492_8_1) + 11) & 127;
  int stage_v_356_2 = (((sec_r001492_0_2 * 3) + pub_r001492_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_356_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_356_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_356_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_356_2 * 2)) & 255;
  int stage_v_357_1 = ((pub_r001492_9_1 * 2) + 35) & 63;
  int stage_v_357_2 = ((pub_r001492_9_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_357_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_357_2) & 127;
  int stage_v_358_1 = (((stage_v_232_1 * 3) + pub_r001492_8_1) + 41) & 127;
  int stage_v_358_2 = (((stage_v_232_2 * 3) + pub_r001492_8_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_358_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_358_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_358_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_358_2 * 2)) & 255;
  int stage_v_359_1 = (((sec_r001492_12_1 * 3) + pub_r001492_15_1) + 8) & 127;
  int stage_v_359_2 = (((sec_r001492_12_2 * 3) + pub_r001492_15_2) + 8) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_359_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_359_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_359_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_359_2 * 2)) & 255;
  int stage_v_360_1 = (((sec_r001492_0_1 * 3) + pub_r001492_5_1) + 29) & 127;
  int stage_v_360_2 = (((sec_r001492_0_2 * 3) + pub_r001492_5_2) + 29) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_360_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_360_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_360_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_360_2 * 2)) & 255;
  int stage_v_361_1 = (((stage_v_27_1 * 3) + pub_r001492_12_1) + 22) & 127;
  int stage_v_361_2 = (((stage_v_27_2 * 3) + pub_r001492_12_2) + 22) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_361_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_361_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_361_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_361_2 * 2)) & 255;
  int stage_v_362_1 = (((stage_v_133_1 * 3) + pub_r001492_14_1) + 32) & 127;
  int stage_v_362_2 = (((stage_v_133_2 * 3) + pub_r001492_14_2) + 32) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_362_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_362_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_362_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_362_2 * 2)) & 255;
  int stage_v_363_1 = ((pub_r001492_10_1 * 2) + 22) & 63;
  int stage_v_363_2 = ((pub_r001492_10_2 * 2) + 22) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_363_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_363_2) & 127;
  int stage_v_364_1 = (((stage_v_78_1 * 3) + pub_r001492_16_1) + 10) & 127;
  int stage_v_364_2 = (((stage_v_78_2 * 3) + pub_r001492_16_2) + 10) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_364_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_364_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_364_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_364_2 * 2)) & 255;
  int stage_v_365_1 = (((sec_r001492_5_1 * 3) + pub_r001492_9_1) + 39) & 127;
  int stage_v_365_2 = (((sec_r001492_5_2 * 3) + pub_r001492_9_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_365_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_365_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_365_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_365_2 * 2)) & 255;
  int stage_v_366_1 = ((pub_r001492_12_1 * 2) + 37) & 63;
  int stage_v_366_2 = ((pub_r001492_12_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_366_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_366_2) & 127;
  int stage_v_367_1 = (((stage_v_315_1 * 3) + pub_r001492_13_1) + 3) & 127;
  int stage_v_367_2 = (((stage_v_315_2 * 3) + pub_r001492_13_2) + 3) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_367_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_367_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_367_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_367_2 * 2)) & 255;
  int stage_v_368_1 = ((pub_r001492_9_1 * 2) + 36) & 63;
  int stage_v_368_2 = ((pub_r001492_9_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_368_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_368_2) & 127;
  int stage_v_369_1 = ((pub_r001492_11_1 * 2) + 21) & 63;
  int stage_v_369_2 = ((pub_r001492_11_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_369_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_369_2) & 127;
  int stage_v_370_1 = ((pub_r001492_8_1 * 2) + 9) & 63;
  int stage_v_370_2 = ((pub_r001492_8_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_370_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_370_2) & 127;
  int stage_v_371_1 = ((pub_r001492_6_1 * 2) + 32) & 63;
  int stage_v_371_2 = ((pub_r001492_6_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_371_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_371_2) & 127;
  int stage_v_372_1 = ((pub_r001492_15_1 * 2) + 43) & 63;
  int stage_v_372_2 = ((pub_r001492_15_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_372_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_372_2) & 127;
  int stage_v_373_1 = (((sec_r001492_13_1 * 3) + pub_r001492_1_1) + 16) & 127;
  int stage_v_373_2 = (((sec_r001492_13_2 * 3) + pub_r001492_1_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_373_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_373_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_373_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_373_2 * 2)) & 255;
  int stage_v_374_1 = ((pub_r001492_2_1 * 2) + 38) & 63;
  int stage_v_374_2 = ((pub_r001492_2_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_374_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_374_2) & 127;
  int stage_v_375_1 = ((pub_r001492_6_1 * 2) + 29) & 63;
  int stage_v_375_2 = ((pub_r001492_6_2 * 2) + 29) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_375_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_375_2) & 127;
  int stage_v_376_1 = (((sec_r001492_11_1 * 3) + pub_r001492_4_1) + 21) & 127;
  int stage_v_376_2 = (((sec_r001492_11_2 * 3) + pub_r001492_4_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_376_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_376_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_376_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_376_2 * 2)) & 255;
  int stage_v_377_1 = ((pub_r001492_15_1 * 2) + 5) & 63;
  int stage_v_377_2 = ((pub_r001492_15_2 * 2) + 5) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_377_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_377_2) & 127;
  int stage_v_378_1 = ((pub_r001492_11_1 * 2) + 33) & 63;
  int stage_v_378_2 = ((pub_r001492_11_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_378_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_378_2) & 127;
  int stage_v_379_1 = ((pub_r001492_12_1 * 2) + 20) & 63;
  int stage_v_379_2 = ((pub_r001492_12_2 * 2) + 20) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_379_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_379_2) & 127;
  int stage_v_380_1 = ((pub_r001492_4_1 * 2) + 43) & 63;
  int stage_v_380_2 = ((pub_r001492_4_2 * 2) + 43) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_380_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_380_2) & 127;
  int stage_v_381_1 = ((pub_r001492_8_1 * 2) + 46) & 63;
  int stage_v_381_2 = ((pub_r001492_8_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_381_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_381_2) & 127;
  int stage_v_382_1 = ((pub_r001492_4_1 * 2) + 40) & 63;
  int stage_v_382_2 = ((pub_r001492_4_2 * 2) + 40) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_382_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_382_2) & 127;
  int stage_v_383_1 = ((pub_r001492_10_1 * 2) + 33) & 63;
  int stage_v_383_2 = ((pub_r001492_10_2 * 2) + 33) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_383_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_383_2) & 127;
  int stage_v_384_1 = (((stage_v_133_1 * 3) + pub_r001492_5_1) + 27) & 127;
  int stage_v_384_2 = (((stage_v_133_2 * 3) + pub_r001492_5_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_384_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_384_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_384_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_384_2 * 2)) & 255;
  int stage_v_385_1 = ((pub_r001492_7_1 * 2) + 38) & 63;
  int stage_v_385_2 = ((pub_r001492_7_2 * 2) + 38) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_385_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_385_2) & 127;
  int stage_v_386_1 = ((pub_r001492_7_1 * 2) + 21) & 63;
  int stage_v_386_2 = ((pub_r001492_7_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_386_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_386_2) & 127;
  int stage_v_387_1 = ((pub_r001492_12_1 * 2) + 36) & 63;
  int stage_v_387_2 = ((pub_r001492_12_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_387_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_387_2) & 127;
  int stage_v_388_1 = ((pub_r001492_3_1 * 2) + 21) & 63;
  int stage_v_388_2 = ((pub_r001492_3_2 * 2) + 21) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_388_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_388_2) & 127;
  int stage_v_389_1 = ((pub_r001492_11_1 * 2) + 9) & 63;
  int stage_v_389_2 = ((pub_r001492_11_2 * 2) + 9) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_389_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_389_2) & 127;
  int stage_v_390_1 = ((pub_r001492_8_1 * 2) + 45) & 63;
  int stage_v_390_2 = ((pub_r001492_8_2 * 2) + 45) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_390_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_390_2) & 127;
  int stage_v_391_1 = (((stage_v_157_1 * 3) + pub_r001492_8_1) + 15) & 127;
  int stage_v_391_2 = (((stage_v_157_2 * 3) + pub_r001492_8_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_391_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_391_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_391_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_391_2 * 2)) & 255;
  int stage_v_392_1 = (((stage_v_225_1 * 3) + pub_r001492_10_1) + 14) & 127;
  int stage_v_392_2 = (((stage_v_225_2 * 3) + pub_r001492_10_2) + 14) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_392_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_392_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_392_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_392_2 * 2)) & 255;
  int stage_v_393_1 = ((pub_r001492_0_1 * 2) + 7) & 63;
  int stage_v_393_2 = ((pub_r001492_0_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_393_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_393_2) & 127;
  int stage_v_394_1 = ((pub_r001492_5_1 * 2) + 44) & 63;
  int stage_v_394_2 = ((pub_r001492_5_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_394_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_394_2) & 127;
  int stage_v_395_1 = (((stage_v_308_1 * 3) + pub_r001492_8_1) + 11) & 127;
  int stage_v_395_2 = (((stage_v_308_2 * 3) + pub_r001492_8_2) + 11) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_395_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_395_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_395_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_395_2 * 2)) & 255;
  int stage_v_396_1 = (((stage_v_168_1 * 3) + pub_r001492_4_1) + 16) & 127;
  int stage_v_396_2 = (((stage_v_168_2 * 3) + pub_r001492_4_2) + 16) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_396_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_396_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_396_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_396_2 * 2)) & 255;
  int stage_v_397_1 = ((pub_r001492_5_1 * 2) + 32) & 63;
  int stage_v_397_2 = ((pub_r001492_5_2 * 2) + 32) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_397_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_397_2) & 127;
  int stage_v_398_1 = (((stage_v_314_1 * 3) + pub_r001492_9_1) + 6) & 127;
  int stage_v_398_2 = (((stage_v_314_2 * 3) + pub_r001492_9_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_398_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_398_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_398_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_398_2 * 2)) & 255;
  int stage_v_399_1 = ((pub_r001492_13_1 * 2) + 42) & 63;
  int stage_v_399_2 = ((pub_r001492_13_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_399_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_399_2) & 127;
  int stage_v_400_1 = ((pub_r001492_12_1 * 2) + 42) & 63;
  int stage_v_400_2 = ((pub_r001492_12_2 * 2) + 42) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_400_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_400_2) & 127;
  int stage_v_401_1 = ((pub_r001492_9_1 * 2) + 30) & 63;
  int stage_v_401_2 = ((pub_r001492_9_2 * 2) + 30) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_401_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_401_2) & 127;
  int stage_v_402_1 = ((pub_r001492_13_1 * 2) + 44) & 63;
  int stage_v_402_2 = ((pub_r001492_13_2 * 2) + 44) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_402_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_402_2) & 127;
  int stage_v_403_1 = ((pub_r001492_12_1 * 2) + 8) & 63;
  int stage_v_403_2 = ((pub_r001492_12_2 * 2) + 8) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_403_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_403_2) & 127;
  int stage_v_404_1 = ((pub_r001492_1_1 * 2) + 27) & 63;
  int stage_v_404_2 = ((pub_r001492_1_2 * 2) + 27) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_404_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_404_2) & 127;
  int stage_v_405_1 = ((pub_r001492_7_1 * 2) + 46) & 63;
  int stage_v_405_2 = ((pub_r001492_7_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_405_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_405_2) & 127;
  int stage_v_406_1 = ((pub_r001492_12_1 * 2) + 19) & 63;
  int stage_v_406_2 = ((pub_r001492_12_2 * 2) + 19) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_406_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_406_2) & 127;
  int stage_v_407_1 = ((pub_r001492_7_1 * 2) + 12) & 63;
  int stage_v_407_2 = ((pub_r001492_7_2 * 2) + 12) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_407_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_407_2) & 127;
  int stage_v_408_1 = ((pub_r001492_6_1 * 2) + 7) & 63;
  int stage_v_408_2 = ((pub_r001492_6_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_408_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_408_2) & 127;
  int stage_v_409_1 = ((pub_r001492_10_1 * 2) + 46) & 63;
  int stage_v_409_2 = ((pub_r001492_10_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_409_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_409_2) & 127;
  int stage_v_410_1 = ((pub_r001492_2_1 * 2) + 39) & 63;
  int stage_v_410_2 = ((pub_r001492_2_2 * 2) + 39) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_410_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_410_2) & 127;
  int stage_v_411_1 = (((sec_r001492_15_1 * 3) + pub_r001492_16_1) + 6) & 127;
  int stage_v_411_2 = (((sec_r001492_15_2 * 3) + pub_r001492_16_2) + 6) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_411_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_411_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_411_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_411_2 * 2)) & 255;
  int stage_v_412_1 = ((pub_r001492_3_1 * 2) + 46) & 63;
  int stage_v_412_2 = ((pub_r001492_3_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_412_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_412_2) & 127;
  int stage_v_413_1 = (((stage_v_273_1 * 3) + pub_r001492_1_1) + 18) & 127;
  int stage_v_413_2 = (((stage_v_273_2 * 3) + pub_r001492_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_413_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_413_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_413_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_413_2 * 2)) & 255;
  int stage_v_414_1 = ((pub_r001492_1_1 * 2) + 34) & 63;
  int stage_v_414_2 = ((pub_r001492_1_2 * 2) + 34) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_414_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_414_2) & 127;
  int stage_v_415_1 = (((stage_v_187_1 * 3) + pub_r001492_10_1) + 27) & 127;
  int stage_v_415_2 = (((stage_v_187_2 * 3) + pub_r001492_10_2) + 27) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_415_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_415_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_415_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_415_2 * 2)) & 255;
  int stage_v_416_1 = ((pub_r001492_1_1 * 2) + 17) & 63;
  int stage_v_416_2 = ((pub_r001492_1_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_416_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_416_2) & 127;
  int stage_v_417_1 = ((pub_r001492_0_1 * 2) + 35) & 63;
  int stage_v_417_2 = ((pub_r001492_0_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_417_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_417_2) & 127;
  int stage_v_418_1 = ((pub_r001492_2_1 * 2) + 7) & 63;
  int stage_v_418_2 = ((pub_r001492_2_2 * 2) + 7) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_418_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_418_2) & 127;
  int stage_v_419_1 = (((stage_v_273_1 * 3) + pub_r001492_10_1) + 40) & 127;
  int stage_v_419_2 = (((stage_v_273_2 * 3) + pub_r001492_10_2) + 40) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_419_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_419_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_419_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_419_2 * 2)) & 255;
  int stage_v_420_1 = ((pub_r001492_3_1 * 2) + 6) & 63;
  int stage_v_420_2 = ((pub_r001492_3_2 * 2) + 6) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_420_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_420_2) & 127;
  int stage_v_421_1 = (((sec_r001492_2_1 * 3) + pub_r001492_11_1) + 15) & 127;
  int stage_v_421_2 = (((sec_r001492_2_2 * 3) + pub_r001492_11_2) + 15) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_421_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_421_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_421_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_421_2 * 2)) & 255;
  int stage_v_422_1 = ((pub_r001492_8_1 * 2) + 37) & 63;
  int stage_v_422_2 = ((pub_r001492_8_2 * 2) + 37) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_422_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_422_2) & 127;
  int stage_v_423_1 = (((stage_v_273_1 * 3) + pub_r001492_5_1) + 24) & 127;
  int stage_v_423_2 = (((stage_v_273_2 * 3) + pub_r001492_5_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_423_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_423_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_423_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_423_2 * 2)) & 255;
  int stage_v_424_1 = ((pub_r001492_9_1 * 2) + 28) & 63;
  int stage_v_424_2 = ((pub_r001492_9_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_424_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_424_2) & 127;
  int stage_v_425_1 = ((pub_r001492_8_1 * 2) + 28) & 63;
  int stage_v_425_2 = ((pub_r001492_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_425_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_425_2) & 127;
  int stage_v_426_1 = (((stage_v_296_1 * 3) + pub_r001492_14_1) + 21) & 127;
  int stage_v_426_2 = (((stage_v_296_2 * 3) + pub_r001492_14_2) + 21) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_426_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_426_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_426_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_426_2 * 2)) & 255;
  int stage_v_427_1 = (((stage_v_250_1 * 3) + pub_r001492_10_1) + 35) & 127;
  int stage_v_427_2 = (((stage_v_250_2 * 3) + pub_r001492_10_2) + 35) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_427_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_427_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_427_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_427_2 * 2)) & 255;
  int stage_v_428_1 = (((stage_v_71_1 * 3) + pub_r001492_5_1) + 41) & 127;
  int stage_v_428_2 = (((stage_v_71_2 * 3) + pub_r001492_5_2) + 41) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_428_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_428_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_428_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_428_2 * 2)) & 255;
  int stage_v_429_1 = (((stage_v_70_1 * 3) + pub_r001492_1_1) + 18) & 127;
  int stage_v_429_2 = (((stage_v_70_2 * 3) + pub_r001492_1_2) + 18) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_429_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_429_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_429_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_429_2 * 2)) & 255;
  int stage_v_430_1 = (((stage_v_205_1 * 3) + pub_r001492_2_1) + 24) & 127;
  int stage_v_430_2 = (((stage_v_205_2 * 3) + pub_r001492_2_2) + 24) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_430_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_430_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_430_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_430_2 * 2)) & 255;
  int stage_v_431_1 = ((pub_r001492_8_1 * 2) + 28) & 63;
  int stage_v_431_2 = ((pub_r001492_8_2 * 2) + 28) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_431_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_431_2) & 127;
  int stage_v_432_1 = (((stage_v_205_1 * 3) + pub_r001492_6_1) + 4) & 127;
  int stage_v_432_2 = (((stage_v_205_2 * 3) + pub_r001492_6_2) + 4) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_432_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_432_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_432_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_432_2 * 2)) & 255;
  int stage_v_433_1 = ((pub_r001492_4_1 * 2) + 35) & 63;
  int stage_v_433_2 = ((pub_r001492_4_2 * 2) + 35) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_433_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_433_2) & 127;
  int stage_v_434_1 = (((stage_v_338_1 * 3) + pub_r001492_9_1) + 43) & 127;
  int stage_v_434_2 = (((stage_v_338_2 * 3) + pub_r001492_9_2) + 43) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_434_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_434_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_434_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_434_2 * 2)) & 255;
  int stage_v_435_1 = (((sec_r001492_11_1 * 3) + pub_r001492_8_1) + 39) & 127;
  int stage_v_435_2 = (((sec_r001492_11_2 * 3) + pub_r001492_8_2) + 39) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_435_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_435_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_435_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_435_2 * 2)) & 255;
  int stage_v_436_1 = ((pub_r001492_10_1 * 2) + 36) & 63;
  int stage_v_436_2 = ((pub_r001492_10_2 * 2) + 36) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_436_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_436_2) & 127;
  int stage_v_437_1 = (((stage_v_318_1 * 3) + pub_r001492_5_1) + 13) & 127;
  int stage_v_437_2 = (((stage_v_318_2 * 3) + pub_r001492_5_2) + 13) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_437_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_437_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_437_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_437_2 * 2)) & 255;
  int stage_v_438_1 = (((stage_v_437_1 * 3) + pub_r001492_14_1) + 19) & 127;
  int stage_v_438_2 = (((stage_v_437_2 * 3) + pub_r001492_14_2) + 19) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_438_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_438_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_438_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_438_2 * 2)) & 255;
  int stage_v_439_1 = ((pub_r001492_3_1 * 2) + 47) & 63;
  int stage_v_439_2 = ((pub_r001492_3_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_439_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_439_2) & 127;
  int stage_v_440_1 = ((pub_r001492_7_1 * 2) + 47) & 63;
  int stage_v_440_2 = ((pub_r001492_7_2 * 2) + 47) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_440_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_440_2) & 127;
  int stage_v_441_1 = (((stage_v_37_1 * 3) + pub_r001492_14_1) + 17) & 127;
  int stage_v_441_2 = (((stage_v_37_2 * 3) + pub_r001492_14_2) + 17) & 127;
  sec_accum_1 = (sec_accum_1 + stage_v_441_1) & 255;
  sec_accum_2 = (sec_accum_2 + stage_v_441_2) & 255;
  out_sink_1 = (out_sink_1 + (stage_v_441_1 * 2)) & 255;
  out_sink_2 = (out_sink_2 + (stage_v_441_2 * 2)) & 255;
  int stage_v_442_1 = ((pub_r001492_6_1 * 2) + 31) & 63;
  int stage_v_442_2 = ((pub_r001492_6_2 * 2) + 31) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_442_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_442_2) & 127;
  int stage_v_443_1 = ((pub_r001492_16_1 * 2) + 13) & 63;
  int stage_v_443_2 = ((pub_r001492_16_2 * 2) + 13) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_443_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_443_2) & 127;
  int stage_v_444_1 = ((pub_r001492_14_1 * 2) + 17) & 63;
  int stage_v_444_2 = ((pub_r001492_14_2 * 2) + 17) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_444_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_444_2) & 127;
  int stage_v_445_1 = ((pub_r001492_13_1 * 2) + 46) & 63;
  int stage_v_445_2 = ((pub_r001492_13_2 * 2) + 46) & 63;
  chk_sum_1 = (chk_sum_1 + stage_v_445_1) & 127;
  chk_sum_2 = (chk_sum_2 + stage_v_445_2) & 127;
  g_out_1 = (out_sink_1 + sec_accum_1) & 255;
  g_out_2 = (out_sink_2 + sec_accum_2) & 255;
  g_chk_1 = chk_sum_1;
  g_chk_2 = chk_sum_2;
  g_telemetry_1 = (sec_accum_1 ^ chk_sum_1) & 127;
  g_telemetry_2 = (sec_accum_2 ^ chk_sum_2) & 127;
  __CPROVER_assume(pub_r001492_11_1 == pub_r001492_11_2);
  __CPROVER_assume(sec_r001492_18_1 != sec_r001492_18_2);
  __CPROVER_assume(pub_r001492_9_1 == pub_r001492_9_2);
  __CPROVER_assume(sec_r001492_8_1 != sec_r001492_8_2);
  __CPROVER_assume(sec_r001492_2_1 != sec_r001492_2_2);
  __CPROVER_assume(sec_r001492_17_1 != sec_r001492_17_2);
  __CPROVER_assume(sec_r001492_0_1 != sec_r001492_0_2);
  __CPROVER_assume(sec_r001492_4_1 != sec_r001492_4_2);
  __CPROVER_assume(pub_r001492_15_1 == pub_r001492_15_2);
  __CPROVER_assume(pub_r001492_14_1 == pub_r001492_14_2);
  __CPROVER_assume(pub_r001492_5_1 == pub_r001492_5_2);
  __CPROVER_assume(sec_r001492_15_1 != sec_r001492_15_2);
  __CPROVER_assume(sec_r001492_10_1 != sec_r001492_10_2);
  __CPROVER_assume(pub_r001492_12_1 == pub_r001492_12_2);
  __CPROVER_assume(pub_r001492_3_1 == pub_r001492_3_2);
  __CPROVER_assume(sec_r001492_13_1 != sec_r001492_13_2);
  __CPROVER_assume(sec_r001492_1_1 != sec_r001492_1_2);
  __CPROVER_assume(sec_r001492_12_1 != sec_r001492_12_2);
  __CPROVER_assume(pub_r001492_6_1 == pub_r001492_6_2);
  __CPROVER_assume(sec_r001492_9_1 != sec_r001492_9_2);
  __CPROVER_assume(sec_r001492_3_1 != sec_r001492_3_2);
  __CPROVER_assume(pub_r001492_10_1 == pub_r001492_10_2);
  __CPROVER_assume(sec_r001492_16_1 != sec_r001492_16_2);
  __CPROVER_assume(sec_r001492_14_1 != sec_r001492_14_2);
  __CPROVER_assume(pub_r001492_1_1 == pub_r001492_1_2);
  __CPROVER_assume(sec_r001492_7_1 != sec_r001492_7_2);
  __CPROVER_assume(sec_r001492_5_1 != sec_r001492_5_2);
  __CPROVER_assume(pub_r001492_2_1 == pub_r001492_2_2);
  __CPROVER_assume(pub_r001492_7_1 == pub_r001492_7_2);
  __CPROVER_assume(sec_r001492_6_1 != sec_r001492_6_2);
  __CPROVER_assume(pub_r001492_0_1 == pub_r001492_0_2);
  __CPROVER_assume(pub_r001492_13_1 == pub_r001492_13_2);
  __CPROVER_assume(pub_r001492_16_1 == pub_r001492_16_2);
  __CPROVER_assume(sec_r001492_11_1 != sec_r001492_11_2);
  __CPROVER_assume(pub_r001492_4_1 == pub_r001492_4_2);
  __CPROVER_assume(pub_r001492_8_1 == pub_r001492_8_2);
  assert(g_out_1 == g_out_2);
  assert(g_chk_1 == g_chk_2);
  assert(g_telemetry_1 == g_telemetry_2);
  assert(out_sink_1 == out_sink_2);
  assert(chk_sum_1 == chk_sum_2);
  assert(sec_accum_1 == sec_accum_2);
  assert(st_var_0_1.norm_sq == st_var_0_2.norm_sq);
  assert(st_var_0_1.coord_z == st_var_0_2.coord_z);
  assert(st_var_0_1.coord_x == st_var_0_2.coord_x);
  assert(st_var_0_1.heading == st_var_0_2.heading);
  assert(st_var_0_1.pitch == st_var_0_2.pitch);
  assert(st_var_0_1.coord_y == st_var_0_2.coord_y);
  for (int i_buffer = 0; i_buffer < 3; i_buffer++)
  {
    assert(st_var_0_1.buffer[i_buffer] == st_var_0_2.buffer[i_buffer]);
  }

  assert(st_var_1_1.prev_out == st_var_1_2.prev_out);
  assert(st_var_1_1.cutoff == st_var_1_2.cutoff);
  assert(st_var_1_1.gain_db == st_var_1_2.gain_db);
  assert(st_var_1_1.damping == st_var_1_2.damping);
  assert(st_var_1_1.prev_in == st_var_1_2.prev_in);
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
}


